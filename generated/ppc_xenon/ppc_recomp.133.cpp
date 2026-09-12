#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8267436C"))) PPC_WEAK_FUNC(sub_8267436C);
PPC_FUNC_IMPL(__imp__sub_8267436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674370"))) PPC_WEAK_FUNC(sub_82674370);
PPC_FUNC_IMPL(__imp__sub_82674370) {
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
	// bl 0x82634010
	ctx.lr = 0x82674388;
	sub_82634010(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
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

__attribute__((alias("__imp__sub_826743A4"))) PPC_WEAK_FUNC(sub_826743A4);
PPC_FUNC_IMPL(__imp__sub_826743A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826743A8"))) PPC_WEAK_FUNC(sub_826743A8);
PPC_FUNC_IMPL(__imp__sub_826743A8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x826743e4
	if (!cr6.eq) goto loc_826743E4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826743D0;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826743E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826743E4:
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

__attribute__((alias("__imp__sub_826743FC"))) PPC_WEAK_FUNC(sub_826743FC);
PPC_FUNC_IMPL(__imp__sub_826743FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674400"))) PPC_WEAK_FUNC(sub_82674400);
PPC_FUNC_IMPL(__imp__sub_82674400) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x826744ac
	if (!cr6.eq) goto loc_826744AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267443C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,246(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674470
	if (cr6.eq) goto loc_82674470;
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82674468
	if (cr6.eq) goto loc_82674468;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,744(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 744);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674468:
	// li r11,0
	r11.s64 = 0;
	// stb r11,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r11.u8);
loc_82674470:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 756);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674484;
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
	ctx.lr = 0x82674498;
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
loc_826744AC:
	// bl 0x82630580
	ctx.lr = 0x826744B0;
	sub_82630580(ctx, base);
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

__attribute__((alias("__imp__sub_826744C4"))) PPC_WEAK_FUNC(sub_826744C4);
PPC_FUNC_IMPL(__imp__sub_826744C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826744C8"))) PPC_WEAK_FUNC(sub_826744C8);
PPC_FUNC_IMPL(__imp__sub_826744C8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674504
	if (cr6.eq) goto loc_82674504;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826744f4
	if (cr6.eq) goto loc_826744F4;
	// bl 0x826537d0
	ctx.lr = 0x826744F0;
	sub_826537D0(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_826744F4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x82674500;
	sub_821E6800(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_82674504:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674510;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674524:
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

__attribute__((alias("__imp__sub_8267453C"))) PPC_WEAK_FUNC(sub_8267453C);
PPC_FUNC_IMPL(__imp__sub_8267453C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674540"))) PPC_WEAK_FUNC(sub_82674540);
PPC_FUNC_IMPL(__imp__sub_82674540) {
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
	// bl 0x82653b30
	ctx.lr = 0x82674550;
	sub_82653B30(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x82674554;
	sub_82216788(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x82674558;
	sub_82215A60(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674568"))) PPC_WEAK_FUNC(sub_82674568);
PPC_FUNC_IMPL(__imp__sub_82674568) {
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
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r30,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,26,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,25,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,24,24
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,21,21
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,20,20
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,19,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,18,18
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82674610
	if (cr6.eq) goto loc_82674610;
loc_826745EC:
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r4,r10,25828
	ctx.r4.s64 = ctx.r10.s64 + 25828;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674610:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,22,22
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267467c
	if (cr6.eq) goto loc_8267467C;
loc_8267464C:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,126
	ctx.r9.s64 = r11.s64 + 126;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r8,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r8.u32);
	// addi r4,r10,25800
	ctx.r4.s64 = ctx.r10.s64 + 25800;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267467C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267467C:
	// rlwinm r11,r30,0,27,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826746b8
	if (cr6.eq) goto loc_826746B8;
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r8,r11,126
	ctx.r8.s64 = r11.s64 + 126;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r9.u32);
	// addi r4,r10,25768
	ctx.r4.s64 = ctx.r10.s64 + 25768;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826746B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826746B8:
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

__attribute__((alias("__imp__sub_826746D0"))) PPC_WEAK_FUNC(sub_826746D0);
PPC_FUNC_IMPL(__imp__sub_826746D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653f28
	sub_82653F28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746D4"))) PPC_WEAK_FUNC(sub_826746D4);
PPC_FUNC_IMPL(__imp__sub_826746D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746D8"))) PPC_WEAK_FUNC(sub_826746D8);
PPC_FUNC_IMPL(__imp__sub_826746D8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653b30
	sub_82653B30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746DC"))) PPC_WEAK_FUNC(sub_826746DC);
PPC_FUNC_IMPL(__imp__sub_826746DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E0"))) PPC_WEAK_FUNC(sub_826746E0);
PPC_FUNC_IMPL(__imp__sub_826746E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653670
	sub_82653670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746E4"))) PPC_WEAK_FUNC(sub_826746E4);
PPC_FUNC_IMPL(__imp__sub_826746E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E8"))) PPC_WEAK_FUNC(sub_826746E8);
PPC_FUNC_IMPL(__imp__sub_826746E8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674718
	if (cr6.eq) goto loc_82674718;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r9,r11,24348
	ctx.r9.s64 = r11.s64 + 24348;
	// b 0x82674720
	goto loc_82674720;
loc_82674718:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
loc_82674720:
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674738;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267474C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267474C:
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

__attribute__((alias("__imp__sub_82674764"))) PPC_WEAK_FUNC(sub_82674764);
PPC_FUNC_IMPL(__imp__sub_82674764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674768"))) PPC_WEAK_FUNC(sub_82674768);
PPC_FUNC_IMPL(__imp__sub_82674768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267477C"))) PPC_WEAK_FUNC(sub_8267477C);
PPC_FUNC_IMPL(__imp__sub_8267477C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674780"))) PPC_WEAK_FUNC(sub_82674780);
PPC_FUNC_IMPL(__imp__sub_82674780) {
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
	ctx.lr = 0x82674788;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x826747a4
	if (!cr6.eq) goto loc_826747A4;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
loc_826747A4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,-10224
	r29.s64 = ctx.r10.s64 + -10224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826747C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee270
	ctx.lr = 0x826747D0;
	sub_825EE270(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826747E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82653450
	ctx.lr = 0x82674814;
	sub_82653450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8267481C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674828"))) PPC_WEAK_FUNC(sub_82674828);
PPC_FUNC_IMPL(__imp__sub_82674828) {
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
	// bl 0x82630580
	ctx.lr = 0x82674840;
	sub_82630580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674854;
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

__attribute__((alias("__imp__sub_82674868"))) PPC_WEAK_FUNC(sub_82674868);
PPC_FUNC_IMPL(__imp__sub_82674868) {
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
	// bl 0x82674400
	ctx.lr = 0x82674880;
	sub_82674400(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82674894;
	sub_8262FFE0(ctx, base);
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

__attribute__((alias("__imp__sub_826748A8"))) PPC_WEAK_FUNC(sub_826748A8);
PPC_FUNC_IMPL(__imp__sub_826748A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826748BC"))) PPC_WEAK_FUNC(sub_826748BC);
PPC_FUNC_IMPL(__imp__sub_826748BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826748C0"))) PPC_WEAK_FUNC(sub_826748C0);
PPC_FUNC_IMPL(__imp__sub_826748C0) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267491c
	if (cr6.eq) goto loc_8267491C;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826748fc
	if (cr6.eq) goto loc_826748FC;
	// bl 0x826537d0
	ctx.lr = 0x826748E8;
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
loc_826748FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82674950
	if (cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// b 0x82674938
	goto loc_82674938;
loc_8267491C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82674950
	if (!cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
loc_82674938:
	// bl 0x821e6800
	ctx.lr = 0x8267493C;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674950:
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

__attribute__((alias("__imp__sub_82674968"))) PPC_WEAK_FUNC(sub_82674968);
PPC_FUNC_IMPL(__imp__sub_82674968) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826535f8
	ctx.lr = 0x82674984;
	sub_826535F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826749B0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826749C0;
	sub_825ED480(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13284
	ctx.r4.s64 = ctx.r7.s64 + -13284;
	// bl 0x82722678
	ctx.lr = 0x826749D8;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_826749F0"))) PPC_WEAK_FUNC(sub_826749F0);
PPC_FUNC_IMPL(__imp__sub_826749F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r5,1008(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1008, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674A00"))) PPC_WEAK_FUNC(sub_82674A00);
PPC_FUNC_IMPL(__imp__sub_82674A00) {
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
	ctx.lr = 0x82674A18;
	sub_82653B30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// lwz r3,-19636(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19636);
	// bl 0x821e6800
	ctx.lr = 0x82674A3C;
	sub_821E6800(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r31,1000
	ctx.r4.s64 = r31.s64 + 1000;
	// lwz r3,-19632(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19632);
	// bl 0x821e6810
	ctx.lr = 0x82674A4C;
	sub_821E6810(ctx, base);
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

__attribute__((alias("__imp__sub_82674A60"))) PPC_WEAK_FUNC(sub_82674A60);
PPC_FUNC_IMPL(__imp__sub_82674A60) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674aa4
	if (cr6.eq) goto loc_82674AA4;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,992(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
loc_82674AA4:
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

__attribute__((alias("__imp__sub_82674ABC"))) PPC_WEAK_FUNC(sub_82674ABC);
PPC_FUNC_IMPL(__imp__sub_82674ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674AC0"))) PPC_WEAK_FUNC(sub_82674AC0);
PPC_FUNC_IMPL(__imp__sub_82674AC0) {
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
	// bl 0x82653670
	ctx.lr = 0x82674AD8;
	sub_82653670(ctx, base);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82674aec
	if (cr6.eq) goto loc_82674AEC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x82674AEC;
	sub_8213C218(ctx, base);
loc_82674AEC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-19628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -19628);
	// bl 0x821e6800
	ctx.lr = 0x82674AF8;
	sub_821E6800(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r10,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674B18;
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

__attribute__((alias("__imp__sub_82674B2C"))) PPC_WEAK_FUNC(sub_82674B2C);
PPC_FUNC_IMPL(__imp__sub_82674B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674B30"))) PPC_WEAK_FUNC(sub_82674B30);
PPC_FUNC_IMPL(__imp__sub_82674B30) {
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
	ctx.lr = 0x82674B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826535f8
	ctx.lr = 0x82674B44;
	sub_826535F8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25856
	ctx.r4.s64 = r11.s64 + 25856;
	// bl 0x825ee120
	ctx.lr = 0x82674B58;
	sub_825EE120(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r10,2612
	r30.s64 = ctx.r10.s64 + 2612;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82674B70;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82674B80;
	sub_825ED480(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-13268
	ctx.r4.s64 = ctx.r9.s64 + -13268;
	// bl 0x82722678
	ctx.lr = 0x82674B90;
	sub_82722678(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r8,-12592
	ctx.r4.s64 = ctx.r8.s64 + -12592;
	// bl 0x825ee0e0
	ctx.lr = 0x82674BA4;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674BAC"))) PPC_WEAK_FUNC(sub_82674BAC);
PPC_FUNC_IMPL(__imp__sub_82674BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674BB0"))) PPC_WEAK_FUNC(sub_82674BB0);
PPC_FUNC_IMPL(__imp__sub_82674BB0) {
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
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82674c30
	if (cr6.gt) goto loc_82674C30;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,19432
	r12.s64 = r12.s64 + 19432;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82674BF8;
	case 1:
		goto loc_82674C18;
	case 2:
		goto loc_82674C18;
	case 3:
		goto loc_82674C18;
	default:
		__builtin_unreachable();
	}
	// lwz r19,19448(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19448);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
	// lwz r19,19480(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19480);
loc_82674BF8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674C04;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674C18:
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
loc_82674C30:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82674C38;
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
}

__attribute__((alias("__imp__sub_82674C4C"))) PPC_WEAK_FUNC(sub_82674C4C);
PPC_FUNC_IMPL(__imp__sub_82674C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674C50"))) PPC_WEAK_FUNC(sub_82674C50);
PPC_FUNC_IMPL(__imp__sub_82674C50) {
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
	// bl 0x82653670
	ctx.lr = 0x82674C60;
	sub_82653670(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82674C68;
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

__attribute__((alias("__imp__sub_82674C78"))) PPC_WEAK_FUNC(sub_82674C78);
PPC_FUNC_IMPL(__imp__sub_82674C78) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674cec
	if (cr6.eq) goto loc_82674CEC;
	// lfs f0,1008(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,1008(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82674cec
	if (!cr6.gt) goto loc_82674CEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1008(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
loc_82674CEC:
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

__attribute__((alias("__imp__sub_82674D04"))) PPC_WEAK_FUNC(sub_82674D04);
PPC_FUNC_IMPL(__imp__sub_82674D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674D08"))) PPC_WEAK_FUNC(sub_82674D08);
PPC_FUNC_IMPL(__imp__sub_82674D08) {
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
	// bl 0x82630158
	ctx.lr = 0x82674D24;
	sub_82630158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r31,224
	ctx.r5.s64 = r31.s64 + 224;
	// addi r4,r11,20292
	ctx.r4.s64 = r11.s64 + 20292;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82722678
	ctx.lr = 0x82674D38;
	sub_82722678(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// bl 0x827227b8
	ctx.lr = 0x82674D4C;
	sub_827227B8(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,212(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r4,r9,-11016
	ctx.r4.s64 = ctx.r9.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x82674D60;
	sub_827227B8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r4,r8,-11024
	ctx.r4.s64 = ctx.r8.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x82674D74;
	sub_827227B8(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// addi r4,r7,-11032
	ctx.r4.s64 = ctx.r7.s64 + -11032;
	// bl 0x827227b8
	ctx.lr = 0x82674D88;
	sub_827227B8(ctx, base);
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

__attribute__((alias("__imp__sub_82674DA0"))) PPC_WEAK_FUNC(sub_82674DA0);
PPC_FUNC_IMPL(__imp__sub_82674DA0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674de4
	if (cr6.eq) goto loc_82674DE4;
	// lfs f0,1064(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1064);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,1064(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
loc_82674DE4:
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

__attribute__((alias("__imp__sub_82674DFC"))) PPC_WEAK_FUNC(sub_82674DFC);
PPC_FUNC_IMPL(__imp__sub_82674DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674E00"))) PPC_WEAK_FUNC(sub_82674E00);
PPC_FUNC_IMPL(__imp__sub_82674E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82674e20
	if (cr6.eq) goto loc_82674E20;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82674E20:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674E28"))) PPC_WEAK_FUNC(sub_82674E28);
PPC_FUNC_IMPL(__imp__sub_82674E28) {
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
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82674eb8
	if (cr6.eq) goto loc_82674EB8;
loc_82674E4C:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82674eb8
	if (cr6.eq) goto loc_82674EB8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x82674eac
	if (!cr6.eq) goto loc_82674EAC;
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
	ctx.lr = 0x82674E94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,744(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674EAC:
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82674e4c
	if (!cr6.eq) goto loc_82674E4C;
loc_82674EB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630580
	ctx.lr = 0x82674EC0;
	sub_82630580(ctx, base);
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

__attribute__((alias("__imp__sub_82674ED8"))) PPC_WEAK_FUNC(sub_82674ED8);
PPC_FUNC_IMPL(__imp__sub_82674ED8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,6892
	ctx.r4.s64 = r11.s64 + 6892;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633e80
	ctx.lr = 0x82674EFC;
	sub_82633E80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,25884
	ctx.r8.s64 = ctx.r10.s64 + 25884;
	// stb r9,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
}

__attribute__((alias("__imp__sub_82674F28"))) PPC_WEAK_FUNC(sub_82674F28);
PPC_FUNC_IMPL(__imp__sub_82674F28) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82674f6c
	if (cr6.eq) goto loc_82674F6C;
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
	ctx.lr = 0x82674F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674F6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653670
	ctx.lr = 0x82674F74;
	sub_82653670(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x82674F78;
	sub_822150D8(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x82674F7C;
	sub_82216648(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-21704
	ctx.r3.s64 = ctx.r10.s64 + -21704;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x82674F9C;
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
	ctx.lr = 0x82674FB0;
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

__attribute__((alias("__imp__sub_82674FC8"))) PPC_WEAK_FUNC(sub_82674FC8);
PPC_FUNC_IMPL(__imp__sub_82674FC8) {
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
	// bl 0x82653670
	ctx.lr = 0x82674FD8;
	sub_82653670(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4520
	ctx.lr = 0x82674FE4;
	sub_826C4520(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674FF4"))) PPC_WEAK_FUNC(sub_82674FF4);
PPC_FUNC_IMPL(__imp__sub_82674FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674FF8"))) PPC_WEAK_FUNC(sub_82674FF8);
PPC_FUNC_IMPL(__imp__sub_82674FF8) {
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
	ctx.lr = 0x82675000;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x8267500C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82675020
	if (cr6.eq) goto loc_82675020;
	// bl 0x82256058
	ctx.lr = 0x82675018;
	sub_82256058(ctx, base);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// b 0x82675024
	goto loc_82675024;
loc_82675020:
	// li r28,0
	r28.s64 = 0;
loc_82675024:
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82675030;
	sub_822A39C8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826750c4
	if (cr6.eq) goto loc_826750C4;
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826750c4
	if (cr6.eq) goto loc_826750C4;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8267506C:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826750a8
	if (cr6.eq) goto loc_826750A8;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82675080;
	sub_822A39C8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x826750a8
	if (cr6.eq) goto loc_826750A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826750A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r25
	cr6.compare<int32_t>(ctx.r3.s32, r25.s32, xer);
	// beq cr6,0x826750c0
	if (cr6.eq) goto loc_826750C0;
loc_826750A8:
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bne cr6,0x8267506c
	if (!cr6.eq) goto loc_8267506C;
	// b 0x826750c4
	goto loc_826750C4;
loc_826750C0:
	// li r23,1
	r23.s64 = 1;
loc_826750C4:
	// cmpwi cr6,r25,16
	cr6.compare<int32_t>(r25.s32, 16, xer);
	// addi r29,r31,1004
	r29.s64 = r31.s64 + 1004;
	// bgt cr6,0x826750ec
	if (cr6.gt) goto loc_826750EC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826750E8;
	sub_82137A08(ctx, base);
	// b 0x8267510c
	goto loc_8267510C;
loc_826750EC:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stb r11,1004(r31)
	PPC_STORE_U8(r31.u32 + 1004, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// li r24,1
	r24.s64 = 1;
	// li r23,0
	r23.s64 = 0;
	// bl 0x8263b860
	ctx.lr = 0x8267510C;
	sub_8263B860(ctx, base);
loc_8267510C:
	// clrlwi r28,r24,24
	r28.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8267517c
	if (!cr6.eq) goto loc_8267517C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b428
	ctx.lr = 0x82675124;
	sub_8263B428(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// beq cr6,0x8267516c
	if (cr6.eq) goto loc_8267516C;
	// cmpwi cr6,r25,2
	cr6.compare<int32_t>(r25.s32, 2, xer);
	// beq cr6,0x82675160
	if (cr6.eq) goto loc_82675160;
	// cmpwi cr6,r25,3
	cr6.compare<int32_t>(r25.s32, 3, xer);
	// beq cr6,0x82675154
	if (cr6.eq) goto loc_82675154;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2348
	ctx.r4.s64 = ctx.r10.s64 + 2348;
	// b 0x82675174
	goto loc_82675174;
loc_82675154:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26824
	ctx.r4.s64 = ctx.r10.s64 + 26824;
	// b 0x82675174
	goto loc_82675174;
loc_82675160:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26820
	ctx.r4.s64 = ctx.r10.s64 + 26820;
	// b 0x82675174
	goto loc_82675174;
loc_8267516C:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,26816
	ctx.r4.s64 = ctx.r10.s64 + 26816;
loc_82675174:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267517C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267517C:
	// clrlwi r30,r23,24
	r30.u64 = r23.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// cntlzw r9,r30
	ctx.r9.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// addi r27,r10,26800
	r27.s64 = ctx.r10.s64 + 26800;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r7,468(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r26,r8,1
	r26.u64 = ctx.r8.u64 ^ 1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826751A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826751B4;
	sub_825EE0E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r6,r28
	ctx.r6.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r27,r5,26784
	r27.s64 = ctx.r5.s64 + 26784;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// xori r26,r4,1
	r26.u64 = ctx.r4.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826751DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826751E8;
	sub_825EE0E0(ctx, base);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82675254
	if (!cr6.gt) goto loc_82675254;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,26776
	ctx.r5.s64 = r11.s64 + 26776;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82675208;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,26744
	ctx.r4.s64 = ctx.r9.s64 + 26744;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82675220;
	sub_822183B0(ctx, base);
	// lwz r7,1024(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// addi r4,r8,26712
	ctx.r4.s64 = ctx.r8.s64 + 26712;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267523C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82675268
	goto loc_82675268;
loc_82675254:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82675268:
	// bctrl 
	ctx.lr = 0x8267526C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// beq cr6,0x82675288
	if (cr6.eq) goto loc_82675288;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r6,r11,26704
	ctx.r6.s64 = r11.s64 + 26704;
	// b 0x8267528c
	goto loc_8267528C;
loc_82675288:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_8267528C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8267529c
	if (cr6.eq) goto loc_8267529C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r11,26696
	ctx.r5.s64 = r11.s64 + 26696;
loc_8267529C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,26652
	ctx.r3.s64 = r11.s64 + 26652;
	// bl 0x82130000
	ctx.lr = 0x826752AC;
	sub_82130000(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826752B4"))) PPC_WEAK_FUNC(sub_826752B4);
PPC_FUNC_IMPL(__imp__sub_826752B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826752B8"))) PPC_WEAK_FUNC(sub_826752B8);
PPC_FUNC_IMPL(__imp__sub_826752B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,18504(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// lhz r11,4(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826752fc
	if (!cr6.gt) goto loc_826752FC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_826752D4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826752e8
	if (!cr6.eq) goto loc_826752E8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_826752E8:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826752d4
	if (!cr0.eq) goto loc_826752D4;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82675304
	if (!cr6.eq) goto loc_82675304;
loc_826752FC:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82675304:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267530C"))) PPC_WEAK_FUNC(sub_8267530C);
PPC_FUNC_IMPL(__imp__sub_8267530C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675310"))) PPC_WEAK_FUNC(sub_82675310);
PPC_FUNC_IMPL(__imp__sub_82675310) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,18508(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x82675338;
	sub_826B95B0(ctx, base);
	// lwz r11,18508(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,508(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// stw r9,3684(r31)
	PPC_STORE_U32(r31.u32 + 3684, ctx.r9.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r8,3688(r31)
	PPC_STORE_U32(r31.u32 + 3688, ctx.r8.u32);
	// lwz r3,18504(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18504);
	// bl 0x826b53f8
	ctx.lr = 0x82675358;
	sub_826B53F8(ctx, base);
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

__attribute__((alias("__imp__sub_82675370"))) PPC_WEAK_FUNC(sub_82675370);
PPC_FUNC_IMPL(__imp__sub_82675370) {
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
	// bl 0x82653670
	ctx.lr = 0x82675388;
	sub_82653670(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// bl 0x826b6228
	ctx.lr = 0x82675394;
	sub_826B6228(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_826753B0"))) PPC_WEAK_FUNC(sub_826753B0);
PPC_FUNC_IMPL(__imp__sub_826753B0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826753DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267543c
	if (cr6.eq) goto loc_8267543C;
	// lfs f0,3664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3664);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,3664(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x826753F8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826754b8
	if (cr6.eq) goto loc_826754B8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3664);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826754b8
	if (!cr6.gt) goto loc_826754B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267542C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,3664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// b 0x826754b8
	goto loc_826754B8;
loc_8267543C:
	// lwz r11,3692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3692);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82675490
	if (cr6.eq) goto loc_82675490;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826754b8
	if (!cr6.eq) goto loc_826754B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826754b8
	if (!cr6.eq) goto loc_826754B8;
	// li r11,3
	r11.s64 = 3;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, r11.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8267548C;
	sub_82213338(ctx, base);
	// b 0x826754b8
	goto loc_826754B8;
loc_82675490:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826754A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826754b8
	if (cr6.eq) goto loc_826754B8;
	// li r11,2
	r11.s64 = 2;
	// stw r11,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, r11.u32);
loc_826754B8:
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

__attribute__((alias("__imp__sub_826754D0"))) PPC_WEAK_FUNC(sub_826754D0);
PPC_FUNC_IMPL(__imp__sub_826754D0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x826754D8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f588
	ctx.lr = 0x826754F4;
	sub_8227F588(ctx, base);
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f588
	ctx.lr = 0x82675508;
	sub_8227F588(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267551C;
	sub_822A3998(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267552C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r25,r11,27136
	r25.s64 = r11.s64 + 27136;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stfs f0,1064(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r29,-10244(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// addi r24,r10,2352
	r24.s64 = ctx.r10.s64 + 2352;
	// addi r28,r9,27124
	r28.s64 = ctx.r9.s64 + 27124;
	// addi r27,r8,27104
	r27.s64 = ctx.r8.s64 + 27104;
	// addi r23,r31,992
	r23.s64 = r31.s64 + 992;
	// addi r30,r11,-10244
	r30.s64 = r11.s64 + -10244;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x826755b0
	if (!cr6.eq) goto loc_826755B0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82218310
	ctx.lr = 0x82675580;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r11,27092
	ctx.r4.s64 = r11.s64 + 27092;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x82675594;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// bl 0x82137a08
	ctx.lr = 0x826755AC;
	sub_82137A08(ctx, base);
	// b 0x826755e8
	goto loc_826755E8;
loc_826755B0:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x826755B8;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r11,27092
	ctx.r4.s64 = r11.s64 + 27092;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826755CC;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// bl 0x82137a08
	ctx.lr = 0x826755E8;
	sub_82137A08(ctx, base);
loc_826755E8:
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r22,-1
	cr6.compare<int32_t>(r22.s32, -1, xer);
	// addi r29,r31,1024
	r29.s64 = r31.s64 + 1024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x82675634
	if (!cr6.eq) goto loc_82675634;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82218310
	ctx.lr = 0x82675604;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,27076
	ctx.r4.s64 = r11.s64 + 27076;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82675618;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82675630;
	sub_82137A08(ctx, base);
	// b 0x8267566c
	goto loc_8267566C;
loc_82675634:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x8267563C;
	sub_82218310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r11,27076
	ctx.r4.s64 = r11.s64 + 27076;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82675650;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267566C;
	sub_82137A08(ctx, base);
loc_8267566C:
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// bne cr6,0x82675680
	if (!cr6.eq) goto loc_82675680;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27056
	ctx.r4.s64 = ctx.r10.s64 + 27056;
	// b 0x82675698
	goto loc_82675698;
loc_82675680:
	// cmpwi cr6,r21,2
	cr6.compare<int32_t>(r21.s32, 2, xer);
	// bne cr6,0x826756e4
	if (!cr6.eq) goto loc_826756E4;
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// bgt cr6,0x826756f4
	if (cr6.gt) goto loc_826756F4;
loc_82675690:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27032
	ctx.r4.s64 = ctx.r10.s64 + 27032;
loc_82675698:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826756AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1056(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826756C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1060(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,344(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 344);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826756DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_826756E4:
	// cmpwi cr6,r21,1
	cr6.compare<int32_t>(r21.s32, 1, xer);
	// bne cr6,0x82675690
	if (!cr6.eq) goto loc_82675690;
	// cmpw cr6,r22,r26
	cr6.compare<int32_t>(r22.s32, r26.s32, xer);
	// ble cr6,0x82675690
	if (!cr6.gt) goto loc_82675690;
loc_826756F4:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,27012
	ctx.r4.s64 = ctx.r10.s64 + 27012;
	// b 0x82675698
	goto loc_82675698;
}

__attribute__((alias("__imp__sub_82675700"))) PPC_WEAK_FUNC(sub_82675700);
PPC_FUNC_IMPL(__imp__sub_82675700) {
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
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8267572C;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82675744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r4,r11,27144
	ctx.r4.s64 = r11.s64 + 27144;
	// li r5,3
	ctx.r5.s64 = 3;
	// bne cr6,0x82675764
	if (!cr6.eq) goto loc_82675764;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82675764:
	// bl 0x825ee0e0
	ctx.lr = 0x82675768;
	sub_825EE0E0(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267578c
	if (cr6.eq) goto loc_8267578C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826757b4
	goto loc_826757B4;
loc_8267578C:
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
	ctx.lr = 0x826757A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x826757B4;
	sub_825EE0E0(ctx, base);
loc_826757B4:
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

__attribute__((alias("__imp__sub_826757CC"))) PPC_WEAK_FUNC(sub_826757CC);
PPC_FUNC_IMPL(__imp__sub_826757CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826757D0"))) PPC_WEAK_FUNC(sub_826757D0);
PPC_FUNC_IMPL(__imp__sub_826757D0) {
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
	ctx.lr = 0x826757D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,764
	ctx.r4.s64 = ctx.r10.s64 + 764;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826757FC;
	sub_82691650(ctx, base);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r9,3998
	ctx.r4.s64 = ctx.r9.s64 + 3998;
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// stw r28,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r28.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267582C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r6,27172
	ctx.r4.s64 = ctx.r6.s64 + 27172;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x82675840;
	sub_8268DA78(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r29,r11,29572
	r29.s64 = r11.s64 + 29572;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r5,27160
	ctx.r4.s64 = ctx.r5.s64 + 27160;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x8268da78
	ctx.lr = 0x82675864;
	sub_8268DA78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r30,860(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x82675898
	if (cr6.gt) goto loc_82675898;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82675898:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826758B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826347f0
	ctx.lr = 0x826758C0;
	sub_826347F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826758D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826758f4
	if (cr6.eq) goto loc_826758F4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826758F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826758F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826758FC"))) PPC_WEAK_FUNC(sub_826758FC);
PPC_FUNC_IMPL(__imp__sub_826758FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675900"))) PPC_WEAK_FUNC(sub_82675900);
PPC_FUNC_IMPL(__imp__sub_82675900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x82675310
	sub_82675310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267590C"))) PPC_WEAK_FUNC(sub_8267590C);
PPC_FUNC_IMPL(__imp__sub_8267590C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82675910"))) PPC_WEAK_FUNC(sub_82675910);
PPC_FUNC_IMPL(__imp__sub_82675910) {
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
	ctx.lr = 0x82675918;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675924;
	sub_82653B30(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x82675928;
	sub_82216788(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8267592C;
	sub_82215A60(ctx, base);
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,126
	ctx.r9.s64 = r11.s64 + 126;
	// addi r4,r10,25216
	ctx.r4.s64 = ctx.r10.s64 + 25216;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r8,r11,r31
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r27,r31,992
	r27.s64 = r31.s64 + 992;
	// addi r4,r6,27840
	ctx.r4.s64 = ctx.r6.s64 + 27840;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82675974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,1040(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x826759bc
	if (!cr6.gt) goto loc_826759BC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,996
	r29.s64 = r31.s64 + 996;
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
loc_82675990:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826759A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82675990
	if (cr6.lt) goto loc_82675990;
loc_826759BC:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,248
	ctx.r9.s64 = r11.s64 + 248;
	// addi r4,r10,25228
	ctx.r4.s64 = ctx.r10.s64 + 25228;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826759E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x82675a1c
	if (cr6.eq) goto loc_82675A1C;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_82675A08:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82675a08
	if (!cr6.eq) goto loc_82675A08;
loc_82675A1C:
	// subf r9,r8,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// srawi r7,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,1040(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addic. r3,r4,1
	xer.ca = ctx.r4.u32 > 4294967294;
	ctx.r3.s64 = ctx.r4.s64 + 1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble 0x82675a7c
	if (!cr0.gt) goto loc_82675A7C;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_82675A44:
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stwx r4,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r4.u32);
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x82675a44
	if (cr6.lt) goto loc_82675A44;
loc_82675A7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82675A84"))) PPC_WEAK_FUNC(sub_82675A84);
PPC_FUNC_IMPL(__imp__sub_82675A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82675A88"))) PPC_WEAK_FUNC(sub_82675A88);
PPC_FUNC_IMPL(__imp__sub_82675A88) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82675A90;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675AB4;
	sub_82653B30(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82675AB8;
	sub_82256058(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82675ed8
	if (cr6.eq) goto loc_82675ED8;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675afc
	if (cr6.eq) goto loc_82675AFC;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675AE8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675ae8
	if (!cr6.eq) goto loc_82675AE8;
loc_82675AFC:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r4,r9,27976
	ctx.r4.s64 = ctx.r9.s64 + 27976;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r24,r25,8
	r24.s64 = r25.s64 + 8;
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82675B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r27,1
	r27.s64 = 1;
	// li r10,25
	ctx.r10.s64 = 25;
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// addi r28,r11,32684
	r28.s64 = r11.s64 + 32684;
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r26,r31,1072
	r26.s64 = r31.s64 + 1072;
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r7,992(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r10,216(r11)
	PPC_STORE_U32(r11.u32 + 216, ctx.r10.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82675B98;
	sub_82137A08(ctx, base);
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82675BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82256150
	ctx.lr = 0x82675BB8;
	sub_82256150(ctx, base);
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// ori r26,r4,65535
	r26.u64 = ctx.r4.u64 | 65535;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// beq cr6,0x82675bdc
	if (cr6.eq) goto loc_82675BDC;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bge cr6,0x82675be0
	if (!cr6.lt) goto loc_82675BE0;
loc_82675BDC:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82675BE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r25,r31,1232
	r25.s64 = r31.s64 + 1232;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82137a08
	ctx.lr = 0x82675C04;
	sub_82137A08(ctx, base);
	// lwz r3,1052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1052);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8223de50
	ctx.lr = 0x82675C28;
	sub_8223DE50(ctx, base);
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r6,27964
	ctx.r4.s64 = ctx.r6.s64 + 27964;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82675C40;
	sub_822183B0(ctx, base);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,27944
	ctx.r4.s64 = ctx.r5.s64 + 27944;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,996(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// li r23,19
	r23.s64 = 19;
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,996(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,996(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r23,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r23.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r4,40(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmpw cr6,r4,r26
	cr6.compare<int32_t>(ctx.r4.s32, r26.s32, xer);
	// beq cr6,0x82675cc8
	if (cr6.eq) goto loc_82675CC8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8223de50
	ctx.lr = 0x82675CB4;
	sub_8223DE50(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r11,27932
	ctx.r4.s64 = r11.s64 + 27932;
	// b 0x82675cec
	goto loc_82675CEC;
loc_82675CC8:
	// lwz r26,-10244(r22)
	r26.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,2352
	ctx.r4.s64 = r11.s64 + 2352;
	// bl 0x82218310
	ctx.lr = 0x82675CDC;
	sub_82218310(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,27932
	ctx.r4.s64 = ctx.r10.s64 + 27932;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82675CEC:
	// bl 0x822183b0
	ctx.lr = 0x82675CF0;
	sub_822183B0(ctx, base);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,27912
	ctx.r4.s64 = r11.s64 + 27912;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82675D0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,27900
	ctx.r4.s64 = ctx.r8.s64 + 27900;
	// stb r29,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r29.u8);
	// lwz r6,1000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r29.u8);
	// lwz r5,1000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r27,212(r5)
	PPC_STORE_U32(ctx.r5.u32 + 212, r27.u32);
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r23,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r23.u32);
	// lwz r8,1000(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// li r9,26
	ctx.r9.s64 = 26;
	// addi r26,r31,1120
	r26.s64 = r31.s64 + 1120;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stb r29,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, r29.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r7,1004(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// li r4,16
	ctx.r4.s64 = 16;
	// stb r29,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r29.u8);
	// lwz r11,1004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// stw r27,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r27.u32);
	// lwz r10,1004(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// stw r9,216(r10)
	PPC_STORE_U32(ctx.r10.u32 + 216, ctx.r9.u32);
	// lwz r8,1004(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82675DC0;
	sub_82137A08(ctx, base);
	// lwz r3,1024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82675DD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,109
	ctx.r3.s64 = 109;
	// bl 0x82204a48
	ctx.lr = 0x82675DE0;
	sub_82204A48(ctx, base);
	// addi r25,r3,2192
	r25.s64 = ctx.r3.s64 + 2192;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r11,r27
	r11.u64 = r27.u64;
	// lfs f13,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,25092(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 25092);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82675e00
	if (cr6.lt) goto loc_82675E00;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82675E00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r26,r31,1238
	r26.s64 = r31.s64 + 1238;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82137a08
	ctx.lr = 0x82675E24;
	sub_82137A08(ctx, base);
	// lwz r3,1064(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1064);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82675E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f0,31016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82137a08
	ctx.lr = 0x82675E68;
	sub_82137A08(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,-10244(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10244);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r4,27888
	ctx.r4.s64 = ctx.r4.s64 + 27888;
	// bl 0x822183b0
	ctx.lr = 0x82675E7C;
	sub_822183B0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r4,r3,27868
	ctx.r4.s64 = ctx.r3.s64 + 27868;
	// lwz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675E98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,1008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// stw r23,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r23.u32);
	// lwz r4,1008(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
loc_82675ED8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82675EE0"))) PPC_WEAK_FUNC(sub_82675EE0);
PPC_FUNC_IMPL(__imp__sub_82675EE0) {
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
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// lhz r11,996(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 996);
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675f2c
	if (cr6.eq) goto loc_82675F2C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675F18:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675f18
	if (!cr6.eq) goto loc_82675F18;
loc_82675F2C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// li r7,6
	ctx.r7.s64 = 6;
	// subf r4,r9,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,4
	ctx.r5.s64 = 4;
	// sth r4,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r4.u16);
	// li r4,60
	ctx.r4.s64 = 60;
	// lwz r3,-10004(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10004);
	// bl 0x826c6738
	ctx.lr = 0x82675F58;
	sub_826C6738(ctx, base);
	// lhz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 996);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82675f78
	if (cr6.eq) goto loc_82675F78;
	// bl 0x82387a18
	ctx.lr = 0x82675F68;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,3
	ctx.r3.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82675f7c
	if (cr6.eq) goto loc_82675F7C;
loc_82675F78:
	// li r3,2
	ctx.r3.s64 = 2;
loc_82675F7C:
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

__attribute__((alias("__imp__sub_82675F90"))) PPC_WEAK_FUNC(sub_82675F90);
PPC_FUNC_IMPL(__imp__sub_82675F90) {
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
	ctx.lr = 0x82675F98;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82675FB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82653b30
	ctx.lr = 0x82675FBC;
	sub_82653B30(ctx, base);
	// lhz r8,996(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// addi r11,r29,992
	r11.s64 = r29.s64 + 992;
	// lwz r9,992(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82675ff4
	if (cr6.eq) goto loc_82675FF4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82675FE0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82675fe0
	if (!cr6.eq) goto loc_82675FE0;
loc_82675FF4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,996(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// addi r6,r29,992
	ctx.r6.s64 = r29.s64 + 992;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r7,6
	ctx.r7.s64 = 6;
	// sth r8,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r8.u16);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwz r3,-10004(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10004);
	// bl 0x826c6738
	ctx.lr = 0x82676024;
	sub_826C6738(ctx, base);
	// lhz r10,852(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r10,2
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r28,r29,848
	r28.s64 = r29.s64 + 848;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267605c
	if (cr6.eq) goto loc_8267605C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82676048:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82676048
	if (!cr6.eq) goto loc_82676048;
loc_8267605C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r3,r9,28052
	ctx.r3.s64 = ctx.r9.s64 + 28052;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r7.u16);
	// lhz r26,996(r29)
	r26.u64 = PPC_LOAD_U16(r29.u32 + 996);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// bl 0x82130000
	ctx.lr = 0x82676088;
	sub_82130000(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ble cr6,0x82676398
	if (!cr6.gt) goto loc_82676398;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x826304b0
	ctx.lr = 0x8267609C;
	sub_826304B0(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r30,r24
	r30.u64 = r24.u64;
	// mr r14,r24
	r14.u64 = r24.u64;
	// ble cr6,0x826763b4
	if (!cr6.gt) goto loc_826763B4;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r8,r8,24804
	ctx.r8.s64 = ctx.r8.s64 + 24804;
	// addi r7,r7,14248
	ctx.r7.s64 = ctx.r7.s64 + 14248;
	// li r21,1
	r21.s64 = 1;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r17,-32121
	r17.s64 = -2105081856;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// addi r18,r11,28020
	r18.s64 = r11.s64 + 28020;
	// addi r16,r10,32684
	r16.s64 = ctx.r10.s64 + 32684;
	// addi r15,r9,27988
	r15.s64 = ctx.r9.s64 + 27988;
loc_826760EC:
	// lwz r10,992(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// addi r11,r29,992
	r11.s64 = r29.s64 + 992;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwzx r20,r10,r9
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r8,656(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpwi cr6,r7,5
	cr6.compare<int32_t>(ctx.r7.s32, 5, xer);
	// beq cr6,0x82676114
	if (cr6.eq) goto loc_82676114;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x826c7370
	ctx.lr = 0x82676114;
	sub_826C7370(ctx, base);
loc_82676114:
	// lwz r11,656(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x8267612c
	if (cr6.eq) goto loc_8267612C;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8267612C:
	// addi r31,r20,200
	r31.s64 = r20.s64 + 200;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x82130000
	ctx.lr = 0x82676140;
	sub_82130000(ctx, base);
	// addi r11,r30,250
	r11.s64 = r30.s64 + 250;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82676160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r7,r31,r29
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r8,18
	ctx.r8.s64 = 18;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// stb r24,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r24.u8);
	// addi r27,r11,1256
	r27.s64 = r11.s64 + 1256;
	// lwzx r6,r31,r29
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// stb r24,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r24.u8);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r11,r31,r29
	r11.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stw r21,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r21.u32);
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stw r8,216(r10)
	PPC_STORE_U32(ctx.r10.u32 + 216, ctx.r8.u32);
	// lwzx r9,r31,r29
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// stb r21,210(r9)
	PPC_STORE_U8(ctx.r9.u32 + 210, r21.u8);
	// lwzx r8,r31,r29
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r7,4(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r6.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lhz r19,720(r20)
	r19.u64 = PPC_LOAD_U16(r20.u32 + 720);
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x826761D0;
	sub_82137A08(ctx, base);
	// addi r8,r30,266
	ctx.r8.s64 = r30.s64 + 266;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826761F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,656(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 656);
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r30,692
	r11.s64 = r30.s64 + 692;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r9,49
	ctx.r9.s64 = 49;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// stb r24,1385(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1385, r24.u8);
	// beq cr6,0x82676220
	if (cr6.eq) goto loc_82676220;
	// li r9,48
	ctx.r9.s64 = 48;
loc_82676220:
	// stbx r9,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r9.u8);
	// addi r11,r30,274
	r11.s64 = r30.s64 + 274;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82676240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
	// mr r22,r24
	r22.u64 = r24.u64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x82676370
	if (!cr6.gt) goto loc_82676370;
	// addi r9,r30,250
	ctx.r9.s64 = r30.s64 + 250;
	// rlwinm r11,r30,5,0,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r7,r30,692
	ctx.r7.s64 = r30.s64 + 692;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// add r31,r8,r29
	r31.u64 = ctx.r8.u64 + r29.u64;
	// addi r27,r11,1400
	r27.s64 = r11.s64 + 1400;
	// add r25,r9,r29
	r25.u64 = ctx.r9.u64 + r29.u64;
	// addi r26,r10,1256
	r26.s64 = ctx.r10.s64 + 1256;
loc_82676288:
	// stb r24,-128(r26)
	PPC_STORE_U8(r26.u32 + -128, r24.u8);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r24,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r24.u8);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// stb r24,0(r25)
	PPC_STORE_U8(r25.u32 + 0, r24.u8);
	// bl 0x826c72a0
	ctx.lr = 0x826762A0;
	sub_826C72A0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82676360
	if (cr6.eq) goto loc_82676360;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826cc350
	ctx.lr = 0x826762B8;
	sub_826CC350(ctx, base);
	// lbz r11,116(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 116);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826762cc
	if (!cr6.eq) goto loc_826762CC;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826762CC:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x826762DC;
	sub_82130000(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10244(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826762EC;
	sub_822183B0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,116(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 116);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
	// addi r27,r27,32
	r27.s64 = r27.s64 + 32;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// stb r8,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, ctx.r8.u8);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r21,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r21.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r21,212(r6)
	PPC_STORE_U32(ctx.r6.u32 + 212, r21.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r24,210(r5)
	PPC_STORE_U8(ctx.r5.u32 + 210, r24.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// sth r9,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r9.u16);
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
loc_82676360:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpw cr6,r22,r19
	cr6.compare<int32_t>(r22.s32, r19.s32, xer);
	// blt cr6,0x82676288
	if (cr6.lt) goto loc_82676288;
	// lwz r26,92(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82676370:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x826763b4
	if (!cr6.lt) goto loc_826763B4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// cmpw cr6,r14,r26
	cr6.compare<int32_t>(r14.s32, r26.s32, xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// blt cr6,0x826760ec
	if (cr6.lt) goto loc_826760EC;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9210
	return;
loc_82676398:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826304b0
	ctx.lr = 0x826763A0;
	sub_826304B0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826763B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826763B4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_826763BC"))) PPC_WEAK_FUNC(sub_826763BC);
PPC_FUNC_IMPL(__imp__sub_826763BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826763C0"))) PPC_WEAK_FUNC(sub_826763C0);
PPC_FUNC_IMPL(__imp__sub_826763C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,1032(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1032);
	// addi r9,r3,992
	ctx.r9.s64 = ctx.r3.s64 + 992;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826763f4
	if (cr6.eq) goto loc_826763F4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826763E0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826763e0
	if (!cr6.eq) goto loc_826763E0;
loc_826763F4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r10,40(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r11,0
	r11.s64 = 0;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r6.u32);
	// stfs f0,3664(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 3664, temp.u32);
	// stw r11,3672(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3672, r11.u32);
	// stw r11,3680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3680, r11.u32);
	// stw r11,3676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3676, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82676428"))) PPC_WEAK_FUNC(sub_82676428);
PPC_FUNC_IMPL(__imp__sub_82676428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,852(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 852);
	// addi r10,r3,848
	ctx.r10.s64 = ctx.r3.s64 + 848;
	// lwz r8,848(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82676460
	if (cr6.eq) goto loc_82676460;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_8267644C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x8267644c
	if (!cr6.eq) goto loc_8267644C;
loc_82676460:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// lwz r4,3672(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x826764d4
	if (!cr6.gt) goto loc_826764D4;
	// addi r11,r3,992
	r11.s64 = ctx.r3.s64 + 992;
	// addi r6,r3,1268
	ctx.r6.s64 = ctx.r3.s64 + 1268;
loc_8267648C:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,3676(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3676);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x826764bc
	if (!cr6.eq) goto loc_826764BC;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
loc_826764BC:
	// lwz r9,3672(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3672);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r6,r6,240
	ctx.r6.s64 = ctx.r6.s64 + 240;
	// cmpw cr6,r5,r9
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, xer);
	// blt cr6,0x8267648c
	if (cr6.lt) goto loc_8267648C;
loc_826764D4:
	// lwz r11,3676(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3676);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3676, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826764E4"))) PPC_WEAK_FUNC(sub_826764E4);
PPC_FUNC_IMPL(__imp__sub_826764E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826764E8"))) PPC_WEAK_FUNC(sub_826764E8);
PPC_FUNC_IMPL(__imp__sub_826764E8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267654c
	if (!cr6.eq) goto loc_8267654C;
	// lwz r11,3676(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3676);
	// lwz r10,3680(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bge cr6,0x82676534
	if (!cr6.lt) goto loc_82676534;
	// bl 0x821e6800
	ctx.lr = 0x82676520;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82676428
	ctx.lr = 0x82676528;
	sub_82676428(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// b 0x82676540
	goto loc_82676540;
loc_82676534:
	// bl 0x821e6800
	ctx.lr = 0x82676538;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
loc_82676540:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267654C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267654C:
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

__attribute__((alias("__imp__sub_82676564"))) PPC_WEAK_FUNC(sub_82676564);
PPC_FUNC_IMPL(__imp__sub_82676564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676568"))) PPC_WEAK_FUNC(sub_82676568);
PPC_FUNC_IMPL(__imp__sub_82676568) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826765A0;
	sub_82654318(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,28740
	ctx.r8.s64 = ctx.r9.s64 + 28740;
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
}

__attribute__((alias("__imp__sub_826765C4"))) PPC_WEAK_FUNC(sub_826765C4);
PPC_FUNC_IMPL(__imp__sub_826765C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826765C8"))) PPC_WEAK_FUNC(sub_826765C8);
PPC_FUNC_IMPL(__imp__sub_826765C8) {
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
	ctx.lr = 0x826765D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,992
	r31.s64 = r29.s64 + 992;
	// addi r10,r11,29548
	ctx.r10.s64 = r11.s64 + 29548;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826765EC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267660c
	if (cr6.eq) goto loc_8267660C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267660C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267660C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826765ec
	if (!cr0.eq) goto loc_826765EC;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r29,1040
	r11.s64 = r29.s64 + 1040;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_82676628:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x82676628
	if (!cr0.lt) goto loc_82676628;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676650
	if (cr6.eq) goto loc_82676650;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676650;
	sub_82130588(ctx, base);
loc_82676650:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676664
	if (cr6.eq) goto loc_82676664;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82676664;
	sub_82130588(ctx, base);
loc_82676664:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267666C;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82676674;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267667C;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676684;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267668C"))) PPC_WEAK_FUNC(sub_8267668C);
PPC_FUNC_IMPL(__imp__sub_8267668C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676690"))) PPC_WEAK_FUNC(sub_82676690);
PPC_FUNC_IMPL(__imp__sub_82676690) {
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
	ctx.lr = 0x82676698;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,1012
	r31.s64 = r29.s64 + 1012;
	// addi r10,r11,30356
	ctx.r10.s64 = r11.s64 + 30356;
	// li r30,5
	r30.s64 = 5;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826766B4:
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826766d4
	if (cr6.eq) goto loc_826766D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826766D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826766D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826766f4
	if (cr6.eq) goto loc_826766F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826766F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826766F4:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676714
	if (cr6.eq) goto loc_82676714;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676714:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676734
	if (cr6.eq) goto loc_82676734;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676734:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826766b4
	if (!cr0.eq) goto loc_826766B4;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676758
	if (cr6.eq) goto loc_82676758;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676758;
	sub_82130588(ctx, base);
loc_82676758:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267676c
	if (cr6.eq) goto loc_8267676C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267676C;
	sub_82130588(ctx, base);
loc_8267676C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676774;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267677C;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82676784;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267678C;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82676794"))) PPC_WEAK_FUNC(sub_82676794);
PPC_FUNC_IMPL(__imp__sub_82676794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676798"))) PPC_WEAK_FUNC(sub_82676798);
PPC_FUNC_IMPL(__imp__sub_82676798) {
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
	ctx.lr = 0x826767A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,1032
	r31.s64 = r29.s64 + 1032;
	// addi r10,r11,31164
	ctx.r10.s64 = r11.s64 + 31164;
	// li r30,10
	r30.s64 = 10;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826767BC:
	// lwz r3,-40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826767dc
	if (cr6.eq) goto loc_826767DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826767DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826767DC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826767fc
	if (cr6.eq) goto loc_826767FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826767FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826767FC:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267681c
	if (cr6.eq) goto loc_8267681C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267681C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267681C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267683c
	if (cr6.eq) goto loc_8267683C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267683C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267683C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826767bc
	if (!cr0.eq) goto loc_826767BC;
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676860
	if (cr6.eq) goto loc_82676860;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82676860;
	sub_82130588(ctx, base);
loc_82676860:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676874
	if (cr6.eq) goto loc_82676874;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82676874;
	sub_82130588(ctx, base);
loc_82676874:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267687C;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82676884;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267688C;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676894;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267689C"))) PPC_WEAK_FUNC(sub_8267689C);
PPC_FUNC_IMPL(__imp__sub_8267689C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826768A0"))) PPC_WEAK_FUNC(sub_826768A0);
PPC_FUNC_IMPL(__imp__sub_826768A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r10,r11,31972
	ctx.r10.s64 = r11.s64 + 31972;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8221fcc8
	sub_8221FCC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826768B0"))) PPC_WEAK_FUNC(sub_826768B0);
PPC_FUNC_IMPL(__imp__sub_826768B0) {
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
	ctx.lr = 0x826768B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r29,1032
	r31.s64 = r29.s64 + 1032;
	// addi r10,r11,-32756
	ctx.r10.s64 = r11.s64 + -32756;
	// li r30,8
	r30.s64 = 8;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826768D4:
	// lwz r3,-32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826768f4
	if (cr6.eq) goto loc_826768F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826768F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826768F4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676914
	if (cr6.eq) goto loc_82676914;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676914:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676934
	if (cr6.eq) goto loc_82676934;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676934:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676954
	if (cr6.eq) goto loc_82676954;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82676954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82676954:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826768d4
	if (!cr0.eq) goto loc_826768D4;
	// lhz r11,998(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 998);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676974
	if (cr6.eq) goto loc_82676974;
	// lwz r3,992(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// bl 0x82130588
	ctx.lr = 0x82676974;
	sub_82130588(ctx, base);
loc_82676974:
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267698c
	if (cr6.eq) goto loc_8267698C;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267698C;
	sub_82130588(ctx, base);
loc_8267698C:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826769a0
	if (cr6.eq) goto loc_826769A0;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826769A0;
	sub_82130588(ctx, base);
loc_826769A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826769A8;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x826769B0;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x826769B8;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x826769C0;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826769C8"))) PPC_WEAK_FUNC(sub_826769C8);
PPC_FUNC_IMPL(__imp__sub_826769C8) {
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
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826543a0
	ctx.lr = 0x82676A08;
	sub_826543A0(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r6,r8,-31948
	ctx.r6.s64 = ctx.r8.s64 + -31948;
	// addi r5,r7,-4092
	ctx.r5.s64 = ctx.r7.s64 + -4092;
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r5,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r5.u32);
	// sth r4,1002(r31)
	PPC_STORE_U16(r31.u32 + 1002, ctx.r4.u16);
	// li r3,64
	ctx.r3.s64 = 64;
	// sth r30,1000(r31)
	PPC_STORE_U16(r31.u32 + 1000, r30.u16);
	// addi r11,r31,992
	r11.s64 = r31.s64 + 992;
	// bl 0x82130528
	ctx.lr = 0x82676A3C;
	sub_82130528(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// addi r9,r11,6560
	ctx.r9.s64 = r11.s64 + 6560;
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// stw r10,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82676A74"))) PPC_WEAK_FUNC(sub_82676A74);
PPC_FUNC_IMPL(__imp__sub_82676A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82676A78"))) PPC_WEAK_FUNC(sub_82676A78);
PPC_FUNC_IMPL(__imp__sub_82676A78) {
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
	ctx.lr = 0x82676A80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-31140
	ctx.r9.s64 = r11.s64 + -31140;
	// li r4,17
	ctx.r4.s64 = 17;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x82676AA8;
	sub_82213650(ctx, base);
	// lhz r8,3634(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 3634);
	// addi r31,r29,3440
	r31.s64 = r29.s64 + 3440;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82676ac0
	if (cr6.eq) goto loc_82676AC0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82676AC0;
	sub_82130588(ctx, base);
loc_82676AC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676AC8;
	sub_82633B00(ctx, base);
	// addi r31,r29,3440
	r31.s64 = r29.s64 + 3440;
	// li r30,9
	r30.s64 = 9;
loc_82676AD0:
	// addi r31,r31,-240
	r31.s64 = r31.s64 + -240;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676ae8
	if (cr6.eq) goto loc_82676AE8;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82676AE8;
	sub_82130588(ctx, base);
loc_82676AE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82676AF0;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82676ad0
	if (!cr0.lt) goto loc_82676AD0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82676B00;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82676B08"))) PPC_WEAK_FUNC(sub_82676B08);
PPC_FUNC_IMPL(__imp__sub_82676B08) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82676B10;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82676B1C;
	sub_82653B30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r16,0
	r16.s64 = 0;
	// li r18,-1
	r18.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826763c0
	ctx.lr = 0x82676B30;
	sub_826763C0(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x82676B40;
	sub_826B95B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// lwz r26,8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82676B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r8,3688(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3688);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r22,r11,-14284
	r22.s64 = r11.s64 + -14284;
	// lwz r23,304(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// subf. r11,r8,r26
	r11.s64 = r26.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r21,12
	r21.s64 = 12;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r17,r10,32684
	r17.s64 = ctx.r10.s64 + 32684;
	// beq 0x82676e2c
	if (cr0.eq) goto loc_82676E2C;
	// lis r10,15258
	ctx.r10.s64 = 999948288;
	// ori r30,r10,51711
	r30.u64 = ctx.r10.u64 | 51711;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// blt cr6,0x82676b98
	if (cr6.lt) goto loc_82676B98;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82676B98:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82676BA8;
	sub_823DC018(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r4,r11,-30196
	ctx.r4.s64 = r11.s64 + -30196;
	// bl 0x822183b0
	ctx.lr = 0x82676BBC;
	sub_822183B0(ctx, base);
	// cmpw cr6,r26,r30
	cr6.compare<int32_t>(r26.s32, r30.s32, xer);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// blt cr6,0x82676bcc
	if (cr6.lt) goto loc_82676BCC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_82676BCC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r25,r11,26932
	r25.s64 = r11.s64 + 26932;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823dc018
	ctx.lr = 0x82676BE0;
	sub_823DC018(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r4,r11,26908
	ctx.r4.s64 = r11.s64 + 26908;
	// bl 0x822183b0
	ctx.lr = 0x82676BF4;
	sub_822183B0(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r10,-30208
	ctx.r4.s64 = ctx.r10.s64 + -30208;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676C08;
	sub_827205A8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// bl 0x826b92c8
	ctx.lr = 0x82676C14;
	sub_826B92C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// blt cr6,0x82676c28
	if (cr6.lt) goto loc_82676C28;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_82676C28:
	// addi r10,r11,38
	ctx.r10.s64 = r11.s64 + 38;
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// rlwinm r24,r10,2,0,29
	r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f0,r24,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dc018
	ctx.lr = 0x82676C50;
	sub_823DC018(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r9,26884
	ctx.r4.s64 = ctx.r9.s64 + 26884;
	// bl 0x822183b0
	ctx.lr = 0x82676C64;
	sub_822183B0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-26544
	ctx.r6.s64 = ctx.r8.s64 + -26544;
	// lwzx r4,r7,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r25,-10244(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82218310
	ctx.lr = 0x82676C80;
	sub_82218310(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-14244
	ctx.r4.s64 = ctx.r4.s64 + -14244;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822183b0
	ctx.lr = 0x82676C94;
	sub_822183B0(ctx, base);
	// cmpwi cr6,r30,12
	cr6.compare<int32_t>(r30.s32, 12, xer);
	// bne cr6,0x82676cc8
	if (!cr6.eq) goto loc_82676CC8;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r26,100
	r26.s64 = 100;
	// addi r4,r11,-14304
	ctx.r4.s64 = r11.s64 + -14304;
	// bl 0x82218310
	ctx.lr = 0x82676CB0;
	sub_82218310(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,-14348
	ctx.r4.s64 = ctx.r10.s64 + -14348;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82720588
	ctx.lr = 0x82676CC4;
	sub_82720588(ctx, base);
	// b 0x82676d30
	goto loc_82676D30;
loc_82676CC8:
	// extsw r10,r26
	ctx.r10.s64 = r26.s32;
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// addi r9,r30,38
	ctx.r9.s64 = r30.s64 + 38;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfsx f11,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// fctiwz f8,f11
	ctx.f8.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r4,r6,-14348
	ctx.r4.s64 = ctx.r6.s64 + -14348;
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fsubs f7,f12,f10
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fdivs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f9.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r26,84(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827205a8
	ctx.lr = 0x82676D30;
	sub_827205A8(ctx, base);
loc_82676D30:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r11,-30220
	ctx.r4.s64 = r11.s64 + -30220;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676D44;
	sub_827205A8(ctx, base);
	// lwz r3,18508(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// lwz r4,3688(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3688);
	// bl 0x826b92c8
	ctx.lr = 0x82676D50;
	sub_826B92C8(ctx, base);
	// subf r10,r30,r3
	ctx.r10.s64 = ctx.r3.s64 - r30.s64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x82676D70;
	sub_82137A08(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82676D80;
	sub_822183B0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r30,-10244(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82676D90;
	sub_82218310(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,26828
	ctx.r4.s64 = ctx.r7.s64 + 26828;
	// bl 0x82218310
	ctx.lr = 0x82676DA4;
	sub_82218310(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,26856
	ctx.r4.s64 = ctx.r6.s64 + 26856;
	// bl 0x82218310
	ctx.lr = 0x82676DB8;
	sub_82218310(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r4,r5,26936
	ctx.r4.s64 = ctx.r5.s64 + 26936;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82676DCC;
	sub_82218310(ctx, base);
	// lwz r4,3672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r7,11
	ctx.r7.s64 = 11;
	// mulli r11,r4,240
	r11.s64 = ctx.r4.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r7,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r7.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r24,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r24.u32);
	// stw r25,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r25.u32);
	// stw r26,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r26.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r6,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r6.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r5,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r5.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82676E2C:
	// li r26,0
	r26.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x82676E34;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82676e4c
	if (cr6.eq) goto loc_82676E4C;
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x82676e4c
	if (!cr6.eq) goto loc_82676E4C;
	// li r26,1
	r26.s64 = 1;
loc_82676E4C:
	// lwz r11,18508(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 18508);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,3684(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3684);
	// addi r30,r10,3998
	r30.s64 = ctx.r10.s64 + 3998;
	// lwz r27,508(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// subf. r5,r9,r27
	ctx.r5.s64 = r27.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x82676e74
	if (!cr0.eq) goto loc_82676E74;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82676f58
	if (cr6.eq) goto loc_82676F58;
loc_82676E74:
	// clrlwi r26,r26,24
	r26.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82676e94
	if (!cr6.eq) goto loc_82676E94;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-30240
	ctx.r4.s64 = r11.s64 + -30240;
	// bl 0x82218788
	ctx.lr = 0x82676E94;
	sub_82218788(ctx, base);
loc_82676E94:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-30256
	ctx.r4.s64 = r11.s64 + -30256;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82218788
	ctx.lr = 0x82676EAC;
	sub_82218788(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r10,-30272
	ctx.r4.s64 = ctx.r10.s64 + -30272;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827205a8
	ctx.lr = 0x82676EC0;
	sub_827205A8(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82676ed4
	if (!cr6.eq) goto loc_82676ED4;
	// lwz r11,3684(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3684);
	// subf. r10,r11,r27
	ctx.r10.s64 = r27.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82676f58
	if (!cr0.gt) goto loc_82676F58;
loc_82676ED4:
	// lwz r27,-10244(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,26960
	ctx.r4.s64 = r11.s64 + 26960;
	// bl 0x82218310
	ctx.lr = 0x82676EE8;
	sub_82218310(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r10,26984
	ctx.r4.s64 = ctx.r10.s64 + 26984;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x82676EFC;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r21,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r21.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r26,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r26.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82676F58:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,796(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 796);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82676fc4
	if (cr6.eq) goto loc_82676FC4;
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r31,3440
	ctx.r7.s64 = r31.s64 + 3440;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r6,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r6.u32);
	// stw r21,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r21.u32);
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r30,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, r30.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r5.u32);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
loc_82676FC4:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82676fe0
	if (cr6.eq) goto loc_82676FE0;
	// mr r16,r11
	r16.u64 = r11.u64;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82676FE0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// li r21,0
	r21.s64 = 0;
	// lwz r27,18504(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826770e4
	if (cr6.eq) goto loc_826770E4;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r25,0
	r25.s64 = 0;
	// li r23,14
	r23.s64 = 14;
	// addi r24,r11,-30296
	r24.s64 = r11.s64 + -30296;
loc_8267700C:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x826770e4
	if (cr6.gt) goto loc_826770E4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bne cr6,0x826770d0
	if (!cr6.eq) goto loc_826770D0;
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// addi r5,r10,92
	ctx.r5.s64 = ctx.r10.s64 + 92;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8267703C;
	sub_82213B80(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// bl 0x82218310
	ctx.lr = 0x82677054;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x822183b0
	ctx.lr = 0x82677064;
	sub_822183B0(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82677070;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r23,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r23.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_826770D0:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x8267700c
	if (cr6.lt) goto loc_8267700C;
loc_826770E4:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x82677104
	if (cr6.eq) goto loc_82677104;
	// mr r16,r11
	r16.u64 = r11.u64;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82677104:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r24,19
	r24.s64 = 19;
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r21,r11,-14748
	r21.s64 = r11.s64 + -14748;
	// beq cr6,0x82677314
	if (cr6.eq) goto loc_82677314;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r25,0
	r25.s64 = 0;
	// addi r22,r11,25056
	r22.s64 = r11.s64 + 25056;
	// addi r20,r10,30804
	r20.s64 = ctx.r10.s64 + 30804;
loc_82677134:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x82677314
	if (cr6.gt) goto loc_82677314;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r10,9
	cr6.compare<int32_t>(ctx.r10.s32, 9, xer);
	// bne cr6,0x8267719c
	if (!cr6.eq) goto loc_8267719C;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x8267718c
	if (!cr6.eq) goto loc_8267718C;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r9,r31,992
	ctx.r9.s64 = r31.s64 + 992;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mulli r8,r11,240
	ctx.r8.s64 = r11.s64 * 240;
	// stw r10,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r10.u32);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r10,r8,1040
	ctx.r10.s64 = ctx.r8.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// stwx r10,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r10.u32);
loc_8267718C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// b 0x82677298
	goto loc_82677298;
loc_8267719C:
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x82677214
	if (!cr6.eq) goto loc_82677214;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// lwzx r3,r25,r11
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826771BC;
	sub_823DEDD8(ctx, base);
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82677300
	if (cr6.eq) goto loc_82677300;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677204
	if (!cr6.eq) goto loc_82677204;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r8,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r8.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r9,r9,1040
	ctx.r9.s64 = ctx.r9.s64 + 1040;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r7.u32);
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82677204:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// b 0x82677298
	goto loc_82677298;
loc_82677214:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82677300
	if (!cr6.eq) goto loc_82677300;
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677258
	if (!cr6.eq) goto loc_82677258;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r8,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r8.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r9,r9,1040
	ctx.r9.s64 = ctx.r9.s64 + 1040;
	// stw r7,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r7.u32);
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82677258:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8267726C;
	sub_82137A08(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// lwzx r11,r25,r11
	r11.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// bl 0x82218310
	ctx.lr = 0x82677284;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x822183b0
	ctx.lr = 0x82677294;
	sub_822183B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
loc_82677298:
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826772A0;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r24,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r24.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_82677300:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82677134
	if (cr6.lt) goto loc_82677134;
loc_82677314:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x826773b0
	if (cr6.eq) goto loc_826773B0;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82677334;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r26,r11,25364
	r26.s64 = r11.s64 + 25364;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822183b0
	ctx.lr = 0x8267734C;
	sub_822183B0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x8267735C;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r10,-30316
	ctx.r4.s64 = ctx.r10.s64 + -30316;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x82677370;
	sub_82218310(ctx, base);
	// mulli r11,r18,240
	r11.s64 = r18.s64 * 240;
	// lwz r9,3680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r8,17
	ctx.r8.s64 = 17;
	// addi r10,r11,1040
	ctx.r10.s64 = r11.s64 + 1040;
	// li r18,-1
	r18.s64 = -1;
	// stw r8,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r8.u32);
	// stw r25,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r25.u32);
	// stw r9,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r9.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r16,3672(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// stw r7,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r7.u32);
loc_826773B0:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// li r22,0
	r22.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826773ec
	if (!cr6.gt) goto loc_826773EC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_826773C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r9,10
	cr6.compare<int32_t>(ctx.r9.s32, 10, xer);
	// beq cr6,0x826773dc
	if (cr6.eq) goto loc_826773DC;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x826773e0
	if (!cr6.eq) goto loc_826773E0;
loc_826773DC:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
loc_826773E0:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826773c4
	if (!cr0.eq) goto loc_826773C4;
loc_826773EC:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82677414
	if (cr6.eq) goto loc_82677414;
	// add r11,r22,r28
	r11.u64 = r22.u64 + r28.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// ble cr6,0x82677414
	if (!cr6.gt) goto loc_82677414;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, r11.u32);
loc_82677414:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677560
	if (cr6.eq) goto loc_82677560;
	// li r25,0
	r25.s64 = 0;
loc_82677428:
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// bgt cr6,0x82677560
	if (cr6.gt) goto loc_82677560;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8267744c
	if (cr6.eq) goto loc_8267744C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8267754c
	if (!cr6.eq) goto loc_8267754C;
loc_8267744C:
	// cmpwi cr6,r18,-1
	cr6.compare<int32_t>(r18.s32, -1, xer);
	// bne cr6,0x82677488
	if (!cr6.eq) goto loc_82677488;
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r9,r31,992
	ctx.r9.s64 = r31.s64 + 992;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mulli r8,r11,240
	ctx.r8.s64 = r11.s64 * 240;
	// stw r10,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r10.u32);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r10,r8,1040
	ctx.r10.s64 = ctx.r8.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// mr r18,r11
	r18.u64 = r11.u64;
	// stwx r10,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r10.u32);
loc_82677488:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8267749C;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// addi r5,r10,92
	ctx.r5.s64 = ctx.r10.s64 + 92;
	// bl 0x82213b80
	ctx.lr = 0x826774B8;
	sub_82213B80(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r25,r10
	r11.u64 = PPC_LOAD_U32(r25.u32 + ctx.r10.u32);
	// addi r4,r11,10
	ctx.r4.s64 = r11.s64 + 10;
	// lwz r26,-10244(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218310
	ctx.lr = 0x826774D0;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x822183b0
	ctx.lr = 0x826774E0;
	sub_822183B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826774EC;
	sub_82218310(ctx, base);
	// lwz r9,3672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// lwz r8,3680(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r10,r31,992
	ctx.r10.s64 = r31.s64 + 992;
	// mulli r11,r9,240
	r11.s64 = ctx.r9.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r24,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, r24.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r8,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r8.u32);
	// stw r30,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r30.u32);
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mulli r9,r11,240
	ctx.r9.s64 = r11.s64 * 240;
	// stw r7,3672(r31)
	PPC_STORE_U32(r31.u32 + 3672, ctx.r7.u32);
	// lwz r11,1032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,1040
	r11.s64 = ctx.r9.s64 + 1040;
	// stw r6,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r6.u32);
	// stwx r11,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r11.u32);
loc_8267754C:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x82677428
	if (cr6.lt) goto loc_82677428;
loc_82677560:
	// lwz r11,3672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3672);
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// beq cr6,0x826775f4
	if (cr6.eq) goto loc_826775F4;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82677580;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// addi r28,r11,25328
	r28.s64 = r11.s64 + 25328;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822183b0
	ctx.lr = 0x82677598;
	sub_822183B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r29,-10244(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826775A8;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-30336
	ctx.r4.s64 = ctx.r10.s64 + -30336;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826775BC;
	sub_82218310(ctx, base);
	// mulli r11,r18,240
	r11.s64 = r18.s64 * 240;
	// lwz r9,3680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r8,13
	ctx.r8.s64 = 13;
	// addi r10,r11,1040
	ctx.r10.s64 = r11.s64 + 1040;
	// stw r30,1256(r11)
	PPC_STORE_U32(r11.u32 + 1256, r30.u32);
	// stw r30,1260(r11)
	PPC_STORE_U32(r11.u32 + 1260, r30.u32);
	// stw r9,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r9.u32);
	// stw r3,1248(r11)
	PPC_STORE_U32(r11.u32 + 1248, ctx.r3.u32);
	// stw r28,1252(r11)
	PPC_STORE_U32(r11.u32 + 1252, r28.u32);
	// stw r8,1264(r11)
	PPC_STORE_U32(r11.u32 + 1264, ctx.r8.u32);
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r7.u32);
loc_826775F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82676428
	ctx.lr = 0x826775FC;
	sub_82676428(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82677604"))) PPC_WEAK_FUNC(sub_82677604);
PPC_FUNC_IMPL(__imp__sub_82677604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677608"))) PPC_WEAK_FUNC(sub_82677608);
PPC_FUNC_IMPL(__imp__sub_82677608) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x82677634;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-30172
	ctx.r8.s64 = ctx.r9.s64 + -30172;
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
}

__attribute__((alias("__imp__sub_82677658"))) PPC_WEAK_FUNC(sub_82677658);
PPC_FUNC_IMPL(__imp__sub_82677658) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,5700
	ctx.r4.s64 = ctx.r10.s64 + 5700;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x82677684;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-29340
	ctx.r8.s64 = ctx.r9.s64 + -29340;
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
}

__attribute__((alias("__imp__sub_826776A8"))) PPC_WEAK_FUNC(sub_826776A8);
PPC_FUNC_IMPL(__imp__sub_826776A8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,28644
	ctx.r5.s64 = r11.s64 + 28644;
	// addi r4,r10,5616
	ctx.r4.s64 = ctx.r10.s64 + 5616;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826544e0
	ctx.lr = 0x826776D4;
	sub_826544E0(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-28524
	ctx.r8.s64 = ctx.r9.s64 + -28524;
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
}

__attribute__((alias("__imp__sub_826776F8"))) PPC_WEAK_FUNC(sub_826776F8);
PPC_FUNC_IMPL(__imp__sub_826776F8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26892
	ctx.r4.s64 = ctx.r9.s64 + -26892;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26904
	ctx.r5.s64 = ctx.r10.s64 + -26904;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// bl 0x826543a0
	ctx.lr = 0x82677738;
	sub_826543A0(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// addi r5,r8,-27708
	ctx.r5.s64 = ctx.r8.s64 + -27708;
	// li r11,2
	r11.s64 = 2;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r6,30356
	ctx.r3.s64 = ctx.r6.s64 + 30356;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r10,30348
	ctx.r4.s64 = ctx.r10.s64 + 30348;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x826347f0
	ctx.lr = 0x82677780;
	sub_826347F0(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826777B4"))) PPC_WEAK_FUNC(sub_826777B4);
PPC_FUNC_IMPL(__imp__sub_826777B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826777B8"))) PPC_WEAK_FUNC(sub_826777B8);
PPC_FUNC_IMPL(__imp__sub_826777B8) {
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
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x821d2028
	ctx.lr = 0x826777DC;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826777E4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826777fc
	if (cr6.eq) goto loc_826777FC;
	// bl 0x82130588
	ctx.lr = 0x826777F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826777FC:
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

__attribute__((alias("__imp__sub_82677814"))) PPC_WEAK_FUNC(sub_82677814);
PPC_FUNC_IMPL(__imp__sub_82677814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677818"))) PPC_WEAK_FUNC(sub_82677818);
PPC_FUNC_IMPL(__imp__sub_82677818) {
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
	ctx.lr = 0x82677820;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26864
	ctx.r4.s64 = ctx.r9.s64 + -26864;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26876
	ctx.r5.s64 = ctx.r10.s64 + -26876;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677850;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r29,r27,1008
	r29.s64 = r27.s64 + 1008;
	// addi r7,r8,29548
	ctx.r7.s64 = ctx.r8.s64 + 29548;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// mr r31,r29
	r31.u64 = r29.u64;
	// li r30,3
	r30.s64 = 3;
	// addi r28,r11,5568
	r28.s64 = r11.s64 + 5568;
	// addi r26,r10,3998
	r26.s64 = ctx.r10.s64 + 3998;
loc_82677878:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677888;
	sub_826311F8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bge 0x82677878
	if (!cr0.lt) goto loc_82677878;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// stw r11,1040(r27)
	PPC_STORE_U32(r27.u32 + 1040, r11.u32);
	// addi r31,r27,672
	r31.s64 = r27.s64 + 672;
	// addi r4,r10,30348
	ctx.r4.s64 = ctx.r10.s64 + 30348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x826347f0
	ctx.lr = 0x826778B4;
	sub_826347F0(ctx, base);
	// lwz r9,672(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 672);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826778CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r27,992
	r30.s64 = r27.s64 + 992;
	// li r31,4
	r31.s64 = 4;
loc_826778D4:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826778DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826778f4
	if (cr6.eq) goto loc_826778F4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x826778F0;
	sub_82633D40(ctx, base);
	// b 0x826778f8
	goto loc_826778F8;
loc_826778F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826778F8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r10,r3,188
	ctx.r10.s64 = ctx.r3.s64 + 188;
	// lwz r10,188(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lhz r11,192(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 192);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// sth r8,192(r3)
	PPC_STORE_U16(ctx.r3.u32 + 192, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x826778d4
	if (!cr0.eq) goto loc_826778D4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82677934"))) PPC_WEAK_FUNC(sub_82677934);
PPC_FUNC_IMPL(__imp__sub_82677934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677938"))) PPC_WEAK_FUNC(sub_82677938);
PPC_FUNC_IMPL(__imp__sub_82677938) {
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
	// bl 0x826765c8
	ctx.lr = 0x82677958;
	sub_826765C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677970
	if (cr6.eq) goto loc_82677970;
	// bl 0x82130588
	ctx.lr = 0x8267796C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677970:
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

__attribute__((alias("__imp__sub_82677988"))) PPC_WEAK_FUNC(sub_82677988);
PPC_FUNC_IMPL(__imp__sub_82677988) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82677990;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26824
	ctx.r4.s64 = ctx.r9.s64 + -26824;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26848
	ctx.r5.s64 = ctx.r10.s64 + -26848;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826779C0;
	sub_82654318(ctx, base);
	// lwz r6,496(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 496);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r24,496
	ctx.r3.s64 = r24.s64 + 496;
	// addi r7,r8,30356
	ctx.r7.s64 = ctx.r8.s64 + 30356;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// stw r7,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826779E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r31,r24,672
	r31.s64 = r24.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,30276
	ctx.r4.s64 = ctx.r9.s64 + 30276;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826347f0
	ctx.lr = 0x82677A14;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r27,r24,1232
	r27.s64 = r24.s64 + 1232;
	// addi r30,r24,1152
	r30.s64 = r24.s64 + 1152;
	// addi r31,r24,1012
	r31.s64 = r24.s64 + 1012;
	// li r26,5
	r26.s64 = 5;
	// li r28,0
	r28.s64 = 0;
	// li r20,1
	r20.s64 = 1;
	// li r21,-1
	r21.s64 = -1;
	// addi r23,r11,5568
	r23.s64 = r11.s64 + 5568;
	// addi r22,r10,30860
	r22.s64 = ctx.r10.s64 + 30860;
	// addi r25,r9,3998
	r25.s64 = ctx.r9.s64 + 3998;
loc_82677A48:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82677A50;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677a88
	if (cr6.eq) goto loc_82677A88;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x82677A68;
	sub_82633D40(ctx, base);
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
	// stb r28,208(r29)
	PPC_STORE_U8(r29.u32 + 208, r28.u8);
	// addi r3,r29,220
	ctx.r3.s64 = r29.s64 + 220;
	// stb r28,210(r29)
	PPC_STORE_U8(r29.u32 + 210, r28.u8);
	// stw r20,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r20.u32);
	// stw r21,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r21.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82677A84;
	sub_821C2F70(ctx, base);
	// b 0x82677a8c
	goto loc_82677A8C;
loc_82677A88:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677A8C:
	// stw r29,-20(r31)
	PPC_STORE_U32(r31.u32 + -20, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677A98;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677ab4
	if (cr6.eq) goto loc_82677AB4;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677AB0;
	sub_826311F8(ctx, base);
	// b 0x82677ab8
	goto loc_82677AB8;
loc_82677AB4:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677AB8:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677AC4;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677ae0
	if (cr6.eq) goto loc_82677AE0;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677ADC;
	sub_826311F8(ctx, base);
	// b 0x82677ae4
	goto loc_82677AE4;
loc_82677AE0:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677AE4:
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677AF0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677b10
	if (cr6.eq) goto loc_82677B10;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677B08;
	sub_826311F8(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// b 0x82677b14
	goto loc_82677B14;
loc_82677B10:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82677B14:
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// addi r4,r30,-80
	ctx.r4.s64 = r30.s64 + -80;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r28,-80(r30)
	PPC_STORE_U8(r30.u32 + -80, r28.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82677BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82677a48
	if (!cr0.eq) goto loc_82677A48;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82677BF0"))) PPC_WEAK_FUNC(sub_82677BF0);
PPC_FUNC_IMPL(__imp__sub_82677BF0) {
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
	// bl 0x82676690
	ctx.lr = 0x82677C10;
	sub_82676690(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677c28
	if (cr6.eq) goto loc_82677C28;
	// bl 0x82130588
	ctx.lr = 0x82677C24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677C28:
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

__attribute__((alias("__imp__sub_82677C40"))) PPC_WEAK_FUNC(sub_82677C40);
PPC_FUNC_IMPL(__imp__sub_82677C40) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82677C48;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26776
	ctx.r4.s64 = ctx.r9.s64 + -26776;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26800
	ctx.r5.s64 = ctx.r10.s64 + -26800;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677C78;
	sub_82654318(ctx, base);
	// lwz r6,496(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 496);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r24,496
	ctx.r3.s64 = r24.s64 + 496;
	// addi r7,r8,31164
	ctx.r7.s64 = ctx.r8.s64 + 31164;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// stw r7,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82677C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r31,r24,672
	r31.s64 = r24.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,30316
	ctx.r4.s64 = ctx.r9.s64 + 30316;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826347f0
	ctx.lr = 0x82677CCC;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r27,r24,1472
	r27.s64 = r24.s64 + 1472;
	// addi r30,r24,1312
	r30.s64 = r24.s64 + 1312;
	// addi r31,r24,1032
	r31.s64 = r24.s64 + 1032;
	// li r26,10
	r26.s64 = 10;
	// li r28,0
	r28.s64 = 0;
	// li r20,1
	r20.s64 = 1;
	// li r21,-1
	r21.s64 = -1;
	// addi r23,r11,5568
	r23.s64 = r11.s64 + 5568;
	// addi r22,r10,30860
	r22.s64 = ctx.r10.s64 + 30860;
	// addi r25,r9,3998
	r25.s64 = ctx.r9.s64 + 3998;
loc_82677D00:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82677D08;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d40
	if (cr6.eq) goto loc_82677D40;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x82677D20;
	sub_82633D40(ctx, base);
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
	// stb r28,208(r29)
	PPC_STORE_U8(r29.u32 + 208, r28.u8);
	// addi r3,r29,220
	ctx.r3.s64 = r29.s64 + 220;
	// stb r28,210(r29)
	PPC_STORE_U8(r29.u32 + 210, r28.u8);
	// stw r20,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r20.u32);
	// stw r21,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r21.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82677D3C;
	sub_821C2F70(ctx, base);
	// b 0x82677d44
	goto loc_82677D44;
loc_82677D40:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D44:
	// stw r29,-40(r31)
	PPC_STORE_U32(r31.u32 + -40, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677D50;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d6c
	if (cr6.eq) goto loc_82677D6C;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677D68;
	sub_826311F8(ctx, base);
	// b 0x82677d70
	goto loc_82677D70;
loc_82677D6C:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D70:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677D7C;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677d98
	if (cr6.eq) goto loc_82677D98;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677D94;
	sub_826311F8(ctx, base);
	// b 0x82677d9c
	goto loc_82677D9C;
loc_82677D98:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82677D9C:
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82677DA8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82677dc8
	if (cr6.eq) goto loc_82677DC8;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x82677DC0;
	sub_826311F8(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// b 0x82677dcc
	goto loc_82677DCC;
loc_82677DC8:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82677DCC:
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// addi r4,r30,-160
	ctx.r4.s64 = r30.s64 + -160;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r28,-160(r30)
	PPC_STORE_U8(r30.u32 + -160, r28.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82677E50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82677E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82677E88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82677d00
	if (!cr0.eq) goto loc_82677D00;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82677EA8"))) PPC_WEAK_FUNC(sub_82677EA8);
PPC_FUNC_IMPL(__imp__sub_82677EA8) {
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
	// bl 0x82676798
	ctx.lr = 0x82677EC8;
	sub_82676798(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82677ee0
	if (cr6.eq) goto loc_82677EE0;
	// bl 0x82130588
	ctx.lr = 0x82677EDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677EE0:
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

__attribute__((alias("__imp__sub_82677EF8"))) PPC_WEAK_FUNC(sub_82677EF8);
PPC_FUNC_IMPL(__imp__sub_82677EF8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,-26752
	ctx.r4.s64 = ctx.r9.s64 + -26752;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82677F34;
	sub_82654318(ctx, base);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// addi r7,r8,31972
	ctx.r7.s64 = ctx.r8.s64 + 31972;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82677F58;
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

__attribute__((alias("__imp__sub_82677F70"))) PPC_WEAK_FUNC(sub_82677F70);
PPC_FUNC_IMPL(__imp__sub_82677F70) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,31972
	ctx.r10.s64 = r11.s64 + 31972;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8221fcc8
	ctx.lr = 0x82677F9C;
	sub_8221FCC8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82677fb4
	if (cr6.eq) goto loc_82677FB4;
	// bl 0x82130588
	ctx.lr = 0x82677FB0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82677FB4:
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

__attribute__((alias("__imp__sub_82677FCC"))) PPC_WEAK_FUNC(sub_82677FCC);
PPC_FUNC_IMPL(__imp__sub_82677FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82677FD0"))) PPC_WEAK_FUNC(sub_82677FD0);
PPC_FUNC_IMPL(__imp__sub_82677FD0) {
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
	ctx.lr = 0x82677FD8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-26704
	ctx.r4.s64 = ctx.r9.s64 + -26704;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,-26728
	ctx.r5.s64 = ctx.r10.s64 + -26728;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678008;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r29,0
	r29.s64 = 0;
	// addi r7,r8,-32756
	ctx.r7.s64 = ctx.r8.s64 + -32756;
	// addi r31,r23,672
	r31.s64 = r23.s64 + 672;
	// stw r7,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,992(r23)
	PPC_STORE_U32(r23.u32 + 992, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,996(r23)
	PPC_STORE_U16(r23.u32 + 996, r29.u16);
	// sth r29,998(r23)
	PPC_STORE_U16(r23.u32 + 998, r29.u16);
	// lwz r6,672(r23)
	ctx.r6.u64 = PPC_LOAD_U32(r23.u32 + 672);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,886(r23)
	ctx.r5.u64 = PPC_LOAD_U16(r23.u32 + 886);
	// addi r4,r4,30248
	ctx.r4.s64 = ctx.r4.s64 + 30248;
	// bl 0x826347f0
	ctx.lr = 0x82678054;
	sub_826347F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r27,r29
	r27.u64 = r29.u64;
	// addi r25,r23,1400
	r25.s64 = r23.s64 + 1400;
	// addi r26,r23,1384
	r26.s64 = r23.s64 + 1384;
	// addi r30,r23,1256
	r30.s64 = r23.s64 + 1256;
	// addi r31,r23,1032
	r31.s64 = r23.s64 + 1032;
	// li r18,1
	r18.s64 = 1;
	// li r19,-1
	r19.s64 = -1;
	// addi r21,r11,5568
	r21.s64 = r11.s64 + 5568;
	// addi r20,r10,30860
	r20.s64 = ctx.r10.s64 + 30860;
	// addi r24,r9,-14748
	r24.s64 = ctx.r9.s64 + -14748;
	// addi r22,r8,3998
	r22.s64 = ctx.r8.s64 + 3998;
loc_82678090:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x82678098;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826780d0
	if (cr6.eq) goto loc_826780D0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x82633d40
	ctx.lr = 0x826780B0;
	sub_82633D40(ctx, base);
	// stw r20,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r20.u32);
	// stb r29,208(r28)
	PPC_STORE_U8(r28.u32 + 208, r29.u8);
	// addi r3,r28,220
	ctx.r3.s64 = r28.s64 + 220;
	// stb r29,210(r28)
	PPC_STORE_U8(r28.u32 + 210, r29.u8);
	// stw r18,212(r28)
	PPC_STORE_U32(r28.u32 + 212, r18.u32);
	// stw r19,216(r28)
	PPC_STORE_U32(r28.u32 + 216, r19.u32);
	// bl 0x821c2f70
	ctx.lr = 0x826780CC;
	sub_821C2F70(ctx, base);
	// b 0x826780d4
	goto loc_826780D4;
loc_826780D0:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_826780D4:
	// stw r28,-32(r31)
	PPC_STORE_U32(r31.u32 + -32, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826780E0;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826780fc
	if (cr6.eq) goto loc_826780FC;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x826780F8;
	sub_826311F8(ctx, base);
	// b 0x82678100
	goto loc_82678100;
loc_826780FC:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_82678100:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8267810C;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82678128
	if (cr6.eq) goto loc_82678128;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x82678124;
	sub_826311F8(ctx, base);
	// b 0x8267812c
	goto loc_8267812C;
loc_82678128:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8267812C:
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678138;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82678158
	if (cr6.eq) goto loc_82678158;
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x826311f8
	ctx.lr = 0x82678150;
	sub_826311F8(ctx, base);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// b 0x8267815c
	goto loc_8267815C;
loc_82678158:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8267815C:
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// addi r4,r30,-128
	ctx.r4.s64 = r30.s64 + -128;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stwx r3,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u32);
	// stb r29,-128(r30)
	PPC_STORE_U8(r30.u32 + -128, r29.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826781E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r29,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r29.u8);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826781FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r29,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r29.u8);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82678218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267822C;
	sub_82137A08(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r25,r25,32
	r25.s64 = r25.s64 + 32;
	// cmpwi cr6,r27,8
	cr6.compare<int32_t>(r27.s32, 8, xer);
	// blt cr6,0x82678090
	if (cr6.lt) goto loc_82678090;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82678254"))) PPC_WEAK_FUNC(sub_82678254);
PPC_FUNC_IMPL(__imp__sub_82678254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678258"))) PPC_WEAK_FUNC(sub_82678258);
PPC_FUNC_IMPL(__imp__sub_82678258) {
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
	// bl 0x826768b0
	ctx.lr = 0x82678278;
	sub_826768B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678290
	if (cr6.eq) goto loc_82678290;
	// bl 0x82130588
	ctx.lr = 0x8267828C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82678290:
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

__attribute__((alias("__imp__sub_826782A8"))) PPC_WEAK_FUNC(sub_826782A8);
PPC_FUNC_IMPL(__imp__sub_826782A8) {
	PPC_FUNC_PROLOGUE();
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-25872
	ctx.r4.s64 = ctx.r9.s64 + -25872;
	// addi r8,r11,28644
	ctx.r8.s64 = r11.s64 + 28644;
	// addi r5,r10,26816
	ctx.r5.s64 = ctx.r10.s64 + 26816;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826782E8;
	sub_82654318(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,-26676
	ctx.r6.s64 = ctx.r7.s64 + -26676;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// lfs f0,11360(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,996(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// stw r11,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r11.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,3998
	ctx.r4.s64 = ctx.r4.s64 + 3998;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82678324;
	sub_82633D40(ctx, base);
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

__attribute__((alias("__imp__sub_8267835C"))) PPC_WEAK_FUNC(sub_8267835C);
PPC_FUNC_IMPL(__imp__sub_8267835C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678360"))) PPC_WEAK_FUNC(sub_82678360);
PPC_FUNC_IMPL(__imp__sub_82678360) {
	PPC_FUNC_PROLOGUE();
	// b 0x82630318
	sub_82630318(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82678364"))) PPC_WEAK_FUNC(sub_82678364);
PPC_FUNC_IMPL(__imp__sub_82678364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678368"))) PPC_WEAK_FUNC(sub_82678368);
PPC_FUNC_IMPL(__imp__sub_82678368) {
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
	ctx.lr = 0x82678370;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678394
	if (cr6.eq) goto loc_82678394;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82678394;
	sub_82130588(ctx, base);
loc_82678394:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267839C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826783A4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826783bc
	if (cr6.eq) goto loc_826783BC;
	// bl 0x82130588
	ctx.lr = 0x826783B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826783BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826783C4"))) PPC_WEAK_FUNC(sub_826783C4);
PPC_FUNC_IMPL(__imp__sub_826783C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826783C8"))) PPC_WEAK_FUNC(sub_826783C8);
PPC_FUNC_IMPL(__imp__sub_826783C8) {
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
	ctx.lr = 0x826783D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-24932
	ctx.r5.s64 = r11.s64 + -24932;
	// addi r4,r10,-24940
	ctx.r4.s64 = ctx.r10.s64 + -24940;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x826783FC;
	sub_8228F920(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r3,208
	ctx.r3.s64 = 208;
	// addi r8,r9,-25740
	ctx.r8.s64 = ctx.r9.s64 + -25740;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x82678410;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678430
	if (cr6.eq) goto loc_82678430;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25756
	ctx.r4.s64 = r11.s64 + -25756;
	// bl 0x82633d40
	ctx.lr = 0x82678428;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678434
	goto loc_82678434;
loc_82678430:
	// li r11,0
	r11.s64 = 0;
loc_82678434:
	// stw r11,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678440;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678460
	if (cr6.eq) goto loc_82678460;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25768
	ctx.r4.s64 = r11.s64 + -25768;
	// bl 0x82633d40
	ctx.lr = 0x82678458;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678464
	goto loc_82678464;
loc_82678460:
	// li r11,0
	r11.s64 = 0;
loc_82678464:
	// stw r11,948(r31)
	PPC_STORE_U32(r31.u32 + 948, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678470;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678490
	if (cr6.eq) goto loc_82678490;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25780
	ctx.r4.s64 = r11.s64 + -25780;
	// bl 0x82633d40
	ctx.lr = 0x82678488;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678494
	goto loc_82678494;
loc_82678490:
	// li r11,0
	r11.s64 = 0;
loc_82678494:
	// stw r11,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826784A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826784c0
	if (cr6.eq) goto loc_826784C0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,-25792
	ctx.r4.s64 = r11.s64 + -25792;
	// bl 0x82633d40
	ctx.lr = 0x826784B8;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x826784c4
	goto loc_826784C4;
loc_826784C0:
	// li r11,0
	r11.s64 = 0;
loc_826784C4:
	// stw r11,956(r31)
	PPC_STORE_U32(r31.u32 + 956, r11.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826784D0;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// beq cr6,0x826784f8
	if (cr6.eq) goto loc_826784F8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25796
	ctx.r4.s64 = r11.s64 + -25796;
	// bl 0x826311f8
	ctx.lr = 0x826784F4;
	sub_826311F8(ctx, base);
	// b 0x826784fc
	goto loc_826784FC;
loc_826784F8:
	// li r30,0
	r30.s64 = 0;
loc_826784FC:
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678508;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678528
	if (cr6.eq) goto loc_82678528;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25800
	ctx.r4.s64 = r11.s64 + -25800;
	// bl 0x826311f8
	ctx.lr = 0x82678524;
	sub_826311F8(ctx, base);
	// b 0x8267852c
	goto loc_8267852C;
loc_82678528:
	// li r30,0
	r30.s64 = 0;
loc_8267852C:
	// stw r30,964(r31)
	PPC_STORE_U32(r31.u32 + 964, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678538;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678558
	if (cr6.eq) goto loc_82678558;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25804
	ctx.r4.s64 = r11.s64 + -25804;
	// bl 0x826311f8
	ctx.lr = 0x82678554;
	sub_826311F8(ctx, base);
	// b 0x8267855c
	goto loc_8267855C;
loc_82678558:
	// li r30,0
	r30.s64 = 0;
loc_8267855C:
	// stw r30,968(r31)
	PPC_STORE_U32(r31.u32 + 968, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678568;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678588
	if (cr6.eq) goto loc_82678588;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25808
	ctx.r4.s64 = r11.s64 + -25808;
	// bl 0x826311f8
	ctx.lr = 0x82678584;
	sub_826311F8(ctx, base);
	// b 0x8267858c
	goto loc_8267858C;
loc_82678588:
	// li r30,0
	r30.s64 = 0;
loc_8267858C:
	// stw r30,972(r31)
	PPC_STORE_U32(r31.u32 + 972, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678598;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826785b8
	if (cr6.eq) goto loc_826785B8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25820
	ctx.r4.s64 = r11.s64 + -25820;
	// bl 0x826311f8
	ctx.lr = 0x826785B4;
	sub_826311F8(ctx, base);
	// b 0x826785bc
	goto loc_826785BC;
loc_826785B8:
	// li r30,0
	r30.s64 = 0;
loc_826785BC:
	// stw r30,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826785C8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826785e8
	if (cr6.eq) goto loc_826785E8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25832
	ctx.r4.s64 = r11.s64 + -25832;
	// bl 0x826311f8
	ctx.lr = 0x826785E4;
	sub_826311F8(ctx, base);
	// b 0x826785ec
	goto loc_826785EC;
loc_826785E8:
	// li r30,0
	r30.s64 = 0;
loc_826785EC:
	// stw r30,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x826785F8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82678618
	if (cr6.eq) goto loc_82678618;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25844
	ctx.r4.s64 = r11.s64 + -25844;
	// bl 0x826311f8
	ctx.lr = 0x82678614;
	sub_826311F8(ctx, base);
	// b 0x8267861c
	goto loc_8267861C;
loc_82678618:
	// li r30,0
	r30.s64 = 0;
loc_8267861C:
	// stw r30,984(r31)
	PPC_STORE_U32(r31.u32 + 984, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82678628;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8267864c
	if (cr6.eq) goto loc_8267864C;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-25856
	ctx.r4.s64 = r11.s64 + -25856;
	// bl 0x826311f8
	ctx.lr = 0x82678644;
	sub_826311F8(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x82678650
	goto loc_82678650;
loc_8267864C:
	// li r11,0
	r11.s64 = 0;
loc_82678650:
	// stw r11,988(r31)
	PPC_STORE_U32(r31.u32 + 988, r11.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// addi r11,r31,880
	r11.s64 = r31.s64 + 880;
	// lwz r5,944(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,944(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// addi r4,r6,30372
	ctx.r4.s64 = ctx.r6.s64 + 30372;
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 960);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,944(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// lwz r5,948(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,964(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 964);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 980);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// lwz r7,952(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r11,952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// lhz r5,192(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r5,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r10,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r10.u16);
	// lwz r5,968(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 968);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// lhz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// lwz r11,984(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 984);
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// lwz r7,956(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r11,956(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r5,192(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r8,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r8.u16);
	// lwz r5,972(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 972);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r11,956(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// sth r8,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r8.u16);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r5,988(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 988);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,30372(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 30372);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r6,884(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r5.u16);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82678868"))) PPC_WEAK_FUNC(sub_82678868);
PPC_FUNC_IMPL(__imp__sub_82678868) {
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
	ctx.lr = 0x82678870;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678894
	if (cr6.eq) goto loc_82678894;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82678894;
	sub_82130588(ctx, base);
loc_82678894:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267889C;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826788A4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826788bc
	if (cr6.eq) goto loc_826788BC;
	// bl 0x82130588
	ctx.lr = 0x826788B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826788BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826788C4"))) PPC_WEAK_FUNC(sub_826788C4);
PPC_FUNC_IMPL(__imp__sub_826788C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826788C8"))) PPC_WEAK_FUNC(sub_826788C8);
PPC_FUNC_IMPL(__imp__sub_826788C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826788D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
	// addi r4,r9,-24884
	ctx.r4.s64 = ctx.r9.s64 + -24884;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678904;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r26,0
	r26.s64 = 0;
	// addi r7,r8,-31140
	ctx.r7.s64 = ctx.r8.s64 + -31140;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r30,r31,1040
	r30.s64 = r31.s64 + 1040;
	// li r29,9
	r29.s64 = 9;
	// stw r26,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, r26.u32);
	// addi r27,r11,28084
	r27.s64 = r11.s64 + 28084;
loc_82678928:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82678938;
	sub_82633D40(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,240
	r30.s64 = r30.s64 + 240;
	// bge 0x82678928
	if (!cr0.lt) goto loc_82678928;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r31,3440
	ctx.r3.s64 = r31.s64 + 3440;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-24896
	ctx.r4.s64 = r11.s64 + -24896;
	// bl 0x82633d40
	ctx.lr = 0x8267895C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,27188
	ctx.r8.s64 = ctx.r10.s64 + 27188;
	// stw r9,3648(r31)
	PPC_STORE_U32(r31.u32 + 3648, ctx.r9.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,3440(r31)
	PPC_STORE_U32(r31.u32 + 3440, ctx.r8.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r26,3684(r31)
	PPC_STORE_U32(r31.u32 + 3684, r26.u32);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// stw r26,3688(r31)
	PPC_STORE_U32(r31.u32 + 3688, r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r5,3692(r31)
	PPC_STORE_U32(r31.u32 + 3692, ctx.r5.u32);
	// lfs f13,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,3664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3664, temp.u32);
	// stfs f13,3668(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3668, temp.u32);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826789B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826789C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r5,-24916
	ctx.r5.s64 = ctx.r5.s64 + -24916;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826789E8;
	sub_82213058(ctx, base);
	// stw r3,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826789F8"))) PPC_WEAK_FUNC(sub_826789F8);
PPC_FUNC_IMPL(__imp__sub_826789F8) {
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
	// bl 0x82676a78
	ctx.lr = 0x82678A18;
	sub_82676A78(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82678a30
	if (cr6.eq) goto loc_82678A30;
	// bl 0x82130588
	ctx.lr = 0x82678A2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82678A30:
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

__attribute__((alias("__imp__sub_82678A48"))) PPC_WEAK_FUNC(sub_82678A48);
PPC_FUNC_IMPL(__imp__sub_82678A48) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
	// addi r4,r9,-24056
	ctx.r4.s64 = ctx.r9.s64 + -24056;
	// addi r8,r10,28644
	ctx.r8.s64 = ctx.r10.s64 + 28644;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82678A8C;
	sub_82654318(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r3,208
	ctx.r3.s64 = 208;
	// addi r5,r6,-24860
	ctx.r5.s64 = ctx.r6.s64 + -24860;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f0,1064(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
	// stfs f13,1068(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1068, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x82678AB8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678ad4
	if (cr6.eq) goto loc_82678AD4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,11
	ctx.r5.s64 = 11;
	// bl 0x82633d40
	ctx.lr = 0x82678ACC;
	sub_82633D40(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82678ad8
	goto loc_82678AD8;
loc_82678AD4:
	// li r11,0
	r11.s64 = 0;
loc_82678AD8:
	// stw r11,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r11.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82678AE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678afc
	if (cr6.eq) goto loc_82678AFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x82633d40
	ctx.lr = 0x82678AF8;
	sub_82633D40(ctx, base);
	// b 0x82678b00
	goto loc_82678B00;
loc_82678AFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82678B00:
	// stw r3,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, ctx.r3.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,1056(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lwz r7,1060(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82678B8C"))) PPC_WEAK_FUNC(sub_82678B8C);
PPC_FUNC_IMPL(__imp__sub_82678B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82678B90"))) PPC_WEAK_FUNC(sub_82678B90);
PPC_FUNC_IMPL(__imp__sub_82678B90) {
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
	ctx.lr = 0x82678B98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,62
	ctx.r4.s64 = 62;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x82678BBC;
	sub_82653B30(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82678BC0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82678e08
	if (cr6.eq) goto loc_82678E08;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82678c00
	if (cr6.eq) goto loc_82678C00;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82678BEC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82678bec
	if (!cr6.eq) goto loc_82678BEC;
loc_82678C00:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addi r4,r9,27976
	ctx.r4.s64 = ctx.r9.s64 + 27976;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// lwz r3,992(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82678C30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r29,0
	r29.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r27,1
	r27.s64 = 1;
	// li r10,25
	ctx.r10.s64 = 25;
	// stb r29,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, r29.u8);
	// addi r26,r9,32684
	r26.s64 = ctx.r9.s64 + 32684;
	// lwz r7,992(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// stb r29,209(r7)
	PPC_STORE_U8(ctx.r7.u32 + 209, r29.u8);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,212(r11)
	PPC_STORE_U32(r11.u32 + 212, r27.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r9,992(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r10,216(r9)
	PPC_STORE_U32(ctx.r9.u32 + 216, ctx.r10.u32);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x82678C98;
	sub_82137A08(ctx, base);
	// lwz r3,1032(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82678CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r31,1472
	r28.s64 = r31.s64 + 1472;
	// addi r3,r4,8988
	ctx.r3.s64 = ctx.r4.s64 + 8988;
	// bl 0x82221fd8
	ctx.lr = 0x82678CC0;
	sub_82221FD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r4,2
	ctx.r4.s64 = 2;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x82678CE0;
	sub_82137A08(ctx, base);
	// lwz r3,1112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1112);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82678CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,25364
	ctx.r4.s64 = ctx.r6.s64 + 25364;
	// lwz r28,-10244(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82678D10;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r4,27964
	ctx.r4.s64 = ctx.r4.s64 + 27964;
	// bl 0x822183b0
	ctx.lr = 0x82678D24;
	sub_822183B0(ctx, base);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,27944
	ctx.r4.s64 = r11.s64 + 27944;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678D40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r26,19
	r26.s64 = 19;
	// lwz r7,996(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,25328
	ctx.r4.s64 = ctx.r8.s64 + 25328;
	// stb r29,208(r7)
	PPC_STORE_U8(ctx.r7.u32 + 208, r29.u8);
	// lwz r6,996(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stb r29,209(r6)
	PPC_STORE_U8(ctx.r6.u32 + 209, r29.u8);
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r27,212(r5)
	PPC_STORE_U32(ctx.r5.u32 + 212, r27.u32);
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// stw r26,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, r26.u32);
	// lwz r8,996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r28,-10244(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82678D98;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,27932
	ctx.r4.s64 = ctx.r4.s64 + 27932;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822183b0
	ctx.lr = 0x82678DAC;
	sub_822183B0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r4,r3,27912
	ctx.r4.s64 = ctx.r3.s64 + 27912;
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1000(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, r29.u8);
	// lwz r8,1000(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stb r29,209(r8)
	PPC_STORE_U8(ctx.r8.u32 + 209, r29.u8);
	// lwz r7,1000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r27,212(r7)
	PPC_STORE_U32(ctx.r7.u32 + 212, r27.u32);
	// lwz r6,1000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// stw r26,216(r6)
	PPC_STORE_U32(ctx.r6.u32 + 216, r26.u32);
	// lwz r5,1000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r3.u16);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
loc_82678E08:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82678E10"))) PPC_WEAK_FUNC(sub_82678E10);
PPC_FUNC_IMPL(__imp__sub_82678E10) {
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
	ctx.lr = 0x82678E18;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82678E24;
	sub_82653B30(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82678E4C;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82678E60;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// beq cr6,0x82678eb0
	if (cr6.eq) goto loc_82678EB0;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-24044
	ctx.r4.s64 = ctx.r10.s64 + -24044;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_82678EB0:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82678EC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82678EC8"))) PPC_WEAK_FUNC(sub_82678EC8);
PPC_FUNC_IMPL(__imp__sub_82678EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x82678ED0;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x82678EDC;
	sub_82256058(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267914c
	if (cr6.eq) goto loc_8267914C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82678F10;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82678F24;
	sub_821FD7C0(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,-23772
	ctx.r4.s64 = r11.s64 + -23772;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stb r10,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r10.u8);
	// stw r10,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r10.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,3104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3104);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// lwz r31,308(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82679138
	if (cr6.gt) goto loc_82679138;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-28812
	r12.s64 = r12.s64 + -28812;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267904C;
	case 1:
		goto loc_82678F98;
	case 2:
		goto loc_82678FD4;
	case 3:
		goto loc_82679138;
	case 4:
		goto loc_82679010;
	case 5:
		goto loc_82679088;
	case 6:
		goto loc_82679138;
	case 7:
		goto loc_826790C4;
	case 8:
		goto loc_82679100;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-28596(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28596);
	// lwz r19,-28776(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28776);
	// lwz r19,-28716(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28716);
	// lwz r19,-28360(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28360);
	// lwz r19,-28656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28656);
	// lwz r19,-28536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28536);
	// lwz r19,-28360(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28360);
	// lwz r19,-28476(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28476);
	// lwz r19,-28416(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -28416);
loc_82678F98:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82678fc8
	if (cr6.eq) goto loc_82678FC8;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23788
	ctx.r4.s64 = r11.s64 + -23788;
	// b 0x82679138
	goto loc_82679138;
loc_82678FC8:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23804
	ctx.r4.s64 = r11.s64 + -23804;
	// b 0x82679138
	goto loc_82679138;
loc_82678FD4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82678FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679004
	if (cr6.eq) goto loc_82679004;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23824
	ctx.r4.s64 = r11.s64 + -23824;
	// b 0x82679138
	goto loc_82679138;
loc_82679004:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23844
	ctx.r4.s64 = r11.s64 + -23844;
	// b 0x82679138
	goto loc_82679138;
loc_82679010:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679040
	if (cr6.eq) goto loc_82679040;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23864
	ctx.r4.s64 = r11.s64 + -23864;
	// b 0x82679138
	goto loc_82679138;
loc_82679040:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23884
	ctx.r4.s64 = r11.s64 + -23884;
	// b 0x82679138
	goto loc_82679138;
loc_8267904C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8267907c
	if (cr6.eq) goto loc_8267907C;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23904
	ctx.r4.s64 = r11.s64 + -23904;
	// b 0x82679138
	goto loc_82679138;
loc_8267907C:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23924
	ctx.r4.s64 = r11.s64 + -23924;
	// b 0x82679138
	goto loc_82679138;
loc_82679088:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826790A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826790b8
	if (cr6.eq) goto loc_826790B8;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23940
	ctx.r4.s64 = r11.s64 + -23940;
	// b 0x82679138
	goto loc_82679138;
loc_826790B8:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23956
	ctx.r4.s64 = r11.s64 + -23956;
	// b 0x82679138
	goto loc_82679138;
loc_826790C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826790DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826790f4
	if (cr6.eq) goto loc_826790F4;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23972
	ctx.r4.s64 = r11.s64 + -23972;
	// b 0x82679138
	goto loc_82679138;
loc_826790F4:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-23988
	ctx.r4.s64 = r11.s64 + -23988;
	// b 0x82679138
	goto loc_82679138;
loc_82679100:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679130
	if (cr6.eq) goto loc_82679130;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-24008
	ctx.r4.s64 = r11.s64 + -24008;
	// b 0x82679138
	goto loc_82679138;
loc_82679130:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r11,-24028
	ctx.r4.s64 = r11.s64 + -24028;
loc_82679138:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267914C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267914C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82679154"))) PPC_WEAK_FUNC(sub_82679154);
PPC_FUNC_IMPL(__imp__sub_82679154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679158"))) PPC_WEAK_FUNC(sub_82679158);
PPC_FUNC_IMPL(__imp__sub_82679158) {
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
	ctx.lr = 0x82679160;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826535f8
	ctx.lr = 0x8267916C;
	sub_826535F8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82679194;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x826791A8;
	sub_821FD7C0(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r7,10248(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r11.u8);
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// lwz r6,468(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stw r7,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r7.u32);
	// lwz r31,324(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826791DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r5,2612
	r29.s64 = ctx.r5.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x826791F4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82679204;
	sub_825ED480(ctx, base);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cntlzw r10,r4
	ctx.r10.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r4,r11,620
	ctx.r4.s64 = r11.s64 + 620;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x82679228;
	sub_82722678(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82679230"))) PPC_WEAK_FUNC(sub_82679230);
PPC_FUNC_IMPL(__imp__sub_82679230) {
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
	ctx.lr = 0x82679238;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8267924C;
	sub_8238EC00(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r30,r10,-21500
	r30.s64 = ctx.r10.s64 + -21500;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r8,-11120
	ctx.r4.s64 = ctx.r8.s64 + -11120;
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r26,-24180(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24180);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823db670
	ctx.lr = 0x82679278;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x8267928C;
	sub_821FD7C0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r11,324(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// li r31,0
	r31.s64 = 0;
	// lwz r7,10248(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 10248);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// addi r28,r11,92
	r28.s64 = r11.s64 + 92;
	// stb r31,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r31.u8);
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r31.u32);
	// stw r7,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r7.u32);
	// bl 0x82256058
	ctx.lr = 0x826792B4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826792d4
	if (cr6.eq) goto loc_826792D4;
	// bl 0x82256058
	ctx.lr = 0x826792C0;
	sub_82256058(ctx, base);
	// addi r31,r3,8
	r31.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826792d4
	if (cr6.eq) goto loc_826792D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x826792d8
	goto loc_826792D8;
loc_826792D4:
	// li r11,-1
	r11.s64 = -1;
loc_826792D8:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r30,-10020(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82679300;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,340
	ctx.r3.s64 = r30.s64 + 340;
	// bl 0x826cac98
	ctx.lr = 0x8267930C;
	sub_826CAC98(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823895f8
	ctx.lr = 0x82679328;
	sub_823895F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x82679408
	if (cr6.gt) goto loc_82679408;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r11,-8292
	r11.s64 = r11.s64 + -8292;
loc_82679350:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82679374
	if (cr6.eq) goto loc_82679374;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679350
	if (cr6.eq) goto loc_82679350;
loc_82679374:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// bl 0x82256058
	ctx.lr = 0x82679380;
	sub_82256058(ctx, base);
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679408
	if (!cr6.eq) goto loc_82679408;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82679408
	if (!cr6.eq) goto loc_82679408;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826793B0;
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
	ctx.lr = 0x826793C4;
	sub_82270170(ctx, base);
	// bl 0x82272e38
	ctx.lr = 0x826793C8;
	sub_82272E38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82679408
	if (cr6.eq) goto loc_82679408;
	// lwz r11,496(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 496);
	// addi r3,r27,496
	ctx.r3.s64 = r27.s64 + 496;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826793EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,29196
	ctx.r4.s64 = ctx.r9.s64 + 29196;
	// addi r3,r27,256
	ctx.r3.s64 = r27.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82679400;
	sub_8262FFE0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
loc_82679408:
	// lwz r11,3096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3096);
	// addi r3,r27,496
	ctx.r3.s64 = r27.s64 + 496;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// lwz r11,496(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 496);
	// bne cr6,0x8267942c
	if (!cr6.eq) goto loc_8267942C;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x8267943c
	goto loc_8267943C;
loc_8267942C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267943C:
	// bctrl 
	ctx.lr = 0x82679440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,27980
	ctx.r4.s64 = r11.s64 + 27980;
	// addi r3,r27,256
	ctx.r3.s64 = r27.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82679454;
	sub_8262FFE0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267945C"))) PPC_WEAK_FUNC(sub_8267945C);
PPC_FUNC_IMPL(__imp__sub_8267945C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679460"))) PPC_WEAK_FUNC(sub_82679460);
PPC_FUNC_IMPL(__imp__sub_82679460) {
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
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82679620
	if (cr6.gt) goto loc_82679620;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-27496
	r12.s64 = r12.s64 + -27496;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82679604;
	case 1:
		goto loc_82679620;
	case 2:
		goto loc_82679604;
	case 3:
		goto loc_82679604;
	case 4:
		goto loc_82679620;
	case 5:
		goto loc_82679620;
	case 6:
		goto loc_82679620;
	case 7:
		goto loc_82679620;
	case 8:
		goto loc_826794BC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27132);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27104(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27104);
	// lwz r19,-27460(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27460);
loc_826794BC:
	// bl 0x82256058
	ctx.lr = 0x826794C0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794CC;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794DC;
	sub_82256058(ctx, base);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// bl 0x82256058
	ctx.lr = 0x826794EC;
	sub_82256058(ctx, base);
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679604
	if (!cr6.eq) goto loc_82679604;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82679604
	if (!cr6.eq) goto loc_82679604;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267951C;
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
	ctx.lr = 0x82679530;
	sub_82270170(ctx, base);
	// bl 0x82272e38
	ctx.lr = 0x82679534;
	sub_82272E38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82679604
	if (cr6.eq) goto loc_82679604;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8267954C;
	sub_8238EC00(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r9,-11120
	ctx.r4.s64 = ctx.r9.s64 + -11120;
	// lwz r3,-24180(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82679564;
	sub_8220EEA8(ctx, base);
	// addi r31,r3,92
	r31.s64 = ctx.r3.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823895f8
	ctx.lr = 0x82679578;
	sub_823895F8(ctx, base);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bgt cr6,0x8267960c
	if (cr6.gt) goto loc_8267960C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r11,-8292
	r11.s64 = r11.s64 + -8292;
loc_82679594:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826795b8
	if (cr6.eq) goto loc_826795B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82679594
	if (cr6.eq) goto loc_82679594;
loc_826795B8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8267960c
	if (cr6.eq) goto loc_8267960C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826795CC;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r4,r9,-23756
	ctx.r4.s64 = ctx.r9.s64 + -23756;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x826795F0;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82679604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679604:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82679624
	goto loc_82679624;
loc_8267960C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679618;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82679624
	goto loc_82679624;
loc_82679620:
	// bl 0x826537d0
	ctx.lr = 0x82679624;
	sub_826537D0(ctx, base);
loc_82679624:
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

__attribute__((alias("__imp__sub_8267963C"))) PPC_WEAK_FUNC(sub_8267963C);
PPC_FUNC_IMPL(__imp__sub_8267963C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679640"))) PPC_WEAK_FUNC(sub_82679640);
PPC_FUNC_IMPL(__imp__sub_82679640) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82653c88
	ctx.lr = 0x82679658;
	sub_82653C88(ctx, base);
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82679678"))) PPC_WEAK_FUNC(sub_82679678);
PPC_FUNC_IMPL(__imp__sub_82679678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r3,9
	cr6.compare<uint32_t>(ctx.r3.u32, 9, xer);
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// bgt cr6,0x82679bc4
	if (cr6.gt) goto loc_82679BC4;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26976
	r12.s64 = r12.s64 + -26976;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_82679BC4;
	case 1:
		goto loc_82679BC4;
	case 2:
		goto loc_82679BC4;
	case 3:
		goto loc_82679BC4;
	case 4:
		goto loc_82679BC4;
	case 5:
		goto loc_82679BC4;
	case 6:
		goto loc_82679854;
	case 7:
		goto loc_82679BC4;
	case 8:
		goto loc_8267984C;
	case 9:
		goto loc_826796C8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-26540(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26540);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-26548(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26548);
	// lwz r19,-26936(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26936);
loc_826796C8:
	// cmplwi cr6,r4,29
	cr6.compare<uint32_t>(ctx.r4.u32, 29, xer);
	// bgt cr6,0x82679840
	if (cr6.gt) goto loc_82679840;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26904
	r12.s64 = r12.s64 + -26904;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82679760;
	case 1:
		goto loc_82679760;
	case 2:
		goto loc_82679770;
	case 3:
		goto loc_82679770;
	case 4:
		goto loc_82679800;
	case 5:
		goto loc_82679800;
	case 6:
		goto loc_82679800;
	case 7:
		goto loc_82679800;
	case 8:
		goto loc_82679800;
	case 9:
		goto loc_82679800;
	case 10:
		goto loc_82679800;
	case 11:
		goto loc_82679800;
	case 12:
		goto loc_82679810;
	case 13:
		goto loc_82679810;
	case 14:
		goto loc_82679810;
	case 15:
		goto loc_82679810;
	case 16:
		goto loc_82679810;
	case 17:
		goto loc_82679810;
	case 18:
		goto loc_82679810;
	case 19:
		goto loc_82679810;
	case 20:
		goto loc_82679820;
	case 21:
		goto loc_82679830;
	case 22:
		goto loc_82679780;
	case 23:
		goto loc_82679790;
	case 24:
		goto loc_826797A0;
	case 25:
		goto loc_826797B0;
	case 26:
		goto loc_826797C0;
	case 27:
		goto loc_826797D0;
	case 28:
		goto loc_826797E0;
	case 29:
		goto loc_826797F0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-26784(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26784);
	// lwz r19,-26784(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26784);
	// lwz r19,-26768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26768);
	// lwz r19,-26768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26768);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26624);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26608(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26608);
	// lwz r19,-26592(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26592);
	// lwz r19,-26576(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26576);
	// lwz r19,-26752(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26752);
	// lwz r19,-26736(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26736);
	// lwz r19,-26720(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26720);
	// lwz r19,-26704(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26704);
	// lwz r19,-26688(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26688);
	// lwz r19,-26672(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26672);
	// lwz r19,-26656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26656);
	// lwz r19,-26640(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26640);
loc_82679760:
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679770:
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679780:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// blr 
	return;
loc_82679790:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// blr 
	return;
loc_826797A0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,124(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// blr 
	return;
loc_826797B0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,120(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// blr 
	return;
loc_826797C0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,144(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// blr 
	return;
loc_826797D0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,148(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// blr 
	return;
loc_826797E0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,140(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// blr 
	return;
loc_826797F0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,136(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// blr 
	return;
loc_82679800:
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679810:
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679820:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,84(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// blr 
	return;
loc_82679830:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,80(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// blr 
	return;
loc_82679840:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// blr 
	return;
loc_8267984C:
	// li r3,6
	ctx.r3.s64 = 6;
	// slw r4,r11,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r4.u8 & 0x3F));
loc_82679854:
	// cmpwi cr6,r4,256
	cr6.compare<int32_t>(ctx.r4.s32, 256, xer);
	// bgt cr6,0x82679b14
	if (cr6.gt) goto loc_82679B14;
	// beq cr6,0x82679b04
	if (cr6.eq) goto loc_82679B04;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bgt cr6,0x82679bc4
	if (cr6.gt) goto loc_82679BC4;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26492
	r12.s64 = r12.s64 + -26492;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82679A84;
	case 1:
		goto loc_82679A94;
	case 2:
		goto loc_82679BC4;
	case 3:
		goto loc_82679AA4;
	case 4:
		goto loc_82679BC4;
	case 5:
		goto loc_82679BC4;
	case 6:
		goto loc_82679BC4;
	case 7:
		goto loc_82679AB4;
	case 8:
		goto loc_82679BC4;
	case 9:
		goto loc_82679BC4;
	case 10:
		goto loc_82679BC4;
	case 11:
		goto loc_82679BC4;
	case 12:
		goto loc_82679BC4;
	case 13:
		goto loc_82679BC4;
	case 14:
		goto loc_82679BC4;
	case 15:
		goto loc_82679AC4;
	case 16:
		goto loc_82679BC4;
	case 17:
		goto loc_82679BC4;
	case 18:
		goto loc_82679BC4;
	case 19:
		goto loc_82679BC4;
	case 20:
		goto loc_82679BC4;
	case 21:
		goto loc_82679BC4;
	case 22:
		goto loc_82679BC4;
	case 23:
		goto loc_82679BC4;
	case 24:
		goto loc_82679BC4;
	case 25:
		goto loc_82679BC4;
	case 26:
		goto loc_82679BC4;
	case 27:
		goto loc_82679BC4;
	case 28:
		goto loc_82679BC4;
	case 29:
		goto loc_82679BC4;
	case 30:
		goto loc_82679BC4;
	case 31:
		goto loc_82679AD4;
	case 32:
		goto loc_82679BC4;
	case 33:
		goto loc_82679BC4;
	case 34:
		goto loc_82679BC4;
	case 35:
		goto loc_82679BC4;
	case 36:
		goto loc_82679BC4;
	case 37:
		goto loc_82679BC4;
	case 38:
		goto loc_82679BC4;
	case 39:
		goto loc_82679BC4;
	case 40:
		goto loc_82679BC4;
	case 41:
		goto loc_82679BC4;
	case 42:
		goto loc_82679BC4;
	case 43:
		goto loc_82679BC4;
	case 44:
		goto loc_82679BC4;
	case 45:
		goto loc_82679BC4;
	case 46:
		goto loc_82679BC4;
	case 47:
		goto loc_82679BC4;
	case 48:
		goto loc_82679BC4;
	case 49:
		goto loc_82679BC4;
	case 50:
		goto loc_82679BC4;
	case 51:
		goto loc_82679BC4;
	case 52:
		goto loc_82679BC4;
	case 53:
		goto loc_82679BC4;
	case 54:
		goto loc_82679BC4;
	case 55:
		goto loc_82679BC4;
	case 56:
		goto loc_82679BC4;
	case 57:
		goto loc_82679BC4;
	case 58:
		goto loc_82679BC4;
	case 59:
		goto loc_82679BC4;
	case 60:
		goto loc_82679BC4;
	case 61:
		goto loc_82679BC4;
	case 62:
		goto loc_82679BC4;
	case 63:
		goto loc_82679AE4;
	case 64:
		goto loc_82679BC4;
	case 65:
		goto loc_82679BC4;
	case 66:
		goto loc_82679BC4;
	case 67:
		goto loc_82679BC4;
	case 68:
		goto loc_82679BC4;
	case 69:
		goto loc_82679BC4;
	case 70:
		goto loc_82679BC4;
	case 71:
		goto loc_82679BC4;
	case 72:
		goto loc_82679BC4;
	case 73:
		goto loc_82679BC4;
	case 74:
		goto loc_82679BC4;
	case 75:
		goto loc_82679BC4;
	case 76:
		goto loc_82679BC4;
	case 77:
		goto loc_82679BC4;
	case 78:
		goto loc_82679BC4;
	case 79:
		goto loc_82679BC4;
	case 80:
		goto loc_82679BC4;
	case 81:
		goto loc_82679BC4;
	case 82:
		goto loc_82679BC4;
	case 83:
		goto loc_82679BC4;
	case 84:
		goto loc_82679BC4;
	case 85:
		goto loc_82679BC4;
	case 86:
		goto loc_82679BC4;
	case 87:
		goto loc_82679BC4;
	case 88:
		goto loc_82679BC4;
	case 89:
		goto loc_82679BC4;
	case 90:
		goto loc_82679BC4;
	case 91:
		goto loc_82679BC4;
	case 92:
		goto loc_82679BC4;
	case 93:
		goto loc_82679BC4;
	case 94:
		goto loc_82679BC4;
	case 95:
		goto loc_82679BC4;
	case 96:
		goto loc_82679BC4;
	case 97:
		goto loc_82679BC4;
	case 98:
		goto loc_82679BC4;
	case 99:
		goto loc_82679BC4;
	case 100:
		goto loc_82679BC4;
	case 101:
		goto loc_82679BC4;
	case 102:
		goto loc_82679BC4;
	case 103:
		goto loc_82679BC4;
	case 104:
		goto loc_82679BC4;
	case 105:
		goto loc_82679BC4;
	case 106:
		goto loc_82679BC4;
	case 107:
		goto loc_82679BC4;
	case 108:
		goto loc_82679BC4;
	case 109:
		goto loc_82679BC4;
	case 110:
		goto loc_82679BC4;
	case 111:
		goto loc_82679BC4;
	case 112:
		goto loc_82679BC4;
	case 113:
		goto loc_82679BC4;
	case 114:
		goto loc_82679BC4;
	case 115:
		goto loc_82679BC4;
	case 116:
		goto loc_82679BC4;
	case 117:
		goto loc_82679BC4;
	case 118:
		goto loc_82679BC4;
	case 119:
		goto loc_82679BC4;
	case 120:
		goto loc_82679BC4;
	case 121:
		goto loc_82679BC4;
	case 122:
		goto loc_82679BC4;
	case 123:
		goto loc_82679BC4;
	case 124:
		goto loc_82679BC4;
	case 125:
		goto loc_82679BC4;
	case 126:
		goto loc_82679BC4;
	case 127:
		goto loc_82679AF4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-25980(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25980);
	// lwz r19,-25964(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25964);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25948(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25948);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25932(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25932);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25916(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25916);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25900(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25900);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25884(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25884);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25868(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25868);
loc_82679A84:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,28(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// blr 
	return;
loc_82679A94:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,32(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// blr 
	return;
loc_82679AA4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// blr 
	return;
loc_82679AB4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,24(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// blr 
	return;
loc_82679AC4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// blr 
	return;
loc_82679AD4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
loc_82679AE4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// blr 
	return;
loc_82679AF4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// blr 
	return;
loc_82679B04:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,40(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// blr 
	return;
loc_82679B14:
	// cmpwi cr6,r4,4096
	cr6.compare<int32_t>(ctx.r4.s32, 4096, xer);
	// bgt cr6,0x82679b78
	if (cr6.gt) goto loc_82679B78;
	// beq cr6,0x82679b68
	if (cr6.eq) goto loc_82679B68;
	// cmpwi cr6,r4,512
	cr6.compare<int32_t>(ctx.r4.s32, 512, xer);
	// beq cr6,0x82679b58
	if (cr6.eq) goto loc_82679B58;
	// cmpwi cr6,r4,1024
	cr6.compare<int32_t>(ctx.r4.s32, 1024, xer);
	// beq cr6,0x82679b48
	if (cr6.eq) goto loc_82679B48;
	// cmpwi cr6,r4,2048
	cr6.compare<int32_t>(ctx.r4.s32, 2048, xer);
	// bne cr6,0x82679bc4
	if (!cr6.eq) goto loc_82679BC4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// blr 
	return;
loc_82679B48:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,112(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// blr 
	return;
loc_82679B58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,116(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// blr 
	return;
loc_82679B68:
	// li r11,0
	r11.s64 = 0;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679B78:
	// cmpwi cr6,r4,8192
	cr6.compare<int32_t>(ctx.r4.s32, 8192, xer);
	// beq cr6,0x82679bb4
	if (cr6.eq) goto loc_82679BB4;
	// cmpwi cr6,r4,16384
	cr6.compare<int32_t>(ctx.r4.s32, 16384, xer);
	// beq cr6,0x82679ba4
	if (cr6.eq) goto loc_82679BA4;
	// cmplwi cr6,r4,32768
	cr6.compare<uint32_t>(ctx.r4.u32, 32768, xer);
	// bne cr6,0x82679bc4
	if (!cr6.eq) goto loc_82679BC4;
	// li r11,0
	r11.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BA4:
	// li r11,0
	r11.s64 = 0;
	// li r4,16384
	ctx.r4.s64 = 16384;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BB4:
	// li r11,0
	r11.s64 = 0;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BC4:
	// li r11,0
	r11.s64 = 0;
}

__attribute__((alias("__imp__sub_82679BD8"))) PPC_WEAK_FUNC(sub_82679BD8);
PPC_FUNC_IMPL(__imp__sub_82679BD8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679BF4;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679c10
	if (cr6.eq) goto loc_82679C10;
	// bl 0x82387b90
	ctx.lr = 0x82679C04;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679C0C;
	sub_8238B070(ctx, base);
	// b 0x82679c1c
	goto loc_82679C1C;
loc_82679C10:
	// bl 0x82387b90
	ctx.lr = 0x82679C14;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679C1C;
	sub_8238B080(ctx, base);
loc_82679C1C:
	// addi r11,r31,5160
	r11.s64 = r31.s64 + 5160;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,592
	ctx.r5.s64 = 592;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823da950
	ctx.lr = 0x82679C30;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_82679C44"))) PPC_WEAK_FUNC(sub_82679C44);
PPC_FUNC_IMPL(__imp__sub_82679C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679C48"))) PPC_WEAK_FUNC(sub_82679C48);
PPC_FUNC_IMPL(__imp__sub_82679C48) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679C64;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679c80
	if (cr6.eq) goto loc_82679C80;
	// bl 0x82387b90
	ctx.lr = 0x82679C74;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679C7C;
	sub_8238B070(ctx, base);
	// b 0x82679c8c
	goto loc_82679C8C;
loc_82679C80:
	// bl 0x82387b90
	ctx.lr = 0x82679C84;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679C8C;
	sub_8238B080(ctx, base);
loc_82679C8C:
	// addi r4,r31,5160
	ctx.r4.s64 = r31.s64 + 5160;
	// bl 0x823917e0
	ctx.lr = 0x82679C94;
	sub_823917E0(ctx, base);
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

__attribute__((alias("__imp__sub_82679CA8"))) PPC_WEAK_FUNC(sub_82679CA8);
PPC_FUNC_IMPL(__imp__sub_82679CA8) {
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// lwz r11,3360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3360);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82679cf4
	if (!cr6.eq) goto loc_82679CF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,2816(r31)
	PPC_STORE_U8(r31.u32 + 2816, ctx.r10.u8);
	// lwz r9,736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82679CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679CF4:
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

__attribute__((alias("__imp__sub_82679D08"))) PPC_WEAK_FUNC(sub_82679D08);
PPC_FUNC_IMPL(__imp__sub_82679D08) {
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
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679D28;
	sub_821E6800(ctx, base);
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r11,r10,23088
	r11.s64 = ctx.r10.s64 + 23088;
	// addi r6,r9,-23272
	ctx.r6.s64 = ctx.r9.s64 + -23272;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,23088(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// addi r5,r7,-23300
	ctx.r5.s64 = ctx.r7.s64 + -23300;
	// stb r4,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, ctx.r4.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82679D68;
	sub_82634EC8(ctx, base);
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

__attribute__((alias("__imp__sub_82679D7C"))) PPC_WEAK_FUNC(sub_82679D7C);
PPC_FUNC_IMPL(__imp__sub_82679D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679D80"))) PPC_WEAK_FUNC(sub_82679D80);
PPC_FUNC_IMPL(__imp__sub_82679D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,804(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 804);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82679D90"))) PPC_WEAK_FUNC(sub_82679D90);
PPC_FUNC_IMPL(__imp__sub_82679D90) {
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
	ctx.lr = 0x82679D98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r29,672
	r28.s64 = r29.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x82679DB0;
	sub_82631F88(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82679e50
	if (!cr6.gt) goto loc_82679E50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r29,2836
	r31.s64 = r29.s64 + 2836;
	// subfic r27,r29,-2836
	xer.ca = r29.u32 <= 4294964460;
	r27.s64 = -2836 - r29.s64;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
loc_82679DCC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x82679DD4;
	sub_82631F88(ctx, base);
	// lwz r11,184(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82679de4
	if (cr6.lt) goto loc_82679DE4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82679DE4:
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x82679e20
	if (!cr6.eq) goto loc_82679E20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lbz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 208);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,208(r11)
	PPC_STORE_U8(r11.u32 + 208, ctx.r9.u8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,188(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 188);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82679E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82679e40
	goto loc_82679E40;
loc_82679E20:
	// lwz r11,848(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82679E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679E40:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x82679dcc
	if (cr6.lt) goto loc_82679DCC;
loc_82679E50:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82679E6C"))) PPC_WEAK_FUNC(sub_82679E6C);
PPC_FUNC_IMPL(__imp__sub_82679E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679E70"))) PPC_WEAK_FUNC(sub_82679E70);
PPC_FUNC_IMPL(__imp__sub_82679E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r11,r8,-112
	r11.s64 = ctx.r8.s64 + -112;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r7,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679E94"))) PPC_WEAK_FUNC(sub_82679E94);
PPC_FUNC_IMPL(__imp__sub_82679E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679E98"))) PPC_WEAK_FUNC(sub_82679E98);
PPC_FUNC_IMPL(__imp__sub_82679E98) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679f34
	if (!cr6.eq) goto loc_82679F34;
	// lbz r11,2816(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679f34
	if (cr6.eq) goto loc_82679F34;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679ED0;
	sub_821E6800(ctx, base);
	// lis r10,-32152
	ctx.r10.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-25432
	ctx.r4.s64 = ctx.r10.s64 + -25432;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2f90
	ctx.lr = 0x82679EE4;
	sub_821C2F90(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r9,-23216
	ctx.r6.s64 = ctx.r9.s64 + -23216;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r8,-23244
	ctx.r5.s64 = ctx.r8.s64 + -23244;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634ec8
	ctx.lr = 0x82679F1C;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_82679F34:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_82679F4C"))) PPC_WEAK_FUNC(sub_82679F4C);
PPC_FUNC_IMPL(__imp__sub_82679F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679F50"))) PPC_WEAK_FUNC(sub_82679F50);
PPC_FUNC_IMPL(__imp__sub_82679F50) {
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
	ctx.lr = 0x82679F58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679F68;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679f84
	if (cr6.eq) goto loc_82679F84;
	// bl 0x82387b90
	ctx.lr = 0x82679F78;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679F80;
	sub_8238B070(ctx, base);
	// b 0x82679f90
	goto loc_82679F90;
loc_82679F84:
	// bl 0x82387b90
	ctx.lr = 0x82679F88;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679F90;
	sub_8238B080(ctx, base);
loc_82679F90:
	// addi r31,r29,5160
	r31.s64 = r29.s64 + 5160;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823917e0
	ctx.lr = 0x82679FA0;
	sub_823917E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679fbc
	if (cr6.eq) goto loc_82679FBC;
	// li r5,592
	ctx.r5.s64 = 592;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82679FBC;
	sub_823DA950(ctx, base);
loc_82679FBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ed0
	ctx.lr = 0x82679FC4;
	sub_822A4ED0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82679FD4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82679ffc
	if (cr6.eq) goto loc_82679FFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82679FEC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,116(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x82679FFC;
	sub_822A4DE8(ctx, base);
loc_82679FFC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,5156(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 5156);
	// li r4,33
	ctx.r4.s64 = 33;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267A01C;
	sub_82641CB0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8264d070
	ctx.lr = 0x8267A024;
	sub_8264D070(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267A030;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267A034;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267A044;
	sub_8260B990(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267A04C"))) PPC_WEAK_FUNC(sub_8267A04C);
PPC_FUNC_IMPL(__imp__sub_8267A04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A050"))) PPC_WEAK_FUNC(sub_8267A050);
PPC_FUNC_IMPL(__imp__sub_8267A050) {
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
	ctx.lr = 0x8267A058;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r29,2836
	r31.s64 = r29.s64 + 2836;
	// addi r10,r11,-22524
	ctx.r10.s64 = r11.s64 + -22524;
	// li r30,32
	r30.s64 = 32;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_8267A074:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267a094
	if (cr6.eq) goto loc_8267A094;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267A094:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8267a074
	if (!cr0.eq) goto loc_8267A074;
	// addi r3,r29,3360
	ctx.r3.s64 = r29.s64 + 3360;
	// bl 0x8221fbc8
	ctx.lr = 0x8267A0A8;
	sub_8221FBC8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r29,3224
	r11.s64 = r29.s64 + 3224;
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_8267A0B8:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8267a0b8
	if (!cr0.lt) goto loc_8267A0B8;
	// lhz r11,2830(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 2830);
	// addi r31,r29,2820
	r31.s64 = r29.s64 + 2820;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a0e0
	if (cr6.eq) goto loc_8267A0E0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8267A0E0;
	sub_82130588(ctx, base);
loc_8267A0E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267A0E8;
	sub_821D2028(ctx, base);
	// addi r3,r29,992
	ctx.r3.s64 = r29.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x8267A0F0;
	sub_8221FBC8(ctx, base);
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a108
	if (cr6.eq) goto loc_8267A108;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267A108;
	sub_82130588(ctx, base);
loc_8267A108:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a11c
	if (cr6.eq) goto loc_8267A11C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267A11C;
	sub_82130588(ctx, base);
loc_8267A11C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267A124;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267A12C;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267A134;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267A13C;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267A144"))) PPC_WEAK_FUNC(sub_8267A144);
PPC_FUNC_IMPL(__imp__sub_8267A144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A148"))) PPC_WEAK_FUNC(sub_8267A148);
PPC_FUNC_IMPL(__imp__sub_8267A148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,2832(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2832);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267A158"))) PPC_WEAK_FUNC(sub_8267A158);
PPC_FUNC_IMPL(__imp__sub_8267A158) {
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
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a188
	if (cr6.eq) goto loc_8267A188;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8267A188;
	sub_82130588(ctx, base);
loc_8267A188:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267A190;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a1a8
	if (cr6.eq) goto loc_8267A1A8;
	// bl 0x82130588
	ctx.lr = 0x8267A1A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267A1A8:
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

__attribute__((alias("__imp__sub_8267A1C0"))) PPC_WEAK_FUNC(sub_8267A1C0);
PPC_FUNC_IMPL(__imp__sub_8267A1C0) {
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
	ctx.lr = 0x8267A1C8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// addi r27,r18,848
	r27.s64 = r18.s64 + 848;
	// lhz r11,852(r18)
	r11.u64 = PPC_LOAD_U16(r18.u32 + 852);
	// lwz r9,848(r18)
	ctx.r9.u64 = PPC_LOAD_U32(r18.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267a208
	if (cr6.eq) goto loc_8267A208;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8267A1F4:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8267a1f4
	if (!cr6.eq) goto loc_8267A1F4;
loc_8267A208:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r24,r18,5752
	r24.s64 = r18.s64 + 5752;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lbz r6,5152(r18)
	ctx.r6.u64 = PPC_LOAD_U8(r18.u32 + 5152);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8267a230
	if (!cr6.eq) goto loc_8267A230;
	// addi r24,r18,5160
	r24.s64 = r18.s64 + 5160;
loc_8267A230:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r15,r11,-112
	r15.s64 = r11.s64 + -112;
	// stb r10,2816(r18)
	PPC_STORE_U8(r18.u32 + 2816, ctx.r10.u8);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// addi r28,r18,2836
	r28.s64 = r18.s64 + 2836;
	// addi r25,r15,4
	r25.s64 = r15.s64 + 4;
	// li r16,1
	r16.s64 = 1;
	// addi r17,r11,-21592
	r17.s64 = r11.s64 + -21592;
	// addi r21,r10,-21612
	r21.s64 = ctx.r10.s64 + -21612;
	// addi r20,r9,-21628
	r20.s64 = ctx.r9.s64 + -21628;
	// addi r23,r8,-21640
	r23.s64 = ctx.r8.s64 + -21640;
	// addi r22,r7,-21652
	r22.s64 = ctx.r7.s64 + -21652;
	// addi r19,r6,-21664
	r19.s64 = ctx.r6.s64 + -21664;
loc_8267A27C:
	// lwz r31,-4(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + -4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82726710
	ctx.lr = 0x8267A288;
	sub_82726710(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267a4f4
	if (!cr6.eq) goto loc_8267A4F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267A29C;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a2c0
	if (cr6.eq) goto loc_8267A2C0;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// blt cr6,0x8267a2b8
	if (cr6.lt) goto loc_8267A2B8;
	// cmplwi cr6,r31,44
	cr6.compare<uint32_t>(r31.u32, 44, xer);
	// bne cr6,0x8267a2c0
	if (!cr6.eq) goto loc_8267A2C0;
loc_8267A2B8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8267a2c4
	goto loc_8267A2C4;
loc_8267A2C0:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8267A2C4:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,388(r28)
	PPC_STORE_U32(r28.u32 + 388, r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A2F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// sth r6,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r6.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822a4a90
	ctx.lr = 0x8267A330;
	sub_822A4A90(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8267a364
	if (cr6.eq) goto loc_8267A364;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8267a364
	if (!cr6.eq) goto loc_8267A364;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827265a0
	ctx.lr = 0x8267A350;
	sub_827265A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a364
	if (cr6.eq) goto loc_8267A364;
	// mr r26,r16
	r26.u64 = r16.u64;
	// stb r16,2816(r18)
	PPC_STORE_U8(r18.u32 + 2816, r16.u8);
loc_8267A364:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267A36C;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a398
	if (!cr6.eq) goto loc_8267A398;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8267a398
	if (!cr6.eq) goto loc_8267A398;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A398:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a3c0
	if (!cr6.eq) goto loc_8267A3C0;
	// cmpwi cr6,r29,27
	cr6.compare<int32_t>(r29.s32, 27, xer);
	// bne cr6,0x8267a3c0
	if (!cr6.eq) goto loc_8267A3C0;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A3C0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a3e8
	if (!cr6.eq) goto loc_8267A3E8;
	// cmpwi cr6,r29,26
	cr6.compare<int32_t>(r29.s32, 26, xer);
	// bne cr6,0x8267a3e8
	if (!cr6.eq) goto loc_8267A3E8;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A3E8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a410
	if (!cr6.eq) goto loc_8267A410;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8267a410
	if (!cr6.eq) goto loc_8267A410;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A410:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a438
	if (!cr6.eq) goto loc_8267A438;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8267a438
	if (!cr6.eq) goto loc_8267A438;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A438:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a460
	if (!cr6.eq) goto loc_8267A460;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8267a460
	if (!cr6.eq) goto loc_8267A460;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A460:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a488
	if (!cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8267a488
	if (!cr6.eq) goto loc_8267A488;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A488:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82679678
	ctx.lr = 0x8267A498;
	sub_82679678(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8267A4A0:
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lbz r7,208(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 208);
	// rlwimi r7,r8,6,25,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0x40) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r7,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, ctx.r7.u8);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r3,208(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 208);
	// rlwimi r3,r11,7,17,24
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r3.u64 & 0xFFFFFFFFFFFF807F);
	// stb r3,208(r5)
	PPC_STORE_U8(ctx.r5.u32 + 208, ctx.r3.u8);
	// beq cr6,0x8267a50c
	if (cr6.eq) goto loc_8267A50C;
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
loc_8267A4D4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
loc_8267A4E8:
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267A4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
loc_8267A4F4:
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// addi r11,r15,364
	r11.s64 = r15.s64 + 364;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8267a27c
	if (cr6.lt) goto loc_8267A27C;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
loc_8267A50C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8267a4d4
	if (cr6.eq) goto loc_8267A4D4;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8267a4e8
	goto loc_8267A4E8;
}

__attribute__((alias("__imp__sub_8267A52C"))) PPC_WEAK_FUNC(sub_8267A52C);
PPC_FUNC_IMPL(__imp__sub_8267A52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A530"))) PPC_WEAK_FUNC(sub_8267A530);
PPC_FUNC_IMPL(__imp__sub_8267A530) {
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
	ctx.lr = 0x8267A538;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-21552
	ctx.r4.s64 = ctx.r9.s64 + -21552;
	// addi r8,r11,28716
	ctx.r8.s64 = r11.s64 + 28716;
	// addi r5,r10,-21572
	ctx.r5.s64 = ctx.r10.s64 + -21572;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,32
	ctx.r6.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8264cc48
	ctx.lr = 0x8267A568;
	sub_8264CC48(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r6,r8,-22524
	ctx.r6.s64 = ctx.r8.s64 + -22524;
	// addi r5,r7,-4092
	ctx.r5.s64 = ctx.r7.s64 + -4092;
	// li r4,74
	ctx.r4.s64 = 74;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r26,0
	r26.s64 = 0;
	// stw r5,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r5.u32);
	// sth r4,2830(r31)
	PPC_STORE_U16(r31.u32 + 2830, ctx.r4.u16);
	// li r3,296
	ctx.r3.s64 = 296;
	// sth r26,2828(r31)
	PPC_STORE_U16(r31.u32 + 2828, r26.u16);
	// addi r11,r31,2820
	r11.s64 = r31.s64 + 2820;
	// bl 0x82130528
	ctx.lr = 0x8267A59C;
	sub_82130528(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r3,2824(r31)
	PPC_STORE_U32(r31.u32 + 2824, ctx.r3.u32);
	// addi r29,r31,2968
	r29.s64 = r31.s64 + 2968;
	// addi r10,r11,-21708
	ctx.r10.s64 = r11.s64 + -21708;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r10,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
	// li r28,31
	r28.s64 = 31;
	// mr r30,r29
	r30.u64 = r29.u64;
	// stw r26,2964(r31)
	PPC_STORE_U32(r31.u32 + 2964, r26.u32);
	// addi r27,r11,5568
	r27.s64 = r11.s64 + 5568;
	// addi r23,r10,3998
	r23.s64 = ctx.r10.s64 + 3998;
loc_8267A5D0:
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267A5E0;
	sub_826311F8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x8267a5d0
	if (!cr0.lt) goto loc_8267A5D0;
	// stw r26,3352(r31)
	PPC_STORE_U32(r31.u32 + 3352, r26.u32);
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634b60
	ctx.lr = 0x8267A5F8;
	sub_82634B60(ctx, base);
	// stb r26,5152(r31)
	PPC_STORE_U8(r31.u32 + 5152, r26.u8);
	// stw r26,5156(r31)
	PPC_STORE_U32(r31.u32 + 5156, r26.u32);
	// addi r3,r31,5160
	ctx.r3.s64 = r31.s64 + 5160;
	// bl 0x82391b18
	ctx.lr = 0x8267A608;
	sub_82391B18(ctx, base);
	// addi r3,r31,5752
	ctx.r3.s64 = r31.s64 + 5752;
	// bl 0x82391b18
	ctx.lr = 0x8267A610;
	sub_82391B18(ctx, base);
	// addi r11,r31,880
	r11.s64 = r31.s64 + 880;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// addi r28,r31,2836
	r28.s64 = r31.s64 + 2836;
	// addi r7,r8,31100
	ctx.r7.s64 = ctx.r8.s64 + 31100;
	// addi r27,r31,3224
	r27.s64 = r31.s64 + 3224;
	// li r30,32
	r30.s64 = 32;
	// lhz r11,884(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r6.u16);
	// lwz r11,31100(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31100);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r11,884(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r24,r11,-23180
	r24.s64 = r11.s64 + -23180;
loc_8267A668:
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x8267A670;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8267a6a0
	if (cr6.eq) goto loc_8267A6A0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x8267A688;
	sub_82633D40(ctx, base);
	// lbz r10,208(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 208);
	// mr r11,r25
	r11.u64 = r25.u64;
	// stw r24,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r24.u32);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,208(r25)
	PPC_STORE_U8(r25.u32 + 208, ctx.r9.u8);
	// b 0x8267a6a4
	goto loc_8267A6A4;
loc_8267A6A0:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8267A6A4:
	// lwz r10,128(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r11,188
	ctx.r10.s64 = r11.s64 + 188;
	// stw r8,128(r28)
	PPC_STORE_U32(r28.u32 + 128, ctx.r8.u32);
	// stwx r11,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, r11.u32);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// stwx r29,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r29.u32);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,128(r27)
	PPC_STORE_U32(r27.u32 + 128, ctx.r5.u32);
	// stwx r26,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, r26.u32);
	// bne 0x8267a668
	if (!cr0.eq) goto loc_8267A668;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8267A700"))) PPC_WEAK_FUNC(sub_8267A700);
PPC_FUNC_IMPL(__imp__sub_8267A700) {
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
	// bl 0x8267a050
	ctx.lr = 0x8267A720;
	sub_8267A050(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a738
	if (cr6.eq) goto loc_8267A738;
	// bl 0x82130588
	ctx.lr = 0x8267A734;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267A738:
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

__attribute__((alias("__imp__sub_8267A750"))) PPC_WEAK_FUNC(sub_8267A750);
PPC_FUNC_IMPL(__imp__sub_8267A750) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8267a1c0
	ctx.lr = 0x8267A76C;
	sub_8267A1C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ab8
	ctx.lr = 0x8267A774;
	sub_822A4AB8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8267a794
	if (cr6.eq) goto loc_8267A794;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,2784(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2784, temp.u32);
	// stfs f0,2788(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2788, temp.u32);
	// stfs f0,2792(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2792, temp.u32);
	// stfs f0,2796(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2796, temp.u32);
loc_8267A794:
	// lwz r11,256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// addi r31,r30,256
	r31.s64 = r30.s64 + 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,5152(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 5152);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267a7d0
	if (cr6.eq) goto loc_8267A7D0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28716
	ctx.r4.s64 = r11.s64 + 28716;
	// b 0x8267a7dc
	goto loc_8267A7DC;
loc_8267A7D0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,29364
	ctx.r4.s64 = r11.s64 + 29364;
loc_8267A7DC:
	// bl 0x8262ffe0
	ctx.lr = 0x8267A7E0;
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
	ctx.lr = 0x8267A7F4;
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

__attribute__((alias("__imp__sub_8267A80C"))) PPC_WEAK_FUNC(sub_8267A80C);
PPC_FUNC_IMPL(__imp__sub_8267A80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A810"))) PPC_WEAK_FUNC(sub_8267A810);
PPC_FUNC_IMPL(__imp__sub_8267A810) {
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
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// beq cr6,0x8267a87c
	if (cr6.eq) goto loc_8267A87C;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21504
	ctx.r4.s64 = ctx.r10.s64 + -21504;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,496(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r8,-21532
	ctx.r4.s64 = ctx.r8.s64 + -21532;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267A864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387b90
	ctx.lr = 0x8267A868;
	sub_82387B90(ctx, base);
	// lwz r5,5156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 5156);
	// addi r4,r31,5752
	ctx.r4.s64 = r31.s64 + 5752;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// bl 0x8238ca70
	ctx.lr = 0x8267A878;
	sub_8238CA70(ctx, base);
	// b 0x8267a8a8
	goto loc_8267A8A8;
loc_8267A87C:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21552
	ctx.r4.s64 = ctx.r10.s64 + -21552;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,496(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r8,-21572
	ctx.r4.s64 = ctx.r8.s64 + -21572;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267A8A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267A8A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267A8B0;
	sub_8267A750(ctx, base);
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
	ctx.lr = 0x8267A8C8;
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

__attribute__((alias("__imp__sub_8267A8DC"))) PPC_WEAK_FUNC(sub_8267A8DC);
PPC_FUNC_IMPL(__imp__sub_8267A8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A8E0"))) PPC_WEAK_FUNC(sub_8267A8E0);
PPC_FUNC_IMPL(__imp__sub_8267A8E0) {
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
	ctx.lr = 0x8267A8E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267aa44
	if (cr6.eq) goto loc_8267AA44;
	// lbz r11,2833(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2833);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a918
	if (cr6.eq) goto loc_8267A918;
	// li r11,0
	r11.s64 = 0;
	// stb r11,2833(r31)
	PPC_STORE_U8(r31.u32 + 2833, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8267A918:
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203240
	ctx.lr = 0x8267A924;
	sub_82203240(ctx, base);
	// addi r11,r3,806
	r11.s64 = ctx.r3.s64 + 806;
	// addi r7,r31,2784
	ctx.r7.s64 = r31.s64 + 2784;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82727010
	ctx.lr = 0x8267A944;
	sub_82727010(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267aa44
	if (cr6.eq) goto loc_8267AA44;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203240
	ctx.lr = 0x8267A958;
	sub_82203240(ctx, base);
	// addi r11,r3,806
	r11.s64 = ctx.r3.s64 + 806;
	// addi r6,r31,5160
	ctx.r6.s64 = r31.s64 + 5160;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82726870
	ctx.lr = 0x8267A974;
	sub_82726870(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x8267A980;
	sub_82631F88(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8267a9bc
	if (!cr6.gt) goto loc_8267A9BC;
	// mr r29,r26
	r29.u64 = r26.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8267A994:
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8267a994
	if (!cr0.eq) goto loc_8267A994;
loc_8267A9BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267A9C4;
	sub_8267A750(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r26,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r26.u32);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A9DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267A9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8267aa38
	if (cr6.eq) goto loc_8267AA38;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AA08;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AA18;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AA1C;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AA2C;
	sub_8260B990(ctx, base);
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8267AA38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82679d08
	ctx.lr = 0x8267AA40;
	sub_82679D08(ctx, base);
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
loc_8267AA44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267AA4C"))) PPC_WEAK_FUNC(sub_8267AA4C);
PPC_FUNC_IMPL(__imp__sub_8267AA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267AA50"))) PPC_WEAK_FUNC(sub_8267AA50);
PPC_FUNC_IMPL(__imp__sub_8267AA50) {
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// lwz r11,3360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3360);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267AA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8267aad4
	if (!cr6.eq) goto loc_8267AAD4;
	// bl 0x82387b90
	ctx.lr = 0x8267AA84;
	sub_82387B90(ctx, base);
	// lwz r11,5156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5156);
	// addi r4,r31,5160
	ctx.r4.s64 = r31.s64 + 5160;
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// bl 0x8238ca70
	ctx.lr = 0x8267AA94;
	sub_8238CA70(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AAA4;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AAA8;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AAB8;
	sub_8260B990(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267AAC0;
	sub_8267A750(ctx, base);
	// lwz r8,672(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267AAD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267AAD4:
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

__attribute__((alias("__imp__sub_8267AAE8"))) PPC_WEAK_FUNC(sub_8267AAE8);
PPC_FUNC_IMPL(__imp__sub_8267AAE8) {
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
	// bl 0x8267a750
	ctx.lr = 0x8267AB00;
	sub_8267A750(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AB10;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AB14;
	sub_822A5578(ctx, base);
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AB24;
	sub_8260B990(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AB38;
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

__attribute__((alias("__imp__sub_8267AB4C"))) PPC_WEAK_FUNC(sub_8267AB4C);
PPC_FUNC_IMPL(__imp__sub_8267AB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267AB50"))) PPC_WEAK_FUNC(sub_8267AB50);
PPC_FUNC_IMPL(__imp__sub_8267AB50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x8267AB58;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac64
	if (!cr6.eq) goto loc_8267AC64;
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8267ae40
	if (cr6.gt) goto loc_8267AE40;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-21616
	r12.s64 = r12.s64 + -21616;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267ACE0;
	case 1:
		goto loc_8267AD9C;
	case 2:
		goto loc_8267AE40;
	case 3:
		goto loc_8267AE40;
	case 4:
		goto loc_8267AE40;
	case 5:
		goto loc_8267AE40;
	case 6:
		goto loc_8267AE40;
	case 7:
		goto loc_8267AC70;
	case 8:
		goto loc_8267ABB4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-21280(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21280);
	// lwz r19,-21092(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21092);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-21392(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21392);
	// lwz r19,-21580(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21580);
loc_8267ABB4:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac58
	if (!cr6.eq) goto loc_8267AC58;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
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
	ctx.lr = 0x8267ABE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267ac58
	if (cr6.eq) goto loc_8267AC58;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267ABFC;
	sub_821E6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8267AC04;
	sub_82203240(ctx, base);
	// addi r9,r3,806
	ctx.r9.s64 = ctx.r3.s64 + 806;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r6,r11,645
	ctx.r6.s64 = r11.s64 + 645;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,17268(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AC38;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AC3C;
	sub_822A5578(ctx, base);
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x8267AC44;
	sub_822A4DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267aae8
	ctx.lr = 0x8267AC4C;
	sub_8267AAE8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AC58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267AC64;
	sub_821E6800(ctx, base);
loc_8267AC64:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AC70:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267acd4
	if (!cr6.eq) goto loc_8267ACD4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AC88;
	sub_821E6800(ctx, base);
	// lis r10,-32152
	ctx.r10.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-25216
	ctx.r4.s64 = ctx.r10.s64 + -25216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2f90
	ctx.lr = 0x8267AC9C;
	sub_821C2F90(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r9,-21444
	ctx.r6.s64 = ctx.r9.s64 + -21444;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r8,-21472
	ctx.r5.s64 = ctx.r8.s64 + -21472;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634ec8
	ctx.lr = 0x8267ACD4;
	sub_82634EC8(ctx, base);
loc_8267ACD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267ACE0:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac58
	if (!cr6.eq) goto loc_8267AC58;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
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
	ctx.lr = 0x8267AD0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267ac58
	if (cr6.eq) goto loc_8267AC58;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AD24;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82679d90
	ctx.lr = 0x8267AD2C;
	sub_82679D90(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stb r29,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r29.u8);
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r28,r10,28156
	r28.s64 = ctx.r10.s64 + 28156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x8267AD50;
	sub_8262FFE0(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r28.u32);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AD68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AD78;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AD7C;
	sub_822A5578(ctx, base);
	// lwz r6,116(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AD8C;
	sub_8260B990(ctx, base);
	// stb r29,2833(r31)
	PPC_STORE_U8(r31.u32 + 2833, r29.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AD9C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267ADA8;
	sub_826304B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267ADB0;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267adcc
	if (cr6.eq) goto loc_8267ADCC;
	// bl 0x82387b90
	ctx.lr = 0x8267ADC0;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x8267ADC8;
	sub_8238B070(ctx, base);
	// b 0x8267add8
	goto loc_8267ADD8;
loc_8267ADCC:
	// bl 0x82387b90
	ctx.lr = 0x8267ADD0;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x8267ADD8;
	sub_8238B080(ctx, base);
loc_8267ADD8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,5160
	ctx.r3.s64 = r31.s64 + 5160;
	// bl 0x82391758
	ctx.lr = 0x8267ADE4;
	sub_82391758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lbz r10,5152(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267ae14
	if (!cr6.eq) goto loc_8267AE14;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267ae14
	if (cr6.eq) goto loc_8267AE14;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AE14;
	sub_826304B0(ctx, base);
loc_8267AE14:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267AE20;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AE34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AE40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264b668
	ctx.lr = 0x8267AE48;
	sub_8264B668(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267AE50"))) PPC_WEAK_FUNC(sub_8267AE50);
PPC_FUNC_IMPL(__imp__sub_8267AE50) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267aebc
	if (cr6.eq) goto loc_8267AEBC;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267ae8c
	if (cr6.eq) goto loc_8267AE8C;
	// bl 0x826537d0
	ctx.lr = 0x8267AE78;
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
loc_8267AE8C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267AE98;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AEA4;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267af38
	goto loc_8267AF38;
loc_8267AEBC:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8267AEC4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267aed4
	if (cr6.lt) goto loc_8267AED4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8267AED4:
	// addi r11,r11,248
	r11.s64 = r11.s64 + 248;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AEF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8267af2c
	if (cr6.eq) goto loc_8267AF2C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AF08;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AF14;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AF28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267af38
	goto loc_8267AF38;
loc_8267AF2C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267AF38;
	sub_821E6800(ctx, base);
loc_8267AF38:
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

__attribute__((alias("__imp__sub_8267AF50"))) PPC_WEAK_FUNC(sub_8267AF50);
PPC_FUNC_IMPL(__imp__sub_8267AF50) {
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
	// addi r11,r4,-47
	r11.s64 = ctx.r4.s64 + -47;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x8267b050
	if (cr6.gt) goto loc_8267B050;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-20600
	r12.s64 = r12.s64 + -20600;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267AFB0;
	case 1:
		goto loc_8267AFB0;
	case 2:
		goto loc_8267AFB0;
	case 3:
		goto loc_8267AFB0;
	case 4:
		goto loc_8267B050;
	case 5:
		goto loc_8267B050;
	case 6:
		goto loc_8267B050;
	case 7:
		goto loc_8267B050;
	case 8:
		goto loc_8267AFC8;
	case 9:
		goto loc_8267B00C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20536);
	// lwz r19,-20468(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20468);
loc_8267AFB0:
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
loc_8267AFC8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AFD4;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AFE0;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AFF4;
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
loc_8267B00C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267B018;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B024;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B038;
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
loc_8267B050:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267B058;
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
}

__attribute__((alias("__imp__sub_8267B06C"))) PPC_WEAK_FUNC(sub_8267B06C);
PPC_FUNC_IMPL(__imp__sub_8267B06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B070"))) PPC_WEAK_FUNC(sub_8267B070);
PPC_FUNC_IMPL(__imp__sub_8267B070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r5,1896(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1896, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267B080"))) PPC_WEAK_FUNC(sub_8267B080);
PPC_FUNC_IMPL(__imp__sub_8267B080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
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
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8267B09C"))) PPC_WEAK_FUNC(sub_8267B09C);
PPC_FUNC_IMPL(__imp__sub_8267B09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B0A0"))) PPC_WEAK_FUNC(sub_8267B0A0);
PPC_FUNC_IMPL(__imp__sub_8267B0A0) {
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
	// addi r11,r4,-47
	r11.s64 = ctx.r4.s64 + -47;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x8267b188
	if (cr6.gt) goto loc_8267B188;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-20264
	r12.s64 = r12.s64 + -20264;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267B12C;
	case 1:
		goto loc_8267B12C;
	case 2:
		goto loc_8267B12C;
	case 3:
		goto loc_8267B12C;
	case 4:
		goto loc_8267B188;
	case 5:
		goto loc_8267B188;
	case 6:
		goto loc_8267B188;
	case 7:
		goto loc_8267B188;
	case 8:
		goto loc_8267B100;
	case 9:
		goto loc_8267B144;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20224(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20224);
	// lwz r19,-20156(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20156);
loc_8267B100:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267B10C;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B118;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267B12C:
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
loc_8267B144:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267B150;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B15C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B170;
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
loc_8267B188:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267B190;
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
}

__attribute__((alias("__imp__sub_8267B1A4"))) PPC_WEAK_FUNC(sub_8267B1A4);
PPC_FUNC_IMPL(__imp__sub_8267B1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B1A8"))) PPC_WEAK_FUNC(sub_8267B1A8);
PPC_FUNC_IMPL(__imp__sub_8267B1A8) {
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
	// bl 0x822150d8
	ctx.lr = 0x8267B1B8;
	sub_822150D8(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267B1BC;
	sub_82216648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267B1CC"))) PPC_WEAK_FUNC(sub_8267B1CC);
PPC_FUNC_IMPL(__imp__sub_8267B1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B1D0"))) PPC_WEAK_FUNC(sub_8267B1D0);
PPC_FUNC_IMPL(__imp__sub_8267B1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267B1D8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-29360
	ctx.r3.s64 = r11.s64 + -29360;
	// bl 0x821fa230
	ctx.lr = 0x8267B1F0;
	sub_821FA230(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,1216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,18508(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18508);
	// bl 0x826b96c8
	ctx.lr = 0x8267B210;
	sub_826B96C8(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r28,r11,-20892
	r28.s64 = r11.s64 + -20892;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x8267B228;
	sub_8268E5B8(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8267b288
	if (cr6.lt) goto loc_8267B288;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f11,32(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 32);
loc_8267B258:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fmul f8,f0,f11
	ctx.f8.f64 = f0.f64 * ctx.f11.f64;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// fmadd f7,f8,f31,f9
	ctx.f7.f64 = ctx.f8.f64 * f31.f64 + ctx.f9.f64;
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f6.u64);
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// ble cr6,0x8267b258
	if (!cr6.gt) goto loc_8267B258;
loc_8267B288:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82217b70
	ctx.lr = 0x8267B2A4;
	sub_82217B70(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r10,-20912
	ctx.r3.s64 = ctx.r10.s64 + -20912;
	// bl 0x82218838
	ctx.lr = 0x8267B2B4;
	sub_82218838(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x8267B2C0;
	sub_8268E5B8(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-20932
	ctx.r3.s64 = ctx.r9.s64 + -20932;
	// bl 0x82218838
	ctx.lr = 0x8267B2D0;
	sub_82218838(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r7,1456(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1456);
	// addi r3,r31,1456
	ctx.r3.s64 = r31.s64 + 1456;
	// addi r30,r8,31444
	r30.s64 = ctx.r8.s64 + 31444;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267B2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1680(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1680);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1680
	ctx.r3.s64 = r31.s64 + 1680;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267B308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,672(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B328"))) PPC_WEAK_FUNC(sub_8267B328);
PPC_FUNC_IMPL(__imp__sub_8267B328) {
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
	// bl 0x822166e8
	ctx.lr = 0x8267B340;
	sub_822166E8(ctx, base);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8262fff0
	ctx.lr = 0x8267B34C;
	sub_8262FFF0(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8267B350;
	sub_82215A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267b1d0
	ctx.lr = 0x8267B358;
	sub_8267B1D0(ctx, base);
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

__attribute__((alias("__imp__sub_8267B36C"))) PPC_WEAK_FUNC(sub_8267B36C);
PPC_FUNC_IMPL(__imp__sub_8267B36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B370"))) PPC_WEAK_FUNC(sub_8267B370);
PPC_FUNC_IMPL(__imp__sub_8267B370) {
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
	ctx.lr = 0x8267B378;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-19384
	ctx.r4.s64 = ctx.r9.s64 + -19384;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-19408
	ctx.r5.s64 = ctx.r10.s64 + -19408;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267B3A8;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r7,r8,-20212
	ctx.r7.s64 = ctx.r8.s64 + -20212;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r26,1008
	r31.s64 = r26.s64 + 1008;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
	// li r30,9
	r30.s64 = 9;
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// addi r27,r10,3998
	r27.s64 = ctx.r10.s64 + 3998;
loc_8267B3CC:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B3DC;
	sub_826311F8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bge 0x8267b3cc
	if (!cr0.lt) goto loc_8267B3CC;
	// addi r28,r26,848
	r28.s64 = r26.s64 + 848;
	// addi r31,r26,992
	r31.s64 = r26.s64 + 992;
	// addi r30,r26,1016
	r30.s64 = r26.s64 + 1016;
	// li r29,4
	r29.s64 = 4;
loc_8267B3F8:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8267B400;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267b418
	if (cr6.eq) goto loc_8267B418;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82633d40
	ctx.lr = 0x8267B414;
	sub_82633D40(ctx, base);
	// b 0x8267b41c
	goto loc_8267B41C;
loc_8267B418:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8267B41C:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r7,r30,-8
	ctx.r7.s64 = r30.s64 + -8;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r6.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r30.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x8267b3f8
	if (!cr0.eq) goto loc_8267B3F8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,31392
	ctx.r4.s64 = r11.s64 + 31392;
	// addi r3,r26,672
	ctx.r3.s64 = r26.s64 + 672;
	// bl 0x826347f0
	ctx.lr = 0x8267B49C;
	sub_826347F0(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267B4A8"))) PPC_WEAK_FUNC(sub_8267B4A8);
PPC_FUNC_IMPL(__imp__sub_8267B4A8) {
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
	ctx.lr = 0x8267B4B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r28,992
	r31.s64 = r28.s64 + 992;
	// addi r10,r11,-20212
	ctx.r10.s64 = r11.s64 + -20212;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// li r29,0
	r29.s64 = 0;
loc_8267B4D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267b4f4
	if (cr6.eq) goto loc_8267B4F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_8267B4F4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8267b4d0
	if (!cr0.eq) goto loc_8267B4D0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r28,1088
	r11.s64 = r28.s64 + 1088;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_8267B510:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8267b510
	if (!cr0.lt) goto loc_8267B510;
	// lhz r11,886(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 886);
	// addi r31,r28,672
	r31.s64 = r28.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b538
	if (cr6.eq) goto loc_8267B538;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267B538;
	sub_82130588(ctx, base);
loc_8267B538:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b54c
	if (cr6.eq) goto loc_8267B54C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267B54C;
	sub_82130588(ctx, base);
loc_8267B54C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267B554;
	sub_82633B00(ctx, base);
	// addi r3,r28,496
	ctx.r3.s64 = r28.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267B55C;
	sub_82633B00(ctx, base);
	// addi r3,r28,256
	ctx.r3.s64 = r28.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267B564;
	sub_82633B00(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267B56C;
	sub_82633B00(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B574"))) PPC_WEAK_FUNC(sub_8267B574);
PPC_FUNC_IMPL(__imp__sub_8267B574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B578"))) PPC_WEAK_FUNC(sub_8267B578);
PPC_FUNC_IMPL(__imp__sub_8267B578) {
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
	ctx.lr = 0x8267B580;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// beq cr6,0x8267b5c0
	if (cr6.eq) goto loc_8267B5C0;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8267B5AC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8267b5ac
	if (!cr6.eq) goto loc_8267B5AC;
loc_8267B5C0:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r30,r28,992
	r30.s64 = r28.s64 + 992;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// li r29,4
	r29.s64 = 4;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
loc_8267B5DC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267b61c
	if (cr6.eq) goto loc_8267B61C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r7,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r7.u32);
loc_8267B61C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8267b5dc
	if (!cr0.eq) goto loc_8267B5DC;
	// lwz r11,672(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// addi r3,r28,672
	ctx.r3.s64 = r28.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267B65C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B664"))) PPC_WEAK_FUNC(sub_8267B664);
PPC_FUNC_IMPL(__imp__sub_8267B664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B668"))) PPC_WEAK_FUNC(sub_8267B668);
PPC_FUNC_IMPL(__imp__sub_8267B668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,852(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 852);
	// addi r11,r3,848
	r11.s64 = ctx.r3.s64 + 848;
	// lwz r8,848(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x8267b6a0
	if (cr6.eq) goto loc_8267B6A0;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_8267B68C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8267b68c
	if (!cr6.eq) goto loc_8267B68C;
loc_8267B6A0:
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// srawi r6,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 2;
	// li r4,8
	ctx.r4.s64 = 8;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r10,992(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 992);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
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
	// lwz r6,996(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 996);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r8,r5,1
	ctx.r8.s64 = ctx.r5.s64 + 1;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r5,1000(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1000);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
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
	// lwz r5,1004(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1004);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r3,-12640(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12640);
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

__attribute__((alias("__imp__sub_8267B748"))) PPC_WEAK_FUNC(sub_8267B748);
PPC_FUNC_IMPL(__imp__sub_8267B748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267B750;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-18532
	ctx.r4.s64 = ctx.r9.s64 + -18532;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-18552
	ctx.r5.s64 = ctx.r10.s64 + -18552;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267B780;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-19356
	ctx.r5.s64 = ctx.r8.s64 + -19356;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// bl 0x826349f0
	ctx.lr = 0x8267B7D0;
	sub_826349F0(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r8,31444
	r30.s64 = ctx.r8.s64 + 31444;
	// lwz r4,31444(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31444);
	// bl 0x82633d40
	ctx.lr = 0x8267B7EC;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r25,r7,-20868
	r25.s64 = ctx.r7.s64 + -20868;
	// addi r24,r6,5568
	r24.s64 = ctx.r6.s64 + 5568;
	// stw r25,1248(r31)
	PPC_STORE_U32(r31.u32 + 1248, r25.u32);
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r24,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B814;
	sub_826311F8(ctx, base);
	// addi r26,r31,1472
	r26.s64 = r31.s64 + 1472;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267B828;
	sub_82633D40(ctx, base);
	// stw r25,1472(r31)
	PPC_STORE_U32(r31.u32 + 1472, r25.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// stw r24,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r24.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B840;
	sub_826311F8(ctx, base);
	// addi r24,r31,672
	r24.s64 = r31.s64 + 672;
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,31436
	ctx.r4.s64 = ctx.r4.s64 + 31436;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267B858;
	sub_826347F0(ctx, base);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267B88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267B898;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-20016
	ctx.r4.s64 = ctx.r4.s64 + -20016;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267B8AC;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267B8B8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267b8b8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267B8B8;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267B8DC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267b8dc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267B8DC;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1436
	ctx.r10.s64 = r31.s64 + 1436;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r31,1660
	ctx.r9.s64 = r31.s64 + 1660;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stwx r28,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r28.u32);
	// lwz r10,1436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1436);
	// lhz r11,1440(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1440);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1440(r31)
	PPC_STORE_U16(r31.u32 + 1440, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,1660(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1660);
	// lhz r11,1664(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1664);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1664(r31)
	PPC_STORE_U16(r31.u32 + 1664, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r9.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8267B984"))) PPC_WEAK_FUNC(sub_8267B984);
PPC_FUNC_IMPL(__imp__sub_8267B984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B988"))) PPC_WEAK_FUNC(sub_8267B988);
PPC_FUNC_IMPL(__imp__sub_8267B988) {
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
	// bl 0x8267b4a8
	ctx.lr = 0x8267B9A8;
	sub_8267B4A8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b9c0
	if (cr6.eq) goto loc_8267B9C0;
	// bl 0x82130588
	ctx.lr = 0x8267B9BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267B9C0:
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

__attribute__((alias("__imp__sub_8267B9D8"))) PPC_WEAK_FUNC(sub_8267B9D8);
PPC_FUNC_IMPL(__imp__sub_8267B9D8) {
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
	ctx.lr = 0x8267B9E0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267BA10;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821fd7c0
	ctx.lr = 0x8267BA24;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r11.u8);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// stw r8,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r8.u32);
	// lwz r11,228(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267bb50
	if (cr6.eq) goto loc_8267BB50;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267BA5C;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267bb50
	if (cr6.eq) goto loc_8267BB50;
	// lwz r29,1216(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267BA70;
	sub_826CD180(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8267bb08
	if (cr6.eq) goto loc_8267BB08;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267bae4
	if (cr6.eq) goto loc_8267BAE4;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x8267bab0
	if (cr6.eq) goto loc_8267BAB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r30,10
	ctx.r4.s64 = r30.s64 + 10;
	// lwz r30,-10244(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x8267BAA4;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// b 0x8267bb44
	goto loc_8267BB44;
loc_8267BAB0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267BAC4;
	sub_826B7AB0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r5,60(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-21312
	ctx.r4.s64 = ctx.r9.s64 + -21312;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x82218788
	ctx.lr = 0x8267BAE0;
	sub_82218788(ctx, base);
	// b 0x8267bb50
	goto loc_8267BB50;
loc_8267BAE4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267BAF0;
	sub_826B7940(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r30,10
	ctx.r5.s64 = r30.s64 + 10;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// b 0x8267bb4c
	goto loc_8267BB4C;
loc_8267BB08:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r7,r11,-17856
	ctx.r7.s64 = r11.s64 + -17856;
	// addi r5,r10,10372
	ctx.r5.s64 = ctx.r10.s64 + 10372;
	// addi r6,r30,10
	ctx.r6.s64 = r30.s64 + 10;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x8267BB28;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r30,-10244(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x8267BB3C;
	sub_82218310(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r8,-21312
	ctx.r4.s64 = ctx.r8.s64 + -21312;
loc_8267BB44:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8267BB4C:
	// bl 0x822183b0
	ctx.lr = 0x8267BB50;
	sub_822183B0(ctx, base);
loc_8267BB50:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r10,1664(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1664);
	// addi r3,r31,1664
	ctx.r3.s64 = r31.s64 + 1664;
	// addi r30,r11,31412
	r30.s64 = r11.s64 + 31412;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267BB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1888(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1888
	ctx.r3.s64 = r31.s64 + 1888;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267BB88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BB9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267BBA4"))) PPC_WEAK_FUNC(sub_8267BBA4);
PPC_FUNC_IMPL(__imp__sub_8267BBA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267BBA8"))) PPC_WEAK_FUNC(sub_8267BBA8);
PPC_FUNC_IMPL(__imp__sub_8267BBA8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8267BBB0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// bl 0x823db670
	ctx.lr = 0x8267BBE4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd7c0
	ctx.lr = 0x8267BBF8;
	sub_821FD7C0(ctx, base);
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r29,0
	r29.s64 = 0;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r31,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r31.u32);
	// stb r29,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r29.u8);
	// stw r29,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r29.u32);
	// stw r8,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r8.u32);
	// beq cr6,0x8267bd40
	if (cr6.eq) goto loc_8267BD40;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267BC30;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267bd40
	if (cr6.eq) goto loc_8267BD40;
	// lwz r23,1216(r24)
	r23.u64 = PPC_LOAD_U32(r24.u32 + 1216);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267BC44;
	sub_826CD180(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r24,1696
	r31.s64 = r24.s64 + 1696;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r27,r24,1728
	r27.s64 = r24.s64 + 1728;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r25,r11,-17836
	r25.s64 = r11.s64 + -17836;
	// addi r26,r10,-21312
	r26.s64 = ctx.r10.s64 + -21312;
loc_8267BC6C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267bcec
	if (cr6.eq) goto loc_8267BCEC;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x8267bd20
	if (!cr6.eq) goto loc_8267BD20;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7ab0
	ctx.lr = 0x8267BC90;
	sub_826B7AB0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r22,60(r30)
	r22.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// bl 0x82217820
	ctx.lr = 0x8267BCAC;
	sub_82217820(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r6,r22,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82217820
	ctx.lr = 0x8267BCC4;
	sub_82217820(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267BCDC;
	sub_82137A08(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8267bd14
	goto loc_8267BD14;
loc_8267BCEC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267BCF8;
	sub_826B7940(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r30,10
	ctx.r5.s64 = r30.s64 + 10;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8267BD08;
	sub_822183B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8267BD14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267BD20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267BD20:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,64
	r27.s64 = r27.s64 + 64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x8267bc6c
	if (cr6.lt) goto loc_8267BC6C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r24,1456
	ctx.r3.s64 = r24.s64 + 1456;
	// bl 0x8262fff0
	ctx.lr = 0x8267BD40;
	sub_8262FFF0(ctx, base);
loc_8267BD40:
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r3,r24,672
	ctx.r3.s64 = r24.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267BD54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8267BD60"))) PPC_WEAK_FUNC(sub_8267BD60);
PPC_FUNC_IMPL(__imp__sub_8267BD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267BD68;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-17000
	ctx.r4.s64 = ctx.r9.s64 + -17000;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-17016
	ctx.r5.s64 = ctx.r10.s64 + -17016;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267BD98;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-17820
	ctx.r5.s64 = ctx.r8.s64 + -17820;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r30,1
	r30.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-328
	ctx.r4.s64 = ctx.r10.s64 + -328;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826349f0
	ctx.lr = 0x8267BDE8;
	sub_826349F0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,3998
	ctx.r4.s64 = ctx.r9.s64 + 3998;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267BE00;
	sub_82633D40(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r24,r8,31412
	r24.s64 = ctx.r8.s64 + 31412;
	// lwz r4,31412(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31412);
	// bl 0x82633d40
	ctx.lr = 0x8267BE1C;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r23,r7,-20868
	r23.s64 = ctx.r7.s64 + -20868;
	// addi r22,r6,5568
	r22.s64 = ctx.r6.s64 + 5568;
	// stw r23,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r23.u32);
	// addi r26,r31,1664
	r26.s64 = r31.s64 + 1664;
	// lwz r4,4(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// stw r22,1664(r31)
	PPC_STORE_U32(r31.u32 + 1664, r22.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267BE44;
	sub_826311F8(ctx, base);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267BE58;
	sub_82633D40(ctx, base);
	// stw r23,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r23.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// addi r24,r31,1888
	r24.s64 = r31.s64 + 1888;
	// stw r22,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, r22.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267BE70;
	sub_826311F8(ctx, base);
	// stw r30,1896(r31)
	PPC_STORE_U32(r31.u32 + 1896, r30.u32);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,31404
	ctx.r4.s64 = ctx.r4.s64 + 31404;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x826347f0
	ctx.lr = 0x8267BE88;
	sub_826347F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// stb r3,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r3.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BEC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,1896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// bl 0x8262fff0
	ctx.lr = 0x8267BED0;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-17960
	ctx.r4.s64 = ctx.r4.s64 + -17960;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267BEE4;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267BEF0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267bef0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267BEF0;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267BF14:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267bf14
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267BF14;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,1644
	r11.s64 = r31.s64 + 1644;
	// addi r11,r31,1868
	r11.s64 = r31.s64 + 1868;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r4.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r11,1648(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lhz r11,1872(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1872);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,1868(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1868);
	// sth r4,1872(r31)
	PPC_STORE_U16(r31.u32 + 1872, ctx.r4.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8267BFCC"))) PPC_WEAK_FUNC(sub_8267BFCC);
PPC_FUNC_IMPL(__imp__sub_8267BFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267BFD0"))) PPC_WEAK_FUNC(sub_8267BFD0);
PPC_FUNC_IMPL(__imp__sub_8267BFD0) {
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
	// bl 0x82646dc8
	ctx.lr = 0x8267BFF0;
	sub_82646DC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c008
	if (cr6.eq) goto loc_8267C008;
	// bl 0x82130588
	ctx.lr = 0x8267C004;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267C008:
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

__attribute__((alias("__imp__sub_8267C020"))) PPC_WEAK_FUNC(sub_8267C020);
PPC_FUNC_IMPL(__imp__sub_8267C020) {
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
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,1896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// bl 0x8262fff0
	ctx.lr = 0x8267C048;
	sub_8262FFF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267b9d8
	ctx.lr = 0x8267C050;
	sub_8267B9D8(ctx, base);
	// lwz r11,1896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x8267c07c
	if (!cr6.eq) goto loc_8267C07C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8267c08c
	goto loc_8267C08C;
loc_8267C07C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8267C08C:
	// lwz r9,1248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C0BC;
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

__attribute__((alias("__imp__sub_8267C0D4"))) PPC_WEAK_FUNC(sub_8267C0D4);
PPC_FUNC_IMPL(__imp__sub_8267C0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C0D8"))) PPC_WEAK_FUNC(sub_8267C0D8);
PPC_FUNC_IMPL(__imp__sub_8267C0D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8267C0E0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r4,r9,-16144
	ctx.r4.s64 = ctx.r9.s64 + -16144;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267C114;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-16948
	ctx.r5.s64 = ctx.r8.s64 + -16948;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r27,r31,1008
	r27.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826349f0
	ctx.lr = 0x8267C164;
	sub_826349F0(ctx, base);
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267C178;
	sub_82633D40(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r25,r31,1456
	r25.s64 = r31.s64 + 1456;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-16976
	ctx.r4.s64 = ctx.r8.s64 + -16976;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82634908
	ctx.lr = 0x8267C194;
	sub_82634908(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// addi r23,r31,1696
	r23.s64 = r31.s64 + 1696;
	// addi r6,r7,-18508
	ctx.r6.s64 = ctx.r7.s64 + -18508;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r23
	r30.u64 = r23.u64;
	// stw r6,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, ctx.r6.u32);
	// li r26,3
	r26.s64 = 3;
	// addi r24,r11,5568
	r24.s64 = r11.s64 + 5568;
loc_8267C1B4:
	// stw r24,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r24.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267C1C4;
	sub_826311F8(ctx, base);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x8267c1b4
	if (!cr0.lt) goto loc_8267C1B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,31428
	ctx.r4.s64 = r11.s64 + 31428;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267C1E8;
	sub_826347F0(ctx, base);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267C220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267C22C;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-17496
	ctx.r4.s64 = ctx.r4.s64 + -17496;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267C240;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267C250:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267c250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267C250;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267C274:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267c274
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267C274;
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267C2BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r31,1644
	r11.s64 = r31.s64 + 1644;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// addi r8,r31,1704
	ctx.r8.s64 = r31.s64 + 1704;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// addi r7,r31,1712
	ctx.r7.s64 = r31.s64 + 1712;
	// addi r6,r31,1720
	ctx.r6.s64 = r31.s64 + 1720;
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r9,1648(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r5.u16);
	// stwx r23,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r23.u32);
	// lwz r9,1644(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r5,1648(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// rotlwi r11,r5,2
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// sth r10,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r10.u16);
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r11,1648(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r9.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r7,1648(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// sth r5,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r5.u16);
	// stwx r6,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r6.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8267C378"))) PPC_WEAK_FUNC(sub_8267C378);
PPC_FUNC_IMPL(__imp__sub_8267C378) {
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
	// bl 0x82646e80
	ctx.lr = 0x8267C398;
	sub_82646E80(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c3b0
	if (cr6.eq) goto loc_8267C3B0;
	// bl 0x82130588
	ctx.lr = 0x8267C3AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267C3B0:
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

__attribute__((alias("__imp__sub_8267C3C8"))) PPC_WEAK_FUNC(sub_8267C3C8);
PPC_FUNC_IMPL(__imp__sub_8267C3C8) {
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
	ctx.lr = 0x8267C3D0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267C400;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8267C414;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c4d0
	if (cr6.eq) goto loc_8267C4D0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267C44C;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267c498
	if (cr6.eq) goto loc_8267C498;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8267c498
	if (!cr6.gt) goto loc_8267C498;
	// lwz r11,1008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r9,-16088
	ctx.r4.s64 = ctx.r9.s64 + -16088;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267c4dc
	goto loc_8267C4DC;
loc_8267C498:
	// lwz r11,1008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r9,-16124
	ctx.r4.s64 = ctx.r9.s64 + -16124;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C4CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267c4dc
	goto loc_8267C4DC;
loc_8267C4D0:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267C4DC;
	sub_8262FFF0(ctx, base);
loc_8267C4DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267bba8
	ctx.lr = 0x8267C4E4;
	sub_8267BBA8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267C508"))) PPC_WEAK_FUNC(sub_8267C508);
PPC_FUNC_IMPL(__imp__sub_8267C508) {
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
	// bl 0x82630580
	ctx.lr = 0x8267C518;
	sub_82630580(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267C524;
	sub_82203BD0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C534"))) PPC_WEAK_FUNC(sub_8267C534);
PPC_FUNC_IMPL(__imp__sub_8267C534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C538"))) PPC_WEAK_FUNC(sub_8267C538);
PPC_FUNC_IMPL(__imp__sub_8267C538) {
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
	// cmpwi cr6,r4,17
	cr6.compare<int32_t>(ctx.r4.s32, 17, xer);
	// beq cr6,0x8267c594
	if (cr6.eq) goto loc_8267C594;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267c57c
	if (!cr6.eq) goto loc_8267C57C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C568;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C57C:
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
loc_8267C594:
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

__attribute__((alias("__imp__sub_8267C5AC"))) PPC_WEAK_FUNC(sub_8267C5AC);
PPC_FUNC_IMPL(__imp__sub_8267C5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C5B0"))) PPC_WEAK_FUNC(sub_8267C5B0);
PPC_FUNC_IMPL(__imp__sub_8267C5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C5C8;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C5E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267C5E8;
	sub_82216788(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C5F8"))) PPC_WEAK_FUNC(sub_8267C5F8);
PPC_FUNC_IMPL(__imp__sub_8267C5F8) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267C610;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267C614;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267C618;
	sub_822150D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C628"))) PPC_WEAK_FUNC(sub_8267C628);
PPC_FUNC_IMPL(__imp__sub_8267C628) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c690
	if (cr6.eq) goto loc_8267C690;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267c664
	if (cr6.eq) goto loc_8267C664;
	// bl 0x8267c538
	ctx.lr = 0x8267C650;
	sub_8267C538(ctx, base);
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
loc_8267C664:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C670;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C67C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C690:
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

__attribute__((alias("__imp__sub_8267C6A8"))) PPC_WEAK_FUNC(sub_8267C6A8);
PPC_FUNC_IMPL(__imp__sub_8267C6A8) {
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
	// lwz r11,17292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17292);
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bl 0x82267e98
	ctx.lr = 0x8267C6D0;
	sub_82267E98(ctx, base);
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267C6F0;
	sub_82641CB0(ctx, base);
	// addi r8,r3,3648
	ctx.r8.s64 = ctx.r3.s64 + 3648;
	// stw r8,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8267C70C"))) PPC_WEAK_FUNC(sub_8267C70C);
PPC_FUNC_IMPL(__imp__sub_8267C70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C710"))) PPC_WEAK_FUNC(sub_8267C710);
PPC_FUNC_IMPL(__imp__sub_8267C710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,944(r3)
	PPC_STORE_U32(ctx.r3.u32 + 944, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C71C"))) PPC_WEAK_FUNC(sub_8267C71C);
PPC_FUNC_IMPL(__imp__sub_8267C71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C720"))) PPC_WEAK_FUNC(sub_8267C720);
PPC_FUNC_IMPL(__imp__sub_8267C720) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267c784
	if (cr6.eq) goto loc_8267C784;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267c784
	if (cr6.eq) goto loc_8267C784;
	// bl 0x8223fd30
	ctx.lr = 0x8267C760;
	sub_8223FD30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8267c784
	if (!cr6.lt) goto loc_8267C784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C784:
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

__attribute__((alias("__imp__sub_8267C798"))) PPC_WEAK_FUNC(sub_8267C798);
PPC_FUNC_IMPL(__imp__sub_8267C798) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C7B8;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267C7D8;
	sub_82216788(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r11,17292(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17292);
	// lwz r4,444(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 444);
	// lwz r3,440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// bl 0x82267e98
	ctx.lr = 0x8267C7EC;
	sub_82267E98(ctx, base);
	// lwz r6,432(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 432);
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

__attribute__((alias("__imp__sub_8267C808"))) PPC_WEAK_FUNC(sub_8267C808);
PPC_FUNC_IMPL(__imp__sub_8267C808) {
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
	// lwz r11,17292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17292);
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82267e98
	ctx.lr = 0x8267C830;
	sub_82267E98(ctx, base);
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
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

__attribute__((alias("__imp__sub_8267C84C"))) PPC_WEAK_FUNC(sub_8267C84C);
PPC_FUNC_IMPL(__imp__sub_8267C84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C850"))) PPC_WEAK_FUNC(sub_8267C850);
PPC_FUNC_IMPL(__imp__sub_8267C850) {
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
	// cmpwi cr6,r4,9
	cr6.compare<int32_t>(ctx.r4.s32, 9, xer);
	// beq cr6,0x8267c88c
	if (cr6.eq) goto loc_8267C88C;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c8b8
	if (cr6.eq) goto loc_8267C8B8;
	// bl 0x8267c538
	ctx.lr = 0x8267C878;
	sub_8267C538(ctx, base);
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
loc_8267C88C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C898;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C8A4;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C8B8:
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

__attribute__((alias("__imp__sub_8267C8D0"))) PPC_WEAK_FUNC(sub_8267C8D0);
PPC_FUNC_IMPL(__imp__sub_8267C8D0) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267c918
	if (!cr6.eq) goto loc_8267C918;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C8F8;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C904;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C918:
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

__attribute__((alias("__imp__sub_8267C930"))) PPC_WEAK_FUNC(sub_8267C930);
PPC_FUNC_IMPL(__imp__sub_8267C930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267C93C"))) PPC_WEAK_FUNC(sub_8267C93C);
PPC_FUNC_IMPL(__imp__sub_8267C93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C940"))) PPC_WEAK_FUNC(sub_8267C940);
PPC_FUNC_IMPL(__imp__sub_8267C940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267C94C"))) PPC_WEAK_FUNC(sub_8267C94C);
PPC_FUNC_IMPL(__imp__sub_8267C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C950"))) PPC_WEAK_FUNC(sub_8267C950);
PPC_FUNC_IMPL(__imp__sub_8267C950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267c95c
	if (cr6.eq) goto loc_8267C95C;
	// b 0x8267c538
	sub_8267C538(ctx, base);
	return;
loc_8267C95C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C964"))) PPC_WEAK_FUNC(sub_8267C964);
PPC_FUNC_IMPL(__imp__sub_8267C964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C968"))) PPC_WEAK_FUNC(sub_8267C968);
PPC_FUNC_IMPL(__imp__sub_8267C968) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267C980;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267C984;
	sub_82216648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C994"))) PPC_WEAK_FUNC(sub_8267C994);
PPC_FUNC_IMPL(__imp__sub_8267C994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C998"))) PPC_WEAK_FUNC(sub_8267C998);
PPC_FUNC_IMPL(__imp__sub_8267C998) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C9B0;
	sub_821E6800(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x8267C9B4;
	sub_82216788(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C9C4"))) PPC_WEAK_FUNC(sub_8267C9C4);
PPC_FUNC_IMPL(__imp__sub_8267C9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C9C8"))) PPC_WEAK_FUNC(sub_8267C9C8);
PPC_FUNC_IMPL(__imp__sub_8267C9C8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c9fc
	if (cr6.eq) goto loc_8267C9FC;
	// bl 0x8267c538
	ctx.lr = 0x8267C9E8;
	sub_8267C538(ctx, base);
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
loc_8267C9FC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CA08;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CA14;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CA28;
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

__attribute__((alias("__imp__sub_8267CA40"))) PPC_WEAK_FUNC(sub_8267CA40);
PPC_FUNC_IMPL(__imp__sub_8267CA40) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CA6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r9,-15764
	ctx.r3.s64 = ctx.r9.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267CA78;
	sub_821E6800(ctx, base);
	// lwz r3,-12640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267CA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267CA94;
	sub_82216788(ctx, base);
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

__attribute__((alias("__imp__sub_8267CAA8"))) PPC_WEAK_FUNC(sub_8267CAA8);
PPC_FUNC_IMPL(__imp__sub_8267CAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267CAC0;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267CAC4;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267CAC8;
	sub_822150D8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267CAE4;
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

__attribute__((alias("__imp__sub_8267CAF4"))) PPC_WEAK_FUNC(sub_8267CAF4);
PPC_FUNC_IMPL(__imp__sub_8267CAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CAF8"))) PPC_WEAK_FUNC(sub_8267CAF8);
PPC_FUNC_IMPL(__imp__sub_8267CAF8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CB24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267cb60
	if (cr6.eq) goto loc_8267CB60;
	// lfs f0,944(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 944);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,944(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8267cb60
	if (!cr6.lt) goto loc_8267CB60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CB60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267CB60:
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

__attribute__((alias("__imp__sub_8267CB78"))) PPC_WEAK_FUNC(sub_8267CB78);
PPC_FUNC_IMPL(__imp__sub_8267CB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,15004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15004);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CB88"))) PPC_WEAK_FUNC(sub_8267CB88);
PPC_FUNC_IMPL(__imp__sub_8267CB88) {
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
	ctx.lr = 0x8267CB90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,-14
	r11.s64 = r31.s64 + -14;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// bgt cr6,0x8267ccf4
	if (cr6.gt) goto loc_8267CCF4;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-13372
	r12.s64 = r12.s64 + -13372;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267CCB4;
	case 1:
		goto loc_8267CCF4;
	case 2:
		goto loc_8267CCF4;
	case 3:
		goto loc_8267CC7C;
	case 4:
		goto loc_8267CCF4;
	case 5:
		goto loc_8267CCF4;
	case 6:
		goto loc_8267CCF4;
	case 7:
		goto loc_8267CCF4;
	case 8:
		goto loc_8267CCF4;
	case 9:
		goto loc_8267CCF4;
	case 10:
		goto loc_8267CCF4;
	case 11:
		goto loc_8267CCF4;
	case 12:
		goto loc_8267CCF4;
	case 13:
		goto loc_8267CCF4;
	case 14:
		goto loc_8267CCF4;
	case 15:
		goto loc_8267CCF4;
	case 16:
		goto loc_8267CCF4;
	case 17:
		goto loc_8267CCF4;
	case 18:
		goto loc_8267CCF4;
	case 19:
		goto loc_8267CCF4;
	case 20:
		goto loc_8267CCF4;
	case 21:
		goto loc_8267CCF4;
	case 22:
		goto loc_8267CCF4;
	case 23:
		goto loc_8267CCF4;
	case 24:
		goto loc_8267CCF4;
	case 25:
		goto loc_8267CCF4;
	case 26:
		goto loc_8267CCF4;
	case 27:
		goto loc_8267CCF4;
	case 28:
		goto loc_8267CCF4;
	case 29:
		goto loc_8267CCF4;
	case 30:
		goto loc_8267CCF4;
	case 31:
		goto loc_8267CCF4;
	case 32:
		goto loc_8267CCF4;
	case 33:
		goto loc_8267CCF4;
	case 34:
		goto loc_8267CCF4;
	case 35:
		goto loc_8267CCF4;
	case 36:
		goto loc_8267CCF4;
	case 37:
		goto loc_8267CCF4;
	case 38:
		goto loc_8267CCF4;
	case 39:
		goto loc_8267CCF4;
	case 40:
		goto loc_8267CCF4;
	case 41:
		goto loc_8267CC7C;
	case 42:
		goto loc_8267CCF4;
	case 43:
		goto loc_8267CCF4;
	case 44:
		goto loc_8267CCF4;
	case 45:
		goto loc_8267CC7C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-13132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13132);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
loc_8267CC7C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CC88;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CC94;
	sub_826304B0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CCA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267CCB4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267CCCC;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,276(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267CCF4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8267c538
	ctx.lr = 0x8267CD04;
	sub_8267C538(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267CD0C"))) PPC_WEAK_FUNC(sub_8267CD0C);
PPC_FUNC_IMPL(__imp__sub_8267CD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CD10"))) PPC_WEAK_FUNC(sub_8267CD10);
PPC_FUNC_IMPL(__imp__sub_8267CD10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31376);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CD20"))) PPC_WEAK_FUNC(sub_8267CD20);
PPC_FUNC_IMPL(__imp__sub_8267CD20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CD30"))) PPC_WEAK_FUNC(sub_8267CD30);
PPC_FUNC_IMPL(__imp__sub_8267CD30) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267cd6c
	if (cr6.eq) goto loc_8267CD6C;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267cd6c
	if (cr6.eq) goto loc_8267CD6C;
	// bl 0x8267c538
	ctx.lr = 0x8267CD58;
	sub_8267C538(ctx, base);
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
loc_8267CD6C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CD78;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CD84;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CD98;
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

__attribute__((alias("__imp__sub_8267CDB0"))) PPC_WEAK_FUNC(sub_8267CDB0);
PPC_FUNC_IMPL(__imp__sub_8267CDB0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-15664
	ctx.r4.s64 = ctx.r10.s64 + -15664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CDDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-15700
	ctx.r4.s64 = ctx.r8.s64 + -15700;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267CDF8;
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

__attribute__((alias("__imp__sub_8267CE0C"))) PPC_WEAK_FUNC(sub_8267CE0C);
PPC_FUNC_IMPL(__imp__sub_8267CE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CE10"))) PPC_WEAK_FUNC(sub_8267CE10);
PPC_FUNC_IMPL(__imp__sub_8267CE10) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267ce8c
	if (cr6.eq) goto loc_8267CE8C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,944(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 944);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8267ce8c
	if (!cr6.gt) goto loc_8267CE8C;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8267ce8c
	if (!cr6.lt) goto loc_8267CE8C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-14972
	ctx.r3.s64 = r11.s64 + -14972;
	// bl 0x82215db8
	ctx.lr = 0x8267CE78;
	sub_82215DB8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CE8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267CE8C:
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

__attribute__((alias("__imp__sub_8267CEA4"))) PPC_WEAK_FUNC(sub_8267CEA4);
PPC_FUNC_IMPL(__imp__sub_8267CEA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CEA8"))) PPC_WEAK_FUNC(sub_8267CEA8);
PPC_FUNC_IMPL(__imp__sub_8267CEA8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267cee4
	if (cr6.eq) goto loc_8267CEE4;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267cee4
	if (cr6.eq) goto loc_8267CEE4;
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
loc_8267CEE4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CEF0;
	sub_821E6800(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f2,-6172(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6172);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,-17424(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17424);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x82207ef0
	ctx.lr = 0x8267CF08;
	sub_82207EF0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
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

__attribute__((alias("__imp__sub_8267CF2C"))) PPC_WEAK_FUNC(sub_8267CF2C);
PPC_FUNC_IMPL(__imp__sub_8267CF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CF30"))) PPC_WEAK_FUNC(sub_8267CF30);
PPC_FUNC_IMPL(__imp__sub_8267CF30) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// bl 0x822a39c0
	ctx.lr = 0x8267CF58;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8267CF7C;
	sub_822A39C8(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// b 0x8267cf94
	goto loc_8267CF94;
loc_8267CF90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8267CF94:
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

__attribute__((alias("__imp__sub_8267CFAC"))) PPC_WEAK_FUNC(sub_8267CFAC);
PPC_FUNC_IMPL(__imp__sub_8267CFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CFB0"))) PPC_WEAK_FUNC(sub_8267CFB0);
PPC_FUNC_IMPL(__imp__sub_8267CFB0) {
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
	// bl 0x82387a18
	ctx.lr = 0x8267CFD0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d004
	if (!cr6.eq) goto loc_8267D004;
	// bl 0x8267cf30
	ctx.lr = 0x8267CFE0;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d004
	if (!cr6.eq) goto loc_8267D004;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8267CFF8;
	sub_82630318(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267D004;
	sub_82203BD0(ctx, base);
loc_8267D004:
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

__attribute__((alias("__imp__sub_8267D01C"))) PPC_WEAK_FUNC(sub_8267D01C);
PPC_FUNC_IMPL(__imp__sub_8267D01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267D020"))) PPC_WEAK_FUNC(sub_8267D020);
PPC_FUNC_IMPL(__imp__sub_8267D020) {
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
	ctx.lr = 0x8267D028;
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
	// bl 0x8267cf30
	ctx.lr = 0x8267D03C;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267d054
	if (cr6.eq) goto loc_8267D054;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267D054:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631e20
	ctx.lr = 0x8267D064;
	sub_82631E20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267D06C"))) PPC_WEAK_FUNC(sub_8267D06C);
PPC_FUNC_IMPL(__imp__sub_8267D06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267D070"))) PPC_WEAK_FUNC(sub_8267D070);
PPC_FUNC_IMPL(__imp__sub_8267D070) {
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
	ctx.lr = 0x8267D078;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r10,-12168
	ctx.r3.s64 = ctx.r10.s64 + -12168;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x8267D0A4;
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
	ctx.lr = 0x8267D0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x8267D0BC;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8267d0f0
	if (!cr6.eq) goto loc_8267D0F0;
	// bl 0x8267cf30
	ctx.lr = 0x8267D0CC;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d0f0
	if (!cr6.eq) goto loc_8267D0F0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82630318
	ctx.lr = 0x8267D0E4;
	sub_82630318(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267D0F0;
	sub_82203BD0(ctx, base);
loc_8267D0F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267D0F8"))) PPC_WEAK_FUNC(sub_8267D0F8);
PPC_FUNC_IMPL(__imp__sub_8267D0F8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d12c
	if (cr6.eq) goto loc_8267D12C;
	// bl 0x8267c538
	ctx.lr = 0x8267D118;
	sub_8267C538(ctx, base);
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
loc_8267D12C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D138;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D168;
	sub_82691650(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8262ce00
	ctx.lr = 0x8267D170;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D188"))) PPC_WEAK_FUNC(sub_8267D188);
PPC_FUNC_IMPL(__imp__sub_8267D188) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267d1f4
	if (cr6.eq) goto loc_8267D1F4;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// bne cr6,0x8267d220
	if (!cr6.eq) goto loc_8267D220;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D1B8;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D1CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D1E8;
	sub_82691650(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8262ce00
	ctx.lr = 0x8267D1F0;
	sub_8262CE00(ctx, base);
	// b 0x8267d220
	goto loc_8267D220;
loc_8267D1F4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D200;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267D20C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267D220:
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

__attribute__((alias("__imp__sub_8267D238"))) PPC_WEAK_FUNC(sub_8267D238);
PPC_FUNC_IMPL(__imp__sub_8267D238) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d26c
	if (cr6.eq) goto loc_8267D26C;
	// bl 0x8267c538
	ctx.lr = 0x8267D258;
	sub_8267C538(ctx, base);
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
loc_8267D26C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D278;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D2A8;
	sub_82691650(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x8262ce00
	ctx.lr = 0x8267D2B0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D2C8"))) PPC_WEAK_FUNC(sub_8267D2C8);
PPC_FUNC_IMPL(__imp__sub_8267D2C8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d2fc
	if (cr6.eq) goto loc_8267D2FC;
	// bl 0x8267c538
	ctx.lr = 0x8267D2E8;
	sub_8267C538(ctx, base);
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
loc_8267D2FC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D308;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D338;
	sub_82691650(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8262ce00
	ctx.lr = 0x8267D340;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D358"))) PPC_WEAK_FUNC(sub_8267D358);
PPC_FUNC_IMPL(__imp__sub_8267D358) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d38c
	if (cr6.eq) goto loc_8267D38C;
	// bl 0x8267c538
	ctx.lr = 0x8267D378;
	sub_8267C538(ctx, base);
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
loc_8267D38C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D398;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D3AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D3C8;
	sub_82691650(ctx, base);
	// li r4,33
	ctx.r4.s64 = 33;
	// bl 0x8262ce00
	ctx.lr = 0x8267D3D0;
	sub_8262CE00(ctx, base);
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

