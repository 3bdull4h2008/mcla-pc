#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82130000"))) PPC_WEAK_FUNC(sub_82130000);
PPC_FUNC_IMPL(__imp__sub_82130000) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130004"))) PPC_WEAK_FUNC(sub_82130004);
PPC_FUNC_IMPL(__imp__sub_82130004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130008"))) PPC_WEAK_FUNC(sub_82130008);
PPC_FUNC_IMPL(__imp__sub_82130008) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130010"))) PPC_WEAK_FUNC(sub_82130010);
PPC_FUNC_IMPL(__imp__sub_82130010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x82130030
	if (cr6.lt) goto loc_82130030;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82130030:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82130044"))) PPC_WEAK_FUNC(sub_82130044);
PPC_FUNC_IMPL(__imp__sub_82130044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130048"))) PPC_WEAK_FUNC(sub_82130048);
PPC_FUNC_IMPL(__imp__sub_82130048) {
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
	ctx.lr = 0x82130050;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8213019c
	if (cr6.eq) goto loc_8213019C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821300a4
	if (cr6.eq) goto loc_821300A4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213009C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821300A4:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821300B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x821300e4
	if (cr6.eq) goto loc_821300E4;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821300DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821300E4:
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r27,4(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mr r28,r29
	r28.u64 = r29.u64;
	// mr r26,r27
	r26.u64 = r27.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,88(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213011C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r29,r25,r3
	r29.u64 = r25.u64 + ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,92(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82130134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,88(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8213014C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r27,r26,r3
	r27.u64 = r26.u64 + ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213017C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r7,3360
	ctx.r3.s64 = ctx.r7.s64 + 3360;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x8213019C;
	sub_82130000(ctx, base);
loc_8213019C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821301A4"))) PPC_WEAK_FUNC(sub_821301A4);
PPC_FUNC_IMPL(__imp__sub_821301A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821301A8"))) PPC_WEAK_FUNC(sub_821301A8);
PPC_FUNC_IMPL(__imp__sub_821301A8) {
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
	ctx.lr = 0x821301B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,8(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821301D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821301EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r29,r3
	ctx.r3.u64 = r29.u64 + ctx.r3.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821301F8"))) PPC_WEAK_FUNC(sub_821301F8);
PPC_FUNC_IMPL(__imp__sub_821301F8) {
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
	// lwz r31,8(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,88(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213023C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
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

__attribute__((alias("__imp__sub_82130258"))) PPC_WEAK_FUNC(sub_82130258);
PPC_FUNC_IMPL(__imp__sub_82130258) {
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
	// lwz r31,8(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213029C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r30,r3
	ctx.r3.u64 = r30.u64 + ctx.r3.u64;
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

__attribute__((alias("__imp__sub_821302B8"))) PPC_WEAK_FUNC(sub_821302B8);
PPC_FUNC_IMPL(__imp__sub_821302B8) {
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
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821302E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821302fc
	if (!cr6.eq) goto loc_821302FC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821302FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821302FC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130310"))) PPC_WEAK_FUNC(sub_82130310);
PPC_FUNC_IMPL(__imp__sub_82130310) {
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
	ctx.lr = 0x82130318;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213033C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213042c
	if (cr6.eq) goto loc_8213042C;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213042c
	if (cr6.eq) goto loc_8213042C;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// subf r26,r31,r9
	r26.s64 = ctx.r9.s64 - r31.s64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r31,132
	r11.s64 = r31.s64 + 132;
	// subf r25,r31,r8
	r25.s64 = ctx.r8.s64 - r31.s64;
	// subf r24,r31,r7
	r24.s64 = ctx.r7.s64 - r31.s64;
	// li r9,8
	ctx.r9.s64 = 8;
loc_82130390:
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,-132(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -132);
	// lwz r27,128(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lwz r28,0(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r27,r27,r6
	r27.u64 = r27.u64 + ctx.r6.u64;
	// lwzx r4,r26,r11
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// add r28,r8,r28
	r28.u64 = ctx.r8.u64 + r28.u64;
	// lwz r30,-128(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -128);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r29,r4,r29
	r29.u64 = ctx.r4.u64 + r29.u64;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwzx r8,r25,r11
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r3,-124(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -124);
	// add r30,r6,r30
	r30.u64 = ctx.r6.u64 + r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r31,r8,r31
	r31.u64 = ctx.r8.u64 + r31.u64;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,-120(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -120);
	// add r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lwzx r6,r24,r11
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stw r27,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r27.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r28,-132(r11)
	PPC_STORE_U32(r11.u32 + -132, r28.u32);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// stw r30,-128(r11)
	PPC_STORE_U32(r11.u32 + -128, r30.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r4,-124(r11)
	PPC_STORE_U32(r11.u32 + -124, ctx.r4.u32);
	// stw r3,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r3.u32);
	// stw r8,-120(r11)
	PPC_STORE_U32(r11.u32 + -120, ctx.r8.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82130390
	if (!cr0.eq) goto loc_82130390;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9238
	return;
loc_8213042C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82130438"))) PPC_WEAK_FUNC(sub_82130438);
PPC_FUNC_IMPL(__imp__sub_82130438) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213049c
	if (!cr6.eq) goto loc_8213049C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213048C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821304a0
	if (cr6.eq) goto loc_821304A0;
loc_8213049C:
	// li r11,1
	r11.s64 = 1;
loc_821304A0:
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

__attribute__((alias("__imp__sub_821304BC"))) PPC_WEAK_FUNC(sub_821304BC);
PPC_FUNC_IMPL(__imp__sub_821304BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821304C0"))) PPC_WEAK_FUNC(sub_821304C0);
PPC_FUNC_IMPL(__imp__sub_821304C0) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821304F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82130510
	if (!cr6.eq) goto loc_82130510;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82130510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82130510:
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

__attribute__((alias("__imp__sub_82130528"))) PPC_WEAK_FUNC(sub_82130528);
PPC_FUNC_IMPL(__imp__sub_82130528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82130550"))) PPC_WEAK_FUNC(sub_82130550);
PPC_FUNC_IMPL(__imp__sub_82130550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// bgt cr6,0x82130564
	if (cr6.gt) goto loc_82130564;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82130564:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,28
	ctx.r9.s64 = 28;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82130588"))) PPC_WEAK_FUNC(sub_82130588);
PPC_FUNC_IMPL(__imp__sub_82130588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821305B0"))) PPC_WEAK_FUNC(sub_821305B0);
PPC_FUNC_IMPL(__imp__sub_821305B0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821305B4"))) PPC_WEAK_FUNC(sub_821305B4);
PPC_FUNC_IMPL(__imp__sub_821305B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821305B8"))) PPC_WEAK_FUNC(sub_821305B8);
PPC_FUNC_IMPL(__imp__sub_821305B8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3576
	ctx.r3.s64 = r11.s64 + 3576;
	// bl 0x821bd618
	ctx.lr = 0x821305D0;
	sub_821BD618(ctx, base);
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

__attribute__((alias("__imp__sub_821305E4"))) PPC_WEAK_FUNC(sub_821305E4);
PPC_FUNC_IMPL(__imp__sub_821305E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821305E8"))) PPC_WEAK_FUNC(sub_821305E8);
PPC_FUNC_IMPL(__imp__sub_821305E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x821bd7c0
	sub_821BD7C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821305EC"))) PPC_WEAK_FUNC(sub_821305EC);
PPC_FUNC_IMPL(__imp__sub_821305EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821305F0"))) PPC_WEAK_FUNC(sub_821305F0);
PPC_FUNC_IMPL(__imp__sub_821305F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821305F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addic. r31,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	r31.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x82130628
	if (cr0.lt) goto loc_82130628;
loc_82130610:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r28
	ctr.u64 = r28.u64;
	// bctrl 
	ctx.lr = 0x8213061C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r30,r29
	r30.u64 = r30.u64 + r29.u64;
	// bge 0x82130610
	if (!cr0.lt) goto loc_82130610;
loc_82130628:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82130630"))) PPC_WEAK_FUNC(sub_82130630);
PPC_FUNC_IMPL(__imp__sub_82130630) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82130638;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mullw r11,r29,r5
	r11.s64 = int64_t(r29.s32) * int64_t(ctx.r5.s32);
	// addic. r31,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	r31.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
	// blt 0x8213066c
	if (cr0.lt) goto loc_8213066C;
loc_82130654:
	// subf r30,r29,r30
	r30.s64 = r30.s64 - r29.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r28
	ctr.u64 = r28.u64;
	// bctrl 
	ctx.lr = 0x82130664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82130654
	if (!cr0.lt) goto loc_82130654;
loc_8213066C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82130674"))) PPC_WEAK_FUNC(sub_82130674);
PPC_FUNC_IMPL(__imp__sub_82130674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130678"))) PPC_WEAK_FUNC(sub_82130678);
PPC_FUNC_IMPL(__imp__sub_82130678) {
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
	// bl 0x82388598
	ctx.lr = 0x8213068C;
	sub_82388598(ctx, base);
	// bl 0x82131c58
	ctx.lr = 0x82130690;
	sub_82131C58(ctx, base);
}

__attribute__((alias("__imp__sub_82130690"))) PPC_WEAK_FUNC(sub_82130690);
PPC_FUNC_IMPL(__imp__sub_82130690) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,2448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130710
	if (cr6.eq) goto loc_82130710;
loc_821306B0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821306b0
	if (cr6.eq) goto loc_821306B0;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r7,3624
	ctx.r4.s64 = ctx.r7.s64 + 3624;
	// ld r5,2736(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2736);
	// lfs f0,3012(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3012);
	f0.f64 = double(temp.f32);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x82130700;
	sub_821BE860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82130710:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130710
	if (cr6.eq) goto loc_82130710;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,2736(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2736);
	// addi r3,r8,3624
	ctx.r3.s64 = ctx.r8.s64 + 3624;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f0,3012(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3012);
	f0.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x823d9750
	ctx.lr = 0x82130760;
	sub_823D9750(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130770"))) PPC_WEAK_FUNC(sub_82130770);
PPC_FUNC_IMPL(__imp__sub_82130770) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,2448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821307f0
	if (cr6.eq) goto loc_821307F0;
loc_82130790:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130790
	if (cr6.eq) goto loc_82130790;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r7,3644
	ctx.r4.s64 = ctx.r7.s64 + 3644;
	// ld r5,2736(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2736);
	// lfs f0,3012(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3012);
	f0.f64 = double(temp.f32);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x821307E0;
	sub_821BE860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821307F0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821307f0
	if (cr6.eq) goto loc_821307F0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,2736(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2736);
	// addi r3,r8,3644
	ctx.r3.s64 = ctx.r8.s64 + 3644;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f0,3012(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3012);
	f0.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x823d9750
	ctx.lr = 0x82130840;
	sub_823D9750(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130850"))) PPC_WEAK_FUNC(sub_82130850);
PPC_FUNC_IMPL(__imp__sub_82130850) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,2448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821308d0
	if (cr6.eq) goto loc_821308D0;
loc_82130870:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130870
	if (cr6.eq) goto loc_82130870;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r7,3664
	ctx.r4.s64 = ctx.r7.s64 + 3664;
	// ld r5,2736(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2736);
	// lfs f0,3012(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3012);
	f0.f64 = double(temp.f32);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x821308C0;
	sub_821BE860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821308D0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821308d0
	if (cr6.eq) goto loc_821308D0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,2736(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2736);
	// addi r3,r8,3664
	ctx.r3.s64 = ctx.r8.s64 + 3664;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f0,3012(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3012);
	f0.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x823d9750
	ctx.lr = 0x82130920;
	sub_823D9750(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130930"))) PPC_WEAK_FUNC(sub_82130930);
PPC_FUNC_IMPL(__imp__sub_82130930) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,2448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821309b4
	if (cr6.eq) goto loc_821309B4;
loc_82130950:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130950
	if (cr6.eq) goto loc_82130950;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r7,3684
	ctx.r4.s64 = ctx.r7.s64 + 3684;
	// ld r5,2736(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2736);
	// lfs f0,3012(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3012);
	f0.f64 = double(temp.f32);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x821309A0;
	sub_821BE860(ctx, base);
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
loc_821309B4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821309b4
	if (cr6.eq) goto loc_821309B4;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,2736(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2736);
	// addi r3,r8,3684
	ctx.r3.s64 = ctx.r8.s64 + 3684;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f0,3012(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3012);
	f0.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x823d9750
	ctx.lr = 0x82130A04;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_82130A18"))) PPC_WEAK_FUNC(sub_82130A18);
PPC_FUNC_IMPL(__imp__sub_82130A18) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,2448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130a98
	if (cr6.eq) goto loc_82130A98;
loc_82130A38:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130a38
	if (cr6.eq) goto loc_82130A38;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r7,3704
	ctx.r4.s64 = ctx.r7.s64 + 3704;
	// ld r5,2736(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2736);
	// lfs f0,3012(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3012);
	f0.f64 = double(temp.f32);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x82130A88;
	sub_821BE860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82130A98:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130a98
	if (cr6.eq) goto loc_82130A98;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,2736(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2736);
	// addi r3,r8,3704
	ctx.r3.s64 = ctx.r8.s64 + 3704;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f0,3012(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3012);
	f0.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x823d9750
	ctx.lr = 0x82130AE8;
	sub_823D9750(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130AF8"))) PPC_WEAK_FUNC(sub_82130AF8);
PPC_FUNC_IMPL(__imp__sub_82130AF8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2464(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2464);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82130b3c
	if (cr6.eq) goto loc_82130B3C;
	// bl 0x822c4388
	ctx.lr = 0x82130B18;
	sub_822C4388(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82130b28
	if (!cr6.lt) goto loc_82130B28;
	// li r11,0
	r11.s64 = 0;
loc_82130B28:
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
loc_82130B3C:
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

__attribute__((alias("__imp__sub_82130B50"))) PPC_WEAK_FUNC(sub_82130B50);
PPC_FUNC_IMPL(__imp__sub_82130B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x82130B58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r26,0,0,0
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x80000000;
	// stw r26,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r26.u32);
	// lbz r8,173(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 173);
	// rlwinm r4,r26,8,28,31
	ctx.r4.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xF;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// li r27,0
	r27.s64 = 0;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82130bac
	if (cr6.eq) goto loc_82130BAC;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82130ba0
	if (!cr6.eq) goto loc_82130BA0;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// b 0x82130bf4
	goto loc_82130BF4;
loc_82130BA0:
	// li r11,1
	r11.s64 = 1;
	// slw r4,r11,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r4.u8 & 0x3F));
	// b 0x82130bf4
	goto loc_82130BF4;
loc_82130BAC:
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x82130bf4
	if (cr6.gt) goto loc_82130BF4;
	// lis r12,-32237
	r12.s64 = -2112684032;
	// addi r12,r12,3020
	r12.s64 = r12.s64 + 3020;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82130BE0;
	case 1:
		goto loc_82130BF0;
	case 2:
		goto loc_82130BE8;
	case 3:
		goto loc_82130BF4;
	case 4:
		goto loc_82130BE0;
	default:
		__builtin_unreachable();
	}
	// lwz r16,3040(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 3040);
	// lwz r16,3056(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 3056);
	// lwz r16,3048(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 3048);
	// lwz r16,3060(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 3060);
	// lwz r16,3040(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 3040);
loc_82130BE0:
	// li r4,16
	ctx.r4.s64 = 16;
	// b 0x82130bf4
	goto loc_82130BF4;
loc_82130BE8:
	// li r4,8
	ctx.r4.s64 = 8;
	// b 0x82130bf4
	goto loc_82130BF4;
loc_82130BF0:
	// li r4,4
	ctx.r4.s64 = 4;
loc_82130BF4:
	// lis r31,-32125
	r31.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,2824(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2824);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bge cr6,0x82130c38
	if (!cr6.lt) goto loc_82130C38;
	// cmpwi cr6,r8,128
	cr6.compare<int32_t>(ctx.r8.s32, 128, xer);
	// bne cr6,0x82130c38
	if (!cr6.eq) goto loc_82130C38;
	// cmplwi cr6,r4,4096
	cr6.compare<uint32_t>(ctx.r4.u32, 4096, xer);
	// bne cr6,0x82130c38
	if (!cr6.eq) goto loc_82130C38;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r28,1
	r28.s64 = 1;
	// stw r11,2824(r31)
	PPC_STORE_U32(r31.u32 + 2824, r11.u32);
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r30,2484(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2484, r30.u32);
loc_82130C38:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r8,-128
	ctx.r9.s64 = ctx.r8.s64 + -128;
	// addi r10,r10,5160
	ctx.r10.s64 = ctx.r10.s64 + 5160;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r8,130
	cr6.compare<int32_t>(ctx.r8.s32, 130, xer);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + r30.u64;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bne cr6,0x82130cbc
	if (!cr6.eq) goto loc_82130CBC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,28
	r28.s64 = 28;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-12464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12464);
	// lwzx r27,r28,r29
	r27.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// stwx r11,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r11.u32);
	// beq cr6,0x82130c8c
	if (cr6.eq) goto loc_82130C8C;
	// bl 0x82135fe8
	ctx.lr = 0x82130C88;
	sub_82135FE8(ctx, base);
	// b 0x82130c90
	goto loc_82130C90;
loc_82130C8C:
	// bl 0x82135fd0
	ctx.lr = 0x82130C90;
	sub_82135FD0(ctx, base);
loc_82130C90:
	// rlwinm r11,r26,0,1,1
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x40000000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82130cac
	if (cr6.eq) goto loc_82130CAC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82130CAC;
	sub_823D9890(ctx, base);
loc_82130CAC:
	// stwx r27,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82130CBC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lbz r9,2488(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2488);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130cd8
	if (cr6.eq) goto loc_82130CD8;
	// lwz r27,5156(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 5156);
	// b 0x82130d2c
	goto loc_82130D2C;
loc_82130CD8:
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130cf8
	if (cr6.eq) goto loc_82130CF8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82131c78
	ctx.lr = 0x82130CF0;
	sub_82131C78(ctx, base);
	// stw r3,5156(r29)
	PPC_STORE_U32(r29.u32 + 5156, ctx.r3.u32);
	// b 0x82130d28
	goto loc_82130D28;
loc_82130CF8:
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82130d2c
	if (!cr6.eq) goto loc_82130D2C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82131c78
	ctx.lr = 0x82130D10;
	sub_82131C78(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82130d28
	if (!cr6.eq) goto loc_82130D28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3728
	ctx.r3.s64 = r11.s64 + 3728;
	// bl 0x82130000
	ctx.lr = 0x82130D28;
	sub_82130000(ctx, base);
loc_82130D28:
	// lwz r11,2824(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2824);
loc_82130D2C:
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82130d60
	if (cr6.eq) goto loc_82130D60;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r10,5156(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5156);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,5460
	ctx.r9.s64 = ctx.r9.s64 + 5460;
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mullw r11,r7,r30
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(r30.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82130D60:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82130D6C"))) PPC_WEAK_FUNC(sub_82130D6C);
PPC_FUNC_IMPL(__imp__sub_82130D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130D70"))) PPC_WEAK_FUNC(sub_82130D70);
PPC_FUNC_IMPL(__imp__sub_82130D70) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lbz r10,125(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 125);
	// cmplwi cr6,r10,130
	cr6.compare<uint32_t>(ctx.r10.u32, 130, xer);
	// bne cr6,0x82130dc0
	if (!cr6.eq) goto loc_82130DC0;
	// rlwinm r11,r4,0,0,0
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82130dac
	if (cr6.eq) goto loc_82130DAC;
	// bl 0x82135ff8
	ctx.lr = 0x82130D9C;
	sub_82135FF8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82130DAC:
	// bl 0x82135fe0
	ctx.lr = 0x82130DB0;
	sub_82135FE0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82130DC0:
	// bl 0x82131d30
	ctx.lr = 0x82130DC4;
	sub_82131D30(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130DD4"))) PPC_WEAK_FUNC(sub_82130DD4);
PPC_FUNC_IMPL(__imp__sub_82130DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130DD8"))) PPC_WEAK_FUNC(sub_82130DD8);
PPC_FUNC_IMPL(__imp__sub_82130DD8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,3236
	ctx.r10.s64 = r11.s64 + 3236;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821bbe30
	ctx.lr = 0x82130E04;
	sub_821BBE30(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82130e30
	if (cr6.eq) goto loc_82130E30;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82130E30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82130E30:
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

__attribute__((alias("__imp__sub_82130E4C"))) PPC_WEAK_FUNC(sub_82130E4C);
PPC_FUNC_IMPL(__imp__sub_82130E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130E50"))) PPC_WEAK_FUNC(sub_82130E50);
PPC_FUNC_IMPL(__imp__sub_82130E50) {
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
	// bl 0x821bbe30
	ctx.lr = 0x82130E70;
	sub_821BBE30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82130ea4
	if (cr6.eq) goto loc_82130EA4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82130ea4
	if (cr6.eq) goto loc_82130EA4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82130EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82130EA4:
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

__attribute__((alias("__imp__sub_82130EC0"))) PPC_WEAK_FUNC(sub_82130EC0);
PPC_FUNC_IMPL(__imp__sub_82130EC0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x827bcd84
	ctx.lr = 0x82130EDC;
	__imp__XGetVideoMode(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82130f64
	if (!cr6.eq) goto loc_82130F64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1280
	cr6.compare<int32_t>(r11.s32, 1280, xer);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// blt cr6,0x82130efc
	if (cr6.lt) goto loc_82130EFC;
	// li r8,1280
	ctx.r8.s64 = 1280;
loc_82130EFC:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r9,768
	cr6.compare<int32_t>(ctx.r9.s32, 768, xer);
	// blt cr6,0x82130f0c
	if (cr6.lt) goto loc_82130F0C;
	// li r9,768
	ctx.r9.s64 = 768;
loc_82130F0C:
	// lis r11,11
	r11.s64 = 720896;
	// mullw r10,r9,r8
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// ori r7,r11,36864
	ctx.r7.u64 = r11.u64 | 36864;
	// subf r6,r10,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r10.s64;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82130f2c
	if (!cr6.lt) goto loc_82130F2C;
	// li r11,0
	r11.s64 = 0;
loc_82130F2C:
	// cmpwi cr6,r8,720
	cr6.compare<int32_t>(ctx.r8.s32, 720, xer);
	// bgt cr6,0x82130f58
	if (cr6.gt) goto loc_82130F58;
	// cmpwi cr6,r9,576
	cr6.compare<int32_t>(ctx.r9.s32, 576, xer);
	// bgt cr6,0x82130f58
	if (cr6.gt) goto loc_82130F58;
	// addis r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -262144;
	// addi r10,r10,31744
	ctx.r10.s64 = ctx.r10.s64 + 31744;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82130f54
	if (!cr6.lt) goto loc_82130F54;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82130F54:
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
loc_82130F58:
	// rlwinm r11,r11,0,0,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// srawi r10,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r10.s64 = r11.s32 >> 10;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
loc_82130F64:
	// bl 0x82131c08
	ctx.lr = 0x82130F68;
	sub_82131C08(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3748
	ctx.r4.s64 = r11.s64 + 3748;
	// bl 0x823d90b0
	ctx.lr = 0x82130F74;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r31,-6144
	ctx.r3.s64 = r31.s64 + -6144;
	// bne cr6,0x82130f84
	if (!cr6.eq) goto loc_82130F84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82130F84:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130F98"))) PPC_WEAK_FUNC(sub_82130F98);
PPC_FUNC_IMPL(__imp__sub_82130F98) {
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
	// bl 0x82177238
	ctx.lr = 0x82130FB8;
	sub_82177238(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82130fec
	if (cr6.eq) goto loc_82130FEC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82130fec
	if (cr6.eq) goto loc_82130FEC;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82130FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82130FEC:
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

__attribute__((alias("__imp__sub_82131008"))) PPC_WEAK_FUNC(sub_82131008);
PPC_FUNC_IMPL(__imp__sub_82131008) {
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
	ctx.lr = 0x82131010;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// addi r29,r11,-6420
	r29.s64 = r11.s64 + -6420;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213103c
	if (!cr6.eq) goto loc_8213103C;
	// lwz r3,-18004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// bl 0x823043f8
	ctx.lr = 0x82131034;
	sub_823043F8(ctx, base);
	// lwz r3,-18004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// bl 0x82304348
	ctx.lr = 0x8213103C;
	sub_82304348(ctx, base);
loc_8213103C:
	// li r11,-1
	r11.s64 = -1;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r3,r10,2764
	ctx.r3.s64 = ctx.r10.s64 + 2764;
	// bl 0x821c0750
	ctx.lr = 0x82131058;
	sub_821C0750(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r31,r11,29952
	r31.s64 = r11.s64 + 29952;
	// beq cr6,0x82131080
	if (cr6.eq) goto loc_82131080;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x82131080
	if (!cr6.eq) goto loc_82131080;
	// bl 0x82130000
	ctx.lr = 0x82131080;
	sub_82130000(ctx, base);
loc_82131080:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r11,2744
	ctx.r3.s64 = r11.s64 + 2744;
	// bl 0x821c0750
	ctx.lr = 0x82131090;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821310b0
	if (cr6.eq) goto loc_821310B0;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x821310b0
	if (!cr6.eq) goto loc_821310B0;
	// bl 0x82130000
	ctx.lr = 0x821310B0;
	sub_82130000(ctx, base);
loc_821310B0:
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2456);
	// bl 0x822c0980
	ctx.lr = 0x821310BC;
	sub_822C0980(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821310d0
	if (cr6.eq) goto loc_821310D0;
	// bl 0x821fc008
	ctx.lr = 0x821310D0;
	sub_821FC008(ctx, base);
loc_821310D0:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821310e4
	if (!cr6.eq) goto loc_821310E4;
	// lwz r3,-18004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// bl 0x82304398
	ctx.lr = 0x821310E4;
	sub_82304398(ctx, base);
loc_821310E4:
	// lwz r3,2456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2456);
	// bl 0x822bf208
	ctx.lr = 0x821310EC;
	sub_822BF208(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821310F4"))) PPC_WEAK_FUNC(sub_821310F4);
PPC_FUNC_IMPL(__imp__sub_821310F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821310F8"))) PPC_WEAK_FUNC(sub_821310F8);
PPC_FUNC_IMPL(__imp__sub_821310F8) {
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
	ctx.lr = 0x82131100;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// beq cr6,0x82131198
	if (cr6.eq) goto loc_82131198;
	// lbz r30,157(r1)
	r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 157);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r11,r10,5160
	r11.s64 = ctx.r10.s64 + 5160;
	// addi r9,r30,-128
	ctx.r9.s64 = r30.s64 + -128;
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// rlwinm r31,r9,3,0,28
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130d70
	ctx.lr = 0x82131134;
	sub_82130D70(ctx, base);
	// lwzx r8,r31,r29
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmpwi cr6,r30,130
	cr6.compare<int32_t>(r30.s32, 130, xer);
	// subf r7,r3,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r3.s64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stwx r7,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r7.u32);
	// bne cr6,0x82131190
	if (!cr6.eq) goto loc_82131190;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,28
	r31.s64 = 28;
	// rlwinm r10,r28,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x80000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,-12464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12464);
	// lwzx r29,r31,r30
	r29.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// beq cr6,0x82131180
	if (cr6.eq) goto loc_82131180;
	// bl 0x82135ff0
	ctx.lr = 0x82131174;
	sub_82135FF0(ctx, base);
	// stwx r29,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82131180:
	// bl 0x82135fd8
	ctx.lr = 0x82131184;
	sub_82135FD8(ctx, base);
	// stwx r29,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82131190:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82131d10
	ctx.lr = 0x82131198;
	sub_82131D10(ctx, base);
loc_82131198:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821311A0"))) PPC_WEAK_FUNC(sub_821311A0);
PPC_FUNC_IMPL(__imp__sub_821311A0) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,48
	ctx.r4.s64 = 48;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821311D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82131204
	if (cr6.eq) goto loc_82131204;
	// bl 0x821c0580
	ctx.lr = 0x821311E8;
	sub_821C0580(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r31,2828(r11)
	PPC_STORE_U32(r11.u32 + 2828, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82131204:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2828, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131224"))) PPC_WEAK_FUNC(sub_82131224);
PPC_FUNC_IMPL(__imp__sub_82131224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131228"))) PPC_WEAK_FUNC(sub_82131228);
PPC_FUNC_IMPL(__imp__sub_82131228) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82131230;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r24,r11,3608
	r24.s64 = r11.s64 + 3608;
	// addi r21,r10,3288
	r21.s64 = ctx.r10.s64 + 3288;
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821312a8
	if (!cr6.eq) goto loc_821312A8;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// li r30,0
	r30.s64 = 0;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x82131c08
	ctx.lr = 0x82131268;
	sub_82131C08(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823d90b0
	ctx.lr = 0x82131270;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213127c
	if (cr6.eq) goto loc_8213127C;
	// li r30,8192
	r30.s64 = 8192;
loc_8213127C:
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r11,r11,-17920
	r11.s64 = r11.s64 + -17920;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r4,r11,10,0,21
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// bl 0x821c2e60
	ctx.lr = 0x82131298;
	sub_821C2E60(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30992
	ctx.r3.s64 = ctx.r10.s64 + -30992;
	// bl 0x823d9a98
	ctx.lr = 0x821312A4;
	sub_823D9A98(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
loc_821312A8:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821312d0
	if (!cr6.eq) goto loc_821312D0;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// li r3,12288
	ctx.r3.s64 = 12288;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x821bc0d8
	ctx.lr = 0x821312C8;
	sub_821BC0D8(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
	// stw r3,3284(r28)
	PPC_STORE_U32(r28.u32 + 3284, ctx.r3.u32);
loc_821312D0:
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// lis r22,-32125
	r22.s64 = -2105344000;
	// ori r30,r9,44544
	r30.u64 = ctx.r9.u64 | 44544;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82131338
	if (!cr6.eq) goto loc_82131338;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// li r29,0
	r29.s64 = 0;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x82131c08
	ctx.lr = 0x821312F8;
	sub_82131C08(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823d90b0
	ctx.lr = 0x82131300;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213130c
	if (cr6.eq) goto loc_8213130C;
	// li r29,8192
	r29.s64 = 8192;
loc_8213130C:
	// bl 0x82130ec0
	ctx.lr = 0x82131310;
	sub_82130EC0(ctx, base);
	// subf r11,r29,r30
	r11.s64 = r30.s64 - r29.s64;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// srawi r9,r10,5
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x821bc0d8
	ctx.lr = 0x82131330;
	sub_821BC0D8(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
	// stw r3,3280(r22)
	PPC_STORE_U32(r22.u32 + 3280, ctx.r3.u32);
loc_82131338:
	// rlwinm r9,r11,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r23,r10,3088
	r23.s64 = ctx.r10.s64 + 3088;
	// bne cr6,0x82131388
	if (!cr6.eq) goto loc_82131388;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// lwz r29,3284(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 3284);
	// lis r3,128
	ctx.r3.s64 = 8388608;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x821bc0f0
	ctx.lr = 0x82131360;
	sub_821BC0F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r6,2048
	ctx.r6.s64 = 2048;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x821c0f80
	ctx.lr = 0x82131378;
	sub_821C0F80(ctx, base);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-31008
	ctx.r3.s64 = r11.s64 + -31008;
	// bl 0x823d9a98
	ctx.lr = 0x82131384;
	sub_823D9A98(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
loc_82131388:
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ori r26,r8,32768
	r26.u64 = ctx.r8.u64 | 32768;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r25,r10,2896
	r25.s64 = ctx.r10.s64 + 2896;
	// bne cr6,0x82131438
	if (!cr6.eq) goto loc_82131438;
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// li r27,0
	r27.s64 = 0;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x82131c08
	ctx.lr = 0x821313B4;
	sub_82131C08(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823d90b0
	ctx.lr = 0x821313BC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821313c8
	if (cr6.eq) goto loc_821313C8;
	// li r27,8192
	r27.s64 = 8192;
loc_821313C8:
	// li r28,0
	r28.s64 = 0;
	// bl 0x82131c08
	ctx.lr = 0x821313D0;
	sub_82131C08(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823d90b0
	ctx.lr = 0x821313D8;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821313e4
	if (cr6.eq) goto loc_821313E4;
	// li r28,8192
	r28.s64 = 8192;
loc_821313E4:
	// lwz r29,3280(r22)
	r29.u64 = PPC_LOAD_U32(r22.u32 + 3280);
	// bl 0x82130ec0
	ctx.lr = 0x821313EC;
	sub_82130EC0(ctx, base);
	// subf r11,r27,r30
	r11.s64 = r30.s64 - r27.s64;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// srawi r9,r10,5
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// addze r27,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	r27.s64 = temp.s64;
	// bl 0x82130ec0
	ctx.lr = 0x82131400;
	sub_82130EC0(ctx, base);
	// subf r8,r28,r30
	ctx.r8.s64 = r30.s64 - r28.s64;
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// rlwinm r3,r7,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// bl 0x821bc0f0
	ctx.lr = 0x82131410;
	sub_821BC0F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x821c0f80
	ctx.lr = 0x82131428;
	sub_821C0F80(ctx, base);
	// lis r6,-32132
	ctx.r6.s64 = -2105802752;
	// addi r3,r6,-31024
	ctx.r3.s64 = ctx.r6.s64 + -31024;
	// bl 0x823d9a98
	ctx.lr = 0x82131434;
	sub_823D9A98(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
loc_82131438:
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r30,r10,2880
	r30.s64 = ctx.r10.s64 + 2880;
	// bne cr6,0x82131480
	if (!cr6.eq) goto loc_82131480;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r23,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r23.u32);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// stw r25,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r25.u32);
	// addi r10,r10,3236
	ctx.r10.s64 = ctx.r10.s64 + 3236;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r3,r11,-31048
	ctx.r3.s64 = r11.s64 + -31048;
	// stw r10,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r10.u32);
	// bl 0x823d9a98
	ctx.lr = 0x8213147C;
	sub_823D9A98(ctx, base);
	// lwz r11,5596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5596);
loc_82131480:
	// rlwinm r9,r11,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r29,r10,2840
	r29.s64 = ctx.r10.s64 + 2840;
	// bne cr6,0x821314b0
	if (!cr6.eq) goto loc_821314B0;
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,5596(r31)
	PPC_STORE_U32(r31.u32 + 5596, r11.u32);
	// bl 0x821c08a8
	ctx.lr = 0x821314A4;
	sub_821C08A8(ctx, base);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-31064
	ctx.r3.s64 = r11.s64 + -31064;
	// bl 0x823d9a98
	ctx.lr = 0x821314B0;
	sub_823D9A98(ctx, base);
loc_821314B0:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c08d0
	ctx.lr = 0x821314BC;
	sub_821C08D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c08d0
	ctx.lr = 0x821314C8;
	sub_821C08D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c08d0
	ctx.lr = 0x821314D4;
	sub_821C08D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c08d0
	ctx.lr = 0x821314E0;
	sub_821C08D0(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,12
	ctx.r8.s64 = 12;
	// stwx r29,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r29.u32);
	// stwx r29,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r29.u32);
	// stwx r29,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82131504"))) PPC_WEAK_FUNC(sub_82131504);
PPC_FUNC_IMPL(__imp__sub_82131504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131508"))) PPC_WEAK_FUNC(sub_82131508);
PPC_FUNC_IMPL(__imp__sub_82131508) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82131510;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,2492
	ctx.r10.s64 = r11.s64 + 2492;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82131538
	if (cr6.eq) goto loc_82131538;
	// bl 0x82322c78
	ctx.lr = 0x8213152C;
	sub_82322C78(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,64
	r11.s64 = 4194304;
	// stw r11,17156(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17156, r11.u32);
loc_82131538:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,2448
	r31.s64 = r11.s64 + 2448;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82304708
	ctx.lr = 0x82131548;
	sub_82304708(ctx, base);
	// bl 0x822bf880
	ctx.lr = 0x8213154C;
	sub_822BF880(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// bl 0x822c2ea8
	ctx.lr = 0x82131554;
	sub_822C2EA8(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822bf970
	ctx.lr = 0x8213155C;
	sub_822BF970(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// bl 0x821ffc28
	ctx.lr = 0x82131568;
	sub_821FFC28(ctx, base);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r11,2836(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821315d8
	if (cr6.eq) goto loc_821315D8;
	// bl 0x822c4eb8
	ctx.lr = 0x82131580;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c4ec8
	ctx.lr = 0x82131588;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821315a4
	if (cr6.eq) goto loc_821315A4;
	// bl 0x822c4eb8
	ctx.lr = 0x82131594;
	sub_822C4EB8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,3804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822c52c8
	ctx.lr = 0x821315A4;
	sub_822C52C8(ctx, base);
loc_821315A4:
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305740
	ctx.lr = 0x821315AC;
	sub_82305740(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,2836(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2836);
	// bl 0x821f9900
	ctx.lr = 0x821315B8;
	sub_821F9900(ctx, base);
loc_821315B8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821315b8
	if (cr6.eq) goto loc_821315B8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// ld r10,2736(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 2736);
	// bl 0x821c31b8
	ctx.lr = 0x821315D4;
	sub_821C31B8(ctx, base);
	// b 0x821315e8
	goto loc_821315E8;
loc_821315D8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5b00
	ctx.lr = 0x821315E8;
	sub_822E5B00(ctx, base);
loc_821315E8:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lwz r30,-17944(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,4104
	ctx.r4.s64 = r11.s64 + 4104;
	// bl 0x821c2fd8
	ctx.lr = 0x821315FC;
	sub_821C2FD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82305690
	ctx.lr = 0x8213160C;
	sub_82305690(ctx, base);
	// li r30,-1
	r30.s64 = -1;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,2672
	ctx.r3.s64 = ctx.r10.s64 + 2672;
	// bl 0x821c0750
	ctx.lr = 0x82131624;
	sub_821C0750(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r9,2552
	ctx.r3.s64 = ctx.r9.s64 + 2552;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x821c0750
	ctx.lr = 0x8213163C;
	sub_821C0750(ctx, base);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r7,2804
	ctx.r3.s64 = ctx.r7.s64 + 2804;
	// bl 0x821c0750
	ctx.lr = 0x82131650;
	sub_821C0750(ctx, base);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r6,2572
	ctx.r3.s64 = ctx.r6.s64 + 2572;
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// bl 0x821c0750
	ctx.lr = 0x82131668;
	sub_821C0750(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lis r26,-32125
	r26.s64 = -2105344000;
	// addi r25,r11,29952
	r25.s64 = r11.s64 + 29952;
	// addi r28,r10,-6420
	r28.s64 = ctx.r10.s64 + -6420;
loc_82131688:
	// lwz r3,-18004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// bl 0x823042d8
	ctx.lr = 0x82131690;
	sub_823042D8(ctx, base);
	// lwz r3,-3624(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// bl 0x8226fd30
	ctx.lr = 0x82131698;
	sub_8226FD30(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822c1fa8
	ctx.lr = 0x821316A0;
	sub_822C1FA8(ctx, base);
	// lwz r3,2464(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 2464);
	// bl 0x822c4bd8
	ctx.lr = 0x821316A8;
	sub_822C4BD8(ctx, base);
	// lwz r3,-18004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// bl 0x82304330
	ctx.lr = 0x821316B0;
	sub_82304330(ctx, base);
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305d00
	ctx.lr = 0x821316B8;
	sub_82305D00(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821316cc
	if (!cr6.eq) goto loc_821316CC;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822bf110
	ctx.lr = 0x821316CC;
	sub_822BF110(ctx, base);
loc_821316CC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821316ec
	if (cr6.eq) goto loc_821316EC;
	// lwz r11,44(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 44);
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821316ec
	if (!cr6.eq) goto loc_821316EC;
	// bl 0x821bdd28
	ctx.lr = 0x821316EC;
	sub_821BDD28(ctx, base);
loc_821316EC:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821776b8
	ctx.lr = 0x821316F4;
	sub_821776B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213170c
	if (!cr6.eq) goto loc_8213170C;
	// lbz r11,18268(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 18268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82131688
	if (cr6.eq) goto loc_82131688;
loc_8213170C:
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305740
	ctx.lr = 0x82131714;
	sub_82305740(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8213171C"))) PPC_WEAK_FUNC(sub_8213171C);
PPC_FUNC_IMPL(__imp__sub_8213171C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131720"))) PPC_WEAK_FUNC(sub_82131720);
PPC_FUNC_IMPL(__imp__sub_82131720) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r31,2828(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8213176c
	if (cr6.eq) goto loc_8213176C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c0688
	ctx.lr = 0x8213174C;
	sub_821C0688(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213176C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213176C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r30)
	PPC_STORE_U32(r30.u32 + 2828, r11.u32);
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

__attribute__((alias("__imp__sub_8213178C"))) PPC_WEAK_FUNC(sub_8213178C);
PPC_FUNC_IMPL(__imp__sub_8213178C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131790"))) PPC_WEAK_FUNC(sub_82131790);
PPC_FUNC_IMPL(__imp__sub_82131790) {
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
	ctx.lr = 0x82131798;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r9,r10,2712
	ctx.r9.s64 = ctx.r10.s64 + 2712;
	// addi r26,r11,2456
	r26.s64 = r11.s64 + 2456;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r10,1656
	ctx.r10.s64 = ctx.r10.s64 + 1656;
	// stb r11,-20(r26)
	PPC_STORE_U8(r26.u32 + -20, r11.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,-352(r8)
	PPC_STORE_U32(ctx.r8.u32 + -352, ctx.r10.u32);
	// beq cr6,0x82131844
	if (cr6.eq) goto loc_82131844;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823d96e0
	ctx.lr = 0x821317D8;
	sub_823D96E0(ctx, base);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823d9680
	ctx.lr = 0x821317E4;
	sub_823D9680(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,4088
	ctx.r5.s64 = r11.s64 + 4088;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823da938
	ctx.lr = 0x821317FC;
	sub_823DA938(ctx, base);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// addi r3,r10,2352
	ctx.r3.s64 = ctx.r10.s64 + 2352;
	// bl 0x821bdcd8
	ctx.lr = 0x82131808;
	sub_821BDCD8(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// addi r3,r9,2584
	ctx.r3.s64 = ctx.r9.s64 + 2584;
	// bl 0x821bdce8
	ctx.lr = 0x82131814;
	sub_821BDCE8(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// addi r11,r11,1680
	r11.s64 = r11.s64 + 1680;
	// addi r10,r10,1904
	ctx.r10.s64 = ctx.r10.s64 + 1904;
	// addi r9,r9,2128
	ctx.r9.s64 = ctx.r9.s64 + 2128;
	// stw r11,-11824(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11824, r11.u32);
	// stw r10,-11840(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11840, ctx.r10.u32);
	// stw r9,-11828(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11828, ctx.r9.u32);
loc_82131844:
	// bl 0x82388300
	ctx.lr = 0x82131848;
	sub_82388300(ctx, base);
	// bl 0x82387870
	ctx.lr = 0x8213184C;
	sub_82387870(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// ori r31,r11,32768
	r31.u64 = r11.u64 | 32768;
	// addi r3,r10,4068
	ctx.r3.s64 = ctx.r10.s64 + 4068;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x821c4a70
	ctx.lr = 0x82131874;
	sub_821C4A70(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r9,4044
	ctx.r3.s64 = ctx.r9.s64 + 4044;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,10
	ctx.r7.s64 = 10;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x821c4a70
	ctx.lr = 0x82131894;
	sub_821C4A70(ctx, base);
	// bl 0x821717e8
	ctx.lr = 0x82131898;
	sub_821717E8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r8,4024
	ctx.r3.s64 = ctx.r8.s64 + 4024;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x821c4a70
	ctx.lr = 0x821318B8;
	sub_821C4A70(ctx, base);
	// bl 0x821e60b0
	ctx.lr = 0x821318BC;
	sub_821E60B0(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r7,4000
	ctx.r3.s64 = ctx.r7.s64 + 4000;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,10
	ctx.r7.s64 = 10;
	// li r6,-2
	ctx.r6.s64 = -2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c4a70
	ctx.lr = 0x821318DC;
	sub_821C4A70(ctx, base);
	// bl 0x8216c7b8
	ctx.lr = 0x821318E0;
	sub_8216C7B8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lis r5,-32119
	ctx.r5.s64 = -2104950784;
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r11,r11,-12712
	r11.s64 = r11.s64 + -12712;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r6,r6,-27192
	ctx.r6.s64 = ctx.r6.s64 + -27192;
	// addi r5,r5,-17772
	ctx.r5.s64 = ctx.r5.s64 + -17772;
	// addi r4,r4,-17980
	ctx.r4.s64 = ctx.r4.s64 + -17980;
	// addi r3,r3,18608
	ctx.r3.s64 = ctx.r3.s64 + 18608;
	// addi r9,r9,-17528
	ctx.r9.s64 = ctx.r9.s64 + -17528;
	// addi r8,r8,-17792
	ctx.r8.s64 = ctx.r8.s64 + -17792;
	// addi r7,r7,17236
	ctx.r7.s64 = ctx.r7.s64 + 17236;
	// addi r30,r10,3998
	r30.s64 = ctx.r10.s64 + 3998;
	// stw r30,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r30.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r30,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r30.u32);
	// stw r30,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// stw r30,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r30.u32);
	// stw r30,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r30.u32);
	// bne cr6,0x8213195c
	if (!cr6.eq) goto loc_8213195C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r10,r10,3996
	ctx.r10.s64 = ctx.r10.s64 + 3996;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8213195C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r31,r11,-27172
	r31.s64 = r11.s64 + -27172;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82131984
	if (!cr6.eq) goto loc_82131984;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,3992
	r11.s64 = r11.s64 + 3992;
	// b 0x821319a4
	goto loc_821319A4;
loc_82131984:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821c0750
	ctx.lr = 0x82131990;
	sub_821C0750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821319a8
	if (!cr6.eq) goto loc_821319A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,3988
	r11.s64 = r11.s64 + 3988;
loc_821319A4:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_821319A8:
	// bl 0x82388848
	ctx.lr = 0x821319AC;
	sub_82388848(ctx, base);
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,28
	r27.s64 = 28;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,496
	ctx.r4.s64 = 496;
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821319D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821319f8
	if (cr6.eq) goto loc_821319F8;
	// bl 0x82177700
	ctx.lr = 0x821319E4;
	sub_82177700(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,3768
	ctx.r10.s64 = r11.s64 + 3768;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x821319fc
	goto loc_821319FC;
loc_821319F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821319FC:
	// stw r3,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r31,r11,3912
	r31.s64 = r11.s64 + 3912;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823063f0
	ctx.lr = 0x82131A14;
	sub_823063F0(ctx, base);
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// ori r4,r4,56
	ctx.r4.u64 = ctx.r4.u64 | 56;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82131A38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82131a5c
	if (cr6.eq) goto loc_82131A5C;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4630
	ctx.lr = 0x82131A4C;
	sub_822C4630(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r11,2464
	r29.s64 = r11.s64 + 2464;
	// stw r3,2464(r11)
	PPC_STORE_U32(r11.u32 + 2464, ctx.r3.u32);
	// b 0x82131a6c
	goto loc_82131A6C;
loc_82131A5C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// addi r29,r10,2464
	r29.s64 = ctx.r10.s64 + 2464;
	// stw r11,2464(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2464, r11.u32);
loc_82131A6C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r11,2592
	ctx.r9.s64 = r11.s64 + 2592;
	// li r11,1
	r11.s64 = 1;
	// stw r11,30516(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30516, r11.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82131a98
	if (!cr6.eq) goto loc_82131A98;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,2492
	ctx.r10.s64 = r11.s64 + 2492;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
loc_82131A98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,18628
	r11.s64 = r11.s64 + 18628;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82131ab8
	if (!cr6.eq) goto loc_82131AB8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r10,r10,3808
	ctx.r10.s64 = ctx.r10.s64 + 3808;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82131AB8:
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82131b08
	if (!cr6.eq) goto loc_82131B08;
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,48
	ctx.r4.s64 = 48;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82131AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82131b00
	if (cr6.eq) goto loc_82131B00;
	// bl 0x821c0580
	ctx.lr = 0x82131AF8;
	sub_821C0580(ctx, base);
	// stw r30,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r30.u32);
	// b 0x82131b08
	goto loc_82131B08;
loc_82131B00:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_82131B08:
	// bl 0x821c4210
	ctx.lr = 0x82131B0C;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x82131B30;
	sub_821C05E8(ctx, base);
	// bl 0x82306398
	ctx.lr = 0x82131B34;
	sub_82306398(ctx, base);
	// bl 0x82306118
	ctx.lr = 0x82131B38;
	sub_82306118(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-17932(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17932);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82131b58
	if (!cr6.gt) goto loc_82131B58;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,-2
	ctx.r3.s64 = -2;
	// bl 0x82131e48
	ctx.lr = 0x82131B54;
	sub_82131E48(ctx, base);
	// bl 0x82131ef8
	ctx.lr = 0x82131B58;
	sub_82131EF8(ctx, base);
loc_82131B58:
	// bl 0x82131508
	ctx.lr = 0x82131B5C;
	sub_82131508(ctx, base);
	// bl 0x82306178
	ctx.lr = 0x82131B60;
	sub_82306178(ctx, base);
	// bl 0x82305640
	ctx.lr = 0x82131B64;
	sub_82305640(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lbz r11,18268(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 18268);
	// stb r11,-20(r26)
	PPC_STORE_U8(r26.u32 + -20, r11.u8);
	// bl 0x822c1920
	ctx.lr = 0x82131B78;
	sub_822C1920(ctx, base);
	// bl 0x822c18d0
	ctx.lr = 0x82131B7C;
	sub_822C18D0(ctx, base);
	// bl 0x82242cc8
	ctx.lr = 0x82131B80;
	sub_82242CC8(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82131ba0
	if (cr6.eq) goto loc_82131BA0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82131BA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82131BA0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x823051d8
	ctx.lr = 0x82131BAC;
	sub_823051D8(ctx, base);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x82131BB4;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82131bf4
	if (cr6.eq) goto loc_82131BF4;
	// lwz r30,2828(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82131bec
	if (cr6.eq) goto loc_82131BEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c0688
	ctx.lr = 0x82131BD4;
	sub_821C0688(ctx, base);
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82131BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82131BEC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_82131BF4:
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x82131BFC;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82131C08"))) PPC_WEAK_FUNC(sub_82131C08);
PPC_FUNC_IMPL(__imp__sub_82131C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,2548(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2548);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131C14"))) PPC_WEAK_FUNC(sub_82131C14);
PPC_FUNC_IMPL(__imp__sub_82131C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C18"))) PPC_WEAK_FUNC(sub_82131C18);
PPC_FUNC_IMPL(__imp__sub_82131C18) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcd94
	__imp__XamShowSigninUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C1C"))) PPC_WEAK_FUNC(sub_82131C1C);
PPC_FUNC_IMPL(__imp__sub_82131C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C20"))) PPC_WEAK_FUNC(sub_82131C20);
PPC_FUNC_IMPL(__imp__sub_82131C20) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcda4
	__imp__XamShowFriendsUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C24"))) PPC_WEAK_FUNC(sub_82131C24);
PPC_FUNC_IMPL(__imp__sub_82131C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C28"))) PPC_WEAK_FUNC(sub_82131C28);
PPC_FUNC_IMPL(__imp__sub_82131C28) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x827bcdb4
	__imp__XamShowGamerCardUIForXUID(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C30"))) PPC_WEAK_FUNC(sub_82131C30);
PPC_FUNC_IMPL(__imp__sub_82131C30) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x827bcdc4
	__imp__XamShowAchievementsUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C38"))) PPC_WEAK_FUNC(sub_82131C38);
PPC_FUNC_IMPL(__imp__sub_82131C38) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcdd4
	__imp__XamShowPlayerReviewUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C3C"))) PPC_WEAK_FUNC(sub_82131C3C);
PPC_FUNC_IMPL(__imp__sub_82131C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C40"))) PPC_WEAK_FUNC(sub_82131C40);
PPC_FUNC_IMPL(__imp__sub_82131C40) {
	PPC_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// b 0x827bcde4
	__imp__XamShowMarketplaceUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C50"))) PPC_WEAK_FUNC(sub_82131C50);
PPC_FUNC_IMPL(__imp__sub_82131C50) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcdf4
	__imp__XamShowDeviceSelectorUI(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131C54"))) PPC_WEAK_FUNC(sub_82131C54);
PPC_FUNC_IMPL(__imp__sub_82131C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C58"))) PPC_WEAK_FUNC(sub_82131C58);
PPC_FUNC_IMPL(__imp__sub_82131C58) {
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
	// bl 0x827bce04
	ctx.lr = 0x82131C68;
	__imp__XamShowDirtyDiscErrorUI(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821324a0
	ctx.lr = 0x82131C74;
	sub_821324A0(ctx, base);
}

__attribute__((alias("__imp__sub_82131C74"))) PPC_WEAK_FUNC(sub_82131C74);
PPC_FUNC_IMPL(__imp__sub_82131C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131C78"))) PPC_WEAK_FUNC(sub_82131C78);
PPC_FUNC_IMPL(__imp__sub_82131C78) {
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
	ctx.lr = 0x82131C80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm. r11,r31,0,0,0
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82131cf0
	if (cr0.eq) goto loc_82131CF0;
	// rlwinm. r11,r31,0,4,7
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xF000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82131ca4
	if (!cr0.eq) goto loc_82131CA4;
	// li r11,3
	r11.s64 = 3;
	// rlwimi r31,r11,26,4,7
	r31.u64 = (__builtin_rotateleft32(r11.u32, 26) & 0xF000000) | (r31.u64 & 0xFFFFFFFFF0FFFFFF);
loc_82131CA4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// rlwinm r10,r31,6,28,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xC;
	// addi r11,r11,5508
	r11.s64 = r11.s64 + 5508;
	// rlwinm r9,r31,8,28,31
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xF;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// slw r5,r8,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x82132578
	ctx.lr = 0x82131CCC;
	sub_82132578(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82131d00
	if (cr0.eq) goto loc_82131D00;
	// rlwinm. r11,r31,0,1,1
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82131d00
	if (cr0.eq) goto loc_82131D00;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x82131CEC;
	sub_823D9890(ctx, base);
	// b 0x82131d00
	goto loc_82131D00;
loc_82131CF0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r3,r31,8,25,25
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0x40;
	// bl 0x82132530
	ctx.lr = 0x82131CFC;
	sub_82132530(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82131D00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82131D0C"))) PPC_WEAK_FUNC(sub_82131D0C);
PPC_FUNC_IMPL(__imp__sub_82131D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131D10"))) PPC_WEAK_FUNC(sub_82131D10);
PPC_FUNC_IMPL(__imp__sub_82131D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm. r11,r4,0,0,0
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82131d24
	if (cr0.eq) goto loc_82131D24;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82132608
	sub_82132608(ctx, base);
	return;
loc_82131D24:
	// b 0x82132620
	sub_82132620(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131D28"))) PPC_WEAK_FUNC(sub_82131D28);
PPC_FUNC_IMPL(__imp__sub_82131D28) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131D2C"))) PPC_WEAK_FUNC(sub_82131D2C);
PPC_FUNC_IMPL(__imp__sub_82131D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131D30"))) PPC_WEAK_FUNC(sub_82131D30);
PPC_FUNC_IMPL(__imp__sub_82131D30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// rlwinm. r11,r4,0,0,0
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82131d3c
	if (cr0.eq) goto loc_82131D3C;
	// b 0x82132600
	sub_82132600(ctx, base);
	return;
loc_82131D3C:
	// b 0x82132668
	sub_82132668(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131D40"))) PPC_WEAK_FUNC(sub_82131D40);
PPC_FUNC_IMPL(__imp__sub_82131D40) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r4,2532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 2532);
	// bl 0x827bce84
	ctx.lr = 0x82131D64;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82131da4
	if (cr0.lt) goto loc_82131DA4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmpwi cr6,r31,15
	cr6.compare<int32_t>(r31.s32, 15, xer);
	// bne cr6,0x82131d80
	if (!cr6.eq) goto loc_82131D80;
	// li r4,16
	ctx.r4.s64 = 16;
	// b 0x82131d8c
	goto loc_82131D8C;
loc_82131D80:
	// cmpwi cr6,r31,-15
	cr6.compare<int32_t>(r31.s32, -15, xer);
	// bne cr6,0x82131d8c
	if (!cr6.eq) goto loc_82131D8C;
	// li r4,-16
	ctx.r4.s64 = -16;
loc_82131D8C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce74
	ctx.lr = 0x82131D94;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x82131D9C;
	__imp__ObDereferenceObject(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82131dac
	goto loc_82131DAC;
loc_82131DA4:
	// bl 0x821326a0
	ctx.lr = 0x82131DA8;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82131DAC:
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

__attribute__((alias("__imp__sub_82131DC0"))) PPC_WEAK_FUNC(sub_82131DC0);
PPC_FUNC_IMPL(__imp__sub_82131DC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r4,2532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 2532);
	// bl 0x827bce84
	ctx.lr = 0x82131DE4;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82131e10
	if (cr0.lt) goto loc_82131E10;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r4,r11,1
	ctx.r4.u64 = r11.u64 ^ 1;
	// bl 0x827bce94
	ctx.lr = 0x82131E00;
	__imp__KeSetDisableBoostThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x82131E08;
	__imp__ObDereferenceObject(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82131e18
	goto loc_82131E18;
loc_82131E10:
	// bl 0x821326a0
	ctx.lr = 0x82131E14;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82131E18:
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

__attribute__((alias("__imp__sub_82131E2C"))) PPC_WEAK_FUNC(sub_82131E2C);
PPC_FUNC_IMPL(__imp__sub_82131E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131E30"))) PPC_WEAK_FUNC(sub_82131E30);
PPC_FUNC_IMPL(__imp__sub_82131E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-23128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23128);
	// stw r11,-23128(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23128, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131E44"))) PPC_WEAK_FUNC(sub_82131E44);
PPC_FUNC_IMPL(__imp__sub_82131E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131E48"))) PPC_WEAK_FUNC(sub_82131E48);
PPC_FUNC_IMPL(__imp__sub_82131E48) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// bge cr6,0x82131ea4
	if (!cr6.lt) goto loc_82131EA4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,2532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 2532);
	// bl 0x827bce84
	ctx.lr = 0x82131E78;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x82131ed4
	if (cr0.lt) goto loc_82131ED4;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// slw r4,r11,r30
	ctx.r4.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// bl 0x827bcea4
	ctx.lr = 0x82131E94;
	__imp__KeSetAffinityThread(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x82131EA0;
	__imp__ObDereferenceObject(ctx, base);
	// b 0x82131eac
	goto loc_82131EAC;
loc_82131EA4:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,13
	r31.u64 = r31.u64 | 13;
loc_82131EAC:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82131ed4
	if (cr6.lt) goto loc_82131ED4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82131ecc
	if (cr6.eq) goto loc_82131ECC;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r3,r11,31
	xer.ca = r11.u32 <= 31;
	ctx.r3.s64 = 31 - r11.s64;
	// b 0x82131ee0
	goto loc_82131EE0;
loc_82131ECC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82131ee0
	goto loc_82131EE0;
loc_82131ED4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821326a0
	ctx.lr = 0x82131EDC;
	sub_821326A0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82131EE0:
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

__attribute__((alias("__imp__sub_82131EF8"))) PPC_WEAK_FUNC(sub_82131EF8);
PPC_FUNC_IMPL(__imp__sub_82131EF8) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,268(r13)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131F00"))) PPC_WEAK_FUNC(sub_82131F00);
PPC_FUNC_IMPL(__imp__sub_82131F00) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,2024(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2024);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82131f40
	if (cr6.eq) goto loc_82131F40;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82131F3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82131f44
	goto loc_82131F44;
loc_82131F40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82131F44:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82131f78
	if (!cr6.eq) goto loc_82131F78;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r10,-23128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -23128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82131f78
	if (cr6.eq) goto loc_82131F78;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82131F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// beq cr6,0x82131f7c
	if (cr6.eq) goto loc_82131F7C;
loc_82131F78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82131F7C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82131F90"))) PPC_WEAK_FUNC(sub_82131F90);
PPC_FUNC_IMPL(__imp__sub_82131F90) {
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
	ctx.lr = 0x82131F98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r4,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r4.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x823d9890
	ctx.lr = 0x82131FC0;
	sub_823D9890(ctx, base);
	// addi r11,r1,108
	r11.s64 = ctx.r1.s64 + 108;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bl 0x827bcec4
	ctx.lr = 0x82131FE0;
	__imp__NtCreateEvent(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82132040
	if (cr0.lt) goto loc_82132040;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,204
	ctx.r7.s64 = ctx.r1.s64 + 204;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x827bce14
	ctx.lr = 0x8213201C;
	__imp__XamShowMessageBoxUIEx(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x82132038
	if (!cr6.eq) goto loc_82132038;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821326a8
	ctx.lr = 0x82132038;
	sub_821326A8(ctx, base);
loc_82132038:
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x827bceb4
	ctx.lr = 0x82132040;
	__imp__NtClose(ctx, base);
loc_82132040:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82132048"))) PPC_WEAK_FUNC(sub_82132048);
PPC_FUNC_IMPL(__imp__sub_82132048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,4312
	r11.s64 = r11.s64 + 4312;
loc_82132058:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmplw cr6,r6,r3
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, xer);
	// bne cr6,0x821320b0
	if (!cr6.eq) goto loc_821320B0;
	// clrlwi. r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x821320a0
	if (cr0.eq) goto loc_821320A0;
	// addi r7,r5,-1
	ctx.r7.s64 = ctx.r5.s64 + -1;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
loc_8213207C:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x821320a0
	if (!cr6.lt) goto loc_821320A0;
	// lhz r31,0(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// sth r31,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, r31.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// blt cr6,0x8213207c
	if (cr6.lt) goto loc_8213207C;
loc_821320A0:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// sthx r9,r10,r4
	PPC_STORE_U16(ctx.r10.u32 + ctx.r4.u32, ctx.r9.u16);
	// b 0x821320b8
	goto loc_821320B8;
loc_821320B0:
	// rlwinm r10,r10,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_821320B8:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplw cr6,r6,r3
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, xer);
	// ble cr6,0x82132058
	if (!cr6.gt) goto loc_82132058;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821320CC"))) PPC_WEAK_FUNC(sub_821320CC);
PPC_FUNC_IMPL(__imp__sub_821320CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821320D0"))) PPC_WEAK_FUNC(sub_821320D0);
PPC_FUNC_IMPL(__imp__sub_821320D0) {
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
	// stwu r1,-800(r1)
	ea = -800 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// li r3,10
	ctx.r3.s64 = 10;
	// mr r31,r30
	r31.u64 = r30.u64;
	// bl 0x827bcee4
	ctx.lr = 0x821320F4;
	__imp__XexCheckExecutablePrivilege(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82132294
	if (cr0.eq) goto loc_82132294;
	// bl 0x827bce34
	ctx.lr = 0x82132100;
	__imp__XGetAVPack(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x82132294
	if (cr6.eq) goto loc_82132294;
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// beq cr6,0x82132294
	if (cr6.eq) goto loc_82132294;
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// beq cr6,0x82132294
	if (cr6.eq) goto loc_82132294;
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// beq cr6,0x82132294
	if (cr6.eq) goto loc_82132294;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x827bced4
	ctx.lr = 0x82132138;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x82132294
	if (!cr0.eq) goto loc_82132294;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r11,0,16,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFF00;
	// cmplwi cr6,r11,768
	cr6.compare<uint32_t>(r11.u32, 768, xer);
	// bne cr6,0x82132294
	if (!cr6.eq) goto loc_82132294;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,10
	ctx.r4.s64 = 10;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x827bced4
	ctx.lr = 0x82132168;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x82132294
	if (!cr0.eq) goto loc_82132294;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm. r10,r11,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82132184
	if (!cr0.eq) goto loc_82132184;
	// rlwinm. r11,r11,0,9,9
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82132294
	if (!cr0.eq) goto loc_82132294;
loc_82132184:
	// bl 0x827bce24
	ctx.lr = 0x82132188;
	__imp__XGetLanguage(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,510
	ctx.r5.s64 = 510;
	// sth r30,256(r1)
	PPC_STORE_U16(ctx.r1.u32 + 256, r30.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,258
	ctx.r3.s64 = ctx.r1.s64 + 258;
	// bl 0x823d9890
	ctx.lr = 0x821321A0;
	sub_823D9890(ctx, base);
	// li r5,62
	ctx.r5.s64 = 62;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r30,192(r1)
	PPC_STORE_U16(ctx.r1.u32 + 192, r30.u16);
	// addi r3,r1,194
	ctx.r3.s64 = ctx.r1.s64 + 194;
	// bl 0x823d9890
	ctx.lr = 0x821321B4;
	sub_823D9890(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r10,13
	ctx.r10.s64 = 13;
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// li r11,16
	r11.s64 = 16;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,14
	ctx.r9.s64 = 14;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r8,17
	ctx.r8.s64 = 17;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// li r11,15
	r11.s64 = 15;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r10,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r9,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// li r11,3
	r11.s64 = 3;
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// cmplwi cr6,r31,10
	cr6.compare<uint32_t>(r31.u32, 10, xer);
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// stw r7,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r7.u32);
	// blt cr6,0x82132254
	if (cr6.lt) goto loc_82132254;
	// li r31,1
	r31.s64 = 1;
loc_82132254:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// rlwinm r31,r31,2,0,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82132048
	ctx.lr = 0x8213226C;
	sub_82132048(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82132048
	ctx.lr = 0x82132280;
	sub_82132048(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82131f90
	ctx.lr = 0x82132290;
	sub_82131F90(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_82132294:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,800
	ctx.r1.s64 = ctx.r1.s64 + 800;
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

__attribute__((alias("__imp__sub_821322B0"))) PPC_WEAK_FUNC(sub_821322B0);
PPC_FUNC_IMPL(__imp__sub_821322B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9288(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9288);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821322C0;
	// addi r31,r1,-496
	r31.s64 = ctx.r1.s64 + -496;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// lis r8,-32107
	ctx.r8.s64 = -2104164352;
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,-22836(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22836, r11.u32);
	// stw r10,-22832(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22832, ctx.r10.u32);
	// bl 0x82132a48
	ctx.lr = 0x821322F0;
	sub_82132A48(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132898
	ctx.lr = 0x821322F8;
	sub_82132898(ctx, base);
	// bl 0x821320d0
	ctx.lr = 0x821322FC;
	sub_821320D0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8213230c
	if (cr0.eq) goto loc_8213230C;
	// bl 0x827bce44
	ctx.lr = 0x82132308;
	__imp__XamLoaderTerminateTitle(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_8213230C:
	// bl 0x823db480
	ctx.lr = 0x82132310;
	sub_823DB480(ctx, base);
	// bl 0x82132820
	ctx.lr = 0x82132314;
	sub_82132820(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132740
	ctx.lr = 0x8213231C;
	sub_82132740(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,5608(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82132444
	if (cr6.eq) goto loc_82132444;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// mr r28,r29
	r28.u64 = r29.u64;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r28,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r28.u32);
	// bl 0x82131c08
	ctx.lr = 0x82132344;
	sub_82131C08(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82132428
	if (cr0.eq) goto loc_82132428;
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
loc_82132358:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
loc_82132360:
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8213239c
	if (cr0.eq) goto loc_8213239C;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x82132378
	if (cr6.eq) goto loc_82132378;
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// bne cr6,0x8213239c
	if (!cr6.eq) goto loc_8213239C;
loc_82132378:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r29,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r29.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82132360
	goto loc_82132360;
loc_8213239C:
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82132414
	if (cr0.eq) goto loc_82132414;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stw r28,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r28.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_821323C0:
	// cmpwi cr6,r9,34
	cr6.compare<int32_t>(ctx.r9.s32, 34, xer);
	// beq cr6,0x821323d8
	if (cr6.eq) goto loc_821323D8;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// b 0x821323e4
	goto loc_821323E4;
loc_821323D8:
	// cntlzw r11,r8
	r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_821323E4:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
	// beq 0x82132414
	if (cr0.eq) goto loc_82132414;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821323c0
	if (!cr6.eq) goto loc_821323C0;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x82132414
	if (cr6.eq) goto loc_82132414;
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// bne cr6,0x821323c0
	if (!cr6.eq) goto loc_821323C0;
loc_82132414:
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82132424
	if (cr0.eq) goto loc_82132424;
	// cmpwi cr6,r28,16
	cr6.compare<int32_t>(r28.s32, 16, xer);
	// ble cr6,0x82132358
	if (!cr6.gt) goto loc_82132358;
loc_82132424:
	// stb r29,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r29.u8);
loc_82132428:
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// b 0x8213244c
	goto loc_8213244C;
loc_82132444:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213244C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821305e8
	ctx.lr = 0x82132454;
	sub_821305E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823db0c0
	ctx.lr = 0x8213245C;
	sub_823DB0C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,6984
	ctx.r3.s64 = r11.s64 + 6984;
	// bl 0x827bcef4
	ctx.lr = 0x8213246C;
	__imp__DbgPrint(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x827bce44
	ctx.lr = 0x8213247C;
	__imp__XamLoaderTerminateTitle(ctx, base);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82131f00
	ctx.lr = 0x8213248C;
	sub_82131F00(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp___xstart"))) PPC_WEAK_FUNC(_xstart);
PPC_FUNC_IMPL(__imp___xstart) {
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
	ctx.lr = 0x821322C0;
	// addi r31,r1,-496
	r31.s64 = ctx.r1.s64 + -496;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// lis r8,-32107
	ctx.r8.s64 = -2104164352;
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,-22836(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22836, r11.u32);
	// stw r10,-22832(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22832, ctx.r10.u32);
	// bl 0x82132a48
	ctx.lr = 0x821322F0;
	sub_82132A48(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132898
	ctx.lr = 0x821322F8;
	sub_82132898(ctx, base);
	// bl 0x821320d0
	ctx.lr = 0x821322FC;
	sub_821320D0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8213230c
	if (cr0.eq) goto loc_8213230C;
	// bl 0x827bce44
	ctx.lr = 0x82132308;
	__imp__XamLoaderTerminateTitle(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_8213230C:
	// bl 0x823db480
	ctx.lr = 0x82132310;
	sub_823DB480(ctx, base);
	// bl 0x82132820
	ctx.lr = 0x82132314;
	sub_82132820(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132740
	ctx.lr = 0x8213231C;
	sub_82132740(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,5608(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82132444
	if (cr6.eq) goto loc_82132444;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// mr r28,r29
	r28.u64 = r29.u64;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r28,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r28.u32);
	// bl 0x82131c08
	ctx.lr = 0x82132344;
	sub_82131C08(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82132428
	if (cr0.eq) goto loc_82132428;
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
loc_82132358:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
loc_82132360:
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8213239c
	if (cr0.eq) goto loc_8213239C;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x82132378
	if (cr6.eq) goto loc_82132378;
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// bne cr6,0x8213239c
	if (!cr6.eq) goto loc_8213239C;
loc_82132378:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stb r29,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r29.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82132360
	goto loc_82132360;
loc_8213239C:
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82132414
	if (cr0.eq) goto loc_82132414;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stw r28,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r28.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_821323C0:
	// cmpwi cr6,r9,34
	cr6.compare<int32_t>(ctx.r9.s32, 34, xer);
	// beq cr6,0x821323d8
	if (cr6.eq) goto loc_821323D8;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// b 0x821323e4
	goto loc_821323E4;
loc_821323D8:
	// cntlzw r11,r8
	r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_821323E4:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
	// beq 0x82132414
	if (cr0.eq) goto loc_82132414;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821323c0
	if (!cr6.eq) goto loc_821323C0;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x82132414
	if (cr6.eq) goto loc_82132414;
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// bne cr6,0x821323c0
	if (!cr6.eq) goto loc_821323C0;
loc_82132414:
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82132424
	if (cr0.eq) goto loc_82132424;
	// cmpwi cr6,r28,16
	cr6.compare<int32_t>(r28.s32, 16, xer);
	// ble cr6,0x82132358
	if (!cr6.gt) goto loc_82132358;
loc_82132424:
	// stb r29,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r29.u8);
loc_82132428:
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// b 0x8213244c
	goto loc_8213244C;
loc_82132444:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213244C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821305e8
	ctx.lr = 0x82132454;
	sub_821305E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823db0c0
	ctx.lr = 0x8213245C;
	sub_823DB0C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,6984
	ctx.r3.s64 = r11.s64 + 6984;
	// bl 0x827bcef4
	ctx.lr = 0x8213246C;
	__imp__DbgPrint(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x827bce44
	ctx.lr = 0x8213247C;
	__imp__XamLoaderTerminateTitle(ctx, base);
}

__attribute__((alias("__imp__sub_8213247C"))) PPC_WEAK_FUNC(sub_8213247C);
PPC_FUNC_IMPL(__imp__sub_8213247C) {
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
	// bl 0x82131f00
	ctx.lr = 0x8213248C;
	sub_82131F00(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821324A0"))) PPC_WEAK_FUNC(sub_821324A0);
PPC_FUNC_IMPL(__imp__sub_821324A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82132528
	if (cr6.eq) goto loc_82132528;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,7028
	ctx.r10.s64 = ctx.r10.s64 + 7028;
loc_821324B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq 0x821324d8
	if (cr0.eq) goto loc_821324D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821324b4
	if (cr6.eq) goto loc_821324B4;
loc_821324D8:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x821324e8
	if (!cr0.eq) goto loc_821324E8;
	// ori r4,r4,2
	ctx.r4.u64 = ctx.r4.u64 | 2;
	// b 0x82132524
	goto loc_82132524;
loc_821324E8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,7008
	ctx.r10.s64 = ctx.r10.s64 + 7008;
loc_821324F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq 0x82132518
	if (cr0.eq) goto loc_82132518;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821324f4
	if (cr6.eq) goto loc_821324F4;
loc_82132518:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82132528
	if (!cr0.eq) goto loc_82132528;
	// ori r4,r4,256
	ctx.r4.u64 = ctx.r4.u64 | 256;
loc_82132524:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82132528:
	// b 0x827bce54
	__imp__XamLoaderLaunchTitle(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213252C"))) PPC_WEAK_FUNC(sub_8213252C);
PPC_FUNC_IMPL(__imp__sub_8213252C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132530"))) PPC_WEAK_FUNC(sub_82132530);
PPC_FUNC_IMPL(__imp__sub_82132530) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82135d28
	ctx.lr = 0x82132550;
	sub_82135D28(ctx, base);
	// rlwinm r4,r31,29,28,28
	ctx.r4.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82134860
	ctx.lr = 0x8213255C;
	sub_82134860(ctx, base);
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

__attribute__((alias("__imp__sub_82132574"))) PPC_WEAK_FUNC(sub_82132574);
PPC_FUNC_IMPL(__imp__sub_82132574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132578"))) PPC_WEAK_FUNC(sub_82132578);
PPC_FUNC_IMPL(__imp__sub_82132578) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r11,5600(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5600);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821325a4
	if (cr6.eq) goto loc_821325A4;
	// rlwinm r5,r5,0,3,1
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFDFFFFFFF;
loc_821325A4:
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x821325c0
	if (cr6.eq) goto loc_821325C0;
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x821325c8
	goto loc_821325C8;
loc_821325C0:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
loc_821325C8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bcf14
	ctx.lr = 0x821325D4;
	__imp__MmAllocatePhysicalMemoryEx(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x821325e4
	if (!cr0.eq) goto loc_821325E4;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82135d38
	ctx.lr = 0x821325E4;
	sub_82135D38(ctx, base);
loc_821325E4:
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

__attribute__((alias("__imp__sub_821325FC"))) PPC_WEAK_FUNC(sub_821325FC);
PPC_FUNC_IMPL(__imp__sub_821325FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132600"))) PPC_WEAK_FUNC(sub_82132600);
PPC_FUNC_IMPL(__imp__sub_82132600) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcf24
	__imp__MmQueryAllocationSize(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82132604"))) PPC_WEAK_FUNC(sub_82132604);
PPC_FUNC_IMPL(__imp__sub_82132604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132608"))) PPC_WEAK_FUNC(sub_82132608);
PPC_FUNC_IMPL(__imp__sub_82132608) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827bcf34
	__imp__MmFreePhysicalMemory(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82132614"))) PPC_WEAK_FUNC(sub_82132614);
PPC_FUNC_IMPL(__imp__sub_82132614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132618"))) PPC_WEAK_FUNC(sub_82132618);
PPC_FUNC_IMPL(__imp__sub_82132618) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bcf44
	__imp__MmQueryAddressProtect(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213261C"))) PPC_WEAK_FUNC(sub_8213261C);
PPC_FUNC_IMPL(__imp__sub_8213261C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132620"))) PPC_WEAK_FUNC(sub_82132620);
PPC_FUNC_IMPL(__imp__sub_82132620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82135d28
	ctx.lr = 0x82132638;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82135150
	ctx.lr = 0x82132644;
	sub_82135150(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne 0x82132654
	if (!cr0.eq) goto loc_82132654;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82132654:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82132668"))) PPC_WEAK_FUNC(sub_82132668);
PPC_FUNC_IMPL(__imp__sub_82132668) {
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
	// bl 0x82135d28
	ctx.lr = 0x82132680;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82133b00
	ctx.lr = 0x8213268C;
	sub_82133B00(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821326A0"))) PPC_WEAK_FUNC(sub_821326A0);
PPC_FUNC_IMPL(__imp__sub_821326A0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82135d58
	sub_82135D58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821326A4"))) PPC_WEAK_FUNC(sub_821326A4);
PPC_FUNC_IMPL(__imp__sub_821326A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821326A8"))) PPC_WEAK_FUNC(sub_821326A8);
PPC_FUNC_IMPL(__imp__sub_821326A8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,997
	cr6.compare<uint32_t>(r11.u32, 997, xer);
	// bne cr6,0x82132714
	if (!cr6.eq) goto loc_82132714;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821326f0
	if (cr6.eq) goto loc_821326F0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821326f0
	if (cr6.eq) goto loc_821326F0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82135db8
	ctx.lr = 0x821326EC;
	sub_82135DB8(ctx, base);
	// b 0x821326f4
	goto loc_821326F4;
loc_821326F0:
	// li r3,258
	ctx.r3.s64 = 258;
loc_821326F4:
	// cmplwi cr6,r3,258
	cr6.compare<uint32_t>(ctx.r3.u32, 258, xer);
	// bne cr6,0x82132704
	if (!cr6.eq) goto loc_82132704;
	// li r3,996
	ctx.r3.s64 = 996;
	// b 0x82132728
	goto loc_82132728;
loc_82132704:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82132714
	if (cr6.eq) goto loc_82132714;
	// bl 0x82135db0
	ctx.lr = 0x82132710;
	sub_82135DB0(ctx, base);
	// b 0x82132728
	goto loc_82132728;
loc_82132714:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82132724
	if (cr6.eq) goto loc_82132724;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_82132724:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82132728:
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

__attribute__((alias("__imp__sub_82132740"))) PPC_WEAK_FUNC(sub_82132740);
PPC_FUNC_IMPL(__imp__sub_82132740) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,-12604(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12604);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82132770
	if (cr6.eq) goto loc_82132770;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82132770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82132770:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r10,5092
	ctx.r10.s64 = ctx.r10.s64 + 5092;
	// addi r30,r11,5104
	r30.s64 = r11.s64 + 5104;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bge cr6,0x821327c0
	if (!cr6.lt) goto loc_821327C0;
loc_82132790:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82132808
	if (!cr6.eq) goto loc_82132808;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821327ac
	if (cr6.eq) goto loc_821327AC;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821327AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821327AC:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x82132790
	if (cr6.lt) goto loc_82132790;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82132808
	if (!cr6.eq) goto loc_82132808;
loc_821327C0:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r30,r11,5088
	r30.s64 = r11.s64 + 5088;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bge cr6,0x82132804
	if (!cr6.lt) goto loc_82132804;
loc_821327DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821327f8
	if (cr6.eq) goto loc_821327F8;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821327f8
	if (cr6.eq) goto loc_821327F8;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821327F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821327F8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x821327dc
	if (cr6.lt) goto loc_821327DC;
loc_82132804:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82132808:
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

__attribute__((alias("__imp__sub_82132820"))) PPC_WEAK_FUNC(sub_82132820);
PPC_FUNC_IMPL(__imp__sub_82132820) {
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
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r10,0
	ctx.r10.s64 = ctx.r10.s64 + 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bge cr6,0x8213287c
	if (!cr6.lt) goto loc_8213287C;
loc_82132854:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8213287c
	if (!cr6.eq) goto loc_8213287C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82132870
	if (cr6.eq) goto loc_82132870;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82132870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82132870:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x82132854
	if (cr6.lt) goto loc_82132854;
loc_8213287C:
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

__attribute__((alias("__imp__sub_82132894"))) PPC_WEAK_FUNC(sub_82132894);
PPC_FUNC_IMPL(__imp__sub_82132894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132898"))) PPC_WEAK_FUNC(sub_82132898);
PPC_FUNC_IMPL(__imp__sub_82132898) {
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
	ctx.lr = 0x821328A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,5524
	r29.s64 = r11.s64 + 5524;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x821328B8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r31,r11,5552
	r31.s64 = r11.s64 + 5552;
	// lwz r11,5552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5552);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// mr r30,r11
	r30.u64 = r11.u64;
	// beq cr6,0x821328f0
	if (cr6.eq) goto loc_821328F0;
loc_821328D0:
	// mr r11,r30
	r11.u64 = r30.u64;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821328E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x821328d0
	if (!cr6.eq) goto loc_821328D0;
loc_821328F0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x821328F8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82132900"))) PPC_WEAK_FUNC(sub_82132900);
PPC_FUNC_IMPL(__imp__sub_82132900) {
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
	ctx.lr = 0x82132908;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,5524
	r30.s64 = r11.s64 + 5524;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x82132924;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8213294c
	if (cr6.eq) goto loc_8213294C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,5552
	ctx.r10.s64 = r11.s64 + 5552;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8213295c
	goto loc_8213295C;
loc_8213294C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8213295C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x82132964;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8213296C"))) PPC_WEAK_FUNC(sub_8213296C);
PPC_FUNC_IMPL(__imp__sub_8213296C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132970"))) PPC_WEAK_FUNC(sub_82132970);
PPC_FUNC_IMPL(__imp__sub_82132970) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r30,16
	r30.s64 = 1048576;
	// lwz r11,1968(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1968);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821329c8
	if (cr6.eq) goto loc_821329C8;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// ori r4,r4,1025
	ctx.r4.u64 = ctx.r4.u64 | 1025;
	// bl 0x827bcf74
	ctx.lr = 0x821329AC;
	__imp__RtlImageXexHeaderField(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x821329c8
	if (cr0.eq) goto loc_821329C8;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821329c8
	if (!cr6.eq) goto loc_821329C8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82132a2c
	goto loc_82132A2C;
loc_821329C8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_821329D8:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x821329d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821329D8;
	// lis r31,-32107
	r31.s64 = -2104164352;
	// li r11,48
	r11.s64 = 48;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r3,-23136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82132a1c
	if (!cr6.eq) goto loc_82132A1C;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821342b8
	ctx.lr = 0x82132A18;
	sub_821342B8(ctx, base);
	// stw r3,-23136(r31)
	PPC_STORE_U32(r31.u32 + -23136, ctx.r3.u32);
loc_82132A1C:
	// addi r11,r3,0
	r11.s64 = ctx.r3.s64 + 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
loc_82132A2C:
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

__attribute__((alias("__imp__sub_82132A44"))) PPC_WEAK_FUNC(sub_82132A44);
PPC_FUNC_IMPL(__imp__sub_82132A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82132A48"))) PPC_WEAK_FUNC(sub_82132A48);
PPC_FUNC_IMPL(__imp__sub_82132A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82132970
	ctx.lr = 0x82132A58;
	sub_82132970(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x82132a90
	if (!cr0.eq) goto loc_82132A90;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r11,2024(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2024);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82132a88
	if (cr6.eq) goto loc_82132A88;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82132A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82132A88:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827bcf84
	ctx.lr = 0x82132A90;
	__imp__HalReturnToFirmware(ctx, base);
loc_82132A90:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82132AA0"))) PPC_WEAK_FUNC(sub_82132AA0);
PPC_FUNC_IMPL(__imp__sub_82132AA0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r10,76
	r11.s64 = ctx.r10.s64 + 76;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82132c3c
	if (!cr6.eq) goto loc_82132C3C;
	// lwz r11,72(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82132b48
	if (cr6.eq) goto loc_82132B48;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x82132b48
	if (cr6.eq) goto loc_82132B48;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// bl 0x827bcf94
	ctx.lr = 0x82132B20;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82132b78
	if (cr0.lt) goto loc_82132B78;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x82132c08
	goto loc_82132C08;
loc_82132B48:
	// lis r11,16
	r11.s64 = 1048576;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcf94
	ctx.lr = 0x82132B70;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82132b80
	if (!cr0.lt) goto loc_82132B80;
loc_82132B78:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82132c48
	goto loc_82132C48;
loc_82132B80:
	// lis r11,1
	r11.s64 = 65536;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcf94
	ctx.lr = 0x82132BA4;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82132bc8
	if (!cr0.lt) goto loc_82132BC8;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcfd4
	ctx.lr = 0x82132BC4;
	__imp__NtFreeVirtualMemory(ctx, base);
	// b 0x82132b78
	goto loc_82132B78;
loc_82132BC8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r11,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, r11.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
loc_82132C08:
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r8,76
	ctx.r10.s64 = ctx.r8.s64 + 76;
	// b 0x82132c28
	goto loc_82132C28;
loc_82132C1C:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82132C28:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82132c1c
	if (cr6.lt) goto loc_82132C1C;
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,76
	r11.s64 = r11.s64 + 76;
loc_82132C3C:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_82132C48:
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

__attribute__((alias("__imp__sub_82132C60"))) PPC_WEAK_FUNC(sub_82132C60);
PPC_FUNC_IMPL(__imp__sub_82132C60) {
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
	ctx.lr = 0x82132C68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r28,r31,56
	r28.s64 = r31.s64 + 56;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82132d04
	if (cr6.eq) goto loc_82132D04;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82132C8C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bgt cr6,0x82132d4c
	if (cr6.gt) goto loc_82132D4C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r7,r29
	cr6.compare<uint32_t>(ctx.r7.u32, r29.u32, xer);
	// bne cr6,0x82132cf4
	if (!cr6.eq) goto loc_82132CF4;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,76(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// ble cr6,0x82132cf8
	if (!cr6.gt) goto loc_82132CF8;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// b 0x82132cf8
	goto loc_82132CF8;
loc_82132CF4:
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82132CF8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82132c8c
	if (!cr6.eq) goto loc_82132C8C;
loc_82132D04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82132aa0
	ctx.lr = 0x82132D0C;
	sub_82132AA0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82132d44
	if (cr0.eq) goto loc_82132D44;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// blt cr6,0x82132d44
	if (cr6.lt) goto loc_82132D44;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_82132D44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82132D4C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r9,r29,r30
	ctx.r9.u64 = r29.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82132d04
	if (!cr6.eq) goto loc_82132D04;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x82132d44
	if (!cr6.gt) goto loc_82132D44;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// b 0x82132d44
	goto loc_82132D44;
}

__attribute__((alias("__imp__sub_82132D80"))) PPC_WEAK_FUNC(sub_82132D80);
PPC_FUNC_IMPL(__imp__sub_82132D80) {
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
	ctx.lr = 0x82132D88;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r26,0
	r26.s64 = 0;
	// addi r25,r30,56
	r25.s64 = r30.s64 + 56;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r25
	r27.u64 = r25.u64;
	// lwz r31,56(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82132de8
	if (cr6.eq) goto loc_82132DE8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_82132DB4:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82132dd4
	if (cr6.lt) goto loc_82132DD4;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82132df4
	if (cr6.eq) goto loc_82132DF4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// beq cr6,0x82132df4
	if (cr6.eq) goto loc_82132DF4;
loc_82132DD4:
	// mr r29,r31
	r29.u64 = r31.u64;
	// mr r27,r31
	r27.u64 = r31.u64;
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82132db4
	if (!cr6.eq) goto loc_82132DB4;
loc_82132DE8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82132DEC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82132DF4:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,1412(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1412);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// beq cr6,0x82132e1c
	if (cr6.eq) goto loc_82132E1C;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82132E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82132e38
	goto loc_82132E38;
loc_82132E1C:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcf94
	ctx.lr = 0x82132E38;
	__imp__NtAllocateVirtualMemory(ctx, base);
loc_82132E38:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82132de8
	if (cr6.lt) goto loc_82132DE8;
	// lhz r11,0(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82132e64
	if (!cr6.eq) goto loc_82132E64;
	// stw r26,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r26.u32);
loc_82132E64:
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82132e94
	if (cr0.eq) goto loc_82132E94;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82132f00
	if (cr6.eq) goto loc_82132F00;
loc_82132E94:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82132ea4
	if (!cr6.eq) goto loc_82132EA4;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// b 0x82132eb0
	goto loc_82132EB0;
loc_82132EA4:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_82132EB0:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82132f00
	if (!cr0.eq) goto loc_82132F00;
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
loc_82132EC0:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82132ef4
	if (!cr6.lt) goto loc_82132EF4;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x82132ef4
	if (cr0.eq) goto loc_82132EF4;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82132ec0
	if (cr0.eq) goto loc_82132EC0;
	// b 0x82132f00
	goto loc_82132F00;
loc_82132EF4:
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bne cr6,0x82132de8
	if (!cr6.eq) goto loc_82132DE8;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82132F00:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// andi. r10,r10,239
	ctx.r10.u64 = ctx.r10.u64 & 239;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// subf. r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne 0x82132f90
	if (!cr0.eq) goto loc_82132F90;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82132f50
	if (!cr6.eq) goto loc_82132F50;
	// li r10,16
	ctx.r10.s64 = 16;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r3,64(r30)
	PPC_STORE_U32(r30.u32 + 64, ctx.r3.u32);
	// b 0x82132f5c
	goto loc_82132F5C;
loc_82132F50:
	// stb r26,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r26.u8);
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r10,64(r30)
	PPC_STORE_U32(r30.u32 + 64, ctx.r10.u32);
loc_82132F5C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,76(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r31,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r31.u32);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r10.u32);
	// b 0x82132f9c
	goto loc_82132F9C;
loc_82132F90:
	// li r10,16
	ctx.r10.s64 = 16;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r3,64(r30)
	PPC_STORE_U32(r30.u32 + 64, ctx.r3.u32);
loc_82132F9C:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lbz r9,5(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// rlwinm. r9,r9,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r10,r10,28,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFF;
	// sth r10,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r10.u16);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// sth r11,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, r11.u16);
	// bne 0x82132fd4
	if (!cr0.eq) goto loc_82132FD4;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// sth r10,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r10.u16);
loc_82132FD4:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82132dec
	if (!cr6.eq) goto loc_82132DEC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x82133000
	goto loc_82133000;
loc_82132FE8:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x82132ffc
	if (cr6.lt) goto loc_82132FFC;
	// stw r10,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r10.u32);
loc_82132FFC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82133000:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82132fe8
	if (!cr6.eq) goto loc_82132FE8;
	// b 0x82132dec
	goto loc_82132DEC;
}

__attribute__((alias("__imp__sub_8213300C"))) PPC_WEAK_FUNC(sub_8213300C);
PPC_FUNC_IMPL(__imp__sub_8213300C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82133010"))) PPC_WEAK_FUNC(sub_82133010);
PPC_FUNC_IMPL(__imp__sub_82133010) {
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
	ctx.lr = 0x82133018;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-274
	ctx.r10.s64 = -17956864;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// li r26,1
	r26.s64 = 1;
	// ori r25,r10,65262
	r25.u64 = ctx.r10.u64 | 65262;
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// subf r31,r11,r30
	r31.s64 = r30.s64 - r11.s64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x82133234
	if (cr6.eq) goto loc_82133234;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82133234
	if (!cr0.eq) goto loc_82133234;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r11,61440
	cr6.compare<uint32_t>(r11.u32, 61440, xer);
	// bgt cr6,0x82133234
	if (cr6.gt) goto loc_82133234;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82133128
	if (cr6.eq) goto loc_82133128;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rldimi r6,r8,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// cmpld cr6,r6,r9
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r9.u64, xer);
	// bne cr6,0x821330dc
	if (!cr6.eq) goto loc_821330DC;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// bne cr6,0x821330dc
	if (!cr6.eq) goto loc_821330DC;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821330dc
	if (!cr6.lt) goto loc_821330DC;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
loc_821330DC:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82133114
	if (cr0.eq) goto loc_82133114;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x82133108
	if (cr0.eq) goto loc_82133108;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x82133108
	if (!cr6.gt) goto loc_82133108;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_82133108:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x82133114;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_82133114:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r11.u32);
loc_82133128:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r31,8
	ctx.r9.s64 = r31.s64 + 8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldimi r6,r8,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// cmpld cr6,r6,r9
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r9.u64, xer);
	// bne cr6,0x82133190
	if (!cr6.eq) goto loc_82133190;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82133190
	if (!cr6.eq) goto loc_82133190;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x82133190
	if (!cr6.lt) goto loc_82133190;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
loc_82133190:
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821331c8
	if (cr0.eq) goto loc_821331C8;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x821331bc
	if (cr0.eq) goto loc_821331BC;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x821331bc
	if (!cr6.gt) goto loc_821331BC;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_821331BC:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x821331C8;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_821331C8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// beq 0x821331ec
	if (cr0.eq) goto loc_821331EC;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
loc_821331EC:
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r30,r31
	r30.u64 = r31.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// sth r10,0(r31)
	PPC_STORE_U16(r31.u32 + 0, ctx.r10.u16);
	// bne 0x82133234
	if (!cr0.eq) goto loc_82133234;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// sth r10,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r10.u16);
loc_82133234:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82133428
	if (!cr0.eq) goto loc_82133428;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r10,r30
	r31.u64 = ctx.r10.u64 + r30.u64;
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82133428
	if (!cr0.eq) goto loc_82133428;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r11,61440
	cr6.compare<uint32_t>(r11.u32, 61440, xer);
	// bgt cr6,0x82133428
	if (cr6.gt) goto loc_82133428;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82133320
	if (cr6.eq) goto loc_82133320;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rldimi r6,r8,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// cmpld cr6,r6,r9
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r9.u64, xer);
	// bne cr6,0x821332d8
	if (!cr6.eq) goto loc_821332D8;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// bne cr6,0x821332d8
	if (!cr6.eq) goto loc_821332D8;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821332d8
	if (!cr6.lt) goto loc_821332D8;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
loc_821332D8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82133310
	if (cr0.eq) goto loc_82133310;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x82133304
	if (cr0.eq) goto loc_82133304;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x82133304
	if (!cr6.gt) goto loc_82133304;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_82133304:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x82133310;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_82133310:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r11.u32);
loc_82133320:
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// beq 0x82133344
	if (cr0.eq) goto loc_82133344;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// stw r30,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r30.u32);
loc_82133344:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r31,8
	ctx.r9.s64 = r31.s64 + 8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldimi r6,r8,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// cmpld cr6,r6,r9
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r9.u64, xer);
	// bne cr6,0x821333ac
	if (!cr6.eq) goto loc_821333AC;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x821333ac
	if (!cr6.eq) goto loc_821333AC;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821333ac
	if (!cr6.lt) goto loc_821333AC;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
loc_821333AC:
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821333e4
	if (cr0.eq) goto loc_821333E4;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x821333d8
	if (cr0.eq) goto loc_821333D8;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x821333d8
	if (!cr6.gt) goto loc_821333D8;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_821333D8:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x821333E4;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_821333E4:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r11.u32);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// sth r10,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r10.u16);
	// bne 0x82133428
	if (!cr0.eq) goto loc_82133428;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// sth r10,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r10.u16);
loc_82133428:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82133434"))) PPC_WEAK_FUNC(sub_82133434);
PPC_FUNC_IMPL(__imp__sub_82133434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82133438"))) PPC_WEAK_FUNC(sub_82133438);
PPC_FUNC_IMPL(__imp__sub_82133438) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82133440;
	// lbz r31,4(r4)
	r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lhz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lbz r29,5(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r3
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// b 0x82133554
	goto loc_82133554;
loc_8213346C:
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// ble cr6,0x82133490
	if (!cr6.gt) goto loc_82133490;
	// li r6,-4096
	ctx.r6.s64 = -4096;
	// cmplwi cr6,r5,61441
	cr6.compare<uint32_t>(ctx.r5.u32, 61441, xer);
	// bne cr6,0x82133484
	if (!cr6.eq) goto loc_82133484;
	// li r6,-4112
	ctx.r6.s64 = -4112;
loc_82133484:
	// li r11,0
	r11.s64 = 0;
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// b 0x82133498
	goto loc_82133498;
loc_82133490:
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
	// stb r29,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r29.u8);
loc_82133498:
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// sth r7,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r7.u16);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r31,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, r31.u8);
	// sth r6,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, ctx.r6.u16);
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// bge cr6,0x821334fc
	if (!cr6.lt) goto loc_821334FC;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82133520
	if (!cr6.eq) goto loc_82133520;
	// rlwinm r9,r10,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r9,88
	ctx.r9.s64 = ctx.r9.s64 + 88;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r8,r7,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r7,r9,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stwx r8,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r8.u32);
	// b 0x82133520
	goto loc_82133520;
loc_821334FC:
	// lwz r11,384(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addi r9,r3,384
	ctx.r9.s64 = ctx.r3.s64 + 384;
	// b 0x82133518
	goto loc_82133518;
loc_82133508:
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82133520
	if (!cr6.gt) goto loc_82133520;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82133518:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82133508
	if (!cr6.eq) goto loc_82133508;
loc_82133520:
	// lwz r28,4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// stw r28,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r28.u32);
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge cr6,0x82133568
	if (!cr6.lt) goto loc_82133568;
loc_82133554:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8213346c
	if (!cr6.eq) goto loc_8213346C;
	// rlwinm. r11,r29,0,27,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82133568
	if (!cr0.eq) goto loc_82133568;
	// sth r7,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r7.u16);
loc_82133568:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8213356C"))) PPC_WEAK_FUNC(sub_8213356C);
PPC_FUNC_IMPL(__imp__sub_8213356C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82133570"))) PPC_WEAK_FUNC(sub_82133570);
PPC_FUNC_IMPL(__imp__sub_82133570) {
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
	ctx.lr = 0x82133578;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// ble cr6,0x821335a4
	if (!cr6.gt) goto loc_821335A4;
loc_8213359C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82133af8
	goto loc_82133AF8;
loc_821335A4:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// li r25,1
	r25.s64 = 1;
	// lbz r9,5(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 5);
	// rotlwi r10,r11,4
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 4);
	// rlwinm. r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// add r31,r10,r27
	r31.u64 = ctx.r10.u64 + r27.u64;
	// beq 0x8213365c
	if (cr0.eq) goto loc_8213365C;
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r10,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF0000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82132d80
	ctx.lr = 0x821335FC;
	sub_82132D80(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x8213359c
	if (cr0.eq) goto loc_8213359C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,28,4,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82133010
	ctx.lr = 0x82133620;
	sub_82133010(ctx, base);
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// lbz r28,5(r4)
	r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// bge cr6,0x82133734
	if (!cr6.lt) goto loc_82133734;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133438
	ctx.lr = 0x82133644;
	sub_82133438(ctx, base);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// b 0x82133af8
	goto loc_82133AF8;
loc_8213365C:
	// lbz r28,5(r31)
	r28.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// clrlwi. r10,r28,31
	ctx.r10.u64 = r28.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8213359c
	if (!cr0.eq) goto loc_8213359C;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x8213359c
	if (cr6.lt) goto loc_8213359C;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r31,8
	ctx.r9.s64 = r31.s64 + 8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x821336e4
	if (!cr6.eq) goto loc_821336E4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x821336e4
	if (!cr6.eq) goto loc_821336E4;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821336e4
	if (!cr6.lt) goto loc_821336E4;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r25,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r25.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
loc_821336E4:
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82133720
	if (cr0.eq) goto loc_82133720;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x82133710
	if (cr0.eq) goto loc_82133710;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x82133710
	if (!cr6.gt) goto loc_82133710;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_82133710:
	// lis r5,-274
	ctx.r5.s64 = -17956864;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// ori r5,r5,65262
	ctx.r5.u64 = ctx.r5.u64 | 65262;
	// bl 0x827bcfe4
	ctx.lr = 0x82133720;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_82133720:
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r10.u32);
loc_82133734:
	// lhz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// lbz r9,6(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 6);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// subf r24,r9,r10
	r24.s64 = ctx.r10.s64 - ctx.r9.s64;
	// bgt cr6,0x82133760
	if (cr6.gt) goto loc_82133760;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82133760:
	// rlwinm. r10,r26,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82133798
	if (cr0.eq) goto loc_82133798;
	// lhz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r9,r11,r27
	ctx.r9.u64 = r11.u64 + r27.u64;
	// add r11,r10,r27
	r11.u64 = ctx.r10.u64 + r27.u64;
	// addi r10,r9,-16
	ctx.r10.s64 = ctx.r9.s64 + -16;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// ld r10,-16(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + -16);
	// std r10,-16(r9)
	PPC_STORE_U64(ctx.r9.u32 + -16, ctx.r10.u64);
	// ld r11,-8(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + -8);
	// std r11,-8(r9)
	PPC_STORE_U64(ctx.r9.u32 + -8, r11.u64);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82133798:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821337f0
	if (!cr6.eq) goto loc_821337F0;
	// lbz r11,5(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 5);
	// rlwinm. r10,r28,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r29,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// subf r9,r23,r9
	ctx.r9.s64 = ctx.r9.s64 - r23.s64;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// stb r8,5(r27)
	PPC_STORE_U8(r27.u32 + 5, ctx.r8.u8);
	// stb r9,6(r27)
	PPC_STORE_U8(r27.u32 + 6, ctx.r9.u8);
	// sth r11,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r11.u16);
	// bne 0x821337d8
	if (!cr0.eq) goto loc_821337D8;
	// rlwinm r10,r11,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + r27.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// b 0x82133ac4
	goto loc_82133AC4;
loc_821337D8:
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r27,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r27.u32);
	// b 0x82133ac4
	goto loc_82133AC4;
loc_821337F0:
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r9,r29,16
	ctx.r9.u64 = r29.u32 & 0xFFFF;
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// subf r10,r23,r11
	ctx.r10.s64 = r11.s64 - r23.s64;
	// sth r9,0(r27)
	PPC_STORE_U16(r27.u32 + 0, ctx.r9.u16);
	// rlwinm. r8,r28,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stb r10,6(r27)
	PPC_STORE_U8(r27.u32 + 6, ctx.r10.u8);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// sth r9,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r9.u16);
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// beq 0x82133880
	if (cr0.eq) goto loc_82133880;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,24,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF8;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
	// stb r28,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r28.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stb r10,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r10.u8);
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// blt cr6,0x821338d4
	if (cr6.lt) goto loc_821338D4;
	// lwz r11,384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// addi r9,r30,384
	ctx.r9.s64 = r30.s64 + 384;
	// b 0x82133874
	goto loc_82133874;
loc_82133864:
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82133a8c
	if (!cr6.gt) goto loc_82133A8C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82133874:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82133864
	if (!cr6.eq) goto loc_82133864;
	// b 0x82133a8c
	goto loc_82133A8C;
loc_82133880:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// lbz r28,5(r29)
	r28.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// clrlwi. r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82133904
	if (cr0.eq) goto loc_82133904;
	// andi. r11,r10,239
	r11.u64 = ctx.r10.u64 & 239;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// bge cr6,0x821338dc
	if (!cr6.lt) goto loc_821338DC;
loc_821338D4:
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// b 0x82133a2c
	goto loc_82133A2C;
loc_821338DC:
	// lwz r11,384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// addi r9,r30,384
	ctx.r9.s64 = r30.s64 + 384;
	// b 0x821338f8
	goto loc_821338F8;
loc_821338E8:
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82133a8c
	if (!cr6.gt) goto loc_82133A8C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_821338F8:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x821338e8
	if (!cr6.eq) goto loc_821338E8;
	// b 0x82133a8c
	goto loc_82133A8C;
loc_82133904:
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r9,r29,8
	ctx.r9.s64 = r29.s64 + 8;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x8213396c
	if (!cr6.eq) goto loc_8213396C;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x8213396c
	if (!cr6.eq) goto loc_8213396C;
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x8213396c
	if (!cr6.lt) goto loc_8213396C;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r25,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r25.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
loc_8213396C:
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821339a8
	if (cr0.eq) goto loc_821339A8;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// beq 0x82133998
	if (cr0.eq) goto loc_82133998;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x82133998
	if (!cr6.gt) goto loc_82133998;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
loc_82133998:
	// lis r5,-274
	ctx.r5.s64 = -17956864;
	// addi r3,r29,24
	ctx.r3.s64 = r29.s64 + 24;
	// ori r5,r5,65262
	ctx.r5.u64 = ctx.r5.u64 | 65262;
	// bl 0x827bcfe4
	ctx.lr = 0x821339A8;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_821339A8:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stb r28,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r28.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x82133ab8
	if (cr6.gt) goto loc_82133AB8;
	// rlwinm. r10,r28,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r5,0(r31)
	PPC_STORE_U16(r31.u32 + 0, ctx.r5.u16);
	// bne 0x821339f8
	if (!cr0.eq) goto loc_821339F8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// b 0x82133a0c
	goto loc_82133A0C;
loc_821339F8:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
loc_82133A0C:
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// bge cr6,0x82133a68
	if (!cr6.lt) goto loc_82133A68;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
loc_82133A2C:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82133a8c
	if (!cr6.eq) goto loc_82133A8C;
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r25,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
	// b 0x82133a8c
	goto loc_82133A8C;
loc_82133A68:
	// lwz r11,384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// b 0x82133a84
	goto loc_82133A84;
loc_82133A74:
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82133a8c
	if (!cr6.gt) goto loc_82133A8C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82133A84:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82133a74
	if (!cr6.eq) goto loc_82133A74;
loc_82133A8C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// b 0x82133ac4
	goto loc_82133AC4;
loc_82133AB8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133438
	ctx.lr = 0x82133AC4;
	sub_82133438(ctx, base);
loc_82133AC4:
	// rlwinm. r11,r22,0,28,28
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82133ae8
	if (cr0.eq) goto loc_82133AE8;
	// cmplw cr6,r23,r24
	cr6.compare<uint32_t>(r23.u32, r24.u32, xer);
	// ble cr6,0x82133ae8
	if (!cr6.gt) goto loc_82133AE8;
	// add r11,r24,r27
	r11.u64 = r24.u64 + r27.u64;
	// subf r5,r24,r23
	ctx.r5.s64 = r23.s64 - r24.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x823d9890
	ctx.lr = 0x82133AE8;
	sub_823D9890(ctx, base);
loc_82133AE8:
	// lbz r11,5(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 5);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r11,r22,28,24,26
	r11.u64 = (__builtin_rotateleft32(r22.u32, 28) & 0xE0) | (r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// stb r11,5(r27)
	PPC_STORE_U8(r27.u32 + 5, r11.u8);
loc_82133AF8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82133B00"))) PPC_WEAK_FUNC(sub_82133B00);
PPC_FUNC_IMPL(__imp__sub_82133B00) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82133b50
	if (cr0.eq) goto loc_82133B50;
	// bl 0x827bcfc4
	ctx.lr = 0x82133B2C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x82133b50
	if (cr6.eq) goto loc_82133B50;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r6,5140
	ctx.r6.s64 = 5140;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x82133B50;
	__imp__KeBugCheckEx(ctx, base);
loc_82133B50:
	// lbz r11,-11(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -11);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82133b64
	if (!cr0.eq) goto loc_82133B64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82133b90
	goto loc_82133B90;
loc_82133B64:
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82133b80
	if (cr0.eq) goto loc_82133B80;
	// lhz r11,-16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -16);
	// lwz r10,-24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -24);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r3,r11,-48
	ctx.r3.s64 = r11.s64 + -48;
	// b 0x82133b90
	goto loc_82133B90;
loc_82133B80:
	// lhz r11,-16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -16);
	// lbz r10,-10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + -10);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
loc_82133B90:
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

__attribute__((alias("__imp__sub_82133BA8"))) PPC_WEAK_FUNC(sub_82133BA8);
PPC_FUNC_IMPL(__imp__sub_82133BA8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82133BB0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// stw r8,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r8.u32);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// subf r10,r29,r27
	ctx.r10.s64 = r27.s64 - r29.s64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r11,r31,87
	r11.s64 = r31.s64 + 87;
	// srawi r10,r10,16
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 16;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// rlwinm r30,r11,0,0,27
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// addze r26,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r26.s64 = temp.s64;
	// bne cr6,0x82133bf4
	if (!cr6.eq) goto loc_82133BF4;
	// lhz r22,0(r28)
	r22.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// b 0x82133bf8
	goto loc_82133BF8;
loc_82133BF4:
	// li r22,0
	r22.s64 = 0;
loc_82133BF8:
	// subf r10,r31,r30
	ctx.r10.s64 = r30.s64 - r31.s64;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// srawi r10,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// clrlwi r24,r10,16
	r24.u64 = ctx.r10.u32 & 0xFFFF;
	// blt cr6,0x82133c60
	if (cr6.lt) goto loc_82133C60;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x82133c20
	if (cr6.lt) goto loc_82133C20;
loc_82133C18:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82133d08
	goto loc_82133D08;
loc_82133C20:
	// subf r11,r8,r30
	r11.s64 = r30.s64 - ctx.r8.s64;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,236
	ctx.r3.s64 = ctx.r1.s64 + 236;
	// bl 0x827bcf94
	ctx.lr = 0x82133C48;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82133c18
	if (cr0.lt) goto loc_82133C18;
	// lwz r10,236(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r8.u32);
loc_82133C60:
	// subf r11,r8,r27
	r11.s64 = r27.s64 - ctx.r8.s64;
	// sth r22,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r22.u16);
	// rlwinm r10,r26,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 16) & 0xFFFF0000;
	// sth r24,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r24.u16);
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// stb r25,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r25.u8);
	// lis r9,-18
	ctx.r9.s64 = -1179648;
	// stw r23,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r23.u32);
	// addze. r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// ori r9,r9,65518
	ctx.r9.u64 = ctx.r9.u64 | 65518;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// stb r7,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r7.u8);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// beq 0x82133cc8
	if (cr0.eq) goto loc_82133CC8;
	// rlwinm r5,r11,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82132c60
	ctx.lr = 0x82133CC4;
	sub_82132C60(ctx, base);
	// lwz r8,236(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
loc_82133CC8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// subf r9,r30,r8
	ctx.r9.s64 = ctx.r8.s64 - r30.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r5,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stwx r31,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r31.u32);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stb r25,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r25.u8);
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// bl 0x82133438
	ctx.lr = 0x82133D04;
	sub_82133438(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_82133D08:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82133D10"))) PPC_WEAK_FUNC(sub_82133D10);
PPC_FUNC_IMPL(__imp__sub_82133D10) {
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
	ctx.lr = 0x82133D18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r11,r28,1
	r11.s64 = r28.s64 + 65536;
	// li r27,64
	r27.s64 = 64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r30,0
	r30.s64 = 0;
	// rlwinm r29,r11,16,16,31
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r29,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
loc_82133D44:
	// addi r10,r30,24
	ctx.r10.s64 = r30.s64 + 24;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// beq cr6,0x82133dc8
	if (cr6.eq) goto loc_82133DC8;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bgt cr6,0x82133dd8
	if (cr6.gt) goto loc_82133DD8;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bgt cr6,0x82133dd8
	if (cr6.gt) goto loc_82133DD8;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82132d80
	ctx.lr = 0x82133D88;
	sub_82132D80(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x82133dd8
	if (cr0.eq) goto loc_82133DD8;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// rlwinm r11,r11,28,4,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bl 0x82133010
	ctx.lr = 0x82133DAC;
	sub_82133010(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82133438
	ctx.lr = 0x82133DC0;
	sub_82133438(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x82133f44
	goto loc_82133F44;
loc_82133DC8:
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r10,64
	cr6.compare<uint32_t>(ctx.r10.u32, 64, xer);
	// bne cr6,0x82133dd8
	if (!cr6.eq) goto loc_82133DD8;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_82133DD8:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,64
	cr6.compare<uint32_t>(r11.u32, 64, xer);
	// blt cr6,0x82133d44
	if (cr6.lt) goto loc_82133D44;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,64
	cr6.compare<uint32_t>(r11.u32, 64, xer);
	// beq cr6,0x82133f40
	if (cr6.eq) goto loc_82133F40;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82133f40
	if (cr0.eq) goto loc_82133F40;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addis r30,r28,1
	r30.s64 = r28.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bgt cr6,0x82133e24
	if (cr6.gt) goto loc_82133E24;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82133E24:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82133E40;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82133e94
	if (!cr0.lt) goto loc_82133E94;
loc_82133E48:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82133e8c
	if (cr6.eq) goto loc_82133E8C;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x82133e68
	if (!cr6.lt) goto loc_82133E68;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
loc_82133E68:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82133E84;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82133e48
	if (cr0.lt) goto loc_82133E48;
loc_82133E8C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82133f40
	if (cr6.lt) goto loc_82133F40;
loc_82133E94:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bgt cr6,0x82133eb8
	if (cr6.gt) goto loc_82133EB8;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
loc_82133EB8:
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82133ED4;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82133f28
	if (cr0.lt) goto loc_82133F28;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r8,r11,r7
	ctx.r8.u64 = r11.u64 + ctx.r7.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x82133ba8
	ctx.lr = 0x82133F04;
	sub_82133BA8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82133f14
	if (!cr0.eq) goto loc_82133F14;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,23
	r30.u64 = r30.u64 | 23;
loc_82133F14:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82133f28
	if (cr6.lt) goto loc_82133F28;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// b 0x82133f44
	goto loc_82133F44;
loc_82133F28:
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bcfd4
	ctx.lr = 0x82133F40;
	__imp__NtFreeVirtualMemory(ctx, base);
loc_82133F40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82133F44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82133F4C"))) PPC_WEAK_FUNC(sub_82133F4C);
PPC_FUNC_IMPL(__imp__sub_82133F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82133F50"))) PPC_WEAK_FUNC(sub_82133F50);
PPC_FUNC_IMPL(__imp__sub_82133F50) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82133F58;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r11,1412(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1412);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134298
	if (!cr6.eq) goto loc_82134298;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r19,0
	r19.s64 = 0;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r9,r10,0,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF0000;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r31,r9
	ctx.r10.s64 = ctx.r9.s64 - r31.s64;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// srawi r10,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	// mr r23,r19
	r23.u64 = r19.u64;
	// clrlwi r26,r10,16
	r26.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r25,r11,r28
	r25.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// cmplwi cr6,r26,1
	cr6.compare<uint32_t>(r26.u32, 1, xer);
	// bne cr6,0x82133fc4
	if (!cr6.eq) goto loc_82133FC4;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// li r26,4097
	r26.s64 = 4097;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// b 0x82133fe0
	goto loc_82133FE0;
loc_82133FC4:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82133fe0
	if (cr0.eq) goto loc_82133FE0;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bne cr6,0x82133fe0
	if (!cr6.eq) goto loc_82133FE0;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r23,r11,r31
	r23.s64 = r31.s64 - r11.s64;
loc_82133FE0:
	// rlwinm r11,r24,4,0,27
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r20,r19
	r20.u64 = r19.u64;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// rlwinm r11,r10,0,0,15
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF0000;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - r11.s64;
	// srawi r8,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 4;
	// clrlwi r27,r8,16
	r27.u64 = ctx.r8.u32 & 0xFFFF;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// bne cr6,0x82134014
	if (!cr6.eq) goto loc_82134014;
	// li r27,4097
	r27.s64 = 4097;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// b 0x8213402c
	goto loc_8213402C;
loc_82134014:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8213402c
	if (!cr6.eq) goto loc_8213402C;
	// lbz r8,5(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm. r8,r8,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8213402c
	if (!cr0.eq) goto loc_8213402C;
	// mr r20,r10
	r20.u64 = ctx.r10.u64;
loc_8213402C:
	// rlwinm r22,r27,4,12,27
	r22.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFF0;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// clrlwi r21,r27,16
	r21.u64 = r27.u32 & 0xFFFF;
	// subf r29,r22,r10
	r29.s64 = ctx.r10.s64 - r22.s64;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// bgt cr6,0x82134048
	if (cr6.gt) goto loc_82134048;
	// mr r11,r19
	r11.u64 = r19.u64;
loc_82134048:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134298
	if (cr6.eq) goto loc_82134298;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82132aa0
	ctx.lr = 0x8213405C;
	sub_82132AA0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82134298
	if (cr0.eq) goto loc_82134298;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bcfd4
	ctx.lr = 0x82134078;
	__imp__NtFreeVirtualMemory(ctx, base);
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// stw r30,76(r11)
	PPC_STORE_U32(r11.u32 + 76, r30.u32);
	// stw r19,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r19.u32);
	// stw r19,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r19.u32);
	// blt 0x82134298
	if (cr0.lt) goto loc_82134298;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82132c60
	ctx.lr = 0x821340AC;
	sub_82132C60(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,48(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// clrlwi. r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r9,r9,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,48(r25)
	PPC_STORE_U32(r25.u32 + 48, ctx.r10.u32);
	// beq 0x82134180
	if (cr0.eq) goto loc_82134180;
	// li r10,16
	ctx.r10.s64 = 16;
	// sth r26,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r26.u16);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// stb r10,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r10.u8);
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r10,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r10.u32);
	// stw r31,64(r25)
	PPC_STORE_U32(r25.u32 + 64, r31.u32);
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// rlwinm r10,r10,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r10,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r10.u8);
	// bge cr6,0x8213413c
	if (!cr6.lt) goto loc_8213413C;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134164
	if (!cr6.eq) goto loc_82134164;
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r28
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
	// b 0x82134164
	goto loc_82134164;
loc_8213413C:
	// lwz r10,384(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// addi r9,r28,384
	ctx.r9.s64 = r28.s64 + 384;
	// b 0x82134158
	goto loc_82134158;
loc_82134148:
	// lhz r7,-8(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + -8);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// ble cr6,0x82134160
	if (!cr6.gt) goto loc_82134160;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_82134158:
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82134148
	if (!cr6.eq) goto loc_82134148;
loc_82134160:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82134164:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// b 0x821341c4
	goto loc_821341C4;
loc_82134180:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8213419c
	if (cr6.eq) goto loc_8213419C;
	// lbz r11,5(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 5);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,5(r23)
	PPC_STORE_U8(r23.u32 + 5, r11.u8);
	// stw r23,64(r25)
	PPC_STORE_U32(r25.u32 + 64, r23.u32);
	// b 0x821341c4
	goto loc_821341C4;
loc_8213419C:
	// lwz r11,64(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821341c4
	if (cr6.lt) goto loc_821341C4;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821341c4
	if (!cr6.lt) goto loc_821341C4;
	// lwz r11,40(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// stw r11,64(r25)
	PPC_STORE_U32(r25.u32 + 64, r11.u32);
loc_821341C4:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82134288
	if (cr6.eq) goto loc_82134288;
	// add r11,r22,r29
	r11.u64 = r22.u64 + r29.u64;
	// sth r19,2(r29)
	PPC_STORE_U16(r29.u32 + 2, r19.u16);
	// lbz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 4);
	// cmplwi cr6,r21,128
	cr6.compare<uint32_t>(r21.u32, 128, xer);
	// stb r19,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r19.u8);
	// stb r10,4(r29)
	PPC_STORE_U8(r29.u32 + 4, ctx.r10.u8);
	// sth r27,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r27.u16);
	// sth r27,2(r11)
	PPC_STORE_U16(r11.u32 + 2, r27.u16);
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x8213423c
	if (!cr6.lt) goto loc_8213423C;
	// addi r11,r21,48
	r11.s64 = r21.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134260
	if (!cr6.eq) goto loc_82134260;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
	// b 0x82134260
	goto loc_82134260;
loc_8213423C:
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// b 0x82134258
	goto loc_82134258;
loc_82134248:
	// lhz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// cmplw cr6,r21,r9
	cr6.compare<uint32_t>(r21.u32, ctx.r9.u32, xer);
	// ble cr6,0x82134260
	if (!cr6.gt) goto loc_82134260;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82134258:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134248
	if (!cr6.eq) goto loc_82134248;
loc_82134260:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r29,8
	ctx.r10.s64 = r29.s64 + 8;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r21,r11
	r11.u64 = r21.u64 + r11.u64;
	// stw r11,48(r28)
	PPC_STORE_U32(r28.u32 + 48, r11.u32);
	// b 0x821342a8
	goto loc_821342A8;
loc_82134288:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x821342a8
	if (cr6.eq) goto loc_821342A8;
	// sth r19,2(r20)
	PPC_STORE_U16(r20.u32 + 2, r19.u16);
	// b 0x821342a8
	goto loc_821342A8;
loc_82134298:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82133438
	ctx.lr = 0x821342A8;
	sub_82133438(ctx, base);
loc_821342A8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_821342B0"))) PPC_WEAK_FUNC(sub_821342B0);
PPC_FUNC_IMPL(__imp__sub_821342B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r24{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9312(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9312);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x821342C0;
	// addi r31,r1,-272
	r31.s64 = ctx.r1.s64 + -272;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// stw r24,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r24.u32);
	// li r22,0
	r22.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r22,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r22.u32);
	// stw r29,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r29.u32);
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// stw r5,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r5.u32);
	// mr r30,r22
	r30.u64 = r22.u64;
	// stw r6,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r6.u32);
	// stw r21,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r21.u32);
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r11,6
	r11.s64 = 6;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82134304:
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82134304
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82134304;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213437c
	if (cr6.eq) {
		sub_8213437C(ctx, base);
		return;
	}
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x82134340
	if (!cr6.eq) goto loc_82134340;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x823db5b0
	ctx.lr = 0x8213433C;
	sub_823DB5B0(ctx, base);
	// lwz r5,308(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 308);
loc_82134340:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134368
	sub_82134368(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821342B8"))) PPC_WEAK_FUNC(sub_821342B8);
PPC_FUNC_IMPL(__imp__sub_821342B8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x821342C0;
	// addi r31,r1,-272
	r31.s64 = ctx.r1.s64 + -272;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// stw r24,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r24.u32);
	// li r22,0
	r22.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r22,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r22.u32);
	// stw r29,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r29.u32);
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// stw r5,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r5.u32);
	// mr r30,r22
	r30.u64 = r22.u64;
	// stw r6,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r6.u32);
	// stw r21,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r21.u32);
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r11,6
	r11.s64 = 6;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82134304:
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82134304
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82134304;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213437c
	if (cr6.eq) goto loc_8213437C;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x82134340
	if (!cr6.eq) goto loc_82134340;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x823db5b0
	ctx.lr = 0x8213433C;
	sub_823DB5B0(ctx, base);
	// lwz r5,308(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 308);
loc_82134340:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134368
	goto loc_82134368;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r21,324(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// li r22,0
	r22.s64 = 0;
	// lwz r5,308(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// lwz r29,300(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r24,292(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 292);
loc_82134368:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82134378
	if (!cr6.lt) goto loc_82134378;
loc_82134370:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82134844
	goto loc_82134844;
loc_82134378:
	// lwz r6,316(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 316);
loc_8213437C:
	// lis r23,-32107
	r23.s64 = -2104164352;
	// lwz r11,-23144(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -23144);
	// rlwinm. r11,r11,0,10,10
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134390
	if (cr0.eq) goto loc_82134390;
	// ori r24,r24,128
	r24.u64 = r24.u64 | 128;
loc_82134390:
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343a8
	if (!cr6.eq) goto loc_821343A8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5560(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5560);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
loc_821343A8:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343c0
	if (!cr6.eq) goto loc_821343C0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5564(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5564);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_821343C0:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343d8
	if (!cr6.eq) goto loc_821343D8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5572);
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
loc_821343D8:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343f0
	if (!cr6.eq) goto loc_821343F0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5568);
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
loc_821343F0:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134408
	if (!cr6.eq) goto loc_82134408;
	// lis r11,32764
	r11.s64 = 2147221504;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82134408:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134420
	if (cr6.eq) goto loc_82134420;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82134428
	if (!cr6.gt) goto loc_82134428;
loc_82134420:
	// lis r11,15
	r11.s64 = 983040;
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
loc_82134428:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lis r30,1
	r30.s64 = 65536;
	// bne cr6,0x82134480
	if (!cr6.eq) goto loc_82134480;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
	// bne cr6,0x82134450
	if (!cr6.eq) goto loc_82134450;
	// lis r11,64
	r11.s64 = 4194304;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r27,r10,65535
	r27.u64 = ctx.r10.u64 | 65535;
	// b 0x82134460
	goto loc_82134460;
loc_82134450:
	// lis r11,0
	r11.s64 = 0;
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
loc_82134458:
	// add r11,r5,r27
	r11.u64 = ctx.r5.u64 + r27.u64;
	// rlwinm r11,r11,0,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF0000;
loc_82134460:
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// clrlwi. r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r25,1424
	r25.s64 = 1424;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne 0x821344b8
	if (!cr0.eq) goto loc_821344B8;
	// beq cr6,0x821344ac
	if (cr6.eq) goto loc_821344AC;
	// oris r24,r24,32768
	r24.u64 = r24.u64 | 2147483648;
	// b 0x821344bc
	goto loc_821344BC;
loc_82134480:
	// lis r11,0
	r11.s64 = 0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
	// add r11,r6,r27
	r11.u64 = ctx.r6.u64 + r27.u64;
	// rlwinm r11,r11,0,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r11.u32);
	// bne cr6,0x82134458
	if (!cr6.eq) goto loc_82134458;
	// addis r11,r11,16
	r11.s64 = r11.s64 + 1048576;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r11,r11,0,0,11
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFF00000;
	// b 0x82134460
	goto loc_82134460;
loc_821344AC:
	// li r25,1452
	r25.s64 = 1452;
	// li r21,-1
	r21.s64 = -1;
	// b 0x821344bc
	goto loc_821344BC;
loc_821344B8:
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
loc_821344BC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// beq cr6,0x821345c4
	if (cr6.eq) goto loc_821345C4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134518
	if (cr6.eq) goto loc_82134518;
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bgt cr6,0x82134370
	if (cr6.gt) goto loc_82134370;
	// rlwinm. r9,r24,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82134370
	if (!cr0.eq) goto loc_82134370;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r28,r10,r29
	r28.u64 = ctx.r10.u64 + r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x82134514;
	sub_823D9890(ctx, base);
	// b 0x821345b4
	goto loc_821345B4;
loc_82134518:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd004
	ctx.lr = 0x82134528;
	__imp__NtQueryVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82134370
	if (cr0.lt) goto loc_82134370;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// bne cr6,0x821345ac
	if (!cr6.eq) goto loc_821345AC;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82134560;
	sub_823D9890(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bd004
	ctx.lr = 0x82134580;
	__imp__NtQueryVirtualMemory(ctx, base);
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// blt 0x821345b4
	if (cr0.lt) goto loc_821345B4;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r10,8192
	cr6.compare<uint32_t>(ctx.r10.u32, 8192, xer);
	// bne cr6,0x821345b4
	if (!cr6.eq) goto loc_821345B4;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// b 0x821345b4
	goto loc_821345B4;
loc_821345AC:
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
loc_821345B4:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r26,1
	r26.s64 = 1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// b 0x82134610
	goto loc_82134610;
loc_821345C4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r31,308
	ctx.r4.s64 = r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x827bcf94
	ctx.lr = 0x821345E8;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82134370
	if (cr0.lt) goto loc_82134370;
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134604
	if (!cr6.eq) goto loc_82134604;
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
loc_82134604:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
loc_82134610:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bne cr6,0x82134670
	if (!cr6.eq) goto loc_82134670;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r31,316
	ctx.r4.s64 = r31.s64 + 316;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82134638;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82134664
	if (!cr0.lt) goto loc_82134664;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,308
	ctx.r4.s64 = r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x827bcfd4
	ctx.lr = 0x82134660;
	__imp__NtFreeVirtualMemory(ctx, base);
	// b 0x82134370
	goto loc_82134370;
loc_82134664:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r28,r28,r11
	r28.u64 = r28.u64 + r11.u64;
loc_82134670:
	// addi r11,r10,1431
	r11.s64 = ctx.r10.s64 + 1431;
	// li r8,8
	ctx.r8.s64 = 8;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r9,r25,128
	ctx.r9.s64 = r25.s64 + 128;
	// addi r10,r10,76
	ctx.r10.s64 = ctx.r10.s64 + 76;
loc_82134684:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82134684
	if (!cr0.eq) goto loc_82134684;
	// stw r22,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r22.u32);
	// mr r29,r11
	r29.u64 = r11.u64;
	// lwz r10,-23144(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -23144);
	// rlwinm. r10,r10,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821346cc
	if (cr0.eq) goto loc_821346CC;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// addi r9,r9,1548
	ctx.r9.s64 = ctx.r9.s64 + 1548;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r11,380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 380, r11.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 380);
	// addi r29,r11,1548
	r29.s64 = r11.s64 + 1548;
loc_821346CC:
	// addi r11,r9,15
	r11.s64 = ctx.r9.s64 + 15;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r9,-4353
	ctx.r9.s64 = -285278208;
	// rlwinm r30,r11,0,0,27
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r8,r30,28,16,31
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFF;
	// ori r9,r9,61183
	ctx.r9.u64 = ctx.r9.u64 | 61183;
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lis r12,24577
	r12.s64 = 1610678272;
	// ori r12,r12,125
	r12.u64 = r12.u64 | 125;
	// and r10,r24,r12
	ctx.r10.u64 = r24.u64 & r12.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stb r11,5(r8)
	PPC_STORE_U8(ctx.r8.u32 + 5, r11.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// sth r27,368(r11)
	PPC_STORE_U16(r11.u32 + 368, r27.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// sth r10,58(r11)
	PPC_STORE_U16(r11.u32 + 58, ctx.r10.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r22,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r22.u32);
	// bl 0x827bcfc4
	ctx.lr = 0x82134738;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r10,128
	ctx.r10.s64 = 128;
	// stb r3,379(r11)
	PPC_STORE_U8(r11.u32 + 379, ctx.r3.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,384
	r11.s64 = r11.s64 + 384;
loc_8213474C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8213474c
	if (!cr0.eq) goto loc_8213474C;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r21,-1
	cr6.compare<int32_t>(r21.s32, -1, xer);
	// addi r11,r10,88
	r11.s64 = ctx.r10.s64 + 88;
	// stw r11,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, r11.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// bne cr6,0x82134784
	if (!cr6.eq) goto loc_82134784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r21,r29
	r21.u64 = r29.u64;
	// bl 0x827bcff4
	ctx.lr = 0x82134784;
	__imp__RtlInitializeCriticalSection(ctx, base);
loc_82134784:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r21,1408(r11)
	PPC_STORE_U32(r11.u32 + 1408, r21.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
	// add r4,r30,r3
	ctx.r4.u64 = r30.u64 + ctx.r3.u64;
	// bl 0x82133ba8
	ctx.lr = 0x821347B0;
	sub_82133BA8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82134370
	if (cr0.eq) goto loc_82134370;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm. r10,r24,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x10000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r22,56(r11)
	PPC_STORE_U16(r11.u32 + 56, r22.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// stw r10,1412(r11)
	PPC_STORE_U32(r11.u32 + 1412, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r10,31
	ctx.r10.s64 = 31;
	// li r9,-16
	ctx.r9.s64 = -16;
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r9.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_82134844:
	// addi r1,r31,272
	ctx.r1.s64 = r31.s64 + 272;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82134350"))) PPC_WEAK_FUNC(sub_82134350);
PPC_FUNC_IMPL(__imp__sub_82134350) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r21,324(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// li r22,0
	r22.s64 = 0;
	// lwz r5,308(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// lwz r29,300(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r24,292(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82134378
	if (!cr6.lt) goto loc_82134378;
loc_82134370:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82134844
	goto loc_82134844;
loc_82134378:
	// lwz r6,316(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lis r23,-32107
	r23.s64 = -2104164352;
	// lwz r11,-23144(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -23144);
	// rlwinm. r11,r11,0,10,10
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134390
	if (cr0.eq) goto loc_82134390;
	// ori r24,r24,128
	r24.u64 = r24.u64 | 128;
loc_82134390:
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343a8
	if (!cr6.eq) goto loc_821343A8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5560(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5560);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
loc_821343A8:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343c0
	if (!cr6.eq) goto loc_821343C0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5564(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5564);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_821343C0:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343d8
	if (!cr6.eq) goto loc_821343D8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5572);
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
loc_821343D8:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821343f0
	if (!cr6.eq) goto loc_821343F0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,5568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5568);
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
loc_821343F0:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134408
	if (!cr6.eq) goto loc_82134408;
	// lis r11,32764
	r11.s64 = 2147221504;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82134408:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134420
	if (cr6.eq) goto loc_82134420;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82134428
	if (!cr6.gt) goto loc_82134428;
loc_82134420:
	// lis r11,15
	r11.s64 = 983040;
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
loc_82134428:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lis r30,1
	r30.s64 = 65536;
	// bne cr6,0x82134480
	if (!cr6.eq) goto loc_82134480;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
	// bne cr6,0x82134450
	if (!cr6.eq) goto loc_82134450;
	// lis r11,64
	r11.s64 = 4194304;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r27,r10,65535
	r27.u64 = ctx.r10.u64 | 65535;
	// b 0x82134460
	goto loc_82134460;
loc_82134450:
	// lis r11,0
	r11.s64 = 0;
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
loc_82134458:
	// add r11,r5,r27
	r11.u64 = ctx.r5.u64 + r27.u64;
	// rlwinm r11,r11,0,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF0000;
loc_82134460:
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// clrlwi. r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r25,1424
	r25.s64 = 1424;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne 0x821344b8
	if (!cr0.eq) goto loc_821344B8;
	// beq cr6,0x821344ac
	if (cr6.eq) goto loc_821344AC;
	// oris r24,r24,32768
	r24.u64 = r24.u64 | 2147483648;
	// b 0x821344bc
	goto loc_821344BC;
loc_82134480:
	// lis r11,0
	r11.s64 = 0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
	// add r11,r6,r27
	r11.u64 = ctx.r6.u64 + r27.u64;
	// rlwinm r11,r11,0,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r11.u32);
	// bne cr6,0x82134458
	if (!cr6.eq) goto loc_82134458;
	// addis r11,r11,16
	r11.s64 = r11.s64 + 1048576;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r11,r11,0,0,11
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFF00000;
	// b 0x82134460
	goto loc_82134460;
loc_821344AC:
	// li r25,1452
	r25.s64 = 1452;
	// li r21,-1
	r21.s64 = -1;
	// b 0x821344bc
	goto loc_821344BC;
loc_821344B8:
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
loc_821344BC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// beq cr6,0x821345c4
	if (cr6.eq) goto loc_821345C4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134518
	if (cr6.eq) goto loc_82134518;
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bgt cr6,0x82134370
	if (cr6.gt) goto loc_82134370;
	// rlwinm. r9,r24,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82134370
	if (!cr0.eq) goto loc_82134370;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r28,r10,r29
	r28.u64 = ctx.r10.u64 + r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x82134514;
	sub_823D9890(ctx, base);
	// b 0x821345b4
	goto loc_821345B4;
loc_82134518:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd004
	ctx.lr = 0x82134528;
	__imp__NtQueryVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82134370
	if (cr0.lt) goto loc_82134370;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82134370
	if (cr6.eq) goto loc_82134370;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// bne cr6,0x821345ac
	if (!cr6.eq) goto loc_821345AC;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82134560;
	sub_823D9890(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bd004
	ctx.lr = 0x82134580;
	__imp__NtQueryVirtualMemory(ctx, base);
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// blt 0x821345b4
	if (cr0.lt) goto loc_821345B4;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r10,8192
	cr6.compare<uint32_t>(ctx.r10.u32, 8192, xer);
	// bne cr6,0x821345b4
	if (!cr6.eq) goto loc_821345B4;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// b 0x821345b4
	goto loc_821345B4;
loc_821345AC:
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
loc_821345B4:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r26,1
	r26.s64 = 1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// b 0x82134610
	goto loc_82134610;
loc_821345C4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// addi r4,r31,308
	ctx.r4.s64 = r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x827bcf94
	ctx.lr = 0x821345E8;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82134370
	if (cr0.lt) goto loc_82134370;
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82134604
	if (!cr6.eq) goto loc_82134604;
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
loc_82134604:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
loc_82134610:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bne cr6,0x82134670
	if (!cr6.eq) goto loc_82134670;
	// lis r5,24576
	ctx.r5.s64 = 1610612736;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r31,316
	ctx.r4.s64 = r31.s64 + 316;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82134638;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82134664
	if (!cr0.lt) goto loc_82134664;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82134370
	if (!cr6.eq) goto loc_82134370;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,308
	ctx.r4.s64 = r31.s64 + 308;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x827bcfd4
	ctx.lr = 0x82134660;
	__imp__NtFreeVirtualMemory(ctx, base);
	// b 0x82134370
	goto loc_82134370;
loc_82134664:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r28,r28,r11
	r28.u64 = r28.u64 + r11.u64;
loc_82134670:
	// addi r11,r10,1431
	r11.s64 = ctx.r10.s64 + 1431;
	// li r8,8
	ctx.r8.s64 = 8;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r9,r25,128
	ctx.r9.s64 = r25.s64 + 128;
	// addi r10,r10,76
	ctx.r10.s64 = ctx.r10.s64 + 76;
loc_82134684:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82134684
	if (!cr0.eq) goto loc_82134684;
	// stw r22,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r22.u32);
	// mr r29,r11
	r29.u64 = r11.u64;
	// lwz r10,-23144(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -23144);
	// rlwinm. r10,r10,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821346cc
	if (cr0.eq) goto loc_821346CC;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// addi r9,r9,1548
	ctx.r9.s64 = ctx.r9.s64 + 1548;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stw r11,380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 380, r11.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 380);
	// addi r29,r11,1548
	r29.s64 = r11.s64 + 1548;
loc_821346CC:
	// addi r11,r9,15
	r11.s64 = ctx.r9.s64 + 15;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r9,-4353
	ctx.r9.s64 = -285278208;
	// rlwinm r30,r11,0,0,27
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r8,r30,28,16,31
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFF;
	// ori r9,r9,61183
	ctx.r9.u64 = ctx.r9.u64 | 61183;
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lis r12,24577
	r12.s64 = 1610678272;
	// ori r12,r12,125
	r12.u64 = r12.u64 | 125;
	// and r10,r24,r12
	ctx.r10.u64 = r24.u64 & r12.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stb r11,5(r8)
	PPC_STORE_U8(ctx.r8.u32 + 5, r11.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// sth r27,368(r11)
	PPC_STORE_U16(r11.u32 + 368, r27.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// sth r10,58(r11)
	PPC_STORE_U16(r11.u32 + 58, ctx.r10.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r22,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r22.u32);
	// bl 0x827bcfc4
	ctx.lr = 0x82134738;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r10,128
	ctx.r10.s64 = 128;
	// stb r3,379(r11)
	PPC_STORE_U8(r11.u32 + 379, ctx.r3.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,384
	r11.s64 = r11.s64 + 384;
loc_8213474C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8213474c
	if (!cr0.eq) goto loc_8213474C;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r21,-1
	cr6.compare<int32_t>(r21.s32, -1, xer);
	// addi r11,r10,88
	r11.s64 = ctx.r10.s64 + 88;
	// stw r11,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, r11.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// bne cr6,0x82134784
	if (!cr6.eq) goto loc_82134784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r21,r29
	r21.u64 = r29.u64;
	// bl 0x827bcff4
	ctx.lr = 0x82134784;
	__imp__RtlInitializeCriticalSection(ctx, base);
loc_82134784:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r21,1408(r11)
	PPC_STORE_U32(r11.u32 + 1408, r21.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
	// add r4,r30,r3
	ctx.r4.u64 = r30.u64 + ctx.r3.u64;
	// bl 0x82133ba8
	ctx.lr = 0x821347B0;
	sub_82133BA8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82134370
	if (cr0.eq) goto loc_82134370;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm. r10,r24,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x10000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r22,56(r11)
	PPC_STORE_U16(r11.u32 + 56, r22.u16);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// stw r10,1412(r11)
	PPC_STORE_U32(r11.u32 + 1412, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r10,31
	ctx.r10.s64 = 31;
	// li r9,-16
	ctx.r9.s64 = -16;
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r9.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_82134844:
	// addi r1,r31,272
	ctx.r1.s64 = r31.s64 + 272;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82134368"))) PPC_WEAK_FUNC(sub_82134368);
PPC_FUNC_IMPL(__imp__sub_82134368) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r30{};
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82134378
	if (!cr6.lt) {
		sub_82134378(ctx, base);
		return;
	}
}

__attribute__((alias("__imp__sub_82134378"))) PPC_WEAK_FUNC(sub_82134378);
PPC_FUNC_IMPL(__imp__sub_82134378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r31{};
	// lwz r6,316(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 316);
}

__attribute__((alias("__imp__sub_8213437C"))) PPC_WEAK_FUNC(sub_8213437C);
PPC_FUNC_IMPL(__imp__sub_8213437C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r23{};
	// lis r23,-32107
	r23.s64 = -2104164352;
	// lwz r11,-23144(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -23144);
}

__attribute__((alias("__imp__sub_8213484C"))) PPC_WEAK_FUNC(sub_8213484C);
PPC_FUNC_IMPL(__imp__sub_8213484C) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82134858"))) PPC_WEAK_FUNC(sub_82134858);
PPC_FUNC_IMPL(__imp__sub_82134858) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
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
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9336(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9336);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82134868;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r24,0
	r24.s64 = 0;
	// mr r28,r30
	r28.u64 = r30.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// stw r24,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r24.u32);
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r28,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r28.u32);
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
	// beq 0x821348c8
	if (cr0.eq) goto loc_821348C8;
	// bl 0x827bcfc4
	ctx.lr = 0x821348A4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821348c8
	if (cr6.eq) goto loc_821348C8;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// li r6,1459
	ctx.r6.s64 = 1459;
	// lwz r5,312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821348C8;
	__imp__KeBugCheckEx(ctx, base);
loc_821348C8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// or r23,r11,r29
	r23.u64 = r11.u64 | r29.u64;
	// li r27,1
	r27.s64 = 1;
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x821348e4
	if (!cr6.eq) goto loc_821348E4;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821348E4:
	// addi r11,r11,31
	r11.s64 = r11.s64 + 31;
	// rlwinm r4,r11,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// stw r4,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r4.u32);
	// rlwinm r29,r4,28,4,31
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82134914
	if (!cr0.eq) goto loc_82134914;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x82134908;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r22,r27
	r22.u64 = r27.u64;
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_82134914:
	// cmplwi cr6,r29,128
	cr6.compare<uint32_t>(r29.u32, 128, xer);
	// bge cr6,0x82134b1c
	if (!cr6.lt) goto loc_82134B1C;
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821349d8
	if (cr6.eq) goto loc_821349D8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stb r8,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r8.u8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rldicr r4,r6,32,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r7,r5,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
	// or r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 | ctx.r6.u64;
	// cmpld cr6,r6,r7
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r7.u64, xer);
	// bne cr6,0x821349a8
	if (!cr6.eq) goto loc_821349A8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// bne cr6,0x821349a8
	if (!cr6.eq) goto loc_821349A8;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// xor r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
loc_821349A8:
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r26,r11
	r26.u64 = r11.u64;
	// subf r10,r29,r10
	ctx.r10.s64 = ctx.r10.s64 - r29.s64;
	// rlwimi r8,r27,0,28,26
	ctx.r8.u64 = (__builtin_rotateleft32(r27.u32, 0) & 0xFFFFFFFFFFFFFFEF) | (ctx.r8.u64 & 0x10);
	// stw r10,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r10.u32);
	// stw r26,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r26.u32);
	// stb r8,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r8.u8);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r10,r25,r10
	ctx.r10.s64 = ctx.r10.s64 - r25.s64;
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
	// stb r24,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r24.u8);
	// b 0x82134f80
	goto loc_82134F80;
loc_821349D8:
	// clrlwi r10,r29,27
	ctx.r10.u64 = r29.u32 & 0x1F;
	// rlwinm r11,r29,27,5,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x7FFFFFF;
	// slw r10,r27,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// addi r9,r11,88
	ctx.r9.s64 = r11.s64 + 88;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// andc r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// blt cr6,0x82134a28
	if (cr6.lt) goto loc_82134A28;
	// beq cr6,0x82134a48
	if (cr6.eq) goto loc_82134A48;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x82134a68
	if (cr6.lt) goto loc_82134A68;
	// beq cr6,0x82134a88
	if (cr6.eq) goto loc_82134A88;
	// b 0x82134b28
	goto loc_82134B28;
loc_82134A28:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a38
	if (cr6.eq) goto loc_82134A38;
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A38:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82134A48:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a58
	if (cr6.eq) goto loc_82134A58;
	// addi r10,r30,640
	ctx.r10.s64 = r30.s64 + 640;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A58:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82134A68:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a78
	if (cr6.eq) goto loc_82134A78;
	// addi r10,r30,896
	ctx.r10.s64 = r30.s64 + 896;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A78:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
loc_82134A88:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134b28
	if (cr6.eq) goto loc_82134B28;
	// addi r10,r30,1152
	ctx.r10.s64 = r30.s64 + 1152;
loc_82134A94:
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r11,r11,31
	xer.ca = r11.u32 <= 31;
	r11.s64 = 31 - r11.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x82134bd0
	if (!cr6.eq) goto loc_82134BD0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82134bd0
	if (!cr6.eq) goto loc_82134BD0;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rlwinm r11,r10,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// addi r11,r11,88
	r11.s64 = r11.s64 + 88;
	// slw r10,r27,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
	// b 0x82134bd0
	goto loc_82134BD0;
loc_82134B1C:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bgt cr6,0x82134fbc
	if (cr6.gt) goto loc_82134FBC;
loc_82134B28:
	// lwz r11,388(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// beq cr6,0x82134b84
	if (cr6.eq) goto loc_82134B84;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x82134b84
	if (cr6.lt) goto loc_82134B84;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
loc_82134B58:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134b84
	if (cr6.eq) goto loc_82134B84;
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// bge cr6,0x82134b98
	if (!cr6.lt) goto loc_82134B98;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134b58
	goto loc_82134B58;
loc_82134B84:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82133d10
	ctx.lr = 0x82134B8C;
	sub_82133D10(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82135088
	if (cr0.eq) goto loc_82135088;
loc_82134B98:
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x82134bcc
	if (!cr6.eq) goto loc_82134BCC;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82134BCC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_82134BD0:
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r8,48(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// stw r9,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r9.u32);
	// stw r26,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r26.u32);
	// stb r27,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r27.u8);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// subf. r7,r29,r9
	ctx.r7.s64 = ctx.r9.s64 - r29.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// stb r9,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r9.u8);
	// stb r24,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r24.u8);
	// beq 0x82134f6c
	if (cr0.eq) goto loc_82134F6C;
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bne cr6,0x82134c3c
	if (!cr6.eq) goto loc_82134C3C;
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// b 0x82134f6c
	goto loc_82134F6C;
loc_82134C3C:
	// rlwinm r9,r29,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm. r8,r10,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r30,r9,r3
	r30.u64 = ctx.r9.u64 + ctx.r3.u64;
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// stb r11,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r11.u8);
	// sth r9,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r9.u16);
	// beq 0x82134cfc
	if (cr0.eq) goto loc_82134CFC;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// bge cr6,0x82134cb8
	if (!cr6.lt) goto loc_82134CB8;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134d68
	if (!cr6.eq) goto loc_82134D68;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// b 0x82134d64
	goto loc_82134D64;
loc_82134CB8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
loc_82134CD0:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134d68
	if (cr6.eq) goto loc_82134D68;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r6,r11,-8
	ctx.r6.s64 = r11.s64 + -8;
	// stw r6,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r6.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82134d68
	if (!cr6.gt) goto loc_82134D68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134cd0
	goto loc_82134CD0;
loc_82134CFC:
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82134dcc
	if (cr0.eq) goto loc_82134DCC;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r9.u16);
	// cmplwi cr6,r8,128
	cr6.compare<uint32_t>(ctx.r8.u32, 128, xer);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bge cr6,0x82134d8c
	if (!cr6.lt) goto loc_82134D8C;
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r9,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r9.u8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134d68
	if (!cr6.eq) goto loc_82134D68;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
loc_82134D64:
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
loc_82134D68:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// b 0x82134f30
	goto loc_82134F30;
loc_82134D8C:
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_82134DA0:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134d68
	if (cr6.eq) goto loc_82134D68;
	// lhz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r6,r11,-8
	ctx.r6.s64 = r11.s64 + -8;
	// stw r6,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r6.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// ble cr6,0x82134d68
	if (!cr6.gt) goto loc_82134D68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134da0
	goto loc_82134DA0;
loc_82134DCC:
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldimi r8,r6,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// rldicr r6,r5,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// cmpld cr6,r6,r8
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r8.u64, xer);
	// bne cr6,0x82134e38
	if (!cr6.eq) goto loc_82134E38;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82134e38
	if (!cr6.eq) goto loc_82134E38;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// bge cr6,0x82134e38
	if (!cr6.lt) goto loc_82134E38;
	// rlwinm r9,r10,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// addi r9,r9,88
	ctx.r9.s64 = ctx.r9.s64 + 88;
	// slw r8,r27,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// xor r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
loc_82134E38:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r9,48(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r10.u32);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add r5,r11,r7
	ctx.r5.u64 = r11.u64 + ctx.r7.u64;
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x82134f38
	if (cr6.gt) goto loc_82134F38;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82134e78
	if (!cr0.eq) goto loc_82134E78;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
loc_82134E78:
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bge cr6,0x82134ed0
	if (!cr6.lt) goto loc_82134ED0;
	// addi r10,r9,48
	ctx.r10.s64 = ctx.r9.s64 + 48;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r9,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r9.u8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134f10
	if (!cr6.eq) goto loc_82134F10;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
	// b 0x82134f10
	goto loc_82134F10;
loc_82134ED0:
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_82134EE4:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134f10
	if (cr6.eq) goto loc_82134F10;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r7.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82134f10
	if (!cr6.gt) goto loc_82134F10;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134ee4
	goto loc_82134EE4;
loc_82134F10:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
loc_82134F30:
	// stw r11,48(r28)
	PPC_STORE_U32(r28.u32 + 48, r11.u32);
	// b 0x82134f44
	goto loc_82134F44;
loc_82134F38:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82133438
	ctx.lr = 0x82134F44;
	sub_82133438(ctx, base);
loc_82134F44:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134f6c
	if (cr0.eq) goto loc_82134F6C;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r30,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r30.u32);
loc_82134F6C:
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134f80
	if (cr0.eq) goto loc_82134F80;
	// lbz r11,5(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 5);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,5(r26)
	PPC_STORE_U8(r26.u32 + 5, r11.u8);
loc_82134F80:
	// addi r30,r26,16
	r30.s64 = r26.s64 + 16;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// beq cr6,0x82134fa0
	if (cr6.eq) goto loc_82134FA0;
	// lwz r3,1408(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82134F98;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r22,r24
	r22.u64 = r24.u64;
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
loc_82134FA0:
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x821350bc
	if (cr0.eq) goto loc_821350BC;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x82134FB8;
	sub_823D9890(ctx, base);
	// b 0x821350bc
	goto loc_821350BC;
loc_82134FBC:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8213508c
	if (cr0.eq) goto loc_8213508C;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r24,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r24.u32);
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne 0x82134fe4
	if (!cr0.eq) goto loc_82134FE4;
	// lis r11,128
	r11.s64 = 8388608;
loc_82134FE4:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// oris r5,r11,24576
	ctx.r5.u64 = r11.u64 | 1610612736;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82135000;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82135088
	if (cr0.lt) goto loc_82135088;
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82135018;
	sub_823D9890(ctx, base);
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r11,r30,88
	r11.s64 = r30.s64 + 88;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// addis r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 65536;
	// addi r9,r9,-48
	ctx.r9.s64 = ctx.r9.s64 + -48;
	// sth r9,32(r8)
	PPC_STORE_U16(ctx.r8.u32 + 32, ctx.r9.u16);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r10,37(r9)
	PPC_STORE_U8(ctx.r9.u32 + 37, ctx.r10.u8);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,92(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// stw r11,92(r30)
	PPC_STORE_U32(r30.u32 + 92, r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// b 0x821350bc
	goto loc_821350BC;
loc_82135088:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_8213508C:
	// rlwinm. r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x821350b8
	if (cr0.eq) goto loc_821350B8;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// stw r24,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r24.u32);
	// stw r27,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r27.u32);
	// stw r24,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r24.u32);
	// stw r4,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r4.u32);
	// bl 0x827bd014
	ctx.lr = 0x821350B8;
	__imp__RtlRaiseException(ctx, base);
loc_821350B8:
	// stw r24,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r24.u32);
loc_821350BC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,320
	r12.s64 = r31.s64 + 320;
	// bl 0x821350fc
	ctx.lr = 0x821350C8;
	sub_821350FC(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82134860"))) PPC_WEAK_FUNC(sub_82134860);
PPC_FUNC_IMPL(__imp__sub_82134860) {
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
	ctx.lr = 0x82134868;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r24,0
	r24.s64 = 0;
	// mr r28,r30
	r28.u64 = r30.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// stw r24,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r24.u32);
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r28,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r28.u32);
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
	// beq 0x821348c8
	if (cr0.eq) goto loc_821348C8;
	// bl 0x827bcfc4
	ctx.lr = 0x821348A4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821348c8
	if (cr6.eq) goto loc_821348C8;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// li r6,1459
	ctx.r6.s64 = 1459;
	// lwz r5,312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821348C8;
	__imp__KeBugCheckEx(ctx, base);
loc_821348C8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// or r23,r11,r29
	r23.u64 = r11.u64 | r29.u64;
	// li r27,1
	r27.s64 = 1;
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x821348e4
	if (!cr6.eq) goto loc_821348E4;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821348E4:
	// addi r11,r11,31
	r11.s64 = r11.s64 + 31;
	// rlwinm r4,r11,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// stw r4,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r4.u32);
	// rlwinm r29,r4,28,4,31
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82134914
	if (!cr0.eq) goto loc_82134914;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x82134908;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r22,r27
	r22.u64 = r27.u64;
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_82134914:
	// cmplwi cr6,r29,128
	cr6.compare<uint32_t>(r29.u32, 128, xer);
	// bge cr6,0x82134b1c
	if (!cr6.lt) goto loc_82134B1C;
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821349d8
	if (cr6.eq) goto loc_821349D8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stb r8,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r8.u8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rldicr r4,r6,32,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r7,r5,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
	// or r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 | ctx.r6.u64;
	// cmpld cr6,r6,r7
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r7.u64, xer);
	// bne cr6,0x821349a8
	if (!cr6.eq) goto loc_821349A8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// bne cr6,0x821349a8
	if (!cr6.eq) goto loc_821349A8;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// xor r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
loc_821349A8:
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r26,r11
	r26.u64 = r11.u64;
	// subf r10,r29,r10
	ctx.r10.s64 = ctx.r10.s64 - r29.s64;
	// rlwimi r8,r27,0,28,26
	ctx.r8.u64 = (__builtin_rotateleft32(r27.u32, 0) & 0xFFFFFFFFFFFFFFEF) | (ctx.r8.u64 & 0x10);
	// stw r10,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r10.u32);
	// stw r26,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r26.u32);
	// stb r8,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r8.u8);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r10,r25,r10
	ctx.r10.s64 = ctx.r10.s64 - r25.s64;
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
	// stb r24,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r24.u8);
	// b 0x82134f80
	goto loc_82134F80;
loc_821349D8:
	// clrlwi r10,r29,27
	ctx.r10.u64 = r29.u32 & 0x1F;
	// rlwinm r11,r29,27,5,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x7FFFFFF;
	// slw r10,r27,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// addi r9,r11,88
	ctx.r9.s64 = r11.s64 + 88;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// andc r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// blt cr6,0x82134a28
	if (cr6.lt) goto loc_82134A28;
	// beq cr6,0x82134a48
	if (cr6.eq) goto loc_82134A48;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x82134a68
	if (cr6.lt) goto loc_82134A68;
	// beq cr6,0x82134a88
	if (cr6.eq) goto loc_82134A88;
	// b 0x82134b28
	goto loc_82134B28;
loc_82134A28:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a38
	if (cr6.eq) goto loc_82134A38;
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A38:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82134A48:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a58
	if (cr6.eq) goto loc_82134A58;
	// addi r10,r30,640
	ctx.r10.s64 = r30.s64 + 640;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A58:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82134A68:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134a78
	if (cr6.eq) goto loc_82134A78;
	// addi r10,r30,896
	ctx.r10.s64 = r30.s64 + 896;
	// b 0x82134a94
	goto loc_82134A94;
loc_82134A78:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
loc_82134A88:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82134b28
	if (cr6.eq) goto loc_82134B28;
	// addi r10,r30,1152
	ctx.r10.s64 = r30.s64 + 1152;
loc_82134A94:
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r11,r11,31
	xer.ca = r11.u32 <= 31;
	r11.s64 = 31 - r11.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x82134bd0
	if (!cr6.eq) goto loc_82134BD0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82134bd0
	if (!cr6.eq) goto loc_82134BD0;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rlwinm r11,r10,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// addi r11,r11,88
	r11.s64 = r11.s64 + 88;
	// slw r10,r27,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
	// b 0x82134bd0
	goto loc_82134BD0;
loc_82134B1C:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bgt cr6,0x82134fbc
	if (cr6.gt) goto loc_82134FBC;
loc_82134B28:
	// lwz r11,388(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// beq cr6,0x82134b84
	if (cr6.eq) goto loc_82134B84;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x82134b84
	if (cr6.lt) goto loc_82134B84;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
loc_82134B58:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134b84
	if (cr6.eq) goto loc_82134B84;
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// bge cr6,0x82134b98
	if (!cr6.lt) goto loc_82134B98;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134b58
	goto loc_82134B58;
loc_82134B84:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82133d10
	ctx.lr = 0x82134B8C;
	sub_82133D10(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82135088
	if (cr0.eq) goto loc_82135088;
loc_82134B98:
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r6,r8,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rldimi r9,r7,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x82134bcc
	if (!cr6.eq) goto loc_82134BCC;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82134BCC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_82134BD0:
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r8,48(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// stw r9,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r9.u32);
	// stw r26,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r26.u32);
	// stb r27,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r27.u8);
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// subf. r7,r29,r9
	ctx.r7.s64 = ctx.r9.s64 - r29.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// stb r9,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r9.u8);
	// stb r24,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r24.u8);
	// beq 0x82134f6c
	if (cr0.eq) goto loc_82134F6C;
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bne cr6,0x82134c3c
	if (!cr6.eq) goto loc_82134C3C;
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// b 0x82134f6c
	goto loc_82134F6C;
loc_82134C3C:
	// rlwinm r9,r29,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm. r8,r10,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r30,r9,r3
	r30.u64 = ctx.r9.u64 + ctx.r3.u64;
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// stb r11,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r11.u8);
	// sth r9,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r9.u16);
	// beq 0x82134cfc
	if (cr0.eq) goto loc_82134CFC;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// bge cr6,0x82134cb8
	if (!cr6.lt) goto loc_82134CB8;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134d68
	if (!cr6.eq) goto loc_82134D68;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// b 0x82134d64
	goto loc_82134D64;
loc_82134CB8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
loc_82134CD0:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134d68
	if (cr6.eq) goto loc_82134D68;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r6,r11,-8
	ctx.r6.s64 = r11.s64 + -8;
	// stw r6,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r6.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82134d68
	if (!cr6.gt) goto loc_82134D68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134cd0
	goto loc_82134CD0;
loc_82134CFC:
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82134dcc
	if (cr0.eq) goto loc_82134DCC;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r9.u16);
	// cmplwi cr6,r8,128
	cr6.compare<uint32_t>(ctx.r8.u32, 128, xer);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bge cr6,0x82134d8c
	if (!cr6.lt) goto loc_82134D8C;
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r9,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r9.u8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134d68
	if (!cr6.eq) goto loc_82134D68;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
loc_82134D64:
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
loc_82134D68:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// b 0x82134f30
	goto loc_82134F30;
loc_82134D8C:
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_82134DA0:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134d68
	if (cr6.eq) goto loc_82134D68;
	// lhz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r6,r11,-8
	ctx.r6.s64 = r11.s64 + -8;
	// stw r6,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r6.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// ble cr6,0x82134d68
	if (!cr6.gt) goto loc_82134D68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134da0
	goto loc_82134DA0;
loc_82134DCC:
	// stb r10,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r10.u8);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldimi r8,r6,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// rldicr r6,r5,32,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// cmpld cr6,r6,r8
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r8.u64, xer);
	// bne cr6,0x82134e38
	if (!cr6.eq) goto loc_82134E38;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// bne cr6,0x82134e38
	if (!cr6.eq) goto loc_82134E38;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// bge cr6,0x82134e38
	if (!cr6.lt) goto loc_82134E38;
	// rlwinm r9,r10,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// addi r9,r9,88
	ctx.r9.s64 = ctx.r9.s64 + 88;
	// slw r8,r27,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// xor r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
loc_82134E38:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r9,48(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r10.u32);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add r5,r11,r7
	ctx.r5.u64 = r11.u64 + ctx.r7.u64;
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x82134f38
	if (cr6.gt) goto loc_82134F38;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82134e78
	if (!cr0.eq) goto loc_82134E78;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
loc_82134E78:
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bge cr6,0x82134ed0
	if (!cr6.lt) goto loc_82134ED0;
	// addi r10,r9,48
	ctx.r10.s64 = ctx.r9.s64 + 48;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r9,5(r30)
	PPC_STORE_U8(r30.u32 + 5, ctx.r9.u8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82134f10
	if (!cr6.eq) goto loc_82134F10;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r9.u32);
	// b 0x82134f10
	goto loc_82134F10;
loc_82134ED0:
	// addi r10,r28,384
	ctx.r10.s64 = r28.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// lwz r11,384(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_82134EE4:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82134f10
	if (cr6.eq) goto loc_82134F10;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r7.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82134f10
	if (!cr6.gt) goto loc_82134F10;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82134ee4
	goto loc_82134EE4;
loc_82134F10:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
loc_82134F30:
	// stw r11,48(r28)
	PPC_STORE_U32(r28.u32 + 48, r11.u32);
	// b 0x82134f44
	goto loc_82134F44;
loc_82134F38:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82133438
	ctx.lr = 0x82134F44;
	sub_82133438(ctx, base);
loc_82134F44:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134f6c
	if (cr0.eq) goto loc_82134F6C;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r30,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r30.u32);
loc_82134F6C:
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82134f80
	if (cr0.eq) goto loc_82134F80;
	// lbz r11,5(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 5);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,5(r26)
	PPC_STORE_U8(r26.u32 + 5, r11.u8);
loc_82134F80:
	// addi r30,r26,16
	r30.s64 = r26.s64 + 16;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// beq cr6,0x82134fa0
	if (cr6.eq) goto loc_82134FA0;
	// lwz r3,1408(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82134F98;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r22,r24
	r22.u64 = r24.u64;
	// stw r22,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r22.u32);
loc_82134FA0:
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x821350bc
	if (cr0.eq) goto loc_821350BC;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x82134FB8;
	sub_823D9890(ctx, base);
	// b 0x821350bc
	goto loc_821350BC;
loc_82134FBC:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8213508c
	if (cr0.eq) goto loc_8213508C;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r24,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r24.u32);
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne 0x82134fe4
	if (!cr0.eq) goto loc_82134FE4;
	// lis r11,128
	r11.s64 = 8388608;
loc_82134FE4:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4
	ctx.r6.s64 = 4;
	// oris r5,r11,24576
	ctx.r5.u64 = r11.u64 | 1610612736;
	// ori r5,r5,4096
	ctx.r5.u64 = ctx.r5.u64 | 4096;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x827bcf94
	ctx.lr = 0x82135000;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82135088
	if (cr0.lt) goto loc_82135088;
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82135018;
	sub_823D9890(ctx, base);
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r11,r30,88
	r11.s64 = r30.s64 + 88;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// addis r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 65536;
	// addi r9,r9,-48
	ctx.r9.s64 = ctx.r9.s64 + -48;
	// sth r9,32(r8)
	PPC_STORE_U16(ctx.r8.u32 + 32, ctx.r9.u16);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r10,37(r9)
	PPC_STORE_U8(ctx.r9.u32 + 37, ctx.r10.u8);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,92(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// stw r11,92(r30)
	PPC_STORE_U32(r30.u32 + 92, r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// b 0x821350bc
	goto loc_821350BC;
loc_82135088:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_8213508C:
	// rlwinm. r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x821350b8
	if (cr0.eq) goto loc_821350B8;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// stw r24,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r24.u32);
	// stw r27,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r27.u32);
	// stw r24,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r24.u32);
	// stw r4,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r4.u32);
	// bl 0x827bd014
	ctx.lr = 0x821350B8;
	__imp__RtlRaiseException(ctx, base);
loc_821350B8:
	// stw r24,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r24.u32);
loc_821350BC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,320
	r12.s64 = r31.s64 + 320;
	// bl 0x821350fc
	ctx.lr = 0x821350C8;
	sub_821350FC(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821350D4"))) PPC_WEAK_FUNC(sub_821350D4);
PPC_FUNC_IMPL(__imp__sub_821350D4) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r22{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// std r22,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r22.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,124(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r22,104(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// b 0x82135118
	goto loc_82135118;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// std r22,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r22.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82135118:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82135128
	if (cr6.eq) goto loc_82135128;
	// lwz r3,1408(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135128;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82135128:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r22,-24(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821350FC"))) PPC_WEAK_FUNC(sub_821350FC);
PPC_FUNC_IMPL(__imp__sub_821350FC) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r22{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// std r22,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r22.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82135128
	if (cr6.eq) goto loc_82135128;
	// lwz r3,1408(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135128;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82135128:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r22,-24(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135144"))) PPC_WEAK_FUNC(sub_82135144);
PPC_FUNC_IMPL(__imp__sub_82135144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135148"))) PPC_WEAK_FUNC(sub_82135148);
PPC_FUNC_IMPL(__imp__sub_82135148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9360(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9360);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82135158;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r26,0
	r26.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// mr r25,r26
	r25.u64 = r26.u64;
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
	// beq 0x821351b8
	if (cr0.eq) goto loc_821351B8;
	// bl 0x827bcfc4
	ctx.lr = 0x82135194;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821351b8
	if (cr6.eq) goto loc_821351B8;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,4390
	ctx.r6.s64 = 4390;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821351B8;
	__imp__KeBugCheckEx(ctx, base);
loc_821351B8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821351c8
	if (!cr6.eq) goto loc_821351C8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821353c0
	goto loc_821353C0;
loc_821351C8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r29,r29,-16
	r29.s64 = r29.s64 + -16;
	// or r11,r11,r28
	r11.u64 = r11.u64 | r28.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x821351f0
	if (!cr0.eq) goto loc_821351F0;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x821351E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r25,r27
	r25.u64 = r27.u64;
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
loc_821351F0:
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82135358
	if (!cr0.eq) goto loc_82135358;
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bl 0x82133010
	ctx.lr = 0x82135218;
	sub_82133010(ctx, base);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,128
	cr6.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// bge cr6,0x821352a0
	if (!cr6.lt) goto loc_821352A0;
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82135278
	if (!cr6.eq) goto loc_82135278;
	// lhz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
loc_82135278:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82135344
	goto loc_82135344;
loc_821352A0:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x821352cc
	if (cr6.lt) goto loc_821352CC;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821352cc
	if (cr6.lt) goto loc_821352CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133f50
	ctx.lr = 0x821352C8;
	sub_82133F50(ctx, base);
	// b 0x821353b0
	goto loc_821353B0;
loc_821352CC:
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x8213534c
	if (cr6.gt) goto loc_8213534C;
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// lwz r11,384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
loc_821352EC:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82135320
	if (cr6.eq) goto loc_82135320;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r11,-8
	ctx.r8.s64 = r11.s64 + -8;
	// lhz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// ble cr6,0x82135320
	if (!cr6.gt) goto loc_82135320;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x821352ec
	goto loc_821352EC;
loc_82135320:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_82135344:
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// b 0x821353b0
	goto loc_821353B0;
loc_8213534C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133438
	ctx.lr = 0x82135354;
	sub_82133438(ctx, base);
	// b 0x821353b0
	goto loc_821353B0;
loc_82135358:
	// addi r11,r29,-32
	r11.s64 = r29.s64 + -32;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// lwz r11,-32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -32);
	// lwz r10,-28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// beq cr6,0x82135388
	if (cr6.eq) goto loc_82135388;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135380;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r25,r26
	r25.u64 = r26.u64;
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
loc_82135388:
	// stw r26,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r26.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x827bcfd4
	ctx.lr = 0x821353A4;
	__imp__NtFreeVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x821353b0
	if (!cr0.lt) goto loc_821353B0;
	// stw r26,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r26.u32);
loc_821353B0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	r12.s64 = r31.s64 + 176;
	// bl 0x821353f0
	ctx.lr = 0x821353BC;
	sub_821353F0(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_821353C0:
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82135150"))) PPC_WEAK_FUNC(sub_82135150);
PPC_FUNC_IMPL(__imp__sub_82135150) {
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
	ctx.lr = 0x82135158;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r26,0
	r26.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// mr r25,r26
	r25.u64 = r26.u64;
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
	// beq 0x821351b8
	if (cr0.eq) goto loc_821351B8;
	// bl 0x827bcfc4
	ctx.lr = 0x82135194;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821351b8
	if (cr6.eq) goto loc_821351B8;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,4390
	ctx.r6.s64 = 4390;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821351B8;
	__imp__KeBugCheckEx(ctx, base);
loc_821351B8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821351c8
	if (!cr6.eq) goto loc_821351C8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821353c0
	goto loc_821353C0;
loc_821351C8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r29,r29,-16
	r29.s64 = r29.s64 + -16;
	// or r11,r11,r28
	r11.u64 = r11.u64 | r28.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x821351f0
	if (!cr0.eq) goto loc_821351F0;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x821351E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r25,r27
	r25.u64 = r27.u64;
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
loc_821351F0:
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82135358
	if (!cr0.eq) goto loc_82135358;
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bl 0x82133010
	ctx.lr = 0x82135218;
	sub_82133010(ctx, base);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,128
	cr6.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// bge cr6,0x821352a0
	if (!cr6.lt) goto loc_821352A0;
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82135278
	if (!cr6.eq) goto loc_82135278;
	// lhz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
loc_82135278:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82135344
	goto loc_82135344;
loc_821352A0:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x821352cc
	if (cr6.lt) goto loc_821352CC;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821352cc
	if (cr6.lt) goto loc_821352CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133f50
	ctx.lr = 0x821352C8;
	sub_82133F50(ctx, base);
	// b 0x821353b0
	goto loc_821353B0;
loc_821352CC:
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x8213534c
	if (cr6.gt) goto loc_8213534C;
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r11.u8);
	// lwz r11,384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
loc_821352EC:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82135320
	if (cr6.eq) goto loc_82135320;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r11,-8
	ctx.r8.s64 = r11.s64 + -8;
	// lhz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// ble cr6,0x82135320
	if (!cr6.gt) goto loc_82135320;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x821352ec
	goto loc_821352EC;
loc_82135320:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_82135344:
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// b 0x821353b0
	goto loc_821353B0;
loc_8213534C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82133438
	ctx.lr = 0x82135354;
	sub_82133438(ctx, base);
	// b 0x821353b0
	goto loc_821353B0;
loc_82135358:
	// addi r11,r29,-32
	r11.s64 = r29.s64 + -32;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// lwz r11,-32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -32);
	// lwz r10,-28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// beq cr6,0x82135388
	if (cr6.eq) goto loc_82135388;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135380;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r25,r26
	r25.u64 = r26.u64;
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
loc_82135388:
	// stw r26,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r26.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x827bcfd4
	ctx.lr = 0x821353A4;
	__imp__NtFreeVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x821353b0
	if (!cr0.lt) goto loc_821353B0;
	// stw r26,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r26.u32);
loc_821353B0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	r12.s64 = r31.s64 + 176;
	// bl 0x821353f0
	ctx.lr = 0x821353BC;
	sub_821353F0(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_821353C0:
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821353C8"))) PPC_WEAK_FUNC(sub_821353C8);
PPC_FUNC_IMPL(__imp__sub_821353C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r25{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-176
	r31.s64 = r12.s64 + -176;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r25,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r25.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,100(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r25,84(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// b 0x8213540c
	goto loc_8213540C;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-176
	r31.s64 = r12.s64 + -176;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r25,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r25.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_8213540C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8213541c
	if (cr6.eq) goto loc_8213541C;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x8213541C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8213541C:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r25,-24(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821353F0"))) PPC_WEAK_FUNC(sub_821353F0);
PPC_FUNC_IMPL(__imp__sub_821353F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r25{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-176
	r31.s64 = r12.s64 + -176;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r25,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r25.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8213541c
	if (cr6.eq) goto loc_8213541C;
	// lwz r3,1408(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x8213541C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8213541C:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r25,-24(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135438"))) PPC_WEAK_FUNC(sub_82135438);
PPC_FUNC_IMPL(__imp__sub_82135438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9384(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9384);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82135448;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r27.u32);
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// li r19,0
	r19.s64 = 0;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r19,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r19.u32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r20,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r20.u32);
	// mr r21,r27
	r21.u64 = r27.u64;
	// stw r26,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r26.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r21,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r21.u32);
	// beq 0x821354b0
	if (cr0.eq) goto loc_821354B0;
	// bl 0x827bcfc4
	ctx.lr = 0x8213548C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821354b0
	if (cr6.eq) goto loc_821354B0;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// li r6,3144
	ctx.r6.s64 = 3144;
	// lwz r5,312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821354B0;
	__imp__KeBugCheckEx(ctx, base);
loc_821354B0:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x821354c0
	if (!cr6.eq) goto loc_821354C0;
loc_821354B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82135c88
	sub_82135C88(ctx, base);
	return;
loc_821354C0:
	// lis r11,32767
	r11.s64 = 2147418112;
	// lwz r10,24(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// or r23,r10,r30
	r23.u64 = ctx.r10.u64 | r30.u64;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bgt cr6,0x821354b8
	if (cr6.gt) goto loc_821354B8;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// li r22,1
	r22.s64 = 1;
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x821354ec
	if (!cr6.eq) goto loc_821354EC;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_821354EC:
	// lwz r10,80(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// rlwinm r9,r23,0,2,23
	ctx.r9.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x3FFFFF00;
	// rlwinm. r9,r9,0,23,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFC0001FF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,84(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// and r24,r11,r8
	r24.u64 = r11.u64 & ctx.r8.u64;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
	// bne 0x82135524
	if (!cr0.eq) goto loc_82135524;
	// lwz r11,380(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82135524
	if (!cr6.eq) goto loc_82135524;
	// lbz r11,-11(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + -11);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8213552c
	if (cr0.eq) goto loc_8213552C;
loc_82135524:
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
loc_8213552C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82135550
	if (!cr0.eq) goto loc_82135550;
	// lwz r3,1408(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x82135544;
	__imp__RtlEnterCriticalSection(ctx, base);
	// xori r23,r23,1
	r23.u64 = r23.u64 ^ 1;
	// stw r22,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r22.u32);
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135550:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r30,r20,-16
	r30.s64 = r20.s64 + -16;
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// lbz r7,5(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi. r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c5c
	if (cr0.eq) {
		sub_82135C5C(ctx, base);
		return;
	}
	// rlwinm. r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// beq 0x821355b8
	if (cr0.eq) goto loc_821355B8;
	// addi r9,r24,32
	ctx.r9.s64 = r24.s64 + 32;
	// lwz r8,-8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// addi r10,r30,-32
	ctx.r10.s64 = r30.s64 + -32;
	// addis r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 65536;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - r11.s64;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// rlwinm r24,r5,0,0,15
	r24.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFF0000;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// addi r25,r8,-48
	r25.s64 = ctx.r8.s64 + -48;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// rlwinm r29,r4,28,4,31
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
	// b 0x821355c8
	goto loc_821355C8;
loc_821355B8:
	// lbz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// rotlwi r9,r11,4
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 4);
	// mr r29,r11
	r29.u64 = r11.u64;
	// subf r25,r10,r9
	r25.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_821355C8:
	// stw r25,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r25.u32);
	// rlwinm r28,r24,28,4,31
	r28.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 28) & 0xFFFFFFF;
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// bgt cr6,0x82135a2c
	if (cr6.gt) goto loc_82135A2C;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bne cr6,0x821355f8
	if (!cr6.eq) goto loc_821355F8;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
loc_821355F8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82135614
	if (cr6.eq) goto loc_82135614;
	// subf r11,r26,r24
	r11.s64 = r24.s64 - r26.s64;
	// addis r11,r11,1
	r11.s64 = r11.s64 + 65536;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// b 0x82135654
	goto loc_82135654;
loc_82135614:
	// rlwinm. r10,r7,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213564c
	if (cr0.eq) goto loc_8213564C;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r28,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// add r11,r9,r30
	r11.u64 = ctx.r9.u64 + r30.u64;
	// subf r9,r26,r24
	ctx.r9.s64 = r24.s64 - r26.s64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// ld r8,-16(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + -16);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// ld r10,-8(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + -8);
	// std r10,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r10.u64);
	// stb r9,6(r30)
	PPC_STORE_U8(r30.u32 + 6, ctx.r9.u8);
	// b 0x82135654
	goto loc_82135654;
loc_8213564C:
	// subf r11,r26,r24
	r11.s64 = r24.s64 - r26.s64;
	// stb r11,6(r30)
	PPC_STORE_U8(r30.u32 + 6, r11.u8);
loc_82135654:
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// ble cr6,0x82135674
	if (!cr6.gt) goto loc_82135674;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135674
	if (cr0.eq) goto loc_82135674;
	// subf r5,r25,r26
	ctx.r5.s64 = r26.s64 - r25.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r25,r20
	ctx.r3.u64 = r25.u64 + r20.u64;
	// bl 0x823d9890
	ctx.lr = 0x82135674;
	sub_823D9890(ctx, base);
loc_82135674:
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// beq cr6,0x82135c28
	if (cr6.eq) {
		sub_82135C28(ctx, base);
		return;
	}
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821356d8
	if (cr0.eq) goto loc_821356D8;
	// addi r30,r30,-32
	r30.s64 = r30.s64 + -32;
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r30,r24
	ctx.r10.u64 = r30.u64 + r24.u64;
	// subf r11,r24,r11
	r11.s64 = r11.s64 - r24.s64;
	// stw r10,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r10.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x827bcfd4
	ctx.lr = 0x821356BC;
	__imp__NtFreeVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82135c28
	if (cr0.lt) {
		sub_82135C28(ctx, base);
		return;
	}
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// b 0x82135c28
	sub_82135C28(ctx, base);
	return;
loc_821356D8:
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r9,r28,16
	ctx.r9.u64 = r28.u32 & 0xFFFF;
	// add r29,r10,r30
	r29.u64 = ctx.r10.u64 + r30.u64;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// sth r9,2(r29)
	PPC_STORE_U16(r29.u32 + 2, ctx.r9.u16);
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// stb r11,4(r29)
	PPC_STORE_U8(r29.u32 + 4, r11.u8);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// subf r28,r28,r11
	r28.s64 = r11.s64 - r28.s64;
	// sth r9,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r9.u16);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// beq 0x8213578c
	if (cr0.eq) goto loc_8213578C;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// lwzx r9,r9,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// stw r29,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, r29.u32);
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x82135754
	if (!cr6.lt) goto loc_82135754;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// b 0x821357c8
	goto loc_821357C8;
loc_82135754:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r9,r27,384
	ctx.r9.s64 = r27.s64 + 384;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
loc_82135760:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82135800
	if (cr6.eq) goto loc_82135800;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82135800
	if (!cr6.gt) goto loc_82135800;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135760
	goto loc_82135760;
loc_8213578C:
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213585c
	if (cr0.eq) goto loc_8213585C;
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x82135824
	if (!cr6.lt) goto loc_82135824;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
loc_821357C8:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82135800
	if (!cr6.eq) goto loc_82135800;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r9.u32);
loc_82135800:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r29,8
	ctx.r10.s64 = r29.s64 + 8;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 48);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// b 0x82135a14
	goto loc_82135A14;
loc_82135824:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r10,r27,384
	ctx.r10.s64 = r27.s64 + 384;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
loc_82135830:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82135800
	if (cr6.eq) goto loc_82135800;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82135800
	if (!cr6.gt) goto loc_82135800;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135830
	goto loc_82135830;
loc_8213585C:
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicr r7,r8,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x821358c8
	if (!cr6.eq) goto loc_821358C8;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x821358c8
	if (!cr6.eq) goto loc_821358C8;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821358c8
	if (!cr6.lt) goto loc_821358C8;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r22.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r10.u32);
loc_821358C8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213590c
	if (cr0.eq) goto loc_8213590C;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// stw r4,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r4.u32);
	// beq 0x821358fc
	if (cr0.eq) goto loc_821358FC;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x821358fc
	if (!cr6.gt) goto loc_821358FC;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r4,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r4.u32);
loc_821358FC:
	// lis r5,-274
	ctx.r5.s64 = -17956864;
	// ori r5,r5,65262
	ctx.r5.u64 = ctx.r5.u64 | 65262;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x8213590C;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_8213590C:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lwz r10,48(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r27)
	PPC_STORE_U32(r27.u32 + 48, r11.u32);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x82135a1c
	if (cr6.gt) goto loc_82135A1C;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// lbz r10,5(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82135950
	if (!cr0.eq) goto loc_82135950;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// b 0x82135964
	goto loc_82135964;
loc_82135950:
	// lbz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// stw r29,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, r29.u32);
loc_82135964:
	// lbz r9,5(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r11,r9,0,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x821359bc
	if (!cr6.lt) goto loc_821359BC;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821359f4
	if (!cr6.eq) goto loc_821359F4;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stwx r9,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r9.u32);
	// b 0x821359f4
	goto loc_821359F4;
loc_821359BC:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r9,r27,384
	ctx.r9.s64 = r27.s64 + 384;
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_821359C8:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x821359f4
	if (cr6.eq) goto loc_821359F4;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x821359f4
	if (!cr6.gt) goto loc_821359F4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x821359c8
	goto loc_821359C8;
loc_821359F4:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r29,8
	ctx.r10.s64 = r29.s64 + 8;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 48);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
loc_82135A14:
	// stw r11,48(r21)
	PPC_STORE_U32(r21.u32 + 48, r11.u32);
	// b 0x82135c28
	sub_82135C28(ctx, base);
	return;
loc_82135A1C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82133438
	ctx.lr = 0x82135A28;
	sub_82133438(ctx, base);
	// b 0x82135c28
	sub_82135C28(ctx, base);
	return;
loc_82135A2C:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82135a54
	if (!cr6.eq) goto loc_82135A54;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82133570
	ctx.lr = 0x82135A4C;
	sub_82133570(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82135c28
	if (!cr0.eq) {
		sub_82135C28(ctx, base);
		return;
	}
loc_82135A54:
	// rlwinm. r11,r23,0,27,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135a64
	if (cr0.eq) goto loc_82135A64;
	// stw r19,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r19.u32);
	// b 0x82135c30
	sub_82135C30(ctx, base);
	return;
loc_82135A64:
	// rlwinm r23,r23,0,14,1
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFC003FFFF;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135b2c
	if (cr0.eq) {
		sub_82135B2C(ctx, base);
		return;
	}
	// rlwinm r11,r23,0,23,19
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// lbz r9,5(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwimi r10,r9,4,20,22
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 4) & 0xE00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF1FF);
	// rlwinm. r9,r9,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// or r23,r10,r11
	r23.u64 = ctx.r10.u64 | r11.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
	// beq 0x82135aa8
	if (cr0.eq) goto loc_82135AA8;
	// addi r11,r30,-32
	r11.s64 = r30.s64 + -32;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// b 0x82135ab8
	goto loc_82135AB8;
loc_82135AA8:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
loc_82135AB8:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82135ae4
	if (cr0.eq) goto loc_82135AE4;
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82135ae4
	if (!cr0.eq) goto loc_82135AE4;
	// rlwinm r11,r11,18,0,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0xFFFC0000;
	// or r23,r11,r23
	r23.u64 = r11.u64 | r23.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135AE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135b44
	sub_82135B44(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135440"))) PPC_WEAK_FUNC(sub_82135440);
PPC_FUNC_IMPL(__imp__sub_82135440) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82135448;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r27.u32);
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// li r19,0
	r19.s64 = 0;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// rlwinm. r11,r11,0,13,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r19,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r19.u32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r20,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r20.u32);
	// mr r21,r27
	r21.u64 = r27.u64;
	// stw r26,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r26.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r21,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r21.u32);
	// beq 0x821354b0
	if (cr0.eq) goto loc_821354B0;
	// bl 0x827bcfc4
	ctx.lr = 0x8213548C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lbz r11,379(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 379);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x821354b0
	if (cr6.eq) goto loc_821354B0;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// li r6,3144
	ctx.r6.s64 = 3144;
	// lwz r5,312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,244
	ctx.r3.s64 = 244;
	// bl 0x827bcfb4
	ctx.lr = 0x821354B0;
	__imp__KeBugCheckEx(ctx, base);
loc_821354B0:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x821354c0
	if (!cr6.eq) goto loc_821354C0;
loc_821354B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82135c88
	goto loc_82135C88;
loc_821354C0:
	// lis r11,32767
	r11.s64 = 2147418112;
	// lwz r10,24(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// or r23,r10,r30
	r23.u64 = ctx.r10.u64 | r30.u64;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bgt cr6,0x821354b8
	if (cr6.gt) goto loc_821354B8;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// li r22,1
	r22.s64 = 1;
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x821354ec
	if (!cr6.eq) goto loc_821354EC;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_821354EC:
	// lwz r10,80(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// rlwinm r9,r23,0,2,23
	ctx.r9.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x3FFFFF00;
	// rlwinm. r9,r9,0,23,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFC0001FF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,84(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// and r24,r11,r8
	r24.u64 = r11.u64 & ctx.r8.u64;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
	// bne 0x82135524
	if (!cr0.eq) goto loc_82135524;
	// lwz r11,380(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82135524
	if (!cr6.eq) goto loc_82135524;
	// lbz r11,-11(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + -11);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8213552c
	if (cr0.eq) goto loc_8213552C;
loc_82135524:
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
loc_8213552C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// clrlwi. r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82135550
	if (!cr0.eq) goto loc_82135550;
	// lwz r3,1408(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 1408);
	// bl 0x827bcf64
	ctx.lr = 0x82135544;
	__imp__RtlEnterCriticalSection(ctx, base);
	// xori r23,r23,1
	r23.u64 = r23.u64 ^ 1;
	// stw r22,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r22.u32);
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135550:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r30,r20,-16
	r30.s64 = r20.s64 + -16;
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// lbz r7,5(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi. r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c5c
	if (cr0.eq) goto loc_82135C5C;
	// rlwinm. r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// beq 0x821355b8
	if (cr0.eq) goto loc_821355B8;
	// addi r9,r24,32
	ctx.r9.s64 = r24.s64 + 32;
	// lwz r8,-8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// addi r10,r30,-32
	ctx.r10.s64 = r30.s64 + -32;
	// addis r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 65536;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - r11.s64;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// rlwinm r24,r5,0,0,15
	r24.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFF0000;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// addi r25,r8,-48
	r25.s64 = ctx.r8.s64 + -48;
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
	// rlwinm r29,r4,28,4,31
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
	// b 0x821355c8
	goto loc_821355C8;
loc_821355B8:
	// lbz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// rotlwi r9,r11,4
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 4);
	// mr r29,r11
	r29.u64 = r11.u64;
	// subf r25,r10,r9
	r25.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_821355C8:
	// stw r25,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r25.u32);
	// rlwinm r28,r24,28,4,31
	r28.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 28) & 0xFFFFFFF;
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// bgt cr6,0x82135a2c
	if (cr6.gt) goto loc_82135A2C;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bne cr6,0x821355f8
	if (!cr6.eq) goto loc_821355F8;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// stw r24,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r24.u32);
loc_821355F8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82135614
	if (cr6.eq) goto loc_82135614;
	// subf r11,r26,r24
	r11.s64 = r24.s64 - r26.s64;
	// addis r11,r11,1
	r11.s64 = r11.s64 + 65536;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// b 0x82135654
	goto loc_82135654;
loc_82135614:
	// rlwinm. r10,r7,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213564c
	if (cr0.eq) goto loc_8213564C;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r28,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// add r11,r9,r30
	r11.u64 = ctx.r9.u64 + r30.u64;
	// subf r9,r26,r24
	ctx.r9.s64 = r24.s64 - r26.s64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// ld r8,-16(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + -16);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// ld r10,-8(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + -8);
	// std r10,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r10.u64);
	// stb r9,6(r30)
	PPC_STORE_U8(r30.u32 + 6, ctx.r9.u8);
	// b 0x82135654
	goto loc_82135654;
loc_8213564C:
	// subf r11,r26,r24
	r11.s64 = r24.s64 - r26.s64;
	// stb r11,6(r30)
	PPC_STORE_U8(r30.u32 + 6, r11.u8);
loc_82135654:
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// ble cr6,0x82135674
	if (!cr6.gt) goto loc_82135674;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135674
	if (cr0.eq) goto loc_82135674;
	// subf r5,r25,r26
	ctx.r5.s64 = r26.s64 - r25.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r25,r20
	ctx.r3.u64 = r25.u64 + r20.u64;
	// bl 0x823d9890
	ctx.lr = 0x82135674;
	sub_823D9890(ctx, base);
loc_82135674:
	// cmplw cr6,r28,r29
	cr6.compare<uint32_t>(r28.u32, r29.u32, xer);
	// beq cr6,0x82135c28
	if (cr6.eq) goto loc_82135C28;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x821356d8
	if (cr0.eq) goto loc_821356D8;
	// addi r30,r30,-32
	r30.s64 = r30.s64 + -32;
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r30,r24
	ctx.r10.u64 = r30.u64 + r24.u64;
	// subf r11,r24,r11
	r11.s64 = r11.s64 - r24.s64;
	// stw r10,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r10.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x827bcfd4
	ctx.lr = 0x821356BC;
	__imp__NtFreeVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82135c28
	if (cr0.lt) goto loc_82135C28;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// b 0x82135c28
	goto loc_82135C28;
loc_821356D8:
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r9,r28,16
	ctx.r9.u64 = r28.u32 & 0xFFFF;
	// add r29,r10,r30
	r29.u64 = ctx.r10.u64 + r30.u64;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// sth r9,2(r29)
	PPC_STORE_U16(r29.u32 + 2, ctx.r9.u16);
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// stb r11,4(r29)
	PPC_STORE_U8(r29.u32 + 4, r11.u8);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// subf r28,r28,r11
	r28.s64 = r11.s64 - r28.s64;
	// sth r9,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r9.u16);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// beq 0x8213578c
	if (cr0.eq) goto loc_8213578C;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// lwzx r9,r9,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// stw r29,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, r29.u32);
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x82135754
	if (!cr6.lt) goto loc_82135754;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// b 0x821357c8
	goto loc_821357C8;
loc_82135754:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r9,r27,384
	ctx.r9.s64 = r27.s64 + 384;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
loc_82135760:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x82135800
	if (cr6.eq) goto loc_82135800;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82135800
	if (!cr6.gt) goto loc_82135800;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135760
	goto loc_82135760;
loc_8213578C:
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213585c
	if (cr0.eq) goto loc_8213585C;
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// lbz r11,5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x82135824
	if (!cr6.lt) goto loc_82135824;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
loc_821357C8:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82135800
	if (!cr6.eq) goto loc_82135800;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwx r9,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r9.u32);
loc_82135800:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r29,8
	ctx.r10.s64 = r29.s64 + 8;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 48);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// b 0x82135a14
	goto loc_82135A14;
loc_82135824:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r10,r27,384
	ctx.r10.s64 = r27.s64 + 384;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
loc_82135830:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82135800
	if (cr6.eq) goto loc_82135800;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x82135800
	if (!cr6.gt) goto loc_82135800;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135830
	goto loc_82135830;
loc_8213585C:
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicr r7,r8,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// cmpld cr6,r8,r9
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r9.u64, xer);
	// bne cr6,0x821358c8
	if (!cr6.eq) goto loc_821358C8;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne cr6,0x821358c8
	if (!cr6.eq) goto loc_821358C8;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x821358c8
	if (!cr6.lt) goto loc_821358C8;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r22.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// stwx r10,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r10.u32);
loc_821358C8:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8213590c
	if (cr0.eq) goto loc_8213590C;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rotlwi r11,r10,4
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// stw r4,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r4.u32);
	// beq 0x821358fc
	if (cr0.eq) goto loc_821358FC;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// ble cr6,0x821358fc
	if (!cr6.gt) goto loc_821358FC;
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r4,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r4.u32);
loc_821358FC:
	// lis r5,-274
	ctx.r5.s64 = -17956864;
	// ori r5,r5,65262
	ctx.r5.u64 = ctx.r5.u64 | 65262;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// bl 0x827bcfe4
	ctx.lr = 0x8213590C;
	__imp__RtlCompareMemoryUlong(ctx, base);
loc_8213590C:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lwz r10,48(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// stw r11,48(r27)
	PPC_STORE_U32(r27.u32 + 48, r11.u32);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// cmplwi cr6,r5,61440
	cr6.compare<uint32_t>(ctx.r5.u32, 61440, xer);
	// bgt cr6,0x82135a1c
	if (cr6.gt) goto loc_82135A1C;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// lbz r10,5(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82135950
	if (!cr0.eq) goto loc_82135950;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// b 0x82135964
	goto loc_82135964;
loc_82135950:
	// lbz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// stw r29,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, r29.u32);
loc_82135964:
	// lbz r9,5(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r11,r9,0,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// stb r11,5(r29)
	PPC_STORE_U8(r29.u32 + 5, r11.u8);
	// bge cr6,0x821359bc
	if (!cr6.lt) goto loc_821359BC;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821359f4
	if (!cr6.eq) goto loc_821359F4;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// rlwinm r10,r9,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r9,27
	ctx.r9.u64 = ctx.r9.u32 & 0x1F;
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// slw r9,r22,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stwx r9,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r9.u32);
	// b 0x821359f4
	goto loc_821359F4;
loc_821359BC:
	// lwz r11,384(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// addi r9,r27,384
	ctx.r9.s64 = r27.s64 + 384;
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_821359C8:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x821359f4
	if (cr6.eq) goto loc_821359F4;
	// lhz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + -8);
	// addi r7,r11,-8
	ctx.r7.s64 = r11.s64 + -8;
	// stw r7,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r7.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x821359f4
	if (!cr6.gt) goto loc_821359F4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x821359c8
	goto loc_821359C8;
loc_821359F4:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r29,8
	ctx.r10.s64 = r29.s64 + 8;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,48(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 48);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
loc_82135A14:
	// stw r11,48(r21)
	PPC_STORE_U32(r21.u32 + 48, r11.u32);
	// b 0x82135c28
	goto loc_82135C28;
loc_82135A1C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82133438
	ctx.lr = 0x82135A28;
	sub_82133438(ctx, base);
	// b 0x82135c28
	goto loc_82135C28;
loc_82135A2C:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82135a54
	if (!cr6.eq) goto loc_82135A54;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82133570
	ctx.lr = 0x82135A4C;
	sub_82133570(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82135c28
	if (!cr0.eq) goto loc_82135C28;
loc_82135A54:
	// rlwinm. r11,r23,0,27,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135a64
	if (cr0.eq) goto loc_82135A64;
	// stw r19,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r19.u32);
	// b 0x82135c30
	goto loc_82135C30;
loc_82135A64:
	// rlwinm r23,r23,0,14,1
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFC003FFFF;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135b2c
	if (cr0.eq) goto loc_82135B2C;
	// rlwinm r11,r23,0,23,19
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// lbz r9,5(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwimi r10,r9,4,20,22
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 4) & 0xE00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF1FF);
	// rlwinm. r9,r9,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// or r23,r10,r11
	r23.u64 = ctx.r10.u64 | r11.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
	// beq 0x82135aa8
	if (cr0.eq) goto loc_82135AA8;
	// addi r11,r30,-32
	r11.s64 = r30.s64 + -32;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// b 0x82135ab8
	goto loc_82135AB8;
loc_82135AA8:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
loc_82135AB8:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82135ae4
	if (cr0.eq) goto loc_82135AE4;
	// rlwinm. r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82135ae4
	if (!cr0.eq) goto loc_82135AE4;
	// rlwinm r11,r11,18,0,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0xFFFC0000;
	// or r23,r11,r23
	r23.u64 = r11.u64 | r23.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135AE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135b44
	goto loc_82135B44;
	// lwz r30,124(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// andi. r11,r11,253
	r11.u64 = r11.u64 & 253;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// li r19,0
	r19.s64 = 0;
	// lwz r26,364(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// li r22,1
	r22.s64 = 1;
	// lwz r20,356(r31)
	r20.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// lwz r23,348(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lwz r27,340(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r21,84(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r24,80(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r25,92(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// b 0x82135b44
	goto loc_82135B44;
loc_82135B2C:
	// lbz r11,7(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 7);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82135b44
	if (cr0.eq) goto loc_82135B44;
	// rlwinm r11,r11,18,0,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0xFFFC0000;
	// or r23,r11,r23
	r23.u64 = r11.u64 | r23.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135B44:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r4,r23,0,29,27
	ctx.r4.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82134860
	ctx.lr = 0x82135B54;
	sub_82134860(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x82135c20
	if (cr0.eq) goto loc_82135C20;
	// lbz r10,-11(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + -11);
	// addi r11,r29,-16
	r11.s64 = r29.s64 + -16;
	// rlwinm. r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82135bd4
	if (cr0.eq) goto loc_82135BD4;
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82135b80
	if (cr0.eq) goto loc_82135B80;
	// addi r11,r11,-32
	r11.s64 = r11.s64 + -32;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// b 0x82135b90
	goto loc_82135B90;
loc_82135B80:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
loc_82135B90:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82135bcc
	if (cr0.eq) goto loc_82135BCC;
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135bb0
	if (cr0.eq) goto loc_82135BB0;
	// addi r11,r30,-32
	r11.s64 = r30.s64 + -32;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// b 0x82135bc0
	goto loc_82135BC0;
loc_82135BB0:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
loc_82135BC0:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x82135bd4
	goto loc_82135BD4;
loc_82135BCC:
	// std r19,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r19.u64);
	// std r19,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r19.u64);
loc_82135BD4:
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// blt cr6,0x82135be4
	if (cr6.lt) goto loc_82135BE4;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_82135BE4:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db5b0
	ctx.lr = 0x82135BF0;
	sub_823DB5B0(ctx, base);
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// ble cr6,0x82135c10
	if (!cr6.gt) goto loc_82135C10;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c10
	if (cr0.eq) goto loc_82135C10;
	// subf r5,r25,r26
	ctx.r5.s64 = r26.s64 - r25.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r29,r25
	ctx.r3.u64 = r29.u64 + r25.u64;
	// bl 0x823d9890
	ctx.lr = 0x82135C10;
	sub_823D9890(ctx, base);
loc_82135C10:
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82135150
	ctx.lr = 0x82135C20;
	sub_82135150(ctx, base);
loc_82135C20:
	// mr r20,r29
	r20.u64 = r29.u64;
	// stw r20,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r20.u32);
loc_82135C28:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82135c5c
	if (!cr6.eq) goto loc_82135C5C;
loc_82135C30:
	// rlwinm. r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c5c
	if (cr0.eq) goto loc_82135C5C;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// stw r19,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r19.u32);
	// stw r22,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r22.u32);
	// stw r19,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r19.u32);
	// stw r24,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r24.u32);
	// bl 0x827bd014
	ctx.lr = 0x82135C5C;
	__imp__RtlRaiseException(ctx, base);
loc_82135C5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135c78
	goto loc_82135C78;
	// li r11,0
	r11.s64 = 0;
	// stw r11,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r11.u32);
	// lwz r21,84(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 84);
loc_82135C78:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,320
	r12.s64 = r31.s64 + 320;
	// bl 0x82135cb0
	ctx.lr = 0x82135C84;
	sub_82135CB0(ctx, base);
	// lwz r3,356(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 356);
loc_82135C88:
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82135AF4"))) PPC_WEAK_FUNC(sub_82135AF4);
PPC_FUNC_IMPL(__imp__sub_82135AF4) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r30{};
	PPCRegister r31{};
	// lwz r30,124(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// andi. r11,r11,253
	r11.u64 = r11.u64 & 253;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,5(r30)
	PPC_STORE_U8(r30.u32 + 5, r11.u8);
	// li r19,0
	r19.s64 = 0;
	// lwz r26,364(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// li r22,1
	r22.s64 = 1;
	// lwz r20,356(r31)
	r20.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// lwz r23,348(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lwz r27,340(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r21,84(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r24,80(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r25,92(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// b 0x82135b44
	sub_82135B44(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135B2C"))) PPC_WEAK_FUNC(sub_82135B2C);
PPC_FUNC_IMPL(__imp__sub_82135B2C) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// lbz r11,7(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 7);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82135b44
	if (cr0.eq) goto loc_82135B44;
	// rlwinm r11,r11,18,0,13
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0xFFFC0000;
	// or r23,r11,r23
	r23.u64 = r11.u64 | r23.u64;
	// stw r23,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r23.u32);
loc_82135B44:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r4,r23,0,29,27
	ctx.r4.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82134860
	ctx.lr = 0x82135B54;
	sub_82134860(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x82135c20
	if (cr0.eq) goto loc_82135C20;
	// lbz r10,-11(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + -11);
	// addi r11,r29,-16
	r11.s64 = r29.s64 + -16;
	// rlwinm. r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82135bd4
	if (cr0.eq) goto loc_82135BD4;
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82135b80
	if (cr0.eq) goto loc_82135B80;
	// addi r11,r11,-32
	r11.s64 = r11.s64 + -32;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// b 0x82135b90
	goto loc_82135B90;
loc_82135B80:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
loc_82135B90:
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// rlwinm. r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82135bcc
	if (cr0.eq) goto loc_82135BCC;
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135bb0
	if (cr0.eq) goto loc_82135BB0;
	// addi r11,r30,-32
	r11.s64 = r30.s64 + -32;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// b 0x82135bc0
	goto loc_82135BC0;
loc_82135BB0:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
loc_82135BC0:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x82135bd4
	goto loc_82135BD4;
loc_82135BCC:
	// std r19,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r19.u64);
	// std r19,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r19.u64);
loc_82135BD4:
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// blt cr6,0x82135be4
	if (cr6.lt) goto loc_82135BE4;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_82135BE4:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db5b0
	ctx.lr = 0x82135BF0;
	sub_823DB5B0(ctx, base);
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// ble cr6,0x82135c10
	if (!cr6.gt) goto loc_82135C10;
	// rlwinm. r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c10
	if (cr0.eq) goto loc_82135C10;
	// subf r5,r25,r26
	ctx.r5.s64 = r26.s64 - r25.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r29,r25
	ctx.r3.u64 = r29.u64 + r25.u64;
	// bl 0x823d9890
	ctx.lr = 0x82135C10;
	sub_823D9890(ctx, base);
loc_82135C10:
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82135150
	ctx.lr = 0x82135C20;
	sub_82135150(ctx, base);
loc_82135C20:
	// mr r20,r29
	r20.u64 = r29.u64;
	// stw r20,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r20.u32);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82135c5c
	if (!cr6.eq) goto loc_82135C5C;
	// rlwinm. r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c5c
	if (cr0.eq) goto loc_82135C5C;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// stw r19,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r19.u32);
	// stw r22,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r22.u32);
	// stw r19,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r19.u32);
	// stw r24,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r24.u32);
	// bl 0x827bd014
	ctx.lr = 0x82135C5C;
	__imp__RtlRaiseException(ctx, base);
loc_82135C5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82135c78
	sub_82135C78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135B44"))) PPC_WEAK_FUNC(sub_82135B44);
PPC_FUNC_IMPL(__imp__sub_82135B44) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r23{};
	PPCRegister r26{};
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r4,r23,0,29,27
	ctx.r4.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
}

__attribute__((alias("__imp__sub_82135C28"))) PPC_WEAK_FUNC(sub_82135C28);
PPC_FUNC_IMPL(__imp__sub_82135C28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r20{};
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82135c5c
	if (!cr6.eq) {
		sub_82135C5C(ctx, base);
		return;
	}
}

__attribute__((alias("__imp__sub_82135C30"))) PPC_WEAK_FUNC(sub_82135C30);
PPC_FUNC_IMPL(__imp__sub_82135C30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r23{};
	// rlwinm. r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82135c5c
	if (cr0.eq) {
		sub_82135C5C(ctx, base);
		return;
	}
}

__attribute__((alias("__imp__sub_82135C5C"))) PPC_WEAK_FUNC(sub_82135C5C);
PPC_FUNC_IMPL(__imp__sub_82135C5C) {
	PPC_FUNC_PROLOGUE();
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
}

__attribute__((alias("__imp__sub_82135C6C"))) PPC_WEAK_FUNC(sub_82135C6C);
PPC_FUNC_IMPL(__imp__sub_82135C6C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r21{};
	PPCRegister r31{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r11.u32);
	// lwz r21,84(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,320
	r12.s64 = r31.s64 + 320;
	// bl 0x82135cb0
	ctx.lr = 0x82135C84;
	sub_82135CB0(ctx, base);
	// lwz r3,356(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82135C78"))) PPC_WEAK_FUNC(sub_82135C78);
PPC_FUNC_IMPL(__imp__sub_82135C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,320
	r12.s64 = r31.s64 + 320;
}

__attribute__((alias("__imp__sub_82135C88"))) PPC_WEAK_FUNC(sub_82135C88);
PPC_FUNC_IMPL(__imp__sub_82135C88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r31{};
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82135C90"))) PPC_WEAK_FUNC(sub_82135C90);
PPC_FUNC_IMPL(__imp__sub_82135C90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r21{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r21,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r21.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r21,84(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// b 0x82135cc8
	goto loc_82135CC8;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r21,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r21.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82135CC8:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82135cdc
	if (cr6.eq) goto loc_82135CDC;
	// lwz r3,1408(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135CDC;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82135CDC:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r21,-16(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135CB0"))) PPC_WEAK_FUNC(sub_82135CB0);
PPC_FUNC_IMPL(__imp__sub_82135CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r21{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-320
	r31.s64 = r12.s64 + -320;
	// std r21,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r21.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82135cdc
	if (cr6.eq) goto loc_82135CDC;
	// lwz r3,1408(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 1408);
	// bl 0x827bcf54
	ctx.lr = 0x82135CDC;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82135CDC:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r21,-16(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135CF4"))) PPC_WEAK_FUNC(sub_82135CF4);
PPC_FUNC_IMPL(__imp__sub_82135CF4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135D1C"))) PPC_WEAK_FUNC(sub_82135D1C);
PPC_FUNC_IMPL(__imp__sub_82135D1C) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135D28"))) PPC_WEAK_FUNC(sub_82135D28);
PPC_FUNC_IMPL(__imp__sub_82135D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r3,-23136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135D34"))) PPC_WEAK_FUNC(sub_82135D34);
PPC_FUNC_IMPL(__imp__sub_82135D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135D38"))) PPC_WEAK_FUNC(sub_82135D38);
PPC_FUNC_IMPL(__imp__sub_82135D38) {
	PPC_FUNC_PROLOGUE();
	// b 0x82135d40
	sub_82135D40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135D3C"))) PPC_WEAK_FUNC(sub_82135D3C);
PPC_FUNC_IMPL(__imp__sub_82135D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135D40"))) PPC_WEAK_FUNC(sub_82135D40);
PPC_FUNC_IMPL(__imp__sub_82135D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,336(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// stw r3,352(r11)
	PPC_STORE_U32(r11.u32 + 352, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135D58"))) PPC_WEAK_FUNC(sub_82135D58);
PPC_FUNC_IMPL(__imp__sub_82135D58) {
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
	// bl 0x827bd024
	ctx.lr = 0x82135D68;
	__imp__RtlNtStatusToDosError(ctx, base);
	// lwz r11,336(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82135d7c
	if (!cr6.eq) goto loc_82135D7C;
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// stw r3,352(r11)
	PPC_STORE_U32(r11.u32 + 352, ctx.r3.u32);
loc_82135D7C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135D8C"))) PPC_WEAK_FUNC(sub_82135D8C);
PPC_FUNC_IMPL(__imp__sub_82135D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135D90"))) PPC_WEAK_FUNC(sub_82135D90);
PPC_FUNC_IMPL(__imp__sub_82135D90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,336(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82135da8
	if (!cr6.eq) goto loc_82135DA8;
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r3,352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 352);
	// blr 
	return;
loc_82135DA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135DB0"))) PPC_WEAK_FUNC(sub_82135DB0);
PPC_FUNC_IMPL(__imp__sub_82135DB0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82135d90
	sub_82135D90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135DB4"))) PPC_WEAK_FUNC(sub_82135DB4);
PPC_FUNC_IMPL(__imp__sub_82135DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135DB8"))) PPC_WEAK_FUNC(sub_82135DB8);
PPC_FUNC_IMPL(__imp__sub_82135DB8) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82135dc0
	sub_82135DC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135DC0"))) PPC_WEAK_FUNC(sub_82135DC0);
PPC_FUNC_IMPL(__imp__sub_82135DC0) {
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
	ctx.lr = 0x82135DC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82135e28
	ctx.lr = 0x82135DDC;
	sub_82135E28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
loc_82135DE4:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd034
	ctx.lr = 0x82135DF8;
	__imp__NtWaitForSingleObjectEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82135e14
	if (cr0.lt) goto loc_82135E14;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82135e1c
	if (cr6.eq) goto loc_82135E1C;
	// cmpwi cr6,r3,257
	cr6.compare<int32_t>(ctx.r3.s32, 257, xer);
	// beq cr6,0x82135de4
	if (cr6.eq) goto loc_82135DE4;
	// b 0x82135e1c
	goto loc_82135E1C;
loc_82135E14:
	// bl 0x82135d58
	ctx.lr = 0x82135E18;
	sub_82135D58(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82135E1C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82135E24"))) PPC_WEAK_FUNC(sub_82135E24);
PPC_FUNC_IMPL(__imp__sub_82135E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135E28"))) PPC_WEAK_FUNC(sub_82135E28);
PPC_FUNC_IMPL(__imp__sub_82135E28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82135e38
	if (!cr6.eq) goto loc_82135E38;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82135E38:
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// mulli r11,r11,-10000
	r11.s64 = r11.s64 * -10000;
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135E48"))) PPC_WEAK_FUNC(sub_82135E48);
PPC_FUNC_IMPL(__imp__sub_82135E48) {
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
	ctx.lr = 0x82135E50;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r30,5616(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5616, r30.u32);
	// stw r29,5620(r9)
	PPC_STORE_U32(ctx.r9.u32 + 5620, r29.u32);
	// subf r10,r11,r8
	ctx.r10.s64 = ctx.r8.s64 - r11.s64;
loc_82135E78:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82135e78
	if (!cr6.eq) goto loc_82135E78;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,5600(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5600);
loc_82135E98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82135e98
	if (!cr6.eq) goto loc_82135E98;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82135EAC:
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
	// bne cr6,0x82135eac
	if (!cr6.eq) goto loc_82135EAC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r31,r11,5608
	r31.s64 = r11.s64 + 5608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213adc8
	ctx.lr = 0x82135ED8;
	sub_8213ADC8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,5676
	ctx.r3.s64 = r11.s64 + 5676;
	// bl 0x821c0750
	ctx.lr = 0x82135EE8;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// bne cr6,0x82135f00
	if (!cr6.eq) goto loc_82135F00;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
loc_82135F00:
	// stw r11,5604(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5604, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ab78
	ctx.lr = 0x82135F10;
	sub_8213AB78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82135f38
	if (cr6.eq) goto loc_82135F38;
	// bl 0x82139be0
	ctx.lr = 0x82135F24;
	sub_82139BE0(ctx, base);
	// bl 0x82138aa0
	ctx.lr = 0x82135F28;
	sub_82138AA0(ctx, base);
	// bl 0x82137198
	ctx.lr = 0x82135F2C;
	sub_82137198(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x821365f8
	ctx.lr = 0x82135F38;
	sub_821365F8(ctx, base);
loc_82135F38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82135F44"))) PPC_WEAK_FUNC(sub_82135F44);
PPC_FUNC_IMPL(__imp__sub_82135F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135F48"))) PPC_WEAK_FUNC(sub_82135F48);
PPC_FUNC_IMPL(__imp__sub_82135F48) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82136450
	ctx.lr = 0x82135F60;
	sub_82136450(ctx, base);
	// bl 0x821398a8
	ctx.lr = 0x82135F64;
	sub_821398A8(ctx, base);
	// bl 0x82139318
	ctx.lr = 0x82135F68;
	sub_82139318(ctx, base);
	// bl 0x82137200
	ctx.lr = 0x82135F6C;
	sub_82137200(ctx, base);
	// bl 0x8213a010
	ctx.lr = 0x82135F70;
	sub_8213A010(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135F80"))) PPC_WEAK_FUNC(sub_82135F80);
PPC_FUNC_IMPL(__imp__sub_82135F80) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82136e10
	ctx.lr = 0x82135F9C;
	sub_82136E10(ctx, base);
	// bl 0x82139710
	ctx.lr = 0x82135FA0;
	sub_82139710(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135FB0"))) PPC_WEAK_FUNC(sub_82135FB0);
PPC_FUNC_IMPL(__imp__sub_82135FB0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a178
	sub_8213A178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FB4"))) PPC_WEAK_FUNC(sub_82135FB4);
PPC_FUNC_IMPL(__imp__sub_82135FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FB8"))) PPC_WEAK_FUNC(sub_82135FB8);
PPC_FUNC_IMPL(__imp__sub_82135FB8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a4b0
	sub_8213A4B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FBC"))) PPC_WEAK_FUNC(sub_82135FBC);
PPC_FUNC_IMPL(__imp__sub_82135FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FC0"))) PPC_WEAK_FUNC(sub_82135FC0);
PPC_FUNC_IMPL(__imp__sub_82135FC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8213a4c8
	sub_8213A4C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FCC"))) PPC_WEAK_FUNC(sub_82135FCC);
PPC_FUNC_IMPL(__imp__sub_82135FCC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135FD0"))) PPC_WEAK_FUNC(sub_82135FD0);
PPC_FUNC_IMPL(__imp__sub_82135FD0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a7b8
	sub_8213A7B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FD4"))) PPC_WEAK_FUNC(sub_82135FD4);
PPC_FUNC_IMPL(__imp__sub_82135FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FD8"))) PPC_WEAK_FUNC(sub_82135FD8);
PPC_FUNC_IMPL(__imp__sub_82135FD8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a828
	sub_8213A828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FDC"))) PPC_WEAK_FUNC(sub_82135FDC);
PPC_FUNC_IMPL(__imp__sub_82135FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FE0"))) PPC_WEAK_FUNC(sub_82135FE0);
PPC_FUNC_IMPL(__imp__sub_82135FE0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a8c8
	sub_8213A8C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FE4"))) PPC_WEAK_FUNC(sub_82135FE4);
PPC_FUNC_IMPL(__imp__sub_82135FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FE8"))) PPC_WEAK_FUNC(sub_82135FE8);
PPC_FUNC_IMPL(__imp__sub_82135FE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a980
	sub_8213A980(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FEC"))) PPC_WEAK_FUNC(sub_82135FEC);
PPC_FUNC_IMPL(__imp__sub_82135FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FF0"))) PPC_WEAK_FUNC(sub_82135FF0);
PPC_FUNC_IMPL(__imp__sub_82135FF0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213a9f0
	sub_8213A9F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FF4"))) PPC_WEAK_FUNC(sub_82135FF4);
PPC_FUNC_IMPL(__imp__sub_82135FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FF8"))) PPC_WEAK_FUNC(sub_82135FF8);
PPC_FUNC_IMPL(__imp__sub_82135FF8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213aa90
	sub_8213AA90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135FFC"))) PPC_WEAK_FUNC(sub_82135FFC);
PPC_FUNC_IMPL(__imp__sub_82135FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136000"))) PPC_WEAK_FUNC(sub_82136000);
PPC_FUNC_IMPL(__imp__sub_82136000) {
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
	// bl 0x8213a7b0
	ctx.lr = 0x82136010;
	sub_8213A7B0(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r11,5612(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5612);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,5612(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5612, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82136030"))) PPC_WEAK_FUNC(sub_82136030);
PPC_FUNC_IMPL(__imp__sub_82136030) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82136054;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136094
	if (cr6.eq) goto loc_82136094;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// bl 0x821c7490
	ctx.lr = 0x82136068;
	sub_821C7490(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823db670
	ctx.lr = 0x8213607C;
	sub_823DB670(ctx, base);
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
loc_82136094:
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

__attribute__((alias("__imp__sub_821360AC"))) PPC_WEAK_FUNC(sub_821360AC);
PPC_FUNC_IMPL(__imp__sub_821360AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821360B0"))) PPC_WEAK_FUNC(sub_821360B0);
PPC_FUNC_IMPL(__imp__sub_821360B0) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x821c82a8
	ctx.lr = 0x821360D4;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136108
	if (cr6.eq) goto loc_82136108;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// bl 0x821c7490
	ctx.lr = 0x821360E8;
	sub_821C7490(ctx, base);
	// bl 0x821c60f8
	ctx.lr = 0x821360EC;
	sub_821C60F8(ctx, base);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
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
loc_82136108:
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

__attribute__((alias("__imp__sub_82136120"))) PPC_WEAK_FUNC(sub_82136120);
PPC_FUNC_IMPL(__imp__sub_82136120) {
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
	ctx.lr = 0x82136128;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82136144;
	sub_821C82A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821361a4
	if (cr6.eq) goto loc_821361A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r11,7760
	ctx.r5.s64 = r11.s64 + 7760;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821360b0
	ctx.lr = 0x82136168;
	sub_821360B0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r6,r29,4
	ctx.r6.s64 = r29.s64 + 4;
	// addi r5,r10,7756
	ctx.r5.s64 = ctx.r10.s64 + 7756;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821360b0
	ctx.lr = 0x82136180;
	sub_821360B0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r6,r29,8
	ctx.r6.s64 = r29.s64 + 8;
	// addi r5,r9,7752
	ctx.r5.s64 = ctx.r9.s64 + 7752;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821360b0
	ctx.lr = 0x82136198;
	sub_821360B0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821361A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821361B0"))) PPC_WEAK_FUNC(sub_821361B0);
PPC_FUNC_IMPL(__imp__sub_821361B0) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821c82a8
	ctx.lr = 0x821361D0;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136208
	if (cr6.eq) goto loc_82136208;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// bl 0x821c7490
	ctx.lr = 0x821361E4;
	sub_821C7490(ctx, base);
	// bl 0x821c6090
	ctx.lr = 0x821361E8;
	sub_821C6090(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82136208:
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

__attribute__((alias("__imp__sub_82136220"))) PPC_WEAK_FUNC(sub_82136220);
PPC_FUNC_IMPL(__imp__sub_82136220) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821c82a8
	ctx.lr = 0x82136240;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136274
	if (cr6.eq) goto loc_82136274;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// bl 0x821c7490
	ctx.lr = 0x82136254;
	sub_821C7490(ctx, base);
	// bl 0x821c60f8
	ctx.lr = 0x82136258;
	sub_821C60F8(ctx, base);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
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
loc_82136274:
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

__attribute__((alias("__imp__sub_8213628C"))) PPC_WEAK_FUNC(sub_8213628C);
PPC_FUNC_IMPL(__imp__sub_8213628C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136290"))) PPC_WEAK_FUNC(sub_82136290);
PPC_FUNC_IMPL(__imp__sub_82136290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// b 0x82136120
	sub_82136120(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821362A4"))) PPC_WEAK_FUNC(sub_821362A4);
PPC_FUNC_IMPL(__imp__sub_821362A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821362A8"))) PPC_WEAK_FUNC(sub_821362A8);
PPC_FUNC_IMPL(__imp__sub_821362A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// b 0x82136030
	sub_82136030(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821362BC"))) PPC_WEAK_FUNC(sub_821362BC);
PPC_FUNC_IMPL(__imp__sub_821362BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821362C0"))) PPC_WEAK_FUNC(sub_821362C0);
PPC_FUNC_IMPL(__imp__sub_821362C0) {
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
	ctx.lr = 0x821362C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821362f4
	if (cr6.eq) goto loc_821362F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c5c70
	ctx.lr = 0x821362E8;
	sub_821C5C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821362F0;
	sub_82130588(ctx, base);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
loc_821362F4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82136304
	if (cr6.eq) goto loc_82136304;
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_82136304:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82136350
	if (cr6.eq) goto loc_82136350;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x8213631C;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213634c
	if (cr6.eq) goto loc_8213634C;
	// lwz r29,2828(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82136344
	if (cr6.eq) goto loc_82136344;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c0688
	ctx.lr = 0x8213633C;
	sub_821C0688(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82136344;
	sub_82130588(ctx, base);
loc_82136344:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_8213634C:
	// stb r28,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r28.u8);
loc_82136350:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82136358"))) PPC_WEAK_FUNC(sub_82136358);
PPC_FUNC_IMPL(__imp__sub_82136358) {
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
	ctx.lr = 0x82136360;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821363a4
	if (!cr6.eq) goto loc_821363A4;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x82136384;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8213639c
	if (cr6.eq) goto loc_8213639C;
	// bl 0x821c0580
	ctx.lr = 0x82136394;
	sub_821C0580(ctx, base);
	// stw r28,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r28.u32);
	// b 0x821363a4
	goto loc_821363A4;
loc_8213639C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_821363A4:
	// bl 0x821c4210
	ctx.lr = 0x821363A8;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x821363CC;
	sub_821C05E8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r9,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r9.u8);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r8,3998
	ctx.r5.s64 = ctx.r8.s64 + 3998;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821c0210
	ctx.lr = 0x821363E8;
	sub_821C0210(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136440
	if (cr6.eq) goto loc_82136440;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// beq cr6,0x82136440
	if (cr6.eq) goto loc_82136440;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,7764
	ctx.r10.s64 = ctx.r10.s64 + 7764;
loc_82136410:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82136434
	if (cr6.eq) goto loc_82136434;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82136410
	if (cr6.eq) goto loc_82136410;
loc_82136434:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x82136444
	if (cr6.eq) goto loc_82136444;
loc_82136440:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82136444:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8213644C"))) PPC_WEAK_FUNC(sub_8213644C);
PPC_FUNC_IMPL(__imp__sub_8213644C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136450"))) PPC_WEAK_FUNC(sub_82136450);
PPC_FUNC_IMPL(__imp__sub_82136450) {
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
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82135fd8
	ctx.lr = 0x82136464;
	sub_82135FD8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,5708(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 5708);
	// bl 0x82135fd8
	ctx.lr = 0x82136470;
	sub_82135FD8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82136480"))) PPC_WEAK_FUNC(sub_82136480);
PPC_FUNC_IMPL(__imp__sub_82136480) {
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
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821364ac
	if (cr6.lt) goto loc_821364AC;
	// beq cr6,0x821364d8
	if (cr6.eq) goto loc_821364D8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x821364c4
	if (!cr6.eq) goto loc_821364C4;
loc_821364AC:
	// bl 0x8240f000
	ctx.lr = 0x821364B0;
	sub_8240F000(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
loc_821364C4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821364D8:
	// li r11,2
	r11.s64 = 2;
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

__attribute__((alias("__imp__sub_821364F4"))) PPC_WEAK_FUNC(sub_821364F4);
PPC_FUNC_IMPL(__imp__sub_821364F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821364F8"))) PPC_WEAK_FUNC(sub_821364F8);
PPC_FUNC_IMPL(__imp__sub_821364F8) {
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
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82136558
	if (!cr6.gt) goto loc_82136558;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x82136544
	if (!cr6.gt) goto loc_82136544;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82136558
	if (!cr6.eq) goto loc_82136558;
	// li r11,0
	r11.s64 = 0;
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
loc_82136544:
	// bl 0x8240f0d8
	ctx.lr = 0x82136548;
	sub_8240F0D8(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
loc_82136558:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8213656C"))) PPC_WEAK_FUNC(sub_8213656C);
PPC_FUNC_IMPL(__imp__sub_8213656C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136570"))) PPC_WEAK_FUNC(sub_82136570);
PPC_FUNC_IMPL(__imp__sub_82136570) {
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
	// bl 0x8240efe0
	ctx.lr = 0x8213658C;
	sub_8240EFE0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,40(r31)
	PPC_STORE_U8(r31.u32 + 40, ctx.r8.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// beq cr6,0x821365d0
	if (cr6.eq) goto loc_821365D0;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x821365e0
	if (!cr6.eq) goto loc_821365E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82136480
	ctx.lr = 0x821365BC;
	sub_82136480(ctx, base);
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
loc_821365D0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821365e0
	if (!cr6.eq) goto loc_821365E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821364f8
	ctx.lr = 0x821365E0;
	sub_821364F8(ctx, base);
loc_821365E0:
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

__attribute__((alias("__imp__sub_821365F4"))) PPC_WEAK_FUNC(sub_821365F4);
PPC_FUNC_IMPL(__imp__sub_821365F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821365F8"))) PPC_WEAK_FUNC(sub_821365F8);
PPC_FUNC_IMPL(__imp__sub_821365F8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r31,0
	r31.s64 = 0;
	// addi r8,r11,5608
	ctx.r8.s64 = r11.s64 + 5608;
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
	// lwz r11,5608(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5608);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r10,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r10.u32);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
	// rlwinm r3,r7,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82135fd0
	ctx.lr = 0x82136650;
	sub_82135FD0(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r5,r11,8
	ctx.r5.s64 = r11.s64 + 8;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	// stw r31,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r31.u32);
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// bl 0x82135fd0
	ctx.lr = 0x82136678;
	sub_82135FD0(ctx, base);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r3,5708(r9)
	PPC_STORE_U32(ctx.r9.u32 + 5708, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,5704(r8)
	PPC_STORE_U32(ctx.r8.u32 + 5704, r11.u32);
	// stw r10,5696(r7)
	PPC_STORE_U32(ctx.r7.u32 + 5696, ctx.r10.u32);
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,5700(r6)
	PPC_STORE_U32(ctx.r6.u32 + 5700, r11.u32);
	// stw r31,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r31.u32);
	// bl 0x821364f8
	ctx.lr = 0x821366B8;
	sub_821364F8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82136570
	ctx.lr = 0x821366C0;
	sub_82136570(ctx, base);
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

__attribute__((alias("__imp__sub_821366D8"))) PPC_WEAK_FUNC(sub_821366D8);
PPC_FUNC_IMPL(__imp__sub_821366D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge cr6,0x821366f4
	if (!cr6.lt) goto loc_821366F4;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// blr 
	return;
loc_821366F4:
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821366FC"))) PPC_WEAK_FUNC(sub_821366FC);
PPC_FUNC_IMPL(__imp__sub_821366FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136700"))) PPC_WEAK_FUNC(sub_82136700);
PPC_FUNC_IMPL(__imp__sub_82136700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82136708;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r21,-32125
	r21.s64 = -2105344000;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// li r20,0
	r20.s64 = 0;
	// lwz r11,5752(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 5752);
	// lbz r10,6049(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 6049);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r19,40(r11)
	r19.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// beq cr6,0x82136744
	if (cr6.eq) goto loc_82136744;
loc_82136730:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c91b8
	ctx.lr = 0x82136738;
	sub_821C91B8(ctx, base);
	// lbz r11,6049(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6049);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82136730
	if (!cr6.eq) goto loc_82136730;
loc_82136744:
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82136a4c
	if (cr6.eq) goto loc_82136A4C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r23,0
	r23.s64 = 0;
	// lis r25,-32768
	r25.s64 = -2147483648;
	// li r24,255
	r24.s64 = 255;
	// addi r26,r11,7216
	r26.s64 = r11.s64 + 7216;
loc_82136764:
	// lwz r11,5752(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 5752);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbzx r9,r10,r22
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r22.u32);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82136a3c
	if (!cr6.eq) goto loc_82136A3C;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add. r31,r23,r11
	r31.u64 = r23.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82136a3c
	if (cr0.eq) goto loc_82136A3C;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r28,72(r30)
	r28.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213f158
	ctx.lr = 0x821367A4;
	sub_8213F158(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mulli r10,r28,359
	ctx.r10.s64 = r28.s64 * 359;
	// lwz r11,232(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 232);
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + r27.u64;
	// addi r10,r10,243
	ctx.r10.s64 = ctx.r10.s64 + 243;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r8,r9,0,0,1
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r8,r25
	cr6.compare<uint32_t>(ctx.r8.u32, r25.u32, xer);
	// bne cr6,0x82136844
	if (!cr6.eq) goto loc_82136844;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821367E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82136844
	if (!cr6.eq) goto loc_82136844;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r24,71(r11)
	PPC_STORE_U8(r11.u32 + 71, r24.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8213680C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82136824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// clrlwi r5,r6,2
	ctx.r5.u64 = ctx.r6.u32 & 0x3FFFFFFF;
	// stw r5,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r5.u32);
	// lbz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r3,r4,0,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136a3c
	if (cr6.eq) goto loc_82136A3C;
	// b 0x82136a2c
	goto loc_82136A2C;
loc_82136844:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82136898
	if (cr6.eq) goto loc_82136898;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82136870
	if (cr6.eq) goto loc_82136870;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// srawi r4,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r4.s64 = r11.s32 >> 3;
	// b 0x82136874
	goto loc_82136874;
loc_82136870:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82136874:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82136888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r8,r9,0,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFE;
	// rlwinm r8,r8,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r8,24(r30)
	PPC_STORE_U8(r30.u32 + 24, ctx.r8.u8);
loc_82136898:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821368fc
	if (cr6.eq) goto loc_821368FC;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821368c8
	if (cr6.eq) goto loc_821368C8;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821368fc
	if (cr6.eq) goto loc_821368FC;
loc_821368C8:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// srawi r4,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r4.s64 = r11.s32 >> 3;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x821368ec
	if (cr6.eq) goto loc_821368EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821368EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821368EC:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r10,24(r30)
	PPC_STORE_U8(r30.u32 + 24, ctx.r10.u8);
loc_821368FC:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82136930
	if (cr6.eq) goto loc_82136930;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r10,24(r30)
	PPC_STORE_U8(r30.u32 + 24, ctx.r10.u8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82136930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82136930:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82136944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r11,r9,2,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8213695c
	if (cr6.eq) goto loc_8213695C;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8213699c
	if (!cr6.eq) goto loc_8213699C;
loc_8213695C:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213697c
	if (cr6.eq) goto loc_8213697C;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213699c
	if (cr6.eq) goto loc_8213699C;
loc_8213697C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82136990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwimi r9,r3,3,0,28
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 3) & 0xFFFFFFF8) | (ctx.r9.u64 & 0xFFFFFFFF00000007);
	// stw r9,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r9.u32);
loc_8213699C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821369B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// rlwimi r9,r3,7,17,24
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 7) & 0x7F80) | (ctx.r9.u64 & 0xFFFFFFFFFFFF807F);
	// stb r9,12(r29)
	PPC_STORE_U8(r29.u32 + 12, ctx.r9.u8);
	// lbz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// rlwinm r6,r7,0,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82136a3c
	if (cr6.eq) goto loc_82136A3C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821369E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82136a3c
	if (!cr6.eq) goto loc_82136A3C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r24,71(r11)
	PPC_STORE_U8(r11.u32 + 71, r24.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82136A08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82136A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// clrlwi r11,r6,2
	r11.u64 = ctx.r6.u32 & 0x3FFFFFFF;
	// stw r11,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r11.u32);
loc_82136A2C:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8213ece0
	ctx.lr = 0x82136A3C;
	sub_8213ECE0(ctx, base);
loc_82136A3C:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r23,r23,768
	r23.s64 = r23.s64 + 768;
	// cmplw cr6,r22,r19
	cr6.compare<uint32_t>(r22.u32, r19.u32, xer);
	// blt cr6,0x82136764
	if (cr6.lt) goto loc_82136764;
loc_82136A4C:
	// stw r20,16(r18)
	PPC_STORE_U32(r18.u32 + 16, r20.u32);
	// bl 0x82136000
	ctx.lr = 0x82136A54;
	sub_82136000(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82136A5C"))) PPC_WEAK_FUNC(sub_82136A5C);
PPC_FUNC_IMPL(__imp__sub_82136A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136A60"))) PPC_WEAK_FUNC(sub_82136A60);
PPC_FUNC_IMPL(__imp__sub_82136A60) {
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
	ctx.lr = 0x82136A68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// rlwinm r10,r4,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82136ab4
	if (cr6.eq) goto loc_82136AB4;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r31,r11,96
	r31.s64 = r11.s64 + 96;
	// b 0x82136ab8
	goto loc_82136AB8;
loc_82136AB4:
	// li r31,0
	r31.s64 = 0;
loc_82136AB8:
	// lbz r29,72(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213f158
	ctx.lr = 0x82136ACC;
	sub_8213F158(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// mulli r8,r29,359
	ctx.r8.s64 = r29.s64 * 359;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,5752(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5752);
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r6,r8,243
	ctx.r6.s64 = ctx.r8.s64 + 243;
	// rlwinm r8,r6,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lbzx r5,r7,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// add r31,r8,r9
	r31.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r4,r5,0,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82136b0c
	if (cr6.eq) goto loc_82136B0C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82136b20
	goto loc_82136B20;
loc_82136B0C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
loc_82136B20:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82136B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r7,1
	ctx.r7.s64 = 1;
	// srawi r11,r8,3
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	r11.s64 = ctx.r8.s32 >> 3;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwimi r6,r7,31,0,1
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0xC0000000) | (ctx.r6.u64 & 0xFFFFFFFF3FFFFFFF);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// stw r6,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r6.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82136bac
	if (cr6.lt) goto loc_82136BAC;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82136b78
	if (!cr6.eq) goto loc_82136B78;
	// li r11,-1
	r11.s64 = -1;
	// rlwimi r8,r11,3,0,28
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 3) & 0xFFFFFFF8) | (ctx.r8.u64 & 0xFFFFFFFF00000007);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82136B78:
	// subf. r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82136ba8
	if (cr0.eq) goto loc_82136BA8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// twllei r9,0
	// divwu r7,r11,r9
	ctx.r7.u32 = r11.u32 / ctx.r9.u32;
	// mullw r6,r7,r9
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwimi r8,r11,3,0,28
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 3) & 0xFFFFFFF8) | (ctx.r8.u64 & 0xFFFFFFFF00000007);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82136BA8:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82136BAC:
	// rlwimi r8,r11,3,0,28
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 3) & 0xFFFFFFF8) | (ctx.r8.u64 & 0xFFFFFFFF00000007);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82136BBC"))) PPC_WEAK_FUNC(sub_82136BBC);
PPC_FUNC_IMPL(__imp__sub_82136BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136BC0"))) PPC_WEAK_FUNC(sub_82136BC0);
PPC_FUNC_IMPL(__imp__sub_82136BC0) {
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
	ctx.lr = 0x82136BC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r30,r28
	r30.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f08
	ctx.lr = 0x82136BE4;
	sub_821C8F08(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_82136BE8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82136c10
	if (!cr6.eq) goto loc_82136C10;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82136c70
	if (!cr6.eq) goto loc_82136C70;
	// li r30,1
	r30.s64 = 1;
loc_82136C10:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82136be8
	if (cr6.eq) goto loc_82136BE8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r8.u8);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r7,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r7.u32);
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821c8f70
	ctx.lr = 0x82136C54;
	sub_821C8F70(ctx, base);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r30,r11
	ctx.r6.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r6,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82136C70:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f70
	ctx.lr = 0x82136C78;
	sub_821C8F70(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82136C84"))) PPC_WEAK_FUNC(sub_82136C84);
PPC_FUNC_IMPL(__imp__sub_82136C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136C88"))) PPC_WEAK_FUNC(sub_82136C88);
PPC_FUNC_IMPL(__imp__sub_82136C88) {
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
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82136CB0;
	sub_821374B0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821380c8
	ctx.lr = 0x82136CB8;
	sub_821380C8(ctx, base);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,5752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 5752);
	// beq cr6,0x82136cec
	if (cr6.eq) goto loc_82136CEC;
	// bl 0x82136bc0
	ctx.lr = 0x82136CD4;
	sub_82136BC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136ce4
	if (cr6.eq) goto loc_82136CE4;
	// bl 0x82141320
	ctx.lr = 0x82136CE0;
	sub_82141320(ctx, base);
	// b 0x82136cfc
	goto loc_82136CFC;
loc_82136CE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82136d20
	goto loc_82136D20;
loc_82136CEC:
	// bl 0x82136bc0
	ctx.lr = 0x82136CF0;
	sub_82136BC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82136ce4
	if (cr6.eq) goto loc_82136CE4;
	// bl 0x8213fbf0
	ctx.lr = 0x82136CFC;
	sub_8213FBF0(ctx, base);
loc_82136CFC:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82136d20
	if (cr6.eq) goto loc_82136D20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82136D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82136D20:
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

__attribute__((alias("__imp__sub_82136D38"))) PPC_WEAK_FUNC(sub_82136D38);
PPC_FUNC_IMPL(__imp__sub_82136D38) {
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
	ctx.lr = 0x82136D40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// rlwinm r10,r4,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82136d90
	if (cr6.eq) goto loc_82136D90;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r31,r11,96
	r31.s64 = r11.s64 + 96;
	// b 0x82136d94
	goto loc_82136D94;
loc_82136D90:
	// li r31,0
	r31.s64 = 0;
loc_82136D94:
	// lbz r28,72(r31)
	r28.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213f158
	ctx.lr = 0x82136DA8;
	sub_8213F158(ctx, base);
	// mulli r10,r28,359
	ctx.r10.s64 = r28.s64 * 359;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r10,r10,243
	ctx.r10.s64 = ctx.r10.s64 + 243;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82136c88
	ctx.lr = 0x82136DCC;
	sub_82136C88(ctx, base);
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// rlwimi r9,r8,30,0,1
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 30) & 0xC0000000) | (ctx.r9.u64 & 0xFFFFFFFF3FFFFFFF);
	// li r6,768
	ctx.r6.s64 = 768;
	// stw r9,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r9.u32);
	// lwz r11,5752(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5752);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// divw r3,r4,r6
	ctx.r3.s32 = ctx.r4.s32 / ctx.r6.s32;
	// stb r3,71(r31)
	PPC_STORE_U8(r31.u32 + 71, ctx.r3.u8);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stb r9,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82136E0C"))) PPC_WEAK_FUNC(sub_82136E0C);
PPC_FUNC_IMPL(__imp__sub_82136E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136E10"))) PPC_WEAK_FUNC(sub_82136E10);
PPC_FUNC_IMPL(__imp__sub_82136E10) {
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
	ctx.lr = 0x82136E18;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x82136570
	ctx.lr = 0x82136E28;
	sub_82136570(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,7496
	ctx.r8.s64 = ctx.r10.s64 + 7496;
	// sth r9,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r9.u16);
	// subf r3,r6,r27
	ctx.r3.s64 = r27.s64 - ctx.r6.s64;
	// lwz r11,5752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5752);
	// lwz r29,12(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r30,44(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82142f20
	ctx.lr = 0x82136E64;
	sub_82142F20(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82142720
	ctx.lr = 0x82136E74;
	sub_82142720(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82142c08
	ctx.lr = 0x82136E8C;
	sub_82142C08(ctx, base);
	// lhz r4,106(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 106);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82136ec8
	if (cr6.eq) goto loc_82136EC8;
	// li r29,0
	r29.s64 = 0;
	// lis r28,-32125
	r28.s64 = -2105344000;
loc_82136EA4:
	// lwz r11,5700(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 5700);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhzx r4,r29,r11
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + r11.u32);
	// bl 0x82136a60
	ctx.lr = 0x82136EB4;
	sub_82136A60(ctx, base);
	// lhz r10,106(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 106);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x82136ea4
	if (cr6.lt) goto loc_82136EA4;
loc_82136EC8:
	// lhz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82136f04
	if (cr6.eq) goto loc_82136F04;
	// li r30,0
	r30.s64 = 0;
	// lis r28,-32125
	r28.s64 = -2105344000;
loc_82136EE0:
	// lwz r11,5696(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 5696);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + r11.u32);
	// bl 0x82136d38
	ctx.lr = 0x82136EF0;
	sub_82136D38(ctx, base);
	// lhz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x82136ee0
	if (cr6.lt) goto loc_82136EE0;
loc_82136F04:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82136700
	ctx.lr = 0x82136F10;
	sub_82136700(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82136F18"))) PPC_WEAK_FUNC(sub_82136F18);
PPC_FUNC_IMPL(__imp__sub_82136F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,8444
	ctx.r10.s64 = r11.s64 + 8444;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82136F28"))) PPC_WEAK_FUNC(sub_82136F28);
PPC_FUNC_IMPL(__imp__sub_82136F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// lbz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// stb r9,137(r31)
	PPC_STORE_U8(r31.u32 + 137, ctx.r9.u8);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// rlwinm r8,r8,0,31,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// stb r8,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r8.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82136F74:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82136f74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82136F74;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r31,56
	ctx.r8.s64 = r31.s64 + 56;
	// li r7,3
	ctx.r7.s64 = 3;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82136F90:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// li r11,6
	r11.s64 = 6;
loc_82136F98:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x82136f98
	if (!cr0.eq) goto loc_82136F98;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x82136f90
	if (!cr0.eq) goto loc_82136F90;
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82137000
	if (cr6.eq) goto loc_82137000;
	// bl 0x821374b0
	ctx.lr = 0x82136FC8;
	sub_821374B0(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x821380c8
	ctx.lr = 0x82136FD4;
	sub_821380C8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lbz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// rlwimi r10,r8,3,28,28
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 3) & 0x8) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// lfs f0,8488(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8488);
	f0.f64 = double(temp.f32);
	// lhz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// b 0x82137010
	goto loc_82137010;
loc_82137000:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// lfs f0,8488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8488);
	f0.f64 = double(temp.f32);
loc_82137010:
	// stfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
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

__attribute__((alias("__imp__sub_8213702C"))) PPC_WEAK_FUNC(sub_8213702C);
PPC_FUNC_IMPL(__imp__sub_8213702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137030"))) PPC_WEAK_FUNC(sub_82137030);
PPC_FUNC_IMPL(__imp__sub_82137030) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82137040
	if (cr6.eq) goto loc_82137040;
	// b 0x82137890
	sub_82137890(ctx, base);
	return;
loc_82137040:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137048"))) PPC_WEAK_FUNC(sub_82137048);
PPC_FUNC_IMPL(__imp__sub_82137048) {
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
	ctx.lr = 0x82137050;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8ed8
	ctx.lr = 0x82137068;
	sub_821C8ED8(ctx, base);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r29,r11,8,0,23
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8213707C;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x82137088;
	sub_82130528(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
	// li r11,0
	r11.s64 = 0;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// ble cr6,0x821370d0
	if (!cr6.gt) goto loc_821370D0;
loc_821370B0:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// blt cr6,0x821370b0
	if (cr6.lt) goto loc_821370B0;
loc_821370D0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r11,8492
	ctx.r3.s64 = r11.s64 + 8492;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x821370E4;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821370F0"))) PPC_WEAK_FUNC(sub_821370F0);
PPC_FUNC_IMPL(__imp__sub_821370F0) {
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
	ctx.lr = 0x821370F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,768
	ctx.r10.s64 = 768;
	// lwz r11,5752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5752);
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// mr r29,r11
	r29.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// divw r30,r8,r10
	r30.s32 = ctx.r8.s32 / ctx.r10.s32;
	// bl 0x821c8f08
	ctx.lr = 0x82137124;
	sub_821C8F08(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stbx r6,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, ctx.r6.u8);
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r5.u32);
	// bl 0x821c8f70
	ctx.lr = 0x82137148;
	sub_821C8F70(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82137150"))) PPC_WEAK_FUNC(sub_82137150);
PPC_FUNC_IMPL(__imp__sub_82137150) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,8444
	ctx.r9.s64 = r11.s64 + 8444;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82137184
	if (cr6.eq) goto loc_82137184;
	// bl 0x821370f0
	ctx.lr = 0x82137180;
	sub_821370F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82137184:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137198"))) PPC_WEAK_FUNC(sub_82137198);
PPC_FUNC_IMPL(__imp__sub_82137198) {
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
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x821371AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821371e4
	if (cr6.eq) goto loc_821371E4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,5608
	ctx.r9.s64 = r11.s64 + 5608;
	// addi r5,r10,8512
	ctx.r5.s64 = ctx.r10.s64 + 8512;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82137048
	ctx.lr = 0x821371CC;
	sub_82137048(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r3,5752(r8)
	PPC_STORE_U32(ctx.r8.u32 + 5752, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821371E4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// stw r11,5752(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5752, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137200"))) PPC_WEAK_FUNC(sub_82137200);
PPC_FUNC_IMPL(__imp__sub_82137200) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r31,5752(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 5752);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82137230
	if (cr6.eq) goto loc_82137230;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82162628
	ctx.lr = 0x82137228;
	sub_82162628(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82137230;
	sub_82130588(ctx, base);
loc_82137230:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137244"))) PPC_WEAK_FUNC(sub_82137244);
PPC_FUNC_IMPL(__imp__sub_82137244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137248"))) PPC_WEAK_FUNC(sub_82137248);
PPC_FUNC_IMPL(__imp__sub_82137248) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// beq cr6,0x8213729c
	if (cr6.eq) goto loc_8213729C;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82137278:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82137278
	if (!cr6.eq) goto loc_82137278;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x8213729C;
	sub_821C9650(ctx, base);
loc_8213729C:
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

__attribute__((alias("__imp__sub_821372B4"))) PPC_WEAK_FUNC(sub_821372B4);
PPC_FUNC_IMPL(__imp__sub_821372B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821372B8"))) PPC_WEAK_FUNC(sub_821372B8);
PPC_FUNC_IMPL(__imp__sub_821372B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821372cc
	if (cr6.eq) goto loc_821372CC;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// blr 
	return;
loc_821372CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821372D8"))) PPC_WEAK_FUNC(sub_821372D8);
PPC_FUNC_IMPL(__imp__sub_821372D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// b 0x821436c0
	sub_821436C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821372EC"))) PPC_WEAK_FUNC(sub_821372EC);
PPC_FUNC_IMPL(__imp__sub_821372EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821372F0"))) PPC_WEAK_FUNC(sub_821372F0);
PPC_FUNC_IMPL(__imp__sub_821372F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// b 0x82144768
	sub_82144768(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137304"))) PPC_WEAK_FUNC(sub_82137304);
PPC_FUNC_IMPL(__imp__sub_82137304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137308"))) PPC_WEAK_FUNC(sub_82137308);
PPC_FUNC_IMPL(__imp__sub_82137308) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x8213732C;
	sub_8244D150(ctx, base);
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// bl 0x821bcac8
	ctx.lr = 0x82137368;
	sub_821BCAC8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8213737C"))) PPC_WEAK_FUNC(sub_8213737C);
PPC_FUNC_IMPL(__imp__sub_8213737C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137380"))) PPC_WEAK_FUNC(sub_82137380);
PPC_FUNC_IMPL(__imp__sub_82137380) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r5,0
	ctx.r5.s64 = 0;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// lwz r6,60(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,16(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// ble cr6,0x8213742c
	if (!cr6.gt) goto loc_8213742C;
	// li r9,0
	ctx.r9.s64 = 0;
loc_821373CC:
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ldx r11,r10,r9
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// clrlwi r8,r4,31
	ctx.r8.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne cr6,0x82137414
	if (!cr6.eq) goto loc_82137414;
	// ld r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 32);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
loc_82137414:
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// blt cr6,0x821373cc
	if (cr6.lt) goto loc_821373CC;
loc_8213742C:
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82137458:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// blt cr6,0x82137458
	if (cr6.lt) goto loc_82137458;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137488"))) PPC_WEAK_FUNC(sub_82137488);
PPC_FUNC_IMPL(__imp__sub_82137488) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821374a8
	if (cr6.eq) goto loc_821374A8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,144
	ctx.r10.s64 = 144;
	// lwz r11,5824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5824);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// divwu r3,r9,r10
	ctx.r3.u32 = ctx.r9.u32 / ctx.r10.u32;
	// blr 
	return;
loc_821374A8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821374B0"))) PPC_WEAK_FUNC(sub_821374B0);
PPC_FUNC_IMPL(__imp__sub_821374B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821374d4
	if (cr6.eq) goto loc_821374D4;
	// rlwinm r11,r3,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,5824(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 5824);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
loc_821374D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821374DC"))) PPC_WEAK_FUNC(sub_821374DC);
PPC_FUNC_IMPL(__imp__sub_821374DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

