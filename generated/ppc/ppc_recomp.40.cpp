#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_82294EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82294EA4) {
	__imp__sub_82294EA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294EA8) {
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
	// bl 0x82501208
	ctx.lr = 0x82294EC8;
	sub_82501208(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82294ee0
	if (cr6.eq) goto loc_82294EE0;
	// bl 0x82130588
	ctx.lr = 0x82294EDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82294EE0:
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

PPC_WEAK_FUNC(sub_82294EA8) {
	__imp__sub_82294EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294EF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294f60
	if (cr6.eq) goto loc_82294F60;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_82294F10:
	// cmpwi cr6,r3,16
	cr6.compare<int32_t>(ctx.r3.s32, 16, xer);
	// beq cr6,0x82294f60
	if (cr6.eq) goto loc_82294F60;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82294F20:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82294f44
	if (cr6.eq) goto loc_82294F44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82294f20
	if (cr6.eq) goto loc_82294F20;
loc_82294F44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294f10
	if (!cr6.eq) goto loc_82294F10;
loc_82294F60:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82294EF8) {
	__imp__sub_82294EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294F68) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82294F68) {
	__imp__sub_82294F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82294F74) {
	__imp__sub_82294F74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
loc_82294F84:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294fd0
	if (cr6.eq) goto loc_82294FD0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82294F94:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82294fb8
	if (cr6.eq) goto loc_82294FB8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82294f94
	if (cr6.eq) goto loc_82294F94;
loc_82294FB8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r8,r8,76
	ctx.r8.s64 = ctx.r8.s64 + 76;
	// cmpwi cr6,r3,32
	cr6.compare<int32_t>(ctx.r3.s32, 32, xer);
	// bne cr6,0x82294f84
	if (!cr6.eq) goto loc_82294F84;
loc_82294FD0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82294F78) {
	__imp__sub_82294F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r10,r4,76
	ctx.r10.s64 = ctx.r4.s64 * 76;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82294FD8) {
	__imp__sub_82294FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82294FF0) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x82294f78
	ctx.lr = 0x82295004;
	sub_82294F78(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82295020
	if (!cr6.lt) goto loc_82295020;
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
loc_82295020:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r11,r3,76
	r11.s64 = ctx.r3.s64 * 76;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82294ef8
	ctx.lr = 0x82295038;
	sub_82294EF8(ctx, base);
	// stw r3,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_82294FF0) {
	__imp__sub_82294FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295050) {
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
	ctx.lr = 0x82295058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e8e40
	ctx.lr = 0x8229506C;
	sub_824E8E40(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822950f0
	if (cr6.eq) goto loc_822950F0;
	// li r31,0
	r31.s64 = 0;
loc_82295084:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x824e9038
	ctx.lr = 0x82295090;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822950d8
	if (cr6.lt) goto loc_822950D8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e9740
	ctx.lr = 0x822950A8;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// blt cr6,0x822950d8
	if (cr6.lt) goto loc_822950D8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// addi r5,r11,72
	ctx.r5.s64 = r11.s64 + 72;
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822950d8
	if (cr6.eq) goto loc_822950D8;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e9530
	ctx.lr = 0x822950D8;
	sub_824E9530(ctx, base);
loc_822950D8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r31,r27,76
	r31.s64 = r27.s64 * 76;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82295084
	if (!cr6.eq) goto loc_82295084;
loc_822950F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295050) {
	__imp__sub_82295050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822950F8) {
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
	ctx.lr = 0x82295100;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r27
	r29.u64 = r27.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82295184
	if (cr6.eq) goto loc_82295184;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82295128:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x824e9038
	ctx.lr = 0x82295134;
	sub_824E9038(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8229516c
	if (cr6.lt) goto loc_8229516C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9740
	ctx.lr = 0x82295150;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8229516c
	if (!cr6.eq) goto loc_8229516C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9690
	ctx.lr = 0x8229516C;
	sub_824E9690(ctx, base);
loc_8229516C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mulli r10,r29,76
	ctx.r10.s64 = r29.s64 * 76;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x82295128
	if (!cr6.eq) goto loc_82295128;
loc_82295184:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822950F8) {
	__imp__sub_822950F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229518C) {
	__imp__sub_8229518C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,-1
	ctx.r8.s64 = -1;
loc_822951A8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r8.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r11,r10,76
	r11.s64 = ctx.r10.s64 * 76;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x822951a8
	if (!cr6.eq) goto loc_822951A8;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82295190) {
	__imp__sub_82295190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822951CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822951CC) {
	__imp__sub_822951CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822951D0) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822951F8;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295214
	if (cr6.eq) goto loc_82295214;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x82619408
	ctx.lr = 0x82295214;
	sub_82619408(ctx, base);
loc_82295214:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229521C;
	sub_821C9030(ctx, base);
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

PPC_WEAK_FUNC(sub_822951D0) {
	__imp__sub_822951D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295234) {
	__imp__sub_82295234(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295238) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295260;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// beq cr6,0x82295284
	if (cr6.eq) goto loc_82295284;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x826193a0
	ctx.lr = 0x82295284;
	sub_826193A0(ctx, base);
loc_82295284:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295290;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_82295238) {
	__imp__sub_82295238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822952AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822952AC) {
	__imp__sub_822952AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822952B0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x822952D8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// beq cr6,0x822952fc
	if (cr6.eq) goto loc_822952FC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x826193a0
	ctx.lr = 0x822952FC;
	sub_826193A0(ctx, base);
loc_822952FC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295308;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_822952B0) {
	__imp__sub_822952B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295324) {
	__imp__sub_82295324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r5,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r5.u8);
	// stb r11,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82295328) {
	__imp__sub_82295328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295338) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82295340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,520
	r29.s64 = r31.s64 + 520;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// stb r30,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r30.u8);
	// bl 0x82618750
	ctx.lr = 0x82295364;
	sub_82618750(ctx, base);
	// addi r28,r31,552
	r28.s64 = r31.s64 + 552;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618750
	ctx.lr = 0x82295370;
	sub_82618750(ctx, base);
	// addi r27,r31,584
	r27.s64 = r31.s64 + 584;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618750
	ctx.lr = 0x8229537C;
	sub_82618750(ctx, base);
	// stw r30,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r30.u32);
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// addi r3,r31,1396
	ctx.r3.s64 = r31.s64 + 1396;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x82295390;
	sub_821C8ED8(ctx, base);
	// addi r26,r31,6
	r26.s64 = r31.s64 + 6;
	// li r5,512
	ctx.r5.s64 = 512;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r30,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x822953B0;
	sub_823D9890(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618750
	ctx.lr = 0x822953B8;
	sub_82618750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82618610
	ctx.lr = 0x822953CC;
	sub_82618610(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826189a8
	ctx.lr = 0x822953D8;
	sub_826189A8(ctx, base);
	// stw r30,548(r31)
	PPC_STORE_U32(r31.u32 + 548, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r29,r31,548
	r29.s64 = r31.s64 + 548;
	// bl 0x82618750
	ctx.lr = 0x822953E8;
	sub_82618750(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82618610
	ctx.lr = 0x822953FC;
	sub_82618610(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826189a8
	ctx.lr = 0x82295408;
	sub_826189A8(ctx, base);
	// stw r30,580(r31)
	PPC_STORE_U32(r31.u32 + 580, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r30,r31,580
	r30.s64 = r31.s64 + 580;
	// bl 0x82618750
	ctx.lr = 0x82295418;
	sub_82618750(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82618610
	ctx.lr = 0x8229542C;
	sub_82618610(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826189a8
	ctx.lr = 0x82295438;
	sub_826189A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82295338) {
	__imp__sub_82295338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295444) {
	__imp__sub_82295444(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,1396
	ctx.r3.s64 = r11.s64 + 1396;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82295448) {
	__imp__sub_82295448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229545C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229545C) {
	__imp__sub_8229545C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295460) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// bl 0x821c8fe0
	ctx.lr = 0x82295480;
	sub_821C8FE0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r11.u32);
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
	// stw r11,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r11.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// bl 0x821c9030
	ctx.lr = 0x822954A0;
	sub_821C9030(ctx, base);
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

PPC_WEAK_FUNC(sub_82295460) {
	__imp__sub_82295460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822954B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822954B4) {
	__imp__sub_822954B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822954B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822954e4
	if (cr6.eq) goto loc_822954E4;
	// addi r11,r4,154
	r11.s64 = ctx.r4.s64 + 154;
	// addi r10,r4,153
	ctx.r10.s64 = ctx.r4.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// lwzx r6,r8,r3
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// subf r3,r6,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r6.s64;
	// blr 
	return;
loc_822954E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822954B8) {
	__imp__sub_822954B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822954EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822954EC) {
	__imp__sub_822954EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822954F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295504
	if (cr6.eq) goto loc_82295504;
	// lwz r3,1392(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1392);
	// blr 
	return;
loc_82295504:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822954F0) {
	__imp__sub_822954F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229550C) {
	__imp__sub_8229550C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295510) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229552c
	if (cr6.eq) goto loc_8229552C;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r3,888(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// blr 
	return;
loc_8229552C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82295510) {
	__imp__sub_82295510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295534) {
	__imp__sub_82295534(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295538) {
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
	ctx.lr = 0x82295540;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x8229555C;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82295634
	if (!cr6.eq) goto loc_82295634;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295598;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822955d0
	if (cr6.eq) goto loc_822955D0;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x822955d4
	goto loc_822955D4;
loc_822955D0:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822955D4:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r7,r29,r31
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// bl 0x826191b8
	ctx.lr = 0x822955F0;
	sub_826191B8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295630
	if (cr6.eq) goto loc_82295630;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// lwzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// subf r27,r10,r8
	r27.s64 = ctx.r8.s64 - ctx.r10.s64;
	// bl 0x821c9030
	ctx.lr = 0x82295624;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295630:
	// li r27,0
	r27.s64 = 0;
loc_82295634:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229563C;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295538) {
	__imp__sub_82295538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295648) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295674;
	sub_821C8FE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822956dc
	if (!cr6.eq) goto loc_822956DC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822956B8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82619330
	ctx.lr = 0x822956DC;
	sub_82619330(ctx, base);
loc_822956DC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f31.f64 = double(temp.f32);
	// bl 0x821c9030
	ctx.lr = 0x822956E8;
	sub_821C9030(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82295648) {
	__imp__sub_82295648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295708) {
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
	ctx.lr = 0x82295710;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295790
	if (cr6.eq) goto loc_82295790;
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x822954f0
	ctx.lr = 0x82295730;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82295790
	if (!cr6.gt) goto loc_82295790;
	// addi r29,r31,1396
	r29.s64 = r31.s64 + 1396;
loc_8229573C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295748;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295768
	if (cr6.eq) goto loc_82295768;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x826193a0
	ctx.lr = 0x82295768;
	sub_826193A0(ctx, base);
loc_82295768:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r27,80(r1)
	r27.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295774;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8229579c
	if (!cr6.eq) goto loc_8229579C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x82295788;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8229573c
	if (cr6.lt) goto loc_8229573C;
loc_82295790:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8229579C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295708) {
	__imp__sub_82295708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822957A8) {
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
	ctx.lr = 0x822957B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229581c
	if (cr6.eq) goto loc_8229581C;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822957CC;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8229581c
	if (!cr6.gt) goto loc_8229581C;
	// addi r29,r31,1396
	r29.s64 = r31.s64 + 1396;
loc_822957D8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822957E4;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295800
	if (cr6.eq) goto loc_82295800;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x82619408
	ctx.lr = 0x82295800;
	sub_82619408(ctx, base);
loc_82295800:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295808;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x82295814;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x822957d8
	if (cr6.lt) goto loc_822957D8;
loc_8229581C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822957A8) {
	__imp__sub_822957A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295824) {
	__imp__sub_82295824(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295828) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82295850;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822958a0
	if (cr6.eq) goto loc_822958A0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295868;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822958a0
	if (cr6.eq) goto loc_822958A0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x82619408
	ctx.lr = 0x82295884;
	sub_82619408(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295890;
	sub_822951D0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
loc_822958A0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822958A8;
	sub_821C9030(ctx, base);
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

PPC_WEAK_FUNC(sub_82295828) {
	__imp__sub_82295828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822958C0) {
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
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295914
	if (cr6.eq) goto loc_82295914;
	// li r31,0
	r31.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822958EC;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82295914
	if (!cr6.gt) goto loc_82295914;
loc_822958F4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295828
	ctx.lr = 0x82295900;
	sub_82295828(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x8229590C;
	sub_822954F0(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x822958f4
	if (cr6.lt) goto loc_822958F4;
loc_82295914:
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

PPC_WEAK_FUNC(sub_822958C0) {
	__imp__sub_822958C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229592C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229592C) {
	__imp__sub_8229592C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295930) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82295958;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295998
	if (cr6.eq) goto loc_82295998;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295970;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82295998
	if (!cr6.eq) goto loc_82295998;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x82619408
	ctx.lr = 0x8229598C;
	sub_82619408(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295998;
	sub_822951D0(ctx, base);
loc_82295998:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822959A0;
	sub_821C9030(ctx, base);
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

PPC_WEAK_FUNC(sub_82295930) {
	__imp__sub_82295930(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822959B8) {
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
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x822959D4;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822959f0
	if (cr6.eq) goto loc_822959F0;
	// lwz r3,136(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822959F0:
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

PPC_WEAK_FUNC(sub_822959B8) {
	__imp__sub_822959B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295A04) {
	__imp__sub_82295A04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295A08) {
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
	ctx.lr = 0x82295A10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295A30;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82295b14
	if (!cr6.eq) goto loc_82295B14;
	// cmpwi cr6,r29,32
	cr6.compare<int32_t>(r29.s32, 32, xer);
	// bgt cr6,0x82295b14
	if (cr6.gt) goto loc_82295B14;
	// li r3,0
	ctx.r3.s64 = 0;
	// addic. r28,r29,1
	xer.ca = r29.u32 > 4294967294;
	r28.s64 = r29.s64 + 1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq 0x82295ae4
	if (cr0.eq) goto loc_82295AE4;
	// addi r8,r31,612
	ctx.r8.s64 = r31.s64 + 612;
	// addi r7,r31,748
	ctx.r7.s64 = r31.s64 + 748;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_82295A64:
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,132(r8)
	PPC_STORE_U32(ctx.r8.u32 + 132, r11.u32);
	// stwx r9,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r9.u32);
	// lwz r11,128(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 128);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,128(r7)
	PPC_STORE_U32(ctx.r7.u32 + 128, ctx.r5.u32);
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// bge cr6,0x82295ad4
	if (!cr6.lt) goto loc_82295AD4;
	// lwz r11,1392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1392);
	// addi r6,r31,880
	ctx.r6.s64 = r31.s64 + 880;
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
loc_82295AD4:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// bne cr6,0x82295a64
	if (!cr6.eq) goto loc_82295A64;
loc_82295AE4:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x822958c0
	ctx.lr = 0x82295AF4;
	sub_822958C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822957a8
	ctx.lr = 0x82295AFC;
	sub_822957A8(ctx, base);
	// stb r27,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r27.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295B08;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295B14:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295B1C;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295A08) {
	__imp__sub_82295A08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295B28) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295b9c
	if (cr6.eq) goto loc_82295B9C;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x82295B4C;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82295b9c
	if (cr6.eq) goto loc_82295B9C;
	// addi r8,r10,880
	ctx.r8.s64 = ctx.r10.s64 + 880;
loc_82295B58:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_82295B60:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x82295b84
	if (cr6.eq) goto loc_82295B84;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82295b60
	if (cr6.eq) goto loc_82295B60;
loc_82295B84:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82295bb0
	if (cr6.eq) goto loc_82295BB0;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpw cr6,r7,r3
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r3.s32, xer);
	// bne cr6,0x82295b58
	if (!cr6.eq) goto loc_82295B58;
loc_82295B9C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82295BB0:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82295B28) {
	__imp__sub_82295B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295BC4) {
	__imp__sub_82295BC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295BC8) {
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
	ctx.lr = 0x82295BD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295BEC;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, ctx.r10.u32);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82295c78
	if (cr6.eq) goto loc_82295C78;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82295c78
	if (!cr6.eq) goto loc_82295C78;
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r10,r30,154
	ctx.r10.s64 = r30.s64 + 154;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf. r29,r7,r6
	r29.s64 = ctx.r6.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// ble 0x82295c78
	if (!cr0.gt) goto loc_82295C78;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// bl 0x82619268
	ctx.lr = 0x82295C50;
	sub_82619268(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295c78
	if (cr6.eq) goto loc_82295C78;
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295C6C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82295C78;
	sub_82295930(ctx, base);
loc_82295C78:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r28,r31
	r31.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82295C84;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295BC8) {
	__imp__sub_82295BC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295C90) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295CB8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82295d4c
	if (!cr6.eq) goto loc_82295D4C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295CF8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d30
	if (cr6.eq) goto loc_82295D30;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x82295d34
	goto loc_82295D34;
loc_82295D30:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82295D34:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273c30
	ctx.lr = 0x82295D4C;
	sub_82273C30(ctx, base);
loc_82295D4C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82295D54;
	sub_821C9030(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

PPC_WEAK_FUNC(sub_82295C90) {
	__imp__sub_82295C90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295D70) {
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
	ctx.lr = 0x82295D78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x82295D94;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r28,0
	r28.s64 = 0;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r28.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295dcc
	if (cr6.eq) goto loc_82295DCC;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r28,r6,r7
	r28.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82295DCC:
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// ble cr6,0x82295df8
	if (!cr6.gt) goto loc_82295DF8;
loc_82295DE4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295DEC;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295DF8:
	// subfic r11,r11,-1
	xer.ca = r11.u32 <= 4294967295;
	r11.s64 = -1 - r11.s64;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82295de4
	if (cr6.lt) goto loc_82295DE4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295E10;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295e30
	if (cr6.eq) goto loc_82295E30;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x82295E28;
	sub_82295C90(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// beq cr6,0x82295de4
	if (cr6.eq) goto loc_82295DE4;
loc_82295E30:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273cd0
	ctx.lr = 0x82295E4C;
	sub_82273CD0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82295e74
	if (cr6.eq) goto loc_82295E74;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295E64;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82295E70;
	sub_82295930(ctx, base);
	// stwx r28,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r28.u32);
loc_82295E74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r27,r31
	r31.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82295E80;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295D70) {
	__imp__sub_82295D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82295E8C) {
	__imp__sub_82295E8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295E90) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295EB8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82295f4c
	if (!cr6.eq) goto loc_82295F4C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295EF8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f30
	if (cr6.eq) goto loc_82295F30;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x82295f34
	goto loc_82295F34;
loc_82295F30:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82295F34:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273d70
	ctx.lr = 0x82295F4C;
	sub_82273D70(ctx, base);
loc_82295F4C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82295F54;
	sub_821C9030(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

PPC_WEAK_FUNC(sub_82295E90) {
	__imp__sub_82295E90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82295F70) {
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
	ctx.lr = 0x82295F78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x82295F94;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r29.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295fcc
	if (cr6.eq) goto loc_82295FCC;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82295FCC:
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r9,r10,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmplw cr6,r28,r8
	cr6.compare<uint32_t>(r28.u32, ctx.r8.u32, xer);
	// ble cr6,0x82295ffc
	if (!cr6.gt) goto loc_82295FFC;
loc_82295FE8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295FF0;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295FFC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296008;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296028
	if (cr6.eq) goto loc_82296028;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82296020;
	sub_82295E90(ctx, base);
	// cmplw cr6,r3,r28
	cr6.compare<uint32_t>(ctx.r3.u32, r28.u32, xer);
	// beq cr6,0x82295fe8
	if (cr6.eq) goto loc_82295FE8;
loc_82296028:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273058
	ctx.lr = 0x82296044;
	sub_82273058(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229606c
	if (cr6.eq) goto loc_8229606C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8229605C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82296068;
	sub_82295930(ctx, base);
	// stwx r29,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r29.u32);
loc_8229606C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r27,r31
	r31.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82296078;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82295F70) {
	__imp__sub_82295F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296084) {
	__imp__sub_82296084(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296088) {
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
	ctx.lr = 0x82296090;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822960B0;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822960e8
	if (cr6.eq) goto loc_822960E8;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_822960E8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822960F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229612c
	if (cr6.eq) goto loc_8229612C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295648
	ctx.lr = 0x8229610C;
	sub_82295648(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x8229612c
	if (!cr6.eq) goto loc_8229612C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229611C;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8229612C:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82619370
	ctx.lr = 0x82296144;
	sub_82619370(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229616c
	if (cr6.eq) goto loc_8229616C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8229615C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82296168;
	sub_82295930(ctx, base);
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
loc_8229616C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r28,r31
	r31.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82296178;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82296088) {
	__imp__sub_82296088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296188) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82296190;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822961B8;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r20,r4,24
	r20.u64 = ctx.r4.u32 & 0xFF;
	// addi r21,r31,612
	r21.s64 = r31.s64 + 612;
	// addi r25,r31,888
	r25.s64 = r31.s64 + 888;
	// addi r24,r5,14236
	r24.s64 = ctx.r5.s64 + 14236;
	// addi r27,r6,14220
	r27.s64 = ctx.r6.s64 + 14220;
	// addi r23,r7,14200
	r23.s64 = ctx.r7.s64 + 14200;
	// addi r26,r8,9792
	r26.s64 = ctx.r8.s64 + 9792;
	// addi r29,r9,32684
	r29.s64 = ctx.r9.s64 + 32684;
	// addi r22,r10,14180
	r22.s64 = ctx.r10.s64 + 14180;
	// addi r28,r11,14168
	r28.s64 = r11.s64 + 14168;
loc_82296204:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82296224
	if (cr6.eq) goto loc_82296224;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82296218;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229638c
	if (cr6.eq) goto loc_8229638C;
loc_82296224:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296230;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296264
	if (!cr6.eq) goto loc_82296264;
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229624C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8229624c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229624C;
	// b 0x8229638c
	goto loc_8229638C;
loc_82296264:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82296278
	if (cr6.eq) goto loc_82296278;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x8229627c
	goto loc_8229627C;
loc_82296278:
	// li r11,-1
	r11.s64 = -1;
loc_8229627C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8229638c
	if (cr6.gt) goto loc_8229638C;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,25248
	r12.s64 = r12.s64 + 25248;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,25272(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25272);
	// lwz r17,25280(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25280);
	// lwz r17,25316(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25316);
	// lwz r17,25352(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25352);
	// lwz r17,25392(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25392);
	// lwz r17,25400(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25400);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// b 0x82296380
	goto loc_82296380;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x822962CC;
	sub_82295C90(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822962E0;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822962F0;
	sub_82295E90(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82296304;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295648
	ctx.lr = 0x82296314;
	sub_82295648(ctx, base);
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8229632C;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// b 0x82296380
	goto loc_82296380;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229637c
	if (cr6.eq) goto loc_8229637C;
	// lwz r11,4(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r9,64
	cr6.compare<int32_t>(ctx.r9.s32, 64, xer);
	// bne cr6,0x8229637c
	if (!cr6.eq) goto loc_8229637C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82296364;
	sub_82295538(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82296378;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
loc_8229637C:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
loc_82296380:
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8229638C;
	sub_82137A08(ctx, base);
loc_8229638C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r25,r25,16
	r25.s64 = r25.s64 + 16;
	// bl 0x822954f0
	ctx.lr = 0x822963A0;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x82296204
	if (!cr6.eq) goto loc_82296204;
loc_822963A8:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_82296188) {
	__imp__sub_82296188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822963B0) {
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
	ctx.lr = 0x822963B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963e4
	if (cr6.eq) goto loc_822963E4;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r29,892(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 892);
	// b 0x822963e8
	goto loc_822963E8;
loc_822963E4:
	// li r29,0
	r29.s64 = 0;
loc_822963E8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822963F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9038
	ctx.lr = 0x82296414;
	sub_824E9038(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9740
	ctx.lr = 0x82296454;
	sub_824E9740(ctx, base);
	// addi r11,r29,31
	r11.s64 = r29.s64 + 31;
	// rlwinm r10,r11,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// srawi r9,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// bne cr6,0x822964d4
	if (!cr6.eq) goto loc_822964D4;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296488
	if (cr6.eq) goto loc_82296488;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r11,888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// b 0x8229648c
	goto loc_8229648C;
loc_82296488:
	// li r11,-1
	r11.s64 = -1;
loc_8229648C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x822964b0
	if (cr6.lt) goto loc_822964B0;
	// bne cr6,0x822964d4
	if (!cr6.eq) goto loc_822964D4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822964A4;
	sub_82295E90(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// b 0x822964c4
	goto loc_822964C4;
loc_822964B0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x822964BC;
	sub_82295C90(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
loc_822964C4:
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9530
	ctx.lr = 0x822964D4;
	sub_824E9530(ctx, base);
loc_822964D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822963B0) {
	__imp__sub_822963B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822964DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822964DC) {
	__imp__sub_822964DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822964E0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822964E8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// bl 0x826185a0
	ctx.lr = 0x822964F8;
	sub_826185A0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lbz r4,1(r21)
	ctx.r4.u64 = PPC_LOAD_U8(r21.u32 + 1);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r22,r21,1
	r22.s64 = r21.s64 + 1;
	// bl 0x82250f50
	ctx.lr = 0x82296510;
	sub_82250F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r20,-32121
	r20.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x8229652C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x82296544;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82296560
	if (!cr6.eq) goto loc_82296560;
loc_8229655C:
	// li r11,0
	r11.s64 = 0;
loc_82296560:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82296778
	if (cr6.eq) goto loc_82296778;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x82296578;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82296588
	if (cr6.eq) goto loc_82296588;
	// lwz r28,136(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8229658c
	goto loc_8229658C;
loc_82296588:
	// li r28,0
	r28.s64 = 0;
loc_8229658C:
	// addi r4,r28,1396
	ctx.r4.s64 = r28.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82296598;
	sub_821C8FE0(ctx, base);
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822965dc
	if (!cr6.eq) goto loc_822965DC;
	// addi r31,r28,552
	r31.s64 = r28.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822965B4;
	sub_82618830(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822965c8
	if (cr6.eq) goto loc_822965C8;
	// lwz r5,1392(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 1392);
	// b 0x822965cc
	goto loc_822965CC;
loc_822965C8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822965CC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822965D8;
	sub_82618C80(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_822965DC:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296620
	if (cr6.eq) goto loc_82296620;
	// addi r31,r28,584
	r31.s64 = r28.s64 + 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822965F8;
	sub_82618830(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229660c
	if (cr6.eq) goto loc_8229660C;
	// lwz r5,1392(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 1392);
	// b 0x82296610
	goto loc_82296610;
loc_8229660C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82296610:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x8229661C;
	sub_82618C80(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_82296620:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296770
	if (cr6.eq) goto loc_82296770;
	// addi r29,r28,612
	r29.s64 = r28.s64 + 612;
	// addi r24,r28,888
	r24.s64 = r28.s64 + 888;
loc_82296638:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822954f0
	ctx.lr = 0x82296640;
	sub_822954F0(ctx, base);
	// cmpw cr6,r26,r3
	cr6.compare<int32_t>(r26.s32, ctx.r3.s32, xer);
	// bge cr6,0x82296770
	if (!cr6.lt) goto loc_82296770;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229666c
	if (!cr6.eq) goto loc_8229666C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295238
	ctx.lr = 0x82296660;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
loc_8229666C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296678;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822966a0
	if (cr6.eq) goto loc_822966A0;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subf r31,r9,r10
	r31.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x822966a4
	goto loc_822966A4;
loc_822966A0:
	// li r31,0
	r31.s64 = 0;
loc_822966A4:
	// mr r30,r31
	r30.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// beq cr6,0x8229670c
	if (cr6.eq) goto loc_8229670C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8229670c
	if (!cr6.eq) goto loc_8229670C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826185a0
	ctx.lr = 0x822966C8;
	sub_826185A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822966dc
	if (!cr6.eq) goto loc_822966DC;
	// lwz r30,136(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
loc_822966DC:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822966fc
	if (cr6.eq) goto loc_822966FC;
loc_822966EC:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822966ec
	if (!cr6.eq) goto loc_822966EC;
loc_822966FC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82299788
	ctx.lr = 0x82296708;
	sub_82299788(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8229670C:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// addi r31,r28,520
	r31.s64 = r28.s64 + 520;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82296728;
	sub_82618830(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x82296738;
	sub_82618C80(ctx, base);
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// stw r30,136(r29)
	PPC_STORE_U32(r29.u32 + 136, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822951d0
	ctx.lr = 0x82296758;
	sub_822951D0(ctx, base);
loc_82296758:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296638
	if (!cr6.eq) goto loc_82296638;
loc_82296770:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82296778;
	sub_821C9030(ctx, base);
loc_82296778:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822967c8
	if (cr6.eq) goto loc_822967C8;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822967c8
	if (cr6.eq) goto loc_822967C8;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x8229679C;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822967bc
	if (cr6.eq) goto loc_822967BC;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
loc_822967BC:
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
loc_822967C8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_822964E0) {
	__imp__sub_822964E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822967D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822967D4) {
	__imp__sub_822967D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822967D8) {
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
	ctx.lr = 0x822967E0;
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
	ctx.lr = 0x82296804;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82296810;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82296820;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82296844
	if (cr6.eq) goto loc_82296844;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822964e0
	ctx.lr = 0x82296834;
	sub_822964E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296848
	if (!cr6.eq) goto loc_82296848;
loc_82296844:
	// li r30,0
	r30.s64 = 0;
loc_82296848:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82296880
	if (cr6.eq) goto loc_82296880;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296878
	if (cr6.eq) goto loc_82296878;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82296864;
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
loc_82296878:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82296880:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822967D8) {
	__imp__sub_822967D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229688C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229688C) {
	__imp__sub_8229688C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296890) {
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
	ctx.lr = 0x82296898;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16844
	ctx.r10.s64 = r11.s64 + 16844;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822967d8
	ctx.lr = 0x822968CC;
	sub_822967D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82296904
	if (cr6.eq) goto loc_82296904;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x822968F4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82296908
	if (!cr6.eq) goto loc_82296908;
loc_82296904:
	// li r11,0
	r11.s64 = 0;
loc_82296908:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82296890) {
	__imp__sub_82296890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296914) {
	__imp__sub_82296914(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296918) {
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
	ctx.lr = 0x82296920;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8229698c
	if (cr6.lt) goto loc_8229698C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x82296948;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229696c
	if (!cr6.eq) goto loc_8229696C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82296960;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229698c
	if (cr6.eq) goto loc_8229698C;
loc_8229696C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82296890
	ctx.lr = 0x82296984;
	sub_82296890(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229698C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296918) {
	__imp__sub_82296918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296998) {
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
	ctx.lr = 0x822969A0;
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
	ctx.lr = 0x822969C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822969fc
	if (cr6.eq) goto loc_822969FC;
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
	// beq cr6,0x822969f4
	if (cr6.eq) goto loc_822969F4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822969fc
	if (!cr6.eq) goto loc_822969FC;
loc_822969F4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82296a00
	goto loc_82296A00;
loc_822969FC:
	// li r11,0
	r11.s64 = 0;
loc_82296A00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296a3c
	if (cr6.eq) goto loc_82296A3C;
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
	// bl 0x82296918
	ctx.lr = 0x82296A34;
	sub_82296918(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82296A3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296998) {
	__imp__sub_82296998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296A48) {
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
	ctx.lr = 0x82296A50;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// li r30,1
	r30.s64 = 1;
	// addi r25,r4,12
	r25.s64 = ctx.r4.s64 + 12;
	// li r24,31
	r24.s64 = 31;
loc_82296A70:
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82296ac4
	if (cr6.eq) goto loc_82296AC4;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82296A84;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ac4
	if (cr6.eq) goto loc_82296AC4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296ac4
	if (!cr6.eq) goto loc_82296AC4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82296998
	ctx.lr = 0x82296AB8;
	sub_82296998(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_82296AC4:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x82296a70
	if (!cr0.eq) goto loc_82296A70;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82296A48) {
	__imp__sub_82296A48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296ADC) {
	__imp__sub_82296ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296AE0) {
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
	ctx.lr = 0x82296AE8;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// bl 0x82295708
	ctx.lr = 0x82296B10;
	sub_82295708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x824817c0
	ctx.lr = 0x82296B28;
	sub_824817C0(ctx, base);
	// addi r4,r3,12
	ctx.r4.s64 = ctx.r3.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea3b8
	ctx.lr = 0x82296B34;
	sub_824EA3B8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// mr r27,r30
	r27.u64 = r30.u64;
	// addi r28,r11,-10240
	r28.s64 = r11.s64 + -10240;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r10,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bne cr6,0x82296b84
	if (!cr6.eq) goto loc_82296B84;
	// bl 0x82296a48
	ctx.lr = 0x82296B80;
	sub_82296A48(ctx, base);
	// b 0x82296b90
	goto loc_82296B90;
loc_82296B84:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82296998
	ctx.lr = 0x82296B90;
	sub_82296998(ctx, base);
loc_82296B90:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822954f0
	ctx.lr = 0x82296B98;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82296c18
	if (!cr6.gt) goto loc_82296C18;
	// addi r29,r31,892
	r29.s64 = r31.s64 + 892;
loc_82296BA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296BB0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296bd4
	if (cr6.eq) goto loc_82296BD4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
loc_82296BD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82296BE0;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822963b0
	ctx.lr = 0x82296BFC;
	sub_822963B0(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_82296C00:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bl 0x822954f0
	ctx.lr = 0x82296C10;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x82296ba4
	if (cr6.lt) goto loc_82296BA4;
loc_82296C18:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x82296C34;
	sub_822950F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82486800
	ctx.lr = 0x82296C48;
	sub_82486800(ctx, base);
loc_82296C48:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296AE0) {
	__imp__sub_82296AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296C50) {
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
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ce4
	if (cr6.eq) goto loc_82296CE4;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ce4
	if (cr6.eq) goto loc_82296CE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r7,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r7.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// bne cr6,0x82296cd0
	if (!cr6.eq) goto loc_82296CD0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82296a48
	ctx.lr = 0x82296CC0;
	sub_82296A48(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82296CD0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82296998
	ctx.lr = 0x82296CE4;
	sub_82296998(ctx, base);
loc_82296CE4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82296C50) {
	__imp__sub_82296C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296CF4) {
	__imp__sub_82296CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296CF8) {
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
	ctx.lr = 0x82296D00;
	// stwu r1,-3152(r1)
	ea = -3152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// li r31,30
	r31.s64 = 30;
loc_82296D14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x82296D1C;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x82296d14
	if (!cr0.lt) goto loc_82296D14;
	// addi r27,r29,144
	r27.s64 = r29.s64 + 144;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824817c8
	ctx.lr = 0x82296D3C;
	sub_824817C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82296dd0
	if (!cr6.gt) goto loc_82296DD0;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
loc_82296D50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82296D58;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82296D5C;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r28
	cr6.compare<uint64_t>(ctx.r3.u64, r28.u64, xer);
	// beq cr6,0x82296d7c
	if (cr6.eq) goto loc_82296D7C;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82296d50
	if (cr6.lt) goto loc_82296D50;
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9244
	return;
loc_82296D7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f99c0
	ctx.lr = 0x82296D84;
	sub_824F99C0(ctx, base);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82130000
	ctx.lr = 0x82296D9C;
	sub_82130000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82296DAC:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82296dac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82296DAC;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824853d0
	ctx.lr = 0x82296DD0;
	sub_824853D0(ctx, base);
loc_82296DD0:
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296CF8) {
	__imp__sub_82296CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296DD8) {
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
	ctx.lr = 0x82296DE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82296DF4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296e1c
	if (cr6.eq) goto loc_82296E1C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296E08;
	sub_82502300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f0550
	ctx.lr = 0x82296E10;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296e38
	if (!cr6.eq) goto loc_82296E38;
loc_82296E1C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296df4
	if (!cr6.eq) goto loc_82296DF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82296E38:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82296DD8) {
	__imp__sub_82296DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296E4C) {
	__imp__sub_82296E4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296E50) {
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
	ctx.lr = 0x82296E58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r3,12
	r31.s64 = ctx.r3.s64 + 12;
loc_82296E68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296e90
	if (cr6.eq) goto loc_82296E90;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82296E7C;
	sub_824E7110(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f92f8
	ctx.lr = 0x82296E84;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296eac
	if (!cr6.eq) goto loc_82296EAC;
loc_82296E90:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296e68
	if (!cr6.eq) goto loc_82296E68;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82296EAC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82296E50) {
	__imp__sub_82296E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296EB8) {
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
	ctx.lr = 0x82296EC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r28,31
	r28.s64 = 31;
loc_82296ED8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f54
	if (cr6.eq) goto loc_82296F54;
	// lbz r10,279(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 279);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82296f18
	if (cr6.eq) goto loc_82296F18;
	// lbz r10,280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82296f10
	if (!cr6.eq) goto loc_82296F10;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82296F04;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f18
	if (cr6.eq) goto loc_82296F18;
loc_82296F10:
	// li r11,1
	r11.s64 = 1;
	// b 0x82296f1c
	goto loc_82296F1C;
loc_82296F18:
	// li r11,0
	r11.s64 = 0;
loc_82296F1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f54
	if (cr6.eq) goto loc_82296F54;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x82296f50
	if (cr6.eq) goto loc_82296F50;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296F3C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// bl 0x82482520
	ctx.lr = 0x82296F48;
	sub_82482520(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// bne cr6,0x82296f54
	if (!cr6.eq) goto loc_82296F54;
loc_82296F50:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82296F54:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82296ed8
	if (!cr0.eq) goto loc_82296ED8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296EB8) {
	__imp__sub_82296EB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296F6C) {
	__imp__sub_82296F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
loc_82296F78:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82296f9c
	if (cr6.eq) goto loc_82296F9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x82296f78
	if (cr6.lt) goto loc_82296F78;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82296F9C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82296F70) {
	__imp__sub_82296F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82296FA4) {
	__imp__sub_82296FA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82296FA8) {
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
	ctx.lr = 0x82296FB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82296FC4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ffc
	if (cr6.eq) goto loc_82296FFC;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296FD8;
	sub_82502300(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296FE8;
	sub_82502300(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824f0550
	ctx.lr = 0x82296FF0;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297014
	if (!cr6.eq) goto loc_82297014;
loc_82296FFC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296fc4
	if (!cr6.eq) goto loc_82296FC4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82297014:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82296FA8) {
	__imp__sub_82296FA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229702C) {
	__imp__sub_8229702C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82297030) {
	__imp__sub_82297030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297040) {
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
	// addi r9,r11,-1380
	ctx.r9.s64 = r11.s64 + -1380;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82297074
	if (cr6.eq) goto loc_82297074;
	// bl 0x82130588
	ctx.lr = 0x82297070;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82297074:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82297040) {
	__imp__sub_82297040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297088) {
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
	ctx.lr = 0x82297090;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r4,1
	r30.s64 = ctx.r4.s64 + 1;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82297128
	if (!cr6.lt) goto loc_82297128;
	// lis r11,20971
	r11.s64 = 1374355456;
	// ori r29,r11,34079
	r29.u64 = r11.u64 | 34079;
loc_822970B0:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// li r5,96
	ctx.r5.s64 = 96;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mulhw r4,r7,r29
	ctx.r4.s64 = (int64_t(ctx.r7.s32) * int64_t(r29.s32)) >> 32;
	// mulhw r3,r6,r29
	ctx.r3.s64 = (int64_t(ctx.r6.s32) * int64_t(r29.s32)) >> 32;
	// srawi r11,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	r11.s64 = ctx.r4.s32 >> 5;
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r9,r11,100
	ctx.r9.s64 = r11.s64 * 100;
	// mulli r8,r10,100
	ctx.r8.s64 = ctx.r10.s64 * 100;
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// subf r11,r8,r6
	r11.s64 = ctx.r6.s64 - ctx.r8.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + r31.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x82297118;
	sub_823DA950(ctx, base);
	// lwz r5,9608(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// blt cr6,0x822970b0
	if (cr6.lt) goto loc_822970B0;
loc_82297128:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// stw r10,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82297150
	if (!cr6.eq) goto loc_82297150;
	// li r11,99
	r11.s64 = 99;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82297150:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82297088) {
	__imp__sub_82297088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297160) {
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
	ctx.lr = 0x82297168;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82488320
	ctx.lr = 0x8229717C;
	sub_82488320(ctx, base);
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82297198
	if (cr6.eq) goto loc_82297198;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295448
	ctx.lr = 0x82297190;
	sub_82295448(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82297198;
	sub_82130588(ctx, base);
loc_82297198:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// bl 0x82489608
	ctx.lr = 0x822971A8;
	sub_82489608(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82297160) {
	__imp__sub_82297160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822971B0) {
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
	ctx.lr = 0x822971B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r30,144
	r29.s64 = r30.s64 + 144;
	// stw r4,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r4.u32);
	// lwz r31,-10240(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r27,68(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ea838
	ctx.lr = 0x822971E4;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x822971E8;
	sub_824F88F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// li r6,11
	ctx.r6.s64 = 11;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r31,23592
	ctx.r4.s64 = r31.s64 + 23592;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// bl 0x824852f8
	ctx.lr = 0x82297208;
	sub_824852F8(ctx, base);
	// addi r4,r30,11760
	ctx.r4.s64 = r30.s64 + 11760;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82485608
	ctx.lr = 0x82297214;
	sub_82485608(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822971B0) {
	__imp__sub_822971B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229721C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229721C) {
	__imp__sub_8229721C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297220) {
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
	ctx.lr = 0x82297228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,31
	r27.s64 = 31;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r28,0
	r28.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_82297240:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82297268
	if (cr6.eq) goto loc_82297268;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297254;
	sub_82272A48(ctx, base);
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x82297264;
	sub_82271D18(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_82297268:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82297240
	if (!cr0.eq) goto loc_82297240;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82297220) {
	__imp__sub_82297220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229727C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229727C) {
	__imp__sub_8229727C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297280) {
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
	ctx.lr = 0x82297288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x8229729C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822972b8
	if (cr6.eq) goto loc_822972B8;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822972bc
	if (!cr6.eq) goto loc_822972BC;
loc_822972B8:
	// li r11,0
	r11.s64 = 0;
loc_822972BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297348
	if (!cr6.eq) goto loc_82297348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x822972D0;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297348
	if (cr6.eq) goto loc_82297348;
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82486430
	ctx.lr = 0x822972F0;
	sub_82486430(ctx, base);
	// addi r29,r30,12
	r29.s64 = r30.s64 + 12;
	// li r28,31
	r28.s64 = 31;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_822972FC:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229733c
	if (cr6.eq) goto loc_8229733C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229733c
	if (cr6.eq) goto loc_8229733C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297320;
	sub_82272A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82296fa8
	ctx.lr = 0x8229732C;
	sub_82296FA8(ctx, base);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x8229733C;
	sub_82271D18(ctx, base);
loc_8229733C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822972fc
	if (!cr0.eq) goto loc_822972FC;
loc_82297348:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82297280) {
	__imp__sub_82297280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297350) {
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
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822973c0
	if (cr6.eq) goto loc_822973C0;
loc_82297378:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// lwz r10,9604(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r9,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r9.u32);
	// stw r11,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x8229739c
	if (!cr6.eq) goto loc_8229739C;
	// stw r30,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r30.u32);
loc_8229739C:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x822973B4;
	sub_824E6F20(ctx, base);
	// lwz r10,9608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82297378
	if (!cr6.eq) goto loc_82297378;
loc_822973C0:
	// stw r30,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, r30.u32);
	// stw r30,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r30.u32);
	// stw r30,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r30.u32);
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

PPC_WEAK_FUNC(sub_82297350) {
	__imp__sub_82297350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822973E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822973E4) {
	__imp__sub_822973E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822973E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,9608(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9608);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822973E8) {
	__imp__sub_822973E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822973F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82297444
	if (cr6.lt) goto loc_82297444;
	// lwz r11,9608(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9608);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82297444
	if (!cr6.lt) goto loc_82297444;
	// lwz r11,9604(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9604);
	// lis r10,20971
	ctx.r10.s64 = 1374355456;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// ori r9,r10,34079
	ctx.r9.u64 = ctx.r10.u64 | 34079;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r7,r8,r9
	ctx.r7.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r7,5
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	r11.s64 = ctx.r7.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mulli r5,r6,100
	ctx.r5.s64 = ctx.r6.s64 * 100;
	// subf r11,r5,r8
	r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
loc_82297444:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822973F0) {
	__imp__sub_822973F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229744C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229744C) {
	__imp__sub_8229744C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297450) {
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
	ctx.lr = 0x82297458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822974d4
	if (!cr6.gt) goto loc_822974D4;
	// lis r11,20971
	r11.s64 = 1374355456;
	// ori r30,r11,34079
	r30.u64 = r11.u64 | 34079;
loc_8229747C:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// mulhw r8,r9,r30
	ctx.r8.s64 = (int64_t(ctx.r9.s32) * int64_t(r30.s32)) >> 32;
	// srawi r11,r8,5
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	r11.s64 = ctx.r8.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mulli r6,r7,100
	ctx.r6.s64 = ctx.r7.s64 * 100;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e7120
	ctx.lr = 0x822974B8;
	sub_824E7120(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822974e0
	if (!cr6.eq) goto loc_822974E0;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229747c
	if (cr6.lt) goto loc_8229747C;
loc_822974D4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822974E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82297450) {
	__imp__sub_82297450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822974EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822974EC) {
	__imp__sub_822974EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822974F0) {
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
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82488320
	ctx.lr = 0x82297514;
	sub_82488320(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x8229751C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297538
	if (!cr6.eq) goto loc_82297538;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8229753c
	if (cr6.eq) goto loc_8229753C;
loc_82297538:
	// li r11,0
	r11.s64 = 0;
loc_8229753C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297550
	if (!cr6.eq) goto loc_82297550;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297280
	ctx.lr = 0x82297550;
	sub_82297280(ctx, base);
loc_82297550:
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

PPC_WEAK_FUNC(sub_822974F0) {
	__imp__sub_822974F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297568) {
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
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stw r11,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r11.u32);
	// stw r11,11816(r31)
	PPC_STORE_U32(r31.u32 + 11816, r11.u32);
	// bl 0x82297220
	ctx.lr = 0x8229759C;
	sub_82297220(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822975b8
	if (cr6.eq) goto loc_822975B8;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822975b8
	if (cr6.eq) goto loc_822975B8;
	// bl 0x82295460
	ctx.lr = 0x822975B8;
	sub_82295460(ctx, base);
loc_822975B8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82297568) {
	__imp__sub_82297568(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822975CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822975CC) {
	__imp__sub_822975CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822975D0) {
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
	// addi r4,r31,11784
	ctx.r4.s64 = r31.s64 + 11784;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82486548
	ctx.lr = 0x822975F0;
	sub_82486548(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229761c
	if (!cr6.eq) goto loc_8229761C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297280
	ctx.lr = 0x82297604;
	sub_82297280(ctx, base);
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
loc_8229761C:
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

PPC_WEAK_FUNC(sub_822975D0) {
	__imp__sub_822975D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82297634) {
	__imp__sub_82297634(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297638) {
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
	// addi r4,r31,11792
	ctx.r4.s64 = r31.s64 + 11792;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x824866e8
	ctx.lr = 0x82297658;
	sub_824866E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297684
	if (!cr6.eq) goto loc_82297684;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297280
	ctx.lr = 0x8229766C;
	sub_82297280(ctx, base);
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
loc_82297684:
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

PPC_WEAK_FUNC(sub_82297638) {
	__imp__sub_82297638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229769C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229769C) {
	__imp__sub_8229769C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822976A0) {
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
	ctx.lr = 0x822976A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,99
	r31.s64 = 99;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822976B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x822976C0;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x822976b8
	if (!cr0.lt) goto loc_822976B8;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,9608(r29)
	PPC_STORE_U32(r29.u32 + 9608, r11.u32);
	// stw r11,9604(r29)
	PPC_STORE_U32(r29.u32 + 9604, r11.u32);
	// stw r11,9600(r29)
	PPC_STORE_U32(r29.u32 + 9600, r11.u32);
	// bl 0x82297350
	ctx.lr = 0x822976E4;
	sub_82297350(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822976A0) {
	__imp__sub_822976A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822976F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82297350
	sub_82297350(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822976F0) {
	__imp__sub_822976F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822976F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822976F4) {
	__imp__sub_822976F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822976F8) {
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
	ctx.lr = 0x82297700;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82297450
	ctx.lr = 0x82297710;
	sub_82297450(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82297724
	if (cr6.lt) goto loc_82297724;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297088
	ctx.lr = 0x82297724;
	sub_82297088(ctx, base);
loc_82297724:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x8229776c
	if (!cr6.eq) goto loc_8229776C;
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// li r10,99
	ctx.r10.s64 = 99;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r10.u32);
	// stw r11,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x82297754
	if (!cr6.eq) goto loc_82297754;
	// stw r29,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r29.u32);
loc_82297754:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x8229776C;
	sub_824E6F20(ctx, base);
loc_8229776C:
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x82297784
	if (!cr6.eq) goto loc_82297784;
	// stw r29,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r29.u32);
loc_82297784:
	// lwz r10,9608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r9.u32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x822977B0;
	sub_823DA950(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822976F8) {
	__imp__sub_822976F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822977B8) {
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
	ctx.lr = 0x822977C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x826185a0
	ctx.lr = 0x822977D0;
	sub_826185A0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbz r4,1(r23)
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + 1);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82250f50
	ctx.lr = 0x822977E4;
	sub_82250F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229781c
	if (cr6.eq) goto loc_8229781C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x822977FC;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229781c
	if (cr6.eq) goto loc_8229781C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297810;
	sub_822959B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82297820
	if (!cr6.eq) goto loc_82297820;
loc_8229781C:
	// li r11,0
	r11.s64 = 0;
loc_82297820:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822979f4
	if (cr6.eq) goto loc_822979F4;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297834;
	sub_822959B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r30,1396
	ctx.r4.s64 = r30.s64 + 1396;
	// bl 0x821c8fe0
	ctx.lr = 0x82297844;
	sub_821C8FE0(ctx, base);
	// lbz r11,0(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229787c
	if (!cr6.eq) goto loc_8229787C;
	// addi r31,r30,552
	r31.s64 = r30.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82297860;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x82297868;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x82297878;
	sub_82618C80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8229787C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822978b4
	if (cr6.eq) goto loc_822978B4;
	// addi r31,r30,584
	r31.s64 = r30.s64 + 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82297898;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x822978A0;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822978B0;
	sub_82618C80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_822978B4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979ec
	if (cr6.eq) goto loc_822979EC;
	// addi r26,r30,748
	r26.s64 = r30.s64 + 748;
loc_822978C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x822978D0;
	sub_822954F0(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// bge cr6,0x822979ec
	if (!cr6.lt) goto loc_822979EC;
	// lbz r11,0(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822978fc
	if (!cr6.eq) goto loc_822978FC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295238
	ctx.lr = 0x822978F0;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
loc_822978FC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x82297908;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954b8
	ctx.lr = 0x82297920;
	sub_822954B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r28,r31
	r28.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bl 0x82295510
	ctx.lr = 0x82297938;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8229798c
	if (!cr6.eq) goto loc_8229798C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826185a0
	ctx.lr = 0x82297948;
	sub_826185A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229795c
	if (!cr6.eq) goto loc_8229795C;
	// lwz r28,0(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8229795C:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229797c
	if (cr6.eq) goto loc_8229797C;
loc_8229796C:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229796c
	if (!cr6.eq) goto loc_8229796C;
loc_8229797C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82299788
	ctx.lr = 0x82297988;
	sub_82299788(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8229798C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// addi r31,r30,520
	r31.s64 = r30.s64 + 520;
	// lwz r4,-136(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + -136);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822979A8;
	sub_82618830(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822979B8;
	sub_82618C80(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// stw r28,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822951d0
	ctx.lr = 0x822979D8;
	sub_822951D0(ctx, base);
loc_822979D8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822978c8
	if (!cr6.eq) goto loc_822978C8;
loc_822979EC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x822979F4;
	sub_821C9030(ctx, base);
loc_822979F4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297a1c
	if (cr6.eq) goto loc_82297A1C;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297a1c
	if (cr6.eq) goto loc_82297A1C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297A14;
	sub_822959B8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
loc_82297A1C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822977B8) {
	__imp__sub_822977B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297A28) {
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
	ctx.lr = 0x82297A30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r27,r31,144
	r27.s64 = r31.s64 + 144;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82486c48
	ctx.lr = 0x82297A44;
	sub_82486C48(ctx, base);
	// lwz r11,11784(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11784);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// addi r30,r31,11784
	r30.s64 = r31.s64 + 11784;
	// ori r29,r10,25904
	r29.u64 = ctx.r10.u64 | 25904;
	// li r26,0
	r26.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82297a90
	if (cr6.eq) goto loc_82297A90;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x82297a80
	if (!cr6.eq) goto loc_82297A80;
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,27
	ctx.r5.s64 = 27;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297A80;
	sub_822990D8(ctx, base);
loc_82297A80:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82297A8C;
	sub_821CE080(ctx, base);
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82297A90:
	// lwz r11,11792(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11792);
	// addi r30,r31,11792
	r30.s64 = r31.s64 + 11792;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82297acc
	if (cr6.eq) goto loc_82297ACC;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x82297abc
	if (!cr6.eq) goto loc_82297ABC;
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,27
	ctx.r5.s64 = 27;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297ABC;
	sub_822990D8(ctx, base);
loc_82297ABC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82297AC8;
	sub_821CE080(ctx, base);
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82297ACC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481578
	ctx.lr = 0x82297AD4;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297b60
	if (!cr6.eq) goto loc_82297B60;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481688
	ctx.lr = 0x82297B0C;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82295708
	ctx.lr = 0x82297B20;
	sub_82295708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296ae0
	ctx.lr = 0x82297B38;
	sub_82296AE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296188
	ctx.lr = 0x82297B44;
	sub_82296188(ctx, base);
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297B58;
	sub_822990D8(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x822957a8
	ctx.lr = 0x82297B60;
	sub_822957A8(ctx, base);
loc_82297B60:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82297A28) {
	__imp__sub_82297A28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297B68) {
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
	ctx.lr = 0x82297B70;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// bl 0x82501b00
	ctx.lr = 0x82297B84;
	sub_82501B00(ctx, base);
	// addi r23,r26,16
	r23.s64 = r26.s64 + 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x824e7060
	ctx.lr = 0x82297B90;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297bb4
	if (cr6.eq) goto loc_82297BB4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r5,r26,112
	ctx.r5.s64 = r26.s64 + 112;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271118
	ctx.lr = 0x82297BB4;
	sub_82271118(ctx, base);
loc_82297BB4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r31,-10240(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82297BC0;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822704d0
	ctx.lr = 0x82297BCC;
	sub_822704D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82297be4
	if (!cr6.eq) goto loc_82297BE4;
loc_82297BD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
loc_82297BE4:
	// addi r22,r28,144
	r22.s64 = r28.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824823f0
	ctx.lr = 0x82297BF4;
	sub_824823F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x82297C08;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82297C0C;
	sub_82130000(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82501a88
	ctx.lr = 0x82297C18;
	sub_82501A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297c28
	if (cr6.eq) goto loc_82297C28;
	// stw r29,11780(r28)
	PPC_STORE_U32(r28.u32 + 11780, r29.u32);
loc_82297C28:
	// addi r24,r29,16
	r24.s64 = r29.s64 + 16;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824e7060
	ctx.lr = 0x82297C34;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297c60
	if (cr6.eq) goto loc_82297C60;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// addi r9,r10,8656
	ctx.r9.s64 = ctx.r10.s64 + 8656;
	// lwz r11,8792(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8792);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x826189a8
	ctx.lr = 0x82297C60;
	sub_826189A8(ctx, base);
loc_82297C60:
	// addi r25,r28,12
	r25.s64 = r28.s64 + 12;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82297C6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297ca0
	if (cr6.eq) goto loc_82297CA0;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82297C80;
	sub_82502300(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82502300
	ctx.lr = 0x82297C8C;
	sub_82502300(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x824f0550
	ctx.lr = 0x82297C94;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297cb4
	if (!cr6.eq) goto loc_82297CB4;
loc_82297CA0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bne cr6,0x82297c6c
	if (!cr6.eq) goto loc_82297C6C;
	// b 0x82297cc0
	goto loc_82297CC0;
loc_82297CB4:
	// mr r30,r31
	r30.u64 = r31.u64;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x82297cfc
	if (!cr6.eq) goto loc_82297CFC;
loc_82297CC0:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_82297CC8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82297cf0
	if (cr6.eq) goto loc_82297CF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x82297cc8
	if (cr6.lt) goto loc_82297CC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
loc_82297CF0:
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
loc_82297CFC:
	// li r11,0
	r11.s64 = 0;
	// addi r10,r29,208
	ctx.r10.s64 = r29.s64 + 208;
loc_82297D04:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// beq cr6,0x82297d24
	if (cr6.eq) goto loc_82297D24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82297d04
	if (!cr6.eq) goto loc_82297D04;
	// b 0x82297d30
	goto loc_82297D30;
loc_82297D24:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82297d40
	if (!cr6.eq) goto loc_82297D40;
loc_82297D30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822729c8
	ctx.lr = 0x82297D38;
	sub_822729C8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
loc_82297D40:
	// addi r11,r3,26
	r11.s64 = ctx.r3.s64 + 26;
	// addi r10,r30,3
	ctx.r10.s64 = r30.s64 + 3;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r31,1
	r31.s64 = 1;
	// stwx r29,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, r29.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stb r31,5(r11)
	PPC_STORE_U8(r11.u32 + 5, r31.u8);
	// lbz r8,280(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 280);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r31,279(r29)
	PPC_STORE_U8(r29.u32 + 279, r31.u8);
	// bne cr6,0x82297d8c
	if (!cr6.eq) goto loc_82297D8C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824e7008
	ctx.lr = 0x82297D7C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297d8c
	if (!cr6.eq) goto loc_82297D8C;
	// li r31,0
	r31.s64 = 0;
loc_82297D8C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297da8
	if (cr6.eq) goto loc_82297DA8;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// bl 0x82130000
	ctx.lr = 0x82297DA8;
	sub_82130000(ctx, base);
loc_82297DA8:
	// lis r11,5
	r11.s64 = 327680;
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// ori r31,r11,25904
	r31.u64 = r11.u64 | 25904;
	// li r5,15
	ctx.r5.s64 = 15;
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297DC4;
	sub_822990D8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// addi r9,r10,-1372
	ctx.r9.s64 = ctx.r10.s64 + -1372;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x824e6310
	ctx.lr = 0x82297DD8;
	sub_824E6310(ctx, base);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r30,-10240(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82297DE8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822704d0
	ctx.lr = 0x82297DF4;
	sub_822704D0(ctx, base);
	// lwz r7,124(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// lwz r6,128(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// ld r8,112(r26)
	ctx.r8.u64 = PPC_LOAD_U64(r26.u32 + 112);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// std r8,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r8.u64);
	// bl 0x824e7060
	ctx.lr = 0x82297E18;
	sub_824E7060(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82297ec4
	if (cr6.eq) goto loc_82297EC4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82297E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r30,31
	r30.s64 = 31;
loc_82297E4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82297E60;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x824825f0
	ctx.lr = 0x82297E7C;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82297E94;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82270170
	ctx.lr = 0x82297EA4;
	sub_82270170(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82274a58
	ctx.lr = 0x82297EB4;
	sub_82274A58(ctx, base);
loc_82297EB4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82297e4c
	if (!cr0.eq) goto loc_82297E4C;
	// b 0x82297eec
	goto loc_82297EEC;
loc_82297EC4:
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,7
	ctx.r5.s64 = 7;
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297ED8;
	sub_822990D8(ctx, base);
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r5,14
	ctx.r5.s64 = 14;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297EEC;
	sub_822990D8(ctx, base);
loc_82297EEC:
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82297F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82297B68) {
	__imp__sub_82297B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82297F14) {
	__imp__sub_82297F14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82297F18) {
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
	ctx.lr = 0x82297F20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82297f40
	if (!cr6.eq) goto loc_82297F40;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82297F40:
	// lwz r11,11780(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 11780);
	// li r26,0
	r26.s64 = 0;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x82297f54
	if (!cr6.eq) goto loc_82297F54;
	// stw r26,11780(r28)
	PPC_STORE_U32(r28.u32 + 11780, r26.u32);
loc_82297F54:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// ori r29,r11,25904
	r29.u64 = r11.u64 | 25904;
	// li r5,14
	ctx.r5.s64 = 14;
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297F74;
	sub_822990D8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r9,r10,16332
	ctx.r9.s64 = ctx.r10.s64 + 16332;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297F9C;
	sub_822990D8(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,68(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82297FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,277(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 277);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82297fe0
	if (!cr6.eq) goto loc_82297FE0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297FD0;
	sub_82272A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82296fa8
	ctx.lr = 0x82297FDC;
	sub_82296FA8(ctx, base);
	// b 0x82297fe8
	goto loc_82297FE8;
loc_82297FE0:
	// li r11,1
	r11.s64 = 1;
	// stb r11,278(r31)
	PPC_STORE_U8(r31.u32 + 278, r11.u8);
loc_82297FE8:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82297FF0;
	sub_824E7008(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x82298004;
	sub_82271D18(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298078
	if (cr6.eq) goto loc_82298078;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226b020
	ctx.lr = 0x82298018;
	sub_8226B020(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298078
	if (!cr6.eq) goto loc_82298078;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_8229802C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8229804c
	if (cr6.eq) goto loc_8229804C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82298040;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298060
	if (!cr6.eq) goto loc_82298060;
loc_8229804C:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r27,31
	cr6.compare<int32_t>(r27.s32, 31, xer);
	// bne cr6,0x8229802c
	if (!cr6.eq) goto loc_8229802C;
	// b 0x82298064
	goto loc_82298064;
loc_82298060:
	// li r26,1
	r26.s64 = 1;
loc_82298064:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298078
	if (!cr6.eq) goto loc_82298078;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82297280
	ctx.lr = 0x82298078;
	sub_82297280(ctx, base);
loc_82298078:
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x8229808C;
	sub_822990D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82297F18) {
	__imp__sub_82297F18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298098) {
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
	ctx.lr = 0x822980A0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,64(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822981b0
	if (cr6.eq) goto loc_822981B0;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481688
	ctx.lr = 0x822980C0;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82296c50
	ctx.lr = 0x822980EC;
	sub_82296C50(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296188
	ctx.lr = 0x822980F8;
	sub_82296188(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x822957a8
	ctx.lr = 0x82298100;
	sub_822957A8(ctx, base);
loc_82298100:
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// stb r29,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r29.u8);
	// stw r29,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r29.u32);
loc_82298110:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298144
	if (cr6.eq) goto loc_82298144;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82298124;
	sub_82130000(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x824f97c0
	ctx.lr = 0x82298130;
	sub_824F97C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f97c0
	ctx.lr = 0x8229813C;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r26
	cr6.compare<uint64_t>(ctx.r3.u64, r26.u64, xer);
	// beq cr6,0x82298158
	if (cr6.eq) goto loc_82298158;
loc_82298144:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x82298110
	if (!cr6.eq) goto loc_82298110;
	// b 0x82298168
	goto loc_82298168;
loc_82298158:
	// addi r11,r29,3
	r11.s64 = r29.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stw r9,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, ctx.r9.u32);
loc_82298168:
	// lwz r11,11780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11780);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822981b0
	if (cr6.eq) goto loc_822981B0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r10,16340
	ctx.r8.s64 = ctx.r10.s64 + 16340;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r5,25
	ctx.r5.s64 = 25;
	// lwz r4,-10240(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822981A4;
	sub_822990D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_822981B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,26
	ctx.r5.s64 = 26;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822981CC;
	sub_822990D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82298098) {
	__imp__sub_82298098(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822981D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822981E0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r29,r30,144
	r29.s64 = r30.s64 + 144;
	// cmplw cr6,r29,r4
	cr6.compare<uint32_t>(r29.u32, ctx.r4.u32, xer);
	// bne cr6,0x82298544
	if (!cr6.eq) goto loc_82298544;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229820C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,12
	cr6.compare<uint32_t>(ctx.r3.u32, 12, xer);
	// bgt cr6,0x82298544
	if (cr6.gt) goto loc_82298544;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-32212
	r12.s64 = r12.s64 + -32212;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-32080(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32080);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31664(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31664);
	// lwz r17,-31896(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31896);
	// lwz r17,-31848(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31848);
	// lwz r17,-32160(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32160);
	// lwz r17,-32140(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32140);
	// lwz r17,-31504(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31504);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31932(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31932);
	// lwz r17,-31916(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31916);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31468(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31468);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82297b68
	ctx.lr = 0x8229826C;
	sub_82297B68(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// lwz r31,-10240(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82298288;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822704d0
	ctx.lr = 0x82298294;
	sub_822704D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297f18
	ctx.lr = 0x822982A8;
	sub_82297F18(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x822982B8;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// lwz r29,-10240(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x822982D8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822704d0
	ctx.lr = 0x822982E4;
	sub_822704D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r11,112
	ctx.r8.s64 = r11.s64 + 112;
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r7,r10,16348
	ctx.r7.s64 = ctx.r10.s64 + 16348;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// lwz r3,624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 624);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298330;
	sub_822990D8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r10,628(r11)
	PPC_STORE_U32(r11.u32 + 628, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// li r11,1
	r11.s64 = 1;
	// stb r11,9(r30)
	PPC_STORE_U8(r30.u32 + 9, r11.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82298098
	ctx.lr = 0x82298360;
	sub_82298098(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298390;
	sub_822990D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822983BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsb r8,r3
	ctx.r8.s64 = ctx.r3.s8;
	// cmpwi cr6,r8,89
	cr6.compare<int32_t>(ctx.r8.s32, 89, xer);
	// beq cr6,0x822983e4
	if (cr6.eq) goto loc_822983E4;
	// li r11,0
	r11.s64 = 0;
	// stb r3,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r3.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,648(r31)
	PPC_STORE_U8(r31.u32 + 648, r11.u8);
	// stw r10,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822983E4:
	// li r11,1
	r11.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r11,648(r31)
	PPC_STORE_U8(r31.u32 + 648, r11.u8);
	// bl 0x82618750
	ctx.lr = 0x822983F4;
	sub_82618750(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618750
	ctx.lr = 0x822983FC;
	sub_82618750(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r31,132
	ctx.r4.s64 = r31.s64 + 132;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618610
	ctx.lr = 0x82298410;
	sub_82618610(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r9,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// bl 0x82295328
	ctx.lr = 0x82298430;
	sub_82295328(ctx, base);
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822977b8
	ctx.lr = 0x8229843C;
	sub_822977B8(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x826186a0
	ctx.lr = 0x82298444;
	sub_826186A0(ctx, base);
	// stw r3,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r3.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82618750
	ctx.lr = 0x82298458;
	sub_82618750(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82618750
	ctx.lr = 0x82298460;
	sub_82618750(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x826185b0
	ctx.lr = 0x82298478;
	sub_826185B0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x822709c8
	ctx.lr = 0x82298494;
	sub_822709C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822959b8
	ctx.lr = 0x822984A8;
	sub_822959B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82296188
	ctx.lr = 0x822984C4;
	sub_82296188(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r4,-10240(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822984E0;
	sub_822990D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822957a8
	ctx.lr = 0x822984E8;
	sub_822957A8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x8229850C;
	sub_822990D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82297568
	ctx.lr = 0x82298528;
	sub_82297568(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r4,-10240(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298544;
	sub_822990D8(ctx, base);
loc_82298544:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822981D8) {
	__imp__sub_822981D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229854C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229854C) {
	__imp__sub_8229854C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298550) {
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
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// bl 0x82489428
	ctx.lr = 0x82298578;
	sub_82489428(ctx, base);
	// stw r30,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, r30.u32);
	// stw r30,11764(r31)
	PPC_STORE_U32(r31.u32 + 11764, r30.u32);
	// addi r3,r31,11800
	ctx.r3.s64 = r31.s64 + 11800;
	// stw r30,11768(r31)
	PPC_STORE_U32(r31.u32 + 11768, r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,11772(r31)
	PPC_STORE_U32(r31.u32 + 11772, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,11776(r31)
	PPC_STORE_U32(r31.u32 + 11776, r30.u32);
	// stw r30,11784(r31)
	PPC_STORE_U32(r31.u32 + 11784, r30.u32);
	// stw r30,11788(r31)
	PPC_STORE_U32(r31.u32 + 11788, r30.u32);
	// stw r30,11792(r31)
	PPC_STORE_U32(r31.u32 + 11792, r30.u32);
	// stw r30,11796(r31)
	PPC_STORE_U32(r31.u32 + 11796, r30.u32);
	// bl 0x821ce460
	ctx.lr = 0x822985AC;
	sub_821CE460(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// li r5,124
	ctx.r5.s64 = 124;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822985BC;
	sub_823D9890(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stb r30,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// stb r30,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r30.u8);
	// stw r30,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r30.u32);
	// stw r30,11816(r31)
	PPC_STORE_U32(r31.u32 + 11816, r30.u32);
	// bl 0x82297220
	ctx.lr = 0x822985DC;
	sub_82297220(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822985f8
	if (cr6.eq) goto loc_822985F8;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822985f8
	if (cr6.eq) goto loc_822985F8;
	// bl 0x82295460
	ctx.lr = 0x822985F8;
	sub_82295460(ctx, base);
loc_822985F8:
	// li r3,1428
	ctx.r3.s64 = 1428;
	// bl 0x82130528
	ctx.lr = 0x82298600;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298614
	if (cr6.eq) goto loc_82298614;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82295338
	ctx.lr = 0x82298610;
	sub_82295338(ctx, base);
	// b 0x82298618
	goto loc_82298618;
loc_82298614:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82298618:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// stw r30,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-32296
	ctx.r10.s64 = r11.s64 + -32296;
	// stw r10,11764(r31)
	PPC_STORE_U32(r31.u32 + 11764, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x82298634;
	sub_82130000(ctx, base);
	// stw r3,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r30.u32);
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

PPC_WEAK_FUNC(sub_82298550) {
	__imp__sub_82298550(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298658) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x822a5578
	ctx.lr = 0x8229867C;
	sub_822A5578(ctx, base);
	// lbz r11,140(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298690
	if (!cr6.eq) goto loc_82298690;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8229871c
	goto loc_8229871C;
loc_82298690:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822986ac
	if (cr6.gt) goto loc_822986AC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8229871c
	goto loc_8229871C;
loc_822986AC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 - f0.f64));
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f11,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lfs f8,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// fsel f1,f2,f3,f9
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f9.f64;
	// fsubs f0,f1,f8
	f0.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// fsel f13,f0,f8,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f8.f64 : ctx.f1.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82298718
	if (!cr6.lt) goto loc_82298718;
	// li r11,0
	r11.s64 = 0;
loc_82298718:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
loc_8229871C:
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

PPC_WEAK_FUNC(sub_82298658) {
	__imp__sub_82298658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82298734) {
	__imp__sub_82298734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298738) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82298754
	if (cr6.gt) goto loc_82298754;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82298754:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lfs f8,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// fsel f1,f2,f3,f9
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f9.f64;
	// fsubs f0,f1,f8
	f0.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// fsel f13,f0,f8,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f8.f64 : ctx.f1.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822987c0
	if (!cr6.lt) goto loc_822987C0;
	// li r11,0
	r11.s64 = 0;
loc_822987C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82298738) {
	__imp__sub_82298738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822987C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x822987EC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82298834
	if (!cr6.gt) goto loc_82298834;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
loc_82298804:
	// addic. r9,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r9.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82298828
	if (cr0.eq) goto loc_82298828;
	// stfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// sth r10,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r10.u16);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stb r10,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r10.u8);
	// stb r10,11(r11)
	PPC_STORE_U8(r11.u32 + 11, ctx.r10.u8);
loc_82298828:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x82298804
	if (!cr0.eq) goto loc_82298804;
loc_82298834:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822987C8) {
	__imp__sub_822987C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82298848) {
	__imp__sub_82298848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298858) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// sth r30,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r30.u16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822988b4
	if (cr6.eq) goto loc_822988B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,984(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 984);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822988a0
	if (cr6.gt) goto loc_822988A0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822988A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822988b0
	if (cr6.eq) goto loc_822988B0;
	// bl 0x822a57d0
	ctx.lr = 0x822988B0;
	sub_822A57D0(ctx, base);
loc_822988B0:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_822988B4:
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

PPC_WEAK_FUNC(sub_82298858) {
	__imp__sub_82298858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822988CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822988CC) {
	__imp__sub_822988CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822988D0) {
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
	ctx.lr = 0x822988D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,0(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,1220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 1220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x822051a0
	ctx.lr = 0x822988F8;
	sub_822051A0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8229890C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17892(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82298940
	if (cr6.eq) goto loc_82298940;
	// addi r10,r31,101
	ctx.r10.s64 = r31.s64 + 101;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x82298948
	goto loc_82298948;
loc_82298940:
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_82298948:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229895C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_8229896C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822989c8
	if (cr6.eq) goto loc_822989C8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x8229897C;
	sub_822A8108(ctx, base);
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x822a8108
	ctx.lr = 0x82298988;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
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
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822989C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,29500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822988D0) {
	__imp__sub_822988D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822989D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_822989EC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x82298a0c
	if (cr6.eq) goto loc_82298A0C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822989ec
	if (cr6.lt) goto loc_822989EC;
	// blr 
	return;
loc_82298A0C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lhz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r9,r11,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FFFC;
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// li r8,5
	ctx.r8.s64 = 5;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82298A58:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82298a58
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82298A58;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822989D8) {
	__imp__sub_822989D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8229af08
	ctx.lr = 0x82298A9C;
	sub_8229AF08(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298AA4;
	sub_822A5578(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r3,124
	r11.s64 = ctx.r3.s64 + 124;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82298AB4:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x82298ab4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82298AB4;
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// li r11,0
	r11.s64 = 0;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// stfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lbz r8,18(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// stb r11,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r11.u8);
	// stb r10,19(r31)
	PPC_STORE_U8(r31.u32 + 19, ctx.r10.u8);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lbz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// sth r9,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r9.u16);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stb r8,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r8.u8);
	// stb r4,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r4.u8);
	// lwz r3,48(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bge cr6,0x82298b20
	if (!cr6.lt) goto loc_82298B20;
	// li r7,-1
	ctx.r7.s64 = -1;
	// b 0x82298b30
	goto loc_82298B30;
loc_82298B20:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// bgt cr6,0x82298b30
	if (cr6.gt) goto loc_82298B30;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_82298B30:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,128(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// beq cr6,0x82298b5c
	if (cr6.eq) goto loc_82298B5C;
	// addi r4,r11,272
	ctx.r4.s64 = r11.s64 + 272;
	// b 0x82298b64
	goto loc_82298B64;
loc_82298B5C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_82298B64:
	// addi r6,r10,288
	ctx.r6.s64 = ctx.r10.s64 + 288;
	// addi r5,r10,272
	ctx.r5.s64 = ctx.r10.s64 + 272;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8229b348
	ctx.lr = 0x82298B74;
	sub_8229B348(ctx, base);
	// stfs f31,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lbz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stb r8,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r8.u8);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b620
	ctx.lr = 0x82298B9C;
	sub_8227B620(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

PPC_WEAK_FUNC(sub_82298A70) {
	__imp__sub_82298A70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298BB8) {
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
	ctx.lr = 0x82298BC0;
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
	// addi r10,r11,16704
	ctx.r10.s64 = r11.s64 + 16704;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// sth r28,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r28.u16);
	// sth r28,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r28.u16);
	// beq cr6,0x82298c00
	if (cr6.eq) goto loc_82298C00;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822987c8
	ctx.lr = 0x82298BFC;
	sub_822987C8(ctx, base);
	// b 0x82298c04
	goto loc_82298C04;
loc_82298C00:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82298C04:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82298BB8) {
	__imp__sub_82298BB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82298C1C) {
	__imp__sub_82298C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298C20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82298c60
	if (!cr6.gt) goto loc_82298C60;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_82298C38:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// beq cr6,0x82298c58
	if (cr6.eq) goto loc_82298C58;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82298c38
	if (cr6.lt) goto loc_82298C38;
	// b 0x82298c60
	goto loc_82298C60;
loc_82298C58:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgelr cr6
	if (!cr6.lt) return;
loc_82298C60:
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// sth r6,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r6.u16);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// sth r8,16(r11)
	PPC_STORE_U16(r11.u32 + 16, ctx.r8.u16);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stb r8,18(r11)
	PPC_STORE_U8(r11.u32 + 18, ctx.r8.u8);
	// stb r8,19(r11)
	PPC_STORE_U8(r11.u32 + 19, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82298C20) {
	__imp__sub_82298C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82298CAC) {
	__imp__sub_82298CAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298CB0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82298CB8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 28);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82298dc4
	if (!cr6.eq) goto loc_82298DC4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82298dc4
	if (cr6.eq) goto loc_82298DC4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82298dc4
	if (cr6.eq) goto loc_82298DC4;
	// li r29,0
	r29.s64 = 0;
loc_82298D0C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r30,r29,r11
	r30.u64 = r29.u64 + r11.u64;
	// bl 0x822a5578
	ctx.lr = 0x82298D1C;
	sub_822A5578(ctx, base);
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lhz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// sth r9,16(r30)
	PPC_STORE_U16(r30.u32 + 16, ctx.r9.u16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298D34;
	sub_822A5578(ctx, base);
	// lbz r7,127(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 127);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82298d50
	if (cr6.eq) goto loc_82298D50;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298D48;
	sub_822A5578(ctx, base);
	// lbz r11,127(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 127);
	// stb r11,18(r30)
	PPC_STORE_U8(r30.u32 + 18, r11.u8);
loc_82298D50:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822988d0
	ctx.lr = 0x82298D5C;
	sub_822988D0(ctx, base);
	// stfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298658
	ctx.lr = 0x82298D70;
	sub_82298658(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298738
	ctx.lr = 0x82298D84;
	sub_82298738(ctx, base);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298da0
	if (!cr6.eq) goto loc_82298DA0;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298db0
	if (cr6.eq) goto loc_82298DB0;
loc_82298DA0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298a70
	ctx.lr = 0x82298DB0;
	sub_82298A70(ctx, base);
loc_82298DB0:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82298d0c
	if (cr6.lt) goto loc_82298D0C;
loc_82298DC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82298CB0) {
	__imp__sub_82298CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298DD0) {
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
	// addi r10,r11,16704
	ctx.r10.s64 = r11.s64 + 16704;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82298e0c
	if (cr6.eq) goto loc_82298E0C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82298E0C;
	sub_82130588(ctx, base);
loc_82298E0C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298e24
	if (cr6.eq) goto loc_82298E24;
	// bl 0x82130588
	ctx.lr = 0x82298E20;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82298E24:
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

PPC_WEAK_FUNC(sub_82298DD0) {
	__imp__sub_82298DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82298E3C) {
	__imp__sub_82298E3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298E40) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82298e68
	if (!cr6.eq) goto loc_82298E68;
loc_82298E60:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82298e98
	goto loc_82298E98;
loc_82298E68:
	// li r31,0
	r31.s64 = 0;
	// addi r30,r3,21856
	r30.s64 = ctx.r3.s64 + 21856;
loc_82298E70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fd670
	ctx.lr = 0x82298E78;
	sub_824FD670(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298e60
	if (!cr6.eq) goto loc_82298E60;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x82298e70
	if (cr6.lt) goto loc_82298E70;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82298E98:
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

PPC_WEAK_FUNC(sub_82298E40) {
	__imp__sub_82298E40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298EB0) {
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
	ctx.lr = 0x82298EB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,27505
	r31.s64 = ctx.r3.s64 + 27505;
	// addi r29,r3,21856
	r29.s64 = ctx.r3.s64 + 21856;
	// li r30,32
	r30.s64 = 32;
	// li r28,0
	r28.s64 = 0;
loc_82298ECC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fd670
	ctx.lr = 0x82298ED4;
	sub_824FD670(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298ee8
	if (cr6.eq) goto loc_82298EE8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fd688
	ctx.lr = 0x82298EE8;
	sub_824FD688(ctx, base);
loc_82298EE8:
	// stb r28,-1(r31)
	PPC_STORE_U8(r31.u32 + -1, r28.u8);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x82298ecc
	if (!cr0.eq) goto loc_82298ECC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82298EB0) {
	__imp__sub_82298EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298F08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,2000(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82298f48
	if (cr6.eq) goto loc_82298F48;
	// addi r10,r3,27504
	ctx.r10.s64 = ctx.r3.s64 + 27504;
loc_82298F20:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82298f38
	if (cr6.eq) goto loc_82298F38;
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x82298f50
	if (cr6.eq) goto loc_82298F50;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_82298F38:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82298f20
	if (!cr6.eq) goto loc_82298F20;
loc_82298F48:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82298F50:
	// mulli r11,r11,620
	r11.s64 = r11.s64 * 620;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,2016
	ctx.r3.s64 = r11.s64 + 2016;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82298F08) {
	__imp__sub_82298F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82298F60) {
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
	ctx.lr = 0x82298F68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8229907c
	if (!cr6.eq) goto loc_8229907C;
	// addi r26,r31,528
	r26.s64 = r31.s64 + 528;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824fbd50
	ctx.lr = 0x82298F9C;
	sub_824FBD50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229907c
	if (!cr6.eq) goto loc_8229907C;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x82298FB4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229907c
	if (cr6.eq) goto loc_8229907C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x82298FC8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298fe0
	if (!cr6.eq) goto loc_82298FE0;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229907c
	if (cr6.eq) goto loc_8229907C;
loc_82298FE0:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x82298eb0
	ctx.lr = 0x82298FF0;
	sub_82298EB0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// stw r27,2000(r31)
	PPC_STORE_U32(r31.u32 + 2000, r27.u32);
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10240);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x82299010;
	sub_822950F8(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrlwi r8,r23,24
	ctx.r8.u64 = r23.u32 & 0xFF;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// addi r10,r31,1992
	ctx.r10.s64 = r31.s64 + 1992;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r4,2008(r31)
	PPC_STORE_U32(r31.u32 + 2008, ctx.r4.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// lwz r11,-10240(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10240);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// rlwinm r5,r5,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// bl 0x824fd470
	ctx.lr = 0x82299064;
	sub_824FD470(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82299080
	if (!cr6.eq) goto loc_82299080;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8229907C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82299080:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82298F60) {
	__imp__sub_82298F60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299088) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82299090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,528
	ctx.r3.s64 = r31.s64 + 528;
	// bl 0x824fd0b0
	ctx.lr = 0x822990A0;
	sub_824FD0B0(ctx, base);
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
	// addi r31,r31,28128
	r31.s64 = r31.s64 + 28128;
	// li r30,32
	r30.s64 = 32;
	// li r28,0
	r28.s64 = 0;
loc_822990B0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82270908
	ctx.lr = 0x822990BC;
	sub_82270908(ctx, base);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// bne 0x822990b0
	if (!cr0.eq) goto loc_822990B0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82299088) {
	__imp__sub_82299088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822990D8) {
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
	ctx.lr = 0x822990E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821b5a60
	ctx.lr = 0x82299108;
	sub_821B5A60(ctx, base);
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// bl 0x821b5a60
	ctx.lr = 0x82299110;
	sub_821B5A60(ctx, base);
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stb r9,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// bl 0x827283c8
	ctx.lr = 0x82299134;
	sub_827283C8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299190
	if (cr6.eq) goto loc_82299190;
loc_82299140:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299168
	if (cr6.eq) goto loc_82299168;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82299164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8229917c
	goto loc_8229917C;
loc_82299168:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8229917C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229917C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fd7b0
	ctx.lr = 0x82299184;
	sub_824FD7B0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299140
	if (!cr6.eq) goto loc_82299140;
loc_82299190:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229920c
	if (cr6.eq) goto loc_8229920C;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822991d0
	if (!cr6.eq) goto loc_822991D0;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822991c8
	if (cr6.eq) goto loc_822991C8;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r28.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991C8:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991D0:
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822991f0
	if (cr6.eq) goto loc_822991F0;
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991F0:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822991F8:
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8229920C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822990D8) {
	__imp__sub_822990D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299214) {
	__imp__sub_82299214(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r10,176
	ctx.r10.s64 = 176;
	// addi r11,r11,-21856
	r11.s64 = r11.s64 + -21856;
	// li r8,0
	ctx.r8.s64 = 0;
	// divw r11,r11,r10
	r11.s32 = r11.s32 / ctx.r10.s32;
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r8,27505(r11)
	PPC_STORE_U8(r11.u32 + 27505, ctx.r8.u8);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-28060
	r12.s64 = r12.s64 + -28060;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_82299218) {
	__imp__sub_82299218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299264) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r17{};
	// lwz r17,-28044(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28044);
	// lwz r17,-28020(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28020);
	// lwz r17,-27928(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27928);
	// lwz r17,-28012(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28012);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,28896
	ctx.r3.s64 = ctx.r3.s64 + 28896;
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82299264) {
	__imp__sub_82299264(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229928C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229928C) {
	__imp__sub_8229928C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299294) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r9,2000(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822992d4
	if (cr6.eq) goto loc_822992D4;
	// addi r11,r3,27504
	r11.s64 = ctx.r3.s64 + 27504;
loc_822992AC:
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822992ac
	if (!cr6.eq) goto loc_822992AC;
loc_822992D4:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,28896
	ctx.r3.s64 = ctx.r3.s64 + 28896;
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82299294) {
	__imp__sub_82299294(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822992E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r10,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r10.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r3,r3,28896
	ctx.r3.s64 = ctx.r3.s64 + 28896;
	// stw r9,27488(r11)
	PPC_STORE_U32(r11.u32 + 27488, ctx.r9.u32);
	// lwz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r8,27492(r11)
	PPC_STORE_U32(r11.u32 + 27492, ctx.r8.u32);
	// lwz r7,8(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r7,27496(r11)
	PPC_STORE_U32(r11.u32 + 27496, ctx.r7.u32);
	// lwz r10,12(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r10,27500(r11)
	PPC_STORE_U32(r11.u32 + 27500, ctx.r10.u32);
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822992E8) {
	__imp__sub_822992E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299320) {
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
	ctx.lr = 0x82299328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r28,528
	ctx.r3.s64 = r28.s64 + 528;
	// bl 0x824fbd00
	ctx.lr = 0x82299338;
	sub_824FBD00(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
	// bl 0x82298eb0
	ctx.lr = 0x82299348;
	sub_82298EB0(ctx, base);
	// addi r31,r28,28144
	r31.s64 = r28.s64 + 28144;
	// stw r29,2000(r28)
	PPC_STORE_U32(r28.u32 + 2000, r29.u32);
	// addi r30,r28,21868
	r30.s64 = r28.s64 + 21868;
	// li r27,32
	r27.s64 = 32;
loc_82299358:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r29,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, r29.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-28136
	ctx.r10.s64 = r11.s64 + -28136;
	// stw r10,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x82299370;
	sub_82130000(ctx, base);
	// stw r3,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r3.u32);
	// lwz r9,-8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822993bc
	if (cr6.eq) goto loc_822993BC;
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r11,r31,-16
	r11.s64 = r31.s64 + -16;
	// beq cr6,0x822993ac
	if (cr6.eq) goto loc_822993AC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// stw r10,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r10.u32);
	// b 0x822993d0
	goto loc_822993D0;
loc_822993AC:
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// stw r10,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r10.u32);
	// b 0x822993d0
	goto loc_822993D0;
loc_822993BC:
	// addi r11,r31,-16
	r11.s64 = r31.s64 + -16;
	// stw r11,-8(r30)
	PPC_STORE_U32(r30.u32 + -8, r11.u32);
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r29.u32);
loc_822993D0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r11,r30,-12
	r11.s64 = r30.s64 + -12;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x82299358
	if (!cr0.eq) goto loc_82299358;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82299320) {
	__imp__sub_82299320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822993FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822993FC) {
	__imp__sub_822993FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299400) {
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
	ctx.lr = 0x82299408;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// li r25,1
	r25.s64 = 1;
	// lwz r11,2004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2004);
	// subf r11,r11,r24
	r11.s64 = r24.s64 - r11.s64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bge cr6,0x82299430
	if (!cr6.lt) goto loc_82299430;
	// mr r28,r25
	r28.u64 = r25.u64;
	// b 0x82299440
	goto loc_82299440;
loc_82299430:
	// cmplwi cr6,r11,1000
	cr6.compare<uint32_t>(r11.u32, 1000, xer);
	// li r28,1000
	r28.s64 = 1000;
	// bgt cr6,0x82299440
	if (cr6.gt) goto loc_82299440;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82299440:
	// addi r27,r31,528
	r27.s64 = r31.s64 + 528;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fd428
	ctx.lr = 0x8229944C;
	sub_824FD428(ctx, base);
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82299480
	if (!cr6.gt) goto loc_82299480;
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
loc_82299460:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fdc88
	ctx.lr = 0x8229946C;
	sub_824FDC88(ctx, base);
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82299460
	if (cr6.lt) goto loc_82299460;
loc_82299480:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82299568
	if (!cr6.eq) goto loc_82299568;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82299568
	if (cr6.eq) goto loc_82299568;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fbd50
	ctx.lr = 0x822994A0;
	sub_824FBD50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299568
	if (!cr6.eq) goto loc_82299568;
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822994e0
	if (!cr6.eq) goto loc_822994E0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,28896
	ctx.r3.s64 = r31.s64 + 28896;
	// bl 0x822990d8
	ctx.lr = 0x822994CC;
	sub_822990D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r24,2004(r31)
	PPC_STORE_U32(r31.u32 + 2004, r24.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822994E0:
	// li r27,0
	r27.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
	// addi r30,r31,27488
	r30.s64 = r31.s64 + 27488;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_822994F4:
	// lbz r11,2012(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299530
	if (cr6.eq) goto loc_82299530;
	// lwz r11,-10240(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// li r7,11
	ctx.r7.s64 = 11;
	// lwz r10,1992(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1992);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,2008(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2008);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// addi r4,r10,557
	ctx.r4.s64 = ctx.r10.s64 + 557;
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824fdc30
	ctx.lr = 0x82299528;
	sub_824FDC30(ctx, base);
	// stb r25,17(r30)
	PPC_STORE_U8(r30.u32 + 17, r25.u8);
	// b 0x82299544
	goto loc_82299544;
loc_82299530:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299218
	ctx.lr = 0x82299544;
	sub_82299218(ctx, base);
loc_82299544:
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,620
	r28.s64 = r28.s64 + 620;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x822994f4
	if (!cr6.eq) goto loc_822994F4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82299568:
	// stw r24,2004(r31)
	PPC_STORE_U32(r31.u32 + 2004, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82299400) {
	__imp__sub_82299400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299574) {
	__imp__sub_82299574(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299578) {
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
	// bl 0x821c9788
	ctx.lr = 0x82299590;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824eff10
	ctx.lr = 0x8229959C;
	sub_824EFF10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82299578) {
	__imp__sub_82299578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822995B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_822995B0) {
	__imp__sub_822995B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822995C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822995C4) {
	__imp__sub_822995C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822995C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_822995C8) {
	__imp__sub_822995C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822995E0) {
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
	ctx.lr = 0x822995E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82299630
	if (!cr6.eq) goto loc_82299630;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229966c
	if (cr6.eq) goto loc_8229966C;
loc_82299630:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// stw r29,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r29.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r8,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r8.u8);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229966C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229966C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822995E0) {
	__imp__sub_822995E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299674) {
	__imp__sub_82299674(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299678) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822996A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822996d8
	if (cr6.eq) goto loc_822996D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822996C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822996D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822996D8:
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

PPC_WEAK_FUNC(sub_82299678) {
	__imp__sub_82299678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822996F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82299734
	if (!cr6.eq) goto loc_82299734;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299728
	if (cr6.eq) goto loc_82299728;
	// stw r6,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,100(r6)
	PPC_STORE_U32(ctx.r6.u32 + 100, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x8229976c
	if (!cr6.eq) goto loc_8229976C;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299728:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299734:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x82299754
	if (!cr6.eq) goto loc_82299754;
	// stw r11,96(r6)
	PPC_STORE_U32(ctx.r6.u32 + 96, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299754:
	// stw r5,96(r6)
	PPC_STORE_U32(ctx.r6.u32 + 96, ctx.r5.u32);
	// lwz r11,100(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// stw r11,100(r6)
	PPC_STORE_U32(ctx.r6.u32 + 100, r11.u32);
	// lwz r10,100(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// stw r6,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r6.u32);
	// stw r6,100(r5)
	PPC_STORE_U32(ctx.r5.u32 + 100, ctx.r6.u32);
loc_8229976C:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822996F0) {
	__imp__sub_822996F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299784) {
	__imp__sub_82299784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299788) {
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
	ctx.lr = 0x82299790;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822997B0;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822997f0
	if (cr6.eq) goto loc_822997F0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822997D8;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822997E4;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822997F0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82299788) {
	__imp__sub_82299788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822997FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822997FC) {
	__imp__sub_822997FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299800) {
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
	ctx.lr = 0x82299808;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229986c
	if (cr6.eq) goto loc_8229986C;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// li r30,16
	r30.s64 = 16;
loc_82299828:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ebcc8
	ctx.lr = 0x82299834;
	sub_824EBCC8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82299828
	if (!cr0.eq) goto loc_82299828;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824eeea0
	ctx.lr = 0x82299848;
	sub_824EEEA0(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299868
	if (cr6.eq) goto loc_82299868;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82299868:
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
loc_8229986C:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229988c
	if (cr6.eq) goto loc_8229988C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229988C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229988C:
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82299800) {
	__imp__sub_82299800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299898) {
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
	ctx.lr = 0x822998A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822998C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299918
	if (cr6.eq) goto loc_82299918;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// bl 0x824efbf8
	ctx.lr = 0x822998F8;
	sub_824EFBF8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stb r10,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82299918:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82299898) {
	__imp__sub_82299898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299924) {
	__imp__sub_82299924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299928) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299990
	if (cr6.eq) goto loc_82299990;
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
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82299980
	if (cr6.eq) goto loc_82299980;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82299990
	if (!cr6.eq) goto loc_82299990;
loc_82299980:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82299994
	if (!cr6.lt) goto loc_82299994;
loc_82299990:
	// li r11,0
	r11.s64 = 0;
loc_82299994:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822999c8
	if (cr6.eq) goto loc_822999C8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,5
	ctx.r10.s64 = 5;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ef220
	ctx.lr = 0x822999C8;
	sub_824EF220(ctx, base);
loc_822999C8:
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

PPC_WEAK_FUNC(sub_82299928) {
	__imp__sub_82299928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822999E0) {
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
	ctx.lr = 0x822999E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299A04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r27,8
	r28.s64 = r27.s64 + 8;
loc_82299A10:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82299a3c
	if (cr6.eq) goto loc_82299A3C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82299a2c
	if (cr6.eq) goto loc_82299A2C;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82299a3c
	if (!cr6.eq) goto loc_82299A3C;
loc_82299A2C:
	// lwz r11,-4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82299a40
	if (!cr6.lt) goto loc_82299A40;
loc_82299A3C:
	// li r11,0
	r11.s64 = 0;
loc_82299A40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299a60
	if (cr6.eq) goto loc_82299A60;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299928
	ctx.lr = 0x82299A5C;
	sub_82299928(ctx, base);
	// b 0x82299a84
	goto loc_82299A84;
loc_82299A60:
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ee190
	ctx.lr = 0x82299A6C;
	sub_824EE190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82299a84
	if (cr6.eq) goto loc_82299A84;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ef220
	ctx.lr = 0x82299A84;
	sub_824EF220(ctx, base);
loc_82299A84:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// blt cr6,0x82299a10
	if (cr6.lt) goto loc_82299A10;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822999E0) {
	__imp__sub_822999E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299A9C) {
	__imp__sub_82299A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82299AA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82299c90
	if (cr6.gt) goto loc_82299C90;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-25872
	r12.s64 = r12.s64 + -25872;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-25856(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25856);
	// lwz r17,-25652(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25652);
	// lwz r17,-25764(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25764);
	// lwz r17,-25520(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25520);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r9.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82299B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bgt cr6,0x82299bac
	if (cr6.gt) goto loc_82299BAC;
	// bl 0x821c9788
	ctx.lr = 0x82299BA8;
	sub_821C9788(ctx, base);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
loc_82299BAC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299BC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299c38
	if (cr6.eq) goto loc_82299C38;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bgt cr6,0x82299c1c
	if (cr6.gt) goto loc_82299C1C;
	// bl 0x821c9788
	ctx.lr = 0x82299C18;
	sub_821C9788(ctx, base);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
loc_82299C1C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,6
	ctx.r9.s64 = 6;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// stb r9,8(r7)
	PPC_STORE_U8(ctx.r7.u32 + 8, ctx.r9.u8);
loc_82299C38:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ef220
	ctx.lr = 0x82299C48;
	sub_824EF220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x82299C6C;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299C90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82299C90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82299AA0) {
	__imp__sub_82299AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299C98) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r3,r11,13928
	ctx.r3.s64 = r11.s64 + 13928;
	// bl 0x82297450
	ctx.lr = 0x82299CB8;
	sub_82297450(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,66
	ctx.r3.s64 = 66;
	// bge cr6,0x82299cc8
	if (!cr6.lt) goto loc_82299CC8;
	// li r3,89
	ctx.r3.s64 = 89;
loc_82299CC8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82299C98) {
	__imp__sub_82299C98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299CD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r10,-488
	ctx.r8.s64 = ctx.r10.s64 + -488;
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82299CF4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x82299cf4
	if (!cr0.lt) goto loc_82299CF4;
	// lbz r7,208(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 208);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// stw r10,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r10.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r10,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r10.u32);
	// stw r10,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r10.u32);
	// stb r6,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, ctx.r6.u8);
loc_82299D2C:
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82299d2c
	if (!cr0.eq) goto loc_82299D2C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82299CD8) {
	__imp__sub_82299CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299D44) {
	__imp__sub_82299D44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299D48) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82299d8c
	if (!cr6.gt) goto loc_82299D8C;
	// bl 0x821c9788
	ctx.lr = 0x82299D80;
	sub_821C9788(ctx, base);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// subf r3,r11,r3
	ctx.r3.s64 = ctx.r3.s64 - r11.s64;
	// b 0x82299d90
	goto loc_82299D90;
loc_82299D8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82299D90:
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

PPC_WEAK_FUNC(sub_82299D48) {
	__imp__sub_82299D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299DA8) {
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
	ctx.lr = 0x82299DB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82299DCC;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82299e0c
	if (cr6.eq) goto loc_82299E0C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82299DF4;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82299E00;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82299E0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82299DA8) {
	__imp__sub_82299DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299E18) {
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
	ctx.lr = 0x82299E20;
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
	ctx.lr = 0x82299E44;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82299E50;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82299E60;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82299e84
	if (cr6.eq) goto loc_82299E84;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82299da8
	ctx.lr = 0x82299E74;
	sub_82299DA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299e88
	if (!cr6.eq) goto loc_82299E88;
loc_82299E84:
	// li r30,0
	r30.s64 = 0;
loc_82299E88:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82299ec0
	if (cr6.eq) goto loc_82299EC0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299eb8
	if (cr6.eq) goto loc_82299EB8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82299EA4;
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
loc_82299EB8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82299EC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82299E18) {
	__imp__sub_82299E18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299ECC) {
	__imp__sub_82299ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299ED0) {
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
	ctx.lr = 0x82299ED8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82299F08;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82299F14;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82299F24;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299f58
	if (cr6.eq) goto loc_82299F58;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82299f58
	if (!cr6.eq) goto loc_82299F58;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82299F48;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299f5c
	if (!cr6.eq) goto loc_82299F5C;
loc_82299F58:
	// li r31,0
	r31.s64 = 0;
loc_82299F5C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82299f88
	if (cr6.eq) goto loc_82299F88;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299f80
	if (cr6.eq) goto loc_82299F80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82299F78;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82299f84
	goto loc_82299F84;
loc_82299F80:
	// li r11,0
	r11.s64 = 0;
loc_82299F84:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82299F88:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299fac
	if (cr6.eq) goto loc_82299FAC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82299F9C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82299fb0
	if (cr6.eq) goto loc_82299FB0;
loc_82299FAC:
	// li r11,0
	r11.s64 = 0;
loc_82299FB0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82299ED0) {
	__imp__sub_82299ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82299FBC) {
	__imp__sub_82299FBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82299FC0) {
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
	ctx.lr = 0x82299FC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,2308
	ctx.r3.s64 = 2308;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x82299FDC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a034
	if (cr6.eq) goto loc_8229A034;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229A018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x821c2d88
	ctx.lr = 0x8229A030;
	sub_821C2D88(ctx, base);
	// b 0x8229a038
	goto loc_8229A038;
loc_8229A034:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8229A038:
	// stw r3,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1340
	ctx.r3.s64 = 1340;
	// bl 0x82130528
	ctx.lr = 0x8229A058;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a068
	if (cr6.eq) goto loc_8229A068;
	// bl 0x824ed2b0
	ctx.lr = 0x8229A064;
	sub_824ED2B0(ctx, base);
	// b 0x8229a06c
	goto loc_8229A06C;
loc_8229A068:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8229A06C:
	// stw r3,68(r30)
	PPC_STORE_U32(r30.u32 + 68, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,72(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r5,31
	ctx.r5.s64 = 31;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824f01d8
	ctx.lr = 0x8229A08C;
	sub_824F01D8(ctx, base);
	// mr r29,r27
	r29.u64 = r27.u64;
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
loc_8229A094:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8229A09C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a0b0
	if (cr6.eq) goto loc_8229A0B0;
	// bl 0x824ebf78
	ctx.lr = 0x8229A0A8;
	sub_824EBF78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8229a0b4
	goto loc_8229A0B4;
loc_8229A0B0:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_8229A0B4:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,-25952
	ctx.r10.s64 = r11.s64 + -25952;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8229A0D0;
	sub_82130000(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ec120
	ctx.lr = 0x8229A0E4;
	sub_824EC120(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// blt cr6,0x8229a094
	if (cr6.lt) goto loc_8229A094;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82299FC0) {
	__imp__sub_82299FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A100) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,2100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a178
	if (cr6.eq) goto loc_8229A178;
	// lwz r3,2092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2092);
	// addi r10,r11,2092
	ctx.r10.s64 = r11.s64 + 2092;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a178
	if (cr6.eq) goto loc_8229A178;
loc_8229A120:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a138
	if (cr6.eq) goto loc_8229A138;
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// b 0x8229a16c
	goto loc_8229A16C;
loc_8229A138:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a154
	if (cr6.eq) goto loc_8229A154;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a158
	if (!cr6.eq) goto loc_8229A158;
loc_8229A154:
	// li r11,0
	r11.s64 = 0;
loc_8229A158:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a16c
	if (cr6.eq) goto loc_8229A16C;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_8229A16C:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8229a120
	if (!cr6.eq) goto loc_8229A120;
loc_8229A178:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229A100) {
	__imp__sub_8229A100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A180) {
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
	ctx.lr = 0x8229A188;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,2100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// lwz r31,2092(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2092);
	// addi r29,r30,2092
	r29.s64 = r30.s64 + 2092;
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// li r27,1
	r27.s64 = 1;
loc_8229A1B8:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e6358
	ctx.lr = 0x8229A1C4;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a1f4
	if (cr6.eq) goto loc_8229A1F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8229A1DC;
	sub_82273AE0(ctx, base);
	// addi r4,r30,2080
	ctx.r4.s64 = r30.s64 + 2080;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822996f0
	ctx.lr = 0x8229A1F0;
	sub_822996F0(ctx, base);
	// stb r27,2104(r30)
	PPC_STORE_U8(r30.u32 + 2104, r27.u8);
loc_8229A1F4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a204
	if (cr6.eq) goto loc_8229A204;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a238
	goto loc_8229A238;
loc_8229A204:
	// rlwinm r11,r28,0,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a220
	if (cr6.eq) goto loc_8229A220;
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x8229a224
	if (!cr6.eq) goto loc_8229A224;
loc_8229A220:
	// li r11,0
	r11.s64 = 0;
loc_8229A224:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// rlwinm r28,r28,0,0,30
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_8229A238:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a1b8
	if (!cr6.eq) goto loc_8229A1B8;
loc_8229A240:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8229A180) {
	__imp__sub_8229A180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A248) {
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
	ctx.lr = 0x8229A250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,2100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
	// lwz r31,2092(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 2092);
	// addi r29,r28,2092
	r29.s64 = r28.s64 + 2092;
	// mr r30,r29
	r30.u64 = r29.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
loc_8229A27C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824f92f8
	ctx.lr = 0x8229A288;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a2e8
	if (!cr6.eq) goto loc_8229A2E8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a2a4
	if (cr6.eq) goto loc_8229A2A4;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a2d8
	goto loc_8229A2D8;
loc_8229A2A4:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a2c0
	if (cr6.eq) goto loc_8229A2C0;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a2c4
	if (!cr6.eq) goto loc_8229A2C4;
loc_8229A2C0:
	// li r11,0
	r11.s64 = 0;
loc_8229A2C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8229A2D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a27c
	if (!cr6.eq) goto loc_8229A27C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8229A2E8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8229A2F4;
	sub_82273AE0(ctx, base);
	// addi r4,r28,2080
	ctx.r4.s64 = r28.s64 + 2080;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822996f0
	ctx.lr = 0x8229A308;
	sub_822996F0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, r11.u8);
loc_8229A310:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229A248) {
	__imp__sub_8229A248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A318) {
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
	ctx.lr = 0x8229A320;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16960
	ctx.r10.s64 = r11.s64 + 16960;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82299e18
	ctx.lr = 0x8229A354;
	sub_82299E18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a38c
	if (cr6.eq) goto loc_8229A38C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8229A37C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a390
	if (!cr6.eq) goto loc_8229A390;
loc_8229A38C:
	// li r11,0
	r11.s64 = 0;
loc_8229A390:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229A318) {
	__imp__sub_8229A318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229A39C) {
	__imp__sub_8229A39C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A3A0) {
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
	ctx.lr = 0x8229A3A8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16928
	ctx.r10.s64 = r11.s64 + 16928;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82299e18
	ctx.lr = 0x8229A3DC;
	sub_82299E18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a414
	if (cr6.eq) goto loc_8229A414;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8229A404;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a418
	if (!cr6.eq) goto loc_8229A418;
loc_8229A414:
	// li r11,0
	r11.s64 = 0;
loc_8229A418:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229A3A0) {
	__imp__sub_8229A3A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229A424) {
	__imp__sub_8229A424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A428) {
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
	ctx.lr = 0x8229A430;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,19
	r29.s64 = 19;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// li r31,0
	r31.s64 = 0;
loc_8229A444:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6400
	ctx.lr = 0x8229A44C;
	sub_824E6400(ctx, base);
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// bl 0x824f9438
	ctx.lr = 0x8229A454;
	sub_824F9438(ctx, base);
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// stw r31,84(r30)
	PPC_STORE_U32(r30.u32 + 84, r31.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stb r31,-16(r30)
	PPC_STORE_U8(r30.u32 + -16, r31.u8);
	// addi r30,r30,104
	r30.s64 = r30.s64 + 104;
	// bge 0x8229a444
	if (!cr0.lt) goto loc_8229A444;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r31,2080(r28)
	PPC_STORE_U32(r28.u32 + 2080, r31.u32);
	// stw r31,2084(r28)
	PPC_STORE_U32(r28.u32 + 2084, r31.u32);
	// addi r11,r28,2080
	r11.s64 = r28.s64 + 2080;
	// stw r31,2088(r28)
	PPC_STORE_U32(r28.u32 + 2088, r31.u32);
	// addi r10,r28,204
	ctx.r10.s64 = r28.s64 + 204;
	// stw r31,2092(r28)
	PPC_STORE_U32(r28.u32 + 2092, r31.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r31,2096(r28)
	PPC_STORE_U32(r28.u32 + 2096, r31.u32);
	// stw r31,2100(r28)
	PPC_STORE_U32(r28.u32 + 2100, r31.u32);
	// stb r9,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, ctx.r9.u8);
loc_8229A498:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r8,r10,-204
	ctx.r8.s64 = ctx.r10.s64 + -204;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a4c8
	if (cr6.eq) goto loc_8229A4C8;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a4d0
	if (!cr6.eq) goto loc_8229A4D0;
	// b 0x8229a4cc
	goto loc_8229A4CC;
loc_8229A4C8:
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_8229A4CC:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_8229A4D0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r9,r10,-100
	ctx.r9.s64 = ctx.r10.s64 + -100;
	// beq cr6,0x8229a508
	if (cr6.eq) goto loc_8229A508;
	// stw r9,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8229a510
	if (!cr6.eq) goto loc_8229A510;
	// b 0x8229a50c
	goto loc_8229A50C;
loc_8229A508:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8229A50C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A510:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// beq cr6,0x8229a548
	if (cr6.eq) goto loc_8229A548;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a550
	if (!cr6.eq) goto loc_8229A550;
	// b 0x8229a54c
	goto loc_8229A54C;
loc_8229A548:
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_8229A54C:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_8229A550:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r9,r10,108
	ctx.r9.s64 = ctx.r10.s64 + 108;
	// beq cr6,0x8229a588
	if (cr6.eq) goto loc_8229A588;
	// stw r9,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,208(r10)
	PPC_STORE_U32(ctx.r10.u32 + 208, ctx.r8.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8229a590
	if (!cr6.eq) goto loc_8229A590;
	// b 0x8229a58c
	goto loc_8229A58C;
loc_8229A588:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8229A58C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A590:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// beq cr6,0x8229a5cc
	if (cr6.eq) goto loc_8229A5CC;
	// addi r8,r10,212
	ctx.r8.s64 = ctx.r10.s64 + 212;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,312(r10)
	PPC_STORE_U32(ctx.r10.u32 + 312, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a5d8
	if (!cr6.eq) goto loc_8229A5D8;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8229a5d8
	goto loc_8229A5D8;
loc_8229A5CC:
	// addi r9,r10,212
	ctx.r9.s64 = ctx.r10.s64 + 212;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A5D8:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,520
	ctx.r10.s64 = ctx.r10.s64 + 520;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// bne 0x8229a498
	if (!cr0.eq) goto loc_8229A498;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229A428) {
	__imp__sub_8229A428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229A5FC) {
	__imp__sub_8229A5FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A600) {
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
	ctx.lr = 0x8229A608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8229a674
	if (cr6.lt) goto loc_8229A674;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8229A630;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a654
	if (!cr6.eq) goto loc_8229A654;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8229A648;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a674
	if (cr6.eq) goto loc_8229A674;
loc_8229A654:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8229a318
	ctx.lr = 0x8229A66C;
	sub_8229A318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229A674:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229A600) {
	__imp__sub_8229A600(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A680) {
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
	ctx.lr = 0x8229A688;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8229a6f4
	if (cr6.lt) goto loc_8229A6F4;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8229A6B0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a6d4
	if (!cr6.eq) goto loc_8229A6D4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8229A6C8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a6f4
	if (cr6.eq) goto loc_8229A6F4;
loc_8229A6D4:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8229a3a0
	ctx.lr = 0x8229A6EC;
	sub_8229A3A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229A6F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229A680) {
	__imp__sub_8229A680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A700) {
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
	ctx.lr = 0x8229A708;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r9,r10,16928
	ctx.r9.s64 = ctx.r10.s64 + 16928;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8229a788
	if (!cr6.eq) goto loc_8229A788;
	// li r11,0
	r11.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82299ed0
	ctx.lr = 0x8229A748;
	sub_82299ED0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a77c
	if (cr6.eq) goto loc_8229A77C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8229a600
	ctx.lr = 0x8229A77C;
	sub_8229A600(ctx, base);
loc_8229A77C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229A788:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16960
	ctx.r9.s64 = ctx.r10.s64 + 16960;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8229a818
	if (!cr6.eq) goto loc_8229A818;
	// li r11,0
	r11.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82299ed0
	ctx.lr = 0x8229A7B8;
	sub_82299ED0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a80c
	if (cr6.eq) goto loc_8229A80C;
	// bl 0x821c9788
	ctx.lr = 0x8229A7C8;
	sub_821C9788(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A7E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a80c
	if (cr6.eq) goto loc_8229A80C;
	// lwz r11,204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// stw r10,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r10.u32);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229A80C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229A80C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229A818:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8229A700) {
	__imp__sub_8229A700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229A824) {
	__imp__sub_8229A824(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A828) {
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
	// bl 0x821c9788
	ctx.lr = 0x8229A844;
	sub_821C9788(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8229a680
	ctx.lr = 0x8229A86C;
	sub_8229A680(ctx, base);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
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

PPC_WEAK_FUNC(sub_8229A828) {
	__imp__sub_8229A828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229A888) {
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
	ctx.lr = 0x8229A890;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,2100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// lwz r31,2092(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 2092);
	// addi r30,r28,2092
	r30.s64 = r28.s64 + 2092;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// addi r29,r27,176
	r29.s64 = r27.s64 + 176;
loc_8229A8BC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824f92f8
	ctx.lr = 0x8229A8C8;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a8ec
	if (cr6.eq) goto loc_8229A8EC;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e6358
	ctx.lr = 0x8229A8E0;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229aa68
	if (!cr6.eq) goto loc_8229AA68;
loc_8229A8EC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a8fc
	if (cr6.eq) goto loc_8229A8FC;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a930
	goto loc_8229A930;
loc_8229A8FC:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a918
	if (cr6.eq) goto loc_8229A918;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a91c
	if (!cr6.eq) goto loc_8229A91C;
loc_8229A918:
	// li r11,0
	r11.s64 = 0;
loc_8229A91C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8229A930:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a8bc
	if (!cr6.eq) goto loc_8229A8BC;
loc_8229A938:
	// addi r30,r27,176
	r30.s64 = r27.s64 + 176;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8229a248
	ctx.lr = 0x8229A948;
	sub_8229A248(ctx, base);
	// lwz r11,2088(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2088);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229aa68
	if (cr6.eq) goto loc_8229AA68;
	// lwz r4,2080(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 2080);
	// addi r3,r28,2080
	ctx.r3.s64 = r28.s64 + 2080;
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229a96c
	if (cr6.eq) goto loc_8229A96C;
	// bl 0x82273ae0
	ctx.lr = 0x8229A96C;
	sub_82273AE0(ctx, base);
loc_8229A96C:
	// lwz r10,192(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 192);
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r8,15
	ctx.r8.s64 = 15;
loc_8229A978:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229aa08
	if (cr6.eq) goto loc_8229AA08;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9ec
	if (cr6.eq) goto loc_8229A9EC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9f4
	if (cr6.eq) goto loc_8229A9F4;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9fc
	if (cr6.eq) goto loc_8229A9FC;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229aa04
	if (cr6.eq) goto loc_8229AA04;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addic. r8,r8,-5
	xer.ca = ctx.r8.u32 > 4;
	ctx.r8.s64 = ctx.r8.s64 + -5;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// bgt 0x8229a978
	if (cr0.gt) goto loc_8229A978;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9EC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9F4:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9FC:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229AA04:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8229AA08:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x8229AA20;
	sub_823DA950(ctx, base);
	// ld r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// addi r4,r28,2092
	ctx.r4.s64 = r28.s64 + 2092;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r9,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r9.u64);
	// ld r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// std r8,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r8.u64);
	// bl 0x822996f0
	ctx.lr = 0x8229AA44;
	sub_822996F0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// stb r7,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, ctx.r7.u8);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,13
	ctx.r5.s64 = 13;
	// lwz r4,-10240(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x8229AA68;
	sub_822990D8(ctx, base);
loc_8229AA68:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229A888) {
	__imp__sub_8229A888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229AA80:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8229aa80
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229AA80;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AA70) {
	__imp__sub_8229AA70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AA90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// bne cr6,0x8229aaac
	if (!cr6.eq) goto loc_8229AAAC;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x8229aad4
	goto loc_8229AAD4;
loc_8229AAAC:
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
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lfs f12,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
loc_8229AAD4:
	// lhz r11,2(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229aae8
	if (!cr6.eq) goto loc_8229AAE8;
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
	// b 0x8229ab10
	goto loc_8229AB10;
loc_8229AAE8:
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
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
loc_8229AB10:
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ab44
	if (cr6.eq) goto loc_8229AB44;
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
	// stw r4,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r4.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
loc_8229AB44:
	// stfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AA90) {
	__imp__sub_8229AA90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AB54) {
	__imp__sub_8229AB54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-12(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// fabs f13,f10
	ctx.f13.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fabs f0,f11
	f0.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229ab90
	if (!cr6.gt) goto loc_8229AB90;
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f9,f11
	ctx.f9.f64 = ctx.f11.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229AB90:
	// lfs f12,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fabs f0,f12
	f0.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229abac
	if (!cr6.gt) goto loc_8229ABAC;
	// li r9,2
	ctx.r9.s64 = 2;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229ABAC:
	// lfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	f0.f64 = double(temp.f32);
	// fabs f8,f0
	ctx.f8.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// ble cr6,0x8229abc8
	if (!cr6.gt) goto loc_8229ABC8;
	// li r9,3
	ctx.r9.s64 = 3;
	// fmr f9,f0
	ctx.f9.f64 = f0.f64;
	// fmr f13,f8
	ctx.f13.f64 = ctx.f8.f64;
loc_8229ABC8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f8,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f9,f8
	cr6.compare(ctx.f9.f64, ctx.f8.f64);
	// bgt cr6,0x8229abe0
	if (cr6.gt) goto loc_8229ABE0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8229ABE0:
	// fcmpu cr6,f13,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8229abf0
	if (cr6.gt) goto loc_8229ABF0;
	// li r11,0
	r11.s64 = 0;
loc_8229ABF0:
	// xor r11,r11,r10
	r11.u64 = r11.u64 ^ ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8229ac0c
	if (cr6.eq) goto loc_8229AC0C;
	// fneg f10,f10
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_8229AC0C:
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x8229ac4c
	if (cr6.gt) {
		sub_8229AC4C(ctx, base);
		return;
	}
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-21460
	r12.s64 = r12.s64 + -21460;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8229AB58) {
	__imp__sub_8229AB58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AC2C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	PPCRegister f0{};
	// lwz r17,-21444(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21444);
	// lwz r17,-21440(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21440);
	// lwz r17,-21436(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21436);
	// lwz r17,-21416(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21416);
	// fmr f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f11.f64;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x8229ac58
	// ERROR 8229AC58
	return;
}

PPC_WEAK_FUNC(sub_8229AC2C) {
	__imp__sub_8229AC2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AC4C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f12,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f0,-3064(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3064);
	f0.f64 = double(temp.f32);
	// fsubs f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f13,32232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32232);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f9,18056(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 18056);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f8,296(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 296);
	ctx.f8.f64 = double(temp.f32);
	// fsel f4,f7,f10,f0
	ctx.f4.f64 = ctx.f7.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsel f3,f6,f12,f0
	ctx.f3.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsel f1,f6,f12,f0
	ctx.f1.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsel f2,f7,f10,f0
	ctx.f2.f64 = ctx.f7.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsel f12,f5,f11,f0
	ctx.f12.f64 = ctx.f5.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsel f11,f5,f11,f0
	ctx.f11.f64 = ctx.f5.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsubs f10,f4,f13
	ctx.f10.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsubs f7,f3,f13
	ctx.f7.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fsubs f6,f12,f13
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f5,f10,f13,f2
	ctx.f5.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f2.f64;
	// fsel f4,f7,f13,f1
	ctx.f4.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f1.f64;
	// fsel f3,f6,f13,f11
	ctx.f3.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// fsubs f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsubs f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 - f0.f64));
	// fsubs f0,f3,f0
	f0.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fmadds f12,f2,f13,f9
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f11,f1,f13,f9
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f10,f0,f13,f9
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmuls f9,f12,f8
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmuls f6,f10,f8
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f8.f64));
	// fctidz f5,f9
	ctx.f5.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f5.u64);
	// lwz r6,-12(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f4,f7
	ctx.f4.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f4.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// or r3,r5,r9
	ctx.r3.u64 = ctx.r5.u64 | ctx.r9.u64;
	// fctidz f3,f6
	ctx.f3.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f3.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// rlwinm r8,r9,12,0,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFFF000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// rlwinm r6,r11,22,0,9
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0xFFC00000;
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AC4C) {
	__imp__sub_8229AC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AD2C) {
	__imp__sub_8229AD2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// rlwinm r8,r11,20,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3FF;
	// rlwinm r7,r11,10,22,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x3FF;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f11,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r6,r11,30,22,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FF;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfs f0,300(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 300);
	f0.f64 = double(temp.f32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// fcfid f5,f10
	ctx.f5.f64 = double(ctx.f10.s64);
	// lfs f13,12512(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12512);
	ctx.f13.f64 = double(temp.f32);
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// lfs f12,32232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32232);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lfs f9,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fmuls f1,f3,f0
	ctx.f1.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fmsubs f11,f4,f13,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fmsubs f0,f1,f13,f12
	f0.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmuls f7,f11,f11
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// fmadds f6,f0,f0,f7
	ctx.f6.f64 = double(float(f0.f64 * f0.f64 + ctx.f7.f64));
	// fmsubs f0,f8,f13,f12
	f0.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmadds f5,f0,f0,f6
	ctx.f5.f64 = double(float(f0.f64 * f0.f64 + ctx.f6.f64));
	// fsubs f4,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fsqrts f13,f4
	ctx.f13.f64 = double(float(sqrt(ctx.f4.f64)));
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-21020
	r12.s64 = r12.s64 + -21020;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8229AD30) {
	__imp__sub_8229AD30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229ADE4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r17,-21004(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21004);
	// lwz r17,-20984(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20984);
	// lwz r17,-20964(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20964);
	// lwz r17,-20944(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20944);
	// stfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f11,4(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229ADE4) {
	__imp__sub_8229ADE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// stfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AE08) {
	__imp__sub_8229AE08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE1C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// stfs f13,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f10,4(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AE1C) {
	__imp__sub_8229AE1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// stfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f10,4(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AE30) {
	__imp__sub_8229AE30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AE44) {
	__imp__sub_8229AE44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229aa90
	ctx.lr = 0x8229AE68;
	sub_8229AA90(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

PPC_WEAK_FUNC(sub_8229AE48) {
	__imp__sub_8229AE48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AE84) {
	__imp__sub_8229AE84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AE88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,22
	ctx.r4.s64 = ctx.r3.s64 + 22;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229aa90
	ctx.lr = 0x8229AEA8;
	sub_8229AA90(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

PPC_WEAK_FUNC(sub_8229AE88) {
	__imp__sub_8229AE88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AEC4) {
	__imp__sub_8229AEC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// stb r11,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r11.u8);
	// stb r11,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r11.u8);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AEC8) {
	__imp__sub_8229AEC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AF08) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// li r9,8
	ctx.r9.s64 = 8;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// stb r11,3(r31)
	PPC_STORE_U8(r31.u32 + 3, r11.u8);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// stb r11,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r11.u8);
	// stb r11,7(r31)
	PPC_STORE_U8(r31.u32 + 7, r11.u8);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// stb r11,11(r31)
	PPC_STORE_U8(r31.u32 + 11, r11.u8);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// stb r11,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r11.u8);
	// stb r11,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r11.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229AF64:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8229af64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229AF64;
	// li r5,52
	ctx.r5.s64 = 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8229AF80;
	sub_823D9890(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r10,r11,27
	ctx.r10.u64 = r11.u32 & 0x1F;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229AF08) {
	__imp__sub_8229AF08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229AFA4) {
	__imp__sub_8229AFA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229AFA8) {
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
	ctx.lr = 0x8229AFB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x82618f70
	ctx.lr = 0x8229AFD0;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x82618f70
	ctx.lr = 0x8229AFEC;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,26,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// bl 0x82618f70
	ctx.lr = 0x8229B008;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b070
	if (cr6.eq) goto loc_8229B070;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B034;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b060
	if (cr6.eq) goto loc_8229B060;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B050;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b064
	if (!cr6.eq) goto loc_8229B064;
loc_8229B060:
	// li r11,0
	r11.s64 = 0;
loc_8229B064:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8229B070:
	// rlwinm r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b09c
	if (cr6.eq) goto loc_8229B09C;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B08C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b0a0
	if (cr6.eq) goto loc_8229B0A0;
loc_8229B09C:
	// li r11,1
	r11.s64 = 1;
loc_8229B0A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229b0f0
	if (cr6.eq) goto loc_8229B0F0;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0dc
	if (cr6.eq) goto loc_8229B0DC;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B0CC;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b0e0
	if (cr6.eq) goto loc_8229B0E0;
loc_8229B0DC:
	// li r11,1
	r11.s64 = 1;
loc_8229B0E0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8229B0EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8229B0F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8229AFA8) {
	__imp__sub_8229AFA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B0F8) {
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
	ctx.lr = 0x8229B100;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x82618f10
	ctx.lr = 0x8229B11C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f10
	ctx.lr = 0x8229B134;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f10
	ctx.lr = 0x8229B14C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwimi r10,r11,2,22,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 2) & 0x3FC) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFC03);
	// lbz r6,82(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// clrlwi r7,r10,22
	ctx.r7.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r7,r7,0,31,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwimi r9,r7,5,0,26
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 5) & 0xFFFFFFE0) | (ctx.r9.u64 & 0xFFFFFFFF0000001F);
	// rlwimi r9,r6,6,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r4,r5,0,26,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// stb r5,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r5.u8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229b1dc
	if (cr6.eq) goto loc_8229B1DC;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1A0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b1cc
	if (cr6.eq) goto loc_8229B1CC;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1BC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b1d0
	if (!cr6.eq) goto loc_8229B1D0;
loc_8229B1CC:
	// li r11,0
	r11.s64 = 0;
loc_8229B1D0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229B1DC:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b20c
	if (cr6.eq) goto loc_8229B20C;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1FC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b210
	if (cr6.eq) goto loc_8229B210;
loc_8229B20C:
	// li r11,1
	r11.s64 = 1;
loc_8229B210:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229b260
	if (cr6.eq) goto loc_8229B260;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b24c
	if (cr6.eq) goto loc_8229B24C;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B23C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b250
	if (cr6.eq) goto loc_8229B250;
loc_8229B24C:
	// li r11,1
	r11.s64 = 1;
loc_8229B250:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229B25C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8229B260:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8229B0F8) {
	__imp__sub_8229B0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B268) {
	PPC_FUNC_PROLOGUE();
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229ab58
	ctx.lr = 0x8229B290;
	sub_8229AB58(ctx, base);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f12,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
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

PPC_WEAK_FUNC(sub_8229B268) {
	__imp__sub_8229B268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B2C0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229ad30
	ctx.lr = 0x8229B2E4;
	sub_8229AD30(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f8,12(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

PPC_WEAK_FUNC(sub_8229B2C0) {
	__imp__sub_8229B2C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8229B350;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8261da20
	ctx.lr = 0x8229B374;
	sub_8261DA20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229ab58
	ctx.lr = 0x8229B380;
	sub_8229AB58(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x8229B3B0;
	sub_8213E850(ctx, base);
	// addi r3,r30,2
	ctx.r3.s64 = r30.s64 + 2;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3BC;
	sub_8213E850(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3C8;
	sub_8213E850(ctx, base);
	// addi r30,r31,22
	r30.s64 = r31.s64 + 22;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f31,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x8229B3E0;
	sub_8213E850(ctx, base);
	// addi r3,r30,2
	ctx.r3.s64 = r30.s64 + 2;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3EC;
	sub_8213E850(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3F8;
	sub_8213E850(ctx, base);
	// stb r27,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r27.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229B348) {
	__imp__sub_8229B348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B40C) {
	__imp__sub_8229B40C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B410) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b2c0
	ctx.lr = 0x8229B430;
	sub_8229B2C0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8261d9d0
	ctx.lr = 0x8229B438;
	sub_8261D9D0(ctx, base);
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

PPC_WEAK_FUNC(sub_8229B410) {
	__imp__sub_8229B410(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B44C) {
	__imp__sub_8229B44C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8256(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8256);
	// li r11,0
	r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// clrlwi r8,r10,25
	ctx.r8.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,8252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8252, r11.u32);
	// stw r11,8260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8260, r11.u32);
	// stb r8,8256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8256, ctx.r8.u8);
	// stw r9,8272(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8272, ctx.r9.u32);
	// stw r11,8264(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8264, r11.u32);
	// stw r11,8268(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8268, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229B450) {
	__imp__sub_8229B450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B47C) {
	__imp__sub_8229B47C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B480) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618750
	ctx.lr = 0x8229B4A4;
	sub_82618750(ctx, base);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B4B4;
	sub_82618640(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238fd38
	ctx.lr = 0x8229B4C0;
	sub_8238FD38(ctx, base);
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r10.u8);
	// bl 0x826186a0
	ctx.lr = 0x8229B4D4;
	sub_826186A0(ctx, base);
	// stw r3,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_8229B480) {
	__imp__sub_8229B480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B4F0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b54c
	if (cr6.eq) goto loc_8229B54C;
	// lwz r11,8252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8229b54c
	if (!cr6.gt) goto loc_8229B54C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B530;
	sub_82618750(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,8252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// bl 0x826185e0
	ctx.lr = 0x8229B540;
	sub_826185E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82390940
	ctx.lr = 0x8229B54C;
	sub_82390940(ctx, base);
loc_8229B54C:
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

PPC_WEAK_FUNC(sub_8229B4F0) {
	__imp__sub_8229B4F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B564) {
	__imp__sub_8229B564(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B568) {
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
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// bl 0x82500cf8
	ctx.lr = 0x8229B584;
	sub_82500CF8(ctx, base);
	// lbz r9,8256(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, r11.u32);
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, ctx.r10.u32);
	// stw r11,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, r11.u32);
	// stw r11,8268(r31)
	PPC_STORE_U32(r31.u32 + 8268, r11.u32);
	// stb r8,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r8.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229B568) {
	__imp__sub_8229B568(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B5C4) {
	__imp__sub_8229B5C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B5C8) {
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
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8229b6a0
	if (!cr6.eq) goto loc_8229B6A0;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b624
	if (cr6.eq) goto loc_8229B624;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r7,8252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// lwz r5,8272(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8272);
	// bl 0x82500df8
	ctx.lr = 0x8229B60C;
	sub_82500DF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r8.u32);
	// b 0x8229b6a0
	goto loc_8229B6A0;
loc_8229B624:
	// bl 0x821c9788
	ctx.lr = 0x8229B628;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821ce460
	ctx.lr = 0x8229B638;
	sub_821CE460(ctx, base);
	// lis r11,23772
	r11.s64 = 1557921792;
	// lis r10,-32116
	ctx.r10.s64 = -2104754176;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r9,r11,64167
	ctx.r9.u64 = r11.u64 | 64167;
	// ori r8,r10,49087
	ctx.r8.u64 = ctx.r10.u64 | 49087;
	// mulld r10,r5,r9
	ctx.r10.s64 = ctx.r5.s64 * ctx.r9.s64;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r10,r11,1
	ctx.r10.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rldicl r3,r11,32,32
	ctx.r3.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulhw r11,r10,r8
	r11.s64 = (int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// srawi r11,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	r11.s64 = r11.s32 >> 7;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// mulli r8,r9,251
	ctx.r8.s64 = ctx.r9.s64 * 251;
	// subf r11,r8,r10
	r11.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r30,r11,250
	r30.s64 = r11.s64 + 250;
	// bl 0x821c9788
	ctx.lr = 0x8229B690;
	sub_821C9788(ctx, base);
	// add r7,r3,r30
	ctx.r7.u64 = ctx.r3.u64 + r30.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r7,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, ctx.r7.u32);
	// stw r6,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r6.u32);
loc_8229B6A0:
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

PPC_WEAK_FUNC(sub_8229B5C8) {
	__imp__sub_8229B5C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B6B8) {
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
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B6DC;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b704
	if (cr6.eq) goto loc_8229B704;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x8229B6F4;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b708
	if (!cr6.eq) goto loc_8229B708;
loc_8229B704:
	// li r11,0
	r11.s64 = 0;
loc_8229B708:
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

PPC_WEAK_FUNC(sub_8229B6B8) {
	__imp__sub_8229B6B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B724) {
	__imp__sub_8229B724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B728) {
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
	ctx.lr = 0x8229B730;
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
	ctx.lr = 0x8229B754;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B760;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B770;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229b794
	if (cr6.eq) goto loc_8229B794;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b6b8
	ctx.lr = 0x8229B784;
	sub_8229B6B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229b798
	if (!cr6.eq) goto loc_8229B798;
loc_8229B794:
	// li r30,0
	r30.s64 = 0;
loc_8229B798:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229b7d0
	if (cr6.eq) goto loc_8229B7D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b7c8
	if (cr6.eq) goto loc_8229B7C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8229B7B4;
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
loc_8229B7C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8229B7D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229B728) {
	__imp__sub_8229B728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B7DC) {
	__imp__sub_8229B7DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B7E0) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8226b338
	ctx.lr = 0x8229B808;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b850
	if (cr6.eq) goto loc_8229B850;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B824;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b850
	if (cr6.eq) goto loc_8229B850;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B840;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b854
	if (!cr6.eq) goto loc_8229B854;
loc_8229B850:
	// li r11,0
	r11.s64 = 0;
loc_8229B854:
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

PPC_WEAK_FUNC(sub_8229B7E0) {
	__imp__sub_8229B7E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B870) {
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
	ctx.lr = 0x8229B878;
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
	ctx.lr = 0x8229B89C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B8A8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B8B8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229b8dc
	if (cr6.eq) goto loc_8229B8DC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b7e0
	ctx.lr = 0x8229B8CC;
	sub_8229B7E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229b8e0
	if (!cr6.eq) goto loc_8229B8E0;
loc_8229B8DC:
	// li r30,0
	r30.s64 = 0;
loc_8229B8E0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229b918
	if (cr6.eq) goto loc_8229B918;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b910
	if (cr6.eq) goto loc_8229B910;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8229B8FC;
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
loc_8229B910:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8229B918:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229B870) {
	__imp__sub_8229B870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B924) {
	__imp__sub_8229B924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B928) {
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
	ctx.lr = 0x8229B930;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16088
	ctx.r10.s64 = r11.s64 + 16088;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8229b728
	ctx.lr = 0x8229B964;
	sub_8229B728(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229b99c
	if (cr6.eq) goto loc_8229B99C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8229B98C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b9a0
	if (!cr6.eq) goto loc_8229B9A0;
loc_8229B99C:
	// li r11,0
	r11.s64 = 0;
loc_8229B9A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229B928) {
	__imp__sub_8229B928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229B9AC) {
	__imp__sub_8229B9AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229B9B0) {
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
	ctx.lr = 0x8229B9B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229b928
	ctx.lr = 0x8229B9F8;
	sub_8229B928(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229ba48
	if (cr6.eq) goto loc_8229BA48;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// bl 0x82500a20
	ctx.lr = 0x8229BA20;
	sub_82500A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ba48
	if (cr6.eq) goto loc_8229BA48;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r27,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, r27.u32);
	// clrlwi r9,r11,25
	ctx.r9.u64 = r11.u32 & 0x7F;
	// stw r30,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, r30.u32);
	// stw r10,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r10.u32);
	// stb r9,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r9.u8);
loc_8229BA48:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8229B9B0) {
	__imp__sub_8229B9B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BA60) {
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
	// li r11,0
	r11.s64 = 0;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r11,8260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8260, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8229b928
	ctx.lr = 0x8229BA94;
	sub_8229B928(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229BA60) {
	__imp__sub_8229BA60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229BAA4) {
	__imp__sub_8229BAA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BAA8) {
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
	ctx.lr = 0x8229BAB0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,15992
	ctx.r10.s64 = r11.s64 + 15992;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8229b870
	ctx.lr = 0x8229BAE4;
	sub_8229B870(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229bb1c
	if (cr6.eq) goto loc_8229BB1C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edfe8
	ctx.lr = 0x8229BB0C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229bb20
	if (!cr6.eq) goto loc_8229BB20;
loc_8229BB1C:
	// li r11,0
	r11.s64 = 0;
loc_8229BB20:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229BAA8) {
	__imp__sub_8229BAA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229BB2C) {
	__imp__sub_8229BB2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BB30) {
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
	ctx.lr = 0x8229BB38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// stw r30,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, r30.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r28,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r28.u32);
	// bl 0x825009a8
	ctx.lr = 0x8229BB60;
	sub_825009A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bbac
	if (cr6.eq) goto loc_8229BBAC;
	// lwz r11,8252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x8229baa8
	ctx.lr = 0x8229BB98;
	sub_8229BAA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229bbac
	if (cr6.eq) goto loc_8229BBAC;
	// li r11,3
	r11.s64 = 3;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
loc_8229BBAC:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229BB30) {
	__imp__sub_8229BB30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229BBC4) {
	__imp__sub_8229BBC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BBC8) {
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
	ctx.lr = 0x8229BBD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8229bc30
	if (!cr6.eq) goto loc_8229BC30;
	// addi r30,r31,8192
	r30.s64 = r31.s64 + 8192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500848
	ctx.lr = 0x8229BBF4;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// bl 0x82500830
	ctx.lr = 0x8229BC10;
	sub_82500830(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8229BC30:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8229bc50
	if (cr6.eq) goto loc_8229BC50;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8229bc50
	if (cr6.eq) goto loc_8229BC50;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x8229bc54
	if (!cr6.eq) goto loc_8229BC54;
loc_8229BC50:
	// li r11,1
	r11.s64 = 1;
loc_8229BC54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// addi r30,r31,8192
	r30.s64 = r31.s64 + 8192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500848
	ctx.lr = 0x8229BC6C;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bc8c
	if (cr6.eq) goto loc_8229BC8C;
	// stw r29,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500830
	ctx.lr = 0x8229BC84;
	sub_82500830(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8229BC8C:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8229bcc8
	if (!cr6.eq) goto loc_8229BCC8;
	// bl 0x821c9788
	ctx.lr = 0x8229BC9C;
	sub_821C9788(ctx, base);
	// lwz r11,8264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8264);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bgt cr6,0x8229bcc8
	if (cr6.gt) goto loc_8229BCC8;
	// lwz r11,8268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8268);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r29,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r4,8272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8272);
	// stw r11,8268(r31)
	PPC_STORE_U32(r31.u32 + 8268, r11.u32);
	// bl 0x8229bb30
	ctx.lr = 0x8229BCC8;
	sub_8229BB30(ctx, base);
loc_8229BCC8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8229BBC8) {
	__imp__sub_8229BBC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BCD0) {
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
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a810
	ctx.lr = 0x8229BCEC;
	sub_8266A810(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229bd10
	if (!cr6.eq) goto loc_8229BD10;
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a810
	ctx.lr = 0x8229BD00;
	sub_8266A810(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229bd14
	if (cr6.eq) goto loc_8229BD14;
loc_8229BD10:
	// li r11,1
	r11.s64 = 1;
loc_8229BD14:
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

PPC_WEAK_FUNC(sub_8229BCD0) {
	__imp__sub_8229BCD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229BD2C) {
	__imp__sub_8229BD2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BD30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,717(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 717);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229bd4c
	if (!cr6.eq) goto loc_8229BD4C;
	// lbz r11,793(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 793);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229bd50
	if (cr6.eq) goto loc_8229BD50;
loc_8229BD4C:
	// li r11,1
	r11.s64 = 1;
loc_8229BD50:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229BD30) {
	__imp__sub_8229BD30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BD58) {
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
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a848
	ctx.lr = 0x8229BD74;
	sub_8266A848(ctx, base);
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a848
	ctx.lr = 0x8229BD7C;
	sub_8266A848(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229BD58) {
	__imp__sub_8229BD58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BD90) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,292
	ctx.r9.s64 = r11.s64 + 292;
	// addi r8,r10,564
	ctx.r8.s64 = ctx.r10.s64 + 564;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// bl 0x8229d380
	ctx.lr = 0x8229BDC8;
	sub_8229D380(ctx, base);
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a748
	ctx.lr = 0x8229BDD0;
	sub_8266A748(ctx, base);
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a748
	ctx.lr = 0x8229BDD8;
	sub_8266A748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// stb r11,796(r31)
	PPC_STORE_U8(r31.u32 + 796, r11.u8);
	// stb r11,797(r31)
	PPC_STORE_U8(r31.u32 + 797, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8229BD90) {
	__imp__sub_8229BD90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229BE04) {
	__imp__sub_8229BE04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BE08) {
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
	ctx.lr = 0x8229BE10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x82388580
	ctx.lr = 0x8229BE24;
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
	ctx.lr = 0x8229BE38;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,208(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// bl 0x82388580
	ctx.lr = 0x8229BE48;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229BE58;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r30,0
	r30.s64 = 0;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
	// addi r25,r11,144
	r25.s64 = r11.s64 + 144;
loc_8229BE6C:
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229be9c
	if (cr6.eq) goto loc_8229BE9C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BE84;
	sub_822577D0(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BE90;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229be9c
	if (cr6.eq) goto loc_8229BE9C;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_8229BE9C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8229be6c
	if (!cr0.eq) goto loc_8229BE6C;
	// cmpw cr6,r27,r30
	cr6.compare<int32_t>(r27.s32, r30.s32, xer);
	// ble cr6,0x8229beb4
	if (!cr6.gt) goto loc_8229BEB4;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_8229BEB4:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// subf r30,r27,r30
	r30.s64 = r30.s64 - r27.s64;
	// addi r31,r11,17088
	r31.s64 = r11.s64 + 17088;
	// lwz r11,17108(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17108);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229bf18
	if (!cr6.eq) goto loc_8229BF18;
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
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,17108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17108, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r10,-26264
	ctx.r3.s64 = ctx.r10.s64 + -26264;
	// bl 0x823d9a98
	ctx.lr = 0x8229BF18;
	sub_823D9A98(ctx, base);
loc_8229BF18:
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BF24;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8229bf60
	if (!cr6.eq) goto loc_8229BF60;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x8229BF3C;
	sub_822A3DE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229bf88
	if (cr6.eq) goto loc_8229BF88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8229BF54;
	sub_822B62A0(ctx, base);
	// addi r7,r31,16
	ctx.r7.s64 = r31.s64 + 16;
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// b 0x8229bf78
	goto loc_8229BF78;
loc_8229BF60:
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bl 0x822577d0
	ctx.lr = 0x8229BF70;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_8229BF78:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r26,16
	ctx.r4.s64 = r26.s64 + 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82481750
	ctx.lr = 0x8229BF88;
	sub_82481750(ctx, base);
loc_8229BF88:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8229BE08) {
	__imp__sub_8229BE08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229BF90) {
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
	ctx.lr = 0x8229BF98;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229BFA8;
	sub_82388580(ctx, base);
	// lis r18,-32121
	r18.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8229BFB8;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,144
	ctx.r9.s64 = r11.s64 + 144;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8229BFD0;
	sub_8238EC00(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,-10240(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// li r31,0
	r31.s64 = 0;
	// addi r14,r10,-2628
	r14.s64 = ctx.r10.s64 + -2628;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// stw r14,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r14.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// bl 0x822701c8
	ctx.lr = 0x8229C000;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x8229C008;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82389668
	ctx.lr = 0x8229C018;
	sub_82389668(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8229c458
	if (cr6.eq) goto loc_8229C458;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,18692
	ctx.r4.s64 = ctx.r10.s64 + 18692;
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
	ctx.lr = 0x8229C04C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C054;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C064;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r28,4096
	r28.s64 = 268435456;
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// lis r24,4096
	r24.s64 = 268435456;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,4096
	r29.s64 = 268435456;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r7,18684
	ctx.r7.s64 = ctx.r7.s64 + 18684;
	// addi r6,r6,18676
	ctx.r6.s64 = ctx.r6.s64 + 18676;
	// addi r5,r5,18668
	ctx.r5.s64 = ctx.r5.s64 + 18668;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// ori r27,r28,39
	r27.u64 = r28.u64 | 39;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// ori r28,r24,40
	r28.u64 = r24.u64 | 40;
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// mr r15,r31
	r15.u64 = r31.u64;
	// li r21,4
	r21.s64 = 4;
	// ori r25,r3,44
	r25.u64 = ctx.r3.u64 | 44;
	// ori r26,r29,36
	r26.u64 = r29.u64 | 36;
	// li r24,1
	r24.s64 = 1;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// addi r17,r11,-28
	r17.s64 = r11.s64 + -28;
	// addi r23,r10,484
	r23.s64 = ctx.r10.s64 + 484;
	// addi r16,r9,68
	r16.s64 = ctx.r9.s64 + 68;
	// addi r22,r8,820
	r22.s64 = ctx.r8.s64 + 820;
loc_8229C0E4:
	// lwz r29,0(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229c444
	if (cr6.eq) goto loc_8229C444;
	// add r11,r30,r20
	r11.u64 = r30.u64 + r20.u64;
	// lbz r10,708(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 708);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8229c444
	if (!cr6.eq) goto loc_8229C444;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C10C;
	sub_822051A0(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8229C118;
	sub_822A3998(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8229be08
	ctx.lr = 0x8229C140;
	sub_8229BE08(ctx, base);
	// lbz r7,648(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 648);
	// lbz r6,1176(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1176);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// ori r5,r7,128
	ctx.r5.u64 = ctx.r7.u64 | 128;
	// std r31,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, r31.u64);
	// ori r11,r6,128
	r11.u64 = ctx.r6.u64 | 128;
	// stw r23,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r23.u32);
	// stw r21,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r21.u32);
	// stw r25,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r25.u32);
	// stw r26,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r26.u32);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r27.u32);
	// stw r28,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r28.u32);
	// stw r22,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r22.u32);
	// stw r23,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r23.u32);
	// stw r21,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r21.u32);
	// stw r25,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, r25.u32);
	// stw r26,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r26.u32);
	// stw r27,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r27.u32);
	// stw r28,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r28.u32);
	// stw r22,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r22.u32);
	// stb r5,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r5.u8);
	// stb r11,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, r11.u8);
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// std r31,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, r31.u64);
	// bl 0x822701c8
	ctx.lr = 0x8229C1A4;
	sub_822701C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82295e90
	ctx.lr = 0x8229C1AC;
	sub_82295E90(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8229c204
	if (cr6.gt) goto loc_8229C204;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-15920
	r12.s64 = r12.s64 + -15920;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-15900(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15900);
	// lwz r17,-15892(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15892);
	// lwz r17,-15876(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15876);
	// lwz r17,-15868(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15868);
	// lwz r17,-15884(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15884);
	// li r11,2
	r11.s64 = 2;
	// b 0x8229c200
	goto loc_8229C200;
	// li r11,5
	r11.s64 = 5;
	// b 0x8229c200
	goto loc_8229C200;
	// stw r21,20(r20)
	PPC_STORE_U32(r20.u32 + 20, r21.u32);
	// b 0x8229c204
	goto loc_8229C204;
	// li r11,3
	r11.s64 = 3;
loc_8229C200:
	// stw r11,20(r20)
	PPC_STORE_U32(r20.u32 + 20, r11.u32);
loc_8229C204:
	// addi r11,r20,8
	r11.s64 = r20.s64 + 8;
	// addi r10,r20,16
	ctx.r10.s64 = r20.s64 + 16;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r11,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, r11.u32);
	// ld r11,140(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// stw r10,1180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1180, ctx.r10.u32);
	// stw r9,12(r20)
	PPC_STORE_U32(r20.u32 + 12, ctx.r9.u32);
	// bne cr6,0x8229c290
	if (!cr6.eq) goto loc_8229C290;
	// std r24,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r24.u64);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C23C;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c26c
	if (cr6.eq) goto loc_8229C26C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C26C:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// std r24,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r24.u64);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3a4
	goto loc_8229C3A4;
loc_8229C290:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// std r31,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r31.u64);
	// bne cr6,0x8229c308
	if (!cr6.eq) goto loc_8229C308;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C2AC;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c2dc
	if (cr6.eq) goto loc_8229C2DC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C2DC:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// stw r24,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r24.u32);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// stw r24,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r24.u32);
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3ac
	goto loc_8229C3AC;
loc_8229C308:
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bne cr6,0x8229c384
	if (!cr6.eq) goto loc_8229C384;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C320;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c350
	if (cr6.eq) goto loc_8229C350;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C350:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// stw r24,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r24.u32);
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// stw r31,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r31.u32);
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// stw r24,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r24.u32);
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3b4
	goto loc_8229C3B4;
loc_8229C384:
	// ld r10,668(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// ori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 | 1;
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// ori r6,r8,4
	ctx.r6.u64 = ctx.r8.u64 | 4;
	// ori r11,r7,8
	r11.u64 = ctx.r7.u64 | 8;
	// ori r10,r6,8
	ctx.r10.u64 = ctx.r6.u64 | 8;
loc_8229C3A4:
	// stw r31,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r31.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
loc_8229C3AC:
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r31.u32);
	// stw r31,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r31.u32);
loc_8229C3B4:
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r24,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r24.u32);
	// stw r24,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, r24.u32);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// std r11,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, r11.u64);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r4,14
	ctx.r4.s64 = 14;
	// std r10,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, ctx.r10.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// bl 0x822577d0
	ctx.lr = 0x8229C3E4;
	sub_822577D0(ctx, base);
	// lwz r14,88(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C3FC;
	sub_824816E8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// addi r29,r1,656
	r29.s64 = ctx.r1.s64 + 656;
	// bl 0x822577d0
	ctx.lr = 0x8229C40C;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C420;
	sub_824816E8(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r9,1
	r30.s64 = ctx.r9.s64 + 1;
	// lwz r14,96(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r17,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r17.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r16,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r16.u32);
	// stw r17,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r17.u32);
	// stw r16,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r16.u32);
loc_8229C444:
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// cmpwi cr6,r15,31
	cr6.compare<int32_t>(r15.s32, 31, xer);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// blt cr6,0x8229c0e4
	if (cr6.lt) goto loc_8229C0E4;
loc_8229C458:
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_8229BF90) {
	__imp__sub_8229BF90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229C460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8229C468;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82388580
	ctx.lr = 0x8229C480;
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
	ctx.lr = 0x8229C494;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,208(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// addi r17,r11,144
	r17.s64 = r11.s64 + 144;
	// bl 0x82388580
	ctx.lr = 0x8229C4A8;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C4B8;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r22,1
	r22.s64 = 1;
	// li r19,0
	r19.s64 = 0;
	// cmpwi cr6,r18,10
	cr6.compare<int32_t>(r18.s32, 10, xer);
	// beq cr6,0x8229c4e0
	if (cr6.eq) goto loc_8229C4E0;
	// cmpwi cr6,r18,9
	cr6.compare<int32_t>(r18.s32, 9, xer);
	// beq cr6,0x8229c4e0
	if (cr6.eq) goto loc_8229C4E0;
	// cmpwi cr6,r18,12
	cr6.compare<int32_t>(r18.s32, 12, xer);
	// mr r11,r19
	r11.u64 = r19.u64;
	// bne cr6,0x8229c4e4
	if (!cr6.eq) goto loc_8229C4E4;
loc_8229C4E0:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8229C4E4:
	// clrlwi r15,r11,24
	r15.u64 = r11.u32 & 0xFF;
	// mr r16,r19
	r16.u64 = r19.u64;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8229c50c
	if (cr6.eq) goto loc_8229C50C;
	// lwz r11,3172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3172);
	// mr r16,r22
	r16.u64 = r22.u64;
	// lwz r9,3176(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3176);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8229c50c
	if (cr6.gt) goto loc_8229C50C;
	// li r16,2
	r16.s64 = 2;
loc_8229C50C:
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lbz r7,600(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 600);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r9,212
	ctx.r9.s64 = ctx.r9.s64 + 212;
	// addi r8,r8,784
	ctx.r8.s64 = ctx.r8.s64 + 784;
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ori r7,r7,128
	ctx.r7.u64 = ctx.r7.u64 | 128;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stb r7,600(r1)
	PPC_STORE_U8(ctx.r1.u32 + 600, ctx.r7.u8);
	// li r9,5
	ctx.r9.s64 = 5;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lis r30,4096
	r30.s64 = 268435456;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ori r8,r6,44
	ctx.r8.u64 = ctx.r6.u64 | 44;
	// ori r7,r5,36
	ctx.r7.u64 = ctx.r5.u64 | 36;
	// ori r6,r4,42
	ctx.r6.u64 = ctx.r4.u64 | 42;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// addi r11,r18,-8
	r11.s64 = r18.s64 + -8;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// ori r5,r3,41
	ctx.r5.u64 = ctx.r3.u64 | 41;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// ori r4,r30,43
	ctx.r4.u64 = r30.u64 | 43;
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// std r9,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r9.u64);
	// bgt cr6,0x8229c5e8
	if (cr6.gt) goto loc_8229C5E8;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-14944
	r12.s64 = r12.s64 + -14944;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-14920(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14920);
	// lwz r17,-14904(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14904);
	// lwz r17,-14912(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14912);
	// lwz r17,-14888(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14888);
	// lwz r17,-14896(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14896);
	// lwz r17,-14880(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14880);
	// li r11,7
	r11.s64 = 7;
	// b 0x8229c5e4
	goto loc_8229C5E4;
	// li r11,8
	r11.s64 = 8;
	// b 0x8229c5e4
	goto loc_8229C5E4;
	// li r11,9
	r11.s64 = 9;
	// b 0x8229c5e4
	goto loc_8229C5E4;
	// li r11,10
	r11.s64 = 10;
	// b 0x8229c5e4
	goto loc_8229C5E4;
	// li r11,11
	r11.s64 = 11;
	// b 0x8229c5e4
	goto loc_8229C5E4;
	// li r11,12
	r11.s64 = 12;
loc_8229C5E4:
	// stw r11,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r11.u32);
loc_8229C5E8:
	// addi r25,r31,196
	r25.s64 = r31.s64 + 196;
	// stw r23,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, r23.u32);
	// addi r24,r10,12
	r24.s64 = ctx.r10.s64 + 12;
	// mr r26,r25
	r26.u64 = r25.u64;
	// mr r21,r24
	r21.u64 = r24.u64;
	// li r20,31
	r20.s64 = 31;
loc_8229C600:
	// lwz r27,0(r21)
	r27.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8229c734
	if (cr6.eq) goto loc_8229C734;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8229c65c
	if (cr6.eq) goto loc_8229C65C;
	// lwz r11,-20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -20);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// ori r11,r9,1
	r11.u64 = ctx.r9.u64 | 1;
	// bne cr6,0x8229c644
	if (!cr6.eq) goto loc_8229C644;
	// std r22,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r22.u64);
	// li r5,1
	ctx.r5.s64 = 1;
	// std r11,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, r11.u64);
	// bl 0x8229be08
	ctx.lr = 0x8229C63C;
	sub_8229BE08(ctx, base);
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// b 0x8229c6dc
	goto loc_8229C6DC;
loc_8229C644:
	// std r19,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r19.u64);
	// li r5,2
	ctx.r5.s64 = 2;
	// std r11,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, r11.u64);
	// bl 0x8229be08
	ctx.lr = 0x8229C654;
	sub_8229BE08(ctx, base);
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// b 0x8229c6dc
	goto loc_8229C6DC;
loc_8229C65C:
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r31,r24
	r31.u64 = r24.u64;
	// li r29,31
	r29.s64 = 31;
loc_8229C66C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229c6b4
	if (cr6.eq) goto loc_8229C6B4;
	// cmpwi cr6,r18,13
	cr6.compare<int32_t>(r18.s32, 13, xer);
	// bne cr6,0x8229c6a0
	if (!cr6.eq) goto loc_8229C6A0;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822051a0
	ctx.lr = 0x8229C688;
	sub_822051A0(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C698;
	sub_822051A0(ctx, base);
	// cmpw cr6,r14,r3
	cr6.compare<int32_t>(r14.s32, ctx.r3.s32, xer);
	// b 0x8229c6ac
	goto loc_8229C6AC;
loc_8229C6A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
loc_8229C6AC:
	// ble cr6,0x8229c6b4
	if (!cr6.gt) goto loc_8229C6B4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8229C6B4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// bne 0x8229c66c
	if (!cr0.eq) goto loc_8229C66C;
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// std r22,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r22.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// beq cr6,0x8229c6dc
	if (cr6.eq) goto loc_8229C6DC;
	// std r19,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r19.u64);
loc_8229C6DC:
	// lwz r10,-8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -8);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// lwz r9,-16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + -16);
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r7,-4(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + -4);
	// ori r8,r11,8
	ctx.r8.u64 = r11.u64 | 8;
	// stw r22,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r22.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r6,r8,16
	ctx.r6.u64 = ctx.r8.u64 | 16;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// ori r5,r6,4
	ctx.r5.u64 = ctx.r6.u64 | 4;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// std r5,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r5.u64);
	// bl 0x822577d0
	ctx.lr = 0x8229C71C;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r27,16
	ctx.r4.s64 = r27.s64 + 16;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C730;
	sub_824816E8(ctx, base);
	// ld r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
loc_8229C734:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r26,r26,192
	r26.s64 = r26.s64 + 192;
	// bne 0x8229c600
	if (!cr0.eq) goto loc_8229C600;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_8229C460) {
	__imp__sub_8229C460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229C74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8229C74C) {
	__imp__sub_8229C74C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8229C750) {
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
	ctx.lr = 0x8229C758;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x82256058
	ctx.lr = 0x8229C768;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229c9cc
	if (cr6.eq) goto loc_8229C9CC;
	// bl 0x82256058
	ctx.lr = 0x8229C774;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8229c9cc
	if (cr0.eq) goto loc_8229C9CC;
	// bl 0x82256058
	ctx.lr = 0x8229C780;
	sub_82256058(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8229c9cc
	if (cr6.eq) goto loc_8229C9CC;
	// addi r29,r25,8
	r29.s64 = r25.s64 + 8;
	// li r30,0
	r30.s64 = 0;
	// li r28,8
	r28.s64 = 8;
	// li r26,12
	r26.s64 = 12;
	// li r27,-1
	r27.s64 = -1;
	// lis r24,-32121
	r24.s64 = -2105081856;
loc_8229C7A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C7AC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C7BC;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r26
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229c884
	if (cr6.eq) goto loc_8229C884;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229c85c
	if (cr6.eq) goto loc_8229C85C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229C7E0;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x8229c834
	if (cr6.eq) goto loc_8229C834;
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8229c804
	if (cr6.eq) goto loc_8229C804;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x822577d0
	ctx.lr = 0x8229C7FC;
	sub_822577D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8229c85c
	goto loc_8229C85C;
loc_8229C804:
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r30,3080(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// bl 0x822051a0
	ctx.lr = 0x8229C810;
	sub_822051A0(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8229C81C;
	sub_823EAEF8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263c28
	ctx.lr = 0x8229C82C;
	sub_82263C28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8229c85c
	goto loc_8229C85C;
loc_8229C834:
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// bl 0x822051a0
	ctx.lr = 0x8229C848;
	sub_822051A0(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r27,196(r10)
	PPC_STORE_U32(ctx.r10.u32 + 196, r27.u32);
loc_8229C85C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8229c884
	if (cr6.eq) goto loc_8229C884;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C870;
	sub_822051A0(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r30,172(r10)
	PPC_STORE_U32(ctx.r10.u32 + 172, r30.u32);
loc_8229C884:
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r26,136
	cr6.compare<int32_t>(r26.s32, 136, xer);
	// blt cr6,0x8229c7a4
	if (cr6.lt) goto loc_8229C7A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C898;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C8A8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8229C8B0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x8229C8B4;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229c940
	if (cr6.eq) goto loc_8229C940;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,444
	ctx.r3.s64 = r11.s64 + 444;
	// bl 0x821fa230
	ctx.lr = 0x8229C8CC;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229C8E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8229C8F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8229C910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r23,8
	cr6.compare<int32_t>(r23.s32, 8, xer);
	// blt cr6,0x8229c934
	if (cr6.lt) goto loc_8229C934;
	// cmpwi cr6,r23,13
	cr6.compare<int32_t>(r23.s32, 13, xer);
	// bgt cr6,0x8229c934
	if (cr6.gt) goto loc_8229C934;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8229c460
	ctx.lr = 0x8229C930;
	sub_8229C460(ctx, base);
	// b 0x8229c9a8
	goto loc_8229C9A8;
loc_8229C934:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8229bf90
	ctx.lr = 0x8229C93C;
	sub_8229BF90(ctx, base);
	// b 0x8229c9a8
	goto loc_8229C9A8;
loc_8229C940:
	// li r30,12
	r30.s64 = 12;
loc_8229C944:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C94C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C95C;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229c99c
	if (cr6.eq) goto loc_8229C99C;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C978;
	sub_822051A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// lwz r5,172(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// bl 0x8229be08
	ctx.lr = 0x8229C99C;
	sub_8229BE08(ctx, base);
loc_8229C99C:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,136
	cr6.compare<int32_t>(r30.s32, 136, xer);
	// blt cr6,0x8229c944
	if (cr6.lt) goto loc_8229C944;
loc_8229C9A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C9B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C9C0;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8229C9CC;
	sub_82274128(ctx, base);
loc_8229C9CC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8229C750) {
	__imp__sub_8229C750(ctx, base);
}

