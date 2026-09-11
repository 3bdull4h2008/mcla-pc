#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821D8658"))) PPC_WEAK_FUNC(sub_821D8658);
PPC_FUNC_IMPL(__imp__sub_821D8658) {
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
	// li r11,-4
	r11.s64 = -4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
loc_821D867C:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be6a8
	ctx.lr = 0x821D868C;
	sub_821BE6A8(ctx, base);
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,65532
	cr6.compare<uint32_t>(ctx.r10.u32, 65532, xer);
	// bne cr6,0x821d86a4
	if (!cr6.eq) goto loc_821D86A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d85d8
	ctx.lr = 0x821D86A0;
	sub_821D85D8(ctx, base);
	// b 0x821d86a8
	goto loc_821D86A8;
loc_821D86A4:
	// li r30,1
	r30.s64 = 1;
loc_821D86A8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d867c
	if (cr6.eq) goto loc_821D867C;
	// lhz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_821D86D0"))) PPC_WEAK_FUNC(sub_821D86D0);
PPC_FUNC_IMPL(__imp__sub_821D86D0) {
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
	// bl 0x821d82c8
	ctx.lr = 0x821D86F0;
	sub_821D82C8(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821D86F4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821d86f4
	if (!cr6.eq) goto loc_821D86F4;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,-4
	ctx.r10.s64 = -4;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be780
	ctx.lr = 0x821D8728;
	sub_821BE780(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be7e8
	ctx.lr = 0x821D8738;
	sub_821BE7E8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be3d8
	ctx.lr = 0x821D8748;
	sub_821BE3D8(ctx, base);
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

__attribute__((alias("__imp__sub_821D8760"))) PPC_WEAK_FUNC(sub_821D8760);
PPC_FUNC_IMPL(__imp__sub_821D8760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// addi r8,r10,23332
	ctx.r8.s64 = ctx.r10.s64 + 23332;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r9,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r9.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// sth r11,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, r11.u16);
	// sth r11,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, r11.u16);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stb r11,88(r3)
	PPC_STORE_U8(ctx.r3.u32 + 88, r11.u8);
	// stb r11,89(r3)
	PPC_STORE_U8(ctx.r3.u32 + 89, r11.u8);
	// stb r11,90(r3)
	PPC_STORE_U8(ctx.r3.u32 + 90, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D87BC"))) PPC_WEAK_FUNC(sub_821D87BC);
PPC_FUNC_IMPL(__imp__sub_821D87BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D87C0"))) PPC_WEAK_FUNC(sub_821D87C0);
PPC_FUNC_IMPL(__imp__sub_821D87C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r9,31
	ctx.r3.u64 = ctx.r9.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D87D4"))) PPC_WEAK_FUNC(sub_821D87D4);
PPC_FUNC_IMPL(__imp__sub_821D87D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D87D8"))) PPC_WEAK_FUNC(sub_821D87D8);
PPC_FUNC_IMPL(__imp__sub_821D87D8) {
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
	ctx.lr = 0x821D87E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r28,0
	r28.s64 = 0;
	// addi r9,r11,23332
	ctx.r9.s64 = r11.s64 + 23332;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 80);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821d882c
	if (cr6.eq) goto loc_821D882C;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_821D880C:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82130588
	ctx.lr = 0x821D8818;
	sub_82130588(ctx, base);
	// lhz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 80);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x821d880c
	if (cr6.lt) goto loc_821D880C;
loc_821D882C:
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r31,r30,76
	r31.s64 = r30.s64 + 76;
	// bl 0x82130588
	ctx.lr = 0x821D8838;
	sub_82130588(ctx, base);
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// stw r28,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r28.u32);
	// sth r28,80(r30)
	PPC_STORE_U16(r30.u32 + 80, r28.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r28,82(r30)
	PPC_STORE_U16(r30.u32 + 82, r28.u16);
	// beq cr6,0x821d8858
	if (cr6.eq) goto loc_821D8858;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821D8858;
	sub_82130588(ctx, base);
loc_821D8858:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e45a0
	ctx.lr = 0x821D8860;
	sub_821E45A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821D8868"))) PPC_WEAK_FUNC(sub_821D8868);
PPC_FUNC_IMPL(__imp__sub_821D8868) {
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
	ctx.lr = 0x821D8870;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x821d8658
	ctx.lr = 0x821D888C;
	sub_821D8658(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r3.u16);
	// cmplwi cr6,r11,65534
	cr6.compare<uint32_t>(r11.u32, 65534, xer);
	// bne cr6,0x821d88c0
	if (!cr6.eq) goto loc_821D88C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be710
	ctx.lr = 0x821D88AC;
	sub_821BE710(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// clrlwi r9,r11,4
	ctx.r9.u64 = r11.u32 & 0xFFFFFFF;
	// sth r10,0(r29)
	PPC_STORE_U16(r29.u32 + 0, ctx.r10.u16);
	// b 0x821d88d0
	goto loc_821D88D0;
loc_821D88C0:
	// rlwinm r11,r3,20,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 20) & 0xF;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// clrlwi r9,r10,20
	ctx.r9.u64 = ctx.r10.u32 & 0xFFF;
loc_821D88D0:
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bne cr6,0x821d88f0
	if (!cr6.eq) goto loc_821D88F0;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_821D88F0:
	// lwz r30,64(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821d8900
	if (!cr6.eq) goto loc_821D8900;
	// addi r30,r31,76
	r30.s64 = r31.s64 + 76;
loc_821D8900:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x821d8960
	if (!cr6.eq) goto loc_821D8960;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262e420
	ctx.lr = 0x821D891C;
	sub_8262E420(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be6a8
	ctx.lr = 0x821D8930;
	sub_821BE6A8(ctx, base);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x821D893C;
	sub_82130528(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// bl 0x821be250
	ctx.lr = 0x821D8950;
	sub_821BE250(ctx, base);
	// lhz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stbx r9,r6,r7
	PPC_STORE_U8(ctx.r6.u32 + ctx.r7.u32, ctx.r9.u8);
loc_821D8960:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821D897C"))) PPC_WEAK_FUNC(sub_821D897C);
PPC_FUNC_IMPL(__imp__sub_821D897C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D8980"))) PPC_WEAK_FUNC(sub_821D8980);
PPC_FUNC_IMPL(__imp__sub_821D8980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x821D8988;
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,86
	ctx.r4.s64 = r31.s64 + 86;
	// stwu r11,-1104(r1)
	ea = -1104 + ctx.r1.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x821be6a8
	ctx.lr = 0x821D89B4;
	sub_821BE6A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// bl 0x821be6a8
	ctx.lr = 0x821D89C4;
	sub_821BE6A8(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// lhz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 84);
	// lhz r4,86(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// bl 0x821d4100
	ctx.lr = 0x821D89D4;
	sub_821D4100(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x821d41d0
	ctx.lr = 0x821D89E0;
	sub_821D41D0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,82
	ctx.r4.s64 = r31.s64 + 82;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821be6a8
	ctx.lr = 0x821D89F0;
	sub_821BE6A8(ctx, base);
	// lhz r7,82(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r24,r25
	r24.u64 = r25.u64;
	// beq cr6,0x821d8ba0
	if (cr6.eq) goto loc_821D8BA0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r26,r11,-13292
	r26.s64 = r11.s64 + -13292;
loc_821D8A0C:
	// addi r7,r31,92
	ctx.r7.s64 = r31.s64 + 92;
	// addi r6,r31,104
	ctx.r6.s64 = r31.s64 + 104;
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// addi r4,r31,90
	ctx.r4.s64 = r31.s64 + 90;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d8868
	ctx.lr = 0x821D8A24;
	sub_821D8868(ctx, base);
	// lhz r11,88(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 88);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x821d8b90
	if (cr6.gt) goto loc_821D8B90;
	// lwz r29,92(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-30128
	r12.s64 = r12.s64 + -30128;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821D8AF8;
	case 1:
		goto loc_821D8B28;
	case 2:
		goto loc_821D8B48;
	case 3:
		goto loc_821D8B64;
	case 4:
		goto loc_821D8B90;
	case 5:
		goto loc_821D8A68;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-29960(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29960);
	// lwz r16,-29912(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29912);
	// lwz r16,-29880(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29880);
	// lwz r16,-29852(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29852);
	// lwz r16,-29808(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29808);
	// lwz r16,-30104(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -30104);
loc_821D8A68:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// bl 0x821be6a8
	ctx.lr = 0x821D8A78;
	sub_821BE6A8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lhz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// bl 0x821be250
	ctx.lr = 0x821D8A88;
	sub_821BE250(ctx, base);
	// lhz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r29,92(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stbx r25,r9,r27
	PPC_STORE_U8(ctx.r9.u32 + r27.u32, r25.u8);
	// lwz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// bl 0x821c7000
	ctx.lr = 0x821D8AB4;
	sub_821C7000(ctx, base);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821D8ABC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821d8ae0
	if (cr6.eq) goto loc_821D8AE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821d8abc
	if (cr6.eq) goto loc_821D8ABC;
loc_821D8AE0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821d8b90
	if (!cr6.eq) goto loc_821D8B90;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e45e8
	ctx.lr = 0x821D8AF0;
	sub_821E45E8(ctx, base);
	// stw r3,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r3.u32);
	// b 0x821d8b90
	goto loc_821D8B90;
loc_821D8AF8:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// bl 0x821be710
	ctx.lr = 0x821D8B08;
	sub_821BE710(ctx, base);
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c70c8
	ctx.lr = 0x821D8B24;
	sub_821C70C8(ctx, base);
	// b 0x821d8b90
	goto loc_821D8B90;
loc_821D8B28:
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c7068
	ctx.lr = 0x821D8B44;
	sub_821C7068(ctx, base);
	// b 0x821d8b90
	goto loc_821D8B90;
loc_821D8B48:
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c7068
	ctx.lr = 0x821D8B64;
	sub_821C7068(ctx, base);
loc_821D8B64:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r31,100
	ctx.r4.s64 = r31.s64 + 100;
	// bl 0x821be710
	ctx.lr = 0x821D8B74;
	sub_821BE710(ctx, base);
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f1,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c7128
	ctx.lr = 0x821D8B90;
	sub_821C7128(ctx, base);
loc_821D8B90:
	// lhz r10,82(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpw cr6,r24,r10
	cr6.compare<int32_t>(r24.s32, ctx.r10.s32, xer);
	// blt cr6,0x821d8a0c
	if (cr6.lt) goto loc_821D8A0C;
loc_821D8BA0:
	// lbz r11,68(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d8bc0
	if (!cr6.eq) goto loc_821D8BC0;
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// ble cr6,0x821d8bc0
	if (!cr6.gt) goto loc_821D8BC0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c7cc0
	ctx.lr = 0x821D8BC0;
	sub_821C7CC0(ctx, base);
loc_821D8BC0:
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821D8BC8"))) PPC_WEAK_FUNC(sub_821D8BC8);
PPC_FUNC_IMPL(__imp__sub_821D8BC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r29{};
	PPCRegister r31{};
	PPCRegister temp{};
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
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x821d8c20
	if (cr6.gt) goto loc_821D8C20;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-29696
	r12.s64 = r12.s64 + -29696;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821D8C18;
	case 1:
		goto loc_821D8C38;
	case 2:
		goto loc_821D8C78;
	case 3:
		goto loc_821D8CA8;
	case 4:
		goto loc_821D8CD8;
	case 5:
		goto loc_821D8D18;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-29672(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29672);
	// lwz r16,-29640(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29640);
	// lwz r16,-29576(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29576);
	// lwz r16,-29528(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29528);
	// lwz r16,-29480(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29480);
	// lwz r16,-29416(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -29416);
loc_821D8C18:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821d8980
	ctx.lr = 0x821D8C20;
	sub_821D8980(ctx, base);
loc_821D8C20:
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
loc_821D8C38:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be710
	ctx.lr = 0x821D8C48;
	sub_821BE710(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c70c8
	ctx.lr = 0x821D8C60;
	sub_821C70C8(ctx, base);
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
loc_821D8C78:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7068
	ctx.lr = 0x821D8C90;
	sub_821C7068(ctx, base);
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
loc_821D8CA8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7068
	ctx.lr = 0x821D8CC0;
	sub_821C7068(ctx, base);
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
loc_821D8CD8:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821be710
	ctx.lr = 0x821D8CE8;
	sub_821BE710(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7128
	ctx.lr = 0x821D8D00;
	sub_821C7128(ctx, base);
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
loc_821D8D18:
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x821be710
	ctx.lr = 0x821D8D28;
	sub_821BE710(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r11,7760
	ctx.r4.s64 = r11.s64 + 7760;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7128
	ctx.lr = 0x821D8D40;
	sub_821C7128(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r10,7756
	ctx.r4.s64 = ctx.r10.s64 + 7756;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7128
	ctx.lr = 0x821D8D58;
	sub_821C7128(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r9,7752
	ctx.r4.s64 = ctx.r9.s64 + 7752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7128
	ctx.lr = 0x821D8D70;
	sub_821C7128(ctx, base);
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
}

__attribute__((alias("__imp__sub_821D8D88"))) PPC_WEAK_FUNC(sub_821D8D88);
PPC_FUNC_IMPL(__imp__sub_821D8D88) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821d8868
	ctx.lr = 0x821D8DB8;
	sub_821D8868(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c6a20
	ctx.lr = 0x821D8DD0;
	sub_821C6A20(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// bl 0x821d8bc8
	ctx.lr = 0x821D8DE0;
	sub_821D8BC8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r3,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r3.u8);
	// stb r9,90(r31)
	PPC_STORE_U8(r31.u32 + 90, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_821D8E04"))) PPC_WEAK_FUNC(sub_821D8E04);
PPC_FUNC_IMPL(__imp__sub_821D8E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D8E08"))) PPC_WEAK_FUNC(sub_821D8E08);
PPC_FUNC_IMPL(__imp__sub_821D8E08) {
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
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d8e54
	if (!cr6.eq) goto loc_821D8E54;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bl 0x821d8868
	ctx.lr = 0x821D8E3C;
	sub_821D8868(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r11.u8);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stb r11,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r11.u8);
	// stb r11,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r11.u8);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
loc_821D8E54:
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

__attribute__((alias("__imp__sub_821D8E68"))) PPC_WEAK_FUNC(sub_821D8E68);
PPC_FUNC_IMPL(__imp__sub_821D8E68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x821D8E70;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x821d8e90
	if (!cr6.eq) goto loc_821D8E90;
	// lwz r28,72(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 72);
loc_821D8E90:
	// lbz r11,89(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 89);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d8ecc
	if (!cr6.eq) goto loc_821D8ECC;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d8868
	ctx.lr = 0x821D8EB4;
	sub_821D8868(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stb r11,89(r30)
	PPC_STORE_U8(r30.u32 + 89, r11.u8);
	// addi r4,r30,84
	ctx.r4.s64 = r30.s64 + 84;
	// bl 0x821be710
	ctx.lr = 0x821D8ECC;
	sub_821BE710(ctx, base);
loc_821D8ECC:
	// lwz r11,84(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// addi r26,r30,84
	r26.s64 = r30.s64 + 84;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// blt cr6,0x821d8ee8
	if (cr6.lt) goto loc_821D8EE8;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_821D8EE8:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r28,11
	cr6.compare<uint32_t>(r28.u32, 11, xer);
	// bgt cr6,0x821d9014
	if (cr6.gt) goto loc_821D9014;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-28916
	r12.s64 = r12.s64 + -28916;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r28.u64) {
	case 0:
		goto loc_821D8F3C;
	case 1:
		goto loc_821D8F50;
	case 2:
		goto loc_821D8F9C;
	case 3:
		goto loc_821D8F3C;
	case 4:
		goto loc_821D8F50;
	case 5:
		goto loc_821D9004;
	case 6:
		goto loc_821D8F3C;
	case 7:
		goto loc_821D8FF0;
	case 8:
		goto loc_821D9004;
	case 9:
		goto loc_821D9004;
	case 10:
		goto loc_821D9004;
	case 11:
		goto loc_821D9004;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-28868(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28868);
	// lwz r16,-28848(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28848);
	// lwz r16,-28772(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28772);
	// lwz r16,-28868(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28868);
	// lwz r16,-28848(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28848);
	// lwz r16,-28668(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28668);
	// lwz r16,-28868(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28868);
	// lwz r16,-28688(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28688);
	// lwz r16,-28668(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28668);
	// lwz r16,-28668(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28668);
	// lwz r16,-28668(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28668);
	// lwz r16,-28668(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -28668);
loc_821D8F3C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x821D8F4C;
	sub_821BE250(ctx, base);
	// b 0x821d9014
	goto loc_821D9014;
loc_821D8F50:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// blt cr6,0x821d8f6c
	if (cr6.lt) goto loc_821D8F6C;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_821D8F6C:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x821D8F80;
	sub_821BE250(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821d9014
	if (!cr6.eq) goto loc_821D9014;
	// li r11,0
	r11.s64 = 0;
	// stbx r11,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x821d9014
	goto loc_821D9014;
loc_821D8F9C:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r11,r27,-2
	r11.s64 = r27.s64 + -2;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// blt cr6,0x821d8fb8
	if (cr6.lt) goto loc_821D8FB8;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_821D8FB8:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r5,r31,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x821be6a8
	ctx.lr = 0x821D8FCC;
	sub_821BE6A8(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821d9014
	if (!cr6.eq) goto loc_821D9014;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stbx r10,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, ctx.r10.u8);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// stbx r10,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r10.u8);
	// b 0x821d9014
	goto loc_821D9014;
loc_821D8FF0:
	// rlwinm r5,r31,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821be6a8
	ctx.lr = 0x821D9000;
	sub_821BE6A8(ctx, base);
	// b 0x821d9014
	goto loc_821D9014;
loc_821D9004:
	// rlwinm r5,r31,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821be710
	ctx.lr = 0x821D9014;
	sub_821BE710(ctx, base);
loc_821D9014:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r10,r31,r11
	ctx.r10.s64 = r11.s64 - r31.s64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821D902C"))) PPC_WEAK_FUNC(sub_821D902C);
PPC_FUNC_IMPL(__imp__sub_821D902C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D9030"))) PPC_WEAK_FUNC(sub_821D9030);
PPC_FUNC_IMPL(__imp__sub_821D9030) {
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
	// bl 0x821d87d8
	ctx.lr = 0x821D9050;
	sub_821D87D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d9068
	if (cr6.eq) goto loc_821D9068;
	// bl 0x82130588
	ctx.lr = 0x821D9064;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821D9068:
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

__attribute__((alias("__imp__sub_821D9080"))) PPC_WEAK_FUNC(sub_821D9080);
PPC_FUNC_IMPL(__imp__sub_821D9080) {
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
	ctx.lr = 0x821D9088;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d90ac
	if (!cr6.eq) goto loc_821D90AC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x821D90AC;
	sub_82608A98(ctx, base);
loc_821D90AC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x821D90B4;
	sub_821C9550(ctx, base);
	// lhz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// divwu r10,r3,r7
	ctx.r10.u32 = ctx.r3.u32 / ctx.r7.u32;
	// twllei r7,0
	// mullw r9,r10,r7
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// subf r31,r9,r3
	r31.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r8,r31,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821d9124
	if (cr6.eq) goto loc_821D9124;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_821D90E4:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_821D90EC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x821d9110
	if (cr6.eq) goto loc_821D9110;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821d90ec
	if (cr6.eq) goto loc_821D90EC;
loc_821D9110:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821d91b8
	if (cr6.eq) goto loc_821D91B8;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821d90e4
	if (!cr6.eq) goto loc_821D90E4;
loc_821D9124:
	// lhz r11,6(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r10,6(r28)
	PPC_STORE_U16(r28.u32 + 6, ctx.r10.u16);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bne cr6,0x821d916c
	if (!cr6.eq) goto loc_821D916C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9438
	ctx.lr = 0x821D9144;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821bed68
	ctx.lr = 0x821D9150;
	sub_821BED68(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x821D9158;
	sub_821C9550(ctx, base);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r31,r9,r3
	r31.s64 = ctx.r3.s64 - ctx.r9.s64;
loc_821D916C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821378b8
	ctx.lr = 0x821D9174;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// rlwinm r30,r31,2,0,29
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// lwzx r29,r30,r11
	r29.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x821D918C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821d91c4
	if (cr6.eq) goto loc_821D91C4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821378b8
	ctx.lr = 0x821D91A0;
	sub_821378B8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// b 0x821d91c8
	goto loc_821D91C8;
loc_821D91B8:
	// addi r3,r8,4
	ctx.r3.s64 = ctx.r8.s64 + 4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821D91C4:
	// li r11,0
	r11.s64 = 0;
loc_821D91C8:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stwx r11,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r11.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x821D91D8;
	sub_821D2AA0(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r11,r30,r9
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821D91EC"))) PPC_WEAK_FUNC(sub_821D91EC);
PPC_FUNC_IMPL(__imp__sub_821D91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D91F0"))) PPC_WEAK_FUNC(sub_821D91F0);
PPC_FUNC_IMPL(__imp__sub_821D91F0) {
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
	ctx.lr = 0x821D91F8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r30,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r30.u8);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// sth r30,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r30.u16);
	// sth r30,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r30.u16);
	// bl 0x821d40e8
	ctx.lr = 0x821D9220;
	sub_821D40E8(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// ori r29,r11,65532
	r29.u64 = r11.u64 | 65532;
	// ori r27,r10,65533
	r27.u64 = ctx.r10.u64 | 65533;
loc_821D9234:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d8868
	ctx.lr = 0x821D924C;
	sub_821D8868(ctx, base);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// blt cr6,0x821d927c
	if (cr6.lt) goto loc_821D927C;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x821d9270
	if (!cr6.gt) goto loc_821D9270;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x821d927c
	if (!cr6.eq) goto loc_821D927C;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// b 0x821d929c
	goto loc_821D929C;
loc_821D9270:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d85d8
	ctx.lr = 0x821D9278;
	sub_821D85D8(ctx, base);
	// b 0x821d929c
	goto loc_821D929C;
loc_821D927C:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lhz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d8bc8
	ctx.lr = 0x821D928C;
	sub_821D8BC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d929c
	if (!cr6.eq) goto loc_821D929C;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_821D929C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bgt cr6,0x821d9234
	if (cr6.gt) goto loc_821D9234;
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stb r30,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r30.u8);
	// stb r30,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r30.u8);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// bl 0x821c6f88
	ctx.lr = 0x821D92C0;
	sub_821C6F88(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821D92C8"))) PPC_WEAK_FUNC(sub_821D92C8);
PPC_FUNC_IMPL(__imp__sub_821D92C8) {
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
	ctx.lr = 0x821D92D0;
	// addi r31,r1,-224
	r31.s64 = ctx.r1.s64 + -224;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,0
	r24.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r23,r24
	r23.u64 = r24.u64;
	// mr r21,r24
	r21.u64 = r24.u64;
	// li r22,1
	r22.s64 = 1;
loc_821D92EC:
	// addi r7,r31,84
	ctx.r7.s64 = r31.s64 + 84;
	// addi r6,r31,92
	ctx.r6.s64 = r31.s64 + 92;
	// addi r5,r31,82
	ctx.r5.s64 = r31.s64 + 82;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d8868
	ctx.lr = 0x821D9304;
	sub_821D8868(ctx, base);
	// lhz r11,80(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// cmplwi cr6,r11,65532
	cr6.compare<uint32_t>(r11.u32, 65532, xer);
	// beq cr6,0x821d94b4
	if (cr6.eq) goto loc_821D94B4;
	// cmplwi cr6,r11,65533
	cr6.compare<uint32_t>(r11.u32, 65533, xer);
	// beq cr6,0x821d93e0
	if (cr6.eq) goto loc_821D93E0;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821d93bc
	if (cr6.eq) goto loc_821D93BC;
	// stw r24,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r24.u32);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// stb r24,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r24.u8);
	// stw r24,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r24.u32);
	// sth r24,108(r31)
	PPC_STORE_U16(r31.u32 + 108, r24.u16);
	// sth r24,110(r31)
	PPC_STORE_U16(r31.u32 + 110, r24.u16);
	// bl 0x821d40e8
	ctx.lr = 0x821D933C;
	sub_821D40E8(ctx, base);
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c6a20
	ctx.lr = 0x821D9354;
	sub_821C6A20(ctx, base);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r5,82(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// bl 0x821d8bc8
	ctx.lr = 0x821D9364;
	sub_821D8BC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821D9380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821d93ac
	if (cr6.eq) goto loc_821D93AC;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r30,28
	ctx.r3.s64 = r30.s64 + 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821D93A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x821c6f88
	ctx.lr = 0x821D93A8;
	sub_821C6F88(ctx, base);
	// b 0x821d94bc
	goto loc_821D94BC;
loc_821D93AC:
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// bl 0x821c6f88
	ctx.lr = 0x821D93B8;
	sub_821C6F88(ctx, base);
	// b 0x821d94bc
	goto loc_821D94BC;
loc_821D93BC:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r30,28
	ctx.r3.s64 = r30.s64 + 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821D93D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bgt 0x821d94bc
	if (cr0.gt) goto loc_821D94BC;
	// mr r21,r22
	r21.u64 = r22.u64;
	// b 0x821d94bc
	goto loc_821D94BC;
loc_821D93E0:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r27,r30,60
	r27.s64 = r30.s64 + 60;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x821D93F4;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// addi r28,r30,84
	r28.s64 = r30.s64 + 84;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// bl 0x821be710
	ctx.lr = 0x821D9414;
	sub_821BE710(ctx, base);
	// lwz r8,84(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// stb r22,89(r30)
	PPC_STORE_U8(r30.u32 + 89, r22.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ble cr6,0x821d94ac
	if (!cr6.gt) goto loc_821D94AC;
	// addi r25,r30,44
	r25.s64 = r30.s64 + 44;
loc_821D9428:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// ble cr6,0x821d9440
	if (!cr6.gt) goto loc_821D9440;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_821D9440:
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// blt cr6,0x821d945c
	if (cr6.lt) goto loc_821D945C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821D945C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821D947C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r7,12(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821D94A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bgt cr6,0x821d9428
	if (cr6.gt) goto loc_821D9428;
loc_821D94AC:
	// stb r24,89(r30)
	PPC_STORE_U8(r30.u32 + 89, r24.u8);
	// b 0x821d94bc
	goto loc_821D94BC;
loc_821D94B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d85d8
	ctx.lr = 0x821D94BC;
	sub_821D85D8(ctx, base);
loc_821D94BC:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d92ec
	if (cr6.eq) goto loc_821D92EC;
	// addi r1,r31,224
	ctx.r1.s64 = r31.s64 + 224;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821D94D0"))) PPC_WEAK_FUNC(sub_821D94D0);
PPC_FUNC_IMPL(__imp__sub_821D94D0) {
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
	ctx.lr = 0x821D94D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r30.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r28,r31,28
	r28.s64 = r31.s64 + 28;
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825edac0
	ctx.lr = 0x821D94FC;
	sub_825EDAC0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sth r27,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r27.u16);
	// beq cr6,0x821d9514
	if (cr6.eq) goto loc_821D9514;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x821d954c
	goto loc_821D954C;
loc_821D9514:
	// lhz r29,34(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 34);
	// mr r27,r30
	r27.u64 = r30.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821D9520:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821d9520
	if (!cr6.eq) goto loc_821D9520;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// bl 0x821d9080
	ctx.lr = 0x821D9548;
	sub_821D9080(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
loc_821D954C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r29,8192
	cr6.compare<uint32_t>(r29.u32, 8192, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bge cr6,0x821d9574
	if (!cr6.lt) goto loc_821D9574;
	// rlwinm r11,r26,12,4,19
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 12) & 0xFFFF000;
	// or r10,r11,r29
	ctx.r10.u64 = r11.u64 | r29.u64;
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
	// bl 0x821be780
	ctx.lr = 0x821D9570;
	sub_821BE780(ctx, base);
	// b 0x821d959c
	goto loc_821D959C;
loc_821D9574:
	// rlwinm r11,r26,28,0,3
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 28) & 0xF0000000;
	// li r10,-2
	ctx.r10.s64 = -2;
	// or r9,r11,r29
	ctx.r9.u64 = r11.u64 | r29.u64;
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x821be780
	ctx.lr = 0x821D958C;
	sub_821BE780(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be7e8
	ctx.lr = 0x821D959C;
	sub_821BE7E8(ctx, base);
loc_821D959C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821d95c4
	if (cr6.eq) goto loc_821D95C4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be780
	ctx.lr = 0x821D95B4;
	sub_821BE780(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// bl 0x821be3d8
	ctx.lr = 0x821D95C4;
	sub_821BE3D8(ctx, base);
loc_821D95C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821D95CC"))) PPC_WEAK_FUNC(sub_821D95CC);
PPC_FUNC_IMPL(__imp__sub_821D95CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D95D0"))) PPC_WEAK_FUNC(sub_821D95D0);
PPC_FUNC_IMPL(__imp__sub_821D95D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x821D95D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d82c8
	ctx.lr = 0x821D95E8;
	sub_821D82C8(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r25,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r25.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821d94d0
	ctx.lr = 0x821D9600;
	sub_821D94D0(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,16,22,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bl 0x821be780
	ctx.lr = 0x821D9620;
	sub_821BE780(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821be780
	ctx.lr = 0x821D9630;
	sub_821BE780(ctx, base);
	// lhz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// bl 0x821be780
	ctx.lr = 0x821D9648;
	sub_821BE780(ctx, base);
	// lhz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// mr r27,r25
	r27.u64 = r25.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821d97d4
	if (cr6.eq) goto loc_821D97D4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r28,r25
	r28.u64 = r25.u64;
	// addi r26,r11,-13292
	r26.s64 = r11.s64 + -13292;
loc_821D9664:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r31,r28,r11
	r31.u64 = r28.u64 + r11.u64;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x821d97c0
	if (cr6.gt) goto loc_821D97C0;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-26992
	r12.s64 = r12.s64 + -26992;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821D96A0;
	case 1:
		goto loc_821D9778;
	case 2:
		goto loc_821D9798;
	case 3:
		goto loc_821D974C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-26976(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -26976);
	// lwz r16,-26760(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -26760);
	// lwz r16,-26728(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -26728);
	// lwz r16,-26804(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -26804);
loc_821D96A0:
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d94d0
	ctx.lr = 0x821D96B0;
	sub_821D94D0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// sth r25,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r25.u16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821d96e0
	if (cr6.eq) goto loc_821D96E0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_821D96C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821d96c4
	if (!cr6.eq) goto loc_821D96C4;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
loc_821D96E0:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821be780
	ctx.lr = 0x821D96F0;
	sub_821BE780(ctx, base);
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821d9708
	if (cr6.eq) goto loc_821D9708;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821be3d8
	ctx.lr = 0x821D9708;
	sub_821BE3D8(ctx, base);
loc_821D9708:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_821D9710:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821d9734
	if (cr6.eq) goto loc_821D9734;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821d9710
	if (cr6.eq) goto loc_821D9710;
loc_821D9734:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821d97c0
	if (!cr6.eq) goto loc_821D97C0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821e45e8
	ctx.lr = 0x821D9744;
	sub_821E45E8(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// b 0x821d97c0
	goto loc_821D97C0;
loc_821D974C:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d976c
	if (cr6.eq) goto loc_821D976C;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821d94d0
	ctx.lr = 0x821D9768;
	sub_821D94D0(ctx, base);
	// b 0x821d97c0
	goto loc_821D97C0;
loc_821D976C:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821d94d0
	ctx.lr = 0x821D9774;
	sub_821D94D0(ctx, base);
	// b 0x821d97c0
	goto loc_821D97C0;
loc_821D9778:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d94d0
	ctx.lr = 0x821D9788;
	sub_821D94D0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// b 0x821d97b4
	goto loc_821D97B4;
loc_821D9798:
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d94d0
	ctx.lr = 0x821D97A8;
	sub_821D94D0(ctx, base);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
loc_821D97B4:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821be7e8
	ctx.lr = 0x821D97C0;
	sub_821BE7E8(ctx, base);
loc_821D97C0:
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x821d9664
	if (cr6.lt) goto loc_821D9664;
loc_821D97D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821D97DC"))) PPC_WEAK_FUNC(sub_821D97DC);
PPC_FUNC_IMPL(__imp__sub_821D97DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D97E0"))) PPC_WEAK_FUNC(sub_821D97E0);
PPC_FUNC_IMPL(__imp__sub_821D97E0) {
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
	ctx.lr = 0x821D97E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821d82c8
	ctx.lr = 0x821D97F8;
	sub_821D82C8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x821d98d8
	if (!cr6.eq) goto loc_821D98D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,7744
	ctx.r4.s64 = r11.s64 + 7744;
	// bl 0x821c7490
	ctx.lr = 0x821D981C;
	sub_821C7490(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821d9998
	if (cr6.eq) goto loc_821D9998;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x821d98a8
	if (cr6.eq) goto loc_821D98A8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x821d9878
	if (cr6.eq) goto loc_821D9878;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x821d9998
	if (!cr6.eq) goto loc_821D9998;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d9868
	if (cr6.eq) goto loc_821D9868;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821d94d0
	ctx.lr = 0x821D9860;
	sub_821D94D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_821D9868:
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821d94d0
	ctx.lr = 0x821D9870;
	sub_821D94D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_821D9878:
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d94d0
	ctx.lr = 0x821D9888;
	sub_821D94D0(ctx, base);
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be7e8
	ctx.lr = 0x821D98A0;
	sub_821BE7E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_821D98A8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d94d0
	ctx.lr = 0x821D98B8;
	sub_821D94D0(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x821be7e8
	ctx.lr = 0x821D98D0;
	sub_821BE7E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_821D98D8:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x821d9998
	if (!cr6.eq) goto loc_821D9998;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,7760
	ctx.r4.s64 = r11.s64 + 7760;
	// bl 0x821c7490
	ctx.lr = 0x821D98F0;
	sub_821C7490(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821d9998
	if (cr6.eq) goto loc_821D9998;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,7756
	ctx.r4.s64 = r11.s64 + 7756;
	// bl 0x821c7490
	ctx.lr = 0x821D990C;
	sub_821C7490(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821d9998
	if (cr6.eq) goto loc_821D9998;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,7752
	ctx.r4.s64 = r11.s64 + 7752;
	// bl 0x821c7490
	ctx.lr = 0x821D9928;
	sub_821C7490(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d9998
	if (cr6.eq) goto loc_821D9998;
	// lbz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 8);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821d9998
	if (!cr6.eq) goto loc_821D9998;
	// lbz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821d9998
	if (!cr6.eq) goto loc_821D9998;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821d9998
	if (!cr6.eq) goto loc_821D9998;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r4,5
	ctx.r4.s64 = 5;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x821d94d0
	ctx.lr = 0x821D9980;
	sub_821D94D0(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821be7e8
	ctx.lr = 0x821D9990;
	sub_821BE7E8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_821D9998:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D99B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821D99C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821D99D0"))) PPC_WEAK_FUNC(sub_821D99D0);
PPC_FUNC_IMPL(__imp__sub_821D99D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,23372
	ctx.r9.s64 = ctx.r10.s64 + 23372;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stb r11,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D9A08"))) PPC_WEAK_FUNC(sub_821D9A08);
PPC_FUNC_IMPL(__imp__sub_821D9A08) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r10,r11,23372
	ctx.r10.s64 = r11.s64 + 23372;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8229d838
	ctx.lr = 0x821D9A38;
	sub_8229D838(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e45a0
	ctx.lr = 0x821D9A40;
	sub_821E45A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821d9a58
	if (cr6.eq) goto loc_821D9A58;
	// bl 0x82130588
	ctx.lr = 0x821D9A54;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821D9A58:
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

__attribute__((alias("__imp__sub_821D9A70"))) PPC_WEAK_FUNC(sub_821D9A70);
PPC_FUNC_IMPL(__imp__sub_821D9A70) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,1103(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1103);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D9A78"))) PPC_WEAK_FUNC(sub_821D9A78);
PPC_FUNC_IMPL(__imp__sub_821D9A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D9A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D9AA8"))) PPC_WEAK_FUNC(sub_821D9AA8);
PPC_FUNC_IMPL(__imp__sub_821D9AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,23780
	ctx.r9.s64 = ctx.r10.s64 + 23780;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stb r8,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r8.u8);
	// stw r7,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D9AE8"))) PPC_WEAK_FUNC(sub_821D9AE8);
PPC_FUNC_IMPL(__imp__sub_821D9AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// extsb r11,r4
	r11.s64 = ctx.r4.s8;
	// addi r11,r11,-34
	r11.s64 = r11.s64 + -34;
	// cmplwi cr6,r11,28
	cr6.compare<uint32_t>(r11.u32, 28, xer);
	// bgt cr6,0x821d9c40
	if (cr6.gt) {
		sub_821D9C40(ctx, base);
		return;
	}
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-25840
	r12.s64 = r12.s64 + -25840;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x821D9C00
		return;
	case 1:
		// ERROR: 0x821D9C40
		return;
	case 2:
		// ERROR: 0x821D9C40
		return;
	case 3:
		// ERROR: 0x821D9C40
		return;
	case 4:
		// ERROR: 0x821D9BAC
		return;
	case 5:
		// ERROR: 0x821D9BC0
		return;
	case 6:
		// ERROR: 0x821D9C40
		return;
	case 7:
		// ERROR: 0x821D9C40
		return;
	case 8:
		// ERROR: 0x821D9C40
		return;
	case 9:
		// ERROR: 0x821D9C40
		return;
	case 10:
		// ERROR: 0x821D9C40
		return;
	case 11:
		// ERROR: 0x821D9C40
		return;
	case 12:
		// ERROR: 0x821D9C40
		return;
	case 13:
		// ERROR: 0x821D9C40
		return;
	case 14:
		// ERROR: 0x821D9C40
		return;
	case 15:
		// ERROR: 0x821D9C40
		return;
	case 16:
		// ERROR: 0x821D9C40
		return;
	case 17:
		// ERROR: 0x821D9C40
		return;
	case 18:
		// ERROR: 0x821D9C40
		return;
	case 19:
		// ERROR: 0x821D9C40
		return;
	case 20:
		// ERROR: 0x821D9C40
		return;
	case 21:
		// ERROR: 0x821D9C40
		return;
	case 22:
		// ERROR: 0x821D9C40
		return;
	case 23:
		// ERROR: 0x821D9C40
		return;
	case 24:
		// ERROR: 0x821D9C40
		return;
	case 25:
		// ERROR: 0x821D9C40
		return;
	case 26:
		// ERROR: 0x821D9B84
		return;
	case 27:
		// ERROR: 0x821D9C40
		return;
	case 28:
		// ERROR: 0x821D9B98
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_821D9B10"))) PPC_WEAK_FUNC(sub_821D9B10);
PPC_FUNC_IMPL(__imp__sub_821D9B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r16{};
	PPCRegister r29{};
	// lwz r16,-25600(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25600);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25684(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25684);
	// lwz r16,-25664(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25664);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25724(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25724);
	// lwz r16,-25536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25536);
	// lwz r16,-25704(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -25704);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,23840
	ctx.r4.s64 = r11.s64 + 23840;
	// b 0x821be3d8
	sub_821BE3D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9B98"))) PPC_WEAK_FUNC(sub_821D9B98);
PPC_FUNC_IMPL(__imp__sub_821D9B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,23832
	ctx.r4.s64 = r11.s64 + 23832;
	// b 0x821be3d8
	sub_821BE3D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9BAC"))) PPC_WEAK_FUNC(sub_821D9BAC);
PPC_FUNC_IMPL(__imp__sub_821D9BAC) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,23824
	ctx.r4.s64 = r11.s64 + 23824;
	// b 0x821be3d8
	sub_821BE3D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9BC0"))) PPC_WEAK_FUNC(sub_821D9BC0);
PPC_FUNC_IMPL(__imp__sub_821D9BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d9be0
	if (cr6.eq) goto loc_821D9BE0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,23816
	ctx.r4.s64 = r11.s64 + 23816;
	// b 0x821be3d8
	sub_821BE3D8(ctx, base);
	return;
loc_821D9BE0:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9bfc
	if (!cr6.eq) goto loc_821D9BFC;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x821d9c60
	if (cr6.lt) {
		// ERROR 821D9C60
		return;
	}
loc_821D9BFC:
	// b 0x821be528
	sub_821BE528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9C00"))) PPC_WEAK_FUNC(sub_821D9C00);
PPC_FUNC_IMPL(__imp__sub_821D9C00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821d9c20
	if (cr6.eq) goto loc_821D9C20;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,23808
	ctx.r4.s64 = r11.s64 + 23808;
	// b 0x821be3d8
	sub_821BE3D8(ctx, base);
	return;
loc_821D9C20:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9c3c
	if (!cr6.eq) goto loc_821D9C3C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x821d9c60
	if (cr6.lt) {
		// ERROR 821D9C60
		return;
	}
loc_821D9C3C:
	// b 0x821be528
	sub_821BE528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9C40"))) PPC_WEAK_FUNC(sub_821D9C40);
PPC_FUNC_IMPL(__imp__sub_821D9C40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9c78
	if (!cr6.eq) goto loc_821D9C78;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9c78
	if (!cr6.lt) goto loc_821D9C78;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// blr 
	return;
loc_821D9C78:
	// b 0x821be528
	sub_821BE528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D9C7C"))) PPC_WEAK_FUNC(sub_821D9C7C);
PPC_FUNC_IMPL(__imp__sub_821D9C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D9C80"))) PPC_WEAK_FUNC(sub_821D9C80);
PPC_FUNC_IMPL(__imp__sub_821D9C80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x821D9C88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821d9ce0
	if (cr6.eq) goto loc_821D9CE0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bge cr6,0x821d9cb0
	if (!cr6.lt) goto loc_821D9CB0;
	// li r30,-1
	r30.s64 = -1;
loc_821D9CB0:
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821d9ce0
	if (cr6.eq) goto loc_821D9CE0;
loc_821D9CBC:
	// lbzx r4,r31,r27
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + r27.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821d9ce0
	if (cr6.eq) goto loc_821D9CE0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d9ae8
	ctx.lr = 0x821D9CD4;
	sub_821D9AE8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x821d9cbc
	if (cr6.lt) goto loc_821D9CBC;
loc_821D9CE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821D9CE8"))) PPC_WEAK_FUNC(sub_821D9CE8);
PPC_FUNC_IMPL(__imp__sub_821D9CE8) {
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
	ctx.lr = 0x821D9CF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bge cr6,0x821d9d08
	if (!cr6.lt) goto loc_821D9D08;
	// li r28,-1
	r28.s64 = -1;
loc_821D9D08:
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821d9ebc
	if (cr6.eq) goto loc_821D9EBC;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821D9D18:
	// lhz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821d9ebc
	if (cr6.eq) goto loc_821D9EBC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821e49e0
	ctx.lr = 0x821D9D2C;
	sub_821E49E0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x821d9d48
	if (!cr6.eq) goto loc_821D9D48;
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d9ae8
	ctx.lr = 0x821D9D44;
	sub_821D9AE8(ctx, base);
	// b 0x821d9eac
	goto loc_821D9EAC;
loc_821D9D48:
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x821d9dd8
	if (!cr6.eq) goto loc_821D9DD8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9d8c
	if (!cr6.eq) goto loc_821D9D8C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9d8c
	if (!cr6.lt) goto loc_821D9D8C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821d9d94
	goto loc_821D9D94;
loc_821D9D8C:
	// lbz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821be528
	ctx.lr = 0x821D9D94;
	sub_821BE528(ctx, base);
loc_821D9D94:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9dd0
	if (!cr6.eq) goto loc_821D9DD0;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9dd0
	if (!cr6.lt) goto loc_821D9DD0;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821d9eac
	goto loc_821D9EAC;
loc_821D9DD0:
	// lbz r4,81(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// b 0x821d9ea8
	goto loc_821D9EA8;
loc_821D9DD8:
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x821d9eac
	if (!cr6.eq) goto loc_821D9EAC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9e1c
	if (!cr6.eq) goto loc_821D9E1C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9e1c
	if (!cr6.lt) goto loc_821D9E1C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821d9e24
	goto loc_821D9E24;
loc_821D9E1C:
	// lbz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821be528
	ctx.lr = 0x821D9E24;
	sub_821BE528(ctx, base);
loc_821D9E24:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9e60
	if (!cr6.eq) goto loc_821D9E60;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9e60
	if (!cr6.lt) goto loc_821D9E60;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821d9e68
	goto loc_821D9E68;
loc_821D9E60:
	// lbz r4,81(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// bl 0x821be528
	ctx.lr = 0x821D9E68;
	sub_821BE528(ctx, base);
loc_821D9E68:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9ea4
	if (!cr6.eq) goto loc_821D9EA4;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9ea4
	if (!cr6.lt) goto loc_821D9EA4;
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821d9eac
	goto loc_821D9EAC;
loc_821D9EA4:
	// lbz r4,82(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
loc_821D9EA8:
	// bl 0x821be528
	ctx.lr = 0x821D9EAC;
	sub_821BE528(ctx, base);
loc_821D9EAC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// blt cr6,0x821d9d18
	if (cr6.lt) goto loc_821D9D18;
loc_821D9EBC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821D9EC4"))) PPC_WEAK_FUNC(sub_821D9EC4);
PPC_FUNC_IMPL(__imp__sub_821D9EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D9EC8"))) PPC_WEAK_FUNC(sub_821D9EC8);
PPC_FUNC_IMPL(__imp__sub_821D9EC8) {
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
	ctx.lr = 0x821D9ED0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r25,13
	r25.s64 = 13;
	// li r26,10
	r26.s64 = 10;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821d9f74
	if (!cr6.eq) goto loc_821D9F74;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9f2c
	if (!cr6.eq) goto loc_821D9F2C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9f2c
	if (!cr6.lt) goto loc_821D9F2C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r25,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r25.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821d9f34
	goto loc_821D9F34;
loc_821D9F2C:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821D9F34;
	sub_821BE528(ctx, base);
loc_821D9F34:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821d9f6c
	if (!cr6.eq) goto loc_821D9F6C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821d9f6c
	if (!cr6.lt) goto loc_821D9F6C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821d9f74
	goto loc_821D9F74;
loc_821D9F6C:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821D9F74;
	sub_821BE528(ctx, base);
loc_821D9F74:
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// mr r29,r28
	r29.u64 = r28.u64;
	// ble cr6,0x821da184
	if (!cr6.gt) goto loc_821DA184;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r30,r11,-30296
	r30.s64 = r11.s64 + -30296;
loc_821D9F8C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// lbzx r8,r29,r27
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + r27.u32);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// bne cr6,0x821da17c
	if (!cr6.eq) goto loc_821DA17C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rlwinm r10,r11,14,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da000
	if (!cr6.eq) goto loc_821DA000;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da000
	if (!cr6.lt) goto loc_821DA000;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da004
	goto loc_821DA004;
loc_821DA000:
	// bl 0x821be528
	ctx.lr = 0x821DA004;
	sub_821BE528(ctx, base);
loc_821DA004:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,20,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da048
	if (!cr6.eq) goto loc_821DA048;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da048
	if (!cr6.lt) goto loc_821DA048;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da04c
	goto loc_821DA04C;
loc_821DA048:
	// bl 0x821be528
	ctx.lr = 0x821DA04C;
	sub_821BE528(ctx, base);
loc_821DA04C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,26,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da090
	if (!cr6.eq) goto loc_821DA090;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da090
	if (!cr6.lt) goto loc_821DA090;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da094
	goto loc_821DA094;
loc_821DA090:
	// bl 0x821be528
	ctx.lr = 0x821DA094;
	sub_821BE528(ctx, base);
loc_821DA094:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da0d8
	if (!cr6.eq) goto loc_821DA0D8;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da0d8
	if (!cr6.lt) goto loc_821DA0D8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da0dc
	goto loc_821DA0DC;
loc_821DA0D8:
	// bl 0x821be528
	ctx.lr = 0x821DA0DC;
	sub_821BE528(ctx, base);
loc_821DA0DC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x821da17c
	if (!cr6.eq) goto loc_821DA17C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da130
	if (!cr6.eq) goto loc_821DA130;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da130
	if (!cr6.lt) goto loc_821DA130;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r25,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r25.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da138
	goto loc_821DA138;
loc_821DA130:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DA138;
	sub_821BE528(ctx, base);
loc_821DA138:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da170
	if (!cr6.eq) goto loc_821DA170;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da170
	if (!cr6.lt) goto loc_821DA170;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da178
	goto loc_821DA178;
loc_821DA170:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DA178;
	sub_821BE528(ctx, base);
loc_821DA178:
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
loc_821DA17C:
	// cmpw cr6,r29,r24
	cr6.compare<int32_t>(r29.s32, r24.s32, xer);
	// blt cr6,0x821d9f8c
	if (cr6.lt) goto loc_821D9F8C;
loc_821DA184:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821DA18C"))) PPC_WEAK_FUNC(sub_821DA18C);
PPC_FUNC_IMPL(__imp__sub_821DA18C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DA190"))) PPC_WEAK_FUNC(sub_821DA190);
PPC_FUNC_IMPL(__imp__sub_821DA190) {
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
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821da4a0
	if (cr6.lt) goto loc_821DA4A0;
	// beq cr6,0x821da2e4
	if (cr6.eq) goto loc_821DA2E4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x821da408
	if (!cr6.lt) goto loc_821DA408;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// addi r31,r11,-30296
	r31.s64 = r11.s64 + -30296;
	// rlwinm r8,r9,14,26,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 14) & 0x3F;
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lbzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + r31.u32);
	// bne cr6,0x821da214
	if (!cr6.eq) goto loc_821DA214;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da214
	if (!cr6.lt) goto loc_821DA214;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da218
	goto loc_821DA218;
loc_821DA214:
	// bl 0x821be528
	ctx.lr = 0x821DA218;
	sub_821BE528(ctx, base);
loc_821DA218:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,20,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da25c
	if (!cr6.eq) goto loc_821DA25C;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da25c
	if (!cr6.lt) goto loc_821DA25C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da260
	goto loc_821DA260;
loc_821DA25C:
	// bl 0x821be528
	ctx.lr = 0x821DA260;
	sub_821BE528(ctx, base);
loc_821DA260:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,26,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da2a4
	if (!cr6.eq) goto loc_821DA2A4;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da2a4
	if (!cr6.lt) goto loc_821DA2A4;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da2a8
	goto loc_821DA2A8;
loc_821DA2A4:
	// bl 0x821be528
	ctx.lr = 0x821DA2A8;
	sub_821BE528(ctx, base);
loc_821DA2A8:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da400
	if (!cr6.eq) goto loc_821DA400;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da400
	if (!cr6.lt) goto loc_821DA400;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,61
	ctx.r9.s64 = 61;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821da408
	goto loc_821DA408;
loc_821DA2E4:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addi r31,r11,-30296
	r31.s64 = r11.s64 + -30296;
	// rlwinm r8,r9,14,26,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 14) & 0x3F;
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lbzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + r31.u32);
	// bne cr6,0x821da338
	if (!cr6.eq) goto loc_821DA338;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da338
	if (!cr6.lt) goto loc_821DA338;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da33c
	goto loc_821DA33C;
loc_821DA338:
	// bl 0x821be528
	ctx.lr = 0x821DA33C;
	sub_821BE528(ctx, base);
loc_821DA33C:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,20,26,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3F;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821da380
	if (!cr6.eq) goto loc_821DA380;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da380
	if (!cr6.lt) goto loc_821DA380;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da384
	goto loc_821DA384;
loc_821DA380:
	// bl 0x821be528
	ctx.lr = 0x821DA384;
	sub_821BE528(ctx, base);
loc_821DA384:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r31,61
	r31.s64 = 61;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da3c0
	if (!cr6.eq) goto loc_821DA3C0;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da3c0
	if (!cr6.lt) goto loc_821DA3C0;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r31,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r31.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da3c8
	goto loc_821DA3C8;
loc_821DA3C0:
	// li r4,61
	ctx.r4.s64 = 61;
	// bl 0x821be528
	ctx.lr = 0x821DA3C8;
	sub_821BE528(ctx, base);
loc_821DA3C8:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da400
	if (!cr6.eq) goto loc_821DA400;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da400
	if (!cr6.lt) goto loc_821DA400;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r31,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r31.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821da408
	goto loc_821DA408;
loc_821DA400:
	// li r4,61
	ctx.r4.s64 = 61;
	// bl 0x821be528
	ctx.lr = 0x821DA408;
	sub_821BE528(ctx, base);
loc_821DA408:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da444
	if (!cr6.eq) goto loc_821DA444;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da444
	if (!cr6.lt) goto loc_821DA444;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821da44c
	goto loc_821DA44C;
loc_821DA444:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DA44C;
	sub_821BE528(ctx, base);
loc_821DA44C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da488
	if (!cr6.eq) goto loc_821DA488;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da488
	if (!cr6.lt) goto loc_821DA488;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821da490
	goto loc_821DA490;
loc_821DA488:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DA490;
	sub_821BE528(ctx, base);
loc_821DA490:
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
loc_821DA4A0:
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

__attribute__((alias("__imp__sub_821DA4B8"))) PPC_WEAK_FUNC(sub_821DA4B8);
PPC_FUNC_IMPL(__imp__sub_821DA4B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,36(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r11,23848
	ctx.r4.s64 = r11.s64 + 23848;
	// b 0x821be860
	sub_821BE860(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821DA4D4"))) PPC_WEAK_FUNC(sub_821DA4D4);
PPC_FUNC_IMPL(__imp__sub_821DA4D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DA4D8"))) PPC_WEAK_FUNC(sub_821DA4D8);
PPC_FUNC_IMPL(__imp__sub_821DA4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r4,r11,23892
	ctx.r4.s64 = r11.s64 + 23892;
	// b 0x821be860
	sub_821BE860(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821DA4EC"))) PPC_WEAK_FUNC(sub_821DA4EC);
PPC_FUNC_IMPL(__imp__sub_821DA4EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DA4F0"))) PPC_WEAK_FUNC(sub_821DA4F0);
PPC_FUNC_IMPL(__imp__sub_821DA4F0) {
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
	ctx.lr = 0x821DA4F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x821da558
	if (!cr6.gt) goto loc_821DA558;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,9
	r30.s64 = 9;
loc_821DA510:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da544
	if (!cr6.eq) goto loc_821DA544;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da544
	if (!cr6.lt) goto loc_821DA544;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r30,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r30.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821da550
	goto loc_821DA550;
loc_821DA544:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA550;
	sub_821BE528(ctx, base);
loc_821DA550:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x821da510
	if (!cr0.eq) goto loc_821DA510;
loc_821DA558:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DA560"))) PPC_WEAK_FUNC(sub_821DA560);
PPC_FUNC_IMPL(__imp__sub_821DA560) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// beq cr6,0x821da5a8
	if (cr6.eq) goto loc_821DA5A8;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x821da63c
	if (!cr6.eq) goto loc_821DA63C;
	// bl 0x821da190
	ctx.lr = 0x821DA5A4;
	sub_821DA190(ctx, base);
	// b 0x821da63c
	goto loc_821DA63C;
loc_821DA5A8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da5e4
	if (!cr6.eq) goto loc_821DA5E4;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da5e4
	if (!cr6.lt) goto loc_821DA5E4;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821da5ec
	goto loc_821DA5EC;
loc_821DA5E4:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DA5EC;
	sub_821BE528(ctx, base);
loc_821DA5EC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da628
	if (!cr6.eq) goto loc_821DA628;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da628
	if (!cr6.lt) goto loc_821DA628;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821da630
	goto loc_821DA630;
loc_821DA628:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DA630;
	sub_821BE528(ctx, base);
loc_821DA630:
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821da4f0
	ctx.lr = 0x821DA63C;
	sub_821DA4F0(ctx, base);
loc_821DA63C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r11,23908
	ctx.r4.s64 = r11.s64 + 23908;
	// bl 0x821be860
	ctx.lr = 0x821DA650;
	sub_821BE860(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
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

__attribute__((alias("__imp__sub_821DA674"))) PPC_WEAK_FUNC(sub_821DA674);
PPC_FUNC_IMPL(__imp__sub_821DA674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DA678"))) PPC_WEAK_FUNC(sub_821DA678);
PPC_FUNC_IMPL(__imp__sub_821DA678) {
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
	ctx.lr = 0x821DA680;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da6cc
	if (!cr6.eq) goto loc_821DA6CC;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da6cc
	if (!cr6.lt) goto loc_821DA6CC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da6d8
	goto loc_821DA6D8;
loc_821DA6CC:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA6D8;
	sub_821BE528(ctx, base);
loc_821DA6D8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da710
	if (!cr6.eq) goto loc_821DA710;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da710
	if (!cr6.lt) goto loc_821DA710;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da71c
	goto loc_821DA71C;
loc_821DA710:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA71C;
	sub_821BE528(ctx, base);
loc_821DA71C:
	// addi r27,r28,-1
	r27.s64 = r28.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DA72C;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821da7a8
	if (!cr6.gt) goto loc_821DA7A8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,23916
	r28.s64 = r11.s64 + 23916;
loc_821DA740:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da774
	if (!cr6.eq) goto loc_821DA774;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da774
	if (!cr6.lt) goto loc_821DA774;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821da780
	goto loc_821DA780;
loc_821DA774:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA780;
	sub_821BE528(ctx, base);
loc_821DA780:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be860
	ctx.lr = 0x821DA790;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DA79C;
	sub_821DA4F0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x821da740
	if (!cr0.eq) goto loc_821DA740;
loc_821DA7A8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DA7B0"))) PPC_WEAK_FUNC(sub_821DA7B0);
PPC_FUNC_IMPL(__imp__sub_821DA7B0) {
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
	ctx.lr = 0x821DA7B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da804
	if (!cr6.eq) goto loc_821DA804;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da804
	if (!cr6.lt) goto loc_821DA804;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da810
	goto loc_821DA810;
loc_821DA804:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA810;
	sub_821BE528(ctx, base);
loc_821DA810:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da848
	if (!cr6.eq) goto loc_821DA848;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da848
	if (!cr6.lt) goto loc_821DA848;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da854
	goto loc_821DA854;
loc_821DA848:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA854;
	sub_821BE528(ctx, base);
loc_821DA854:
	// addi r29,r30,-1
	r29.s64 = r30.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DA864;
	sub_821DA4F0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x821da8e8
	if (!cr6.gt) goto loc_821DA8E8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,23916
	r28.s64 = r11.s64 + 23916;
loc_821DA87C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da8b0
	if (!cr6.eq) goto loc_821DA8B0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da8b0
	if (!cr6.lt) goto loc_821DA8B0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821da8bc
	goto loc_821DA8BC;
loc_821DA8B0:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA8BC;
	sub_821BE528(ctx, base);
loc_821DA8BC:
	// lbzx r11,r30,r25
	r11.u64 = PPC_LOAD_U8(r30.u32 + r25.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsb r5,r11
	ctx.r5.s64 = r11.s8;
	// bl 0x821be860
	ctx.lr = 0x821DA8D0;
	sub_821BE860(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DA8DC;
	sub_821DA4F0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x821da87c
	if (cr6.lt) goto loc_821DA87C;
loc_821DA8E8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821DA8F0"))) PPC_WEAK_FUNC(sub_821DA8F0);
PPC_FUNC_IMPL(__imp__sub_821DA8F0) {
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
	ctx.lr = 0x821DA8F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da944
	if (!cr6.eq) goto loc_821DA944;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da944
	if (!cr6.lt) goto loc_821DA944;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da950
	goto loc_821DA950;
loc_821DA944:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA950;
	sub_821BE528(ctx, base);
loc_821DA950:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da988
	if (!cr6.eq) goto loc_821DA988;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da988
	if (!cr6.lt) goto loc_821DA988;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821da994
	goto loc_821DA994;
loc_821DA988:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA994;
	sub_821BE528(ctx, base);
loc_821DA994:
	// addi r27,r28,-1
	r27.s64 = r28.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DA9A4;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821daa24
	if (!cr6.gt) goto loc_821DAA24;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,23916
	r28.s64 = r11.s64 + 23916;
loc_821DA9B8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821da9ec
	if (!cr6.eq) goto loc_821DA9EC;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821da9ec
	if (!cr6.lt) goto loc_821DA9EC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821da9f8
	goto loc_821DA9F8;
loc_821DA9EC:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DA9F8;
	sub_821BE528(ctx, base);
loc_821DA9F8:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// bl 0x821be860
	ctx.lr = 0x821DAA0C;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DAA18;
	sub_821DA4F0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// bne 0x821da9b8
	if (!cr0.eq) goto loc_821DA9B8;
loc_821DAA24:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DAA2C"))) PPC_WEAK_FUNC(sub_821DAA2C);
PPC_FUNC_IMPL(__imp__sub_821DAA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DAA30"))) PPC_WEAK_FUNC(sub_821DAA30);
PPC_FUNC_IMPL(__imp__sub_821DAA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// addi r8,r10,23928
	ctx.r8.s64 = ctx.r10.s64 + 23928;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r9,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r9.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,1096(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1096, r11.u32);
	// stb r11,1100(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1100, r11.u8);
	// stb r11,1101(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1101, r11.u8);
	// stb r11,1102(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1102, r11.u8);
	// stb r11,1103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1103, r11.u8);
	// stb r11,1104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1104, r11.u8);
	// stw r11,1108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1108, r11.u32);
	// stw r11,1112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1112, r11.u32);
	// stw r11,1116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1116, r11.u32);
	// stw r11,1120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1120, r11.u32);
	// stb r7,1124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1124, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DAA9C"))) PPC_WEAK_FUNC(sub_821DAA9C);
PPC_FUNC_IMPL(__imp__sub_821DAA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DAAA0"))) PPC_WEAK_FUNC(sub_821DAAA0);
PPC_FUNC_IMPL(__imp__sub_821DAAA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,23928
	ctx.r10.s64 = r11.s64 + 23928;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821e45a0
	sub_821E45A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821DAAB0"))) PPC_WEAK_FUNC(sub_821DAAB0);
PPC_FUNC_IMPL(__imp__sub_821DAAB0) {
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
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821daaec
	if (!cr6.gt) goto loc_821DAAEC;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dab1c
	goto loc_821DAB1C;
loc_821DAAEC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dab14
	if (!cr6.lt) goto loc_821DAB14;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dab1c
	goto loc_821DAB1C;
loc_821DAB14:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DAB1C;
	sub_821BE4F0(ctx, base);
loc_821DAB1C:
	// cmpwi cr6,r3,38
	cr6.compare<int32_t>(ctx.r3.s32, 38, xer);
	// bne cr6,0x821dacfc
	if (!cr6.eq) goto loc_821DACFC;
	// li r30,0
	r30.s64 = 0;
loc_821DAB28:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dab4c
	if (!cr6.gt) goto loc_821DAB4C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dab80
	goto loc_821DAB80;
loc_821DAB4C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dab74
	if (!cr6.lt) goto loc_821DAB74;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dab7c
	goto loc_821DAB7C;
loc_821DAB74:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DAB7C;
	sub_821BE4F0(ctx, base);
loc_821DAB7C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DAB80:
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// blt cr6,0x821dabac
	if (cr6.lt) goto loc_821DABAC;
	// cmpwi cr6,r11,122
	cr6.compare<int32_t>(r11.s32, 122, xer);
	// bgt cr6,0x821dabac
	if (cr6.gt) goto loc_821DABAC;
	// cmpwi cr6,r30,7
	cr6.compare<int32_t>(r30.s32, 7, xer);
	// bge cr6,0x821dab28
	if (!cr6.lt) goto loc_821DAB28;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// stbx r9,r30,r10
	PPC_STORE_U8(r30.u32 + ctx.r10.u32, ctx.r9.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x821dab28
	goto loc_821DAB28;
loc_821DABAC:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,23992
	ctx.r10.s64 = ctx.r10.s64 + 23992;
	// stbx r8,r30,r9
	PPC_STORE_U8(r30.u32 + ctx.r9.u32, ctx.r8.u8);
loc_821DABC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dabe8
	if (cr6.eq) goto loc_821DABE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dabc4
	if (cr6.eq) goto loc_821DABC4;
loc_821DABE8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dabf8
	if (!cr6.eq) goto loc_821DABF8;
	// li r3,316
	ctx.r3.s64 = 316;
	// b 0x821dacfc
	goto loc_821DACFC;
loc_821DABF8:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,23988
	ctx.r10.s64 = ctx.r10.s64 + 23988;
loc_821DAC04:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dac28
	if (cr6.eq) goto loc_821DAC28;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dac04
	if (cr6.eq) goto loc_821DAC04;
loc_821DAC28:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dac38
	if (!cr6.eq) goto loc_821DAC38;
	// li r3,318
	ctx.r3.s64 = 318;
	// b 0x821dacfc
	goto loc_821DACFC;
loc_821DAC38:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,23980
	ctx.r10.s64 = ctx.r10.s64 + 23980;
loc_821DAC44:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dac68
	if (cr6.eq) goto loc_821DAC68;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dac44
	if (cr6.eq) goto loc_821DAC44;
loc_821DAC68:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dac78
	if (!cr6.eq) goto loc_821DAC78;
	// li r3,295
	ctx.r3.s64 = 295;
	// b 0x821dacfc
	goto loc_821DACFC;
loc_821DAC78:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,23972
	ctx.r10.s64 = ctx.r10.s64 + 23972;
loc_821DAC84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821daca8
	if (cr6.eq) goto loc_821DACA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dac84
	if (cr6.eq) goto loc_821DAC84;
loc_821DACA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dacb8
	if (!cr6.eq) goto loc_821DACB8;
	// li r3,290
	ctx.r3.s64 = 290;
	// b 0x821dacfc
	goto loc_821DACFC;
loc_821DACB8:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,23968
	ctx.r10.s64 = ctx.r10.s64 + 23968;
loc_821DACC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dace8
	if (cr6.eq) goto loc_821DACE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dacc4
	if (cr6.eq) goto loc_821DACC4;
loc_821DACE8:
	// subfic r11,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	r11.s64 = 0 - ctx.r9.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r10,27
	r11.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r11,r11,0,31,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// addi r3,r11,294
	ctx.r3.s64 = r11.s64 + 294;
loc_821DACFC:
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

__attribute__((alias("__imp__sub_821DAD14"))) PPC_WEAK_FUNC(sub_821DAD14);
PPC_FUNC_IMPL(__imp__sub_821DAD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DAD18"))) PPC_WEAK_FUNC(sub_821DAD18);
PPC_FUNC_IMPL(__imp__sub_821DAD18) {
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
	ctx.lr = 0x821DAD20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821daab0
	ctx.lr = 0x821DAD34;
	sub_821DAAB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821daab0
	ctx.lr = 0x821DAD40;
	sub_821DAAB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x821dad74
	if (!cr6.gt) goto loc_821DAD74;
loc_821DAD48:
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// beq cr6,0x821dad74
	if (cr6.eq) goto loc_821DAD74;
	// cmpwi cr6,r31,1023
	cr6.compare<int32_t>(r31.s32, 1023, xer);
	// bge cr6,0x821dad74
	if (!cr6.lt) goto loc_821DAD74;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stbx r11,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x821daab0
	ctx.lr = 0x821DAD6C;
	sub_821DAAB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x821dad48
	if (cr6.gt) goto loc_821DAD48;
loc_821DAD74:
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,1
	ctx.r3.s64 = r31.s64 + 1;
	// stbx r11,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DAD88"))) PPC_WEAK_FUNC(sub_821DAD88);
PPC_FUNC_IMPL(__imp__sub_821DAD88) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,23780
	ctx.r10.s64 = r11.s64 + 23780;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821e45a0
	ctx.lr = 0x821DADB4;
	sub_821E45A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821dadcc
	if (cr6.eq) goto loc_821DADCC;
	// bl 0x82130588
	ctx.lr = 0x821DADC8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821DADCC:
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

__attribute__((alias("__imp__sub_821DADE4"))) PPC_WEAK_FUNC(sub_821DADE4);
PPC_FUNC_IMPL(__imp__sub_821DADE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DADE8"))) PPC_WEAK_FUNC(sub_821DADE8);
PPC_FUNC_IMPL(__imp__sub_821DADE8) {
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
	ctx.lr = 0x821DADF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821dae3c
	if (!cr6.eq) goto loc_821DAE3C;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821dae3c
	if (!cr6.lt) goto loc_821DAE3C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821dae48
	goto loc_821DAE48;
loc_821DAE3C:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DAE48;
	sub_821BE528(ctx, base);
loc_821DAE48:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821dae80
	if (!cr6.eq) goto loc_821DAE80;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821dae80
	if (!cr6.lt) goto loc_821DAE80;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821dae8c
	goto loc_821DAE8C;
loc_821DAE80:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DAE8C;
	sub_821BE528(ctx, base);
loc_821DAE8C:
	// addi r27,r28,-1
	r27.s64 = r28.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DAE9C;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821daf20
	if (!cr6.gt) goto loc_821DAF20;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,23996
	r28.s64 = r11.s64 + 23996;
loc_821DAEB0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821daee4
	if (!cr6.eq) goto loc_821DAEE4;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821daee4
	if (!cr6.lt) goto loc_821DAEE4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821daef0
	goto loc_821DAEF0;
loc_821DAEE4:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DAEF0;
	sub_821BE528(ctx, base);
loc_821DAEF0:
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x821be860
	ctx.lr = 0x821DAF08;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DAF14;
	sub_821DA4F0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x821daeb0
	if (!cr0.eq) goto loc_821DAEB0;
loc_821DAF20:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DAF28"))) PPC_WEAK_FUNC(sub_821DAF28);
PPC_FUNC_IMPL(__imp__sub_821DAF28) {
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
	ctx.lr = 0x821DAF30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821daf7c
	if (!cr6.eq) goto loc_821DAF7C;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821daf7c
	if (!cr6.lt) goto loc_821DAF7C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821daf88
	goto loc_821DAF88;
loc_821DAF7C:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DAF88;
	sub_821BE528(ctx, base);
loc_821DAF88:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821dafc0
	if (!cr6.eq) goto loc_821DAFC0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821dafc0
	if (!cr6.lt) goto loc_821DAFC0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821dafcc
	goto loc_821DAFCC;
loc_821DAFC0:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DAFCC;
	sub_821BE528(ctx, base);
loc_821DAFCC:
	// addi r27,r28,-1
	r27.s64 = r28.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DAFDC;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821db06c
	if (!cr6.gt) goto loc_821DB06C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,24004
	r28.s64 = r11.s64 + 24004;
loc_821DAFF0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db024
	if (!cr6.eq) goto loc_821DB024;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db024
	if (!cr6.lt) goto loc_821DB024;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821db030
	goto loc_821DB030;
loc_821DB024:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB030;
	sub_821BE528(ctx, base);
loc_821DB030:
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x821be860
	ctx.lr = 0x821DB054;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DB060;
	sub_821DA4F0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x821daff0
	if (!cr0.eq) goto loc_821DAFF0;
loc_821DB06C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DB074"))) PPC_WEAK_FUNC(sub_821DB074);
PPC_FUNC_IMPL(__imp__sub_821DB074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DB078"))) PPC_WEAK_FUNC(sub_821DB078);
PPC_FUNC_IMPL(__imp__sub_821DB078) {
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
	ctx.lr = 0x821DB080;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db0cc
	if (!cr6.eq) goto loc_821DB0CC;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db0cc
	if (!cr6.lt) goto loc_821DB0CC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821db0d8
	goto loc_821DB0D8;
loc_821DB0CC:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB0D8;
	sub_821BE528(ctx, base);
loc_821DB0D8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db110
	if (!cr6.eq) goto loc_821DB110;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db110
	if (!cr6.lt) goto loc_821DB110;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821db11c
	goto loc_821DB11C;
loc_821DB110:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB11C;
	sub_821BE528(ctx, base);
loc_821DB11C:
	// addi r27,r30,-1
	r27.s64 = r30.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DB12C;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821db1cc
	if (!cr6.gt) goto loc_821DB1CC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,24012
	r28.s64 = r11.s64 + 24012;
loc_821DB144:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db178
	if (!cr6.eq) goto loc_821DB178;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db178
	if (!cr6.lt) goto loc_821DB178;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821db184
	goto loc_821DB184;
loc_821DB178:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB184;
	sub_821BE528(ctx, base);
loc_821DB184:
	// lfs f3,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f1,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f2,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x821be860
	ctx.lr = 0x821DB1B4;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DB1C0;
	sub_821DA4F0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x821db144
	if (!cr0.eq) goto loc_821DB144;
loc_821DB1CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DB1D4"))) PPC_WEAK_FUNC(sub_821DB1D4);
PPC_FUNC_IMPL(__imp__sub_821DB1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DB1D8"))) PPC_WEAK_FUNC(sub_821DB1D8);
PPC_FUNC_IMPL(__imp__sub_821DB1D8) {
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
	ctx.lr = 0x821DB1E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db22c
	if (!cr6.eq) goto loc_821DB22C;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db22c
	if (!cr6.lt) goto loc_821DB22C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,13
	ctx.r9.s64 = 13;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821db238
	goto loc_821DB238;
loc_821DB22C:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB238;
	sub_821BE528(ctx, base);
loc_821DB238:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db270
	if (!cr6.eq) goto loc_821DB270;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db270
	if (!cr6.lt) goto loc_821DB270;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,10
	ctx.r9.s64 = 10;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x821db27c
	goto loc_821DB27C;
loc_821DB270:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB27C;
	sub_821BE528(ctx, base);
loc_821DB27C:
	// addi r27,r30,-1
	r27.s64 = r30.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DB28C;
	sub_821DA4F0(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821db338
	if (!cr6.gt) goto loc_821DB338;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r28,8
	r30.s64 = r28.s64 + 8;
	// li r26,9
	r26.s64 = 9;
	// addi r28,r11,24024
	r28.s64 = r11.s64 + 24024;
loc_821DB2A4:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db2d8
	if (!cr6.eq) goto loc_821DB2D8;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db2d8
	if (!cr6.lt) goto loc_821DB2D8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stbx r26,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r26.u8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x821db2e4
	goto loc_821DB2E4;
loc_821DB2D8:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be528
	ctx.lr = 0x821DB2E4;
	sub_821BE528(ctx, base);
loc_821DB2E4:
	// lfs f1,-8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f4,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f4,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f4.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x821be860
	ctx.lr = 0x821DB320;
	sub_821BE860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821da4f0
	ctx.lr = 0x821DB32C;
	sub_821DA4F0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x821db2a4
	if (!cr0.eq) goto loc_821DB2A4;
loc_821DB338:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DB340"))) PPC_WEAK_FUNC(sub_821DB340);
PPC_FUNC_IMPL(__imp__sub_821DB340) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x821DB348;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r14,r5
	r14.u64 = ctx.r5.u64;
	// li r16,13
	r16.s64 = 13;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db394
	if (!cr6.eq) goto loc_821DB394;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db394
	if (!cr6.lt) goto loc_821DB394;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r16,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r16.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db39c
	goto loc_821DB39C;
loc_821DB394:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DB39C;
	sub_821BE528(ctx, base);
loc_821DB39C:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r17,10
	r17.s64 = 10;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db3d8
	if (!cr6.eq) goto loc_821DB3D8;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db3d8
	if (!cr6.lt) goto loc_821DB3D8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r17,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r17.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db3e0
	goto loc_821DB3E0;
loc_821DB3D8:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DB3E0;
	sub_821BE528(ctx, base);
loc_821DB3E0:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x821da4f0
	ctx.lr = 0x821DB3EC;
	sub_821DA4F0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r5,0(r19)
	ctx.r5.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r11,24076
	ctx.r4.s64 = r11.s64 + 24076;
	// bl 0x821be860
	ctx.lr = 0x821DB400;
	sub_821BE860(ctx, base);
	// li r15,0
	r15.s64 = 0;
	// addi r11,r19,16
	r11.s64 = r19.s64 + 16;
	// stw r15,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r15.u32);
	// lwz r10,16(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 16);
	// rlwinm r9,r10,0,6,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3FF0000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821db42c
	if (!cr6.eq) goto loc_821DB42C;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821db430
	if (cr6.eq) goto loc_821DB430;
loc_821DB42C:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
loc_821DB430:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821db458
	if (!cr6.eq) goto loc_821DB458;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r10,24064
	ctx.r4.s64 = ctx.r10.s64 + 24064;
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// rlwinm r5,r11,16,22,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821be860
	ctx.lr = 0x821DB458;
	sub_821BE860(ctx, base);
loc_821DB458:
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lhz r10,12(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 12);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x821db470
	if (cr6.gt) goto loc_821DB470;
	// mr r11,r15
	r11.u64 = r15.u64;
loc_821DB470:
	// clrlwi r18,r11,24
	r18.u64 = r11.u32 & 0xFF;
	// mr r21,r15
	r21.u64 = r15.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821db608
	if (!cr6.gt) goto loc_821DB608;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// clrlwi r20,r18,24
	r20.u64 = r18.u32 & 0xFF;
	// mr r26,r15
	r26.u64 = r15.u64;
	// li r27,-1
	r27.s64 = -1;
	// addi r25,r11,-13292
	r25.s64 = r11.s64 + -13292;
	// addi r24,r10,24060
	r24.s64 = ctx.r10.s64 + 24060;
	// addi r22,r9,24052
	r22.s64 = ctx.r9.s64 + 24052;
	// addi r23,r8,24044
	r23.s64 = ctx.r8.s64 + 24044;
loc_821DB4AC:
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r28,r11,r26
	r28.u64 = r11.u64 + r26.u64;
	// beq cr6,0x821db558
	if (cr6.eq) goto loc_821DB558;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db4f4
	if (!cr6.eq) goto loc_821DB4F4;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db4f4
	if (!cr6.lt) goto loc_821DB4F4;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r16,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r16.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db4fc
	goto loc_821DB4FC;
loc_821DB4F4:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DB4FC;
	sub_821BE528(ctx, base);
loc_821DB4FC:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db534
	if (!cr6.eq) goto loc_821DB534;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db534
	if (!cr6.lt) goto loc_821DB534;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r17,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r17.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db53c
	goto loc_821DB53C;
loc_821DB534:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DB53C;
	sub_821BE528(ctx, base);
loc_821DB53C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x821da4f0
	ctx.lr = 0x821DB54C;
	sub_821DA4F0(ctx, base);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// b 0x821db55c
	goto loc_821DB55C;
loc_821DB558:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
loc_821DB55C:
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821be860
	ctx.lr = 0x821DB564;
	sub_821BE860(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c6160
	ctx.lr = 0x821DB574;
	sub_821C6160(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821db5a8
	if (cr6.eq) goto loc_821DB5A8;
	// mr r31,r15
	r31.u64 = r15.u64;
loc_821DB584:
	// lbzx r4,r31,r30
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + r30.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821db5a8
	if (cr6.eq) goto loc_821DB5A8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d9ae8
	ctx.lr = 0x821DB59C;
	sub_821D9AE8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// blt cr6,0x821db584
	if (cr6.lt) goto loc_821DB584;
loc_821DB5A8:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821be860
	ctx.lr = 0x821DB5B4;
	sub_821BE860(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_821DB5BC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821db5e0
	if (cr6.eq) goto loc_821DB5E0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821db5bc
	if (cr6.eq) goto loc_821DB5BC;
loc_821DB5E0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821db5f4
	if (!cr6.eq) goto loc_821DB5F4;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x821e45e8
	ctx.lr = 0x821DB5F0;
	sub_821E45E8(ctx, base);
	// stw r3,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r3.u32);
loc_821DB5F4:
	// lhz r11,12(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 12);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r26,r26,12
	r26.s64 = r26.s64 + 12;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x821db4ac
	if (cr6.lt) goto loc_821DB4AC;
loc_821DB608:
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821db6ac
	if (cr6.eq) goto loc_821DB6AC;
	// lhz r11,12(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821db6ac
	if (cr6.eq) goto loc_821DB6AC;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db658
	if (!cr6.eq) goto loc_821DB658;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db658
	if (!cr6.lt) goto loc_821DB658;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r16,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r16.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db660
	goto loc_821DB660;
loc_821DB658:
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x821be528
	ctx.lr = 0x821DB660;
	sub_821BE528(ctx, base);
loc_821DB660:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db698
	if (!cr6.eq) goto loc_821DB698;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db698
	if (!cr6.lt) goto loc_821DB698;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stbx r17,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r17.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x821db6a0
	goto loc_821DB6A0;
loc_821DB698:
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821be528
	ctx.lr = 0x821DB6A0;
	sub_821BE528(ctx, base);
loc_821DB6A0:
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821da4f0
	ctx.lr = 0x821DB6AC;
	sub_821DA4F0(ctx, base);
loc_821DB6AC:
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821db6cc
	if (cr6.eq) goto loc_821DB6CC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r4,r11,24040
	ctx.r4.s64 = r11.s64 + 24040;
	// bl 0x821be860
	ctx.lr = 0x821DB6C8;
	sub_821BE860(ctx, base);
	// b 0x821db718
	goto loc_821DB718;
loc_821DB6CC:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821db704
	if (!cr6.eq) goto loc_821DB704;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821db704
	if (!cr6.lt) goto loc_821DB704;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,62
	ctx.r9.s64 = 62;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821db70c
	goto loc_821DB70C;
loc_821DB704:
	// li r4,62
	ctx.r4.s64 = 62;
	// bl 0x821be528
	ctx.lr = 0x821DB70C;
	sub_821BE528(ctx, base);
loc_821DB70C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
loc_821DB718:
	// stb r15,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r15.u8);
	// stw r15,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r15.u32);
	// stw r15,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r15.u32);
	// stw r15,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r15.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_821DB730"))) PPC_WEAK_FUNC(sub_821DB730);
PPC_FUNC_IMPL(__imp__sub_821DB730) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x821db340
	sub_821DB340(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821DB738"))) PPC_WEAK_FUNC(sub_821DB738);
PPC_FUNC_IMPL(__imp__sub_821DB738) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821db340
	ctx.lr = 0x821DB754;
	sub_821DB340(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
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

__attribute__((alias("__imp__sub_821DB770"))) PPC_WEAK_FUNC(sub_821DB770);
PPC_FUNC_IMPL(__imp__sub_821DB770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r29{};
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
	// beq cr6,0x821db8d0
	if (cr6.eq) goto loc_821DB8D0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x821db79c
	if (!cr6.eq) goto loc_821DB79C;
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
loc_821DB79C:
	// cmplwi cr6,r7,11
	cr6.compare<uint32_t>(ctx.r7.u32, 11, xer);
	// bgt cr6,0x821db8c8
	if (cr6.gt) goto loc_821DB8C8;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-18500
	r12.s64 = r12.s64 + -18500;
	// rlwinm r0,r7,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r7.u64) {
	case 0:
		goto loc_821DB7EC;
	case 1:
		goto loc_821DB7EC;
	case 2:
		goto loc_821DB800;
	case 3:
		goto loc_821DB814;
	case 4:
		goto loc_821DB8C8;
	case 5:
		goto loc_821DB824;
	case 6:
		goto loc_821DB83C;
	case 7:
		goto loc_821DB854;
	case 8:
		goto loc_821DB86C;
	case 9:
		goto loc_821DB884;
	case 10:
		goto loc_821DB89C;
	case 11:
		goto loc_821DB8B4;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-18452(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18452);
	// lwz r16,-18452(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18452);
	// lwz r16,-18432(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18432);
	// lwz r16,-18412(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18412);
	// lwz r16,-18232(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18232);
	// lwz r16,-18396(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18396);
	// lwz r16,-18372(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18372);
	// lwz r16,-18348(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18348);
	// lwz r16,-18324(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18324);
	// lwz r16,-18300(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18300);
	// lwz r16,-18276(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18276);
	// lwz r16,-18252(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -18252);
loc_821DB7EC:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d9c80
	ctx.lr = 0x821DB7FC;
	sub_821D9C80(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB800:
	// rlwinm r5,r5,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d9ce8
	ctx.lr = 0x821DB810;
	sub_821D9CE8(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB814:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d9ec8
	ctx.lr = 0x821DB820;
	sub_821D9EC8(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB824:
	// rlwinm r6,r5,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821da678
	ctx.lr = 0x821DB838;
	sub_821DA678(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB83C:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821da7b0
	ctx.lr = 0x821DB850;
	sub_821DA7B0(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB854:
	// rlwinm r6,r5,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821da8f0
	ctx.lr = 0x821DB868;
	sub_821DA8F0(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB86C:
	// rlwinm r6,r5,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821dade8
	ctx.lr = 0x821DB880;
	sub_821DADE8(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB884:
	// rlwinm r6,r5,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821daf28
	ctx.lr = 0x821DB898;
	sub_821DAF28(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB89C:
	// rlwinm r6,r5,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821db078
	ctx.lr = 0x821DB8B0;
	sub_821DB078(ctx, base);
	// b 0x821db8c8
	goto loc_821DB8C8;
loc_821DB8B4:
	// rlwinm r6,r5,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821db1d8
	ctx.lr = 0x821DB8C8;
	sub_821DB1D8(ctx, base);
loc_821DB8C8:
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
loc_821DB8D0:
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

__attribute__((alias("__imp__sub_821DB8E4"))) PPC_WEAK_FUNC(sub_821DB8E4);
PPC_FUNC_IMPL(__imp__sub_821DB8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DB8E8"))) PPC_WEAK_FUNC(sub_821DB8E8);
PPC_FUNC_IMPL(__imp__sub_821DB8E8) {
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
	ctx.lr = 0x821DB8F0;
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
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821db924
	if (!cr6.gt) goto loc_821DB924;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821db958
	goto loc_821DB958;
loc_821DB924:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821db94c
	if (!cr6.lt) goto loc_821DB94C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821db954
	goto loc_821DB954;
loc_821DB94C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DB954;
	sub_821BE4F0(ctx, base);
loc_821DB954:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DB958:
	// extsb r8,r30
	ctx.r8.s64 = r30.s8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x821db970
	if (!cr6.eq) goto loc_821DB970;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821db984
	if (!cr6.eq) goto loc_821DB984;
loc_821DB970:
	// lwz r9,1096(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r6.u32);
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r11.u8);
loc_821DB984:
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DB998"))) PPC_WEAK_FUNC(sub_821DB998);
PPC_FUNC_IMPL(__imp__sub_821DB998) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,23928
	ctx.r10.s64 = r11.s64 + 23928;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821e45a0
	ctx.lr = 0x821DB9C4;
	sub_821E45A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821db9dc
	if (cr6.eq) goto loc_821DB9DC;
	// bl 0x82130588
	ctx.lr = 0x821DB9D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821DB9DC:
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

__attribute__((alias("__imp__sub_821DB9F4"))) PPC_WEAK_FUNC(sub_821DB9F4);
PPC_FUNC_IMPL(__imp__sub_821DB9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DB9F8"))) PPC_WEAK_FUNC(sub_821DB9F8);
PPC_FUNC_IMPL(__imp__sub_821DB9F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,3
	r11.s64 = 3;
loc_821DBA04:
	// addi r8,r1,28
	ctx.r8.s64 = ctx.r1.s64 + 28;
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r7.u32);
	// lbzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stbx r6,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u8);
	// bge 0x821dba04
	if (!cr0.lt) goto loc_821DBA04;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBA28"))) PPC_WEAK_FUNC(sub_821DBA28);
PPC_FUNC_IMPL(__imp__sub_821DBA28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// addi r11,r4,-290
	r11.s64 = ctx.r4.s64 + -290;
	// cmplwi cr6,r11,28
	cr6.compare<uint32_t>(r11.u32, 28, xer);
	// bgt cr6,0x821dbbb0
	if (cr6.gt) {
		sub_821DBBB0(ctx, base);
		return;
	}
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-17844
	r12.s64 = r12.s64 + -17844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x821DBB50
		return;
	case 1:
		// ERROR: 0x821DBBB0
		return;
	case 2:
		// ERROR: 0x821DBBB0
		return;
	case 3:
		// ERROR: 0x821DBBB0
		return;
	case 4:
		// ERROR: 0x821DBB80
		return;
	case 5:
		// ERROR: 0x821DBB20
		return;
	case 6:
		// ERROR: 0x821DBBB0
		return;
	case 7:
		// ERROR: 0x821DBBB0
		return;
	case 8:
		// ERROR: 0x821DBBB0
		return;
	case 9:
		// ERROR: 0x821DBBB0
		return;
	case 10:
		// ERROR: 0x821DBBB0
		return;
	case 11:
		// ERROR: 0x821DBBB0
		return;
	case 12:
		// ERROR: 0x821DBBB0
		return;
	case 13:
		// ERROR: 0x821DBBB0
		return;
	case 14:
		// ERROR: 0x821DBBB0
		return;
	case 15:
		// ERROR: 0x821DBBB0
		return;
	case 16:
		// ERROR: 0x821DBBB0
		return;
	case 17:
		// ERROR: 0x821DBBB0
		return;
	case 18:
		// ERROR: 0x821DBBB0
		return;
	case 19:
		// ERROR: 0x821DBBB0
		return;
	case 20:
		// ERROR: 0x821DBBB0
		return;
	case 21:
		// ERROR: 0x821DBBB0
		return;
	case 22:
		// ERROR: 0x821DBBB0
		return;
	case 23:
		// ERROR: 0x821DBBB0
		return;
	case 24:
		// ERROR: 0x821DBBB0
		return;
	case 25:
		// ERROR: 0x821DBBB0
		return;
	case 26:
		// ERROR: 0x821DBAC0
		return;
	case 27:
		// ERROR: 0x821DBBB0
		return;
	case 28:
		// ERROR: 0x821DBAF0
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_821DBA4C"))) PPC_WEAK_FUNC(sub_821DBA4C);
PPC_FUNC_IMPL(__imp__sub_821DBA4C) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r16{};
	PPCRegister r29{};
	// lwz r16,-17584(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17584);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17536(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17536);
	// lwz r16,-17632(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17632);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17728(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17728);
	// lwz r16,-17488(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17488);
	// lwz r16,-17680(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -17680);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,3
	r11.s64 = 3;
	// addi r8,r9,23840
	ctx.r8.s64 = ctx.r9.s64 + 23840;
loc_821DBAD0:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// bge 0x821dbad0
	if (!cr0.lt) goto loc_821DBAD0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBAF0"))) PPC_WEAK_FUNC(sub_821DBAF0);
PPC_FUNC_IMPL(__imp__sub_821DBAF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,3
	r11.s64 = 3;
	// addi r8,r9,23832
	ctx.r8.s64 = ctx.r9.s64 + 23832;
loc_821DBB00:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// bge 0x821dbb00
	if (!cr0.lt) goto loc_821DBB00;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBB20"))) PPC_WEAK_FUNC(sub_821DBB20);
PPC_FUNC_IMPL(__imp__sub_821DBB20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,5
	r11.s64 = 5;
	// addi r8,r9,23816
	ctx.r8.s64 = ctx.r9.s64 + 23816;
loc_821DBB30:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// bge 0x821dbb30
	if (!cr0.lt) goto loc_821DBB30;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBB50"))) PPC_WEAK_FUNC(sub_821DBB50);
PPC_FUNC_IMPL(__imp__sub_821DBB50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,5
	r11.s64 = 5;
	// addi r8,r9,23808
	ctx.r8.s64 = ctx.r9.s64 + 23808;
loc_821DBB60:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// bge 0x821dbb60
	if (!cr0.lt) goto loc_821DBB60;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBB80"))) PPC_WEAK_FUNC(sub_821DBB80);
PPC_FUNC_IMPL(__imp__sub_821DBB80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// li r11,4
	r11.s64 = 4;
	// addi r8,r9,23824
	ctx.r8.s64 = ctx.r9.s64 + 23824;
loc_821DBB90:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// bge 0x821dbb90
	if (!cr0.lt) goto loc_821DBB90;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBBB0"))) PPC_WEAK_FUNC(sub_821DBBB0);
PPC_FUNC_IMPL(__imp__sub_821DBBB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,1096(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1096);
	// addi r11,r3,72
	r11.s64 = ctx.r3.s64 + 72;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,1096(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1096, ctx.r8.u32);
	// stbx r4,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DBBC8"))) PPC_WEAK_FUNC(sub_821DBBC8);
PPC_FUNC_IMPL(__imp__sub_821DBBC8) {
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
	ctx.lr = 0x821DBBD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dbc68
	if (cr6.eq) goto loc_821DBC68;
loc_821DBBF0:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dbc14
	if (!cr6.gt) goto loc_821DBC14;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dbc48
	goto loc_821DBC48;
loc_821DBC14:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dbc3c
	if (!cr6.lt) goto loc_821DBC3C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dbc48
	goto loc_821DBC48;
loc_821DBC3C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DBC44;
	sub_821BE4F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_821DBC48:
	// lbzx r11,r30,r29
	r11.u64 = PPC_LOAD_U8(r30.u32 + r29.u32);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x821dbcd4
	if (!cr6.eq) goto loc_821DBCD4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbzx r11,r30,r29
	r11.u64 = PPC_LOAD_U8(r30.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dbbf0
	if (!cr6.eq) goto loc_821DBBF0;
loc_821DBC68:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dbcc8
	if (!cr6.eq) goto loc_821DBCC8;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x821dbca0
	if (!cr6.lt) goto loc_821DBCA0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821DBC84:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821dbc84
	if (!cr6.eq) goto loc_821DBC84;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
loc_821DBCA0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x821dbcc8
	if (cr0.lt) goto loc_821DBCC8;
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
loc_821DBCAC:
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// lbzx r8,r11,r29
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + r29.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r7.u32);
	// stbx r8,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u8);
	// bge 0x821dbcac
	if (!cr0.lt) goto loc_821DBCAC;
loc_821DBCC8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821DBCD4:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r7,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r7.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r8.u8);
	// bge cr6,0x821dbd18
	if (!cr6.lt) goto loc_821DBD18;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_821DBCFC:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821dbcfc
	if (!cr6.eq) goto loc_821DBCFC;
	// subf r10,r29,r10
	ctx.r10.s64 = ctx.r10.s64 - r29.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
loc_821DBD18:
	// addic. r10,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r10.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x821dbd3c
	if (cr0.lt) goto loc_821DBD3C;
loc_821DBD20:
	// lwz r9,1024(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1024);
	// lbzx r8,r10,r29
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r29.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,1024(r11)
	PPC_STORE_U32(r11.u32 + 1024, ctx.r7.u32);
	// stbx r8,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r8.u8);
	// bge 0x821dbd20
	if (!cr0.lt) goto loc_821DBD20;
loc_821DBD3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DBD48"))) PPC_WEAK_FUNC(sub_821DBD48);
PPC_FUNC_IMPL(__imp__sub_821DBD48) {
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
	ctx.lr = 0x821DBD50;
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
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dbd84
	if (!cr6.gt) goto loc_821DBD84;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dbdb8
	goto loc_821DBDB8;
loc_821DBD84:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dbdac
	if (!cr6.lt) goto loc_821DBDAC;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lbzx r11,r9,r11
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// b 0x821dbdb8
	goto loc_821DBDB8;
loc_821DBDAC:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DBDB4;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DBDB8:
	// li r30,0
	r30.s64 = 0;
loc_821DBDBC:
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// blt cr6,0x821dbdcc
	if (cr6.lt) goto loc_821DBDCC;
	// cmpwi cr6,r11,122
	cr6.compare<int32_t>(r11.s32, 122, xer);
	// ble cr6,0x821dbe0c
	if (!cr6.gt) goto loc_821DBE0C;
loc_821DBDCC:
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// blt cr6,0x821dbddc
	if (cr6.lt) goto loc_821DBDDC;
	// cmpwi cr6,r11,90
	cr6.compare<int32_t>(r11.s32, 90, xer);
	// ble cr6,0x821dbe0c
	if (!cr6.gt) goto loc_821DBE0C;
loc_821DBDDC:
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// blt cr6,0x821dbdec
	if (cr6.lt) goto loc_821DBDEC;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// ble cr6,0x821dbe0c
	if (!cr6.gt) goto loc_821DBE0C;
loc_821DBDEC:
	// cmpwi cr6,r11,58
	cr6.compare<int32_t>(r11.s32, 58, xer);
	// beq cr6,0x821dbe0c
	if (cr6.eq) goto loc_821DBE0C;
	// cmpwi cr6,r11,95
	cr6.compare<int32_t>(r11.s32, 95, xer);
	// beq cr6,0x821dbe0c
	if (cr6.eq) goto loc_821DBE0C;
	// cmpwi cr6,r11,46
	cr6.compare<int32_t>(r11.s32, 46, xer);
	// beq cr6,0x821dbe0c
	if (cr6.eq) goto loc_821DBE0C;
	// cmpwi cr6,r11,45
	cr6.compare<int32_t>(r11.s32, 45, xer);
	// bne cr6,0x821dbe7c
	if (!cr6.eq) goto loc_821DBE7C;
loc_821DBE0C:
	// addi r10,r28,-1
	ctx.r10.s64 = r28.s64 + -1;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x821dbe7c
	if (!cr6.lt) goto loc_821DBE7C;
	// stbx r11,r30,r29
	PPC_STORE_U8(r30.u32 + r29.u32, r11.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821dbe44
	if (!cr6.gt) goto loc_821DBE44;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dbdbc
	goto loc_821DBDBC;
loc_821DBE44:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dbe6c
	if (!cr6.lt) goto loc_821DBE6C;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lbzx r11,r9,r11
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// b 0x821dbdbc
	goto loc_821DBDBC;
loc_821DBE6C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DBE74;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x821dbdbc
	goto loc_821DBDBC;
loc_821DBE7C:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stbx r10,r30,r29
	PPC_STORE_U8(r30.u32 + r29.u32, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// blt cr6,0x821dbea4
	if (cr6.lt) goto loc_821DBEA4;
	// lwz r9,1096(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r11.u8);
loc_821DBEA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DBEAC"))) PPC_WEAK_FUNC(sub_821DBEAC);
PPC_FUNC_IMPL(__imp__sub_821DBEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DBEB0"))) PPC_WEAK_FUNC(sub_821DBEB0);
PPC_FUNC_IMPL(__imp__sub_821DBEB0) {
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
	ctx.lr = 0x821DBEB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// extsb r30,r11
	r30.s64 = r11.s8;
	// addi r28,r4,1
	r28.s64 = ctx.r4.s64 + 1;
	// addi r27,r30,1
	r27.s64 = r30.s64 + 1;
loc_821DBED4:
	// cmpw cr6,r27,r30
	cr6.compare<int32_t>(r27.s32, r30.s32, xer);
	// beq cr6,0x821dbf3c
	if (cr6.eq) goto loc_821DBF3C;
loc_821DBEDC:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dbf00
	if (!cr6.gt) goto loc_821DBF00;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dbf34
	goto loc_821DBF34;
loc_821DBF00:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dbf28
	if (!cr6.lt) goto loc_821DBF28;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dbf30
	goto loc_821DBF30;
loc_821DBF28:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DBF30;
	sub_821BE4F0(ctx, base);
loc_821DBF30:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DBF34:
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// bne cr6,0x821dbedc
	if (!cr6.eq) goto loc_821DBEDC;
loc_821DBF3C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821dbf60
	if (cr6.eq) goto loc_821DBF60;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x821DBF54;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dbf64
	if (cr6.eq) goto loc_821DBF64;
loc_821DBF60:
	// li r29,1
	r29.s64 = 1;
loc_821DBF64:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dbed4
	if (cr6.eq) goto loc_821DBED4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821DBF78"))) PPC_WEAK_FUNC(sub_821DBF78);
PPC_FUNC_IMPL(__imp__sub_821DBF78) {
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
loc_821DBF8C:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dbfb0
	if (!cr6.gt) goto loc_821DBFB0;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dbfe4
	goto loc_821DBFE4;
loc_821DBFB0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dbfd8
	if (!cr6.lt) goto loc_821DBFD8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dbfe0
	goto loc_821DBFE0;
loc_821DBFD8:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DBFE0;
	sub_821BE4F0(ctx, base);
loc_821DBFE0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DBFE4:
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x821dbf8c
	if (cr6.eq) goto loc_821DBF8C;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x821dbf8c
	if (cr6.eq) goto loc_821DBF8C;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x821dbf8c
	if (cr6.eq) goto loc_821DBF8C;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x821dbf8c
	if (cr6.eq) goto loc_821DBF8C;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x821dbf8c
	if (cr6.eq) goto loc_821DBF8C;
	// lwz r9,1096(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r11.u8);
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

__attribute__((alias("__imp__sub_821DC034"))) PPC_WEAK_FUNC(sub_821DC034);
PPC_FUNC_IMPL(__imp__sub_821DC034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DC038"))) PPC_WEAK_FUNC(sub_821DC038);
PPC_FUNC_IMPL(__imp__sub_821DC038) {
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
	ctx.lr = 0x821DC040;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x821dc05c
	if (!cr6.eq) goto loc_821DC05C;
	// addi r26,r5,-2
	r26.s64 = ctx.r5.s64 + -2;
loc_821DC05C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r28,1
	r28.s64 = 1;
	// addi r21,r5,-1
	r21.s64 = ctx.r5.s64 + -1;
	// li r27,60
	r27.s64 = 60;
	// addi r23,r11,24088
	r23.s64 = r11.s64 + 24088;
	// addi r22,r10,24084
	r22.s64 = ctx.r10.s64 + 24084;
	// addi r25,r9,24080
	r25.s64 = ctx.r9.s64 + 24080;
loc_821DC080:
	// cmpw cr6,r26,r21
	cr6.compare<int32_t>(r26.s32, r21.s32, xer);
	// bge cr6,0x821dc308
	if (!cr6.lt) goto loc_821DC308;
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc0ac
	if (!cr6.gt) goto loc_821DC0AC;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc0e0
	goto loc_821DC0E0;
loc_821DC0AC:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc0d4
	if (!cr6.lt) goto loc_821DC0D4;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lbzx r11,r9,r11
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// b 0x821dc0e0
	goto loc_821DC0E0;
loc_821DC0D4:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC0DC;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC0E0:
	// cmpwi cr6,r11,60
	cr6.compare<int32_t>(r11.s32, 60, xer);
	// bne cr6,0x821dc29c
	if (!cr6.eq) goto loc_821DC29C;
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc10c
	if (!cr6.gt) goto loc_821DC10C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r10.u32);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc140
	goto loc_821DC140;
loc_821DC10C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc134
	if (!cr6.lt) goto loc_821DC134;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc140
	goto loc_821DC140;
loc_821DC134:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC13C;
	sub_821BE4F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_821DC140:
	// cmpwi cr6,r10,33
	cr6.compare<int32_t>(ctx.r10.s32, 33, xer);
	// beq cr6,0x821dc180
	if (cr6.eq) goto loc_821DC180;
	// cmpwi cr6,r10,63
	cr6.compare<int32_t>(ctx.r10.s32, 63, xer);
	// beq cr6,0x821dc180
	if (cr6.eq) goto loc_821DC180;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,1096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// li r28,0
	r28.s64 = 0;
	// stw r8,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r8.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r10,1096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r7.u32);
	// stbx r27,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r27.u8);
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC180:
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// bl 0x821dbbc8
	ctx.lr = 0x821DC1A4;
	sub_821DBBC8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821dc1c0
	if (cr6.eq) goto loc_821DC1C0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x821dbeb0
	ctx.lr = 0x821DC1BC;
	sub_821DBEB0(ctx, base);
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC1C0:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,33
	ctx.r4.s64 = 33;
	// bl 0x821db8e8
	ctx.lr = 0x821DC1CC;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dc258
	if (cr6.eq) goto loc_821DC258;
	// li r29,1
	r29.s64 = 1;
loc_821DC1DC:
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc1fc
	if (!cr6.gt) goto loc_821DC1FC;
	// lwz r11,1024(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r11.u32);
	// lbzx r11,r11,r31
	r11.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// b 0x821dc230
	goto loc_821DC230;
loc_821DC1FC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc224
	if (!cr6.lt) goto loc_821DC224;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc22c
	goto loc_821DC22C;
loc_821DC224:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC22C;
	sub_821BE4F0(ctx, base);
loc_821DC22C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC230:
	// cmpwi cr6,r11,60
	cr6.compare<int32_t>(r11.s32, 60, xer);
	// bne cr6,0x821dc240
	if (!cr6.eq) goto loc_821DC240;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x821dc24c
	goto loc_821DC24C;
loc_821DC240:
	// cmpwi cr6,r11,62
	cr6.compare<int32_t>(r11.s32, 62, xer);
	// bne cr6,0x821dc24c
	if (!cr6.eq) goto loc_821DC24C;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
loc_821DC24C:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bgt cr6,0x821dc1dc
	if (cr6.gt) goto loc_821DC1DC;
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC258:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,63
	ctx.r4.s64 = 63;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DC268;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dc284
	if (cr6.eq) goto loc_821DC284;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbeb0
	ctx.lr = 0x821DC280;
	sub_821DBEB0(ctx, base);
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC284:
	// lwz r11,1024(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, ctx.r10.u32);
	// stbx r27,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r27.u8);
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC29C:
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x821dc2e8
	if (cr6.eq) goto loc_821DC2E8;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x821dc2e8
	if (cr6.eq) goto loc_821DC2E8;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x821dc2e8
	if (cr6.eq) goto loc_821DC2E8;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x821dc2e8
	if (cr6.eq) goto loc_821DC2E8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x821dc2e8
	if (cr6.eq) goto loc_821DC2E8;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821dc2fc
	if (cr6.eq) goto loc_821DC2FC;
	// lwz r9,1096(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r10,r30,72
	ctx.r10.s64 = r30.s64 + 72;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r8.u32);
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r11.u8);
	// b 0x821dc2fc
	goto loc_821DC2FC;
loc_821DC2E8:
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821dc2fc
	if (cr6.eq) goto loc_821DC2FC;
	// stbx r11,r26,r24
	PPC_STORE_U8(r26.u32 + r24.u32, r11.u8);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_821DC2FC:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dc080
	if (!cr6.eq) goto loc_821DC080;
loc_821DC308:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821dc324
	if (cr6.eq) goto loc_821DC324;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r26,1
	ctx.r3.s64 = r26.s64 + 1;
	// stbx r11,r26,r24
	PPC_STORE_U8(r26.u32 + r24.u32, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_821DC324:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821DC330"))) PPC_WEAK_FUNC(sub_821DC330);
PPC_FUNC_IMPL(__imp__sub_821DC330) {
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
	ctx.lr = 0x821DC338;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r20,0
	r20.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r22,1
	r22.s64 = 1;
	// lwz r11,1116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1116);
	// li r21,2
	r21.s64 = 2;
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x821dc384
	if (cr6.eq) goto loc_821DC384;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x821dc390
	if (!cr6.eq) goto loc_821DC390;
	// lbz r11,1114(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1114);
	// mr r29,r21
	r29.u64 = r21.u64;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// lwz r10,1112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1112);
	// stb r10,1(r26)
	PPC_STORE_U8(r26.u32 + 1, ctx.r10.u8);
	// b 0x821dc390
	goto loc_821DC390;
loc_821DC384:
	// lwz r11,1112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1112);
	// mr r29,r22
	r29.u64 = r22.u64;
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
loc_821DC390:
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// stw r20,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r20.u32);
	// stw r20,1112(r31)
	PPC_STORE_U32(r31.u32 + 1112, r20.u32);
	// bge cr6,0x821dc728
	if (!cr6.lt) goto loc_821DC728;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r25,r29,3
	r25.s64 = r29.s64 + 3;
	// addi r24,r11,-30232
	r24.s64 = r11.s64 + -30232;
loc_821DC3AC:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc54c
	if (!cr6.gt) goto loc_821DC54C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DC3C0;
	sub_821DBF78(ctx, base);
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc3e4
	if (!cr6.gt) goto loc_821DC3E4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc418
	goto loc_821DC418;
loc_821DC3E4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc40c
	if (!cr6.lt) goto loc_821DC40C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc414
	goto loc_821DC414;
loc_821DC40C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC414;
	sub_821BE4F0(ctx, base);
loc_821DC414:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC418:
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// cmpwi cr6,r27,60
	cr6.compare<int32_t>(r27.s32, 60, xer);
	// beq cr6,0x821dc734
	if (cr6.eq) goto loc_821DC734;
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc44c
	if (!cr6.gt) goto loc_821DC44C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc480
	goto loc_821DC480;
loc_821DC44C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc474
	if (!cr6.lt) goto loc_821DC474;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc47c
	goto loc_821DC47C;
loc_821DC474:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC47C;
	sub_821BE4F0(ctx, base);
loc_821DC47C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC480:
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// extsb r28,r11
	r28.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821dc4a8
	if (!cr6.gt) goto loc_821DC4A8;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc4dc
	goto loc_821DC4DC;
loc_821DC4A8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc4d0
	if (!cr6.lt) goto loc_821DC4D0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc4d8
	goto loc_821DC4D8;
loc_821DC4D0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC4D8;
	sub_821BE4F0(ctx, base);
loc_821DC4D8:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC4DC:
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// extsb r30,r11
	r30.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821dc508
	if (!cr6.gt) goto loc_821DC508;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x821dc64c
	goto loc_821DC64C;
loc_821DC508:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc538
	if (!cr6.lt) goto loc_821DC538;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x821dc64c
	goto loc_821DC64C;
loc_821DC538:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC540;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x821dc64c
	goto loc_821DC64C;
loc_821DC54C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc574
	if (!cr6.lt) goto loc_821DC574;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc57c
	goto loc_821DC57C;
loc_821DC574:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC57C;
	sub_821BE4F0(ctx, base);
loc_821DC57C:
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x821dc54c
	if (cr6.eq) goto loc_821DC54C;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x821dc54c
	if (cr6.eq) goto loc_821DC54C;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x821dc54c
	if (cr6.eq) goto loc_821DC54C;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x821dc54c
	if (cr6.eq) goto loc_821DC54C;
	// extsb r27,r10
	r27.s64 = ctx.r10.s8;
	// cmpwi cr6,r27,60
	cr6.compare<int32_t>(r27.s32, 60, xer);
	// beq cr6,0x821dc734
	if (cr6.eq) goto loc_821DC734;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc5d8
	if (!cr6.lt) goto loc_821DC5D8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc5e0
	goto loc_821DC5E0;
loc_821DC5D8:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC5E0;
	sub_821BE4F0(ctx, base);
loc_821DC5E0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsb r28,r3
	r28.s64 = ctx.r3.s8;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc60c
	if (!cr6.lt) goto loc_821DC60C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc614
	goto loc_821DC614;
loc_821DC60C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC614;
	sub_821BE4F0(ctx, base);
loc_821DC614:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsb r30,r3
	r30.s64 = ctx.r3.s8;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc640
	if (!cr6.lt) goto loc_821DC640;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc648
	goto loc_821DC648;
loc_821DC640:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC648;
	sub_821BE4F0(ctx, base);
loc_821DC648:
	// extsb r11,r3
	r11.s64 = ctx.r3.s8;
loc_821DC64C:
	// extsb r10,r30
	ctx.r10.s64 = r30.s8;
	// lbzx r9,r27,r24
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + r24.u32);
	// extsb r7,r28
	ctx.r7.s64 = r28.s8;
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// cmpwi cr6,r10,61
	cr6.compare<int32_t>(ctx.r10.s32, 61, xer);
	// rlwinm r6,r9,2,24,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFC;
	// lbzx r5,r10,r24
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + r24.u32);
	// lbzx r3,r7,r24
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + r24.u32);
	// lbzx r10,r8,r24
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r24.u32);
	// rotlwi r11,r5,6
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 6);
	// rlwinm r9,r5,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r4,r3,4,24,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xF0;
	// or r7,r11,r10
	ctx.r7.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r5,r3,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 28) & 0xFFFFFFF;
	// or r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 | ctx.r9.u64;
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// beq cr6,0x821dc758
	if (cr6.eq) goto loc_821DC758;
	// cmpwi cr6,r8,61
	cr6.compare<int32_t>(ctx.r8.s32, 61, xer);
	// beq cr6,0x821dc768
	if (cr6.eq) goto loc_821DC768;
	// cmpw cr6,r25,r23
	cr6.compare<int32_t>(r25.s32, r23.s32, xer);
	// bgt cr6,0x821dc6c4
	if (cr6.gt) goto loc_821DC6C4;
	// stbx r11,r29,r26
	PPC_STORE_U8(r29.u32 + r26.u32, r11.u8);
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// addi r8,r25,1
	ctx.r8.s64 = r25.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stbx r10,r11,r26
	PPC_STORE_U8(r11.u32 + r26.u32, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r9,r11,r26
	PPC_STORE_U8(r11.u32 + r26.u32, ctx.r9.u8);
	// b 0x821dc718
	goto loc_821DC718;
loc_821DC6C4:
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// bne cr6,0x821dc6f0
	if (!cr6.eq) goto loc_821DC6F0;
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stbx r11,r29,r26
	PPC_STORE_U8(r29.u32 + r26.u32, r11.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r21,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r21.u32);
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// stw r11,1112(r31)
	PPC_STORE_U32(r31.u32 + 1112, r11.u32);
	// b 0x821dc720
	goto loc_821DC720;
loc_821DC6F0:
	// addi r8,r23,-2
	ctx.r8.s64 = r23.s64 + -2;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// bne cr6,0x821dc720
	if (!cr6.eq) goto loc_821DC720;
	// stbx r11,r29,r26
	PPC_STORE_U8(r29.u32 + r26.u32, r11.u8);
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// addi r8,r25,1
	ctx.r8.s64 = r25.s64 + 1;
	// stbx r10,r11,r26
	PPC_STORE_U8(r11.u32 + r26.u32, ctx.r10.u8);
	// stw r22,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r22.u32);
	// stw r9,1112(r31)
	PPC_STORE_U32(r31.u32 + 1112, ctx.r9.u32);
loc_821DC718:
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// addi r25,r8,1
	r25.s64 = ctx.r8.s64 + 1;
loc_821DC720:
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// blt cr6,0x821dc3ac
	if (cr6.lt) goto loc_821DC3AC;
loc_821DC728:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_821DC734:
	// stb r20,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r20.u8);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,1096(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_821DC758:
	// stbx r11,r29,r26
	PPC_STORE_U8(r29.u32 + r26.u32, r11.u8);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_821DC768:
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// stbx r11,r29,r26
	PPC_STORE_U8(r29.u32 + r26.u32, r11.u8);
	// cmpw cr6,r3,r23
	cr6.compare<int32_t>(ctx.r3.s32, r23.s32, xer);
	// bge cr6,0x821dc788
	if (!cr6.lt) goto loc_821DC788;
	// stbx r10,r3,r26
	PPC_STORE_U8(ctx.r3.u32 + r26.u32, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_821DC788:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stw r22,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r22.u32);
	// stw r11,1112(r31)
	PPC_STORE_U32(r31.u32 + 1112, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_821DC79C"))) PPC_WEAK_FUNC(sub_821DC79C);
PPC_FUNC_IMPL(__imp__sub_821DC79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DC7A0"))) PPC_WEAK_FUNC(sub_821DC7A0);
PPC_FUNC_IMPL(__imp__sub_821DC7A0) {
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
	ctx.lr = 0x821DC7A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	r26.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addic. r28,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	r28.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r30,r26
	r30.u64 = r26.u64;
	// ble 0x821dc8cc
	if (!cr0.gt) goto loc_821DC8CC;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_821DC7C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821daab0
	ctx.lr = 0x821DC7D0;
	sub_821DAAB0(ctx, base);
	// cmpwi cr6,r3,60
	cr6.compare<int32_t>(ctx.r3.s32, 60, xer);
	// beq cr6,0x821dc8d8
	if (cr6.eq) goto loc_821DC8D8;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stb r9,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// cmplwi cr6,r9,192
	cr6.compare<uint32_t>(ctx.r9.u32, 192, xer);
	// blt cr6,0x821dc848
	if (cr6.lt) goto loc_821DC848;
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc80c
	if (!cr6.gt) goto loc_821DC80C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc844
	goto loc_821DC844;
loc_821DC80C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc834
	if (!cr6.lt) goto loc_821DC834;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc83c
	goto loc_821DC83C;
loc_821DC834:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC83C;
	sub_821BE4F0(ctx, base);
loc_821DC83C:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC844:
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
loc_821DC848:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,224
	cr6.compare<uint32_t>(r11.u32, 224, xer);
	// blt cr6,0x821dc8b0
	if (cr6.lt) goto loc_821DC8B0;
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dc878
	if (!cr6.gt) goto loc_821DC878;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dc8ac
	goto loc_821DC8AC;
loc_821DC878:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dc8a0
	if (!cr6.lt) goto loc_821DC8A0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dc8a8
	goto loc_821DC8A8;
loc_821DC8A0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DC8A8;
	sub_821BE4F0(ctx, base);
loc_821DC8A8:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DC8AC:
	// stb r11,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r11.u8);
loc_821DC8B0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e4a50
	ctx.lr = 0x821DC8BC;
	sub_821E4A50(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x821dc7c8
	if (cr6.lt) goto loc_821DC7C8;
loc_821DC8CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DC8D8:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// rlwinm r9,r30,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// li r7,60
	ctx.r7.s64 = 60;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// addi r3,r30,1
	ctx.r3.s64 = r30.s64 + 1;
	// stbx r7,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, ctx.r7.u8);
	// sthx r26,r9,r27
	PPC_STORE_U16(ctx.r9.u32 + r27.u32, r26.u16);
	// stb r26,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DC908"))) PPC_WEAK_FUNC(sub_821DC908);
PPC_FUNC_IMPL(__imp__sub_821DC908) {
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
	ctx.lr = 0x821DC910;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x821dc994
	if (!cr6.gt) goto loc_821DC994;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821DC92C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DC934;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DC944;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dc98c
	if (!cr6.eq) goto loc_821DC98C;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DC960;
	sub_821DBD48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de058
	ctx.lr = 0x821DC968;
	sub_823DE058(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x821dc92c
	if (cr6.lt) goto loc_821DC92C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_821DC98C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r29)
	PPC_STORE_U8(r29.u32 + 1103, r11.u8);
loc_821DC994:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DC9A0"))) PPC_WEAK_FUNC(sub_821DC9A0);
PPC_FUNC_IMPL(__imp__sub_821DC9A0) {
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
	ctx.lr = 0x821DC9A8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x821dca48
	if (!cr6.gt) goto loc_821DCA48;
	// li r30,0
	r30.s64 = 0;
loc_821DC9C8:
	// li r31,0
	r31.s64 = 0;
loc_821DC9CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DC9D4;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DC9E4;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dca40
	if (!cr6.eq) goto loc_821DCA40;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCA00;
	sub_821DBD48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de058
	ctx.lr = 0x821DCA08;
	sub_823DE058(ctx, base);
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// stfsx f0,r10,r28
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, temp.u32);
	// blt cr6,0x821dc9cc
	if (cr6.lt) goto loc_821DC9CC;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// blt cr6,0x821dc9c8
	if (cr6.lt) goto loc_821DC9C8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
loc_821DCA40:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r29)
	PPC_STORE_U8(r29.u32 + 1103, r11.u8);
loc_821DCA48:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DCA54"))) PPC_WEAK_FUNC(sub_821DCA54);
PPC_FUNC_IMPL(__imp__sub_821DCA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCA58"))) PPC_WEAK_FUNC(sub_821DCA58);
PPC_FUNC_IMPL(__imp__sub_821DCA58) {
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
	ctx.lr = 0x821DCA60;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x821dcb00
	if (!cr6.gt) goto loc_821DCB00;
	// li r30,0
	r30.s64 = 0;
loc_821DCA80:
	// li r31,0
	r31.s64 = 0;
loc_821DCA84:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DCA8C;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCA9C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dcaf8
	if (!cr6.eq) goto loc_821DCAF8;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCAB8;
	sub_821DBD48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de058
	ctx.lr = 0x821DCAC0;
	sub_823DE058(ctx, base);
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// stfsx f0,r10,r28
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, temp.u32);
	// blt cr6,0x821dca84
	if (cr6.lt) goto loc_821DCA84;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// blt cr6,0x821dca80
	if (cr6.lt) goto loc_821DCA80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
loc_821DCAF8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r29)
	PPC_STORE_U8(r29.u32 + 1103, r11.u8);
loc_821DCB00:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DCB0C"))) PPC_WEAK_FUNC(sub_821DCB0C);
PPC_FUNC_IMPL(__imp__sub_821DCB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCB10"))) PPC_WEAK_FUNC(sub_821DCB10);
PPC_FUNC_IMPL(__imp__sub_821DCB10) {
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
	ctx.lr = 0x821DCB18;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x821dcbb8
	if (!cr6.gt) goto loc_821DCBB8;
	// li r30,0
	r30.s64 = 0;
loc_821DCB38:
	// li r31,0
	r31.s64 = 0;
loc_821DCB3C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DCB44;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCB54;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dcbb0
	if (!cr6.eq) goto loc_821DCBB0;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCB70;
	sub_821DBD48(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de058
	ctx.lr = 0x821DCB78;
	sub_823DE058(ctx, base);
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// stfsx f0,r10,r28
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, temp.u32);
	// blt cr6,0x821dcb3c
	if (cr6.lt) goto loc_821DCB3C;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// blt cr6,0x821dcb38
	if (cr6.lt) goto loc_821DCB38;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
loc_821DCBB0:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r29)
	PPC_STORE_U8(r29.u32 + 1103, r11.u8);
loc_821DCBB8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DCBC4"))) PPC_WEAK_FUNC(sub_821DCBC4);
PPC_FUNC_IMPL(__imp__sub_821DCBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCBC8"))) PPC_WEAK_FUNC(sub_821DCBC8);
PPC_FUNC_IMPL(__imp__sub_821DCBC8) {
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
	ctx.lr = 0x821DCBD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lbz r10,1100(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1100);
	// stb r11,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, r11.u8);
	// stb r11,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r11.u8);
	// stw r11,1108(r31)
	PPC_STORE_U32(r31.u32 + 1108, r11.u32);
	// stb r11,1104(r31)
	PPC_STORE_U8(r31.u32 + 1104, r11.u8);
	// beq cr6,0x821dcc08
	if (cr6.eq) goto loc_821DCC08;
	// stb r11,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821DCC08:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r29,1
	r29.s64 = 1;
	// addi r28,r10,24096
	r28.s64 = ctx.r10.s64 + 24096;
	// addi r27,r11,24092
	r27.s64 = r11.s64 + 24092;
loc_821DCC1C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dbeb0
	ctx.lr = 0x821DCC28;
	sub_821DBEB0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,47
	ctx.r4.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCC38;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dcc58
	if (cr6.eq) goto loc_821DCC58;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// bl 0x821dbeb0
	ctx.lr = 0x821DCC54;
	sub_821DBEB0(ctx, base);
	// b 0x821dcccc
	goto loc_821DCCCC;
loc_821DCC58:
	// li r11,32
	r11.s64 = 32;
loc_821DCC5C:
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821dcc84
	if (!cr6.gt) goto loc_821DCC84;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dccb8
	goto loc_821DCCB8;
loc_821DCC84:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dccac
	if (!cr6.lt) goto loc_821DCCAC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dccb4
	goto loc_821DCCB4;
loc_821DCCAC:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DCCB4;
	sub_821BE4F0(ctx, base);
loc_821DCCB4:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_821DCCB8:
	// cmpwi cr6,r11,62
	cr6.compare<int32_t>(r11.s32, 62, xer);
	// bne cr6,0x821dcc5c
	if (!cr6.eq) goto loc_821DCC5C;
	// cmpwi cr6,r30,47
	cr6.compare<int32_t>(r30.s32, 47, xer);
	// beq cr6,0x821dcccc
	if (cr6.eq) goto loc_821DCCCC;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_821DCCCC:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bgt cr6,0x821dcc1c
	if (cr6.gt) goto loc_821DCC1C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821DCCDC"))) PPC_WEAK_FUNC(sub_821DCCDC);
PPC_FUNC_IMPL(__imp__sub_821DCCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCCE0"))) PPC_WEAK_FUNC(sub_821DCCE0);
PPC_FUNC_IMPL(__imp__sub_821DCCE0) {
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
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9850
	ctx.lr = 0x821DCD00;
	sub_821C9850(ctx, base);
	// lhz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821dcd34
	if (cr6.eq) goto loc_821DCD34;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x821DCD28;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x821dcd38
	if (!cr6.eq) goto loc_821DCD38;
loc_821DCD34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821DCD38:
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

__attribute__((alias("__imp__sub_821DCD4C"))) PPC_WEAK_FUNC(sub_821DCD4C);
PPC_FUNC_IMPL(__imp__sub_821DCD4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCD50"))) PPC_WEAK_FUNC(sub_821DCD50);
PPC_FUNC_IMPL(__imp__sub_821DCD50) {
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
	ctx.lr = 0x821DCD58;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821dce14
	if (!cr6.gt) goto loc_821DCE14;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821DCD74:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DCD7C;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCD8C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dce0c
	if (!cr6.eq) goto loc_821DCE0C;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCDA8;
	sub_821DBD48(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// ble cr6,0x821dcddc
	if (!cr6.gt) goto loc_821DCDDC;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x821dcddc
	if (!cr6.eq) goto loc_821DCDDC;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,120
	cr6.compare<uint32_t>(r11.u32, 120, xer);
	// bne cr6,0x821dcddc
	if (!cr6.eq) goto loc_821DCDDC;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// bl 0x823ddf40
	ctx.lr = 0x821DCDD8;
	sub_823DDF40(ctx, base);
	// b 0x821dcdec
	goto loc_821DCDEC;
loc_821DCDDC:
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823ddf20
	ctx.lr = 0x821DCDEC;
	sub_823DDF20(ctx, base);
loc_821DCDEC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x821dcd74
	if (cr6.lt) goto loc_821DCD74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_821DCE0C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r28)
	PPC_STORE_U8(r28.u32 + 1103, r11.u8);
loc_821DCE14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DCE20"))) PPC_WEAK_FUNC(sub_821DCE20);
PPC_FUNC_IMPL(__imp__sub_821DCE20) {
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
	ctx.lr = 0x821DCE28;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x821dcee0
	if (!cr6.gt) goto loc_821DCEE0;
loc_821DCE44:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DCE4C;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCE5C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dced8
	if (!cr6.eq) goto loc_821DCED8;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCE78;
	sub_821DBD48(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// ble cr6,0x821dceac
	if (!cr6.gt) goto loc_821DCEAC;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x821dceac
	if (!cr6.eq) goto loc_821DCEAC;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,120
	cr6.compare<uint32_t>(r11.u32, 120, xer);
	// bne cr6,0x821dceac
	if (!cr6.eq) goto loc_821DCEAC;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// bl 0x823ddf40
	ctx.lr = 0x821DCEA8;
	sub_823DDF40(ctx, base);
	// b 0x821dcebc
	goto loc_821DCEBC;
loc_821DCEAC:
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823ddf20
	ctx.lr = 0x821DCEBC;
	sub_823DDF20(ctx, base);
loc_821DCEBC:
	// stbx r3,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x821dce44
	if (cr6.lt) goto loc_821DCE44;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_821DCED8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r29)
	PPC_STORE_U8(r29.u32 + 1103, r11.u8);
loc_821DCEE0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DCEEC"))) PPC_WEAK_FUNC(sub_821DCEEC);
PPC_FUNC_IMPL(__imp__sub_821DCEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DCEF0"))) PPC_WEAK_FUNC(sub_821DCEF0);
PPC_FUNC_IMPL(__imp__sub_821DCEF0) {
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
	ctx.lr = 0x821DCEF8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821dcfb4
	if (!cr6.gt) goto loc_821DCFB4;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821DCF14:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DCF1C;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,60
	ctx.r4.s64 = 60;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DCF2C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dcfac
	if (!cr6.eq) goto loc_821DCFAC;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DCF48;
	sub_821DBD48(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// ble cr6,0x821dcf7c
	if (!cr6.gt) goto loc_821DCF7C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x821dcf7c
	if (!cr6.eq) goto loc_821DCF7C;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,120
	cr6.compare<uint32_t>(r11.u32, 120, xer);
	// bne cr6,0x821dcf7c
	if (!cr6.eq) goto loc_821DCF7C;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// bl 0x823ddf40
	ctx.lr = 0x821DCF78;
	sub_823DDF40(ctx, base);
	// b 0x821dcf8c
	goto loc_821DCF8C;
loc_821DCF7C:
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823ddf20
	ctx.lr = 0x821DCF8C;
	sub_823DDF20(ctx, base);
loc_821DCF8C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// sth r3,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r3.u16);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x821dcf14
	if (cr6.lt) goto loc_821DCF14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_821DCFAC:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r28)
	PPC_STORE_U8(r28.u32 + 1103, r11.u8);
loc_821DCFB4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DCFC0"))) PPC_WEAK_FUNC(sub_821DCFC0);
PPC_FUNC_IMPL(__imp__sub_821DCFC0) {
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
	// lis r31,-32130
	r31.s64 = -2105671680;
	// addi r30,r31,-30104
	r30.s64 = r31.s64 + -30104;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821DCFE4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// sth r10,8(r30)
	PPC_STORE_U16(r30.u32 + 8, ctx.r10.u16);
	// sth r9,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r9.u16);
	// stb r11,-30104(r31)
	PPC_STORE_U8(r31.u32 + -30104, r11.u8);
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

__attribute__((alias("__imp__sub_821DD01C"))) PPC_WEAK_FUNC(sub_821DD01C);
PPC_FUNC_IMPL(__imp__sub_821DD01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DD020"))) PPC_WEAK_FUNC(sub_821DD020);
PPC_FUNC_IMPL(__imp__sub_821DD020) {
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
	ctx.lr = 0x821DD028;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd0ec
	if (cr6.eq) goto loc_821DD0EC;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_821DD044:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,115
	cr6.compare<int32_t>(r11.s32, 115, xer);
	// bne cr6,0x821dd060
	if (!cr6.eq) goto loc_821DD060;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DD05C;
	sub_821DBF78(ctx, base);
	// b 0x821dd0dc
	goto loc_821DD0DC;
loc_821DD060:
	// cmpwi cr6,r11,83
	cr6.compare<int32_t>(r11.s32, 83, xer);
	// bne cr6,0x821dd07c
	if (!cr6.eq) goto loc_821DD07C;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc038
	ctx.lr = 0x821DD078;
	sub_821DC038(ctx, base);
	// b 0x821dd0dc
	goto loc_821DD0DC;
loc_821DD07C:
	// cmpwi cr6,r11,119
	cr6.compare<int32_t>(r11.s32, 119, xer);
	// bne cr6,0x821dd098
	if (!cr6.eq) goto loc_821DD098;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DD094;
	sub_821DBD48(ctx, base);
	// b 0x821dd0dc
	goto loc_821DD0DC;
loc_821DD098:
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dd0b8
	if (!cr6.gt) goto loc_821DD0B8;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r11,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, r11.u32);
	// b 0x821dd0dc
	goto loc_821DD0DC;
loc_821DD0B8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821dd0d8
	if (!cr6.lt) goto loc_821DD0D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// b 0x821dd0dc
	goto loc_821DD0DC;
loc_821DD0D8:
	// bl 0x821be4f0
	ctx.lr = 0x821DD0DC;
	sub_821BE4F0(ctx, base);
loc_821DD0DC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd044
	if (!cr6.eq) goto loc_821DD044;
loc_821DD0EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DD0F8"))) PPC_WEAK_FUNC(sub_821DD0F8);
PPC_FUNC_IMPL(__imp__sub_821DD0F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x821DD100;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,1
	r26.s64 = 1;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,11
	cr6.compare<uint32_t>(ctx.r6.u32, 11, xer);
	// stb r26,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r26.u8);
	// bgt cr6,0x821dd308
	if (cr6.gt) goto loc_821DD308;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-11976
	r12.s64 = r12.s64 + -11976;
	// rlwinm r0,r6,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r6.u64) {
	case 0:
		goto loc_821DD168;
	case 1:
		goto loc_821DD168;
	case 2:
		goto loc_821DD210;
	case 3:
		goto loc_821DD230;
	case 4:
		goto loc_821DD308;
	case 5:
		goto loc_821DD248;
	case 6:
		goto loc_821DD264;
	case 7:
		goto loc_821DD27C;
	case 8:
		goto loc_821DD298;
	case 9:
		goto loc_821DD2B4;
	case 10:
		goto loc_821DD2D0;
	case 11:
		goto loc_821DD2EC;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-11928(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11928);
	// lwz r16,-11928(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11928);
	// lwz r16,-11760(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11760);
	// lwz r16,-11728(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11728);
	// lwz r16,-11512(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11512);
	// lwz r16,-11704(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11704);
	// lwz r16,-11676(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11676);
	// lwz r16,-11652(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11652);
	// lwz r16,-11624(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11624);
	// lwz r16,-11596(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11596);
	// lwz r16,-11568(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11568);
	// lwz r16,-11540(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -11540);
loc_821DD168:
	// li r27,0
	r27.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// bl 0x821daab0
	ctx.lr = 0x821DD178;
	sub_821DAAB0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821dd1b0
	if (cr6.eq) goto loc_821DD1B0;
loc_821DD180:
	// cmpwi cr6,r3,60
	cr6.compare<int32_t>(ctx.r3.s32, 60, xer);
	// beq cr6,0x821dd1b0
	if (cr6.eq) goto loc_821DD1B0;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x821dd1b0
	if (!cr6.lt) goto loc_821DD1B0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stbx r11,r30,r29
	PPC_STORE_U8(r30.u32 + r29.u32, r11.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x821daab0
	ctx.lr = 0x821DD1A8;
	sub_821DAAB0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x821dd180
	if (!cr6.eq) goto loc_821DD180;
loc_821DD1B0:
	// cmpwi cr6,r3,60
	cr6.compare<int32_t>(ctx.r3.s32, 60, xer);
	// stbx r27,r30,r29
	PPC_STORE_U8(r30.u32 + r29.u32, r27.u8);
	// bne cr6,0x821dd1e8
	if (!cr6.eq) goto loc_821DD1E8;
	// lwz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// li r9,60
	ctx.r9.s64 = 60;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r27,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD1E8:
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x821dd204
	if (!cr6.eq) goto loc_821DD204;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dba28
	ctx.lr = 0x821DD200;
	sub_821DBA28(ctx, base);
	// stb r26,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r26.u8);
loc_821DD204:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD210:
	// rlwinm r11,r28,31,1,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc7a0
	ctx.lr = 0x821DD224;
	sub_821DC7A0(ctx, base);
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD230:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc330
	ctx.lr = 0x821DD240;
	sub_821DC330(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD248:
	// rlwinm r5,r28,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dcd50
	ctx.lr = 0x821DD258;
	sub_821DCD50(ctx, base);
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD264:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dce20
	ctx.lr = 0x821DD274;
	sub_821DCE20(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD27C:
	// rlwinm r5,r28,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dcef0
	ctx.lr = 0x821DD28C;
	sub_821DCEF0(ctx, base);
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD298:
	// rlwinm r5,r28,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc908
	ctx.lr = 0x821DD2A8;
	sub_821DC908(ctx, base);
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD2B4:
	// rlwinm r5,r28,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc9a0
	ctx.lr = 0x821DD2C4;
	sub_821DC9A0(ctx, base);
	// rlwinm r3,r3,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD2D0:
	// rlwinm r5,r28,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 28) & 0xFFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dca58
	ctx.lr = 0x821DD2E0;
	sub_821DCA58(ctx, base);
	// rlwinm r3,r3,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD2EC:
	// rlwinm r5,r28,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 28) & 0xFFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dcb10
	ctx.lr = 0x821DD2FC;
	sub_821DCB10(ctx, base);
	// rlwinm r3,r3,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821DD308:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DD314"))) PPC_WEAK_FUNC(sub_821DD314);
PPC_FUNC_IMPL(__imp__sub_821DD314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DD318"))) PPC_WEAK_FUNC(sub_821DD318);
PPC_FUNC_IMPL(__imp__sub_821DD318) {
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
	ctx.lr = 0x821DD320;
	// stwu r1,-1408(r1)
	ea = -1408 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c7190
	ctx.lr = 0x821DD334;
	sub_821C7190(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24108
	ctx.r4.s64 = r11.s64 + 24108;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x821DD348;
	sub_821DBBC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821dd360
	if (cr6.eq) goto loc_821DD360;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9230
	return;
loc_821DD360:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,24104
	ctx.r4.s64 = r11.s64 + 24104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dd020
	ctx.lr = 0x821DD374;
	sub_821DD020(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DD384;
	sub_821DBD48(ctx, base);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,-30104
	r29.s64 = r11.s64 + -30104;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821dcce0
	ctx.lr = 0x821DD3A0;
	sub_821DCCE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821dd3b0
	if (cr6.eq) goto loc_821DD3B0;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x821dd3b4
	goto loc_821DD3B4;
loc_821DD3B0:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
loc_821DD3B4:
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x821c6a20
	ctx.lr = 0x821DD3C4;
	sub_821C6A20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DD3CC;
	sub_821DBF78(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,1112(r30)
	PPC_STORE_U32(r30.u32 + 1112, r27.u32);
	// li r4,62
	ctx.r4.s64 = 62;
	// stw r27,1116(r30)
	PPC_STORE_U32(r30.u32 + 1116, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r27,1108(r30)
	PPC_STORE_U32(r30.u32 + 1108, r27.u32);
	// bl 0x821db8e8
	ctx.lr = 0x821DD3EC;
	sub_821DB8E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r22,r11,24040
	r22.s64 = r11.s64 + 24040;
	// bne cr6,0x821dd5fc
	if (!cr6.eq) goto loc_821DD5FC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r23,1
	r23.s64 = 1;
	// addi r26,r11,23488
	r26.s64 = r11.s64 + 23488;
	// addi r25,r10,-13292
	r25.s64 = ctx.r10.s64 + -13292;
	// addi r24,r9,24100
	r24.s64 = ctx.r9.s64 + 24100;
loc_821DD41C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x821DD42C;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd5fc
	if (!cr6.eq) goto loc_821DD5FC;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbd48
	ctx.lr = 0x821DD448;
	sub_821DBD48(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dd020
	ctx.lr = 0x821DD458;
	sub_821DD020(ctx, base);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dad18
	ctx.lr = 0x821DD464;
	sub_821DAD18(ctx, base);
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd4b4
	if (cr6.eq) goto loc_821DD4B4;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_821DD478:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dd49c
	if (cr6.eq) goto loc_821DD49C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dd478
	if (cr6.eq) goto loc_821DD478;
loc_821DD49C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dd4b4
	if (!cr6.eq) goto loc_821DD4B4;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x821e45e8
	ctx.lr = 0x821DD4AC;
	sub_821E45E8(ctx, base);
	// stw r3,1108(r30)
	PPC_STORE_U32(r30.u32 + 1108, ctx.r3.u32);
	// stb r23,1104(r30)
	PPC_STORE_U8(r30.u32 + 1104, r23.u8);
loc_821DD4B4:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd510
	if (cr6.eq) goto loc_821DD510;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_821DD4C8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821dd4ec
	if (cr6.eq) goto loc_821DD4EC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821dd4c8
	if (cr6.eq) goto loc_821DD4C8;
loc_821DD4EC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821dd510
	if (!cr6.eq) goto loc_821DD510;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4118
	ctx.lr = 0x821DD500;
	sub_821D4118(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x821d41d0
	ctx.lr = 0x821DD50C;
	sub_821D41D0(ctx, base);
	// b 0x821dd5d8
	goto loc_821DD5D8;
loc_821DD510:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9850
	ctx.lr = 0x821DD51C;
	sub_821C9850(ctx, base);
	// lhz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821dd550
	if (cr6.eq) goto loc_821DD550;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823de288
	ctx.lr = 0x821DD544;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x821dd554
	if (!cr6.eq) goto loc_821DD554;
loc_821DD550:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_821DD554:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x821c9850
	ctx.lr = 0x821DD560;
	sub_821C9850(ctx, base);
	// lhz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821dd5a4
	if (cr6.eq) goto loc_821DD5A4;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823de288
	ctx.lr = 0x821DD588;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821dd5a4
	if (cr6.eq) goto loc_821DD5A4;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd5a8
	if (cr6.eq) goto loc_821DD5A8;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821dd5ac
	goto loc_821DD5AC;
loc_821DD5A4:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821DD5A8:
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
loc_821DD5AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821dd5bc
	if (cr6.eq) goto loc_821DD5BC;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x821dd5c0
	goto loc_821DD5C0;
loc_821DD5BC:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
loc_821DD5C0:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r31
	ctx.r10.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r7,r11,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c7000
	ctx.lr = 0x821DD5D8;
	sub_821C7000(ctx, base);
loc_821DD5D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbf78
	ctx.lr = 0x821DD5E0;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,62
	ctx.r4.s64 = 62;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DD5F0;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd41c
	if (cr6.eq) goto loc_821DD41C;
loc_821DD5FC:
	// lbz r11,68(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd61c
	if (!cr6.eq) goto loc_821DD61C;
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// ble cr6,0x821dd61c
	if (!cr6.gt) goto loc_821DD61C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c7cc0
	ctx.lr = 0x821DD61C;
	sub_821C7CC0(ctx, base);
loc_821DD61C:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,62
	ctx.r4.s64 = 62;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x821DD62C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd644
	if (cr6.eq) goto loc_821DD644;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9230
	return;
loc_821DD644:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x821DD654;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821DD66C"))) PPC_WEAK_FUNC(sub_821DD66C);
PPC_FUNC_IMPL(__imp__sub_821DD66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DD670"))) PPC_WEAK_FUNC(sub_821DD670);
PPC_FUNC_IMPL(__imp__sub_821DD670) {
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
	// bl 0x821dd318
	ctx.lr = 0x821DD688;
	sub_821DD318(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd6a8
	if (!cr6.eq) goto loc_821DD6A8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,24112
	ctx.r4.s64 = r11.s64 + 24112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dd020
	ctx.lr = 0x821DD6A8;
	sub_821DD020(ctx, base);
loc_821DD6A8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r11.u8);
	// stb r11,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, r11.u8);
	// stb r11,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, r11.u8);
	// stb r11,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r11.u8);
	// stw r11,1108(r31)
	PPC_STORE_U32(r31.u32 + 1108, r11.u32);
	// stb r11,1104(r31)
	PPC_STORE_U8(r31.u32 + 1104, r11.u8);
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

__attribute__((alias("__imp__sub_821DD6D8"))) PPC_WEAK_FUNC(sub_821DD6D8);
PPC_FUNC_IMPL(__imp__sub_821DD6D8) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lbz r11,1100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd708
	if (!cr6.eq) goto loc_821DD708;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r4,r11,24112
	ctx.r4.s64 = r11.s64 + 24112;
	// bl 0x821dd020
	ctx.lr = 0x821DD708;
	sub_821DD020(ctx, base);
loc_821DD708:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r11.u8);
	// stb r11,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, r11.u8);
	// stb r11,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, r11.u8);
	// stb r11,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r11.u8);
	// stw r11,1108(r31)
	PPC_STORE_U32(r31.u32 + 1108, r11.u32);
	// stb r11,1104(r31)
	PPC_STORE_U8(r31.u32 + 1104, r11.u8);
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

__attribute__((alias("__imp__sub_821DD738"))) PPC_WEAK_FUNC(sub_821DD738);
PPC_FUNC_IMPL(__imp__sub_821DD738) {
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
	// lbz r11,1100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd7bc
	if (!cr6.eq) goto loc_821DD7BC;
	// lbz r11,1101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd77c
	if (!cr6.eq) goto loc_821DD77C;
	// lbz r11,1102(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1102);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd7bc
	if (cr6.eq) goto loc_821DD7BC;
	// lbz r11,1103(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1103);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dd7bc
	if (cr6.eq) goto loc_821DD7BC;
loc_821DD77C:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x821dd788
	if (!cr6.eq) goto loc_821DD788;
	// lwz r6,1108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1108);
loc_821DD788:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dd0f8
	ctx.lr = 0x821DD790;
	sub_821DD0F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r11.u8);
	// stb r10,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, ctx.r10.u8);
	// stb r11,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, r11.u8);
	// stb r11,1104(r31)
	PPC_STORE_U8(r31.u32 + 1104, r11.u8);
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
loc_821DD7BC:
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

__attribute__((alias("__imp__sub_821DD7D4"))) PPC_WEAK_FUNC(sub_821DD7D4);
PPC_FUNC_IMPL(__imp__sub_821DD7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DD7D8"))) PPC_WEAK_FUNC(sub_821DD7D8);
PPC_FUNC_IMPL(__imp__sub_821DD7D8) {
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
	// lwz r11,1096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821dd810
	if (!cr6.gt) goto loc_821DD810;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r10.u32);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821dd844
	goto loc_821DD844;
loc_821DD810:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821dd838
	if (!cr6.lt) goto loc_821DD838;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821dd844
	goto loc_821DD844;
loc_821DD838:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DD840;
	sub_821BE4F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_821DD844:
	// cmpwi cr6,r10,239
	cr6.compare<int32_t>(ctx.r10.s32, 239, xer);
	// bne cr6,0x821dd864
	if (!cr6.eq) goto loc_821DD864;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,24120
	ctx.r4.s64 = r11.s64 + 24120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dd020
	ctx.lr = 0x821DD860;
	sub_821DD020(ctx, base);
	// b 0x821dd878
	goto loc_821DD878;
loc_821DD864:
	// lwz r9,1096(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1096);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r8.u32);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
loc_821DD878:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dc038
	ctx.lr = 0x821DD888;
	sub_821DC038(ctx, base);
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

__attribute__((alias("__imp__sub_821DD89C"))) PPC_WEAK_FUNC(sub_821DD89C);
PPC_FUNC_IMPL(__imp__sub_821DD89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DD8A0"))) PPC_WEAK_FUNC(sub_821DD8A0);
PPC_FUNC_IMPL(__imp__sub_821DD8A0) {
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
	ctx.lr = 0x821DD8A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r28,r11,-30416
	r28.s64 = r11.s64 + -30416;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r10,-30104
	r29.s64 = ctx.r10.s64 + -30104;
	// lwz r3,-30416(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -30416);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821dd914
	if (cr6.eq) goto loc_821DD914;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_821DD8D0:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9850
	ctx.lr = 0x821DD8D8;
	sub_821C9850(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x821DD8F0;
	sub_824787B0(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// lwzx r3,r11,r28
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821dd8d0
	if (!cr6.eq) goto loc_821DD8D0;
loc_821DD914:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dd948
	if (!cr6.eq) goto loc_821DD948;
	// lhz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821dd940
	if (cr6.eq) goto loc_821DD940;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x821DD940;
	sub_823DCF08(ctx, base);
loc_821DD940:
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
loc_821DD948:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821DD950"))) PPC_WEAK_FUNC(sub_821DD950);
PPC_FUNC_IMPL(__imp__sub_821DD950) {
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
	// lwz r11,1120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821dd97c
	if (!cr6.eq) goto loc_821DD97C;
	// bl 0x821dd7d8
	ctx.lr = 0x821DD97C;
	sub_821DD7D8(ctx, base);
loc_821DD97C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dd318
	ctx.lr = 0x821DD988;
	sub_821DD318(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r3,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, ctx.r3.u8);
	// stb r11,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, r11.u8);
	// stb r10,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, ctx.r10.u8);
	// stb r11,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r11.u8);
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

__attribute__((alias("__imp__sub_821DD9B8"))) PPC_WEAK_FUNC(sub_821DD9B8);
PPC_FUNC_IMPL(__imp__sub_821DD9B8) {
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
	ctx.lr = 0x821DD9C0;
	// addi r31,r1,-1296
	r31.s64 = ctx.r1.s64 + -1296;
	// stwu r1,-1296(r1)
	ea = -1296 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821dd7d8
	ctx.lr = 0x821DD9D0;
	sub_821DD7D8(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x821DD9E0;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r27,r28
	r27.u64 = r28.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// mr r23,r28
	r23.u64 = r28.u64;
	// li r26,1
	r26.s64 = 1;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// li r24,60
	r24.s64 = 60;
	// addi r22,r11,24124
	r22.s64 = r11.s64 + 24124;
	// addi r21,r10,24108
	r21.s64 = ctx.r10.s64 + 24108;
loc_821DDA10:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// addi r4,r31,176
	ctx.r4.s64 = r31.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dc038
	ctx.lr = 0x821DDA20;
	sub_821DC038(ctx, base);
	// lbz r11,1104(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1104);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ddab0
	if (cr6.eq) goto loc_821DDAB0;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x821DDA40;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ddab0
	if (cr6.eq) goto loc_821DDAB0;
	// addic. r11,r29,-1
	xer.ca = r29.u32 > 0;
	r11.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x821dda78
	if (!cr0.lt) goto loc_821DDA78;
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821DDA5C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821dda5c
	if (!cr6.eq) goto loc_821DDA5C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
loc_821DDA78:
	// addic. r10,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r10.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x821ddaac
	if (cr0.lt) goto loc_821DDAAC;
	// addi r9,r31,176
	ctx.r9.s64 = r31.s64 + 176;
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_821DDA8C:
	// lwz r9,1024(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1024);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1024(r11)
	PPC_STORE_U32(r11.u32 + 1024, ctx.r6.u32);
	// stbx r7,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r7.u8);
	// bge 0x821dda8c
	if (!cr0.lt) goto loc_821DDA8C;
loc_821DDAAC:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_821DDAB0:
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ddad4
	if (!cr6.gt) goto loc_821DDAD4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r10.u32);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821ddb08
	goto loc_821DDB08;
loc_821DDAD4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821ddafc
	if (!cr6.lt) goto loc_821DDAFC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821ddb08
	goto loc_821DDB08;
loc_821DDAFC:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DDB04;
	sub_821BE4F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_821DDB08:
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x821ddd90
	if (cr6.eq) goto loc_821DDD90;
	// cmpwi cr6,r10,60
	cr6.compare<int32_t>(ctx.r10.s32, 60, xer);
	// bne cr6,0x821ddcb8
	if (!cr6.eq) goto loc_821DDCB8;
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ddb3c
	if (!cr6.gt) goto loc_821DDB3C;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r10.u32);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// b 0x821ddb70
	goto loc_821DDB70;
loc_821DDB3C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821ddb64
	if (!cr6.lt) goto loc_821DDB64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x821ddb70
	goto loc_821DDB70;
loc_821DDB64:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x821DDB6C;
	sub_821BE4F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_821DDB70:
	// cmpwi cr6,r10,47
	cr6.compare<int32_t>(ctx.r10.s32, 47, xer);
	// bne cr6,0x821ddbcc
	if (!cr6.eq) goto loc_821DDBCC;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r31,112
	ctx.r5.s64 = r31.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dd020
	ctx.lr = 0x821DDB88;
	sub_821DD020(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bne 0x821ddb98
	if (!cr0.eq) goto loc_821DDB98;
	// mr r23,r26
	r23.u64 = r26.u64;
	// b 0x821ddba8
	goto loc_821DDBA8;
loc_821DDB98:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dc038
	ctx.lr = 0x821DDBA8;
	sub_821DC038(ctx, base);
loc_821DDBA8:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r30,28
	ctx.r3.s64 = r30.s64 + 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DDBBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,1101(r30)
	PPC_STORE_U8(r30.u32 + 1101, r28.u8);
	// stb r28,1102(r30)
	PPC_STORE_U8(r30.u32 + 1102, r28.u8);
	// stb r28,1104(r30)
	PPC_STORE_U8(r30.u32 + 1104, r28.u8);
	// b 0x821ddd84
	goto loc_821DDD84;
loc_821DDBCC:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,1096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r8,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r8.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r10,1096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r7.u32);
	// stbx r24,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, r24.u8);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
	// stb r28,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r28.u8);
	// stw r28,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r28.u32);
	// sth r28,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r28.u16);
	// sth r28,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r28.u16);
	// bl 0x821d40e8
	ctx.lr = 0x821DDC10;
	sub_821D40E8(ctx, base);
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dd318
	ctx.lr = 0x821DDC1C;
	sub_821DD318(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821ddc88
	if (cr6.eq) goto loc_821DDC88;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x821ddc38
	if (!cr6.eq) goto loc_821DDC38;
	// mr r23,r26
	r23.u64 = r26.u64;
	// b 0x821ddc48
	goto loc_821DDC48;
loc_821DDC38:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dc038
	ctx.lr = 0x821DDC48;
	sub_821DC038(ctx, base);
loc_821DDC48:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DDC60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r30,28
	ctx.r3.s64 = r30.s64 + 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821DDC74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,1101(r30)
	PPC_STORE_U8(r30.u32 + 1101, r28.u8);
	// stb r28,1102(r30)
	PPC_STORE_U8(r30.u32 + 1102, r28.u8);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x821c6f88
	ctx.lr = 0x821DDC84;
	sub_821C6F88(ctx, base);
	// b 0x821ddd84
	goto loc_821DDD84;
loc_821DDC88:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DDCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r26,1101(r30)
	PPC_STORE_U8(r30.u32 + 1101, r26.u8);
	// stb r28,1102(r30)
	PPC_STORE_U8(r30.u32 + 1102, r28.u8);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x821c6f88
	ctx.lr = 0x821DDCB4;
	sub_821C6F88(ctx, base);
	// b 0x821ddd84
	goto loc_821DDD84;
loc_821DDCB8:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,1096(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r8,1096(r30)
	PPC_STORE_U32(r30.u32 + 1096, ctx.r8.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// ble cr6,0x821ddd34
	if (!cr6.gt) goto loc_821DDD34;
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x821ddd04
	if (!cr0.lt) goto loc_821DDD04;
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_821DDCE8:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821ddce8
	if (!cr6.eq) goto loc_821DDCE8;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
loc_821DDD04:
	// addic. r9,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x821ddd34
	if (cr0.lt) goto loc_821DDD34;
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_821DDD14:
	// lwz r10,1024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1024);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,1024(r11)
	PPC_STORE_U32(r11.u32 + 1024, ctx.r6.u32);
	// stbx r7,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r7.u8);
	// bge 0x821ddd14
	if (!cr0.lt) goto loc_821DDD14;
loc_821DDD34:
	// addi r29,r30,44
	r29.s64 = r30.s64 + 44;
	// stb r28,1101(r30)
	PPC_STORE_U8(r30.u32 + 1101, r28.u8);
	// stb r26,1103(r30)
	PPC_STORE_U8(r30.u32 + 1103, r26.u8);
	// stb r28,1104(r30)
	PPC_STORE_U8(r30.u32 + 1104, r28.u8);
loc_821DDD44:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r6,1108(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 1108);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,60(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// bl 0x821dd0f8
	ctx.lr = 0x821DDD58;
	sub_821DD0F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lbz r6,1103(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 1103);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DDD74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,1103(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 1103);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ddd44
	if (!cr6.eq) goto loc_821DDD44;
	// stb r26,1102(r30)
	PPC_STORE_U8(r30.u32 + 1102, r26.u8);
loc_821DDD84:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dda10
	if (cr6.eq) goto loc_821DDA10;
loc_821DDD90:
	// addi r1,r31,1296
	ctx.r1.s64 = r31.s64 + 1296;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821DDD98"))) PPC_WEAK_FUNC(sub_821DDD98);
PPC_FUNC_IMPL(__imp__sub_821DDD98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r4,1,15,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// rlwinm r10,r4,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r5,70
	ctx.r6.s64 = ctx.r5.s64 + 70;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwimi r6,r5,11,0,20
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 11) & 0xFFFFF800) | (ctx.r6.u64 & 0xFFFFFFFF000007FF);
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// sthx r7,r9,r6
	PPC_STORE_U16(ctx.r9.u32 + ctx.r6.u32, ctx.r7.u16);
	// lhzx r8,r10,r3
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// sth r8,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r8.u16);
	// lhzx r11,r10,r3
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821dde10
	if (cr6.eq) goto loc_821DDE10;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r4,r6,r8
	PPC_STORE_U16(ctx.r6.u32 + ctx.r8.u32, ctx.r4.u16);
loc_821DDE10:
	// addi r11,r5,54
	r11.s64 = ctx.r5.s64 + 54;
	// sthx r4,r10,r3
	PPC_STORE_U16(ctx.r10.u32 + ctx.r3.u32, ctx.r4.u16);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r3
	PPC_STORE_U16(r11.u32 + ctx.r3.u32, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DDE2C"))) PPC_WEAK_FUNC(sub_821DDE2C);
PPC_FUNC_IMPL(__imp__sub_821DDE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DDE30"))) PPC_WEAK_FUNC(sub_821DDE30);
PPC_FUNC_IMPL(__imp__sub_821DDE30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r4,1,15,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lhzx r11,r9,r8
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// lhz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821dde70
	if (cr6.eq) goto loc_821DDE70;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// sth r10,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r10.u16);
	// b 0x821dde7c
	goto loc_821DDE7C;
loc_821DDE70:
	// addi r11,r5,70
	r11.s64 = ctx.r5.s64 + 70;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r9,r3
	PPC_STORE_U16(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u16);
loc_821DDE7C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x821ddea8
	if (cr6.eq) goto loc_821DDEA8;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r7,r4,r10
	PPC_STORE_U16(ctx.r4.u32 + ctx.r10.u32, ctx.r7.u16);
loc_821DDEA8:
	// lis r11,0
	r11.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r5,54
	ctx.r9.s64 = ctx.r5.s64 + 54;
	// ori r11,r11,65534
	r11.u64 = r11.u64 | 65534;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// sthx r7,r8,r10
	PPC_STORE_U16(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u16);
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// sth r6,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r6.u16);
	// lhzx r4,r11,r3
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// addis r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sthx r10,r11,r3
	PPC_STORE_U16(r11.u32 + ctx.r3.u32, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DDEE8"))) PPC_WEAK_FUNC(sub_821DDEE8);
PPC_FUNC_IMPL(__imp__sub_821DDEE8) {
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
	ctx.lr = 0x821DDEF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// bne cr6,0x821ddf10
	if (!cr6.eq) goto loc_821DDF10;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821DDF10:
	// addi r11,r30,70
	r11.s64 = r30.s64 + 70;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r31,r10,r29
	r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + r29.u32);
	// cmplwi cr6,r31,65535
	cr6.compare<uint32_t>(r31.u32, 65535, xer);
	// beq cr6,0x821ddf40
	if (cr6.eq) goto loc_821DDF40;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821dde30
	ctx.lr = 0x821DDF34;
	sub_821DDE30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821DDF40:
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// bl 0x821ddee8
	ctx.lr = 0x821DDF48;
	sub_821DDEE8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// cmplwi cr6,r31,65535
	cr6.compare<uint32_t>(r31.u32, 65535, xer);
	// beq cr6,0x821ddfa8
	if (cr6.eq) goto loc_821DDFA8;
	// li r11,1
	r11.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// slw r10,r11,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// xor r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 ^ r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// bl 0x821ddd98
	ctx.lr = 0x821DDF74;
	sub_821DDD98(ctx, base);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r31,r11
	ctx.r8.u64 = r31.u64 + r11.u64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r10,r6,21,11,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1FFFFF;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// rlwimi r5,r4,11,16,20
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 11) & 0xF800) | (ctx.r5.u64 & 0xFFFFFFFFFFFF07FF);
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
loc_821DDFA8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821DDFB4"))) PPC_WEAK_FUNC(sub_821DDFB4);
PPC_FUNC_IMPL(__imp__sub_821DDFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DDFB8"))) PPC_WEAK_FUNC(sub_821DDFB8);
PPC_FUNC_IMPL(__imp__sub_821DDFB8) {
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
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// and r10,r11,r4
	ctx.r10.u64 = r11.u64 & ctx.r4.u64;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// ble cr6,0x821ddffc
	if (!cr6.gt) goto loc_821DDFFC;
loc_821DDFEC:
	// rlwinm r4,r4,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// bgt cr6,0x821ddfec
	if (cr6.gt) goto loc_821DDFEC;
loc_821DDFFC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ddee8
	ctx.lr = 0x821DE008;
	sub_821DDEE8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821de0b4
	if (cr6.eq) goto loc_821DE0B4;
	// addi r9,r30,38
	ctx.r9.s64 = r30.s64 + 38;
	// lwz r8,0(r13)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + r31.u32);
	// add r6,r11,r6
	ctx.r6.u64 = r11.u64 + ctx.r6.u64;
	// slw r10,r10,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r30.u8 & 0x3F));
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// li r9,48
	ctx.r9.s64 = 48;
	// sthx r4,r7,r31
	PPC_STORE_U16(ctx.r7.u32 + r31.u32, ctx.r4.u16);
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// add r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// lhz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r7,r7,0,24,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// ori r5,r7,256
	ctx.r5.u64 = ctx.r7.u64 | 256;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwimi r7,r4,4,24,27
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0xF0) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFF0F);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r5,r11,3
	ctx.r5.s64 = r11.s64 + 3;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
loc_821DE0B4:
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

__attribute__((alias("__imp__sub_821DE0CC"))) PPC_WEAK_FUNC(sub_821DE0CC);
PPC_FUNC_IMPL(__imp__sub_821DE0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE0D0"))) PPC_WEAK_FUNC(sub_821DE0D0);
PPC_FUNC_IMPL(__imp__sub_821DE0D0) {
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
	ctx.lr = 0x821DE0D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r26,1
	r26.s64 = 1;
	// clrlwi r29,r27,16
	r29.u64 = r27.u32 & 0xFFFF;
	// rlwinm r11,r27,1,15,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0x1FFFE;
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r27,1,15,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0x1FFFE;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r29,r11
	ctx.r8.u64 = r29.u64 + r11.u64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r30,r6,21,11,31
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1FFFFF;
	// addi r5,r30,38
	ctx.r5.s64 = r30.s64 + 38;
	// slw r4,r26,r30
	ctx.r4.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// xor r8,r4,r29
	ctx.r8.u64 = ctx.r4.u64 ^ r29.u64;
	// clrlwi r31,r8,16
	r31.u64 = ctx.r8.u32 & 0xFFFF;
	// lhzx r7,r11,r3
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// addis r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 65536;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// sthx r6,r11,r3
	PPC_STORE_U16(r11.u32 + ctx.r3.u32, ctx.r6.u16);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// subf r6,r4,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r4.s64;
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// lhz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r5,28,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xF;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// subf r8,r4,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r4.s64;
	// stwx r8,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r8.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r6,r6,0,24,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r31,r5
	cr6.compare<uint32_t>(r31.u32, ctx.r5.u32, xer);
	// bge cr6,0x821de250
	if (!cr6.lt) goto loc_821DE250;
	// lis r11,0
	r11.s64 = 0;
	// ori r28,r11,65534
	r28.u64 = r11.u64 | 65534;
loc_821DE194:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r10,65534
	cr6.compare<uint32_t>(ctx.r10.u32, 65534, xer);
	// beq cr6,0x821de250
	if (cr6.eq) goto loc_821DE250;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r10,r11,21,11,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1FFFFF;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bne cr6,0x821de250
	if (!cr6.eq) goto loc_821DE250;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821dde30
	ctx.lr = 0x821DE1D0;
	sub_821DDE30(ctx, base);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x821de1e4
	if (!cr6.lt) goto loc_821DE1E4;
	// mr r11,r31
	r11.u64 = r31.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_821DE1E4:
	// clrlwi r11,r31,16
	r11.u64 = r31.u32 & 0xFFFF;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r31,1,15,30
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0x1FFFE;
	// rlwinm r10,r31,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0x1FFFE;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// clrlwi r29,r27,16
	r29.u64 = r27.u32 & 0xFFFF;
	// slw r6,r26,r30
	ctx.r6.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// xor r4,r6,r29
	ctx.r4.u64 = ctx.r6.u64 ^ r29.u64;
	// clrlwi r9,r5,21
	ctx.r9.u64 = ctx.r5.u32 & 0x7FF;
	// clrlwi r31,r4,16
	r31.u64 = ctx.r4.u32 & 0xFFFF;
	// ori r8,r9,32768
	ctx.r8.u64 = ctx.r9.u64 | 32768;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// sthx r28,r10,r7
	PPC_STORE_U16(ctx.r10.u32 + ctx.r7.u32, r28.u16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// sth r28,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, r28.u16);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r31,r5
	cr6.compare<uint32_t>(r31.u32, ctx.r5.u32, xer);
	// blt cr6,0x821de194
	if (cr6.lt) goto loc_821DE194;
loc_821DE250:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821ddd98
	ctx.lr = 0x821DE25C;
	sub_821DDD98(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821DE264"))) PPC_WEAK_FUNC(sub_821DE264);
PPC_FUNC_IMPL(__imp__sub_821DE264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE268"))) PPC_WEAK_FUNC(sub_821DE268);
PPC_FUNC_IMPL(__imp__sub_821DE268) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821de2b4
	if (!cr6.lt) goto loc_821DE2B4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r10,r10,21,11,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1FFFFF;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// beq cr6,0x821de2b4
	if (cr6.eq) goto loc_821DE2B4;
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r11,65534
	cr6.compare<uint32_t>(r11.u32, 65534, xer);
	// bne cr6,0x821de2b4
	if (!cr6.eq) goto loc_821DE2B4;
	// li r11,1
	r11.s64 = 1;
	// slw r3,r11,r10
	ctx.r3.u64 = ctx.r10.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r10.u8 & 0x3F));
	// blr 
	return;
loc_821DE2B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DE2BC"))) PPC_WEAK_FUNC(sub_821DE2BC);
PPC_FUNC_IMPL(__imp__sub_821DE2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE2C0"))) PPC_WEAK_FUNC(sub_821DE2C0);
PPC_FUNC_IMPL(__imp__sub_821DE2C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r3,108
	ctx.r8.s64 = ctx.r3.s64 + 108;
loc_821DE2CC:
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bge cr6,0x821de2dc
	if (!cr6.lt) goto loc_821DE2DC;
	// lhz r9,-32(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + -32);
	// b 0x821de2e0
	goto loc_821DE2E0;
loc_821DE2DC:
	// li r9,0
	ctx.r9.s64 = 0;
loc_821DE2E0:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bge cr6,0x821de2f4
	if (!cr6.lt) goto loc_821DE2F4;
	// lhz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// b 0x821de2f8
	goto loc_821DE2F8;
loc_821DE2F4:
	// li r9,0
	ctx.r9.s64 = 0;
loc_821DE2F8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r9,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r9.u32);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// blt cr6,0x821de2cc
	if (cr6.lt) goto loc_821DE2CC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DE314"))) PPC_WEAK_FUNC(sub_821DE314);
PPC_FUNC_IMPL(__imp__sub_821DE314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE318"))) PPC_WEAK_FUNC(sub_821DE318);
PPC_FUNC_IMPL(__imp__sub_821DE318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,15
	r11.s64 = 15;
	// addi r10,r3,170
	ctx.r10.s64 = ctx.r3.s64 + 170;
loc_821DE320:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// bne cr6,0x821de340
	if (!cr6.eq) goto loc_821DE340;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// bge 0x821de320
	if (!cr0.lt) goto loc_821DE320;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821DE340:
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r3,r10,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DE34C"))) PPC_WEAK_FUNC(sub_821DE34C);
PPC_FUNC_IMPL(__imp__sub_821DE34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE350"))) PPC_WEAK_FUNC(sub_821DE350);
PPC_FUNC_IMPL(__imp__sub_821DE350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DE360"))) PPC_WEAK_FUNC(sub_821DE360);
PPC_FUNC_IMPL(__imp__sub_821DE360) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x821de380
	if (cr6.lt) goto loc_821DE380;
	// cmpwi cr6,r4,16
	cr6.compare<int32_t>(ctx.r4.s32, 16, xer);
	// bge cr6,0x821de380
	if (!cr6.lt) goto loc_821DE380;
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
loc_821DE380:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DE388"))) PPC_WEAK_FUNC(sub_821DE388);
PPC_FUNC_IMPL(__imp__sub_821DE388) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821DE390;
	// li r31,0
	r31.s64 = 0;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// beq cr6,0x821de434
	if (cr6.eq) goto loc_821DE434;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// ori r9,r10,65534
	ctx.r9.u64 = ctx.r10.u64 | 65534;
loc_821DE3B4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// sthx r9,r10,r6
	PPC_STORE_U16(ctx.r10.u32 + ctx.r6.u32, ctx.r9.u16);
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// sth r9,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r9.u16);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r8,r5,21
	ctx.r8.u64 = ctx.r5.u32 & 0x7FF;
	// ori r6,r8,32768
	ctx.r6.u64 = ctx.r8.u64 | 32768;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// sth r6,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r6.u16);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r7,r5,16
	ctx.r7.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwinm r7,r7,0,24,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// blt cr6,0x821de3b4
	if (cr6.lt) goto loc_821DE3B4;
loc_821DE434:
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r3,108
	r11.s64 = ctx.r3.s64 + 108;
	// li r10,16
	ctx.r10.s64 = 16;
	// ori r5,r9,65535
	ctx.r5.u64 = ctx.r9.u64 | 65535;
loc_821DE444:
	// sth r5,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r5.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r31,0(r11)
	PPC_STORE_U16(r11.u32 + 0, r31.u16);
	// sth r31,-32(r11)
	PPC_STORE_U16(r11.u32 + -32, r31.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x821de444
	if (!cr0.eq) goto loc_821DE444;
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_821DE46C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x821de46c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821DE46C;
	// lis r30,0
	r30.s64 = 0;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r31,15
	r31.s64 = 15;
	// ori r30,r30,32768
	r30.u64 = r30.u64 | 32768;
	// addi r8,r3,170
	ctx.r8.s64 = ctx.r3.s64 + 170;
loc_821DE48C:
	// and r11,r30,r4
	r11.u64 = r30.u64 & ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821de518
	if (cr6.eq) goto loc_821DE518;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r7,r9,1,15,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1FFFE;
	// rlwinm r11,r9,1,15,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1FFFE;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r29,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwimi r6,r31,11,0,20
	ctx.r6.u64 = (__builtin_rotateleft32(r31.u32, 11) & 0xFFFFF800) | (ctx.r6.u64 & 0xFFFFFFFF000007FF);
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// sthx r5,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r5.u16);
	// lhz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// sth r6,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r6.u16);
	// lhz r11,0(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821de504
	if (cr6.eq) goto loc_821DE504;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r7,r6
	PPC_STORE_U16(ctx.r7.u32 + ctx.r6.u32, ctx.r10.u16);
loc_821DE504:
	// lhz r11,-32(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + -32);
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// sth r10,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r10.u16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,-32(r8)
	PPC_STORE_U16(ctx.r8.u32 + -32, r11.u16);
loc_821DE518:
	// rlwinm r30,r30,31,1,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r8,r8,-2
	ctx.r8.s64 = ctx.r8.s64 + -2;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821de48c
	if (!cr6.eq) goto loc_821DE48C;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DE530"))) PPC_WEAK_FUNC(sub_821DE530);
PPC_FUNC_IMPL(__imp__sub_821DE530) {
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
	ctx.lr = 0x821DE538;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,196
	ctx.r5.s64 = 196;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x821DE554;
	sub_823D9890(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r23,r31,140
	r23.s64 = r31.s64 + 140;
	// li r22,1
	r22.s64 = 1;
	// ori r21,r11,65535
	r21.u64 = r11.u64 | 65535;
loc_821DE568:
	// lhz r29,0(r23)
	r29.u64 = PPC_LOAD_U16(r23.u32 + 0);
	// slw r11,r22,r5
	r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r5.u8 & 0x3F));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r26,r21
	r26.u64 = r21.u64;
	// clrlwi r24,r11,16
	r24.u64 = r11.u32 & 0xFFFF;
	// mr r27,r29
	r27.u64 = r29.u64;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x821de648
	if (cr6.eq) goto loc_821DE648;
	// lwz r25,4(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r3,r24,16
	ctx.r3.u64 = r24.u32 & 0xFFFF;
loc_821DE590:
	// xor r11,r3,r4
	r11.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// clrlwi r26,r11,16
	r26.u64 = r11.u32 & 0xFFFF;
	// add r10,r26,r3
	ctx.r10.u64 = r26.u64 + ctx.r3.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// bgt cr6,0x821de624
	if (cr6.gt) goto loc_821DE624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821de618
	if (cr6.eq) goto loc_821DE618;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
loc_821DE5C0:
	// add r11,r9,r6
	r11.u64 = ctx.r9.u64 + ctx.r6.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r19,r10,0,21,23
	r19.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x700;
	// rlwinm r20,r10,21,11,31
	r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1FFFFF;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// slw r10,r22,r20
	ctx.r10.u64 = r20.u8 & 0x20 ? 0 : (r22.u32 << (r20.u8 & 0x3F));
	// bne cr6,0x821de618
	if (!cr6.eq) goto loc_821DE618;
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r11,65534
	cr6.compare<uint32_t>(r11.u32, 65534, xer);
	// bne cr6,0x821de604
	if (!cr6.eq) goto loc_821DE604;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,32
	cr6.compare<int32_t>(r28.s32, 32, xer);
	// bgt cr6,0x821de618
	if (cr6.gt) goto loc_821DE618;
loc_821DE604:
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r7,r11,16
	ctx.r7.u64 = r11.u32 & 0xFFFF;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// blt cr6,0x821de5c0
	if (cr6.lt) goto loc_821DE5C0;
loc_821DE618:
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// beq cr6,0x821de648
	if (cr6.eq) goto loc_821DE648;
loc_821DE624:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lhz r27,2(r10)
	r27.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// bne cr6,0x821de590
	if (!cr6.eq) goto loc_821DE590;
loc_821DE648:
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821de6ac
	if (cr6.eq) goto loc_821DE6AC;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821de6a0
	if (cr6.eq) goto loc_821DE6A0;
	// clrlwi r8,r24,16
	ctx.r8.u64 = r24.u32 & 0xFFFF;
	// clrlwi r7,r26,16
	ctx.r7.u64 = r26.u32 & 0xFFFF;
loc_821DE668:
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// xor r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bne cr6,0x821de6a0
	if (!cr6.eq) goto loc_821DE6A0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lhz r29,2(r10)
	r29.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x821de668
	if (!cr6.eq) goto loc_821DE668;
loc_821DE6A0:
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x821de6c8
	if (!cr6.eq) goto loc_821DE6C8;
loc_821DE6AC:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r23,r23,2
	r23.s64 = r23.s64 + 2;
	// cmplwi cr6,r5,15
	cr6.compare<uint32_t>(ctx.r5.u32, 15, xer);
	// blt cr6,0x821de568
	if (cr6.lt) goto loc_821DE568;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
loc_821DE6C8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821dde30
	ctx.lr = 0x821DE6D4;
	sub_821DDE30(ctx, base);
	// clrlwi r24,r24,16
	r24.u64 = r24.u32 & 0xFFFF;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821de8f8
	if (cr6.eq) goto loc_821DE8F8;
	// clrlwi r25,r26,16
	r25.u64 = r26.u32 & 0xFFFF;
	// clrlwi r26,r29,16
	r26.u64 = r29.u32 & 0xFFFF;
	// li r27,0
	r27.s64 = 0;
loc_821DE6EC:
	// add r4,r25,r27
	ctx.r4.u64 = r25.u64 + r27.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lhz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// add r11,r27,r26
	r11.u64 = r27.u64 + r26.u64;
	// rlwinm r9,r9,21,11,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x1FFFFF;
	// cmplwi cr6,r8,65534
	cr6.compare<uint32_t>(ctx.r8.u32, 65534, xer);
	// slw r5,r22,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// bne cr6,0x821de860
	if (!cr6.eq) goto loc_821DE860;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r4,1,15,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// add r10,r8,r6
	ctx.r10.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r11,r8
	r29.u64 = r11.u64 + ctx.r8.u64;
	// add r8,r6,r30
	ctx.r8.u64 = ctx.r6.u64 + r30.u64;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r11,r11,1,15,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 + ctx.r4.u64;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// add r23,r10,r11
	r23.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r28,r8,1,0,30
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r29,1,0,30
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r28
	ctx.r3.u64 = ctx.r8.u64 + r28.u64;
	// addi r8,r9,38
	ctx.r8.s64 = ctx.r9.s64 + 38;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r6,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r11,r30
	PPC_STORE_U16(r11.u32 + r30.u32, ctx.r10.u16);
	// rlwinm r10,r23,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// sth r5,8(r4)
	PPC_STORE_U16(ctx.r4.u32 + 8, ctx.r5.u16);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwimi r7,r9,11,0,20
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 11) & 0xFFFFF800) | (ctx.r7.u64 & 0xFFFFFFFF000007FF);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r7,r11,r5
	ctx.r7.u64 = r11.u64 + ctx.r5.u64;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// lhzx r11,r6,r31
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + r31.u32);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sthx r4,r6,r31
	PPC_STORE_U16(ctx.r6.u32 + r31.u32, ctx.r4.u16);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + r11.u64;
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// rlwinm r11,r7,28,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xF;
	// addi r6,r11,3
	ctx.r6.s64 = r11.s64 + 3;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// add r4,r9,r5
	ctx.r4.u64 = ctx.r9.u64 + ctx.r5.u64;
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lhz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// lhz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// rlwinm r9,r7,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF00;
	// addi r6,r9,256
	ctx.r6.s64 = ctx.r9.s64 + 256;
	// rlwimi r3,r6,0,21,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x700) | (ctx.r3.u64 & 0xFFFFFFFFFFFFF8FF);
	// sth r3,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r3.u16);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// rlwinm r10,r9,0,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// addi r7,r10,256
	ctx.r7.s64 = ctx.r10.s64 + 256;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwimi r8,r7,0,21,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x700) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF8FF);
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// b 0x821de8e8
	goto loc_821DE8E8;
loc_821DE860:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r6,r9,70
	ctx.r6.s64 = ctx.r9.s64 + 70;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,1,15,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r4,r11,r7
	ctx.r4.u64 = r11.u64 + ctx.r7.u64;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lhz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// rlwimi r6,r9,11,0,20
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 11) & 0xFFFFF800) | (ctx.r6.u64 & 0xFFFFFFFF000007FF);
	// sth r6,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r6.u16);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// sthx r21,r7,r3
	PPC_STORE_U16(ctx.r7.u32 + ctx.r3.u32, r21.u16);
	// lhzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + r31.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// sth r6,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r6.u16);
	// lhzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + r31.u32);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x821de8d0
	if (cr6.eq) goto loc_821DE8D0;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r3,r6
	PPC_STORE_U16(ctx.r3.u32 + ctx.r6.u32, r11.u16);
loc_821DE8D0:
	// addi r10,r9,54
	ctx.r10.s64 = ctx.r9.s64 + 54;
	// sthx r11,r8,r31
	PPC_STORE_U16(ctx.r8.u32 + r31.u32, r11.u16);
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sthx r9,r11,r31
	PPC_STORE_U16(r11.u32 + r31.u32, ctx.r9.u16);
loc_821DE8E8:
	// add r11,r27,r5
	r11.u64 = r27.u64 + ctx.r5.u64;
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r27,r24
	cr6.compare<uint32_t>(r27.u32, r24.u32, xer);
	// blt cr6,0x821de6ec
	if (cr6.lt) goto loc_821DE6EC;
loc_821DE8F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_821DE904"))) PPC_WEAK_FUNC(sub_821DE904);
PPC_FUNC_IMPL(__imp__sub_821DE904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE908"))) PPC_WEAK_FUNC(sub_821DE908);
PPC_FUNC_IMPL(__imp__sub_821DE908) {
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
	ctx.lr = 0x821DE910;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,221
	ctx.r4.s64 = 221;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// bl 0x823d9890
	ctx.lr = 0x821DE934;
	sub_823D9890(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lhz r8,6(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x821de9cc
	if (!cr6.eq) goto loc_821DE9CC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821de970
	if (cr6.eq) goto loc_821DE970;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_821DE970:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821de98c
	if (!cr6.eq) goto loc_821DE98C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x821de990
	goto loc_821DE990;
loc_821DE98C:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_821DE990:
	// lwz r11,248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// subf r8,r11,r31
	ctx.r8.s64 = r31.s64 - r11.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// srawi r11,r8,14
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFF) != 0);
	r11.s64 = ctx.r8.s32 >> 14;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// addi r6,r10,63
	ctx.r6.s64 = ctx.r10.s64 + 63;
	// slw r5,r9,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// andc r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 & ~ctx.r5.u64;
	// stwx r9,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r9.u32);
	// bl 0x821c22d0
	ctx.lr = 0x821DE9CC;
	sub_821C22D0(ctx, base);
loc_821DE9CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DE9D4"))) PPC_WEAK_FUNC(sub_821DE9D4);
PPC_FUNC_IMPL(__imp__sub_821DE9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DE9D8"))) PPC_WEAK_FUNC(sub_821DE9D8);
PPC_FUNC_IMPL(__imp__sub_821DE9D8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dea18
	if (cr6.eq) goto loc_821DEA18;
loc_821DEA00:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821dea6c
	if (!cr6.eq) goto loc_821DEA6C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dea00
	if (!cr6.eq) goto loc_821DEA00;
loc_821DEA18:
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,16320
	ctx.r4.s64 = 16320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c1bb0
	ctx.lr = 0x821DEA28;
	sub_821C1BB0(ctx, base);
	// lwz r10,248(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// srawi r10,r7,14
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3FFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 14;
	// rlwinm r9,r10,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r6,r10,27
	ctx.r6.u64 = ctx.r10.u32 & 0x1F;
	// addi r5,r9,63
	ctx.r5.s64 = ctx.r9.s64 + 63;
	// slw r4,r8,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// or r9,r4,r3
	ctx.r9.u64 = ctx.r4.u64 | ctx.r3.u64;
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
	// bne cr6,0x821dea88
	if (!cr6.eq) goto loc_821DEA88;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821deb10
	goto loc_821DEB10;
loc_821DEA6C:
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// b 0x821deafc
	goto loc_821DEAFC;
loc_821DEA88:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821dea98
	if (cr6.eq) goto loc_821DEA98;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_821DEA98:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lhz r8,6(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addic. r9,r8,-2
	xer.ca = ctx.r8.u32 > 1;
	ctx.r9.s64 = ctx.r8.s64 + -2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x821deaf0
	if (cr0.eq) goto loc_821DEAF0;
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
loc_821DEAD8:
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bne 0x821dead8
	if (!cr0.eq) goto loc_821DEAD8;
loc_821DEAF0:
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// addi r30,r11,32
	r30.s64 = r11.s64 + 32;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_821DEAFC:
	// li r4,205
	ctx.r4.s64 = 205;
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x821DEB0C;
	sub_823D9890(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821DEB10:
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

__attribute__((alias("__imp__sub_821DEB28"))) PPC_WEAK_FUNC(sub_821DEB28);
PPC_FUNC_IMPL(__imp__sub_821DEB28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821deba0
	if (cr6.eq) goto loc_821DEBA0;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821deba0
	if (cr6.eq) goto loc_821DEBA0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r11,1328
	ctx.r9.s64 = r11.s64 + 1328;
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// ori r6,r8,32768
	ctx.r6.u64 = ctx.r8.u64 | 32768;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// stw r9,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r9.u32);
	// stw r9,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r9.u32);
	// blr 
	return;
loc_821DEBA0:
	// li r3,-2
	ctx.r3.s64 = -2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821DEBA8"))) PPC_WEAK_FUNC(sub_821DEBA8);
PPC_FUNC_IMPL(__imp__sub_821DEBA8) {
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
	ctx.lr = 0x821DEBB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821decd0
	if (cr6.eq) goto loc_821DECD0;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,49
	cr6.compare<uint32_t>(r11.u32, 49, xer);
	// bne cr6,0x821decd0
	if (!cr6.eq) goto loc_821DECD0;
	// cmpwi cr6,r6,56
	cr6.compare<int32_t>(ctx.r6.s32, 56, xer);
	// bne cr6,0x821decd0
	if (!cr6.eq) goto loc_821DECD0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821debec
	if (!cr6.eq) goto loc_821DEBEC;
	// li r3,-2
	ctx.r3.s64 = -2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821DEBEC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r29,0
	r29.s64 = 0;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dec10
	if (!cr6.eq) goto loc_821DEC10;
	// lis r11,-32226
	r11.s64 = -2111963136;
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// addi r10,r11,19216
	ctx.r10.s64 = r11.s64 + 19216;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
loc_821DEC10:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dec28
	if (!cr6.eq) goto loc_821DEC28;
	// lis r11,-32226
	r11.s64 = -2111963136;
	// addi r10,r11,19224
	ctx.r10.s64 = r11.s64 + 19224;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
loc_821DEC28:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r5,9520
	ctx.r5.s64 = 9520;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DEC40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x821dec58
	if (!cr6.eq) goto loc_821DEC58;
	// li r3,-4
	ctx.r3.s64 = -4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821DEC58:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// bge cr6,0x821dec70
	if (!cr6.lt) goto loc_821DEC70;
	// neg r30,r30
	r30.s64 = -r30.s64;
	// stw r29,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r29.u32);
	// b 0x821dec88
	goto loc_821DEC88;
loc_821DEC70:
	// srawi r11,r30,4
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xF) != 0);
	r11.s64 = r30.s32 >> 4;
	// cmpwi cr6,r30,48
	cr6.compare<int32_t>(r30.s32, 48, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// bge cr6,0x821dec88
	if (!cr6.lt) goto loc_821DEC88;
	// clrlwi r30,r30,28
	r30.u64 = r30.u32 & 0xF;
loc_821DEC88:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x821decb0
	if (cr6.lt) goto loc_821DECB0;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// bgt cr6,0x821decb0
	if (cr6.gt) goto loc_821DECB0;
	// stw r30,36(r4)
	PPC_STORE_U32(ctx.r4.u32 + 36, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,52(r4)
	PPC_STORE_U32(ctx.r4.u32 + 52, r29.u32);
	// bl 0x821deb28
	ctx.lr = 0x821DECA8;
	sub_821DEB28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821DECB0:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821DECC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,-2
	ctx.r3.s64 = -2;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821DECD0:
	// li r3,-6
	ctx.r3.s64 = -6;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821DECDC"))) PPC_WEAK_FUNC(sub_821DECDC);
PPC_FUNC_IMPL(__imp__sub_821DECDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821DECE0"))) PPC_WEAK_FUNC(sub_821DECE0);
PPC_FUNC_IMPL(__imp__sub_821DECE0) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,15
	ctx.r4.s64 = 15;
	// b 0x821deba8
	sub_821DEBA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821DECF0"))) PPC_WEAK_FUNC(sub_821DECF0);
PPC_FUNC_IMPL(__imp__sub_821DECF0) {
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
	ctx.lr = 0x821DECF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,1
	r30.s64 = 1;
	// lwz r31,28(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821ded4c
	if (!cr6.eq) goto loc_821DED4C;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,40(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// lwz r10,32(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// slw r4,r30,r11
	ctx.r4.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 << (r11.u8 & 0x3F));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821DED34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821ded4c
	if (!cr6.eq) goto loc_821DED4C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821DED4C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ded70
	if (!cr6.eq) goto loc_821DED70;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r27,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r27.u32);
	// slw r10,r30,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 << (r11.u8 & 0x3F));
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_821DED70:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// subf r30,r11,r29
	r30.s64 = r29.s64 - r11.s64;
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// blt cr6,0x821deda8
	if (cr6.lt) goto loc_821DEDA8;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// subf r4,r5,r11
	ctx.r4.s64 = r11.s64 - ctx.r5.s64;
	// bl 0x823da950
	ctx.lr = 0x821DED90;
	sub_823DA950(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r27,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r27.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821DEDA8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r29,r11,r5
	r29.s64 = ctx.r5.s64 - r11.s64;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// ble cr6,0x821dedbc
	if (!cr6.gt) goto loc_821DEDBC;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_821DEDBC:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// subf r4,r30,r10
	ctx.r4.s64 = ctx.r10.s64 - r30.s64;
	// bl 0x823da950
	ctx.lr = 0x821DEDD0;
	sub_823DA950(ctx, base);
	// subf. r30,r29,r30
	r30.s64 = r30.s64 - r29.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x821dee04
	if (cr0.eq) goto loc_821DEE04;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r4,r30,r11
	ctx.r4.s64 = r11.s64 - r30.s64;
	// bl 0x823da950
	ctx.lr = 0x821DEDEC;
	sub_823DA950(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821DEE04:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821dee20
	if (!cr6.eq) goto loc_821DEE20;
	// stw r27,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r27.u32);
loc_821DEE20:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821dee34
	if (!cr6.lt) goto loc_821DEE34;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
loc_821DEE34:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821DEE40"))) PPC_WEAK_FUNC(sub_821DEE40);
PPC_FUNC_IMPL(__imp__sub_821DEE40) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x821DEE48;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// stw r4,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r4.u32);
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// beq cr6,0x821e0468
	if (cr6.eq) goto loc_821E0468;
	// lwz r29,28(r17)
	r29.u64 = PPC_LOAD_U32(r17.u32 + 28);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e0468
	if (cr6.eq) goto loc_821E0468;
	// lwz r11,12(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e0468
	if (cr6.eq) goto loc_821E0468;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dee8c
	if (!cr6.eq) goto loc_821DEE8C;
	// lwz r11,4(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e0468
	if (!cr6.eq) goto loc_821E0468;
loc_821DEE8C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bne cr6,0x821deea0
	if (!cr6.eq) goto loc_821DEEA0;
	// li r11,12
	r11.s64 = 12;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DEEA0:
	// lwz r11,12(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// li r15,0
	r15.s64 = 0;
	// lwz r14,16(r17)
	r14.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// lwz r27,4(r17)
	r27.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// lwz r19,0(r29)
	r19.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r28,0(r17)
	r28.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwz r30,56(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cmplwi cr6,r19,28
	cr6.compare<uint32_t>(r19.u32, 28, xer);
	// lwz r31,60(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r15,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r15.u32);
	// stw r14,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r14.u32);
	// stw r27,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r27.u32);
	// bgt cr6,0x821e0468
	if (cr6.gt) goto loc_821E0468;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r22,-32255
	r22.s64 = -2113863680;
	// addi r11,r11,24416
	r11.s64 = r11.s64 + 24416;
	// lis r20,-32255
	r20.s64 = -2113863680;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r11,r22,27016
	r11.s64 = r22.s64 + 27016;
	// addi r20,r20,26992
	r20.s64 = r20.s64 + 26992;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r20,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r20.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r10,26968
	ctx.r10.s64 = ctx.r10.s64 + 26968;
	// lis r24,-32255
	r24.s64 = -2113863680;
	// lwz r20,88(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lis r23,-32255
	r23.s64 = -2113863680;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lis r26,-32255
	r26.s64 = -2113863680;
	// addi r9,r9,26936
	ctx.r9.s64 = ctx.r9.s64 + 26936;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r25,-32255
	r25.s64 = -2113863680;
	// addi r24,r24,26916
	r24.s64 = r24.s64 + 26916;
	// addi r23,r23,26888
	r23.s64 = r23.s64 + 26888;
	// addi r10,r26,26852
	ctx.r10.s64 = r26.s64 + 26852;
	// stw r24,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r24.u32);
	// lis r21,-32255
	r21.s64 = -2113863680;
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r23.u32);
	// addi r8,r8,26828
	ctx.r8.s64 = ctx.r8.s64 + 26828;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// addi r7,r7,26800
	ctx.r7.s64 = ctx.r7.s64 + 26800;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r6,r6,26776
	ctx.r6.s64 = ctx.r6.s64 + 26776;
	// lwz r23,80(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r5,26748
	ctx.r5.s64 = ctx.r5.s64 + 26748;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// addi r4,r4,26720
	ctx.r4.s64 = ctx.r4.s64 + 26720;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// addi r3,r3,26692
	ctx.r3.s64 = ctx.r3.s64 + 26692;
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// addi r9,r25,26660
	ctx.r9.s64 = r25.s64 + 26660;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// addi r24,r21,26632
	r24.s64 = r21.s64 + 26632;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// rotlwi r22,r14,0
	r22.u64 = __builtin_rotateleft32(r14.u32, 0);
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// rotlwi r21,r15,0
	r21.u64 = __builtin_rotateleft32(r15.u32, 0);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r18,1
	r18.s64 = 1;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// li r16,27
	r16.s64 = 27;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
loc_821DEFBC:
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-4140
	r12.s64 = r12.s64 + -4140;
	// rlwinm r0,r19,2,0,29
	r0.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r19.u64) {
	case 0:
		goto loc_821DF048;
	case 1:
		goto loc_821DF1B4;
	case 2:
		goto loc_821DF268;
	case 3:
		goto loc_821DF2FC;
	case 4:
		goto loc_821DF38C;
	case 5:
		goto loc_821DF434;
	case 6:
		goto loc_821DF4F4;
	case 7:
		goto loc_821DF5B4;
	case 8:
		goto loc_821DF670;
	case 9:
		goto loc_821DF700;
	case 10:
		goto loc_821DF768;
	case 11:
		goto loc_821DF77C;
	case 12:
		goto loc_821DF788;
	case 13:
		goto loc_821DF890;
	case 14:
		goto loc_821DF8FC;
	case 15:
		goto loc_821DF958;
	case 16:
		goto loc_821DF9E0;
	case 17:
		goto loc_821DFAFC;
	case 18:
		goto loc_821DFE30;
	case 19:
		goto loc_821E0038;
	case 20:
		goto loc_821E00A0;
	case 21:
		goto loc_821E022C;
	case 22:
		goto loc_821E02B4;
	case 23:
		goto loc_821E0360;
	case 24:
		goto loc_821E0384;
	case 25:
		goto loc_821E03FC;
	case 26:
		goto loc_821E04A8;
	case 27:
		goto loc_821E04B0;
	case 28:
		goto loc_821E05D0;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-4024(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -4024);
	// lwz r16,-3660(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -3660);
	// lwz r16,-3480(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -3480);
	// lwz r16,-3332(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -3332);
	// lwz r16,-3188(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -3188);
	// lwz r16,-3020(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -3020);
	// lwz r16,-2828(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2828);
	// lwz r16,-2636(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2636);
	// lwz r16,-2448(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2448);
	// lwz r16,-2304(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2304);
	// lwz r16,-2200(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2200);
	// lwz r16,-2180(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2180);
	// lwz r16,-2168(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2168);
	// lwz r16,-1904(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1904);
	// lwz r16,-1796(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1796);
	// lwz r16,-1704(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1704);
	// lwz r16,-1568(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1568);
	// lwz r16,-1284(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1284);
	// lwz r16,-464(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -464);
	// lwz r16,56(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r16,160(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// lwz r16,556(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 556);
	// lwz r16,692(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 692);
	// lwz r16,864(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// lwz r16,900(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 900);
	// lwz r16,1020(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 1020);
	// lwz r16,1192(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 1192);
	// lwz r16,1200(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 1200);
	// lwz r16,1488(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 1488);
loc_821DF048:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821df060
	if (!cr6.eq) goto loc_821DF060;
	// li r11,12
	r11.s64 = 12;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF060:
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// bge cr6,0x821df090
	if (!cr6.lt) goto loc_821DF090;
loc_821DF068:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// blt cr6,0x821df068
	if (cr6.lt) goto loc_821DF068;
loc_821DF090:
	// rlwinm r11,r10,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821df0ec
	if (cr6.eq) goto loc_821DF0EC;
	// cmplwi cr6,r30,35615
	cr6.compare<uint32_t>(r30.u32, 35615, xer);
	// bne cr6,0x821df0ec
	if (!cr6.eq) goto loc_821DF0EC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821d58d8
	ctx.lr = 0x821DF0B4;
	sub_821D58D8(ctx, base);
	// li r11,31
	r11.s64 = 31;
	// li r10,139
	ctx.r10.s64 = 139;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// bl 0x821d58d8
	ctx.lr = 0x821DF0D8;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// mr r30,r15
	r30.u64 = r15.u64;
	// stw r18,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r18.u32);
	// mr r31,r15
	r31.u64 = r15.u64;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF0EC:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// stw r15,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r15.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df104
	if (cr6.eq) goto loc_821DF104;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
loc_821DF104:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df1ac
	if (cr6.eq) goto loc_821DF1AC;
	// rlwinm r10,r30,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFF00;
	// rlwinm r11,r30,24,8,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFFFFFF;
	// lis r9,2114
	ctx.r9.s64 = 138543104;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// ori r7,r9,4229
	ctx.r7.u64 = ctx.r9.u64 | 4229;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mulhwu r11,r6,r7
	r11.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// subf r5,r11,r6
	ctx.r5.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r10,r5,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r3,r4,28,4,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r3,r11
	ctx.r10.s64 = r11.s64 - ctx.r3.s64;
	// subf. r9,r10,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x821df1ac
	if (!cr0.eq) goto loc_821DF1AC;
	// clrlwi r11,r30,28
	r11.u64 = r30.u32 & 0xF;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// beq cr6,0x821df164
	if (cr6.eq) goto loc_821DF164;
	// stw r24,24(r17)
	PPC_STORE_U32(r17.u32 + 24, r24.u32);
	// b 0x821e0458
	goto loc_821E0458;
loc_821DF164:
	// rlwinm r30,r30,28,4,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// clrlwi r11,r30,28
	r11.u64 = r30.u32 & 0xF;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x821df188
	if (!cr6.gt) goto loc_821DF188;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DF188:
	// not r10,r30
	ctx.r10.u64 = ~r30.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// slw r8,r18,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r18.u32 << (r11.u8 & 0x3F));
	// rlwimi r9,r10,24,30,30
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0x2) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r8,20(r29)
	PPC_STORE_U32(r29.u32 + 20, ctx.r8.u32);
	// mr r30,r15
	r30.u64 = r15.u64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// mr r31,r15
	r31.u64 = r15.u64;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF1AC:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DF1B4:
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// bge cr6,0x821df1e4
	if (!cr6.lt) goto loc_821DF1E4;
loc_821DF1BC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// blt cr6,0x821df1bc
	if (cr6.lt) goto loc_821DF1BC;
loc_821DF1E4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r30,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r30.u32);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x821df1fc
	if (cr6.eq) goto loc_821DF1FC;
	// stw r24,24(r17)
	PPC_STORE_U32(r17.u32 + 24, r24.u32);
	// b 0x821e0458
	goto loc_821E0458;
loc_821DF1FC:
	// rlwinm r11,r30,0,16,18
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xE000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821df210
	if (cr6.eq) goto loc_821DF210;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DF210:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df224
	if (cr6.eq) goto loc_821DF224;
	// rlwinm r10,r30,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0x1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_821DF224:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df254
	if (cr6.eq) goto loc_821DF254;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// bl 0x821d58d8
	ctx.lr = 0x821DF250;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF254:
	// li r11,2
	r11.s64 = 2;
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821df270
	goto loc_821DF270;
loc_821DF268:
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x821df298
	if (!cr6.lt) goto loc_821DF298;
loc_821DF270:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// blt cr6,0x821df270
	if (cr6.lt) goto loc_821DF270;
loc_821DF298:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df2a8
	if (cr6.eq) goto loc_821DF2A8;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
loc_821DF2A8:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df2e8
	if (cr6.eq) goto loc_821DF2E8;
	// rlwinm r11,r30,8,24,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r30.u8);
	// rlwinm r9,r30,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// rlwinm r8,r30,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFF;
	// stb r11,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r11.u8);
	// stb r9,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r9.u8);
	// li r5,4
	ctx.r5.s64 = 4;
	// stb r8,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r8.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// bl 0x821d58d8
	ctx.lr = 0x821DF2E4;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF2E8:
	// li r11,3
	r11.s64 = 3;
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821df304
	goto loc_821DF304;
loc_821DF2FC:
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// bge cr6,0x821df32c
	if (!cr6.lt) goto loc_821DF32C;
loc_821DF304:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// blt cr6,0x821df304
	if (cr6.lt) goto loc_821DF304;
loc_821DF32C:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df34c
	if (cr6.eq) goto loc_821DF34C;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// rlwinm r9,r30,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFFFFFF;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r8,32(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
loc_821DF34C:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df37c
	if (cr6.eq) goto loc_821DF37C;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// bl 0x821d58d8
	ctx.lr = 0x821DF378;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF37C:
	// li r11,4
	r11.s64 = 4;
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF38C:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df41c
	if (cr6.eq) goto loc_821DF41C;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// bge cr6,0x821df3cc
	if (!cr6.lt) goto loc_821DF3CC;
loc_821DF3A4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// blt cr6,0x821df3a4
	if (cr6.lt) goto loc_821DF3A4;
loc_821DF3CC:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// stw r30,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df3e0
	if (cr6.eq) goto loc_821DF3E0;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
loc_821DF3E0:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df410
	if (cr6.eq) goto loc_821DF410;
	// rlwinm r11,r30,24,24,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// bl 0x821d58d8
	ctx.lr = 0x821DF40C;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF410:
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// b 0x821df42c
	goto loc_821DF42C;
loc_821DF41C:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df42c
	if (cr6.eq) goto loc_821DF42C;
	// stw r15,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r15.u32);
loc_821DF42C:
	// li r11,5
	r11.s64 = 5;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF434:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df4e8
	if (cr6.eq) goto loc_821DF4E8;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r27
	cr6.compare<uint32_t>(ctx.r9.u32, r27.u32, xer);
	// ble cr6,0x821df458
	if (!cr6.gt) goto loc_821DF458;
	// mr r26,r27
	r26.u64 = r27.u64;
loc_821DF458:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821df4dc
	if (cr6.eq) goto loc_821DF4DC;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df4a4
	if (cr6.eq) goto loc_821DF4A4;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821df4a4
	if (cr6.eq) goto loc_821DF4A4;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// subf r11,r9,r7
	r11.s64 = ctx.r7.s64 - ctx.r9.s64;
	// add r6,r26,r11
	ctx.r6.u64 = r26.u64 + r11.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r6,r10
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, xer);
	// bgt cr6,0x821df498
	if (cr6.gt) goto loc_821DF498;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
loc_821DF498:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x821DF4A4;
	sub_823DA950(ctx, base);
loc_821DF4A4:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df4c8
	if (cr6.eq) goto loc_821DF4C8;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821d58d8
	ctx.lr = 0x821DF4C4;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF4C8:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// subf r27,r26,r27
	r27.s64 = r27.s64 - r26.s64;
	// add r28,r26,r28
	r28.u64 = r26.u64 + r28.u64;
	// subf r10,r26,r11
	ctx.r10.s64 = r11.s64 - r26.s64;
	// stw r10,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r10.u32);
loc_821DF4DC:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e04b4
	if (!cr6.eq) goto loc_821E04B4;
loc_821DF4E8:
	// li r11,6
	r11.s64 = 6;
	// stw r15,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r15.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF4F4:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df598
	if (cr6.eq) goto loc_821DF598;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// mr r26,r15
	r26.u64 = r15.u64;
loc_821DF510:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lbzx r25,r26,r28
	r25.u64 = PPC_LOAD_U8(r26.u32 + r28.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df550
	if (cr6.eq) goto loc_821DF550;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821df550
	if (cr6.eq) goto loc_821DF550;
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x821df550
	if (!cr6.lt) goto loc_821DF550;
	// stbx r25,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, r25.u8);
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r8.u32);
loc_821DF550:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x821df560
	if (cr6.eq) goto loc_821DF560;
	// cmplw cr6,r26,r27
	cr6.compare<uint32_t>(r26.u32, r27.u32, xer);
	// blt cr6,0x821df510
	if (cr6.lt) goto loc_821DF510;
loc_821DF560:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df584
	if (cr6.eq) goto loc_821DF584;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821d58d8
	ctx.lr = 0x821DF580;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF584:
	// subf r27,r26,r27
	r27.s64 = r27.s64 - r26.s64;
	// add r28,r26,r28
	r28.u64 = r26.u64 + r28.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x821e04b4
	if (!cr6.eq) goto loc_821E04B4;
	// b 0x821df5a8
	goto loc_821DF5A8;
loc_821DF598:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df5a8
	if (cr6.eq) goto loc_821DF5A8;
	// stw r15,28(r11)
	PPC_STORE_U32(r11.u32 + 28, r15.u32);
loc_821DF5A8:
	// li r11,7
	r11.s64 = 7;
	// stw r15,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r15.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF5B4:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df658
	if (cr6.eq) goto loc_821DF658;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// mr r26,r15
	r26.u64 = r15.u64;
loc_821DF5D0:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lbzx r25,r26,r28
	r25.u64 = PPC_LOAD_U8(r26.u32 + r28.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df610
	if (cr6.eq) goto loc_821DF610;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821df610
	if (cr6.eq) goto loc_821DF610;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x821df610
	if (!cr6.lt) goto loc_821DF610;
	// stbx r25,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, r25.u8);
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r8.u32);
loc_821DF610:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x821df620
	if (cr6.eq) goto loc_821DF620;
	// cmplw cr6,r26,r27
	cr6.compare<uint32_t>(r26.u32, r27.u32, xer);
	// blt cr6,0x821df5d0
	if (cr6.lt) goto loc_821DF5D0;
loc_821DF620:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df644
	if (cr6.eq) goto loc_821DF644;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821d58d8
	ctx.lr = 0x821DF640;
	sub_821D58D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
loc_821DF644:
	// subf r27,r26,r27
	r27.s64 = r27.s64 - r26.s64;
	// add r28,r26,r28
	r28.u64 = r26.u64 + r28.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x821e04b4
	if (!cr6.eq) goto loc_821E04B4;
	// b 0x821df668
	goto loc_821DF668;
loc_821DF658:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df668
	if (cr6.eq) goto loc_821DF668;
	// stw r15,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r15.u32);
loc_821DF668:
	// li r11,8
	r11.s64 = 8;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF670:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821df6b8
	if (cr6.eq) goto loc_821DF6B8;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// bge cr6,0x821df6b0
	if (!cr6.lt) goto loc_821DF6B0;
loc_821DF688:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,16
	cr6.compare<uint32_t>(r31.u32, 16, xer);
	// blt cr6,0x821df688
	if (cr6.lt) goto loc_821DF688;
loc_821DF6B0:
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
loc_821DF6B8:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821df6dc
	if (cr6.eq) goto loc_821DF6DC;
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// srawi r9,r10,9
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 9;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// stw r18,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, r18.u32);
loc_821DF6DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821d58d8
	ctx.lr = 0x821DF6EC;
	sub_821D58D8(ctx, base);
	// li r11,11
	r11.s64 = 11;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// stw r3,48(r17)
	PPC_STORE_U32(r17.u32 + 48, ctx.r3.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF700:
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x821df730
	if (!cr6.lt) goto loc_821DF730;
loc_821DF708:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// blt cr6,0x821df708
	if (cr6.lt) goto loc_821DF708;
loc_821DF730:
	// rlwinm r10,r30,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r30,0,16,23
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFF00;
	// rlwinm r9,r30,24,16,23
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF00;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r30,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// li r8,10
	ctx.r8.s64 = 10;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r30,r15
	r30.u64 = r15.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
	// stw r11,48(r17)
	PPC_STORE_U32(r17.u32 + 48, r11.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
loc_821DF768:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e0474
	if (cr6.eq) goto loc_821E0474;
	// li r11,11
	r11.s64 = 11;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF77C:
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
loc_821DF788:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821df7ac
	if (cr6.eq) goto loc_821DF7AC;
	// clrlwi r11,r31,29
	r11.u64 = r31.u32 & 0x7;
	// li r10,24
	ctx.r10.s64 = 24;
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF7AC:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x821df7dc
	if (!cr6.lt) goto loc_821DF7DC;
loc_821DF7B4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// blt cr6,0x821df7b4
	if (cr6.lt) goto loc_821DF7B4;
loc_821DF7DC:
	// rlwinm r10,r30,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// clrlwi r11,r10,30
	r11.u64 = ctx.r10.u32 & 0x3;
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// addi r9,r31,-1
	ctx.r9.s64 = r31.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x821df884
	if (cr6.gt) goto loc_821DF884;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,-2032
	r12.s64 = r12.s64 + -2032;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821DF820;
	case 1:
		goto loc_821DF834;
	case 2:
		goto loc_821DF864;
	case 3:
		goto loc_821DF878;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-2016(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -2016);
	// lwz r16,-1996(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1996);
	// lwz r16,-1948(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1948);
	// lwz r16,-1928(r29)
	r16.u64 = PPC_LOAD_U32(r29.u32 + -1928);
loc_821DF820:
	// li r11,13
	r11.s64 = 13;
	// rlwinm r30,r10,30,2,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r31,r9,-2
	r31.s64 = ctx.r9.s64 + -2;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF834:
	// addi r11,r20,2048
	r11.s64 = r20.s64 + 2048;
	// stw r20,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r20.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r11,80(r29)
	PPC_STORE_U32(r29.u32 + 80, r11.u32);
	// li r6,18
	ctx.r6.s64 = 18;
	// stw r8,84(r29)
	PPC_STORE_U32(r29.u32 + 84, ctx.r8.u32);
	// stw r7,88(r29)
	PPC_STORE_U32(r29.u32 + 88, ctx.r7.u32);
	// rlwinm r30,r10,30,2,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// addi r31,r9,-2
	r31.s64 = ctx.r9.s64 + -2;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF864:
	// li r11,15
	r11.s64 = 15;
	// rlwinm r30,r10,30,2,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r31,r9,-2
	r31.s64 = ctx.r9.s64 + -2;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF878:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r11,24(r17)
	PPC_STORE_U32(r17.u32 + 24, r11.u32);
	// stw r16,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r16.u32);
loc_821DF884:
	// rlwinm r30,r10,30,2,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r9,-2
	r31.s64 = ctx.r9.s64 + -2;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF890:
	// clrlwi r11,r31,29
	r11.u64 = r31.u32 & 0x7;
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x821df8cc
	if (!cr6.lt) goto loc_821DF8CC;
loc_821DF8A4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// blt cr6,0x821df8a4
	if (cr6.lt) goto loc_821DF8A4;
loc_821DF8CC:
	// not r10,r30
	ctx.r10.u64 = ~r30.u64;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// rlwinm r9,r10,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x821df8e8
	if (cr6.eq) goto loc_821DF8E8;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DF8E8:
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r11,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r11.u32);
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_821DF8FC:
	// lwz r26,64(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e0008
	if (cr6.eq) goto loc_821E0008;
	// cmplw cr6,r26,r27
	cr6.compare<uint32_t>(r26.u32, r27.u32, xer);
	// ble cr6,0x821df914
	if (!cr6.gt) goto loc_821DF914;
	// mr r26,r27
	r26.u64 = r27.u64;
loc_821DF914:
	// cmplw cr6,r26,r14
	cr6.compare<uint32_t>(r26.u32, r14.u32, xer);
	// ble cr6,0x821df920
	if (!cr6.gt) goto loc_821DF920;
	// mr r26,r14
	r26.u64 = r14.u64;
loc_821DF920:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823da950
	ctx.lr = 0x821DF938;
	sub_823DA950(ctx, base);
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// subf r27,r26,r27
	r27.s64 = r27.s64 - r26.s64;
	// subf r10,r26,r11
	ctx.r10.s64 = r11.s64 - r26.s64;
	// add r28,r26,r28
	r28.u64 = r26.u64 + r28.u64;
	// subf r14,r26,r14
	r14.s64 = r14.s64 - r26.s64;
	// stw r10,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r10.u32);
	// add r23,r26,r23
	r23.u64 = r26.u64 + r23.u64;
	// b 0x821e045c
	goto loc_821E045C;
loc_821DF958:
	// cmplwi cr6,r31,14
	cr6.compare<uint32_t>(r31.u32, 14, xer);
	// bge cr6,0x821df988
	if (!cr6.lt) goto loc_821DF988;
loc_821DF960:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,14
	cr6.compare<uint32_t>(r31.u32, 14, xer);
	// blt cr6,0x821df960
	if (cr6.lt) goto loc_821DF960;
loc_821DF988:
	// clrlwi r9,r30,27
	ctx.r9.u64 = r30.u32 & 0x1F;
	// rlwinm r11,r30,27,5,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 27) & 0x7FFFFFF;
	// addi r10,r9,257
	ctx.r10.s64 = ctx.r9.s64 + 257;
	// rlwinm r9,r11,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// stw r10,96(r29)
	PPC_STORE_U32(r29.u32 + 96, ctx.r10.u32);
	// clrlwi r10,r11,27
	ctx.r10.u64 = r11.u32 & 0x1F;
	// clrlwi r11,r9,28
	r11.u64 = ctx.r9.u32 & 0xF;
	// lwz r6,96(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r30,r9,28,4,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// stw r8,100(r29)
	PPC_STORE_U32(r29.u32 + 100, ctx.r8.u32);
	// addi r31,r31,-14
	r31.s64 = r31.s64 + -14;
	// stw r7,92(r29)
	PPC_STORE_U32(r29.u32 + 92, ctx.r7.u32);
	// cmplwi cr6,r6,286
	cr6.compare<uint32_t>(ctx.r6.u32, 286, xer);
	// bgt cr6,0x821dfae8
	if (cr6.gt) goto loc_821DFAE8;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r11,30
	cr6.compare<uint32_t>(r11.u32, 30, xer);
	// bgt cr6,0x821dfae8
	if (cr6.gt) goto loc_821DFAE8;
	// li r11,16
	r11.s64 = 16;
	// stw r15,104(r29)
	PPC_STORE_U32(r29.u32 + 104, r15.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DF9E0:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// lwz r10,92(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821dfa64
	if (!cr6.lt) goto loc_821DFA64;
loc_821DF9F0:
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x821dfa20
	if (!cr6.lt) goto loc_821DFA20;
loc_821DF9F8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// blt cr6,0x821df9f8
	if (cr6.lt) goto loc_821DF9F8;
loc_821DFA20:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r10,r20,2176
	ctx.r10.s64 = r20.s64 + 2176;
	// clrlwi r9,r30,29
	ctx.r9.u64 = r30.u32 & 0x7;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r30,r30,29,3,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r31,r31,-3
	r31.s64 = r31.s64 + -3;
	// lhzx r11,r8,r10
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// addi r7,r11,56
	ctx.r7.s64 = r11.s64 + 56;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r6,r29
	PPC_STORE_U16(ctx.r6.u32 + r29.u32, ctx.r9.u16);
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r5.u32);
	// lwz r3,92(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// cmplw cr6,r4,r3
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, xer);
	// blt cr6,0x821df9f0
	if (cr6.lt) goto loc_821DF9F0;
loc_821DFA64:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bge cr6,0x821dfaa4
	if (!cr6.lt) goto loc_821DFAA4;
loc_821DFA70:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r10,r20,2176
	ctx.r10.s64 = r20.s64 + 2176;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r9,r10
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r11,56
	ctx.r8.s64 = r11.s64 + 56;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r15,r7,r29
	PPC_STORE_U16(ctx.r7.u32 + r29.u32, r15.u16);
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r6.u32);
	// cmplwi cr6,r5,19
	cr6.compare<uint32_t>(ctx.r5.u32, 19, xer);
	// blt cr6,0x821dfa70
	if (cr6.lt) goto loc_821DFA70;
loc_821DFAA4:
	// addi r11,r29,1328
	r11.s64 = r29.s64 + 1328;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r11.u32);
	// addi r6,r29,108
	ctx.r6.s64 = r29.s64 + 108;
	// stw r11,108(r29)
	PPC_STORE_U32(r29.u32 + 108, r11.u32);
	// addi r7,r29,84
	ctx.r7.s64 = r29.s64 + 84;
	// stw r10,84(r29)
	PPC_STORE_U32(r29.u32 + 84, ctx.r10.u32);
	// addi r8,r29,752
	ctx.r8.s64 = r29.s64 + 752;
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r29,112
	ctx.r4.s64 = r29.s64 + 112;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e4fe8
	ctx.lr = 0x821DFAD4;
	sub_821E4FE8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x821dfaf0
	if (cr6.eq) goto loc_821DFAF0;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DFAE8:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DFAF0:
	// li r11,17
	r11.s64 = 17;
	// stw r15,104(r29)
	PPC_STORE_U32(r29.u32 + 104, r15.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DFAFC:
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x821dfd7c
	if (!cr6.lt) goto loc_821DFD7C;
loc_821DFB14:
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// slw r11,r18,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r18.u32 << (r11.u8 & 0x3F));
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 & r30.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// ble cr6,0x821dfb94
	if (!cr6.gt) goto loc_821DFB94;
loc_821DFB44:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r9,84(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// slw r11,r18,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r9.u8 & 0x3F));
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// and r6,r7,r30
	ctx.r6.u64 = ctx.r7.u64 & r30.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bgt cr6,0x821dfb44
	if (cr6.gt) goto loc_821DFB44;
loc_821DFB94:
	// lhz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// bge cr6,0x821dfc00
	if (!cr6.lt) goto loc_821DFC00;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bge cr6,0x821dfbd8
	if (!cr6.lt) goto loc_821DFBD8;
loc_821DFBB0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x821dfbb0
	if (cr6.lt) goto loc_821DFBB0;
loc_821DFBD8:
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r8,r29
	PPC_STORE_U16(ctx.r8.u32 + r29.u32, ctx.r9.u16);
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r7.u32);
	// b 0x821dfd64
	goto loc_821DFD64;
loc_821DFC00:
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// bne cr6,0x821dfc70
	if (!cr6.eq) goto loc_821DFC70;
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x821dfc3c
	if (!cr6.lt) goto loc_821DFC3C;
loc_821DFC14:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x821dfc14
	if (cr6.lt) goto loc_821DFC14;
loc_821DFC3C:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// srw r30,r30,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r9.u8 & 0x3F));
	// subf r31,r9,r31
	r31.s64 = r31.s64 - ctx.r9.s64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dfdd4
	if (cr6.eq) goto loc_821DFDD4;
	// addi r10,r11,55
	ctx.r10.s64 = r11.s64 + 55;
	// clrlwi r11,r30,30
	r11.u64 = r30.u32 & 0x3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r30,r30,30,2,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r31,-2
	r31.s64 = r31.s64 + -2;
	// lhzx r10,r9,r29
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + r29.u32);
	// b 0x821dfd18
	goto loc_821DFD18;
loc_821DFC70:
	// cmplwi cr6,r10,17
	cr6.compare<uint32_t>(ctx.r10.u32, 17, xer);
	// bne cr6,0x821dfcc8
	if (!cr6.eq) goto loc_821DFCC8;
	// addi r10,r9,3
	ctx.r10.s64 = ctx.r9.s64 + 3;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x821dfcac
	if (!cr6.lt) goto loc_821DFCAC;
loc_821DFC84:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x821dfc84
	if (cr6.lt) goto loc_821DFC84;
loc_821DFCAC:
	// srw r8,r30,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r11,r8,29
	r11.u64 = ctx.r8.u32 & 0x7;
	// subf r9,r9,r31
	ctx.r9.s64 = r31.s64 - ctx.r9.s64;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r30,r8,29,3,31
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r31,r9,-3
	r31.s64 = ctx.r9.s64 + -3;
	// b 0x821dfd14
	goto loc_821DFD14;
loc_821DFCC8:
	// addi r10,r9,7
	ctx.r10.s64 = ctx.r9.s64 + 7;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x821dfcfc
	if (!cr6.lt) goto loc_821DFCFC;
loc_821DFCD4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x821dfcd4
	if (cr6.lt) goto loc_821DFCD4;
loc_821DFCFC:
	// srw r8,r30,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r11,r8,25
	r11.u64 = ctx.r8.u32 & 0x7F;
	// subf r9,r9,r31
	ctx.r9.s64 = r31.s64 - ctx.r9.s64;
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r30,r8,25,7,31
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// addi r31,r9,-7
	r31.s64 = ctx.r9.s64 + -7;
loc_821DFD14:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
loc_821DFD18:
	// lwz r7,96(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r8,100(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// bgt cr6,0x821dfdd4
	if (cr6.gt) goto loc_821DFDD4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821dfd64
	if (cr6.eq) goto loc_821DFD64;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
loc_821DFD40:
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r8,r29
	PPC_STORE_U16(ctx.r8.u32 + r29.u32, ctx.r9.u16);
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r7.u32);
	// bne 0x821dfd40
	if (!cr0.eq) goto loc_821DFD40;
loc_821DFD64:
	// lwz r11,100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x821dfb14
	if (cr6.lt) goto loc_821DFB14;
loc_821DFD7C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,27
	cr6.compare<int32_t>(r11.s32, 27, xer);
	// beq cr6,0x821e045c
	if (cr6.eq) goto loc_821E045C;
	// addi r11,r29,1328
	r11.s64 = r29.s64 + 1328;
	// lwz r5,96(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r11,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r11.u32);
	// addi r26,r29,108
	r26.s64 = r29.s64 + 108;
	// stw r11,108(r29)
	PPC_STORE_U32(r29.u32 + 108, r11.u32);
	// addi r25,r29,752
	r25.s64 = r29.s64 + 752;
	// stw r10,84(r29)
	PPC_STORE_U32(r29.u32 + 84, ctx.r10.u32);
	// addi r7,r29,84
	ctx.r7.s64 = r29.s64 + 84;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// addi r4,r29,112
	ctx.r4.s64 = r29.s64 + 112;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821e4fe8
	ctx.lr = 0x821DFDC0;
	sub_821E4FE8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x821dfddc
	if (cr6.eq) goto loc_821DFDDC;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DFDD4:
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DFDDC:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// addi r7,r29,88
	ctx.r7.s64 = r29.s64 + 88;
	// stw r9,88(r29)
	PPC_STORE_U32(r29.u32 + 88, ctx.r9.u32);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// addi r4,r11,56
	ctx.r4.s64 = r11.s64 + 56;
	// lwz r5,100(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// stw r10,80(r29)
	PPC_STORE_U32(r29.u32 + 80, ctx.r10.u32);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,2
	ctx.r3.s64 = 2;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x821e4fe8
	ctx.lr = 0x821DFE14;
	sub_821E4FE8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x821dfe28
	if (cr6.eq) goto loc_821DFE28;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// b 0x821e0454
	goto loc_821E0454;
loc_821DFE28:
	// li r11,18
	r11.s64 = 18;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821DFE30:
	// cmplwi cr6,r27,6
	cr6.compare<uint32_t>(r27.u32, 6, xer);
	// blt cr6,0x821dfe80
	if (cr6.lt) goto loc_821DFE80;
	// cmplwi cr6,r14,258
	cr6.compare<uint32_t>(r14.u32, 258, xer);
	// blt cr6,0x821dfe80
	if (cr6.lt) goto loc_821DFE80;
	// stw r23,12(r17)
	PPC_STORE_U32(r17.u32 + 12, r23.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stw r14,16(r17)
	PPC_STORE_U32(r17.u32 + 16, r14.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// stw r28,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r28.u32);
	// stw r27,4(r17)
	PPC_STORE_U32(r17.u32 + 4, r27.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r31.u32);
	// bl 0x821e4b20
	ctx.lr = 0x821DFE64;
	sub_821E4B20(ctx, base);
	// lwz r23,12(r17)
	r23.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// lwz r14,16(r17)
	r14.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// lwz r28,0(r17)
	r28.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwz r27,4(r17)
	r27.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// lwz r30,56(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// lwz r31,60(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// b 0x821e045c
	goto loc_821E045C;
loc_821DFE80:
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// slw r11,r18,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r18.u32 << (r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// and r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 & r30.u64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// cmplw cr6,r6,r31
	cr6.compare<uint32_t>(ctx.r6.u32, r31.u32, xer);
	// ble cr6,0x821dff00
	if (!cr6.gt) goto loc_821DFF00;
loc_821DFEB0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r9,84(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// lwz r7,76(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// slw r11,r18,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r9.u8 & 0x3F));
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & r30.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r7
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bgt cr6,0x821dfeb0
	if (cr6.gt) goto loc_821DFEB0;
loc_821DFF00:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821dffd0
	if (cr6.eq) goto loc_821DFFD0;
	// rlwinm r7,r9,0,24,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821dffd0
	if (!cr6.eq) goto loc_821DFFD0;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// slw r11,r18,r7
	r11.u64 = ctx.r7.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r7.u8 & 0x3F));
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// lbz r11,89(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// and r4,r6,r30
	ctx.r4.u64 = ctx.r6.u64 & r30.u64;
	// srw r10,r4,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r10.u8 & 0x3F));
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// ble cr6,0x821dffc8
	if (!cr6.gt) goto loc_821DFFC8;
	// lhz r8,90(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// lbz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_821DFF68:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// lwz r6,76(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// slw r9,r9,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r31.u8 & 0x3F));
	// slw r10,r18,r5
	ctx.r10.u64 = ctx.r5.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r5.u8 & 0x3F));
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// and r3,r4,r30
	ctx.r3.u64 = ctx.r4.u64 & r30.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// srw r10,r3,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// bgt cr6,0x821dff68
	if (cr6.gt) goto loc_821DFF68;
loc_821DFFC8:
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
loc_821DFFD0:
	// lhz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// stw r8,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r8.u32);
	// subf r31,r10,r31
	r31.s64 = r31.s64 - ctx.r10.s64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821dfffc
	if (!cr6.eq) goto loc_821DFFFC;
	// li r11,23
	r11.s64 = 23;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821DFFFC:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e0014
	if (cr6.eq) goto loc_821E0014;
loc_821E0008:
	// li r11,11
	r11.s64 = 11;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821E0014:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e0028
	if (cr6.eq) goto loc_821E0028;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// b 0x821e0454
	goto loc_821E0454;
loc_821E0028:
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// li r10,19
	ctx.r10.s64 = 19;
	// stw r11,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r11.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_821E0038:
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e0098
	if (cr6.eq) goto loc_821E0098;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x821e0078
	if (!cr6.lt) goto loc_821E0078;
loc_821E004C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r9,72(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x821e004c
	if (cr6.lt) goto loc_821E004C;
loc_821E0078:
	// slw r11,r18,r10
	r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// subf r31,r10,r31
	r31.s64 = r31.s64 - ctx.r10.s64;
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// stw r10,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r10.u32);
loc_821E0098:
	// li r11,20
	r11.s64 = 20;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821E00A0:
	// lwz r11,88(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// lwz r7,80(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// slw r11,r18,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r18.u32 << (r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// and r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 & r30.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r7
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// cmplw cr6,r6,r31
	cr6.compare<uint32_t>(ctx.r6.u32, r31.u32, xer);
	// ble cr6,0x821e0120
	if (!cr6.gt) goto loc_821E0120;
loc_821E00D0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r9,88(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// lwz r8,80(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// slw r11,r18,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r9.u8 & 0x3F));
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & r30.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r8
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bgt cr6,0x821e00d0
	if (cr6.gt) goto loc_821E00D0;
loc_821E0120:
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r6,r8,0,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821e01f0
	if (!cr6.eq) goto loc_821E01F0;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// slw r11,r18,r8
	r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r8.u8 & 0x3F));
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// lbz r11,89(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// and r4,r6,r30
	ctx.r4.u64 = ctx.r6.u64 & r30.u64;
	// srw r10,r4,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r10.u8 & 0x3F));
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// ble cr6,0x821e01e4
	if (!cr6.gt) goto loc_821E01E4;
	// lhz r8,90(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// lbz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_821E0184:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// lwz r6,80(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// slw r9,r9,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r31.u8 & 0x3F));
	// slw r10,r18,r5
	ctx.r10.u64 = ctx.r5.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r5.u8 & 0x3F));
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// and r3,r4,r30
	ctx.r3.u64 = ctx.r4.u64 & r30.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// srw r10,r3,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// bgt cr6,0x821e0184
	if (cr6.gt) goto loc_821E0184;
loc_821E01E4:
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
loc_821E01F0:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r10,r8,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e0214
	if (cr6.eq) goto loc_821E0214;
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// b 0x821e0454
	goto loc_821E0454;
loc_821E0214:
	// lhz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// li r8,21
	ctx.r8.s64 = 21;
	// stw r9,72(r29)
	PPC_STORE_U32(r29.u32 + 72, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stw r7,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r7.u32);
loc_821E022C:
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e028c
	if (cr6.eq) goto loc_821E028C;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x821e026c
	if (!cr6.lt) goto loc_821E026C;
loc_821E0240:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lwz r9,72(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x821e0240
	if (cr6.lt) goto loc_821E0240;
loc_821E026C:
	// slw r11,r18,r10
	r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r9,68(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// subf r31,r10,r31
	r31.s64 = r31.s64 - ctx.r10.s64;
	// and r11,r11,r30
	r11.u64 = r11.u64 & r30.u64;
	// srw r30,r30,r10
	r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 >> (ctx.r10.u8 & 0x3F));
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// stw r10,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r10.u32);
loc_821E028C:
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r10,68(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// subf r11,r14,r11
	r11.s64 = r11.s64 - r14.s64;
	// add r9,r11,r22
	ctx.r9.u64 = r11.u64 + r22.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x821e02ac
	if (!cr6.gt) goto loc_821E02AC;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// b 0x821e0454
	goto loc_821E0454;
loc_821E02AC:
	// li r11,22
	r11.s64 = 22;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821E02B4:
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// subf r9,r14,r22
	ctx.r9.s64 = r22.s64 - r14.s64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x821e030c
	if (!cr6.gt) goto loc_821E030C;
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r9,52(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x821e02f4
	if (!cr6.gt) goto loc_821E02F4;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// b 0x821e02fc
	goto loc_821E02FC;
loc_821E02F4:
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_821E02FC:
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x821e0318
	if (!cr6.gt) goto loc_821E0318;
	// b 0x821e0314
	goto loc_821E0314;
loc_821E030C:
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// subf r10,r11,r23
	ctx.r10.s64 = r23.s64 - r11.s64;
loc_821E0314:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821E0318:
	// cmplw cr6,r11,r14
	cr6.compare<uint32_t>(r11.u32, r14.u32, xer);
	// ble cr6,0x821e0324
	if (!cr6.gt) goto loc_821E0324;
	// mr r11,r14
	r11.u64 = r14.u64;
loc_821E0324:
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// subf r14,r11,r14
	r14.s64 = r14.s64 - r11.s64;
	// stw r9,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r9.u32);
loc_821E0330:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r23)
	PPC_STORE_U8(r23.u32 + 0, ctx.r9.u8);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// bne 0x821e0330
	if (!cr0.eq) goto loc_821E0330;
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e045c
	if (!cr6.eq) goto loc_821E045C;
	// li r11,18
	r11.s64 = 18;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821E0360:
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// li r10,18
	ctx.r10.s64 = 18;
	// addi r14,r14,-1
	r14.s64 = r14.s64 + -1;
	// stb r11,0(r23)
	PPC_STORE_U8(r23.u32 + 0, r11.u8);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x821e045c
	goto loc_821E045C;
loc_821E0384:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e03f4
	if (cr6.eq) goto loc_821E03F4;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x821e03c0
	if (!cr6.lt) goto loc_821E03C0;
loc_821E0398:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// blt cr6,0x821e0398
	if (cr6.lt) goto loc_821E0398;
loc_821E03C0:
	// lwz r10,20(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 20);
	// subf. r11,r14,r22
	r11.s64 = r22.s64 - r14.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,20(r17)
	PPC_STORE_U32(r17.u32 + 20, ctx.r10.u32);
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,28(r29)
	PPC_STORE_U32(r29.u32 + 28, ctx.r9.u32);
	// beq 0x821e03e8
	if (cr0.eq) goto loc_821E03E8;
	// stw r15,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r15.u32);
	// stw r15,48(r17)
	PPC_STORE_U32(r17.u32 + 48, r15.u32);
loc_821E03E8:
	// mr r22,r14
	r22.u64 = r14.u64;
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
loc_821E03F4:
	// li r11,25
	r11.s64 = 25;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821E03FC:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e04a0
	if (cr6.eq) goto loc_821E04A0;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e04a0
	if (cr6.eq) goto loc_821E04A0;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x821e0444
	if (!cr6.lt) goto loc_821E0444;
loc_821E041C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e04b4
	if (cr6.eq) goto loc_821E04B4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// blt cr6,0x821e041c
	if (cr6.lt) goto loc_821E041C;
loc_821E0444:
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x821e0498
	if (cr6.eq) goto loc_821E0498;
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
loc_821E0454:
	// stw r11,24(r17)
	PPC_STORE_U32(r17.u32 + 24, r11.u32);
loc_821E0458:
	// stw r16,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r16.u32);
loc_821E045C:
	// lwz r19,0(r29)
	r19.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r19,28
	cr6.compare<uint32_t>(r19.u32, 28, xer);
	// ble cr6,0x821defbc
	if (!cr6.gt) goto loc_821DEFBC;
loc_821E0468:
	// li r3,-2
	ctx.r3.s64 = -2;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_821E0474:
	// stw r23,12(r17)
	PPC_STORE_U32(r17.u32 + 12, r23.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r14,16(r17)
	PPC_STORE_U32(r17.u32 + 16, r14.u32);
	// stw r28,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r28.u32);
	// stw r27,4(r17)
	PPC_STORE_U32(r17.u32 + 4, r27.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r31.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_821E0498:
	// mr r30,r15
	r30.u64 = r15.u64;
	// mr r31,r15
	r31.u64 = r15.u64;
loc_821E04A0:
	// li r11,26
	r11.s64 = 26;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821E04A8:
	// mr r21,r18
	r21.u64 = r18.u64;
	// b 0x821e04b4
	goto loc_821E04B4;
loc_821E04B0:
	// li r21,-3
	r21.s64 = -3;
loc_821E04B4:
	// stw r23,12(r17)
	PPC_STORE_U32(r17.u32 + 12, r23.u32);
	// stw r27,4(r17)
	PPC_STORE_U32(r17.u32 + 4, r27.u32);
	// stw r14,16(r17)
	PPC_STORE_U32(r17.u32 + 16, r14.u32);
	// stw r28,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r28.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r31.u32);
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e04f0
	if (!cr6.eq) goto loc_821E04F0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,24
	cr6.compare<int32_t>(r11.s32, 24, xer);
	// bge cr6,0x821e0518
	if (!cr6.lt) goto loc_821E0518;
	// lwz r11,16(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// cmplw cr6,r22,r11
	cr6.compare<uint32_t>(r22.u32, r11.u32, xer);
	// beq cr6,0x821e0518
	if (cr6.eq) goto loc_821E0518;
loc_821E04F0:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821decf0
	ctx.lr = 0x821E04FC;
	sub_821DECF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821e0518
	if (cr6.eq) goto loc_821E0518;
	// li r11,28
	r11.s64 = 28;
	// li r3,-4
	ctx.r3.s64 = -4;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_821E0518:
	// lwz r11,4(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// lwz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r9,8(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 8);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// lwz r8,16(r17)
	ctx.r8.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// lwz r9,20(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 20);
	// subf r10,r8,r22
	ctx.r10.s64 = r22.s64 - ctx.r8.s64;
	// stw r7,8(r17)
	PPC_STORE_U32(r17.u32 + 8, ctx.r7.u32);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r6,20(r17)
	PPC_STORE_U32(r17.u32 + 20, ctx.r6.u32);
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stw r4,28(r29)
	PPC_STORE_U32(r29.u32 + 28, ctx.r4.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821e056c
	if (cr6.eq) goto loc_821E056C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e056c
	if (cr6.eq) goto loc_821E056C;
	// stw r15,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r15.u32);
	// stw r15,48(r17)
	PPC_STORE_U32(r17.u32 + 48, r15.u32);
loc_821E056C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r7,r11,-11
	ctx.r7.s64 = r11.s64 + -11;
	// lwz r9,60(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// subfic r6,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r8.s64;
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r8,r5,2,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x80;
	// rlwinm r11,r4,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// stw r3,44(r17)
	PPC_STORE_U32(r17.u32 + 44, ctx.r3.u32);
	// bne cr6,0x821e05ac
	if (!cr6.eq) goto loc_821E05AC;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e05b8
	if (cr6.eq) goto loc_821E05B8;
loc_821E05AC:
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x821e05c4
	if (!cr6.eq) goto loc_821E05C4;
loc_821E05B8:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x821e05c4
	if (!cr6.eq) goto loc_821E05C4;
	// li r21,-5
	r21.s64 = -5;
loc_821E05C4:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_821E05D0:
	// li r3,-4
	ctx.r3.s64 = -4;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E05E0"))) PPC_WEAK_FUNC(sub_821E05E0);
PPC_FUNC_IMPL(__imp__sub_821E05E0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e0660
	if (cr6.eq) goto loc_821E0660;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e0660
	if (cr6.eq) goto loc_821E0660;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e0660
	if (cr6.eq) goto loc_821E0660;
	// lwz r4,52(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821e062c
	if (cr6.eq) goto loc_821E062C;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821E062C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E062C:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821E0640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
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
loc_821E0660:
	// li r3,-2
	ctx.r3.s64 = -2;
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

__attribute__((alias("__imp__sub_821E0678"))) PPC_WEAK_FUNC(sub_821E0678);
PPC_FUNC_IMPL(__imp__sub_821E0678) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x821E0680;
	// cmpwi cr6,r4,16
	cr6.compare<int32_t>(ctx.r4.s32, 16, xer);
	// beq cr6,0x821e0698
	if (cr6.eq) goto loc_821E0698;
	// cmpwi cr6,r4,24
	cr6.compare<int32_t>(ctx.r4.s32, 24, xer);
	// beq cr6,0x821e0698
	if (cr6.eq) goto loc_821E0698;
	// cmpwi cr6,r4,32
	cr6.compare<int32_t>(ctx.r4.s32, 32, xer);
	// bne cr6,0x821e0fe8
	if (!cr6.eq) goto loc_821E0FE8;
loc_821E0698:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821e06b8
	if (cr6.eq) goto loc_821E06B8;
	// srawi r11,r4,3
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	r11.s64 = ctx.r4.s32 >> 3;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r5,r9
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, xer);
	// bne cr6,0x821e0fe8
	if (!cr6.eq) goto loc_821E0FE8;
loc_821E06B8:
	// srawi r11,r4,3
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	r11.s64 = ctx.r4.s32 >> 3;
	// addi r8,r6,4
	ctx.r8.s64 = ctx.r6.s64 + 4;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// cmpwi cr6,r4,16
	cr6.compare<int32_t>(ctx.r4.s32, 16, xer);
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,480(r6)
	PPC_STORE_U32(ctx.r6.u32 + 480, ctx.r9.u32);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r5,2(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r11,3(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r10,r7,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 | ctx.r5.u64;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 | r11.u64;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r9,7(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// rotlwi r5,r7,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// or r11,r5,r11
	r11.u64 = ctx.r5.u64 | r11.u64;
	// rlwinm r7,r11,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r11,r5,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r9
	ctx.r10.u64 = r11.u64 | ctx.r9.u64;
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// lbz r7,10(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// lbz r5,11(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 8);
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r11,r9,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r7
	ctx.r10.u64 = r11.u64 | ctx.r7.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 | ctx.r5.u64;
	// stw r7,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r7.u32);
	// lbz r5,13(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lbz r11,14(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14);
	// lbz r10,15(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 15);
	// lbz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// rlwinm r9,r5,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 | r11.u64;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r5,r10
	r11.u64 = ctx.r5.u64 | ctx.r10.u64;
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// bne cr6,0x821e08c0
	if (!cr6.eq) goto loc_821E08C0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r11,r11,29088
	r11.s64 = r11.s64 + 29088;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r9,r7,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// lwz r31,8(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// rlwinm r28,r7,26,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// addi r29,r11,-1024
	r29.s64 = r11.s64 + -1024;
	// addi r10,r11,-1024
	ctx.r10.s64 = r11.s64 + -1024;
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// lwzx r9,r9,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r30,r7,10,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// lwzx r29,r28,r29
	r29.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r9,r9,0,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFF000000;
	// rlwinm r28,r7,2,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// xoris r26,r9,256
	r26.u64 = ctx.r9.u64 ^ 16777216;
	// rlwinm r29,r29,0,8,15
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFF0000;
	// lbzx r30,r30,r10
	r30.u64 = PPC_LOAD_U8(r30.u32 + ctx.r10.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// or r29,r26,r29
	r29.u64 = r26.u64 | r29.u64;
	// lwzx r28,r28,r27
	r28.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// addi r9,r11,2048
	ctx.r9.s64 = r11.s64 + 2048;
	// xor r8,r29,r30
	ctx.r8.u64 = r29.u64 ^ r30.u64;
	// rlwinm r30,r28,0,16,23
	r30.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFF00;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// xor r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 ^ r30.u64;
	// xor r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r4.u64;
	// xor r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r3.u64;
	// stw r4,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r4.u32);
	// xor r8,r3,r31
	ctx.r8.u64 = ctx.r3.u64 ^ r31.u64;
	// stw r3,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r3.u32);
	// xor r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// stw r8,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r8.u32);
	// stw r7,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r7.u32);
loc_821E0820:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r8,r11,-1024
	ctx.r8.s64 = r11.s64 + -1024;
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// addi r3,r11,-1024
	ctx.r3.s64 = r11.s64 + -1024;
	// addi r29,r8,3
	r29.s64 = ctx.r8.s64 + 3;
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r8,r11,2048
	ctx.r8.s64 = r11.s64 + 2048;
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// lwz r28,-4(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// rlwinm r27,r30,26,22,29
	r27.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 26) & 0x3FC;
	// rlwinm r26,r30,18,22,29
	r26.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 18) & 0x3FC;
	// rlwinm r25,r30,10,22,29
	r25.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 10) & 0x3FC;
	// rlwinm r30,r30,2,22,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// addi r8,r8,40
	ctx.r8.s64 = ctx.r8.s64 + 40;
	// lwzx r4,r27,r4
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + ctx.r4.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lwzx r3,r26,r3
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r3.u32);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// lbzx r29,r25,r29
	r29.u64 = PPC_LOAD_U8(r25.u32 + r29.u32);
	// rlwimi r4,r3,0,0,7
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 0) & 0xFF000000) | (ctx.r4.u64 & 0xFFFFFFFF00FFFFFF);
	// lwzx r8,r30,r31
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// rlwinm r4,r4,0,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFF0000;
	// rlwinm r3,r8,0,16,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFF00;
	// xor r8,r4,r29
	ctx.r8.u64 = ctx.r4.u64 ^ r29.u64;
	// xor r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// xor r3,r4,r28
	ctx.r3.u64 = ctx.r4.u64 ^ r28.u64;
	// xor r8,r3,r7
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// stw r8,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r8.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// xor r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// stw r4,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// xor r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// stw r8,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// xor r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// stw r4,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r4.u32);
	// bne cr6,0x821e0820
	if (!cr6.eq) goto loc_821E0820;
	// b 0x821e0d18
	goto loc_821E0D18;
loc_821E08C0:
	// cmpwi cr6,r4,24
	cr6.compare<int32_t>(ctx.r4.s32, 24, xer);
	// bne cr6,0x821e0a8c
	if (!cr6.eq) goto loc_821E0A8C;
	// lbz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lbz r9,17(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// li r5,52
	ctx.r5.s64 = 52;
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r4,18(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 18);
	// addi r11,r11,29088
	r11.s64 = r11.s64 + 29088;
	// lbz r31,19(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 19);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// addi r10,r11,-1024
	ctx.r10.s64 = r11.s64 + -1024;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// addi r30,r10,3
	r30.s64 = ctx.r10.s64 + 3;
	// or r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 | ctx.r4.u64;
	// addi r29,r11,-1024
	r29.s64 = r11.s64 + -1024;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// or r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 | r31.u64;
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// stw r10,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r10.u32);
	// addi r9,r11,2048
	ctx.r9.s64 = r11.s64 + 2048;
	// lbz r28,22(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// addi r10,r6,40
	ctx.r10.s64 = ctx.r6.s64 + 40;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lbz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// lbz r26,21(r3)
	r26.u64 = PPC_LOAD_U8(ctx.r3.u32 + 21);
	// rotlwi r27,r7,8
	r27.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// lbz r3,23(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 23);
	// subfic r7,r6,-40
	xer.ca = ctx.r6.u32 <= 4294967256;
	ctx.r7.s64 = -40 - ctx.r6.s64;
	// or r27,r27,r26
	r27.u64 = r27.u64 | r26.u64;
	// rlwinm r27,r27,8,0,23
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 8) & 0xFFFFFF00;
	// or r28,r27,r28
	r28.u64 = r27.u64 | r28.u64;
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r28,r3
	ctx.r3.u64 = r28.u64 | ctx.r3.u64;
	// stw r3,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r3.u32);
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r26,12(r6)
	r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r27,20(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// rlwinm r25,r27,10,22,29
	r25.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 10) & 0x3FC;
	// lbzx r30,r25,r30
	r30.u64 = PPC_LOAD_U8(r25.u32 + r30.u32);
	// rlwinm r23,r27,18,22,29
	r23.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 18) & 0x3FC;
	// rlwinm r24,r27,2,22,29
	r24.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x3FC;
	// lwz r28,8(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// rlwinm r27,r27,26,22,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 26) & 0x3FC;
	// lwzx r4,r23,r4
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + ctx.r4.u32);
	// rlwinm r4,r4,0,0,7
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFF000000;
	// lwzx r31,r27,r31
	r31.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// xoris r4,r4,256
	ctx.r4.u64 = ctx.r4.u64 ^ 16777216;
	// rlwinm r31,r31,0,8,15
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFF0000;
	// lwzx r29,r24,r29
	r29.u64 = PPC_LOAD_U32(r24.u32 + r29.u32);
	// or r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 | r31.u64;
	// rlwinm r29,r29,0,16,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFF00;
	// xor r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 ^ r30.u64;
	// xor r4,r4,r29
	ctx.r4.u64 = ctx.r4.u64 ^ r29.u64;
	// xor r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r3.u64;
	// xor r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r8.u64;
	// stw r3,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r3.u32);
	// xor r4,r8,r28
	ctx.r4.u64 = ctx.r8.u64 ^ r28.u64;
	// stw r8,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r8.u32);
	// xor r3,r4,r26
	ctx.r3.u64 = ctx.r4.u64 ^ r26.u64;
	// stw r4,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r4.u32);
	// stw r3,36(r6)
	PPC_STORE_U32(ctx.r6.u32 + 36, ctx.r3.u32);
loc_821E09C0:
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r8,r11,-1024
	ctx.r8.s64 = r11.s64 + -1024;
	// lwz r4,-24(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// lwz r30,-20(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	// addi r29,r8,3
	r29.s64 = ctx.r8.s64 + 3;
	// xor r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r3.u64;
	// addi r8,r11,2048
	ctx.r8.s64 = r11.s64 + 2048;
	// xor r3,r30,r4
	ctx.r3.u64 = r30.u64 ^ ctx.r4.u64;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addi r4,r8,32
	ctx.r4.s64 = ctx.r8.s64 + 32;
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// srawi r8,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// lwz r27,-40(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// addi r8,r8,5
	ctx.r8.s64 = ctx.r8.s64 + 5;
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r4,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// rlwinm r4,r8,10,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x3FC;
	// lbzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + r29.u32);
	// rlwinm r26,r8,26,22,29
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FC;
	// rlwinm r25,r8,18,22,29
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0x3FC;
	// rlwinm r8,r8,2,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// lwzx r31,r26,r31
	r31.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// lwzx r30,r25,r30
	r30.u64 = PPC_LOAD_U32(r25.u32 + r30.u32);
	// rlwimi r31,r30,0,0,7
	r31.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0xFF000000) | (r31.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r31,r31,0,0,15
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFF0000;
	// lwzx r8,r8,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// rlwinm r8,r8,0,16,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFF00;
	// xor r4,r31,r4
	ctx.r4.u64 = r31.u64 ^ ctx.r4.u64;
	// xor r4,r4,r8
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// xor r8,r4,r27
	ctx.r8.u64 = ctx.r4.u64 ^ r27.u64;
	// xor r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// stw r4,-16(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16, ctx.r4.u32);
	// lwz r3,-36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -36);
	// xor r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// stw r8,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r8.u32);
	// lwz r4,-32(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32);
	// xor r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// stw r3,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r3.u32);
	// lwz r8,-28(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28);
	// xor r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// stw r4,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r4.u32);
	// bne cr6,0x821e09c0
	if (!cr6.eq) goto loc_821E09C0;
	// b 0x821e0d18
	goto loc_821E0D18;
loc_821E0A8C:
	// cmpwi cr6,r4,32
	cr6.compare<int32_t>(ctx.r4.s32, 32, xer);
	// bne cr6,0x821e0fe8
	if (!cr6.eq) goto loc_821E0FE8;
	// lbz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lbz r9,17(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// li r5,60
	ctx.r5.s64 = 60;
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r4,18(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 18);
	// addi r11,r11,29088
	r11.s64 = r11.s64 + 29088;
	// lbz r31,19(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 19);
	// or r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 | ctx.r9.u64;
	// addi r7,r11,-1024
	ctx.r7.s64 = r11.s64 + -1024;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// addi r10,r11,-1024
	ctx.r10.s64 = r11.s64 + -1024;
	// or r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 | ctx.r4.u64;
	// addi r30,r10,3
	r30.s64 = ctx.r10.s64 + 3;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// or r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 | r31.u64;
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// stw r10,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r10.u32);
	// addi r9,r11,2048
	ctx.r9.s64 = r11.s64 + 2048;
	// lbz r27,21(r3)
	r27.u64 = PPC_LOAD_U8(ctx.r3.u32 + 21);
	// addi r10,r6,48
	ctx.r10.s64 = ctx.r6.s64 + 48;
	// lbz r26,23(r3)
	r26.u64 = PPC_LOAD_U8(ctx.r3.u32 + 23);
	// lbz r28,20(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// rotlwi r28,r28,8
	r28.u64 = __builtin_rotateleft32(r28.u32, 8);
	// or r28,r28,r27
	r28.u64 = r28.u64 | r27.u64;
	// lbz r29,22(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// or r29,r28,r29
	r29.u64 = r28.u64 | r29.u64;
	// rlwinm r29,r29,8,0,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFFFFFF00;
	// or r29,r29,r26
	r29.u64 = r29.u64 | r26.u64;
	// stw r29,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r29.u32);
	// lbz r28,25(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 25);
	// lbz r26,27(r3)
	r26.u64 = PPC_LOAD_U8(ctx.r3.u32 + 27);
	// lbz r29,24(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// rotlwi r29,r29,8
	r29.u64 = __builtin_rotateleft32(r29.u32, 8);
	// or r29,r29,r28
	r29.u64 = r29.u64 | r28.u64;
	// lbz r27,26(r3)
	r27.u64 = PPC_LOAD_U8(ctx.r3.u32 + 26);
	// rlwinm r29,r29,8,0,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFFFFFF00;
	// or r29,r29,r27
	r29.u64 = r29.u64 | r27.u64;
	// rlwinm r29,r29,8,0,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFFFFFF00;
	// or r29,r29,r26
	r29.u64 = r29.u64 | r26.u64;
	// stw r29,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, r29.u32);
	// lbz r29,31(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 31);
	// lbz r28,28(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 28);
	// rotlwi r28,r28,8
	r28.u64 = __builtin_rotateleft32(r28.u32, 8);
	// lbz r27,29(r3)
	r27.u64 = PPC_LOAD_U8(ctx.r3.u32 + 29);
	// or r28,r28,r27
	r28.u64 = r28.u64 | r27.u64;
	// rlwinm r28,r28,8,0,23
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r3,30(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 30);
	// or r3,r28,r3
	ctx.r3.u64 = r28.u64 | ctx.r3.u64;
	// rlwinm r3,r3,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 | r29.u64;
	// stw r3,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r27,0(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r29,r3,26,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r28,r3,2,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwz r26,8(r6)
	r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r25,12(r6)
	r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwzx r7,r29,r7
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// rlwinm r29,r3,10,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// lwzx r4,r28,r4
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + ctx.r4.u32);
	// rlwinm r3,r3,18,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r7,r7,0,8,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFF0000;
	// lbzx r30,r29,r30
	r30.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// rlwinm r4,r4,0,16,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFF00;
	// lwzx r3,r3,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r31.u32);
	// rlwinm r3,r3,0,0,7
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFF000000;
	// xoris r3,r3,256
	ctx.r3.u64 = ctx.r3.u64 ^ 16777216;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// xor r7,r3,r30
	ctx.r7.u64 = ctx.r3.u64 ^ r30.u64;
	// xor r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// xor r3,r4,r27
	ctx.r3.u64 = ctx.r4.u64 ^ r27.u64;
	// xor r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r8.u64;
	// stw r3,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r3.u32);
	// xor r7,r8,r26
	ctx.r7.u64 = ctx.r8.u64 ^ r26.u64;
	// stw r8,36(r6)
	PPC_STORE_U32(ctx.r6.u32 + 36, ctx.r8.u32);
	// stw r7,40(r6)
	PPC_STORE_U32(ctx.r6.u32 + 40, ctx.r7.u32);
	// xor r4,r7,r25
	ctx.r4.u64 = ctx.r7.u64 ^ r25.u64;
	// subfic r7,r6,-48
	xer.ca = ctx.r6.u32 <= 4294967248;
	ctx.r7.s64 = -48 - ctx.r6.s64;
	// stw r4,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r4.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_821E0BE4:
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// addi r3,r11,-1024
	ctx.r3.s64 = r11.s64 + -1024;
	// lwz r31,-32(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32);
	// rlwinm r28,r8,24,8,31
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// lwz r29,-28(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28);
	// rlwinm r30,r8,24,0,7
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// lwz r27,-24(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	// addi r8,r11,-1024
	ctx.r8.s64 = r11.s64 + -1024;
	// lwz r26,-20(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	// or r30,r30,r28
	r30.u64 = r30.u64 | r28.u64;
	// addi r28,r8,3
	r28.s64 = ctx.r8.s64 + 3;
	// rlwinm r8,r30,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 26) & 0x3FC;
	// rlwinm r25,r30,18,22,29
	r25.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 18) & 0x3FC;
	// rlwinm r23,r30,10,22,29
	r23.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 10) & 0x3FC;
	// rlwinm r30,r30,2,22,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// addi r24,r11,-1024
	r24.s64 = r11.s64 + -1024;
	// lwzx r4,r8,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// addi r8,r11,-1024
	ctx.r8.s64 = r11.s64 + -1024;
	// lwzx r3,r25,r3
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + ctx.r3.u32);
	// addi r25,r11,-1024
	r25.s64 = r11.s64 + -1024;
	// addi r22,r8,3
	r22.s64 = ctx.r8.s64 + 3;
	// rlwimi r4,r3,0,0,7
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 0) & 0xFF000000) | (ctx.r4.u64 & 0xFFFFFFFF00FFFFFF);
	// lbzx r3,r23,r28
	ctx.r3.u64 = PPC_LOAD_U8(r23.u32 + r28.u32);
	// lwzx r30,r30,r24
	r30.u64 = PPC_LOAD_U32(r30.u32 + r24.u32);
	// addi r8,r11,2048
	ctx.r8.s64 = r11.s64 + 2048;
	// rlwinm r4,r4,0,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFF0000;
	// rlwinm r30,r30,0,16,23
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFF00;
	// xor r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r3.u64;
	// addi r4,r8,28
	ctx.r4.s64 = ctx.r8.s64 + 28;
	// xor r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 ^ r30.u64;
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// xor r8,r3,r31
	ctx.r8.u64 = ctx.r3.u64 ^ r31.u64;
	// addi r3,r11,-1024
	ctx.r3.s64 = r11.s64 + -1024;
	// xor r31,r29,r8
	r31.u64 = r29.u64 ^ ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// xor r8,r27,r31
	ctx.r8.u64 = r27.u64 ^ r31.u64;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// xor r31,r26,r8
	r31.u64 = r26.u64 ^ ctx.r8.u64;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r31,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r31.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// lwz r31,0(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// srawi r8,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// lwz r4,-48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -48);
	// addi r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 + 7;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// rlwinm r29,r8,2,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// rlwinm r28,r8,10,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x3FC;
	// lwzx r29,r29,r25
	r29.u64 = PPC_LOAD_U32(r29.u32 + r25.u32);
	// rlwinm r27,r8,26,22,29
	r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FC;
	// rlwinm r8,r8,18,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0x3FC;
	// lbzx r28,r28,r22
	r28.u64 = PPC_LOAD_U8(r28.u32 + r22.u32);
	// lwzx r30,r27,r30
	r30.u64 = PPC_LOAD_U32(r27.u32 + r30.u32);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// rlwimi r30,r3,0,0,7
	r30.u64 = (__builtin_rotateleft32(ctx.r3.u32, 0) & 0xFF000000) | (r30.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r8,r30,0,0,15
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFF0000;
	// rlwinm r3,r29,0,16,23
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFF00;
	// xor r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 ^ r28.u64;
	// xor r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// xor r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// xor r4,r8,r31
	ctx.r4.u64 = ctx.r8.u64 ^ r31.u64;
	// stw r4,-16(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16, ctx.r4.u32);
	// lwz r3,-44(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -44);
	// xor r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// stw r8,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r8.u32);
	// lwz r4,-40(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	// xor r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// stw r3,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r3.u32);
	// lwz r8,-36(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -36);
	// xor r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// stw r4,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r4.u32);
	// bne cr6,0x821e0be4
	if (!cr6.eq) goto loc_821E0BE4;
loc_821E0D18:
	// addi r9,r5,-4
	ctx.r9.s64 = ctx.r5.s64 + -4;
	// addi r10,r6,240
	ctx.r10.s64 = ctx.r6.s64 + 240;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r7,240(r6)
	PPC_STORE_U32(ctx.r6.u32 + 240, ctx.r7.u32);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// addi r9,r7,-12
	ctx.r9.s64 = ctx.r7.s64 + -12;
	// lwz r7,480(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 480);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x821e0fb0
	if (!cr6.gt) goto loc_821E0FB0;
loc_821E0D78:
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// addi r7,r11,-1024
	ctx.r7.s64 = r11.s64 + -1024;
	// addi r5,r11,-1024
	ctx.r5.s64 = r11.s64 + -1024;
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// addi r3,r11,-1024
	ctx.r3.s64 = r11.s64 + -1024;
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r26,r11,-1024
	r26.s64 = r11.s64 + -1024;
	// rlwinm r29,r31,26,22,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 26) & 0x3FC;
	// rlwinm r28,r31,2,22,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x3FC;
	// rlwinm r27,r31,18,22,29
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 18) & 0x3FC;
	// rlwinm r31,r31,10,22,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 10) & 0x3FC;
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// lwzx r7,r29,r7
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// addi r29,r11,-1024
	r29.s64 = r11.s64 + -1024;
	// lwzx r5,r28,r5
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + ctx.r5.u32);
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// lwzx r4,r27,r4
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + ctx.r4.u32);
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r31,r3
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// lwzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// addi r25,r11,-1024
	r25.s64 = r11.s64 + -1024;
	// lwzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// rlwinm r24,r7,16,16,31
	r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF;
	// rlwinm r23,r5,8,24,31
	r23.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF;
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r22,r4,24,0,7
	r22.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// or r7,r24,r7
	ctx.r7.u64 = r24.u64 | ctx.r7.u64;
	// rlwinm r4,r4,24,8,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFFFFFF;
	// or r5,r23,r5
	ctx.r5.u64 = r23.u64 | ctx.r5.u64;
	// or r4,r22,r4
	ctx.r4.u64 = r22.u64 | ctx.r4.u64;
	// xor r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 ^ ctx.r7.u64;
	// addi r5,r11,-1024
	ctx.r5.s64 = r11.s64 + -1024;
	// xor r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// addi r7,r11,-1024
	ctx.r7.s64 = r11.s64 + -1024;
	// xor r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r3.u64;
	// addi r3,r11,-1024
	ctx.r3.s64 = r11.s64 + -1024;
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// addi r4,r11,-1024
	ctx.r4.s64 = r11.s64 + -1024;
	// lwz r24,4(r10)
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r22,r24,2,22,29
	r22.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FC;
	// lwzx r26,r22,r26
	r26.u64 = PPC_LOAD_U32(r22.u32 + r26.u32);
	// rlwinm r23,r24,26,22,29
	r23.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 26) & 0x3FC;
	// rlwinm r21,r24,18,22,29
	r21.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 18) & 0x3FC;
	// rlwinm r24,r24,10,22,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 10) & 0x3FC;
	// lwzx r30,r23,r30
	r30.u64 = PPC_LOAD_U32(r23.u32 + r30.u32);
	// rlwinm r30,r30,2,22,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// lwzx r29,r21,r29
	r29.u64 = PPC_LOAD_U32(r21.u32 + r29.u32);
	// rlwinm r26,r26,2,22,29
	r26.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0x3FC;
	// lwzx r30,r30,r11
	r30.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// rlwinm r29,r29,2,22,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// lwzx r28,r24,r28
	r28.u64 = PPC_LOAD_U32(r24.u32 + r28.u32);
	// rlwinm r24,r30,16,16,31
	r24.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF;
	// lwzx r26,r26,r11
	r26.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// rlwinm r30,r30,16,0,15
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// lwzx r29,r29,r11
	r29.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// rlwinm r23,r26,8,24,31
	r23.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFF;
	// rlwinm r26,r26,8,0,23
	r26.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFFFFFF00;
	// or r30,r24,r30
	r30.u64 = r24.u64 | r30.u64;
	// rlwinm r24,r29,24,0,7
	r24.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFF000000;
	// rlwinm r28,r28,2,22,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FC;
	// or r26,r23,r26
	r26.u64 = r23.u64 | r26.u64;
	// rlwinm r29,r29,24,8,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFFFFFF;
	// xor r30,r26,r30
	r30.u64 = r26.u64 ^ r30.u64;
	// or r29,r24,r29
	r29.u64 = r24.u64 | r29.u64;
	// lwzx r28,r28,r11
	r28.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// xor r30,r30,r29
	r30.u64 = r30.u64 ^ r29.u64;
	// xor r30,r30,r28
	r30.u64 = r30.u64 ^ r28.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r29,r30,2,22,29
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// rlwinm r28,r30,26,22,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 26) & 0x3FC;
	// rlwinm r26,r30,18,22,29
	r26.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 18) & 0x3FC;
	// lwzx r31,r29,r31
	r31.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// rlwinm r30,r30,10,22,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 10) & 0x3FC;
	// lwzx r29,r28,r27
	r29.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// lwzx r27,r26,r25
	r27.u64 = PPC_LOAD_U32(r26.u32 + r25.u32);
	// rlwinm r31,r31,2,22,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x3FC;
	// rlwinm r29,r29,2,22,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// rlwinm r27,r27,2,22,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x3FC;
	// lwzx r5,r30,r5
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + ctx.r5.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r31,r31,r11
	r31.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// lwzx r30,r29,r11
	r30.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwzx r29,r27,r11
	r29.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// rlwinm r27,r31,8,24,31
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFF;
	// rlwinm r26,r30,16,16,31
	r26.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF;
	// rlwinm r30,r30,16,0,15
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// or r30,r26,r30
	r30.u64 = r26.u64 | r30.u64;
	// rlwinm r26,r29,24,0,7
	r26.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFF000000;
	// or r31,r27,r31
	r31.u64 = r27.u64 | r31.u64;
	// rlwinm r29,r29,24,8,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFFFFFF;
	// xor r31,r31,r30
	r31.u64 = r31.u64 ^ r30.u64;
	// or r29,r26,r29
	r29.u64 = r26.u64 | r29.u64;
	// xor r31,r31,r29
	r31.u64 = r31.u64 ^ r29.u64;
	// xor r5,r31,r5
	ctx.r5.u64 = r31.u64 ^ ctx.r5.u64;
	// stw r5,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r29,r5,18,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 18) & 0x3FC;
	// rlwinm r30,r5,26,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0x3FC;
	// rlwinm r31,r5,2,22,29
	r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// rlwinm r5,r5,10,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0x3FC;
	// lwzx r3,r29,r3
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// lwzx r4,r30,r4
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r4.u32);
	// lwzx r7,r31,r7
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// lwzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwzx r5,r5,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r28.u32);
	// rlwinm r31,r7,8,24,31
	r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFF;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// lwzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// or r7,r31,r7
	ctx.r7.u64 = r31.u64 | ctx.r7.u64;
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// rlwinm r30,r4,16,16,31
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF;
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// rlwinm r4,r4,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r3,24,0,7
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF000000;
	// or r4,r30,r4
	ctx.r4.u64 = r30.u64 | ctx.r4.u64;
	// rlwinm r3,r3,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// xor r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// or r4,r31,r3
	ctx.r4.u64 = r31.u64 | ctx.r3.u64;
	// xor r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// xor r7,r3,r5
	ctx.r7.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// lwz r5,480(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 480);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x821e0d78
	if (cr6.lt) goto loc_821E0D78;
loc_821E0FB0:
	// addi r11,r10,-16
	r11.s64 = ctx.r10.s64 + -16;
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// b 0x823d922c
	return;
loc_821E0FE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821E0FF0"))) PPC_WEAK_FUNC(sub_821E0FF0);
PPC_FUNC_IMPL(__imp__sub_821E0FF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x821E0FF8;
	// lbz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lbz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// addi r10,r5,240
	ctx.r10.s64 = ctx.r5.s64 + 240;
	// rotlwi r6,r9,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r7,5(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r9,9(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// lbz r31,12(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// or r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 | ctx.r7.u64;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lbz r6,13(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// rotlwi r8,r31,8
	ctx.r8.u64 = __builtin_rotateleft32(r31.u32, 8);
	// lbz r30,10(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r31,6(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// lbz r6,14(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14);
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r29,0(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r28,11(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// or r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 | r30.u64;
	// lbz r30,7(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// or r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 | r31.u64;
	// lbz r31,1(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// lbz r25,15(r3)
	r25.u64 = PPC_LOAD_U8(ctx.r3.u32 + 15);
	// rotlwi r29,r29,8
	r29.u64 = __builtin_rotateleft32(r29.u32, 8);
	// lwz r26,248(r5)
	r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + 248);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r27,244(r5)
	r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + 244);
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r6,252(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 252);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r29,r31
	r31.u64 = r29.u64 | r31.u64;
	// lbz r29,2(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// or r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 | r28.u64;
	// lbz r3,3(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | r30.u64;
	// lwz r30,240(r5)
	r30.u64 = PPC_LOAD_U32(ctx.r5.u32 + 240);
	// or r8,r8,r25
	ctx.r8.u64 = ctx.r8.u64 | r25.u64;
	// lwz r5,480(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 480);
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,30112
	r11.s64 = r11.s64 + 30112;
	// xor r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 ^ r26.u64;
	// xor r7,r7,r27
	ctx.r7.u64 = ctx.r7.u64 ^ r27.u64;
	// xor r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// or r31,r31,r29
	r31.u64 = r31.u64 | r29.u64;
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// rlwinm r8,r9,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FC;
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// rlwinm r29,r7,2,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// addi r26,r11,-1024
	r26.s64 = r11.s64 + -1024;
	// rlwinm r25,r6,18,22,29
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC;
	// lwzx r8,r8,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// or r3,r31,r3
	ctx.r3.u64 = r31.u64 | ctx.r3.u64;
	// lwzx r31,r29,r27
	r31.u64 = PPC_LOAD_U32(r29.u32 + r27.u32);
	// rlwinm r28,r8,16,16,31
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF;
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r27,r31,8,24,31
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFF;
	// xor r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 ^ r30.u64;
	// lwzx r30,r25,r26
	r30.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r28,r8
	ctx.r8.u64 = r28.u64 | ctx.r8.u64;
	// or r31,r27,r31
	r31.u64 = r27.u64 | r31.u64;
	// rlwinm r28,r30,24,0,7
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF000000;
	// rlwinm r30,r30,24,8,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFFFFFF;
	// addi r29,r11,-1024
	r29.s64 = r11.s64 + -1024;
	// rlwinm r27,r3,10,22,29
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// xor r8,r31,r8
	ctx.r8.u64 = r31.u64 ^ ctx.r8.u64;
	// or r31,r28,r30
	r31.u64 = r28.u64 | r30.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// xor r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 ^ r31.u64;
	// lwzx r29,r27,r29
	r29.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// xor r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 ^ r29.u64;
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r29,4(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// xor r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 ^ r31.u64;
	// stw r8,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, ctx.r8.u32);
	// rlwinm r8,r3,18,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r24,r9,2,22,29
	r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwz r26,12(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r22,r6,2,22,29
	r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwz r28,8(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r31,r11,-1024
	r31.s64 = r11.s64 + -1024;
	// addi r25,r11,-1024
	r25.s64 = r11.s64 + -1024;
	// lwzx r8,r8,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// rlwinm r23,r3,26,22,29
	r23.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// rlwinm r30,r7,26,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// lwzx r31,r24,r31
	r31.u64 = PPC_LOAD_U32(r24.u32 + r31.u32);
	// addi r21,r11,-1024
	r21.s64 = r11.s64 + -1024;
	// lwzx r25,r22,r25
	r25.u64 = PPC_LOAD_U32(r22.u32 + r25.u32);
	// addi r20,r11,-1024
	r20.s64 = r11.s64 + -1024;
	// lwzx r27,r23,r27
	r27.u64 = PPC_LOAD_U32(r23.u32 + r27.u32);
	// rlwinm r22,r6,26,22,29
	r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x3FC;
	// addi r24,r11,-1024
	r24.s64 = r11.s64 + -1024;
	// rlwinm r19,r7,18,22,29
	r19.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// lwzx r30,r30,r21
	r30.u64 = PPC_LOAD_U32(r30.u32 + r21.u32);
	// addi r23,r11,-1024
	r23.s64 = r11.s64 + -1024;
	// lwzx r3,r3,r20
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r20.u32);
	// rlwinm r20,r9,18,22,29
	r20.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 18) & 0x3FC;
	// addi r21,r11,-1024
	r21.s64 = r11.s64 + -1024;
	// lwzx r24,r22,r24
	r24.u64 = PPC_LOAD_U32(r22.u32 + r24.u32);
	// rlwinm r22,r8,24,0,7
	r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// rlwinm r18,r31,8,24,31
	r18.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFF;
	// lwzx r23,r19,r23
	r23.u64 = PPC_LOAD_U32(r19.u32 + r23.u32);
	// rlwinm r8,r8,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r19,r27,16,16,31
	r19.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 16) & 0xFFFF;
	// lwzx r21,r20,r21
	r21.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// rlwinm r20,r25,8,24,31
	r20.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 8) & 0xFF;
	// rlwinm r17,r3,8,24,31
	r17.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r16,r30,16,16,31
	r16.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF;
	// rlwinm r27,r27,16,0,15
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r3,r3,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r25,r25,8,0,23
	r25.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r30,r30,16,0,15
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// or r8,r22,r8
	ctx.r8.u64 = r22.u64 | ctx.r8.u64;
	// or r31,r18,r31
	r31.u64 = r18.u64 | r31.u64;
	// rlwinm r22,r24,16,16,31
	r22.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0xFFFF;
	// or r27,r19,r27
	r27.u64 = r19.u64 | r27.u64;
	// or r25,r20,r25
	r25.u64 = r20.u64 | r25.u64;
	// rlwinm r7,r7,10,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// or r3,r17,r3
	ctx.r3.u64 = r17.u64 | ctx.r3.u64;
	// or r30,r16,r30
	r30.u64 = r16.u64 | r30.u64;
	// rlwinm r19,r21,24,0,7
	r19.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 24) & 0xFF000000;
	// addi r15,r11,-1024
	r15.s64 = r11.s64 + -1024;
	// rlwinm r24,r24,16,0,15
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r6,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r20,r23,24,0,7
	r20.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 24) & 0xFF000000;
	// rlwinm r21,r21,24,8,31
	r21.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 24) & 0xFFFFFF;
	// addi r18,r11,-1024
	r18.s64 = r11.s64 + -1024;
	// lwzx r7,r7,r15
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r15.u32);
	// xor r8,r31,r8
	ctx.r8.u64 = r31.u64 ^ ctx.r8.u64;
	// rlwinm r9,r9,10,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x3FC;
	// addi r14,r11,-1024
	r14.s64 = r11.s64 + -1024;
	// rlwinm r23,r23,24,8,31
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 24) & 0xFFFFFF;
	// or r31,r22,r24
	r31.u64 = r22.u64 | r24.u64;
	// lwzx r6,r6,r18
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r18.u32);
	// xor r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 ^ r30.u64;
	// xor r27,r25,r27
	r27.u64 = r25.u64 ^ r27.u64;
	// or r30,r19,r21
	r30.u64 = r19.u64 | r21.u64;
	// lwzx r9,r9,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r14.u32);
	// or r25,r20,r23
	r25.u64 = r20.u64 | r23.u64;
	// xor r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 ^ r31.u64;
	// xor r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 ^ r30.u64;
	// xor r31,r27,r25
	r31.u64 = r27.u64 ^ r25.u64;
	// xor r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// xor r6,r3,r6
	ctx.r6.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// xor r9,r31,r9
	ctx.r9.u64 = r31.u64 ^ ctx.r9.u64;
	// xor r7,r8,r29
	ctx.r7.u64 = ctx.r8.u64 ^ r29.u64;
	// xor r8,r6,r26
	ctx.r8.u64 = ctx.r6.u64 ^ r26.u64;
	// lwz r6,-160(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// addic. r5,r5,-2
	xer.ca = ctx.r5.u32 > 1;
	ctx.r5.s64 = ctx.r5.s64 + -2;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// xor r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 ^ r28.u64;
	// beq 0x821e142c
	if (cr0.eq) goto loc_821E142C;
loc_821E127C:
	// rlwinm r31,r7,2,22,29
	r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// addi r29,r11,-1024
	r29.s64 = r11.s64 + -1024;
	// rlwinm r26,r9,26,22,29
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FC;
	// addi r30,r11,-1024
	r30.s64 = r11.s64 + -1024;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// rlwinm r25,r8,26,22,29
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FC;
	// rlwinm r24,r9,2,22,29
	r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r31,r31,r29
	r31.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// lwzx r30,r26,r30
	r30.u64 = PPC_LOAD_U32(r26.u32 + r30.u32);
	// rlwinm r29,r3,18,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// addi r23,r11,-1024
	r23.s64 = r11.s64 + -1024;
	// addi r22,r11,-1024
	r22.s64 = r11.s64 + -1024;
	// rlwinm r26,r8,18,22,29
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0x3FC;
	// lwzx r28,r25,r28
	r28.u64 = PPC_LOAD_U32(r25.u32 + r28.u32);
	// lwzx r27,r24,r27
	r27.u64 = PPC_LOAD_U32(r24.u32 + r27.u32);
	// rlwinm r25,r31,8,24,31
	r25.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFF;
	// rlwinm r31,r31,8,0,23
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r24,r30,16,16,31
	r24.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF;
	// lwzx r29,r29,r22
	r29.u64 = PPC_LOAD_U32(r29.u32 + r22.u32);
	// rlwinm r22,r28,16,16,31
	r22.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 16) & 0xFFFF;
	// lwzx r26,r26,r23
	r26.u64 = PPC_LOAD_U32(r26.u32 + r23.u32);
	// rlwinm r23,r27,8,24,31
	r23.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 8) & 0xFF;
	// rlwinm r27,r27,8,0,23
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r28,r28,16,0,15
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 16) & 0xFFFF0000;
	// or r27,r23,r27
	r27.u64 = r23.u64 | r27.u64;
	// or r28,r22,r28
	r28.u64 = r22.u64 | r28.u64;
	// rlwinm r30,r30,16,0,15
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// or r31,r25,r31
	r31.u64 = r25.u64 | r31.u64;
	// rlwinm r23,r29,24,0,7
	r23.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFF000000;
	// rlwinm r22,r8,2,22,29
	r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// addi r18,r11,-1024
	r18.s64 = r11.s64 + -1024;
	// rlwinm r25,r26,24,0,7
	r25.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 24) & 0xFF000000;
	// rlwinm r21,r7,10,22,29
	r21.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// rlwinm r29,r29,24,8,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFFFFFF;
	// addi r19,r11,-1024
	r19.s64 = r11.s64 + -1024;
	// or r30,r24,r30
	r30.u64 = r24.u64 | r30.u64;
	// rlwinm r6,r6,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r26,r26,24,8,31
	r26.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 24) & 0xFFFFFF;
	// addi r20,r11,-1024
	r20.s64 = r11.s64 + -1024;
	// xor r28,r27,r28
	r28.u64 = r27.u64 ^ r28.u64;
	// lwzx r24,r21,r19
	r24.u64 = PPC_LOAD_U32(r21.u32 + r19.u32);
	// or r29,r23,r29
	r29.u64 = r23.u64 | r29.u64;
	// xor r31,r31,r30
	r31.u64 = r31.u64 ^ r30.u64;
	// lwzx r30,r22,r18
	r30.u64 = PPC_LOAD_U32(r22.u32 + r18.u32);
	// or r26,r25,r26
	r26.u64 = r25.u64 | r26.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwzx r6,r6,r20
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r20.u32);
	// xor r29,r28,r29
	r29.u64 = r28.u64 ^ r29.u64;
	// rlwinm r22,r7,18,22,29
	r22.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// xor r31,r31,r26
	r31.u64 = r31.u64 ^ r26.u64;
	// rlwinm r21,r3,26,22,29
	r21.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// rlwinm r7,r7,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// lwz r27,4(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r28,r11,-1024
	r28.s64 = r11.s64 + -1024;
	// lwz r25,0(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r20,r11,-1024
	r20.s64 = r11.s64 + -1024;
	// lwz r23,8(r10)
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r26,r11,-1024
	r26.s64 = r11.s64 + -1024;
	// lwz r19,12(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// xor r6,r31,r6
	ctx.r6.u64 = r31.u64 ^ ctx.r6.u64;
	// xor r31,r29,r24
	r31.u64 = r29.u64 ^ r24.u64;
	// lwzx r28,r7,r28
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// lwzx r21,r21,r20
	r21.u64 = PPC_LOAD_U32(r21.u32 + r20.u32);
	// addi r20,r11,-1024
	r20.s64 = r11.s64 + -1024;
	// xor r7,r31,r27
	ctx.r7.u64 = r31.u64 ^ r27.u64;
	// lwzx r3,r3,r26
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r26.u32);
	// addi r27,r11,-1024
	r27.s64 = r11.s64 + -1024;
	// rlwinm r26,r9,18,22,29
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 18) & 0x3FC;
	// rlwinm r29,r30,8,24,31
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFF;
	// rlwinm r30,r30,8,0,23
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// lwzx r22,r22,r20
	r22.u64 = PPC_LOAD_U32(r22.u32 + r20.u32);
	// xor r6,r6,r25
	ctx.r6.u64 = ctx.r6.u64 ^ r25.u64;
	// or r31,r29,r30
	r31.u64 = r29.u64 | r30.u64;
	// lwzx r27,r26,r27
	r27.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// rlwinm r30,r21,16,16,31
	r30.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 16) & 0xFFFF;
	// rlwinm r29,r21,16,0,15
	r29.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 16) & 0xFFFF0000;
	// addi r25,r11,-1024
	r25.s64 = r11.s64 + -1024;
	// addi r24,r11,-1024
	r24.s64 = r11.s64 + -1024;
	// rlwinm r26,r28,16,16,31
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 16) & 0xFFFF;
	// rlwinm r28,r28,16,0,15
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r21,r3,8,24,31
	r21.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// or r30,r30,r29
	r30.u64 = r30.u64 | r29.u64;
	// rlwinm r3,r3,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r29,r22,24,0,7
	r29.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 24) & 0xFF000000;
	// or r28,r26,r28
	r28.u64 = r26.u64 | r28.u64;
	// rlwinm r26,r27,24,0,7
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 24) & 0xFF000000;
	// rlwinm r22,r22,24,8,31
	r22.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,10,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x3FC;
	// rlwinm r8,r8,10,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x3FC;
	// or r3,r21,r3
	ctx.r3.u64 = r21.u64 | ctx.r3.u64;
	// rlwinm r27,r27,24,8,31
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 24) & 0xFFFFFF;
	// xor r31,r31,r30
	r31.u64 = r31.u64 ^ r30.u64;
	// or r30,r29,r22
	r30.u64 = r29.u64 | r22.u64;
	// lwzx r9,r9,r25
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r25.u32);
	// xor r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 ^ r28.u64;
	// lwzx r8,r8,r24
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r24.u32);
	// or r29,r26,r27
	r29.u64 = r26.u64 | r27.u64;
	// xor r31,r31,r30
	r31.u64 = r31.u64 ^ r30.u64;
	// xor r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 ^ r29.u64;
	// xor r9,r31,r9
	ctx.r9.u64 = r31.u64 ^ ctx.r9.u64;
	// xor r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r8.u64;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// xor r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 ^ r23.u64;
	// xor r8,r8,r19
	ctx.r8.u64 = ctx.r8.u64 ^ r19.u64;
	// bne 0x821e127c
	if (!cr0.eq) goto loc_821E127C;
loc_821E142C:
	// rlwinm r5,r8,18,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 18) & 0x3FC;
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r31,r9,26,22,29
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FC;
	// rlwinm r30,r6,10,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r29,r7,2,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// addi r28,r11,3
	r28.s64 = r11.s64 + 3;
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// rlwinm r27,r7,10,22,29
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// lwzx r31,r31,r11
	r31.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// rlwinm r26,r9,2,22,29
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r30,r30,r11
	r30.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// addi r25,r11,3
	r25.s64 = r11.s64 + 3;
	// rlwimi r5,r31,0,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(r31.u32, 0) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// lbzx r31,r29,r28
	r31.u64 = PPC_LOAD_U8(r29.u32 + r28.u32);
	// rlwinm r29,r6,18,22,29
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC;
	// rlwimi r5,r30,0,0,7
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0xFF000000) | (ctx.r5.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r28,r8,26,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FC;
	// rlwinm r5,r5,0,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF00;
	// rlwinm r30,r9,10,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x3FC;
	// xor r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 ^ r31.u64;
	// rlwinm r24,r8,2,22,29
	r24.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// xor r3,r5,r3
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r3.u64;
	// addi r31,r11,3
	r31.s64 = r11.s64 + 3;
	// rlwinm r23,r3,8,24,31
	r23.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// stb r3,3(r4)
	PPC_STORE_U8(ctx.r4.u32 + 3, ctx.r3.u8);
	// rlwinm r22,r3,16,24,31
	r22.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFF;
	// rlwinm r21,r3,24,24,31
	r21.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF;
	// stb r23,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r23.u8);
	// stb r22,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, r22.u8);
	// rlwinm r5,r7,18,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// stb r21,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, r21.u8);
	// rlwinm r23,r6,26,22,29
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x3FC;
	// lwzx r27,r27,r11
	r27.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// rlwinm r8,r8,10,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x3FC;
	// lbzx r26,r26,r25
	r26.u64 = PPC_LOAD_U8(r26.u32 + r25.u32);
	// rlwinm r9,r9,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 18) & 0x3FC;
	// lwz r25,20(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r7,r7,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// lwzx r29,r29,r11
	r29.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwzx r28,r28,r11
	r28.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// rlwimi r29,r28,0,16,23
	r29.u64 = (__builtin_rotateleft32(r28.u32, 0) & 0xFF00) | (r29.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r29,r27,0,0,7
	r29.u64 = (__builtin_rotateleft32(r27.u32, 0) & 0xFF000000) | (r29.u64 & 0xFFFFFFFF00FFFFFF);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r29,r29,0,0,23
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFF00;
	// xor r29,r29,r26
	r29.u64 = r29.u64 ^ r26.u64;
	// xor r29,r29,r25
	r29.u64 = r29.u64 ^ r25.u64;
	// rlwinm r28,r29,8,24,31
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFF;
	// stb r29,7(r4)
	PPC_STORE_U8(ctx.r4.u32 + 7, r29.u8);
	// rlwinm r27,r29,16,24,31
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 16) & 0xFF;
	// rlwinm r26,r29,24,24,31
	r26.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFF;
	// stb r28,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, r28.u8);
	// stb r27,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, r27.u8);
	// stb r26,6(r4)
	PPC_STORE_U8(ctx.r4.u32 + 6, r26.u8);
	// lwzx r30,r30,r11
	r30.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lbzx r31,r24,r31
	r31.u64 = PPC_LOAD_U8(r24.u32 + r31.u32);
	// lwz r29,24(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// lwzx r28,r23,r11
	r28.u64 = PPC_LOAD_U32(r23.u32 + r11.u32);
	// rlwimi r5,r28,0,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(r28.u32, 0) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r5,r30,0,0,7
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0xFF000000) | (ctx.r5.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r5,r5,0,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF00;
	// xor r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 ^ r31.u64;
	// xor r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 ^ r29.u64;
	// rlwinm r31,r5,8,24,31
	r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF;
	// stb r5,11(r4)
	PPC_STORE_U8(ctx.r4.u32 + 11, ctx.r5.u8);
	// rlwinm r30,r5,16,24,31
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF;
	// rlwinm r29,r5,24,24,31
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF;
	// stb r31,8(r4)
	PPC_STORE_U8(ctx.r4.u32 + 8, r31.u8);
	// stb r30,9(r4)
	PPC_STORE_U8(ctx.r4.u32 + 9, r30.u8);
	// stb r29,10(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10, r29.u8);
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lwz r5,28(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwzx r9,r7,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// rlwimi r10,r9,0,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r7,r11,3
	ctx.r7.s64 = r11.s64 + 3;
	// rlwimi r10,r8,0,0,7
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFF000000) | (ctx.r10.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwinm r11,r10,0,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// lbzx r6,r6,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// xor r10,r11,r6
	ctx.r10.u64 = r11.u64 ^ ctx.r6.u64;
	// xor r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// rlwinm r8,r9,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// stb r9,15(r4)
	PPC_STORE_U8(ctx.r4.u32 + 15, ctx.r9.u8);
	// rlwinm r7,r9,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// rlwinm r6,r9,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// stb r8,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, ctx.r8.u8);
	// stb r7,13(r4)
	PPC_STORE_U8(ctx.r4.u32 + 13, ctx.r7.u8);
	// stb r6,14(r4)
	PPC_STORE_U8(ctx.r4.u32 + 14, ctx.r6.u8);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_821E1594"))) PPC_WEAK_FUNC(sub_821E1594);
PPC_FUNC_IMPL(__imp__sub_821E1594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E1598"))) PPC_WEAK_FUNC(sub_821E1598);
PPC_FUNC_IMPL(__imp__sub_821E1598) {
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
	ctx.lr = 0x821E15A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e15f8
	if (cr6.eq) goto loc_821E15F8;
loc_821E15BC:
	// li r30,0
	r30.s64 = 0;
loc_821E15C0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r28
	ctr.u64 = r28.u64;
	// bctrl 
	ctx.lr = 0x821E15D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e1604
	if (cr6.eq) goto loc_821E1604;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// blt cr6,0x821e15c0
	if (cr6.lt) goto loc_821E15C0;
	// addic. r27,r27,-16
	xer.ca = r27.u32 > 15;
	r27.s64 = r27.s64 + -16;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x821e15bc
	if (!cr0.eq) goto loc_821E15BC;
loc_821E15F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821E1604:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E1610"))) PPC_WEAK_FUNC(sub_821E1610);
PPC_FUNC_IMPL(__imp__sub_821E1610) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r11,-30012
	ctx.r3.s64 = r11.s64 + -30012;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x821e0678
	ctx.lr = 0x821E163C;
	sub_821E0678(ctx, base);
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

__attribute__((alias("__imp__sub_821E1654"))) PPC_WEAK_FUNC(sub_821E1654);
PPC_FUNC_IMPL(__imp__sub_821E1654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E1658"))) PPC_WEAK_FUNC(sub_821E1658);
PPC_FUNC_IMPL(__imp__sub_821E1658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r6,r9,4080
	ctx.r6.s64 = ctx.r9.s64 + 4080;
	// rlwinm r4,r10,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x821e1598
	sub_821E1598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E1678"))) PPC_WEAK_FUNC(sub_821E1678);
PPC_FUNC_IMPL(__imp__sub_821E1678) {
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
	ctx.lr = 0x821E1680;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r30,256
	r11.s64 = r30.s64 + 256;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r7,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r7.u32);
	// bl 0x823d9890
	ctx.lr = 0x821E16AC;
	sub_823D9890(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,2
	r11.s64 = 2;
	// addi r10,r10,4096
	ctx.r10.s64 = ctx.r10.s64 + 4096;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r8,r30,-1
	ctx.r8.s64 = r30.s64 + -1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// stw r28,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r28.u32);
	// ble cr6,0x821e1710
	if (!cr6.gt) goto loc_821E1710;
	// li r10,32
	ctx.r10.s64 = 32;
loc_821E16DC:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// clrldi r7,r11,32
	ctx.r7.u64 = r11.u64 & 0xFFFFFFFF;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// ld r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & r12.u64;
	// rldimi r5,r7,6,38
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r5.u64 & 0xFFFFFFFFFC00003F);
	// std r5,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r5.u64);
	// blt cr6,0x821e16dc
	if (cr6.lt) goto loc_821E16DC;
loc_821E1710:
	// li r29,0
	r29.s64 = 0;
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// bl 0x823d9890
	ctx.lr = 0x821E1734;
	sub_823D9890(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// lis r10,1024
	ctx.r10.s64 = 67108864;
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E1750"))) PPC_WEAK_FUNC(sub_821E1750);
PPC_FUNC_IMPL(__imp__sub_821E1750) {
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
	ctx.lr = 0x821E1758;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bge cr6,0x821e176c
	if (!cr6.lt) goto loc_821E176C;
	// stw r5,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r5.u32);
loc_821E176C:
	// lwz r30,36(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e1780
	if (cr6.eq) goto loc_821E1780;
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bgt cr6,0x821e1be4
	if (cr6.gt) goto loc_821E1BE4;
loc_821E1780:
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e1be4
	if (cr6.eq) goto loc_821E1BE4;
	// lwz r24,4(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ldx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + r24.u32);
	// rlwinm r8,r10,0,6,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3FFFFC0;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x821e1be4
	if (cr6.eq) goto loc_821E1BE4;
	// addi r31,r5,-1
	r31.s64 = ctx.r5.s64 + -1;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// li r3,-1
	ctx.r3.s64 = -1;
	// add r11,r31,r4
	r11.u64 = r31.u64 + ctx.r4.u64;
	// not r5,r31
	ctx.r5.u64 = ~r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// and r25,r11,r5
	r25.u64 = r11.u64 & ctx.r5.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821e1be8
	if (cr6.eq) goto loc_821E1BE8;
loc_821E17D8:
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// ld r26,0(r11)
	r26.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rlwinm r10,r26,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x20;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// bne cr6,0x821e186c
	if (!cr6.eq) goto loc_821E186C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// and r11,r8,r5
	r11.u64 = ctx.r8.u64 & ctx.r5.u64;
	// and r8,r7,r5
	ctx.r8.u64 = ctx.r7.u64 & ctx.r5.u64;
	// subf r10,r11,r8
	ctx.r10.s64 = ctx.r8.s64 - r11.s64;
	// beq cr6,0x821e183c
	if (cr6.eq) goto loc_821E183C;
	// add r7,r11,r25
	ctx.r7.u64 = r11.u64 + r25.u64;
	// divwu r22,r11,r30
	r22.u32 = r11.u32 / r30.u32;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// twllei r30,0
	// divwu r7,r7,r30
	ctx.r7.u32 = ctx.r7.u32 / r30.u32;
	// twllei r30,0
	// cmplw cr6,r22,r7
	cr6.compare<uint32_t>(r22.u32, ctx.r7.u32, xer);
	// beq cr6,0x821e183c
	if (cr6.eq) goto loc_821E183C;
	// mullw r11,r30,r7
	r11.s64 = int64_t(r30.s32) * int64_t(ctx.r7.s32);
	// subf r10,r11,r8
	ctx.r10.s64 = ctx.r8.s64 - r11.s64;
loc_821E183C:
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// ble cr6,0x821e186c
	if (!cr6.gt) goto loc_821E186C;
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// blt cr6,0x821e186c
	if (cr6.lt) goto loc_821E186C;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// bge cr6,0x821e186c
	if (!cr6.lt) goto loc_821E186C;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r11
	r27.u64 = r11.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// beq cr6,0x821e1880
	if (cr6.eq) goto loc_821E1880;
loc_821E186C:
	// rldicl r11,r26,58,6
	r11.u64 = __builtin_rotateleft64(r26.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// clrlwi r6,r11,12
	ctx.r6.u64 = r11.u32 & 0xFFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821e17d8
	if (!cr6.eq) goto loc_821E17D8;
loc_821E1880:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x821e1be8
	if (cr6.eq) goto loc_821E1BE8;
	// rlwinm r11,r23,4,0,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r27,r25
	ctx.r4.u64 = r27.u64 + r25.u64;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x821e18c4
	if (cr6.eq) goto loc_821E18C4;
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lis r12,-1024
	r12.s64 = -67108864;
	// rlwinm r7,r8,0,6,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3FFFFC0;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ldx r6,r10,r24
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + r24.u32);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & r12.u64;
	// or r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stdx r3,r10,r24
	PPC_STORE_U64(ctx.r10.u32 + r24.u32, ctx.r3.u64);
	// b 0x821e18d4
	goto loc_821E18D4;
loc_821E18C4:
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicl r8,r10,58,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r7,r8,12
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFFF;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
loc_821E18D4:
	// lis r12,-1024
	r12.s64 = -67108864;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// subf. r6,r8,r27
	ctx.r6.s64 = r27.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// and r7,r10,r12
	ctx.r7.u64 = ctx.r10.u64 & r12.u64;
	// ori r8,r7,32
	ctx.r8.u64 = ctx.r7.u64 | 32;
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// beq 0x821e1a04
	if (cr0.eq) goto loc_821E1A04;
	// rldicl r7,r8,38,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 38) & 0x3FFFFFFFFF;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r5,r7,4,9,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0x7FFFF0;
	// ldx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r5.u32 + ctx.r10.u32);
	// rlwinm r7,r3,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// bne cr6,0x821e1934
	if (!cr6.eq) goto loc_821E1934;
	// rldicl r8,r8,38,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 38) & 0x3FFFFFFFFF;
	// rlwinm r8,r8,4,9,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x7FFFF0;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r7,r6,r8
	ctx.r7.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// b 0x821e19ec
	goto loc_821E19EC;
loc_821E1934:
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lis r12,-1024
	r12.s64 = -67108864;
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// clrldi r12,r12,19
	r12.u64 = r12.u64 & 0x1FFFFFFFFFFF;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r5,r7,58,6
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r3,r5,12
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFFF;
	// stw r3,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r3.u32);
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// clrldi r3,r5,38
	ctx.r3.u64 = ctx.r5.u64 & 0x3FFFFFF;
	// rldimi r3,r23,45,0
	ctx.r3.u64 = (__builtin_rotateleft64(r23.u64, 45) & 0xFFFFE00000000000) | (ctx.r3.u64 & 0x1FFFFFFFFFFF);
	// and r7,r7,r12
	ctx.r7.u64 = ctx.r7.u64 & r12.u64;
	// or r5,r3,r7
	ctx.r5.u64 = ctx.r3.u64 | ctx.r7.u64;
	// std r5,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r5.u64);
	// ld r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicl r7,r3,38,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u64, 38) & 0x3FFFFFFFFF;
	// clrldi r5,r7,45
	ctx.r5.u64 = ctx.r7.u64 & 0x7FFFF;
	// cmpldi cr6,r5,0
	cr6.compare<uint64_t>(ctx.r5.u64, 0, xer);
	// beq cr6,0x821e19a0
	if (cr6.eq) goto loc_821E19A0;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r7,r7,4,9,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0x7FFFF0;
	// ldx r3,r7,r5
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r7.u32 + ctx.r5.u32);
	// clrldi r3,r3,19
	ctx.r3.u64 = ctx.r3.u64 & 0x1FFFFFFFFFFF;
	// rldimi r3,r8,45,0
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r8.u64, 45) & 0xFFFFE00000000000) | (ctx.r3.u64 & 0x1FFFFFFFFFFF);
	// stdx r3,r7,r5
	PPC_STORE_U64(ctx.r7.u32 + ctx.r5.u32, ctx.r3.u64);
loc_821E19A0:
	// lis r12,-8
	r12.s64 = -524288;
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// clrldi r5,r8,32
	ctx.r5.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// subf r3,r6,r27
	ctx.r3.s64 = r27.s64 - ctx.r6.s64;
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// and r7,r7,r12
	ctx.r7.u64 = ctx.r7.u64 & r12.u64;
	// lis r12,-1024
	r12.s64 = -67108864;
	// rldimi r7,r5,26,19
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u64, 26) & 0x1FFFFC000000) | (ctx.r7.u64 & 0xFFFFE00003FFFFFF);
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// std r7,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r7.u64);
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// and r7,r7,r12
	ctx.r7.u64 = ctx.r7.u64 & r12.u64;
	// rldimi r7,r5,6,38
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r5.u64, 6) & 0x3FFFFC0) | (ctx.r7.u64 & 0xFFFFFFFFFC00003F);
	// std r7,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r7.u64);
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// stw r3,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r3.u32);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
loc_821E19EC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 + ctx.r6.u64;
	// subf r6,r6,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r6.s64;
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
loc_821E1A04:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
	// add. r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x821e1b30
	if (cr0.eq) goto loc_821E1B30;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicl r10,r10,19,45
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 19) & 0x7FFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x821e1a60
	if (cr6.eq) goto loc_821E1A60;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r10,r10,4,9,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0x7FFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// bne cr6,0x821e1a60
	if (!cr6.eq) goto loc_821E1A60;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r6,r5,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r5.s64;
	// add r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 + ctx.r8.u64;
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r4,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
	// b 0x821e1b24
	goto loc_821E1B24;
loc_821E1A60:
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lis r12,-8
	r12.s64 = -524288;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrldi r6,r23,32
	ctx.r6.u64 = r23.u64 & 0xFFFFFFFF;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// ld r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r7,r3,58,6
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r3,r7,12
	ctx.r3.u64 = ctx.r7.u32 & 0xFFFFF;
	// stw r3,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r3.u32);
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// and r3,r7,r12
	ctx.r3.u64 = ctx.r7.u64 & r12.u64;
	// rldimi r3,r6,26,19
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r6.u64, 26) & 0x1FFFFC000000) | (ctx.r3.u64 & 0xFFFFE00003FFFFFF);
	// std r3,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r3.u64);
	// clrldi r7,r3,19
	ctx.r7.u64 = ctx.r3.u64 & 0x1FFFFFFFFFFF;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r3,r6,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u64, 0) & 0xFFFFE00000000000;
	// or r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 | ctx.r3.u64;
	// std r7,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r7.u64);
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicl r7,r6,19,45
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u64, 19) & 0x7FFFF;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x821e1aec
	if (cr6.eq) goto loc_821E1AEC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r7,r7,4,9,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0x7FFFF0;
	// lis r12,-8
	r12.s64 = -524288;
	// clrldi r3,r8,32
	ctx.r3.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// ldx r31,r7,r6
	r31.u64 = PPC_LOAD_U64(ctx.r7.u32 + ctx.r6.u32);
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// and r31,r31,r12
	r31.u64 = r31.u64 & r12.u64;
	// rldimi r31,r3,26,19
	r31.u64 = (__builtin_rotateleft64(ctx.r3.u64, 26) & 0x1FFFFC000000) | (r31.u64 & 0xFFFFE00003FFFFFF);
	// stdx r31,r7,r6
	PPC_STORE_U64(ctx.r7.u32 + ctx.r6.u32, r31.u64);
loc_821E1AEC:
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lis r12,-1024
	r12.s64 = -67108864;
	// clrldi r6,r7,19
	ctx.r6.u64 = ctx.r7.u64 & 0x1FFFFFFFFFFF;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// rldimi r6,r8,45,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 45) & 0xFFFFE00000000000) | (ctx.r6.u64 & 0x1FFFFFFFFFFF);
	// std r6,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r6.u64);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// and r6,r7,r12
	ctx.r6.u64 = ctx.r7.u64 & r12.u64;
	// rldimi r6,r3,6,38
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r3.u64, 6) & 0x3FFFFC0) | (ctx.r6.u64 & 0xFFFFFFFFFC00003F);
	// std r6,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r6.u64);
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
loc_821E1B24:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// subf r8,r5,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r5.s64;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
loc_821E1B30:
	// lwz r10,20(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// li r8,48
	ctx.r8.s64 = 48;
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r12,-4096
	r12.s64 = -268435456;
	// add r6,r10,r25
	ctx.r6.u64 = ctx.r10.u64 + r25.u64;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// stw r6,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r6.u32);
	// rldicr r12,r12,4,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 4) & 0xFFFFFFFFFFFFFFFF;
	// ld r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwzx r5,r8,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rldicr r10,r3,0,59
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 0) & 0xFFFFFFFFFFFFFFF0;
	// and r4,r5,r12
	ctx.r4.u64 = ctx.r5.u64 & r12.u64;
	// lis r12,-1024
	r12.s64 = -67108864;
	// or r7,r4,r10
	ctx.r7.u64 = ctx.r4.u64 | ctx.r10.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// std r7,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r7.u64);
	// clrlwi r8,r7,28
	ctx.r8.u64 = ctx.r7.u32 & 0xF;
	// clrlwi r10,r7,28
	ctx.r10.u64 = ctx.r7.u32 & 0xF;
	// addi r6,r8,11
	ctx.r6.s64 = ctx.r8.s64 + 11;
	// addi r5,r10,11
	ctx.r5.s64 = ctx.r10.s64 + 11;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// stwx r10,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// and r3,r8,r12
	ctx.r3.u64 = ctx.r8.u64 & r12.u64;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r6,r7,22,10,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 22) & 0x3FFFFF;
	// xor r4,r6,r7
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// rlwinm r10,r4,22,10,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 22) & 0x3FFFFF;
	// xor r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r7.u64;
	// rlwinm r6,r8,0,20,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFC;
	// lwzx r5,r6,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// rldimi r3,r5,6,38
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r5.u64, 6) & 0x3FFFFC0) | (ctx.r3.u64 & 0xFFFFFFFFFC00003F);
	// std r3,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r3.u64);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r23,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, r23.u32);
	// lwz r3,40(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplw cr6,r25,r3
	cr6.compare<uint32_t>(r25.u32, ctx.r3.u32, xer);
	// ble cr6,0x821e1bdc
	if (!cr6.gt) goto loc_821E1BDC;
	// stw r25,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, r25.u32);
loc_821E1BDC:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x823d9230
	return;
loc_821E1BE4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821E1BE8:
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821E1BEC"))) PPC_WEAK_FUNC(sub_821E1BEC);
PPC_FUNC_IMPL(__imp__sub_821E1BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E1BF0"))) PPC_WEAK_FUNC(sub_821E1BF0);
PPC_FUNC_IMPL(__imp__sub_821E1BF0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821E1BF8;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x821e1c08
	if (!cr6.eq) goto loc_821E1C08;
loc_821E1C00:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d9240
	return;
loc_821E1C08:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// and r10,r11,r4
	ctx.r10.u64 = r11.u64 & ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e1c00
	if (!cr6.eq) goto loc_821E1C00;
	// rlwinm r11,r4,22,10,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 22) & 0x3FFFFF;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,-1
	r29.s64 = -1;
	// xor r10,r11,r4
	ctx.r10.u64 = r11.u64 ^ ctx.r4.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// rlwinm r9,r10,22,10,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x3FFFFF;
	// xor r6,r9,r4
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r4.u64;
	// rlwinm r6,r6,0,20,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFC;
	// lwzx r27,r6,r7
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e1c00
	if (cr6.eq) goto loc_821E1C00;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_821E1C4C:
	// rlwinm r11,r27,4,0,27
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x821e1c80
	if (cr6.eq) goto loc_821E1C80;
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// rldicl r10,r11,58,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r27,r10,12
	r27.u64 = ctx.r10.u32 & 0xFFFFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x821e1c4c
	if (!cr6.eq) goto loc_821E1C4C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d9240
	return;
loc_821E1C80:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821e1c00
	if (cr6.eq) goto loc_821E1C00;
	// rlwinm r26,r27,4,0,27
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// add r10,r9,r26
	ctx.r10.u64 = ctx.r9.u64 + r26.u64;
	// bne cr6,0x821e1cac
	if (!cr6.eq) goto loc_821E1CAC;
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r9,r11,58,6
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r8,r9,12
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFFF;
	// stwx r8,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r8.u32);
	// b 0x821e1cd0
	goto loc_821E1CD0;
loc_821E1CAC:
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// lis r12,-1024
	r12.s64 = -67108864;
	// rlwinm r7,r8,0,6,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3FFFFC0;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ldx r6,r11,r9
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + ctx.r9.u32);
	// and r5,r6,r12
	ctx.r5.u64 = ctx.r6.u64 & r12.u64;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stdx r4,r11,r9
	PPC_STORE_U64(r11.u32 + ctx.r9.u32, ctx.r4.u64);
loc_821E1CD0:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r28,0
	r28.s64 = 0;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// clrlwi r11,r6,28
	r11.u64 = ctx.r6.u32 & 0xF;
	// addi r5,r11,11
	ctx.r5.s64 = r11.s64 + 11;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r3
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// subf r9,r7,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r7.s64;
	// stwx r9,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r7,r9,38,45
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 38) & 0x7FFFF;
	// rldicl r8,r9,38,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 38) & 0x3FFFFFFFFF;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x821e1d34
	if (cr6.eq) goto loc_821E1D34;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r7,r8,4,9,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x7FFFF0;
	// ldx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r5,r6,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x20;
	// cmpldi cr6,r5,0
	cr6.compare<uint64_t>(ctx.r5.u64, 0, xer);
	// beq cr6,0x821e1d38
	if (cr6.eq) goto loc_821E1D38;
loc_821E1D34:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
loc_821E1D38:
	// rldicl r11,r9,19,45
	r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 19) & 0x7FFFF;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x821e1d64
	if (cr6.eq) goto loc_821E1D64;
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r5,r11,4,9,27
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0x7FFFF0;
	// ldx r4,r5,r6
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r5.u32 + ctx.r6.u32);
	// rlwinm r6,r4,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20;
	// cmpldi cr6,r6,0
	cr6.compare<uint64_t>(ctx.r6.u64, 0, xer);
	// li r6,1
	ctx.r6.s64 = 1;
	// beq cr6,0x821e1d68
	if (cr6.eq) goto loc_821E1D68;
loc_821E1D64:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_821E1D68:
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e20d4
	if (cr6.eq) goto loc_821E20D4;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821e2014
	if (cr6.eq) goto loc_821E2014;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r5,r8,13
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFF;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r8,4,9,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x7FFFF0;
	// rlwinm r31,r11,4,9,27
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0x7FFFF0;
	// clrlwi r30,r11,13
	r30.u64 = r11.u32 & 0x7FFFF;
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r11,r31,r7
	r11.u64 = r31.u64 + ctx.r7.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// beq cr6,0x821e1de0
	if (cr6.eq) goto loc_821E1DE0;
loc_821E1DB0:
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x821e1dd8
	if (cr6.eq) goto loc_821E1DD8;
	// rlwinm r29,r9,4,0,27
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// ldx r9,r29,r7
	ctx.r9.u64 = PPC_LOAD_U64(r29.u32 + ctx.r7.u32);
	// rldicl r9,r9,58,6
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r9,r9,12
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFFF;
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// bne cr6,0x821e1db0
	if (!cr6.eq) goto loc_821E1DB0;
	// b 0x821e1de0
	goto loc_821E1DE0;
loc_821E1DD8:
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// bne cr6,0x821e1ee4
	if (!cr6.eq) goto loc_821E1EE4;
loc_821E1DE0:
	// lis r12,-8
	r12.s64 = -524288;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// subf r31,r10,r31
	r31.s64 = r31.s64 - ctx.r10.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// and r9,r7,r12
	ctx.r9.u64 = ctx.r7.u64 & r12.u64;
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// lis r12,-1024
	r12.s64 = -67108864;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// clrldi r12,r12,19
	r12.u64 = r12.u64 & 0x1FFFFFFFFFFF;
	// and r10,r7,r12
	ctx.r10.u64 = ctx.r7.u64 & r12.u64;
	// or r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// rldicl r11,r7,38,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 38) & 0x3FFFFFFFFF;
	// clrldi r10,r11,45
	ctx.r10.u64 = r11.u64 & 0x7FFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x821e1e5c
	if (cr6.eq) goto loc_821E1E5C;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r11,r11,4,9,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0x7FFFF0;
	// ldx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + ctx.r10.u32);
	// clrldi r7,r9,19
	ctx.r7.u64 = ctx.r9.u64 & 0x1FFFFFFFFFFF;
	// rldimi r7,r30,45,0
	ctx.r7.u64 = (__builtin_rotateleft64(r30.u64, 45) & 0xFFFFE00000000000) | (ctx.r7.u64 & 0x1FFFFFFFFFFF);
	// stdx r7,r11,r10
	PPC_STORE_U64(r11.u32 + ctx.r10.u32, ctx.r7.u64);
loc_821E1E5C:
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x821e1e78
	if (!cr6.eq) goto loc_821E1E78;
	// ld r11,0(r8)
	r11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// rldicl r10,r11,58,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r9,r10,12
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFFF;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// b 0x821e1ea0
	goto loc_821E1EA0;
loc_821E1E78:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r12,-1024
	r12.s64 = -67108864;
	// ld r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// rlwinm r8,r9,0,6,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x3FFFFC0;
	// ldx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + ctx.r10.u32);
	// and r4,r7,r12
	ctx.r4.u64 = ctx.r7.u64 & r12.u64;
	// or r9,r4,r8
	ctx.r9.u64 = ctx.r4.u64 | ctx.r8.u64;
	// stdx r9,r11,r10
	PPC_STORE_U64(r11.u32 + ctx.r10.u32, ctx.r9.u64);
loc_821E1EA0:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & r12.u64;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rldimi r8,r7,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// b 0x821e1fcc
	goto loc_821E1FCC;
loc_821E1EE4:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 + ctx.r6.u64;
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrldi r10,r7,19
	ctx.r10.u64 = ctx.r7.u64 & 0x1FFFFFFFFFFF;
	// stw r6,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r7,r9,0,18
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 0) & 0xFFFFE00000000000;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// std r6,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r6.u64);
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicl r10,r10,19,45
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 19) & 0x7FFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x821e1f4c
	if (cr6.eq) goto loc_821E1F4C;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r10,4,9,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0x7FFFF0;
	// lis r12,-8
	r12.s64 = -524288;
	// clrldi r8,r5,32
	ctx.r8.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// ldx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// and r6,r7,r12
	ctx.r6.u64 = ctx.r7.u64 & r12.u64;
	// rldimi r6,r8,26,19
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r8.u64, 26) & 0x1FFFFC000000) | (ctx.r6.u64 & 0xFFFFE00003FFFFFF);
	// stdx r6,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u64);
loc_821E1F4C:
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x821e1f68
	if (!cr6.eq) goto loc_821E1F68;
	// rldicl r10,r11,58,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r9,r10,12
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFFF;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// b 0x821e1f8c
	goto loc_821E1F8C;
loc_821E1F68:
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r12,-1024
	r12.s64 = -67108864;
	// rlwinm r8,r11,0,6,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3FFFFC0;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ldx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// and r6,r7,r12
	ctx.r6.u64 = ctx.r7.u64 & r12.u64;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stdx r5,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u64);
loc_821E1F8C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & r12.u64;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rldimi r8,r7,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r30.u32);
loc_821E1FCC:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & r12.u64;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rldimi r8,r7,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// stw r27,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d9240
	return;
loc_821E2014:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e20d4
	if (cr6.eq) goto loc_821E20D4;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r11,r8,4,9,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x7FFFF0;
	// rldicr r8,r9,0,18
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 0) & 0xFFFFE00000000000;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// clrldi r6,r7,19
	ctx.r6.u64 = ctx.r7.u64 & 0x1FFFFFFFFFFF;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// std r5,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r5.u64);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r10,r11,19,45
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 19) & 0x7FFFF;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x821e208c
	if (cr6.eq) goto loc_821E208C;
	// lis r12,-1024
	r12.s64 = -67108864;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r10,4,9,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0x7FFFF0;
	// clrldi r12,r12,19
	r12.u64 = r12.u64 & 0x1FFFFFFFFFFF;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// lis r12,-8
	r12.s64 = -524288;
	// ldx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & r12.u64;
	// or r6,r11,r7
	ctx.r6.u64 = r11.u64 | ctx.r7.u64;
	// stdx r6,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u64);
loc_821E208C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & r12.u64;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rldimi r8,r7,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// stw r27,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d9240
	return;
loc_821E20D4:
	// clrlwi r8,r6,24
	ctx.r8.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821e21ac
	if (cr6.eq) goto loc_821E21AC;
	// lis r12,-1024
	r12.s64 = -67108864;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r11,r11,4,9,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0x7FFFF0;
	// clrldi r12,r12,19
	r12.u64 = r12.u64 & 0x1FFFFFFFFFFF;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// and r7,r9,r12
	ctx.r7.u64 = ctx.r9.u64 & r12.u64;
	// lis r12,-8
	r12.s64 = -524288;
	// ori r12,r12,0
	r12.u64 = r12.u64 | 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r12,r12,26,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 26) & 0xFFFFFFFFFFFFFFFF;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// and r4,r6,r12
	ctx.r4.u64 = ctx.r6.u64 & r12.u64;
	// or r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 | ctx.r7.u64;
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// subf r6,r7,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r7.s64;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r4,r11,38,45
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 38) & 0x7FFFF;
	// rldicl r10,r11,38,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 38) & 0x3FFFFFFFFF;
	// cmpldi cr6,r4,0
	cr6.compare<uint64_t>(ctx.r4.u64, 0, xer);
	// beq cr6,0x821e2164
	if (cr6.eq) goto loc_821E2164;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r10,4,9,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0x7FFFF0;
	// rldicr r11,r11,0,18
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFE00000000000;
	// ldx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// clrldi r7,r8,19
	ctx.r7.u64 = ctx.r8.u64 & 0x1FFFFFFFFFFF;
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | r11.u64;
	// stdx r6,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u64);
loc_821E2164:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r12,-1024
	r12.s64 = -67108864;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// ori r12,r12,63
	r12.u64 = r12.u64 | 63;
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & r12.u64;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rldimi r8,r7,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// stw r27,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d9240
	return;
loc_821E21AC:
	// lis r12,-1024
	r12.s64 = -67108864;
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// ori r12,r12,31
	r12.u64 = r12.u64 | 31;
	// and r8,r11,r12
	ctx.r8.u64 = r11.u64 & r12.u64;
	// rldimi r8,r9,6,38
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u64, 6) & 0x3FFFFC0) | (ctx.r8.u64 & 0xFFFFFFFFFC00003F);
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E21D4"))) PPC_WEAK_FUNC(sub_821E21D4);
PPC_FUNC_IMPL(__imp__sub_821E21D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E21D8"))) PPC_WEAK_FUNC(sub_821E21D8);
PPC_FUNC_IMPL(__imp__sub_821E21D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,22,10,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 22) & 0x3FFFFF;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// xor r10,r11,r4
	ctx.r10.u64 = r11.u64 ^ ctx.r4.u64;
	// rlwinm r8,r10,22,10,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x3FFFFF;
	// xor r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r4.u64;
	// rlwinm r6,r7,0,20,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2238
	if (cr6.eq) goto loc_821E2238;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_821E2200:
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x821e2230
	if (cr6.eq) goto loc_821E2230;
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r10,r11,58,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r11,r10,12
	r11.u64 = ctx.r10.u32 & 0xFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e2200
	if (!cr6.eq) goto loc_821E2200;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821E2230:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e2240
	if (!cr6.eq) goto loc_821E2240;
loc_821E2238:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821E2240:
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2250"))) PPC_WEAK_FUNC(sub_821E2250);
PPC_FUNC_IMPL(__imp__sub_821E2250) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2290
	if (cr6.eq) goto loc_821E2290;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_821E2264:
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r8
	ctx.r10.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x821e227c
	if (!cr6.gt) goto loc_821E227C;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_821E227C:
	// ld r11,0(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicl r10,r11,58,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 58) & 0x3FFFFFFFFFFFFFF;
	// clrlwi r11,r10,12
	r11.u64 = ctx.r10.u32 & 0xFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e2264
	if (!cr6.eq) goto loc_821E2264;
loc_821E2290:
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e22a4
	if (cr6.eq) goto loc_821E22A4;
	// cmplw cr6,r9,r3
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, xer);
	// bgtlr cr6
	if (cr6.gt) return;
loc_821E22A4:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E22AC"))) PPC_WEAK_FUNC(sub_821E22AC);
PPC_FUNC_IMPL(__imp__sub_821E22AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E22B0"))) PPC_WEAK_FUNC(sub_821E22B0);
PPC_FUNC_IMPL(__imp__sub_821E22B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r10,31476
	ctx.r9.s64 = ctx.r10.s64 + 31476;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r10,-12720(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-12720(r11)
	PPC_STORE_U32(r11.u32 + -12720, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E22D8"))) PPC_WEAK_FUNC(sub_821E22D8);
PPC_FUNC_IMPL(__imp__sub_821E22D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// rlwinm r8,r10,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821e2314
	if (!cr6.eq) goto loc_821E2314;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x821e2314
	if (!cr6.lt) goto loc_821E2314;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x821e2314
	if (cr6.eq) goto loc_821E2314;
	// stfs f1,8(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// stw r6,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r6.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
loc_821E2314:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lis r8,8192
	ctx.r8.s64 = 536870912;
	// rlwinm r7,r10,0,2,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rlwinm r10,r10,2,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mulli r10,r10,1540
	ctx.r10.s64 = ctx.r10.s64 * 1540;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// addi r4,r11,44
	ctx.r4.s64 = r11.s64 + 44;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821E2350"))) PPC_WEAK_FUNC(sub_821E2350);
PPC_FUNC_IMPL(__imp__sub_821E2350) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2354"))) PPC_WEAK_FUNC(sub_821E2354);
PPC_FUNC_IMPL(__imp__sub_821E2354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2358"))) PPC_WEAK_FUNC(sub_821E2358);
PPC_FUNC_IMPL(__imp__sub_821E2358) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// bl 0x821e2808
	ctx.lr = 0x821E2378;
	sub_821E2808(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2394
	if (cr6.eq) goto loc_821E2394;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_821E2394:
	// li r11,0
	r11.s64 = 0;
	// stw r11,6208(r31)
	PPC_STORE_U32(r31.u32 + 6208, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_821E23B4"))) PPC_WEAK_FUNC(sub_821E23B4);
PPC_FUNC_IMPL(__imp__sub_821E23B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E23B8"))) PPC_WEAK_FUNC(sub_821E23B8);
PPC_FUNC_IMPL(__imp__sub_821E23B8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x821e23fc
	if (!cr6.eq) goto loc_821E23FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e28e8
	ctx.lr = 0x821E23E8;
	sub_821E28E8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,31520
	ctx.r3.s64 = r11.s64 + 31520;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x821E23FC;
	sub_82130000(ctx, base);
loc_821E23FC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x821e2420
	if (!cr6.eq) goto loc_821E2420;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// lfs f0,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_821E2420:
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

__attribute__((alias("__imp__sub_821E2438"))) PPC_WEAK_FUNC(sub_821E2438);
PPC_FUNC_IMPL(__imp__sub_821E2438) {
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
	ctx.lr = 0x821E2440;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,6208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6208);
	// lwz r29,4(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e2478
	if (cr6.eq) goto loc_821E2478;
	// bl 0x821bc598
	ctx.lr = 0x821E245C;
	sub_821BC598(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,6208(r31)
	PPC_STORE_U32(r31.u32 + 6208, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e2808
	ctx.lr = 0x821E2470;
	sub_821E2808(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
loc_821E2478:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E2480"))) PPC_WEAK_FUNC(sub_821E2480);
PPC_FUNC_IMPL(__imp__sub_821E2480) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e24a8
	if (!cr6.eq) goto loc_821E24A8;
	// lwz r11,6208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e24a8
	if (!cr6.eq) goto loc_821E24A8;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x821e24ac
	if (cr6.eq) goto loc_821E24AC;
loc_821E24A8:
	// li r11,1
	r11.s64 = 1;
loc_821E24AC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E24B4"))) PPC_WEAK_FUNC(sub_821E24B4);
PPC_FUNC_IMPL(__imp__sub_821E24B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E24B8"))) PPC_WEAK_FUNC(sub_821E24B8);
PPC_FUNC_IMPL(__imp__sub_821E24B8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821E24C0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
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
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e2508
	if (cr6.eq) goto loc_821E2508;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,2,30,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mulli r11,r10,1540
	r11.s64 = ctx.r10.s64 * 1540;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,44
	ctx.r4.s64 = r11.s64 + 44;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E2504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
loc_821E2508:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f31.f64 = double(temp.f32);
	// beq cr6,0x821e2524
	if (cr6.eq) goto loc_821E2524;
	// li r29,1
	r29.s64 = 1;
	// b 0x821e2598
	goto loc_821E2598;
loc_821E2524:
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e2594
	if (cr6.eq) goto loc_821E2594;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E2564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821e2578
	if (!cr6.eq) goto loc_821E2578;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// b 0x821e2598
	goto loc_821E2598;
loc_821E2578:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r29,1
	r29.s64 = 1;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x821e2598
	if (!cr6.eq) goto loc_821E2598;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// bl 0x821e2808
	ctx.lr = 0x821E2590;
	sub_821E2808(ctx, base);
	// b 0x821e2598
	goto loc_821E2598;
loc_821E2594:
	// stfs f31,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_821E2598:
	// stfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E25B0"))) PPC_WEAK_FUNC(sub_821E25B0);
PPC_FUNC_IMPL(__imp__sub_821E25B0) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,6204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6204);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,6204(r31)
	PPC_STORE_U32(r31.u32 + 6204, r11.u32);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x821e25e4
	if (cr6.lt) goto loc_821E25E4;
	// stw r9,6204(r31)
	PPC_STORE_U32(r31.u32 + 6204, ctx.r9.u32);
loc_821E25E4:
	// mulli r11,r10,1540
	r11.s64 = ctx.r10.s64 * 1540;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,44
	ctx.r4.s64 = r11.s64 + 44;
	// sth r9,46(r11)
	PPC_STORE_U16(r11.u32 + 46, ctx.r9.u16);
	// sth r9,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r9.u16);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwimi r11,r10,30,0,1
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 30) & 0xC0000000) | (r11.u64 & 0xFFFFFFFF3FFFFFFF);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// bl 0x821e2820
	ctx.lr = 0x821E2608;
	sub_821E2820(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r3,6208(r31)
	PPC_STORE_U32(r31.u32 + 6208, ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
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

__attribute__((alias("__imp__sub_821E262C"))) PPC_WEAK_FUNC(sub_821E262C);
PPC_FUNC_IMPL(__imp__sub_821E262C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2630"))) PPC_WEAK_FUNC(sub_821E2630);
PPC_FUNC_IMPL(__imp__sub_821E2630) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x821e2644
	if (!cr6.eq) goto loc_821E2644;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_821E2644:
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x821e2654
	if (!cr6.eq) goto loc_821E2654;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
loc_821E2654:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2668"))) PPC_WEAK_FUNC(sub_821E2668);
PPC_FUNC_IMPL(__imp__sub_821E2668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,31476
	ctx.r8.s64 = ctx.r9.s64 + 31476;
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,46(r3)
	PPC_STORE_U16(ctx.r3.u32 + 46, r11.u16);
	// sth r11,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, r11.u16);
	// sth r11,1586(r3)
	PPC_STORE_U16(ctx.r3.u32 + 1586, r11.u16);
	// sth r11,1584(r3)
	PPC_STORE_U16(ctx.r3.u32 + 1584, r11.u16);
	// sth r11,3126(r3)
	PPC_STORE_U16(ctx.r3.u32 + 3126, r11.u16);
	// sth r11,3124(r3)
	PPC_STORE_U16(ctx.r3.u32 + 3124, r11.u16);
	// sth r11,4666(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4666, r11.u16);
	// sth r11,4664(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4664, r11.u16);
	// stw r11,6204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 6204, r11.u32);
	// stw r11,6208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 6208, r11.u32);
	// stb r11,6212(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6212, r11.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-12720(r11)
	PPC_STORE_U32(r11.u32 + -12720, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E26E0"))) PPC_WEAK_FUNC(sub_821E26E0);
PPC_FUNC_IMPL(__imp__sub_821E26E0) {
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
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r10,31476
	ctx.r9.s64 = ctx.r10.s64 + 31476;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r10,-12720(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x821e2718
	if (!cr6.eq) goto loc_821E2718;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-12720(r11)
	PPC_STORE_U32(r11.u32 + -12720, ctx.r10.u32);
loc_821E2718:
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2730
	if (cr6.eq) goto loc_821E2730;
	// bl 0x82130588
	ctx.lr = 0x821E272C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821E2730:
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

__attribute__((alias("__imp__sub_821E2744"))) PPC_WEAK_FUNC(sub_821E2744);
PPC_FUNC_IMPL(__imp__sub_821E2744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2748"))) PPC_WEAK_FUNC(sub_821E2748);
PPC_FUNC_IMPL(__imp__sub_821E2748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2760"))) PPC_WEAK_FUNC(sub_821E2760);
PPC_FUNC_IMPL(__imp__sub_821E2760) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821e2794
	if (cr6.eq) goto loc_821E2794;
	// bl 0x821bd220
	ctx.lr = 0x821E2784;
	sub_821BD220(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_821E2794:
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

__attribute__((alias("__imp__sub_821E27A8"))) PPC_WEAK_FUNC(sub_821E27A8);
PPC_FUNC_IMPL(__imp__sub_821E27A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-12720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821E27D0"))) PPC_WEAK_FUNC(sub_821E27D0);
PPC_FUNC_IMPL(__imp__sub_821E27D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E27D4"))) PPC_WEAK_FUNC(sub_821E27D4);
PPC_FUNC_IMPL(__imp__sub_821E27D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E27D8"))) PPC_WEAK_FUNC(sub_821E27D8);
PPC_FUNC_IMPL(__imp__sub_821E27D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-12720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821E2804"))) PPC_WEAK_FUNC(sub_821E2804);
PPC_FUNC_IMPL(__imp__sub_821E2804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2808"))) PPC_WEAK_FUNC(sub_821E2808);
PPC_FUNC_IMPL(__imp__sub_821E2808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,4,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFCFFFFFFF;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E281C"))) PPC_WEAK_FUNC(sub_821E281C);
PPC_FUNC_IMPL(__imp__sub_821E281C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2820"))) PPC_WEAK_FUNC(sub_821E2820);
PPC_FUNC_IMPL(__imp__sub_821E2820) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e28cc
	if (!cr6.eq) goto loc_821E28CC;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x821e28cc
	if (cr6.eq) goto loc_821E28CC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e5530
	ctx.lr = 0x821E285C;
	sub_821E5530(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2898
	if (cr6.eq) goto loc_821E2898;
	// lis r11,-32226
	r11.s64 = -2111963136;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,10152
	ctx.r5.s64 = r11.s64 + 10152;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e5e58
	ctx.lr = 0x821E2880;
	sub_821E5E58(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e2898
	if (cr6.eq) goto loc_821E2898;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821bc7a0
	ctx.lr = 0x821E2890;
	sub_821BC7A0(ctx, base);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x821e28d0
	goto loc_821E28D0;
loc_821E2898:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r31,r11
	r31.u64 = r11.u64;
	// bl 0x821bc6b8
	ctx.lr = 0x821E28A8;
	sub_821BC6B8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r10,31608
	ctx.r3.s64 = ctx.r10.s64 + 31608;
	// rlwinm r4,r31,22,15,31
	ctx.r4.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 22) & 0x1FFFF;
	// bl 0x82130000
	ctx.lr = 0x821E28BC;
	sub_82130000(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,-12720(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12720);
	// stb r8,6212(r11)
	PPC_STORE_U8(r11.u32 + 6212, ctx.r8.u8);
loc_821E28CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E28D0:
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

__attribute__((alias("__imp__sub_821E28E8"))) PPC_WEAK_FUNC(sub_821E28E8);
PPC_FUNC_IMPL(__imp__sub_821E28E8) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x821e2918
	if (!cr6.eq) goto loc_821E2918;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,31716
	ctx.r3.s64 = r11.s64 + 31716;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E2918:
	// bl 0x821bc6b8
	ctx.lr = 0x821E291C;
	sub_821BC6B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821e292c
	if (!cr6.eq) goto loc_821E292C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,31692
	ctx.r3.s64 = r11.s64 + 31692;
loc_821E292C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E293C"))) PPC_WEAK_FUNC(sub_821E293C);
PPC_FUNC_IMPL(__imp__sub_821E293C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2940"))) PPC_WEAK_FUNC(sub_821E2940);
PPC_FUNC_IMPL(__imp__sub_821E2940) {
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
	ctx.lr = 0x821E2948;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,4072
	ctx.r4.s64 = r11.s64 + 4072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x823dd800
	ctx.lr = 0x821E2974;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bne cr6,0x821e2998
	if (!cr6.eq) goto loc_821E2998;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// bl 0x82137a08
	ctx.lr = 0x821E2994;
	sub_82137A08(ctx, base);
	// b 0x821e29ac
	goto loc_821E29AC;
loc_821E2998:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821e5c78
	ctx.lr = 0x821E29AC;
	sub_821E5C78(ctx, base);
loc_821E29AC:
	// li r30,0
	r30.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821bce68
	ctx.lr = 0x821E29C4;
	sub_821BCE68(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// rlwinm r10,r11,0,4,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFCFFFFFFF;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x821e29ec
	if (!cr6.eq) goto loc_821E29EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9244
	return;
loc_821E29EC:
	// bl 0x821bc7a0
	ctx.lr = 0x821E29F0;
	sub_821BC7A0(ctx, base);
	// rlwinm r8,r3,6,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xF;
	// rlwinm r7,r3,21,28,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 21) & 0xF;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r11,256
	r11.s64 = 256;
	// rlwinm r5,r3,17,21,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 17) & 0x7FF;
	// slw r6,r11,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r8.u8 & 0x3F));
	// slw r4,r11,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r7.u8 & 0x3F));
	// clrlwi r3,r3,21
	ctx.r3.u64 = ctx.r3.u32 & 0x7FF;
	// mullw r10,r6,r5
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// mullw r11,r4,r3
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r9,0,27,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFF800001F;
	// li r3,1
	ctx.r3.s64 = 1;
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r8,r9,0,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// or r7,r8,r27
	ctx.r7.u64 = ctx.r8.u64 | r27.u64;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E2A3C"))) PPC_WEAK_FUNC(sub_821E2A3C);
PPC_FUNC_IMPL(__imp__sub_821E2A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2A40"))) PPC_WEAK_FUNC(sub_821E2A40);
PPC_FUNC_IMPL(__imp__sub_821E2A40) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821e2a74
	if (cr6.eq) goto loc_821E2A74;
	// bl 0x821bd220
	ctx.lr = 0x821E2A64;
	sub_821BD220(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_821E2A74:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e2a98
	if (cr6.eq) goto loc_821E2A98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E2A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E2A98:
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

__attribute__((alias("__imp__sub_821E2AAC"))) PPC_WEAK_FUNC(sub_821E2AAC);
PPC_FUNC_IMPL(__imp__sub_821E2AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2AB0"))) PPC_WEAK_FUNC(sub_821E2AB0);
PPC_FUNC_IMPL(__imp__sub_821E2AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2ABC"))) PPC_WEAK_FUNC(sub_821E2ABC);
PPC_FUNC_IMPL(__imp__sub_821E2ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2AC0"))) PPC_WEAK_FUNC(sub_821E2AC0);
PPC_FUNC_IMPL(__imp__sub_821E2AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2ACC"))) PPC_WEAK_FUNC(sub_821E2ACC);
PPC_FUNC_IMPL(__imp__sub_821E2ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2AD0"))) PPC_WEAK_FUNC(sub_821E2AD0);
PPC_FUNC_IMPL(__imp__sub_821E2AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2ADC"))) PPC_WEAK_FUNC(sub_821E2ADC);
PPC_FUNC_IMPL(__imp__sub_821E2ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2AE0"))) PPC_WEAK_FUNC(sub_821E2AE0);
PPC_FUNC_IMPL(__imp__sub_821E2AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2AEC"))) PPC_WEAK_FUNC(sub_821E2AEC);
PPC_FUNC_IMPL(__imp__sub_821E2AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2AF0"))) PPC_WEAK_FUNC(sub_821E2AF0);
PPC_FUNC_IMPL(__imp__sub_821E2AF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r3,13(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2AFC"))) PPC_WEAK_FUNC(sub_821E2AFC);
PPC_FUNC_IMPL(__imp__sub_821E2AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2B00"))) PPC_WEAK_FUNC(sub_821E2B00);
PPC_FUNC_IMPL(__imp__sub_821E2B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r3,14(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2B0C"))) PPC_WEAK_FUNC(sub_821E2B0C);
PPC_FUNC_IMPL(__imp__sub_821E2B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2B10"))) PPC_WEAK_FUNC(sub_821E2B10);
PPC_FUNC_IMPL(__imp__sub_821E2B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2B1C"))) PPC_WEAK_FUNC(sub_821E2B1C);
PPC_FUNC_IMPL(__imp__sub_821E2B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2B20"))) PPC_WEAK_FUNC(sub_821E2B20);
PPC_FUNC_IMPL(__imp__sub_821E2B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r3,18(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2B2C"))) PPC_WEAK_FUNC(sub_821E2B2C);
PPC_FUNC_IMPL(__imp__sub_821E2B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2B30"))) PPC_WEAK_FUNC(sub_821E2B30);
PPC_FUNC_IMPL(__imp__sub_821E2B30) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,13584
	ctx.r10.s64 = r11.s64 + 13584;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E2B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,31
	ctx.r8.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821e2b90
	if (!cr6.eq) goto loc_821E2B90;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2b88
	if (cr6.eq) goto loc_821E2B88;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x821E2B7C;
	sub_82130588(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x821E2B88;
	sub_82130588(ctx, base);
loc_821E2B88:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821E2B90;
	sub_82130588(ctx, base);
loc_821E2B90:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,13540
	ctx.r10.s64 = r11.s64 + 13540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821E2BB0"))) PPC_WEAK_FUNC(sub_821E2BB0);
PPC_FUNC_IMPL(__imp__sub_821E2BB0) {
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
	ctx.lr = 0x821E2BB8;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x821E2BDC;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r5,36(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x821e2bfc
	if (cr6.eq) goto loc_821E2BFC;
	// lwz r4,32(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// b 0x821e2c00
	goto loc_821E2C00;
loc_821E2BFC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821E2C00:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db670
	ctx.lr = 0x821E2C08;
	sub_823DB670(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e2c90
	if (cr6.eq) goto loc_821E2C90;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_821E2C24:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_821E2C2C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x821e2c50
	if (cr6.eq) goto loc_821E2C50;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821e2c2c
	if (cr6.eq) goto loc_821E2C2C;
loc_821E2C50:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821e2c78
	if (cr6.eq) goto loc_821E2C78;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e2c24
	if (!cr6.eq) goto loc_821E2C24;
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9244
	return;
loc_821E2C78:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E2C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r30,r3,r27
	PPC_STORE_U32(ctx.r3.u32 + r27.u32, r30.u32);
loc_821E2C90:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E2C98"))) PPC_WEAK_FUNC(sub_821E2C98);
PPC_FUNC_IMPL(__imp__sub_821E2C98) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,13636
	ctx.r10.s64 = r11.s64 + 13636;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E2CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,31
	ctx.r8.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821e2cec
	if (!cr6.eq) goto loc_821E2CEC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e2ce4
	if (cr6.eq) goto loc_821E2CE4;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821E2CE4;
	sub_82130588(ctx, base);
loc_821E2CE4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821E2CEC;
	sub_82130588(ctx, base);
loc_821E2CEC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,13540
	ctx.r10.s64 = r11.s64 + 13540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821E2D0C"))) PPC_WEAK_FUNC(sub_821E2D0C);
PPC_FUNC_IMPL(__imp__sub_821E2D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2D10"))) PPC_WEAK_FUNC(sub_821E2D10);
PPC_FUNC_IMPL(__imp__sub_821E2D10) {
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
	ctx.lr = 0x821E2D18;
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
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E2D38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// beq cr6,0x821e2d84
	if (cr6.eq) goto loc_821E2D84;
	// cmpwi cr6,r3,16
	cr6.compare<int32_t>(ctx.r3.s32, 16, xer);
	// beq cr6,0x821e2d5c
	if (cr6.eq) goto loc_821E2D5C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,22912
	ctx.r3.s64 = r11.s64 + 22912;
	// bl 0x821bd618
	ctx.lr = 0x821E2D54;
	sub_821BD618(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E2D5C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E2D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r4,r3,r29
	ctx.r4.u64 = ctx.r3.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8238
	ctx.lr = 0x821E2D7C;
	sub_821C8238(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E2D84:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E2D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r4,r3,r29
	ctx.r4.u64 = ctx.r3.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8238
	ctx.lr = 0x821E2DA4;
	sub_821C8238(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E2DAC"))) PPC_WEAK_FUNC(sub_821E2DAC);
PPC_FUNC_IMPL(__imp__sub_821E2DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2DB0"))) PPC_WEAK_FUNC(sub_821E2DB0);
PPC_FUNC_IMPL(__imp__sub_821E2DB0) {
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x821e2dec
	if (cr6.eq) goto loc_821E2DEC;
	// subf r5,r31,r30
	ctx.r5.s64 = r30.s64 - r31.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x821E2DE4;
	sub_823DA950(ctx, base);
	// subf r11,r31,r3
	r11.s64 = ctx.r3.s64 - r31.s64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
loc_821E2DEC:
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

__attribute__((alias("__imp__sub_821E2E04"))) PPC_WEAK_FUNC(sub_821E2E04);
PPC_FUNC_IMPL(__imp__sub_821E2E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2E08"))) PPC_WEAK_FUNC(sub_821E2E08);
PPC_FUNC_IMPL(__imp__sub_821E2E08) {
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
	// li r11,-1
	r11.s64 = -1;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// ble cr6,0x821e2e34
	if (!cr6.gt) goto loc_821E2E34;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-15120
	ctx.r3.s64 = r11.s64 + -15120;
	// bl 0x823dd898
	ctx.lr = 0x821E2E2C;
	sub_823DD898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x821E2E34;
	sub_823DB0A0(ctx, base);
loc_821E2E34:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821e2e54
	if (cr6.eq) goto loc_821E2E54;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x821E2E44;
	sub_82130528(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E2E54:
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

__attribute__((alias("__imp__sub_821E2E68"))) PPC_WEAK_FUNC(sub_821E2E68);
PPC_FUNC_IMPL(__imp__sub_821E2E68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x821e2e80
	if (cr6.eq) goto loc_821E2E80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821E2E80:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// beq cr6,0x821e2e9c
	if (cr6.eq) goto loc_821E2E9C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821E2E9C:
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// beq cr6,0x821e2eb4
	if (cr6.eq) goto loc_821E2EB4;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821E2EB4:
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E2EBC"))) PPC_WEAK_FUNC(sub_821E2EBC);
PPC_FUNC_IMPL(__imp__sub_821E2EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E2EC0"))) PPC_WEAK_FUNC(sub_821E2EC0);
PPC_FUNC_IMPL(__imp__sub_821E2EC0) {
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
	ctx.lr = 0x821E2EC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplw cr6,r23,r22
	cr6.compare<uint32_t>(r23.u32, r22.u32, xer);
	// beq cr6,0x821e3060
	if (cr6.eq) goto loc_821E3060;
	// lwz r11,20(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r31,r24,16
	r31.s64 = r24.s64 + 16;
	// lwz r10,16(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// addi r27,r24,20
	r27.s64 = r24.s64 + 20;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// beq cr6,0x821e2f00
	if (cr6.eq) goto loc_821E2F00;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_821E2F00:
	// subf r25,r23,r22
	r25.s64 = r22.s64 - r23.s64;
	// li r9,-2
	ctx.r9.s64 = -2;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r25,r9
	cr6.compare<uint32_t>(r25.u32, ctx.r9.u32, xer);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bgt cr6,0x821e2f24
	if (cr6.gt) goto loc_821E2F24;
	// subfic r11,r25,-2
	xer.ca = r25.u32 <= 4294967294;
	r11.s64 = -2 - r25.s64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x821e2f30
	if (!cr6.gt) goto loc_821E2F30;
loc_821E2F24:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,31776
	ctx.r3.s64 = r11.s64 + 31776;
	// bl 0x82616560
	ctx.lr = 0x821E2F30;
	sub_82616560(ctx, base);
loc_821E2F30:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x821e2f44
	if (cr6.eq) goto loc_821E2F44;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_821E2F44:
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// add r9,r25,r30
	ctx.r9.u64 = r25.u64 + r30.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x821e3010
	if (!cr6.gt) goto loc_821E3010;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// cmplw cr6,r30,r25
	cr6.compare<uint32_t>(r30.u32, r25.u32, xer);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x821e2f6c
	if (cr6.lt) goto loc_821E2F6C;
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
loc_821E2F6C:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821e2e08
	ctx.lr = 0x821E2F88;
	sub_821E2E08(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// mr r30,r24
	r30.u64 = r24.u64;
	// beq cr6,0x821e2fa4
	if (cr6.eq) goto loc_821E2FA4;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_821E2FA4:
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// beq cr6,0x821e2fc4
	if (cr6.eq) goto loc_821E2FC4;
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821E2FBC;
	sub_823DA950(ctx, base);
	// subf r11,r30,r3
	r11.s64 = ctx.r3.s64 - r30.s64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
loc_821E2FC4:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x823da950
	ctx.lr = 0x821E2FD0;
	sub_823DA950(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// subf r11,r23,r3
	r11.s64 = ctx.r3.s64 - r23.s64;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// add r30,r11,r22
	r30.u64 = r11.u64 + r22.u64;
	// beq cr6,0x821e2ff4
	if (cr6.eq) goto loc_821E2FF4;
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e2ff4
	if (cr6.eq) goto loc_821E2FF4;
	// bl 0x82130588
	ctx.lr = 0x821E2FF4;
	sub_82130588(ctx, base);
loc_821E2FF4:
	// add r11,r28,r26
	r11.u64 = r28.u64 + r26.u64;
	// stw r28,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r28.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_821E3010:
	// addi r3,r23,1
	ctx.r3.s64 = r23.s64 + 1;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x821e3038
	if (!cr6.eq) goto loc_821E3038;
	// subf. r5,r3,r22
	ctx.r5.s64 = r22.s64 - ctx.r3.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x821e3048
	if (cr0.eq) goto loc_821E3048;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x823da950
	ctx.lr = 0x821E3034;
	sub_823DA950(ctx, base);
	// b 0x821e3048
	goto loc_821E3048;
loc_821E3038:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x821e2db0
	ctx.lr = 0x821E3048;
	sub_821E2DB0(ctx, base);
loc_821E3048:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_821E3060:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821E306C"))) PPC_WEAK_FUNC(sub_821E306C);
PPC_FUNC_IMPL(__imp__sub_821E306C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3070"))) PPC_WEAK_FUNC(sub_821E3070);
PPC_FUNC_IMPL(__imp__sub_821E3070) {
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
	ctx.lr = 0x821E3078;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// subf r29,r30,r27
	r29.s64 = r27.s64 - r30.s64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x821e30a8
	if (cr6.eq) goto loc_821E30A8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_821E30A8:
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x821e3130
	if (cr6.gt) goto loc_821E3130;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x821e30c4
	if (cr6.eq) goto loc_821E30C4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_821E30C4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e30d8
	if (cr6.eq) goto loc_821E30D8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821E30D8;
	sub_823DA950(ctx, base);
loc_821E30D8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// beq cr6,0x821e30f0
	if (cr6.eq) goto loc_821E30F0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_821E30F0:
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// beq cr6,0x821e318c
	if (cr6.eq) goto loc_821E318C;
	// subf r11,r30,r30
	r11.s64 = r30.s64 - r30.s64;
	// addic. r5,r11,1
	xer.ca = r11.u32 > 4294967294;
	ctx.r5.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x821e3114
	if (cr0.eq) goto loc_821E3114;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823db5b0
	ctx.lr = 0x821E3114;
	sub_823DB5B0(ctx, base);
loc_821E3114:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821E3130:
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// beq cr6,0x821e3144
	if (cr6.eq) goto loc_821E3144;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bne cr6,0x821e314c
	if (!cr6.eq) goto loc_821E314C;
loc_821E3144:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x821e3150
	goto loc_821E3150;
loc_821E314C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_821E3150:
	// subf. r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x821e3160
	if (cr0.eq) goto loc_821E3160;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821E3160;
	sub_823DA950(ctx, base);
loc_821E3160:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// beq cr6,0x821e3178
	if (cr6.eq) goto loc_821E3178;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_821E3178:
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2ec0
	ctx.lr = 0x821E318C;
	sub_821E2EC0(ctx, base);
loc_821E318C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E3198"))) PPC_WEAK_FUNC(sub_821E3198);
PPC_FUNC_IMPL(__imp__sub_821E3198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821E31A0;
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
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E31C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x821e3374
	if (cr6.gt) goto loc_821E3374;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,12772
	r12.s64 = r12.s64 + 12772;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821E32D0;
	case 1:
		goto loc_821E326C;
	case 2:
		goto loc_821E31F4;
	case 3:
		goto loc_821E333C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,13008(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13008);
	// lwz r16,12908(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 12908);
	// lwz r16,12788(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 12788);
	// lwz r16,13116(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13116);
loc_821E31F4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 44);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + r29.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e3260
	if (cr6.eq) goto loc_821E3260;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e322c
	if (cr6.eq) goto loc_821E322C;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// b 0x821e3230
	goto loc_821E3230;
loc_821E322C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821E3230:
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_821E3234:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e3234
	if (!cr6.eq) goto loc_821E3234;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x821e3070
	ctx.lr = 0x821E3258;
	sub_821E3070(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E3260:
	// bl 0x821e2e68
	ctx.lr = 0x821E3264;
	sub_821E2E68(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E326C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3280;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r3,r29
	r31.u64 = ctx.r3.u64 + r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821E328C;
	sub_82130588(ctx, base);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x821E3298;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821e32b0
	if (cr6.eq) goto loc_821E32B0;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// b 0x821e32b4
	goto loc_821E32B4;
loc_821E32B0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821E32B4:
	// bl 0x8244d5c0
	ctx.lr = 0x821E32B8;
	sub_8244D5C0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r11,0
	r11.s64 = 0;
	// stbx r11,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E32D0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E32E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// lwz r10,20(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821e3300
	if (!cr6.lt) goto loc_821E3300;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821E3300:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e3310
	if (cr6.eq) goto loc_821E3310;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// b 0x821e3314
	goto loc_821E3314;
loc_821E3310:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821E3314:
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x821E3320;
	sub_8244D5C0(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// stb r10,-1(r8)
	PPC_STORE_U8(ctx.r8.u32 + -1, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821E333C:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e3350
	if (cr6.eq) goto loc_821E3350;
	// lwz r30,32(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// b 0x821e3354
	goto loc_821E3354;
loc_821E3350:
	// li r30,0
	r30.s64 = 0;
loc_821E3354:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821d2a58
	ctx.lr = 0x821E3374;
	sub_821D2A58(ctx, base);
loc_821E3374:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E337C"))) PPC_WEAK_FUNC(sub_821E337C);
PPC_FUNC_IMPL(__imp__sub_821E337C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3380"))) PPC_WEAK_FUNC(sub_821E3380);
PPC_FUNC_IMPL(__imp__sub_821E3380) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E33A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// beq cr6,0x821e33d4
	if (cr6.eq) goto loc_821E33D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E33C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x821e33d8
	if (!cr6.eq) goto loc_821E33D8;
loc_821E33D4:
	// li r11,1
	r11.s64 = 1;
loc_821E33D8:
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

__attribute__((alias("__imp__sub_821E33F0"))) PPC_WEAK_FUNC(sub_821E33F0);
PPC_FUNC_IMPL(__imp__sub_821E33F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,255
	ctx.r10.s64 = 255;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stb r10,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// sth r9,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, ctx.r9.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E3430"))) PPC_WEAK_FUNC(sub_821E3430);
PPC_FUNC_IMPL(__imp__sub_821E3430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E343C"))) PPC_WEAK_FUNC(sub_821E343C);
PPC_FUNC_IMPL(__imp__sub_821E343C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3440"))) PPC_WEAK_FUNC(sub_821E3440);
PPC_FUNC_IMPL(__imp__sub_821E3440) {
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
	ctx.lr = 0x821E3448;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,20(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x821e3380
	ctx.lr = 0x821E3460;
	sub_821E3380(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e34a4
	if (cr6.eq) goto loc_821E34A4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e34a4
	if (cr6.eq) goto loc_821E34A4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E348C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E34A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E34A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E34B0"))) PPC_WEAK_FUNC(sub_821E34B0);
PPC_FUNC_IMPL(__imp__sub_821E34B0) {
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
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E34DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821e3514
	if (cr6.lt) goto loc_821E3514;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// blt cr6,0x821e34f8
	if (cr6.lt) goto loc_821E34F8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821e352c
	goto loc_821E352C;
loc_821E34F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E350C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r3,r3,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r30.u32);
	// b 0x821e352c
	goto loc_821E352C;
loc_821E3514:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + r30.u64;
loc_821E352C:
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

__attribute__((alias("__imp__sub_821E3544"))) PPC_WEAK_FUNC(sub_821E3544);
PPC_FUNC_IMPL(__imp__sub_821E3544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3548"))) PPC_WEAK_FUNC(sub_821E3548);
PPC_FUNC_IMPL(__imp__sub_821E3548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821E3550;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x821e3714
	if (cr6.gt) goto loc_821E3714;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,13716
	r12.s64 = r12.s64 + 13716;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821E35A8;
	case 1:
		goto loc_821E3660;
	case 2:
		goto loc_821E3660;
	case 3:
		goto loc_821E35E8;
	case 4:
		goto loc_821E35E8;
	default:
		__builtin_unreachable();
	}
	// lwz r16,13736(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13736);
	// lwz r16,13920(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13920);
	// lwz r16,13920(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13920);
	// lwz r16,13800(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13800);
	// lwz r16,13800(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 13800);
loc_821E35A8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E35C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r5,r3,r30
	ctx.r5.u64 = ctx.r3.u64 + r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821E35E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821E35E8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E35FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r29,r3,r30
	r29.u64 = ctx.r3.u64 + r30.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821e3634
	if (!cr6.eq) goto loc_821E3634;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e3714
	if (cr6.eq) goto loc_821E3714;
loc_821E3634:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821e3440
	ctx.lr = 0x821E3640;
	sub_821E3440(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821E3660:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// add r29,r3,r30
	r29.u64 = ctx.r3.u64 + r30.u64;
	// addi r4,r9,22800
	ctx.r4.s64 = ctx.r9.s64 + 22800;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c7490
	ctx.lr = 0x821E3688;
	sub_821C7490(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e370c
	if (cr6.eq) goto loc_821E370C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E36A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// beq cr6,0x821e36ec
	if (cr6.eq) goto loc_821E36EC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r10,r10,17404
	ctx.r10.s64 = ctx.r10.s64 + 17404;
loc_821E36C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821e36e4
	if (cr6.eq) goto loc_821E36E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821e36c0
	if (cr6.eq) goto loc_821E36C0;
loc_821E36E4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821e370c
	if (cr6.eq) goto loc_821E370C;
loc_821E36EC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821E370C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_821E3714:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E371C"))) PPC_WEAK_FUNC(sub_821E371C);
PPC_FUNC_IMPL(__imp__sub_821E371C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3720"))) PPC_WEAK_FUNC(sub_821E3720);
PPC_FUNC_IMPL(__imp__sub_821E3720) {
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
	ctx.lr = 0x821E3728;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821e38bc
	if (cr6.eq) goto loc_821E38BC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x821e37b8
	if (!cr6.gt) goto loc_821E37B8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bgt cr6,0x821e37b8
	if (cr6.gt) goto loc_821E37B8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// bl 0x821c7490
	ctx.lr = 0x821E3774;
	sub_821C7490(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821e37c4
	if (cr6.eq) goto loc_821E37C4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r10,r10,17404
	ctx.r10.s64 = ctx.r10.s64 + 17404;
loc_821E378C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821e37b0
	if (cr6.eq) goto loc_821E37B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821e378c
	if (cr6.eq) goto loc_821E378C;
loc_821E37B0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821e37c4
	if (!cr6.eq) goto loc_821E37C4;
loc_821E37B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E37C4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r29,20(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mr r30,r29
	r30.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E37E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,4
	cr6.compare<uint32_t>(ctx.r8.u32, 4, xer);
	// beq cr6,0x821e3878
	if (cr6.eq) goto loc_821E3878;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821e3878
	if (cr6.eq) goto loc_821E3878;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r3,2828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// bl 0x821bee48
	ctx.lr = 0x821E3808;
	sub_821BEE48(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821e3878
	if (!cr6.eq) goto loc_821E3878;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e3874
	if (cr6.eq) goto loc_821E3874;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r30,r3,r27
	r30.u64 = ctx.r3.u64 + r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E3850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821E3868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E3874:
	// mr r30,r29
	r30.u64 = r29.u64;
loc_821E3878:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E388C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r29,r3,r27
	r29.u64 = ctx.r3.u64 + r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d4bb0
	ctx.lr = 0x821E3898;
	sub_821D4BB0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E38B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E38BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E38D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r3,r3,r27
	ctx.r3.u64 = ctx.r3.u64 + r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E38DC"))) PPC_WEAK_FUNC(sub_821E38DC);
PPC_FUNC_IMPL(__imp__sub_821E38DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E38E0"))) PPC_WEAK_FUNC(sub_821E38E0);
PPC_FUNC_IMPL(__imp__sub_821E38E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// sth r8,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, ctx.r8.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E3928"))) PPC_WEAK_FUNC(sub_821E3928);
PPC_FUNC_IMPL(__imp__sub_821E3928) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,13792
	ctx.r10.s64 = r11.s64 + 13792;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E3954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,31
	ctx.r8.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821e397c
	if (!cr6.eq) goto loc_821E397C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e3974
	if (cr6.eq) goto loc_821E3974;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821E3974;
	sub_82130588(ctx, base);
loc_821E3974:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821E397C;
	sub_82130588(ctx, base);
loc_821E397C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,13540
	ctx.r10.s64 = r11.s64 + 13540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821E399C"))) PPC_WEAK_FUNC(sub_821E399C);
PPC_FUNC_IMPL(__imp__sub_821E399C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E39A0"))) PPC_WEAK_FUNC(sub_821E39A0);
PPC_FUNC_IMPL(__imp__sub_821E39A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821E39A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E39C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,8
	cr6.compare<int32_t>(ctx.r3.s32, 8, xer);
	// beq cr6,0x821e3a5c
	if (cr6.eq) goto loc_821E3A5C;
	// cmpwi cr6,r3,9
	cr6.compare<int32_t>(ctx.r3.s32, 9, xer);
	// beq cr6,0x821e3a28
	if (cr6.eq) goto loc_821E3A28;
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// beq cr6,0x821e39f4
	if (cr6.eq) goto loc_821E39F4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,22944
	ctx.r3.s64 = r11.s64 + 22944;
	// bl 0x821bd618
	ctx.lr = 0x821E39EC;
	sub_821BD618(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
loc_821E39F4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3A08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r3,r29
	r31.u64 = ctx.r3.u64 + r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c80f0
	ctx.lr = 0x821E3A18;
	sub_821C80F0(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
loc_821E3A28:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3A3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r3,r29
	r31.u64 = ctx.r3.u64 + r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8048
	ctx.lr = 0x821E3A4C;
	sub_821C8048(ctx, base);
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
loc_821E3A5C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E3A70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r31,r3,r29
	r31.u64 = ctx.r3.u64 + r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c7fc0
	ctx.lr = 0x821E3A80;
	sub_821C7FC0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E3A98"))) PPC_WEAK_FUNC(sub_821E3A98);
PPC_FUNC_IMPL(__imp__sub_821E3A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// sth r8,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, ctx.r8.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E3AD4"))) PPC_WEAK_FUNC(sub_821E3AD4);
PPC_FUNC_IMPL(__imp__sub_821E3AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E3AD8"))) PPC_WEAK_FUNC(sub_821E3AD8);
PPC_FUNC_IMPL(__imp__sub_821E3AD8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,13844
	ctx.r10.s64 = r11.s64 + 13844;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E3B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,31
	ctx.r8.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821e3b2c
	if (!cr6.eq) goto loc_821E3B2C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e3b24
	if (cr6.eq) goto loc_821E3B24;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821E3B24;
	sub_82130588(ctx, base);
loc_821E3B24:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821E3B2C;
	sub_82130588(ctx, base);
loc_821E3B2C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,13540
	ctx.r10.s64 = r11.s64 + 13540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821E3B4C"))) PPC_WEAK_FUNC(sub_821E3B4C);
PPC_FUNC_IMPL(__imp__sub_821E3B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

