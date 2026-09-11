#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82641A34"))) PPC_WEAK_FUNC(sub_82641A34);
PPC_FUNC_IMPL(__imp__sub_82641A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641A38"))) PPC_WEAK_FUNC(sub_82641A38);
PPC_FUNC_IMPL(__imp__sub_82641A38) {
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
	ctx.lr = 0x82641A40;
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
	ctx.lr = 0x82641A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82641ac4
	if (cr6.eq) goto loc_82641AC4;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641ac4
	if (cr6.eq) goto loc_82641AC4;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,512(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// b 0x82641ad8
	goto loc_82641AD8;
loc_82641AC4:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// lwz r31,436(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 436);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
loc_82641AD8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641AF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
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
	ctx.lr = 0x82641B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82641B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82641b4c
	if (cr6.eq) goto loc_82641B4C;
loc_82641B48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82641B4C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82641B54"))) PPC_WEAK_FUNC(sub_82641B54);
PPC_FUNC_IMPL(__imp__sub_82641B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641B58"))) PPC_WEAK_FUNC(sub_82641B58);
PPC_FUNC_IMPL(__imp__sub_82641B58) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82641bb0
	if (cr6.eq) goto loc_82641BB0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641bb0
	if (cr6.eq) goto loc_82641BB0;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82641bc0
	if (!cr6.eq) goto loc_82641BC0;
loc_82641BB0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82641BBC;
	sub_82207190(ctx, base);
	// b 0x82641bf4
	goto loc_82641BF4;
loc_82641BC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641BD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641bf4
	if (cr6.eq) goto loc_82641BF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641BF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82641BF4:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641c08
	if (cr6.eq) goto loc_82641C08;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82207190
	ctx.lr = 0x82641C08;
	sub_82207190(ctx, base);
loc_82641C08:
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

__attribute__((alias("__imp__sub_82641C20"))) PPC_WEAK_FUNC(sub_82641C20);
PPC_FUNC_IMPL(__imp__sub_82641C20) {
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
	ctx.lr = 0x82641C28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lhz r24,72(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82641c98
	if (!cr6.gt) goto loc_82641C98;
	// li r31,0
	r31.s64 = 0;
loc_82641C54:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,380(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 380);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82641ca4
	if (!cr6.eq) goto loc_82641CA4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r24
	cr6.compare<int32_t>(r29.s32, r24.s32, xer);
	// blt cr6,0x82641c54
	if (cr6.lt) goto loc_82641C54;
loc_82641C98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82641CA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82641CB0"))) PPC_WEAK_FUNC(sub_82641CB0);
PPC_FUNC_IMPL(__imp__sub_82641CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641CC8"))) PPC_WEAK_FUNC(sub_82641CC8);
PPC_FUNC_IMPL(__imp__sub_82641CC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641cec
	if (cr6.eq) goto loc_82641CEC;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,13136
	ctx.r10.s64 = ctx.r10.s64 + 13136;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82641CEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641CF4"))) PPC_WEAK_FUNC(sub_82641CF4);
PPC_FUNC_IMPL(__imp__sub_82641CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641CF8"))) PPC_WEAK_FUNC(sub_82641CF8);
PPC_FUNC_IMPL(__imp__sub_82641CF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641d18
	if (cr6.eq) goto loc_82641D18;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82641D18:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641D20"))) PPC_WEAK_FUNC(sub_82641D20);
PPC_FUNC_IMPL(__imp__sub_82641D20) {
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
	// lwz r31,212(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82641d7c
	if (cr6.eq) goto loc_82641D7C;
loc_82641D3C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641d70
	if (cr6.eq) goto loc_82641D70;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82641D70:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82641d3c
	if (!cr6.eq) goto loc_82641D3C;
loc_82641D7C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641D90"))) PPC_WEAK_FUNC(sub_82641D90);
PPC_FUNC_IMPL(__imp__sub_82641D90) {
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
	// addi r10,r11,6644
	ctx.r10.s64 = r11.s64 + 6644;
	// lwz r3,872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dc4
	if (cr6.eq) goto loc_82641DC4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DC4;
	sub_821EC060(ctx, base);
loc_82641DC4:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dd8
	if (cr6.eq) goto loc_82641DD8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DD8;
	sub_821EC060(ctx, base);
loc_82641DD8:
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dec
	if (cr6.eq) goto loc_82641DEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DEC;
	sub_821EC060(ctx, base);
loc_82641DEC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// bl 0x82633b00
	ctx.lr = 0x82641E04;
	sub_82633B00(ctx, base);
	// addi r3,r31,464
	ctx.r3.s64 = r31.s64 + 464;
	// bl 0x82633b00
	ctx.lr = 0x82641E0C;
	sub_82633B00(ctx, base);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// bl 0x82633b00
	ctx.lr = 0x82641E14;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82641E1C;
	sub_82633B00(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641E30"))) PPC_WEAK_FUNC(sub_82641E30);
PPC_FUNC_IMPL(__imp__sub_82641E30) {
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
	// bl 0x8221cdd0
	ctx.lr = 0x82641E48;
	sub_8221CDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641e64
	if (cr6.eq) goto loc_82641E64;
	// lbz r11,896(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 896);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82641e68
	if (cr6.eq) goto loc_82641E68;
loc_82641E64:
	// li r11,0
	r11.s64 = 0;
loc_82641E68:
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

__attribute__((alias("__imp__sub_82641E80"))) PPC_WEAK_FUNC(sub_82641E80);
PPC_FUNC_IMPL(__imp__sub_82641E80) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r3,r10,7412
	ctx.r3.s64 = ctx.r10.s64 + 7412;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x82641EB4;
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
	ctx.lr = 0x82641EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r6,r7,16324
	ctx.r6.u64 = ctx.r7.u64 | 16324;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwzx r5,r11,r6
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// lwz r3,284(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 284);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82215a60
	ctx.lr = 0x82641EF8;
	sub_82215A60(ctx, base);
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

__attribute__((alias("__imp__sub_82641F10"))) PPC_WEAK_FUNC(sub_82641F10);
PPC_FUNC_IMPL(__imp__sub_82641F10) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82641F18;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d8
	ctx.lr = 0x82641F20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641F4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f29,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82642114
	if (cr6.eq) goto loc_82642114;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,264(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// lwz r30,-5008(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r9,1892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1892);
	// lwz r8,1888(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1888);
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r6,r10,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r10.s64;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f9,f11,f30
	ctx.f9.f64 = double(float(ctx.f11.f64 - f30.f64));
	// fsubs f7,f30,f9
	ctx.f7.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fsel f6,f7,f30,f9
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : ctx.f9.f64;
	// fdivs f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 / ctx.f6.f64));
	// fsel f4,f5,f5,f29
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f29.f64;
	// fsubs f3,f4,f30
	ctx.f3.f64 = double(float(ctx.f4.f64 - f30.f64));
	// fsel f1,f3,f30,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? f30.f64 : ctx.f4.f64;
	// bl 0x82630290
	ctx.lr = 0x82641FC8;
	sub_82630290(ctx, base);
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// rlwinm r3,r11,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826420f8
	if (!cr6.eq) goto loc_826420F8;
	// rlwinm r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82641ff4
	if (!cr6.eq) goto loc_82641FF4;
	// bl 0x822610b0
	ctx.lr = 0x82641FE8;
	sub_822610B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82642044
	if (!cr6.eq) goto loc_82642044;
loc_82641FF4:
	// lwz r11,1888(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1888);
	// lwz r10,1892(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1892);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82642044
	if (!cr6.eq) goto loc_82642044;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82642014;
	sub_822A39C8(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f0,36(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82642038
	if (cr6.lt) goto loc_82642038;
	// li r11,1
	r11.s64 = 1;
loc_82642038:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826420f8
	if (cr6.eq) goto loc_826420F8;
loc_82642044:
	// bl 0x823bbf80
	ctx.lr = 0x82642048;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82642114
	if (!cr6.eq) goto loc_82642114;
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82642114
	if (!cr6.eq) goto loc_82642114;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82642068;
	sub_82388598(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r30,r10,21384
	r30.s64 = ctx.r10.s64 + 21384;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8264207C;
	sub_8221CBA0(ctx, base);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82642088;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x82642094;
	sub_8221CBF8(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8260c6d8
	ctx.lr = 0x826420B0;
	sub_8260C6D8(ctx, base);
	// fmuls f31,f1,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// lfs f13,864(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 864);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14196(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14196);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// stfs f12,864(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x826420f0
	if (!cr6.lt) goto loc_826420F0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826420EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f30,864(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
loc_826420F0:
	// li r29,1
	r29.s64 = 1;
	// b 0x82642114
	goto loc_82642114;
loc_826420F8:
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
	ctx.lr = 0x82642110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82641e80
	ctx.lr = 0x82642114;
	sub_82641E80(ctx, base);
loc_82642114:
	// lfs f0,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8264214c
	if (!cr6.lt) goto loc_8264214C;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f13,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f11,868(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// ble cr6,0x82642180
	if (!cr6.gt) goto loc_82642180;
	// b 0x8264217c
	goto loc_8264217C;
loc_8264214C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82642180
	if (!cr6.gt) goto loc_82642180;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,868(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fnmsubs f11,f0,f13,f12
	ctx.f11.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// stfs f11,868(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x82642180
	if (!cr6.lt) goto loc_82642180;
loc_8264217C:
	// stfs f31,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
loc_82642180:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826421a8
	if (cr6.eq) goto loc_826421A8;
	// lfs f0,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x826421a8
	if (cr6.eq) goto loc_826421A8;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x826421b4
	goto loc_826421B4;
loc_826421A8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_826421B4:
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640958
	ctx.lr = 0x826421C0;
	sub_82640958(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x82130000
	ctx.lr = 0x826421CC;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x826421D8;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826421DC"))) PPC_WEAK_FUNC(sub_826421DC);
PPC_FUNC_IMPL(__imp__sub_826421DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826421E0"))) PPC_WEAK_FUNC(sub_826421E0);
PPC_FUNC_IMPL(__imp__sub_826421E0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826421F0"))) PPC_WEAK_FUNC(sub_826421F0);
PPC_FUNC_IMPL(__imp__sub_826421F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r11,r11,r4
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// add r9,r11,r5
	ctx.r9.u64 = r11.u64 + ctx.r5.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264220C"))) PPC_WEAK_FUNC(sub_8264220C);
PPC_FUNC_IMPL(__imp__sub_8264220C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642210"))) PPC_WEAK_FUNC(sub_82642210);
PPC_FUNC_IMPL(__imp__sub_82642210) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10868
	ctx.r4.s64 = ctx.r10.s64 + -10868;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642238;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82642250
	if (cr6.eq) goto loc_82642250;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82632f00
	ctx.lr = 0x82642250;
	sub_82632F00(ctx, base);
loc_82642250:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82642264"))) PPC_WEAK_FUNC(sub_82642264);
PPC_FUNC_IMPL(__imp__sub_82642264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642268"))) PPC_WEAK_FUNC(sub_82642268);
PPC_FUNC_IMPL(__imp__sub_82642268) {
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
	// addi r10,r11,4588
	ctx.r10.s64 = r11.s64 + 4588;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82642294;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826422ac
	if (cr6.eq) goto loc_826422AC;
	// bl 0x82130588
	ctx.lr = 0x826422A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826422AC:
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

__attribute__((alias("__imp__sub_826422C4"))) PPC_WEAK_FUNC(sub_826422C4);
PPC_FUNC_IMPL(__imp__sub_826422C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826422C8"))) PPC_WEAK_FUNC(sub_826422C8);
PPC_FUNC_IMPL(__imp__sub_826422C8) {
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
	ctx.lr = 0x826422D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,63
	cr6.compare<int32_t>(ctx.r4.s32, 63, xer);
	// beq cr6,0x826422ec
	if (cr6.eq) goto loc_826422EC;
	// bl 0x826537d0
	ctx.lr = 0x826422E4;
	sub_826537D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826422EC:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x826422F8;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826423ec
	if (!cr6.gt) goto loc_826423EC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264230C;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,16324
	ctx.r8.u64 = ctx.r9.u64 | 16324;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r3,164(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 164);
	// bl 0x82204ab8
	ctx.lr = 0x8264232C;
	sub_82204AB8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,-12216(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// bl 0x82203240
	ctx.lr = 0x82642340;
	sub_82203240(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ef5e0
	ctx.lr = 0x82642350;
	sub_821EF5E0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826423c8
	if (!cr6.eq) goto loc_826423C8;
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,-12216(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r27,r11,3,0,28
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82203240
	ctx.lr = 0x82642374;
	sub_82203240(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lwz r3,-12216(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x821ef700
	ctx.lr = 0x82642390;
	sub_821EF700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x82642398;
	sub_82641000(ctx, base);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826423AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640338
	ctx.lr = 0x826423B4;
	sub_82640338(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, ctx.r4.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826423C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x826423D0;
	sub_82641000(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r11,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, r11.u8);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826423EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826423EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826423F8"))) PPC_WEAK_FUNC(sub_826423F8);
PPC_FUNC_IMPL(__imp__sub_826423F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642424;
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
	ctx.lr = 0x82642440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,2800(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r6,-23232
	ctx.r5.s64 = ctx.r6.s64 + -23232;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// lwzx r4,r10,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r6,992(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r11,-12216(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12216);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82642498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = r11.s64 + -8;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, ctx.r9.u8);
	// bl 0x82640338
	ctx.lr = 0x826424B8;
	sub_82640338(ctx, base);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826424CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826424ec
	if (!cr6.gt) goto loc_826424EC;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826424EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826424EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x826424F4;
	sub_82641000(ctx, base);
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

__attribute__((alias("__imp__sub_8264250C"))) PPC_WEAK_FUNC(sub_8264250C);
PPC_FUNC_IMPL(__imp__sub_8264250C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642510"))) PPC_WEAK_FUNC(sub_82642510);
PPC_FUNC_IMPL(__imp__sub_82642510) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8264253C;
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
	ctx.lr = 0x82642558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lis r5,3
	ctx.r5.s64 = 196608;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// ori r4,r5,37060
	ctx.r4.u64 = ctx.r5.u64 | 37060;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10028(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10028);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stbx r10,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// lwz r8,672(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r9,524(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// stb r9,1012(r31)
	PPC_STORE_U8(r31.u32 + 1012, ctx.r9.u8);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lwz r7,648(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 648);
	// lwz r4,52(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264259C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r5,r31,1008
	ctx.r5.s64 = r31.s64 + 1008;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826425c8
	if (!cr6.eq) goto loc_826425C8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r4,r9,7528
	ctx.r4.s64 = ctx.r9.s64 + 7528;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x826425C8;
	sub_821EE720(ctx, base);
loc_826425C8:
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r11,524(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// beq cr6,0x826425f0
	if (cr6.eq) goto loc_826425F0;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3992
	ctx.r8.s64 = ctx.r10.s64 + 3992;
	// addi r3,r9,7508
	ctx.r3.s64 = ctx.r9.s64 + 7508;
	// b 0x82642600
	goto loc_82642600;
loc_826425F0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3968
	ctx.r8.s64 = ctx.r10.s64 + 3968;
	// addi r3,r9,7488
	ctx.r3.s64 = ctx.r9.s64 + 7488;
loc_82642600:
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x82642608;
	sub_82130000(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264261C;
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

__attribute__((alias("__imp__sub_82642634"))) PPC_WEAK_FUNC(sub_82642634);
PPC_FUNC_IMPL(__imp__sub_82642634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642638"))) PPC_WEAK_FUNC(sub_82642638);
PPC_FUNC_IMPL(__imp__sub_82642638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82642640;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,3
	r11.s64 = 196608;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// ori r8,r11,37060
	ctx.r8.u64 = r11.u64 | 37060;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,-10028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// lwz r11,-12216(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8264267c
	if (!cr6.eq) goto loc_8264267C;
	// lbz r10,524(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// lbz r9,1012(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1012);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826426bc
	if (cr6.eq) goto loc_826426BC;
loc_8264267C:
	// lbz r29,524(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// bl 0x82387b90
	ctx.lr = 0x82642684;
	sub_82387B90(ctx, base);
	// stb r29,1325(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1325, r29.u8);
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,-31280
	ctx.r3.s64 = ctx.r3.s64 + -31280;
	// bl 0x826410d8
	ctx.lr = 0x82642698;
	sub_826410D8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826426BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826426BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826426CC;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x826426fc
	if (cr6.eq) goto loc_826426FC;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x82642718
	if (!cr6.eq) goto loc_82642718;
loc_826426FC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f3,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82207ef0
	ctx.lr = 0x82642718;
	sub_82207EF0(ctx, base);
loc_82642718:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r3,284(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 284);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82642740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1008(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1008);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82642754
	if (cr6.eq) goto loc_82642754;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82642754;
	sub_821EC060(ctx, base);
loc_82642754:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x8264275C;
	sub_82216138(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82642764"))) PPC_WEAK_FUNC(sub_82642764);
PPC_FUNC_IMPL(__imp__sub_82642764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642768"))) PPC_WEAK_FUNC(sub_82642768);
PPC_FUNC_IMPL(__imp__sub_82642768) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82642814
	if (cr6.eq) goto loc_82642814;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// beq cr6,0x82642798
	if (cr6.eq) goto loc_82642798;
	// bl 0x826537d0
	ctx.lr = 0x82642794;
	sub_826537D0(ctx, base);
	// b 0x82642870
	goto loc_82642870;
loc_82642798:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826427A4;
	sub_821E6800(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r10,524(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 524);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821eea90
	ctx.lr = 0x826427BC;
	sub_821EEA90(ctx, base);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r8,524(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// beq cr6,0x826427e4
	if (cr6.eq) goto loc_826427E4;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3992
	ctx.r8.s64 = ctx.r10.s64 + 3992;
	// addi r3,r9,7508
	ctx.r3.s64 = ctx.r9.s64 + 7508;
	// b 0x826427f4
	goto loc_826427F4;
loc_826427E4:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3968
	ctx.r8.s64 = ctx.r10.s64 + 3968;
	// addi r3,r9,7488
	ctx.r3.s64 = ctx.r9.s64 + 7488;
loc_826427F4:
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x826427FC;
	sub_82130000(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8264286c
	goto loc_8264286C;
loc_82642814:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82642820;
	sub_821E6800(ctx, base);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x82642828;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642838
	if (cr6.lt) goto loc_82642838;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642838:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r8,r9,16324
	ctx.r8.u64 = ctx.r9.u64 | 16324;
	// lwz r10,-10236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r3,160(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 160);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,2800(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2800, r11.u32);
	// lwz r11,704(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 704);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264286C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264286C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82642870:
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

__attribute__((alias("__imp__sub_82642888"))) PPC_WEAK_FUNC(sub_82642888);
PPC_FUNC_IMPL(__imp__sub_82642888) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x826428A4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826428b4
	if (cr6.lt) goto loc_826428B4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826428B4:
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x826429bc
	if (cr6.gt) goto loc_826429BC;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,10452
	r12.s64 = r12.s64 + 10452;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826428EC;
	case 1:
		goto loc_8264290C;
	case 2:
		goto loc_8264292C;
	case 3:
		goto loc_8264294C;
	case 4:
		goto loc_8264296C;
	case 5:
		goto loc_8264298C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10476(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10476);
	// lwz r19,10508(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10508);
	// lwz r19,10540(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10540);
	// lwz r19,10572(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10572);
	// lwz r19,10604(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10604);
	// lwz r19,10636(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10636);
loc_826428EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,116(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 116);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264290C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,108(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264292C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,104(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264294C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,112(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264296C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,88(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264298C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,84(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
loc_826429A8:
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,704(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 704);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826429BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826429BC:
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

__attribute__((alias("__imp__sub_826429D4"))) PPC_WEAK_FUNC(sub_826429D4);
PPC_FUNC_IMPL(__imp__sub_826429D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826429D8"))) PPC_WEAK_FUNC(sub_826429D8);
PPC_FUNC_IMPL(__imp__sub_826429D8) {
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
	ctx.lr = 0x826429E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// ori r30,r11,16324
	r30.u64 = r11.u64 | 16324;
	// addi r31,r26,672
	r31.s64 = r26.s64 + 672;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r29,96(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// bl 0x82631f88
	ctx.lr = 0x82642A10;
	sub_82631F88(ctx, base);
	// lwz r11,856(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642a20
	if (cr6.lt) goto loc_82642A20;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642A20:
	// lwz r10,1000(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 1000);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r26,1000
	r27.s64 = r26.s64 + 1000;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,-12120(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12120);
	// mulli r5,r6,104
	ctx.r5.s64 = ctx.r6.s64 * 104;
	// lwz r10,788(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// lwzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r8,r9,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// lwz r30,96(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// bl 0x82631f88
	ctx.lr = 0x82642A6C;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r29,r11
	r29.u64 = r11.u64;
	// blt cr6,0x82642a80
	if (cr6.lt) goto loc_82642A80;
	// addi r29,r3,-1
	r29.s64 = ctx.r3.s64 + -1;
loc_82642A80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82642A88;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642a98
	if (cr6.lt) goto loc_82642A98;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642A98:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,688(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 688);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82642AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82642AD0"))) PPC_WEAK_FUNC(sub_82642AD0);
PPC_FUNC_IMPL(__imp__sub_82642AD0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r30,100(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 100);
	// bl 0x82631f88
	ctx.lr = 0x82642B0C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642b1c
	if (cr6.lt) goto loc_82642B1C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642B1C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,700(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82642B54"))) PPC_WEAK_FUNC(sub_82642B54);
PPC_FUNC_IMPL(__imp__sub_82642B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642B58"))) PPC_WEAK_FUNC(sub_82642B58);
PPC_FUNC_IMPL(__imp__sub_82642B58) {
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
	ctx.lr = 0x82642B60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r25,992
	ctx.r3.s64 = r25.s64 + 992;
	// lwz r11,992(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 992);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82642c98
	if (!cr6.gt) goto loc_82642C98;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82642B90;
	sub_8238EC00(ctx, base);
	// addi r31,r25,672
	r31.s64 = r25.s64 + 672;
	// lwz r30,864(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 864);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82642BA4;
	sub_82631F88(ctx, base);
	// lwz r4,856(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 856);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642bb4
	if (cr6.lt) goto loc_82642BB4;
	// addi r4,r3,-1
	ctx.r4.s64 = ctx.r3.s64 + -1;
loc_82642BB4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642BCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82389800
	ctx.lr = 0x82642BD8;
	sub_82389800(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lwz r28,864(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 864);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// ori r30,r9,16324
	r30.u64 = ctx.r9.u64 | 16324;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// lwz r27,92(r7)
	r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// bl 0x82631f88
	ctx.lr = 0x82642C04;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642c14
	if (cr6.lt) goto loc_82642C14;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642C14:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r26,0(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,788(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 788);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r6,r7,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	// lwz r30,92(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// bl 0x82631f88
	ctx.lr = 0x82642C60;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642c70
	if (cr6.lt) goto loc_82642C70;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642C70:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r25,1232
	ctx.r7.s64 = r25.s64 + 1232;
	// lhz r9,16(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 16);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,688(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 688);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82642C98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82642CA4"))) PPC_WEAK_FUNC(sub_82642CA4);
PPC_FUNC_IMPL(__imp__sub_82642CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642CA8"))) PPC_WEAK_FUNC(sub_82642CA8);
PPC_FUNC_IMPL(__imp__sub_82642CA8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r30,80(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// bl 0x82631f88
	ctx.lr = 0x82642CE4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642cf4
	if (cr6.lt) goto loc_82642CF4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642CF4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,700(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642D10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82642D2C"))) PPC_WEAK_FUNC(sub_82642D2C);
PPC_FUNC_IMPL(__imp__sub_82642D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642D30"))) PPC_WEAK_FUNC(sub_82642D30);
PPC_FUNC_IMPL(__imp__sub_82642D30) {
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
	ctx.lr = 0x82642D38;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,1000(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1000);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82642e34
	if (!cr6.gt) goto loc_82642E34;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r28,r27,848
	r28.s64 = r27.s64 + 848;
	// addi r31,r27,1084
	r31.s64 = r27.s64 + 1084;
	// ori r26,r8,57220
	r26.u64 = ctx.r8.u64 | 57220;
	// addi r24,r11,7596
	r24.s64 = r11.s64 + 7596;
	// addi r23,r10,7576
	r23.s64 = ctx.r10.s64 + 7576;
	// addi r25,r9,7556
	r25.s64 = ctx.r9.s64 + 7556;
loc_82642D78:
	// addi r30,r29,1
	r30.s64 = r29.s64 + 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,50
	ctx.r4.s64 = 50;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82642D90;
	sub_82137A08(ctx, base);
	// lwz r3,-80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642DA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lwz r6,-80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r11,996(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 996);
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// bl 0x82387b90
	ctx.lr = 0x82642DD0;
	sub_82387B90(ctx, base);
	// add r5,r3,r29
	ctx.r5.u64 = ctx.r3.u64 + r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbzx r4,r5,r26
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + r26.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// beq cr6,0x82642df4
	if (cr6.eq) goto loc_82642DF4;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
loc_82642DF4:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r4,1000(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 1000);
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x82642d78
	if (cr6.lt) goto loc_82642D78;
loc_82642E34:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82642E3C"))) PPC_WEAK_FUNC(sub_82642E3C);
PPC_FUNC_IMPL(__imp__sub_82642E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642E40"))) PPC_WEAK_FUNC(sub_82642E40);
PPC_FUNC_IMPL(__imp__sub_82642E40) {
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
	ctx.lr = 0x82642E48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
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
	ctx.lr = 0x82642E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82642e8c
	if (!cr6.eq) goto loc_82642E8C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643180
	if (cr6.eq) goto loc_82643180;
loc_82642E8C:
	// addi r30,r31,996
	r30.s64 = r31.s64 + 996;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740958
	ctx.lr = 0x82642E98;
	sub_82740958(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823b2078
	ctx.lr = 0x82642EA0;
	sub_823B2078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82642f6c
	if (cr6.eq) goto loc_82642F6C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,1044
	ctx.r3.s64 = r31.s64 + 1044;
	// lwz r4,-6752(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -6752);
	// bl 0x82740730
	ctx.lr = 0x82642EC4;
	sub_82740730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,792(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 792);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,4176(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r9,7680
	ctx.r4.s64 = ctx.r9.s64 + 7680;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82642EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640738
	ctx.lr = 0x82642EFC;
	sub_82640738(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r3.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r6,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r6.u32);
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stb r29,4385(r31)
	PPC_STORE_U8(r31.u32 + 4385, r29.u8);
	// addi r4,r5,28988
	ctx.r4.s64 = ctx.r5.s64 + 28988;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8262ffe0
	ctx.lr = 0x82642F24;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642F38;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642F54;
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
	ctx.lr = 0x82642F68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_82642F6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823b2090
	ctx.lr = 0x82642F74;
	sub_823B2090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643020
	if (cr6.eq) goto loc_82643020;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,7656
	ctx.r4.s64 = ctx.r10.s64 + 7656;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,4176(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r8,7640
	ctx.r4.s64 = ctx.r8.s64 + 7640;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82642FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r5,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r5.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,29228
	ctx.r4.s64 = ctx.r4.s64 + 29228;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82642FD8;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642FEC;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643008;
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
	ctx.lr = 0x8264301C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_82643020:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740708
	ctx.lr = 0x82643028;
	sub_82740708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430d4
	if (cr6.eq) goto loc_826430D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,7616
	ctx.r4.s64 = ctx.r10.s64 + 7616;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,4176(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r8,7640
	ctx.r4.s64 = ctx.r8.s64 + 7640;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264306C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r5,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r5.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,29228
	ctx.r4.s64 = ctx.r4.s64 + 29228;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x8264308C;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826430A0;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826430BC;
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
	ctx.lr = 0x826430D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_826430D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740720
	ctx.lr = 0x826430DC;
	sub_82740720(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430fc
	if (cr6.eq) goto loc_826430FC;
	// lbz r11,4386(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4386);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430fc
	if (cr6.eq) goto loc_826430FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d4cc0
	ctx.lr = 0x826430FC;
	sub_822D4CC0(ctx, base);
loc_826430FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82643104;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82643114;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8264311C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643154
	if (cr6.eq) goto loc_82643154;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82643130;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82643140;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82643148;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82643180
	if (!cr6.eq) goto loc_82643180;
loc_82643154:
	// lbz r11,4387(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4387);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82643180
	if (!cr6.eq) goto loc_82643180;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8264317C;
	sub_82289AB0(ctx, base);
	// stb r29,4387(r31)
	PPC_STORE_U8(r31.u32 + 4387, r29.u8);
loc_82643180:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643188"))) PPC_WEAK_FUNC(sub_82643188);
PPC_FUNC_IMPL(__imp__sub_82643188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x82643190;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826431B4;
	sub_821F9FB8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r28,56(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826431C8;
	sub_8238EC00(ctx, base);
	// lwz r4,4172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// bl 0x82388c48
	ctx.lr = 0x826431D0;
	sub_82388C48(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,55
	cr6.compare<int32_t>(r29.s32, 55, xer);
	// beq cr6,0x826432a0
	if (cr6.eq) goto loc_826432A0;
	// cmpwi cr6,r29,56
	cr6.compare<int32_t>(r29.s32, 56, xer);
	// beq cr6,0x82643280
	if (cr6.eq) goto loc_82643280;
	// cmpwi cr6,r29,62
	cr6.compare<int32_t>(r29.s32, 62, xer);
	// beq cr6,0x82643204
	if (cr6.eq) goto loc_82643204;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x826431FC;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643204:
	// lbz r11,4385(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4385);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826434e0
	if (cr6.eq) goto loc_826434E0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264321C;
	sub_821E6800(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r29,r10,16324
	r29.u64 = ctx.r10.u64 | 16324;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// lwz r3,24(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,196(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82643248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r6,4164(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4164);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,1048(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 1048);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r11,r3,r29
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,696(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 696);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643280:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826432A0:
	// lbz r11,4385(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4385);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826434e0
	if (cr6.eq) goto loc_826434E0;
	// bl 0x82387b38
	ctx.lr = 0x826432B0;
	sub_82387B38(ctx, base);
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x826434ec
	if (cr6.gt) goto loc_826434EC;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,13016
	r12.s64 = r12.s64 + 13016;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826432E8;
	case 1:
		goto loc_826433FC;
	case 2:
		goto loc_82643448;
	case 3:
		goto loc_82643494;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13032(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13032);
	// lwz r19,13308(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13308);
	// lwz r19,13384(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13384);
	// lwz r19,13460(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13460);
loc_826432E8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,25
	ctx.r3.s64 = 25;
	// stb r10,4384(r30)
	PPC_STORE_U8(r30.u32 + 4384, ctx.r10.u8);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r10,797(r8)
	PPC_STORE_U8(ctx.r8.u32 + 797, ctx.r10.u8);
	// bl 0x82216138
	ctx.lr = 0x8264330C;
	sub_82216138(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lwz r4,4172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// lis r6,2
	ctx.r6.s64 = 131072;
	// ori r28,r7,44552
	r28.u64 = ctx.r7.u64 | 44552;
	// ori r29,r6,36016
	r29.u64 = ctx.r6.u64 | 36016;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stwx r4,r5,r28
	PPC_STORE_U32(ctx.r5.u32 + r28.u32, ctx.r4.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + r29.u64;
	// bl 0x826583c0
	ctx.lr = 0x8264333C;
	sub_826583C0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r10,4172(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stwx r10,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, ctx.r10.u32);
	// beq cr6,0x82643388
	if (cr6.eq) goto loc_82643388;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lbz r10,19(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 19);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r11,r8,3
	r11.s64 = ctx.r8.s64 + 196608;
	// addi r11,r11,-28128
	r11.s64 = r11.s64 + -28128;
	// lwz r7,216(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 216);
	// stw r9,216(r11)
	PPC_STORE_U32(r11.u32 + 216, ctx.r9.u32);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// beq cr6,0x82643388
	if (cr6.eq) goto loc_82643388;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82643388;
	sub_821C3048(ctx, base);
loc_82643388:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,-26912
	ctx.r3.s64 = ctx.r3.s64 + -26912;
	// bl 0x8262fff0
	ctx.lr = 0x826433A0;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,3
	ctx.r3.s64 = ctx.r10.s64 + 196608;
	// addi r3,r3,-26672
	ctx.r3.s64 = ctx.r3.s64 + -26672;
	// bl 0x8262fff0
	ctx.lr = 0x826433B8;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 196608;
	// addi r3,r3,-27632
	ctx.r3.s64 = ctx.r3.s64 + -27632;
	// bl 0x8262fff0
	ctx.lr = 0x826433D0;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r29
	ctx.r3.u64 = ctx.r8.u64 + r29.u64;
	// bl 0x82655550
	ctx.lr = 0x826433E0;
	sub_82655550(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r29
	ctx.r3.u64 = ctx.r7.u64 + r29.u64;
	// bl 0x8265d2b8
	ctx.lr = 0x826433F0;
	sub_8265D2B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826433FC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7732
	ctx.r3.s64 = r11.s64 + 7732;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x82643418;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8264342C;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264343C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643448:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7716
	ctx.r3.s64 = r11.s64 + 7716;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x82643464;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82643478;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82643488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643494:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7700
	ctx.r3.s64 = r11.s64 + 7700;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x826434B0;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826434C4;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826434D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826434E0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826434EC;
	sub_821E6800(ctx, base);
loc_826434EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826434F8"))) PPC_WEAK_FUNC(sub_826434F8);
PPC_FUNC_IMPL(__imp__sub_826434F8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8264355c
	if (!cr6.eq) goto loc_8264355C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 65536;
	// addi r4,r4,16256
	ctx.r4.s64 = ctx.r4.s64 + 16256;
	// lwz r9,68(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r3,440(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 440);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264354C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8264355C:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82643564;
	sub_82216138(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82643574"))) PPC_WEAK_FUNC(sub_82643574);
PPC_FUNC_IMPL(__imp__sub_82643574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643578"))) PPC_WEAK_FUNC(sub_82643578);
PPC_FUNC_IMPL(__imp__sub_82643578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82643580;
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// lwz r11,672(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 672);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826435A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r3,2832(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2832);
	// lbz r8,10852(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10852);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82643768
	if (cr6.eq) goto loc_82643768;
	// lbz r11,10096(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643744
	if (cr6.eq) goto loc_82643744;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-6752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6752);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x82643664
	if (cr6.gt) goto loc_82643664;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,13808
	r12.s64 = r12.s64 + 13808;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82643650;
	case 1:
		goto loc_82643614;
	case 2:
		goto loc_82643628;
	case 3:
		goto loc_8264363C;
	case 4:
		goto loc_82643664;
	case 5:
		goto loc_82643608;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13904(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13904);
	// lwz r19,13844(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13844);
	// lwz r19,13864(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13864);
	// lwz r19,13884(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13884);
	// lwz r19,13924(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13924);
	// lwz r19,13832(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13832);
loc_82643608:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,9416
	r29.s64 = ctx.r10.s64 + 9416;
	// b 0x8264366c
	goto loc_8264366C;
loc_82643614:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,9368
	r30.s64 = r11.s64 + 9368;
	// addi r29,r10,9064
	r29.s64 = ctx.r10.s64 + 9064;
	// b 0x82643674
	goto loc_82643674;
loc_82643628:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,9012
	r30.s64 = r11.s64 + 9012;
	// addi r29,r10,8688
	r29.s64 = ctx.r10.s64 + 8688;
	// b 0x82643674
	goto loc_82643674;
loc_8264363C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,8644
	r30.s64 = r11.s64 + 8644;
	// addi r29,r10,8352
	r29.s64 = ctx.r10.s64 + 8352;
	// b 0x82643674
	goto loc_82643674;
loc_82643650:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,8308
	r30.s64 = r11.s64 + 8308;
	// addi r29,r10,8032
	r29.s64 = ctx.r10.s64 + 8032;
	// b 0x82643674
	goto loc_82643674;
loc_82643664:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,7808
	r29.s64 = ctx.r10.s64 + 7808;
loc_8264366C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r30,r11,7764
	r30.s64 = r11.s64 + 7764;
loc_82643674:
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwu r11,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// addi r26,r1,96
	r26.s64 = ctx.r1.s64 + 96;
	// stb r28,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r28.u8);
	// bl 0x823de3a8
	ctx.lr = 0x82643690;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821e4958
	ctx.lr = 0x826436A0;
	sub_821E4958(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r25,r10,7744
	r25.s64 = ctx.r10.s64 + 7744;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826436BC;
	sub_822183B0(ctx, base);
	// stb r28,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r28.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823de3a8
	ctx.lr = 0x826436C8;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821e4958
	ctx.lr = 0x826436D8;
	sub_821E4958(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r30,r9,-3200
	r30.s64 = ctx.r9.s64 + -3200;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x826436F0;
	sub_822183B0(ctx, base);
	// lis r8,-32156
	ctx.r8.s64 = -2107375616;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r8,13560
	ctx.r4.s64 = ctx.r8.s64 + 13560;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8264370C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// stb r28,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r28.u8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r3,r27,1248
	ctx.r3.s64 = r27.s64 + 1248;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82634ec8
	ctx.lr = 0x8264373C;
	sub_82634EC8(ctx, base);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
loc_82643744:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
loc_82643768:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82643770;
	sub_82216138(ctx, base);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82643778"))) PPC_WEAK_FUNC(sub_82643778);
PPC_FUNC_IMPL(__imp__sub_82643778) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633dc8
	ctx.lr = 0x82643798;
	sub_82633DC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r10,r11,9564
	ctx.r10.s64 = r11.s64 + 9564;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,27808
	ctx.r4.s64 = ctx.r9.s64 + 27808;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b68
	ctx.lr = 0x826437BC;
	sub_82633B68(ctx, base);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_826437FC"))) PPC_WEAK_FUNC(sub_826437FC);
PPC_FUNC_IMPL(__imp__sub_826437FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643800"))) PPC_WEAK_FUNC(sub_82643800);
PPC_FUNC_IMPL(__imp__sub_82643800) {
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
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82643824;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8264382C;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643844
	if (cr6.eq) goto loc_82643844;
	// bl 0x82130588
	ctx.lr = 0x82643840;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82643844:
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

__attribute__((alias("__imp__sub_8264385C"))) PPC_WEAK_FUNC(sub_8264385C);
PPC_FUNC_IMPL(__imp__sub_8264385C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643860"))) PPC_WEAK_FUNC(sub_82643860);
PPC_FUNC_IMPL(__imp__sub_82643860) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643888;
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
	ctx.lr = 0x826438A4;
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

__attribute__((alias("__imp__sub_826438B8"))) PPC_WEAK_FUNC(sub_826438B8);
PPC_FUNC_IMPL(__imp__sub_826438B8) {
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
	// addi r3,r31,5700
	ctx.r3.s64 = r31.s64 + 5700;
	// bl 0x821d2028
	ctx.lr = 0x826438D8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5696
	ctx.r3.s64 = r31.s64 + 5696;
	// bl 0x821d2028
	ctx.lr = 0x826438E0;
	sub_821D2028(ctx, base);
	// addi r3,r31,5692
	ctx.r3.s64 = r31.s64 + 5692;
	// bl 0x821d2028
	ctx.lr = 0x826438E8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5688
	ctx.r3.s64 = r31.s64 + 5688;
	// bl 0x821d2028
	ctx.lr = 0x826438F0;
	sub_821D2028(ctx, base);
	// addi r3,r31,5680
	ctx.r3.s64 = r31.s64 + 5680;
	// bl 0x821d2028
	ctx.lr = 0x826438F8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5676
	ctx.r3.s64 = r31.s64 + 5676;
	// bl 0x821d2028
	ctx.lr = 0x82643900;
	sub_821D2028(ctx, base);
	// addi r3,r31,5672
	ctx.r3.s64 = r31.s64 + 5672;
	// bl 0x821d2028
	ctx.lr = 0x82643908;
	sub_821D2028(ctx, base);
	// addi r3,r31,5668
	ctx.r3.s64 = r31.s64 + 5668;
	// bl 0x821d2028
	ctx.lr = 0x82643910;
	sub_821D2028(ctx, base);
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// bl 0x821d2028
	ctx.lr = 0x82643918;
	sub_821D2028(ctx, base);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// bl 0x82633b00
	ctx.lr = 0x82643920;
	sub_82633B00(ctx, base);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// bl 0x82633b00
	ctx.lr = 0x82643928;
	sub_82633B00(ctx, base);
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// bl 0x82233ba0
	ctx.lr = 0x82643930;
	sub_82233BA0(ctx, base);
	// addi r3,r31,3840
	ctx.r3.s64 = r31.s64 + 3840;
	// bl 0x82633b00
	ctx.lr = 0x82643938;
	sub_82633B00(ctx, base);
	// addi r3,r31,3648
	ctx.r3.s64 = r31.s64 + 3648;
	// bl 0x82633b00
	ctx.lr = 0x82643940;
	sub_82633B00(ctx, base);
	// addi r30,r31,2832
	r30.s64 = r31.s64 + 2832;
	// addi r3,r30,468
	ctx.r3.s64 = r30.s64 + 468;
	// bl 0x82726128
	ctx.lr = 0x8264394C;
	sub_82726128(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82643954;
	sub_82633B00(ctx, base);
	// addi r3,r31,2624
	ctx.r3.s64 = r31.s64 + 2624;
	// bl 0x82633b00
	ctx.lr = 0x8264395C;
	sub_82633B00(ctx, base);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// bl 0x82633b00
	ctx.lr = 0x82643964;
	sub_82633B00(ctx, base);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// bl 0x82633b00
	ctx.lr = 0x8264396C;
	sub_82633B00(ctx, base);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// bl 0x82633b00
	ctx.lr = 0x82643974;
	sub_82633B00(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x82633b00
	ctx.lr = 0x8264397C;
	sub_82633B00(ctx, base);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// bl 0x82633b00
	ctx.lr = 0x82643984;
	sub_82633B00(ctx, base);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82633b00
	ctx.lr = 0x8264398C;
	sub_82633B00(ctx, base);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// bl 0x82633b00
	ctx.lr = 0x82643994;
	sub_82633B00(ctx, base);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// bl 0x82633b00
	ctx.lr = 0x8264399C;
	sub_82633B00(ctx, base);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// bl 0x82633b00
	ctx.lr = 0x826439A4;
	sub_82633B00(ctx, base);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// bl 0x82633b00
	ctx.lr = 0x826439AC;
	sub_82633B00(ctx, base);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// bl 0x82633b00
	ctx.lr = 0x826439B4;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x826439BC;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826439C4;
	sub_82633B00(ctx, base);
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

__attribute__((alias("__imp__sub_826439DC"))) PPC_WEAK_FUNC(sub_826439DC);
PPC_FUNC_IMPL(__imp__sub_826439DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826439E0"))) PPC_WEAK_FUNC(sub_826439E0);
PPC_FUNC_IMPL(__imp__sub_826439E0) {
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
	ctx.lr = 0x826439E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x82643A08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// cmpwi cr6,r29,63
	cr6.compare<int32_t>(r29.s32, 63, xer);
	// bne cr6,0x82643a54
	if (!cr6.eq) goto loc_82643A54;
	// bl 0x823bbf80
	ctx.lr = 0x82643A20;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643a54
	if (cr6.eq) goto loc_82643A54;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb498
	ctx.lr = 0x82643A38;
	sub_823BB498(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// addi r3,r11,10736
	ctx.r3.s64 = r11.s64 + 10736;
	// bl 0x82214168
	ctx.lr = 0x82643A48;
	sub_82214168(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82643A54:
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82643a90
	if (cr6.eq) goto loc_82643A90;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643A74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643a90
	if (cr6.eq) goto loc_82643A90;
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82643a98
	if (!cr6.eq) goto loc_82643A98;
loc_82643A90:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r31,436(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 436);
loc_82643A98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643AB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82643afc
	if (!cr6.eq) goto loc_82643AFC;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r10,436(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x82643b40
	if (!cr6.eq) goto loc_82643B40;
loc_82643AFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643B18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82643b44
	if (cr6.eq) goto loc_82643B44;
loc_82643B40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82643B44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82643B4C"))) PPC_WEAK_FUNC(sub_82643B4C);
PPC_FUNC_IMPL(__imp__sub_82643B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643B50"))) PPC_WEAK_FUNC(sub_82643B50);
PPC_FUNC_IMPL(__imp__sub_82643B50) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82643B58;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lhz r31,72(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82643ba0
	if (!cr6.gt) goto loc_82643BA0;
	// li r30,0
	r30.s64 = 0;
loc_82643B78:
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82643b78
	if (!cr0.eq) goto loc_82643B78;
loc_82643BA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641d20
	ctx.lr = 0x82643BA8;
	sub_82641D20(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643BB4"))) PPC_WEAK_FUNC(sub_82643BB4);
PPC_FUNC_IMPL(__imp__sub_82643BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643BB8"))) PPC_WEAK_FUNC(sub_82643BB8);
PPC_FUNC_IMPL(__imp__sub_82643BB8) {
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
	ctx.lr = 0x82643BC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BCC;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r29,r29,14048
	r29.s64 = r29.s64 + 14048;
loc_82643BDC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BE4;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BF4;
	sub_82641CC8(ctx, base);
	// addi r11,r31,2672
	r11.s64 = r31.s64 + 2672;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C08;
	sub_82641CC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C14;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C2C;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x82643c54
	if (cr6.eq) goto loc_82643C54;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643c84
	if (cr6.eq) goto loc_82643C84;
loc_82643C54:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,744(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82643C84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C8C;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82643bdc
	if (!cr6.eq) goto loc_82643BDC;
loc_82643C94:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643C9C"))) PPC_WEAK_FUNC(sub_82643C9C);
PPC_FUNC_IMPL(__imp__sub_82643C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643CA0"))) PPC_WEAK_FUNC(sub_82643CA0);
PPC_FUNC_IMPL(__imp__sub_82643CA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82643CA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633dc8
	ctx.lr = 0x82643CB8;
	sub_82633DC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,6644
	ctx.r9.s64 = r11.s64 + 6644;
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// addi r28,r31,272
	r28.s64 = r31.s64 + 272;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826340f0
	ctx.lr = 0x82643CE4;
	sub_826340F0(ctx, base);
	// addi r29,r31,464
	r29.s64 = r31.s64 + 464;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633930
	ctx.lr = 0x82643CF4;
	sub_82633930(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// addi r7,r8,3236
	ctx.r7.s64 = ctx.r8.s64 + 3236;
	// addi r27,r31,640
	r27.s64 = r31.s64 + 640;
	// stw r7,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r7.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r6,28052
	ctx.r4.s64 = ctx.r6.s64 + 28052;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633b68
	ctx.lr = 0x82643D18;
	sub_82633B68(ctx, base);
	// stb r30,896(r31)
	PPC_STORE_U8(r31.u32 + 896, r30.u8);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// addi r11,r31,532
	r11.s64 = r31.s64 + 532;
	// lwz r10,532(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 532);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r26,r4,19856
	r26.s64 = ctx.r4.s64 + 19856;
	// addi r4,r3,10408
	ctx.r4.s64 = ctx.r3.s64 + 10408;
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lhz r11,536(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 536);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,536(r31)
	PPC_STORE_U16(r31.u32 + 536, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,532(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 532);
	// lhz r11,536(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 536);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,536(r31)
	PPC_STORE_U16(r31.u32 + 536, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// stfs f0,864(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// stfs f0,868(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// stb r30,844(r31)
	PPC_STORE_U8(r31.u32 + 844, r30.u8);
	// stw r30,872(r31)
	PPC_STORE_U32(r31.u32 + 872, r30.u32);
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// stw r30,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r30.u32);
	// bl 0x82144a20
	ctx.lr = 0x82643DA4;
	sub_82144A20(ctx, base);
	// stw r3,884(r31)
	PPC_STORE_U32(r31.u32 + 884, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r6,10372
	ctx.r4.s64 = ctx.r6.s64 + 10372;
	// bl 0x82144a20
	ctx.lr = 0x82643DB8;
	sub_82144A20(ctx, base);
	// stw r3,888(r31)
	PPC_STORE_U32(r31.u32 + 888, ctx.r3.u32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r5,10344
	ctx.r4.s64 = ctx.r5.s64 + 10344;
	// bl 0x82144a20
	ctx.lr = 0x82643DCC;
	sub_82144A20(ctx, base);
	// stw r3,892(r31)
	PPC_STORE_U32(r31.u32 + 892, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82643DDC"))) PPC_WEAK_FUNC(sub_82643DDC);
PPC_FUNC_IMPL(__imp__sub_82643DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643DE0"))) PPC_WEAK_FUNC(sub_82643DE0);
PPC_FUNC_IMPL(__imp__sub_82643DE0) {
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
	// bl 0x82641d90
	ctx.lr = 0x82643E00;
	sub_82641D90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643e18
	if (cr6.eq) goto loc_82643E18;
	// bl 0x82130588
	ctx.lr = 0x82643E14;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82643E18:
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

__attribute__((alias("__imp__sub_82643E30"))) PPC_WEAK_FUNC(sub_82643E30);
PPC_FUNC_IMPL(__imp__sub_82643E30) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643E58;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643e70
	if (cr6.eq) goto loc_82643E70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82632f00
	ctx.lr = 0x82643E70;
	sub_82632F00(ctx, base);
loc_82643E70:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82643E84"))) PPC_WEAK_FUNC(sub_82643E84);
PPC_FUNC_IMPL(__imp__sub_82643E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643E88"))) PPC_WEAK_FUNC(sub_82643E88);
PPC_FUNC_IMPL(__imp__sub_82643E88) {
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
	ctx.lr = 0x82643E90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x82643EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644068
	if (cr6.eq) goto loc_82644068;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82643EC4;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lbz r10,36(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 36);
	// bne cr6,0x82643f0c
	if (!cr6.eq) goto loc_82643F0C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// addi r4,r11,29484
	ctx.r4.s64 = r11.s64 + 29484;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82643EF4;
	sub_8262FFE0(ctx, base);
	// lwz r10,640(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82643fc0
	goto loc_82643FC0;
loc_82643F0C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82643f2c
	if (!cr6.eq) goto loc_82643F2C;
	// lwz r11,640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82643fc0
	goto loc_82643FC0;
loc_82643F2C:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// bne cr6,0x82643f74
	if (!cr6.eq) goto loc_82643F74;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643f5c
	if (cr6.eq) goto loc_82643F5C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,28052
	ctx.r4.s64 = ctx.r10.s64 + 28052;
	// lwz r11,28892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28892);
	// b 0x82643f9c
	goto loc_82643F9C;
loc_82643F5C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,28052
	ctx.r4.s64 = ctx.r10.s64 + 28052;
	// lwz r11,28888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28888);
	// b 0x82643f9c
	goto loc_82643F9C;
loc_82643F74:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643f88
	if (cr6.eq) goto loc_82643F88;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r11,28892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28892);
	// b 0x82643f90
	goto loc_82643F90;
loc_82643F88:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r11,28888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28888);
loc_82643F90:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r10,29300
	ctx.r4.s64 = ctx.r10.s64 + 29300;
loc_82643F9C:
	// stw r11,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r11.u32);
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82643FAC;
	sub_8262FFE0(ctx, base);
	// lwz r9,640(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82643FC0:
	// bctrl 
	ctx.lr = 0x82643FC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643FD8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82644068
	if (cr6.eq) goto loc_82644068;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r11,-10292
	r29.s64 = r11.s64 + -10292;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82643FF8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82644008;
	sub_825ED480(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bne cr6,0x8264402c
	if (!cr6.eq) goto loc_8264402C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2736
	ctx.r4.s64 = ctx.r10.s64 + -2736;
	// b 0x82644034
	goto loc_82644034;
loc_8264402C:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,10448
	ctx.r4.s64 = ctx.r10.s64 + 10448;
loc_82644034:
	// bl 0x82218310
	ctx.lr = 0x82644038;
	sub_82218310(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-13276
	ctx.r4.s64 = ctx.r9.s64 + -13276;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8264404C;
	sub_827227B8(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,10436
	ctx.r4.s64 = ctx.r10.s64 + 10436;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x82644068;
	sub_82722678(ctx, base);
loc_82644068:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82632f78
	ctx.lr = 0x82644070;
	sub_82632F78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82644084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826440a0
	if (!cr6.eq) goto loc_826440A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x826440A0;
	sub_8220F040(ctx, base);
loc_826440A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826440A8"))) PPC_WEAK_FUNC(sub_826440A8);
PPC_FUNC_IMPL(__imp__sub_826440A8) {
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
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// bl 0x8221fbc8
	ctx.lr = 0x826440C8;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,1424
	ctx.r3.s64 = r31.s64 + 1424;
	// bl 0x8221fbc8
	ctx.lr = 0x826440D0;
	sub_8221FBC8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,1376
	ctx.r3.s64 = r31.s64 + 1376;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// stw r10,1376(r31)
	PPC_STORE_U32(r31.u32 + 1376, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826440E4;
	sub_821D2028(ctx, base);
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// bl 0x821d2028
	ctx.lr = 0x826440EC;
	sub_821D2028(ctx, base);
	// lhz r9,1050(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 1050);
	// addi r30,r31,1040
	r30.s64 = r31.s64 + 1040;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644104
	if (cr6.eq) goto loc_82644104;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644104;
	sub_82130588(ctx, base);
loc_82644104:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264410C;
	sub_821D2028(ctx, base);
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// addi r30,r31,1016
	r30.s64 = r31.s64 + 1016;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644124
	if (cr6.eq) goto loc_82644124;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644124;
	sub_82130588(ctx, base);
loc_82644124:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264412C;
	sub_821D2028(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644144
	if (cr6.eq) goto loc_82644144;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644144;
	sub_82130588(ctx, base);
loc_82644144:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264414C;
	sub_821D2028(ctx, base);
	// lhz r11,986(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 986);
	// addi r30,r31,976
	r30.s64 = r31.s64 + 976;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644164
	if (cr6.eq) goto loc_82644164;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644164;
	sub_82130588(ctx, base);
loc_82644164:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264416C;
	sub_821D2028(ctx, base);
	// lhz r11,962(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 962);
	// addi r30,r31,952
	r30.s64 = r31.s64 + 952;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644184
	if (cr6.eq) goto loc_82644184;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644184;
	sub_82130588(ctx, base);
loc_82644184:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264418C;
	sub_821D2028(ctx, base);
	// lhz r11,938(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 938);
	// addi r30,r31,928
	r30.s64 = r31.s64 + 928;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826441a4
	if (cr6.eq) goto loc_826441A4;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x826441A4;
	sub_82130588(ctx, base);
loc_826441A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x826441AC;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826441B4;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826441CC"))) PPC_WEAK_FUNC(sub_826441CC);
PPC_FUNC_IMPL(__imp__sub_826441CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826441D0"))) PPC_WEAK_FUNC(sub_826441D0);
PPC_FUNC_IMPL(__imp__sub_826441D0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,-25064
	ctx.r5.s64 = r11.s64 + -25064;
	// addi r4,r10,11264
	ctx.r4.s64 = ctx.r10.s64 + 11264;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644208;
	sub_82654318(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,10460
	ctx.r6.s64 = ctx.r7.s64 + 10460;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stb r5,245(r31)
	PPC_STORE_U8(r31.u32 + 245, ctx.r5.u8);
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

__attribute__((alias("__imp__sub_82644258"))) PPC_WEAK_FUNC(sub_82644258);
PPC_FUNC_IMPL(__imp__sub_82644258) {
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
	// bl 0x82653b30
	ctx.lr = 0x82644270;
	sub_82653B30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1008(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82644290"))) PPC_WEAK_FUNC(sub_82644290);
PPC_FUNC_IMPL(__imp__sub_82644290) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,12896
	ctx.r4.s64 = ctx.r9.s64 + 12896;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28964
	ctx.r8.s64 = r11.s64 + 28964;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x826442D0;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r6,r8,12092
	ctx.r6.s64 = ctx.r8.s64 + 12092;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r4,r5,7460
	ctx.r4.s64 = ctx.r5.s64 + 7460;
	// lwz r11,-12216(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12216);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stb r30,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, r30.u8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x82634b60
	ctx.lr = 0x82644314;
	sub_82634B60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r30,480(r31)
	PPC_STORE_U8(r31.u32 + 480, r30.u8);
	// lis r8,-32156
	ctx.r8.s64 = -2107375616;
	// stb r9,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, ctx.r9.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r30,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r30.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,4464
	ctx.r4.s64 = ctx.r8.s64 + 4464;
	// bl 0x821c2f90
	ctx.lr = 0x82644338;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82644348:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82644348
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82644348;
	// addi r10,r31,888
	ctx.r10.s64 = r31.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264436C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264436c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264436C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8264439C"))) PPC_WEAK_FUNC(sub_8264439C);
PPC_FUNC_IMPL(__imp__sub_8264439C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826443A0"))) PPC_WEAK_FUNC(sub_826443A0);
PPC_FUNC_IMPL(__imp__sub_826443A0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r9,13732
	ctx.r4.s64 = ctx.r9.s64 + 13732;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28100
	ctx.r8.s64 = r11.s64 + 28100;
	// addi r5,r10,13720
	ctx.r5.s64 = ctx.r10.s64 + 13720;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x826443DC;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r8,12916
	ctx.r5.s64 = ctx.r8.s64 + 12916;
	// addi r3,r6,-23232
	ctx.r3.s64 = ctx.r6.s64 + -23232;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,9
	r11.s64 = 9;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82644430"))) PPC_WEAK_FUNC(sub_82644430);
PPC_FUNC_IMPL(__imp__sub_82644430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82644438;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,14672
	ctx.r4.s64 = ctx.r9.s64 + 14672;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644468;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r7,r8,13868
	ctx.r7.s64 = ctx.r8.s64 + 13868;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,13840
	ctx.r4.s64 = ctx.r6.s64 + 13840;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264448C;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,13824
	ctx.r4.s64 = ctx.r4.s64 + 13824;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444A4;
	sub_82633D40(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,13804
	ctx.r4.s64 = ctx.r3.s64 + 13804;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444BC;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13784
	ctx.r4.s64 = r11.s64 + 13784;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444D4;
	sub_82633D40(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r26,r31,1824
	r26.s64 = r31.s64 + 1824;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13764
	ctx.r4.s64 = ctx.r10.s64 + 13764;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444EC;
	sub_82633D40(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r25,r31,2032
	r25.s64 = r31.s64 + 2032;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,13744
	ctx.r4.s64 = ctx.r9.s64 + 13744;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x82644504;
	sub_82633D40(ctx, base);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264451C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826445BC"))) PPC_WEAK_FUNC(sub_826445BC);
PPC_FUNC_IMPL(__imp__sub_826445BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826445C0"))) PPC_WEAK_FUNC(sub_826445C0);
PPC_FUNC_IMPL(__imp__sub_826445C0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13840
	ctx.r4.s64 = ctx.r9.s64 + 13840;
	// addi r8,r11,24348
	ctx.r8.s64 = r11.s64 + 24348;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,50
	ctx.r6.s64 = 50;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826445FC;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,14700
	ctx.r7.s64 = ctx.r8.s64 + 14700;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1004(r31)
	PPC_STORE_U16(r31.u32 + 1004, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1006(r31)
	PPC_STORE_U16(r31.u32 + 1006, r11.u16);
	// stw r11,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r11.u32);
	// sth r11,1012(r31)
	PPC_STORE_U16(r31.u32 + 1012, r11.u16);
	// sth r11,1014(r31)
	PPC_STORE_U16(r31.u32 + 1014, r11.u16);
	// stw r11,1016(r31)
	PPC_STORE_U32(r31.u32 + 1016, r11.u32);
	// sth r11,1020(r31)
	PPC_STORE_U16(r31.u32 + 1020, r11.u16);
	// sth r11,1022(r31)
	PPC_STORE_U16(r31.u32 + 1022, r11.u16);
	// stw r11,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r11.u32);
	// sth r11,1028(r31)
	PPC_STORE_U16(r31.u32 + 1028, r11.u16);
	// sth r11,1030(r31)
	PPC_STORE_U16(r31.u32 + 1030, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x82644658;
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

__attribute__((alias("__imp__sub_82644670"))) PPC_WEAK_FUNC(sub_82644670);
PPC_FUNC_IMPL(__imp__sub_82644670) {
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
	// lhz r11,1030(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1030);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644698
	if (cr6.eq) goto loc_82644698;
	// lwz r3,1024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// bl 0x82130588
	ctx.lr = 0x82644698;
	sub_82130588(ctx, base);
loc_82644698:
	// lhz r11,1022(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1022);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446ac
	if (cr6.eq) goto loc_826446AC;
	// lwz r3,1016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1016);
	// bl 0x82130588
	ctx.lr = 0x826446AC;
	sub_82130588(ctx, base);
loc_826446AC:
	// lhz r11,1014(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1014);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446c0
	if (cr6.eq) goto loc_826446C0;
	// lwz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// bl 0x82130588
	ctx.lr = 0x826446C0;
	sub_82130588(ctx, base);
loc_826446C0:
	// lhz r11,1006(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1006);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446d4
	if (cr6.eq) goto loc_826446D4;
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x826446D4;
	sub_82130588(ctx, base);
loc_826446D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826446DC;
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

__attribute__((alias("__imp__sub_826446F0"))) PPC_WEAK_FUNC(sub_826446F0);
PPC_FUNC_IMPL(__imp__sub_826446F0) {
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
	ctx.lr = 0x826446F8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,103
	ctx.r10.s64 = 103;
	// addi r9,r11,5392
	ctx.r9.s64 = r11.s64 + 5392;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r24,r31,1008
	r24.s64 = r31.s64 + 1008;
	// addi r23,r31,1000
	r23.s64 = r31.s64 + 1000;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12440(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12440);
	// bl 0x8238e3a8
	ctx.lr = 0x8264473C;
	sub_8238E3A8(ctx, base);
	// lhz r6,1004(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 1004);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82644894
	if (cr6.eq) goto loc_82644894;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r31,1016
	r29.s64 = r31.s64 + 1016;
	// addi r28,r31,1024
	r28.s64 = r31.s64 + 1024;
	// li r30,0
	r30.s64 = 0;
	// addi r22,r11,5568
	r22.s64 = r11.s64 + 5568;
	// addi r25,r10,3998
	r25.s64 = ctx.r10.s64 + 3998;
loc_82644768:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bgt cr6,0x82644840
	if (cr6.gt) goto loc_82644840;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8264477C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82644798
	if (cr6.eq) goto loc_82644798;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x82644790;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8264479c
	goto loc_8264479C;
loc_82644798:
	// li r27,0
	r27.s64 = 0;
loc_8264479C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x826447A8;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x826447B8;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826447d4
	if (cr6.eq) goto loc_826447D4;
	// stw r22,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r22.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x826447D0;
	sub_826311F8(ctx, base);
	// b 0x826447d8
	goto loc_826447D8;
loc_826447D4:
	// li r27,0
	r27.s64 = 0;
loc_826447D8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x826447E4;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r6,r30,r10
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r11,r30,r5
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r5.u32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r30,r7
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
loc_82644840:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwzx r4,r30,r10
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82644860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r3,r30,r7
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// lwzx r4,r30,r6
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82644880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,1004(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1004);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x82644768
	if (cr6.lt) goto loc_82644768;
loc_82644894:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8264489C"))) PPC_WEAK_FUNC(sub_8264489C);
PPC_FUNC_IMPL(__imp__sub_8264489C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826448A0"))) PPC_WEAK_FUNC(sub_826448A0);
PPC_FUNC_IMPL(__imp__sub_826448A0) {
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
	ctx.lr = 0x826448A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r11,-12120
	r31.s64 = r11.s64 + -12120;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// addi r4,r7,13824
	ctx.r4.s64 = ctx.r7.s64 + 13824;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826448E0;
	sub_82654318(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// addi r5,r6,15508
	ctx.r5.s64 = ctx.r6.s64 + 15508;
	// addi r25,r30,992
	r25.s64 = r30.s64 + 992;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// mr r27,r29
	r27.u64 = r29.u64;
	// stw r29,992(r30)
	PPC_STORE_U32(r30.u32 + 992, r29.u32);
	// sth r29,996(r30)
	PPC_STORE_U16(r30.u32 + 996, r29.u16);
	// sth r29,998(r30)
	PPC_STORE_U16(r30.u32 + 998, r29.u16);
	// stw r29,1000(r30)
	PPC_STORE_U32(r30.u32 + 1000, r29.u32);
	// sth r29,1004(r30)
	PPC_STORE_U16(r30.u32 + 1004, r29.u16);
	// sth r29,1006(r30)
	PPC_STORE_U16(r30.u32 + 1006, r29.u16);
	// stw r29,1008(r30)
	PPC_STORE_U32(r30.u32 + 1008, r29.u32);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82644974
	if (cr6.eq) goto loc_82644974;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_82644924:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8264492C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264494c
	if (cr6.eq) goto loc_8264494C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r28,r11
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x82644944;
	sub_82633D40(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x82644950
	goto loc_82644950;
loc_8264494C:
	// mr r26,r29
	r26.u64 = r29.u64;
loc_82644950:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8262e420
	ctx.lr = 0x8264495C;
	sub_8262E420(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// addi r28,r28,104
	r28.s64 = r28.s64 + 104;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82644924
	if (cr6.lt) goto loc_82644924;
loc_82644974:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82644980"))) PPC_WEAK_FUNC(sub_82644980);
PPC_FUNC_IMPL(__imp__sub_82644980) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82644988;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r28,r26,848
	r28.s64 = r26.s64 + 848;
	// lwz r3,848(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 848);
	// bl 0x82130588
	ctx.lr = 0x8264499C;
	sub_82130588(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// addi r27,r26,1000
	r27.s64 = r26.s64 + 1000;
	// stw r31,848(r26)
	PPC_STORE_U32(r26.u32 + 848, r31.u32);
	// sth r31,852(r26)
	PPC_STORE_U16(r26.u32 + 852, r31.u16);
	// sth r31,854(r26)
	PPC_STORE_U16(r26.u32 + 854, r31.u16);
	// lwz r9,1000(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 1000);
	// lhz r11,1004(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 1004);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826449e4
	if (cr6.eq) goto loc_826449E4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826449D0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826449d0
	if (!cr6.eq) goto loc_826449D0;
loc_826449E4:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r24,r11,-12120
	r24.s64 = r11.s64 + -12120;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r7.u16);
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644ad4
	if (cr6.eq) goto loc_82644AD4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r29,r31
	r29.u64 = r31.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// li r21,118
	r21.s64 = 118;
	// lis r22,-32115
	r22.s64 = -2104688640;
	// addi r20,r11,-19152
	r20.s64 = r11.s64 + -19152;
	// addi r23,r10,3924
	r23.s64 = ctx.r10.s64 + 3924;
loc_82644A2C:
	// lhz r11,996(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 996);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82644ad4
	if (!cr6.lt) goto loc_82644AD4;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r30,r25,r11
	r30.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82644abc
	if (cr6.eq) goto loc_82644ABC;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r21,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r21.u8);
	// sth r31,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r31.u16);
	// lwz r3,-12440(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -12440);
	// bl 0x8238dd80
	ctx.lr = 0x82644A60;
	sub_8238DD80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82644ab4
	if (cr6.eq) goto loc_82644AB4;
	// lwz r11,992(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 992);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82644A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x82644A94;
	sub_8262E420(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r31.u32);
	// lwz r11,992(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 992);
	// lwzx r30,r11,r29
	r30.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8262e420
	ctx.lr = 0x82644AB0;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_82644AB4:
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
loc_82644ABC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r25,r25,104
	r25.s64 = r25.s64 + 104;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82644a2c
	if (cr6.lt) goto loc_82644A2C;
loc_82644AD4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82644ADC"))) PPC_WEAK_FUNC(sub_82644ADC);
PPC_FUNC_IMPL(__imp__sub_82644ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644AE0"))) PPC_WEAK_FUNC(sub_82644AE0);
PPC_FUNC_IMPL(__imp__sub_82644AE0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644B1C;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r6,r8,16428
	ctx.r6.s64 = ctx.r8.s64 + 16428;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r4,r7,16392
	ctx.r4.s64 = ctx.r7.s64 + 16392;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B3C;
	sub_82633D40(ctx, base);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// addi r3,r31,1200
	ctx.r3.s64 = r31.s64 + 1200;
	// addi r4,r5,16364
	ctx.r4.s64 = ctx.r5.s64 + 16364;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B50;
	sub_82633D40(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// addi r4,r4,16336
	ctx.r4.s64 = ctx.r4.s64 + 16336;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B64;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,1616
	ctx.r3.s64 = r31.s64 + 1616;
	// addi r4,r11,16312
	ctx.r4.s64 = r11.s64 + 16312;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B78;
	sub_82633D40(ctx, base);
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

__attribute__((alias("__imp__sub_82644B90"))) PPC_WEAK_FUNC(sub_82644B90);
PPC_FUNC_IMPL(__imp__sub_82644B90) {
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
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644bc0
	if (cr6.eq) goto loc_82644BC0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644BC0;
	sub_82130588(ctx, base);
loc_82644BC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644BC8;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644be0
	if (cr6.eq) goto loc_82644BE0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644BE0;
	sub_82130588(ctx, base);
loc_82644BE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644BE8;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644c00
	if (cr6.eq) goto loc_82644C00;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644C00;
	sub_82130588(ctx, base);
loc_82644C00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644C08;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644c20
	if (cr6.eq) goto loc_82644C20;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644C20;
	sub_82130588(ctx, base);
loc_82644C20:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644C28;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82644C30;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82644C48"))) PPC_WEAK_FUNC(sub_82644C48);
PPC_FUNC_IMPL(__imp__sub_82644C48) {
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
	ctx.lr = 0x82644C50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82659e28
	ctx.lr = 0x82644C60;
	sub_82659E28(ctx, base);
	// lhz r11,852(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 852);
	// lwz r9,848(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 848);
	// addi r31,r30,848
	r31.s64 = r30.s64 + 848;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82644c98
	if (cr6.eq) goto loc_82644C98;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82644C84:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82644c84
	if (!cr6.eq) goto loc_82644C84;
loc_82644C98:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r29,r11,17232
	r29.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r6,-4680
	ctx.r5.s64 = ctx.r6.s64 + -4680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644CC8;
	sub_826571D8(ctx, base);
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644cf4
	if (cr6.eq) goto loc_82644CF4;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,992
	ctx.r8.s64 = r30.s64 + 992;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82644CF4:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4744
	ctx.r5.s64 = r11.s64 + -4744;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D08;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644d34
	if (cr6.eq) goto loc_82644D34;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1408
	ctx.r8.s64 = r30.s64 + 1408;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82644D34:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4692
	ctx.r5.s64 = r11.s64 + -4692;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D48;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644d74
	if (cr6.eq) goto loc_82644D74;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1200
	ctx.r8.s64 = r30.s64 + 1200;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82644D74:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4764
	ctx.r5.s64 = r11.s64 + -4764;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D88;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644db4
	if (cr6.eq) goto loc_82644DB4;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1616
	ctx.r8.s64 = r30.s64 + 1616;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82644DB4:
	// lhz r10,90(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82644dc8
	if (cr6.eq) goto loc_82644DC8;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82130588
	ctx.lr = 0x82644DC8;
	sub_82130588(ctx, base);
loc_82644DC8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2028
	ctx.lr = 0x82644DD0;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82644DD8"))) PPC_WEAK_FUNC(sub_82644DD8);
PPC_FUNC_IMPL(__imp__sub_82644DD8) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644E18;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,17268
	ctx.r7.s64 = ctx.r8.s64 + 17268;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x82644E2C;
	sub_82659E28(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,17244
	ctx.r4.s64 = ctx.r6.s64 + 17244;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82644E44;
	sub_82633D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// stw r11,1232(r31)
	PPC_STORE_U32(r31.u32 + 1232, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,1236(r31)
	PPC_STORE_U16(r31.u32 + 1236, r11.u16);
	// sth r11,1238(r31)
	PPC_STORE_U16(r31.u32 + 1238, r11.u16);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
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

__attribute__((alias("__imp__sub_82644E8C"))) PPC_WEAK_FUNC(sub_82644E8C);
PPC_FUNC_IMPL(__imp__sub_82644E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644E90"))) PPC_WEAK_FUNC(sub_82644E90);
PPC_FUNC_IMPL(__imp__sub_82644E90) {
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
	// lhz r11,1238(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1238);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ebc
	if (cr6.eq) goto loc_82644EBC;
	// lwz r3,1232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1232);
	// bl 0x82130588
	ctx.lr = 0x82644EBC;
	sub_82130588(ctx, base);
loc_82644EBC:
	// lhz r11,1218(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1218);
	// addi r31,r30,1024
	r31.s64 = r30.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ed4
	if (cr6.eq) goto loc_82644ED4;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644ED4;
	sub_82130588(ctx, base);
loc_82644ED4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644EDC;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1002);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ef4
	if (cr6.eq) goto loc_82644EF4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644EF4;
	sub_82130588(ctx, base);
loc_82644EF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82644EFC;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82644F04;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82644F1C"))) PPC_WEAK_FUNC(sub_82644F1C);
PPC_FUNC_IMPL(__imp__sub_82644F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644F20"))) PPC_WEAK_FUNC(sub_82644F20);
PPC_FUNC_IMPL(__imp__sub_82644F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x82644F28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r27,r30,1232
	r27.s64 = r30.s64 + 1232;
	// lhz r11,1236(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1236);
	// lwz r9,1232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1232);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82644f68
	if (cr6.eq) goto loc_82644F68;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82644F54:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82644f54
	if (!cr6.eq) goto loc_82644F54;
loc_82644F68:
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
	// lwz r11,1240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1240);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82645060
	if (cr6.gt) goto loc_82645060;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,18072
	r29.s64 = ctx.r10.s64 + 18072;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,20392
	r12.s64 = r12.s64 + 20392;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82644FB8;
	case 1:
		goto loc_82644FDC;
	case 2:
		goto loc_82645000;
	case 3:
		goto loc_82645040;
	default:
		__builtin_unreachable();
	}
	// lwz r19,20408(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20408);
	// lwz r19,20444(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20444);
	// lwz r19,20480(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20480);
	// lwz r19,20544(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20544);
loc_82644FB8:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// addi r5,r10,-4680
	ctx.r5.s64 = ctx.r10.s64 + -4680;
	// addi r4,r9,18072
	ctx.r4.s64 = ctx.r9.s64 + 18072;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8264505c
	goto loc_8264505C;
loc_82644FDC:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// addi r4,r9,18072
	ctx.r4.s64 = ctx.r9.s64 + 18072;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8264505c
	goto loc_8264505C;
loc_82645000:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82645038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x82645060
	if (cr6.gt) goto loc_82645060;
loc_82645040:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264505C:
	// bctrl 
	ctx.lr = 0x82645060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82645060:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82645078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82645128
	if (cr6.eq) goto loc_82645128;
	// stw r31,864(r30)
	PPC_STORE_U32(r30.u32 + 864, r31.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,24324
	ctx.r4.s64 = r11.s64 + 24324;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82645098;
	sub_8262FFE0(ctx, base);
	// addi r29,r30,672
	r29.s64 = r30.s64 + 672;
	// li r31,0
	r31.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x826450A8;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8264515c
	if (!cr6.gt) goto loc_8264515C;
	// lis r28,-32120
	r28.s64 = -2105016320;
loc_826450B4:
	// lwz r3,-27856(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826450BC;
	sub_8238EC00(ctx, base);
	// lwz r11,864(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826450E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82389800
	ctx.lr = 0x826450EC;
	sub_82389800(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lhz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 16);
	// extsh r26,r7
	r26.s64 = ctx.r7.s16;
	// bl 0x8262e420
	ctx.lr = 0x82645104;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r26,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r26.u32);
	// bl 0x82631f88
	ctx.lr = 0x82645118;
	sub_82631F88(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x826450b4
	if (cr6.lt) goto loc_826450B4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82645128:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r31,r30,256
	r31.s64 = r30.s64 + 256;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82645140;
	sub_8262FFE0(ctx, base);
	// lwz r10,256(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645154;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,864(r30)
	PPC_STORE_U32(r30.u32 + 864, ctx.r8.u32);
loc_8264515C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82645164"))) PPC_WEAK_FUNC(sub_82645164);
PPC_FUNC_IMPL(__imp__sub_82645164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645168"))) PPC_WEAK_FUNC(sub_82645168);
PPC_FUNC_IMPL(__imp__sub_82645168) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13784
	ctx.r4.s64 = ctx.r9.s64 + 13784;
	// addi r8,r11,24348
	ctx.r8.s64 = r11.s64 + 24348;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,35
	ctx.r6.s64 = 35;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826451A4;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,18092
	ctx.r7.s64 = ctx.r8.s64 + 18092;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1000(r31)
	PPC_STORE_U16(r31.u32 + 1000, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1002(r31)
	PPC_STORE_U16(r31.u32 + 1002, r11.u16);
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x826451FC;
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

__attribute__((alias("__imp__sub_82645214"))) PPC_WEAK_FUNC(sub_82645214);
PPC_FUNC_IMPL(__imp__sub_82645214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645218"))) PPC_WEAK_FUNC(sub_82645218);
PPC_FUNC_IMPL(__imp__sub_82645218) {
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
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645240
	if (cr6.eq) goto loc_82645240;
	// lwz r3,1020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// bl 0x82130588
	ctx.lr = 0x82645240;
	sub_82130588(ctx, base);
loc_82645240:
	// lhz r11,1018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1018);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645254
	if (cr6.eq) goto loc_82645254;
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// bl 0x82130588
	ctx.lr = 0x82645254;
	sub_82130588(ctx, base);
loc_82645254:
	// lhz r11,1010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1010);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645268
	if (cr6.eq) goto loc_82645268;
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// bl 0x82130588
	ctx.lr = 0x82645268;
	sub_82130588(ctx, base);
loc_82645268:
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264527c
	if (cr6.eq) goto loc_8264527C;
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// bl 0x82130588
	ctx.lr = 0x8264527C;
	sub_82130588(ctx, base);
loc_8264527C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82645284;
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

__attribute__((alias("__imp__sub_82645298"))) PPC_WEAK_FUNC(sub_82645298);
PPC_FUNC_IMPL(__imp__sub_82645298) {
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
	ctx.lr = 0x826452A0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,107
	ctx.r10.s64 = 107;
	// addi r9,r11,3912
	ctx.r9.s64 = r11.s64 + 3912;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r22,r30,1004
	r22.s64 = r30.s64 + 1004;
	// addi r25,r30,996
	r25.s64 = r30.s64 + 996;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12440(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12440);
	// bl 0x8238e3a8
	ctx.lr = 0x826452E4;
	sub_8238E3A8(ctx, base);
	// lhz r6,1000(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 1000);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8264545c
	if (cr6.eq) goto loc_8264545C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r28,r30,1012
	r28.s64 = r30.s64 + 1012;
	// addi r27,r30,1020
	r27.s64 = r30.s64 + 1020;
	// li r31,0
	r31.s64 = 0;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r21,r11,5568
	r21.s64 = r11.s64 + 5568;
	// addi r24,r10,3998
	r24.s64 = ctx.r10.s64 + 3998;
loc_82645314:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bgt cr6,0x82645408
	if (cr6.gt) goto loc_82645408;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82645328;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82645344
	if (cr6.eq) goto loc_82645344;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x8264533C;
	sub_82633D40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82645348
	goto loc_82645348;
loc_82645344:
	// li r29,0
	r29.s64 = 0;
loc_82645348:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645354;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82645364;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82645380
	if (cr6.eq) goto loc_82645380;
	// stw r21,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r21.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8264537C;
	sub_826311F8(ctx, base);
	// b 0x82645384
	goto loc_82645384;
loc_82645380:
	// li r29,0
	r29.s64 = 0;
loc_82645384:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645390;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r3,-10244(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10244);
	// lwzx r4,r31,r11
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x822175d0
	ctx.lr = 0x826453A4;
	sub_822175D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826453fc
	if (cr6.eq) goto loc_826453FC;
	// lhz r11,852(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 852);
	// addi r10,r30,848
	ctx.r10.s64 = r30.s64 + 848;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,848(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,852(r30)
	PPC_STORE_U16(r30.u32 + 852, ctx.r8.u16);
	// lwzx r6,r31,r10
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// stwx r6,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r31,r5
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r31,r7
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
loc_826453FC:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,992(r30)
	PPC_STORE_U32(r30.u32 + 992, r11.u32);
loc_82645408:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82645428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r6,0(r22)
	ctx.r6.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwzx r3,r31,r7
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82645448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,1000(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 1000);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x82645314
	if (cr6.lt) goto loc_82645314;
loc_8264545C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82645464"))) PPC_WEAK_FUNC(sub_82645464);
PPC_FUNC_IMPL(__imp__sub_82645464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645468"))) PPC_WEAK_FUNC(sub_82645468);
PPC_FUNC_IMPL(__imp__sub_82645468) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13824
	ctx.r4.s64 = ctx.r9.s64 + 13824;
	// addi r8,r11,29164
	ctx.r8.s64 = r11.s64 + 29164;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826454A4;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,18900
	ctx.r7.s64 = ctx.r8.s64 + 18900;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r11.u32);
	// sth r11,1032(r31)
	PPC_STORE_U16(r31.u32 + 1032, r11.u16);
	// sth r11,1034(r31)
	PPC_STORE_U16(r31.u32 + 1034, r11.u16);
	// stw r11,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r11.u32);
	// sth r11,1040(r31)
	PPC_STORE_U16(r31.u32 + 1040, r11.u16);
	// sth r11,1042(r31)
	PPC_STORE_U16(r31.u32 + 1042, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x82645510;
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

__attribute__((alias("__imp__sub_82645528"))) PPC_WEAK_FUNC(sub_82645528);
PPC_FUNC_IMPL(__imp__sub_82645528) {
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
	ctx.lr = 0x82645530;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r9,118
	ctx.r9.s64 = 118;
	// addi r8,r10,3924
	ctx.r8.s64 = ctx.r10.s64 + 3924;
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lwz r11,996(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r21,r31,1012
	r21.s64 = r31.s64 + 1012;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r26,r31,1004
	r26.s64 = r31.s64 + 1004;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-12440(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12440);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// bl 0x8238e3a8
	ctx.lr = 0x82645574;
	sub_8238E3A8(ctx, base);
	// lhz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r25,0
	r25.s64 = 0;
	// addi r19,r11,19760
	r19.s64 = r11.s64 + 19760;
	// addi r18,r10,19736
	r18.s64 = ctx.r10.s64 + 19736;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82645794
	if (cr6.eq) goto loc_82645794;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r27,r31,1028
	r27.s64 = r31.s64 + 1028;
	// li r30,0
	r30.s64 = 0;
	// addi r20,r11,5568
	r20.s64 = r11.s64 + 5568;
	// addi r23,r10,19720
	r23.s64 = ctx.r10.s64 + 19720;
	// addi r22,r9,19704
	r22.s64 = ctx.r9.s64 + 19704;
	// addi r24,r8,3998
	r24.s64 = ctx.r8.s64 + 3998;
loc_826455BC:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// bgt cr6,0x82645698
	if (cr6.gt) goto loc_82645698;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826455D0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826455ec
	if (cr6.eq) goto loc_826455EC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x826455E4;
	sub_82633D40(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x826455f0
	goto loc_826455F0;
loc_826455EC:
	// li r28,0
	r28.s64 = 0;
loc_826455F0:
	// addi r29,r31,1020
	r29.s64 = r31.s64 + 1020;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645600;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// bl 0x82130528
	ctx.lr = 0x82645610;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8264562c
	if (cr6.eq) goto loc_8264562C;
	// stw r20,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r20.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x82645628;
	sub_826311F8(ctx, base);
	// b 0x82645630
	goto loc_82645630;
loc_8264562C:
	// li r28,0
	r28.s64 = 0;
loc_82645630:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x8264563C;
	sub_8262E420(ctx, base);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r6,r30,r10
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r30,r5
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r5.u32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r7,188(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r30,r8
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// stwx r11,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
loc_82645698:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x826456A8;
	sub_823DC018(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_826456B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826456d8
	if (cr6.eq) goto loc_826456D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826456b4
	if (cr6.eq) goto loc_826456B4;
loc_826456D8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826456fc
	if (!cr6.eq) goto loc_826456FC;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826456FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826456FC:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x8264570C;
	sub_823DC018(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82645718:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8264573c
	if (cr6.eq) goto loc_8264573C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645718
	if (cr6.eq) goto loc_82645718;
loc_8264573C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645760
	if (!cr6.eq) goto loc_82645760;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82645760:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwzx r4,r30,r10
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82645780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r25,r7
	cr6.compare<int32_t>(r25.s32, ctx.r7.s32, xer);
	// blt cr6,0x826455bc
	if (cr6.lt) goto loc_826455BC;
loc_82645794:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x826457e4
	if (!cr6.gt) goto loc_826457E4;
	// lhz r11,1008(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x826457e4
	if (!cr6.eq) goto loc_826457E4;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826457C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1020(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826457E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826457E4:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826457F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82645800"))) PPC_WEAK_FUNC(sub_82645800);
PPC_FUNC_IMPL(__imp__sub_82645800) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,28372
	ctx.r8.s64 = r11.s64 + 28372;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264583C;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,19780
	ctx.r7.s64 = ctx.r8.s64 + 19780;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r11.u32);
	// sth r11,1032(r31)
	PPC_STORE_U16(r31.u32 + 1032, r11.u16);
	// sth r11,1034(r31)
	PPC_STORE_U16(r31.u32 + 1034, r11.u16);
	// stw r11,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r11.u32);
	// sth r11,1040(r31)
	PPC_STORE_U16(r31.u32 + 1040, r11.u16);
	// sth r11,1042(r31)
	PPC_STORE_U16(r31.u32 + 1042, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x826458A4;
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

__attribute__((alias("__imp__sub_826458BC"))) PPC_WEAK_FUNC(sub_826458BC);
PPC_FUNC_IMPL(__imp__sub_826458BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826458C0"))) PPC_WEAK_FUNC(sub_826458C0);
PPC_FUNC_IMPL(__imp__sub_826458C0) {
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
	// lhz r11,1042(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1042);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826458e8
	if (cr6.eq) goto loc_826458E8;
	// lwz r3,1036(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// bl 0x82130588
	ctx.lr = 0x826458E8;
	sub_82130588(ctx, base);
loc_826458E8:
	// lhz r11,1034(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1034);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826458fc
	if (cr6.eq) goto loc_826458FC;
	// lwz r3,1028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// bl 0x82130588
	ctx.lr = 0x826458FC;
	sub_82130588(ctx, base);
loc_826458FC:
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645910
	if (cr6.eq) goto loc_82645910;
	// lwz r3,1020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// bl 0x82130588
	ctx.lr = 0x82645910;
	sub_82130588(ctx, base);
loc_82645910:
	// lhz r11,1018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1018);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645924
	if (cr6.eq) goto loc_82645924;
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// bl 0x82130588
	ctx.lr = 0x82645924;
	sub_82130588(ctx, base);
loc_82645924:
	// lhz r11,1010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1010);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645938
	if (cr6.eq) goto loc_82645938;
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// bl 0x82130588
	ctx.lr = 0x82645938;
	sub_82130588(ctx, base);
loc_82645938:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82645940;
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

__attribute__((alias("__imp__sub_82645954"))) PPC_WEAK_FUNC(sub_82645954);
PPC_FUNC_IMPL(__imp__sub_82645954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645958"))) PPC_WEAK_FUNC(sub_82645958);
PPC_FUNC_IMPL(__imp__sub_82645958) {
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
	ctx.lr = 0x82645960;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r9,114
	ctx.r9.s64 = 114;
	// addi r8,r10,5392
	ctx.r8.s64 = ctx.r10.s64 + 5392;
	// stb r9,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r9.u8);
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lwz r11,996(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r22,r31,1004
	r22.s64 = r31.s64 + 1004;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// addi r6,r31,1012
	ctx.r6.s64 = r31.s64 + 1012;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lwz r3,-12440(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12440);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// sth r11,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r11.u16);
	// bl 0x8238e3a8
	ctx.lr = 0x826459A4;
	sub_8238E3A8(ctx, base);
	// lhz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r21,r24
	r21.u64 = r24.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// beq cr6,0x82645de4
	if (cr6.eq) goto loc_82645DE4;
	// lis r27,-32247
	r27.s64 = -2113339392;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r27,20772
	ctx.r6.s64 = r27.s64 + 20772;
	// addi r11,r11,5568
	r11.s64 = r11.s64 + 5568;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r29,-32247
	r29.s64 = -2113339392;
	// lis r28,-32247
	r28.s64 = -2113339392;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lis r30,-32247
	r30.s64 = -2113339392;
	// lis r26,-32247
	r26.s64 = -2113339392;
	// lis r25,-32256
	r25.s64 = -2113929216;
	// addi r10,r10,20756
	ctx.r10.s64 = ctx.r10.s64 + 20756;
	// addi r9,r9,20740
	ctx.r9.s64 = ctx.r9.s64 + 20740;
	// addi r3,r3,20716
	ctx.r3.s64 = ctx.r3.s64 + 20716;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r11,r29,20700
	r11.s64 = r29.s64 + 20700;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r17,r28,20684
	r17.s64 = r28.s64 + 20684;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r23,r31,1028
	r23.s64 = r31.s64 + 1028;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r16,r8,23424
	r16.s64 = ctx.r8.s64 + 23424;
	// addi r15,r7,20664
	r15.s64 = ctx.r7.s64 + 20664;
	// addi r20,r6,20648
	r20.s64 = ctx.r6.s64 + 20648;
	// addi r14,r5,20632
	r14.s64 = ctx.r5.s64 + 20632;
	// addi r19,r4,20616
	r19.s64 = ctx.r4.s64 + 20616;
	// addi r18,r30,20600
	r18.s64 = r30.s64 + 20600;
	// addi r27,r26,20584
	r27.s64 = r26.s64 + 20584;
	// addi r28,r25,3998
	r28.s64 = r25.s64 + 3998;
loc_82645A50:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r26,84(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bgt cr6,0x82645b34
	if (cr6.gt) goto loc_82645B34;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82645A68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82645a84
	if (cr6.eq) goto loc_82645A84;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x82645A7C;
	sub_82633D40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82645a88
	goto loc_82645A88;
loc_82645A84:
	// li r29,0
	r29.s64 = 0;
loc_82645A88:
	// addi r30,r31,1020
	r30.s64 = r31.s64 + 1020;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645A98;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82645AA8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82645ac8
	if (cr6.eq) goto loc_82645AC8;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x826311f8
	ctx.lr = 0x82645AC4;
	sub_826311F8(ctx, base);
	// b 0x82645acc
	goto loc_82645ACC;
loc_82645AC8:
	// li r29,0
	r29.s64 = 0;
loc_82645ACC:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645AD8;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r6,r24,r10
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + ctx.r10.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r23)
	ctx.r7.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r11,r24,r5
	r11.u64 = PPC_LOAD_U32(r24.u32 + ctx.r5.u32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r24,r7
	r11.u64 = PPC_LOAD_U32(r24.u32 + ctx.r7.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
loc_82645B34:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82645B44;
	sub_823DC018(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
loc_82645B50:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645b74
	if (cr6.eq) goto loc_82645B74;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645b50
	if (cr6.eq) goto loc_82645B50;
loc_82645B74:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645b98
	if (!cr6.eq) goto loc_82645B98;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwzx r3,r11,r24
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82645B98:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82645BA8;
	sub_823DC018(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
loc_82645BB4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645bd8
	if (cr6.eq) goto loc_82645BD8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645bb4
	if (cr6.eq) goto loc_82645BB4;
loc_82645BD8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645c00
	if (!cr6.eq) goto loc_82645C00;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwzx r3,r11,r24
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r21,1
	r21.s64 = 1;
loc_82645C00:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82645C10;
	sub_823DC018(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
loc_82645C1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645c40
	if (cr6.eq) goto loc_82645C40;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645c1c
	if (cr6.eq) goto loc_82645C1C;
loc_82645C40:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645c68
	if (!cr6.eq) goto loc_82645C68;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwzx r3,r11,r24
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r21,1
	r21.s64 = 1;
loc_82645C68:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82645C78;
	sub_823DC018(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
loc_82645C84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645ca8
	if (cr6.eq) goto loc_82645CA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645c84
	if (cr6.eq) goto loc_82645C84;
loc_82645CA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645cd0
	if (!cr6.eq) goto loc_82645CD0;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645CCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r21,1
	r21.s64 = 1;
loc_82645CD0:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82645CE0;
	sub_823DC018(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwzx r11,r24,r11
	r11.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
loc_82645CEC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645d10
	if (cr6.eq) goto loc_82645D10;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645cec
	if (cr6.eq) goto loc_82645CEC;
loc_82645D10:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645d38
	if (!cr6.eq) goto loc_82645D38;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwzx r3,r11,r24
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r21,1
	r21.s64 = 1;
loc_82645D38:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645da8
	if (cr6.eq) goto loc_82645DA8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r11,r24,r9
	r11.u64 = PPC_LOAD_U32(r24.u32 + ctx.r9.u32);
loc_82645D54:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82645d78
	if (cr6.eq) goto loc_82645D78;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645d54
	if (cr6.eq) goto loc_82645D54;
loc_82645D78:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwzx r3,r24,r11
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bne cr6,0x82645d9c
	if (!cr6.eq) goto loc_82645D9C;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82645dc8
	goto loc_82645DC8;
loc_82645D9C:
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82645dc8
	goto loc_82645DC8;
loc_82645DA8:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwzx r3,r24,r11
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r4,r24,r9
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + ctx.r9.u32);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82645DC8:
	// bctrl 
	ctx.lr = 0x82645DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,1008(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82645a50
	if (cr6.lt) goto loc_82645A50;
loc_82645DE4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82645DF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82645E0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82645E14"))) PPC_WEAK_FUNC(sub_82645E14);
PPC_FUNC_IMPL(__imp__sub_82645E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645E18"))) PPC_WEAK_FUNC(sub_82645E18);
PPC_FUNC_IMPL(__imp__sub_82645E18) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r4,r10,13764
	ctx.r4.s64 = ctx.r10.s64 + 13764;
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
	// bl 0x82654318
	ctx.lr = 0x82645E50;
	sub_82654318(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,20796
	ctx.r8.s64 = ctx.r9.s64 + 20796;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// addi r4,r7,25024
	ctx.r4.s64 = ctx.r7.s64 + 25024;
	// sth r11,1000(r31)
	PPC_STORE_U16(r31.u32 + 1000, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1002(r31)
	PPC_STORE_U16(r31.u32 + 1002, r11.u16);
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x82645EA8;
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

__attribute__((alias("__imp__sub_82645EC0"))) PPC_WEAK_FUNC(sub_82645EC0);
PPC_FUNC_IMPL(__imp__sub_82645EC0) {
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
	ctx.lr = 0x82645EC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13744
	ctx.r4.s64 = ctx.r9.s64 + 13744;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82645EF8;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r7,r8,21724
	ctx.r7.s64 = ctx.r8.s64 + 21724;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,21688
	ctx.r4.s64 = ctx.r6.s64 + 21688;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82645F1C;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,21660
	ctx.r4.s64 = ctx.r4.s64 + 21660;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x82645F34;
	sub_82633D40(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,21628
	ctx.r4.s64 = ctx.r3.s64 + 21628;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x82645F4C;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,21600
	ctx.r4.s64 = r11.s64 + 21600;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x82645F64;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82645FD4"))) PPC_WEAK_FUNC(sub_82645FD4);
PPC_FUNC_IMPL(__imp__sub_82645FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645FD8"))) PPC_WEAK_FUNC(sub_82645FD8);
PPC_FUNC_IMPL(__imp__sub_82645FD8) {
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
	ctx.lr = 0x82645FE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r4,r9,13744
	ctx.r4.s64 = ctx.r9.s64 + 13744;
	// addi r8,r10,28372
	ctx.r8.s64 = ctx.r10.s64 + 28372;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,20
	ctx.r6.s64 = 20;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82646014;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r7,r8,22532
	ctx.r7.s64 = ctx.r8.s64 + 22532;
	// addi r30,r27,1084
	r30.s64 = r27.s64 + 1084;
	// li r28,20
	r28.s64 = 20;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// addi r26,r11,5568
	r26.s64 = r11.s64 + 5568;
loc_82646030:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82646038;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82646050
	if (cr6.eq) goto loc_82646050;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x8264604C;
	sub_82633D40(ctx, base);
	// b 0x82646054
	goto loc_82646054;
loc_82646050:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82646054:
	// stw r3,-80(r30)
	PPC_STORE_U32(r30.u32 + -80, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82646060;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8264607c
	if (cr6.eq) goto loc_8264607C;
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826311f8
	ctx.lr = 0x82646078;
	sub_826311F8(ctx, base);
	// b 0x82646080
	goto loc_82646080;
loc_8264607C:
	// li r31,0
	r31.s64 = 0;
loc_82646080:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82646030
	if (!cr0.eq) goto loc_82646030;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,25024
	ctx.r4.s64 = r11.s64 + 25024;
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// bl 0x826347f0
	ctx.lr = 0x826460A4;
	sub_826347F0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,996(r27)
	PPC_STORE_U32(r27.u32 + 996, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826460B8"))) PPC_WEAK_FUNC(sub_826460B8);
PPC_FUNC_IMPL(__imp__sub_826460B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r9,r31,848
	ctx.r9.s64 = r31.s64 + 848;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82646108
	if (cr6.eq) goto loc_82646108;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_826460F4:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826460f4
	if (!cr6.eq) goto loc_826460F4;
loc_82646108:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// li r3,20
	ctx.r3.s64 = 20;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r7,r31,1004
	ctx.r7.s64 = r31.s64 + 1004;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
loc_82646128:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r11,188
	ctx.r9.s64 = r11.s64 + 188;
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r11,r10,2
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82646164
	if (cr6.eq) goto loc_82646164;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_82646150:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r30,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, r30.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82646150
	if (!cr6.eq) goto loc_82646150;
loc_82646164:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// bne 0x82646128
	if (!cr0.eq) goto loc_82646128;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x82646244
	if (cr6.gt) goto loc_82646244;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,24996
	r12.s64 = r12.s64 + 24996;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_826461B4;
	case 1:
		goto loc_826461DC;
	case 2:
		goto loc_82646204;
	case 3:
		goto loc_82646218;
	default:
		__builtin_unreachable();
	}
	// lwz r19,25012(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 25012);
	// lwz r19,25052(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 25052);
	// lwz r19,25092(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 25092);
	// lwz r19,25112(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 25112);
loc_826461B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r3.u32);
	// stw r10,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-4244
	ctx.r4.s64 = ctx.r9.s64 + -4244;
	// lwz r8,788(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82646240
	goto loc_82646240;
loc_826461DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// stw r10,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-4256
	ctx.r4.s64 = ctx.r9.s64 + -4256;
	// lwz r8,788(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82646240
	goto loc_82646240;
loc_82646204:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r10,35
	ctx.r10.s64 = 35;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r4,r8,-4280
	ctx.r4.s64 = ctx.r8.s64 + -4280;
	// b 0x82646228
	goto loc_82646228;
loc_82646218:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r10,50
	ctx.r10.s64 = 50;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r4,r8,-4268
	ctx.r4.s64 = ctx.r8.s64 + -4268;
loc_82646228:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r9.u32);
	// stw r10,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r10.u32);
	// lwz r7,788(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82646240:
	// bctrl 
	ctx.lr = 0x82646244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82646244:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82642d30
	ctx.lr = 0x8264624C;
	sub_82642D30(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82646260;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82646274;
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

__attribute__((alias("__imp__sub_8264628C"))) PPC_WEAK_FUNC(sub_8264628C);
PPC_FUNC_IMPL(__imp__sub_8264628C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646290"))) PPC_WEAK_FUNC(sub_82646290);
PPC_FUNC_IMPL(__imp__sub_82646290) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82630318
	ctx.lr = 0x826462B0;
	sub_82630318(ctx, base);
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826460b8
	ctx.lr = 0x826462C0;
	sub_826460B8(ctx, base);
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

__attribute__((alias("__imp__sub_826462D8"))) PPC_WEAK_FUNC(sub_826462D8);
PPC_FUNC_IMPL(__imp__sub_826462D8) {
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
	ctx.lr = 0x826462E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
	// addi r4,r9,24144
	ctx.r4.s64 = ctx.r9.s64 + 24144;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82646314;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r7,r8,23340
	ctx.r7.s64 = ctx.r8.s64 + 23340;
	// addi r29,r11,-27520
	r29.s64 = r11.s64 + -27520;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// addi r30,r28,992
	r30.s64 = r28.s64 + 992;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82646330:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82646338;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82646350
	if (cr6.eq) goto loc_82646350;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x8264634C;
	sub_82633D40(ctx, base);
	// b 0x82646354
	goto loc_82646354;
loc_82646350:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82646354:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264636C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r9,r29,32
	ctx.r9.s64 = r29.s64 + 32;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82646330
	if (cr6.lt) goto loc_82646330;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8264638C"))) PPC_WEAK_FUNC(sub_8264638C);
PPC_FUNC_IMPL(__imp__sub_8264638C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646390"))) PPC_WEAK_FUNC(sub_82646390);
PPC_FUNC_IMPL(__imp__sub_82646390) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,852(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 852);
	// addi r11,r3,848
	r11.s64 = ctx.r3.s64 + 848;
	// lwz r9,848(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x826463c8
	if (cr6.eq) goto loc_826463C8;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_826463B4:
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stwx r6,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r6.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x826463b4
	if (!cr6.eq) goto loc_826463B4;
loc_826463C8:
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rotlwi r8,r5,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// lwz r7,992(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 992);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// rotlwi r8,r6,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r10,996(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 996);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// rotlwi r10,r7,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,1000(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1000);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r6,1004(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1004);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// lwz r7,1008(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1008);
	// stwx r7,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r8,1012(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1012);
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// rotlwi r10,r7,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,1016(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1016);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r6,1020(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1020);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826464D8"))) PPC_WEAK_FUNC(sub_826464D8);
PPC_FUNC_IMPL(__imp__sub_826464D8) {
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
	ctx.lr = 0x826464E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,25024
	ctx.r4.s64 = ctx.r9.s64 + 25024;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82646510;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r7,r8,24220
	ctx.r7.s64 = ctx.r8.s64 + 24220;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,24188
	ctx.r4.s64 = ctx.r6.s64 + 24188;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82646534;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,24168
	ctx.r4.s64 = ctx.r4.s64 + 24168;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264654C;
	sub_82633D40(ctx, base);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82634b60
	ctx.lr = 0x82646554;
	sub_82634B60(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82646594"))) PPC_WEAK_FUNC(sub_82646594);
PPC_FUNC_IMPL(__imp__sub_82646594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646598"))) PPC_WEAK_FUNC(sub_82646598);
PPC_FUNC_IMPL(__imp__sub_82646598) {
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
	// addi r3,r30,1408
	ctx.r3.s64 = r30.s64 + 1408;
	// bl 0x8221fbc8
	ctx.lr = 0x826465B8;
	sub_8221FBC8(ctx, base);
	// lhz r11,1394(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1394);
	// addi r31,r30,1200
	r31.s64 = r30.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826465d0
	if (cr6.eq) goto loc_826465D0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826465D0;
	sub_82130588(ctx, base);
loc_826465D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826465D8;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1186);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826465f0
	if (cr6.eq) goto loc_826465F0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826465F0;
	sub_82130588(ctx, base);
loc_826465F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826465F8;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646600;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82646618"))) PPC_WEAK_FUNC(sub_82646618);
PPC_FUNC_IMPL(__imp__sub_82646618) {
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
	ctx.lr = 0x82646620;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82215a60
	ctx.lr = 0x8264662C;
	sub_82215A60(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// addi r31,r29,848
	r31.s64 = r29.s64 + 848;
	// stb r28,3200(r29)
	PPC_STORE_U8(r29.u32 + 3200, r28.u8);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// lhz r11,852(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8264666c
	if (cr6.eq) goto loc_8264666C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82646658:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82646658
	if (!cr6.eq) goto loc_82646658;
loc_8264666C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// ori r5,r9,27761
	ctx.r5.u64 = ctx.r9.u64 | 27761;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10020(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10020);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stbx r3,r11,r5
	PPC_STORE_U8(r11.u32 + ctx.r5.u32, ctx.r3.u8);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r5,r9,25064
	ctx.r5.s64 = ctx.r9.s64 + 25064;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// addi r4,r8,25048
	ctx.r4.s64 = ctx.r8.s64 + 25048;
	// bl 0x822183b0
	ctx.lr = 0x826466B4;
	sub_822183B0(ctx, base);
	// lwz r7,1200(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 1200);
	// addi r30,r29,1200
	r30.s64 = r29.s64 + 1200;
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826466CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1200);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,25036
	ctx.r4.s64 = ctx.r5.s64 + 25036;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826466E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826466F8;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822a8170
	ctx.lr = 0x82646704;
	sub_822A8170(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// lfs f0,27644(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x822a3998
	ctx.lr = 0x82646728;
	sub_822A3998(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822abd10
	ctx.lr = 0x82646734;
	sub_822ABD10(ctx, base);
	// stw r28,3224(r29)
	PPC_STORE_U32(r29.u32 + 3224, r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,17268(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82646748;
	sub_821E80F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826467b0
	if (cr6.eq) goto loc_826467B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a3998
	ctx.lr = 0x82646760;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x822a93a8
	ctx.lr = 0x8264676C;
	sub_822A93A8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a6198
	ctx.lr = 0x8264677C;
	sub_822A6198(ctx, base);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// addi r3,r29,992
	ctx.r3.s64 = r29.s64 + 992;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,664(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lhz r8,14(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 14);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,992(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// beq cr6,0x826467a8
	if (cr6.eq) goto loc_826467A8;
	// li r4,1
	ctx.r4.s64 = 1;
loc_826467A8:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826467B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826467B0:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,992
	ctx.r8.s64 = r29.s64 + 992;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r3,r7,-15924
	ctx.r3.s64 = ctx.r7.s64 + -15924;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x821e6800
	ctx.lr = 0x826467F4;
	sub_821E6800(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826467FC"))) PPC_WEAK_FUNC(sub_826467FC);
PPC_FUNC_IMPL(__imp__sub_826467FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646800"))) PPC_WEAK_FUNC(sub_82646800);
PPC_FUNC_IMPL(__imp__sub_82646800) {
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
	ctx.lr = 0x82646808;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r4,r9,25880
	ctx.r4.s64 = ctx.r9.s64 + 25880;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r8,r10,29228
	ctx.r8.s64 = ctx.r10.s64 + 29228;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264683C;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,996
	ctx.r3.s64 = r31.s64 + 996;
	// addi r7,r8,25076
	ctx.r7.s64 = ctx.r8.s64 + 25076;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x827407d8
	ctx.lr = 0x82646850;
	sub_827407D8(ctx, base);
	// addi r30,r31,4176
	r30.s64 = r31.s64 + 4176;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82646864;
	sub_82633D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r6,13
	ctx.r6.s64 = 13;
	// li r5,-1
	ctx.r5.s64 = -1;
	// stb r11,4384(r31)
	PPC_STORE_U8(r31.u32 + 4384, r11.u8);
	// stb r11,4385(r31)
	PPC_STORE_U8(r31.u32 + 4385, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,4386(r31)
	PPC_STORE_U8(r31.u32 + 4386, r11.u8);
	// stw r11,4164(r31)
	PPC_STORE_U32(r31.u32 + 4164, r11.u32);
	// stw r11,4172(r31)
	PPC_STORE_U32(r31.u32 + 4172, r11.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// stw r6,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, ctx.r6.u32);
	// stw r5,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r5.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826468B4"))) PPC_WEAK_FUNC(sub_826468B4);
PPC_FUNC_IMPL(__imp__sub_826468B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826468B8"))) PPC_WEAK_FUNC(sub_826468B8);
PPC_FUNC_IMPL(__imp__sub_826468B8) {
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
	ctx.lr = 0x826468C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
	// addi r4,r9,26736
	ctx.r4.s64 = ctx.r9.s64 + 26736;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826468F4;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r27,r31,992
	r27.s64 = r31.s64 + 992;
	// addi r7,r8,25932
	ctx.r7.s64 = ctx.r8.s64 + 25932;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x82646914;
	sub_82633D40(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// stw r6,1232(r31)
	PPC_STORE_U32(r31.u32 + 1232, ctx.r6.u32);
	// bl 0x82634b60
	ctx.lr = 0x82646924;
	sub_82634B60(ctx, base);
	// addi r28,r31,1200
	r28.s64 = r31.s64 + 1200;
	// li r29,8
	r29.s64 = 8;
loc_8264692C:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82646934;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264694c
	if (cr6.eq) goto loc_8264694C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82646948;
	sub_82633D40(ctx, base);
	// b 0x82646950
	goto loc_82646950;
loc_8264694C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82646950:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8264692c
	if (!cr0.eq) goto loc_8264692C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r10,25900
	ctx.r4.s64 = ctx.r10.s64 + 25900;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264697C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82646988"))) PPC_WEAK_FUNC(sub_82646988);
PPC_FUNC_IMPL(__imp__sub_82646988) {
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
	ctx.lr = 0x82646990;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r28,848
	r31.s64 = r28.s64 + 848;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826469d0
	if (cr6.eq) goto loc_826469D0;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826469BC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826469bc
	if (!cr6.eq) goto loc_826469BC;
loc_826469D0:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// stw r29,1232(r28)
	PPC_STORE_U32(r28.u32 + 1232, r29.u32);
	// bl 0x82388558
	ctx.lr = 0x826469F0;
	sub_82388558(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82646a94
	if (!cr6.gt) goto loc_82646A94;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r28,1200
	r30.s64 = r28.s64 + 1200;
	// addi r26,r11,3998
	r26.s64 = r11.s64 + 3998;
loc_82646A08:
	// cmpwi cr6,r29,7
	cr6.compare<int32_t>(r29.s32, 7, xer);
	// bge cr6,0x82646a94
	if (!cr6.lt) goto loc_82646A94;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82646A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82388568
	ctx.lr = 0x82646A2C;
	sub_82388568(ctx, base);
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82646a40
	if (cr6.eq) goto loc_82646A40;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82646a44
	goto loc_82646A44;
loc_82646A40:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_82646A44:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82646A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// stwx r5,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,1232(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1232);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,1232(r28)
	PPC_STORE_U32(r28.u32 + 1232, ctx.r4.u32);
	// blt cr6,0x82646a08
	if (cr6.lt) goto loc_82646A08;
loc_82646A94:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r28,992
	ctx.r8.s64 = r28.s64 + 992;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r28,672
	ctx.r3.s64 = r28.s64 + 672;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r5,672(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// lwz r4,1232(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 1232);
	// lwz r11,648(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82646ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82646AD4"))) PPC_WEAK_FUNC(sub_82646AD4);
PPC_FUNC_IMPL(__imp__sub_82646AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646AD8"))) PPC_WEAK_FUNC(sub_82646AD8);
PPC_FUNC_IMPL(__imp__sub_82646AD8) {
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
	// bl 0x82646988
	ctx.lr = 0x82646AF0;
	sub_82646988(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x82646AF8;
	sub_82653B30(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82646B0C"))) PPC_WEAK_FUNC(sub_82646B0C);
PPC_FUNC_IMPL(__imp__sub_82646B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646B10"))) PPC_WEAK_FUNC(sub_82646B10);
PPC_FUNC_IMPL(__imp__sub_82646B10) {
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
	// bl 0x82646988
	ctx.lr = 0x82646B28;
	sub_82646988(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826535f8
	ctx.lr = 0x82646B30;
	sub_826535F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82646B44"))) PPC_WEAK_FUNC(sub_82646B44);
PPC_FUNC_IMPL(__imp__sub_82646B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646B48"))) PPC_WEAK_FUNC(sub_82646B48);
PPC_FUNC_IMPL(__imp__sub_82646B48) {
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
	// addi r3,r30,1200
	ctx.r3.s64 = r30.s64 + 1200;
	// bl 0x8221fbc8
	ctx.lr = 0x82646B68;
	sub_8221FBC8(ctx, base);
	// lhz r11,1170(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1170);
	// addi r31,r30,976
	r31.s64 = r30.s64 + 976;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646b80
	if (cr6.eq) goto loc_82646B80;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646B80;
	sub_82130588(ctx, base);
loc_82646B80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646B88;
	sub_82633B00(ctx, base);
	// lhz r11,954(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 954);
	// addi r31,r30,944
	r31.s64 = r30.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646ba0
	if (cr6.eq) goto loc_82646BA0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82646BA0;
	sub_82130588(ctx, base);
loc_82646BA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82646BA8;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646BB0;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82646BC8"))) PPC_WEAK_FUNC(sub_82646BC8);
PPC_FUNC_IMPL(__imp__sub_82646BC8) {
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
	ctx.lr = 0x82646BD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r29,2688
	ctx.r3.s64 = r29.s64 + 2688;
	// bl 0x8221fbc8
	ctx.lr = 0x82646BE0;
	sub_8221FBC8(ctx, base);
	// lhz r11,2626(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 2626);
	// addi r31,r29,2432
	r31.s64 = r29.s64 + 2432;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646bf8
	if (cr6.eq) goto loc_82646BF8;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646BF8;
	sub_82130588(ctx, base);
loc_82646BF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646C00;
	sub_82633B00(ctx, base);
	// addi r31,r29,2432
	r31.s64 = r29.s64 + 2432;
	// li r30,5
	r30.s64 = 5;
loc_82646C08:
	// addi r31,r31,-240
	r31.s64 = r31.s64 + -240;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646c20
	if (cr6.eq) goto loc_82646C20;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646C20;
	sub_82130588(ctx, base);
loc_82646C20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646C28;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82646c08
	if (!cr0.lt) goto loc_82646C08;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646C38;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82646C40"))) PPC_WEAK_FUNC(sub_82646C40);
PPC_FUNC_IMPL(__imp__sub_82646C40) {
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
	ctx.lr = 0x82646C48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r29,1408
	ctx.r3.s64 = r29.s64 + 1408;
	// bl 0x8221fbc8
	ctx.lr = 0x82646C58;
	sub_8221FBC8(ctx, base);
	// addi r31,r29,1408
	r31.s64 = r29.s64 + 1408;
	// li r30,1
	r30.s64 = 1;
loc_82646C60:
	// addi r31,r31,-208
	r31.s64 = r31.s64 + -208;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646c78
	if (cr6.eq) goto loc_82646C78;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646C78;
	sub_82130588(ctx, base);
loc_82646C78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646C80;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82646c60
	if (!cr0.lt) goto loc_82646C60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646C90;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82646C98"))) PPC_WEAK_FUNC(sub_82646C98);
PPC_FUNC_IMPL(__imp__sub_82646C98) {
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
	// addi r3,r31,1504
	ctx.r3.s64 = r31.s64 + 1504;
	// addi r10,r11,3888
	ctx.r10.s64 = r11.s64 + 3888;
	// stw r10,1504(r31)
	PPC_STORE_U32(r31.u32 + 1504, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82646CC4;
	sub_821D2028(ctx, base);
	// lhz r9,1442(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 1442);
	// addi r30,r31,1248
	r30.s64 = r31.s64 + 1248;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82646cdc
	if (cr6.eq) goto loc_82646CDC;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646CDC;
	sub_82130588(ctx, base);
loc_82646CDC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646CE4;
	sub_82633B00(ctx, base);
	// lhz r11,1202(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1202);
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646cfc
	if (cr6.eq) goto loc_82646CFC;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646CFC;
	sub_82130588(ctx, base);
loc_82646CFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646D04;
	sub_82633B00(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82646D0C;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646D14;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82646D2C"))) PPC_WEAK_FUNC(sub_82646D2C);
PPC_FUNC_IMPL(__imp__sub_82646D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82646D30"))) PPC_WEAK_FUNC(sub_82646D30);
PPC_FUNC_IMPL(__imp__sub_82646D30) {
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
	ctx.lr = 0x82646D38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,1472
	r30.s64 = r31.s64 + 1472;
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// stw r29,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r29.u32);
	// lhz r11,1666(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1666);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646d64
	if (cr6.eq) goto loc_82646D64;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646D64;
	sub_82130588(ctx, base);
loc_82646D64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646D6C;
	sub_82633B00(ctx, base);
	// stw r29,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r29.u32);
	// lhz r11,1442(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1442);
	// addi r30,r31,1248
	r30.s64 = r31.s64 + 1248;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646d88
	if (cr6.eq) goto loc_82646D88;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646D88;
	sub_82130588(ctx, base);
loc_82646D88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646D90;
	sub_82633B00(ctx, base);
	// lhz r11,1202(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1202);
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646da8
	if (cr6.eq) goto loc_82646DA8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646DA8;
	sub_82130588(ctx, base);
loc_82646DA8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646DB0;
	sub_82633B00(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82646DB8;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646DC0;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82646DC8"))) PPC_WEAK_FUNC(sub_82646DC8);
PPC_FUNC_IMPL(__imp__sub_82646DC8) {
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
	ctx.lr = 0x82646DD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,1680
	r30.s64 = r31.s64 + 1680;
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// stw r29,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, r29.u32);
	// lhz r11,1874(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1874);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646dfc
	if (cr6.eq) goto loc_82646DFC;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646DFC;
	sub_82130588(ctx, base);
loc_82646DFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646E04;
	sub_82633B00(ctx, base);
	// stw r29,1664(r31)
	PPC_STORE_U32(r31.u32 + 1664, r29.u32);
	// lhz r11,1650(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1650);
	// addi r30,r31,1456
	r30.s64 = r31.s64 + 1456;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646e20
	if (cr6.eq) goto loc_82646E20;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646E20;
	sub_82130588(ctx, base);
loc_82646E20:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646E28;
	sub_82633B00(ctx, base);
	// lhz r11,1442(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1442);
	// addi r30,r31,1248
	r30.s64 = r31.s64 + 1248;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646e40
	if (cr6.eq) goto loc_82646E40;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646E40;
	sub_82130588(ctx, base);
loc_82646E40:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646E48;
	sub_82633B00(ctx, base);
	// lhz r11,1202(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1202);
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646e60
	if (cr6.eq) goto loc_82646E60;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646E60;
	sub_82130588(ctx, base);
loc_82646E60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646E68;
	sub_82633B00(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82646E70;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646E78;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82646E80"))) PPC_WEAK_FUNC(sub_82646E80);
PPC_FUNC_IMPL(__imp__sub_82646E80) {
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
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r30,1728
	r11.s64 = r30.s64 + 1728;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_82646EA8:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x82646ea8
	if (!cr0.lt) goto loc_82646EA8;
	// lhz r11,1650(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1650);
	// addi r31,r30,1456
	r31.s64 = r30.s64 + 1456;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646ed0
	if (cr6.eq) goto loc_82646ED0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646ED0;
	sub_82130588(ctx, base);
loc_82646ED0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646ED8;
	sub_82633B00(ctx, base);
	// lhz r11,1442(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1442);
	// addi r31,r30,1248
	r31.s64 = r30.s64 + 1248;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646ef0
	if (cr6.eq) goto loc_82646EF0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646EF0;
	sub_82130588(ctx, base);
loc_82646EF0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646EF8;
	sub_82633B00(ctx, base);
	// lhz r11,1202(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1202);
	// addi r31,r30,1008
	r31.s64 = r30.s64 + 1008;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646f10
	if (cr6.eq) goto loc_82646F10;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646F10;
	sub_82130588(ctx, base);
loc_82646F10:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646F18;
	sub_82633B00(ctx, base);
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82646F20;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646F28;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82646F40"))) PPC_WEAK_FUNC(sub_82646F40);
PPC_FUNC_IMPL(__imp__sub_82646F40) {
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
	// addi r31,r30,1152
	r31.s64 = r30.s64 + 1152;
	// lhz r11,1346(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1346);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646f70
	if (cr6.eq) goto loc_82646F70;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646F70;
	sub_82130588(ctx, base);
loc_82646F70:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646F78;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1138);
	// addi r31,r30,944
	r31.s64 = r30.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82646f90
	if (cr6.eq) goto loc_82646F90;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82646F90;
	sub_82130588(ctx, base);
loc_82646F90:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82646F98;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82646FA0;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82646FB8"))) PPC_WEAK_FUNC(sub_82646FB8);
PPC_FUNC_IMPL(__imp__sub_82646FB8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,-25064
	ctx.r5.s64 = r11.s64 + -25064;
	// addi r4,r10,28376
	ctx.r4.s64 = ctx.r10.s64 + 28376;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82646FF0;
	sub_82654318(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,27572
	ctx.r6.s64 = ctx.r7.s64 + 27572;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// lfs f13,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
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

__attribute__((alias("__imp__sub_82647038"))) PPC_WEAK_FUNC(sub_82647038);
PPC_FUNC_IMPL(__imp__sub_82647038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82647044"))) PPC_WEAK_FUNC(sub_82647044);
PPC_FUNC_IMPL(__imp__sub_82647044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82647048"))) PPC_WEAK_FUNC(sub_82647048);
PPC_FUNC_IMPL(__imp__sub_82647048) {
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
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8221fbc8
	ctx.lr = 0x8264706C;
	sub_8221FBC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r10,r11,4588
	ctx.r10.s64 = r11.s64 + 4588;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82647080;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82647088;
	sub_8221FCC8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826470a0
	if (cr6.eq) goto loc_826470A0;
	// bl 0x82130588
	ctx.lr = 0x8264709C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826470A0:
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

__attribute__((alias("__imp__sub_826470B8"))) PPC_WEAK_FUNC(sub_826470B8);
PPC_FUNC_IMPL(__imp__sub_826470B8) {
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
	// addi r10,r11,12916
	ctx.r10.s64 = r11.s64 + 12916;
	// lwz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826470f4
	if (cr6.eq) goto loc_826470F4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826470F4;
	sub_821EC060(ctx, base);
loc_826470F4:
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x826470FC;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82647104;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264711c
	if (cr6.eq) goto loc_8264711C;
	// bl 0x82130588
	ctx.lr = 0x82647118;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264711C:
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

__attribute__((alias("__imp__sub_82647134"))) PPC_WEAK_FUNC(sub_82647134);
PPC_FUNC_IMPL(__imp__sub_82647134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82647138"))) PPC_WEAK_FUNC(sub_82647138);
PPC_FUNC_IMPL(__imp__sub_82647138) {
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
	// bl 0x82644670
	ctx.lr = 0x82647158;
	sub_82644670(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647170
	if (cr6.eq) goto loc_82647170;
	// bl 0x82130588
	ctx.lr = 0x8264716C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647170:
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

__attribute__((alias("__imp__sub_82647188"))) PPC_WEAK_FUNC(sub_82647188);
PPC_FUNC_IMPL(__imp__sub_82647188) {
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
	// addi r9,r31,1000
	ctx.r9.s64 = r31.s64 + 1000;
	// lhz r11,1004(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1004);
	// lwz r8,1000(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826471dc
	if (cr6.eq) goto loc_826471DC;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_826471C8:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826471c8
	if (!cr6.eq) goto loc_826471C8;
loc_826471DC:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,1008
	ctx.r8.s64 = r31.s64 + 1008;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lhz r4,1012(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 1012);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647228
	if (cr6.eq) goto loc_82647228;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82647214:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647214
	if (!cr6.eq) goto loc_82647214;
loc_82647228:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
	// stw r9,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r9.u32);
	// bl 0x826446f0
	ctx.lr = 0x8264724C;
	sub_826446F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82647258;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_82647270"))) PPC_WEAK_FUNC(sub_82647270);
PPC_FUNC_IMPL(__imp__sub_82647270) {
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
	// lhz r11,1006(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1006);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826472a0
	if (cr6.eq) goto loc_826472A0;
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x826472A0;
	sub_82130588(ctx, base);
loc_826472A0:
	// lhz r11,998(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 998);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826472b4
	if (cr6.eq) goto loc_826472B4;
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// bl 0x82130588
	ctx.lr = 0x826472B4;
	sub_82130588(ctx, base);
loc_826472B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826472BC;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826472d4
	if (cr6.eq) goto loc_826472D4;
	// bl 0x82130588
	ctx.lr = 0x826472D0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826472D4:
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

__attribute__((alias("__imp__sub_826472EC"))) PPC_WEAK_FUNC(sub_826472EC);
PPC_FUNC_IMPL(__imp__sub_826472EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826472F0"))) PPC_WEAK_FUNC(sub_826472F0);
PPC_FUNC_IMPL(__imp__sub_826472F0) {
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
	// bl 0x82644b90
	ctx.lr = 0x82647310;
	sub_82644B90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647328
	if (cr6.eq) goto loc_82647328;
	// bl 0x82130588
	ctx.lr = 0x82647324;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647328:
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

__attribute__((alias("__imp__sub_82647340"))) PPC_WEAK_FUNC(sub_82647340);
PPC_FUNC_IMPL(__imp__sub_82647340) {
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
	// bl 0x82644e90
	ctx.lr = 0x82647360;
	sub_82644E90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647378
	if (cr6.eq) goto loc_82647378;
	// bl 0x82130588
	ctx.lr = 0x82647374;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647378:
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

__attribute__((alias("__imp__sub_82647390"))) PPC_WEAK_FUNC(sub_82647390);
PPC_FUNC_IMPL(__imp__sub_82647390) {
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
	// bl 0x82645218
	ctx.lr = 0x826473B0;
	sub_82645218(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826473c8
	if (cr6.eq) goto loc_826473C8;
	// bl 0x82130588
	ctx.lr = 0x826473C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826473C8:
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

__attribute__((alias("__imp__sub_826473E0"))) PPC_WEAK_FUNC(sub_826473E0);
PPC_FUNC_IMPL(__imp__sub_826473E0) {
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
	// bl 0x82645298
	ctx.lr = 0x82647400;
	sub_82645298(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8264740C;
	sub_82630318(ctx, base);
	// lhz r11,1000(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1000);
	// lwz r8,996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r9,r31,996
	ctx.r9.s64 = r31.s64 + 996;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647444
	if (cr6.eq) goto loc_82647444;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_82647430:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647430
	if (!cr6.eq) goto loc_82647430;
loc_82647444:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,1004
	ctx.r8.s64 = r31.s64 + 1004;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,1004(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// lhz r4,1008(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647490
	if (cr6.eq) goto loc_82647490;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_8264747C:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8264747c
	if (!cr6.eq) goto loc_8264747C;
loc_82647490:
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

__attribute__((alias("__imp__sub_826474BC"))) PPC_WEAK_FUNC(sub_826474BC);
PPC_FUNC_IMPL(__imp__sub_826474BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826474C0"))) PPC_WEAK_FUNC(sub_826474C0);
PPC_FUNC_IMPL(__imp__sub_826474C0) {
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
	ctx.lr = 0x826474C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x826474E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82647500
	if (!cr6.eq) goto loc_82647500;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82647500:
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x826476cc
	if (cr6.eq) goto loc_826476CC;
	// cmpwi cr6,r30,60
	cr6.compare<int32_t>(r30.s32, 60, xer);
	// beq cr6,0x826475d8
	if (cr6.eq) goto loc_826475D8;
	// cmpwi cr6,r30,61
	cr6.compare<int32_t>(r30.s32, 61, xer);
	// beq cr6,0x82647530
	if (cr6.eq) goto loc_82647530;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82647528;
	sub_826537D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82647530:
	// lhz r10,1040(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1040);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82647554
	if (!cr6.eq) goto loc_82647554;
loc_8264753C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82647548;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82647554:
	// lwz r11,1000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82647564
	if (!cr0.lt) goto loc_82647564;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_82647564:
	// lwz r10,1036(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// addi r3,r31,1004
	ctx.r3.s64 = r31.s64 + 1004;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r8.u32);
	// bl 0x826b6228
	ctx.lr = 0x82647580;
	sub_826B6228(ctx, base);
	// addi r3,r31,1012
	ctx.r3.s64 = r31.s64 + 1012;
	// bl 0x826b6228
	ctx.lr = 0x82647588;
	sub_826B6228(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8264767c
	if (!cr6.gt) goto loc_8264767C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,3992
	r28.s64 = r11.s64 + 3992;
loc_826475A4:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826475C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826475a4
	if (cr6.lt) goto loc_826475A4;
	// b 0x8264767c
	goto loc_8264767C;
loc_826475D8:
	// lhz r10,1040(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1040);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264753c
	if (cr6.eq) goto loc_8264753C;
	// lwz r11,1000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8264760c
	if (cr6.lt) goto loc_8264760C;
	// lwz r11,1036(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r9.u32);
	// b 0x82647620
	goto loc_82647620;
loc_8264760C:
	// lwz r10,1036(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r8.u32);
loc_82647620:
	// addi r3,r31,1004
	ctx.r3.s64 = r31.s64 + 1004;
	// bl 0x826b6228
	ctx.lr = 0x82647628;
	sub_826B6228(ctx, base);
	// addi r3,r31,1012
	ctx.r3.s64 = r31.s64 + 1012;
	// bl 0x826b6228
	ctx.lr = 0x82647630;
	sub_826B6228(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8264767c
	if (!cr6.gt) goto loc_8264767C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,3992
	r28.s64 = r11.s64 + 3992;
loc_8264764C:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82647668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8264764c
	if (cr6.lt) goto loc_8264764C;
loc_8264767C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,996(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r8,r10,104
	ctx.r8.s64 = ctx.r10.s64 * 104;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// lwz r7,788(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// lwzx r4,r8,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826476A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826476B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82645528
	ctx.lr = 0x826476C0;
	sub_82645528(ctx, base);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// lwz r3,24588(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826476CC;
	sub_821E6800(ctx, base);
loc_826476CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826476D8"))) PPC_WEAK_FUNC(sub_826476D8);
PPC_FUNC_IMPL(__imp__sub_826476D8) {
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
	ctx.lr = 0x826476E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r30,r31,1036
	r30.s64 = r31.s64 + 1036;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stw r5,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r5.u32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x82647734
	if (cr6.eq) goto loc_82647734;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82647728
	if (cr6.eq) goto loc_82647728;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647728
	if (cr6.eq) goto loc_82647728;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82647728;
	sub_82130588(ctx, base);
loc_82647728:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x82647734;
	sub_826C7480(ctx, base);
loc_82647734:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r30,0
	r30.s64 = 0;
	// stw r28,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r28.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82647784
	if (!cr6.gt) goto loc_82647784;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,3992
	r28.s64 = r11.s64 + 3992;
loc_82647754:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82647770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x82647754
	if (cr6.lt) goto loc_82647754;
loc_82647784:
	// lhz r11,1008(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r9,r31,1004
	ctx.r9.s64 = r31.s64 + 1004;
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826477bc
	if (cr6.eq) goto loc_826477BC;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_826477A8:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826477a8
	if (!cr6.eq) goto loc_826477A8;
loc_826477BC:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,1012
	ctx.r8.s64 = r31.s64 + 1012;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,1012(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// lhz r4,1016(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 1016);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647808
	if (cr6.eq) goto loc_82647808;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_826477F4:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826477f4
	if (!cr6.eq) goto loc_826477F4;
loc_82647808:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// bl 0x82645528
	ctx.lr = 0x82647824;
	sub_82645528(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82647830;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82647838"))) PPC_WEAK_FUNC(sub_82647838);
PPC_FUNC_IMPL(__imp__sub_82647838) {
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
	// bl 0x826458c0
	ctx.lr = 0x82647858;
	sub_826458C0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647870
	if (cr6.eq) goto loc_82647870;
	// bl 0x82130588
	ctx.lr = 0x8264786C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647870:
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

__attribute__((alias("__imp__sub_82647888"))) PPC_WEAK_FUNC(sub_82647888);
PPC_FUNC_IMPL(__imp__sub_82647888) {
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
	ctx.lr = 0x82647890;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826478AC;
	sub_8238EC00(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826478C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826478dc
	if (!cr6.eq) goto loc_826478DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826478DC:
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x82647b14
	if (cr6.eq) goto loc_82647B14;
	// cmpwi cr6,r30,60
	cr6.compare<int32_t>(r30.s32, 60, xer);
	// beq cr6,0x826479c4
	if (cr6.eq) goto loc_826479C4;
	// cmpwi cr6,r30,61
	cr6.compare<int32_t>(r30.s32, 61, xer);
	// beq cr6,0x8264790c
	if (cr6.eq) goto loc_8264790C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82647904;
	sub_826537D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8264790C:
	// lwz r11,1000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x82647938
	if (cr0.lt) goto loc_82647938;
	// lwz r10,1036(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r7,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r7.u32);
	// lwz r3,24588(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24588);
	// b 0x82647940
	goto loc_82647940;
loc_82647938:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
loc_82647940:
	// bl 0x821e6800
	ctx.lr = 0x82647944;
	sub_821E6800(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82647990
	if (!cr6.gt) goto loc_82647990;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,3992
	r28.s64 = r11.s64 + 3992;
loc_82647960:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264797C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x82647960
	if (cr6.lt) goto loc_82647960;
loc_82647990:
	// addi r3,r31,1004
	ctx.r3.s64 = r31.s64 + 1004;
	// bl 0x826b6228
	ctx.lr = 0x82647998;
	sub_826B6228(ctx, base);
	// addi r3,r31,1012
	ctx.r3.s64 = r31.s64 + 1012;
	// bl 0x826b6228
	ctx.lr = 0x826479A0;
	sub_826B6228(ctx, base);
	// lwz r11,996(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,788(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 788);
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x82647b08
	goto loc_82647B08;
loc_826479C4:
	// lwz r11,1000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lhz r10,1040(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1040);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x826479f8
	if (!cr6.lt) goto loc_826479F8;
	// lwz r10,1036(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r7,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r7.u32);
	// lwz r3,24588(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24588);
	// b 0x82647a00
	goto loc_82647A00;
loc_826479F8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
loc_82647A00:
	// bl 0x821e6800
	ctx.lr = 0x82647A04;
	sub_821E6800(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82647a50
	if (!cr6.gt) goto loc_82647A50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,3992
	r28.s64 = r11.s64 + 3992;
loc_82647A20:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82647A3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x82647a20
	if (cr6.lt) goto loc_82647A20;
loc_82647A50:
	// lhz r11,1008(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r9,r31,1004
	ctx.r9.s64 = r31.s64 + 1004;
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647a88
	if (cr6.eq) goto loc_82647A88;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_82647A74:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647a74
	if (!cr6.eq) goto loc_82647A74;
loc_82647A88:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,1012
	ctx.r8.s64 = r31.s64 + 1012;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,1012(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// lhz r4,1016(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 1016);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647ad4
	if (cr6.eq) goto loc_82647AD4;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82647AC0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647ac0
	if (!cr6.eq) goto loc_82647AC0;
loc_82647AD4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,788(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 788);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82647B08:
	// bctrl 
	ctx.lr = 0x82647B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82645958
	ctx.lr = 0x82647B14;
	sub_82645958(ctx, base);
loc_82647B14:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82647B20"))) PPC_WEAK_FUNC(sub_82647B20);
PPC_FUNC_IMPL(__imp__sub_82647B20) {
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
	ctx.lr = 0x82647B28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r30,r31,1036
	r30.s64 = r31.s64 + 1036;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stw r5,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r5.u32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x82647b7c
	if (cr6.eq) goto loc_82647B7C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82647b70
	if (cr6.eq) goto loc_82647B70;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647b70
	if (cr6.eq) goto loc_82647B70;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82647B70;
	sub_82130588(ctx, base);
loc_82647B70:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x82647B7C;
	sub_826C7480(ctx, base);
loc_82647B7C:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r30,0
	r30.s64 = 0;
	// stw r28,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r28.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82647bcc
	if (!cr6.gt) goto loc_82647BCC;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,20756
	r28.s64 = r11.s64 + 20756;
loc_82647B9C:
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82647BB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x82647b9c
	if (cr6.lt) goto loc_82647B9C;
loc_82647BCC:
	// lhz r11,1008(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r9,r31,1004
	ctx.r9.s64 = r31.s64 + 1004;
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647c04
	if (cr6.eq) goto loc_82647C04;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_82647BF0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647bf0
	if (!cr6.eq) goto loc_82647BF0;
loc_82647C04:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,1012
	ctx.r8.s64 = r31.s64 + 1012;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,1012(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// lhz r4,1016(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 1016);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82647c50
	if (cr6.eq) goto loc_82647C50;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82647C3C:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82647c3c
	if (!cr6.eq) goto loc_82647C3C;
loc_82647C50:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// bl 0x82645958
	ctx.lr = 0x82647C6C;
	sub_82645958(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82647C78;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82647C80"))) PPC_WEAK_FUNC(sub_82647C80);
PPC_FUNC_IMPL(__imp__sub_82647C80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,60
	cr6.compare<int32_t>(ctx.r4.s32, 60, xer);
	// beq cr6,0x82647cd8
	if (cr6.eq) goto loc_82647CD8;
	// cmpwi cr6,r4,61
	cr6.compare<int32_t>(ctx.r4.s32, 61, xer);
	// beq cr6,0x82647cbc
	if (cr6.eq) goto loc_82647CBC;
	// bl 0x826537d0
	ctx.lr = 0x82647CA8;
	sub_826537D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82647CBC:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82647ce8
	if (!cr0.lt) goto loc_82647CE8;
loc_82647CC8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82647CD4;
	sub_821E6800(ctx, base);
	// b 0x82647d04
	goto loc_82647D04;
loc_82647CD8:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bgt cr6,0x82647cc8
	if (cr6.gt) goto loc_82647CC8;
loc_82647CE8:
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82647CF8;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,992(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// bl 0x826460b8
	ctx.lr = 0x82647D04;
	sub_826460B8(ctx, base);
loc_82647D04:
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

__attribute__((alias("__imp__sub_82647D1C"))) PPC_WEAK_FUNC(sub_82647D1C);
PPC_FUNC_IMPL(__imp__sub_82647D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82647D20"))) PPC_WEAK_FUNC(sub_82647D20);
PPC_FUNC_IMPL(__imp__sub_82647D20) {
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
	// bl 0x82646598
	ctx.lr = 0x82647D40;
	sub_82646598(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647d58
	if (cr6.eq) goto loc_82647D58;
	// bl 0x82130588
	ctx.lr = 0x82647D54;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647D58:
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

__attribute__((alias("__imp__sub_82647D70"))) PPC_WEAK_FUNC(sub_82647D70);
PPC_FUNC_IMPL(__imp__sub_82647D70) {
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
	ctx.lr = 0x82647D78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,4176
	r30.s64 = r31.s64 + 4176;
	// lhz r11,4370(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4370);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647d9c
	if (cr6.eq) goto loc_82647D9C;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647D9C;
	sub_82130588(ctx, base);
loc_82647D9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647DA4;
	sub_82633B00(ctx, base);
	// addi r3,r31,996
	ctx.r3.s64 = r31.s64 + 996;
	// bl 0x827408f8
	ctx.lr = 0x82647DAC;
	sub_827408F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82647DB4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647dcc
	if (cr6.eq) goto loc_82647DCC;
	// bl 0x82130588
	ctx.lr = 0x82647DC8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647DCC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82647DD4"))) PPC_WEAK_FUNC(sub_82647DD4);
PPC_FUNC_IMPL(__imp__sub_82647DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82647DD8"))) PPC_WEAK_FUNC(sub_82647DD8);
PPC_FUNC_IMPL(__imp__sub_82647DD8) {
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
	ctx.lr = 0x82647DE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// bl 0x8221fbc8
	ctx.lr = 0x82647DF4;
	sub_8221FBC8(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647e0c
	if (cr6.eq) goto loc_82647E0C;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647E0C;
	sub_82130588(ctx, base);
loc_82647E0C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647E14;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82647E1C;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647e34
	if (cr6.eq) goto loc_82647E34;
	// bl 0x82130588
	ctx.lr = 0x82647E30;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82647E34:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82647E3C"))) PPC_WEAK_FUNC(sub_82647E3C);
PPC_FUNC_IMPL(__imp__sub_82647E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82647E40"))) PPC_WEAK_FUNC(sub_82647E40);
PPC_FUNC_IMPL(__imp__sub_82647E40) {
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
	// addi r3,r31,8560
	ctx.r3.s64 = r31.s64 + 8560;
	// bl 0x8221fbc8
	ctx.lr = 0x82647E60;
	sub_8221FBC8(ctx, base);
	// lhz r11,8450(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8450);
	// addi r30,r31,8256
	r30.s64 = r31.s64 + 8256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647e78
	if (cr6.eq) goto loc_82647E78;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647E78;
	sub_82130588(ctx, base);
loc_82647E78:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647E80;
	sub_82633B00(ctx, base);
	// lhz r11,8210(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8210);
	// addi r30,r31,8016
	r30.s64 = r31.s64 + 8016;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647e98
	if (cr6.eq) goto loc_82647E98;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647E98;
	sub_82130588(ctx, base);
loc_82647E98:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647EA0;
	sub_82633B00(ctx, base);
	// lhz r11,7970(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 7970);
	// addi r30,r31,7776
	r30.s64 = r31.s64 + 7776;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647eb8
	if (cr6.eq) goto loc_82647EB8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647EB8;
	sub_82130588(ctx, base);
loc_82647EB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647EC0;
	sub_82633B00(ctx, base);
	// lhz r11,7730(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 7730);
	// addi r30,r31,7536
	r30.s64 = r31.s64 + 7536;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647ed8
	if (cr6.eq) goto loc_82647ED8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647ED8;
	sub_82130588(ctx, base);
loc_82647ED8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647EE0;
	sub_82633B00(ctx, base);
	// lhz r11,7490(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 7490);
	// addi r30,r31,7296
	r30.s64 = r31.s64 + 7296;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647ef8
	if (cr6.eq) goto loc_82647EF8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647EF8;
	sub_82130588(ctx, base);
loc_82647EF8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647F00;
	sub_82633B00(ctx, base);
	// lhz r11,7250(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 7250);
	// addi r30,r31,7056
	r30.s64 = r31.s64 + 7056;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647f18
	if (cr6.eq) goto loc_82647F18;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647F18;
	sub_82130588(ctx, base);
loc_82647F18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647F20;
	sub_82633B00(ctx, base);
	// lhz r11,7010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 7010);
	// addi r30,r31,6816
	r30.s64 = r31.s64 + 6816;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647f38
	if (cr6.eq) goto loc_82647F38;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647F38;
	sub_82130588(ctx, base);
loc_82647F38:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647F40;
	sub_82633B00(ctx, base);
	// lhz r11,6770(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6770);
	// addi r30,r31,6576
	r30.s64 = r31.s64 + 6576;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647f58
	if (cr6.eq) goto loc_82647F58;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647F58;
	sub_82130588(ctx, base);
loc_82647F58:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647F60;
	sub_82633B00(ctx, base);
	// lhz r11,6530(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6530);
	// addi r30,r31,6336
	r30.s64 = r31.s64 + 6336;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647f78
	if (cr6.eq) goto loc_82647F78;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647F78;
	sub_82130588(ctx, base);
loc_82647F78:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647F80;
	sub_82633B00(ctx, base);
	// lhz r11,6290(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6290);
	// addi r30,r31,6096
	r30.s64 = r31.s64 + 6096;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647f98
	if (cr6.eq) goto loc_82647F98;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647F98;
	sub_82130588(ctx, base);
loc_82647F98:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647FA0;
	sub_82633B00(ctx, base);
	// lhz r11,6050(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6050);
	// addi r30,r31,5856
	r30.s64 = r31.s64 + 5856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647fb8
	if (cr6.eq) goto loc_82647FB8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647FB8;
	sub_82130588(ctx, base);
loc_82647FB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647FC0;
	sub_82633B00(ctx, base);
	// lhz r11,5810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5810);
	// addi r30,r31,5616
	r30.s64 = r31.s64 + 5616;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647fd8
	if (cr6.eq) goto loc_82647FD8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647FD8;
	sub_82130588(ctx, base);
loc_82647FD8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82647FE0;
	sub_82633B00(ctx, base);
	// lhz r11,5570(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5570);
	// addi r30,r31,5376
	r30.s64 = r31.s64 + 5376;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82647ff8
	if (cr6.eq) goto loc_82647FF8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82647FF8;
	sub_82130588(ctx, base);
loc_82647FF8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648000;
	sub_82633B00(ctx, base);
	// lhz r11,5330(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5330);
	// addi r30,r31,5136
	r30.s64 = r31.s64 + 5136;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648018
	if (cr6.eq) goto loc_82648018;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648018;
	sub_82130588(ctx, base);
loc_82648018:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648020;
	sub_82633B00(ctx, base);
	// lhz r11,5074(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5074);
	// addi r30,r31,4880
	r30.s64 = r31.s64 + 4880;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648038
	if (cr6.eq) goto loc_82648038;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648038;
	sub_82130588(ctx, base);
loc_82648038:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648040;
	sub_82633B00(ctx, base);
	// lhz r11,4818(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4818);
	// addi r30,r31,4624
	r30.s64 = r31.s64 + 4624;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648058
	if (cr6.eq) goto loc_82648058;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648058;
	sub_82130588(ctx, base);
loc_82648058:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648060;
	sub_82633B00(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,4288
	r30.s64 = r31.s64 + 4288;
	// addi r10,r11,5568
	ctx.r10.s64 = r11.s64 + 5568;
	// stw r10,4584(r31)
	PPC_STORE_U32(r31.u32 + 4584, ctx.r10.u32);
	// stw r10,4576(r31)
	PPC_STORE_U32(r31.u32 + 4576, ctx.r10.u32);
	// stw r10,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, ctx.r10.u32);
	// stw r10,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, ctx.r10.u32);
	// stw r10,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r10.u32);
	// stw r10,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, ctx.r10.u32);
	// stw r10,4536(r31)
	PPC_STORE_U32(r31.u32 + 4536, ctx.r10.u32);
	// stw r10,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, ctx.r10.u32);
	// lhz r9,4482(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4482);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826480a0
	if (cr6.eq) goto loc_826480A0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826480A0;
	sub_82130588(ctx, base);
loc_826480A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826480A8;
	sub_82633B00(ctx, base);
	// lhz r11,4242(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4242);
	// addi r30,r31,4048
	r30.s64 = r31.s64 + 4048;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826480c0
	if (cr6.eq) goto loc_826480C0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826480C0;
	sub_82130588(ctx, base);
loc_826480C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826480C8;
	sub_82633B00(ctx, base);
	// lhz r11,4002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4002);
	// addi r30,r31,3808
	r30.s64 = r31.s64 + 3808;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826480e0
	if (cr6.eq) goto loc_826480E0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826480E0;
	sub_82130588(ctx, base);
loc_826480E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826480E8;
	sub_82633B00(ctx, base);
	// lhz r11,3762(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3762);
	// addi r30,r31,3568
	r30.s64 = r31.s64 + 3568;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648100
	if (cr6.eq) goto loc_82648100;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648100;
	sub_82130588(ctx, base);
loc_82648100:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648108;
	sub_82633B00(ctx, base);
	// lhz r11,3522(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3522);
	// addi r30,r31,3328
	r30.s64 = r31.s64 + 3328;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648120
	if (cr6.eq) goto loc_82648120;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648120;
	sub_82130588(ctx, base);
loc_82648120:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648128;
	sub_82633B00(ctx, base);
	// lhz r11,3282(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3282);
	// addi r30,r31,3088
	r30.s64 = r31.s64 + 3088;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648140
	if (cr6.eq) goto loc_82648140;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648140;
	sub_82130588(ctx, base);
loc_82648140:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648148;
	sub_82633B00(ctx, base);
	// lhz r11,3042(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3042);
	// addi r30,r31,2848
	r30.s64 = r31.s64 + 2848;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648160
	if (cr6.eq) goto loc_82648160;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648160;
	sub_82130588(ctx, base);
loc_82648160:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648168;
	sub_82633B00(ctx, base);
	// lhz r11,2802(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2802);
	// addi r30,r31,2608
	r30.s64 = r31.s64 + 2608;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648180
	if (cr6.eq) goto loc_82648180;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648180;
	sub_82130588(ctx, base);
loc_82648180:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648188;
	sub_82633B00(ctx, base);
	// lhz r11,2562(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2562);
	// addi r30,r31,2368
	r30.s64 = r31.s64 + 2368;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826481a0
	if (cr6.eq) goto loc_826481A0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826481A0;
	sub_82130588(ctx, base);
loc_826481A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826481A8;
	sub_82633B00(ctx, base);
	// lhz r11,2322(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2322);
	// addi r30,r31,2128
	r30.s64 = r31.s64 + 2128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826481c0
	if (cr6.eq) goto loc_826481C0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826481C0;
	sub_82130588(ctx, base);
loc_826481C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826481C8;
	sub_82633B00(ctx, base);
	// lhz r11,2082(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2082);
	// addi r30,r31,1888
	r30.s64 = r31.s64 + 1888;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826481e0
	if (cr6.eq) goto loc_826481E0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826481E0;
	sub_82130588(ctx, base);
loc_826481E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826481E8;
	sub_82633B00(ctx, base);
	// lhz r11,1842(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1842);
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648200
	if (cr6.eq) goto loc_82648200;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648200;
	sub_82130588(ctx, base);
loc_82648200:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648208;
	sub_82633B00(ctx, base);
	// lhz r11,1586(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1586);
	// addi r30,r31,1392
	r30.s64 = r31.s64 + 1392;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648220
	if (cr6.eq) goto loc_82648220;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648220;
	sub_82130588(ctx, base);
loc_82648220:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648228;
	sub_82633B00(ctx, base);
	// lhz r11,1330(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1330);
	// addi r30,r31,1136
	r30.s64 = r31.s64 + 1136;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648240
	if (cr6.eq) goto loc_82648240;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648240;
	sub_82130588(ctx, base);
loc_82648240:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648248;
	sub_82633B00(ctx, base);
	// addi r3,r31,1120
	ctx.r3.s64 = r31.s64 + 1120;
	// bl 0x821d2028
	ctx.lr = 0x82648250;
	sub_821D2028(ctx, base);
	// addi r3,r31,1104
	ctx.r3.s64 = r31.s64 + 1104;
	// bl 0x821d2028
	ctx.lr = 0x82648258;
	sub_821D2028(ctx, base);
	// addi r3,r31,1088
	ctx.r3.s64 = r31.s64 + 1088;
	// bl 0x821d2028
	ctx.lr = 0x82648260;
	sub_821D2028(ctx, base);
	// addi r3,r31,1072
	ctx.r3.s64 = r31.s64 + 1072;
	// bl 0x821d2028
	ctx.lr = 0x82648268;
	sub_821D2028(ctx, base);
	// addi r3,r31,1056
	ctx.r3.s64 = r31.s64 + 1056;
	// bl 0x821d2028
	ctx.lr = 0x82648270;
	sub_821D2028(ctx, base);
	// addi r3,r31,1040
	ctx.r3.s64 = r31.s64 + 1040;
	// bl 0x821d2028
	ctx.lr = 0x82648278;
	sub_821D2028(ctx, base);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// bl 0x821d2028
	ctx.lr = 0x82648280;
	sub_821D2028(ctx, base);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x821d2028
	ctx.lr = 0x82648288;
	sub_821D2028(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82648290;
	sub_821D2028(ctx, base);
	// addi r3,r31,976
	ctx.r3.s64 = r31.s64 + 976;
	// bl 0x821d2028
	ctx.lr = 0x82648298;
	sub_821D2028(ctx, base);
	// addi r3,r31,960
	ctx.r3.s64 = r31.s64 + 960;
	// bl 0x821d2028
	ctx.lr = 0x826482A0;
	sub_821D2028(ctx, base);
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// bl 0x821d2028
	ctx.lr = 0x826482A8;
	sub_821D2028(ctx, base);
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// bl 0x821d2028
	ctx.lr = 0x826482B0;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826482B8;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826482D0"))) PPC_WEAK_FUNC(sub_826482D0);
PPC_FUNC_IMPL(__imp__sub_826482D0) {
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
	ctx.lr = 0x826482D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r29,5424
	ctx.r3.s64 = r29.s64 + 5424;
	// bl 0x8221fbc8
	ctx.lr = 0x826482E8;
	sub_8221FBC8(ctx, base);
	// addi r31,r29,5424
	r31.s64 = r29.s64 + 5424;
	// li r30,10
	r30.s64 = 10;
loc_826482F0:
	// addi r31,r31,-240
	r31.s64 = r31.s64 + -240;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648308
	if (cr6.eq) goto loc_82648308;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648308;
	sub_82130588(ctx, base);
loc_82648308:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648310;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826482f0
	if (!cr0.lt) goto loc_826482F0;
	// addi r3,r29,992
	ctx.r3.s64 = r29.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x82648320;
	sub_8221FBC8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648328;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82648330"))) PPC_WEAK_FUNC(sub_82648330);
PPC_FUNC_IMPL(__imp__sub_82648330) {
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
	// addi r30,r31,3296
	r30.s64 = r31.s64 + 3296;
	// lhz r11,3490(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3490);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648360
	if (cr6.eq) goto loc_82648360;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648360;
	sub_82130588(ctx, base);
loc_82648360:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648368;
	sub_82633B00(ctx, base);
	// lhz r11,3250(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3250);
	// addi r30,r31,3056
	r30.s64 = r31.s64 + 3056;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648380
	if (cr6.eq) goto loc_82648380;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648380;
	sub_82130588(ctx, base);
loc_82648380:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648388;
	sub_82633B00(ctx, base);
	// lhz r11,3010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3010);
	// addi r30,r31,2816
	r30.s64 = r31.s64 + 2816;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826483a0
	if (cr6.eq) goto loc_826483A0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826483A0;
	sub_82130588(ctx, base);
loc_826483A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826483A8;
	sub_82633B00(ctx, base);
	// addi r3,r31,2800
	ctx.r3.s64 = r31.s64 + 2800;
	// bl 0x821d2028
	ctx.lr = 0x826483B0;
	sub_821D2028(ctx, base);
	// addi r3,r31,2784
	ctx.r3.s64 = r31.s64 + 2784;
	// bl 0x821d2028
	ctx.lr = 0x826483B8;
	sub_821D2028(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x826483C0;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826483C8;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826483E0"))) PPC_WEAK_FUNC(sub_826483E0);
PPC_FUNC_IMPL(__imp__sub_826483E0) {
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
	// addi r3,r31,4064
	ctx.r3.s64 = r31.s64 + 4064;
	// bl 0x8221fbc8
	ctx.lr = 0x82648400;
	sub_8221FBC8(ctx, base);
	// lhz r11,4018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4018);
	// addi r30,r31,3824
	r30.s64 = r31.s64 + 3824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648418
	if (cr6.eq) goto loc_82648418;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648418;
	sub_82130588(ctx, base);
loc_82648418:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648420;
	sub_82633B00(ctx, base);
	// lhz r11,3762(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3762);
	// addi r30,r31,3568
	r30.s64 = r31.s64 + 3568;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648438
	if (cr6.eq) goto loc_82648438;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648438;
	sub_82130588(ctx, base);
loc_82648438:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648440;
	sub_82633B00(ctx, base);
	// lhz r11,3522(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3522);
	// addi r30,r31,3328
	r30.s64 = r31.s64 + 3328;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648458
	if (cr6.eq) goto loc_82648458;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648458;
	sub_82130588(ctx, base);
loc_82648458:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648460;
	sub_82633B00(ctx, base);
	// lhz r11,3282(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3282);
	// addi r30,r31,3088
	r30.s64 = r31.s64 + 3088;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648478
	if (cr6.eq) goto loc_82648478;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648478;
	sub_82130588(ctx, base);
loc_82648478:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648480;
	sub_82633B00(ctx, base);
	// lhz r11,3042(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3042);
	// addi r30,r31,2848
	r30.s64 = r31.s64 + 2848;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648498
	if (cr6.eq) goto loc_82648498;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648498;
	sub_82130588(ctx, base);
loc_82648498:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826484A0;
	sub_82633B00(ctx, base);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// bl 0x821d2028
	ctx.lr = 0x826484A8;
	sub_821D2028(ctx, base);
	// addi r3,r31,2816
	ctx.r3.s64 = r31.s64 + 2816;
	// bl 0x821d2028
	ctx.lr = 0x826484B0;
	sub_821D2028(ctx, base);
	// addi r3,r31,2800
	ctx.r3.s64 = r31.s64 + 2800;
	// bl 0x821d2028
	ctx.lr = 0x826484B8;
	sub_821D2028(ctx, base);
	// addi r3,r31,2784
	ctx.r3.s64 = r31.s64 + 2784;
	// bl 0x821d2028
	ctx.lr = 0x826484C0;
	sub_821D2028(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x826484C8;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826484D0;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826484E8"))) PPC_WEAK_FUNC(sub_826484E8);
PPC_FUNC_IMPL(__imp__sub_826484E8) {
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
	// addi r30,r31,3808
	r30.s64 = r31.s64 + 3808;
	// lhz r11,4002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648518
	if (cr6.eq) goto loc_82648518;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648518;
	sub_82130588(ctx, base);
loc_82648518:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648520;
	sub_82633B00(ctx, base);
	// lhz r11,3746(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3746);
	// addi r30,r31,3552
	r30.s64 = r31.s64 + 3552;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648538
	if (cr6.eq) goto loc_82648538;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648538;
	sub_82130588(ctx, base);
loc_82648538:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648540;
	sub_82633B00(ctx, base);
	// lhz r11,3490(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3490);
	// addi r30,r31,3296
	r30.s64 = r31.s64 + 3296;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648558
	if (cr6.eq) goto loc_82648558;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648558;
	sub_82130588(ctx, base);
loc_82648558:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648560;
	sub_82633B00(ctx, base);
	// lhz r11,3234(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 3234);
	// addi r30,r31,3040
	r30.s64 = r31.s64 + 3040;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648578
	if (cr6.eq) goto loc_82648578;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648578;
	sub_82130588(ctx, base);
loc_82648578:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648580;
	sub_82633B00(ctx, base);
	// lhz r11,2978(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2978);
	// addi r30,r31,2784
	r30.s64 = r31.s64 + 2784;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648598
	if (cr6.eq) goto loc_82648598;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648598;
	sub_82130588(ctx, base);
loc_82648598:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x826485A0;
	sub_82633B00(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x826485A8;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826485B0;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826485C8"))) PPC_WEAK_FUNC(sub_826485C8);
PPC_FUNC_IMPL(__imp__sub_826485C8) {
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
	ctx.lr = 0x826485D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3
	r11.s64 = 196608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r11,8848
	ctx.r9.u64 = r11.u64 | 8848;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r8,r10,29204
	ctx.r8.s64 = ctx.r10.s64 + 29204;
	// lwzx r3,r31,r9
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264860c
	if (cr6.eq) goto loc_8264860C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264860C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264860C:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8852
	ctx.r10.u64 = r11.u64 | 8852;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82648634
	if (cr6.eq) goto loc_82648634;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82648634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82648634:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8856
	ctx.r10.u64 = r11.u64 | 8856;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264865c
	if (cr6.eq) goto loc_8264865C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264865C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264865C:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8860
	ctx.r10.u64 = r11.u64 | 8860;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82648684
	if (cr6.eq) goto loc_82648684;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82648684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82648684:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8868
	ctx.r10.u64 = r11.u64 | 8868;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826486ac
	if (cr6.eq) goto loc_826486AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826486AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826486AC:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8872
	ctx.r10.u64 = r11.u64 | 8872;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826486d4
	if (cr6.eq) goto loc_826486D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826486D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826486D4:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8876
	ctx.r10.u64 = r11.u64 | 8876;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826486fc
	if (cr6.eq) goto loc_826486FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826486FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826486FC:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8880
	ctx.r10.u64 = r11.u64 | 8880;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82648724
	if (cr6.eq) goto loc_82648724;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82648724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82648724:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8884
	ctx.r10.u64 = r11.u64 | 8884;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264874c
	if (cr6.eq) goto loc_8264874C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264874C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264874C:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,8864
	ctx.r10.u64 = r11.u64 | 8864;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82648774
	if (cr6.eq) goto loc_82648774;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82648774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82648774:
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-11840
	ctx.r3.s64 = ctx.r3.s64 + -11840;
	// bl 0x82633b00
	ctx.lr = 0x82648780;
	sub_82633B00(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-12784
	ctx.r3.s64 = ctx.r3.s64 + -12784;
	// bl 0x8221fcc8
	ctx.lr = 0x8264878C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-14144
	ctx.r3.s64 = ctx.r3.s64 + -14144;
	// bl 0x82646f40
	ctx.lr = 0x82648798;
	sub_82646F40(ctx, base);
	// addis r30,r31,4
	r30.s64 = r31.s64 + 262144;
	// addi r30,r30,-17184
	r30.s64 = r30.s64 + -17184;
	// addi r3,r30,1248
	ctx.r3.s64 = r30.s64 + 1248;
	// bl 0x8221fbc8
	ctx.lr = 0x826487A8;
	sub_8221FBC8(ctx, base);
	// lhz r11,1186(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1186);
	// addi r29,r30,992
	r29.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826487c0
	if (cr6.eq) goto loc_826487C0;
	// lwz r3,188(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826487C0;
	sub_82130588(ctx, base);
loc_826487C0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x826487C8;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826487D0;
	sub_8221FCC8(ctx, base);
	// addis r30,r31,4
	r30.s64 = r31.s64 + 262144;
	// addi r30,r30,-21584
	r30.s64 = r30.s64 + -21584;
	// addi r29,r30,4176
	r29.s64 = r30.s64 + 4176;
	// lhz r11,4370(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4370);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826487f0
	if (cr6.eq) goto loc_826487F0;
	// lwz r3,188(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826487F0;
	sub_82130588(ctx, base);
loc_826487F0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x826487F8;
	sub_82633B00(ctx, base);
	// addi r3,r30,996
	ctx.r3.s64 = r30.s64 + 996;
	// bl 0x827408f8
	ctx.lr = 0x82648800;
	sub_827408F8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648808;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-22608
	ctx.r3.s64 = ctx.r3.s64 + -22608;
	// bl 0x8221fcc8
	ctx.lr = 0x82648814;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-25840
	ctx.r3.s64 = ctx.r3.s64 + -25840;
	// bl 0x82646598
	ctx.lr = 0x82648820;
	sub_82646598(ctx, base);
	// addis r30,r31,4
	r30.s64 = r31.s64 + 262144;
	// addi r30,r30,-26320
	r30.s64 = r30.s64 + -26320;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82648830;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648838;
	sub_82633B00(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-27280
	ctx.r3.s64 = ctx.r3.s64 + -27280;
	// bl 0x8221fcc8
	ctx.lr = 0x82648844;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-28240
	ctx.r3.s64 = ctx.r3.s64 + -28240;
	// bl 0x8221fcc8
	ctx.lr = 0x82648850;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-29200
	ctx.r3.s64 = ctx.r3.s64 + -29200;
	// bl 0x8221fcc8
	ctx.lr = 0x8264885C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-30160
	ctx.r3.s64 = ctx.r3.s64 + -30160;
	// bl 0x8221fcc8
	ctx.lr = 0x82648868;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-31104
	ctx.r3.s64 = ctx.r3.s64 + -31104;
	// bl 0x8221fcc8
	ctx.lr = 0x82648874;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// addi r3,r3,-32048
	ctx.r3.s64 = ctx.r3.s64 + -32048;
	// bl 0x8221fcc8
	ctx.lr = 0x82648880;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,32544
	ctx.r3.s64 = ctx.r3.s64 + 32544;
	// bl 0x8221fcc8
	ctx.lr = 0x8264888C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,31600
	ctx.r3.s64 = ctx.r3.s64 + 31600;
	// bl 0x8221fcc8
	ctx.lr = 0x82648898;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,30656
	ctx.r3.s64 = ctx.r3.s64 + 30656;
	// bl 0x8221fcc8
	ctx.lr = 0x826488A4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,29712
	ctx.r3.s64 = ctx.r3.s64 + 29712;
	// bl 0x8221fcc8
	ctx.lr = 0x826488B0;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,28768
	ctx.r3.s64 = ctx.r3.s64 + 28768;
	// bl 0x8221fcc8
	ctx.lr = 0x826488BC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,27824
	ctx.r3.s64 = ctx.r3.s64 + 27824;
	// bl 0x8221fcc8
	ctx.lr = 0x826488C8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,26880
	ctx.r3.s64 = ctx.r3.s64 + 26880;
	// bl 0x8221fcc8
	ctx.lr = 0x826488D4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,25920
	ctx.r3.s64 = ctx.r3.s64 + 25920;
	// bl 0x8221fcc8
	ctx.lr = 0x826488E0;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,24976
	ctx.r3.s64 = ctx.r3.s64 + 24976;
	// bl 0x8221fcc8
	ctx.lr = 0x826488EC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,24032
	ctx.r3.s64 = ctx.r3.s64 + 24032;
	// bl 0x8221fcc8
	ctx.lr = 0x826488F8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,23088
	ctx.r3.s64 = ctx.r3.s64 + 23088;
	// bl 0x8221fcc8
	ctx.lr = 0x82648904;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,22144
	ctx.r3.s64 = ctx.r3.s64 + 22144;
	// bl 0x8221fcc8
	ctx.lr = 0x82648910;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,21200
	ctx.r3.s64 = ctx.r3.s64 + 21200;
	// bl 0x8221fcc8
	ctx.lr = 0x8264891C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,20256
	ctx.r3.s64 = ctx.r3.s64 + 20256;
	// bl 0x8221fcc8
	ctx.lr = 0x82648928;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,19312
	ctx.r3.s64 = ctx.r3.s64 + 19312;
	// bl 0x8221fcc8
	ctx.lr = 0x82648934;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,18368
	ctx.r3.s64 = ctx.r3.s64 + 18368;
	// bl 0x8221fcc8
	ctx.lr = 0x82648940;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,17408
	ctx.r3.s64 = ctx.r3.s64 + 17408;
	// bl 0x8221fcc8
	ctx.lr = 0x8264894C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,16464
	ctx.r3.s64 = ctx.r3.s64 + 16464;
	// bl 0x8221fcc8
	ctx.lr = 0x82648958;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,15520
	ctx.r3.s64 = ctx.r3.s64 + 15520;
	// bl 0x8221fcc8
	ctx.lr = 0x82648964;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,14576
	ctx.r3.s64 = ctx.r3.s64 + 14576;
	// bl 0x8221fcc8
	ctx.lr = 0x82648970;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,13632
	ctx.r3.s64 = ctx.r3.s64 + 13632;
	// bl 0x8221fcc8
	ctx.lr = 0x8264897C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,12688
	ctx.r3.s64 = ctx.r3.s64 + 12688;
	// bl 0x8221fcc8
	ctx.lr = 0x82648988;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,11728
	ctx.r3.s64 = ctx.r3.s64 + 11728;
	// bl 0x8221fcc8
	ctx.lr = 0x82648994;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,10784
	ctx.r3.s64 = ctx.r3.s64 + 10784;
	// bl 0x8221fcc8
	ctx.lr = 0x826489A0;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,9840
	ctx.r3.s64 = ctx.r3.s64 + 9840;
	// bl 0x8221fcc8
	ctx.lr = 0x826489AC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,8896
	ctx.r3.s64 = ctx.r3.s64 + 8896;
	// bl 0x8221fcc8
	ctx.lr = 0x826489B8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,7680
	ctx.r3.s64 = ctx.r3.s64 + 7680;
	// bl 0x8221fcc8
	ctx.lr = 0x826489C4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,5856
	ctx.r3.s64 = ctx.r3.s64 + 5856;
	// bl 0x82644b90
	ctx.lr = 0x826489D0;
	sub_82644B90(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,4816
	ctx.r3.s64 = ctx.r3.s64 + 4816;
	// bl 0x82645218
	ctx.lr = 0x826489DC;
	sub_82645218(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,3120
	ctx.r3.s64 = ctx.r3.s64 + 3120;
	// bl 0x82646d30
	ctx.lr = 0x826489E8;
	sub_82646D30(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,1136
	ctx.r3.s64 = ctx.r3.s64 + 1136;
	// bl 0x82646e80
	ctx.lr = 0x826489F4;
	sub_82646E80(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-768
	ctx.r3.s64 = ctx.r3.s64 + -768;
	// bl 0x82646dc8
	ctx.lr = 0x82648A00;
	sub_82646DC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-1856
	ctx.r3.s64 = ctx.r3.s64 + -1856;
	// bl 0x8267b4a8
	ctx.lr = 0x82648A0C;
	sub_8267B4A8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-3552
	ctx.r3.s64 = ctx.r3.s64 + -3552;
	// bl 0x82646d30
	ctx.lr = 0x82648A18;
	sub_82646D30(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-5152
	ctx.r3.s64 = ctx.r3.s64 + -5152;
	// bl 0x82646c98
	ctx.lr = 0x82648A24;
	sub_82646C98(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-8352
	ctx.r3.s64 = ctx.r3.s64 + -8352;
	// bl 0x82646c40
	ctx.lr = 0x82648A30;
	sub_82646C40(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-9408
	ctx.r3.s64 = ctx.r3.s64 + -9408;
	// bl 0x826458c0
	ctx.lr = 0x82648A3C;
	sub_826458C0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-10464
	ctx.r3.s64 = ctx.r3.s64 + -10464;
	// bl 0x826458c0
	ctx.lr = 0x82648A48;
	sub_826458C0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-11504
	ctx.r3.s64 = ctx.r3.s64 + -11504;
	// bl 0x82645218
	ctx.lr = 0x82648A54;
	sub_82645218(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-12752
	ctx.r3.s64 = ctx.r3.s64 + -12752;
	// bl 0x82644e90
	ctx.lr = 0x82648A60;
	sub_82644E90(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-14576
	ctx.r3.s64 = ctx.r3.s64 + -14576;
	// bl 0x82644b90
	ctx.lr = 0x82648A6C;
	sub_82644B90(ctx, base);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// addi r30,r30,-15600
	r30.s64 = r30.s64 + -15600;
	// lhz r11,1006(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1006);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648a88
	if (cr6.eq) goto loc_82648A88;
	// lwz r3,1000(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x82648A88;
	sub_82130588(ctx, base);
loc_82648A88:
	// lhz r11,998(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 998);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648a9c
	if (cr6.eq) goto loc_82648A9C;
	// lwz r3,992(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// bl 0x82130588
	ctx.lr = 0x82648A9C;
	sub_82130588(ctx, base);
loc_82648A9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AA4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-16656
	ctx.r3.s64 = ctx.r3.s64 + -16656;
	// bl 0x82644670
	ctx.lr = 0x82648AB0;
	sub_82644670(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-17616
	ctx.r3.s64 = ctx.r3.s64 + -17616;
	// bl 0x8221fcc8
	ctx.lr = 0x82648ABC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-18608
	ctx.r3.s64 = ctx.r3.s64 + -18608;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AC8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-19632
	ctx.r3.s64 = ctx.r3.s64 + -19632;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AD4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-20640
	ctx.r3.s64 = ctx.r3.s64 + -20640;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AE0;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-21648
	ctx.r3.s64 = ctx.r3.s64 + -21648;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AEC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-22656
	ctx.r3.s64 = ctx.r3.s64 + -22656;
	// bl 0x8221fcc8
	ctx.lr = 0x82648AF8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-23712
	ctx.r3.s64 = ctx.r3.s64 + -23712;
	// bl 0x826765c8
	ctx.lr = 0x82648B04;
	sub_826765C8(ctx, base);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// addi r30,r30,-24720
	r30.s64 = r30.s64 + -24720;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82648B14;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648B1C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-24976
	ctx.r3.s64 = ctx.r3.s64 + -24976;
	// bl 0x82633b00
	ctx.lr = 0x82648B28;
	sub_82633B00(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-26048
	ctx.r3.s64 = ctx.r3.s64 + -26048;
	// bl 0x8221fcc8
	ctx.lr = 0x82648B34;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-29744
	ctx.r3.s64 = ctx.r3.s64 + -29744;
	// bl 0x82676a78
	ctx.lr = 0x82648B40;
	sub_82676A78(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-30736
	ctx.r3.s64 = ctx.r3.s64 + -30736;
	// bl 0x826768a0
	ctx.lr = 0x82648B4C;
	sub_826768A0(ctx, base);
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// addi r29,r29,-31968
	r29.s64 = r29.s64 + -31968;
	// addi r30,r29,1024
	r30.s64 = r29.s64 + 1024;
	// lhz r11,1218(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1218);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648b6c
	if (cr6.eq) goto loc_82648B6C;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82648B6C;
	sub_82130588(ctx, base);
loc_82648B6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648B74;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648B7C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,31904
	ctx.r3.s64 = ctx.r3.s64 + 31904;
	// bl 0x826768b0
	ctx.lr = 0x82648B88;
	sub_826768B0(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,30896
	ctx.r3.s64 = ctx.r3.s64 + 30896;
	// bl 0x8221fcc8
	ctx.lr = 0x82648B94;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,29648
	ctx.r3.s64 = ctx.r3.s64 + 29648;
	// bl 0x82676690
	ctx.lr = 0x82648BA0;
	sub_82676690(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,28640
	ctx.r3.s64 = ctx.r3.s64 + 28640;
	// bl 0x8221fcc8
	ctx.lr = 0x82648BAC;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,27632
	ctx.r3.s64 = ctx.r3.s64 + 27632;
	// bl 0x8221fcc8
	ctx.lr = 0x82648BB8;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,25392
	ctx.r3.s64 = ctx.r3.s64 + 25392;
	// bl 0x8266ee60
	ctx.lr = 0x82648BC4;
	sub_8266EE60(ctx, base);
	// addis r29,r31,2
	r29.s64 = r31.s64 + 131072;
	// addi r29,r29,24368
	r29.s64 = r29.s64 + 24368;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// lhz r11,1002(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648be4
	if (cr6.eq) goto loc_82648BE4;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82648BE4;
	sub_82130588(ctx, base);
loc_82648BE4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82648BEC;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648BF4;
	sub_8221FCC8(ctx, base);
	// addis r29,r31,2
	r29.s64 = r31.s64 + 131072;
	// addi r29,r29,23344
	r29.s64 = r29.s64 + 23344;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// lhz r11,1002(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648c14
	if (cr6.eq) goto loc_82648C14;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82648C14;
	sub_82130588(ctx, base);
loc_82648C14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82648C1C;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648C24;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,21840
	ctx.r3.s64 = ctx.r3.s64 + 21840;
	// bl 0x82676798
	ctx.lr = 0x82648C30;
	sub_82676798(ctx, base);
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r30,r30,20816
	r30.s64 = r30.s64 + 20816;
	// addi r10,r11,12916
	ctx.r10.s64 = r11.s64 + 12916;
	// lwz r3,1008(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1008);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82648c58
	if (cr6.eq) goto loc_82648C58;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82648C58;
	sub_821EC060(ctx, base);
loc_82648C58:
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x82648C60;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648C68;
	sub_8221FCC8(ctx, base);
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,18000
	r30.s64 = r30.s64 + 18000;
	// addi r3,r30,1008
	ctx.r3.s64 = r30.s64 + 1008;
	// bl 0x8221fbc8
	ctx.lr = 0x82648C78;
	sub_8221FBC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// addi r10,r11,4588
	ctx.r10.s64 = r11.s64 + 4588;
	// stw r10,992(r30)
	PPC_STORE_U32(r30.u32 + 992, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82648C8C;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648C94;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,12560
	ctx.r3.s64 = ctx.r3.s64 + 12560;
	// bl 0x8264d6d8
	ctx.lr = 0x82648CA0;
	sub_8264D6D8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,8464
	ctx.r3.s64 = ctx.r3.s64 + 8464;
	// bl 0x826484e8
	ctx.lr = 0x82648CAC;
	sub_826484E8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,2576
	ctx.r3.s64 = ctx.r3.s64 + 2576;
	// bl 0x826483e0
	ctx.lr = 0x82648CB8;
	sub_826483E0(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-960
	ctx.r3.s64 = ctx.r3.s64 + -960;
	// bl 0x82648330
	ctx.lr = 0x82648CC4;
	sub_82648330(ctx, base);
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,-3760
	r30.s64 = r30.s64 + -3760;
	// addi r3,r30,2784
	ctx.r3.s64 = r30.s64 + 2784;
	// bl 0x821d2028
	ctx.lr = 0x82648CD4;
	sub_821D2028(ctx, base);
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x82648CDC;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648CE4;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-10976
	ctx.r3.s64 = ctx.r3.s64 + -10976;
	// bl 0x826482d0
	ctx.lr = 0x82648CF0;
	sub_826482D0(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-17328
	ctx.r3.s64 = ctx.r3.s64 + -17328;
	// bl 0x8267a050
	ctx.lr = 0x82648CFC;
	sub_8267A050(ctx, base);
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,-20128
	r30.s64 = r30.s64 + -20128;
	// addi r3,r30,2784
	ctx.r3.s64 = r30.s64 + 2784;
	// bl 0x821d2028
	ctx.lr = 0x82648D0C;
	sub_821D2028(ctx, base);
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x82648D14;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82648D1C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-24624
	ctx.r3.s64 = ctx.r3.s64 + -24624;
	// bl 0x82646bc8
	ctx.lr = 0x82648D28;
	sub_82646BC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-27616
	ctx.r3.s64 = ctx.r3.s64 + -27616;
	// bl 0x82646b48
	ctx.lr = 0x82648D34;
	sub_82646B48(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-32640
	ctx.r3.s64 = ctx.r3.s64 + -32640;
	// bl 0x826440a8
	ctx.lr = 0x82648D40;
	sub_826440A8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,31904
	ctx.r3.s64 = ctx.r3.s64 + 31904;
	// bl 0x8221fcc8
	ctx.lr = 0x82648D4C;
	sub_8221FCC8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,30112
	ctx.r3.s64 = ctx.r3.s64 + 30112;
	// bl 0x8221fbc8
	ctx.lr = 0x82648D58;
	sub_8221FBC8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,19760
	ctx.r3.s64 = ctx.r3.s64 + 19760;
	// bl 0x82647e40
	ctx.lr = 0x82648D64;
	sub_82647E40(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,14048
	ctx.r3.s64 = ctx.r3.s64 + 14048;
	// bl 0x826438b8
	ctx.lr = 0x82648D70;
	sub_826438B8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,13136
	ctx.r3.s64 = ctx.r3.s64 + 13136;
	// bl 0x82641d90
	ctx.lr = 0x82648D7C;
	sub_82641D90(ctx, base);
	// addi r30,r31,2672
	r30.s64 = r31.s64 + 2672;
	// addi r3,r30,480
	ctx.r3.s64 = r30.s64 + 480;
	// bl 0x826628b0
	ctx.lr = 0x82648D88;
	sub_826628B0(ctx, base);
	// lhz r9,3110(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 3110);
	// addi r29,r30,256
	r29.s64 = r30.s64 + 256;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82648da0
	if (cr6.eq) goto loc_82648DA0;
	// lwz r3,176(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82648DA0;
	sub_82130588(ctx, base);
loc_82648DA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648DA8;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648DB0;
	sub_82633B00(ctx, base);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// bl 0x82633b00
	ctx.lr = 0x82648DB8;
	sub_82633B00(ctx, base);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x82646f40
	ctx.lr = 0x82648DC0;
	sub_82646F40(ctx, base);
	// addi r30,r31,512
	r30.s64 = r31.s64 + 512;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82648DCC;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648DD4;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82648DDC;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82648DE4;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82648DEC"))) PPC_WEAK_FUNC(sub_82648DEC);
PPC_FUNC_IMPL(__imp__sub_82648DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82648DF0"))) PPC_WEAK_FUNC(sub_82648DF0);
PPC_FUNC_IMPL(__imp__sub_82648DF0) {
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
	// bl 0x826485c8
	ctx.lr = 0x82648E10;
	sub_826485C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82648e28
	if (cr6.eq) goto loc_82648E28;
	// bl 0x82130588
	ctx.lr = 0x82648E24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82648E28:
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

__attribute__((alias("__imp__sub_82648E40"))) PPC_WEAK_FUNC(sub_82648E40);
PPC_FUNC_IMPL(__imp__sub_82648E40) {
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
	ctx.lr = 0x82648E48;
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,29988
	ctx.r4.s64 = r11.s64 + 29988;
	// li r5,112
	ctx.r5.s64 = 112;
	// stw r31,644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 644, r31.u32);
	// bl 0x82633e80
	ctx.lr = 0x82648E64;
	sub_82633E80(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r9,r10,29204
	ctx.r9.s64 = ctx.r10.s64 + 29204;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r30.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633dc8
	ctx.lr = 0x82648E84;
	sub_82633DC8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// addi r7,r8,4620
	ctx.r7.s64 = ctx.r8.s64 + 4620;
	// stw r29,204(r30)
	PPC_STORE_U32(r30.u32 + 204, r29.u32);
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// stw r3,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// bl 0x82653ea0
	ctx.lr = 0x82648EA4;
	sub_82653EA0(ctx, base);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// stw r3,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
	// bl 0x82662738
	ctx.lr = 0x82648EB0;
	sub_82662738(ctx, base);
	// addi r30,r31,2400
	r30.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// bl 0x82633dc8
	ctx.lr = 0x82648EC4;
	sub_82633DC8(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r28,1
	r28.s64 = 1;
	// stw r29,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r29.u32);
	// addi r5,r6,5764
	ctx.r5.s64 = ctx.r6.s64 + 5764;
	// stw r29,204(r30)
	PPC_STORE_U32(r30.u32 + 204, r29.u32);
	// stb r28,256(r30)
	PPC_STORE_U8(r30.u32 + 256, r28.u8);
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// stw r3,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// bl 0x82668348
	ctx.lr = 0x82648EEC;
	sub_82668348(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,13136
	ctx.r3.s64 = ctx.r3.s64 + 13136;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x82643ca0
	ctx.lr = 0x82648EFC;
	sub_82643CA0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,14048
	ctx.r3.s64 = ctx.r3.s64 + 14048;
	// stw r3,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r3.u32);
	// bl 0x826521a0
	ctx.lr = 0x82648F0C;
	sub_826521A0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,19760
	ctx.r3.s64 = ctx.r3.s64 + 19760;
	// stw r3,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r3.u32);
	// bl 0x8265b4d8
	ctx.lr = 0x82648F1C;
	sub_8265B4D8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,30112
	ctx.r3.s64 = ctx.r3.s64 + 30112;
	// stw r3,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r3.u32);
	// bl 0x82634b60
	ctx.lr = 0x82648F2C;
	sub_82634B60(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,31904
	ctx.r3.s64 = ctx.r3.s64 + 31904;
	// stw r3,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// bl 0x82676568
	ctx.lr = 0x82648F3C;
	sub_82676568(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-32640
	ctx.r3.s64 = ctx.r3.s64 + -32640;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// bl 0x8265b1e8
	ctx.lr = 0x82648F4C;
	sub_8265B1E8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-27616
	ctx.r3.s64 = ctx.r3.s64 + -27616;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// bl 0x8265c810
	ctx.lr = 0x82648F5C;
	sub_8265C810(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-24624
	ctx.r3.s64 = ctx.r3.s64 + -24624;
	// stw r3,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r3.u32);
	// bl 0x8264e250
	ctx.lr = 0x82648F6C;
	sub_8264E250(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-20128
	ctx.r3.s64 = ctx.r3.s64 + -20128;
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// bl 0x8264cfb8
	ctx.lr = 0x82648F7C;
	sub_8264CFB8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-17328
	ctx.r3.s64 = ctx.r3.s64 + -17328;
	// stw r3,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// bl 0x8267a530
	ctx.lr = 0x82648F8C;
	sub_8267A530(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-10976
	ctx.r3.s64 = ctx.r3.s64 + -10976;
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// bl 0x8264df48
	ctx.lr = 0x82648F9C;
	sub_8264DF48(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-3760
	ctx.r3.s64 = ctx.r3.s64 + -3760;
	// stw r3,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r3.u32);
	// bl 0x8264d2c0
	ctx.lr = 0x82648FAC;
	sub_8264D2C0(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,-960
	ctx.r3.s64 = ctx.r3.s64 + -960;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// bl 0x8264d378
	ctx.lr = 0x82648FBC;
	sub_8264D378(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,2576
	ctx.r3.s64 = ctx.r3.s64 + 2576;
	// stw r3,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// bl 0x8264d908
	ctx.lr = 0x82648FCC;
	sub_8264D908(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,8464
	ctx.r3.s64 = ctx.r3.s64 + 8464;
	// stw r3,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r3.u32);
	// bl 0x8264dbc8
	ctx.lr = 0x82648FDC;
	sub_8264DBC8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,12560
	ctx.r3.s64 = ctx.r3.s64 + 12560;
	// stw r3,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r3.u32);
	// bl 0x8264d4f8
	ctx.lr = 0x82648FEC;
	sub_8264D4F8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,18000
	ctx.r3.s64 = ctx.r3.s64 + 18000;
	// stw r3,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// bl 0x82644290
	ctx.lr = 0x82648FFC;
	sub_82644290(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,20816
	ctx.r3.s64 = ctx.r3.s64 + 20816;
	// stw r3,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r3.u32);
	// bl 0x826443a0
	ctx.lr = 0x8264900C;
	sub_826443A0(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,21840
	ctx.r3.s64 = ctx.r3.s64 + 21840;
	// stw r3,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r3.u32);
	// bl 0x82677c40
	ctx.lr = 0x8264901C;
	sub_82677C40(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,23344
	ctx.r3.s64 = ctx.r3.s64 + 23344;
	// stw r3,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// bl 0x826769c8
	ctx.lr = 0x8264902C;
	sub_826769C8(ctx, base);
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,24368
	r30.s64 = r30.s64 + 24368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r30.u32);
	// bl 0x826769c8
	ctx.lr = 0x82649040;
	sub_826769C8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r11,r4,26764
	r11.s64 = ctx.r4.s64 + 26764;
	// addi r3,r3,25392
	ctx.r3.s64 = ctx.r3.s64 + 25392;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// bl 0x82644430
	ctx.lr = 0x8264905C;
	sub_82644430(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,27632
	ctx.r3.s64 = ctx.r3.s64 + 27632;
	// stw r3,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r3.u32);
	// bl 0x826776a8
	ctx.lr = 0x8264906C;
	sub_826776A8(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,28640
	ctx.r3.s64 = ctx.r3.s64 + 28640;
	// stw r3,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// bl 0x82677658
	ctx.lr = 0x8264907C;
	sub_82677658(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,29648
	ctx.r3.s64 = ctx.r3.s64 + 29648;
	// stw r3,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// bl 0x82677988
	ctx.lr = 0x8264908C;
	sub_82677988(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,30896
	ctx.r3.s64 = ctx.r3.s64 + 30896;
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// bl 0x82677608
	ctx.lr = 0x8264909C;
	sub_82677608(ctx, base);
	// addis r3,r31,2
	ctx.r3.s64 = r31.s64 + 131072;
	// addi r3,r3,31904
	ctx.r3.s64 = ctx.r3.s64 + 31904;
	// stw r3,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// bl 0x82677fd0
	ctx.lr = 0x826490AC;
	sub_82677FD0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-31968
	ctx.r3.s64 = ctx.r3.s64 + -31968;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// bl 0x826782a8
	ctx.lr = 0x826490BC;
	sub_826782A8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-30736
	ctx.r3.s64 = ctx.r3.s64 + -30736;
	// stw r3,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r3.u32);
	// bl 0x82677ef8
	ctx.lr = 0x826490CC;
	sub_82677EF8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-29744
	ctx.r3.s64 = ctx.r3.s64 + -29744;
	// stw r3,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r3.u32);
	// bl 0x826788c8
	ctx.lr = 0x826490DC;
	sub_826788C8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-26048
	ctx.r3.s64 = ctx.r3.s64 + -26048;
	// stw r3,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r3.u32);
	// bl 0x82678a48
	ctx.lr = 0x826490EC;
	sub_82678A48(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-24976
	ctx.r3.s64 = ctx.r3.s64 + -24976;
	// stw r3,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r3.u32);
	// bl 0x82674ed8
	ctx.lr = 0x826490FC;
	sub_82674ED8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-24720
	ctx.r3.s64 = ctx.r3.s64 + -24720;
	// stw r3,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// bl 0x826776f8
	ctx.lr = 0x8264910C;
	sub_826776F8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-23712
	ctx.r3.s64 = ctx.r3.s64 + -23712;
	// stw r3,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// bl 0x82677818
	ctx.lr = 0x8264911C;
	sub_82677818(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-22656
	ctx.r3.s64 = ctx.r3.s64 + -22656;
	// stw r3,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r3.u32);
	// bl 0x826441d0
	ctx.lr = 0x8264912C;
	sub_826441D0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-21648
	ctx.r3.s64 = ctx.r3.s64 + -21648;
	// stw r3,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r3.u32);
	// bl 0x82646fb8
	ctx.lr = 0x8264913C;
	sub_82646FB8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-20640
	ctx.r3.s64 = ctx.r3.s64 + -20640;
	// stw r3,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// bl 0x826783c8
	ctx.lr = 0x8264914C;
	sub_826783C8(ctx, base);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r30,-19632
	r30.s64 = r30.s64 + -19632;
	// addi r4,r10,5700
	ctx.r4.s64 = ctx.r10.s64 + 5700;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// bl 0x82654428
	ctx.lr = 0x82649168;
	sub_82654428(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r8,11284
	ctx.r6.s64 = ctx.r8.s64 + 11284;
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// stfs f0,1008(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 1008, temp.u32);
	// addi r27,r7,3998
	r27.s64 = ctx.r7.s64 + 3998;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r3,r3,-18608
	ctx.r3.s64 = ctx.r3.s64 + -18608;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r4,29972
	ctx.r4.s64 = ctx.r4.s64 + 29972;
	// stw r3,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x82654318
	ctx.lr = 0x826491B4;
	sub_82654318(ctx, base);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r30,r30,-17616
	r30.s64 = r30.s64 + -17616;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8228f920
	ctx.lr = 0x826491E0;
	sub_8228F920(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stb r28,245(r30)
	PPC_STORE_U8(r30.u32 + 245, r28.u8);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r10,r11,28396
	ctx.r10.s64 = r11.s64 + 28396;
	// addi r3,r3,-16656
	ctx.r3.s64 = ctx.r3.s64 + -16656;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// bl 0x826445c0
	ctx.lr = 0x82649200;
	sub_826445C0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-15600
	ctx.r3.s64 = ctx.r3.s64 + -15600;
	// stw r3,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// bl 0x826448a0
	ctx.lr = 0x82649210;
	sub_826448A0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-14576
	ctx.r3.s64 = ctx.r3.s64 + -14576;
	// stw r3,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r3.u32);
	// bl 0x82644ae0
	ctx.lr = 0x82649220;
	sub_82644AE0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-12752
	ctx.r3.s64 = ctx.r3.s64 + -12752;
	// stw r3,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r3.u32);
	// bl 0x82644dd8
	ctx.lr = 0x82649230;
	sub_82644DD8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-11504
	ctx.r3.s64 = ctx.r3.s64 + -11504;
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// bl 0x82645168
	ctx.lr = 0x82649240;
	sub_82645168(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-10464
	ctx.r3.s64 = ctx.r3.s64 + -10464;
	// stw r3,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r3.u32);
	// bl 0x82645468
	ctx.lr = 0x82649250;
	sub_82645468(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-9408
	ctx.r3.s64 = ctx.r3.s64 + -9408;
	// stw r3,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r3.u32);
	// bl 0x82645800
	ctx.lr = 0x82649260;
	sub_82645800(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-8352
	ctx.r3.s64 = ctx.r3.s64 + -8352;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// bl 0x8267f638
	ctx.lr = 0x82649270;
	sub_8267F638(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-5152
	ctx.r3.s64 = ctx.r3.s64 + -5152;
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// bl 0x8267f788
	ctx.lr = 0x82649280;
	sub_8267F788(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-3552
	ctx.r3.s64 = ctx.r3.s64 + -3552;
	// stw r3,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r3.u32);
	// bl 0x8267fe08
	ctx.lr = 0x82649290;
	sub_8267FE08(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-1856
	ctx.r3.s64 = ctx.r3.s64 + -1856;
	// stw r3,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r3.u32);
	// bl 0x8267b370
	ctx.lr = 0x826492A0;
	sub_8267B370(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,-768
	ctx.r3.s64 = ctx.r3.s64 + -768;
	// stw r3,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r3.u32);
	// bl 0x8267bd60
	ctx.lr = 0x826492B0;
	sub_8267BD60(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,1136
	ctx.r3.s64 = ctx.r3.s64 + 1136;
	// stw r3,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r3.u32);
	// bl 0x8267c0d8
	ctx.lr = 0x826492C0;
	sub_8267C0D8(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,3120
	ctx.r3.s64 = ctx.r3.s64 + 3120;
	// stw r3,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r3.u32);
	// bl 0x8267b748
	ctx.lr = 0x826492D0;
	sub_8267B748(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,4816
	ctx.r3.s64 = ctx.r3.s64 + 4816;
	// stw r3,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r3.u32);
	// bl 0x82645e18
	ctx.lr = 0x826492E0;
	sub_82645E18(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,5856
	ctx.r3.s64 = ctx.r3.s64 + 5856;
	// stw r3,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r3.u32);
	// bl 0x82645ec0
	ctx.lr = 0x826492F0;
	sub_82645EC0(ctx, base);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// addi r3,r3,7680
	ctx.r3.s64 = ctx.r3.s64 + 7680;
	// stw r3,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r3.u32);
	// bl 0x82645fd8
	ctx.lr = 0x82649300;
	sub_82645FD8(ctx, base);
	// li r3,1616
	ctx.r3.s64 = 1616;
	// bl 0x82130528
	ctx.lr = 0x82649308;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264931c
	if (cr6.eq) goto loc_8264931C;
	// bl 0x8266dc60
	ctx.lr = 0x82649314;
	sub_8266DC60(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649320
	goto loc_82649320;
loc_8264931C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649320:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,1856
	ctx.r3.s64 = 1856;
	// addi r11,r11,8848
	r11.s64 = r11.s64 + 8848;
	// stw r11,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649338;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264934c
	if (cr6.eq) goto loc_8264934C;
	// bl 0x8266e848
	ctx.lr = 0x82649344;
	sub_8266E848(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649350
	goto loc_82649350;
loc_8264934C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649350:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,1856
	ctx.r3.s64 = 1856;
	// addi r11,r11,8852
	r11.s64 = r11.s64 + 8852;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649368;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264937c
	if (cr6.eq) goto loc_8264937C;
	// bl 0x8266e228
	ctx.lr = 0x82649374;
	sub_8266E228(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649380
	goto loc_82649380;
loc_8264937C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649380:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,5072
	ctx.r3.s64 = 5072;
	// addi r11,r11,8856
	r11.s64 = r11.s64 + 8856;
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649398;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826493ac
	if (cr6.eq) goto loc_826493AC;
	// bl 0x82671230
	ctx.lr = 0x826493A4;
	sub_82671230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x826493b0
	goto loc_826493B0;
loc_826493AC:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826493B0:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,2064
	ctx.r3.s64 = 2064;
	// addi r11,r11,8860
	r11.s64 = r11.s64 + 8860;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x826493C8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826493dc
	if (cr6.eq) goto loc_826493DC;
	// bl 0x8266dde0
	ctx.lr = 0x826493D4;
	sub_8266DDE0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x826493e0
	goto loc_826493E0;
loc_826493DC:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826493E0:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,2240
	ctx.r3.s64 = 2240;
	// addi r11,r11,8864
	r11.s64 = r11.s64 + 8864;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x826493F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264940c
	if (cr6.eq) goto loc_8264940C;
	// bl 0x8266ece8
	ctx.lr = 0x82649404;
	sub_8266ECE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649410
	goto loc_82649410;
loc_8264940C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649410:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,10864
	ctx.r3.s64 = 10864;
	// addi r11,r11,8868
	r11.s64 = r11.s64 + 8868;
	// stw r11,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649428;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264943c
	if (cr6.eq) goto loc_8264943C;
	// bl 0x8266f128
	ctx.lr = 0x82649434;
	sub_8266F128(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649440
	goto loc_82649440;
loc_8264943C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649440:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,10896
	ctx.r3.s64 = 10896;
	// addi r11,r11,8872
	r11.s64 = r11.s64 + 8872;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649458;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264946c
	if (cr6.eq) goto loc_8264946C;
	// bl 0x8266f830
	ctx.lr = 0x82649464;
	sub_8266F830(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82649470
	goto loc_82649470;
loc_8264946C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82649470:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,10864
	ctx.r3.s64 = 10864;
	// addi r11,r11,8876
	r11.s64 = r11.s64 + 8876;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82649488;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264949c
	if (cr6.eq) goto loc_8264949C;
	// bl 0x82670a58
	ctx.lr = 0x82649494;
	sub_82670A58(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x826494a0
	goto loc_826494A0;
loc_8264949C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826494A0:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,10608
	ctx.r3.s64 = 10608;
	// addi r11,r11,8880
	r11.s64 = r11.s64 + 8880;
	// stw r11,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x826494B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826494cc
	if (cr6.eq) goto loc_826494CC;
	// bl 0x8266ff70
	ctx.lr = 0x826494C4;
	sub_8266FF70(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x826494d0
	goto loc_826494D0;
loc_826494CC:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826494D0:
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// li r3,10896
	ctx.r3.s64 = 10896;
	// addi r11,r11,8884
	r11.s64 = r11.s64 + 8884;
	// stw r11,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x826494E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826494fc
	if (cr6.eq) goto loc_826494FC;
	// bl 0x82670fa0
	ctx.lr = 0x826494F4;
	sub_82670FA0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82649500
	goto loc_82649500;
loc_826494FC:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82649500:
	// addis r10,r31,3
	ctx.r10.s64 = r31.s64 + 196608;
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// addi r10,r10,8888
	ctx.r10.s64 = ctx.r10.s64 + 8888;
	// addi r9,r9,8896
	ctx.r9.s64 = ctx.r9.s64 + 8896;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stw r9,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r9.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// bl 0x8267dfc0
	ctx.lr = 0x82649524;
	sub_8267DFC0(ctx, base);
	// addis r8,r31,3
	ctx.r8.s64 = r31.s64 + 196608;
	// addi r8,r8,9840
	ctx.r8.s64 = ctx.r8.s64 + 9840;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stw r8,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r8.u32);
	// bl 0x8267e050
	ctx.lr = 0x82649538;
	sub_8267E050(ctx, base);
	// addis r7,r31,3
	ctx.r7.s64 = r31.s64 + 196608;
	// addi r7,r7,10784
	ctx.r7.s64 = ctx.r7.s64 + 10784;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// bl 0x8267e0d0
	ctx.lr = 0x8264954C;
	sub_8267E0D0(ctx, base);
	// addis r6,r31,3
	ctx.r6.s64 = r31.s64 + 196608;
	// addi r6,r6,11728
	ctx.r6.s64 = ctx.r6.s64 + 11728;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x8267e150
	ctx.lr = 0x82649560;
	sub_8267E150(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addi r5,r5,12688
	ctx.r5.s64 = ctx.r5.s64 + 12688;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r5,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r5.u32);
	// bl 0x8267e1d8
	ctx.lr = 0x82649574;
	sub_8267E1D8(ctx, base);
	// addis r4,r31,3
	ctx.r4.s64 = r31.s64 + 196608;
	// addi r4,r4,13632
	ctx.r4.s64 = ctx.r4.s64 + 13632;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r4,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// bl 0x8267e258
	ctx.lr = 0x82649588;
	sub_8267E258(ctx, base);
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// addi r11,r11,14576
	r11.s64 = r11.s64 + 14576;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// bl 0x8267e2d8
	ctx.lr = 0x8264959C;
	sub_8267E2D8(ctx, base);
	// addis r10,r31,3
	ctx.r10.s64 = r31.s64 + 196608;
	// addi r10,r10,15520
	ctx.r10.s64 = ctx.r10.s64 + 15520;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r10,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r10.u32);
	// bl 0x8267e368
	ctx.lr = 0x826495B0;
	sub_8267E368(ctx, base);
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// addi r9,r9,16464
	ctx.r9.s64 = ctx.r9.s64 + 16464;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// bl 0x8267e3f8
	ctx.lr = 0x826495C4;
	sub_8267E3F8(ctx, base);
	// addis r8,r31,3
	ctx.r8.s64 = r31.s64 + 196608;
	// addi r8,r8,17408
	ctx.r8.s64 = ctx.r8.s64 + 17408;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x8267e488
	ctx.lr = 0x826495D8;
	sub_8267E488(ctx, base);
	// addis r7,r31,3
	ctx.r7.s64 = r31.s64 + 196608;
	// addi r7,r7,18368
	ctx.r7.s64 = ctx.r7.s64 + 18368;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r7,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r7.u32);
	// bl 0x8267e520
	ctx.lr = 0x826495EC;
	sub_8267E520(ctx, base);
	// addis r6,r31,3
	ctx.r6.s64 = r31.s64 + 196608;
	// addi r6,r6,19312
	ctx.r6.s64 = ctx.r6.s64 + 19312;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r6,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r6.u32);
	// bl 0x8267e5a0
	ctx.lr = 0x82649600;
	sub_8267E5A0(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addi r5,r5,20256
	ctx.r5.s64 = ctx.r5.s64 + 20256;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r5,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r5.u32);
	// bl 0x8267e620
	ctx.lr = 0x82649614;
	sub_8267E620(ctx, base);
	// addis r4,r31,3
	ctx.r4.s64 = r31.s64 + 196608;
	// addi r4,r4,21200
	ctx.r4.s64 = ctx.r4.s64 + 21200;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r4,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r4.u32);
	// bl 0x8267e6a0
	ctx.lr = 0x82649628;
	sub_8267E6A0(ctx, base);
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// addi r11,r11,22144
	r11.s64 = r11.s64 + 22144;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, r11.u32);
	// bl 0x8267e720
	ctx.lr = 0x8264963C;
	sub_8267E720(ctx, base);
	// addis r10,r31,3
	ctx.r10.s64 = r31.s64 + 196608;
	// addi r10,r10,23088
	ctx.r10.s64 = ctx.r10.s64 + 23088;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r10,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r10.u32);
	// bl 0x8267e7a0
	ctx.lr = 0x82649650;
	sub_8267E7A0(ctx, base);
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// addi r9,r9,24032
	ctx.r9.s64 = ctx.r9.s64 + 24032;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stw r9,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r9.u32);
	// bl 0x8267e820
	ctx.lr = 0x82649664;
	sub_8267E820(ctx, base);
	// addis r8,r31,3
	ctx.r8.s64 = r31.s64 + 196608;
	// addi r8,r8,24976
	ctx.r8.s64 = ctx.r8.s64 + 24976;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stw r8,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r8.u32);
	// bl 0x8267e8a0
	ctx.lr = 0x82649678;
	sub_8267E8A0(ctx, base);
	// addis r7,r31,3
	ctx.r7.s64 = r31.s64 + 196608;
	// addi r7,r7,25920
	ctx.r7.s64 = ctx.r7.s64 + 25920;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r7,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r7.u32);
	// bl 0x8267e9a0
	ctx.lr = 0x8264968C;
	sub_8267E9A0(ctx, base);
	// addis r6,r31,3
	ctx.r6.s64 = r31.s64 + 196608;
	// addi r6,r6,26880
	ctx.r6.s64 = ctx.r6.s64 + 26880;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r6,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r6.u32);
	// bl 0x8267ea30
	ctx.lr = 0x826496A0;
	sub_8267EA30(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addi r5,r5,27824
	ctx.r5.s64 = ctx.r5.s64 + 27824;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r5,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r5.u32);
	// bl 0x8267eab0
	ctx.lr = 0x826496B4;
	sub_8267EAB0(ctx, base);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// addi r30,r30,28768
	r30.s64 = r30.s64 + 28768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8267eb30
	ctx.lr = 0x826496C4;
	sub_8267EB30(ctx, base);
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// addi r29,r29,29712
	r29.s64 = r29.s64 + 29712;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8267ebb0
	ctx.lr = 0x826496D4;
	sub_8267EBB0(ctx, base);
	// addis r28,r31,3
	r28.s64 = r31.s64 + 196608;
	// addi r28,r28,30656
	r28.s64 = r28.s64 + 30656;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8267ec30
	ctx.lr = 0x826496E4;
	sub_8267EC30(ctx, base);
	// addis r27,r31,3
	r27.s64 = r31.s64 + 196608;
	// addi r27,r27,31600
	r27.s64 = r27.s64 + 31600;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8267ecb0
	ctx.lr = 0x826496F4;
	sub_8267ECB0(ctx, base);
	// addis r26,r31,3
	r26.s64 = r31.s64 + 196608;
	// addi r26,r26,32544
	r26.s64 = r26.s64 + 32544;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8267ed30
	ctx.lr = 0x82649704;
	sub_8267ED30(ctx, base);
	// addis r25,r31,4
	r25.s64 = r31.s64 + 262144;
	// addi r25,r25,-32048
	r25.s64 = r25.s64 + -32048;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8267edc0
	ctx.lr = 0x82649714;
	sub_8267EDC0(ctx, base);
	// addis r24,r31,4
	r24.s64 = r31.s64 + 262144;
	// addi r24,r24,-31104
	r24.s64 = r24.s64 + -31104;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8267ee50
	ctx.lr = 0x82649724;
	sub_8267EE50(ctx, base);
	// addis r23,r31,4
	r23.s64 = r31.s64 + 262144;
	// addi r23,r23,-30160
	r23.s64 = r23.s64 + -30160;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8267eee0
	ctx.lr = 0x82649734;
	sub_8267EEE0(ctx, base);
	// addis r22,r31,4
	r22.s64 = r31.s64 + 262144;
	// addi r22,r22,-29200
	r22.s64 = r22.s64 + -29200;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8267ef70
	ctx.lr = 0x82649744;
	sub_8267EF70(ctx, base);
	// addis r21,r31,4
	r21.s64 = r31.s64 + 262144;
	// addi r21,r21,-28240
	r21.s64 = r21.s64 + -28240;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8267eff8
	ctx.lr = 0x82649754;
	sub_8267EFF8(ctx, base);
	// addis r20,r31,4
	r20.s64 = r31.s64 + 262144;
	// addi r20,r20,-27280
	r20.s64 = r20.s64 + -27280;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8267f088
	ctx.lr = 0x82649764;
	sub_8267F088(ctx, base);
	// addis r19,r31,4
	r19.s64 = r31.s64 + 262144;
	// addi r19,r19,-26320
	r19.s64 = r19.s64 + -26320;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82643778
	ctx.lr = 0x82649774;
	sub_82643778(ctx, base);
	// addis r18,r31,4
	r18.s64 = r31.s64 + 262144;
	// addi r18,r18,-25840
	r18.s64 = r18.s64 + -25840;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826464d8
	ctx.lr = 0x82649784;
	sub_826464D8(ctx, base);
	// addis r17,r31,4
	r17.s64 = r31.s64 + 262144;
	// addi r17,r17,-22608
	r17.s64 = r17.s64 + -22608;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826462d8
	ctx.lr = 0x82649794;
	sub_826462D8(ctx, base);
	// addis r16,r31,4
	r16.s64 = r31.s64 + 262144;
	// addi r16,r16,-21584
	r16.s64 = r16.s64 + -21584;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x82646800
	ctx.lr = 0x826497A4;
	sub_82646800(ctx, base);
	// addis r15,r31,4
	r15.s64 = r31.s64 + 262144;
	// addi r15,r15,-17184
	r15.s64 = r15.s64 + -17184;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x826468b8
	ctx.lr = 0x826497B4;
	sub_826468B8(ctx, base);
	// addis r14,r31,4
	r14.s64 = r31.s64 + 262144;
	// addi r14,r14,-14144
	r14.s64 = r14.s64 + -14144;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x8265c8f8
	ctx.lr = 0x826497C4;
	sub_8265C8F8(ctx, base);
	// addis r11,r31,4
	r11.s64 = r31.s64 + 262144;
	// addi r11,r11,-12784
	r11.s64 = r11.s64 + -12784;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, r11.u32);
	// bl 0x8267e920
	ctx.lr = 0x826497D8;
	sub_8267E920(ctx, base);
	// lwz r4,644(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// addis r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 262144;
	// addi r3,r3,-11840
	ctx.r3.s64 = ctx.r3.s64 + -11840;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// bl 0x826337a8
	ctx.lr = 0x826497EC;
	sub_826337A8(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r3,-14100
	ctx.r9.s64 = ctx.r3.s64 + -14100;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// stw r10,176(r11)
	PPC_STORE_U32(r11.u32 + 176, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r10,180(r11)
	PPC_STORE_U32(r11.u32 + 180, ctx.r10.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82649810;
	sub_821C2F70(ctx, base);
	// lwz r8,644(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r7,1
	ctx.r7.s64 = 1;
	// addis r5,r8,4
	ctx.r5.s64 = ctx.r8.s64 + 262144;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r5,r5,-11616
	ctx.r5.s64 = ctx.r5.s64 + -11616;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r7,204(r11)
	PPC_STORE_U8(r11.u32 + 204, ctx.r7.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r6,208(r11)
	PPC_STORE_U32(r11.u32 + 208, ctx.r6.u32);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// lwz r7,448(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 448);
	// stw r4,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
	// stw r3,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// addi r11,r11,68
	r11.s64 = r11.s64 + 68;
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r4,272(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// lwz r3,196(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lwz r5,232(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r6,192(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r8,144(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r31,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r31.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,132(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rotlwi r4,r8,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// rotlwi r3,r5,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r7,132(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stwx r9,r3,r4
	PPC_STORE_U32(ctx.r3.u32 + ctx.r4.u32, ctx.r9.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rotlwi r7,r3,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r11,268(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// stwx r6,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r6.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r5,328(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r7,68(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r9,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r9.u16);
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r7,68(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r7,68(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r9,r5,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r7,140(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r6,r11,2
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r7,440(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 440);
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r8,296(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// rotlwi r3,r6,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r6,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r6.u32);
	// lwz r6,188(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stwx r9,r3,r11
	PPC_STORE_U32(ctx.r3.u32 + r11.u32, ctx.r9.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r4,68(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r4,68(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r14,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, r14.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r14,152(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r4,316(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r3,324(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lwz r6,300(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r7,292(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// lwz r31,392(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// lwz r5,348(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// lwz r7,340(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r4.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r14,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r14.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r6,152(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r4,200(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r7,208(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// lwz r3,456(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 456);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r6,336(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r5,216(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// lwz r4,400(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	// lwz r31,224(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// lwz r14,344(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,120(r1)
	PPC_STORE_U16(ctx.r1.u32 + 120, ctx.r9.u16);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,120(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 120);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r4.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// stwx r31,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r31.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// lwz r7,432(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 432);
	// stwx r14,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r14.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r3,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r3.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// stwx r7,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r7.u32);
	// lwz r11,156(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r5,240(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r4,352(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lwz r3,248(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// lwz r7,408(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r11.u32);
	// lwz r6,256(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// lwz r31,360(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// lwz r14,264(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r4.u32);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stwx r3,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r3.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r5,156(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// lwz r3,180(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r6,280(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// lwz r31,172(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r14,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r14.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r11,368(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// lwz r5,416(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r3,288(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lwz r7,376(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	// lwz r14,148(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r9.u16);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r8,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r8.u32);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stwx r4,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r4.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// lwz r6,304(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r4,312(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// lwz r7,320(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r31,184(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r14,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r14.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r5,384(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 384);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwz r3,424(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	// sth r6,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r6.u16);
	// lwz r6,164(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r14,r11,1
	r14.s64 = r11.s64 + 1;
	// sth r14,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r14.u16);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r14,104(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r31,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r31.u32);
	// lwz r31,252(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// rotlwi r7,r3,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r9,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r18,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, r18.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r6,204(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r7,228(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r18,260(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// lwz r3,220(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r5,212(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// lwz r4,244(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// lwz r6,236(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r4,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r4.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// rotlwi r7,r10,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r31,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r31.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stwx r18,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r18.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r8,68(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// stwx r14,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r14.u32);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r6,68(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rotlwi r4,r6,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r17,r11,r4
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, r17.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r4,68(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r31,r11,2
	r31.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rotlwi r4,r4,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r11,r31,0
	r11.u64 = __builtin_rotateleft32(r31.u32, 0);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r6,276(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r5,284(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// stwx r16,r11,r4
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, r16.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r10,68(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r31,r10,0
	r31.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rotlwi r4,r11,2
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// sth r11,72(r9)
	PPC_STORE_U16(ctx.r9.u32 + 72, r11.u16);
	// rotlwi r11,r4,0
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stwx r15,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r15.u32);
	// lhz r11,72(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 72);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,644(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// sth r4,72(r11)
	PPC_STORE_U16(r11.u32 + 72, ctx.r4.u16);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// stwx r6,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r6.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// rotlwi r4,r7,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r9,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r9.u16);
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// sth r7,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r7.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,160(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// stwx r3,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r3.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r4,r11,2
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// rotlwi r7,r4,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r4,308(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r8.u32);
	// lwz r7,168(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r31,644(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r6,68(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// sth r3,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r3.u16);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// lwz r8,168(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r6,332(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r11,160(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// stwx r4,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r4.u32);
	// lwz r4,68(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// rotlwi r4,r11,2
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r8.u16);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stwx r9,r8,r4
	PPC_STORE_U32(ctx.r8.u32 + ctx.r4.u32, ctx.r9.u32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// lwz r7,68(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// rotlwi r4,r11,2
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stwx r6,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r6,68(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// rotlwi r9,r6,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, ctx.r4.u16);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stwx r5,r6,r9
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r5,68(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r11,72(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 72);
	// rotlwi r4,r11,2
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// rotlwi r7,r4,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// sth r11,72(r10)
	PPC_STORE_U16(ctx.r10.u32 + 72, r11.u16);
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lwz r5,356(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lwz r4,364(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// lwz r18,412(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// lwz r17,420(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	// lwz r16,428(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 428);
	// stwx r3,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r3.u32);
	// lwz r8,372(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r7,380(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r3,404(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// lwz r6,388(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r5,396(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r4,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r4.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r7,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r5,436(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 436);
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r18,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r18.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r4.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// stwx r17,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r17.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r16,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r16.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// lwz r30,452(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 452);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r29,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r29.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// stwx r28,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r28.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r27,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r27.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r26,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r26.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r24,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r24.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r23,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r23.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r22,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r22.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r21,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r21.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r6,444(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// stwx r19,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r19.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r29,460(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 460);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r20,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r20.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r29,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r29.u32);
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
	// bl 0x82630420
	ctx.lr = 0x8264A6FC;
	sub_82630420(ctx, base);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264A714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8264A720"))) PPC_WEAK_FUNC(sub_8264A720);
PPC_FUNC_IMPL(__imp__sub_8264A720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8264A728;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264A748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8264a760
	if (!cr6.eq) goto loc_8264A760;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264A760:
	// bl 0x823bbf80
	ctx.lr = 0x8264A764;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r27,1
	r27.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264a794
	if (!cr6.eq) goto loc_8264A794;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x8264A784;
	sub_822040F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// beq cr6,0x8264a798
	if (cr6.eq) goto loc_8264A798;
loc_8264A794:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8264A798:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r25,r11,-21500
	r25.s64 = r11.s64 + -21500;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r8,22440
	ctx.r4.s64 = ctx.r8.s64 + 22440;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r24,-24180(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24180);
	// clrlwi r30,r10,24
	r30.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x823db670
	ctx.lr = 0x8264A7C4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8264A7D8;
	sub_821FD7C0(ctx, base);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// lwz r7,10248(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r29,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r29.u8);
	// stw r29,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r29.u32);
	// stw r25,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r25.u32);
	// stw r7,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r7.u32);
	// beq cr6,0x8264a810
	if (cr6.eq) goto loc_8264A810;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// or r30,r8,r30
	r30.u64 = ctx.r8.u64 | r30.u64;
loc_8264A810:
	// addi r11,r28,-17
	r11.s64 = r28.s64 + -17;
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bgt cr6,0x8264ab38
	if (cr6.gt) goto loc_8264AB38;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-22476
	r12.s64 = r12.s64 + -22476;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8264A8F0;
	case 1:
		goto loc_8264AB38;
	case 2:
		goto loc_8264AB38;
	case 3:
		goto loc_8264AB38;
	case 4:
		goto loc_8264AB38;
	case 5:
		goto loc_8264AB38;
	case 6:
		goto loc_8264AB38;
	case 7:
		goto loc_8264AB38;
	case 8:
		goto loc_8264AB38;
	case 9:
		goto loc_8264AB38;
	case 10:
		goto loc_8264AB38;
	case 11:
		goto loc_8264AB38;
	case 12:
		goto loc_8264AB38;
	case 13:
		goto loc_8264AB38;
	case 14:
		goto loc_8264AB38;
	case 15:
		goto loc_8264AB38;
	case 16:
		goto loc_8264AB38;
	case 17:
		goto loc_8264AB38;
	case 18:
		goto loc_8264AB38;
	case 19:
		goto loc_8264AB38;
	case 20:
		goto loc_8264AB38;
	case 21:
		goto loc_8264AB38;
	case 22:
		goto loc_8264AB38;
	case 23:
		goto loc_8264AB38;
	case 24:
		goto loc_8264AB38;
	case 25:
		goto loc_8264AB38;
	case 26:
		goto loc_8264AB38;
	case 27:
		goto loc_8264AB38;
	case 28:
		goto loc_8264AB38;
	case 29:
		goto loc_8264AB38;
	case 30:
		goto loc_8264AB38;
	case 31:
		goto loc_8264AB38;
	case 32:
		goto loc_8264AB38;
	case 33:
		goto loc_8264AB38;
	case 34:
		goto loc_8264AB38;
	case 35:
		goto loc_8264AB38;
	case 36:
		goto loc_8264AB38;
	case 37:
		goto loc_8264AB38;
	case 38:
		goto loc_8264A9BC;
	case 39:
		goto loc_8264A930;
	case 40:
		goto loc_8264AB38;
	case 41:
		goto loc_8264AB38;
	case 42:
		goto loc_8264AA50;
	case 43:
		goto loc_8264AB38;
	case 44:
		goto loc_8264AB38;
	case 45:
		goto loc_8264AAE0;
	case 46:
		goto loc_8264AAA8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-22288(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -22288);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-22084(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -22084);
	// lwz r19,-22224(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -22224);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21936(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21936);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21704);
	// lwz r19,-21792(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21792);
	// lwz r19,-21848(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -21848);
loc_8264A8F0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264a924
	if (!cr6.eq) goto loc_8264A924;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264A908;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264A920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82641e80
	ctx.lr = 0x8264A924;
	sub_82641E80(ctx, base);
loc_8264A924:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264A930:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264a924
	if (!cr6.eq) goto loc_8264A924;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264A948;
	sub_821E6800(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,864(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// bne cr6,0x8264a984
	if (!cr6.eq) goto loc_8264A984;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r9,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r9.u32);
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x8264a998
	goto loc_8264A998;
loc_8264A984:
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8264A998:
	// bctrl 
	ctx.lr = 0x8264A99C;
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
	ctx.lr = 0x8264A9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264A9BC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264a924
	if (!cr6.eq) goto loc_8264A924;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264A9D4;
	sub_821E6800(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8264aa10
	if (!cr6.eq) goto loc_8264AA10;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,864(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// lwz r3,-12640(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x8264aa2c
	goto loc_8264AA2C;
loc_8264AA10:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r27,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r27.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264AA2C:
	// bctrl 
	ctx.lr = 0x8264AA30;
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
	ctx.lr = 0x8264AA44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264AA50:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264AA5C;
	sub_821E6800(ctx, base);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// mulhw r11,r9,r8
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// subf r4,r5,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r5.s64;
	// stw r4,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r4.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264AA9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264AAA8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264AAB4;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264AAC4;
	sub_822A3998(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r8,880(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 880);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// stb r27,37(r7)
	PPC_STORE_U8(ctx.r7.u32 + 37, r27.u8);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264AAE0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264AAEC;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264AAFC;
	sub_822A3998(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,880(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 880);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// lbz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 36);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r4,36(r7)
	PPC_STORE_U8(ctx.r7.u32 + 36, ctx.r4.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264AB2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_8264AB38:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x8264AB48;
	sub_826309E0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8264AB50"))) PPC_WEAK_FUNC(sub_8264AB50);
PPC_FUNC_IMPL(__imp__sub_8264AB50) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264AB78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8264ab94
	if (!cr6.eq) goto loc_8264AB94;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264AB94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264AB94:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264ABA8"))) PPC_WEAK_FUNC(sub_8264ABA8);
PPC_FUNC_IMPL(__imp__sub_8264ABA8) {
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
	// stwu r1,-1440(r1)
	ea = -1440 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238c960
	ctx.lr = 0x8264ABC4;
	sub_8238C960(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,808(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 808);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264ABDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264ABF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,1440
	ctx.r1.s64 = ctx.r1.s64 + 1440;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264AC04"))) PPC_WEAK_FUNC(sub_8264AC04);
PPC_FUNC_IMPL(__imp__sub_8264AC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264AC08"))) PPC_WEAK_FUNC(sub_8264AC08);
PPC_FUNC_IMPL(__imp__sub_8264AC08) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264AC30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x8264ac58
	if (cr6.eq) goto loc_8264AC58;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,3088
	ctx.r3.s64 = r31.s64 + 3088;
	// bl 0x8262fff0
	ctx.lr = 0x8264AC44;
	sub_8262FFF0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8264AC58:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x821c3048
	ctx.lr = 0x8264AC64;
	sub_821C3048(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264AC78"))) PPC_WEAK_FUNC(sub_8264AC78);
PPC_FUNC_IMPL(__imp__sub_8264AC78) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x8264AC9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264ad28
	if (cr6.eq) goto loc_8264AD28;
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8264ad1c
	if (!cr6.eq) goto loc_8264AD1C;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-21496
	ctx.r4.s64 = r11.s64 + -21496;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8264ACD0;
	sub_821C2FB0(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r10,30616
	ctx.r6.s64 = ctx.r10.s64 + 30616;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r9,30596
	ctx.r5.s64 = ctx.r9.s64 + 30596;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,4064
	ctx.r3.s64 = r31.s64 + 4064;
	// bl 0x82634ec8
	ctx.lr = 0x8264AD08;
	sub_82634EC8(ctx, base);
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
loc_8264AD1C:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x821c3048
	ctx.lr = 0x8264AD28;
	sub_821C3048(ctx, base);
loc_8264AD28:
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

__attribute__((alias("__imp__sub_8264AD3C"))) PPC_WEAK_FUNC(sub_8264AD3C);
PPC_FUNC_IMPL(__imp__sub_8264AD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264AD40"))) PPC_WEAK_FUNC(sub_8264AD40);
PPC_FUNC_IMPL(__imp__sub_8264AD40) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r31,2784
	r11.s64 = r31.s64 + 2784;
	// lfs f0,1240(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1240);
	f0.f64 = double(temp.f32);
	// lfs f31,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f31.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lwz r9,3000(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3000);
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// stw r8,3000(r31)
	PPC_STORE_U32(r31.u32 + 3000, ctx.r8.u32);
	// beq cr6,0x8264ad9c
	if (cr6.eq) goto loc_8264AD9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264AD9C;
	sub_821C3048(ctx, base);
loc_8264AD9C:
	// lfs f0,1244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1244);
	f0.f64 = double(temp.f32);
	// lwz r10,3256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3256);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r11,r31,3040
	r11.s64 = r31.s64 + 3040;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// stw r9,3256(r31)
	PPC_STORE_U32(r31.u32 + 3256, ctx.r9.u32);
	// beq cr6,0x8264add0
	if (cr6.eq) goto loc_8264ADD0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264ADD0;
	sub_821C3048(ctx, base);
loc_8264ADD0:
	// lfs f0,1248(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1248);
	f0.f64 = double(temp.f32);
	// lwz r10,3512(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3512);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r11,r31,3296
	r11.s64 = r31.s64 + 3296;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// stw r9,3512(r31)
	PPC_STORE_U32(r31.u32 + 3512, ctx.r9.u32);
	// beq cr6,0x8264ae04
	if (cr6.eq) goto loc_8264AE04;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264AE04;
	sub_821C3048(ctx, base);
loc_8264AE04:
	// lfs f0,1252(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1252);
	f0.f64 = double(temp.f32);
	// lwz r10,3768(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3768);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r11,r31,3552
	r11.s64 = r31.s64 + 3552;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// stw r9,3768(r31)
	PPC_STORE_U32(r31.u32 + 3768, ctx.r9.u32);
	// beq cr6,0x8264ae38
	if (cr6.eq) goto loc_8264AE38;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264AE38;
	sub_821C3048(ctx, base);
loc_8264AE38:
	// lfs f0,1256(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1256);
	f0.f64 = double(temp.f32);
	// lwz r10,4024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4024);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r11,r31,3808
	r11.s64 = r31.s64 + 3808;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// stw r9,4024(r31)
	PPC_STORE_U32(r31.u32 + 4024, ctx.r9.u32);
	// beq cr6,0x8264ae6c
	if (cr6.eq) goto loc_8264AE6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264AE6C;
	sub_821C3048(ctx, base);
loc_8264AE6C:
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

__attribute__((alias("__imp__sub_8264AE88"))) PPC_WEAK_FUNC(sub_8264AE88);
PPC_FUNC_IMPL(__imp__sub_8264AE88) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264AEA0;
	sub_82653B30(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264AEA4;
	sub_82387B90(ctx, base);
	// lwz r11,1320(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1320);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8264af14
	if (cr6.gt) goto loc_8264AF14;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-20788
	r12.s64 = r12.s64 + -20788;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8264AEEC;
	case 1:
		goto loc_8264AEF4;
	case 2:
		goto loc_8264AEE4;
	case 3:
		goto loc_8264AEFC;
	case 4:
		goto loc_8264AF0C;
	case 5:
		goto loc_8264AF04;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20756(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20756);
	// lwz r19,-20748(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20748);
	// lwz r19,-20764(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20764);
	// lwz r19,-20740(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20740);
	// lwz r19,-20724(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20724);
	// lwz r19,-20732(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20732);
loc_8264AEE4:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AEEC:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AEF4:
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AEFC:
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AF04:
	// li r4,5
	ctx.r4.s64 = 5;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AF0C:
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x8264af18
	goto loc_8264AF18;
loc_8264AF14:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8264AF18:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264AF2C;
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

__attribute__((alias("__imp__sub_8264AF40"))) PPC_WEAK_FUNC(sub_8264AF40);
PPC_FUNC_IMPL(__imp__sub_8264AF40) {
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
	ctx.lr = 0x8264AF5C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264afa4
	if (cr6.eq) goto loc_8264AFA4;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8264AF70;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x8264AF78;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264afa4
	if (cr6.eq) goto loc_8264AFA4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x8264AF88;
	sub_822A5578(ctx, base);
	// bl 0x822a0028
	ctx.lr = 0x8264AF8C;
	sub_822A0028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x8264AF94;
	sub_822A5578(ctx, base);
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8264AFA4;
	sub_8260B990(ctx, base);
loc_8264AFA4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264AFB8"))) PPC_WEAK_FUNC(sub_8264AFB8);
PPC_FUNC_IMPL(__imp__sub_8264AFB8) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8264AFD8;
	sub_82631F88(ctx, base);
	// lwz r30,856(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264afe8
	if (cr6.lt) goto loc_8264AFE8;
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
loc_8264AFE8:
	// mulli r11,r30,240
	r11.s64 = r30.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,2784
	ctx.r3.s64 = r11.s64 + 2784;
	// lwz r11,2784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2784);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264b050
	if (cr6.eq) goto loc_8264B050;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// extsh r4,r30
	ctx.r4.s64 = r30.s16;
	// lwz r3,-12052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8264B020;
	sub_82397BA8(ctx, base);
	// lbz r10,604(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 604);
	// addi r31,r31,256
	r31.s64 = r31.s64 + 256;
	// li r5,3
	ctx.r5.s64 = 3;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8264b044
	if (cr6.eq) goto loc_8264B044;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28300
	ctx.r4.s64 = r11.s64 + 28300;
	// b 0x8264b064
	goto loc_8264B064;
loc_8264B044:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28932
	ctx.r4.s64 = r11.s64 + 28932;
	// b 0x8264b064
	goto loc_8264B064;
loc_8264B050:
	// addi r31,r31,256
	r31.s64 = r31.s64 + 256;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28956
	ctx.r4.s64 = r11.s64 + 28956;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264B064:
	// bl 0x8262ffe0
	ctx.lr = 0x8264B068;
	sub_8262FFE0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B07C;
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

__attribute__((alias("__imp__sub_8264B094"))) PPC_WEAK_FUNC(sub_8264B094);
PPC_FUNC_IMPL(__imp__sub_8264B094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264B098"))) PPC_WEAK_FUNC(sub_8264B098);
PPC_FUNC_IMPL(__imp__sub_8264B098) {
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
	// bl 0x82653b30
	ctx.lr = 0x8264B0B0;
	sub_82653B30(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B0C8;
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

__attribute__((alias("__imp__sub_8264B0DC"))) PPC_WEAK_FUNC(sub_8264B0DC);
PPC_FUNC_IMPL(__imp__sub_8264B0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264B0E0"))) PPC_WEAK_FUNC(sub_8264B0E0);
PPC_FUNC_IMPL(__imp__sub_8264B0E0) {
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
	ctx.lr = 0x8264B0E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1192(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1192);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,1208(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1208);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8264b10c
	if (cr6.eq) goto loc_8264B10C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x8264b110
	if (!cr6.eq) goto loc_8264B110;
loc_8264B10C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8264B110:
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8264b128
	if (cr6.eq) goto loc_8264B128;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r31,0
	r31.s64 = 0;
	// bne cr6,0x8264b12c
	if (!cr6.eq) goto loc_8264B12C;
loc_8264B128:
	// li r31,1
	r31.s64 = 1;
loc_8264B12C:
	// addi r3,r30,2816
	ctx.r3.s64 = r30.s64 + 2816;
	// bl 0x8262fff0
	ctx.lr = 0x8264B134;
	sub_8262FFF0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// addi r3,r30,3056
	ctx.r3.s64 = r30.s64 + 3056;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8262fff0
	ctx.lr = 0x8264B14C;
	sub_8262FFF0(ctx, base);
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// addi r3,r30,3296
	ctx.r3.s64 = r30.s64 + 3296;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8262fff0
	ctx.lr = 0x8264B164;
	sub_8262FFF0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264B16C"))) PPC_WEAK_FUNC(sub_8264B16C);
PPC_FUNC_IMPL(__imp__sub_8264B16C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264B170"))) PPC_WEAK_FUNC(sub_8264B170);
PPC_FUNC_IMPL(__imp__sub_8264B170) {
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
	// bl 0x82653b30
	ctx.lr = 0x8264B188;
	sub_82653B30(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264B18C;
	sub_82387B90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,808(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 808);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B1A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,648(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264B1BC;
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

__attribute__((alias("__imp__sub_8264B1D0"))) PPC_WEAK_FUNC(sub_8264B1D0);
PPC_FUNC_IMPL(__imp__sub_8264B1D0) {
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
	// addi r3,r31,2688
	ctx.r3.s64 = r31.s64 + 2688;
	// lwz r11,2688(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2688);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8264b214
	if (!cr6.eq) goto loc_8264B214;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4480(r31)
	PPC_STORE_U8(r31.u32 + 4480, ctx.r10.u8);
	// lwz r9,736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// b 0x8264b228
	goto loc_8264B228;
loc_8264B214:
	// bl 0x82387b38
	ctx.lr = 0x8264B218;
	sub_82387B38(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// stb r11,4480(r31)
	PPC_STORE_U8(r31.u32 + 4480, r11.u8);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
loc_8264B228:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B234;
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

__attribute__((alias("__imp__sub_8264B248"))) PPC_WEAK_FUNC(sub_8264B248);
PPC_FUNC_IMPL(__imp__sub_8264B248) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,2432
	ctx.r3.s64 = r31.s64 + 2432;
	// lwz r11,2432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2432);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// addi r10,r31,1200
	ctx.r10.s64 = r31.s64 + 1200;
	// li r11,6
	r11.s64 = 6;
	// stw r3,-6744(r9)
	PPC_STORE_U32(ctx.r9.u32 + -6744, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
loc_8264B284:
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,240
	ctx.r10.s64 = ctx.r10.s64 + 240;
	// bne 0x8264b284
	if (!cr0.eq) goto loc_8264B284;
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x8264B29C;
	sub_82216138(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264B2B0"))) PPC_WEAK_FUNC(sub_8264B2B0);
PPC_FUNC_IMPL(__imp__sub_8264B2B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// addi r11,r4,5
	r11.s64 = ctx.r4.s64 + 5;
	// cmplwi cr6,r4,5
	cr6.compare<uint32_t>(ctx.r4.u32, 5, xer);
	// mulli r11,r11,240
	r11.s64 = r11.s64 * 240;
	// lbzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r3.u32);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stbx r8,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// bgt cr6,0x8264b38c
	if (cr6.gt) {
		// ERROR 8264B38C
		return;
	}
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-19736
	r12.s64 = r12.s64 + -19736;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		// ERROR: 0x8264B300
		return;
	case 1:
		// ERROR: 0x8264B318
		return;
	case 2:
		// ERROR: 0x8264B330
		return;
	case 3:
		// ERROR: 0x8264B348
		return;
	case 4:
		// ERROR: 0x8264B360
		return;
	case 5:
		// ERROR: 0x8264B378
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8264B2E8"))) PPC_WEAK_FUNC(sub_8264B2E8);
PPC_FUNC_IMPL(__imp__sub_8264B2E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r19{};
	// lwz r19,-19712(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19712);
	// lwz r19,-19688(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19688);
	// lwz r19,-19664(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19664);
	// lwz r19,-19640(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19640);
	// lwz r19,-19616(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19616);
	// lwz r19,-19592(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19592);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6736(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6736);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6736(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6736, r11.u8);
	// b 0x8264b38c
	// ERROR 8264B38C
	return;
}

__attribute__((alias("__imp__sub_8264B318"))) PPC_WEAK_FUNC(sub_8264B318);
PPC_FUNC_IMPL(__imp__sub_8264B318) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// b 0x8264b38c
	// ERROR 8264B38C
	return;
}

__attribute__((alias("__imp__sub_8264B330"))) PPC_WEAK_FUNC(sub_8264B330);
PPC_FUNC_IMPL(__imp__sub_8264B330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6735(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6735);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6735(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6735, r11.u8);
	// b 0x8264b38c
	// ERROR 8264B38C
	return;
}

__attribute__((alias("__imp__sub_8264B348"))) PPC_WEAK_FUNC(sub_8264B348);
PPC_FUNC_IMPL(__imp__sub_8264B348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6734(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6734);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6734(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6734, r11.u8);
	// b 0x8264b38c
	// ERROR 8264B38C
	return;
}

__attribute__((alias("__imp__sub_8264B360"))) PPC_WEAK_FUNC(sub_8264B360);
PPC_FUNC_IMPL(__imp__sub_8264B360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6732(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6732);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6732(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6732, r11.u8);
	// b 0x8264b38c
	// ERROR 8264B38C
	return;
}

__attribute__((alias("__imp__sub_8264B378"))) PPC_WEAK_FUNC(sub_8264B378);
PPC_FUNC_IMPL(__imp__sub_8264B378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6730(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6730);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6730(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6730, r11.u8);
	// lwz r11,672(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// addi r3,r3,672
	ctx.r3.s64 = ctx.r3.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8264B3A0"))) PPC_WEAK_FUNC(sub_8264B3A0);
PPC_FUNC_IMPL(__imp__sub_8264B3A0) {
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
	ctx.lr = 0x8264B3A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r28,r11,-18804
	r28.s64 = r11.s64 + -18804;
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B3D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30740
	ctx.r4.s64 = ctx.r10.s64 + 30740;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r30,1
	r30.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,1201(r31)
	PPC_STORE_U8(r31.u32 + 1201, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B41C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6736(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6736);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b430
	if (cr6.eq) goto loc_8264B430;
	// stb r30,1200(r31)
	PPC_STORE_U8(r31.u32 + 1200, r30.u8);
loc_8264B430:
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B44C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,20
	cr6.compare<int32_t>(ctx.r3.s32, 20, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,1232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1232);
	// addi r29,r31,1232
	r29.s64 = r31.s64 + 1232;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30716
	ctx.r4.s64 = ctx.r10.s64 + 30716;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1232);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,1441(r31)
	PPC_STORE_U8(r31.u32 + 1441, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B48C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6745(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6745);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b4a0
	if (cr6.eq) goto loc_8264B4A0;
	// stb r30,1440(r31)
	PPC_STORE_U8(r31.u32 + 1440, r30.u8);
loc_8264B4A0:
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B4BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,30
	cr6.compare<int32_t>(ctx.r3.s32, 30, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,1472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1472);
	// addi r29,r31,1472
	r29.s64 = r31.s64 + 1472;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30692
	ctx.r4.s64 = ctx.r10.s64 + 30692;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B4E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1472(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1472);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,1681(r31)
	PPC_STORE_U8(r31.u32 + 1681, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6735(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6735);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b510
	if (cr6.eq) goto loc_8264B510;
	// stb r30,1680(r31)
	PPC_STORE_U8(r31.u32 + 1680, r30.u8);
loc_8264B510:
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B52C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,40
	cr6.compare<int32_t>(ctx.r3.s32, 40, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,1712(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1712);
	// addi r29,r31,1712
	r29.s64 = r31.s64 + 1712;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30672
	ctx.r4.s64 = ctx.r10.s64 + 30672;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B554;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1712(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1712);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,1921(r31)
	PPC_STORE_U8(r31.u32 + 1921, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B56C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6734(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6734);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b580
	if (cr6.eq) goto loc_8264B580;
	// stb r30,1920(r31)
	PPC_STORE_U8(r31.u32 + 1920, r30.u8);
loc_8264B580:
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,50
	cr6.compare<int32_t>(ctx.r3.s32, 50, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,1952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1952);
	// addi r29,r31,1952
	r29.s64 = r31.s64 + 1952;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30656
	ctx.r4.s64 = ctx.r10.s64 + 30656;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B5C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1952(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1952);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,2161(r31)
	PPC_STORE_U8(r31.u32 + 2161, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B5DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6732(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6732);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b5f0
	if (cr6.eq) goto loc_8264B5F0;
	// stb r30,2160(r31)
	PPC_STORE_U8(r31.u32 + 2160, r30.u8);
loc_8264B5F0:
	// lwz r3,-12440(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B60C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,60
	cr6.compare<int32_t>(ctx.r3.s32, 60, xer);
	// blt cr6,0x8264b660
	if (cr6.lt) goto loc_8264B660;
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r29,r31,2192
	r29.s64 = r31.s64 + 2192;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,30636
	ctx.r4.s64 = ctx.r10.s64 + 30636;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264B634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,2192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,2401(r31)
	PPC_STORE_U8(r31.u32 + 2401, r30.u8);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B64C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lbz r5,-6730(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + -6730);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8264b660
	if (cr6.eq) goto loc_8264B660;
	// stb r30,2400(r31)
	PPC_STORE_U8(r31.u32 + 2400, r30.u8);
loc_8264B660:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8264B668"))) PPC_WEAK_FUNC(sub_8264B668);
PPC_FUNC_IMPL(__imp__sub_8264B668) {
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
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// beq cr6,0x8264b69c
	if (cr6.eq) goto loc_8264B69C;
	// bl 0x826537d0
	ctx.lr = 0x8264B688;
	sub_826537D0(ctx, base);
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
loc_8264B69C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264B6A8;
	sub_821E6800(ctx, base);
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-21680
	ctx.r4.s64 = ctx.r10.s64 + -21680;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2fb0
	ctx.lr = 0x8264B6C4;
	sub_821C2FB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,20
	ctx.r5.s64 = 20;
	// stb r9,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r9.u8);
	// bl 0x823da950
	ctx.lr = 0x8264B6DC;
	sub_823DA950(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r10,r8,3916
	ctx.r10.s64 = ctx.r8.s64 + 3916;
	// addi r8,r6,30808
	ctx.r8.s64 = ctx.r6.s64 + 30808;
	// addi r6,r5,30784
	ctx.r6.s64 = ctx.r5.s64 + 30784;
	// addi r9,r7,3998
	ctx.r9.s64 = ctx.r7.s64 + 3998;
	// addi r5,r4,30764
	ctx.r5.s64 = ctx.r4.s64 + 30764;
	// li r7,2
	ctx.r7.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x82634db0
	ctx.lr = 0x8264B714;
	sub_82634DB0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_8264B72C"))) PPC_WEAK_FUNC(sub_8264B72C);
PPC_FUNC_IMPL(__imp__sub_8264B72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264B730"))) PPC_WEAK_FUNC(sub_8264B730);
PPC_FUNC_IMPL(__imp__sub_8264B730) {
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
	ctx.lr = 0x8264B738;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264B744;
	sub_82653B30(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264B748;
	sub_82387B90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264B754;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264B764:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264b764
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264B764;
	// addi r30,r31,3300
	r30.s64 = r31.s64 + 3300;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264B78C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264b78c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264B78C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,808(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 808);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32155
	ctx.r9.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-21384
	ctx.r4.s64 = ctx.r9.s64 + -21384;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264B7CC;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264B7DC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264b7dc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264B7DC;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x8264B814;
	sub_822A5948(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264b850
	if (cr6.eq) goto loc_8264B850;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264b850
	if (cr6.eq) goto loc_8264B850;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264b848
	if (cr6.eq) goto loc_8264B848;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264b84c
	if (!cr6.eq) goto loc_8264B84C;
loc_8264B848:
	// li r11,0
	r11.s64 = 0;
loc_8264B84C:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_8264B850:
	// lwz r11,3824(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3824);
	// addi r3,r31,3824
	ctx.r3.s64 = r31.s64 + 3824;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264B870"))) PPC_WEAK_FUNC(sub_8264B870);
PPC_FUNC_IMPL(__imp__sub_8264B870) {
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
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8264b898
	if (cr6.eq) goto loc_8264B898;
	// bl 0x8264b668
	ctx.lr = 0x8264B894;
	sub_8264B668(ctx, base);
	// b 0x8264b9a4
	goto loc_8264B9A4;
loc_8264B898:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264B8A4;
	sub_821E6800(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264B8A8;
	sub_82387B90(ctx, base);
	// lwz r11,3056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x8238b0f0
	ctx.lr = 0x8264B8C0;
	sub_8238B0F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264B8CC;
	sub_8238B128(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,3536(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3536);
	// bl 0x8238b020
	ctx.lr = 0x8264B8DC;
	sub_8238B020(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264B8E8;
	sub_8238B128(ctx, base);
	// lwz r8,3568(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3568);
	// addi r3,r31,3568
	ctx.r3.s64 = r31.s64 + 3568;
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264B8FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x8238b090
	ctx.lr = 0x8264B928;
	sub_8238B090(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264B934;
	sub_8238B128(ctx, base);
	// lwz r11,4032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4032);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8238b0c8
	ctx.lr = 0x8264B950;
	sub_8238B0C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264B95C;
	sub_8238B128(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264B96C;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8264B970;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264b98c
	if (cr6.eq) goto loc_8264B98C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264B984;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8264B988;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x8264B98C;
	sub_822A2370(ctx, base);
loc_8264B98C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264B9A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8264B9A4:
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

__attribute__((alias("__imp__sub_8264B9BC"))) PPC_WEAK_FUNC(sub_8264B9BC);
PPC_FUNC_IMPL(__imp__sub_8264B9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264B9C0"))) PPC_WEAK_FUNC(sub_8264B9C0);
PPC_FUNC_IMPL(__imp__sub_8264B9C0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,2848
	ctx.r3.s64 = r31.s64 + 2848;
	// lhz r11,1238(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1238);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8262fff0
	ctx.lr = 0x8264B9F4;
	sub_8262FFF0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,2832(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2832);
	// bl 0x821fec88
	ctx.lr = 0x8264BA00;
	sub_821FEC88(ctx, base);
	// lwz r11,3088(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3088);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,3088
	ctx.r3.s64 = r31.s64 + 3088;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// bne cr6,0x8264ba20
	if (!cr6.eq) goto loc_8264BA20;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8264BA20:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264BA28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,3328
	ctx.r3.s64 = r31.s64 + 3328;
	// lwz r4,1204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 1204);
	// bl 0x8262fff0
	ctx.lr = 0x8264BA34;
	sub_8262FFF0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,1224(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1224);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,3784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3784);
	// addi r11,r31,3568
	r11.s64 = r31.s64 + 3568;
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// stw r8,3784(r31)
	PPC_STORE_U32(r31.u32 + 3784, ctx.r8.u32);
	// beq cr6,0x8264ba70
	if (cr6.eq) goto loc_8264BA70;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8264BA70;
	sub_821C3048(ctx, base);
loc_8264BA70:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b0b8
	ctx.lr = 0x8264BA7C;
	sub_8238B0B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,3824
	ctx.r3.s64 = r31.s64 + 3824;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8262fff0
	ctx.lr = 0x8264BA94;
	sub_8262FFF0(ctx, base);
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

__attribute__((alias("__imp__sub_8264BAAC"))) PPC_WEAK_FUNC(sub_8264BAAC);
PPC_FUNC_IMPL(__imp__sub_8264BAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264BAB0"))) PPC_WEAK_FUNC(sub_8264BAB0);
PPC_FUNC_IMPL(__imp__sub_8264BAB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x8264BAC4;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8264badc
	if (cr6.eq) goto loc_8264BADC;
	// bl 0x8264b668
	ctx.lr = 0x8264BAD8;
	sub_8264B668(ctx, base);
	// b 0x8264bc34
	goto loc_8264BC34;
loc_8264BADC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264BAE8;
	sub_821E6800(ctx, base);
	// lwz r10,2784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2784);
	// addi r3,r31,2784
	ctx.r3.s64 = r31.s64 + 2784;
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264BAFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,3040(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3040);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r3,r31,3040
	ctx.r3.s64 = r31.s64 + 3040;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f31,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f31.f64 = double(temp.f32);
	// lwz r5,336(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 336);
	// fmuls f30,f12,f31
	f30.f64 = double(float(ctx.f12.f64 * f31.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264BB30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// addi r3,r31,3296
	ctx.r3.s64 = r31.s64 + 3296;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// fmuls f29,f9,f31
	f29.f64 = double(float(ctx.f9.f64 * f31.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264BB5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r8,3552(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3552);
	// addi r3,r31,3552
	ctx.r3.s64 = r31.s64 + 3552;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// fmuls f28,f6,f31
	f28.f64 = double(float(ctx.f6.f64 * f31.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264BB88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r5,3808(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3808);
	// addi r3,r31,3808
	ctx.r3.s64 = r31.s64 + 3808;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f5,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lwz r4,336(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 336);
	// fmuls f27,f3,f31
	f27.f64 = double(float(ctx.f3.f64 * f31.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8264BBB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f2,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x82387b90
	ctx.lr = 0x8264BBD0;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264BBDC;
	sub_8238C090(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264BBE0;
	sub_82387B90(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264BBEC;
	sub_8238C090(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264BBF0;
	sub_82387B90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264BBFC;
	sub_8238C090(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264BC00;
	sub_82387B90(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264BC0C;
	sub_8238C090(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264BC10;
	sub_82387B90(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264BC1C;
	sub_8238C090(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264BC30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8264BC34:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x8264BC40;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264BC50"))) PPC_WEAK_FUNC(sub_8264BC50);
PPC_FUNC_IMPL(__imp__sub_8264BC50) {
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
	// bl 0x82387b90
	ctx.lr = 0x8264BC60;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1240);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,1244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1244);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f12,1248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1248);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f11,1252(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1252);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f10,1256(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1256);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x821e6980
	ctx.lr = 0x8264BC94;
	sub_821E6980(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lfs f9,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,-12216(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12216);
	// stfs f9,32(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264BCB4"))) PPC_WEAK_FUNC(sub_8264BCB4);
PPC_FUNC_IMPL(__imp__sub_8264BCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264BCB8"))) PPC_WEAK_FUNC(sub_8264BCB8);
PPC_FUNC_IMPL(__imp__sub_8264BCB8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r30,672
	ctx.r3.s64 = r30.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8264BCD8;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264bce8
	if (cr6.lt) goto loc_8264BCE8;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264BCE8:
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x8264bd54
	if (cr6.gt) goto loc_8264BD54;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-17144
	r12.s64 = r12.s64 + -17144;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8264BD24;
	case 1:
		goto loc_8264BD54;
	case 2:
		goto loc_8264BD2C;
	case 3:
		goto loc_8264BD34;
	case 4:
		goto loc_8264BD3C;
	case 5:
		goto loc_8264BD44;
	case 6:
		goto loc_8264BD4C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17116(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17116);
	// lwz r19,-17068(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17068);
	// lwz r19,-17108(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17108);
	// lwz r19,-17100(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17100);
	// lwz r19,-17092(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17092);
	// lwz r19,-17084(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17084);
	// lwz r19,-17076(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17076);
loc_8264BD24:
	// li r31,3
	r31.s64 = 3;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD2C:
	// li r31,1
	r31.s64 = 1;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD34:
	// li r31,2
	r31.s64 = 2;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD3C:
	// li r31,4
	r31.s64 = 4;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD44:
	// li r31,6
	r31.s64 = 6;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD4C:
	// li r31,5
	r31.s64 = 5;
	// b 0x8264bd58
	goto loc_8264BD58;
loc_8264BD54:
	// li r31,0
	r31.s64 = 0;
loc_8264BD58:
	// bl 0x82387b90
	ctx.lr = 0x8264BD5C;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238c070
	ctx.lr = 0x8264BD64;
	sub_8238C070(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822189b0
	ctx.lr = 0x8264BD74;
	sub_822189B0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264BD88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8264BDA4"))) PPC_WEAK_FUNC(sub_8264BDA4);
PPC_FUNC_IMPL(__imp__sub_8264BDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264BDA8"))) PPC_WEAK_FUNC(sub_8264BDA8);
PPC_FUNC_IMPL(__imp__sub_8264BDA8) {
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
	// bl 0x82631c08
	ctx.lr = 0x8264BDC4;
	sub_82631C08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630070
	ctx.lr = 0x8264BDCC;
	sub_82630070(ctx, base);
	// lbz r11,208(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264bdf8
	if (cr6.eq) goto loc_8264BDF8;
	// li r11,20
	r11.s64 = 20;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20292
	ctx.r4.s64 = ctx.r10.s64 + 20292;
	// bl 0x82722678
	ctx.lr = 0x8264BDF8;
	sub_82722678(ctx, base);
loc_8264BDF8:
	// lhz r11,192(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264be48
	if (cr6.eq) goto loc_8264BE48;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264be48
	if (cr6.eq) goto loc_8264BE48;
	// lbz r11,208(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264be48
	if (cr6.eq) goto loc_8264BE48;
	// li r11,7
	r11.s64 = 7;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8264BE48;
	sub_82722678(ctx, base);
loc_8264BE48:
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

__attribute__((alias("__imp__sub_8264BE60"))) PPC_WEAK_FUNC(sub_8264BE60);
PPC_FUNC_IMPL(__imp__sub_8264BE60) {
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
	ctx.lr = 0x8264BE68;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264BE78;
	sub_822A4AE0(ctx, base);
	// lhz r11,852(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 852);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264bf00
	if (cr6.eq) goto loc_8264BF00;
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// addi r31,r27,2784
	r31.s64 = r27.s64 + 2784;
	// lis r28,-32115
	r28.s64 = -2104688640;
loc_8264BE94:
	// extsh r26,r30
	r26.s64 = r30.s16;
	// lwz r3,-12052(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12052);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82397ba8
	ctx.lr = 0x8264BEA4;
	sub_82397BA8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r9,605(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 605);
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// subf r7,r9,r29
	ctx.r7.s64 = r29.s64 - ctx.r9.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264BECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-12052(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8264BED8;
	sub_82397BA8(ctx, base);
	// lbz r5,605(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 605);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// subf r4,r5,r29
	ctx.r4.s64 = r29.s64 - ctx.r5.s64;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// stb r11,209(r31)
	PPC_STORE_U8(r31.u32 + 209, r11.u8);
	// addi r31,r31,240
	r31.s64 = r31.s64 + 240;
	// lhz r10,852(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 852);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8264be94
	if (cr6.lt) goto loc_8264BE94;
loc_8264BF00:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264BF08;
	sub_822A4AE0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264BF10;
	sub_82387B90(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264bf24
	if (!cr6.eq) goto loc_8264BF24;
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// b 0x8264bf28
	goto loc_8264BF28;
loc_8264BF24:
	// lhz r11,2(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
loc_8264BF28:
	// lwz r10,672(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 672);
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264BF40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8264BF48"))) PPC_WEAK_FUNC(sub_8264BF48);
PPC_FUNC_IMPL(__imp__sub_8264BF48) {
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
	ctx.lr = 0x8264BF50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8264bf6c
	if (cr6.eq) goto loc_8264BF6C;
	// bl 0x8264b668
	ctx.lr = 0x8264BF64;
	sub_8264B668(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8264BF6C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264BF78;
	sub_821E6800(ctx, base);
	// lwz r11,3264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// lwz r10,3504(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3504);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r30,r7,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r29,r6,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r28,3024(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 3024);
	// bl 0x82387b90
	ctx.lr = 0x8264BFA0;
	sub_82387B90(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x8238b048
	ctx.lr = 0x8264BFB0;
	sub_8238B048(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264BFBC;
	sub_8238B128(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8264bfe0
	if (cr6.eq) goto loc_8264BFE0;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264bfe0
	if (cr6.eq) goto loc_8264BFE0;
	// bl 0x82387b90
	ctx.lr = 0x8264BFD8;
	sub_82387B90(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8264c028
	goto loc_8264C028;
loc_8264BFE0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c008
	if (cr6.eq) goto loc_8264C008;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8264c000
	if (!cr6.eq) goto loc_8264C000;
	// bl 0x82387b90
	ctx.lr = 0x8264BFF8;
	sub_82387B90(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x8264c028
	goto loc_8264C028;
loc_8264C000:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264c020
	if (!cr6.eq) goto loc_8264C020;
loc_8264C008:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c020
	if (cr6.eq) goto loc_8264C020;
	// bl 0x82387b90
	ctx.lr = 0x8264C018;
	sub_82387B90(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x8264c028
	goto loc_8264C028;
loc_8264C020:
	// bl 0x82387b90
	ctx.lr = 0x8264C024;
	sub_82387B90(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
loc_8264C028:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8238aff8
	ctx.lr = 0x8264C034;
	sub_8238AFF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264C040;
	sub_8238B128(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C054;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8264C060"))) PPC_WEAK_FUNC(sub_8264C060);
PPC_FUNC_IMPL(__imp__sub_8264C060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,1872(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1872);
	// addi r3,r3,1872
	ctx.r3.s64 = ctx.r3.s64 + 1872;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lbz r8,10096(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8264C088"))) PPC_WEAK_FUNC(sub_8264C088);
PPC_FUNC_IMPL(__imp__sub_8264C088) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8264C0B8;
	sub_82641CB0(ctx, base);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// addi r3,r3,3088
	ctx.r3.s64 = ctx.r3.s64 + 3088;
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// lbz r10,10096(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,5420(r31)
	PPC_STORE_U8(r31.u32 + 5420, ctx.r8.u8);
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// lbz r7,10096(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// bl 0x8262fff0
	ctx.lr = 0x8264C0E8;
	sub_8262FFF0(ctx, base);
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// lwz r5,1872(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1872);
	// addi r3,r31,1872
	ctx.r3.s64 = r31.s64 + 1872;
	// lbz r4,10096(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// lwz r10,76(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C10C;
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

__attribute__((alias("__imp__sub_8264C124"))) PPC_WEAK_FUNC(sub_8264C124);
PPC_FUNC_IMPL(__imp__sub_8264C124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C128"))) PPC_WEAK_FUNC(sub_8264C128);
PPC_FUNC_IMPL(__imp__sub_8264C128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8264C130;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264C13C;
	sub_82653B30(ctx, base);
	// addi r31,r29,992
	r31.s64 = r29.s64 + 992;
	// li r30,6
	r30.s64 = 6;
loc_8264C144:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,240
	r31.s64 = r31.s64 + 240;
	// bne 0x8264c144
	if (!cr0.eq) goto loc_8264C144;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r11,4480(r29)
	PPC_STORE_U8(r29.u32 + 4480, r11.u8);
	// bl 0x8264b3a0
	ctx.lr = 0x8264C174;
	sub_8264B3A0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264C17C"))) PPC_WEAK_FUNC(sub_8264C17C);
PPC_FUNC_IMPL(__imp__sub_8264C17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C180"))) PPC_WEAK_FUNC(sub_8264C180);
PPC_FUNC_IMPL(__imp__sub_8264C180) {
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
	// lbz r11,4480(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4480);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264c20c
	if (!cr6.eq) goto loc_8264C20C;
	// bl 0x82387a98
	ctx.lr = 0x8264C1A4;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c20c
	if (cr6.eq) goto loc_8264C20C;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-20016
	ctx.r4.s64 = r11.s64 + -20016;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x8264C1C4;
	sub_821C2F90(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r9,30832
	ctx.r5.s64 = ctx.r9.s64 + 30832;
	// ld r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r9,r8,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r6,r10,30812
	ctx.r6.s64 = ctx.r10.s64 + 30812;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,2688
	ctx.r3.s64 = r31.s64 + 2688;
	// bl 0x826350b8
	ctx.lr = 0x8264C1F4;
	sub_826350B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_8264C20C:
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
}

__attribute__((alias("__imp__sub_8264C224"))) PPC_WEAK_FUNC(sub_8264C224);
PPC_FUNC_IMPL(__imp__sub_8264C224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C228"))) PPC_WEAK_FUNC(sub_8264C228);
PPC_FUNC_IMPL(__imp__sub_8264C228) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8264c250
	if (cr6.eq) goto loc_8264C250;
	// bl 0x826537d0
	ctx.lr = 0x8264C24C;
	sub_826537D0(ctx, base);
	// b 0x8264c2c8
	goto loc_8264C2C8;
loc_8264C250:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8264C25C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264c26c
	if (cr6.lt) goto loc_8264C26C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264C26C:
	// mulli r11,r11,240
	r11.s64 = r11.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// lwz r11,992(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 992);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264c2b8
	if (cr6.eq) goto loc_8264C2B8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264C2A0;
	sub_821E6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8264C2A8;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264b2b0
	ctx.lr = 0x8264C2B4;
	sub_8264B2B0(ctx, base);
	// b 0x8264c2c4
	goto loc_8264C2C4;
loc_8264C2B8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8264C2C4;
	sub_821E6800(ctx, base);
loc_8264C2C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8264C2C8:
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

__attribute__((alias("__imp__sub_8264C2E0"))) PPC_WEAK_FUNC(sub_8264C2E0);
PPC_FUNC_IMPL(__imp__sub_8264C2E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x8264C2F4;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,2784
	ctx.r3.s64 = r31.s64 + 2784;
	// lwz r11,2784(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2784);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,3040(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 3040);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r3,r31,3040
	ctx.r3.s64 = r31.s64 + 3040;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f31,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	f31.f64 = double(temp.f32);
	// lwz r6,336(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 336);
	// fmuls f30,f12,f31
	f30.f64 = double(float(ctx.f12.f64 * f31.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264C344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// lwz r4,3296(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// addi r3,r31,3296
	ctx.r3.s64 = r31.s64 + 3296;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lwz r11,336(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 336);
	// fmuls f29,f9,f31
	f29.f64 = double(float(ctx.f9.f64 * f31.f64));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264C370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,3552(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3552);
	// addi r3,r31,3552
	ctx.r3.s64 = r31.s64 + 3552;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f8,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// lwz r8,336(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 336);
	// fmuls f28,f6,f31
	f28.f64 = double(float(ctx.f6.f64 * f31.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264C39C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// lwz r6,3808(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3808);
	// addi r3,r31,3808
	ctx.r3.s64 = r31.s64 + 3808;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f5,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lwz r5,336(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 336);
	// fmuls f27,f3,f31
	f27.f64 = double(float(ctx.f3.f64 * f31.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264C3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f2,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x82387b90
	ctx.lr = 0x8264C3E4;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8238c090
	ctx.lr = 0x8264C3F4;
	sub_8238C090(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264C404;
	sub_8238C090(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264C414;
	sub_8238C090(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264C424;
	sub_8238C090(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8238c090
	ctx.lr = 0x8264C434;
	sub_8238C090(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264C438;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f13,1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1240);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f12,1244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1244);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f11,1248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1248);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f10,1252(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1252);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f9,1256(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1256);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x821e6980
	ctx.lr = 0x8264C46C;
	sub_821E6980(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lfs f8,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// lwz r11,-12216(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12216);
	// stfs f8,32(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x8264C488;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264C498"))) PPC_WEAK_FUNC(sub_8264C498);
PPC_FUNC_IMPL(__imp__sub_8264C498) {
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
	// bl 0x82387b90
	ctx.lr = 0x8264C4A8;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238c070
	ctx.lr = 0x8264C4B0;
	sub_8238C070(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822189b0
	ctx.lr = 0x8264C4C0;
	sub_822189B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264C4D0"))) PPC_WEAK_FUNC(sub_8264C4D0);
PPC_FUNC_IMPL(__imp__sub_8264C4D0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264C4F0;
	sub_822A4AE0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264C4F8;
	sub_82387B90(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264c50c
	if (!cr6.eq) goto loc_8264C50C;
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// b 0x8264c510
	goto loc_8264C510;
loc_8264C50C:
	// lhz r11,2(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
loc_8264C510:
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// addi r10,r31,2992
	ctx.r10.s64 = r31.s64 + 2992;
	// li r11,11
	r11.s64 = 11;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8264C520:
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,240
	ctx.r10.s64 = ctx.r10.s64 + 240;
	// bne 0x8264c520
	if (!cr0.eq) goto loc_8264C520;
	// mulli r11,r8,240
	r11.s64 = ctx.r8.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2992(r11)
	PPC_STORE_U8(r11.u32 + 2992, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8264C558"))) PPC_WEAK_FUNC(sub_8264C558);
PPC_FUNC_IMPL(__imp__sub_8264C558) {
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
	ctx.lr = 0x8264C560;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264C56C;
	sub_82653B30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264C574;
	sub_822A4AE0(ctx, base);
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c5fc
	if (cr6.eq) goto loc_8264C5FC;
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// addi r31,r28,2784
	r31.s64 = r28.s64 + 2784;
	// lis r27,-32115
	r27.s64 = -2104688640;
loc_8264C590:
	// extsh r26,r30
	r26.s64 = r30.s16;
	// lwz r3,-12052(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12052);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82397ba8
	ctx.lr = 0x8264C5A0;
	sub_82397BA8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r9,605(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 605);
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// subf r7,r9,r29
	ctx.r7.s64 = r29.s64 - ctx.r9.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264C5C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-12052(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8264C5D4;
	sub_82397BA8(ctx, base);
	// lbz r5,605(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 605);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// subf r4,r5,r29
	ctx.r4.s64 = r29.s64 - ctx.r5.s64;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// stb r11,209(r31)
	PPC_STORE_U8(r31.u32 + 209, r11.u8);
	// addi r31,r31,240
	r31.s64 = r31.s64 + 240;
	// lhz r10,852(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8264c590
	if (cr6.lt) goto loc_8264C590;
loc_8264C5FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264C604;
	sub_822A4AE0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264C60C;
	sub_82387B90(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264c620
	if (!cr6.eq) goto loc_8264C620;
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// b 0x8264c624
	goto loc_8264C624;
loc_8264C620:
	// lhz r11,2(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
loc_8264C624:
	// lwz r10,672(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// addi r3,r28,672
	ctx.r3.s64 = r28.s64 + 672;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264C63C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8264c4d0
	ctx.lr = 0x8264C644;
	sub_8264C4D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8264C64C"))) PPC_WEAK_FUNC(sub_8264C64C);
PPC_FUNC_IMPL(__imp__sub_8264C64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C650"))) PPC_WEAK_FUNC(sub_8264C650);
PPC_FUNC_IMPL(__imp__sub_8264C650) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8264C66C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264c67c
	if (cr6.lt) goto loc_8264C67C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264C67C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8264c6a8
	if (cr6.lt) goto loc_8264C6A8;
	// beq cr6,0x8264c6a0
	if (cr6.eq) goto loc_8264C6A0;
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
loc_8264C6A0:
	// li r4,32
	ctx.r4.s64 = 32;
	// b 0x8264c6ac
	goto loc_8264C6AC;
loc_8264C6A8:
	// li r4,33
	ctx.r4.s64 = 33;
loc_8264C6AC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8264C6C4;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264C6D8;
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
}

__attribute__((alias("__imp__sub_8264C6F0"))) PPC_WEAK_FUNC(sub_8264C6F0);
PPC_FUNC_IMPL(__imp__sub_8264C6F0) {
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
	ctx.lr = 0x8264C6F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r9,656(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r28,r8,1
	r28.s64 = ctx.r8.s64 + 65536;
	// addi r28,r28,16256
	r28.s64 = r28.s64 + 16256;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264C728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8264c914
	if (cr6.eq) goto loc_8264C914;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8264c944
	if (!cr6.eq) goto loc_8264C944;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264C744;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82679c48
	ctx.lr = 0x8264C74C;
	sub_82679C48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c760
	if (cr6.eq) goto loc_8264C760;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82679f50
	ctx.lr = 0x8264C760;
	sub_82679F50(ctx, base);
loc_8264C760:
	// li r4,33
	ctx.r4.s64 = 33;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264C76C;
	sub_82641CB0(ctx, base);
	// bl 0x8264af40
	ctx.lr = 0x8264C770;
	sub_8264AF40(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264C774;
	sub_82387B90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,5288(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 5288);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,1208(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 1208);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x8264c7d0
	if (cr6.eq) goto loc_8264C7D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264C798;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,80(r11)
	PPC_STORE_U32(r11.u32 + 80, r31.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264C7AC;
	sub_822A3998(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lfs f1,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x8264C7C0;
	sub_822B0F10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82387ba0
	ctx.lr = 0x8264C7C8;
	sub_82387BA0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82398568
	ctx.lr = 0x8264C7D0;
	sub_82398568(ctx, base);
loc_8264C7D0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238b0b8
	ctx.lr = 0x8264C7DC;
	sub_8238B0B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264c808
	if (cr6.eq) goto loc_8264C808;
	// bl 0x822a3998
	ctx.lr = 0x8264C7F4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r31,1
	r31.s64 = 1;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r31,2160(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2160, r31.u8);
	// b 0x8264c81c
	goto loc_8264C81C;
loc_8264C808:
	// bl 0x822a3998
	ctx.lr = 0x8264C80C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r31,1
	r31.s64 = 1;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r31,2159(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2159, r31.u8);
loc_8264C81C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264C828;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8264c890
	if (cr6.eq) goto loc_8264C890;
	// lwz r10,1192(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1192);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8264c84c
	if (cr6.eq) goto loc_8264C84C;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8264c850
	if (!cr6.eq) goto loc_8264C850;
loc_8264C84C:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8264C850:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8264c868
	if (cr6.eq) goto loc_8264C868;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// beq cr6,0x8264c868
	if (cr6.eq) goto loc_8264C868;
	// li r31,0
	r31.s64 = 0;
loc_8264C868:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264C874;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r29,88(r11)
	PPC_STORE_U8(r11.u32 + 88, r29.u8);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8264C888;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// stb r31,89(r10)
	PPC_STORE_U8(ctx.r10.u32 + 89, r31.u8);
loc_8264C890:
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264C89C;
	sub_82641CB0(ctx, base);
	// lwz r11,3296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3296);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r30,r8,24
	r30.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8264c8e8
	if (cr6.eq) goto loc_8264C8E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,2832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// bl 0x822008b8
	ctx.lr = 0x8264C8C8;
	sub_822008B8(ctx, base);
	// lwz r3,2832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-14960
	ctx.r4.s64 = r11.s64 + -14960;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264C8E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264C8E8:
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// lwz r3,2832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x822008b8
	ctx.lr = 0x8264C8F8;
	sub_822008B8(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264C90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8264C914:
	// bl 0x82387b90
	ctx.lr = 0x8264C918;
	sub_82387B90(ctx, base);
	// addi r4,r27,4080
	ctx.r4.s64 = r27.s64 + 4080;
	// bl 0x8238b3c0
	ctx.lr = 0x8264C920;
	sub_8238B3C0(ctx, base);
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264C92C;
	sub_82641CB0(ctx, base);
	// bl 0x8264bc50
	ctx.lr = 0x8264C930;
	sub_8264BC50(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264C944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264C944:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8264C94C"))) PPC_WEAK_FUNC(sub_8264C94C);
PPC_FUNC_IMPL(__imp__sub_8264C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C950"))) PPC_WEAK_FUNC(sub_8264C950);
PPC_FUNC_IMPL(__imp__sub_8264C950) {
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
	ctx.lr = 0x8264C958;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,1
	r30.s64 = ctx.r10.s64 + 65536;
	// addi r30,r30,16256
	r30.s64 = r30.s64 + 16256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264C980;
	sub_82641CB0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r30,3296(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3296);
	// bl 0x82641cb0
	ctx.lr = 0x8264C994;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264C99C;
	sub_82387B90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,4080
	ctx.r3.s64 = r31.s64 + 4080;
	// bl 0x8238b138
	ctx.lr = 0x8264C9A8;
	sub_8238B138(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264c9e4
	if (cr6.eq) goto loc_8264C9E4;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// lbz r10,5420(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5420);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x8264c9e4
	if (!cr6.eq) goto loc_8264C9E4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82679c48
	ctx.lr = 0x8264C9D4;
	sub_82679C48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8264c9e8
	if (cr6.eq) goto loc_8264C9E8;
loc_8264C9E4:
	// li r11,1
	r11.s64 = 1;
loc_8264C9E8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264C9F4"))) PPC_WEAK_FUNC(sub_8264C9F4);
PPC_FUNC_IMPL(__imp__sub_8264C9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264C9F8"))) PPC_WEAK_FUNC(sub_8264C9F8);
PPC_FUNC_IMPL(__imp__sub_8264C9F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,1
	r30.s64 = ctx.r10.s64 + 65536;
	// addi r30,r30,16256
	r30.s64 = r30.s64 + 16256;
	// bl 0x82631f88
	ctx.lr = 0x8264CA2C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264ca3c
	if (cr6.lt) goto loc_8264CA3C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264CA3C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8264cb0c
	if (cr6.gt) goto loc_8264CB0C;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-13732
	r12.s64 = r12.s64 + -13732;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8264CA6C;
	case 1:
		goto loc_8264CA94;
	case 2:
		goto loc_8264CABC;
	case 3:
		goto loc_8264CAE4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-13716(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -13716);
	// lwz r19,-13676(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -13676);
	// lwz r19,-13636(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -13636);
	// lwz r19,-13596(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -13596);
loc_8264CA6C:
	// li r4,33
	ctx.r4.s64 = 33;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CA78;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CA8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8264cb10
	goto loc_8264CB10;
loc_8264CA94:
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CAA0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CAB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8264cb10
	goto loc_8264CB10;
loc_8264CABC:
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CAC8;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8264cb10
	goto loc_8264CB10;
loc_8264CAE4:
	// li r4,37
	ctx.r4.s64 = 37;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CAF0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CB04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8264cb10
	goto loc_8264CB10;
loc_8264CB0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8264CB10:
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

__attribute__((alias("__imp__sub_8264CB28"))) PPC_WEAK_FUNC(sub_8264CB28);
PPC_FUNC_IMPL(__imp__sub_8264CB28) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264CB44;
	sub_82653B30(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,1
	r30.s64 = ctx.r10.s64 + 65536;
	// addi r30,r30,16256
	r30.s64 = r30.s64 + 16256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CB64;
	sub_82641CB0(ctx, base);
	// bl 0x82679bd8
	ctx.lr = 0x8264CB68;
	sub_82679BD8(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264CB6C;
	sub_82387B90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,4080
	ctx.r3.s64 = r31.s64 + 4080;
	// bl 0x8238b3c0
	ctx.lr = 0x8264CB78;
	sub_8238B3C0(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,648(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264CB90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264CB9C;
	sub_82641CB0(ctx, base);
	// lis r7,-32123
	ctx.r7.s64 = -2105212928;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r7,23088
	r11.s64 = ctx.r7.s64 + 23088;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CBB0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cbb0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CBB0;
	// addi r30,r3,5856
	r30.s64 = ctx.r3.s64 + 5856;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CBD8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cbd8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CBD8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264c088
	ctx.lr = 0x8264CBF4;
	sub_8264C088(ctx, base);
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-16288
	ctx.r4.s64 = r11.s64 + -16288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x8264CC08;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CC18:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cc18
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CC18;
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

__attribute__((alias("__imp__sub_8264CC44"))) PPC_WEAK_FUNC(sub_8264CC44);
PPC_FUNC_IMPL(__imp__sub_8264CC44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264CC48"))) PPC_WEAK_FUNC(sub_8264CC48);
PPC_FUNC_IMPL(__imp__sub_8264CC48) {
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
	// bl 0x82654318
	ctx.lr = 0x8264CC60;
	sub_82654318(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r10,r11,31516
	ctx.r10.s64 = r11.s64 + 31516;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264CC74;
	sub_82634B60(ctx, base);
	// lwz r9,496(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264CC8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8264CCA4"))) PPC_WEAK_FUNC(sub_8264CCA4);
PPC_FUNC_IMPL(__imp__sub_8264CCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264CCA8"))) PPC_WEAK_FUNC(sub_8264CCA8);
PPC_FUNC_IMPL(__imp__sub_8264CCA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8264CCB0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8264CCBC;
	sub_82653B30(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264CCC4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CCD4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264ccd4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CCD4;
	// addi r26,r31,3012
	r26.s64 = r31.s64 + 3012;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CCFC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264ccfc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CCFC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264CD18;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CD28:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cd28
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CD28;
	// addi r27,r31,3268
	r27.s64 = r31.s64 + 3268;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CD50:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cd50
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CD50;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264CD6C;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CD7C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cd7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CD7C;
	// addi r28,r31,3524
	r28.s64 = r31.s64 + 3524;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CDA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cda4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CDA4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264CDC0;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CDD0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cdd0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CDD0;
	// addi r29,r31,3780
	r29.s64 = r31.s64 + 3780;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CDF8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cdf8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CDF8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8264CE14;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CE24:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264ce24
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CE24;
	// addi r30,r31,4036
	r30.s64 = r31.s64 + 4036;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CE4C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264ce4c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CE4C;
	// bl 0x82387b90
	ctx.lr = 0x8264CE64;
	sub_82387B90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,808(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 808);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CE7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32155
	ctx.r9.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-15648
	ctx.r4.s64 = ctx.r9.s64 + -15648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264CE90;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CEA0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cea0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CEA0;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-15648
	ctx.r4.s64 = r11.s64 + -15648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264CEC8;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CED8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264ced8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CED8;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-15648
	ctx.r4.s64 = r11.s64 + -15648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264CF00;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CF10:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cf10
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CF10;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-15648
	ctx.r4.s64 = r11.s64 + -15648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264CF38;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CF48:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cf48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CF48;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-15648
	ctx.r4.s64 = r11.s64 + -15648;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264CF70;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264CF80:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264cf80
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264CF80;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264CFAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8264CFB4"))) PPC_WEAK_FUNC(sub_8264CFB4);
PPC_FUNC_IMPL(__imp__sub_8264CFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264CFB8"))) PPC_WEAK_FUNC(sub_8264CFB8);
PPC_FUNC_IMPL(__imp__sub_8264CFB8) {
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
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-32368
	ctx.r4.s64 = ctx.r9.s64 + -32368;
	// addi r6,r31,2784
	ctx.r6.s64 = r31.s64 + 2784;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-32392
	ctx.r5.s64 = ctx.r10.s64 + -32392;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x8264CFF4;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D008;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r4,32332
	ctx.r10.s64 = ctx.r4.s64 + 32332;
	// addi r9,r3,7428
	ctx.r9.s64 = ctx.r3.s64 + 7428;
	// addi r8,r11,26516
	ctx.r8.s64 = r11.s64 + 26516;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r9,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r8.u32);
	// stw r7,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, ctx.r6.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264D06C"))) PPC_WEAK_FUNC(sub_8264D06C);
PPC_FUNC_IMPL(__imp__sub_8264D06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D070"))) PPC_WEAK_FUNC(sub_8264D070);
PPC_FUNC_IMPL(__imp__sub_8264D070) {
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
	ctx.lr = 0x8264D078;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264D088;
	sub_82387B90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264D094;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// extsh r5,r30
	ctx.r5.s64 = r30.s16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8264d0b4
	if (!cr6.eq) goto loc_8264D0B4;
	// bl 0x8238af98
	ctx.lr = 0x8264D0B0;
	sub_8238AF98(ctx, base);
	// b 0x8264d0b8
	goto loc_8264D0B8;
loc_8264D0B4:
	// bl 0x8238afc8
	ctx.lr = 0x8264D0B8;
	sub_8238AFC8(ctx, base);
loc_8264D0B8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264D0C4;
	sub_8238B128(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8264c4d0
	ctx.lr = 0x8264D0CC;
	sub_8264C4D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264D0D4"))) PPC_WEAK_FUNC(sub_8264D0D4);
PPC_FUNC_IMPL(__imp__sub_8264D0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D0D8"))) PPC_WEAK_FUNC(sub_8264D0D8);
PPC_FUNC_IMPL(__imp__sub_8264D0D8) {
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
	ctx.lr = 0x8264D0E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8264d204
	if (cr6.eq) goto loc_8264D204;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// beq cr6,0x8264d2b4
	if (cr6.eq) goto loc_8264D2B4;
	// cmpwi cr6,r4,63
	cr6.compare<int32_t>(ctx.r4.s32, 63, xer);
	// beq cr6,0x8264d10c
	if (cr6.eq) goto loc_8264D10C;
	// bl 0x8264b668
	ctx.lr = 0x8264D104;
	sub_8264B668(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D10C:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8264D114;
	sub_82203240(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mulli r11,r29,240
	r11.s64 = r29.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,2784
	r30.s64 = r11.s64 + 2784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,2784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2784);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d2a8
	if (cr6.eq) goto loc_8264D2A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264D150;
	sub_821E6800(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264d2b4
	if (cr6.eq) goto loc_8264D2B4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8264D18C;
	sub_82641CB0(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// extsh r4,r29
	ctx.r4.s64 = r29.s16;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-12052(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8264D1A0;
	sub_82397BA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r7,0
	ctx.r4.s64 = ctx.r7.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r6,604(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 604);
	// stw r29,5156(r28)
	PPC_STORE_U32(r28.u32 + 5156, r29.u32);
	// cntlzw r11,r6
	r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r10,5152(r28)
	PPC_STORE_U8(r28.u32 + 5152, ctx.r10.u8);
	// bl 0x821c2f90
	ctx.lr = 0x8264D1D0;
	sub_821C2F90(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,728(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 728);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r7,r7,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264D1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D204:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8264D210;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264d220
	if (cr6.lt) goto loc_8264D220;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264D220:
	// mulli r11,r11,240
	r11.s64 = r11.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,2784
	ctx.r3.s64 = r11.s64 + 2784;
	// lwz r11,2784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2784);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D23C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d2a8
	if (cr6.eq) goto loc_8264D2A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8264D250;
	sub_82203240(ctx, base);
	// mulli r11,r3,240
	r11.s64 = ctx.r3.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,2784
	ctx.r10.s64 = r11.s64 + 2784;
	// lbz r11,2992(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2992);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264d2a8
	if (!cr6.eq) goto loc_8264D2A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264D274;
	sub_821E6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8264D27C;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264d070
	ctx.lr = 0x8264D288;
	sub_8264D070(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D29C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D2A8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8264D2B4;
	sub_821E6800(ctx, base);
loc_8264D2B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8264D2C0"))) PPC_WEAK_FUNC(sub_8264D2C0);
PPC_FUNC_IMPL(__imp__sub_8264D2C0) {
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
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-31520
	ctx.r4.s64 = ctx.r9.s64 + -31520;
	// addi r6,r31,2784
	ctx.r6.s64 = r31.s64 + 2784;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-31536
	ctx.r5.s64 = ctx.r10.s64 + -31536;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x8264D2FC;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D310;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r4,-32348
	ctx.r10.s64 = ctx.r4.s64 + -32348;
	// addi r9,r3,7428
	ctx.r9.s64 = ctx.r3.s64 + 7428;
	// addi r8,r11,26508
	ctx.r8.s64 = r11.s64 + 26508;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r8.u32);
	// stw r7,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, ctx.r6.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264D374"))) PPC_WEAK_FUNC(sub_8264D374);
PPC_FUNC_IMPL(__imp__sub_8264D374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D378"))) PPC_WEAK_FUNC(sub_8264D378);
PPC_FUNC_IMPL(__imp__sub_8264D378) {
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
	ctx.lr = 0x8264D380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-30628
	ctx.r4.s64 = ctx.r9.s64 + -30628;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-30640
	ctx.r5.s64 = ctx.r10.s64 + -30640;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264D3B0;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D3C4;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// addi r8,r4,-31452
	ctx.r8.s64 = ctx.r4.s64 + -31452;
	// addi r7,r3,7428
	ctx.r7.s64 = ctx.r3.s64 + 7428;
	// addi r6,r10,-28004
	ctx.r6.s64 = ctx.r10.s64 + -28004;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r7,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r7.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r6,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r6.u32);
	// addi r4,r9,26464
	ctx.r4.s64 = ctx.r9.s64 + 26464;
	// stw r11,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, r11.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r5,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r5.u32);
	// stw r4,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, ctx.r4.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r3,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r3.u32);
	// addi r29,r31,2816
	r29.s64 = r31.s64 + 2816;
	// stw r7,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, ctx.r7.u32);
	// addi r5,r31,2784
	ctx.r5.s64 = r31.s64 + 2784;
	// stw r11,2812(r31)
	PPC_STORE_U32(r31.u32 + 2812, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-31472
	ctx.r4.s64 = ctx.r10.s64 + -31472;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r31,2800
	r30.s64 = r31.s64 + 2800;
	// bl 0x826349f0
	ctx.lr = 0x8264D44C;
	sub_826349F0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r28,r31,3056
	r28.s64 = r31.s64 + 3056;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r9,-31484
	ctx.r4.s64 = ctx.r9.s64 + -31484;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264D468;
	sub_826349F0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r27,r31,3296
	r27.s64 = r31.s64 + 3296;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-31500
	ctx.r4.s64 = ctx.r8.s64 + -31500;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264D484;
	sub_826349F0(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r5,648(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8264D4F4"))) PPC_WEAK_FUNC(sub_8264D4F4);
PPC_FUNC_IMPL(__imp__sub_8264D4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D4F8"))) PPC_WEAK_FUNC(sub_8264D4F8);
PPC_FUNC_IMPL(__imp__sub_8264D4F8) {
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
	ctx.lr = 0x8264D500;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-29760
	ctx.r4.s64 = ctx.r9.s64 + -29760;
	// addi r8,r11,29180
	ctx.r8.s64 = r11.s64 + 29180;
	// addi r5,r10,-29776
	ctx.r5.s64 = ctx.r10.s64 + -29776;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264D530;
	sub_82654318(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r7,r8,-21868
	ctx.r7.s64 = ctx.r8.s64 + -21868;
	// addi r26,r29,992
	r26.s64 = r29.s64 + 992;
	// stw r7,992(r29)
	PPC_STORE_U32(r29.u32 + 992, ctx.r7.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r6,-29788
	ctx.r4.s64 = ctx.r6.s64 + -29788;
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x8264D554;
	sub_823DB670(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r11,r4,-29796
	r11.s64 = ctx.r4.s64 + -29796;
	// addi r3,r5,-30604
	ctx.r3.s64 = ctx.r5.s64 + -30604;
	// stw r11,992(r29)
	PPC_STORE_U32(r29.u32 + 992, r11.u32);
	// addi r31,r29,1040
	r31.s64 = r29.s64 + 1040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// li r30,5
	r30.s64 = 5;
	// mr r28,r31
	r28.u64 = r31.u64;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
loc_8264D580:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264D590;
	sub_82633D40(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,208
	r28.s64 = r28.s64 + 208;
	// bge 0x8264d580
	if (!cr0.lt) goto loc_8264D580;
	// addi r3,r29,2288
	ctx.r3.s64 = r29.s64 + 2288;
	// bl 0x82634b60
	ctx.lr = 0x8264D5A4;
	sub_82634B60(ctx, base);
	// addi r3,r29,4080
	ctx.r3.s64 = r29.s64 + 4080;
	// bl 0x8238c960
	ctx.lr = 0x8264D5AC;
	sub_8238C960(ctx, base);
	// lwz r10,496(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 496);
	// li r11,2
	r11.s64 = 2;
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// stw r11,952(r29)
	PPC_STORE_U32(r29.u32 + 952, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r28,r29,848
	r28.s64 = r29.s64 + 848;
	// addi r27,r11,26492
	r27.s64 = r11.s64 + 26492;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8264D5DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D5F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r6,r27,16
	ctx.r6.s64 = r27.s64 + 16;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// addi r31,r31,208
	r31.s64 = r31.s64 + 208;
	// blt cr6,0x8264d5dc
	if (cr6.lt) goto loc_8264D5DC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r10,-20020
	ctx.r5.s64 = ctx.r10.s64 + -20020;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8264D63C;
	sub_8268B960(ctx, base);
	// stw r3,5424(r29)
	PPC_STORE_U32(r29.u32 + 5424, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8264D64C"))) PPC_WEAK_FUNC(sub_8264D64C);
PPC_FUNC_IMPL(__imp__sub_8264D64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D650"))) PPC_WEAK_FUNC(sub_8264D650);
PPC_FUNC_IMPL(__imp__sub_8264D650) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D67C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d6a8
	if (cr6.eq) goto loc_8264D6A8;
	// lwz r11,5424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5424);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8264d6a8
	if (!cr6.eq) goto loc_8264D6A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264D6A8:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8264D6C4"))) PPC_WEAK_FUNC(sub_8264D6C4);
PPC_FUNC_IMPL(__imp__sub_8264D6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8264D6C8"))) PPC_WEAK_FUNC(sub_8264D6C8);
PPC_FUNC_IMPL(__imp__sub_8264D6C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-992
	ctx.r3.s64 = ctx.r3.s64 + -992;
	// b 0x8264e200
	sub_8264E200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8264D6D0"))) PPC_WEAK_FUNC(sub_8264D6D0);
PPC_FUNC_IMPL(__imp__sub_8264D6D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-992
	ctx.r3.s64 = ctx.r3.s64 + -992;
	// b 0x8264d650
	sub_8264D650(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8264D6D8"))) PPC_WEAK_FUNC(sub_8264D6D8);
PPC_FUNC_IMPL(__imp__sub_8264D6D8) {
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
	ctx.lr = 0x8264D6E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,-30604
	ctx.r9.s64 = r11.s64 + -30604;
	// addi r8,r10,-29796
	ctx.r8.s64 = ctx.r10.s64 + -29796;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r8,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r8.u32);
	// addi r28,r31,992
	r28.s64 = r31.s64 + 992;
	// lwz r5,5424(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 5424);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10224(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x8264D718;
	sub_8268B6D0(ctx, base);
	// addi r30,r31,2288
	r30.s64 = r31.s64 + 2288;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fbc8
	ctx.lr = 0x8264D724;
	sub_8221FBC8(ctx, base);
	// li r29,5
	r29.s64 = 5;
loc_8264D728:
	// addi r30,r30,-208
	r30.s64 = r30.s64 + -208;
	// lhz r11,194(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264d740
	if (cr6.eq) goto loc_8264D740;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8264D740;
	sub_82130588(ctx, base);
loc_8264D740:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8264D748;
	sub_82633B00(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8264d728
	if (!cr0.lt) goto loc_8264D728;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x8221fcc8
	ctx.lr = 0x8264D764;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8264D76C"))) PPC_WEAK_FUNC(sub_8264D76C);
PPC_FUNC_IMPL(__imp__sub_8264D76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

