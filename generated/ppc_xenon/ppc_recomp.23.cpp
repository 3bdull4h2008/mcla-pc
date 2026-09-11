#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821F850C"))) PPC_WEAK_FUNC(sub_821F850C);
PPC_FUNC_IMPL(__imp__sub_821F850C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8510"))) PPC_WEAK_FUNC(sub_821F8510);
PPC_FUNC_IMPL(__imp__sub_821F8510) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f854c
	if (cr6.eq) goto loc_821F854C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f8570
	if (cr6.eq) goto loc_821F8570;
loc_821F854C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f8574
	if (!cr6.eq) goto loc_821F8574;
loc_821F8570:
	// li r11,0
	r11.s64 = 0;
loc_821F8574:
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

__attribute__((alias("__imp__sub_821F858C"))) PPC_WEAK_FUNC(sub_821F858C);
PPC_FUNC_IMPL(__imp__sub_821F858C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8590"))) PPC_WEAK_FUNC(sub_821F8590);
PPC_FUNC_IMPL(__imp__sub_821F8590) {
	PPC_FUNC_PROLOGUE();
	// stw r4,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8598"))) PPC_WEAK_FUNC(sub_821F8598);
PPC_FUNC_IMPL(__imp__sub_821F8598) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F85A0"))) PPC_WEAK_FUNC(sub_821F85A0);
PPC_FUNC_IMPL(__imp__sub_821F85A0) {
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
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lbz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x821f85dc
	if (cr6.eq) goto loc_821F85DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F85DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F85DC:
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
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

__attribute__((alias("__imp__sub_821F85F8"))) PPC_WEAK_FUNC(sub_821F85F8);
PPC_FUNC_IMPL(__imp__sub_821F85F8) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,100(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 100);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8600"))) PPC_WEAK_FUNC(sub_821F8600);
PPC_FUNC_IMPL(__imp__sub_821F8600) {
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
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x821f863c
	if (cr6.eq) goto loc_821F863C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F863C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F863C:
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
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

__attribute__((alias("__imp__sub_821F8658"))) PPC_WEAK_FUNC(sub_821F8658);
PPC_FUNC_IMPL(__imp__sub_821F8658) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,101(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 101);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8660"))) PPC_WEAK_FUNC(sub_821F8660);
PPC_FUNC_IMPL(__imp__sub_821F8660) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8668"))) PPC_WEAK_FUNC(sub_821F8668);
PPC_FUNC_IMPL(__imp__sub_821F8668) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,102(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8670"))) PPC_WEAK_FUNC(sub_821F8670);
PPC_FUNC_IMPL(__imp__sub_821F8670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-20836
	ctx.r3.s64 = r11.s64 + -20836;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F867C"))) PPC_WEAK_FUNC(sub_821F867C);
PPC_FUNC_IMPL(__imp__sub_821F867C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8680"))) PPC_WEAK_FUNC(sub_821F8680);
PPC_FUNC_IMPL(__imp__sub_821F8680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-20828
	ctx.r3.s64 = r11.s64 + -20828;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F868C"))) PPC_WEAK_FUNC(sub_821F868C);
PPC_FUNC_IMPL(__imp__sub_821F868C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8690"))) PPC_WEAK_FUNC(sub_821F8690);
PPC_FUNC_IMPL(__imp__sub_821F8690) {
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
	// bl 0x8263f330
	ctx.lr = 0x821F86A8;
	sub_8263F330(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r11,-20156
	ctx.r7.s64 = r11.s64 + -20156;
	// addi r6,r10,-20196
	ctx.r6.s64 = ctx.r10.s64 + -20196;
	// addi r5,r9,-20756
	ctx.r5.s64 = ctx.r9.s64 + -20756;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r4,r8,-20776
	ctx.r4.s64 = ctx.r8.s64 + -20776;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// stw r5,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r4.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821F86F0"))) PPC_WEAK_FUNC(sub_821F86F0);
PPC_FUNC_IMPL(__imp__sub_821F86F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F86FC"))) PPC_WEAK_FUNC(sub_821F86FC);
PPC_FUNC_IMPL(__imp__sub_821F86FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8700"))) PPC_WEAK_FUNC(sub_821F8700);
PPC_FUNC_IMPL(__imp__sub_821F8700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,384(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 384);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F8710"))) PPC_WEAK_FUNC(sub_821F8710);
PPC_FUNC_IMPL(__imp__sub_821F8710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,388(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 388);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F8720"))) PPC_WEAK_FUNC(sub_821F8720);
PPC_FUNC_IMPL(__imp__sub_821F8720) {
	PPC_FUNC_PROLOGUE();
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8728"))) PPC_WEAK_FUNC(sub_821F8728);
PPC_FUNC_IMPL(__imp__sub_821F8728) {
	PPC_FUNC_PROLOGUE();
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8730"))) PPC_WEAK_FUNC(sub_821F8730);
PPC_FUNC_IMPL(__imp__sub_821F8730) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8738"))) PPC_WEAK_FUNC(sub_821F8738);
PPC_FUNC_IMPL(__imp__sub_821F8738) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8740"))) PPC_WEAK_FUNC(sub_821F8740);
PPC_FUNC_IMPL(__imp__sub_821F8740) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r7,r11,-20156
	ctx.r7.s64 = r11.s64 + -20156;
	// addi r6,r10,-20196
	ctx.r6.s64 = ctx.r10.s64 + -20196;
	// addi r5,r9,-20756
	ctx.r5.s64 = ctx.r9.s64 + -20756;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r4,r8,-20776
	ctx.r4.s64 = ctx.r8.s64 + -20776;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// stw r5,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r5.u32);
	// stw r4,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r4.u32);
	// bl 0x8263f748
	ctx.lr = 0x821F8790;
	sub_8263F748(ctx, base);
	// clrlwi r3,r30,31
	ctx.r3.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x821f87a8
	if (cr6.eq) goto loc_821F87A8;
	// bl 0x82130588
	ctx.lr = 0x821F87A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F87A8:
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

__attribute__((alias("__imp__sub_821F87C0"))) PPC_WEAK_FUNC(sub_821F87C0);
PPC_FUNC_IMPL(__imp__sub_821F87C0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-456
	ctx.r3.s64 = ctx.r3.s64 + -456;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87C8"))) PPC_WEAK_FUNC(sub_821F87C8);
PPC_FUNC_IMPL(__imp__sub_821F87C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-420
	ctx.r3.s64 = ctx.r3.s64 + -420;
	// b 0x8263cfd0
	sub_8263CFD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87D0"))) PPC_WEAK_FUNC(sub_821F87D0);
PPC_FUNC_IMPL(__imp__sub_821F87D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-456
	ctx.r3.s64 = ctx.r3.s64 + -456;
	// b 0x8263e4f0
	sub_8263E4F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87D8"))) PPC_WEAK_FUNC(sub_821F87D8);
PPC_FUNC_IMPL(__imp__sub_821F87D8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-36
	ctx.r3.s64 = ctx.r3.s64 + -36;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87E0"))) PPC_WEAK_FUNC(sub_821F87E0);
PPC_FUNC_IMPL(__imp__sub_821F87E0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-536
	ctx.r3.s64 = ctx.r3.s64 + -536;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87E8"))) PPC_WEAK_FUNC(sub_821F87E8);
PPC_FUNC_IMPL(__imp__sub_821F87E8) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f8824
	if (cr6.eq) goto loc_821F8824;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8818;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x821f8828
	if (!cr6.eq) goto loc_821F8828;
loc_821F8824:
	// li r11,1
	r11.s64 = 1;
loc_821F8828:
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

__attribute__((alias("__imp__sub_821F8840"))) PPC_WEAK_FUNC(sub_821F8840);
PPC_FUNC_IMPL(__imp__sub_821F8840) {
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
	ctx.lr = 0x821F8848;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x824e6400
	ctx.lr = 0x821F886C;
	sub_824E6400(ctx, base);
	// addi r3,r30,68
	ctx.r3.s64 = r30.s64 + 68;
	// bl 0x824e6310
	ctx.lr = 0x821F8874;
	sub_824E6310(ctx, base);
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// bl 0x824e1c10
	ctx.lr = 0x821F887C;
	sub_824E1C10(ctx, base);
	// stw r29,648(r31)
	PPC_STORE_U32(r31.u32 + 648, r29.u32);
	// stw r29,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r29.u32);
	// addi r3,r30,68
	ctx.r3.s64 = r30.s64 + 68;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// stb r29,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r29.u8);
	// bl 0x824e6310
	ctx.lr = 0x821F8894;
	sub_824E6310(ctx, base);
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// bl 0x824e0a58
	ctx.lr = 0x821F889C;
	sub_824E0A58(ctx, base);
	// addi r3,r30,640
	ctx.r3.s64 = r30.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x821F88A8;
	sub_821CE080(ctx, base);
	// stw r29,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F88B8"))) PPC_WEAK_FUNC(sub_821F88B8);
PPC_FUNC_IMPL(__imp__sub_821F88B8) {
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
	// addi r4,r10,-20132
	ctx.r4.s64 = ctx.r10.s64 + -20132;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82691650
	ctx.lr = 0x821F88EC;
	sub_82691650(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f8918
	if (cr6.eq) goto loc_821F8918;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F890C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x821f891c
	if (!cr6.eq) goto loc_821F891C;
loc_821F8918:
	// li r11,1
	r11.s64 = 1;
loc_821F891C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f8948
	if (cr6.eq) goto loc_821F8948;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-20148
	ctx.r4.s64 = r11.s64 + -20148;
	// bl 0x82691650
	ctx.lr = 0x821F8938;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,268(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F8948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F8948:
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

__attribute__((alias("__imp__sub_821F8960"))) PPC_WEAK_FUNC(sub_821F8960);
PPC_FUNC_IMPL(__imp__sub_821F8960) {
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
	ctx.lr = 0x821F8968;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x821F897C;
	sub_82180430(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r31,1
	r31.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r8,-20108
	ctx.r4.s64 = ctx.r8.s64 + -20108;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r7,640
	ctx.r7.s64 = 640;
	// stb r31,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r31.u8);
	// li r6,960
	ctx.r6.s64 = 960;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F89D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r11,-25232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stb r31,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r31.u8);
	// addi r4,r7,-20124
	ctx.r4.s64 = ctx.r7.s64 + -20124;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// li r7,640
	ctx.r7.s64 = 640;
	// stw r3,-22100(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22100, ctx.r3.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,56(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	// li r6,960
	ctx.r6.s64 = 960;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rldicr r8,r6,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// ld r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// stw r11,-22104(r7)
	PPC_STORE_U32(ctx.r7.u32 + -22104, r11.u32);
	// ld r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x821f7710
	ctx.lr = 0x821F8A4C;
	sub_821F7710(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F8A54"))) PPC_WEAK_FUNC(sub_821F8A54);
PPC_FUNC_IMPL(__imp__sub_821F8A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8A58"))) PPC_WEAK_FUNC(sub_821F8A58);
PPC_FUNC_IMPL(__imp__sub_821F8A58) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821F8A60;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821F8A84;
	sub_82305870(ctx, base);
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgt cr6,0x821f921c
	if (cr6.gt) goto loc_821F921C;
	// lis r12,-32224
	r12.s64 = -2111832064;
	// addi r12,r12,-30036
	r12.s64 = r12.s64 + -30036;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821F8B14;
	case 1:
		goto loc_821F8B44;
	case 2:
		goto loc_821F8B74;
	case 3:
		goto loc_821F8BA8;
	case 4:
		goto loc_821F8BDC;
	case 5:
		goto loc_821F8C0C;
	case 6:
		goto loc_821F8C3C;
	case 7:
		goto loc_821F8C6C;
	case 8:
		goto loc_821F8CCC;
	case 9:
		goto loc_821F8D00;
	case 10:
		goto loc_821F8FB4;
	case 11:
		goto loc_821F910C;
	case 12:
		goto loc_821F8C9C;
	case 13:
		goto loc_821F8D88;
	case 14:
		goto loc_821F8E08;
	case 15:
		goto loc_821F8E88;
	case 16:
		goto loc_821F8F08;
	case 17:
		goto loc_821F921C;
	case 18:
		goto loc_821F921C;
	case 19:
		goto loc_821F8D34;
	case 20:
		goto loc_821F9160;
	case 21:
		goto loc_821F8FD0;
	case 22:
		goto loc_821F90B8;
	case 23:
		goto loc_821F91B4;
	case 24:
		goto loc_821F9000;
	case 25:
		goto loc_821F905C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-29932(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29932);
	// lwz r16,-29884(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29884);
	// lwz r16,-29836(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29836);
	// lwz r16,-29784(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29784);
	// lwz r16,-29732(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29732);
	// lwz r16,-29684(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29684);
	// lwz r16,-29636(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29636);
	// lwz r16,-29588(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29588);
	// lwz r16,-29492(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29492);
	// lwz r16,-29440(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29440);
	// lwz r16,-28748(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28748);
	// lwz r16,-28404(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28404);
	// lwz r16,-29540(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29540);
	// lwz r16,-29304(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29304);
	// lwz r16,-29176(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29176);
	// lwz r16,-29048(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29048);
	// lwz r16,-28920(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28920);
	// lwz r16,-28132(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28132);
	// lwz r16,-28132(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28132);
	// lwz r16,-29388(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -29388);
	// lwz r16,-28320(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28320);
	// lwz r16,-28720(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28720);
	// lwz r16,-28488(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28488);
	// lwz r16,-28236(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28236);
	// lwz r16,-28672(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28672);
	// lwz r16,-28580(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -28580);
loc_821F8B14:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8B20;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8B40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8B44:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8B50;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8B74:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8B80;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8BA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8BA8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8BB4;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8BDC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8BE8;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,108(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8C08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8C0C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8C18;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,112(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8C38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8C3C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8C48;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,88(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8C68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8C6C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8C78;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,68(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8C9C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8CA8;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,100(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8CCC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8CD8;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8D00:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8D0C;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8D34:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8D40;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f31.f64 = double(temp.f32);
	// bl 0x8268c9f0
	ctx.lr = 0x821F8D54;
	sub_8268C9F0(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82234a10
	ctx.lr = 0x821F8D84;
	sub_82234A10(ctx, base);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8D88:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8D94;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f8dbc
	if (cr6.eq) goto loc_821F8DBC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8DA8;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x821f8dc0
	goto loc_821F8DC0;
loc_821F8DBC:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821F8DC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8DD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,92(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F8DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r7,96(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F8E04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8E08:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8E14;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f8e3c
	if (cr6.eq) goto loc_821F8E3C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8E28;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x821f8e40
	goto loc_821F8E40;
loc_821F8E3C:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821F8E40:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F8E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,96(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821F8E84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8E88:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8E94;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f8ebc
	if (cr6.eq) goto loc_821F8EBC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8EA8;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x821f8ec0
	goto loc_821F8EC0;
loc_821F8EBC:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821F8EC0:
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
	ctx.lr = 0x821F8ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,112(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F8EEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,96(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821F8F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8F08:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8F14;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f8f3c
	if (cr6.eq) goto loc_821F8F3C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F8F28;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x821f8f40
	goto loc_821F8F40;
loc_821F8F3C:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821F8F40:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r30,r8,-22444
	r30.s64 = ctx.r8.s64 + -22444;
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x8268ee10
	ctx.lr = 0x821F8F7C;
	sub_8268EE10(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,92(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821F8F90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x8268ee10
	ctx.lr = 0x821F8FB0;
	sub_8268EE10(ctx, base);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8FB4:
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
	// bl 0x82643bb8
	ctx.lr = 0x821F8FCC;
	sub_82643BB8(ctx, base);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F8FD0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,69
	ctx.r4.s64 = 69;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x821F8FEC;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F8FFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F9000:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4944
	ctx.r9.u64 = ctx.r10.u64 | 4944;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821f921c
	if (cr6.eq) goto loc_821F921C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F902C;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r8,r10
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823058f8
	ctx.lr = 0x821F904C;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_821F905C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4994
	ctx.r9.u64 = ctx.r10.u64 | 4994;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821f921c
	if (cr6.eq) goto loc_821F921C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F9088;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r8,r10
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823058f8
	ctx.lr = 0x821F90A8;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_821F90B8:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F90C4;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,-10244(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x8268c9f0
	ctx.lr = 0x821F90E0;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-10244(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82218310
	ctx.lr = 0x821F90F8;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x821F9108;
	sub_822183B0(ctx, base);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F910C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x821F9118;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r5,r7,-22108
	ctx.r5.s64 = ctx.r7.s64 + -22108;
	// addi r6,r9,-21896
	ctx.r6.s64 = ctx.r9.s64 + -21896;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823dedd8
	ctx.lr = 0x821F9144;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f921c
	if (cr6.eq) goto loc_821F921C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F915C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F9160:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4947
	ctx.r10.u64 = r11.u64 | 4947;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f921c
	if (!cr6.eq) goto loc_821F921C;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,69
	ctx.r4.s64 = 69;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x821F9194;
	sub_82641CB0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r7,704(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// add r4,r8,r31
	ctx.r4.u64 = ctx.r8.u64 + r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F91B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f921c
	goto loc_821F921C;
loc_821F91B4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// ori r10,r11,4944
	ctx.r10.u64 = r11.u64 | 4944;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f921c
	if (cr6.eq) goto loc_821F921C;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82204480
	ctx.lr = 0x821F91DC;
	sub_82204480(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r31,r10,4672
	r31.u64 = ctx.r10.u64 | 4672;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x8221bb90
	ctx.lr = 0x821F91F4;
	sub_8221BB90(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r31
	ctx.r3.u64 = ctx.r8.u64 + r31.u64;
	// bl 0x8221a2a8
	ctx.lr = 0x821F9208;
	sub_8221A2A8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x821F9218;
	sub_8221A440(ctx, base);
	// bl 0x823bbf48
	ctx.lr = 0x821F921C;
	sub_823BBF48(ctx, base);
loc_821F921C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821F9228;
	sub_823058F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F9238"))) PPC_WEAK_FUNC(sub_821F9238);
PPC_FUNC_IMPL(__imp__sub_821F9238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,150
	r11.s64 = ctx.r4.s64 + 150;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9248"))) PPC_WEAK_FUNC(sub_821F9248);
PPC_FUNC_IMPL(__imp__sub_821F9248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f9268
	if (cr6.eq) goto loc_821F9268;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// b 0x821f9270
	goto loc_821F9270;
loc_821F9268:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
loc_821F9270:
	// mulli r10,r11,1040
	ctx.r10.s64 = r11.s64 * 1040;
	// rlwinm r11,r4,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,7520
	ctx.r3.s64 = r11.s64 + 7520;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9288"))) PPC_WEAK_FUNC(sub_821F9288);
PPC_FUNC_IMPL(__imp__sub_821F9288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r5,10640(r11)
	PPC_STORE_U8(r11.u32 + 10640, ctx.r5.u8);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// rlwinm r9,r4,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r8,r4,150
	ctx.r8.s64 = ctx.r4.s64 + 150;
	// li r6,16
	ctx.r6.s64 = 16;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r10,-17936(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// li r7,32
	ctx.r7.s64 = 32;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mulli r10,r10,1040
	ctx.r10.s64 = ctx.r10.s64 * 1040;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// li r8,48
	ctx.r8.s64 = 48;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r10,r10,7520
	ctx.r10.s64 = ctx.r10.s64 + 7520;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F92F4"))) PPC_WEAK_FUNC(sub_821F92F4);
PPC_FUNC_IMPL(__imp__sub_821F92F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F92F8"))) PPC_WEAK_FUNC(sub_821F92F8);
PPC_FUNC_IMPL(__imp__sub_821F92F8) {
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
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f9324
	if (!cr6.eq) goto loc_821F9324;
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
loc_821F9324:
	// lis r11,1
	r11.s64 = 65536;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// ori r8,r11,3600
	ctx.r8.u64 = r11.u64 | 3600;
	// addi r4,r9,-20092
	ctx.r4.s64 = ctx.r9.s64 + -20092;
	// lwzx r3,r10,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// bl 0x82695c78
	ctx.lr = 0x821F9340;
	sub_82695C78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f9358
	if (cr6.eq) goto loc_821F9358;
	// bl 0x826947e0
	ctx.lr = 0x821F934C;
	sub_826947E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f935c
	if (!cr6.eq) goto loc_821F935C;
loc_821F9358:
	// li r11,0
	r11.s64 = 0;
loc_821F935C:
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
}

__attribute__((alias("__imp__sub_821F9370"))) PPC_WEAK_FUNC(sub_821F9370);
PPC_FUNC_IMPL(__imp__sub_821F9370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// stw r3,10712(r11)
	PPC_STORE_U32(r11.u32 + 10712, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9380"))) PPC_WEAK_FUNC(sub_821F9380);
PPC_FUNC_IMPL(__imp__sub_821F9380) {
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
	ctx.lr = 0x821F9388;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f93b8
	if (cr6.eq) goto loc_821F93B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F93B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_821F93B8:
	// lis r3,4
	ctx.r3.s64 = 262144;
	// ori r3,r3,2148
	ctx.r3.u64 = ctx.r3.u64 | 2148;
	// bl 0x82130528
	ctx.lr = 0x821F93C4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f93d8
	if (cr6.eq) goto loc_821F93D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8221fe30
	ctx.lr = 0x821F93D4;
	sub_8221FE30(ctx, base);
	// b 0x821f93dc
	goto loc_821F93DC;
loc_821F93D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_821F93DC:
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,-19860
	ctx.r4.s64 = ctx.r10.s64 + -19860;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x821F93F8;
	sub_821CA540(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r9,-19868
	ctx.r4.s64 = ctx.r9.s64 + -19868;
	// bl 0x82693e10
	ctx.lr = 0x821F940C;
	sub_82693E10(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821f943c
	if (!cr6.eq) goto loc_821F943C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f9438
	if (cr6.eq) goto loc_821F9438;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F9438;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F9438:
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_821F943C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821F9444;
	sub_821C9A90(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821F9454;
	sub_82305870(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f94e4
	if (cr6.eq) goto loc_821F94E4;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,-19884
	ctx.r4.s64 = ctx.r10.s64 + -19884;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r30,r9,-22132
	r30.s64 = ctx.r9.s64 + -22132;
	// addi r27,r8,-22108
	r27.s64 = ctx.r8.s64 + -22108;
	// bl 0x82691650
	ctx.lr = 0x821F9480;
	sub_82691650(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821F9494;
	sub_823DEDD8(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r7,-21704
	ctx.r4.s64 = ctx.r7.s64 + -21704;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r26,r6,-21872
	r26.s64 = ctx.r6.s64 + -21872;
	// bl 0x82691650
	ctx.lr = 0x821F94B8;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821F94CC;
	sub_823DEDD8(ctx, base);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// ori r4,r5,4656
	ctx.r4.u64 = ctx.r5.u64 | 4656;
	// stwx r3,r30,r4
	PPC_STORE_U32(r30.u32 + ctx.r4.u32, ctx.r3.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x8268de28
	ctx.lr = 0x821F94E4;
	sub_8268DE28(ctx, base);
loc_821F94E4:
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r5,r11,-19908
	ctx.r5.s64 = r11.s64 + -19908;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x821F9504;
	sub_8268B960(ctx, base);
	// stw r3,10668(r31)
	PPC_STORE_U32(r31.u32 + 10668, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-19924
	ctx.r5.s64 = ctx.r10.s64 + -19924;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F9520;
	sub_8268B960(ctx, base);
	// stw r3,10672(r31)
	PPC_STORE_U32(r31.u32 + 10672, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-19952
	ctx.r5.s64 = ctx.r9.s64 + -19952;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F953C;
	sub_8268B960(ctx, base);
	// stw r3,10676(r31)
	PPC_STORE_U32(r31.u32 + 10676, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-19968
	ctx.r5.s64 = ctx.r8.s64 + -19968;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F9558;
	sub_8268B960(ctx, base);
	// stw r3,10680(r31)
	PPC_STORE_U32(r31.u32 + 10680, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-19992
	ctx.r5.s64 = ctx.r7.s64 + -19992;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F9574;
	sub_8268B960(ctx, base);
	// stw r3,10684(r31)
	PPC_STORE_U32(r31.u32 + 10684, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-20020
	ctx.r5.s64 = ctx.r6.s64 + -20020;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F9590;
	sub_8268B960(ctx, base);
	// stw r3,10688(r31)
	PPC_STORE_U32(r31.u32 + 10688, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-20036
	ctx.r5.s64 = ctx.r5.s64 + -20036;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F95AC;
	sub_8268B960(ctx, base);
	// stw r3,10692(r31)
	PPC_STORE_U32(r31.u32 + 10692, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-20056
	ctx.r5.s64 = r11.s64 + -20056;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821F95C8;
	sub_8268B960(ctx, base);
	// stw r3,10696(r31)
	PPC_STORE_U32(r31.u32 + 10696, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-20072
	ctx.r5.s64 = ctx.r10.s64 + -20072;
	// li r6,10
	ctx.r6.s64 = 10;
	// bl 0x8268b960
	ctx.lr = 0x821F95E4;
	sub_8268B960(ctx, base);
	// stw r3,10700(r31)
	PPC_STORE_U32(r31.u32 + 10700, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-20088
	ctx.r5.s64 = ctx.r9.s64 + -20088;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268b960
	ctx.lr = 0x821F9600;
	sub_8268B960(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r3,10704(r31)
	PPC_STORE_U32(r31.u32 + 10704, ctx.r3.u32);
	// lwz r11,2832(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2832);
	// stb r28,10271(r11)
	PPC_STORE_U8(r11.u32 + 10271, r28.u8);
	// lwz r3,2832(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2832);
	// bl 0x821fec10
	ctx.lr = 0x821F9618;
	sub_821FEC10(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r7,10708(r31)
	PPC_STORE_U8(r31.u32 + 10708, ctx.r7.u8);
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821F962C;
	sub_823058F8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F9634"))) PPC_WEAK_FUNC(sub_821F9634);
PPC_FUNC_IMPL(__imp__sub_821F9634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9638"))) PPC_WEAK_FUNC(sub_821F9638);
PPC_FUNC_IMPL(__imp__sub_821F9638) {
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
	ctx.lr = 0x821F9640;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x823db670
	ctx.lr = 0x821F9660;
	sub_823DB670(ctx, base);
	// li r4,47
	ctx.r4.s64 = 47;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dd850
	ctx.lr = 0x821F966C;
	sub_823DD850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// beq cr6,0x821f96a8
	if (cr6.eq) goto loc_821F96A8;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// addi r5,r10,-19852
	ctx.r5.s64 = ctx.r10.s64 + -19852;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x821F96A0;
	sub_82137A08(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_821F96A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x821F96BC;
	sub_82137A08(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F96C4"))) PPC_WEAK_FUNC(sub_821F96C4);
PPC_FUNC_IMPL(__imp__sub_821F96C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F96C8"))) PPC_WEAK_FUNC(sub_821F96C8);
PPC_FUNC_IMPL(__imp__sub_821F96C8) {
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
	ctx.lr = 0x821F96D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821f7d70
	ctx.lr = 0x821F96E4;
	sub_821F7D70(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821f96f8
	if (cr6.eq) goto loc_821F96F8;
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,7508(r11)
	PPC_STORE_U8(r11.u32 + 7508, ctx.r10.u8);
loc_821F96F8:
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x826949b0
	ctx.lr = 0x821F9704;
	sub_826949B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f9774
	if (cr6.eq) goto loc_821F9774;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9774
	if (cr6.eq) goto loc_821F9774;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addis r11,r10,4
	r11.s64 = ctx.r10.s64 + 262144;
	// addi r11,r11,1808
	r11.s64 = r11.s64 + 1808;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x821f9740
	if (!cr6.eq) goto loc_821F9740;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_821F9740:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x821F974C;
	sub_82720E28(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720fc8
	ctx.lr = 0x821F9754;
	sub_82720FC8(ctx, base);
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lhz r11,92(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 92);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,92(r31)
	PPC_STORE_U16(r31.u32 + 92, ctx.r8.u16);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
loc_821F9774:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F977C"))) PPC_WEAK_FUNC(sub_821F977C);
PPC_FUNC_IMPL(__imp__sub_821F977C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9780"))) PPC_WEAK_FUNC(sub_821F9780);
PPC_FUNC_IMPL(__imp__sub_821F9780) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,60
	ctx.r3.s64 = ctx.r3.s64 + 60;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x826949b0
	ctx.lr = 0x821F97A4;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x821f97b4
	if (cr6.eq) goto loc_821F97B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821F97B4:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821F97CC"))) PPC_WEAK_FUNC(sub_821F97CC);
PPC_FUNC_IMPL(__imp__sub_821F97CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F97D0"))) PPC_WEAK_FUNC(sub_821F97D0);
PPC_FUNC_IMPL(__imp__sub_821F97D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// addi r3,r11,10736
	ctx.r3.s64 = r11.s64 + 10736;
	// b 0x82214140
	sub_82214140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F97E0"))) PPC_WEAK_FUNC(sub_821F97E0);
PPC_FUNC_IMPL(__imp__sub_821F97E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// addi r3,r11,10736
	ctx.r3.s64 = r11.s64 + 10736;
	// b 0x82214168
	sub_82214168(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F97F0"))) PPC_WEAK_FUNC(sub_821F97F0);
PPC_FUNC_IMPL(__imp__sub_821F97F0) {
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
	ctx.lr = 0x821F97F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-19796
	ctx.r3.s64 = r11.s64 + -19796;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x821F9818;
	sub_82130000(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x821F981C;
	sub_82387B90(ctx, base);
	// lhz r10,1238(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1238);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f983c
	if (!cr6.eq) goto loc_821F983C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-10284
	ctx.r10.s64 = r11.s64 + -10284;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f98b4
	if (cr6.eq) goto loc_821F98B4;
loc_821F983C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-19832
	ctx.r3.s64 = r11.s64 + -19832;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x821F9850;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// addi r28,r7,30576
	r28.s64 = ctx.r7.s64 + 30576;
	// addi r4,r6,-19840
	ctx.r4.s64 = ctx.r6.s64 + -19840;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r29,r11,10736
	r29.s64 = r11.s64 + 10736;
	// lwz r10,-6752(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -6752);
	// stfs f0,12256(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12256, temp.u32);
	// stw r10,12192(r11)
	PPC_STORE_U32(r11.u32 + 12192, ctx.r10.u32);
	// bl 0x821ca540
	ctx.lr = 0x821F988C;
	sub_821CA540(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x821F9898;
	sub_821CA540(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82214410
	ctx.lr = 0x821F98A4;
	sub_82214410(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821F98AC;
	sub_821C9A90(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821F98B4;
	sub_821C9A90(ctx, base);
loc_821F98B4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F98BC"))) PPC_WEAK_FUNC(sub_821F98BC);
PPC_FUNC_IMPL(__imp__sub_821F98BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F98C0"))) PPC_WEAK_FUNC(sub_821F98C0);
PPC_FUNC_IMPL(__imp__sub_821F98C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f98d8
	if (cr6.eq) goto loc_821F98D8;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x82204258
	sub_82204258(ctx, base);
	return;
loc_821F98D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F98E0"))) PPC_WEAK_FUNC(sub_821F98E0);
PPC_FUNC_IMPL(__imp__sub_821F98E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,4
	r11.s64 = 4;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F98FC"))) PPC_WEAK_FUNC(sub_821F98FC);
PPC_FUNC_IMPL(__imp__sub_821F98FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9900"))) PPC_WEAK_FUNC(sub_821F9900);
PPC_FUNC_IMPL(__imp__sub_821F9900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r4,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9918"))) PPC_WEAK_FUNC(sub_821F9918);
PPC_FUNC_IMPL(__imp__sub_821F9918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9a00
	if (cr6.eq) goto loc_821F9A00;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,1000
	cr6.compare<int32_t>(r11.s32, 1000, xer);
	// ble cr6,0x821f9a00
	if (!cr6.gt) goto loc_821F9A00;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f99dc
	if (!cr6.eq) goto loc_821F99DC;
	// lbz r11,13(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f997c
	if (cr6.eq) goto loc_821F997C;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r11,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r11.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-19736
	ctx.r4.s64 = ctx.r10.s64 + -19736;
	// bl 0x825ee0e0
	ctx.lr = 0x821F997C;
	sub_825EE0E0(ctx, base);
loc_821F997C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19756
	ctx.r4.s64 = r11.s64 + -19756;
	// bl 0x825ee120
	ctx.lr = 0x821F9990;
	sub_825EE120(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x821f99a4
	if (cr6.eq) goto loc_821F99A4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821f99c0
	if (!cr6.eq) goto loc_821F99C0;
loc_821F99A4:
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stb r11,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r11.u8);
	// lis r4,-257
	ctx.r4.s64 = -16842752;
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5b00
	ctx.lr = 0x821F99C0;
	sub_822E5B00(ctx, base);
loc_821F99C0:
	// lbz r11,15(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 15);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,-19772
	ctx.r4.s64 = ctx.r10.s64 + -19772;
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x825ee0e0
	ctx.lr = 0x821F99DC;
	sub_825EE0E0(ctx, base);
loc_821F99DC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,4400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4400);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F9A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F9A00:
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

__attribute__((alias("__imp__sub_821F9A14"))) PPC_WEAK_FUNC(sub_821F9A14);
PPC_FUNC_IMPL(__imp__sub_821F9A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9A18"))) PPC_WEAK_FUNC(sub_821F9A18);
PPC_FUNC_IMPL(__imp__sub_821F9A18) {
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
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x821F9A30;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f9a68
	if (cr6.eq) goto loc_821F9A68;
	// bl 0x82217b78
	ctx.lr = 0x821F9A40;
	sub_82217B78(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-21492
	ctx.r9.s64 = r11.s64 + -21492;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10244(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10244, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821F9A68:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10244(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10244, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821F9A88"))) PPC_WEAK_FUNC(sub_821F9A88);
PPC_FUNC_IMPL(__imp__sub_821F9A88) {
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
	// li r3,1348
	ctx.r3.s64 = 1348;
	// bl 0x82130528
	ctx.lr = 0x821F9A9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f9ac0
	if (cr6.eq) goto loc_821F9AC0;
	// bl 0x821f8690
	ctx.lr = 0x821F9AA8;
	sub_821F8690(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-10228(r11)
	PPC_STORE_U32(r11.u32 + -10228, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821F9AC0:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10228(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10228, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9ADC"))) PPC_WEAK_FUNC(sub_821F9ADC);
PPC_FUNC_IMPL(__imp__sub_821F9ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9AE0"))) PPC_WEAK_FUNC(sub_821F9AE0);
PPC_FUNC_IMPL(__imp__sub_821F9AE0) {
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
	ctx.lr = 0x821F9AE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,-21484
	ctx.r10.s64 = r11.s64 + -21484;
	// lwz r30,176(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f9b1c
	if (cr6.eq) goto loc_821F9B1C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217cb48
	ctx.lr = 0x821F9B14;
	sub_8217CB48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821F9B1C;
	sub_82130588(ctx, base);
loc_821F9B1C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x821F9B24;
	sub_82633B00(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9b3c
	if (cr6.eq) goto loc_821F9B3C;
	// bl 0x82130588
	ctx.lr = 0x821F9B38;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F9B3C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F9B44"))) PPC_WEAK_FUNC(sub_821F9B44);
PPC_FUNC_IMPL(__imp__sub_821F9B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9B48"))) PPC_WEAK_FUNC(sub_821F9B48);
PPC_FUNC_IMPL(__imp__sub_821F9B48) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r30,92
	ctx.r4.s64 = r30.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x821F9B74;
	sub_823DB670(ctx, base);
	// lwz r11,156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// lwz r10,88(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821F9BA0"))) PPC_WEAK_FUNC(sub_821F9BA0);
PPC_FUNC_IMPL(__imp__sub_821F9BA0) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r31,r30,92
	r31.s64 = r30.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db670
	ctx.lr = 0x821F9BC8;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r11.u32);
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

__attribute__((alias("__imp__sub_821F9BEC"))) PPC_WEAK_FUNC(sub_821F9BEC);
PPC_FUNC_IMPL(__imp__sub_821F9BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9BF0"))) PPC_WEAK_FUNC(sub_821F9BF0);
PPC_FUNC_IMPL(__imp__sub_821F9BF0) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-19708
	ctx.r9.s64 = r11.s64 + -19708;
	// addi r8,r10,-21500
	ctx.r8.s64 = ctx.r10.s64 + -21500;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821f9c30
	if (cr6.eq) goto loc_821F9C30;
	// bl 0x82130588
	ctx.lr = 0x821F9C2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F9C30:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821F9C44"))) PPC_WEAK_FUNC(sub_821F9C44);
PPC_FUNC_IMPL(__imp__sub_821F9C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9C48"))) PPC_WEAK_FUNC(sub_821F9C48);
PPC_FUNC_IMPL(__imp__sub_821F9C48) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-19692
	ctx.r10.s64 = r11.s64 + -19692;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,10248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// bl 0x82130588
	ctx.lr = 0x821F9C70;
	sub_82130588(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r11,r31,10244
	r11.s64 = r31.s64 + 10244;
	// li r10,63
	ctx.r10.s64 = 63;
	// addi r9,r9,-21500
	ctx.r9.s64 = ctx.r9.s64 + -21500;
	// addi r8,r8,-19708
	ctx.r8.s64 = ctx.r8.s64 + -19708;
loc_821F9C88:
	// addi r11,r11,-160
	r11.s64 = r11.s64 + -160;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bge 0x821f9c88
	if (!cr0.lt) goto loc_821F9C88;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821F9CB0"))) PPC_WEAK_FUNC(sub_821F9CB0);
PPC_FUNC_IMPL(__imp__sub_821F9CB0) {
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
	// bl 0x821f9c48
	ctx.lr = 0x821F9CD0;
	sub_821F9C48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9ce8
	if (cr6.eq) goto loc_821F9CE8;
	// bl 0x82130588
	ctx.lr = 0x821F9CE4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F9CE8:
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

__attribute__((alias("__imp__sub_821F9D00"))) PPC_WEAK_FUNC(sub_821F9D00);
PPC_FUNC_IMPL(__imp__sub_821F9D00) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,-19684
	ctx.r10.s64 = r11.s64 + -19684;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x825ed460
	ctx.lr = 0x821F9D2C;
	sub_825ED460(ctx, base);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f9d48
	if (cr6.eq) goto loc_821F9D48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ef340
	ctx.lr = 0x821F9D40;
	sub_825EF340(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821F9D48;
	sub_82130588(ctx, base);
loc_821F9D48:
	// addi r3,r31,10260
	ctx.r3.s64 = r31.s64 + 10260;
	// bl 0x827253d0
	ctx.lr = 0x821F9D50;
	sub_827253D0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821f9c48
	ctx.lr = 0x821F9D58;
	sub_821F9C48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x821F9D60;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_821F9D78"))) PPC_WEAK_FUNC(sub_821F9D78);
PPC_FUNC_IMPL(__imp__sub_821F9D78) {
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
	// bl 0x821f9d00
	ctx.lr = 0x821F9D98;
	sub_821F9D00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9db0
	if (cr6.eq) goto loc_821F9DB0;
	// bl 0x82130588
	ctx.lr = 0x821F9DAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F9DB0:
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

__attribute__((alias("__imp__sub_821F9DC8"))) PPC_WEAK_FUNC(sub_821F9DC8);
PPC_FUNC_IMPL(__imp__sub_821F9DC8) {
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
	ctx.lr = 0x821F9DD0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821F9DF0;
	sub_82305870(ctx, base);
	// lis r27,-32120
	r27.s64 = -2105016320;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e5048
	ctx.lr = 0x821F9E08;
	sub_822E5048(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821f7920
	ctx.lr = 0x821F9E14;
	sub_821F7920(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f8960
	ctx.lr = 0x821F9E1C;
	sub_821F8960(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x821F9E28;
	sub_82180430(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r31,1
	r31.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r8,-19664
	ctx.r4.s64 = ctx.r8.s64 + -19664;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r7,256
	ctx.r7.s64 = 256;
	// stb r31,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r31.u8);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F9E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stb r31,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r31.u8);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,5532(r30)
	PPC_STORE_U32(r30.u32 + 5532, ctx.r8.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// addi r4,r7,-19680
	ctx.r4.s64 = ctx.r7.s64 + -19680;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// li r7,256
	ctx.r7.s64 = 256;
	// li r6,256
	ctx.r6.s64 = 256;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// li r5,3
	ctx.r5.s64 = 3;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821F9EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,5528(r30)
	PPC_STORE_U32(r30.u32 + 5528, ctx.r3.u32);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x821F9ED0;
	sub_822E50B8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821F9EDC;
	sub_823058F8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x82213398
	ctx.lr = 0x821F9EE8;
	sub_82213398(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821F9EF0"))) PPC_WEAK_FUNC(sub_821F9EF0);
PPC_FUNC_IMPL(__imp__sub_821F9EF0) {
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
	ctx.lr = 0x821F9EF8;
	// stwu r1,-1680(r1)
	ea = -1680 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// sth r28,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r28.u16);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// sth r28,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r28.u16);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720140
	ctx.lr = 0x821F9F20;
	sub_82720140(ctx, base);
	// lwz r11,13284(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 13284);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9f3c
	if (cr6.eq) goto loc_821F9F3C;
	// lwz r10,-24880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r31)
	PPC_STORE_U32(r31.u32 + -24880, r11.u32);
loc_821F9F3C:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827206c0
	ctx.lr = 0x821F9F4C;
	sub_827206C0(ctx, base);
	// lwz r11,13284(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 13284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f9f64
	if (cr6.eq) goto loc_821F9F64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,-24880(r31)
	PPC_STORE_U32(r31.u32 + -24880, ctx.r10.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
loc_821F9F64:
	// addi r1,r1,1680
	ctx.r1.s64 = ctx.r1.s64 + 1680;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F9F6C"))) PPC_WEAK_FUNC(sub_821F9F6C);
PPC_FUNC_IMPL(__imp__sub_821F9F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9F70"))) PPC_WEAK_FUNC(sub_821F9F70);
PPC_FUNC_IMPL(__imp__sub_821F9F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,13284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r10,-24880(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r9)
	PPC_STORE_U32(ctx.r9.u32 + -24880, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9F90"))) PPC_WEAK_FUNC(sub_821F9F90);
PPC_FUNC_IMPL(__imp__sub_821F9F90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,13284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,-24880(r9)
	PPC_STORE_U32(ctx.r9.u32 + -24880, ctx.r10.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F9FB4"))) PPC_WEAK_FUNC(sub_821F9FB4);
PPC_FUNC_IMPL(__imp__sub_821F9FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F9FB8"))) PPC_WEAK_FUNC(sub_821F9FB8);
PPC_FUNC_IMPL(__imp__sub_821F9FB8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-19636
	ctx.r10.s64 = ctx.r10.s64 + -19636;
loc_821F9FD0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f9ff4
	if (cr6.eq) goto loc_821F9FF4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f9fd0
	if (cr6.eq) goto loc_821F9FD0;
loc_821F9FF4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821fa024
	if (!cr6.eq) goto loc_821FA024;
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA014;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821FA024:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-19648
	ctx.r10.s64 = ctx.r10.s64 + -19648;
loc_821FA030:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821fa054
	if (cr6.eq) goto loc_821FA054;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fa030
	if (cr6.eq) goto loc_821FA030;
loc_821FA054:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821fa084
	if (!cr6.eq) goto loc_821FA084;
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821FA084:
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,60
	ctx.r3.s64 = ctx.r3.s64 + 60;
	// bl 0x826949b0
	ctx.lr = 0x821FA094;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fa0bc
	if (cr6.eq) goto loc_821FA0BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa0bc
	if (cr6.eq) goto loc_821FA0BC;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821FA0BC:
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

__attribute__((alias("__imp__sub_821FA0D0"))) PPC_WEAK_FUNC(sub_821FA0D0);
PPC_FUNC_IMPL(__imp__sub_821FA0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r9,10850(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 10850);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FA0E8"))) PPC_WEAK_FUNC(sub_821FA0E8);
PPC_FUNC_IMPL(__imp__sub_821FA0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826947f0
	sub_826947F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FA0F4"))) PPC_WEAK_FUNC(sub_821FA0F4);
PPC_FUNC_IMPL(__imp__sub_821FA0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA0F8"))) PPC_WEAK_FUNC(sub_821FA0F8);
PPC_FUNC_IMPL(__imp__sub_821FA0F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// stw r9,10712(r11)
	PPC_STORE_U32(r11.u32 + 10712, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FA110"))) PPC_WEAK_FUNC(sub_821FA110);
PPC_FUNC_IMPL(__imp__sub_821FA110) {
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
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa140
	if (cr6.eq) goto loc_821FA140;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204220
	ctx.lr = 0x821FA13C;
	sub_82204220(ctx, base);
	// b 0x821fa144
	goto loc_821FA144;
loc_821FA140:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FA144:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FA164"))) PPC_WEAK_FUNC(sub_821FA164);
PPC_FUNC_IMPL(__imp__sub_821FA164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA168"))) PPC_WEAK_FUNC(sub_821FA168);
PPC_FUNC_IMPL(__imp__sub_821FA168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa18c
	if (cr6.eq) goto loc_821FA18C;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_821FA18C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FA1A0"))) PPC_WEAK_FUNC(sub_821FA1A0);
PPC_FUNC_IMPL(__imp__sub_821FA1A0) {
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
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa1e8
	if (cr6.eq) goto loc_821FA1E8;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821fa1e8
	if (cr6.eq) goto loc_821FA1E8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FA1E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821fa1ec
	goto loc_821FA1EC;
loc_821FA1E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FA1EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FA20C"))) PPC_WEAK_FUNC(sub_821FA20C);
PPC_FUNC_IMPL(__imp__sub_821FA20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA210"))) PPC_WEAK_FUNC(sub_821FA210);
PPC_FUNC_IMPL(__imp__sub_821FA210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// ori r9,r10,3600
	ctx.r9.u64 = ctx.r10.u64 | 3600;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// b 0x82695c78
	sub_82695C78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FA230"))) PPC_WEAK_FUNC(sub_821FA230);
PPC_FUNC_IMPL(__imp__sub_821FA230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa250
	if (cr6.eq) goto loc_821FA250;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// b 0x82691650
	sub_82691650(ctx, base);
	return;
loc_821FA250:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FA258"))) PPC_WEAK_FUNC(sub_821FA258);
PPC_FUNC_IMPL(__imp__sub_821FA258) {
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
	ctx.lr = 0x821FA260;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r11,104
	r30.s64 = r11.s64 + 104;
	// addi r29,r11,232
	r29.s64 = r11.s64 + 232;
	// beq cr6,0x821fa34c
	if (cr6.eq) goto loc_821FA34C;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x821fa2a4
	if (!cr6.eq) goto loc_821FA2A4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r11,-19588(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -19588);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x821fa2b8
	goto loc_821FA2B8;
loc_821FA2A4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r4,1
	ctx.r5.s64 = ctx.r4.s64 + 1;
	// addi r4,r11,-19600
	ctx.r4.s64 = r11.s64 + -19600;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dc018
	ctx.lr = 0x821FA2B8;
	sub_823DC018(ctx, base);
loc_821FA2B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA2D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-19612
	ctx.r4.s64 = ctx.r9.s64 + -19612;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x821FA2E4;
	sub_8268DA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-19624
	ctx.r4.s64 = r11.s64 + -19624;
	// beq cr6,0x821fa324
	if (cr6.eq) goto loc_821FA324;
	// bl 0x8268da78
	ctx.lr = 0x821FA304;
	sub_8268DA78(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268f078
	ctx.lr = 0x821FA310;
	sub_8268F078(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r10.u32);
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// b 0x821fa32c
	goto loc_821FA32C;
loc_821FA324:
	// bl 0x8268da78
	ctx.lr = 0x821FA328;
	sub_8268DA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_821FA32C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fa34c
	if (cr6.eq) goto loc_821FA34C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8223de50
	ctx.lr = 0x821FA340;
	sub_8223DE50(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_821FA34C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821FA354"))) PPC_WEAK_FUNC(sub_821FA354);
PPC_FUNC_IMPL(__imp__sub_821FA354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA358"))) PPC_WEAK_FUNC(sub_821FA358);
PPC_FUNC_IMPL(__imp__sub_821FA358) {
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
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FA380;
	sub_82305870(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822160d0
	ctx.lr = 0x821FA388;
	sub_822160D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r9,r10,3600
	ctx.r9.u64 = ctx.r10.u64 | 3600;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x82696c88
	ctx.lr = 0x821FA3A8;
	sub_82696C88(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FA3B4;
	sub_823058F8(ctx, base);
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

__attribute__((alias("__imp__sub_821FA3CC"))) PPC_WEAK_FUNC(sub_821FA3CC);
PPC_FUNC_IMPL(__imp__sub_821FA3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA3D0"))) PPC_WEAK_FUNC(sub_821FA3D0);
PPC_FUNC_IMPL(__imp__sub_821FA3D0) {
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
	ctx.lr = 0x821FA3D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FA3F4;
	sub_82305870(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822160d0
	ctx.lr = 0x821FA3FC;
	sub_822160D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// ori r9,r10,3600
	ctx.r9.u64 = ctx.r10.u64 | 3600;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x82695c20
	ctx.lr = 0x821FA420;
	sub_82695C20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FA42C;
	sub_823058F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FA434"))) PPC_WEAK_FUNC(sub_821FA434);
PPC_FUNC_IMPL(__imp__sub_821FA434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA438"))) PPC_WEAK_FUNC(sub_821FA438);
PPC_FUNC_IMPL(__imp__sub_821FA438) {
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
	ctx.lr = 0x821FA440;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa5b4
	if (cr6.eq) goto loc_821FA5B4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-26880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26880);
	// bl 0x8217c658
	ctx.lr = 0x821FA46C;
	sub_8217C658(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82178370
	ctx.lr = 0x821FA494;
	sub_82178370(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8218f308
	ctx.lr = 0x821FA4A0;
	sub_8218F308(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f31,272(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f31,276(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f31,280(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// sth r8,288(r1)
	PPC_STORE_U16(ctx.r1.u32 + 288, ctx.r8.u16);
	// stfs f31,284(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x821800a0
	ctx.lr = 0x821FA4D4;
	sub_821800A0(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r4,r6,-31280
	ctx.r4.s64 = ctx.r6.s64 + -31280;
	// lwz r3,-26876(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x821FA4E8;
	sub_8217C088(ctx, base);
	// li r3,38
	ctx.r3.s64 = 38;
	// bl 0x8217fed0
	ctx.lr = 0x821FA4F0;
	sub_8217FED0(ctx, base);
	// cntlzw r5,r3
	ctx.r5.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// li r3,38
	ctx.r3.s64 = 38;
	// xori r29,r11,1
	r29.u64 = r11.u64 ^ 1;
	// bl 0x8217f768
	ctx.lr = 0x821FA508;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x821FA514;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x821FA520;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x821FA52C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x821FA538;
	sub_8217F768(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x821fa550
	if (!cr6.lt) goto loc_821FA550;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_821FA550:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x821FA558;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x821FA564;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x821FA570;
	sub_8217F768(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x821FA590;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x821FA59C;
	sub_8217F768(ctx, base);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// li r3,38
	ctx.r3.s64 = 38;
	// bl 0x8217f768
	ctx.lr = 0x821FA5A8;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217c658
	ctx.lr = 0x821FA5B4;
	sub_8217C658(ctx, base);
loc_821FA5B4:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FA5C0"))) PPC_WEAK_FUNC(sub_821FA5C0);
PPC_FUNC_IMPL(__imp__sub_821FA5C0) {
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
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
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
	// bl 0x823d91d8
	ctx.lr = 0x821FA5C8;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9b4
	ctx.lr = 0x821FA5D0;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// fmr f28,f2
	f28.f64 = ctx.f2.f64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// fmr f24,f3
	f24.f64 = ctx.f3.f64;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// fmr f22,f4
	f22.f64 = ctx.f4.f64;
	// fmr f26,f5
	f26.f64 = ctx.f5.f64;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fa904
	if (cr6.eq) goto loc_821FA904;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r21,1
	r21.s64 = 1;
	// lwz r20,-26876(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c658
	ctx.lr = 0x821FA618;
	sub_8217C658(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,580(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 580);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FA62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,580(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 580);
	// lfs f29,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f29.f64 = double(temp.f32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821FA648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f23,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f23.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,580(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 580);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x821FA660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fadds f27,f0,f13
	f27.f64 = double(float(f0.f64 + ctx.f13.f64));
	// beq cr6,0x821fa68c
	if (cr6.eq) goto loc_821FA68C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fsubs f29,f29,f0
	f29.f64 = double(float(f29.f64 - f0.f64));
	// fsubs f23,f23,f0
	f23.f64 = double(float(f23.f64 - f0.f64));
	// fsubs f27,f27,f0
	f27.f64 = double(float(f27.f64 - f0.f64));
loc_821FA68C:
	// lwz r22,420(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x821fa6b4
	if (cr6.eq) goto loc_821FA6B4;
	// lwz r11,428(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 428);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82187f40
	ctx.lr = 0x821FA6B0;
	sub_82187F40(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
loc_821FA6B4:
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA6C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x821fa8e8
	if (!cr6.gt) goto loc_821FA8E8;
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// fneg f30,f31
	ctx.fpscr.disableFlushMode();
	f30.u64 = f31.u64 ^ 0x8000000000000000;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,8
	r26.s64 = 8;
	// rlwinm r24,r11,1,0,30
	r24.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r25,r31,188
	r25.s64 = r31.s64 + 188;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_821FA6F8:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x821fa70c
	if (cr6.eq) goto loc_821FA70C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82187b88
	ctx.lr = 0x821FA70C;
	sub_82187B88(ctx, base);
loc_821FA70C:
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r26,r27
	PPC_STORE_U32(r26.u32 + r27.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821fa728
	if (!cr6.eq) goto loc_821FA728;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8218f118
	ctx.lr = 0x821FA728;
	sub_8218F118(ctx, base);
loc_821FA728:
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// fmr f9,f26
	ctx.f9.f64 = f26.f64;
	// fmr f8,f22
	ctx.f8.f64 = f22.f64;
	// fmr f7,f24
	ctx.f7.f64 = f24.f64;
	// fmr f6,f28
	ctx.f6.f64 = f28.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f27
	ctx.f4.f64 = f27.f64;
	// fadds f3,f29,f0
	ctx.f3.f64 = double(float(f29.f64 + f0.f64));
	// fmr f2,f23
	ctx.f2.f64 = f23.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8218f138
	ctx.lr = 0x821FA758;
	sub_8218F138(ctx, base);
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r26,r27
	PPC_STORE_U32(r26.u32 + r27.u32, r11.u32);
	// bne 0x821fa76c
	if (!cr0.eq) goto loc_821FA76C;
	// bl 0x8218f130
	ctx.lr = 0x821FA76C;
	sub_8218F130(ctx, base);
loc_821FA76C:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x821FA778;
	sub_8217BB68(ctx, base);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fmr f8,f24
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f24.f64;
	// fmr f7,f28
	ctx.f7.f64 = f28.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f2,f23
	ctx.f2.f64 = f23.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8217bc28
	ctx.lr = 0x821FA7A0;
	sub_8217BC28(ctx, base);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fmr f8,f24
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f24.f64;
	// fmr f7,f22
	ctx.f7.f64 = f22.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8217bc28
	ctx.lr = 0x821FA7C8;
	sub_8217BC28(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821fa8c8
	if (!cr6.gt) goto loc_821FA8C8;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f25,f13
	f25.f64 = double(float(ctx.f13.f64));
loc_821FA7E8:
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FA804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lfs f13,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfs f10,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f0,f9,f8
	f0.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x821fa834
	if (!cr6.gt) goto loc_821FA834;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_821FA834:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// lfs f12,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f9,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f9.f64 = double(temp.f32);
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fsubs f20,f27,f1
	f20.f64 = double(float(f27.f64 - ctx.f1.f64));
	// fmuls f21,f9,f12
	f21.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmr f8,f26
	ctx.f8.f64 = f26.f64;
	// fmr f7,f28
	ctx.f7.f64 = f28.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmuls f0,f2,f13
	f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fsubs f2,f20,f21
	ctx.f2.f64 = double(float(f20.f64 - f21.f64));
	// fdivs f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 / f25.f64));
	// fadds f19,f13,f29
	f19.f64 = double(float(ctx.f13.f64 + f29.f64));
	// fmr f1,f19
	ctx.f1.f64 = f19.f64;
	// bl 0x8217bc28
	ctx.lr = 0x821FA894;
	sub_8217BC28(ctx, base);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// fmr f8,f26
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f26.f64;
	// fmr f7,f28
	ctx.f7.f64 = f28.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fadds f2,f20,f21
	ctx.f2.f64 = double(float(f20.f64 + f21.f64));
	// fmr f1,f19
	ctx.f1.f64 = f19.f64;
	// bl 0x8217bc28
	ctx.lr = 0x821FA8BC;
	sub_8217BC28(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x821fa7e8
	if (cr6.lt) goto loc_821FA7E8;
loc_821FA8C8:
	// bl 0x8217bc98
	ctx.lr = 0x821FA8CC;
	sub_8217BC98(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x821fa8dc
	if (cr6.eq) goto loc_821FA8DC;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82187ba8
	ctx.lr = 0x821FA8DC;
	sub_82187BA8(ctx, base);
loc_821FA8DC:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpw cr6,r23,r21
	cr6.compare<int32_t>(r23.s32, r21.s32, xer);
	// blt cr6,0x821fa6f8
	if (cr6.lt) goto loc_821FA6F8;
loc_821FA8E8:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x821fa8f8
	if (cr6.eq) goto loc_821FA8F8;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82187bd0
	ctx.lr = 0x821FA8F8;
	sub_82187BD0(ctx, base);
loc_821FA8F8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8217c658
	ctx.lr = 0x821FA904;
	sub_8217C658(ctx, base);
loc_821FA904:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba00
	ctx.lr = 0x821FA910;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_821FA914"))) PPC_WEAK_FUNC(sub_821FA914);
PPC_FUNC_IMPL(__imp__sub_821FA914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA918"))) PPC_WEAK_FUNC(sub_821FA918);
PPC_FUNC_IMPL(__imp__sub_821FA918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-18932
	ctx.r5.s64 = ctx.r10.s64 + -18932;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,208
	ctx.r6.s64 = r11.s64 + 208;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FA93C"))) PPC_WEAK_FUNC(sub_821FA93C);
PPC_FUNC_IMPL(__imp__sub_821FA93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FA940"))) PPC_WEAK_FUNC(sub_821FA940);
PPC_FUNC_IMPL(__imp__sub_821FA940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x821FA964;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fa9c4
	if (cr6.eq) goto loc_821FA9C4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fa9c4
	if (cr6.eq) goto loc_821FA9C4;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lfs f5,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f5.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x821fa5c0
	ctx.lr = 0x821FA9C4;
	sub_821FA5C0(ctx, base);
loc_821FA9C4:
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

__attribute__((alias("__imp__sub_821FA9D8"))) PPC_WEAK_FUNC(sub_821FA9D8);
PPC_FUNC_IMPL(__imp__sub_821FA9D8) {
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
	ctx.lr = 0x821FA9E0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x821faa8c
	if (!cr6.eq) goto loc_821FAA8C;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,68
	r26.s64 = 68;
	// lwz r25,0(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r30,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, r30.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bc6b8
	ctx.lr = 0x821FAA18;
	sub_821BC6B8(ctx, base);
	// li r29,60
	r29.s64 = 60;
	// lis r24,-32112
	r24.s64 = -2104492032;
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stwx r9,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r11,23572(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 23572);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,23572(r24)
	PPC_STORE_U32(r24.u32 + 23572, r11.u32);
	// bl 0x825ef238
	ctx.lr = 0x821FAA58;
	sub_825EF238(ctx, base);
	// sth r28,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r28.u16);
	// sth r28,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r28.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x821FAA6C;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x821FAA74;
	sub_8276D240(ctx, base);
	// lwz r11,23572(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 23572);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r28,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, r28.u32);
	// stw r11,23572(r24)
	PPC_STORE_U32(r24.u32 + 23572, r11.u32);
	// stwx r8,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r8.u32);
loc_821FAA8C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821FAA94"))) PPC_WEAK_FUNC(sub_821FAA94);
PPC_FUNC_IMPL(__imp__sub_821FAA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FAA98"))) PPC_WEAK_FUNC(sub_821FAA98);
PPC_FUNC_IMPL(__imp__sub_821FAA98) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r31,2836(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2836);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821faacc
	if (cr6.eq) goto loc_821FAACC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7fb8
	ctx.lr = 0x821FAAC4;
	sub_821F7FB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821FAACC;
	sub_82130588(ctx, base);
loc_821FAACC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2836(r30)
	PPC_STORE_U32(r30.u32 + 2836, r11.u32);
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

__attribute__((alias("__imp__sub_821FAAEC"))) PPC_WEAK_FUNC(sub_821FAAEC);
PPC_FUNC_IMPL(__imp__sub_821FAAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FAAF0"))) PPC_WEAK_FUNC(sub_821FAAF0);
PPC_FUNC_IMPL(__imp__sub_821FAAF0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r10,-21500
	ctx.r9.s64 = ctx.r10.s64 + -21500;
	// stw r5,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r5.u32);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// beq cr6,0x821fab48
	if (cr6.eq) goto loc_821FAB48;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r30,20
	ctx.r4.s64 = r30.s64 + 20;
	// bl 0x823db670
	ctx.lr = 0x821FAB40;
	sub_823DB670(ctx, base);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// b 0x821fab4c
	goto loc_821FAB4C;
loc_821FAB48:
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_821FAB4C:
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

__attribute__((alias("__imp__sub_821FAB68"))) PPC_WEAK_FUNC(sub_821FAB68);
PPC_FUNC_IMPL(__imp__sub_821FAB68) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-18912
	ctx.r10.s64 = r11.s64 + -18912;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821f9d00
	ctx.lr = 0x821FAB94;
	sub_821F9D00(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fabac
	if (cr6.eq) goto loc_821FABAC;
	// bl 0x82130588
	ctx.lr = 0x821FABA8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821FABAC:
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

__attribute__((alias("__imp__sub_821FABC4"))) PPC_WEAK_FUNC(sub_821FABC4);
PPC_FUNC_IMPL(__imp__sub_821FABC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FABC8"))) PPC_WEAK_FUNC(sub_821FABC8);
PPC_FUNC_IMPL(__imp__sub_821FABC8) {
	PPC_FUNC_PROLOGUE();
	// b 0x821fa9d8
	sub_821FA9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FABCC"))) PPC_WEAK_FUNC(sub_821FABCC);
PPC_FUNC_IMPL(__imp__sub_821FABCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FABD0"))) PPC_WEAK_FUNC(sub_821FABD0);
PPC_FUNC_IMPL(__imp__sub_821FABD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821fac00
	if (cr6.eq) goto loc_821FAC00;
	// stw r4,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
loc_821FAC00:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x821fac24
	if (!cr6.eq) goto loc_821FAC24;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// blr 
	return;
loc_821FAC24:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x821fac44
	if (!cr6.eq) goto loc_821FAC44;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// blr 
	return;
loc_821FAC44:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FAC60"))) PPC_WEAK_FUNC(sub_821FAC60);
PPC_FUNC_IMPL(__imp__sub_821FAC60) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fad20
	if (cr6.eq) goto loc_821FAD20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9550
	ctx.lr = 0x821FAC90;
	sub_821C9550(ctx, base);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// divwu r9,r3,r10
	ctx.r9.u32 = ctx.r3.u32 / ctx.r10.u32;
	// twllei r10,0
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821fad20
	if (cr6.eq) goto loc_821FAD20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r11,3998
	ctx.r6.s64 = r11.s64 + 3998;
loc_821FACC4:
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lhz r11,4(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821facdc
	if (cr6.eq) goto loc_821FACDC;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// b 0x821face0
	goto loc_821FACE0;
loc_821FACDC:
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_821FACE0:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_821FACE4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x821fad08
	if (cr6.eq) goto loc_821FAD08;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821face4
	if (cr6.eq) goto loc_821FACE4;
loc_821FAD08:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fad3c
	if (cr6.eq) goto loc_821FAD3C;
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addi r8,r7,12
	ctx.r8.s64 = ctx.r7.s64 + 12;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821facc4
	if (!cr6.eq) goto loc_821FACC4;
loc_821FAD20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FAD24:
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
loc_821FAD3C:
	// lwz r31,0(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// beq cr6,0x821fad60
	if (cr6.eq) goto loc_821FAD60;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821FAD58;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821FAD60;
	sub_82130588(ctx, base);
loc_821FAD60:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r10.u16);
	// b 0x821fad24
	goto loc_821FAD24;
}

__attribute__((alias("__imp__sub_821FAD78"))) PPC_WEAK_FUNC(sub_821FAD78);
PPC_FUNC_IMPL(__imp__sub_821FAD78) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb074
	if (cr6.eq) goto loc_821FB074;
	// lwz r10,10688(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10688);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// beq cr6,0x821fb020
	if (cr6.eq) goto loc_821FB020;
	// lwz r10,10692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10692);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// beq cr6,0x821fb020
	if (cr6.eq) goto loc_821FB020;
	// lwz r10,10676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10676);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x821faddc
	if (!cr6.eq) goto loc_821FADDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,-31280
	ctx.r3.s64 = ctx.r3.s64 + -31280;
	// bl 0x826402c0
	ctx.lr = 0x821FADD8;
	sub_826402C0(ctx, base);
	// b 0x821fb074
	goto loc_821FB074;
loc_821FADDC:
	// lwz r10,10664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10664);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x821fae04
	if (!cr6.eq) goto loc_821FAE04;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,-22444
	ctx.r3.s64 = r11.s64 + -22444;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8268ee10
	ctx.lr = 0x821FAE00;
	sub_8268EE10(ctx, base);
	// b 0x821fb074
	goto loc_821FB074;
loc_821FAE04:
	// lwz r10,10668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10668);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x821faf48
	if (!cr6.eq) goto loc_821FAF48;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stw r31,10708(r11)
	PPC_STORE_U32(r11.u32 + 10708, r31.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fae3c
	if (cr6.eq) goto loc_821FAE3C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18792
	ctx.r4.s64 = ctx.r10.s64 + -18792;
	// bl 0x82691650
	ctx.lr = 0x821FAE38;
	sub_82691650(ctx, base);
	// b 0x821fae40
	goto loc_821FAE40;
loc_821FAE3C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FAE40:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-21680
	ctx.r6.s64 = r11.s64 + -21680;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821FAE5C;
	sub_823DEDD8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,136(r3)
	PPC_STORE_U8(ctx.r3.u32 + 136, ctx.r9.u8);
	// bl 0x82256058
	ctx.lr = 0x821FAE68;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821faee0
	if (cr6.eq) goto loc_821FAEE0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fae94
	if (cr6.eq) goto loc_821FAE94;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18800
	ctx.r4.s64 = ctx.r10.s64 + -18800;
	// bl 0x82691650
	ctx.lr = 0x821FAE90;
	sub_82691650(ctx, base);
	// b 0x821fae98
	goto loc_821FAE98;
loc_821FAE94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FAE98:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FAEA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821faee0
	if (cr6.eq) goto loc_821FAEE0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821faf0c
	if (cr6.eq) goto loc_821FAF0C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18820
	ctx.r4.s64 = ctx.r10.s64 + -18820;
	// bl 0x82691650
	ctx.lr = 0x821FAED8;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821faf10
	goto loc_821FAF10;
loc_821FAEE0:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821faf0c
	if (cr6.eq) goto loc_821FAF0C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18844
	ctx.r4.s64 = ctx.r10.s64 + -18844;
	// bl 0x82691650
	ctx.lr = 0x821FAF04;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821faf10
	goto loc_821FAF10;
loc_821FAF0C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821FAF10:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FAF24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,57
	ctx.r4.s64 = 57;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8268ee10
	ctx.lr = 0x821FAF44;
	sub_8268EE10(ctx, base);
	// b 0x821fb074
	goto loc_821FB074;
loc_821FAF48:
	// lwz r10,10672(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10672);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x821fafc8
	if (!cr6.eq) goto loc_821FAFC8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r10,10708(r11)
	PPC_STORE_U32(r11.u32 + 10708, ctx.r10.u32);
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821faf84
	if (cr6.eq) goto loc_821FAF84;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18792
	ctx.r4.s64 = ctx.r10.s64 + -18792;
	// bl 0x82691650
	ctx.lr = 0x821FAF80;
	sub_82691650(ctx, base);
	// b 0x821faf88
	goto loc_821FAF88;
loc_821FAF84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FAF88:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-21680
	ctx.r6.s64 = r11.s64 + -21680;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821FAFA4;
	sub_823DEDD8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stb r9,136(r3)
	PPC_STORE_U8(ctx.r3.u32 + 136, ctx.r9.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r8,-22444
	ctx.r3.s64 = ctx.r8.s64 + -22444;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8268ee10
	ctx.lr = 0x821FAFC4;
	sub_8268EE10(ctx, base);
	// b 0x821fb074
	goto loc_821FB074;
loc_821FAFC8:
	// lwz r10,10696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10696);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// beq cr6,0x821faff8
	if (cr6.eq) goto loc_821FAFF8;
	// lwz r11,10700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 10700);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x821faff8
	if (cr6.eq) goto loc_821FAFF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r10,272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FAFF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821fb078
	goto loc_821FB078;
loc_821FAFF8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-18908
	ctx.r3.s64 = r11.s64 + -18908;
	// bl 0x82130000
	ctx.lr = 0x821FB004;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-10220(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb074
	if (cr6.eq) goto loc_821FB074;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82622d20
	ctx.lr = 0x821FB01C;
	sub_82622D20(ctx, base);
	// b 0x821fb074
	goto loc_821FB074;
loc_821FB020:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,38
	ctx.r4.s64 = 38;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x821FB038;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FB04C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fb074
	if (cr6.eq) goto loc_821FB074;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264c088
	ctx.lr = 0x821FB060;
	sub_8264C088(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FB074:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FB078:
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

__attribute__((alias("__imp__sub_821FB090"))) PPC_WEAK_FUNC(sub_821FB090);
PPC_FUNC_IMPL(__imp__sub_821FB090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x821FB098;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FB0B0;
	sub_82305870(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-10232(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10232);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8223dad8
	ctx.lr = 0x821FB0C8;
	sub_8223DAD8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r9,29952
	ctx.r8.s64 = ctx.r9.s64 + 29952;
	// lwz r11,-6432(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6432);
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// lfs f1,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821FB0F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8220ed58
	ctx.lr = 0x821FB0FC;
	sub_8220ED58(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,-18780
	ctx.r4.s64 = ctx.r4.s64 + -18780;
	// lwz r11,-10028(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10028);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x821f9fb8
	ctx.lr = 0x821FB118;
	sub_821F9FB8(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FB138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r30,r31,7520
	r30.s64 = r31.s64 + 7520;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,492(r8)
	PPC_STORE_U32(ctx.r8.u32 + 492, r30.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821FB15C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lis r4,-32221
	ctx.r4.s64 = -2111635456;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,29152
	ctx.r4.s64 = ctx.r4.s64 + 29152;
	// stw r30,492(r5)
	PPC_STORE_U32(ctx.r5.u32 + 492, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,56(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// stw r30,492(r11)
	PPC_STORE_U32(r11.u32 + 492, r30.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r5,r11,224
	ctx.r5.s64 = r11.s64 + 224;
	// lwz r31,56(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// bl 0x821c2fb0
	ctx.lr = 0x821FB190;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r7,r9,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82722b78
	ctx.lr = 0x821FB1B0;
	sub_82722B78(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FB1BC;
	sub_823058F8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FB1C4"))) PPC_WEAK_FUNC(sub_821FB1C4);
PPC_FUNC_IMPL(__imp__sub_821FB1C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FB1C8"))) PPC_WEAK_FUNC(sub_821FB1C8);
PPC_FUNC_IMPL(__imp__sub_821FB1C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821FB1D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lbz r11,4408(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4408);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb5c4
	if (cr6.eq) goto loc_821FB5C4;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-17944(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FB1FC;
	sub_82305870(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r27,6
	cr6.compare<uint32_t>(r27.u32, 6, xer);
	// bgt cr6,0x821fb44c
	if (cr6.gt) goto loc_821FB44C;
	// lis r12,-32224
	r12.s64 = -2111832064;
	// addi r12,r12,-19936
	r12.s64 = r12.s64 + -19936;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_821FB284;
	case 1:
		goto loc_821FB284;
	case 2:
		goto loc_821FB2DC;
	case 3:
		goto loc_821FB44C;
	case 4:
		goto loc_821FB44C;
	case 5:
		goto loc_821FB44C;
	case 6:
		goto loc_821FB23C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-19836(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19836);
	// lwz r16,-19836(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19836);
	// lwz r16,-19748(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19748);
	// lwz r16,-19380(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19380);
	// lwz r16,-19380(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19380);
	// lwz r16,-19380(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19380);
	// lwz r16,-19908(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -19908);
loc_821FB23C:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x821fb268
	if (cr6.eq) goto loc_821FB268;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x821fb44c
	if (!cr6.eq) goto loc_821FB44C;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x821FB258;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82189e80
	ctx.lr = 0x821FB264;
	sub_82189E80(ctx, base);
	// b 0x821fb44c
	goto loc_821FB44C;
loc_821FB268:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x821FB274;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82189e80
	ctx.lr = 0x821FB280;
	sub_82189E80(ctx, base);
	// b 0x821fb44c
	goto loc_821FB44C;
loc_821FB284:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82189e80
	ctx.lr = 0x821FB290;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x82189e80
	ctx.lr = 0x821FB29C;
	sub_82189E80(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x821FB2A8;
	sub_82189E80(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x821FB2B4;
	sub_82189E80(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82189e80
	ctx.lr = 0x821FB2C0;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,26
	ctx.r3.s64 = 26;
	// bl 0x82189e80
	ctx.lr = 0x821FB2CC;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x82189e80
	ctx.lr = 0x821FB2D8;
	sub_82189E80(ctx, base);
	// b 0x821fb44c
	goto loc_821FB44C;
loc_821FB2DC:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x821fb300
	if (cr6.eq) goto loc_821FB300;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x821fb318
	if (!cr6.eq) goto loc_821FB318;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x821FB2F8;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821fb310
	goto loc_821FB310;
loc_821FB300:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x821FB30C;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_821FB310:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82189e80
	ctx.lr = 0x821FB318;
	sub_82189E80(ctx, base);
loc_821FB318:
	// lwz r11,-10228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10228);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb448
	if (cr6.eq) goto loc_821FB448;
	// lwz r10,456(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 456);
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FB338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fb448
	if (cr6.eq) goto loc_821FB448;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb36c
	if (cr6.eq) goto loc_821FB36C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18724
	ctx.r4.s64 = ctx.r10.s64 + -18724;
	// bl 0x82691650
	ctx.lr = 0x821FB368;
	sub_82691650(ctx, base);
	// b 0x821fb370
	goto loc_821FB370;
loc_821FB36C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FB370:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821fb418
	if (!cr6.eq) goto loc_821FB418;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb3b0
	if (cr6.eq) goto loc_821FB3B0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18740
	ctx.r4.s64 = ctx.r10.s64 + -18740;
	// bl 0x82691650
	ctx.lr = 0x821FB3AC;
	sub_82691650(ctx, base);
	// b 0x821fb3b4
	goto loc_821FB3B4;
loc_821FB3B0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FB3B4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB3C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821fb418
	if (!cr6.eq) goto loc_821FB418;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb3f4
	if (cr6.eq) goto loc_821FB3F4;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-18756
	ctx.r4.s64 = ctx.r10.s64 + -18756;
	// bl 0x82691650
	ctx.lr = 0x821FB3F0;
	sub_82691650(ctx, base);
	// b 0x821fb3f8
	goto loc_821FB3F8;
loc_821FB3F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FB3F8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fb41c
	if (cr6.eq) goto loc_821FB41C;
loc_821FB418:
	// li r11,1
	r11.s64 = 1;
loc_821FB41C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82178370
	ctx.lr = 0x821FB444;
	sub_82178370(ctx, base);
	// b 0x821fb44c
	goto loc_821FB44C;
loc_821FB448:
	// bl 0x82722140
	ctx.lr = 0x821FB44C;
	sub_82722140(ctx, base);
loc_821FB44C:
	// lwz r11,-10228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10228);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb480
	if (cr6.eq) goto loc_821FB480;
	// lwz r10,456(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 456);
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FB470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fb480
	if (cr6.eq) goto loc_821FB480;
	// li r31,1
	r31.s64 = 1;
loc_821FB480:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fb4b8
	if (!cr6.eq) goto loc_821FB4B8;
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb4b8
	if (cr6.eq) goto loc_821FB4B8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r6,5540(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 5540);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB4B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FB4B8:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x821fb51c
	if (cr6.eq) goto loc_821FB51C;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x821fb56c
	if (!cr6.eq) goto loc_821FB56C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x821FB4D8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb4f0
	if (cr6.eq) goto loc_821FB4F0;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r5,5540(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 5540);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82721258
	ctx.lr = 0x821FB4F0;
	sub_82721258(ctx, base);
loc_821FB4F0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-21652
	ctx.r4.s64 = r11.s64 + -21652;
	// bl 0x821f9fb8
	ctx.lr = 0x821FB500;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb56c
	if (cr6.eq) goto loc_821FB56C;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r5,5540(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 5540);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82721258
	ctx.lr = 0x821FB518;
	sub_82721258(ctx, base);
	// b 0x821fb56c
	goto loc_821FB56C;
loc_821FB51C:
	// lhz r29,84(r28)
	r29.u64 = PPC_LOAD_U16(r28.u32 + 84);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x821fb56c
	if (!cr6.gt) goto loc_821FB56C;
	// li r31,0
	r31.s64 = 0;
loc_821FB530:
	// cmpwi cr6,r30,6
	cr6.compare<int32_t>(r30.s32, 6, xer);
	// beq cr6,0x821fb55c
	if (cr6.eq) goto loc_821FB55C;
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lbz r10,69(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 69);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821fb55c
	if (!cr6.eq) goto loc_821FB55C;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,5540(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 5540);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82721258
	ctx.lr = 0x821FB55C;
	sub_82721258(ctx, base);
loc_821FB55C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x821fb530
	if (cr6.lt) goto loc_821FB530;
loc_821FB56C:
	// cmplwi cr6,r27,2
	cr6.compare<uint32_t>(r27.u32, 2, xer);
	// bge cr6,0x821fb5b4
	if (!cr6.lt) goto loc_821FB5B4;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82189e80
	ctx.lr = 0x821FB580;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x821FB58C;
	sub_82189E80(ctx, base);
	// lwz r11,4416(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4416);
	// addi r3,r28,4416
	ctx.r3.s64 = r28.s64 + 4416;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FB5A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4640(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4640);
	// addi r3,r28,4640
	ctx.r3.s64 = r28.s64 + 4640;
	// lwz r8,176(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 176);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FB5B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FB5B4:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-17944(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FB5C0;
	sub_823058F8(ctx, base);
	// bl 0x82722120
	ctx.lr = 0x821FB5C4;
	sub_82722120(ctx, base);
loc_821FB5C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821FB5CC"))) PPC_WEAK_FUNC(sub_821FB5CC);
PPC_FUNC_IMPL(__imp__sub_821FB5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FB5D0"))) PPC_WEAK_FUNC(sub_821FB5D0);
PPC_FUNC_IMPL(__imp__sub_821FB5D0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x821FB5D8;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r5,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r5.u32);
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,76
	ctx.r3.s64 = 76;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lfs f31,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f31.f64 = double(temp.f32);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// bl 0x82130528
	ctx.lr = 0x821FB614;
	sub_82130528(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb64c
	if (cr6.eq) goto loc_821FB64C;
	// lwz r11,-10232(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10232);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lbz r9,271(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 271);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,8
	ctx.r5.s64 = r11.s64 + 8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x827201d8
	ctx.lr = 0x821FB644;
	sub_827201D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x821fb650
	goto loc_821FB650;
loc_821FB64C:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_821FB650:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r10,r27,7520
	ctx.r10.s64 = r27.s64 + 7520;
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r10,492(r11)
	PPC_STORE_U32(r11.u32 + 492, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x821FB664;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fb680
	if (cr6.eq) goto loc_821FB680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// b 0x821fb684
	goto loc_821FB684;
loc_821FB680:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_821FB684:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,212
	ctx.r4.s64 = ctx.r1.s64 + 212;
	// addi r3,r27,60
	ctx.r3.s64 = r27.s64 + 60;
	// bl 0x82695df0
	ctx.lr = 0x821FB698;
	sub_82695DF0(ctx, base);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb6e4
	if (cr6.eq) goto loc_821FB6E4;
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb6d8
	if (cr6.eq) goto loc_821FB6D8;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821fb6cc
	if (cr6.eq) goto loc_821FB6CC;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
loc_821FB6CC:
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// stw r31,72(r27)
	PPC_STORE_U32(r27.u32 + 72, r31.u32);
	// b 0x821fb720
	goto loc_821FB720;
loc_821FB6D8:
	// stw r31,72(r27)
	PPC_STORE_U32(r27.u32 + 72, r31.u32);
	// stw r31,76(r27)
	PPC_STORE_U32(r27.u32 + 76, r31.u32);
	// b 0x821fb720
	goto loc_821FB720;
loc_821FB6E4:
	// lwz r11,76(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// addi r9,r27,72
	ctx.r9.s64 = r27.s64 + 72;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb718
	if (cr6.eq) goto loc_821FB718;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821fb710
	if (cr6.eq) goto loc_821FB710;
	// stw r31,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r31.u32);
loc_821FB710:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// b 0x821fb71c
	goto loc_821FB71C;
loc_821FB718:
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
loc_821FB71C:
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
loc_821FB720:
	// lwz r11,-10232(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10232);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r11,10260
	ctx.r6.s64 = r11.s64 + 10260;
	// bl 0x82720288
	ctx.lr = 0x821FB738;
	sub_82720288(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821FB748"))) PPC_WEAK_FUNC(sub_821FB748);
PPC_FUNC_IMPL(__imp__sub_821FB748) {
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
	ctx.lr = 0x821FB750;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,7088(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 7088);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821fb874
	if (cr6.eq) goto loc_821FB874;
	// lwz r10,7084(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 7084);
	// addi r11,r28,5544
	r11.s64 = r28.s64 + 5544;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// bne cr6,0x821fb780
	if (!cr6.eq) goto loc_821FB780;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_821FB780:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,1544(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1544);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,1540(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1540);
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r8,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r7,1544(r11)
	PPC_STORE_U32(r11.u32 + 1544, ctx.r7.u32);
	// stw r10,1540(r11)
	PPC_STORE_U32(r11.u32 + 1540, ctx.r10.u32);
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// add r31,r9,r11
	r31.u64 = ctx.r9.u64 + r11.u64;
	// bne cr6,0x821fb7b4
	if (!cr6.eq) goto loc_821FB7B4;
	// stw r30,1540(r11)
	PPC_STORE_U32(r11.u32 + 1540, r30.u32);
loc_821FB7B4:
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FB7C4;
	sub_82305870(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lhz r8,82(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// lhz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// stb r30,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r30.u8);
	// bl 0x821fb5d0
	ctx.lr = 0x821FB7F0;
	sub_821FB5D0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r11,-21664
	r11.s64 = r11.s64 + -21664;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_821FB800:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821fb824
	if (cr6.eq) goto loc_821FB824;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fb800
	if (cr6.eq) goto loc_821FB800;
loc_821FB824:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821fb850
	if (!cr6.eq) goto loc_821FB850;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r28,56(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FB84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,408(r28)
	PPC_STORE_U32(r28.u32 + 408, ctx.r3.u32);
loc_821FB850:
	// lbz r11,93(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 93);
	// li r5,31
	ctx.r5.s64 = 31;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// stb r11,71(r30)
	PPC_STORE_U8(r30.u32 + 71, r11.u8);
	// bl 0x823db670
	ctx.lr = 0x821FB868;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FB874;
	sub_823058F8(ctx, base);
loc_821FB874:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FB87C"))) PPC_WEAK_FUNC(sub_821FB87C);
PPC_FUNC_IMPL(__imp__sub_821FB87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FB880"))) PPC_WEAK_FUNC(sub_821FB880);
PPC_FUNC_IMPL(__imp__sub_821FB880) {
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
	ctx.lr = 0x821FB888;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FB8A8;
	sub_82305870(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,13284(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 13284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fb8cc
	if (cr6.eq) goto loc_821FB8CC;
	// lwz r10,-24880(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r27)
	PPC_STORE_U32(r27.u32 + -24880, r11.u32);
loc_821FB8CC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa9d8
	ctx.lr = 0x821FB8D8;
	sub_821FA9D8(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r10,13284(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 13284);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821fb8fc
	if (cr6.eq) goto loc_821FB8FC;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-24880(r27)
	PPC_STORE_U32(r27.u32 + -24880, r11.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
loc_821FB8FC:
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r8,r30,r10
	ctx.r8.u64 = r30.u64 + ctx.r10.u64;
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r11,7124
	ctx.r4.s64 = r11.s64 + 7124;
	// stw r9,7212(r11)
	PPC_STORE_U32(r11.u32 + 7212, ctx.r9.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r3,r11,5544
	ctx.r3.s64 = r11.s64 + 5544;
	// bl 0x821f81a0
	ctx.lr = 0x821FB924;
	sub_821F81A0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FB930;
	sub_823058F8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821FB938"))) PPC_WEAK_FUNC(sub_821FB938);
PPC_FUNC_IMPL(__imp__sub_821FB938) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x821FB940;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// bl 0x82305870
	ctx.lr = 0x821FB974;
	sub_82305870(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// sth r27,160(r1)
	PPC_STORE_U16(ctx.r1.u32 + 160, r27.u16);
	// mr r11,r31
	r11.u64 = r31.u64;
	// sth r26,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r26.u16);
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// stw r25,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r25.u32);
	// stb r24,172(r1)
	PPC_STORE_U8(ctx.r1.u32 + 172, r24.u8);
	// stb r23,173(r1)
	PPC_STORE_U8(ctx.r1.u32 + 173, r23.u8);
loc_821FB994:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821fb994
	if (!cr6.eq) goto loc_821FB994;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_821FB9B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821fb9b4
	if (!cr6.eq) goto loc_821FB9B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7d70
	ctx.lr = 0x821FB9D0;
	sub_821F7D70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,96
	ctx.r5.s64 = 96;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r3,r11,7124
	ctx.r3.s64 = r11.s64 + 7124;
	// bl 0x823da950
	ctx.lr = 0x821FB9F4;
	sub_823DA950(ctx, base);
	// addi r10,r31,1773
	ctx.r10.s64 = r31.s64 + 1773;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r30,r10,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r8,-18304
	ctx.r5.s64 = ctx.r8.s64 + -18304;
	// lfs f1,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r30,r29
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// bl 0x821e27d8
	ctx.lr = 0x821FBA18;
	sub_821E27D8(ctx, base);
	// lwzx r11,r30,r29
	r11.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// lis r7,12288
	ctx.r7.s64 = 805306368;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r5,r6,0,2,3
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r5,r7
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, xer);
	// bne cr6,0x821fba4c
	if (!cr6.eq) goto loc_821FBA4C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// addi r3,r11,5544
	ctx.r3.s64 = r11.s64 + 5544;
	// bl 0x821f81a0
	ctx.lr = 0x821FBA4C;
	sub_821F81A0(ctx, base);
loc_821FBA4C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FBA58;
	sub_823058F8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821FBA60"))) PPC_WEAK_FUNC(sub_821FBA60);
PPC_FUNC_IMPL(__imp__sub_821FBA60) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,-10236(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x82203a78
	ctx.lr = 0x821FBA80;
	sub_82203A78(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// stw r31,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r31.u32);
	// bl 0x8223d5f8
	ctx.lr = 0x821FBA8C;
	sub_8223D5F8(ctx, base);
	// stw r31,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r31.u32);
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

__attribute__((alias("__imp__sub_821FBAA8"))) PPC_WEAK_FUNC(sub_821FBAA8);
PPC_FUNC_IMPL(__imp__sub_821FBAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// b 0x821f9380
	sub_821F9380(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBAB4"))) PPC_WEAK_FUNC(sub_821FBAB4);
PPC_FUNC_IMPL(__imp__sub_821FBAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBAB8"))) PPC_WEAK_FUNC(sub_821FBAB8);
PPC_FUNC_IMPL(__imp__sub_821FBAB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821f96c8
	sub_821F96C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBACC"))) PPC_WEAK_FUNC(sub_821FBACC);
PPC_FUNC_IMPL(__imp__sub_821FBACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBAD0"))) PPC_WEAK_FUNC(sub_821FBAD0);
PPC_FUNC_IMPL(__imp__sub_821FBAD0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x821f9fb8
	ctx.lr = 0x821FBAF8;
	sub_821F9FB8(ctx, base);
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

__attribute__((alias("__imp__sub_821FBB14"))) PPC_WEAK_FUNC(sub_821FBB14);
PPC_FUNC_IMPL(__imp__sub_821FBB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBB18"))) PPC_WEAK_FUNC(sub_821FBB18);
PPC_FUNC_IMPL(__imp__sub_821FBB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r11,104
	ctx.r7.s64 = r11.s64 + 104;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FBB40"))) PPC_WEAK_FUNC(sub_821FBB40);
PPC_FUNC_IMPL(__imp__sub_821FBB40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821fa258
	sub_821FA258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBB58"))) PPC_WEAK_FUNC(sub_821FBB58);
PPC_FUNC_IMPL(__imp__sub_821FBB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821fa358
	sub_821FA358(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBB64"))) PPC_WEAK_FUNC(sub_821FBB64);
PPC_FUNC_IMPL(__imp__sub_821FBB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBB68"))) PPC_WEAK_FUNC(sub_821FBB68);
PPC_FUNC_IMPL(__imp__sub_821FBB68) {
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
	ctx.lr = 0x821FBB70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17944);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82305870
	ctx.lr = 0x821FBB90;
	sub_82305870(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822160d0
	ctx.lr = 0x821FBB98;
	sub_822160D0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r8,r9,3600
	ctx.r8.u64 = ctx.r9.u64 | 3600;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x82695c20
	ctx.lr = 0x821FBBBC;
	sub_82695C20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FBBC8;
	sub_823058F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FBBD0"))) PPC_WEAK_FUNC(sub_821FBBD0);
PPC_FUNC_IMPL(__imp__sub_821FBBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82216168
	sub_82216168(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBBE0"))) PPC_WEAK_FUNC(sub_821FBBE0);
PPC_FUNC_IMPL(__imp__sub_821FBBE0) {
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
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,3600
	ctx.r8.u64 = ctx.r9.u64 | 3600;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x82695c78
	ctx.lr = 0x821FBC18;
	sub_82695C78(ctx, base);
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

__attribute__((alias("__imp__sub_821FBC34"))) PPC_WEAK_FUNC(sub_821FBC34);
PPC_FUNC_IMPL(__imp__sub_821FBC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBC38"))) PPC_WEAK_FUNC(sub_821FBC38);
PPC_FUNC_IMPL(__imp__sub_821FBC38) {
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
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbc8c
	if (cr6.eq) goto loc_821FBC8C;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x821FBC70;
	sub_82691650(ctx, base);
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
loc_821FBC8C:
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

__attribute__((alias("__imp__sub_821FBCAC"))) PPC_WEAK_FUNC(sub_821FBCAC);
PPC_FUNC_IMPL(__imp__sub_821FBCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBCB0"))) PPC_WEAK_FUNC(sub_821FBCB0);
PPC_FUNC_IMPL(__imp__sub_821FBCB0) {
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
	// bl 0x826959b8
	ctx.lr = 0x821FBCD4;
	sub_826959B8(ctx, base);
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

__attribute__((alias("__imp__sub_821FBCF0"))) PPC_WEAK_FUNC(sub_821FBCF0);
PPC_FUNC_IMPL(__imp__sub_821FBCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
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
	// b 0x82695170
	sub_82695170(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD14"))) PPC_WEAK_FUNC(sub_821FBD14);
PPC_FUNC_IMPL(__imp__sub_821FBD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBD18"))) PPC_WEAK_FUNC(sub_821FBD18);
PPC_FUNC_IMPL(__imp__sub_821FBD18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82694e50
	sub_82694E50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD2C"))) PPC_WEAK_FUNC(sub_821FBD2C);
PPC_FUNC_IMPL(__imp__sub_821FBD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBD30"))) PPC_WEAK_FUNC(sub_821FBD30);
PPC_FUNC_IMPL(__imp__sub_821FBD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82694ed0
	sub_82694ED0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD44"))) PPC_WEAK_FUNC(sub_821FBD44);
PPC_FUNC_IMPL(__imp__sub_821FBD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBD48"))) PPC_WEAK_FUNC(sub_821FBD48);
PPC_FUNC_IMPL(__imp__sub_821FBD48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82694f58
	sub_82694F58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD5C"))) PPC_WEAK_FUNC(sub_821FBD5C);
PPC_FUNC_IMPL(__imp__sub_821FBD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBD60"))) PPC_WEAK_FUNC(sub_821FBD60);
PPC_FUNC_IMPL(__imp__sub_821FBD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8223de50
	sub_8223DE50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD70"))) PPC_WEAK_FUNC(sub_821FBD70);
PPC_FUNC_IMPL(__imp__sub_821FBD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lfs f1,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82208800
	sub_82208800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FBD88"))) PPC_WEAK_FUNC(sub_821FBD88);
PPC_FUNC_IMPL(__imp__sub_821FBD88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbdbc
	if (cr6.eq) goto loc_821FBDBC;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,4876(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4876);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4872);
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// blr 
	return;
loc_821FBDBC:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FBDCC"))) PPC_WEAK_FUNC(sub_821FBDCC);
PPC_FUNC_IMPL(__imp__sub_821FBDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FBDD0"))) PPC_WEAK_FUNC(sub_821FBDD0);
PPC_FUNC_IMPL(__imp__sub_821FBDD0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbe04
	if (cr6.eq) goto loc_821FBE04;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x821FBE00;
	sub_82691650(ctx, base);
	// b 0x821fbe08
	goto loc_821FBE08;
loc_821FBE04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FBE08:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-22132
	ctx.r6.s64 = r11.s64 + -22132;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821FBE24;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x821fbe3c
	if (!cr6.eq) goto loc_821FBE3C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_821FBE3C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FBE4C;
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

__attribute__((alias("__imp__sub_821FBE60"))) PPC_WEAK_FUNC(sub_821FBE60);
PPC_FUNC_IMPL(__imp__sub_821FBE60) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbe90
	if (cr6.eq) goto loc_821FBE90;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x821FBE8C;
	sub_82691650(ctx, base);
	// b 0x821fbe94
	goto loc_821FBE94;
loc_821FBE90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FBE94:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-22132
	ctx.r6.s64 = r11.s64 + -22132;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x821FBEB0;
	sub_823DEDD8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,308(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 308);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FBEC0;
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

__attribute__((alias("__imp__sub_821FBED0"))) PPC_WEAK_FUNC(sub_821FBED0);
PPC_FUNC_IMPL(__imp__sub_821FBED0) {
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
	ctx.lr = 0x821FBED8;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x82387928
	ctx.lr = 0x821FBF00;
	sub_82387928(ctx, base);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bne cr6,0x821fbf24
	if (!cr6.eq) goto loc_821FBF24;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r6,r11,-18712
	ctx.r6.s64 = r11.s64 + -18712;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x821f9638
	ctx.lr = 0x821FBF20;
	sub_821F9638(ctx, base);
	// b 0x821fbf38
	goto loc_821FBF38;
loc_821FBF24:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,255
	ctx.r4.s64 = 255;
	// bl 0x82137a08
	ctx.lr = 0x821FBF38;
	sub_82137A08(ctx, base);
loc_821FBF38:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// clrlwi r6,r30,16
	ctx.r6.u64 = r30.u32 & 0xFFFF;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821fb938
	ctx.lr = 0x821FBF60;
	sub_821FB938(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821FBF68"))) PPC_WEAK_FUNC(sub_821FBF68);
PPC_FUNC_IMPL(__imp__sub_821FBF68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x821fbf80
	if (!cr6.eq) goto loc_821FBF80;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_821FBF80:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x821fbf94
	if (!cr6.eq) goto loc_821FBF94;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
loc_821FBF94:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbfa8
	if (cr6.eq) goto loc_821FBFA8;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_821FBFA8:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbfbc
	if (cr6.eq) goto loc_821FBFBC;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_821FBFBC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fbffc
	if (cr6.eq) goto loc_821FBFFC;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fbff0
	if (cr6.eq) goto loc_821FBFF0;
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
loc_821FBFF0:
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// blr 
	return;
loc_821FBFFC:
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FC008"))) PPC_WEAK_FUNC(sub_821FC008);
PPC_FUNC_IMPL(__imp__sub_821FC008) {
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
	// lwz r11,2836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc0a8
	if (cr6.eq) goto loc_821FC0A8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,1000
	cr6.compare<int32_t>(ctx.r10.s32, 1000, xer);
	// ble cr6,0x821fc094
	if (!cr6.gt) goto loc_821FC094;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FC048;
	sub_82305870(ctx, base);
	// lwz r3,2836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc068
	if (cr6.eq) goto loc_821FC068;
	// bl 0x8217a068
	ctx.lr = 0x821FC05C;
	sub_8217A068(ctx, base);
	// lwz r3,2836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// bl 0x821f9918
	ctx.lr = 0x821FC064;
	sub_821F9918(ctx, base);
	// lwz r3,2836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2836);
loc_821FC068:
	// bl 0x821fa438
	ctx.lr = 0x821FC06C;
	sub_821FA438(ctx, base);
	// lwz r11,2836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// lbz r11,12(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc084
	if (cr6.eq) goto loc_821FC084;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217b7b0
	ctx.lr = 0x821FC084;
	sub_8217B7B0(ctx, base);
loc_821FC084:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FC090;
	sub_823058F8(ctx, base);
	// b 0x821fc0a8
	goto loc_821FC0A8;
loc_821FC094:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821fc0a8
	if (!cr6.gt) goto loc_821FC0A8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_821FC0A8:
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

__attribute__((alias("__imp__sub_821FC0C0"))) PPC_WEAK_FUNC(sub_821FC0C0);
PPC_FUNC_IMPL(__imp__sub_821FC0C0) {
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
	// li r3,10272
	ctx.r3.s64 = 10272;
	// bl 0x82130528
	ctx.lr = 0x821FC0D8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821fc110
	if (cr6.eq) goto loc_821FC110;
	// bl 0x82721cc8
	ctx.lr = 0x821FC0E8;
	sub_82721CC8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-18912
	ctx.r9.s64 = r11.s64 + -18912;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10232, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821FC110:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10232, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FC130"))) PPC_WEAK_FUNC(sub_821FC130);
PPC_FUNC_IMPL(__imp__sub_821FC130) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x821fc3ec
	if (cr6.eq) goto loc_821FC3EC;
loc_821FC158:
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x821fc3ec
	if (!cr6.eq) goto loc_821FC3EC;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x821fc2c4
	if (!cr6.eq) goto loc_821FC2C4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc1dc
	if (cr6.eq) goto loc_821FC1DC;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x821fc1dc
	if (!cr6.eq) goto loc_821FC1DC;
	// rotlwi r10,r4,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 | 1;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x821fc3e0
	goto loc_821FC3E0;
loc_821FC1DC:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821fc1f4
	if (!cr6.eq) goto loc_821FC1F4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821fabd0
	ctx.lr = 0x821FC1F4;
	sub_821FABD0(ctx, base);
loc_821FC1F4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r3,r4,0,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r3,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r3.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fc248
	if (cr6.eq) goto loc_821FC248;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
loc_821FC248:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x821fc274
	if (!cr6.eq) goto loc_821FC274;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x821fc3dc
	goto loc_821FC3DC;
loc_821FC274:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r7,r8,0,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bne cr6,0x821fc2ac
	if (!cr6.eq) goto loc_821FC2AC;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x821fc3dc
	goto loc_821FC3DC;
loc_821FC2AC:
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x821fc3dc
	goto loc_821FC3DC;
loc_821FC2C4:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc320
	if (cr6.eq) goto loc_821FC320;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x821fc320
	if (!cr6.eq) goto loc_821FC320;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 | 1;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x821fc3e0
	goto loc_821FC3E0;
loc_821FC320:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821fc338
	if (!cr6.eq) goto loc_821FC338;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824adf98
	ctx.lr = 0x821FC338;
	sub_824ADF98(ctx, base);
loc_821FC338:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r10,r3,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFE;
	// clrlwi r8,r4,31
	ctx.r8.u64 = ctx.r4.u32 & 0x1;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fc394
	if (cr6.eq) goto loc_821FC394;
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
loc_821FC394:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x821fc3b0
	if (!cr6.eq) goto loc_821FC3B0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x821fc3d8
	goto loc_821FC3D8;
loc_821FC3B0:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x821fc3c8
	if (!cr6.eq) goto loc_821FC3C8;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// b 0x821fc3d8
	goto loc_821FC3D8;
loc_821FC3C8:
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
loc_821FC3D8:
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_821FC3DC:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_821FC3E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821fc158
	if (!cr6.eq) goto loc_821FC158;
loc_821FC3EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_821FC414"))) PPC_WEAK_FUNC(sub_821FC414);
PPC_FUNC_IMPL(__imp__sub_821FC414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FC418"))) PPC_WEAK_FUNC(sub_821FC418);
PPC_FUNC_IMPL(__imp__sub_821FC418) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc4a8
	if (cr6.eq) goto loc_821FC4A8;
	// li r30,0
	r30.s64 = 0;
loc_821FC440:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc49c
	if (cr6.eq) goto loc_821FC49C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne cr6,0x821fc460
	if (!cr6.eq) goto loc_821FC460;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_821FC460:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc474
	if (cr6.eq) goto loc_821FC474;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_821FC474:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc488
	if (cr6.eq) goto loc_821FC488;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_821FC488:
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// beq cr6,0x821fc49c
	if (cr6.eq) goto loc_821FC49C;
	// bl 0x82130588
	ctx.lr = 0x821FC49C;
	sub_82130588(ctx, base);
loc_821FC49C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc440
	if (!cr6.eq) goto loc_821FC440;
loc_821FC4A8:
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

__attribute__((alias("__imp__sub_821FC4C0"))) PPC_WEAK_FUNC(sub_821FC4C0);
PPC_FUNC_IMPL(__imp__sub_821FC4C0) {
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
	ctx.lr = 0x821FC4C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r27,r28,60
	r27.s64 = r28.s64 + 60;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x821FC4EC;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fc56c
	if (cr6.eq) goto loc_821FC56C;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_821FC500:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc524
	if (cr6.eq) goto loc_821FC524;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FC524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FC524:
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821fc500
	if (!cr6.eq) goto loc_821FC500;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_821FC53C:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821fc564
	if (!cr6.lt) goto loc_821FC564;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r11,r8
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fc53c
	if (cr6.eq) goto loc_821FC53C;
	// b 0x821fc500
	goto loc_821FC500;
loc_821FC564:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821fc500
	if (!cr6.eq) goto loc_821FC500;
loc_821FC56C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82138a18
	ctx.lr = 0x821FC574;
	sub_82138A18(ctx, base);
	// addi r3,r28,72
	ctx.r3.s64 = r28.s64 + 72;
	// bl 0x821fc418
	ctx.lr = 0x821FC57C;
	sub_821FC418(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821FC584"))) PPC_WEAK_FUNC(sub_821FC584);
PPC_FUNC_IMPL(__imp__sub_821FC584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FC588"))) PPC_WEAK_FUNC(sub_821FC588);
PPC_FUNC_IMPL(__imp__sub_821FC588) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x821FC590;
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f30.u64);
	// stfd f31,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// li r20,1
	r20.s64 = 1;
	// lfs f0,10660(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 10660);
	f0.f64 = double(temp.f32);
	// lbz r11,10720(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f13,10660(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 10660, temp.u32);
	// bne cr6,0x821fc6c0
	if (!cr6.eq) goto loc_821FC6C0;
	// lbz r11,10708(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10708);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc6c0
	if (cr6.eq) goto loc_821FC6C0;
	// lwz r11,10716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10716);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,10716(r31)
	PPC_STORE_U32(r31.u32 + 10716, r11.u32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// ble cr6,0x821fc6c0
	if (!cr6.gt) goto loc_821FC6C0;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FC5FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,41
	ctx.r3.s64 = 41;
	// bl 0x82216138
	ctx.lr = 0x821FC604;
	sub_82216138(ctx, base);
	// stw r22,4872(r31)
	PPC_STORE_U32(r31.u32 + 4872, r22.u32);
	// addi r30,r31,4872
	r30.s64 = r31.s64 + 4872;
	// bl 0x82387860
	ctx.lr = 0x821FC610;
	sub_82387860(ctx, base);
	// bl 0x82387860
	ctx.lr = 0x821FC614;
	sub_82387860(ctx, base);
	// bl 0x82387860
	ctx.lr = 0x821FC618;
	sub_82387860(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,656
	ctx.r5.s64 = 656;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821FC628;
	sub_823DA950(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r29,-10240(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82387860
	ctx.lr = 0x821FC634;
	sub_82387860(ctx, base);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82270170
	ctx.lr = 0x821FC640;
	sub_82270170(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,4940(r31)
	PPC_STORE_U32(r31.u32 + 4940, ctx.r3.u32);
	// addi r29,r11,-27408
	r29.s64 = r11.s64 + -27408;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc674
	if (!cr6.eq) goto loc_821FC674;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x821fc674
	if (!cr6.eq) goto loc_821FC674;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-18676
	ctx.r3.s64 = r11.s64 + -18676;
	// bl 0x822160d0
	ctx.lr = 0x821FC670;
	sub_822160D0(ctx, base);
	// b 0x821fc67c
	goto loc_821FC67C;
loc_821FC674:
	// li r3,46
	ctx.r3.s64 = 46;
	// bl 0x82216138
	ctx.lr = 0x821FC67C;
	sub_82216138(ctx, base);
loc_821FC67C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x821fc698
	if (!cr6.eq) goto loc_821FC698;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,4880
	ctx.r4.s64 = r31.s64 + 4880;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c120
	ctx.lr = 0x821FC698;
	sub_8226C120(ctx, base);
loc_821FC698:
	// stb r20,10720(r31)
	PPC_STORE_U8(r31.u32 + 10720, r20.u8);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc6c0
	if (cr6.eq) goto loc_821FC6C0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,-22444
	ctx.r3.s64 = r11.s64 + -22444;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8268ee10
	ctx.lr = 0x821FC6C0;
	sub_8268EE10(ctx, base);
loc_821FC6C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fb748
	ctx.lr = 0x821FC6C8;
	sub_821FB748(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x82213800
	ctx.lr = 0x821FC6D0;
	sub_82213800(ctx, base);
	// lis r21,-32119
	r21.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FC6E0;
	sub_82305870(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// stfs f30,4200(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 4200, temp.u32);
	// lwz r11,-10232(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10232);
	// addi r28,r11,8
	r28.s64 = r11.s64 + 8;
	// beq cr6,0x821fc71c
	if (cr6.eq) goto loc_821FC71C;
	// bl 0x8221dea0
	ctx.lr = 0x821FC708;
	sub_8221DEA0(ctx, base);
	// lbz r11,10656(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc71c
	if (!cr6.eq) goto loc_821FC71C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82224920
	ctx.lr = 0x821FC71C;
	sub_82224920(ctx, base);
loc_821FC71C:
	// lbz r11,10656(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc73c
	if (!cr6.eq) goto loc_821FC73C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc73c
	if (cr6.eq) goto loc_821FC73C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822247a8
	ctx.lr = 0x821FC73C;
	sub_822247A8(ctx, base);
loc_821FC73C:
	// lbz r11,10656(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc758
	if (!cr6.eq) goto loc_821FC758;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc758
	if (cr6.eq) goto loc_821FC758;
	// bl 0x8221eae8
	ctx.lr = 0x821FC758;
	sub_8221EAE8(ctx, base);
loc_821FC758:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r23,16
	r23.s64 = 16;
	// li r24,32
	r24.s64 = 32;
	// li r25,48
	r25.s64 = 48;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc850
	if (cr6.eq) goto loc_821FC850;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FC780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821fc850
	if (cr6.eq) goto loc_821FC850;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc7a8
	if (cr6.eq) goto loc_821FC7A8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82212298
	ctx.lr = 0x821FC7A8;
	sub_82212298(ctx, base);
loc_821FC7A8:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FC7C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FC7D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,68(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821fc850
	if (cr6.eq) goto loc_821FC850;
	// lbz r11,70(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 70);
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc850
	if (cr6.eq) goto loc_821FC850;
	// lfs f0,560(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 560);
	f0.f64 = double(temp.f32);
	// mr r11,r20
	r11.u64 = r20.u64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x821fc808
	if (!cr6.eq) goto loc_821FC808;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_821FC808:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc850
	if (cr6.eq) goto loc_821FC850;
	// addi r11,r9,496
	r11.s64 = ctx.r9.s64 + 496;
	// stfs f0,4200(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4200, temp.u32);
	// addi r10,r31,4336
	ctx.r10.s64 = r31.s64 + 4336;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,564(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 564);
	f0.f64 = double(temp.f32);
	// stfs f0,4400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4400, temp.u32);
	// lfs f13,568(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 568);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4404(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4404, temp.u32);
loc_821FC850:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2836(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fc864
	if (cr6.eq) goto loc_821FC864;
	// bl 0x821f9918
	ctx.lr = 0x821FC864;
	sub_821F9918(ctx, base);
loc_821FC864:
	// lhz r30,100(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 100);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821fc89c
	if (!cr6.gt) goto loc_821FC89C;
	// mr r29,r22
	r29.u64 = r22.u64;
loc_821FC874:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FC890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x821fc874
	if (!cr0.eq) goto loc_821FC874;
loc_821FC89C:
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// addi r27,r31,60
	r27.s64 = r31.s64 + 60;
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821fc9d4
	if (!cr6.gt) goto loc_821FC9D4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_821FC8B4:
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821fc8d4
	if (!cr6.eq) goto loc_821FC8D4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x821fc8b4
	if (cr6.lt) goto loc_821FC8B4;
	// b 0x821fc9d4
	goto loc_821FC9D4;
loc_821FC8D4:
	// lis r26,-32130
	r26.s64 = -2105671680;
loc_821FC8D8:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821fc98c
	if (cr6.eq) goto loc_821FC98C;
	// lbz r11,69(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 69);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fc98c
	if (!cr6.eq) goto loc_821FC98C;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r5,-15876(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + -15876);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82720898
	ctx.lr = 0x821FC90C;
	sub_82720898(ctx, base);
	// lbz r11,70(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc98c
	if (cr6.eq) goto loc_821FC98C;
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lfs f0,560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 560);
	f0.f64 = double(temp.f32);
	// mr r11,r20
	r11.u64 = r20.u64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x821fc930
	if (!cr6.eq) goto loc_821FC930;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_821FC930:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc98c
	if (cr6.eq) goto loc_821FC98C;
	// lwz r10,56(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r11,r31,4336
	r11.s64 = r31.s64 + 4336;
	// lfs f0,560(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 560);
	f0.f64 = double(temp.f32);
	// stfs f0,4200(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4200, temp.u32);
	// lwz r10,56(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r10,r10,496
	ctx.r10.s64 = ctx.r10.s64 + 496;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r10,r23
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r10,r24
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r10,r25
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,56(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lfs f13,564(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 564);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4400(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4400, temp.u32);
	// lwz r8,56(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lfs f12,568(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 568);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4404(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 4404, temp.u32);
loc_821FC98C:
	// lwz r28,12(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821fc8d8
	if (!cr6.eq) goto loc_821FC8D8;
	// lhz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
loc_821FC9A4:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x821fc9cc
	if (!cr6.lt) goto loc_821FC9CC;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r28,r8,r11
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821fc9a4
	if (cr6.eq) goto loc_821FC9A4;
	// b 0x821fc8d8
	goto loc_821FC8D8;
loc_821FC9CC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821fc8d8
	if (!cr6.eq) goto loc_821FC8D8;
loc_821FC9D4:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fc9f0
	if (cr6.eq) goto loc_821FC9F0;
	// addi r3,r11,224
	ctx.r3.s64 = r11.s64 + 224;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82235068
	ctx.lr = 0x821FC9F0;
	sub_82235068(ctx, base);
loc_821FC9F0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18780
	ctx.r4.s64 = ctx.r10.s64 + -18780;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x821FCA04;
	sub_821F9FB8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x821FCA0C;
	sub_82256058(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r3,-10220(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// xori r29,r7,1
	r29.u64 = ctx.r7.u64 ^ 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fca44
	if (cr6.eq) goto loc_821FCA44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FCA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821fca60
	if (!cr6.eq) goto loc_821FCA60;
loc_821FCA44:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54609
	ctx.r9.u64 = ctx.r10.u64 | 54609;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fca90
	if (cr6.eq) goto loc_821FCA90;
loc_821FCA60:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,-10028(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r3,r10,224
	ctx.r3.s64 = ctx.r10.s64 + 224;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// b 0x821fcb10
	goto loc_821FCB10;
loc_821FCA90:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fcb18
	if (cr6.eq) goto loc_821FCB18;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x827229e8
	ctx.lr = 0x821FCAA0;
	sub_827229E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fcb18
	if (cr6.eq) goto loc_821FCB18;
	// lwz r30,56(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-18692
	ctx.r4.s64 = r11.s64 + -18692;
	// bl 0x82722990
	ctx.lr = 0x821FCABC;
	sub_82722990(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FCAD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef808
	ctx.lr = 0x821FCAD4;
	sub_825EF808(ctx, base);
	// stb r20,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r20.u8);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-18708
	ctx.r4.s64 = ctx.r8.s64 + -18708;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x825ee270
	ctx.lr = 0x821FCAF0;
	sub_825EE270(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,-10028(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// lbz r26,80(r1)
	r26.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x827229e8
	ctx.lr = 0x821FCB00;
	sub_827229E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,224
	ctx.r3.s64 = r30.s64 + 224;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
loc_821FCB10:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x822373e8
	ctx.lr = 0x821FCB18;
	sub_822373E8(ctx, base);
loc_821FCB18:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FCB34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822164d0
	ctx.lr = 0x821FCB3C;
	sub_822164D0(ctx, base);
	// lbz r8,10657(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10657);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fcb4c
	if (cr6.eq) goto loc_821FCB4C;
	// stb r22,10656(r31)
	PPC_STORE_U8(r31.u32 + 10656, r22.u8);
loc_821FCB4C:
	// stb r22,10657(r31)
	PPC_STORE_U8(r31.u32 + 10657, r22.u8);
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fcb6c
	if (cr6.eq) goto loc_821FCB6C;
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221be98
	ctx.lr = 0x821FCB6C;
	sub_8221BE98(ctx, base);
loc_821FCB6C:
	// addi r3,r31,10736
	ctx.r3.s64 = r31.s64 + 10736;
	// bl 0x822141e8
	ctx.lr = 0x821FCB74;
	sub_822141E8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FCB80;
	sub_823058F8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_821FCB90"))) PPC_WEAK_FUNC(sub_821FCB90);
PPC_FUNC_IMPL(__imp__sub_821FCB90) {
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
	ctx.lr = 0x821FCB98;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// bl 0x82387928
	ctx.lr = 0x821FCBC4;
	sub_82387928(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r27,r11,9572
	r27.s64 = r11.s64 + 9572;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bne cr6,0x821fcbf0
	if (!cr6.eq) goto loc_821FCBF0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r6,r11,-18712
	ctx.r6.s64 = r11.s64 + -18712;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821f9638
	ctx.lr = 0x821FCBEC;
	sub_821F9638(ctx, base);
	// b 0x821fcc00
	goto loc_821FCC00;
loc_821FCBF0:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// bl 0x82137a08
	ctx.lr = 0x821FCC00;
	sub_82137A08(ctx, base);
loc_821FCC00:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9ef0
	ctx.lr = 0x821FCC0C;
	sub_821F9EF0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821fcc3c
	if (!cr6.eq) goto loc_821FCC3C;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x821FCC2C;
	sub_82137A08(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f9ef0
	ctx.lr = 0x821FCC38;
	sub_821F9EF0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_821FCC3C:
	// lis r28,-32119
	r28.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x821FCC4C;
	sub_82305870(ctx, base);
	// lbz r11,551(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 551);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// stb r8,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, ctx.r8.u8);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stb r11,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r11.u8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fb5d0
	ctx.lr = 0x821FCC80;
	sub_821FB5D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// li r5,31
	ctx.r5.s64 = 31;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x821FCC94;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x821FCCA0;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821FCCAC"))) PPC_WEAK_FUNC(sub_821FCCAC);
PPC_FUNC_IMPL(__imp__sub_821FCCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FCCB0"))) PPC_WEAK_FUNC(sub_821FCCB0);
PPC_FUNC_IMPL(__imp__sub_821FCCB0) {
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
	ctx.lr = 0x821FCCB8;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,92(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821fcda0
	if (!cr6.gt) goto loc_821FCDA0;
	// mr r29,r11
	r29.u64 = r11.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r27,r28,72
	r27.s64 = r28.s64 + 72;
	// addi r24,r28,60
	r24.s64 = r28.s64 + 60;
	// mr r30,r26
	r30.u64 = r26.u64;
	// addi r25,r11,-18660
	r25.s64 = r11.s64 + -18660;
loc_821FCCE8:
	// lwz r11,88(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x821FCD04;
	sub_823DB670(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x821FCD10;
	sub_82130000(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fcd30
	if (cr6.eq) goto loc_821FCD30;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FCD30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FCD30:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821fcd44
	if (!cr6.eq) goto loc_821FCD44;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_821FCD44:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x821fcd58
	if (!cr6.eq) goto loc_821FCD58;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_821FCD58:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fcd6c
	if (cr6.eq) goto loc_821FCD6C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_821FCD6C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fcd80
	if (cr6.eq) goto loc_821FCD80;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_821FCD80:
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821fac60
	ctx.lr = 0x821FCD94;
	sub_821FAC60(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x821fcce8
	if (!cr0.eq) goto loc_821FCCE8;
loc_821FCDA0:
	// lhz r10,94(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 94);
	// addi r11,r28,88
	r11.s64 = r28.s64 + 88;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821fcdb8
	if (!cr6.eq) goto loc_821FCDB8;
	// sth r26,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r26.u16);
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_821FCDB8:
	// lis r31,-32125
	r31.s64 = -2105344000;
	// sth r26,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r26.u16);
	// lwz r11,2836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fce10
	if (cr6.eq) goto loc_821FCE10;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821fce10
	if (!cr6.eq) goto loc_821FCE10;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,-257
	ctx.r4.s64 = -16842752;
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5b00
	ctx.lr = 0x821FCDEC;
	sub_822E5B00(ctx, base);
	// lwz r30,2836(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fce08
	if (cr6.eq) goto loc_821FCE08;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f7fb8
	ctx.lr = 0x821FCE00;
	sub_821F7FB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821FCE08;
	sub_82130588(ctx, base);
loc_821FCE08:
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r11,2836(r31)
	PPC_STORE_U32(r31.u32 + 2836, r11.u32);
loc_821FCE10:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821FCE18"))) PPC_WEAK_FUNC(sub_821FCE18);
PPC_FUNC_IMPL(__imp__sub_821FCE18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// b 0x821fb090
	sub_821FB090(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FCE24"))) PPC_WEAK_FUNC(sub_821FCE24);
PPC_FUNC_IMPL(__imp__sub_821FCE24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FCE28"))) PPC_WEAK_FUNC(sub_821FCE28);
PPC_FUNC_IMPL(__imp__sub_821FCE28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r7,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r6,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// b 0x821fbed0
	sub_821FBED0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FCE70"))) PPC_WEAK_FUNC(sub_821FCE70);
PPC_FUNC_IMPL(__imp__sub_821FCE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821fbe60
	sub_821FBE60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FCE7C"))) PPC_WEAK_FUNC(sub_821FCE7C);
PPC_FUNC_IMPL(__imp__sub_821FCE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FCE80"))) PPC_WEAK_FUNC(sub_821FCE80);
PPC_FUNC_IMPL(__imp__sub_821FCE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821fbdd0
	sub_821FBDD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FCE8C"))) PPC_WEAK_FUNC(sub_821FCE8C);
PPC_FUNC_IMPL(__imp__sub_821FCE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FCE90"))) PPC_WEAK_FUNC(sub_821FCE90);
PPC_FUNC_IMPL(__imp__sub_821FCE90) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x826949b0
	ctx.lr = 0x821FCEB4;
	sub_826949B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821fbf68
	ctx.lr = 0x821FCEC4;
	sub_821FBF68(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FCED8"))) PPC_WEAK_FUNC(sub_821FCED8);
PPC_FUNC_IMPL(__imp__sub_821FCED8) {
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
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fcf18
	if (cr6.eq) goto loc_821FCF18;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821fcf18
	if (!cr6.eq) goto loc_821FCF18;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,-257
	ctx.r4.s64 = -16842752;
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5b00
	ctx.lr = 0x821FCF14;
	sub_822E5B00(ctx, base);
	// bl 0x821faa98
	ctx.lr = 0x821FCF18;
	sub_821FAA98(ctx, base);
loc_821FCF18:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FCF28"))) PPC_WEAK_FUNC(sub_821FCF28);
PPC_FUNC_IMPL(__imp__sub_821FCF28) {
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
	ctx.lr = 0x821FCF30;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fcf60
	if (!cr6.eq) goto loc_821FCF60;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x821fd01c
	goto loc_821FD01C;
loc_821FCF60:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r6,r27,4
	ctx.r6.s64 = r27.s64 + 4;
loc_821FCF68:
	// addi r8,r7,20
	ctx.r8.s64 = ctx.r7.s64 + 20;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_821FCF74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x821fcf98
	if (cr6.eq) goto loc_821FCF98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fcf74
	if (cr6.eq) goto loc_821FCF74;
loc_821FCF98:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x821fcfb4
	if (!cr6.lt) goto loc_821FCFB4;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fd010
	if (!cr6.eq) goto loc_821FD010;
	// stw r31,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r31.u32);
	// b 0x821fd008
	goto loc_821FD008;
loc_821FCFB4:
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_821FCFBC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821fcfe0
	if (cr6.eq) goto loc_821FCFE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fcfbc
	if (cr6.eq) goto loc_821FCFBC;
loc_821FCFE0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x821fd01c
	if (!cr6.lt) goto loc_821FD01C;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fd010
	if (!cr6.eq) goto loc_821FD010;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// or r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 | r31.u64;
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
loc_821FD008:
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
loc_821FD010:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fcf68
	if (!cr6.eq) goto loc_821FCF68;
loc_821FD01C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fd058
	if (cr6.eq) goto loc_821FD058;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x821fc130
	ctx.lr = 0x821FD03C;
	sub_821FC130(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r27,4
	ctx.r4.s64 = r27.s64 + 4;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x823db670
	ctx.lr = 0x821FD04C;
	sub_823DB670(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r9.u32);
loc_821FD058:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821faaf0
	ctx.lr = 0x821FD068;
	sub_821FAAF0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-21500
	ctx.r10.s64 = r11.s64 + -21500;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x821FD088;
	sub_823DA950(ctx, base);
	// addi r9,r30,0
	ctx.r9.s64 = r30.s64 + 0;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// stw r8,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r8.u32);
	// stw r6,72(r29)
	PPC_STORE_U32(r29.u32 + 72, ctx.r6.u32);
	// stb r4,76(r29)
	PPC_STORE_U8(r29.u32 + 76, ctx.r4.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821FD0B8"))) PPC_WEAK_FUNC(sub_821FD0B8);
PPC_FUNC_IMPL(__imp__sub_821FD0B8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821fd140
	if (cr6.eq) goto loc_821FD140;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
loc_821FD0EC:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r11,r8,20
	r11.s64 = ctx.r8.s64 + 20;
loc_821FD0F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r30,0(r10)
	r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - r30.s64;
	// beq cr6,0x821fd118
	if (cr6.eq) goto loc_821FD118;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fd0f4
	if (cr6.eq) goto loc_821FD0F4;
loc_821FD118:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x821fd12c
	if (!cr6.lt) goto loc_821FD12C;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r8,r11,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x821fd134
	goto loc_821FD134;
loc_821FD12C:
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
loc_821FD134:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821fd0ec
	if (!cr6.eq) goto loc_821FD0EC;
loc_821FD140:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821fd14c
	if (cr6.eq) goto loc_821FD14C;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
loc_821FD14C:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821faaf0
	ctx.lr = 0x821FD158;
	sub_821FAAF0(ctx, base);
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

__attribute__((alias("__imp__sub_821FD174"))) PPC_WEAK_FUNC(sub_821FD174);
PPC_FUNC_IMPL(__imp__sub_821FD174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FD178"))) PPC_WEAK_FUNC(sub_821FD178);
PPC_FUNC_IMPL(__imp__sub_821FD178) {
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
	ctx.lr = 0x821FD180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-18612
	ctx.r9.s64 = r11.s64 + -18612;
	// addi r8,r10,-18624
	ctx.r8.s64 = ctx.r10.s64 + -18624;
	// lwz r3,13284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13284);
	// addi r27,r31,4
	r27.s64 = r31.s64 + 4;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// beq cr6,0x821fd1b4
	if (cr6.eq) goto loc_821FD1B4;
	// bl 0x821f7648
	ctx.lr = 0x821FD1B4;
	sub_821F7648(ctx, base);
loc_821FD1B4:
	// lwz r3,13288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd1c4
	if (cr6.eq) goto loc_821FD1C4;
	// bl 0x821f7648
	ctx.lr = 0x821FD1C4;
	sub_821F7648(ctx, base);
loc_821FD1C4:
	// addi r29,r31,7092
	r29.s64 = r31.s64 + 7092;
	// li r28,4
	r28.s64 = 4;
loc_821FD1CC:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fd1f4
	if (cr6.eq) goto loc_821FD1F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82765168
	ctx.lr = 0x821FD1E4;
	sub_82765168(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2a40
	ctx.lr = 0x821FD1EC;
	sub_821E2A40(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821FD1F4;
	sub_82130588(ctx, base);
loc_821FD1F4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x821fd1cc
	if (!cr0.eq) goto loc_821FD1CC;
	// lwz r5,10668(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10668);
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd224
	if (cr6.eq) goto loc_821FD224;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD220;
	sub_8268B6D0(ctx, base);
	// stw r29,10668(r31)
	PPC_STORE_U32(r31.u32 + 10668, r29.u32);
loc_821FD224:
	// lwz r5,10672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10672);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd240
	if (cr6.eq) goto loc_821FD240;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD23C;
	sub_8268B6D0(ctx, base);
	// stw r29,10672(r31)
	PPC_STORE_U32(r31.u32 + 10672, r29.u32);
loc_821FD240:
	// lwz r5,10676(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10676);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd25c
	if (cr6.eq) goto loc_821FD25C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD258;
	sub_8268B6D0(ctx, base);
	// stw r29,10676(r31)
	PPC_STORE_U32(r31.u32 + 10676, r29.u32);
loc_821FD25C:
	// lwz r5,10680(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10680);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd278
	if (cr6.eq) goto loc_821FD278;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD274;
	sub_8268B6D0(ctx, base);
	// stw r29,10680(r31)
	PPC_STORE_U32(r31.u32 + 10680, r29.u32);
loc_821FD278:
	// lwz r5,10684(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10684);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd294
	if (cr6.eq) goto loc_821FD294;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD290;
	sub_8268B6D0(ctx, base);
	// stw r29,10684(r31)
	PPC_STORE_U32(r31.u32 + 10684, r29.u32);
loc_821FD294:
	// lwz r5,10688(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10688);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd2b0
	if (cr6.eq) goto loc_821FD2B0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD2AC;
	sub_8268B6D0(ctx, base);
	// stw r29,10688(r31)
	PPC_STORE_U32(r31.u32 + 10688, r29.u32);
loc_821FD2B0:
	// lwz r5,10692(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10692);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd2cc
	if (cr6.eq) goto loc_821FD2CC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD2C8;
	sub_8268B6D0(ctx, base);
	// stw r29,10692(r31)
	PPC_STORE_U32(r31.u32 + 10692, r29.u32);
loc_821FD2CC:
	// lwz r5,10696(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10696);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd2e8
	if (cr6.eq) goto loc_821FD2E8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD2E4;
	sub_8268B6D0(ctx, base);
	// stw r29,10696(r31)
	PPC_STORE_U32(r31.u32 + 10696, r29.u32);
loc_821FD2E8:
	// lwz r5,10700(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10700);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd304
	if (cr6.eq) goto loc_821FD304;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD300;
	sub_8268B6D0(ctx, base);
	// stw r29,10700(r31)
	PPC_STORE_U32(r31.u32 + 10700, r29.u32);
loc_821FD304:
	// lwz r5,10704(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10704);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821fd320
	if (cr6.eq) goto loc_821FD320;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FD31C;
	sub_8268B6D0(ctx, base);
	// stw r29,10704(r31)
	PPC_STORE_U32(r31.u32 + 10704, r29.u32);
loc_821FD320:
	// lwz r11,5540(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5540);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd378
	if (cr6.eq) goto loc_821FD378;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// addi r4,r11,-18640
	ctx.r4.s64 = r11.s64 + -18640;
	// bl 0x82181530
	ctx.lr = 0x821FD340;
	sub_82181530(ctx, base);
	// lwz r30,5540(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 5540);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821FD34C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821fd374
	if (!cr6.eq) goto loc_821FD374;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fd374
	if (cr6.eq) goto loc_821FD374;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD374:
	// stw r29,5540(r31)
	PPC_STORE_U32(r31.u32 + 5540, r29.u32);
loc_821FD378:
	// lwz r11,5536(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5536);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd3cc
	if (cr6.eq) goto loc_821FD3CC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// addi r4,r11,-21824
	ctx.r4.s64 = r11.s64 + -21824;
	// bl 0x82181530
	ctx.lr = 0x821FD394;
	sub_82181530(ctx, base);
	// lwz r30,5536(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 5536);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821FD3A0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821fd3c8
	if (!cr6.eq) goto loc_821FD3C8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fd3c8
	if (cr6.eq) goto loc_821FD3C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD3C8:
	// stw r29,5536(r31)
	PPC_STORE_U32(r31.u32 + 5536, r29.u32);
loc_821FD3CC:
	// lwz r3,5528(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5528);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd3ec
	if (cr6.eq) goto loc_821FD3EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD3EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD3EC:
	// lwz r3,5532(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5532);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd40c
	if (cr6.eq) goto loc_821FD40C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD40C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD40C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7818
	ctx.lr = 0x821FD414;
	sub_821F7818(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fc4c0
	ctx.lr = 0x821FD41C;
	sub_821FC4C0(ctx, base);
	// lwz r30,56(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821fd438
	if (cr6.eq) goto loc_821FD438;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82213a20
	ctx.lr = 0x821FD430;
	sub_82213A20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821FD438;
	sub_82130588(ctx, base);
loc_821FD438:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10232);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd45c
	if (cr6.eq) goto loc_821FD45C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD45C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD45C:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-10232(r28)
	PPC_STORE_U32(r28.u32 + -10232, r11.u32);
	// lwz r3,2832(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd488
	if (cr6.eq) goto loc_821FD488;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD488:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,2832(r30)
	PPC_STORE_U32(r30.u32 + 2832, r11.u32);
	// lwz r3,-10228(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10228);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd4b4
	if (cr6.eq) goto loc_821FD4B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD4B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD4B4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-10228(r28)
	PPC_STORE_U32(r28.u32 + -10228, r11.u32);
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fd4e0
	if (cr6.eq) goto loc_821FD4E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FD4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD4E0:
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r3,r31,10736
	ctx.r3.s64 = r31.s64 + 10736;
	// stw r11,-10244(r30)
	PPC_STORE_U32(r30.u32 + -10244, r11.u32);
	// bl 0x82214308
	ctx.lr = 0x821FD4F0;
	sub_82214308(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r31,4640
	r30.s64 = r31.s64 + 4640;
	// addi r29,r11,-21484
	r29.s64 = r11.s64 + -21484;
	// stw r29,4640(r31)
	PPC_STORE_U32(r31.u32 + 4640, r29.u32);
	// lwz r28,4816(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4816);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821fd51c
	if (cr6.eq) goto loc_821FD51C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217cb48
	ctx.lr = 0x821FD514;
	sub_8217CB48(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x821FD51C;
	sub_82130588(ctx, base);
loc_821FD51C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x821FD524;
	sub_82633B00(ctx, base);
	// stw r29,4416(r31)
	PPC_STORE_U32(r31.u32 + 4416, r29.u32);
	// addi r30,r31,4416
	r30.s64 = r31.s64 + 4416;
	// lwz r29,4592(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4592);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821fd548
	if (cr6.eq) goto loc_821FD548;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217cb48
	ctx.lr = 0x821FD540;
	sub_8217CB48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821FD548;
	sub_82130588(ctx, base);
loc_821FD548:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x821FD550;
	sub_82633B00(ctx, base);
	// lhz r11,102(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 102);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd564
	if (cr6.eq) goto loc_821FD564;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x821FD564;
	sub_82130588(ctx, base);
loc_821FD564:
	// lhz r11,94(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 94);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd578
	if (cr6.eq) goto loc_821FD578;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x821FD578;
	sub_82130588(ctx, base);
loc_821FD578:
	// lhz r11,86(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd58c
	if (cr6.eq) goto loc_821FD58C;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x821FD58C;
	sub_82130588(ctx, base);
loc_821FD58C:
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x82138a18
	ctx.lr = 0x821FD594;
	sub_82138A18(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x821FD5A8;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821FD5B0"))) PPC_WEAK_FUNC(sub_821FD5B0);
PPC_FUNC_IMPL(__imp__sub_821FD5B0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821fda78
	sub_821FDA78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FD5B8"))) PPC_WEAK_FUNC(sub_821FD5B8);
PPC_FUNC_IMPL(__imp__sub_821FD5B8) {
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
	// bl 0x821fccb0
	ctx.lr = 0x821FD5D0;
	sub_821FCCB0(ctx, base);
	// lhz r9,86(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821fd5ec
	if (!cr6.eq) goto loc_821FD5EC;
	// sth r11,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r11.u16);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_821FD5EC:
	// sth r11,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r11.u16);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd624
	if (cr6.eq) goto loc_821FD624;
loc_821FD5FC:
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r6.u16);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r4,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r4.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fd5fc
	if (!cr6.eq) goto loc_821FD5FC;
loc_821FD624:
	// bl 0x8263eaa8
	ctx.lr = 0x821FD628;
	sub_8263EAA8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FD63C"))) PPC_WEAK_FUNC(sub_821FD63C);
PPC_FUNC_IMPL(__imp__sub_821FD63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FD640"))) PPC_WEAK_FUNC(sub_821FD640);
PPC_FUNC_IMPL(__imp__sub_821FD640) {
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
	ctx.lr = 0x821FD648;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,7508
	r31.s64 = ctx.r3.s64 + 7508;
	// addi r30,r3,7092
	r30.s64 = ctx.r3.s64 + 7092;
	// li r29,4
	r29.s64 = 4;
	// li r28,0
	r28.s64 = 0;
loc_821FD65C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd698
	if (cr6.eq) goto loc_821FD698;
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// bl 0x82305ad8
	ctx.lr = 0x821FD670;
	sub_82305AD8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32137
	r11.s64 = -2106130432;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-11448
	ctx.r6.s64 = r11.s64 + -11448;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r10,-21560
	ctx.r5.s64 = ctx.r10.s64 + -21560;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FD698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FD698:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x821fd65c
	if (!cr0.eq) goto loc_821FD65C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FD6B0"))) PPC_WEAK_FUNC(sub_821FD6B0);
PPC_FUNC_IMPL(__imp__sub_821FD6B0) {
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
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r8,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r8.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10236(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r30,r6,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// xori r30,r30,1
	r30.u64 = r30.u64 ^ 1;
	// bl 0x821fcb90
	ctx.lr = 0x821FD714;
	sub_821FCB90(ctx, base);
	// stb r30,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, r30.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_821FD738"))) PPC_WEAK_FUNC(sub_821FD738);
PPC_FUNC_IMPL(__imp__sub_821FD738) {
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
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r8,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r8.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10236(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r30,r6,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// xori r30,r30,1
	r30.u64 = r30.u64 ^ 1;
	// bl 0x821fcb90
	ctx.lr = 0x821FD79C;
	sub_821FCB90(ctx, base);
	// stb r30,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, r30.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_821FD7C0"))) PPC_WEAK_FUNC(sub_821FD7C0);
PPC_FUNC_IMPL(__imp__sub_821FD7C0) {
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
	ctx.lr = 0x821FD7C8;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x821fd0b8
	ctx.lr = 0x821FD7E4;
	sub_821FD0B8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r8,r11,-21500
	ctx.r8.s64 = r11.s64 + -21500;
	// lwz r11,228(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fd834
	if (cr6.eq) goto loc_821FD834;
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
loc_821FD800:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x821fd824
	if (cr6.eq) goto loc_821FD824;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fd800
	if (cr6.eq) goto loc_821FD800;
loc_821FD824:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x821fd834
	if (cr6.lt) goto loc_821FD834;
	// addi r31,r1,160
	r31.s64 = ctx.r1.s64 + 160;
	// b 0x821fd848
	goto loc_821FD848;
loc_821FD834:
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r29.u32);
	// stb r28,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r28.u8);
	// stw r28,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r28.u32);
loc_821FD848:
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x821FD85C;
	sub_823DA950(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r11.u32);
	// stw r10,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r10.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FD878"))) PPC_WEAK_FUNC(sub_821FD878);
PPC_FUNC_IMPL(__imp__sub_821FD878) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821FD880;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x821FD8AC;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fd7c0
	ctx.lr = 0x821FD8C0;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// stb r11,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r11.u8);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r29.u32);
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// stw r11,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r11.u32);
	// bne cr6,0x821fd974
	if (!cr6.eq) goto loc_821FD974;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10244);
	// addi r4,r10,9792
	ctx.r4.s64 = ctx.r10.s64 + 9792;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, ctx.r9.u32);
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x821FD924;
	sub_823DC018(ctx, base);
	// li r7,4
	ctx.r7.s64 = 4;
	// stfs f31,92(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 92, temp.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r7,160(r28)
	PPC_STORE_U32(r28.u32 + 160, ctx.r7.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r29,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r29.u32);
	// addi r3,r1,324
	ctx.r3.s64 = ctx.r1.s64 + 324;
	// bl 0x823db670
	ctx.lr = 0x821FD944;
	sub_823DB670(ctx, base);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,324
	ctx.r4.s64 = ctx.r1.s64 + 324;
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x821FD958;
	sub_823DA950(ctx, base);
	// stw r30,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r30.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fcf28
	ctx.lr = 0x821FD970;
	sub_821FCF28(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821FD974:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821FD980"))) PPC_WEAK_FUNC(sub_821FD980);
PPC_FUNC_IMPL(__imp__sub_821FD980) {
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
	ctx.lr = 0x821FD988;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x821FD9B0;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fd7c0
	ctx.lr = 0x821FD9C4;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// stb r11,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r11.u8);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// stw r11,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r11.u32);
	// bne cr6,0x821fda70
	if (!cr6.eq) goto loc_821FDA70;
	// lwz r11,10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10244);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, ctx.r8.u32);
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// addi r29,r28,4
	r29.s64 = r28.s64 + 4;
	// addi r3,r29,92
	ctx.r3.s64 = r29.s64 + 92;
	// stw r27,92(r28)
	PPC_STORE_U32(r28.u32 + 92, r27.u32);
	// bl 0x823dc018
	ctx.lr = 0x821FDA24;
	sub_823DC018(ctx, base);
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r6,160(r28)
	PPC_STORE_U32(r28.u32 + 160, ctx.r6.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// addi r3,r1,324
	ctx.r3.s64 = ctx.r1.s64 + 324;
	// bl 0x823db670
	ctx.lr = 0x821FDA40;
	sub_823DB670(ctx, base);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,324
	ctx.r4.s64 = ctx.r1.s64 + 324;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x821FDA54;
	sub_823DA950(ctx, base);
	// stw r29,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r29.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fcf28
	ctx.lr = 0x821FDA6C;
	sub_821FCF28(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_821FDA70:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821FDA78"))) PPC_WEAK_FUNC(sub_821FDA78);
PPC_FUNC_IMPL(__imp__sub_821FDA78) {
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
	// bl 0x821fd178
	ctx.lr = 0x821FDA98;
	sub_821FD178(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fdab0
	if (cr6.eq) goto loc_821FDAB0;
	// bl 0x82130588
	ctx.lr = 0x821FDAAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821FDAB0:
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

__attribute__((alias("__imp__sub_821FDAC8"))) PPC_WEAK_FUNC(sub_821FDAC8);
PPC_FUNC_IMPL(__imp__sub_821FDAC8) {
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
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-12776
	ctx.r4.s64 = r11.s64 + -12776;
	// addi r3,r10,-17840
	ctx.r3.s64 = ctx.r10.s64 + -17840;
	// bl 0x82554798
	ctx.lr = 0x821FDAE8;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17824
	ctx.r4.s64 = ctx.r9.s64 + -17824;
	// addi r3,r8,-17860
	ctx.r3.s64 = ctx.r8.s64 + -17860;
	// bl 0x82554798
	ctx.lr = 0x821FDAFC;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17752
	ctx.r4.s64 = ctx.r7.s64 + -17752;
	// addi r3,r6,-17884
	ctx.r3.s64 = ctx.r6.s64 + -17884;
	// bl 0x82554798
	ctx.lr = 0x821FDB10;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-10576
	ctx.r4.s64 = ctx.r5.s64 + -10576;
	// addi r3,r3,-17904
	ctx.r3.s64 = ctx.r3.s64 + -17904;
	// bl 0x82554798
	ctx.lr = 0x821FDB24;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-10440
	ctx.r4.s64 = r11.s64 + -10440;
	// addi r3,r10,-17928
	ctx.r3.s64 = ctx.r10.s64 + -17928;
	// bl 0x82554798
	ctx.lr = 0x821FDB38;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17736
	ctx.r4.s64 = ctx.r9.s64 + -17736;
	// addi r3,r8,-17952
	ctx.r3.s64 = ctx.r8.s64 + -17952;
	// bl 0x82554798
	ctx.lr = 0x821FDB4C;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17712
	ctx.r4.s64 = ctx.r7.s64 + -17712;
	// addi r3,r6,-17972
	ctx.r3.s64 = ctx.r6.s64 + -17972;
	// bl 0x82554798
	ctx.lr = 0x821FDB60;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-12760
	ctx.r4.s64 = ctx.r5.s64 + -12760;
	// addi r3,r3,-17996
	ctx.r3.s64 = ctx.r3.s64 + -17996;
	// bl 0x82554798
	ctx.lr = 0x821FDB74;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-24368
	ctx.r4.s64 = r11.s64 + -24368;
	// addi r3,r10,-18016
	ctx.r3.s64 = ctx.r10.s64 + -18016;
	// bl 0x82554798
	ctx.lr = 0x821FDB88;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17640
	ctx.r4.s64 = ctx.r9.s64 + -17640;
	// addi r3,r8,-18040
	ctx.r3.s64 = ctx.r8.s64 + -18040;
	// bl 0x82554798
	ctx.lr = 0x821FDB9C;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17600
	ctx.r4.s64 = ctx.r7.s64 + -17600;
	// addi r3,r6,-18064
	ctx.r3.s64 = ctx.r6.s64 + -18064;
	// bl 0x82554798
	ctx.lr = 0x821FDBB0;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17576
	ctx.r4.s64 = ctx.r5.s64 + -17576;
	// addi r3,r3,-18084
	ctx.r3.s64 = ctx.r3.s64 + -18084;
	// bl 0x82554798
	ctx.lr = 0x821FDBC4;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17560
	ctx.r4.s64 = r11.s64 + -17560;
	// addi r3,r10,-18108
	ctx.r3.s64 = ctx.r10.s64 + -18108;
	// bl 0x82554798
	ctx.lr = 0x821FDBD8;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17456
	ctx.r4.s64 = ctx.r9.s64 + -17456;
	// addi r3,r8,-18140
	ctx.r3.s64 = ctx.r8.s64 + -18140;
	// bl 0x82554798
	ctx.lr = 0x821FDBEC;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17440
	ctx.r4.s64 = ctx.r7.s64 + -17440;
	// addi r3,r6,-18160
	ctx.r3.s64 = ctx.r6.s64 + -18160;
	// bl 0x82554798
	ctx.lr = 0x821FDC00;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17352
	ctx.r4.s64 = ctx.r5.s64 + -17352;
	// addi r3,r3,-18180
	ctx.r3.s64 = ctx.r3.s64 + -18180;
	// bl 0x82554798
	ctx.lr = 0x821FDC14;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-24344
	ctx.r4.s64 = r11.s64 + -24344;
	// addi r3,r10,-18212
	ctx.r3.s64 = ctx.r10.s64 + -18212;
	// bl 0x82554798
	ctx.lr = 0x821FDC28;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17232
	ctx.r4.s64 = ctx.r9.s64 + -17232;
	// addi r3,r8,-18248
	ctx.r3.s64 = ctx.r8.s64 + -18248;
	// bl 0x82554798
	ctx.lr = 0x821FDC3C;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17168
	ctx.r4.s64 = ctx.r7.s64 + -17168;
	// addi r3,r6,-18272
	ctx.r3.s64 = ctx.r6.s64 + -18272;
	// bl 0x82554798
	ctx.lr = 0x821FDC50;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17128
	ctx.r4.s64 = ctx.r5.s64 + -17128;
	// addi r3,r3,-18304
	ctx.r3.s64 = ctx.r3.s64 + -18304;
	// bl 0x82554798
	ctx.lr = 0x821FDC64;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17104
	ctx.r4.s64 = r11.s64 + -17104;
	// addi r3,r10,-18332
	ctx.r3.s64 = ctx.r10.s64 + -18332;
	// bl 0x82554798
	ctx.lr = 0x821FDC78;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-17080
	ctx.r4.s64 = ctx.r9.s64 + -17080;
	// addi r3,r8,-18360
	ctx.r3.s64 = ctx.r8.s64 + -18360;
	// bl 0x82554798
	ctx.lr = 0x821FDC8C;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-17056
	ctx.r4.s64 = ctx.r7.s64 + -17056;
	// addi r3,r6,-18388
	ctx.r3.s64 = ctx.r6.s64 + -18388;
	// bl 0x82554798
	ctx.lr = 0x821FDCA0;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-17040
	ctx.r4.s64 = ctx.r5.s64 + -17040;
	// addi r3,r3,-18412
	ctx.r3.s64 = ctx.r3.s64 + -18412;
	// bl 0x82554798
	ctx.lr = 0x821FDCB4;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-24328
	ctx.r4.s64 = r11.s64 + -24328;
	// addi r3,r10,-18440
	ctx.r3.s64 = ctx.r10.s64 + -18440;
	// bl 0x82554798
	ctx.lr = 0x821FDCC8;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-24304
	ctx.r4.s64 = ctx.r9.s64 + -24304;
	// addi r3,r8,-18468
	ctx.r3.s64 = ctx.r8.s64 + -18468;
	// bl 0x82554798
	ctx.lr = 0x821FDCDC;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-12688
	ctx.r4.s64 = ctx.r7.s64 + -12688;
	// addi r3,r6,-18496
	ctx.r3.s64 = ctx.r6.s64 + -18496;
	// bl 0x82554798
	ctx.lr = 0x821FDCF0;
	sub_82554798(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-12672
	ctx.r4.s64 = ctx.r5.s64 + -12672;
	// addi r3,r3,-18520
	ctx.r3.s64 = ctx.r3.s64 + -18520;
	// bl 0x82554798
	ctx.lr = 0x821FDD04;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-17016
	ctx.r4.s64 = r11.s64 + -17016;
	// addi r3,r10,-18548
	ctx.r3.s64 = ctx.r10.s64 + -18548;
	// bl 0x82554798
	ctx.lr = 0x821FDD18;
	sub_82554798(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-24216
	ctx.r4.s64 = ctx.r9.s64 + -24216;
	// addi r3,r8,-18576
	ctx.r3.s64 = ctx.r8.s64 + -18576;
	// bl 0x82554798
	ctx.lr = 0x821FDD2C;
	sub_82554798(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-24160
	ctx.r4.s64 = ctx.r7.s64 + -24160;
	// addi r3,r6,-18608
	ctx.r3.s64 = ctx.r6.s64 + -18608;
	// bl 0x82554798
	ctx.lr = 0x821FDD40;
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

__attribute__((alias("__imp__sub_821FDD50"))) PPC_WEAK_FUNC(sub_821FDD50);
PPC_FUNC_IMPL(__imp__sub_821FDD50) {
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
	ctx.lr = 0x821FDD58;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x821FDD8C;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821fddf8
	if (cr6.eq) goto loc_821FDDF8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82193090
	ctx.lr = 0x821FDDDC;
	sub_82193090(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_821FDDF8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821FDE0C"))) PPC_WEAK_FUNC(sub_821FDE0C);
PPC_FUNC_IMPL(__imp__sub_821FDE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FDE10"))) PPC_WEAK_FUNC(sub_821FDE10);
PPC_FUNC_IMPL(__imp__sub_821FDE10) {
	PPC_FUNC_PROLOGUE();
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x821fd878
	ctx.lr = 0x821FDE2C;
	sub_821FD878(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r11,9792
	ctx.r4.s64 = r11.s64 + 9792;
	// bl 0x823dc018
	ctx.lr = 0x821FDE4C;
	sub_823DC018(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// stfs f31,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FDE74"))) PPC_WEAK_FUNC(sub_821FDE74);
PPC_FUNC_IMPL(__imp__sub_821FDE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FDE78"))) PPC_WEAK_FUNC(sub_821FDE78);
PPC_FUNC_IMPL(__imp__sub_821FDE78) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821fd980
	ctx.lr = 0x821FDE94;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x821FDEB0;
	sub_823DC018(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821FDED4"))) PPC_WEAK_FUNC(sub_821FDED4);
PPC_FUNC_IMPL(__imp__sub_821FDED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FDED8"))) PPC_WEAK_FUNC(sub_821FDED8);
PPC_FUNC_IMPL(__imp__sub_821FDED8) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x821FDEE0;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
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
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r7,-17572
	ctx.r4.s64 = ctx.r7.s64 + -17572;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x821FDF24;
	sub_823DB670(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r5,-18624
	ctx.r3.s64 = ctx.r5.s64 + -18624;
	// addi r4,r6,-18612
	ctx.r4.s64 = ctx.r6.s64 + -18612;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r11,10
	r11.s64 = 10;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// li r3,40
	ctx.r3.s64 = 40;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// addi r27,r31,80
	r27.s64 = r31.s64 + 80;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// addi r25,r31,88
	r25.s64 = r31.s64 + 88;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r30.u16);
	// sth r30,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r30.u16);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stb r30,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r30.u8);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// sth r30,84(r31)
	PPC_STORE_U16(r31.u32 + 84, r30.u16);
	// sth r30,86(r31)
	PPC_STORE_U16(r31.u32 + 86, r30.u16);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// sth r30,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r30.u16);
	// sth r30,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r30.u16);
	// sth r30,100(r31)
	PPC_STORE_U16(r31.u32 + 100, r30.u16);
	// sth r11,102(r31)
	PPC_STORE_U16(r31.u32 + 102, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x821FDFA0;
	sub_82130528(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,1
	r28.s64 = 1;
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r28,4408(r31)
	PPC_STORE_U8(r31.u32 + 4408, r28.u8);
	// addi r29,r31,4416
	r29.s64 = r31.s64 + 4416;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stfs f31,4200(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4200, temp.u32);
	// lfs f30,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x821f82e0
	ctx.lr = 0x821FDFD0;
	sub_821F82E0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r24,r31,4640
	r24.s64 = r31.s64 + 4640;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r26,r8,-19580
	r26.s64 = ctx.r8.s64 + -19580;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r26,4416(r31)
	PPC_STORE_U32(r31.u32 + 4416, r26.u32);
	// bl 0x821f82e0
	ctx.lr = 0x821FDFEC;
	sub_821F82E0(ctx, base);
	// stw r26,4640(r31)
	PPC_STORE_U32(r31.u32 + 4640, r26.u32);
	// addi r3,r31,4872
	ctx.r3.s64 = r31.s64 + 4872;
	// bl 0x821f8840
	ctx.lr = 0x821FDFF8;
	sub_821F8840(ctx, base);
	// addi r21,r31,7520
	r21.s64 = r31.s64 + 7520;
	// stw r30,5528(r31)
	PPC_STORE_U32(r31.u32 + 5528, r30.u32);
	// mr r23,r28
	r23.u64 = r28.u64;
	// stw r30,5532(r31)
	PPC_STORE_U32(r31.u32 + 5532, r30.u32);
	// mr r26,r21
	r26.u64 = r21.u64;
	// stw r30,5536(r31)
	PPC_STORE_U32(r31.u32 + 5536, r30.u32);
	// stw r30,5540(r31)
	PPC_STORE_U32(r31.u32 + 5540, r30.u32);
	// stw r30,7088(r31)
	PPC_STORE_U32(r31.u32 + 7088, r30.u32);
	// stw r30,7084(r31)
	PPC_STORE_U32(r31.u32 + 7084, r30.u32);
	// stw r30,7080(r31)
	PPC_STORE_U32(r31.u32 + 7080, r30.u32);
loc_821FE020:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821305f0
	ctx.lr = 0x821FE038;
	sub_821305F0(ctx, base);
	// stw r30,1024(r26)
	PPC_STORE_U32(r26.u32 + 1024, r30.u32);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r26,r26,1040
	r26.s64 = r26.s64 + 1040;
	// bge 0x821fe020
	if (!cr0.lt) goto loc_821FE020;
	// stw r30,10624(r31)
	PPC_STORE_U32(r31.u32 + 10624, r30.u32);
	// stfs f31,10660(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 10660, temp.u32);
	// stb r30,10656(r31)
	PPC_STORE_U8(r31.u32 + 10656, r30.u8);
	// addi r3,r31,10736
	ctx.r3.s64 = r31.s64 + 10736;
	// stb r30,10657(r31)
	PPC_STORE_U8(r31.u32 + 10657, r30.u8);
	// addi r26,r31,9600
	r26.s64 = r31.s64 + 9600;
	// stw r30,10668(r31)
	PPC_STORE_U32(r31.u32 + 10668, r30.u32);
	// stw r30,10672(r31)
	PPC_STORE_U32(r31.u32 + 10672, r30.u32);
	// stw r30,10676(r31)
	PPC_STORE_U32(r31.u32 + 10676, r30.u32);
	// stw r30,10680(r31)
	PPC_STORE_U32(r31.u32 + 10680, r30.u32);
	// stw r30,10684(r31)
	PPC_STORE_U32(r31.u32 + 10684, r30.u32);
	// stb r30,10708(r31)
	PPC_STORE_U8(r31.u32 + 10708, r30.u8);
	// stw r30,10712(r31)
	PPC_STORE_U32(r31.u32 + 10712, r30.u32);
	// stw r30,10716(r31)
	PPC_STORE_U32(r31.u32 + 10716, r30.u32);
	// stb r30,10720(r31)
	PPC_STORE_U8(r31.u32 + 10720, r30.u8);
	// bl 0x82214ac0
	ctx.lr = 0x821FE088;
	sub_82214AC0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stb r30,13280(r31)
	PPC_STORE_U8(r31.u32 + 13280, r30.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stb r30,13281(r31)
	PPC_STORE_U8(r31.u32 + 13281, r30.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,13284(r31)
	PPC_STORE_U32(r31.u32 + 13284, r30.u32);
	// lfs f30,-17576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17576);
	f30.f64 = double(temp.f32);
	// stw r30,13288(r31)
	PPC_STORE_U32(r31.u32 + 13288, r30.u32);
	// lfs f29,-17580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17580);
	f29.f64 = double(temp.f32);
	// lwz r8,604(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 604);
	// stfs f30,96(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r30,4604(r31)
	PPC_STORE_U32(r31.u32 + 4604, r30.u32);
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FE0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stfs f30,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r11,4496
	r11.s64 = 4496;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f30,30284(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30284);
	f30.f64 = double(temp.f32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lfs f29,-29924(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29924);
	f29.f64 = double(temp.f32);
	// stfs f30,128(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f29,132(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,4828(r31)
	PPC_STORE_U32(r31.u32 + 4828, r30.u32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,604(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 604);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FE124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f30,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r7,4720
	ctx.r7.s64 = 4720;
	// stfs f29,132(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-10264
	ctx.r5.s64 = ctx.r6.s64 + -10264;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fe164
	if (cr6.eq) goto loc_821FE164;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
	// b 0x821fe168
	goto loc_821FE168;
loc_821FE164:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821FE168:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r5,r10,-22604
	ctx.r5.s64 = ctx.r10.s64 + -22604;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r24,r10,32684
	r24.s64 = ctx.r10.s64 + 32684;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// beq cr6,0x821fe190
	if (cr6.eq) goto loc_821FE190;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823ddb08
	ctx.lr = 0x821FE190;
	sub_823DDB08(ctx, base);
loc_821FE190:
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x821FE198;
	sub_82130528(ctx, base);
	// li r29,32
	r29.s64 = 32;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x821FE1AC;
	sub_82130528(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// sth r29,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r29.u16);
	// bl 0x821fc0c0
	ctx.lr = 0x821FE1B8;
	sub_821FC0C0(ctx, base);
	// lis r25,-32111
	r25.s64 = -2104426496;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r11,-17592
	ctx.r4.s64 = r11.s64 + -17592;
	// lwz r3,-24180(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -24180);
	// bl 0x821fd878
	ctx.lr = 0x821FE1D0;
	sub_821FD878(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r3,r27,92
	ctx.r3.s64 = r27.s64 + 92;
	// addi r4,r9,9792
	ctx.r4.s64 = ctx.r9.s64 + 9792;
	// lfd f1,-17600(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + -17600);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x823dc018
	ctx.lr = 0x821FE1F4;
	sub_823DC018(ctx, base);
	// li r8,4
	ctx.r8.s64 = 4;
	// stfs f31,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + 88, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,156(r27)
	PPC_STORE_U32(r27.u32 + 156, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-21540
	ctx.r4.s64 = ctx.r7.s64 + -21540;
	// lwz r3,-24180(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x821FE214;
	sub_821FD980(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r30,88(r27)
	PPC_STORE_U32(r27.u32 + 88, r30.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r27,92
	ctx.r3.s64 = r27.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x821FE22C;
	sub_823DC018(ctx, base);
	// li r23,3
	r23.s64 = 3;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stw r23,156(r27)
	PPC_STORE_U32(r27.u32 + 156, r23.u32);
	// lwz r11,-10232(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10232);
	// addi r25,r11,8
	r25.s64 = r11.s64 + 8;
	// bl 0x82178848
	ctx.lr = 0x821FE244;
	sub_82178848(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r4,r4,-21512
	ctx.r4.s64 = ctx.r4.s64 + -21512;
	// xori r22,r10,1
	r22.u64 = ctx.r10.u64 ^ 1;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x821fd980
	ctx.lr = 0x821FE268;
	sub_821FD980(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r27,92
	ctx.r3.s64 = r27.s64 + 92;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// stw r22,88(r27)
	PPC_STORE_U32(r27.u32 + 88, r22.u32);
	// bl 0x823dc018
	ctx.lr = 0x821FE280;
	sub_823DC018(ctx, base);
	// stw r23,156(r27)
	PPC_STORE_U32(r27.u32 + 156, r23.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821FE28C;
	sub_82387928(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r4,r9,-21520
	ctx.r4.s64 = ctx.r9.s64 + -21520;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821fd980
	ctx.lr = 0x821FE2A4;
	sub_821FD980(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r27,92
	ctx.r3.s64 = r27.s64 + 92;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// stw r22,88(r27)
	PPC_STORE_U32(r27.u32 + 88, r22.u32);
	// bl 0x823dc018
	ctx.lr = 0x821FE2BC;
	sub_823DC018(ctx, base);
	// stw r23,156(r27)
	PPC_STORE_U32(r27.u32 + 156, r23.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82180430
	ctx.lr = 0x821FE2CC;
	sub_82180430(ctx, base);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-25232(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -25232);
	// addi r4,r8,-21824
	ctx.r4.s64 = ctx.r8.s64 + -21824;
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r30.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stb r30,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, r30.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// stb r28,162(r1)
	PPC_STORE_U8(ctx.r1.u32 + 162, r28.u8);
	// li r7,256
	ctx.r7.s64 = 256;
	// stb r28,161(r1)
	PPC_STORE_U8(ctx.r1.u32 + 161, r28.u8);
	// li r6,256
	ctx.r6.s64 = 256;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FE310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stb r28,162(r1)
	PPC_STORE_U8(ctx.r1.u32 + 162, r28.u8);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,5536(r31)
	PPC_STORE_U32(r31.u32 + 5536, ctx.r8.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lwz r3,-25232(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -25232);
	// addi r4,r7,-18640
	ctx.r4.s64 = ctx.r7.s64 + -18640;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// stb r28,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, r28.u8);
	// li r7,256
	ctx.r7.s64 = 256;
	// li r6,256
	ctx.r6.s64 = 256;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// li r5,3
	ctx.r5.s64 = 3;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821FE354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,4208
	r11.s64 = r31.s64 + 4208;
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r3,5540(r31)
	PPC_STORE_U32(r31.u32 + 5540, ctx.r3.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r9,r31,4272
	ctx.r9.s64 = r31.s64 + 4272;
	// vupkd3d128 v63,v62,4
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// addi r8,r31,4336
	ctx.r8.s64 = r31.s64 + 4336;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r22,-32
	r22.s64 = -32;
	// li r23,-16
	r23.s64 = -16;
	// vpermwi128 v61,v63,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// li r24,1008
	r24.s64 = 1008;
	// vpermwi128 v60,v63,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// li r25,1024
	r25.s64 = 1024;
	// vpermwi128 v59,v63,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// li r27,1040
	r27.s64 = 1040;
	// vpermwi128 v58,v63,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// li r3,2048
	ctx.r3.s64 = 2048;
	// vpermwi128 v57,v63,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// li r4,2064
	ctx.r4.s64 = 2064;
	// vpermwi128 v56,v63,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// li r5,2080
	ctx.r5.s64 = 2080;
	// vpermwi128 v55,v63,234
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v54,v63,186
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v53,v63,174
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// stvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v63,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,7552
	r11.s64 = r31.s64 + 7552;
	// stvx128 v57,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v63,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// stvx128 v56,r9,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r8,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r8,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,1056
	r29.s64 = 1056;
	// stvx128 v62,r8,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,10640
	ctx.r8.s64 = r31.s64 + 10640;
	// li r6,2096
	ctx.r6.s64 = 2096;
loc_821FE408:
	// vpermwi128 v52,v63,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// lwz r9,1024(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 1024);
	// vpermwi128 v51,v63,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v50,v63,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// vpermwi128 v49,v63,234
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// stw r9,1024(r21)
	PPC_STORE_U32(r21.u32 + 1024, ctx.r9.u32);
	// vpermwi128 v48,v63,186
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v47,v63,174
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// stvx128 v52,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,9584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 9584);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,9584(r31)
	PPC_STORE_U32(r31.u32 + 9584, ctx.r9.u32);
	// stvx128 v49,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,1024(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 1024);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,1024(r26)
	PPC_STORE_U32(r26.u32 + 1024, ctx.r9.u32);
	// stvx128 v61,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stbx r28,r8,r10
	PPC_STORE_U8(ctx.r8.u32 + ctx.r10.u32, r28.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// blt cr6,0x821fe408
	if (cr6.lt) goto loc_821FE408;
	// addi r25,r31,7092
	r25.s64 = r31.s64 + 7092;
	// mr r29,r30
	r29.u64 = r30.u64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// addi r26,r31,7508
	r26.s64 = r31.s64 + 7508;
loc_821FE498:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x821FE4A0;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821fe4bc
	if (cr6.eq) goto loc_821FE4BC;
	// bl 0x821e2748
	ctx.lr = 0x821FE4B0;
	sub_821E2748(ctx, base);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r30,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r30.u32);
	// b 0x821fe4c0
	goto loc_821FE4C0;
loc_821FE4BC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821FE4C0:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// stbx r30,r26,r29
	PPC_STORE_U8(r26.u32 + r29.u32, r30.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x821fe498
	if (cr6.lt) goto loc_821FE498;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r28,r11,-17620
	r28.s64 = r11.s64 + -17620;
	// addi r29,r10,30576
	r29.s64 = ctx.r10.s64 + 30576;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x821FE4F4;
	sub_821CA540(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821FE4FC;
	sub_82387928(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r27,r11,-17624
	r27.s64 = r11.s64 + -17624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bne cr6,0x821fe56c
	if (!cr6.eq) goto loc_821FE56C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-17652
	ctx.r4.s64 = ctx.r10.s64 + -17652;
	// bl 0x821e2940
	ctx.lr = 0x821FE528;
	sub_821E2940(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,7096(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7096);
	// addi r4,r9,-17672
	ctx.r4.s64 = ctx.r9.s64 + -17672;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// bl 0x821e2940
	ctx.lr = 0x821FE544;
	sub_821E2940(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,7100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7100);
	// addi r4,r8,-17700
	ctx.r4.s64 = ctx.r8.s64 + -17700;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// bl 0x821e2940
	ctx.lr = 0x821FE560;
	sub_821E2940(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-17724
	ctx.r4.s64 = ctx.r7.s64 + -17724;
	// b 0x821fe5b8
	goto loc_821FE5B8;
loc_821FE56C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-17748
	ctx.r4.s64 = ctx.r10.s64 + -17748;
	// bl 0x821e2940
	ctx.lr = 0x821FE578;
	sub_821E2940(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,7096(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7096);
	// addi r4,r9,-17764
	ctx.r4.s64 = ctx.r9.s64 + -17764;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// bl 0x821e2940
	ctx.lr = 0x821FE594;
	sub_821E2940(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,7100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7100);
	// addi r4,r8,-17784
	ctx.r4.s64 = ctx.r8.s64 + -17784;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// bl 0x821e2940
	ctx.lr = 0x821FE5B0;
	sub_821E2940(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-17800
	ctx.r4.s64 = ctx.r7.s64 + -17800;
loc_821FE5B8:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,7104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7104);
	// li r6,27
	ctx.r6.s64 = 27;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x821e2940
	ctx.lr = 0x821FE5CC;
	sub_821E2940(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821FE5D4;
	sub_821C9A90(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x821FE5E0;
	sub_821CA540(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r5,r11,-17804
	ctx.r5.s64 = r11.s64 + -17804;
	// addi r4,r10,-17820
	ctx.r4.s64 = ctx.r10.s64 + -17820;
	// addi r3,r9,-22060
	ctx.r3.s64 = ctx.r9.s64 + -22060;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,9
	ctx.r6.s64 = 9;
	// bl 0x821fdd50
	ctx.lr = 0x821FE604;
	sub_821FDD50(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821FE60C;
	sub_821C9A90(ctx, base);
	// li r3,596
	ctx.r3.s64 = 596;
	// bl 0x82130528
	ctx.lr = 0x821FE614;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fe62c
	if (cr6.eq) goto loc_821FE62C;
	// bl 0x822139b0
	ctx.lr = 0x821FE620;
	sub_822139B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x821fe630
	goto loc_821FE630;
loc_821FE62C:
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
loc_821FE630:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821FE648"))) PPC_WEAK_FUNC(sub_821FE648);
PPC_FUNC_IMPL(__imp__sub_821FE648) {
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
	ctx.lr = 0x821FE650;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x821f9a18
	ctx.lr = 0x821FE65C;
	sub_821F9A18(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x821FE660;
	sub_82387B90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,1320(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1320);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218a38
	ctx.lr = 0x821FE674;
	sub_82218A38(ctx, base);
	// li r3,1348
	ctx.r3.s64 = 1348;
	// bl 0x82130528
	ctx.lr = 0x821FE67C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fe694
	if (cr6.eq) goto loc_821FE694;
	// bl 0x821f8690
	ctx.lr = 0x821FE688;
	sub_821F8690(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-10228(r11)
	PPC_STORE_U32(r11.u32 + -10228, ctx.r3.u32);
	// b 0x821fe6a0
	goto loc_821FE6A0;
loc_821FE694:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10228(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10228, r11.u32);
loc_821FE6A0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// addi r4,r10,-17620
	ctx.r4.s64 = ctx.r10.s64 + -17620;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x821FE6B8;
	sub_821CA540(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821FE6C0;
	sub_82387928(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r30,r11,-17804
	r30.s64 = r11.s64 + -17804;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,9
	ctx.r6.s64 = 9;
	// addi r3,r28,13284
	ctx.r3.s64 = r28.s64 + 13284;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bne cr6,0x821fe6f8
	if (!cr6.eq) goto loc_821FE6F8;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-17460
	ctx.r4.s64 = ctx.r10.s64 + -17460;
	// bl 0x821fdd50
	ctx.lr = 0x821FE6EC;
	sub_821FDD50(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-17484
	ctx.r4.s64 = ctx.r9.s64 + -17484;
	// b 0x821fe70c
	goto loc_821FE70C;
loc_821FE6F8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-17500
	ctx.r4.s64 = ctx.r10.s64 + -17500;
	// bl 0x821fdd50
	ctx.lr = 0x821FE704;
	sub_821FDD50(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-17524
	ctx.r4.s64 = ctx.r9.s64 + -17524;
loc_821FE70C:
	// addi r31,r28,13288
	r31.s64 = r28.s64 + 13288;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fdd50
	ctx.lr = 0x821FE724;
	sub_821FDD50(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821FE72C;
	sub_821C9A90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fe748
	if (cr6.eq) goto loc_821FE748;
	// lwz r10,-24880(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, r11.u32);
loc_821FE748:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821FE750;
	sub_82387928(ctx, base);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x821fe768
	if (!cr6.eq) goto loc_821FE768;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-17540
	ctx.r4.s64 = r11.s64 + -17540;
	// b 0x821fe770
	goto loc_821FE770;
loc_821FE768:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-17552
	ctx.r4.s64 = r11.s64 + -17552;
loc_821FE770:
	// bl 0x821ca540
	ctx.lr = 0x821FE774;
	sub_821CA540(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r28,10736
	ctx.r3.s64 = r28.s64 + 10736;
	// addi r4,r11,-17560
	ctx.r4.s64 = r11.s64 + -17560;
	// bl 0x82213ee8
	ctx.lr = 0x821FE784;
	sub_82213EE8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821FE78C;
	sub_821C9A90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fe7a8
	if (cr6.eq) goto loc_821FE7A8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_821FE7A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FE7B0"))) PPC_WEAK_FUNC(sub_821FE7B0);
PPC_FUNC_IMPL(__imp__sub_821FE7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// addi r11,r3,260
	r11.s64 = ctx.r3.s64 + 260;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,32
	ctx.r10.s64 = 32;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_821FE7C0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x821fe7c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821FE7C0;
	// li r11,14
	r11.s64 = 14;
	// stw r9,388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 388, ctx.r9.u32);
	// stw r9,396(r3)
	PPC_STORE_U32(ctx.r3.u32 + 396, ctx.r9.u32);
	// stw r9,392(r3)
	PPC_STORE_U32(ctx.r3.u32 + 392, ctx.r9.u32);
	// stb r9,416(r3)
	PPC_STORE_U8(ctx.r3.u32 + 416, ctx.r9.u8);
	// stb r9,417(r3)
	PPC_STORE_U8(ctx.r3.u32 + 417, ctx.r9.u8);
	// stb r9,418(r3)
	PPC_STORE_U8(ctx.r3.u32 + 418, ctx.r9.u8);
	// stw r11,400(r3)
	PPC_STORE_U32(ctx.r3.u32 + 400, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FE7F0"))) PPC_WEAK_FUNC(sub_821FE7F0);
PPC_FUNC_IMPL(__imp__sub_821FE7F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r6,388(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821fe84c
	if (cr6.eq) goto loc_821FE84C;
	// addi r8,r3,260
	ctx.r8.s64 = ctx.r3.s64 + 260;
loc_821FE804:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
loc_821FE810:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x821fe834
	if (cr6.eq) goto loc_821FE834;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fe810
	if (cr6.eq) goto loc_821FE810;
loc_821FE834:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fe854
	if (cr6.eq) goto loc_821FE854;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// blt cr6,0x821fe804
	if (cr6.lt) goto loc_821FE804;
loc_821FE84C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821FE854:
	// addi r11,r7,65
	r11.s64 = ctx.r7.s64 + 65;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FE864"))) PPC_WEAK_FUNC(sub_821FE864);
PPC_FUNC_IMPL(__imp__sub_821FE864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FE868"))) PPC_WEAK_FUNC(sub_821FE868);
PPC_FUNC_IMPL(__imp__sub_821FE868) {
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
	ctx.lr = 0x821FE870;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,388(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821fe8bc
	if (!cr6.gt) goto loc_821FE8BC;
	// addi r30,r28,260
	r30.s64 = r28.s64 + 260;
loc_821FE890:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FE8A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,388(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 388);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x821fe890
	if (cr6.lt) goto loc_821FE890;
loc_821FE8BC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FE8C8"))) PPC_WEAK_FUNC(sub_821FE8C8);
PPC_FUNC_IMPL(__imp__sub_821FE8C8) {
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
	ctx.lr = 0x821FE8D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,388(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821fe91c
	if (!cr6.gt) goto loc_821FE91C;
	// addi r30,r29,260
	r30.s64 = r29.s64 + 260;
loc_821FE8F0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FE904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,388(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x821fe8f0
	if (cr6.lt) goto loc_821FE8F0;
loc_821FE91C:
	// lwz r11,396(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 396);
	// addi r31,r28,8
	r31.s64 = r28.s64 + 8;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x821fe94c
	if (!cr6.lt) goto loc_821FE94C;
	// lwz r3,392(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821fe93c
	if (cr6.eq) goto loc_821FE93C;
	// bl 0x82130588
	ctx.lr = 0x821FE93C;
	sub_82130588(ctx, base);
loc_821FE93C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x821FE944;
	sub_82130528(ctx, base);
	// stw r3,392(r29)
	PPC_STORE_U32(r29.u32 + 392, ctx.r3.u32);
	// stw r31,396(r29)
	PPC_STORE_U32(r29.u32 + 396, r31.u32);
loc_821FE94C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FE954"))) PPC_WEAK_FUNC(sub_821FE954);
PPC_FUNC_IMPL(__imp__sub_821FE954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FE958"))) PPC_WEAK_FUNC(sub_821FE958);
PPC_FUNC_IMPL(__imp__sub_821FE958) {
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
	ctx.lr = 0x821FE960;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r29,12
	r30.s64 = r29.s64 + 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FE984;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821fe9b0
	if (!cr6.eq) goto loc_821FE9B0;
	// addi r11,r11,65
	r11.s64 = r11.s64 + 65;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r29.u32);
	// lwz r11,388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,388(r31)
	PPC_STORE_U32(r31.u32 + 388, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821FE9B0:
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821fea20
	if (!cr6.gt) goto loc_821FEA20;
	// addi r8,r31,260
	ctx.r8.s64 = r31.s64 + 260;
loc_821FE9C0:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
loc_821FE9CC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x821fe9f0
	if (cr6.eq) goto loc_821FE9F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fe9cc
	if (cr6.eq) goto loc_821FE9CC;
loc_821FE9F0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fea14
	if (cr6.eq) goto loc_821FEA14;
	// lwz r11,388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x821fe9c0
	if (cr6.lt) goto loc_821FE9C0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821FEA14:
	// addi r11,r7,65
	r11.s64 = ctx.r7.s64 + 65;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r29.u32);
loc_821FEA20:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FEA28"))) PPC_WEAK_FUNC(sub_821FEA28);
PPC_FUNC_IMPL(__imp__sub_821FEA28) {
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
	ctx.lr = 0x821FEA30;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r29,388
	r26.s64 = r29.s64 + 388;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,388(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821fea80
	if (!cr6.gt) goto loc_821FEA80;
	// addi r30,r29,260
	r30.s64 = r29.s64 + 260;
loc_821FEA54:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FEA68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x821fea54
	if (cr6.lt) goto loc_821FEA54;
loc_821FEA80:
	// lwz r11,396(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 396);
	// addi r27,r28,8
	r27.s64 = r28.s64 + 8;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x821feab0
	if (!cr6.lt) goto loc_821FEAB0;
	// lwz r3,392(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821feaa0
	if (cr6.eq) goto loc_821FEAA0;
	// bl 0x82130588
	ctx.lr = 0x821FEAA0;
	sub_82130588(ctx, base);
loc_821FEAA0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130528
	ctx.lr = 0x821FEAA8;
	sub_82130528(ctx, base);
	// stw r3,392(r29)
	PPC_STORE_U32(r29.u32 + 392, ctx.r3.u32);
	// stw r27,396(r29)
	PPC_STORE_U32(r29.u32 + 396, r27.u32);
loc_821FEAB0:
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// addi r10,r29,400
	ctx.r10.s64 = r29.s64 + 400;
	// lbz r9,400(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 400);
	// li r31,8
	r31.s64 = 8;
	// li r25,0
	r25.s64 = 0;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r8,401(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 401);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,402(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 402);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,403(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 403);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// lbz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// stb r5,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r5.u8);
	// lbz r4,1(r26)
	ctx.r4.u64 = PPC_LOAD_U8(r26.u32 + 1);
	// stb r4,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r4.u8);
	// lbz r3,2(r26)
	ctx.r3.u64 = PPC_LOAD_U8(r26.u32 + 2);
	// stb r3,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r3.u8);
	// lbz r10,3(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 3);
	// stb r10,7(r11)
	PPC_STORE_U8(r11.u32 + 7, ctx.r10.u8);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// ble cr6,0x821fec04
	if (!cr6.gt) goto loc_821FEC04;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r29,260
	r30.s64 = r29.s64 + 260;
	// addi r24,r11,-16016
	r24.s64 = r11.s64 + -16016;
loc_821FEB1C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// add r4,r31,r11
	ctx.r4.u64 = r31.u64 + r11.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FEB3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subf r8,r28,r27
	ctx.r8.s64 = r27.s64 - r28.s64;
	// add r10,r28,r31
	ctx.r10.u64 = r28.u64 + r31.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// subf r5,r31,r8
	ctx.r5.s64 = ctx.r8.s64 - r31.s64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821FEB6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subf r8,r28,r27
	ctx.r8.s64 = r27.s64 - r28.s64;
	// add r10,r28,r31
	ctx.r10.u64 = r28.u64 + r31.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// subf r5,r31,r8
	ctx.r5.s64 = ctx.r8.s64 - r31.s64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821FEB9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821FEBB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x821febec
	if (cr6.eq) goto loc_821FEBEC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FEBD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82130000
	ctx.lr = 0x821FEBEC;
	sub_82130000(ctx, base);
loc_821FEBEC:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// add r31,r28,r31
	r31.u64 = r28.u64 + r31.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x821feb1c
	if (cr6.lt) goto loc_821FEB1C;
loc_821FEC04:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821FEC0C"))) PPC_WEAK_FUNC(sub_821FEC0C);
PPC_FUNC_IMPL(__imp__sub_821FEC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEC10"))) PPC_WEAK_FUNC(sub_821FEC10);
PPC_FUNC_IMPL(__imp__sub_821FEC10) {
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
	ctx.lr = 0x821FEC18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,10232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 10232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821fec50
	if (!cr6.gt) goto loc_821FEC50;
	// addi r31,r29,10104
	r31.s64 = r29.s64 + 10104;
loc_821FEC34:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821fe8c8
	ctx.lr = 0x821FEC3C;
	sub_821FE8C8(ctx, base);
	// lwz r11,10232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 10232);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x821fec34
	if (cr6.lt) goto loc_821FEC34;
loc_821FEC50:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FEC58"))) PPC_WEAK_FUNC(sub_821FEC58);
PPC_FUNC_IMPL(__imp__sub_821FEC58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-10164
	ctx.r10.s64 = r11.s64 + -10164;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fec80
	if (!cr6.eq) goto loc_821FEC80;
	// lbz r11,10096(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fec80
	if (!cr6.eq) goto loc_821FEC80;
	// lbz r3,10851(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10851);
	// blr 
	return;
loc_821FEC80:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FEC88"))) PPC_WEAK_FUNC(sub_821FEC88);
PPC_FUNC_IMPL(__imp__sub_821FEC88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,10256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fec9c
	if (cr6.eq) goto loc_821FEC9C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// b 0x824e70e0
	sub_824E70E0(ctx, base);
	return;
loc_821FEC9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FECA4"))) PPC_WEAK_FUNC(sub_821FECA4);
PPC_FUNC_IMPL(__imp__sub_821FECA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FECA8"))) PPC_WEAK_FUNC(sub_821FECA8);
PPC_FUNC_IMPL(__imp__sub_821FECA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r6,10232(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10232);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821fed04
	if (cr6.eq) goto loc_821FED04;
	// addi r8,r3,10104
	ctx.r8.s64 = ctx.r3.s64 + 10104;
loc_821FECBC:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_821FECC8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x821fecec
	if (cr6.eq) goto loc_821FECEC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fecc8
	if (cr6.eq) goto loc_821FECC8;
loc_821FECEC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fed0c
	if (cr6.eq) goto loc_821FED0C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// blt cr6,0x821fecbc
	if (cr6.lt) goto loc_821FECBC;
loc_821FED04:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821FED0C:
	// addi r11,r7,2526
	r11.s64 = ctx.r7.s64 + 2526;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FED1C"))) PPC_WEAK_FUNC(sub_821FED1C);
PPC_FUNC_IMPL(__imp__sub_821FED1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FED20"))) PPC_WEAK_FUNC(sub_821FED20);
PPC_FUNC_IMPL(__imp__sub_821FED20) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,41
	ctx.r5.s64 = 41;
	// lwz r11,10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10232);
	// addi r9,r11,2526
	ctx.r9.s64 = r11.s64 + 2526;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10232);
	// addi r7,r11,2526
	ctx.r7.s64 = r11.s64 + 2526;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r31
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x821FED70;
	sub_823DB670(ctx, base);
	// lwz r11,10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10232);
	// li r5,127
	ctx.r5.s64 = 127;
	// addi r3,r11,2526
	ctx.r3.s64 = r11.s64 + 2526;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r3,r11,132
	ctx.r3.s64 = r11.s64 + 132;
	// bl 0x823db670
	ctx.lr = 0x821FED90;
	sub_823DB670(ctx, base);
	// lwz r11,10232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10232);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,10232(r31)
	PPC_STORE_U32(r31.u32 + 10232, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821FEDB4"))) PPC_WEAK_FUNC(sub_821FEDB4);
PPC_FUNC_IMPL(__imp__sub_821FEDB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEDB8"))) PPC_WEAK_FUNC(sub_821FEDB8);
PPC_FUNC_IMPL(__imp__sub_821FEDB8) {
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
	ctx.lr = 0x821FEDC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821feca8
	ctx.lr = 0x821FEDD4;
	sub_821FECA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821FEDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FEDF4"))) PPC_WEAK_FUNC(sub_821FEDF4);
PPC_FUNC_IMPL(__imp__sub_821FEDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEDF8"))) PPC_WEAK_FUNC(sub_821FEDF8);
PPC_FUNC_IMPL(__imp__sub_821FEDF8) {
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
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821feca8
	ctx.lr = 0x821FEE18;
	sub_821FECA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821FEE2C;
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

__attribute__((alias("__imp__sub_821FEE44"))) PPC_WEAK_FUNC(sub_821FEE44);
PPC_FUNC_IMPL(__imp__sub_821FEE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEE48"))) PPC_WEAK_FUNC(sub_821FEE48);
PPC_FUNC_IMPL(__imp__sub_821FEE48) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FEE78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821fef04
	if (!cr6.eq) goto loc_821FEF04;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821feecc
	if (!cr6.eq) goto loc_821FEECC;
	// lwz r11,10256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10256);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7120
	ctx.lr = 0x821FEEA0;
	sub_824E7120(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fef04
	if (cr6.eq) goto loc_821FEF04;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FEEC0;
	sub_8268EE10(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,10097(r30)
	PPC_STORE_U8(r30.u32 + 10097, r11.u8);
	// b 0x821fef04
	goto loc_821FEF04;
loc_821FEECC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821fef04
	if (!cr6.eq) goto loc_821FEF04;
	// lwz r11,10256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10256);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7120
	ctx.lr = 0x821FEEE4;
	sub_824E7120(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fef04
	if (cr6.eq) goto loc_821FEF04;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,22
	ctx.r4.s64 = 22;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FEF04;
	sub_8268EE10(ctx, base);
loc_821FEF04:
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

__attribute__((alias("__imp__sub_821FEF1C"))) PPC_WEAK_FUNC(sub_821FEF1C);
PPC_FUNC_IMPL(__imp__sub_821FEF1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEF20"))) PPC_WEAK_FUNC(sub_821FEF20);
PPC_FUNC_IMPL(__imp__sub_821FEF20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r5,220(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x821fef7c
	if (!cr6.gt) goto loc_821FEF7C;
	// addi r6,r3,10296
	ctx.r6.s64 = ctx.r3.s64 + 10296;
	// addi r8,r3,488
	ctx.r8.s64 = ctx.r3.s64 + 488;
loc_821FEF38:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_821FEF40:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x821fef64
	if (cr6.eq) goto loc_821FEF64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fef40
	if (cr6.eq) goto loc_821FEF40;
loc_821FEF64:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821fef84
	if (cr6.eq) goto loc_821FEF84;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,308
	ctx.r8.s64 = ctx.r8.s64 + 308;
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// blt cr6,0x821fef38
	if (cr6.lt) goto loc_821FEF38;
loc_821FEF7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821FEF84:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FEF8C"))) PPC_WEAK_FUNC(sub_821FEF8C);
PPC_FUNC_IMPL(__imp__sub_821FEF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FEF90"))) PPC_WEAK_FUNC(sub_821FEF90);
PPC_FUNC_IMPL(__imp__sub_821FEF90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10100);
	// addi r3,r11,23576
	ctx.r3.s64 = r11.s64 + 23576;
	// b 0x82617700
	sub_82617700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FEFA0"))) PPC_WEAK_FUNC(sub_821FEFA0);
PPC_FUNC_IMPL(__imp__sub_821FEFA0) {
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
	ctx.lr = 0x821FEFA8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10274(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10274);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ff128
	if (!cr6.eq) goto loc_821FF128;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-10124
	ctx.r10.s64 = r11.s64 + -10124;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ff128
	if (!cr6.eq) goto loc_821FF128;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-10184
	ctx.r10.s64 = r11.s64 + -10184;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ff128
	if (!cr6.eq) goto loc_821FF128;
	// lwz r11,392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x821ff128
	if (!cr6.eq) goto loc_821FF128;
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r11,8
	r11.s64 = 8;
	// mr r27,r28
	r27.u64 = r28.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821ff128
	if (cr6.eq) goto loc_821FF128;
loc_821FF028:
	// lwz r10,396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821ff128
	if (!cr6.lt) goto loc_821FF128;
	// lwz r10,392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + r29.u64;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821FF054;
	sub_823DA950(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// add r9,r30,r29
	ctx.r9.u64 = r30.u64 + r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stbx r28,r30,r10
	PPC_STORE_U8(r30.u32 + ctx.r10.u32, r28.u8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821FF07C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821ff0f0
	if (cr6.eq) goto loc_821FF0F0;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// lwz r10,392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821FF0B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821ff104
	if (cr6.eq) goto loc_821FF104;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// lwz r10,392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821FF0E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r3,r6
	r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_821FF0F0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmplw cr6,r27,r26
	cr6.compare<uint32_t>(r27.u32, r26.u32, xer);
	// blt cr6,0x821ff028
	if (cr6.lt) goto loc_821FF028;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
loc_821FF104:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821FF128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FF128:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821FF130"))) PPC_WEAK_FUNC(sub_821FF130);
PPC_FUNC_IMPL(__imp__sub_821FF130) {
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
	ctx.lr = 0x821FF138;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bne cr6,0x821ff150
	if (!cr6.eq) goto loc_821FF150;
	// li r4,0
	ctx.r4.s64 = 0;
loc_821FF150:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF160;
	sub_8268B6D0(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268b6d0
	ctx.lr = 0x821FF174;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF184;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF194;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1A4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1B4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1C4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1D4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1E4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF1F4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF204;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF214;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF224;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF234;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF244;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF254;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF264;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF274;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF284;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,132(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF294;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2A4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2B4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2C4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2D4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2E4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF2F4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,164(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF304;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF314;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,172(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF324;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF334;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF344;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF354;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,188(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF364;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF374;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF384;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF394;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,204(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF3A4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF3B4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF3C4;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,212(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF3D4;
	sub_8268B6D0(ctx, base);
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// bl 0x8268b6d0
	ctx.lr = 0x821FF3E4;
	sub_8268B6D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,10236
	ctx.r4.s64 = r31.s64 + 10236;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7fe8
	ctx.lr = 0x821FF3F8;
	sub_824E7FE8(ctx, base);
	// lhz r10,10860(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10860);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ff444
	if (cr6.eq) goto loc_821FF444;
	// li r29,0
	r29.s64 = 0;
loc_821FF40C:
	// lwz r11,10856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ff430
	if (cr6.eq) goto loc_821FF430;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FF430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FF430:
	// lhz r11,10860(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10860);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x821ff40c
	if (cr6.lt) goto loc_821FF40C;
loc_821FF444:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FF44C"))) PPC_WEAK_FUNC(sub_821FF44C);
PPC_FUNC_IMPL(__imp__sub_821FF44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FF450"))) PPC_WEAK_FUNC(sub_821FF450);
PPC_FUNC_IMPL(__imp__sub_821FF450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x821FF458;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r10,r31,10104
	ctx.r10.s64 = r31.s64 + 10104;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r9,32
	ctx.r9.s64 = 32;
	// stfs f0,10260(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 10260, temp.u32);
	// stb r11,10272(r31)
	PPC_STORE_U8(r31.u32 + 10272, r11.u8);
	// stw r11,10100(r31)
	PPC_STORE_U32(r31.u32 + 10100, r11.u32);
	// stb r11,10096(r31)
	PPC_STORE_U8(r31.u32 + 10096, r11.u8);
	// stw r11,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r11.u32);
	// stb r11,10097(r31)
	PPC_STORE_U8(r31.u32 + 10097, r11.u8);
	// stb r11,10098(r31)
	PPC_STORE_U8(r31.u32 + 10098, r11.u8);
	// stb r11,10099(r31)
	PPC_STORE_U8(r31.u32 + 10099, r11.u8);
	// stb r11,10268(r31)
	PPC_STORE_U8(r31.u32 + 10268, r11.u8);
	// stb r11,10269(r31)
	PPC_STORE_U8(r31.u32 + 10269, r11.u8);
	// stb r11,10088(r31)
	PPC_STORE_U8(r31.u32 + 10088, r11.u8);
	// stb r11,10270(r31)
	PPC_STORE_U8(r31.u32 + 10270, r11.u8);
	// stw r11,10292(r31)
	PPC_STORE_U32(r31.u32 + 10292, r11.u32);
	// stb r11,10273(r31)
	PPC_STORE_U8(r31.u32 + 10273, r11.u8);
	// stb r11,10274(r31)
	PPC_STORE_U8(r31.u32 + 10274, r11.u8);
	// stb r11,10275(r31)
	PPC_STORE_U8(r31.u32 + 10275, r11.u8);
	// stb r11,10850(r31)
	PPC_STORE_U8(r31.u32 + 10850, r11.u8);
	// stb r11,10852(r31)
	PPC_STORE_U8(r31.u32 + 10852, r11.u8);
	// stb r11,10276(r31)
	PPC_STORE_U8(r31.u32 + 10276, r11.u8);
	// stw r11,10280(r31)
	PPC_STORE_U32(r31.u32 + 10280, r11.u32);
	// stb r11,10288(r31)
	PPC_STORE_U8(r31.u32 + 10288, r11.u8);
	// stb r7,10851(r31)
	PPC_STORE_U8(r31.u32 + 10851, ctx.r7.u8);
	// stb r11,10289(r31)
	PPC_STORE_U8(r31.u32 + 10289, r11.u8);
	// stb r11,10290(r31)
	PPC_STORE_U8(r31.u32 + 10290, r11.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_821FF4DC:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x821ff4dc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821FF4DC;
	// stw r11,10232(r31)
	PPC_STORE_U32(r31.u32 + 10232, r11.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r5,r11,-15244
	ctx.r5.s64 = r11.s64 + -15244;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x821FF510;
	sub_8268B960(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-19968
	ctx.r5.s64 = ctx.r10.s64 + -19968;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF52C;
	sub_8268B960(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15256
	ctx.r5.s64 = ctx.r9.s64 + -15256;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF548;
	sub_8268B960(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-15268
	ctx.r5.s64 = ctx.r8.s64 + -15268;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF564;
	sub_8268B960(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15284
	ctx.r5.s64 = ctx.r7.s64 + -15284;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF580;
	sub_8268B960(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-15296
	ctx.r5.s64 = ctx.r6.s64 + -15296;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF59C;
	sub_8268B960(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-15312
	ctx.r5.s64 = ctx.r5.s64 + -15312;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF5B8;
	sub_8268B960(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-15332
	ctx.r5.s64 = r11.s64 + -15332;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF5D4;
	sub_8268B960(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-15348
	ctx.r5.s64 = ctx.r10.s64 + -15348;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF5F0;
	sub_8268B960(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15368
	ctx.r5.s64 = ctx.r9.s64 + -15368;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF60C;
	sub_8268B960(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-15400
	ctx.r5.s64 = ctx.r8.s64 + -15400;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF628;
	sub_8268B960(ctx, base);
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15416
	ctx.r5.s64 = ctx.r7.s64 + -15416;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF644;
	sub_8268B960(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-15440
	ctx.r5.s64 = ctx.r6.s64 + -15440;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF660;
	sub_8268B960(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-19992
	ctx.r5.s64 = ctx.r5.s64 + -19992;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF67C;
	sub_8268B960(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-15464
	ctx.r5.s64 = r11.s64 + -15464;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF698;
	sub_8268B960(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-15488
	ctx.r5.s64 = ctx.r10.s64 + -15488;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF6B4;
	sub_8268B960(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15512
	ctx.r5.s64 = ctx.r9.s64 + -15512;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF6D0;
	sub_8268B960(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-20020
	ctx.r5.s64 = ctx.r8.s64 + -20020;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF6EC;
	sub_8268B960(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15536
	ctx.r5.s64 = ctx.r7.s64 + -15536;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF708;
	sub_8268B960(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-15552
	ctx.r5.s64 = ctx.r6.s64 + -15552;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF724;
	sub_8268B960(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-15576
	ctx.r5.s64 = ctx.r5.s64 + -15576;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF740;
	sub_8268B960(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-15592
	ctx.r5.s64 = r11.s64 + -15592;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF75C;
	sub_8268B960(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r10,-15612
	ctx.r5.s64 = ctx.r10.s64 + -15612;
	// bl 0x8268b960
	ctx.lr = 0x821FF778;
	sub_8268B960(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15628
	ctx.r5.s64 = ctx.r9.s64 + -15628;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF794;
	sub_8268B960(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-15648
	ctx.r5.s64 = ctx.r8.s64 + -15648;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF7B0;
	sub_8268B960(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15668
	ctx.r5.s64 = ctx.r7.s64 + -15668;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF7CC;
	sub_8268B960(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-15692
	ctx.r5.s64 = ctx.r6.s64 + -15692;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF7E8;
	sub_8268B960(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r5,-15712
	ctx.r5.s64 = ctx.r5.s64 + -15712;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF804;
	sub_8268B960(ctx, base);
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-15732
	ctx.r5.s64 = r11.s64 + -15732;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF820;
	sub_8268B960(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-15760
	ctx.r5.s64 = ctx.r10.s64 + -15760;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF83C;
	sub_8268B960(ctx, base);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15772
	ctx.r5.s64 = ctx.r9.s64 + -15772;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF858;
	sub_8268B960(ctx, base);
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-15796
	ctx.r5.s64 = ctx.r8.s64 + -15796;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF874;
	sub_8268B960(ctx, base);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15816
	ctx.r5.s64 = ctx.r7.s64 + -15816;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF890;
	sub_8268B960(ctx, base);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r6,-20036
	ctx.r5.s64 = ctx.r6.s64 + -20036;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF8AC;
	sub_8268B960(ctx, base);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// addi r5,r5,-20056
	ctx.r5.s64 = ctx.r5.s64 + -20056;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF8C8;
	sub_8268B960(ctx, base);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-15832
	ctx.r5.s64 = r11.s64 + -15832;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF8E4;
	sub_8268B960(ctx, base);
	// stw r3,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,-15852
	ctx.r5.s64 = ctx.r10.s64 + -15852;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF900;
	sub_8268B960(ctx, base);
	// stw r3,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r9,-15876
	ctx.r5.s64 = ctx.r9.s64 + -15876;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF91C;
	sub_8268B960(ctx, base);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r8,-15900
	ctx.r5.s64 = ctx.r8.s64 + -15900;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF938;
	sub_8268B960(ctx, base);
	// stw r3,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,-15920
	ctx.r5.s64 = ctx.r7.s64 + -15920;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8268b960
	ctx.lr = 0x821FF954;
	sub_8268B960(ctx, base);
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r5,-15940
	ctx.r5.s64 = ctx.r5.s64 + -15940;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268b960
	ctx.lr = 0x821FF970;
	sub_8268B960(ctx, base);
	// stw r3,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821FF97C"))) PPC_WEAK_FUNC(sub_821FF97C);
PPC_FUNC_IMPL(__imp__sub_821FF97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FF980"))) PPC_WEAK_FUNC(sub_821FF980);
PPC_FUNC_IMPL(__imp__sub_821FF980) {
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
	// bl 0x821feca8
	ctx.lr = 0x821FF99C;
	sub_821FECA8(ctx, base);
	// lbz r11,10096(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10096);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ffa54
	if (!cr6.eq) goto loc_821FFA54;
	// lwz r11,10092(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821ffa54
	if (!cr6.eq) goto loc_821FFA54;
	// lwz r11,10256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10256);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x821FF9C4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ff9e8
	if (!cr6.eq) goto loc_821FF9E8;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FF9E4;
	sub_8268EE10(ctx, base);
	// b 0x821ffa54
	goto loc_821FFA54;
loc_821FF9E8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ffa54
	if (cr6.eq) goto loc_821FFA54;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r31,4
	ctx.r9.s64 = r31.s64 + 4;
	// stb r11,417(r31)
	PPC_STORE_U8(r31.u32 + 417, r11.u8);
	// addi r11,r30,10296
	r11.s64 = r30.s64 + 10296;
	// stw r31,10292(r30)
	PPC_STORE_U32(r30.u32 + 10292, r31.u32);
	// li r10,41
	ctx.r10.s64 = 41;
loc_821FFA08:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821ffa28
	if (cr6.eq) goto loc_821FFA28;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x821ffa08
	if (cr0.gt) goto loc_821FFA08;
loc_821FFA28:
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r3,r9,23576
	ctx.r3.s64 = ctx.r9.s64 + 23576;
	// lwz r4,10100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10100);
	// addi r6,r30,224
	ctx.r6.s64 = r30.s64 + 224;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826174e8
	ctx.lr = 0x821FFA4C;
	sub_826174E8(ctx, base);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r8,10092(r30)
	PPC_STORE_U32(r30.u32 + 10092, ctx.r8.u32);
loc_821FFA54:
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

__attribute__((alias("__imp__sub_821FFA6C"))) PPC_WEAK_FUNC(sub_821FFA6C);
PPC_FUNC_IMPL(__imp__sub_821FFA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FFA70"))) PPC_WEAK_FUNC(sub_821FFA70);
PPC_FUNC_IMPL(__imp__sub_821FFA70) {
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
	ctx.lr = 0x821FFA78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,10096(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ffc1c
	if (!cr6.eq) goto loc_821FFC1C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821ffc1c
	if (cr6.eq) goto loc_821FFC1C;
	// lwz r11,10092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821ffc1c
	if (!cr6.eq) goto loc_821FFC1C;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x821FFAB0;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ffad8
	if (!cr6.eq) goto loc_821FFAD8;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FFAD0;
	sub_8268EE10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821FFAD8:
	// li r11,2
	r11.s64 = 2;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// stw r11,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x821FFAF8;
	sub_8268B800(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821FFB0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r30,4
	ctx.r7.s64 = r30.s64 + 4;
	// addi r8,r31,488
	ctx.r8.s64 = r31.s64 + 488;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_821FFB1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x821ffb40
	if (cr6.eq) goto loc_821FFB40;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821ffb1c
	if (cr6.eq) goto loc_821FFB1C;
loc_821FFB40:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821ffbac
	if (cr6.eq) goto loc_821FFBAC;
loc_821FFB48:
	// cmplwi cr6,r29,32
	cr6.compare<uint32_t>(r29.u32, 32, xer);
	// bge cr6,0x821ffb94
	if (!cr6.lt) goto loc_821FFB94;
	// addi r8,r8,308
	ctx.r8.s64 = ctx.r8.s64 + 308;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_821FFB60:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x821ffb84
	if (cr6.eq) goto loc_821FFB84;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821ffb60
	if (cr6.eq) goto loc_821FFB60;
loc_821FFB84:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821ffb48
	if (!cr6.eq) goto loc_821FFB48;
	// cmplwi cr6,r29,32
	cr6.compare<uint32_t>(r29.u32, 32, xer);
	// blt cr6,0x821ffbac
	if (cr6.lt) goto loc_821FFBAC;
loc_821FFB94:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x8268b800
	ctx.lr = 0x821FFBA4;
	sub_8268B800(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821FFBAC:
	// li r11,1
	r11.s64 = 1;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// stb r11,417(r30)
	PPC_STORE_U8(r30.u32 + 417, r11.u8);
	// addi r11,r31,10296
	r11.s64 = r31.s64 + 10296;
	// stw r30,10292(r31)
	PPC_STORE_U32(r31.u32 + 10292, r30.u32);
	// li r10,41
	ctx.r10.s64 = 41;
loc_821FFBC4:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821ffbe4
	if (cr6.eq) goto loc_821FFBE4;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x821ffbc4
	if (cr0.gt) goto loc_821FFBC4;
loc_821FFBE4:
	// li r10,0
	ctx.r10.s64 = 0;
	// mulli r8,r29,308
	ctx.r8.s64 = r29.s64 * 308;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r10,396(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// lwz r9,392(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r8,r11,488
	ctx.r8.s64 = r11.s64 + 488;
	// addi r3,r7,23576
	ctx.r3.s64 = ctx.r7.s64 + 23576;
	// addi r6,r11,232
	ctx.r6.s64 = r11.s64 + 232;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r7,224(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// bl 0x826175d0
	ctx.lr = 0x821FFC1C;
	sub_826175D0(ctx, base);
loc_821FFC1C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821FFC24"))) PPC_WEAK_FUNC(sub_821FFC24);
PPC_FUNC_IMPL(__imp__sub_821FFC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FFC28"))) PPC_WEAK_FUNC(sub_821FFC28);
PPC_FUNC_IMPL(__imp__sub_821FFC28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r3,10236
	ctx.r4.s64 = ctx.r3.s64 + 10236;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// b 0x824e7f88
	sub_824E7F88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821FFC3C"))) PPC_WEAK_FUNC(sub_821FFC3C);
PPC_FUNC_IMPL(__imp__sub_821FFC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821FFC40"))) PPC_WEAK_FUNC(sub_821FFC40);
PPC_FUNC_IMPL(__imp__sub_821FFC40) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r3,r11,23576
	ctx.r3.s64 = r11.s64 + 23576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82617478
	ctx.lr = 0x821FFC74;
	sub_82617478(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ffcd8
	if (cr6.eq) goto loc_821FFCD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x821FFC94;
	sub_8268B800(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,33
	ctx.r4.s64 = 33;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FFCA8;
	sub_8268EE10(ctx, base);
	// lbz r9,10275(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r10,10098(r31)
	PPC_STORE_U8(r31.u32 + 10098, ctx.r10.u8);
	// bne cr6,0x821ffcec
	if (!cr6.eq) goto loc_821FFCEC;
	// li r11,3
	r11.s64 = 3;
	// stw r11,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821FFCD8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15232
	ctx.r3.s64 = r11.s64 + -15232;
	// bl 0x82130000
	ctx.lr = 0x821FFCE4;
	sub_82130000(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,10098(r31)
	PPC_STORE_U8(r31.u32 + 10098, ctx.r10.u8);
loc_821FFCEC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FFD00"))) PPC_WEAK_FUNC(sub_821FFD00);
PPC_FUNC_IMPL(__imp__sub_821FFD00) {
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
	// lbz r11,10096(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ffe04
	if (!cr6.eq) goto loc_821FFE04;
	// lwz r11,10092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821ffe04
	if (!cr6.eq) goto loc_821FFE04;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ffd74
	if (cr6.eq) goto loc_821FFD74;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x821FFD40;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ffd74
	if (!cr6.eq) goto loc_821FFD74;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FFD60;
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
loc_821FFD74:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r3,r11,23576
	ctx.r3.s64 = r11.s64 + 23576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82617478
	ctx.lr = 0x821FFD94;
	sub_82617478(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ffdf0
	if (cr6.eq) goto loc_821FFDF0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x821FFDB4;
	sub_8268B800(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FFDC8;
	sub_8268EE10(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,6
	ctx.r10.s64 = 6;
	// stb r11,10098(r31)
	PPC_STORE_U8(r31.u32 + 10098, r11.u8);
	// stb r11,10097(r31)
	PPC_STORE_U8(r31.u32 + 10097, r11.u8);
	// stw r10,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821FFDF0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15232
	ctx.r3.s64 = r11.s64 + -15232;
	// bl 0x82130000
	ctx.lr = 0x821FFDFC;
	sub_82130000(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,10098(r31)
	PPC_STORE_U8(r31.u32 + 10098, ctx.r10.u8);
loc_821FFE04:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_821FFE18"))) PPC_WEAK_FUNC(sub_821FFE18);
PPC_FUNC_IMPL(__imp__sub_821FFE18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,10264(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 10264);
	ctx.f13.f64 = double(temp.f32);
	// lbz r10,10096(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// lfs f0,96(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,10264(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 10264, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821fffcc
	if (!cr6.eq) goto loc_821FFFCC;
	// lfs f0,10260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 10260);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,10260(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 10260, temp.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821ffeec
	if (cr6.lt) goto loc_821FFEEC;
	// lbz r11,10099(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10099);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ffe98
	if (cr6.eq) goto loc_821FFE98;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,10256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// bl 0x82272d50
	ctx.lr = 0x821FFE98;
	sub_82272D50(ctx, base);
loc_821FFE98:
	// lbz r11,10098(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10098);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ffeac
	if (cr6.eq) goto loc_821FFEAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ffc40
	ctx.lr = 0x821FFEAC;
	sub_821FFC40(ctx, base);
loc_821FFEAC:
	// lbz r11,10269(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10269);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ffee8
	if (cr6.eq) goto loc_821FFEE8;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r3,r11,23576
	ctx.r3.s64 = r11.s64 + 23576;
	// bl 0x82617750
	ctx.lr = 0x821FFEC8;
	sub_82617750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ffee8
	if (cr6.eq) goto loc_821FFEE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x821FFEE8;
	sub_8268B800(ctx, base);
loc_821FFEE8:
	// stfs f30,10260(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 10260, temp.u32);
loc_821FFEEC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lbz r11,-10188(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -10188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821fff44
	if (cr6.eq) goto loc_821FFF44;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f0,-10192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -10192);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lfd f13,-10200(r11)
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + -10200);
	// stfs f0,-10192(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -10192, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821fff44
	if (cr6.lt) goto loc_821FFF44;
	// lbz r11,10850(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10850);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821fff44
	if (!cr6.eq) goto loc_821FFF44;
	// stfs f30,-10192(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + -10192, temp.u32);
	// stb r11,-10188(r10)
	PPC_STORE_U8(ctx.r10.u32 + -10188, r11.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,44
	ctx.r4.s64 = 44;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x821FFF44;
	sub_8268EE10(ctx, base);
loc_821FFF44:
	// lwz r11,10092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10092);
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x821fffcc
	if (cr6.gt) goto loc_821FFFCC;
	// lis r12,-32224
	r12.s64 = -2111832064;
	// addi r12,r12,-152
	r12.s64 = r12.s64 + -152;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_821FFFCC;
	case 1:
		goto loc_821FFF84;
	case 2:
		goto loc_821FFF90;
	case 3:
		goto loc_821FFF9C;
	case 4:
		goto loc_821FFFA8;
	case 5:
		goto loc_821FFFCC;
	case 6:
		goto loc_821FFFB4;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-52(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -52);
	// lwz r16,-124(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -124);
	// lwz r16,-112(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -112);
	// lwz r16,-100(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -100);
	// lwz r16,-88(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -88);
	// lwz r16,-52(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -52);
	// lwz r16,-76(r31)
	r16.u64 = PPC_LOAD_U32(r31.u32 + -76);
loc_821FFF84:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// b 0x821fffbc
	goto loc_821FFFBC;
loc_821FFF90:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// b 0x821fffbc
	goto loc_821FFFBC;
loc_821FFF9C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x821fffbc
	goto loc_821FFFBC;
loc_821FFFA8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// b 0x821fffbc
	goto loc_821FFFBC;
loc_821FFFB4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
loc_821FFFBC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821FFFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821FFFCC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821FFFE8"))) PPC_WEAK_FUNC(sub_821FFFE8);
PPC_FUNC_IMPL(__imp__sub_821FFFE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,23576
	r31.s64 = r11.s64 + 23576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,10100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10100);
	// bl 0x82617820
	ctx.lr = 0x82200014;
	sub_82617820(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,10100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10100);
	// bl 0x826177f0
	ctx.lr = 0x82200020;
	sub_826177F0(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x82200084
	if (cr6.gt) goto loc_82200084;
	// lis r12,-32224
	r12.s64 = -2111832064;
	// addi r12,r12,68
	r12.s64 = r12.s64 + 68;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82200064;
	case 1:
		goto loc_8220006C;
	case 2:
		goto loc_82200074;
	case 3:
		goto loc_82200084;
	case 4:
		goto loc_82200084;
	case 5:
		goto loc_82200084;
	case 6:
		goto loc_8220007C;
	case 7:
		goto loc_8220007C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,100(0)
	r17.u64 = PPC_LOAD_U32(100);
	// lwz r17,108(0)
	r17.u64 = PPC_LOAD_U32(108);
	// lwz r17,116(0)
	r17.u64 = PPC_LOAD_U32(116);
	// lwz r17,132(0)
	r17.u64 = PPC_LOAD_U32(132);
	// lwz r17,132(0)
	r17.u64 = PPC_LOAD_U32(132);
	// lwz r17,132(0)
	r17.u64 = PPC_LOAD_U32(132);
	// lwz r17,124(0)
	r17.u64 = PPC_LOAD_U32(124);
	// lwz r17,124(0)
	r17.u64 = PPC_LOAD_U32(124);
loc_82200064:
	// lwz r4,132(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// b 0x82200088
	goto loc_82200088;
loc_8220006C:
	// lwz r4,120(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// b 0x82200088
	goto loc_82200088;
loc_82200074:
	// lwz r4,144(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// b 0x82200088
	goto loc_82200088;
loc_8220007C:
	// lwz r4,140(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// b 0x82200088
	goto loc_82200088;
loc_82200084:
	// lwz r4,148(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 148);
loc_82200088:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-10224
	r31.s64 = r11.s64 + -10224;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x8220009C;
	sub_8268B800(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822000B0;
	sub_8268EE10(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// bl 0x8268b800
	ctx.lr = 0x822000C0;
	sub_8268B800(ctx, base);
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

__attribute__((alias("__imp__sub_822000D8"))) PPC_WEAK_FUNC(sub_822000D8);
PPC_FUNC_IMPL(__imp__sub_822000D8) {
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
	ctx.lr = 0x822000E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822000fc
	if (!cr6.eq) goto loc_822000FC;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8220038c
	goto loc_8220038C;
loc_822000FC:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82200110
	if (!cr6.eq) goto loc_82200110;
	// li r4,25
	ctx.r4.s64 = 25;
	// b 0x8220038c
	goto loc_8220038C;
loc_82200110:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822001ac
	if (!cr6.eq) goto loc_822001AC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200130;
	sub_8268EE10(ctx, base);
	// lwz r10,10292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r30,0
	r30.s64 = 0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r29,r11,23576
	r29.s64 = r11.s64 + 23576;
	// stb r30,417(r10)
	PPC_STORE_U8(ctx.r10.u32 + 417, r30.u8);
	// lwz r9,10080(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10080);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mulli r11,r8,308
	r11.s64 = ctx.r8.s64 * 308;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// lwz r5,224(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	// bl 0x826174d0
	ctx.lr = 0x82200164;
	sub_826174D0(ctx, base);
	// lwz r6,10080(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10080);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r10,r5,308
	ctx.r10.s64 = ctx.r5.s64 * 308;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lwz r9,224(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	// stb r11,10097(r31)
	PPC_STORE_U8(r31.u32 + 10097, r11.u8);
	// stb r11,10275(r31)
	PPC_STORE_U8(r31.u32 + 10275, r11.u8);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// stw r9,10284(r31)
	PPC_STORE_U32(r31.u32 + 10284, ctx.r9.u32);
	// stw r9,10280(r31)
	PPC_STORE_U32(r31.u32 + 10280, ctx.r9.u32);
	// bl 0x82617820
	ctx.lr = 0x8220019C;
	sub_82617820(ctx, base);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822001AC:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822001f8
	if (!cr6.eq) goto loc_822001F8;
	// lwz r11,10292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r30,0
	r30.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// stb r30,417(r11)
	PPC_STORE_U8(r11.u32 + 417, r30.u8);
	// bl 0x8268ee10
	ctx.lr = 0x822001D8;
	sub_8268EE10(ctx, base);
	// lwz r10,10292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r11,1
	r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,10273(r31)
	PPC_STORE_U8(r31.u32 + 10273, r11.u8);
	// stb r11,418(r10)
	PPC_STORE_U8(ctx.r10.u32 + 418, r11.u8);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822001F8:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822002c4
	if (!cr6.eq) goto loc_822002C4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r29,r11,23576
	r29.s64 = r11.s64 + 23576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826177a8
	ctx.lr = 0x82200218;
	sub_826177A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200240
	if (!cr6.eq) goto loc_82200240;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// bl 0x82617750
	ctx.lr = 0x82200230;
	sub_82617750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r4,2
	ctx.r4.s64 = 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200244
	if (cr6.eq) goto loc_82200244;
loc_82200240:
	// li r4,25
	ctx.r4.s64 = 25;
loc_82200244:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200254;
	sub_8268EE10(ctx, base);
	// lwz r11,10292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,417(r11)
	PPC_STORE_U8(r11.u32 + 417, r30.u8);
	// lwz r10,10080(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10080);
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r11,r9,308
	r11.s64 = ctx.r9.s64 * 308;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// lwz r5,224(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 224);
	// bl 0x826174d0
	ctx.lr = 0x82200280;
	sub_826174D0(ctx, base);
	// lwz r7,10080(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 10080);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mulli r10,r6,308
	ctx.r10.s64 = ctx.r6.s64 * 308;
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// lwz r10,224(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 224);
	// stb r11,10097(r31)
	PPC_STORE_U8(r31.u32 + 10097, r11.u8);
	// stb r11,10275(r31)
	PPC_STORE_U8(r31.u32 + 10275, r11.u8);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// stw r10,10284(r31)
	PPC_STORE_U32(r31.u32 + 10284, ctx.r10.u32);
	// stw r10,10280(r31)
	PPC_STORE_U32(r31.u32 + 10280, ctx.r10.u32);
	// bl 0x82617820
	ctx.lr = 0x822002B8;
	sub_82617820(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822002C4:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82200300
	if (!cr6.eq) goto loc_82200300;
	// addi r11,r31,228
	r11.s64 = r31.s64 + 228;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r30,0
	r30.s64 = 0;
loc_822002DC:
	// stw r30,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stb r30,260(r11)
	PPC_STORE_U8(r11.u32 + 260, r30.u8);
	// addi r11,r11,308
	r11.s64 = r11.s64 + 308;
	// bne 0x822002dc
	if (!cr0.eq) goto loc_822002DC;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x8220038c
	goto loc_8220038C;
loc_82200300:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8220033c
	if (!cr6.eq) goto loc_8220033C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200320;
	sub_8268EE10(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r3,r11,23576
	ctx.r3.s64 = r11.s64 + 23576;
	// bl 0x826176b8
	ctx.lr = 0x82200330;
	sub_826176B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8220033C:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x82200368
	if (cr6.eq) goto loc_82200368;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8220037c
	if (!cr6.eq) goto loc_8220037C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200368;
	sub_8268EE10(ctx, base);
loc_82200368:
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8220037C:
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8220039c
	if (!cr6.eq) goto loc_8220039C;
	// li r4,29
	ctx.r4.s64 = 29;
loc_8220038C:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8220039C;
	sub_8268EE10(ctx, base);
loc_8220039C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822003A8"))) PPC_WEAK_FUNC(sub_822003A8);
PPC_FUNC_IMPL(__imp__sub_822003A8) {
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
	ctx.lr = 0x822003B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8220045c
	if (!cr6.eq) goto loc_8220045C;
	// lwz r10,10292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r11,1
	r11.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,416(r10)
	PPC_STORE_U8(ctx.r10.u32 + 416, r30.u8);
	// stb r11,10273(r31)
	PPC_STORE_U8(r31.u32 + 10273, r11.u8);
	// stb r30,10850(r31)
	PPC_STORE_U8(r31.u32 + 10850, r30.u8);
	// stb r11,10851(r31)
	PPC_STORE_U8(r31.u32 + 10851, r11.u8);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x822003F8;
	sub_8268B800(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r3,r9,23576
	ctx.r3.s64 = ctx.r9.s64 + 23576;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826174e8
	ctx.lr = 0x82200414;
	sub_826174E8(ctx, base);
	// lbz r8,10852(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10852);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82200580
	if (cr6.eq) goto loc_82200580;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,110
	ctx.r4.s64 = 110;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r29,r10,1
	r29.s64 = ctx.r10.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82200440;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82200454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,10852(r31)
	PPC_STORE_U8(r31.u32 + 10852, r30.u8);
	// b 0x82200580
	goto loc_82200580;
loc_8220045C:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82200488
	if (!cr6.eq) goto loc_82200488;
	// lbz r11,10275(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bl 0x8268ee10
	ctx.lr = 0x82200484;
	sub_8268EE10(ctx, base);
	// b 0x82200580
	goto loc_82200580;
loc_82200488:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822004c0
	if (!cr6.eq) goto loc_822004C0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,41
	ctx.r4.s64 = 41;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822004A8;
	sub_8268EE10(ctx, base);
	// lwz r11,10292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,132
	ctx.r4.s64 = r11.s64 + 132;
	// addi r3,r10,-15064
	ctx.r3.s64 = ctx.r10.s64 + -15064;
	// bl 0x82130000
	ctx.lr = 0x822004BC;
	sub_82130000(ctx, base);
	// b 0x8220057c
	goto loc_8220057C;
loc_822004C0:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82200570
	if (!cr6.eq) goto loc_82200570;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r29,r11,23576
	r29.s64 = r11.s64 + 23576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826177a8
	ctx.lr = 0x822004E0;
	sub_826177A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200534
	if (!cr6.eq) goto loc_82200534;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// bl 0x82617750
	ctx.lr = 0x822004F8;
	sub_82617750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200534
	if (!cr6.eq) goto loc_82200534;
	// lbz r11,10270(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10270);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// beq cr6,0x82200528
	if (cr6.eq) goto loc_82200528;
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x8268ee10
	ctx.lr = 0x82200524;
	sub_8268EE10(ctx, base);
	// b 0x8220057c
	goto loc_8220057C;
loc_82200528:
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8268ee10
	ctx.lr = 0x82200530;
	sub_8268EE10(ctx, base);
	// b 0x8220057c
	goto loc_8220057C;
loc_82200534:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// bl 0x826177a8
	ctx.lr = 0x82200540;
	sub_826177A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200558
	if (!cr6.eq) goto loc_82200558;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// bl 0x82617750
	ctx.lr = 0x82200558;
	sub_82617750(ctx, base);
loc_82200558:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8220056C;
	sub_8268EE10(ctx, base);
	// b 0x8220057c
	goto loc_8220057C;
loc_82200570:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82200580
	if (!cr6.eq) goto loc_82200580;
loc_8220057C:
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
loc_82200580:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822005c8
	if (!cr6.eq) goto loc_822005C8;
	// addi r11,r31,228
	r11.s64 = r31.s64 + 228;
	// li r10,32
	ctx.r10.s64 = 32;
loc_82200594:
	// stw r30,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stb r30,260(r11)
	PPC_STORE_U8(r11.u32 + 260, r30.u8);
	// addi r11,r11,308
	r11.s64 = r11.s64 + 308;
	// bne 0x82200594
	if (!cr0.eq) goto loc_82200594;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822005C4;
	sub_8268EE10(ctx, base);
	// b 0x82200684
	goto loc_82200684;
loc_822005C8:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82200684
	if (!cr6.eq) goto loc_82200684;
	// lbz r11,10275(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220064c
	if (cr6.eq) goto loc_8220064C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15080
	ctx.r3.s64 = r11.s64 + -15080;
	// bl 0x821fa230
	ctx.lr = 0x822005F0;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-15096
	ctx.r3.s64 = ctx.r10.s64 + -15096;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r8,r9,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// rlwinm r8,r8,0,23,21
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// bl 0x821fa230
	ctx.lr = 0x82200610;
	sub_821FA230(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r7,-15108
	ctx.r3.s64 = ctx.r7.s64 + -15108;
	// bl 0x821fa230
	ctx.lr = 0x82200620;
	sub_821FA230(ctx, base);
	// bl 0x821f87e8
	ctx.lr = 0x82200624;
	sub_821F87E8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8220064c
	if (cr6.eq) goto loc_8220064C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15172
	ctx.r3.s64 = r11.s64 + -15172;
	// bl 0x82130000
	ctx.lr = 0x8220063C;
	sub_82130000(ctx, base);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// rlwinm r9,r9,0,23,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// stw r9,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r9.u32);
loc_8220064C:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200660;
	sub_8268EE10(ctx, base);
	// lbz r11,10270(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10270);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200684
	if (cr6.eq) goto loc_82200684;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10224);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-15816
	ctx.r4.s64 = r11.s64 + -15816;
	// bl 0x8268b770
	ctx.lr = 0x82200680;
	sub_8268B770(ctx, base);
	// stb r30,10270(r31)
	PPC_STORE_U8(r31.u32 + 10270, r30.u8);
loc_82200684:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82200698
	if (!cr6.eq) goto loc_82200698;
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
loc_82200698:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822006A0"))) PPC_WEAK_FUNC(sub_822006A0);
PPC_FUNC_IMPL(__imp__sub_822006A0) {
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
	ctx.lr = 0x822006A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x8220071c
	if (!cr6.eq) goto loc_8220071C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822006DC;
	sub_8268EE10(ctx, base);
	// lwz r10,10292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// li r11,1
	r11.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,416(r10)
	PPC_STORE_U8(ctx.r10.u32 + 416, r30.u8);
	// stb r11,10273(r31)
	PPC_STORE_U8(r31.u32 + 10273, r11.u8);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x822006FC;
	sub_8268B800(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r3,r9,23576
	ctx.r3.s64 = ctx.r9.s64 + 23576;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826174e8
	ctx.lr = 0x82200718;
	sub_826174E8(ctx, base);
	// b 0x82200778
	goto loc_82200778;
loc_8220071C:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82200740
	if (!cr6.eq) goto loc_82200740;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8220073C;
	sub_8268EE10(ctx, base);
	// b 0x82200778
	goto loc_82200778;
loc_82200740:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82200754
	if (!cr6.eq) goto loc_82200754;
	// li r4,41
	ctx.r4.s64 = 41;
	// b 0x82200764
	goto loc_82200764;
loc_82200754:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82200778
	if (!cr6.eq) goto loc_82200778;
	// li r4,5
	ctx.r4.s64 = 5;
loc_82200764:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200774;
	sub_8268EE10(ctx, base);
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
loc_82200778:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x822007c0
	if (!cr6.eq) goto loc_822007C0;
	// addi r11,r31,228
	r11.s64 = r31.s64 + 228;
	// li r10,32
	ctx.r10.s64 = 32;
loc_8220078C:
	// stw r30,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stb r30,260(r11)
	PPC_STORE_U8(r11.u32 + 260, r30.u8);
	// addi r11,r11,308
	r11.s64 = r11.s64 + 308;
	// bne 0x8220078c
	if (!cr0.eq) goto loc_8220078C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822007BC;
	sub_8268EE10(ctx, base);
	// b 0x822007e4
	goto loc_822007E4;
loc_822007C0:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x822007e4
	if (!cr6.eq) goto loc_822007E4;
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// addi r4,r11,-15816
	ctx.r4.s64 = r11.s64 + -15816;
	// bl 0x8268b770
	ctx.lr = 0x822007E4;
	sub_8268B770(ctx, base);
loc_822007E4:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x822007f8
	if (!cr6.eq) goto loc_822007F8;
	// stw r30,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r30.u32);
loc_822007F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82200800"))) PPC_WEAK_FUNC(sub_82200800);
PPC_FUNC_IMPL(__imp__sub_82200800) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,10084(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10084);
	// subfic r10,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r10.s64 = 1 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r9,31
	ctx.r3.u64 = ctx.r9.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82200814"))) PPC_WEAK_FUNC(sub_82200814);
PPC_FUNC_IMPL(__imp__sub_82200814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82200818"))) PPC_WEAK_FUNC(sub_82200818);
PPC_FUNC_IMPL(__imp__sub_82200818) {
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
	ctx.lr = 0x82200820;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821feca8
	ctx.lr = 0x8220082C;
	sub_821FECA8(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,23576
	r30.s64 = r11.s64 + 23576;
	// beq cr6,0x82200864
	if (cr6.eq) goto loc_82200864;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8220084C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// bl 0x826176d0
	ctx.lr = 0x8220085C;
	sub_826176D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82200868
	goto loc_82200868;
loc_82200864:
	// li r11,0
	r11.s64 = 0;
loc_82200868:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// mr r30,r11
	r30.u64 = r11.u64;
	// bl 0x826176b8
	ctx.lr = 0x82200878;
	sub_826176B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82200890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822008a0
	if (cr6.eq) goto loc_822008A0;
	// li r30,0
	r30.s64 = 0;
loc_822008A0:
	// cmpld cr6,r30,r29
	cr6.compare<uint64_t>(r30.u64, r29.u64, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// blt cr6,0x822008b0
	if (cr6.lt) goto loc_822008B0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822008B0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822008B8"))) PPC_WEAK_FUNC(sub_822008B8);
PPC_FUNC_IMPL(__imp__sub_822008B8) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200940
	if (cr6.eq) goto loc_82200940;
	// lbz r10,10096(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82200938
	if (!cr6.eq) goto loc_82200938;
	// stb r4,10096(r31)
	PPC_STORE_U8(r31.u32 + 10096, ctx.r4.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x822008FC;
	sub_8268B800(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,30
	ctx.r4.s64 = 30;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200910;
	sub_8268EE10(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,10851(r31)
	PPC_STORE_U8(r31.u32 + 10851, r11.u8);
	// stb r10,10850(r31)
	PPC_STORE_U8(r31.u32 + 10850, ctx.r10.u8);
	// stb r11,10275(r31)
	PPC_STORE_U8(r31.u32 + 10275, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82200938:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200978
	if (!cr6.eq) goto loc_82200978;
loc_82200940:
	// lbz r11,10096(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200978
	if (cr6.eq) goto loc_82200978;
	// stb r4,10096(r31)
	PPC_STORE_U8(r31.u32 + 10096, ctx.r4.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x82200964;
	sub_8268B800(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82200978:
	// stb r4,10096(r31)
	PPC_STORE_U8(r31.u32 + 10096, ctx.r4.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82200990"))) PPC_WEAK_FUNC(sub_82200990);
PPC_FUNC_IMPL(__imp__sub_82200990) {
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
	ctx.lr = 0x82200998;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r27,404
	r30.s64 = r27.s64 + 404;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r11,408(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 408);
	// lwz r10,404(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82200a1c
	if (cr0.eq) goto loc_82200A1C;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_822009C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822009fc
	if (cr6.eq) goto loc_822009FC;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822009f4
	if (cr6.eq) goto loc_822009F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822009F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822009F4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r28,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r28.u32);
loc_822009FC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x822009c4
	if (cr6.lt) goto loc_822009C4;
loc_82200A1C:
	// lwz r3,392(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 392);
	// bl 0x82130588
	ctx.lr = 0x82200A24;
	sub_82130588(ctx, base);
	// stw r28,392(r27)
	PPC_STORE_U32(r27.u32 + 392, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82200A30"))) PPC_WEAK_FUNC(sub_82200A30);
PPC_FUNC_IMPL(__imp__sub_82200A30) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82200A38;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r10,10096(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10096);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,10264(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 10264, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82200d10
	if (!cr6.eq) goto loc_82200D10;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-10124
	ctx.r10.s64 = r11.s64 + -10124;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200a98
	if (cr6.eq) goto loc_82200A98;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200A8C;
	sub_8268EE10(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200A98:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82200d10
	if (cr6.eq) goto loc_82200D10;
	// lwz r11,10092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82200d10
	if (!cr6.eq) goto loc_82200D10;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200aec
	if (cr6.eq) goto loc_82200AEC;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82200AC0;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200aec
	if (!cr6.eq) goto loc_82200AEC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200AE0;
	sub_8268EE10(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200AEC:
	// lbz r11,10273(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10273);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r27,0
	r27.s64 = 0;
	// stb r8,10850(r31)
	PPC_STORE_U8(r31.u32 + 10850, ctx.r8.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r27,10851(r31)
	PPC_STORE_U8(r31.u32 + 10851, r27.u8);
	// bne cr6,0x82200b68
	if (!cr6.eq) goto loc_82200B68;
	// lbz r10,10270(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10270);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82200b24
	if (!cr6.eq) goto loc_82200B24;
	// lbz r10,10275(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82200b24
	if (cr6.eq) goto loc_82200B24;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_82200B24:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200b68
	if (!cr6.eq) goto loc_82200B68;
	// lbz r11,10270(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10270);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200b68
	if (!cr6.eq) goto loc_82200B68;
	// lbz r11,10275(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200b68
	if (!cr6.eq) goto loc_82200B68;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-15668
	ctx.r4.s64 = ctx.r10.s64 + -15668;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x82200B5C;
	sub_8268B770(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200B68:
	// stb r8,416(r30)
	PPC_STORE_U8(r30.u32 + 416, ctx.r8.u8);
	// addi r11,r31,10296
	r11.s64 = r31.s64 + 10296;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// stw r30,10292(r31)
	PPC_STORE_U32(r31.u32 + 10292, r30.u32);
	// li r10,41
	ctx.r10.s64 = 41;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
loc_82200B84:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82200b9c
	if (cr6.eq) goto loc_82200B9C;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82200b84
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82200B84;
loc_82200B9C:
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r5,3
	ctx.r5.s64 = 3;
	// beq cr6,0x82200bcc
	if (cr6.eq) goto loc_82200BCC;
	// li r4,27
	ctx.r4.s64 = 27;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200BC0;
	sub_8268EE10(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200BCC:
	// stw r8,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, ctx.r8.u32);
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82200BE0;
	sub_8268EE10(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r28,r11,23576
	r28.s64 = r11.s64 + 23576;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82617700
	ctx.lr = 0x82200BF4;
	sub_82617700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200c24
	if (!cr6.eq) goto loc_82200C24;
	// stw r27,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r27.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82200C18;
	sub_8268EE10(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200C24:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82200818
	ctx.lr = 0x82200C30;
	sub_82200818(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82200c5c
	if (!cr6.eq) goto loc_82200C5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x82200C50;
	sub_8268B800(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82200C5C:
	// lwz r3,10292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82200C70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,10292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,132
	ctx.r9.s64 = ctx.r9.s64 + 132;
loc_82200C80:
	// lbzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// blt cr6,0x82200c80
	if (cr6.lt) goto loc_82200C80;
	// lbz r11,10275(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10275);
	// stfs f31,10264(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 10264, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200ce8
	if (cr6.eq) goto loc_82200CE8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15080
	ctx.r3.s64 = r11.s64 + -15080;
	// bl 0x821fa230
	ctx.lr = 0x82200CB4;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r9,-15036
	ctx.r3.s64 = ctx.r9.s64 + -15036;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ori r7,r8,528
	ctx.r7.u64 = ctx.r8.u64 | 528;
	// stw r7,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x82200CD0;
	sub_82130000(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r3,r6,-15096
	ctx.r3.s64 = ctx.r6.s64 + -15096;
	// bl 0x821fa230
	ctx.lr = 0x82200CDC;
	sub_821FA230(ctx, base);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r4,r5,528
	ctx.r4.u64 = ctx.r5.u64 | 528;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
loc_82200CE8:
	// lwz r11,10292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10292);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,396(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 396);
	// lwz r8,392(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 392);
	// bl 0x82617550
	ctx.lr = 0x82200D10;
	sub_82617550(ctx, base);
loc_82200D10:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82200D1C"))) PPC_WEAK_FUNC(sub_82200D1C);
PPC_FUNC_IMPL(__imp__sub_82200D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82200D20"))) PPC_WEAK_FUNC(sub_82200D20);
PPC_FUNC_IMPL(__imp__sub_82200D20) {
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
	ctx.lr = 0x82200D28;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-10164
	ctx.r10.s64 = r11.s64 + -10164;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82200d54
	if (cr6.eq) goto loc_82200D54;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822008b8
	ctx.lr = 0x82200D4C;
	sub_822008B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82200D54:
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r11,r31,10296
	r11.s64 = r31.s64 + 10296;
	// stw r10,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, ctx.r10.u32);
	// li r10,41
	ctx.r10.s64 = 41;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r9,-14960
	ctx.r8.s64 = ctx.r9.s64 + -14960;
	// subf r9,r11,r8
	ctx.r9.s64 = ctx.r8.s64 - r11.s64;
loc_82200D74:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82200d8c
	if (cr6.eq) goto loc_82200D8C;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82200d74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82200D74;
loc_82200D8C:
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,-10224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x82200DA8;
	sub_8268B800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82200DB0;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82200DC4;
	sub_82270170(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r11.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82200DD4;
	sub_824E70E0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82200e84
	if (cr6.eq) goto loc_82200E84;
	// lwz r11,10256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10256);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82200DEC;
	sub_821F8730(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,10100(r31)
	PPC_STORE_U32(r31.u32 + 10100, r29.u32);
	// bl 0x82387b90
	ctx.lr = 0x82200DF8;
	sub_82387B90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8238bd20
	ctx.lr = 0x82200E00;
	sub_8238BD20(ctx, base);
	// bl 0x82388540
	ctx.lr = 0x82200E04;
	sub_82388540(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-6747(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6747, r11.u8);
	// bl 0x82130af8
	ctx.lr = 0x82200E14;
	sub_82130AF8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82200e34
	if (cr6.eq) goto loc_82200E34;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-14972
	ctx.r3.s64 = r11.s64 + -14972;
	// bl 0x82215db8
	ctx.lr = 0x82200E2C;
	sub_82215DB8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82200E34:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r29,r11,23576
	r29.s64 = r11.s64 + 23576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826176e0
	ctx.lr = 0x82200E48;
	sub_826176E0(ctx, base);
	// stb r30,10097(r31)
	PPC_STORE_U8(r31.u32 + 10097, r30.u8);
	// stb r30,10276(r31)
	PPC_STORE_U8(r31.u32 + 10276, r30.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200E64;
	sub_8268EE10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10100);
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826174e8
	ctx.lr = 0x82200E7C;
	sub_826174E8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82200E84:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,20
	ctx.r4.s64 = 20;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82200E98;
	sub_8268EE10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82200EA0"))) PPC_WEAK_FUNC(sub_82200EA0);
PPC_FUNC_IMPL(__imp__sub_82200EA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lhz r11,2(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x822010fc
	if (cr6.gt) goto loc_822010FC;
	// lis r12,-32224
	r12.s64 = -2111832064;
	// addi r12,r12,3804
	r12.s64 = r12.s64 + 3804;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82200F10;
	case 1:
		goto loc_82200F30;
	case 2:
		goto loc_82200F54;
	case 3:
		goto loc_82200F98;
	case 4:
		goto loc_82200FAC;
	case 5:
		goto loc_82200FC0;
	case 6:
		goto loc_82201008;
	case 7:
		goto loc_82200FD0;
	case 8:
		goto loc_82201054;
	case 9:
		goto loc_82200FEC;
	case 10:
		goto loc_82201080;
	case 11:
		goto loc_82201094;
	case 12:
		goto loc_822010D0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,3856(0)
	r17.u64 = PPC_LOAD_U32(3856);
	// lwz r17,3888(0)
	r17.u64 = PPC_LOAD_U32(3888);
	// lwz r17,3924(0)
	r17.u64 = PPC_LOAD_U32(3924);
	// lwz r17,3992(0)
	r17.u64 = PPC_LOAD_U32(3992);
	// lwz r17,4012(0)
	r17.u64 = PPC_LOAD_U32(4012);
	// lwz r17,4032(0)
	r17.u64 = PPC_LOAD_U32(4032);
	// lwz r17,4104(0)
	r17.u64 = PPC_LOAD_U32(4104);
	// lwz r17,4048(0)
	r17.u64 = PPC_LOAD_U32(4048);
	// lwz r17,4180(0)
	r17.u64 = PPC_LOAD_U32(4180);
	// lwz r17,4076(0)
	r17.u64 = PPC_LOAD_U32(4076);
	// lwz r17,4224(0)
	r17.u64 = PPC_LOAD_U32(4224);
	// lwz r17,4244(0)
	r17.u64 = PPC_LOAD_U32(4244);
	// lwz r17,4304(0)
	r17.u64 = PPC_LOAD_U32(4304);
loc_82200F10:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,2832(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2832);
	// stw r9,10092(r11)
	PPC_STORE_U32(r11.u32 + 10092, ctx.r9.u32);
	// lwz r3,2832(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2832);
	// bl 0x822008b8
	ctx.lr = 0x82200F2C;
	sub_822008B8(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200F30:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82200F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200F54:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2832(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// bl 0x8268c9f0
	ctx.lr = 0x82200F64;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-14960
	ctx.r4.s64 = ctx.r8.s64 + -14960;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82200F94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200F98:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// bl 0x822008b8
	ctx.lr = 0x82200FA8;
	sub_822008B8(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200FAC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// stb r10,10274(r11)
	PPC_STORE_U8(r11.u32 + 10274, ctx.r10.u8);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200FC0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
loc_82200FC8:
	// bl 0x821ffc40
	ctx.lr = 0x82200FCC;
	sub_821FFC40(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200FD0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10275(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10275);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82200fc8
	if (cr6.eq) goto loc_82200FC8;
	// bl 0x821ffd00
	ctx.lr = 0x82200FE8;
	sub_821FFD00(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82200FEC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r3,r10,23576
	ctx.r3.s64 = ctx.r10.s64 + 23576;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r4,10100(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10100);
	// bl 0x826176e0
	ctx.lr = 0x82201004;
	sub_826176E0(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82201008:
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r10,2832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// lwz r11,10256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8220102c
	if (cr6.eq) goto loc_8220102C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82201024;
	sub_824E70E0(ctx, base);
	// lwz r10,2832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// b 0x82201030
	goto loc_82201030;
loc_8220102C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82201030:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822010fc
	if (!cr6.eq) goto loc_822010FC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,20
	ctx.r4.s64 = 20;
	// addi r3,r10,40
	ctx.r3.s64 = ctx.r10.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x82201050;
	sub_8268EE10(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82201054:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10096(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822010fc
	if (cr6.eq) goto loc_822010FC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,37
	ctx.r4.s64 = 37;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8220107C;
	sub_8268EE10(ctx, base);
	// b 0x822010fc
	goto loc_822010FC;
loc_82201080:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// stb r10,10290(r11)
	PPC_STORE_U8(r11.u32 + 10290, ctx.r10.u8);
	// b 0x822010fc
	goto loc_822010FC;
loc_82201094:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268c9f0
	ctx.lr = 0x8220109C;
	sub_8268C9F0(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x823de058
	ctx.lr = 0x822010A4;
	sub_823DE058(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,-10188(r9)
	PPC_STORE_U8(ctx.r9.u32 + -10188, r11.u8);
	// stfs f13,-10192(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + -10192, temp.u32);
	// stfd f0,-10200(r7)
	PPC_STORE_U64(ctx.r7.u32 + -10200, f0.u64);
	// b 0x822010fc
	goto loc_822010FC;
loc_822010D0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,-17600(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + -17600);
	// stb r11,-10188(r8)
	PPC_STORE_U8(ctx.r8.u32 + -10188, r11.u8);
	// stfs f0,-10192(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -10192, temp.u32);
	// stfd f13,-10200(r6)
	PPC_STORE_U64(ctx.r6.u32 + -10200, ctx.f13.u64);
loc_822010FC:
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

__attribute__((alias("__imp__sub_82201114"))) PPC_WEAK_FUNC(sub_82201114);
PPC_FUNC_IMPL(__imp__sub_82201114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

