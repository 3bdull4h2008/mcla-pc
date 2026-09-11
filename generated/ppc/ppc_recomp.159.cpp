#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_8274B9F8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8274BA00;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bab8
	if (cr6.eq) goto loc_8274BAB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,3592
	cr6.compare<uint32_t>(r11.u32, 3592, xer);
	// blt cr6,0x8274bab8
	if (cr6.lt) goto loc_8274BAB8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BA34;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8274bac4
	if (!cr0.eq) goto loc_8274BAC4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,300
	ctx.r10.s64 = 300;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// std r26,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r26.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// ori r4,r4,26
	ctx.r4.u64 = ctx.r4.u64 | 26;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BA7C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274ba8c
	if (!cr0.lt) goto loc_8274BA8C;
	// li r29,1627
	r29.s64 = 1627;
	// b 0x8274baac
	goto loc_8274BAAC;
loc_8274BA8C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8274baa8
	if (!cr6.eq) goto loc_8274BAA8;
	// bl 0x82135d90
	ctx.lr = 0x8274BA98;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r29,r11,1627
	r29.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// b 0x8274baac
	goto loc_8274BAAC;
loc_8274BAA8:
	// li r29,997
	r29.s64 = 997;
loc_8274BAAC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BAB4;
	__imp__ObDereferenceObject(ctx, base);
	// b 0x8274bac4
	goto loc_8274BAC4;
loc_8274BAB8:
	// li r11,3592
	r11.s64 = 3592;
	// li r29,122
	r29.s64 = 122;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8274BAC4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274B9F8) {
	__imp__sub_8274B9F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BAD0) {
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
	ctx.lr = 0x8274BAD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BAEC;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bb5c
	if (!cr0.eq) goto loc_8274BB5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// ori r4,r4,20
	ctx.r4.u64 = ctx.r4.u64 | 20;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BB24;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bb34
	if (!cr0.lt) goto loc_8274BB34;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bb54
	goto loc_8274BB54;
loc_8274BB34:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bb50
	if (!cr6.eq) goto loc_8274BB50;
	// bl 0x82135d90
	ctx.lr = 0x8274BB40;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bb54
	goto loc_8274BB54;
loc_8274BB50:
	// li r31,997
	r31.s64 = 997;
loc_8274BB54:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BB5C;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BB5C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274BAD0) {
	__imp__sub_8274BAD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BB68) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BB88;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bbf8
	if (!cr0.eq) goto loc_8274BBF8;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,21
	ctx.r4.u64 = ctx.r4.u64 | 21;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BBC0;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bbd0
	if (!cr0.lt) goto loc_8274BBD0;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bbf0
	goto loc_8274BBF0;
loc_8274BBD0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bbec
	if (!cr6.eq) goto loc_8274BBEC;
	// bl 0x82135d90
	ctx.lr = 0x8274BBDC;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bbf0
	goto loc_8274BBF0;
loc_8274BBEC:
	// li r31,997
	r31.s64 = 997;
loc_8274BBF0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BBF8;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BBF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_8274BB68) {
	__imp__sub_8274BB68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274BC14) {
	__imp__sub_8274BC14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BC18) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274BC20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,260(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mulli r11,r5,1326
	r11.s64 = ctx.r5.s64 * 1326;
	// addi r27,r11,8
	r27.s64 = r11.s64 + 8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8274bcec
	if (cr6.lt) goto loc_8274BCEC;
	// lwz r11,268(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274bcec
	if (cr6.eq) goto loc_8274BCEC;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// li r7,36
	ctx.r7.s64 = 36;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// ori r4,r4,28
	ctx.r4.u64 = ctx.r4.u64 | 28;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// sth r29,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r29.u16);
	// sth r8,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, ctx.r8.u16);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r28,276(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BCA8;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bcc8
	if (!cr0.lt) goto loc_8274BCC8;
	// lis r11,-32747
	r11.s64 = -2146107392;
	// ori r11,r11,20999
	r11.u64 = r11.u64 | 20999;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// beq cr6,0x8274bcec
	if (cr6.eq) goto loc_8274BCEC;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCC8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8274bce4
	if (!cr6.eq) goto loc_8274BCE4;
	// bl 0x82135d90
	ctx.lr = 0x8274BCD4;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r3,r11,1627
	ctx.r3.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCE4:
	// li r3,997
	ctx.r3.s64 = 997;
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCEC:
	// li r3,122
	ctx.r3.s64 = 122;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
loc_8274BCF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274BC18) {
	__imp__sub_8274BC18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274BCFC) {
	__imp__sub_8274BCFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BD00) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BD20;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bd84
	if (!cr0.eq) goto loc_8274BD84;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// ori r4,r4,38
	ctx.r4.u64 = ctx.r4.u64 | 38;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BD4C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bd5c
	if (!cr0.lt) goto loc_8274BD5C;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bd7c
	goto loc_8274BD7C;
loc_8274BD5C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bd78
	if (!cr6.eq) goto loc_8274BD78;
	// bl 0x82135d90
	ctx.lr = 0x8274BD68;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bd7c
	goto loc_8274BD7C;
loc_8274BD78:
	// li r31,997
	r31.s64 = 997;
loc_8274BD7C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BD84;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BD84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_8274BD00) {
	__imp__sub_8274BD00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BDA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274BDA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// rldicl r11,r31,16,48
	r11.u64 = __builtin_rotateleft64(r31.u64, 16) & 0xFFFF;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,9
	cr6.compare<uint32_t>(ctx.r10.u32, 9, xer);
	// bne cr6,0x8274bdd8
	if (!cr6.eq) goto loc_8274BDD8;
	// rlwinm. r11,r11,0,24,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC0;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274be50
	if (!cr0.eq) goto loc_8274BE50;
loc_8274BDD8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BDE0;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8274be50
	if (!cr0.eq) goto loc_8274BE50;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// std r31,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r31.u64);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,37
	ctx.r4.u64 = ctx.r4.u64 | 37;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BE18;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274be28
	if (!cr0.lt) goto loc_8274BE28;
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8274be48
	goto loc_8274BE48;
loc_8274BE28:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274be44
	if (!cr6.eq) goto loc_8274BE44;
	// bl 0x82135d90
	ctx.lr = 0x8274BE34;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r30,r11,1627
	r30.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// b 0x8274be48
	goto loc_8274BE48;
loc_8274BE44:
	// li r30,997
	r30.s64 = 997;
loc_8274BE48:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BE50;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BE50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274BDA0) {
	__imp__sub_8274BDA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274BE5C) {
	__imp__sub_8274BE5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BE60) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8274be90
	if (!cr6.gt) goto loc_8274BE90;
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = r11.u64 | 2147942400;
loc_8274BE90:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// bl 0x82135d40
	ctx.lr = 0x8274BE98;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274bea8
	if (cr6.eq) goto loc_8274BEA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
loc_8274BEA8:
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

PPC_WEAK_FUNC(sub_8274BE60) {
	__imp__sub_8274BE60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BEC0) {
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
	ctx.lr = 0x8274BEC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8274BEE8;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8204
	r11.s64 = 537657344;
	// ori r11,r11,59648
	r11.u64 = r11.u64 | 59648;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274bf1c
	if (!cr6.lt) goto loc_8274BF1C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// li r29,1627
	r29.s64 = 1627;
	// ori r3,r3,1627
	ctx.r3.u64 = ctx.r3.u64 | 1627;
	// bl 0x82135d40
	ctx.lr = 0x8274BF08;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bfd4
	if (cr6.eq) goto loc_8274BFD4;
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,1627
	r11.u64 = r11.u64 | 1627;
	// b 0x8274bf50
	goto loc_8274BF50;
loc_8274BF1C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x8274bf58
	if (!cr6.lt) goto loc_8274BF58;
	// li r11,128
	r11.s64 = 128;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// li r29,122
	r29.s64 = 122;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// bl 0x82135d40
	ctx.lr = 0x8274BF40;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bfd4
	if (cr6.eq) goto loc_8274BFD4;
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,122
	r11.u64 = r11.u64 | 122;
loc_8274BF50:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BF58:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BF64;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8274bfd4
	if (!cr0.eq) goto loc_8274BFD4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// ori r4,r4,29
	ctx.r4.u64 = ctx.r4.u64 | 29;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BFA4;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274bfc8
	if (cr0.lt) goto loc_8274BFC8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274bfd0
	if (!cr6.eq) goto loc_8274BFD0;
	// bl 0x82135d90
	ctx.lr = 0x8274BFB8;
	sub_82135D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274bfc8
	if (cr0.lt) goto loc_8274BFC8;
	// mr r29,r30
	r29.u64 = r30.u64;
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BFC8:
	// li r29,1627
	r29.s64 = 1627;
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BFD0:
	// li r29,997
	r29.s64 = 997;
loc_8274BFD4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274bfe4
	if (cr6.eq) goto loc_8274BFE4;
	// bl 0x827bce64
	ctx.lr = 0x8274BFE4;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BFE4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274BEC0) {
	__imp__sub_8274BEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274BFF0) {
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
	ctx.lr = 0x8274BFF8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8274C01C;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8204
	r11.s64 = 537657344;
	// ori r11,r11,59648
	r11.u64 = r11.u64 | 59648;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274c044
	if (!cr6.lt) goto loc_8274C044;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// bl 0x8274be60
	ctx.lr = 0x8274C040;
	sub_8274BE60(ctx, base);
	// b 0x8274c0cc
	goto loc_8274C0CC;
loc_8274C044:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274C050;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274c0cc
	if (!cr0.eq) goto loc_8274C0CC;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// ori r4,r4,30
	ctx.r4.u64 = ctx.r4.u64 | 30;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274C094;
	__imp__XMsgStartIORequest(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c0a8
	if (!cr0.lt) goto loc_8274C0A8;
loc_8274C0A0:
	// li r11,1627
	r11.s64 = 1627;
	// b 0x8274c0c8
	goto loc_8274C0C8;
loc_8274C0A8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274c0c4
	if (!cr6.eq) goto loc_8274C0C4;
	// bl 0x82135d90
	ctx.lr = 0x8274C0B4;
	sub_82135D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274c0a0
	if (cr0.lt) goto loc_8274C0A0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// b 0x8274c0cc
	goto loc_8274C0CC;
loc_8274C0C4:
	// li r11,997
	r11.s64 = 997;
loc_8274C0C8:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_8274C0CC:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c0dc
	if (cr6.eq) goto loc_8274C0DC;
	// bl 0x827bce64
	ctx.lr = 0x8274C0DC;
	__imp__ObDereferenceObject(ctx, base);
loc_8274C0DC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274BFF0) {
	__imp__sub_8274BFF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C0E8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// ori r4,r4,32821
	ctx.r4.u64 = ctx.r4.u64 | 32821;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// bl 0x827bd0d4
	ctx.lr = 0x8274C130;
	__imp__XMsgInProcessCall(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274c140
	if (cr0.lt) goto loc_8274C140;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8274c170
	goto loc_8274C170;
loc_8274C140:
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,87
	r11.u64 = r11.u64 | 87;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8274c158
	if (!cr6.eq) goto loc_8274C158;
	// li r3,87
	ctx.r3.s64 = 87;
	// b 0x8274c170
	goto loc_8274C170;
loc_8274C158:
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,122
	r11.u64 = r11.u64 | 122;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,122
	ctx.r3.s64 = 122;
	// beq cr6,0x8274c170
	if (cr6.eq) goto loc_8274C170;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8274C170:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274C0E8) {
	__imp__sub_8274C0E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C180) {
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
	ctx.lr = 0x8274C188;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274c1e0
	if (cr6.eq) goto loc_8274C1E0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8274C1B4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274c1b4
	if (!cr6.eq) goto loc_8274C1B4;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r30,r11,0
	r30.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r30,199
	cr6.compare<uint32_t>(r30.u32, 199, xer);
	// ble cr6,0x8274c1e4
	if (!cr6.gt) goto loc_8274C1E4;
loc_8274C1D8:
	// li r31,87
	r31.s64 = 87;
	// b 0x8274c2d4
	goto loc_8274C2D4;
loc_8274C1E0:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8274C1E4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c1d8
	if (cr6.eq) goto loc_8274C1D8;
	// cmplwi cr6,r27,1000
	cr6.compare<uint32_t>(r27.u32, 1000, xer);
	// bgt cr6,0x8274c1d8
	if (cr6.gt) goto loc_8274C1D8;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274c1d8
	if (cr6.eq) goto loc_8274C1D8;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r7,212
	ctx.r7.s64 = 212;
	// ori r6,r6,32826
	ctx.r6.u64 = ctx.r6.u64 | 32826;
	// ori r5,r5,32825
	ctx.r5.u64 = ctx.r5.u64 | 32825;
	// li r4,252
	ctx.r4.s64 = 252;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x827bd094
	ctx.lr = 0x8274C228;
	__imp__XamCreateEnumeratorHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274c2b4
	if (!cr0.eq) goto loc_8274C2B4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bd0e4
	ctx.lr = 0x8274C23C;
	__imp__XamGetPrivateEnumStructureFromHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274c2b4
	if (!cr0.eq) goto loc_8274C2B4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8274c254
	if (cr6.eq) goto loc_8274C254;
	// mulli r11,r27,208
	r11.s64 = r27.s64 * 208;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8274C254:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r31,r11,24
	r31.s64 = r11.s64 + 24;
	// beq cr6,0x8274c274
	if (cr6.eq) goto loc_8274C274;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x8274C274;
	sub_823DA950(ctx, base);
loc_8274C274:
	// mulli r11,r27,215
	r11.s64 = r27.s64 * 215;
	// stbx r28,r30,r31
	PPC_STORE_U8(r30.u32 + r31.u32, r28.u8);
	// stw r28,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r28.u32);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// stw r4,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r4.u32);
	// lis r3,6144
	ctx.r3.s64 = 402653184;
	// bl 0x827bd354
	ctx.lr = 0x8274C294;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c2a4
	if (!cr0.lt) goto loc_8274C2A4;
	// li r31,8
	r31.s64 = 8;
	// b 0x8274c2b4
	goto loc_8274C2B4;
loc_8274C2A4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r28
	r31.u64 = r28.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
loc_8274C2B4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c2c4
	if (cr6.eq) goto loc_8274C2C4;
	// bl 0x8244eee0
	ctx.lr = 0x8274C2C4;
	sub_8244EEE0(ctx, base);
loc_8274C2C4:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c2d4
	if (cr6.eq) goto loc_8274C2D4;
	// bl 0x827bce64
	ctx.lr = 0x8274C2D4;
	__imp__ObDereferenceObject(ctx, base);
loc_8274C2D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8274C180) {
	__imp__sub_8274C180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C2E0) {
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
	ctx.lr = 0x8274C2E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c31c
	if (cr6.eq) goto loc_8274C31C;
	// lbz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8274c31c
	if (cr0.eq) goto loc_8274C31C;
	// li r11,0
	r11.s64 = 0;
loc_8274C30C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274c30c
	if (cr6.lt) goto loc_8274C30C;
loc_8274C31C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r11,-5036
	r28.s64 = r11.s64 + -5036;
	// lbz r4,-5036(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + -5036);
	// cmplwi r4,0
	cr0.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq 0x8274c3ac
	if (cr0.eq) goto loc_8274C3AC;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
loc_8274C338:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c38c
	if (cr6.eq) goto loc_8274C38C;
	// lbz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r7,0
	cr0.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq 0x8274c38c
	if (cr0.eq) goto loc_8274C38C;
	// mulli r11,r8,12
	r11.s64 = ctx.r8.s64 * 12;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lbzx r9,r11,r5
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r5.u32);
	// li r11,0
	r11.s64 = 0;
loc_8274C360:
	// mulli r3,r11,12
	ctx.r3.s64 = r11.s64 * 12;
	// lbzx r3,r3,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274c374
	if (!cr6.eq) goto loc_8274C374;
	// li r6,1
	ctx.r6.s64 = 1;
loc_8274C374:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274c360
	if (cr6.lt) goto loc_8274C360;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x8274c398
	if (!cr6.eq) goto loc_8274C398;
loc_8274C38C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_8274C398:
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// blt cr6,0x8274c338
	if (cr6.lt) goto loc_8274C338;
loc_8274C3AC:
	// lis r11,24714
	r11.s64 = 1619656704;
	// li r3,8
	ctx.r3.s64 = 8;
	// ori r31,r11,8194
	r31.u64 = r11.u64 | 8194;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130b50
	ctx.lr = 0x8274C3C0;
	sub_82130B50(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8274c504
	if (cr0.eq) goto loc_8274C504;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c3d8
	if (cr6.eq) goto loc_8274C3D8;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
loc_8274C3D8:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
	// mulli r3,r11,12
	ctx.r3.s64 = r11.s64 * 12;
	// bl 0x82130b50
	ctx.lr = 0x8274C3F8;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// beq 0x8274c4d8
	if (cr0.eq) goto loc_8274C4D8;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c430
	if (cr6.eq) goto loc_8274C430;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c430
	if (cr6.eq) goto loc_8274C430;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mulli r5,r11,12
	ctx.r5.s64 = r11.s64 * 12;
	// bl 0x823da950
	ctx.lr = 0x8274C430;
	sub_823DA950(ctx, base);
loc_8274C430:
	// lbz r26,0(r28)
	r26.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi r26,0
	cr0.compare<uint32_t>(r26.u32, 0, xer);
	// beq 0x8274c504
	if (cr0.eq) goto loc_8274C504;
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r30,0
	r30.s64 = 0;
loc_8274C444:
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c498
	if (cr6.eq) goto loc_8274C498;
	// lbz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq 0x8274c498
	if (cr0.eq) goto loc_8274C498;
	// mulli r11,r30,12
	r11.s64 = r30.s64 * 12;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lbzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// li r11,0
	r11.s64 = 0;
loc_8274C46C:
	// mulli r6,r11,12
	ctx.r6.s64 = r11.s64 * 12;
	// lbzx r6,r6,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// cmplw cr6,r6,r9
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274c480
	if (!cr6.eq) goto loc_8274C480;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8274C480:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274c46c
	if (cr6.lt) goto loc_8274C46C;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8274c4c0
	if (!cr6.eq) goto loc_8274C4C0;
loc_8274C498:
	// clrlwi r31,r31,24
	r31.u64 = r31.u32 & 0xFF;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mulli r11,r30,12
	r11.s64 = r30.s64 * 12;
	// mulli r10,r31,12
	ctx.r10.s64 = r31.s64 * 12;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x823da950
	ctx.lr = 0x8274C4B8;
	sub_823DA950(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
loc_8274C4C0:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// blt cr6,0x8274c444
	if (cr6.lt) goto loc_8274C444;
	// b 0x8274c504
	goto loc_8274C504;
loc_8274C4D8:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c4f4
	if (cr6.eq) goto loc_8274C4F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x8274C4EC;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_8274C4F4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821310f8
	ctx.lr = 0x8274C500;
	sub_821310F8(ctx, base);
	// li r29,0
	r29.s64 = 0;
loc_8274C504:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274C2E0) {
	__imp__sub_8274C2E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C510) {
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
	ctx.lr = 0x8274C518;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x8274c2e0
	ctx.lr = 0x8274C548;
	sub_8274C2E0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274c560
	if (!cr0.eq) goto loc_8274C560;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x8274c60c
	goto loc_8274C60C;
loc_8274C560:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bge cr6,0x8274c574
	if (!cr6.lt) goto loc_8274C574;
	// li r11,4
	r11.s64 = 4;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
loc_8274C574:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8274c588
	if (!cr6.lt) goto loc_8274C588;
	// li r11,3
	r11.s64 = 3;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
loc_8274C588:
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// b 0x8274c5a0
	goto loc_8274C5A0;
loc_8274C590:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274c5a8
	if (!cr6.eq) goto loc_8274C5A8;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_8274C5A0:
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// blt cr6,0x8274c590
	if (cr6.lt) goto loc_8274C590;
loc_8274C5A8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274C5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274c60c
	if (!cr0.lt) goto loc_8274C60C;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c60c
	if (cr6.eq) goto loc_8274C60C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c600
	if (cr6.eq) goto loc_8274C600;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274C5F4;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8274C600:
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274C60C;
	sub_821310F8(ctx, base);
loc_8274C60C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274C510) {
	__imp__sub_8274C510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C618) {
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
	ctx.lr = 0x8274C620;
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
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x8244d150
	ctx.lr = 0x8274C644;
	sub_8244D150(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8274ebc0
	ctx.lr = 0x8274C65C;
	sub_8274EBC0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274c688
	if (!cr0.lt) goto loc_8274C688;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c688
	if (cr6.eq) goto loc_8274C688;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274C680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274C688:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274C618) {
	__imp__sub_8274C618(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274C694) {
	__imp__sub_8274C694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C698) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8274c618
	sub_8274C618(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274C698) {
	__imp__sub_8274C698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274C6A4) {
	__imp__sub_8274C6A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C6A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274c6c8
	if (!cr6.eq) goto loc_8274C6C8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-4928
	r11.s64 = r11.s64 + -4928;
	// b 0x8274c6d0
	goto loc_8274C6D0;
loc_8274C6C8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-4960
	r11.s64 = r11.s64 + -4960;
loc_8274C6D0:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274C6A8) {
	__imp__sub_8274C6A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274C6D8) {
	__imp__sub_8274C6D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274C6EC) {
	__imp__sub_8274C6EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C6F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8244d150
	ctx.lr = 0x8274C720;
	sub_8244D150(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8274f578
	ctx.lr = 0x8274C730;
	sub_8274F578(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c750
	if (!cr0.lt) goto loc_8274C750;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8274C750:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r11,r30,44
	r11.s64 = r30.s64 + 44;
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274c76c
	if (cr6.eq) goto loc_8274C76C;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8274c770
	goto loc_8274C770;
loc_8274C76C:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8274C770:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
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

PPC_WEAK_FUNC(sub_8274C6F0) {
	__imp__sub_8274C6F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274C78C) {
	__imp__sub_8274C78C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C790) {
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
	ctx.lr = 0x8274C798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_8274C7AC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c7fc
	if (cr6.eq) goto loc_8274C7FC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274c7fc
	if (cr6.eq) goto loc_8274C7FC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c7ec
	if (cr6.eq) goto loc_8274C7EC;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274c7e0
	if (!cr6.eq) goto loc_8274C7E0;
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274C7E0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
loc_8274C7EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274C7F4;
	sub_8274C6F0(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x8274c7ac
	goto loc_8274C7AC;
loc_8274C7FC:
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
loc_8274C804:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c940
	if (cr6.eq) goto loc_8274C940;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274c940
	if (cr6.eq) goto loc_8274C940;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274c848
	if (cr6.eq) goto loc_8274C848;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x8274c83c
	if (!cr6.eq) goto loc_8274C83C;
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
loc_8274C83C:
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
loc_8274C848:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8274c930
	if (!cr6.eq) goto loc_8274C930;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r10,140(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 140);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8274c874
	if (cr6.eq) goto loc_8274C874;
	// stb r10,60(r31)
	PPC_STORE_U8(r31.u32 + 60, ctx.r10.u8);
loc_8274C874:
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// cmplwi cr6,r10,4096
	cr6.compare<uint32_t>(ctx.r10.u32, 4096, xer);
	// ble cr6,0x8274c884
	if (!cr6.gt) goto loc_8274C884;
	// sth r28,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r28.u16);
loc_8274C884:
	// lhz r10,-2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lbz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// li r7,259
	ctx.r7.s64 = 259;
	// rlwimi r10,r8,12,0,19
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 12) & 0xFFFFF000) | (ctx.r10.u64 & 0xFFFFFFFF00000FFF);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// rlwimi r8,r10,1,20,30
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFE) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF001);
	// sth r8,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r8.u16);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,62(r31)
	PPC_STORE_U16(r31.u32 + 62, ctx.r10.u16);
	// lhz r10,-2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// lwz r8,196(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// rlwinm r8,r8,0,12,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xF0000;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwimi r10,r9,27,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 27) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r28,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r28.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c904
	if (cr6.eq) goto loc_8274C904;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// b 0x8274c908
	goto loc_8274C908;
loc_8274C904:
	// stw r4,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r4.u32);
loc_8274C908:
	// stw r4,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,1268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1268);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r10.u32);
	// b 0x8274c938
	goto loc_8274C938;
loc_8274C930:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274C938;
	sub_8274C6F0(ctx, base);
loc_8274C938:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x8274c804
	goto loc_8274C804;
loc_8274C940:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274C790) {
	__imp__sub_8274C790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274C94C) {
	__imp__sub_8274C94C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274C950) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8274C958;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// lwz r24,64(r29)
	r24.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// bl 0x82750430
	ctx.lr = 0x8274C978;
	sub_82750430(ctx, base);
	// addi r28,r29,44
	r28.s64 = r29.s64 + 44;
	// lwz r31,44(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274c990
	if (!cr6.eq) goto loc_8274C990;
	// mr r30,r25
	r30.u64 = r25.u64;
	// b 0x8274c9a8
	goto loc_8274C9A8;
loc_8274C990:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274c9a8
	if (cr6.eq) goto loc_8274C9A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// bne cr6,0x8274c9c4
	if (!cr6.eq) goto loc_8274C9C4;
loc_8274C9A8:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274c9c4
	if (!cr6.eq) goto loc_8274C9C4;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// stw r11,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r11.u32);
	// bl 0x823ea478
	ctx.lr = 0x8274C9C4;
	sub_823EA478(ctx, base);
loc_8274C9C4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
loc_8274C9CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bge cr6,0x8274caa8
	if (!cr6.lt) goto loc_8274CAA8;
	// addi r27,r29,52
	r27.s64 = r29.s64 + 52;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8274f988
	ctx.lr = 0x8274C9F0;
	sub_8274F988(ctx, base);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274caa8
	if (!cr6.lt) goto loc_8274CAA8;
	// li r11,259
	r11.s64 = 259;
	// li r5,88
	ctx.r5.s64 = 88;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274CA14;
	sub_8244D150(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r31.u32);
	// bl 0x823ea320
	ctx.lr = 0x8274CA38;
	sub_823EA320(ctx, base);
	// mr. r23,r3
	r23.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// blt 0x8274caa0
	if (cr0.lt) goto loc_8274CAA0;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ca68
	if (cr6.eq) goto loc_8274CA68;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274ca5c
	if (!cr6.eq) goto loc_8274CA5C;
	// stw r25,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r25.u32);
loc_8274CA5C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r25.u32);
loc_8274CA68:
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ca80
	if (cr6.eq) goto loc_8274CA80;
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// b 0x8274ca84
	goto loc_8274CA84;
loc_8274CA80:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
loc_8274CA84:
	// stw r31,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r31.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x8274c9cc
	goto loc_8274C9CC;
loc_8274CAA0:
	// mr r23,r25
	r23.u64 = r25.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
loc_8274CAA8:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cadc
	if (!cr6.eq) goto loc_8274CADC;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// bne cr6,0x8274cadc
	if (!cr6.eq) goto loc_8274CADC;
	// addi r3,r29,52
	ctx.r3.s64 = r29.s64 + 52;
	// bl 0x8274f988
	ctx.lr = 0x8274CAC4;
	sub_8274F988(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// blt cr6,0x8274cadc
	if (cr6.lt) goto loc_8274CADC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// bl 0x823ea3d8
	ctx.lr = 0x8274CAD8;
	sub_823EA3D8(ctx, base);
	// stw r25,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r25.u32);
loc_8274CADC:
	// lwz r4,52(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// addi r31,r29,52
	r31.s64 = r29.s64 + 52;
	// b 0x8274cb2c
	goto loc_8274CB2C;
loc_8274CAE8:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274cb34
	if (cr6.eq) goto loc_8274CB34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274cb20
	if (cr6.eq) goto loc_8274CB20;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274cb14
	if (!cr6.eq) goto loc_8274CB14;
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
loc_8274CB14:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r25.u32);
loc_8274CB20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274CB28;
	sub_8274C6F0(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8274CB2C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274cae8
	if (!cr6.eq) goto loc_8274CAE8;
loc_8274CB34:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_8274C950) {
	__imp__sub_8274C950(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CB40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cb50
	if (!cr6.eq) goto loc_8274CB50;
	// b 0x8274c950
	sub_8274C950(ctx, base);
	return;
loc_8274CB50:
	// b 0x8274c790
	sub_8274C790(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274CB40) {
	__imp__sub_8274CB40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274CB54) {
	__imp__sub_8274CB54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CB58) {
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
	// bl 0x8274ede8
	ctx.lr = 0x8274CB70;
	sub_8274EDE8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274cbdc
	if (cr0.lt) goto loc_8274CBDC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274cbb0
	if (!cr6.eq) goto loc_8274CBB0;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x8274cba8
	goto loc_8274CBA8;
loc_8274CB8C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8274CBA8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274cb8c
	if (!cr6.eq) goto loc_8274CB8C;
loc_8274CBB0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cbdc
	if (!cr6.eq) goto loc_8274CBDC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274cbdc
	if (cr6.eq) goto loc_8274CBDC;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ea420
	ctx.lr = 0x8274CBDC;
	sub_823EA420(ctx, base);
loc_8274CBDC:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8274CB58) {
	__imp__sub_8274CB58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CBF0) {
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
	ctx.lr = 0x8274CBF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// lwz r11,24(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,28,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// xori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 ^ 2;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// add r3,r11,r6
	ctx.r3.u64 = r11.u64 + ctx.r6.u64;
	// bl 0x8274fc70
	ctx.lr = 0x8274CC3C;
	sub_8274FC70(ctx, base);
	// mr. r27,r3
	r27.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// blt 0x8274ccb4
	if (cr0.lt) goto loc_8274CCB4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274cc98
	if (!cr6.gt) goto loc_8274CC98;
	// li r30,0
	r30.s64 = 0;
loc_8274CC58:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r10,r29
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r29.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274CC84;
	sub_8274C6F0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274cc58
	if (cr6.lt) goto loc_8274CC58;
loc_8274CC98:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274ccb4
	if (!cr6.eq) goto loc_8274CCB4;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82750928
	ctx.lr = 0x8274CCB0;
	sub_82750928(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8274CCB4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274CBF0) {
	__imp__sub_8274CBF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CCC0) {
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
	// beq cr6,0x8274cd40
	if (cr6.eq) goto loc_8274CD40;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cd0c
	if (!cr6.eq) goto loc_8274CD0C;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cd04
	if (cr6.eq) goto loc_8274CD04;
	// bl 0x823ea140
	ctx.lr = 0x8274CD00;
	sub_823EA140(ctx, base);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
loc_8274CD04:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x827503b8
	ctx.lr = 0x8274CD0C;
	sub_827503B8(ctx, base);
loc_8274CD0C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cd28
	if (cr6.eq) goto loc_8274CD28;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x8274CD24;
	sub_821310F8(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
loc_8274CD28:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8274fb28
	ctx.lr = 0x8274CD30;
	sub_8274FB28(ctx, base);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// bl 0x821310f8
	ctx.lr = 0x8274CD40;
	sub_821310F8(ctx, base);
loc_8274CD40:
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

PPC_WEAK_FUNC(sub_8274CCC0) {
	__imp__sub_8274CCC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CD58) {
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
	ctx.lr = 0x8274CD60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8274cd90
	if (cr6.eq) goto loc_8274CD90;
	// stw r26,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r26.u32);
loc_8274CD90:
	// lwz r29,52(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 52);
	// b 0x8274ce38
	goto loc_8274CE38;
loc_8274CD98:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8274ce34
	if (cr6.eq) goto loc_8274CE34;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r8,r30,r8
	ctx.r8.s64 = ctx.r8.s64 - r30.s64;
	// addi r31,r9,2
	r31.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// bgt cr6,0x8274ce6c
	if (cr6.gt) goto loc_8274CE6C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r3,r30,r27
	ctx.r3.u64 = r30.u64 + r27.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r11,-2
	ctx.r4.s64 = r11.s64 + -2;
	// bl 0x823da950
	ctx.lr = 0x8274CDE0;
	sub_823DA950(ctx, base);
	// add r30,r31,r30
	r30.u64 = r31.u64 + r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8274cdfc
	if (cr6.eq) goto loc_8274CDFC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8274CDFC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r31,-2
	ctx.r9.s64 = r31.s64 + -2;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274ce1c
	if (!cr6.lt) goto loc_8274CE1C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274CE1C:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274ce38
	if (!cr6.eq) goto loc_8274CE38;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_8274CE34:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_8274CE38:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274cd98
	if (!cr6.eq) goto loc_8274CD98;
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,32(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,1268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1268);
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// andc r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// stw r10,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r10.u32);
loc_8274CE60:
	// stw r30,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8274CE6C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274ce60
	if (!cr6.eq) goto loc_8274CE60;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// mr r30,r31
	r30.u64 = r31.u64;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8274ce60
	goto loc_8274CE60;
}

PPC_WEAK_FUNC(sub_8274CD58) {
	__imp__sub_8274CD58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274CE84) {
	__imp__sub_8274CE84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CE88) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8274CE90;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32768
	r11.s64 = -2147483648;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// ori r26,r11,16385
	r26.u64 = r11.u64 | 16385;
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8274cfc0
	if (cr6.eq) goto loc_8274CFC0;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274CEC0;
	sub_8244D150(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r31,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r31.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274CEE8;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r30,1
	r30.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274CF08;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244d150
	ctx.lr = 0x8274CF24;
	sub_8244D150(ctx, base);
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// addi r11,r1,104
	r11.s64 = ctx.r1.s64 + 104;
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// addi r28,r29,60
	r28.s64 = r29.s64 + 60;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cf54
	if (cr6.eq) goto loc_8274CF54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274cfbc
	if (cr6.eq) goto loc_8274CFBC;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x823ea218
	ctx.lr = 0x8274CF50;
	sub_823EA218(ctx, base);
	// b 0x8274cfb8
	goto loc_8274CFB8;
loc_8274CF54:
	// li r5,92
	ctx.r5.s64 = 92;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x8274CF64;
	sub_8244D150(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// li r10,16000
	ctx.r10.s64 = 16000;
	// stw r29,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r29.u32);
	// addi r11,r11,-14632
	r11.s64 = r11.s64 + -14632;
	// stb r30,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r30.u8);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r30.u8);
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r30,169(r1)
	PPC_STORE_U8(ctx.r1.u32 + 169, r30.u8);
	// stb r30,170(r1)
	PPC_STORE_U8(ctx.r1.u32 + 170, r30.u8);
	// stb r31,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r31.u8);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r31.u32);
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r31.u32);
	// stw r31,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r31.u32);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// stb r11,171(r1)
	PPC_STORE_U8(ctx.r1.u32 + 171, r11.u8);
	// bl 0x823eaa90
	ctx.lr = 0x8274CFB8;
	sub_823EAA90(ctx, base);
loc_8274CFB8:
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_8274CFBC:
	// stw r30,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r30.u32);
loc_8274CFC0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274CE88) {
	__imp__sub_8274CE88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274CFCC) {
	__imp__sub_8274CFCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274CFD0) {
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
	ctx.lr = 0x8274CFD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,36(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274d004
	if (!cr6.eq) goto loc_8274D004;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// b 0x8274d068
	goto loc_8274D068;
loc_8274D004:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r31,r11,2
	r31.s64 = r11.s64 + 2;
	// divwu. r27,r10,r31
	r27.u32 = ctx.r10.u32 / r31.u32;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// twllei r31,0
	// beq 0x8274d068
	if (cr0.eq) goto loc_8274D068;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
loc_8274D02C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,68(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 68);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x827506a8
	ctx.lr = 0x8274D03C;
	sub_827506A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d068
	if (cr0.lt) goto loc_8274D068;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8274d068
	if (cr6.eq) goto loc_8274D068;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r28,r28,r31
	r28.u64 = r28.u64 + r31.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// blt cr6,0x8274d02c
	if (cr6.lt) goto loc_8274D02C;
loc_8274D068:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274CFD0) {
	__imp__sub_8274CFD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D070) {
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274d0a8
	if (!cr6.eq) goto loc_8274D0A8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274d0a8
	if (!cr6.eq) goto loc_8274D0A8;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82750870
	ctx.lr = 0x8274D0A8;
	sub_82750870(ctx, base);
loc_8274D0A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274edc0
	ctx.lr = 0x8274D0B0;
	sub_8274EDC0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274d0c0
	if (!cr0.lt) goto loc_8274D0C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274cb58
	ctx.lr = 0x8274D0C0;
	sub_8274CB58(ctx, base);
loc_8274D0C0:
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

PPC_WEAK_FUNC(sub_8274D070) {
	__imp__sub_8274D070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D0DC) {
	__imp__sub_8274D0DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D0E0) {
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
	ctx.lr = 0x8274D0E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274D110;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8274d190
	if (cr0.eq) goto loc_8274D190;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r11,r11,-5028
	r11.s64 = r11.s64 + -5028;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// bne cr6,0x8274d168
	if (!cr6.eq) goto loc_8274D168;
	// lwz r4,72(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d170
	if (cr6.eq) goto loc_8274D170;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274D164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8274d170
	goto loc_8274D170;
loc_8274D168:
	// li r11,255
	r11.s64 = 255;
	// stb r11,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r11.u8);
loc_8274D170:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130b50
	ctx.lr = 0x8274D184;
	sub_82130B50(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274d1a4
	if (!cr0.eq) goto loc_8274D1A4;
loc_8274D190:
	// lis r27,-32761
	r27.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r27,r27,14
	r27.u64 = r27.u64 | 14;
	// bl 0x8274ccc0
	ctx.lr = 0x8274D1A0;
	sub_8274CCC0(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274D1A4:
	// stw r31,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r31.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274D0E0) {
	__imp__sub_8274D0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D1B4) {
	__imp__sub_8274D1B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	// clrlwi. r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x8274d1c8
	if (!cr0.eq) goto loc_8274D1C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8274d0e0
	sub_8274D0E0(ctx, base);
	return;
loc_8274D1C8:
	// b 0x8274d0e0
	sub_8274D0E0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274D1B8) {
	__imp__sub_8274D1B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D1CC) {
	__imp__sub_8274D1CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-11848
	ctx.r3.s64 = r11.s64 + -11848;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D1D0) {
	__imp__sub_8274D1D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D1DC) {
	__imp__sub_8274D1DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d1f0
	if (cr6.eq) goto loc_8274D1F0;
	// li r11,6172
	r11.s64 = 6172;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
loc_8274D1F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D1E0) {
	__imp__sub_8274D1E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D1F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274D1FC:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274d1fc
	if (!cr0.eq) goto loc_8274D1FC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D1F8) {
	__imp__sub_8274D1F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D220) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274D224:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274d224
	if (!cr0.eq) goto loc_8274D224;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D220) {
	__imp__sub_8274D220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d260
	if (cr6.eq) goto loc_8274D260;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
loc_8274D260:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D248) {
	__imp__sub_8274D248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D268) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32761
	r11.s64 = -2147024896;
	// clrlwi. r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ori r11,r11,87
	r11.u64 = r11.u64 | 87;
	// bne 0x8274d284
	if (!cr0.eq) goto loc_8274D284;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8274D284:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D268) {
	__imp__sub_8274D268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D28C) {
	__imp__sub_8274D28C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d2a0
	if (cr6.eq) goto loc_8274D2A0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
loc_8274D2A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D290) {
	__imp__sub_8274D290(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D2A8) {
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
	ctx.lr = 0x8274D2B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,6172
	ctx.r4.s64 = 6172;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274D2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274d2fc
	if (!cr0.eq) goto loc_8274D2FC;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
loc_8274D2EC:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8274D2FC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-4988
	r11.s64 = r11.s64 + -4988;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x8274d2ec
	goto loc_8274D2EC;
}

PPC_WEAK_FUNC(sub_8274D2A8) {
	__imp__sub_8274D2A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D31C) {
	__imp__sub_8274D31C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D320) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8274D328;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274d470
	if (cr6.eq) goto loc_8274D470;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823eaf00
	ctx.lr = 0x8274D358;
	sub_823EAF00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d470
	if (cr0.lt) goto loc_8274D470;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r27,r24
	r27.u64 = r24.u64;
	// mr r28,r24
	r28.u64 = r24.u64;
	// addi r31,r30,6156
	r31.s64 = r30.s64 + 6156;
	// addi r26,r30,12
	r26.s64 = r30.s64 + 12;
	// lfs f31,6332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6332);
	f31.f64 = double(temp.f32);
	// subfic r25,r30,-5044
	xer.ca = r30.u32 <= 4294962252;
	r25.s64 = -5044 - r30.s64;
loc_8274D37C:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r10,r25,r31
	ctx.r10.u64 = r25.u64 + r31.u64;
	// lwzx r29,r10,r11
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274d450
	if (cr6.eq) goto loc_8274D450;
	// lwz r11,196(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8274d450
	if (!cr6.eq) goto loc_8274D450;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 184);
	f0.f64 = double(temp.f32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r9,256
	ctx.r9.s64 = 256;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r10,r10,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0xFFFFFE00;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_8274D3C4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * f31.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r8,32767
	cr6.compare<int32_t>(ctx.r8.s32, 32767, xer);
	// blt cr6,0x8274d3ec
	if (cr6.lt) goto loc_8274D3EC;
	// li r8,32767
	ctx.r8.s64 = 32767;
	// b 0x8274d3f8
	goto loc_8274D3F8;
loc_8274D3EC:
	// cmpwi cr6,r8,-32768
	cr6.compare<int32_t>(ctx.r8.s32, -32768, xer);
	// bgt cr6,0x8274d3f8
	if (cr6.gt) goto loc_8274D3F8;
	// li r8,-32738
	ctx.r8.s64 = -32738;
loc_8274D3F8:
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274d3c4
	if (!cr0.eq) goto loc_8274D3C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8274d454
	if (cr6.lt) goto loc_8274D454;
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,768
	ctx.r6.s64 = 768;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r29,200
	ctx.r3.s64 = r29.s64 + 200;
	// bl 0x82751ca8
	ctx.lr = 0x8274D43C;
	sub_82751CA8(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82750ec0
	ctx.lr = 0x8274D44C;
	sub_82750EC0(ctx, base);
	// b 0x8274d454
	goto loc_8274D454;
loc_8274D450:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_8274D454:
	// addi r28,r28,1024
	r28.s64 = r28.s64 + 1024;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r27,r27,3
	r27.s64 = r27.s64 + 3;
	// addi r26,r26,1536
	r26.s64 = r26.s64 + 1536;
	// cmplwi cr6,r28,4096
	cr6.compare<uint32_t>(r28.u32, 4096, xer);
	// blt cr6,0x8274d37c
	if (cr6.lt) goto loc_8274D37C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8274D470:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8274D320) {
	__imp__sub_8274D320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D47C) {
	__imp__sub_8274D47C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1092(r11)
	PPC_STORE_U32(r11.u32 + 1092, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274D480) {
	__imp__sub_8274D480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D490) {
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
	ctx.lr = 0x8274D498;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x8244d150
	ctx.lr = 0x8274D4C4;
	sub_8244D150(ctx, base);
	// li r11,127
	r11.s64 = 127;
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r11,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274D4E0;
	sub_8244D150(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stb r31,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r31.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244d150
	ctx.lr = 0x8274D4FC;
	sub_8244D150(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,161
	r11.s64 = ctx.r1.s64 + 161;
	// li r27,2
	r27.s64 = 2;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8274D510:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// stb r9,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274d510
	if (cr6.lt) goto loc_8274D510;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274D540;
	sub_8244D150(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// li r30,4
	r30.s64 = 4;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274D560;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244d150
	ctx.lr = 0x8274D57C;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r29,1
	r29.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8244d150
	ctx.lr = 0x8274D59C;
	sub_8244D150(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// ori r25,r10,48000
	r25.u64 = ctx.r10.u64 | 48000;
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stb r31,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r31.u8);
	// stb r30,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r30.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r25.u32);
	// stb r29,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r29.u8);
	// stb r30,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, r30.u8);
	// stb r27,138(r1)
	PPC_STORE_U8(ctx.r1.u32 + 138, r27.u8);
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r31.u32);
	// beq cr6,0x8274d620
	if (cr6.eq) goto loc_8274D620;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8274d618
	if (cr0.eq) goto loc_8274D618;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8274D5F4:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwzx r8,r8,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stwx r8,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274d5f4
	if (cr6.lt) goto loc_8274D5F4;
loc_8274D618:
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8274d624
	goto loc_8274D624;
loc_8274D620:
	// lbz r11,104(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 104);
loc_8274D624:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwinm r11,r11,2,22,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FC;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// addi r27,r28,56
	r27.s64 = r28.s64 + 56;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823eaaf0
	ctx.lr = 0x8274D650;
	sub_823EAAF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d740
	if (cr0.lt) goto loc_8274D740;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244d150
	ctx.lr = 0x8274D668;
	sub_8244D150(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,161
	r11.s64 = ctx.r1.s64 + 161;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8274D678:
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r9.u8);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274d678
	if (cr6.lt) goto loc_8274D678;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274D6A8;
	sub_8244D150(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274D6C4;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274D6E4;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// li r5,92
	ctx.r5.s64 = 92;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8244d150
	ctx.lr = 0x8274D700;
	sub_8244D150(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r28,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r28.u32);
	// addi r11,r11,-11136
	r11.s64 = r11.s64 + -11136;
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, r31.u8);
	// stb r30,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, r30.u8);
	// addi r4,r28,64
	ctx.r4.s64 = r28.s64 + 64;
	// stw r25,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r25.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stb r29,249(r1)
	PPC_STORE_U8(ctx.r1.u32 + 249, r29.u8);
	// stb r30,250(r1)
	PPC_STORE_U8(ctx.r1.u32 + 250, r30.u8);
	// stb r29,251(r1)
	PPC_STORE_U8(ctx.r1.u32 + 251, r29.u8);
	// stb r29,256(r1)
	PPC_STORE_U8(ctx.r1.u32 + 256, r29.u8);
	// stw r10,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r10.u32);
	// stw r11,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r11.u32);
	// bl 0x823eaa90
	ctx.lr = 0x8274D740;
	sub_823EAA90(ctx, base);
loc_8274D740:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8274D490) {
	__imp__sub_8274D490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D748) {
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
	ctx.lr = 0x8274D750;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// bne cr6,0x8274d7d0
	if (!cr6.eq) goto loc_8274D7D0;
	// addi r10,r5,344
	ctx.r10.s64 = ctx.r5.s64 + 344;
	// lwz r31,1320(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1320);
	// addi r7,r11,1328
	ctx.r7.s64 = r11.s64 + 1328;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,1376
	r29.s64 = r11.s64 + 1376;
	// addi r8,r11,1112
	ctx.r8.s64 = r11.s64 + 1112;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,4
	r11.s64 = 4;
loc_8274D788:
	// lwz r30,0(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d7a4
	if (cr6.eq) goto loc_8274D7A4;
	// lwz r30,0(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d7a4
	if (cr6.eq) goto loc_8274D7A4;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_8274D7A4:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// bne 0x8274d788
	if (!cr0.eq) goto loc_8274D788;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d7e0
	if (cr6.eq) goto loc_8274D7E0;
	// divwu r11,r31,r4
	r11.u32 = r31.u32 / ctx.r4.u32;
	// twllei r4,0
	// mullw r11,r11,r4
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// b 0x8274d7e0
	goto loc_8274D7E0;
loc_8274D7D0:
	// li r31,0
	r31.s64 = 0;
	// addi r7,r11,1424
	ctx.r7.s64 = r11.s64 + 1424;
	// addi r29,r11,1832
	r29.s64 = r11.s64 + 1832;
	// li r10,34
	ctx.r10.s64 = 34;
loc_8274D7E0:
	// mulli r11,r10,12
	r11.s64 = ctx.r10.s64 * 12;
	// add r28,r11,r7
	r28.u64 = r11.u64 + ctx.r7.u64;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// bge cr6,0x8274d814
	if (!cr6.lt) goto loc_8274D814;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274D7F8:
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + r11.u64;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// blt cr6,0x8274d7f8
	if (cr6.lt) goto loc_8274D7F8;
loc_8274D814:
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274d898
	if (cr6.eq) goto loc_8274D898;
loc_8274D824:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274d888
	if (cr6.eq) goto loc_8274D888;
	// add r11,r4,r31
	r11.u64 = ctx.r4.u64 + r31.u64;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// divwu r9,r11,r10
	ctx.r9.u32 = r11.u32 / ctx.r10.u32;
	// twllei r10,0
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// mulli r9,r11,3
	ctx.r9.s64 = r11.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// mulli r11,r11,12
	r11.s64 = r11.s64 * 12;
	// rlwinm r27,r9,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwzx r27,r27,r29
	r27.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// lwzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpw cr6,r9,r27
	cr6.compare<int32_t>(ctx.r9.s32, r27.s32, xer);
	// bge cr6,0x8274d87c
	if (!cr6.lt) goto loc_8274D87C;
	// addic. r9,r9,1
	xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r9.s64 = ctx.r9.s64 + 1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// ble 0x8274d87c
	if (!cr0.gt) goto loc_8274D87C;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
loc_8274D87C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274d824
	if (cr6.lt) goto loc_8274D824;
loc_8274D888:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d898
	if (cr6.eq) goto loc_8274D898;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274d814
	if (!cr6.eq) goto loc_8274D814;
loc_8274D898:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// bge cr6,0x8274d8d0
	if (!cr6.lt) goto loc_8274D8D0;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274D8A8:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8274d8bc
	if (!cr6.lt) goto loc_8274D8BC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
loc_8274D8BC:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// blt cr6,0x8274d8a8
	if (cr6.lt) goto loc_8274D8A8;
loc_8274D8D0:
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274D748) {
	__imp__sub_8274D748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D8D4) {
	__imp__sub_8274D8D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D8D8) {
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
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8274d93c
	if (cr6.lt) goto loc_8274D93C;
	// beq cr6,0x8274d918
	if (cr6.eq) goto loc_8274D918;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8274d90c
	if (cr6.lt) goto loc_8274D90C;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D90C:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bcf54
	ctx.lr = 0x8274D914;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D918:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bd4a4
	ctx.lr = 0x8274D920;
	__imp__RtlTryEnterCriticalSection(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x8274d930
	if (!cr6.eq) goto loc_8274D930;
	// li r31,0
	r31.s64 = 0;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D930:
	// lis r31,-32768
	r31.s64 = -2147483648;
	// ori r31,r31,16388
	r31.u64 = r31.u64 | 16388;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D93C:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bcf64
	ctx.lr = 0x8274D944;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8274D944:
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

PPC_WEAK_FUNC(sub_8274D8D8) {
	__imp__sub_8274D8D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D95C) {
	__imp__sub_8274D95C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D960) {
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
	ctx.lr = 0x8274D968;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r27,r31,1272
	r27.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274D988;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274d9a8
	if (!cr6.eq) goto loc_8274D9A8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274d9b8
	goto loc_8274D9B8;
loc_8274D9A8:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82751270
	ctx.lr = 0x8274D9B4;
	sub_82751270(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274D9B8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274D9C0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274D960) {
	__imp__sub_8274D960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274D9CC) {
	__imp__sub_8274D9CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274D9D0) {
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
	ctx.lr = 0x8274D9D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r27,r31,1272
	r27.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274D9F8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274da18
	if (!cr6.eq) goto loc_8274DA18;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274da28
	goto loc_8274DA28;
loc_8274DA18:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x827512e8
	ctx.lr = 0x8274DA24;
	sub_827512E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274DA28:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DA30;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274D9D0) {
	__imp__sub_8274D9D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274DA3C) {
	__imp__sub_8274DA3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DA40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,1324
	r11.s64 = ctx.r3.s64 + 1324;
loc_8274DA44:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// stwcx. r4,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r4.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274da44
	if (!cr0.eq) goto loc_8274DA44;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274DA40) {
	__imp__sub_8274DA40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274DA64) {
	__imp__sub_8274DA64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DA68) {
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
	ctx.lr = 0x8274DA70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DA88;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274dabc
	if (cr6.eq) goto loc_8274DABC;
	// addi r10,r31,1096
	ctx.r10.s64 = r31.s64 + 1096;
loc_8274DA9C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8274dabc
	if (!cr6.eq) goto loc_8274DABC;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274da9c
	if (cr6.lt) goto loc_8274DA9C;
loc_8274DABC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274dad0
	if (!cr6.eq) goto loc_8274DAD0;
	// lis r30,-32768
	r30.s64 = -2147483648;
	// ori r30,r30,16389
	r30.u64 = r30.u64 | 16389;
	// b 0x8274db0c
	goto loc_8274DB0C;
loc_8274DAD0:
	// addi r11,r11,274
	r11.s64 = r11.s64 + 274;
	// addi r9,r30,278
	ctx.r9.s64 = r30.s64 + 278;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stwx r8,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r8.u32);
	// stwx r9,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r9.u32);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82751870
	ctx.lr = 0x8274DAFC;
	sub_82751870(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274db0c
	if (cr0.lt) goto loc_8274DB0C;
	// li r11,1
	r11.s64 = 1;
	// stw r11,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r11.u32);
loc_8274DB0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DB14;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274DA68) {
	__imp__sub_8274DA68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DB20) {
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
	ctx.lr = 0x8274DB28;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DB40;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274db90
	if (cr6.eq) goto loc_8274DB90;
	// addi r9,r31,1096
	ctx.r9.s64 = r31.s64 + 1096;
loc_8274DB64:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274db84
	if (cr6.eq) goto loc_8274DB84;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274db64
	if (cr6.lt) goto loc_8274DB64;
	// b 0x8274db90
	goto loc_8274DB90;
loc_8274DB84:
	// addi r11,r10,274
	r11.s64 = ctx.r10.s64 + 274;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r3.u32);
loc_8274DB90:
	// bl 0x82751150
	ctx.lr = 0x8274DB94;
	sub_82751150(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DB9C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274DB20) {
	__imp__sub_8274DB20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DBA8) {
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
	ctx.lr = 0x8274DBB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1272
	r30.s64 = r31.s64 + 1272;
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DBCC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r29,278
	r11.s64 = r29.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274dbe8
	if (cr6.eq) goto loc_8274DBE8;
	// bl 0x82750ae0
	ctx.lr = 0x8274DBE4;
	sub_82750AE0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8274DBE8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DBF0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274DBA8) {
	__imp__sub_8274DBA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274DBFC) {
	__imp__sub_8274DBFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DC00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,278
	r11.s64 = ctx.r4.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274dc28
	if (cr6.eq) goto loc_8274DC28;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274dc28
	if (cr6.eq) goto loc_8274DC28;
	// lwz r3,144(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// blr 
	return;
loc_8274DC28:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274DC00) {
	__imp__sub_8274DC00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DC30) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1268(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1268);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274DC30) {
	__imp__sub_8274DC30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DC38) {
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
	ctx.lr = 0x8274DC40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r26,r31,1272
	r26.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DC64;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274dc84
	if (!cr6.eq) goto loc_8274DC84;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274dca0
	goto loc_8274DCA0;
loc_8274DC84:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,-1840(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// bl 0x82751670
	ctx.lr = 0x8274DC9C;
	sub_82751670(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274DCA0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DCA8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274DC38) {
	__imp__sub_8274DC38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274DCB4) {
	__imp__sub_8274DCB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DCB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274dcec
	if (cr6.eq) goto loc_8274DCEC;
	// addi r10,r3,1128
	ctx.r10.s64 = ctx.r3.s64 + 1128;
loc_8274DCCC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ld r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// cmpld cr6,r4,r8
	cr6.compare<uint64_t>(ctx.r4.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274dcec
	if (cr6.eq) goto loc_8274DCEC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274dccc
	if (cr6.lt) goto loc_8274DCCC;
loc_8274DCEC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8274dd04
	if (!cr6.lt) goto loc_8274DD04;
	// addi r11,r11,282
	r11.s64 = r11.s64 + 282;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// blr 
	return;
loc_8274DD04:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274DCB8) {
	__imp__sub_8274DCB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274DD0C) {
	__imp__sub_8274DD0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274DD10) {
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
	ctx.lr = 0x8274DD18;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r24,r28,1376
	r24.s64 = r28.s64 + 1376;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r22,0
	r22.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x8274DD38;
	sub_8244D150(ctx, base);
	// addi r31,r28,1112
	r31.s64 = r28.s64 + 1112;
	// mr r30,r24
	r30.u64 = r24.u64;
	// li r29,4
	r29.s64 = 4;
loc_8274DD44:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274dd58
	if (cr6.eq) goto loc_8274DD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827516c8
	ctx.lr = 0x8274DD58;
	sub_827516C8(ctx, base);
loc_8274DD58:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x8274dd44
	if (!cr0.eq) goto loc_8274DD44;
	// addi r23,r28,1832
	r23.s64 = r28.s64 + 1832;
	// li r5,408
	ctx.r5.s64 = 408;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244d150
	ctx.lr = 0x8274DD7C;
	sub_8244D150(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r27,r22
	r27.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274dec4
	if (!cr6.gt) goto loc_8274DEC4;
	// addi r31,r28,1128
	r31.s64 = r28.s64 + 1128;
	// mr r25,r23
	r25.u64 = r23.u64;
	// li r26,-1
	r26.s64 = -1;
loc_8274DD98:
	// lwz r11,1308(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1308);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274de94
	if (!cr6.eq) goto loc_8274DE94;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r27
	r29.u64 = r27.u64;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274dde8
	if (cr6.eq) goto loc_8274DDE8;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// li r8,4
	ctx.r8.s64 = 4;
loc_8274DDC4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274ddd4
	if (cr6.lt) goto loc_8274DDD4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274DDD4:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274ddc4
	if (!cr0.eq) goto loc_8274DDC4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x8274ddec
	goto loc_8274DDEC;
loc_8274DDE8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8274DDEC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r5,r27,1
	ctx.r5.s64 = r27.s64 + 1;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bge cr6,0x8274de94
	if (!cr6.lt) goto loc_8274DE94;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
loc_8274DE04:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r26
	r11.u64 = r26.u64;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r9,r10,36
	ctx.r9.s64 = ctx.r10.s64 + 36;
loc_8274DE14:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274de24
	if (cr6.lt) goto loc_8274DE24;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8274DE24:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8274de14
	if (!cr0.eq) goto loc_8274DE14;
	// ld r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x8274de4c
	if (cr6.eq) goto loc_8274DE4C;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bge cr6,0x8274de4c
	if (!cr6.lt) goto loc_8274DE4C;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8274DE4C:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r5,r4
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, xer);
	// blt cr6,0x8274de04
	if (cr6.lt) goto loc_8274DE04;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// beq cr6,0x8274de94
	if (cr6.eq) goto loc_8274DE94;
	// addi r11,r29,282
	r11.s64 = r29.s64 + 282;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// xor r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 ^ r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// stwx r10,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// xor r11,r11,r10
	r11.u64 = r11.u64 ^ ctx.r10.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274DE94:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274deac
	if (cr6.eq) goto loc_8274DEAC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82752bc0
	ctx.lr = 0x8274DEAC;
	sub_82752BC0(ctx, base);
loc_8274DEAC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r25,r25,12
	r25.s64 = r25.s64 + 12;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274dd98
	if (cr6.lt) goto loc_8274DD98;
loc_8274DEC4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r22,1308(r28)
	PPC_STORE_U32(r28.u32 + 1308, r22.u32);
	// addi r11,r28,1328
	r11.s64 = r28.s64 + 1328;
	// addi r10,r10,-4368
	ctx.r10.s64 = ctx.r10.s64 + -4368;
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x8274df24
	if (!cr6.lt) goto loc_8274DF24;
	// addi r6,r24,48
	ctx.r6.s64 = r24.s64 + 48;
	// subf r5,r11,r24
	ctx.r5.s64 = r24.s64 - r11.s64;
loc_8274DEF0:
	// add r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 + r11.u64;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x8274df18
	if (!cr6.lt) goto loc_8274DF18;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r10,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274def0
	if (cr6.lt) goto loc_8274DEF0;
loc_8274DF18:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274df24
	if (cr6.eq) goto loc_8274DF24;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
loc_8274DF24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r11,r11,-4960
	r11.s64 = r11.s64 + -4960;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x8274d748
	ctx.lr = 0x8274DF40;
	sub_8274D748(ctx, base);
	// cmplw cr6,r3,r22
	cr6.compare<uint32_t>(ctx.r3.u32, r22.u32, xer);
	// ble cr6,0x8274df4c
	if (!cr6.gt) goto loc_8274DF4C;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274DF4C:
	// lwz r11,1324(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274df60
	if (!cr6.eq) goto loc_8274DF60;
	// li r11,2
	r11.s64 = 2;
	// stw r11,1324(r28)
	PPC_STORE_U32(r28.u32 + 1324, r11.u32);
loc_8274DF60:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r6,1324(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 1324);
	// addi r30,r23,408
	r30.s64 = r23.s64 + 408;
	// addi r10,r11,-4928
	ctx.r10.s64 = r11.s64 + -4928;
	// addi r31,r28,1424
	r31.s64 = r28.s64 + 1424;
	// mr r11,r23
	r11.u64 = r23.u64;
	// cmplw cr6,r23,r30
	cr6.compare<uint32_t>(r23.u32, r30.u32, xer);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x8274dfa8
	if (!cr6.lt) goto loc_8274DFA8;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274DF88:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x8274df9c
	if (!cr6.gt) goto loc_8274DF9C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
loc_8274DF9C:
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x8274df88
	if (cr6.lt) goto loc_8274DF88;
loc_8274DFA8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8274d748
	ctx.lr = 0x8274DFB4;
	sub_8274D748(ctx, base);
	// addi r10,r31,408
	ctx.r10.s64 = r31.s64 + 408;
	// mr r11,r23
	r11.u64 = r23.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274dff0
	if (!cr6.lt) goto loc_8274DFF0;
	// subf r8,r23,r31
	ctx.r8.s64 = r31.s64 - r23.s64;
loc_8274DFC8:
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8274dff0
	if (!cr6.lt) goto loc_8274DFF0;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// lwzx r7,r7,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stwx r7,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r7.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274dfc8
	if (cr6.lt) goto loc_8274DFC8;
loc_8274DFF0:
	// cmplw cr6,r3,r22
	cr6.compare<uint32_t>(ctx.r3.u32, r22.u32, xer);
	// ble cr6,0x8274dffc
	if (!cr6.gt) goto loc_8274DFFC;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274DFFC:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274e010
	if (cr6.eq) goto loc_8274E010;
	// lwz r11,1320(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1320);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1320(r28)
	PPC_STORE_U32(r28.u32 + 1320, r11.u32);
loc_8274E010:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_8274DD10) {
	__imp__sub_8274DD10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E01C) {
	__imp__sub_8274E01C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E020) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8274E028;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274E048;
	sub_8244D150(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// bl 0x8244d150
	ctx.lr = 0x8274E06C;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r30,1
	r30.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274E08C;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274E0AC;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stb r30,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r30.u8);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274e108
	if (cr6.eq) goto loc_8274E108;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274e0e0
	if (!cr0.eq) goto loc_8274E0E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82750ae0
	ctx.lr = 0x8274E0D8;
	sub_82750AE0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274e0f8
	if (!cr0.eq) goto loc_8274E0F8;
loc_8274E0E0:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm. r11,r11,0,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274e0f8
	if (cr0.eq) goto loc_8274E0F8;
	// lfs f0,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x8274e0fc
	goto loc_8274E0FC;
loc_8274E0F8:
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_8274E0FC:
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x823ea270
	ctx.lr = 0x8274E108;
	sub_823EA270(ctx, base);
loc_8274E108:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274E020) {
	__imp__sub_8274E020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E114) {
	__imp__sub_8274E114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274e14c
	if (cr6.eq) goto loc_8274E14C;
	// addi r9,r3,1128
	ctx.r9.s64 = ctx.r3.s64 + 1128;
loc_8274E12C:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// cmpld cr6,r4,r8
	cr6.compare<uint64_t>(ctx.r4.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274e14c
	if (cr6.eq) goto loc_8274E14C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274e12c
	if (cr6.lt) goto loc_8274E12C;
loc_8274E14C:
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mulli r11,r11,3
	r11.s64 = r11.s64 * 3;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,458
	ctx.r10.s64 = r11.s64 + 458;
	// addi r11,r11,356
	r11.s64 = r11.s64 + 356;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274E118) {
	__imp__sub_8274E118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E17C) {
	__imp__sub_8274E17C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E180) {
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
	ctx.lr = 0x8274E188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274e2e8
	if (cr6.eq) goto loc_8274E2E8;
	// lwz r11,1264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r28,0
	r28.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274e1e0
	if (cr6.eq) goto loc_8274E1E0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8274e1e0
	if (cr6.eq) goto loc_8274E1E0;
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// bl 0x82458230
	ctx.lr = 0x8274E1BC;
	sub_82458230(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// lwz r3,1264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r11.u32);
	// bl 0x82135db8
	ctx.lr = 0x8274E1D0;
	sub_82135DB8(ctx, base);
	// stw r28,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r28.u32);
	// lwz r3,1264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// bl 0x8244eee0
	ctx.lr = 0x8274E1DC;
	sub_8244EEE0(ctx, base);
	// stw r30,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, r30.u32);
loc_8274E1E0:
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e1fc
	if (cr6.eq) goto loc_8274E1FC;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8274e1fc
	if (cr6.eq) goto loc_8274E1FC;
	// bl 0x8244eee0
	ctx.lr = 0x8274E1F8;
	sub_8244EEE0(ctx, base);
	// stw r30,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, r30.u32);
loc_8274E1FC:
	// lwz r3,1312(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e218
	if (cr6.eq) goto loc_8274E218;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8274e218
	if (cr6.eq) goto loc_8274E218;
	// bl 0x8244eee0
	ctx.lr = 0x8274E214;
	sub_8244EEE0(ctx, base);
	// stw r30,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, r30.u32);
loc_8274E218:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e228
	if (cr6.eq) goto loc_8274E228;
	// bl 0x823ea140
	ctx.lr = 0x8274E228;
	sub_823EA140(ctx, base);
loc_8274E228:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e23c
	if (cr6.eq) goto loc_8274E23C;
	// bl 0x823ea140
	ctx.lr = 0x8274E238;
	sub_823EA140(ctx, base);
	// stw r28,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r28.u32);
loc_8274E23C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e250
	if (cr6.eq) goto loc_8274E250;
	// bl 0x823ea140
	ctx.lr = 0x8274E24C;
	sub_823EA140(ctx, base);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
loc_8274E250:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e284
	if (!cr6.gt) goto loc_8274E284;
	// addi r30,r31,1096
	r30.s64 = r31.s64 + 1096;
loc_8274E264:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82751778
	ctx.lr = 0x8274E26C;
	sub_82751778(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e264
	if (cr6.lt) goto loc_8274E264;
loc_8274E284:
	// addi r30,r31,1112
	r30.s64 = r31.s64 + 1112;
	// li r29,4
	r29.s64 = 4;
loc_8274E28C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82751778
	ctx.lr = 0x8274E294;
	sub_82751778(ctx, base);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8274e28c
	if (!cr0.eq) goto loc_8274E28C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e2d8
	if (!cr6.gt) goto loc_8274E2D8;
	// addi r30,r31,1128
	r30.s64 = r31.s64 + 1128;
loc_8274E2B8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x827526b0
	ctx.lr = 0x8274E2C0;
	sub_827526B0(ctx, base);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e2b8
	if (cr6.lt) goto loc_8274E2B8;
loc_8274E2D8:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x821310f8
	ctx.lr = 0x8274E2E8;
	sub_821310F8(ctx, base);
loc_8274E2E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274E180) {
	__imp__sub_8274E180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274E304:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274e304
	if (!cr0.eq) goto loc_8274E304;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274e330
	if (!cr6.eq) goto loc_8274E330;
	// bl 0x8274e180
	ctx.lr = 0x8274E330;
	sub_8274E180(ctx, base);
loc_8274E330:
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

PPC_WEAK_FUNC(sub_8274E2F0) {
	__imp__sub_8274E2F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E348) {
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
	ctx.lr = 0x8274E350;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r31,1272
	r26.s64 = r31.s64 + 1272;
	// mr r28,r27
	r28.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E36C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,1300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1300);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x8274e4a4
	if (cr6.eq) goto loc_8274E4A4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r3,1312(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd054
	ctx.lr = 0x8274E38C;
	__imp__XNotifyGetNext(ctx, base);
	// li r30,1
	r30.s64 = 1;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8274e3d0
	if (cr0.eq) goto loc_8274E3D0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// cmplwi cr6,r11,14
	cr6.compare<uint32_t>(r11.u32, 14, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// lis r10,1024
	ctx.r10.s64 = 67108864;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// lis r10,1024
	ctx.r10.s64 = 67108864;
	// ori r10,r10,3
	ctx.r10.u64 = ctx.r10.u64 | 3;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274e3d0
	if (!cr6.eq) goto loc_8274E3D0;
loc_8274E3CC:
	// stw r30,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r30.u32);
loc_8274E3D0:
	// lwz r11,1092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274e42c
	if (!cr6.eq) goto loc_8274E42C;
	// li r5,88
	ctx.r5.s64 = 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274E3EC;
	sub_8244D150(ctx, base);
	// li r11,1024
	r11.s64 = 1024;
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x823ea320
	ctx.lr = 0x8274E41C;
	sub_823EA320(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x823ea3d8
	ctx.lr = 0x8274E428;
	sub_823EA3D8(ctx, base);
	// stw r30,1092(r31)
	PPC_STORE_U32(r31.u32 + 1092, r30.u32);
loc_8274E42C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dd10
	ctx.lr = 0x8274E434;
	sub_8274DD10(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r31,1112
	r30.s64 = r31.s64 + 1112;
	// li r29,4
	r29.s64 = 4;
loc_8274E440:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e450
	if (cr6.eq) goto loc_8274E450;
	// bl 0x82751360
	ctx.lr = 0x8274E450;
	sub_82751360(ctx, base);
loc_8274E450:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8274e440
	if (!cr0.eq) goto loc_8274E440;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e4a0
	if (!cr6.gt) goto loc_8274E4A0;
	// addi r30,r31,1128
	r30.s64 = r31.s64 + 1128;
loc_8274E470:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e48c
	if (cr6.eq) goto loc_8274E48C;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274e48c
	if (cr6.eq) goto loc_8274E48C;
	// bl 0x82752798
	ctx.lr = 0x8274E48C;
	sub_82752798(ctx, base);
loc_8274E48C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e470
	if (cr6.lt) goto loc_8274E470;
loc_8274E4A0:
	// stw r27,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r27.u32);
loc_8274E4A4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E4AC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274E348) {
	__imp__sub_8274E348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E4BC) {
	__imp__sub_8274E4BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E4C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E4C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E4E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E4F4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e508
	if (!cr0.eq) goto loc_8274E508;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e518
	goto loc_8274E518;
loc_8274E508:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752848
	ctx.lr = 0x8274E514;
	sub_82752848(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E518:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E520;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274E4C0) {
	__imp__sub_8274E4C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E52C) {
	__imp__sub_8274E52C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E538;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E558;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E564;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e578
	if (!cr0.eq) goto loc_8274E578;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e588
	goto loc_8274E588;
loc_8274E578:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827528c0
	ctx.lr = 0x8274E584;
	sub_827528C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E588:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E590;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274E530) {
	__imp__sub_8274E530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E59C) {
	__imp__sub_8274E59C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E5A0) {
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
	ctx.lr = 0x8274E5A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r26,r30,1272
	r26.s64 = r30.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E5CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274E5DC;
	sub_8244D150(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8274dcb8
	ctx.lr = 0x8274E5E8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e5fc
	if (!cr0.eq) goto loc_8274E5FC;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
	// b 0x8274e694
	goto loc_8274E694;
loc_8274E5FC:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82752938
	ctx.lr = 0x8274E614;
	sub_82752938(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274e694
	if (cr0.lt) goto loc_8274E694;
	// lis r12,-1057
	r12.s64 = -69271552;
	// lis r11,-5413
	r11.s64 = -354746368;
	// ori r12,r12,221
	r12.u64 = r12.u64 | 221;
	// lis r10,-1057
	ctx.r10.s64 = -69271552;
	// rldicr r12,r12,32,31
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFF00000000;
	// ori r11,r11,61168
	r11.u64 = r11.u64 | 61168;
	// oris r12,r12,60123
	r12.u64 = r12.u64 | 3940220928;
	// ori r10,r10,221
	ctx.r10.u64 = ctx.r10.u64 | 221;
	// ori r12,r12,61168
	r12.u64 = r12.u64 | 61168;
	// rldimi r11,r10,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// and r9,r31,r12
	ctx.r9.u64 = r31.u64 & r12.u64;
	// cmpld cr6,r9,r11
	cr6.compare<uint64_t>(ctx.r9.u64, r11.u64, xer);
	// beq cr6,0x8274e694
	if (cr6.eq) goto loc_8274E694;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,1112
	r11.s64 = r30.s64 + 1112;
loc_8274E658:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274e678
	if (cr6.eq) goto loc_8274E678;
	// lwz r9,196(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8274e68c
	if (cr6.eq) goto loc_8274E68C;
loc_8274E678:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274e658
	if (cr6.lt) goto loc_8274E658;
	// b 0x8274e694
	goto loc_8274E694;
loc_8274E68C:
	// li r11,1
	r11.s64 = 1;
	// stw r11,1316(r30)
	PPC_STORE_U32(r30.u32 + 1316, r11.u32);
loc_8274E694:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E69C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274E5A0) {
	__imp__sub_8274E5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E6A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8274E6B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1272
	r30.s64 = r31.s64 + 1272;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E6C8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E6D4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e6e8
	if (!cr0.eq) goto loc_8274E6E8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e6f0
	goto loc_8274E6F0;
loc_8274E6E8:
	// bl 0x827529d8
	ctx.lr = 0x8274E6EC;
	sub_827529D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E6F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E6F8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8274E6A8) {
	__imp__sub_8274E6A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E704) {
	__imp__sub_8274E704(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E708) {
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
	ctx.lr = 0x8274E710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E72C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e7b0
	if (!cr6.gt) goto loc_8274E7B0;
	// addi r9,r31,1128
	ctx.r9.s64 = r31.s64 + 1128;
loc_8274E744:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274e79c
	if (cr6.eq) goto loc_8274E79C;
	// lis r12,-1057
	r12.s64 = -69271552;
	// lis r8,-5413
	ctx.r8.s64 = -354746368;
	// ori r12,r12,221
	r12.u64 = r12.u64 | 221;
	// lis r7,-1057
	ctx.r7.s64 = -69271552;
	// rldicr r12,r12,32,31
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFF00000000;
	// ori r8,r8,61168
	ctx.r8.u64 = ctx.r8.u64 | 61168;
	// oris r12,r12,60123
	r12.u64 = r12.u64 | 3940220928;
	// ori r7,r7,221
	ctx.r7.u64 = ctx.r7.u64 | 221;
	// ori r12,r12,61168
	r12.u64 = r12.u64 | 61168;
	// rldimi r8,r7,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// and r6,r11,r12
	ctx.r6.u64 = r11.u64 & r12.u64;
	// cmpld cr6,r6,r8
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274e79c
	if (cr6.eq) goto loc_8274E79C;
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8274E79C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274e744
	if (cr6.lt) goto loc_8274E744;
loc_8274E7B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E7B8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274E708) {
	__imp__sub_8274E708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E7C4) {
	__imp__sub_8274E7C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E7C8) {
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
	ctx.lr = 0x8274E7D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E7EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E7F8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8274e808
	if (cr0.eq) goto loc_8274E808;
	// bl 0x82752b00
	ctx.lr = 0x8274E804;
	sub_82752B00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8274E808:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E810;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274E7C8) {
	__imp__sub_8274E7C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E81C) {
	__imp__sub_8274E81C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E820) {
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
	ctx.lr = 0x8274E828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E844;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E850;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e864
	if (!cr0.eq) goto loc_8274E864;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e870
	goto loc_8274E870;
loc_8274E864:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752028
	ctx.lr = 0x8274E86C;
	sub_82752028(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E870:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E878;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274E820) {
	__imp__sub_8274E820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E884) {
	__imp__sub_8274E884(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E890;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r25,r31,1272
	r25.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E8BC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E8C8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e8dc
	if (!cr0.eq) goto loc_8274E8DC;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e8f8
	goto loc_8274E8F8;
loc_8274E8DC:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752130
	ctx.lr = 0x8274E8F4;
	sub_82752130(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E8F8:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E900;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8274E888) {
	__imp__sub_8274E888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E90C) {
	__imp__sub_8274E90C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E910) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E918;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E938;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E944;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e958
	if (!cr0.eq) goto loc_8274E958;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e968
	goto loc_8274E968;
loc_8274E958:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752ad8
	ctx.lr = 0x8274E964;
	sub_82752AD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E968:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E970;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274E910) {
	__imp__sub_8274E910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E97C) {
	__imp__sub_8274E97C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E980) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E988;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E9A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E9B4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e9c8
	if (!cr0.eq) goto loc_8274E9C8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e9d8
	goto loc_8274E9D8;
loc_8274E9C8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752a60
	ctx.lr = 0x8274E9D4;
	sub_82752A60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E9D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E9E0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274E980) {
	__imp__sub_8274E980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274E9EC) {
	__imp__sub_8274E9EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274E9F0) {
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
	// lis r11,-2
	r11.s64 = -131072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r11,r11,31072
	r11.u64 = r11.u64 | 31072;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8275cef0
	ctx.lr = 0x8274EA24;
	sub_8275CEF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274ea34
	if (!cr0.eq) goto loc_8274EA34;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fe98
	ctx.lr = 0x8274EA34;
	sub_8244FE98(ctx, base);
loc_8274EA34:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275ce80
	ctx.lr = 0x8274EA50;
	sub_8275CE80(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274ea60
	if (!cr0.eq) goto loc_8274EA60;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fe98
	ctx.lr = 0x8274EA60;
	sub_8244FE98(ctx, base);
loc_8274EA60:
	// lwz r3,1304(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1304);
	// bl 0x8244ee00
	ctx.lr = 0x8274EA68;
	sub_8244EE00(ctx, base);
	// b 0x8274ea7c
	goto loc_8274EA7C;
loc_8274EA6C:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82135db8
	ctx.lr = 0x8274EA74;
	sub_82135DB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8274e348
	ctx.lr = 0x8274EA7C;
	sub_8274E348(ctx, base);
loc_8274EA7C:
	// lwz r11,1300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1300);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8274ea6c
	if (!cr6.eq) goto loc_8274EA6C;
	// bl 0x8275ce40
	ctx.lr = 0x8274EA90;
	sub_8275CE40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244eee0
	ctx.lr = 0x8274EA98;
	sub_8244EEE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244fe98
	ctx.lr = 0x8274EAA0;
	sub_8244FE98(ctx, base);
}

PPC_WEAK_FUNC(sub_8274E9F0) {
	__imp__sub_8274E9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EAA0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8274EAA8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ebbc
	if (!cr6.eq) goto loc_8274EBBC;
	// lis r11,-32139
	r11.s64 = -2106261504;
	// lis r10,-32139
	ctx.r10.s64 = -2106261504;
	// addi r11,r11,-11784
	r11.s64 = r11.s64 + -11784;
	// lis r9,-32139
	ctx.r9.s64 = -2106261504;
	// lis r8,-32139
	ctx.r8.s64 = -2106261504;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r10,r10,-7440
	ctx.r10.s64 = ctx.r10.s64 + -7440;
	// addi r9,r9,-10024
	ctx.r9.s64 = ctx.r9.s64 + -10024;
	// addi r11,r8,-9888
	r11.s64 = ctx.r8.s64 + -9888;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,-32139
	ctx.r7.s64 = -2106261504;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lis r6,-32139
	ctx.r6.s64 = -2106261504;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lis r5,-32139
	ctx.r5.s64 = -2106261504;
	// addi r10,r7,-9776
	ctx.r10.s64 = ctx.r7.s64 + -9776;
	// addi r9,r6,-6976
	ctx.r9.s64 = ctx.r6.s64 + -6976;
	// addi r11,r5,-6864
	r11.s64 = ctx.r5.s64 + -6864;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r4,-32139
	ctx.r4.s64 = -2106261504;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r31,-32139
	r31.s64 = -2106261504;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lis r30,-32139
	r30.s64 = -2106261504;
	// addi r10,r4,-9664
	ctx.r10.s64 = ctx.r4.s64 + -9664;
	// addi r9,r31,-9624
	ctx.r9.s64 = r31.s64 + -9624;
	// addi r11,r30,-9440
	r11.s64 = r30.s64 + -9440;
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// lis r29,-32139
	r29.s64 = -2106261504;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lis r28,-32139
	r28.s64 = -2106261504;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lis r27,-32139
	r27.s64 = -2106261504;
	// addi r10,r29,-6752
	ctx.r10.s64 = r29.s64 + -6752;
	// addi r9,r28,-6488
	ctx.r9.s64 = r28.s64 + -6488;
	// addi r11,r27,-6392
	r11.s64 = r27.s64 + -6392;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lis r26,-32139
	r26.s64 = -2106261504;
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// lis r25,-32139
	r25.s64 = -2106261504;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// lis r24,-32139
	r24.s64 = -2106261504;
	// addi r10,r26,-9304
	ctx.r10.s64 = r26.s64 + -9304;
	// addi r9,r25,-9216
	ctx.r9.s64 = r25.s64 + -9216;
	// addi r11,r24,-6200
	r11.s64 = r24.s64 + -6200;
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lis r23,-32139
	r23.s64 = -2106261504;
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// lis r22,-32139
	r22.s64 = -2106261504;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// lis r21,-32139
	r21.s64 = -2106261504;
	// addi r10,r23,-6112
	ctx.r10.s64 = r23.s64 + -6112;
	// addi r9,r22,-6008
	ctx.r9.s64 = r22.s64 + -6008;
	// addi r11,r21,-9168
	r11.s64 = r21.s64 + -9168;
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// lis r20,-32139
	r20.s64 = -2106261504;
	// stw r9,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// lis r19,-32139
	r19.s64 = -2106261504;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// lis r18,-32139
	r18.s64 = -2106261504;
	// addi r10,r20,-9160
	ctx.r10.s64 = r20.s64 + -9160;
	// addi r9,r19,-5872
	ctx.r9.s64 = r19.s64 + -5872;
	// addi r11,r18,-5760
	r11.s64 = r18.s64 + -5760;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
loc_8274EBBC:
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_8274EAA0) {
	__imp__sub_8274EAA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EBC0) {
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
	ctx.lr = 0x8274EBC8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r29,r11,-21400
	r29.s64 = r11.s64 + -21400;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x8274eaa0
	ctx.lr = 0x8274EBE8;
	sub_8274EAA0(ctx, base);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// li r3,2240
	ctx.r3.s64 = 2240;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x82130b50
	ctx.lr = 0x8274EBF8;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274ec0c
	if (!cr0.eq) goto loc_8274EC0C;
	// lis r29,-32761
	r29.s64 = -2147024896;
	// ori r29,r29,14
	r29.u64 = r29.u64 | 14;
	// b 0x8274edb0
	goto loc_8274EDB0;
loc_8274EC0C:
	// li r25,1
	r25.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8274EC28;
	sub_823DA950(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274d490
	ctx.lr = 0x8274EC34;
	sub_8274D490(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274ec80
	if (!cr6.gt) goto loc_8274EC80;
	// addi r28,r31,1096
	r28.s64 = r31.s64 + 1096;
loc_8274EC50:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82751928
	ctx.lr = 0x8274EC64;
	sub_82751928(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274ec50
	if (cr6.lt) goto loc_8274EC50;
loc_8274EC80:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274eccc
	if (!cr6.gt) goto loc_8274ECCC;
	// addi r28,r31,1128
	r28.s64 = r31.s64 + 1128;
loc_8274EC94:
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r7,40(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82752c70
	ctx.lr = 0x8274ECB0;
	sub_82752C70(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274ec94
	if (cr6.lt) goto loc_8274EC94;
loc_8274ECCC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x8274ECE0;
	sub_8244EE40(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, ctx.r3.u32);
	// bne 0x8274ecf8
	if (!cr0.eq) goto loc_8274ECF8;
loc_8274ECEC:
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
	// b 0x8274eda4
	goto loc_8274EDA4;
loc_8274ECF8:
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x827bd3f4
	ctx.lr = 0x8274ED04;
	__imp__XamNotifyCreateListener(ctx, base);
	// stw r3,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8274ecec
	if (cr0.eq) goto loc_8274ECEC;
	// stw r25,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r25.u32);
	// addi r3,r31,1272
	ctx.r3.s64 = r31.s64 + 1272;
	// bl 0x827bcff4
	ctx.lr = 0x8274ED1C;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274ed9c
	if (!cr6.eq) goto loc_8274ED9C;
	// lis r11,-32139
	r11.s64 = -2106261504;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,-5648
	ctx.r5.s64 = r11.s64 + -5648;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82460300
	ctx.lr = 0x8274ED4C;
	sub_82460300(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, ctx.r3.u32);
	// beq 0x8274ecec
	if (cr0.eq) goto loc_8274ECEC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// bl 0x82135db8
	ctx.lr = 0x8274ED64;
	sub_82135DB8(ctx, base);
	// lwz r6,4(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274ed9c
	if (cr6.eq) goto loc_8274ED9C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1264(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8275cf78
	ctx.lr = 0x8274ED8C;
	sub_8275CF78(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274ed9c
	if (!cr0.eq) goto loc_8274ED9C;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
loc_8274ED9C:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x8274edb0
	if (!cr6.lt) goto loc_8274EDB0;
loc_8274EDA4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274e2f0
	ctx.lr = 0x8274EDAC;
	sub_8274E2F0(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274EDB0:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8274EBC0) {
	__imp__sub_8274EBC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EDC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274EDC0) {
	__imp__sub_8274EDC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EDE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274EDE8) {
	__imp__sub_8274EDE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EE10) {
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
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274ee8c
	if (!cr6.eq) goto loc_8274EE8C;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274ee8c
	if (cr6.eq) goto loc_8274EE8C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
loc_8274EE3C:
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274ee54
	if (cr6.eq) goto loc_8274EE54;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x8274ee7c
	if (cr6.eq) goto loc_8274EE7C;
loc_8274EE54:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x8274ee3c
	if (cr6.lt) goto loc_8274EE3C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274EE68:
	// addi r11,r3,0
	r11.s64 = ctx.r3.s64 + 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
	// b 0x8274ee90
	goto loc_8274EE90;
loc_8274EE7C:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x8274EE88;
	sub_8274F988(ctx, base);
	// b 0x8274ee68
	goto loc_8274EE68;
loc_8274EE8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274EE90:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274EE10) {
	__imp__sub_8274EE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r11.s32);
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x82130b50
	sub_82130B50(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274EEA0) {
	__imp__sub_8274EEA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EEB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274EEB4) {
	__imp__sub_8274EEB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EEB8) {
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
	// bl 0x8244d150
	ctx.lr = 0x8274EED0;
	sub_8244D150(ctx, base);
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

PPC_WEAK_FUNC(sub_8274EEB8) {
	__imp__sub_8274EEB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EEE8) {
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
	// bl 0x823da950
	ctx.lr = 0x8274EF00;
	sub_823DA950(ctx, base);
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

PPC_WEAK_FUNC(sub_8274EEE8) {
	__imp__sub_8274EEE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EF18) {
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
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// bl 0x82753160
	ctx.lr = 0x8274EF2C;
	sub_82753160(ctx, base);
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

PPC_WEAK_FUNC(sub_8274EF18) {
	__imp__sub_8274EF18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EF40) {
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
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// bl 0x82753570
	ctx.lr = 0x8274EF54;
	sub_82753570(ctx, base);
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

PPC_WEAK_FUNC(sub_8274EF40) {
	__imp__sub_8274EF40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EF68) {
	PPC_FUNC_PROLOGUE();
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x821310f8
	sub_821310F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274EF68) {
	__imp__sub_8274EF68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274EF74) {
	__imp__sub_8274EF74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EF78) {
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
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4448
	ctx.r3.s64 = r11.s64 + -4448;
	// bl 0x827536c8
	ctx.lr = 0x8274EF90;
	sub_827536C8(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4248
	ctx.r3.s64 = r11.s64 + -4248;
	// bl 0x827536e0
	ctx.lr = 0x8274EF9C;
	sub_827536E0(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4424
	ctx.r3.s64 = r11.s64 + -4424;
	// bl 0x827536f8
	ctx.lr = 0x8274EFA8;
	sub_827536F8(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4376
	ctx.r3.s64 = r11.s64 + -4376;
	// bl 0x82753710
	ctx.lr = 0x8274EFB4;
	sub_82753710(ctx, base);
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r3,r11,-17464
	ctx.r3.s64 = r11.s64 + -17464;
	// bl 0x82753728
	ctx.lr = 0x8274EFC0;
	sub_82753728(ctx, base);
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r3,r11,-17688
	ctx.r3.s64 = r11.s64 + -17688;
	// bl 0x82753740
	ctx.lr = 0x8274EFCC;
	sub_82753740(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274EF78) {
	__imp__sub_8274EF78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274EFDC) {
	__imp__sub_8274EFDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274EFE0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8274ef78
	ctx.lr = 0x8274EFFC;
	sub_8274EF78(ctx, base);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753280
	ctx.lr = 0x8274F008;
	sub_82753280(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274f024
	if (cr0.eq) goto loc_8274F024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753160
	ctx.lr = 0x8274F018;
	sub_82753160(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8274f048
	goto loc_8274F048;
loc_8274F024:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// li r10,160
	ctx.r10.s64 = 160;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// addi r9,r31,384
	ctx.r9.s64 = r31.s64 + 384;
	// li r11,9
	r11.s64 = 9;
	// sth r10,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r10.u16);
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r11.u16);
loc_8274F048:
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

PPC_WEAK_FUNC(sub_8274EFE0) {
	__imp__sub_8274EFE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F060) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8274F068;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// addi r9,r31,28
	ctx.r9.s64 = r31.s64 + 28;
	// addi r23,r31,8
	r23.s64 = r31.s64 + 8;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r20,r24
	r20.u64 = r24.u64;
	// li r22,1
	r22.s64 = 1;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// lwz r25,8(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
loc_8274F0A4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f0e0
	if (cr6.eq) goto loc_8274F0E0;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// bne cr6,0x8274f0c8
	if (!cr6.eq) goto loc_8274F0C8;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8274f0cc
	goto loc_8274F0CC;
loc_8274F0C8:
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
loc_8274F0CC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f0e4
	if (cr6.eq) goto loc_8274F0E4;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// b 0x8274f0e4
	goto loc_8274F0E4;
loc_8274F0E0:
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
loc_8274F0E4:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274f0a4
	if (!cr0.eq) goto loc_8274F0A4;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// mr r22,r24
	r22.u64 = r24.u64;
	// b 0x8274f24c
	goto loc_8274F24C;
loc_8274F10C:
	// addi r21,r21,-1
	r21.s64 = r21.s64 + -1;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// addi r3,r31,400
	ctx.r3.s64 = r31.s64 + 400;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r6,r9,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x82751ca8
	ctx.lr = 0x8274F14C;
	sub_82751CA8(ctx, base);
	// stb r24,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r24.u8);
	// sth r24,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r24.u16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x82752ff8
	ctx.lr = 0x8274F164;
	sub_82752FF8(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f254
	if (!cr0.eq) goto loc_8274F254;
	// lhz r29,46(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// mr r22,r24
	r22.u64 = r24.u64;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// mr r27,r23
	r27.u64 = r23.u64;
	// li r26,2
	r26.s64 = 2;
loc_8274F180:
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f1f4
	if (cr6.eq) goto loc_8274F1F4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r31,384
	ctx.r4.s64 = r31.s64 + 384;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F1A8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f1c4
	if (!cr6.lt) goto loc_8274F1C4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F1C4:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f1f4
	if (!cr6.eq) goto loc_8274F1F4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F1E4;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274f1f4
	if (!cr0.eq) goto loc_8274F1F4;
	// addi r20,r20,-1
	r20.s64 = r20.s64 + -1;
loc_8274F1F4:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8274f180
	if (!cr0.eq) goto loc_8274F180;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f228
	if (!cr6.lt) goto loc_8274F228;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F228:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f24c
	if (!cr6.eq) goto loc_8274F24C;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F248;
	sub_8274F9A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_8274F24C:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8274f10c
	if (!cr6.eq) goto loc_8274F10C;
loc_8274F254:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8274F060) {
	__imp__sub_8274F060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F260) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8274ef78
	ctx.lr = 0x8274F27C;
	sub_8274EF78(ctx, base);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827536c0
	ctx.lr = 0x8274F288;
	sub_827536C0(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274f2a4
	if (cr0.eq) goto loc_8274F2A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753570
	ctx.lr = 0x8274F298;
	sub_82753570(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8274f2c0
	goto loc_8274F2C0;
loc_8274F2A4:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// addi r10,r31,704
	ctx.r10.s64 = r31.s64 + 704;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r9,40(r31)
	PPC_STORE_U16(r31.u32 + 40, ctx.r9.u16);
loc_8274F2C0:
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

PPC_WEAK_FUNC(sub_8274F260) {
	__imp__sub_8274F260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F2D8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8274F2E0;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addi r21,r31,28
	r21.s64 = r31.s64 + 28;
	// addi r20,r31,8
	r20.s64 = r31.s64 + 8;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r18,r23
	r18.u64 = r23.u64;
	// li r17,1
	r17.s64 = 1;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r22,8(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r23.u32);
loc_8274F31C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f358
	if (cr6.eq) goto loc_8274F358;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// bne cr6,0x8274f340
	if (!cr6.eq) goto loc_8274F340;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8274f344
	goto loc_8274F344;
loc_8274F340:
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8274F344:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f35c
	if (cr6.eq) goto loc_8274F35C;
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// b 0x8274f35c
	goto loc_8274F35C;
loc_8274F358:
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8274F35C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274f31c
	if (!cr0.eq) goto loc_8274F31C;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// mr r17,r23
	r17.u64 = r23.u64;
	// b 0x8274f564
	goto loc_8274F564;
loc_8274F384:
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r3,r31,704
	ctx.r3.s64 = r31.s64 + 704;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,24(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F3B8;
	sub_823DA950(ctx, base);
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// sth r23,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r23.u16);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// stw r28,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r28.u32);
	// sth r23,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r23.u16);
	// stb r23,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r23.u8);
loc_8274F3D0:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753408
	ctx.lr = 0x8274F3E0;
	sub_82753408(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi. r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f41c
	if (!cr0.eq) goto loc_8274F41C;
	// lhz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// sth r23,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r23.u16);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r11.u32);
	// bl 0x827534a0
	ctx.lr = 0x8274F410;
	sub_827534A0(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8274f3d0
	if (cr0.eq) goto loc_8274F3D0;
loc_8274F41C:
	// clrlwi. r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f56c
	if (!cr0.eq) goto loc_8274F56C;
	// li r11,160
	r11.s64 = 160;
	// lhz r24,42(r31)
	r24.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// li r5,320
	ctx.r5.s64 = 320;
	// sth r11,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r11.u16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823da950
	ctx.lr = 0x8274F440;
	sub_823DA950(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,160
	ctx.r6.s64 = 160;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x82751ca8
	ctx.lr = 0x8274F458;
	sub_82751CA8(ctx, base);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// mr r26,r20
	r26.u64 = r20.u64;
	// li r25,2
	r25.s64 = 2;
loc_8274F464:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f514
	if (cr6.eq) goto loc_8274F514;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,8000
	ctx.r10.s64 = 8000;
	// lhz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// mulli r9,r9,16000
	ctx.r9.s64 = ctx.r9.s64 * 16000;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// divw r10,r9,r10
	ctx.r10.s32 = ctx.r9.s32 / ctx.r10.s32;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// rlwinm r29,r10,1,0,30
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274f4ac
	if (cr6.lt) goto loc_8274F4AC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r29,r11,r10
	r29.s64 = ctx.r10.s64 - r11.s64;
loc_8274F4AC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F4C8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f4e4
	if (!cr6.lt) goto loc_8274F4E4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F4E4:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f514
	if (!cr6.eq) goto loc_8274F514;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F504;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274f514
	if (!cr0.eq) goto loc_8274F514;
	// addi r18,r18,-1
	r18.s64 = r18.s64 + -1;
loc_8274F514:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x8274f464
	if (!cr0.eq) goto loc_8274F464;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r24,r9
	ctx.r9.u64 = r24.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f540
	if (!cr6.lt) goto loc_8274F540;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F540:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f564
	if (!cr6.eq) goto loc_8274F564;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F560;
	sub_8274F9A8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274F564:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x8274f384
	if (!cr6.eq) goto loc_8274F384;
loc_8274F56C:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_8274F2D8) {
	__imp__sub_8274F2D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8274f58c
	if (!cr6.eq) goto loc_8274F58C;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x8274f598
	goto loc_8274F598;
loc_8274F58C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
loc_8274F598:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x8274fa28
	sub_8274FA28(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8274F578) {
	__imp__sub_8274F578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F5A0) {
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
	ctx.lr = 0x8274F5A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8274F5C0:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274f5d8
	if (cr6.eq) goto loc_8274F5D8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x8274f604
	if (cr6.eq) goto loc_8274F604;
loc_8274F5D8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x8274f5c0
	if (cr6.lt) goto loc_8274F5C0;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_8274F5EC:
	// subf r30,r29,r4
	r30.s64 = ctx.r4.s64 - r29.s64;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x8274f640
	if (cr6.eq) goto loc_8274F640;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274f638
	goto loc_8274F638;
loc_8274F604:
	// li r28,1
	r28.s64 = 1;
	// b 0x8274f5ec
	goto loc_8274F5EC;
loc_8274F60C:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f640
	if (cr6.eq) goto loc_8274F640;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F634;
	sub_8274F9A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8274F638:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274f60c
	if (!cr6.eq) goto loc_8274F60C;
loc_8274F640:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x8274f678
	if (!cr6.eq) goto loc_8274F678;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f670
	if (cr6.eq) goto loc_8274F670;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8274f6b8
	goto loc_8274F6B8;
loc_8274F670:
	// li r27,1
	r27.s64 = 1;
	// b 0x8274f6b8
	goto loc_8274F6B8;
loc_8274F678:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274f6b0
	goto loc_8274F6B0;
loc_8274F684:
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f6b8
	if (cr6.eq) goto loc_8274F6B8;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F6AC;
	sub_8274F9A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8274F6B0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274f684
	if (!cr6.eq) goto loc_8274F684;
loc_8274F6B8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8274F5A0) {
	__imp__sub_8274F5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274F6C4) {
	__imp__sub_8274F6C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F6C8) {
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
	ctx.lr = 0x8274F6D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f6f4
	if (cr6.eq) goto loc_8274F6F4;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_8274F6F4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274f700
	if (cr6.eq) goto loc_8274F700;
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
loc_8274F700:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// ori r31,r9,1
	r31.u64 = ctx.r9.u64 | 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f744
	if (cr6.eq) goto loc_8274F744;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F740;
	sub_8274F9A8(ctx, base);
	// b 0x8274f764
	goto loc_8274F764;
loc_8274F744:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
loc_8274F74C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F75C;
	sub_8274F9A8(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x8274f74c
	if (!cr0.eq) goto loc_8274F74C;
loc_8274F764:
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8274F768:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f7b0
	if (cr6.eq) goto loc_8274F7B0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274f784
	if (cr6.eq) goto loc_8274F784;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bne cr6,0x8274f7b0
	if (!cr6.eq) goto loc_8274F7B0;
loc_8274F784:
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8274f7c4
	if (!cr6.eq) goto loc_8274F7C4;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f7b0
	if (cr6.eq) goto loc_8274F7B0;
loc_8274F798:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F7A8;
	sub_8274F9A8(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x8274f798
	if (!cr0.eq) goto loc_8274F798;
loc_8274F7B0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// blt cr6,0x8274f768
	if (cr6.lt) goto loc_8274F768;
	// b 0x8274f7ec
	goto loc_8274F7EC;
loc_8274F7C4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f7ec
	if (cr6.eq) goto loc_8274F7EC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r10,r30,2
	ctx.r10.s64 = r30.s64 + 2;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwzx r3,r10,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F7EC;
	sub_8274F9A8(ctx, base);
loc_8274F7EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8274F6C8) {
	__imp__sub_8274F6C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F7F8) {
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
	ctx.lr = 0x8274F800;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f898
	if (cr6.eq) goto loc_8274F898;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x8274F820;
	sub_8274F6C8(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f84c
	if (cr6.eq) goto loc_8274F84C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f848
	if (cr6.eq) goto loc_8274F848;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274F848:
	// stw r28,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r28.u32);
loc_8274F84C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f860
	if (cr6.eq) goto loc_8274F860;
	// bl 0x8274fac8
	ctx.lr = 0x8274F85C;
	sub_8274FAC8(ctx, base);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274F860:
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// li r29,2
	r29.s64 = 2;
loc_8274F868:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f87c
	if (cr6.eq) goto loc_8274F87C;
	// bl 0x8274fac8
	ctx.lr = 0x8274F878;
	sub_8274FAC8(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_8274F87C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8274f868
	if (!cr0.eq) goto loc_8274F868;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// bl 0x821310f8
	ctx.lr = 0x8274F898;
	sub_821310F8(ctx, base);
loc_8274F898:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274F7F8) {
	__imp__sub_8274F7F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F8A0) {
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
	ctx.lr = 0x8274F8A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// bl 0x82130b50
	ctx.lr = 0x8274F8D0;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274f8e4
	if (!cr0.eq) goto loc_8274F8E4;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x8274f968
	goto loc_8274F968;
loc_8274F8E4:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8274fbb0
	ctx.lr = 0x8274F8F4;
	sub_8274FBB0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274f968
	if (cr0.lt) goto loc_8274F968;
	// li r27,0
	r27.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
loc_8274F904:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f920
	if (cr6.eq) goto loc_8274F920;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8274fbb0
	ctx.lr = 0x8274F918;
	sub_8274FBB0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274f968
	if (cr0.lt) goto loc_8274F968;
loc_8274F920:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplwi cr6,r27,2
	cr6.compare<uint32_t>(r27.u32, 2, xer);
	// blt cr6,0x8274f904
	if (cr6.lt) goto loc_8274F904;
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f95c
	if (cr6.eq) goto loc_8274F95C;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8274f960
	goto loc_8274F960;
loc_8274F95C:
	// li r30,1
	r30.s64 = 1;
loc_8274F960:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8274f974
	if (!cr6.lt) goto loc_8274F974;
loc_8274F968:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274f7f8
	ctx.lr = 0x8274F970;
	sub_8274F7F8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274F974:
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8274F8A0) {
	__imp__sub_8274F8A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274F984) {
	__imp__sub_8274F984(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F988) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8274f99c
	goto loc_8274F99C;
loc_8274F994:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8274F99C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274f994
	if (!cr6.eq) goto loc_8274F994;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274F988) {
	__imp__sub_8274F988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274F9A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,259
	cr6.compare<int32_t>(ctx.r9.s32, 259, xer);
	// bne cr6,0x8274f9c4
	if (!cr6.eq) goto loc_8274F9C4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_8274F9C4:
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// addi r11,r8,8
	r11.s64 = ctx.r8.s64 + 8;
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274fa00
	if (!cr6.eq) goto loc_8274FA00;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274fa00
	if (cr6.eq) goto loc_8274FA00;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bne cr6,0x8274f9f4
	if (!cr6.eq) goto loc_8274F9F4;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8274F9F4:
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
loc_8274FA00:
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274fa18
	if (cr6.eq) goto loc_8274FA18;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// b 0x8274fa1c
	goto loc_8274FA1C;
loc_8274FA18:
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_8274FA1C:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r4,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274F9A8) {
	__imp__sub_8274F9A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FA28) {
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
	ctx.lr = 0x8274FA30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274faa4
	if (cr6.eq) goto loc_8274FAA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8274fa5c
	if (!cr6.eq) goto loc_8274FA5C;
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274FA5C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274FA78;
	sub_8244D150(ctx, base);
	// li r10,259
	ctx.r10.s64 = 259;
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274fab0
	if (cr6.eq) goto loc_8274FAB0;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8274fab4
	goto loc_8274FAB4;
loc_8274FAA4:
	// lis r28,-32761
	r28.s64 = -2147024896;
	// ori r28,r28,122
	r28.u64 = r28.u64 | 122;
	// b 0x8274fab8
	goto loc_8274FAB8;
loc_8274FAB0:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8274FAB4:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_8274FAB8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8274FA28) {
	__imp__sub_8274FA28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274FAC4) {
	__imp__sub_8274FAC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FAC8) {
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
	// beq cr6,0x8274fb14
	if (cr6.eq) goto loc_8274FB14;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb04
	if (cr6.eq) goto loc_8274FB04;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x8274FAFC;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_8274FB04:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32773
	ctx.r4.u64 = ctx.r4.u64 | 32773;
	// bl 0x821310f8
	ctx.lr = 0x8274FB14;
	sub_821310F8(ctx, base);
loc_8274FB14:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8274FAC8) {
	__imp__sub_8274FAC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FB28) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274fb94
	if (cr6.eq) goto loc_8274FB94;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb68
	if (cr6.eq) goto loc_8274FB68;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274FB64;
	sub_821310F8(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8274FB68:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb84
	if (cr6.eq) goto loc_8274FB84;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x8274FB80;
	sub_821310F8(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_8274FB84:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32774
	ctx.r4.u64 = ctx.r4.u64 | 32774;
	// bl 0x821310f8
	ctx.lr = 0x8274FB94;
	sub_821310F8(ctx, base);
loc_8274FB94:
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

PPC_WEAK_FUNC(sub_8274FB28) {
	__imp__sub_8274FB28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274FBAC) {
	__imp__sub_8274FBAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FBB0) {
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
	ctx.lr = 0x8274FBB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// ori r4,r4,32773
	ctx.r4.u64 = ctx.r4.u64 | 32773;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274FBD8;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274fc04
	if (!cr0.eq) goto loc_8274FC04;
loc_8274FBE0:
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r28,r28,14
	r28.u64 = r28.u64 | 14;
	// bl 0x8274fac8
	ctx.lr = 0x8274FBF0;
	sub_8274FAC8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274FBF4:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8274FC04:
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x82130b50
	ctx.lr = 0x8274FC18;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// beq 0x8274fbe0
	if (cr0.eq) goto loc_8274FBE0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274fbf4
	if (cr6.eq) goto loc_8274FBF4;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8274FC30:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274fc5c
	if (cr6.eq) goto loc_8274FC5C;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// b 0x8274fc60
	goto loc_8274FC60;
loc_8274FC5C:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274FC60:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274fc30
	if (!cr6.eq) goto loc_8274FC30;
	// b 0x8274fbf4
	goto loc_8274FBF4;
}

PPC_WEAK_FUNC(sub_8274FBB0) {
	__imp__sub_8274FBB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FC70) {
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
	ctx.lr = 0x8274FC78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,12
	ctx.r3.s64 = 12;
	// ori r4,r4,32774
	ctx.r4.u64 = ctx.r4.u64 | 32774;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274FCA4;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8274fd34
	if (cr0.eq) goto loc_8274FD34;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mullw r26,r29,r30
	r26.s64 = int64_t(r29.s32) * int64_t(r30.s32);
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x8274FCC4;
	sub_82130B50(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mullw r3,r28,r30
	ctx.r3.s64 = int64_t(r28.s32) * int64_t(r30.s32);
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x82130b50
	ctx.lr = 0x8274FCD8;
	sub_82130B50(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274fd34
	if (cr6.eq) goto loc_8274FD34;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fd34
	if (cr6.eq) goto loc_8274FD34;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274fd48
	if (cr6.eq) goto loc_8274FD48;
	// subf r8,r27,r29
	ctx.r8.s64 = r29.s64 - r27.s64;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8274FD00:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r8.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// bne 0x8274fd00
	if (!cr0.eq) goto loc_8274FD00;
	// b 0x8274fd48
	goto loc_8274FD48;
loc_8274FD34:
	// lis r25,-32761
	r25.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r25,r25,14
	r25.u64 = r25.u64 | 14;
	// bl 0x8274fb28
	ctx.lr = 0x8274FD44;
	sub_8274FB28(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274FD48:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8274FC70) {
	__imp__sub_8274FC70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FD58) {
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
	// bl 0x82458098
	ctx.lr = 0x8274FD74;
	sub_82458098(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r10,328(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 328);
	// mulli r9,r11,1000
	ctx.r9.s64 = r11.s64 * 1000;
	// rotldi r11,r9,1
	r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 1);
	// divd r3,r9,r10
	ctx.r3.s64 = ctx.r9.s64 / ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// tdllei r10,0
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// tdlgei r11,-1
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

PPC_WEAK_FUNC(sub_8274FD58) {
	__imp__sub_8274FD58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274FDAC) {
	__imp__sub_8274FDAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FDB0) {
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
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274fe00
	if (cr6.eq) goto loc_8274FE00;
	// bl 0x8274fd58
	ctx.lr = 0x8274FDDC;
	sub_8274FD58(ctx, base);
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// blt cr6,0x8274fe00
	if (cr6.lt) goto loc_8274FE00;
	// li r30,1
	r30.s64 = 1;
	// std r11,56(r31)
	PPC_STORE_U64(r31.u32 + 56, r11.u64);
loc_8274FE00:
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

PPC_WEAK_FUNC(sub_8274FDB0) {
	__imp__sub_8274FDB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8274FE1C) {
	__imp__sub_8274FE1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FE20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// ld r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r8.u32 + 16);
	// lhz r11,32(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 32);
	// divdu r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 / ctx.r9.u64;
	// lhz r9,66(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 66);
	// std r6,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.r6.u64);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// srawi r10,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	ctx.r10.s64 = r11.s32 >> 12;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r11,4096
	ctx.r10.s64 = r11.s64 + 4096;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r10,r7,12
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 12;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r3,r9,12
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 12;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// rlwinm r7,r3,12,0,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFFFF000;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// bge cr6,0x8274fecc
	if (!cr6.lt) goto loc_8274FECC;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274feb8
	if (cr6.lt) goto loc_8274FEB8;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8274ff08
	if (!cr6.gt) goto loc_8274FF08;
loc_8274FEB8:
	// lwz r11,356(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 356);
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,356(r8)
	PPC_STORE_U32(ctx.r8.u32 + 356, r11.u32);
	// blr 
	return;
loc_8274FECC:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x8274fedc
	if (!cr6.lt) goto loc_8274FEDC;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8274feb8
	if (cr6.gt) goto loc_8274FEB8;
loc_8274FEDC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8274ff00
	if (!cr6.lt) goto loc_8274FF00;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8274fef4
	if (cr6.gt) goto loc_8274FEF4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8274ff10
	if (!cr6.gt) goto loc_8274FF10;
loc_8274FEF4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8274FEF8:
	// stw r6,356(r8)
	PPC_STORE_U32(ctx.r8.u32 + 356, ctx.r6.u32);
	// blr 
	return;
loc_8274FF00:
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8274ff10
	if (cr6.gt) goto loc_8274FF10;
loc_8274FF08:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274fef4
	if (cr6.lt) goto loc_8274FEF4;
loc_8274FF10:
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// ld r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r8.u32 + 16);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r11,r11,4096
	r11.s64 = r11.s64 + 4096;
	// srawi r9,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	ctx.r9.s64 = r11.s32 >> 12;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r9,r9,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mulli r11,r11,20
	r11.s64 = r11.s64 * 20;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r11.u64);
	// b 0x8274fef8
	goto loc_8274FEF8;
}

PPC_WEAK_FUNC(sub_8274FE20) {
	__imp__sub_8274FE20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8274FF48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r10,r3,372
	ctx.r10.s64 = ctx.r3.s64 + 372;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ffa8
	if (cr6.eq) goto loc_8274FFA8;
	// ld r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
loc_8274FF68:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ld r6,24(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// cmpld cr6,r7,r6
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r6.u64, xer);
	// blt cr6,0x8274ff88
	if (cr6.lt) goto loc_8274FF88;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ff68
	if (!cr6.eq) goto loc_8274FF68;
loc_8274FF88:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ffcc
	if (!cr6.eq) goto loc_8274FFCC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274ffa8
	if (cr6.eq) goto loc_8274FFA8;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,24(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// cmpld cr6,r11,r7
	cr6.compare<uint64_t>(r11.u64, ctx.r7.u64, xer);
	// beq cr6,0x8275000c
	if (cr6.eq) goto loc_8275000C;
loc_8274FFA8:
	// stw r3,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r3.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ffc0
	if (cr6.eq) goto loc_8274FFC0;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// b 0x8274ffc4
	goto loc_8274FFC4;
loc_8274FFC0:
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_8274FFC4:
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_8274FFCC:
	// ld r11,24(r8)
	r11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// cmpld cr6,r11,r7
	cr6.compare<uint64_t>(r11.u64, ctx.r7.u64, xer);
	// beq cr6,0x8275000c
	if (cr6.eq) goto loc_8275000C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8274fffc
	if (!cr6.eq) goto loc_8274FFFC;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x8274ffc4
	goto loc_8274FFC4;
loc_8274FFFC:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_8275000C:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8274FF48) {
	__imp__sub_8274FF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750018) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 64);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// std r9,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r9.u64);
	// addi r10,r3,372
	ctx.r10.s64 = ctx.r3.s64 + 372;
	// addi r7,r7,4096
	ctx.r7.s64 = ctx.r7.s64 + 4096;
	// stw r9,312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 312, ctx.r9.u32);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r9,304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 304, ctx.r9.u32);
	// srawi r8,r7,12
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 12;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,12,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x8275007c
	if (!cr6.eq) goto loc_8275007C;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_8275007C:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,364
	ctx.r7.s64 = ctx.r3.s64 + 364;
loc_82750094:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827500ac
	if (cr6.eq) goto loc_827500AC;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// b 0x827500b0
	goto loc_827500B0;
loc_827500AC:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_827500B0:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x827500d0
	if (!cr6.eq) goto loc_827500D0;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_827500D0:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x82750094
	if (!cr6.eq) goto loc_82750094;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82750018) {
	__imp__sub_82750018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827500E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827500F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// lhz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// lhz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f13,21560(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// subf r10,r8,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r8.s64;
	// fdiv f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 / f0.f64;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x82750140
	if (!cr6.lt) goto loc_82750140;
	// fdiv f12,f12,f0
	ctx.f12.f64 = ctx.f12.f64 / f0.f64;
	// b 0x82750144
	goto loc_82750144;
loc_82750140:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_82750144:
	// lfd f11,288(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 288);
	// fmul f0,f11,f0
	f0.f64 = ctx.f11.f64 * f0.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82750158
	if (cr6.lt) goto loc_82750158;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82750158:
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// addi r11,r10,10
	r11.s64 = ctx.r10.s64 + 10;
	// fmul f12,f0,f12
	ctx.f12.f64 = f0.f64 * ctx.f12.f64;
	// stfd f0,296(r31)
	PPC_STORE_U64(r31.u32 + 296, f0.u64);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r26,0
	r26.s64 = 0;
	// lfdx f0,r11,r31
	f0.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fmadd f0,f13,f0,f12
	f0.f64 = ctx.f13.f64 * f0.f64 + ctx.f12.f64;
	// stfdx f0,r11,r31
	PPC_STORE_U64(r11.u32 + r31.u32, f0.u64);
	// lfd f0,280(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 280);
	// stw r26,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r26.u32);
	// stw r26,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r26.u32);
	// lfdx f13,r11,r31
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827502b8
	if (!cr6.lt) goto loc_827502B8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// addi r11,r10,9
	r11.s64 = ctx.r10.s64 + 9;
	// fsub f13,f13,f0
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fsub f0,f12,f0
	f0.f64 = ctx.f12.f64 - f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	f0.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r28,372(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// addi r30,r31,372
	r30.s64 = r31.s64 + 372;
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// divdu r10,r11,r10
	ctx.r10.u64 = r11.u64 / ctx.r10.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// ld r29,24(r27)
	r29.u64 = PPC_LOAD_U64(r27.u32 + 24);
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// bl 0x8274f988
	ctx.lr = 0x82750204;
	sub_8274F988(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82750314
	if (cr0.eq) goto loc_82750314;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpld cr6,r11,r29
	cr6.compare<uint64_t>(r11.u64, r29.u64, xer);
	// ble cr6,0x82750314
	if (!cr6.gt) goto loc_82750314;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r29,20
	ctx.r10.s64 = r29.s64 + 20;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827502a8
	if (cr6.eq) goto loc_827502A8;
loc_8275022C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ld r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// cmpld cr6,r9,r10
	cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, xer);
	// bgt cr6,0x82750250
	if (cr6.gt) goto loc_82750250;
	// bne cr6,0x82750244
	if (!cr6.eq) goto loc_82750244;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82750244:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275022c
	if (!cr6.eq) goto loc_8275022C;
loc_82750250:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x827502a8
	if (cr6.eq) goto loc_827502A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750280
	if (cr6.eq) goto loc_82750280;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82750274
	if (!cr6.eq) goto loc_82750274;
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82750274:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_82750280:
	// stw r26,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r26.u32);
	// addi r11,r31,364
	r11.s64 = r31.s64 + 364;
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275029c
	if (cr6.eq) goto loc_8275029C;
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
	// b 0x827502a0
	goto loc_827502A0;
loc_8275029C:
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_827502A0:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// b 0x82750314
	goto loc_82750314;
loc_827502A8:
	// ld r11,24(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 24);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r11,24(r27)
	PPC_STORE_U64(r27.u32 + 24, r11.u64);
	// b 0x82750314
	goto loc_82750314;
loc_827502B8:
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// addi r11,r10,11
	r11.s64 = ctx.r10.s64 + 11;
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fsub f0,f12,f0
	f0.f64 = ctx.f12.f64 - f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	f0.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// addi r10,r11,-20
	ctx.r10.s64 = r11.s64 + -20;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// li r9,20
	ctx.r9.s64 = 20;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// divdu r10,r11,r9
	ctx.r10.u64 = r11.u64 / ctx.r9.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
loc_82750314:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_827500E8) {
	__imp__sub_827500E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275031C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275031C) {
	__imp__sub_8275031C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750320) {
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
	ctx.lr = 0x82750328;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r3,392(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// bl 0x8274f578
	ctx.lr = 0x82750360;
	sub_8274F578(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82750384
	if (!cr0.lt) goto loc_82750384;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x827503ac
	goto loc_827503AC;
loc_82750384:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,380
	r11.s64 = r29.s64 + 380;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lwz r10,384(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 384);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827503a4
	if (cr6.eq) goto loc_827503A4;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// b 0x827503a8
	goto loc_827503A8;
loc_827503A4:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_827503A8:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
loc_827503AC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82750320) {
	__imp__sub_82750320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827503B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827503B4) {
	__imp__sub_827503B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827503B8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82750414
	if (cr6.eq) goto loc_82750414;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827503f8
	if (cr6.eq) goto loc_827503F8;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x827503F4;
	sub_821310F8(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_827503F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8274fb28
	ctx.lr = 0x82750400;
	sub_8274FB28(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x821310f8
	ctx.lr = 0x82750414;
	sub_821310F8(ctx, base);
loc_82750414:
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

PPC_WEAK_FUNC(sub_827503B8) {
	__imp__sub_827503B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275042C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275042C) {
	__imp__sub_8275042C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750430) {
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
	ctx.lr = 0x82750438;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32768
	r28.s64 = -2147483648;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r28,r28,16389
	r28.u64 = r28.u64 | 16389;
	// bl 0x8274fdb0
	ctx.lr = 0x8275044C;
	sub_8274FDB0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x827505a4
	if (cr0.eq) goto loc_827505A4;
	// lwz r29,372(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 372);
	// addi r31,r30,372
	r31.s64 = r30.s64 + 372;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827505a0
	if (cr6.eq) goto loc_827505A0;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// ld r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// cmpld cr6,r9,r11
	cr6.compare<uint64_t>(ctx.r9.u64, r11.u64, xer);
	// beq cr6,0x8275051c
	if (cr6.eq) goto loc_8275051C;
	// lwz r11,316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 316);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,316(r30)
	PPC_STORE_U32(r30.u32 + 316, r11.u32);
	// lwz r11,352(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 352);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750598
	if (cr6.eq) goto loc_82750598;
	// lwz r31,364(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// addi r29,r30,364
	r29.s64 = r30.s64 + 364;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827505d8
	if (cr6.eq) goto loc_827505D8;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x827504b4
	if (!cr6.eq) goto loc_827504B4;
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_827504B4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r30,340
	ctx.r4.s64 = r30.s64 + 340;
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x827504D4;
	sub_823DA950(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,10
	r11.s64 = 10;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82750320
	ctx.lr = 0x827504EC;
	sub_82750320(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x82750590
	if (!cr0.lt) goto loc_82750590;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// bne cr6,0x827505b8
	if (!cr6.eq) goto loc_827505B8;
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_8275051C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750544
	if (cr6.eq) goto loc_82750544;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82750538
	if (!cr6.eq) goto loc_82750538;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
loc_82750538:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82750544:
	// addi r3,r30,340
	ctx.r3.s64 = r30.s64 + 340;
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x82750554;
	sub_823DA950(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,352(r30)
	PPC_STORE_U32(r30.u32 + 352, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82750320
	ctx.lr = 0x82750568;
	sub_82750320(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x827505ac
	if (!cr0.lt) goto loc_827505AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827505b8
	if (!cr6.eq) goto loc_827505B8;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_82750590:
	// stw r27,352(r30)
	PPC_STORE_U32(r30.u32 + 352, r27.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_82750598:
	// mr r28,r27
	r28.u64 = r27.u64;
	// b 0x827505b8
	goto loc_827505B8;
loc_827505A0:
	// stw r27,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r27.u32);
loc_827505A4:
	// std r27,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r27.u64);
	// b 0x827505b8
	goto loc_827505B8;
loc_827505AC:
	// ld r11,56(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 56);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r11,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r11.u64);
loc_827505B8:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827505d8
	if (cr6.lt) goto loc_827505D8;
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// lwz r10,320(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// stw r10,320(r30)
	PPC_STORE_U32(r30.u32 + 320, ctx.r10.u32);
loc_827505D8:
	// ld r11,56(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 56);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// ble cr6,0x827505ec
	if (!cr6.gt) goto loc_827505EC;
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// std r11,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r11.u64);
loc_827505EC:
	// lwz r31,380(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 380);
	// addi r29,r30,380
	r29.s64 = r30.s64 + 380;
	// b 0x82750694
	goto loc_82750694;
loc_827505F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8275069c
	if (cr6.eq) goto loc_8275069C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750630
	if (cr6.eq) goto loc_82750630;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82750624
	if (!cr6.eq) goto loc_82750624;
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_82750624:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82750630:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8244d150
	ctx.lr = 0x8275066C;
	sub_8244D150(ctx, base);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// addi r11,r30,364
	r11.s64 = r30.s64 + 364;
	// lwz r10,368(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750688
	if (cr6.eq) goto loc_82750688;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8275068c
	goto loc_8275068C;
loc_82750688:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8275068C:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82750694:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827505f8
	if (!cr6.eq) goto loc_827505F8;
loc_8275069C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82750430) {
	__imp__sub_82750430(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827506A8) {
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
	ctx.lr = 0x827506B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lhz r11,0(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r27,r11,31,21,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FF;
	// rlwinm r30,r11,20,12,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// bne cr6,0x8275073c
	if (!cr6.eq) goto loc_8275073C;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8275071c
	if (cr6.eq) goto loc_8275071C;
	// bl 0x8244fee8
	ctx.lr = 0x827506F0;
	sub_8244FEE8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// addi r11,r11,-21312
	r11.s64 = r11.s64 + -21312;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// bne cr6,0x82750714
	if (!cr6.eq) goto loc_82750714;
	// li r9,20
	ctx.r9.s64 = 20;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
loc_82750714:
	// std r10,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r10.u64);
	// b 0x82750728
	goto loc_82750728;
loc_8275071C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274fd58
	ctx.lr = 0x82750724;
	sub_8274FD58(ctx, base);
	// std r3,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r3.u64);
loc_82750728:
	// li r11,1
	r11.s64 = 1;
	// stb r30,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r30.u8);
	// sth r27,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r27.u16);
	// std r25,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r25.u64);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
loc_8275073C:
	// lbz r11,308(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 308);
	// clrlwi r29,r30,24
	r29.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x82750758
	if (cr6.eq) goto loc_82750758;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827500e8
	ctx.lr = 0x82750754;
	sub_827500E8(ctx, base);
	// stb r30,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r30.u8);
loc_82750758:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274fe20
	ctx.lr = 0x82750768;
	sub_8274FE20(ctx, base);
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
	// blt cr6,0x827507a8
	if (cr6.lt) goto loc_827507A8;
	// beq cr6,0x82750828
	if (cr6.eq) goto loc_82750828;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x82750860
	if (!cr6.lt) goto loc_82750860;
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8275085c
	if (!cr6.lt) goto loc_8275085C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82750018
	ctx.lr = 0x827507A0;
	sub_82750018(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8274fe20
	ctx.lr = 0x827507A8;
	sub_8274FE20(ctx, base);
loc_827507A8:
	// lwz r30,364(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// addi r29,r31,364
	r29.s64 = r31.s64 + 364;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8275085c
	if (cr6.eq) goto loc_8275085C;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x827507c8
	if (!cr6.eq) goto loc_827507C8;
	// stw r25,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r25.u32);
loc_827507C8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x827507F4;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r24.u32);
	// bl 0x8274ff48
	ctx.lr = 0x82750808;
	sub_8274FF48(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x82750860
	if (!cr0.lt) goto loc_82750860;
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750848
	if (cr6.eq) goto loc_82750848;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// b 0x8275084c
	goto loc_8275084C;
loc_82750828:
	// lbz r11,308(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 308);
	// li r28,1
	r28.s64 = 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82750860
	if (!cr6.eq) goto loc_82750860;
	// lwz r11,312(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r11.u32);
	// b 0x82750860
	goto loc_82750860;
loc_82750848:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_8275084C:
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
loc_8275085C:
	// li r28,1
	r28.s64 = 1;
loc_82750860:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_827506A8) {
	__imp__sub_827506A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275086C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275086C) {
	__imp__sub_8275086C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// li r8,20
	ctx.r8.s64 = 20;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,372(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// divdu r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 / ctx.r8.u64;
	// addi r8,r3,372
	ctx.r8.s64 = ctx.r3.s64 + 372;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// sth r9,64(r3)
	PPC_STORE_U16(ctx.r3.u32 + 64, ctx.r9.u16);
	// std r11,296(r3)
	PPC_STORE_U64(ctx.r3.u32 + 296, r11.u64);
	// stw r11,304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 304, r11.u32);
	// stb r11,308(r3)
	PPC_STORE_U8(ctx.r3.u32 + 308, r11.u8);
	// stw r11,312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 312, r11.u32);
	// beq cr6,0x82750908
	if (cr6.eq) goto loc_82750908;
	// addi r7,r3,364
	ctx.r7.s64 = ctx.r3.s64 + 364;
loc_827508B4:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827508dc
	if (cr6.eq) goto loc_827508DC;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// bne cr6,0x827508d0
	if (!cr6.eq) goto loc_827508D0;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
loc_827508D0:
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
loc_827508DC:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827508f4
	if (cr6.eq) goto loc_827508F4;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x827508f8
	goto loc_827508F8;
loc_827508F4:
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_827508F8:
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827508b4
	if (!cr6.eq) goto loc_827508B4;
loc_82750908:
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// li r11,25
	r11.s64 = 25;
loc_82750910:
	// ld r9,280(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 280);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x82750910
	if (!cr0.eq) goto loc_82750910;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82750870) {
	__imp__sub_82750870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750928) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82750930;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,400
	ctx.r3.s64 = 400;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x82130b50
	ctx.lr = 0x8275094C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82750960
	if (!cr0.eq) goto loc_82750960;
loc_82750954:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x82750ac4
	goto loc_82750AC4;
loc_82750960:
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stw r30,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r30.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// li r10,28
	ctx.r10.s64 = 28;
	// li r11,240
	r11.s64 = 240;
	// li r7,12
	ctx.r7.s64 = 12;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lfd f0,-1824(r9)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -1824);
	// li r6,4
	ctx.r6.s64 = 4;
	// lfd f13,-1832(r8)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r8.u32 + -1832);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,1
	ctx.r8.s64 = 1;
	// stfd f0,288(r31)
	PPC_STORE_U64(r31.u32 + 288, f0.u64);
	// stfd f13,280(r31)
	PPC_STORE_U64(r31.u32 + 280, ctx.f13.u64);
	// std r11,48(r31)
	PPC_STORE_U64(r31.u32 + 48, r11.u64);
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// addi r3,r31,328
	ctx.r3.s64 = r31.s64 + 328;
	// sth r7,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r7.u16);
	// sth r6,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r6.u16);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// stw r9,360(r31)
	PPC_STORE_U32(r31.u32 + 360, ctx.r9.u32);
	// stw r8,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r8.u32);
	// bl 0x82458060
	ctx.lr = 0x827509BC;
	sub_82458060(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x827509e4
	if (!cr0.eq) goto loc_827509E4;
	// bl 0x82135db0
	ctx.lr = 0x827509C8;
	sub_82135DB0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt 0x827509d8
	if (cr0.gt) goto loc_827509D8;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82750abc
	goto loc_82750ABC;
loc_827509D8:
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	r30.u64 = r11.u64 | 2147942400;
	// b 0x82750abc
	goto loc_82750ABC;
loc_827509E4:
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// li r11,25
	r11.s64 = 25;
loc_827509EC:
	// lfd f0,280(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 280);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfd f0,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, f0.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x827509ec
	if (!cr0.eq) goto loc_827509EC;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// bl 0x8274fc70
	ctx.lr = 0x82750A20;
	sub_8274FC70(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82750ac4
	if (cr0.lt) goto loc_82750AC4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130b50
	ctx.lr = 0x82750A3C;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// beq 0x82750954
	if (cr0.eq) goto loc_82750954;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750abc
	if (!cr6.gt) goto loc_82750ABC;
	// addi r7,r31,364
	ctx.r7.s64 = r31.s64 + 364;
	// li r11,0
	r11.s64 = 0;
loc_82750A60:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwx r10,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82750aa0
	if (cr6.eq) goto loc_82750AA0;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x82750aa4
	goto loc_82750AA4;
loc_82750AA0:
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_82750AA4:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x82750a60
	if (cr6.lt) goto loc_82750A60;
loc_82750ABC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82750ad0
	if (!cr6.lt) goto loc_82750AD0;
loc_82750AC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827503b8
	ctx.lr = 0x82750ACC;
	sub_827503B8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_82750AD0:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82750928) {
	__imp__sub_82750928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750AE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82750AE0) {
	__imp__sub_82750AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750AE8) {
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
	ctx.lr = 0x82750AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750b40
	if (!cr6.gt) goto loc_82750B40;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82750B10:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82750B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x82750b4c
	if (cr6.eq) goto loc_82750B4C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82750b10
	if (cr6.lt) goto loc_82750B10;
loc_82750B40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82750B44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82750B4C:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// b 0x82750b44
	goto loc_82750B44;
}

PPC_WEAK_FUNC(sub_82750AE8) {
	__imp__sub_82750AE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82750B5C) {
	__imp__sub_82750B5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750B60) {
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
	ctx.lr = 0x82750B68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x827bdc04
	ctx.lr = 0x82750B84;
	__imp__XamVoiceHeadsetPresent(ctx, base);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750ba0
	if (cr6.eq) goto loc_82750BA0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82750ba8
	if (cr6.eq) goto loc_82750BA8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82750bb0
	if (!cr6.eq) goto loc_82750BB0;
loc_82750BA0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82750bb0
	if (cr6.eq) goto loc_82750BB0;
loc_82750BA8:
	// li r28,1
	r28.s64 = 1;
	// li r27,1
	r27.s64 = 1;
loc_82750BB0:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lwz r11,1316(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82750bd0
	if (!cr6.eq) goto loc_82750BD0;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
loc_82750BD0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827bd314
	ctx.lr = 0x82750BD8;
	__imp__XamUserGetSigninState(ctx, base);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750dd0
	if (cr6.eq) goto loc_82750DD0;
	// addi r30,r31,148
	r30.s64 = r31.s64 + 148;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821326a8
	ctx.lr = 0x82750BFC;
	sub_821326A8(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82750d24
	if (cr6.eq) goto loc_82750D24;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82750d24
	if (!cr6.eq) goto loc_82750D24;
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750d50
	if (!cr6.gt) goto loc_82750D50;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
loc_82750C28:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addis r10,r10,-4100
	ctx.r10.s64 = ctx.r10.s64 + -268697600;
	// addic. r10,r10,-12
	xer.ca = ctx.r10.u32 > 11;
	ctx.r10.s64 = ctx.r10.s64 + -12;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82750ce8
	if (cr0.eq) goto loc_82750CE8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82750ca4
	if (cr6.eq) goto loc_82750CA4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x82750d08
	if (!cr6.eq) goto loc_82750D08;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// ble cr6,0x82750c68
	if (!cr6.gt) goto loc_82750C68;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
loc_82750C68:
	// lwa r10,32(r11)
	ctx.r10.s64 = int32_t(PPC_LOAD_U32(r11.u32 + 32));
	// lfs f0,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	f0.f64 = double(temp.f32);
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x82750d08
	if (cr6.eq) goto loc_82750D08;
	// stb r26,198(r31)
	PPC_STORE_U8(r31.u32 + 198, r26.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750CA4:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// beq cr6,0x82750cbc
	if (cr6.eq) goto loc_82750CBC;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// b 0x82750cc0
	goto loc_82750CC0;
loc_82750CBC:
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_82750CC0:
	// stw r10,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r10.u32);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// beq cr6,0x82750cdc
	if (cr6.eq) goto loc_82750CDC;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// b 0x82750ce0
	goto loc_82750CE0;
loc_82750CDC:
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
loc_82750CE0:
	// li r27,1
	r27.s64 = 1;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750CE8:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// beq cr6,0x82750d00
	if (cr6.eq) goto loc_82750D00;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750D00:
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_82750D04:
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
loc_82750D08:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// blt cr6,0x82750c28
	if (cr6.lt) goto loc_82750C28;
	// b 0x82750d50
	goto loc_82750D50;
loc_82750D24:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,997
	cr6.compare<uint32_t>(r11.u32, 997, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
loc_82750D34:
	// lis r11,2
	r11.s64 = 131072;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// li r28,1
	r28.s64 = 1;
loc_82750D50:
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x82750d90
	if (!cr6.eq) goto loc_82750D90;
loc_82750D58:
	// li r30,1128
	r30.s64 = 1128;
loc_82750D5C:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750d80
	if (cr6.eq) goto loc_82750D80;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82750d80
	if (cr6.eq) goto loc_82750D80;
	// bl 0x82752450
	ctx.lr = 0x82750D80;
	sub_82752450(ctx, base);
loc_82750D80:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r30,1264
	cr6.compare<uint32_t>(r30.u32, 1264, xer);
	// blt cr6,0x82750d5c
	if (cr6.lt) goto loc_82750D5C;
	// li r28,1
	r28.s64 = 1;
loc_82750D90:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x82750dc8
	if (!cr6.eq) goto loc_82750DC8;
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,184(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// bl 0x8274e020
	ctx.lr = 0x82750DC8;
	sub_8274E020(ctx, base);
loc_82750DC8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82750DD0:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82750d34
	if (cr6.eq) goto loc_82750D34;
	// addi r7,r31,148
	ctx.r7.s64 = r31.s64 + 148;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lis r3,-2
	ctx.r3.s64 = -131072;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r8,r11,-4896
	ctx.r8.s64 = r11.s64 + -4896;
	// addi r9,r31,180
	ctx.r9.s64 = r31.s64 + 180;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r3,r3,2001
	ctx.r3.u64 = ctx.r3.u64 | 2001;
	// bl 0x827bd324
	ctx.lr = 0x82750E0C;
	__imp__XamUserReadProfileSettings(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82750e38
	if (cr0.eq) goto loc_82750E38;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// beq cr6,0x82750e38
	if (cr6.eq) goto loc_82750E38;
	// lis r11,2
	r11.s64 = 131072;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82750e40
	if (cr6.eq) goto loc_82750E40;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// b 0x82750e40
	goto loc_82750E40;
loc_82750E38:
	// li r11,1
	r11.s64 = 1;
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
loc_82750E40:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,252
	ctx.r4.s64 = 252;
	// bl 0x827bd424
	ctx.lr = 0x82750E50;
	__imp__XamUserCheckPrivilege(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82750e94
	if (!cr0.eq) goto loc_82750E94;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82750e94
	if (cr6.eq) goto loc_82750E94;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,251
	ctx.r4.s64 = 251;
	// bl 0x827bd424
	ctx.lr = 0x82750E74;
	__imp__XamUserCheckPrivilege(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rldimi r11,r3,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// cmpldi cr6,r11,1
	cr6.compare<uint64_t>(r11.u64, 1, xer);
	// bne cr6,0x82750e8c
	if (!cr6.eq) goto loc_82750E8C;
	// lis r11,1
	r11.s64 = 65536;
	// b 0x82750e98
	goto loc_82750E98;
loc_82750E8C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82750e98
	goto loc_82750E98;
loc_82750E94:
	// lis r11,2
	r11.s64 = 131072;
loc_82750E98:
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r10,36(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82750eac
	if (cr6.eq) goto loc_82750EAC;
	// lis r11,2
	r11.s64 = 131072;
loc_82750EAC:
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// b 0x82750d58
	goto loc_82750D58;
}

PPC_WEAK_FUNC(sub_82750B60) {
	__imp__sub_82750B60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82750EC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82750EC8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r20,1
	r20.s64 = 1;
	// li r21,2
	r21.s64 = 2;
	// mr r29,r22
	r29.u64 = r22.u64;
	// addi r23,r27,72
	r23.s64 = r27.s64 + 72;
loc_82750EEC:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r20
	cr6.compare<int32_t>(r11.s32, r20.s32, xer);
	// bne cr6,0x82750f10
	if (!cr6.eq) goto loc_82750F10;
	// stwcx. r21,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r21.s32));
	cr0.so = xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82750eec
	if (!cr0.eq) goto loc_82750EEC;
	// b 0x82750f18
	goto loc_82750F18;
loc_82750F10:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82750F18:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8275109c
	if (!cr6.eq) goto loc_8275109C;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751098
	if (cr6.eq) goto loc_82751098;
	// lwz r11,196(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// rlwinm. r11,r11,0,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82751098
	if (cr0.eq) goto loc_82751098;
	// addi r26,r27,68
	r26.s64 = r27.s64 + 68;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// bl 0x827bd684
	ctx.lr = 0x82750F50;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,52(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 52);
	// addi r28,r27,52
	r28.s64 = r27.s64 + 52;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82750f80
	goto loc_82750F80;
loc_82750F60:
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// bge cr6,0x82750f88
	if (!cr6.lt) goto loc_82750F88;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
loc_82750F80:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82750f60
	if (!cr6.eq) goto loc_82750F60;
loc_82750F88:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd674
	ctx.lr = 0x82750F90;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// blt cr6,0x8275109c
	if (cr6.lt) goto loc_8275109C;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x8275108c
	goto loc_8275108C;
loc_82750FA0:
	// cmplw cr6,r29,r25
	cr6.compare<uint32_t>(r29.u32, r25.u32, xer);
	// bge cr6,0x8275109c
	if (!cr6.lt) goto loc_8275109C;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8275109c
	if (cr6.eq) goto loc_8275109C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r29,r25
	ctx.r9.s64 = r25.s64 - r29.s64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x82750fd8
	if (cr6.lt) goto loc_82750FD8;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
loc_82750FD8:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// add r4,r29,r24
	ctx.r4.u64 = r29.u64 + r24.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x82750FEC;
	sub_823DA950(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751008
	if (!cr6.lt) goto loc_82751008;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751008:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82751088
	if (!cr6.eq) goto loc_82751088;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd684
	ctx.lr = 0x82751024;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751050
	if (cr6.eq) goto loc_82751050;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82751044
	if (!cr6.eq) goto loc_82751044;
	// stw r22,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r22.u32);
loc_82751044:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
loc_82751050:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8275107c
	if (!cr6.eq) goto loc_8275107C;
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// addi r11,r27,60
	r11.s64 = r27.s64 + 60;
	// lwz r10,64(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751074
	if (cr6.eq) goto loc_82751074;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82751078
	goto loc_82751078;
loc_82751074:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82751078:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_8275107C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd674
	ctx.lr = 0x82751084;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_82751088:
	// add r29,r30,r29
	r29.u64 = r30.u64 + r29.u64;
loc_8275108C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82750fa0
	if (!cr6.eq) goto loc_82750FA0;
	// b 0x8275109c
	goto loc_8275109C;
loc_82751098:
	// mr r29,r25
	r29.u64 = r25.u64;
loc_8275109C:
	// li r10,3
	ctx.r10.s64 = 3;
loc_827510A0:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82751130
	if (!cr6.eq) goto loc_82751130;
	// stwcx. r22,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r22.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827510a0
	if (!cr0.eq) goto loc_827510A0;
	// b 0x82751138
	goto loc_82751138;
loc_827510C4:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r21
	cr6.compare<int32_t>(r11.s32, r21.s32, xer);
	// bne cr6,0x827510e8
	if (!cr6.eq) goto loc_827510E8;
	// stwcx. r20,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r20.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827510c4
	if (!cr0.eq) goto loc_827510C4;
	// b 0x827510f0
	goto loc_827510F0;
loc_827510E8:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827510F0:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
loc_8275110C:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82751130
	if (!cr6.eq) goto loc_82751130;
	// stwcx. r22,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r22.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8275110c
	if (!cr0.eq) goto loc_8275110C;
	// b 0x82751138
	goto loc_82751138;
loc_82751130:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82751138:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x827510c4
	if (!cr6.eq) goto loc_827510C4;
loc_82751144:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_82750EC0) {
	__imp__sub_82750EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x82751158;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// addi r30,r31,72
	r30.s64 = r31.s64 + 72;
	// bl 0x827bdc24
	ctx.lr = 0x82751170;
	__imp__XMsgCancelIORequest(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// b 0x827511f0
	goto loc_827511F0;
loc_8275117C:
	// li r11,2
	r11.s64 = 2;
	// li r8,3
	ctx.r8.s64 = 3;
loc_82751184:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r30
	reserved.u32 = *(uint32_t*)(base + r30.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x827511a8
	if (!cr6.eq) goto loc_827511A8;
	// stwcx. r8,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82751184
	if (!cr0.eq) goto loc_82751184;
	// b 0x827511b0
	goto loc_827511B0;
loc_827511A8:
	// stwcx. r10,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827511B0:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x827511fc
	if (cr6.eq) goto loc_827511FC;
	// li r11,1
	r11.s64 = 1;
loc_827511C0:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r30
	reserved.u32 = *(uint32_t*)(base + r30.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x827511e4
	if (!cr6.eq) goto loc_827511E4;
	// stwcx. r29,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(r29.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827511c0
	if (!cr0.eq) goto loc_827511C0;
	// b 0x827511ec
	goto loc_827511EC;
loc_827511E4:
	// stwcx. r10,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827511EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_827511F0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8275117c
	if (!cr6.eq) goto loc_8275117C;
	// b 0x82751208
	goto loc_82751208;
loc_827511FC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827511fc
	if (!cr6.eq) goto loc_827511FC;
loc_82751208:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275121c
	if (cr6.eq) goto loc_8275121C;
	// bl 0x827bdc14
	ctx.lr = 0x82751218;
	__imp__XamVoiceClose(ctx, base);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_8275121C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82754dd8
	ctx.lr = 0x82751224;
	sub_82754DD8(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751264
	if (!cr6.gt) goto loc_82751264;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_8275123C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8275123c
	if (cr6.lt) goto loc_8275123C;
loc_82751264:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82751150) {
	__imp__sub_82751150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275126C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275126C) {
	__imp__sub_8275126C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751270) {
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
	ctx.lr = 0x82751278;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827512d8
	if (cr6.eq) goto loc_827512D8;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_8275129C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82750ae8
	ctx.lr = 0x827512A8;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827512d8
	if (cr0.eq) goto loc_827512D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827512C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x827512d8
	if (cr0.lt) goto loc_827512D8;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8275129c
	if (cr6.lt) goto loc_8275129C;
loc_827512D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82751270) {
	__imp__sub_82751270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827512E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827512E4) {
	__imp__sub_827512E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827512E8) {
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
	ctx.lr = 0x827512F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82751350
	if (cr6.eq) goto loc_82751350;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_82751314:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82750ae8
	ctx.lr = 0x82751320;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82751350
	if (cr0.eq) goto loc_82751350;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82751350
	if (cr0.lt) goto loc_82751350;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x82751314
	if (cr6.lt) goto loc_82751314;
loc_82751350:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827512E8) {
	__imp__sub_827512E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275135C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275135C) {
	__imp__sub_8275135C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751360) {
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
	ctx.lr = 0x82751368;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82750b60
	ctx.lr = 0x82751374;
	sub_82750B60(ctx, base);
	// addi r24,r25,76
	r24.s64 = r25.s64 + 76;
	// li r26,0
	r26.s64 = 0;
	// lwz r31,76(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// b 0x82751428
	goto loc_82751428;
loc_82751384:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x82751430
	if (cr6.eq) goto loc_82751430;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827513bc
	if (cr6.eq) goto loc_827513BC;
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827513b0
	if (!cr6.eq) goto loc_827513B0;
	// stw r26,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r26.u32);
loc_827513B0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_827513BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x827513e0
	if (!cr6.eq) goto loc_827513E0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
loc_827513E0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r25,68
	r30.s64 = r25.s64 + 68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
	// bl 0x827bd684
	ctx.lr = 0x827513F4;
	__imp__KfAcquireSpinLock(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// lwz r10,56(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r11,r25,52
	r11.s64 = r25.s64 + 52;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751414
	if (cr6.eq) goto loc_82751414;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82751418
	goto loc_82751418;
loc_82751414:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82751418:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd674
	ctx.lr = 0x82751424;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_82751428:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82751384
	if (!cr6.eq) goto loc_82751384;
loc_82751430:
	// lwz r27,60(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 60);
	// addi r23,r25,60
	r23.s64 = r25.s64 + 60;
	// b 0x827515f0
	goto loc_827515F0;
loc_8275143C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf. r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82751614
	if (!cr0.eq) goto loc_82751614;
	// addi r31,r25,68
	r31.s64 = r25.s64 + 68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd684
	ctx.lr = 0x8275145C;
	__imp__KfAcquireSpinLock(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8274f988
	ctx.lr = 0x82751468;
	sub_8274F988(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82751480
	if (!cr0.eq) goto loc_82751480;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8274f988
	ctx.lr = 0x82751478;
	sub_8274F988(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// ble cr6,0x827515fc
	if (!cr6.gt) goto loc_827515FC;
loc_82751480:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827514a8
	if (cr6.eq) goto loc_827514A8;
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8275149c
	if (!cr6.eq) goto loc_8275149C;
	// stw r26,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r26.u32);
loc_8275149C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_827514A8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd674
	ctx.lr = 0x827514B4;
	__imp__KfReleaseSpinLock(ctx, base);
	// stw r26,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r26.u32);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827514cc
	if (cr6.eq) goto loc_827514CC;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// b 0x827514d0
	goto loc_827514D0;
loc_827514CC:
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
loc_827514D0:
	// stw r27,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r27.u32);
	// addi r28,r25,84
	r28.s64 = r25.s64 + 84;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// rlwinm. r11,r10,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x827515b8
	if (!cr0.gt) goto loc_827515B8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
loc_827514FC:
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// li r12,-7880
	r12.s64 = -7880;
	// addi r11,r10,-7880
	r11.s64 = ctx.r10.s64 + -7880;
	// sth r26,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r26.u16);
	// sth r26,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r26.u16);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r10,7880
	r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = r11.u64 & r12.u64;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// bl 0x82753758
	ctx.lr = 0x8275154C;
	sub_82753758(ctx, base);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// li r12,-7880
	r12.s64 = -7880;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// addi r11,r10,-7880
	r11.s64 = ctx.r10.s64 + -7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// addi r11,r10,7880
	r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = r11.u64 & r12.u64;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// bl 0x82753758
	ctx.lr = 0x82751598;
	sub_82753758(ctx, base);
	// lha r11,80(r1)
	r11.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 80));
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// rlwimi r10,r11,4,0,27
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xFFFFFFF0) | (ctx.r10.u64 & 0xFFFFFFFF0000000F);
	// stb r10,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x827514fc
	if (!cr0.eq) goto loc_827514FC;
loc_827515B8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r3,8(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// bl 0x827bdc34
	ctx.lr = 0x827515E4;
	__imp__XamVoiceSubmitPacket(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275160c
	if (cr0.lt) goto loc_8275160C;
	// lwz r27,0(r23)
	r27.u64 = PPC_LOAD_U32(r23.u32 + 0);
loc_827515F0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8275143c
	if (!cr6.eq) goto loc_8275143C;
	// b 0x82751614
	goto loc_82751614;
loc_827515FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r25,68
	ctx.r3.s64 = r25.s64 + 68;
	// bl 0x827bd674
	ctx.lr = 0x82751608;
	__imp__KfReleaseSpinLock(ctx, base);
	// b 0x82751614
	goto loc_82751614;
loc_8275160C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_82751614:
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// bl 0x82754e98
	ctx.lr = 0x8275161C;
	sub_82754E98(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x82751660
	if (cr0.lt) goto loc_82751660;
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// mr r30,r26
	r30.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751660
	if (!cr6.gt) goto loc_82751660;
	// addi r31,r25,12
	r31.s64 = r25.s64 + 12;
loc_82751638:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275164C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82751638
	if (cr6.lt) goto loc_82751638;
loc_82751660:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82751360) {
	__imp__sub_82751360(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275166C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275166C) {
	__imp__sub_8275166C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751670) {
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
	ctx.lr = 0x82751678;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// bl 0x82750ae8
	ctx.lr = 0x82751694;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827516bc
	if (cr0.eq) goto loc_827516BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827516B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_827516BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82751670) {
	__imp__sub_82751670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827516C8) {
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
	ctx.lr = 0x827516D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x827516EC;
	sub_8244D150(ctx, base);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8275175c
	if (!cr6.gt) goto loc_8275175C;
	// addi r31,r28,36
	r31.s64 = r28.s64 + 36;
loc_82751700:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r29,12(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
loc_82751714:
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275172c
	if (cr6.eq) goto loc_8275172C;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x82751764
	if (cr6.eq) goto loc_82751764;
loc_8275172C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// blt cr6,0x82751714
	if (cr6.lt) goto loc_82751714;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82751740:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r3,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r3.u32);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82751700
	if (cr6.lt) goto loc_82751700;
loc_8275175C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82751764:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x82751770;
	sub_8274F988(ctx, base);
	// b 0x82751740
	goto loc_82751740;
}

PPC_WEAK_FUNC(sub_827516C8) {
	__imp__sub_827516C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82751774) {
	__imp__sub_82751774(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751778) {
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
	ctx.lr = 0x82751780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751868
	if (cr6.eq) goto loc_82751868;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827517a8
	if (cr6.eq) goto loc_827517A8;
	// bl 0x827bdc14
	ctx.lr = 0x827517A4;
	__imp__XamVoiceClose(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
loc_827517A8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x827553d0
	ctx.lr = 0x827517B0;
	sub_827553D0(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r29,r28
	r29.u64 = r28.u64;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827517e8
	if (!cr6.gt) goto loc_827517E8;
	// addi r30,r31,36
	r30.s64 = r31.s64 + 36;
loc_827517C8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8274f7f8
	ctx.lr = 0x827517D0;
	sub_8274F7F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827517c8
	if (cr6.lt) goto loc_827517C8;
loc_827517E8:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751828
	if (!cr6.gt) goto loc_82751828;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_827517FC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827517fc
	if (cr6.lt) goto loc_827517FC;
loc_82751828:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x8274fb28
	ctx.lr = 0x82751830;
	sub_8274FB28(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// bl 0x827bdc24
	ctx.lr = 0x8275183C;
	__imp__XMsgCancelIORequest(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751858
	if (cr6.eq) goto loc_82751858;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x82751854;
	sub_821310F8(ctx, base);
	// stw r28,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r28.u32);
loc_82751858:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x821310f8
	ctx.lr = 0x82751868;
	sub_821310F8(ctx, base);
loc_82751868:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82751778) {
	__imp__sub_82751778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x82751878;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82751150
	ctx.lr = 0x82751888;
	sub_82751150(ctx, base);
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bdc44
	ctx.lr = 0x8275189C;
	__imp__XamVoiceCreate(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x82751900
	if (cr0.lt) goto loc_82751900;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x827554d0
	ctx.lr = 0x827518B0;
	sub_827554D0(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
loc_827518CC:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// stwcx. r8,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827518cc
	if (!cr0.eq) goto loc_827518CC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// addi r4,r11,-1808
	ctx.r4.s64 = r11.s64 + -1808;
	// li r5,54
	ctx.r5.s64 = 54;
	// bl 0x823da950
	ctx.lr = 0x827518F8;
	sub_823DA950(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x82751918
	if (!cr6.lt) goto loc_82751918;
loc_82751900:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751918
	if (cr6.eq) goto loc_82751918;
	// bl 0x827bdc14
	ctx.lr = 0x82751910;
	__imp__XamVoiceClose(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82751918:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82751870) {
	__imp__sub_82751870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82751924) {
	__imp__sub_82751924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751928) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82751930;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// li r3,464
	ctx.r3.s64 = 464;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// bl 0x82130b50
	ctx.lr = 0x82751954;
	sub_82130B50(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// li r20,0
	r20.s64 = 0;
	// bne 0x8275196c
	if (!cr0.eq) goto loc_8275196C;
loc_82751960:
	// lis r22,-32761
	r22.s64 = -2147024896;
	// ori r22,r22,14
	r22.u64 = r22.u64 | 14;
	// b 0x82751c88
	goto loc_82751C88;
loc_8275196C:
	// lis r11,2
	r11.s64 = 131072;
	// stw r19,144(r28)
	PPC_STORE_U32(r28.u32 + 144, r19.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r20,68(r28)
	PPC_STORE_U32(r28.u32 + 68, r20.u32);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// stw r20,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r20.u32);
	// addi r31,r28,180
	r31.s64 = r28.s64 + 180;
	// stw r11,196(r28)
	PPC_STORE_U32(r28.u32 + 196, r11.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r9,198(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 198);
	// lis r3,-2
	ctx.r3.s64 = -131072;
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// addi r8,r11,-4896
	ctx.r8.s64 = r11.s64 + -4896;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,255
	ctx.r4.s64 = 255;
	// ori r3,r3,2001
	ctx.r3.u64 = ctx.r3.u64 | 2001;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,184(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 184, temp.u32);
	// bl 0x827bd324
	ctx.lr = 0x827519D8;
	__imp__XamUserReadProfileSettings(ctx, base);
	// cmplwi cr6,r3,122
	cr6.compare<uint32_t>(ctx.r3.u32, 122, xer);
	// beq cr6,0x827519ec
	if (cr6.eq) goto loc_827519EC;
	// lis r22,-32768
	r22.s64 = -2147483648;
	// ori r22,r22,16389
	r22.u64 = r22.u64 | 16389;
	// b 0x82751c88
	goto loc_82751C88;
loc_827519EC:
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x827519FC;
	sub_82130B50(ctx, base);
	// stw r3,176(r28)
	PPC_STORE_U32(r28.u32 + 176, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82751960
	if (cr0.eq) goto loc_82751960;
	// addi r31,r28,48
	r31.s64 = r28.s64 + 48;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x8274fc70
	ctx.lr = 0x82751A24;
	sub_8274FC70(ctx, base);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c88
	if (cr0.lt) goto loc_82751C88;
	// addi r8,r28,52
	ctx.r8.s64 = r28.s64 + 52;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
loc_82751A34:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r10,24
	r11.s64 = ctx.r10.s64 + 24;
	// stw r10,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r10.u32);
	// stw r20,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r20.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751a68
	if (cr6.eq) goto loc_82751A68;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x82751a6c
	goto loc_82751A6C;
loc_82751A68:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_82751A6C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// cmplwi cr6,r9,5
	cr6.compare<uint32_t>(ctx.r9.u32, 5, xer);
	// blt cr6,0x82751a34
	if (cr6.lt) goto loc_82751A34;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8244d150
	ctx.lr = 0x82751A8C;
	sub_8244D150(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x82751A9C;
	sub_8244D150(ctx, base);
	// mr r30,r20
	r30.u64 = r20.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82751b30
	if (cr6.eq) goto loc_82751B30;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82751AAC:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bge cr6,0x82751b30
	if (!cr6.lt) goto loc_82751B30;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751AD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751b30
	if (cr0.lt) goto loc_82751B30;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751AF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// stwx r11,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r11,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r11.u32);
	// blt cr6,0x82751aac
	if (cr6.lt) goto loc_82751AAC;
loc_82751B30:
	// addi r11,r28,32
	r11.s64 = r28.s64 + 32;
	// stw r30,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r30.u32);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c88
	if (cr6.lt) goto loc_82751C88;
	// mr r25,r20
	r25.u64 = r20.u64;
	// mr r21,r20
	r21.u64 = r20.u64;
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
	// addi r23,r1,112
	r23.s64 = ctx.r1.s64 + 112;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_82751B54:
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mr r29,r20
	r29.u64 = r20.u64;
	// bl 0x8244d150
	ctx.lr = 0x82751B68;
	sub_8244D150(ctx, base);
	// addi r30,r1,104
	r30.s64 = ctx.r1.s64 + 104;
	// mr r24,r31
	r24.u64 = r31.u64;
	// li r27,2
	r27.s64 = 2;
loc_82751B74:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751ba4
	if (cr6.eq) goto loc_82751BA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_82751BA4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// bne 0x82751b74
	if (!cr0.eq) goto loc_82751B74;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82751c34
	if (cr6.eq) goto loc_82751C34;
	// addi r7,r26,4
	ctx.r7.s64 = r26.s64 + 4;
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8274f8a0
	ctx.lr = 0x82751BD0;
	sub_8274F8A0(ctx, base);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c48
	if (cr0.lt) goto loc_82751C48;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// mr r30,r20
	r30.u64 = r20.u64;
	// mr r29,r20
	r29.u64 = r20.u64;
loc_82751BE8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751c1c
	if (cr6.eq) goto loc_82751C1C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c48
	if (cr0.lt) goto loc_82751C48;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82751C1C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// blt cr6,0x82751be8
	if (cr6.lt) goto loc_82751BE8;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c48
	if (cr6.lt) goto loc_82751C48;
loc_82751C34:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// mr r31,r24
	r31.u64 = r24.u64;
	// cmplwi cr6,r21,3
	cr6.compare<uint32_t>(r21.u32, 3, xer);
	// blt cr6,0x82751b54
	if (cr6.lt) goto loc_82751B54;
loc_82751C48:
	// stw r25,44(r28)
	PPC_STORE_U32(r28.u32 + 44, r25.u32);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c88
	if (cr6.lt) goto loc_82751C88;
	// addi r8,r28,4
	ctx.r8.s64 = r28.s64 + 4;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// addi r6,r28,36
	ctx.r6.s64 = r28.s64 + 36;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82755560
	ctx.lr = 0x82751C70;
	sub_82755560(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r10,140(r28)
	PPC_STORE_U32(r28.u32 + 140, ctx.r10.u32);
	// bge 0x82751c94
	if (!cr0.lt) goto loc_82751C94;
loc_82751C88:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82751778
	ctx.lr = 0x82751C90;
	sub_82751778(ctx, base);
	// mr r28,r20
	r28.u64 = r20.u64;
loc_82751C94:
	// stw r28,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r28.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_82751928) {
	__imp__sub_82751928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82751CA4) {
	__imp__sub_82751CA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751CA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r31,1
	r31.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// blt cr6,0x82751d24
	if (cr6.lt) goto loc_82751D24;
	// beq cr6,0x82751ce8
	if (cr6.eq) goto loc_82751CE8;
	// cmplwi cr6,r7,3
	cr6.compare<uint32_t>(ctx.r7.u32, 3, xer);
	// blt cr6,0x82751cd8
	if (cr6.lt) goto loc_82751CD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82751e1c
	goto loc_82751E1C;
loc_82751CD8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r31,6
	r31.s64 = 6;
	// addi r5,r11,-4624
	ctx.r5.s64 = r11.s64 + -4624;
	// b 0x82751d30
	goto loc_82751D30;
loc_82751CE8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82751d18
	if (cr6.eq) goto loc_82751D18;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_82751CF8:
	// lhz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// sth r7,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bne 0x82751cf8
	if (!cr0.eq) goto loc_82751CF8;
loc_82751D18:
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// b 0x82751d28
	goto loc_82751D28;
loc_82751D24:
	// li r31,2
	r31.s64 = 2;
loc_82751D28:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r5,r11,-4880
	ctx.r5.s64 = r11.s64 + -4880;
loc_82751D30:
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82751e14
	if (cr6.eq) goto loc_82751E14;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfd f12,-1816(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + -1816);
	// lfd f13,-17600(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + -17600);
loc_82751D4C:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751d9c
	if (cr6.eq) goto loc_82751D9C;
	// mr r11,r31
	r11.u64 = r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
loc_82751D60:
	// lha r10,0(r7)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + 0));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r10,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f11,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// fmul f11,f11,f12
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64;
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// stfdx f11,r9,r3
	PPC_STORE_U64(ctx.r9.u32 + ctx.r3.u32, ctx.f11.u64);
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// stw r10,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, ctx.r10.u32);
	// bne 0x82751d60
	if (!cr0.eq) goto loc_82751D60;
loc_82751D9C:
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// li r11,32
	r11.s64 = 32;
loc_82751DA8:
	// rlwinm r30,r10,3,24,28
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// lfd f11,0(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lfdx f10,r30,r3
	ctx.f10.u64 = PPC_LOAD_U64(r30.u32 + ctx.r3.u32);
	// fmadd f0,f10,f11,f0
	f0.f64 = ctx.f10.f64 * ctx.f11.f64 + f0.f64;
	// bne 0x82751da8
	if (!cr0.eq) goto loc_82751DA8;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f0.u64);
	// lwz r10,-20(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// addi r11,r10,-32767
	r11.s64 = ctx.r10.s64 + -32767;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// clrlwi r10,r9,17
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFF;
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// addis r11,r10,1
	r11.s64 = ctx.r10.s64 + 65536;
	// addi r11,r11,-32768
	r11.s64 = r11.s64 + -32768;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// rlwinm r9,r11,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// sth r11,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, r11.u16);
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
	// blt cr6,0x82751d4c
	if (cr6.lt) goto loc_82751D4C;
loc_82751E14:
	// divwu r3,r8,r31
	ctx.r3.u32 = ctx.r8.u32 / r31.u32;
	// twllei r31,0
loc_82751E1C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82751CA8) {
	__imp__sub_82751CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82751E28) {
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
	ctx.lr = 0x82751E30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r24,r25,8
	r24.s64 = r25.s64 + 8;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// li r21,1
	r21.s64 = 1;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r27,8(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_82751E60:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82751e9c
	if (cr6.eq) goto loc_82751E9C;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// bne cr6,0x82751e84
	if (!cr6.eq) goto loc_82751E84;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x82751e88
	goto loc_82751E88;
loc_82751E84:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
loc_82751E88:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82751ea0
	if (cr6.eq) goto loc_82751EA0;
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// b 0x82751ea0
	goto loc_82751EA0;
loc_82751E9C:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
loc_82751EA0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82751e60
	if (!cr0.eq) goto loc_82751E60;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// b 0x82752010
	goto loc_82752010;
loc_82751EC8:
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
loc_82751EF4:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751f28
	if (cr6.eq) goto loc_82751F28;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// blt cr6,0x82751f28
	if (cr6.lt) goto loc_82751F28;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
loc_82751F28:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82751ef4
	if (!cr0.eq) goto loc_82751EF4;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r28,r24
	r28.u64 = r24.u64;
	// li r26,2
	r26.s64 = 2;
loc_82751F40:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751fc0
	if (cr6.eq) goto loc_82751FC0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x823da950
	ctx.lr = 0x82751F74;
	sub_823DA950(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751f90
	if (!cr6.lt) goto loc_82751F90;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751F90:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82751fc0
	if (!cr6.eq) goto loc_82751FC0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x82751FB0;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82751fc0
	if (!cr0.eq) goto loc_82751FC0;
	// addi r22,r22,-1
	r22.s64 = r22.s64 + -1;
loc_82751FC0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82751f40
	if (!cr0.eq) goto loc_82751F40;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751fec
	if (!cr6.lt) goto loc_82751FEC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751FEC:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82752010
	if (!cr6.eq) goto loc_82752010;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8275200C;
	sub_8274F9A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_82752010:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x82751ec8
	if (!cr6.eq) goto loc_82751EC8;
loc_82752018:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82751E28) {
	__imp__sub_82751E28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752024) {
	__imp__sub_82752024(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752028) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82752030;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,1
	r29.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplw cr6,r30,r7
	cr6.compare<uint32_t>(r30.u32, ctx.r7.u32, xer);
	// beq cr6,0x82752124
	if (cr6.eq) goto loc_82752124;
	// li r11,4
	r11.s64 = 4;
	// stb r29,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r29.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// addi r9,r31,36
	ctx.r9.s64 = r31.s64 + 36;
loc_8275209C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stb r8,-4(r11)
	PPC_STORE_U8(r11.u32 + -4, ctx.r8.u8);
	// cmplwi cr6,r6,65535
	cr6.compare<uint32_t>(ctx.r6.u32, 65535, xer);
	// stb r10,-3(r11)
	PPC_STORE_U8(r11.u32 + -3, ctx.r10.u8);
	// bgt cr6,0x827520c8
	if (cr6.gt) goto loc_827520C8;
	// lbz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// slw r5,r29,r10
	ctx.r5.u64 = ctx.r10.u8 & 0x20 ? 0 : (r29.u32 << (ctx.r10.u8 & 0x3F));
	// and. r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 & ctx.r5.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne 0x827520c8
	if (!cr0.eq) goto loc_827520C8;
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// b 0x827520cc
	goto loc_827520CC;
loc_827520C8:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_827520CC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8275209c
	if (cr6.lt) goto loc_8275209C;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827520f0
	if (cr6.eq) goto loc_827520F0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x823ea140
	ctx.lr = 0x827520F0;
	sub_823EA140(ctx, base);
loc_827520F0:
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82752104
	if (!cr6.eq) goto loc_82752104;
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// b 0x82752114
	goto loc_82752114;
loc_82752104:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ea0d8
	ctx.lr = 0x8275210C;
	sub_823EA0D8(ctx, base);
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
loc_82752114:
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x823ea218
	ctx.lr = 0x82752124;
	sub_823EA218(ctx, base);
loc_82752124:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82752028) {
	__imp__sub_82752028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8275214c
	if (cr6.eq) goto loc_8275214C;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// b 0x82752150
	goto loc_82752150;
loc_8275214C:
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_82752150:
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x823ea1a8
	sub_823EA1A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82752130) {
	__imp__sub_82752130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275215C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275215C) {
	__imp__sub_8275215C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752160) {
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
	ctx.lr = 0x82752168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827521b8
	if (!cr6.gt) goto loc_827521B8;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82752188:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275219C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x827521c4
	if (cr6.eq) goto loc_827521C4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752188
	if (cr6.lt) goto loc_82752188;
loc_827521B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827521BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827521C4:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// b 0x827521bc
	goto loc_827521BC;
}

PPC_WEAK_FUNC(sub_82752160) {
	__imp__sub_82752160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827521D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827521D4) {
	__imp__sub_827521D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827521D8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x827521E0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r11,4
	r11.s64 = 4;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r30,1
	r30.s64 = 1;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// ori r10,r10,48000
	ctx.r10.u64 = ctx.r10.u64 | 48000;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// stb r29,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r29.u8);
	// addi r26,r31,72
	r26.s64 = r31.s64 + 72;
	// stb r11,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r11.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stb r30,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r30.u8);
	// stb r11,121(r1)
	PPC_STORE_U8(ctx.r1.u32 + 121, r11.u8);
	// stb r30,122(r1)
	PPC_STORE_U8(ctx.r1.u32 + 122, r30.u8);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// beq cr6,0x82752270
	if (cr6.eq) goto loc_82752270;
	// bl 0x823ea140
	ctx.lr = 0x8275226C;
	sub_823EA140(ctx, base);
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
loc_82752270:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r24,r31,80
	r24.s64 = r31.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752288
	if (cr6.eq) goto loc_82752288;
	// bl 0x823ea140
	ctx.lr = 0x82752284;
	sub_823EA140(ctx, base);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
loc_82752288:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275229c
	if (cr6.eq) goto loc_8275229C;
	// bl 0x823ea140
	ctx.lr = 0x82752298;
	sub_823EA140(ctx, base);
	// stw r29,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r29.u32);
loc_8275229C:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r9,56(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_827522B8:
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,145
	ctx.r7.s64 = ctx.r1.s64 + 145;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r6,r1,148
	ctx.r6.s64 = ctx.r1.s64 + 148;
	// stbx r11,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, r11.u8);
	// stbx r11,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r11.u8);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stfsx f31,r9,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r6.u32, temp.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// blt cr6,0x827522b8
	if (cr6.lt) goto loc_827522B8;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823eaaf0
	ctx.lr = 0x827522F4;
	sub_823EAAF0(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752418
	if (cr0.lt) goto loc_82752418;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stb r30,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r30.u8);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stb r29,122(r1)
	PPC_STORE_U8(ctx.r1.u32 + 122, r29.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82752318:
	// addi r8,r11,9
	ctx.r8.s64 = r11.s64 + 9;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,145
	ctx.r6.s64 = ctx.r1.s64 + 145;
	// lwzx r8,r8,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// stbx r29,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r29.u8);
	// stbx r10,r9,r6
	PPC_STORE_U8(ctx.r9.u32 + ctx.r6.u32, ctx.r10.u8);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bgt cr6,0x8275235c
	if (cr6.gt) goto loc_8275235C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// slw r8,r30,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 << (r11.u8 & 0x3F));
	// and. r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8275235c
	if (!cr0.eq) goto loc_8275235C;
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// stfsx f31,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// b 0x82752364
	goto loc_82752364;
loc_8275235C:
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82752364:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x82752318
	if (cr6.lt) goto loc_82752318;
	// stw r25,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r25.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8275238c
	if (!cr6.eq) goto loc_8275238C;
	// lwz r25,0(r24)
	r25.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// b 0x8275239c
	goto loc_8275239C;
loc_8275238C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823ea0d8
	ctx.lr = 0x82752394;
	sub_823EA0D8(ctx, base);
	// stfs f31,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
loc_8275239C:
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823eaaf0
	ctx.lr = 0x827523AC;
	sub_823EAAF0(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752418
	if (cr0.lt) goto loc_82752418;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752410
	if (!cr6.gt) goto loc_82752410;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_827523C4:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827523E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x827523fc
	if (!cr0.lt) goto loc_827523FC;
	// lis r11,-32768
	r11.s64 = -2147483648;
	// ori r11,r11,16385
	r11.u64 = r11.u64 | 16385;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x82752410
	if (!cr6.eq) goto loc_82752410;
loc_827523FC:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x827523c4
	if (cr6.lt) goto loc_827523C4;
loc_82752410:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x82752440
	if (!cr6.lt) goto loc_82752440;
loc_82752418:
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275242c
	if (cr6.eq) goto loc_8275242C;
	// bl 0x823ea140
	ctx.lr = 0x82752428;
	sub_823EA140(ctx, base);
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
loc_8275242C:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752440
	if (cr6.eq) goto loc_82752440;
	// bl 0x823ea140
	ctx.lr = 0x8275243C;
	sub_823EA140(ctx, base);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
loc_82752440:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_827521D8) {
	__imp__sub_827521D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752450) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82752458;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r22,1
	r22.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r23,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r23.u8);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,3
	ctx.r8.s64 = 3;
	// lwz r10,76(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stb r22,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r22.u8);
	// stb r9,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r9.u8);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stb r8,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r8.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r7,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r7.u8);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stb r23,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r23.u8);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r22,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r22.u8);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// bne cr6,0x827526a0
	if (!cr6.eq) goto loc_827526A0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r30,68(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// li r31,1112
	r31.s64 = 1112;
	// stw r22,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r22.u32);
	// addi r21,r11,-1112
	r21.s64 = r11.s64 + -1112;
	// stw r22,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r22.u32);
	// stw r22,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r22.u32);
loc_827524F4:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8275252c
	if (cr6.eq) goto loc_8275252C;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r9,196(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// beq cr6,0x82752530
	if (cr6.eq) goto loc_82752530;
loc_8275252C:
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
loc_82752530:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82752588
	if (cr6.eq) goto loc_82752588;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,196(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// rlwinm. r10,r10,0,12,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82752584
	if (cr0.eq) goto loc_82752584;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82752558
	if (!cr6.eq) goto loc_82752558;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82752588
	if (cr6.eq) goto loc_82752588;
loc_82752558:
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x827bd414
	ctx.lr = 0x82752578;
	__imp__XamUserAreUsersFriends(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82752588
	if (!cr6.eq) goto loc_82752588;
loc_82752584:
	// stwx r23,r21,r31
	PPC_STORE_U32(r21.u32 + r31.u32, r23.u32);
loc_82752588:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r31,1128
	cr6.compare<uint32_t>(r31.u32, 1128, xer);
	// blt cr6,0x827524f4
	if (cr6.lt) goto loc_827524F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r26,r23
	r26.u64 = r23.u64;
	// addi r25,r1,132
	r25.s64 = ctx.r1.s64 + 132;
	// li r31,1112
	r31.s64 = 1112;
	// addi r24,r28,-1076
	r24.s64 = r28.s64 + -1076;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_827525AC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827525d0
	if (cr6.eq) goto loc_827525D0;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r27,r22
	r27.u64 = r22.u64;
	// lwz r9,192(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x827525d4
	if (!cr6.eq) goto loc_827525D4;
loc_827525D0:
	// mr r27,r23
	r27.u64 = r23.u64;
loc_827525D4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82752664
	if (cr6.eq) goto loc_82752664;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827525f4
	if (!cr0.eq) goto loc_827525F4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x82752664
	if (!cr6.eq) goto loc_82752664;
loc_827525F4:
	// mr r30,r23
	r30.u64 = r23.u64;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
loc_827525FC:
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// beq cr6,0x82752654
	if (cr6.eq) goto loc_82752654;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82752654
	if (!cr6.eq) goto loc_82752654;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82752650
	if (cr0.eq) goto loc_82752650;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82752650
	if (cr6.eq) goto loc_82752650;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,196(r11)
	PPC_STORE_U32(r11.u32 + 196, ctx.r10.u32);
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r4,r31,r3
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// bl 0x8274e020
	ctx.lr = 0x8275264C;
	sub_8274E020(ctx, base);
	// b 0x82752654
	goto loc_82752654;
loc_82752650:
	// stwx r23,r31,r21
	PPC_STORE_U32(r31.u32 + r21.u32, r23.u32);
loc_82752654:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x827525fc
	if (cr6.lt) goto loc_827525FC;
loc_82752664:
	// lwzx r11,r31,r21
	r11.u64 = PPC_LOAD_U32(r31.u32 + r21.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82752680
	if (cr6.eq) goto loc_82752680;
	// lwzx r11,r24,r31
	r11.u64 = PPC_LOAD_U32(r24.u32 + r31.u32);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bgt cr6,0x82752680
	if (cr6.gt) goto loc_82752680;
	// stfs f31,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
loc_82752680:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// cmplwi cr6,r31,1128
	cr6.compare<uint32_t>(r31.u32, 1128, xer);
	// blt cr6,0x827525ac
	if (cr6.lt) goto loc_827525AC;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,72(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// bl 0x823ea270
	ctx.lr = 0x827526A0;
	sub_823EA270(ctx, base);
loc_827526A0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82752450) {
	__imp__sub_82752450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827526AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827526AC) {
	__imp__sub_827526AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827526B0) {
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
	ctx.lr = 0x827526B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275278c
	if (cr6.eq) goto loc_8275278C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752700
	if (!cr6.gt) goto loc_82752700;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
loc_827526E0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8274f7f8
	ctx.lr = 0x827526E8;
	sub_8274F7F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827526e0
	if (cr6.lt) goto loc_827526E0;
loc_82752700:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752740
	if (!cr6.gt) goto loc_82752740;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752714:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752714
	if (cr6.lt) goto loc_82752714;
loc_82752740:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752754
	if (cr6.eq) goto loc_82752754;
	// bl 0x823ea140
	ctx.lr = 0x82752750;
	sub_823EA140(ctx, base);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
loc_82752754:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752768
	if (cr6.eq) goto loc_82752768;
	// bl 0x823ea140
	ctx.lr = 0x82752764;
	sub_823EA140(ctx, base);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
loc_82752768:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275277c
	if (cr6.eq) goto loc_8275277C;
	// bl 0x823ea140
	ctx.lr = 0x82752778;
	sub_823EA140(ctx, base);
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
loc_8275277C:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// bl 0x821310f8
	ctx.lr = 0x8275278C;
	sub_821310F8(ctx, base);
loc_8275278C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827526B0) {
	__imp__sub_827526B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752794) {
	__imp__sub_82752794(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752798) {
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
	ctx.lr = 0x827527A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827527fc
	if (!cr6.gt) goto loc_827527FC;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
loc_827527BC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x8274e118
	ctx.lr = 0x827527D8;
	sub_8274E118(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8274f5a0
	ctx.lr = 0x827527E8;
	sub_8274F5A0(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827527bc
	if (cr6.lt) goto loc_827527BC;
loc_827527FC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752838
	if (!cr6.gt) goto loc_82752838;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752810:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752810
	if (cr6.lt) goto loc_82752810;
loc_82752838:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82752798) {
	__imp__sub_82752798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752844) {
	__imp__sub_82752844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752848) {
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
	ctx.lr = 0x82752850;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827528b0
	if (cr6.eq) goto loc_827528B0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_82752874:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752160
	ctx.lr = 0x82752880;
	sub_82752160(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827528b0
	if (cr0.eq) goto loc_827528B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x827528b0
	if (cr0.lt) goto loc_827528B0;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x82752874
	if (cr6.lt) goto loc_82752874;
loc_827528B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82752848) {
	__imp__sub_82752848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827528BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827528BC) {
	__imp__sub_827528BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827528C0) {
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
	ctx.lr = 0x827528C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82752928
	if (cr6.eq) goto loc_82752928;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_827528EC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752160
	ctx.lr = 0x827528F8;
	sub_82752160(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82752928
	if (cr0.eq) goto loc_82752928;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752928
	if (cr0.lt) goto loc_82752928;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x827528ec
	if (cr6.lt) goto loc_827528EC;
loc_82752928:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827528C0) {
	__imp__sub_827528C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752934) {
	__imp__sub_82752934(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752938) {
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
	ctx.lr = 0x82752940;
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
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x8244d150
	ctx.lr = 0x8275296C;
	sub_8244D150(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stb r26,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r26.u8);
	// bne cr6,0x827529a0
	if (!cr6.eq) goto loc_827529A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827529a0
	if (!cr6.eq) goto loc_827529A0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752028
	ctx.lr = 0x8275298C;
	sub_82752028(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x827529bc
	if (!cr6.eq) goto loc_827529BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752450
	ctx.lr = 0x8275299C;
	sub_82752450(ctx, base);
	// b 0x827529bc
	goto loc_827529BC;
loc_827529A0:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827521d8
	ctx.lr = 0x827529B4;
	sub_827521D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x827529cc
	if (cr0.lt) goto loc_827529CC;
loc_827529BC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r27,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r27.u64);
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
loc_827529CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82752938) {
	__imp__sub_82752938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827529D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827529D4) {
	__imp__sub_827529D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827529D8) {
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
	ctx.lr = 0x827529E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x827529F4;
	sub_8244D150(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752a30
	if (!cr6.gt) goto loc_82752A30;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752A08:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752a08
	if (cr6.lt) goto loc_82752A08;
loc_82752A30:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752a48
	if (cr6.eq) goto loc_82752A48;
	// bl 0x823ea140
	ctx.lr = 0x82752A40;
	sub_823EA140(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_82752A48:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827529D8) {
	__imp__sub_827529D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752A60) {
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
	ctx.lr = 0x82752A68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r30,-32768
	r30.s64 = -2147483648;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r4,-1840(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// ori r30,r30,16389
	r30.u64 = r30.u64 | 16389;
	// bl 0x82752160
	ctx.lr = 0x82752A8C;
	sub_82752160(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x82752ac8
	if (cr0.eq) goto loc_82752AC8;
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82752ab4
	if (cr6.eq) goto loc_82752AB4;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752450
	ctx.lr = 0x82752AB4;
	sub_82752450(ctx, base);
loc_82752AB4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8274cfd0
	ctx.lr = 0x82752AC4;
	sub_8274CFD0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82752AC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82752A60) {
	__imp__sub_82752A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752AD4) {
	__imp__sub_82752AD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752AD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,9
	r11.s64 = ctx.r4.s64 + 9;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// beq cr6,0x82752afc
	if (cr6.eq) goto loc_82752AFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
loc_82752AFC:
	// b 0x82752450
	sub_82752450(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82752AD8) {
	__imp__sub_82752AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752B00) {
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
	ctx.lr = 0x82752B08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752b60
	if (!cr6.gt) goto loc_82752B60;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82752B2C:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752B40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82752b4c
	if (!cr6.eq) goto loc_82752B4C;
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_82752B4C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752b2c
	if (cr6.lt) goto loc_82752B2C;
loc_82752B60:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82752b78
	if (cr6.eq) goto loc_82752B78;
	// li r11,200
	r11.s64 = 200;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x82752bac
	goto loc_82752BAC;
loc_82752B78:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82752bac
	if (!cr6.gt) goto loc_82752BAC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82752ba8
	if (cr6.eq) goto loc_82752BA8;
	// bl 0x8244fee8
	ctx.lr = 0x82752B94;
	sub_8244FEE8(ctx, base);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
loc_82752BA8:
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_82752BAC:
	// bl 0x8244fee8
	ctx.lr = 0x82752BB0;
	sub_8244FEE8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82752B00) {
	__imp__sub_82752B00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752BC0) {
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
	ctx.lr = 0x82752BC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x82752BE4;
	sub_8244D150(ctx, base);
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752c54
	if (!cr6.gt) goto loc_82752C54;
	// addi r31,r28,24
	r31.s64 = r28.s64 + 24;
loc_82752BF8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r29,12(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
loc_82752C0C:
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82752c24
	if (cr6.eq) goto loc_82752C24;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x82752c5c
	if (cr6.eq) goto loc_82752C5C;
loc_82752C24:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// blt cr6,0x82752c0c
	if (cr6.lt) goto loc_82752C0C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82752C38:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r3,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r3.u32);
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752bf8
	if (cr6.lt) goto loc_82752BF8;
loc_82752C54:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82752C5C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x82752C68;
	sub_8274F988(ctx, base);
	// b 0x82752c38
	goto loc_82752C38;
}

PPC_WEAK_FUNC(sub_82752BC0) {
	__imp__sub_82752BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752C6C) {
	__imp__sub_82752C6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752C70) {
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
	ctx.lr = 0x82752C78;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// mr r17,r8
	r17.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x82752CA8;
	sub_82130B50(ctx, base);
	// mr. r25,r3
	r25.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x82752cbc
	if (!cr0.eq) goto loc_82752CBC;
	// lis r26,-32761
	r26.s64 = -2147024896;
	// ori r26,r26,14
	r26.u64 = r26.u64 | 14;
	// b 0x82752ebc
	goto loc_82752EBC;
loc_82752CBC:
	// li r11,0
	r11.s64 = 0;
	// stw r20,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r20.u32);
	// li r5,24
	ctx.r5.s64 = 24;
	// stw r11,68(r25)
	PPC_STORE_U32(r25.u32 + 68, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x82752CD8;
	sub_8244D150(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x82752CE8;
	sub_8244D150(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82752d7c
	if (cr6.eq) goto loc_82752D7C;
	// addi r31,r25,12
	r31.s64 = r25.s64 + 12;
loc_82752CF8:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bge cr6,0x82752d7c
	if (!cr6.lt) goto loc_82752D7C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752d7c
	if (cr0.lt) goto loc_82752D7C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752D3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// stwx r11,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r11,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r11.u32);
	// blt cr6,0x82752cf8
	if (cr6.lt) goto loc_82752CF8;
loc_82752D7C:
	// addi r11,r25,20
	r11.s64 = r25.s64 + 20;
	// stw r30,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r30.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752ebc
	if (cr6.lt) goto loc_82752EBC;
	// li r24,0
	r24.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// addi r22,r1,96
	r22.s64 = ctx.r1.s64 + 96;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_82752DA0:
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// li r29,0
	r29.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x82752DB4;
	sub_8244D150(ctx, base);
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// mr r23,r31
	r23.u64 = r31.u64;
	// li r28,2
	r28.s64 = 2;
loc_82752DC0:
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752df0
	if (cr6.eq) goto loc_82752DF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_82752DF0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// bne 0x82752dc0
	if (!cr0.eq) goto loc_82752DC0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82752e80
	if (cr6.eq) goto loc_82752E80;
	// addi r7,r27,4
	ctx.r7.s64 = r27.s64 + 4;
	// lwz r4,0(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8274f8a0
	ctx.lr = 0x82752E1C;
	sub_8274F8A0(ctx, base);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752e94
	if (cr0.lt) goto loc_82752E94;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// li r30,0
	r30.s64 = 0;
	// li r29,0
	r29.s64 = 0;
loc_82752E34:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752e68
	if (cr6.eq) goto loc_82752E68;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752e94
	if (cr0.lt) goto loc_82752E94;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82752E68:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// blt cr6,0x82752e34
	if (cr6.lt) goto loc_82752E34;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752e94
	if (cr6.lt) goto loc_82752E94;
loc_82752E80:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// mr r31,r23
	r31.u64 = r23.u64;
	// cmplwi cr6,r21,3
	cr6.compare<uint32_t>(r21.u32, 3, xer);
	// blt cr6,0x82752da0
	if (cr6.lt) goto loc_82752DA0;
loc_82752E94:
	// stw r24,32(r25)
	PPC_STORE_U32(r25.u32 + 32, r24.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752ebc
	if (cr6.lt) goto loc_82752EBC;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827521d8
	ctx.lr = 0x82752EB4;
	sub_827521D8(ctx, base);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bge 0x82752ec8
	if (!cr0.lt) goto loc_82752EC8;
loc_82752EBC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827526b0
	ctx.lr = 0x82752EC4;
	sub_827526B0(ctx, base);
	// li r25,0
	r25.s64 = 0;
loc_82752EC8:
	// stw r25,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r25.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_82752C70) {
	__imp__sub_82752C70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752ED8) {
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
	ctx.lr = 0x82752EE0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82752efc
	if (!cr6.eq) goto loc_82752EFC;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752EFC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82752f10
	if (!cr6.eq) goto loc_82752F10;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F10:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82752f24
	if (!cr6.eq) goto loc_82752F24;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F24:
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82752f3c
	if (cr6.lt) goto loc_82752F3C;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F3C:
	// lhz r10,18(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// addi r29,r31,18
	r29.s64 = r31.s64 + 18;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82752f54
	if (cr6.lt) goto loc_82752F54;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F54:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// ble cr6,0x82752f68
	if (!cr6.gt) goto loc_82752F68;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F68:
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// ble cr6,0x82752f80
	if (!cr6.gt) goto loc_82752F80;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F80:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82752fe8
	if (cr6.eq) goto loc_82752FE8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82752fe8
	if (!cr6.eq) goto loc_82752FE8;
	// lbz r11,12(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 12);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82752fa8
	if (cr6.eq) goto loc_82752FA8;
	// li r3,6110
	ctx.r3.s64 = 6110;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752FA8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x82755e70
	ctx.lr = 0x82752FB4;
	sub_82755E70(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x827556f8
	ctx.lr = 0x82752FC4;
	sub_827556F8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lhz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82755688
	ctx.lr = 0x82752FE0;
	sub_82755688(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752FE8:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82752FEC:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82752ED8) {
	__imp__sub_82752ED8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82752FF4) {
	__imp__sub_82752FF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82752FF8) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82458098
	ctx.lr = 0x8275301C;
	sub_82458098(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752ed8
	ctx.lr = 0x82753028;
	sub_82752ED8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82458098
	ctx.lr = 0x82753034;
	sub_82458098(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,-22784
	r11.s64 = r11.s64 + -22784;
	// ld r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// bge cr6,0x82753058
	if (!cr6.lt) goto loc_82753058;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
loc_82753058:
	// ld r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// ble cr6,0x82753068
	if (!cr6.gt) goto loc_82753068;
	// std r10,16(r11)
	PPC_STORE_U64(r11.u32 + 16, ctx.r10.u64);
loc_82753068:
	// ld r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82752FF8) {
	__imp__sub_82752FF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275309C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275309C) {
	__imp__sub_8275309C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827530A0) {
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
	ctx.lr = 0x827530A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827530c0
	if (!cr6.eq) goto loc_827530C0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82753158
	goto loc_82753158;
loc_827530C0:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82753154
	if (cr6.eq) goto loc_82753154;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82753154
	if (!cr6.eq) goto loc_82753154;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x827530ec
	if (cr6.eq) goto loc_827530EC;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82753158
	goto loc_82753158;
loc_827530EC:
	// li r29,0
	r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x827558c0
	ctx.lr = 0x827530FC;
	sub_827558C0(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275311c
	if (cr6.eq) goto loc_8275311C;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_8275311C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82753138
	if (cr6.eq) goto loc_82753138;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_82753138:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
	// b 0x82753158
	goto loc_82753158;
loc_82753154:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82753158:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827530A0) {
	__imp__sub_827530A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753160) {
	PPC_FUNC_PROLOGUE();
	// b 0x827530a0
	sub_827530A0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82753160) {
	__imp__sub_82753160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82753164) {
	__imp__sub_82753164(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753168) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8275318c
	if (!cr6.eq) goto loc_8275318C;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x8275326c
	goto loc_8275326C;
loc_8275318C:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21248(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21240);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82753218
	if (!cr0.eq) goto loc_82753218;
loc_82753210:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x8275326c
	goto loc_8275326C;
loc_82753218:
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r9,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r9.u8);
	// li r8,100
	ctx.r8.s64 = 100;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// li r9,3000
	ctx.r9.s64 = 3000;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x82755790
	ctx.lr = 0x8275324C;
	sub_82755790(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82753260
	if (cr0.eq) goto loc_82753260;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827530a0
	ctx.lr = 0x8275325C;
	sub_827530A0(ctx, base);
	// b 0x82753210
	goto loc_82753210;
loc_82753260:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275326c
	goto loc_8275326C;
loc_82753268:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_8275326C:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_82753168) {
	__imp__sub_82753168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-22784
	ctx.r8.s64 = ctx.r9.s64 + -22784;
	// lis r10,15258
	ctx.r10.s64 = 999948288;
	// ori r10,r10,51712
	ctx.r10.u64 = ctx.r10.u64 | 51712;
	// std r11,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, r11.u64);
	// std r11,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, r11.u64);
	// std r11,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, r11.u64);
	// std r11,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, r11.u64);
	// std r11,32(r8)
	PPC_STORE_U64(ctx.r8.u32 + 32, r11.u64);
	// std r10,-22784(r9)
	PPC_STORE_U64(ctx.r9.u32 + -22784, ctx.r10.u64);
	// b 0x82753168
	sub_82753168(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82753280) {
	__imp__sub_82753280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827532B0) {
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
	ctx.lr = 0x827532B8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827533f8
	if (cr6.eq) goto loc_827533F8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,64206
	cr6.compare<uint32_t>(ctx.r10.u32, 64206, xer);
	// bne cr6,0x827533f8
	if (!cr6.eq) goto loc_827533F8;
	// lbz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r10,11
	cr6.compare<uint32_t>(ctx.r10.u32, 11, xer);
	// beq cr6,0x827532ec
	if (cr6.eq) goto loc_827532EC;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x827533fc
	goto loc_827533FC;
loc_827532EC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827532fc
	if (!cr6.eq) goto loc_827532FC;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827533fc
	goto loc_827533FC;
loc_827532FC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82753310
	if (!cr6.eq) goto loc_82753310;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753310:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82753324
	if (!cr6.eq) goto loc_82753324;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753324:
	// lhz r9,14(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// addi r8,r11,14
	ctx.r8.s64 = r11.s64 + 14;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x82753340
	if (cr6.lt) goto loc_82753340;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753340:
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x82753354
	if (cr6.lt) goto loc_82753354;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753354:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// ble cr6,0x8275336c
	if (!cr6.gt) goto loc_8275336C;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x827533fc
	goto loc_827533FC;
loc_8275336C:
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// ble cr6,0x82753380
	if (!cr6.gt) goto loc_82753380;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753380:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lhz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x82756270
	ctx.lr = 0x827533B0;
	sub_82756270(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827533f0
	if (cr6.eq) goto loc_827533F0;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// li r11,0
	r11.s64 = 0;
loc_827533C8:
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r11,r8
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfs f0,-48(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -48, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// blt cr6,0x827533c8
	if (cr6.lt) goto loc_827533C8;
loc_827533F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827533fc
	goto loc_827533FC;
loc_827533F8:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_827533FC:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827532B0) {
	__imp__sub_827532B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82753404) {
	__imp__sub_82753404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753408) {
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
	ctx.lr = 0x82753410;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82458098
	ctx.lr = 0x82753428;
	sub_82458098(ctx, base);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827532b0
	ctx.lr = 0x82753438;
	sub_827532B0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82458098
	ctx.lr = 0x82753444;
	sub_82458098(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,-21296
	r11.s64 = r11.s64 + -21296;
	// ld r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// bge cr6,0x82753468
	if (!cr6.lt) goto loc_82753468;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
loc_82753468:
	// ld r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// ble cr6,0x82753478
	if (!cr6.gt) goto loc_82753478;
	// std r10,16(r11)
	PPC_STORE_U64(r11.u32 + 16, ctx.r10.u64);
loc_82753478:
	// ld r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82753408) {
	__imp__sub_82753408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275349C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275349C) {
	__imp__sub_8275349C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827534A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,92(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 92);
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827534A0) {
	__imp__sub_827534A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827534B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827534B4) {
	__imp__sub_827534B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827534B8) {
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
	ctx.lr = 0x827534C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827534d4
	if (!cr6.eq) goto loc_827534D4;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82753568
	goto loc_82753568;
loc_827534D4:
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82753564
	if (cr6.eq) goto loc_82753564;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82753564
	if (!cr6.eq) goto loc_82753564;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// beq cr6,0x82753500
	if (cr6.eq) goto loc_82753500;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82753568
	goto loc_82753568;
loc_82753500:
	// li r29,0
	r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x82756638
	ctx.lr = 0x82753510;
	sub_82756638(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82753530
	if (cr6.eq) goto loc_82753530;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275352C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_82753530:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275354c
	if (cr6.eq) goto loc_8275354C;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_8275354C:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275355C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82753568
	goto loc_82753568;
loc_82753564:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82753568:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827534B8) {
	__imp__sub_827534B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753570) {
	PPC_FUNC_PROLOGUE();
	// b 0x827534b8
	sub_827534B8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82753570) {
	__imp__sub_82753570(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82753574) {
	__imp__sub_82753574(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753578) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827535a0
	if (!cr6.eq) goto loc_827535A0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827536a8
	goto loc_827536A8;
loc_827535A0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r31,0
	r31.s64 = 0;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21248(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21240);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275361C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8275362c
	if (!cr0.eq) goto loc_8275362C;
loc_82753624:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x827536a8
	goto loc_827536A8;
loc_8275362C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// stb r9,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r9.u8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82756468
	ctx.lr = 0x8275364C;
	sub_82756468(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82753660
	if (cr0.eq) goto loc_82753660;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827534b8
	ctx.lr = 0x8275365C;
	sub_827534B8(ctx, base);
	// b 0x82753624
	goto loc_82753624;
loc_82753660:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,15258
	r11.s64 = 999948288;
	// addi r30,r10,-21296
	r30.s64 = ctx.r10.s64 + -21296;
	// ori r11,r11,51712
	r11.u64 = r11.u64 | 51712;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r31.u64);
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, r31.u64);
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, r31.u64);
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, r31.u64);
	// std r31,32(r9)
	PPC_STORE_U64(ctx.r9.u32 + 32, r31.u64);
	// std r11,-21296(r10)
	PPC_STORE_U64(ctx.r10.u32 + -21296, r11.u64);
	// bl 0x82458060
	ctx.lr = 0x82753694;
	sub_82458060(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// b 0x827536a8
	goto loc_827536A8;
loc_827536A4:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_827536A8:
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

PPC_WEAK_FUNC(sub_82753578) {
	__imp__sub_82753578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536C0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82753578
	sub_82753578(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827536C0) {
	__imp__sub_827536C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827536C4) {
	__imp__sub_827536C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21256(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21256, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827536C8) {
	__imp__sub_827536C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827536DC) {
	__imp__sub_827536DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21252(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21252, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827536E0) {
	__imp__sub_827536E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827536F4) {
	__imp__sub_827536F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827536F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21248(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21248, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827536F8) {
	__imp__sub_827536F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275370C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275370C) {
	__imp__sub_8275370C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21244(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21244, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82753710) {
	__imp__sub_82753710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82753724) {
	__imp__sub_82753724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21240(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21240, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82753728) {
	__imp__sub_82753728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8275373C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8275373C) {
	__imp__sub_8275373C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21236(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21236, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82753740) {
	__imp__sub_82753740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82753754) {
	__imp__sub_82753754(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82753758) {
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82753760;
	// lhz r11,8(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 8);
	// addi r21,r6,8
	r21.s64 = ctx.r6.s64 + 8;
	// lhz r9,26(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 26);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// srawi r8,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 15;
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82753790
	if (cr6.eq) goto loc_82753790;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753790:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x827537a8
	if (!cr6.eq) goto loc_827537A8;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x827537b0
	goto loc_827537B0;
loc_827537A8:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_827537B0:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x827537ec
	if (cr6.gt) goto loc_827537EC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827537f8
	goto loc_827537F8;
loc_827537EC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_827537F8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,10(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 10);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,28(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 28);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r27,r11
	r27.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753840
	if (cr6.eq) goto loc_82753840;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753840:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753858
	if (!cr6.eq) goto loc_82753858;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753860
	goto loc_82753860;
loc_82753858:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753860:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x8275389c
	if (cr6.gt) goto loc_8275389C;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827538a8
	goto loc_827538A8;
loc_8275389C:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_827538A8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,12(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,30(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r28,r11
	r28.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x827538f0
	if (cr6.eq) goto loc_827538F0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_827538F0:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753908
	if (!cr6.eq) goto loc_82753908;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753910
	goto loc_82753910;
loc_82753908:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753910:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x8275394c
	if (cr6.gt) goto loc_8275394C;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753958
	goto loc_82753958;
loc_8275394C:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753958:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,14(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 14);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,32(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r29,r11
	r29.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x827539a0
	if (cr6.eq) goto loc_827539A0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_827539A0:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x827539b8
	if (!cr6.eq) goto loc_827539B8;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x827539c0
	goto loc_827539C0;
loc_827539B8:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_827539C0:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x827539fc
	if (cr6.gt) goto loc_827539FC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753a08
	goto loc_82753A08;
loc_827539FC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753A08:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,16(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 16);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,34(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 34);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r30,r11
	r30.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753a50
	if (cr6.eq) goto loc_82753A50;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753A50:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753a68
	if (!cr6.eq) goto loc_82753A68;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753a70
	goto loc_82753A70;
loc_82753A68:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753A70:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753aac
	if (cr6.gt) goto loc_82753AAC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753ab8
	goto loc_82753AB8;
loc_82753AAC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753AB8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,18(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 18);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r26,36(r6)
	r26.u64 = PPC_LOAD_U16(ctx.r6.u32 + 36);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r31,r11
	r31.s64 = r11.s16;
	// extsh r11,r26
	r11.s64 = r26.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753b00
	if (cr6.eq) goto loc_82753B00;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753B00:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r7,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753b18
	if (!cr6.eq) goto loc_82753B18;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753b20
	goto loc_82753B20;
loc_82753B18:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753B20:
	// srawi r26,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	r26.s64 = r11.s32 >> 10;
	// clrlwi r9,r11,26
	ctx.r9.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r26,r26,31
	r26.u64 = r26.u32 & 0x1;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// xor r11,r26,r8
	r11.u64 = r26.u64 ^ ctx.r8.u64;
	// rlwinm r9,r9,3,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r10,26
	cr6.compare<int32_t>(ctx.r10.s32, 26, xer);
	// bgt cr6,0x82753b5c
	if (cr6.gt) goto loc_82753B5C;
	// subfic r10,r10,26
	xer.ca = ctx.r10.u32 <= 26;
	ctx.r10.s64 = 26 - ctx.r10.s64;
	// sraw r10,r9,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r10.s64 = ctx.r9.s32 >> temp.u32;
	// b 0x82753b68
	goto loc_82753B68;
loc_82753B5C:
	// addi r10,r10,-26
	ctx.r10.s64 = ctx.r10.s64 + -26;
	// slw r9,r9,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// clrlwi r10,r9,17
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFF;
loc_82753B68:
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// lhz r26,0(r6)
	r26.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r31
	ctx.r9.s64 = r31.s16;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// and r11,r8,r11
	r11.u64 = ctx.r8.u64 & r11.u64;
	// extsh r8,r30
	ctx.r8.s64 = r30.s16;
	// or r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 | r11.u64;
	// extsh r7,r29
	ctx.r7.s64 = r29.s16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r31,r28
	r31.s64 = r28.s16;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsh r11,r26
	r11.s64 = r26.s16;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lhz r27,42(r6)
	r27.u64 = PPC_LOAD_U16(ctx.r6.u32 + 42);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// srawi r9,r11,15
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFF) != 0);
	ctx.r9.s64 = r11.s32 >> 15;
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// clrlwi r29,r9,31
	r29.u64 = ctx.r9.u32 & 0x1;
	// extsh r28,r27
	r28.s64 = r27.s16;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// extsh r31,r8
	r31.s64 = ctx.r8.s16;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// beq cr6,0x82753bd8
	if (cr6.eq) goto loc_82753BD8;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// clrlwi r11,r10,19
	r11.u64 = ctx.r10.u32 & 0x1FFF;
loc_82753BD8:
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subfic r9,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r10.s64;
	// bne cr6,0x82753bf0
	if (!cr6.eq) goto loc_82753BF0;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753bf8
	goto loc_82753BF8;
loc_82753BF0:
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r11,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	ctx.r10.s64 = r11.s32 >> temp.u32;
loc_82753BF8:
	// srawi r8,r28,10
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x3FF) != 0);
	ctx.r8.s64 = r28.s32 >> 10;
	// srawi r7,r28,6
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x3F) != 0);
	ctx.r7.s64 = r28.s32 >> 6;
	// clrlwi r30,r28,26
	r30.u64 = r28.u32 & 0x3F;
	// clrlwi r11,r7,28
	r11.u64 = ctx.r7.u32 & 0xF;
	// mullw r10,r30,r10
	ctx.r10.s64 = int64_t(r30.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// xor r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 ^ r29.u64;
	// rlwinm r10,r8,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753c34
	if (cr6.gt) goto loc_82753C34;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753c40
	goto loc_82753C40;
loc_82753C34:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753C40:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r9,2(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 2);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// lhz r30,44(r6)
	r30.u64 = PPC_LOAD_U16(ctx.r6.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// and r11,r8,r11
	r11.u64 = ctx.r8.u64 & r11.u64;
	// srawi r9,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 15;
	// or r8,r11,r7
	ctx.r8.u64 = r11.u64 | ctx.r7.u64;
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// extsh r11,r30
	r11.s64 = r30.s16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// beq cr6,0x82753c88
	if (cr6.eq) goto loc_82753C88;
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// clrlwi r10,r8,19
	ctx.r10.u64 = ctx.r8.u32 & 0x1FFF;
loc_82753C88:
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r8,r8,32
	xer.ca = ctx.r8.u32 <= 32;
	ctx.r8.s64 = 32 - ctx.r8.s64;
	// bne cr6,0x82753ca0
	if (!cr6.eq) goto loc_82753CA0;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753ca8
	goto loc_82753CA8;
loc_82753CA0:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753CA8:
	// srawi r30,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	r30.s64 = r11.s32 >> 10;
	// clrlwi r29,r11,26
	r29.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r29,r10
	ctx.r10.s64 = int64_t(r29.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r30,r30,31
	r30.u64 = r30.u32 & 0x1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r30,r9
	ctx.r9.u64 = r30.u64 ^ ctx.r9.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753ce4
	if (cr6.gt) goto loc_82753CE4;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753cf0
	goto loc_82753CF0;
loc_82753CE4:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753CF0:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// neg r30,r10
	r30.s64 = -ctx.r10.s64;
	// sth r27,44(r6)
	PPC_STORE_U16(ctx.r6.u32 + 44, r27.u16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// and r11,r30,r11
	r11.u64 = r30.u64 & r11.u64;
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// extsh r7,r31
	ctx.r7.s64 = r31.s16;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// srawi r24,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r24.s64 = ctx.r7.s32 >> 1;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r9,256
	cr6.compare<int32_t>(ctx.r9.s32, 256, xer);
	// srawi r25,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	r25.s64 = ctx.r10.s32 >> 1;
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82753d40
	if (cr6.lt) goto loc_82753D40;
	// li r11,0
	r11.s64 = 0;
loc_82753D40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753d58
	if (cr6.eq) goto loc_82753D58;
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// b 0x82753d5c
	goto loc_82753D5C;
loc_82753D58:
	// li r9,64
	ctx.r9.s64 = 64;
loc_82753D5C:
	// lhz r27,50(r6)
	r27.u64 = PPC_LOAD_U16(ctx.r6.u32 + 50);
	// lhz r8,52(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 52);
	// subf r7,r27,r8
	ctx.r7.s64 = ctx.r8.s64 - r27.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82753d80
	if (!cr6.lt) goto loc_82753D80;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
loc_82753D80:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// srawi r11,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	r11.s64 = ctx.r8.s32 >> 6;
	// bge cr6,0x82753da4
	if (!cr6.lt) goto loc_82753DA4;
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// extsh r30,r9
	r30.s64 = ctx.r9.s16;
	// b 0x82753dac
	goto loc_82753DAC;
loc_82753DA4:
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// extsh r30,r11
	r30.s64 = r11.s16;
loc_82753DAC:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82753dbc
	if (cr6.eq) goto loc_82753DBC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// b 0x8275403c
	goto loc_8275403C;
loc_82753DBC:
	// subf r9,r25,r4
	ctx.r9.s64 = ctx.r4.s64 - r25.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82753ddc
	if (!cr6.lt) goto loc_82753DDC;
	// neg r11,r4
	r11.s64 = -ctx.r4.s64;
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// b 0x82753de0
	goto loc_82753DE0;
loc_82753DDC:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_82753DE0:
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// ori r11,r8,1
	r11.u64 = ctx.r8.u64 | 1;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// rlwinm r11,r10,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0x1;
	// rlwinm r9,r10,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e08
	if (cr6.eq) goto loc_82753E08;
	// li r11,15
	r11.s64 = 15;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E08:
	// rlwinm r9,r10,19,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e20
	if (cr6.eq) goto loc_82753E20;
	// li r11,14
	r11.s64 = 14;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E20:
	// rlwinm r9,r10,20,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e38
	if (cr6.eq) goto loc_82753E38;
	// li r11,13
	r11.s64 = 13;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E38:
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e50
	if (cr6.eq) goto loc_82753E50;
	// li r11,12
	r11.s64 = 12;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E50:
	// rlwinm r9,r10,22,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e68
	if (cr6.eq) goto loc_82753E68;
	// li r11,11
	r11.s64 = 11;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E68:
	// rlwinm r9,r10,23,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e80
	if (cr6.eq) goto loc_82753E80;
	// li r11,10
	r11.s64 = 10;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E80:
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e98
	if (cr6.eq) goto loc_82753E98;
	// li r11,9
	r11.s64 = 9;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E98:
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753eb0
	if (cr6.eq) goto loc_82753EB0;
	// li r11,8
	r11.s64 = 8;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EB0:
	// rlwinm r9,r10,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ec8
	if (cr6.eq) goto loc_82753EC8;
	// li r11,7
	r11.s64 = 7;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EC8:
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ee0
	if (cr6.eq) goto loc_82753EE0;
	// li r11,6
	r11.s64 = 6;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EE0:
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ef8
	if (cr6.eq) goto loc_82753EF8;
	// li r11,5
	r11.s64 = 5;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EF8:
	// rlwinm r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f10
	if (cr6.eq) goto loc_82753F10;
	// li r11,4
	r11.s64 = 4;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F10:
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f28
	if (cr6.eq) goto loc_82753F28;
	// li r11,3
	r11.s64 = 3;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F28:
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f40
	if (cr6.eq) goto loc_82753F40;
	// li r11,2
	r11.s64 = 2;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F40:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
loc_82753F54:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// subfic r11,r9,7
	xer.ca = ctx.r9.u32 <= 7;
	r11.s64 = 7 - ctx.r9.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82753f80
	if (!cr6.lt) goto loc_82753F80;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753f88
	goto loc_82753F88;
loc_82753F80:
	// slw r11,r8,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82753F88:
	// rlwinm r10,r9,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// extsh r9,r30
	ctx.r9.s64 = r30.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// srawi r7,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-124
	cr6.compare<int32_t>(r11.s32, -124, xer);
	// bge cr6,0x82753fb8
	if (!cr6.lt) goto loc_82753FB8;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754020
	goto loc_82754020;
loc_82753FB8:
	// cmpwi cr6,r11,80
	cr6.compare<int32_t>(r11.s32, 80, xer);
	// blt cr6,0x8275401c
	if (cr6.lt) goto loc_8275401C;
	// cmpwi cr6,r11,178
	cr6.compare<int32_t>(r11.s32, 178, xer);
	// bge cr6,0x82753fd0
	if (!cr6.lt) goto loc_82753FD0;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754020
	goto loc_82754020;
loc_82753FD0:
	// cmpwi cr6,r11,246
	cr6.compare<int32_t>(r11.s32, 246, xer);
	// bge cr6,0x82753fe0
	if (!cr6.lt) goto loc_82753FE0;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754020
	goto loc_82754020;
loc_82753FE0:
	// cmpwi cr6,r11,300
	cr6.compare<int32_t>(r11.s32, 300, xer);
	// bge cr6,0x82753ff0
	if (!cr6.lt) goto loc_82753FF0;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754020
	goto loc_82754020;
loc_82753FF0:
	// cmpwi cr6,r11,349
	cr6.compare<int32_t>(r11.s32, 349, xer);
	// bge cr6,0x82754000
	if (!cr6.lt) goto loc_82754000;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754020
	goto loc_82754020;
loc_82754000:
	// cmpwi cr6,r11,400
	cr6.compare<int32_t>(r11.s32, 400, xer);
	// bge cr6,0x82754010
	if (!cr6.lt) goto loc_82754010;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754020
	goto loc_82754020;
loc_82754010:
	// cmpwi cr6,r11,2048
	cr6.compare<int32_t>(r11.s32, 2048, xer);
	// li r11,7
	r11.s64 = 7;
	// blt cr6,0x82754020
	if (cr6.lt) goto loc_82754020;
loc_8275401C:
	// li r11,1
	r11.s64 = 1;
loc_82754020:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x8275403c
	if (!cr6.lt) goto loc_8275403C;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// beq cr6,0x8275403c
	if (cr6.eq) goto loc_8275403C;
	// not r11,r10
	r11.u64 = ~ctx.r10.u64;
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
loc_8275403C:
	// extsh r28,r11
	r28.s64 = r11.s16;
	// srawi. r31,r28,3
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7) != 0);
	r31.s64 = r28.s32 >> 3;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82754050
	if (cr0.eq) goto loc_82754050;
	// xori r11,r28,15
	r11.u64 = r28.u64 ^ 15;
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82754050:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r23,r11,1,0,30
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r10,-4320
	ctx.r9.s64 = ctx.r10.s64 + -4320;
	// extsh r8,r30
	ctx.r8.s64 = r30.s16;
	// srawi r10,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 2;
	// lhzx r11,r23,r9
	r11.u64 = PPC_LOAD_U16(r23.u32 + ctx.r9.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,0,21,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x780;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// srawi r11,r4,7
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7F) != 0);
	r11.s64 = ctx.r4.s32 >> 7;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827540ac
	if (!cr6.lt) goto loc_827540AC;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827540b8
	goto loc_827540B8;
loc_827540AC:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
loc_827540B8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// blt cr6,0x827540c8
	if (cr6.lt) goto loc_827540C8;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_827540C8:
	// extsh r11,r27
	r11.s64 = r27.s16;
	// rlwinm r9,r27,0,23,27
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1F0;
	// srawi r11,r11,9
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FF) != 0);
	r11.s64 = r11.s32 >> 9;
	// srawi r10,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 4;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827540fc
	if (!cr6.lt) goto loc_827540FC;
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// sraw r10,r8,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r10.s64 = ctx.r8.s32 >> temp.u32;
	// b 0x82754108
	goto loc_82754108;
loc_827540FC:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// slw r9,r10,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
loc_82754108:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// li r11,15872
	r11.s64 = 15872;
	// bgt cr6,0x82754118
	if (cr6.gt) goto loc_82754118;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82754118:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// extsh r29,r4
	r29.s64 = ctx.r4.s16;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// ble cr6,0x82754148
	if (!cr6.gt) goto loc_82754148;
	// lhz r11,46(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 46);
	// li r26,-1
	r26.s64 = -1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8275414c
	if (cr6.eq) goto loc_8275414C;
loc_82754148:
	// li r26,0
	r26.s64 = 0;
loc_8275414C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// extsh r22,r30
	r22.s64 = r30.s16;
	// addi r10,r11,-4272
	ctx.r10.s64 = r11.s64 + -4272;
	// lhzx r9,r23,r10
	ctx.r9.u64 = PPC_LOAD_U16(r23.u32 + ctx.r10.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// rlwinm r7,r8,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r22,r7
	r11.s64 = ctx.r7.s64 - r22.s64;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
	// add r10,r11,r22
	ctx.r10.u64 = r11.u64 + r22.u64;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpwi cr6,r10,544
	cr6.compare<int32_t>(ctx.r10.s32, 544, xer);
	// bge cr6,0x82754188
	if (!cr6.lt) goto loc_82754188;
	// li r11,544
	r11.s64 = 544;
	// b 0x82754194
	goto loc_82754194;
loc_82754188:
	// cmpwi cr6,r10,5120
	cr6.compare<int32_t>(ctx.r10.s32, 5120, xer);
	// blt cr6,0x82754194
	if (cr6.lt) goto loc_82754194;
	// li r11,5120
	r11.s64 = 5120;
loc_82754194:
	// lhz r10,48(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 48);
	// extsh r9,r27
	ctx.r9.s64 = r27.s16;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// sth r11,52(r6)
	PPC_STORE_U16(ctx.r6.u32 + 52, r11.u16);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r11,r4,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 17) & 0x1;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r30,r29,18,31,31
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 18) & 0x1;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// xor r30,r30,r11
	r30.u64 = r30.u64 ^ r11.u64;
	// srawi r8,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 6;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r7,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 6;
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// sth r7,50(r6)
	PPC_STORE_U16(ctx.r6.u32 + 50, ctx.r7.u16);
	// sth r10,48(r6)
	PPC_STORE_U16(ctx.r6.u32 + 48, ctx.r10.u16);
	// beq cr6,0x827541f4
	if (cr6.eq) goto loc_827541F4;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754340
	goto loc_82754340;
loc_827541F4:
	// rlwinm r10,r29,19,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 19) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275420c
	if (cr6.eq) goto loc_8275420C;
	// li r11,14
	r11.s64 = 14;
	// b 0x82754340
	goto loc_82754340;
loc_8275420C:
	// rlwinm r10,r29,20,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 20) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754224
	if (cr6.eq) goto loc_82754224;
	// li r11,13
	r11.s64 = 13;
	// b 0x82754340
	goto loc_82754340;
loc_82754224:
	// rlwinm r10,r29,21,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 21) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275423c
	if (cr6.eq) goto loc_8275423C;
	// li r11,12
	r11.s64 = 12;
	// b 0x82754340
	goto loc_82754340;
loc_8275423C:
	// rlwinm r10,r29,22,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 22) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754254
	if (cr6.eq) goto loc_82754254;
	// li r11,11
	r11.s64 = 11;
	// b 0x82754340
	goto loc_82754340;
loc_82754254:
	// rlwinm r10,r29,23,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 23) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275426c
	if (cr6.eq) goto loc_8275426C;
	// li r11,10
	r11.s64 = 10;
	// b 0x82754340
	goto loc_82754340;
loc_8275426C:
	// rlwinm r10,r29,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754284
	if (cr6.eq) goto loc_82754284;
	// li r11,9
	r11.s64 = 9;
	// b 0x82754340
	goto loc_82754340;
loc_82754284:
	// rlwinm r10,r29,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 25) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275429c
	if (cr6.eq) goto loc_8275429C;
	// li r11,8
	r11.s64 = 8;
	// b 0x82754340
	goto loc_82754340;
loc_8275429C:
	// rlwinm r10,r29,26,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 26) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542b4
	if (cr6.eq) goto loc_827542B4;
	// li r11,7
	r11.s64 = 7;
	// b 0x82754340
	goto loc_82754340;
loc_827542B4:
	// rlwinm r10,r29,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542cc
	if (cr6.eq) goto loc_827542CC;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754340
	goto loc_82754340;
loc_827542CC:
	// rlwinm r10,r29,28,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 28) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542e4
	if (cr6.eq) goto loc_827542E4;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754340
	goto loc_82754340;
loc_827542E4:
	// rlwinm r10,r29,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 29) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542fc
	if (cr6.eq) goto loc_827542FC;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754340
	goto loc_82754340;
loc_827542FC:
	// rlwinm r10,r29,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 30) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754314
	if (cr6.eq) goto loc_82754314;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754340
	goto loc_82754340;
loc_82754314:
	// rlwinm r10,r29,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 31) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275432c
	if (cr6.eq) goto loc_8275432C;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754340
	goto loc_82754340;
loc_8275432C:
	// clrlwi r10,r29,31
	ctx.r10.u64 = r29.u32 & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_82754340:
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// subfic r11,r8,6
	xer.ca = ctx.r8.u32 <= 6;
	r11.s64 = 6 - ctx.r8.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82754368
	if (!cr6.lt) goto loc_82754368;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// sraw r11,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82754370
	goto loc_82754370;
loc_82754368:
	// slw r11,r29,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r29.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82754370:
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// beq cr6,0x82754398
	if (cr6.eq) goto loc_82754398;
	// subf r7,r29,r24
	ctx.r7.s64 = r24.s64 - r29.s64;
	// subf r4,r29,r25
	ctx.r4.s64 = r25.s64 - r29.s64;
	// li r31,-1024
	r31.s64 = -1024;
	// extsh r27,r7
	r27.s64 = ctx.r7.s16;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// b 0x827543ac
	goto loc_827543AC;
loc_82754398:
	// add r10,r24,r29
	ctx.r10.u64 = r24.u64 + r29.u64;
	// add r7,r25,r29
	ctx.r7.u64 = r25.u64 + r29.u64;
	// li r31,0
	r31.s64 = 0;
	// extsh r27,r10
	r27.s64 = ctx.r10.s16;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
loc_827543AC:
	// extsh r30,r4
	r30.s64 = ctx.r4.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// addi r11,r30,-8191
	r11.s64 = r30.s64 + -8191;
	// xori r10,r3,1
	ctx.r10.u64 = ctx.r3.u64 ^ 1;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// rlwinm r8,r8,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r3,r11,r30
	ctx.r3.u64 = r11.u64 & r30.u64;
	// clrlwi r11,r9,19
	r11.u64 = ctx.r9.u32 & 0x1FFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// or r9,r11,r3
	ctx.r9.u64 = r11.u64 | ctx.r3.u64;
	// extsh r31,r31
	r31.s64 = r31.s16;
	// addi r3,r9,8192
	ctx.r3.s64 = ctx.r9.s64 + 8192;
	// andc r25,r28,r10
	r25.u64 = r28.u64 & ~ctx.r10.u64;
	// srawi r11,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	r11.s64 = ctx.r3.s32 >> 16;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// rlwinm r3,r11,0,0,18
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFE000;
	// andc r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ~r11.u64;
	// add r11,r8,r7
	r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// or r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 | ctx.r3.u64;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// and r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 & ctx.r10.u64;
	// extsh r28,r7
	r28.s64 = ctx.r7.s16;
	// or r11,r3,r25
	r11.u64 = ctx.r3.u64 | r25.u64;
	// sth r11,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, r11.u16);
	// bge cr6,0x8275441c
	if (!cr6.lt) goto loc_8275441C;
	// neg r11,r30
	r11.s64 = -r30.s64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
loc_8275441C:
	// rlwinm r11,r4,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 17) & 0x1;
	// rlwinm r9,r4,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x1;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275443c
	if (cr6.eq) goto loc_8275443C;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754588
	goto loc_82754588;
loc_8275443C:
	// rlwinm r9,r10,19,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754454
	if (cr6.eq) goto loc_82754454;
	// li r11,14
	r11.s64 = 14;
	// b 0x82754588
	goto loc_82754588;
loc_82754454:
	// rlwinm r9,r10,20,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275446c
	if (cr6.eq) goto loc_8275446C;
	// li r11,13
	r11.s64 = 13;
	// b 0x82754588
	goto loc_82754588;
loc_8275446C:
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754484
	if (cr6.eq) goto loc_82754484;
	// li r11,12
	r11.s64 = 12;
	// b 0x82754588
	goto loc_82754588;
loc_82754484:
	// rlwinm r9,r10,22,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275449c
	if (cr6.eq) goto loc_8275449C;
	// li r11,11
	r11.s64 = 11;
	// b 0x82754588
	goto loc_82754588;
loc_8275449C:
	// rlwinm r9,r10,23,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544b4
	if (cr6.eq) goto loc_827544B4;
	// li r11,10
	r11.s64 = 10;
	// b 0x82754588
	goto loc_82754588;
loc_827544B4:
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544cc
	if (cr6.eq) goto loc_827544CC;
	// li r11,9
	r11.s64 = 9;
	// b 0x82754588
	goto loc_82754588;
loc_827544CC:
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544e4
	if (cr6.eq) goto loc_827544E4;
	// li r11,8
	r11.s64 = 8;
	// b 0x82754588
	goto loc_82754588;
loc_827544E4:
	// rlwinm r9,r10,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544fc
	if (cr6.eq) goto loc_827544FC;
	// li r11,7
	r11.s64 = 7;
	// b 0x82754588
	goto loc_82754588;
loc_827544FC:
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754514
	if (cr6.eq) goto loc_82754514;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754588
	goto loc_82754588;
loc_82754514:
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275452c
	if (cr6.eq) goto loc_8275452C;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754588
	goto loc_82754588;
loc_8275452C:
	// rlwinm r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754544
	if (cr6.eq) goto loc_82754544;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754588
	goto loc_82754588;
loc_82754544:
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275455c
	if (cr6.eq) goto loc_8275455C;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754588
	goto loc_82754588;
loc_8275455C:
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754574
	if (cr6.eq) goto loc_82754574;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754588
	goto loc_82754588;
loc_82754574:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
loc_82754588:
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// subfic r11,r9,6
	xer.ca = ctx.r9.u32 <= 6;
	r11.s64 = 6 - ctx.r9.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827545b0
	if (!cr6.lt) goto loc_827545B0;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827545b8
	goto loc_827545B8;
loc_827545B0:
	// slw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_827545B8:
	// cntlzw r10,r30
	ctx.r10.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// ori r5,r11,32
	ctx.r5.u64 = r11.u64 | 32;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subfic r3,r4,0
	xer.ca = ctx.r4.u32 <= 0;
	ctx.r3.s64 = 0 - ctx.r4.s64;
	// extsh r5,r26
	ctx.r5.s64 = r26.s16;
	// subfe r8,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r3.u64 + ctx.r3.u64 + xer.ca;
	xer.ca = temp.u8;
	// not r3,r5
	ctx.r3.u64 = ~ctx.r5.u64;
	// rlwinm r11,r8,0,0,21
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFC00;
	// subfic r7,r29,0
	xer.ca = r29.u32 <= 0;
	ctx.r7.s64 = 0 - r29.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// subfe r4,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r30,r3
	r30.s64 = ctx.r3.s16;
	// sth r11,42(r6)
	PPC_STORE_U16(ctx.r6.u32 + 42, r11.u16);
	// rlwinm r8,r4,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r11,r21
	r11.u64 = r21.u64;
	// li r10,6
	ctx.r10.s64 = 6;
loc_82754610:
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// xor r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 ^ r31.u64;
	// srawi r9,r4,8
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x8275463c
	if (!cr6.lt) goto loc_8275463C;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// b 0x82754644
	goto loc_82754644;
loc_8275463C:
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
loc_82754644:
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// and r4,r5,r3
	ctx.r4.u64 = ctx.r5.u64 & ctx.r3.u64;
	// sth r4,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r4.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x82754610
	if (!cr0.eq) goto loc_82754610;
	// lhz r4,28(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 28);
	// extsh r8,r27
	ctx.r8.s64 = r27.s16;
	// lhz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 40);
	// lhz r10,32(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 32);
	// lhz r7,38(r6)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r6.u32 + 38);
	// xor r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 ^ r27.u64;
	// lhz r11,30(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// lhz r31,34(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 34);
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// lhz r29,26(r6)
	r29.u64 = PPC_LOAD_U16(ctx.r6.u32 + 26);
	// sth r4,30(r6)
	PPC_STORE_U16(ctx.r6.u32 + 30, ctx.r4.u16);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r10,34(r6)
	PPC_STORE_U16(ctx.r6.u32 + 34, ctx.r10.u16);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r11,32(r6)
	PPC_STORE_U16(ctx.r6.u32 + 32, r11.u16);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// sth r31,36(r6)
	PPC_STORE_U16(ctx.r6.u32 + 36, r31.u16);
	// li r10,-4096
	ctx.r10.s64 = -4096;
	// sth r29,28(r6)
	PPC_STORE_U16(ctx.r6.u32 + 28, r29.u16);
	// sth r28,26(r6)
	PPC_STORE_U16(ctx.r6.u32 + 26, r28.u16);
	// sth r27,38(r6)
	PPC_STORE_U16(ctx.r6.u32 + 38, r27.u16);
	// sth r7,40(r6)
	PPC_STORE_U16(ctx.r6.u32 + 40, ctx.r7.u16);
	// blt cr6,0x827546c4
	if (cr6.lt) goto loc_827546C4;
	// li r10,4096
	ctx.r10.s64 = 4096;
loc_827546C4:
	// lhz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// cmpwi cr6,r11,-8191
	cr6.compare<int32_t>(r11.s32, -8191, xer);
	// li r11,-8191
	r11.s64 = -8191;
	// blt cr6,0x827546dc
	if (cr6.lt) goto loc_827546DC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_827546DC:
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// cmpwi cr6,r7,8191
	cr6.compare<int32_t>(ctx.r7.s32, 8191, xer);
	// blt cr6,0x827546ec
	if (cr6.lt) goto loc_827546EC;
	// li r11,8191
	r11.s64 = 8191;
loc_827546EC:
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x82754704
	if (!cr6.lt) goto loc_82754704;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x8275470c
	goto loc_8275470C;
loc_82754704:
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
loc_8275470C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82754720
	if (!cr6.eq) goto loc_82754720;
	// li r11,0
	r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8275472c
	goto loc_8275472C;
loc_82754720:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// li r9,192
	ctx.r9.s64 = 192;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
loc_8275472C:
	// lhz r10,2(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 2);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// srawi r7,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 7;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-12288
	cr6.compare<int32_t>(ctx.r10.s32, -12288, xer);
	// bge cr6,0x82754750
	if (!cr6.lt) goto loc_82754750;
	// li r11,-12288
	r11.s64 = -12288;
loc_82754750:
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,12288
	cr6.compare<int32_t>(ctx.r10.s32, 12288, xer);
	// blt cr6,0x82754760
	if (cr6.lt) goto loc_82754760;
	// li r11,12288
	r11.s64 = 12288;
loc_82754760:
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// and r10,r7,r3
	ctx.r10.u64 = ctx.r7.u64 & ctx.r3.u64;
	// srawi r11,r11,8
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFF) != 0);
	r11.s64 = r11.s32 >> 8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// sth r10,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r10.u16);
	// bge cr6,0x82754788
	if (!cr6.lt) goto loc_82754788;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x82754790
	goto loc_82754790;
loc_82754788:
	// subf r9,r9,r11
	ctx.r9.s64 = r11.s64 - ctx.r9.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
loc_82754790:
	// subfic r10,r7,15360
	xer.ca = ctx.r7.u32 <= 15360;
	ctx.r10.s64 = 15360 - ctx.r7.s64;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// neg r10,r9
	ctx.r10.s64 = -ctx.r9.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// bge cr6,0x827547c0
	if (!cr6.lt) goto loc_827547C0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_827547C0:
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827547d0
	if (!cr6.lt) goto loc_827547D0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_827547D0:
	// and r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 & ctx.r3.u64;
	// cmpwi cr6,r7,-11776
	cr6.compare<int32_t>(ctx.r7.s32, -11776, xer);
	// sth r10,0(r6)
	PPC_STORE_U16(ctx.r6.u32 + 0, ctx.r10.u16);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x827547e8
	if (cr6.lt) goto loc_827547E8;
	// li r11,0
	r11.s64 = 0;
loc_827547E8:
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lhz r10,20(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 20);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// lhz r11,22(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 22);
	// addi r5,r9,-4288
	ctx.r5.s64 = ctx.r9.s64 + -4288;
	// and r7,r8,r3
	ctx.r7.u64 = ctx.r8.u64 & ctx.r3.u64;
	// sth r7,46(r6)
	PPC_STORE_U16(ctx.r6.u32 + 46, ctx.r7.u16);
	// lhzx r5,r23,r5
	ctx.r5.u64 = PPC_LOAD_U16(r23.u32 + ctx.r5.u32);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
	// rlwinm r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// subf r7,r10,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r10.s64;
	// srawi r9,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 5;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// srawi r9,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 7;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// sth r11,22(r6)
	PPC_STORE_U16(ctx.r6.u32 + 22, r11.u16);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,20(r6)
	PPC_STORE_U16(ctx.r6.u32 + 20, r11.u16);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - r11.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8275485c
	if (!cr6.lt) goto loc_8275485C;
	// neg r10,r9
	ctx.r10.s64 = -ctx.r9.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
loc_8275485C:
	// rlwinm r9,r11,29,19,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFF;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82754874
	if (!cr6.lt) goto loc_82754874;
	// cmpwi cr6,r22,1536
	cr6.compare<int32_t>(r22.s32, 1536, xer);
	// bge cr6,0x8275487c
	if (!cr6.lt) goto loc_8275487C;
loc_82754874:
	// li r10,512
	ctx.r10.s64 = 512;
	// b 0x82754888
	goto loc_82754888;
loc_8275487C:
	// subfic r11,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	r11.s64 = 0 - ctx.r8.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r10,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200;
loc_82754888:
	// lhz r11,4(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// not r9,r3
	ctx.r9.u64 = ~ctx.r3.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// rlwinm r7,r9,0,23,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x100;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// srawi r10,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// and r11,r3,r30
	r11.u64 = ctx.r3.u64 & r30.u64;
	// or r10,r11,r7
	ctx.r10.u64 = r11.u64 | ctx.r7.u64;
	// sth r10,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r10.u16);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82753758) {
	__imp__sub_82753758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827548B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827548B4) {
	__imp__sub_827548B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827548B8) {
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
	ctx.lr = 0x827548C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r26,r29
	r26.u64 = r29.u64;
	// mr r25,r29
	r25.u64 = r29.u64;
	// lwz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754950
	if (cr6.eq) goto loc_82754950;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
loc_827548EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82754904
	if (cr6.gt) goto loc_82754904;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
loc_82754904:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827548ec
	if (!cr0.eq) goto loc_827548EC;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754950
	if (cr6.eq) goto loc_82754950;
	// lwz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
loc_82754920:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// divwu r8,r26,r11
	ctx.r8.u32 = r26.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf. r8,r8,r26
	ctx.r8.s64 = r26.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82754944
	if (cr0.eq) goto loc_82754944;
	// mullw r26,r11,r26
	r26.s64 = int64_t(r11.s32) * int64_t(r26.s32);
loc_82754944:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82754920
	if (!cr0.eq) goto loc_82754920;
loc_82754950:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mullw r27,r26,r30
	r27.s64 = int64_t(r26.s32) * int64_t(r30.s32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82754a24
	if (!cr6.eq) goto loc_82754A24;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x82754970;
	sub_82130B50(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mulli r3,r30,28
	ctx.r3.s64 = r30.s64 * 28;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x82130b50
	ctx.lr = 0x82754984;
	sub_82130B50(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// rlwinm r3,r30,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x82130b50
	ctx.lr = 0x82754998;
	sub_82130B50(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827549bc
	if (cr6.eq) goto loc_827549BC;
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827549bc
	if (cr6.eq) goto loc_827549BC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82754a24
	if (!cr6.eq) goto loc_82754A24;
loc_827549BC:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r25,-32761
	r25.s64 = -2147024896;
	// ori r25,r25,14
	r25.u64 = r25.u64 | 14;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827549e0
	if (cr6.eq) goto loc_827549E0;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x827549DC;
	sub_821310F8(ctx, base);
	// stw r29,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r29.u32);
loc_827549E0:
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827549fc
	if (cr6.eq) goto loc_827549FC;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x827549F8;
	sub_821310F8(ctx, base);
	// stw r29,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r29.u32);
loc_827549FC:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82754a18
	if (cr6.eq) goto loc_82754A18;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x82754A14;
	sub_821310F8(ctx, base);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_82754A18:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82754A24:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754A34;
	sub_8244D150(ctx, base);
	// mulli r28,r30,28
	r28.s64 = r30.s64 * 28;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x82754A48;
	sub_8244D150(ctx, base);
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754A5C;
	sub_8244D150(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// beq cr6,0x82754a18
	if (cr6.eq) goto loc_82754A18;
loc_82754A7C:
	// addi r11,r11,-28
	r11.s64 = r11.s64 + -28;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// subf r9,r26,r9
	ctx.r9.s64 = ctx.r9.s64 - r26.s64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// bne 0x82754a7c
	if (!cr0.eq) goto loc_82754A7C;
	// b 0x82754a18
	goto loc_82754A18;
}

PPC_WEAK_FUNC(sub_827548B8) {
	__imp__sub_827548B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754AA0) {
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
	ctx.lr = 0x82754AA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r22,0
	r22.s64 = 0;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// mr r28,r22
	r28.u64 = r22.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r27,8(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r23,144(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r26,r11,31,1,31
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r25,148(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754b2c
	if (cr6.eq) goto loc_82754B2C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,196(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82754b04
	if (cr0.eq) goto loc_82754B04;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754B04;
	sub_8244D150(ctx, base);
loc_82754B04:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82754B28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
loc_82754B2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r24,16000
	r24.s64 = 16000;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82754c1c
	if (!cr6.eq) goto loc_82754C1C;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// rlwinm r9,r11,0,0,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82754b64
	if (!cr6.eq) goto loc_82754B64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// blt cr6,0x82754b64
	if (cr6.lt) goto loc_82754B64;
	// addi r25,r25,200
	r25.s64 = r25.s64 + 200;
loc_82754B64:
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// beq cr6,0x82754bc8
	if (cr6.eq) goto loc_82754BC8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82754bc8
	if (!cr0.eq) goto loc_82754BC8;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82754bac
	if (cr6.eq) goto loc_82754BAC;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82754B8C:
	// lha r9,0(r11)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(r11.u32 + 0));
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// srawi r8,r9,31
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 31;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// xor r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r28,r9,r28
	r28.u64 = ctx.r9.u64 + r28.u64;
	// bne 0x82754b8c
	if (!cr0.eq) goto loc_82754B8C;
loc_82754BAC:
	// divwu r11,r28,r26
	r11.u32 = r28.u32 / r26.u32;
	// twllei r26,0
	// subfc r11,r11,r25
	xer.ca = r25.u32 >= r11.u32;
	r11.s64 = r25.s64 - r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x82754bcc
	goto loc_82754BCC;
loc_82754BC8:
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
loc_82754BCC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82754bec
	if (!cr6.eq) goto loc_82754BEC;
	// li r11,500
	r11.s64 = 500;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// stw r10,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r10.u32);
	// b 0x82754c1c
	goto loc_82754C1C;
loc_82754BEC:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82754c14
	if (!cr6.gt) goto loc_82754C14;
	// mulli r10,r26,1000
	ctx.r10.s64 = r26.s64 * 1000;
	// divwu r10,r10,r24
	ctx.r10.u32 = ctx.r10.u32 / r24.u32;
	// li r9,1
	ctx.r9.s64 = 1;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// b 0x82754c1c
	goto loc_82754C1C;
loc_82754C14:
	// li r11,600
	r11.s64 = 600;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82754C1C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82754c30
	if (!cr6.eq) goto loc_82754C30;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// beq cr6,0x82754c3c
	if (cr6.eq) goto loc_82754C3C;
loc_82754C30:
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r11,30000
	cr6.compare<uint32_t>(r11.u32, 30000, xer);
	// ble cr6,0x82754c60
	if (!cr6.gt) goto loc_82754C60;
loc_82754C3C:
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r22,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r22.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r10,-1808
	ctx.r4.s64 = ctx.r10.s64 + -1808;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// li r5,54
	ctx.r5.s64 = 54;
	// bl 0x823da950
	ctx.lr = 0x82754C60;
	sub_823DA950(ctx, base);
loc_82754C60:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82754c80
	if (!cr6.eq) goto loc_82754C80;
	// mulli r11,r26,1000
	r11.s64 = r26.s64 * 1000;
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// divwu r11,r11,r24
	r11.u32 = r11.u32 / r24.u32;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
loc_82754C80:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82754AA0) {
	__imp__sub_82754AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754C88) {
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
	ctx.lr = 0x82754C90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82754cc0
	if (!cr6.eq) goto loc_82754CC0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82754CC0:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82754cfc
	if (cr6.eq) goto loc_82754CFC;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r10,r10,0,12,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82754cfc
	if (cr0.eq) goto loc_82754CFC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bdc34
	ctx.lr = 0x82754CFC;
	__imp__XamVoiceSubmitPacket(ctx, base);
loc_82754CFC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82754d14
	if (cr6.eq) goto loc_82754D14;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82754d28
	if (!cr6.lt) goto loc_82754D28;
loc_82754D14:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82754D28:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,116
	r11.s64 = r30.s64 + 116;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// lwz r10,120(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754d48
	if (cr6.eq) goto loc_82754D48;
	// stw r29,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r29.u32);
	// b 0x82754d4c
	goto loc_82754D4C;
loc_82754D48:
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
loc_82754D4C:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82754C88) {
	__imp__sub_82754C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754D58) {
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
	ctx.lr = 0x82754D60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r11,r29,20
	r11.s64 = r29.s64 + 20;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8274f578
	ctx.lr = 0x82754D8C;
	sub_8274F578(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82754da4
	if (!cr0.lt) goto loc_82754DA4;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
loc_82754DA4:
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754dc8
	if (cr6.eq) goto loc_82754DC8;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82754dcc
	goto loc_82754DCC;
loc_82754DC8:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82754DCC:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82754D58) {
	__imp__sub_82754D58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754DD8) {
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
	ctx.lr = 0x82754DE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82754e5c
	if (!cr6.gt) goto loc_82754E5C;
	// addi r31,r30,100
	r31.s64 = r30.s64 + 100;
	// addi r29,r30,80
	r29.s64 = r30.s64 + 80;
loc_82754E04:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x82754E18;
	sub_8274F6C8(ctx, base);
loc_82754E18:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82754e44
	if (cr6.eq) goto loc_82754E44;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82754e34
	if (!cr6.eq) goto loc_82754E34;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
loc_82754E34:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// b 0x82754e18
	goto loc_82754E18;
loc_82754E44:
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82754e04
	if (cr6.lt) goto loc_82754E04;
loc_82754E5C:
	// addi r11,r30,116
	r11.s64 = r30.s64 + 116;
loc_82754E60:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754e8c
	if (cr6.eq) goto loc_82754E8C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82754e7c
	if (!cr6.eq) goto loc_82754E7C;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82754E7C:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r27,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r27.u32);
	// b 0x82754e60
	goto loc_82754E60;
loc_82754E8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82754DD8) {
	__imp__sub_82754DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82754E94) {
	__imp__sub_82754E94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82754E98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82754EA0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r15,0
	r15.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r15,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r15.u32);
	// mr r17,r15
	r17.u64 = r15.u64;
	// mr r16,r15
	r16.u64 = r15.u64;
	// bl 0x8244fee8
	ctx.lr = 0x82754EBC;
	sub_8244FEE8(ctx, base);
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r14,28
	r14.s64 = 28;
	// cmplw cr6,r19,r11
	cr6.compare<uint32_t>(r19.u32, r11.u32, xer);
	// lwz r20,116(r28)
	r20.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// subf r11,r11,r19
	r11.s64 = r19.s64 - r11.s64;
	// addi r21,r28,116
	r21.s64 = r28.s64 + 116;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// beq cr6,0x82755224
	if (cr6.eq) goto loc_82755224;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r18,r11,-4256
	r18.s64 = r11.s64 + -4256;
loc_82754EF4:
	// lwz r29,0(r20)
	r29.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x82755224
	if (cr6.eq) goto loc_82755224;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82755224
	if (!cr6.eq) goto loc_82755224;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplw cr6,r17,r10
	cr6.compare<uint32_t>(r17.u32, ctx.r10.u32, xer);
	// bge cr6,0x82755224
	if (!cr6.lt) goto loc_82755224;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmpwi cr6,r10,20
	cr6.compare<int32_t>(ctx.r10.s32, 20, xer);
	// blt cr6,0x82755224
	if (cr6.lt) goto loc_82755224;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// beq cr6,0x82754f74
	if (cr6.eq) goto loc_82754F74;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82754f44
	if (cr6.eq) goto loc_82754F44;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82754f54
	if (!cr6.eq) goto loc_82754F54;
loc_82754F44:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r15,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r15.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
loc_82754F54:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x8244d150
	ctx.lr = 0x82754F64;
	sub_8244D150(ctx, base);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r16,1
	r16.s64 = 1;
	// stw r15,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r15.u32);
	// b 0x82755114
	goto loc_82755114;
loc_82754F74:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x827550b8
	if (!cr6.eq) goto loc_827550B8;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r23,r28,24
	r23.s64 = r28.s64 + 24;
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
	// mulli r11,r31,3
	r11.s64 = r31.s64 * 3;
	// add r27,r11,r30
	r27.u64 = r11.u64 + r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x82754FAC;
	sub_823DA950(ctx, base);
	// mulli r11,r31,7
	r11.s64 = r31.s64 * 7;
	// add r24,r11,r30
	r24.u64 = r11.u64 + r30.u64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823da950
	ctx.lr = 0x82754FC4;
	sub_823DA950(ctx, base);
	// rlwinm. r25,r31,1,0,30
	r25.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// mr r26,r30
	r26.u64 = r30.u64;
	// ble 0x82755038
	if (!cr0.gt) goto loc_82755038;
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_82754FDC:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// clrlwi r4,r11,28
	ctx.r4.u64 = r11.u32 & 0xF;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82753758
	ctx.lr = 0x82754FF4;
	sub_82753758(ctx, base);
	// lha r11,0(r26)
	r11.s64 = int16_t(PPC_LOAD_U16(r26.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// sth r11,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r11.u16);
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// rlwinm r4,r11,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x82753758
	ctx.lr = 0x8275501C;
	sub_82753758(ctx, base);
	// lha r11,0(r26)
	r11.s64 = int16_t(PPC_LOAD_U16(r26.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// sth r11,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r11.u16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// bne 0x82754fdc
	if (!cr0.eq) goto loc_82754FDC;
loc_82755038:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r24
	r27.u64 = r24.u64;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82755104
	if (!cr6.gt) goto loc_82755104;
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
loc_82755058:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// clrlwi r4,r11,28
	ctx.r4.u64 = r11.u32 & 0xF;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82753758
	ctx.lr = 0x82755070;
	sub_82753758(ctx, base);
	// lha r11,0(r31)
	r11.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// rlwinm r4,r11,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82753758
	ctx.lr = 0x82755098;
	sub_82753758(ctx, base);
	// lha r11,0(r31)
	r11.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// bne 0x82755058
	if (!cr0.eq) goto loc_82755058;
	// b 0x82755104
	goto loc_82755104;
loc_827550B8:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82755118
	if (!cr6.eq) goto loc_82755118;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82755104
	if (cr6.eq) goto loc_82755104;
loc_827550DC:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lhzx r8,r8,r18
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + r18.u32);
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// bne 0x827550dc
	if (!cr0.eq) goto loc_827550DC;
loc_82755104:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r15,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r15.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
loc_82755114:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_82755118:
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754aa0
	ctx.lr = 0x82755128;
	sub_82754AA0(ctx, base);
	// lwz r11,144(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x827551c8
	if (!cr6.eq) goto loc_827551C8;
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r30,r15
	r30.u64 = r15.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827551c8
	if (!cr6.gt) goto loc_827551C8;
	// addi r27,r28,88
	r27.s64 = r28.s64 + 88;
loc_82755148:
	// lwz r11,132(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// divw r11,r11,r14
	r11.s32 = r11.s32 / r14.s32;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82755168
	if (cr6.lt) goto loc_82755168;
	// mr r31,r15
	r31.u64 = r15.u64;
	// b 0x82755174
	goto loc_82755174;
loc_82755168:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
loc_82755174:
	// lwz r26,0(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8244d150
	ctx.lr = 0x82755188;
	sub_8244D150(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r11.u32);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r11,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r11.u32);
	// bl 0x82754d58
	ctx.lr = 0x827551A8;
	sub_82754D58(ctx, base);
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82755148
	if (cr6.lt) goto loc_82755148;
loc_827551C8:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827551f0
	if (cr6.eq) goto loc_827551F0;
	// lwz r10,4(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827551e4
	if (!cr6.eq) goto loc_827551E4;
	// stw r15,4(r21)
	PPC_STORE_U32(r21.u32 + 4, r15.u32);
loc_827551E4:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r10.u32);
	// stw r15,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r15.u32);
loc_827551F0:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82755208
	if (!cr6.eq) goto loc_82755208;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754c88
	ctx.lr = 0x82755208;
	sub_82754C88(ctx, base);
loc_82755208:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// lwz r20,0(r21)
	r20.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// bne cr6,0x82754ef4
	if (!cr6.eq) goto loc_82754EF4;
loc_82755224:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r30,r15
	r30.u64 = r15.u64;
	// stw r19,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r19.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827552d0
	if (!cr6.gt) goto loc_827552D0;
	// addi r31,r28,80
	r31.s64 = r28.s64 + 80;
loc_8275523C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulli r11,r11,3
	r11.s64 = r11.s64 * 3;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,344
	ctx.r10.s64 = r11.s64 + 344;
	// addi r11,r11,332
	r11.s64 = r11.s64 + 332;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// bl 0x8274f5a0
	ctx.lr = 0x82755278;
	sub_8274F5A0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82755288:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827552a0
	if (cr6.eq) goto loc_827552A0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x827552b4
	if (cr6.eq) goto loc_827552B4;
loc_827552A0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x82755288
	if (cr6.lt) goto loc_82755288;
	// stw r15,144(r28)
	PPC_STORE_U32(r28.u32 + 144, r15.u32);
loc_827552B4:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8275523c
	if (cr6.lt) goto loc_8275523C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827553c0
	if (cr6.lt) goto loc_827553C0;
loc_827552D0:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r31,r15
	r31.u64 = r15.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827553c0
	if (!cr6.gt) goto loc_827553C0;
	// li r29,24
	r29.s64 = 24;
loc_827552E4:
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r30,r11,100
	r30.s64 = r11.s64 + 100;
	// lwz r11,100(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 100);
loc_827552F4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// bne cr6,0x82755318
	if (!cr6.eq) goto loc_82755318;
	// lwz r11,132(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// divw r11,r11,r14
	r11.s32 = r11.s32 / r14.s32;
	// b 0x8275532c
	goto loc_8275532C;
loc_82755318:
	// addi r11,r31,31
	r11.s64 = r31.s64 + 31;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// divw r11,r11,r29
	r11.s32 = r11.s32 / r29.s32;
loc_8275532C:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82755340
	if (cr6.lt) goto loc_82755340;
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// b 0x8275534c
	goto loc_8275534C;
loc_82755340:
	// lwz r10,96(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
loc_8275534C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82755390
	if (cr6.eq) goto loc_82755390;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82755384
	if (!cr6.eq) goto loc_82755384;
	// stw r15,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r15.u32);
loc_82755384:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// stw r15,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r15.u32);
loc_82755390:
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// bne 0x827553a8
	if (!cr0.eq) goto loc_827553A8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754c88
	ctx.lr = 0x827553A8;
	sub_82754C88(ctx, base);
loc_827553A8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x827552f4
	goto loc_827552F4;
loc_827553B0:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x827552e4
	if (cr6.lt) goto loc_827552E4;
loc_827553C0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82754E98) {
	__imp__sub_82754E98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827553CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827553CC) {
	__imp__sub_827553CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827553D0) {
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
	ctx.lr = 0x827553D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827554c4
	if (cr6.eq) goto loc_827554C4;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// li r29,0
	r29.s64 = 0;
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82755460
	if (!cr6.gt) goto loc_82755460;
	// addi r31,r30,124
	r31.s64 = r30.s64 + 124;
loc_82755400:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x82755414;
	sub_8274F6C8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82755430
	if (cr6.eq) goto loc_82755430;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x8275542C;
	sub_821310F8(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_82755430:
	// lwz r3,-36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275544c
	if (cr6.eq) goto loc_8275544C;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x82755448;
	sub_821310F8(ctx, base);
	// stw r29,-36(r31)
	PPC_STORE_U32(r31.u32 + -36, r29.u32);
loc_8275544C:
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82755400
	if (cr6.lt) goto loc_82755400;
loc_82755460:
	// lwz r3,96(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275547c
	if (cr6.eq) goto loc_8275547C;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x82755478;
	sub_821310F8(ctx, base);
	// stw r29,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r29.u32);
loc_8275547C:
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82755498
	if (cr6.eq) goto loc_82755498;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x82755494;
	sub_821310F8(ctx, base);
	// stw r29,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r29.u32);
loc_82755498:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827554b4
	if (cr6.eq) goto loc_827554B4;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x827554B0;
	sub_821310F8(ctx, base);
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
loc_827554B4:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,32781
	ctx.r4.u64 = ctx.r4.u64 | 32781;
	// bl 0x821310f8
	ctx.lr = 0x827554C4;
	sub_821310F8(ctx, base);
loc_827554C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827553D0) {
	__imp__sub_827553D0(ctx, base);
}

