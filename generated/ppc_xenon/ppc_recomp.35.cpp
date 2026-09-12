#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8227421C"))) PPC_WEAK_FUNC(sub_8227421C);
PPC_FUNC_IMPL(__imp__sub_8227421C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274220"))) PPC_WEAK_FUNC(sub_82274220);
PPC_FUNC_IMPL(__imp__sub_82274220) {
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
	ctx.lr = 0x82274228;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8796
	ctx.r10.s64 = r11.s64 + 8796;
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
	// bl 0x82275ca8
	ctx.lr = 0x8227425C;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82274294
	if (cr6.eq) goto loc_82274294;
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
	ctx.lr = 0x82274284;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274298
	if (!cr6.eq) goto loc_82274298;
loc_82274294:
	// li r11,0
	r11.s64 = 0;
loc_82274298:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822742A4"))) PPC_WEAK_FUNC(sub_822742A4);
PPC_FUNC_IMPL(__imp__sub_822742A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822742A8"))) PPC_WEAK_FUNC(sub_822742A8);
PPC_FUNC_IMPL(__imp__sub_822742A8) {
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
	ctx.lr = 0x822742B0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8828
	ctx.r10.s64 = r11.s64 + 8828;
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
	// bl 0x82275ca8
	ctx.lr = 0x822742E4;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227431c
	if (cr6.eq) goto loc_8227431C;
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
	ctx.lr = 0x8227430C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274320
	if (!cr6.eq) goto loc_82274320;
loc_8227431C:
	// li r11,0
	r11.s64 = 0;
loc_82274320:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227432C"))) PPC_WEAK_FUNC(sub_8227432C);
PPC_FUNC_IMPL(__imp__sub_8227432C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274330"))) PPC_WEAK_FUNC(sub_82274330);
PPC_FUNC_IMPL(__imp__sub_82274330) {
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
	ctx.lr = 0x82274338;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82273280
	ctx.lr = 0x82274344;
	sub_82273280(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-972
	ctx.r10.s64 = r11.s64 + -972;
	// addi r28,r31,312
	r28.s64 = r31.s64 + 312;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r29,49
	r29.s64 = 49;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// stw r30,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r30.u32);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// stw r30,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r30.u32);
loc_82274374:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825006b8
	ctx.lr = 0x8227437C;
	sub_825006B8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,196
	r28.s64 = r28.s64 + 196;
	// bge 0x82274374
	if (!cr0.lt) goto loc_82274374;
	// stb r30,10112(r31)
	PPC_STORE_U8(r31.u32 + 10112, r30.u8);
	// addi r3,r31,10116
	ctx.r3.s64 = r31.s64 + 10116;
	// bl 0x824ff7d0
	ctx.lr = 0x82274394;
	sub_824FF7D0(ctx, base);
	// stw r30,10236(r31)
	PPC_STORE_U32(r31.u32 + 10236, r30.u32);
	// stw r30,10240(r31)
	PPC_STORE_U32(r31.u32 + 10240, r30.u32);
	// li r3,2112
	ctx.r3.s64 = 2112;
	// stw r30,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, r30.u32);
	// stw r30,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822743AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822743bc
	if (cr6.eq) goto loc_822743BC;
	// bl 0x8229a428
	ctx.lr = 0x822743B8;
	sub_8229A428(ctx, base);
	// b 0x822743c0
	goto loc_822743C0;
loc_822743BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822743C0:
	// stw r3,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, ctx.r3.u32);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// stw r30,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r30.u32);
	// sth r30,10260(r31)
	PPC_STORE_U16(r31.u32 + 10260, r30.u16);
	// sth r30,10262(r31)
	PPC_STORE_U16(r31.u32 + 10262, r30.u16);
	// bl 0x824ff928
	ctx.lr = 0x822743D8;
	sub_824FF928(ctx, base);
	// stw r30,10584(r31)
	PPC_STORE_U32(r31.u32 + 10584, r30.u32);
	// stw r30,10588(r31)
	PPC_STORE_U32(r31.u32 + 10588, r30.u32);
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x822743E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822743f8
	if (cr6.eq) goto loc_822743F8;
	// bl 0x824fef88
	ctx.lr = 0x822743F4;
	sub_824FEF88(ctx, base);
	// b 0x822743fc
	goto loc_822743FC;
loc_822743F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822743FC:
	// stw r3,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, ctx.r3.u32);
	// addi r3,r31,10600
	ctx.r3.s64 = r31.s64 + 10600;
	// bl 0x825004d0
	ctx.lr = 0x82274408;
	sub_825004D0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82274410;
	sub_82130528(ctx, base);
	// stw r3,10816(r31)
	PPC_STORE_U32(r31.u32 + 10816, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8227441C;
	sub_82130528(ctx, base);
	// stw r3,10820(r31)
	PPC_STORE_U32(r31.u32 + 10820, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,10824(r31)
	PPC_STORE_U8(r31.u32 + 10824, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82274430"))) PPC_WEAK_FUNC(sub_82274430);
PPC_FUNC_IMPL(__imp__sub_82274430) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,10256
	ctx.r3.s64 = ctx.r3.s64 + 10256;
	// bl 0x8262e420
	ctx.lr = 0x82274450;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82274468"))) PPC_WEAK_FUNC(sub_82274468);
PPC_FUNC_IMPL(__imp__sub_82274468) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822744a8
	if (cr6.eq) goto loc_822744A8;
loc_82274488:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8227449c
	if (cr6.eq) goto loc_8227449C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8227449C;
	sub_82273AE0(ctx, base);
loc_8227449C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274488
	if (!cr6.eq) goto loc_82274488;
loc_822744A8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822744BC"))) PPC_WEAK_FUNC(sub_822744BC);
PPC_FUNC_IMPL(__imp__sub_822744BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822744C0"))) PPC_WEAK_FUNC(sub_822744C0);
PPC_FUNC_IMPL(__imp__sub_822744C0) {
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
	ctx.lr = 0x822744C8;
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
	// blt cr6,0x82274534
	if (cr6.lt) goto loc_82274534;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822744F0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274514
	if (!cr6.eq) goto loc_82274514;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274508;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274534
	if (cr6.eq) goto loc_82274534;
loc_82274514:
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
	// bl 0x82274220
	ctx.lr = 0x8227452C;
	sub_82274220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82274534:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82274540"))) PPC_WEAK_FUNC(sub_82274540);
PPC_FUNC_IMPL(__imp__sub_82274540) {
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
	ctx.lr = 0x82274548;
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
	// blt cr6,0x822745b4
	if (cr6.lt) goto loc_822745B4;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x82274570;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274594
	if (!cr6.eq) goto loc_82274594;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274588;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822745b4
	if (cr6.eq) goto loc_822745B4;
loc_82274594:
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
	// bl 0x822742a8
	ctx.lr = 0x822745AC;
	sub_822742A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822745B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822745C0"))) PPC_WEAK_FUNC(sub_822745C0);
PPC_FUNC_IMPL(__imp__sub_822745C0) {
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
	ctx.lr = 0x822745C8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,8860
	ctx.r10.s64 = r11.s64 + 8860;
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
	// bl 0x82273e10
	ctx.lr = 0x822745FC;
	sub_82273E10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82274634
	if (cr6.eq) goto loc_82274634;
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
	ctx.lr = 0x82274624;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82274638
	if (!cr6.eq) goto loc_82274638;
loc_82274634:
	// li r11,0
	r11.s64 = 0;
loc_82274638:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82274644"))) PPC_WEAK_FUNC(sub_82274644);
PPC_FUNC_IMPL(__imp__sub_82274644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274648"))) PPC_WEAK_FUNC(sub_82274648);
PPC_FUNC_IMPL(__imp__sub_82274648) {
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
	ctx.lr = 0x82274650;
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
	ctx.lr = 0x82274678;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822746ac
	if (cr6.eq) goto loc_822746AC;
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
	// beq cr6,0x822746a4
	if (cr6.eq) goto loc_822746A4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822746ac
	if (!cr6.eq) goto loc_822746AC;
loc_822746A4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822746b0
	goto loc_822746B0;
loc_822746AC:
	// li r11,0
	r11.s64 = 0;
loc_822746B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822746ec
	if (cr6.eq) goto loc_822746EC;
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
	// bl 0x822744c0
	ctx.lr = 0x822746E4;
	sub_822744C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822746EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822746F8"))) PPC_WEAK_FUNC(sub_822746F8);
PPC_FUNC_IMPL(__imp__sub_822746F8) {
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
	ctx.lr = 0x82274700;
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
	ctx.lr = 0x82274728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227475c
	if (cr6.eq) goto loc_8227475C;
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
	// beq cr6,0x82274754
	if (cr6.eq) goto loc_82274754;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227475c
	if (!cr6.eq) goto loc_8227475C;
loc_82274754:
	// li r11,1
	r11.s64 = 1;
	// b 0x82274760
	goto loc_82274760;
loc_8227475C:
	// li r11,0
	r11.s64 = 0;
loc_82274760:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227479c
	if (cr6.eq) goto loc_8227479C;
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
	// bl 0x82274540
	ctx.lr = 0x82274794;
	sub_82274540(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227479C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822747A8"))) PPC_WEAK_FUNC(sub_822747A8);
PPC_FUNC_IMPL(__imp__sub_822747A8) {
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
	ctx.lr = 0x822747B0;
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
	// blt cr6,0x8227481c
	if (cr6.lt) goto loc_8227481C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822747D8;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822747fc
	if (!cr6.eq) goto loc_822747FC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x822747F0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227481c
	if (cr6.eq) goto loc_8227481C;
loc_822747FC:
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
	// bl 0x822745c0
	ctx.lr = 0x82274814;
	sub_822745C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227481C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82274828"))) PPC_WEAK_FUNC(sub_82274828);
PPC_FUNC_IMPL(__imp__sub_82274828) {
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
	// lbz r10,281(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 281);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82274888
	if (cr6.eq) goto loc_82274888;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r4,281(r3)
	PPC_STORE_U8(ctx.r3.u32 + 281, ctx.r4.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// beq cr6,0x82274884
	if (cr6.eq) goto loc_82274884;
	// bl 0x82274648
	ctx.lr = 0x82274874;
	sub_82274648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82274884:
	// bl 0x822746f8
	ctx.lr = 0x82274888;
	sub_822746F8(ctx, base);
loc_82274888:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82274898"))) PPC_WEAK_FUNC(sub_82274898);
PPC_FUNC_IMPL(__imp__sub_82274898) {
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
	ctx.lr = 0x822748A0;
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
	ctx.lr = 0x822748C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822748fc
	if (cr6.eq) goto loc_822748FC;
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
	// beq cr6,0x822748f4
	if (cr6.eq) goto loc_822748F4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822748fc
	if (!cr6.eq) goto loc_822748FC;
loc_822748F4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82274900
	goto loc_82274900;
loc_822748FC:
	// li r11,0
	r11.s64 = 0;
loc_82274900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227493c
	if (cr6.eq) goto loc_8227493C;
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
	// bl 0x822747a8
	ctx.lr = 0x82274934;
	sub_822747A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227493C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82274948"))) PPC_WEAK_FUNC(sub_82274948);
PPC_FUNC_IMPL(__imp__sub_82274948) {
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
	ctx.lr = 0x82274950;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8227496C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82274984;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822749b8
	if (cr6.eq) goto loc_822749B8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822749b0
	if (cr6.eq) goto loc_822749B0;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822749b8
	if (!cr6.eq) goto loc_822749B8;
loc_822749B0:
	// li r11,1
	r11.s64 = 1;
	// b 0x822749bc
	goto loc_822749BC;
loc_822749B8:
	// li r11,0
	r11.s64 = 0;
loc_822749BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274a40
	if (cr6.eq) goto loc_82274A40;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82274a30
	if (cr6.lt) goto loc_82274A30;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x822749F0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82274a14
	if (!cr6.eq) goto loc_82274A14;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82274A08;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274a30
	if (cr6.eq) goto loc_82274A30;
loc_82274A14:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822745c0
	ctx.lr = 0x82274A2C;
	sub_822745C0(ctx, base);
	// b 0x82274a34
	goto loc_82274A34;
loc_82274A30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82274A34:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_82274A40:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227496c
	if (cr6.lt) goto loc_8227496C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82274A58"))) PPC_WEAK_FUNC(sub_82274A58);
PPC_FUNC_IMPL(__imp__sub_82274A58) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824f0498
	ctx.lr = 0x82274A7C;
	sub_824F0498(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618750
	ctx.lr = 0x82274A84;
	sub_82618750(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618640
	ctx.lr = 0x82274A94;
	sub_82618640(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82272c78
	ctx.lr = 0x82274AA0;
	sub_82272C78(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82274898
	ctx.lr = 0x82274AC4;
	sub_82274898(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_82274ADC"))) PPC_WEAK_FUNC(sub_82274ADC);
PPC_FUNC_IMPL(__imp__sub_82274ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274AE0"))) PPC_WEAK_FUNC(sub_82274AE0);
PPC_FUNC_IMPL(__imp__sub_82274AE0) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274b64
	if (cr6.eq) goto loc_82274B64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x82274B0C;
	sub_824F0498(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618750
	ctx.lr = 0x82274B14;
	sub_82618750(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82618640
	ctx.lr = 0x82274B24;
	sub_82618640(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82272b98
	ctx.lr = 0x82274B30;
	sub_82272B98(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82274948
	ctx.lr = 0x82274B4C;
	sub_82274948(ctx, base);
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,14
	ctx.r5.s64 = 14;
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82274B64;
	sub_822990D8(ctx, base);
loc_82274B64:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_82274B7C"))) PPC_WEAK_FUNC(sub_82274B7C);
PPC_FUNC_IMPL(__imp__sub_82274B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274B80"))) PPC_WEAK_FUNC(sub_82274B80);
PPC_FUNC_IMPL(__imp__sub_82274B80) {
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
	ctx.lr = 0x82274B88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r6,304(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82274be8
	if (cr6.eq) goto loc_82274BE8;
	// lwz r11,288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274be8
	if (cr6.eq) goto loc_82274BE8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82274bbc
	if (!cr6.eq) goto loc_82274BBC;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x82274bd0
	goto loc_82274BD0;
loc_82274BBC:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82274BC8;
	sub_82272A48(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82274BD0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82274BE4;
	sub_822990D8(ctx, base);
	// stw r29,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r29.u32);
loc_82274BE8:
	// lwz r11,10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10236);
	// addi r30,r31,10236
	r30.s64 = r31.s64 + 10236;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274c20
	if (cr6.eq) goto loc_82274C20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82274c10
	if (cr6.eq) goto loc_82274C10;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82274c10
	if (cr6.eq) goto loc_82274C10;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82274c20
	if (!cr6.eq) goto loc_82274C20;
loc_82274C10:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82274C1C;
	sub_821CE080(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_82274C20:
	// lhz r11,10260(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274c70
	if (cr6.eq) goto loc_82274C70;
	// lwz r11,10584(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10584);
	// addi r6,r31,10584
	ctx.r6.s64 = r31.s64 + 10584;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82274c70
	if (cr6.eq) goto loc_82274C70;
	// lhz r10,10260(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r31,10256
	r11.s64 = r31.s64 + 10256;
	// lwz r5,-4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// bl 0x824ffc88
	ctx.lr = 0x82274C60;
	sub_824FFC88(ctx, base);
	// lhz r8,10260(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 10260);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// sth r7,10260(r31)
	PPC_STORE_U16(r31.u32 + 10260, ctx.r7.u16);
loc_82274C70:
	// lwz r3,10592(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10592);
	// bl 0x824fed28
	ctx.lr = 0x82274C78;
	sub_824FED28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82274C80"))) PPC_WEAK_FUNC(sub_82274C80);
PPC_FUNC_IMPL(__imp__sub_82274C80) {
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
	ctx.lr = 0x82274C88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-972
	ctx.r10.s64 = r11.s64 + -972;
	// lwz r30,10592(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 10592);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82274cb8
	if (cr6.eq) goto loc_82274CB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fefd8
	ctx.lr = 0x82274CB0;
	sub_824FEFD8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82274CB8;
	sub_82130588(ctx, base);
loc_82274CB8:
	// lwz r30,10252(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82274cdc
	if (cr6.eq) goto loc_82274CDC;
	// addi r3,r30,2092
	ctx.r3.s64 = r30.s64 + 2092;
	// bl 0x82274468
	ctx.lr = 0x82274CCC;
	sub_82274468(ctx, base);
	// addi r3,r30,2080
	ctx.r3.s64 = r30.s64 + 2080;
	// bl 0x82274468
	ctx.lr = 0x82274CD4;
	sub_82274468(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82274CDC;
	sub_82130588(ctx, base);
loc_82274CDC:
	// lbz r11,10824(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274cf8
	if (cr6.eq) goto loc_82274CF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821326a8
	ctx.lr = 0x82274CF8;
	sub_821326A8(ctx, base);
loc_82274CF8:
	// lwz r3,10816(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10816);
	// bl 0x82130588
	ctx.lr = 0x82274D00;
	sub_82130588(ctx, base);
	// lwz r3,10820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10820);
	// bl 0x82130588
	ctx.lr = 0x82274D08;
	sub_82130588(ctx, base);
	// addi r3,r31,10600
	ctx.r3.s64 = r31.s64 + 10600;
	// bl 0x82500550
	ctx.lr = 0x82274D10;
	sub_82500550(ctx, base);
	// addi r3,r31,10264
	ctx.r3.s64 = r31.s64 + 10264;
	// bl 0x824ffc18
	ctx.lr = 0x82274D18;
	sub_824FFC18(ctx, base);
	// lhz r11,10262(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10262);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274d2c
	if (cr6.eq) goto loc_82274D2C;
	// lwz r3,10256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// bl 0x82130588
	ctx.lr = 0x82274D2C;
	sub_82130588(ctx, base);
loc_82274D2C:
	// addi r3,r31,10116
	ctx.r3.s64 = r31.s64 + 10116;
	// bl 0x824ff810
	ctx.lr = 0x82274D34;
	sub_824FF810(ctx, base);
	// addi r30,r31,10112
	r30.s64 = r31.s64 + 10112;
	// li r29,49
	r29.s64 = 49;
loc_82274D3C:
	// addi r30,r30,-196
	r30.s64 = r30.s64 + -196;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82274D48;
	sub_82130000(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x82274d3c
	if (!cr0.lt) goto loc_82274D3C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-1020
	ctx.r10.s64 = r11.s64 + -1020;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82274D64"))) PPC_WEAK_FUNC(sub_82274D64);
PPC_FUNC_IMPL(__imp__sub_82274D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274D68"))) PPC_WEAK_FUNC(sub_82274D68);
PPC_FUNC_IMPL(__imp__sub_82274D68) {
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
	// bl 0x8229af08
	ctx.lr = 0x82274D88;
	sub_8229AF08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82274D98;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_82274DB4"))) PPC_WEAK_FUNC(sub_82274DB4);
PPC_FUNC_IMPL(__imp__sub_82274DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274DB8"))) PPC_WEAK_FUNC(sub_82274DB8);
PPC_FUNC_IMPL(__imp__sub_82274DB8) {
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
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82274DD8;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82274DDC;
	sub_824F97C0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0da0
	ctx.lr = 0x82274DF4;
	sub_824F0DA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274e10
	if (cr6.eq) goto loc_82274E10;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0d28
	ctx.lr = 0x82274E10;
	sub_824F0D28(ctx, base);
loc_82274E10:
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0ce0
	ctx.lr = 0x82274E20;
	sub_824F0CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274e3c
	if (cr6.eq) goto loc_82274E3C;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f1558
	ctx.lr = 0x82274E3C;
	sub_824F1558(ctx, base);
loc_82274E3C:
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

__attribute__((alias("__imp__sub_82274E54"))) PPC_WEAK_FUNC(sub_82274E54);
PPC_FUNC_IMPL(__imp__sub_82274E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274E58"))) PPC_WEAK_FUNC(sub_82274E58);
PPC_FUNC_IMPL(__imp__sub_82274E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82274e7c
	if (cr6.lt) goto loc_82274E7C;
	// cmpwi cr6,r4,31
	cr6.compare<int32_t>(ctx.r4.s32, 31, xer);
	// bge cr6,0x82274e7c
	if (!cr6.lt) goto loc_82274E7C;
	// mulli r11,r4,220
	r11.s64 = ctx.r4.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
loc_82274E7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82274E84"))) PPC_WEAK_FUNC(sub_82274E84);
PPC_FUNC_IMPL(__imp__sub_82274E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274E88"))) PPC_WEAK_FUNC(sub_82274E88);
PPC_FUNC_IMPL(__imp__sub_82274E88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r11,r3,2
	r11.s64 = ctx.r3.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,276
	r11.s64 = r11.s64 + 276;
loc_82274E94:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x82274eb8
	if (cr6.eq) goto loc_82274EB8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82274e94
	if (cr6.lt) goto loc_82274E94;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82274EB8:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82274ECC"))) PPC_WEAK_FUNC(sub_82274ECC);
PPC_FUNC_IMPL(__imp__sub_82274ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274ED0"))) PPC_WEAK_FUNC(sub_82274ED0);
PPC_FUNC_IMPL(__imp__sub_82274ED0) {
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
	ctx.lr = 0x82274ED8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addis r31,r28,2
	r31.s64 = r28.s64 + 131072;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r31,276
	r31.s64 = r31.s64 + 276;
loc_82274EF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82274f10
	if (cr6.eq) goto loc_82274F10;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82274F04;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82274F08;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r29
	cr6.compare<uint64_t>(ctx.r3.u64, r29.u64, xer);
	// beq cr6,0x82274f2c
	if (cr6.eq) goto loc_82274F2C;
loc_82274F10:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// blt cr6,0x82274ef0
	if (cr6.lt) goto loc_82274EF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82274F2C:
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82274F44"))) PPC_WEAK_FUNC(sub_82274F44);
PPC_FUNC_IMPL(__imp__sub_82274F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82274F48"))) PPC_WEAK_FUNC(sub_82274F48);
PPC_FUNC_IMPL(__imp__sub_82274F48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r11,r3,2
	r11.s64 = ctx.r3.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,276
	r11.s64 = r11.s64 + 276;
loc_82274F54:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x82274f78
	if (cr6.eq) goto loc_82274F78;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82274f54
	if (cr6.lt) goto loc_82274F54;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82274F78:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82274F80"))) PPC_WEAK_FUNC(sub_82274F80);
PPC_FUNC_IMPL(__imp__sub_82274F80) {
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
	ctx.lr = 0x82274F88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,292
	r11.s64 = r11.s64 + 292;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275034
	if (cr6.eq) goto loc_82275034;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r8,8
	ctx.r8.s64 = 8;
	// lbz r7,22300(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 22300);
	// ori r6,r7,64
	ctx.r6.u64 = ctx.r7.u64 | 64;
	// stb r6,22300(r10)
	PPC_STORE_U8(ctx.r10.u32 + 22300, ctx.r6.u8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,22260
	r11.s64 = r11.s64 + 22260;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82274FD4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82274fd4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82274FD4;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r31,17268(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82274FFC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275034
	if (cr6.eq) goto loc_82275034;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275014;
	sub_822A3998(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82275034
	if (!cr6.eq) goto loc_82275034;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8227502C;
	sub_822A3998(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a57a0
	ctx.lr = 0x82275034;
	sub_822A57A0(ctx, base);
loc_82275034:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227503C"))) PPC_WEAK_FUNC(sub_8227503C);
PPC_FUNC_IMPL(__imp__sub_8227503C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275040"))) PPC_WEAK_FUNC(sub_82275040);
PPC_FUNC_IMPL(__imp__sub_82275040) {
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
	ctx.lr = 0x82275048;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275064;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822750a0
	if (cr6.eq) goto loc_822750A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8227507C;
	sub_822A3998(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822750a0
	if (!cr6.eq) goto loc_822750A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275094;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82275098;
	sub_822A5578(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a0c20
	ctx.lr = 0x822750A0;
	sub_822A0C20(ctx, base);
loc_822750A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822750A8"))) PPC_WEAK_FUNC(sub_822750A8);
PPC_FUNC_IMPL(__imp__sub_822750A8) {
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
	ctx.lr = 0x822750B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x822750D0;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275108
	if (cr6.eq) goto loc_82275108;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,700(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x821c9790
	ctx.lr = 0x822750F0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x822837b8
	ctx.lr = 0x82275108;
	sub_822837B8(ctx, base);
loc_82275108:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82275110"))) PPC_WEAK_FUNC(sub_82275110);
PPC_FUNC_IMPL(__imp__sub_82275110) {
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
	ctx.lr = 0x82275118;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x82275138;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275164
	if (cr6.eq) goto loc_82275164;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,-12672(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12672);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822837b8
	ctx.lr = 0x82275164;
	sub_822837B8(ctx, base);
loc_82275164:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227516C"))) PPC_WEAK_FUNC(sub_8227516C);
PPC_FUNC_IMPL(__imp__sub_8227516C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275170"))) PPC_WEAK_FUNC(sub_82275170);
PPC_FUNC_IMPL(__imp__sub_82275170) {
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
	ctx.lr = 0x82275178;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227519C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822751B4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822751d8
	if (cr6.eq) goto loc_822751D8;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82342b70
	ctx.lr = 0x822751D8;
	sub_82342B70(ctx, base);
loc_822751D8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822751E0"))) PPC_WEAK_FUNC(sub_822751E0);
PPC_FUNC_IMPL(__imp__sub_822751E0) {
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
	ctx.lr = 0x822751E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275204;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275238
	if (cr6.eq) goto loc_82275238;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8227521C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275238
	if (cr6.eq) goto loc_82275238;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275234;
	sub_822A3998(ctx, base);
	// bl 0x822a7388
	ctx.lr = 0x82275238;
	sub_822A7388(ctx, base);
loc_82275238:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82275240"))) PPC_WEAK_FUNC(sub_82275240);
PPC_FUNC_IMPL(__imp__sub_82275240) {
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
	ctx.lr = 0x82275248;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r28,17268(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82275268;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275330
	if (cr6.eq) goto loc_82275330;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275280;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275330
	if (cr6.eq) goto loc_82275330;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275298;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822752B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1672(r11)
	PPC_STORE_U8(r11.u32 + 1672, ctx.r5.u8);
	// lbz r4,1(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1768(r11)
	PPC_STORE_U8(r11.u32 + 1768, ctx.r9.u8);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1816(r11)
	PPC_STORE_U8(r11.u32 + 1816, ctx.r5.u8);
	// lbz r4,3(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1864(r11)
	PPC_STORE_U8(r11.u32 + 1864, ctx.r9.u8);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,1912(r11)
	PPC_STORE_U8(r11.u32 + 1912, ctx.r5.u8);
	// lbz r4,5(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r3,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1720(r11)
	PPC_STORE_U8(r11.u32 + 1720, ctx.r9.u8);
loc_82275330:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82275338"))) PPC_WEAK_FUNC(sub_82275338);
PPC_FUNC_IMPL(__imp__sub_82275338) {
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
	ctx.lr = 0x82275340;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227535C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275390
	if (cr6.eq) goto loc_82275390;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82275374;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82275390
	if (cr6.eq) goto loc_82275390;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8227538C;
	sub_822A3998(ctx, base);
	// bl 0x822a6de0
	ctx.lr = 0x82275390;
	sub_822A6DE0(ctx, base);
loc_82275390:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82275398"))) PPC_WEAK_FUNC(sub_82275398);
PPC_FUNC_IMPL(__imp__sub_82275398) {
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
	ctx.lr = 0x822753A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x822753BC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822753f8
	if (cr6.eq) goto loc_822753F8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x822753D4;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822753f8
	if (cr6.eq) goto loc_822753F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822a3998
	ctx.lr = 0x822753F0;
	sub_822A3998(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826809f8
	ctx.lr = 0x822753F8;
	sub_826809F8(ctx, base);
loc_822753F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82275400"))) PPC_WEAK_FUNC(sub_82275400);
PPC_FUNC_IMPL(__imp__sub_82275400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r10,r3,2
	ctx.r10.s64 = ctx.r3.s64 + 131072;
	// li r11,1
	r11.s64 = 1;
	// addi r10,r10,508
	ctx.r10.s64 = ctx.r10.s64 + 508;
loc_8227540C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82275434
	if (!cr6.eq) goto loc_82275434;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,220
	ctx.r10.s64 = ctx.r10.s64 + 220;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x8227540c
	if (cr6.lt) goto loc_8227540C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82275434:
	// mulli r11,r11,220
	r11.s64 = r11.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275448"))) PPC_WEAK_FUNC(sub_82275448);
PPC_FUNC_IMPL(__imp__sub_82275448) {
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
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x82275480
	if (!cr6.eq) goto loc_82275480;
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
loc_82275480:
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227549c
	if (!cr6.eq) goto loc_8227549C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r11.u32);
loc_8227549C:
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// li r5,56
	ctx.r5.s64 = 56;
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x822754B0;
	sub_823DA950(ctx, base);
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822754D4"))) PPC_WEAK_FUNC(sub_822754D4);
PPC_FUNC_IMPL(__imp__sub_822754D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822754D8"))) PPC_WEAK_FUNC(sub_822754D8);
PPC_FUNC_IMPL(__imp__sub_822754D8) {
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
	ctx.lr = 0x822754E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r26,r28,52
	r26.s64 = r28.s64 + 52;
	// mr r29,r25
	r29.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_82275500:
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826193a0
	ctx.lr = 0x82275514;
	sub_826193A0(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275538
	if (cr6.eq) goto loc_82275538;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// clrlwi r29,r10,16
	r29.u64 = ctx.r10.u32 & 0xFFFF;
	// lbzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// stbx r9,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, ctx.r9.u8);
	// b 0x82275540
	goto loc_82275540;
loc_82275538:
	// lbzx r11,r31,r27
	r11.u64 = PPC_LOAD_U8(r31.u32 + r27.u32);
	// stbx r11,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, r11.u8);
loc_82275540:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r31,r11,16
	r31.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r31,52
	cr6.compare<uint32_t>(r31.u32, 52, xer);
	// blt cr6,0x82275500
	if (cr6.lt) goto loc_82275500;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82275558"))) PPC_WEAK_FUNC(sub_82275558);
PPC_FUNC_IMPL(__imp__sub_82275558) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,2804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227556c
	if (!cr6.eq) goto loc_8227556C;
	// li r11,0
	r11.s64 = 0;
loc_8227556C:
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275578"))) PPC_WEAK_FUNC(sub_82275578);
PPC_FUNC_IMPL(__imp__sub_82275578) {
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
	ctx.lr = 0x82275580;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r31,r29,52
	r31.s64 = r29.s64 + 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x8227559C;
	sub_82618830(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618af8
	ctx.lr = 0x822755AC;
	sub_82618AF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822755BC;
	sub_82618830(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r27,88(r29)
	PPC_STORE_U16(r29.u32 + 88, r27.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82275628
	if (cr6.eq) goto loc_82275628;
loc_822755D4:
	// clrlwi r28,r11,16
	r28.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r28,52
	cr6.compare<uint32_t>(r28.u32, 52, xer);
	// bge cr6,0x82275628
	if (!cr6.lt) goto loc_82275628;
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x822755F0;
	sub_82618F10(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275618
	if (cr6.eq) goto loc_82275618;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275618
	if (cr6.eq) goto loc_82275618;
	// lhz r10,88(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 88);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,88(r29)
	PPC_STORE_U16(r29.u32 + 88, ctx.r10.u16);
loc_82275618:
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// bne cr6,0x822755d4
	if (!cr6.eq) goto loc_822755D4;
loc_82275628:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275654
	if (cr6.eq) goto loc_82275654;
	// lhz r5,88(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 88);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82275654
	if (cr6.eq) goto loc_82275654;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618f80
	ctx.lr = 0x8227564C;
	sub_82618F80(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82275654:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82275660"))) PPC_WEAK_FUNC(sub_82275660);
PPC_FUNC_IMPL(__imp__sub_82275660) {
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
	ctx.lr = 0x82275668;
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
	// bl 0x826186c0
	ctx.lr = 0x82275684;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822756c4
	if (cr6.eq) goto loc_822756C4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r4,r29,16
	ctx.r4.u64 = r29.u32 & 0xFFFF;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822756AC;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822756B8;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822756C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822756D0"))) PPC_WEAK_FUNC(sub_822756D0);
PPC_FUNC_IMPL(__imp__sub_822756D0) {
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
	ctx.lr = 0x822756D8;
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
	ctx.lr = 0x822756F4;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227573c
	if (cr6.eq) goto loc_8227573C;
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
	ctx.lr = 0x8227571C;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// bl 0x826188d8
	ctx.lr = 0x82275730;
	sub_826188D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227573C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// sth r28,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227574C"))) PPC_WEAK_FUNC(sub_8227574C);
PPC_FUNC_IMPL(__imp__sub_8227574C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275750"))) PPC_WEAK_FUNC(sub_82275750);
PPC_FUNC_IMPL(__imp__sub_82275750) {
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
	ctx.lr = 0x82275758;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// bl 0x82257568
	ctx.lr = 0x82275780;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822757ac
	if (cr6.eq) goto loc_822757AC;
	// addi r5,r30,-1
	ctx.r5.s64 = r30.s64 + -1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x8227579C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822757b0
	if (!cr6.eq) goto loc_822757B0;
loc_822757AC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822757B0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// xor r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822757D0"))) PPC_WEAK_FUNC(sub_822757D0);
PPC_FUNC_IMPL(__imp__sub_822757D0) {
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
	ctx.lr = 0x822757D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r29,r30,64
	r29.s64 = r30.s64 + 64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82293e18
	ctx.lr = 0x822757F4;
	sub_82293E18(ctx, base);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82275800:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275858
	if (cr6.eq) goto loc_82275858;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227584c
	if (cr6.eq) goto loc_8227584C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82275854
	if (cr6.eq) goto loc_82275854;
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
	// bgt 0x82275800
	if (cr0.gt) goto loc_82275800;
	// b 0x82275858
	goto loc_82275858;
loc_8227584C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x82275858
	goto loc_82275858;
loc_82275854:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_82275858:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82293e60
	ctx.lr = 0x8227586C;
	sub_82293E60(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82275878"))) PPC_WEAK_FUNC(sub_82275878);
PPC_FUNC_IMPL(__imp__sub_82275878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCVRegister v33{};
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
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// subf r9,r3,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8227588C:
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
	// bne 0x8227588c
	if (!cr0.eq) goto loc_8227588C;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,80
	r11.s64 = ctx.r4.s64 + 80;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,64(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// stb r10,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r10.u8);
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// lbz r9,65(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 65);
	// stb r9,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, ctx.r9.u8);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,112
	r11.s64 = ctx.r4.s64 + 112;
	// lbz r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 96);
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// stb r8,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r8.u8);
	// lbz r7,97(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 97);
	// stb r7,97(r3)
	PPC_STORE_U8(ctx.r3.u32 + 97, ctx.r7.u8);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,144
	r11.s64 = ctx.r4.s64 + 144;
	// lbz r6,128(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 128);
	// addi r10,r3,144
	ctx.r10.s64 = ctx.r3.s64 + 144;
	// stb r6,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, ctx.r6.u8);
	// lbz r5,129(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 129);
	// stb r5,129(r3)
	PPC_STORE_U8(ctx.r3.u32 + 129, ctx.r5.u8);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,176
	r11.s64 = ctx.r4.s64 + 176;
	// lbz r9,160(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// addi r10,r3,176
	ctx.r10.s64 = ctx.r3.s64 + 176;
	// stb r9,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r9.u8);
	// lbz r8,161(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 161);
	// stb r8,161(r3)
	PPC_STORE_U8(ctx.r3.u32 + 161, ctx.r8.u8);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,208
	r11.s64 = ctx.r4.s64 + 208;
	// lbz r7,192(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 192);
	// addi r10,r3,208
	ctx.r10.s64 = ctx.r3.s64 + 208;
	// stb r7,192(r3)
	PPC_STORE_U8(ctx.r3.u32 + 192, ctx.r7.u8);
	// lbz r6,193(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 193);
	// stb r6,193(r3)
	PPC_STORE_U8(ctx.r3.u32 + 193, ctx.r6.u8);
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,240
	r11.s64 = ctx.r4.s64 + 240;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,224(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 224);
	// addi r10,r3,240
	ctx.r10.s64 = ctx.r3.s64 + 240;
	// stb r5,224(r3)
	PPC_STORE_U8(ctx.r3.u32 + 224, ctx.r5.u8);
	// lbz r9,225(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 225);
	// stb r9,225(r3)
	PPC_STORE_U8(ctx.r3.u32 + 225, ctx.r9.u8);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,272
	r11.s64 = ctx.r4.s64 + 272;
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,256(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 256);
	// addi r10,r3,272
	ctx.r10.s64 = ctx.r3.s64 + 272;
	// stb r8,256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 256, ctx.r8.u8);
	// lbz r7,257(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 257);
	// stb r7,257(r3)
	PPC_STORE_U8(ctx.r3.u32 + 257, ctx.r7.u8);
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,304
	r11.s64 = ctx.r4.s64 + 304;
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,288(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 288);
	// addi r10,r3,304
	ctx.r10.s64 = ctx.r3.s64 + 304;
	// stb r6,288(r3)
	PPC_STORE_U8(ctx.r3.u32 + 288, ctx.r6.u8);
	// lbz r5,289(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 289);
	// stb r5,289(r3)
	PPC_STORE_U8(ctx.r3.u32 + 289, ctx.r5.u8);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,336
	r11.s64 = ctx.r4.s64 + 336;
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,320(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 320);
	// addi r10,r3,336
	ctx.r10.s64 = ctx.r3.s64 + 336;
	// stb r9,320(r3)
	PPC_STORE_U8(ctx.r3.u32 + 320, ctx.r9.u8);
	// lbz r8,321(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 321);
	// stb r8,321(r3)
	PPC_STORE_U8(ctx.r3.u32 + 321, ctx.r8.u8);
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,352(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 352);
	// stb r7,352(r3)
	PPC_STORE_U8(ctx.r3.u32 + 352, ctx.r7.u8);
	// addi r11,r4,368
	r11.s64 = ctx.r4.s64 + 368;
	// lbz r6,353(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 353);
	// stb r6,353(r3)
	PPC_STORE_U8(ctx.r3.u32 + 353, ctx.r6.u8);
	// addi r10,r3,368
	ctx.r10.s64 = ctx.r3.s64 + 368;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,400
	r11.s64 = ctx.r4.s64 + 400;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,384(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 384);
	// stb r5,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, ctx.r5.u8);
	// addi r10,r3,400
	ctx.r10.s64 = ctx.r3.s64 + 400;
	// lbz r9,385(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 385);
	// stb r9,385(r3)
	PPC_STORE_U8(ctx.r3.u32 + 385, ctx.r9.u8);
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,432
	r11.s64 = ctx.r4.s64 + 432;
	// addi r10,r3,432
	ctx.r10.s64 = ctx.r3.s64 + 432;
	// lbz r8,416(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 416);
	// stb r8,416(r3)
	PPC_STORE_U8(ctx.r3.u32 + 416, ctx.r8.u8);
	// lbz r7,417(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 417);
	// stb r7,417(r3)
	PPC_STORE_U8(ctx.r3.u32 + 417, ctx.r7.u8);
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,464
	r11.s64 = ctx.r4.s64 + 464;
	// lbz r6,448(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 448);
	// addi r10,r3,464
	ctx.r10.s64 = ctx.r3.s64 + 464;
	// stb r6,448(r3)
	PPC_STORE_U8(ctx.r3.u32 + 448, ctx.r6.u8);
	// lbz r5,449(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 449);
	// stb r5,449(r3)
	PPC_STORE_U8(ctx.r3.u32 + 449, ctx.r5.u8);
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,496
	r11.s64 = ctx.r4.s64 + 496;
	// stvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,480(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 480);
	// stb r10,480(r3)
	PPC_STORE_U8(ctx.r3.u32 + 480, ctx.r10.u8);
	// addi r10,r3,496
	ctx.r10.s64 = ctx.r3.s64 + 496;
	// lbz r9,481(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 481);
	// stb r9,481(r3)
	PPC_STORE_U8(ctx.r3.u32 + 481, ctx.r9.u8);
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,528
	r11.s64 = ctx.r4.s64 + 528;
	// stvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,528
	ctx.r10.s64 = ctx.r3.s64 + 528;
	// lbz r8,512(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 512);
	// stb r8,512(r3)
	PPC_STORE_U8(ctx.r3.u32 + 512, ctx.r8.u8);
	// lbz r7,513(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 513);
	// stb r7,513(r3)
	PPC_STORE_U8(ctx.r3.u32 + 513, ctx.r7.u8);
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,560
	r11.s64 = ctx.r4.s64 + 560;
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,560
	ctx.r10.s64 = ctx.r3.s64 + 560;
	// lbz r6,544(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 544);
	// stb r6,544(r3)
	PPC_STORE_U8(ctx.r3.u32 + 544, ctx.r6.u8);
	// lbz r5,545(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 545);
	// stb r5,545(r3)
	PPC_STORE_U8(ctx.r3.u32 + 545, ctx.r5.u8);
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,592
	r11.s64 = ctx.r4.s64 + 592;
	// stvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,576(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 576);
	// stb r10,576(r3)
	PPC_STORE_U8(ctx.r3.u32 + 576, ctx.r10.u8);
	// addi r10,r3,592
	ctx.r10.s64 = ctx.r3.s64 + 592;
	// lbz r9,577(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 577);
	// stb r9,577(r3)
	PPC_STORE_U8(ctx.r3.u32 + 577, ctx.r9.u8);
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,624
	r11.s64 = ctx.r4.s64 + 624;
	// stvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,624
	ctx.r10.s64 = ctx.r3.s64 + 624;
	// lbz r8,608(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 608);
	// stb r8,608(r3)
	PPC_STORE_U8(ctx.r3.u32 + 608, ctx.r8.u8);
	// lbz r7,609(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 609);
	// stb r7,609(r3)
	PPC_STORE_U8(ctx.r3.u32 + 609, ctx.r7.u8);
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,656
	r11.s64 = ctx.r4.s64 + 656;
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,656
	ctx.r10.s64 = ctx.r3.s64 + 656;
	// lbz r6,640(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 640);
	// stb r6,640(r3)
	PPC_STORE_U8(ctx.r3.u32 + 640, ctx.r6.u8);
	// lbz r5,641(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 641);
	// stb r5,641(r3)
	PPC_STORE_U8(ctx.r3.u32 + 641, ctx.r5.u8);
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,672(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 672);
	// stb r11,672(r3)
	PPC_STORE_U8(ctx.r3.u32 + 672, r11.u8);
	// addi r11,r4,688
	r11.s64 = ctx.r4.s64 + 688;
	// lbz r10,673(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 673);
	// stb r10,673(r3)
	PPC_STORE_U8(ctx.r3.u32 + 673, ctx.r10.u8);
	// addi r10,r3,688
	ctx.r10.s64 = ctx.r3.s64 + 688;
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,720
	r11.s64 = ctx.r4.s64 + 720;
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,704(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 704);
	// stb r9,704(r3)
	PPC_STORE_U8(ctx.r3.u32 + 704, ctx.r9.u8);
	// addi r10,r3,720
	ctx.r10.s64 = ctx.r3.s64 + 720;
	// lbz r8,705(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 705);
	// stb r8,705(r3)
	PPC_STORE_U8(ctx.r3.u32 + 705, ctx.r8.u8);
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,752
	r11.s64 = ctx.r4.s64 + 752;
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,752
	ctx.r10.s64 = ctx.r3.s64 + 752;
	// lbz r7,736(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 736);
	// stb r7,736(r3)
	PPC_STORE_U8(ctx.r3.u32 + 736, ctx.r7.u8);
	// lbz r6,737(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 737);
	// stb r6,737(r3)
	PPC_STORE_U8(ctx.r3.u32 + 737, ctx.r6.u8);
	// lvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,784
	r11.s64 = ctx.r4.s64 + 784;
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,768(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 768);
	// stb r5,768(r3)
	PPC_STORE_U8(ctx.r3.u32 + 768, ctx.r5.u8);
	// addi r10,r3,784
	ctx.r10.s64 = ctx.r3.s64 + 784;
	// lbz r9,769(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 769);
	// stb r9,769(r3)
	PPC_STORE_U8(ctx.r3.u32 + 769, ctx.r9.u8);
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,816
	r11.s64 = ctx.r4.s64 + 816;
	// stvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,800(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 800);
	// stb r8,800(r3)
	PPC_STORE_U8(ctx.r3.u32 + 800, ctx.r8.u8);
	// addi r10,r3,816
	ctx.r10.s64 = ctx.r3.s64 + 816;
	// lbz r7,801(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 801);
	// stb r7,801(r3)
	PPC_STORE_U8(ctx.r3.u32 + 801, ctx.r7.u8);
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,848
	r11.s64 = ctx.r4.s64 + 848;
	// lbz r6,832(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 832);
	// addi r10,r3,848
	ctx.r10.s64 = ctx.r3.s64 + 848;
	// stb r6,832(r3)
	PPC_STORE_U8(ctx.r3.u32 + 832, ctx.r6.u8);
	// lbz r5,833(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 833);
	// stb r5,833(r3)
	PPC_STORE_U8(ctx.r3.u32 + 833, ctx.r5.u8);
	// lvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,864(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 864);
	// stb r11,864(r3)
	PPC_STORE_U8(ctx.r3.u32 + 864, r11.u8);
	// addi r11,r4,880
	r11.s64 = ctx.r4.s64 + 880;
	// lbz r9,865(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 865);
	// addi r10,r3,880
	ctx.r10.s64 = ctx.r3.s64 + 880;
	// stb r9,865(r3)
	PPC_STORE_U8(ctx.r3.u32 + 865, ctx.r9.u8);
	// lvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,912
	r11.s64 = ctx.r4.s64 + 912;
	// stvx128 v37,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,896(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 896);
	// stb r8,896(r3)
	PPC_STORE_U8(ctx.r3.u32 + 896, ctx.r8.u8);
	// addi r10,r3,912
	ctx.r10.s64 = ctx.r3.s64 + 912;
	// lbz r7,897(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 897);
	// stb r7,897(r3)
	PPC_STORE_U8(ctx.r3.u32 + 897, ctx.r7.u8);
	// lvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,928(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 928);
	// stb r6,928(r3)
	PPC_STORE_U8(ctx.r3.u32 + 928, ctx.r6.u8);
	// addi r11,r4,944
	r11.s64 = ctx.r4.s64 + 944;
	// lbz r5,929(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 929);
	// addi r10,r3,944
	ctx.r10.s64 = ctx.r3.s64 + 944;
	// stb r5,929(r3)
	PPC_STORE_U8(ctx.r3.u32 + 929, ctx.r5.u8);
	// lvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,960(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 960);
	// stb r11,960(r3)
	PPC_STORE_U8(ctx.r3.u32 + 960, r11.u8);
	// addi r11,r4,976
	r11.s64 = ctx.r4.s64 + 976;
	// lbz r9,961(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 961);
	// addi r10,r3,976
	ctx.r10.s64 = ctx.r3.s64 + 976;
	// stb r9,961(r3)
	PPC_STORE_U8(ctx.r3.u32 + 961, ctx.r9.u8);
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,1008
	r11.s64 = ctx.r4.s64 + 1008;
	// stvx128 v34,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,992(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 992);
	// stb r8,992(r3)
	PPC_STORE_U8(ctx.r3.u32 + 992, ctx.r8.u8);
	// addi r10,r3,1008
	ctx.r10.s64 = ctx.r3.s64 + 1008;
	// lbz r7,993(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 993);
	// stb r7,993(r3)
	PPC_STORE_U8(ctx.r3.u32 + 993, ctx.r7.u8);
	// lvx128 v33,r0,r11
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,1024(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1024);
	// stb r6,16(r10)
	PPC_STORE_U8(ctx.r10.u32 + 16, ctx.r6.u8);
	// lbz r5,1025(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1025);
	// stb r5,17(r10)
	PPC_STORE_U8(ctx.r10.u32 + 17, ctx.r5.u8);
	// lbz r11,1040(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1040);
	// stb r11,1040(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1040, r11.u8);
	// lbz r10,1041(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1041);
	// stb r10,1041(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1041, ctx.r10.u8);
	// lbz r9,1042(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1042);
	// stb r9,1042(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1042, ctx.r9.u8);
	// lbz r8,1043(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1043);
	// stb r8,1043(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1043, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275CA4"))) PPC_WEAK_FUNC(sub_82275CA4);
PPC_FUNC_IMPL(__imp__sub_82275CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275CA8"))) PPC_WEAK_FUNC(sub_82275CA8);
PPC_FUNC_IMPL(__imp__sub_82275CA8) {
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
	ctx.lr = 0x82275CB0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x82275CD0;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82275CDC;
	sub_82618750(ctx, base);
	// subf r5,r31,r28
	ctx.r5.s64 = r28.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82275CEC;
	sub_82618640(ctx, base);
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r30,r10,1
	r30.u64 = ctx.r10.u64 ^ 1;
	// beq cr6,0x82275d30
	if (cr6.eq) goto loc_82275D30;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275d28
	if (cr6.eq) goto loc_82275D28;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82275D14;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_82275D28:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82275D30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82275D3C"))) PPC_WEAK_FUNC(sub_82275D3C);
PPC_FUNC_IMPL(__imp__sub_82275D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275D40"))) PPC_WEAK_FUNC(sub_82275D40);
PPC_FUNC_IMPL(__imp__sub_82275D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82275D50:
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82275d50
	if (!cr0.eq) goto loc_82275D50;
	// lbz r11,208(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 208);
	// stw r9,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r9.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r9,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r9.u32);
	// stw r9,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r9.u32);
	// stb r10,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275D84"))) PPC_WEAK_FUNC(sub_82275D84);
PPC_FUNC_IMPL(__imp__sub_82275D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275D88"))) PPC_WEAK_FUNC(sub_82275D88);
PPC_FUNC_IMPL(__imp__sub_82275D88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,4
	ctx.r10.s64 = 4;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275DA4"))) PPC_WEAK_FUNC(sub_82275DA4);
PPC_FUNC_IMPL(__imp__sub_82275DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275DA8"))) PPC_WEAK_FUNC(sub_82275DA8);
PPC_FUNC_IMPL(__imp__sub_82275DA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,5
	ctx.r10.s64 = 5;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82275DCC"))) PPC_WEAK_FUNC(sub_82275DCC);
PPC_FUNC_IMPL(__imp__sub_82275DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82275DD0"))) PPC_WEAK_FUNC(sub_82275DD0);
PPC_FUNC_IMPL(__imp__sub_82275DD0) {
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
	// addi r9,r11,-572
	ctx.r9.s64 = r11.s64 + -572;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82275e04
	if (cr6.eq) goto loc_82275E04;
	// bl 0x82130588
	ctx.lr = 0x82275E00;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82275E04:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82275E18"))) PPC_WEAK_FUNC(sub_82275E18);
PPC_FUNC_IMPL(__imp__sub_82275E18) {
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
	// addi r9,r11,-488
	ctx.r9.s64 = r11.s64 + -488;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82275e4c
	if (cr6.eq) goto loc_82275E4C;
	// bl 0x82130588
	ctx.lr = 0x82275E48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82275E4C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82275E60"))) PPC_WEAK_FUNC(sub_82275E60);
PPC_FUNC_IMPL(__imp__sub_82275E60) {
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
	ctx.lr = 0x82275E68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// addis r27,r29,2
	r27.s64 = r29.s64 + 131072;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r27,r27,6930
	r27.s64 = r27.s64 + 6930;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
	// bl 0x82388580
	ctx.lr = 0x82275E88;
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
	ctx.lr = 0x82275E9C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82275EA4;
	sub_824E70F0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82275efc
	if (cr6.eq) goto loc_82275EFC;
	// bl 0x82387b90
	ctx.lr = 0x82275EB4;
	sub_82387B90(ctx, base);
	// lwz r28,1340(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82275ef4
	if (!cr6.gt) goto loc_82275EF4;
	// addis r29,r29,2
	r29.s64 = r29.s64 + 131072;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r29,6900
	r29.s64 = r29.s64 + 6900;
loc_82275ED0:
	// bl 0x82387b90
	ctx.lr = 0x82275ED4;
	sub_82387B90(ctx, base);
	// add r11,r30,r3
	r11.u64 = r30.u64 + ctx.r3.u64;
	// addi r3,r11,3479
	ctx.r3.s64 = r11.s64 + 3479;
	// bl 0x82392a20
	ctx.lr = 0x82275EE0;
	sub_82392A20(ctx, base);
	// stbx r3,r29,r31
	PPC_STORE_U8(r29.u32 + r31.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,8176
	r30.s64 = r30.s64 + 8176;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x82275ed0
	if (cr6.lt) goto loc_82275ED0;
loc_82275EF4:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
loc_82275EFC:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82275F10"))) PPC_WEAK_FUNC(sub_82275F10);
PPC_FUNC_IMPL(__imp__sub_82275F10) {
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
	ctx.lr = 0x82275F18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82275F30;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r27,r10,276
	r27.u64 = ctx.r10.u64 | 276;
	// beq cr6,0x82275f7c
	if (cr6.eq) goto loc_82275F7C;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r28,r27
	r11.u64 = r28.u64 + r27.u64;
loc_82275F50:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x82275f74
	if (cr6.eq) goto loc_82275F74;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82275f50
	if (cr6.lt) goto loc_82275F50;
	// li r30,-1
	r30.s64 = -1;
	// b 0x82275f80
	goto loc_82275F80;
loc_82275F74:
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// b 0x82275f80
	goto loc_82275F80;
loc_82275F7C:
	// li r30,0
	r30.s64 = 0;
loc_82275F80:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82275F8C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82275fc8
	if (cr6.eq) goto loc_82275FC8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82275FA8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82275fc8
	if (!cr6.eq) goto loc_82275FC8;
	// bl 0x822c4eb8
	ctx.lr = 0x82275FB8;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x82275FC0;
	sub_822C4EC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822cad90
	ctx.lr = 0x82275FC8;
	sub_822CAD90(ctx, base);
loc_82275FC8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82275FD4;
	sub_822A3998(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a5d20
	ctx.lr = 0x82275FE0;
	sub_822A5D20(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276010
	if (cr6.eq) goto loc_82276010;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82276010
	if (cr6.eq) goto loc_82276010;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// extsb r5,r9
	ctx.r5.s64 = ctx.r9.s8;
	// lwz r3,17892(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17892);
	// bl 0x822b6470
	ctx.lr = 0x82276010;
	sub_822B6470(ctx, base);
loc_82276010:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8227601C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276130
	if (cr6.eq) goto loc_82276130;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82276034;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82276038;
	sub_824F97C0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f0ce0
	ctx.lr = 0x82276050;
	sub_824F0CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227606c
	if (!cr6.eq) goto loc_8227606C;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f14e8
	ctx.lr = 0x8227606C;
	sub_824F14E8(ctx, base);
loc_8227606C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82276088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822760A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r28,r27
	r31.u64 = r28.u64 + r27.u64;
	// li r29,0
	r29.s64 = 0;
	// li r30,31
	r30.s64 = 31;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_822760B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822760f4
	if (cr6.eq) goto loc_822760F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822760C8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822760DC;
	sub_82270170(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82272ee8
	ctx.lr = 0x822760E4;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822760f4
	if (cr6.eq) goto loc_822760F4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_822760F4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bne 0x822760b4
	if (!cr0.eq) goto loc_822760B4;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// blt cr6,0x82276130
	if (cr6.lt) goto loc_82276130;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-468
	ctx.r4.s64 = ctx.r10.s64 + -468;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82276130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82276130:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82276138"))) PPC_WEAK_FUNC(sub_82276138);
PPC_FUNC_IMPL(__imp__sub_82276138) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82276158;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822761bc
	if (cr6.eq) goto loc_822761BC;
	// bl 0x82388580
	ctx.lr = 0x8227616C;
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
	ctx.lr = 0x82276180;
	sub_82270170(ctx, base);
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r4,11780(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11780);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822761a8
	if (!cr6.eq) goto loc_822761A8;
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
loc_822761A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822761BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822761BC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822761D0"))) PPC_WEAK_FUNC(sub_822761D0);
PPC_FUNC_IMPL(__imp__sub_822761D0) {
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
	ctx.lr = 0x822761D8;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8304(r1)
	ea = -8304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82387b90
	ctx.lr = 0x822761F4;
	sub_82387B90(ctx, base);
	// mulli r11,r28,8176
	r11.s64 = r28.s64 * 8176;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,1360
	r31.s64 = r11.s64 + 1360;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238f648
	ctx.lr = 0x8227620C;
	sub_8238F648(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822763d8
	if (cr6.eq) goto loc_822763D8;
	// lis r11,2
	r11.s64 = 131072;
	// add r10,r28,r29
	ctx.r10.u64 = r28.u64 + r29.u64;
	// ori r9,r11,6900
	ctx.r9.u64 = r11.u64 | 6900;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822762ac
	if (!cr6.eq) goto loc_822762AC;
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227623C;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227624C;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227625C;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227626C;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227627C;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227628C;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x8227629C;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822762AC;
	sub_823924B0(ctx, base);
loc_822762AC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82276348
	if (cr6.eq) goto loc_82276348;
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x822762c8
	if (cr6.eq) goto loc_822762C8;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822763d8
	if (!cr6.eq) goto loc_822763D8;
loc_822762C8:
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822763d8
	if (cr6.eq) goto loc_822763D8;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822762f8
	if (cr6.eq) goto loc_822762F8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822762f8
	if (cr6.eq) goto loc_822762F8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822762fc
	if (!cr6.eq) goto loc_822762FC;
loc_822762F8:
	// li r11,1
	r11.s64 = 1;
loc_822762FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276334
	if (!cr6.eq) goto loc_82276334;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b480
	ctx.lr = 0x82276310;
	sub_8229B480(ctx, base);
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwz r5,68(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8229bb30
	ctx.lr = 0x82276324;
	sub_8229BB30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x8227632C;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
loc_82276334:
	// stw r28,22296(r10)
	PPC_STORE_U32(ctx.r10.u32 + 22296, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x82276340;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
loc_82276348:
	// addis r31,r29,2
	r31.s64 = r29.s64 + 131072;
	// li r30,31
	r30.s64 = 31;
	// addi r31,r31,292
	r31.s64 = r31.s64 + 292;
loc_82276354:
	// lbz r11,-192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -192);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82276368
	if (cr6.eq) goto loc_82276368;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822763cc
	if (!cr6.eq) goto loc_822763CC;
loc_82276368:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822763cc
	if (cr6.eq) goto loc_822763CC;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82276398
	if (cr6.eq) goto loc_82276398;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82276398
	if (cr6.eq) goto loc_82276398;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8227639c
	if (!cr6.eq) goto loc_8227639C;
loc_82276398:
	// li r11,1
	r11.s64 = 1;
loc_8227639C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822763c8
	if (!cr6.eq) goto loc_822763C8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b480
	ctx.lr = 0x822763B0;
	sub_8229B480(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,68(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,-196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -196);
	// bl 0x8229bb30
	ctx.lr = 0x822763C4;
	sub_8229BB30(ctx, base);
	// b 0x822763cc
	goto loc_822763CC;
loc_822763C8:
	// stw r28,22296(r10)
	PPC_STORE_U32(ctx.r10.u32 + 22296, r28.u32);
loc_822763CC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bne 0x82276354
	if (!cr0.eq) goto loc_82276354;
loc_822763D8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x822763E0;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8304
	ctx.r1.s64 = ctx.r1.s64 + 8304;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822763E8"))) PPC_WEAK_FUNC(sub_822763E8);
PPC_FUNC_IMPL(__imp__sub_822763E8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r31,0(r4)
	r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// bl 0x82388580
	ctx.lr = 0x82276404;
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
	ctx.lr = 0x82276418;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82276424;
	sub_82274128(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82276438"))) PPC_WEAK_FUNC(sub_82276438);
PPC_FUNC_IMPL(__imp__sub_82276438) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x82276458;
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
	ctx.lr = 0x8227646C;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82276474;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8227648C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822764c4
	if (cr6.eq) goto loc_822764C4;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x822764d0
	goto loc_822764D0;
loc_822764C4:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_822764D0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822764EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82276510
	if (cr6.eq) goto loc_82276510;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82680598
	ctx.lr = 0x82276510;
	sub_82680598(ctx, base);
loc_82276510:
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

__attribute__((alias("__imp__sub_82276528"))) PPC_WEAK_FUNC(sub_82276528);
PPC_FUNC_IMPL(__imp__sub_82276528) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82276530;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8432(r1)
	ea = -8432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mulli r11,r30,220
	r11.s64 = r30.s64 * 220;
	// add r28,r11,r3
	r28.u64 = r11.u64 + ctx.r3.u64;
	// addis r31,r28,2
	r31.s64 = r28.s64 + 131072;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r3,r11,22260
	ctx.r3.s64 = r11.s64 + 22260;
	// bl 0x8229b410
	ctx.lr = 0x82276564;
	sub_8229B410(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8216c9c0
	ctx.lr = 0x8227658C;
	sub_8216C9C0(ctx, base);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,30288(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x8238f550
	ctx.lr = 0x822765B0;
	sub_8238F550(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b4f0
	ctx.lr = 0x822765C0;
	sub_8229B4F0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x822765D0;
	sub_821E80F8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227680c
	if (cr6.eq) goto loc_8227680C;
	// bl 0x822c4eb8
	ctx.lr = 0x822765E0;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822765E8;
	sub_822C4EC8(ctx, base);
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822a3998
	ctx.lr = 0x822765FC;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276608;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82276618;
	sub_82270170(ctx, base);
	// bl 0x82272e98
	ctx.lr = 0x8227661C;
	sub_82272E98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276688
	if (!cr6.eq) goto loc_82276688;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276630;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82276640;
	sub_82270170(ctx, base);
	// bl 0x82272ec0
	ctx.lr = 0x82276644;
	sub_82272EC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276680
	if (cr6.eq) goto loc_82276680;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,1220(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x82388580
	ctx.lr = 0x8227665C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227666C;
	sub_82270170(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82272ee8
	ctx.lr = 0x82276674;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82276688
	if (!cr6.eq) goto loc_82276688;
loc_82276680:
	// li r11,0
	r11.s64 = 0;
	// b 0x8227668c
	goto loc_8227668C;
loc_82276688:
	// li r11,1
	r11.s64 = 1;
loc_8227668C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82276720
	if (!cr6.eq) goto loc_82276720;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82393148
	ctx.lr = 0x822766A0;
	sub_82393148(ctx, base);
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766B0;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766C0;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766D0;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766E0;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x822766F0;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276700;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276710;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x823924b0
	ctx.lr = 0x82276720;
	sub_823924B0(ctx, base);
loc_82276720:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e10
	ctx.lr = 0x8227672C;
	sub_822A8E10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82276734;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,-10240(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r25,4(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x82276748;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82276758;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82276760;
	sub_82272A30(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824818a0
	ctx.lr = 0x82276768;
	sub_824818A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82270170
	ctx.lr = 0x82276778;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82276780;
	sub_82272A30(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824818a0
	ctx.lr = 0x82276788;
	sub_824818A0(ctx, base);
	// add r8,r29,r3
	ctx.r8.u64 = r29.u64 + ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// subfic r7,r8,8
	xer.ca = ctx.r8.u32 <= 8;
	ctx.r7.s64 = 8 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r29,r6,31
	r29.u64 = ctx.r6.u32 & 0x1;
	// bl 0x822577d0
	ctx.lr = 0x822767A4;
	sub_822577D0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x822cadf0
	ctx.lr = 0x822767C4;
	sub_822CADF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8838
	ctx.lr = 0x822767CC;
	sub_822A8838(ctx, base);
	// bl 0x822387e8
	ctx.lr = 0x822767D0;
	sub_822387E8(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82238578
	ctx.lr = 0x822767E0;
	sub_82238578(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238988
	ctx.lr = 0x822767E8;
	sub_82238988(ctx, base);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// addis r4,r28,2
	ctx.r4.s64 = r28.s64 + 131072;
	// ori r3,r5,292
	ctx.r3.u64 = ctx.r5.u64 | 292;
	// addi r4,r4,296
	ctx.r4.s64 = ctx.r4.s64 + 296;
	// lwzx r11,r28,r3
	r11.u64 = PPC_LOAD_U32(r28.u32 + ctx.r3.u32);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
loc_8227680C:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8238ed78
	ctx.lr = 0x82276814;
	sub_8238ED78(ctx, base);
	// addi r1,r1,8432
	ctx.r1.s64 = ctx.r1.s64 + 8432;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82276820"))) PPC_WEAK_FUNC(sub_82276820);
PPC_FUNC_IMPL(__imp__sub_82276820) {
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
	ctx.lr = 0x82276828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227684C;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481688
	ctx.lr = 0x82276874;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481590
	ctx.lr = 0x82276888;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x822768A0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822768B8;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822768cc
	if (cr6.eq) goto loc_822768CC;
	// li r3,83
	ctx.r3.s64 = 83;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822768CC:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82299c98
	ctx.lr = 0x822768DC;
	sub_82299C98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822768E4"))) PPC_WEAK_FUNC(sub_822768E4);
PPC_FUNC_IMPL(__imp__sub_822768E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822768E8"))) PPC_WEAK_FUNC(sub_822768E8);
PPC_FUNC_IMPL(__imp__sub_822768E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82276904:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82276928
	if (cr6.eq) goto loc_82276928;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82276904
	if (cr6.lt) goto loc_82276904;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82276928:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// li r10,220
	ctx.r10.s64 = 220;
	// divw r3,r11,r10
	ctx.r3.s32 = r11.s32 / ctx.r10.s32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82276938"))) PPC_WEAK_FUNC(sub_82276938);
PPC_FUNC_IMPL(__imp__sub_82276938) {
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
	ctx.lr = 0x82276940;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addis r11,r30,2
	r11.s64 = r30.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82276958:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822769c0
	if (cr6.eq) goto loc_822769C0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82276958
	if (cr6.lt) goto loc_82276958;
	// li r31,-1
	r31.s64 = -1;
loc_82276978:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276998
	if (cr6.eq) goto loc_82276998;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82275040
	ctx.lr = 0x82276998;
	sub_82275040(ctx, base);
loc_82276998:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822769b8
	if (cr6.eq) goto loc_822769B8;
	// addi r5,r29,16
	ctx.r5.s64 = r29.s64 + 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82274f80
	ctx.lr = 0x822769B8;
	sub_82274F80(ctx, base);
loc_822769B8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822769C0:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// li r10,220
	ctx.r10.s64 = 220;
	// divw r31,r11,r10
	r31.s32 = r11.s32 / ctx.r10.s32;
	// b 0x82276978
	goto loc_82276978;
}

__attribute__((alias("__imp__sub_822769D0"))) PPC_WEAK_FUNC(sub_822769D0);
PPC_FUNC_IMPL(__imp__sub_822769D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,2808(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2808);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82276a14
	if (!cr6.gt) goto loc_82276A14;
	// lwz r11,2804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2804);
	// lis r9,20971
	ctx.r9.s64 = 1374355456;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// ori r7,r9,34079
	ctx.r7.u64 = ctx.r9.u64 | 34079;
	// mulhw r6,r8,r7
	ctx.r6.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r11,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	r11.s64 = ctx.r6.s32 >> 4;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r4,r5,50
	ctx.r4.s64 = ctx.r5.s64 * 50;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
loc_82276A14:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82276A1C"))) PPC_WEAK_FUNC(sub_82276A1C);
PPC_FUNC_IMPL(__imp__sub_82276A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276A20"))) PPC_WEAK_FUNC(sub_82276A20);
PPC_FUNC_IMPL(__imp__sub_82276A20) {
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
	ctx.lr = 0x82276A28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r27,r31,52
	r27.s64 = r31.s64 + 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82618830
	ctx.lr = 0x82276A48;
	sub_82618830(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// sth r11,88(r31)
	PPC_STORE_U16(r31.u32 + 88, r11.u16);
loc_82276A54:
	// lbzx r11,r30,r28
	r11.u64 = PPC_LOAD_U8(r30.u32 + r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lbzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r29.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82276a84
	if (cr6.eq) goto loc_82276A84;
	// lhz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// li r4,1
	ctx.r4.s64 = 1;
	// stbx r11,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, r11.u8);
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// sth r9,88(r31)
	PPC_STORE_U16(r31.u32 + 88, ctx.r9.u16);
loc_82276A84:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618f70
	ctx.lr = 0x82276A8C;
	sub_82618F70(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r30,52
	cr6.compare<uint32_t>(r30.u32, 52, xer);
	// blt cr6,0x82276a54
	if (cr6.lt) goto loc_82276A54;
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// li r10,416
	ctx.r10.s64 = 416;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// addi r9,r11,52
	ctx.r9.s64 = r11.s64 + 52;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// subfc r7,r10,r8
	xer.ca = ctx.r8.u32 >= ctx.r10.u32;
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r6,31
	ctx.r3.u64 = ctx.r6.u32 & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82276AC4"))) PPC_WEAK_FUNC(sub_82276AC4);
PPC_FUNC_IMPL(__imp__sub_82276AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276AC8"))) PPC_WEAK_FUNC(sub_82276AC8);
PPC_FUNC_IMPL(__imp__sub_82276AC8) {
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
	// bl 0x82618f80
	ctx.lr = 0x82276AEC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276b14
	if (cr6.eq) goto loc_82276B14;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82276B04;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276b18
	if (!cr6.eq) goto loc_82276B18;
loc_82276B14:
	// li r11,0
	r11.s64 = 0;
loc_82276B18:
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

__attribute__((alias("__imp__sub_82276B34"))) PPC_WEAK_FUNC(sub_82276B34);
PPC_FUNC_IMPL(__imp__sub_82276B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276B38"))) PPC_WEAK_FUNC(sub_82276B38);
PPC_FUNC_IMPL(__imp__sub_82276B38) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x82276B5C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276b88
	if (cr6.eq) goto loc_82276B88;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276B78;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276b8c
	if (!cr6.eq) goto loc_82276B8C;
loc_82276B88:
	// li r11,0
	r11.s64 = 0;
loc_82276B8C:
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

__attribute__((alias("__imp__sub_82276BA8"))) PPC_WEAK_FUNC(sub_82276BA8);
PPC_FUNC_IMPL(__imp__sub_82276BA8) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618fa0
	ctx.lr = 0x82276BCC;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276bf8
	if (cr6.eq) goto loc_82276BF8;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276BE8;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276bfc
	if (!cr6.eq) goto loc_82276BFC;
loc_82276BF8:
	// li r11,0
	r11.s64 = 0;
loc_82276BFC:
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

__attribute__((alias("__imp__sub_82276C18"))) PPC_WEAK_FUNC(sub_82276C18);
PPC_FUNC_IMPL(__imp__sub_82276C18) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822559f0
	ctx.lr = 0x82276C40;
	sub_822559F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276c6c
	if (cr6.eq) goto loc_82276C6C;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,1056
	ctx.r4.s64 = r30.s64 + 1056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276C5C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276c70
	if (!cr6.eq) goto loc_82276C70;
loc_82276C6C:
	// li r11,0
	r11.s64 = 0;
loc_82276C70:
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

__attribute__((alias("__imp__sub_82276C8C"))) PPC_WEAK_FUNC(sub_82276C8C);
PPC_FUNC_IMPL(__imp__sub_82276C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276C90"))) PPC_WEAK_FUNC(sub_82276C90);
PPC_FUNC_IMPL(__imp__sub_82276C90) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82255ae0
	ctx.lr = 0x82276CB8;
	sub_82255AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276ce4
	if (cr6.eq) goto loc_82276CE4;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,1056
	ctx.r4.s64 = r30.s64 + 1056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276CD4;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276ce8
	if (!cr6.eq) goto loc_82276CE8;
loc_82276CE4:
	// li r11,0
	r11.s64 = 0;
loc_82276CE8:
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

__attribute__((alias("__imp__sub_82276D04"))) PPC_WEAK_FUNC(sub_82276D04);
PPC_FUNC_IMPL(__imp__sub_82276D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276D08"))) PPC_WEAK_FUNC(sub_82276D08);
PPC_FUNC_IMPL(__imp__sub_82276D08) {
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
	ctx.lr = 0x82276D10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82276D2C;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82276d6c
	if (cr6.eq) goto loc_82276D6C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82276D54;
	sub_82618390(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82276D60;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82276D6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82276D78"))) PPC_WEAK_FUNC(sub_82276D78);
PPC_FUNC_IMPL(__imp__sub_82276D78) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276D9C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276dc8
	if (cr6.eq) goto loc_82276DC8;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82276DB8;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276dcc
	if (!cr6.eq) goto loc_82276DCC;
loc_82276DC8:
	// li r11,0
	r11.s64 = 0;
loc_82276DCC:
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

__attribute__((alias("__imp__sub_82276DE8"))) PPC_WEAK_FUNC(sub_82276DE8);
PPC_FUNC_IMPL(__imp__sub_82276DE8) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276E0C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276e38
	if (cr6.eq) goto loc_82276E38;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82276E28;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276e3c
	if (!cr6.eq) goto loc_82276E3C;
loc_82276E38:
	// li r11,0
	r11.s64 = 0;
loc_82276E3C:
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

__attribute__((alias("__imp__sub_82276E58"))) PPC_WEAK_FUNC(sub_82276E58);
PPC_FUNC_IMPL(__imp__sub_82276E58) {
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
	ctx.lr = 0x82276E60;
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
	ctx.lr = 0x82276E7C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276eb4
	if (cr6.eq) goto loc_82276EB4;
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
	ctx.lr = 0x82276EA4;
	sub_82618390(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82276EB0;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_82276EB4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276edc
	if (cr6.eq) goto loc_82276EDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x82276ECC;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276ee0
	if (!cr6.eq) goto loc_82276EE0;
loc_82276EDC:
	// li r11,0
	r11.s64 = 0;
loc_82276EE0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82276EEC"))) PPC_WEAK_FUNC(sub_82276EEC);
PPC_FUNC_IMPL(__imp__sub_82276EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276EF0"))) PPC_WEAK_FUNC(sub_82276EF0);
PPC_FUNC_IMPL(__imp__sub_82276EF0) {
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
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x82276F14;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,1(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// bl 0x82618f70
	ctx.lr = 0x82276F2C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,2(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// bl 0x82618f70
	ctx.lr = 0x82276F44;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,3(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// bl 0x82618f70
	ctx.lr = 0x82276F5C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x82276F74;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82276f9c
	if (cr6.eq) goto loc_82276F9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// bl 0x82618f70
	ctx.lr = 0x82276F8C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82276fa0
	if (!cr6.eq) goto loc_82276FA0;
loc_82276F9C:
	// li r11,0
	r11.s64 = 0;
loc_82276FA0:
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

__attribute__((alias("__imp__sub_82276FBC"))) PPC_WEAK_FUNC(sub_82276FBC);
PPC_FUNC_IMPL(__imp__sub_82276FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82276FC0"))) PPC_WEAK_FUNC(sub_82276FC0);
PPC_FUNC_IMPL(__imp__sub_82276FC0) {
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
	// bl 0x82618f10
	ctx.lr = 0x82276FE0;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82276FF8;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,2
	ctx.r4.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277010;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,3
	ctx.r4.s64 = r30.s64 + 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277028;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277040;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277068
	if (cr6.eq) goto loc_82277068;
	// addi r4,r30,5
	ctx.r4.s64 = r30.s64 + 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82277058;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227706c
	if (!cr6.eq) goto loc_8227706C;
loc_82277068:
	// li r11,0
	r11.s64 = 0;
loc_8227706C:
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

__attribute__((alias("__imp__sub_82277088"))) PPC_WEAK_FUNC(sub_82277088);
PPC_FUNC_IMPL(__imp__sub_82277088) {
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
	ctx.lr = 0x82277090;
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
	// lhz r29,0(r11)
	r29.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822770B0;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822770f0
	if (cr6.eq) goto loc_822770F0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r4,r29,16
	ctx.r4.u64 = r29.u32 & 0xFFFF;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822770D8;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822770E4;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822770F0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822770FC"))) PPC_WEAK_FUNC(sub_822770FC);
PPC_FUNC_IMPL(__imp__sub_822770FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277100"))) PPC_WEAK_FUNC(sub_82277100);
PPC_FUNC_IMPL(__imp__sub_82277100) {
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
	ctx.lr = 0x82277108;
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
	ctx.lr = 0x82277138;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277144;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277154;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277184
	if (cr6.eq) goto loc_82277184;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277184
	if (!cr6.eq) goto loc_82277184;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276ac8
	ctx.lr = 0x82277174;
	sub_82276AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277188
	if (!cr6.eq) goto loc_82277188;
loc_82277184:
	// li r31,0
	r31.s64 = 0;
loc_82277188:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822771b4
	if (cr6.eq) goto loc_822771B4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822771ac
	if (cr6.eq) goto loc_822771AC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822771A4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822771b0
	goto loc_822771B0;
loc_822771AC:
	// li r11,0
	r11.s64 = 0;
loc_822771B0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822771B4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822771d8
	if (cr6.eq) goto loc_822771D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822771C8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822771dc
	if (cr6.eq) goto loc_822771DC;
loc_822771D8:
	// li r11,0
	r11.s64 = 0;
loc_822771DC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822771E8"))) PPC_WEAK_FUNC(sub_822771E8);
PPC_FUNC_IMPL(__imp__sub_822771E8) {
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
	ctx.lr = 0x822771F0;
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
	ctx.lr = 0x82277214;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277220;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277230;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277254
	if (cr6.eq) goto loc_82277254;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229afa8
	ctx.lr = 0x82277244;
	sub_8229AFA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277258
	if (!cr6.eq) goto loc_82277258;
loc_82277254:
	// li r30,0
	r30.s64 = 0;
loc_82277258:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277290
	if (cr6.eq) goto loc_82277290;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277288
	if (cr6.eq) goto loc_82277288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277274;
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
loc_82277288:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277290:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227729C"))) PPC_WEAK_FUNC(sub_8227729C);
PPC_FUNC_IMPL(__imp__sub_8227729C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822772A0"))) PPC_WEAK_FUNC(sub_822772A0);
PPC_FUNC_IMPL(__imp__sub_822772A0) {
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
	ctx.lr = 0x822772A8;
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
	ctx.lr = 0x822772D8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822772E4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822772F4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277324
	if (cr6.eq) goto loc_82277324;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277324
	if (!cr6.eq) goto loc_82277324;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8229b0f8
	ctx.lr = 0x82277314;
	sub_8229B0F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277328
	if (!cr6.eq) goto loc_82277328;
loc_82277324:
	// li r31,0
	r31.s64 = 0;
loc_82277328:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277354
	if (cr6.eq) goto loc_82277354;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227734c
	if (cr6.eq) goto loc_8227734C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277344;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277350
	goto loc_82277350;
loc_8227734C:
	// li r11,0
	r11.s64 = 0;
loc_82277350:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277354:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277378
	if (cr6.eq) goto loc_82277378;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277368;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227737c
	if (cr6.eq) goto loc_8227737C;
loc_82277378:
	// li r11,0
	r11.s64 = 0;
loc_8227737C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82277388"))) PPC_WEAK_FUNC(sub_82277388);
PPC_FUNC_IMPL(__imp__sub_82277388) {
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
	ctx.lr = 0x82277390;
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
	ctx.lr = 0x822773B4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822773C0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822773D0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822773f4
	if (cr6.eq) goto loc_822773F4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276b38
	ctx.lr = 0x822773E4;
	sub_82276B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822773f8
	if (!cr6.eq) goto loc_822773F8;
loc_822773F4:
	// li r30,0
	r30.s64 = 0;
loc_822773F8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277430
	if (cr6.eq) goto loc_82277430;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277428
	if (cr6.eq) goto loc_82277428;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277414;
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
loc_82277428:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277430:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227743C"))) PPC_WEAK_FUNC(sub_8227743C);
PPC_FUNC_IMPL(__imp__sub_8227743C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277440"))) PPC_WEAK_FUNC(sub_82277440);
PPC_FUNC_IMPL(__imp__sub_82277440) {
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
	ctx.lr = 0x82277448;
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
	ctx.lr = 0x82277478;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277484;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277494;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822774c4
	if (cr6.eq) goto loc_822774C4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822774c4
	if (!cr6.eq) goto loc_822774C4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276ba8
	ctx.lr = 0x822774B4;
	sub_82276BA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822774c8
	if (!cr6.eq) goto loc_822774C8;
loc_822774C4:
	// li r31,0
	r31.s64 = 0;
loc_822774C8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822774f4
	if (cr6.eq) goto loc_822774F4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822774ec
	if (cr6.eq) goto loc_822774EC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822774E4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822774f0
	goto loc_822774F0;
loc_822774EC:
	// li r11,0
	r11.s64 = 0;
loc_822774F0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822774F4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277518
	if (cr6.eq) goto loc_82277518;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277508;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227751c
	if (cr6.eq) goto loc_8227751C;
loc_82277518:
	// li r11,0
	r11.s64 = 0;
loc_8227751C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82277528"))) PPC_WEAK_FUNC(sub_82277528);
PPC_FUNC_IMPL(__imp__sub_82277528) {
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
	ctx.lr = 0x82277530;
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
	ctx.lr = 0x82277554;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277560;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277570;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277594
	if (cr6.eq) goto loc_82277594;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276c18
	ctx.lr = 0x82277584;
	sub_82276C18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277598
	if (!cr6.eq) goto loc_82277598;
loc_82277594:
	// li r30,0
	r30.s64 = 0;
loc_82277598:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822775d0
	if (cr6.eq) goto loc_822775D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822775c8
	if (cr6.eq) goto loc_822775C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822775B4;
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
loc_822775C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822775D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822775DC"))) PPC_WEAK_FUNC(sub_822775DC);
PPC_FUNC_IMPL(__imp__sub_822775DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822775E0"))) PPC_WEAK_FUNC(sub_822775E0);
PPC_FUNC_IMPL(__imp__sub_822775E0) {
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
	ctx.lr = 0x822775E8;
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
	ctx.lr = 0x82277618;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277624;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277634;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277664
	if (cr6.eq) goto loc_82277664;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277664
	if (!cr6.eq) goto loc_82277664;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276c90
	ctx.lr = 0x82277654;
	sub_82276C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277668
	if (!cr6.eq) goto loc_82277668;
loc_82277664:
	// li r31,0
	r31.s64 = 0;
loc_82277668:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277694
	if (cr6.eq) goto loc_82277694;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227768c
	if (cr6.eq) goto loc_8227768C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277684;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277690
	goto loc_82277690;
loc_8227768C:
	// li r11,0
	r11.s64 = 0;
loc_82277690:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277694:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822776b8
	if (cr6.eq) goto loc_822776B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822776A8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822776bc
	if (cr6.eq) goto loc_822776BC;
loc_822776B8:
	// li r11,0
	r11.s64 = 0;
loc_822776BC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822776C8"))) PPC_WEAK_FUNC(sub_822776C8);
PPC_FUNC_IMPL(__imp__sub_822776C8) {
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
	ctx.lr = 0x822776D0;
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
	ctx.lr = 0x822776F4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277700;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277710;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277734
	if (cr6.eq) goto loc_82277734;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276d08
	ctx.lr = 0x82277724;
	sub_82276D08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277738
	if (!cr6.eq) goto loc_82277738;
loc_82277734:
	// li r30,0
	r30.s64 = 0;
loc_82277738:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277770
	if (cr6.eq) goto loc_82277770;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277768
	if (cr6.eq) goto loc_82277768;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277754;
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
loc_82277768:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277770:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227777C"))) PPC_WEAK_FUNC(sub_8227777C);
PPC_FUNC_IMPL(__imp__sub_8227777C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277780"))) PPC_WEAK_FUNC(sub_82277780);
PPC_FUNC_IMPL(__imp__sub_82277780) {
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
	ctx.lr = 0x82277788;
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
	ctx.lr = 0x822777AC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822777B8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822777C8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822777f0
	if (cr6.eq) goto loc_822777F0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f90
	ctx.lr = 0x822777E0;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822777f4
	if (!cr6.eq) goto loc_822777F4;
loc_822777F0:
	// li r30,0
	r30.s64 = 0;
loc_822777F4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8227782c
	if (cr6.eq) goto loc_8227782C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277824
	if (cr6.eq) goto loc_82277824;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277810;
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
loc_82277824:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8227782C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82277838"))) PPC_WEAK_FUNC(sub_82277838);
PPC_FUNC_IMPL(__imp__sub_82277838) {
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
	ctx.lr = 0x82277840;
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
	ctx.lr = 0x82277870;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227787C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8227788C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822778c0
	if (cr6.eq) goto loc_822778C0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822778c0
	if (!cr6.eq) goto loc_822778C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618f80
	ctx.lr = 0x822778B0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822778c4
	if (!cr6.eq) goto loc_822778C4;
loc_822778C0:
	// li r31,0
	r31.s64 = 0;
loc_822778C4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822778f0
	if (cr6.eq) goto loc_822778F0;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822778e8
	if (cr6.eq) goto loc_822778E8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822778E0;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822778ec
	goto loc_822778EC;
loc_822778E8:
	// li r11,0
	r11.s64 = 0;
loc_822778EC:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822778F0:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277914
	if (cr6.eq) goto loc_82277914;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277904;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277918
	if (cr6.eq) goto loc_82277918;
loc_82277914:
	// li r11,0
	r11.s64 = 0;
loc_82277918:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82277924"))) PPC_WEAK_FUNC(sub_82277924);
PPC_FUNC_IMPL(__imp__sub_82277924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277928"))) PPC_WEAK_FUNC(sub_82277928);
PPC_FUNC_IMPL(__imp__sub_82277928) {
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
	ctx.lr = 0x82277930;
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
	ctx.lr = 0x82277954;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277960;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277970;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277994
	if (cr6.eq) goto loc_82277994;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276d78
	ctx.lr = 0x82277984;
	sub_82276D78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277998
	if (!cr6.eq) goto loc_82277998;
loc_82277994:
	// li r30,0
	r30.s64 = 0;
loc_82277998:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822779d0
	if (cr6.eq) goto loc_822779D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822779c8
	if (cr6.eq) goto loc_822779C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822779B4;
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
loc_822779C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822779D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822779DC"))) PPC_WEAK_FUNC(sub_822779DC);
PPC_FUNC_IMPL(__imp__sub_822779DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822779E0"))) PPC_WEAK_FUNC(sub_822779E0);
PPC_FUNC_IMPL(__imp__sub_822779E0) {
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
	ctx.lr = 0x822779E8;
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
	ctx.lr = 0x82277A18;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277A24;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277A34;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277a64
	if (cr6.eq) goto loc_82277A64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277a64
	if (!cr6.eq) goto loc_82277A64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276de8
	ctx.lr = 0x82277A54;
	sub_82276DE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277a68
	if (!cr6.eq) goto loc_82277A68;
loc_82277A64:
	// li r31,0
	r31.s64 = 0;
loc_82277A68:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277a94
	if (cr6.eq) goto loc_82277A94;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277a8c
	if (cr6.eq) goto loc_82277A8C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277A84;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277a90
	goto loc_82277A90;
loc_82277A8C:
	// li r11,0
	r11.s64 = 0;
loc_82277A90:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277A94:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277ab8
	if (cr6.eq) goto loc_82277AB8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277AA8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277abc
	if (cr6.eq) goto loc_82277ABC;
loc_82277AB8:
	// li r11,0
	r11.s64 = 0;
loc_82277ABC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82277AC8"))) PPC_WEAK_FUNC(sub_82277AC8);
PPC_FUNC_IMPL(__imp__sub_82277AC8) {
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
	ctx.lr = 0x82277AD0;
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
	ctx.lr = 0x82277AF4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277B00;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277B10;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277b34
	if (cr6.eq) goto loc_82277B34;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276e58
	ctx.lr = 0x82277B24;
	sub_82276E58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277b38
	if (!cr6.eq) goto loc_82277B38;
loc_82277B34:
	// li r30,0
	r30.s64 = 0;
loc_82277B38:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277b70
	if (cr6.eq) goto loc_82277B70;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277b68
	if (cr6.eq) goto loc_82277B68;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277B54;
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
loc_82277B68:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277B70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82277B7C"))) PPC_WEAK_FUNC(sub_82277B7C);
PPC_FUNC_IMPL(__imp__sub_82277B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277B80"))) PPC_WEAK_FUNC(sub_82277B80);
PPC_FUNC_IMPL(__imp__sub_82277B80) {
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
	ctx.lr = 0x82277B88;
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
	ctx.lr = 0x82277BAC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82277BB8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82277BC8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82277bec
	if (cr6.eq) goto loc_82277BEC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82276ef0
	ctx.lr = 0x82277BDC;
	sub_82276EF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277bf0
	if (!cr6.eq) goto loc_82277BF0;
loc_82277BEC:
	// li r30,0
	r30.s64 = 0;
loc_82277BF0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82277c28
	if (cr6.eq) goto loc_82277C28;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277c20
	if (cr6.eq) goto loc_82277C20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82277C0C;
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
loc_82277C20:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82277C28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82277C34"))) PPC_WEAK_FUNC(sub_82277C34);
PPC_FUNC_IMPL(__imp__sub_82277C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82277C38"))) PPC_WEAK_FUNC(sub_82277C38);
PPC_FUNC_IMPL(__imp__sub_82277C38) {
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
	ctx.lr = 0x82277C40;
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
	ctx.lr = 0x82277C70;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82277C7C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82277C8C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82277cbc
	if (cr6.eq) goto loc_82277CBC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82277cbc
	if (!cr6.eq) goto loc_82277CBC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82276fc0
	ctx.lr = 0x82277CAC;
	sub_82276FC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277cc0
	if (!cr6.eq) goto loc_82277CC0;
loc_82277CBC:
	// li r31,0
	r31.s64 = 0;
loc_82277CC0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82277cec
	if (cr6.eq) goto loc_82277CEC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277ce4
	if (cr6.eq) goto loc_82277CE4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277CDC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82277ce8
	goto loc_82277CE8;
loc_82277CE4:
	// li r11,0
	r11.s64 = 0;
loc_82277CE8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82277CEC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277d10
	if (cr6.eq) goto loc_82277D10;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82277D00;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82277d14
	if (cr6.eq) goto loc_82277D14;
loc_82277D10:
	// li r11,0
	r11.s64 = 0;
loc_82277D14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82277D20"))) PPC_WEAK_FUNC(sub_82277D20);
PPC_FUNC_IMPL(__imp__sub_82277D20) {
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
	ctx.lr = 0x82277D28;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8368(r1)
	ea = -8368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82299578
	ctx.lr = 0x82277D3C;
	sub_82299578(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// bl 0x821c9788
	ctx.lr = 0x82277D44;
	sub_821C9788(ctx, base);
	// addis r31,r29,2
	r31.s64 = r29.s64 + 131072;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// addi r31,r31,292
	r31.s64 = r31.s64 + 292;
	// li r23,-1
	r23.s64 = -1;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_82277D68:
	// lbz r11,-204(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -204);
	// addi r30,r31,-8
	r30.s64 = r31.s64 + -8;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x82277d98
	if (!cr6.eq) goto loc_82277D98;
	// lwz r11,-200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82277d98
	if (cr6.lt) goto loc_82277D98;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r24,1
	r24.s64 = 1;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bge cr6,0x82277d98
	if (!cr6.lt) goto loc_82277D98;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_82277D98:
	// lbz r11,-184(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -184);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x82277eb4
	if (!cr6.eq) goto loc_82277EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277eb4
	if (cr6.eq) goto loc_82277EB4;
	// lwz r10,16540(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16540);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82277e1c
	if (!cr6.eq) goto loc_82277E1C;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x8229bbc8
	ctx.lr = 0x82277DC8;
	sub_8229BBC8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277DD8;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277e1c
	if (cr6.eq) goto loc_82277E1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500830
	ctx.lr = 0x82277DF4;
	sub_82500830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// beq cr6,0x82277e14
	if (cr6.eq) goto loc_82277E14;
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// b 0x82277e1c
	goto loc_82277E1C;
loc_82277E14:
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x82277E1C;
	sub_8229B450(ctx, base);
loc_82277E1C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// lwz r11,8264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8264);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82277e44
	if (cr6.eq) goto loc_82277E44;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82277e44
	if (cr6.eq) goto loc_82277E44;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82277e48
	if (!cr6.eq) goto loc_82277E48;
loc_82277E44:
	// li r11,1
	r11.s64 = 1;
loc_82277E48:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277e94
	if (cr6.eq) goto loc_82277E94;
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x8229bbc8
	ctx.lr = 0x82277E5C;
	sub_8229BBC8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277E6C;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277eb4
	if (cr6.eq) goto loc_82277EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8196
	ctx.r3.s64 = r11.s64 + 8196;
	// bl 0x82500830
	ctx.lr = 0x82277E84;
	sub_82500830(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x8229b450
	ctx.lr = 0x82277E90;
	sub_8229B450(ctx, base);
	// b 0x82277eb4
	goto loc_82277EB4;
loc_82277E94:
	// lwz r5,22296(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22296);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x82277eb4
	if (cr6.lt) goto loc_82277EB4;
	// addi r4,r30,-204
	ctx.r4.s64 = r30.s64 + -204;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822761d0
	ctx.lr = 0x82277EAC;
	sub_822761D0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r23,22296(r11)
	PPC_STORE_U32(r11.u32 + 22296, r23.u32);
loc_82277EB4:
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82277EBC;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// addi r11,r11,8280
	r11.s64 = r11.s64 + 8280;
	// addi r3,r11,8192
	ctx.r3.s64 = r11.s64 + 8192;
	// bl 0x82500848
	ctx.lr = 0x82277EE0;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,22300(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82277f7c
	if (!cr6.eq) goto loc_82277F7C;
	// bl 0x822912c8
	ctx.lr = 0x82277F20;
	sub_822912C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82277f50
	if (cr6.eq) goto loc_82277F50;
	// lwz r3,-8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// bl 0x82291a20
	ctx.lr = 0x82277F34;
	sub_82291A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82277f50
	if (!cr6.eq) goto loc_82277F50;
	// bl 0x822914e8
	ctx.lr = 0x82277F44;
	sub_822914E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278100
	if (cr6.eq) goto loc_82278100;
loc_82277F50:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82276528
	ctx.lr = 0x82277F5C;
	sub_82276528(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x82277F78;
	sub_8229B450(ctx, base);
	// b 0x82278100
	goto loc_82278100;
loc_82277F7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f550
	ctx.lr = 0x82277F84;
	sub_8238F550(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82277F90;
	sub_822A3998(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b4f0
	ctx.lr = 0x82277FA4;
	sub_8229B4F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82277FAC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82277FBC;
	sub_82270170(ctx, base);
	// bl 0x82272e98
	ctx.lr = 0x82277FC0;
	sub_82272E98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8227802c
	if (!cr6.eq) goto loc_8227802C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82277FD4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82277FE4;
	sub_82270170(ctx, base);
	// bl 0x82272ec0
	ctx.lr = 0x82277FE8;
	sub_82272EC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278024
	if (cr6.eq) goto loc_82278024;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r20,1220(r30)
	r20.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// bl 0x82388580
	ctx.lr = 0x82278000;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82278010;
	sub_82270170(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x82272ee8
	ctx.lr = 0x82278018;
	sub_82272EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8227802c
	if (!cr6.eq) goto loc_8227802C;
loc_82278024:
	// li r11,0
	r11.s64 = 0;
	// b 0x82278030
	goto loc_82278030;
loc_8227802C:
	// li r11,1
	r11.s64 = 1;
loc_82278030:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822780c4
	if (!cr6.eq) goto loc_822780C4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82393148
	ctx.lr = 0x82278044;
	sub_82393148(ctx, base);
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278054;
	sub_823924B0(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278064;
	sub_823924B0(ctx, base);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278074;
	sub_823924B0(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278084;
	sub_823924B0(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x82278094;
	sub_823924B0(ctx, base);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780A4;
	sub_823924B0(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780B4;
	sub_823924B0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823924b0
	ctx.lr = 0x822780C4;
	sub_823924B0(ctx, base);
loc_822780C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8e10
	ctx.lr = 0x822780D0;
	sub_822A8E10(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822aae48
	ctx.lr = 0x822780DC;
	sub_822AAE48(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8280
	ctx.r3.s64 = r11.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x822780F8;
	sub_8229B450(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x82278100;
	sub_8238ED78(ctx, base);
loc_82278100:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x82277d68
	if (cr6.lt) goto loc_82277D68;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278198
	if (cr6.eq) goto loc_82278198;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82278124;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278198
	if (cr6.eq) goto loc_82278198;
	// lwz r11,-3624(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// subf r10,r25,r21
	ctx.r10.s64 = r21.s64 - r25.s64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x82278198
	if (!cr6.gt) goto loc_82278198;
	// addis r11,r29,2
	r11.s64 = r29.s64 + 131072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278154:
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x8227816c
	if (!cr6.eq) goto loc_8227816C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x82278184
	if (!cr6.lt) goto loc_82278184;
loc_8227816C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278154
	if (cr6.lt) goto loc_82278154;
	// addi r1,r1,8368
	ctx.r1.s64 = ctx.r1.s64 + 8368;
	// b 0x823d9228
	return;
loc_82278184:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// bl 0x8229a828
	ctx.lr = 0x82278198;
	sub_8229A828(ctx, base);
loc_82278198:
	// addi r1,r1,8368
	ctx.r1.s64 = ctx.r1.s64 + 8368;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822781A0"))) PPC_WEAK_FUNC(sub_822781A0);
PPC_FUNC_IMPL(__imp__sub_822781A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822781B0:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x822781b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822781B0;
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// lwz r6,28(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r6,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// lhz r5,32(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// sth r5,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, ctx.r5.u16);
	// lhz r11,34(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 34);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// lhz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 36);
	// sth r10,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r10.u16);
	// lhz r9,38(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 38);
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// lhz r8,40(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 40);
	// sth r8,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, ctx.r8.u16);
	// lhz r7,42(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 42);
	// sth r7,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, ctx.r7.u16);
	// lbz r6,44(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 44);
	// stb r6,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r6.u8);
	// lbz r5,48(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// lbz r11,48(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r5,r11,0,24,24
	ctx.r5.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x80) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFF7F);
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stb r10,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r10.u8);
	// lbz r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r9,r8,0,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stb r7,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r7.u8);
	// lbz r5,48(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 48);
	// rlwimi r6,r5,0,26,26
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x20) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r6,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82278260"))) PPC_WEAK_FUNC(sub_82278260);
PPC_FUNC_IMPL(__imp__sub_82278260) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278288:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822782a8
	if (cr6.eq) goto loc_822782A8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278288
	if (cr6.lt) goto loc_82278288;
	// blr 
	return;
loc_822782A8:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,212(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addis r11,r8,2
	r11.s64 = ctx.r8.s64 + 131072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,292
	r11.s64 = r11.s64 + 292;
	// li r9,31
	ctx.r9.s64 = 31;
loc_822782E8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278304
	if (cr6.eq) goto loc_82278304;
	// lwz r10,16540(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16540);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82278304
	if (!cr6.eq) goto loc_82278304;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_82278304:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// bne 0x822782e8
	if (!cr0.eq) goto loc_822782E8;
	// lwz r6,4(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// addi r3,r3,8280
	ctx.r3.s64 = ctx.r3.s64 + 8280;
	// bge cr6,0x8227832c
	if (!cr6.lt) goto loc_8227832C;
	// lwz r7,8(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r5,68(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229b9b0
	sub_8229B9B0(ctx, base);
	return;
loc_8227832C:
	// lwz r5,68(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229ba60
	sub_8229BA60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82278334"))) PPC_WEAK_FUNC(sub_82278334);
PPC_FUNC_IMPL(__imp__sub_82278334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278338"))) PPC_WEAK_FUNC(sub_82278338);
PPC_FUNC_IMPL(__imp__sub_82278338) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278360:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// beq cr6,0x82278380
	if (cr6.eq) goto loc_82278380;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82278360
	if (cr6.lt) goto loc_82278360;
	// blr 
	return;
loc_82278380:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,212(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r4,68(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// b 0x8229b5c8
	sub_8229B5C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822783B4"))) PPC_WEAK_FUNC(sub_822783B4);
PPC_FUNC_IMPL(__imp__sub_822783B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822783B8"))) PPC_WEAK_FUNC(sub_822783B8);
PPC_FUNC_IMPL(__imp__sub_822783B8) {
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
	ctx.lr = 0x822783C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + r31.u64;
	// addis r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 131072;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
loc_822783F4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82278418
	if (cr6.eq) goto loc_82278418;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,220
	ctx.r10.s64 = ctx.r10.s64 + 220;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x822783f4
	if (cr6.lt) goto loc_822783F4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82278418:
	// mulli r11,r11,220
	r11.s64 = r11.s64 * 220;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r6,r11,2
	ctx.r6.s64 = r11.s64 + 131072;
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// lwz r7,212(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822768e8
	ctx.lr = 0x82278444;
	sub_822768E8(ctx, base);
	// lbz r11,22300(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 22300);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278470
	if (cr6.eq) goto loc_82278470;
	// lhz r9,22292(r7)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + 22292);
	// lhz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 52);
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822784d4
	if (cr6.lt) goto loc_822784D4;
loc_82278470:
	// lwz r11,212(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lbz r10,22300(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22300);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,22300(r11)
	PPC_STORE_U8(r11.u32 + 22300, ctx.r9.u8);
	// lwz r7,212(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	// lhz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 52);
	// sth r6,22292(r7)
	PPC_STORE_U16(ctx.r7.u32 + 22292, ctx.r6.u16);
	// blt cr6,0x822784d4
	if (cr6.lt) goto loc_822784D4;
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822784b4
	if (cr6.eq) goto loc_822784B4;
	// addi r5,r29,16
	ctx.r5.s64 = r29.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274f80
	ctx.lr = 0x822784B4;
	sub_82274F80(ctx, base);
loc_822784B4:
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822784d4
	if (cr6.eq) goto loc_822784D4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275040
	ctx.lr = 0x822784D4;
	sub_82275040(ctx, base);
loc_822784D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822784DC"))) PPC_WEAK_FUNC(sub_822784DC);
PPC_FUNC_IMPL(__imp__sub_822784DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822784E0"))) PPC_WEAK_FUNC(sub_822784E0);
PPC_FUNC_IMPL(__imp__sub_822784E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,220
	ctx.r10.s64 = 220;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// addis r8,r9,-2
	ctx.r8.s64 = ctx.r9.s64 + -131072;
	// addi r8,r8,-80
	ctx.r8.s64 = ctx.r8.s64 + -80;
	// divw r7,r8,r10
	ctx.r7.s32 = ctx.r8.s32 / ctx.r10.s32;
	// addic. r10,r7,1
	xer.ca = ctx.r7.u32 > 4294967294;
	ctx.r10.s64 = ctx.r7.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bltlr 
	if (cr0.lt) return;
	// mulli r9,r10,220
	ctx.r9.s64 = ctx.r10.s64 * 220;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addis r11,r11,2
	r11.s64 = r11.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82278518:
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x8227853c
	if (!cr6.eq) goto loc_8227853C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8227854c
	if (!cr6.lt) goto loc_8227854C;
loc_8227853C:
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// bge 0x82278518
	if (!cr0.lt) goto loc_82278518;
	// blr 
	return;
loc_8227854C:
	// b 0x8229a828
	sub_8229A828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82278550"))) PPC_WEAK_FUNC(sub_82278550);
PPC_FUNC_IMPL(__imp__sub_82278550) {
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
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// stb r10,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r10.u8);
	// bne cr6,0x822785cc
	if (!cr6.eq) goto loc_822785CC;
	// lwz r31,212(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82278608
	if (cr6.eq) goto loc_82278608;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32217
	ctx.r10.s64 = -2111373312;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,26936
	ctx.r8.s64 = ctx.r10.s64 + 26936;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// stw r9,22240(r31)
	PPC_STORE_U32(r31.u32 + 22240, ctx.r9.u32);
	// stw r8,22244(r31)
	PPC_STORE_U32(r31.u32 + 22244, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x822785B4;
	sub_82130000(ctx, base);
	// stw r3,22240(r31)
	PPC_STORE_U32(r31.u32 + 22240, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822785CC:
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// bne cr6,0x82278608
	if (!cr6.eq) goto loc_82278608;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822785E0;
	sub_822A39C8(ctx, base);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82278608
	if (cr6.eq) goto loc_82278608;
	// bl 0x82387b90
	ctx.lr = 0x822785F0;
	sub_82387B90(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,1344(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822761d0
	ctx.lr = 0x82278608;
	sub_822761D0(ctx, base);
loc_82278608:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227861C"))) PPC_WEAK_FUNC(sub_8227861C);
PPC_FUNC_IMPL(__imp__sub_8227861C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278620"))) PPC_WEAK_FUNC(sub_82278620);
PPC_FUNC_IMPL(__imp__sub_82278620) {
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
	// li r9,22304
	ctx.r9.s64 = 22304;
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
	// beq cr6,0x8227866c
	if (cr6.eq) goto loc_8227866C;
	// mulli r3,r10,22304
	ctx.r3.s64 = ctx.r10.s64 * 22304;
	// bl 0x82130528
	ctx.lr = 0x82278668;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8227866C:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x8227867C;
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

__attribute__((alias("__imp__sub_82278694"))) PPC_WEAK_FUNC(sub_82278694);
PPC_FUNC_IMPL(__imp__sub_82278694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278698"))) PPC_WEAK_FUNC(sub_82278698);
PPC_FUNC_IMPL(__imp__sub_82278698) {
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
	ctx.lr = 0x822786A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8229af08
	ctx.lr = 0x822786B0;
	sub_8229AF08(ctx, base);
	// addi r29,r31,60
	r29.s64 = r31.s64 + 60;
	// addi r30,r29,52
	r30.s64 = r29.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618750
	ctx.lr = 0x822786C0;
	sub_82618750(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// sth r11,144(r31)
	PPC_STORE_U16(r31.u32 + 144, r11.u16);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// stb r11,146(r31)
	PPC_STORE_U8(r31.u32 + 146, r11.u8);
	// bl 0x82618750
	ctx.lr = 0x822786DC;
	sub_82618750(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618610
	ctx.lr = 0x822786F0;
	sub_82618610(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822786FC"))) PPC_WEAK_FUNC(sub_822786FC);
PPC_FUNC_IMPL(__imp__sub_822786FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278700"))) PPC_WEAK_FUNC(sub_82278700);
PPC_FUNC_IMPL(__imp__sub_82278700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// lhz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// rlwinm r9,r11,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r8,r10,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfc r8,r10,r9
	xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// beq cr6,0x82278740
	if (cr6.eq) goto loc_82278740;
	// subfc r8,r9,r10
	xer.ca = ctx.r10.u32 >= ctx.r9.u32;
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
loc_82278740:
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r7,31
	ctx.r3.u64 = ctx.r7.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227874C"))) PPC_WEAK_FUNC(sub_8227874C);
PPC_FUNC_IMPL(__imp__sub_8227874C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278750"))) PPC_WEAK_FUNC(sub_82278750);
PPC_FUNC_IMPL(__imp__sub_82278750) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r9,5620(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82278764
	if (!cr6.eq) goto loc_82278764;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82278764:
	// lwz r11,5616(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5616);
	// lis r8,20971
	ctx.r8.s64 = 1374355456;
	// addi r10,r3,2812
	ctx.r10.s64 = ctx.r3.s64 + 2812;
	// lhz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// ori r5,r8,34079
	ctx.r5.u64 = ctx.r8.u64 | 34079;
	// rlwinm r4,r7,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// mulhw r3,r6,r5
	ctx.r3.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// clrlwi r8,r7,16
	ctx.r8.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r8,0,25,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mulli r9,r11,50
	ctx.r9.s64 = r11.s64 * 50;
	// subf r7,r9,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r9.s64;
	// mulli r11,r7,56
	r11.s64 = ctx.r7.s64 * 56;
	// lhzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// rlwinm r5,r6,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// xor r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r4.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// subfc r9,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// beq cr6,0x822787d4
	if (cr6.eq) goto loc_822787D4;
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
loc_822787D4:
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822787EC"))) PPC_WEAK_FUNC(sub_822787EC);
PPC_FUNC_IMPL(__imp__sub_822787EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822787F0"))) PPC_WEAK_FUNC(sub_822787F0);
PPC_FUNC_IMPL(__imp__sub_822787F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,5620(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// li r8,50
	ctx.r8.s64 = 50;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r9,r3,2812
	ctx.r9.s64 = ctx.r3.s64 + 2812;
	// li r7,0
	ctx.r7.s64 = 0;
loc_82278808:
	// lwz r11,2804(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227881c
	if (!cr6.eq) goto loc_8227881C;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8227881C:
	// mulli r10,r11,56
	ctx.r10.s64 = r11.s64 * 56;
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// lhzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r5,r10,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r6,r11,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// xor r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// subfc r6,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r6.s64 = ctx.r10.s64 - r11.s64;
	// beq cr6,0x82278860
	if (cr6.eq) goto loc_82278860;
	// subfc r6,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r6.s64 = r11.s64 - ctx.r10.s64;
loc_82278860:
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r5,31
	r11.u64 = ctx.r5.u32 & 0x1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r11,2808(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2808);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,2804(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,2808(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2808, ctx.r10.u32);
	// stw r11,2804(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2804, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x822788a0
	if (!cr6.eq) goto loc_822788A0;
	// stw r7,2804(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2804, ctx.r7.u32);
loc_822788A0:
	// lwz r11,5620(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5620);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82278808
	if (!cr6.eq) goto loc_82278808;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822788B4"))) PPC_WEAK_FUNC(sub_822788B4);
PPC_FUNC_IMPL(__imp__sub_822788B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822788B8"))) PPC_WEAK_FUNC(sub_822788B8);
PPC_FUNC_IMPL(__imp__sub_822788B8) {
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
	ctx.lr = 0x822788C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,50
	r30.s64 = 50;
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82278940
	if (cr6.eq) goto loc_82278940;
	// li r28,0
	r28.s64 = 0;
loc_822788E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275558
	ctx.lr = 0x822788E8;
	sub_82275558(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82278700
	ctx.lr = 0x822788F8;
	sub_82278700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278940
	if (cr6.eq) goto loc_82278940;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82278940
	if (cr6.lt) goto loc_82278940;
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,2804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r10.u32);
	// stw r11,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x82278930
	if (!cr6.eq) goto loc_82278930;
	// stw r28,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r28.u32);
loc_82278930:
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822788e0
	if (!cr6.eq) goto loc_822788E0;
loc_82278940:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82278948"))) PPC_WEAK_FUNC(sub_82278948);
PPC_FUNC_IMPL(__imp__sub_82278948) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822789b0
	if (cr6.eq) goto loc_822789B0;
loc_8227896C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822789a4
	if (cr6.eq) goto loc_822789A4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822789a4
	if (!cr6.eq) goto loc_822789A4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7c48
	ctx.lr = 0x82278998;
	sub_824E7C48(ctx, base);
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r10.u8);
loc_822789A4:
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8227896c
	if (!cr6.eq) goto loc_8227896C;
loc_822789B0:
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

__attribute__((alias("__imp__sub_822789C8"))) PPC_WEAK_FUNC(sub_822789C8);
PPC_FUNC_IMPL(__imp__sub_822789C8) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x8229afa8
	ctx.lr = 0x822789F0;
	sub_8229AFA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278a1c
	if (cr6.eq) goto loc_82278A1C;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82277088
	ctx.lr = 0x82278A0C;
	sub_82277088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278a20
	if (!cr6.eq) goto loc_82278A20;
loc_82278A1C:
	// li r11,0
	r11.s64 = 0;
loc_82278A20:
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

__attribute__((alias("__imp__sub_82278A3C"))) PPC_WEAK_FUNC(sub_82278A3C);
PPC_FUNC_IMPL(__imp__sub_82278A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278A40"))) PPC_WEAK_FUNC(sub_82278A40);
PPC_FUNC_IMPL(__imp__sub_82278A40) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x8229b0f8
	ctx.lr = 0x82278A68;
	sub_8229B0F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278a94
	if (cr6.eq) goto loc_82278A94;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822756d0
	ctx.lr = 0x82278A84;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278a98
	if (!cr6.eq) goto loc_82278A98;
loc_82278A94:
	// li r11,0
	r11.s64 = 0;
loc_82278A98:
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

__attribute__((alias("__imp__sub_82278AB4"))) PPC_WEAK_FUNC(sub_82278AB4);
PPC_FUNC_IMPL(__imp__sub_82278AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278AB8"))) PPC_WEAK_FUNC(sub_82278AB8);
PPC_FUNC_IMPL(__imp__sub_82278AB8) {
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
	ctx.lr = 0x82278AC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r31,52
	r29.s64 = r31.s64 + 52;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618830
	ctx.lr = 0x82278AE0;
	sub_82618830(ctx, base);
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618c80
	ctx.lr = 0x82278AF0;
	sub_82618C80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278b14
	if (cr6.eq) goto loc_82278B14;
	// lhz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82278b14
	if (cr6.eq) goto loc_82278B14;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82278B14;
	sub_82618F90(ctx, base);
loc_82278B14:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278b5c
	if (cr6.eq) goto loc_82278B5C;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82277088
	ctx.lr = 0x82278B30;
	sub_82277088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278b5c
	if (cr6.eq) goto loc_82278B5C;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r28,2
	ctx.r4.s64 = r28.s64 + 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82277088
	ctx.lr = 0x82278B4C;
	sub_82277088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278b60
	if (!cr6.eq) goto loc_82278B60;
loc_82278B5C:
	// li r11,0
	r11.s64 = 0;
loc_82278B60:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82278B6C"))) PPC_WEAK_FUNC(sub_82278B6C);
PPC_FUNC_IMPL(__imp__sub_82278B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278B70"))) PPC_WEAK_FUNC(sub_82278B70);
PPC_FUNC_IMPL(__imp__sub_82278B70) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82275578
	ctx.lr = 0x82278B98;
	sub_82275578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278be0
	if (cr6.eq) goto loc_82278BE0;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822756d0
	ctx.lr = 0x82278BB4;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278be0
	if (cr6.eq) goto loc_82278BE0;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,2
	ctx.r4.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822756d0
	ctx.lr = 0x82278BD0;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278be4
	if (!cr6.eq) goto loc_82278BE4;
loc_82278BE0:
	// li r11,0
	r11.s64 = 0;
loc_82278BE4:
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

__attribute__((alias("__imp__sub_82278C00"))) PPC_WEAK_FUNC(sub_82278C00);
PPC_FUNC_IMPL(__imp__sub_82278C00) {
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
	ctx.lr = 0x82278C08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r30,0(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82278C24;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82278c64
	if (cr6.eq) goto loc_82278C64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r4,r30,16
	ctx.r4.u64 = r30.u32 & 0xFFFF;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82278C4C;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82278C58;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82278C64:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82278C70"))) PPC_WEAK_FUNC(sub_82278C70);
PPC_FUNC_IMPL(__imp__sub_82278C70) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82275750
	ctx.lr = 0x82278C94;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278cdc
	if (cr6.eq) goto loc_82278CDC;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82278CB0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278cdc
	if (cr6.eq) goto loc_82278CDC;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82278CCC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278ce0
	if (!cr6.eq) goto loc_82278CE0;
loc_82278CDC:
	// li r11,0
	r11.s64 = 0;
loc_82278CE0:
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

__attribute__((alias("__imp__sub_82278CFC"))) PPC_WEAK_FUNC(sub_82278CFC);
PPC_FUNC_IMPL(__imp__sub_82278CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278D00"))) PPC_WEAK_FUNC(sub_82278D00);
PPC_FUNC_IMPL(__imp__sub_82278D00) {
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
	ctx.lr = 0x82278D08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r28,4(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x826186c0
	ctx.lr = 0x82278D24;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278d5c
	if (cr6.eq) goto loc_82278D5C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82278D4C;
	sub_82618390(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82278D58;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_82278D5C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278dd8
	if (cr6.eq) goto loc_82278DD8;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82278D78;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278dd8
	if (cr6.eq) goto loc_82278DD8;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82278D94;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278dd8
	if (cr6.eq) goto loc_82278DD8;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r29,12
	ctx.r4.s64 = r29.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82278DB0;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278dd8
	if (cr6.eq) goto loc_82278DD8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// bl 0x82618f70
	ctx.lr = 0x82278DC8;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278ddc
	if (!cr6.eq) goto loc_82278DDC;
loc_82278DD8:
	// li r11,0
	r11.s64 = 0;
loc_82278DDC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82278DE8"))) PPC_WEAK_FUNC(sub_82278DE8);
PPC_FUNC_IMPL(__imp__sub_82278DE8) {
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
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82257568
	ctx.lr = 0x82278E10;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278e8c
	if (cr6.eq) goto loc_82278E8C;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x82278E2C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278e8c
	if (cr6.eq) goto loc_82278E8C;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x82278E48;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278e8c
	if (cr6.eq) goto loc_82278E8C;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x82278E64;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278e8c
	if (cr6.eq) goto loc_82278E8C;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82278E7C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278e90
	if (!cr6.eq) goto loc_82278E90;
loc_82278E8C:
	// li r11,0
	r11.s64 = 0;
loc_82278E90:
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

__attribute__((alias("__imp__sub_82278EAC"))) PPC_WEAK_FUNC(sub_82278EAC);
PPC_FUNC_IMPL(__imp__sub_82278EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278EB0"))) PPC_WEAK_FUNC(sub_82278EB0);
PPC_FUNC_IMPL(__imp__sub_82278EB0) {
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
	// bl 0x824fa278
	ctx.lr = 0x82278ED0;
	sub_824FA278(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278f14
	if (cr6.eq) goto loc_82278F14;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa278
	ctx.lr = 0x82278EE8;
	sub_824FA278(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278f14
	if (cr6.eq) goto loc_82278F14;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822510e8
	ctx.lr = 0x82278F04;
	sub_822510E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278f18
	if (!cr6.eq) goto loc_82278F18;
loc_82278F14:
	// li r11,0
	r11.s64 = 0;
loc_82278F18:
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

__attribute__((alias("__imp__sub_82278F34"))) PPC_WEAK_FUNC(sub_82278F34);
PPC_FUNC_IMPL(__imp__sub_82278F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278F38"))) PPC_WEAK_FUNC(sub_82278F38);
PPC_FUNC_IMPL(__imp__sub_82278F38) {
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
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82257568
	ctx.lr = 0x82278F5C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82278f84
	if (cr6.eq) goto loc_82278F84;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f10
	ctx.lr = 0x82278F74;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82278f88
	if (!cr6.eq) goto loc_82278F88;
loc_82278F84:
	// li r11,0
	r11.s64 = 0;
loc_82278F88:
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

__attribute__((alias("__imp__sub_82278FA4"))) PPC_WEAK_FUNC(sub_82278FA4);
PPC_FUNC_IMPL(__imp__sub_82278FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82278FA8"))) PPC_WEAK_FUNC(sub_82278FA8);
PPC_FUNC_IMPL(__imp__sub_82278FA8) {
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
	ctx.lr = 0x82278FB0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16760
	ctx.r10.s64 = r11.s64 + 16760;
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
	// bl 0x82275ca8
	ctx.lr = 0x82278FE4;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227901c
	if (cr6.eq) goto loc_8227901C;
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
	ctx.lr = 0x8227900C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82279020
	if (!cr6.eq) goto loc_82279020;
loc_8227901C:
	// li r11,0
	r11.s64 = 0;
loc_82279020:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227902C"))) PPC_WEAK_FUNC(sub_8227902C);
PPC_FUNC_IMPL(__imp__sub_8227902C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279030"))) PPC_WEAK_FUNC(sub_82279030);
PPC_FUNC_IMPL(__imp__sub_82279030) {
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
	ctx.lr = 0x82279038;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16632
	ctx.r10.s64 = r11.s64 + 16632;
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
	// bl 0x82275ca8
	ctx.lr = 0x8227906C;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822790a4
	if (cr6.eq) goto loc_822790A4;
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
	ctx.lr = 0x82279094;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822790a8
	if (!cr6.eq) goto loc_822790A8;
loc_822790A4:
	// li r11,0
	r11.s64 = 0;
loc_822790A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822790B4"))) PPC_WEAK_FUNC(sub_822790B4);
PPC_FUNC_IMPL(__imp__sub_822790B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822790B8"))) PPC_WEAK_FUNC(sub_822790B8);
PPC_FUNC_IMPL(__imp__sub_822790B8) {
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
	ctx.lr = 0x822790C0;
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
	ctx.lr = 0x822790E4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822790F0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82279100;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82279124
	if (cr6.eq) goto loc_82279124;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822789c8
	ctx.lr = 0x82279114;
	sub_822789C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279128
	if (!cr6.eq) goto loc_82279128;
loc_82279124:
	// li r30,0
	r30.s64 = 0;
loc_82279128:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82279160
	if (cr6.eq) goto loc_82279160;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279158
	if (cr6.eq) goto loc_82279158;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82279144;
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
loc_82279158:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82279160:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227916C"))) PPC_WEAK_FUNC(sub_8227916C);
PPC_FUNC_IMPL(__imp__sub_8227916C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279170"))) PPC_WEAK_FUNC(sub_82279170);
PPC_FUNC_IMPL(__imp__sub_82279170) {
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
	ctx.lr = 0x82279178;
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
	ctx.lr = 0x822791A8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822791B4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822791C4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822791f4
	if (cr6.eq) goto loc_822791F4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822791f4
	if (!cr6.eq) goto loc_822791F4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278a40
	ctx.lr = 0x822791E4;
	sub_82278A40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822791f8
	if (!cr6.eq) goto loc_822791F8;
loc_822791F4:
	// li r31,0
	r31.s64 = 0;
loc_822791F8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279224
	if (cr6.eq) goto loc_82279224;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227921c
	if (cr6.eq) goto loc_8227921C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279214;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279220
	goto loc_82279220;
loc_8227921C:
	// li r11,0
	r11.s64 = 0;
loc_82279220:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279224:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279248
	if (cr6.eq) goto loc_82279248;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279238;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227924c
	if (cr6.eq) goto loc_8227924C;
loc_82279248:
	// li r11,0
	r11.s64 = 0;
loc_8227924C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279258"))) PPC_WEAK_FUNC(sub_82279258);
PPC_FUNC_IMPL(__imp__sub_82279258) {
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
	ctx.lr = 0x82279260;
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
	ctx.lr = 0x82279284;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82279290;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822792A0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822792c4
	if (cr6.eq) goto loc_822792C4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82278ab8
	ctx.lr = 0x822792B4;
	sub_82278AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822792c8
	if (!cr6.eq) goto loc_822792C8;
loc_822792C4:
	// li r30,0
	r30.s64 = 0;
loc_822792C8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82279300
	if (cr6.eq) goto loc_82279300;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822792f8
	if (cr6.eq) goto loc_822792F8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822792E4;
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
loc_822792F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82279300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227930C"))) PPC_WEAK_FUNC(sub_8227930C);
PPC_FUNC_IMPL(__imp__sub_8227930C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279310"))) PPC_WEAK_FUNC(sub_82279310);
PPC_FUNC_IMPL(__imp__sub_82279310) {
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
	ctx.lr = 0x82279318;
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
	ctx.lr = 0x82279348;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82279354;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279364;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279394
	if (cr6.eq) goto loc_82279394;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279394
	if (!cr6.eq) goto loc_82279394;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278b70
	ctx.lr = 0x82279384;
	sub_82278B70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279398
	if (!cr6.eq) goto loc_82279398;
loc_82279394:
	// li r31,0
	r31.s64 = 0;
loc_82279398:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822793c4
	if (cr6.eq) goto loc_822793C4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822793bc
	if (cr6.eq) goto loc_822793BC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822793B4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822793c0
	goto loc_822793C0;
loc_822793BC:
	// li r11,0
	r11.s64 = 0;
loc_822793C0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822793C4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822793e8
	if (cr6.eq) goto loc_822793E8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822793D8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822793ec
	if (cr6.eq) goto loc_822793EC;
loc_822793E8:
	// li r11,0
	r11.s64 = 0;
loc_822793EC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822793F8"))) PPC_WEAK_FUNC(sub_822793F8);
PPC_FUNC_IMPL(__imp__sub_822793F8) {
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
	ctx.lr = 0x82279400;
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
	ctx.lr = 0x82279424;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82279430;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82279440;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82279464
	if (cr6.eq) goto loc_82279464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82278c00
	ctx.lr = 0x82279454;
	sub_82278C00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279468
	if (!cr6.eq) goto loc_82279468;
loc_82279464:
	// li r30,0
	r30.s64 = 0;
loc_82279468:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822794a0
	if (cr6.eq) goto loc_822794A0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279498
	if (cr6.eq) goto loc_82279498;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82279484;
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
loc_82279498:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822794A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822794AC"))) PPC_WEAK_FUNC(sub_822794AC);
PPC_FUNC_IMPL(__imp__sub_822794AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822794B0"))) PPC_WEAK_FUNC(sub_822794B0);
PPC_FUNC_IMPL(__imp__sub_822794B0) {
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
	ctx.lr = 0x822794B8;
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
	ctx.lr = 0x822794E8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822794F4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279504;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279538
	if (cr6.eq) goto loc_82279538;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279538
	if (!cr6.eq) goto loc_82279538;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822756d0
	ctx.lr = 0x82279528;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227953c
	if (!cr6.eq) goto loc_8227953C;
loc_82279538:
	// li r31,0
	r31.s64 = 0;
loc_8227953C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279568
	if (cr6.eq) goto loc_82279568;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279560
	if (cr6.eq) goto loc_82279560;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279558;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279564
	goto loc_82279564;
loc_82279560:
	// li r11,0
	r11.s64 = 0;
loc_82279564:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279568:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227958c
	if (cr6.eq) goto loc_8227958C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x8227957C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82279590
	if (cr6.eq) goto loc_82279590;
loc_8227958C:
	// li r11,0
	r11.s64 = 0;
loc_82279590:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8227959C"))) PPC_WEAK_FUNC(sub_8227959C);
PPC_FUNC_IMPL(__imp__sub_8227959C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822795A0"))) PPC_WEAK_FUNC(sub_822795A0);
PPC_FUNC_IMPL(__imp__sub_822795A0) {
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
	ctx.lr = 0x822795A8;
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
	ctx.lr = 0x822795D8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822795E4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822795F4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279624
	if (cr6.eq) goto loc_82279624;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279624
	if (!cr6.eq) goto loc_82279624;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278c70
	ctx.lr = 0x82279614;
	sub_82278C70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279628
	if (!cr6.eq) goto loc_82279628;
loc_82279624:
	// li r31,0
	r31.s64 = 0;
loc_82279628:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279654
	if (cr6.eq) goto loc_82279654;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227964c
	if (cr6.eq) goto loc_8227964C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279644;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279650
	goto loc_82279650;
loc_8227964C:
	// li r11,0
	r11.s64 = 0;
loc_82279650:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279654:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279678
	if (cr6.eq) goto loc_82279678;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279668;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227967c
	if (cr6.eq) goto loc_8227967C;
loc_82279678:
	// li r11,0
	r11.s64 = 0;
loc_8227967C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279688"))) PPC_WEAK_FUNC(sub_82279688);
PPC_FUNC_IMPL(__imp__sub_82279688) {
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
	ctx.lr = 0x82279690;
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
	ctx.lr = 0x822796C0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x822796CC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822796DC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279710
	if (cr6.eq) goto loc_82279710;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279710
	if (!cr6.eq) goto loc_82279710;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82279700;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279714
	if (!cr6.eq) goto loc_82279714;
loc_82279710:
	// li r31,0
	r31.s64 = 0;
loc_82279714:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279740
	if (cr6.eq) goto loc_82279740;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279738
	if (cr6.eq) goto loc_82279738;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279730;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x8227973c
	goto loc_8227973C;
loc_82279738:
	// li r11,0
	r11.s64 = 0;
loc_8227973C:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279740:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279764
	if (cr6.eq) goto loc_82279764;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279754;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82279768
	if (cr6.eq) goto loc_82279768;
loc_82279764:
	// li r11,0
	r11.s64 = 0;
loc_82279768:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279774"))) PPC_WEAK_FUNC(sub_82279774);
PPC_FUNC_IMPL(__imp__sub_82279774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279778"))) PPC_WEAK_FUNC(sub_82279778);
PPC_FUNC_IMPL(__imp__sub_82279778) {
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
	ctx.lr = 0x82279780;
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
	ctx.lr = 0x822797A4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822797B0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822797C0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822797e4
	if (cr6.eq) goto loc_822797E4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82278d00
	ctx.lr = 0x822797D4;
	sub_82278D00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822797e8
	if (!cr6.eq) goto loc_822797E8;
loc_822797E4:
	// li r30,0
	r30.s64 = 0;
loc_822797E8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82279820
	if (cr6.eq) goto loc_82279820;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279818
	if (cr6.eq) goto loc_82279818;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82279804;
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
loc_82279818:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82279820:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227982C"))) PPC_WEAK_FUNC(sub_8227982C);
PPC_FUNC_IMPL(__imp__sub_8227982C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279830"))) PPC_WEAK_FUNC(sub_82279830);
PPC_FUNC_IMPL(__imp__sub_82279830) {
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
	ctx.lr = 0x82279838;
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
	ctx.lr = 0x82279868;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82279874;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279884;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822798b4
	if (cr6.eq) goto loc_822798B4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822798b4
	if (!cr6.eq) goto loc_822798B4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278de8
	ctx.lr = 0x822798A4;
	sub_82278DE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822798b8
	if (!cr6.eq) goto loc_822798B8;
loc_822798B4:
	// li r31,0
	r31.s64 = 0;
loc_822798B8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822798e4
	if (cr6.eq) goto loc_822798E4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822798dc
	if (cr6.eq) goto loc_822798DC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822798D4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822798e0
	goto loc_822798E0;
loc_822798DC:
	// li r11,0
	r11.s64 = 0;
loc_822798E0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822798E4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279908
	if (cr6.eq) goto loc_82279908;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822798F8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227990c
	if (cr6.eq) goto loc_8227990C;
loc_82279908:
	// li r11,0
	r11.s64 = 0;
loc_8227990C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279918"))) PPC_WEAK_FUNC(sub_82279918);
PPC_FUNC_IMPL(__imp__sub_82279918) {
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
	ctx.lr = 0x82279920;
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
	ctx.lr = 0x82279950;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227995C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8227996C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8227999c
	if (cr6.eq) goto loc_8227999C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8227999c
	if (!cr6.eq) goto loc_8227999C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278eb0
	ctx.lr = 0x8227998C;
	sub_82278EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822799a0
	if (!cr6.eq) goto loc_822799A0;
loc_8227999C:
	// li r31,0
	r31.s64 = 0;
loc_822799A0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822799cc
	if (cr6.eq) goto loc_822799CC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822799c4
	if (cr6.eq) goto loc_822799C4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822799BC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822799c8
	goto loc_822799C8;
loc_822799C4:
	// li r11,0
	r11.s64 = 0;
loc_822799C8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822799CC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822799f0
	if (cr6.eq) goto loc_822799F0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822799E0;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822799f4
	if (cr6.eq) goto loc_822799F4;
loc_822799F0:
	// li r11,0
	r11.s64 = 0;
loc_822799F4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279A00"))) PPC_WEAK_FUNC(sub_82279A00);
PPC_FUNC_IMPL(__imp__sub_82279A00) {
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
	ctx.lr = 0x82279A08;
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
	ctx.lr = 0x82279A38;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82279A44;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279A54;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279a88
	if (cr6.eq) goto loc_82279A88;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279a88
	if (!cr6.eq) goto loc_82279A88;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82279A78;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279a8c
	if (!cr6.eq) goto loc_82279A8C;
loc_82279A88:
	// li r31,0
	r31.s64 = 0;
loc_82279A8C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279ab8
	if (cr6.eq) goto loc_82279AB8;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279ab0
	if (cr6.eq) goto loc_82279AB0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279AA8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279ab4
	goto loc_82279AB4;
loc_82279AB0:
	// li r11,0
	r11.s64 = 0;
loc_82279AB4:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279AB8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279adc
	if (cr6.eq) goto loc_82279ADC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279ACC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82279ae0
	if (cr6.eq) goto loc_82279AE0;
loc_82279ADC:
	// li r11,0
	r11.s64 = 0;
loc_82279AE0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279AEC"))) PPC_WEAK_FUNC(sub_82279AEC);
PPC_FUNC_IMPL(__imp__sub_82279AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279AF0"))) PPC_WEAK_FUNC(sub_82279AF0);
PPC_FUNC_IMPL(__imp__sub_82279AF0) {
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
	ctx.lr = 0x82279AF8;
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
	ctx.lr = 0x82279B28;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82279B34;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279B44;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279b78
	if (cr6.eq) goto loc_82279B78;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279b78
	if (!cr6.eq) goto loc_82279B78;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82275750
	ctx.lr = 0x82279B68;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279b7c
	if (!cr6.eq) goto loc_82279B7C;
loc_82279B78:
	// li r31,0
	r31.s64 = 0;
loc_82279B7C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279ba8
	if (cr6.eq) goto loc_82279BA8;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279ba0
	if (cr6.eq) goto loc_82279BA0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279B98;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279ba4
	goto loc_82279BA4;
loc_82279BA0:
	// li r11,0
	r11.s64 = 0;
loc_82279BA4:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279BA8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279bcc
	if (cr6.eq) goto loc_82279BCC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279BBC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82279bd0
	if (cr6.eq) goto loc_82279BD0;
loc_82279BCC:
	// li r11,0
	r11.s64 = 0;
loc_82279BD0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279BDC"))) PPC_WEAK_FUNC(sub_82279BDC);
PPC_FUNC_IMPL(__imp__sub_82279BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279BE0"))) PPC_WEAK_FUNC(sub_82279BE0);
PPC_FUNC_IMPL(__imp__sub_82279BE0) {
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
	ctx.lr = 0x82279BE8;
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
	ctx.lr = 0x82279C18;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82279C24;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82279C34;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279c64
	if (cr6.eq) goto loc_82279C64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82279c64
	if (!cr6.eq) goto loc_82279C64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82278f38
	ctx.lr = 0x82279C54;
	sub_82278F38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82279c68
	if (!cr6.eq) goto loc_82279C68;
loc_82279C64:
	// li r31,0
	r31.s64 = 0;
loc_82279C68:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82279c94
	if (cr6.eq) goto loc_82279C94;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279c8c
	if (cr6.eq) goto loc_82279C8C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279C84;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82279c90
	goto loc_82279C90;
loc_82279C8C:
	// li r11,0
	r11.s64 = 0;
loc_82279C90:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82279C94:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82279cb8
	if (cr6.eq) goto loc_82279CB8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82279CA8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82279cbc
	if (cr6.eq) goto loc_82279CBC;
loc_82279CB8:
	// li r11,0
	r11.s64 = 0;
loc_82279CBC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279CC8"))) PPC_WEAK_FUNC(sub_82279CC8);
PPC_FUNC_IMPL(__imp__sub_82279CC8) {
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
	ctx.lr = 0x82279CD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addis r26,r29,2
	r26.s64 = r29.s64 + 131072;
	// addi r10,r11,-428
	ctx.r10.s64 = r11.s64 + -428;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r26,80
	r26.s64 = r26.s64 + 80;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r27,68(r29)
	PPC_STORE_U32(r29.u32 + 68, r27.u32);
	// li r30,30
	r30.s64 = 30;
	// stw r27,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r27.u32);
	// mr r31,r26
	r31.u64 = r26.u64;
	// addi r28,r11,-456
	r28.s64 = r11.s64 + -456;
loc_82279D08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299cd8
	ctx.lr = 0x82279D10;
	sub_82299CD8(ctx, base);
	// lbz r11,216(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 216);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r27,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r27.u32);
	// stb r10,216(r31)
	PPC_STORE_U8(r31.u32 + 216, ctx.r10.u8);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bge 0x82279d08
	if (!cr0.lt) goto loc_82279D08;
	// lis r11,2
	r11.s64 = 131072;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r11,6930
	ctx.r9.u64 = r11.u64 | 6930;
	// li r3,20
	ctx.r3.s64 = 20;
	// stbx r10,r29,r9
	PPC_STORE_U8(r29.u32 + ctx.r9.u32, ctx.r10.u8);
	// bl 0x82130528
	ctx.lr = 0x82279D48;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82279d5c
	if (cr6.eq) goto loc_82279D5C;
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x82278620
	ctx.lr = 0x82279D58;
	sub_82278620(ctx, base);
	// b 0x82279d60
	goto loc_82279D60;
loc_82279D5C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82279D60:
	// lis r11,2
	r11.s64 = 131072;
	// mr r31,r26
	r31.u64 = r26.u64;
	// ori r10,r11,76
	ctx.r10.u64 = r11.u64 | 76;
	// li r30,31
	r30.s64 = 31;
	// stwx r3,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, ctx.r3.u32);
loc_82279D74:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82279D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,220
	r31.s64 = r31.s64 + 220;
	// bne 0x82279d74
	if (!cr0.eq) goto loc_82279D74;
	// addis r11,r29,2
	r11.s64 = r29.s64 + 131072;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r11,r11,6900
	r11.s64 = r11.s64 + 6900;
	// li r10,30
	ctx.r10.s64 = 30;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82279DA8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82279da8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82279DA8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82279DC0"))) PPC_WEAK_FUNC(sub_82279DC0);
PPC_FUNC_IMPL(__imp__sub_82279DC0) {
	PPC_FUNC_PROLOGUE();
	// lis r3,2
	ctx.r3.s64 = 131072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82279DC8"))) PPC_WEAK_FUNC(sub_82279DC8);
PPC_FUNC_IMPL(__imp__sub_82279DC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// addis r11,r9,2
	r11.s64 = ctx.r9.s64 + 131072;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
loc_82279DE4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82279e08
	if (cr6.eq) goto loc_82279E08;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,220
	r11.s64 = r11.s64 + 220;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x82279de4
	if (cr6.lt) goto loc_82279DE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82279E08:
	// mulli r11,r10,220
	r11.s64 = ctx.r10.s64 * 220;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addis r3,r11,2
	ctx.r3.s64 = r11.s64 + 131072;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82279E1C"))) PPC_WEAK_FUNC(sub_82279E1C);
PPC_FUNC_IMPL(__imp__sub_82279E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279E20"))) PPC_WEAK_FUNC(sub_82279E20);
PPC_FUNC_IMPL(__imp__sub_82279E20) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82279e88
	if (cr6.eq) goto loc_82279E88;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x82279E58;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82279e88
	if (cr6.eq) goto loc_82279E88;
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82279e88
	if (!cr6.eq) goto loc_82279E88;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82279e7c
	if (cr6.eq) goto loc_82279E7C;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// bl 0x82278948
	ctx.lr = 0x82279E7C;
	sub_82278948(ctx, base);
loc_82279E7C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x82279E88;
	sub_825D7AA0(ctx, base);
loc_82279E88:
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

__attribute__((alias("__imp__sub_82279EA0"))) PPC_WEAK_FUNC(sub_82279EA0);
PPC_FUNC_IMPL(__imp__sub_82279EA0) {
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
	ctx.lr = 0x82279EA8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16376
	ctx.r10.s64 = r11.s64 + 16376;
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
	// bl 0x822771e8
	ctx.lr = 0x82279EDC;
	sub_822771E8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82279f14
	if (cr6.eq) goto loc_82279F14;
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
	ctx.lr = 0x82279F04;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82279f18
	if (!cr6.eq) goto loc_82279F18;
loc_82279F14:
	// li r11,0
	r11.s64 = 0;
loc_82279F18:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82279F24"))) PPC_WEAK_FUNC(sub_82279F24);
PPC_FUNC_IMPL(__imp__sub_82279F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279F28"))) PPC_WEAK_FUNC(sub_82279F28);
PPC_FUNC_IMPL(__imp__sub_82279F28) {
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
	ctx.lr = 0x82279F30;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16312
	ctx.r10.s64 = r11.s64 + 16312;
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
	// bl 0x82277528
	ctx.lr = 0x82279F64;
	sub_82277528(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82279f9c
	if (cr6.eq) goto loc_82279F9C;
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
	ctx.lr = 0x82279F8C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82279fa0
	if (!cr6.eq) goto loc_82279FA0;
loc_82279F9C:
	// li r11,0
	r11.s64 = 0;
loc_82279FA0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82279FAC"))) PPC_WEAK_FUNC(sub_82279FAC);
PPC_FUNC_IMPL(__imp__sub_82279FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82279FB0"))) PPC_WEAK_FUNC(sub_82279FB0);
PPC_FUNC_IMPL(__imp__sub_82279FB0) {
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
	ctx.lr = 0x82279FB8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16664
	ctx.r10.s64 = r11.s64 + 16664;
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
	// bl 0x82277388
	ctx.lr = 0x82279FEC;
	sub_82277388(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a024
	if (cr6.eq) goto loc_8227A024;
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
	ctx.lr = 0x8227A014;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a028
	if (!cr6.eq) goto loc_8227A028;
loc_8227A024:
	// li r11,0
	r11.s64 = 0;
loc_8227A028:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A034"))) PPC_WEAK_FUNC(sub_8227A034);
PPC_FUNC_IMPL(__imp__sub_8227A034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A038"))) PPC_WEAK_FUNC(sub_8227A038);
PPC_FUNC_IMPL(__imp__sub_8227A038) {
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
	ctx.lr = 0x8227A040;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16408
	ctx.r10.s64 = r11.s64 + 16408;
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
	// bl 0x82277780
	ctx.lr = 0x8227A074;
	sub_82277780(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a0ac
	if (cr6.eq) goto loc_8227A0AC;
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
	ctx.lr = 0x8227A09C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a0b0
	if (!cr6.eq) goto loc_8227A0B0;
loc_8227A0AC:
	// li r11,0
	r11.s64 = 0;
loc_8227A0B0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A0BC"))) PPC_WEAK_FUNC(sub_8227A0BC);
PPC_FUNC_IMPL(__imp__sub_8227A0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A0C0"))) PPC_WEAK_FUNC(sub_8227A0C0);
PPC_FUNC_IMPL(__imp__sub_8227A0C0) {
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
	ctx.lr = 0x8227A0C8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16024
	ctx.r10.s64 = r11.s64 + 16024;
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
	// bl 0x82277ac8
	ctx.lr = 0x8227A0FC;
	sub_82277AC8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a134
	if (cr6.eq) goto loc_8227A134;
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
	ctx.lr = 0x8227A124;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a138
	if (!cr6.eq) goto loc_8227A138;
loc_8227A134:
	// li r11,0
	r11.s64 = 0;
loc_8227A138:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A144"))) PPC_WEAK_FUNC(sub_8227A144);
PPC_FUNC_IMPL(__imp__sub_8227A144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A148"))) PPC_WEAK_FUNC(sub_8227A148);
PPC_FUNC_IMPL(__imp__sub_8227A148) {
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
	ctx.lr = 0x8227A150;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16728
	ctx.r10.s64 = r11.s64 + 16728;
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
	// bl 0x82277b80
	ctx.lr = 0x8227A184;
	sub_82277B80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a1bc
	if (cr6.eq) goto loc_8227A1BC;
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
	ctx.lr = 0x8227A1AC;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a1c0
	if (!cr6.eq) goto loc_8227A1C0;
loc_8227A1BC:
	// li r11,0
	r11.s64 = 0;
loc_8227A1C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A1CC"))) PPC_WEAK_FUNC(sub_8227A1CC);
PPC_FUNC_IMPL(__imp__sub_8227A1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A1D0"))) PPC_WEAK_FUNC(sub_8227A1D0);
PPC_FUNC_IMPL(__imp__sub_8227A1D0) {
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
	ctx.lr = 0x8227A1D8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16536
	ctx.r10.s64 = r11.s64 + 16536;
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
	// bl 0x822776c8
	ctx.lr = 0x8227A20C;
	sub_822776C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a244
	if (cr6.eq) goto loc_8227A244;
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
	ctx.lr = 0x8227A234;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a248
	if (!cr6.eq) goto loc_8227A248;
loc_8227A244:
	// li r11,0
	r11.s64 = 0;
loc_8227A248:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A254"))) PPC_WEAK_FUNC(sub_8227A254);
PPC_FUNC_IMPL(__imp__sub_8227A254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A258"))) PPC_WEAK_FUNC(sub_8227A258);
PPC_FUNC_IMPL(__imp__sub_8227A258) {
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
	ctx.lr = 0x8227A260;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16344
	ctx.r10.s64 = r11.s64 + 16344;
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
	// bl 0x82277928
	ctx.lr = 0x8227A294;
	sub_82277928(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a2cc
	if (cr6.eq) goto loc_8227A2CC;
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
	ctx.lr = 0x8227A2BC;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a2d0
	if (!cr6.eq) goto loc_8227A2D0;
loc_8227A2CC:
	// li r11,0
	r11.s64 = 0;
loc_8227A2D0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A2DC"))) PPC_WEAK_FUNC(sub_8227A2DC);
PPC_FUNC_IMPL(__imp__sub_8227A2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A2E0"))) PPC_WEAK_FUNC(sub_8227A2E0);
PPC_FUNC_IMPL(__imp__sub_8227A2E0) {
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
	ctx.lr = 0x8227A2E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addis r29,r28,2
	r29.s64 = r28.s64 + 131072;
	// addi r10,r11,-428
	ctx.r10.s64 = r11.s64 + -428;
	// addi r29,r29,76
	r29.s64 = r29.s64 + 76;
	// li r30,0
	r30.s64 = 0;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227a344
	if (cr6.eq) goto loc_8227A344;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a328
	if (cr6.eq) goto loc_8227A328;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8227A328;
	sub_82130588(ctx, base);
loc_8227A328:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// bl 0x82130588
	ctx.lr = 0x8227A344;
	sub_82130588(ctx, base);
loc_8227A344:
	// addis r11,r28,2
	r11.s64 = r28.s64 + 131072;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r10,30
	ctx.r10.s64 = 30;
	// addi r11,r11,6900
	r11.s64 = r11.s64 + 6900;
	// addi r9,r9,-488
	ctx.r9.s64 = ctx.r9.s64 + -488;
loc_8227A35C:
	// addi r11,r11,-220
	r11.s64 = r11.s64 + -220;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8227a35c
	if (!cr0.lt) goto loc_8227A35C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-572
	ctx.r10.s64 = r11.s64 + -572;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A380"))) PPC_WEAK_FUNC(sub_8227A380);
PPC_FUNC_IMPL(__imp__sub_8227A380) {
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
	// lwz r3,5632(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5632);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227a3a8
	if (cr6.eq) goto loc_8227A3A8;
	// addi r4,r31,5636
	ctx.r4.s64 = r31.s64 + 5636;
	// bl 0x824ebcc8
	ctx.lr = 0x8227A3A8;
	sub_824EBCC8(ctx, base);
loc_8227A3A8:
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// bl 0x824e7d20
	ctx.lr = 0x8227A3B0;
	sub_824E7D20(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, r11.u32);
	// stw r11,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r11.u32);
	// stw r11,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r11.u32);
	// stw r11,5620(r31)
	PPC_STORE_U32(r31.u32 + 5620, r11.u32);
	// stw r11,5616(r31)
	PPC_STORE_U32(r31.u32 + 5616, r11.u32);
	// stw r11,5612(r31)
	PPC_STORE_U32(r31.u32 + 5612, r11.u32);
	// stw r10,5628(r31)
	PPC_STORE_U32(r31.u32 + 5628, ctx.r10.u32);
	// stw r11,5632(r31)
	PPC_STORE_U32(r31.u32 + 5632, r11.u32);
	// stw r11,5624(r31)
	PPC_STORE_U32(r31.u32 + 5624, r11.u32);
	// sth r11,5680(r31)
	PPC_STORE_U16(r31.u32 + 5680, r11.u16);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227A3F4"))) PPC_WEAK_FUNC(sub_8227A3F4);
PPC_FUNC_IMPL(__imp__sub_8227A3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A3F8"))) PPC_WEAK_FUNC(sub_8227A3F8);
PPC_FUNC_IMPL(__imp__sub_8227A3F8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r3,5664
	r30.s64 = ctx.r3.s64 + 5664;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x8227A424;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227a440
	if (!cr6.eq) goto loc_8227A440;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7930
	ctx.lr = 0x8227A440;
	sub_824E7930(ctx, base);
loc_8227A440:
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

__attribute__((alias("__imp__sub_8227A458"))) PPC_WEAK_FUNC(sub_8227A458);
PPC_FUNC_IMPL(__imp__sub_8227A458) {
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
	ctx.lr = 0x8227A460;
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
	// blt cr6,0x8227a4cc
	if (cr6.lt) goto loc_8227A4CC;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A488;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a4ac
	if (!cr6.eq) goto loc_8227A4AC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A4A0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a4cc
	if (cr6.eq) goto loc_8227A4CC;
loc_8227A4AC:
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
	// bl 0x82279ea0
	ctx.lr = 0x8227A4C4;
	sub_82279EA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227A4CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227A4D8"))) PPC_WEAK_FUNC(sub_8227A4D8);
PPC_FUNC_IMPL(__imp__sub_8227A4D8) {
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
	ctx.lr = 0x8227A4E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8227A4FC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227A514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227a548
	if (cr6.eq) goto loc_8227A548;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227a540
	if (cr6.eq) goto loc_8227A540;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227a548
	if (!cr6.eq) goto loc_8227A548;
loc_8227A540:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227a54c
	goto loc_8227A54C;
loc_8227A548:
	// li r11,0
	r11.s64 = 0;
loc_8227A54C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a5d0
	if (cr6.eq) goto loc_8227A5D0;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8227a5c0
	if (cr6.lt) goto loc_8227A5C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A580;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a5a4
	if (!cr6.eq) goto loc_8227A5A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A598;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a5c0
	if (cr6.eq) goto loc_8227A5C0;
loc_8227A5A4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82278fa8
	ctx.lr = 0x8227A5BC;
	sub_82278FA8(ctx, base);
	// b 0x8227a5c4
	goto loc_8227A5C4;
loc_8227A5C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227A5C4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8227A5D0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227a4fc
	if (cr6.lt) goto loc_8227A4FC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227A5E8"))) PPC_WEAK_FUNC(sub_8227A5E8);
PPC_FUNC_IMPL(__imp__sub_8227A5E8) {
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
	ctx.lr = 0x8227A5F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8227A60C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227A624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227a658
	if (cr6.eq) goto loc_8227A658;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227a650
	if (cr6.eq) goto loc_8227A650;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227a658
	if (!cr6.eq) goto loc_8227A658;
loc_8227A650:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227a65c
	goto loc_8227A65C;
loc_8227A658:
	// li r11,0
	r11.s64 = 0;
loc_8227A65C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a6e0
	if (cr6.eq) goto loc_8227A6E0;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8227a6d0
	if (cr6.lt) goto loc_8227A6D0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A690;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a6b4
	if (!cr6.eq) goto loc_8227A6B4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A6A8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a6d0
	if (cr6.eq) goto loc_8227A6D0;
loc_8227A6B4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82279030
	ctx.lr = 0x8227A6CC;
	sub_82279030(ctx, base);
	// b 0x8227a6d4
	goto loc_8227A6D4;
loc_8227A6D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227A6D4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8227A6E0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227a60c
	if (cr6.lt) goto loc_8227A60C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227A6F8"))) PPC_WEAK_FUNC(sub_8227A6F8);
PPC_FUNC_IMPL(__imp__sub_8227A6F8) {
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
	ctx.lr = 0x8227A700;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16992
	ctx.r10.s64 = r11.s64 + 16992;
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
	// bl 0x82279258
	ctx.lr = 0x8227A734;
	sub_82279258(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a76c
	if (cr6.eq) goto loc_8227A76C;
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
	ctx.lr = 0x8227A75C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a770
	if (!cr6.eq) goto loc_8227A770;
loc_8227A76C:
	// li r11,0
	r11.s64 = 0;
loc_8227A770:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A77C"))) PPC_WEAK_FUNC(sub_8227A77C);
PPC_FUNC_IMPL(__imp__sub_8227A77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A780"))) PPC_WEAK_FUNC(sub_8227A780);
PPC_FUNC_IMPL(__imp__sub_8227A780) {
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
	ctx.lr = 0x8227A788;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,17024
	ctx.r10.s64 = r11.s64 + 17024;
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
	// bl 0x822790b8
	ctx.lr = 0x8227A7BC;
	sub_822790B8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a7f4
	if (cr6.eq) goto loc_8227A7F4;
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
	ctx.lr = 0x8227A7E4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a7f8
	if (!cr6.eq) goto loc_8227A7F8;
loc_8227A7F4:
	// li r11,0
	r11.s64 = 0;
loc_8227A7F8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A804"))) PPC_WEAK_FUNC(sub_8227A804);
PPC_FUNC_IMPL(__imp__sub_8227A804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A808"))) PPC_WEAK_FUNC(sub_8227A808);
PPC_FUNC_IMPL(__imp__sub_8227A808) {
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
	ctx.lr = 0x8227A810;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,17056
	ctx.r10.s64 = r11.s64 + 17056;
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
	// bl 0x822793f8
	ctx.lr = 0x8227A844;
	sub_822793F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227a87c
	if (cr6.eq) goto loc_8227A87C;
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
	ctx.lr = 0x8227A86C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227a880
	if (!cr6.eq) goto loc_8227A880;
loc_8227A87C:
	// li r11,0
	r11.s64 = 0;
loc_8227A880:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227A88C"))) PPC_WEAK_FUNC(sub_8227A88C);
PPC_FUNC_IMPL(__imp__sub_8227A88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227A890"))) PPC_WEAK_FUNC(sub_8227A890);
PPC_FUNC_IMPL(__imp__sub_8227A890) {
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
	ctx.lr = 0x8227A898;
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
	// blt cr6,0x8227a904
	if (cr6.lt) goto loc_8227A904;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A8C0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a8e4
	if (!cr6.eq) goto loc_8227A8E4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A8D8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a904
	if (cr6.eq) goto loc_8227A904;
loc_8227A8E4:
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
	// bl 0x82279f28
	ctx.lr = 0x8227A8FC;
	sub_82279F28(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227A904:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227A910"))) PPC_WEAK_FUNC(sub_8227A910);
PPC_FUNC_IMPL(__imp__sub_8227A910) {
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
	ctx.lr = 0x8227A918;
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
	// blt cr6,0x8227a984
	if (cr6.lt) goto loc_8227A984;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A940;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a964
	if (!cr6.eq) goto loc_8227A964;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A958;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227a984
	if (cr6.eq) goto loc_8227A984;
loc_8227A964:
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
	// bl 0x82279fb0
	ctx.lr = 0x8227A97C;
	sub_82279FB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227A984:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227A990"))) PPC_WEAK_FUNC(sub_8227A990);
PPC_FUNC_IMPL(__imp__sub_8227A990) {
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
	ctx.lr = 0x8227A998;
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
	// blt cr6,0x8227aa04
	if (cr6.lt) goto loc_8227AA04;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227A9C0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227a9e4
	if (!cr6.eq) goto loc_8227A9E4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227A9D8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227aa04
	if (cr6.eq) goto loc_8227AA04;
loc_8227A9E4:
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
	// bl 0x8227a038
	ctx.lr = 0x8227A9FC;
	sub_8227A038(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227AA04:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227AA10"))) PPC_WEAK_FUNC(sub_8227AA10);
PPC_FUNC_IMPL(__imp__sub_8227AA10) {
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
	ctx.lr = 0x8227AA18;
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
	// blt cr6,0x8227aa84
	if (cr6.lt) goto loc_8227AA84;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227AA40;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227aa64
	if (!cr6.eq) goto loc_8227AA64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227AA58;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227aa84
	if (cr6.eq) goto loc_8227AA84;
loc_8227AA64:
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
	// bl 0x8227a0c0
	ctx.lr = 0x8227AA7C;
	sub_8227A0C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227AA84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227AA90"))) PPC_WEAK_FUNC(sub_8227AA90);
PPC_FUNC_IMPL(__imp__sub_8227AA90) {
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
	ctx.lr = 0x8227AA98;
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
	// blt cr6,0x8227ab04
	if (cr6.lt) goto loc_8227AB04;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227AAC0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227aae4
	if (!cr6.eq) goto loc_8227AAE4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227AAD8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ab04
	if (cr6.eq) goto loc_8227AB04;
loc_8227AAE4:
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
	// bl 0x8227a1d0
	ctx.lr = 0x8227AAFC;
	sub_8227A1D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227AB04:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227AB10"))) PPC_WEAK_FUNC(sub_8227AB10);
PPC_FUNC_IMPL(__imp__sub_8227AB10) {
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
	ctx.lr = 0x8227AB18;
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
	// blt cr6,0x8227ab84
	if (cr6.lt) goto loc_8227AB84;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227AB40;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227ab64
	if (!cr6.eq) goto loc_8227AB64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227AB58;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ab84
	if (cr6.eq) goto loc_8227AB84;
loc_8227AB64:
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
	// bl 0x8227a258
	ctx.lr = 0x8227AB7C;
	sub_8227A258(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227AB84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227AB90"))) PPC_WEAK_FUNC(sub_8227AB90);
PPC_FUNC_IMPL(__imp__sub_8227AB90) {
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
	ctx.lr = 0x8227AB98;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16600
	ctx.r10.s64 = r11.s64 + 16600;
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
	// bl 0x82279778
	ctx.lr = 0x8227ABCC;
	sub_82279778(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227ac04
	if (cr6.eq) goto loc_8227AC04;
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
	ctx.lr = 0x8227ABF4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227ac08
	if (!cr6.eq) goto loc_8227AC08;
loc_8227AC04:
	// li r11,0
	r11.s64 = 0;
loc_8227AC08:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227AC14"))) PPC_WEAK_FUNC(sub_8227AC14);
PPC_FUNC_IMPL(__imp__sub_8227AC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227AC18"))) PPC_WEAK_FUNC(sub_8227AC18);
PPC_FUNC_IMPL(__imp__sub_8227AC18) {
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
	// bl 0x8227a2e0
	ctx.lr = 0x8227AC38;
	sub_8227A2E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ac50
	if (cr6.eq) goto loc_8227AC50;
	// bl 0x82130588
	ctx.lr = 0x8227AC4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227AC50:
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

__attribute__((alias("__imp__sub_8227AC68"))) PPC_WEAK_FUNC(sub_8227AC68);
PPC_FUNC_IMPL(__imp__sub_8227AC68) {
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
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8227a4d8
	ctx.lr = 0x8227AC84;
	sub_8227A4D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227AC94"))) PPC_WEAK_FUNC(sub_8227AC94);
PPC_FUNC_IMPL(__imp__sub_8227AC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227AC98"))) PPC_WEAK_FUNC(sub_8227AC98);
PPC_FUNC_IMPL(__imp__sub_8227AC98) {
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
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8227a5e8
	ctx.lr = 0x8227ACB4;
	sub_8227A5E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227ACC4"))) PPC_WEAK_FUNC(sub_8227ACC4);
PPC_FUNC_IMPL(__imp__sub_8227ACC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227ACC8"))) PPC_WEAK_FUNC(sub_8227ACC8);
PPC_FUNC_IMPL(__imp__sub_8227ACC8) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,22292(r31)
	PPC_STORE_U16(r31.u32 + 22292, r11.u16);
	// bl 0x8229b450
	ctx.lr = 0x8227ACF0;
	sub_8229B450(ctx, base);
	// addi r3,r31,8280
	ctx.r3.s64 = r31.s64 + 8280;
	// bl 0x8229b450
	ctx.lr = 0x8227ACF8;
	sub_8229B450(ctx, base);
	// addi r3,r31,16556
	ctx.r3.s64 = r31.s64 + 16556;
	// bl 0x8227a380
	ctx.lr = 0x8227AD00;
	sub_8227A380(ctx, base);
	// lbz r10,22300(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 22300);
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,22296(r31)
	PPC_STORE_U32(r31.u32 + 22296, r11.u32);
	// stb r9,22300(r31)
	PPC_STORE_U8(r31.u32 + 22300, ctx.r9.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227AD28"))) PPC_WEAK_FUNC(sub_8227AD28);
PPC_FUNC_IMPL(__imp__sub_8227AD28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r8,8
	r11.s64 = ctx.r8.s64 + 8;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8227AD3C:
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x8227ad3c
	if (!cr0.eq) goto loc_8227AD3C;
	// lbz r11,208(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 208);
	// lbz r10,216(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 216);
	// lwz r3,212(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 212);
	// ori r7,r11,128
	ctx.r7.u64 = r11.u64 | 128;
	// clrlwi r6,r10,25
	ctx.r6.u64 = ctx.r10.u32 & 0x7F;
	// stw r9,196(r8)
	PPC_STORE_U32(ctx.r8.u32 + 196, ctx.r9.u32);
	// stb r7,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, ctx.r7.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r9,200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 200, ctx.r9.u32);
	// stw r9,204(r8)
	PPC_STORE_U32(ctx.r8.u32 + 204, ctx.r9.u32);
	// stb r6,216(r8)
	PPC_STORE_U8(ctx.r8.u32 + 216, ctx.r6.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8227acc8
	sub_8227ACC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8227AD88"))) PPC_WEAK_FUNC(sub_8227AD88);
PPC_FUNC_IMPL(__imp__sub_8227AD88) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227AD8C"))) PPC_WEAK_FUNC(sub_8227AD8C);
PPC_FUNC_IMPL(__imp__sub_8227AD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227AD90"))) PPC_WEAK_FUNC(sub_8227AD90);
PPC_FUNC_IMPL(__imp__sub_8227AD90) {
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
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,-1
	ctx.r9.s64 = -1;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8227adf4
	if (!cr6.eq) goto loc_8227ADF4;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227adf4
	if (cr6.eq) goto loc_8227ADF4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r4,r11,22240
	ctx.r4.s64 = r11.s64 + 22240;
	// addi r3,r11,22220
	ctx.r3.s64 = r11.s64 + 22220;
	// bl 0x82279e20
	ctx.lr = 0x8227ADE8;
	sub_82279E20(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r3,r11,16556
	ctx.r3.s64 = r11.s64 + 16556;
	// bl 0x8227a380
	ctx.lr = 0x8227ADF4;
	sub_8227A380(ctx, base);
loc_8227ADF4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227AE08"))) PPC_WEAK_FUNC(sub_8227AE08);
PPC_FUNC_IMPL(__imp__sub_8227AE08) {
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
	ctx.lr = 0x8227AE10;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
	// bl 0x8229af08
	ctx.lr = 0x8227AE34;
	sub_8229AF08(ctx, base);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8227AE44;
	sub_823DA950(ctx, base);
	// lhz r11,5680(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5680);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bge cr6,0x8227ae5c
	if (!cr6.lt) goto loc_8227AE5C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// b 0x8227ae60
	goto loc_8227AE60;
loc_8227AE5C:
	// li r11,1
	r11.s64 = 1;
loc_8227AE60:
	// lwz r10,5624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5624);
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227aef0
	if (cr6.eq) goto loc_8227AEF0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82278698
	ctx.lr = 0x8227AE78;
	sub_82278698(ctx, base);
	// lwz r11,5624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5624);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,204
	ctx.r3.s64 = ctx.r1.s64 + 204;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x82276a20
	ctx.lr = 0x8227AE8C;
	sub_82276A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227aef0
	if (cr6.eq) goto loc_8227AEF0;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227aebc
	if (!cr6.eq) goto loc_8227AEBC;
	// lhz r10,292(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 292);
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8227aeec
	if (cr6.eq) goto loc_8227AEEC;
loc_8227AEBC:
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,5624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5624);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,200
	ctx.r5.s64 = ctx.r1.s64 + 200;
	// lwz r4,5628(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 5628);
	// lwz r3,5632(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5632);
	// sth r11,200(r1)
	PPC_STORE_U16(ctx.r1.u32 + 200, r11.u16);
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// sth r9,202(r1)
	PPC_STORE_U16(ctx.r1.u32 + 202, ctx.r9.u16);
	// bl 0x8227a6f8
	ctx.lr = 0x8227AEE8;
	sub_8227A6F8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8227AEEC:
	// li r29,1
	r29.s64 = 1;
loc_8227AEF0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227af38
	if (!cr6.eq) goto loc_8227AF38;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82278698
	ctx.lr = 0x8227AF04;
	sub_82278698(ctx, base);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// sth r11,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, r11.u16);
	// bl 0x823da950
	ctx.lr = 0x8227AF1C;
	sub_823DA950(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,5628(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 5628);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,5632(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5632);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// bl 0x8227a780
	ctx.lr = 0x8227AF34;
	sub_8227A780(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8227AF38:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227afc8
	if (cr6.eq) goto loc_8227AFC8;
	// lwz r11,2808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2808);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227af8c
	if (!cr6.eq) goto loc_8227AF8C;
	// lwz r11,2804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// li r10,49
	ctx.r10.s64 = 49;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r10.u32);
	// stw r11,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r11.u32);
	// cmpwi cr6,r11,50
	cr6.compare<int32_t>(r11.s32, 50, xer);
	// bne cr6,0x8227af70
	if (!cr6.eq) goto loc_8227AF70;
	// stw r26,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r26.u32);
loc_8227AF70:
	// lwz r11,2804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// lwz r10,5624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5624);
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8227af8c
	if (!cr6.eq) goto loc_8227AF8C;
	// stw r26,5624(r31)
	PPC_STORE_U32(r31.u32 + 5624, r26.u32);
loc_8227AF8C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275448
	ctx.lr = 0x8227AF98;
	sub_82275448(ctx, base);
	// lhz r11,5680(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5680);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bge cr6,0x8227afb8
	if (!cr6.lt) goto loc_8227AFB8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,5680(r31)
	PPC_STORE_U16(r31.u32 + 5680, r11.u16);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9240
	return;
loc_8227AFB8:
	// li r11,1
	r11.s64 = 1;
	// sth r11,5680(r31)
	PPC_STORE_U16(r31.u32 + 5680, r11.u16);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9240
	return;
loc_8227AFC8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8227AFD4"))) PPC_WEAK_FUNC(sub_8227AFD4);
PPC_FUNC_IMPL(__imp__sub_8227AFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227AFD8"))) PPC_WEAK_FUNC(sub_8227AFD8);
PPC_FUNC_IMPL(__imp__sub_8227AFD8) {
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229af08
	ctx.lr = 0x8227AFFC;
	sub_8229AF08(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82618750
	ctx.lr = 0x8227B004;
	sub_82618750(ctx, base);
	// addi r10,r1,220
	ctx.r10.s64 = ctx.r1.s64 + 220;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// sth r11,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r11.u16);
	// stb r11,6(r10)
	PPC_STORE_U8(ctx.r10.u32 + 6, r11.u8);
	// bl 0x82618750
	ctx.lr = 0x8227B020;
	sub_82618750(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82618610
	ctx.lr = 0x8227B034;
	sub_82618610(ctx, base);
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,5628(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 5628);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,5632(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5632);
	// addi r5,r1,232
	ctx.r5.s64 = ctx.r1.s64 + 232;
	// sth r9,232(r1)
	PPC_STORE_U16(ctx.r1.u32 + 232, ctx.r9.u16);
	// bl 0x8227a808
	ctx.lr = 0x8227B054;
	sub_8227A808(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_8227B06C"))) PPC_WEAK_FUNC(sub_8227B06C);
PPC_FUNC_IMPL(__imp__sub_8227B06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B070"))) PPC_WEAK_FUNC(sub_8227B070);
PPC_FUNC_IMPL(__imp__sub_8227B070) {
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
	ctx.lr = 0x8227B078;
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
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227B0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b0d8
	if (cr6.eq) goto loc_8227B0D8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8227a890
	ctx.lr = 0x8227B0D0;
	sub_8227A890(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B0D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B0E4"))) PPC_WEAK_FUNC(sub_8227B0E4);
PPC_FUNC_IMPL(__imp__sub_8227B0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B0E8"))) PPC_WEAK_FUNC(sub_8227B0E8);
PPC_FUNC_IMPL(__imp__sub_8227B0E8) {
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
	ctx.lr = 0x8227B0F0;
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
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227B118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b150
	if (cr6.eq) goto loc_8227B150;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8227a910
	ctx.lr = 0x8227B148;
	sub_8227A910(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B150:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B15C"))) PPC_WEAK_FUNC(sub_8227B15C);
PPC_FUNC_IMPL(__imp__sub_8227B15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B160"))) PPC_WEAK_FUNC(sub_8227B160);
PPC_FUNC_IMPL(__imp__sub_8227B160) {
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
	ctx.lr = 0x8227B168;
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
	ctx.lr = 0x8227B190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b1c4
	if (cr6.eq) goto loc_8227B1C4;
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
	// beq cr6,0x8227b1bc
	if (cr6.eq) goto loc_8227B1BC;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227b1c4
	if (!cr6.eq) goto loc_8227B1C4;
loc_8227B1BC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227b1c8
	goto loc_8227B1C8;
loc_8227B1C4:
	// li r11,0
	r11.s64 = 0;
loc_8227B1C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b204
	if (cr6.eq) goto loc_8227B204;
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
	// bl 0x8227a990
	ctx.lr = 0x8227B1FC;
	sub_8227A990(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B204:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B210"))) PPC_WEAK_FUNC(sub_8227B210);
PPC_FUNC_IMPL(__imp__sub_8227B210) {
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
	ctx.lr = 0x8227B218;
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
	ctx.lr = 0x8227B240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b274
	if (cr6.eq) goto loc_8227B274;
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
	// beq cr6,0x8227b26c
	if (cr6.eq) goto loc_8227B26C;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227b274
	if (!cr6.eq) goto loc_8227B274;
loc_8227B26C:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227b278
	goto loc_8227B278;
loc_8227B274:
	// li r11,0
	r11.s64 = 0;
loc_8227B278:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b2b4
	if (cr6.eq) goto loc_8227B2B4;
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
	// bl 0x8227aa10
	ctx.lr = 0x8227B2AC;
	sub_8227AA10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B2B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B2C0"))) PPC_WEAK_FUNC(sub_8227B2C0);
PPC_FUNC_IMPL(__imp__sub_8227B2C0) {
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
	ctx.lr = 0x8227B2C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8227B2E4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227B2FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b330
	if (cr6.eq) goto loc_8227B330;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227b328
	if (cr6.eq) goto loc_8227B328;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227b330
	if (!cr6.eq) goto loc_8227B330;
loc_8227B328:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227b334
	goto loc_8227B334;
loc_8227B330:
	// li r11,0
	r11.s64 = 0;
loc_8227B334:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b3b8
	if (cr6.eq) goto loc_8227B3B8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8227b3a8
	if (cr6.lt) goto loc_8227B3A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227B368;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227b38c
	if (!cr6.eq) goto loc_8227B38C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227B380;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b3a8
	if (cr6.eq) goto loc_8227B3A8;
loc_8227B38C:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8227a148
	ctx.lr = 0x8227B3A4;
	sub_8227A148(ctx, base);
	// b 0x8227b3ac
	goto loc_8227B3AC;
loc_8227B3A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227B3AC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8227B3B8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227b2e4
	if (cr6.lt) goto loc_8227B2E4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

