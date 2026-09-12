#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8277BB6C"))) PPC_WEAK_FUNC(sub_8277BB6C);
PPC_FUNC_IMPL(__imp__sub_8277BB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277BB70"))) PPC_WEAK_FUNC(sub_8277BB70);
PPC_FUNC_IMPL(__imp__sub_8277BB70) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,1
	r31.s64 = 1;
loc_8277BB8C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277b9e8
	ctx.lr = 0x8277BB98;
	sub_8277B9E8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8277bb8c
	if (!cr0.lt) goto loc_8277BB8C;
	// li r5,84
	ctx.r5.s64 = 84;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BBB0;
	sub_821E4B18(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x8277BBC0;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_8277BBD8"))) PPC_WEAK_FUNC(sub_8277BBD8);
PPC_FUNC_IMPL(__imp__sub_8277BBD8) {
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
	ctx.lr = 0x8277BBE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// bl 0x821a5cc0
	ctx.lr = 0x8277BBF4;
	sub_821A5CC0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277BC04;
	sub_8277DC20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277bc40
	if (!cr6.eq) goto loc_8277BC40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8277BC18;
	sub_82130000(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,54
	r11.s64 = 54;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277BC40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BC40:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// addi r11,r11,-21504
	r11.s64 = r11.s64 + -21504;
	// addi r10,r10,-21032
	ctx.r10.s64 = ctx.r10.s64 + -21032;
	// addi r9,r9,-20744
	ctx.r9.s64 = ctx.r9.s64 + -20744;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// lis r4,-32136
	ctx.r4.s64 = -2106064896;
	// lis r3,-32136
	ctx.r3.s64 = -2106064896;
	// lis r28,-32136
	r28.s64 = -2106064896;
	// lis r27,-32136
	r27.s64 = -2106064896;
	// lis r26,15258
	r26.s64 = 999948288;
	// addi r8,r8,-20520
	ctx.r8.s64 = ctx.r8.s64 + -20520;
	// addi r7,r7,-20288
	ctx.r7.s64 = ctx.r7.s64 + -20288;
	// addi r6,r6,-20136
	ctx.r6.s64 = ctx.r6.s64 + -20136;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// addi r5,r5,-19984
	ctx.r5.s64 = ctx.r5.s64 + -19984;
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// addi r4,r4,-18960
	ctx.r4.s64 = ctx.r4.s64 + -18960;
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// addi r3,r3,-18456
	ctx.r3.s64 = ctx.r3.s64 + -18456;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// addi r11,r28,-17944
	r11.s64 = r28.s64 + -17944;
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// addi r10,r27,-17552
	ctx.r10.s64 = r27.s64 + -17552;
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// ori r9,r26,51712
	ctx.r9.u64 = r26.u64 | 51712;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r8,84
	ctx.r8.s64 = 84;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// stw r29,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r29.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// stw r29,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r29.u32);
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277BD00"))) PPC_WEAK_FUNC(sub_8277BD00);
PPC_FUNC_IMPL(__imp__sub_8277BD00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lbz r11,266(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 266);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bgt cr6,0x8277bdc0
	if (cr6.gt) goto loc_8277BDC0;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 204);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8277BDC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277BDC8"))) PPC_WEAK_FUNC(sub_8277BDC8);
PPC_FUNC_IMPL(__imp__sub_8277BDC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8277BDD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,202
	cr6.compare<int32_t>(r11.s32, 202, xer);
	// beq cr6,0x8277be0c
	if (cr6.eq) goto loc_8277BE0C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277BE0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BE0C:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r27,1
	r27.s64 = 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r28,4
	r28.s64 = 4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277be50
	if (cr6.gt) goto loc_8277BE50;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BE34;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BE44;
	sub_8277A320(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r27,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r27.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BE50:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277be88
	if (cr6.gt) goto loc_8277BE88;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BE68;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BE78;
	sub_8277A320(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r11,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r11.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BE88:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277bebc
	if (cr6.gt) goto loc_8277BEBC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BEA0;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BEB0;
	sub_8277A320(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BEBC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r10,280(r31)
	PPC_STORE_U32(r31.u32 + 280, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
loc_8277BED4:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277bf58
	if (!cr6.gt) goto loc_8277BF58;
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
loc_8277BEEC:
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// bge cr6,0x8277bf40
	if (!cr6.lt) goto loc_8277BF40;
	// lwz r7,272(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
loc_8277BF08:
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// rlwinm r4,r5,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// bgt cr6,0x8277bf40
	if (cr6.gt) goto loc_8277BF40;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mullw r3,r11,r5
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// mullw r5,r4,r9
	ctx.r5.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// bgt cr6,0x8277bf40
	if (cr6.gt) goto loc_8277BF40;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8277bf08
	if (cr6.lt) goto loc_8277BF08;
loc_8277BF40:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x8277beec
	if (cr6.lt) goto loc_8277BEEC;
loc_8277BF58:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r29,0
	r29.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277bfcc
	if (!cr6.gt) goto loc_8277BFCC;
	// addi r30,r11,36
	r30.s64 = r11.s64 + 36;
loc_8277BF70:
	// lwz r11,-28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -28);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,272(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r3,r7,r8
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277BF90;
	sub_8277A320(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lwz r6,276(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r5,-24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -24);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mullw r11,r5,r4
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// mullw r3,r11,r3
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r3.s32);
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277BFB4;
	sub_8277A320(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277bf70
	if (cr6.lt) goto loc_8277BF70;
loc_8277BFCC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8277c020
	if (cr6.gt) goto loc_8277C020;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-16396
	r12.s64 = r12.s64 + -16396;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8277C008;
	case 1:
		goto loc_8277C010;
	case 2:
		goto loc_8277C010;
	case 3:
		goto loc_8277C018;
	case 4:
		goto loc_8277C018;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-16376(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16376);
	// lwz r19,-16368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16368);
	// lwz r19,-16368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16368);
	// lwz r19,-16360(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16360);
	// lwz r19,-16360(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16360);
loc_8277C008:
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// b 0x8277c028
	goto loc_8277C028;
loc_8277C010:
	// li r11,3
	r11.s64 = 3;
	// b 0x8277c024
	goto loc_8277C024;
loc_8277C018:
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// b 0x8277c028
	goto loc_8277C028;
loc_8277C020:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
loc_8277C024:
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_8277C028:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x8277c03c
	if (!cr6.eq) goto loc_8277C03C;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
loc_8277C03C:
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277bd00
	ctx.lr = 0x8277C048;
	sub_8277BD00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c064
	if (cr6.eq) goto loc_8277C064;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277C064:
	// stw r27,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277C070"))) PPC_WEAK_FUNC(sub_8277C070);
PPC_FUNC_IMPL(__imp__sub_8277C070) {
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
	ctx.lr = 0x8277C078;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r28,384(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x8277bdc8
	ctx.lr = 0x8277C088;
	sub_8277BDC8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1408
	ctx.r5.s64 = 1408;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C0A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r3,256
	r30.s64 = ctx.r3.s64 + 256;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// bl 0x823d9890
	ctx.lr = 0x8277C0BC;
	sub_823D9890(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8277C0C4:
	// stbx r11,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, r11.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x8277c0c4
	if (!cr6.gt) goto loc_8277C0C4;
	// addi r30,r30,128
	r30.s64 = r30.s64 + 128;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r30,128
	r11.s64 = r30.s64 + 128;
	// li r10,384
	ctx.r10.s64 = 384;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8277C0E8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8277c0e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277C0E8;
	// li r5,384
	ctx.r5.s64 = 384;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,512
	ctx.r3.s64 = r30.s64 + 512;
	// bl 0x823d9890
	ctx.lr = 0x8277C104;
	sub_823D9890(ctx, base);
	// addi r3,r30,896
	ctx.r3.s64 = r30.s64 + 896;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r4,288(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// bl 0x823da950
	ctx.lr = 0x8277C114;
	sub_823DA950(ctx, base);
	// stw r29,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277bd00
	ctx.lr = 0x8277C120;
	sub_8277BD00(ctx, base);
	// stb r3,16(r28)
	PPC_STORE_U8(r28.u32 + 16, ctx.r3.u8);
	// stw r29,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r29.u32);
	// stw r29,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r29.u32);
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c144
	if (cr6.eq) goto loc_8277C144;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c150
	if (!cr6.eq) goto loc_8277C150;
loc_8277C144:
	// stb r29,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r29.u8);
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
loc_8277C150:
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1e8
	if (cr6.eq) goto loc_8277C1E8;
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c188
	if (cr6.eq) goto loc_8277C188;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C188:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8277c20c
	if (cr6.eq) goto loc_8277C20C;
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
loc_8277C1A0:
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
loc_8277C1A4:
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1c0
	if (cr6.eq) goto loc_8277C1C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82785498
	ctx.lr = 0x8277C1B8;
	sub_82785498(ctx, base);
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
loc_8277C1C0:
	// lbz r11,90(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c1d8
	if (!cr6.eq) goto loc_8277C1D8;
	// lbz r11,89(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1e8
	if (cr6.eq) goto loc_8277C1E8;
loc_8277C1D8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827846b8
	ctx.lr = 0x8277C1E0;
	sub_827846B8(ctx, base);
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// stw r11,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r11.u32);
loc_8277C1E8:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c24c
	if (!cr6.eq) goto loc_8277C24C;
	// lbz r11,16(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c234
	if (cr6.eq) goto loc_8277C234;
	// bl 0x82783240
	ctx.lr = 0x8277C208;
	sub_82783240(ctx, base);
	// b 0x8277c240
	goto loc_8277C240;
loc_8277C20C:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c220
	if (cr6.eq) goto loc_8277C220;
	// stb r30,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r30.u8);
	// b 0x8277c1a4
	goto loc_8277C1A4;
loc_8277C220:
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1a0
	if (cr6.eq) goto loc_8277C1A0;
	// stb r30,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r30.u8);
	// b 0x8277c1a4
	goto loc_8277C1A4;
loc_8277C234:
	// bl 0x827829f8
	ctx.lr = 0x8277C238;
	sub_827829F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827822e8
	ctx.lr = 0x8277C240;
	sub_827822E8(ctx, base);
loc_8277C240:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,90(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// bl 0x82781c48
	ctx.lr = 0x8277C24C;
	sub_82781C48(ctx, base);
loc_8277C24C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827817e8
	ctx.lr = 0x8277C254;
	sub_827817E8(ctx, base);
	// lbz r11,201(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 201);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c280
	if (cr6.eq) goto loc_8277C280;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277c29c
	goto loc_8277C29C;
loc_8277C280:
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c298
	if (cr6.eq) goto loc_8277C298;
	// bl 0x82781318
	ctx.lr = 0x8277C294;
	sub_82781318(ctx, base);
	// b 0x8277c29c
	goto loc_8277C29C;
loc_8277C298:
	// bl 0x82780490
	ctx.lr = 0x8277C29C;
	sub_82780490(ctx, base);
loc_8277C29C:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c2bc
	if (!cr6.eq) goto loc_8277C2BC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// beq cr6,0x8277c2c0
	if (cr6.eq) goto loc_8277C2C0;
loc_8277C2BC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8277C2C0:
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277f5f0
	ctx.lr = 0x8277C2CC;
	sub_8277F5F0(ctx, base);
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c2e4
	if (!cr6.eq) goto loc_8277C2E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277e378
	ctx.lr = 0x8277C2E4;
	sub_8277E378(ctx, base);
loc_8277C2E4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C2F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277c394
	if (cr6.eq) goto loc_8277C394;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c394
	if (!cr6.eq) goto loc_8277C394;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277c394
	if (cr6.eq) goto loc_8277C394;
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// beq cr6,0x8277c350
	if (cr6.eq) goto loc_8277C350;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8277C350:
	// stw r29,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r29.u32);
	// lwz r9,284(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r29,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, r29.u32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r5,90(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r3,1
	r11.u64 = ctx.r3.u64 ^ 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, r11.u32);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r10.u32);
loc_8277C394:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8277C39C"))) PPC_WEAK_FUNC(sub_8277C39C);
PPC_FUNC_IMPL(__imp__sub_8277C39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277C3A0"))) PPC_WEAK_FUNC(sub_8277C3A0);
PPC_FUNC_IMPL(__imp__sub_8277C3A0) {
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
	// lwz r30,384(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c404
	if (cr6.eq) goto loc_8277C404;
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
	// lwz r10,424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C3E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8277c534
	goto loc_8277C534;
loc_8277C404:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c480
	if (cr6.eq) goto loc_8277C480;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c480
	if (!cr6.eq) goto loc_8277C480;
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c448
	if (cr6.eq) goto loc_8277C448;
	// lbz r11,90(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c448
	if (cr6.eq) goto loc_8277C448;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// stb r10,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r10.u8);
	// b 0x8277c480
	goto loc_8277C480;
loc_8277C448:
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c460
	if (cr6.eq) goto loc_8277C460;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// b 0x8277c480
	goto loc_8277C480;
loc_8277C460:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,46
	ctx.r10.s64 = 46;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C480:
	// lwz r11,412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C4A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,65(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8277c548
	if (!cr6.eq) goto loc_8277C548;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c4d4
	if (!cr6.eq) goto loc_8277C4D4;
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C4D4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,74(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277c50c
	if (cr6.eq) goto loc_8277C50C;
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C50C:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r4,r8,30
	ctx.r4.u64 = ctx.r8.u32 & 0x3;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8277C534:
	// lwz r6,388(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8277C548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C548:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c5c0
	if (cr6.eq) goto loc_8277C5C0;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stw r5,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r5.u32);
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277c5c0
	if (cr6.eq) goto loc_8277C5C0;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c5c0
	if (!cr6.eq) goto loc_8277C5C0;
	// lbz r10,90(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
loc_8277C5C0:
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

__attribute__((alias("__imp__sub_8277C5D8"))) PPC_WEAK_FUNC(sub_8277C5D8);
PPC_FUNC_IMPL(__imp__sub_8277C5D8) {
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
	// lbz r11,74(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 74);
	// lwz r31,384(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c608
	if (cr6.eq) goto loc_8277C608;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C608:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277C628"))) PPC_WEAK_FUNC(sub_8277C628);
PPC_FUNC_IMPL(__imp__sub_8277C628) {
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
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// stw r9,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r9.u32);
	// addi r6,r8,-15456
	ctx.r6.s64 = ctx.r8.s64 + -15456;
	// addi r5,r7,-14888
	ctx.r5.s64 = ctx.r7.s64 + -14888;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// stw r5,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r4,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r4.u8);
	// bl 0x8277c070
	ctx.lr = 0x8277C684;
	sub_8277C070(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277C698"))) PPC_WEAK_FUNC(sub_8277C698);
PPC_FUNC_IMPL(__imp__sub_8277C698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r4,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r4.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c70c
	if (!cr0.eq) goto loc_8277C70C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c70c
	if (!cr6.eq) goto loc_8277C70C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,24
	ctx.r10.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C70C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277C720"))) PPC_WEAK_FUNC(sub_8277C720);
PPC_FUNC_IMPL(__imp__sub_8277C720) {
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
	ctx.lr = 0x8277C728;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r29,18
	r11.s64 = r29.s64 + 18;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r10,r31
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8277c76c
	if (!cr6.eq) goto loc_8277C76C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,52
	ctx.r10.s64 = 52;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C76C:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r25,4
	r11.s64 = r25.s64 + 4;
	// li r10,16
	ctx.r10.s64 = 16;
loc_8277C778:
	// lhz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c788
	if (!cr6.gt) goto loc_8277C788;
	// li r27,1
	r27.s64 = 1;
loc_8277C788:
	// lhz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c798
	if (!cr6.gt) goto loc_8277C798;
	// li r27,1
	r27.s64 = 1;
loc_8277C798:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c7a8
	if (!cr6.gt) goto loc_8277C7A8;
	// li r27,1
	r27.s64 = 1;
loc_8277C7A8:
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c7b8
	if (!cr6.gt) goto loc_8277C7B8;
	// li r27,1
	r27.s64 = 1;
loc_8277C7B8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8277c778
	if (!cr0.eq) goto loc_8277C778;
	// lbz r11,128(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277cad4
	if (!cr6.eq) goto loc_8277CAD4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r26,24
	r26.s64 = 24;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277c838
	if (!cr0.eq) goto loc_8277C838;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c838
	if (!cr6.eq) goto loc_8277C838;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C838:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,219
	ctx.r10.s64 = 219;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c89c
	if (!cr0.eq) goto loc_8277C89C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c89c
	if (!cr6.eq) goto loc_8277C89C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C89C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C89C:
	// subfic r10,r27,0
	xer.ca = r27.u32 <= 0;
	ctx.r10.s64 = 0 - r27.s64;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r9,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r10,67
	r30.s64 = ctx.r10.s64 + 67;
	// srawi r7,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r7.s64 = r30.s32 >> 8;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// bne 0x8277c910
	if (!cr0.eq) goto loc_8277C910;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C8E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c910
	if (!cr6.eq) goto loc_8277C910;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C910:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c970
	if (!cr0.eq) goto loc_8277C970;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c970
	if (!cr6.eq) goto loc_8277C970;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C970:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r27,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r10.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c9d8
	if (!cr0.eq) goto loc_8277C9D8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c9d8
	if (!cr6.eq) goto loc_8277C9D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C9D8:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r28,r11,-31424
	r28.s64 = r11.s64 + -31424;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8277C9E4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r30,r10,r25
	r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + r25.u32);
	// beq cr6,0x8277ca5c
	if (cr6.eq) goto loc_8277CA5C;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277ca5c
	if (!cr0.eq) goto loc_8277CA5C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CA34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277ca5c
	if (!cr6.eq) goto loc_8277CA5C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CA5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CA5C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277cabc
	if (!cr0.eq) goto loc_8277CABC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cabc
	if (!cr6.eq) goto loc_8277CABC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CABC:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r28,256
	r11.s64 = r28.s64 + 256;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277c9e4
	if (cr6.lt) goto loc_8277C9E4;
	// li r11,1
	r11.s64 = 1;
	// stb r11,128(r25)
	PPC_STORE_U8(r25.u32 + 128, r11.u8);
loc_8277CAD4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277CAE0"))) PPC_WEAK_FUNC(sub_8277CAE0);
PPC_FUNC_IMPL(__imp__sub_8277CAE0) {
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
	ctx.lr = 0x8277CAE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277cb0c
	if (cr6.eq) goto loc_8277CB0C;
	// addi r11,r29,26
	r11.s64 = r29.s64 + 26;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// b 0x8277cb10
	goto loc_8277CB10;
loc_8277CB0C:
	// addi r11,r29,22
	r11.s64 = r29.s64 + 22;
loc_8277CB10:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r10,r31
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8277cb48
	if (!cr6.eq) goto loc_8277CB48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,50
	ctx.r10.s64 = 50;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277CB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CB48:
	// lbz r11,273(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277cdcc
	if (!cr6.eq) goto loc_8277CDCC;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CB60;
	sub_8277C698(ctx, base);
	// li r4,196
	ctx.r4.s64 = 196;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CB6C;
	sub_8277C698(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r26,3
	r11.s64 = r26.s64 + 3;
	// li r10,4
	ctx.r10.s64 = 4;
loc_8277CB78:
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r28,r9,r28
	r28.u64 = ctx.r9.u64 + r28.u64;
	// bne 0x8277cb78
	if (!cr0.eq) goto loc_8277CB78;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r28,19
	r30.s64 = r28.s64 + 19;
	// li r27,24
	r27.s64 = 24;
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cc10
	if (!cr0.eq) goto loc_8277CC10;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CBE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cc10
	if (!cr6.eq) goto loc_8277CC10;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CC10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CC10:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cc70
	if (!cr0.eq) goto loc_8277CC70;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CC48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cc70
	if (!cr6.eq) goto loc_8277CC70;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CC70:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277ccd0
	if (!cr0.eq) goto loc_8277CCD0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CCA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277ccd0
	if (!cr6.eq) goto loc_8277CCD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CCD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CCD0:
	// li r30,1
	r30.s64 = 1;
loc_8277CCD4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbzx r10,r30,r26
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r26.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cd38
	if (!cr0.eq) goto loc_8277CD38;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CD10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cd38
	if (!cr6.eq) goto loc_8277CD38;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CD38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CD38:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// ble cr6,0x8277ccd4
	if (!cr6.gt) goto loc_8277CCD4;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8277cdc4
	if (!cr6.gt) goto loc_8277CDC4;
	// addi r29,r26,17
	r29.s64 = r26.s64 + 17;
loc_8277CD54:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cdb8
	if (!cr0.eq) goto loc_8277CDB8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CD90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cdb8
	if (!cr6.eq) goto loc_8277CDB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CDB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CDB8:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x8277cd54
	if (cr6.lt) goto loc_8277CD54;
loc_8277CDC4:
	// li r11,1
	r11.s64 = 1;
	// stb r11,273(r26)
	PPC_STORE_U8(r26.u32 + 273, r11.u8);
loc_8277CDCC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277CDD4"))) PPC_WEAK_FUNC(sub_8277CDD4);
PPC_FUNC_IMPL(__imp__sub_8277CDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277CDD8"))) PPC_WEAK_FUNC(sub_8277CDD8);
PPC_FUNC_IMPL(__imp__sub_8277CDD8) {
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
	ctx.lr = 0x8277CDE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CDF4;
	sub_8277C698(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CE00;
	sub_8277C698(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CE20;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CE2C;
	sub_8277C698(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// ori r11,r10,65535
	r11.u64 = ctx.r10.u64 | 65535;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bgt cr6,0x8277ce4c
	if (cr6.gt) goto loc_8277CE4C;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277ce74
	if (!cr6.gt) goto loc_8277CE74;
loc_8277CE4C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,41
	ctx.r9.s64 = 41;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r11.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277CE74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CE74:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x8277c698
	ctx.lr = 0x8277CE80;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CE94;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CEA0;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CEB4;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CEC0;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x8277c698
	ctx.lr = 0x8277CECC;
	sub_8277C698(ctx, base);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// ble cr6,0x8277d030
	if (!cr6.gt) goto loc_8277D030;
	// li r28,24
	r28.s64 = 24;
loc_8277CEE4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addic. r10,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r10.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cf48
	if (!cr0.eq) goto loc_8277CF48;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cf48
	if (!cr6.eq) goto loc_8277CF48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CF48:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// bne 0x8277cfb8
	if (!cr0.eq) goto loc_8277CFB8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CF90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cfb8
	if (!cr6.eq) goto loc_8277CFB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CFB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CFB8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d01c
	if (!cr0.eq) goto loc_8277D01C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CFF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d01c
	if (!cr6.eq) goto loc_8277D01C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D01C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D01C:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277cee4
	if (cr6.lt) goto loc_8277CEE4;
loc_8277D030:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8277D038"))) PPC_WEAK_FUNC(sub_8277D038);
PPC_FUNC_IMPL(__imp__sub_8277D038) {
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
	ctx.lr = 0x8277D040;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D050;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,218
	ctx.r4.s64 = 218;
	// bl 0x8277c698
	ctx.lr = 0x8277D05C;
	sub_8277C698(ctx, base);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r30,r11,1,0,30
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D078;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D084;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,228(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x8277c698
	ctx.lr = 0x8277D090;
	sub_8277C698(ctx, base);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// li r28,0
	r28.s64 = 0;
	// li r27,24
	r27.s64 = 24;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8277d1cc
	if (!cr6.gt) goto loc_8277D1CC;
	// addi r29,r31,232
	r29.s64 = r31.s64 + 232;
loc_8277D0A8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d110
	if (!cr0.eq) goto loc_8277D110;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D0E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d110
	if (!cr6.eq) goto loc_8277D110;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D110:
	// lbz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277d150
	if (cr6.eq) goto loc_8277D150;
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8277d14c
	if (!cr6.eq) goto loc_8277D14C;
	// lwz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277d150
	if (cr6.eq) goto loc_8277D150;
	// lbz r10,177(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d150
	if (!cr6.eq) goto loc_8277D150;
loc_8277D14C:
	// li r11,0
	r11.s64 = 0;
loc_8277D150:
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d1b8
	if (!cr0.eq) goto loc_8277D1B8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d1b8
	if (!cr6.eq) goto loc_8277D1B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D1B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D1B8:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8277d0a8
	if (cr6.lt) goto loc_8277D0A8;
loc_8277D1CC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d230
	if (!cr0.eq) goto loc_8277D230;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d230
	if (!cr6.eq) goto loc_8277D230;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D230:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277d294
	if (!cr0.eq) goto loc_8277D294;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d294
	if (!cr6.eq) goto loc_8277D294;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D294:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277d304
	if (!cr0.eq) goto loc_8277D304;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d304
	if (!cr6.eq) goto loc_8277D304;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D304:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277D30C"))) PPC_WEAK_FUNC(sub_8277D30C);
PPC_FUNC_IMPL(__imp__sub_8277D30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D310"))) PPC_WEAK_FUNC(sub_8277D310);
PPC_FUNC_IMPL(__imp__sub_8277D310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D330;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,224
	ctx.r4.s64 = 224;
	// bl 0x8277c698
	ctx.lr = 0x8277D33C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D348;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8277c698
	ctx.lr = 0x8277D354;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,74
	ctx.r4.s64 = 74;
	// bl 0x8277c698
	ctx.lr = 0x8277D360;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,70
	ctx.r4.s64 = 70;
	// bl 0x8277c698
	ctx.lr = 0x8277D36C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,73
	ctx.r4.s64 = 73;
	// bl 0x8277c698
	ctx.lr = 0x8277D378;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,70
	ctx.r4.s64 = 70;
	// bl 0x8277c698
	ctx.lr = 0x8277D384;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D390;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,197(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 197);
	// bl 0x8277c698
	ctx.lr = 0x8277D39C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,198(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// bl 0x8277c698
	ctx.lr = 0x8277D3A8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,199(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 199);
	// bl 0x8277c698
	ctx.lr = 0x8277D3B4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r30,200(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 200);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3C8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3D4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r30,202(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 202);
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3E8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3F4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D400;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D40C;
	sub_8277C698(ctx, base);
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

__attribute__((alias("__imp__sub_8277D424"))) PPC_WEAK_FUNC(sub_8277D424);
PPC_FUNC_IMPL(__imp__sub_8277D424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D428"))) PPC_WEAK_FUNC(sub_8277D428);
PPC_FUNC_IMPL(__imp__sub_8277D428) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D444;
	sub_8277C698(ctx, base);
	// li r4,238
	ctx.r4.s64 = 238;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D450;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D45C;
	sub_8277C698(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D468;
	sub_8277C698(ctx, base);
	// li r4,65
	ctx.r4.s64 = 65;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D474;
	sub_8277C698(ctx, base);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D480;
	sub_8277C698(ctx, base);
	// li r4,111
	ctx.r4.s64 = 111;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D48C;
	sub_8277C698(ctx, base);
	// li r4,98
	ctx.r4.s64 = 98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D498;
	sub_8277C698(ctx, base);
	// li r4,101
	ctx.r4.s64 = 101;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4A4;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4B0;
	sub_8277C698(ctx, base);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4BC;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4C8;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4D4;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4E0;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4EC;
	sub_8277C698(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8277d514
	if (cr6.eq) goto loc_8277D514;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x8277d50c
	if (cr6.eq) goto loc_8277D50C;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8277d518
	goto loc_8277D518;
loc_8277D50C:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8277d518
	goto loc_8277D518;
loc_8277D514:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8277D518:
	// bl 0x8277c698
	ctx.lr = 0x8277D51C;
	sub_8277C698(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277D530"))) PPC_WEAK_FUNC(sub_8277D530);
PPC_FUNC_IMPL(__imp__sub_8277D530) {
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
	ctx.lr = 0x8277D538;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,65533
	cr6.compare<uint32_t>(r30.u32, 65533, xer);
	// ble cr6,0x8277d56c
	if (!cr6.gt) goto loc_8277D56C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277D56C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D56C:
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D578;
	sub_8277C698(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D584;
	sub_8277C698(ctx, base);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D598;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D5A4;
	sub_8277C698(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277D5AC"))) PPC_WEAK_FUNC(sub_8277D5AC);
PPC_FUNC_IMPL(__imp__sub_8277D5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D5B0"))) PPC_WEAK_FUNC(sub_8277D5B0);
PPC_FUNC_IMPL(__imp__sub_8277D5B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8277c698
	sub_8277C698(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277D5B4"))) PPC_WEAK_FUNC(sub_8277D5B4);
PPC_FUNC_IMPL(__imp__sub_8277D5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D5B8"))) PPC_WEAK_FUNC(sub_8277D5B8);
PPC_FUNC_IMPL(__imp__sub_8277D5B8) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// lwz r30,332(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// bl 0x8277c698
	ctx.lr = 0x8277D5DC;
	sub_8277C698(ctx, base);
	// li r4,216
	ctx.r4.s64 = 216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D5E8;
	sub_8277C698(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
	// lbz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 196);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277d604
	if (cr6.eq) goto loc_8277D604;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d310
	ctx.lr = 0x8277D604;
	sub_8277D310(ctx, base);
loc_8277D604:
	// lbz r11,204(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d618
	if (cr6.eq) goto loc_8277D618;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d428
	ctx.lr = 0x8277D618;
	sub_8277D428(ctx, base);
loc_8277D618:
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

__attribute__((alias("__imp__sub_8277D630"))) PPC_WEAK_FUNC(sub_8277D630);
PPC_FUNC_IMPL(__imp__sub_8277D630) {
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
	ctx.lr = 0x8277D638;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277d680
	if (!cr6.gt) goto loc_8277D680;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
loc_8277D65C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8277c720
	ctx.lr = 0x8277D668;
	sub_8277C720(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277d65c
	if (cr6.lt) goto loc_8277D65C;
loc_8277D680:
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r30,1
	r30.s64 = 1;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277d6e4
	if (!cr6.gt) goto loc_8277D6E4;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
loc_8277D6BC:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bgt cr6,0x8277d6d4
	if (cr6.gt) goto loc_8277D6D4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x8277d6d8
	if (!cr6.gt) goto loc_8277D6D8;
loc_8277D6D4:
	// li r30,0
	r30.s64 = 0;
loc_8277D6D8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// bne 0x8277d6bc
	if (!cr0.eq) goto loc_8277D6BC;
loc_8277D6E4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8277d728
	if (cr6.eq) goto loc_8277D728;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d728
	if (cr6.eq) goto loc_8277D728;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,75
	ctx.r10.s64 = 75;
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277D720;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277d728
	goto loc_8277D728;
loc_8277D724:
	// li r30,0
	r30.s64 = 0;
loc_8277D728:
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d748
	if (cr6.eq) goto loc_8277D748;
	// li r4,201
	ctx.r4.s64 = 201;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D740;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8277D748:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d768
	if (cr6.eq) goto loc_8277D768;
	// li r4,194
	ctx.r4.s64 = 194;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D760;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8277D768:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// li r4,192
	ctx.r4.s64 = 192;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d77c
	if (!cr6.eq) goto loc_8277D77C;
	// li r4,193
	ctx.r4.s64 = 193;
loc_8277D77C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D784;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8277D78C"))) PPC_WEAK_FUNC(sub_8277D78C);
PPC_FUNC_IMPL(__imp__sub_8277D78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D790"))) PPC_WEAK_FUNC(sub_8277D790);
PPC_FUNC_IMPL(__imp__sub_8277D790) {
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
	ctx.lr = 0x8277D798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// lwz r27,332(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d82c
	if (!cr6.eq) goto loc_8277D82C;
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277d82c
	if (!cr6.gt) goto loc_8277D82C;
	// addi r29,r31,232
	r29.s64 = r31.s64 + 232;
loc_8277D7C4:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d7f8
	if (cr6.eq) goto loc_8277D7F8;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277d808
	if (!cr6.eq) goto loc_8277D808;
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277d818
	if (!cr6.eq) goto loc_8277D818;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8277d810
	goto loc_8277D810;
loc_8277D7F8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D808;
	sub_8277CAE0(ctx, base);
loc_8277D808:
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
loc_8277D810:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D818;
	sub_8277CAE0(ctx, base);
loc_8277D818:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8277d7c4
	if (cr6.lt) goto loc_8277D7C4;
loc_8277D82C:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r10,28(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8277d894
	if (cr6.eq) goto loc_8277D894;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D848;
	sub_8277C698(ctx, base);
	// li r4,221
	ctx.r4.s64 = 221;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D854;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D860;
	sub_8277C698(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D86C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,188(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D880;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D88C;
	sub_8277C698(ctx, base);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r10,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r10.u32);
loc_8277D894:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d038
	ctx.lr = 0x8277D89C;
	sub_8277D038(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277D8A4"))) PPC_WEAK_FUNC(sub_8277D8A4);
PPC_FUNC_IMPL(__imp__sub_8277D8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D8A8"))) PPC_WEAK_FUNC(sub_8277D8A8);
PPC_FUNC_IMPL(__imp__sub_8277D8A8) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D8C4;
	sub_8277C698(ctx, base);
	// li r4,217
	ctx.r4.s64 = 217;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D8D0;
	sub_8277C698(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277D8E4"))) PPC_WEAK_FUNC(sub_8277D8E4);
PPC_FUNC_IMPL(__imp__sub_8277D8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277D8E8"))) PPC_WEAK_FUNC(sub_8277D8E8);
PPC_FUNC_IMPL(__imp__sub_8277D8E8) {
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
	ctx.lr = 0x8277D8F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D900;
	sub_8277C698(ctx, base);
	// li r4,216
	ctx.r4.s64 = 216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D90C;
	sub_8277C698(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,72
	r29.s64 = r31.s64 + 72;
loc_8277D914:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d92c
	if (cr6.eq) goto loc_8277D92C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c720
	ctx.lr = 0x8277D92C;
	sub_8277C720(ctx, base);
loc_8277D92C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x8277d914
	if (cr6.lt) goto loc_8277D914;
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d998
	if (!cr6.eq) goto loc_8277D998;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,104
	r29.s64 = r31.s64 + 104;
loc_8277D950:
	// lwz r11,-16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d96c
	if (cr6.eq) goto loc_8277D96C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D96C;
	sub_8277CAE0(ctx, base);
loc_8277D96C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d988
	if (cr6.eq) goto loc_8277D988;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D988;
	sub_8277CAE0(ctx, base);
loc_8277D988:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x8277d950
	if (cr6.lt) goto loc_8277D950;
loc_8277D998:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r30,24
	r30.s64 = 24;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277da00
	if (!cr0.eq) goto loc_8277DA00;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277da00
	if (!cr6.eq) goto loc_8277DA00;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DA00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277DA00:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,217
	ctx.r10.s64 = 217;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277da64
	if (!cr0.eq) goto loc_8277DA64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277DA3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277da64
	if (!cr6.eq) goto loc_8277DA64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DA64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277DA64:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277DA6C"))) PPC_WEAK_FUNC(sub_8277DA6C);
PPC_FUNC_IMPL(__imp__sub_8277DA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277DA70"))) PPC_WEAK_FUNC(sub_8277DA70);
PPC_FUNC_IMPL(__imp__sub_8277DA70) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277DA9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,332(r31)
	PPC_STORE_U32(r31.u32 + 332, ctx.r3.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r10,r9,-10824
	ctx.r10.s64 = ctx.r9.s64 + -10824;
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// addi r9,r8,-10704
	ctx.r9.s64 = ctx.r8.s64 + -10704;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r4,-32136
	ctx.r4.s64 = -2106064896;
	// addi r8,r7,-10352
	ctx.r8.s64 = ctx.r7.s64 + -10352;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r7,r6,-10072
	ctx.r7.s64 = ctx.r6.s64 + -10072;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// addi r6,r5,-10008
	ctx.r6.s64 = ctx.r5.s64 + -10008;
	// addi r5,r4,-10960
	ctx.r5.s64 = ctx.r4.s64 + -10960;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// addi r4,r11,-10832
	ctx.r4.s64 = r11.s64 + -10832;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// stw r4,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277DB10"))) PPC_WEAK_FUNC(sub_8277DB10);
PPC_FUNC_IMPL(__imp__sub_8277DB10) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8278c480
	ctx.lr = 0x8277DB2C;
	sub_8278C480(ctx, base);
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277db54
	if (!cr6.eq) goto loc_8277DB54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278b270
	ctx.lr = 0x8277DB40;
	sub_8278B270(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278ab90
	ctx.lr = 0x8277DB48;
	sub_8278AB90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278a188
	ctx.lr = 0x8277DB54;
	sub_8278A188(ctx, base);
loc_8277DB54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82789a30
	ctx.lr = 0x8277DB5C;
	sub_82789A30(ctx, base);
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277db8c
	if (cr6.eq) goto loc_8277DB8C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277DB88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277dba8
	goto loc_8277DBA8;
loc_8277DB8C:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277dba4
	if (cr6.eq) goto loc_8277DBA4;
	// bl 0x827885c8
	ctx.lr = 0x8277DBA0;
	sub_827885C8(ctx, base);
	// b 0x8277dba8
	goto loc_8277DBA8;
loc_8277DBA4:
	// bl 0x82787518
	ctx.lr = 0x8277DBA8;
	sub_82787518(ctx, base);
loc_8277DBA8:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x8277dbc4
	if (cr6.gt) goto loc_8277DBC4;
	// lbz r11,178(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 178);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277dbc8
	if (cr6.eq) goto loc_8277DBC8;
loc_8277DBC4:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8277DBC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82786088
	ctx.lr = 0x8277DBD0;
	sub_82786088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82785700
	ctx.lr = 0x8277DBDC;
	sub_82785700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277da70
	ctx.lr = 0x8277DBE4;
	sub_8277DA70(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277DBF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,332(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277DC0C;
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

__attribute__((alias("__imp__sub_8277DC20"))) PPC_WEAK_FUNC(sub_8277DC20);
PPC_FUNC_IMPL(__imp__sub_8277DC20) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x821bc130
	sub_821BC130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277DC28"))) PPC_WEAK_FUNC(sub_8277DC28);
PPC_FUNC_IMPL(__imp__sub_8277DC28) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277DC30"))) PPC_WEAK_FUNC(sub_8277DC30);
PPC_FUNC_IMPL(__imp__sub_8277DC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,49
	ctx.r10.s64 = 49;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8277DC4C"))) PPC_WEAK_FUNC(sub_8277DC4C);
PPC_FUNC_IMPL(__imp__sub_8277DC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277DC50"))) PPC_WEAK_FUNC(sub_8277DC50);
PPC_FUNC_IMPL(__imp__sub_8277DC50) {
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
	ctx.lr = 0x8277DC58;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r27,388(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// lwz r30,280(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DC84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,56(r27)
	PPC_STORE_U32(r27.u32 + 56, ctx.r3.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r3
	ctx.r7.u64 = r11.u64 + ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// stw r7,60(r27)
	PPC_STORE_U32(r27.u32 + 60, ctx.r7.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ble cr6,0x8277dd38
	if (!cr6.gt) goto loc_8277DD38;
	// addi r26,r30,4
	r26.s64 = r30.s64 + 4;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8277DCB8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r25,r8,r9
	r25.s32 = ctx.r8.s32 / ctx.r9.s32;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// mullw r24,r26,r25
	r24.s64 = int64_t(r26.s32) * int64_t(r25.s32);
	// andc r11,r9,r5
	r11.u64 = ctx.r9.u64 & ~ctx.r5.u64;
	// twllei r9,0
	// rlwinm r5,r24,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 3) & 0xFFFFFFF8;
	// twlgei r11,-1
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277DD00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r8,r25,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,56(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r8
	r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// stwx r11,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + r29.u32, r11.u32);
	// lwz r6,60(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 60);
	// stwx r7,r29,r6
	PPC_STORE_U32(r29.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r28,r5
	cr6.compare<int32_t>(r28.s32, ctx.r5.s32, xer);
	// blt cr6,0x8277dcb8
	if (cr6.lt) goto loc_8277DCB8;
loc_8277DD38:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8277DD40"))) PPC_WEAK_FUNC(sub_8277DD40);
PPC_FUNC_IMPL(__imp__sub_8277DD40) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8277DD48;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r25,0
	r25.s64 = 0;
	// lwz r28,388(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r27,280(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// ble cr6,0x8277de70
	if (!cr6.gt) goto loc_8277DE70;
	// addi r26,r27,2
	r26.s64 = r27.s64 + 2;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8277DD74:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,280(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,56(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r7,r5,r6
	ctx.r7.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// twllei r6,0
	// andc r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 & ~ctx.r10.u64;
	// mullw. r9,r26,r7
	ctx.r9.s64 = int64_t(r26.s32) * int64_t(ctx.r7.s32);
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// twlgei r6,-1
	// ble 0x8277dddc
	if (!cr0.gt) goto loc_8277DDDC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// subf r5,r11,r4
	ctx.r5.s64 = ctx.r4.s64 - r11.s64;
loc_8277DDC4:
	// lwzx r24,r6,r10
	r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r24,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r24.u32);
	// stwx r24,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, r24.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8277ddc4
	if (!cr0.eq) goto loc_8277DDC4;
loc_8277DDDC:
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8277de30
	if (!cr6.gt) goto loc_8277DE30;
	// addi r10,r27,-2
	ctx.r10.s64 = r27.s64 + -2;
	// mullw r9,r7,r27
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(r27.s32);
	// mullw r6,r10,r7
	ctx.r6.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// subf r8,r8,r11
	ctx.r8.s64 = r11.s64 - ctx.r8.s64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_8277DE10:
	// lwzx r5,r9,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r5,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8277de10
	if (!cr0.eq) goto loc_8277DE10;
loc_8277DE30:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8277de54
	if (!cr6.gt) goto loc_8277DE54;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
loc_8277DE40:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8277de40
	if (!cr0.eq) goto loc_8277DE40;
loc_8277DE54:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8277dd74
	if (cr6.lt) goto loc_8277DD74;
loc_8277DE70:
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8277DE74"))) PPC_WEAK_FUNC(sub_8277DE74);
PPC_FUNC_IMPL(__imp__sub_8277DE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277DE78"))) PPC_WEAK_FUNC(sub_8277DE78);
PPC_FUNC_IMPL(__imp__sub_8277DE78) {
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
	ctx.lr = 0x8277DE80;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r29,0
	r29.s64 = 0;
	// lwz r30,388(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r31,280(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// ble cr6,0x8277df5c
	if (!cr6.gt) goto loc_8277DF5C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
loc_8277DEA4:
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,280(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r6,56(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// lwzx r6,r5,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwzx r11,r5,r11
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw. r10,r7,r8
	ctx.r10.s32 = ctx.r7.s32 / ctx.r8.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r8,0
	// andc r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// ble 0x8277df44
	if (!cr0.gt) goto loc_8277DF44;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r10,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// subf r8,r28,r11
	ctx.r8.s64 = r11.s64 - r28.s64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - r11.s64;
loc_8277DF0C:
	// lwzx r28,r6,r9
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r28,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, r28.u32);
	// lwz r28,0(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r28,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r28.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lwzx r28,r6,r11
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// stwx r28,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, r28.u32);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r28,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r28.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8277df0c
	if (!cr0.eq) goto loc_8277DF0C;
loc_8277DF44:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r4,r4,84
	ctx.r4.s64 = ctx.r4.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277dea4
	if (cr6.lt) goto loc_8277DEA4;
loc_8277DF5C:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8277DF60"))) PPC_WEAK_FUNC(sub_8277DF60);
PPC_FUNC_IMPL(__imp__sub_8277DF60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,388(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e048
	if (!cr6.gt) goto loc_8277E048;
	// addi r7,r11,12
	ctx.r7.s64 = r11.s64 + 12;
loc_8277DF80:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// lwz r9,32(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,280(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divwu r4,r9,r11
	ctx.r4.u32 = ctx.r9.u32 / r11.u32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r4,r4,r11
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// andc r31,r8,r10
	r31.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// subf. r10,r4,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// twllei r11,0
	// divw r9,r11,r8
	ctx.r9.s32 = r11.s32 / ctx.r8.s32;
	// twllei r8,0
	// twlgei r31,-1
	// bne 0x8277dfc4
	if (!cr0.eq) goto loc_8277DFC4;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8277DFC4:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8277dff0
	if (!cr6.eq) goto loc_8277DFF0;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// twllei r9,0
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r11,r11,r9
	r11.s32 = r11.s32 / ctx.r9.s32;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// andc r11,r9,r8
	r11.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// stw r4,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r4.u32);
	// twlgei r11,-1
loc_8277DFF0:
	// lwz r8,64(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r8,14
	ctx.r9.s64 = ctx.r8.s64 + 14;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r8,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r9,r9,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// ble cr6,0x8277e034
	if (!cr6.gt) goto loc_8277E034;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8277E020:
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8277e020
	if (!cr0.eq) goto loc_8277E020;
loc_8277E034:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,84
	ctx.r7.s64 = ctx.r7.s64 + 84;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// blt cr6,0x8277df80
	if (cr6.lt) goto loc_8277DF80;
loc_8277E048:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277E050"))) PPC_WEAK_FUNC(sub_8277E050);
PPC_FUNC_IMPL(__imp__sub_8277E050) {
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
	ctx.lr = 0x8277E058;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r30,388(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// lbz r11,48(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e0a0
	if (!cr6.eq) goto loc_8277E0A0;
	// lwz r11,392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277e0ec
	if (cr6.eq) goto loc_8277E0EC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,48(r30)
	PPC_STORE_U8(r30.u32 + 48, r11.u8);
loc_8277E0A0:
	// lwz r11,396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// addi r29,r30,52
	r29.s64 = r30.s64 + 52;
	// lwz r25,280(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,52(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplw cr6,r9,r25
	cr6.compare<uint32_t>(ctx.r9.u32, r25.u32, xer);
	// blt cr6,0x8277e0ec
	if (cr6.lt) goto loc_8277E0EC;
	// li r11,0
	r11.s64 = 0;
	// stb r11,48(r30)
	PPC_STORE_U8(r30.u32 + 48, r11.u8);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8277E0EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277E0F4"))) PPC_WEAK_FUNC(sub_8277E0F4);
PPC_FUNC_IMPL(__imp__sub_8277E0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277E0F8"))) PPC_WEAK_FUNC(sub_8277E0F8);
PPC_FUNC_IMPL(__imp__sub_8277E0F8) {
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
	ctx.lr = 0x8277E100;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r24,1
	r24.s64 = 1;
	// lwz r31,388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e160
	if (!cr6.eq) goto loc_8277E160;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,392(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// addi r9,r11,14
	ctx.r9.s64 = r11.s64 + 14;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277E148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277e290
	if (cr6.eq) goto loc_8277E290;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stb r24,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r24.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_8277E160:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277e1d4
	if (cr6.lt) goto loc_8277E1D4;
	// beq cr6,0x8277e200
	if (cr6.eq) goto loc_8277E200;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8277e290
	if (!cr6.lt) goto loc_8277E290;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r5,r31,52
	ctx.r5.s64 = r31.s64 + 52;
	// lwz r10,396(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r11,14
	ctx.r7.s64 = r11.s64 + 14;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r4,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8277e290
	if (cr6.lt) goto loc_8277E290;
	// stw r25,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r25.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277e290
	if (!cr6.lt) goto loc_8277E290;
loc_8277E1D4:
	// stw r25,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r25.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// lwz r8,284(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x8277e1fc
	if (!cr6.eq) goto loc_8277E1FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277df60
	ctx.lr = 0x8277E1FC;
	sub_8277DF60(ctx, base);
loc_8277E1FC:
	// stw r24,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r24.u32);
loc_8277E200:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r29,r31,52
	r29.s64 = r31.s64 + 52;
	// lwz r10,396(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r11,14
	ctx.r7.s64 = r11.s64 + 14;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r4,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E23C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8277e290
	if (cr6.lt) goto loc_8277E290;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8277e260
	if (!cr6.eq) goto loc_8277E260;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277de78
	ctx.lr = 0x8277E260;
	sub_8277DE78(ctx, base);
loc_8277E260:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r25,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r25.u8);
	// xori r9,r11,1
	ctx.r9.u64 = r11.u64 ^ 1;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
loc_8277E290:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8277E298"))) PPC_WEAK_FUNC(sub_8277E298);
PPC_FUNC_IMPL(__imp__sub_8277E298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,396(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8277E2C0"))) PPC_WEAK_FUNC(sub_8277E2C0);
PPC_FUNC_IMPL(__imp__sub_8277E2C0) {
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
	// lwz r31,388(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8277e318
	if (cr6.eq) goto loc_8277E318;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8277e308
	if (cr6.eq) goto loc_8277E308;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277e360
	goto loc_8277E360;
loc_8277E308:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-7528
	ctx.r10.s64 = r11.s64 + -7528;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// b 0x8277e360
	goto loc_8277E360;
loc_8277E318:
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// li r30,0
	r30.s64 = 0;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277e34c
	if (cr6.eq) goto loc_8277E34C;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-7944
	ctx.r10.s64 = r11.s64 + -7944;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x8277dd40
	ctx.lr = 0x8277E33C;
	sub_8277DD40(ctx, base);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// b 0x8277e358
	goto loc_8277E358;
loc_8277E34C:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-8112
	ctx.r10.s64 = r11.s64 + -8112;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_8277E358:
	// stb r30,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r30.u8);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
loc_8277E360:
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

__attribute__((alias("__imp__sub_8277E378"))) PPC_WEAK_FUNC(sub_8277E378);
PPC_FUNC_IMPL(__imp__sub_8277E378) {
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
	ctx.lr = 0x8277E380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E3A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// stw r29,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r29.u32);
	// addi r7,r9,-7488
	ctx.r7.s64 = ctx.r9.s64 + -7488;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// beq cr6,0x8277e3e4
	if (cr6.eq) goto loc_8277E3E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E3E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277E3E4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277e434
	if (cr6.eq) goto loc_8277E434;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x8277e420
	if (!cr6.lt) goto loc_8277E420;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277E420:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277dc50
	ctx.lr = 0x8277E428;
	sub_8277DC50(ctx, base);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// addi r27,r11,2
	r27.s64 = r11.s64 + 2;
	// b 0x8277e438
	goto loc_8277E438;
loc_8277E434:
	// lwz r27,280(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 280);
loc_8277E438:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e4bc
	if (!cr6.gt) goto loc_8277E4BC;
	// addi r30,r11,36
	r30.s64 = r11.s64 + 36;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
loc_8277E454:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,-24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,280(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,-8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// lwz r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r7,r7,r8
	ctx.r7.s32 = ctx.r7.s32 / ctx.r8.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r8,0
	// andc r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & ~r11.u64;
	// mullw r6,r7,r27
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r27.s32);
	// mullw r5,r5,r10
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// twlgei r8,-1
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277E4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r28,r7
	cr6.compare<int32_t>(r28.s32, ctx.r7.s32, xer);
	// blt cr6,0x8277e454
	if (cr6.lt) goto loc_8277E454;
loc_8277E4BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277E4C4"))) PPC_WEAK_FUNC(sub_8277E4C4);
PPC_FUNC_IMPL(__imp__sub_8277E4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277E4C8"))) PPC_WEAK_FUNC(sub_8277E4C8);
PPC_FUNC_IMPL(__imp__sub_8277E4C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,292(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x8277e4f0
	if (!cr6.gt) goto loc_8277E4F0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// blr 
	return;
loc_8277E4F0:
	// lwz r10,284(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,296(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x8277e520
	if (!cr6.lt) goto loc_8277E520;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// blr 
	return;
loc_8277E520:
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277E538"))) PPC_WEAK_FUNC(sub_8277E538);
PPC_FUNC_IMPL(__imp__sub_8277E538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// b 0x8277e4c8
	sub_8277E4C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277E544"))) PPC_WEAK_FUNC(sub_8277E544);
PPC_FUNC_IMPL(__imp__sub_8277E544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277E548"))) PPC_WEAK_FUNC(sub_8277E548);
PPC_FUNC_IMPL(__imp__sub_8277E548) {
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
	ctx.lr = 0x8277E550;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// lwz r11,312(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 312);
	// lwz r18,392(r26)
	r18.u64 = PPC_LOAD_U32(r26.u32 + 392);
	// addi r14,r11,-1
	r14.s64 = r11.s64 + -1;
	// lwz r11,284(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 284);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r19,24(r18)
	r19.u64 = PPC_LOAD_U32(r18.u32 + 24);
	// lwz r10,28(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmpw cr6,r19,r10
	cr6.compare<int32_t>(r19.s32, ctx.r10.s32, xer);
	// bge cr6,0x8277e718
	if (!cr6.lt) goto loc_8277E718;
loc_8277E584:
	// lwz r20,20(r18)
	r20.u64 = PPC_LOAD_U32(r18.u32 + 20);
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// bgt cr6,0x8277e700
	if (cr6.gt) goto loc_8277E700;
loc_8277E590:
	// lwz r11,320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// addi r31,r18,32
	r31.s64 = r18.s64 + 32;
	// lwz r3,32(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + 32);
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// bl 0x8277a3e8
	ctx.lr = 0x8277E5A4;
	sub_8277A3E8(ctx, base);
	// lwz r10,408(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 408);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277E5BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277e76c
	if (cr6.eq) goto loc_8277E76C;
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// li r23,0
	r23.s64 = 0;
	// li r15,0
	r15.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e6f4
	if (!cr6.gt) goto loc_8277E6F4;
	// addi r16,r26,296
	r16.s64 = r26.s64 + 296;
loc_8277E5E0:
	// lwz r31,0(r16)
	r31.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e5fc
	if (!cr6.eq) goto loc_8277E5FC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
	// b 0x8277e6e0
	goto loc_8277E6E0;
loc_8277E5FC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// lwz r10,412(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 412);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r24,4(r10)
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bge cr6,0x8277e620
	if (!cr6.lt) goto loc_8277E620;
	// lwz r22,52(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x8277e624
	goto loc_8277E624;
loc_8277E620:
	// lwz r22,68(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 68);
loc_8277E624:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r25,0
	r25.s64 = 0;
	// lwzx r10,r11,r17
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// mullw r8,r9,r19
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r19.s32);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r21,r7,r20
	r21.s64 = int64_t(ctx.r7.s32) * int64_t(r20.s32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// ble cr6,0x8277e6e0
	if (!cr6.gt) goto loc_8277E6E0;
loc_8277E650:
	// lwz r11,128(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8277e670
	if (cr6.lt) goto loc_8277E670;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r10,r25,r19
	ctx.r10.u64 = r25.u64 + r19.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277e6bc
	if (!cr6.lt) goto loc_8277E6BC;
loc_8277E670:
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x8277e6bc
	if (!cr6.gt) goto loc_8277E6BC;
	// addi r11,r23,8
	r11.s64 = r23.s64 + 8;
	// mr r30,r22
	r30.u64 = r22.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r18
	r29.u64 = r11.u64 + r18.u64;
loc_8277E68C:
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mtctr r24
	ctr.u64 = r24.u64;
	// bctrl 
	ctx.lr = 0x8277E6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// bne 0x8277e68c
	if (!cr0.eq) goto loc_8277E68C;
loc_8277E6BC:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r23,r10,r23
	r23.u64 = ctx.r10.u64 + r23.u64;
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// cmpw cr6,r25,r9
	cr6.compare<int32_t>(r25.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277e650
	if (cr6.lt) goto loc_8277E650;
loc_8277E6E0:
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// addi r16,r16,4
	r16.s64 = r16.s64 + 4;
	// cmpw cr6,r15,r11
	cr6.compare<int32_t>(r15.s32, r11.s32, xer);
	// blt cr6,0x8277e5e0
	if (cr6.lt) goto loc_8277E5E0;
loc_8277E6F4:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// ble cr6,0x8277e590
	if (!cr6.gt) goto loc_8277E590;
loc_8277E700:
	// li r11,0
	r11.s64 = 0;
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// stw r11,20(r18)
	PPC_STORE_U32(r18.u32 + 20, r11.u32);
	// lwz r10,28(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// cmpw cr6,r19,r10
	cr6.compare<int32_t>(r19.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277e584
	if (cr6.lt) goto loc_8277E584;
loc_8277E718:
	// lwz r11,136(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 136);
	// lwz r10,284(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 284);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,128(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r9,136(r26)
	PPC_STORE_U32(r26.u32 + 136, ctx.r9.u32);
	// stw r11,128(r26)
	PPC_STORE_U32(r26.u32 + 128, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277e7b8
	if (!cr6.lt) goto loc_8277E7B8;
	// lwz r8,292(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// lwz r9,392(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 392);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x8277e780
	if (!cr6.gt) goto loc_8277E780;
	// li r11,1
	r11.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// stw r11,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E76C:
	// stw r19,24(r18)
	PPC_STORE_U32(r18.u32 + 24, r19.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r20,20(r18)
	PPC_STORE_U32(r18.u32 + 20, r20.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E780:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// lwz r11,296(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 296);
	// bge cr6,0x8277e798
	if (!cr6.lt) goto loc_8277E798;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x8277e79c
	goto loc_8277E79C;
loc_8277E798:
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
loc_8277E79C:
	// li r11,0
	r11.s64 = 0;
	// stw r10,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r10.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// stw r11,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E7B8:
	// lwz r11,400(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 400);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E7CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8277E7D8"))) PPC_WEAK_FUNC(sub_8277E7D8);
PPC_FUNC_IMPL(__imp__sub_8277E7D8) {
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
	ctx.lr = 0x8277E7E0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// lwz r27,392(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 392);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e860
	if (!cr6.gt) goto loc_8277E860;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,296
	r31.s64 = r28.s64 + 296;
loc_8277E808:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,128(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r4,r11,18
	ctx.r4.s64 = r11.s64 + 18;
	// lwz r11,32(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r5,r8,r5
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,292(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277e808
	if (cr6.lt) goto loc_8277E808;
loc_8277E860:
	// lwz r23,24(r27)
	r23.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// bge cr6,0x8277e984
	if (!cr6.lt) goto loc_8277E984;
	// rlwinm r24,r23,2,0,29
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
loc_8277E874:
	// lwz r26,20(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r11,312(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 312);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bge cr6,0x8277e96c
	if (!cr6.lt) goto loc_8277E96C;
	// addi r22,r27,32
	r22.s64 = r27.s64 + 32;
loc_8277E888:
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e938
	if (!cr6.gt) goto loc_8277E938;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,296
	r31.s64 = r28.s64 + 296;
loc_8277E8A4:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// lwz r10,56(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mullw r11,r8,r26
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r26.s32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e920
	if (!cr6.gt) goto loc_8277E920;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r5,r24,r10
	ctx.r5.u64 = r24.u64 + ctx.r10.u64;
loc_8277E8CC:
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// ble cr6,0x8277e90c
	if (!cr6.gt) goto loc_8277E90C;
	// addi r11,r6,8
	r11.s64 = ctx.r6.s64 + 8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_8277E8EC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8277e8ec
	if (cr6.lt) goto loc_8277E8EC;
loc_8277E90C:
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x8277e8cc
	if (cr6.lt) goto loc_8277E8CC;
loc_8277E920:
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277e8a4
	if (cr6.lt) goto loc_8277E8A4;
loc_8277E938:
	// lwz r11,408(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 408);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277e9c8
	if (cr6.eq) goto loc_8277E9C8;
	// lwz r11,312(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 312);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x8277e888
	if (cr6.lt) goto loc_8277E888;
loc_8277E96C:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// stw r25,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r25.u32);
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x8277e874
	if (cr6.lt) goto loc_8277E874;
loc_8277E984:
	// lwz r11,128(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r9,284(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,128(r28)
	PPC_STORE_U32(r28.u32 + 128, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8277ea24
	if (!cr6.lt) goto loc_8277EA24;
	// lwz r8,292(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// lwz r10,392(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 392);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x8277e9dc
	if (!cr6.gt) goto loc_8277E9DC;
	// li r11,1
	r11.s64 = 1;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r11,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277E9C8:
	// stw r23,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r26,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277E9DC:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// lwz r11,296(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 296);
	// bge cr6,0x8277ea08
	if (!cr6.lt) goto loc_8277EA08;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277EA08:
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277EA24:
	// lwz r11,400(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 400);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8277EA44"))) PPC_WEAK_FUNC(sub_8277EA44);
PPC_FUNC_IMPL(__imp__sub_8277EA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277EA48"))) PPC_WEAK_FUNC(sub_8277EA48);
PPC_FUNC_IMPL(__imp__sub_8277EA48) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8277EA50;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// lwz r30,392(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 392);
	// addi r18,r11,-1
	r18.s64 = r11.s64 + -1;
loc_8277EA68:
	// lwz r11,124(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 124);
	// lwz r10,132(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277ea8c
	if (cr6.lt) goto loc_8277EA8C;
	// bne cr6,0x8277eab0
	if (!cr6.eq) goto loc_8277EAB0;
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// lwz r10,136(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277eab0
	if (cr6.gt) goto loc_8277EAB0;
loc_8277EA8C:
	// lwz r11,400(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 400);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EAA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8277ea68
	if (!cr6.eq) goto loc_8277EA68;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
loc_8277EAB0:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// li r20,0
	r20.s64 = 0;
	// lwz r31,196(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277ebdc
	if (!cr6.gt) goto loc_8277EBDC;
	// li r22,0
	r22.s64 = 0;
	// addi r21,r30,72
	r21.s64 = r30.s64 + 72;
loc_8277EACC:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ebc0
	if (cr6.eq) goto loc_8277EBC0;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,136(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// lwz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// mullw r5,r9,r10
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277EB04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,136(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// cmplw cr6,r7,r18
	cr6.compare<uint32_t>(ctx.r7.u32, r18.u32, xer);
	// bge cr6,0x8277eb18
	if (!cr6.lt) goto loc_8277EB18;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// b 0x8277eb38
	goto loc_8277EB38;
loc_8277EB18:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// twllei r10,0
	// divwu r9,r11,r10
	ctx.r9.u32 = r11.u32 / ctx.r10.u32;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf. r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8277eb38
	if (!cr0.eq) goto loc_8277EB38;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277EB38:
	// lwz r10,412(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 412);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwzx r26,r22,r19
	r26.u64 = PPC_LOAD_U32(r22.u32 + r19.u32);
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + r22.u64;
	// lwz r25,4(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// ble cr6,0x8277ebc0
	if (!cr6.gt) goto loc_8277EBC0;
	// mr r23,r11
	r23.u64 = r11.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_8277EB5C:
	// lwz r29,0(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277eba8
	if (cr6.eq) goto loc_8277EBA8;
loc_8277EB70:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r25
	ctr.u64 = r25.u64;
	// bctrl 
	ctx.lr = 0x8277EB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,128
	r29.s64 = r29.s64 + 128;
	// add r28,r28,r10
	r28.u64 = r28.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8277eb70
	if (cr6.lt) goto loc_8277EB70;
loc_8277EBA8:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r10,r26
	r26.u64 = ctx.r10.u64 + r26.u64;
	// bne 0x8277eb5c
	if (!cr0.eq) goto loc_8277EB5C;
loc_8277EBC0:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r20,r11
	cr6.compare<int32_t>(r20.s32, r11.s32, xer);
	// blt cr6,0x8277eacc
	if (cr6.lt) goto loc_8277EACC;
loc_8277EBDC:
	// lwz r11,136(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// lwz r10,284(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,136(r27)
	PPC_STORE_U32(r27.u32 + 136, r11.u32);
	// subfe r11,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8277EC00"))) PPC_WEAK_FUNC(sub_8277EC00);
PPC_FUNC_IMPL(__imp__sub_8277EC00) {
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
	ctx.lr = 0x8277EC08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// lwz r31,392(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ec64
	if (!cr6.eq) goto loc_8277EC64;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r5,r8,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277EC60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
loc_8277EC64:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277ed84
	if (!cr6.gt) goto loc_8277ED84;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r11,76
	ctx.r6.s64 = r11.s64 + 76;
loc_8277EC84:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8277ed90
	if (cr6.lt) goto loc_8277ED90;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed04
	if (cr6.eq) goto loc_8277ED04;
	// li r29,1
	r29.s64 = 1;
loc_8277ED04:
	// li r10,8
	ctx.r10.s64 = 8;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8277ed20
	if (cr6.eq) goto loc_8277ED20;
	// li r29,1
	r29.s64 = 1;
loc_8277ED20:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed38
	if (cr6.eq) goto loc_8277ED38;
	// li r29,1
	r29.s64 = 1;
loc_8277ED38:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed50
	if (cr6.eq) goto loc_8277ED50;
	// li r29,1
	r29.s64 = 1;
loc_8277ED50:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed68
	if (cr6.eq) goto loc_8277ED68;
	// li r29,1
	r29.s64 = 1;
loc_8277ED68:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// addi r8,r8,256
	ctx.r8.s64 = ctx.r8.s64 + 256;
	// addi r6,r6,84
	ctx.r6.s64 = ctx.r6.s64 + 84;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8277ec84
	if (cr6.lt) goto loc_8277EC84;
loc_8277ED84:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277ED90:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277ED9C"))) PPC_WEAK_FUNC(sub_8277ED9C);
PPC_FUNC_IMPL(__imp__sub_8277ED9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277EDA0"))) PPC_WEAK_FUNC(sub_8277EDA0);
PPC_FUNC_IMPL(__imp__sub_8277EDA0) {
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
	ctx.lr = 0x8277EDA8;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r30,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, r30.u32);
	// lwz r10,392(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// lwz r9,132(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lwz r8,124(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// bgt cr6,0x8277ee44
	if (cr6.gt) goto loc_8277EE44;
loc_8277EDDC:
	// lwz r9,400(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 400);
	// lbz r11,17(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ee44
	if (!cr6.eq) goto loc_8277EE44;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277ee1c
	if (!cr6.eq) goto loc_8277EE1C;
	// lwz r10,364(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r7,128(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// rlwinm r10,r8,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bgt cr6,0x8277ee44
	if (cr6.gt) goto loc_8277EE44;
loc_8277EE1C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277EE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277eeb4
	if (cr6.eq) goto loc_8277EEB4;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8277eddc
	if (!cr6.gt) goto loc_8277EDDC;
loc_8277EE44:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r16,196(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277f530
	if (!cr6.gt) goto loc_8277F530;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r14,1
	r14.s64 = 1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r9,r11,72
	ctx.r9.s64 = r11.s64 + 72;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// subfic r8,r11,-72
	xer.ca = r11.u32 <= 4294967224;
	ctx.r8.s64 = -72 - r11.s64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
loc_8277EE7C:
	// lbz r11,48(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f4ec
	if (cr6.eq) goto loc_8277F4EC;
	// lwz r31,468(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// lwz r11,12(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// bge cr6,0x8277eec0
	if (!cr6.lt) goto loc_8277EEC0;
	// mr r28,r11
	r28.u64 = r11.u64;
	// li r30,0
	r30.s64 = 0;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// b 0x8277eeec
	goto loc_8277EEEC;
loc_8277EEB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9210
	return;
loc_8277EEC0:
	// lwz r9,32(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 32);
	// twllei r11,0
	// divwu r8,r9,r11
	ctx.r8.u32 = ctx.r9.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf. r28,r7,r9
	r28.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bne 0x8277eee4
	if (!cr0.eq) goto loc_8277EEE4;
	// mr r28,r11
	r28.u64 = r11.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8277EEE4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r30,r14
	r30.u64 = r14.u64;
loc_8277EEEC:
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x8277ef38
	if (cr6.eq) goto loc_8277EF38;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// add r6,r11,r6
	ctx.r6.u64 = r11.u64 + ctx.r6.u64;
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,32(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277EF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// b 0x8277ef58
	goto loc_8277EF58;
loc_8277EF38:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EF50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
loc_8277EF58:
	// lwz r11,412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,76(r16)
	ctx.r7.u64 = PPC_LOAD_U32(r16.u32 + 76);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,112(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// add r5,r10,r3
	ctx.r5.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 16);
	// lhz r3,32(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 32);
	// lhz r10,18(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 18);
	// lhz r31,4(r7)
	r31.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lhz r15,0(r7)
	r15.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r4,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r4.u32);
	// ble cr6,0x8277f4ec
	if (!cr6.gt) goto loc_8277F4EC;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
loc_8277EFE0:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,132(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,148(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r19,0(r11)
	r19.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8277f00c
	if (cr6.eq) goto loc_8277F00C;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// beq cr6,0x8277f010
	if (cr6.eq) goto loc_8277F010;
loc_8277F00C:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
loc_8277F010:
	// lwz r8,140(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277f034
	if (cr6.eq) goto loc_8277F034;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bne cr6,0x8277f034
	if (!cr6.eq) goto loc_8277F034;
	// mr r11,r19
	r11.u64 = r19.u64;
	// b 0x8277f038
	goto loc_8277F038;
loc_8277F034:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277F038:
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// li r20,0
	r20.s64 = 0;
	// lhz r8,0(r19)
	ctx.r8.u64 = PPC_LOAD_U16(r19.u32 + 0);
	// li r21,0
	r21.s64 = 0;
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r25,r10
	r25.s64 = ctx.r10.s16;
	// lwz r10,28(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 28);
	// extsh r28,r8
	r28.s64 = ctx.r8.s16;
	// extsh r24,r7
	r24.s64 = ctx.r7.s16;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r27,r28
	r27.u64 = r28.u64;
	// mr r29,r24
	r29.u64 = r24.u64;
	// addi r31,r10,-1
	r31.s64 = ctx.r10.s64 + -1;
	// addi r17,r11,128
	r17.s64 = r11.s64 + 128;
	// addi r18,r9,128
	r18.s64 = ctx.r9.s64 + 128;
loc_8277F080:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8277a3d0
	ctx.lr = 0x8277F090;
	sub_8277A3D0(ctx, base);
	// cmplw cr6,r21,r31
	cr6.compare<uint32_t>(r21.u32, r31.u32, xer);
	// bge cr6,0x8277f0b0
	if (!cr6.lt) goto loc_8277F0B0;
	// lhz r11,0(r18)
	r11.u64 = PPC_LOAD_U16(r18.u32 + 0);
	// lhz r10,128(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 128);
	// lhz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U16(r17.u32 + 0);
	// extsh r25,r11
	r25.s64 = r11.s16;
	// extsh r28,r10
	r28.s64 = ctx.r10.s16;
	// extsh r24,r9
	r24.s64 = ctx.r9.s16;
loc_8277F0B0:
	// lwz r7,144(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277f174
	if (cr6.eq) goto loc_8277F174;
	// lhz r11,162(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 162);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f174
	if (!cr6.eq) goto loc_8277F174;
	// subf r11,r28,r27
	r11.s64 = r27.s64 - r28.s64;
	// mullw r11,r11,r15
	r11.s64 = int64_t(r11.s32) * int64_t(r15.s32);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277f12c
	if (cr6.lt) goto loc_8277F12C;
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r8,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f170
	if (!cr6.gt) goto loc_8277F170;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f170
	if (cr6.lt) goto loc_8277F170;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f170
	goto loc_8277F170;
loc_8277F12C:
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f16c
	if (!cr6.gt) goto loc_8277F16C;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f16c
	if (cr6.lt) goto loc_8277F16C;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F16C:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F170:
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
loc_8277F174:
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277f234
	if (cr6.eq) goto loc_8277F234;
	// lhz r11,176(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f234
	if (!cr6.eq) goto loc_8277F234;
	// subf r11,r22,r23
	r11.s64 = r23.s64 - r22.s64;
	// mullw r11,r11,r15
	r11.s64 = int64_t(r11.s32) * int64_t(r15.s32);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277f1ec
	if (cr6.lt) goto loc_8277F1EC;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r8,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f230
	if (!cr6.gt) goto loc_8277F230;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f230
	if (cr6.lt) goto loc_8277F230;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f230
	goto loc_8277F230;
loc_8277F1EC:
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f22c
	if (!cr6.gt) goto loc_8277F22C;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f22c
	if (cr6.lt) goto loc_8277F22C;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F22C:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F230:
	// sth r11,176(r1)
	PPC_STORE_U16(ctx.r1.u32 + 176, r11.u16);
loc_8277F234:
	// lwz r9,12(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f2f0
	if (cr6.eq) goto loc_8277F2F0;
	// lhz r11,192(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f2f0
	if (!cr6.eq) goto loc_8277F2F0;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r11,r22
	r11.s64 = r22.s64 - r11.s64;
	// add r10,r11,r23
	ctx.r10.u64 = r11.u64 + r23.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f2ac
	if (cr0.lt) goto loc_8277F2AC;
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f2ec
	if (!cr6.gt) goto loc_8277F2EC;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f2ec
	if (cr6.lt) goto loc_8277F2EC;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f2ec
	goto loc_8277F2EC;
loc_8277F2AC:
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f2e8
	if (!cr6.gt) goto loc_8277F2E8;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f2e8
	if (cr6.lt) goto loc_8277F2E8;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F2E8:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F2EC:
	// sth r11,192(r1)
	PPC_STORE_U16(ctx.r1.u32 + 192, r11.u16);
loc_8277F2F0:
	// lwz r9,16(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f3ac
	if (cr6.eq) goto loc_8277F3AC;
	// lhz r11,178(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 178);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f3ac
	if (!cr6.eq) goto loc_8277F3AC;
	// subf r11,r29,r24
	r11.s64 = r24.s64 - r29.s64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r25,r11
	r11.s64 = r11.s64 - r25.s64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f368
	if (cr0.lt) goto loc_8277F368;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f3a8
	if (!cr6.gt) goto loc_8277F3A8;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f3a8
	if (cr6.lt) goto loc_8277F3A8;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f3a8
	goto loc_8277F3A8;
loc_8277F368:
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f3a4
	if (!cr6.gt) goto loc_8277F3A4;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f3a4
	if (cr6.lt) goto loc_8277F3A4;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F3A4:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F3A8:
	// sth r11,178(r1)
	PPC_STORE_U16(ctx.r1.u32 + 178, r11.u16);
loc_8277F3AC:
	// lwz r9,20(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f468
	if (cr6.eq) goto loc_8277F468;
	// lhz r11,164(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f468
	if (!cr6.eq) goto loc_8277F468;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f424
	if (cr0.lt) goto loc_8277F424;
	// lwz r8,124(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r11,r7,r8
	r11.s32 = ctx.r7.s32 / ctx.r8.s32;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// andc r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r6.u64;
	// twlgei r5,-1
	// ble cr6,0x8277f464
	if (!cr6.gt) goto loc_8277F464;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f464
	if (cr6.lt) goto loc_8277F464;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f464
	goto loc_8277F464;
loc_8277F424:
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r7,r10,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// twllei r7,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r7
	r11.s32 = ctx.r6.s32 / ctx.r7.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r7,r5
	ctx.r4.u64 = ctx.r7.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f460
	if (!cr6.gt) goto loc_8277F460;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f460
	if (cr6.lt) goto loc_8277F460;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F460:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F464:
	// sth r11,164(r1)
	PPC_STORE_U16(ctx.r1.u32 + 164, r11.u16);
loc_8277F468:
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277F488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 36);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// mr r30,r23
	r30.u64 = r23.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// addi r19,r19,128
	r19.s64 = r19.s64 + 128;
	// addi r18,r18,128
	r18.s64 = r18.s64 + 128;
	// addi r17,r17,128
	r17.s64 = r17.s64 + 128;
	// cmplw cr6,r21,r31
	cr6.compare<uint32_t>(r21.u32, r31.u32, xer);
	// add r20,r20,r11
	r20.u64 = r20.u64 + r11.u64;
	// ble cr6,0x8277f080
	if (!cr6.gt) goto loc_8277F080;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// blt cr6,0x8277efe0
	if (cr6.lt) goto loc_8277EFE0;
loc_8277F4EC:
	// lwz r10,468(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// addi r16,r16,84
	r16.s64 = r16.s64 + 84;
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r5,r8,24
	ctx.r5.s64 = ctx.r8.s64 + 24;
	// lwz r4,36(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// addi r3,r7,4
	ctx.r3.s64 = ctx.r7.s64 + 4;
	// addi r10,r6,4
	ctx.r10.s64 = ctx.r6.s64 + 4;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// blt cr6,0x8277ee7c
	if (cr6.lt) goto loc_8277EE7C;
loc_8277F530:
	// lwz r10,468(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r11,136(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r9,284(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subfc r8,r9,r11
	xer.ca = r11.u32 >= ctx.r9.u32;
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// stw r11,136(r10)
	PPC_STORE_U32(ctx.r10.u32 + 136, r11.u32);
	// subfe r11,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8277F558"))) PPC_WEAK_FUNC(sub_8277F558);
PPC_FUNC_IMPL(__imp__sub_8277F558) {
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
	// lwz r30,392(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5cc
	if (cr6.eq) goto loc_8277F5CC;
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5b4
	if (cr6.eq) goto loc_8277F5B4;
	// bl 0x8277ec00
	ctx.lr = 0x8277F590;
	sub_8277EC00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5b4
	if (cr6.eq) goto loc_8277F5B4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-4704
	ctx.r9.s64 = r11.s64 + -4704;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// b 0x8277f5d4
	goto loc_8277F5D4;
loc_8277F5B4:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-5560
	ctx.r9.s64 = r11.s64 + -5560;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// b 0x8277f5d4
	goto loc_8277F5D4;
loc_8277F5CC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_8277F5D4:
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

__attribute__((alias("__imp__sub_8277F5EC"))) PPC_WEAK_FUNC(sub_8277F5EC);
PPC_FUNC_IMPL(__imp__sub_8277F5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277F5F0"))) PPC_WEAK_FUNC(sub_8277F5F0);
PPC_FUNC_IMPL(__imp__sub_8277F5F0) {
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
	ctx.lr = 0x8277F5F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,116
	ctx.r5.s64 = 116;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F61C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r29,392(r30)
	PPC_STORE_U32(r30.u32 + 392, r29.u32);
	// li r26,0
	r26.s64 = 0;
	// addi r7,r9,-6856
	ctx.r7.s64 = ctx.r9.s64 + -6856;
	// addi r6,r8,-2728
	ctx.r6.s64 = ctx.r8.s64 + -2728;
	// stw r26,112(r29)
	PPC_STORE_U32(r29.u32 + 112, r26.u32);
	// clrlwi r5,r31,24
	ctx.r5.u64 = r31.u32 & 0xFF;
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// stw r6,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r6.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8277f708
	if (cr6.eq) goto loc_8277F708;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277f6e0
	if (!cr6.gt) goto loc_8277F6E0;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
	// addi r27,r29,72
	r27.s64 = r29.s64 + 72;
loc_8277F668:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f684
	if (cr6.eq) goto loc_8277F684;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r28,r28,r11
	r28.u64 = r28.u64 + r11.u64;
loc_8277F684:
	// lwz r25,4(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8277a348
	ctx.lr = 0x8277F690;
	sub_8277A348(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8277a348
	ctx.lr = 0x8277F6A0;
	sub_8277A348(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,20(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277F6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f668
	if (cr6.lt) goto loc_8277F668;
loc_8277F6E0:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,-6184
	ctx.r9.s64 = r11.s64 + -6184;
	// addi r8,r10,-5560
	ctx.r8.s64 = ctx.r10.s64 + -5560;
	// addi r7,r29,72
	ctx.r7.s64 = r29.s64 + 72;
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// stw r7,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8277F708:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1280
	ctx.r5.s64 = 1280;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r3,128
	ctx.r7.s64 = ctx.r3.s64 + 128;
	// addi r6,r3,256
	ctx.r6.s64 = ctx.r3.s64 + 256;
	// stw r3,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r3.u32);
	// addi r5,r3,384
	ctx.r5.s64 = ctx.r3.s64 + 384;
	// stw r7,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r7.u32);
	// addi r4,r3,512
	ctx.r4.s64 = ctx.r3.s64 + 512;
	// stw r6,40(r29)
	PPC_STORE_U32(r29.u32 + 40, ctx.r6.u32);
	// lis r9,-32230
	ctx.r9.s64 = -2112225280;
	// stw r5,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r5.u32);
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r4,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r4.u32);
	// addi r11,r3,640
	r11.s64 = ctx.r3.s64 + 640;
	// addi r10,r3,768
	ctx.r10.s64 = ctx.r3.s64 + 768;
	// addi r7,r3,896
	ctx.r7.s64 = ctx.r3.s64 + 896;
	// stw r11,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r11.u32);
	// addi r6,r3,1024
	ctx.r6.s64 = ctx.r3.s64 + 1024;
	// stw r10,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r10.u32);
	// addi r5,r3,1152
	ctx.r5.s64 = ctx.r3.s64 + 1152;
	// stw r7,60(r29)
	PPC_STORE_U32(r29.u32 + 60, ctx.r7.u32);
	// addi r4,r9,23744
	ctx.r4.s64 = ctx.r9.s64 + 23744;
	// stw r6,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r6.u32);
	// addi r3,r8,-6840
	ctx.r3.s64 = ctx.r8.s64 + -6840;
	// stw r5,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r5.u32);
	// stw r4,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r4.u32);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
	// stw r26,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r26.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8277F794"))) PPC_WEAK_FUNC(sub_8277F794);
PPC_FUNC_IMPL(__imp__sub_8277F794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277F798"))) PPC_WEAK_FUNC(sub_8277F798);
PPC_FUNC_IMPL(__imp__sub_8277F798) {
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
	ctx.lr = 0x8277F7A0;
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r28,50
	r28.s64 = 50;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277f7c8
	if (cr6.lt) goto loc_8277F7C8;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x8277f7ec
	if (cr6.lt) goto loc_8277F7EC;
loc_8277F7C8:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277F7EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F7EC:
	// clrlwi r22,r30,24
	r22.u64 = r30.u32 & 0xFF;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x8277f800
	if (!cr6.eq) goto loc_8277F800;
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
loc_8277F800:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r10,r25
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8277f834
	if (!cr6.eq) goto loc_8277F834;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277F834;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F834:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f860
	if (!cr6.eq) goto loc_8277F860;
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// li r5,1424
	ctx.r5.s64 = 1424;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F85C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8277F860:
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r26,1
	r26.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r26
	r30.u64 = r26.u64;
	// li r23,8
	r23.s64 = 8;
	// stw r27,140(r28)
	PPC_STORE_U32(r28.u32 + 140, r27.u32);
loc_8277F878:
	// lbzx r31,r30,r27
	r31.u64 = PPC_LOAD_U8(r30.u32 + r27.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277f890
	if (cr6.lt) goto loc_8277F890;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x8277f8ac
	if (!cr6.gt) goto loc_8277F8AC;
loc_8277F890:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277F8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F8AC:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8277f8dc
	if (cr6.eq) goto loc_8277F8DC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// extsb r10,r30
	ctx.r10.s64 = r30.s8;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277f8d8
	if (cr6.eq) goto loc_8277F8D8;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_8277F8CC:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8277f8cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277F8CC;
loc_8277F8D8:
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
loc_8277F8DC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// ble cr6,0x8277f878
	if (!cr6.gt) goto loc_8277F878;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r24,r29
	r24.u64 = r29.u64;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// stbx r10,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, ctx.r10.u8);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r29,r9
	r29.s64 = ctx.r9.s8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8277f998
	if (cr6.eq) goto loc_8277F998;
loc_8277F910:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// bne cr6,0x8277f958
	if (!cr6.eq) goto loc_8277F958;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8277F934:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x8277f934
	if (cr6.eq) goto loc_8277F934;
loc_8277F958:
	// slw r11,r26,r29
	r11.u64 = r29.u8 & 0x20 ? 0 : (r26.u32 << (r29.u8 & 0x3F));
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277f980
	if (cr6.lt) goto loc_8277F980;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277F980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F980:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277f910
	if (!cr6.eq) goto loc_8277F910;
loc_8277F998:
	// li r11,0
	r11.s64 = 0;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// addi r10,r28,4
	ctx.r10.s64 = r28.s64 + 4;
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8277F9A8:
	// lbzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r27.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277f9e8
	if (cr6.eq) goto loc_8277F9E8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lwzx r4,r8,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// subf r3,r4,r11
	ctx.r3.s64 = r11.s64 - ctx.r4.s64;
	// stw r3,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r3.u32);
	// lbzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r27.u32);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// b 0x8277f9ec
	goto loc_8277F9EC;
loc_8277F9E8:
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_8277F9EC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// ble cr6,0x8277f9a8
	if (!cr6.gt) goto loc_8277F9A8;
	// lis r11,15
	r11.s64 = 983040;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r28,144
	ctx.r3.s64 = r28.s64 + 144;
	// stw r10,68(r28)
	PPC_STORE_U32(r28.u32 + 68, ctx.r10.u32);
	// bl 0x823d9890
	ctx.lr = 0x8277FA18;
	sub_823D9890(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r30,7
	r30.s64 = 7;
loc_8277FA24:
	// lbzx r11,r5,r27
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277faac
	if (cr6.lt) goto loc_8277FAAC;
	// add r11,r4,r27
	r11.u64 = ctx.r4.u64 + r27.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// slw r31,r26,r30
	r31.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// addi r8,r11,17
	ctx.r8.s64 = r11.s64 + 17;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8277FA4C:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// slw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// ble cr6,0x8277fa90
	if (!cr6.gt) goto loc_8277FA90;
	// addi r10,r11,36
	ctx.r10.s64 = r11.s64 + 36;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1168
	ctx.r10.s64 = r11.s64 + 1168;
	// add r11,r7,r28
	r11.u64 = ctx.r7.u64 + r28.u64;
loc_8277FA74:
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bgt 0x8277fa74
	if (cr0.gt) goto loc_8277FA74;
loc_8277FA90:
	// lbzx r11,r5,r27
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + r27.u32);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// ble cr6,0x8277fa4c
	if (!cr6.gt) goto loc_8277FA4C;
loc_8277FAAC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// bge 0x8277fa24
	if (!cr0.lt) goto loc_8277FA24;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8277fb0c
	if (cr6.eq) goto loc_8277FB0C;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8277fb0c
	if (!cr6.gt) goto loc_8277FB0C;
	// addi r30,r27,17
	r30.s64 = r27.s64 + 17;
loc_8277FAD0:
	// lbzx r11,r30,r31
	r11.u64 = PPC_LOAD_U8(r30.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277fae4
	if (cr6.lt) goto loc_8277FAE4;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// ble cr6,0x8277fb00
	if (!cr6.gt) goto loc_8277FB00;
loc_8277FAE4:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277FB00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277FB00:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r24
	cr6.compare<int32_t>(r31.s32, r24.s32, xer);
	// blt cr6,0x8277fad0
	if (cr6.lt) goto loc_8277FAD0;
loc_8277FB0C:
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8277FB14"))) PPC_WEAK_FUNC(sub_8277FB14);
PPC_FUNC_IMPL(__imp__sub_8277FB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277FB18"))) PPC_WEAK_FUNC(sub_8277FB18);
PPC_FUNC_IMPL(__imp__sub_8277FB18) {
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
	ctx.lr = 0x8277FB20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r29,16(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,380(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277fc18
	if (!cr6.eq) goto loc_8277FC18;
	// cmpwi cr6,r28,25
	cr6.compare<int32_t>(r28.s32, 25, xer);
	// bge cr6,0x8277fc6c
	if (!cr6.lt) goto loc_8277FC6C;
loc_8277FB54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277fb88
	if (!cr6.eq) goto loc_8277FB88;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277FB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277fc08
	if (cr6.eq) goto loc_8277FC08;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277FB88:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// bne cr6,0x8277fbf0
	if (!cr6.eq) goto loc_8277FBF0;
loc_8277FB9C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277fbd0
	if (!cr6.eq) goto loc_8277FBD0;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277FBB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277fc08
	if (cr6.eq) goto loc_8277FC08;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277FBD0:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x8277fb9c
	if (cr6.eq) goto loc_8277FB9C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277fc14
	if (!cr6.eq) goto loc_8277FC14;
	// li r11,255
	r11.s64 = 255;
loc_8277FBF0:
	// rlwinm r10,r26,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFFFFFF00;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// or r26,r10,r11
	r26.u64 = ctx.r10.u64 | r11.u64;
	// cmpwi cr6,r28,25
	cr6.compare<int32_t>(r28.s32, 25, xer);
	// blt cr6,0x8277fb54
	if (cr6.lt) goto loc_8277FB54;
	// b 0x8277fc6c
	goto loc_8277FC6C;
loc_8277FC08:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8277FC14:
	// stw r11,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r11.u32);
loc_8277FC18:
	// cmpw cr6,r25,r28
	cr6.compare<int32_t>(r25.s32, r28.s32, xer);
	// ble cr6,0x8277fc6c
	if (!cr6.gt) goto loc_8277FC6C;
	// lwz r11,408(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277fc60
	if (!cr6.eq) goto loc_8277FC60;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,117
	ctx.r10.s64 = 117;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277FC54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,408(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,8(r6)
	PPC_STORE_U8(ctx.r6.u32 + 8, ctx.r7.u8);
loc_8277FC60:
	// subfic r11,r28,25
	xer.ca = r28.u32 <= 25;
	r11.s64 = 25 - r28.s64;
	// li r28,25
	r28.s64 = 25;
	// slw r26,r26,r11
	r26.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
loc_8277FC6C:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// stw r26,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r26.u32);
	// stw r28,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277FC88"))) PPC_WEAK_FUNC(sub_8277FC88);
PPC_FUNC_IMPL(__imp__sub_8277FC88) {
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
	ctx.lr = 0x8277FC90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8277fcd0
	if (!cr6.lt) goto loc_8277FCD0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x8277fb18
	ctx.lr = 0x8277FCB0;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277fcc8
	if (!cr6.eq) goto loc_8277FCC8;
loc_8277FCBC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277FCC8:
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_8277FCD0:
	// li r11,1
	r11.s64 = 1;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// lwzx r9,r10,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// sraw r7,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r7.s64 = ctx.r4.s32 >> temp.u32;
	// and r11,r7,r8
	r11.u64 = ctx.r7.u64 & ctx.r8.u64;
	// add r30,r10,r27
	r30.u64 = ctx.r10.u64 + r27.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x8277fd4c
	if (!cr6.gt) goto loc_8277FD4C;
loc_8277FCFC:
	// rlwinm r28,r11,1,0,30
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bge cr6,0x8277fd28
	if (!cr6.lt) goto loc_8277FD28;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277fb18
	ctx.lr = 0x8277FD14;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fcbc
	if (cr6.eq) goto loc_8277FCBC;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_8277FD28:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// sraw r11,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	r11.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// or r11,r10,r28
	r11.u64 = ctx.r10.u64 | r28.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8277fcfc
	if (cr6.gt) goto loc_8277FCFC;
loc_8277FD4C:
	// stw r4,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r4.u32);
	// cmpwi cr6,r31,16
	cr6.compare<int32_t>(r31.s32, 16, xer);
	// stw r5,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r5.u32);
	// ble cr6,0x8277fd90
	if (!cr6.gt) goto loc_8277FD90;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r10,118
	ctx.r10.s64 = 118;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277FD84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277FD90:
	// addi r10,r31,18
	ctx.r10.s64 = r31.s64 + 18;
	// lwz r9,140(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 140);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r27.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbz r3,17(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 17);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277FDB4"))) PPC_WEAK_FUNC(sub_8277FDB4);
PPC_FUNC_IMPL(__imp__sub_8277FDB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277FDB8"))) PPC_WEAK_FUNC(sub_8277FDB8);
PPC_FUNC_IMPL(__imp__sub_8277FDB8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8277FDC0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// li r25,1
	r25.s64 = 1;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r10,252(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 252);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r24,408(r26)
	r24.u64 = PPC_LOAD_U32(r26.u32 + 408);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// beq cr6,0x8277feac
	if (cr6.eq) goto loc_8277FEAC;
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277feac
	if (!cr6.eq) goto loc_8277FEAC;
	// lwz r10,16(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lwz r11,404(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 404);
	// srawi r9,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r31,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r31.u32);
	// lwz r7,404(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 404);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277FE38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8277fe4c
	if (!cr6.eq) goto loc_8277FE4C;
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x8277fe94
	goto loc_8277FE94;
loc_8277FE4C:
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277fe78
	if (!cr6.gt) goto loc_8277FE78;
	// addi r11,r24,20
	r11.s64 = r24.s64 + 20;
loc_8277FE60:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r9,292(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277fe60
	if (cr6.lt) goto loc_8277FE60;
loc_8277FE78:
	// lwz r11,252(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 252);
	// stw r11,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r11.u32);
	// lwz r10,380(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 380);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8277fe90
	if (!cr6.eq) goto loc_8277FE90;
	// stb r31,8(r24)
	PPC_STORE_U8(r24.u32 + 8, r31.u8);
loc_8277FE90:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8277FE94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277feac
	if (!cr6.eq) goto loc_8277FEAC;
loc_8277FEA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
loc_8277FEAC:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827802cc
	if (!cr6.eq) goto loc_827802CC;
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,20(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r22,r24,20
	r22.s64 = r24.s64 + 20;
	// lwz r8,24(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// mr r19,r31
	r19.u64 = r31.u64;
	// lwz r7,28(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// lwz r6,32(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,320(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// ble cr6,0x82780288
	if (!cr6.gt) goto loc_82780288;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// mr r20,r30
	r20.u64 = r30.u64;
	// addi r21,r26,324
	r21.s64 = r26.s64 + 324;
	// addi r23,r24,112
	r23.s64 = r24.s64 + 112;
	// addi r18,r11,-31424
	r18.s64 = r11.s64 + -31424;
	// addi r27,r10,-31088
	r27.s64 = ctx.r10.s64 + -31088;
loc_8277FF2C:
	// lwz r29,0(r20)
	r29.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// lwz r31,-40(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + -40);
	// lwz r28,0(r23)
	r28.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bge cr6,0x8277ff70
	if (!cr6.lt) goto loc_8277FF70;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8277FF4C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8277ff70
	if (!cr6.lt) goto loc_8277FF70;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x8277ffa4
	goto loc_8277FFA4;
loc_8277FF70:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277ffa0
	if (cr6.eq) goto loc_8277FFA0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r31,1168(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x8277ffc4
	goto loc_8277FFC4;
loc_8277FFA0:
	// li r7,9
	ctx.r7.s64 = 9;
loc_8277FFA4:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x8277FFB0;
	sub_8277FC88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8277FFC4:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82780024
	if (cr6.eq) goto loc_82780024;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8277fff4
	if (!cr6.lt) goto loc_8277FFF4;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8277FFE0;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8277FFF4:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// slw r10,r25,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r25.u32 << (r31.u8 & 0x3F));
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// and r31,r10,r9
	r31.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// bge cr6,0x82780024
	if (!cr6.lt) goto loc_82780024;
	// addi r10,r27,64
	ctx.r10.s64 = r27.s64 + 64;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82780024:
	// add r11,r19,r24
	r11.u64 = r19.u64 + r24.u64;
	// lbz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780050
	if (cr6.eq) goto loc_82780050;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
loc_82780050:
	// add r11,r19,r24
	r11.u64 = r19.u64 + r24.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lbz r10,162(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 162);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780188
	if (cr6.eq) goto loc_82780188;
loc_82780064:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8278009c
	if (!cr6.lt) goto loc_8278009C;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780078;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8278009c
	if (!cr6.lt) goto loc_8278009C;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x827800d0
	goto loc_827800D0;
loc_8278009C:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827800cc
	if (cr6.eq) goto loc_827800CC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x827800ec
	goto loc_827800EC;
loc_827800CC:
	// li r7,9
	ctx.r7.s64 = 9;
loc_827800D0:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x827800DC;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_827800EC:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8278016c
	if (cr6.eq) goto loc_8278016C;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x82780128
	if (!cr6.lt) goto loc_82780128;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780114;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780128:
	// slw r11,r25,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r25.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// and r11,r11,r9
	r11.u64 = r11.u64 & ctx.r9.u64;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x82780158
	if (!cr6.lt) goto loc_82780158;
	// addi r9,r27,64
	ctx.r9.s64 = r27.s64 + 64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_82780158:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r18
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r18.u32);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r7,r29
	PPC_STORE_U16(ctx.r7.u32 + r29.u32, r11.u16);
	// b 0x82780178
	goto loc_82780178;
loc_8278016C:
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x8278026c
	if (!cr6.eq) goto loc_8278026C;
	// addi r30,r30,15
	r30.s64 = r30.s64 + 15;
loc_82780178:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// blt cr6,0x82780064
	if (cr6.lt) goto loc_82780064;
	// b 0x8278026c
	goto loc_8278026C;
loc_82780188:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827801c0
	if (!cr6.lt) goto loc_827801C0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8278019C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827801c0
	if (!cr6.lt) goto loc_827801C0;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x827801f4
	goto loc_827801F4;
loc_827801C0:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827801f0
	if (cr6.eq) goto loc_827801F0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780210
	goto loc_82780210;
loc_827801F0:
	// li r7,9
	ctx.r7.s64 = 9;
loc_827801F4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x82780200;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780210:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82780254
	if (cr6.eq) goto loc_82780254;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8278024c
	if (!cr6.lt) goto loc_8278024C;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780238;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8278024C:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// b 0x82780260
	goto loc_82780260;
loc_82780254:
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x8278026c
	if (!cr6.eq) goto loc_8278026C;
	// addi r30,r30,15
	r30.s64 = r30.s64 + 15;
loc_82780260:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// blt cr6,0x82780188
	if (cr6.lt) goto loc_82780188;
loc_8278026C:
	// lwz r11,320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// cmpw cr6,r19,r11
	cr6.compare<int32_t>(r19.s32, r11.s32, xer);
	// blt cr6,0x8277ff2c
	if (cr6.lt) goto loc_8277FF2C;
loc_82780288:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
	// stw r7,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r7.u32);
	// stw r6,4(r22)
	PPC_STORE_U32(r22.u32 + 4, ctx.r6.u32);
	// stw r3,8(r22)
	PPC_STORE_U32(r22.u32 + 8, ctx.r3.u32);
	// stw r11,12(r22)
	PPC_STORE_U32(r22.u32 + 12, r11.u32);
loc_827802CC:
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_827802E4"))) PPC_WEAK_FUNC(sub_827802E4);
PPC_FUNC_IMPL(__imp__sub_827802E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827802E8"))) PPC_WEAK_FUNC(sub_827802E8);
PPC_FUNC_IMPL(__imp__sub_827802E8) {
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
	ctx.lr = 0x827802F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpwi cr6,r11,63
	cr6.compare<int32_t>(r11.s32, 63, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82780350
	if (cr6.eq) goto loc_82780350;
loc_8278032C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,122
	ctx.r10.s64 = 122;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82780350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82780350:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// li r25,0
	r25.s64 = 0;
	// mr r26,r25
	r26.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827803c8
	if (!cr6.gt) goto loc_827803C8;
	// addi r28,r30,20
	r28.s64 = r30.s64 + 20;
	// addi r29,r31,296
	r29.s64 = r31.s64 + 296;
loc_8278036C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r27,24(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r10,r5,10
	ctx.r10.s64 = ctx.r5.s64 + 10;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// bl 0x8277f798
	ctx.lr = 0x82780390;
	sub_8277F798(ctx, base);
	// addi r9,r27,14
	ctx.r9.s64 = r27.s64 + 14;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277f798
	ctx.lr = 0x827803AC;
	sub_8277F798(ctx, base);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r8,292(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x8278036c
	if (cr6.lt) goto loc_8278036C;
loc_827803C8:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82780470
	if (!cr6.gt) goto loc_82780470;
	// addi r8,r30,152
	ctx.r8.s64 = r30.s64 + 152;
	// addi r10,r30,112
	ctx.r10.s64 = r30.s64 + 112;
	// addi r7,r31,324
	ctx.r7.s64 = r31.s64 + 324;
	// subfic r6,r30,-152
	xer.ca = r30.u32 <= 4294967144;
	ctx.r6.s64 = -152 - r30.s64;
	// li r5,1
	ctx.r5.s64 = 1;
loc_827803E8:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,74
	r11.s64 = r11.s64 + 74;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r9,10
	ctx.r4.s64 = ctx.r9.s64 + 10;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r30.u32);
	// stw r9,-40(r10)
	PPC_STORE_U32(ctx.r10.u32 + -40, ctx.r9.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r4,r9,14
	ctx.r4.s64 = ctx.r9.s64 + 14;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r30.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lbz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8278044c
	if (cr6.eq) goto loc_8278044C;
	// stb r5,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r5.u8);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// bgt cr6,0x82780444
	if (cr6.gt) goto loc_82780444;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82780444:
	// stb r11,10(r8)
	PPC_STORE_U8(ctx.r8.u32 + 10, r11.u8);
	// b 0x82780454
	goto loc_82780454;
loc_8278044C:
	// stb r25,10(r8)
	PPC_STORE_U8(ctx.r8.u32 + 10, r25.u8);
	// stb r25,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r25.u8);
loc_82780454:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x827803e8
	if (cr6.lt) goto loc_827803E8;
loc_82780470:
	// stw r25,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r25.u32);
	// stb r25,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r25.u8);
	// stw r25,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r25.u32);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8278048C"))) PPC_WEAK_FUNC(sub_8278048C);
PPC_FUNC_IMPL(__imp__sub_8278048C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82780490"))) PPC_WEAK_FUNC(sub_82780490);
PPC_FUNC_IMPL(__imp__sub_82780490) {
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
	// li r5,172
	ctx.r5.s64 = 172;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827804BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// addi r7,r9,744
	ctx.r7.s64 = ctx.r9.s64 + 744;
	// addi r6,r8,-584
	ctx.r6.s64 = ctx.r8.s64 + -584;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r11,r3,40
	r11.s64 = ctx.r3.s64 + 40;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_827804E4:
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827804e4
	if (!cr0.eq) goto loc_827804E4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8278050C"))) PPC_WEAK_FUNC(sub_8278050C);
PPC_FUNC_IMPL(__imp__sub_8278050C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82780510"))) PPC_WEAK_FUNC(sub_82780510);
PPC_FUNC_IMPL(__imp__sub_82780510) {
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
	ctx.lr = 0x82780518;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srawi r8,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 3;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// lwz r6,404(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82780558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82780570
	if (!cr6.eq) goto loc_82780570;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82780570:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278059c
	if (!cr6.gt) goto loc_8278059C;
	// addi r11,r30,24
	r11.s64 = r30.s64 + 24;
loc_82780584:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// lwz r9,292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82780584
	if (cr6.lt) goto loc_82780584;
loc_8278059C:
	// stw r29,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r29.u32);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827805b8
	if (!cr6.eq) goto loc_827805B8;
	// stb r29,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r29.u8);
loc_827805B8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827805C4"))) PPC_WEAK_FUNC(sub_827805C4);
PPC_FUNC_IMPL(__imp__sub_827805C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827805C8"))) PPC_WEAK_FUNC(sub_827805C8);
PPC_FUNC_IMPL(__imp__sub_827805C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x827805D0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// lwz r24,408(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r21,376(r30)
	r21.u64 = PPC_LOAD_U32(r30.u32 + 376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780618
	if (cr6.eq) goto loc_82780618;
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780618
	if (!cr6.eq) goto loc_82780618;
	// bl 0x82780510
	ctx.lr = 0x82780600;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780618
	if (!cr6.eq) goto loc_82780618;
loc_8278060C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
loc_82780618:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780818
	if (!cr6.eq) goto loc_82780818;
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r20,r24,20
	r20.s64 = r24.s64 + 20;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r20
	r11.u64 = r20.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82780658:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82780658
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82780658;
	// lwz r11,320(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827807d4
	if (!cr6.gt) goto loc_827807D4;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r29,r31
	r29.u64 = r31.u64;
	// addi r28,r30,324
	r28.s64 = r30.s64 + 324;
	// li r22,1
	r22.s64 = 1;
	// addi r23,r11,-30960
	r23.s64 = r11.s64 + -30960;
loc_82780690:
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// lwz r25,0(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r27,74
	r11.s64 = r27.s64 + 74;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r7,r24
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r24.u32);
	// bge cr6,0x827806ec
	if (!cr6.lt) goto loc_827806EC;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x827806C8;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278060c
	if (cr6.eq) goto loc_8278060C;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827806ec
	if (!cr6.lt) goto loc_827806EC;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// b 0x82780720
	goto loc_82780720;
loc_827806EC:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8278071c
	if (cr6.eq) goto loc_8278071C;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r31,1168(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780740
	goto loc_82780740;
loc_8278071C:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780720:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fc88
	ctx.lr = 0x8278072C;
	sub_8277FC88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8278060c
	if (cr6.lt) goto loc_8278060C;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780740:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827807a0
	if (cr6.eq) goto loc_827807A0;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x82780770
	if (!cr6.lt) goto loc_82780770;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x8278075C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278060c
	if (cr6.eq) goto loc_8278060C;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780770:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// slw r10,r22,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r22.u32 << (r31.u8 & 0x3F));
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r11,r23
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r23.u32);
	// and r31,r10,r9
	r31.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// bge cr6,0x827807a0
	if (!cr6.lt) goto loc_827807A0;
	// addi r10,r23,64
	ctx.r10.s64 = r23.s64 + 64;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_827807A0:
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// slw r8,r11,r21
	ctx.r8.u64 = r21.u8 & 0x20 ? 0 : (r11.u32 << (r21.u8 & 0x3F));
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// sth r8,0(r25)
	PPC_STORE_U16(r25.u32 + 0, ctx.r8.u16);
	// lwz r6,320(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// cmpw cr6,r26,r6
	cr6.compare<int32_t>(r26.s32, ctx.r6.s32, xer);
	// blt cr6,0x82780690
	if (cr6.lt) goto loc_82780690;
loc_827807D4:
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r3,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82780804:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82780804
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82780804;
loc_82780818:
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82780830"))) PPC_WEAK_FUNC(sub_82780830);
PPC_FUNC_IMPL(__imp__sub_82780830) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82780838;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,252(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 252);
	// lwz r24,408(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 408);
	// lwz r21,368(r25)
	r21.u64 = PPC_LOAD_U32(r25.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r20,376(r25)
	r20.u64 = PPC_LOAD_U32(r25.u32 + 376);
	// beq cr6,0x82780884
	if (cr6.eq) goto loc_82780884;
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780884
	if (!cr6.eq) goto loc_82780884;
	// bl 0x82780510
	ctx.lr = 0x8278086C;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780884
	if (!cr6.eq) goto loc_82780884;
loc_82780878:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
loc_82780884:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780a84
	if (!cr6.eq) goto loc_82780A84;
	// lwz r19,20(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x827808a4
	if (cr6.eq) goto loc_827808A4;
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
	// b 0x82780a80
	goto loc_82780A80;
loc_827808A4:
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// lwz r29,364(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 364);
	// lwz r22,0(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r29,r21
	cr6.compare<int32_t>(r29.s32, r21.s32, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lwz r28,60(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 60);
	// bgt cr6,0x82780a60
	if (cr6.gt) goto loc_82780A60;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r26,1
	r26.s64 = 1;
	// addi r23,r10,-31424
	r23.s64 = ctx.r10.s64 + -31424;
	// addi r27,r11,-30960
	r27.s64 = r11.s64 + -30960;
loc_827808EC:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x82780924
	if (!cr6.lt) goto loc_82780924;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780900;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x82780924
	if (!cr6.lt) goto loc_82780924;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// b 0x82780958
	goto loc_82780958;
loc_82780924:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780954
	if (cr6.eq) goto loc_82780954;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780974
	goto loc_82780974;
loc_82780954:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780958:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fc88
	ctx.lr = 0x82780964;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82780878
	if (cr6.lt) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780974:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r30,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r30.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827809f8
	if (cr6.eq) goto loc_827809F8;
	// add r30,r30,r29
	r30.u64 = r30.u64 + r29.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x827809b0
	if (!cr6.lt) goto loc_827809B0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x8278099C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_827809B0:
	// slw r11,r26,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r26.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// and r11,r11,r9
	r11.u64 = r11.u64 & ctx.r9.u64;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x827809e0
	if (!cr6.lt) goto loc_827809E0;
	// addi r9,r27,64
	ctx.r9.s64 = r27.s64 + 64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_827809E0:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r9,r11,r20
	ctx.r9.u64 = r20.u8 & 0x20 ? 0 : (r11.u32 << (r20.u8 & 0x3F));
	// lwzx r8,r10,r23
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r23.u32);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r6,r22
	PPC_STORE_U16(ctx.r6.u32 + r22.u32, ctx.r9.u16);
	// b 0x82780a04
	goto loc_82780A04;
loc_827809F8:
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// bne cr6,0x82780a14
	if (!cr6.eq) goto loc_82780A14;
	// addi r30,r29,15
	r30.s64 = r29.s64 + 15;
loc_82780A04:
	// addi r29,r30,1
	r29.s64 = r30.s64 + 1;
	// cmpw cr6,r29,r21
	cr6.compare<int32_t>(r29.s32, r21.s32, xer);
	// ble cr6,0x827808ec
	if (!cr6.gt) goto loc_827808EC;
	// b 0x82780a60
	goto loc_82780A60;
loc_82780A14:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// slw r31,r26,r30
	r31.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// beq cr6,0x82780a5c
	if (cr6.eq) goto loc_82780A5C;
	// cmpw cr6,r5,r30
	cr6.compare<int32_t>(ctx.r5.s32, r30.s32, xer);
	// bge cr6,0x82780a48
	if (!cr6.lt) goto loc_82780A48;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780A34;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780A48:
	// subf r5,r30,r5
	ctx.r5.s64 = ctx.r5.s64 - r30.s64;
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// sraw r10,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// and r11,r10,r11
	r11.u64 = ctx.r10.u64 & r11.u64;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82780A5C:
	// addi r19,r31,-1
	r19.s64 = r31.s64 + -1;
loc_82780A60:
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
loc_82780A80:
	// stw r19,20(r24)
	PPC_STORE_U32(r24.u32 + 20, r19.u32);
loc_82780A84:
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82780A9C"))) PPC_WEAK_FUNC(sub_82780A9C);
PPC_FUNC_IMPL(__imp__sub_82780A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82780AA0"))) PPC_WEAK_FUNC(sub_82780AA0);
PPC_FUNC_IMPL(__imp__sub_82780AA0) {
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
	ctx.lr = 0x82780AA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// slw r26,r10,r11
	r26.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82780af8
	if (cr6.eq) goto loc_82780AF8;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780af8
	if (!cr6.eq) goto loc_82780AF8;
	// bl 0x82780510
	ctx.lr = 0x82780AE0;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780af8
	if (!cr6.eq) goto loc_82780AF8;
loc_82780AEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82780AF8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r27,0
	r27.s64 = 0;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// ble cr6,0x82780b88
	if (!cr6.gt) goto loc_82780B88;
loc_82780B28:
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bge cr6,0x82780b54
	if (!cr6.lt) goto loc_82780B54;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780B40;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780aec
	if (cr6.eq) goto loc_82780AEC;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780B54:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// sraw r11,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	r11.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780b74
	if (cr6.eq) goto loc_82780B74;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// or r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 | r26.u64;
	// sth r9,0(r28)
	PPC_STORE_U16(r28.u32 + 0, ctx.r9.u16);
loc_82780B74:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82780b28
	if (cr6.lt) goto loc_82780B28;
loc_82780B88:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r4,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r4.u32);
	// stw r5,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r5.u32);
	// stw r7,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82780BC0"))) PPC_WEAK_FUNC(sub_82780BC0);
PPC_FUNC_IMPL(__imp__sub_82780BC0) {
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
	ctx.lr = 0x82780BC8;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r15,1
	r15.s64 = 1;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,376(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 376);
	// lwz r27,368(r19)
	r27.u64 = PPC_LOAD_U32(r19.u32 + 368);
	// lwz r9,252(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 252);
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// lwz r17,408(r19)
	r17.u64 = PPC_LOAD_U32(r19.u32 + 408);
	// slw r20,r15,r11
	r20.u64 = r11.u8 & 0x20 ? 0 : (r15.u32 << (r11.u8 & 0x3F));
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// beq cr6,0x82780c20
	if (cr6.eq) goto loc_82780C20;
	// lwz r11,40(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780c20
	if (!cr6.eq) goto loc_82780C20;
	// bl 0x82780510
	ctx.lr = 0x82780C14;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781010
	if (cr6.eq) goto loc_82781010;
loc_82780C20:
	// lbz r11,8(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780fc8
	if (!cr6.eq) goto loc_82780FC8;
	// lwz r10,24(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// stw r19,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r19.u32);
	// li r16,0
	r16.s64 = 0;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r21,r11,-31424
	r21.s64 = r11.s64 + -31424;
	// lwz r24,364(r19)
	r24.u64 = PPC_LOAD_U32(r19.u32 + 364);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// lwz r14,20(r17)
	r14.u64 = PPC_LOAD_U32(r17.u32 + 20);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// lwz r25,12(r17)
	r25.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// lwz r30,16(r17)
	r30.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// lwz r23,60(r17)
	r23.u64 = PPC_LOAD_U32(r17.u32 + 60);
	// bne cr6,0x82780ef8
	if (!cr6.eq) goto loc_82780EF8;
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// bgt cr6,0x82780fa4
	if (cr6.gt) goto loc_82780FA4;
	// addi r22,r1,128
	r22.s64 = ctx.r1.s64 + 128;
	// li r18,118
	r18.s64 = 118;
loc_82780C80:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x82780cc4
	if (!cr6.lt) goto loc_82780CC4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780C9C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bge cr6,0x82780cc4
	if (!cr6.lt) goto loc_82780CC4;
	// mr r7,r15
	ctx.r7.u64 = r15.u64;
	// b 0x82780cf8
	goto loc_82780CF8;
loc_82780CC4:
	// addi r11,r30,-8
	r11.s64 = r30.s64 + -8;
	// sraw r10,r25,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	ctx.r10.s64 = r25.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r23.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780cf4
	if (cr6.eq) goto loc_82780CF4;
	// add r11,r11,r23
	r11.u64 = r11.u64 + r23.u64;
	// subf r30,r10,r30
	r30.s64 = r30.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780d1c
	goto loc_82780D1C;
loc_82780CF4:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780CF8:
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x82780D0C;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82780fe0
	if (cr6.lt) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780D1C:
	// clrlwi r27,r3,28
	r27.u64 = ctx.r3.u32 & 0xF;
	// srawi r26,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r26.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82780da8
	if (cr6.eq) goto loc_82780DA8;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// beq cr6,0x82780d54
	if (cr6.eq) goto loc_82780D54;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r18,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r18.u32);
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82780D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82780D54:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780d84
	if (!cr6.lt) goto loc_82780D84;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780D70;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780D84:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780da0
	if (cr6.eq) goto loc_82780DA0;
	// mr r27,r20
	r27.u64 = r20.u64;
	// b 0x82780db0
	goto loc_82780DB0;
loc_82780DA0:
	// lwz r27,116(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x82780db0
	goto loc_82780DB0;
loc_82780DA8:
	// cmpwi cr6,r26,15
	cr6.compare<int32_t>(r26.s32, 15, xer);
	// bne cr6,0x82780e9c
	if (!cr6.eq) goto loc_82780E9C;
loc_82780DB0:
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r21
	r29.u64 = r11.u64 + r21.u64;
loc_82780DB8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780e48
	if (cr6.eq) goto loc_82780E48;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780dfc
	if (!cr6.lt) goto loc_82780DFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780DE8;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780DFC:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780e50
	if (cr6.eq) goto loc_82780E50;
	// lhzx r11,r31,r28
	r11.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// and r9,r10,r20
	ctx.r9.u64 = ctx.r10.u64 & r20.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82780e50
	if (!cr6.eq) goto loc_82780E50;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82780e38
	if (cr6.lt) goto loc_82780E38;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// sthx r11,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, r11.u16);
	// b 0x82780e50
	goto loc_82780E50;
loc_82780E38:
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// sthx r9,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, ctx.r9.u16);
	// b 0x82780e50
	goto loc_82780E50;
loc_82780E48:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82780e64
	if (cr0.lt) goto loc_82780E64;
loc_82780E50:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// ble cr6,0x82780db8
	if (!cr6.gt) goto loc_82780DB8;
loc_82780E64:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82780e88
	if (cr6.eq) goto loc_82780E88;
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
	// lwzx r9,r11,r21
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r21.u32);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r9.u32);
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// sthx r27,r8,r28
	PPC_STORE_U16(ctx.r8.u32 + r28.u32, r27.u16);
loc_82780E88:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// ble cr6,0x82780c80
	if (!cr6.gt) goto loc_82780C80;
	// b 0x82780fa4
	goto loc_82780FA4;
loc_82780E9C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// slw r14,r15,r26
	r14.u64 = r26.u8 & 0x20 ? 0 : (r15.u32 << (r26.u8 & 0x3F));
	// beq cr6,0x82780eec
	if (cr6.eq) goto loc_82780EEC;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// bge cr6,0x82780ed8
	if (!cr6.lt) goto loc_82780ED8;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780EC4;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780ED8:
	// subf r30,r26,r30
	r30.s64 = r30.s64 - r26.s64;
	// addi r11,r14,-1
	r11.s64 = r14.s64 + -1;
	// sraw r10,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	ctx.r10.s64 = r25.s32 >> temp.u32;
	// and r11,r10,r11
	r11.u64 = ctx.r10.u64 & r11.u64;
	// add r14,r11,r14
	r14.u64 = r11.u64 + r14.u64;
loc_82780EEC:
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x82780fa4
	if (cr6.eq) goto loc_82780FA4;
loc_82780EF8:
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// bgt cr6,0x82780fa0
	if (cr6.gt) goto loc_82780FA0;
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r26,116(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// add r29,r11,r21
	r29.u64 = r11.u64 + r21.u64;
loc_82780F0C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780f90
	if (cr6.eq) goto loc_82780F90;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780f50
	if (!cr6.lt) goto loc_82780F50;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780F3C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780F50:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780f90
	if (cr6.eq) goto loc_82780F90;
	// lhzx r11,r31,r28
	r11.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// and r9,r10,r20
	ctx.r9.u64 = ctx.r10.u64 & r20.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82780f90
	if (!cr6.eq) goto loc_82780F90;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82780f88
	if (cr6.lt) goto loc_82780F88;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// b 0x82780f8c
	goto loc_82780F8C;
loc_82780F88:
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
loc_82780F8C:
	// sthx r11,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, r11.u16);
loc_82780F90:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// ble cr6,0x82780f0c
	if (!cr6.gt) goto loc_82780F0C;
loc_82780FA0:
	// addi r14,r14,-1
	r14.s64 = r14.s64 + -1;
loc_82780FA4:
	// lwz r11,24(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r25,12(r17)
	PPC_STORE_U32(r17.u32 + 12, r25.u32);
	// stw r30,16(r17)
	PPC_STORE_U32(r17.u32 + 16, r30.u32);
	// stw r14,20(r17)
	PPC_STORE_U32(r17.u32 + 20, r14.u32);
loc_82780FC8:
	// lwz r11,40(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r17)
	PPC_STORE_U32(r17.u32 + 40, r11.u32);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9210
	return;
loc_82780FE0:
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// ble cr6,0x82781010
	if (!cr6.gt) goto loc_82781010;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// rlwinm r11,r16,2,0,29
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82780FF8:
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// addic. r16,r16,-1
	xer.ca = r16.u32 > 0;
	r16.s64 = r16.s64 + -1;
	cr0.compare<int32_t>(r16.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r8,r28
	PPC_STORE_U16(ctx.r8.u32 + r28.u32, ctx.r10.u16);
	// bgt 0x82780ff8
	if (cr0.gt) goto loc_82780FF8;
loc_82781010:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8278101C"))) PPC_WEAK_FUNC(sub_8278101C);
PPC_FUNC_IMPL(__imp__sub_8278101C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781020"))) PPC_WEAK_FUNC(sub_82781020);
PPC_FUNC_IMPL(__imp__sub_82781020) {
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
	ctx.lr = 0x82781028;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// lwz r10,364(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r24,408(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cntlzw r11,r10
	r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r22,r11
	r22.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// beq cr6,0x82781060
	if (cr6.eq) goto loc_82781060;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// b 0x8278107c
	goto loc_8278107C;
loc_82781060:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x82781070
	if (cr6.gt) goto loc_82781070;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x82781074
	if (cr6.lt) goto loc_82781074;
loc_82781070:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82781074:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
loc_8278107C:
	// beq cr6,0x82781084
	if (cr6.eq) goto loc_82781084;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82781084:
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827810a4
	if (cr6.eq) goto loc_827810A4;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x827810a4
	if (cr6.eq) goto loc_827810A4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827810A4:
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// ble cr6,0x827810b4
	if (!cr6.gt) goto loc_827810B4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827810B4:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781110
	if (cr6.eq) goto loc_82781110;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,16
	ctx.r10.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,364(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,368(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,372(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// stw r4,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781110:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82781214
	if (!cr6.gt) goto loc_82781214;
	// addi r26,r31,296
	r26.s64 = r31.s64 + 296;
	// li r27,115
	r27.s64 = 115;
loc_82781128:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r28,4(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r28,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// bne cr6,0x82781180
	if (!cr6.eq) goto loc_82781180;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82781180
	if (!cr6.lt) goto loc_82781180;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r23,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r23.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781180;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781180:
	// lwz r30,364(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bgt cr6,0x82781200
	if (cr6.gt) goto loc_82781200;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
loc_82781198:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827811a8
	if (!cr6.lt) goto loc_827811A8;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_827811A8:
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x827811e4
	if (cr6.eq) goto loc_827811E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r30.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827811E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827811E4:
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82781198
	if (!cr6.gt) goto loc_82781198;
loc_82781200:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82781128
	if (cr6.lt) goto loc_82781128;
loc_82781214:
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82781240
	if (!cr6.eq) goto loc_82781240;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82781234
	if (cr6.eq) goto loc_82781234;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,1480
	ctx.r10.s64 = r11.s64 + 1480;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781234:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,2096
	ctx.r10.s64 = r11.s64 + 2096;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781240:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82781254
	if (cr6.eq) goto loc_82781254;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,2720
	ctx.r10.s64 = r11.s64 + 2720;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781254:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,3008
	ctx.r10.s64 = r11.s64 + 3008;
loc_8278125C:
	// stw r10,4(r24)
	PPC_STORE_U32(r24.u32 + 4, ctx.r10.u32);
	// mr r27,r23
	r27.u64 = r23.u64;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827812f4
	if (!cr6.gt) goto loc_827812F4;
	// addi r28,r24,24
	r28.s64 = r24.s64 + 24;
	// addi r29,r31,296
	r29.s64 = r31.s64 + 296;
loc_82781278:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x827812b0
	if (cr6.eq) goto loc_827812B0;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827812d8
	if (!cr6.eq) goto loc_827812D8;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r5,11
	r11.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r24
	ctx.r6.u64 = r11.u64 + r24.u64;
	// bl 0x8277f798
	ctx.lr = 0x827812AC;
	sub_8277F798(ctx, base);
	// b 0x827812d8
	goto loc_827812D8;
loc_827812B0:
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r5,11
	r11.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r24
	r30.u64 = r11.u64 + r24.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x8277f798
	ctx.lr = 0x827812D0;
	sub_8277F798(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,60(r24)
	PPC_STORE_U32(r24.u32 + 60, ctx.r10.u32);
loc_827812D8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stw r23,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r23.u32);
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82781278
	if (cr6.lt) goto loc_82781278;
loc_827812F4:
	// stw r23,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r23.u32);
	// stw r23,12(r24)
	PPC_STORE_U32(r24.u32 + 12, r23.u32);
	// stw r23,20(r24)
	PPC_STORE_U32(r24.u32 + 20, r23.u32);
	// stb r23,8(r24)
	PPC_STORE_U8(r24.u32 + 8, r23.u8);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82781314"))) PPC_WEAK_FUNC(sub_82781314);
PPC_FUNC_IMPL(__imp__sub_82781314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781318"))) PPC_WEAK_FUNC(sub_82781318);
PPC_FUNC_IMPL(__imp__sub_82781318) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r30,0
	r30.s64 = 0;
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// addi r8,r9,4128
	ctx.r8.s64 = ctx.r9.s64 + 4128;
	// addi r11,r3,44
	r11.s64 = ctx.r3.s64 + 44;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r30.u32);
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r30.u32);
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r30.u32);
	// stw r30,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82781390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r9.u32);
	// ble cr6,0x827813d4
	if (!cr6.gt) goto loc_827813D4;
	// li r8,-1
	ctx.r8.s64 = -1;
loc_827813A8:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_827813B4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x827813b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_827813B4;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r9,r9,256
	ctx.r9.s64 = ctx.r9.s64 + 256;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827813a8
	if (cr6.lt) goto loc_827813A8;
loc_827813D4:
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

__attribute__((alias("__imp__sub_827813EC"))) PPC_WEAK_FUNC(sub_827813EC);
PPC_FUNC_IMPL(__imp__sub_827813EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827813F0"))) PPC_WEAK_FUNC(sub_827813F0);
PPC_FUNC_IMPL(__imp__sub_827813F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x827813F8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// lwz r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// lwz r11,412(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 412);
	// lwz r10,196(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827817e0
	if (!cr6.gt) goto loc_827817E0;
	// addi r26,r11,44
	r26.s64 = r11.s64 + 44;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r30,r10,36
	r30.s64 = ctx.r10.s64 + 36;
	// li r24,48
	r24.s64 = 48;
	// li r23,7
	r23.s64 = 7;
	// addi r31,r11,-30832
	r31.s64 = r11.s64 + -30832;
loc_82781438:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x82781514
	if (cr6.gt) goto loc_82781514;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,5216
	r12.s64 = r12.s64 + 5216;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82781480;
	case 1:
		goto loc_82781490;
	case 2:
		goto loc_82781514;
	case 3:
		goto loc_827814A0;
	case 4:
		goto loc_82781514;
	case 5:
		goto loc_82781514;
	case 6:
		goto loc_82781514;
	case 7:
		goto loc_827814B0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,5248(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5248);
	// lwz r19,5264(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5264);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5280(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5280);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5296(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5296);
loc_82781480:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-9560
	r28.s64 = r11.s64 + -9560;
	// b 0x8278153c
	goto loc_8278153C;
loc_82781490:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-10952
	r28.s64 = r11.s64 + -10952;
	// b 0x8278153c
	goto loc_8278153C;
loc_827814A0:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-11736
	r28.s64 = r11.s64 + -11736;
	// b 0x8278153c
	goto loc_8278153C;
loc_827814B0:
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82781504
	if (cr6.lt) goto loc_82781504;
	// beq cr6,0x827814f4
	if (cr6.eq) goto loc_827814F4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x827814e4
	if (cr6.lt) goto loc_827814E4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82781538
	goto loc_82781538;
loc_827814E4:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,2
	r29.s64 = 2;
	// addi r28,r11,-12840
	r28.s64 = r11.s64 + -12840;
	// b 0x8278153c
	goto loc_8278153C;
loc_827814F4:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,1
	r29.s64 = 1;
	// addi r28,r11,-13824
	r28.s64 = r11.s64 + -13824;
	// b 0x8278153c
	goto loc_8278153C;
loc_82781504:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-14976
	r28.s64 = r11.s64 + -14976;
	// b 0x8278153c
	goto loc_8278153C;
loc_82781514:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82781538:
	// bctrl 
	ctx.lr = 0x8278153C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278153C:
	// stw r28,-40(r26)
	PPC_STORE_U32(r26.u32 + -40, r28.u32);
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// blt cr6,0x827817a8
	if (cr6.lt) goto loc_827817A8;
	// beq cr6,0x827816fc
	if (cr6.eq) goto loc_827816FC;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// blt cr6,0x8278159c
	if (cr6.lt) goto loc_8278159C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827817c8
	goto loc_827817C8;
loc_8278159C:
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
loc_827815AC:
	// lhz r7,-4(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + -4);
	// lfd f9,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f0,136(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 136);
	// addi r8,r31,128
	ctx.r8.s64 = r31.s64 + 128;
	// lfd f13,144(r31)
	ctx.f13.u64 = PPC_LOAD_U64(r31.u32 + 144);
	// lfd f12,152(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 152);
	// addi r4,r8,64
	ctx.r4.s64 = ctx.r8.s64 + 64;
	// lfd f11,168(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 168);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,176(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fmul f6,f7,f9
	ctx.f6.f64 = ctx.f7.f64 * ctx.f9.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,-8(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// lfd f4,0(r11)
	ctx.f4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,-2(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f3,88(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fmul f1,f2,f4
	ctx.f1.f64 = ctx.f2.f64 * ctx.f4.f64;
	// fmul f0,f1,f0
	f0.f64 = ctx.f1.f64 * f0.f64;
	// frsp f9,f0
	ctx.f9.f64 = double(float(f0.f64));
	// stfs f9,-4(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// lfd f8,0(r11)
	ctx.f8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f7,96(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fmul f5,f6,f8
	ctx.f5.f64 = ctx.f6.f64 * ctx.f8.f64;
	// fmul f4,f5,f13
	ctx.f4.f64 = ctx.f5.f64 * ctx.f13.f64;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfd f2,0(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f1,104(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// fmul f13,f0,f2
	ctx.f13.f64 = f0.f64 * ctx.f2.f64;
	// fmul f12,f13,f12
	ctx.f12.f64 = ctx.f13.f64 * ctx.f12.f64;
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// stfs f9,4(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lfd f8,0(r11)
	ctx.f8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fmul f5,f6,f8
	ctx.f5.f64 = ctx.f6.f64 * ctx.f8.f64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,8(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lfd f3,0(r11)
	ctx.f3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,6(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f2,120(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// fmul f0,f1,f3
	f0.f64 = ctx.f1.f64 * ctx.f3.f64;
	// fmul f13,f0,f11
	ctx.f13.f64 = f0.f64 * ctx.f11.f64;
	// lfd f0,184(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 184);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,12(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfd f11,0(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfd f9,128(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fmul f7,f8,f11
	ctx.f7.f64 = ctx.f8.f64 * ctx.f11.f64;
	// fmul f6,f7,f10
	ctx.f6.f64 = ctx.f7.f64 * ctx.f10.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,16(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// lfd f4,0(r11)
	ctx.f4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,10(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lfd f3,136(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// fmul f1,f2,f4
	ctx.f1.f64 = ctx.f2.f64 * ctx.f4.f64;
	// fmul f0,f1,f0
	f0.f64 = ctx.f1.f64 * f0.f64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,20(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// blt cr6,0x827815ac
	if (cr6.lt) goto loc_827815AC;
	// b 0x827817c8
	goto loc_827817C8;
loc_827816FC:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// addi r5,r31,2
	ctx.r5.s64 = r31.s64 + 2;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// add r6,r7,r31
	ctx.r6.u64 = ctx.r7.u64 + r31.u64;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r11,r8,4
	r11.s64 = ctx.r8.s64 + 4;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
loc_8278171C:
	// lhz r8,-2(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// addi r5,r31,130
	ctx.r5.s64 = r31.s64 + 130;
	// lhz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// mullw r8,r3,r4
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// addi r8,r8,2048
	ctx.r8.s64 = ctx.r8.s64 + 2048;
	// srawi r4,r8,12
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 12;
	// stw r4,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r4.u32);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// lhz r3,-2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// mullw r8,r3,r4
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// addi r3,r8,2048
	ctx.r3.s64 = ctx.r8.s64 + 2048;
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// srawi r8,r3,12
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 12;
	// stw r8,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r8.u32);
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lhzx r4,r6,r11
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + r11.u32);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// mullw r8,r3,r5
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// addi r8,r8,2048
	ctx.r8.s64 = ctx.r8.s64 + 2048;
	// srawi r5,r8,12
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 12;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lhz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// mullw r8,r8,r4
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// addi r5,r8,2048
	ctx.r5.s64 = ctx.r8.s64 + 2048;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// srawi r4,r5,12
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 12;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// blt cr6,0x8278171c
	if (cr6.lt) goto loc_8278171C;
	// b 0x827817c8
	goto loc_827817C8;
loc_827817A8:
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// li r11,64
	r11.s64 = 64;
loc_827817B0:
	// lhz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x827817b0
	if (!cr0.eq) goto loc_827817B0;
loc_827817C8:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82781438
	if (cr6.lt) goto loc_82781438;
loc_827817E0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827817E8"))) PPC_WEAK_FUNC(sub_827817E8);
PPC_FUNC_IMPL(__imp__sub_827817E8) {
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
	ctx.lr = 0x827817F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,84
	ctx.r5.s64 = 84;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// stw r3,412(r31)
	PPC_STORE_U32(r31.u32 + 412, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r8,r9,5104
	ctx.r8.s64 = ctx.r9.s64 + 5104;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ble cr6,0x82781888
	if (!cr6.gt) goto loc_82781888;
	// addi r29,r11,80
	r29.s64 = r11.s64 + 80;
	// addi r30,r3,44
	r30.s64 = ctx.r3.s64 + 44;
	// li r27,-1
	r27.s64 = -1;
loc_82781840:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278185C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x8278186C;
	sub_823D9890(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// blt cr6,0x82781840
	if (cr6.lt) goto loc_82781840;
loc_82781888:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82781890"))) PPC_WEAK_FUNC(sub_82781890);
PPC_FUNC_IMPL(__imp__sub_82781890) {
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
	ctx.lr = 0x82781898;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r29,396(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// ble cr6,0x827818c4
	if (!cr6.gt) goto loc_827818C4;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_827818C4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827818E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82781928"))) PPC_WEAK_FUNC(sub_82781928);
PPC_FUNC_IMPL(__imp__sub_82781928) {
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
	ctx.lr = 0x82781930;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r31,396(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781980
	if (!cr6.eq) goto loc_82781980;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278197C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_82781980:
	// lwz r11,416(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827819B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// ble cr6,0x827819f4
	if (!cr6.gt) goto loc_827819F4;
	// lwz r9,424(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// subf r27,r29,r11
	r27.s64 = r11.s64 - r29.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827819E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r7,r11,r27
	ctx.r7.u64 = r11.u64 + r27.u64;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
loc_827819F4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82781a18
	if (cr6.lt) goto loc_82781A18;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
loc_82781A18:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82781A20"))) PPC_WEAK_FUNC(sub_82781A20);
PPC_FUNC_IMPL(__imp__sub_82781A20) {
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
	ctx.lr = 0x82781A28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// lwz r31,396(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 396);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781a70
	if (!cr6.eq) goto loc_82781A70;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781A6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_82781A70:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf r9,r10,r30
	ctx.r9.s64 = r30.s64 - ctx.r10.s64;
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// ble cr6,0x82781a90
	if (!cr6.gt) goto loc_82781A90;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
loc_82781A90:
	// lwz r9,96(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// ble cr6,0x82781aa8
	if (!cr6.gt) goto loc_82781AA8;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
loc_82781AA8:
	// lwz r8,424(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 424);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r9,r27
	ctx.r5.u64 = ctx.r9.u64 + r27.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781AD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// stw r6,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r6.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82781b0c
	if (cr6.lt) goto loc_82781B0C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
loc_82781B0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82781B14"))) PPC_WEAK_FUNC(sub_82781B14);
PPC_FUNC_IMPL(__imp__sub_82781B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781B18"))) PPC_WEAK_FUNC(sub_82781B18);
PPC_FUNC_IMPL(__imp__sub_82781B18) {
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
	// lwz r31,396(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82781bcc
	if (cr6.eq) goto loc_82781BCC;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x82781b98
	if (cr6.eq) goto loc_82781B98;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x82781b64
	if (cr6.eq) goto loc_82781B64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781B60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82781c24
	goto loc_82781C24;
loc_82781B64:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781b8c
	if (!cr6.eq) goto loc_82781B8C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781B8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781B8C:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,6440
	ctx.r10.s64 = r11.s64 + 6440;
	// b 0x82781c20
	goto loc_82781C20;
loc_82781B98:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781bc0
	if (!cr6.eq) goto loc_82781BC0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781BC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781BC0:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,6688
	ctx.r10.s64 = r11.s64 + 6688;
	// b 0x82781c20
	goto loc_82781C20;
loc_82781BCC:
	// lbz r11,74(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781c18
	if (cr6.eq) goto loc_82781C18;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,6288
	ctx.r9.s64 = r11.s64 + 6288;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// bne cr6,0x82781c24
	if (!cr6.eq) goto loc_82781C24;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// b 0x82781c24
	goto loc_82781C24;
loc_82781C18:
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_82781C20:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_82781C24:
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82781C44"))) PPC_WEAK_FUNC(sub_82781C44);
PPC_FUNC_IMPL(__imp__sub_82781C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781C48"))) PPC_WEAK_FUNC(sub_82781C48);
PPC_FUNC_IMPL(__imp__sub_82781C48) {
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
	ctx.lr = 0x82781C50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r11,0
	r11.s64 = 0;
	// stw r30,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r30.u32);
	// addi r8,r9,6936
	ctx.r8.s64 = ctx.r9.s64 + 6936;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lbz r7,74(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82781d28
	if (cr6.eq) goto loc_82781D28;
	// lwz r29,276(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// beq cr6,0x82781cfc
	if (cr6.eq) goto loc_82781CFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8277a348
	ctx.lr = 0x82781CC4;
	sub_8277A348(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mullw r6,r11,r10
	ctx.r6.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82781CFC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mullw r5,r10,r9
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781D24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
loc_82781D28:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82781D30"))) PPC_WEAK_FUNC(sub_82781D30);
PPC_FUNC_IMPL(__imp__sub_82781D30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r10,276(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// stw r10,92(r11)
	PPC_STORE_U32(r11.u32 + 92, ctx.r10.u32);
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// stw r9,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82781D48"))) PPC_WEAK_FUNC(sub_82781D48);
PPC_FUNC_IMPL(__imp__sub_82781D48) {
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
	ctx.lr = 0x82781D50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// lwz r29,416(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// lwz r11,276(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// lwz r10,92(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82781dec
	if (cr6.lt) goto loc_82781DEC;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r27,0
	r27.s64 = 0;
	// lwz r26,196(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82781de4
	if (!cr6.gt) goto loc_82781DE4;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r29,12
	r31.s64 = r29.s64 + 12;
loc_82781D98:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r26,r26,84
	r26.s64 = r26.s64 + 84;
	// cmpw cr6,r27,r6
	cr6.compare<int32_t>(r27.s32, ctx.r6.s32, xer);
	// blt cr6,0x82781d98
	if (cr6.lt) goto loc_82781D98;
loc_82781DE4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r11.u32);
loc_82781DEC:
	// lwz r5,92(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// lwz r10,276(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// subf r31,r5,r10
	r31.s64 = ctx.r10.s64 - ctx.r5.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x82781e08
	if (!cr6.gt) goto loc_82781E08;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_82781E08:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// subf r10,r11,r23
	ctx.r10.s64 = r23.s64 - r11.s64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// ble cr6,0x82781e1c
	if (!cr6.gt) goto loc_82781E1C;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_82781E1C:
	// lwz r10,420(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 420);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// add r6,r11,r22
	ctx.r6.u64 = r11.u64 + r22.u64;
	// addi r4,r29,12
	ctx.r4.s64 = r29.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stw r8,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r8.u32);
	// lwz r7,96(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// subf r6,r31,r7
	ctx.r6.s64 = ctx.r7.s64 - r31.s64;
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// stw r11,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r11.u32);
	// stw r6,96(r29)
	PPC_STORE_U32(r29.u32 + 96, ctx.r6.u32);
	// lwz r5,276(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x82781e7c
	if (cr6.lt) goto loc_82781E7C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
loc_82781E7C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82781E84"))) PPC_WEAK_FUNC(sub_82781E84);
PPC_FUNC_IMPL(__imp__sub_82781E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781E88"))) PPC_WEAK_FUNC(sub_82781E88);
PPC_FUNC_IMPL(__imp__sub_82781E88) {
	PPC_FUNC_PROLOGUE();
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82781E90"))) PPC_WEAK_FUNC(sub_82781E90);
PPC_FUNC_IMPL(__imp__sub_82781E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82781E9C"))) PPC_WEAK_FUNC(sub_82781E9C);
PPC_FUNC_IMPL(__imp__sub_82781E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82781EA0"))) PPC_WEAK_FUNC(sub_82781EA0);
PPC_FUNC_IMPL(__imp__sub_82781EA0) {
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
	ctx.lr = 0x82781EA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r25,0(r6)
	r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lwz r9,276(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lbz r29,140(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 140);
	// lbz r26,150(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 150);
	// ble cr6,0x82781f70
	if (!cr6.gt) goto loc_82781F70;
	// rlwinm r24,r26,2,0,29
	r24.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
loc_82781EE4:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x82781f34
	if (!cr6.lt) goto loc_82781F34;
loc_82781EFC:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82781f2c
	if (!cr6.gt) goto loc_82781F2C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82781f28
	if (cr6.eq) goto loc_82781F28;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_82781F1C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82781f1c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82781F1C;
loc_82781F28:
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
loc_82781F2C:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x82781efc
	if (cr6.lt) goto loc_82781EFC;
loc_82781F34:
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// ble cr6,0x82781f58
	if (!cr6.gt) goto loc_82781F58;
	// addi r7,r26,-1
	ctx.r7.s64 = r26.s64 + -1;
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8277a378
	ctx.lr = 0x82781F58;
	sub_8277A378(ctx, base);
loc_82781F58:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// add r27,r24,r27
	r27.u64 = r24.u64 + r27.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82781ee4
	if (cr6.lt) goto loc_82781EE4;
loc_82781F70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82781F78"))) PPC_WEAK_FUNC(sub_82781F78);
PPC_FUNC_IMPL(__imp__sub_82781F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// subf r7,r8,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r8.s64;
loc_82781F90:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82781fc8
	if (!cr6.lt) goto loc_82781FC8;
loc_82781FA8:
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82781fa8
	if (cr6.lt) goto loc_82781FA8;
loc_82781FC8:
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x82781f90
	if (cr6.lt) goto loc_82781F90;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82781FE0"))) PPC_WEAK_FUNC(sub_82781FE0);
PPC_FUNC_IMPL(__imp__sub_82781FE0) {
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
	ctx.lr = 0x82781FE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r27,0(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82782078
	if (!cr6.gt) goto loc_82782078;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
loc_8278200C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,92(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82782044
	if (!cr6.lt) goto loc_82782044;
loc_82782024:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82782024
	if (cr6.lt) goto loc_82782024;
loc_82782044:
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,92(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// addi r6,r28,1
	ctx.r6.s64 = r28.s64 + 1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277a378
	ctx.lr = 0x82782060;
	sub_8277A378(ctx, base);
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8278200c
	if (cr6.lt) goto loc_8278200C;
loc_82782078:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82782080"))) PPC_WEAK_FUNC(sub_82782080);
PPC_FUNC_IMPL(__imp__sub_82782080) {
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
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r31,0
	r31.s64 = 0;
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278216c
	if (!cr6.gt) goto loc_8278216C;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
loc_827820A0:
	// lwzx r10,r5,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r30.u8);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// lwz r7,40(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// addic. r9,r7,-2
	xer.ca = ctx.r7.u32 > 1;
	ctx.r9.s64 = ctx.r7.s64 + -2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82782130
	if (cr0.eq) goto loc_82782130;
loc_827820E8:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r7,r8,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lbz r7,-2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// srawi r7,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 2;
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x827820e8
	if (!cr0.eq) goto loc_827820E8;
loc_82782130:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,-1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// rotlwi r8,r9,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// lwz r7,276(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x827820a0
	if (cr6.lt) goto loc_827820A0;
loc_8278216C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82782178"))) PPC_WEAK_FUNC(sub_82782178);
PPC_FUNC_IMPL(__imp__sub_82782178) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82782180;
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r27,0
	r27.s64 = 0;
	// lwz r24,0(r6)
	r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827822e4
	if (!cr6.gt) goto loc_827822E4;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
loc_82782198:
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// li r26,0
	r26.s64 = 0;
	// add r28,r11,r24
	r28.u64 = r11.u64 + r24.u64;
loc_827821A4:
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x827821b8
	if (!cr6.eq) goto loc_827821B8;
	// lwz r10,-4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -4);
	// b 0x827821bc
	goto loc_827821BC;
loc_827821B8:
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827821BC:
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,0(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r31,r9,1
	r31.s64 = ctx.r9.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lbz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// rotlwi r30,r11,1
	r30.u64 = __builtin_rotateleft32(r11.u32, 1);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + r11.u64;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,7
	ctx.r6.s64 = ctx.r6.s64 + 7;
	// srawi r5,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 4;
	// srawi r6,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 4;
	// stb r5,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stb r6,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// lwz r10,40(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// addic. r9,r10,-2
	xer.ca = ctx.r10.u32 > 1;
	ctx.r9.s64 = ctx.r10.s64 + -2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// beq 0x827822a0
	if (cr0.eq) goto loc_827822A0;
loc_82782244:
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r11,0(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r30,0(r7)
	r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
	// rotlwi r29,r11,1
	r29.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r5,r31,r5
	ctx.r5.u64 = r31.u64 + ctx.r5.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// srawi r30,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r30.s64 = ctx.r5.s32 >> 4;
	// add r5,r31,r11
	ctx.r5.u64 = r31.u64 + r11.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r30.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r5,r5,7
	ctx.r5.s64 = ctx.r5.s64 + 7;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// srawi r31,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r31.s64 = ctx.r5.s32 >> 4;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stb r31,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r31.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne 0x82782244
	if (!cr0.eq) goto loc_82782244;
loc_827822A0:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 + 7;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// srawi r7,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// srawi r6,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 4;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// stb r6,1(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1, ctx.r6.u8);
	// blt cr6,0x827821a4
	if (cr6.lt) goto loc_827821A4;
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82782198
	if (cr6.lt) goto loc_82782198;
loc_827822E4:
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827822E8"))) PPC_WEAK_FUNC(sub_827822E8);
PPC_FUNC_IMPL(__imp__sub_827822E8) {
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
	ctx.lr = 0x827822F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r26,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r26.u32);
	// addi r7,r9,7472
	ctx.r7.s64 = ctx.r9.s64 + 7472;
	// addi r6,r8,7496
	ctx.r6.s64 = ctx.r8.s64 + 7496;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
	// stw r6,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r6.u32);
	// stb r5,8(r26)
	PPC_STORE_U8(r26.u32 + 8, ctx.r5.u8);
	// lbz r4,266(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 266);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82782364
	if (cr6.eq) goto loc_82782364;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,25
	ctx.r10.s64 = 25;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782364:
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r25,1
	r25.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782384
	if (cr6.eq) goto loc_82782384;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x82782388
	if (cr6.gt) goto loc_82782388;
loc_82782384:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82782388:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// clrlwi r24,r10,24
	r24.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827825f0
	if (!cr6.gt) goto loc_827825F0;
	// addi r29,r11,36
	r29.s64 = r11.s64 + 36;
	// addi r30,r26,52
	r30.s64 = r26.s64 + 52;
	// li r23,38
	r23.s64 = 38;
loc_827823AC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r28,r25
	r28.u64 = r25.u64;
	// lwz r10,-28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// lwz r8,-24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + -24);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r6,280(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lwz r10,272(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r9,276(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// rotlwi r8,r5,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// addi r3,r8,-1
	ctx.r3.s64 = ctx.r8.s64 + -1;
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// andc r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// andc r4,r6,r3
	ctx.r4.u64 = ctx.r6.u64 & ~ctx.r3.u64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// lbz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// twllei r6,0
	// divw r8,r7,r6
	ctx.r8.s32 = ctx.r7.s32 / ctx.r6.s32;
	// twllei r6,0
	// twlgei r5,-1
	// twlgei r4,-1
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82782424
	if (!cr6.eq) goto loc_82782424;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,7824
	ctx.r10.s64 = r11.s64 + 7824;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782424:
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bne cr6,0x82782448
	if (!cr6.eq) goto loc_82782448;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82782448
	if (!cr6.eq) goto loc_82782448;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,7816
	ctx.r10.s64 = r11.s64 + 7816;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782448:
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82782494
	if (!cr6.eq) goto loc_82782494;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782484
	if (cr6.eq) goto loc_82782484;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// ble cr6,0x82782484
	if (!cr6.gt) goto loc_82782484;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8320
	ctx.r10.s64 = r11.s64 + 8320;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782484:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8056
	ctx.r10.s64 = r11.s64 + 8056;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782494:
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827824d4
	if (cr6.eq) goto loc_827824D4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// ble cr6,0x827824d4
	if (!cr6.gt) goto loc_827824D4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8568
	ctx.r10.s64 = r11.s64 + 8568;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stb r25,8(r26)
	PPC_STORE_U8(r26.u32 + 8, r25.u8);
	// b 0x82782598
	goto loc_82782598;
loc_827824D4:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8160
	ctx.r10.s64 = r11.s64 + 8160;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_827824E4:
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r6,r10,r8
	ctx.r6.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// mullw r5,r6,r8
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// andc r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 & ~ctx.r4.u64;
	// twllei r8,0
	// subf. r3,r5,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// twlgei r7,-1
	// bne 0x8278257c
	if (!cr0.eq) goto loc_8278257C;
	// rotlwi r7,r9,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r6,r9,r11
	ctx.r6.s32 = ctx.r9.s32 / r11.s32;
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// mullw r5,r6,r11
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// andc r7,r11,r4
	ctx.r7.u64 = r11.u64 & ~ctx.r4.u64;
	// twllei r11,0
	// subf. r3,r5,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// twlgei r7,-1
	// bne 0x8278257c
	if (!cr0.eq) goto loc_8278257C;
	// rotlwi r6,r10,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// rotlwi r7,r9,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r4,r10,r8
	ctx.r4.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r3,r6,-1
	ctx.r3.s64 = ctx.r6.s64 + -1;
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// add r10,r27,r26
	ctx.r10.u64 = r27.u64 + r26.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// add r6,r27,r26
	ctx.r6.u64 = r27.u64 + r26.u64;
	// addi r5,r5,7840
	ctx.r5.s64 = ctx.r5.s64 + 7840;
	// divw r9,r9,r11
	ctx.r9.s32 = ctx.r9.s32 / r11.s32;
	// andc r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// andc r7,r11,r7
	ctx.r7.u64 = r11.u64 & ~ctx.r7.u64;
	// stb r4,140(r10)
	PPC_STORE_U8(ctx.r10.u32 + 140, ctx.r4.u8);
	// twllei r8,0
	// stb r9,150(r6)
	PPC_STORE_U8(ctx.r6.u32 + 150, ctx.r9.u8);
	// twllei r11,0
	// twlgei r3,-1
	// twlgei r7,-1
	// b 0x82782598
	goto loc_82782598;
loc_8278257C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82782598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782598:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827825d8
	if (cr6.eq) goto loc_827825D8;
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r22,276(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r4,272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x8277a348
	ctx.lr = 0x827825B8;
	sub_8277A348(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827825D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,-40(r30)
	PPC_STORE_U32(r30.u32 + -40, ctx.r3.u32);
loc_827825D8:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x827823ac
	if (cr6.lt) goto loc_827823AC;
loc_827825F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_827825F8"))) PPC_WEAK_FUNC(sub_827825F8);
PPC_FUNC_IMPL(__imp__sub_827825F8) {
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
	ctx.lr = 0x82782600;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r31,420(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 420);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82782664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r7,91
	ctx.r7.s64 = 5963776;
	// lis r8,-227
	ctx.r8.s64 = -14876672;
	// lis r9,-179
	ctx.r9.s64 = -11730944;
	// lis r10,44
	ctx.r10.s64 = 2883584;
	// lis r30,0
	r30.s64 = 0;
	// lis r29,-44
	r29.s64 = -2883584;
	// ori r3,r6,26345
	ctx.r3.u64 = ctx.r6.u64 | 26345;
	// ori r4,r5,50594
	ctx.r4.u64 = ctx.r5.u64 | 50594;
	// li r11,0
	r11.s64 = 0;
	// ori r7,r7,26880
	ctx.r7.u64 = ctx.r7.u64 | 26880;
	// ori r8,r8,44800
	ctx.r8.u64 = ctx.r8.u64 | 44800;
	// ori r9,r9,2944
	ctx.r9.u64 = ctx.r9.u64 | 2944;
	// ori r10,r10,36096
	ctx.r10.u64 = ctx.r10.u64 | 36096;
	// ori r5,r30,46802
	ctx.r5.u64 = r30.u64 | 46802;
	// ori r6,r29,51994
	ctx.r6.u64 = r29.u64 | 51994;
loc_827826CC:
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// srawi r29,r9,16
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	r29.s64 = ctx.r9.s32 >> 16;
	// srawi r28,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	r28.s64 = ctx.r8.s32 >> 16;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stwx r29,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r29.u32);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stwx r28,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r28.u32);
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stwx r7,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r7.u32);
	// subf r7,r5,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r5.s64;
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r10,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r10.u32);
	// addi r10,r10,-22554
	ctx.r10.s64 = ctx.r10.s64 + -22554;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x827826cc
	if (!cr6.lt) goto loc_827826CC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82782718"))) PPC_WEAK_FUNC(sub_82782718);
PPC_FUNC_IMPL(__imp__sub_82782718) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82782720;
	// lwz r11,420(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// addic. r23,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r23.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// lwz r24,92(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r7,288(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r27,16(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r26,20(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// blt 0x827827e8
	if (cr0.lt) goto loc_827827E8;
	// rlwinm r25,r5,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_82782748:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lwzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// lwzx r11,r25,r8
	r11.u64 = PPC_LOAD_U32(r25.u32 + ctx.r8.u32);
	// lwzx r8,r5,r25
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + r25.u32);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// beq cr6,0x827827e0
	if (cr6.eq) goto loc_827827E0;
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
	// subf r31,r11,r9
	r31.s64 = ctx.r9.s64 - r11.s64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
loc_82782780:
	// lbzx r5,r30,r11
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// lbzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// rotlwi r3,r5,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r22,r5,2
	r22.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r5,r3,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// lwzx r5,r3,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lwzx r3,r22,r26
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + r26.u32);
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// srawi r5,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 16;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r3,r5,r7
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// lwzx r5,r22,r28
	ctx.r5.u64 = PPC_LOAD_U32(r22.u32 + r28.u32);
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r5,r9,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// bne 0x82782780
	if (!cr0.eq) goto loc_82782780;
loc_827827E0:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bge 0x82782748
	if (!cr0.lt) goto loc_82782748;
loc_827827E8:
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_827827EC"))) PPC_WEAK_FUNC(sub_827827EC);
PPC_FUNC_IMPL(__imp__sub_827827EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827827F0"))) PPC_WEAK_FUNC(sub_827827F0);
PPC_FUNC_IMPL(__imp__sub_827827F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827827F8;
	// lwz r31,36(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addic. r30,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r30.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blt 0x82782870
	if (cr0.lt) goto loc_82782870;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8278280C:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82782860
	if (!cr6.gt) goto loc_82782860;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
loc_8278281C:
	// lwz r29,0(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r10,r29,r5
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// beq cr6,0x82782850
	if (cr6.eq) goto loc_82782850;
loc_82782838:
	// lbz r29,0(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// bne 0x82782838
	if (!cr0.eq) goto loc_82782838;
loc_82782850:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r8,r31
	cr6.compare<int32_t>(ctx.r8.s32, r31.s32, xer);
	// blt cr6,0x8278281c
	if (cr6.lt) goto loc_8278281C;
loc_82782860:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bge 0x8278280c
	if (!cr0.lt) goto loc_8278280C;
loc_82782870:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82782874"))) PPC_WEAK_FUNC(sub_82782874);
PPC_FUNC_IMPL(__imp__sub_82782874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82782878"))) PPC_WEAK_FUNC(sub_82782878);
PPC_FUNC_IMPL(__imp__sub_82782878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8277a378
	sub_8277A378(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82782894"))) PPC_WEAK_FUNC(sub_82782894);
PPC_FUNC_IMPL(__imp__sub_82782894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82782898"))) PPC_WEAK_FUNC(sub_82782898);
PPC_FUNC_IMPL(__imp__sub_82782898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addic. r31,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r31.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x827828f4
	if (cr0.lt) goto loc_827828F4;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_827828AC:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// beq cr6,0x827828ec
	if (cr6.eq) goto loc_827828EC;
loc_827828CC:
	// lbzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// stb r5,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r5.u8);
	// stb r5,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r5.u8);
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// blt cr6,0x827828cc
	if (cr6.lt) goto loc_827828CC;
loc_827828EC:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x827828ac
	if (!cr0.lt) goto loc_827828AC;
loc_827828F4:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827828FC"))) PPC_WEAK_FUNC(sub_827828FC);
PPC_FUNC_IMPL(__imp__sub_827828FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82782900"))) PPC_WEAK_FUNC(sub_82782900);
PPC_FUNC_IMPL(__imp__sub_82782900) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82782908;
	// lwz r11,420(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// addic. r23,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r23.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// lwz r24,92(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r8,288(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwz r28,8(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,12(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r26,16(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r25,20(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// blt 0x827829f0
	if (cr0.lt) goto loc_827829F0;
	// rlwinm r29,r5,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_82782930:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lwzx r9,r11,r29
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwzx r11,r29,r7
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// lwzx r7,r5,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + r29.u32);
	// lwzx r5,r29,r3
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// beq cr6,0x827829e8
	if (cr6.eq) goto loc_827829E8;
	// subf r3,r11,r9
	ctx.r3.s64 = ctx.r9.s64 - r11.s64;
	// subf r31,r11,r7
	r31.s64 = ctx.r7.s64 - r11.s64;
	// subf r30,r11,r5
	r30.s64 = ctx.r5.s64 - r11.s64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
loc_82782974:
	// lbzx r7,r31,r11
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lbzx r22,r3,r11
	r22.u64 = PPC_LOAD_U8(ctx.r3.u32 + r11.u32);
	// rotlwi r21,r5,2
	r21.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r5,r7,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// subf r5,r5,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - r22.s64;
	// lbz r5,255(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// lwzx r7,r7,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r26.u32);
	// lwzx r5,r21,r25
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + r25.u32);
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// srawi r5,r7,16
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 16;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r7,r5,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r7
	ctx.r5.s64 = ctx.r7.s64 - r22.s64;
	// lbz r7,255(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// lwzx r5,r21,r27
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + r27.u32);
	// subf r7,r5,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r7
	ctx.r5.s64 = ctx.r7.s64 - r22.s64;
	// lbz r7,255(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r7,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// lbzx r5,r30,r11
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r5,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r5.u8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82782974
	if (!cr0.eq) goto loc_82782974;
loc_827829E8:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bge 0x82782930
	if (!cr0.lt) goto loc_82782930;
loc_827829F0:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_827829F4"))) PPC_WEAK_FUNC(sub_827829F4);
PPC_FUNC_IMPL(__imp__sub_827829F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827829F8"))) PPC_WEAK_FUNC(sub_827829F8);
PPC_FUNC_IMPL(__imp__sub_827829F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r24{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82782A00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r30,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r30.u32);
	// addi r8,r9,0
	ctx.r8.s64 = ctx.r9.s64 + 0;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82782aa0
	if (cr6.gt) goto loc_82782AA0;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,10844
	r12.s64 = r12.s64 + 10844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82782A70;
	case 1:
		goto loc_82782A80;
	case 2:
		goto loc_82782A80;
	case 3:
		goto loc_82782A90;
	case 4:
		goto loc_82782A90;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10864(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10864);
	// lwz r19,10880(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10880);
	// lwz r19,10880(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10880);
	// lwz r19,10896(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10896);
	// lwz r19,10896(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10896);
loc_82782A70:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
loc_82782A80:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
loc_82782A90:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
loc_82782AA0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x82782acc
	if (!cr6.lt) goto loc_82782ACC;
loc_82782AAC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,10
	ctx.r10.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782ACC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782bb0
	if (cr6.eq) goto loc_82782BB0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82782b54
	if (cr6.eq) goto loc_82782B54;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82782b10
	if (cr6.eq) goto loc_82782B10;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r10,10224
	ctx.r9.s64 = ctx.r10.s64 + 10224;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B10:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82782b3c
	if (!cr6.eq) goto loc_82782B3C;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10496
	ctx.r10.s64 = r11.s64 + 10496;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bl 0x827825f8
	ctx.lr = 0x82782B38;
	sub_827825F8(ctx, base);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B3C:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10224
	ctx.r10.s64 = r11.s64 + 10224;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B54:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82782b80
	if (!cr6.eq) goto loc_82782B80;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10008
	ctx.r10.s64 = r11.s64 + 10008;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bl 0x827825f8
	ctx.lr = 0x82782B7C;
	sub_827825F8(ctx, base);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B80:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82782b98
	if (!cr6.eq) goto loc_82782B98;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10392
	ctx.r10.s64 = r11.s64 + 10392;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B98:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10224
	ctx.r10.s64 = r11.s64 + 10224;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782BB0:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782bec
	if (cr6.eq) goto loc_82782BEC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82782bec
	if (cr6.eq) goto loc_82782BEC;
loc_82782BC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,27
	ctx.r10.s64 = 27;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782BEC:
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r9,r10,10360
	ctx.r9.s64 = ctx.r10.s64 + 10360;
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x82782c30
	if (!cr6.gt) goto loc_82782C30;
	// li r10,84
	ctx.r10.s64 = 84;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82782C10:
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// stb r8,48(r9)
	PPC_STORE_U8(ctx.r9.u32 + 48, ctx.r8.u8);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82782c10
	if (cr6.lt) goto loc_82782C10;
loc_82782C30:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782c48
	if (cr6.eq) goto loc_82782C48;
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82782C48:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82782C58"))) PPC_WEAK_FUNC(sub_82782C58);
PPC_FUNC_IMPL(__imp__sub_82782C58) {
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
	ctx.lr = 0x82782C60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r31,416(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82782CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782CE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r7,91
	ctx.r7.s64 = 5963776;
	// lis r8,-227
	ctx.r8.s64 = -14876672;
	// lis r9,-179
	ctx.r9.s64 = -11730944;
	// lis r10,44
	ctx.r10.s64 = 2883584;
	// lis r30,0
	r30.s64 = 0;
	// lis r29,-44
	r29.s64 = -2883584;
	// ori r3,r6,26345
	ctx.r3.u64 = ctx.r6.u64 | 26345;
	// ori r4,r5,50594
	ctx.r4.u64 = ctx.r5.u64 | 50594;
	// li r11,0
	r11.s64 = 0;
	// ori r7,r7,26880
	ctx.r7.u64 = ctx.r7.u64 | 26880;
	// ori r8,r8,44800
	ctx.r8.u64 = ctx.r8.u64 | 44800;
	// ori r9,r9,2944
	ctx.r9.u64 = ctx.r9.u64 | 2944;
	// ori r10,r10,36096
	ctx.r10.u64 = ctx.r10.u64 | 36096;
	// ori r5,r30,46802
	ctx.r5.u64 = r30.u64 | 46802;
	// ori r6,r29,51994
	ctx.r6.u64 = r29.u64 | 51994;
loc_82782D2C:
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// srawi r29,r9,16
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	r29.s64 = ctx.r9.s32 >> 16;
	// srawi r28,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	r28.s64 = ctx.r8.s32 >> 16;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stwx r29,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r29.u32);
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r28,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r28.u32);
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stwx r7,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r7.u32);
	// subf r7,r5,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r5.s64;
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stwx r10,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r10.u32);
	// addi r10,r10,-22554
	ctx.r10.s64 = ctx.r10.s64 + -22554;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82782d2c
	if (!cr6.lt) goto loc_82782D2C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82782D78"))) PPC_WEAK_FUNC(sub_82782D78);
PPC_FUNC_IMPL(__imp__sub_82782D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,36(r11)
	PPC_STORE_U8(r11.u32 + 36, ctx.r10.u8);
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// stw r9,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82782D90"))) PPC_WEAK_FUNC(sub_82782D90);
PPC_FUNC_IMPL(__imp__sub_82782D90) {
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
	ctx.lr = 0x82782D98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,416(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782dec
	if (cr6.eq) goto loc_82782DEC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x8277a378
	ctx.lr = 0x82782DDC;
	sub_8277A378(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
	// b 0x82782e5c
	goto loc_82782E5C;
loc_82782DEC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r30,2
	r30.s64 = 2;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bge cr6,0x82782e00
	if (!cr6.lt) goto loc_82782E00;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82782E00:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x82782e14
	if (!cr6.gt) goto loc_82782E14;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
loc_82782E14:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ble cr6,0x82782e38
	if (!cr6.gt) goto loc_82782E38;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// b 0x82782e48
	goto loc_82782E48;
loc_82782E38:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
loc_82782E48:
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82782E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782E5C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lbz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82782e8c
	if (!cr6.eq) goto loc_82782E8C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82782E8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82782E94"))) PPC_WEAK_FUNC(sub_82782E94);
PPC_FUNC_IMPL(__imp__sub_82782E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82782E98"))) PPC_WEAK_FUNC(sub_82782E98);
PPC_FUNC_IMPL(__imp__sub_82782E98) {
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
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lwz r10,416(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r6,r11,r7
	ctx.r6.u64 = r11.u64 + ctx.r7.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_82782F04"))) PPC_WEAK_FUNC(sub_82782F04);
PPC_FUNC_IMPL(__imp__sub_82782F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82782F08"))) PPC_WEAK_FUNC(sub_82782F08);
PPC_FUNC_IMPL(__imp__sub_82782F08) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82782F10;
	// lwz r10,416(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r31,8(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,92(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r28,16(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r4,r5,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r27,20(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r26,24(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r25,28(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r11,288(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwzx r7,r7,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// beq cr6,0x82782ff0
	if (cr6.eq) goto loc_82782FF0;
loc_82782F58:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r6,r5,1
	ctx.r6.s64 = ctx.r5.s64 + 1;
	// lbz r31,0(r7)
	r31.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rotlwi r29,r9,2
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r24,r31,2
	r24.u64 = __builtin_rotateleft32(r31.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// lwzx r31,r24,r25
	r31.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// lwzx r5,r29,r26
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
	// add r23,r9,r30
	r23.u64 = ctx.r9.u64 + r30.u64;
	// lwzx r29,r24,r27
	r29.u64 = PPC_LOAD_U32(r24.u32 + r27.u32);
	// add r5,r31,r5
	ctx.r5.u64 = r31.u64 + ctx.r5.u64;
	// add r24,r9,r29
	r24.u64 = ctx.r9.u64 + r29.u64;
	// srawi r31,r5,16
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	r31.s64 = ctx.r5.s32 >> 16;
	// lbzx r23,r23,r11
	r23.u64 = PPC_LOAD_U8(r23.u32 + r11.u32);
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stb r23,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r23.u8);
	// lbzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stb r9,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// lbzx r9,r24,r11
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + r11.u32);
	// stb r9,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// add r6,r9,r30
	ctx.r6.u64 = ctx.r9.u64 + r30.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// lbzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// lbzx r6,r31,r11
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// stb r6,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// lbzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stb r9,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// bne 0x82782f58
	if (!cr0.eq) goto loc_82782F58;
loc_82782FF0:
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82783050
	if (cr6.eq) goto loc_82783050;
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r5,r8,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r8,r7,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// lwzx r6,r5,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + r25.u32);
	// lwzx r7,r7,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r26.u32);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwzx r8,r5,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + r27.u32);
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r8,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 16;
	// lbzx r6,r4,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// lbzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r4,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r4.u8);
	// lbzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// stb r3,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r3.u8);
loc_82783050:
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82783054"))) PPC_WEAK_FUNC(sub_82783054);
PPC_FUNC_IMPL(__imp__sub_82783054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82783058"))) PPC_WEAK_FUNC(sub_82783058);
PPC_FUNC_IMPL(__imp__sub_82783058) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82783060;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r10,r5,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,416(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r11,288(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// rlwinm r28,r4,31,1,31
	r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r26,16(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r29,4(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r25,20(r9)
	r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r24,24(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r23,28(r9)
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwzx r31,r7,r8
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// beq cr6,0x827831b0
	if (cr6.eq) goto loc_827831B0;
loc_827830B8:
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lbz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rotlwi r6,r8,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r22,r7,2
	r22.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwzx r7,r6,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + r26.u32);
	// lwzx r27,r22,r23
	r27.u64 = PPC_LOAD_U32(r22.u32 + r23.u32);
	// lwzx r8,r6,r24
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + r24.u32);
	// add r21,r5,r7
	r21.u64 = ctx.r5.u64 + ctx.r7.u64;
	// lwzx r6,r22,r25
	ctx.r6.u64 = PPC_LOAD_U32(r22.u32 + r25.u32);
	// add r8,r27,r8
	ctx.r8.u64 = r27.u64 + ctx.r8.u64;
	// add r27,r5,r6
	r27.u64 = ctx.r5.u64 + ctx.r6.u64;
	// srawi r8,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 16;
	// lbzx r22,r21,r11
	r22.u64 = PPC_LOAD_U8(r21.u32 + r11.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// stb r22,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r22.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r5.u8);
	// lbzx r5,r27,r11
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// add r27,r5,r7
	r27.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r22,r5,r8
	r22.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r27,r27,r11
	r27.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r27,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r27.u8);
	// lbzx r27,r22,r11
	r27.u64 = PPC_LOAD_U8(r22.u32 + r11.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stb r27,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r27.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r27,r5,r7
	r27.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r22,r5,r8
	r22.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r27,r27,r11
	r27.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r27,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r27.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lbzx r27,r22,r11
	r27.u64 = PPC_LOAD_U8(r22.u32 + r11.u32);
	// stb r27,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r27.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// lbz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// lbzx r5,r8,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stb r5,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r5.u8);
	// lbzx r8,r6,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// stb r8,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r8.u8);
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// bne 0x827830b8
	if (!cr0.eq) goto loc_827830B8;
loc_827831B0:
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82783238
	if (cr6.eq) goto loc_82783238;
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rotlwi r5,r7,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r3,r4,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwzx r6,r5,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + r26.u32);
	// lwzx r4,r3,r23
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + r23.u32);
	// lwzx r7,r5,r24
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + r24.u32);
	// add r31,r8,r6
	r31.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lwzx r5,r3,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r25.u32);
	// add r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 + ctx.r5.u64;
	// srawi r7,r7,16
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// lbzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stb r3,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// lbzx r3,r8,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// lbzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// stb r8,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r8.u8);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbzx r3,r6,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stb r3,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r3.u8);
	// lbzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// stb r8,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r8.u8);
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// stb r7,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r7.u8);
loc_82783238:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8278323C"))) PPC_WEAK_FUNC(sub_8278323C);
PPC_FUNC_IMPL(__imp__sub_8278323C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82783240"))) PPC_WEAK_FUNC(sub_82783240);
PPC_FUNC_IMPL(__imp__sub_82783240) {
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
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82783270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r11,0
	r11.s64 = 0;
	// stw r31,416(r30)
	PPC_STORE_U32(r30.u32 + 416, r31.u32);
	// addi r8,r9,11640
	ctx.r8.s64 = ctx.r9.s64 + 11640;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// lwz r7,100(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r6,92(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// lwz r4,276(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x827832e4
	if (!cr6.eq) goto loc_827832E4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,11664
	ctx.r9.s64 = r11.s64 + 11664;
	// addi r8,r10,12376
	ctx.r8.s64 = ctx.r10.s64 + 12376;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// rotlwi r5,r5,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827832DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// b 0x82783300
	goto loc_82783300;
loc_827832E4:
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// addi r8,r10,11928
	ctx.r8.s64 = ctx.r10.s64 + 11928;
	// addi r7,r9,12040
	ctx.r7.s64 = ctx.r9.s64 + 12040;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
loc_82783300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82782c58
	ctx.lr = 0x82783308;
	sub_82782C58(ctx, base);
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

__attribute__((alias("__imp__sub_82783320"))) PPC_WEAK_FUNC(sub_82783320);
PPC_FUNC_IMPL(__imp__sub_82783320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r31,92(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// ble cr6,0x827833b0
	if (!cr6.gt) goto loc_827833B0;
	// lis r11,0
	r11.s64 = 0;
	// ori r3,r11,65535
	ctx.r3.u64 = r11.u64 | 65535;
loc_82783340:
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827833a4
	if (cr6.eq) goto loc_827833A4;
loc_82783350:
	// lbz r11,1(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r10,2(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rlwinm r11,r11,3,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFE0;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,31,1,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// lhzx r11,r10,r9
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82783398
	if (!cr6.eq) goto loc_82783398;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
loc_82783398:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// bne 0x82783350
	if (!cr0.eq) goto loc_82783350;
loc_827833A4:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x82783340
	if (!cr0.eq) goto loc_82783340;
loc_827833B0:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827833B8"))) PPC_WEAK_FUNC(sub_827833B8);
PPC_FUNC_IMPL(__imp__sub_827833B8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x827833C0;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r26,4(r4)
	r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r29,8(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r27,12(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpw cr6,r26,r31
	cr6.compare<int32_t>(r26.s32, r31.s32, xer);
	// lwz r25,24(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r30,16(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r28,20(r4)
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// ble cr6,0x827834f8
	if (!cr6.gt) goto loc_827834F8;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// add r7,r11,r25
	ctx.r7.u64 = r11.u64 + r25.u64;
loc_827833F4:
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x82783450
	if (cr6.gt) goto loc_82783450;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
loc_82783414:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x82783440
	if (cr6.gt) goto loc_82783440;
loc_82783424:
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783464
	if (!cr6.eq) goto loc_82783464;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783424
	if (!cr6.gt) goto loc_82783424;
loc_82783440:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r8,r27
	cr6.compare<int32_t>(ctx.r8.s32, r27.s32, xer);
	// ble cr6,0x82783414
	if (!cr6.gt) goto loc_82783414;
loc_82783450:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r6,r26
	cr6.compare<int32_t>(ctx.r6.s32, r26.s32, xer);
	// ble cr6,0x827833f4
	if (!cr6.gt) goto loc_827833F4;
	// b 0x8278346c
	goto loc_8278346C;
loc_82783464:
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
loc_8278346C:
	// cmpw cr6,r26,r31
	cr6.compare<int32_t>(r26.s32, r31.s32, xer);
	// ble cr6,0x827834f8
	if (!cr6.gt) goto loc_827834F8;
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// add r7,r11,r25
	ctx.r7.u64 = r11.u64 + r25.u64;
loc_82783480:
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x827834dc
	if (cr6.gt) goto loc_827834DC;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
loc_827834A0:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x827834cc
	if (cr6.gt) goto loc_827834CC;
loc_827834B0:
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827834f0
	if (!cr6.eq) goto loc_827834F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x827834b0
	if (!cr6.gt) goto loc_827834B0;
loc_827834CC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r8,r27
	cr6.compare<int32_t>(ctx.r8.s32, r27.s32, xer);
	// ble cr6,0x827834a0
	if (!cr6.gt) goto loc_827834A0;
loc_827834DC:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// cmpw cr6,r6,r31
	cr6.compare<int32_t>(ctx.r6.s32, r31.s32, xer);
	// bge cr6,0x82783480
	if (!cr6.lt) goto loc_82783480;
	// b 0x827834f8
	goto loc_827834F8;
loc_827834F0:
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
loc_827834F8:
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bge cr6,0x82783608
	if (!cr6.lt) goto loc_82783608;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783510:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x82783564
	if (cr6.gt) goto loc_82783564;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
loc_82783524:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x82783554
	if (cr6.gt) goto loc_82783554;
loc_82783538:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783578
	if (!cr6.eq) goto loc_82783578;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783538
	if (!cr6.gt) goto loc_82783538;
loc_82783554:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x82783524
	if (!cr6.gt) goto loc_82783524;
loc_82783564:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// cmpw cr6,r6,r27
	cr6.compare<int32_t>(ctx.r6.s32, r27.s32, xer);
	// ble cr6,0x82783510
	if (!cr6.gt) goto loc_82783510;
	// b 0x82783580
	goto loc_82783580;
loc_82783578:
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r6,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r6.u32);
loc_82783580:
	// cmpw cr6,r27,r29
	cr6.compare<int32_t>(r27.s32, r29.s32, xer);
	// ble cr6,0x82783608
	if (!cr6.gt) goto loc_82783608;
	// rlwinm r11,r27,5,0,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783598:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827835ec
	if (cr6.gt) goto loc_827835EC;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
loc_827835AC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x827835dc
	if (cr6.gt) goto loc_827835DC;
loc_827835C0:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783600
	if (!cr6.eq) goto loc_82783600;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x827835c0
	if (!cr6.gt) goto loc_827835C0;
loc_827835DC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x827835ac
	if (!cr6.gt) goto loc_827835AC;
loc_827835EC:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r8,r8,-64
	ctx.r8.s64 = ctx.r8.s64 + -64;
	// cmpw cr6,r6,r29
	cr6.compare<int32_t>(ctx.r6.s32, r29.s32, xer);
	// bge cr6,0x82783598
	if (!cr6.lt) goto loc_82783598;
	// b 0x82783608
	goto loc_82783608;
loc_82783600:
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// stw r6,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r6.u32);
loc_82783608:
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bge cr6,0x82783710
	if (!cr6.lt) goto loc_82783710;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
loc_82783614:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x82783674
	if (cr6.gt) goto loc_82783674;
	// rlwinm r10,r29,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783634:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x82783664
	if (cr6.gt) goto loc_82783664;
loc_82783648:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783684
	if (!cr6.eq) goto loc_82783684;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x82783648
	if (!cr6.gt) goto loc_82783648;
loc_82783664:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x82783634
	if (!cr6.gt) goto loc_82783634;
loc_82783674:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r28
	cr6.compare<int32_t>(ctx.r6.s32, r28.s32, xer);
	// ble cr6,0x82783614
	if (!cr6.gt) goto loc_82783614;
	// b 0x8278368c
	goto loc_8278368C;
loc_82783684:
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stw r6,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r6.u32);
loc_8278368C:
	// cmpw cr6,r28,r30
	cr6.compare<int32_t>(r28.s32, r30.s32, xer);
	// ble cr6,0x82783710
	if (!cr6.gt) goto loc_82783710;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_82783698:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827836f8
	if (cr6.gt) goto loc_827836F8;
	// rlwinm r10,r29,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
loc_827836B8:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// bgt cr6,0x827836e8
	if (cr6.gt) goto loc_827836E8;
loc_827836CC:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783708
	if (!cr6.eq) goto loc_82783708;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x827836cc
	if (!cr6.gt) goto loc_827836CC;
loc_827836E8:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x827836b8
	if (!cr6.gt) goto loc_827836B8;
loc_827836F8:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// bge cr6,0x82783698
	if (!cr6.lt) goto loc_82783698;
	// b 0x82783710
	goto loc_82783710;
loc_82783708:
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stw r6,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r6.u32);
loc_82783710:
	// subf r8,r29,r27
	ctx.r8.s64 = r27.s64 - r29.s64;
	// subf r5,r30,r28
	ctx.r5.s64 = r28.s64 - r30.s64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r11,r31,r26
	r11.s64 = r26.s64 - r31.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r10,r9,r9
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r6,r6
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r6.s32);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r10.u32);
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827837c4
	if (cr6.gt) goto loc_827837C4;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// add r6,r10,r25
	ctx.r6.u64 = ctx.r10.u64 + r25.u64;
loc_82783760:
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x827837b8
	if (cr6.gt) goto loc_827837B8;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
loc_82783780:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x827837ac
	if (cr6.gt) goto loc_827837AC;
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
loc_82783790:
	// lhz r26,0(r10)
	r26.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x827837a0
	if (cr6.eq) goto loc_827837A0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_827837A0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne 0x82783790
	if (!cr0.eq) goto loc_82783790;
loc_827837AC:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// bne 0x82783780
	if (!cr0.eq) goto loc_82783780;
loc_827837B8:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x82783760
	if (!cr0.eq) goto loc_82783760;
loc_827837C4:
	// stw r3,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r3.u32);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827837CC"))) PPC_WEAK_FUNC(sub_827837CC);
PPC_FUNC_IMPL(__imp__sub_827837CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827837D0"))) PPC_WEAK_FUNC(sub_827837D0);
PPC_FUNC_IMPL(__imp__sub_827837D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x827837D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// bge cr6,0x827839a4
	if (!cr6.lt) goto loc_827839A4;
	// rlwinm r11,r27,5,0,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r26,r27,1,0,30
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
loc_82783804:
	// cmpw cr6,r26,r23
	cr6.compare<int32_t>(r26.s32, r23.s32, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bgt cr6,0x82783854
	if (cr6.gt) goto loc_82783854;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82783884
	if (!cr6.gt) goto loc_82783884;
	// addi r11,r25,28
	r11.s64 = r25.s64 + 28;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82783824:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x82783844
	if (!cr6.gt) goto loc_82783844;
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82783844
	if (!cr6.gt) goto loc_82783844;
	// addi r4,r11,-28
	ctx.r4.s64 = r11.s64 + -28;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82783844:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82783824
	if (!cr0.eq) goto loc_82783824;
	// b 0x82783884
	goto loc_82783884;
loc_82783854:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82783884
	if (!cr6.gt) goto loc_82783884;
	// addi r11,r25,24
	r11.s64 = r25.s64 + 24;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82783864:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x82783878
	if (!cr6.gt) goto loc_82783878;
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82783878:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82783864
	if (!cr0.eq) goto loc_82783864;
loc_82783884:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827839a4
	if (cr6.eq) goto loc_827839A4;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r29,r31,-12
	r29.s64 = r31.s64 + -12;
	// li r30,1
	r30.s64 = 1;
	// stw r11,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r11.u32);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r8,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r8.u32);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r7,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r7.u32);
	// lwz r6,16(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r5,20(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// subf r11,r6,r7
	r11.s64 = ctx.r7.s64 - ctx.r6.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r8,r9
	r28.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r28,r3,r5
	r28.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,3,0,28
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8278390c
	if (!cr6.gt) goto loc_8278390C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r30,0
	r30.s64 = 0;
loc_8278390C:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x82783918
	if (!cr6.gt) goto loc_82783918;
	// li r30,2
	r30.s64 = 2;
loc_82783918:
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// blt cr6,0x82783964
	if (cr6.lt) goto loc_82783964;
	// beq cr6,0x82783948
	if (cr6.eq) goto loc_82783948;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bge cr6,0x8278397c
	if (!cr6.lt) goto loc_8278397C;
	// add r11,r3,r5
	r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// b 0x8278397c
	goto loc_8278397C;
loc_82783948:
	// add r11,r6,r7
	r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r9,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r9.u32);
	// b 0x8278397c
	goto loc_8278397C;
loc_82783964:
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
loc_8278397C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827833b8
	ctx.lr = 0x82783984;
	sub_827833B8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827833b8
	ctx.lr = 0x82783990;
	sub_827833B8(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// blt cr6,0x82783804
	if (cr6.lt) goto loc_82783804;
loc_827839A4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827839B0"))) PPC_WEAK_FUNC(sub_827839B0);
PPC_FUNC_IMPL(__imp__sub_827839B0) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x827839B8;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lwz r6,424(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r23,8(r8)
	r23.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r19,12(r8)
	r19.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lwz r9,24(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r26,16(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r21,20(r8)
	r21.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bgt cr6,0x82783aac
	if (cr6.gt) goto loc_82783AAC;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r28,r8,4
	r28.s64 = ctx.r8.s64 + 4;
	// add r20,r6,r9
	r20.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r18,r11,1
	r18.s64 = r11.s64 + 1;
loc_82783A0C:
	// cmpw cr6,r23,r19
	cr6.compare<int32_t>(r23.s32, r19.s32, xer);
	// bgt cr6,0x82783a9c
	if (cr6.gt) goto loc_82783A9C;
	// rlwinm r11,r23,5,0,26
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r26
	ctx.r8.u64 = r11.u64 + r26.u64;
	// subf r11,r23,r19
	r11.s64 = r19.s64 - r23.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r10,2
	r29.s64 = ctx.r10.s64 + 2;
	// add r24,r8,r9
	r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_82783A38:
	// mr r25,r24
	r25.u64 = r24.u64;
	// cmpw cr6,r26,r21
	cr6.compare<int32_t>(r26.s32, r21.s32, xer);
	// bgt cr6,0x82783a8c
	if (cr6.gt) goto loc_82783A8C;
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r26,r21
	r11.s64 = r21.s64 - r26.s64;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
loc_82783A54:
	// lhz r11,0(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 0);
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82783a80
	if (cr6.eq) goto loc_82783A80;
	// mullw r8,r28,r11
	ctx.r8.s64 = int64_t(r28.s32) * int64_t(r11.s32);
	// mullw r9,r29,r11
	ctx.r9.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// mullw r10,r6,r11
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
loc_82783A80:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// bne 0x82783a54
	if (!cr0.eq) goto loc_82783A54;
loc_82783A8C:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r24,r24,64
	r24.s64 = r24.s64 + 64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82783a38
	if (!cr0.eq) goto loc_82783A38;
loc_82783A9C:
	// addic. r18,r18,-1
	xer.ca = r18.u32 > 0;
	r18.s64 = r18.s64 + -1;
	cr0.compare<int32_t>(r18.s32, 0, xer);
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x82783a0c
	if (!cr0.eq) goto loc_82783A0C;
loc_82783AAC:
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// twllei r7,0
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// divw r31,r9,r7
	r31.s32 = ctx.r9.s32 / ctx.r7.s32;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r30,r8,r7
	r30.s32 = ctx.r8.s32 / ctx.r7.s32;
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stbx r31,r4,r5
	PPC_STORE_U8(ctx.r4.u32 + ctx.r5.u32, r31.u8);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// lwz r8,116(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stbx r30,r10,r5
	PPC_STORE_U8(ctx.r10.u32 + ctx.r5.u32, r30.u8);
	// andc r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 & ~ctx.r9.u64;
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// andc r8,r7,r4
	ctx.r8.u64 = ctx.r7.u64 & ~ctx.r4.u64;
	// divw r6,r6,r7
	ctx.r6.s32 = ctx.r6.s32 / ctx.r7.s32;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// andc r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 & ~r11.u64;
	// twllei r7,0
	// stbx r6,r4,r5
	PPC_STORE_U8(ctx.r4.u32 + ctx.r5.u32, ctx.r6.u8);
	// twllei r7,0
	// twlgei r10,-1
	// twlgei r8,-1
	// twlgei r3,-1
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82783B2C"))) PPC_WEAK_FUNC(sub_82783B2C);
PPC_FUNC_IMPL(__imp__sub_82783B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82783B30"))) PPC_WEAK_FUNC(sub_82783B30);
PPC_FUNC_IMPL(__imp__sub_82783B30) {
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
	ctx.lr = 0x82783B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r5,r29,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82783B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r11,31
	r11.s64 = 31;
	// li r9,63
	ctx.r9.s64 = 63;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x827833b8
	ctx.lr = 0x82783B90;
	sub_827833B8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827837d0
	ctx.lr = 0x82783BA0;
	sub_827837D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82783bcc
	if (!cr6.gt) goto loc_82783BCC;
loc_82783BB0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827839b0
	ctx.lr = 0x82783BBC;
	sub_827839B0(ctx, base);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// blt cr6,0x82783bb0
	if (cr6.lt) goto loc_82783BB0;
loc_82783BCC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,96
	ctx.r10.s64 = 96;
	// stw r29,112(r30)
	PPC_STORE_U32(r30.u32 + 112, r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82783BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82783C04"))) PPC_WEAK_FUNC(sub_82783C04);
PPC_FUNC_IMPL(__imp__sub_82783C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82783C08"))) PPC_WEAK_FUNC(sub_82783C08);
PPC_FUNC_IMPL(__imp__sub_82783C08) {
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
	ctx.lr = 0x82783C10;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r4,24
	r28.s64 = ctx.r4.s64 + 24;
	// lwz r25,112(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// addi r30,r5,28
	r30.s64 = ctx.r5.s64 + 28;
	// addi r29,r6,24
	r29.s64 = ctx.r6.s64 + 24;
	// add r11,r28,r4
	r11.u64 = r28.u64 + ctx.r4.u64;
	// add r10,r30,r5
	ctx.r10.u64 = r30.u64 + ctx.r5.u64;
	// add r9,r29,r6
	ctx.r9.u64 = r29.u64 + ctx.r6.u64;
	// lis r23,32767
	r23.s64 = 2147418112;
	// srawi r24,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r24.s64 = r11.s32 >> 1;
	// srawi r19,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	r19.s64 = ctx.r10.s32 >> 1;
	// srawi r18,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	r18.s64 = ctx.r9.s32 >> 1;
	// ori r23,r23,65535
	r23.u64 = r23.u64 | 65535;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82783dd0
	if (!cr6.gt) goto loc_82783DD0;
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r26,r1,16
	r26.s64 = ctx.r1.s64 + 16;
	// lwz r22,0(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r21,4(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r20,8(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82783C64:
	// lbzx r11,r22,r27
	r11.u64 = PPC_LOAD_U8(r22.u32 + r27.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x82783c8c
	if (!cr6.lt) goto loc_82783C8C;
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// subf r9,r28,r11
	ctx.r9.s64 = r11.s64 - r28.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r9,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r10,r8,r8
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// b 0x82783cd0
	goto loc_82783CD0;
loc_82783C8C:
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783cb0
	if (!cr6.gt) goto loc_82783CB0;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// subf r9,r4,r11
	ctx.r9.s64 = r11.s64 - ctx.r4.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r9,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r10,r8,r8
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// b 0x82783cd0
	goto loc_82783CD0;
loc_82783CB0:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// bgt cr6,0x82783cc4
	if (cr6.gt) goto loc_82783CC4;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// b 0x82783cc8
	goto loc_82783CC8;
loc_82783CC4:
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
loc_82783CC8:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r9
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
loc_82783CD0:
	// lbzx r11,r21,r27
	r11.u64 = PPC_LOAD_U8(r21.u32 + r27.u32);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bge cr6,0x82783d00
	if (!cr6.lt) goto loc_82783D00;
	// subf r8,r5,r11
	ctx.r8.s64 = r11.s64 - ctx.r5.s64;
	// subf r3,r30,r11
	ctx.r3.s64 = r11.s64 - r30.s64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r3,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// mullw r8,r11,r11
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783d48
	goto loc_82783D48;
loc_82783D00:
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// ble cr6,0x82783d2c
	if (!cr6.gt) goto loc_82783D2C;
	// subf r8,r30,r11
	ctx.r8.s64 = r11.s64 - r30.s64;
	// subf r3,r5,r11
	ctx.r3.s64 = r11.s64 - ctx.r5.s64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r3,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// mullw r8,r11,r11
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783d48
	goto loc_82783D48;
loc_82783D2C:
	// cmpw cr6,r11,r19
	cr6.compare<int32_t>(r11.s32, r19.s32, xer);
	// bgt cr6,0x82783d3c
	if (cr6.gt) goto loc_82783D3C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// b 0x82783d40
	goto loc_82783D40;
loc_82783D3C:
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
loc_82783D40:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_82783D48:
	// mullw r11,r11,r11
	r11.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbzx r9,r20,r27
	ctx.r9.u64 = PPC_LOAD_U8(r20.u32 + r27.u32);
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// bge cr6,0x82783d74
	if (!cr6.lt) goto loc_82783D74;
	// subf r8,r6,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r6.s64;
	// subf r3,r29,r9
	ctx.r3.s64 = ctx.r9.s64 - r29.s64;
	// mullw r8,r8,r8
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783dac
	goto loc_82783DAC;
loc_82783D74:
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// ble cr6,0x82783d94
	if (!cr6.gt) goto loc_82783D94;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
	// subf r3,r6,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r6.s64;
	// mullw r8,r8,r8
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783dac
	goto loc_82783DAC;
loc_82783D94:
	// cmpw cr6,r9,r18
	cr6.compare<int32_t>(ctx.r9.s32, r18.s32, xer);
	// bgt cr6,0x82783da4
	if (cr6.gt) goto loc_82783DA4;
	// subf r9,r29,r9
	ctx.r9.s64 = ctx.r9.s64 - r29.s64;
	// b 0x82783da8
	goto loc_82783DA8;
loc_82783DA4:
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
loc_82783DA8:
	// mullw r9,r9,r9
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
loc_82783DAC:
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bge cr6,0x82783dc0
	if (!cr6.lt) goto loc_82783DC0;
	// mr r23,r11
	r23.u64 = r11.u64;
loc_82783DC0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r27,r25
	cr6.compare<int32_t>(r27.s32, r25.s32, xer);
	// blt cr6,0x82783c64
	if (cr6.lt) goto loc_82783C64;
loc_82783DD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82783e08
	if (!cr6.gt) goto loc_82783E08;
	// addi r10,r1,16
	ctx.r10.s64 = ctx.r1.s64 + 16;
loc_82783DE4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r23
	cr6.compare<int32_t>(ctx.r9.s32, r23.s32, xer);
	// bgt cr6,0x82783df8
	if (cr6.gt) goto loc_82783DF8;
	// stbx r11,r3,r7
	PPC_STORE_U8(ctx.r3.u32 + ctx.r7.u32, r11.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82783DF8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// blt cr6,0x82783de4
	if (cr6.lt) goto loc_82783DE4;
loc_82783E08:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82783E10"))) PPC_WEAK_FUNC(sub_82783E10);
PPC_FUNC_IMPL(__imp__sub_82783E10) {
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
	ctx.lr = 0x82783E18;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,32767
	r31.s64 = 2147418112;
	// addi r11,r1,16
	r11.s64 = ctx.r1.s64 + 16;
	// ori r31,r31,65535
	r31.u64 = r31.u64 | 65535;
	// li r10,128
	ctx.r10.s64 = 128;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82783E30:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82783e30
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82783E30;
	// li r19,0
	r19.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82783f64
	if (!cr6.gt) goto loc_82783F64;
loc_82783E48:
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r11,r1,16
	r11.s64 = ctx.r1.s64 + 16;
	// lbzx r28,r19,r8
	r28.u64 = PPC_LOAD_U8(r19.u32 + ctx.r8.u32);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// li r22,3
	r22.s64 = 3;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r29,0(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r28.u32);
	// lbzx r31,r30,r28
	r31.u64 = PPC_LOAD_U8(r30.u32 + r28.u32);
	// subf r10,r10,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbzx r29,r28,r29
	r29.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// subf r30,r31,r6
	r30.s64 = ctx.r6.s64 - r31.s64;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r29,r29,r4
	r29.s64 = ctx.r4.s64 - r29.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// rlwinm r31,r29,1,0,30
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r10,6
	r29.s64 = ctx.r10.s64 + 6;
	// mullw r25,r10,r10
	r25.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r10.s32);
	// mullw r10,r30,r30
	ctx.r10.s64 = int64_t(r30.s32) * int64_t(r30.s32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// rlwinm r26,r29,1,0,30
	r26.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// rlwinm r25,r30,4,0,27
	r25.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mullw r30,r31,r31
	r30.s64 = int64_t(r31.s32) * int64_t(r31.s32);
	// add r29,r29,r26
	r29.u64 = r29.u64 + r26.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r26,r10,r30
	r26.u64 = ctx.r10.u64 + r30.u64;
	// rlwinm r20,r29,3,0,28
	r20.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r21,r31,5,0,26
	r21.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r24,r25,128
	r24.s64 = r25.s64 + 128;
	// addi r23,r25,256
	r23.s64 = r25.s64 + 256;
loc_82783EC8:
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r29,r20
	r29.u64 = r20.u64;
	// li r30,7
	r30.s64 = 7;
loc_82783ED4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bge cr6,0x82783ee8
	if (!cr6.lt) goto loc_82783EE8;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
loc_82783EE8:
	// lwz r18,4(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r31,r25
	ctx.r10.u64 = r31.u64 + r25.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f00
	if (!cr6.lt) goto loc_82783F00;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stb r28,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r28.u8);
loc_82783F00:
	// lwz r18,8(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r24,r10
	ctx.r10.u64 = r24.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f18
	if (!cr6.lt) goto loc_82783F18;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stb r28,2(r27)
	PPC_STORE_U8(r27.u32 + 2, r28.u8);
loc_82783F18:
	// lwz r18,12(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r10,r23,r10
	ctx.r10.u64 = r23.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f30
	if (!cr6.lt) goto loc_82783F30;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stb r28,3(r27)
	PPC_STORE_U8(r27.u32 + 3, r28.u8);
loc_82783F30:
	// add r31,r29,r31
	r31.u64 = r29.u64 + r31.u64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// bge 0x82783ed4
	if (!cr0.lt) goto loc_82783ED4;
	// add r26,r21,r26
	r26.u64 = r21.u64 + r26.u64;
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r21,r21,512
	r21.s64 = r21.s64 + 512;
	// bge 0x82783ec8
	if (!cr0.lt) goto loc_82783EC8;
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// cmpw cr6,r19,r7
	cr6.compare<int32_t>(r19.s32, ctx.r7.s32, xer);
	// blt cr6,0x82783e48
	if (cr6.lt) goto loc_82783E48;
loc_82783F64:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82783F6C"))) PPC_WEAK_FUNC(sub_82783F6C);
PPC_FUNC_IMPL(__imp__sub_82783F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82783F70"))) PPC_WEAK_FUNC(sub_82783F70);
PPC_FUNC_IMPL(__imp__sub_82783F70) {
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
	ctx.lr = 0x82783F78;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// srawi r31,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r31.s64 = ctx.r4.s32 >> 2;
	// srawi r30,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	r30.s64 = ctx.r5.s32 >> 3;
	// srawi r29,r6,2
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	r29.s64 = ctx.r6.s32 >> 2;
	// rlwinm r11,r31,5,0,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,424(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 424);
	// rlwinm r10,r30,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r9,r29,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lwz r28,24(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// bl 0x82783c08
	ctx.lr = 0x82783FB4;
	sub_82783C08(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82783e10
	ctx.lr = 0x82783FC8;
	sub_82783E10(ctx, base);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r30,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r31,r5,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r9,r28
	ctx.r4.u64 = ctx.r9.u64 + r28.u64;
	// li r3,4
	ctx.r3.s64 = 4;
loc_82783FE8:
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r9,8
	ctx.r9.s64 = 8;
loc_82783FF0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r30,r7,1
	r30.s64 = ctx.r7.s64 + 1;
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// sth r30,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r30.u16);
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// sth r6,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r6.u16);
	// sth r5,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r5.u16);
	// sth r7,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r7.u16);
	// bne 0x82783ff0
	if (!cr0.eq) goto loc_82783FF0;
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x82783fe8
	if (!cr0.eq) goto loc_82783FE8;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8278404C"))) PPC_WEAK_FUNC(sub_8278404C);
PPC_FUNC_IMPL(__imp__sub_8278404C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82784050"))) PPC_WEAK_FUNC(sub_82784050);
PPC_FUNC_IMPL(__imp__sub_82784050) {
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
	ctx.lr = 0x82784058;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,424(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 424);
	// lwz r23,92(r24)
	r23.u64 = PPC_LOAD_U32(r24.u32 + 92);
	// lwz r26,24(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// ble cr6,0x82784104
	if (!cr6.gt) goto loc_82784104;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// subf r22,r5,r4
	r22.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
loc_82784080:
	// lwzx r31,r22,r25
	r31.u64 = PPC_LOAD_U32(r22.u32 + r25.u32);
	// mr r28,r23
	r28.u64 = r23.u64;
	// lwz r27,0(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x827840f8
	if (cr6.eq) goto loc_827840F8;
loc_82784094:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r4,r10,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r5,r9,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// rlwinm r6,r7,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// lwzx r29,r8,r26
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r30,r3,1,0,30
	r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r30,r29
	r11.u64 = PPC_LOAD_U16(r30.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827840e0
	if (!cr6.eq) goto loc_827840E0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82783f70
	ctx.lr = 0x827840E0;
	sub_82783F70(ctx, base);
loc_827840E0:
	// lhzx r11,r30,r29
	r11.u64 = PPC_LOAD_U16(r30.u32 + r29.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// bne 0x82784094
	if (!cr0.eq) goto loc_82784094;
loc_827840F8:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x82784080
	if (!cr0.eq) goto loc_82784080;
loc_82784104:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8278410C"))) PPC_WEAK_FUNC(sub_8278410C);
PPC_FUNC_IMPL(__imp__sub_8278410C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82784110"))) PPC_WEAK_FUNC(sub_82784110);
PPC_FUNC_IMPL(__imp__sub_82784110) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82784118;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r7,424(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r23,92(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r15,288(r3)
	r15.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// stw r3,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r3.u32);
	// lwz r9,24(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r14,40(r7)
	r14.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// stw r23,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r23.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// ble cr6,0x827843d8
	if (!cr6.gt) goto loc_827843D8;
	// subf r11,r5,r4
	r11.s64 = ctx.r4.s64 - ctx.r5.s64;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// b 0x8278417c
	goto loc_8278417C;
loc_82784178:
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8278417C:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lbz r10,36(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 36);
	// lwz r24,0(r5)
	r24.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwzx r30,r11,r5
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// beq cr6,0x827841e0
	if (cr6.eq) goto loc_827841E0;
	// addi r11,r23,1
	r11.s64 = r23.s64 + 1;
	// lwz r8,32(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// rlwinm r10,r23,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r23,r10
	ctx.r10.u64 = r23.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r11,r10,r30
	r11.u64 = ctx.r10.u64 + r30.u64;
	// add r10,r24,r23
	ctx.r10.u64 = r24.u64 + r23.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r3,-3
	ctx.r3.s64 = -3;
	// stb r6,36(r7)
	PPC_STORE_U8(ctx.r7.u32 + 36, ctx.r6.u8);
	// addi r30,r11,-3
	r30.s64 = r11.s64 + -3;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r24,r10,-1
	r24.s64 = ctx.r10.s64 + -1;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// add r31,r9,r8
	r31.u64 = ctx.r9.u64 + ctx.r8.u64;
	// b 0x827841fc
	goto loc_827841FC;
loc_827841E0:
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r31,32(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// li r11,1
	r11.s64 = 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stb r11,36(r7)
	PPC_STORE_U8(ctx.r7.u32 + 36, r11.u8);
loc_827841FC:
	// li r11,0
	r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r16,0
	r16.s64 = 0;
	// li r17,0
	r17.s64 = 0;
	// li r18,0
	r18.s64 = 0;
	// li r19,0
	r19.s64 = 0;
	// li r20,0
	r20.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x827843b4
	if (cr6.eq) goto loc_827843B4;
	// addi r10,r3,2
	ctx.r10.s64 = ctx.r3.s64 + 2;
	// rlwinm r22,r3,1,0,30
	r22.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
loc_82784238:
	// addi r10,r22,2
	ctx.r10.s64 = r22.s64 + 2;
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lhzx r29,r22,r31
	r29.u64 = PPC_LOAD_U16(r22.u32 + r31.u32);
	// lbz r6,1(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// lbz r7,2(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lhzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// lhzx r5,r5,r31
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r5.u32 + r31.u32);
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// extsh r11,r29
	r11.s64 = r29.s16;
	// addi r4,r5,8
	ctx.r4.s64 = ctx.r5.s64 + 8;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// srawi r5,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 4;
	// srawi r4,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 4;
	// srawi r11,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	r11.s64 = ctx.r9.s32 >> 4;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r14
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r14.u32);
	// lwzx r9,r4,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + r14.u32);
	// lwzx r11,r11,r14
	r11.u64 = PPC_LOAD_U32(r11.u32 + r14.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r29,r8,r15
	r29.u64 = PPC_LOAD_U8(ctx.r8.u32 + r15.u32);
	// lbzx r28,r7,r15
	r28.u64 = PPC_LOAD_U8(ctx.r7.u32 + r15.u32);
	// lbzx r27,r6,r15
	r27.u64 = PPC_LOAD_U8(ctx.r6.u32 + r15.u32);
	// srawi r5,r29,2
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x3) != 0);
	ctx.r5.s64 = r29.s32 >> 2;
	// srawi r6,r28,3
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7) != 0);
	ctx.r6.s64 = r28.s32 >> 3;
	// srawi r4,r27,3
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x7) != 0);
	ctx.r4.s64 = r27.s32 >> 3;
	// rlwinm r11,r5,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r6
	ctx.r9.u64 = r11.u64 + ctx.r6.u64;
	// rlwinm r26,r9,1,0,30
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r25,r10,r25
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// lhzx r8,r26,r25
	ctx.r8.u64 = PPC_LOAD_U16(r26.u32 + r25.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827842f4
	if (!cr6.eq) goto loc_827842F4;
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// bl 0x82783f70
	ctx.lr = 0x827842F0;
	sub_82783F70(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_827842F4:
	// lhzx r11,r26,r25
	r11.u64 = PPC_LOAD_U16(r26.u32 + r25.u32);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stb r11,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r11.u8);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lbzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// add r24,r6,r24
	r24.u64 = ctx.r6.u64 + r24.u64;
	// lbzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// lbzx r11,r11,r8
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// subf r11,r5,r29
	r11.s64 = r29.s64 - ctx.r5.s64;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r21,r10
	r29.u64 = r21.u64 + ctx.r10.u64;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	// add r21,r18,r7
	r21.u64 = r18.u64 + ctx.r7.u64;
	// sth r29,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r29.u16);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// subf r11,r4,r28
	r11.s64 = r28.s64 - ctx.r4.s64;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r4,r20,r10
	ctx.r4.u64 = r20.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r20,r17,r6
	r20.u64 = r17.u64 + ctx.r6.u64;
	// sth r4,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r4.u16);
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r28,r19,r11
	r28.u64 = r19.u64 + r11.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r19,r16,r11
	r19.u64 = r16.u64 + r11.u64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r31,r22,r31
	r31.u64 = r22.u64 + r31.u64;
	// bne 0x82784238
	if (!cr0.eq) goto loc_82784238;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r23,120(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r7,124(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_827843B4:
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r6,r5,4
	ctx.r6.s64 = ctx.r5.s64 + 4;
	// sth r21,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r21.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// sth r20,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r20.u16);
	// sth r19,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r19.u16);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bne 0x82784178
	if (!cr0.eq) goto loc_82784178;
loc_827843D8:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827843E0"))) PPC_WEAK_FUNC(sub_827843E0);
PPC_FUNC_IMPL(__imp__sub_827843E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,2044
	ctx.r5.s64 = 2044;
	// lwz r31,424(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278440C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r3,1020
	ctx.r5.s64 = ctx.r3.s64 + 1020;
	// li r11,0
	r11.s64 = 0;
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,16
	ctx.r10.s64 = 16;
loc_8278442C:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// bne 0x8278442c
	if (!cr0.eq) goto loc_8278442C;
	// addi r9,r5,64
	ctx.r9.s64 = ctx.r5.s64 + 64;
	// addi r8,r5,-64
	ctx.r8.s64 = ctx.r5.s64 + -64;
loc_82784454:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// neg r7,r11
	ctx.r7.s64 = -r11.s64;
	// not r6,r10
	ctx.r6.u64 = ~ctx.r10.u64;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// clrlwi r7,r6,31
	ctx.r7.u64 = ctx.r6.u32 & 0x1;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// cmpwi cr6,r10,48
	cr6.compare<int32_t>(ctx.r10.s32, 48, xer);
	// blt cr6,0x82784454
	if (cr6.lt) goto loc_82784454;
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// bgt cr6,0x827844b4
	if (cr6.gt) goto loc_827844B4;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r7,r11
	ctx.r7.s64 = -r11.s64;
	// add r9,r8,r5
	ctx.r9.u64 = ctx.r8.u64 + ctx.r5.u64;
	// subf r8,r8,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r8.s64;
	// subfic r10,r10,256
	xer.ca = ctx.r10.u32 <= 256;
	ctx.r10.s64 = 256 - ctx.r10.s64;
loc_8278449C:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bne 0x8278449c
	if (!cr0.eq) goto loc_8278449C;
loc_827844B4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827844C8"))) PPC_WEAK_FUNC(sub_827844C8);
PPC_FUNC_IMPL(__imp__sub_827844C8) {
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
	// lwz r31,424(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82783b30
	ctx.lr = 0x827844EC;
	sub_82783B30(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,28(r31)
	PPC_STORE_U8(r31.u32 + 28, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82784508"))) PPC_WEAK_FUNC(sub_82784508);
PPC_FUNC_IMPL(__imp__sub_82784508) {
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
	ctx.lr = 0x82784510;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,424(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r29,24(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// beq cr6,0x82784534
	if (cr6.eq) goto loc_82784534;
	// li r11,2
	r11.s64 = 2;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_82784534:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82784568
	if (cr6.eq) goto loc_82784568;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,13088
	ctx.r9.s64 = r11.s64 + 13088;
	// addi r8,r10,17608
	ctx.r8.s64 = ctx.r10.s64 + 17608;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// stb r7,28(r30)
	PPC_STORE_U8(r30.u32 + 28, ctx.r7.u8);
	// b 0x82784674
	goto loc_82784674;
loc_82784568:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82784580
	if (!cr6.eq) goto loc_82784580;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,16656
	ctx.r10.s64 = r11.s64 + 16656;
	// b 0x82784588
	goto loc_82784588;
loc_82784580:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,16464
	ctx.r10.s64 = r11.s64 + 16464;
loc_82784588:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// addi r10,r11,0
	ctx.r10.s64 = r11.s64 + 0;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// lwz r28,112(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bge cr6,0x827845d0
	if (!cr6.lt) goto loc_827845D0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827845D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827845D0:
	// cmpwi cr6,r28,256
	cr6.compare<int32_t>(r28.s32, 256, xer);
	// ble cr6,0x82784604
	if (!cr6.gt) goto loc_82784604;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,57
	ctx.r10.s64 = 57;
	// li r9,256
	ctx.r9.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82784604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82784604:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82784674
	if (!cr6.eq) goto loc_82784674;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r28,r9,1,0,30
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x82784650
	if (!cr6.eq) goto loc_82784650;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278464C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
loc_82784650:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x8277a3e8
	ctx.lr = 0x8278465C;
	sub_8277A3E8(ctx, base);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82784670
	if (!cr6.eq) goto loc_82784670;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827843e0
	ctx.lr = 0x82784670;
	sub_827843E0(ctx, base);
loc_82784670:
	// stb r27,36(r30)
	PPC_STORE_U8(r30.u32 + 36, r27.u8);
loc_82784674:
	// lbz r11,28(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827846a0
	if (cr6.eq) goto loc_827846A0;
	// li r31,32
	r31.s64 = 32;
loc_82784684:
	// li r4,4096
	ctx.r4.s64 = 4096;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8277a3e8
	ctx.lr = 0x82784690;
	sub_8277A3E8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82784684
	if (!cr0.eq) goto loc_82784684;
	// stb r27,28(r30)
	PPC_STORE_U8(r30.u32 + 28, r27.u8);
loc_827846A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827846A8"))) PPC_WEAK_FUNC(sub_827846A8);
PPC_FUNC_IMPL(__imp__sub_827846A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,28(r11)
	PPC_STORE_U8(r11.u32 + 28, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827846B8"))) PPC_WEAK_FUNC(sub_827846B8);
PPC_FUNC_IMPL(__imp__sub_827846B8) {
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
	ctx.lr = 0x827846C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827846E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r30,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r30.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r7,r9,17672
	ctx.r7.s64 = ctx.r9.s64 + 17672;
	// addi r6,r8,18088
	ctx.r6.s64 = ctx.r8.s64 + 18088;
	// stw r28,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r28.u32);
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// stw r6,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r6.u32);
	// stw r28,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r28.u32);
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// beq cr6,0x82784738
	if (cr6.eq) goto loc_82784738;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82784738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82784738:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82784754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8278475C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82784778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stwx r3,r29,r9
	PPC_STORE_U32(r29.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r29,128
	cr6.compare<int32_t>(r29.s32, 128, xer);
	// blt cr6,0x8278475c
	if (cr6.lt) goto loc_8278475C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,28(r30)
	PPC_STORE_U8(r30.u32 + 28, r11.u8);
	// lbz r10,90(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82784838
	if (cr6.eq) goto loc_82784838;
	// lwz r29,84(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bge cr6,0x827847d8
	if (!cr6.lt) goto loc_827847D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// li r9,8
	ctx.r9.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827847D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827847D8:
	// cmpwi cr6,r29,256
	cr6.compare<int32_t>(r29.s32, 256, xer);
	// ble cr6,0x8278480c
	if (!cr6.gt) goto loc_8278480C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,57
	ctx.r10.s64 = 57;
	// li r9,256
	ctx.r9.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8278480C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278480C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278482C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// stw r29,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r29.u32);
	// b 0x8278483c
	goto loc_8278483C;
loc_82784838:
	// stw r28,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r28.u32);
loc_8278483C:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82784850
	if (cr6.eq) goto loc_82784850;
	// li r11,2
	r11.s64 = 2;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_82784850:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82784894
	if (!cr6.eq) goto loc_82784894;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82784888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827843e0
	ctx.lr = 0x82784894;
	sub_827843E0(ctx, base);
loc_82784894:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8278489C"))) PPC_WEAK_FUNC(sub_8278489C);
PPC_FUNC_IMPL(__imp__sub_8278489C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827848A0"))) PPC_WEAK_FUNC(sub_827848A0);
PPC_FUNC_IMPL(__imp__sub_827848A0) {
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
	ctx.lr = 0x827848A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r29,100(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 100);
	// lwz r28,84(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 84);
loc_827848C0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// ble cr6,0x827848e0
	if (!cr6.gt) goto loc_827848E0;
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
loc_827848D4:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// bne 0x827848d4
	if (!cr0.eq) goto loc_827848D4;
loc_827848E0:
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// ble cr6,0x827848c0
	if (!cr6.gt) goto loc_827848C0;
	// addi r30,r9,-1
	r30.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bge cr6,0x8278491c
	if (!cr6.lt) goto loc_8278491C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r9,56
	ctx.r9.s64 = 56;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8278491C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278491C:
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82784954
	if (!cr6.gt) goto loc_82784954;
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82784948
	if (cr6.eq) goto loc_82784948;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_8278493C:
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8278493c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278493C;
loc_82784948:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mullw r3,r3,r30
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r30.s32);
	// bne 0x82784948
	if (!cr0.eq) goto loc_82784948;
loc_82784954:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r5,r11,-30384
	ctx.r5.s64 = r11.s64 + -30384;
loc_8278495C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x827849d4
	if (!cr6.gt) goto loc_827849D4;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
loc_82784970:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82784984
	if (!cr6.eq) goto loc_82784984;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// b 0x82784988
	goto loc_82784988;
loc_82784984:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82784988:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r11,r3,1
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// divw r30,r3,r11
	r30.s32 = ctx.r3.s32 / r11.s32;
	// andc r4,r11,r4
	ctx.r4.u64 = r11.u64 & ~ctx.r4.u64;
	// twllei r11,0
	// mullw r11,r30,r10
	r11.s64 = int64_t(r30.s32) * int64_t(ctx.r10.s32);
	// twlgei r4,-1
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// bgt cr6,0x827849d4
	if (cr6.gt) goto loc_827849D4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// blt cr6,0x82784970
	if (cr6.lt) goto loc_82784970;
loc_827849D4:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8278495c
	if (!cr6.eq) goto loc_8278495C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827849E8"))) PPC_WEAK_FUNC(sub_827849E8);
PPC_FUNC_IMPL(__imp__sub_827849E8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x827849F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r23,424(r25)
	r23.u64 = PPC_LOAD_U32(r25.u32 + 424);
	// addi r31,r23,32
	r31.s64 = r23.s64 + 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x827848a0
	ctx.lr = 0x82784A08;
	sub_827848A0(ctx, base);
	// lwz r11,100(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bne cr6,0x82784a5c
	if (!cr6.eq) goto loc_82784A5C;
	// stw r29,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r29.u32);
	// li r10,94
	ctx.r10.s64 = 94;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r8,36(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 36);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lwz r7,40(r23)
	ctx.r7.u64 = PPC_LOAD_U32(r23.u32 + 40);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r10,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r10.u32);
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82784a78
	goto loc_82784A78;
loc_82784A5C:
	// li r10,95
	ctx.r10.s64 = 95;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82784A78:
	// bctrl 
	ctx.lr = 0x82784A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lwz r6,100(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82784A9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,100(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// mr r26,r29
	r26.u64 = r29.u64;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82784b78
	if (!cr6.gt) goto loc_82784B78;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_82784AB4:
	// rotlwi r10,r26,1
	ctx.r10.u64 = __builtin_rotateleft32(r26.u32, 1);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// divw r8,r26,r11
	ctx.r8.s32 = r26.s32 / r11.s32;
	// andc r9,r11,r10
	ctx.r9.u64 = r11.u64 & ~ctx.r10.u64;
	// twllei r11,0
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// twlgei r9,-1
	// ble cr6,0x82784b5c
	if (!cr6.gt) goto loc_82784B5C;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// srawi r10,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addze r27,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r27.s64 = temp.s64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82784AF0:
	// add r9,r5,r27
	ctx.r9.u64 = ctx.r5.u64 + r27.u64;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r30,r9,r4
	r30.s32 = ctx.r9.s32 / ctx.r4.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r4,0
	// andc r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 & ~r11.u64;
	// cmpw cr6,r6,r29
	cr6.compare<int32_t>(ctx.r6.s32, r29.s32, xer);
	// twlgei r9,-1
	// bge cr6,0x82784b4c
	if (!cr6.lt) goto loc_82784B4C;
loc_82784B18:
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82784b40
	if (!cr6.gt) goto loc_82784B40;
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
loc_82784B28:
	// lwz r22,0(r7)
	r22.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r21,r11,r10
	r21.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// stbx r9,r21,r22
	PPC_STORE_U8(r21.u32 + r22.u32, ctx.r9.u8);
	// blt cr6,0x82784b28
	if (cr6.lt) goto loc_82784B28;
loc_82784B40:
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + r26.u64;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// blt cr6,0x82784b18
	if (cr6.lt) goto loc_82784B18;
loc_82784B4C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r5,r5,255
	ctx.r5.s64 = ctx.r5.s64 + 255;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// bne 0x82784af0
	if (!cr0.eq) goto loc_82784AF0;
loc_82784B5C:
	// lwz r11,100(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82784ab4
	if (cr6.lt) goto loc_82784AB4;
loc_82784B78:
	// stw r29,20(r23)
	PPC_STORE_U32(r23.u32 + 20, r29.u32);
	// stw r3,16(r23)
	PPC_STORE_U32(r23.u32 + 16, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82784B88"))) PPC_WEAK_FUNC(sub_82784B88);
PPC_FUNC_IMPL(__imp__sub_82784B88) {
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
	ctx.lr = 0x82784B90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r31,424(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 424);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82784bb0
	if (!cr6.eq) goto loc_82784BB0;
	// li r26,510
	r26.s64 = 510;
	// b 0x82784bb8
	goto loc_82784BB8;
loc_82784BB0:
	// li r11,0
	r11.s64 = 0;
	// li r26,0
	r26.s64 = 0;
loc_82784BB8:
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
	// addi r5,r26,256
	ctx.r5.s64 = r26.s64 + 256;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,100(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82784BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r9,100(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// li r27,0
	r27.s64 = 0;
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82784d04
	if (!cr6.gt) goto loc_82784D04;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
loc_82784BFC:
	// rotlwi r10,r30,1
	ctx.r10.u64 = __builtin_rotateleft32(r30.u32, 1);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// divw r30,r30,r11
	r30.s32 = r30.s32 / r11.s32;
	// andc r9,r11,r10
	ctx.r9.u64 = r11.u64 & ~ctx.r10.u64;
	// twllei r11,0
	// twlgei r9,-1
	// beq cr6,0x82784c30
	if (cr6.eq) goto loc_82784C30;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r9,r9,255
	ctx.r9.s64 = ctx.r9.s64 + 255;
	// stwx r9,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r9.u32);
loc_82784C30:
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r5,255
	ctx.r8.s64 = ctx.r5.s64 + 255;
	// rlwinm r6,r5,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lwzx r4,r9,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// divw r7,r8,r6
	ctx.r7.s32 = ctx.r8.s32 / ctx.r6.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r6,0
	// andc r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 & ~r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// twlgei r9,-1
loc_82784C64:
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// ble cr6,0x82784ca4
	if (!cr6.gt) goto loc_82784CA4;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r11,r10,510
	r11.s64 = ctx.r10.s64 * 510;
loc_82784C74:
	// addi r11,r11,510
	r11.s64 = r11.s64 + 510;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r11,r5
	ctx.r7.u64 = r11.u64 + ctx.r5.u64;
	// twllei r9,0
	// addi r7,r7,255
	ctx.r7.s64 = ctx.r7.s64 + 255;
	// rotlwi r6,r7,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r7,r7,r9
	ctx.r7.s32 = ctx.r7.s32 / ctx.r9.s32;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// andc r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r6.u64;
	// twlgei r6,-1
	// bgt cr6,0x82784c74
	if (cr6.gt) goto loc_82784C74;
loc_82784CA4:
	// mullw r11,r10,r30
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// stbx r11,r8,r4
	PPC_STORE_U8(ctx.r8.u32 + ctx.r4.u32, r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,255
	cr6.compare<int32_t>(ctx.r8.s32, 255, xer);
	// ble cr6,0x82784c64
	if (!cr6.gt) goto loc_82784C64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82784cec
	if (cr6.eq) goto loc_82784CEC;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r4,255
	ctx.r9.s64 = ctx.r4.s64 + 255;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
loc_82784CCC:
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stbx r7,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82784ccc
	if (!cr6.gt) goto loc_82784CCC;
loc_82784CEC:
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82784bfc
	if (cr6.lt) goto loc_82784BFC;
loc_82784D04:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82784D0C"))) PPC_WEAK_FUNC(sub_82784D0C);
PPC_FUNC_IMPL(__imp__sub_82784D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82784D10"))) PPC_WEAK_FUNC(sub_82784D10);
PPC_FUNC_IMPL(__imp__sub_82784D10) {
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
	ctx.lr = 0x82784D18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// lwz r25,424(r28)
	r25.u64 = PPC_LOAD_U32(r28.u32 + 424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82784e2c
	if (!cr6.gt) goto loc_82784E2C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r26,r25,52
	r26.s64 = r25.s64 + 52;
	// ori r30,r10,65025
	r30.u64 = ctx.r10.u64 | 65025;
	// addi r27,r11,-30640
	r27.s64 = r11.s64 + -30640;
loc_82784D48:
	// lwz r31,-20(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + -20);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82784d90
	if (!cr6.gt) goto loc_82784D90;
	// addi r10,r25,32
	ctx.r10.s64 = r25.s64 + 32;
loc_82784D5C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// beq cr6,0x82784d7c
	if (cr6.eq) goto loc_82784D7C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// blt cr6,0x82784d5c
	if (cr6.lt) goto loc_82784D5C;
	// b 0x82784d90
	goto loc_82784D90;
loc_82784D7C:
	// addi r11,r11,13
	r11.s64 = r11.s64 + 13;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r25
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82784e14
	if (!cr6.eq) goto loc_82784E14;
loc_82784D90:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82784DAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r31,9,0,22
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 9) & 0xFFFFFE00;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r8,r11,-512
	ctx.r8.s64 = r11.s64 + -512;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82784DBC:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_82784DC4:
	// lbzx r11,r6,r9
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// twllei r8,0
	// mulli r10,r11,510
	ctx.r10.s64 = r11.s64 * 510;
	// subf. r11,r10,r30
	r11.s64 = r30.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r11,r11,r8
	r11.s32 = r11.s32 / ctx.r8.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// andc r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// twlgei r5,-1
	// blt cr6,0x82784dc4
	if (cr6.lt) goto loc_82784DC4;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// addi r10,r27,256
	ctx.r10.s64 = r27.s64 + 256;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmpw cr6,r6,r10
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, xer);
	// blt cr6,0x82784dbc
	if (cr6.lt) goto loc_82784DBC;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82784E14:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
	// lwz r11,100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82784d48
	if (cr6.lt) goto loc_82784D48;
loc_82784E2C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82784E34"))) PPC_WEAK_FUNC(sub_82784E34);
PPC_FUNC_IMPL(__imp__sub_82784E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82784E38"))) PPC_WEAK_FUNC(sub_82784E38);
PPC_FUNC_IMPL(__imp__sub_82784E38) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82784E40;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r30,92(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r3,100(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r29,24(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// ble cr6,0x82784ec4
	if (!cr6.gt) goto loc_82784EC4;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// subf r28,r5,r4
	r28.s64 = ctx.r4.s64 - ctx.r5.s64;
loc_82784E60:
	// lwzx r9,r28,r31
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82784eb8
	if (cr6.eq) goto loc_82784EB8;
loc_82784E74:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82784ea8
	if (!cr6.gt) goto loc_82784EA8;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82784E88:
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r27,0(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbzx r7,r7,r27
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + r27.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// bne 0x82784e88
	if (!cr0.eq) goto loc_82784E88;
loc_82784EA8:
	// stb r8,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r8.u8);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bne 0x82784e74
	if (!cr0.eq) goto loc_82784E74;
loc_82784EB8:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82784e60
	if (!cr0.eq) goto loc_82784E60;
loc_82784EC4:
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82784EC8"))) PPC_WEAK_FUNC(sub_82784EC8);
PPC_FUNC_IMPL(__imp__sub_82784EC8) {
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
	ctx.lr = 0x82784ED0;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r29,92(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// ble cr6,0x82784f50
	if (!cr6.gt) goto loc_82784F50;
	// subf r4,r5,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r5.s64;
loc_82784EF4:
	// lwzx r10,r4,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82784f44
	if (cr6.eq) goto loc_82784F44;
loc_82784F08:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r8,r8,r3
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r3.u32);
	// lbz r28,0(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r7,r7,r31
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + r31.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lbzx r7,r28,r30
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne 0x82784f08
	if (!cr0.eq) goto loc_82784F08;
loc_82784F44:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// bne 0x82784ef4
	if (!cr0.eq) goto loc_82784EF4;
loc_82784F50:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82784F54"))) PPC_WEAK_FUNC(sub_82784F54);
PPC_FUNC_IMPL(__imp__sub_82784F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82784F58"))) PPC_WEAK_FUNC(sub_82784F58);
PPC_FUNC_IMPL(__imp__sub_82784F58) {
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
	ctx.lr = 0x82784F60;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r25,424(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r29,100(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r28,92(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// ble cr6,0x8278503c
	if (!cr6.gt) goto loc_8278503C;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// subf r23,r5,r4
	r23.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
loc_82784F84:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8277a3e8
	ctx.lr = 0x82784F90;
	sub_8277A3E8(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lwz r22,48(r25)
	r22.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// ble cr6,0x82785024
	if (!cr6.gt) goto loc_82785024;
	// rlwinm r24,r22,6,0,25
	r24.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 6) & 0xFFFFFFC0;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r25,52
	r26.s64 = r25.s64 + 52;
loc_82784FAC:
	// lwz r6,24(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwzx r9,r23,r31
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + r31.u32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// add r4,r7,r24
	ctx.r4.u64 = ctx.r7.u64 + r24.u64;
	// lwzx r3,r6,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r27.u32);
	// beq cr6,0x82785010
	if (cr6.eq) goto loc_82785010;
loc_82784FD8:
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// clrlwi r8,r8,28
	ctx.r8.u64 = ctx.r8.u32 & 0xF;
	// lwzx r7,r7,r4
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// lbzx r7,r7,r3
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r3.u32);
	// add r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x82784fd8
	if (!cr0.eq) goto loc_82784FD8;
loc_82785010:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82784fac
	if (cr6.lt) goto loc_82784FAC;
loc_82785024:
	// addi r11,r22,1
	r11.s64 = r22.s64 + 1;
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r10,48(r25)
	PPC_STORE_U32(r25.u32 + 48, ctx.r10.u32);
	// bne 0x82784f84
	if (!cr0.eq) goto loc_82784F84;
loc_8278503C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82785044"))) PPC_WEAK_FUNC(sub_82785044);
PPC_FUNC_IMPL(__imp__sub_82785044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82785048"))) PPC_WEAK_FUNC(sub_82785048);
PPC_FUNC_IMPL(__imp__sub_82785048) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82785050;
	// lwz r28,424(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r22,92(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r25,8(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// ble cr6,0x8278512c
	if (!cr6.gt) goto loc_8278512C;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// subf r21,r5,r4
	r21.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
loc_8278507C:
	// lwz r23,48(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,52(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// mr r11,r22
	r11.u64 = r22.u64;
	// rlwinm r7,r23,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r6,56(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r5,60(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// add r31,r8,r7
	r31.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwzx r9,r21,r24
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + r24.u32);
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add r30,r6,r7
	r30.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r29,r5,r7
	r29.u64 = ctx.r5.u64 + ctx.r7.u64;
	// beq cr6,0x82785114
	if (cr6.eq) goto loc_82785114;
loc_827850B4:
	// lbz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// clrlwi r10,r6,28
	ctx.r10.u64 = ctx.r6.u32 & 0xF;
	// lbz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwzx r6,r7,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// add r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 + ctx.r5.u64;
	// lwzx r7,r7,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// add r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lbz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r3,r7,r6
	ctx.r3.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbzx r7,r5,r26
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + r26.u32);
	// lbzx r6,r4,r27
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + r27.u32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lbzx r6,r3,r25
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + r25.u32);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne 0x827850b4
	if (!cr0.eq) goto loc_827850B4;
loc_82785114:
	// addi r11,r23,1
	r11.s64 = r23.s64 + 1;
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// stw r10,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r10.u32);
	// bne 0x8278507c
	if (!cr0.eq) goto loc_8278507C;
loc_8278512C:
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82785130"))) PPC_WEAK_FUNC(sub_82785130);
PPC_FUNC_IMPL(__imp__sub_82785130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82785138;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r21,424(r3)
	r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r24,100(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r25,92(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r26,288(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// ble cr6,0x8278529c
	if (!cr6.gt) goto loc_8278529C;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// subf r18,r5,r4
	r18.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r17,r6
	r17.u64 = ctx.r6.u64;
loc_82785160:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// bl 0x8277a3e8
	ctx.lr = 0x8278516C;
	sub_8277A3E8(ctx, base);
	// li r20,0
	r20.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82785280
	if (!cr6.gt) goto loc_82785280;
	// li r22,0
	r22.s64 = 0;
	// addi r23,r21,68
	r23.s64 = r21.s64 + 68;
loc_82785180:
	// lwzx r10,r18,r19
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + r19.u32);
	// lbz r9,84(r21)
	ctx.r9.u64 = PPC_LOAD_U8(r21.u32 + 84);
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// add r7,r10,r20
	ctx.r7.u64 = ctx.r10.u64 + r20.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827851c4
	if (cr6.eq) goto loc_827851C4;
	// addi r10,r25,-1
	ctx.r10.s64 = r25.s64 + -1;
	// lwz r8,0(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r6,r25,1
	ctx.r6.s64 = r25.s64 + 1;
	// mullw r9,r10,r24
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r24.s32);
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// li r30,-1
	r30.s64 = -1;
	// neg r29,r24
	r29.s64 = -r24.s64;
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// b 0x827851d0
	goto loc_827851D0;
loc_827851C4:
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// li r30,1
	r30.s64 = 1;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_827851D0:
	// lwz r8,24(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,16(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 16);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r28,r8,r22
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + r22.u32);
	// lwzx r27,r22,r4
	r27.u64 = PPC_LOAD_U32(r22.u32 + ctx.r4.u32);
	// mtctr r25
	ctr.u64 = r25.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82785268
	if (cr6.eq) goto loc_82785268;
	// rlwinm r4,r30,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
loc_827851FC:
	// lhzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r10.u32);
	// lbz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// add r7,r29,r7
	ctx.r7.u64 = r29.u64 + ctx.r7.u64;
	// extsh r31,r8
	r31.s64 = ctx.r8.s16;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r9,r31,r9
	ctx.r9.u64 = r31.u64 + ctx.r9.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// srawi r9,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 4;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lbzx r3,r3,r26
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + r26.u32);
	// lbzx r9,r3,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + r28.u32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbzx r9,r9,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r27.u32);
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r31,r6,r9
	r31.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// sth r31,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r31.u16);
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bdnz 0x827851fc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_827851FC;
loc_82785268:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// sth r6,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r6.u16);
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r20,r24
	cr6.compare<int32_t>(r20.s32, r24.s32, xer);
	// blt cr6,0x82785180
	if (cr6.lt) goto loc_82785180;
loc_82785280:
	// lbz r11,84(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 84);
	// addic. r17,r17,-1
	xer.ca = r17.u32 > 0;
	r17.s64 = r17.s64 + -1;
	cr0.compare<int32_t>(r17.s32, 0, xer);
	// addi r19,r19,4
	r19.s64 = r19.s64 + 4;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,84(r21)
	PPC_STORE_U8(r21.u32 + 84, ctx.r9.u8);
	// bne 0x82785160
	if (!cr0.eq) goto loc_82785160;
loc_8278529C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_827852A4"))) PPC_WEAK_FUNC(sub_827852A4);
PPC_FUNC_IMPL(__imp__sub_827852A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827852A8"))) PPC_WEAK_FUNC(sub_827852A8);
PPC_FUNC_IMPL(__imp__sub_827852A8) {
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
	ctx.lr = 0x827852B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// lwz r10,424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r28,r8,1,0,30
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82785310
	if (!cr6.gt) goto loc_82785310;
	// addi r29,r10,68
	r29.s64 = ctx.r10.s64 + 68;
loc_827852DC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827852F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x827852dc
	if (cr6.lt) goto loc_827852DC;
loc_82785310:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82785318"))) PPC_WEAK_FUNC(sub_82785318);
PPC_FUNC_IMPL(__imp__sub_82785318) {
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
	ctx.lr = 0x82785320;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,424(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r9,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r9.u32);
	// blt cr6,0x82785444
	if (cr6.lt) goto loc_82785444;
	// beq cr6,0x827853e8
	if (cr6.eq) goto loc_827853E8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x82785378
	if (cr6.lt) goto loc_82785378;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82785370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82785378:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,20784
	ctx.r8.s64 = r11.s64 + 20784;
	// addi r29,r30,68
	r29.s64 = r30.s64 + 68;
	// stb r9,84(r30)
	PPC_STORE_U8(r30.u32 + 84, ctx.r9.u8);
	// stw r8,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827853a4
	if (!cr6.eq) goto loc_827853A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827852a8
	ctx.lr = 0x827853A4;
	sub_827852A8(ctx, base);
loc_827853A4:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r28,r9,1,0,30
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82785470
	if (!cr6.gt) goto loc_82785470;
loc_827853C0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8277a3e8
	ctx.lr = 0x827853CC;
	sub_8277A3E8(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827853c0
	if (cr6.lt) goto loc_827853C0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827853E8:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82785400
	if (!cr6.eq) goto loc_82785400;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,20552
	ctx.r10.s64 = r11.s64 + 20552;
	// b 0x82785408
	goto loc_82785408;
loc_82785400:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,20312
	ctx.r10.s64 = r11.s64 + 20312;
loc_82785408:
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r11,28(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 28);
	// stw r10,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82785428
	if (!cr6.eq) goto loc_82785428;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82784b88
	ctx.lr = 0x82785428;
	sub_82784B88(ctx, base);
loc_82785428:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82785470
	if (!cr6.eq) goto loc_82785470;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82784d10
	ctx.lr = 0x8278543C;
	sub_82784D10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82785444:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82785464
	if (!cr6.eq) goto loc_82785464;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,20168
	ctx.r10.s64 = r11.s64 + 20168;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82785464:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,20024
	ctx.r10.s64 = r11.s64 + 20024;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
loc_82785470:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82785478"))) PPC_WEAK_FUNC(sub_82785478);
PPC_FUNC_IMPL(__imp__sub_82785478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,46
	ctx.r10.s64 = 46;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82785494"))) PPC_WEAK_FUNC(sub_82785494);
PPC_FUNC_IMPL(__imp__sub_82785494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82785498"))) PPC_WEAK_FUNC(sub_82785498);
PPC_FUNC_IMPL(__imp__sub_82785498) {
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
	// li r5,88
	ctx.r5.s64 = 88;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827854C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// stw r3,424(r31)
	PPC_STORE_U32(r31.u32 + 424, ctx.r3.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r9,21272
	ctx.r6.s64 = ctx.r9.s64 + 21272;
	// addi r5,r8,0
	ctx.r5.s64 = ctx.r8.s64 + 0;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// addi r4,r7,21624
	ctx.r4.s64 = ctx.r7.s64 + 21624;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// ble cr6,0x82785530
	if (!cr6.gt) goto loc_82785530;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,55
	ctx.r10.s64 = 55;
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82785530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82785530:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x82785568
	if (!cr6.gt) goto loc_82785568;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,57
	ctx.r10.s64 = 57;
	// li r9,256
	ctx.r9.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82785568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82785568:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827849e8
	ctx.lr = 0x82785570;
	sub_827849E8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82784b88
	ctx.lr = 0x82785578;
	sub_82784B88(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8278558c
	if (!cr6.eq) goto loc_8278558C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827852a8
	ctx.lr = 0x8278558C;
	sub_827852A8(ctx, base);
loc_8278558C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827855A0"))) PPC_WEAK_FUNC(sub_827855A0);
PPC_FUNC_IMPL(__imp__sub_827855A0) {
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
	ctx.lr = 0x827855A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r31,320(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// lwz r11,224(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 224);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x827856a0
	if (!cr6.lt) goto loc_827856A0;
	// addi r28,r31,12
	r28.s64 = r31.s64 + 12;
	// li r27,0
	r27.s64 = 0;
loc_827855D8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bge cr6,0x82785610
	if (!cr6.lt) goto loc_82785610;
	// lwz r11,324(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 324);
	// li r9,8
	ctx.r9.s64 = 8;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// addi r7,r31,24
	ctx.r7.s64 = r31.s64 + 24;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82785610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82785610:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x827856a0
	if (!cr6.eq) goto loc_827856A0;
	// lwz r11,328(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 328);
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82785634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82785684
	if (cr6.eq) goto loc_82785684;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278565c
	if (cr6.eq) goto loc_8278565C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// stb r27,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r27.u8);
loc_8278565C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r27,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r27.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r9,224(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 224);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x827855d8
	if (cr6.lt) goto loc_827855D8;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82785684:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827856a0
	if (!cr6.eq) goto loc_827856A0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
loc_827856A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827856A8"))) PPC_WEAK_FUNC(sub_827856A8);
PPC_FUNC_IMPL(__imp__sub_827856A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// lwz r11,320(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r4,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stb r10,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r10.u8);
	// beq cr6,0x827856ec
	if (cr6.eq) goto loc_827856EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_827856EC:
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r10,21920
	ctx.r9.s64 = ctx.r10.s64 + 21920;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827856FC"))) PPC_WEAK_FUNC(sub_827856FC);
PPC_FUNC_IMPL(__imp__sub_827856FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82785700"))) PPC_WEAK_FUNC(sub_82785700);
PPC_FUNC_IMPL(__imp__sub_82785700) {
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
	ctx.lr = 0x82785708;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278572C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// stw r3,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r3.u32);
	// addi r8,r9,22184
	ctx.r8.s64 = ctx.r9.s64 + 22184;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lbz r7,176(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x827857dc
	if (!cr6.eq) goto loc_827857DC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278577c
	if (cr6.eq) goto loc_8278577C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82785774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8278577C:
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x827857dc
	if (!cr6.gt) goto loc_827857DC;
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
	// addi r29,r3,24
	r29.s64 = ctx.r3.s64 + 24;
loc_82785798:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,-16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r9,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827857C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,60(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r28,r7
	cr6.compare<int32_t>(r28.s32, ctx.r7.s32, xer);
	// blt cr6,0x82785798
	if (cr6.lt) goto loc_82785798;
loc_827857DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827857E4"))) PPC_WEAK_FUNC(sub_827857E4);
PPC_FUNC_IMPL(__imp__sub_827857E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827857E8"))) PPC_WEAK_FUNC(sub_827857E8);
PPC_FUNC_IMPL(__imp__sub_827857E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,228(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 228);
	// lwz r11,328(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x82785810
	if (!cr6.gt) goto loc_82785810;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
loc_82785810:
	// lwz r10,224(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x82785840
	if (!cr6.lt) goto loc_82785840;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// blr 
	return;
loc_82785840:
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82785858"))) PPC_WEAK_FUNC(sub_82785858);
PPC_FUNC_IMPL(__imp__sub_82785858) {
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
	ctx.lr = 0x82785860;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// li r19,0
	r19.s64 = 0;
	// lwz r11,248(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 248);
	// lwz r29,328(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 328);
	// addi r15,r11,-1
	r15.s64 = r11.s64 + -1;
	// lwz r11,224(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 224);
	// addi r14,r11,-1
	r14.s64 = r11.s64 + -1;
	// lwz r17,16(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpw cr6,r17,r11
	cr6.compare<int32_t>(r17.s32, r11.s32, xer);
	// bge cr6,0x82785a88
	if (!cr6.lt) goto loc_82785A88;
loc_82785894:
	// lwz r21,12(r29)
	r21.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplw cr6,r21,r15
	cr6.compare<uint32_t>(r21.u32, r15.u32, xer);
	// bgt cr6,0x82785a74
	if (cr6.gt) goto loc_82785A74;
loc_827858A0:
	// lwz r11,228(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 228);
	// mr r28,r19
	r28.u64 = r19.u64;
	// mr r16,r19
	r16.u64 = r19.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82785a44
	if (!cr6.gt) goto loc_82785A44;
	// rlwinm r18,r17,3,0,28
	r18.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r20,r24,232
	r20.s64 = r24.s64 + 232;
loc_827858BC:
	// lwz r31,0(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplw cr6,r21,r15
	cr6.compare<uint32_t>(r21.u32, r15.u32, xer);
	// bge cr6,0x827858d0
	if (!cr6.lt) goto loc_827858D0;
	// lwz r27,52(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x827858d4
	goto loc_827858D4;
loc_827858D0:
	// lwz r27,68(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 68);
loc_827858D4:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r26,r18
	r26.u64 = r18.u64;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r25,r19
	r25.u64 = r19.u64;
	// mullw r23,r11,r21
	r23.s64 = int64_t(r11.s32) * int64_t(r21.s32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82785a30
	if (!cr6.gt) goto loc_82785A30;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_827858F4:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r10,r14
	cr6.compare<uint32_t>(ctx.r10.u32, r14.u32, xer);
	// blt cr6,0x8278596c
	if (cr6.lt) goto loc_8278596C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r9,r25,r17
	ctx.r9.u64 = r25.u64 + r17.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x8278596c
	if (cr6.lt) goto loc_8278596C;
	// addi r10,r28,6
	ctx.r10.s64 = r28.s64 + 6;
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x82785928;
	sub_8277A3E8(ctx, base);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r11,r19
	r11.u64 = r19.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82785a14
	if (!cr6.gt) goto loc_82785A14;
	// addi r9,r28,5
	ctx.r9.s64 = r28.s64 + 5;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_82785944:
	// lwzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x82785944
	if (cr6.lt) goto loc_82785944;
	// b 0x82785a14
	goto loc_82785A14;
loc_8278596C:
	// addi r10,r28,6
	ctx.r10.s64 = r28.s64 + 6;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r6,344(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 344);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r6,r5,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + r29.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwzx r5,r11,r22
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r22.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827859A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bge cr6,0x82785a14
	if (!cr6.lt) goto loc_82785A14;
	// add r10,r27,r28
	ctx.r10.u64 = r27.u64 + r28.u64;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x827859D0;
	sub_8277A3E8(ctx, base);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// cmpw cr6,r27,r8
	cr6.compare<int32_t>(r27.s32, ctx.r8.s32, xer);
	// bge cr6,0x82785a14
	if (!cr6.lt) goto loc_82785A14;
	// add r11,r27,r28
	r11.u64 = r27.u64 + r28.u64;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
loc_827859F0:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// sth r7,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x827859f0
	if (cr6.lt) goto loc_827859F0;
loc_82785A14:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// blt cr6,0x827858f4
	if (cr6.lt) goto loc_827858F4;
loc_82785A30:
	// lwz r11,228(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 228);
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// cmpw cr6,r16,r11
	cr6.compare<int32_t>(r16.s32, r11.s32, xer);
	// blt cr6,0x827858bc
	if (cr6.lt) goto loc_827858BC;
loc_82785A44:
	// lwz r11,348(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 348);
	// addi r4,r29,24
	ctx.r4.s64 = r29.s64 + 24;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82785A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82785ac0
	if (cr6.eq) goto loc_82785AC0;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// cmplw cr6,r21,r15
	cr6.compare<uint32_t>(r21.u32, r15.u32, xer);
	// ble cr6,0x827858a0
	if (!cr6.gt) goto loc_827858A0;
loc_82785A74:
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// stw r19,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r19.u32);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpw cr6,r17,r11
	cr6.compare<int32_t>(r17.s32, r11.s32, xer);
	// blt cr6,0x82785894
	if (cr6.lt) goto loc_82785894;
loc_82785A88:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// lwz r10,228(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 228);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lwz r11,328(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 328);
	// ble cr6,0x82785ad4
	if (!cr6.gt) goto loc_82785AD4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r19,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r19.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r19,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r19.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_82785AC0:
	// stw r17,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r17.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r21,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r21.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_82785AD4:
	// lwz r10,224(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 224);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,232(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 232);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x82785af4
	if (!cr6.lt) goto loc_82785AF4;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82785af8
	goto loc_82785AF8;
loc_82785AF4:
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
loc_82785AF8:
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r19,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r19.u32);
	// stw r19,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r19.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82785B10"))) PPC_WEAK_FUNC(sub_82785B10);
PPC_FUNC_IMPL(__imp__sub_82785B10) {
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
	ctx.lr = 0x82785B18;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// lwz r11,228(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// lwz r27,328(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 328);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82785b98
	if (!cr6.gt) goto loc_82785B98;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,232
	r31.s64 = r28.s64 + 232;
loc_82785B40:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r11,32(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r5,r8,r5
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82785B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,228(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x82785b40
	if (cr6.lt) goto loc_82785B40;
loc_82785B98:
	// lwz r23,16(r27)
	r23.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// bge cr6,0x82785cbc
	if (!cr6.lt) goto loc_82785CBC;
	// rlwinm r24,r23,2,0,29
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
loc_82785BAC:
	// lwz r26,12(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r11,248(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 248);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bge cr6,0x82785ca4
	if (!cr6.lt) goto loc_82785CA4;
	// addi r22,r27,24
	r22.s64 = r27.s64 + 24;
loc_82785BC0:
	// lwz r11,228(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82785c70
	if (!cr6.gt) goto loc_82785C70;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,232
	r31.s64 = r28.s64 + 232;
loc_82785BDC:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// lwz r10,56(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mullw r11,r8,r26
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r26.s32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82785c58
	if (!cr6.gt) goto loc_82785C58;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r5,r24,r10
	ctx.r5.u64 = r24.u64 + ctx.r10.u64;
loc_82785C04:
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// ble cr6,0x82785c44
	if (!cr6.gt) goto loc_82785C44;
	// addi r11,r6,6
	r11.s64 = ctx.r6.s64 + 6;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_82785C24:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82785c24
	if (cr6.lt) goto loc_82785C24;
loc_82785C44:
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x82785c04
	if (cr6.lt) goto loc_82785C04;
loc_82785C58:
	// lwz r11,228(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82785bdc
	if (cr6.lt) goto loc_82785BDC;
loc_82785C70:
	// lwz r11,348(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 348);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82785C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82785cf4
	if (cr6.eq) goto loc_82785CF4;
	// lwz r11,248(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 248);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x82785bc0
	if (cr6.lt) goto loc_82785BC0;
loc_82785CA4:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// stw r25,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r25.u32);
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82785bac
	if (cr6.lt) goto loc_82785BAC;
loc_82785CBC:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r11.u32);
	// lwz r10,228(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lwz r11,328(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 328);
	// ble cr6,0x82785d08
	if (!cr6.gt) goto loc_82785D08;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r25,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r25,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r25.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_82785CF4:
	// stw r23,16(r27)
	PPC_STORE_U32(r27.u32 + 16, r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r26,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_82785D08:
	// lwz r10,224(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 224);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x82785d28
	if (!cr6.lt) goto loc_82785D28;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82785d2c
	goto loc_82785D2C;
loc_82785D28:
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
loc_82785D2C:
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r25,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r25.u32);
	// stw r25,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r25.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82785D44"))) PPC_WEAK_FUNC(sub_82785D44);
PPC_FUNC_IMPL(__imp__sub_82785D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82785D48"))) PPC_WEAK_FUNC(sub_82785D48);
PPC_FUNC_IMPL(__imp__sub_82785D48) {
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
	ctx.lr = 0x82785D50;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r16,r4
	r16.u64 = ctx.r4.u64;
	// li r18,0
	r18.s64 = 0;
	// lwz r11,224(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 224);
	// lwz r10,60(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 60);
	// lwz r19,328(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 328);
	// addi r17,r11,-1
	r17.s64 = r11.s64 + -1;
	// lwz r23,68(r22)
	r23.u64 = PPC_LOAD_U32(r22.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82785f58
	if (!cr6.gt) goto loc_82785F58;
	// mr r21,r16
	r21.u64 = r16.u64;
	// addi r20,r19,64
	r20.s64 = r19.s64 + 64;
loc_82785D84:
	// lwz r11,4(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r9,8(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// lwz r4,0(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// mullw r5,r10,r9
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82785DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,8(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplw cr6,r7,r17
	cr6.compare<uint32_t>(ctx.r7.u32, r17.u32, xer);
	// bge cr6,0x82785dc8
	if (!cr6.lt) goto loc_82785DC8;
	// lwz r26,12(r23)
	r26.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// b 0x82785de8
	goto loc_82785DE8;
loc_82785DC8:
	// lwz r11,12(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// lwz r10,32(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 32);
	// twllei r11,0
	// divwu r9,r10,r11
	ctx.r9.u32 = ctx.r10.u32 / r11.u32;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf. r26,r8,r10
	r26.s64 = ctx.r10.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bne 0x82785de8
	if (!cr0.eq) goto loc_82785DE8;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_82785DE8:
	// lwz r25,8(r23)
	r25.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// lwz r29,28(r23)
	r29.u64 = PPC_LOAD_U32(r23.u32 + 28);
	// twllei r25,0
	// divwu r11,r29,r25
	r11.u32 = r29.u32 / r25.u32;
	// mullw r10,r11,r25
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r25.s32);
	// subf. r30,r10,r29
	r30.s64 = r29.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// ble 0x82785e08
	if (!cr0.gt) goto loc_82785E08;
	// subf r30,r30,r25
	r30.s64 = r25.s64 - r30.s64;
loc_82785E08:
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82785e98
	if (!cr6.gt) goto loc_82785E98;
	// mr r27,r24
	r27.u64 = r24.u64;
loc_82785E18:
	// lwz r11,344(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 344);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,0(r21)
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r7,r28,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82785E48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82785e88
	if (!cr6.gt) goto loc_82785E88;
	// rlwinm r11,r29,7,0,24
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r4,r30,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 7) & 0xFFFFFF80;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a3e8
	ctx.lr = 0x82785E64;
	sub_8277A3E8(ctx, base);
	// lhz r9,-128(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + -128);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82785e88
	if (!cr6.gt) goto loc_82785E88;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82785E78:
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// bne 0x82785e78
	if (!cr0.eq) goto loc_82785E78;
loc_82785E88:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// blt cr6,0x82785e18
	if (cr6.lt) goto loc_82785E18;
loc_82785E98:
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// bne cr6,0x82785f3c
	if (!cr6.eq) goto loc_82785F3C;
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// add r11,r30,r29
	r11.u64 = r30.u64 + r29.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// divwu r28,r11,r25
	r28.u32 = r11.u32 / r25.u32;
	// twllei r25,0
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// bge cr6,0x82785f3c
	if (!cr6.lt) goto loc_82785F3C;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r11,7,0,24
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r29,r10,r24
	r29.u64 = ctx.r10.u64 + r24.u64;
loc_82785ECC:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r30,-4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a3e8
	ctx.lr = 0x82785EE0;
	sub_8277A3E8(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82785f28
	if (cr6.eq) goto loc_82785F28;
	// rlwinm r7,r25,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 7) & 0xFFFFFF80;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// addi r6,r7,-128
	ctx.r6.s64 = ctx.r7.s64 + -128;
loc_82785EF4:
	// lhzx r9,r6,r30
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + r30.u32);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82785f18
	if (!cr6.gt) goto loc_82785F18;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82785F08:
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// bne 0x82785f08
	if (!cr0.eq) goto loc_82785F08;
loc_82785F18:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r31,r7,r31
	r31.u64 = ctx.r7.u64 + r31.u64;
	// add r30,r7,r30
	r30.u64 = ctx.r7.u64 + r30.u64;
	// bne 0x82785ef4
	if (!cr0.eq) goto loc_82785EF4;
loc_82785F28:
	// lwz r11,12(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82785ecc
	if (cr6.lt) goto loc_82785ECC;
loc_82785F3C:
	// lwz r11,60(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 60);
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r23,r23,84
	r23.s64 = r23.s64 + 84;
	// cmpw cr6,r18,r11
	cr6.compare<int32_t>(r18.s32, r11.s32, xer);
	// blt cr6,0x82785d84
	if (cr6.lt) goto loc_82785D84;
loc_82785F58:
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82785b10
	ctx.lr = 0x82785F64;
	sub_82785B10(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82785F6C"))) PPC_WEAK_FUNC(sub_82785F6C);
PPC_FUNC_IMPL(__imp__sub_82785F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82785F70"))) PPC_WEAK_FUNC(sub_82785F70);
PPC_FUNC_IMPL(__imp__sub_82785F70) {
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
	// lwz r31,328(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x827857e8
	ctx.lr = 0x82785F90;
	sub_827857E8(ctx, base);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82786040
	if (cr6.eq) goto loc_82786040;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8278600c
	if (cr6.eq) goto loc_8278600C;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x82785fd8
	if (cr6.eq) goto loc_82785FD8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82785FC4;
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
loc_82785FD8:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786000
	if (!cr6.eq) goto loc_82786000;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82786000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786000:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,23880
	ctx.r10.s64 = r11.s64 + 23880;
	// b 0x82786070
	goto loc_82786070;
loc_8278600C:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786034
	if (!cr6.eq) goto loc_82786034;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82786034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786034:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,23312
	ctx.r10.s64 = r11.s64 + 23312;
	// b 0x82786070
	goto loc_82786070;
loc_82786040:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786068
	if (cr6.eq) goto loc_82786068;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82786068;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786068:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,22616
	ctx.r10.s64 = r11.s64 + 22616;
loc_82786070:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82786088"))) PPC_WEAK_FUNC(sub_82786088);
PPC_FUNC_IMPL(__imp__sub_82786088) {
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
	ctx.lr = 0x82786090;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827860B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// stw r29,328(r30)
	PPC_STORE_U32(r30.u32 + 328, r29.u32);
	// addi r7,r9,24432
	ctx.r7.s64 = ctx.r9.s64 + 24432;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// beq cr6,0x8278615c
	if (cr6.eq) goto loc_8278615C;
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x827861cc
	if (!cr6.gt) goto loc_827861CC;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
	// addi r29,r29,64
	r29.s64 = r29.s64 + 64;
loc_827860F0:
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r26,4(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8277a348
	ctx.lr = 0x82786104;
	sub_8277A348(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8277a348
	ctx.lr = 0x82786114;
	sub_8277A348(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82786138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x827860f0
	if (cr6.lt) goto loc_827860F0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8278615C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1280
	ctx.r5.s64 = 1280;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82786178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r3,128
	ctx.r8.s64 = ctx.r3.s64 + 128;
	// addi r7,r3,256
	ctx.r7.s64 = ctx.r3.s64 + 256;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// stw r8,28(r29)
	PPC_STORE_U32(r29.u32 + 28, ctx.r8.u32);
	// addi r6,r3,384
	ctx.r6.s64 = ctx.r3.s64 + 384;
	// stw r7,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r7.u32);
	// addi r5,r3,512
	ctx.r5.s64 = ctx.r3.s64 + 512;
	// addi r4,r3,640
	ctx.r4.s64 = ctx.r3.s64 + 640;
	// stw r6,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r6.u32);
	// addi r11,r3,768
	r11.s64 = ctx.r3.s64 + 768;
	// stw r5,40(r29)
	PPC_STORE_U32(r29.u32 + 40, ctx.r5.u32);
	// addi r10,r3,896
	ctx.r10.s64 = ctx.r3.s64 + 896;
	// stw r4,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r4.u32);
	// addi r8,r3,1024
	ctx.r8.s64 = ctx.r3.s64 + 1024;
	// stw r11,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r11.u32);
	// addi r7,r3,1152
	ctx.r7.s64 = ctx.r3.s64 + 1152;
	// stw r10,52(r29)
	PPC_STORE_U32(r29.u32 + 52, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r8.u32);
	// stw r7,60(r29)
	PPC_STORE_U32(r29.u32 + 60, ctx.r7.u32);
	// stw r9,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r9.u32);
loc_827861CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827861D4"))) PPC_WEAK_FUNC(sub_827861D4);
PPC_FUNC_IMPL(__imp__sub_827861D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827861D8"))) PPC_WEAK_FUNC(sub_827861D8);
PPC_FUNC_IMPL(__imp__sub_827861D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x827861E0;
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r28,50
	r28.s64 = 50;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82786208
	if (cr6.lt) goto loc_82786208;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x8278622c
	if (cr6.lt) goto loc_8278622C;
loc_82786208:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8278622C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278622C:
	// clrlwi r26,r30,24
	r26.u64 = r30.u32 & 0xFF;
	// addi r11,r31,22
	r11.s64 = r31.s64 + 22;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82786240
	if (!cr6.eq) goto loc_82786240;
	// addi r11,r31,26
	r11.s64 = r31.s64 + 26;
loc_82786240:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r10,r24
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82786274
	if (!cr6.eq) goto loc_82786274;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82786274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786274:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827862a0
	if (!cr6.eq) goto loc_827862A0;
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// li r5,1280
	ctx.r5.s64 = 1280;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278629C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_827862A0:
	// li r28,1
	r28.s64 = 1;
	// lwz r23,0(r29)
	r23.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// li r22,8
	r22.s64 = 8;
loc_827862B4:
	// lbzx r31,r30,r27
	r31.u64 = PPC_LOAD_U8(r30.u32 + r27.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x827862cc
	if (cr6.lt) goto loc_827862CC;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x827862e8
	if (!cr6.gt) goto loc_827862E8;
loc_827862CC:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827862E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827862E8:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82786318
	if (cr6.eq) goto loc_82786318;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// extsb r10,r30
	ctx.r10.s64 = r30.s8;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82786314
	if (cr6.eq) goto loc_82786314;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_82786308:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82786308
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786308;
loc_82786314:
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
loc_82786318:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// ble cr6,0x827862b4
	if (!cr6.gt) goto loc_827862B4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r25,r29
	r25.u64 = r29.u64;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// stbx r10,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, ctx.r10.u8);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r29,r9
	r29.s64 = ctx.r9.s8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x827863d4
	if (cr6.eq) goto loc_827863D4;
loc_8278634C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// bne cr6,0x82786394
	if (!cr6.eq) goto loc_82786394;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_82786370:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x82786370
	if (cr6.eq) goto loc_82786370;
loc_82786394:
	// slw r11,r28,r29
	r11.u64 = r29.u8 & 0x20 ? 0 : (r28.u32 << (r29.u8 & 0x3F));
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827863bc
	if (cr6.lt) goto loc_827863BC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827863BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827863BC:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8278634c
	if (!cr6.eq) goto loc_8278634C;
loc_827863D4:
	// addi r28,r23,1024
	r28.s64 = r23.s64 + 1024;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d9890
	ctx.lr = 0x827863E8;
	sub_823D9890(ctx, base);
	// subfic r11,r26,0
	xer.ca = r26.u32 <= 0;
	r11.s64 = 0 - r26.s64;
	// li r31,0
	r31.s64 = 0;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// rlwinm r11,r10,0,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r11,r11,0,27,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF1F;
	// addi r26,r11,255
	r26.s64 = r11.s64 + 255;
	// ble cr6,0x82786474
	if (!cr6.gt) goto loc_82786474;
	// addi r29,r1,352
	r29.s64 = ctx.r1.s64 + 352;
	// addi r27,r27,17
	r27.s64 = r27.s64 + 17;
loc_82786410:
	// lbzx r30,r27,r31
	r30.u64 = PPC_LOAD_U8(r27.u32 + r31.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82786430
	if (cr6.lt) goto loc_82786430;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// bgt cr6,0x82786430
	if (cr6.gt) goto loc_82786430;
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278644c
	if (cr6.eq) goto loc_8278644C;
loc_82786430:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8278644C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278644C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lbzx r8,r31,r11
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stwx r10,r9,r23
	PPC_STORE_U32(ctx.r9.u32 + r23.u32, ctx.r10.u32);
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// stbx r8,r28,r30
	PPC_STORE_U8(r28.u32 + r30.u32, ctx.r8.u8);
	// blt cr6,0x82786410
	if (cr6.lt) goto loc_82786410;
loc_82786474:
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8278647C"))) PPC_WEAK_FUNC(sub_8278647C);
PPC_FUNC_IMPL(__imp__sub_8278647C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82786480"))) PPC_WEAK_FUNC(sub_82786480);
PPC_FUNC_IMPL(__imp__sub_82786480) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r30,24(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827864AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827864c0
	if (!cr6.eq) goto loc_827864C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827864d4
	goto loc_827864D4;
loc_827864C0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_827864D4:
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

__attribute__((alias("__imp__sub_827864EC"))) PPC_WEAK_FUNC(sub_827864EC);
PPC_FUNC_IMPL(__imp__sub_827864EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827864F0"))) PPC_WEAK_FUNC(sub_827864F0);
PPC_FUNC_IMPL(__imp__sub_827864F0) {
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
	ctx.lr = 0x827864F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bne cr6,0x82786538
	if (!cr6.eq) goto loc_82786538;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,40
	ctx.r10.s64 = 40;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82786538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786538:
	// li r11,1
	r11.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r28,r28,r30
	r28.u64 = r28.u64 + r30.u64;
	// slw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// subfic r8,r28,24
	xer.ca = r28.u32 <= 24;
	ctx.r8.s64 = 24 - r28.s64;
	// and r7,r9,r29
	ctx.r7.u64 = ctx.r9.u64 & r29.u64;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// slw r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// or r27,r6,r10
	r27.u64 = ctx.r6.u64 | ctx.r10.u64;
	// blt cr6,0x82786660
	if (cr6.lt) goto loc_82786660;
	// li r26,0
	r26.s64 = 0;
loc_82786568:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// srawi r10,r27,16
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = r27.s32 >> 16;
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x827865dc
	if (!cr0.eq) goto loc_827865DC;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r30,24(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827865A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827865bc
	if (!cr6.eq) goto loc_827865BC;
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x827865d0
	goto loc_827865D0;
loc_827865BC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_827865D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786674
	if (cr6.eq) goto loc_82786674;
loc_827865DC:
	// cmpwi cr6,r29,255
	cr6.compare<int32_t>(r29.s32, 255, xer);
	// bne cr6,0x82786650
	if (!cr6.eq) goto loc_82786650;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r26,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r26.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x82786650
	if (!cr0.eq) goto loc_82786650;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r30,24(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8278661C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82786630
	if (!cr6.eq) goto loc_82786630;
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82786644
	goto loc_82786644;
loc_82786630:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_82786644:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786674
	if (cr6.eq) goto loc_82786674;
loc_82786650:
	// addi r28,r28,-8
	r28.s64 = r28.s64 + -8;
	// rlwinm r27,r27,8,0,23
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 8) & 0xFFFFFF00;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bge cr6,0x82786568
	if (!cr6.lt) goto loc_82786568;
loc_82786660:
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82786674:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82786680"))) PPC_WEAK_FUNC(sub_82786680);
PPC_FUNC_IMPL(__imp__sub_82786680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82786688;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r11,0(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// subf. r30,r5,r10
	r30.s64 = ctx.r10.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bge 0x827866b8
	if (!cr0.lt) goto loc_827866B8;
	// neg r11,r30
	r11.s64 = -r30.s64;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
loc_827866B8:
	// li r31,0
	r31.s64 = 0;
	// li r23,6
	r23.s64 = 6;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827866fc
	if (cr6.eq) goto loc_827866FC;
loc_827866C8:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x827866c8
	if (!cr0.eq) goto loc_827866C8;
	// cmpwi cr6,r31,11
	cr6.compare<int32_t>(r31.s32, 11, xer);
	// ble cr6,0x827866fc
	if (!cr6.gt) goto loc_827866FC;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r23,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r23.u32);
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827866FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827866FC:
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r9,1024(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1024);
	// lwzx r4,r10,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// extsb r5,r9
	ctx.r5.s64 = ctx.r9.s8;
	// bl 0x827864f0
	ctx.lr = 0x82786718;
	sub_827864F0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82786730
	if (!cr6.eq) goto loc_82786730;
loc_82786724:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_82786730:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82786754
	if (cr6.eq) goto loc_82786754;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827864f0
	ctx.lr = 0x82786748;
	sub_827864F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786724
	if (cr6.eq) goto loc_82786724;
loc_82786754:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r30,0
	r30.s64 = 0;
	// addi r25,r11,-31424
	r25.s64 = r11.s64 + -31424;
	// addi r26,r25,4
	r26.s64 = r25.s64 + 4;
loc_82786764:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r24
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r24.u32);
	// extsh r31,r9
	r31.s64 = ctx.r9.s16;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82786784
	if (!cr6.eq) goto loc_82786784;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x8278685c
	goto loc_8278685C;
loc_82786784:
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// ble cr6,0x827867b8
	if (!cr6.gt) goto loc_827867B8;
loc_8278678C:
	// lbz r11,1264(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1264);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,960(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 960);
	// extsb r5,r11
	ctx.r5.s64 = r11.s8;
	// bl 0x827864f0
	ctx.lr = 0x827867A0;
	sub_827864F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82786724
	if (cr6.eq) goto loc_82786724;
	// addi r30,r30,-16
	r30.s64 = r30.s64 + -16;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// bgt cr6,0x8278678c
	if (cr6.gt) goto loc_8278678C;
loc_827867B8:
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x827867cc
	if (!cr6.lt) goto loc_827867CC;
	// neg r31,r31
	r31.s64 = -r31.s64;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
loc_827867CC:
	// srawi. r11,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	r11.s64 = r31.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r31,1
	r31.s64 = 1;
	// beq 0x8278680c
	if (cr0.eq) goto loc_8278680C;
loc_827867D8:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x827867d8
	if (!cr0.eq) goto loc_827867D8;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// ble cr6,0x8278680c
	if (!cr6.gt) goto loc_8278680C;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r23,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r23.u32);
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8278680C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278680C:
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r8,1024(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1024);
	// lwzx r4,r9,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// bl 0x827864f0
	ctx.lr = 0x82786830;
	sub_827864F0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82786724
	if (cr6.eq) goto loc_82786724;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827864f0
	ctx.lr = 0x8278684C;
	sub_827864F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786724
	if (cr6.eq) goto loc_82786724;
	// li r30,0
	r30.s64 = 0;
loc_8278685C:
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r11,r25,256
	r11.s64 = r25.s64 + 256;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82786764
	if (cr6.lt) goto loc_82786764;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82786898
	if (!cr6.gt) goto loc_82786898;
	// lbz r11,1024(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1024);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// extsb r5,r11
	ctx.r5.s64 = r11.s8;
	// bl 0x827864f0
	ctx.lr = 0x82786888;
	sub_827864F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8278689c
	if (cr6.eq) goto loc_8278689C;
loc_82786898:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8278689C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827868A4"))) PPC_WEAK_FUNC(sub_827868A4);
PPC_FUNC_IMPL(__imp__sub_827868A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827868A8"))) PPC_WEAK_FUNC(sub_827868A8);
PPC_FUNC_IMPL(__imp__sub_827868A8) {
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
	ctx.lr = 0x827868B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827864f0
	ctx.lr = 0x827868C8;
	sub_827864F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827868e0
	if (!cr6.eq) goto loc_827868E0;
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x827868ec
	goto loc_827868EC;
loc_827868E0:
	// li r11,1
	r11.s64 = 1;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_827868EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786904
	if (!cr6.eq) goto loc_82786904;
loc_827868F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82786904:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne 0x82786940
	if (!cr0.eq) goto loc_82786940;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82786480
	ctx.lr = 0x82786934;
	sub_82786480(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827868f8
	if (cr6.eq) goto loc_827868F8;
loc_82786940:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r29,208
	ctx.r10.s64 = r29.s64 + 208;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addic. r11,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r11.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x8278697c
	if (!cr0.eq) goto loc_8278697C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82786480
	ctx.lr = 0x82786970;
	sub_82786480(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827868f8
	if (cr6.eq) goto loc_827868F8;
loc_8278697C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r9,228(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 228);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827869b0
	if (!cr6.gt) goto loc_827869B0;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
loc_82786994:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,228(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 228);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82786994
	if (cr6.lt) goto loc_82786994;
loc_827869B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827869BC"))) PPC_WEAK_FUNC(sub_827869BC);
PPC_FUNC_IMPL(__imp__sub_827869BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827869C0"))) PPC_WEAK_FUNC(sub_827869C0);
PPC_FUNC_IMPL(__imp__sub_827869C0) {
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
	ctx.lr = 0x827869C8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r26,348(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// addi r24,r26,12
	r24.s64 = r26.s64 + 12;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r24
	r11.u64 = r24.u64;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82786A00:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82786a00
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786A00;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786a54
	if (cr6.eq) goto loc_82786A54;
	// lwz r11,36(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786a54
	if (!cr6.eq) goto loc_82786A54;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,40(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// bl 0x827868a8
	ctx.lr = 0x82786A3C;
	sub_827868A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786a54
	if (!cr6.eq) goto loc_82786A54;
loc_82786A48:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_82786A54:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82786ae4
	if (!cr6.gt) goto loc_82786AE4;
	// addi r27,r31,260
	r27.s64 = r31.s64 + 260;
loc_82786A68:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,58
	ctx.r10.s64 = r11.s64 + 58;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r28,r29
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwz r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// addi r7,r10,15
	ctx.r7.s64 = ctx.r10.s64 + 15;
	// addi r6,r11,11
	ctx.r6.s64 = r11.s64 + 11;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r11,r26
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// lwzx r6,r10,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x82786680
	ctx.lr = 0x82786AB0;
	sub_82786680(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82786a48
	if (cr6.eq) goto loc_82786A48;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// stwx r8,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r8.u32);
	// blt cr6,0x82786a68
	if (cr6.lt) goto loc_82786A68;
loc_82786AE4:
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r6,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82786B0C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82786b0c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786B0C;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786b58
	if (cr6.eq) goto loc_82786B58;
	// lwz r10,36(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82786b4c
	if (!cr6.eq) goto loc_82786B4C;
	// lwz r10,40(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// stw r11,36(r26)
	PPC_STORE_U32(r26.u32 + 36, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stw r10,40(r26)
	PPC_STORE_U32(r26.u32 + 40, ctx.r10.u32);
loc_82786B4C:
	// lwz r11,36(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 36);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,36(r26)
	PPC_STORE_U32(r26.u32 + 36, r11.u32);
loc_82786B58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82786B64"))) PPC_WEAK_FUNC(sub_82786B64);
PPC_FUNC_IMPL(__imp__sub_82786B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82786B68"))) PPC_WEAK_FUNC(sub_82786B68);
PPC_FUNC_IMPL(__imp__sub_82786B68) {
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
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82786BAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82786bac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786BAC;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,127
	ctx.r4.s64 = 127;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827864f0
	ctx.lr = 0x82786BD4;
	sub_827864F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786bf0
	if (cr6.eq) goto loc_82786BF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_82786BF0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786c1c
	if (!cr6.eq) goto loc_82786C1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,24
	ctx.r10.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82786C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786C1C:
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r6,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82786C44:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82786c44
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786C44;
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

__attribute__((alias("__imp__sub_82786C70"))) PPC_WEAK_FUNC(sub_82786C70);
PPC_FUNC_IMPL(__imp__sub_82786C70) {
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
	ctx.lr = 0x82786C78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lhz r11,0(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 0);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// subf. r11,r5,r10
	r11.s64 = ctx.r10.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82786ca0
	if (!cr0.lt) goto loc_82786CA0;
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_82786CA0:
	// li r31,0
	r31.s64 = 0;
	// li r24,6
	r24.s64 = 6;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82786ce0
	if (cr6.eq) goto loc_82786CE0;
loc_82786CB0:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x82786cb0
	if (!cr0.eq) goto loc_82786CB0;
	// cmpwi cr6,r31,11
	cr6.compare<int32_t>(r31.s32, 11, xer);
	// ble cr6,0x82786ce0
	if (!cr6.gt) goto loc_82786CE0;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82786CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786CE0:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// li r31,0
	r31.s64 = 0;
	// addi r27,r10,-31424
	r27.s64 = ctx.r10.s64 + -31424;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
loc_82786D00:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r25.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82786d20
	if (!cr6.eq) goto loc_82786D20;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x82786dac
	goto loc_82786DAC;
loc_82786D20:
	// cmpwi cr6,r31,15
	cr6.compare<int32_t>(r31.s32, 15, xer);
	// ble cr6,0x82786d48
	if (!cr6.gt) goto loc_82786D48;
	// addi r11,r31,-16
	r11.s64 = r31.s64 + -16;
	// lwz r10,960(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 960);
	// rlwinm r11,r11,28,4,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// subf r31,r8,r31
	r31.s64 = r31.s64 - ctx.r8.s64;
	// stw r7,960(r29)
	PPC_STORE_U32(r29.u32 + 960, ctx.r7.u32);
loc_82786D48:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x82786d54
	if (!cr6.lt) goto loc_82786D54;
	// neg r9,r9
	ctx.r9.s64 = -ctx.r9.s64;
loc_82786D54:
	// srawi. r11,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	r11.s64 = ctx.r9.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r30,1
	r30.s64 = 1;
	// beq 0x82786d90
	if (cr0.eq) goto loc_82786D90;
loc_82786D60:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x82786d60
	if (!cr0.eq) goto loc_82786D60;
	// cmpwi cr6,r30,10
	cr6.compare<int32_t>(r30.s32, 10, xer);
	// ble cr6,0x82786d90
	if (!cr6.gt) goto loc_82786D90;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82786D90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82786D90:
	// rlwinm r11,r31,4,0,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// li r31,0
	r31.s64 = 0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
loc_82786DAC:
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r11,r27,256
	r11.s64 = r27.s64 + 256;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82786d00
	if (cr6.lt) goto loc_82786D00;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82786dd0
	if (!cr6.gt) goto loc_82786DD0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82786DD0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82786DD8"))) PPC_WEAK_FUNC(sub_82786DD8);
PPC_FUNC_IMPL(__imp__sub_82786DD8) {
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
	ctx.lr = 0x82786DE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r29,348(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82786e48
	if (cr6.eq) goto loc_82786E48;
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82786e3c
	if (!cr6.eq) goto loc_82786E3C;
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82786e34
	if (!cr6.gt) goto loc_82786E34;
	// addi r11,r29,20
	r11.s64 = r29.s64 + 20;
loc_82786E1C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82786e1c
	if (cr6.lt) goto loc_82786E1C;
loc_82786E34:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r11,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r11.u32);
loc_82786E3C:
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r11.u32);
loc_82786E48:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82786ecc
	if (!cr6.gt) goto loc_82786ECC;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,260
	r28.s64 = r31.s64 + 260;
loc_82786E5C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,58
	ctx.r10.s64 = r11.s64 + 58;
	// addi r9,r11,5
	ctx.r9.s64 = r11.s64 + 5;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r9,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r5,r27,r29
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// lwz r10,24(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// addi r6,r10,23
	ctx.r6.s64 = ctx.r10.s64 + 23;
	// addi r11,r11,19
	r11.s64 = r11.s64 + 19;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lwzx r6,r9,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// bl 0x82786c70
	ctx.lr = 0x82786EA4;
	sub_82786C70(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lhz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// stwx r6,r27,r29
	PPC_STORE_U32(r27.u32 + r29.u32, ctx.r6.u32);
	// lwz r5,256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpw cr6,r26,r5
	cr6.compare<int32_t>(r26.s32, ctx.r5.s32, xer);
	// blt cr6,0x82786e5c
	if (cr6.lt) goto loc_82786E5C;
loc_82786ECC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82786ED8"))) PPC_WEAK_FUNC(sub_82786ED8);
PPC_FUNC_IMPL(__imp__sub_82786ED8) {
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
	ctx.lr = 0x82786EE0;
	// stwu r1,-2272(r1)
	ea = -2272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	r26.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82786F04:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82786f04
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786F04;
	// li r5,1028
	ctx.r5.s64 = 1028;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d9890
	ctx.lr = 0x82786F24;
	sub_823D9890(ctx, base);
	// addi r11,r1,1168
	r11.s64 = ctx.r1.s64 + 1168;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r10,257
	ctx.r10.s64 = 257;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82786F34:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82786f34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82786F34;
	// li r11,1
	r11.s64 = 1;
	// stw r11,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r11.u32);
	// lis r11,15258
	r11.s64 = 999948288;
	// ori r30,r11,51712
	r30.u64 = r11.u64 | 51712;
loc_82786F50:
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
loc_82786F60:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82786f7c
	if (cr6.eq) goto loc_82786F7C;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bgt cr6,0x82786f7c
	if (cr6.gt) goto loc_82786F7C;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82786F7C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x82786f60
	if (!cr6.gt) goto loc_82786F60;
	// li r3,-1
	ctx.r3.s64 = -1;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
loc_82786F9C:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82786fc0
	if (cr6.eq) goto loc_82786FC0;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bgt cr6,0x82786fc0
	if (cr6.gt) goto loc_82786FC0;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x82786fc0
	if (cr6.eq) goto loc_82786FC0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_82786FC0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x82786f9c
	if (!cr6.gt) goto loc_82786F9C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827870a4
	if (cr6.lt) goto loc_827870A4;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,1168
	ctx.r10.s64 = ctx.r1.s64 + 1168;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwzx r6,r9,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r6.u32);
	// stwx r26,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, r26.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stwx r5,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r5.u32);
	// blt cr6,0x82787044
	if (cr6.lt) goto loc_82787044;
loc_82787018:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,1168
	ctx.r10.s64 = ctx.r1.s64 + 1168;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stwx r5,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r5.u32);
	// bge cr6,0x82787018
	if (!cr6.lt) goto loc_82787018;
loc_82787044:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,1168
	r11.s64 = ctx.r1.s64 + 1168;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r1,1168
	ctx.r6.s64 = ctx.r1.s64 + 1168;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// stwx r3,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r3.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// blt cr6,0x82786f50
	if (cr6.lt) goto loc_82786F50;
loc_82787074:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,1168
	r11.s64 = ctx.r1.s64 + 1168;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// bge cr6,0x82787074
	if (!cr6.lt) goto loc_82787074;
	// b 0x82786f50
	goto loc_82786F50;
loc_827870A4:
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// li r29,257
	r29.s64 = 257;
	// li r28,39
	r28.s64 = 39;
loc_827870B0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827870f0
	if (cr6.eq) goto loc_827870F0;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// ble cr6,0x827870e0
	if (!cr6.gt) goto loc_827870E0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827870E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827870E0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbx r10,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, ctx.r10.u8);
loc_827870F0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x827870b0
	if (!cr0.eq) goto loc_827870B0;
	// li r11,30
	r11.s64 = 30;
	// li r3,16
	ctx.r3.s64 = 16;
	// li r31,16
	r31.s64 = 16;
loc_82787108:
	// addi r7,r1,82
	ctx.r7.s64 = ctx.r1.s64 + 82;
	// lbzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8278718c
	if (cr6.eq) goto loc_8278718C;
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
loc_8278711C:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82787148
	if (!cr6.eq) goto loc_82787148;
loc_82787134:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82787134
	if (cr6.eq) goto loc_82787134;
loc_82787148:
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// addi r9,r1,81
	ctx.r9.s64 = ctx.r1.s64 + 81;
	// lbzx r6,r11,r4
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,254
	ctx.r5.s64 = ctx.r5.s64 + 254;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stbx r5,r11,r7
	PPC_STORE_U8(r11.u32 + ctx.r7.u32, ctx.r5.u8);
	// stbx r6,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r6.u8);
	// lbzx r6,r10,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// addi r6,r6,255
	ctx.r6.s64 = ctx.r6.s64 + 255;
	// lbzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// stbx r6,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, ctx.r6.u8);
	// stbx r5,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u8);
	// lbzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8278711c
	if (!cr6.eq) goto loc_8278711C;
loc_8278718C:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// bne 0x82787108
	if (!cr0.eq) goto loc_82787108;
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827871bc
	if (!cr6.eq) goto loc_827871BC;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_827871A8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827871a8
	if (cr6.eq) goto loc_827871A8;
loc_827871BC:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,17
	ctx.r5.s64 = 17;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stbx r10,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, ctx.r10.u8);
	// bl 0x823da950
	ctx.lr = 0x827871DC;
	sub_823DA950(ctx, base);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r8,1
	ctx.r8.s64 = 1;
loc_827871E4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
loc_827871EC:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bne cr6,0x82787204
	if (!cr6.eq) goto loc_82787204;
	// add r7,r10,r25
	ctx.r7.u64 = ctx.r10.u64 + r25.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,17(r7)
	PPC_STORE_U8(ctx.r7.u32 + 17, r11.u8);
loc_82787204:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x827871ec
	if (!cr6.gt) goto loc_827871EC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// ble cr6,0x827871e4
	if (!cr6.gt) goto loc_827871E4;
	// stb r26,273(r25)
	PPC_STORE_U8(r25.u32 + 273, r26.u8);
	// addi r1,r1,2272
	ctx.r1.s64 = ctx.r1.s64 + 2272;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8278722C"))) PPC_WEAK_FUNC(sub_8278722C);
PPC_FUNC_IMPL(__imp__sub_8278722C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82787230"))) PPC_WEAK_FUNC(sub_82787230);
PPC_FUNC_IMPL(__imp__sub_82787230) {
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
	ctx.lr = 0x82787238;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r23,r11
	r23.u64 = r11.u64;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r26,348(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// ble cr6,0x82787328
	if (!cr6.gt) goto loc_82787328;
	// addi r24,r31,232
	r24.s64 = r31.s64 + 232;
	// li r25,1
	r25.s64 = 1;
loc_82787270:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lwz r30,20(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r27,24(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lbzx r10,r30,r28
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827872c8
	if (!cr6.eq) goto loc_827872C8;
	// addi r11,r30,22
	r11.s64 = r30.s64 + 22;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827872ac
	if (!cr6.eq) goto loc_827872AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a2e0
	ctx.lr = 0x827872A8;
	sub_8277A2E0(ctx, base);
	// stwx r3,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r3.u32);
loc_827872AC:
	// addi r11,r30,19
	r11.s64 = r30.s64 + 19;
	// lwzx r4,r29,r31
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r26
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x82786ed8
	ctx.lr = 0x827872C4;
	sub_82786ED8(ctx, base);
	// stbx r25,r30,r28
	PPC_STORE_U8(r30.u32 + r28.u32, r25.u8);
loc_827872C8:
	// addi r29,r1,84
	r29.s64 = ctx.r1.s64 + 84;
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787314
	if (!cr6.eq) goto loc_82787314;
	// addi r11,r27,26
	r11.s64 = r27.s64 + 26;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827872f8
	if (!cr6.eq) goto loc_827872F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a2e0
	ctx.lr = 0x827872F4;
	sub_8277A2E0(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
loc_827872F8:
	// addi r11,r27,23
	r11.s64 = r27.s64 + 23;
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r26
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x82786ed8
	ctx.lr = 0x82787310;
	sub_82786ED8(ctx, base);
	// stbx r25,r27,r29
	PPC_STORE_U8(r27.u32 + r29.u32, r25.u8);
loc_82787314:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82787270
	if (cr6.lt) goto loc_82787270;
loc_82787328:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82787330"))) PPC_WEAK_FUNC(sub_82787330);
PPC_FUNC_IMPL(__imp__sub_82787330) {
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
	ctx.lr = 0x82787338;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r22,r4,24
	r22.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r30,348(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// beq cr6,0x82787364
	if (cr6.eq) goto loc_82787364;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,28120
	ctx.r9.s64 = r11.s64 + 28120;
	// addi r8,r10,29232
	ctx.r8.s64 = ctx.r10.s64 + 29232;
	// b 0x82787374
	goto loc_82787374;
loc_82787364:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,27072
	ctx.r9.s64 = r11.s64 + 27072;
	// addi r8,r10,27496
	ctx.r8.s64 = ctx.r10.s64 + 27496;
loc_82787374:
	// li r23,0
	r23.s64 = 0;
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827874f8
	if (!cr6.gt) goto loc_827874F8;
	// addi r26,r30,20
	r26.s64 = r30.s64 + 20;
	// addi r27,r31,232
	r27.s64 = r31.s64 + 232;
	// li r24,50
	r24.s64 = 50;
loc_8278739C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r29,20(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r28,24(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// beq cr6,0x827874a4
	if (cr6.eq) goto loc_827874A4;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x827873c0
	if (cr6.lt) goto loc_827873C0;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x827873e4
	if (cr6.lt) goto loc_827873E4;
loc_827873C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r29.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827873E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827873E4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827873f4
	if (cr6.lt) goto loc_827873F4;
	// cmpwi cr6,r28,4
	cr6.compare<int32_t>(r28.s32, 4, xer);
	// blt cr6,0x82787418
	if (cr6.lt) goto loc_82787418;
loc_827873F4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82787418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82787418:
	// addi r11,r29,19
	r11.s64 = r29.s64 + 19;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8278744c
	if (!cr6.eq) goto loc_8278744C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1028
	ctx.r5.s64 = 1028;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82787448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
loc_8278744C:
	// li r5,1028
	ctx.r5.s64 = 1028;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8278745C;
	sub_823D9890(ctx, base);
	// addi r11,r28,23
	r11.s64 = r28.s64 + 23;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82787490
	if (!cr6.eq) goto loc_82787490;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1028
	ctx.r5.s64 = 1028;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278748C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
loc_82787490:
	// li r5,1028
	ctx.r5.s64 = 1028;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x827874A0;
	sub_823D9890(ctx, base);
	// b 0x827874dc
	goto loc_827874DC;
loc_827874A4:
	// addi r11,r29,11
	r11.s64 = r29.s64 + 11;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827861d8
	ctx.lr = 0x827874C0;
	sub_827861D8(ctx, base);
	// addi r10,r28,15
	ctx.r10.s64 = r28.s64 + 15;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827861d8
	ctx.lr = 0x827874DC;
	sub_827861D8(ctx, base);
loc_827874DC:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// stw r23,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r23.u32);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8278739c
	if (cr6.lt) goto loc_8278739C;
loc_827874F8:
	// stw r23,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r23.u32);
	// stw r23,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r23.u32);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r23,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r23.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82787514"))) PPC_WEAK_FUNC(sub_82787514);
PPC_FUNC_IMPL(__imp__sub_82787514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82787518"))) PPC_WEAK_FUNC(sub_82787518);
PPC_FUNC_IMPL(__imp__sub_82787518) {
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
	// li r5,108
	ctx.r5.s64 = 108;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82787544;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// stw r3,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r3.u32);
	// addi r11,r3,44
	r11.s64 = ctx.r3.s64 + 44;
	// addi r8,r9,29488
	ctx.r8.s64 = ctx.r9.s64 + 29488;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
loc_82787560:
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82787560
	if (!cr0.eq) goto loc_82787560;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82787590"))) PPC_WEAK_FUNC(sub_82787590);
PPC_FUNC_IMPL(__imp__sub_82787590) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r30,24(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827875BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827875ec
	if (!cr6.eq) goto loc_827875EC;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,24
	ctx.r10.s64 = 24;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827875EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827875EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82787614"))) PPC_WEAK_FUNC(sub_82787614);
PPC_FUNC_IMPL(__imp__sub_82787614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82787618"))) PPC_WEAK_FUNC(sub_82787618);
PPC_FUNC_IMPL(__imp__sub_82787618) {
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
	ctx.lr = 0x82787620;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lwz r28,28(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bne cr6,0x82787660
	if (!cr6.eq) goto loc_82787660;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,40
	ctx.r10.s64 = 40;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82787660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82787660:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787770
	if (!cr6.eq) goto loc_82787770;
	// li r11,1
	r11.s64 = 1;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r27,r28,r30
	r27.u64 = r28.u64 + r30.u64;
	// slw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// subfic r8,r27,24
	xer.ca = r27.u32 <= 24;
	ctx.r8.s64 = 24 - r27.s64;
	// and r7,r9,r29
	ctx.r7.u64 = ctx.r9.u64 & r29.u64;
	// cmpwi cr6,r27,8
	cr6.compare<int32_t>(r27.s32, 8, xer);
	// slw r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// or r28,r6,r10
	r28.u64 = ctx.r6.u64 | ctx.r10.u64;
	// blt cr6,0x82787768
	if (cr6.lt) goto loc_82787768;
	// rlwinm r11,r27,0,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFF8;
	// rlwinm r26,r27,29,3,31
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r27,r11,r27
	r27.s64 = r27.s64 - r11.s64;
	// li r24,24
	r24.s64 = 24;
	// li r25,0
	r25.s64 = 0;
loc_827876AC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// srawi r10,r28,16
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = r28.s32 >> 16;
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// bne 0x82787728
	if (!cr0.eq) goto loc_82787728;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r30,24(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827876EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82787718
	if (!cr6.eq) goto loc_82787718;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r24,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r24.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82787718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82787718:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
loc_82787728:
	// cmpwi cr6,r29,255
	cr6.compare<int32_t>(r29.s32, 255, xer);
	// bne cr6,0x8278775c
	if (!cr6.eq) goto loc_8278775C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stb r25,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r25.u8);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bne 0x8278775c
	if (!cr0.eq) goto loc_8278775C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787590
	ctx.lr = 0x8278775C;
	sub_82787590(ctx, base);
loc_8278775C:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// bne 0x827876ac
	if (!cr0.eq) goto loc_827876AC;
loc_82787768:
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
loc_82787770:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82787778"))) PPC_WEAK_FUNC(sub_82787778);
PPC_FUNC_IMPL(__imp__sub_82787778) {
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
	ctx.lr = 0x82787780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82787894
	if (cr6.eq) goto loc_82787894;
	// li r28,0
	r28.s64 = 0;
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r30,r28
	r30.u64 = r28.u64;
	// beq 0x827877dc
	if (cr0.eq) goto loc_827877DC;
loc_827877A4:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x827877a4
	if (!cr0.eq) goto loc_827877A4;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// ble cr6,0x827877dc
	if (!cr6.gt) goto loc_827877DC;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,40
	ctx.r10.s64 = 40;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827877DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827877DC:
	// lbz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82787810
	if (cr6.eq) goto loc_82787810;
	// addi r10,r10,23
	ctx.r10.s64 = ctx.r10.s64 + 23;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// b 0x82787838
	goto loc_82787838;
loc_82787810:
	// addi r10,r10,19
	ctx.r10.s64 = ctx.r10.s64 + 19;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r6,1024(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1024);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// bl 0x82787618
	ctx.lr = 0x82787838;
	sub_82787618(ctx, base);
loc_82787838:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82787850
	if (cr6.eq) goto loc_82787850;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787618
	ctx.lr = 0x82787850;
	sub_82787618(ctx, base);
loc_82787850:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lwz r29,64(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r30,60(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
	// bne cr6,0x82787890
	if (!cr6.eq) goto loc_82787890;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82787890
	if (cr6.eq) goto loc_82787890;
loc_82787870:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
	// bl 0x82787618
	ctx.lr = 0x82787884;
	sub_82787618(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82787870
	if (!cr0.eq) goto loc_82787870;
loc_82787890:
	// stw r28,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r28.u32);
loc_82787894:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8278789C"))) PPC_WEAK_FUNC(sub_8278789C);
PPC_FUNC_IMPL(__imp__sub_8278789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827878A0"))) PPC_WEAK_FUNC(sub_827878A0);
PPC_FUNC_IMPL(__imp__sub_827878A0) {
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
	ctx.lr = 0x827878A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82787778
	ctx.lr = 0x827878B8;
	sub_82787778(ctx, base);
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787940
	if (!cr6.eq) goto loc_82787940;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787618
	ctx.lr = 0x827878D8;
	sub_82787618(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r11,255
	r11.s64 = 255;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bne 0x82787910
	if (!cr0.eq) goto loc_82787910;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787590
	ctx.lr = 0x82787910;
	sub_82787590(ctx, base);
loc_82787910:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r10,r29,208
	ctx.r10.s64 = r29.s64 + 208;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addic. r11,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r11.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// bne 0x82787940
	if (!cr0.eq) goto loc_82787940;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787590
	ctx.lr = 0x82787940;
	sub_82787590(ctx, base);
loc_82787940:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,300(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82787988
	if (!cr6.eq) goto loc_82787988;
	// lwz r11,228(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 228);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82787990
	if (!cr6.gt) goto loc_82787990;
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
loc_82787964:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,228(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 228);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82787964
	if (cr6.lt) goto loc_82787964;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82787988:
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
loc_82787990:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82787998"))) PPC_WEAK_FUNC(sub_82787998);
PPC_FUNC_IMPL(__imp__sub_82787998) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x827879A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r31,348(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 348);
	// lwz r28,312(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 312);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// lwz r7,188(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827879f0
	if (cr6.eq) goto loc_827879F0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827879f0
	if (!cr6.eq) goto loc_827879F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x827878a0
	ctx.lr = 0x827879F0;
	sub_827878A0(ctx, base);
loc_827879F0:
	// lwz r11,256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82787b18
	if (!cr6.gt) goto loc_82787B18;
	// mr r25,r30
	r25.u64 = r30.u64;
	// extsh r24,r28
	r24.s64 = r28.s16;
	// addi r26,r29,260
	r26.s64 = r29.s64 + 260;
	// li r22,6
	r22.s64 = 6;
loc_82787A10:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// extsh r5,r24
	ctx.r5.s64 = r24.s16;
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r7,r11,9
	ctx.r7.s64 = r11.s64 + 9;
	// addi r6,r11,58
	ctx.r6.s64 = r11.s64 + 58;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// sraw r10,r11,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	ctx.r10.s64 = r11.s32 >> temp.u32;
	// lwzx r28,r3,r29
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// subf. r11,r8,r10
	r11.s64 = ctx.r10.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
	// mr r27,r11
	r27.u64 = r11.u64;
	// bge 0x82787a58
	if (!cr0.lt) goto loc_82787A58;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
loc_82787A58:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82787a94
	if (cr6.eq) goto loc_82787A94;
loc_82787A64:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x82787a64
	if (!cr0.eq) goto loc_82787A64;
	// cmpwi cr6,r30,11
	cr6.compare<int32_t>(r30.s32, 11, xer);
	// ble cr6,0x82787a94
	if (!cr6.gt) goto loc_82787A94;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82787A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82787A94:
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x82787ac4
	if (cr6.eq) goto loc_82787AC4;
	// addi r11,r11,23
	r11.s64 = r11.s64 + 23;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// b 0x82787ae8
	goto loc_82787AE8;
loc_82787AC4:
	// addi r11,r11,19
	r11.s64 = r11.s64 + 19;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lbz r7,1024(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1024);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// bl 0x82787618
	ctx.lr = 0x82787AE8;
	sub_82787618(ctx, base);
loc_82787AE8:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82787b00
	if (cr6.eq) goto loc_82787B00;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787618
	ctx.lr = 0x82787B00;
	sub_82787618(ctx, base);
loc_82787B00:
	// lwz r11,256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82787a10
	if (cr6.lt) goto loc_82787A10;
loc_82787B18:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// lwz r11,188(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82787b68
	if (cr6.eq) goto loc_82787B68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82787b5c
	if (!cr6.eq) goto loc_82787B5C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
loc_82787B5C:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_82787B68:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82787B74"))) PPC_WEAK_FUNC(sub_82787B74);
PPC_FUNC_IMPL(__imp__sub_82787B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82787B78"))) PPC_WEAK_FUNC(sub_82787B78);
PPC_FUNC_IMPL(__imp__sub_82787B78) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82787B80;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r31,348(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 348);
	// lwz r30,304(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 304);
	// lwz r23,312(r26)
	r23.u64 = PPC_LOAD_U32(r26.u32 + 312);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// lwz r9,24(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// lwz r7,188(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 188);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82787bd4
	if (cr6.eq) goto loc_82787BD4;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787bd4
	if (!cr6.eq) goto loc_82787BD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x827878a0
	ctx.lr = 0x82787BD4;
	sub_827878A0(ctx, base);
loc_82787BD4:
	// lwz r11,300(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 300);
	// li r28,0
	r28.s64 = 0;
	// lwz r22,0(r29)
	r22.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// bgt cr6,0x82787db4
	if (cr6.gt) goto loc_82787DB4;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-31424
	ctx.r10.s64 = ctx.r10.s64 + -31424;
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// add r25,r9,r10
	r25.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r24,r11,1
	r24.s64 = r11.s64 + 1;
	// li r21,6
	r21.s64 = 6;
loc_82787C04:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r22
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r22.u32);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82787c24
	if (!cr6.eq) goto loc_82787C24;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x82787d84
	goto loc_82787D84;
loc_82787C24:
	// bge cr6,0x82787c38
	if (!cr6.lt) goto loc_82787C38;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// sraw r30,r11,r23
	temp.u32 = r23.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	r30.s64 = r11.s32 >> temp.u32;
	// not r27,r30
	r27.u64 = ~r30.u64;
	// b 0x82787c40
	goto loc_82787C40;
loc_82787C38:
	// sraw r30,r11,r23
	temp.u32 = r23.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	r30.s64 = r11.s32 >> temp.u32;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_82787C40:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82787c50
	if (!cr6.eq) goto loc_82787C50;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x82787d84
	goto loc_82787D84;
loc_82787C50:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82787c64
	if (!cr6.gt) goto loc_82787C64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787778
	ctx.lr = 0x82787C64;
	sub_82787778(ctx, base);
loc_82787C64:
	// cmpwi cr6,r28,15
	cr6.compare<int32_t>(r28.s32, 15, xer);
	// ble cr6,0x82787cd4
	if (!cr6.gt) goto loc_82787CD4;
	// addi r11,r28,-16
	r11.s64 = r28.s64 + -16;
	// rlwinm r11,r11,28,4,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r28,r10,r28
	r28.s64 = r28.s64 - ctx.r10.s64;
loc_82787C80:
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82787cac
	if (cr6.eq) goto loc_82787CAC;
	// addi r11,r11,23
	r11.s64 = r11.s64 + 23;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r10,960(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 960);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,960(r11)
	PPC_STORE_U32(r11.u32 + 960, ctx.r9.u32);
	// b 0x82787ccc
	goto loc_82787CCC;
loc_82787CAC:
	// addi r11,r11,19
	r11.s64 = r11.s64 + 19;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lbz r8,1264(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1264);
	// lwz r4,960(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 960);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// bl 0x82787618
	ctx.lr = 0x82787CCC;
	sub_82787618(ctx, base);
loc_82787CCC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x82787c80
	if (!cr0.eq) goto loc_82787C80;
loc_82787CD4:
	// srawi. r11,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	r11.s64 = r30.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r30,1
	r30.s64 = 1;
	// beq 0x82787d10
	if (cr0.eq) goto loc_82787D10;
loc_82787CE0:
	// srawi. r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x82787ce0
	if (!cr0.eq) goto loc_82787CE0;
	// cmpwi cr6,r30,10
	cr6.compare<int32_t>(r30.s32, 10, xer);
	// ble cr6,0x82787d10
	if (!cr6.gt) goto loc_82787D10;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r21,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r21.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82787D10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82787D10:
	// lbz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82787d48
	if (cr6.eq) goto loc_82787D48;
	// addi r9,r10,23
	ctx.r9.s64 = ctx.r10.s64 + 23;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r31
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// b 0x82787d70
	goto loc_82787D70;
loc_82787D48:
	// addi r10,r10,19
	ctx.r10.s64 = ctx.r10.s64 + 19;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r6,1024(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1024);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// bl 0x82787618
	ctx.lr = 0x82787D70;
	sub_82787618(ctx, base);
loc_82787D70:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787618
	ctx.lr = 0x82787D80;
	sub_82787618(ctx, base);
	// li r28,0
	r28.s64 = 0;
loc_82787D84:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x82787c04
	if (!cr0.eq) goto loc_82787C04;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82787db4
	if (!cr6.gt) goto loc_82787DB4;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// bne cr6,0x82787db4
	if (!cr6.eq) goto loc_82787DB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787778
	ctx.lr = 0x82787DB4;
	sub_82787778(ctx, base);
loc_82787DB4:
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,24(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// lwz r11,188(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82787e04
	if (cr6.eq) goto loc_82787E04;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82787df8
	if (!cr6.eq) goto loc_82787DF8;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
loc_82787DF8:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_82787E04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82787E10"))) PPC_WEAK_FUNC(sub_82787E10);
PPC_FUNC_IMPL(__imp__sub_82787E10) {
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
	ctx.lr = 0x82787E18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r30,348(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lwz r27,312(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r8.u32);
	// lwz r7,188(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82787e68
	if (cr6.eq) goto loc_82787E68;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787e68
	if (!cr6.eq) goto loc_82787E68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,72(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x827878a0
	ctx.lr = 0x82787E68;
	sub_827878A0(ctx, base);
loc_82787E68:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82787eb4
	if (!cr6.gt) goto loc_82787EB4;
	// extsh r27,r27
	r27.s64 = r27.s16;
loc_82787E7C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// extsh r10,r27
	ctx.r10.s64 = r27.s16;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sraw r7,r8,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r7.s64 = ctx.r8.s32 >> temp.u32;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// bl 0x82787618
	ctx.lr = 0x82787EA0;
	sub_82787618(ctx, base);
	// lwz r6,256(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r6
	cr6.compare<int32_t>(r28.s32, ctx.r6.s32, xer);
	// blt cr6,0x82787e7c
	if (cr6.lt) goto loc_82787E7C;
loc_82787EB4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82787f04
	if (cr6.eq) goto loc_82787F04;
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82787ef8
	if (!cr6.eq) goto loc_82787EF8;
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r11,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stw r10,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r10.u32);
loc_82787EF8:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r11.u32);
loc_82787F04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82787F10"))) PPC_WEAK_FUNC(sub_82787F10);
PPC_FUNC_IMPL(__imp__sub_82787F10) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82787F18;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,24(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// lwz r31,348(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + 348);
	// lwz r22,304(r21)
	r22.u64 = PPC_LOAD_U32(r21.u32 + 304);
	// lwz r29,312(r21)
	r29.u64 = PPC_LOAD_U32(r21.u32 + 312);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// lwz r9,24(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// lwz r7,188(r21)
	ctx.r7.u64 = PPC_LOAD_U32(r21.u32 + 188);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82787f6c
	if (cr6.eq) goto loc_82787F6C;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82787f6c
	if (!cr6.eq) goto loc_82787F6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x827878a0
	ctx.lr = 0x82787F6C;
	sub_827878A0(ctx, base);
loc_82787F6C:
	// lwz r9,300(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 300);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lwz r24,0(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r20,0
	r20.s64 = 0;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpw cr6,r9,r22
	cr6.compare<int32_t>(ctx.r9.s32, r22.s32, xer);
	// addi r23,r11,-31424
	r23.s64 = r11.s64 + -31424;
	// bgt cr6,0x82787fd4
	if (cr6.gt) goto loc_82787FD4;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_82787F90:
	// lwzx r11,r10,r23
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r23.u32);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r24
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + r24.u32);
	// extsh r11,r6
	r11.s64 = ctx.r6.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82787fac
	if (!cr6.lt) goto loc_82787FAC;
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_82787FAC:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// sraw r11,r11,r29
	temp.u32 = r29.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	r11.s64 = r11.s32 >> temp.u32;
	// stwx r11,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82787fc4
	if (!cr6.eq) goto loc_82787FC4;
	// mr r20,r8
	r20.u64 = ctx.r8.u64;
loc_82787FC4:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r8,r22
	cr6.compare<int32_t>(ctx.r8.s32, r22.s32, xer);
	// ble cr6,0x82787f90
	if (!cr6.gt) goto loc_82787F90;
loc_82787FD4:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r30,0
	r30.s64 = 0;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmpw cr6,r9,r22
	cr6.compare<int32_t>(ctx.r9.s32, r22.s32, xer);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// bgt cr6,0x827881f8
	if (cr6.gt) goto loc_827881F8;
	// rlwinm r26,r25,2,0,29
	r26.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
loc_82787FF8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwzx r27,r26,r11
	r27.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x82788010
	if (!cr6.eq) goto loc_82788010;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x827881a8
	goto loc_827881A8;
loc_82788010:
	// cmpwi cr6,r28,15
	cr6.compare<int32_t>(r28.s32, 15, xer);
	// ble cr6,0x827880bc
	if (!cr6.gt) goto loc_827880BC;
loc_82788018:
	// cmpw cr6,r25,r20
	cr6.compare<int32_t>(r25.s32, r20.s32, xer);
	// bgt cr6,0x827880bc
	if (cr6.gt) goto loc_827880BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787778
	ctx.lr = 0x82788028;
	sub_82787778(ctx, base);
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82788054
	if (cr6.eq) goto loc_82788054;
	// addi r11,r11,23
	r11.s64 = r11.s64 + 23;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r10,960(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 960);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,960(r11)
	PPC_STORE_U32(r11.u32 + 960, ctx.r9.u32);
	// b 0x82788074
	goto loc_82788074;
loc_82788054:
	// addi r11,r11,19
	r11.s64 = r11.s64 + 19;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lbz r8,1264(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1264);
	// lwz r4,960(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 960);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// bl 0x82787618
	ctx.lr = 0x82788074;
	sub_82787618(ctx, base);
loc_82788074:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// addi r28,r28,-16
	r28.s64 = r28.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827880ac
	if (!cr6.eq) goto loc_827880AC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827880ac
	if (cr6.eq) goto loc_827880AC;
loc_8278808C:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
	// bl 0x82787618
	ctx.lr = 0x827880A0;
	sub_82787618(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x8278808c
	if (!cr0.eq) goto loc_8278808C;
loc_827880AC:
	// lwz r29,64(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,15
	cr6.compare<int32_t>(r28.s32, 15, xer);
	// bgt cr6,0x82788018
	if (cr6.gt) goto loc_82788018;
loc_827880BC:
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// ble cr6,0x827880d4
	if (!cr6.gt) goto loc_827880D4;
	// clrlwi r11,r27,31
	r11.u64 = r27.u32 & 0x1;
	// stbx r11,r29,r30
	PPC_STORE_U8(r29.u32 + r30.u32, r11.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x827881a8
	goto loc_827881A8;
loc_827880D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787778
	ctx.lr = 0x827880DC;
	sub_82787778(ctx, base);
	// lbz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq cr6,0x82788114
	if (cr6.eq) goto loc_82788114;
	// addi r9,r10,23
	ctx.r9.s64 = ctx.r10.s64 + 23;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r31
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// b 0x8278813c
	goto loc_8278813C;
loc_82788114:
	// addi r10,r10,19
	ctx.r10.s64 = ctx.r10.s64 + 19;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r6,1024(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1024);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// bl 0x82787618
	ctx.lr = 0x8278813C;
	sub_82787618(ctx, base);
loc_8278813C:
	// lwzx r11,r26,r23
	r11.u64 = PPC_LOAD_U32(r26.u32 + r23.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r24
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r24.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 ^ 1;
	// bl 0x82787618
	ctx.lr = 0x82788168;
	sub_82787618(ctx, base);
	// lbz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8278819c
	if (!cr6.eq) goto loc_8278819C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8278819c
	if (cr6.eq) goto loc_8278819C;
loc_8278817C:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
	// bl 0x82787618
	ctx.lr = 0x82788190;
	sub_82787618(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x8278817c
	if (!cr0.eq) goto loc_8278817C;
loc_8278819C:
	// lwz r29,64(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r30,0
	r30.s64 = 0;
	// li r28,0
	r28.s64 = 0;
loc_827881A8:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r25,r22
	cr6.compare<int32_t>(r25.s32, r22.s32, xer);
	// ble cr6,0x82787ff8
	if (!cr6.gt) goto loc_82787FF8;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bgt cr6,0x827881c8
	if (cr6.gt) goto loc_827881C8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827881f8
	if (cr6.eq) goto loc_827881F8;
loc_827881C8:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
	// beq cr6,0x827881f0
	if (cr6.eq) goto loc_827881F0;
	// cmplwi cr6,r10,937
	cr6.compare<uint32_t>(ctx.r10.u32, 937, xer);
	// ble cr6,0x827881f8
	if (!cr6.gt) goto loc_827881F8;
loc_827881F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82787778
	ctx.lr = 0x827881F8;
	sub_82787778(ctx, base);
loc_827881F8:
	// lwz r11,24(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r8,24(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// lwz r11,188(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82788248
	if (cr6.eq) goto loc_82788248;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8278823c
	if (!cr6.eq) goto loc_8278823C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
loc_8278823C:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_82788248:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82788254"))) PPC_WEAK_FUNC(sub_82788254);
PPC_FUNC_IMPL(__imp__sub_82788254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82788258"))) PPC_WEAK_FUNC(sub_82788258);
PPC_FUNC_IMPL(__imp__sub_82788258) {
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r30,348(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r8.u32);
	// bl 0x82787778
	ctx.lr = 0x82788294;
	sub_82787778(ctx, base);
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82787618
	ctx.lr = 0x827882A4;
	sub_82787618(ctx, base);
	// lwz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r4,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_827882E0"))) PPC_WEAK_FUNC(sub_827882E0);
PPC_FUNC_IMPL(__imp__sub_827882E0) {
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
	ctx.lr = 0x827882E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r26,348(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82787778
	ctx.lr = 0x827882FC;
	sub_82787778(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,300(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// li r25,0
	r25.s64 = 0;
	// lwz r9,228(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// ble cr6,0x827883c0
	if (!cr6.gt) goto loc_827883C0;
	// clrlwi r23,r11,24
	r23.u64 = r11.u32 & 0xFF;
	// addi r27,r30,232
	r27.s64 = r30.s64 + 232;
	// li r24,1
	r24.s64 = 1;
loc_8278832C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8278834c
	if (cr6.eq) goto loc_8278834C;
	// lwz r10,308(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 308);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827883ac
	if (!cr6.eq) goto loc_827883AC;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x82788350
	goto loc_82788350;
loc_8278834C:
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
loc_82788350:
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lbzx r11,r31,r28
	r11.u64 = PPC_LOAD_U8(r31.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827883ac
	if (!cr6.eq) goto loc_827883AC;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// addi r11,r31,22
	r11.s64 = r31.s64 + 22;
	// bne cr6,0x82788370
	if (!cr6.eq) goto loc_82788370;
	// addi r11,r31,26
	r11.s64 = r31.s64 + 26;
loc_82788370:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82788390
	if (!cr6.eq) goto loc_82788390;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277a2e0
	ctx.lr = 0x8278838C;
	sub_8277A2E0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82788390:
	// addi r11,r31,23
	r11.s64 = r31.s64 + 23;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r26
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x82786ed8
	ctx.lr = 0x827883A8;
	sub_82786ED8(ctx, base);
	// stbx r24,r31,r28
	PPC_STORE_U8(r31.u32 + r28.u32, r24.u8);
loc_827883AC:
	// lwz r11,228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8278832c
	if (cr6.lt) goto loc_8278832C;
loc_827883C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827883C8"))) PPC_WEAK_FUNC(sub_827883C8);
PPC_FUNC_IMPL(__imp__sub_827883C8) {
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
	ctx.lr = 0x827883D0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r29,348(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// stw r30,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r30.u32);
	// stb r31,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r31.u8);
	// lwz r11,308(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 308);
	// lwz r10,300(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r22,r9,27,31,31
	r22.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// clrlwi r23,r22,24
	r23.u64 = r22.u32 & 0xFF;
	// bne cr6,0x8278842c
	if (!cr6.eq) goto loc_8278842C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8278841c
	if (cr6.eq) goto loc_8278841C;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,31128
	ctx.r10.s64 = r11.s64 + 31128;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// b 0x8278847c
	goto loc_8278847C;
loc_8278841C:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,31608
	ctx.r10.s64 = r11.s64 + 31608;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// b 0x8278847c
	goto loc_8278847C;
loc_8278842C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82788444
	if (cr6.eq) goto loc_82788444;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,32272
	ctx.r10.s64 = r11.s64 + 32272;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// b 0x8278847c
	goto loc_8278847C;
loc_82788444:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r9,r11,32528
	ctx.r9.s64 = r11.s64 + 32528;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8278847c
	if (!cr6.eq) goto loc_8278847C;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1000
	ctx.r5.s64 = 1000;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82788478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r3.u32);
loc_8278847C:
	// clrlwi r21,r31,24
	r21.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82788494
	if (cr6.eq) goto loc_82788494;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-32032
	ctx.r10.s64 = r11.s64 + -32032;
	// b 0x8278849c
	goto loc_8278849C;
loc_82788494:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-32168
	ctx.r10.s64 = r11.s64 + -32168;
loc_8278849C:
	// li r25,0
	r25.s64 = 0;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// lwz r11,228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r26,r25
	r26.u64 = r25.u64;
	// ble cr6,0x827885a4
	if (!cr6.gt) goto loc_827885A4;
	// addi r27,r29,36
	r27.s64 = r29.s64 + 36;
	// addi r28,r30,232
	r28.s64 = r30.s64 + 232;
	// li r24,50
	r24.s64 = 50;
loc_827884C0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// stw r25,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r25.u32);
	// beq cr6,0x827884e4
	if (cr6.eq) goto loc_827884E4;
	// lwz r10,308(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 308);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8278858c
	if (!cr6.eq) goto loc_8278858C;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x827884ec
	goto loc_827884EC;
loc_827884E4:
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r31,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r31.u32);
loc_827884EC:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82788570
	if (cr6.eq) goto loc_82788570;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82788504
	if (cr6.lt) goto loc_82788504;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82788528
	if (cr6.lt) goto loc_82788528;
loc_82788504:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82788528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82788528:
	// addi r11,r31,23
	r11.s64 = r31.s64 + 23;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8278855c
	if (!cr6.eq) goto loc_8278855C;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1028
	ctx.r5.s64 = 1028;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82788558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r3.u32);
loc_8278855C:
	// li r5,1028
	ctx.r5.s64 = 1028;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8278856C;
	sub_823D9890(ctx, base);
	// b 0x8278858c
	goto loc_8278858C;
loc_82788570:
	// addi r11,r31,19
	r11.s64 = r31.s64 + 19;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// add r6,r11,r29
	ctx.r6.u64 = r11.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827861d8
	ctx.lr = 0x8278858C;
	sub_827861D8(ctx, base);
loc_8278858C:
	// lwz r11,228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x827884c0
	if (cr6.lt) goto loc_827884C0;
loc_827885A4:
	// stw r25,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r25.u32);
	// stw r25,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r25.u32);
	// stw r25,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r25.u32);
	// stw r25,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r25.u32);
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// stw r11,68(r29)
	PPC_STORE_U32(r29.u32 + 68, r11.u32);
	// stw r25,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_827885C8"))) PPC_WEAK_FUNC(sub_827885C8);
PPC_FUNC_IMPL(__imp__sub_827885C8) {
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
	// li r5,108
	ctx.r5.s64 = 108;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827885F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32135
	ctx.r9.s64 = -2105999360;
	// stw r3,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r3.u32);
	// addi r11,r3,92
	r11.s64 = ctx.r3.s64 + 92;
	// addi r8,r9,-31800
	ctx.r8.s64 = ctx.r9.s64 + -31800;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
loc_82788610:
	// stw r9,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82788610
	if (!cr0.eq) goto loc_82788610;
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8278863C"))) PPC_WEAK_FUNC(sub_8278863C);
PPC_FUNC_IMPL(__imp__sub_8278863C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82788640"))) PPC_WEAK_FUNC(sub_82788640);
PPC_FUNC_IMPL(__imp__sub_82788640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x823d91e4
	ctx.lr = 0x82788648;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9cc
	ctx.lr = 0x82788650;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r10,60(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 60);
	// lwz r28,344(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 344);
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82788a44
	if (!cr6.gt) goto loc_82788A44;
	// addi r26,r11,16
	r26.s64 = r11.s64 + 16;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// lis r8,-32242
	ctx.r8.s64 = -2113011712;
	// lis r7,-32242
	ctx.r7.s64 = -2113011712;
	// lis r6,-32242
	ctx.r6.s64 = -2113011712;
	// lfd f25,-30128(r11)
	ctx.fpscr.disableFlushMode();
	f25.u64 = PPC_LOAD_U64(r11.u32 + -30128);
	// lis r5,-32242
	ctx.r5.s64 = -2113011712;
	// lfd f26,-30136(r10)
	f26.u64 = PPC_LOAD_U64(ctx.r10.u32 + -30136);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lfd f27,-30144(r9)
	f27.u64 = PPC_LOAD_U64(ctx.r9.u32 + -30144);
	// lfd f28,-30152(r8)
	f28.u64 = PPC_LOAD_U64(ctx.r8.u32 + -30152);
	// li r24,52
	r24.s64 = 52;
	// lfd f29,-30160(r7)
	f29.u64 = PPC_LOAD_U64(ctx.r7.u32 + -30160);
	// li r23,48
	r23.s64 = 48;
	// lfd f30,-30168(r6)
	f30.u64 = PPC_LOAD_U64(ctx.r6.u32 + -30168);
	// addi r31,r11,-30368
	r31.s64 = r11.s64 + -30368;
	// lfd f31,-30176(r5)
	f31.u64 = PPC_LOAD_U64(ctx.r5.u32 + -30176);
loc_827886BC:
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x827886e4
	if (cr6.lt) goto loc_827886E4;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// bge cr6,0x827886e4
	if (!cr6.lt) goto loc_827886E4;
	// addi r11,r29,18
	r11.s64 = r29.s64 + 18;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82788708
	if (!cr6.eq) goto loc_82788708;
loc_827886E4:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r29,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r29.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82788708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82788708:
	// addi r10,r29,18
	ctx.r10.s64 = r29.s64 + 18;
	// lwz r11,184(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 184);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// lwzx r30,r9,r27
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// blt cr6,0x827889d4
	if (cr6.lt) goto loc_827889D4;
	// beq cr6,0x827888f4
	if (cr6.eq) goto loc_827888F4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8278874c
	if (cr6.lt) goto loc_8278874C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82788748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82788a30
	goto loc_82788A30;
loc_8278874C:
	// addi r11,r29,8
	r11.s64 = r29.s64 + 8;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r28
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82788780
	if (!cr6.eq) goto loc_82788780;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278877C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r28
	PPC_STORE_U32(r29.u32 + r28.u32, ctx.r3.u32);
loc_82788780:
	// lwzx r9,r29,r28
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addi r10,r30,4
	ctx.r10.s64 = r30.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
loc_82788790:
	// lhz r7,-4(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + -4);
	// lfd f13,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f0,128(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 128);
	// addi r8,r31,128
	ctx.r8.s64 = r31.s64 + 128;
	// addi r6,r8,64
	ctx.r6.s64 = ctx.r8.s64 + 64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fmul f10,f11,f13
	ctx.f10.f64 = ctx.f11.f64 * ctx.f13.f64;
	// fmul f9,f10,f31
	ctx.f9.f64 = ctx.f10.f64 * f31.f64;
	// fdiv f8,f0,f9
	ctx.f8.f64 = f0.f64 / ctx.f9.f64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,-8(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// lfd f6,0(r11)
	ctx.f6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,-2(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f5,88(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fmul f3,f4,f6
	ctx.f3.f64 = ctx.f4.f64 * ctx.f6.f64;
	// fmul f2,f3,f30
	ctx.f2.f64 = ctx.f3.f64 * f30.f64;
	// fdiv f1,f0,f2
	ctx.f1.f64 = f0.f64 / ctx.f2.f64;
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f13,-4(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// lfd f12,0(r11)
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fmul f9,f10,f12
	ctx.f9.f64 = ctx.f10.f64 * ctx.f12.f64;
	// fmul f8,f9,f29
	ctx.f8.f64 = ctx.f9.f64 * f29.f64;
	// fdiv f7,f0,f8
	ctx.f7.f64 = f0.f64 / ctx.f8.f64;
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfd f5,0(r11)
	ctx.f5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f4,104(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// fmul f2,f3,f5
	ctx.f2.f64 = ctx.f3.f64 * ctx.f5.f64;
	// fmul f1,f2,f28
	ctx.f1.f64 = ctx.f2.f64 * f28.f64;
	// fdiv f13,f0,f1
	ctx.f13.f64 = f0.f64 / ctx.f1.f64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,4(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lfd f11,0(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f10,112(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fmul f8,f9,f11
	ctx.f8.f64 = ctx.f9.f64 * ctx.f11.f64;
	// fmul f7,f8,f31
	ctx.f7.f64 = ctx.f8.f64 * f31.f64;
	// fdiv f6,f0,f7
	ctx.f6.f64 = f0.f64 / ctx.f7.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,8(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lfd f4,0(r11)
	ctx.f4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,6(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f3,120(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fmul f1,f2,f4
	ctx.f1.f64 = ctx.f2.f64 * ctx.f4.f64;
	// fmul f13,f1,f27
	ctx.f13.f64 = ctx.f1.f64 * f27.f64;
	// fdiv f12,f0,f13
	ctx.f12.f64 = f0.f64 / ctx.f13.f64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,12(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfd f10,0(r11)
	ctx.f10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfd f9,128(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fmul f7,f8,f10
	ctx.f7.f64 = ctx.f8.f64 * ctx.f10.f64;
	// fmul f6,f7,f26
	ctx.f6.f64 = ctx.f7.f64 * f26.f64;
	// fdiv f5,f0,f6
	ctx.f5.f64 = f0.f64 / ctx.f6.f64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,16(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// lhz r4,10(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// lfd f3,0(r11)
	ctx.f3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r4,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lfd f2,136(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// fmul f13,f1,f3
	ctx.f13.f64 = ctx.f1.f64 * ctx.f3.f64;
	// fmul f12,f13,f25
	ctx.f12.f64 = ctx.f13.f64 * f25.f64;
	// fdiv f11,f0,f12
	ctx.f11.f64 = f0.f64 / ctx.f12.f64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,20(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// blt cr6,0x82788790
	if (cr6.lt) goto loc_82788790;
	// b 0x82788a30
	goto loc_82788A30;
loc_827888F4:
	// addi r11,r29,3
	r11.s64 = r29.s64 + 3;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r28
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82788928
	if (!cr6.eq) goto loc_82788928;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82788924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r28
	PPC_STORE_U32(r29.u32 + r28.u32, ctx.r3.u32);
loc_82788928:
	// lwzx r11,r29,r28
	r11.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// neg r8,r30
	ctx.r8.s64 = -r30.s64;
	// addi r6,r31,2
	ctx.r6.s64 = r31.s64 + 2;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// add r7,r8,r31
	ctx.r7.u64 = ctx.r8.u64 + r31.u64;
	// add r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 + ctx.r6.u64;
loc_82788948:
	// lhz r8,-2(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// addi r5,r31,130
	ctx.r5.s64 = r31.s64 + 130;
	// lhz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// mullw r8,r4,r3
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// addi r8,r8,1024
	ctx.r8.s64 = ctx.r8.s64 + 1024;
	// srawi r4,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 11;
	// stw r4,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r4.u32);
	// lhz r4,-2(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// lhz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// mullw r8,r4,r8
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// addi r3,r8,1024
	ctx.r3.s64 = ctx.r8.s64 + 1024;
	// srawi r8,r3,11
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 11;
	// stw r8,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r8.u32);
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lhzx r4,r7,r11
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// mullw r8,r3,r5
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// addi r8,r8,1024
	ctx.r8.s64 = ctx.r8.s64 + 1024;
	// srawi r5,r8,11
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 11;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lhz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhzx r3,r6,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r6.u32 + r11.u32);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// mullw r8,r8,r4
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// addi r5,r8,1024
	ctx.r5.s64 = ctx.r8.s64 + 1024;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// srawi r4,r5,11
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 11;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// blt cr6,0x82788948
	if (cr6.lt) goto loc_82788948;
	// b 0x82788a30
	goto loc_82788A30;
loc_827889D4:
	// addi r11,r29,3
	r11.s64 = r29.s64 + 3;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r28
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82788a08
	if (!cr6.eq) goto loc_82788A08;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82788A04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r28
	PPC_STORE_U32(r29.u32 + r28.u32, ctx.r3.u32);
loc_82788A08:
	// lwzx r9,r29,r28
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r11,64
	r11.s64 = 64;
loc_82788A14:
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rotlwi r7,r8,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82788a14
	if (!cr0.eq) goto loc_82788A14;
loc_82788A30:
	// lwz r11,60(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 60);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,84
	r26.s64 = r26.s64 + 84;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x827886bc
	if (cr6.lt) goto loc_827886BC;
loc_82788A44:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba18
	ctx.lr = 0x82788A50;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82788A54"))) PPC_WEAK_FUNC(sub_82788A54);
PPC_FUNC_IMPL(__imp__sub_82788A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82788A58"))) PPC_WEAK_FUNC(sub_82788A58);
PPC_FUNC_IMPL(__imp__sub_82788A58) {
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
	ctx.lr = 0x82788A60;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// lwz r8,344(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	// addi r7,r11,3
	ctx.r7.s64 = r11.s64 + 3;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r25,8(r8)
	r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwzx r11,r5,r8
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// beq cr6,0x82788f74
	if (cr6.eq) goto loc_82788F74;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r24,r10,8
	r24.s64 = ctx.r10.s64 + 8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// subf r29,r11,r8
	r29.s64 = ctx.r8.s64 - r11.s64;
	// subf r28,r11,r7
	r28.s64 = ctx.r7.s64 - r11.s64;
	// addi r30,r6,4
	r30.s64 = ctx.r6.s64 + 4;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
loc_82788AB0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r24
	r11.u64 = r24.u64;
	// li r9,2
	ctx.r9.s64 = 2;
loc_82788ABC:
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// lbz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r4,r4,-128
	ctx.r4.s64 = ctx.r4.s64 + -128;
	// addi r8,r7,4
	ctx.r8.s64 = ctx.r7.s64 + 4;
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// add r10,r5,r31
	ctx.r10.u64 = ctx.r5.u64 + r31.u64;
	// lbzx r7,r5,r31
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + r31.u32);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r5,r7,-128
	ctx.r5.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r5,r7,-128
	ctx.r5.s64 = ctx.r7.s64 + -128;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// add r8,r6,r31
	ctx.r8.u64 = ctx.r6.u64 + r31.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r5,r7,-128
	ctx.r5.s64 = ctx.r7.s64 + -128;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// lbz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r3,r5,-128
	ctx.r3.s64 = ctx.r5.s64 + -128;
	// addi r8,r7,4
	ctx.r8.s64 = ctx.r7.s64 + 4;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r5,r7,-128
	ctx.r5.s64 = ctx.r7.s64 + -128;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// add r10,r6,r31
	ctx.r10.u64 = ctx.r6.u64 + r31.u64;
	// lbzx r7,r6,r31
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + r31.u32);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r6,r7,-128
	ctx.r6.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r5,r7,-128
	ctx.r5.s64 = ctx.r7.s64 + -128;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r4,r7,-128
	ctx.r4.s64 = ctx.r7.s64 + -128;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r3,r7,-128
	ctx.r3.s64 = ctx.r7.s64 + -128;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// bne 0x82788abc
	if (!cr0.eq) goto loc_82788ABC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r25
	ctr.u64 = r25.u64;
	// bctrl 
	ctx.lr = 0x82788D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r5,16
	ctx.r5.s64 = 16;
loc_82788D54:
	// lwz r10,-4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	// lwz r11,-8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// srawi r9,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r9.s64 = r11.s32 >> 1;
	// bge cr6,0x82788da0
	if (!cr6.lt) goto loc_82788DA0;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788d94
	if (cr6.lt) goto loc_82788D94;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// twlgei r4,-1
	// b 0x82788dcc
	goto loc_82788DCC;
loc_82788D94:
	// li r10,0
	ctx.r10.s64 = 0;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// b 0x82788dcc
	goto loc_82788DCC;
loc_82788DA0:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788dc8
	if (cr6.lt) goto loc_82788DC8;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// b 0x82788dcc
	goto loc_82788DCC;
loc_82788DC8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82788DCC:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// sth r11,-4(r7)
	PPC_STORE_U16(ctx.r7.u32 + -4, r11.u16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// srawi r9,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r9.s64 = r11.s32 >> 1;
	// bge cr6,0x82788e20
	if (!cr6.lt) goto loc_82788E20;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788e14
	if (cr6.lt) goto loc_82788E14;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// twlgei r4,-1
	// b 0x82788e4c
	goto loc_82788E4C;
loc_82788E14:
	// li r10,0
	ctx.r10.s64 = 0;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// b 0x82788e4c
	goto loc_82788E4C;
loc_82788E20:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788e48
	if (cr6.lt) goto loc_82788E48;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// b 0x82788e4c
	goto loc_82788E4C;
loc_82788E48:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82788E4C:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwzx r10,r8,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// sth r11,-2(r7)
	PPC_STORE_U16(ctx.r7.u32 + -2, r11.u16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// srawi r9,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r9.s64 = r11.s32 >> 1;
	// bge cr6,0x82788ea0
	if (!cr6.lt) goto loc_82788EA0;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788e94
	if (cr6.lt) goto loc_82788E94;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// twlgei r4,-1
	// b 0x82788ecc
	goto loc_82788ECC;
loc_82788E94:
	// li r10,0
	ctx.r10.s64 = 0;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// b 0x82788ecc
	goto loc_82788ECC;
loc_82788EA0:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788ec8
	if (cr6.lt) goto loc_82788EC8;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// b 0x82788ecc
	goto loc_82788ECC;
loc_82788EC8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82788ECC:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// sth r11,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, r11.u16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// srawi r9,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r9.s64 = r11.s32 >> 1;
	// bge cr6,0x82788f20
	if (!cr6.lt) goto loc_82788F20;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788f14
	if (cr6.lt) goto loc_82788F14;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// twlgei r4,-1
	// b 0x82788f4c
	goto loc_82788F4C;
loc_82788F14:
	// li r10,0
	ctx.r10.s64 = 0;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// b 0x82788f4c
	goto loc_82788F4C;
loc_82788F20:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82788f48
	if (cr6.lt) goto loc_82788F48;
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r11
	ctx.r10.s32 = ctx.r10.s32 / r11.s32;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r11,0
	// andc r4,r11,r9
	ctx.r4.u64 = r11.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// b 0x82788f4c
	goto loc_82788F4C;
loc_82788F48:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82788F4C:
	// sth r10,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r10.u16);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bne 0x82788d54
	if (!cr0.eq) goto loc_82788D54;
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82788ab0
	if (!cr0.eq) goto loc_82788AB0;
loc_82788F74:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82788F7C"))) PPC_WEAK_FUNC(sub_82788F7C);
PPC_FUNC_IMPL(__imp__sub_82788F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82788F80"))) PPC_WEAK_FUNC(sub_82788F80);
PPC_FUNC_IMPL(__imp__sub_82788F80) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82788F88;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-976(r1)
	ea = -976 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// lwz r8,344(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// add r30,r10,r5
	r30.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r27,28(r8)
	r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// lwzx r11,r5,r8
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// beq cr6,0x82789a20
	if (cr6.eq) goto loc_82789A20;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// addi r28,r11,8
	r28.s64 = r11.s64 + 8;
	// subf r26,r11,r10
	r26.s64 = ctx.r10.s64 - r11.s64;
	// subf r25,r11,r8
	r25.s64 = ctx.r8.s64 - r11.s64;
	// subf r24,r11,r7
	r24.s64 = ctx.r7.s64 - r11.s64;
	// subf r23,r11,r5
	r23.s64 = ctx.r5.s64 - r11.s64;
	// subf r22,r11,r4
	r22.s64 = ctx.r4.s64 - r11.s64;
	// subf r21,r11,r3
	r21.s64 = ctx.r3.s64 - r11.s64;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r29,r6,4
	r29.s64 = ctx.r6.s64 + 4;
	// mr r20,r9
	r20.u64 = ctx.r9.u64;
	// lfs f31,-30120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30120);
	f31.f64 = double(temp.f32);
loc_82789000:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,848(r1)
	PPC_STORE_U64(ctx.r1.u32 + 848, ctx.r8.u64);
	// lfd f0,848(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 848);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r6,840(r1)
	PPC_STORE_U64(ctx.r1.u32 + 840, ctx.r6.u64);
	// lfd f11,840(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 840);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r4,856(r1)
	PPC_STORE_U64(ctx.r1.u32 + 856, ctx.r4.u64);
	// lfd f8,856(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 856);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r10,368(r1)
	PPC_STORE_U64(ctx.r1.u32 + 368, ctx.r10.u64);
	// lfd f5,368(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 368);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,108(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r10,-128
	ctx.r8.s64 = ctx.r10.s64 + -128;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, ctx.r7.u64);
	// lfd f2,736(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 736);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,384(r1)
	PPC_STORE_U64(ctx.r1.u32 + 384, ctx.r5.u64);
	// lfd f13,384(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 384);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,624(r1)
	PPC_STORE_U64(ctx.r1.u32 + 624, ctx.r3.u64);
	// lfd f10,624(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 624);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r11,r10,-128
	r11.s64 = ctx.r10.s64 + -128;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// add r11,r31,r9
	r11.u64 = r31.u64 + ctx.r9.u64;
	// std r10,400(r1)
	PPC_STORE_U64(ctx.r1.u32 + 400, ctx.r10.u64);
	// lfd f7,400(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 400);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lbzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// addi r9,r10,-128
	ctx.r9.s64 = ctx.r10.s64 + -128;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,800(r1)
	PPC_STORE_U64(ctx.r1.u32 + 800, ctx.r8.u64);
	// lfd f4,800(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 800);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,128(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r6,416(r1)
	PPC_STORE_U64(ctx.r1.u32 + 416, ctx.r6.u64);
	// lfd f1,416(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 416);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r4,640(r1)
	PPC_STORE_U64(ctx.r1.u32 + 640, ctx.r4.u64);
	// lfd f12,640(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 640);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r10,432(r1)
	PPC_STORE_U64(ctx.r1.u32 + 432, ctx.r10.u64);
	// lfd f9,432(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 432);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,140(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r10,-128
	ctx.r8.s64 = ctx.r10.s64 + -128;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,752(r1)
	PPC_STORE_U64(ctx.r1.u32 + 752, ctx.r7.u64);
	// lfd f6,752(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 752);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,144(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,448(r1)
	PPC_STORE_U64(ctx.r1.u32 + 448, ctx.r5.u64);
	// lfd f3,448(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 448);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// stfs f1,148(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,656(r1)
	PPC_STORE_U64(ctx.r1.u32 + 656, ctx.r3.u64);
	// lfd f0,656(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 656);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r11,r10,-128
	r11.s64 = ctx.r10.s64 + -128;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// std r10,464(r1)
	PPC_STORE_U64(ctx.r1.u32 + 464, ctx.r10.u64);
	// lfd f11,464(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 464);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,156(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lbzx r10,r9,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r31.u32);
	// addi r9,r10,-128
	ctx.r9.s64 = ctx.r10.s64 + -128;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,832(r1)
	PPC_STORE_U64(ctx.r1.u32 + 832, ctx.r8.u64);
	// lfd f8,832(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 832);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,160(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r6,480(r1)
	PPC_STORE_U64(ctx.r1.u32 + 480, ctx.r6.u64);
	// lfd f5,480(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 480);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,164(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,672(r1)
	PPC_STORE_U64(ctx.r1.u32 + 672, ctx.r4.u64);
	// lfd f2,672(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 672);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r10,496(r1)
	PPC_STORE_U64(ctx.r1.u32 + 496, ctx.r10.u64);
	// lfd f13,496(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 496);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,172(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r6,768(r1)
	PPC_STORE_U64(ctx.r1.u32 + 768, ctx.r6.u64);
	// lfd f10,768(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 768);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,176(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,512(r1)
	PPC_STORE_U64(ctx.r1.u32 + 512, ctx.r4.u64);
	// lfd f7,512(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 512);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,180(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,688(r1)
	PPC_STORE_U64(ctx.r1.u32 + 688, ctx.r10.u64);
	// lfd f4,688(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 688);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,184(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// add r11,r31,r9
	r11.u64 = r31.u64 + ctx.r9.u64;
	// std r6,528(r1)
	PPC_STORE_U64(ctx.r1.u32 + 528, ctx.r6.u64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfd f1,528(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 528);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lbzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,816(r1)
	PPC_STORE_U64(ctx.r1.u32 + 816, ctx.r4.u64);
	// lfd f12,816(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 816);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r10,544(r1)
	PPC_STORE_U64(ctx.r1.u32 + 544, ctx.r10.u64);
	// lfd f9,544(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 544);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,196(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r10,-128
	ctx.r9.s64 = ctx.r10.s64 + -128;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,704(r1)
	PPC_STORE_U64(ctx.r1.u32 + 704, ctx.r7.u64);
	// lfd f6,704(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 704);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,200(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,560(r1)
	PPC_STORE_U64(ctx.r1.u32 + 560, ctx.r5.u64);
	// lfd f3,560(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 560);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// stfs f1,204(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r3,784(r1)
	PPC_STORE_U64(ctx.r1.u32 + 784, ctx.r3.u64);
	// lfd f0,784(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 784);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,208(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r7,576(r1)
	PPC_STORE_U64(ctx.r1.u32 + 576, ctx.r7.u64);
	// lfd f11,576(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 576);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,212(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,720(r1)
	PPC_STORE_U64(ctx.r1.u32 + 720, ctx.r5.u64);
	// lfd f8,720(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 720);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,216(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// std r3,592(r1)
	PPC_STORE_U64(ctx.r1.u32 + 592, ctx.r3.u64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfd f5,592(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 592);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,220(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lbzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r31.u32);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// std r7,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r7.u64);
	// lfd f2,352(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 352);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,224(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r5,608(r1)
	PPC_STORE_U64(ctx.r1.u32 + 608, ctx.r5.u64);
	// lfd f13,608(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 608);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,228(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r3,360(r1)
	PPC_STORE_U64(ctx.r1.u32 + 360, ctx.r3.u64);
	// lfd f10,360(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 360);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,232(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,376(r1)
	PPC_STORE_U64(ctx.r1.u32 + 376, ctx.r7.u64);
	// lfd f7,376(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 376);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,236(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,392(r1)
	PPC_STORE_U64(ctx.r1.u32 + 392, ctx.r5.u64);
	// lfd f4,392(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 392);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,240(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,408(r1)
	PPC_STORE_U64(ctx.r1.u32 + 408, ctx.r3.u64);
	// lfd f1,408(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 408);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r7,424(r1)
	PPC_STORE_U64(ctx.r1.u32 + 424, ctx.r7.u64);
	// lfd f12,424(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 424);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,248(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// add r11,r31,r9
	r11.u64 = r31.u64 + ctx.r9.u64;
	// std r5,440(r1)
	PPC_STORE_U64(ctx.r1.u32 + 440, ctx.r5.u64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfd f9,440(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 440);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,252(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lbzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,456(r1)
	PPC_STORE_U64(ctx.r1.u32 + 456, ctx.r3.u64);
	// lfd f6,456(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 456);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,256(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,472(r1)
	PPC_STORE_U64(ctx.r1.u32 + 472, ctx.r7.u64);
	// lfd f3,472(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 472);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// stfs f1,260(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r5,488(r1)
	PPC_STORE_U64(ctx.r1.u32 + 488, ctx.r5.u64);
	// lfd f0,488(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 488);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r3,504(r1)
	PPC_STORE_U64(ctx.r1.u32 + 504, ctx.r3.u64);
	// lfd f11,504(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 504);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,268(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,520(r1)
	PPC_STORE_U64(ctx.r1.u32 + 520, ctx.r7.u64);
	// lfd f8,520(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 520);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,272(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,536(r1)
	PPC_STORE_U64(ctx.r1.u32 + 536, ctx.r5.u64);
	// lfd f5,536(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 536);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,276(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r10,552(r1)
	PPC_STORE_U64(ctx.r1.u32 + 552, ctx.r10.u64);
	// lfd f2,552(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 552);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,280(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// std r6,568(r1)
	PPC_STORE_U64(ctx.r1.u32 + 568, ctx.r6.u64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfd f13,568(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 568);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,284(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// lbzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r31.u32);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,584(r1)
	PPC_STORE_U64(ctx.r1.u32 + 584, ctx.r4.u64);
	// lfd f10,584(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 584);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,288(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r8,600(r1)
	PPC_STORE_U64(ctx.r1.u32 + 600, ctx.r8.u64);
	// lfd f7,600(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 600);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,292(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r6,616(r1)
	PPC_STORE_U64(ctx.r1.u32 + 616, ctx.r6.u64);
	// lfd f4,616(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 616);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,296(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r4,632(r1)
	PPC_STORE_U64(ctx.r1.u32 + 632, ctx.r4.u64);
	// lfd f1,632(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 632);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,300(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r8,648(r1)
	PPC_STORE_U64(ctx.r1.u32 + 648, ctx.r8.u64);
	// lfd f12,648(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 648);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,304(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,664(r1)
	PPC_STORE_U64(ctx.r1.u32 + 664, ctx.r6.u64);
	// lfd f9,664(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 664);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,308(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, ctx.r4.u64);
	// lfd f6,680(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 680);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,312(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// add r11,r31,r9
	r11.u64 = r31.u64 + ctx.r9.u64;
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,696(r1)
	PPC_STORE_U64(ctx.r1.u32 + 696, ctx.r8.u64);
	// lfd f3,696(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 696);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// stfs f1,316(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// lbzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// addi r7,r10,-128
	ctx.r7.s64 = ctx.r10.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,712(r1)
	PPC_STORE_U64(ctx.r1.u32 + 712, ctx.r6.u64);
	// lfd f0,712(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 712);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,320(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r4,728(r1)
	PPC_STORE_U64(ctx.r1.u32 + 728, ctx.r4.u64);
	// lfd f11,728(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 728);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,324(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,744(r1)
	PPC_STORE_U64(ctx.r1.u32 + 744, ctx.r9.u64);
	// lfd f8,744(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 744);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,328(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r10,-128
	ctx.r8.s64 = ctx.r10.s64 + -128;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,760(r1)
	PPC_STORE_U64(ctx.r1.u32 + 760, ctx.r7.u64);
	// lfd f5,760(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 760);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,332(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r6,r10,-128
	ctx.r6.s64 = ctx.r10.s64 + -128;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r5,776(r1)
	PPC_STORE_U64(ctx.r1.u32 + 776, ctx.r5.u64);
	// lfd f2,776(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 776);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,336(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r4,r10,-128
	ctx.r4.s64 = ctx.r10.s64 + -128;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r10,792(r1)
	PPC_STORE_U64(ctx.r1.u32 + 792, ctx.r10.u64);
	// lfd f13,792(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 792);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,340(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r9,r10,-128
	ctx.r9.s64 = ctx.r10.s64 + -128;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,808(r1)
	PPC_STORE_U64(ctx.r1.u32 + 808, ctx.r8.u64);
	// lfd f10,808(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 808);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,344(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r7,r11,-128
	ctx.r7.s64 = r11.s64 + -128;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,824(r1)
	PPC_STORE_U64(ctx.r1.u32 + 824, ctx.r6.u64);
	// lfd f7,824(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 824);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,348(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// mtctr r27
	ctr.u64 = r27.u64;
	// bctrl 
	ctx.lr = 0x827898EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,8
	ctx.r8.s64 = 8;
loc_827898FC:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lfs f13,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f13,f31
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64 + f31.f64));
	// lfs f11,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r26,r11
	temp.u32 = PPC_LOAD_U32(r26.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// lfsx f9,r25,r11
	temp.u32 = PPC_LOAD_U32(r25.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f7,r23,r11
	temp.u32 = PPC_LOAD_U32(r23.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f6,r22,r11
	temp.u32 = PPC_LOAD_U32(r22.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fctiwz f4,f12
	ctx.f4.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r7,-16384
	ctx.r7.s64 = ctx.r7.s64 + -16384;
	// sth r7,-4(r10)
	PPC_STORE_U16(ctx.r10.u32 + -4, ctx.r7.u16);
	// lfs f3,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f3,f11,f31
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + f31.f64));
	// fctiwz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r7,-16384
	ctx.r5.s64 = ctx.r7.s64 + -16384;
	// sth r5,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, ctx.r5.u16);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmadds f13,f10,f0,f31
	ctx.f13.f64 = double(float(ctx.f10.f64 * f0.f64 + f31.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r7,-16384
	ctx.r3.s64 = ctx.r7.s64 + -16384;
	// sth r3,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r3.u16);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f9,f11,f31
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + f31.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r7,-16384
	ctx.r6.s64 = ctx.r7.s64 + -16384;
	// sth r6,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r6.u16);
	// lfs f4,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f8,f4,f31
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f4.f64 + f31.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r7,-16384
	ctx.r4.s64 = ctx.r7.s64 + -16384;
	// sth r4,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r4.u16);
	// lfs f1,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f0,f7,f1,f31
	f0.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r7,-16384
	ctx.r7.s64 = ctx.r7.s64 + -16384;
	// sth r7,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r7.u16);
	// lfs f12,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f6,f12,f31
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f12.f64 + f31.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r7,-16384
	ctx.r5.s64 = ctx.r7.s64 + -16384;
	// sth r5,8(r10)
	PPC_STORE_U16(ctx.r10.u32 + 8, ctx.r5.u16);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f5,f9,f31
	ctx.f8.f64 = double(float(ctx.f5.f64 * ctx.f9.f64 + f31.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r7,-16384
	ctx.r3.s64 = ctx.r7.s64 + -16384;
	// sth r3,10(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10, ctx.r3.u16);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x827898fc
	if (!cr0.eq) goto loc_827898FC;
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82789000
	if (!cr0.eq) goto loc_82789000;
loc_82789A20:
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82789A2C"))) PPC_WEAK_FUNC(sub_82789A2C);
PPC_FUNC_IMPL(__imp__sub_82789A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82789A30"))) PPC_WEAK_FUNC(sub_82789A30);
PPC_FUNC_IMPL(__imp__sub_82789A30) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82789A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32135
	ctx.r9.s64 = -2105999360;
	// stw r30,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r30.u32);
	// addi r8,r9,-31168
	ctx.r8.s64 = ctx.r9.s64 + -31168;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82789ad4
	if (cr6.lt) goto loc_82789AD4;
	// beq cr6,0x82789ac8
	if (cr6.eq) goto loc_82789AC8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x82789ab0
	if (cr6.lt) goto loc_82789AB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,48
	ctx.r10.s64 = 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82789AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82789aec
	goto loc_82789AEC;
loc_82789AB0:
	// lis r10,-32135
	ctx.r10.s64 = -2105999360;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r8,r10,-6920
	ctx.r8.s64 = ctx.r10.s64 + -6920;
	// addi r9,r11,-28800
	ctx.r9.s64 = r11.s64 + -28800;
	// stw r8,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r8.u32);
	// b 0x82789ae8
	goto loc_82789AE8;
loc_82789AC8:
	// lis r10,-32135
	ctx.r10.s64 = -2105999360;
	// addi r8,r10,-8848
	ctx.r8.s64 = ctx.r10.s64 + -8848;
	// b 0x82789adc
	goto loc_82789ADC;
loc_82789AD4:
	// lis r10,-32135
	ctx.r10.s64 = -2105999360;
	// addi r8,r10,-9504
	ctx.r8.s64 = ctx.r10.s64 + -9504;
loc_82789ADC:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// addi r9,r11,-30120
	ctx.r9.s64 = r11.s64 + -30120;
loc_82789AE8:
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
loc_82789AEC:
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82789AF8:
	// stw r9,-20(r11)
	PPC_STORE_U32(r11.u32 + -20, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82789af8
	if (!cr0.eq) goto loc_82789AF8;
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

__attribute__((alias("__imp__sub_82789B24"))) PPC_WEAK_FUNC(sub_82789B24);
PPC_FUNC_IMPL(__imp__sub_82789B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82789B28"))) PPC_WEAK_FUNC(sub_82789B28);
PPC_FUNC_IMPL(__imp__sub_82789B28) {
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
	// lwz r30,324(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// beq cr6,0x82789b68
	if (cr6.eq) goto loc_82789B68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82789B68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82789B68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r11.u32);
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// stw r10,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r10.u32);
	// lwz r9,220(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82789BA0"))) PPC_WEAK_FUNC(sub_82789BA0);
PPC_FUNC_IMPL(__imp__sub_82789BA0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x82789BA8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r17,r6
	r17.u64 = ctx.r6.u64;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r19,r8
	r19.u64 = ctx.r8.u64;
	// lwz r30,324(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 324);
	// mr r15,r9
	r15.u64 = ctx.r9.u64;
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// bge cr6,0x82789dcc
	if (!cr6.lt) goto loc_82789DCC;
	// li r16,0
	r16.s64 = 0;
loc_82789BDC:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// bge cr6,0x82789dcc
	if (!cr6.lt) goto loc_82789DCC;
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r9,220(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 220);
	// lwz r6,52(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// subf r10,r11,r17
	ctx.r10.s64 = r17.s64 - r11.s64;
	// subf r31,r6,r9
	r31.s64 = ctx.r9.s64 - ctx.r6.s64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x82789c08
	if (cr6.lt) goto loc_82789C08;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_82789C08:
	// lwz r10,336(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 336);
	// addi r21,r30,8
	r21.s64 = r30.s64 + 8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// add r4,r11,r18
	ctx.r4.u64 = r11.u64 + r18.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82789C30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stw r8,0(r20)
	PPC_STORE_U32(r20.u32 + 0, ctx.r8.u32);
	// lwz r7,48(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// subf. r6,r31,r7
	ctx.r6.s64 = ctx.r7.s64 - r31.s64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r11,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r11.u32);
	// stw r6,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r6.u32);
	// bne 0x82789cd8
	if (!cr0.eq) goto loc_82789CD8;
	// lwz r10,220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 220);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82789cd8
	if (!cr6.lt) goto loc_82789CD8;
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// mr r22,r16
	r22.u64 = r16.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82789cd0
	if (!cr6.gt) goto loc_82789CD0;
	// mr r23,r21
	r23.u64 = r21.u64;
loc_82789C78:
	// lwz r31,52(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r27,220(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 220);
	// lwz r26,28(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r29,0(r23)
	r29.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// bge cr6,0x82789cbc
	if (!cr6.lt) goto loc_82789CBC;
	// addi r25,r31,-1
	r25.s64 = r31.s64 + -1;
loc_82789C94:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277a378
	ctx.lr = 0x82789CB0;
	sub_8277A378(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x82789c94
	if (cr6.lt) goto loc_82789C94;
loc_82789CBC:
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// blt cr6,0x82789c78
	if (cr6.lt) goto loc_82789C78;
loc_82789CD0:
	// lwz r11,220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 220);
	// stw r11,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r11.u32);
loc_82789CD8:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r10,220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 220);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82789d1c
	if (!cr6.eq) goto loc_82789D1C;
	// lwz r11,340(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 340);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lwz r7,0(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82789D0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r16,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r16.u32);
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r19)
	PPC_STORE_U32(r19.u32 + 0, ctx.r9.u32);
loc_82789D1C:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82789d34
	if (!cr6.eq) goto loc_82789D34;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// blt cr6,0x82789d48
	if (cr6.lt) goto loc_82789D48;
loc_82789D34:
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// blt cr6,0x82789bdc
	if (cr6.lt) goto loc_82789BDC;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9214
	return;
loc_82789D48:
	// lwz r10,60(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// mr r23,r16
	r23.u64 = r16.u64;
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82789dc8
	if (!cr6.gt) goto loc_82789DC8;
	// addi r26,r11,12
	r26.s64 = r11.s64 + 12;
loc_82789D60:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// mullw r29,r11,r15
	r29.s64 = int64_t(r11.s32) * int64_t(r15.s32);
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mullw r31,r11,r10
	r31.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r27,r9,3,0,28
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x82789db0
	if (!cr6.lt) goto loc_82789DB0;
	// addi r25,r31,-1
	r25.s64 = r31.s64 + -1;
loc_82789D88:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277a378
	ctx.lr = 0x82789DA4;
	sub_8277A378(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82789d88
	if (cr6.lt) goto loc_82789D88;
loc_82789DB0:
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// addi r26,r26,84
	r26.s64 = r26.s64 + 84;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82789d60
	if (cr6.lt) goto loc_82789D60;
loc_82789DC8:
	// stw r15,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r15.u32);
loc_82789DCC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_82789DD4"))) PPC_WEAK_FUNC(sub_82789DD4);
PPC_FUNC_IMPL(__imp__sub_82789DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82789DD8"))) PPC_WEAK_FUNC(sub_82789DD8);
PPC_FUNC_IMPL(__imp__sub_82789DD8) {
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
	ctx.lr = 0x82789DE0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// mr r15,r9
	r15.u64 = ctx.r9.u64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r28,324(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 324);
	// cmplw cr6,r9,r15
	cr6.compare<uint32_t>(ctx.r9.u32, r15.u32, xer);
	// add r21,r11,r10
	r21.u64 = r11.u64 + ctx.r10.u64;
	// bge cr6,0x8278a028
	if (!cr6.lt) goto loc_8278A028;
	// li r16,0
	r16.s64 = 0;
loc_82789E20:
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplw cr6,r11,r19
	cr6.compare<uint32_t>(r11.u32, r19.u32, xer);
	// bge cr6,0x82789f10
	if (!cr6.lt) goto loc_82789F10;
	// lwz r9,60(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// subf r10,r11,r19
	ctx.r10.s64 = r19.s64 - r11.s64;
	// lwz r6,52(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// subf r26,r6,r9
	r26.s64 = ctx.r9.s64 - ctx.r6.s64;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// blt cr6,0x82789e48
	if (cr6.lt) goto loc_82789E48;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
loc_82789E48:
	// lwz r10,336(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 336);
	// addi r27,r28,8
	r27.s64 = r28.s64 + 8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r4,r11,r17
	ctx.r4.u64 = r11.u64 + r17.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82789E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,48(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bne cr6,0x82789ee8
	if (!cr6.eq) goto loc_82789EE8;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r25,r16
	r25.u64 = r16.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82789ee8
	if (!cr6.gt) goto loc_82789EE8;
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
loc_82789E94:
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x82789ed4
	if (cr6.lt) goto loc_82789ED4;
	// li r31,-1
	r31.s64 = -1;
loc_82789EA4:
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277a378
	ctx.lr = 0x82789EC0;
	sub_8277A378(ctx, base);
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// ble cr6,0x82789ea4
	if (!cr6.gt) goto loc_82789EA4;
loc_82789ED4:
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// blt cr6,0x82789e94
	if (cr6.lt) goto loc_82789E94;
loc_82789EE8:
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// subf r8,r26,r10
	ctx.r8.s64 = ctx.r10.s64 - r26.s64;
	// add r9,r11,r26
	ctx.r9.u64 = r11.u64 + r26.u64;
	// stw r8,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r8.u32);
	// stw r9,52(r28)
	PPC_STORE_U32(r28.u32 + 52, ctx.r9.u32);
	// b 0x82789fa0
	goto loc_82789FA0;
loc_82789F10:
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8278a028
	if (!cr6.eq) goto loc_8278A028;
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82789fa0
	if (!cr6.lt) goto loc_82789FA0;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r23,r16
	r23.u64 = r16.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82789f98
	if (!cr6.gt) goto loc_82789F98;
	// addi r24,r28,8
	r24.s64 = r28.s64 + 8;
loc_82789F40:
	// lwz r31,52(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// lwz r27,60(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwz r26,28(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwz r29,0(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// bge cr6,0x82789f84
	if (!cr6.lt) goto loc_82789F84;
	// addi r25,r31,-1
	r25.s64 = r31.s64 + -1;
loc_82789F5C:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277a378
	ctx.lr = 0x82789F78;
	sub_8277A378(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x82789f5c
	if (cr6.lt) goto loc_82789F5C;
loc_82789F84:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82789f40
	if (cr6.lt) goto loc_82789F40;
loc_82789F98:
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// stw r11,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r11.u32);
loc_82789FA0:
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// lwz r10,60(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8278a01c
	if (!cr6.eq) goto loc_8278A01C;
	// lwz r11,340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 340);
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// lwz r5,56(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82789FD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r9.u32);
	// lwz r10,56(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,56(r28)
	PPC_STORE_U32(r28.u32 + 56, r11.u32);
	// cmpw cr6,r11,r21
	cr6.compare<int32_t>(r11.s32, r21.s32, xer);
	// blt cr6,0x82789ffc
	if (cr6.lt) goto loc_82789FFC;
	// stw r16,56(r28)
	PPC_STORE_U32(r28.u32 + 56, r16.u32);
loc_82789FFC:
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmpw cr6,r11,r21
	cr6.compare<int32_t>(r11.s32, r21.s32, xer);
	// blt cr6,0x8278a00c
	if (cr6.lt) goto loc_8278A00C;
	// stw r16,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r16.u32);
loc_8278A00C:
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,60(r28)
	PPC_STORE_U32(r28.u32 + 60, r11.u32);
loc_8278A01C:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// blt cr6,0x82789e20
	if (cr6.lt) goto loc_82789E20;
loc_8278A028:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8278A030"))) PPC_WEAK_FUNC(sub_8278A030);
PPC_FUNC_IMPL(__imp__sub_8278A030) {
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
	ctx.lr = 0x8278A038;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r31,220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 220);
	// lwz r11,60(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// lwz r30,324(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 324);
	// mullw r11,r11,r31
	r11.s64 = int64_t(r11.s32) * int64_t(r31.s32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8278A070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,60(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8278a180
	if (!cr6.gt) goto loc_8278A180;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r31,r11
	ctx.r7.u64 = r31.u64 + r11.u64;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r31,r9
	ctx.r6.u64 = r31.u64 + ctx.r9.u64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r22,r31,r10
	r22.u64 = r31.u64 + ctx.r10.u64;
	// rlwinm r21,r6,2,0,29
	r21.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r24,r7,2,0,29
	r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r8,8
	r27.s64 = ctx.r8.s64 + 8;
	// add r26,r11,r28
	r26.u64 = r11.u64 + r28.u64;
	// addi r25,r30,8
	r25.s64 = r30.s64 + 8;
loc_8278A0B8:
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lwz r10,216(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 216);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// twllei r9,0
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r5,r8,r9
	ctx.r5.s32 = ctx.r8.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// andc r11,r9,r7
	r11.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twlgei r11,-1
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278A100;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823da950
	ctx.lr = 0x8278A114;
	sub_823DA950(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8278a15c
	if (!cr6.gt) goto loc_8278A15C;
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 + r28.u64;
	// add r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 + r30.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r7,r30,r28
	ctx.r7.s64 = r28.s64 - r30.s64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8278A138:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stwx r6,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r6.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8278a138
	if (!cr0.eq) goto loc_8278A138;
loc_8278A15C:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// stw r26,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r26.u32);
	// lwz r11,60(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// add r28,r24,r28
	r28.u64 = r24.u64 + r28.u64;
	// add r26,r26,r24
	r26.u64 = r26.u64 + r24.u64;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// addi r27,r27,84
	r27.s64 = r27.s64 + 84;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x8278a0b8
	if (cr6.lt) goto loc_8278A0B8;
loc_8278A180:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8278A188"))) PPC_WEAK_FUNC(sub_8278A188);
PPC_FUNC_IMPL(__imp__sub_8278A188) {
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
	ctx.lr = 0x8278A190;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278a1c0
	if (cr6.eq) goto loc_8278A1C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8278A1C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278A1C0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278A1DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32135
	ctx.r9.s64 = -2105999360;
	// stw r11,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r11.u32);
	// addi r8,r9,-25816
	ctx.r8.s64 = ctx.r9.s64 + -25816;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r7,340(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lbz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8278a21c
	if (cr6.eq) goto loc_8278A21C;
	// lis r10,-32135
	ctx.r10.s64 = -2105999360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-25128
	ctx.r9.s64 = ctx.r10.s64 + -25128;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bl 0x8278a030
	ctx.lr = 0x8278A214;
	sub_8278A030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8278A21C:
	// lis r10,-32135
	ctx.r10.s64 = -2105999360;
	// li r28,0
	r28.s64 = 0;
	// addi r9,r10,-25696
	ctx.r9.s64 = ctx.r10.s64 + -25696;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8278a2a8
	if (!cr6.gt) goto loc_8278A2A8;
	// addi r30,r10,8
	r30.s64 = ctx.r10.s64 + 8;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
loc_8278A244:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,220(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// twllei r9,0
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r5,r8,r9
	ctx.r5.s32 = ctx.r8.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// andc r11,r9,r7
	r11.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twlgei r11,-1
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278A28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x8278a244
	if (cr6.lt) goto loc_8278A244;
loc_8278A2A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8278A2B0"))) PPC_WEAK_FUNC(sub_8278A2B0);
PPC_FUNC_IMPL(__imp__sub_8278A2B0) {
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
	ctx.lr = 0x8278A2B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r10,60(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwz r11,340(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 340);
	// lwz r30,68(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8278a338
	if (!cr6.gt) goto loc_8278A338;
	// rlwinm r26,r5,2,0,29
	r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r29,r11,12
	r29.s64 = r11.s64 + 12;
	// subf r25,r4,r6
	r25.s64 = ctx.r6.s64 - ctx.r4.s64;
loc_8278A2EC:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r10,r25,r31
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r31.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mullw r8,r11,r24
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(r24.s32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r26
	ctx.r5.u64 = ctx.r9.u64 + r26.u64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8278A31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,60(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r27,r6
	cr6.compare<int32_t>(r27.s32, ctx.r6.s32, xer);
	// blt cr6,0x8278a2ec
	if (cr6.lt) goto loc_8278A2EC;
loc_8278A338:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8278A340"))) PPC_WEAK_FUNC(sub_8278A340);
PPC_FUNC_IMPL(__imp__sub_8278A340) {
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8278A348;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// lwz r8,216(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// lwz r30,12(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lwz r29,28(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// divw r26,r11,r30
	r26.s32 = r11.s32 / r30.s32;
	// divw r31,r8,r7
	r31.s32 = ctx.r8.s32 / ctx.r7.s32;
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r22,r29,3,0,28
	r22.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r28,r26,r31
	r28.s64 = int64_t(r26.s32) * int64_t(r31.s32);
	// andc r3,r30,r3
	ctx.r3.u64 = r30.u64 & ~ctx.r3.u64;
	// twllei r7,0
	// twllei r30,0
	// andc r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// mullw r9,r31,r22
	ctx.r9.s64 = int64_t(r31.s32) * int64_t(r22.s32);
	// srawi r30,r28,1
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x1) != 0);
	r30.s64 = r28.s32 >> 1;
	// subf. r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// twlgei r7,-1
	// twlgei r3,-1
	// addze r24,r30
	temp.s64 = r30.s64 + xer.ca;
	xer.ca = temp.u32 < r30.u32;
	r24.s64 = temp.s64;
	// ble 0x8278a3ec
	if (!cr0.gt) goto loc_8278A3EC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a3ec
	if (!cr6.gt) goto loc_8278A3EC;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8278A3BC:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278a3e0
	if (cr6.eq) goto loc_8278A3E0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8278A3D4:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278a3d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278A3D4;
loc_8278A3E0:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8278a3bc
	if (!cr0.eq) goto loc_8278A3BC;
loc_8278A3EC:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a4a8
	if (!cr6.gt) goto loc_8278A4A8;
	// rlwinm r23,r26,2,0,29
	r23.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
loc_8278A404:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8278a490
	if (cr6.eq) goto loc_8278A490;
	// mr r29,r22
	r29.u64 = r22.u64;
loc_8278A418:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x8278a460
	if (!cr6.gt) goto loc_8278A460;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8278A42C:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// ble cr6,0x8278a454
	if (!cr6.gt) goto loc_8278A454;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8278A440:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// bne 0x8278a440
	if (!cr0.eq) goto loc_8278A440;
loc_8278A454:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8278a42c
	if (!cr0.eq) goto loc_8278A42C;
loc_8278A460:
	// add r10,r8,r24
	ctx.r10.u64 = ctx.r8.u64 + r24.u64;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r9,r10,r28
	ctx.r9.s32 = ctx.r10.s32 / r28.s32;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// twllei r28,0
	// andc r3,r28,r8
	ctx.r3.u64 = r28.u64 & ~ctx.r8.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// twlgei r3,-1
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + r31.u64;
	// bne 0x8278a418
	if (!cr0.eq) goto loc_8278A418;
loc_8278A490:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// add r5,r23,r5
	ctx.r5.u64 = r23.u64 + ctx.r5.u64;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8278a404
	if (cr6.lt) goto loc_8278A404;
loc_8278A4A8:
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8278A4AC"))) PPC_WEAK_FUNC(sub_8278A4AC);
PPC_FUNC_IMPL(__imp__sub_8278A4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278A4B0"))) PPC_WEAK_FUNC(sub_8278A4B0);
PPC_FUNC_IMPL(__imp__sub_8278A4B0) {
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
	ctx.lr = 0x8278A4B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,220(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// bl 0x8277a378
	ctx.lr = 0x8278A4E4;
	sub_8277A378(ctx, base);
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// subf. r8,r7,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble 0x8278a53c
	if (!cr0.gt) goto loc_8278A53C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a53c
	if (!cr6.gt) goto loc_8278A53C;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
loc_8278A50C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278a530
	if (cr6.eq) goto loc_8278A530;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8278A524:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278a524
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278A524;
loc_8278A530:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8278a50c
	if (!cr0.eq) goto loc_8278A50C;
loc_8278A53C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8278A544"))) PPC_WEAK_FUNC(sub_8278A544);
PPC_FUNC_IMPL(__imp__sub_8278A544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278A548"))) PPC_WEAK_FUNC(sub_8278A548);
PPC_FUNC_IMPL(__imp__sub_8278A548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r30,r11,3,0,28
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r7,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble 0x8278a5ac
	if (!cr0.gt) goto loc_8278A5AC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a5ac
	if (!cr6.gt) goto loc_8278A5AC;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8278A57C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278a5a0
	if (cr6.eq) goto loc_8278A5A0;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8278A594:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278a594
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278A594;
loc_8278A5A0:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8278a57c
	if (!cr0.eq) goto loc_8278A57C;
loc_8278A5AC:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a618
	if (!cr6.gt) goto loc_8278A618;
	// subf r3,r5,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r5.s64;
loc_8278A5C0:
	// lwzx r9,r3,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8278a604
	if (cr6.eq) goto loc_8278A604;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
loc_8278A5D8:
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// srawi r6,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stb r6,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r6.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne 0x8278a5d8
	if (!cr0.eq) goto loc_8278A5D8;
loc_8278A604:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8278a5c0
	if (cr6.lt) goto loc_8278A5C0;
loc_8278A618:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8278A624"))) PPC_WEAK_FUNC(sub_8278A624);
PPC_FUNC_IMPL(__imp__sub_8278A624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278A628"))) PPC_WEAK_FUNC(sub_8278A628);
PPC_FUNC_IMPL(__imp__sub_8278A628) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8278A630;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r28,r11,3,0,28
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r7,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble 0x8278a68c
	if (!cr0.gt) goto loc_8278A68C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a68c
	if (!cr6.gt) goto loc_8278A68C;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8278A65C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278a680
	if (cr6.eq) goto loc_8278A680;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8278A674:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278a674
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278A674;
loc_8278A680:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8278a65c
	if (!cr0.eq) goto loc_8278A65C;
loc_8278A68C:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a718
	if (!cr6.gt) goto loc_8278A718;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
loc_8278A6A4:
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// beq cr6,0x8278a700
	if (cr6.eq) goto loc_8278A700;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
loc_8278A6C0:
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 + ctx.r3.u64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// xori r9,r9,3
	ctx.r9.u64 = ctx.r9.u64 ^ 3;
	// srawi r5,r6,2
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 2;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stb r5,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r5.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bne 0x8278a6c0
	if (!cr0.eq) goto loc_8278A6C0;
loc_8278A700:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8278a6a4
	if (cr6.lt) goto loc_8278A6A4;
loc_8278A718:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8278A71C"))) PPC_WEAK_FUNC(sub_8278A71C);
PPC_FUNC_IMPL(__imp__sub_8278A71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278A720"))) PPC_WEAK_FUNC(sub_8278A720);
PPC_FUNC_IMPL(__imp__sub_8278A720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8278A728;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r30,r11,3,0,28
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// subf. r9,r7,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble 0x8278a788
	if (!cr0.gt) goto loc_8278A788;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278a788
	if (!cr6.gt) goto loc_8278A788;
	// addi r8,r5,-4
	ctx.r8.s64 = ctx.r5.s64 + -4;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8278A758:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278a77c
	if (cr6.eq) goto loc_8278A77C;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8278A770:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278a770
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278A770;
loc_8278A77C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8278a758
	if (!cr0.eq) goto loc_8278A758;
loc_8278A788:
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// li r18,0
	r18.s64 = 0;
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r11,4,0,27
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subfic r27,r7,16384
	xer.ca = ctx.r7.u32 <= 16384;
	r27.s64 = 16384 - ctx.r7.s64;
	// ble cr6,0x8278a9d0
	if (!cr6.gt) goto loc_8278A9D0;
	// lis r11,0
	r11.s64 = 0;
	// addi r17,r30,-2
	r17.s64 = r30.s64 + -2;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// addi r29,r5,-4
	r29.s64 = ctx.r5.s64 + -4;
	// ori r7,r11,32768
	ctx.r7.u64 = r11.u64 | 32768;
loc_8278A7C4:
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// lwz r31,12(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r8,r6,2
	ctx.r8.s64 = ctx.r6.s64 + 2;
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r10,r3,2
	ctx.r10.s64 = ctx.r3.s64 + 2;
	// lwz r26,0(r19)
	r26.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lbz r25,1(r6)
	r25.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1);
	// addi r11,r30,2
	r11.s64 = r30.s64 + 2;
	// lbz r24,1(r31)
	r24.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lbz r22,2(r3)
	r22.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// add r25,r24,r25
	r25.u64 = r24.u64 + r25.u64;
	// lbz r23,0(r3)
	r23.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r3,1(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// add r22,r25,r22
	r22.u64 = r25.u64 + r22.u64;
	// lbz r25,0(r6)
	r25.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r6,2(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// lbz r24,0(r30)
	r24.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// add r22,r22,r6
	r22.u64 = r22.u64 + ctx.r6.u64;
	// lbz r20,1(r30)
	r20.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// lbz r31,0(r31)
	r31.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r6,r26,1
	ctx.r6.s64 = r26.s64 + 1;
	// add r30,r22,r23
	r30.u64 = r22.u64 + r23.u64;
	// lbz r21,0(r8)
	r21.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// add r3,r20,r3
	ctx.r3.u64 = r20.u64 + ctx.r3.u64;
	// lbz r22,0(r9)
	r22.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// add r30,r30,r24
	r30.u64 = r30.u64 + r24.u64;
	// add r3,r3,r23
	ctx.r3.u64 = ctx.r3.u64 + r23.u64;
	// add r30,r30,r25
	r30.u64 = r30.u64 + r25.u64;
	// add r3,r3,r24
	ctx.r3.u64 = ctx.r3.u64 + r24.u64;
	// add r24,r30,r31
	r24.u64 = r30.u64 + r31.u64;
	// mullw r30,r3,r27
	r30.s64 = int64_t(ctx.r3.s32) * int64_t(r27.s32);
	// rlwinm r3,r24,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r3,r21
	ctx.r3.u64 = ctx.r3.u64 + r21.u64;
	// add r3,r3,r22
	ctx.r3.u64 = ctx.r3.u64 + r22.u64;
	// add r3,r3,r25
	ctx.r3.u64 = ctx.r3.u64 + r25.u64;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// mullw r3,r3,r28
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r28.s32);
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + r30.u64;
	// add r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 + ctx.r7.u64;
	// srawi r3,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// stb r3,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r3.u8);
	// beq cr6,0x8278a934
	if (cr6.eq) goto loc_8278A934;
loc_8278A87C:
	// lbz r31,1(r9)
	r31.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// addi r3,r8,2
	ctx.r3.s64 = ctx.r8.s64 + 2;
	// lbz r30,1(r8)
	r30.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r26,-1(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// add r30,r31,r30
	r30.u64 = r31.u64 + r30.u64;
	// lbz r24,-1(r10)
	r24.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r25,0(r9)
	r25.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r31,r9,2
	r31.s64 = ctx.r9.s64 + 2;
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// lbz r22,0(r8)
	r22.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r26,2(r10)
	r26.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// add r30,r30,r24
	r30.u64 = r30.u64 + r24.u64;
	// lbz r23,1(r11)
	r23.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r20,1(r10)
	r20.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// add r30,r30,r25
	r30.u64 = r30.u64 + r25.u64;
	// lbz r21,2(r11)
	r21.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r25,-1(r8)
	r25.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// add r30,r30,r22
	r30.u64 = r30.u64 + r22.u64;
	// lbz r22,0(r11)
	r22.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r24,-1(r9)
	r24.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// lbz r26,0(r3)
	r26.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// add r3,r23,r20
	ctx.r3.u64 = r23.u64 + r20.u64;
	// lbz r23,0(r10)
	r23.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// add r21,r30,r21
	r21.u64 = r30.u64 + r21.u64;
	// lbz r30,0(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// add r31,r3,r22
	r31.u64 = ctx.r3.u64 + r22.u64;
	// rlwinm r3,r21,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 1) & 0xFFFFFFFE;
	// add r31,r31,r23
	r31.u64 = r31.u64 + r23.u64;
	// add r3,r3,r24
	ctx.r3.u64 = ctx.r3.u64 + r24.u64;
	// mullw r31,r31,r27
	r31.s64 = int64_t(r31.s32) * int64_t(r27.s32);
	// add r3,r3,r25
	ctx.r3.u64 = ctx.r3.u64 + r25.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// add r3,r3,r26
	ctx.r3.u64 = ctx.r3.u64 + r26.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + r30.u64;
	// mullw r3,r3,r28
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r28.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// add r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 + ctx.r7.u64;
	// srawi r3,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stb r3,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r3.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// bne 0x8278a87c
	if (!cr0.eq) goto loc_8278A87C;
loc_8278A934:
	// lbz r5,-1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// lbz r31,-1(r10)
	r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lbz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r19,r19,4
	r19.s64 = r19.s64 + 4;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + r31.u64;
	// lbz r26,0(r8)
	r26.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r30,1(r10)
	r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r31,1(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r3,1(r8)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// add r25,r5,r26
	r25.u64 = ctx.r5.u64 + r26.u64;
	// lbz r5,1(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r26,-1(r9)
	r26.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1);
	// add r25,r25,r30
	r25.u64 = r25.u64 + r30.u64;
	// lbz r9,-1(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// add r25,r25,r31
	r25.u64 = r25.u64 + r31.u64;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r10,r25,r3
	ctx.r10.u64 = r25.u64 + ctx.r3.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// add r8,r10,r5
	ctx.r8.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// mullw r10,r10,r27
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r27.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// add r9,r11,r5
	ctx.r9.u64 = r11.u64 + ctx.r5.u64;
	// mullw r11,r9,r28
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r28.s32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// add r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r3,r5,16
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 16;
	// stb r3,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r3.u8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpw cr6,r18,r10
	cr6.compare<int32_t>(r18.s32, ctx.r10.s32, xer);
	// blt cr6,0x8278a7c4
	if (cr6.lt) goto loc_8278A7C4;
loc_8278A9D0:
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8278A9D4"))) PPC_WEAK_FUNC(sub_8278A9D4);
PPC_FUNC_IMPL(__imp__sub_8278A9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278A9D8"))) PPC_WEAK_FUNC(sub_8278A9D8);
PPC_FUNC_IMPL(__imp__sub_8278A9D8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8278A9E0;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r30,r11,3,0,28
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// subf. r9,r7,r30
	ctx.r9.s64 = r30.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// ble 0x8278aa3c
	if (!cr0.gt) goto loc_8278AA3C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278aa3c
	if (!cr6.gt) goto loc_8278AA3C;
	// addi r8,r5,-4
	ctx.r8.s64 = ctx.r5.s64 + -4;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8278AA0C:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// beq cr6,0x8278aa30
	if (cr6.eq) goto loc_8278AA30;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8278AA24:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8278aa24
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8278AA24;
loc_8278AA30:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8278aa0c
	if (!cr0.eq) goto loc_8278AA0C;
loc_8278AA3C:
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// li r21,0
	r21.s64 = 0;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// subfic r9,r11,128
	xer.ca = r11.u32 <= 128;
	ctx.r9.s64 = 128 - r11.s64;
	// rlwinm r28,r11,6,0,25
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r27,r9,9,0,22
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0xFFFFFE00;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8278ab88
	if (!cr6.gt) goto loc_8278AB88;
	// lis r11,0
	r11.s64 = 0;
	// addi r22,r30,-2
	r22.s64 = r30.s64 + -2;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// addi r29,r5,4
	r29.s64 = ctx.r5.s64 + 4;
	// ori r7,r11,32768
	ctx.r7.u64 = r11.u64 | 32768;
loc_8278AA70:
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r10,-8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -8);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r5,-4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// addi r8,r6,1
	ctx.r8.s64 = ctx.r6.s64 + 1;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r30,0(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// lbz r31,0(r6)
	r31.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r5,0(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// add r31,r31,r10
	r31.u64 = r31.u64 + ctx.r10.u64;
	// lbz r24,0(r9)
	r24.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// mullw r25,r5,r27
	r25.s64 = int64_t(ctx.r5.s32) * int64_t(r27.s32);
	// lbz r26,0(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r31,r31,r5
	r31.u64 = r31.u64 + ctx.r5.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + r24.u64;
	// rlwinm r24,r31,1,0,30
	r24.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + r26.u64;
	// subf r5,r5,r24
	ctx.r5.s64 = r24.s64 - ctx.r5.s64;
	// add r26,r5,r10
	r26.u64 = ctx.r5.u64 + ctx.r10.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// mullw r26,r26,r28
	r26.s64 = int64_t(r26.s32) * int64_t(r28.s32);
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// add r26,r26,r7
	r26.u64 = r26.u64 + ctx.r7.u64;
	// srawi r26,r26,16
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0xFFFF) != 0);
	r26.s64 = r26.s32 >> 16;
	// stb r26,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r26.u8);
	// beq cr6,0x8278ab48
	if (cr6.eq) goto loc_8278AB48;
loc_8278AAEC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subf r30,r10,r31
	r30.s64 = r31.s64 - ctx.r10.s64;
	// mullw r26,r10,r27
	r26.s64 = int64_t(ctx.r10.s32) * int64_t(r27.s32);
	// lbz r25,0(r9)
	r25.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r31,0(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// add r30,r30,r10
	r30.u64 = r30.u64 + ctx.r10.u64;
	// add r30,r30,r5
	r30.u64 = r30.u64 + ctx.r5.u64;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// mullw r30,r30,r28
	r30.s64 = int64_t(r30.s32) * int64_t(r28.s32);
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// add r30,r30,r7
	r30.u64 = r30.u64 + ctx.r7.u64;
	// srawi r30,r30,16
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFFFF) != 0);
	r30.s64 = r30.s32 >> 16;
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stb r30,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r30.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// bne 0x8278aaec
	if (!cr0.eq) goto loc_8278AAEC;
loc_8278AB48:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// mullw r10,r9,r27
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(r27.s32);
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// mullw r11,r5,r28
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(r28.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// add r11,r3,r7
	r11.u64 = ctx.r3.u64 + ctx.r7.u64;
	// srawi r10,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = r11.s32 >> 16;
	// stb r10,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r10.u8);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpw cr6,r21,r8
	cr6.compare<int32_t>(r21.s32, ctx.r8.s32, xer);
	// blt cr6,0x8278aa70
	if (cr6.lt) goto loc_8278AA70;
loc_8278AB88:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8278AB8C"))) PPC_WEAK_FUNC(sub_8278AB8C);
PPC_FUNC_IMPL(__imp__sub_8278AB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278AB90"))) PPC_WEAK_FUNC(sub_8278AB90);
PPC_FUNC_IMPL(__imp__sub_8278AB90) {
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
	ctx.lr = 0x8278AB98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,1
	r25.s64 = 1;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r26,r25
	r26.u64 = r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278ABC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32135
	ctx.r8.s64 = -2105999360;
	// stw r28,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r28.u32);
	// addi r7,r9,0
	ctx.r7.s64 = ctx.r9.s64 + 0;
	// addi r6,r8,-23888
	ctx.r6.s64 = ctx.r8.s64 + -23888;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// stw r6,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r6.u32);
	// stb r5,8(r28)
	PPC_STORE_U8(r28.u32 + 8, ctx.r5.u8);
	// lbz r4,179(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 179);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8278ac14
	if (cr6.eq) goto loc_8278AC14;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,25
	ctx.r10.s64 = 25;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8278AC14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278AC14:
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r27,0
	r27.s64 = 0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8278ad98
	if (!cr6.gt) goto loc_8278AD98;
	// addi r29,r11,12
	r29.s64 = r11.s64 + 12;
	// addi r30,r28,12
	r30.s64 = r28.s64 + 12;
	// li r24,38
	r24.s64 = 38;
loc_8278AC34:
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x8278ac84
	if (!cr6.eq) goto loc_8278AC84;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x8278ac84
	if (!cr6.eq) goto loc_8278AC84;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8278ac74
	if (cr6.eq) goto loc_8278AC74;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-22056
	ctx.r10.s64 = r11.s64 + -22056;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stb r25,8(r28)
	PPC_STORE_U8(r28.u32 + 8, r25.u8);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278AC74:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-23376
	ctx.r10.s64 = r11.s64 + -23376;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278AC84:
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bne cr6,0x8278ad00
	if (!cr6.eq) goto loc_8278AD00;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,220(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// bne cr6,0x8278acb4
	if (!cr6.eq) goto loc_8278ACB4;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r26,0
	r26.s64 = 0;
	// addi r10,r11,-23224
	ctx.r10.s64 = r11.s64 + -23224;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278ACB4:
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bne cr6,0x8278ad00
	if (!cr6.eq) goto loc_8278AD00;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bne cr6,0x8278ad00
	if (!cr6.eq) goto loc_8278AD00;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8278acf0
	if (cr6.eq) goto loc_8278ACF0;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-22752
	ctx.r10.s64 = r11.s64 + -22752;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stb r25,8(r28)
	PPC_STORE_U8(r28.u32 + 8, r25.u8);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278ACF0:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// addi r10,r11,-23000
	ctx.r10.s64 = r11.s64 + -23000;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278AD00:
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r8,r11,r10
	ctx.r8.s32 = r11.s32 / ctx.r10.s32;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// andc r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 & ~ctx.r6.u64;
	// twllei r10,0
	// subf. r5,r7,r11
	ctx.r5.s64 = r11.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// twlgei r4,-1
	// bne 0x8278ad64
	if (!cr0.eq) goto loc_8278AD64;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r8,r10,r9
	ctx.r8.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// andc r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twllei r9,0
	// subf. r4,r6,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// twlgei r5,-1
	// bne 0x8278ad64
	if (!cr0.eq) goto loc_8278AD64;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r26,0
	r26.s64 = 0;
	// addi r10,r11,-23744
	ctx.r10.s64 = r11.s64 + -23744;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x8278ad80
	goto loc_8278AD80;
loc_8278AD64:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8278AD80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278AD80:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8278ac34
	if (cr6.lt) goto loc_8278AC34;
loc_8278AD98:
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8278add4
	if (cr6.eq) goto loc_8278ADD4;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8278add4
	if (!cr6.eq) goto loc_8278ADD4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,99
	ctx.r10.s64 = 99;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8278ADD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278ADD4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8278ADDC"))) PPC_WEAK_FUNC(sub_8278ADDC);
PPC_FUNC_IMPL(__imp__sub_8278ADDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8278ADE0"))) PPC_WEAK_FUNC(sub_8278ADE0);
PPC_FUNC_IMPL(__imp__sub_8278ADE0) {
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
	ctx.lr = 0x8278ADE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// lwz r31,336(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278AE08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// addi r11,r3,2048
	r11.s64 = ctx.r3.s64 + 2048;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r30,r9,32768
	r30.u64 = ctx.r9.u64 | 32768;
	// lis r5,128
	ctx.r5.s64 = 8388608;
	// lis r28,29
	r28.s64 = 1900544;
	// ori r29,r3,38470
	r29.u64 = ctx.r3.u64 | 38470;
	// li r31,0
	r31.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r5,r5,32767
	ctx.r5.u64 = ctx.r5.u64 | 32767;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// ori r3,r28,37329
	ctx.r3.u64 = r28.u64 | 37329;
loc_8278AE4C:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r10,r10,7471
	ctx.r10.s64 = ctx.r10.s64 + 7471;
	// stw r9,-2048(r11)
	PPC_STORE_U32(r11.u32 + -2048, ctx.r9.u32);
	// addi r9,r9,19595
	ctx.r9.s64 = ctx.r9.s64 + 19595;
	// stw r8,-1024(r11)
	PPC_STORE_U32(r11.u32 + -1024, ctx.r8.u32);
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
	// stw r7,1024(r11)
	PPC_STORE_U32(r11.u32 + 1024, ctx.r7.u32);
	// addi r7,r7,-11059
	ctx.r7.s64 = ctx.r7.s64 + -11059;
	// stw r6,2048(r11)
	PPC_STORE_U32(r11.u32 + 2048, ctx.r6.u32);
	// addi r6,r6,-21709
	ctx.r6.s64 = ctx.r6.s64 + -21709;
	// stw r5,3072(r11)
	PPC_STORE_U32(r11.u32 + 3072, ctx.r5.u32);
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + r30.u64;
	// stw r4,4096(r11)
	PPC_STORE_U32(r11.u32 + 4096, ctx.r4.u32);
	// addi r4,r4,-27439
	ctx.r4.s64 = ctx.r4.s64 + -27439;
	// stw r31,5120(r11)
	PPC_STORE_U32(r11.u32 + 5120, r31.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,-5329
	r31.s64 = r31.s64 + -5329;
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x8278ae4c
	if (!cr6.gt) goto loc_8278AE4C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8278AEA0"))) PPC_WEAK_FUNC(sub_8278AEA0);
PPC_FUNC_IMPL(__imp__sub_8278AEA0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8278AEA8;
	// lwz r11,336(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// addic. r24,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r24.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// lwz r25,28(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blt 0x8278afb4
	if (cr0.lt) goto loc_8278AFB4;
	// rlwinm r26,r6,2,0,29
	r26.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_8278AEC0:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// lwz r7,4(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r6,8(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lwzx r8,r26,r10
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// lwzx r10,r26,r7
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + ctx.r7.u32);
	// lwzx r7,r6,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + r26.u32);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// beq cr6,0x8278afac
	if (cr6.eq) goto loc_8278AFAC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// subf r28,r10,r8
	r28.s64 = ctx.r8.s64 - ctx.r10.s64;
	// subf r27,r10,r7
	r27.s64 = ctx.r7.s64 - ctx.r10.s64;
loc_8278AEF8:
	// lbz r8,1(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r7,2(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// addi r31,r8,256
	r31.s64 = ctx.r8.s64 + 256;
	// lbz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r30,r7,512
	r30.s64 = ctx.r7.s64 + 512;
	// rlwinm r31,r31,2,0,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r6,768
	r29.s64 = ctx.r6.s64 + 768;
	// rotlwi r23,r6,2
	r23.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// rlwinm r21,r29,2,0,29
	r21.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r31,r11
	r31.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r22,r7,1280
	r22.s64 = ctx.r7.s64 + 1280;
	// lwzx r29,r30,r11
	r29.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// addi r7,r7,1792
	ctx.r7.s64 = ctx.r7.s64 + 1792;
	// addi r6,r6,1280
	ctx.r6.s64 = ctx.r6.s64 + 1280;
	// lwzx r30,r23,r11
	r30.u64 = PPC_LOAD_U32(r23.u32 + r11.u32);
	// add r31,r29,r31
	r31.u64 = r29.u64 + r31.u64;
	// addi r23,r8,1024
	r23.s64 = ctx.r8.s64 + 1024;
	// add r31,r31,r30
	r31.u64 = r31.u64 + r30.u64;
	// rlwinm r30,r23,2,0,29
	r30.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r31,r31,16
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0xFFFF) != 0);
	r31.s64 = r31.s32 >> 16;
	// rlwinm r29,r22,2,0,29
	r29.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0xFFFFFFFC;
	// stbx r31,r28,r10
	PPC_STORE_U8(r28.u32 + ctx.r10.u32, r31.u8);
	// rlwinm r31,r7,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r21,r11
	ctx.r7.u64 = PPC_LOAD_U32(r21.u32 + r11.u32);
	// addi r8,r8,1536
	ctx.r8.s64 = ctx.r8.s64 + 1536;
	// rlwinm r23,r6,2,0,29
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r30,r11
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r29,r11
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// srawi r7,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 16;
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// lwzx r7,r23,r11
	ctx.r7.u64 = PPC_LOAD_U32(r23.u32 + r11.u32);
	// lwzx r8,r31,r11
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r6,r30,r11
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r7,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 16;
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stbx r7,r27,r10
	PPC_STORE_U8(r27.u32 + ctx.r10.u32, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x8278aef8
	if (!cr0.eq) goto loc_8278AEF8;
loc_8278AFAC:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// bge 0x8278aec0
	if (!cr0.lt) goto loc_8278AEC0;
loc_8278AFB4:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8278AFB8"))) PPC_WEAK_FUNC(sub_8278AFB8);
PPC_FUNC_IMPL(__imp__sub_8278AFB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8278AFC0;
	// lwz r11,336(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// addic. r29,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r29.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blt 0x8278b04c
	if (cr0.lt) goto loc_8278B04C;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_8278AFD8:
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r31,r8,r30
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// beq cr6,0x8278b044
	if (cr6.eq) goto loc_8278B044;
loc_8278AFF8:
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r8,r8,256
	ctx.r8.s64 = ctx.r8.s64 + 256;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r7,512
	ctx.r7.s64 = ctx.r7.s64 + 512;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r6,r6,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// lwzx r8,r8,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwzx r7,r7,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwzx r6,r6,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// srawi r7,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 16;
	// stbx r7,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// blt cr6,0x8278aff8
	if (cr6.lt) goto loc_8278AFF8;
loc_8278B044:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8278afd8
	if (!cr0.lt) goto loc_8278AFD8;
loc_8278B04C:
	// b 0x823d924c
	return;
}

