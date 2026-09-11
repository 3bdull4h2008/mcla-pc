#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_825EE0E0) {
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
	// bl 0x825edda8
	ctx.lr = 0x825EE0F8;
	sub_825EDDA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee10c
	if (cr6.eq) goto loc_825EE10C;
	// li r11,3
	r11.s64 = 3;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
loc_825EE10C:
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

PPC_WEAK_FUNC(sub_825EE0E0) {
	__imp__sub_825EE0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE120) {
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
	ctx.lr = 0x825EE128;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x825EE144;
	sub_821C9790(ctx, base);
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee17c
	if (cr6.eq) goto loc_825EE17C;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x825fa2b8
	ctx.lr = 0x825EE160;
	sub_825FA2B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee17c
	if (cr6.eq) goto loc_825EE17C;
	// bl 0x825ef808
	ctx.lr = 0x825EE16C;
	sub_825EF808(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_825EE17C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EE120) {
	__imp__sub_825EE120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE188) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x825edda8
	ctx.lr = 0x825EE1A0;
	sub_825EDDA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee1b4
	if (cr6.eq) goto loc_825EE1B4;
	// li r11,4
	r11.s64 = 4;
	// stfs f31,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
loc_825EE1B4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EE188) {
	__imp__sub_825EE188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE1C8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x825EE1D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x825EE1EC;
	sub_821C9790(ctx, base);
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee224
	if (cr6.eq) goto loc_825EE224;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x825fa2b8
	ctx.lr = 0x825EE208;
	sub_825FA2B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee224
	if (cr6.eq) goto loc_825EE224;
	// bl 0x825ef8c8
	ctx.lr = 0x825EE214;
	sub_825EF8C8(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_825EE224:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EE1C8) {
	__imp__sub_825EE1C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE230) {
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
	// bl 0x825edda8
	ctx.lr = 0x825EE248;
	sub_825EDDA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee25c
	if (cr6.eq) goto loc_825EE25C;
	// li r11,2
	r11.s64 = 2;
	// stb r31,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r31.u8);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
loc_825EE25C:
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

PPC_WEAK_FUNC(sub_825EE230) {
	__imp__sub_825EE230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE270) {
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
	ctx.lr = 0x825EE278;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x825EE294;
	sub_821C9790(ctx, base);
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee2cc
	if (cr6.eq) goto loc_825EE2CC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x825fa2b8
	ctx.lr = 0x825EE2B0;
	sub_825FA2B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee2cc
	if (cr6.eq) goto loc_825EE2CC;
	// bl 0x825ef780
	ctx.lr = 0x825EE2BC;
	sub_825EF780(ctx, base);
	// stb r3,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_825EE2CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EE270) {
	__imp__sub_825EE270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE2D8) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x825edda8
	ctx.lr = 0x825EE2F0;
	sub_825EDDA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee300
	if (cr6.eq) goto loc_825EE300;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825ef9a8
	ctx.lr = 0x825EE300;
	sub_825EF9A8(ctx, base);
loc_825EE300:
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

PPC_WEAK_FUNC(sub_825EE2D8) {
	__imp__sub_825EE2D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE314) {
	__imp__sub_825EE314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE318) {
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
	ctx.lr = 0x825EE320;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x825EE340;
	sub_821C9790(ctx, base);
	// lwz r11,128(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee3d0
	if (cr6.eq) goto loc_825EE3D0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x825fa2b8
	ctx.lr = 0x825EE35C;
	sub_825FA2B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ee3d0
	if (cr6.eq) goto loc_825EE3D0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x825ee378
	if (!cr6.eq) goto loc_825EE378;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x825ee388
	goto loc_825EE388;
loc_825EE378:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825efb40
	ctx.lr = 0x825EE384;
	sub_825EFB40(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_825EE388:
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// beq cr6,0x825ee3c4
	if (cr6.eq) goto loc_825EE3C4;
	// addic. r11,r29,-1
	xer.ca = r29.u32 > 0;
	r11.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// ble 0x825ee3bc
	if (!cr0.gt) goto loc_825EE3BC;
loc_825EE39C:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825ee3bc
	if (cr6.eq) goto loc_825EE3BC;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x825ee39c
	if (cr0.gt) goto loc_825EE39C;
loc_825EE3BC:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
loc_825EE3C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_825EE3D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825EE318) {
	__imp__sub_825EE318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE3DC) {
	__imp__sub_825EE3DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE3E0) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// bl 0x825edac0
	ctx.lr = 0x825EE3FC;
	sub_825EDAC0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r11,-1648(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1648);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EE3E0) {
	__imp__sub_825EE3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE424) {
	__imp__sub_825EE424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f4
	ctx.lr = 0x825EE430;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r10,-1648(r30)
	PPC_STORE_U32(r30.u32 + -1648, ctx.r10.u32);
	// lis r27,-32112
	r27.s64 = -2104492032;
	// stw r5,-1668(r29)
	PPC_STORE_U32(r29.u32 + -1668, ctx.r5.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// lwz r9,688(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f11,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f11.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fdivs f0,f5,f0
	f0.f64 = double(float(ctx.f5.f64 / f0.f64));
	// stfs f0,-1664(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + -1664, temp.u32);
	// lfs f4,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f4.f64 = double(temp.f32);
	// lwz r5,692(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// lfs f3,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f2,80(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f4
	ctx.f13.f64 = double(float(f0.f64 * ctx.f4.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f0,f9,f3
	f0.f64 = double(float(ctx.f9.f64 / ctx.f3.f64));
	// stfs f0,-1644(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + -1644, temp.u32);
	// bl 0x825ef598
	ctx.lr = 0x825EE4FC;
	sub_825EF598(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825fb348
	ctx.lr = 0x825EE508;
	sub_825FB348(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-1648(r30)
	PPC_STORE_U32(r30.u32 + -1648, r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,-1668(r29)
	PPC_STORE_U32(r29.u32 + -1668, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-1644(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + -1644, temp.u32);
	// stfs f0,-1664(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + -1664, temp.u32);
	// bl 0x825edb80
	ctx.lr = 0x825EE530;
	sub_825EDB80(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825EE428) {
	__imp__sub_825EE428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-1648(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -1648);
	// b 0x825ed5f8
	sub_825ED5F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825EE538) {
	__imp__sub_825EE538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE548) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825ee578
	if (cr6.eq) goto loc_825EE578;
	// bl 0x8217d890
	ctx.lr = 0x825EE56C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_825EE578:
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

PPC_WEAK_FUNC(sub_825EE548) {
	__imp__sub_825EE548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE58C) {
	__imp__sub_825EE58C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE590) {
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
	// li r9,224
	ctx.r9.s64 = 224;
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
	// beq cr6,0x825ee5dc
	if (cr6.eq) goto loc_825EE5DC;
	// mulli r3,r10,224
	ctx.r3.s64 = ctx.r10.s64 * 224;
	// bl 0x82130528
	ctx.lr = 0x825EE5D8;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_825EE5DC:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x825EE5EC;
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

PPC_WEAK_FUNC(sub_825EE590) {
	__imp__sub_825EE590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE604) {
	__imp__sub_825EE604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE608) {
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
	// li r9,8
	ctx.r9.s64 = 8;
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
	// beq cr6,0x825ee654
	if (cr6.eq) goto loc_825EE654;
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x825EE650;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_825EE654:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x825EE664;
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

PPC_WEAK_FUNC(sub_825EE608) {
	__imp__sub_825EE608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE67C) {
	__imp__sub_825EE67C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE680) {
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
	// li r9,16
	ctx.r9.s64 = 16;
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
	// beq cr6,0x825ee6cc
	if (cr6.eq) goto loc_825EE6CC;
	// rlwinm r3,r10,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x825EE6C8;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_825EE6CC:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x825EE6DC;
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

PPC_WEAK_FUNC(sub_825EE680) {
	__imp__sub_825EE680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE6F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EE6F4) {
	__imp__sub_825EE6F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE6F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,4(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
loc_825EE718:
	// rlwinm r11,r9,29,3,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// slw r5,r6,r8
	ctx.r5.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r8.u8 & 0x3F));
	// lbzx r11,r11,r4
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// and r8,r5,r11
	ctx.r8.u64 = ctx.r5.u64 & r11.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x825ee780
	if (!cr6.eq) goto loc_825EE780;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// clrlwi r5,r8,31
	ctx.r5.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x825ee774
	if (!cr6.eq) goto loc_825EE774;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee76c
	if (cr6.eq) goto loc_825EE76C;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lhz r8,6(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// sth r5,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r5.u16);
loc_825EE76C:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x825ee780
	goto loc_825EE780;
loc_825EE774:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r5,r8,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
loc_825EE780:
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x825ee718
	if (cr6.lt) goto loc_825EE718;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EE6F8) {
	__imp__sub_825EE6F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE798) {
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
	ctx.lr = 0x825EE7A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825ee7d4
	if (cr6.eq) goto loc_825EE7D4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x825EE7C8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
loc_825EE7D4:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ee93c
	if (cr6.eq) goto loc_825EE93C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r11,-26560
	r26.s64 = r11.s64 + -26560;
loc_825EE7F0:
	// lwz r29,0(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r31,r27,r29
	r31.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825ee858
	if (cr6.eq) goto loc_825EE858;
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x825EE810;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x825ee838
	if (cr6.eq) goto loc_825EE838;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x825ee84c
	goto loc_825EE84C;
loc_825EE838:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2378
	ctx.lr = 0x825EE848;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_825EE84C:
	// lwzx r10,r27,r29
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r27,r29
	PPC_STORE_U32(r27.u32 + r29.u32, r11.u32);
loc_825EE858:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r31,r27,r11
	r31.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825ee928
	if (cr6.eq) goto loc_825EE928;
loc_825EE868:
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825ee8ec
	if (cr6.eq) goto loc_825EE8EC;
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x825ee8d0
	if (!cr0.gt) goto loc_825EE8D0;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_825EE890:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x825ee8b0
	if (cr6.lt) goto loc_825EE8B0;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x825ee8b4
	if (cr6.lt) goto loc_825EE8B4;
loc_825EE8B0:
	// li r11,0
	r11.s64 = 0;
loc_825EE8B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825ee948
	if (!cr6.eq) goto loc_825EE948;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x825ee890
	if (cr6.lt) goto loc_825EE890;
loc_825EE8D0:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2378
	ctx.lr = 0x825EE8DC;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_825EE8E0:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_825EE8EC:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825ee904
	if (cr6.eq) goto loc_825EE904;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r24
	ctr.u64 = r24.u64;
	// bctrl 
	ctx.lr = 0x825EE904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EE904:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x825ee91c
	if (cr6.eq) goto loc_825EE91C;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r23
	ctr.u64 = r23.u64;
	// bctrl 
	ctx.lr = 0x825EE91C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EE91C:
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825ee868
	if (!cr6.eq) goto loc_825EE868;
loc_825EE928:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r22,r11
	cr6.compare<uint32_t>(r22.u32, r11.u32, xer);
	// blt cr6,0x825ee7f0
	if (cr6.lt) goto loc_825EE7F0;
loc_825EE93C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_825EE948:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x825ee8d0
	if (cr6.eq) goto loc_825EE8D0;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x825ee8e0
	goto loc_825EE8E0;
}

PPC_WEAK_FUNC(sub_825EE798) {
	__imp__sub_825EE798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE970) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r11,-1680(r31)
	PPC_STORE_U32(r31.u32 + -1680, r11.u32);
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// bl 0x825ee428
	ctx.lr = 0x825EE99C;
	sub_825EE428(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-1680(r31)
	PPC_STORE_U32(r31.u32 + -1680, r11.u32);
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

PPC_WEAK_FUNC(sub_825EE970) {
	__imp__sub_825EE970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EE9B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x825EE9C0;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,108(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 108);
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// srawi r10,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r10.s64 = r11.s32 >> 3;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825EE9E4;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// addi r29,r30,104
	r29.s64 = r30.s64 + 104;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825eda40
	ctx.lr = 0x825EEA00;
	sub_825EDA40(ctx, base);
	// lwz r3,124(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// bl 0x825fc488
	ctx.lr = 0x825EEA08;
	sub_825FC488(ctx, base);
	// lwz r3,128(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x825EEA1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x825EEA30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee6f8
	ctx.lr = 0x825EEA3C;
	sub_825EE6F8(ctx, base);
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825EE9B8) {
	__imp__sub_825EE9B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EEA44) {
	__imp__sub_825EEA44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEA48) {
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
	ctx.lr = 0x825EEA50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r27,r26
	r27.u64 = r26.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825eeab4
	if (cr6.eq) goto loc_825EEAB4;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_825EEA70:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r31,r28,r11
	r31.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825eeaa0
	if (cr6.eq) goto loc_825EEAA0;
loc_825EEA80:
	// mr r30,r31
	r30.u64 = r31.u64;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x825EEA90;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x825EEA98;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825eea80
	if (!cr6.eq) goto loc_825EEA80;
loc_825EEAA0:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x825eea70
	if (cr6.lt) goto loc_825EEA70;
loc_825EEAB4:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EEABC;
	sub_82130588(ctx, base);
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
	// sth r26,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r26.u16);
	// sth r26,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r26.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825EEA48) {
	__imp__sub_825EEA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEAD0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x825fc480
	sub_825FC480(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825EEAD0) {
	__imp__sub_825EEAD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEAD8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x825fa2e0
	sub_825FA2E0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825EEAD8) {
	__imp__sub_825EEAD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEAE0) {
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
	ctx.lr = 0x825EEAE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r10,r11,21260
	ctx.r10.s64 = r11.s64 + 21260;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x825fc480
	ctx.lr = 0x825EEB0C;
	sub_825FC480(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825eea48
	ctx.lr = 0x825EEB14;
	sub_825EEA48(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// clrlwi r8,r29,31
	ctx.r8.u64 = r29.u32 & 0x1;
	// addi r7,r9,20884
	ctx.r7.s64 = ctx.r9.s64 + 20884;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x825eeb38
	if (cr6.eq) goto loc_825EEB38;
	// bl 0x82130588
	ctx.lr = 0x825EEB34;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825EEB38:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EEAE0) {
	__imp__sub_825EEAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEB40) {
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
	ctx.lr = 0x825EEB48;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r26,r31,4
	r26.s64 = r31.s64 + 4;
	// addi r10,r11,21244
	ctx.r10.s64 = r11.s64 + 21244;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// bl 0x821c2f70
	ctx.lr = 0x825EEB78;
	sub_821C2F70(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825ee590
	ctx.lr = 0x825EEB84;
	sub_825EE590(ctx, base);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x825ee608
	ctx.lr = 0x825EEB90;
	sub_825EE608(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// li r8,12
	ctx.r8.s64 = 12;
	// sth r30,84(r31)
	PPC_STORE_U16(r31.u32 + 84, r30.u16);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// sth r30,86(r31)
	PPC_STORE_U16(r31.u32 + 86, r30.u16);
	// divw r7,r28,r8
	ctx.r7.s32 = r28.s32 / ctx.r8.s32;
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// clrlwi r4,r7,16
	ctx.r4.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r30,96(r31)
	PPC_STORE_U8(r31.u32 + 96, r30.u8);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// bl 0x825ee680
	ctx.lr = 0x825EEBC8;
	sub_825EE680(ctx, base);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
	// stb r30,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ed3a8
	ctx.lr = 0x825EEBDC;
	sub_825ED3A8(ctx, base);
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x825fc410
	ctx.lr = 0x825EEBE4;
	sub_825FC410(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eebf8
	if (cr6.eq) goto loc_825EEBF8;
	// bl 0x825fa2e8
	ctx.lr = 0x825EEBF0;
	sub_825FA2E8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x825eebfc
	goto loc_825EEBFC;
loc_825EEBF8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825EEBFC:
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x825EEC08;
	sub_82130528(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r29,r11,21260
	r29.s64 = r11.s64 + 21260;
	// beq cr6,0x825eec3c
	if (cr6.eq) goto loc_825EEC3C;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r30,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r30.u16);
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r30.u32);
	// b 0x825eec40
	goto loc_825EEC40;
loc_825EEC3C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825EEC40:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r11,-1656(r10)
	PPC_STORE_U32(ctx.r10.u32 + -1656, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x825EEC54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eec80
	if (cr6.eq) goto loc_825EEC80;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r30,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r30.u16);
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r30.u32);
	// b 0x825eec84
	goto loc_825EEC84;
loc_825EEC80:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825EEC84:
	// lis r28,-32112
	r28.s64 = -2104492032;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r11,-1652(r28)
	PPC_STORE_U32(r28.u32 + -1652, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x825EEC98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eecb8
	if (cr6.eq) goto loc_825EECB8;
	// sth r30,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r30.u16);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r30,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r30.u16);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stb r30,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r30.u8);
	// b 0x825eecbc
	goto loc_825EECBC;
loc_825EECB8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825EECBC:
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r11,-1676(r29)
	PPC_STORE_U32(r29.u32 + -1676, r11.u32);
	// bl 0x825fd100
	ctx.lr = 0x825EECCC;
	sub_825FD100(ctx, base);
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825eed20
	if (!cr6.eq) goto loc_825EED20;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r30
	r11.u64 = r30.u64;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r11,-1652(r28)
	PPC_STORE_U32(r28.u32 + -1652, r11.u32);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r11,8088(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8088, r11.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r10,6916(r8)
	PPC_STORE_U32(ctx.r8.u32 + 6916, ctx.r10.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// stw r9,6924(r7)
	PPC_STORE_U32(ctx.r7.u32 + 6924, ctx.r9.u32);
	// stw r11,6920(r6)
	PPC_STORE_U32(ctx.r6.u32 + 6920, r11.u32);
	// addi r3,r4,6556
	ctx.r3.s64 = ctx.r4.s64 + 6556;
	// stw r9,-1676(r29)
	PPC_STORE_U32(r29.u32 + -1676, ctx.r9.u32);
	// stw r10,6596(r5)
	PPC_STORE_U32(ctx.r5.u32 + 6596, ctx.r10.u32);
	// bl 0x821c8f70
	ctx.lr = 0x825EED20;
	sub_821C8F70(ctx, base);
loc_825EED20:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x825f9068
	ctx.lr = 0x825EED2C;
	sub_825F9068(ctx, base);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r10,23088
	ctx.r7.s64 = ctx.r10.s64 + 23088;
	// stb r8,177(r6)
	PPC_STORE_U8(ctx.r6.u32 + 177, ctx.r8.u8);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r30,180(r6)
	PPC_STORE_U32(ctx.r6.u32 + 180, r30.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_825EED68:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x825eed68
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825EED68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825EEB40) {
	__imp__sub_825EEB40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EED88) {
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
	ctx.lr = 0x825EED90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,21244
	ctx.r10.s64 = r11.s64 + 21244;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x825ed3a8
	ctx.lr = 0x825EEDAC;
	sub_825ED3A8(ctx, base);
	// bl 0x825fb810
	ctx.lr = 0x825EEDB0;
	sub_825FB810(ctx, base);
	// lwz r9,100(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825eee00
	if (cr6.eq) goto loc_825EEE00;
loc_825EEDBC:
	// lwz r31,100(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r11,100(r28)
	PPC_STORE_U32(r28.u32 + 100, r11.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825EEDDC;
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
	ctx.lr = 0x825EEDF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,100(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x825eedbc
	if (!cr6.eq) goto loc_825EEDBC;
loc_825EEE00:
	// lis r30,-32112
	r30.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// stb r11,6592(r30)
	PPC_STORE_U8(r30.u32 + 6592, r11.u8);
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eee2c
	if (cr6.eq) goto loc_825EEE2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825EEE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EEE2C:
	// li r31,0
	r31.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stb r11,6592(r30)
	PPC_STORE_U8(r30.u32 + 6592, r11.u8);
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eee58
	if (cr6.eq) goto loc_825EEE58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825EEE58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EEE58:
	// lwz r30,124(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 124);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825eee7c
	if (cr6.eq) goto loc_825EEE7C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825fc480
	ctx.lr = 0x825EEE6C;
	sub_825FC480(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825eea48
	ctx.lr = 0x825EEE74;
	sub_825EEA48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x825EEE7C;
	sub_82130588(ctx, base);
loc_825EEE7C:
	// lwz r11,300(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 300);
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825eeec4
	if (!cr6.gt) goto loc_825EEEC4;
	// addi r30,r28,140
	r30.s64 = r28.s64 + 140;
loc_825EEE90:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825eeeb0
	if (cr6.eq) goto loc_825EEEB0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825EEEB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EEEB0:
	// lwz r11,300(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 300);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825eee90
	if (cr6.lt) goto loc_825EEE90;
loc_825EEEC4:
	// lbz r11,136(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825eef20
	if (!cr6.eq) goto loc_825EEF20;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r31
	r11.u64 = r31.u64;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r11,8088(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8088, r11.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// stw r11,6920(r6)
	PPC_STORE_U32(ctx.r6.u32 + 6920, r11.u32);
	// stw r10,6916(r8)
	PPC_STORE_U32(ctx.r8.u32 + 6916, ctx.r10.u32);
	// stw r10,6596(r5)
	PPC_STORE_U32(ctx.r5.u32 + 6596, ctx.r10.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,-1652(r3)
	PPC_STORE_U32(ctx.r3.u32 + -1652, r11.u32);
	// stw r9,6924(r7)
	PPC_STORE_U32(ctx.r7.u32 + 6924, ctx.r9.u32);
	// addi r3,r10,6556
	ctx.r3.s64 = ctx.r10.s64 + 6556;
	// stw r9,-1676(r4)
	PPC_STORE_U32(ctx.r4.u32 + -1676, ctx.r9.u32);
	// bl 0x821c8f70
	ctx.lr = 0x825EEF20;
	sub_821C8F70(ctx, base);
loc_825EEF20:
	// lbz r11,120(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 120);
	// addi r30,r28,104
	r30.s64 = r28.s64 + 104;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825eef38
	if (cr6.eq) goto loc_825EEF38;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EEF38;
	sub_82130588(ctx, base);
loc_825EEF38:
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// addi r29,r28,80
	r29.s64 = r28.s64 + 80;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// lbz r11,96(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825eef64
	if (cr6.eq) goto loc_825EEF64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EEF64;
	sub_82130588(ctx, base);
loc_825EEF64:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r30,r28,60
	r30.s64 = r28.s64 + 60;
	// sth r31,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r31.u16);
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// stb r31,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r31.u8);
	// lbz r11,76(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825eef90
	if (cr6.eq) goto loc_825EEF90;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EEF90;
	sub_82130588(ctx, base);
loc_825EEF90:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// addi r29,r28,40
	r29.s64 = r28.s64 + 40;
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// lbz r11,56(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825eefbc
	if (cr6.eq) goto loc_825EEFBC;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EEFBC;
	sub_82130588(ctx, base);
loc_825EEFBC:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// sth r31,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r31.u16);
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// stb r31,16(r29)
	PPC_STORE_U8(r29.u32 + 16, r31.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825EED88) {
	__imp__sub_825EED88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EEFD8) {
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
	// bl 0x825eed88
	ctx.lr = 0x825EEFF8;
	sub_825EED88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ef010
	if (cr6.eq) goto loc_825EF010;
	// bl 0x82130588
	ctx.lr = 0x825EF00C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825EF010:
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

PPC_WEAK_FUNC(sub_825EEFD8) {
	__imp__sub_825EEFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF028) {
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
	ctx.lr = 0x825EF030;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,21348
	ctx.r9.s64 = r11.s64 + 21348;
	// lhz r10,50(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 50);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825ef090
	if (cr6.eq) goto loc_825EF090;
	// li r30,0
	r30.s64 = 0;
loc_825EF058:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ef07c
	if (cr6.eq) goto loc_825EF07C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825EF07C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EF07C:
	// lhz r11,50(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 50);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825ef058
	if (cr6.lt) goto loc_825EF058;
loc_825EF090:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x825EF098;
	sub_82130588(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x8229d838
	ctx.lr = 0x825EF0A0;
	sub_8229D838(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825fdc88
	ctx.lr = 0x825EF0A8;
	sub_825FDC88(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EF028) {
	__imp__sub_825EF028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF0B0) {
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
	// bl 0x825ef028
	ctx.lr = 0x825EF0D0;
	sub_825EF028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ef0e8
	if (cr6.eq) goto loc_825EF0E8;
	// bl 0x82130588
	ctx.lr = 0x825EF0E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825EF0E8:
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

PPC_WEAK_FUNC(sub_825EF0B0) {
	__imp__sub_825EF0B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF100) {
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
	ctx.lr = 0x825EF108;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// bl 0x825fdbf8
	ctx.lr = 0x825EF118;
	sub_825FDBF8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32161
	ctx.r10.s64 = -2107703296;
	// addi r9,r11,21348
	ctx.r9.s64 = r11.s64 + 21348;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// addi r5,r10,-6840
	ctx.r5.s64 = ctx.r10.s64 + -6840;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r27,56
	ctx.r3.s64 = r27.s64 + 56;
	// bl 0x825ee798
	ctx.lr = 0x825EF13C;
	sub_825EE798(ctx, base);
	// lwz r4,24(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825ef15c
	if (cr6.eq) goto loc_825EF15C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217d890
	ctx.lr = 0x825EF150;
	sub_8217D890(ctx, base);
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,24(r27)
	PPC_STORE_U32(r27.u32 + 24, ctx.r10.u32);
loc_825EF15C:
	// lhz r11,50(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 50);
	// li r25,1
	r25.s64 = 1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x825ef210
	if (!cr6.gt) goto loc_825EF210;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r29,4
	r29.s64 = 4;
	// addi r24,r11,-26560
	r24.s64 = r11.s64 + -26560;
loc_825EF178:
	// lwz r28,24(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825ef1fc
	if (cr6.eq) goto loc_825EF1FC;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825ef1ec
	if (cr6.eq) goto loc_825EF1EC;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x825EF1A4;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x825ef1cc
	if (cr6.eq) goto loc_825EF1CC;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x825ef1e0
	goto loc_825EF1E0;
loc_825EF1CC:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821d2378
	ctx.lr = 0x825EF1DC;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_825EF1E0:
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r11.u32);
loc_825EF1EC:
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x825fda90
	ctx.lr = 0x825EF1FC;
	sub_825FDA90(ctx, base);
loc_825EF1FC:
	// lhz r11,50(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 50);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x825ef178
	if (cr6.lt) goto loc_825EF178;
loc_825EF210:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// addi r3,r11,-1640
	ctx.r3.s64 = r11.s64 + -1640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x825EF224;
	sub_823D9890(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r10,29(r27)
	PPC_STORE_U8(r27.u32 + 29, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_825EF100) {
	__imp__sub_825EF100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x825ef100
	sub_825EF100(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825EF238) {
	__imp__sub_825EF238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF244) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF244) {
	__imp__sub_825EF244(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF248) {
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
	ctx.lr = 0x825EF250;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x825ef2b8
	if (cr6.eq) goto loc_825EF2B8;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825EF274:
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r7,-1
	ctx.r7.s64 = -1;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r28
	ctx.r6.u64 = r11.u64 + r28.u64;
	// bl 0x8260b740
	ctx.lr = 0x825EF298;
	sub_8260B740(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r31,r11
	ctx.r10.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x825ef274
	if (!cr6.eq) goto loc_825EF274;
loc_825EF2B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825EF248) {
	__imp__sub_825EF248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF2C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_825EF2D8:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r8,261
	ctx.r8.s64 = ctx.r8.s64 + 261;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r3
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825ef314
	if (cr6.eq) goto loc_825EF314;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r6,r8,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r7,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r7.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
loc_825EF314:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// bne cr6,0x825ef2d8
	if (!cr6.eq) goto loc_825EF2D8;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF2C0) {
	__imp__sub_825EF2C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF33C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF33C) {
	__imp__sub_825EF33C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF340) {
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
	ctx.lr = 0x825EF348;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// stw r11,6588(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6588, r11.u32);
	// lwz r9,1024(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 1024);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x825ef394
	if (!cr6.gt) goto loc_825EF394;
	// addi r31,r29,1044
	r31.s64 = r29.s64 + 1044;
loc_825EF370:
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// bl 0x82130588
	ctx.lr = 0x825EF378;
	sub_82130588(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825EF380;
	sub_82130588(ctx, base);
	// lwz r11,1024(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1024);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x825ef370
	if (cr6.lt) goto loc_825EF370;
loc_825EF394:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825EF340) {
	__imp__sub_825EF340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF39C) {
	__imp__sub_825EF39C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF3A0) {
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
	ctx.lr = 0x825EF3A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r4,1024(r28)
	PPC_STORE_U32(r28.u32 + 1024, ctx.r4.u32);
	// addi r27,r11,21408
	r27.s64 = r11.s64 + 21408;
	// ble cr6,0x825ef468
	if (!cr6.gt) goto loc_825EF468;
	// addi r30,r28,1028
	r30.s64 = r28.s64 + 1028;
loc_825EF3D0:
	// li r3,776
	ctx.r3.s64 = 776;
	// bl 0x82130528
	ctx.lr = 0x825EF3D8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825ef3ec
	if (cr6.eq) goto loc_825EF3EC;
	// bl 0x8260b730
	ctx.lr = 0x825EF3E4;
	sub_8260B730(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x825ef3f0
	goto loc_825EF3F0;
loc_825EF3EC:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_825EF3F0:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r3,204
	ctx.r3.s64 = 204;
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x825EF400;
	sub_82130528(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825ef43c
	if (cr6.eq) goto loc_825EF43C;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
loc_825EF414:
	// stb r31,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, r31.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r31,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r31.u8);
	// stb r31,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r31.u8);
	// stb r31,1(r11)
	PPC_STORE_U8(r11.u32 + 1, r31.u8);
	// stb r31,2(r11)
	PPC_STORE_U8(r11.u32 + 2, r31.u8);
	// stw r31,6(r11)
	PPC_STORE_U32(r11.u32 + 6, r31.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x825ef414
	if (!cr0.lt) goto loc_825EF414;
	// b 0x825ef440
	goto loc_825EF440;
loc_825EF43C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_825EF440:
	// stw r4,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r4.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,17
	ctx.r5.s64 = 17;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x825ef248
	ctx.lr = 0x825EF454;
	sub_825EF248(ctx, base);
	// lwz r11,1024(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1024);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825ef3d0
	if (cr6.lt) goto loc_825EF3D0;
loc_825EF468:
	// addi r4,r27,240
	ctx.r4.s64 = r27.s64 + 240;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef2c0
	ctx.lr = 0x825EF474;
	sub_825EF2C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825EF3A0) {
	__imp__sub_825EF3A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF47C) {
	__imp__sub_825EF47C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF480) {
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
	// li r10,127
	ctx.r10.s64 = 127;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_825EF4A0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x825ef4a0
	if (!cr0.lt) goto loc_825EF4A0;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,1060(r31)
	PPC_STORE_U8(r31.u32 + 1060, r11.u8);
	// stb r11,1061(r31)
	PPC_STORE_U8(r31.u32 + 1061, r11.u8);
	// stb r11,1062(r31)
	PPC_STORE_U8(r31.u32 + 1062, r11.u8);
	// stb r11,1063(r31)
	PPC_STORE_U8(r31.u32 + 1063, r11.u8);
	// stb r11,1064(r31)
	PPC_STORE_U8(r31.u32 + 1064, r11.u8);
	// stw r11,1068(r31)
	PPC_STORE_U32(r31.u32 + 1068, r11.u32);
	// stw r31,6588(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6588, r31.u32);
	// stw r11,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r11.u32);
	// stw r11,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, r11.u32);
	// stw r11,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r11.u32);
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// stw r11,1044(r31)
	PPC_STORE_U32(r31.u32 + 1044, r11.u32);
	// stw r11,1048(r31)
	PPC_STORE_U32(r31.u32 + 1048, r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(r31.u32 + 1052, r11.u32);
	// stw r11,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r11.u32);
	// bl 0x825ef3a0
	ctx.lr = 0x825EF500;
	sub_825EF3A0(ctx, base);
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

PPC_WEAK_FUNC(sub_825EF480) {
	__imp__sub_825EF480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,27644(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x825EF548;
	sub_823DBBC8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x825EF554;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f30,0(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f30,12(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF518) {
	__imp__sub_825EF518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,64
	ctx.r10.s64 = 64;
	// lfs f13,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r9,255
	ctx.r9.s64 = 255;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r10,51(r3)
	PPC_STORE_U8(ctx.r3.u32 + 51, ctx.r10.u8);
	// stb r10,50(r3)
	PPC_STORE_U8(ctx.r3.u32 + 50, ctx.r10.u8);
	// lfs f12,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// stb r10,49(r3)
	PPC_STORE_U8(ctx.r3.u32 + 49, ctx.r10.u8);
	// stb r10,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r10.u8);
	// stb r11,55(r3)
	PPC_STORE_U8(ctx.r3.u32 + 55, r11.u8);
	// stb r11,54(r3)
	PPC_STORE_U8(ctx.r3.u32 + 54, r11.u8);
	// stb r11,53(r3)
	PPC_STORE_U8(ctx.r3.u32 + 53, r11.u8);
	// stb r11,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, r11.u8);
	// stb r10,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r10.u8);
	// stb r10,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r10.u8);
	// stb r10,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r10.u8);
	// stb r10,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r10.u8);
	// stb r11,63(r3)
	PPC_STORE_U8(ctx.r3.u32 + 63, r11.u8);
	// stb r11,62(r3)
	PPC_STORE_U8(ctx.r3.u32 + 62, r11.u8);
	// stb r11,61(r3)
	PPC_STORE_U8(ctx.r3.u32 + 61, r11.u8);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// stfs f13,128(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// stfs f13,116(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stfs f0,124(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stfs f0,76(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stb r9,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r9.u8);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stb r9,69(r3)
	PPC_STORE_U8(ctx.r3.u32 + 69, ctx.r9.u8);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stb r9,70(r3)
	PPC_STORE_U8(ctx.r3.u32 + 70, ctx.r9.u8);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stb r9,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, ctx.r9.u8);
	// stfs f12,96(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r11.u32);
	// stfs f12,92(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stb r11,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r11.u8);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stw r6,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r6.u32);
	// stfs f0,108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f12,104(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f12,100(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF598) {
	__imp__sub_825EF598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF694) {
	__imp__sub_825EF694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF698) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r31,140(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x821811c0
	ctx.lr = 0x825EF6C0;
	sub_821811C0(ctx, base);
	// stw r3,140(r30)
	PPC_STORE_U32(r30.u32 + 140, ctx.r3.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825ef6f4
	if (cr6.eq) goto loc_825EF6F4;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x825EF6D4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x825ef6f4
	if (!cr6.eq) goto loc_825EF6F4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825EF6F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825EF6F4:
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

PPC_WEAK_FUNC(sub_825EF698) {
	__imp__sub_825EF698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF70C) {
	__imp__sub_825EF70C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_825EF724:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne cr6,0x825ef724
	if (!cr6.eq) goto loc_825EF724;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF710) {
	__imp__sub_825EF710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_825EF760:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne cr6,0x825ef760
	if (!cr6.eq) goto loc_825EF760;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF740) {
	__imp__sub_825EF740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF77C) {
	__imp__sub_825EF77C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x825ef7fc
	if (cr6.gt) {
		sub_825EF7FC(ctx, base);
		return;
	}
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,-2140
	r12.s64 = r12.s64 + -2140;
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

PPC_WEAK_FUNC(sub_825EF780) {
	__imp__sub_825EF780(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF7A4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r18{};
	PPCRegister r30{};
	// lwz r18,-2052(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2052);
	// lwz r18,-2052(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2052);
	// lwz r18,-2116(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2116);
	// lwz r18,-2108(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2108);
	// lwz r18,-2088(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2088);
	// lwz r18,-2108(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -2108);
	// lbz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF7A4) {
	__imp__sub_825EF7A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF7C4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF7C4) {
	__imp__sub_825EF7C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF7D8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x825ef7f4
	if (!cr6.eq) goto loc_825EF7F4;
	// li r11,0
	r11.s64 = 0;
loc_825EF7F4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF7D8) {
	__imp__sub_825EF7D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF7FC) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF7FC) {
	__imp__sub_825EF7FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF804) {
	__imp__sub_825EF804(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r30{};
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x825ef8b0
	if (cr6.gt) goto loc_825EF8B0;
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,-1992
	r12.s64 = r12.s64 + -1992;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-1968(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1968);
	// lwz r18,-1968(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1968);
	// lwz r18,-1944(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1944);
	// lwz r18,-1924(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1924);
	// lwz r18,-1904(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1904);
	// lwz r18,-1872(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1872);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x823dd7f0
	ctx.lr = 0x825EF858;
	sub_823DD7F0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lbz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_825EF8B0:
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

PPC_WEAK_FUNC(sub_825EF808) {
	__imp__sub_825EF808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF8C4) {
	__imp__sub_825EF8C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF8C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r30{};
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x825ef98c
	if (cr6.gt) goto loc_825EF98C;
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,-1800
	r12.s64 = r12.s64 + -1800;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-1776(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1776);
	// lwz r18,-1776(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1776);
	// lwz r18,-1748(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1748);
	// lwz r18,-1712(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1712);
	// lwz r18,-1672(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1672);
	// lwz r18,-1652(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1652);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x823de058
	ctx.lr = 0x825EF918;
	sub_823DE058(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lfs f1,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_825EF98C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF8C8) {
	__imp__sub_825EF8C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EF9A4) {
	__imp__sub_825EF9A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF9A8) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x825EF9D0;
	sub_821C9790(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_825EF9A8) {
	__imp__sub_825EF9A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EF9F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x825efa04
	if (!cr6.eq) goto loc_825EFA04;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// blr 
	return;
loc_825EFA04:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EF9F0) {
	__imp__sub_825EF9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EFA0C) {
	__imp__sub_825EFA0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFA10) {
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
	ctx.lr = 0x825EFA18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825efa34
	if (!cr6.eq) goto loc_825EFA34;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_825EFA34:
	// mr r28,r31
	r28.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,12
	r29.s64 = 12;
loc_825EFA40:
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bgt cr6,0x825efa6c
	if (cr6.gt) goto loc_825EFA6C;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x825EFA58;
	sub_823DA950(ctx, base);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825efa40
	if (!cr6.eq) goto loc_825EFA40;
loc_825EFA6C:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825EFA10) {
	__imp__sub_825EFA10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFA80) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825efaac
	if (!cr6.eq) goto loc_825EFAAC;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x825efa10
	ctx.lr = 0x825EFAA8;
	sub_825EFA10(ctx, base);
	// b 0x825efab8
	goto loc_825EFAB8;
loc_825EFAAC:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x825efb14
	if (!cr6.eq) goto loc_825EFB14;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_825EFAB8:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825efb28
	if (cr6.eq) goto loc_825EFB28;
	// li r4,46
	ctx.r4.s64 = 46;
	// bl 0x823dd850
	ctx.lr = 0x825EFAC8;
	sub_823DD850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825efb28
	if (cr6.eq) goto loc_825EFB28;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,48
	cr6.compare<uint32_t>(ctx.r10.u32, 48, xer);
	// bne cr6,0x825efaf4
	if (!cr6.eq) goto loc_825EFAF4;
loc_825EFAE0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,48
	cr6.compare<uint32_t>(ctx.r10.u32, 48, xer);
	// beq cr6,0x825efae0
	if (cr6.eq) goto loc_825EFAE0;
loc_825EFAF4:
	// lbz r11,1(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_825EFB14:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x825efb28
	if (cr6.eq) goto loc_825EFB28;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x825efb2c
	if (!cr6.eq) goto loc_825EFB2C;
loc_825EFB28:
	// li r3,1
	ctx.r3.s64 = 1;
loc_825EFB2C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EFA80) {
	__imp__sub_825EFA80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFB3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EFB3C) {
	__imp__sub_825EFB3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFB40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r30{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x825efc90
	if (cr6.gt) goto loc_825EFC90;
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,-1156
	r12.s64 = r12.s64 + -1156;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-1132(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1132);
	// lwz r18,-880(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -880);
	// lwz r18,-1096(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1096);
	// lwz r18,-1028(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -1028);
	// lwz r18,-984(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -984);
	// lwz r18,-880(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -880);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825efa10
	ctx.lr = 0x825EFBA4;
	sub_825EFA10(ctx, base);
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
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825efbe0
	if (cr6.eq) goto loc_825EFBE0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-13576
	ctx.r3.s64 = r11.s64 + -13576;
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
loc_825EFBE0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-13568
	ctx.r3.s64 = r11.s64 + -13568;
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// bl 0x82137a08
	ctx.lr = 0x825EFC10;
	sub_82137A08(ctx, base);
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
	// lfs f1,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fctiwz f0,f1
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f1,f11
	cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// bne cr6,0x825efc60
	if (!cr6.eq) goto loc_825EFC60;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r5,r11,22640
	ctx.r5.s64 = r11.s64 + 22640;
	// b 0x825efc68
	goto loc_825EFC68;
loc_825EFC60:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r11,9792
	ctx.r5.s64 = r11.s64 + 9792;
loc_825EFC68:
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x825EFC78;
	sub_82137A08(ctx, base);
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
loc_825EFC90:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
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

PPC_WEAK_FUNC(sub_825EFB40) {
	__imp__sub_825EFB40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EFCAC) {
	__imp__sub_825EFCAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFCB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
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
	// stwu r1,-3184(r1)
	ea = -3184 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x825efe70
	if (cr6.gt) goto loc_825EFE70;
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,-784
	r12.s64 = r12.s64 + -784;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-756(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -756);
	// lwz r18,-656(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -656);
	// lwz r18,-568(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -568);
	// lwz r18,-540(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -540);
	// lwz r18,-516(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -516);
	// lwz r18,-484(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -484);
	// lwz r18,-424(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + -424);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x825efd20
	if (!cr6.eq) goto loc_825EFD20;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x825efd30
	goto loc_825EFD30;
loc_825EFD20:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// addi r4,r1,1104
	ctx.r4.s64 = ctx.r1.s64 + 1104;
	// bl 0x825efb40
	ctx.lr = 0x825EFD2C;
	sub_825EFB40(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_825EFD30:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x825efa10
	ctx.lr = 0x825EFD40;
	sub_825EFA10(ctx, base);
loc_825EFD40:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x825efd64
	if (cr6.eq) goto loc_825EFD64;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825efd40
	if (cr6.eq) goto loc_825EFD40;
loc_825EFD64:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x825efd84
	if (!cr6.eq) goto loc_825EFD84;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x825efd94
	goto loc_825EFD94;
loc_825EFD84:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// addi r4,r1,2128
	ctx.r4.s64 = ctx.r1.s64 + 2128;
	// bl 0x825efb40
	ctx.lr = 0x825EFD90;
	sub_825EFB40(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_825EFD94:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_825EFD98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x825efdbc
	if (cr6.eq) goto loc_825EFDBC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x825efd98
	if (cr6.eq) goto loc_825EFD98;
loc_825EFDBC:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
	// bl 0x825ef780
	ctx.lr = 0x825EFDCC;
	sub_825EF780(ctx, base);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
	// bl 0x825ef808
	ctx.lr = 0x825EFDE8;
	sub_825EF808(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
	// bl 0x825ef8c8
	ctx.lr = 0x825EFE00;
	sub_825EF8C8(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x825efe14
	if (cr6.eq) goto loc_825EFE14;
	// li r11,0
	r11.s64 = 0;
loc_825EFE14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// b 0x825efe74
	goto loc_825EFE74;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x825efe40
	if (!cr6.eq) goto loc_825EFE40;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
loc_825EFE40:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x825efe74
	goto loc_825EFE74;
loc_825EFE70:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825EFE74:
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
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

PPC_WEAK_FUNC(sub_825EFCB0) {
	__imp__sub_825EFCB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825EFE8C) {
	__imp__sub_825EFE8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFE90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,6596(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6596);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r3,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r3.u32);
	// sth r8,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r8.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825EFE90) {
	__imp__sub_825EFE90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFEC0) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825eff0c
	if (cr6.eq) goto loc_825EFF0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825efec0
	ctx.lr = 0x825EFEE4;
	sub_825EFEC0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r11,6596(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6596);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lhz r10,6(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// sth r7,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r7.u16);
loc_825EFF0C:
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

PPC_WEAK_FUNC(sub_825EFEC0) {
	__imp__sub_825EFEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825EFF20) {
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
	ctx.lr = 0x825EFF28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
loc_825EFF40:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825eff40
	if (!cr6.eq) goto loc_825EFF40;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addic. r11,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	r11.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x825f0014
	if (!cr0.gt) goto loc_825F0014;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r10,12
	ctx.r10.s64 = 12;
	// lis r9,0
	ctx.r9.s64 = 0;
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// ori r24,r9,65535
	r24.u64 = ctx.r9.u64 | 65535;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// addi r26,r11,22648
	r26.s64 = r11.s64 + 22648;
	// addi r25,r10,22664
	r25.s64 = ctx.r10.s64 + 22664;
loc_825EFF90:
	// lwz r10,6596(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 6596);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825effb0
	if (!cr6.eq) goto loc_825EFFB0;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821bd618
	ctx.lr = 0x825EFFAC;
	sub_821BD618(ctx, base);
	// lwz r10,6596(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 6596);
loc_825EFFB0:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r8,6(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r6,r8,r24
	ctx.r6.u64 = ctx.r8.u64 + r24.u64;
	// sth r6,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r6.u16);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// beq cr6,0x825effec
	if (cr6.eq) goto loc_825EFFEC;
	// stw r27,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r27.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
	// b 0x825efff0
	goto loc_825EFFF0;
loc_825EFFEC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_825EFFF0:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x825F0000;
	sub_823DA950(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// addi r29,r11,12
	r29.s64 = r11.s64 + 12;
	// bne 0x825eff90
	if (!cr0.eq) goto loc_825EFF90;
loc_825F0014:
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_825EFF20) {
	__imp__sub_825EFF20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F0024) {
	__imp__sub_825F0024(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0028) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x825eff20
	ctx.lr = 0x825F0044;
	sub_825EFF20(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
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

PPC_WEAK_FUNC(sub_825F0028) {
	__imp__sub_825F0028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F0064) {
	__imp__sub_825F0064(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0068) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x825F0094;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x821be250
	ctx.lr = 0x825F00A4;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,5
	ctx.r4.s64 = r31.s64 + 5;
	// bl 0x821be250
	ctx.lr = 0x825F00B4;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,6
	ctx.r4.s64 = r31.s64 + 6;
	// bl 0x821be250
	ctx.lr = 0x825F00C4;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,7
	ctx.r4.s64 = r31.s64 + 7;
	// bl 0x821be250
	ctx.lr = 0x825F00D4;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// bl 0x821be250
	ctx.lr = 0x825F00E4;
	sub_821BE250(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,9
	ctx.r4.s64 = r31.s64 + 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x825F00F4;
	sub_821BE250(ctx, base);
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

PPC_WEAK_FUNC(sub_825F0068) {
	__imp__sub_825F0068(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F010C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F010C) {
	__imp__sub_825F010C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0110) {
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
	ctx.lr = 0x825F0118;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwz r31,6600(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 6600);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f015c
	if (cr6.eq) goto loc_825F015C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,22992
	r30.s64 = r11.s64 + 22992;
loc_825F0134:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,376(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// lwz r4,368(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130000
	ctx.lr = 0x825F0144;
	sub_82130000(ctx, base);
	// lwz r31,372(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825f0134
	if (!cr6.eq) goto loc_825F0134;
	// lwz r31,6600(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 6600);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825f0168
	if (!cr6.eq) goto loc_825F0168;
loc_825F015C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,22972
	ctx.r3.s64 = r11.s64 + 22972;
	// bl 0x82130000
	ctx.lr = 0x825F0168;
	sub_82130000(ctx, base);
loc_825F0168:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F0110) {
	__imp__sub_825F0110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F0170) {
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
	PPCRegister f0{};
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
	// bl 0x823d91c0
	ctx.lr = 0x825F0178;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9c4
	ctx.lr = 0x825F0180;
	// addi r31,r1,-2400
	r31.s64 = ctx.r1.s64 + -2400;
	// stwu r1,-2400(r1)
	ea = -2400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2484(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2484);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// fmr f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = ctx.f1.f64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// fmr f23,f2
	f23.f64 = ctx.f2.f64;
	// mr r16,r9
	r16.u64 = ctx.r9.u64;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// mr r18,r10
	r18.u64 = ctx.r10.u64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f01bc
	if (cr6.eq) goto loc_825F01BC;
	// lbz r10,96(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 96);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_825F01BC:
	// li r11,-1
	r11.s64 = -1;
	// li r14,0
	r14.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// mr r23,r14
	r23.u64 = r14.u64;
	// bl 0x823de3a8
	ctx.lr = 0x825F01D4;
	sub_823DE3A8(ctx, base);
	// lwz r10,52(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 52);
	// clrlwi r20,r3,16
	r20.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r19,r14
	r19.u64 = r14.u64;
	// extsh r24,r10
	r24.s64 = ctx.r10.s16;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x825f0244
	if (cr6.eq) goto loc_825F0244;
	// extsh r10,r20
	ctx.r10.s64 = r20.s16;
	// lwz r9,28(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 28);
	// lwz r11,32(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// extsh r23,r9
	r23.s64 = ctx.r9.s16;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f020c
	if (cr6.lt) goto loc_825F020C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_825F020C:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// extsh r11,r23
	r11.s64 = r23.s16;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x825f13c4
	if (cr6.lt) goto loc_825F13C4;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// lwz r9,0(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lwz r11,36(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 36);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r19,r9,25,31,31
	r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
	// extsh r20,r8
	r20.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825f0244
	if (cr6.eq) goto loc_825F0244;
	// extsh r24,r11
	r24.s64 = r11.s16;
loc_825F0244:
	// extsh r15,r20
	r15.s64 = r20.s16;
	// rlwinm r11,r15,1,0,30
	r11.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F0258;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r8,r15
	ctx.r8.s64 = -r15.s64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r17,r1,80
	r17.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x825F0270;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r22,-1
	r22.s64 = -1;
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r6,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r6.u32);
	// ble cr6,0x825f053c
	if (!cr6.gt) goto loc_825F053C;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// extsh r29,r23
	r29.s64 = r23.s16;
	// lhz r27,14300(r10)
	r27.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14300);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r26,6604(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 6604);
	// ori r30,r8,65535
	r30.u64 = ctx.r8.u64 | 65535;
	// addi r28,r11,14304
	r28.s64 = r11.s64 + 14304;
loc_825F02B4:
	// add r11,r3,r29
	r11.u64 = ctx.r3.u64 + r29.u64;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stbx r22,r3,r10
	PPC_STORE_U8(ctx.r3.u32 + ctx.r10.u32, r22.u8);
	// sthx r22,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r22.u16);
	// lhzx r6,r9,r21
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + r21.u32);
	// cmpwi cr6,r6,10
	cr6.compare<int32_t>(ctx.r6.s32, 10, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,13
	cr6.compare<int32_t>(ctx.r6.s32, 13, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,8
	cr6.compare<int32_t>(ctx.r6.s32, 8, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,32
	cr6.compare<int32_t>(ctx.r6.s32, 32, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,160
	cr6.compare<int32_t>(ctx.r6.s32, 160, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,256
	cr6.compare<int32_t>(ctx.r6.s32, 256, xer);
	// bge cr6,0x825f0378
	if (!cr6.lt) goto loc_825F0378;
	// lhz r11,364(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 364);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0378
	if (cr6.eq) goto loc_825F0378;
	// add r11,r6,r25
	r11.u64 = ctx.r6.u64 + r25.u64;
	// lwz r9,100(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// lbz r11,108(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 108);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r5,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bne cr6,0x825f0478
	if (!cr6.eq) goto loc_825F0478;
	// lhz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// sthx r11,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r11.u16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x825f0478
	if (!cr6.gt) goto loc_825F0478;
	// lwz r8,32(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// mr r11,r14
	r11.u64 = r14.u64;
loc_825F0350:
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r5,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// blt cr6,0x825f0470
	if (cr6.lt) goto loc_825F0470;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x825f0350
	if (cr6.lt) goto loc_825F0350;
	// b 0x825f0478
	goto loc_825F0478;
loc_825F0378:
	// lhz r11,364(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 364);
	// lwz r5,104(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 104);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r7,100(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r8,r5,r30
	ctx.r8.u64 = ctx.r5.u64 + r30.u64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r8,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// bgt cr6,0x825f0478
	if (cr6.gt) goto loc_825F0478;
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
	// rlwinm r11,r11,1,15,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r7
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x825f0478
	if (cr6.lt) goto loc_825F0478;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bgt cr6,0x825f0478
	if (cr6.gt) goto loc_825F0478;
loc_825F03CC:
	// subf r11,r10,r8
	r11.s64 = ctx.r8.s64 - ctx.r10.s64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r9,r11,1,15,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// bge cr6,0x825f0408
	if (!cr6.lt) goto loc_825F0408;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// bge cr6,0x825f0478
	if (!cr6.lt) goto loc_825F0478;
	// b 0x825f041c
	goto loc_825F041C;
loc_825F0408:
	// ble cr6,0x825f0428
	if (!cr6.gt) goto loc_825F0428;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// beq cr6,0x825f0478
	if (cr6.eq) goto loc_825F0478;
loc_825F041C:
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x825f03cc
	if (!cr6.gt) goto loc_825F03CC;
	// b 0x825f0478
	goto loc_825F0478;
loc_825F0428:
	// lhz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// sthx r11,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r11.u16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x825f0478
	if (!cr6.gt) goto loc_825F0478;
	// clrlwi r7,r11,16
	ctx.r7.u64 = r11.u32 & 0xFFFF;
	// lwz r8,32(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// mr r11,r14
	r11.u64 = r14.u64;
loc_825F0448:
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r5,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// blt cr6,0x825f0470
	if (cr6.lt) goto loc_825F0470;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x825f0448
	if (cr6.lt) goto loc_825F0448;
	// b 0x825f0478
	goto loc_825F0478;
loc_825F0470:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stbx r10,r3,r11
	PPC_STORE_U8(ctx.r3.u32 + r11.u32, ctx.r10.u8);
loc_825F0478:
	// lhzx r11,r4,r17
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + r17.u32);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x825f052c
	if (!cr6.eq) goto loc_825F052C;
	// cmpwi cr6,r6,32
	cr6.compare<int32_t>(ctx.r6.s32, 32, xer);
	// ble cr6,0x825f0498
	if (!cr6.gt) goto loc_825F0498;
	// cmpwi cr6,r6,256
	cr6.compare<int32_t>(ctx.r6.s32, 256, xer);
	// bge cr6,0x825f0498
	if (!cr6.lt) goto loc_825F0498;
	// stb r6,1(r28)
	PPC_STORE_U8(r28.u32 + 1, ctx.r6.u8);
loc_825F0498:
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// beq cr6,0x825f04a8
	if (cr6.eq) goto loc_825F04A8;
	// cmpwi cr6,r26,3
	cr6.compare<int32_t>(r26.s32, 3, xer);
	// bne cr6,0x825f052c
	if (!cr6.eq) goto loc_825F052C;
loc_825F04A8:
	// lhz r11,364(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 364);
	// clrlwi r10,r27,16
	ctx.r10.u64 = r27.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f052c
	if (cr6.eq) goto loc_825F052C;
	// add r11,r10,r25
	r11.u64 = ctx.r10.u64 + r25.u64;
	// lwz r8,100(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// lbz r11,108(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 108);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// add r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r5,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x825f052c
	if (!cr6.eq) goto loc_825F052C;
	// lhz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// sthx r11,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r11.u16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x825f052c
	if (!cr6.gt) goto loc_825F052C;
	// lwz r8,32(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// mr r11,r14
	r11.u64 = r14.u64;
loc_825F04FC:
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// blt cr6,0x825f0524
	if (cr6.lt) goto loc_825F0524;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x825f04fc
	if (cr6.lt) goto loc_825F04FC;
	// b 0x825f052c
	goto loc_825F052C;
loc_825F0524:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stbx r10,r3,r11
	PPC_STORE_U8(ctx.r3.u32 + r11.u32, ctx.r10.u8);
loc_825F052C:
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// cmpw cr6,r3,r15
	cr6.compare<int32_t>(ctx.r3.s32, r15.s32, xer);
	// blt cr6,0x825f02b4
	if (cr6.lt) goto loc_825F02B4;
loc_825F053C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// rlwinm r27,r15,2,0,29
	r27.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r10,r27
	ctx.r10.s64 = -r27.s64;
	// lfs f27,22964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 22964);
	f27.f64 = double(temp.f32);
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// fmr f29,f27
	f29.f64 = f27.f64;
	// fmr f30,f27
	f30.f64 = f27.f64;
	// bl 0x823dbff4
	ctx.lr = 0x825F055C;
	sub_823DBFF4(ctx, base);
	// extsh r28,r24
	r28.s64 = r24.s16;
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// stfs f27,640(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + 640, temp.u32);
	// extsw r8,r28
	ctx.r8.s64 = r28.s32;
	// sth r14,384(r31)
	PPC_STORE_U16(r31.u32 + 384, r14.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r8,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r8.u64);
	// lfd f0,104(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r3,r31,384
	ctx.r3.s64 = r31.s64 + 384;
	// frsp f25,f13
	f25.f64 = double(float(ctx.f13.f64));
	// mr r29,r22
	r29.u64 = r22.u64;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// li r30,1
	r30.s64 = 1;
	// bl 0x823d9890
	ctx.lr = 0x825F05A0;
	sub_823D9890(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823d9890
	ctx.lr = 0x825F05B0;
	sub_823D9890(ctx, base);
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x825f063c
	if (cr6.eq) goto loc_825F063C;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f05f4
	if (cr6.eq) goto loc_825F05F4;
	// lwz r11,4(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 4);
	// lwz r10,20(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f05e4
	if (cr6.lt) goto loc_825F05E4;
	// lwz r9,24(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x825f05f4
	if (!cr6.gt) goto loc_825F05F4;
loc_825F05E4:
	// extsw r11,r10
	r11.s64 = ctx.r10.s32;
	// std r11,104(r31)
	PPC_STORE_U64(r31.u32 + 104, r11.u64);
	// lfd f0,104(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// b 0x825f0604
	goto loc_825F0604;
loc_825F05F4:
	// lwz r11,4(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 4);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
loc_825F0604:
	// fcfid f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(f0.s64);
	// lwz r11,8(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 8);
	// lfs f0,48(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 48);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
	// std r10,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r10.u64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,52(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f28,f13,f28
	f28.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fadds f29,f12,f27
	f29.f64 = double(float(ctx.f12.f64 + f27.f64));
	// lfd f12,104(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fadds f30,f10,f27
	f30.f64 = double(float(ctx.f10.f64 + f27.f64));
loc_825F063C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// lfs f26,15000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	f26.f64 = double(temp.f32);
	// ble cr6,0x825f0d28
	if (!cr6.gt) goto loc_825F0D28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// extsh r3,r23
	ctx.r3.s64 = r23.s16;
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// lfs f8,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f8.f64 = double(temp.f32);
loc_825F0660:
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r3
	r11.u64 = ctx.r8.u64 + ctx.r3.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r4,r17
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + r17.u32);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// lhzx r10,r10,r21
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + r21.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x825f07ac
	if (!cr6.lt) goto loc_825F07AC;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bne cr6,0x825f0704
	if (!cr6.eq) goto loc_825F0704;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x825f06b4
	if (cr6.eq) goto loc_825F06B4;
	// lwz r11,20(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f29,f12,f27
	f29.f64 = double(float(ctx.f12.f64 + f27.f64));
	// b 0x825f06b8
	goto loc_825F06B8;
loc_825F06B4:
	// fmr f29,f27
	ctx.fpscr.disableFlushMode();
	f29.f64 = f27.f64;
loc_825F06B8:
	// lwz r10,40(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// extsh r11,r30
	r11.s64 = r30.s16;
	// addi r9,r31,640
	ctx.r9.s64 = r31.s64 + 640;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r7,240(r31)
	PPC_STORE_U64(r31.u32 + 240, ctx.r7.u64);
	// lfd f0,240(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 240);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// addi r10,r31,384
	ctx.r10.s64 = r31.s64 + 384;
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// mr r29,r22
	r29.u64 = r22.u64;
	// extsh r30,r5
	r30.s64 = ctx.r5.s16;
	// sthx r7,r4,r10
	PPC_STORE_U16(ctx.r4.u32 + ctx.r10.u32, ctx.r7.u16);
	// fadds f30,f12,f30
	f30.f64 = double(float(ctx.f12.f64 + f30.f64));
	// stfsx f30,r6,r9
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, temp.u32);
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F0704:
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x825f0740
	if (!cr6.eq) goto loc_825F0740;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x825f0720
	if (!cr6.eq) goto loc_825F0720;
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
loc_825F0720:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// std r11,256(r31)
	PPC_STORE_U64(r31.u32 + 256, r11.u64);
	// lfd f0,256(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 256);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f29,f12,f29
	f29.f64 = double(float(ctx.f12.f64 + f29.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F0740:
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// bne cr6,0x825f0780
	if (!cr6.eq) goto loc_825F0780;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x825f075c
	if (!cr6.eq) goto loc_825F075C;
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
loc_825F075C:
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,368(r31)
	PPC_STORE_U64(r31.u32 + 368, ctx.r9.u64);
	// lfd f0,368(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 368);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f29,f29,f12
	f29.f64 = double(float(f29.f64 - ctx.f12.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F0780:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x825f0790
	if (!cr6.eq) goto loc_825F0790;
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
loc_825F0790:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,296(r31)
	PPC_STORE_U64(r31.u32 + 296, r11.u64);
	// lfd f0,296(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 296);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f29,f12,f29
	f29.f64 = double(float(ctx.f12.f64 + f29.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F07AC:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,100(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// clrlwi r7,r19,24
	ctx.r7.u64 = r19.u32 & 0xFF;
	// lwz r27,56(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// bne cr6,0x825f0a6c
	if (!cr6.eq) goto loc_825F0A6C;
	// lbz r7,6(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// fmuls f13,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f29.f64 * f31.f64));
	// lbz r6,7(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// lbz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// std r11,312(r31)
	PPC_STORE_U64(r31.u32 + 312, r11.u64);
	// extsw r11,r27
	r11.s64 = r27.s32;
	// lfd f0,312(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 312);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// std r11,344(r31)
	PPC_STORE_U64(r31.u32 + 344, r11.u64);
	// lfd f11,344(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 344);
	// std r6,328(r31)
	PPC_STORE_U64(r31.u32 + 328, ctx.r6.u64);
	// lfd f12,328(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 328);
	// std r9,336(r31)
	PPC_STORE_U64(r31.u32 + 336, ctx.r9.u64);
	// lfd f9,336(r31)
	ctx.f9.u64 = PPC_LOAD_U64(r31.u32 + 336);
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// fcfid f5,f0
	ctx.f5.f64 = double(f0.s64);
	// fcfid f4,f12
	ctx.f4.f64 = double(ctx.f12.s64);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// fadds f0,f3,f7
	f0.f64 = double(float(ctx.f3.f64 + ctx.f7.f64));
	// fmuls f11,f2,f31
	ctx.f11.f64 = double(float(ctx.f2.f64 * f31.f64));
	// fmuls f10,f1,f28
	ctx.f10.f64 = double(float(ctx.f1.f64 * f28.f64));
	// fadds f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 + f30.f64));
	// fmuls f12,f12,f28
	ctx.f12.f64 = double(float(ctx.f12.f64 * f28.f64));
	// beq cr6,0x825f0a0c
	if (cr6.eq) goto loc_825F0A0C;
	// lwz r6,0(r16)
	ctx.r6.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// rlwinm r11,r6,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0964
	if (cr6.eq) goto loc_825F0964;
	// lwz r11,24(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// fadds f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.r9.u64);
	// lfd f7,176(r31)
	ctx.f7.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcmpu cr6,f9,f5
	cr6.compare(ctx.f9.f64, ctx.f5.f64);
	// blt cr6,0x825f0964
	if (cr6.lt) goto loc_825F0964;
	// extsh r9,r29
	ctx.r9.s64 = r29.s16;
	// extsh r11,r30
	r11.s64 = r30.s16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x825f08fc
	if (cr6.lt) goto loc_825F08FC;
	// lwz r7,20(r16)
	ctx.r7.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// extsh r8,r29
	ctx.r8.s64 = r29.s16;
	// lwz r10,40(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// std r5,288(r31)
	PPC_STORE_U64(r31.u32 + 288, ctx.r5.u64);
	// lfd f0,288(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 288);
	// std r6,192(r31)
	PPC_STORE_U64(r31.u32 + 192, ctx.r6.u64);
	// lfd f12,192(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 192);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r10,r31,640
	ctx.r10.s64 = r31.s64 + 640;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// addi r6,r31,384
	ctx.r6.s64 = r31.s64 + 384;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r29,r22
	r29.u64 = r22.u64;
	// sthx r9,r7,r6
	PPC_STORE_U16(ctx.r7.u32 + ctx.r6.u32, ctx.r9.u16);
	// extsh r30,r11
	r30.s64 = r11.s16;
	// sthx r22,r5,r17
	PPC_STORE_U16(ctx.r5.u32 + r17.u32, r22.u16);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fadds f30,f9,f30
	f30.f64 = double(float(ctx.f9.f64 + f30.f64));
	// stfsx f30,r4,r10
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r10.u32, temp.u32);
	// fadds f29,f11,f27
	f29.f64 = double(float(ctx.f11.f64 + f27.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F08FC:
	// lwz r30,40(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// rlwinm r24,r11,1,0,30
	r24.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,20(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// addi r27,r31,640
	r27.s64 = r31.s64 + 640;
	// extsw r30,r30
	r30.s64 = r30.s32;
	// extsw r9,r9
	ctx.r9.s64 = ctx.r9.s32;
	// std r30,360(r31)
	PPC_STORE_U64(r31.u32 + 360, r30.u64);
	// addi r23,r31,384
	r23.s64 = r31.s64 + 384;
	// std r9,208(r31)
	PPC_STORE_U64(r31.u32 + 208, ctx.r9.u64);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r29,r22
	r29.u64 = r22.u64;
	// extsh r30,r11
	r30.s64 = r11.s16;
	// sthx r5,r24,r23
	PPC_STORE_U16(r24.u32 + r23.u32, ctx.r5.u16);
	// lfd f13,360(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r31.u32 + 360);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f9,208(r31)
	ctx.f9.u64 = PPC_LOAD_U64(r31.u32 + 208);
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// frsp f7,f12
	ctx.f7.f64 = double(float(ctx.f12.f64));
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fadds f30,f7,f30
	f30.f64 = double(float(ctx.f7.f64 + f30.f64));
	// stfsx f30,r9,r27
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + r27.u32, temp.u32);
	// fadds f29,f5,f27
	f29.f64 = double(float(ctx.f5.f64 + f27.f64));
	// fadds f4,f0,f30
	ctx.f4.f64 = double(float(f0.f64 + f30.f64));
	// fmuls f13,f29,f31
	ctx.f13.f64 = double(float(f29.f64 * f31.f64));
	// fmuls f12,f4,f28
	ctx.f12.f64 = double(float(ctx.f4.f64 * f28.f64));
loc_825F0964:
	// rlwinm r11,r6,0,20,20
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0a0c
	if (cr6.eq) goto loc_825F0A0C;
	// clrlwi r11,r6,29
	r11.u64 = ctx.r6.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f0a0c
	if (!cr6.eq) goto loc_825F0A0C;
	// lwz r11,24(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// fadds f0,f11,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,304(r31)
	PPC_STORE_U64(r31.u32 + 304, ctx.r9.u64);
	// lfd f11,304(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 304);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bge cr6,0x825f0a08
	if (!cr6.lt) goto loc_825F0A08;
	// lwz r11,16(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 16);
	// fadds f0,f10,f12
	f0.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,224(r31)
	PPC_STORE_U64(r31.u32 + 224, ctx.r9.u64);
	// lfd f11,224(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 224);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// bge cr6,0x825f0a08
	if (!cr6.lt) goto loc_825F0A08;
	// lwz r11,20(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,352(r31)
	PPC_STORE_U64(r31.u32 + 352, ctx.r9.u64);
	// lfd f0,352(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 352);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f13,f10
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// blt cr6,0x825f0a08
	if (cr6.lt) goto loc_825F0A08;
	// lwz r11,12(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,152(r31)
	PPC_STORE_U64(r31.u32 + 152, ctx.r9.u64);
	// lfd f0,152(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 152);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f12,f10
	cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// bge cr6,0x825f0a0c
	if (!cr6.lt) goto loc_825F0A0C;
loc_825F0A08:
	// sthx r22,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r22.u16);
loc_825F0A0C:
	// lbz r10,9(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// fmuls f0,f13,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 * f26.f64));
	// lwz r11,44(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 44);
	// fmuls f13,f12,f26
	ctx.f13.f64 = double(float(ctx.f12.f64 * f26.f64));
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r9,r26
	r11.u64 = ctx.r9.u64 + r26.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,320(r31)
	PPC_STORE_U64(r31.u32 + 320, ctx.r6.u64);
	// fctiwz f11,f0
	ctx.f11.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// fctiwz f10,f13
	ctx.f10.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f10,128(r31)
	PPC_STORE_U64(r31.u32 + 128, ctx.f10.u64);
	// stfd f11,136(r31)
	PPC_STORE_U64(r31.u32 + 136, ctx.f11.u64);
	// lhz r4,142(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 142);
	// sthx r4,r9,r26
	PPC_STORE_U16(ctx.r9.u32 + r26.u32, ctx.r4.u16);
	// lfd f12,320(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 320);
	// lhz r5,134(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 134);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// sth r5,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r5.u16);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fadds f29,f7,f29
	f29.f64 = double(float(ctx.f7.f64 + f29.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F0A6C:
	// lbz r11,9(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// lbz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// extsb r7,r11
	ctx.r7.s64 = r11.s8;
	// lbz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// lbz r11,7(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// subf r7,r7,r28
	ctx.r7.s64 = r28.s64 - ctx.r7.s64;
	// std r10,272(r31)
	PPC_STORE_U64(r31.u32 + 272, ctx.r10.u64);
	// lfd f0,272(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 272);
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// extsb r9,r6
	ctx.r9.s64 = ctx.r6.s8;
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r9,160(r31)
	PPC_STORE_U64(r31.u32 + 160, ctx.r9.u64);
	// extsw r11,r27
	r11.s64 = r27.s32;
	// std r6,184(r31)
	PPC_STORE_U64(r31.u32 + 184, ctx.r6.u64);
	// std r7,168(r31)
	PPC_STORE_U64(r31.u32 + 168, ctx.r7.u64);
	// lfd f11,168(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 168);
	// std r11,200(r31)
	PPC_STORE_U64(r31.u32 + 200, r11.u64);
	// lfd f7,200(r31)
	ctx.f7.u64 = PPC_LOAD_U64(r31.u32 + 200);
	// lfd f10,184(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 184);
	// lfd f12,160(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 160);
	// fcfid f4,f12
	ctx.f4.f64 = double(ctx.f12.s64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f5,f11
	ctx.f5.f64 = double(ctx.f11.s64);
	// frsp f0,f4
	f0.f64 = double(float(ctx.f4.f64));
	// fcfid f2,f10
	ctx.f2.f64 = double(ctx.f10.s64);
	// fmuls f10,f9,f31
	ctx.f10.f64 = double(float(ctx.f9.f64 * f31.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// frsp f11,f2
	ctx.f11.f64 = double(float(ctx.f2.f64));
	// fadds f13,f0,f3
	ctx.f13.f64 = double(float(f0.f64 + ctx.f3.f64));
	// fmuls f12,f1,f8
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// fmuls f9,f11,f28
	ctx.f9.f64 = double(float(ctx.f11.f64 * f28.f64));
	// fadds f6,f13,f30
	ctx.f6.f64 = double(float(ctx.f13.f64 + f30.f64));
	// fadds f7,f12,f29
	ctx.f7.f64 = double(float(ctx.f12.f64 + f29.f64));
	// fmuls f11,f6,f28
	ctx.f11.f64 = double(float(ctx.f6.f64 * f28.f64));
	// fmuls f0,f7,f31
	f0.f64 = double(float(ctx.f7.f64 * f31.f64));
	// beq cr6,0x825f0ce0
	if (cr6.eq) goto loc_825F0CE0;
	// lwz r9,0(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// rlwinm r11,r9,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0c34
	if (cr6.eq) goto loc_825F0C34;
	// lwz r11,24(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// fadds f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 + f0.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,216(r31)
	PPC_STORE_U64(r31.u32 + 216, ctx.r10.u64);
	// lfd f6,216(r31)
	ctx.f6.u64 = PPC_LOAD_U64(r31.u32 + 216);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fcmpu cr6,f7,f4
	cr6.compare(ctx.f7.f64, ctx.f4.f64);
	// blt cr6,0x825f0c34
	if (cr6.lt) goto loc_825F0C34;
	// extsh r10,r29
	ctx.r10.s64 = r29.s16;
	// extsh r11,r30
	r11.s64 = r30.s16;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x825f0bc8
	if (cr6.lt) goto loc_825F0BC8;
	// lwz r9,40(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// extsh r8,r29
	ctx.r8.s64 = r29.s16;
	// lwz r7,20(r16)
	ctx.r7.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r6,248(r31)
	PPC_STORE_U64(r31.u32 + 248, ctx.r6.u64);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// std r5,232(r31)
	PPC_STORE_U64(r31.u32 + 232, ctx.r5.u64);
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r31,640
	ctx.r9.s64 = r31.s64 + 640;
	// addi r5,r31,384
	ctx.r5.s64 = r31.s64 + 384;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r29,r22
	r29.u64 = r22.u64;
	// extsh r30,r11
	r30.s64 = r11.s16;
	// sthx r7,r6,r5
	PPC_STORE_U16(ctx.r6.u32 + ctx.r5.u32, ctx.r7.u16);
	// sthx r22,r10,r17
	PPC_STORE_U16(ctx.r10.u32 + r17.u32, r22.u16);
	// lfd f12,248(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 248);
	// lfd f0,232(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 232);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fadds f30,f9,f30
	f30.f64 = double(float(ctx.f9.f64 + f30.f64));
	// stfsx f30,r4,r9
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r9.u32, temp.u32);
	// fadds f29,f11,f27
	f29.f64 = double(float(ctx.f11.f64 + f27.f64));
	// b 0x825f0d14
	goto loc_825F0D14;
loc_825F0BC8:
	// lwz r7,40(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// addi r6,r31,640
	ctx.r6.s64 = r31.s64 + 640;
	// lwz r10,20(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// addi r27,r31,384
	r27.s64 = r31.s64 + 384;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r7,264(r31)
	PPC_STORE_U64(r31.u32 + 264, ctx.r7.u64);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// std r10,280(r31)
	PPC_STORE_U64(r31.u32 + 280, ctx.r10.u64);
	// lfd f7,280(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f7.u64 = PPC_LOAD_U64(r31.u32 + 280);
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfd f0,264(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 264);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r29,r22
	r29.u64 = r22.u64;
	// sthx r5,r7,r27
	PPC_STORE_U16(ctx.r7.u32 + r27.u32, ctx.r5.u16);
	// extsh r30,r11
	r30.s64 = r11.s16;
	// fadds f29,f4,f27
	f29.f64 = double(float(ctx.f4.f64 + f27.f64));
	// frsp f6,f11
	ctx.f6.f64 = double(float(ctx.f11.f64));
	// fadds f2,f12,f29
	ctx.f2.f64 = double(float(ctx.f12.f64 + f29.f64));
	// fadds f30,f6,f30
	f30.f64 = double(float(ctx.f6.f64 + f30.f64));
	// stfsx f30,r10,r6
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r6.u32, temp.u32);
	// fmuls f0,f2,f31
	f0.f64 = double(float(ctx.f2.f64 * f31.f64));
	// fadds f3,f13,f30
	ctx.f3.f64 = double(float(ctx.f13.f64 + f30.f64));
	// fmuls f11,f3,f28
	ctx.f11.f64 = double(float(ctx.f3.f64 * f28.f64));
loc_825F0C34:
	// rlwinm r11,r9,0,20,20
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0ce0
	if (cr6.eq) goto loc_825F0CE0;
	// clrlwi r11,r9,29
	r11.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f0ce0
	if (!cr6.eq) goto loc_825F0CE0;
	// lwz r11,24(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// fadds f13,f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f10.f64 + f0.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,144(r31)
	PPC_STORE_U64(r31.u32 + 144, ctx.r10.u64);
	// lfd f10,144(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 144);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x825f0cdc
	if (!cr6.lt) goto loc_825F0CDC;
	// lwz r11,16(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 16);
	// fadds f13,f9,f11
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,120(r31)
	PPC_STORE_U64(r31.u32 + 120, ctx.r10.u64);
	// lfd f10,120(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 120);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x825f0cdc
	if (!cr6.lt) goto loc_825F0CDC;
	// lwz r11,20(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 20);
	// fnmsubs f13,f12,f31,f0
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * f31.f64 - f0.f64)));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// blt cr6,0x825f0cdc
	if (cr6.lt) goto loc_825F0CDC;
	// lwz r11,12(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r31)
	ctx.f13.u64 = PPC_LOAD_U64(r31.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f10
	cr6.compare(ctx.f11.f64, ctx.f10.f64);
	// bge cr6,0x825f0ce0
	if (!cr6.lt) goto loc_825F0CE0;
loc_825F0CDC:
	// sthx r22,r4,r17
	PPC_STORE_U16(ctx.r4.u32 + r17.u32, r22.u16);
loc_825F0CE0:
	// fmuls f13,f11,f26
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f11.f64 * f26.f64));
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f0,f0,f26
	f0.f64 = double(float(f0.f64 * f26.f64));
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// fadds f29,f25,f29
	f29.f64 = double(float(f25.f64 + f29.f64));
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,136(r31)
	PPC_STORE_U64(r31.u32 + 136, ctx.f11.u64);
	// fctiwz f12,f0
	ctx.f12.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f12,128(r31)
	PPC_STORE_U64(r31.u32 + 128, ctx.f12.u64);
	// lhz r9,134(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 134);
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
	// lhz r10,142(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 142);
	// sth r10,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r10.u16);
loc_825F0D14:
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// cmpw cr6,r8,r15
	cr6.compare<int32_t>(ctx.r8.s32, r15.s32, xer);
	// blt cr6,0x825f0660
	if (cr6.lt) goto loc_825F0660;
loc_825F0D28:
	// extsh r4,r30
	ctx.r4.s64 = r30.s16;
	// addi r11,r31,384
	r11.s64 = r31.s64 + 384;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// sthx r20,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + r11.u32, r20.u16);
	// beq cr6,0x825f10a0
	if (cr6.eq) goto loc_825F10A0;
	// lwz r5,0(r16)
	ctx.r5.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// clrlwi r11,r5,29
	r11.u64 = ctx.r5.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f0f08
	if (cr6.eq) goto loc_825F0F08;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x825f0f08
	if (!cr6.gt) goto loc_825F0F08;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
loc_825F0D60:
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r31,386
	ctx.r10.s64 = r31.s64 + 386;
	// addi r9,r31,384
	ctx.r9.s64 = r31.s64 + 384;
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// lhzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// lhzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + ctx.r9.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x825f0ef8
	if (cr6.lt) goto loc_825F0EF8;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x825f0e88
	if (cr6.lt) goto loc_825F0E88;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_825F0DA0:
	// rlwinm r3,r9,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r3,r3,r17
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + r17.u32);
	// cmplwi cr6,r3,32768
	cr6.compare<uint32_t>(ctx.r3.u32, 32768, xer);
	// blt cr6,0x825f0dc8
	if (cr6.lt) goto loc_825F0DC8;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bge cr6,0x825f0da0
	if (!cr6.lt) goto loc_825F0DA0;
	// b 0x825f0e88
	goto loc_825F0E88;
loc_825F0DC8:
	// clrlwi r9,r19,24
	ctx.r9.u64 = r19.u32 & 0xFF;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f0e10
	if (cr6.eq) goto loc_825F0E10;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r8,r9,r26
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + r26.u32);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// srawi r10,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f11,f25,f31,f12
	ctx.f11.f64 = double(float(f25.f64 * f31.f64 + ctx.f12.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f10.u64);
	// lhz r8,86(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// b 0x825f0e88
	goto loc_825F0E88;
loc_825F0E10:
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,100(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r9,r17
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + r17.u32);
	// lhzx r9,r3,r26
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + r26.u32);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r3,r9
	ctx.r3.s64 = ctx.r9.s16;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r3,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 4;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// std r3,120(r31)
	PPC_STORE_U64(r31.u32 + 120, ctx.r3.u64);
	// lfd f0,120(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 120);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lbz r9,9(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lbz r10,6(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// std r3,144(r31)
	PPC_STORE_U64(r31.u32 + 144, ctx.r3.u64);
	// lfd f11,144(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 144);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmadds f8,f9,f31,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f7.u64);
	// lhz r8,86(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 86);
loc_825F0E88:
	// rlwinm r9,r5,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f0eac
	if (cr6.eq) goto loc_825F0EAC;
	// lwz r10,24(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r3,r8,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x825f0ec8
	goto loc_825F0EC8;
loc_825F0EAC:
	// clrlwi r9,r5,31
	ctx.r9.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f0ecc
	if (cr6.eq) goto loc_825F0ECC;
	// lwz r10,24(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 24);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r3,r8,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
loc_825F0EC8:
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
loc_825F0ECC:
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bgt cr6,0x825f0ef8
	if (cr6.gt) goto loc_825F0EF8;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
loc_825F0ED8:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lhzx r3,r10,r26
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + r26.u32);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// add r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 + ctx.r8.u64;
	// sthx r9,r10,r26
	PPC_STORE_U16(ctx.r10.u32 + r26.u32, ctx.r9.u16);
	// ble cr6,0x825f0ed8
	if (!cr6.gt) goto loc_825F0ED8;
loc_825F0EF8:
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// extsh r6,r11
	ctx.r6.s64 = r11.s16;
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// blt cr6,0x825f0d60
	if (cr6.lt) goto loc_825F0D60;
loc_825F0F08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r14,40(r16)
	PPC_STORE_U32(r16.u32 + 40, r14.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// stw r14,44(r16)
	PPC_STORE_U32(r16.u32 + 44, r14.u32);
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// ble cr6,0x825f1044
	if (!cr6.gt) goto loc_825F1044;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
loc_825F0F2C:
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r31,386
	ctx.r10.s64 = r31.s64 + 386;
	// addi r9,r31,384
	ctx.r9.s64 = r31.s64 + 384;
	// mr r7,r14
	ctx.r7.u64 = r14.u64;
	// lhzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// lhzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + ctx.r9.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bgt cr6,0x825f1030
	if (cr6.gt) goto loc_825F1030;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x825f1030
	if (cr6.lt) goto loc_825F1030;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x825f101c
	if (cr6.lt) goto loc_825F101C;
loc_825F0F74:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r3,r8,r17
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + r17.u32);
	// cmplwi cr6,r3,32768
	cr6.compare<uint32_t>(ctx.r3.u32, 32768, xer);
	// blt cr6,0x825f0f9c
	if (cr6.lt) goto loc_825F0F9C;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x825f0f74
	if (!cr6.lt) goto loc_825F0F74;
	// b 0x825f101c
	goto loc_825F101C;
loc_825F0F9C:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lwz r9,100(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r10,r26
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + r26.u32);
	// lhzx r3,r8,r17
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + r17.u32);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// srawi r8,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// std r10,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// extsb r11,r9
	r11.s64 = ctx.r9.s8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r31)
	ctx.f13.u64 = PPC_LOAD_U64(r31.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f7,f10,f31,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f8.f64));
	// fadds f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 + f0.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,120(r31)
	PPC_STORE_U64(r31.u32 + 120, ctx.f5.u64);
	// lhz r7,126(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 126);
loc_825F101C:
	// lwz r10,40(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 40);
	// extsh r11,r7
	r11.s64 = ctx.r7.s16;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x825f1030
	if (!cr6.gt) goto loc_825F1030;
	// stw r11,40(r16)
	PPC_STORE_U32(r16.u32 + 40, r11.u32);
loc_825F1030:
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// blt cr6,0x825f0f2c
	if (cr6.lt) goto loc_825F0F2C;
loc_825F1044:
	// lwz r11,60(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 60);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// lwz r9,56(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r8,r31,640
	ctx.r8.s64 = r31.s64 + 640;
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// std r7,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r7.u64);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// std r6,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r6.u64);
	// lfsx f13,r5,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfd f12,88(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfd f10,80(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fadds f6,f13,f8
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f8.f64));
	// fadds f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// fadds f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 + f0.f64));
	// fmuls f3,f4,f28
	ctx.f3.f64 = double(float(ctx.f4.f64 * f28.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// li r12,44
	r12.s64 = 44;
	// stfiwx f2,r16,r12
	PPC_STORE_U32(r16.u32 + r12.u32, ctx.f2.u32);
loc_825F10A0:
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f13c4
	if (!cr6.eq) goto loc_825F13C4;
	// lwz r11,68(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 68);
	// li r23,1
	r23.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f10e0
	if (!cr6.eq) goto loc_825F10E0;
	// lwz r11,64(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f10e0
	if (!cr6.eq) goto loc_825F10E0;
	// lwz r11,72(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f10e0
	if (!cr6.eq) goto loc_825F10E0;
	// lwz r11,76(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825f10e4
	if (cr6.eq) goto loc_825F10E4;
loc_825F10E0:
	// li r23,2
	r23.s64 = 2;
loc_825F10E4:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x825f1368
	if (!cr6.gt) goto loc_825F1368;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r24,r14
	r24.u64 = r14.u64;
	// lfs f27,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f27.f64 = double(temp.f32);
loc_825F10F8:
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x825f1130
	if (cr6.eq) goto loc_825F1130;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// ble cr6,0x825f1128
	if (!cr6.gt) goto loc_825F1128;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x825f1128
	if (!cr6.eq) goto loc_825F1128;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// rlwinm r10,r11,20,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1128
	if (cr6.eq) goto loc_825F1128;
	// lwz r11,60(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 60);
	// b 0x825f112c
	goto loc_825F112C;
loc_825F1128:
	// lwz r11,56(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 56);
loc_825F112C:
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
loc_825F1130:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1358
	if (cr6.eq) goto loc_825F1358;
	// lwz r20,2484(r31)
	r20.u64 = PPC_LOAD_U32(r31.u32 + 2484);
	// mr r27,r14
	r27.u64 = r14.u64;
	// lwz r22,96(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r21,112(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 112);
loc_825F114C:
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// ble cr6,0x825f1344
	if (!cr6.gt) goto loc_825F1344;
	// mr r29,r14
	r29.u64 = r14.u64;
loc_825F1158:
	// subf r11,r29,r15
	r11.s64 = r15.s64 - r29.s64;
	// mr r7,r14
	ctx.r7.u64 = r14.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// ble cr6,0x825f1170
	if (!cr6.gt) goto loc_825F1170;
	// li r11,128
	r11.s64 = 128;
loc_825F1170:
	// extsh r28,r11
	r28.s64 = r11.s16;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x825f1290
	if (!cr6.gt) goto loc_825F1290;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
loc_825F1180:
	// add r11,r29,r6
	r11.u64 = r29.u64 + ctx.r6.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r17
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + r17.u32);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x825f1280
	if (cr6.lt) goto loc_825F1280;
	// lbzx r9,r11,r22
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r22.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpw cr6,r8,r27
	cr6.compare<int32_t>(ctx.r8.s32, r27.s32, xer);
	// bne cr6,0x825f1280
	if (!cr6.eq) goto loc_825F1280;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,100(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 100);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r3,r31,1152
	ctx.r3.s64 = r31.s64 + 1152;
	// lhz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// addi r30,r31,1154
	r30.s64 = r31.s64 + 1154;
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r31,1156
	ctx.r9.s64 = r31.s64 + 1156;
	// addi r8,r31,1158
	ctx.r8.s64 = r31.s64 + 1158;
	// sthx r4,r5,r3
	PPC_STORE_U16(ctx.r5.u32 + ctx.r3.u32, ctx.r4.u16);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// sthx r7,r5,r30
	PPC_STORE_U16(ctx.r5.u32 + r30.u32, ctx.r7.u16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r7,6(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// std r7,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r7.u64);
	// lfd f0,88(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// addi r30,r31,641
	r30.s64 = r31.s64 + 641;
	// addi r19,r31,642
	r19.s64 = r31.s64 + 642;
	// addi r18,r31,643
	r18.s64 = r31.s64 + 643;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f10,f11,f26
	ctx.f10.f64 = double(float(ctx.f11.f64 * f26.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f9.u64);
	// lhz r10,86(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// sthx r10,r5,r9
	PPC_STORE_U16(ctx.r5.u32 + ctx.r9.u32, ctx.r10.u16);
	// lbz r10,7(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// std r10,120(r31)
	PPC_STORE_U64(r31.u32 + 120, ctx.r10.u64);
	// lfd f8,120(r31)
	ctx.f8.u64 = PPC_LOAD_U64(r31.u32 + 120);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f5,f6,f28
	ctx.f5.f64 = double(float(ctx.f6.f64 * f28.f64));
	// fmuls f4,f5,f26
	ctx.f4.f64 = double(float(ctx.f5.f64 * f26.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f3.u64);
	// lhz r9,86(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// sthx r9,r5,r8
	PPC_STORE_U16(ctx.r5.u32 + ctx.r8.u32, ctx.r9.u16);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// stbx r8,r4,r3
	PPC_STORE_U8(ctx.r4.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stbx r5,r4,r30
	PPC_STORE_U8(ctx.r4.u32 + r30.u32, ctx.r5.u8);
	// lbz r3,6(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// stbx r3,r4,r19
	PPC_STORE_U8(ctx.r4.u32 + r19.u32, ctx.r3.u8);
	// lbz r11,7(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// stbx r11,r4,r18
	PPC_STORE_U8(ctx.r4.u32 + r18.u32, r11.u8);
loc_825F1280:
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// extsh r6,r11
	ctx.r6.s64 = r11.s16;
	// cmpw cr6,r6,r28
	cr6.compare<int32_t>(ctx.r6.s32, r28.s32, xer);
	// blt cr6,0x825f1180
	if (cr6.lt) goto loc_825F1180;
loc_825F1290:
	// extsh r30,r7
	r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x825f1334
	if (!cr6.gt) goto loc_825F1334;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// beq cr6,0x825f12b4
	if (cr6.eq) goto loc_825F12B4;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// beq cr6,0x825f12b4
	if (cr6.eq) goto loc_825F12B4;
	// lwz r11,16(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// b 0x825f12b8
	goto loc_825F12B8;
loc_825F12B4:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
loc_825F12B8:
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// beq cr6,0x825f12e0
	if (cr6.eq) goto loc_825F12E0;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r31,640
	ctx.r6.s64 = r31.s64 + 640;
	// addi r5,r31,1152
	ctx.r5.s64 = r31.s64 + 1152;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82605c10
	ctx.lr = 0x825F12DC;
	sub_82605C10(ctx, base);
	// b 0x825f1334
	goto loc_825F1334;
loc_825F12E0:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8217d9a0
	ctx.lr = 0x825F12E8;
	sub_8217D9A0(ctx, base);
	// fmr f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f23.f64;
	// bl 0x823dbaa8
	ctx.lr = 0x825F12F0;
	sub_823DBAA8(ctx, base);
	// frsp f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = double(float(ctx.f1.f64));
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x823dbaa8
	ctx.lr = 0x825F12FC;
	sub_823DBAA8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// fctiwz f13,f25
	ctx.f13.s64 = (f25.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f25.f64));
	// stfd f13,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r7,r31,640
	ctx.r7.s64 = r31.s64 + 640;
	// lbz r10,96(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 96);
	// addi r6,r31,1152
	ctx.r6.s64 = r31.s64 + 1152;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// fctiwz f12,f0
	ctx.f12.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f12,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f12.u64);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x8217b368
	ctx.lr = 0x825F1334;
	sub_8217B368(ctx, base);
loc_825F1334:
	// add r11,r28,r29
	r11.u64 = r28.u64 + r29.u64;
	// extsh r29,r11
	r29.s64 = r11.s16;
	// cmpw cr6,r29,r15
	cr6.compare<int32_t>(r29.s32, r15.s32, xer);
	// blt cr6,0x825f1158
	if (cr6.lt) goto loc_825F1158;
loc_825F1344:
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// lhz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// extsh r27,r11
	r27.s64 = r11.s16;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f114c
	if (cr6.lt) goto loc_825F114C;
loc_825F1358:
	// addi r11,r24,1
	r11.s64 = r24.s64 + 1;
	// extsh r24,r11
	r24.s64 = r11.s16;
	// cmpw cr6,r24,r23
	cr6.compare<int32_t>(r24.s32, r23.s32, xer);
	// blt cr6,0x825f10f8
	if (cr6.lt) goto loc_825F10F8;
loc_825F1368:
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x825f13c4
	if (cr6.eq) goto loc_825F13C4;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f13ac
	if (cr6.eq) goto loc_825F13AC;
	// stw r14,4(r16)
	PPC_STORE_U32(r16.u32 + 4, r14.u32);
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// stfd f0,88(r31)
	PPC_STORE_U64(r31.u32 + 88, f0.u64);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,40(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,8(r16)
	PPC_STORE_U32(r16.u32 + 8, r11.u32);
	// addi r1,r31,2400
	ctx.r1.s64 = r31.s64 + 2400;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba10
	ctx.lr = 0x825F13A8;
	// b 0x823d9210
	return;
loc_825F13AC:
	// li r11,4
	r11.s64 = 4;
	// fctiwz f0,f29
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f29.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f29.f64));
	// li r10,8
	ctx.r10.s64 = 8;
	// fctiwz f13,f30
	ctx.f13.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// stfiwx f0,r16,r11
	PPC_STORE_U32(r16.u32 + r11.u32, f0.u32);
	// stfiwx f13,r16,r10
	PPC_STORE_U32(r16.u32 + ctx.r10.u32, ctx.f13.u32);
loc_825F13C4:
	// addi r1,r31,2400
	ctx.r1.s64 = r31.s64 + 2400;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba10
	ctx.lr = 0x825F13D0;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_825F0170) {
	__imp__sub_825F0170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F13D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F13D4) {
	__imp__sub_825F13D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F13D8) {
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
	ctx.lr = 0x825F13E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1444
	if (cr6.eq) goto loc_825F1444;
	// mr r30,r28
	r30.u64 = r28.u64;
	// lis r27,-32127
	r27.s64 = -2105475072;
loc_825F140C:
	// lbz r10,14296(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 14296);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1430
	if (cr6.eq) goto loc_825F1430;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8217da18
	ctx.lr = 0x825F1424;
	sub_8217DA18(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// bl 0x8217da18
	ctx.lr = 0x825F1430;
	sub_8217DA18(ctx, base);
loc_825F1430:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825f140c
	if (cr6.lt) goto loc_825F140C;
loc_825F1444:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mr r27,r28
	r27.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f14d4
	if (cr6.eq) goto loc_825F14D4;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_825F1458:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f148c
	if (cr6.eq) goto loc_825F148C;
	// rotlwi r29,r10,0
	r29.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// bne 0x825f148c
	if (!cr0.eq) goto loc_825F148C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218cd10
	ctx.lr = 0x825F1484;
	sub_8218CD10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x825F148C;
	sub_82130588(ctx, base);
loc_825F148C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f14c0
	if (cr6.eq) goto loc_825F14C0;
	// rotlwi r29,r10,0
	r29.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// bne 0x825f14c0
	if (!cr0.eq) goto loc_825F14C0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218cd10
	ctx.lr = 0x825F14B8;
	sub_8218CD10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x825F14C0;
	sub_82130588(ctx, base);
loc_825F14C0:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x825f1458
	if (cr6.lt) goto loc_825F1458;
loc_825F14D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825F14DC;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x825F14F0;
	sub_82130588(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// sth r28,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r28.u16);
	// sth r28,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r28.u16);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x825F1504;
	sub_82130588(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// sth r28,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r28.u16);
	// sth r28,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r28.u16);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x825F1518;
	sub_82130588(ctx, base);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// sth r28,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r28.u16);
	// sth r28,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r28.u16);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x825F152C;
	sub_82130588(ctx, base);
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// sth r28,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r28.u16);
	// sth r28,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r28.u16);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x825F1540;
	sub_82130588(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x825f1550
	if (!cr6.eq) goto loc_825F1550;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// b 0x825f1588
	goto loc_825F1588;
loc_825F1550:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_825F1554:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f1554
	if (!cr6.eq) goto loc_825F1554;
	// subf r11,r26,r11
	r11.s64 = r11.s64 - r26.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x825F157C;
	sub_82130528(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x823da950
	ctx.lr = 0x825F1588;
	sub_823DA950(ctx, base);
loc_825F1588:
	// stw r3,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r3.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f159c
	if (cr6.eq) goto loc_825F159C;
	// bl 0x82130588
	ctx.lr = 0x825F159C;
	sub_82130588(ctx, base);
loc_825F159C:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x825f1620
	if (cr6.eq) goto loc_825F1620;
	// lis r11,5461
	r11.s64 = 357892096;
	// ori r10,r11,21845
	ctx.r10.u64 = r11.u64 | 21845;
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// bgt cr6,0x825f15c4
	if (cr6.gt) goto loc_825F15C4;
	// rlwinm r11,r25,1,0,30
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x825f15c8
	goto loc_825F15C8;
loc_825F15C4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825F15C8:
	// bl 0x82130528
	ctx.lr = 0x825F15CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f1614
	if (cr6.eq) goto loc_825F1614;
	// addic. r10,r25,-1
	xer.ca = r25.u32 > 0;
	ctx.r10.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x825f1608
	if (cr0.lt) goto loc_825F1608;
	// addi r11,r3,6
	r11.s64 = ctx.r3.s64 + 6;
loc_825F15E0:
	// stw r28,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, r28.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r28,1(r11)
	PPC_STORE_U8(r11.u32 + 1, r28.u8);
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// stb r28,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r28.u8);
	// stb r28,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, r28.u8);
	// stb r28,3(r11)
	PPC_STORE_U8(r11.u32 + 3, r28.u8);
	// stb r28,2(r11)
	PPC_STORE_U8(r11.u32 + 2, r28.u8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x825f15e0
	if (!cr0.lt) goto loc_825F15E0;
loc_825F1608:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// b 0x825f1624
	goto loc_825F1624;
loc_825F1614:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// b 0x825f1624
	goto loc_825F1624;
loc_825F1620:
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
loc_825F1624:
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r25,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r25.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x823d9890
	ctx.lr = 0x825F1638;
	sub_823D9890(ctx, base);
	// sth r28,364(r31)
	PPC_STORE_U16(r31.u32 + 364, r28.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_825F13D8) {
	__imp__sub_825F13D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F1644) {
	__imp__sub_825F1644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1648) {
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
	ctx.lr = 0x825F1650;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r11,-20156
	ctx.r5.s64 = r11.s64 + -20156;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825f13d8
	ctx.lr = 0x825F1674;
	sub_825F13D8(ctx, base);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x825F167C;
	sub_82130588(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821378b8
	ctx.lr = 0x825F1684;
	sub_821378B8(ctx, base);
	// stw r3,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r3.u32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r10,23160
	ctx.r5.s64 = ctx.r10.s64 + 23160;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x825F16A8;
	sub_821CA6A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x825f16d4
	if (!cr6.eq) goto loc_825F16D4;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,23136
	ctx.r3.s64 = r11.s64 + 23136;
	// bl 0x82130000
	ctx.lr = 0x825F16C4;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_825F16D4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f16f0
	if (cr6.eq) goto loc_825F16F0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,23112
	ctx.r3.s64 = r11.s64 + 23112;
	// bl 0x82130000
	ctx.lr = 0x825F16F0;
	sub_82130000(ctx, base);
loc_825F16F0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x821be710
	ctx.lr = 0x825F170C;
	sub_821BE710(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lis r29,-32252
	r29.s64 = -2113667072;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,-1352(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -1352);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x825f1768
	if (cr6.eq) goto loc_825F1768;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x825f1768
	if (cr6.eq) goto loc_825F1768;
	// lfs f0,12796(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x825f1768
	if (cr6.eq) goto loc_825F1768;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r10,23044
	ctx.r3.s64 = ctx.r10.s64 + 23044;
	// lfd f2,23104(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 23104);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x825F1768;
	sub_82130000(ctx, base);
loc_825F1768:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F1778;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,44
	ctx.r4.s64 = r31.s64 + 44;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F1788;
	sub_821BE710(ctx, base);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F179C;
	sub_821BE710(ctx, base);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// addi r21,r31,52
	r21.s64 = r31.s64 + 52;
	// blt cr6,0x825f17c0
	if (cr6.lt) goto loc_825F17C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F17BC;
	sub_821BE710(ctx, base);
	// b 0x825f17cc
	goto loc_825F17CC;
loc_825F17C0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
loc_825F17CC:
	// lfs f0,12796(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12796);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x825f183c
	if (cr6.lt) goto loc_825F183C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,56
	ctx.r4.s64 = r31.s64 + 56;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F17EC;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,60
	ctx.r4.s64 = r31.s64 + 60;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F17FC;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F180C;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F181C;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F182C;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F183C;
	sub_821BE710(ctx, base);
loc_825F183C:
	// addi r22,r31,104
	r22.s64 = r31.s64 + 104;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F1850;
	sub_821BE710(ctx, base);
	// lis r11,5461
	r11.s64 = 357892096;
	// ori r10,r11,21845
	ctx.r10.u64 = r11.u64 | 21845;
	// lwz r30,104(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// bgt cr6,0x825f1874
	if (cr6.gt) goto loc_825F1874;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x825f1878
	goto loc_825F1878;
loc_825F1874:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825F1878:
	// bl 0x82130528
	ctx.lr = 0x825F187C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r24,0
	r24.s64 = 0;
	// beq cr6,0x825f18c4
	if (cr6.eq) goto loc_825F18C4;
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x825f18bc
	if (cr0.lt) goto loc_825F18BC;
	// addi r11,r3,6
	r11.s64 = ctx.r3.s64 + 6;
loc_825F1894:
	// stw r24,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, r24.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r24,1(r11)
	PPC_STORE_U8(r11.u32 + 1, r24.u8);
	// stb r24,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r24.u8);
	// stb r24,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r24.u8);
	// stb r24,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, r24.u8);
	// stb r24,3(r11)
	PPC_STORE_U8(r11.u32 + 3, r24.u8);
	// stb r24,2(r11)
	PPC_STORE_U8(r11.u32 + 2, r24.u8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x825f1894
	if (!cr0.lt) goto loc_825F1894;
loc_825F18BC:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x825f18c8
	goto loc_825F18C8;
loc_825F18C4:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_825F18C8:
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r30,r24
	r30.u64 = r24.u64;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x825f1904
	if (!cr6.gt) goto loc_825F1904;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_825F18E0:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// bl 0x825f0068
	ctx.lr = 0x825F18F0;
	sub_825F0068(ctx, base);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x825f18e0
	if (cr6.lt) goto loc_825F18E0;
loc_825F1904:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F1914;
	sub_821BE710(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f1950
	if (!cr6.eq) goto loc_825F1950;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// beq cr6,0x825f1948
	if (cr6.eq) goto loc_825F1948;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825F193C;
	sub_82130528(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x825f194c
	goto loc_825F194C;
loc_825F1948:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_825F194C:
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_825F1950:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// addi r25,r31,16
	r25.s64 = r31.s64 + 16;
	// lhz r9,22(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f1990
	if (!cr6.eq) goto loc_825F1990;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r11,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r11.u16);
	// beq cr6,0x825f1988
	if (cr6.eq) goto loc_825F1988;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825F197C;
	sub_82130528(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x825f198c
	goto loc_825F198C;
loc_825F1988:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_825F198C:
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
loc_825F1990:
	// sth r30,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r30.u16);
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f19d0
	if (!cr6.eq) goto loc_825F19D0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r11,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r11.u16);
	// beq cr6,0x825f19c8
	if (cr6.eq) goto loc_825F19C8;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825F19BC;
	sub_82130528(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x825f19cc
	goto loc_825F19CC;
loc_825F19C8:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_825F19CC:
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_825F19D0:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// sth r10,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r10.u16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f1a10
	if (!cr6.gt) goto loc_825F1A10;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_825F19E8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// add r4,r29,r11
	ctx.r4.u64 = r29.u64 + r11.u64;
	// bl 0x821be710
	ctx.lr = 0x825F19FC;
	sub_821BE710(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x825f19e8
	if (cr6.lt) goto loc_825F19E8;
loc_825F1A10:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x825F1A18;
	sub_821BE610(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1ad4
	if (cr6.eq) goto loc_825F1AD4;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r27,r11,23028
	r27.s64 = r11.s64 + 23028;
	// addi r26,r10,23016
	r26.s64 = ctx.r10.s64 + 23016;
loc_825F1A3C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x825F1A50;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8217d9f8
	ctx.lr = 0x825F1A5C;
	sub_8217D9F8(ctx, base);
	// stwx r3,r30,r28
	PPC_STORE_U32(r30.u32 + r28.u32, ctx.r3.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f1a9c
	if (!cr6.eq) goto loc_825F1A9C;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f1a9c
	if (!cr6.eq) goto loc_825F1A9C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f1a9c
	if (!cr6.eq) goto loc_825F1A9C;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f1a9c
	if (!cr6.eq) goto loc_825F1A9C;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stwx r24,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r24.u32);
	// b 0x825f1ac0
	goto loc_825F1AC0;
loc_825F1A9C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x825F1AB0;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// bl 0x8217d9f8
	ctx.lr = 0x825F1ABC;
	sub_8217D9F8(ctx, base);
	// stwx r3,r30,r28
	PPC_STORE_U32(r30.u32 + r28.u32, ctx.r3.u32);
loc_825F1AC0:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825f1a3c
	if (cr6.lt) goto loc_825F1A3C;
loc_825F1AD4:
	// lwz r6,0(r22)
	ctx.r6.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x825f1b18
	if (!cr6.gt) goto loc_825F1B18;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rotlwi r7,r6,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
loc_825F1AF0:
	// lbz r9,3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// ble cr6,0x825f1b0c
	if (!cr6.gt) goto loc_825F1B0C;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_825F1B0C:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x825f1af0
	if (!cr0.eq) goto loc_825F1AF0;
loc_825F1B18:
	// stw r8,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r8.u32);
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// sth r24,364(r31)
	PPC_STORE_U16(r31.u32 + 364, r24.u16);
	// ble cr6,0x825f1b68
	if (!cr6.gt) goto loc_825F1B68;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_825F1B30:
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,255
	cr6.compare<int32_t>(ctx.r8.s32, 255, xer);
	// bgt cr6,0x825f1b68
	if (cr6.gt) goto loc_825F1B68;
	// sth r11,364(r31)
	PPC_STORE_U16(r31.u32 + 364, r11.u16);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// add r6,r9,r31
	ctx.r6.u64 = ctx.r9.u64 + r31.u64;
	// stb r7,108(r6)
	PPC_STORE_U8(ctx.r6.u32 + 108, ctx.r7.u8);
	// lwz r5,0(r22)
	ctx.r5.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x825f1b30
	if (cr6.lt) goto loc_825F1B30;
loc_825F1B68:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_825F1648) {
	__imp__sub_825F1648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1B78) {
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
	ctx.lr = 0x825F1B80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r29,r27
	r29.u64 = r27.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1bdc
	if (cr6.eq) goto loc_825F1BDC;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lis r28,-32127
	r28.s64 = -2105475072;
loc_825F1BA4:
	// lbz r10,14296(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 14296);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1bc8
	if (cr6.eq) goto loc_825F1BC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8217da18
	ctx.lr = 0x825F1BBC;
	sub_8217DA18(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// bl 0x8217da18
	ctx.lr = 0x825F1BC8;
	sub_8217DA18(ctx, base);
loc_825F1BC8:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825f1ba4
	if (cr6.lt) goto loc_825F1BA4;
loc_825F1BDC:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1c6c
	if (cr6.eq) goto loc_825F1C6C;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_825F1BF0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1c24
	if (cr6.eq) goto loc_825F1C24;
	// rotlwi r29,r10,0
	r29.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// bne 0x825f1c24
	if (!cr0.eq) goto loc_825F1C24;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218cd10
	ctx.lr = 0x825F1C1C;
	sub_8218CD10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x825F1C24;
	sub_82130588(ctx, base);
loc_825F1C24:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1c58
	if (cr6.eq) goto loc_825F1C58;
	// rotlwi r29,r10,0
	r29.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// bne 0x825f1c58
	if (!cr0.eq) goto loc_825F1C58;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218cd10
	ctx.lr = 0x825F1C50;
	sub_8218CD10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x825F1C58;
	sub_82130588(ctx, base);
loc_825F1C58:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x825f1bf0
	if (cr6.lt) goto loc_825F1BF0;
loc_825F1C6C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825F1C74;
	sub_82130588(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
	// sth r27,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r27.u16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x825F1C88;
	sub_82130588(ctx, base);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// sth r27,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r27.u16);
	// sth r27,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r27.u16);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x825F1C9C;
	sub_82130588(ctx, base);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// sth r27,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r27.u16);
	// sth r27,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r27.u16);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x825F1CB0;
	sub_82130588(ctx, base);
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// sth r27,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r27.u16);
	// sth r27,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r27.u16);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x825F1CC4;
	sub_82130588(ctx, base);
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// sth r27,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r27.u16);
	// sth r27,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r27.u16);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x825F1CD8;
	sub_82130588(ctx, base);
	// stw r27,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r27.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x825F1CE4;
	sub_82130588(ctx, base);
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825F1B78) {
	__imp__sub_825F1B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F1CF4) {
	__imp__sub_825F1CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1CF8) {
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
	// bl 0x825f1b78
	ctx.lr = 0x825F1D10;
	sub_825F1B78(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,6600(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 6600);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x825f1d2c
	if (!cr6.eq) goto loc_825F1D2C;
	// lwz r10,372(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// stw r10,6600(r11)
	PPC_STORE_U32(r11.u32 + 6600, ctx.r10.u32);
	// b 0x825f1d5c
	goto loc_825F1D5C;
loc_825F1D2C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1d5c
	if (cr6.eq) goto loc_825F1D5C;
loc_825F1D34:
	// lwz r11,372(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x825f1d50
	if (cr6.eq) goto loc_825F1D50;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f1d34
	if (!cr6.eq) goto loc_825F1D34;
	// b 0x825f1d5c
	goto loc_825F1D5C;
loc_825F1D50:
	// lwz r11,372(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// lwz r9,372(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 372);
	// stw r9,372(r10)
	PPC_STORE_U32(ctx.r10.u32 + 372, ctx.r9.u32);
loc_825F1D5C:
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x825F1D64;
	sub_82130588(ctx, base);
	// lhz r11,38(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1d78
	if (cr6.eq) goto loc_825F1D78;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x825F1D78;
	sub_82130588(ctx, base);
loc_825F1D78:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1d8c
	if (cr6.eq) goto loc_825F1D8C;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x825F1D8C;
	sub_82130588(ctx, base);
loc_825F1D8C:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1da0
	if (cr6.eq) goto loc_825F1DA0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x825F1DA0;
	sub_82130588(ctx, base);
loc_825F1DA0:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1db4
	if (cr6.eq) goto loc_825F1DB4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x825F1DB4;
	sub_82130588(ctx, base);
loc_825F1DB4:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f1dc8
	if (cr6.eq) goto loc_825F1DC8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825F1DC8;
	sub_82130588(ctx, base);
loc_825F1DC8:
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

PPC_WEAK_FUNC(sub_825F1CF8) {
	__imp__sub_825F1CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F1DDC) {
	__imp__sub_825F1DDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1DE0) {
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
	// beq cr6,0x825f1e78
	if (cr6.eq) goto loc_825F1E78;
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x825f1e6c
	if (!cr6.eq) goto loc_825F1E6C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,6600(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 6600);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x825f1e40
	if (!cr6.eq) goto loc_825F1E40;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// stw r10,6600(r11)
	PPC_STORE_U32(r11.u32 + 6600, ctx.r10.u32);
	// bl 0x825f1cf8
	ctx.lr = 0x825F1E24;
	sub_825F1CF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x825F1E2C;
	sub_82130588(ctx, base);
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
loc_825F1E40:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f1e60
	if (cr6.eq) goto loc_825F1E60;
loc_825F1E48:
	// lwz r11,372(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x825f1e8c
	if (cr6.eq) goto loc_825F1E8C;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f1e48
	if (!cr6.eq) goto loc_825F1E48;
loc_825F1E60:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,23168
	ctx.r3.s64 = r11.s64 + 23168;
	// bl 0x821bd618
	ctx.lr = 0x825F1E6C;
	sub_821BD618(ctx, base);
loc_825F1E6C:
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,376(r31)
	PPC_STORE_U32(r31.u32 + 376, r11.u32);
loc_825F1E78:
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
loc_825F1E8C:
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,372(r10)
	PPC_STORE_U32(ctx.r10.u32 + 372, r11.u32);
	// bl 0x825f1cf8
	ctx.lr = 0x825F1E9C;
	sub_825F1CF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x825F1EA4;
	sub_82130588(ctx, base);
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

PPC_WEAK_FUNC(sub_825F1DE0) {
	__imp__sub_825F1DE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1EB8) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r3,6600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f1ee8
	if (cr6.eq) goto loc_825F1EE8;
loc_825F1ED8:
	// bl 0x825f1de0
	ctx.lr = 0x825F1EDC;
	sub_825F1DE0(ctx, base);
	// lwz r3,6600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825f1ed8
	if (!cr6.eq) goto loc_825F1ED8;
loc_825F1EE8:
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

PPC_WEAK_FUNC(sub_825F1EB8) {
	__imp__sub_825F1EB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F1EFC) {
	__imp__sub_825F1EFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1F00) {
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
	ctx.lr = 0x825F1F08;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// sth r30,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r30.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// sth r30,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r30.u16);
	// sth r30,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r30.u16);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// sth r30,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r30.u16);
	// sth r30,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r30.u16);
	// lwz r11,6600(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 6600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f1f84
	if (!cr6.eq) goto loc_825F1F84;
	// lis r11,-32161
	r11.s64 = -2107703296;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,7864
	ctx.r4.s64 = r11.s64 + 7864;
	// bl 0x821c2fd8
	ctx.lr = 0x825F1F70;
	sub_821C2FD8(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r10,30368
	ctx.r3.s64 = ctx.r10.s64 + 30368;
	// bl 0x821c3128
	ctx.lr = 0x825F1F80;
	sub_821C3128(ctx, base);
	// lwz r11,6600(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 6600);
loc_825F1F84:
	// stw r11,372(r31)
	PPC_STORE_U32(r31.u32 + 372, r11.u32);
	// li r11,32
	r11.s64 = 32;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r31,6600(r29)
	PPC_STORE_U32(r29.u32 + 6600, r31.u32);
	// stw r30,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r10.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stb r30,96(r31)
	PPC_STORE_U8(r31.u32 + 96, r30.u8);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stb r30,108(r31)
	PPC_STORE_U8(r31.u32 + 108, r30.u8);
	// sth r30,364(r31)
	PPC_STORE_U16(r31.u32 + 364, r30.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F1F00) {
	__imp__sub_825F1F00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F1FF4) {
	__imp__sub_825F1FF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F1FF8) {
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
	ctx.lr = 0x825F2000;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825f2028
	if (!cr6.eq) goto loc_825F2028;
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r4,14292(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 14292);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x825F2024;
	sub_823DB670(ctx, base);
	// b 0x825f2074
	goto loc_825F2074;
loc_825F2028:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// subf r7,r3,r11
	ctx.r7.s64 = r11.s64 - ctx.r3.s64;
loc_825F2038:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r11,r9
	r11.s64 = ctx.r9.s8;
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// blt cr6,0x825f2058
	if (cr6.lt) goto loc_825F2058;
	// cmpwi cr6,r11,90
	cr6.compare<int32_t>(r11.s32, 90, xer);
	// bgt cr6,0x825f2058
	if (cr6.gt) goto loc_825F2058;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
loc_825F2058:
	// stbx r9,r7,r10
	PPC_STORE_U8(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825f2074
	if (cr6.eq) goto loc_825F2074;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r8,80
	cr6.compare<int32_t>(ctx.r8.s32, 80, xer);
	// blt cr6,0x825f2038
	if (cr6.lt) goto loc_825F2038;
loc_825F2074:
	// li r3,380
	ctx.r3.s64 = 380;
	// bl 0x82130528
	ctx.lr = 0x825F207C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2090
	if (cr6.eq) goto loc_825F2090;
	// bl 0x825f1f00
	ctx.lr = 0x825F2088;
	sub_825F1F00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x825f2094
	goto loc_825F2094;
loc_825F2090:
	// li r31,0
	r31.s64 = 0;
loc_825F2094:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f1648
	ctx.lr = 0x825F20A4;
	sub_825F1648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f211c
	if (!cr6.eq) goto loc_825F211C;
	// lwz r4,14292(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 14292);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825f20fc
	if (cr6.eq) goto loc_825F20FC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f1648
	ctx.lr = 0x825F20C8;
	sub_825F1648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f2108
	if (!cr6.eq) goto loc_825F2108;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lwz r4,14292(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 14292);
	// addi r3,r11,23216
	ctx.r3.s64 = r11.s64 + 23216;
	// bl 0x82130000
	ctx.lr = 0x825F20E4;
	sub_82130000(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f20fc
	if (cr6.eq) goto loc_825F20FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f1cf8
	ctx.lr = 0x825F20F4;
	sub_825F1CF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x825F20FC;
	sub_82130588(ctx, base);
loc_825F20FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_825F2108:
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x825F2110;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821378b8
	ctx.lr = 0x825F2118;
	sub_821378B8(ctx, base);
	// stw r3,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r3.u32);
loc_825F211C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F1FF8) {
	__imp__sub_825F1FF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r9,9999
	ctx.r9.s64 = 9999;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// li r7,3842
	ctx.r7.s64 = 3842;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F2128) {
	__imp__sub_825F2128(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F2184) {
	__imp__sub_825F2184(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2188) {
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
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x825F21A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f21cc
	if (cr6.eq) goto loc_825F21CC;
	// li r4,100
	ctx.r4.s64 = 100;
	// bl 0x82606048
	ctx.lr = 0x825F21B4;
	sub_82606048(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
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
loc_825F21CC:
	// li r11,0
	r11.s64 = 0;
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

PPC_WEAK_FUNC(sub_825F2188) {
	__imp__sub_825F2188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F21E8) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c9790
	sub_821C9790(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F21E8) {
	__imp__sub_825F21E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F21F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82605fc8
	sub_82605FC8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F21F0) {
	__imp__sub_825F21F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F21F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82605f70
	sub_82605F70(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F21F8) {
	__imp__sub_825F21F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2200) {
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
	ctx.lr = 0x825F2208;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// bl 0x821be710
	ctx.lr = 0x825F2234;
	sub_821BE710(ctx, base);
	// addi r28,r29,22
	r28.s64 = r29.s64 + 22;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821be6a8
	ctx.lr = 0x825F2248;
	sub_821BE6A8(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r26,r27
	r26.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F2264;
	sub_821BE710(ctx, base);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x825f22a0
	if (cr6.eq) goto loc_825F22A0;
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2280;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821be250
	ctx.lr = 0x825F2298;
	sub_821BE250(ctx, base);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stbx r27,r26,r8
	PPC_STORE_U8(r26.u32 + ctx.r8.u32, r27.u8);
loc_825F22A0:
	// stw r27,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x825F22B4;
	sub_821BE710(ctx, base);
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F22CC;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821be708
	ctx.lr = 0x825F22E4;
	sub_821BE708(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r29,12
	ctx.r4.s64 = r29.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x825F22F4;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r29,20
	ctx.r4.s64 = r29.s64 + 20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x825F2304;
	sub_821BE250(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r29,21
	ctx.r4.s64 = r29.s64 + 21;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be250
	ctx.lr = 0x825F2314;
	sub_821BE250(ctx, base);
	// lhz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// and r6,r7,r25
	ctx.r6.u64 = ctx.r7.u64 & r25.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825f23b0
	if (cr6.eq) goto loc_825F23B0;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f2340
	if (cr6.eq) goto loc_825F2340;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825f1ff8
	ctx.lr = 0x825F233C;
	sub_825F1FF8(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
loc_825F2340:
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// bne cr6,0x825f2398
	if (!cr6.eq) goto loc_825F2398;
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2368;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e4958
	ctx.lr = 0x825F2380;
	sub_821E4958(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821378b8
	ctx.lr = 0x825F2388;
	sub_821378B8(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9234
	return;
loc_825F2398:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e48e8
	ctx.lr = 0x825F23A0;
	sub_821E48E8(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9234
	return;
loc_825F23B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_825F2200) {
	__imp__sub_825F2200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F23BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F23BC) {
	__imp__sub_825F23BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F23C0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x825F23C8;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r20,r8,24
	r20.u64 = ctx.r8.u32 & 0xFF;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x825f2408
	if (cr6.eq) goto loc_825F2408;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f242c
	if (!cr6.eq) goto loc_825F242C;
loc_825F2408:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x825F2410;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2424
	if (cr6.eq) goto loc_825F2424;
	// li r4,100
	ctx.r4.s64 = 100;
	// bl 0x82606048
	ctx.lr = 0x825F2420;
	sub_82606048(ctx, base);
	// b 0x825f2428
	goto loc_825F2428;
loc_825F2424:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_825F2428:
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_825F242C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,23344
	ctx.r5.s64 = r11.s64 + 23344;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x825F244C;
	sub_821CA6A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x825f2478
	if (!cr6.eq) goto loc_825F2478;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,23312
	ctx.r3.s64 = r11.s64 + 23312;
	// bl 0x82130000
	ctx.lr = 0x825F2468;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_825F2478:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f2490
	if (cr6.eq) goto loc_825F2490;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be8d8
	ctx.lr = 0x825F248C;
	sub_821BE8D8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_825F2490:
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F24A4;
	sub_821BE710(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r25,r30
	r25.u64 = r30.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f24e4
	if (!cr6.gt) goto loc_825F24E4;
loc_825F24B8:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F24C8;
	sub_821BE710(ctx, base);
	// cmpw cr6,r31,r21
	cr6.compare<int32_t>(r31.s32, r21.s32, xer);
	// bne cr6,0x825f24d4
	if (!cr6.eq) goto loc_825F24D4;
	// lwz r25,92(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_825F24D4:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x825f24b8
	if (cr6.lt) goto loc_825F24B8;
loc_825F24E4:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F24F4;
	sub_821BE710(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f25b0
	if (cr6.eq) goto loc_825F25B0;
	// addi r28,r26,8
	r28.s64 = r26.s64 + 8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F2514;
	sub_821BE710(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x825f2530
	if (!cr6.gt) goto loc_825F2530;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825F2530:
	// bl 0x82130528
	ctx.lr = 0x825F2534;
	sub_82130528(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r3,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r3.u32);
	// mr r29,r30
	r29.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f25b0
	if (!cr6.gt) goto loc_825F25B0;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_825F254C:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F255C;
	sub_821BE710(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x825F2568;
	sub_82130528(ctx, base);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// lwzx r4,r31,r8
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// bl 0x821be250
	ctx.lr = 0x825F258C;
	sub_821BE250(ctx, base);
	// lwz r6,4(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stbx r30,r4,r5
	PPC_STORE_U8(ctx.r4.u32 + ctx.r5.u32, r30.u8);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// blt cr6,0x825f254c
	if (cr6.lt) goto loc_825F254C;
loc_825F25B0:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x825f25e0
	if (!cr6.eq) goto loc_825F25E0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r11,23288
	ctx.r3.s64 = r11.s64 + 23288;
	// bl 0x82130000
	ctx.lr = 0x825F25C8;
	sub_82130000(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x825F25D0;
	sub_821BE610(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_825F25E0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be568
	ctx.lr = 0x825F25EC;
	sub_821BE568(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be710
	ctx.lr = 0x825F2600;
	sub_821BE710(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r24,r30
	r24.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f2720
	if (!cr6.gt) goto loc_825F2720;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r25,340(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// li r28,1
	r28.s64 = 1;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_825F2620:
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// stb r30,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r30.u8);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r30.u8);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// sth r28,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, r28.u16);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x825f2200
	ctx.lr = 0x825F2658;
	sub_825F2200(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f2708
	if (cr6.eq) goto loc_825F2708;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x825F266C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f269c
	if (cr6.eq) goto loc_825F269C;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// stfs f31,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f31,16(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r30,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r30.u8);
	// stb r30,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r30.u8);
	// sth r28,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r28.u16);
	// b 0x825f26a0
	goto loc_825F26A0;
loc_825F269C:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_825F26A0:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_825F26B0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x825f26b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F26B0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82605d78
	ctx.lr = 0x825F26D8;
	sub_82605D78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f2708
	if (!cr6.eq) goto loc_825F2708;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x825f2708
	if (cr6.eq) goto loc_825F2708;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82605e88
	ctx.lr = 0x825F26F8;
	sub_82605E88(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82605d78
	ctx.lr = 0x825F2708;
	sub_82605D78(ctx, base);
loc_825F2708:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// blt cr6,0x825f2620
	if (cr6.lt) goto loc_825F2620;
loc_825F2720:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x825F2728;
	sub_821BE610(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825f275c
	if (!cr6.eq) goto loc_825F275C;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82606158
	ctx.lr = 0x825F273C;
	sub_82606158(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,23252
	ctx.r3.s64 = r11.s64 + 23252;
	// bl 0x82130000
	ctx.lr = 0x825F274C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_825F275C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_825F23C0) {
	__imp__sub_825F23C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F276C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F276C) {
	__imp__sub_825F276C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2770) {
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
	ctx.lr = 0x825F2778;
	// addi r31,r1,-208
	r31.s64 = ctx.r1.s64 + -208;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825f27ac
	if (!cr6.eq) goto loc_825F27AC;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,23416
	ctx.r3.s64 = r11.s64 + 23416;
	// bl 0x82130000
	ctx.lr = 0x825F27A0;
	sub_82130000(ctx, base);
loc_825F27A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// b 0x823d9240
	return;
loc_825F27AC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82605e38
	ctx.lr = 0x825F27B4;
	sub_82605E38(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825f29a0
	if (!cr6.eq) goto loc_825F29A0;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// lwz r11,14316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14316);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x825f27f4
	if (cr6.eq) goto loc_825F27F4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x825f27f4
	if (cr6.eq) goto loc_825F27F4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x825f27f4
	if (!cr6.eq) goto loc_825F27F4;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,23360
	ctx.r3.s64 = r11.s64 + 23360;
	// bl 0x821bd618
	ctx.lr = 0x825F27F0;
	sub_821BD618(ctx, base);
	// lwz r11,14316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14316);
loc_825F27F4:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x825f27a0
	if (cr6.eq) goto loc_825F27A0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bne cr6,0x825f2890
	if (!cr6.eq) goto loc_825F2890;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r11,23352
	ctx.r4.s64 = r11.s64 + 23352;
	// bl 0x823dc018
	ctx.lr = 0x825F2818;
	sub_823DC018(ctx, base);
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_825F2820:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f2820
	if (!cr6.eq) goto loc_825F2820;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2850;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x825f2918
	if (!cr6.gt) goto loc_825F2918;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_825F2870:
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// sth r5,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r5.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// blt cr6,0x825f2870
	if (cr6.lt) goto loc_825F2870;
	// b 0x825f2918
	goto loc_825F2918;
loc_825F2890:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82137a08
	ctx.lr = 0x825F28A4;
	sub_82137A08(ctx, base);
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_825F28AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f28ac
	if (!cr6.eq) goto loc_825F28AC;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F28DC;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x825f2918
	if (!cr6.gt) goto loc_825F2918;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_825F28FC:
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// sth r5,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r5.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// blt cr6,0x825f28fc
	if (cr6.lt) goto loc_825F28FC;
loc_825F2918:
	// li r3,24
	ctx.r3.s64 = 24;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// bl 0x82130528
	ctx.lr = 0x825F2924;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2960
	if (cr6.eq) goto loc_825F2960;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r28,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r28.u8);
	// stb r28,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r28.u8);
	// sth r10,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, ctx.r10.u16);
	// b 0x825f2964
	goto loc_825F2964;
loc_825F2960:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_825F2964:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e48e8
	ctx.lr = 0x825F296C;
	sub_821E48E8(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// lwz r3,6608(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6608);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2990
	if (cr6.eq) goto loc_825F2990;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825f1ff8
	ctx.lr = 0x825F298C;
	sub_825F1FF8(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
loc_825F2990:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82605d78
	ctx.lr = 0x825F29A0;
	sub_82605D78(ctx, base);
loc_825F29A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825F2770) {
	__imp__sub_825F2770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F29AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F29AC) {
	__imp__sub_825F29AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F29B0) {
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
	ctx.lr = 0x825F29B8;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f29ec
	if (!cr6.eq) goto loc_825F29EC;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,23416
	ctx.r3.s64 = r11.s64 + 23416;
	// bl 0x82130000
	ctx.lr = 0x825F29E0;
	sub_82130000(ctx, base);
loc_825F29E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9240
	return;
loc_825F29EC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x825F29F8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82605e38
	ctx.lr = 0x825F2A04;
	sub_82605E38(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825f2cac
	if (!cr6.eq) goto loc_825F2CAC;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// lwz r11,14316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14316);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x825f2a44
	if (cr6.eq) goto loc_825F2A44;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x825f2a44
	if (cr6.eq) goto loc_825F2A44;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x825f2a58
	if (!cr6.eq) goto loc_825F2A58;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,23560
	ctx.r3.s64 = r11.s64 + 23560;
	// bl 0x821bd618
	ctx.lr = 0x825F2A40;
	sub_821BD618(ctx, base);
	// b 0x825f2a54
	goto loc_825F2A54;
loc_825F2A44:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,23500
	ctx.r3.s64 = r11.s64 + 23500;
	// bl 0x82130000
	ctx.lr = 0x825F2A54;
	sub_82130000(ctx, base);
loc_825F2A54:
	// lwz r11,14316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14316);
loc_825F2A58:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x825f29e0
	if (cr6.eq) goto loc_825F29E0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x825f2b9c
	if (!cr6.eq) goto loc_825F2B9C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_825F2A6C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f2a6c
	if (!cr6.eq) goto loc_825F2A6C;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r11,5
	ctx.r10.s64 = r11.s64 + 5;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2A98;
	sub_823DBFF4(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r8,r11,23496
	ctx.r8.s64 = r11.s64 + 23496;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r4,1(r6)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lbz r3,2(r6)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + 2);
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// stb r4,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r4.u8);
	// stb r3,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r3.u8);
loc_825F2AD0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x825f2ad0
	if (!cr6.eq) goto loc_825F2AD0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_825F2AE4:
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x825f2ae4
	if (!cr6.eq) goto loc_825F2AE4;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_825F2B00:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f2b00
	if (!cr6.eq) goto loc_825F2B00;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_825F2B14:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x825f2b14
	if (!cr6.eq) goto loc_825F2B14;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_825F2B30:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825f2b30
	if (!cr6.eq) goto loc_825F2B30;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// rlwinm r12,r7,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2B60;
	sub_823DBFF4(ctx, base);
	// lwz r6,0(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stwux r6,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x825f2c1c
	if (!cr6.gt) goto loc_825F2C1C;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
loc_825F2B80:
	// lbzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// sth r6,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r6.u16);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// blt cr6,0x825f2b80
	if (cr6.lt) goto loc_825F2B80;
	// b 0x825f2c1c
	goto loc_825F2C1C;
loc_825F2B9C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x825f2bb0
	if (!cr6.eq) goto loc_825F2BB0;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// b 0x825f2c1c
	goto loc_825F2C1C;
loc_825F2BB0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_825F2BB4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f2bb4
	if (!cr6.eq) goto loc_825F2BB4;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825F2BE4;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x825f2c1c
	if (!cr6.gt) goto loc_825F2C1C;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_825F2C04:
	// lbzx r7,r11,r27
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + r27.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// sth r7,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// blt cr6,0x825f2c04
	if (cr6.lt) goto loc_825F2C04;
loc_825F2C1C:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x825F2C24;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2c60
	if (cr6.eq) goto loc_825F2C60;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r28,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r28.u8);
	// stb r28,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r28.u8);
	// sth r10,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, ctx.r10.u16);
	// b 0x825f2c64
	goto loc_825F2C64;
loc_825F2C60:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_825F2C64:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e48e8
	ctx.lr = 0x825F2C6C;
	sub_821E48E8(ctx, base);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x825F2C7C;
	sub_821C9790(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r3,6608(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6608);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2c9c
	if (cr6.eq) goto loc_825F2C9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825f1ff8
	ctx.lr = 0x825F2C98;
	sub_825F1FF8(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
loc_825F2C9C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82605d78
	ctx.lr = 0x825F2CAC;
	sub_82605D78(ctx, base);
loc_825F2CAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825F29B0) {
	__imp__sub_825F29B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2CB8) {
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
	ctx.lr = 0x825F2CC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f2d7c
	if (!cr6.gt) goto loc_825F2D7C;
	// li r30,0
	r30.s64 = 0;
loc_825F2CDC:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f2d68
	if (cr6.eq) goto loc_825F2D68;
loc_825F2CEC:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r28,8(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f2d44
	if (cr6.eq) goto loc_825F2D44;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2d14
	if (cr6.eq) goto loc_825F2D14;
	// bl 0x82130588
	ctx.lr = 0x825F2D14;
	sub_82130588(ctx, base);
loc_825F2D14:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f2d3c
	if (cr6.eq) goto loc_825F2D3C;
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f2d38
	if (cr6.eq) goto loc_825F2D38;
	// rlwinm r3,r3,0,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFE;
	// bl 0x82130588
	ctx.lr = 0x825F2D34;
	sub_82130588(ctx, base);
	// b 0x825f2d3c
	goto loc_825F2D3C;
loc_825F2D38:
	// bl 0x825f1de0
	ctx.lr = 0x825F2D3C;
	sub_825F1DE0(ctx, base);
loc_825F2D3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x825F2D44;
	sub_82130588(ctx, base);
loc_825F2D44:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x825F2D50;
	sub_82130588(ctx, base);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stwx r28,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r28.u32);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r8,r30,r9
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825f2cec
	if (!cr6.eq) goto loc_825F2CEC;
loc_825F2D68:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x825f2cdc
	if (cr6.lt) goto loc_825F2CDC;
loc_825F2D7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825F2CB8) {
	__imp__sub_825F2CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F2D84) {
	__imp__sub_825F2D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2D88) {
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
	ctx.lr = 0x825F2D90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x825f2cb8
	ctx.lr = 0x825F2DA0;
	sub_825F2CB8(ctx, base);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825f2dbc
	if (cr6.eq) goto loc_825F2DBC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826060d8
	ctx.lr = 0x825F2DB4;
	sub_826060D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x825F2DBC;
	sub_82130588(ctx, base);
loc_825F2DBC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825f2df8
	if (!cr6.gt) goto loc_825F2DF8;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_825F2DD8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x825F2DE4;
	sub_82130588(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f2dd8
	if (cr6.lt) goto loc_825F2DD8;
loc_825F2DF8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x825F2E00;
	sub_82130588(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F2D88) {
	__imp__sub_825F2D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F2E10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x825F2E18;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mullw r10,r4,r9
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x825f3160
	if (cr0.eq) goto loc_825F3160;
	// addis r19,r11,1
	r19.s64 = r11.s64 + 65536;
	// addi r19,r19,-13312
	r19.s64 = r19.s64 + -13312;
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// bge cr6,0x825f3160
	if (!cr6.lt) goto loc_825F3160;
	// mulli r10,r10,816
	ctx.r10.s64 = ctx.r10.s64 * 816;
	// add. r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// beq 0x825f3160
	if (cr0.eq) goto loc_825F3160;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,60(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 60);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// ori r8,r10,57696
	ctx.r8.u64 = ctx.r10.u64 | 57696;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v127,r11,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bgt cr6,0x825f2e9c
	if (cr6.gt) goto loc_825F2E9C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	f0.f64 = double(temp.f32);
loc_825F2E9C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,10584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 10584);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// dcbt r0,r28
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f9,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmuls f6,f10,f10
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f12
	cr6.compare(ctx.f5.f64, ctx.f12.f64);
	// bgt cr6,0x825f3160
	if (cr6.gt) goto loc_825F3160;
	// lwz r11,288(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 288);
	// li r21,0
	r21.s64 = 0;
	// li r22,1
	r22.s64 = 1;
	// oris r10,r11,32768
	ctx.r10.u64 = r11.u64 | 2147483648;
	// stw r21,276(r25)
	PPC_STORE_U32(r25.u32 + 276, r21.u32);
	// stw r21,268(r25)
	PPC_STORE_U32(r25.u32 + 268, r21.u32);
	// mr r26,r21
	r26.u64 = r21.u64;
	// stw r10,288(r25)
	PPC_STORE_U32(r25.u32 + 288, ctx.r10.u32);
	// mr r24,r21
	r24.u64 = r21.u64;
	// lbz r9,67(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 67);
	// extsb r29,r9
	r29.s64 = ctx.r9.s8;
	// mr r23,r21
	r23.u64 = r21.u64;
	// mr r31,r21
	r31.u64 = r21.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x825f306c
	if (!cr6.gt) goto loc_825F306C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r21
	r30.u64 = r21.u64;
	// lfs f31,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f31.f64 = double(temp.f32);
loc_825F2F20:
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x825f2f44
	if (cr6.gt) goto loc_825F2F44;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x825f2f50
	goto loc_825F2F50;
loc_825F2F44:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
loc_825F2F50:
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171c48
	ctx.lr = 0x825F2F78;
	sub_82171C48(ctx, base);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// blt cr6,0x825f305c
	if (cr6.lt) goto loc_825F305C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82171c48
	ctx.lr = 0x825F2FB4;
	sub_82171C48(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171e70
	ctx.lr = 0x825F2FCC;
	sub_82171E70(ctx, base);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825f305c
	if (cr6.eq) goto loc_825F305C;
loc_825F2FEC:
	// dcbt r0,r11
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bgt cr6,0x825f300c
	if (cr6.gt) goto loc_825F300C;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lbz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// b 0x825f3014
	goto loc_825F3014;
loc_825F300C:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
loc_825F3014:
	// extsb r10,r7
	ctx.r10.s64 = ctx.r7.s8;
	// slw r10,r22,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r10.u8 & 0x3F));
	// xor r24,r10,r24
	r24.u64 = ctx.r10.u64 ^ r24.u64;
	// and r7,r10,r24
	ctx.r7.u64 = ctx.r10.u64 & r24.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825f3050
	if (cr6.eq) goto loc_825F3050;
	// dcbt r0,r11
	// slw r7,r22,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825f304c
	if (cr6.eq) goto loc_825F304C;
	// or r23,r10,r23
	r23.u64 = ctx.r10.u64 | r23.u64;
	// b 0x825f3050
	goto loc_825F3050;
loc_825F304C:
	// andc r23,r23,r10
	r23.u64 = r23.u64 & ~ctx.r10.u64;
loc_825F3050:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x825f2fec
	if (cr6.lt) goto loc_825F2FEC;
loc_825F305C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x825f2f20
	if (cr6.lt) goto loc_825F2F20;
loc_825F306C:
	// lbz r11,65(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 65);
	// mr r31,r21
	r31.u64 = r21.u64;
	// extsb r27,r11
	r27.s64 = r11.s8;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x825f310c
	if (!cr6.gt) goto loc_825F310C;
loc_825F3080:
	// slw r30,r22,r31
	r30.u64 = r31.u8 & 0x20 ? 0 : (r22.u32 << (r31.u8 & 0x3F));
	// and r11,r30,r24
	r11.u64 = r30.u64 & r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3100
	if (cr6.eq) goto loc_825F3100;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82171c18
	ctx.lr = 0x825F30A0;
	sub_82171C18(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82171c18
	ctx.lr = 0x825F30B4;
	sub_82171C18(ctx, base);
	// and r11,r30,r23
	r11.u64 = r30.u64 & r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// beq cr6,0x825f30d0
	if (cr6.eq) goto loc_825F30D0;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r29,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x825f30d8
	goto loc_825F30D8;
loc_825F30D0:
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
loc_825F30D8:
	// lvx128 v2,r9,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// lvx128 v3,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x825f3160
	if (cr6.eq) goto loc_825F3160;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82171e80
	ctx.lr = 0x825F30FC;
	sub_82171E80(ctx, base);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_825F3100:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x825f3080
	if (cr6.lt) goto loc_825F3080;
loc_825F310C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x825f3160
	if (!cr6.gt) goto loc_825F3160;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// stw r26,276(r25)
	PPC_STORE_U32(r25.u32 + 276, r26.u32);
	// stw r21,268(r25)
	PPC_STORE_U32(r25.u32 + 268, r21.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3134
	if (cr6.eq) goto loc_825F3134;
	// li r11,2
	r11.s64 = 2;
	// stw r11,272(r25)
	PPC_STORE_U32(r25.u32 + 272, r11.u32);
	// b 0x825f3138
	goto loc_825F3138;
loc_825F3134:
	// stw r21,272(r25)
	PPC_STORE_U32(r25.u32 + 272, r21.u32);
loc_825F3138:
	// stw r28,256(r25)
	PPC_STORE_U32(r25.u32 + 256, r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_825F3160:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_825F2E10) {
	__imp__sub_825F2E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3178) {
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
	ctx.lr = 0x825F3180;
	// stwu r1,-2224(r1)
	ea = -2224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r22,0
	r22.s64 = 0;
	// lbz r10,10552(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10552);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f31c8
	if (cr6.eq) goto loc_825F31C8;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x825f31c8
	if (cr6.eq) goto loc_825F31C8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821716c0
	ctx.lr = 0x825F31B8;
	sub_821716C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f31c8
	if (cr6.eq) goto loc_825F31C8;
	// li r22,1
	r22.s64 = 1;
loc_825F31C8:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r30,0
	r30.s64 = 0;
	// ori r8,r10,57792
	ctx.r8.u64 = ctx.r10.u64 | 57792;
	// lwz r28,16(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mullw r10,r25,r8
	ctx.r10.s64 = int64_t(r25.s32) * int64_t(ctx.r8.s32);
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
	// beq cr6,0x825f3204
	if (cr6.eq) goto loc_825F3204;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,10577(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10577);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f3208
	if (!cr6.eq) goto loc_825F3208;
loc_825F3204:
	// li r11,0
	r11.s64 = 0;
loc_825F3208:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3234
	if (cr6.eq) goto loc_825F3234;
	// addis r6,r26,1
	ctx.r6.s64 = r26.s64 + 65536;
	// li r5,512
	ctx.r5.s64 = 512;
	// addi r6,r6,-7840
	ctx.r6.s64 = ctx.r6.s64 + -7840;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,1
	r30.s64 = 1;
	// bl 0x82173728
	ctx.lr = 0x825F3230;
	sub_82173728(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_825F3234:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x825f32bc
	if (!cr6.gt) goto loc_825F32BC;
	// lis r11,0
	r11.s64 = 0;
	// clrlwi r24,r30,24
	r24.u64 = r30.u32 & 0xFF;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// ori r27,r11,52224
	r27.u64 = r11.u64 | 52224;
loc_825F3250:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825f3260
	if (cr6.eq) goto loc_825F3260;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x825f3264
	goto loc_825F3264;
loc_825F3260:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_825F3264:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,64(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f32ac
	if (cr6.eq) goto loc_825F32AC;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f2e10
	ctx.lr = 0x825F3294;
	sub_825F2E10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f32ac
	if (cr6.eq) goto loc_825F32AC;
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x825f32bc
	if (!cr6.lt) goto loc_825F32BC;
loc_825F32AC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x825f3250
	if (cr6.lt) goto loc_825F3250;
loc_825F32BC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,10544(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10544);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f32f0
	if (cr6.eq) goto loc_825F32F0;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bne cr6,0x825f32ec
	if (!cr6.eq) goto loc_825F32EC;
	// li r5,0
	ctx.r5.s64 = 0;
loc_825F32EC:
	// bl 0x82172d08
	ctx.lr = 0x825F32F0;
	sub_82172D08(ctx, base);
loc_825F32F0:
	// addi r1,r1,2224
	ctx.r1.s64 = ctx.r1.s64 + 2224;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_825F3178) {
	__imp__sub_825F3178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F32F8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
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
	// bl 0x823d91c4
	ctx.lr = 0x825F3300;
	// stfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f31.u64);
	// stwu r1,-592(r1)
	ea = -592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mullw r10,r4,r9
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// add. r21,r10,r11
	r21.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// beq 0x825f370c
	if (cr0.eq) goto loc_825F370C;
	// addis r16,r21,1
	r16.s64 = r21.s64 + 65536;
	// addi r16,r16,-13312
	r16.s64 = r16.s64 + -13312;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x825f370c
	if (!cr6.lt) goto loc_825F370C;
	// mulli r11,r11,816
	r11.s64 = r11.s64 * 816;
	// add. r23,r11,r21
	r23.u64 = r11.u64 + r21.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// beq 0x825f370c
	if (cr0.eq) goto loc_825F370C;
	// lis r11,0
	r11.s64 = 0;
	// lfs f0,60(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 60);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// ori r9,r11,57696
	ctx.r9.u64 = r11.u64 | 57696;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r21,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bgt cr6,0x825f337c
	if (cr6.gt) goto loc_825F337C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	f0.f64 = double(temp.f32);
loc_825F337C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,10584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 10584);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// dcbt r0,r25
	// lfs f13,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f9,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmuls f6,f10,f10
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f12
	cr6.compare(ctx.f5.f64, ctx.f12.f64);
	// bgt cr6,0x825f370c
	if (cr6.gt) goto loc_825F370C;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82171ed0
	ctx.lr = 0x825F33C8;
	sub_82171ED0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f370c
	if (!cr6.eq) goto loc_825F370C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r10,288(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 288);
	// li r18,0
	r18.s64 = 0;
	// addi r11,r11,-30940
	r11.s64 = r11.s64 + -30940;
	// oris r9,r10,32768
	ctx.r9.u64 = ctx.r10.u64 | 2147483648;
	// stw r18,276(r23)
	PPC_STORE_U32(r23.u32 + 276, r18.u32);
	// stw r18,268(r23)
	PPC_STORE_U32(r23.u32 + 268, r18.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r9,288(r23)
	PPC_STORE_U32(r23.u32 + 288, ctx.r9.u32);
	// li r20,1
	r20.s64 = 1;
	// lbz r7,67(r25)
	ctx.r7.u64 = PPC_LOAD_U8(r25.u32 + 67);
	// mr r24,r18
	r24.u64 = r18.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// extsb r28,r7
	r28.s64 = ctx.r7.s8;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x825f3420
	if (!cr6.eq) goto loc_825F3420;
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
loc_825F3420:
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// clrlwi r26,r10,24
	r26.u64 = ctx.r10.u32 & 0xFF;
	// mr r22,r18
	r22.u64 = r18.u64;
	// mr r19,r18
	r19.u64 = r18.u64;
	// mr r30,r18
	r30.u64 = r18.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x825f35d0
	if (!cr6.gt) goto loc_825F35D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r31,r18
	r31.u64 = r18.u64;
	// addi r29,r1,304
	r29.s64 = ctx.r1.s64 + 304;
	// ori r27,r10,57712
	r27.u64 = ctx.r10.u64 | 57712;
	// lfs f31,14196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f31.f64 = double(temp.f32);
loc_825F3460:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82171c48
	ctx.lr = 0x825F3470;
	sub_82171C48(ctx, base);
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x825f3494
	if (cr6.gt) goto loc_825F3494;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x825f34a0
	goto loc_825F34A0;
loc_825F3494:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
loc_825F34A0:
	// lwz r10,52(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 52);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r8,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v60,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v57,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x825f34e0
	if (!cr6.lt) goto loc_825F34E0;
	// stw r18,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r18.u32);
	// b 0x825f35bc
	goto loc_825F35BC;
loc_825F34E0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// stw r20,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r20.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// beq cr6,0x825f3510
	if (cr6.eq) goto loc_825F3510;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// add r7,r21,r27
	ctx.r7.u64 = r21.u64 + r27.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// bl 0x82171d38
	ctx.lr = 0x825F350C;
	sub_82171D38(ctx, base);
	// b 0x825f3514
	goto loc_825F3514;
loc_825F3510:
	// bl 0x82171c48
	ctx.lr = 0x825F3514;
	sub_82171C48(ctx, base);
loc_825F3514:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171e70
	ctx.lr = 0x825F352C;
	sub_82171E70(ctx, base);
	// lwz r11,48(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 48);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// mr r9,r18
	ctx.r9.u64 = r18.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x825f35bc
	if (!cr6.gt) goto loc_825F35BC;
loc_825F354C:
	// dcbt r0,r11
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bgt cr6,0x825f356c
	if (cr6.gt) goto loc_825F356C;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lbz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// b 0x825f3574
	goto loc_825F3574;
loc_825F356C:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
loc_825F3574:
	// extsb r10,r7
	ctx.r10.s64 = ctx.r7.s8;
	// slw r10,r20,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r20.u32 << (ctx.r10.u8 & 0x3F));
	// xor r22,r10,r22
	r22.u64 = ctx.r10.u64 ^ r22.u64;
	// and r7,r10,r22
	ctx.r7.u64 = ctx.r10.u64 & r22.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825f35b0
	if (cr6.eq) goto loc_825F35B0;
	// dcbt r0,r11
	// slw r7,r20,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (r20.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825f35ac
	if (cr6.eq) goto loc_825F35AC;
	// or r19,r10,r19
	r19.u64 = ctx.r10.u64 | r19.u64;
	// b 0x825f35b0
	goto loc_825F35B0;
loc_825F35AC:
	// andc r19,r19,r10
	r19.u64 = r19.u64 & ~ctx.r10.u64;
loc_825F35B0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x825f354c
	if (cr6.lt) goto loc_825F354C;
loc_825F35BC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x825f3460
	if (cr6.lt) goto loc_825F3460;
loc_825F35D0:
	// lbz r11,65(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 65);
	// mr r28,r18
	r28.u64 = r18.u64;
	// mr r30,r18
	r30.u64 = r18.u64;
	// extsb r27,r11
	r27.s64 = r11.s8;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x825f36c0
	if (!cr6.gt) goto loc_825F36C0;
	// lis r26,-32127
	r26.s64 = -2105475072;
loc_825F35EC:
	// slw r29,r20,r30
	r29.u64 = r30.u8 & 0x20 ? 0 : (r20.u32 << (r30.u8 & 0x3F));
	// and r11,r29,r22
	r11.u64 = r29.u64 & r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f36b4
	if (cr6.eq) goto loc_825F36B4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82171c18
	ctx.lr = 0x825F360C;
	sub_82171C18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82171c18
	ctx.lr = 0x825F3620;
	sub_82171C18(ctx, base);
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lis r12,160
	r12.s64 = 10485760;
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// ori r12,r12,41120
	r12.u64 = r12.u64 | 41120;
	// lwzx r6,r9,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// and r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 & ctx.r6.u64;
	// and r4,r5,r12
	ctx.r4.u64 = ctx.r5.u64 & r12.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825f3664
	if (cr6.eq) goto loc_825F3664;
	// lwz r11,14328(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 14328);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x825f3664
	if (!cr6.lt) goto loc_825F3664;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x825f36b4
	goto loc_825F36B4;
loc_825F3664:
	// and r11,r29,r19
	r11.u64 = r29.u64 & r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,52(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 52);
	// beq cr6,0x825f3680
	if (cr6.eq) goto loc_825F3680;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x825f3688
	goto loc_825F3688;
loc_825F3680:
	// rlwinm r10,r31,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
loc_825F3688:
	// lvx128 v2,r9,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r24,16
	cr6.compare<int32_t>(r24.s32, 16, xer);
	// lvx128 v3,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x825f370c
	if (cr6.eq) goto loc_825F370C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82171e80
	ctx.lr = 0x825F36B0;
	sub_82171E80(ctx, base);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_825F36B4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x825f35ec
	if (cr6.lt) goto loc_825F35EC;
loc_825F36C0:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x825f370c
	if (!cr6.gt) goto loc_825F370C;
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// stw r24,276(r23)
	PPC_STORE_U32(r23.u32 + 276, r24.u32);
	// stw r18,268(r23)
	PPC_STORE_U32(r23.u32 + 268, r18.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f36e8
	if (cr6.eq) goto loc_825F36E8;
	// li r11,2
	r11.s64 = 2;
	// stw r11,272(r23)
	PPC_STORE_U32(r23.u32 + 272, r11.u32);
	// b 0x825f36ec
	goto loc_825F36EC;
loc_825F36E8:
	// stw r18,272(r23)
	PPC_STORE_U32(r23.u32 + 272, r18.u32);
loc_825F36EC:
	// stw r25,256(r23)
	PPC_STORE_U32(r23.u32 + 256, r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r11.u32);
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// lfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x823d9214
	return;
loc_825F370C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// lfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x823d9214
	return;
}

PPC_WEAK_FUNC(sub_825F32F8) {
	__imp__sub_825F32F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F371C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F371C) {
	__imp__sub_825F371C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3720) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x825F3728;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// lbz r10,10552(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10552);
	// mr r15,r7
	r15.u64 = ctx.r7.u64;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f3778
	if (cr6.eq) goto loc_825F3778;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x825f3778
	if (cr6.eq) goto loc_825F3778;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821716c0
	ctx.lr = 0x825F3768;
	sub_821716C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3778
	if (cr6.eq) goto loc_825F3778;
	// li r28,1
	r28.s64 = 1;
loc_825F3778:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ori r9,r10,57792
	ctx.r9.u64 = ctx.r10.u64 | 57792;
	// mullw r30,r20,r9
	r30.s64 = int64_t(r20.s32) * int64_t(ctx.r9.s32);
	// add. r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x825f3a28
	if (cr0.eq) goto loc_825F3A28;
	// lwz r27,16(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x825f3a28
	if (cr6.eq) goto loc_825F3A28;
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// li r9,64
	ctx.r9.s64 = 64;
	// dcbt r10,r9
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r8,52224
	ctx.r7.u64 = ctx.r8.u64 | 52224;
	// lwzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// subfic r17,r6,64
	xer.ca = ctx.r6.u32 <= 64;
	r17.s64 = 64 - ctx.r6.s64;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// beq cr6,0x825f3a28
	if (cr6.eq) goto loc_825F3A28;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r5,128
	ctx.r5.s64 = 128;
	// ori r31,r10,57696
	r31.u64 = ctx.r10.u64 | 57696;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82173728
	ctx.lr = 0x825F37DC;
	sub_82173728(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v63,r8,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,11364(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11364);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x825f3a28
	if (cr6.gt) goto loc_825F3A28;
	// clrlwi r18,r28,24
	r18.u64 = r28.u32 & 0xFF;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x825f3818
	if (cr6.eq) goto loc_825F3818;
	// mr r24,r15
	r24.u64 = r15.u64;
loc_825F3818:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r21,0
	r21.s64 = 0;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// lbz r10,10577(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10577);
	// beq cr6,0x825f3834
	if (cr6.eq) goto loc_825F3834;
	// lwz r27,4(r19)
	r27.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// b 0x825f3864
	goto loc_825F3864;
loc_825F3834:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3850
	if (cr6.eq) goto loc_825F3850;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x825f3854
	if (!cr6.eq) goto loc_825F3854;
loc_825F3850:
	// li r11,0
	r11.s64 = 0;
loc_825F3854:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3864
	if (cr6.eq) goto loc_825F3864;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_825F3864:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f3880
	if (cr6.eq) goto loc_825F3880;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x825f3884
	if (!cr6.eq) goto loc_825F3884;
loc_825F3880:
	// li r11,0
	r11.s64 = 0;
loc_825F3884:
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x825f39d8
	if (!cr6.gt) goto loc_825F39D8;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lis r25,1024
	r25.s64 = 67108864;
	// lis r23,4096
	r23.s64 = 268435456;
loc_825F38A4:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x825f38cc
	if (cr6.eq) goto loc_825F38CC;
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// b 0x825f3900
	goto loc_825F3900;
loc_825F38CC:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f38f8
	if (cr6.eq) goto loc_825F38F8;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x825f3900
	goto loc_825F3900;
loc_825F38F8:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// add r31,r28,r11
	r31.u64 = r28.u64 + r11.u64;
loc_825F3900:
	// dcbt r0,r31
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82175238
	ctx.lr = 0x825F3924;
	sub_82175238(ctx, base);
	// rlwinm r10,r3,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r10,r25
	cr6.compare<int32_t>(ctx.r10.s32, r25.s32, xer);
	// beq cr6,0x825f3940
	if (cr6.eq) goto loc_825F3940;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x825f3944
	if (!cr6.eq) goto loc_825F3944;
loc_825F3940:
	// li r11,0
	r11.s64 = 0;
loc_825F3944:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f39c4
	if (cr6.eq) goto loc_825F39C4;
	// li r8,5
	ctx.r8.s64 = 5;
	// mr r7,r16
	ctx.r7.u64 = r16.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825f32f8
	ctx.lr = 0x825F396C;
	sub_825F32F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f39c4
	if (cr6.eq) goto loc_825F39C4;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x825f39a8
	if (cr6.eq) goto loc_825F39A8;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x825f39a8
	if (!cr6.lt) goto loc_825F39A8;
	// lwz r10,8(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r24)
	PPC_STORE_U32(r24.u32 + 4, ctx.r8.u32);
loc_825F39A8:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r17,r17,-1
	r17.s64 = r17.s64 + -1;
	// cmpwi cr6,r21,5
	cr6.compare<int32_t>(r21.s32, 5, xer);
	// blt cr6,0x825f39bc
	if (cr6.lt) goto loc_825F39BC;
	// li r21,0
	r21.s64 = 0;
loc_825F39BC:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// beq cr6,0x825f39d8
	if (cr6.eq) goto loc_825F39D8;
loc_825F39C4:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r28,r28,80
	r28.s64 = r28.s64 + 80;
	// cmpw cr6,r26,r27
	cr6.compare<int32_t>(r26.s32, r27.s32, xer);
	// blt cr6,0x825f38a4
	if (cr6.lt) goto loc_825F38A4;
loc_825F39D8:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x825f39e8
	if (cr6.eq) goto loc_825F39E8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82171750
	ctx.lr = 0x825F39E8;
	sub_82171750(ctx, base);
loc_825F39E8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,10544(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10544);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f3a28
	if (cr6.eq) goto loc_825F3A28;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// beq cr6,0x825f3a1c
	if (cr6.eq) goto loc_825F3A1C;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// bl 0x82172d08
	ctx.lr = 0x825F3A14;
	sub_82172D08(ctx, base);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9214
	return;
loc_825F3A1C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82172d08
	ctx.lr = 0x825F3A28;
	sub_82172D08(ctx, base);
loc_825F3A28:
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9214
	return;
}

PPC_WEAK_FUNC(sub_825F3720) {
	__imp__sub_825F3720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3A30) {
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
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x823dba38
	ctx.lr = 0x825F3A58;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f3a88
	if (cr6.lt) goto loc_825F3A88;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x825f3a8c
	if (!cr6.gt) goto loc_825F3A8C;
loc_825F3A88:
	// li r11,0
	r11.s64 = 0;
loc_825F3A8C:
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

PPC_WEAK_FUNC(sub_825F3A30) {
	__imp__sub_825F3A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3AA8) {
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
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x823dba38
	ctx.lr = 0x825F3AD0;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f3b00
	if (cr6.lt) goto loc_825F3B00;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x825f3b04
	if (!cr6.gt) goto loc_825F3B04;
loc_825F3B00:
	// li r11,0
	r11.s64 = 0;
loc_825F3B04:
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

PPC_WEAK_FUNC(sub_825F3AA8) {
	__imp__sub_825F3AA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f0,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f13,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r4,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r4.u64);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f11,-8(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// extsw r7,r6
	ctx.r7.s64 = ctx.r6.s32;
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// std r7,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r7.u64);
	// lfd f9,-8(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// mullw r4,r6,r5
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f12,f4,f13
	ctx.f12.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fmuls f9,f1,f13
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f9,36(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fmuls f11,f3,f0
	ctx.f11.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// fmuls f10,f2,f0
	ctx.f10.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f10,24(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F3B20) {
	__imp__sub_825F3B20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F3BCC) {
	__imp__sub_825F3BCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3BD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6624);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F3BD0) {
	__imp__sub_825F3BD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F3BDC) {
	__imp__sub_825F3BDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3BE0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x823dba38
	ctx.lr = 0x825F3C08;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x825f3c34
	if (!cr6.lt) goto loc_825F3C34;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x825f3c48
	goto loc_825F3C48;
loc_825F3C34:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x825f3c44
	if (!cr6.gt) goto loc_825F3C44;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x825f3c48
	goto loc_825F3C48;
loc_825F3C44:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_825F3C48:
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

PPC_WEAK_FUNC(sub_825F3BE0) {
	__imp__sub_825F3BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3C60) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x823dba38
	ctx.lr = 0x825F3C88;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x825f3cb4
	if (!cr6.lt) goto loc_825F3CB4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x825f3cc8
	goto loc_825F3CC8;
loc_825F3CB4:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x825f3cc4
	if (!cr6.gt) goto loc_825F3CC4;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x825f3cc8
	goto loc_825F3CC8;
loc_825F3CC4:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_825F3CC8:
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

PPC_WEAK_FUNC(sub_825F3C60) {
	__imp__sub_825F3C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// li r11,0
	r11.s64 = 0;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x825f3be0
	ctx.lr = 0x825F3D18;
	sub_825F3BE0(ctx, base);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825f3c60
	ctx.lr = 0x825F3D28;
	sub_825F3C60(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// subf r4,r7,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r7.s64;
	// mullw r3,r4,r5
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// subf r11,r9,r3
	r11.s64 = ctx.r3.s64 - ctx.r9.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
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

PPC_WEAK_FUNC(sub_825F3CE0) {
	__imp__sub_825F3CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F3D74) {
	__imp__sub_825F3D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3D78) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,24532
	ctx.r7.s64 = ctx.r8.s64 + 24532;
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x825f3b20
	ctx.lr = 0x825F3DD4;
	sub_825F3B20(ctx, base);
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

PPC_WEAK_FUNC(sub_825F3D78) {
	__imp__sub_825F3D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3DE8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x825F3DFC;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f29,f2
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f2.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f27,f5
	f27.f64 = ctx.f5.f64;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fdivs f0,f31,f3
	f0.f64 = double(float(f31.f64 / ctx.f3.f64));
	// stfs f3,40(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// fdivs f13,f31,f6
	ctx.f13.f64 = double(float(f31.f64 / ctx.f6.f64));
	// stfs f6,44(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f30,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f30.f64 = double(temp.f32);
	// fmsubs f1,f0,f1,f30
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64 - f30.f64));
	// bl 0x823dba38
	ctx.lr = 0x825F3E40;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// li r9,8
	ctx.r9.s64 = 8;
	// lfs f11,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f1,f11,f29,f30
	ctx.f1.f64 = double(float(ctx.f11.f64 * f29.f64 + f30.f64));
	// fctiwz f10,f12
	ctx.f10.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f10,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.f10.u32);
	// bl 0x823dba38
	ctx.lr = 0x825F3E5C;
	sub_823DBA38(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// li r8,12
	ctx.r8.s64 = 12;
	// lfs f8,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// fmsubs f1,f8,f28,f30
	ctx.f1.f64 = double(float(ctx.f8.f64 * f28.f64 - f30.f64));
	// fctiwz f7,f9
	ctx.f7.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfiwx f7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.f7.u32);
	// bl 0x823dba38
	ctx.lr = 0x825F3E78;
	sub_823DBA38(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f5,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f5,f27,f30
	ctx.f1.f64 = double(float(ctx.f5.f64 * f27.f64 + f30.f64));
	// fctiwz f4,f6
	ctx.f4.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfiwx f4,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.f4.u32);
	// bl 0x823dba38
	ctx.lr = 0x825F3E94;
	sub_823DBA38(ctx, base);
	// frsp f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f1.f64));
	// li r6,20
	ctx.r6.s64 = 20;
	// lfs f2,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// fdivs f0,f31,f2
	f0.f64 = double(float(f31.f64 / ctx.f2.f64));
	// fdivs f13,f31,f1
	ctx.f13.f64 = double(float(f31.f64 / ctx.f1.f64));
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fctiwz f12,f3
	ctx.f12.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfiwx f12,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.f12.u32);
	// bl 0x825f3b20
	ctx.lr = 0x825F3EC4;
	sub_825F3B20(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x825F3ED0;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F3DE8) {
	__imp__sub_825F3DE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3EE0) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r3,6628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6628);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f3f14
	if (cr6.eq) goto loc_825F3F14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F3F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F3F14:
	// li r11,0
	r11.s64 = 0;
	// stw r11,6628(r31)
	PPC_STORE_U32(r31.u32 + 6628, r11.u32);
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

PPC_WEAK_FUNC(sub_825F3EE0) {
	__imp__sub_825F3EE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3F30) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,24820
	ctx.r10.s64 = r11.s64 + 24820;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x825F3F5C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f3f74
	if (cr6.eq) goto loc_825F3F74;
	// bl 0x82130588
	ctx.lr = 0x825F3F70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825F3F74:
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

PPC_WEAK_FUNC(sub_825F3F30) {
	__imp__sub_825F3F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F3F8C) {
	__imp__sub_825F3F8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F3F90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x825F3F98;
	// li r10,768
	ctx.r10.s64 = 768;
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r9,784
	ctx.r9.s64 = 784;
	// lfs f13,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r6,r1,-80
	ctx.r6.s64 = ctx.r1.s64 + -80;
	// li r11,800
	r11.s64 = 800;
	// lvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,-128
	ctx.r3.s64 = ctx.r1.s64 + -128;
	// vxor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_setzero_si128());
	// lvx128 v62,r4,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v58,v62,v62
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_setzero_si128());
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// lvx128 v61,r4,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// vsubfp128 v56,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// vxor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_setzero_si128());
	// vsubfp128 v55,v58,v62
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// addi r4,r1,-96
	ctx.r4.s64 = ctx.r1.s64 + -96;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// addi r31,r1,-64
	r31.s64 = ctx.r1.s64 + -64;
	// vsubfp128 v57,v60,v61
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,-128
	ctx.r4.s64 = ctx.r1.s64 + -128;
	// addi r30,r1,-48
	r30.s64 = ctx.r1.s64 + -48;
	// lis r29,-32256
	r29.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-76(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f6.f64 = double(temp.f32);
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f3.f64 = double(temp.f32);
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f6,-128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -128, temp.u32);
	// stfs f8,-124(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -124, temp.u32);
	// stfs f7,-120(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -120, temp.u32);
	// lfs f10,-60(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-56(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -56);
	ctx.f9.f64 = double(temp.f32);
	// lfs f2,-64(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f2.f64 = double(temp.f32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f5,-112(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f4,-108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f3,-104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f9,-88(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// lfs f9,-60(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	ctx.f9.f64 = double(temp.f32);
	// stfs f2,-96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f10,-92(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// lfs f1,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f1.f64 = double(temp.f32);
	// lfs f6,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,-64(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,-56(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -56);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f13,f7,f8
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f8.f64));
	// lfs f7,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f12,f0,f1
	ctx.f12.f64 = double(float(f0.f64 * ctx.f1.f64));
	// fmuls f5,f0,f6
	ctx.f5.f64 = double(float(f0.f64 * ctx.f6.f64));
	// lfs f0,3796(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f6,f11,f4,f9
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f4.f64 + ctx.f9.f64));
	// fmadds f1,f13,f2,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f12.f64));
	// fmadds f8,f13,f3,f5
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f5.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// fmadds f12,f11,f10,f1
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f1.f64));
	// fmadds f13,f11,f7,f8
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 + ctx.f8.f64));
	// ble cr6,0x825f4104
	if (!cr6.gt) goto loc_825F4104;
	// lvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-48
	r11.s64 = ctx.r1.s64 + -48;
	// vmsum3fp128 v53,v63,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// lfs f11,-116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -116);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fcmpu cr6,f8,f10
	cr6.compare(ctx.f8.f64, ctx.f10.f64);
	// ble cr6,0x825f4104
	if (!cr6.gt) goto loc_825F4104;
	// li r3,8
	ctx.r3.s64 = 8;
loc_825F4104:
	// rlwinm r10,r3,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f4184
	if (!cr6.eq) goto loc_825F4184;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x825f414c
	if (!cr6.gt) goto loc_825F414C;
	// lvx128 v52,r0,r5
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-48
	ctx.r10.s64 = ctx.r1.s64 + -48;
	// vmsum3fp128 v51,v62,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// lfs f13,-100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fcmpu cr6,f9,f11
	cr6.compare(ctx.f9.f64, ctx.f11.f64);
	// ble cr6,0x825f414c
	if (!cr6.gt) goto loc_825F414C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// ori r3,r11,2
	ctx.r3.u64 = r11.u64 | 2;
loc_825F414C:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x825f4184
	if (!cr6.gt) goto loc_825F4184;
	// lvx128 v50,r0,r5
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-48
	r11.s64 = ctx.r1.s64 + -48;
	// vmsum3fp128 v49,v61,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// lfs f0,-84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -84);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x825f4184
	if (!cr6.gt) goto loc_825F4184;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// ori r3,r11,4
	ctx.r3.u64 = r11.u64 | 4;
loc_825F4184:
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F3F90) {
	__imp__sub_825F3F90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4188) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x825F4190;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,496
	ctx.r5.s64 = 496;
	// li r6,480
	ctx.r6.s64 = 480;
	// li r29,16
	r29.s64 = 16;
	// li r7,464
	ctx.r7.s64 = 464;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r28,32
	r28.s64 = 32;
	// lwz r30,336(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r8,512
	ctx.r8.s64 = 512;
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// li r27,48
	r27.s64 = 48;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r9,448
	ctx.r9.s64 = 448;
	// li r26,64
	r26.s64 = 64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// lvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,80
	r25.s64 = 80;
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,336(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r24,96
	r24.s64 = 96;
	// stvx128 v62,r30,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,336(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r23,112
	r23.s64 = 112;
	// stvx128 v61,r30,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,336(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,128
	r29.s64 = 128;
	// stvx128 v60,r30,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,336(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,112
	r11.s64 = ctx.r4.s64 + 112;
	// stvx128 v59,r30,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v58,r10,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,144
	r28.s64 = 144;
	// stvx128 v58,r4,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v57,r10,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,160
	r30.s64 = 160;
	// stvx128 v57,r4,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v56,r10,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,176
	r27.s64 = 176;
	// stvx128 v56,r4,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v55,r10,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,192
	r26.s64 = 192;
	// stvx128 v55,r4,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v54,r10,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// stvx128 v54,r4,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v53,r11,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,208
	r25.s64 = 208;
	// stvx128 v53,r4,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v52,r11,r6
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,224
	r29.s64 = 224;
	// stvx128 v52,r3,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v51,r11,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,240
	ctx.r4.s64 = 240;
	// stvx128 v51,r3,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v50,r11,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,256
	r30.s64 = 256;
	// stvx128 v50,r3,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v49,r11,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,272
	r28.s64 = 272;
	// stvx128 v49,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v48,r10,r5
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,336(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v47,r10,r6
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,288
	ctx.r3.s64 = 288;
	// stvx128 v47,r5,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lvx128 v46,r10,r7
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,304
	r11.s64 = 304;
	// stvx128 v46,r4,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r10,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,336(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// stvx128 v45,r8,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r10,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,336(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// stvx128 v44,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,336(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,288(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 288);
	f0.f64 = double(temp.f32);
	// lfs f13,272(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lfs f12,256(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 256);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,240(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 240);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,360(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 360, temp.u32);
	// stfs f12,356(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// stfs f0,364(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 364, temp.u32);
	// stfs f11,352(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lfs f9,244(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 244);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,276(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 276);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,292(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 292);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,260(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 260);
	ctx.f10.f64 = double(temp.f32);
	// stfs f9,368(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f7,380(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// stfs f10,372(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// stfs f8,376(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// lfs f6,296(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 296);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,280(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 280);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,248(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 248);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,264(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 264);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,388(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// stfs f3,384(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// stfs f4,392(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// stfs f6,396(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// lfs f2,300(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 300);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,252(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 252);
	f0.f64 = double(temp.f32);
	// lfs f13,268(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,284(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 284);
	ctx.f1.f64 = double(temp.f32);
	// stfs f0,400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f2,412(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 412, temp.u32);
	// stfs f13,404(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// stfs f1,408(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 408, temp.u32);
	// lfs f12,192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,160(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 160);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,208(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 208);
	ctx.f10.f64 = double(temp.f32);
	// stfs f9,416(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 416, temp.u32);
	// stfs f11,420(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 420, temp.u32);
	// stfs f12,424(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 424, temp.u32);
	// stfs f10,428(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 428, temp.u32);
	// lfs f8,212(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 212);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,180(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 180);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,164(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 164);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,196(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 196);
	ctx.f7.f64 = double(temp.f32);
	// stfs f5,432(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
	// stfs f6,436(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 436, temp.u32);
	// stfs f7,440(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 440, temp.u32);
	// stfs f8,444(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 444, temp.u32);
	// lfs f4,184(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 184);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,216(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 216);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,200(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 200);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,168(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,448(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 448, temp.u32);
	// stfs f2,456(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
	// stfs f3,460(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 460, temp.u32);
	// stfs f4,452(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// lfs f0,220(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 220);
	f0.f64 = double(temp.f32);
	// lfs f13,172(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,204(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 204);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,188(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 188);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,464(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 464, temp.u32);
	// stfs f11,468(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 468, temp.u32);
	// stfs f12,472(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// stfs f0,476(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// lfs f10,112(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,128(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,96(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,484(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// stfs f8,492(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stfs f9,480(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// stfs f10,488(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// lfs f5,116(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,84(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,132(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	ctx.f3.f64 = double(temp.f32);
	// lfs f6,100(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	ctx.f6.f64 = double(temp.f32);
	// stfs f4,496(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stfs f6,500(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stfs f5,504(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// stfs f3,508(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 508, temp.u32);
	// lfs f1,136(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 136);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,104(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f2,120(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 120);
	ctx.f2.f64 = double(temp.f32);
	// lfs f13,88(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,512(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stfs f0,516(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// stfs f2,520(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// stfs f1,524(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 524, temp.u32);
	// lfs f11,124(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,92(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,140(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,108(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// stfs f10,528(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stfs f9,532(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stfs f11,536(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// stfs f12,540(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 540, temp.u32);
	// lfs f8,48(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f5,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f6.f64 = double(temp.f32);
	// stfs f5,544(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 544, temp.u32);
	// stfs f7,548(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// stfs f6,552(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 552, temp.u32);
	// stfs f8,556(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 556, temp.u32);
	// lfs f4,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,52(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// stfs f1,560(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 560, temp.u32);
	// stfs f3,564(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 564, temp.u32);
	// stfs f4,568(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 568, temp.u32);
	// stfs f2,572(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// lfs f0,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f12,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f11,576(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// stfs f13,580(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stfs f0,584(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// stfs f12,588(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// lfs f10,60(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,44(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,592(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// stfs f8,596(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// stfs f9,600(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f10,604(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 604, temp.u32);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_825F4188) {
	__imp__sub_825F4188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F4514) {
	__imp__sub_825F4514(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4518) {
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
	// li r3,608
	ctx.r3.s64 = 608;
	// bl 0x82130528
	ctx.lr = 0x825F452C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// beq cr6,0x825f4560
	if (cr6.eq) goto loc_825F4560;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// addi r9,r11,24820
	ctx.r9.s64 = r11.s64 + 24820;
	// stw r8,336(r3)
	PPC_STORE_U32(ctx.r3.u32 + 336, ctx.r8.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r3,6628(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6628, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_825F4560:
	// li r11,0
	r11.s64 = 0;
	// stw r11,6628(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6628, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F4518) {
	__imp__sub_825F4518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4578) {
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
	// li r3,68
	ctx.r3.s64 = 68;
	// bl 0x82130528
	ctx.lr = 0x825F458C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x825f45d8
	if (cr6.eq) goto loc_825F45D8;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// addi r8,r10,25108
	ctx.r8.s64 = ctx.r10.s64 + 25108;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r3,6632(r9)
	PPC_STORE_U32(ctx.r9.u32 + 6632, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_825F45D8:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,6632(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6632, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F4578) {
	__imp__sub_825F4578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F45F0) {
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
	ctx.lr = 0x825F45F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// beq cr6,0x825f461c
	if (cr6.eq) goto loc_825F461C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x825F461C;
	sub_821CA540(ctx, base);
loc_825F461C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r28,r10,25156
	r28.s64 = ctx.r10.s64 + 25156;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825F4648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F467C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825f468c
	if (cr6.eq) goto loc_825F468C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x825F468C;
	sub_821C9A90(ctx, base);
loc_825F468C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F46A4;
	sub_8218B688(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,25148
	ctx.r4.s64 = ctx.r9.s64 + 25148;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F46C0;
	sub_8218B688(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,25140
	ctx.r4.s64 = ctx.r6.s64 + 25140;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F46DC;
	sub_8218B688(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,25132
	ctx.r4.s64 = ctx.r4.s64 + 25132;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F46F8;
	sub_8218B688(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,25124
	ctx.r4.s64 = ctx.r10.s64 + 25124;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F4714;
	sub_8218B688(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,25112
	ctx.r4.s64 = ctx.r9.s64 + 25112;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x825F4730;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,14124
	ctx.r3.s64 = ctx.r7.s64 + 14124;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4744;
	sub_8218A4E8(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F45F0) {
	__imp__sub_825F45F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4750) {
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
	ctx.lr = 0x825F4758;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// bl 0x82180430
	ctx.lr = 0x825F4784;
	sub_82180430(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// stb r28,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r28.u8);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// stb r25,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r25.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825f47a4
	if (!cr6.eq) goto loc_825F47A4;
	// stb r11,145(r1)
	PPC_STORE_U8(ctx.r1.u32 + 145, r11.u8);
loc_825F47A4:
	// addi r10,r30,-1
	ctx.r10.s64 = r30.s64 + -1;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// stb r11,146(r1)
	PPC_STORE_U8(ctx.r1.u32 + 146, r11.u8);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r25,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r25.u32);
	// rlwinm r24,r9,27,31,31
	r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r24,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r24.u8);
	// bge cr6,0x825f47ec
	if (!cr6.lt) goto loc_825F47EC;
	// bl 0x821789d8
	ctx.lr = 0x825F47CC;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f47e4
	if (cr6.eq) goto loc_825F47E4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17004(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x825f47ec
	goto loc_825F47EC;
loc_825F47E4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17012(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_825F47EC:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bge cr6,0x825f4818
	if (!cr6.lt) goto loc_825F4818;
	// bl 0x821789d8
	ctx.lr = 0x825F47F8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4810
	if (cr6.eq) goto loc_825F4810;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r27,17008(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x825f4818
	goto loc_825F4818;
loc_825F4810:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r27,17016(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_825F4818:
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,25200
	ctx.r4.s64 = r11.s64 + 25200;
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F484C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x825F485C;
	sub_82180430(ctx, base);
	// addi r10,r30,-1
	ctx.r10.s64 = r30.s64 + -1;
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, ctx.r8.u8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// beq cr6,0x825f4884
	if (cr6.eq) goto loc_825F4884;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
loc_825F4884:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// stb r24,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r24.u8);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// beq cr6,0x825f48a8
	if (cr6.eq) goto loc_825F48A8;
	// li r11,13
	r11.s64 = 13;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
loc_825F48A8:
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25180
	ctx.r4.s64 = r11.s64 + 25180;
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F48D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_825F4750) {
	__imp__sub_825F4750(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F48E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F48E4) {
	__imp__sub_825F48E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F48E8) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82178f38
	ctx.lr = 0x825F490C;
	sub_82178F38(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x825f4990
	if (cr6.gt) goto loc_825F4990;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4990
	if (cr6.eq) goto loc_825F4990;
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4960
	if (cr6.eq) goto loc_825F4960;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8217a470
	ctx.lr = 0x825F494C;
	sub_8217A470(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c658
	ctx.lr = 0x825F495C;
	sub_8217C658(ctx, base);
	// b 0x825f4990
	goto loc_825F4990;
loc_825F4960:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F4990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F4990:
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

PPC_WEAK_FUNC(sub_825F48E8) {
	__imp__sub_825F48E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F49A8) {
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
	ctx.lr = 0x825F49B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82178f38
	ctx.lr = 0x825F49C8;
	sub_82178F38(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x825f4a24
	if (cr6.gt) goto loc_825F4A24;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4a24
	if (cr6.eq) goto loc_825F4A24;
	// lbz r11,56(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f49f8
	if (cr6.eq) goto loc_825F49F8;
	// bl 0x8217b430
	ctx.lr = 0x825F49F0;
	sub_8217B430(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_825F49F8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825F4A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_825F4A24:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f4a38
	if (cr6.eq) goto loc_825F4A38;
	// lbz r11,23(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4a48
	if (cr6.eq) goto loc_825F4A48;
loc_825F4A38:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82178f70
	ctx.lr = 0x825F4A48;
	sub_82178F70(ctx, base);
loc_825F4A48:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F49A8) {
	__imp__sub_825F49A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4A50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,60(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// b 0x8218ae48
	sub_8218AE48(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F4A50) {
	__imp__sub_825F4A50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4A68) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F4A68) {
	__imp__sub_825F4A68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F4A6C) {
	__imp__sub_825F4A6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x825F4A88;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x825F4ABC;
	sub_82189CE0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmr f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f28.f64;
	// li r11,-1
	r11.s64 = -1;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f7,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// bl 0x82194b58
	ctx.lr = 0x825F4B00;
	sub_82194B58(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x825F4B1C;
	sub_82189CE0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x825F4B28;
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

PPC_WEAK_FUNC(sub_825F4A70) {
	__imp__sub_825F4A70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F4B3C) {
	__imp__sub_825F4B3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4B40) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,25108
	ctx.r10.s64 = r11.s64 + 25108;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f4b88
	if (cr6.eq) goto loc_825F4B88;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F4B88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F4B88:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x825F4B90;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f4ba8
	if (cr6.eq) goto loc_825F4BA8;
	// bl 0x82130588
	ctx.lr = 0x825F4BA4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825F4BA8:
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

PPC_WEAK_FUNC(sub_825F4B40) {
	__imp__sub_825F4B40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lbz r11,40(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x825f4c24
	if (cr6.gt) {
		sub_825F4C24(ctx, base);
		return;
	}
	// lis r12,-32161
	r12.s64 = -2107703296;
	// addi r12,r12,19444
	r12.s64 = r12.s64 + 19444;
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

PPC_WEAK_FUNC(sub_825F4BC0) {
	__imp__sub_825F4BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4BF4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r18{};
	PPCRegister r31{};
	// lwz r18,19460(r31)
	r18.u64 = PPC_LOAD_U32(r31.u32 + 19460);
	// lwz r18,19468(r31)
	r18.u64 = PPC_LOAD_U32(r31.u32 + 19468);
	// lwz r18,19476(r31)
	r18.u64 = PPC_LOAD_U32(r31.u32 + 19476);
	// lwz r18,19484(r31)
	r18.u64 = PPC_LOAD_U32(r31.u32 + 19484);
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// b 0x825f4c28
	// ERROR 825F4C28
	return;
}

PPC_WEAK_FUNC(sub_825F4BF4) {
	__imp__sub_825F4BF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C0C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// b 0x825f4c28
	// ERROR 825F4C28
	return;
}

PPC_WEAK_FUNC(sub_825F4C0C) {
	__imp__sub_825F4C0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C14) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,20
	r11.s64 = ctx.r3.s64 + 20;
	// b 0x825f4c28
	// ERROR 825F4C28
	return;
}

PPC_WEAK_FUNC(sub_825F4C14) {
	__imp__sub_825F4C14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C1C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// b 0x825f4c28
	// ERROR 825F4C28
	return;
}

PPC_WEAK_FUNC(sub_825F4C1C) {
	__imp__sub_825F4C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C24) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r4,60(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f4,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// b 0x825f4a70
	sub_825F4A70(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F4C24) {
	__imp__sub_825F4C24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C4C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F4C4C) {
	__imp__sub_825F4C4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// li r4,16
	ctx.r4.s64 = 16;
	// vpermwi128 v58,v62,171
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// lfs f12,32312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32312);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f11,31332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31332);
	ctx.f11.f64 = double(temp.f32);
	// li r9,32
	ctx.r9.s64 = 32;
	// stfs f0,92(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// fmadds f9,f10,f13,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f13.f64));
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f10,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// stw r10,832(r3)
	PPC_STORE_U32(ctx.r3.u32 + 832, ctx.r10.u32);
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f12,108(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f11,840(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 840, temp.u32);
	// stfs f10,88(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f13,100(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f9,84(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F4C50) {
	__imp__sub_825F4C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F4D04) {
	__imp__sub_825F4D04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4D08) {
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
	ctx.lr = 0x825F4D10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// beq cr6,0x825f4d34
	if (cr6.eq) goto loc_825F4D34;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x825F4D34;
	sub_821CA540(ctx, base);
loc_825F4D34:
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r26,r11,26064
	r26.s64 = r11.s64 + 26064;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -24728);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825F4D60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F4D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -24728);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r27,r10,26044
	r27.s64 = ctx.r10.s64 + 26044;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825F4DC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F4DF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825f4e04
	if (cr6.eq) goto loc_825F4E04;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x825F4E04;
	sub_821C9A90(ctx, base);
loc_825F4E04:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F4E1C;
	sub_8218B688(ctx, base);
	// stw r3,616(r31)
	PPC_STORE_U32(r31.u32 + 616, ctx.r3.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,26032
	ctx.r4.s64 = ctx.r9.s64 + 26032;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x825F4E38;
	sub_8218B688(ctx, base);
	// stw r3,620(r31)
	PPC_STORE_U32(r31.u32 + 620, ctx.r3.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,40
	ctx.r3.s64 = ctx.r7.s64 + 40;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4E4C;
	sub_8218A4E8(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r6,24
	ctx.r3.s64 = ctx.r6.s64 + 24;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4E60;
	sub_8218A4E8(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r5,0
	ctx.r3.s64 = ctx.r5.s64 + 0;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4E74;
	sub_8218A4E8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lis r3,-32248
	ctx.r3.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,26016
	ctx.r3.s64 = ctx.r3.s64 + 26016;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4E88;
	sub_8218A4E8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,26000
	ctx.r3.s64 = r11.s64 + 26000;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4E9C;
	sub_8218A4E8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,25988
	ctx.r3.s64 = ctx.r10.s64 + 25988;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4EB0;
	sub_8218A4E8(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r9,25976
	ctx.r3.s64 = ctx.r9.s64 + 25976;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4EC4;
	sub_8218A4E8(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r8,25968
	ctx.r3.s64 = ctx.r8.s64 + 25968;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4ED8;
	sub_8218A4E8(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,25956
	ctx.r3.s64 = ctx.r7.s64 + 25956;
	// bl 0x8218a4e8
	ctx.lr = 0x825F4EEC;
	sub_8218A4E8(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825F4D08) {
	__imp__sub_825F4D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x825F4F1C;
	sub_82180430(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// li r9,4
	ctx.r9.s64 = 4;
	// stb r10,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, ctx.r10.u8);
	// addi r4,r6,26084
	ctx.r4.s64 = ctx.r6.s64 + 26084;
	// lwz r3,-25232(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25232);
	// li r8,15
	ctx.r8.s64 = 15;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,5
	ctx.r5.s64 = 5;
	// lwz r6,592(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// lwz r7,596(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// lwz r10,600(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// rlwinm r11,r6,28,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0x7FFFFFF;
	// rlwinm r30,r7,29,4,31
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0xFFFFFFF;
	// mullw r11,r30,r11
	r11.s64 = int64_t(r30.s32) * int64_t(r11.s32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// subfic r10,r11,3600
	xer.ca = r11.u32 <= 3600;
	ctx.r10.s64 = 3600 - r11.s64;
	// subfe r11,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r11,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r11.u8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F4F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,608(r31)
	PPC_STORE_U32(r31.u32 + 608, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_825F4EF8) {
	__imp__sub_825F4EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F4FB8) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x825F4FC0;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dd52c
	ctx.lr = 0x825F4FD4;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// vspltisw128 v125,0
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lvx128 v124,r0,r5
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lfs f13,164(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lvx128 v63,r5,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lfs f12,696(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 696);
	ctx.f12.f64 = double(temp.f32);
	// vsubfp128 v127,v125,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v63.f32)));
	// fmuls f11,f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lvx128 v126,r5,r8
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r5,r7
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f31,f10,f1
	f31.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// bl 0x82171600
	ctx.lr = 0x825F5038;
	sub_82171600(ctx, base);
	// fmuls f9,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64 * f31.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,27644(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f31,f31,f0
	f31.f64 = double(float(f31.f64 * f0.f64));
	// fmuls f30,f9,f0
	f30.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbf10
	ctx.lr = 0x825F5054;
	sub_823DBF10(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbf10
	ctx.lr = 0x825F5060;
	sub_823DBF10(ctx, base);
	// lfs f8,160(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f8.f64 = double(temp.f32);
	// frsp f7,f1
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lfs f6,80(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmuls f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// lfs f4,168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,84(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f3.f64));
	// fmuls f0,f5,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// fmuls f13,f2,f29
	ctx.f13.f64 = double(float(ctx.f2.f64 * f29.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmuls f12,f0,f7
	ctx.f12.f64 = double(float(f0.f64 * ctx.f7.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x823dbf10
	ctx.lr = 0x825F5098;
	sub_823DBF10(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbf10
	ctx.lr = 0x825F50A4;
	sub_823DBF10(ctx, base);
	// lfs f11,160(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lfs f10,80(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lfs f9,168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// lfs f7,84(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stvx128 v126,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f5,f11,f7
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// lfs f4,160(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f4.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f3,80(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f3.f64 = double(temp.f32);
	// vsubfp128 v62,v125,v123
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v123.f32)));
	// lfs f2,168(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// lvlx128 v61,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f13,f1,f4
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f4.f64));
	// lvlx128 v60,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f12,f5,f30
	ctx.f12.f64 = double(float(ctx.f5.f64 * f30.f64));
	// lvlx128 v57,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmuls f0,f8,f9
	f0.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// vmulfp128 v56,v124,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v59.f32)));
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// vmulfp128 v55,v124,v58
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v0,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f11,f0,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(f0.f64 * ctx.f6.f64));
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v53,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// vmaddcfp128 v0,v127,v0,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(v126.f32)));
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// lvlx128 v51,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r31,32
	ctx.r9.s64 = r31.s64 + 32;
	// vsubfp128 v54,v125,v56
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v56.f32)));
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// stvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,48
	ctx.r8.s64 = r31.s64 + 48;
	// lfs f10,100(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// fneg f9,f10
	ctx.f9.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmulfp128 v49,v62,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v52.f32)));
	// lvlx128 v45,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v44,v45,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vmaddfp128 v0,v127,v44,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r5,r31,112
	ctx.r5.s64 = r31.s64 + 112;
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vsubfp128 v46,v125,v49
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v48,v125,v55
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v55.f32)));
	// vmulfp128 v47,v62,v50
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,84(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,160(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vsubfp128 v53,v125,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v47.f32)));
	// lvlx128 v43,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v43,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// vmaddcfp128 v0,v127,v0,v126
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(v126.f32)));
	// stvx128 v0,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,100(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 100);
	ctx.f5.f64 = double(temp.f32);
	// fneg f4,f5
	ctx.f4.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v42,r0,r26
	temp.u32 = r26.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v41,v42,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vmaddfp128 v0,v127,v41,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v41.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r28
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v32,v40,v40
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// stvx128 v40,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v32,v54
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v54.f32)));
	// lvx128 v39,r0,r27
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r28
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v63,v49
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r0,r27
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r28
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r0,r27
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r28
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r0,r27
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v56
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v56.f32)));
	// vor128 v59,v60,v60
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v49
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v57,v56
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vor128 v52,v56,v56
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v51,v52,v46
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v49,v50,v54
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v45,v49,v49
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vaddfp128 v44,v45,v46
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v44,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v42,v43,v48
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v48.f32)));
	// vor128 v41,v42,v42
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v40,v41,v47
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v38,v39,v55
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v55.f32)));
	// vor128 v37,v38,v38
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// stvx128 v38,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v36,v37,v47
	simde_mm_store_ps(v36.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v36,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r0,r6
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v34,v35,v55
	simde_mm_store_ps(v34.f32, simde_mm_add_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v55.f32)));
	// vor128 v33,v34,v34
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_load_si128((simde__m128i*)v34.u8));
	// stvx128 v34,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v32,v33,v53
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v32,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v63,v48
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v48.f32)));
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v53
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dd7c4
	ctx.lr = 0x825F52E0;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_825F4FB8) {
	__imp__sub_825F4FB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F52F0) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x825F52F8;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f1,840(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 840);
	ctx.f1.f64 = double(temp.f32);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x825f4fb8
	ctx.lr = 0x825F532C;
	sub_825F4FB8(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v52,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// lvx128 v0,r29,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v51,v63,v59
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v50,v0,v60
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// vmsum3fp128 v49,v0,v59
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r29,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v48,v63,v61
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v47,v62,v60
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v46,v62,v59
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// vmsum3fp128 v45,v0,v61
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v44,v0,v58
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// vmsum3fp128 v43,v63,v58
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// vmsum3fp128 v42,v62,v61
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// li r10,48
	ctx.r10.s64 = 48;
	// vmsum3fp128 v41,v0,v57
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// vmsum3fp128 v40,v63,v57
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// vmsum3fp128 v39,v62,v58
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v32,v62,v57
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v0,v56
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// lvx128 v53,r29,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v63,v56
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmrghw128 v38,v52,v50
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v57,v62,v56
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmrghw128 v37,v51,v49
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v36,v47,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v34,v48,v45
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// addi r28,r1,176
	r28.s64 = ctx.r1.s64 + 176;
	// vmrghw128 v35,v46,v37
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// addi r27,r1,192
	r27.s64 = ctx.r1.s64 + 192;
	// vmrghw128 v33,v43,v44
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// li r10,2
	ctx.r10.s64 = 2;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v38,v36
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v58,v37,v35
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmsum3fp128 v52,v0,v55
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrghw128 v56,v42,v34
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmsum3fp128 v50,v63,v55
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrghw128 v51,v40,v41
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmsum3fp128 v48,v62,v55
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrghw128 v49,v39,v33
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmsum3fp128 v47,v0,v54
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v46,v63,v54
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v44,v59,v61
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum3fp128 v45,v62,v54
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v43,v50,v52
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v41,v32,v51
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vmrghw128 v61,v34,v56
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// vmrghw128 v40,v57,v44
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// vmrghw128 v39,v48,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// vmrghw128 v37,v33,v49
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v36,v51,v41
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// stvx128 v58,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v35,v44,v40
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v34,v43,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// vmrghw128 v42,v46,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v45,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// stvx128 v36,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v33,v42,v38
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v33,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825F54D8:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f6
	cr6.compare(ctx.f12.f64, ctx.f6.f64);
	// bge cr6,0x825f54e8
	if (!cr6.lt) goto loc_825F54E8;
	// fmr f6,f12
	ctx.f6.f64 = ctx.f12.f64;
loc_825F54E8:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x825f54f8
	if (!cr6.lt) goto loc_825F54F8;
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
loc_825F54F8:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x825f5508
	if (!cr6.lt) goto loc_825F5508;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_825F5508:
	// fcmpu cr6,f12,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// ble cr6,0x825f5514
	if (!cr6.gt) goto loc_825F5514;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_825F5514:
	// fcmpu cr6,f13,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x825f5520
	if (!cr6.gt) goto loc_825F5520;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
loc_825F5520:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x825f552c
	if (!cr6.gt) goto loc_825F552C;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
loc_825F552C:
	// lfs f12,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f6
	cr6.compare(ctx.f12.f64, ctx.f6.f64);
	// bge cr6,0x825f553c
	if (!cr6.lt) goto loc_825F553C;
	// fmr f6,f12
	ctx.f6.f64 = ctx.f12.f64;
loc_825F553C:
	// lfs f13,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x825f554c
	if (!cr6.lt) goto loc_825F554C;
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
loc_825F554C:
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x825f555c
	if (!cr6.lt) goto loc_825F555C;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_825F555C:
	// fcmpu cr6,f12,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// ble cr6,0x825f5568
	if (!cr6.gt) goto loc_825F5568;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_825F5568:
	// fcmpu cr6,f13,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x825f5574
	if (!cr6.gt) goto loc_825F5574;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
loc_825F5574:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x825f5580
	if (!cr6.gt) goto loc_825F5580;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
loc_825F5580:
	// lfs f12,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f6
	cr6.compare(ctx.f12.f64, ctx.f6.f64);
	// bge cr6,0x825f5590
	if (!cr6.lt) goto loc_825F5590;
	// fmr f6,f12
	ctx.f6.f64 = ctx.f12.f64;
loc_825F5590:
	// lfs f13,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x825f55a0
	if (!cr6.lt) goto loc_825F55A0;
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
loc_825F55A0:
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x825f55b0
	if (!cr6.lt) goto loc_825F55B0;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_825F55B0:
	// fcmpu cr6,f12,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// ble cr6,0x825f55bc
	if (!cr6.gt) goto loc_825F55BC;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_825F55BC:
	// fcmpu cr6,f13,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x825f55c8
	if (!cr6.gt) goto loc_825F55C8;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
loc_825F55C8:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x825f55d4
	if (!cr6.gt) goto loc_825F55D4;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
loc_825F55D4:
	// lfs f12,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f6
	cr6.compare(ctx.f12.f64, ctx.f6.f64);
	// bge cr6,0x825f55e4
	if (!cr6.lt) goto loc_825F55E4;
	// fmr f6,f12
	ctx.f6.f64 = ctx.f12.f64;
loc_825F55E4:
	// lfs f13,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x825f55f4
	if (!cr6.lt) goto loc_825F55F4;
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
loc_825F55F4:
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x825f5604
	if (!cr6.lt) goto loc_825F5604;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_825F5604:
	// fcmpu cr6,f12,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// ble cr6,0x825f5610
	if (!cr6.gt) goto loc_825F5610;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_825F5610:
	// fcmpu cr6,f13,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x825f561c
	if (!cr6.gt) goto loc_825F561C;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
loc_825F561C:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x825f5628
	if (!cr6.gt) goto loc_825F5628;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
loc_825F5628:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x825f54d8
	if (!cr0.eq) goto loc_825F54D8;
	// vmrghw128 v61,v62,v53
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stfs f6,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// vmrghw128 v32,v63,v0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// vmrglw128 v60,v62,v53
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stfs f8,136(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vmrglw128 v59,v63,v0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// vmrghw128 v63,v32,v61
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vmrglw128 v62,v32,v61
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// stfs f6,160(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// vmrghw128 v61,v59,v60
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// stfs f8,168(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f7,180(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f6,192(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f11,200(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f9,208(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f10,212(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f11,216(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f6,224(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f7,228(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f11,232(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f9,240(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f7,244(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f11,248(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
loc_825F56B8:
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// vmsum3fp128 v57,v58,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v56,v58,v63
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v55,v58,v62
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmrghw128 v54,v56,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v53,v55,v54
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v52,v54,v53
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x825f56b8
	if (!cr0.eq) goto loc_825F56B8;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lfs f7,88(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f6,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// vsubfp128 v50,v51,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v13.f32)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v47,v49,v13
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f0,14884(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// vsubfp128 v46,v48,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v44,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v44,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// stvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f13,f13
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// fmadds f4,f12,f12,f5
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f5.f64));
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stvx128 v47,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r7,-31280
	ctx.r4.s64 = ctx.r7.s64 + -31280;
	// fmadds f2,f10,f10,f4
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f4.f64));
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v46,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v45,r0,r3
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vsubfp128 v12,v45,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(ctx.v13.f32)));
	// fsqrts f1,f2
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// vmaddfp v10,v12,v11,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// fmuls f31,f1,f7
	ctx.fpscr.disableFlushModeUnconditional();
	f31.f64 = double(float(ctx.f1.f64 * ctx.f7.f64));
	// fmuls f3,f13,f13
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f31,f0
	ctx.f10.f64 = double(float(f31.f64 * f0.f64));
	// fmadds f11,f11,f11,f3
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f3.f64));
	// fneg f7,f10
	ctx.f7.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fmadds f9,f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fsubs f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fsqrts f5,f9
	ctx.f5.f64 = double(float(sqrt(ctx.f9.f64)));
	// lvlx128 v43,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v9,v43,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// vmaddfp v8,v0,v9,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v8,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f3,f13,f13,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fmuls f30,f5,f0
	f30.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmadds f2,f8,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fmuls f29,f1,f0
	f29.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x8217c088
	ctx.lr = 0x825F57F0;
	sub_8217C088(ctx, base);
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// vspltisw128 v42,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v40,v42,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v40,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x825F5814;
	sub_8217CE80(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f6,f31
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f31.f64;
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// lfs f5,27640(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27640);
	ctx.f5.f64 = double(temp.f32);
	// fneg f3,f29
	ctx.f3.u64 = f29.u64 ^ 0x8000000000000000;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x8217cc80
	ctx.lr = 0x825F5838;
	sub_8217CC80(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825F52F0) {
	__imp__sub_825F52F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F584C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F584C) {
	__imp__sub_825F584C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5850) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x825F5858;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r10,592(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// stb r11,660(r30)
	PPC_STORE_U8(r30.u32 + 660, r11.u8);
	// cmplwi cr6,r10,1344
	cr6.compare<uint32_t>(ctx.r10.u32, 1344, xer);
	// ble cr6,0x825f588c
	if (!cr6.gt) goto loc_825F588C;
	// lwz r10,596(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 596);
	// cmplwi cr6,r10,1344
	cr6.compare<uint32_t>(ctx.r10.u32, 1344, xer);
	// ble cr6,0x825f588c
	if (!cr6.gt) goto loc_825F588C;
	// li r11,1
	r11.s64 = 1;
loc_825F588C:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// stb r11,661(r30)
	PPC_STORE_U8(r30.u32 + 661, r11.u8);
	// lwz r10,600(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 600);
	// addi r29,r30,640
	r29.s64 = r30.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-25232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// ble cr6,0x825f5904
	if (!cr6.gt) goto loc_825F5904;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F58C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,604(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 604);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825f5968
	if (cr6.eq) goto loc_825F5968;
	// lwz r3,-25232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F58FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// b 0x825f594c
	goto loc_825F594C;
loc_825F5904:
	// li r6,-1
	ctx.r6.s64 = -1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F5910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,604(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 604);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825f5968
	if (cr6.eq) goto loc_825F5968;
	// lwz r3,-25232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F5948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
loc_825F594C:
	// lwz r3,-25232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825F5968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F5968:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,12
	ctx.r3.s64 = 12;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x825F5980;
	sub_8217F768(ctx, base);
	// li r3,13
	ctx.r3.s64 = 13;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x825F5990;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,636(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 636);
	// bl 0x8217c658
	ctx.lr = 0x825F599C;
	sub_8217C658(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F5850) {
	__imp__sub_825F5850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F59A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x825F59C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8218ae48
	ctx.lr = 0x825F59E4;
	sub_8218AE48(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmr f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f28.f64;
	// li r11,-1
	r11.s64 = -1;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f7,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// bl 0x82194b58
	ctx.lr = 0x825F5A28;
	sub_82194B58(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r4,-25360(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25360);
	// bl 0x8218ae48
	ctx.lr = 0x825F5A38;
	sub_8218AE48(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x825F5A44;
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

PPC_WEAK_FUNC(sub_825F59A8) {
	__imp__sub_825F59A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,628(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,604(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 604);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x825f5a74
	if (!cr6.eq) goto loc_825F5A74;
	// lwz r4,608(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 608);
loc_825F5A74:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r5,616(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 616);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lfs f4,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 104);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,27536(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27536);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-32524(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32524);
	ctx.f1.f64 = double(temp.f32);
	// b 0x825f59a8
	sub_825F59A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F5A58) {
	__imp__sub_825F5A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5A9C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F5A9C) {
	__imp__sub_825F5A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6676(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6676);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F5AA0) {
	__imp__sub_825F5AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F5AAC) {
	__imp__sub_825F5AAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5AB0) {
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
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwzx r30,r9,r10
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825f52f0
	ctx.lr = 0x825F5AEC;
	sub_825F52F0(ctx, base);
	// addi r5,r31,64
	ctx.r5.s64 = r31.s64 + 64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,112
	ctx.r3.s64 = r30.s64 + 112;
	// bl 0x825f7cf8
	ctx.lr = 0x825F5AFC;
	sub_825F7CF8(ctx, base);
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

PPC_WEAK_FUNC(sub_825F5AB0) {
	__imp__sub_825F5AB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F5B14) {
	__imp__sub_825F5B14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5B18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f5b2c
	if (cr6.eq) goto loc_825F5B2C;
	// lfs f0,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	f0.f64 = double(temp.f32);
	// b 0x825f5b30
	goto loc_825F5B30;
loc_825F5B2C:
	// lfs f0,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	f0.f64 = double(temp.f32);
loc_825F5B30:
	// stfs f0,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f5b44
	if (cr6.eq) goto loc_825F5B44;
	// lfs f0,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	f0.f64 = double(temp.f32);
	// b 0x825f5b48
	goto loc_825F5B48;
loc_825F5B44:
	// lfs f0,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	f0.f64 = double(temp.f32);
loc_825F5B48:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,88(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 88, temp.u32);
	// beq cr6,0x825f5b64
	if (cr6.eq) goto loc_825F5B64;
	// lfs f0,104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	f0.f64 = double(temp.f32);
	// b 0x825f5b68
	goto loc_825F5B68;
loc_825F5B64:
	// lfs f0,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	f0.f64 = double(temp.f32);
loc_825F5B68:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,96(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 96, temp.u32);
	// beq cr6,0x825f5b84
	if (cr6.eq) goto loc_825F5B84;
	// lfs f0,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	f0.f64 = double(temp.f32);
	// b 0x825f5b88
	goto loc_825F5B88;
loc_825F5B84:
	// lfs f0,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	f0.f64 = double(temp.f32);
loc_825F5B88:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,104(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 104, temp.u32);
	// beq cr6,0x825f5ba4
	if (cr6.eq) goto loc_825F5BA4;
	// lfs f0,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	f0.f64 = double(temp.f32);
	// b 0x825f5ba8
	goto loc_825F5BA8;
loc_825F5BA4:
	// lfs f0,124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	f0.f64 = double(temp.f32);
loc_825F5BA8:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,92(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 92, temp.u32);
	// beq cr6,0x825f5bc4
	if (cr6.eq) goto loc_825F5BC4;
	// lfs f0,128(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	f0.f64 = double(temp.f32);
	// b 0x825f5bc8
	goto loc_825F5BC8;
loc_825F5BC4:
	// lfs f0,132(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	f0.f64 = double(temp.f32);
loc_825F5BC8:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,100(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 100, temp.u32);
	// beq cr6,0x825f5be4
	if (cr6.eq) goto loc_825F5BE4;
	// lfs f0,136(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	f0.f64 = double(temp.f32);
	// b 0x825f5be8
	goto loc_825F5BE8;
loc_825F5BE4:
	// lfs f0,140(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	f0.f64 = double(temp.f32);
loc_825F5BE8:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,80(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 80, temp.u32);
	// beq cr6,0x825f5c04
	if (cr6.eq) goto loc_825F5C04;
	// lfs f0,144(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	f0.f64 = double(temp.f32);
	// b 0x825f5c08
	goto loc_825F5C08;
loc_825F5C04:
	// lfs f0,148(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	f0.f64 = double(temp.f32);
loc_825F5C08:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,84(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 84, temp.u32);
	// beq cr6,0x825f5c30
	if (cr6.eq) goto loc_825F5C30;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f0,152(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f0,840(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 840, temp.u32);
	// blr 
	return;
loc_825F5C30:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f0,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f0,840(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 840, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F5B18) {
	__imp__sub_825F5B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F5C44) {
	__imp__sub_825F5C44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F5C48) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x825F5C50;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// lwzx r29,r10,r8
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// lwzx r25,r8,r9
	r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r11,636(r31)
	PPC_STORE_U32(r31.u32 + 636, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c658
	ctx.lr = 0x825F5C94;
	sub_8217C658(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c568
	ctx.lr = 0x825F5C9C;
	sub_8217C568(ctx, base);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// li r26,16
	r26.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// li r27,32
	r27.s64 = 32;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// li r28,48
	r28.s64 = 48;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// lvx128 v62,r3,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lvx128 v61,r3,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,312(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	f0.f64 = double(temp.f32);
	// lfs f13,708(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 708);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,296(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// stfs f11,296(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lfs f10,708(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 708);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 / ctx.f10.f64));
	// stfs f9,312(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// bl 0x8217cd88
	ctx.lr = 0x825F5D04;
	sub_8217CD88(ctx, base);
	// lfs f8,172(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 172);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,92(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 92);
	ctx.f7.f64 = double(temp.f32);
	// li r3,12
	ctx.r3.s64 = 12;
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x825F5D20;
	sub_8217F768(ctx, base);
	// lfs f5,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// li r3,13
	ctx.r3.s64 = 13;
	// lfs f4,104(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 104);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x825F5D3C;
	sub_8217F768(ctx, base);
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// lwz r6,608(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-25232(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -25232);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825F5D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r24,-32256
	r24.s64 = -2113929216;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x825f5d94
	if (cr6.eq) goto loc_825F5D94;
	// lwz r11,592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// cmplwi cr6,r11,1344
	cr6.compare<uint32_t>(r11.u32, 1344, xer);
	// ble cr6,0x825f5d94
	if (!cr6.gt) goto loc_825F5D94;
	// lwz r11,596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// cmplwi cr6,r11,1344
	cr6.compare<uint32_t>(r11.u32, 1344, xer);
	// bgt cr6,0x825f5db0
	if (cr6.gt) goto loc_825F5DB0;
loc_825F5D94:
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// lfs f1,7444(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178370
	ctx.lr = 0x825F5DB0;
	sub_82178370(ctx, base);
loc_825F5DB0:
	// lwz r9,596(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// lwz r8,592(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f30,f12
	f30.f64 = double(float(ctx.f12.f64));
	// frsp f29,f11
	f29.f64 = double(float(ctx.f11.f64));
	// beq cr6,0x825f5e10
	if (cr6.eq) goto loc_825F5E10;
	// lfs f0,7444(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,5
	ctx.r6.s64 = 5;
	// fdivs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 / f30.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fdivs f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 / f29.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f29,124(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8218aef8
	ctx.lr = 0x825F5E10;
	sub_8218AEF8(ctx, base);
loc_825F5E10:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f5e24
	if (!cr6.eq) goto loc_825F5E24;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_825F5E24:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x825f5eb8
	if (cr6.lt) goto loc_825F5EB8;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// bge cr6,0x825f5eb8
	if (!cr6.lt) goto loc_825F5EB8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r30,22
	ctx.r8.s64 = r30.s64 + 22;
	// li r7,608
	ctx.r7.s64 = 608;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r30,25
	ctx.r5.s64 = r30.s64 + 25;
	// lwzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// li r3,592
	ctx.r3.s64 = 592;
	// rlwinm r8,r5,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r30,28
	ctx.r5.s64 = r30.s64 + 28;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r23,576
	r23.s64 = 576;
	// lvx128 v59,r4,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r4,r5,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v59,r6,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r6,r9,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// lvx128 v58,r6,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r8,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwzx r3,r9,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// lvx128 v57,r3,r23
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r4,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 460);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 364);
	f0.f64 = double(temp.f32);
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f11,412(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 412, temp.u32);
	// fneg f10,f12
	ctx.f10.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f9,364(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 364, temp.u32);
	// stfs f10,460(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 460, temp.u32);
loc_825F5EB8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,12
	ctx.r7.s64 = 12;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r10,r11,608
	ctx.r10.s64 = r11.s64 + 608;
	// addi r8,r11,624
	ctx.r8.s64 = r11.s64 + 624;
	// lfs f31,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f31.f64 = double(temp.f32);
	// addi r9,r11,576
	ctx.r9.s64 = r11.s64 + 576;
	// lfs f0,636(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 636);
	f0.f64 = double(temp.f32);
	// addi r11,r11,592
	r11.s64 = r11.s64 + 592;
	// lvlx128 v56,r10,r7
	temp.u32 = ctx.r10.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v0,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32)));
	// vmsum3fp128 v53,v54,v13
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fmuls f13,f11,f31
	ctx.f13.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fneg f10,f13
	ctx.f10.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v52,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x825f5f44
	if (!cr6.eq) goto loc_825F5F44;
	// li r8,496
	ctx.r8.s64 = 496;
	// stvx128 v0,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825F5F44:
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r8,r30,128
	ctx.r8.s64 = r30.s64 + 128;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r30,132
	ctx.r6.s64 = r30.s64 + 132;
	// fmuls f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f0,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fsubs f6,f13,f0
	ctx.f6.f64 = double(float(ctx.f13.f64 - f0.f64));
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// fmadds f5,f10,f9,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fnmadds f4,f8,f7,f5
	ctx.f4.f64 = double(float(-(ctx.f8.f64 * ctx.f7.f64 + ctx.f5.f64)));
	// stfsx f4,r4,r31
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + r31.u32, temp.u32);
	// stfsx f6,r3,r31
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, temp.u32);
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v0,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)));
	// vmsum3fp128 v48,v51,v13
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// lfs f3,12(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f2,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fabs f13,f1
	ctx.f13.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * f31.f64));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v47,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v47,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x825f5ff0
	if (!cr6.eq) goto loc_825F5FF0;
	// li r10,544
	ctx.r10.s64 = 544;
	// stvx128 v0,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825F5FF0:
	// lfs f12,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r30,140
	ctx.r10.s64 = r30.s64 + 140;
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r30,144
	ctx.r9.s64 = r30.s64 + 144;
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f13,f0
	ctx.f5.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r11,r29,384
	r11.s64 = r29.s64 + 384;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmadds f4,f9,f8,f10
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f10.f64));
	// fnmadds f3,f6,f7,f4
	ctx.f3.f64 = double(float(-(ctx.f6.f64 * ctx.f7.f64 + ctx.f4.f64)));
	// stfsx f3,r8,r31
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, temp.u32);
	// stfsx f5,r7,r31
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, temp.u32);
	// lvx128 v46,r11,r26
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r11,r27
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r11,r28
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c568
	ctx.lr = 0x825F606C;
	sub_8217C568(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r25,16
	r29.s64 = r25.s64 + 16;
	// lvx128 v41,r9,r26
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v40,r9,r27
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v39,r9,r28
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x825F60B4;
	sub_8215E000(ctx, base);
	// lwz r3,608(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,148(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825F60D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fdivs f2,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(f31.f64 / f30.f64));
	// fdivs f1,f31,f29
	ctx.f1.f64 = double(float(f31.f64 / f29.f64));
	// vspltisw128 v38,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,7444(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// vupkd3d128 v37,v38,4
	temp.f32 = 3.0f;
	temp.s32 += v38.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v38.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v37 = vTemp;
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v33,r0,r29
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r7,26112
	ctx.r4.s64 = ctx.r7.s64 + 26112;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// vpermwi128 v36,v37,234
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), 0x15));
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f11,f2,f31
	ctx.f11.f64 = double(float(ctx.f2.f64 + f31.f64));
	// vpermwi128 v35,v37,174
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), 0x51));
	// fadds f10,f1,f31
	ctx.f10.f64 = double(float(ctx.f1.f64 + f31.f64));
	// vpermwi128 v34,v37,186
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), 0x45));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fmadds f6,f11,f13,f8
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f7,f10,f12,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stvx128 v36,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lfs f11,31492(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31492);
	ctx.f11.f64 = double(temp.f32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lvx128 v32,r0,r4
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// addi r31,r1,224
	r31.s64 = ctx.r1.s64 + 224;
	// fmuls f5,f13,f31
	ctx.f5.f64 = double(float(ctx.f13.f64 * f31.f64));
	// addi r30,r1,176
	r30.s64 = ctx.r1.s64 + 176;
	// stvx128 v34,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f4,f12,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// lvx128 v63,r29,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r29,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v61,r29,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f4,148(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v33,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x825F61D8;
	sub_8215E000(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_825F5C48) {
	__imp__sub_825F5C48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F61EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F61EC) {
	__imp__sub_825F61EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F61F0) {
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
	PPCRegister f31{};
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
	// bl 0x823d91ec
	ctx.lr = 0x825F61F8;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r8,596(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// lwz r7,592(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f0,f12
	f0.f64 = double(float(ctx.f12.f64));
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// beq cr6,0x825f6270
	if (cr6.eq) goto loc_825F6270;
	// fdivs f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 / f0.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fdivs f11,f31,f13
	ctx.f11.f64 = double(float(f31.f64 / ctx.f13.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8218aef8
	ctx.lr = 0x825F6270;
	sub_8218AEF8(ctx, base);
loc_825F6270:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r27,28(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825f6290
	if (cr6.eq) goto loc_825F6290;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r31,496
	ctx.r4.s64 = r31.s64 + 496;
	// bl 0x8218aef8
	ctx.lr = 0x825F6290;
	sub_8218AEF8(ctx, base);
loc_825F6290:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825f62ac
	if (cr6.eq) goto loc_825F62AC;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r31,544
	ctx.r4.s64 = r31.s64 + 544;
	// bl 0x8218aef8
	ctx.lr = 0x825F62AC;
	sub_8218AEF8(ctx, base);
loc_825F62AC:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r30,16
	r30.s64 = 16;
	// li r28,32
	r28.s64 = 32;
	// li r29,48
	r29.s64 = 48;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825f6328
	if (cr6.eq) goto loc_825F6328;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x825f6318
	if (!cr6.gt) goto loc_825F6318;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r6,-32
	ctx.r6.s64 = -32;
	// li r7,-16
	ctx.r7.s64 = -16;
loc_825F62E0:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x825f62e0
	if (!cr0.eq) goto loc_825F62E0;
loc_825F6318:
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// bl 0x8218aef8
	ctx.lr = 0x825F6328;
	sub_8218AEF8(ctx, base);
loc_825F6328:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r10,r4,2352
	ctx.r10.s64 = ctx.r4.s64 + 2352;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v59,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r28
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v54,v55,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v54,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v52,v53,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v63,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// stvx128 v51,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x825f63ac
	if (cr6.eq) goto loc_825F63AC;
	// li r6,9
	ctx.r6.s64 = 9;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8218aef8
	ctx.lr = 0x825F63AC;
	sub_8218AEF8(ctx, base);
loc_825F63AC:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825f63c0
	if (cr6.eq) goto loc_825F63C0;
	// lwz r4,608(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// bl 0x8218ae48
	ctx.lr = 0x825F63C0;
	sub_8218AE48(ctx, base);
loc_825F63C0:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825f640c
	if (cr6.eq) goto loc_825F640C;
	// lhz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// lfs f0,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	f0.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// li r6,3
	ctx.r6.s64 = 3;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// lfs f11,84(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fmsubs f10,f11,f0,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 - ctx.f12.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x825F640C;
	sub_8218AEF8(ctx, base);
loc_825F640C:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f6458
	if (!cr6.eq) goto loc_825F6458;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,629(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 629);
	// lwz r9,632(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 632);
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,6632(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6632);
	// stb r10,40(r11)
	PPC_STORE_U8(r11.u32 + 40, ctx.r10.u8);
	// stw r9,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r9.u32);
	// bne cr6,0x825f6458
	if (!cr6.eq) goto loc_825F6458;
	// li r4,-1
	ctx.r4.s64 = -1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x825F6458;
	sub_82178370(ctx, base);
loc_825F6458:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_825F61F0) {
	__imp__sub_825F61F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F6464) {
	__imp__sub_825F6464(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6468) {
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
	// li r3,848
	ctx.r3.s64 = 848;
	// bl 0x82130528
	ctx.lr = 0x825F6480;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f64b4
	if (cr6.eq) goto loc_825F64B4;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x82475e28
	ctx.lr = 0x825F6494;
	sub_82475E28(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f4c50
	ctx.lr = 0x825F64A0;
	sub_825F4C50(ctx, base);
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
loc_825F64B4:
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

PPC_WEAK_FUNC(sub_825F6468) {
	__imp__sub_825F6468(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F64CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F64CC) {
	__imp__sub_825F64CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F64D0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r11,6676
	r31.s64 = r11.s64 + 6676;
	// lwz r11,6676(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6676);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f6680
	if (!cr6.eq) goto loc_825F6680;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x825F6500;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6514
	if (cr6.eq) goto loc_825F6514;
	// bl 0x821d5408
	ctx.lr = 0x825F6510;
	sub_821D5408(ctx, base);
	// b 0x825f6518
	goto loc_825F6518;
loc_825F6514:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_825F6518:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32161
	r11.s64 = -2107703296;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,26128
	ctx.r7.s64 = ctx.r10.s64 + 26128;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,23200
	ctx.r9.s64 = r11.s64 + 23200;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,848
	ctx.r5.s64 = 848;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32161
	ctx.r8.s64 = -2107703296;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32126
	ctx.r3.s64 = -2105409536;
	// addi r4,r8,25704
	ctx.r4.s64 = ctx.r8.s64 + 25704;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-22536
	ctx.r8.s64 = ctx.r10.s64 + -22536;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-22560
	ctx.r9.s64 = ctx.r3.s64 + -22560;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// addi r6,r5,-22512
	ctx.r6.s64 = ctx.r5.s64 + -22512;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r4,-22488
	ctx.r5.s64 = ctx.r4.s64 + -22488;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r4,r7,-22464
	ctx.r4.s64 = ctx.r7.s64 + -22464;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r9,84
	ctx.r9.s64 = 84;
	// li r11,88
	r11.s64 = 88;
	// li r10,92
	ctx.r10.s64 = 92;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// addi r6,r8,-22440
	ctx.r6.s64 = ctx.r8.s64 + -22440;
	// addi r5,r7,-22416
	ctx.r5.s64 = ctx.r7.s64 + -22416;
	// addi r4,r30,-22392
	ctx.r4.s64 = r30.s64 + -22392;
	// li r9,104
	ctx.r9.s64 = 104;
	// li r11,96
	r11.s64 = 96;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// addi r5,r7,-22344
	ctx.r5.s64 = ctx.r7.s64 + -22344;
	// addi r6,r8,-22368
	ctx.r6.s64 = ctx.r8.s64 + -22368;
	// addi r4,r30,-22320
	ctx.r4.s64 = r30.s64 + -22320;
	// li r9,108
	ctx.r9.s64 = 108;
	// li r11,836
	r11.s64 = 836;
	// li r10,840
	ctx.r10.s64 = 840;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bl 0x821d4458
	ctx.lr = 0x825F662C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x825F663C;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x825F6658;
	sub_821D41D0(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r4,r8,-22296
	ctx.r4.s64 = ctx.r8.s64 + -22296;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4b00
	ctx.lr = 0x825F6668;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x825F6680;
	sub_821C0548(ctx, base);
loc_825F6680:
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

PPC_WEAK_FUNC(sub_825F64D0) {
	__imp__sub_825F64D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6698) {
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
	ctx.lr = 0x825F66A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x825f66e0
	if (!cr6.gt) goto loc_825F66E0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r28
	r31.u64 = r28.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r29,r11,-12156
	r29.s64 = r11.s64 + -12156;
loc_825F66C0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f66d4
	if (cr6.eq) goto loc_825F66D4;
	// stw r29,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r29.u32);
	// bl 0x82130588
	ctx.lr = 0x825F66D4;
	sub_82130588(ctx, base);
loc_825F66D4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x825f66c0
	if (!cr0.eq) goto loc_825F66C0;
loc_825F66E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x825F66E8;
	sub_82130588(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F6698) {
	__imp__sub_825F6698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F66F0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r11,6672
	r31.s64 = r11.s64 + 6672;
	// lwz r11,6672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6672);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f6928
	if (!cr6.eq) goto loc_825F6928;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x825F6720;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6730
	if (cr6.eq) goto loc_825F6730;
	// bl 0x821d5408
	ctx.lr = 0x825F672C;
	sub_821D5408(ctx, base);
	// b 0x825f6734
	goto loc_825F6734;
loc_825F6730:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825F6734:
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// addi r5,r8,26152
	ctx.r5.s64 = ctx.r8.s64 + 26152;
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r4,688
	ctx.r4.s64 = 688;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r3,r7,-22212
	ctx.r3.s64 = ctx.r7.s64 + -22212;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,24
	ctx.r10.s64 = 24;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r9,6676(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 6676);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bne cr6,0x825f6798
	if (!cr6.eq) goto loc_825F6798;
	// bl 0x825f64d0
	ctx.lr = 0x825F6794;
	sub_825F64D0(ctx, base);
	// lwz r9,6676(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 6676);
loc_825F6798:
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r8,r11,24100
	ctx.r8.s64 = r11.s64 + 24100;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// addi r5,r10,-23076
	ctx.r5.s64 = ctx.r10.s64 + -23076;
	// addi r4,r7,-23052
	ctx.r4.s64 = ctx.r7.s64 + -23052;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r9,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r9.u32);
	// li r11,84
	r11.s64 = 84;
	// addi r7,r6,-23028
	ctx.r7.s64 = ctx.r6.s64 + -23028;
	// li r10,628
	ctx.r10.s64 = 628;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r30,-32126
	r30.s64 = -2105409536;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// li r9,96
	ctx.r9.s64 = 96;
	// addi r5,r8,-22980
	ctx.r5.s64 = ctx.r8.s64 + -22980;
	// addi r6,r6,-23004
	ctx.r6.s64 = ctx.r6.s64 + -23004;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-22956
	ctx.r4.s64 = r30.s64 + -22956;
	// li r11,100
	r11.s64 = 100;
	// li r10,104
	ctx.r10.s64 = 104;
	// li r9,108
	ctx.r9.s64 = 108;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// addi r6,r8,-22932
	ctx.r6.s64 = ctx.r8.s64 + -22932;
	// addi r5,r7,-22908
	ctx.r5.s64 = ctx.r7.s64 + -22908;
	// addi r4,r30,-22884
	ctx.r4.s64 = r30.s64 + -22884;
	// li r11,120
	r11.s64 = 120;
	// li r10,124
	ctx.r10.s64 = 124;
	// li r9,112
	ctx.r9.s64 = 112;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// addi r6,r8,-22860
	ctx.r6.s64 = ctx.r8.s64 + -22860;
	// addi r5,r7,-22836
	ctx.r5.s64 = ctx.r7.s64 + -22836;
	// addi r4,r30,-22812
	ctx.r4.s64 = r30.s64 + -22812;
	// li r11,116
	r11.s64 = 116;
	// li r10,128
	ctx.r10.s64 = 128;
	// li r9,132
	ctx.r9.s64 = 132;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// addi r6,r8,-22788
	ctx.r6.s64 = ctx.r8.s64 + -22788;
	// addi r5,r7,-22764
	ctx.r5.s64 = ctx.r7.s64 + -22764;
	// addi r4,r30,-22740
	ctx.r4.s64 = r30.s64 + -22740;
	// li r11,136
	r11.s64 = 136;
	// li r10,140
	ctx.r10.s64 = 140;
	// li r9,144
	ctx.r9.s64 = 144;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r30,-32126
	r30.s64 = -2105409536;
	// addi r5,r7,-22692
	ctx.r5.s64 = ctx.r7.s64 + -22692;
	// addi r6,r8,-22716
	ctx.r6.s64 = ctx.r8.s64 + -22716;
	// addi r4,r30,-22668
	ctx.r4.s64 = r30.s64 + -22668;
	// li r11,148
	r11.s64 = 148;
	// li r10,152
	ctx.r10.s64 = 152;
	// li r9,156
	ctx.r9.s64 = 156;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x825F68D4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x825F68E4;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x825F6900;
	sub_821D41D0(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-22640
	ctx.r4.s64 = ctx.r8.s64 + -22640;
	// bl 0x821d4b00
	ctx.lr = 0x825F6910;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x825F6928;
	sub_821C0548(ctx, base);
loc_825F6928:
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

PPC_WEAK_FUNC(sub_825F66F0) {
	__imp__sub_825F66F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91d4
	ctx.lr = 0x825F6948;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d0
	ctx.lr = 0x825F6950;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r11,26216
	ctx.r8.s64 = r11.s64 + 26216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r10,640
	ctx.r10.s64 = 640;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// sth r29,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r29.u16);
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// sth r29,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r29.u16);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// sth r29,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r29.u16);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// sth r29,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r29.u16);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r10,592(r31)
	PPC_STORE_U32(r31.u32 + 592, ctx.r10.u32);
	// lfs f30,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// lis r25,-32256
	r25.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r29,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r29.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r29,608(r31)
	PPC_STORE_U32(r31.u32 + 608, r29.u32);
	// lis r28,-256
	r28.s64 = -16777216;
	// stb r29,628(r31)
	PPC_STORE_U8(r31.u32 + 628, r29.u8);
	// lis r27,-32248
	r27.s64 = -2113404928;
	// stb r29,629(r31)
	PPC_STORE_U8(r31.u32 + 629, r29.u8);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r29,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r29.u32);
	// li r11,1
	r11.s64 = 1;
	// stfs f30,640(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 640, temp.u32);
	// lis r26,-32248
	r26.s64 = -2113404928;
	// stfs f30,644(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// lis r24,-32248
	r24.s64 = -2113404928;
	// stw r28,648(r31)
	PPC_STORE_U32(r31.u32 + 648, r28.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r29,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r29.u32);
	// stw r29,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r29.u32);
	// lfs f0,31292(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31292);
	f0.f64 = double(temp.f32);
	// stb r29,660(r31)
	PPC_STORE_U8(r31.u32 + 660, r29.u8);
	// lfs f13,-11624(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11624);
	ctx.f13.f64 = double(temp.f32);
	// stb r29,661(r31)
	PPC_STORE_U8(r31.u32 + 661, r29.u8);
	// lfs f12,26208(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 26208);
	ctx.f12.f64 = double(temp.f32);
	// stb r29,662(r31)
	PPC_STORE_U8(r31.u32 + 662, r29.u8);
	// lfs f11,-17424(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -17424);
	ctx.f11.f64 = double(temp.f32);
	// stb r11,663(r31)
	PPC_STORE_U8(r31.u32 + 663, r11.u8);
	// lfs f31,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r11,664(r31)
	PPC_STORE_U8(r31.u32 + 664, r11.u8);
	// stfs f13,84(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// addi r21,r31,16
	r21.s64 = r31.s64 + 16;
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stw r30,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r30.u32);
	// lfs f29,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f29.f64 = double(temp.f32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// lfs f28,11368(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 11368);
	f28.f64 = double(temp.f32);
	// addi r25,r31,24
	r25.s64 = r31.s64 + 24;
	// lfs f0,26204(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 26204);
	f0.f64 = double(temp.f32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// lfs f13,-31384(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,92(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f11,96(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// lfs f12,26200(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 26200);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,26196(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 26196);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-6176(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6176);
	ctx.f10.f64 = double(temp.f32);
	// stfs f31,88(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f29,100(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f29,104(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f29,108(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f31,140(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f30,164(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f30,160(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f12,144(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f28,148(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f11,152(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stfs f10,156(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stfs f30,168(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f30,172(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stfs f30,176(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// lhz r8,30(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825f6ae4
	if (!cr6.eq) goto loc_825F6AE4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r30.u16);
	// beq cr6,0x825f6adc
	if (cr6.eq) goto loc_825F6ADC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82195e48
	ctx.lr = 0x825F6AD8;
	sub_82195E48(ctx, base);
	// b 0x825f6ae0
	goto loc_825F6AE0;
loc_825F6ADC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_825F6AE0:
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
loc_825F6AE4:
	// clrlwi r28,r30,16
	r28.u64 = r30.u32 & 0xFFFF;
	// sth r28,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r28.u16);
	// lhz r11,6(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f6b18
	if (!cr6.eq) goto loc_825F6B18;
	// sth r28,6(r21)
	PPC_STORE_U16(r21.u32 + 6, r28.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825f6b10
	if (cr6.eq) goto loc_825F6B10;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825F6B0C;
	sub_82130528(ctx, base);
	// b 0x825f6b14
	goto loc_825F6B14;
loc_825F6B10:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_825F6B14:
	// stw r3,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r3.u32);
loc_825F6B18:
	// sth r28,4(r21)
	PPC_STORE_U16(r21.u32 + 4, r28.u16);
	// mr r28,r29
	r28.u64 = r29.u64;
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f6c1c
	if (cr6.eq) goto loc_825F6C1C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r26,r29
	r26.u64 = r29.u64;
	// li r22,16
	r22.s64 = 16;
	// lfs f26,31332(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31332);
	f26.f64 = double(temp.f32);
	// li r23,32
	r23.s64 = 32;
	// lfs f27,32312(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32312);
	f27.f64 = double(temp.f32);
	// li r24,48
	r24.s64 = 48;
	// addi r20,r11,-12156
	r20.s64 = r11.s64 + -12156;
loc_825F6B54:
	// li r3,848
	ctx.r3.s64 = 848;
	// bl 0x82130528
	ctx.lr = 0x825F6B5C;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825f6be8
	if (cr6.eq) goto loc_825F6BE8;
	// addi r3,r30,112
	ctx.r3.s64 = r30.s64 + 112;
	// bl 0x82475e28
	ctx.lr = 0x825F6B70;
	sub_82475E28(ctx, base);
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// stfs f31,80(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 80, temp.u32);
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f31,92(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 92, temp.u32);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// stfs f31,104(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
	// stw r29,832(r30)
	PPC_STORE_U32(r30.u32 + 832, r29.u32);
	// stfs f27,108(r30)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 108, temp.u32);
	// mr r27,r30
	r27.u64 = r30.u64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f26,840(r30)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r30.u32 + 840, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f28,88(r30)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r30.u32 + 88, temp.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f31,96(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// vpermwi128 v58,v62,171
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// stfs f30,100(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// fmadds f11,f12,f29,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64 + f29.f64));
	// stfs f11,84(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 84, temp.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x825f6bec
	goto loc_825F6BEC;
loc_825F6BE8:
	// mr r27,r29
	r27.u64 = r29.u64;
loc_825F6BEC:
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r3,r26,r30
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6c04
	if (cr6.eq) goto loc_825F6C04;
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r20.u32);
	// bl 0x82130588
	ctx.lr = 0x825F6C04;
	sub_82130588(ctx, base);
loc_825F6C04:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r27,r26,r30
	PPC_STORE_U32(r26.u32 + r30.u32, r27.u32);
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x825f6b54
	if (cr6.lt) goto loc_825F6B54;
loc_825F6C1C:
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f6c68
	if (cr6.eq) goto loc_825F6C68;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_825F6C30:
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x825F6C38;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6c48
	if (cr6.eq) goto loc_825F6C48;
	// bl 0x8217d5e8
	ctx.lr = 0x825F6C44;
	sub_8217D5E8(ctx, base);
	// b 0x825f6c4c
	goto loc_825F6C4C;
loc_825F6C48:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_825F6C4C:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r3,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lhz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x825f6c30
	if (cr6.lt) goto loc_825F6C30;
loc_825F6C68:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r11,2828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f6c9c
	if (!cr6.eq) goto loc_825F6C9C;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x825F6C80;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x825f6c98
	if (cr6.eq) goto loc_825F6C98;
	// bl 0x821c0580
	ctx.lr = 0x825F6C90;
	sub_821C0580(ctx, base);
	// stw r28,2828(r30)
	PPC_STORE_U32(r30.u32 + 2828, r28.u32);
	// b 0x825f6c9c
	goto loc_825F6C9C;
loc_825F6C98:
	// stw r29,2828(r30)
	PPC_STORE_U32(r30.u32 + 2828, r29.u32);
loc_825F6C9C:
	// bl 0x821c4210
	ctx.lr = 0x825F6CA0;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,2828(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2828);
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
	ctx.lr = 0x825F6CC4;
	sub_821C05E8(ctx, base);
	// clrlwi r9,r19,24
	ctx.r9.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f6d2c
	if (cr6.eq) goto loc_825F6D2C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// addi r4,r10,-19840
	ctx.r4.s64 = ctx.r10.s64 + -19840;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x825F6CE8;
	sub_821CA540(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r30,2828(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825F6D00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r7,5276
	ctx.r5.s64 = ctx.r7.s64 + 5276;
	// addi r4,r4,26172
	ctx.r4.s64 = ctx.r4.s64 + 26172;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c04b0
	ctx.lr = 0x825F6D24;
	sub_821C04B0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x825F6D2C;
	sub_821C9A90(ctx, base);
loc_825F6D2C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba1c
	ctx.lr = 0x825F6D3C;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_825F6940) {
	__imp__sub_825F6940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lfs f5,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,26228(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 26228);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f5
	ctx.f2.f64 = ctx.f5.f64;
	// lfs f6,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// b 0x8217d548
	sub_8217D548(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F6D40) {
	__imp__sub_825F6D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F6D6C) {
	__imp__sub_825F6D6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6D70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6672(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6672);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F6D70) {
	__imp__sub_825F6D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F6D7C) {
	__imp__sub_825F6D7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6D80) {
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
	ctx.lr = 0x825F6D88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// addi r10,r11,26216
	ctx.r10.s64 = r11.s64 + 26216;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x825F6DA8;
	sub_821BFC50(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f6dd8
	if (cr6.eq) goto loc_825F6DD8;
	// lwz r29,2828(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825f6dd0
	if (cr6.eq) goto loc_825F6DD0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c0688
	ctx.lr = 0x825F6DC8;
	sub_821C0688(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x825F6DD0;
	sub_82130588(ctx, base);
loc_825F6DD0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_825F6DD8:
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6df8
	if (cr6.eq) goto loc_825F6DF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F6DF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F6DF8:
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f6e18
	if (cr6.eq) goto loc_825F6E18;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F6E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F6E18:
	// lhz r5,30(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 30);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825f6e30
	if (cr6.eq) goto loc_825F6E30;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f6698
	ctx.lr = 0x825F6E30;
	sub_825F6698(ctx, base);
loc_825F6E30:
	// lhz r11,22(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f6e44
	if (cr6.eq) goto loc_825F6E44;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x825F6E44;
	sub_82130588(ctx, base);
loc_825F6E44:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x825F6E4C;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F6D80) {
	__imp__sub_825F6D80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F6E54) {
	__imp__sub_825F6E54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6E58) {
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
	// bl 0x825f6d80
	ctx.lr = 0x825F6E78;
	sub_825F6D80(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f6e90
	if (cr6.eq) goto loc_825F6E90;
	// bl 0x82130588
	ctx.lr = 0x825F6E8C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825F6E90:
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

PPC_WEAK_FUNC(sub_825F6E58) {
	__imp__sub_825F6E58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F6EA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	f0.f64 = double(temp.f32);
	// lbz r8,706(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// lfs f13,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,328(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 328);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 / ctx.f10.f64));
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f1,16(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmsubs f9,f9,f8,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 - ctx.f7.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x825f6f28
	if (cr6.eq) goto loc_825F6F28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f11,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// b 0x825f6fdc
	goto loc_825F6FDC;
loc_825F6F28:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v62,v63,99
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v10,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vpermwi128 v9,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v13,v9,v0,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v60,v13,v13
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v8,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v7,v59,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v6,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v61,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v2,v3,v4,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v13,v2
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
loc_825F6FDC:
	// fmuls f9,f11,f9
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// addi r11,r31,368
	r11.s64 = r31.s64 + 368;
	// addi r3,r31,464
	ctx.r3.s64 = r31.s64 + 464;
	// stfs f11,368(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f12,372(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// addi r4,r31,224
	ctx.r4.s64 = r31.s64 + 224;
	// stfs f13,376(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// fmadds f8,f13,f10,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmadds f7,f12,f0,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f8.f64));
	// stfs f7,380(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F7010;
	sub_82475FF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,704(r31)
	PPC_STORE_U8(r31.u32 + 704, r11.u8);
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

PPC_WEAK_FUNC(sub_825F6EA8) {
	__imp__sub_825F6EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F702C) {
	__imp__sub_825F702C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7030) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	f0.f64 = double(temp.f32);
	// lbz r8,706(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// lfs f13,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,328(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 328);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 / ctx.f10.f64));
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f1,20(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmsubs f9,f9,f8,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 - ctx.f7.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x825f70b0
	if (cr6.eq) goto loc_825F70B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f11,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f11.f64 = double(temp.f32);
	// b 0x825f7164
	goto loc_825F7164;
loc_825F70B0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v62,v63,99
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v10,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vpermwi128 v9,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v13,v9,v0,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v60,v13,v13
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v8,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v7,v59,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v6,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v61,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v2,v3,v4,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v13,v2
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
loc_825F7164:
	// fmuls f9,f11,f9
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// addi r11,r31,384
	r11.s64 = r31.s64 + 384;
	// addi r3,r31,480
	ctx.r3.s64 = r31.s64 + 480;
	// stfs f11,384(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// stfs f12,388(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// addi r4,r31,224
	ctx.r4.s64 = r31.s64 + 224;
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// fmadds f8,f13,f10,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmadds f7,f12,f0,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f8.f64));
	// stfs f7,396(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F7198;
	sub_82475FF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,704(r31)
	PPC_STORE_U8(r31.u32 + 704, r11.u8);
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

PPC_WEAK_FUNC(sub_825F7030) {
	__imp__sub_825F7030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F71B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F71B4) {
	__imp__sub_825F71B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F71B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	f0.f64 = double(temp.f32);
	// lbz r8,706(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// lfs f13,316(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,332(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 332);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 / ctx.f10.f64));
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fnmsubs f9,f9,f8,f7
	ctx.f9.f64 = double(float(-(ctx.f9.f64 * ctx.f8.f64 - ctx.f7.f64)));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// beq cr6,0x825f7238
	if (cr6.eq) goto loc_825F7238;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f12,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// b 0x825f72ec
	goto loc_825F72EC;
loc_825F7238:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v62,v63,99
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v10,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vpermwi128 v9,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v13,v9,v0,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v60,v13,v13
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v8,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v7,v59,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v6,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v61,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v2,v3,v4,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v13,v2
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
loc_825F72EC:
	// fmuls f10,f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// addi r11,r31,400
	r11.s64 = r31.s64 + 400;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// stfs f11,400(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f12,404(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// addi r4,r31,224
	ctx.r4.s64 = r31.s64 + 224;
	// stfs f13,408(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 408, temp.u32);
	// fmadds f9,f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fmadds f8,f11,f0,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f9.f64));
	// stfs f8,412(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 412, temp.u32);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F7320;
	sub_82475FF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,704(r31)
	PPC_STORE_U8(r31.u32 + 704, r11.u8);
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

PPC_WEAK_FUNC(sub_825F71B8) {
	__imp__sub_825F71B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F733C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F733C) {
	__imp__sub_825F733C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	f0.f64 = double(temp.f32);
	// lbz r8,706(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// lfs f13,316(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,332(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 332);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 / ctx.f10.f64));
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f1,28(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fnmsubs f9,f9,f8,f7
	ctx.f9.f64 = double(float(-(ctx.f9.f64 * ctx.f8.f64 - ctx.f7.f64)));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// beq cr6,0x825f73c0
	if (cr6.eq) goto loc_825F73C0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f12,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// b 0x825f7474
	goto loc_825F7474;
loc_825F73C0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v62,v63,99
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v10,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vpermwi128 v9,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v13,v9,v0,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v60,v13,v13
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v8,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v7,v59,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v6,v11,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v61,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v2,v3,v4,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v13,v2
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
loc_825F7474:
	// fmuls f10,f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// addi r11,r31,416
	r11.s64 = r31.s64 + 416;
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// stfs f11,416(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 416, temp.u32);
	// stfs f12,420(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 420, temp.u32);
	// addi r4,r31,224
	ctx.r4.s64 = r31.s64 + 224;
	// stfs f13,424(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 424, temp.u32);
	// fmadds f9,f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fmadds f8,f11,f0,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f9.f64));
	// stfs f8,428(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 428, temp.u32);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F74A8;
	sub_82475FF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,704(r31)
	PPC_STORE_U8(r31.u32 + 704, r11.u8);
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

PPC_WEAK_FUNC(sub_825F7340) {
	__imp__sub_825F7340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F74C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F74C4) {
	__imp__sub_825F74C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F74C8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,704(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 704);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfs f13,708(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 708);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f12,716(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 716);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f11,712(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 712);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x8217c560
	ctx.lr = 0x825F750C;
	sub_8217C560(ctx, base);
	// bl 0x821797d0
	ctx.lr = 0x825F7510;
	sub_821797D0(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,16(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// bl 0x8217c560
	ctx.lr = 0x825F7530;
	sub_8217C560(ctx, base);
	// bl 0x82179830
	ctx.lr = 0x825F7534;
	sub_82179830(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f7,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,20(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// bl 0x8217c560
	ctx.lr = 0x825F7554;
	sub_8217C560(ctx, base);
	// bl 0x82179890
	ctx.lr = 0x825F7558;
	sub_82179890(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f4,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,24(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// bl 0x8217c560
	ctx.lr = 0x825F7578;
	sub_8217C560(ctx, base);
	// bl 0x821798f0
	ctx.lr = 0x825F757C;
	sub_821798F0(ctx, base);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
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

PPC_WEAK_FUNC(sub_825F74C8) {
	__imp__sub_825F74C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F75AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F75AC) {
	__imp__sub_825F75AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F75B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	f0.f64 = double(temp.f32);
	// addi r11,r3,432
	r11.s64 = ctx.r3.s64 + 432;
loc_825F75C0:
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// vmsum3fp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x825f75fc
	if (cr6.gt) goto loc_825F75FC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// blt cr6,0x825f75c0
	if (cr6.lt) goto loc_825F75C0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_825F75FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F75B0) {
	__imp__sub_825F75B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F7604) {
	__imp__sub_825F7604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
	PPCVRegister v32{};
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
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r3,224
	r11.s64 = ctx.r3.s64 + 224;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,32
	ctx.r9.s64 = 32;
	// lfs f0,308(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	f0.f64 = double(temp.f32);
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f13,312(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v60,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vsubfp128 v55,v61,v57
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v58,r11,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v58,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// stfs f12,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f11,-28(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lvlx128 v54,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r1,-24
	ctx.r5.s64 = ctx.r1.s64 + -24;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r7,2240
	ctx.r4.s64 = ctx.r7.s64 + 2240;
	// lfs f10,316(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,-24(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f8,-20(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// lvlx128 v48,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,-31664
	ctx.r8.s64 = ctx.r10.s64 + -31664;
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r7,r9,-31648
	ctx.r7.s64 = ctx.r9.s64 + -31648;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r10,r3,308
	ctx.r10.s64 = ctx.r3.s64 + 308;
	// vmsum3fp128 v52,v55,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vor128 v9,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// li r6,304
	ctx.r6.s64 = 304;
	// vspltw128 v45,v54,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vrsqrtefp128 v53,v59
	simde_mm_store_ps(v53.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v8,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vrsqrtefp128 v49,v56
	simde_mm_store_ps(v49.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// lvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v46,v52
	simde_mm_store_ps(v46.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// vor128 v7,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vor128 v31,v52,v52
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v50,r3,r6
	temp.u32 = ctx.r3.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v5,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vspltw128 v6,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// addi r10,r3,592
	ctx.r10.s64 = ctx.r3.s64 + 592;
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// addi r9,r3,544
	ctx.r9.s64 = ctx.r3.s64 + 544;
	// lvx128 v10,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,528
	r11.s64 = ctx.r3.s64 + 528;
	// addi r8,r3,608
	ctx.r8.s64 = ctx.r3.s64 + 608;
	// addi r7,r3,560
	ctx.r7.s64 = ctx.r3.s64 + 560;
	// vcmpeqfp128 v3,v53,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v4,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vcmpeqfp128 v1,v49,v62
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v2,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vcmpeqfp128 v30,v46,v62
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v29,v46,v46
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vsel v0,v4,v12,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v13,v2,v13,v1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v12,v29,v9,v30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vmulfp128 v28,v0,v0
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v27,v13,v13
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v25,v63,v0
	simde_mm_store_ps(v25.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v24,v12,v12
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v26,v63,v13
	simde_mm_store_ps(v26.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v21,v63,v12
	simde_mm_store_ps(v21.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp v23,v8,v28,v11
	simde_mm_store_ps(v23.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v22,v7,v27,v11
	simde_mm_store_ps(v22.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v20,v31,v24,v11
	simde_mm_store_ps(v20.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v19,v23,v25,v0
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v25.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v18,v22,v26,v13
	simde_mm_store_ps(v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r6,r3,576
	ctx.r6.s64 = ctx.r3.s64 + 576;
	// vmaddfp v17,v20,v21,v12
	simde_mm_store_ps(v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v20.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// addi r5,r3,624
	ctx.r5.s64 = ctx.r3.s64 + 624;
	// addi r4,r3,640
	ctx.r4.s64 = ctx.r3.s64 + 640;
	// vmulfp128 v44,v60,v19
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v19.f32)));
	// addi r3,r1,-28
	ctx.r3.s64 = ctx.r1.s64 + -28;
	// addi r31,r1,-20
	r31.s64 = ctx.r1.s64 + -20;
	// lvlx128 v42,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v40,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v41,v42,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vspltw128 v39,v40,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vmulfp128 v43,v58,v18
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v18.f32)));
	// vmulfp128 v0,v55,v17
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v17.f32)));
	// vmulfp128 v38,v44,v45
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v45.f32)));
	// vmulfp128 v36,v44,v41
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v41.f32)));
	// vsubfp128 v37,v61,v43
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v43.f32)));
	// vmaddfp v16,v0,v6,v10
	simde_mm_store_ps(v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vsubfp128 v34,v61,v38
	simde_mm_store_ps(v34.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v38.f32)));
	// vsubfp128 v32,v61,v36
	simde_mm_store_ps(v32.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v36.f32)));
	// vmaddfp v15,v0,v5,v10
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmulfp128 v35,v37,v47
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v47.f32)));
	// vmulfp128 v33,v37,v39
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v16,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v35
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v35.f32)));
	// vsubfp128 v62,v61,v33
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v33.f32)));
	// vor128 v61,v16,v16
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v16.u8));
	// vaddfp128 v60,v61,v38
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v38.f32)));
	// vor128 v59,v60,v60
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v35
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v35.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v57,v34
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v34.f32)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v55,v35
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v35.f32)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v52,v53,v34
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v34.f32)));
	// vor128 v51,v52,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// stvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v50,v51,v63
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v48,v49,v38
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v38.f32)));
	// vor128 v47,v48,v48
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// stvx128 v48,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v46,v47,v63
	simde_mm_store_ps(v46.f32, simde_mm_add_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v46,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v44,v45,v36
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v36.f32)));
	// vor128 v43,v44,v44
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_load_si128((simde__m128i*)v44.u8));
	// stvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v42,v43,v33
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v40,v41,v32
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v32.f32)));
	// vor128 v39,v40,v40
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// stvx128 v40,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v38,v39,v33
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v38,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r0,r5
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v35,v37,v32
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v32.f32)));
	// vor128 v34,v35,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// stvx128 v35,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v33,v34,v62
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v33,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r0,r4
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v32,v36
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v36.f32)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F7608) {
	__imp__sub_825F7608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F789C) {
	__imp__sub_825F789C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F78A0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x825F78A8;
	// stfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,704(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 704);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f7c04
	if (!cr6.eq) goto loc_825F7C04;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,706(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// beq cr6,0x825f78dc
	if (cr6.eq) goto loc_825F78DC;
	// bl 0x825f7608
	ctx.lr = 0x825F78D8;
	sub_825F7608(ctx, base);
	// b 0x825f7ac4
	goto loc_825F7AC4;
loc_825F78DC:
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f12,316(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 316);
	ctx.f12.f64 = double(temp.f32);
	// li r10,272
	ctx.r10.s64 = 272;
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f10,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,332(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 332);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f7,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fdivs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f8.f64));
	// lfs f5,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lfs f3,328(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 328);
	ctx.f3.f64 = double(temp.f32);
	// fdivs f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 / ctx.f8.f64));
	// lfs f2,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// fneg f8,f13
	ctx.f8.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f1,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fdivs f12,f2,f3
	ctx.f12.f64 = double(float(ctx.f2.f64 / ctx.f3.f64));
	// fdivs f10,f1,f3
	ctx.f10.f64 = double(float(ctx.f1.f64 / ctx.f3.f64));
	// lvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r11,-22112
	r26.s64 = r11.s64 + -22112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * f0.f64));
	// addi r28,r31,224
	r28.s64 = r31.s64 + 224;
	// fmuls f5,f9,f0
	ctx.f5.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stfs f8,168(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f8,200(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// mr r30,r26
	r30.u64 = r26.u64;
	// addi r21,r28,48
	r21.s64 = r28.s64 + 48;
	// addi r20,r28,16
	r20.s64 = r28.s64 + 16;
	// addi r19,r28,32
	r19.s64 = r28.s64 + 32;
	// addi r18,r31,432
	r18.s64 = r31.s64 + 432;
	// fmuls f3,f7,f31
	ctx.f3.f64 = double(float(ctx.f7.f64 * f31.f64));
	// addi r17,r31,448
	r17.s64 = r31.s64 + 448;
	// fmuls f2,f5,f31
	ctx.f2.f64 = double(float(ctx.f5.f64 * f31.f64));
	// addi r29,r1,144
	r29.s64 = ctx.r1.s64 + 144;
	// addi r25,r11,-31664
	r25.s64 = r11.s64 + -31664;
	// addi r24,r10,-31648
	r24.s64 = ctx.r10.s64 + -31648;
	// addi r23,r9,2240
	r23.s64 = ctx.r9.s64 + 2240;
	// addi r22,r8,2528
	r22.s64 = ctx.r8.s64 + 2528;
	// fmsubs f1,f6,f7,f3
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 - ctx.f3.f64));
	// fmsubs f0,f4,f7,f3
	f0.f64 = double(float(ctx.f4.f64 * ctx.f7.f64 - ctx.f3.f64));
	// fmsubs f13,f12,f5,f2
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f5.f64 - ctx.f2.f64));
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmsubs f12,f10,f5,f2
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f5.f64 - ctx.f2.f64));
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fneg f11,f1
	ctx.f11.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
loc_825F79D4:
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v13,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v59,r0,r19
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,33
	ctx.r8.s64 = r11.s64 + 33;
	// lvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v57,r0,r21
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v55,r0,r20
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v58,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v53,v55,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v55,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r27,4(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// vmrghw128 v51,v56,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// vmrghw128 v50,v54,v52
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v49,v56,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vrsqrtefp128 v48,v60
	simde_mm_store_ps(v48.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v48,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v47,v63,v6
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vmsum3fp128 v46,v47,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v45,v47,v51
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v44,v47,v49
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v41,v43,v42
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v41,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82606170
	ctx.lr = 0x825F7A90;
	sub_82606170(ctx, base);
	// addi r6,r27,33
	ctx.r6.s64 = r27.s64 + 33;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82606170
	ctx.lr = 0x825F7AB0;
	sub_82606170(ctx, base);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// addi r5,r26,32
	ctx.r5.s64 = r26.s64 + 32;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// blt cr6,0x825f79d4
	if (cr6.lt) goto loc_825F79D4;
loc_825F7AC4:
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// vspltisw128 v40,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r10,r31,528
	ctx.r10.s64 = r31.s64 + 528;
	// li r11,8
	r11.s64 = 8;
	// lfs f0,-31400(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	f0.f64 = double(temp.f32);
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v38,v40,v39
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v38.f32, simde_mm_sub_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v38,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
loc_825F7B0C:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x825f7b2c
	if (cr6.lt) goto loc_825F7B2C;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_825F7B2C:
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x825f7b40
	if (cr6.lt) goto loc_825F7B40;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_825F7B40:
	// lfs f13,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x825f7b54
	if (cr6.lt) goto loc_825F7B54;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_825F7B54:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// bgt cr6,0x825f7b70
	if (cr6.gt) goto loc_825F7B70;
	// fmr f8,f13
	ctx.f8.f64 = ctx.f13.f64;
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_825F7B70:
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x825f7b84
	if (cr6.gt) goto loc_825F7B84;
	// fmr f9,f13
	ctx.f9.f64 = ctx.f13.f64;
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_825F7B84:
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// bgt cr6,0x825f7b98
	if (cr6.gt) goto loc_825F7B98;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_825F7B98:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x825f7b0c
	if (!cr0.eq) goto loc_825F7B0C;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r11,r31,656
	r11.s64 = r31.s64 + 656;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v36,r0,r8
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,1
	ctx.r6.s64 = 1;
	// vor128 v35,v36,v36
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// lvx128 v37,r0,r9
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v33,v34,v35
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_sub_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v35.f32)));
	// stvx128 v33,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// stfs f8,688(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 688, temp.u32);
	// stb r6,704(r31)
	PPC_STORE_U8(r31.u32 + 704, ctx.r6.u8);
loc_825F7C04:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_825F78A0) {
	__imp__sub_825F78A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// bl 0x823d91f4
	ctx.lr = 0x825F7C18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r29,r31,224
	r29.s64 = r31.s64 + 224;
	// addi r8,r11,2384
	ctx.r8.s64 = r11.s64 + 2384;
	// addi r30,r31,96
	r30.s64 = r31.s64 + 96;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vand128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// addi r6,r7,2352
	ctx.r6.s64 = ctx.r7.s64 + 2352;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v60,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r29,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v58,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v57,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r29,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v56,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v63,v55
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// stvx128 v54,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cea20
	ctx.lr = 0x825F7CA0;
	sub_821CEA20(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217c568
	ctx.lr = 0x825F7CA8;
	sub_8217C568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x8215e000
	ctx.lr = 0x825F7CB8;
	sub_8215E000(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,704(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 704);
	ctx.f12.f64 = double(temp.f32);
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,300(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 300, temp.u32);
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,288(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 288, temp.u32);
	// stfs f0,292(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// bl 0x82475ff8
	ctx.lr = 0x825F7CEC;
	sub_82475FF8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_825F7C10) {
	__imp__sub_825F7C10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F7CF4) {
	__imp__sub_825F7CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F7CF8) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x825F7D00;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d8
	ctx.lr = 0x825F7D08;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r3,r31,304
	ctx.r3.s64 = r31.s64 + 304;
	// lbz r11,752(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 752);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,706(r31)
	PPC_STORE_U8(r31.u32 + 706, ctx.r9.u8);
	// bl 0x825f74c8
	ctx.lr = 0x825F7D30;
	sub_825F74C8(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825F7D4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,704(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 704);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,348(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 348, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r11,r31,336
	r11.s64 = r31.s64 + 336;
	// lfs f31,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r31,432
	ctx.r3.s64 = r31.s64 + 432;
	// lfs f29,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f29.f64 = double(temp.f32);
	// addi r30,r31,224
	r30.s64 = r31.s64 + 224;
	// stfs f31,336(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// addi r28,r31,352
	r28.s64 = r31.s64 + 352;
	// stfs f31,340(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stfs f29,344(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lfs f12,708(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 708);
	ctx.f12.f64 = double(temp.f32);
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f30,14192(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f30.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmuls f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 * f30.f64));
	// stfs f31,352(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// stfs f31,356(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// stfs f30,360(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 360, temp.u32);
	// stfs f10,364(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 364, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F7DB8;
	sub_82475FF8(ctx, base);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F7DCC;
	sub_82475FF8(ctx, base);
	// lbz r3,706(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f81ac
	if (cr6.eq) goto loc_825F81AC;
	// addi r10,r29,736
	ctx.r10.s64 = r29.s64 + 736;
	// lfs f0,704(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 704);
	f0.f64 = double(temp.f32);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f12,708(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 708);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// lvlx128 v59,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lfs f11,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// lvlx128 v57,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f10,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// addi r29,r31,528
	r29.s64 = r31.s64 + 528;
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v56,r30,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v49,v57,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmulfp128 v55,v56,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v53,r30,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,544
	ctx.r7.s64 = 544;
	// lfs f9,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f9.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vmulfp128 v45,v53,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v49.f32)));
	// stfs f9,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v54,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v54,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vaddfp128 v48,v52,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v55.f32)));
	// stfs f10,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v51,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmulfp128 v47,v61,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v44,v48,v45
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v45.f32)));
	// li r4,560
	ctx.r4.s64 = 560;
	// vmulfp128 v42,v53,v46
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v46.f32)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fneg f8,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,576
	ctx.r9.s64 = 576;
	// li r8,592
	ctx.r8.s64 = 592;
	// li r6,608
	ctx.r6.s64 = 608;
	// lvlx128 v35,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v34,v35,0
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0xFF));
	// vaddfp128 v40,v44,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v47.f32)));
	// lfs f7,148(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmulfp128 v33,v56,v34
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v34.f32)));
	// lvlx128 v43,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v41,v43,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// stvx128 v40,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v39,v61,v41
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v41.f32)));
	// lvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v37,v38,v55
	simde_mm_store_ps(v37.f32, simde_mm_add_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v36,v37,v42
	simde_mm_store_ps(v36.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v42.f32)));
	// vaddfp128 v32,v36,v47
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v32,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v63,v55
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v61,v62,v45
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v45.f32)));
	// vaddfp128 v60,v61,v39
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v60,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v55
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v57,v58,v42
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v42.f32)));
	// vaddfp128 v56,v57,v39
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v56,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v55,v33
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v33.f32)));
	// li r5,624
	ctx.r5.s64 = 624;
	// li r7,640
	ctx.r7.s64 = 640;
	// addi r25,r1,144
	r25.s64 = ctx.r1.s64 + 144;
	// addi r24,r1,144
	r24.s64 = ctx.r1.s64 + 144;
	// addi r23,r1,144
	r23.s64 = ctx.r1.s64 + 144;
	// addi r22,r1,144
	r22.s64 = ctx.r1.s64 + 144;
	// addi r9,r31,368
	ctx.r9.s64 = r31.s64 + 368;
	// addi r3,r31,464
	ctx.r3.s64 = r31.s64 + 464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r28,r31,384
	r28.s64 = r31.s64 + 384;
	// addi r27,r31,400
	r27.s64 = r31.s64 + 400;
	// addi r26,r31,416
	r26.s64 = r31.s64 + 416;
	// vaddfp128 v53,v54,v45
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v45.f32)));
	// vaddfp128 v52,v53,v47
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v52,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v50,v51,v33
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v33.f32)));
	// vaddfp128 v49,v50,v42
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v42.f32)));
	// vaddfp128 v48,v49,v47
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v48,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v46,v47,v33
	simde_mm_store_ps(v46.f32, simde_mm_add_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v33.f32)));
	// vaddfp128 v45,v46,v45
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v45.f32)));
	// vaddfp128 v44,v45,v39
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v44,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v41,v43,v33
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v33.f32)));
	// vaddfp128 v40,v41,v42
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v42.f32)));
	// vaddfp128 v39,v40,v39
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v39,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64));
	// stfs f5,380(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// stfs f30,368(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f31,372(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// stfs f31,376(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// lvx128 v37,r0,r10
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,384(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// lfs f4,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f4.f64 = double(temp.f32);
	// stfs f31,388(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// stfs f31,392(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// stfs f4,396(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// lvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f3.f64 = double(temp.f32);
	// stfs f31,400(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f29,404(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// stfs f31,408(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 408, temp.u32);
	// stfs f3,412(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 412, temp.u32);
	// lvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f30
	ctx.f1.f64 = double(float(ctx.f2.f64 * f30.f64));
	// stfs f31,416(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 416, temp.u32);
	// stfs f30,420(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 420, temp.u32);
	// stfs f31,424(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 424, temp.u32);
	// stfs f1,428(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 428, temp.u32);
	// lvx128 v34,r0,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F801C;
	sub_82475FF8(ctx, base);
	// addi r3,r31,480
	ctx.r3.s64 = r31.s64 + 480;
	// lvx128 v33,r0,r28
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v33,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F8030;
	sub_82475FF8(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// lvx128 v32,r0,r27
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v32,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F8044;
	sub_82475FF8(ctx, base);
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82475ff8
	ctx.lr = 0x825F8058;
	sub_82475FF8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f0,-31400(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31400);
	f0.f64 = double(temp.f32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,8
	r11.s64 = 8;
	// lfs f8,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
loc_825F809C:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x825f80bc
	if (cr6.lt) goto loc_825F80BC;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_825F80BC:
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x825f80d0
	if (cr6.lt) goto loc_825F80D0;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_825F80D0:
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x825f80e4
	if (cr6.lt) goto loc_825F80E4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_825F80E4:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// bgt cr6,0x825f8100
	if (cr6.gt) goto loc_825F8100;
	// fmr f8,f13
	ctx.f8.f64 = ctx.f13.f64;
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_825F8100:
	// lfs f13,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x825f8114
	if (cr6.gt) goto loc_825F8114;
	// fmr f9,f13
	ctx.f9.f64 = ctx.f13.f64;
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_825F8114:
	// lfs f13,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// bgt cr6,0x825f8128
	if (cr6.gt) goto loc_825F8128;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
loc_825F8128:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x825f809c
	if (!cr0.eq) goto loc_825F809C;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r31,656
	r11.s64 = r31.s64 + 656;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v58,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,14884(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,688(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 688, temp.u32);
	// stb r5,704(r31)
	PPC_STORE_U8(r31.u32 + 704, ctx.r5.u8);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba24
	ctx.lr = 0x825F81A8;
	// b 0x823d9230
	return;
loc_825F81AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c560
	ctx.lr = 0x825F81B4;
	sub_8217C560(ctx, base);
	// bl 0x821797d0
	ctx.lr = 0x825F81B8;
	sub_821797D0(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// bl 0x8217c560
	ctx.lr = 0x825F81D4;
	sub_8217C560(ctx, base);
	// bl 0x82179830
	ctx.lr = 0x825F81D8;
	sub_82179830(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f30,f11
	f30.f64 = double(float(ctx.f11.f64));
	// bl 0x8217c560
	ctx.lr = 0x825F81F4;
	sub_8217C560(ctx, base);
	// bl 0x82179890
	ctx.lr = 0x825F81F8;
	sub_82179890(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f10,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f29,f9
	f29.f64 = double(float(ctx.f9.f64));
	// bl 0x8217c560
	ctx.lr = 0x825F8214;
	sub_8217C560(ctx, base);
	// bl 0x821798f0
	ctx.lr = 0x825F8218;
	sub_821798F0(ctx, base);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lfd f8,96(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f28,f7
	f28.f64 = double(float(ctx.f7.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x825F8244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fadds f1,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f29.f64 + f31.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,12(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x825F825C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F8274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fadds f1,f28,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f28.f64 + f30.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825F828C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f78a0
	ctx.lr = 0x825F8294;
	sub_825F78A0(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba24
	ctx.lr = 0x825F82A0;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_825F7CF8) {
	__imp__sub_825F7CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F82A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F82A4) {
	__imp__sub_825F82A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F82A8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,6904(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6904);
	// bl 0x82178430
	ctx.lr = 0x825F82C8;
	sub_82178430(ctx, base);
	// li r5,108
	ctx.r5.s64 = 108;
	// rlwinm r4,r31,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82178480
	ctx.lr = 0x825F82D8;
	sub_82178480(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,6896(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6896, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_825F82A8) {
	__imp__sub_825F82A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F82F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F82F4) {
	__imp__sub_825F82F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F82F8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,6904(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6904);
	// bl 0x82178430
	ctx.lr = 0x825F8320;
	sub_82178430(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// li r5,108
	ctx.r5.s64 = 108;
	// mullw r9,r10,r30
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82178480
	ctx.lr = 0x825F8338;
	sub_82178480(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,6896(r8)
	PPC_STORE_U32(ctx.r8.u32 + 6896, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_825F82F8) {
	__imp__sub_825F82F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x825F8370;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r11,6896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6896);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f8628
	if (cr6.eq) goto loc_825F8628;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lbz r7,127(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 127);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r9,-21764(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21764);
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x825f83a8
	if (cr6.eq) goto loc_825F83A8;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r10,-21840
	ctx.r6.s64 = ctx.r10.s64 + -21840;
	// b 0x825f83ac
	goto loc_825F83AC;
loc_825F83A8:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_825F83AC:
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fneg f28,f5
	f28.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// fneg f13,f6
	ctx.f13.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r7,r11,76
	ctx.r7.s64 = r11.s64 + 76;
	// li r9,8
	ctx.r9.s64 = 8;
	// lfs f31,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f31.f64 = double(temp.f32);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lfs f30,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f30.f64 = double(temp.f32);
	// stfs f2,0(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f3,4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f4,8(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f28,12(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f7,20(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stw r3,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r3.u32);
	// stfs f0,28(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f10,32(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stfs f30,36(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f31,40(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stfs f11,44(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// lfs f0,3796(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f12,48(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// stfs f0,52(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// stfs f0,56(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f8,60(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// stfs f9,64(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// stfs f1,68(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// stfs f0,72(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_825F8440:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bdnz 0x825f8440
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F8440;
	// lwz r11,6896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6896);
	// lfs f12,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f31,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f31.f64 = double(temp.f32);
	// lfs f30,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f30.f64 = double(temp.f32);
	// lfs f29,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f29.f64 = double(temp.f32);
	// beq cr6,0x825f84f0
	if (cr6.eq) goto loc_825F84F0;
	// stfs f2,108(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 108, temp.u32);
	// addi r8,r11,108
	ctx.r8.s64 = r11.s64 + 108;
	// stfs f3,112(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stfs f4,116(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// addi r8,r8,76
	ctx.r8.s64 = ctx.r8.s64 + 76;
	// stfs f5,120(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stfs f13,124(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// stfs f7,128(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stw r3,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r3.u32);
	// stfs f29,136(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f10,140(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f11,148(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f12,156(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// stfs f0,160(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f0,164(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f8,168(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f9,172(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// stfs f1,176(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// stfs f0,180(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_825F84D8:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x825f84d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F84D8;
	// lwz r11,6896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6896);
loc_825F84F0:
	// lfs f13,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f31,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f31.f64 = double(temp.f32);
	// lfs f30,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	f30.f64 = double(temp.f32);
	// beq cr6,0x825f8588
	if (cr6.eq) goto loc_825F8588;
	// stfs f2,216(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 216, temp.u32);
	// addi r8,r11,216
	ctx.r8.s64 = r11.s64 + 216;
	// stfs f3,220(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 220, temp.u32);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stfs f4,224(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 224, temp.u32);
	// addi r8,r8,76
	ctx.r8.s64 = ctx.r8.s64 + 76;
	// stfs f5,228(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 228, temp.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stfs f6,232(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 232, temp.u32);
	// stfs f7,236(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 236, temp.u32);
	// stw r3,240(r11)
	PPC_STORE_U32(r11.u32 + 240, ctx.r3.u32);
	// stfs f11,244(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 244, temp.u32);
	// stfs f30,248(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 248, temp.u32);
	// stfs f12,252(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 252, temp.u32);
	// stfs f31,256(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 256, temp.u32);
	// stfs f13,260(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// stfs f10,264(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
	// stfs f0,268(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 268, temp.u32);
	// stfs f0,272(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 272, temp.u32);
	// stfs f8,276(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 276, temp.u32);
	// stfs f9,280(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 280, temp.u32);
	// stfs f1,284(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 284, temp.u32);
	// stfs f0,288(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 288, temp.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_825F8570:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x825f8570
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F8570;
	// lwz r11,6896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6896);
loc_825F8588:
	// lfs f13,12(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f5,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f31,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f31.f64 = double(temp.f32);
	// beq cr6,0x825f8620
	if (cr6.eq) goto loc_825F8620;
	// stfs f2,324(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 324, temp.u32);
	// addi r9,r11,324
	ctx.r9.s64 = r11.s64 + 324;
	// stfs f3,328(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 328, temp.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stfs f4,332(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 332, temp.u32);
	// addi r9,r9,76
	ctx.r9.s64 = ctx.r9.s64 + 76;
	// stfs f28,336(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 336, temp.u32);
	// li r8,8
	ctx.r8.s64 = 8;
	// stfs f6,340(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 340, temp.u32);
	// stfs f7,344(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 344, temp.u32);
	// stw r3,348(r11)
	PPC_STORE_U32(r11.u32 + 348, ctx.r3.u32);
	// stfs f31,352(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 352, temp.u32);
	// stfs f5,356(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 356, temp.u32);
	// stfs f10,360(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 360, temp.u32);
	// stfs f11,364(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 364, temp.u32);
	// stfs f12,368(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 368, temp.u32);
	// stfs f13,372(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 372, temp.u32);
	// stfs f0,376(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 376, temp.u32);
	// stfs f0,380(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 380, temp.u32);
	// stfs f8,384(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 384, temp.u32);
	// stfs f9,388(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 388, temp.u32);
	// stfs f1,392(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 392, temp.u32);
	// stfs f0,396(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 396, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_825F8608:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x825f8608
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F8608;
	// lwz r11,6896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6896);
loc_825F8620:
	// addi r11,r11,432
	r11.s64 = r11.s64 + 432;
	// stw r11,6896(r31)
	PPC_STORE_U32(r31.u32 + 6896, r11.u32);
loc_825F8628:
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x825F8630;
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

PPC_WEAK_FUNC(sub_825F8358) {
	__imp__sub_825F8358(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8644) {
	__imp__sub_825F8644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8648) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// li r8,7
	ctx.r8.s64 = 7;
	// fneg f12,f1
	ctx.f12.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f1,-60(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r8,-100(r1)
	PPC_STORE_U32(ctx.r1.u32 + -100, ctx.r8.u32);
	// stw r8,-96(r1)
	PPC_STORE_U32(ctx.r1.u32 + -96, ctx.r8.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stfs f1,-48(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stfs f1,-36(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stfs f0,-76(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stfs f0,-72(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stfs f0,-64(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// li r31,6
	r31.s64 = 6;
	// stfs f0,-20(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r9,r11,6704
	ctx.r9.s64 = r11.s64 + 6704;
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f13,-52(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stw r10,-116(r1)
	PPC_STORE_U32(ctx.r1.u32 + -116, ctx.r10.u32);
	// stfs f13,-44(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stw r10,-108(r1)
	PPC_STORE_U32(ctx.r1.u32 + -108, ctx.r10.u32);
	// stfs f13,-40(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stw r6,-128(r1)
	PPC_STORE_U32(ctx.r1.u32 + -128, ctx.r6.u32);
	// stfs f12,-80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stw r4,-124(r1)
	PPC_STORE_U32(ctx.r1.u32 + -124, ctx.r4.u32);
	// stfs f12,-68(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stw r3,-120(r1)
	PPC_STORE_U32(ctx.r1.u32 + -120, ctx.r3.u32);
	// stfs f12,-56(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stw r6,-112(r1)
	PPC_STORE_U32(ctx.r1.u32 + -112, ctx.r6.u32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// addi r11,r1,-124
	r11.s64 = ctx.r1.s64 + -124;
	// stfs f12,-28(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stw r7,-104(r1)
	PPC_STORE_U32(ctx.r1.u32 + -104, ctx.r7.u32);
	// stfs f1,-24(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stw r7,-92(r1)
	PPC_STORE_U32(ctx.r1.u32 + -92, ctx.r7.u32);
	// stw r5,-88(r1)
	PPC_STORE_U32(ctx.r1.u32 + -88, ctx.r5.u32);
	// stw r31,-84(r1)
	PPC_STORE_U32(ctx.r1.u32 + -84, r31.u32);
loc_825F8708:
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,-80
	ctx.r6.s64 = ctx.r1.s64 + -80;
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// rlwinm r31,r3,3,0,28
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsx f13,r5,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,-80
	ctx.r3.s64 = ctx.r1.s64 + -80;
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f9,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// add r8,r5,r6
	ctx.r8.u64 = ctx.r5.u64 + ctx.r6.u64;
	// lfsx f7,r4,r7
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	ctx.f7.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// lfsx f5,r31,r3
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f3,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// add r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 + ctx.r7.u64;
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fadds f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 + f0.f64));
	// fadds f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 + f0.f64));
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fadds f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 + f0.f64));
	// lfs f8,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// add r8,r31,r3
	ctx.r8.u64 = r31.u64 + ctx.r3.u64;
	// fmuls f11,f8,f0
	ctx.f11.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fadds f6,f6,f0
	ctx.f6.f64 = double(float(ctx.f6.f64 + f0.f64));
	// fadds f4,f4,f0
	ctx.f4.f64 = double(float(ctx.f4.f64 + f0.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fadds f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 + f0.f64));
	// lfs f10,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f31,f10,f0
	f31.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f12,0(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fadds f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f9,0(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fadds f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 + f0.f64));
	// stfs f1,0(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f2,0(r9)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f12,0(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f7,0(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f8,0(r9)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f4,0(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f5,0(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x825f8708
	if (!cr0.eq) goto loc_825F8708;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8648) {
	__imp__sub_825F8648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8840) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x825F8848;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9b8
	ctx.lr = 0x825F8850;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwz r10,6896(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 6896);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f89dc
	if (cr6.eq) goto loc_825F89DC;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lbz r7,127(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 127);
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r9,-21764(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21764);
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// beq cr6,0x825f8888
	if (cr6.eq) goto loc_825F8888;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r3,r11,-21824
	ctx.r3.s64 = r11.s64 + -21824;
	// b 0x825f888c
	goto loc_825F888C;
loc_825F8888:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825F888C:
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f11,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r11,r8,6704
	r11.s64 = ctx.r8.s64 + 6704;
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f24,f11,f10
	f24.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f12,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// fsubs f27,f0,f13
	f27.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f26,f12,f13
	f26.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f10,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fsubs f25,f11,f10
	f25.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f0,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lfs f13,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f22,f0,f11
	f22.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsubs f23,f13,f12
	f23.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
loc_825F88FC:
	// lfs f29,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f29.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f28,-4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4);
	f28.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f11,f29,f22,f11
	ctx.f11.f64 = double(float(f29.f64 * f22.f64 + ctx.f11.f64));
	// lfs f31,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f31.f64 = double(temp.f32);
	// fmadds f10,f28,f24,f10
	ctx.f10.f64 = double(float(f28.f64 * f24.f64 + ctx.f10.f64));
	// lfs f30,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f30.f64 = double(temp.f32);
	// fmadds f31,f29,f23,f31
	f31.f64 = double(float(f29.f64 * f23.f64 + f31.f64));
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f30,f28,f25,f30
	f30.f64 = double(float(f28.f64 * f25.f64 + f30.f64));
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// lfs f21,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f21.f64 = double(temp.f32);
	// fmuls f12,f12,f5
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f5.f64));
	// lfs f20,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f20.f64 = double(temp.f32);
	// fmadds f29,f29,f26,f21
	f29.f64 = double(float(f29.f64 * f26.f64 + f21.f64));
	// fmadds f28,f28,f27,f20
	f28.f64 = double(float(f28.f64 * f27.f64 + f20.f64));
	// beq cr6,0x825f89c4
	if (cr6.eq) goto loc_825F89C4;
	// add r11,r7,r10
	r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stfsx f2,r7,r10
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, temp.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r9,r11,76
	ctx.r9.s64 = r11.s64 + 76;
	// li r8,8
	ctx.r8.s64 = 8;
	// stfs f3,4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f4,8(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f7,20(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stw r30,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r30.u32);
	// stfs f28,28(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f29,32(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stfs f30,36(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f31,40(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stfs f10,44(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// stfs f11,48(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// stfs f0,52(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// stfs f0,56(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stfs f8,60(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// stfs f9,64(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// stfs f1,68(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// stfs f0,72(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_825F89AC:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x825f89ac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F89AC;
	// lwz r10,6896(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 6896);
loc_825F89C4:
	// addi r7,r7,108
	ctx.r7.s64 = ctx.r7.s64 + 108;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// cmpwi cr6,r7,1296
	cr6.compare<int32_t>(ctx.r7.s32, 1296, xer);
	// blt cr6,0x825f88fc
	if (cr6.lt) goto loc_825F88FC;
	// addi r11,r10,1296
	r11.s64 = ctx.r10.s64 + 1296;
	// stw r11,6896(r29)
	PPC_STORE_U32(r29.u32 + 6896, r11.u32);
loc_825F89DC:
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba04
	ctx.lr = 0x825F89E4;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F8840) {
	__imp__sub_825F8840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F89E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x821784a8
	sub_821784A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_825F89E8) {
	__imp__sub_825F89E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F89EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F89EC) {
	__imp__sub_825F89EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F89F0) {
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
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r11,-22072
	ctx.r3.s64 = r11.s64 + -22072;
	// bl 0x8217aac0
	ctx.lr = 0x825F8A0C;
	sub_8217AAC0(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r3,6904(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6904, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F89F0) {
	__imp__sub_825F89F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8A24) {
	__imp__sub_825F8A24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A28) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r3,6904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6904);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f8a54
	if (cr6.eq) goto loc_825F8A54;
	// bl 0x821783e8
	ctx.lr = 0x825F8A4C;
	sub_821783E8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,6904(r31)
	PPC_STORE_U32(r31.u32 + 6904, r11.u32);
loc_825F8A54:
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

PPC_WEAK_FUNC(sub_825F8A28) {
	__imp__sub_825F8A28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-21800
	ctx.r9.s64 = r11.s64 + -21800;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r3,-21804(r8)
	PPC_STORE_U32(ctx.r8.u32 + -21804, ctx.r3.u32);
	// stw r11,-21764(r7)
	PPC_STORE_U32(ctx.r7.u32 + -21764, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8A68) {
	__imp__sub_825F8A68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8A8C) {
	__imp__sub_825F8A8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,-21764(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21764);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8A90) {
	__imp__sub_825F8A90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8A9C) {
	__imp__sub_825F8A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fsel f6,f12,f0,f13
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f6,0(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f5,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f11,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f5.f64));
	// fsel f3,f4,f5,f11
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f5.f64 : ctx.f11.f64;
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f2,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f10,f2
	ctx.f1.f64 = double(float(ctx.f10.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f10
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : ctx.f10.f64;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f9,f13
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsel f11,f12,f9,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f9.f64 : ctx.f13.f64;
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f8,f10
	ctx.f9.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// fsel f8,f9,f8,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f8.f64 : ctx.f10.f64;
	// stfs f8,20(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f6,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsel f4,f5,f7,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f6.f64;
	// stfs f4,24(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8AA0) {
	__imp__sub_825F8AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8B1C) {
	__imp__sub_825F8B1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8B20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x825F8B28;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rlwinm r8,r6,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFF;
	// lbz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// rlwinm r31,r6,24,24,31
	r31.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// lbz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// extsb r30,r10
	r30.s64 = ctx.r10.s8;
	// lbz r29,0(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mullw r9,r30,r11
	ctx.r9.s64 = int64_t(r30.s32) * int64_t(r11.s32);
	// srawi r9,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 6;
	// extsb r30,r29
	r30.s64 = r29.s8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r30,r30,r11
	r30.s64 = int64_t(r30.s32) * int64_t(r11.s32);
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// lbz r29,5(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lbz r9,5(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 5);
	// lbz r10,1(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// lbz r27,1(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r28,r10
	r28.s64 = ctx.r10.s8;
	// extsb r29,r29
	r29.s64 = r29.s8;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mullw r9,r29,r28
	ctx.r9.s64 = int64_t(r29.s32) * int64_t(r28.s32);
	// srawi r9,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 6;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r11,255
	r11.s64 = 255;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// lbz r29,6(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// lbz r9,6(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 6);
	// lbz r10,2(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 2);
	// extsb r26,r10
	r26.s64 = ctx.r10.s8;
	// extsb r29,r29
	r29.s64 = r29.s8;
	// lbz r25,2(r4)
	r25.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mullw r9,r29,r26
	ctx.r9.s64 = int64_t(r29.s32) * int64_t(r26.s32);
	// srawi r9,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 6;
	// extsb r29,r27
	r29.s64 = r27.s8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r29,r29,r28
	r29.s64 = int64_t(r29.s32) * int64_t(r28.s32);
	// stb r10,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r10.u8);
	// lbz r10,3(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 3);
	// lbz r5,7(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 7);
	// lbz r28,3(r4)
	r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// lbz r4,7(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// extsb r10,r25
	ctx.r10.s64 = r25.s8;
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// srawi r9,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 6;
	// mullw r10,r10,r26
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// srawi r30,r30,6
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x3F) != 0);
	r30.s64 = r30.s32 >> 6;
	// srawi r29,r29,6
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x3F) != 0);
	r29.s64 = r29.s32 >> 6;
	// srawi r10,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 6;
	// extsb r30,r30
	r30.s64 = r30.s8;
	// extsb r27,r10
	r27.s64 = ctx.r10.s8;
	// extsb r29,r29
	r29.s64 = r29.s8;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mullw r8,r30,r8
	ctx.r8.s64 = int64_t(r30.s32) * int64_t(ctx.r8.s32);
	// mullw r5,r29,r31
	ctx.r5.s64 = int64_t(r29.s32) * int64_t(r31.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r6,r27,r6
	ctx.r6.s64 = int64_t(r27.s32) * int64_t(ctx.r6.s32);
	// divw r9,r8,r11
	ctx.r9.s32 = ctx.r8.s32 / r11.s32;
	// divw r8,r5,r11
	ctx.r8.s32 = ctx.r5.s32 / r11.s32;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// divw r6,r6,r11
	ctx.r6.s32 = ctx.r6.s32 / r11.s32;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stb r5,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r5.u8);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// extsb r6,r28
	ctx.r6.s64 = r28.s8;
	// stb r9,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// stb r8,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r8.u8);
	// mullw r5,r6,r4
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r4.s32);
	// srawi r4,r5,6
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 6;
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// mullw r8,r9,r7
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// divw r7,r8,r11
	ctx.r7.s32 = ctx.r8.s32 / r11.s32;
	// stb r7,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, ctx.r7.u8);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_825F8B20) {
	__imp__sub_825F8B20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8C70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x825F8C84;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x825f8ca8
	if (!cr6.eq) goto loc_825F8CA8;
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
loc_825F8CA8:
	// bl 0x825ef518
	ctx.lr = 0x825F8CAC;
	sub_825EF518(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x825f8cd8
	if (!cr6.eq) goto loc_825F8CD8;
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x825f8cd8
	if (!cr6.eq) goto loc_825F8CD8;
	// lfs f13,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// b 0x825f8cdc
	goto loc_825F8CDC;
loc_825F8CD8:
	// lfs f12,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
loc_825F8CDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lfs f5,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// li r9,6
	ctx.r9.s64 = 6;
	// lfs f3,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// lfs f30,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f30.f64 = double(temp.f32);
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// lfs f29,132(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f29.f64 = double(temp.f32);
	// fmuls f1,f3,f13
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfs f28,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f28.f64 = double(temp.f32);
	// fmuls f0,f30,f0
	f0.f64 = double(float(f30.f64 * f0.f64));
	// lfs f27,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f27.f64 = double(temp.f32);
	// fmuls f13,f29,f13
	ctx.f13.f64 = double(float(f29.f64 * ctx.f13.f64));
	// fmadds f7,f7,f12,f6
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmadds f6,f8,f11,f4
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fmadds f4,f3,f12,f2
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f2.f64));
	// fmadds f3,f5,f11,f1
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmadds f2,f29,f12,f0
	ctx.f2.f64 = double(float(f29.f64 * ctx.f12.f64 + f0.f64));
	// fmadds f1,f30,f11,f13
	ctx.f1.f64 = double(float(f30.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fmuls f0,f7,f31
	f0.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fmuls f13,f6,f31
	ctx.f13.f64 = double(float(ctx.f6.f64 * f31.f64));
	// fmuls f12,f4,f31
	ctx.f12.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fmuls f11,f3,f31
	ctx.f11.f64 = double(float(ctx.f3.f64 * f31.f64));
	// fadds f8,f2,f28
	ctx.f8.f64 = double(float(ctx.f2.f64 + f28.f64));
	// fadds f5,f1,f27
	ctx.f5.f64 = double(float(ctx.f1.f64 + f27.f64));
	// fmadds f4,f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f9.f64 + f0.f64));
	// stfs f4,124(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmadds f3,f3,f9,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f9.f64 + ctx.f13.f64));
	// stfs f3,120(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fadds f2,f0,f12
	ctx.f2.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fadds f1,f13,f11
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// fmadds f0,f6,f10,f11
	f0.f64 = double(float(ctx.f6.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmadds f13,f7,f10,f12
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f12.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f12,f2,f8
	ctx.f12.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fadds f11,f1,f5
	ctx.f11.f64 = double(float(ctx.f1.f64 + ctx.f5.f64));
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_825F8DAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x825f8dac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825F8DAC;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f10,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f9,20(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x825F8DF4;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8C70) {
	__imp__sub_825F8C70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8E04) {
	__imp__sub_825F8E04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8E08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x825f8e64
	if (cr6.eq) goto loc_825F8E64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,21384
	ctx.r10.s64 = ctx.r10.s64 + 21384;
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r7,r10,44
	ctx.r7.s64 = ctx.r10.s64 + 44;
	// lbzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825f8e64
	if (cr6.eq) goto loc_825F8E64;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r10,261
	ctx.r9.s64 = ctx.r10.s64 + 261;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_825F8E64:
	// addi r3,r3,1060
	ctx.r3.s64 = ctx.r3.s64 + 1060;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F8E08) {
	__imp__sub_825F8E08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F8E6C) {
	__imp__sub_825F8E6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8E70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lbz r10,14280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f8ef8
	if (cr6.eq) goto loc_825F8EF8;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6588);
	// bl 0x825f8e08
	ctx.lr = 0x825F8E9C;
	sub_825F8E08(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825f8ee4
	if (cr6.eq) goto loc_825F8EE4;
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825f8ee8
	if (cr6.eq) goto loc_825F8EE8;
loc_825F8EE4:
	// li r11,0
	r11.s64 = 0;
loc_825F8EE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x825f8efc
	if (!cr6.eq) goto loc_825F8EFC;
loc_825F8EF8:
	// li r11,0
	r11.s64 = 0;
loc_825F8EFC:
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

PPC_WEAK_FUNC(sub_825F8E70) {
	__imp__sub_825F8E70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8F10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lbz r10,14280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f8f98
	if (cr6.eq) goto loc_825F8F98;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6588);
	// bl 0x825f8e08
	ctx.lr = 0x825F8F3C;
	sub_825F8E08(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x825f8f84
	if (!cr6.eq) goto loc_825F8F84;
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x825f8f88
	if (!cr6.eq) goto loc_825F8F88;
loc_825F8F84:
	// li r11,0
	r11.s64 = 0;
loc_825F8F88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x825f8f9c
	if (!cr6.eq) goto loc_825F8F9C;
loc_825F8F98:
	// li r11,0
	r11.s64 = 0;
loc_825F8F9C:
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

PPC_WEAK_FUNC(sub_825F8F10) {
	__imp__sub_825F8F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F8FB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lbz r10,14280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f9004
	if (cr6.eq) goto loc_825F9004;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,6588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6588);
	// bl 0x825f8e08
	ctx.lr = 0x825F8FDC;
	sub_825F8E08(ctx, base);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// li r11,1
	r11.s64 = 1;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x825f9008
	if (!cr6.eq) goto loc_825F9008;
loc_825F9004:
	// li r11,0
	r11.s64 = 0;
loc_825F9008:
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

PPC_WEAK_FUNC(sub_825F8FB0) {
	__imp__sub_825F8FB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F901C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F901C) {
	__imp__sub_825F901C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,184(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// stb r10,173(r11)
	PPC_STORE_U8(r11.u32 + 173, ctx.r10.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,8(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_825F9020) {
	__imp__sub_825F9020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9060) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F9060) {
	__imp__sub_825F9060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F9064) {
	__imp__sub_825F9064(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9068) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,8(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x825f908c
	if (cr6.eq) goto loc_825F908C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x825f9090
	if (!cr6.eq) goto loc_825F9090;
loc_825F908C:
	// li r11,1
	r11.s64 = 1;
loc_825F9090:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lhz r11,16(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lhz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 164);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// li r11,0
	r11.s64 = 0;
	// sth r11,164(r3)
	PPC_STORE_U16(ctx.r3.u32 + 164, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F9068) {
	__imp__sub_825F9068(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F90C0) {
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
	ctx.lr = 0x825F90C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r29,r4,16
	r29.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bge cr6,0x825f9170
	if (!cr6.lt) goto loc_825F9170;
	// lhz r11,164(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 164);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// beq cr6,0x825f9170
	if (cr6.eq) goto loc_825F9170;
	// clrlwi r28,r5,24
	r28.u64 = ctx.r5.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
loc_825F90F8:
	// lhz r11,164(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 164);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,164(r31)
	PPC_STORE_U16(r31.u32 + 164, ctx.r8.u16);
	// lhz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// blt cr6,0x825f913c
	if (cr6.lt) goto loc_825F913C;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825f9138
	if (cr6.eq) goto loc_825F9138;
loc_825F9124:
	// stb r30,177(r11)
	PPC_STORE_U8(r11.u32 + 177, r30.u8);
	// stw r30,180(r11)
	PPC_STORE_U32(r11.u32 + 180, r30.u32);
	// lwz r11,192(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825f9124
	if (!cr6.eq) goto loc_825F9124;
loc_825F9138:
	// sth r30,164(r31)
	PPC_STORE_U16(r31.u32 + 164, r30.u16);
loc_825F913C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne cr6,0x825f9154
	if (!cr6.eq) goto loc_825F9154;
	// bl 0x825fdbc8
	ctx.lr = 0x825F9150;
	sub_825FDBC8(ctx, base);
	// b 0x825f9164
	goto loc_825F9164;
loc_825F9154:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F9164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F9164:
	// lhz r11,164(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 164);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x825f90f8
	if (!cr6.eq) goto loc_825F90F8;
loc_825F9170:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F90C0) {
	__imp__sub_825F90C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9178) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r11,164(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 164);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lhz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x825f91b4
	if (cr6.lt) goto loc_825F91B4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_825F91B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r30,172(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 172);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// stb r9,172(r31)
	PPC_STORE_U8(r31.u32 + 172, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825F91D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,172(r31)
	PPC_STORE_U8(r31.u32 + 172, r30.u8);
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

PPC_WEAK_FUNC(sub_825F9178) {
	__imp__sub_825F9178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F91F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F91F4) {
	__imp__sub_825F91F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F91F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r11,164(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bne cr6,0x825f922c
	if (!cr6.eq) goto loc_825F922C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// addis r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 65536;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// clrlwi r4,r7,16
	ctx.r4.u64 = ctx.r7.u32 & 0xFFFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_825F922C:
	// addis r9,r11,1
	ctx.r9.s64 = r11.s64 + 65536;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_825F91F8) {
	__imp__sub_825F91F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9240) {
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
	ctx.lr = 0x825F9248;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x825F9268;
	sub_821C9790(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825F9290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r10,r10,28088
	ctx.r10.s64 = ctx.r10.s64 + 28088;
loc_825F929C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x825f92c0
	if (cr6.eq) goto loc_825F92C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x825f929c
	if (cr6.eq) goto loc_825F929C;
loc_825F92C0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x825f92d8
	if (!cr6.eq) goto loc_825F92D8;
	// li r11,0
	r11.s64 = 0;
	// stw r11,216(r30)
	PPC_STORE_U32(r30.u32 + 216, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_825F92D8:
	// lwz r3,160(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f92fc
	if (cr6.eq) goto loc_825F92FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825F92FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825F92FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_825F9240) {
	__imp__sub_825F9240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F9304) {
	__imp__sub_825F9304(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_825F9308) {
	__imp__sub_825F9308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9328) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F9328) {
	__imp__sub_825F9328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F932C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F932C) {
	__imp__sub_825F932C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// lhz r11,200(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 200);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x825f934c
	if (!cr6.lt) goto loc_825F934C;
	// lwz r3,188(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	// b 0x825f9350
	goto loc_825F9350;
loc_825F934C:
	// lwz r3,204(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 204);
loc_825F9350:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825f9374
	if (cr6.eq) goto loc_825F9374;
loc_825F9358:
	// lhz r11,166(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 166);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x825f937c
	if (cr6.eq) goto loc_825F937C;
	// bgt cr6,0x825f9374
	if (cr6.gt) goto loc_825F9374;
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825f9358
	if (!cr6.eq) goto loc_825F9358;
loc_825F9374:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_825F937C:
	// stw r3,204(r9)
	PPC_STORE_U32(ctx.r9.u32 + 204, ctx.r3.u32);
	// lhz r11,166(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 166);
	// sth r11,200(r9)
	PPC_STORE_U16(ctx.r9.u32 + 200, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_825F9330) {
	__imp__sub_825F9330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F938C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F938C) {
	__imp__sub_825F938C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F9390) {
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
	ctx.lr = 0x825F9398;
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
	// lwz r31,212(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825f93e4
	if (cr6.eq) goto loc_825F93E4;
loc_825F93B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 & r29.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825f93d8
	if (cr6.eq) goto loc_825F93D8;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82603158
	ctx.lr = 0x825F93D8;
	sub_82603158(ctx, base);
loc_825F93D8:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825f93b4
	if (!cr6.eq) goto loc_825F93B4;
loc_825F93E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_825F9390) {
	__imp__sub_825F9390(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F93EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_825F93EC) {
	__imp__sub_825F93EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_825F93F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,174(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 174);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f9408
	if (cr6.eq) goto loc_825F9408;
	// stb r11,172(r3)
	PPC_STORE_U8(ctx.r3.u32 + 172, r11.u8);
	// stb r11,174(r3)
	PPC_STORE_U8(ctx.r3.u32 + 174, r11.u8);
loc_825F9408:
	// lbz r10,173(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 173);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825f9420
	if (cr6.eq) goto loc_825F9420;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,173(r3)
	PPC_STORE_U8(ctx.r3.u32 + 173, r11.u8);
	// stb r10,172(r3)
	PPC_STORE_U8(ctx.r3.u32 + 172, ctx.r10.u8);
loc_825F9420:
	// lbz r11,172(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_825F93F0) {
	__imp__sub_825F93F0(ctx, base);
}

