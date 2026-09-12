#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82449FE0"))) PPC_WEAK_FUNC(sub_82449FE0);
PPC_FUNC_IMPL(__imp__sub_82449FE0) {
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
	// bl 0x82449ee0
	ctx.lr = 0x82449FF8;
	sub_82449EE0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a014
	if (cr0.lt) goto loc_8244A014;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82447eb8
	ctx.lr = 0x8244A008;
	sub_82447EB8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a014
	if (cr0.lt) goto loc_8244A014;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244A014:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8244A028"))) PPC_WEAK_FUNC(sub_8244A028);
PPC_FUNC_IMPL(__imp__sub_8244A028) {
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
	// bl 0x82449f40
	ctx.lr = 0x8244A040;
	sub_82449F40(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a05c
	if (cr0.lt) goto loc_8244A05C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82447eb8
	ctx.lr = 0x8244A050;
	sub_82447EB8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a05c
	if (cr0.lt) goto loc_8244A05C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244A05C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8244A070"))) PPC_WEAK_FUNC(sub_8244A070);
PPC_FUNC_IMPL(__imp__sub_8244A070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// subf r8,r9,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// li r9,16
	ctx.r9.s64 = 16;
loc_8244A090:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f13,-8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8244a090
	if (!cr0.eq) goto loc_8244A090;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82449f88
	ctx.lr = 0x8244A0D4;
	sub_82449F88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a0e0
	if (cr0.lt) goto loc_8244A0E0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244A0E0:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244A0F0"))) PPC_WEAK_FUNC(sub_8244A0F0);
PPC_FUNC_IMPL(__imp__sub_8244A0F0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// subf r8,r9,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r9.s64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// li r9,16
	ctx.r9.s64 = 16;
loc_8244A120:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f13,-8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8244a120
	if (!cr0.eq) goto loc_8244A120;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824487a8
	ctx.lr = 0x8244A170;
	sub_824487A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a188
	if (cr0.lt) goto loc_8244A188;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82449938
	ctx.lr = 0x8244A188;
	sub_82449938(ctx, base);
loc_8244A188:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8244a194
	if (cr6.lt) goto loc_8244A194;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244A194:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_8244A1AC"))) PPC_WEAK_FUNC(sub_8244A1AC);
PPC_FUNC_IMPL(__imp__sub_8244A1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A1B0"))) PPC_WEAK_FUNC(sub_8244A1B0);
PPC_FUNC_IMPL(__imp__sub_8244A1B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,12256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244a1c4
	if (cr6.eq) goto loc_8244A1C4;
	// b 0x82449fe0
	sub_82449FE0(ctx, base);
	return;
loc_8244A1C4:
	// b 0x82449ee0
	sub_82449EE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A1C8"))) PPC_WEAK_FUNC(sub_8244A1C8);
PPC_FUNC_IMPL(__imp__sub_8244A1C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,12256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244a1dc
	if (cr6.eq) goto loc_8244A1DC;
	// b 0x8244a028
	sub_8244A028(ctx, base);
	return;
loc_8244A1DC:
	// b 0x82449f40
	sub_82449F40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A1E0"))) PPC_WEAK_FUNC(sub_8244A1E0);
PPC_FUNC_IMPL(__imp__sub_8244A1E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,12256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244a1f4
	if (cr6.eq) goto loc_8244A1F4;
	// b 0x8244a070
	sub_8244A070(ctx, base);
	return;
loc_8244A1F4:
	// b 0x82449f88
	sub_82449F88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A1F8"))) PPC_WEAK_FUNC(sub_8244A1F8);
PPC_FUNC_IMPL(__imp__sub_8244A1F8) {
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
	ctx.lr = 0x8244A200;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,12256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244a228
	if (cr6.eq) goto loc_8244A228;
	// bl 0x8244a0f0
	ctx.lr = 0x8244A224;
	sub_8244A0F0(ctx, base);
	// b 0x8244a250
	goto loc_8244A250;
loc_8244A228:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824487a8
	ctx.lr = 0x8244A238;
	sub_824487A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a250
	if (cr0.lt) goto loc_8244A250;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82449938
	ctx.lr = 0x8244A250;
	sub_82449938(ctx, base);
loc_8244A250:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244A258"))) PPC_WEAK_FUNC(sub_8244A258);
PPC_FUNC_IMPL(__imp__sub_8244A258) {
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
	ctx.lr = 0x8244A260;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8244A27C;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8202
	r11.s64 = 537526272;
	// ori r11,r11,12800
	r11.u64 = r11.u64 | 12800;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x8244a2c8
	if (cr6.lt) goto loc_8244A2C8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r11,-23056
	ctx.r3.s64 = r11.s64 + -23056;
	// bl 0x827bd894
	ctx.lr = 0x8244A29C;
	__imp__XexGetModuleHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a2c8
	if (cr0.lt) goto loc_8244A2C8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x827bd884
	ctx.lr = 0x8244A2B4;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244a2c8
	if (!cr0.lt) goto loc_8244A2C8;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// b 0x8244a2cc
	goto loc_8244A2CC;
loc_8244A2C8:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244A2CC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8244a2f4
	if (cr6.eq) goto loc_8244A2F4;
	// lis r6,8219
	ctx.r6.s64 = 538640384;
	// ori r6,r6,21248
	ctx.r6.u64 = ctx.r6.u64 | 21248;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244A2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8244a2f8
	goto loc_8244A2F8;
loc_8244A2F4:
	// bl 0x827bd0f4
	ctx.lr = 0x8244A2F8;
	__imp__NetDll_WSAStartup(ctx, base);
loc_8244A2F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244A300"))) PPC_WEAK_FUNC(sub_8244A300);
PPC_FUNC_IMPL(__imp__sub_8244A300) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244a258
	sub_8244A258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A310"))) PPC_WEAK_FUNC(sub_8244A310);
PPC_FUNC_IMPL(__imp__sub_8244A310) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd104
	__imp__NetDll_WSACleanup(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A318"))) PPC_WEAK_FUNC(sub_8244A318);
PPC_FUNC_IMPL(__imp__sub_8244A318) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd114
	__imp__NetDll_socket(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A32C"))) PPC_WEAK_FUNC(sub_8244A32C);
PPC_FUNC_IMPL(__imp__sub_8244A32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A330"))) PPC_WEAK_FUNC(sub_8244A330);
PPC_FUNC_IMPL(__imp__sub_8244A330) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd124
	__imp__NetDll_closesocket(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A33C"))) PPC_WEAK_FUNC(sub_8244A33C);
PPC_FUNC_IMPL(__imp__sub_8244A33C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A340"))) PPC_WEAK_FUNC(sub_8244A340);
PPC_FUNC_IMPL(__imp__sub_8244A340) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd134
	__imp__NetDll_ioctlsocket(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A354"))) PPC_WEAK_FUNC(sub_8244A354);
PPC_FUNC_IMPL(__imp__sub_8244A354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A358"))) PPC_WEAK_FUNC(sub_8244A358);
PPC_FUNC_IMPL(__imp__sub_8244A358) {
	PPC_FUNC_PROLOGUE();
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd144
	__imp__NetDll_setsockopt(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A374"))) PPC_WEAK_FUNC(sub_8244A374);
PPC_FUNC_IMPL(__imp__sub_8244A374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A378"))) PPC_WEAK_FUNC(sub_8244A378);
PPC_FUNC_IMPL(__imp__sub_8244A378) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd154
	__imp__NetDll_getsockname(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A38C"))) PPC_WEAK_FUNC(sub_8244A38C);
PPC_FUNC_IMPL(__imp__sub_8244A38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A390"))) PPC_WEAK_FUNC(sub_8244A390);
PPC_FUNC_IMPL(__imp__sub_8244A390) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd164
	__imp__NetDll_bind(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A3A4"))) PPC_WEAK_FUNC(sub_8244A3A4);
PPC_FUNC_IMPL(__imp__sub_8244A3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A3A8"))) PPC_WEAK_FUNC(sub_8244A3A8);
PPC_FUNC_IMPL(__imp__sub_8244A3A8) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd174
	__imp__NetDll_connect(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A3BC"))) PPC_WEAK_FUNC(sub_8244A3BC);
PPC_FUNC_IMPL(__imp__sub_8244A3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A3C0"))) PPC_WEAK_FUNC(sub_8244A3C0);
PPC_FUNC_IMPL(__imp__sub_8244A3C0) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd184
	__imp__NetDll_listen(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A3D0"))) PPC_WEAK_FUNC(sub_8244A3D0);
PPC_FUNC_IMPL(__imp__sub_8244A3D0) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd194
	__imp__NetDll_accept(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A3E4"))) PPC_WEAK_FUNC(sub_8244A3E4);
PPC_FUNC_IMPL(__imp__sub_8244A3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A3E8"))) PPC_WEAK_FUNC(sub_8244A3E8);
PPC_FUNC_IMPL(__imp__sub_8244A3E8) {
	PPC_FUNC_PROLOGUE();
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd1a4
	__imp__NetDll_select(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A404"))) PPC_WEAK_FUNC(sub_8244A404);
PPC_FUNC_IMPL(__imp__sub_8244A404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A408"))) PPC_WEAK_FUNC(sub_8244A408);
PPC_FUNC_IMPL(__imp__sub_8244A408) {
	PPC_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd1b4
	__imp__NetDll_recv(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A420"))) PPC_WEAK_FUNC(sub_8244A420);
PPC_FUNC_IMPL(__imp__sub_8244A420) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd1c4
	__imp__NetDll_recvfrom(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A440"))) PPC_WEAK_FUNC(sub_8244A440);
PPC_FUNC_IMPL(__imp__sub_8244A440) {
	PPC_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd1d4
	__imp__NetDll_send(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A458"))) PPC_WEAK_FUNC(sub_8244A458);
PPC_FUNC_IMPL(__imp__sub_8244A458) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd1e4
	__imp__NetDll_sendto(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A478"))) PPC_WEAK_FUNC(sub_8244A478);
PPC_FUNC_IMPL(__imp__sub_8244A478) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd1f4
	__imp__NetDll_inet_addr(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A47C"))) PPC_WEAK_FUNC(sub_8244A47C);
PPC_FUNC_IMPL(__imp__sub_8244A47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A480"))) PPC_WEAK_FUNC(sub_8244A480);
PPC_FUNC_IMPL(__imp__sub_8244A480) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd204
	__imp__NetDll_WSAGetLastError(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A484"))) PPC_WEAK_FUNC(sub_8244A484);
PPC_FUNC_IMPL(__imp__sub_8244A484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A488"))) PPC_WEAK_FUNC(sub_8244A488);
PPC_FUNC_IMPL(__imp__sub_8244A488) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd214
	__imp__NetDll___WSAFDIsSet(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A48C"))) PPC_WEAK_FUNC(sub_8244A48C);
PPC_FUNC_IMPL(__imp__sub_8244A48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A490"))) PPC_WEAK_FUNC(sub_8244A490);
PPC_FUNC_IMPL(__imp__sub_8244A490) {
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
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8244A4B8;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8202
	r11.s64 = 537526272;
	// ori r11,r11,12800
	r11.u64 = r11.u64 | 12800;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x8244a504
	if (cr6.lt) goto loc_8244A504;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r11,-23056
	ctx.r3.s64 = r11.s64 + -23056;
	// bl 0x827bd894
	ctx.lr = 0x8244A4D8;
	__imp__XexGetModuleHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244a504
	if (cr0.lt) goto loc_8244A504;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,80
	ctx.r4.s64 = 80;
	// bl 0x827bd884
	ctx.lr = 0x8244A4F0;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244a504
	if (!cr0.lt) goto loc_8244A504;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// b 0x8244a508
	goto loc_8244A508;
loc_8244A504:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244A508:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8244a52c
	if (cr6.eq) goto loc_8244A52C;
	// lis r5,8219
	ctx.r5.s64 = 538640384;
	// ori r5,r5,21248
	ctx.r5.u64 = ctx.r5.u64 | 21248;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244A528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8244a530
	goto loc_8244A530;
loc_8244A52C:
	// bl 0x827bd224
	ctx.lr = 0x8244A530;
	__imp__NetDll_XNetStartup(ctx, base);
loc_8244A530:
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

__attribute__((alias("__imp__sub_8244A548"))) PPC_WEAK_FUNC(sub_8244A548);
PPC_FUNC_IMPL(__imp__sub_8244A548) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244a490
	sub_8244A490(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A554"))) PPC_WEAK_FUNC(sub_8244A554);
PPC_FUNC_IMPL(__imp__sub_8244A554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A558"))) PPC_WEAK_FUNC(sub_8244A558);
PPC_FUNC_IMPL(__imp__sub_8244A558) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd234
	__imp__NetDll_XNetCleanup(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A560"))) PPC_WEAK_FUNC(sub_8244A560);
PPC_FUNC_IMPL(__imp__sub_8244A560) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd244
	__imp__NetDll_XNetRegisterKey(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A570"))) PPC_WEAK_FUNC(sub_8244A570);
PPC_FUNC_IMPL(__imp__sub_8244A570) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd254
	__imp__NetDll_XNetUnregisterKey(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A57C"))) PPC_WEAK_FUNC(sub_8244A57C);
PPC_FUNC_IMPL(__imp__sub_8244A57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A580"))) PPC_WEAK_FUNC(sub_8244A580);
PPC_FUNC_IMPL(__imp__sub_8244A580) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd264
	__imp__NetDll_XNetXnAddrToInAddr(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A594"))) PPC_WEAK_FUNC(sub_8244A594);
PPC_FUNC_IMPL(__imp__sub_8244A594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A598"))) PPC_WEAK_FUNC(sub_8244A598);
PPC_FUNC_IMPL(__imp__sub_8244A598) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd274
	__imp__NetDll_XNetServerToInAddr(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A5AC"))) PPC_WEAK_FUNC(sub_8244A5AC);
PPC_FUNC_IMPL(__imp__sub_8244A5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A5B0"))) PPC_WEAK_FUNC(sub_8244A5B0);
PPC_FUNC_IMPL(__imp__sub_8244A5B0) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd284
	__imp__NetDll_XNetUnregisterInAddr(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A5BC"))) PPC_WEAK_FUNC(sub_8244A5BC);
PPC_FUNC_IMPL(__imp__sub_8244A5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A5C0"))) PPC_WEAK_FUNC(sub_8244A5C0);
PPC_FUNC_IMPL(__imp__sub_8244A5C0) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd294
	__imp__NetDll_XNetConnect(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A5CC"))) PPC_WEAK_FUNC(sub_8244A5CC);
PPC_FUNC_IMPL(__imp__sub_8244A5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A5D0"))) PPC_WEAK_FUNC(sub_8244A5D0);
PPC_FUNC_IMPL(__imp__sub_8244A5D0) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd2a4
	__imp__NetDll_XNetGetConnectStatus(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A5DC"))) PPC_WEAK_FUNC(sub_8244A5DC);
PPC_FUNC_IMPL(__imp__sub_8244A5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A5E0"))) PPC_WEAK_FUNC(sub_8244A5E0);
PPC_FUNC_IMPL(__imp__sub_8244A5E0) {
	PPC_FUNC_PROLOGUE();
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd2b4
	__imp__NetDll_XNetQosListen(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A5FC"))) PPC_WEAK_FUNC(sub_8244A5FC);
PPC_FUNC_IMPL(__imp__sub_8244A5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A600"))) PPC_WEAK_FUNC(sub_8244A600);
PPC_FUNC_IMPL(__imp__sub_8244A600) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8244A608;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r31,268(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r30,260(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r29,252(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lwz r28,244(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// bl 0x827bd2c4
	ctx.lr = 0x8244A658;
	__imp__NetDll_XNetQosLookup(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244A660"))) PPC_WEAK_FUNC(sub_8244A660);
PPC_FUNC_IMPL(__imp__sub_8244A660) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd2d4
	__imp__NetDll_XNetQosRelease(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A66C"))) PPC_WEAK_FUNC(sub_8244A66C);
PPC_FUNC_IMPL(__imp__sub_8244A66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A670"))) PPC_WEAK_FUNC(sub_8244A670);
PPC_FUNC_IMPL(__imp__sub_8244A670) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd2e4
	__imp__NetDll_XNetGetTitleXnAddr(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A67C"))) PPC_WEAK_FUNC(sub_8244A67C);
PPC_FUNC_IMPL(__imp__sub_8244A67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A680"))) PPC_WEAK_FUNC(sub_8244A680);
PPC_FUNC_IMPL(__imp__sub_8244A680) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827bd2f4
	__imp__NetDll_XNetGetEthernetLinkStatus(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244A688"))) PPC_WEAK_FUNC(sub_8244A688);
PPC_FUNC_IMPL(__imp__sub_8244A688) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8244A690;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// bge cr6,0x8244a6b4
	if (!cr6.lt) goto loc_8244A6B4;
	// li r3,122
	ctx.r3.s64 = 122;
	// b 0x8244a74c
	goto loc_8244A74C;
loc_8244A6B4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8244a6c4
	if (!cr6.eq) goto loc_8244A6C4;
	// li r3,87
	ctx.r3.s64 = 87;
	// b 0x8244a74c
	goto loc_8244A74C;
loc_8244A6C4:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x827bd314
	ctx.lr = 0x8244A6D8;
	__imp__XamUserGetSigninState(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8244a6e8
	if (cr6.eq) goto loc_8244A6E8;
	// li r3,1245
	ctx.r3.s64 = 1245;
	// b 0x8244a74c
	goto loc_8244A74C;
loc_8244A6E8:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x827bd304
	ctx.lr = 0x8244A6F4;
	__imp__XNetLogonGetTitleID(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,32777
	ctx.r4.u64 = ctx.r4.u64 | 32777;
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x827bd0b4
	ctx.lr = 0x8244A71C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244a72c
	if (!cr0.lt) goto loc_8244A72C;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x8244a74c
	goto loc_8244A74C;
loc_8244A72C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8244a748
	if (!cr6.eq) goto loc_8244A748;
	// bl 0x82135d90
	ctx.lr = 0x8244A738;
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
	// b 0x8244a74c
	goto loc_8244A74C;
loc_8244A748:
	// li r3,997
	ctx.r3.s64 = 997;
loc_8244A74C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244A754"))) PPC_WEAK_FUNC(sub_8244A754);
PPC_FUNC_IMPL(__imp__sub_8244A754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A758"))) PPC_WEAK_FUNC(sub_8244A758);
PPC_FUNC_IMPL(__imp__sub_8244A758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8244A760;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// bl 0x824581c8
	ctx.lr = 0x8244A784;
	sub_824581C8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244a7b4
	if (!cr0.eq) goto loc_8244A7B4;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd324
	ctx.lr = 0x8244A7B4;
	__imp__XamUserReadProfileSettings(ctx, base);
loc_8244A7B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8244A7BC"))) PPC_WEAK_FUNC(sub_8244A7BC);
PPC_FUNC_IMPL(__imp__sub_8244A7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A7C0"))) PPC_WEAK_FUNC(sub_8244A7C0);
PPC_FUNC_IMPL(__imp__sub_8244A7C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8244A7C8;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// bl 0x824581c8
	ctx.lr = 0x8244A7F0;
	sub_824581C8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244a824
	if (!cr0.eq) goto loc_8244A824;
	// lwz r11,244(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd324
	ctx.lr = 0x8244A824;
	__imp__XamUserReadProfileSettings(ctx, base);
loc_8244A824:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8244A82C"))) PPC_WEAK_FUNC(sub_8244A82C);
PPC_FUNC_IMPL(__imp__sub_8244A82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244A830"))) PPC_WEAK_FUNC(sub_8244A830);
PPC_FUNC_IMPL(__imp__sub_8244A830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// extsw r8,r4
	ctx.r8.s64 = ctx.r4.s32;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// std r8,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r8.u64);
	// lwz r3,512(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244A860"))) PPC_WEAK_FUNC(sub_8244A860);
PPC_FUNC_IMPL(__imp__sub_8244A860) {
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
	ctx.lr = 0x8244A868;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// stw r3,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r3.u32);
	// stw r4,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r4.u32);
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// stw r5,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r5.u32);
	// li r3,518
	ctx.r3.s64 = 518;
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// bl 0x8244bb00
	ctx.lr = 0x8244A89C;
	sub_8244BB00(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244a98c
	if (cr0.lt) goto loc_8244A98C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244A8C4;
	sub_8244BB88(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244a98c
	if (cr0.lt) goto loc_8244A98C;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244A8DC;
	__imp__XamAlloc(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244a98c
	if (cr0.lt) goto loc_8244A98C;
	// addi r5,r1,148
	ctx.r5.s64 = ctx.r1.s64 + 148;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r11,r1,140
	r11.s64 = ctx.r1.s64 + 140;
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// li r3,518
	ctx.r3.s64 = 518;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x8244bc28
	ctx.lr = 0x8244A928;
	sub_8244BC28(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244a98c
	if (cr0.lt) goto loc_8244A98C;
	// addi r4,r1,740
	ctx.r4.s64 = ctx.r1.s64 + 740;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244A93C;
	sub_8244A830(ctx, base);
	// addi r4,r1,748
	ctx.r4.s64 = ctx.r1.s64 + 748;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244A948;
	sub_8244A830(ctx, base);
	// addi r4,r1,756
	ctx.r4.s64 = ctx.r1.s64 + 756;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244A954;
	sub_8244A830(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244A960;
	sub_8244A830(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244A96C;
	sub_8244A830(ctx, base);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lwz r5,140(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// ori r4,r4,32800
	ctx.r4.u64 = ctx.r4.u64 | 32800;
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x827bd0d4
	ctx.lr = 0x8244A984;
	__imp__XMsgInProcessCall(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8244a9ac
	if (!cr0.lt) goto loc_8244A9AC;
loc_8244A98C:
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244a99c
	if (cr6.eq) goto loc_8244A99C;
	// bl 0x827bd344
	ctx.lr = 0x8244A99C;
	__imp__XamFree(ctx, base);
loc_8244A99C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82135d38
	ctx.lr = 0x8244A9A4;
	sub_82135D38(ctx, base);
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8244a9b4
	goto loc_8244A9B4;
loc_8244A9AC:
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x827bd344
	ctx.lr = 0x8244A9B4;
	__imp__XamFree(ctx, base);
loc_8244A9B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244A9C0"))) PPC_WEAK_FUNC(sub_8244A9C0);
PPC_FUNC_IMPL(__imp__sub_8244A9C0) {
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
	ctx.lr = 0x8244A9C8;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// stw r3,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r3.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// li r3,1414
	ctx.r3.s64 = 1414;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// bl 0x8244bb00
	ctx.lr = 0x8244A9F0;
	sub_8244BB00(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244aabc
	if (cr0.lt) goto loc_8244AABC;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AA18;
	sub_8244BB88(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244aabc
	if (cr0.lt) goto loc_8244AABC;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244AA30;
	__imp__XamAlloc(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244aabc
	if (cr0.lt) goto loc_8244AABC;
	// addi r5,r1,148
	ctx.r5.s64 = ctx.r1.s64 + 148;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r11,r1,140
	r11.s64 = ctx.r1.s64 + 140;
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// li r3,1414
	ctx.r3.s64 = 1414;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x8244bc28
	ctx.lr = 0x8244AA7C;
	sub_8244BC28(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244aabc
	if (cr0.lt) goto loc_8244AABC;
	// addi r4,r1,740
	ctx.r4.s64 = ctx.r1.s64 + 740;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244AA90;
	sub_8244A830(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244a830
	ctx.lr = 0x8244AA9C;
	sub_8244A830(ctx, base);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lwz r5,140(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// ori r4,r4,32803
	ctx.r4.u64 = ctx.r4.u64 | 32803;
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x827bd0d4
	ctx.lr = 0x8244AAB4;
	__imp__XMsgInProcessCall(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8244aadc
	if (!cr0.lt) goto loc_8244AADC;
loc_8244AABC:
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244aacc
	if (cr6.eq) goto loc_8244AACC;
	// bl 0x827bd344
	ctx.lr = 0x8244AACC;
	__imp__XamFree(ctx, base);
loc_8244AACC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82135d38
	ctx.lr = 0x8244AAD4;
	sub_82135D38(ctx, base);
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8244aae4
	goto loc_8244AAE4;
loc_8244AADC:
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x827bd344
	ctx.lr = 0x8244AAE4;
	__imp__XamFree(ctx, base);
loc_8244AAE4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244AAF0"))) PPC_WEAK_FUNC(sub_8244AAF0);
PPC_FUNC_IMPL(__imp__sub_8244AAF0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8244AAF8;
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r3,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r3.u32);
	// stw r4,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r4.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r31,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r31.u32);
	// li r3,3329
	ctx.r3.s64 = 3329;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244AB2C;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AB54;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3586
	ctx.r3.s64 = 3586;
	// addi r30,r11,1500
	r30.s64 = r11.s64 + 1500;
	// bl 0x8244bb00
	ctx.lr = 0x8244AB70;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AB98;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,1408
	ctx.r3.s64 = 1408;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244ABB4;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244ABDC;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,1411
	ctx.r3.s64 = 1411;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244ABF8;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8244bb88
	ctx.lr = 0x8244AC20;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244AC38;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// lwz r11,844(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 844);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// beq cr6,0x8244ac64
	if (cr6.eq) goto loc_8244AC64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823de3a8
	ctx.lr = 0x8244AC58;
	sub_823DE3A8(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// b 0x8244ac74
	goto loc_8244AC74;
loc_8244AC64:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r28,r11,-23048
	r28.s64 = r11.s64 + -23048;
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
loc_8244AC74:
	// addi r11,r1,140
	r11.s64 = ctx.r1.s64 + 140;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r26,r1,144
	r26.s64 = ctx.r1.s64 + 144;
	// lwz r7,136(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r25,r1,156
	r25.s64 = ctx.r1.s64 + 156;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// li r3,1411
	ctx.r3.s64 = 1411;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// bl 0x8244bc28
	ctx.lr = 0x8244ACBC;
	sub_8244BC28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// addi r4,r1,836
	ctx.r4.s64 = ctx.r1.s64 + 836;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244ACD0;
	sub_8244A830(ctx, base);
	// addi r4,r1,844
	ctx.r4.s64 = ctx.r1.s64 + 844;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244ACDC;
	sub_8244A830(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244ACE8;
	sub_8244A830(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244ACF4;
	sub_8244A830(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244AD00;
	sub_8244A830(ctx, base);
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244AD0C;
	sub_8244A830(ctx, base);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244AD18;
	sub_8244A830(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lwz r9,156(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244bd08
	ctx.lr = 0x8244AD3C;
	sub_8244BD08(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ad98
	if (cr0.lt) goto loc_8244AD98;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,40
	ctx.r7.s64 = 40;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r31.u64);
	// std r31,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r31.u64);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// rlwimi r4,r8,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// bl 0x827bd0b4
	ctx.lr = 0x8244AD90;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244adc4
	if (!cr0.lt) goto loc_8244ADC4;
loc_8244AD98:
	// li r31,1627
	r31.s64 = 1627;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244adac
	if (cr6.eq) goto loc_8244ADAC;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// b 0x8244adb0
	goto loc_8244ADB0;
loc_8244ADAC:
	// bl 0x82135d40
	ctx.lr = 0x8244ADB0;
	sub_82135D40(ctx, base);
loc_8244ADB0:
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244ade4
	if (cr6.eq) goto loc_8244ADE4;
	// bl 0x827bd344
	ctx.lr = 0x8244ADC0;
	__imp__XamFree(ctx, base);
	// b 0x8244ade4
	goto loc_8244ADE4;
loc_8244ADC4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244add4
	if (cr6.eq) goto loc_8244ADD4;
	// li r31,997
	r31.s64 = 997;
	// b 0x8244ade4
	goto loc_8244ADE4;
loc_8244ADD4:
	// bl 0x82135d90
	ctx.lr = 0x8244ADD8;
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
loc_8244ADE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8244ADF0"))) PPC_WEAK_FUNC(sub_8244ADF0);
PPC_FUNC_IMPL(__imp__sub_8244ADF0) {
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
	ctx.lr = 0x8244ADF8;
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r3,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r3.u32);
	// stw r5,852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 852, ctx.r5.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r31.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// li r3,3329
	ctx.r3.s64 = 3329;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244AE34;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AE5C;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3073
	ctx.r3.s64 = 3073;
	// addi r30,r11,448
	r30.s64 = r11.s64 + 448;
	// bl 0x8244bb00
	ctx.lr = 0x8244AE78;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AEA0;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3585
	ctx.r3.s64 = 3585;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244AEBC;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244AEE4;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3601
	ctx.r3.s64 = 3601;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244AF00;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8244bb88
	ctx.lr = 0x8244AF28;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244AF40;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823de3a8
	ctx.lr = 0x8244AF50;
	sub_823DE3A8(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// addi r3,r1,140
	ctx.r3.s64 = ctx.r1.s64 + 140;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r24,r1,144
	r24.s64 = ctx.r1.s64 + 144;
	// lwz r7,136(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r23,r1,152
	r23.s64 = ctx.r1.s64 + 152;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r11.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r27,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r27.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r3,3601
	ctx.r3.s64 = 3601;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r24.u32);
	// stw r23,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r23.u32);
	// bl 0x8244bc28
	ctx.lr = 0x8244AFA0;
	sub_8244BC28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// addi r4,r1,836
	ctx.r4.s64 = ctx.r1.s64 + 836;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFB4;
	sub_8244A830(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFC0;
	sub_8244A830(ctx, base);
	// addi r4,r1,852
	ctx.r4.s64 = ctx.r1.s64 + 852;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFCC;
	sub_8244A830(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFD8;
	sub_8244A830(ctx, base);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFE4;
	sub_8244A830(ctx, base);
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244AFF0;
	sub_8244A830(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lwz r9,152(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244bd08
	ctx.lr = 0x8244B014;
	sub_8244BD08(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b070
	if (cr0.lt) goto loc_8244B070;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,40
	ctx.r7.s64 = 40;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r31.u64);
	// std r31,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r31.u64);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// rlwimi r4,r8,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// bl 0x827bd0b4
	ctx.lr = 0x8244B068;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244b09c
	if (!cr0.lt) goto loc_8244B09C;
loc_8244B070:
	// li r31,1627
	r31.s64 = 1627;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b084
	if (cr6.eq) goto loc_8244B084;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// b 0x8244b088
	goto loc_8244B088;
loc_8244B084:
	// bl 0x82135d40
	ctx.lr = 0x8244B088;
	sub_82135D40(ctx, base);
loc_8244B088:
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244b0bc
	if (cr6.eq) goto loc_8244B0BC;
	// bl 0x827bd344
	ctx.lr = 0x8244B098;
	__imp__XamFree(ctx, base);
	// b 0x8244b0bc
	goto loc_8244B0BC;
loc_8244B09C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b0ac
	if (cr6.eq) goto loc_8244B0AC;
	// li r31,997
	r31.s64 = 997;
	// b 0x8244b0bc
	goto loc_8244B0BC;
loc_8244B0AC:
	// bl 0x82135d90
	ctx.lr = 0x8244B0B0;
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
loc_8244B0BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8244B0C8"))) PPC_WEAK_FUNC(sub_8244B0C8);
PPC_FUNC_IMPL(__imp__sub_8244B0C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8244B0D0;
	// stwu r1,-800(r1)
	ea = -800 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r3,820(r1)
	PPC_STORE_U32(ctx.r1.u32 + 820, ctx.r3.u32);
	// stw r5,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r5.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r6,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r6.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r31.u32);
	// li r3,3329
	ctx.r3.s64 = 3329;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244B10C;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244B134;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3587
	ctx.r3.s64 = 3587;
	// addi r30,r11,48
	r30.s64 = r11.s64 + 48;
	// bl 0x8244bb00
	ctx.lr = 0x8244B150;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244B178;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,3604
	ctx.r3.s64 = 3604;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244B194;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8244bb88
	ctx.lr = 0x8244B1BC;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244B1D4;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823de3a8
	ctx.lr = 0x8244B1E4;
	sub_823DE3A8(ctx, base);
	// addi r5,r1,140
	ctx.r5.s64 = ctx.r1.s64 + 140;
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// addi r25,r1,144
	r25.s64 = ctx.r1.s64 + 144;
	// addi r24,r1,148
	r24.s64 = ctx.r1.s64 + 148;
	// lwz r7,136(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// li r3,3604
	ctx.r3.s64 = 3604;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// stw r24,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r24.u32);
	// bl 0x8244bc28
	ctx.lr = 0x8244B230;
	sub_8244BC28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// addi r4,r1,820
	ctx.r4.s64 = ctx.r1.s64 + 820;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244B244;
	sub_8244A830(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244B250;
	sub_8244A830(ctx, base);
	// addi r4,r1,836
	ctx.r4.s64 = ctx.r1.s64 + 836;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244B25C;
	sub_8244A830(ctx, base);
	// addi r4,r1,844
	ctx.r4.s64 = ctx.r1.s64 + 844;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244B268;
	sub_8244A830(ctx, base);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244a830
	ctx.lr = 0x8244B274;
	sub_8244A830(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lwz r9,148(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244bd08
	ctx.lr = 0x8244B298;
	sub_8244BD08(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b2f4
	if (cr0.lt) goto loc_8244B2F4;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,40
	ctx.r7.s64 = 40;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r31.u64);
	// std r31,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r31.u64);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// rlwimi r4,r8,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// bl 0x827bd0b4
	ctx.lr = 0x8244B2EC;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244b320
	if (!cr0.lt) goto loc_8244B320;
loc_8244B2F4:
	// li r31,1627
	r31.s64 = 1627;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b308
	if (cr6.eq) goto loc_8244B308;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// b 0x8244b30c
	goto loc_8244B30C;
loc_8244B308:
	// bl 0x82135d40
	ctx.lr = 0x8244B30C;
	sub_82135D40(ctx, base);
loc_8244B30C:
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244b340
	if (cr6.eq) goto loc_8244B340;
	// bl 0x827bd344
	ctx.lr = 0x8244B31C;
	__imp__XamFree(ctx, base);
	// b 0x8244b340
	goto loc_8244B340;
loc_8244B320:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b330
	if (cr6.eq) goto loc_8244B330;
	// li r31,997
	r31.s64 = 997;
	// b 0x8244b340
	goto loc_8244B340;
loc_8244B330:
	// bl 0x82135d90
	ctx.lr = 0x8244B334;
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
loc_8244B340:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,800
	ctx.r1.s64 = ctx.r1.s64 + 800;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8244B34C"))) PPC_WEAK_FUNC(sub_8244B34C);
PPC_FUNC_IMPL(__imp__sub_8244B34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B350"))) PPC_WEAK_FUNC(sub_8244B350);
PPC_FUNC_IMPL(__imp__sub_8244B350) {
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
	ctx.lr = 0x8244B358;
	// stwu r1,-800(r1)
	ea = -800 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r3,820(r1)
	PPC_STORE_U32(ctx.r1.u32 + 820, ctx.r3.u32);
	// stw r5,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r5.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r31,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r31.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// li r3,2049
	ctx.r3.s64 = 2049;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// bl 0x8244bb00
	ctx.lr = 0x8244B394;
	sub_8244BB00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b530
	if (cr0.lt) goto loc_8244B530;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,136
	ctx.r7.s64 = ctx.r1.s64 + 136;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244bb88
	ctx.lr = 0x8244B3BC;
	sub_8244BB88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b530
	if (cr0.lt) goto loc_8244B530;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244B3D4;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b530
	if (cr0.lt) goto loc_8244B530;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x827bd304
	ctx.lr = 0x8244B3E4;
	__imp__XNetLogonGetTitleID(ctx, base);
	// stw r3,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8244B3EC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8244b3ec
	if (!cr6.eq) goto loc_8244B3EC;
	// lwz r10,836(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 836);
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r9,r1,152
	ctx.r9.s64 = ctx.r1.s64 + 152;
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r6,r1,148
	ctx.r6.s64 = ctx.r1.s64 + 148;
	// lwz r7,144(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// sth r10,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, ctx.r10.u16);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r3,2049
	ctx.r3.s64 = 2049;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// sth r11,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, r11.u16);
	// bl 0x8244bc28
	ctx.lr = 0x8244B454;
	sub_8244BC28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b530
	if (cr0.lt) goto loc_8244B530;
	// addi r4,r1,820
	ctx.r4.s64 = ctx.r1.s64 + 820;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B468;
	sub_8244A830(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B474;
	sub_8244A830(ctx, base);
	// addi r4,r1,836
	ctx.r4.s64 = ctx.r1.s64 + 836;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B480;
	sub_8244A830(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B48C;
	sub_8244A830(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B498;
	sub_8244A830(ctx, base);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B4A4;
	sub_8244A830(ctx, base);
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8244a830
	ctx.lr = 0x8244B4B0;
	sub_8244A830(ctx, base);
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lwz r9,156(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244bd08
	ctx.lr = 0x8244B4D4;
	sub_8244BD08(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244b530
	if (cr0.lt) goto loc_8244B530;
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r9,148(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,40
	ctx.r7.s64 = 40;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r31.u64);
	// std r31,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r31.u64);
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// rlwimi r4,r8,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// bl 0x827bd0b4
	ctx.lr = 0x8244B528;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244b55c
	if (!cr0.lt) goto loc_8244B55C;
loc_8244B530:
	// li r31,1627
	r31.s64 = 1627;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b544
	if (cr6.eq) goto loc_8244B544;
	// stw r3,24(r29)
	PPC_STORE_U32(r29.u32 + 24, ctx.r3.u32);
	// b 0x8244b548
	goto loc_8244B548;
loc_8244B544:
	// bl 0x82135d40
	ctx.lr = 0x8244B548;
	sub_82135D40(ctx, base);
loc_8244B548:
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244b57c
	if (cr6.eq) goto loc_8244B57C;
	// bl 0x827bd344
	ctx.lr = 0x8244B558;
	__imp__XamFree(ctx, base);
	// b 0x8244b57c
	goto loc_8244B57C;
loc_8244B55C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244b56c
	if (cr6.eq) goto loc_8244B56C;
	// li r31,997
	r31.s64 = 997;
	// b 0x8244b57c
	goto loc_8244B57C;
loc_8244B56C:
	// bl 0x82135d90
	ctx.lr = 0x8244B570;
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
loc_8244B57C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,800
	ctx.r1.s64 = ctx.r1.s64 + 800;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8244B588"))) PPC_WEAK_FUNC(sub_8244B588);
PPC_FUNC_IMPL(__imp__sub_8244B588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B5A4"))) PPC_WEAK_FUNC(sub_8244B5A4);
PPC_FUNC_IMPL(__imp__sub_8244B5A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B5A8"))) PPC_WEAK_FUNC(sub_8244B5A8);
PPC_FUNC_IMPL(__imp__sub_8244B5A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// ble cr6,0x8244b5c0
	if (!cr6.gt) goto loc_8244B5C0;
	// lis r3,-32744
	ctx.r3.s64 = -2145910784;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// blr 
	return;
loc_8244B5C0:
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B5CC"))) PPC_WEAK_FUNC(sub_8244B5CC);
PPC_FUNC_IMPL(__imp__sub_8244B5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B5D0"))) PPC_WEAK_FUNC(sub_8244B5D0);
PPC_FUNC_IMPL(__imp__sub_8244B5D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x8244b5fc
	if (!cr6.lt) goto loc_8244B5FC;
	// lis r3,-32744
	ctx.r3.s64 = -2145910784;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// blr 
	return;
loc_8244B5FC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B620"))) PPC_WEAK_FUNC(sub_8244B620);
PPC_FUNC_IMPL(__imp__sub_8244B620) {
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
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8244b5d0
	ctx.lr = 0x8244B63C;
	sub_8244B5D0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244b6e0
	if (cr0.lt) goto loc_8244B6E0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8244b6d0
	if (cr6.eq) goto loc_8244B6D0;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8244b6c0
	if (cr6.eq) goto loc_8244B6C0;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8244b6a8
	if (cr6.eq) goto loc_8244B6A8;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x8244b698
	if (cr6.eq) goto loc_8244B698;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// beq cr6,0x8244b67c
	if (cr6.eq) goto loc_8244B67C;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,13
	r31.u64 = r31.u64 | 13;
	// b 0x8244b6e0
	goto loc_8244B6E0;
loc_8244B67C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwbrx r11,0,r11
	r11.u64 = __builtin_bswap32(PPC_LOAD_U32(r11.u32));
	// lwbrx r10,0,r10
	ctx.r10.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r10.u32));
	// rldimi r11,r10,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// std r11,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, r11.u64);
	// b 0x8244b6e0
	goto loc_8244B6E0;
loc_8244B698:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwbrx r11,0,r11
	r11.u64 = __builtin_bswap32(PPC_LOAD_U32(r11.u32));
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// b 0x8244b6e0
	goto loc_8244B6E0;
loc_8244B6A8:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rlwinm r10,r11,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r10,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r10.u16);
	// b 0x8244b6e0
	goto loc_8244B6E0;
loc_8244B6C0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r11.u8);
	// b 0x8244b6e0
	goto loc_8244B6E0;
loc_8244B6D0:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r5,0(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x823da950
	ctx.lr = 0x8244B6E0;
	sub_823DA950(ctx, base);
loc_8244B6E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8244B6F8"))) PPC_WEAK_FUNC(sub_8244B6F8);
PPC_FUNC_IMPL(__imp__sub_8244B6F8) {
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
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bge cr6,0x8244b734
	if (!cr6.lt) goto loc_8244B734;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// b 0x8244b754
	goto loc_8244B754;
loc_8244B734:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x8244B744;
	sub_823DA950(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_8244B754:
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

__attribute__((alias("__imp__sub_8244B76C"))) PPC_WEAK_FUNC(sub_8244B76C);
PPC_FUNC_IMPL(__imp__sub_8244B76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B770"))) PPC_WEAK_FUNC(sub_8244B770);
PPC_FUNC_IMPL(__imp__sub_8244B770) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244b794
	if (!cr6.lt) goto loc_8244B794;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// blr 
	return;
loc_8244B794:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x8244b7e4
	if (cr6.eq) goto loc_8244B7E4;
loc_8244B7A4:
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8244b7c0
	if (cr6.eq) goto loc_8244B7C0;
	// lhz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// rlwinm r10,r9,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// b 0x8244b7c4
	goto loc_8244B7C4;
loc_8244B7C0:
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
loc_8244B7C4:
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x8244b7a4
	if (!cr0.eq) goto loc_8244B7A4;
loc_8244B7E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B7EC"))) PPC_WEAK_FUNC(sub_8244B7EC);
PPC_FUNC_IMPL(__imp__sub_8244B7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B7F0"))) PPC_WEAK_FUNC(sub_8244B7F0);
PPC_FUNC_IMPL(__imp__sub_8244B7F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244b814
	if (!cr6.lt) goto loc_8244B814;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// blr 
	return;
loc_8244B814:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x8244b86c
	if (cr6.eq) goto loc_8244B86C;
loc_8244B824:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244b848
	if (cr6.eq) goto loc_8244B848;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r11,r9,8,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// rlwimi r11,r9,24,16,23
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 24) & 0xFF00) | (r11.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r11,r9,8,8,15
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF0000) | (r11.u64 & 0xFFFFFFFFFF00FFFF);
	// rlwimi r11,r9,24,0,7
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 24) & 0xFF000000) | (r11.u64 & 0xFFFFFFFF00FFFFFF);
	// b 0x8244b84c
	goto loc_8244B84C;
loc_8244B848:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
loc_8244B84C:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8244b824
	if (!cr0.eq) goto loc_8244B824;
loc_8244B86C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B874"))) PPC_WEAK_FUNC(sub_8244B874);
PPC_FUNC_IMPL(__imp__sub_8244B874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B878"))) PPC_WEAK_FUNC(sub_8244B878);
PPC_FUNC_IMPL(__imp__sub_8244B878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244b89c
	if (!cr6.lt) goto loc_8244B89C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// blr 
	return;
loc_8244B89C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x8244b910
	if (cr6.eq) goto loc_8244B910;
loc_8244B8AC:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ld r11,0(r4)
	r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// addi r4,r4,8
	ctx.r4.s64 = ctx.r4.s64 + 8;
	// beq cr6,0x8244b8f4
	if (cr6.eq) goto loc_8244B8F4;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r11,-16(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// rlwinm r8,r11,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwimi r8,r11,24,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 24) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm r7,r10,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// rlwimi r8,r11,8,8,15
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF0000) | (ctx.r8.u64 & 0xFFFFFFFFFF00FFFF);
	// rlwimi r7,r10,24,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r8,r11,24,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 24) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// rlwimi r7,r10,8,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// clrldi r11,r8,32
	r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// rldimi r11,r7,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
loc_8244B8F4:
	// std r11,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r11.u64);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x8244b8ac
	if (!cr0.eq) goto loc_8244B8AC;
loc_8244B910:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B918"))) PPC_WEAK_FUNC(sub_8244B918);
PPC_FUNC_IMPL(__imp__sub_8244B918) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bge cr6,0x8244b93c
	if (!cr6.lt) goto loc_8244B93C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// blr 
	return;
loc_8244B93C:
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B94C"))) PPC_WEAK_FUNC(sub_8244B94C);
PPC_FUNC_IMPL(__imp__sub_8244B94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244B950"))) PPC_WEAK_FUNC(sub_8244B950);
PPC_FUNC_IMPL(__imp__sub_8244B950) {
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
	// li r11,1
	r11.s64 = 1;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x8244b5d0
	ctx.lr = 0x8244B978;
	sub_8244B5D0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244b990
	if (cr0.lt) goto loc_8244B990;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823da950
	ctx.lr = 0x8244B990;
	sub_823DA950(ctx, base);
loc_8244B990:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8244B9A8"))) PPC_WEAK_FUNC(sub_8244B9A8);
PPC_FUNC_IMPL(__imp__sub_8244B9A8) {
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
	// li r11,2
	r11.s64 = 2;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8244b620
	ctx.lr = 0x8244B9C8;
	sub_8244B620(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244B9D8"))) PPC_WEAK_FUNC(sub_8244B9D8);
PPC_FUNC_IMPL(__imp__sub_8244B9D8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8244b5d0
	ctx.lr = 0x8244B9F4;
	sub_8244B5D0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244ba0c
	if (cr0.lt) goto loc_8244BA0C;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r5,0(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x823da950
	ctx.lr = 0x8244BA0C;
	sub_823DA950(ctx, base);
loc_8244BA0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8244BA24"))) PPC_WEAK_FUNC(sub_8244BA24);
PPC_FUNC_IMPL(__imp__sub_8244BA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BA28"))) PPC_WEAK_FUNC(sub_8244BA28);
PPC_FUNC_IMPL(__imp__sub_8244BA28) {
	PPC_FUNC_PROLOGUE();
	// b 0x8244b5d0
	sub_8244B5D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244BA2C"))) PPC_WEAK_FUNC(sub_8244BA2C);
PPC_FUNC_IMPL(__imp__sub_8244BA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BA30"))) PPC_WEAK_FUNC(sub_8244BA30);
PPC_FUNC_IMPL(__imp__sub_8244BA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244BA40"))) PPC_WEAK_FUNC(sub_8244BA40);
PPC_FUNC_IMPL(__imp__sub_8244BA40) {
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
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8244bab0
	if (cr6.eq) goto loc_8244BAB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244bab0
	if (cr6.eq) goto loc_8244BAB0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244bab0
	if (cr6.eq) goto loc_8244BAB0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8244a300
	ctx.lr = 0x8244BA80;
	sub_8244A300(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8244bab4
	if (!cr0.eq) goto loc_8244BAB4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,12280
	ctx.r3.s64 = r11.s64 + 12280;
	// bl 0x8244c2b8
	ctx.lr = 0x8244BA9C;
	sub_8244C2B8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bge 0x8244bab4
	if (!cr0.lt) goto loc_8244BAB4;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x8244bab4
	goto loc_8244BAB4;
loc_8244BAB0:
	// li r3,87
	ctx.r3.s64 = 87;
loc_8244BAB4:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244BAC8"))) PPC_WEAK_FUNC(sub_8244BAC8);
PPC_FUNC_IMPL(__imp__sub_8244BAC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,14468
	ctx.r3.s64 = r11.s64 + 14468;
	// b 0x8244ba40
	sub_8244BA40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244BAD4"))) PPC_WEAK_FUNC(sub_8244BAD4);
PPC_FUNC_IMPL(__imp__sub_8244BAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BAD8"))) PPC_WEAK_FUNC(sub_8244BAD8);
PPC_FUNC_IMPL(__imp__sub_8244BAD8) {
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
	// bl 0x8244a310
	ctx.lr = 0x8244BAE8;
	sub_8244A310(ctx, base);
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

__attribute__((alias("__imp__sub_8244BAFC"))) PPC_WEAK_FUNC(sub_8244BAFC);
PPC_FUNC_IMPL(__imp__sub_8244BAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BB00"))) PPC_WEAK_FUNC(sub_8244BB00);
PPC_FUNC_IMPL(__imp__sub_8244BB00) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r11,r11,12280
	r11.s64 = r11.s64 + 12280;
	// lwz r4,44(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// cmplwi r4,0
	cr0.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne 0x8244bb34
	if (!cr0.eq) goto loc_8244BB34;
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,5
	ctx.r3.u64 = ctx.r3.u64 | 5;
	// b 0x8244bb70
	goto loc_8244BB70;
loc_8244BB34:
	// sth r3,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r3.u16);
	// lis r9,-32187
	ctx.r9.s64 = -2109407232;
	// li r6,4
	ctx.r6.s64 = 4;
	// lhz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 40);
	// addi r7,r9,-17872
	ctx.r7.s64 = ctx.r9.s64 + -17872;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x8244BB50;
	sub_823DE288(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244bb64
	if (!cr0.eq) goto loc_8244BB64;
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8244bb70
	goto loc_8244BB70;
loc_8244BB64:
	// lhz r11,2(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8244BB70:
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

__attribute__((alias("__imp__sub_8244BB84"))) PPC_WEAK_FUNC(sub_8244BB84);
PPC_FUNC_IMPL(__imp__sub_8244BB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BB88"))) PPC_WEAK_FUNC(sub_8244BB88);
PPC_FUNC_IMPL(__imp__sub_8244BB88) {
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
	ctx.lr = 0x8244BB90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,12280
	ctx.r3.s64 = ctx.r10.s64 + 12280;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x8244c228
	ctx.lr = 0x8244BBC4;
	sub_8244C228(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244bc1c
	if (cr0.lt) goto loc_8244BC1C;
	// rlwinm. r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8244bbd8
	if (!cr0.eq) goto loc_8244BBD8;
	// lwz r29,92(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8244BBD8:
	// mulli r11,r29,120
	r11.s64 = r29.s64 * 120;
	// li r10,100
	ctx.r10.s64 = 100;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// beq cr6,0x8244bbf8
	if (cr6.eq) goto loc_8244BBF8;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8244BBF8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8244bc08
	if (cr6.eq) goto loc_8244BC08;
	// li r10,4096
	ctx.r10.s64 = 4096;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
loc_8244BC08:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8244bc1c
	if (cr6.eq) goto loc_8244BC1C;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// addi r11,r11,11884
	r11.s64 = r11.s64 + 11884;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8244BC1C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8244BC24"))) PPC_WEAK_FUNC(sub_8244BC24);
PPC_FUNC_IMPL(__imp__sub_8244BC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BC28"))) PPC_WEAK_FUNC(sub_8244BC28);
PPC_FUNC_IMPL(__imp__sub_8244BC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8244BC30;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// addi r29,r6,7712
	r29.s64 = ctx.r6.s64 + 7712;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// ori r4,r4,32772
	ctx.r4.u64 = ctx.r4.u64 | 32772;
	// li r3,252
	ctx.r3.s64 = 252;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// addi r22,r29,4172
	r22.s64 = r29.s64 + 4172;
	// bl 0x827bd0d4
	ctx.lr = 0x8244BC70;
	__imp__XMsgInProcessCall(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// blt 0x8244bc80
	if (cr0.lt) goto loc_8244BC80;
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
loc_8244BC80:
	// lwz r9,324(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// addi r8,r31,76
	ctx.r8.s64 = r31.s64 + 76;
	// mr r28,r31
	r28.u64 = r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// subf r31,r22,r30
	r31.s64 = r30.s64 - r22.s64;
	// lwz r10,348(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// add r30,r29,r8
	r30.u64 = r29.u64 + ctx.r8.u64;
	// stw r23,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r23.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r24.u32);
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// li r9,4096
	ctx.r9.s64 = 4096;
	// add r7,r31,r30
	ctx.r7.u64 = r31.u64 + r30.u64;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// addi r5,r11,12280
	ctx.r5.s64 = r11.s64 + 12280;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8244c3f8
	ctx.lr = 0x8244BCE0;
	sub_8244C3F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244bd00
	if (cr0.lt) goto loc_8244BD00;
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r10,340(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// lwz r9,356(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// stw r28,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r28.u32);
loc_8244BD00:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8244BD08"))) PPC_WEAK_FUNC(sub_8244BD08);
PPC_FUNC_IMPL(__imp__sub_8244BD08) {
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
	ctx.lr = 0x8244BD10;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// not r11,r6
	r11.u64 = ~ctx.r6.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// rlwinm r24,r11,30,31,31
	r24.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r4,1088
	cr6.compare<uint32_t>(ctx.r4.u32, 1088, xer);
	// bge cr6,0x8244bd74
	if (!cr6.lt) goto loc_8244BD74;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244bd54
	if (cr6.eq) goto loc_8244BD54;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,122
	r31.u64 = r31.u64 | 122;
	// b 0x8244bdd0
	goto loc_8244BDD0;
loc_8244BD54:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1088
	ctx.r4.s64 = 1088;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd354
	ctx.lr = 0x8244BD64;
	__imp__XamAlloc(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244bdc0
	if (cr0.lt) goto loc_8244BDC0;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8244bd78
	goto loc_8244BD78;
loc_8244BD74:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8244BD78:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// addi r4,r11,12280
	ctx.r4.s64 = r11.s64 + 12280;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244c4d8
	ctx.lr = 0x8244BDA0;
	sub_8244C4D8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244bdc0
	if (cr0.lt) goto loc_8244BDC0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244cdf0
	ctx.lr = 0x8244BDB0;
	sub_8244CDF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244bdc0
	if (cr0.lt) goto loc_8244BDC0;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
loc_8244BDC0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244bdd0
	if (cr6.eq) goto loc_8244BDD0;
	// bl 0x827bd344
	ctx.lr = 0x8244BDD0;
	__imp__XamFree(ctx, base);
loc_8244BDD0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8244BDDC"))) PPC_WEAK_FUNC(sub_8244BDDC);
PPC_FUNC_IMPL(__imp__sub_8244BDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BDE0"))) PPC_WEAK_FUNC(sub_8244BDE0);
PPC_FUNC_IMPL(__imp__sub_8244BDE0) {
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
	// li r11,1
	r11.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8244b9d8
	ctx.lr = 0x8244BDFC;
	sub_8244B9D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244BE0C"))) PPC_WEAK_FUNC(sub_8244BE0C);
PPC_FUNC_IMPL(__imp__sub_8244BE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BE10"))) PPC_WEAK_FUNC(sub_8244BE10);
PPC_FUNC_IMPL(__imp__sub_8244BE10) {
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
	// li r11,2
	r11.s64 = 2;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244BE3C;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244be50
	if (cr0.lt) goto loc_8244BE50;
	// addi r4,r30,2
	ctx.r4.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244BE50;
	sub_8244B9A8(ctx, base);
loc_8244BE50:
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

__attribute__((alias("__imp__sub_8244BE68"))) PPC_WEAK_FUNC(sub_8244BE68);
PPC_FUNC_IMPL(__imp__sub_8244BE68) {
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
	// li r11,2
	r11.s64 = 2;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8244b9d8
	ctx.lr = 0x8244BE84;
	sub_8244B9D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244BE94"))) PPC_WEAK_FUNC(sub_8244BE94);
PPC_FUNC_IMPL(__imp__sub_8244BE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244BE98"))) PPC_WEAK_FUNC(sub_8244BE98);
PPC_FUNC_IMPL(__imp__sub_8244BE98) {
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
	ctx.lr = 0x8244BEA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,2
	r11.s64 = 2;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244BEC0;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244bee0
	if (cr0.lt) goto loc_8244BEE0;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244bee0
	if (cr0.eq) goto loc_8244BEE0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244BEE0;
	sub_8244B9A8(ctx, base);
loc_8244BEE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244BEE8"))) PPC_WEAK_FUNC(sub_8244BEE8);
PPC_FUNC_IMPL(__imp__sub_8244BEE8) {
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
	ctx.lr = 0x8244BEF0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,16
	cr6.compare<uint32_t>(r26.u32, 16, xer);
	// bge cr6,0x8244c064
	if (!cr6.lt) goto loc_8244C064;
	// li r27,1
	r27.s64 = 1;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// bl 0x8244b9d8
	ctx.lr = 0x8244BF18;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,30,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244c064
	if (cr6.lt) goto loc_8244C064;
	// beq cr6,0x8244bf3c
	if (cr6.eq) goto loc_8244BF3C;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8244c064
	if (!cr6.lt) goto loc_8244C064;
loc_8244BF3C:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244BF48;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244bf78
	if (cr0.eq) goto loc_8244BF78;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,83
	ctx.r4.s64 = ctx.r1.s64 + 83;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244BF70;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244BF78:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244bf98
	if (cr0.eq) goto loc_8244BF98;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244BF90;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244BF98:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r28,2
	r28.s64 = 2;
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244bfe4
	if (cr0.eq) goto loc_8244BFE4;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244BFBC;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,86(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244bfe4
	if (cr0.eq) goto loc_8244BFE4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244BFDC;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244BFE4:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244c014
	if (!cr6.eq) goto loc_8244C014;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244be98
	ctx.lr = 0x8244C004;
	sub_8244BE98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// li r29,0
	r29.s64 = 0;
	// b 0x8244c018
	goto loc_8244C018;
loc_8244C014:
	// lhz r29,88(r1)
	r29.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
loc_8244C018:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244c0fc
	if (!cr6.eq) goto loc_8244C0FC;
	// lbz r11,89(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// clrlwi r10,r29,16
	ctx.r10.u64 = r29.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8244c074
	if (cr6.lt) goto loc_8244C074;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8244b9d8
	ctx.lr = 0x8244C04C;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
loc_8244C060:
	// beq cr6,0x8244c150
	if (cr6.eq) goto loc_8244C150;
loc_8244C064:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_8244C06C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8244C074:
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bl 0x8244b950
	ctx.lr = 0x8244C07C;
	sub_8244B950(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,82(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// li r30,0
	r30.s64 = 0;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8244c0b8
	if (cr0.eq) goto loc_8244C0B8;
loc_8244C094:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C0A0;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,82(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8244c094
	if (cr6.lt) goto loc_8244C094;
loc_8244C0B8:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C0C4;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lhz r11,84(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bl 0x8244ba28
	ctx.lr = 0x8244C0E4;
	sub_8244BA28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8244c150
	goto loc_8244C150;
loc_8244C0FC:
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8244b9d8
	ctx.lr = 0x8244C110;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r11,r10,30,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244c180
	if (cr6.lt) goto loc_8244C180;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8244c060
	if (!cr6.lt) goto loc_8244C060;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b5a8
	ctx.lr = 0x8244C13C;
	sub_8244B5A8(ctx, base);
	// addi r4,r26,1
	ctx.r4.s64 = r26.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244bee8
	ctx.lr = 0x8244C148;
	sub_8244BEE8(ctx, base);
loc_8244C148:
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244C150:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244c16c
	if (!cr6.eq) goto loc_8244C16C;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r29,r11,16
	r29.u64 = r11.u32 & 0xFFFF;
loc_8244C16C:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x8244c018
	if (!cr6.eq) goto loc_8244C018;
	// b 0x8244c06c
	goto loc_8244C06C;
loc_8244C180:
	// rlwinm. r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c1a4
	if (cr0.eq) goto loc_8244C1A4;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,83
	ctx.r4.s64 = ctx.r1.s64 + 83;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244C19C;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244C1A4:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c1c4
	if (cr0.eq) goto loc_8244C1C4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C1BC;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244C1C4:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c20c
	if (cr0.eq) goto loc_8244C20C;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9d8
	ctx.lr = 0x8244C1E4;
	sub_8244B9D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
	// lbz r11,86(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c20c
	if (cr0.eq) goto loc_8244C20C;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C204;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c06c
	if (cr0.lt) goto loc_8244C06C;
loc_8244C20C:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c150
	if (cr0.eq) goto loc_8244C150;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244be10
	ctx.lr = 0x8244C224;
	sub_8244BE10(ctx, base);
	// b 0x8244c148
	goto loc_8244C148;
}

__attribute__((alias("__imp__sub_8244C228"))) PPC_WEAK_FUNC(sub_8244C228);
PPC_FUNC_IMPL(__imp__sub_8244C228) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lhz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 40);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// blt cr6,0x8244c254
	if (cr6.lt) goto loc_8244C254;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8244c270
	goto loc_8244C270;
loc_8244C254:
	// lhz r9,42(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 42);
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mullw r11,r9,r4
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x8244C26C;
	sub_823DA950(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244C270:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244C280"))) PPC_WEAK_FUNC(sub_8244C280);
PPC_FUNC_IMPL(__imp__sub_8244C280) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8244c29c
	if (!cr6.gt) goto loc_8244C29C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
loc_8244C29C:
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244C2B4"))) PPC_WEAK_FUNC(sub_8244C2B4);
PPC_FUNC_IMPL(__imp__sub_8244C2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244C2B8"))) PPC_WEAK_FUNC(sub_8244C2B8);
PPC_FUNC_IMPL(__imp__sub_8244C2B8) {
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
	ctx.lr = 0x8244C2C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x823da950
	ctx.lr = 0x8244C2D8;
	sub_823DA950(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r9,r30,44
	ctx.r9.s64 = r30.s64 + 44;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c2f4
	if (cr0.eq) goto loc_8244C2F4;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
	// b 0x8244c370
	goto loc_8244C370;
loc_8244C2F4:
	// lhz r8,38(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq 0x8244c308
	if (cr0.eq) goto loc_8244C308;
	// stw r9,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r9.u32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_8244C308:
	// lhz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rotlwi r11,r10,2
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lhz r6,42(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// subf r7,r11,r7
	ctx.r7.s64 = ctx.r7.s64 - r11.s64;
	// lhz r5,26(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// mullw r10,r6,r10
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// lhz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// lhz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// subf r9,r10,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r9,-44
	ctx.r10.s64 = ctx.r9.s64 + -44;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// mullw r9,r5,r6
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
loc_8244C370:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244C37C"))) PPC_WEAK_FUNC(sub_8244C37C);
PPC_FUNC_IMPL(__imp__sub_8244C37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244C380"))) PPC_WEAK_FUNC(sub_8244C380);
PPC_FUNC_IMPL(__imp__sub_8244C380) {
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
	ctx.lr = 0x8244C388;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r31.u32);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8244c228
	ctx.lr = 0x8244C3AC;
	sub_8244C228(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244c3ec
	if (cr0.lt) goto loc_8244C3EC;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8244c3cc
	if (cr6.eq) goto loc_8244C3CC;
	// lhz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8244c3d4
	goto loc_8244C3D4;
loc_8244C3CC:
	// lhz r6,82(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_8244C3D4:
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x8244b588
	ctx.lr = 0x8244C3EC;
	sub_8244B588(ctx, base);
loc_8244C3EC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244C3F8"))) PPC_WEAK_FUNC(sub_8244C3F8);
PPC_FUNC_IMPL(__imp__sub_8244C3F8) {
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
	ctx.lr = 0x8244C400;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// rlwinm. r11,r30,0,25,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c43c
	if (cr0.eq) goto loc_8244C43C;
	// bl 0x827bcfc4
	ctx.lr = 0x8244C430;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8244c43c
	if (!cr6.eq) goto loc_8244C43C;
	// ori r30,r30,16
	r30.u64 = r30.u64 | 16;
loc_8244C43C:
	// lwz r11,252(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,260(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,244(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,284(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// lwz r4,292(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// stw r5,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r5.u32);
	// stw r4,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r4.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r26.u32);
	// stw r25,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r25.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
	// stw r24,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r24.u32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// lwz r5,276(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// bl 0x8244b588
	ctx.lr = 0x8244C4A0;
	sub_8244B588(ctx, base);
	// lwz r11,300(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// beq cr6,0x8244c4cc
	if (cr6.eq) goto loc_8244C4CC;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244c4c0
	if (cr6.eq) goto loc_8244C4C0;
	// bl 0x82458230
	ctx.lr = 0x8244C4C0;
	sub_82458230(ctx, base);
loc_8244C4C0:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r10,997
	ctx.r10.s64 = 997;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_8244C4CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8244C4D8"))) PPC_WEAK_FUNC(sub_8244C4D8);
PPC_FUNC_IMPL(__imp__sub_8244C4D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8244C4E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// bl 0x8244c380
	ctx.lr = 0x8244C510;
	sub_8244C380(ctx, base);
	// mr. r25,r3
	r25.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bge 0x8244c54c
	if (!cr0.lt) goto loc_8244C54C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,1080(r31)
	PPC_STORE_U32(r31.u32 + 1080, r11.u32);
	// b 0x8244c58c
	goto loc_8244C58C;
loc_8244C54C:
	// stw r28,1080(r31)
	PPC_STORE_U32(r31.u32 + 1080, r28.u32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x8244b588
	ctx.lr = 0x8244C568;
	sub_8244B588(ctx, base);
	// addi r10,r31,56
	ctx.r10.s64 = r31.s64 + 56;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r11,0
	r11.s64 = 0;
loc_8244C574:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8244c574
	if (!cr0.eq) goto loc_8244C574;
loc_8244C58C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8244C598"))) PPC_WEAK_FUNC(sub_8244C598);
PPC_FUNC_IMPL(__imp__sub_8244C598) {
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
	ctx.lr = 0x8244C5A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// bgt cr6,0x8244c610
	if (cr6.gt) goto loc_8244C610;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x8244bde0
	ctx.lr = 0x8244C5C4;
	sub_8244BDE0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244c618
	if (cr0.lt) goto loc_8244C618;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8244c5e0
	if (cr6.eq) goto loc_8244C5E0;
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8244C5E0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// lwz r9,512(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244c600
	if (!cr6.lt) goto loc_8244C600;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8244c604
	goto loc_8244C604;
loc_8244C600:
	// li r11,0
	r11.s64 = 0;
loc_8244C604:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8244c618
	if (!cr6.eq) goto loc_8244C618;
loc_8244C610:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
loc_8244C618:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244C620"))) PPC_WEAK_FUNC(sub_8244C620);
PPC_FUNC_IMPL(__imp__sub_8244C620) {
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
	ctx.lr = 0x8244C628;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r14,0
	r14.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r28,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, r28.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// sth r14,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, r14.u16);
	// stw r29,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r29.u32);
	// cmplwi cr6,r28,16
	cr6.compare<uint32_t>(r28.u32, 16, xer);
	// stw r14,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r14.u32);
	// blt cr6,0x8244c660
	if (cr6.lt) goto loc_8244C660;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8244c8ac
	goto loc_8244C8AC;
loc_8244C660:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244c670
	if (cr6.eq) goto loc_8244C670;
	// lwz r20,0(r29)
	r20.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x8244c674
	goto loc_8244C674;
loc_8244C670:
	// mr r20,r14
	r20.u64 = r14.u64;
loc_8244C674:
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// addi r23,r27,28
	r23.s64 = r27.s64 + 28;
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// bl 0x8244bde0
	ctx.lr = 0x8244C68C;
	sub_8244BDE0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,30,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244c8a0
	if (cr6.lt) goto loc_8244C8A0;
	// beq cr6,0x8244c6b8
	if (cr6.eq) goto loc_8244C6B8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8244c8a0
	if (!cr6.lt) goto loc_8244C8A0;
	// addi r4,r1,90
	ctx.r4.s64 = ctx.r1.s64 + 90;
	// b 0x8244c6bc
	goto loc_8244C6BC;
loc_8244C6B8:
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
loc_8244C6BC:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C6C4;
	sub_8244B9A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r15,4
	r15.s64 = 4;
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c718
	if (cr0.eq) goto loc_8244C718;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244c598
	ctx.lr = 0x8244C6F0;
	sub_8244C598(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// ld r20,8(r11)
	r20.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// stw r15,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r15.u32);
	// std r10,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r10.u64);
loc_8244C718:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c738
	if (cr0.eq) goto loc_8244C738;
	// addi r4,r1,98
	ctx.r4.s64 = ctx.r1.s64 + 98;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C730;
	sub_8244B9A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
loc_8244C738:
	// lbz r4,81(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r18,1
	r18.s64 = 1;
	// rlwinm. r11,r4,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244c770
	if (cr0.eq) goto loc_8244C770;
	// lwz r11,1080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1080);
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r27,56
	ctx.r3.s64 = r27.s64 + 56;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// bl 0x8244cf50
	ctx.lr = 0x8244C764;
	sub_8244CF50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// b 0x8244c774
	goto loc_8244C774;
loc_8244C770:
	// stw r18,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r18.u32);
loc_8244C774:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r17,r14
	r17.u64 = r14.u64;
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244c810
	if (!cr6.eq) goto loc_8244C810;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244be98
	ctx.lr = 0x8244C798;
	sub_8244BE98(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// addi r30,r27,56
	r30.s64 = r27.s64 + 56;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244cea0
	ctx.lr = 0x8244C7B8;
	sub_8244CEA0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ld r16,8(r11)
	r16.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// beq 0x8244c7f4
	if (cr0.eq) goto loc_8244C7F4;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lhz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 92);
	// lwz r3,48(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// bl 0x8244c280
	ctx.lr = 0x8244C7E4;
	sub_8244C280(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// and r16,r11,r16
	r16.u64 = r11.u64 & r16.u64;
loc_8244C7F4:
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// bl 0x8244cef0
	ctx.lr = 0x8244C804;
	sub_8244CEF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8244c814
	if (!cr0.lt) goto loc_8244C814;
	// b 0x8244c8a8
	goto loc_8244C8A8;
loc_8244C810:
	// lwz r16,132(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
loc_8244C814:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r19,40(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244cd90
	if (cr6.eq) goto loc_8244CD90;
	// ld r24,136(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
loc_8244C828:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r22,r14
	r22.u64 = r14.u64;
	// mr r21,r14
	r21.u64 = r14.u64;
	// andi. r11,r11,243
	r11.u64 = r11.u64 & 243;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8244c844
	goto loc_8244C844;
loc_8244C840:
	// lwz r28,332(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
loc_8244C844:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244c968
	if (!cr6.eq) goto loc_8244C968;
	// lbz r11,85(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// clrlwi r10,r22,16
	ctx.r10.u64 = r22.u32 & 0xFFFF;
	// mr r29,r14
	r29.u64 = r14.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// blt cr6,0x8244c8b4
	if (cr6.lt) goto loc_8244C8B4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8244bde0
	ctx.lr = 0x8244C874;
	sub_8244BDE0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r11,r9,0,28,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x8244c8a0
	if (!cr6.eq) goto loc_8244C8A0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x8244cd34
	if (!cr6.eq) goto loc_8244CD34;
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244cd34
	if (cr0.eq) goto loc_8244CD34;
loc_8244C8A0:
	// lis r31,-32768
	r31.s64 = -2147483648;
	// ori r31,r31,16389
	r31.u64 = r31.u64 | 16389;
loc_8244C8A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8244C8AC:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_8244C8B4:
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// bl 0x8244b950
	ctx.lr = 0x8244C8BC;
	sub_8244B950(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,82(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// mr r30,r14
	r30.u64 = r14.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8244c924
	if (cr0.eq) goto loc_8244C924;
loc_8244C8D4:
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C8E0;
	sub_8244B9A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lhz r4,86(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// lwz r3,48(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// bl 0x8244c280
	ctx.lr = 0x8244C8F8;
	sub_8244C280(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplw cr6,r16,r11
	cr6.compare<uint32_t>(r16.u32, r11.u32, xer);
	// bne cr6,0x8244c914
	if (!cr6.eq) goto loc_8244C914;
	// mr r29,r18
	r29.u64 = r18.u64;
	// mr r21,r18
	r21.u64 = r18.u64;
loc_8244C914:
	// lbz r11,82(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8244c8d4
	if (cr6.lt) goto loc_8244C8D4;
loc_8244C924:
	// addi r4,r1,86
	ctx.r4.s64 = ctx.r1.s64 + 86;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244C930;
	sub_8244B9A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8244c968
	if (!cr6.eq) goto loc_8244C968;
	// lhz r11,86(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// bl 0x8244ba28
	ctx.lr = 0x8244C958;
	sub_8244BA28(ctx, base);
loc_8244C958:
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// b 0x8244cd34
	goto loc_8244CD34;
loc_8244C968:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r30,40(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244bde0
	ctx.lr = 0x8244C978;
	sub_8244BDE0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r11,r9,30,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244ca10
	if (cr6.lt) goto loc_8244CA10;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8244c9a4
	if (cr6.lt) goto loc_8244C9A4;
	// bne cr6,0x8244c8a0
	if (!cr6.eq) goto loc_8244C8A0;
	// b 0x8244cd34
	goto loc_8244CD34;
loc_8244C9A4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b5a8
	ctx.lr = 0x8244C9B0;
	sub_8244B5A8(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8244ca08
	if (cr0.eq) goto loc_8244CA08;
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8244ca08
	if (!cr0.eq) goto loc_8244CA08;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8244ca00
	if (cr6.eq) goto loc_8244CA00;
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
loc_8244C9D4:
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r28,1
	ctx.r4.s64 = r28.s64 + 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244c620
	ctx.lr = 0x8244C9E4;
	sub_8244C620(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r11,r9,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244cd14
	if (cr0.eq) goto loc_8244CD14;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// b 0x8244cd34
	goto loc_8244CD34;
loc_8244CA00:
	// stw r14,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r14.u32);
	// b 0x8244c9d4
	goto loc_8244C9D4;
loc_8244CA08:
	// stw r20,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r20.u32);
	// b 0x8244c9d4
	goto loc_8244C9D4;
loc_8244CA10:
	// mr r26,r14
	r26.u64 = r14.u64;
	// rlwinm. r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r25,r14
	r25.u64 = r14.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// beq 0x8244ca68
	if (cr0.eq) goto loc_8244CA68;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244c598
	ctx.lr = 0x8244CA38;
	sub_8244C598(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r26,92(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// ld r20,8(r11)
	r20.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// stw r15,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r15.u32);
	// std r10,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r10.u64);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
loc_8244CA68:
	// rlwinm. r11,r9,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244ca88
	if (cr0.eq) goto loc_8244CA88;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244CA7C;
	sub_8244B9A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
loc_8244CA88:
	// clrlwi r11,r9,30
	r11.u64 = ctx.r9.u32 & 0x3;
	// rlwinm. r10,r9,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// slw r28,r18,r11
	r28.u64 = r11.u8 & 0x20 ? 0 : (r18.u32 << (r11.u8 & 0x3F));
	// beq 0x8244cb68
	if (cr0.eq) goto loc_8244CB68;
	// lwz r11,1080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1080);
	// addi r30,r27,56
	r30.s64 = r27.s64 + 56;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244cf50
	ctx.lr = 0x8244CABC;
	sub_8244CF50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,88(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// rlwinm. r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne 0x8244caf4
	if (!cr0.eq) goto loc_8244CAF4;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm. r9,r9,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8244caf4
	if (!cr0.eq) goto loc_8244CAF4;
	// mr r29,r18
	r29.u64 = r18.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8244cb58
	if (cr6.eq) goto loc_8244CB58;
	// lwz r3,0(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// b 0x8244cafc
	goto loc_8244CAFC;
loc_8244CAF4:
	// mr r29,r14
	r29.u64 = r14.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_8244CAFC:
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8244cb28
	if (cr0.eq) goto loc_8244CB28;
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r25,r18
	r25.u64 = r18.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8244cb28
	if (!cr6.eq) goto loc_8244CB28;
	// bl 0x823de3a8
	ctx.lr = 0x8244CB1C;
	sub_823DE3A8(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r11,88(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_8244CB28:
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244cef0
	ctx.lr = 0x8244CB34;
	sub_8244CEF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// beq cr6,0x8244cb60
	if (cr6.eq) goto loc_8244CB60;
	// mr r28,r15
	r28.u64 = r15.u64;
	// b 0x8244cb78
	goto loc_8244CB78;
loc_8244CB58:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// b 0x8244cafc
	goto loc_8244CAFC;
loc_8244CB60:
	// mullw r28,r5,r28
	r28.s64 = int64_t(ctx.r5.s32) * int64_t(r28.s32);
	// b 0x8244cb78
	goto loc_8244CB78;
loc_8244CB68:
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
loc_8244CB78:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x8244cbf0
	if (cr6.eq) goto loc_8244CBF0;
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r31,16(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r3,0
	ctx.r3.s64 = 0;
	// add r7,r11,r8
	ctx.r7.u64 = r11.u64 + ctx.r8.u64;
	// subf r8,r4,r31
	ctx.r8.s64 = r31.s64 - ctx.r4.s64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// bl 0x82458268
	ctx.lr = 0x8244CBBC;
	sub_82458268(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8244b918
	ctx.lr = 0x8244CBCC;
	sub_8244B918(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,88(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// li r6,1
	ctx.r6.s64 = 1;
	// clrldi r5,r30,32
	ctx.r5.u64 = r30.u64 & 0xFFFFFFFF;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// addi r3,r27,56
	ctx.r3.s64 = r27.s64 + 56;
	// bl 0x8244d060
	ctx.lr = 0x8244CBEC;
	sub_8244D060(ctx, base);
	// b 0x8244cc74
	goto loc_8244CC74;
loc_8244CBF0:
	// mr r31,r14
	r31.u64 = r14.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8244cc88
	if (cr6.eq) goto loc_8244CC88;
	// clrlwi r11,r9,30
	r11.u64 = ctx.r9.u32 & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244cc60
	if (cr6.lt) goto loc_8244CC60;
	// beq cr6,0x8244cc48
	if (cr6.eq) goto loc_8244CC48;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8244cc30
	if (cr6.lt) goto loc_8244CC30;
	// bne cr6,0x8244cc88
	if (!cr6.eq) goto loc_8244CC88;
	// ld r24,0(r4)
	r24.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8244cc88
	if (!cr6.eq) goto loc_8244CC88;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8244b878
	ctx.lr = 0x8244CC2C;
	sub_8244B878(ctx, base);
	// b 0x8244cc74
	goto loc_8244CC74;
loc_8244CC30:
	// lwz r24,0(r4)
	r24.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8244cc88
	if (!cr6.eq) goto loc_8244CC88;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8244b7f0
	ctx.lr = 0x8244CC44;
	sub_8244B7F0(ctx, base);
	// b 0x8244cc74
	goto loc_8244CC74;
loc_8244CC48:
	// lhz r24,0(r4)
	r24.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8244cc88
	if (!cr6.eq) goto loc_8244CC88;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8244b770
	ctx.lr = 0x8244CC5C;
	sub_8244B770(ctx, base);
	// b 0x8244cc74
	goto loc_8244CC74;
loc_8244CC60:
	// lbz r24,0(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8244cc88
	if (!cr6.eq) goto loc_8244CC88;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8244b6f8
	ctx.lr = 0x8244CC74;
	sub_8244B6F8(ctx, base);
loc_8244CC74:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244c8a8
	if (cr6.lt) goto loc_8244C8A8;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_8244CC88:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244cc9c
	if (!cr6.eq) goto loc_8244CC9C;
	// lhz r28,90(r1)
	r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
loc_8244CC9C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8244cca8
	if (cr6.eq) goto loc_8244CCA8;
	// add r20,r28,r20
	r20.u64 = r28.u64 + r20.u64;
loc_8244CCA8:
	// rlwinm. r11,r9,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244cd34
	if (cr0.eq) goto loc_8244CD34;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244be10
	ctx.lr = 0x8244CCBC;
	sub_8244BE10(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lhz r4,126(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 126);
	// lwz r3,48(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// bl 0x8244c280
	ctx.lr = 0x8244CCD4;
	sub_8244C280(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// lbz r11,124(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 124);
	// addi r8,r1,124
	ctx.r8.s64 = ctx.r1.s64 + 124;
	// lwz r9,8(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// rlwinm r5,r11,26,6,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3FFFFFF;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// slw r11,r18,r5
	r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r5.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r3,r27,56
	ctx.r3.s64 = r27.s64 + 56;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// bl 0x8244ce20
	ctx.lr = 0x8244CD10;
	sub_8244CE20(ctx, base);
	// b 0x8244c958
	goto loc_8244C958;
loc_8244CD14:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244cd30
	if (!cr6.eq) goto loc_8244CD30;
	// lhz r11,90(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// add r20,r11,r20
	r20.u64 = r11.u64 + r20.u64;
	// b 0x8244cd34
	goto loc_8244CD34;
loc_8244CD30:
	// lwz r20,104(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_8244CD34:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm r11,r11,0,28,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8244cd50
	if (!cr6.eq) goto loc_8244CD50;
	// clrlwi r11,r22,16
	r11.u64 = r22.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r22,r11,16
	r22.u64 = r11.u32 & 0xFFFF;
loc_8244CD50:
	// rlwinm r11,r9,0,28,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x8244c840
	if (!cr6.eq) goto loc_8244C840;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// cmplw cr6,r17,r11
	cr6.compare<uint32_t>(r17.u32, r11.u32, xer);
	// bge cr6,0x8244cd8c
	if (!cr6.lt) goto loc_8244CD8C;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244b5a8
	ctx.lr = 0x8244CD78;
	sub_8244B5A8(ctx, base);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplw cr6,r17,r11
	cr6.compare<uint32_t>(r17.u32, r11.u32, xer);
	// bge cr6,0x8244cd8c
	if (!cr6.lt) goto loc_8244CD8C;
	// lwz r28,332(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// b 0x8244c828
	goto loc_8244C828;
loc_8244CD8C:
	// lwz r29,340(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
loc_8244CD90:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244cdb4
	if (cr0.eq) goto loc_8244CDB4;
	// lbz r11,96(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// addi r3,r27,56
	ctx.r3.s64 = r27.s64 + 56;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// bl 0x8244cef0
	ctx.lr = 0x8244CDAC;
	sub_8244CEF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
loc_8244CDB4:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8244cde8
	if (!cr6.eq) goto loc_8244CDE8;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8244b5a8
	ctx.lr = 0x8244CDCC;
	sub_8244B5A8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244bee8
	ctx.lr = 0x8244CDE0;
	sub_8244BEE8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244c8a8
	if (cr0.lt) goto loc_8244C8A8;
loc_8244CDE8:
	// stw r20,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r20.u32);
	// b 0x8244c8a8
	goto loc_8244C8A8;
}

__attribute__((alias("__imp__sub_8244CDF0"))) PPC_WEAK_FUNC(sub_8244CDF0);
PPC_FUNC_IMPL(__imp__sub_8244CDF0) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244c620
	ctx.lr = 0x8244CE10;
	sub_8244C620(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244CE20"))) PPC_WEAK_FUNC(sub_8244CE20);
PPC_FUNC_IMPL(__imp__sub_8244CE20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,64
	cr6.compare<uint32_t>(ctx.r4.u32, 64, xer);
	// bge cr6,0x8244ce90
	if (!cr6.lt) goto loc_8244CE90;
	// cmplwi cr6,r5,3
	cr6.compare<uint32_t>(ctx.r5.u32, 3, xer);
	// bgt cr6,0x8244ce90
	if (cr6.gt) goto loc_8244CE90;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8244ce50
	if (cr0.eq) goto loc_8244CE50;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
loc_8244CE50:
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8244ce78
	if (cr6.eq) goto loc_8244CE78;
	// lbz r8,1(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// clrlwi. r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8244ce78
	if (cr0.eq) goto loc_8244CE78;
	// slw r8,r10,r5
	ctx.r8.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r5.u8 & 0x3F));
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// divdu r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 / ctx.r8.u64;
	// tdllei r8,0
loc_8244CE78:
	// rlwimi r5,r10,31,0,29
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 31) & 0xFFFFFFFC) | (ctx.r5.u64 & 0xFFFFFFFF00000003);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// std r6,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r6.u64);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// blr 
	return;
loc_8244CE90:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244CE9C"))) PPC_WEAK_FUNC(sub_8244CE9C);
PPC_FUNC_IMPL(__imp__sub_8244CE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244CEA0"))) PPC_WEAK_FUNC(sub_8244CEA0);
PPC_FUNC_IMPL(__imp__sub_8244CEA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,64
	cr6.compare<uint32_t>(ctx.r4.u32, 64, xer);
	// blt cr6,0x8244ceb4
	if (cr6.lt) goto loc_8244CEB4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_8244CEB4:
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8244cee4
	if (cr0.eq) goto loc_8244CEE4;
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8244cee4
	if (!cr0.eq) goto loc_8244CEE4;
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8244CEE4:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244CEF0"))) PPC_WEAK_FUNC(sub_8244CEF0);
PPC_FUNC_IMPL(__imp__sub_8244CEF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,64
	cr6.compare<uint32_t>(ctx.r4.u32, 64, xer);
	// blt cr6,0x8244cf08
	if (cr6.lt) goto loc_8244CF08;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_8244CF08:
	// cmplwi cr6,r4,63
	cr6.compare<uint32_t>(ctx.r4.u32, 63, xer);
	// bne cr6,0x8244cf18
	if (!cr6.eq) goto loc_8244CF18;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8244CF18:
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm. r8,r11,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8244cf40
	if (cr0.eq) goto loc_8244CF40;
	// rlwinm. r8,r11,0,1,1
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8244cf40
	if (cr0.eq) goto loc_8244CF40;
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// blr 
	return;
loc_8244CF40:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244CF4C"))) PPC_WEAK_FUNC(sub_8244CF4C);
PPC_FUNC_IMPL(__imp__sub_8244CF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244CF50"))) PPC_WEAK_FUNC(sub_8244CF50);
PPC_FUNC_IMPL(__imp__sub_8244CF50) {
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
	ctx.lr = 0x8244CF58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8244be68
	ctx.lr = 0x8244CF7C;
	sub_8244BE68(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d048
	if (cr0.lt) goto loc_8244D048;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// cmplwi cr6,r10,63
	cr6.compare<uint32_t>(ctx.r10.u32, 63, xer);
	// beq cr6,0x8244d048
	if (cr6.eq) goto loc_8244D048;
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244d020
	if (cr0.eq) goto loc_8244D020;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244b9a8
	ctx.lr = 0x8244CFA8;
	sub_8244B9A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d048
	if (cr0.lt) goto loc_8244D048;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lhz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8244c280
	ctx.lr = 0x8244CFC0;
	sub_8244C280(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d048
	if (cr0.lt) goto loc_8244D048;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// clrlwi r10,r29,30
	ctx.r10.u64 = r29.u32 & 0x3;
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// cmplwi cr6,r11,64
	cr6.compare<uint32_t>(r11.u32, 64, xer);
	// bge cr6,0x8244d050
	if (!cr6.lt) goto loc_8244D050;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bgt cr6,0x8244d050
	if (cr6.gt) goto loc_8244D050;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm. r9,r9,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8244d004
	if (cr0.eq) goto loc_8244D004;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8244d048
	goto loc_8244D048;
loc_8244D004:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwimi r10,r8,31,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 31) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
loc_8244D020:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// clrlwi r4,r11,26
	ctx.r4.u64 = r11.u32 & 0x3F;
	// bl 0x8244cea0
	ctx.lr = 0x8244D034;
	sub_8244CEA0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d048
	if (cr0.lt) goto loc_8244D048;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ld r11,8(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_8244D048:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8244D050:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x8244d048
	goto loc_8244D048;
}

__attribute__((alias("__imp__sub_8244D05C"))) PPC_WEAK_FUNC(sub_8244D05C);
PPC_FUNC_IMPL(__imp__sub_8244D05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D060"))) PPC_WEAK_FUNC(sub_8244D060);
PPC_FUNC_IMPL(__imp__sub_8244D060) {
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
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// std r5,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// slw r6,r10,r11
	ctx.r6.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x8244b588
	ctx.lr = 0x8244D0AC;
	sub_8244B588(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8244d118
	if (cr6.lt) goto loc_8244D118;
	// beq cr6,0x8244d0fc
	if (cr6.eq) goto loc_8244D0FC;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8244d0e0
	if (cr6.lt) goto loc_8244D0E0;
	// bne cr6,0x8244d134
	if (!cr6.eq) goto loc_8244D134;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244b878
	ctx.lr = 0x8244D0DC;
	sub_8244B878(ctx, base);
	// b 0x8244d130
	goto loc_8244D130;
loc_8244D0E0:
	// ld r11,176(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x8244b7f0
	ctx.lr = 0x8244D0F8;
	sub_8244B7F0(ctx, base);
	// b 0x8244d130
	goto loc_8244D130;
loc_8244D0FC:
	// ld r11,176(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r11,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r11.u16);
	// bl 0x8244b770
	ctx.lr = 0x8244D114;
	sub_8244B770(ctx, base);
	// b 0x8244d130
	goto loc_8244D130;
loc_8244D118:
	// ld r11,176(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// bl 0x8244b6f8
	ctx.lr = 0x8244D130;
	sub_8244B6F8(ctx, base);
loc_8244D130:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8244D134:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_8244D150"))) PPC_WEAK_FUNC(sub_8244D150);
PPC_FUNC_IMPL(__imp__sub_8244D150) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8244D158;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,16
	cr6.compare<uint32_t>(ctx.r5.u32, 16, xer);
	// bge cr6,0x8244d18c
	if (!cr6.lt) goto loc_8244D18C;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8244d2f8
	if (cr6.eq) goto loc_8244D2F8;
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// cmplwi r5,0
	cr0.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq 0x8244d2f8
	if (cr0.eq) goto loc_8244D2F8;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
loc_8244D17C:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8244d17c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8244D17C;
	// b 0x8244d2f8
	goto loc_8244D2F8;
loc_8244D18C:
	// neg r10,r3
	ctx.r10.s64 = -ctx.r3.s64;
	// vspltisb v0,4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x4)));
	// lvsl v13,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// srawi r9,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// srawi r8,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 4;
	// clrlwi. r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvsl v12,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// clrlwi r9,r9,29
	ctx.r9.u64 = ctx.r9.u32 & 0x7;
	// vslb v0,v12,v0
	ctx.v0.u8[0] = ctx.v12.u8[0] << (ctx.v0.u8[0] & 0x7);
	ctx.v0.u8[1] = ctx.v12.u8[1] << (ctx.v0.u8[1] & 0x7);
	ctx.v0.u8[2] = ctx.v12.u8[2] << (ctx.v0.u8[2] & 0x7);
	ctx.v0.u8[3] = ctx.v12.u8[3] << (ctx.v0.u8[3] & 0x7);
	ctx.v0.u8[4] = ctx.v12.u8[4] << (ctx.v0.u8[4] & 0x7);
	ctx.v0.u8[5] = ctx.v12.u8[5] << (ctx.v0.u8[5] & 0x7);
	ctx.v0.u8[6] = ctx.v12.u8[6] << (ctx.v0.u8[6] & 0x7);
	ctx.v0.u8[7] = ctx.v12.u8[7] << (ctx.v0.u8[7] & 0x7);
	ctx.v0.u8[8] = ctx.v12.u8[8] << (ctx.v0.u8[8] & 0x7);
	ctx.v0.u8[9] = ctx.v12.u8[9] << (ctx.v0.u8[9] & 0x7);
	ctx.v0.u8[10] = ctx.v12.u8[10] << (ctx.v0.u8[10] & 0x7);
	ctx.v0.u8[11] = ctx.v12.u8[11] << (ctx.v0.u8[11] & 0x7);
	ctx.v0.u8[12] = ctx.v12.u8[12] << (ctx.v0.u8[12] & 0x7);
	ctx.v0.u8[13] = ctx.v12.u8[13] << (ctx.v0.u8[13] & 0x7);
	ctx.v0.u8[14] = ctx.v12.u8[14] << (ctx.v0.u8[14] & 0x7);
	ctx.v0.u8[15] = ctx.v12.u8[15] << (ctx.v0.u8[15] & 0x7);
	// vor v0,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltb v0,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_set1_epi8(char(0xF))));
	// beq 0x8244d1c8
	if (cr0.eq) goto loc_8244D1C8;
	// stvlx v0,0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v0.u8[15 - i]);
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_8244D1C8:
	// rlwinm r10,r5,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244d1d8
	if (!cr6.lt) goto loc_8244D1D8;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8244D1D8:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r6,14476(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14476);
	// beq cr6,0x8244d1fc
	if (cr6.eq) goto loc_8244D1FC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8244D1EC:
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// bne 0x8244d1ec
	if (!cr0.eq) goto loc_8244D1EC;
loc_8244D1FC:
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi. r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r7,r10,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r10.s64;
	// rlwinm r9,r7,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// bne 0x8244d230
	if (!cr0.eq) goto loc_8244D230;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d2cc
	if (cr6.eq) goto loc_8244D2CC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8244D21C:
	// dcbzl r0,r11
	memset(base + ((r11.u32) & ~127), 0, 128);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// bne 0x8244d21c
	if (!cr0.eq) goto loc_8244D21C;
	// b 0x8244d2cc
	goto loc_8244D2CC;
loc_8244D230:
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// blt cr6,0x8244d240
	if (cr6.lt) goto loc_8244D240;
	// li r8,4
	ctx.r8.s64 = 4;
loc_8244D240:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8244d260
	if (cr6.eq) goto loc_8244D260;
loc_8244D24C:
	// rlwinm r5,r10,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// dcbzl r5,r11
	memset(base + ((ctx.r5.u32 + r11.u32) & ~127), 0, 128);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x8244d24c
	if (cr6.lt) goto loc_8244D24C;
loc_8244D260:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d2cc
	if (cr6.eq) goto loc_8244D2CC;
loc_8244D26C:
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244d280
	if (!cr6.lt) goto loc_8244D280;
	// li r8,512
	ctx.r8.s64 = 512;
	// dcbzl r8,r11
	memset(base + ((ctx.r8.u32 + r11.u32) & ~127), 0, 128);
loc_8244D280:
	// li r8,16
	ctx.r8.s64 = 16;
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,48
	ctx.r4.s64 = 48;
	// li r31,64
	r31.s64 = 64;
	// li r30,80
	r30.s64 = 80;
	// stvx128 v0,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,96
	r29.s64 = 96;
	// li r8,112
	ctx.r8.s64 = 112;
	// stvx128 v0,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stvx128 v0,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stvx128 v0,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// blt cr6,0x8244d26c
	if (cr6.lt) goto loc_8244D26C;
loc_8244D2CC:
	// rlwinm r10,r9,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// blt cr6,0x8244d2f4
	if (cr6.lt) goto loc_8244D2F4;
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
loc_8244D2E0:
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bne 0x8244d2e0
	if (!cr0.eq) goto loc_8244D2E0;
loc_8244D2F4:
	// stvrx v0,r11,r10
	ea = r11.u32 + ctx.r10.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v0.u8[i]);
loc_8244D2F8:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244D2FC"))) PPC_WEAK_FUNC(sub_8244D2FC);
PPC_FUNC_IMPL(__imp__sub_8244D2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D300"))) PPC_WEAK_FUNC(sub_8244D300);
PPC_FUNC_IMPL(__imp__sub_8244D300) {
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8244D308;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// rlwinm r9,r5,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x8244d338
	if (!cr6.eq) goto loc_8244D338;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d3f4
	if (cr6.eq) goto loc_8244D3F4;
loc_8244D324:
	// dcbzl r0,r11
	memset(base + ((r11.u32) & ~127), 0, 128);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// bne 0x8244d324
	if (!cr0.eq) goto loc_8244D324;
	// b 0x823d9248
	return;
loc_8244D338:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// blt cr6,0x8244d348
	if (cr6.lt) goto loc_8244D348;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8244D348:
	// srawi r7,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 4;
	// vspltisb v0,4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x4)));
	// lvsl v13,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvsl v12,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vslb v11,v12,v0
	ctx.v11.u8[0] = ctx.v12.u8[0] << (ctx.v0.u8[0] & 0x7);
	ctx.v11.u8[1] = ctx.v12.u8[1] << (ctx.v0.u8[1] & 0x7);
	ctx.v11.u8[2] = ctx.v12.u8[2] << (ctx.v0.u8[2] & 0x7);
	ctx.v11.u8[3] = ctx.v12.u8[3] << (ctx.v0.u8[3] & 0x7);
	ctx.v11.u8[4] = ctx.v12.u8[4] << (ctx.v0.u8[4] & 0x7);
	ctx.v11.u8[5] = ctx.v12.u8[5] << (ctx.v0.u8[5] & 0x7);
	ctx.v11.u8[6] = ctx.v12.u8[6] << (ctx.v0.u8[6] & 0x7);
	ctx.v11.u8[7] = ctx.v12.u8[7] << (ctx.v0.u8[7] & 0x7);
	ctx.v11.u8[8] = ctx.v12.u8[8] << (ctx.v0.u8[8] & 0x7);
	ctx.v11.u8[9] = ctx.v12.u8[9] << (ctx.v0.u8[9] & 0x7);
	ctx.v11.u8[10] = ctx.v12.u8[10] << (ctx.v0.u8[10] & 0x7);
	ctx.v11.u8[11] = ctx.v12.u8[11] << (ctx.v0.u8[11] & 0x7);
	ctx.v11.u8[12] = ctx.v12.u8[12] << (ctx.v0.u8[12] & 0x7);
	ctx.v11.u8[13] = ctx.v12.u8[13] << (ctx.v0.u8[13] & 0x7);
	ctx.v11.u8[14] = ctx.v12.u8[14] << (ctx.v0.u8[14] & 0x7);
	ctx.v11.u8[15] = ctx.v12.u8[15] << (ctx.v0.u8[15] & 0x7);
	// vor v10,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vspltb v0,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_set1_epi8(char(0xF))));
	// beq cr6,0x8244d384
	if (cr6.eq) goto loc_8244D384;
loc_8244D370:
	// rlwinm r8,r11,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// dcbzl r8,r3
	memset(base + ((ctx.r8.u32 + ctx.r3.u32) & ~127), 0, 128);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8244d370
	if (cr6.lt) goto loc_8244D370;
loc_8244D384:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d3f4
	if (cr6.eq) goto loc_8244D3F4;
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// li r30,-32
	r30.s64 = -32;
	// li r31,-16
	r31.s64 = -16;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r8,80
	ctx.r8.s64 = 80;
loc_8244D3B0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8244d3c8
	if (!cr6.lt) goto loc_8244D3C8;
	// addi r29,r11,-32
	r29.s64 = r11.s64 + -32;
	// li r28,128
	r28.s64 = 128;
	// dcbzl r28,r29
	memset(base + ((r28.u32 + r29.u32) & ~127), 0, 128);
loc_8244D3C8:
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stvx128 v0,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// blt cr6,0x8244d3b0
	if (cr6.lt) goto loc_8244D3B0;
loc_8244D3F4:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244D3F8"))) PPC_WEAK_FUNC(sub_8244D3F8);
PPC_FUNC_IMPL(__imp__sub_8244D3F8) {
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
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8244D400;
	// cmplwi cr6,r5,1024
	cr6.compare<uint32_t>(ctx.r5.u32, 1024, xer);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// blt cr6,0x8244d410
	if (cr6.lt) goto loc_8244D410;
	// li r10,1024
	ctx.r10.s64 = 1024;
loc_8244D410:
	// cmplwi cr6,r5,128
	cr6.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// blt cr6,0x8244d420
	if (cr6.lt) goto loc_8244D420;
	// li r9,128
	ctx.r9.s64 = 128;
loc_8244D420:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8244d43c
	if (cr6.eq) goto loc_8244D43C;
loc_8244D42C:
	// dcbt r11,r4
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8244d42c
	if (cr6.lt) goto loc_8244D42C;
loc_8244D43C:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d458
	if (cr6.eq) goto loc_8244D458;
loc_8244D448:
	// dcbzl r11,r3
	memset(base + ((r11.u32 + ctx.r3.u32) & ~127), 0, 128);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8244d448
	if (cr6.lt) goto loc_8244D448;
loc_8244D458:
	// cmplwi cr6,r5,128
	cr6.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// blt cr6,0x8244d508
	if (cr6.lt) goto loc_8244D508;
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// subf r28,r4,r3
	r28.s64 = ctx.r3.s64 - ctx.r4.s64;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// li r4,-32
	ctx.r4.s64 = -32;
	// li r29,-16
	r29.s64 = -16;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r30,80
	r30.s64 = 80;
	// li r31,-48
	r31.s64 = -48;
loc_8244D48C:
	// cmplwi cr6,r5,1024
	cr6.compare<uint32_t>(ctx.r5.u32, 1024, xer);
	// ble cr6,0x8244d4a0
	if (!cr6.gt) goto loc_8244D4A0;
	// addi r27,r11,-32
	r27.s64 = r11.s64 + -32;
	// li r26,1024
	r26.s64 = 1024;
	// dcbt r26,r27
loc_8244D4A0:
	// cmplwi cr6,r5,256
	cr6.compare<uint32_t>(ctx.r5.u32, 256, xer);
	// ble cr6,0x8244d4b4
	if (!cr6.gt) goto loc_8244D4B4;
	// addi r27,r10,-48
	r27.s64 = ctx.r10.s64 + -48;
	// li r26,128
	r26.s64 = 128;
	// dcbzl r26,r27
	memset(base + ((r26.u32 + r27.u32) & ~127), 0, 128);
loc_8244D4B4:
	// addi r5,r5,-128
	ctx.r5.s64 = ctx.r5.s64 + -128;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r5,128
	cr6.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// lvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r28,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// stvx128 v62,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// bge cr6,0x8244d48c
	if (!cr6.lt) goto loc_8244D48C;
loc_8244D508:
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8244D50C"))) PPC_WEAK_FUNC(sub_8244D50C);
PPC_FUNC_IMPL(__imp__sub_8244D50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D510"))) PPC_WEAK_FUNC(sub_8244D510);
PPC_FUNC_IMPL(__imp__sub_8244D510) {
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
	ctx.lr = 0x8244D518;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// neg r11,r27
	r11.s64 = -r27.s64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// clrlwi r30,r11,25
	r30.u64 = r11.u32 & 0x7F;
	// cmplwi cr6,r31,256
	cr6.compare<uint32_t>(r31.u32, 256, xer);
	// bge cr6,0x8244d548
	if (!cr6.lt) goto loc_8244D548;
	// bl 0x823da950
	ctx.lr = 0x8244D540;
	sub_823DA950(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8244D548:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8244d56c
	if (cr6.eq) goto loc_8244D56C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x8244D560;
	sub_823DA950(ctx, base);
	// add r28,r30,r27
	r28.u64 = r30.u64 + r27.u64;
	// add r29,r30,r29
	r29.u64 = r30.u64 + r29.u64;
	// subf r31,r30,r31
	r31.s64 = r31.s64 - r30.s64;
loc_8244D56C:
	// rlwinm r30,r31,0,0,24
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFF80;
	// clrlwi r11,r29,28
	r11.u64 = r29.u32 & 0xF;
	// clrlwi r31,r31,25
	r31.u64 = r31.u32 & 0x7F;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// beq cr6,0x8244d594
	if (cr6.eq) goto loc_8244D594;
	// bl 0x82458654
	ctx.lr = 0x8244D590;
	sub_82458654(ctx, base);
	// b 0x8244d598
	goto loc_8244D598;
loc_8244D594:
	// bl 0x82458330
	ctx.lr = 0x8244D598;
	sub_82458330(ctx, base);
loc_8244D598:
	// add r3,r30,r28
	ctx.r3.u64 = r30.u64 + r28.u64;
	// add r4,r30,r29
	ctx.r4.u64 = r30.u64 + r29.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8244d5b0
	if (cr6.eq) goto loc_8244D5B0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x8244D5B0;
	sub_823DA950(ctx, base);
loc_8244D5B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8244D5BC"))) PPC_WEAK_FUNC(sub_8244D5BC);
PPC_FUNC_IMPL(__imp__sub_8244D5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D5C0"))) PPC_WEAK_FUNC(sub_8244D5C0);
PPC_FUNC_IMPL(__imp__sub_8244D5C0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8244D5C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// bge cr6,0x8244d680
	if (!cr6.lt) goto loc_8244D680;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// blt cr6,0x8244d60c
	if (cr6.lt) goto loc_8244D60C;
	// clrlwi r11,r4,29
	r11.u64 = ctx.r4.u32 & 0x7;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8244d60c
	if (!cr6.eq) goto loc_8244D60C;
	// ld r11,0(r4)
	r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// addi r30,r26,8
	r30.s64 = r26.s64 + 8;
	// addi r31,r4,8
	r31.s64 = ctx.r4.s64 + 8;
	// addi r29,r29,-8
	r29.s64 = r29.s64 + -8;
	// std r11,0(r26)
	PPC_STORE_U64(r26.u32 + 0, r11.u64);
loc_8244D60C:
	// clrlwi r11,r31,30
	r11.u64 = r31.u32 & 0x3;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8244d64c
	if (!cr6.eq) goto loc_8244D64C;
	// cmplwi cr6,r29,4
	cr6.compare<uint32_t>(r29.u32, 4, xer);
	// blt cr6,0x8244d64c
	if (cr6.lt) goto loc_8244D64C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r5,r29,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r28,r29,30,2,31
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x823dadd8
	ctx.lr = 0x8244D634;
	sub_823DADD8(ctx, base);
	// rlwinm r11,r29,0,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFFC;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_8244D640:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// bne 0x8244d640
	if (!cr0.eq) goto loc_8244D640;
loc_8244D64C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244d894
	if (cr6.eq) goto loc_8244D894;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,14480(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14480);
loc_8244D65C:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// subf. r29,r11,r29
	r29.s64 = r29.s64 - r11.s64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stb r10,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x8244d65c
	if (!cr0.eq) goto loc_8244D65C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8244D680:
	// neg r11,r26
	r11.s64 = -r26.s64;
	// cmplwi cr6,r29,1024
	cr6.compare<uint32_t>(r29.u32, 1024, xer);
	// srawi r9,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	ctx.r9.s64 = r11.s32 >> 4;
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// blt cr6,0x8244d6a0
	if (cr6.lt) goto loc_8244D6A0;
	// li r9,1024
	ctx.r9.s64 = 1024;
loc_8244D6A0:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8244d6bc
	if (cr6.eq) goto loc_8244D6BC;
loc_8244D6AC:
	// dcbt r11,r4
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8244d6ac
	if (cr6.lt) goto loc_8244D6AC;
loc_8244D6BC:
	// li r27,15
	r27.s64 = 15;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8244d6e8
	if (cr6.eq) goto loc_8244D6E8;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r10,r4
	r31.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvx128 v62,r4,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r29,r10,r29
	r29.s64 = r29.s64 - ctx.r10.s64;
	// lvsl v0,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r30,r10,r26
	r30.u64 = ctx.r10.u64 + r26.u64;
	// vperm128 v63,v63,v62,v0
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvlx128 v63,r0,r26
	ea = r26.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v63.u8[15 - i]);
loc_8244D6E8:
	// rlwinm r11,r29,28,4,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 28) & 0xFFFFFFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bge cr6,0x8244d6f8
	if (!cr6.lt) goto loc_8244D6F8;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_8244D6F8:
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// rlwinm r28,r10,0,0,24
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r28,128
	cr6.compare<uint32_t>(r28.u32, 128, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// blt cr6,0x8244d714
	if (cr6.lt) goto loc_8244D714;
	// li r10,128
	ctx.r10.s64 = 128;
loc_8244D714:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8244d734
	if (cr6.eq) goto loc_8244D734;
	// addi r9,r30,127
	ctx.r9.s64 = r30.s64 + 127;
loc_8244D724:
	// dcbzl r11,r9
	memset(base + ((r11.u32 + ctx.r9.u32) & ~127), 0, 128);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8244d724
	if (cr6.lt) goto loc_8244D724;
loc_8244D734:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvsl v0,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8244d76c
	if (cr6.eq) goto loc_8244D76C;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8244D74C:
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// vperm128 v62,v63,v62,v0
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x8244d74c
	if (!cr0.eq) goto loc_8244D74C;
loc_8244D76C:
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r10,r31,28
	ctx.r10.u64 = r31.u32 & 0xF;
	// subf r29,r11,r29
	r29.s64 = r29.s64 - r11.s64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8244d81c
	if (!cr6.eq) goto loc_8244D81C;
	// cmplwi cr6,r29,128
	cr6.compare<uint32_t>(r29.u32, 128, xer);
	// blt cr6,0x8244d840
	if (cr6.lt) goto loc_8244D840;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,64
	ctx.r8.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r11,112
	r11.s64 = 112;
loc_8244D7A4:
	// cmplwi cr6,r29,1024
	cr6.compare<uint32_t>(r29.u32, 1024, xer);
	// ble cr6,0x8244d7b4
	if (!cr6.gt) goto loc_8244D7B4;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// dcbt r4,r31
loc_8244D7B4:
	// cmplwi cr6,r29,256
	cr6.compare<uint32_t>(r29.u32, 256, xer);
	// ble cr6,0x8244d7c4
	if (!cr6.gt) goto loc_8244D7C4;
	// li r4,128
	ctx.r4.s64 = 128;
	// dcbzl r4,r30
	memset(base + ((ctx.r4.u32 + r30.u32) & ~127), 0, 128);
loc_8244D7C4:
	// addi r29,r29,-128
	r29.s64 = r29.s64 + -128;
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r29,128
	cr6.compare<uint32_t>(r29.u32, 128, xer);
	// lvx128 v58,r31,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r31,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r31,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r31,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r31,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,128
	r31.s64 = r31.s64 + 128;
	// stvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r30,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,128
	r30.s64 = r30.s64 + 128;
	// bge cr6,0x8244d7a4
	if (!cr6.lt) goto loc_8244D7A4;
	// b 0x8244d840
	goto loc_8244D840;
loc_8244D81C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824593d0
	ctx.lr = 0x8244D82C;
	sub_824593D0(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// add r30,r28,r30
	r30.u64 = r28.u64 + r30.u64;
	// add r31,r28,r31
	r31.u64 = r28.u64 + r31.u64;
	// subf r29,r28,r29
	r29.s64 = r29.s64 - r28.s64;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8244D840:
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// blt cr6,0x8244d870
	if (cr6.lt) goto loc_8244D870;
	// rlwinm r11,r29,28,4,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 28) & 0xFFFFFFF;
loc_8244D84C:
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r29,-16
	r29.s64 = r29.s64 + -16;
	// vperm128 v53,v63,v62,v0
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// stvx128 v53,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x8244d84c
	if (!cr0.eq) goto loc_8244D84C;
loc_8244D870:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244d894
	if (cr6.eq) goto loc_8244D894;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// lvx128 v52,r0,r31
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,-1
	ctx.r10.s64 = -1;
	// lvsl v0,r31,r29
	temp.u32 = r31.u32 + r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// lvx128 v51,r11,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v50,v52,v51,v0
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvrx128 v50,r30,r29
	ea = r30.u32 + r29.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v50.u8[i]);
loc_8244D894:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8244D8A0"))) PPC_WEAK_FUNC(sub_8244D8A0);
PPC_FUNC_IMPL(__imp__sub_8244D8A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x827bcf94
	ctx.lr = 0x8244D8C4;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d8d4
	if (cr0.lt) goto loc_8244D8D4;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x8244d8dc
	goto loc_8244D8DC;
loc_8244D8D4:
	// bl 0x82135d58
	ctx.lr = 0x8244D8D8;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244D8DC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244D8EC"))) PPC_WEAK_FUNC(sub_8244D8EC);
PPC_FUNC_IMPL(__imp__sub_8244D8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D8F0"))) PPC_WEAK_FUNC(sub_8244D8F0);
PPC_FUNC_IMPL(__imp__sub_8244D8F0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r11,1968(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1968);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8244d92c
	if (!cr6.eq) goto loc_8244D92C;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,309
	ctx.r3.u64 = ctx.r3.u64 | 309;
	// b 0x8244d958
	goto loc_8244D958;
loc_8244D92C:
	// lis r4,4
	ctx.r4.s64 = 262144;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// ori r4,r4,6
	ctx.r4.u64 = ctx.r4.u64 | 6;
	// bl 0x827bcf74
	ctx.lr = 0x8244D93C;
	__imp__RtlImageXexHeaderField(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8244d950
	if (cr0.eq) goto loc_8244D950;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8244d958
	goto loc_8244D958;
loc_8244D950:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,549
	ctx.r3.u64 = ctx.r3.u64 | 549;
loc_8244D958:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8244D96C"))) PPC_WEAK_FUNC(sub_8244D96C);
PPC_FUNC_IMPL(__imp__sub_8244D96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244D970"))) PPC_WEAK_FUNC(sub_8244D970);
PPC_FUNC_IMPL(__imp__sub_8244D970) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x8244d8f0
	ctx.lr = 0x8244D98C;
	sub_8244D8F0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244d9a8
	if (cr0.lt) goto loc_8244D9A8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// lhz r11,14(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// or r31,r10,r11
	r31.u64 = ctx.r10.u64 | r11.u64;
loc_8244D9A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8244D9C0"))) PPC_WEAK_FUNC(sub_8244D9C0);
PPC_FUNC_IMPL(__imp__sub_8244D9C0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r31,556
	ctx.r3.s64 = r31.s64 + 556;
	// bl 0x827bd8f4
	ctx.lr = 0x8244DA00;
	__imp__XeCryptSha(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd8e4
	ctx.lr = 0x8244DA10;
	__imp__XeKeysConsoleSignatureVerification(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8244da28
	if (cr0.eq) goto loc_8244DA28;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8244da2c
	if (!cr6.eq) goto loc_8244DA2C;
loc_8244DA28:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244DA2C:
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

__attribute__((alias("__imp__sub_8244DA40"))) PPC_WEAK_FUNC(sub_8244DA40);
PPC_FUNC_IMPL(__imp__sub_8244DA40) {
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
	ctx.lr = 0x8244DA48;
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,108
	r11.s64 = ctx.r1.s64 + 108;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r5,1023
	ctx.r5.s64 = 1023;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r31.u8);
	// addi r3,r1,177
	ctx.r3.s64 = ctx.r1.s64 + 177;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bl 0x823d9890
	ctx.lr = 0x8244DA74;
	sub_823D9890(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// li r8,34
	ctx.r8.s64 = 34;
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-22900
	r11.s64 = r11.s64 + -22900;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// lis r4,-16368
	ctx.r4.s64 = -1072693248;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd934
	ctx.lr = 0x8244DAB8;
	__imp__NtCreateFile(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244db68
	if (cr0.lt) goto loc_8244DB68;
	// li r10,20
	ctx.r10.s64 = 20;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r30,556
	ctx.r3.s64 = r30.s64 + 556;
	// bl 0x827bd8f4
	ctx.lr = 0x8244DAE4;
	__imp__XeCryptSha(ctx, base);
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x827bd924
	ctx.lr = 0x8244DAF0;
	__imp__XeKeysConsolePrivateKeySign(ctx, base);
	// li r29,2048
	r29.s64 = 2048;
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// std r29,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r29.u64);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd914
	ctx.lr = 0x8244DB1C;
	__imp__NtReadFile(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244db60
	if (cr0.lt) goto loc_8244DB60;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// li r5,644
	ctx.r5.s64 = 644;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8244DB34;
	sub_823DA950(ctx, base);
	// std r29,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r29.u64);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8244DB5C;
	__imp__NtWriteFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8244DB60:
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8244DB68;
	__imp__NtClose(ctx, base);
loc_8244DB68:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244DB74"))) PPC_WEAK_FUNC(sub_8244DB74);
PPC_FUNC_IMPL(__imp__sub_8244DB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244DB78"))) PPC_WEAK_FUNC(sub_8244DB78);
PPC_FUNC_IMPL(__imp__sub_8244DB78) {
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
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r5,1023
	ctx.r5.s64 = 1023;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r30.u8);
	// addi r3,r1,145
	ctx.r3.s64 = ctx.r1.s64 + 145;
	// bl 0x823d9890
	ctx.lr = 0x8244DBA8;
	sub_823D9890(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x823d9890
	ctx.lr = 0x8244DBB8;
	sub_823D9890(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,644
	ctx.r5.s64 = 644;
	// addi r11,r11,12384
	r11.s64 = r11.s64 + 12384;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// bl 0x823d9890
	ctx.lr = 0x8244DBD0;
	sub_823D9890(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// li r8,34
	ctx.r8.s64 = 34;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-22900
	r11.s64 = r11.s64 + -22900;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lis r4,-16368
	ctx.r4.s64 = -1072693248;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd934
	ctx.lr = 0x8244DC14;
	__imp__NtCreateFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244dc50
	if (cr0.lt) goto loc_8244DC50;
	// li r11,2048
	r11.s64 = 2048;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8244DC48;
	__imp__NtWriteFile(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8244DC50;
	__imp__NtClose(ctx, base);
loc_8244DC50:
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
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

__attribute__((alias("__imp__sub_8244DC68"))) PPC_WEAK_FUNC(sub_8244DC68);
PPC_FUNC_IMPL(__imp__sub_8244DC68) {
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
	ctx.lr = 0x8244DC70;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r26,r11,-22916
	r26.s64 = r11.s64 + -22916;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r5,r26,-56
	ctx.r5.s64 = r26.s64 + -56;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827bd944
	ctx.lr = 0x8244DCA4;
	__imp___snprintf(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827bd844
	ctx.lr = 0x8244DCB0;
	__imp__RtlInitAnsiString(ctx, base);
	// li r5,88
	ctx.r5.s64 = 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8244DCC0;
	sub_823D9890(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// addi r24,r31,24
	r24.s64 = r31.s64 + 24;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// li r11,40
	r11.s64 = 40;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827bd934
	ctx.lr = 0x8244DD08;
	__imp__NtCreateFile(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244de6c
	if (cr0.lt) goto loc_8244DE6C;
	// lwz r25,4(r28)
	r25.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r25,5
	cr6.compare<uint32_t>(r25.u32, 5, xer);
	// bge cr6,0x8244dd20
	if (!cr6.lt) goto loc_8244DD20;
	// li r25,5
	r25.s64 = 5;
loc_8244DD20:
	// rlwinm r11,r25,12,0,19
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 12) & 0xFFFFF000;
	// lis r5,144
	ctx.r5.s64 = 9437184;
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// ori r5,r5,12288
	ctx.r5.u64 = ctx.r5.u64 | 12288;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x827bcf94
	ctx.lr = 0x8244DD44;
	__imp__NtAllocateVirtualMemory(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244de6c
	if (cr0.lt) goto loc_8244DE6C;
	// li r7,3
	ctx.r7.s64 = 3;
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r6,24
	ctx.r6.s64 = 24;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x827bd8c4
	ctx.lr = 0x8244DD64;
	__imp__NtQueryVolumeInformationFile(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244de6c
	if (cr0.lt) goto loc_8244DE6C;
	// lwz r11,164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ld r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mulld r30,r11,r9
	r30.s64 = r11.s64 * ctx.r9.s64;
	// bl 0x823dc018
	ctx.lr = 0x8244DD94;
	sub_823DC018(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd844
	ctx.lr = 0x8244DDA0;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,4096
	ctx.r10.s64 = 4096;
	// stb r25,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r25.u8);
	// addi r9,r30,-4096
	ctx.r9.s64 = r30.s64 + -4096;
	// stb r11,82(r31)
	PPC_STORE_U8(r31.u32 + 82, r11.u8);
	// stb r11,81(r31)
	PPC_STORE_U8(r31.u32 + 81, r11.u8);
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// std r10,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r10.u64);
	// addi r29,r31,28
	r29.s64 = r31.s64 + 28;
	// std r9,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r9.u64);
	// mulli r11,r11,36
	r11.s64 = r11.s64 * 36;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x8244DDDC;
	sub_823DA950(ctx, base);
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// li r4,88
	ctx.r4.s64 = 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DDF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8244de2c
	if (!cr0.lt) goto loc_8244DE2C;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x8244DE0C;
	sub_823D9890(ctx, base);
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// li r4,88
	ctx.r4.s64 = 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DE24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244de6c
	if (cr0.lt) goto loc_8244DE6C;
loc_8244DE2C:
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8244de64
	if (cr0.eq) goto loc_8244DE64;
	// lis r10,-32187
	ctx.r10.s64 = -2109407232;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,-9352
	ctx.r10.s64 = ctx.r10.s64 + -9352;
	// li r4,8
	ctx.r4.s64 = 8;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DE64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8244DE64:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8244dea0
	if (!cr6.lt) goto loc_8244DEA0;
loc_8244DE6C:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8244de7c
	if (cr6.eq) goto loc_8244DE7C;
	// bl 0x827bceb4
	ctx.lr = 0x8244DE7C;
	__imp__NtClose(ctx, base);
loc_8244DE7C:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244dea0
	if (cr6.eq) goto loc_8244DEA0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x827bcfd4
	ctx.lr = 0x8244DEA0;
	__imp__NtFreeVirtualMemory(ctx, base);
loc_8244DEA0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8244DEAC"))) PPC_WEAK_FUNC(sub_8244DEAC);
PPC_FUNC_IMPL(__imp__sub_8244DEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244DEB0"))) PPC_WEAK_FUNC(sub_8244DEB0);
PPC_FUNC_IMPL(__imp__sub_8244DEB0) {
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
	ctx.lr = 0x8244DEB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827bd814
	ctx.lr = 0x8244DECC;
	__imp__KeEnterCriticalRegion(ctx, base);
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DEE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DF04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244df7c
	if (cr0.lt) goto loc_8244DF7C;
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// addi r29,r30,28
	r29.s64 = r30.s64 + 28;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DF2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244df7c
	if (cr0.lt) goto loc_8244DF7C;
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DF50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r28,16
	r11.s64 = r28.s64 + 16;
	// li r5,36
	ctx.r5.s64 = 36;
	// mulli r11,r11,36
	r11.s64 = r11.s64 * 36;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x8244DF68;
	sub_823DA950(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x8244da40
	ctx.lr = 0x8244DF70;
	sub_8244DA40(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x827bd954
	ctx.lr = 0x8244DF7C;
	__imp__NtFlushBuffersFile(ctx, base);
loc_8244DF7C:
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244DF98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x827bd7e4
	ctx.lr = 0x8244DF9C;
	__imp__KeLeaveCriticalRegion(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244DFA4"))) PPC_WEAK_FUNC(sub_8244DFA4);
PPC_FUNC_IMPL(__imp__sub_8244DFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244DFA8"))) PPC_WEAK_FUNC(sub_8244DFA8);
PPC_FUNC_IMPL(__imp__sub_8244DFA8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// ori r8,r8,33
	ctx.r8.u64 = ctx.r8.u64 | 33;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd8d4
	ctx.lr = 0x8244DFF8;
	__imp__NtOpenFile(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244e048
	if (cr0.lt) goto loc_8244E048;
	// li r7,3
	ctx.r7.s64 = 3;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,24
	ctx.r6.s64 = 24;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd8c4
	ctx.lr = 0x8244E018;
	__imp__NtQueryVolumeInformationFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bceb4
	ctx.lr = 0x8244E024;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244e048
	if (cr6.lt) goto loc_8244E048;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x8244e048
	if (cr6.eq) goto loc_8244E048;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,335
	r31.u64 = r31.u64 | 335;
loc_8244E048:
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

__attribute__((alias("__imp__sub_8244E064"))) PPC_WEAK_FUNC(sub_8244E064);
PPC_FUNC_IMPL(__imp__sub_8244E064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244E068"))) PPC_WEAK_FUNC(sub_8244E068);
PPC_FUNC_IMPL(__imp__sub_8244E068) {
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
	ctx.lr = 0x8244E070;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// li r5,41
	ctx.r5.s64 = 41;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// addi r3,r1,97
	ctx.r3.s64 = ctx.r1.s64 + 97;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x823d9890
	ctx.lr = 0x8244E09C;
	sub_823D9890(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r28,r11,-22944
	r28.s64 = r11.s64 + -22944;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r28,-28
	ctx.r4.s64 = r28.s64 + -28;
	// bl 0x823dc018
	ctx.lr = 0x8244E0B4;
	sub_823DC018(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244E0C0;
	__imp__RtlInitAnsiString(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x8244E0D0;
	sub_823DC018(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd844
	ctx.lr = 0x8244E0DC;
	__imp__RtlInitAnsiString(ctx, base);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x8244e118
	if (cr6.eq) goto loc_8244E118;
	// mulli r11,r31,36
	r11.s64 = r31.s64 * 36;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,556
	ctx.r3.s64 = r11.s64 + 556;
	// bl 0x823d9890
	ctx.lr = 0x8244E0FC;
	sub_823D9890(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8245fb30
	ctx.lr = 0x8244E108;
	sub_8245FB30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244e118
	if (!cr0.lt) goto loc_8244E118;
loc_8244E110:
	// bl 0x827bd024
	ctx.lr = 0x8244E114;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x8244e170
	goto loc_8244E170;
loc_8244E118:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244dfa8
	ctx.lr = 0x8244E124;
	sub_8244DFA8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244e16c
	if (!cr0.lt) goto loc_8244E16C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8245fb30
	ctx.lr = 0x8244E138;
	sub_8245FB30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244e110
	if (cr0.lt) goto loc_8244E110;
	// mulli r11,r31,36
	r11.s64 = r31.s64 * 36;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,556
	ctx.r3.s64 = r11.s64 + 556;
	// bl 0x823d9890
	ctx.lr = 0x8244E158;
	sub_823D9890(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244dfa8
	ctx.lr = 0x8244E164;
	sub_8244DFA8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244e110
	if (cr0.lt) goto loc_8244E110;
loc_8244E16C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244E170:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8244E178"))) PPC_WEAK_FUNC(sub_8244E178);
PPC_FUNC_IMPL(__imp__sub_8244E178) {
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
	ctx.lr = 0x8244E180;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x827bd944
	ctx.lr = 0x8244E1A4;
	__imp___snprintf(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244E1B0;
	__imp__RtlInitAnsiString(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x827bd944
	ctx.lr = 0x8244E1C4;
	__imp___snprintf(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd844
	ctx.lr = 0x8244E1D0;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd834
	ctx.lr = 0x8244E1DC;
	__imp__ObCreateSymbolicLink(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244E1F8"))) PPC_WEAK_FUNC(sub_8244E1F8);
PPC_FUNC_IMPL(__imp__sub_8244E1F8) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r31,r10,12376
	r31.s64 = ctx.r10.s64 + 12376;
	// addi r30,r11,-23000
	r30.s64 = r11.s64 + -23000;
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e258
	if (cr6.eq) goto loc_8244E258;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd944
	ctx.lr = 0x8244E244;
	__imp___snprintf(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244E250;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd824
	ctx.lr = 0x8244E258;
	__imp__ObDeleteSymbolicLink(ctx, base);
loc_8244E258:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e294
	if (cr6.eq) goto loc_8244E294;
	// li r11,0
	r11.s64 = 0;
	// addi r5,r30,12
	ctx.r5.s64 = r30.s64 + 12;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd944
	ctx.lr = 0x8244E280;
	__imp___snprintf(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244E28C;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd824
	ctx.lr = 0x8244E294;
	__imp__ObDeleteSymbolicLink(ctx, base);
loc_8244E294:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e2d0
	if (cr6.eq) goto loc_8244E2D0;
	// li r11,0
	r11.s64 = 0;
	// addi r5,r30,12
	ctx.r5.s64 = r30.s64 + 12;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd944
	ctx.lr = 0x8244E2BC;
	__imp___snprintf(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244E2C8;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd824
	ctx.lr = 0x8244E2D0;
	__imp__ObDeleteSymbolicLink(ctx, base);
loc_8244E2D0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_8244E2E8"))) PPC_WEAK_FUNC(sub_8244E2E8);
PPC_FUNC_IMPL(__imp__sub_8244E2E8) {
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
	ctx.lr = 0x8244E2F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r10,12376
	r29.s64 = ctx.r10.s64 + 12376;
	// addi r28,r11,-23000
	r28.s64 = r11.s64 + -23000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r7,r29,-4
	ctx.r7.s64 = r29.s64 + -4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244e178
	ctx.lr = 0x8244E324;
	sub_8244E178(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244e378
	if (cr0.lt) goto loc_8244E378;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x8244e370
	if (cr6.eq) goto loc_8244E370;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r3,r28,12
	ctx.r3.s64 = r28.s64 + 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244e178
	ctx.lr = 0x8244E34C;
	sub_8244E178(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8244e378
	if (cr0.lt) goto loc_8244E378;
	// addi r3,r28,12
	ctx.r3.s64 = r28.s64 + 12;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r29,4
	ctx.r7.s64 = r29.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8244e178
	ctx.lr = 0x8244E36C;
	sub_8244E178(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8244E370:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8244e37c
	if (!cr6.lt) goto loc_8244E37C;
loc_8244E378:
	// bl 0x8244e1f8
	ctx.lr = 0x8244E37C;
	sub_8244E1F8(ctx, base);
loc_8244E37C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8244E388"))) PPC_WEAK_FUNC(sub_8244E388);
PPC_FUNC_IMPL(__imp__sub_8244E388) {
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
	ctx.lr = 0x8244E390;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,11
	ctx.r3.s64 = 11;
	// li r31,0
	r31.s64 = 0;
	// bl 0x827bcee4
	ctx.lr = 0x8244E3A0;
	__imp__XexCheckExecutablePrivilege(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244e418
	if (!cr0.eq) goto loc_8244E418;
	// bl 0x827bd814
	ctx.lr = 0x8244E3AC;
	__imp__KeEnterCriticalRegion(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r31,r11,14492
	r31.s64 = r11.s64 + 14492;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8244E3BC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r9,14520
	ctx.r3.s64 = ctx.r9.s64 + 14520;
	// stw r11,12384(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12384, r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r30,r10,12384
	r30.s64 = ctx.r10.s64 + 12384;
	// bl 0x827bd564
	ctx.lr = 0x8244E3E0;
	__imp__KeSetEvent(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r29,r11,14536
	r29.s64 = r11.s64 + 14536;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x8244E400;
	__imp__KeWaitForSingleObject(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd874
	ctx.lr = 0x8244E408;
	__imp__KeResetEvent(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x827bcf54
	ctx.lr = 0x8244E414;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x827bd7e4
	ctx.lr = 0x8244E418;
	__imp__KeLeaveCriticalRegion(ctx, base);
loc_8244E418:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244E424"))) PPC_WEAK_FUNC(sub_8244E424);
PPC_FUNC_IMPL(__imp__sub_8244E424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244E428"))) PPC_WEAK_FUNC(sub_8244E428);
PPC_FUNC_IMPL(__imp__sub_8244E428) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,12364(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12364);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e44c
	if (cr6.eq) goto loc_8244E44C;
	// bl 0x8244e388
	ctx.lr = 0x8244E448;
	sub_8244E388(ctx, base);
	// b 0x8244e454
	goto loc_8244E454;
loc_8244E44C:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,622
	ctx.r3.u64 = ctx.r3.u64 | 622;
loc_8244E454:
	// bl 0x827bd024
	ctx.lr = 0x8244E458;
	__imp__RtlNtStatusToDosError(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244E468"))) PPC_WEAK_FUNC(sub_8244E468);
PPC_FUNC_IMPL(__imp__sub_8244E468) {
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
	ctx.lr = 0x8244E470;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,12360
	r31.s64 = r11.s64 + 12360;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e518
	if (cr6.eq) goto loc_8244E518;
	// bl 0x827bd814
	ctx.lr = 0x8244E48C;
	__imp__KeEnterCriticalRegion(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e4b0
	if (cr6.eq) goto loc_8244E4B0;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,14552
	ctx.r3.s64 = ctx.r10.s64 + 14552;
	// bl 0x827bd554
	ctx.lr = 0x8244E4B0;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
loc_8244E4B0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,14492
	r30.s64 = r11.s64 + 14492;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8244E4C0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,2
	r11.s64 = 2;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r9,14520
	ctx.r3.s64 = ctx.r9.s64 + 14520;
	// stw r11,12384(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12384, r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x8244E4E0;
	__imp__KeSetEvent(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r29,r11,14536
	r29.s64 = r11.s64 + 14536;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x8244E500;
	__imp__KeWaitForSingleObject(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd874
	ctx.lr = 0x8244E508;
	__imp__KeResetEvent(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8244E510;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x827bd7e4
	ctx.lr = 0x8244E514;
	__imp__KeLeaveCriticalRegion(ctx, base);
	// b 0x8244e528
	goto loc_8244E528;
loc_8244E518:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e528
	if (cr6.eq) goto loc_8244E528;
	// bl 0x8244e1f8
	ctx.lr = 0x8244E528;
	sub_8244E1F8(ctx, base);
loc_8244E528:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244E538"))) PPC_WEAK_FUNC(sub_8244E538);
PPC_FUNC_IMPL(__imp__sub_8244E538) {
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
	ctx.lr = 0x8244E540;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244e56c
	if (cr6.eq) goto loc_8244E56C;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244E564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8244e570
	goto loc_8244E570;
loc_8244E56C:
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244E570:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r25,r10,14536
	r25.s64 = ctx.r10.s64 + 14536;
	// addi r28,r11,12360
	r28.s64 = r11.s64 + 12360;
	// blt cr6,0x8244e750
	if (cr6.lt) goto loc_8244E750;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8244dc68
	ctx.lr = 0x8244E5A0;
	sub_8244DC68(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244e738
	if (cr0.lt) goto loc_8244E738;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e5d8
	if (cr6.eq) goto loc_8244E5D8;
	// addi r7,r1,274
	ctx.r7.s64 = ctx.r1.s64 + 274;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,184
	ctx.r5.s64 = ctx.r1.s64 + 184;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244dc68
	ctx.lr = 0x8244E5CC;
	sub_8244DC68(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244e6d0
	if (cr0.lt) goto loc_8244E6D0;
	// li r24,1
	r24.s64 = 1;
loc_8244E5D8:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,-22916
	ctx.r4.s64 = r11.s64 + -22916;
	// bl 0x8244e2e8
	ctx.lr = 0x8244E5EC;
	sub_8244E2E8(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8244e6d0
	if (cr0.lt) goto loc_8244E6D0;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r29,r10,14552
	r29.s64 = ctx.r10.s64 + 14552;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd554
	ctx.lr = 0x8244E610;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x8244E62C;
	__imp__KeSetEvent(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r26,r11,14520
	r26.s64 = r11.s64 + 14520;
loc_8244E634:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x8244E64C;
	__imp__KeWaitForSingleObject(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8244deb0
	ctx.lr = 0x8244E660;
	sub_8244DEB0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e67c
	if (cr6.eq) goto loc_8244E67C;
	// addi r5,r1,184
	ctx.r5.s64 = ctx.r1.s64 + 184;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244deb0
	ctx.lr = 0x8244E67C;
	sub_8244DEB0(ctx, base);
loc_8244E67C:
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x8244e698
	if (!cr6.eq) goto loc_8244E698;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x8244E698;
	__imp__KeSetEvent(ctx, base);
loc_8244E698:
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// beq cr6,0x8244e6ac
	if (cr6.eq) goto loc_8244E6AC;
	// bl 0x827bd364
	ctx.lr = 0x8244E6A4;
	__imp__XamTaskShouldExit(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8244e634
	if (cr0.eq) goto loc_8244E634;
loc_8244E6AC:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8244e6cc
	if (cr6.eq) goto loc_8244E6CC;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd554
	ctx.lr = 0x8244E6CC;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
loc_8244E6CC:
	// bl 0x8244e1f8
	ctx.lr = 0x8244E6D0;
	sub_8244E1F8(ctx, base);
loc_8244E6D0:
	// lwz r3,168(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x827bd964
	ctx.lr = 0x8244E6D8;
	__imp__IoDismountVolume(ctx, base);
	// lwz r3,168(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x827bce64
	ctx.lr = 0x8244E6E0;
	__imp__ObDereferenceObject(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x827bcfd4
	ctx.lr = 0x8244E6F8;
	__imp__NtFreeVirtualMemory(ctx, base);
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x827bceb4
	ctx.lr = 0x8244E700;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x8244e738
	if (cr6.eq) goto loc_8244E738;
	// lwz r3,256(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// bl 0x827bd964
	ctx.lr = 0x8244E710;
	__imp__IoDismountVolume(ctx, base);
	// lwz r3,256(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// bl 0x827bce64
	ctx.lr = 0x8244E718;
	__imp__ObDereferenceObject(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// bl 0x827bcfd4
	ctx.lr = 0x8244E730;
	__imp__NtFreeVirtualMemory(ctx, base);
	// lwz r3,208(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// bl 0x827bceb4
	ctx.lr = 0x8244E738;
	__imp__NtClose(ctx, base);
loc_8244E738:
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8244e750
	if (cr6.eq) goto loc_8244E750;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244E750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8244E750:
	// li r11,0
	r11.s64 = 0;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x8244E76C;
	__imp__KeSetEvent(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8244E778"))) PPC_WEAK_FUNC(sub_8244E778);
PPC_FUNC_IMPL(__imp__sub_8244E778) {
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
	ctx.lr = 0x8244E780;
	// stwu r1,-1296(r1)
	ea = -1296 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r5,1023
	ctx.r5.s64 = 1023;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r28,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r28.u8);
	// addi r3,r1,161
	ctx.r3.s64 = ctx.r1.s64 + 161;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// bl 0x823d9890
	ctx.lr = 0x8244E7B0;
	sub_823D9890(ctx, base);
	// lis r19,-32115
	r19.s64 = -2104688640;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// addi r10,r1,116
	ctx.r10.s64 = ctx.r1.s64 + 116;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r24,r28
	r24.u64 = r28.u64;
	// lwz r11,12364(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 12364);
	// stw r28,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r28.u32);
	// stw r28,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bne cr6,0x8244ebd8
	if (!cr6.eq) goto loc_8244EBD8;
	// lis r11,15
	r11.s64 = 983040;
	// ori r11,r11,61440
	r11.u64 = r11.u64 | 61440;
	// cmplw cr6,r21,r11
	cr6.compare<uint32_t>(r21.u32, r11.u32, xer);
	// bgt cr6,0x8244ebd8
	if (cr6.gt) goto loc_8244EBD8;
	// clrlwi. r11,r22,23
	r11.u64 = r22.u32 & 0x1FF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8244ebd8
	if (!cr0.eq) goto loc_8244EBD8;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x827bcee4
	ctx.lr = 0x8244E804;
	__imp__XexCheckExecutablePrivilege(ctx, base);
	// li r20,1
	r20.s64 = 1;
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8244e814
	if (cr0.eq) goto loc_8244E814;
	// mr r24,r20
	r24.u64 = r20.u64;
loc_8244E814:
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r28.u32);
	// li r8,34
	ctx.r8.s64 = 34;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-22900
	r11.s64 = r11.s64 + -22900;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,152
	ctx.r6.s64 = ctx.r1.s64 + 152;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// lis r4,-16368
	ctx.r4.s64 = -1072693248;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827bd934
	ctx.lr = 0x8244E858;
	__imp__NtCreateFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244e868
	if (!cr0.lt) goto loc_8244E868;
loc_8244E860:
	// bl 0x827bd024
	ctx.lr = 0x8244E864;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x8244ebdc
	goto loc_8244EBDC;
loc_8244E868:
	// li r11,2048
	r11.s64 = 2048;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,152
	ctx.r7.s64 = ctx.r1.s64 + 152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd914
	ctx.lr = 0x8244E894;
	__imp__NtReadFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x827bceb4
	ctx.lr = 0x8244E8A0;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8244e8b0
	if (!cr6.lt) goto loc_8244E8B0;
loc_8244E8A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8244e860
	goto loc_8244E860;
loc_8244E8B0:
	// lis r11,19055
	r11.s64 = 1248788480;
	// lwz r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// ori r31,r11,29544
	r31.u64 = r11.u64 | 29544;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x8244e8e0
	if (!cr6.eq) goto loc_8244E8E0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244d9c0
	ctx.lr = 0x8244E8CC;
	sub_8244D9C0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8244e8e0
	if (cr0.eq) goto loc_8244E8E0;
	// lwz r11,788(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8244e8f8
	if (cr6.eq) goto loc_8244E8F8;
loc_8244E8E0:
	// addi r11,r1,796
	r11.s64 = ctx.r1.s64 + 796;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r20,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, r20.u32);
	// ori r29,r29,15
	r29.u64 = r29.u64 | 15;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
loc_8244E8F8:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x8244e964
	if (cr6.eq) goto loc_8244E964;
	// addi r9,r1,717
	ctx.r9.s64 = ctx.r1.s64 + 717;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8244E908:
	// addi r10,r1,796
	ctx.r10.s64 = ctx.r1.s64 + 796;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r25
	cr6.compare<uint32_t>(ctx.r8.u32, r25.u32, xer);
	// bne cr6,0x8244e940
	if (!cr6.eq) goto loc_8244E940;
	// lbz r8,0(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r8,240
	cr6.compare<uint32_t>(ctx.r8.u32, 240, xer);
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// bge cr6,0x8244e938
	if (!cr6.lt) goto loc_8244E938;
	// cmplwi cr6,r8,240
	cr6.compare<uint32_t>(ctx.r8.u32, 240, xer);
	// blt cr6,0x8244e948
	if (cr6.lt) goto loc_8244E948;
	// b 0x8244e940
	goto loc_8244E940;
loc_8244E938:
	// cmplwi cr6,r8,240
	cr6.compare<uint32_t>(ctx.r8.u32, 240, xer);
	// bge cr6,0x8244e948
	if (!cr6.lt) goto loc_8244E948;
loc_8244E940:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stwx r20,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r20.u32);
loc_8244E948:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r25,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r25.u32);
	// addi r9,r9,36
	ctx.r9.s64 = ctx.r9.s64 + 36;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x8244e908
	if (cr6.lt) goto loc_8244E908;
	// mr r30,r28
	r30.u64 = r28.u64;
	// b 0x8244e9dc
	goto loc_8244E9DC;
loc_8244E964:
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r11,r1,796
	r11.s64 = ctx.r1.s64 + 796;
loc_8244E96C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// beq cr6,0x8244e988
	if (cr6.eq) goto loc_8244E988;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// blt cr6,0x8244e96c
	if (cr6.lt) goto loc_8244E96C;
loc_8244E988:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bne cr6,0x8244e9a0
	if (!cr6.eq) goto loc_8244E9A0;
	// lwz r11,792(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 792);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r30,r11,27,31,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x8244e9d0
	goto loc_8244E9D0;
loc_8244E9A0:
	// mulli r10,r30,36
	ctx.r10.s64 = r30.s64 * 36;
	// lbz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// addi r11,r1,716
	r11.s64 = ctx.r1.s64 + 716;
	// cmplwi cr6,r9,240
	cr6.compare<uint32_t>(ctx.r9.u32, 240, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// bge cr6,0x8244e9c8
	if (!cr6.lt) goto loc_8244E9C8;
	// cmplwi cr6,r11,240
	cr6.compare<uint32_t>(r11.u32, 240, xer);
	// blt cr6,0x8244e9dc
	if (cr6.lt) goto loc_8244E9DC;
	// b 0x8244e9d0
	goto loc_8244E9D0;
loc_8244E9C8:
	// cmplwi cr6,r11,240
	cr6.compare<uint32_t>(r11.u32, 240, xer);
	// bge cr6,0x8244e9dc
	if (!cr6.lt) goto loc_8244E9DC;
loc_8244E9D0:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r20,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r20.u32);
loc_8244E9DC:
	// rlwinm r26,r30,2,0,29
	r26.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, r30.u32);
	// addi r27,r1,796
	r27.s64 = ctx.r1.s64 + 796;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stwx r25,r26,r27
	PPC_STORE_U32(r26.u32 + r27.u32, r25.u32);
	// bl 0x8244da40
	ctx.lr = 0x8244E9F4;
	sub_8244DA40(ctx, base);
	// clrlwi. r11,r29,28
	r11.u64 = r29.u32 & 0xF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244ea38
	if (cr0.eq) goto loc_8244EA38;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// beq cr6,0x8244ea30
	if (cr6.eq) goto loc_8244EA30;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8244EA0C:
	// slw r9,r20,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r20.u32 << (r11.u8 & 0x3F));
	// and. r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & r29.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8244ea1c
	if (cr0.eq) goto loc_8244EA1C;
	// stw r20,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r20.u32);
loc_8244EA1C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// blt cr6,0x8244ea0c
	if (cr6.lt) goto loc_8244EA0C;
	// b 0x8244ea38
	goto loc_8244EA38;
loc_8244EA30:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r20,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r20.u32);
loc_8244EA38:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x8244ea84
	if (cr6.eq) goto loc_8244EA84;
	// mr r31,r28
	r31.u64 = r28.u64;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
loc_8244EA48:
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// bne cr6,0x8244ea70
	if (!cr6.eq) goto loc_8244EA70;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244e068
	ctx.lr = 0x8244EA68;
	sub_8244E068(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244ebdc
	if (!cr0.eq) goto loc_8244EBDC;
loc_8244EA70:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// blt cr6,0x8244ea48
	if (cr6.lt) goto loc_8244EA48;
	// b 0x8244eaa8
	goto loc_8244EAA8;
loc_8244EA84:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x8244e068
	ctx.lr = 0x8244EAA0;
	sub_8244E068(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244ebdc
	if (!cr0.eq) goto loc_8244EBDC;
loc_8244EAA8:
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x827bcee4
	ctx.lr = 0x8244EAB0;
	__imp__XexCheckExecutablePrivilege(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8244eb78
	if (!cr0.eq) goto loc_8244EB78;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// std r28,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r28.u64);
	// bl 0x827bd814
	ctx.lr = 0x8244EAC4;
	__imp__KeEnterCriticalRegion(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r29,r11,14492
	r29.s64 = r11.s64 + 14492;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8244EAD4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r31,r10,12384
	r31.s64 = ctx.r10.s64 + 12384;
	// rlwinm r10,r21,20,12,31
	ctx.r10.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 20) & 0xFFFFF;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r5,644
	ctx.r5.s64 = 644;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r24,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r24.u32);
	// stw r23,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r23.u32);
	// bl 0x823da950
	ctx.lr = 0x8244EB08;
	sub_823DA950(ctx, base);
	// lis r11,520
	r11.s64 = 34078720;
	// lis r10,-32187
	ctx.r10.s64 = -2109407232;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r10,-6856
	ctx.r3.s64 = ctx.r10.s64 + -6856;
	// bl 0x827bd384
	ctx.lr = 0x8244EB2C;
	__imp__XamTaskSchedule(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244eb64
	if (cr0.lt) goto loc_8244EB64;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x827bd374
	ctx.lr = 0x8244EB3C;
	__imp__XamTaskCloseHandle(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r30,r11,14536
	r30.s64 = r11.s64 + 14536;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x8244EB5C;
	__imp__KeWaitForSingleObject(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd874
	ctx.lr = 0x8244EB64;
	__imp__KeResetEvent(ctx, base);
loc_8244EB64:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x827bcf54
	ctx.lr = 0x8244EB70;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x827bd7e4
	ctx.lr = 0x8244EB74;
	__imp__KeLeaveCriticalRegion(ctx, base);
	// b 0x8244eb90
	goto loc_8244EB90;
loc_8244EB78:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-22944
	ctx.r4.s64 = r11.s64 + -22944;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8244e2e8
	ctx.lr = 0x8244EB8C;
	sub_8244E2E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8244EB90:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244ebd0
	if (cr6.lt) goto loc_8244EBD0;
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
loc_8244EBA0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8244ebc0
	if (!cr6.eq) goto loc_8244EBC0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// blt cr6,0x8244eba0
	if (cr6.lt) goto loc_8244EBA0;
	// b 0x8244ebc4
	goto loc_8244EBC4;
loc_8244EBC0:
	// bl 0x8244e388
	ctx.lr = 0x8244EBC4;
	sub_8244E388(ctx, base);
loc_8244EBC4:
	// mr r11,r20
	r11.u64 = r20.u64;
	// stw r11,12364(r19)
	PPC_STORE_U32(r19.u32 + 12364, r11.u32);
	// b 0x8244e8a8
	goto loc_8244E8A8;
loc_8244EBD0:
	// bl 0x8244e1f8
	ctx.lr = 0x8244EBD4;
	sub_8244E1F8(ctx, base);
	// b 0x8244e8a8
	goto loc_8244E8A8;
loc_8244EBD8:
	// li r3,87
	ctx.r3.s64 = 87;
loc_8244EBDC:
	// addi r1,r1,1296
	ctx.r1.s64 = ctx.r1.s64 + 1296;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8244EBE4"))) PPC_WEAK_FUNC(sub_8244EBE4);
PPC_FUNC_IMPL(__imp__sub_8244EBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EBE8"))) PPC_WEAK_FUNC(sub_8244EBE8);
PPC_FUNC_IMPL(__imp__sub_8244EBE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x8244EBF0;
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
	// bl 0x8244d970
	ctx.lr = 0x8244EC04;
	sub_8244D970(ctx, base);
	// subfic r11,r31,0
	xer.ca = r31.u32 <= 0;
	r11.s64 = 0 - r31.s64;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r7,r10,14588
	ctx.r7.s64 = ctx.r10.s64 + 14588;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// clrlwi r4,r11,28
	ctx.r4.u64 = r11.u32 & 0xF;
	// bl 0x8244e778
	ctx.lr = 0x8244EC24;
	sub_8244E778(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244EC2C"))) PPC_WEAK_FUNC(sub_8244EC2C);
PPC_FUNC_IMPL(__imp__sub_8244EC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EC30"))) PPC_WEAK_FUNC(sub_8244EC30);
PPC_FUNC_IMPL(__imp__sub_8244EC30) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,12364(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12364);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8244ec54
	if (!cr6.eq) goto loc_8244EC54;
	// li r3,4304
	ctx.r3.s64 = 4304;
	// b 0x8244ec5c
	goto loc_8244EC5C;
loc_8244EC54:
	// bl 0x8244e468
	ctx.lr = 0x8244EC58;
	sub_8244E468(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244EC5C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244EC6C"))) PPC_WEAK_FUNC(sub_8244EC6C);
PPC_FUNC_IMPL(__imp__sub_8244EC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EC70"))) PPC_WEAK_FUNC(sub_8244EC70);
PPC_FUNC_IMPL(__imp__sub_8244EC70) {
	PPC_FUNC_PROLOGUE();
	// b 0x8244e468
	sub_8244E468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244EC74"))) PPC_WEAK_FUNC(sub_8244EC74);
PPC_FUNC_IMPL(__imp__sub_8244EC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EC78"))) PPC_WEAK_FUNC(sub_8244EC78);
PPC_FUNC_IMPL(__imp__sub_8244EC78) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8244ecb4
	if (cr6.eq) goto loc_8244ECB4;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ff00
	ctx.lr = 0x8244ECAC;
	sub_8245FF00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8244ecb8
	goto loc_8244ECB8;
loc_8244ECB4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8244ECB8:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd974
	ctx.lr = 0x8244ECC8;
	__imp__NtCreateSemaphore(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ecf0
	if (cr0.lt) goto loc_8244ECF0;
	// lis r11,16384
	r11.s64 = 1073741824;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,183
	ctx.r3.s64 = 183;
	// beq cr6,0x8244ece4
	if (cr6.eq) goto loc_8244ECE4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244ECE4:
	// bl 0x82135d38
	ctx.lr = 0x8244ECE8;
	sub_82135D38(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8244ecf8
	goto loc_8244ECF8;
loc_8244ECF0:
	// bl 0x821326a0
	ctx.lr = 0x8244ECF4;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244ECF8:
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

__attribute__((alias("__imp__sub_8244ED10"))) PPC_WEAK_FUNC(sub_8244ED10);
PPC_FUNC_IMPL(__imp__sub_8244ED10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x827bd984
	ctx.lr = 0x8244ED20;
	__imp__NtReleaseSemaphore(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ed30
	if (cr0.lt) goto loc_8244ED30;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244ed38
	goto loc_8244ED38;
loc_8244ED30:
	// bl 0x821326a0
	ctx.lr = 0x8244ED34;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244ED38:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244ED48"))) PPC_WEAK_FUNC(sub_8244ED48);
PPC_FUNC_IMPL(__imp__sub_8244ED48) {
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
	ctx.lr = 0x8244ED50;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,64
	cr6.compare<uint32_t>(r31.u32, 64, xer);
	// ble cr6,0x8244ed80
	if (!cr6.gt) goto loc_8244ED80;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// bl 0x821326a0
	ctx.lr = 0x8244ED78;
	sub_821326A0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8244edf0
	goto loc_8244EDF0;
loc_8244ED80:
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x8244ED8C;
	sub_823DA950(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82135e28
	ctx.lr = 0x8244ED98;
	sub_82135E28(ctx, base);
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r30,r27,24
	r30.u64 = r27.u32 & 0xFF;
	// rlwinm r29,r11,27,31,31
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// extsb r28,r10
	r28.s64 = ctx.r10.s8;
loc_8244EDB0:
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bd994
	ctx.lr = 0x8244EDCC;
	__imp__NtWaitForMultipleObjectsEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ede8
	if (cr0.lt) goto loc_8244EDE8;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x8244edf0
	if (cr6.eq) goto loc_8244EDF0;
	// cmpwi cr6,r3,257
	cr6.compare<int32_t>(ctx.r3.s32, 257, xer);
	// beq cr6,0x8244edb0
	if (cr6.eq) goto loc_8244EDB0;
	// b 0x8244edf0
	goto loc_8244EDF0;
loc_8244EDE8:
	// bl 0x821326a0
	ctx.lr = 0x8244EDEC;
	sub_821326A0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8244EDF0:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8244EDF8"))) PPC_WEAK_FUNC(sub_8244EDF8);
PPC_FUNC_IMPL(__imp__sub_8244EDF8) {
	PPC_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x8244ed48
	sub_8244ED48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244EE00"))) PPC_WEAK_FUNC(sub_8244EE00);
PPC_FUNC_IMPL(__imp__sub_8244EE00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd9a4
	ctx.lr = 0x8244EE14;
	__imp__NtSetEvent(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ee24
	if (cr0.lt) goto loc_8244EE24;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244ee2c
	goto loc_8244EE2C;
loc_8244EE24:
	// bl 0x82135d58
	ctx.lr = 0x8244EE28;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244EE2C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244EE3C"))) PPC_WEAK_FUNC(sub_8244EE3C);
PPC_FUNC_IMPL(__imp__sub_8244EE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EE40"))) PPC_WEAK_FUNC(sub_8244EE40);
PPC_FUNC_IMPL(__imp__sub_8244EE40) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8244ee7c
	if (cr6.eq) goto loc_8244EE7C;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ff00
	ctx.lr = 0x8244EE74;
	sub_8245FF00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8244ee80
	goto loc_8244EE80;
loc_8244EE7C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8244EE80:
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bcec4
	ctx.lr = 0x8244EE94;
	__imp__NtCreateEvent(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244eebc
	if (cr0.lt) goto loc_8244EEBC;
	// lis r11,16384
	r11.s64 = 1073741824;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,183
	ctx.r3.s64 = 183;
	// beq cr6,0x8244eeb0
	if (cr6.eq) goto loc_8244EEB0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244EEB0:
	// bl 0x82135d40
	ctx.lr = 0x8244EEB4;
	sub_82135D40(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8244eec4
	goto loc_8244EEC4;
loc_8244EEBC:
	// bl 0x82135d58
	ctx.lr = 0x8244EEC0;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244EEC4:
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

__attribute__((alias("__imp__sub_8244EEDC"))) PPC_WEAK_FUNC(sub_8244EEDC);
PPC_FUNC_IMPL(__imp__sub_8244EEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244EEE0"))) PPC_WEAK_FUNC(sub_8244EEE0);
PPC_FUNC_IMPL(__imp__sub_8244EEE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244EF00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244ef10
	if (cr0.lt) goto loc_8244EF10;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244ef18
	goto loc_8244EF18;
loc_8244EF10:
	// bl 0x82135d58
	ctx.lr = 0x8244EF14;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244EF18:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244EF28"))) PPC_WEAK_FUNC(sub_8244EF28);
PPC_FUNC_IMPL(__imp__sub_8244EF28) {
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
	ctx.lr = 0x8244EF30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// beq cr6,0x8244efa8
	if (cr6.eq) goto loc_8244EFA8;
	// cmplwi cr6,r27,2
	cr6.compare<uint32_t>(r27.u32, 2, xer);
	// beq cr6,0x8244efa0
	if (cr6.eq) goto loc_8244EFA0;
	// cmplwi cr6,r27,3
	cr6.compare<uint32_t>(r27.u32, 3, xer);
	// beq cr6,0x8244ef98
	if (cr6.eq) goto loc_8244EF98;
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// beq cr6,0x8244ef90
	if (cr6.eq) goto loc_8244EF90;
	// cmplwi cr6,r27,5
	cr6.compare<uint32_t>(r27.u32, 5, xer);
	// bne cr6,0x8244ef7c
	if (!cr6.eq) goto loc_8244EF7C;
	// rlwinm. r11,r28,0,1,1
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r30,4
	r30.s64 = 4;
	// bne 0x8244efac
	if (!cr0.eq) goto loc_8244EFAC;
loc_8244EF7C:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// bl 0x82135d58
	ctx.lr = 0x8244EF88;
	sub_82135D58(ctx, base);
loc_8244EF88:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8244f114
	goto loc_8244F114;
loc_8244EF90:
	// li r30,3
	r30.s64 = 3;
	// b 0x8244efac
	goto loc_8244EFAC;
loc_8244EF98:
	// li r30,1
	r30.s64 = 1;
	// b 0x8244efac
	goto loc_8244EFAC;
loc_8244EFA0:
	// li r30,5
	r30.s64 = 5;
	// b 0x8244efac
	goto loc_8244EFAC;
loc_8244EFA8:
	// li r30,2
	r30.s64 = 2;
loc_8244EFAC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827bd844
	ctx.lr = 0x8244EFB8;
	__imp__RtlInitAnsiString(ctx, base);
	// lhz r11,104(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x8244efd8
	if (!cr6.gt) goto loc_8244EFD8;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r29,1
	r29.s64 = 1;
	// lbz r11,-1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// beq cr6,0x8244efdc
	if (cr6.eq) goto loc_8244EFDC;
loc_8244EFD8:
	// li r29,0
	r29.s64 = 0;
loc_8244EFDC:
	// mr r11,r31
	r11.u64 = r31.u64;
	// rlwinm r9,r31,0,4,4
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x8000000;
	// rlwimi r11,r31,28,4,4
	r11.u64 = (__builtin_rotateleft32(r31.u32, 28) & 0x8000000) | (r11.u64 & 0xFFFFFFFFF7FFFFFF);
	// rlwinm r8,r31,0,3,3
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x10000000;
	// rlwinm r11,r11,31,3,5
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1C000000;
	// rlwinm r10,r31,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x2000000;
	// rlwinm r11,r11,0,5,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// li r7,-3
	ctx.r7.s64 = -3;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// not r9,r31
	ctx.r9.u64 = ~r31.u64;
	// stw r7,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// rlwinm r11,r11,24,8,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r9,7,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0x20;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// li r6,64
	ctx.r6.s64 = 64;
	// rlwinm r11,r11,26,6,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3FFFFFF;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm. r8,r31,0,5,5
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x4000000;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// rlwinm r11,r11,21,11,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1FFFFF;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// beq 0x8244f044
	if (cr0.eq) goto loc_8244F044;
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// oris r28,r28,1
	r28.u64 = r28.u64 | 65536;
loc_8244F044:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8244f050
	if (!cr6.eq) goto loc_8244F050;
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
loc_8244F050:
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// oris r4,r28,16
	ctx.r4.u64 = r28.u64 | 1048576;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// andi. r8,r31,32679
	ctx.r8.u64 = r31.u64 & 32679;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r11,14800(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14800);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// ori r4,r4,128
	ctx.r4.u64 = ctx.r4.u64 | 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F08C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8244f0dc
	if (!cr0.lt) goto loc_8244F0DC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82135d58
	ctx.lr = 0x8244F09C;
	sub_82135D58(ctx, base);
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,53
	r11.u64 = r11.u64 | 53;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x8244f0b4
	if (!cr6.eq) goto loc_8244F0B4;
	// li r3,80
	ctx.r3.s64 = 80;
	// b 0x8244f0d4
	goto loc_8244F0D4;
loc_8244F0B4:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,186
	r11.u64 = r11.u64 | 186;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x8244ef88
	if (!cr6.eq) goto loc_8244EF88;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// li r3,3
	ctx.r3.s64 = 3;
	// bne cr6,0x8244f0d4
	if (!cr6.eq) goto loc_8244F0D4;
	// li r3,5
	ctx.r3.s64 = 5;
loc_8244F0D4:
	// bl 0x82135d38
	ctx.lr = 0x8244F0D8;
	sub_82135D38(ctx, base);
	// b 0x8244ef88
	goto loc_8244EF88;
loc_8244F0DC:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r27,2
	cr6.compare<uint32_t>(r27.u32, 2, xer);
	// bne cr6,0x8244f0f0
	if (!cr6.eq) goto loc_8244F0F0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x8244f100
	if (cr6.eq) goto loc_8244F100;
loc_8244F0F0:
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// bne cr6,0x8244f108
	if (!cr6.eq) goto loc_8244F108;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8244f108
	if (!cr6.eq) goto loc_8244F108;
loc_8244F100:
	// li r3,183
	ctx.r3.s64 = 183;
	// b 0x8244f10c
	goto loc_8244F10C;
loc_8244F108:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F10C:
	// bl 0x82135d38
	ctx.lr = 0x8244F110;
	sub_82135D38(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_8244F114:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8244F11C"))) PPC_WEAK_FUNC(sub_8244F11C);
PPC_FUNC_IMPL(__imp__sub_8244F11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F120"))) PPC_WEAK_FUNC(sub_8244F120);
PPC_FUNC_IMPL(__imp__sub_8244F120) {
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
	ctx.lr = 0x8244F128;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8244f150
	if (cr6.eq) goto loc_8244F150;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r30,80(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8244f154
	goto loc_8244F154;
loc_8244F150:
	// extsw r30,r4
	r30.s64 = ctx.r4.s32;
loc_8244F154:
	// lis r31,-32129
	r31.s64 = -2105606144;
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// blt cr6,0x8244f1e0
	if (cr6.lt) goto loc_8244F1E0;
	// beq cr6,0x8244f1ac
	if (cr6.eq) goto loc_8244F1AC;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bge cr6,0x8244f1ac
	if (!cr6.lt) goto loc_8244F1AC;
	// lwz r11,14800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14800);
	// li r7,34
	ctx.r7.s64 = 34;
	// li r6,56
	ctx.r6.s64 = 56;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244f1a0
	if (!cr0.lt) goto loc_8244F1A0;
loc_8244F198:
	// bl 0x82135d58
	ctx.lr = 0x8244F19C;
	sub_82135D58(ctx, base);
	// b 0x8244f284
	goto loc_8244F284;
loc_8244F1A0:
	// ld r11,136(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
loc_8244F1A4:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// b 0x8244f1e4
	goto loc_8244F1E4;
loc_8244F1AC:
	// lwz r11,14800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14800);
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f198
	if (cr0.lt) goto loc_8244F198;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8244f1a4
	goto loc_8244F1A4;
loc_8244F1E0:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8244F1E4:
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// bge cr6,0x8244f1fc
	if (!cr6.lt) goto loc_8244F1FC;
	// li r3,131
	ctx.r3.s64 = 131;
loc_8244F1F4:
	// bl 0x82135d40
	ctx.lr = 0x8244F1F8;
	sub_82135D40(ctx, base);
	// b 0x8244f284
	goto loc_8244F284;
loc_8244F1FC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8244f218
	if (!cr6.eq) goto loc_8244F218;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi. r11,r11,1
	r11.u64 = r11.u32 & 0x7FFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244f218
	if (cr0.eq) goto loc_8244F218;
	// li r3,87
	ctx.r3.s64 = 87;
	// b 0x8244f1f4
	goto loc_8244F1F4;
loc_8244F218:
	// lwz r11,14800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14800);
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F23C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f270
	if (cr0.lt) goto loc_8244F270;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8244f254
	if (cr6.eq) goto loc_8244F254;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8244F254:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8244f268
	if (!cr6.eq) goto loc_8244F268;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82135d38
	ctx.lr = 0x8244F268;
	sub_82135D38(ctx, base);
loc_8244F268:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8244f288
	goto loc_8244F288;
loc_8244F270:
	// bl 0x82135d58
	ctx.lr = 0x8244F274;
	sub_82135D58(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8244f284
	if (cr6.eq) goto loc_8244F284;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8244F284:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8244F288:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244F290"))) PPC_WEAK_FUNC(sub_8244F290);
PPC_FUNC_IMPL(__imp__sub_8244F290) {
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
	ctx.lr = 0x8244F298;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r30,-32129
	r30.s64 = -2105606144;
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// blt cr6,0x8244f328
	if (cr6.lt) goto loc_8244F328;
	// beq cr6,0x8244f2f4
	if (cr6.eq) goto loc_8244F2F4;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bge cr6,0x8244f2f4
	if (!cr6.lt) goto loc_8244F2F4;
	// lwz r11,14800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14800);
	// li r7,34
	ctx.r7.s64 = 34;
	// li r6,56
	ctx.r6.s64 = 56;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F2E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f388
	if (cr0.lt) goto loc_8244F388;
	// ld r11,136(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
loc_8244F2EC:
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// b 0x8244f32c
	goto loc_8244F32C;
loc_8244F2F4:
	// lwz r11,14800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14800);
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f388
	if (cr0.lt) goto loc_8244F388;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8244f2ec
	goto loc_8244F2EC;
loc_8244F328:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8244F32C:
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// bge cr6,0x8244f344
	if (!cr6.lt) goto loc_8244F344;
	// li r3,131
	ctx.r3.s64 = 131;
	// bl 0x82135d40
	ctx.lr = 0x8244F340;
	sub_82135D40(ctx, base);
	// b 0x8244f38c
	goto loc_8244F38C;
loc_8244F344:
	// lwz r11,14800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14800);
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f388
	if (cr0.lt) goto loc_8244F388;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8244f380
	if (cr6.eq) goto loc_8244F380;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r28)
	PPC_STORE_U64(r28.u32 + 0, r11.u64);
loc_8244F380:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244f390
	goto loc_8244F390;
loc_8244F388:
	// bl 0x82135d58
	ctx.lr = 0x8244F38C;
	sub_82135D58(ctx, base);
loc_8244F38C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F390:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244F398"))) PPC_WEAK_FUNC(sub_8244F398);
PPC_FUNC_IMPL(__imp__sub_8244F398) {
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
	ctx.lr = 0x8244F3A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244f3c8
	if (cr6.eq) goto loc_8244F3C8;
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
loc_8244F3C8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8244f43c
	if (cr6.eq) goto loc_8244F43C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r11,259
	r11.s64 = 259;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// clrlwi. r5,r4,31
	ctx.r5.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bne 0x8244f3f8
	if (!cr0.eq) goto loc_8244F3F8;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
loc_8244F3F8:
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd904
	ctx.lr = 0x8244F40C;
	__imp__NtWriteFile(ctx, base);
	// lis r11,-16384
	r11.s64 = -1073741824;
	// rlwinm r10,r3,0,0,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8244f4b0
	if (cr6.eq) goto loc_8244F4B0;
	// cmpwi cr6,r3,259
	cr6.compare<int32_t>(ctx.r3.s32, 259, xer);
	// beq cr6,0x8244f4b0
	if (cr6.eq) goto loc_8244F4B0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244f434
	if (cr6.eq) goto loc_8244F434;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8244F434:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244f4b8
	goto loc_8244F4B8;
loc_8244F43C:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd904
	ctx.lr = 0x8244F458;
	__imp__NtWriteFile(ctx, base);
	// cmpwi cr6,r3,259
	cr6.compare<int32_t>(ctx.r3.s32, 259, xer);
	// bne cr6,0x8244f480
	if (!cr6.eq) goto loc_8244F480;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd034
	ctx.lr = 0x8244F474;
	__imp__NtWaitForSingleObjectEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f498
	if (cr0.lt) goto loc_8244F498;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244F480:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8244f498
	if (cr6.lt) goto loc_8244F498;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x8244f4b8
	goto loc_8244F4B8;
loc_8244F498:
	// rlwinm r11,r3,0,0,1
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0000000;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8244f4b0
	if (!cr6.eq) goto loc_8244F4B0;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8244F4B0:
	// bl 0x82135d58
	ctx.lr = 0x8244F4B4;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F4B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8244F4C0"))) PPC_WEAK_FUNC(sub_8244F4C0);
PPC_FUNC_IMPL(__imp__sub_8244F4C0) {
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
	ctx.lr = 0x8244F4C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244f4f0
	if (cr6.eq) goto loc_8244F4F0;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_8244F4F0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8244f594
	if (cr6.eq) goto loc_8244F594;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r11,259
	r11.s64 = 259;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// clrlwi. r6,r4,31
	ctx.r6.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bne 0x8244f524
	if (!cr0.eq) goto loc_8244F524;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
loc_8244F524:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f570
	if (cr0.lt) goto loc_8244F570;
	// cmpwi cr6,r3,259
	cr6.compare<int32_t>(ctx.r3.s32, 259, xer);
	// beq cr6,0x8244f570
	if (cr6.eq) goto loc_8244F570;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244f568
	if (cr6.eq) goto loc_8244F568;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8244F568:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244f63c
	goto loc_8244F63C;
loc_8244F570:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,17
	r11.u64 = r11.u64 | 17;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8244f634
	if (!cr6.eq) goto loc_8244F634;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8244f58c
	if (cr6.eq) goto loc_8244F58C;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_8244F58C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8244f634
	goto loc_8244F634;
loc_8244F594:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,259
	cr6.compare<int32_t>(ctx.r3.s32, 259, xer);
	// bne cr6,0x8244f5e8
	if (!cr6.eq) goto loc_8244F5E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd034
	ctx.lr = 0x8244F5DC;
	__imp__NtWaitForSingleObjectEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f600
	if (cr0.lt) goto loc_8244F600;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244F5E8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8244f600
	if (cr6.lt) goto loc_8244F600;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x8244f63c
	goto loc_8244F63C;
loc_8244F600:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,17
	r11.u64 = r11.u64 | 17;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8244f61c
	if (!cr6.eq) goto loc_8244F61C;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// b 0x8244f63c
	goto loc_8244F63C;
loc_8244F61C:
	// rlwinm r11,r3,0,0,1
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0000000;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8244f634
	if (!cr6.eq) goto loc_8244F634;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8244F634:
	// bl 0x82135d58
	ctx.lr = 0x8244F638;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F63C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8244F644"))) PPC_WEAK_FUNC(sub_8244F644);
PPC_FUNC_IMPL(__imp__sub_8244F644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F648"))) PPC_WEAK_FUNC(sub_8244F648);
PPC_FUNC_IMPL(__imp__sub_8244F648) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r7,34
	ctx.r7.s64 = 34;
	// li r6,56
	ctx.r6.s64 = 56;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244F680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244f694
	if (!cr0.lt) goto loc_8244F694;
	// bl 0x82135d58
	ctx.lr = 0x8244F68C;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8244f6a0
	goto loc_8244F6A0;
loc_8244F694:
	// ld r11,136(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
loc_8244F6A0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F6B4"))) PPC_WEAK_FUNC(sub_8244F6B4);
PPC_FUNC_IMPL(__imp__sub_8244F6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F6B8"))) PPC_WEAK_FUNC(sub_8244F6B8);
PPC_FUNC_IMPL(__imp__sub_8244F6B8) {
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
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827bd844
	ctx.lr = 0x8244F6E0;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r5,328
	ctx.r5.s64 = 328;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8245fff8
	ctx.lr = 0x8244F70C;
	sub_8245FFF8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244f720
	if (!cr0.lt) goto loc_8244F720;
	// bl 0x82135d58
	ctx.lr = 0x8244F718;
	sub_82135D58(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8244f730
	goto loc_8244F730;
loc_8244F720:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8245ff58
	ctx.lr = 0x8244F72C;
	sub_8245FF58(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244F730:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F744"))) PPC_WEAK_FUNC(sub_8244F744);
PPC_FUNC_IMPL(__imp__sub_8244F744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F748"))) PPC_WEAK_FUNC(sub_8244F748);
PPC_FUNC_IMPL(__imp__sub_8244F748) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// std r11,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r11.u64);
	// std r11,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r11.u64);
	// std r11,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r11.u64);
	// beq cr6,0x8244f788
	if (cr6.eq) goto loc_8244F788;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
loc_8244F788:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8244f7a0
	if (cr6.eq) goto loc_8244F7A0;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_8244F7A0:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8244f7b8
	if (cr6.eq) goto loc_8244F7B8;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_8244F7B8:
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,40
	ctx.r6.s64 = 40;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd9b4
	ctx.lr = 0x8244F7CC;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f7dc
	if (cr0.lt) goto loc_8244F7DC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244f7e4
	goto loc_8244F7E4;
loc_8244F7DC:
	// bl 0x82135d58
	ctx.lr = 0x8244F7E0;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F7E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F7F4"))) PPC_WEAK_FUNC(sub_8244F7F4);
PPC_FUNC_IMPL(__imp__sub_8244F7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F7F8"))) PPC_WEAK_FUNC(sub_8244F7F8);
PPC_FUNC_IMPL(__imp__sub_8244F7F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd844
	ctx.lr = 0x8244F810;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd9c4
	ctx.lr = 0x8244F834;
	__imp__NtQueryFullAttributesFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f844
	if (cr0.lt) goto loc_8244F844;
	// lwz r3,160(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// b 0x8244f84c
	goto loc_8244F84C;
loc_8244F844:
	// bl 0x82135d58
	ctx.lr = 0x8244F848;
	sub_82135D58(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8244F84C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F85C"))) PPC_WEAK_FUNC(sub_8244F85C);
PPC_FUNC_IMPL(__imp__sub_8244F85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F860"))) PPC_WEAK_FUNC(sub_8244F860);
PPC_FUNC_IMPL(__imp__sub_8244F860) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd844
	ctx.lr = 0x8244F880;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// li r8,16416
	ctx.r8.s64 = 16416;
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// ori r4,r4,256
	ctx.r4.u64 = ctx.r4.u64 | 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd8d4
	ctx.lr = 0x8244F8B8;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244f920
	if (cr0.lt) goto loc_8244F920;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// andi. r9,r31,12583
	ctx.r9.u64 = r31.u64 & 12583;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// ori r9,r9,128
	ctx.r9.u64 = ctx.r9.u64 | 128;
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// li r7,4
	ctx.r7.s64 = 4;
	// std r11,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r11.u64);
	// li r6,40
	ctx.r6.s64 = 40;
	// std r11,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, r11.u64);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// std r11,32(r10)
	PPC_STORE_U64(ctx.r10.u32 + 32, r11.u64);
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd9b4
	ctx.lr = 0x8244F900;
	__imp__NtSetInformationFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bceb4
	ctx.lr = 0x8244F90C;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244f91c
	if (cr6.lt) goto loc_8244F91C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244f928
	goto loc_8244F928;
loc_8244F91C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8244F920:
	// bl 0x82135d58
	ctx.lr = 0x8244F924;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244F928:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F93C"))) PPC_WEAK_FUNC(sub_8244F93C);
PPC_FUNC_IMPL(__imp__sub_8244F93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244F940"))) PPC_WEAK_FUNC(sub_8244F940);
PPC_FUNC_IMPL(__imp__sub_8244F940) {
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
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,328
	ctx.r5.s64 = 328;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82460178
	ctx.lr = 0x8244F960;
	sub_82460178(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244f974
	if (!cr0.lt) goto loc_8244F974;
	// bl 0x82135d58
	ctx.lr = 0x8244F96C;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8244f984
	goto loc_8244F984;
loc_8244F974:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8245ff58
	ctx.lr = 0x8244F980;
	sub_8245FF58(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8244F984:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244F998"))) PPC_WEAK_FUNC(sub_8244F998);
PPC_FUNC_IMPL(__imp__sub_8244F998) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827bd9d4
	ctx.lr = 0x8244F9C0;
	__imp__NtQueryInformationFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fa20
	if (cr0.lt) goto loc_8244FA20;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// bl 0x827bd9b4
	ctx.lr = 0x8244F9E8;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fa20
	if (cr0.lt) goto loc_8244FA20;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r7,19
	ctx.r7.s64 = 19;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bl 0x827bd9b4
	ctx.lr = 0x8244FA10;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fa20
	if (cr0.lt) goto loc_8244FA20;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fa28
	goto loc_8244FA28;
loc_8244FA20:
	// bl 0x82135d58
	ctx.lr = 0x8244FA24;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FA28:
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

__attribute__((alias("__imp__sub_8244FA3C"))) PPC_WEAK_FUNC(sub_8244FA3C);
PPC_FUNC_IMPL(__imp__sub_8244FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FA40"))) PPC_WEAK_FUNC(sub_8244FA40);
PPC_FUNC_IMPL(__imp__sub_8244FA40) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd844
	ctx.lr = 0x8244FA5C;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// li r8,16448
	ctx.r8.s64 = 16448;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bd8d4
	ctx.lr = 0x8244FA90;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fad8
	if (cr0.lt) goto loc_8244FAD8;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r7,13
	ctx.r7.s64 = 13;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd9b4
	ctx.lr = 0x8244FAB8;
	__imp__NtSetInformationFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827bceb4
	ctx.lr = 0x8244FAC4;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244fad4
	if (cr6.lt) goto loc_8244FAD4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fae0
	goto loc_8244FAE0;
loc_8244FAD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8244FAD8:
	// bl 0x82135d58
	ctx.lr = 0x8244FADC;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FAE0:
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

__attribute__((alias("__imp__sub_8244FAF4"))) PPC_WEAK_FUNC(sub_8244FAF4);
PPC_FUNC_IMPL(__imp__sub_8244FAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FAF8"))) PPC_WEAK_FUNC(sub_8244FAF8);
PPC_FUNC_IMPL(__imp__sub_8244FAF8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd844
	ctx.lr = 0x8244FB1C;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,64
	r11.s64 = 64;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// li r30,-3
	r30.s64 = -3;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// li r8,16416
	ctx.r8.s64 = 16416;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lis r4,17
	ctx.r4.s64 = 1114112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd8d4
	ctx.lr = 0x8244FB50;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fba8
	if (cr0.lt) goto loc_8244FBA8;
	// li r11,0
	r11.s64 = 0;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stb r11,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r11.u8);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x827bd844
	ctx.lr = 0x8244FB70;
	__imp__RtlInitAnsiString(ctx, base);
	// li r7,10
	ctx.r7.s64 = 10;
	// li r6,16
	ctx.r6.s64 = 16;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd9b4
	ctx.lr = 0x8244FB88;
	__imp__NtSetInformationFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bceb4
	ctx.lr = 0x8244FB94;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8244fba4
	if (cr6.lt) goto loc_8244FBA4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fbb0
	goto loc_8244FBB0;
loc_8244FBA4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8244FBA8:
	// bl 0x821326a0
	ctx.lr = 0x8244FBAC;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FBB0:
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

__attribute__((alias("__imp__sub_8244FBC8"))) PPC_WEAK_FUNC(sub_8244FBC8);
PPC_FUNC_IMPL(__imp__sub_8244FBC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x827bd844
	ctx.lr = 0x8244FBE0;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// li r11,16417
	r11.s64 = 16417;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd934
	ctx.lr = 0x8244FC28;
	__imp__NtCreateFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fc40
	if (cr0.lt) goto loc_8244FC40;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8244FC38;
	__imp__NtClose(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fc48
	goto loc_8244FC48;
loc_8244FC40:
	// bl 0x82135d58
	ctx.lr = 0x8244FC44;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FC48:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FC58"))) PPC_WEAK_FUNC(sub_8244FC58);
PPC_FUNC_IMPL(__imp__sub_8244FC58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r11,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r11.u16);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x827bd844
	ctx.lr = 0x8244FC80;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824601d8
	ctx.lr = 0x8244FC88;
	sub_824601D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fc98
	if (cr0.lt) goto loc_8244FC98;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fca0
	goto loc_8244FCA0;
loc_8244FC98:
	// bl 0x821326a0
	ctx.lr = 0x8244FC9C;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FCA0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FCB0"))) PPC_WEAK_FUNC(sub_8244FCB0);
PPC_FUNC_IMPL(__imp__sub_8244FCB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r7,26
	ctx.r7.s64 = 26;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8244FCE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244fcf4
	if (!cr0.lt) goto loc_8244FCF4;
	// bl 0x82135d58
	ctx.lr = 0x8244FCEC;
	sub_82135D58(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8244fcf8
	goto loc_8244FCF8;
loc_8244FCF4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244FCF8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FD08"))) PPC_WEAK_FUNC(sub_8244FD08);
PPC_FUNC_IMPL(__imp__sub_8244FD08) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x827bd9e4
	ctx.lr = 0x8244FD38;
	__imp__RtlTimeToTimeFields(ctx, base);
	// lhz r11,96(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// lhz r10,98(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// lhz r8,110(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// lhz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// lhz r5,106(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 106);
	// lhz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 108);
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// sth r10,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r10.u16);
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// sth r6,10(r31)
	PPC_STORE_U16(r31.u32 + 10, ctx.r6.u16);
	// sth r5,12(r31)
	PPC_STORE_U16(r31.u32 + 12, ctx.r5.u16);
	// sth r4,14(r31)
	PPC_STORE_U16(r31.u32 + 14, ctx.r4.u16);
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

__attribute__((alias("__imp__sub_8244FD90"))) PPC_WEAK_FUNC(sub_8244FD90);
PPC_FUNC_IMPL(__imp__sub_8244FD90) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8244fdc0
	if (cr6.eq) goto loc_8244FDC0;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ff00
	ctx.lr = 0x8244FDB8;
	sub_8245FF00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8244fdc4
	goto loc_8244FDC4;
loc_8244FDC0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8244FDC4:
	// clrlwi r5,r31,24
	ctx.r5.u64 = r31.u32 & 0xFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd9f4
	ctx.lr = 0x8244FDD0;
	__imp__NtCreateMutant(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fdf8
	if (cr0.lt) goto loc_8244FDF8;
	// lis r11,16384
	r11.s64 = 1073741824;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,183
	ctx.r3.s64 = 183;
	// beq cr6,0x8244fdec
	if (cr6.eq) goto loc_8244FDEC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FDEC:
	// bl 0x82135d38
	ctx.lr = 0x8244FDF0;
	sub_82135D38(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8244fe00
	goto loc_8244FE00;
loc_8244FDF8:
	// bl 0x82135d58
	ctx.lr = 0x8244FDFC;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FE00:
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

__attribute__((alias("__imp__sub_8244FE14"))) PPC_WEAK_FUNC(sub_8244FE14);
PPC_FUNC_IMPL(__imp__sub_8244FE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FE18"))) PPC_WEAK_FUNC(sub_8244FE18);
PPC_FUNC_IMPL(__imp__sub_8244FE18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bda04
	ctx.lr = 0x8244FE2C;
	__imp__NtReleaseMutant(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8244fe3c
	if (cr0.lt) goto loc_8244FE3C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8244fe44
	goto loc_8244FE44;
loc_8244FE3C:
	// bl 0x82135d58
	ctx.lr = 0x8244FE40;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8244FE44:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FE54"))) PPC_WEAK_FUNC(sub_8244FE54);
PPC_FUNC_IMPL(__imp__sub_8244FE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FE58"))) PPC_WEAK_FUNC(sub_8244FE58);
PPC_FUNC_IMPL(__imp__sub_8244FE58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bda14
	ctx.lr = 0x8244FE6C;
	__imp__NtResumeThread(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8244fe80
	if (!cr0.lt) goto loc_8244FE80;
	// bl 0x82135d58
	ctx.lr = 0x8244FE78;
	sub_82135D58(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8244fe84
	goto loc_8244FE84;
loc_8244FE80:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8244FE84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FE94"))) PPC_WEAK_FUNC(sub_8244FE94);
PPC_FUNC_IMPL(__imp__sub_8244FE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FE98"))) PPC_WEAK_FUNC(sub_8244FE98);
PPC_FUNC_IMPL(__imp__sub_8244FE98) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82132898
	ctx.lr = 0x8244FEB4;
	sub_82132898(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bda24
	ctx.lr = 0x8244FEBC;
	__imp__ExTerminateThread(ctx, base);
}

__attribute__((alias("__imp__sub_8244FEBC"))) PPC_WEAK_FUNC(sub_8244FEBC);
PPC_FUNC_IMPL(__imp__sub_8244FEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FEC0"))) PPC_WEAK_FUNC(sub_8244FEC0);
PPC_FUNC_IMPL(__imp__sub_8244FEC0) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82460270
	sub_82460270(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244FEC8"))) PPC_WEAK_FUNC(sub_8244FEC8);
PPC_FUNC_IMPL(__imp__sub_8244FEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r3,332(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FED4"))) PPC_WEAK_FUNC(sub_8244FED4);
PPC_FUNC_IMPL(__imp__sub_8244FED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FED8"))) PPC_WEAK_FUNC(sub_8244FED8);
PPC_FUNC_IMPL(__imp__sub_8244FED8) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// b 0x82460300
	sub_82460300(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244FEE4"))) PPC_WEAK_FUNC(sub_8244FEE4);
PPC_FUNC_IMPL(__imp__sub_8244FEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FEE8"))) PPC_WEAK_FUNC(sub_8244FEE8);
PPC_FUNC_IMPL(__imp__sub_8244FEE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r11,2408(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2408);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FEF8"))) PPC_WEAK_FUNC(sub_8244FEF8);
PPC_FUNC_IMPL(__imp__sub_8244FEF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x824603c0
	sub_824603C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244FF18"))) PPC_WEAK_FUNC(sub_8244FF18);
PPC_FUNC_IMPL(__imp__sub_8244FF18) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FF1C"))) PPC_WEAK_FUNC(sub_8244FF1C);
PPC_FUNC_IMPL(__imp__sub_8244FF1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FF20"))) PPC_WEAK_FUNC(sub_8244FF20);
PPC_FUNC_IMPL(__imp__sub_8244FF20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82460420
	sub_82460420(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8244FF40"))) PPC_WEAK_FUNC(sub_8244FF40);
PPC_FUNC_IMPL(__imp__sub_8244FF40) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8244FF44"))) PPC_WEAK_FUNC(sub_8244FF44);
PPC_FUNC_IMPL(__imp__sub_8244FF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8244FF48"))) PPC_WEAK_FUNC(sub_8244FF48);
PPC_FUNC_IMPL(__imp__sub_8244FF48) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8244ff6c
	if (!cr6.eq) goto loc_8244FF6C;
	// bl 0x822b9708
	ctx.lr = 0x8244FF6C;
	sub_822B9708(ctx, base);
loc_8244FF6C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8244ff84
	if (cr0.eq) goto loc_8244FF84;
	// lis r4,9347
	ctx.r4.s64 = 612564992;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x8244FF84;
	sub_821310F8(ctx, base);
loc_8244FF84:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8244FF98"))) PPC_WEAK_FUNC(sub_8244FF98);
PPC_FUNC_IMPL(__imp__sub_8244FF98) {
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
	ctx.lr = 0x8244FFA0;
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
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// bge cr6,0x8244ffd0
	if (!cr6.lt) goto loc_8244FFD0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824603b8
	ctx.lr = 0x8244FFCC;
	sub_824603B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8244FFD0:
	// lis r4,9347
	ctx.r4.s64 = 612564992;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130b50
	ctx.lr = 0x8244FFDC;
	sub_82130B50(ctx, base);
	// mr. r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x8244fff0
	if (!cr0.eq) goto loc_8244FFF0;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82450024
	goto loc_82450024;
loc_8244FFF0:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// bge cr6,0x82450010
	if (!cr6.lt) goto loc_82450010;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82460370
	ctx.lr = 0x8245000C;
	sub_82460370(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82450010:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_82450024:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8245002C"))) PPC_WEAK_FUNC(sub_8245002C);
PPC_FUNC_IMPL(__imp__sub_8245002C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82450030"))) PPC_WEAK_FUNC(sub_82450030);
PPC_FUNC_IMPL(__imp__sub_82450030) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,996
	ctx.r3.s64 = 996;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82450044
	if (!cr6.eq) goto loc_82450044;
	// b 0x82135db0
	sub_82135DB0(ctx, base);
	return;
loc_82450044:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,997
	cr6.compare<uint32_t>(ctx.r10.u32, 997, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82450058"))) PPC_WEAK_FUNC(sub_82450058);
PPC_FUNC_IMPL(__imp__sub_82450058) {
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
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824500c4
	if (cr6.eq) goto loc_824500C4;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824500c4
	if (cr6.eq) goto loc_824500C4;
	// andi. r11,r6,144
	r11.u64 = ctx.r6.u64 & 144;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmplwi cr6,r11,144
	cr6.compare<uint32_t>(r11.u32, 144, xer);
	// beq cr6,0x824500c4
	if (cr6.eq) goto loc_824500C4;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824500a0
	if (!cr6.eq) goto loc_824500A0;
	// rlwinm. r31,r6,0,24,24
	r31.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x824500a0
	if (!cr0.eq) goto loc_824500A0;
	// ori r6,r6,16
	ctx.r6.u64 = ctx.r6.u64 | 16;
loc_824500A0:
	// rlwinm. r11,r11,0,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824500b4
	if (cr0.eq) goto loc_824500B4;
	// clrlwi r11,r6,28
	r11.u64 = ctx.r6.u32 & 0xF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824500c4
	if (!cr6.eq) goto loc_824500C4;
loc_824500B4:
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x827bd394
	ctx.lr = 0x824500C0;
	__imp__XamContentCreateEx(ctx, base);
	// b 0x824500c8
	goto loc_824500C8;
loc_824500C4:
	// li r3,87
	ctx.r3.s64 = 87;
loc_824500C8:
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

__attribute__((alias("__imp__sub_824500DC"))) PPC_WEAK_FUNC(sub_824500DC);
PPC_FUNC_IMPL(__imp__sub_824500DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824500E0"))) PPC_WEAK_FUNC(sub_824500E0);
PPC_FUNC_IMPL(__imp__sub_824500E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd3a4
	__imp__XamContentClose(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824500E4"))) PPC_WEAK_FUNC(sub_824500E4);
PPC_FUNC_IMPL(__imp__sub_824500E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824500E8"))) PPC_WEAK_FUNC(sub_824500E8);
PPC_FUNC_IMPL(__imp__sub_824500E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd3b4
	__imp__XamContentCreateEnumerator(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824500EC"))) PPC_WEAK_FUNC(sub_824500EC);
PPC_FUNC_IMPL(__imp__sub_824500EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824500F0"))) PPC_WEAK_FUNC(sub_824500F0);
PPC_FUNC_IMPL(__imp__sub_824500F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd3c4
	__imp__XamContentGetDeviceState(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824500F4"))) PPC_WEAK_FUNC(sub_824500F4);
PPC_FUNC_IMPL(__imp__sub_824500F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824500F8"))) PPC_WEAK_FUNC(sub_824500F8);
PPC_FUNC_IMPL(__imp__sub_824500F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x827bd3c4
	__imp__XamContentGetDeviceState(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82450100"))) PPC_WEAK_FUNC(sub_82450100);
PPC_FUNC_IMPL(__imp__sub_82450100) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd3d4
	__imp__XamContentGetDeviceData(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82450104"))) PPC_WEAK_FUNC(sub_82450104);
PPC_FUNC_IMPL(__imp__sub_82450104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82450108"))) PPC_WEAK_FUNC(sub_82450108);
PPC_FUNC_IMPL(__imp__sub_82450108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// addi r11,r11,4159
	r11.s64 = r11.s64 + 4159;
	// addi r10,r10,4095
	ctx.r10.s64 = ctx.r10.s64 + 4095;
	// rlwinm r11,r11,1,0,18
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFE000;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// li r9,170
	ctx.r9.s64 = 170;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r8,r11,20,12,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// addi r11,r8,169
	r11.s64 = ctx.r8.s64 + 169;
	// divwu r11,r11,r9
	r11.u32 = r11.u32 / ctx.r9.u32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x82450148
	if (!cr6.gt) goto loc_82450148;
	// addi r10,r11,169
	ctx.r10.s64 = r11.s64 + 169;
	// divwu r10,r10,r9
	ctx.r10.u32 = ctx.r10.u32 / ctx.r9.u32;
	// b 0x8245014c
	goto loc_8245014C;
loc_82450148:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8245014C:
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x82450160
	if (!cr6.gt) goto loc_82450160;
	// addi r7,r10,169
	ctx.r7.s64 = ctx.r10.s64 + 169;
	// divwu r9,r7,r9
	ctx.r9.u32 = ctx.r7.u32 / ctx.r9.u32;
	// b 0x82450164
	goto loc_82450164;
loc_82450160:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82450164:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// addi r11,r11,26
	r11.s64 = r11.s64 + 26;
	// rldicr r3,r11,12,51
	ctx.r3.u64 = __builtin_rotateleft64(r11.u64, 12) & 0xFFFFFFFFFFFFF000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82450184"))) PPC_WEAK_FUNC(sub_82450184);
PPC_FUNC_IMPL(__imp__sub_82450184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82450188"))) PPC_WEAK_FUNC(sub_82450188);
PPC_FUNC_IMPL(__imp__sub_82450188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82450058
	ctx.lr = 0x824501B4;
	sub_82450058(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824501C4"))) PPC_WEAK_FUNC(sub_824501C4);
PPC_FUNC_IMPL(__imp__sub_824501C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824501C8"))) PPC_WEAK_FUNC(sub_824501C8);
PPC_FUNC_IMPL(__imp__sub_824501C8) {
	PPC_FUNC_PROLOGUE();
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x827bd3e4
	__imp__XamEnumerate(ctx, base);
	return;
}

