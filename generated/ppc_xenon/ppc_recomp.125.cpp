#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8261EBB8"))) PPC_WEAK_FUNC(sub_8261EBB8);
PPC_FUNC_IMPL(__imp__sub_8261EBB8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8261ebf4
	if (!cr6.gt) goto loc_8261EBF4;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfd f2,-23152(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -23152);
	// bl 0x823dc480
	ctx.lr = 0x8261EBE0;
	sub_823DC480(ctx, base);
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
loc_8261EBF4:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8261ec24
	if (!cr6.lt) goto loc_8261EC24;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lfd f2,-23152(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -23152);
	// bl 0x823dc480
	ctx.lr = 0x8261EC0C;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8261EC24:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261EC38"))) PPC_WEAK_FUNC(sub_8261EC38);
PPC_FUNC_IMPL(__imp__sub_8261EC38) {
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
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r5,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r5.u8);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// beq cr6,0x8261ec7c
	if (cr6.eq) goto loc_8261EC7C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x8261ecac
	goto loc_8261ECAC;
loc_8261EC7C:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ec78
	ctx.lr = 0x8261EC90;
	sub_8244EC78(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ec78
	ctx.lr = 0x8261ECA8;
	sub_8244EC78(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_8261ECAC:
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

__attribute__((alias("__imp__sub_8261ECC4"))) PPC_WEAK_FUNC(sub_8261ECC4);
PPC_FUNC_IMPL(__imp__sub_8261ECC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261ECC8"))) PPC_WEAK_FUNC(sub_8261ECC8);
PPC_FUNC_IMPL(__imp__sub_8261ECC8) {
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
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8261ecf8
	if (!cr6.eq) goto loc_8261ECF8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8244eee0
	ctx.lr = 0x8261ECF0;
	sub_8244EEE0(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8244eee0
	ctx.lr = 0x8261ECF8;
	sub_8244EEE0(ctx, base);
loc_8261ECF8:
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

__attribute__((alias("__imp__sub_8261ED0C"))) PPC_WEAK_FUNC(sub_8261ED0C);
PPC_FUNC_IMPL(__imp__sub_8261ED0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261ED10"))) PPC_WEAK_FUNC(sub_8261ED10);
PPC_FUNC_IMPL(__imp__sub_8261ED10) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261ED1C"))) PPC_WEAK_FUNC(sub_8261ED1C);
PPC_FUNC_IMPL(__imp__sub_8261ED1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261ED20"))) PPC_WEAK_FUNC(sub_8261ED20);
PPC_FUNC_IMPL(__imp__sub_8261ED20) {
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
	ctx.lr = 0x8261ED28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821ce100
	ctx.lr = 0x8261ED3C;
	sub_821CE100(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8261edac
	if (!cr6.eq) goto loc_8261EDAC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// ble cr6,0x8261ee48
	if (!cr6.gt) goto loc_8261EE48;
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r30,4
	ctx.r10.s64 = r30.s64 + 4;
	// beq cr6,0x8261ed88
	if (cr6.eq) goto loc_8261ED88;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x821ce128
	ctx.lr = 0x8261ED74;
	sub_821CE128(ctx, base);
	// subfic r4,r30,1
	xer.ca = r30.u32 <= 1;
	ctx.r4.s64 = 1 - r30.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x8261ED80;
	sub_821CE080(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8261ED88:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r3,r9,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// bl 0x8244ed10
	ctx.lr = 0x8261ED98;
	sub_8244ED10(ctx, base);
	// subfic r4,r30,1
	xer.ca = r30.u32 <= 1;
	ctx.r4.s64 = 1 - r30.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x8261EDA4;
	sub_821CE080(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8261EDAC:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261ee34
	if (cr6.eq) goto loc_8261EE34;
	// addi r10,r30,4
	ctx.r10.s64 = r30.s64 + 4;
	// li r11,8
	r11.s64 = 8;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 + r31.u64;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8261ee1c
	if (!cr6.eq) goto loc_8261EE1C;
loc_8261EDD4:
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8261edfc
	if (!cr6.lt) goto loc_8261EDFC;
loc_8261EDE4:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// blt cr6,0x8261ede4
	if (cr6.lt) goto loc_8261EDE4;
loc_8261EDFC:
	// cmplwi cr6,r11,1024
	cr6.compare<uint32_t>(r11.u32, 1024, xer);
	// bge cr6,0x8261ee08
	if (!cr6.lt) goto loc_8261EE08;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_8261EE08:
	// lwsync 
	// db16cyc 
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8261edd4
	if (cr6.eq) goto loc_8261EDD4;
loc_8261EE1C:
	// bl 0x821ce100
	ctx.lr = 0x8261EE20;
	sub_821CE100(ctx, base);
	// subfic r4,r30,1
	xer.ca = r30.u32 <= 1;
	ctx.r4.s64 = 1 - r30.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x8261EE2C;
	sub_821CE080(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8261EE34:
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// li r4,-1
	ctx.r4.s64 = -1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82135db8
	ctx.lr = 0x8261EE48;
	sub_82135DB8(ctx, base);
loc_8261EE48:
	// subfic r4,r30,1
	xer.ca = r30.u32 <= 1;
	ctx.r4.s64 = 1 - r30.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x8261EE54;
	sub_821CE080(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8261EE5C"))) PPC_WEAK_FUNC(sub_8261EE5C);
PPC_FUNC_IMPL(__imp__sub_8261EE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261EE60"))) PPC_WEAK_FUNC(sub_8261EE60);
PPC_FUNC_IMPL(__imp__sub_8261EE60) {
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
	// bl 0x821daa30
	ctx.lr = 0x8261EE78;
	sub_821DAA30(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-22884
	ctx.r10.s64 = r11.s64 + -22884;
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

__attribute__((alias("__imp__sub_8261EE9C"))) PPC_WEAK_FUNC(sub_8261EE9C);
PPC_FUNC_IMPL(__imp__sub_8261EE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261EEA0"))) PPC_WEAK_FUNC(sub_8261EEA0);
PPC_FUNC_IMPL(__imp__sub_8261EEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-22884
	ctx.r10.s64 = r11.s64 + -22884;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821daaa0
	sub_821DAAA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261EEB0"))) PPC_WEAK_FUNC(sub_8261EEB0);
PPC_FUNC_IMPL(__imp__sub_8261EEB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24108
	ctx.r4.s64 = r11.s64 + 24108;
	// b 0x821dbbc8
	sub_821DBBC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261EEC0"))) PPC_WEAK_FUNC(sub_8261EEC0);
PPC_FUNC_IMPL(__imp__sub_8261EEC0) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821bdcf8
	ctx.lr = 0x8261EEE0;
	sub_821BDCF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821bdd08
	ctx.lr = 0x8261EEEC;
	sub_821BDD08(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x8261eefc
	if (!cr6.lt) goto loc_8261EEFC;
	// li r11,0
	r11.s64 = 0;
loc_8261EEFC:
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

__attribute__((alias("__imp__sub_8261EF18"))) PPC_WEAK_FUNC(sub_8261EF18);
PPC_FUNC_IMPL(__imp__sub_8261EF18) {
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
	// addi r10,r11,-22884
	ctx.r10.s64 = r11.s64 + -22884;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821daaa0
	ctx.lr = 0x8261EF44;
	sub_821DAAA0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261ef5c
	if (cr6.eq) goto loc_8261EF5C;
	// bl 0x82130588
	ctx.lr = 0x8261EF58;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8261EF5C:
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

__attribute__((alias("__imp__sub_8261EF74"))) PPC_WEAK_FUNC(sub_8261EF74);
PPC_FUNC_IMPL(__imp__sub_8261EF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261EF78"))) PPC_WEAK_FUNC(sub_8261EF78);
PPC_FUNC_IMPL(__imp__sub_8261EF78) {
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
	ctx.lr = 0x8261EF80;
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
	// beq cr6,0x8261f00c
	if (cr6.eq) goto loc_8261F00C;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_8261EF9C:
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsb r11,r4
	r11.s64 = ctx.r4.s8;
	// cmpwi cr6,r11,115
	cr6.compare<int32_t>(r11.s32, 115, xer);
	// bne cr6,0x8261efb8
	if (!cr6.eq) goto loc_8261EFB8;
	// bl 0x821dbf78
	ctx.lr = 0x8261EFB4;
	sub_821DBF78(ctx, base);
	// b 0x8261effc
	goto loc_8261EFFC;
loc_8261EFB8:
	// cmpwi cr6,r11,83
	cr6.compare<int32_t>(r11.s32, 83, xer);
	// bne cr6,0x8261efd0
	if (!cr6.eq) goto loc_8261EFD0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821dc038
	ctx.lr = 0x8261EFCC;
	sub_821DC038(ctx, base);
	// b 0x8261effc
	goto loc_8261EFFC;
loc_8261EFD0:
	// cmpwi cr6,r11,119
	cr6.compare<int32_t>(r11.s32, 119, xer);
	// bne cr6,0x8261efe8
	if (!cr6.eq) goto loc_8261EFE8;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821dbd48
	ctx.lr = 0x8261EFE4;
	sub_821DBD48(ctx, base);
	// b 0x8261effc
	goto loc_8261EFFC;
loc_8261EFE8:
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821db8e8
	ctx.lr = 0x8261EFF0;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f018
	if (cr6.eq) goto loc_8261F018;
loc_8261EFFC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8261ef9c
	if (!cr6.eq) goto loc_8261EF9C;
loc_8261F00C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8261F018:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8261F024"))) PPC_WEAK_FUNC(sub_8261F024);
PPC_FUNC_IMPL(__imp__sub_8261F024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F028"))) PPC_WEAK_FUNC(sub_8261F028);
PPC_FUNC_IMPL(__imp__sub_8261F028) {
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
	ctx.lr = 0x8261F030;
	// addi r31,r1,-1360
	r31.s64 = ctx.r1.s64 + -1360;
	// stwu r1,-1360(r1)
	ea = -1360 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c7190
	ctx.lr = 0x8261F048;
	sub_821C7190(ctx, base);
	// li r27,1
	r27.s64 = 1;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stb r27,1103(r30)
	PPC_STORE_U8(r30.u32 + 1103, r27.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24108
	ctx.r4.s64 = r11.s64 + 24108;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x8261F064;
	sub_821DBBC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8261f2cc
	if (!cr6.eq) goto loc_8261F2CC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// addi r4,r11,24104
	ctx.r4.s64 = r11.s64 + 24104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8261ef78
	ctx.lr = 0x8261F084;
	sub_8261EF78(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8261f1b0
	if (!cr6.eq) goto loc_8261F1B0;
	// lwz r29,1096(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bdcf8
	ctx.lr = 0x8261F09C;
	sub_821BDCF8(ctx, base);
	// subf r28,r29,r3
	r28.s64 = ctx.r3.s64 - r29.s64;
loc_8261F0A0:
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8261f0c4
	if (!cr6.gt) goto loc_8261F0C4;
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
	// b 0x8261f0f8
	goto loc_8261F0F8;
loc_8261F0C4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x8261f0ec
	if (!cr6.lt) goto loc_8261F0EC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x8261f0f4
	goto loc_8261F0F4;
loc_8261F0EC:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8261F0F4;
	sub_821BE4F0(ctx, base);
loc_8261F0F4:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8261F0F8:
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,60
	cr6.compare<int32_t>(ctx.r10.s32, 60, xer);
	// bne cr6,0x8261f0a0
	if (!cr6.eq) goto loc_8261F0A0;
	// lwz r29,1096(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bdcf8
	ctx.lr = 0x8261F110;
	sub_821BDCF8(ctx, base);
	// lwz r11,1096(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// subf r10,r29,r3
	ctx.r10.s64 = ctx.r3.s64 - r29.s64;
	// subf r29,r28,r10
	r29.s64 = ctx.r10.s64 - r28.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261f140
	if (cr6.eq) goto loc_8261F140;
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
loc_8261F128:
	// lwz r10,1024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1024);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,1024(r11)
	PPC_STORE_U32(r11.u32 + 1024, ctx.r10.u32);
	// lwz r9,1096(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1096);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8261f128
	if (!cr6.eq) goto loc_8261F128;
loc_8261F140:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821be568
	ctx.lr = 0x8261F14C;
	sub_821BE568(ctx, base);
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// li r10,10
	ctx.r10.s64 = 10;
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// stw r10,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r10.u32);
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8261F164;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r6,1108(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 1108);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821dd0f8
	ctx.lr = 0x8261F184;
	sub_821DD0F8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stbx r7,r30,r29
	PPC_STORE_U8(r30.u32 + r29.u32, ctx.r7.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r6,32320
	ctx.r4.s64 = ctx.r6.s64 + 32320;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c7000
	ctx.lr = 0x8261F1A8;
	sub_821C7000(ctx, base);
	// addi r1,r31,1360
	ctx.r1.s64 = r31.s64 + 1360;
	// b 0x823d9240
	return;
loc_8261F1B0:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,144
	ctx.r4.s64 = r31.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbd48
	ctx.lr = 0x8261F1C0;
	sub_821DBD48(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,144
	ctx.r4.s64 = r31.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c6a98
	ctx.lr = 0x8261F1D0;
	sub_821C6A98(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbf78
	ctx.lr = 0x8261F1D8;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,62
	ctx.r4.s64 = 62;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x8261F1E8;
	sub_821DB8E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r28,r11,24040
	r28.s64 = r11.s64 + 24040;
	// bne cr6,0x8261f288
	if (!cr6.eq) goto loc_8261F288;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r11,24100
	r29.s64 = r11.s64 + 24100;
loc_8261F204:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x8261F214;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8261f288
	if (!cr6.eq) goto loc_8261F288;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbd48
	ctx.lr = 0x8261F230;
	sub_821DBD48(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8261ef78
	ctx.lr = 0x8261F240;
	sub_8261EF78(ctx, base);
	// addi r4,r31,272
	ctx.r4.s64 = r31.s64 + 272;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dad18
	ctx.lr = 0x8261F24C;
	sub_821DAD18(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,272
	ctx.r5.s64 = r31.s64 + 272;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c7000
	ctx.lr = 0x8261F264;
	sub_821C7000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbf78
	ctx.lr = 0x8261F26C;
	sub_821DBF78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,62
	ctx.r4.s64 = 62;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x8261F27C;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f204
	if (cr6.eq) goto loc_8261F204;
loc_8261F288:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,62
	ctx.r4.s64 = 62;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821db8e8
	ctx.lr = 0x8261F298;
	sub_821DB8E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f2b0
	if (cr6.eq) goto loc_8261F2B0;
	// stb r27,1103(r30)
	PPC_STORE_U8(r30.u32 + 1103, r27.u8);
	// addi r1,r31,1360
	ctx.r1.s64 = r31.s64 + 1360;
	// b 0x823d9240
	return;
loc_8261F2B0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821dbbc8
	ctx.lr = 0x8261F2C0;
	sub_821DBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f2d4
	if (cr6.eq) goto loc_8261F2D4;
loc_8261F2CC:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1103(r30)
	PPC_STORE_U8(r30.u32 + 1103, r11.u8);
loc_8261F2D4:
	// addi r1,r31,1360
	ctx.r1.s64 = r31.s64 + 1360;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8261F2DC"))) PPC_WEAK_FUNC(sub_8261F2DC);
PPC_FUNC_IMPL(__imp__sub_8261F2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F2E0"))) PPC_WEAK_FUNC(sub_8261F2E0);
PPC_FUNC_IMPL(__imp__sub_8261F2E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8261f028
	sub_8261F028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261F2E4"))) PPC_WEAK_FUNC(sub_8261F2E4);
PPC_FUNC_IMPL(__imp__sub_8261F2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F2E8"))) PPC_WEAK_FUNC(sub_8261F2E8);
PPC_FUNC_IMPL(__imp__sub_8261F2E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmadds f9,f13,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f8,f10,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// ble cr6,0x8261f32c
	if (!cr6.gt) goto loc_8261F32C;
loc_8261F324:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8261F32C:
	// lfs f11,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsubs f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f0
	cr6.compare(ctx.f4.f64, f0.f64);
	// bgt cr6,0x8261f324
	if (cr6.gt) goto loc_8261F324;
	// lfs f11,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsubs f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f0
	cr6.compare(ctx.f4.f64, f0.f64);
	// bgt cr6,0x8261f324
	if (cr6.gt) goto loc_8261F324;
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f11,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fmadds f6,f13,f8,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8261f324
	if (cr6.gt) goto loc_8261F324;
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f8,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f8,f11,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f9.f64));
	// fmadds f5,f7,f13,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x8261f324
	if (cr6.gt) goto loc_8261F324;
	// fmr f13,f8
	ctx.f13.f64 = ctx.f8.f64;
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fmr f8,f7
	ctx.f8.f64 = ctx.f7.f64;
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F400"))) PPC_WEAK_FUNC(sub_8261F400);
PPC_FUNC_IMPL(__imp__sub_8261F400) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8261F408;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261F420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261f654
	if (cr6.eq) goto loc_8261F654;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r29,-32120
	r29.s64 = -2105016320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,100
	r28.s64 = ctx.r1.s64 + 100;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lwz r11,-17936(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -17936);
	// lwz r10,-8092(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// lwz r7,548(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 548);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r10
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8261F460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x8217c570
	ctx.lr = 0x8261F474;
	sub_8217C570(ctx, base);
	// lwz r11,-17936(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -17936);
	// lwz r10,-8092(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r11,45
	ctx.r4.s64 = r11.s64 + 45;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r3,688(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// lfs f12,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f13,f3
	cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x8261f654
	if (!cr6.gt) goto loc_8261F654;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r7,688(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 688);
	// lfs f12,648(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f3,f5,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fmuls f4,f6,f12
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fctiwz f1,f3
	ctx.f1.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fnmsubs f6,f7,f0,f8
	ctx.f6.f64 = double(float(-(ctx.f7.f64 * f0.f64 - ctx.f8.f64)));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x8261f654
	if (!cr6.lt) goto loc_8261F654;
	// lwz r8,692(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f13,f3
	cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x8261f654
	if (!cr6.gt) goto loc_8261F654;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fmuls f5,f8,f12
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// fctiwz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// fmuls f2,f4,f11
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// fctiwz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r3,1
	ctx.r3.s64 = 1;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fnmsubs f6,f10,f0,f7
	ctx.f6.f64 = double(float(-(ctx.f10.f64 * f0.f64 - ctx.f7.f64)));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// blt cr6,0x8261f658
	if (cr6.lt) goto loc_8261F658;
loc_8261F654:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8261F658:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8261F660"))) PPC_WEAK_FUNC(sub_8261F660);
PPC_FUNC_IMPL(__imp__sub_8261F660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f680
	if (cr6.eq) goto loc_8261F680;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8261F680:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F688"))) PPC_WEAK_FUNC(sub_8261F688);
PPC_FUNC_IMPL(__imp__sub_8261F688) {
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
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261f6c0
	if (cr6.eq) goto loc_8261F6C0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261F6C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261F6C0:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
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

__attribute__((alias("__imp__sub_8261F6D8"))) PPC_WEAK_FUNC(sub_8261F6D8);
PPC_FUNC_IMPL(__imp__sub_8261F6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r3,128
	ctx.r4.s64 = ctx.r3.s64 + 128;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8261F700"))) PPC_WEAK_FUNC(sub_8261F700);
PPC_FUNC_IMPL(__imp__sub_8261F700) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F704"))) PPC_WEAK_FUNC(sub_8261F704);
PPC_FUNC_IMPL(__imp__sub_8261F704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F708"))) PPC_WEAK_FUNC(sub_8261F708);
PPC_FUNC_IMPL(__imp__sub_8261F708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F718"))) PPC_WEAK_FUNC(sub_8261F718);
PPC_FUNC_IMPL(__imp__sub_8261F718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8261F72C"))) PPC_WEAK_FUNC(sub_8261F72C);
PPC_FUNC_IMPL(__imp__sub_8261F72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F730"))) PPC_WEAK_FUNC(sub_8261F730);
PPC_FUNC_IMPL(__imp__sub_8261F730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8261F744"))) PPC_WEAK_FUNC(sub_8261F744);
PPC_FUNC_IMPL(__imp__sub_8261F744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F748"))) PPC_WEAK_FUNC(sub_8261F748);
PPC_FUNC_IMPL(__imp__sub_8261F748) {
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
	// bl 0x82637538
	ctx.lr = 0x8261F760;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r10,r11,-22060
	ctx.r10.s64 = r11.s64 + -22060;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82637538
	ctx.lr = 0x8261F774;
	sub_82637538(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,7132
	ctx.r8.s64 = ctx.r9.s64 + 7132;
	// stw r11,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
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

__attribute__((alias("__imp__sub_8261F7A8"))) PPC_WEAK_FUNC(sub_8261F7A8);
PPC_FUNC_IMPL(__imp__sub_8261F7A8) {
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
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// addi r31,r3,80
	r31.s64 = ctx.r3.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261F7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8261f7e0
	if (!cr6.eq) goto loc_8261F7E0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8261F7E0:
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

__attribute__((alias("__imp__sub_8261F7F4"))) PPC_WEAK_FUNC(sub_8261F7F4);
PPC_FUNC_IMPL(__imp__sub_8261F7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F7F8"))) PPC_WEAK_FUNC(sub_8261F7F8);
PPC_FUNC_IMPL(__imp__sub_8261F7F8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-22060
	ctx.r9.s64 = r11.s64 + -22060;
	// addi r8,r10,6548
	ctx.r8.s64 = ctx.r10.s64 + 6548;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826375a0
	ctx.lr = 0x8261F834;
	sub_826375A0(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,7716
	ctx.r6.s64 = ctx.r7.s64 + 7716;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// bl 0x826375a0
	ctx.lr = 0x8261F848;
	sub_826375A0(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8261f860
	if (cr6.eq) goto loc_8261F860;
	// bl 0x82130588
	ctx.lr = 0x8261F85C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8261F860:
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

__attribute__((alias("__imp__sub_8261F878"))) PPC_WEAK_FUNC(sub_8261F878);
PPC_FUNC_IMPL(__imp__sub_8261F878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// lwz r10,572(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 572);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8261F88C"))) PPC_WEAK_FUNC(sub_8261F88C);
PPC_FUNC_IMPL(__imp__sub_8261F88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F890"))) PPC_WEAK_FUNC(sub_8261F890);
PPC_FUNC_IMPL(__imp__sub_8261F890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f10,1124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1124);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lfs f12,-11620(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11620);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f11,27632(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27632);
	ctx.f11.f64 = double(temp.f32);
	// stb r11,1184(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1184, r11.u8);
	// lfs f10,-21464(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21464);
	ctx.f10.f64 = double(temp.f32);
	// stb r11,1185(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1185, r11.u8);
	// stfs f13,1176(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1176, temp.u32);
	// stb r11,1424(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1424, r11.u8);
	// stfs f13,1172(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1172, temp.u32);
	// stb r11,716(r3)
	PPC_STORE_U8(ctx.r3.u32 + 716, r11.u8);
	// stfs f11,704(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 704, temp.u32);
	// stfs f0,708(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 708, temp.u32);
	// stfs f9,1180(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1180, temp.u32);
	// stfs f10,384(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 384, temp.u32);
	// stfs f0,1392(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1392, temp.u32);
	// stfs f0,448(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 448, temp.u32);
	// stfs f0,452(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 452, temp.u32);
	// stfs f0,456(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 456, temp.u32);
	// stb r11,1484(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1484, r11.u8);
	// lfs f13,-21468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21468);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,1485(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1485, r11.u8);
	// lfs f12,29940(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 29940);
	ctx.f12.f64 = double(temp.f32);
	// stb r4,1486(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1486, ctx.r4.u8);
	// stfs f0,1492(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1492, temp.u32);
	// stb r11,1487(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1487, r11.u8);
	// stfs f13,1496(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1496, temp.u32);
	// stb r11,396(r3)
	PPC_STORE_U8(ctx.r3.u32 + 396, r11.u8);
	// stfs f12,1488(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1488, temp.u32);
	// stb r11,1532(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1532, r11.u8);
	// stb r11,379(r3)
	PPC_STORE_U8(ctx.r3.u32 + 379, r11.u8);
	// stb r11,380(r3)
	PPC_STORE_U8(ctx.r3.u32 + 380, r11.u8);
	// stw r11,1536(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1536, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F944"))) PPC_WEAK_FUNC(sub_8261F944);
PPC_FUNC_IMPL(__imp__sub_8261F944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F948"))) PPC_WEAK_FUNC(sub_8261F948);
PPC_FUNC_IMPL(__imp__sub_8261F948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,104(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8261F968"))) PPC_WEAK_FUNC(sub_8261F968);
PPC_FUNC_IMPL(__imp__sub_8261F968) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261F96C"))) PPC_WEAK_FUNC(sub_8261F96C);
PPC_FUNC_IMPL(__imp__sub_8261F96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261F970"))) PPC_WEAK_FUNC(sub_8261F970);
PPC_FUNC_IMPL(__imp__sub_8261F970) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r4,629(r31)
	PPC_STORE_U8(r31.u32 + 629, ctx.r4.u8);
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// beq cr6,0x8261f9c0
	if (cr6.eq) goto loc_8261F9C0;
	// addi r31,r10,-21456
	r31.s64 = ctx.r10.s64 + -21456;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261F9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8261F9BC;
	sub_825EE0E0(ctx, base);
	// b 0x8261f9e0
	goto loc_8261F9E0;
loc_8261F9C0:
	// addi r30,r10,-21456
	r30.s64 = ctx.r10.s64 + -21456;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261F9CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8261F9D8;
	sub_825EE0E0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,600(r31)
	PPC_STORE_U32(r31.u32 + 600, ctx.r8.u32);
loc_8261F9E0:
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

__attribute__((alias("__imp__sub_8261F9F8"))) PPC_WEAK_FUNC(sub_8261F9F8);
PPC_FUNC_IMPL(__imp__sub_8261F9F8) {
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
	// lwz r11,592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fa28
	if (cr6.eq) goto loc_8261FA28;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,124(r11)
	PPC_STORE_U8(r11.u32 + 124, ctx.r10.u8);
loc_8261FA28:
	// lwz r3,616(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261fa54
	if (cr6.eq) goto loc_8261FA54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,568(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FA44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261fa54
	if (cr6.eq) goto loc_8261FA54;
	// stb r30,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, r30.u8);
	// stw r3,592(r31)
	PPC_STORE_U32(r31.u32 + 592, ctx.r3.u32);
loc_8261FA54:
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

__attribute__((alias("__imp__sub_8261FA6C"))) PPC_WEAK_FUNC(sub_8261FA6C);
PPC_FUNC_IMPL(__imp__sub_8261FA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FA70"))) PPC_WEAK_FUNC(sub_8261FA70);
PPC_FUNC_IMPL(__imp__sub_8261FA70) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261FAA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// bl 0x8223ef08
	ctx.lr = 0x8261FAAC;
	sub_8223EF08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f9f8
	ctx.lr = 0x8261FAB8;
	sub_8261F9F8(ctx, base);
	// lwz r3,616(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r30,628(r31)
	PPC_STORE_U8(r31.u32 + 628, r30.u8);
	// beq cr6,0x8261fae0
	if (cr6.eq) goto loc_8261FAE0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FAE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FAE0:
	// stw r30,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r30.u32);
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

__attribute__((alias("__imp__sub_8261FAFC"))) PPC_WEAK_FUNC(sub_8261FAFC);
PPC_FUNC_IMPL(__imp__sub_8261FAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FB00"))) PPC_WEAK_FUNC(sub_8261FB00);
PPC_FUNC_IMPL(__imp__sub_8261FB00) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stb r4,496(r3)
	PPC_STORE_U8(ctx.r3.u32 + 496, ctx.r4.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fb44
	if (cr6.eq) goto loc_8261FB44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r31,r10,-21440
	r31.s64 = ctx.r10.s64 + -21440;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261FB38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8261FB44;
	sub_825EE0E0(ctx, base);
loc_8261FB44:
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

__attribute__((alias("__imp__sub_8261FB58"))) PPC_WEAK_FUNC(sub_8261FB58);
PPC_FUNC_IMPL(__imp__sub_8261FB58) {
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
	// bl 0x82637a40
	ctx.lr = 0x8261FB70;
	sub_82637A40(ctx, base);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FB84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,496(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fbb8
	if (cr6.eq) goto loc_8261FBB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-21440
	r31.s64 = ctx.r10.s64 + -21440;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261FBAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8261FBB8;
	sub_825EE0E0(ctx, base);
loc_8261FBB8:
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

__attribute__((alias("__imp__sub_8261FBCC"))) PPC_WEAK_FUNC(sub_8261FBCC);
PPC_FUNC_IMPL(__imp__sub_8261FBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FBD0"))) PPC_WEAK_FUNC(sub_8261FBD0);
PPC_FUNC_IMPL(__imp__sub_8261FBD0) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6432);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FC04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// bl 0x8223ef08
	ctx.lr = 0x8261FC0C;
	sub_8223EF08(ctx, base);
	// lwz r3,-6432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6432);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8261FC24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8261FC38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f9f8
	ctx.lr = 0x8261FC44;
	sub_8261F9F8(ctx, base);
	// lwz r3,588(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r11,628(r31)
	PPC_STORE_U8(r31.u32 + 628, r11.u8);
	// stw r11,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r11.u32);
	// stw r11,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r11.u32);
	// beq cr6,0x8261fc70
	if (cr6.eq) goto loc_8261FC70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,568(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FC70:
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

__attribute__((alias("__imp__sub_8261FC88"))) PPC_WEAK_FUNC(sub_8261FC88);
PPC_FUNC_IMPL(__imp__sub_8261FC88) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f1,f13
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8261fcd4
	if (!cr6.lt) goto loc_8261FCD4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8261FCBC:
	// fsubs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f0,-21460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fabs f1,f12
	ctx.f1.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// blr 
	return;
loc_8261FCD4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8261fcbc
	if (!cr6.gt) goto loc_8261FCBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261FCE8"))) PPC_WEAK_FUNC(sub_8261FCE8);
PPC_FUNC_IMPL(__imp__sub_8261FCE8) {
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
	// lwz r11,1512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fd40
	if (cr6.eq) goto loc_8261FD40;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FD1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fd40
	if (cr6.eq) goto loc_8261FD40;
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FD40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FD40:
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

__attribute__((alias("__imp__sub_8261FD54"))) PPC_WEAK_FUNC(sub_8261FD54);
PPC_FUNC_IMPL(__imp__sub_8261FD54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FD58"))) PPC_WEAK_FUNC(sub_8261FD58);
PPC_FUNC_IMPL(__imp__sub_8261FD58) {
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
	// lwz r11,1540(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1540);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fdac
	if (cr6.eq) goto loc_8261FDAC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FD8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fdac
	if (cr6.eq) goto loc_8261FDAC;
	// lwz r3,1540(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1540);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FDAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FDAC:
	// lwz r11,1544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fdec
	if (cr6.eq) goto loc_8261FDEC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FDCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fdec
	if (cr6.eq) goto loc_8261FDEC;
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FDEC:
	// lwz r11,1512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fe2c
	if (cr6.eq) goto loc_8261FE2C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FE0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fe2c
	if (cr6.eq) goto loc_8261FE2C;
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FE2C:
	// lwz r11,1500(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1500);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261fe6c
	if (cr6.eq) goto loc_8261FE6C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FE4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fe6c
	if (cr6.eq) goto loc_8261FE6C;
	// lwz r3,1500(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1500);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FE6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FE6C:
	// lwz r11,1504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261feac
	if (cr6.eq) goto loc_8261FEAC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FE8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261feac
	if (cr6.eq) goto loc_8261FEAC;
	// lwz r3,1504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1504);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FEAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FEAC:
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

__attribute__((alias("__imp__sub_8261FEC0"))) PPC_WEAK_FUNC(sub_8261FEC0);
PPC_FUNC_IMPL(__imp__sub_8261FEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// addi r11,r3,928
	r11.s64 = ctx.r3.s64 + 928;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261FEF4"))) PPC_WEAK_FUNC(sub_8261FEF4);
PPC_FUNC_IMPL(__imp__sub_8261FEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FEF8"))) PPC_WEAK_FUNC(sub_8261FEF8);
PPC_FUNC_IMPL(__imp__sub_8261FEF8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r11,464
	r11.s64 = 464;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,448
	ctx.r10.s64 = 448;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v60,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v61,r3,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v63,v61
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-12(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f0
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	f0.f64 = double(temp.f32);
	// fmadds f8,f13,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f7,f0,f0,f9
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// fmadds f6,f12,f12,f8
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fmadds f5,f11,f11,f7
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fsqrts f4,f6
	ctx.f4.f64 = double(float(sqrt(ctx.f6.f64)));
	// fsqrts f3,f5
	ctx.f3.f64 = double(float(sqrt(ctx.f5.f64)));
	// fcmpu cr6,f3,f4
	cr6.compare(ctx.f3.f64, ctx.f4.f64);
	// blt cr6,0x8261ff6c
	if (cr6.lt) goto loc_8261FF6C;
	// li r11,0
	r11.s64 = 0;
loc_8261FF6C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261FF74"))) PPC_WEAK_FUNC(sub_8261FF74);
PPC_FUNC_IMPL(__imp__sub_8261FF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8261FF78"))) PPC_WEAK_FUNC(sub_8261FF78);
PPC_FUNC_IMPL(__imp__sub_8261FF78) {
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
	// lbz r11,1529(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1529);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8261ffb0
	if (!cr6.eq) goto loc_8261FFB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3408
	ctx.r3.s64 = ctx.r3.s64 + 3408;
	// bl 0x82224a28
	ctx.lr = 0x8261FFB0;
	sub_82224A28(ctx, base);
loc_8261FFB0:
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// li r30,0
	r30.s64 = 0;
	// stw r30,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r30,716(r31)
	PPC_STORE_U8(r31.u32 + 716, r30.u8);
	// beq cr6,0x8261fff8
	if (cr6.eq) goto loc_8261FFF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FFD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261fff8
	if (cr6.eq) goto loc_8261FFF8;
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261FFF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261FFF8:
	// lbz r11,376(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620030
	if (cr6.eq) goto loc_82620030;
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82620030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82620030:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8262003C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5680
	ctx.lr = 0x82620040;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82620050
	if (cr6.eq) goto loc_82620050;
	// stb r30,1168(r31)
	PPC_STORE_U8(r31.u32 + 1168, r30.u8);
loc_82620050:
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

__attribute__((alias("__imp__sub_82620068"))) PPC_WEAK_FUNC(sub_82620068);
PPC_FUNC_IMPL(__imp__sub_82620068) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,600(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 600);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82620070"))) PPC_WEAK_FUNC(sub_82620070);
PPC_FUNC_IMPL(__imp__sub_82620070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,120(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826200a8
	if (cr6.eq) goto loc_826200A8;
	// bl 0x822a8108
	ctx.lr = 0x82620094;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826200b8
	goto loc_826200B8;
loc_826200A8:
	// li r11,80
	r11.s64 = 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826200B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826200CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f6,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// lfs f0,-26236(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -26236);
	f0.f64 = double(temp.f32);
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fmadds f1,f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f11.f64 + f0.f64));
	// stfs f1,384(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
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

__attribute__((alias("__imp__sub_8262012C"))) PPC_WEAK_FUNC(sub_8262012C);
PPC_FUNC_IMPL(__imp__sub_8262012C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620130"))) PPC_WEAK_FUNC(sub_82620130);
PPC_FUNC_IMPL(__imp__sub_82620130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,1108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1108);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,388(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,392(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-26236(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26236);
	f0.f64 = double(temp.f32);
	// fmadds f10,f13,f12,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + f0.f64));
	// fmuls f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// stfs f1,384(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 384, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82620154"))) PPC_WEAK_FUNC(sub_82620154);
PPC_FUNC_IMPL(__imp__sub_82620154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620158"))) PPC_WEAK_FUNC(sub_82620158);
PPC_FUNC_IMPL(__imp__sub_82620158) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,600(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 600);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826201dc
	if (cr6.eq) goto loc_826201DC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r10,448
	ctx.r10.s64 = 448;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,548(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 548);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826201A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// ble cr6,0x826201e0
	if (!cr6.gt) goto loc_826201E0;
loc_826201DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826201E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_826201F4"))) PPC_WEAK_FUNC(sub_826201F4);
PPC_FUNC_IMPL(__imp__sub_826201F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826201F8"))) PPC_WEAK_FUNC(sub_826201F8);
PPC_FUNC_IMPL(__imp__sub_826201F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82620224
	if (!cr6.eq) goto loc_82620224;
loc_8262021C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82620290
	goto loc_82620290;
loc_82620224:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262021c
	if (cr6.eq) goto loc_8262021C;
	// li r11,448
	r11.s64 = 448;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bgt cr6,0x82620290
	if (cr6.gt) goto loc_82620290;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82620290:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_826202A8"))) PPC_WEAK_FUNC(sub_826202A8);
PPC_FUNC_IMPL(__imp__sub_826202A8) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x826202E4;
	sub_8217C570(ctx, base);
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r11,45
	ctx.r7.s64 = r11.s64 + 45;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r6,688(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// lfs f12,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f13,f3
	cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x826204c4
	if (!cr6.gt) goto loc_826204C4;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r7,688(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 688);
	// lfs f12,648(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fmuls f4,f6,f11
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fctiwz f1,f3
	ctx.f1.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fnmsubs f6,f8,f0,f7
	ctx.f6.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f7.f64)));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x826204c4
	if (!cr6.lt) goto loc_826204C4;
	// lwz r8,692(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f13,f3
	cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x826204c4
	if (!cr6.gt) goto loc_826204C4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmuls f2,f4,f12
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f5,f7,f11
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fctiwz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// li r3,1
	ctx.r3.s64 = 1;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fnmsubs f6,f7,f0,f10
	ctx.f6.f64 = double(float(-(ctx.f7.f64 * f0.f64 - ctx.f10.f64)));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// blt cr6,0x826204c8
	if (cr6.lt) goto loc_826204C8;
loc_826204C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826204C8:
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

__attribute__((alias("__imp__sub_826204E0"))) PPC_WEAK_FUNC(sub_826204E0);
PPC_FUNC_IMPL(__imp__sub_826204E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,452(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	f0.f64 = double(temp.f32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f13,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,448(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 448);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f6,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// lfs f0,-26236(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -26236);
	f0.f64 = double(temp.f32);
	// lfs f4,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f9,f9
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f1,f5,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fsqrts f13,f1
	ctx.f13.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmadds f12,f13,f11,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + f0.f64));
	// fmuls f1,f12,f4
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f4.f64));
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

__attribute__((alias("__imp__sub_82620568"))) PPC_WEAK_FUNC(sub_82620568);
PPC_FUNC_IMPL(__imp__sub_82620568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,1112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1112);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f12,1104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1128(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1128);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r3,720
	r11.s64 = ctx.r3.s64 + 720;
	// addi r3,r3,1328
	ctx.r3.s64 = ctx.r3.s64 + 1328;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	f0.f64 = double(temp.f32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x826205F4;
	sub_82202EC0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82620604"))) PPC_WEAK_FUNC(sub_82620604);
PPC_FUNC_IMPL(__imp__sub_82620604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620608"))) PPC_WEAK_FUNC(sub_82620608);
PPC_FUNC_IMPL(__imp__sub_82620608) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f11,f2,f13
	ctx.f11.f64 = double(float(ctx.f2.f64 - ctx.f13.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82620684
	if (!cr6.lt) goto loc_82620684;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8262064C:
	// fsubs f12,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f0,-21460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fabs f1,f11
	ctx.f1.u64 = ctx.f11.u64 & ~0x8000000000000000;
loc_82620660:
	// fcmpu cr6,f2,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// bne cr6,0x82620698
	if (!cr6.eq) goto loc_82620698;
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bne cr6,0x82620698
	if (!cr6.eq) goto loc_82620698;
	// fmr f1,f13
	ctx.f1.f64 = ctx.f13.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620684:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8262064c
	if (!cr6.gt) goto loc_8262064C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82620660
	goto loc_82620660;
loc_82620698:
	// bl 0x823dcdd8
	ctx.lr = 0x8262069C;
	sub_823DCDD8(ctx, base);
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
}

__attribute__((alias("__imp__sub_826206B0"))) PPC_WEAK_FUNC(sub_826206B0);
PPC_FUNC_IMPL(__imp__sub_826206B0) {
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
	// bl 0x823d91f0
	ctx.lr = 0x826206B8;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d0
	ctx.lr = 0x826206C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f26,f2
	f26.f64 = ctx.f2.f64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lfs f27,-1332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1332);
	f27.f64 = double(temp.f32);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x82178848
	ctx.lr = 0x826206F0;
	sub_82178848(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82620704
	if (cr6.eq) goto loc_82620704;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f27,-1336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1336);
	f27.f64 = double(temp.f32);
loc_82620704:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f31,-21408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21408);
	f31.f64 = double(temp.f32);
	// fsubs f29,f31,f30
	f29.f64 = double(float(f31.f64 - f30.f64));
	// fadds f1,f30,f31
	ctx.f1.f64 = double(float(f30.f64 + f31.f64));
	// bl 0x823dbf10
	ctx.lr = 0x82620718;
	sub_823DBF10(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmuls f28,f0,f13
	f28.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbf10
	ctx.lr = 0x8262072C;
	sub_823DBF10(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmuls f29,f12,f11
	f29.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82620740;
	sub_823DBAE8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f27,f31
	ctx.f1.f64 = double(float(f27.f64 * f31.f64));
	// fdivs f31,f29,f10
	f31.f64 = double(float(f29.f64 / ctx.f10.f64));
	// bl 0x823dbf10
	ctx.lr = 0x82620750;
	sub_823DBF10(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lfs f0,-28880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28880);
	f0.f64 = double(temp.f32);
	// lfd f1,-21416(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + -21416);
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f30,f8,f0
	f30.f64 = double(float(ctx.f8.f64 * f0.f64));
	// bl 0x823dbf10
	ctx.lr = 0x82620770;
	sub_823DBF10(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lfs f6,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r6,-11956
	ctx.r4.s64 = ctx.r6.s64 + -11956;
	// lfs f0,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lwz r3,-27856(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27856);
	// fmuls f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmuls f31,f5,f0
	f31.f64 = double(float(ctx.f5.f64 * f0.f64));
	// bl 0x823db730
	ctx.lr = 0x8262079C;
	sub_823DB730(ctx, base);
	// lfs f0,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 + f31.f64));
	// lfs f11,1392(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1392);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f12,f30
	ctx.f9.f64 = double(float(ctx.f12.f64 + f30.f64));
	// stfs f9,0(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f8,304(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 - f30.f64));
	// fsubs f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 - f31.f64));
	// stfs f6,0(r29)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfs f5,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f5.f64 = double(temp.f32);
	// fadds f4,f5,f28
	ctx.f4.f64 = double(float(ctx.f5.f64 + f28.f64));
	// fsubs f2,f4,f31
	ctx.f2.f64 = double(float(ctx.f4.f64 - f31.f64));
	// bne cr6,0x82620810
	if (!cr6.eq) goto loc_82620810;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-12988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12988);
	f0.f64 = double(temp.f32);
	// fmuls f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fsubs f1,f2,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// stfs f1,0(r28)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lfs f0,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 - f29.f64));
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// fnmsubs f10,f3,f13,f11
	ctx.f10.f64 = double(float(-(ctx.f3.f64 * ctx.f13.f64 - ctx.f11.f64)));
	// b 0x82620834
	goto loc_82620834;
loc_82620810:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,31304(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	f0.f64 = double(temp.f32);
	// fmuls f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fsubs f1,f2,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// stfs f1,0(r28)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lfs f0,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 - f29.f64));
	// fmadds f11,f3,f13,f12
	ctx.f11.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fadds f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 + f31.f64));
loc_82620834:
	// stfs f10,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82620854
	if (!cr6.lt) goto loc_82620854;
	// lfs f0,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_82620854:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82620870
	if (!cr6.lt) goto loc_82620870;
	// lfs f0,360(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
loc_82620870:
	// lwz r10,276(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r11,284(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262089c
	if (cr6.eq) goto loc_8262089C;
	// lfs f13,720(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 720);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f28,f26
	f0.f64 = double(float(f28.f64 - f26.f64));
	// fsubs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 - f30.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f11,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// stfs f10,8(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
loc_8262089C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826208c0
	if (cr6.eq) goto loc_826208C0;
	// lfs f13,720(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 720);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f29,f26
	f0.f64 = double(float(f29.f64 + f26.f64));
	// fadds f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 + f30.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f11,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 + ctx.f11.f64));
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_826208C0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba1c
	ctx.lr = 0x826208CC;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826208D0"))) PPC_WEAK_FUNC(sub_826208D0);
PPC_FUNC_IMPL(__imp__sub_826208D0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,1124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1108);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lfs f0,-18920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f8,f0,f13
	ctx.f8.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f0,f11,f8
	f0.f64 = double(float(ctx.f11.f64 / ctx.f8.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826209c8
	if (!cr6.lt) goto loc_826209C8;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82620920:
	// fsubs f12,f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lfs f0,-21460(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fabs f0,f11
	f0.u64 = ctx.f11.u64 & ~0x8000000000000000;
loc_82620934:
	// lfs f12,56(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lfs f0,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfs f12,56(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x8262095c
	if (cr6.eq) goto loc_8262095C;
	// lfs f11,1252(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1252);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8262095c
	if (!cr6.lt) goto loc_8262095C;
	// stfs f11,52(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
loc_8262095C:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f11,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fadds f9,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f9.f64));
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f9,88(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r8,720
	ctx.r8.s64 = 720;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x826209B8;
	sub_82202EC0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826209C8:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x82620920
	if (!cr6.gt) goto loc_82620920;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x82620934
	goto loc_82620934;
}

__attribute__((alias("__imp__sub_826209D8"))) PPC_WEAK_FUNC(sub_826209D8);
PPC_FUNC_IMPL(__imp__sub_826209D8) {
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
	// lbz r11,629(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620a50
	if (cr6.eq) goto loc_82620A50;
	// lwz r11,600(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620a20
	if (cr6.eq) goto loc_82620A20;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
loc_82620A00:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620A20:
	// lwz r11,588(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 588);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620ad0
	if (cr6.eq) goto loc_82620AD0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620A50:
	// lwz r3,600(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82620a00
	if (!cr6.eq) goto loc_82620A00;
	// bl 0x822a5948
	ctx.lr = 0x82620A60;
	sub_822A5948(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82620ad0
	if (cr6.eq) goto loc_82620AD0;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620ab8
	if (cr6.eq) goto loc_82620AB8;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82620aa0
	if (cr6.eq) goto loc_82620AA0;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// addi r3,r11,48
	ctx.r3.s64 = r11.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620AA0:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// addi r3,r11,48
	ctx.r3.s64 = r11.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620AB8:
	// bl 0x822a8108
	ctx.lr = 0x82620ABC;
	sub_822A8108(ctx, base);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82620AD0:
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

__attribute__((alias("__imp__sub_82620AE4"))) PPC_WEAK_FUNC(sub_82620AE4);
PPC_FUNC_IMPL(__imp__sub_82620AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620AE8"))) PPC_WEAK_FUNC(sub_82620AE8);
PPC_FUNC_IMPL(__imp__sub_82620AE8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f30,f31
	f30.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82620B28;
	sub_823DBAE8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82620B34;
	sub_823DBBC8(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f0,f29
	ctx.f10.f64 = double(float(f0.f64 * f29.f64));
	// fmuls f9,f29,f12
	ctx.f9.f64 = double(float(f29.f64 * ctx.f12.f64));
	// fneg f31,f31
	f31.u64 = f31.u64 ^ 0x8000000000000000;
	// fmsubs f8,f11,f12,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 - ctx.f10.f64));
	// stfs f8,88(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f7,f0,f11,f9
	ctx.f7.f64 = double(float(f0.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82620B64;
	sub_823DBAE8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82620B70;
	sub_823DBBC8(ctx, base);
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vmsum3fp128 v61,v62,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vor128 v60,v62,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// frsp f6,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fmuls f5,f0,f30
	ctx.f5.f64 = double(float(f0.f64 * f30.f64));
	// addi r4,r6,2240
	ctx.r4.s64 = ctx.r6.s64 + 2240;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v63,99
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v12,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f4,f0,f6
	ctx.f4.f64 = double(float(f0.f64 * ctx.f6.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmsubs f3,f13,f6,f5
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 - ctx.f5.f64));
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vrsqrtefp128 v58,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// vor128 v10,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f2,f13,f30,f4
	ctx.f2.f64 = double(float(ctx.f13.f64 * f30.f64 + ctx.f4.f64));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vcmpeqfp128 v9,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v8,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v8,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v60,v4
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v57,v63,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v3,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vmulfp128 v2,v57,v59
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v59.f32)));
	// vnmsubfp v1,v3,v12,v2
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x82620c74
	if (!cr6.lt) goto loc_82620C74;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v56,v63,135
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v0,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v55,v62,99
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v13,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vmulfp128 v12,v56,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// vnmsubfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82620c74
	if (!cr6.gt) goto loc_82620C74;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82620C74:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82620C94"))) PPC_WEAK_FUNC(sub_82620C94);
PPC_FUNC_IMPL(__imp__sub_82620C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620C98"))) PPC_WEAK_FUNC(sub_82620C98);
PPC_FUNC_IMPL(__imp__sub_82620C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,1536(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1536);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620cac
	if (cr6.eq) goto loc_82620CAC;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_82620CAC:
	// b 0x826393f0
	sub_826393F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82620CB0"))) PPC_WEAK_FUNC(sub_82620CB0);
PPC_FUNC_IMPL(__imp__sub_82620CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stw r4,1536(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1536, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,56(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82620CD0"))) PPC_WEAK_FUNC(sub_82620CD0);
PPC_FUNC_IMPL(__imp__sub_82620CD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82620CD4"))) PPC_WEAK_FUNC(sub_82620CD4);
PPC_FUNC_IMPL(__imp__sub_82620CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620CD8"))) PPC_WEAK_FUNC(sub_82620CD8);
PPC_FUNC_IMPL(__imp__sub_82620CD8) {
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
	// lwz r10,436(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82620d78
	if (!cr6.eq) goto loc_82620D78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,440(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82620d78
	if (!cr6.eq) goto loc_82620D78;
	// lwz r11,1512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620d54
	if (cr6.eq) goto loc_82620D54;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82620d78
	if (!cr6.eq) goto loc_82620D78;
loc_82620D54:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,544(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 544);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82620d7c
	if (cr6.eq) goto loc_82620D7C;
loc_82620D78:
	// li r11,1
	r11.s64 = 1;
loc_82620D7C:
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

__attribute__((alias("__imp__sub_82620D94"))) PPC_WEAK_FUNC(sub_82620D94);
PPC_FUNC_IMPL(__imp__sub_82620D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620D98"))) PPC_WEAK_FUNC(sub_82620D98);
PPC_FUNC_IMPL(__imp__sub_82620D98) {
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
	// lwz r11,1540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1540);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620dd4
	if (cr6.eq) goto loc_82620DD4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620DC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82620dd8
	if (!cr6.eq) goto loc_82620DD8;
loc_82620DD4:
	// li r11,0
	r11.s64 = 0;
loc_82620DD8:
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

__attribute__((alias("__imp__sub_82620DEC"))) PPC_WEAK_FUNC(sub_82620DEC);
PPC_FUNC_IMPL(__imp__sub_82620DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620DF0"))) PPC_WEAK_FUNC(sub_82620DF0);
PPC_FUNC_IMPL(__imp__sub_82620DF0) {
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
	// lwz r11,1544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620e2c
	if (cr6.eq) goto loc_82620E2C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82620e30
	if (!cr6.eq) goto loc_82620E30;
loc_82620E2C:
	// li r11,0
	r11.s64 = 0;
loc_82620E30:
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

__attribute__((alias("__imp__sub_82620E44"))) PPC_WEAK_FUNC(sub_82620E44);
PPC_FUNC_IMPL(__imp__sub_82620E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620E48"))) PPC_WEAK_FUNC(sub_82620E48);
PPC_FUNC_IMPL(__imp__sub_82620E48) {
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
	// lwz r11,1540(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1540);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620ea0
	if (cr6.eq) goto loc_82620EA0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620E7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82620ea0
	if (cr6.eq) goto loc_82620EA0;
	// lwz r3,1540(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1540);
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
loc_82620EA0:
	// lwz r11,1544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82620ee4
	if (cr6.eq) goto loc_82620EE4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620EC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82620ee4
	if (cr6.eq) goto loc_82620EE4;
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
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
loc_82620EE4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620EFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82620f44
	if (cr6.eq) goto loc_82620F44;
loc_82620F08:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,516(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 516);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620F1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82620f48
	if (!cr6.eq) goto loc_82620F48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,484(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 484);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82620F38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82620f08
	if (!cr6.eq) goto loc_82620F08;
loc_82620F44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82620F48:
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

__attribute__((alias("__imp__sub_82620F5C"))) PPC_WEAK_FUNC(sub_82620F5C);
PPC_FUNC_IMPL(__imp__sub_82620F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82620F60"))) PPC_WEAK_FUNC(sub_82620F60);
PPC_FUNC_IMPL(__imp__sub_82620F60) {
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
	// bl 0x82637538
	ctx.lr = 0x82620F78;
	sub_82637538(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-21396
	ctx.r8.s64 = ctx.r9.s64 + -21396;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// bl 0x8222e0f0
	ctx.lr = 0x82620FA4;
	sub_8222E0F0(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f0,32680(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32680);
	f0.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f13,88(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lfs f0,-28012(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -28012);
	f0.f64 = double(temp.f32);
	// lfs f13,-26928(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -26928);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// lfs f13,-32032(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// lfs f12,-6176(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,-17424(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -17424);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,132(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f11,136(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f0,140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stfs f13,156(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
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

__attribute__((alias("__imp__sub_82621054"))) PPC_WEAK_FUNC(sub_82621054);
PPC_FUNC_IMPL(__imp__sub_82621054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621058"))) PPC_WEAK_FUNC(sub_82621058);
PPC_FUNC_IMPL(__imp__sub_82621058) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-21396
	ctx.r9.s64 = r11.s64 + -21396;
	// addi r8,r10,2700
	ctx.r8.s64 = ctx.r10.s64 + 2700;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// stw r8,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826375a0
	ctx.lr = 0x82621094;
	sub_826375A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x8262109C;
	sub_826375A0(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826210b4
	if (cr6.eq) goto loc_826210B4;
	// bl 0x82130588
	ctx.lr = 0x826210B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826210B4:
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

__attribute__((alias("__imp__sub_826210CC"))) PPC_WEAK_FUNC(sub_826210CC);
PPC_FUNC_IMPL(__imp__sub_826210CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826210D0"))) PPC_WEAK_FUNC(sub_826210D0);
PPC_FUNC_IMPL(__imp__sub_826210D0) {
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
	// bl 0x82637a40
	ctx.lr = 0x826210E8;
	sub_82637A40(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826210FC;
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

__attribute__((alias("__imp__sub_82621110"))) PPC_WEAK_FUNC(sub_82621110);
PPC_FUNC_IMPL(__imp__sub_82621110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,176(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,380(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 380);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82621124"))) PPC_WEAK_FUNC(sub_82621124);
PPC_FUNC_IMPL(__imp__sub_82621124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621128"))) PPC_WEAK_FUNC(sub_82621128);
PPC_FUNC_IMPL(__imp__sub_82621128) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20588
	ctx.r10.s64 = ctx.r10.s64 + -20588;
loc_82621150:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621174
	if (cr6.eq) goto loc_82621174;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621150
	if (cr6.eq) goto loc_82621150;
loc_82621174:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826211a0
	if (!cr6.eq) goto loc_826211A0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823de058
	ctx.lr = 0x82621184;
	sub_823DE058(ctx, base);
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82621198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826211A0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20604
	ctx.r10.s64 = ctx.r10.s64 + -20604;
loc_826211AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826211d0
	if (cr6.eq) goto loc_826211D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826211ac
	if (cr6.eq) goto loc_826211AC;
loc_826211D0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826211ec
	if (!cr6.eq) goto loc_826211EC;
	// bl 0x823de058
	ctx.lr = 0x826211DC;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,156(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 156, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826211EC:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20616
	ctx.r10.s64 = ctx.r10.s64 + -20616;
loc_826211F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262121c
	if (cr6.eq) goto loc_8262121C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826211f8
	if (cr6.eq) goto loc_826211F8;
loc_8262121C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621238
	if (!cr6.eq) goto loc_82621238;
	// bl 0x823de058
	ctx.lr = 0x82621228;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,92(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 92, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621238:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20632
	ctx.r10.s64 = ctx.r10.s64 + -20632;
loc_82621244:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621268
	if (cr6.eq) goto loc_82621268;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621244
	if (cr6.eq) goto loc_82621244;
loc_82621268:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621284
	if (!cr6.eq) goto loc_82621284;
	// bl 0x823de058
	ctx.lr = 0x82621274;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,108(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 108, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621284:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20652
	ctx.r10.s64 = ctx.r10.s64 + -20652;
loc_82621290:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826212b4
	if (cr6.eq) goto loc_826212B4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621290
	if (cr6.eq) goto loc_82621290;
loc_826212B4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826212d0
	if (!cr6.eq) goto loc_826212D0;
	// bl 0x823de058
	ctx.lr = 0x826212C0;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,124(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 124, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826212D0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20668
	ctx.r10.s64 = ctx.r10.s64 + -20668;
loc_826212DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621300
	if (cr6.eq) goto loc_82621300;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826212dc
	if (cr6.eq) goto loc_826212DC;
loc_82621300:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262131c
	if (!cr6.eq) goto loc_8262131C;
	// bl 0x823de058
	ctx.lr = 0x8262130C;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,140(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 140, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_8262131C:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20680
	ctx.r10.s64 = ctx.r10.s64 + -20680;
loc_82621328:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262134c
	if (cr6.eq) goto loc_8262134C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621328
	if (cr6.eq) goto loc_82621328;
loc_8262134C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621368
	if (!cr6.eq) goto loc_82621368;
	// bl 0x823de058
	ctx.lr = 0x82621358;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,144(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 144, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621368:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20692
	ctx.r10.s64 = ctx.r10.s64 + -20692;
loc_82621374:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621398
	if (cr6.eq) goto loc_82621398;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621374
	if (cr6.eq) goto loc_82621374;
loc_82621398:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826213b4
	if (!cr6.eq) goto loc_826213B4;
	// bl 0x823de058
	ctx.lr = 0x826213A4;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,148(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 148, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826213B4:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20704
	ctx.r10.s64 = ctx.r10.s64 + -20704;
loc_826213C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826213e4
	if (cr6.eq) goto loc_826213E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826213c0
	if (cr6.eq) goto loc_826213C0;
loc_826213E4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621400
	if (!cr6.eq) goto loc_82621400;
	// bl 0x823de058
	ctx.lr = 0x826213F0;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,152(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 152, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621400:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20712
	ctx.r10.s64 = ctx.r10.s64 + -20712;
loc_8262140C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621430
	if (cr6.eq) goto loc_82621430;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262140c
	if (cr6.eq) goto loc_8262140C;
loc_82621430:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262144c
	if (!cr6.eq) goto loc_8262144C;
	// bl 0x823de058
	ctx.lr = 0x8262143C;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,80(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 80, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_8262144C:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20720
	ctx.r10.s64 = ctx.r10.s64 + -20720;
loc_82621458:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262147c
	if (cr6.eq) goto loc_8262147C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621458
	if (cr6.eq) goto loc_82621458;
loc_8262147C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621498
	if (!cr6.eq) goto loc_82621498;
	// bl 0x823de058
	ctx.lr = 0x82621488;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,84(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 84, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621498:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20728
	ctx.r10.s64 = ctx.r10.s64 + -20728;
loc_826214A4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826214c8
	if (cr6.eq) goto loc_826214C8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826214a4
	if (cr6.eq) goto loc_826214A4;
loc_826214C8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826214e4
	if (!cr6.eq) goto loc_826214E4;
	// bl 0x823de058
	ctx.lr = 0x826214D4;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,88(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 88, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826214E4:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20740
	ctx.r10.s64 = ctx.r10.s64 + -20740;
loc_826214F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621514
	if (cr6.eq) goto loc_82621514;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826214f0
	if (cr6.eq) goto loc_826214F0;
loc_82621514:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621530
	if (!cr6.eq) goto loc_82621530;
	// bl 0x823de058
	ctx.lr = 0x82621520;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,96(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621530:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20752
	ctx.r10.s64 = ctx.r10.s64 + -20752;
loc_8262153C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621560
	if (cr6.eq) goto loc_82621560;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262153c
	if (cr6.eq) goto loc_8262153C;
loc_82621560:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262157c
	if (!cr6.eq) goto loc_8262157C;
	// bl 0x823de058
	ctx.lr = 0x8262156C;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,100(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_8262157C:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20764
	ctx.r10.s64 = ctx.r10.s64 + -20764;
loc_82621588:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826215ac
	if (cr6.eq) goto loc_826215AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621588
	if (cr6.eq) goto loc_82621588;
loc_826215AC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826215c8
	if (!cr6.eq) goto loc_826215C8;
	// bl 0x823de058
	ctx.lr = 0x826215B8;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,104(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826215C8:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20780
	ctx.r10.s64 = ctx.r10.s64 + -20780;
loc_826215D4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826215f8
	if (cr6.eq) goto loc_826215F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826215d4
	if (cr6.eq) goto loc_826215D4;
loc_826215F8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621614
	if (!cr6.eq) goto loc_82621614;
	// bl 0x823de058
	ctx.lr = 0x82621604;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,112(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 112, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621614:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20796
	ctx.r10.s64 = ctx.r10.s64 + -20796;
loc_82621620:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621644
	if (cr6.eq) goto loc_82621644;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621620
	if (cr6.eq) goto loc_82621620;
loc_82621644:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621660
	if (!cr6.eq) goto loc_82621660;
	// bl 0x823de058
	ctx.lr = 0x82621650;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,116(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 116, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621660:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20812
	ctx.r10.s64 = ctx.r10.s64 + -20812;
loc_8262166C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621690
	if (cr6.eq) goto loc_82621690;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262166c
	if (cr6.eq) goto loc_8262166C;
loc_82621690:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826216ac
	if (!cr6.eq) goto loc_826216AC;
	// bl 0x823de058
	ctx.lr = 0x8262169C;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,120(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 120, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826216AC:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20824
	ctx.r10.s64 = ctx.r10.s64 + -20824;
loc_826216B8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826216dc
	if (cr6.eq) goto loc_826216DC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826216b8
	if (cr6.eq) goto loc_826216B8;
loc_826216DC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826216f8
	if (!cr6.eq) goto loc_826216F8;
	// bl 0x823de058
	ctx.lr = 0x826216E8;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,128(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 128, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_826216F8:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20836
	ctx.r10.s64 = ctx.r10.s64 + -20836;
loc_82621704:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621728
	if (cr6.eq) goto loc_82621728;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621704
	if (cr6.eq) goto loc_82621704;
loc_82621728:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621744
	if (!cr6.eq) goto loc_82621744;
	// bl 0x823de058
	ctx.lr = 0x82621734;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,132(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 132, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621744:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-20848
	ctx.r10.s64 = ctx.r10.s64 + -20848;
loc_82621750:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82621774
	if (cr6.eq) goto loc_82621774;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82621750
	if (cr6.eq) goto loc_82621750;
loc_82621774:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82621790
	if (!cr6.eq) goto loc_82621790;
	// bl 0x823de058
	ctx.lr = 0x82621780;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,136(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 136, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8262179c
	goto loc_8262179C;
loc_82621790:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82639498
	ctx.lr = 0x8262179C;
	sub_82639498(ctx, base);
loc_8262179C:
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

__attribute__((alias("__imp__sub_826217B4"))) PPC_WEAK_FUNC(sub_826217B4);
PPC_FUNC_IMPL(__imp__sub_826217B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826217B8"))) PPC_WEAK_FUNC(sub_826217B8);
PPC_FUNC_IMPL(__imp__sub_826217B8) {
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
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826217E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826217F8;
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

__attribute__((alias("__imp__sub_8262180C"))) PPC_WEAK_FUNC(sub_8262180C);
PPC_FUNC_IMPL(__imp__sub_8262180C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621810"))) PPC_WEAK_FUNC(sub_82621810);
PPC_FUNC_IMPL(__imp__sub_82621810) {
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
	// bl 0x822b9708
	ctx.lr = 0x82621828;
	sub_822B9708(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262183C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82621854;
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

__attribute__((alias("__imp__sub_82621868"))) PPC_WEAK_FUNC(sub_82621868);
PPC_FUNC_IMPL(__imp__sub_82621868) {
	PPC_FUNC_PROLOGUE();
	// b 0x82637a40
	sub_82637A40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262186C"))) PPC_WEAK_FUNC(sub_8262186C);
PPC_FUNC_IMPL(__imp__sub_8262186C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621870"))) PPC_WEAK_FUNC(sub_82621870);
PPC_FUNC_IMPL(__imp__sub_82621870) {
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
	ctx.lr = 0x82621878;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82621890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r9,-20576
	r29.s64 = ctx.r9.s64 + -20576;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x826218A8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x826218B8;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x826218BC;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826218D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// addi r5,r6,-14360
	ctx.r5.s64 = ctx.r6.s64 + -14360;
	// addi r4,r4,-13276
	ctx.r4.s64 = ctx.r4.s64 + -13276;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827227b8
	ctx.lr = 0x826218E8;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82621904;
	sub_82722678(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262190C"))) PPC_WEAK_FUNC(sub_8262190C);
PPC_FUNC_IMPL(__imp__sub_8262190C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621910"))) PPC_WEAK_FUNC(sub_82621910);
PPC_FUNC_IMPL(__imp__sub_82621910) {
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
	ctx.lr = 0x82621918;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r28,-32114
	r28.s64 = -2104623104;
	// lis r27,-32114
	r27.s64 = -2104623104;
	// lwz r9,88(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// lwz r31,-22860(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -22860);
	// lwz r30,-22856(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + -22856);
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// stw r11,-22860(r28)
	PPC_STORE_U32(r28.u32 + -22860, r11.u32);
	// lwz r8,88(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// stw r11,-22856(r27)
	PPC_STORE_U32(r27.u32 + -22856, r11.u32);
	// bl 0x826355a8
	ctx.lr = 0x8262194C;
	sub_826355A8(ctx, base);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82621960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,-22860(r28)
	PPC_STORE_U32(r28.u32 + -22860, r31.u32);
	// stw r30,-22856(r27)
	PPC_STORE_U32(r27.u32 + -22856, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82621970"))) PPC_WEAK_FUNC(sub_82621970);
PPC_FUNC_IMPL(__imp__sub_82621970) {
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
	// bl 0x82130000
	ctx.lr = 0x82621988;
	sub_82130000(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262199C;
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

__attribute__((alias("__imp__sub_826219B0"))) PPC_WEAK_FUNC(sub_826219B0);
PPC_FUNC_IMPL(__imp__sub_826219B0) {
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
	// bl 0x82130000
	ctx.lr = 0x826219C8;
	sub_82130000(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826219DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r11,30
	r11.s64 = 30;
	// addi r8,r9,24432
	ctx.r8.s64 = ctx.r9.s64 + 24432;
	// li r10,60
	ctx.r10.s64 = 60;
	// stw r11,24432(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24432, r11.u32);
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82621A08"))) PPC_WEAK_FUNC(sub_82621A08);
PPC_FUNC_IMPL(__imp__sub_82621A08) {
	PPC_FUNC_PROLOGUE();
	// b 0x8263aef8
	sub_8263AEF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82621A0C"))) PPC_WEAK_FUNC(sub_82621A0C);
PPC_FUNC_IMPL(__imp__sub_82621A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621A10"))) PPC_WEAK_FUNC(sub_82621A10);
PPC_FUNC_IMPL(__imp__sub_82621A10) {
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
	ctx.lr = 0x82621A18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82621a68
	if (!cr6.eq) goto loc_82621A68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82621A3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r9,-20576
	r29.s64 = ctx.r9.s64 + -20576;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82621A54;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82621A64;
	sub_825ED480(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
loc_82621A68:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82621A74"))) PPC_WEAK_FUNC(sub_82621A74);
PPC_FUNC_IMPL(__imp__sub_82621A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621A78"))) PPC_WEAK_FUNC(sub_82621A78);
PPC_FUNC_IMPL(__imp__sub_82621A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x82621c0c
	if (cr6.eq) goto loc_82621C0C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82621AD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82621AF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r13)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r4,72
	ctx.r4.s64 = 72;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32120
	r30.s64 = -2105016320;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// lbzx r10,r4,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// beq cr6,0x82621b48
	if (cr6.eq) goto loc_82621B48;
	// lis r31,-32130
	r31.s64 = -2105671680;
	// lwz r11,22080(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82621B40;
	sub_8217C570(ctx, base);
	// lwz r11,22080(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// b 0x82621b64
	goto loc_82621B64;
loc_82621B48:
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82621B60;
	sub_8217C570(ctx, base);
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
loc_82621B64:
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82621B84;
	sub_8217C570(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82621bb4
	if (!cr6.lt) goto loc_82621BB4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// b 0x82621bcc
	goto loc_82621BCC;
loc_82621BB4:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
loc_82621BCC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8216c9c0
	ctx.lr = 0x82621BF4;
	sub_8216C9C0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82621c10
	if (!cr6.lt) goto loc_82621C10;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fadds f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 + f0.f64));
	// b 0x82621c10
	goto loc_82621C10;
loc_82621C0C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_82621C10:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_82621C2C"))) PPC_WEAK_FUNC(sub_82621C2C);
PPC_FUNC_IMPL(__imp__sub_82621C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621C30"))) PPC_WEAK_FUNC(sub_82621C30);
PPC_FUNC_IMPL(__imp__sub_82621C30) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82621C6C;
	sub_8217C570(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82621d34
	if (!cr6.gt) goto loc_82621D34;
	// lwz r11,-17936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17936);
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,688(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// lfs f12,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f12.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fcmpu cr6,f13,f4
	cr6.compare(ctx.f13.f64, ctx.f4.f64);
	// bge cr6,0x82621d34
	if (!cr6.lt) goto loc_82621D34;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82621d34
	if (!cr6.gt) goto loc_82621D34;
	// lwz r10,692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f0,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcmpu cr6,f13,f5
	cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// blt cr6,0x82621d38
	if (cr6.lt) goto loc_82621D38;
loc_82621D34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82621D38:
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

__attribute__((alias("__imp__sub_82621D50"))) PPC_WEAK_FUNC(sub_82621D50);
PPC_FUNC_IMPL(__imp__sub_82621D50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82621D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82621DA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82621c30
	ctx.lr = 0x82621DC0;
	sub_82621C30(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82621c30
	ctx.lr = 0x82621DD0;
	sub_82621C30(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82621df8
	if (cr6.eq) goto loc_82621DF8;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82621df0
	if (cr6.eq) goto loc_82621DF0;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x82621e0c
	goto loc_82621E0C;
loc_82621DF0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82621e08
	if (!cr6.eq) goto loc_82621E08;
loc_82621DF8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82621e0c
	if (cr6.eq) goto loc_82621E0C;
loc_82621E08:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82621E0C:
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

__attribute__((alias("__imp__sub_82621E24"))) PPC_WEAK_FUNC(sub_82621E24);
PPC_FUNC_IMPL(__imp__sub_82621E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621E28"))) PPC_WEAK_FUNC(sub_82621E28);
PPC_FUNC_IMPL(__imp__sub_82621E28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,520(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82621e84
	if (!cr6.lt) goto loc_82621E84;
loc_82621E38:
	// lwz r10,516(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 516);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// srawi r8,r9,7
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 7;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r6,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 7;
	// rlwinm r5,r7,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// rlwinm r8,r4,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// stwx r4,r5,r3
	PPC_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r4.u32);
	// lwz r10,520(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82621e38
	if (cr6.lt) goto loc_82621E38;
loc_82621E84:
	// lwz r11,520(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,512(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// stw r10,520(r3)
	PPC_STORE_U32(ctx.r3.u32 + 520, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82621ea8
	if (!cr6.eq) goto loc_82621EA8;
	// li r11,127
	r11.s64 = 127;
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
	// blr 
	return;
loc_82621EA8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82621EB4"))) PPC_WEAK_FUNC(sub_82621EB4);
PPC_FUNC_IMPL(__imp__sub_82621EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82621EB8"))) PPC_WEAK_FUNC(sub_82621EB8);
PPC_FUNC_IMPL(__imp__sub_82621EB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,520(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// lwz r10,516(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 516);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x82621f18
	if (cr6.eq) goto loc_82621F18;
	// lwz r11,512(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// bne cr6,0x82621efc
	if (!cr6.eq) goto loc_82621EFC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
loc_82621EFC:
	// lwz r11,512(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 512);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// lwz r11,520(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,520(r3)
	PPC_STORE_U32(ctx.r3.u32 + 520, ctx.r8.u32);
loc_82621F18:
	// lwz r11,520(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// ble cr6,0x82621f74
	if (!cr6.gt) goto loc_82621F74;
loc_82621F28:
	// lwz r10,516(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 516);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// srawi r7,r9,7
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 7;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r10,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 7;
	// rlwinm r7,r6,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// addze r6,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r6.s64 = temp.s64;
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// rlwinm r9,r6,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r7,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// stwx r9,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r9.u32);
	// bgt cr6,0x82621f28
	if (cr6.gt) goto loc_82621F28;
loc_82621F74:
	// lwz r11,516(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 516);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// srawi r8,r9,7
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 7;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r4,r3
	PPC_STORE_U32(ctx.r4.u32 + ctx.r3.u32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82621FA0"))) PPC_WEAK_FUNC(sub_82621FA0);
PPC_FUNC_IMPL(__imp__sub_82621FA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82621fb8
	if (!cr6.eq) goto loc_82621FB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82621FB8:
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82621fd4
	if (!cr6.eq) goto loc_82621FD4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_82621FD4:
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82621FF8"))) PPC_WEAK_FUNC(sub_82621FF8);
PPC_FUNC_IMPL(__imp__sub_82621FF8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// vsubfp128 v63,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v60,v62
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f12,-31408(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31408);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f0,f13,f13,f10
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fabs f9,f0
	ctx.f9.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// ble cr6,0x82622098
	if (!cr6.gt) goto loc_82622098;
	// vpermwi128 v59,v63,99
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// vpermwi128 v58,v62,135
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// fmuls f11,f1,f1
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v13,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vmulfp128 v12,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f8,f12,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fdivs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 / f0.f64));
	// fcmpu cr6,f7,f11
	cr6.compare(ctx.f7.f64, ctx.f11.f64);
	// ble cr6,0x82622098
	if (!cr6.gt) goto loc_82622098;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82622098:
	// lfs f13,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f1
	f0.f64 = double(float(f0.f64 + ctx.f1.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f11,f7,f6
	ctx.f11.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f4,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f10,f5,f4
	ctx.f10.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// lfs f2,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f9,f3,f2
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fmadds f1,f13,f13,f8
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f13,f12,f12,f1
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f1.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x826220f8
	if (cr6.gt) goto loc_826220F8;
	// fmuls f13,f10,f10
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// li r11,1
	r11.s64 = 1;
	// fmadds f12,f9,f9,f13
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f13.f64));
	// fmadds f11,f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x826220fc
	if (!cr6.gt) goto loc_826220FC;
loc_826220F8:
	// li r11,0
	r11.s64 = 0;
loc_826220FC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82622104"))) PPC_WEAK_FUNC(sub_82622104);
PPC_FUNC_IMPL(__imp__sub_82622104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622108"))) PPC_WEAK_FUNC(sub_82622108);
PPC_FUNC_IMPL(__imp__sub_82622108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82622110"))) PPC_WEAK_FUNC(sub_82622110);
PPC_FUNC_IMPL(__imp__sub_82622110) {
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
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r10,616(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 616);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82622150
	if (cr6.eq) goto loc_82622150;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262214C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82622154
	goto loc_82622154;
loc_82622150:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82622154:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82622178"))) PPC_WEAK_FUNC(sub_82622178);
PPC_FUNC_IMPL(__imp__sub_82622178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82622180;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r4,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r10,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r10.u8);
	// li r8,352
	ctx.r8.s64 = 352;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r10,-10220(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lfs f13,-12080(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12080);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vsubfp128 v59,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lfs f13,7444(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82622228;
	sub_82202EC0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82622230"))) PPC_WEAK_FUNC(sub_82622230);
PPC_FUNC_IMPL(__imp__sub_82622230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,352
	ctx.r9.s64 = 352;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,-10220(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,132(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262225C"))) PPC_WEAK_FUNC(sub_8262225C);
PPC_FUNC_IMPL(__imp__sub_8262225C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622260"))) PPC_WEAK_FUNC(sub_82622260);
PPC_FUNC_IMPL(__imp__sub_82622260) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82622268;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stw r8,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r8.u32);
	// lfs f0,-20484(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20484);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f13,-20488(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20488);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,29904(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 29904);
	f0.f64 = double(temp.f32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lfs f13,-20492(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20492);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// lfs f12,-20496(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -20496);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r9,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r9.u32);
	// lfs f10,-20504(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -20504);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r30,r10,-11956
	r30.s64 = ctx.r10.s64 + -11956;
	// lfs f11,-20500(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -20500);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lis r29,-32120
	r29.s64 = -2105016320;
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f9,-20508(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20508);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lfs f13,-20512(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20512);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r6,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r6.u32);
	// stfsx f12,r10,r31
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r5,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r5.u32);
	// stfsx f11,r10,r31
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// stfsx f9,r10,r31
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// lwz r3,-27856(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// bl 0x823db730
	ctx.lr = 0x82622370;
	sub_823DB730(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r7,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r7.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// bne cr6,0x82622400
	if (!cr6.eq) goto loc_82622400;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lfs f0,-20516(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20516);
	f0.f64 = double(temp.f32);
	// lfs f13,-20520(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20520);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f13,r10,r31
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,-20524(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -20524);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lfs f12,-20528(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -20528);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// lfs f11,-20532(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -20532);
	ctx.f11.f64 = double(temp.f32);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// stfsx f13,r10,r31
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r9,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r9.u32);
	// stfsx f12,r10,r31
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f11,8(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// b 0x8262243c
	goto loc_8262243C;
loc_82622400:
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lfs f13,-20536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20536);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-20540(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20540);
	f0.f64 = double(temp.f32);
	// stfsx f13,r10,r31
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,-20544(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -20544);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r5,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r5.u32);
	// stfsx f13,r10,r31
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_8262243C:
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stw r7,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r7.u32);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// addi r28,r31,240
	r28.s64 = r31.s64 + 240;
	// addi r27,r31,192
	r27.s64 = r31.s64 + 192;
	// lfs f0,-20548(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20548);
	f0.f64 = double(temp.f32);
	// addi r26,r31,176
	r26.s64 = r31.s64 + 176;
	// lfs f13,-20552(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20552);
	ctx.f13.f64 = double(temp.f32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stfsx f0,r10,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8261a810
	ctx.lr = 0x82622498;
	sub_8261A810(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f0,-12080(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12080);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// lwz r3,-27856(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// bl 0x823db730
	ctx.lr = 0x826224B0;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8262250c
	if (!cr6.eq) goto loc_8262250C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lfs f11,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lfs f0,-29936(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29936);
	f0.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,-20556(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20556);
	f0.f64 = double(temp.f32);
	// lfs f13,-20560(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20560);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f12,-20564(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20564);
	ctx.f12.f64 = double(temp.f32);
	// fadds f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f10,248(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f9,0(r26)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stfs f8,0(r27)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// fsubs f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// stfs f7,184(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// fadds f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfs f6,200(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
loc_8262250C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82622518"))) PPC_WEAK_FUNC(sub_82622518);
PPC_FUNC_IMPL(__imp__sub_82622518) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lfs f12,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f10,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fmuls f6,f13,f13
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f5,f9,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// fsqrts f13,f4
	ctx.f13.f64 = double(float(sqrt(ctx.f4.f64)));
	// blelr cr6
	if (!cr6.gt) return;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
loc_82622568:
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	f0.f64 = double(temp.f32);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// lfs f6,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826225a0
	if (!cr6.lt) goto loc_826225A0;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_826225A0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82622568
	if (cr6.lt) goto loc_82622568;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826225B4"))) PPC_WEAK_FUNC(sub_826225B4);
PPC_FUNC_IMPL(__imp__sub_826225B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826225B8"))) PPC_WEAK_FUNC(sub_826225B8);
PPC_FUNC_IMPL(__imp__sub_826225B8) {
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
	PPCRegister f31{};
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
	ctx.lr = 0x826225C0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushModeUnconditional();
	f31.f64 = ctx.f1.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r31,0(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// lvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x82622618;
	sub_8216C900(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,26468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 26468);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82622634
	if (!cr6.gt) goto loc_82622634;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// b 0x8262263c
	goto loc_8262263C;
loc_82622634:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
loc_8262263C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8262265c
	if (!cr6.eq) goto loc_8262265C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8262265C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r9,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r9.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 - f31.f64));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82622680"))) PPC_WEAK_FUNC(sub_82622680);
PPC_FUNC_IMPL(__imp__sub_82622680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r2{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82622688;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x82622ab4
	if (cr6.gt) goto loc_82622AB4;
	// lis r12,-32158
	r12.s64 = -2107506688;
	// addi r12,r12,9920
	r12.s64 = r12.s64 + 9920;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82622704;
	case 1:
		goto loc_82622AB4;
	case 2:
		goto loc_82622AB4;
	case 3:
		goto loc_82622754;
	case 4:
		goto loc_8262277C;
	case 5:
		goto loc_826227A4;
	case 6:
		goto loc_826227CC;
	case 7:
		goto loc_826227F4;
	case 8:
		goto loc_82622820;
	case 9:
		goto loc_82622870;
	case 10:
		goto loc_8262288C;
	case 11:
		goto loc_82622848;
	case 12:
		goto loc_8262290C;
	case 13:
		goto loc_826228BC;
	case 14:
		goto loc_82622984;
	case 15:
		goto loc_826228E4;
	case 16:
		goto loc_826229CC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,9988(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 9988);
	// lwz r19,10932(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10932);
	// lwz r19,10932(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10932);
	// lwz r19,10068(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10068);
	// lwz r19,10108(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10108);
	// lwz r19,10148(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10148);
	// lwz r19,10188(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10188);
	// lwz r19,10228(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10228);
	// lwz r19,10272(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10272);
	// lwz r19,10352(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10352);
	// lwz r19,10380(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10380);
	// lwz r19,10312(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10312);
	// lwz r19,10508(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10508);
	// lwz r19,10428(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10428);
	// lwz r19,10628(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10628);
	// lwz r19,10468(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10468);
	// lwz r19,10700(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + 10700);
loc_82622704:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622710;
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
	// addi r6,r9,-19728
	ctx.r6.s64 = ctx.r9.s64 + -19728;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823dedd8
	ctx.lr = 0x8262273C;
	sub_823DEDD8(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r11,-10220(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10220);
	// stw r3,1512(r11)
	PPC_STORE_U32(r11.u32 + 1512, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622754:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622760;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8262277C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622788;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826227A4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826227B0;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,375(r11)
	PPC_STORE_U8(r11.u32 + 375, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826227CC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826227D8;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,374(r11)
	PPC_STORE_U8(r11.u32 + 374, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826227F4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622800;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x8261fb00
	ctx.lr = 0x82622814;
	sub_8261FB00(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622820:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8262282C;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,372(r11)
	PPC_STORE_U8(r11.u32 + 372, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622848:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622854;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,377(r11)
	PPC_STORE_U8(r11.u32 + 377, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622870:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1528(r11)
	PPC_STORE_U8(r11.u32 + 1528, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8262288C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622898;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826228BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826228C8;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,378(r11)
	PPC_STORE_U8(r11.u32 + 378, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826228E4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826228F0;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,380(r11)
	PPC_STORE_U8(r11.u32 + 380, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8262290C:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8262291C;
	sub_822A3998(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r31,-10220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x822afa10
	ctx.lr = 0x8262292C;
	sub_822AFA10(ctx, base);
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82622968;
	sub_822A3998(ctx, base);
	// lwz r31,-10220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa30
	ctx.lr = 0x82622974;
	sub_822AFA30(ctx, base);
	// stfs f1,1524(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1524, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622984:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lbz r9,376(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 376);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x8268c9f0
	ctx.lr = 0x826229A0;
	sub_8268C9F0(ctx, base);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r6,76(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,304(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 304);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826229C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826229CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x826229D4;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82622a6c
	if (!cr6.gt) goto loc_82622A6C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-20480
	ctx.r3.s64 = r11.s64 + -20480;
	// bl 0x821fa230
	ctx.lr = 0x826229E8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// lwz r29,-10220(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82622A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,372(r29)
	PPC_STORE_U8(r29.u32 + 372, ctx.r6.u8);
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x8261fbd0
	ctx.lr = 0x82622A18;
	sub_8261FBD0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622A24;
	sub_8268C9F0(ctx, base);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r11,-22160
	ctx.r6.s64 = r11.s64 + -22160;
	// addi r5,r9,-22108
	ctx.r5.s64 = ctx.r9.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// bl 0x823dedd8
	ctx.lr = 0x82622A50;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82622A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82622A6C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82622A78;
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
	// addi r6,r9,-22160
	ctx.r6.s64 = ctx.r9.s64 + -22160;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823dedd8
	ctx.lr = 0x82622AA4;
	sub_823DEDD8(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,304(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 304);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82622AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82622AB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82622AC0"))) PPC_WEAK_FUNC(sub_82622AC0);
PPC_FUNC_IMPL(__imp__sub_82622AC0) {
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
	ctx.lr = 0x82622AC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,-20452
	ctx.r9.s64 = r11.s64 + -20452;
	// addi r8,r10,-20464
	ctx.r8.s64 = ctx.r10.s64 + -20464;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r28,r31,68
	r28.s64 = r31.s64 + 68;
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x82622AF0;
	sub_82130000(ctx, base);
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622b10
	if (cr6.eq) goto loc_82622B10;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82622B10:
	// lwz r5,1548(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82622b34
	if (cr6.eq) goto loc_82622B34;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x82622B30;
	sub_8268B6D0(ctx, base);
	// stw r29,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r29.u32);
loc_82622B34:
	// lwz r5,1552(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1552);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82622b50
	if (cr6.eq) goto loc_82622B50;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x82622B4C;
	sub_8268B6D0(ctx, base);
	// stw r29,1552(r31)
	PPC_STORE_U32(r31.u32 + 1552, r29.u32);
loc_82622B50:
	// lwz r3,612(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622b74
	if (cr6.eq) goto loc_82622B74;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r29.u32);
loc_82622B74:
	// lwz r3,608(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622b98
	if (cr6.eq) goto loc_82622B98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,608(r31)
	PPC_STORE_U32(r31.u32 + 608, r29.u32);
loc_82622B98:
	// lwz r3,620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622bbc
	if (cr6.eq) goto loc_82622BBC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622BB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r29.u32);
loc_82622BBC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x82622BD0;
	sub_826375A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82622BD8"))) PPC_WEAK_FUNC(sub_82622BD8);
PPC_FUNC_IMPL(__imp__sub_82622BD8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-68
	ctx.r3.s64 = ctx.r3.s64 + -68;
	// b 0x82625830
	sub_82625830(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82622BE0"))) PPC_WEAK_FUNC(sub_82622BE0);
PPC_FUNC_IMPL(__imp__sub_82622BE0) {
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
	// bl 0x82130000
	ctx.lr = 0x82622BF8;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f890
	ctx.lr = 0x82622C00;
	sub_8261F890(ctx, base);
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

__attribute__((alias("__imp__sub_82622C14"))) PPC_WEAK_FUNC(sub_82622C14);
PPC_FUNC_IMPL(__imp__sub_82622C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622C18"))) PPC_WEAK_FUNC(sub_82622C18);
PPC_FUNC_IMPL(__imp__sub_82622C18) {
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
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622c4c
	if (cr6.eq) goto loc_82622C4C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622C4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82622C4C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10220(r31)
	PPC_STORE_U32(r31.u32 + -10220, r11.u32);
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

__attribute__((alias("__imp__sub_82622C68"))) PPC_WEAK_FUNC(sub_82622C68);
PPC_FUNC_IMPL(__imp__sub_82622C68) {
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
	ctx.lr = 0x82622C70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r10,-18664
	r30.s64 = ctx.r10.s64 + -18664;
	// lwz r3,612(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 612);
	// addi r29,r11,-18512
	r29.s64 = r11.s64 + -18512;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622cc4
	if (cr6.eq) goto loc_82622CC4;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82622CAC;
	sub_823DEDD8(ctx, base);
	// bl 0x822842e0
	ctx.lr = 0x82622CB0;
	sub_822842E0(ctx, base);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bne cr6,0x82622cc4
	if (!cr6.eq) goto loc_82622CC4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8261f970
	ctx.lr = 0x82622CC4;
	sub_8261F970(ctx, base);
loc_82622CC4:
	// lwz r3,624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 624);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82622d14
	if (cr6.eq) goto loc_82622D14;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82622CE4;
	sub_823DEDD8(ctx, base);
	// bl 0x822842e0
	ctx.lr = 0x82622CE8;
	sub_822842E0(ctx, base);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bne cr6,0x82622d14
	if (!cr6.eq) goto loc_82622D14;
	// lwz r3,624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 624);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622D08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8261fa70
	ctx.lr = 0x82622D14;
	sub_8261FA70(ctx, base);
loc_82622D14:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82622D1C"))) PPC_WEAK_FUNC(sub_82622D1C);
PPC_FUNC_IMPL(__imp__sub_82622D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622D20"))) PPC_WEAK_FUNC(sub_82622D20);
PPC_FUNC_IMPL(__imp__sub_82622D20) {
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
	// lwz r11,616(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622d70
	if (cr6.eq) goto loc_82622D70;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622D5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x82622d70
	if (!cr6.eq) goto loc_82622D70;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fa70
	ctx.lr = 0x82622D70;
	sub_8261FA70(ctx, base);
loc_82622D70:
	// lwz r11,600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622da4
	if (cr6.eq) goto loc_82622DA4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622D90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x82622da4
	if (!cr6.eq) goto loc_82622DA4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f970
	ctx.lr = 0x82622DA4;
	sub_8261F970(ctx, base);
loc_82622DA4:
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

__attribute__((alias("__imp__sub_82622DBC"))) PPC_WEAK_FUNC(sub_82622DBC);
PPC_FUNC_IMPL(__imp__sub_82622DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622DC0"))) PPC_WEAK_FUNC(sub_82622DC0);
PPC_FUNC_IMPL(__imp__sub_82622DC0) {
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
	ctx.lr = 0x82622DC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,616(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622de8
	if (cr6.eq) goto loc_82622DE8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8261fa70
	ctx.lr = 0x82622DE8;
	sub_8261FA70(ctx, base);
loc_82622DE8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82622df8
	if (cr6.eq) goto loc_82622DF8;
	// stw r30,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r30.u32);
	// b 0x82622e84
	goto loc_82622E84;
loc_82622DF8:
	// lwz r11,600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622e84
	if (cr6.eq) goto loc_82622E84;
	// bl 0x82387a18
	ctx.lr = 0x82622E08;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622e20
	if (cr6.eq) goto loc_82622E20;
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// stw r11,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r11.u32);
	// b 0x82622e80
	goto loc_82622E80;
loc_82622E20:
	// lwz r3,608(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622E34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r6,r9,-18636
	ctx.r6.s64 = ctx.r9.s64 + -18636;
	// addi r5,r8,-18664
	ctx.r5.s64 = ctx.r8.s64 + -18664;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// bl 0x823dedd8
	ctx.lr = 0x82622E58;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r30,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r30.u32);
	// beq cr6,0x82622e7c
	if (cr6.eq) goto loc_82622E7C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r3,128
	ctx.r4.s64 = ctx.r3.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622E7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82622E7C:
	// lwz r11,620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 620);
loc_82622E80:
	// stw r11,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r11.u32);
loc_82622E84:
	// lwz r11,616(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622f60
	if (cr6.eq) goto loc_82622F60;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6432);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82622EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-6432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6432);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82622EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,464(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 464);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82622EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-6432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6432);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82622F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,616(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r29,692(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 692);
	// lwz r5,548(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 548);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82622F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r30,1
	r30.s64 = 1;
	// stw r3,612(r29)
	PPC_STORE_U32(r29.u32 + 612, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r30,608(r29)
	PPC_STORE_U8(r29.u32 + 608, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f9f8
	ctx.lr = 0x82622F44;
	sub_8261F9F8(ctx, base);
	// lwz r3,616(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// stb r30,628(r31)
	PPC_STORE_U8(r31.u32 + 628, r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622F60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82622F60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82622F68"))) PPC_WEAK_FUNC(sub_82622F68);
PPC_FUNC_IMPL(__imp__sub_82622F68) {
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
	// lwz r11,616(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82622fcc
	if (cr6.eq) goto loc_82622FCC;
	// lwz r3,600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82622F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82622fc8
	if (cr6.eq) goto loc_82622FC8;
	// bl 0x8261fa70
	ctx.lr = 0x82622FB4;
	sub_8261FA70(ctx, base);
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
loc_82622FC8:
	// bl 0x8261fa70
	ctx.lr = 0x82622FCC;
	sub_8261FA70(ctx, base);
loc_82622FCC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82622dc0
	ctx.lr = 0x82622FD8;
	sub_82622DC0(ctx, base);
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

__attribute__((alias("__imp__sub_82622FEC"))) PPC_WEAK_FUNC(sub_82622FEC);
PPC_FUNC_IMPL(__imp__sub_82622FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82622FF0"))) PPC_WEAK_FUNC(sub_82622FF0);
PPC_FUNC_IMPL(__imp__sub_82622FF0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82622FF8;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r27,0
	r27.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lbz r11,1530(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1530);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826231c4
	if (cr6.eq) goto loc_826231C4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f1,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c0d10
	ctx.lr = 0x82623048;
	sub_823C0D10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826231c4
	if (cr6.eq) goto loc_826231C4;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82218cb8
	ctx.lr = 0x8262305C;
	sub_82218CB8(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// addi r29,r31,1056
	r29.s64 = r31.s64 + 1056;
	// ori r30,r11,5088
	r30.u64 = r11.u64 | 5088;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82219678
	ctx.lr = 0x82623084;
	sub_82219678(ctx, base);
	// stw r3,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r3.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r25,r9,-19728
	r25.s64 = ctx.r9.s64 + -19728;
	// addi r24,r8,-22132
	r24.s64 = ctx.r8.s64 + -22132;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,480(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 480);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826230AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826230C0;
	sub_823DEDD8(ctx, base);
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// addi r9,r5,29952
	ctx.r9.s64 = ctx.r5.s64 + 29952;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lfs f13,27632(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823c0f88
	ctx.lr = 0x826230EC;
	sub_823C0F88(ctx, base);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,648(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 648);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82623104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r4,r6,r30
	ctx.r4.u64 = ctx.r6.u64 + r30.u64;
	// lwz r11,632(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 632);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82623124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,636(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 636);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262313C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,144
	r30.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r7,636(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 636);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82623194;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,720(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 720);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826231AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r4,1544(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x826231BC;
	sub_82220980(ctx, base);
	// stb r27,1530(r31)
	PPC_STORE_U8(r31.u32 + 1530, r27.u8);
	// stb r27,1531(r31)
	PPC_STORE_U8(r31.u32 + 1531, r27.u8);
loc_826231C4:
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82623254
	if (cr6.eq) goto loc_82623254;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826231E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82623254
	if (cr6.eq) goto loc_82623254;
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lfs f0,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 432);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f13,432(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,600(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 600);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262320C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lfs f12,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 432);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-19896(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19896);
	f0.f64 = double(temp.f32);
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x82623260
	if (!cr6.gt) goto loc_82623260;
	// lbz r11,1531(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1531);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82623260
	if (!cr6.eq) goto loc_82623260;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// stb r27,293(r11)
	PPC_STORE_U8(r11.u32 + 293, r27.u8);
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// bl 0x823bb5a0
	ctx.lr = 0x82623240;
	sub_823BB5A0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,1531(r31)
	PPC_STORE_U8(r31.u32 + 1531, r11.u8);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82623254:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,432(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
loc_82623260:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8262326C"))) PPC_WEAK_FUNC(sub_8262326C);
PPC_FUNC_IMPL(__imp__sub_8262326C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623270"))) PPC_WEAK_FUNC(sub_82623270);
PPC_FUNC_IMPL(__imp__sub_82623270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82623284"))) PPC_WEAK_FUNC(sub_82623284);
PPC_FUNC_IMPL(__imp__sub_82623284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623288"))) PPC_WEAK_FUNC(sub_82623288);
PPC_FUNC_IMPL(__imp__sub_82623288) {
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
	ctx.lr = 0x82623290;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623344
	if (cr6.eq) goto loc_82623344;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623344
	if (cr6.eq) goto loc_82623344;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,24996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// bl 0x826cb780
	ctx.lr = 0x826232C4;
	sub_826CB780(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r3,r10,-19892
	ctx.r3.s64 = ctx.r10.s64 + -19892;
	// addi r31,r9,23724
	r31.s64 = ctx.r9.s64 + 23724;
	// addi r28,r8,-22108
	r28.s64 = ctx.r8.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x826232E4;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826232F8;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82623344
	if (cr6.eq) goto loc_82623344;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82623344
	if (cr6.eq) goto loc_82623344;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82623320;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 552);
	// lwz r31,-10220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82623338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82622dc0
	ctx.lr = 0x82623344;
	sub_82622DC0(ctx, base);
loc_82623344:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262334C"))) PPC_WEAK_FUNC(sub_8262334C);
PPC_FUNC_IMPL(__imp__sub_8262334C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623350"))) PPC_WEAK_FUNC(sub_82623350);
PPC_FUNC_IMPL(__imp__sub_82623350) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,1124(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82623488
	if (!cr6.lt) goto loc_82623488;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_826233A8:
	// fsubs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f0,-21460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fabs f31,f12
	f31.u64 = ctx.f12.u64 & ~0x8000000000000000;
loc_826233BC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82620608
	ctx.lr = 0x826233C8;
	sub_82620608(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// addi r7,r1,108
	ctx.r7.s64 = ctx.r1.s64 + 108;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826206b0
	ctx.lr = 0x826233F4;
	sub_826206B0(ctx, base);
	// lfs f0,1124(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82623408
	if (!cr6.lt) goto loc_82623408;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
loc_82623408:
	// lfs f0,1128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1128);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8262341c
	if (!cr6.gt) goto loc_8262341C;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
loc_8262341C:
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82623430
	if (!cr6.lt) goto loc_82623430;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_82623430:
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82623444
	if (!cr6.gt) goto loc_82623444;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_82623444:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82623458
	if (!cr6.gt) goto loc_82623458;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_82623458:
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8262346c
	if (!cr6.lt) goto loc_8262346C;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_8262346C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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
loc_82623488:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x826233a8
	if (!cr6.gt) goto loc_826233A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f31.f64 = double(temp.f32);
	// b 0x826233bc
	goto loc_826233BC;
}

__attribute__((alias("__imp__sub_8262349C"))) PPC_WEAK_FUNC(sub_8262349C);
PPC_FUNC_IMPL(__imp__sub_8262349C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826234A0"))) PPC_WEAK_FUNC(sub_826234A0);
PPC_FUNC_IMPL(__imp__sub_826234A0) {
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
	ctx.lr = 0x826234A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8263b730
	ctx.lr = 0x826234B4;
	sub_8263B730(ctx, base);
	// lbz r11,1528(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826234dc
	if (cr6.eq) goto loc_826234DC;
	// li r30,1
	r30.s64 = 1;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,1530(r31)
	PPC_STORE_U8(r31.u32 + 1530, r30.u8);
	// lwz r3,-10000(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// bl 0x823bc1a8
	ctx.lr = 0x826234D4;
	sub_823BC1A8(ctx, base);
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
loc_826234DC:
	// li r28,0
	r28.s64 = 0;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// stb r28,1184(r31)
	PPC_STORE_U8(r31.u32 + 1184, r28.u8);
	// stb r28,1185(r31)
	PPC_STORE_U8(r31.u32 + 1185, r28.u8);
	// bl 0x8262bfa8
	ctx.lr = 0x826234F0;
	sub_8262BFA8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,-21440
	r30.s64 = r11.s64 + -21440;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262350C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82623518;
	sub_825EE0E0(ctx, base);
	// lbz r8,376(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 376);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262353c
	if (cr6.eq) goto loc_8262353C;
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262353C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262353C:
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,804(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 804);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82623558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// addi r4,r31,712
	ctx.r4.s64 = r31.s64 + 712;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,800(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 800);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82623570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// ori r5,r6,12788
	ctx.r5.u64 = ctx.r6.u64 | 12788;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfsx f1,r4,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,812(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 812);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262359C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,628(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 628);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826235B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,1529(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 1529);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826235f4
	if (cr6.eq) goto loc_826235F4;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,580(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 580);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826235D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-17424(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// lwz r6,576(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 576);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82623660
	goto loc_82623660;
loc_826235F4:
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r11,1508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82623610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r7,580(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 580);
	// lfs f0,31308(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262362C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r6,1508(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,592(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 592);
	// lwz r29,0(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82623648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r10,576(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// lfs f0,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82623660:
	// bctrl 
	ctx.lr = 0x82623664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r4,1508(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82623674;
	sub_82220980(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// addi r5,r31,864
	ctx.r5.s64 = r31.s64 + 864;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221d6f0
	ctx.lr = 0x82623688;
	sub_8221D6F0(ctx, base);
	// stw r28,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82623694"))) PPC_WEAK_FUNC(sub_82623694);
PPC_FUNC_IMPL(__imp__sub_82623694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623698"))) PPC_WEAK_FUNC(sub_82623698);
PPC_FUNC_IMPL(__imp__sub_82623698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x826236B0;
	sub_82130000(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r4,r31,928
	ctx.r4.s64 = r31.s64 + 928;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r5,r6,5
	ctx.r5.s64 = ctx.r6.s64 + 327680;
	// addi r5,r5,5088
	ctx.r5.s64 = ctx.r5.s64 + 5088;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r5,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r5,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r5,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221a118
	ctx.lr = 0x82623708;
	sub_8221A118(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,382(r31)
	PPC_STORE_U8(r31.u32 + 382, r11.u8);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r10,1529(r31)
	PPC_STORE_U8(r31.u32 + 1529, ctx.r10.u8);
	// stfs f0,1396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// stb r10,630(r31)
	PPC_STORE_U8(r31.u32 + 630, ctx.r10.u8);
	// stw r11,24436(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24436, r11.u32);
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

__attribute__((alias("__imp__sub_82623744"))) PPC_WEAK_FUNC(sub_82623744);
PPC_FUNC_IMPL(__imp__sub_82623744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623748"))) PPC_WEAK_FUNC(sub_82623748);
PPC_FUNC_IMPL(__imp__sub_82623748) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82623750;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8262375C;
	sub_82130000(ctx, base);
	// lbz r11,1532(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1532);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623794
	if (cr6.eq) goto loc_82623794;
	// li r11,1
	r11.s64 = 1;
	// stb r11,1529(r31)
	PPC_STORE_U8(r31.u32 + 1529, r11.u8);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,5
	ctx.r3.s64 = ctx.r10.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221a440
	ctx.lr = 0x82623788;
	sub_8221A440(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262ba40
	ctx.lr = 0x82623794;
	sub_8262BA40(ctx, base);
loc_82623794:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826237AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 552);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826237C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,1529(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1529);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r27,0
	r27.s64 = 0;
	// ori r30,r7,12656
	r30.u64 = ctx.r7.u64 | 12656;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82623844
	if (cr6.eq) goto loc_82623844;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826237F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,31308(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,580(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 580);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82623810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,628(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 628);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82623824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-17424(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82623840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826239f4
	goto loc_826239F4;
loc_82623844:
	// bl 0x8261fd58
	ctx.lr = 0x82623848;
	sub_8261FD58(ctx, base);
	// lwz r4,1516(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1516);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82623878
	if (cr6.eq) goto loc_82623878;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82623868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1516(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1516);
	// stw r27,1516(r31)
	PPC_STORE_U32(r31.u32 + 1516, r27.u32);
	// stw r9,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r9.u32);
	// b 0x82623944
	goto loc_82623944;
loc_82623878:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82218cb8
	ctx.lr = 0x82623880;
	sub_82218CB8(ctx, base);
	// lbz r11,380(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623900
	if (cr6.eq) goto loc_82623900;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8262389C;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x826238A4;
	sub_822AFA10(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,1056
	ctx.r4.s64 = r31.s64 + 1056;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82219678
	ctx.lr = 0x826238B4;
	sub_82219678(ctx, base);
	// stw r3,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826238C4;
	sub_822A3998(ctx, base);
	// lwz r11,1508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822afa30
	ctx.lr = 0x826238D4;
	sub_822AFA30(ctx, base);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r10,812(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 812);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826238E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826238F0;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa30
	ctx.lr = 0x826238F8;
	sub_822AFA30(ctx, base);
	// stfs f1,1524(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1524, temp.u32);
	// b 0x82623928
	goto loc_82623928;
loc_82623900:
	// bl 0x82387a18
	ctx.lr = 0x82623904;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r31,1056
	ctx.r4.s64 = r31.s64 + 1056;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r5,r11,r30
	ctx.r5.u64 = r11.u64 + r30.u64;
	// bl 0x82219678
	ctx.lr = 0x82623924;
	sub_82219678(ctx, base);
	// stw r3,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r3.u32);
loc_82623928:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1544(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82623940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r27,380(r31)
	PPC_STORE_U8(r31.u32 + 380, r27.u8);
loc_82623944:
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r11,1508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82623960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r7,580(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 580);
	// lfs f0,31308(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262397C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,628(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 628);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82623990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r4,1508(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// lwz r28,0(r4)
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826239AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r8,576(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 576);
	// lfs f0,-17424(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17424);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826239C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,592(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 592);
	// lwz r28,104(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826239E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f2,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8262bab0
	ctx.lr = 0x826239F4;
	sub_8262BAB0(ctx, base);
loc_826239F4:
	// lis r11,1
	r11.s64 = 65536;
	// stb r27,1532(r31)
	PPC_STORE_U8(r31.u32 + 1532, r27.u8);
	// stb r27,381(r31)
	PPC_STORE_U8(r31.u32 + 381, r27.u8);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r6,r11,12784
	ctx.r6.u64 = r11.u64 | 12784;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// ori r5,r7,12788
	ctx.r5.u64 = ctx.r7.u64 | 12788;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 65536;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r7,12720
	ctx.r7.s64 = ctx.r7.s64 + 12720;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// stvx128 v62,r7,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stvx128 v61,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lfs f1,-29232(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfsx f0,r4,r6
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r4,r5
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, temp.u32);
	// bl 0x827229f0
	ctx.lr = 0x82623A68;
	sub_827229F0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82623A70"))) PPC_WEAK_FUNC(sub_82623A70);
PPC_FUNC_IMPL(__imp__sub_82623A70) {
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82623A78;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d4
	ctx.lr = 0x82623A80;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r22,0(r13)
	r22.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lfs f27,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f27.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// li r21,72
	r21.s64 = 72;
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// li r25,0
	r25.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// fmr f30,f27
	f30.f64 = f27.f64;
	// li r29,8
	r29.s64 = 8;
	// lfs f28,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f28.f64 = double(temp.f32);
	// li r23,448
	r23.s64 = 448;
	// li r24,48
	r24.s64 = 48;
loc_82623ACC:
	// lbzx r11,r21,r22
	r11.u64 = PPC_LOAD_U8(r21.u32 + r22.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623afc
	if (cr6.eq) goto loc_82623AFC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82623b20
	if (cr6.lt) goto loc_82623B20;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82623b20
	if (!cr6.lt) goto loc_82623B20;
	// add r11,r29,r3
	r11.u64 = r29.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x82623b18
	goto loc_82623B18;
loc_82623AFC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82623b20
	if (cr6.lt) goto loc_82623B20;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82623b20
	if (!cr6.lt) goto loc_82623B20;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_82623B18:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82623b24
	if (!cr6.eq) goto loc_82623B24;
loc_82623B20:
	// li r11,0
	r11.s64 = 0;
loc_82623B24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82623bd0
	if (cr6.eq) goto loc_82623BD0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82623B38;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82623bcc
	if (cr6.eq) goto loc_82623BCC;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82623bcc
	if (!cr6.eq) goto loc_82623BCC;
	// bl 0x822a8108
	ctx.lr = 0x82623B58;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lvx128 v63,r27,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v62,r11,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f31,f10
	f31.f64 = double(float(sqrt(ctx.f10.f64)));
	// bl 0x82620ae8
	ctx.lr = 0x82623BA0;
	sub_82620AE8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82623bcc
	if (cr6.eq) goto loc_82623BCC;
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// ble cr6,0x82623bbc
	if (!cr6.gt) goto loc_82623BBC;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x82623bc4
	if (cr6.lt) goto loc_82623BC4;
loc_82623BBC:
	// fcmpu cr6,f30,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f27.f64);
	// bne cr6,0x82623bcc
	if (!cr6.eq) goto loc_82623BCC;
loc_82623BC4:
	// mr r25,r31
	r25.u64 = r31.u64;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_82623BCC:
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
loc_82623BD0:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r29,132
	cr6.compare<int32_t>(r29.s32, 132, xer);
	// bne cr6,0x82623acc
	if (!cr6.eq) goto loc_82623ACC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba20
	ctx.lr = 0x82623BF0;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82623BF4"))) PPC_WEAK_FUNC(sub_82623BF4);
PPC_FUNC_IMPL(__imp__sub_82623BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82623BF8"))) PPC_WEAK_FUNC(sub_82623BF8);
PPC_FUNC_IMPL(__imp__sub_82623BF8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82623C00;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82623C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lfs f0,-18920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// lfs f30,-21460(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21460);
	f30.f64 = double(temp.f32);
	// fdivs f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82623ed4
	if (!cr6.lt) goto loc_82623ED4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82623C60:
	// fsubs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// fabs f31,f13
	f31.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_82623C6C:
	// addi r30,r31,1104
	r30.s64 = r31.s64 + 1104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r29,r31,416
	r29.s64 = r31.s64 + 416;
	// addi r28,r31,400
	r28.s64 = r31.s64 + 400;
	// bl 0x82620608
	ctx.lr = 0x82623C84;
	sub_82620608(ctx, base);
	// addi r8,r31,1164
	ctx.r8.s64 = r31.s64 + 1164;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// addi r7,r31,1160
	ctx.r7.s64 = r31.s64 + 1160;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r6,r31,1156
	ctx.r6.s64 = r31.s64 + 1156;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r5,r31,1152
	ctx.r5.s64 = r31.s64 + 1152;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826206b0
	ctx.lr = 0x82623CAC;
	sub_826206B0(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f9,1396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1396);
	ctx.f9.f64 = double(temp.f32);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lfs f7,400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f7.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f6,416(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 416);
	ctx.f6.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,24456(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24456);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// lwz r10,-8092(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// lfs f12,18900(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 18900);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f11,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// fmuls f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// lwz r5,688(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 688);
	// lfs f5,648(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	ctx.f5.f64 = double(temp.f32);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f4,96(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f5
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// fctiwz f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f5,f10
	ctx.f5.f64 = double(float(ctx.f10.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmadds f3,f4,f11,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fadds f2,f3,f7
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f7.f64));
	// stfs f2,572(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// lwz r10,-8092(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// lfs f13,24460(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24460);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r7,r11,45
	ctx.r7.s64 = r11.s64 + 45;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f1,f13,f30
	ctx.f1.f64 = double(float(ctx.f13.f64 + f30.f64));
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lwz r4,688(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 688);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f11,648(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	ctx.f11.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f5,96(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fnmsubs f2,f3,f0,f6
	ctx.f2.f64 = double(float(-(ctx.f3.f64 * f0.f64 - ctx.f6.f64)));
	// fnmsubs f5,f1,f9,f2
	ctx.f5.f64 = double(float(-(ctx.f1.f64 * ctx.f9.f64 - ctx.f2.f64)));
	// stfs f5,580(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// lfs f8,408(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 408);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,31016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r10,-8092(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f7,424(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 424);
	ctx.f7.f64 = double(temp.f32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lfs f13,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lfs f11,3732(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3732);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,24464(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24464);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,31020(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 31020);
	ctx.f10.f64 = double(temp.f32);
	// lwz r3,692(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 692);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f4,96(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// lfs f2,652(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 652);
	ctx.f2.f64 = double(temp.f32);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fmuls f5,f1,f2
	ctx.f5.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f3,96(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f5,f1,f0
	ctx.f5.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmadds f4,f5,f13,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fadds f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// fsubs f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f12.f64));
	// stfs f2,576(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r6,r11,45
	ctx.r6.s64 = r11.s64 + 45;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-8092(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// lfs f13,24468(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24468);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// lfs f8,652(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 652);
	ctx.f8.f64 = double(temp.f32);
	// lwz r3,692(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 692);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f1,96(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f1
	ctx.f12.f64 = double(ctx.f1.s64);
	// frsp f6,f12
	ctx.f6.f64 = double(float(ctx.f12.f64));
	// fmuls f5,f6,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f3,96(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fnmsubs f12,f0,f11,f7
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f11.f64 - ctx.f7.f64)));
	// fnmsubs f11,f9,f10,f12
	ctx.f11.f64 = double(float(-(ctx.f9.f64 * ctx.f10.f64 - ctx.f12.f64)));
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f10,584(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82623ED4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82623c60
	if (!cr6.gt) goto loc_82623C60;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f31.f64 = double(temp.f32);
	// b 0x82623c6c
	goto loc_82623C6C;
}

__attribute__((alias("__imp__sub_82623EE8"))) PPC_WEAK_FUNC(sub_82623EE8);
PPC_FUNC_IMPL(__imp__sub_82623EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82623EF0;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r31,1396
	r30.s64 = r31.s64 + 1396;
	// lfs f0,1124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,1128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1108);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fdivs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// stfs f9,1396(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// fabs f8,f9
	ctx.f8.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// bge cr6,0x82623f3c
	if (!cr6.lt) goto loc_82623F3C;
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_82623F3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 - f0.f64));
	// bl 0x82502110
	ctx.lr = 0x82623F50;
	sub_82502110(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,3468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3468);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f13,1392(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82623f6c
	if (!cr6.gt) goto loc_82623F6C;
	// stfs f31,1392(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
loc_82623F6C:
	// lfs f1,1392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1392);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82227c70
	ctx.lr = 0x82623F74;
	sub_82227C70(ctx, base);
	// li r11,512
	r11.s64 = 512;
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// li r10,528
	ctx.r10.s64 = 528;
	// lvlx128 v63,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f12,560(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 560);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v0,r31,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f13,f1
	ctx.f13.f64 = ctx.f1.f64;
	// lvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// vsubfp128 v12,v62,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f11,564(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 564);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// li r8,544
	ctx.r8.s64 = 544;
	// lfs f9,1108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1108);
	ctx.f9.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-11620(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11620);
	f0.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f8,1180(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 1180, temp.u32);
	// fmadds f7,f10,f13,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f7,568(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 568, temp.u32);
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,208(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82623FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// lfs f6,452(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	ctx.f6.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f5,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f5.f64 = double(temp.f32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f4,448(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 448);
	ctx.f4.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f6,f2
	ctx.f1.f64 = double(float(ctx.f6.f64 - ctx.f2.f64));
	// lfs f0,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f13,f5,f0
	ctx.f13.f64 = double(float(ctx.f5.f64 - f0.f64));
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f4,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 - ctx.f12.f64));
	// lfs f31,-26236(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -26236);
	f31.f64 = double(temp.f32);
	// lfs f10,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// fmuls f9,f1,f1
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fsqrts f30,f7
	f30.f64 = double(float(sqrt(ctx.f7.f64)));
	// fmadds f6,f30,f3,f31
	ctx.f6.f64 = double(float(f30.f64 * ctx.f3.f64 + f31.f64));
	// fmuls f29,f6,f10
	f29.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r30,4
	r30.s64 = 4;
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r29,r9,-19880
	r29.s64 = ctx.r9.s64 + -19880;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x82624068;
	sub_82203058(ctx, base);
	// lfs f5,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f30,f5,f31
	ctx.f4.f64 = double(float(f30.f64 * ctx.f5.f64 + f31.f64));
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f3,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,468(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// fmuls f29,f4,f3
	f29.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262408C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f29,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x826240A4;
	sub_82203058(ctx, base);
	// lfs f2,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f2.f64 = double(temp.f32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmadds f1,f30,f2,f31
	ctx.f1.f64 = double(float(f30.f64 * ctx.f2.f64 + f31.f64));
	// lfs f0,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	f0.f64 = double(temp.f32);
	// lwz r5,468(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 468);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826240C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82203058
	ctx.lr = 0x826240E0;
	sub_82203058(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826240F4"))) PPC_WEAK_FUNC(sub_826240F4);
PPC_FUNC_IMPL(__imp__sub_826240F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826240F8"))) PPC_WEAK_FUNC(sub_826240F8);
PPC_FUNC_IMPL(__imp__sub_826240F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82624100;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,576(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 576);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82624128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lfs f1,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// lwz r7,804(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 804);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82624144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,800(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 800);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262415C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,812(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 812);
	// lfs f1,-12084(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -12084);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x8262418C;
	sub_82220980(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82624194"))) PPC_WEAK_FUNC(sub_82624194);
PPC_FUNC_IMPL(__imp__sub_82624194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82624198"))) PPC_WEAK_FUNC(sub_82624198);
PPC_FUNC_IMPL(__imp__sub_82624198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x826241A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,576(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 576);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826241C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lfs f1,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// lwz r7,804(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 804);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826241E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,800(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 800);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826241FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,812(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 812);
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x8262422C;
	sub_82220980(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82624234"))) PPC_WEAK_FUNC(sub_82624234);
PPC_FUNC_IMPL(__imp__sub_82624234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82624238"))) PPC_WEAK_FUNC(sub_82624238);
PPC_FUNC_IMPL(__imp__sub_82624238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r9,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lfs f12,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lfs f0,-17576(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -17576);
	f0.f64 = double(temp.f32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lfs f13,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,-7900(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + -7900);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,3796(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lfs f11,1396(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1396);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fadds f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// stfs f9,148(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x826242EC;
	sub_82723940(ctx, base);
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

__attribute__((alias("__imp__sub_82624300"))) PPC_WEAK_FUNC(sub_82624300);
PPC_FUNC_IMPL(__imp__sub_82624300) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82624308;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x8268d388
	ctx.lr = 0x82624320;
	sub_8268D388(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x826246c8
	if (!cr6.gt) goto loc_826246C8;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// bne cr6,0x826246c8
	if (!cr6.eq) goto loc_826246C8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,156(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lfd f31,-1072(r11)
	f31.u64 = PPC_LOAD_U64(r11.u32 + -1072);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82624384
	if (!cr6.gt) goto loc_82624384;
	// li r10,144
	ctx.r10.s64 = 144;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,668(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// bl 0x82624238
	ctx.lr = 0x82624384;
	sub_82624238(ctx, base);
loc_82624384:
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826243c4
	if (!cr6.gt) goto loc_826243C4;
	// li r10,80
	ctx.r10.s64 = 80;
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,656(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// bl 0x82624238
	ctx.lr = 0x826243C4;
	sub_82624238(ctx, base);
loc_826243C4:
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82624404
	if (!cr6.gt) goto loc_82624404;
	// li r10,96
	ctx.r10.s64 = 96;
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,660(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// bl 0x82624238
	ctx.lr = 0x82624404;
	sub_82624238(ctx, base);
loc_82624404:
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82624444
	if (!cr6.gt) goto loc_82624444;
	// li r10,112
	ctx.r10.s64 = 112;
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,664(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// bl 0x82624238
	ctx.lr = 0x82624444;
	sub_82624238(ctx, base);
loc_82624444:
	// lfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82624484
	if (!cr6.gt) goto loc_82624484;
	// li r10,128
	ctx.r10.s64 = 128;
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,672(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// bl 0x82624238
	ctx.lr = 0x82624484;
	sub_82624238(ctx, base);
loc_82624484:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262449C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// lfs f0,-19856(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19856);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826244c0
	if (!cr6.lt) goto loc_826244C0;
	// stb r28,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r28.u8);
	// b 0x826244c4
	goto loc_826244C4;
loc_826244C0:
	// stb r29,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r29.u8);
loc_826244C4:
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826244D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-2376(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2376);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826244f4
	if (!cr6.lt) goto loc_826244F4;
	// stb r28,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r28.u8);
	// b 0x826244f8
	goto loc_826244F8;
loc_826244F4:
	// stb r29,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r29.u8);
loc_826244F8:
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262450C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-18920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82624528
	if (!cr6.lt) goto loc_82624528;
	// stb r28,161(r31)
	PPC_STORE_U8(r31.u32 + 161, r28.u8);
	// b 0x8262452c
	goto loc_8262452C;
loc_82624528:
	// stb r29,161(r31)
	PPC_STORE_U8(r31.u32 + 161, r29.u8);
loc_8262452C:
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f31,-6432(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6432);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8262455c
	if (!cr6.lt) goto loc_8262455C;
	// stb r28,162(r31)
	PPC_STORE_U8(r31.u32 + 162, r28.u8);
	// b 0x82624560
	goto loc_82624560;
loc_8262455C:
	// stb r29,162(r31)
	PPC_STORE_U8(r31.u32 + 162, r29.u8);
loc_82624560:
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82624588
	if (!cr6.lt) goto loc_82624588;
	// stb r28,163(r31)
	PPC_STORE_U8(r31.u32 + 163, r28.u8);
	// b 0x8262458c
	goto loc_8262458C;
loc_82624588:
	// stb r29,163(r31)
	PPC_STORE_U8(r31.u32 + 163, r29.u8);
loc_8262458C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r7,164(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 164);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f12,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x826245bc
	if (cr6.eq) goto loc_826245BC;
	// lfs f0,156(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826245bc
	if (!cr6.lt) goto loc_826245BC;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
loc_826245BC:
	// lbz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826245dc
	if (cr6.eq) goto loc_826245DC;
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826245dc
	if (!cr6.lt) goto loc_826245DC;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
loc_826245DC:
	// lbz r9,161(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 161);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826245fc
	if (cr6.eq) goto loc_826245FC;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826245fc
	if (!cr6.lt) goto loc_826245FC;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
loc_826245FC:
	// lbz r10,162(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 162);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262461c
	if (cr6.eq) goto loc_8262461C;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8262461c
	if (!cr6.lt) goto loc_8262461C;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
loc_8262461C:
	// lbz r11,163(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 163);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262463c
	if (cr6.eq) goto loc_8262463C;
	// lfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8262463c
	if (!cr6.lt) goto loc_8262463C;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
loc_8262463C:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82624658
	if (!cr6.eq) goto loc_82624658;
	// lfs f0,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82624658
	if (!cr6.gt) goto loc_82624658;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
loc_82624658:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82624674
	if (!cr6.eq) goto loc_82624674;
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82624674
	if (!cr6.gt) goto loc_82624674;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
loc_82624674:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82624690
	if (!cr6.eq) goto loc_82624690;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82624690
	if (!cr6.gt) goto loc_82624690;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
loc_82624690:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826246ac
	if (!cr6.eq) goto loc_826246AC;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x826246ac
	if (!cr6.gt) goto loc_826246AC;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
loc_826246AC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826246c8
	if (!cr6.eq) goto loc_826246C8;
	// lfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x826246c8
	if (!cr6.gt) goto loc_826246C8;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
loc_826246C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826246D8"))) PPC_WEAK_FUNC(sub_826246D8);
PPC_FUNC_IMPL(__imp__sub_826246D8) {
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
	ctx.lr = 0x826246E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r11,24432
	r30.s64 = r11.s64 + 24432;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r4,24432(r11)
	PPC_STORE_U32(r11.u32 + 24432, ctx.r4.u32);
	// stw r4,260(r29)
	PPC_STORE_U32(r29.u32 + 260, ctx.r4.u32);
	// stw r8,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r8.u32);
	// ble cr6,0x82624728
	if (!cr6.gt) goto loc_82624728;
loc_8262470C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82621870
	ctx.lr = 0x82624718;
	sub_82621870(ctx, base);
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x8262470c
	if (cr6.lt) goto loc_8262470C;
loc_82624728:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,24472
	r11.s64 = r11.s64 + 24472;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
	// stw r6,516(r11)
	PPC_STORE_U32(r11.u32 + 516, ctx.r6.u32);
	// stw r9,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r9.u32);
	// ble cr6,0x82624798
	if (!cr6.gt) goto loc_82624798;
loc_82624754:
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// beq cr6,0x8262478c
	if (cr6.eq) goto loc_8262478C;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82624774
	if (!cr6.eq) goto loc_82624774;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_82624774:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,512(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
loc_8262478C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x82624754
	if (cr6.lt) goto loc_82624754;
loc_82624798:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826247A0"))) PPC_WEAK_FUNC(sub_826247A0);
PPC_FUNC_IMPL(__imp__sub_826247A0) {
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
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82624808
	if (cr6.eq) goto loc_82624808;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r11,r11,24472
	r11.s64 = r11.s64 + 24472;
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// beq cr6,0x82624808
	if (cr6.eq) goto loc_82624808;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x826247f0
	if (!cr6.eq) goto loc_826247F0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_826247F0:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
loc_82624808:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82624828;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,464(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 464);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82624840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
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

__attribute__((alias("__imp__sub_82624860"))) PPC_WEAK_FUNC(sub_82624860);
PPC_FUNC_IMPL(__imp__sub_82624860) {
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
	ctx.lr = 0x82624868;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,72(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826248f4
	if (cr6.eq) goto loc_826248F4;
	// li r29,0
	r29.s64 = 0;
loc_82624884:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8224d270
	ctx.lr = 0x82624898;
	sub_8224D270(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x826248e0
	if (!cr6.gt) goto loc_826248E0;
loc_826248A8:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8224d6f8
	ctx.lr = 0x826248B8;
	sub_8224D6F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826248d4
	if (cr6.eq) goto loc_826248D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82621d50
	ctx.lr = 0x826248CC;
	sub_82621D50(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82624900
	if (cr6.eq) goto loc_82624900;
loc_826248D4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x826248a8
	if (cr6.lt) goto loc_826248A8;
loc_826248E0:
	// lhz r11,72(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82624884
	if (cr6.lt) goto loc_82624884;
loc_826248F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82624900:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8262490C"))) PPC_WEAK_FUNC(sub_8262490C);
PPC_FUNC_IMPL(__imp__sub_8262490C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82624910"))) PPC_WEAK_FUNC(sub_82624910);
PPC_FUNC_IMPL(__imp__sub_82624910) {
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
	// bl 0x82637538
	ctx.lr = 0x8262492C;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-19260
	ctx.r10.s64 = r11.s64 + -19260;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82637538
	ctx.lr = 0x82624948;
	sub_82637538(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
	// addi r7,r9,-19844
	ctx.r7.s64 = ctx.r9.s64 + -19844;
	// addi r6,r8,18928
	ctx.r6.s64 = ctx.r8.s64 + 18928;
	// stw r7,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r6.u32);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
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

__attribute__((alias("__imp__sub_82624984"))) PPC_WEAK_FUNC(sub_82624984);
PPC_FUNC_IMPL(__imp__sub_82624984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82624988"))) PPC_WEAK_FUNC(sub_82624988);
PPC_FUNC_IMPL(__imp__sub_82624988) {
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
	ctx.lr = 0x82624990;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82637a40
	ctx.lr = 0x8262499C;
	sub_82637A40(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826249B0;
	sub_821F9FB8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,56(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826249CC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826249DC;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x826249E0;
	sub_825EF9F0(ctx, base);
	// lwz r7,144(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82624dfc
	if (cr6.eq) goto loc_82624DFC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,1072
	r30.s64 = r11.s64 + 1072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825ee120
	ctx.lr = 0x82624A08;
	sub_825EE120(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82624a1c
	if (cr6.lt) goto loc_82624A1C;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82624a2c
	if (!cr6.gt) goto loc_82624A2C;
loc_82624A1C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82624A2C;
	sub_825EE0E0(ctx, base);
loc_82624A2C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x82624A50;
	sub_821C9790(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82624A78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x82624A80;
	sub_825EF9F0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82624A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r9,564(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 564);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82624AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82624dfc
	if (cr6.eq) goto loc_82624DFC;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82624d20
	if (cr6.lt) goto loc_82624D20;
	// beq cr6,0x82624b94
	if (cr6.eq) goto loc_82624B94;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x82624dfc
	if (!cr6.lt) goto loc_82624DFC;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x826be5a0
	ctx.lr = 0x82624AD8;
	sub_826BE5A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82624b00
	if (cr6.eq) goto loc_82624B00;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82624AF0;
	sub_82218310(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,2672
	ctx.r4.s64 = r11.s64 + 2672;
	// b 0x82624b10
	goto loc_82624B10;
loc_82624B00:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,-18712
	ctx.r5.s64 = r11.s64 + -18712;
	// addi r4,r10,2672
	ctx.r4.s64 = ctx.r10.s64 + 2672;
loc_82624B10:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624B18;
	sub_827227B8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r4,r10,2680
	ctx.r4.s64 = ctx.r10.s64 + 2680;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624B34;
	sub_827227B8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r9,2688
	ctx.r4.s64 = ctx.r9.s64 + 2688;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624B48;
	sub_827227B8(ctx, base);
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r7,556(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 556);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82624B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
loc_82624B64:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// beq cr6,0x82624b80
	if (cr6.eq) goto loc_82624B80;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11224
	ctx.r4.s64 = r11.s64 + -11224;
	// bl 0x82218310
	ctx.lr = 0x82624B78;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82624dec
	goto loc_82624DEC;
loc_82624B80:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11204
	ctx.r4.s64 = r11.s64 + -11204;
	// bl 0x82218310
	ctx.lr = 0x82624B8C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82624dec
	goto loc_82624DEC;
loc_82624B94:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,23956
	ctx.r6.s64 = r11.s64 + 23956;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82624BB4;
	sub_823DEDD8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82624c94
	if (cr6.eq) goto loc_82624C94;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r27,-10020(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + -10020);
	// bl 0x826cb5d8
	ctx.lr = 0x82624BCC;
	sub_826CB5D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826bcd50
	ctx.lr = 0x82624BD8;
	sub_826BCD50(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r29,16(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82624c94
	if (cr6.eq) goto loc_82624C94;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82624c94
	if (cr6.eq) goto loc_82624C94;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10020(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10020);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// lwz r28,-10244(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x826be2b0
	ctx.lr = 0x82624C04;
	sub_826BE2B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82624C10;
	sub_82218310(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,2672
	ctx.r4.s64 = r11.s64 + 2672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624C24;
	sub_827227B8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8d98
	ctx.lr = 0x82624C2C;
	sub_822A8D98(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82624c5c
	if (cr6.eq) goto loc_82624C5C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r29,-10244(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822a8d98
	ctx.lr = 0x82624C40;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x82624C4C;
	sub_82218310(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,2680
	ctx.r4.s64 = r11.s64 + 2680;
	// b 0x82624c6c
	goto loc_82624C6C;
loc_82624C5C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r4,r10,2680
	ctx.r4.s64 = ctx.r10.s64 + 2680;
loc_82624C6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624C74;
	sub_827227B8(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// b 0x82624b64
	goto loc_82624B64;
loc_82624C94:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x826be5a0
	ctx.lr = 0x82624C9C;
	sub_826BE5A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// beq cr6,0x82624cc4
	if (cr6.eq) goto loc_82624CC4;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82624CBC;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82624cc8
	goto loc_82624CC8;
loc_82624CC4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
loc_82624CC8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,2672
	ctx.r4.s64 = r11.s64 + 2672;
	// bl 0x827227b8
	ctx.lr = 0x82624CD8;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,2680
	ctx.r4.s64 = r11.s64 + 2680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624CEC;
	sub_827227B8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,2688
	ctx.r4.s64 = ctx.r10.s64 + 2688;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624D00;
	sub_827227B8(ctx, base);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r8,556(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 556);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82624D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// b 0x82624b64
	goto loc_82624B64;
loc_82624D20:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,23896
	ctx.r6.s64 = r11.s64 + 23896;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82624D40;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82624d50
	if (cr6.eq) goto loc_82624D50;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x82624d54
	goto loc_82624D54;
loc_82624D50:
	// li r30,0
	r30.s64 = 0;
loc_82624D54:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,2672
	ctx.r4.s64 = ctx.r9.s64 + 2672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624D7C;
	sub_827227B8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8d98
	ctx.lr = 0x82624D84;
	sub_822A8D98(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// beq cr6,0x82624dc0
	if (cr6.eq) goto loc_82624DC0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,-10244(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822a8d98
	ctx.lr = 0x82624DA4;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82624DB0;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,2680
	ctx.r4.s64 = ctx.r10.s64 + 2680;
	// b 0x82624dcc
	goto loc_82624DCC;
loc_82624DC0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,2680
	ctx.r4.s64 = r11.s64 + 2680;
loc_82624DCC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624DD4;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,2688
	ctx.r4.s64 = r11.s64 + 2688;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82624DE8;
	sub_827227B8(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
loc_82624DEC:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,2604
	ctx.r4.s64 = ctx.r10.s64 + 2604;
	// bl 0x827227b8
	ctx.lr = 0x82624DFC;
	sub_827227B8(ctx, base);
loc_82624DFC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82624E04"))) PPC_WEAK_FUNC(sub_82624E04);
PPC_FUNC_IMPL(__imp__sub_82624E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82624E08"))) PPC_WEAK_FUNC(sub_82624E08);
PPC_FUNC_IMPL(__imp__sub_82624E08) {
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
	ctx.lr = 0x82624E10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,224
	ctx.r3.s64 = r11.s64 + 224;
	// lwz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82624E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,0
	r27.s64 = 0;
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
loc_82624E40:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x82624e9c
	if (cr6.eq) goto loc_82624E9C;
loc_82624E4C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82624e90
	if (cr6.eq) goto loc_82624E90;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r26,32(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82624E84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r26,r9
	cr6.compare<int32_t>(r26.s32, ctx.r9.s32, xer);
	// beq cr6,0x82624eb8
	if (cr6.eq) goto loc_82624EB8;
loc_82624E90:
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// bne cr6,0x82624e4c
	if (!cr6.eq) goto loc_82624E4C;
loc_82624E9C:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpwi cr6,r27,7
	cr6.compare<int32_t>(r27.s32, 7, xer);
	// blt cr6,0x82624e40
	if (cr6.lt) goto loc_82624E40;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82624EB8:
	// stw r29,148(r30)
	PPC_STORE_U32(r30.u32 + 148, r29.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82624EC8"))) PPC_WEAK_FUNC(sub_82624EC8);
PPC_FUNC_IMPL(__imp__sub_82624EC8) {
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
	ctx.lr = 0x82624ED0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x82622518
	ctx.lr = 0x82624EF0;
	sub_82622518(ctx, base);
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
	// addi r25,r11,16
	r25.s64 = r11.s64 + 16;
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// blt cr6,0x82624f14
	if (cr6.lt) goto loc_82624F14;
	// mr r25,r31
	r25.u64 = r31.u64;
loc_82624F14:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82624f2c
	if (!cr6.eq) goto loc_82624F2C;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// addi r27,r10,-16
	r27.s64 = ctx.r10.s64 + -16;
	// b 0x82624f30
	goto loc_82624F30;
loc_82624F2C:
	// addi r27,r11,-16
	r27.s64 = r11.s64 + -16;
loc_82624F30:
	// lfs f13,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f7,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f12,f7,f0
	ctx.f12.f64 = double(float(ctx.f7.f64 - f0.f64));
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fsubs f11,f6,f13
	ctx.f11.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f6,116(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f9,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fsubs f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 - f0.f64));
	// lfs f8,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f10,f9,f11
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f8,124(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fsubs f8,f8,f13
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f5,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmsubs f4,f8,f12,f10
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 - ctx.f10.f64));
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fabs f3,f4
	ctx.f3.u64 = ctx.f4.u64 & ~0x8000000000000000;
	// lfs f10,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	ctx.f10.f64 = double(temp.f32);
	// lfs f4,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,132(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// bge cr6,0x82625004
	if (!cr6.lt) goto loc_82625004;
	// fsubs f0,f7,f0
	f0.f64 = double(float(ctx.f7.f64 - f0.f64));
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// fsubs f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// fmuls f11,f9,f9
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f9,f8,f8,f11
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f11.f64));
	// fmadds f10,f13,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fsqrts f7,f9
	ctx.f7.f64 = double(float(sqrt(ctx.f9.f64)));
	// fsqrts f8,f10
	ctx.f8.f64 = double(float(sqrt(ctx.f10.f64)));
	// fdivs f1,f8,f7
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x826225b8
	ctx.lr = 0x82624FF8;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82625004:
	// fsubs f9,f5,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsubs f8,f4,f13
	ctx.f8.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fmuls f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmsubs f5,f8,f12,f11
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 - ctx.f11.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f10
	cr6.compare(ctx.f4.f64, ctx.f10.f64);
	// bge cr6,0x82625078
	if (!cr6.lt) goto loc_82625078;
	// fsubs f0,f7,f0
	f0.f64 = double(float(ctx.f7.f64 - f0.f64));
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// fsubs f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// fmuls f11,f9,f9
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f9,f8,f8,f11
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f11.f64));
	// fmadds f10,f13,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fsqrts f7,f9
	ctx.f7.f64 = double(float(sqrt(ctx.f9.f64)));
	// fsqrts f8,f10
	ctx.f8.f64 = double(float(sqrt(ctx.f10.f64)));
	// fdivs f1,f8,f7
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x826225b8
	ctx.lr = 0x8262506C;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82625078:
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r10,2384
	ctx.r9.s64 = ctx.r10.s64 + 2384;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82625154
	if (cr6.eq) goto loc_82625154;
	// lvx128 v57,r0,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v56,r0,r25
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v61
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v61.f32)));
	// vsubfp128 v54,v56,v62
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x826250D4;
	sub_8216C900(ctx, base);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lvx128 v53,r0,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v53,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x826250FC;
	sub_8216C900(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, ctx.f1.f64);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bge cr6,0x82625138
	if (!cr6.lt) goto loc_82625138;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// bl 0x8261b168
	ctx.lr = 0x82625128;
	sub_8261B168(ctx, base);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82625138:
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// bl 0x8261b168
	ctx.lr = 0x82625144;
	sub_8261B168(ctx, base);
loc_82625144:
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82625154:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8261b168
	ctx.lr = 0x82625174;
	sub_8261B168(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826251b4
	if (cr6.eq) goto loc_826251B4;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826225b8
	ctx.lr = 0x826251A8;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_826251B4:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8261b168
	ctx.lr = 0x826251D4;
	sub_8261B168(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82625214
	if (cr6.eq) goto loc_82625214;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826225b8
	ctx.lr = 0x82625208;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82625214:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821ce4f0
	ctx.lr = 0x82625224;
	sub_821CE4F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821ce4f0
	ctx.lr = 0x82625234;
	sub_821CE4F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821ce4f0
	ctx.lr = 0x82625244;
	sub_821CE4F0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82621ff8
	ctx.lr = 0x82625260;
	sub_82621FF8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826252c0
	if (cr6.eq) goto loc_826252C0;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8261b020
	ctx.lr = 0x82625290;
	sub_8261B020(ctx, base);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826225b8
	ctx.lr = 0x826252B4;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_826252C0:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821ce4f0
	ctx.lr = 0x826252D0;
	sub_821CE4F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821ce4f0
	ctx.lr = 0x826252E0;
	sub_821CE4F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821ce4f0
	ctx.lr = 0x826252F0;
	sub_821CE4F0(ctx, base);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82621ff8
	ctx.lr = 0x82625304;
	sub_82621FF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82625144
	if (cr6.eq) goto loc_82625144;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8261b020
	ctx.lr = 0x82625334;
	sub_8261B020(ctx, base);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826225b8
	ctx.lr = 0x82625358;
	sub_826225B8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82625364"))) PPC_WEAK_FUNC(sub_82625364);
PPC_FUNC_IMPL(__imp__sub_82625364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82625368"))) PPC_WEAK_FUNC(sub_82625368);
PPC_FUNC_IMPL(__imp__sub_82625368) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82625370;
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// li r24,0
	r24.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// lwz r11,25000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 25000);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x826253c0
	if (cr6.lt) goto loc_826253C0;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9238
	return;
loc_826253C0:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v58,v60,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82625404
	if (cr6.eq) goto loc_82625404;
	// stvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9238
	return;
loc_82625404:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82624ec8
	ctx.lr = 0x8262541C;
	sub_82624EC8(ctx, base);
	// lwz r25,80(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v54,r0,r25
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v53,r0,r31
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v52,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x8262545C;
	sub_8216C900(ctx, base);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v51,r0,r29
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r31
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v48,v49,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v47,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v127,v47,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// vmaddcfp128 v127,v48,v127,v0
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v127.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsubfp128 v46,v50,v127
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbbc8
	ctx.lr = 0x826254A0;
	sub_823DBBC8(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// lfs f8,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f3,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// lfd f12,14304(r5)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r5.u32 + 14304);
	// fmadds f13,f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmuls f10,f7,f7
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fmadds f9,f0,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f8,f4,f4,f10
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f10.f64));
	// fsqrts f7,f9
	ctx.f7.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmadds f6,f1,f1,f8
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f8.f64));
	// fmuls f5,f11,f7
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// fsqrts f4,f6
	ctx.f4.f64 = double(float(sqrt(ctx.f6.f64)));
	// fdivs f0,f5,f4
	f0.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x82625540
	if (cr6.lt) goto loc_82625540;
	// lwz r11,25000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 25000);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v45,r0,r31
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,25000(r28)
	PPC_STORE_U32(r28.u32 + 25000, r11.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82625368
	ctx.lr = 0x8262553C;
	sub_82625368(ctx, base);
	// b 0x8262558c
	goto loc_8262558C;
loc_82625540:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8262555c
	if (!cr6.eq) goto loc_8262555C;
	// lvx128 v44,r0,r30
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8262558c
	goto loc_8262558C;
loc_8262555C:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82625570
	if (!cr6.lt) goto loc_82625570;
	// lvx128 v43,r0,r29
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8262558c
	goto loc_8262558C;
loc_82625570:
	// lvx128 v42,r0,r31
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v41,v42,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v127.f32)));
	// lvlx128 v40,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v39,v40,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vmaddfp128 v127,v41,v39,v127
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v39.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8262558C:
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r11,25000(r28)
	PPC_STORE_U32(r28.u32 + 25000, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826255A4"))) PPC_WEAK_FUNC(sub_826255A4);
PPC_FUNC_IMPL(__imp__sub_826255A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826255A8"))) PPC_WEAK_FUNC(sub_826255A8);
PPC_FUNC_IMPL(__imp__sub_826255A8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826255B0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82637538
	ctx.lr = 0x826255C0;
	sub_82637538(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,2148
	ctx.r9.s64 = r11.s64 + 2148;
	// addi r8,r10,-21868
	ctx.r8.s64 = ctx.r10.s64 + -21868;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// addi r4,r7,21428
	ctx.r4.s64 = ctx.r7.s64 + 21428;
	// bl 0x823db670
	ctx.lr = 0x826255F0;
	sub_823DB670(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r4,r6,-20452
	ctx.r4.s64 = ctx.r6.s64 + -20452;
	// addi r11,r5,-20464
	r11.s64 = ctx.r5.s64 + -20464;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// bl 0x82622260
	ctx.lr = 0x8262561C;
	sub_82622260(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r30,376(r31)
	PPC_STORE_U8(r31.u32 + 376, r30.u8);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stb r30,378(r31)
	PPC_STORE_U8(r31.u32 + 378, r30.u8);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stb r30,381(r31)
	PPC_STORE_U8(r31.u32 + 381, r30.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r30,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r30.u32);
	// lfs f0,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stw r30,592(r31)
	PPC_STORE_U32(r31.u32 + 592, r30.u32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r30.u32);
	// stfs f0,712(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// stw r30,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r30.u32);
	// stw r30,608(r31)
	PPC_STORE_U32(r31.u32 + 608, r30.u32);
	// lfs f0,-18668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18668);
	f0.f64 = double(temp.f32);
	// stw r30,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r30.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r30,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r30.u32);
	// lfs f13,-12080(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -12080);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r30.u32);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// stw r30,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r30.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stb r30,628(r31)
	PPC_STORE_U8(r31.u32 + 628, r30.u8);
	// stfs f31,720(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// stfs f31,724(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 724, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f31,728(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
	// stb r30,1400(r31)
	PPC_STORE_U8(r31.u32 + 1400, r30.u8);
	// stfs f0,1124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1124, temp.u32);
	// stw r30,1512(r31)
	PPC_STORE_U32(r31.u32 + 1512, r30.u32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r11,1520(r31)
	PPC_STORE_U8(r31.u32 + 1520, r11.u8);
	// stfs f13,1128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
	// stw r30,1540(r31)
	PPC_STORE_U32(r31.u32 + 1540, r30.u32);
	// stfs f0,1396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// stw r30,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, r30.u32);
	// stb r11,372(r31)
	PPC_STORE_U8(r31.u32 + 372, r11.u8);
	// addi r5,r5,-1520
	ctx.r5.s64 = ctx.r5.s64 + -1520;
	// stb r11,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r11.u8);
	// li r6,10
	ctx.r6.s64 = 10;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x826256D0;
	sub_8268B960(ctx, base);
	// stw r3,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,-18684
	ctx.r5.s64 = ctx.r4.s64 + -18684;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826256EC;
	sub_8268B960(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r3,1552(r31)
	PPC_STORE_U32(r31.u32 + 1552, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// lfs f0,-18688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18688);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,-1684(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1684);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stfs f0,388(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f12,-28736(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28736);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stfs f12,500(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r30,1120(r31)
	PPC_STORE_U8(r31.u32 + 1120, r30.u8);
	// stw r30,1516(r31)
	PPC_STORE_U32(r31.u32 + 1516, r30.u32);
	// lfs f0,18108(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 18108);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// li r3,208
	ctx.r3.s64 = 208;
	// stfs f0,512(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stfs f13,516(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// lfs f12,-29800(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29800);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,520(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// lfs f0,-18692(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18692);
	f0.f64 = double(temp.f32);
	// lfs f13,-15948(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -15948);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29484(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29484);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,528(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stfs f31,532(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stfs f13,536(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// stfs f12,560(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 560, temp.u32);
	// stfs f11,564(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 564, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8262577C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82625794
	if (cr6.eq) goto loc_82625794;
	// bl 0x8221d330
	ctx.lr = 0x82625788;
	sub_8221D330(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// bne cr6,0x82625798
	if (!cr6.eq) goto loc_82625798;
loc_82625794:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82625798:
	// stw r11,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r11.u32);
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x826257A4;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r28,r11,7132
	r28.s64 = r11.s64 + 7132;
	// beq cr6,0x826257d0
	if (cr6.eq) goto loc_826257D0;
	// bl 0x82637538
	ctx.lr = 0x826257BC;
	sub_82637538(ctx, base);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// stw r30,144(r29)
	PPC_STORE_U32(r29.u32 + 144, r30.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r30,148(r29)
	PPC_STORE_U32(r29.u32 + 148, r30.u32);
	// b 0x826257d4
	goto loc_826257D4;
loc_826257D0:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_826257D4:
	// stw r11,608(r31)
	PPC_STORE_U32(r31.u32 + 608, r11.u32);
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x826257E0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82625804
	if (cr6.eq) goto loc_82625804;
	// bl 0x82637538
	ctx.lr = 0x826257F0;
	sub_82637538(ctx, base);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// stw r30,144(r29)
	PPC_STORE_U32(r29.u32 + 144, r30.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r30,148(r29)
	PPC_STORE_U32(r29.u32 + 148, r30.u32);
	// b 0x82625808
	goto loc_82625808;
loc_82625804:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82625808:
	// stw r11,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,1168(r31)
	PPC_STORE_U8(r31.u32 + 1168, r30.u8);
	// bl 0x82130000
	ctx.lr = 0x82625818;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f890
	ctx.lr = 0x82625820;
	sub_8261F890(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262582C"))) PPC_WEAK_FUNC(sub_8262582C);
PPC_FUNC_IMPL(__imp__sub_8262582C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82625830"))) PPC_WEAK_FUNC(sub_82625830);
PPC_FUNC_IMPL(__imp__sub_82625830) {
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
	// bl 0x82622ac0
	ctx.lr = 0x82625850;
	sub_82622AC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82625868
	if (cr6.eq) goto loc_82625868;
	// bl 0x82130588
	ctx.lr = 0x82625864;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82625868:
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

__attribute__((alias("__imp__sub_82625880"))) PPC_WEAK_FUNC(sub_82625880);
PPC_FUNC_IMPL(__imp__sub_82625880) {
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
	PPCRegister f0{};
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
	// bl 0x823d91f4
	ctx.lr = 0x82625888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826258A4;
	sub_821F9FB8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826258C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82635af8
	ctx.lr = 0x826258C8;
	sub_82635AF8(ctx, base);
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826258f8
	if (!cr6.eq) goto loc_826258F8;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x826258E0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826258f0
	if (cr6.eq) goto loc_826258F0;
	// bl 0x8262b910
	ctx.lr = 0x826258EC;
	sub_8262B910(ctx, base);
	// b 0x826258f4
	goto loc_826258F4;
loc_826258F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826258F4:
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
loc_826258F8:
	// stw r30,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r30.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x82625904;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82625918
	if (cr6.eq) goto loc_82625918;
	// bl 0x82624910
	ctx.lr = 0x82625910;
	sub_82624910(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8262591c
	goto loc_8262591C;
loc_82625918:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_8262591C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r4.u32);
	// lwz r10,368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r4,r9,6124
	ctx.r4.s64 = ctx.r9.s64 + 6124;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r8,23804
	r28.s64 = ctx.r8.s64 + 23804;
	// addi r27,r7,-22108
	r27.s64 = ctx.r7.s64 + -22108;
	// bl 0x8268dce0
	ctx.lr = 0x82625954;
	sub_8268DCE0(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82625968;
	sub_823DEDD8(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r6,-1676
	ctx.r4.s64 = ctx.r6.s64 + -1676;
	// addi r28,r5,-19700
	r28.s64 = ctx.r5.s64 + -19700;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8262598C;
	sub_82691650(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826259A0;
	sub_823DEDD8(ctx, base);
	// stw r3,1508(r31)
	PPC_STORE_U32(r31.u32 + 1508, ctx.r3.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r28,r3,-18736
	r28.s64 = ctx.r3.s64 + -18736;
	// addi r4,r4,-18656
	ctx.r4.s64 = ctx.r4.s64 + -18656;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826259C4;
	sub_82691650(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826259D8;
	sub_823DEDD8(ctx, base);
	// stw r3,1500(r31)
	PPC_STORE_U32(r31.u32 + 1500, ctx.r3.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-18664
	ctx.r4.s64 = ctx.r10.s64 + -18664;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826259F4;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82625A08;
	sub_823DEDD8(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,800
	r11.s64 = r31.s64 + 800;
	// stw r3,1504(r31)
	PPC_STORE_U32(r31.u32 + 1504, ctx.r3.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
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
	// li r7,48
	ctx.r7.s64 = 48;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r6,1
	ctx.r6.s64 = 1;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r30.u8);
	// lfs f13,320(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r30.u8);
	// stfs f13,1128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
	// stfs f0,1476(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1476, temp.u32);
	// stfs f0,1480(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1480, temp.u32);
	// stb r30,1528(r31)
	PPC_STORE_U8(r31.u32 + 1528, r30.u8);
	// stb r6,377(r31)
	PPC_STORE_U8(r31.u32 + 377, ctx.r6.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82625A74"))) PPC_WEAK_FUNC(sub_82625A74);
PPC_FUNC_IMPL(__imp__sub_82625A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82625A78"))) PPC_WEAK_FUNC(sub_82625A78);
PPC_FUNC_IMPL(__imp__sub_82625A78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82625a9c
	if (cr6.eq) goto loc_82625A9C;
	// lbz r11,628(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 628);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82625A9C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82625AB0"))) PPC_WEAK_FUNC(sub_82625AB0);
PPC_FUNC_IMPL(__imp__sub_82625AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82623288
	sub_82623288(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82625ABC"))) PPC_WEAK_FUNC(sub_82625ABC);
PPC_FUNC_IMPL(__imp__sub_82625ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82625AC0"))) PPC_WEAK_FUNC(sub_82625AC0);
PPC_FUNC_IMPL(__imp__sub_82625AC0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82625AC8;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
	// addi r6,r1,116
	ctx.r6.s64 = ctx.r1.s64 + 116;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82625B14;
	sub_8217C570(ctx, base);
	// clrlwi r8,r24,24
	ctx.r8.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82625cfc
	if (!cr6.eq) goto loc_82625CFC;
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r11,45
	ctx.r7.s64 = r11.s64 + 45;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r6,688(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// lfs f13,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f13.f64 = double(temp.f32);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f12,f3
	cr6.compare(ctx.f12.f64, ctx.f3.f64);
	// ble cr6,0x82625cfc
	if (!cr6.gt) goto loc_82625CFC;
	// lwz r8,692(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f11,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fcmpu cr6,f13,f2
	cr6.compare(ctx.f13.f64, ctx.f2.f64);
	// ble cr6,0x82625cfc
	if (!cr6.gt) goto loc_82625CFC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r8,688(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// lfs f11,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f11.f64 = double(temp.f32);
	// fmr f10,f11
	ctx.f10.f64 = ctx.f11.f64;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// fmuls f4,f7,f11
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f1,80(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// fmuls f11,f3,f10
	ctx.f11.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f1
	ctx.f8.f64 = double(ctx.f1.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fnmsubs f4,f5,f0,f6
	ctx.f4.f64 = double(float(-(ctx.f5.f64 * f0.f64 - ctx.f6.f64)));
	// fcmpu cr6,f12,f4
	cr6.compare(ctx.f12.f64, ctx.f4.f64);
	// bgt cr6,0x82625cfc
	if (cr6.gt) goto loc_82625CFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r10,692(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fmuls f4,f6,f12
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// fmuls f3,f5,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fctiwz f1,f3
	ctx.f1.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fnmsubs f6,f8,f0,f7
	ctx.f6.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f7.f64)));
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82625f40
	if (!cr6.gt) goto loc_82625F40;
loc_82625CFC:
	// lbz r11,1520(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1520);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82625f40
	if (cr6.eq) goto loc_82625F40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82625f40
	if (cr6.eq) goto loc_82625F40;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625D24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82625f40
	if (cr6.eq) goto loc_82625F40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82625de0
	if (cr6.eq) goto loc_82625DE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,728(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 728);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,760(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 760);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82625D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,564(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 564);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82625D9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82625dbc
	if (cr6.eq) goto loc_82625DBC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625DBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82625DBC:
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x82625de8
	if (cr6.eq) goto loc_82625DE8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 756);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625DDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82625de8
	goto loc_82625DE8;
loc_82625DE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8261fd58
	ctx.lr = 0x82625DE8;
	sub_8261FD58(ctx, base);
loc_82625DE8:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82625e24
	if (!cr6.eq) goto loc_82625E24;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625E14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82625E24:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f1,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261fc88
	ctx.lr = 0x82625E38;
	sub_8261FC88(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,724(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 724);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82625E8C;
	sub_82202EC0(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82623350
	ctx.lr = 0x82625E98;
	sub_82623350(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r30,1056
	ctx.r4.s64 = r30.s64 + 1056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,648(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82625EB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,208(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 208);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82625EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,632(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 632);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,636(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 636);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82625EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82625F08;
	sub_82220980(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82625f40
	if (cr6.eq) goto loc_82625F40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,744(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 744);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625F28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82625F40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82625F40:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82625F4C"))) PPC_WEAK_FUNC(sub_82625F4C);
PPC_FUNC_IMPL(__imp__sub_82625F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82625F50"))) PPC_WEAK_FUNC(sub_82625F50);
PPC_FUNC_IMPL(__imp__sub_82625F50) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x82625F58;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d8
	ctx.lr = 0x82625F60;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r30,r28,24
	r30.u64 = r28.u32 & 0xFF;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82625fcc
	if (!cr6.eq) goto loc_82625FCC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623350
	ctx.lr = 0x82625FC4;
	sub_82623350(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8262601c
	if (cr6.eq) goto loc_8262601C;
loc_82625FCC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82625FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262601c
	if (!cr6.eq) goto loc_8262601C;
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x82626004
	if (!cr6.lt) goto loc_82626004;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82626004:
	// lfs f0,1128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x82626020
	if (!cr6.gt) goto loc_82626020;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82626020
	goto loc_82626020;
loc_8262601C:
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
loc_82626020:
	// lfs f13,1152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82626038
	if (!cr6.lt) goto loc_82626038;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82626038:
	// lfs f13,1156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1156);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82626048
	if (!cr6.gt) goto loc_82626048;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82626048:
	// lfs f13,1164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82626060
	if (!cr6.gt) goto loc_82626060;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_82626060:
	// lfs f13,1160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1160);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82626070
	if (!cr6.lt) goto loc_82626070;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_82626070:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f29,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f28,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f28.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82626208
	if (!cr6.lt) goto loc_82626208;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_826260AC:
	// fsubs f13,f29,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f29.f64 - f0.f64));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f0,-21460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fabs f30,f12
	f30.u64 = ctx.f12.u64 & ~0x8000000000000000;
loc_826260C0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r6,272(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fsubs f2,f0,f30
	ctx.f2.f64 = double(float(f0.f64 - f30.f64));
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x8261b4d0
	ctx.lr = 0x826260F4;
	sub_8261B4D0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82626128
	if (!cr6.eq) goto loc_82626128;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r31,720
	ctx.r4.s64 = r31.s64 + 720;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82625368
	ctx.lr = 0x82626114;
	sub_82625368(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 + f30.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82626128:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vsubfp128 v59,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82626168;
	sub_82202EC0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,516(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 516);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262617C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8262619c
	if (cr6.eq) goto loc_8262619C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r10,728(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 728);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262619C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262619C:
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826261b0
	if (cr6.eq) goto loc_826261B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fd58
	ctx.lr = 0x826261B0;
	sub_8261FD58(ctx, base);
loc_826261B0:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82626250
	if (!cr6.eq) goto loc_82626250;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826261D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82626218
	if (cr6.eq) goto loc_82626218;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82626218
	if (!cr6.eq) goto loc_82626218;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82626218
	if (cr6.eq) goto loc_82626218;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,636(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 636);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826262b8
	goto loc_826262B8;
loc_82626208:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x826260ac
	if (!cr6.gt) goto loc_826260AC;
	// fmr f30,f28
	f30.f64 = f28.f64;
	// b 0x826260c0
	goto loc_826260C0;
loc_82626218:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// beq cr6,0x82626240
	if (cr6.eq) goto loc_82626240;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625ac0
	ctx.lr = 0x8262623C;
	sub_82625AC0(ctx, base);
	// b 0x826262b8
	goto loc_826262B8;
loc_82626240:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1512(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// bl 0x82625ac0
	ctx.lr = 0x8262624C;
	sub_82625AC0(ctx, base);
	// b 0x826262b8
	goto loc_826262B8;
loc_82626250:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r31,1056
	r30.s64 = r31.s64 + 1056;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8261f2e8
	ctx.lr = 0x82626264;
	sub_8261F2E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8262627c
	if (!cr6.eq) goto loc_8262627C;
	// lfs f0,200(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 + f28.f64));
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
loc_8262627C:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r30,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826262B8:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82620568
	ctx.lr = 0x826262C4;
	sub_82620568(ctx, base);
	// lfs f0,1104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1104);
	f0.f64 = double(temp.f32);
	// lfs f13,1112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1112);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,1312(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1312, temp.u32);
	// stfs f0,1248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1248, temp.u32);
	// stfs f0,1376(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1376, temp.u32);
	// stfs f13,1320(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1320, temp.u32);
	// stfs f13,1256(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1256, temp.u32);
	// stfs f13,1384(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1384, temp.u32);
	// bl 0x82623ee8
	ctx.lr = 0x826262EC;
	sub_82623EE8(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x826262F8;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826262FC"))) PPC_WEAK_FUNC(sub_826262FC);
PPC_FUNC_IMPL(__imp__sub_826262FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82626300"))) PPC_WEAK_FUNC(sub_82626300);
PPC_FUNC_IMPL(__imp__sub_82626300) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82626308;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfa8
	ctx.lr = 0x82626318;
	sub_8262BFA8(ctx, base);
	// addi r11,r31,1056
	r11.s64 = r31.s64 + 1056;
	// lfs f0,448(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 448);
	f0.f64 = double(temp.f32);
	// li r10,48
	ctx.r10.s64 = 48;
	// lfs f13,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r30,r31,448
	r30.s64 = r31.s64 + 448;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x82626378;
	sub_826208D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826202a8
	ctx.lr = 0x82626384;
	sub_826202A8(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x826263b0
	if (!cr6.eq) goto loc_826263B0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625f50
	ctx.lr = 0x826263B0;
	sub_82625F50(ctx, base);
loc_826263B0:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826263C0"))) PPC_WEAK_FUNC(sub_826263C0);
PPC_FUNC_IMPL(__imp__sub_826263C0) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x826263C8;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stfs f1,240(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f2,244(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stfs f3,248(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r9,2384
	ctx.r7.s64 = ctx.r9.s64 + 2384;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r30,r31,448
	r30.s64 = r31.s64 + 448;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vand128 v59,v60,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vaddfp128 v55,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vsubfp128 v54,v59,v58
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vcmpgefp128 v53,v55,v56
	simde_mm_store_ps(v53.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vcmpgefp128 v52,v56,v54
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32)));
	// vand128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vcmpequw128. v50,v51,v62
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82626750
	if (!cr6.eq) goto loc_82626750;
	// addi r29,r31,112
	r29.s64 = r31.s64 + 112;
	// lwz r6,272(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// fmr f2,f3
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = ctx.f3.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8261b4d0
	ctx.lr = 0x82626464;
	sub_8261B4D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82626484
	if (!cr6.eq) goto loc_82626484;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82625368
	ctx.lr = 0x82626484;
	sub_82625368(ctx, base);
loc_82626484:
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// lbz r10,496(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stvx128 v49,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82626730
	if (cr6.eq) goto loc_82626730;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826264B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	f0.f64 = double(temp.f32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f13,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lfs f12,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r7,-21440
	r29.s64 = ctx.r7.s64 + -21440;
	// lfs f11,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// lwz r6,468(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f30,f3
	f30.f64 = double(float(sqrt(ctx.f3.f64)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82626504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82626510;
	sub_825EE0E0(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f2,544(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 544);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// fadds f31,f2,f1
	f31.f64 = double(float(ctx.f2.f64 + ctx.f1.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82626530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r30,4
	r30.s64 = 4;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r29,r11,-18628
	r29.s64 = r11.s64 + -18628;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x82626554;
	sub_82203058(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,452(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	ctx.f13.f64 = double(temp.f32);
	// fadds f31,f0,f13
	f31.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82626574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x8262658C;
	sub_82203058(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f12,552(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 552);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f11,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f11.f64 = double(temp.f32);
	// fadds f31,f12,f11
	f31.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lwz r7,468(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826265AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82203058
	ctx.lr = 0x826265C4;
	sub_82203058(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,468(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 468);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826265D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r28,0
	r28.s64 = 0;
	// li r29,3
	r29.s64 = 3;
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r28.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// addi r27,r4,-18648
	r27.s64 = ctx.r4.s64 + -18648;
	// addi r6,r1,136
	ctx.r6.s64 = ctx.r1.s64 + 136;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82203058
	ctx.lr = 0x82626600;
	sub_82203058(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r6,r1,152
	ctx.r6.s64 = ctx.r1.s64 + 152;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x8262662C;
	sub_82203058(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,468(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82626640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r28.u32);
	// stw r29,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r29.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r6,r1,168
	ctx.r6.s64 = ctx.r1.s64 + 168;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82203058
	ctx.lr = 0x82626658;
	sub_82203058(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f10,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f10.f64 = double(temp.f32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f8,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f8.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,-26236(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26236);
	f31.f64 = double(temp.f32);
	// fmadds f9,f10,f30,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64 + f31.f64));
	// lwz r5,468(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 468);
	// fmuls f29,f9,f8
	f29.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82626684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f29,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r6,r1,184
	ctx.r6.s64 = ctx.r1.s64 + 184;
	// addi r29,r4,-19880
	r29.s64 = ctx.r4.s64 + -19880;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x826266A4;
	sub_82203058(ctx, base);
	// lfs f7,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f7,f30,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 * f30.f64 + f31.f64));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f5,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f5.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// fmuls f29,f6,f5
	f29.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826266C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f29,200(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,200
	ctx.r6.s64 = ctx.r1.s64 + 200;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x826266E0;
	sub_82203058(ctx, base);
	// lfs f4,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f4,f30,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 * f30.f64 + f31.f64));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f2,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,468(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// fmuls f31,f3,f2
	f31.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82626704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,216(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,216
	ctx.r6.s64 = ctx.r1.s64 + 216;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82203058
	ctx.lr = 0x8262671C;
	sub_82203058(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82626730:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// addi r31,r10,-21440
	r31.s64 = ctx.r10.s64 + -21440;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82626744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82626750;
	sub_825EE0E0(ctx, base);
loc_82626750:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
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

__attribute__((alias("__imp__sub_82626764"))) PPC_WEAK_FUNC(sub_82626764);
PPC_FUNC_IMPL(__imp__sub_82626764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82626768"))) PPC_WEAK_FUNC(sub_82626768);
PPC_FUNC_IMPL(__imp__sub_82626768) {
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
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x8262677C;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82626948
	if (cr6.eq) goto loc_82626948;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826267B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,1128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// li r6,720
	ctx.r6.s64 = 720;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f29.f64 = double(temp.f32);
	// fsubs f11,f29,f0
	ctx.f11.f64 = double(float(f29.f64 - f0.f64));
	// fdivs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lvx128 v62,r31,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,1396(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82626808
	if (!cr6.lt) goto loc_82626808;
	// stfs f31,1396(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
loc_82626808:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,1396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1396);
	f0.f64 = double(temp.f32);
	// lfs f28,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fsubs f1,f28,f0
	ctx.f1.f64 = double(float(f28.f64 - f0.f64));
	// bl 0x82502110
	ctx.lr = 0x8262681C;
	sub_82502110(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,3468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3468);
	f0.f64 = double(temp.f32);
	// lfs f27,-11620(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11620);
	f27.f64 = double(temp.f32);
	// fmsubs f13,f1,f0,f27
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 - f27.f64));
	// stfs f13,1392(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x82626840
	if (!cr6.lt) goto loc_82626840;
	// stfs f31,1392(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
loc_82626840:
	// lfs f1,1392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1392);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82227c70
	ctx.lr = 0x82626848;
	sub_82227C70(ctx, base);
	// lfs f13,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// fmr f9,f1
	ctx.f9.f64 = ctx.f1.f64;
	// lfs f12,1128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f10,1108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1108);
	ctx.f10.f64 = double(temp.f32);
	// stfs f1,1396(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// fmadds f31,f11,f9,f13
	f31.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f13.f64));
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bge cr6,0x82626880
	if (!cr6.lt) goto loc_82626880;
	// li r11,0
	r11.s64 = 0;
	// stb r11,1400(r31)
	PPC_STORE_U8(r31.u32 + 1400, r11.u8);
loc_82626880:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,712(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 712);
	f0.f64 = double(temp.f32);
	// lfd f30,32224(r11)
	f30.u64 = PPC_LOAD_U64(r11.u32 + 32224);
	// fmul f1,f0,f30
	ctx.f1.f64 = f0.f64 * f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82626894;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,712(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 712);
	ctx.f12.f64 = double(temp.f32);
	// fmul f1,f12,f30
	ctx.f1.f64 = ctx.f12.f64 * f30.f64;
	// fmuls f30,f13,f29
	f30.f64 = double(float(ctx.f13.f64 * f29.f64));
	// bl 0x823dbae8
	ctx.lr = 0x826268A8;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lbz r10,496(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fsubs f9,f30,f10
	ctx.f9.f64 = double(float(f30.f64 - ctx.f10.f64));
	// fdivs f0,f9,f10
	f0.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// beq cr6,0x826268fc
	if (cr6.eq) goto loc_826268FC;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f11,448(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fmadds f7,f10,f0,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f13.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f6,f8,f0,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f12.f64));
	// bl 0x8261fc88
	ctx.lr = 0x826268F4;
	sub_8261FC88(ctx, base);
	// fadds f5,f1,f6
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f5,88(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_826268FC:
	// lfs f0,1180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1180);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x82626914
	if (!cr6.gt) goto loc_82626914;
	// fmuls f0,f31,f27
	f0.f64 = double(float(f31.f64 * f27.f64));
	// stfs f0,1180(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1180, temp.u32);
	// b 0x82626918
	goto loc_82626918;
loc_82626914:
	// stfs f28,1180(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 1180, temp.u32);
loc_82626918:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623ee8
	ctx.lr = 0x82626920;
	sub_82623EE8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625f50
	ctx.lr = 0x82626940;
	sub_82625F50(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,396(r31)
	PPC_STORE_U8(r31.u32 + 396, r11.u8);
loc_82626948:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x82626954;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82626964"))) PPC_WEAK_FUNC(sub_82626964);
PPC_FUNC_IMPL(__imp__sub_82626964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82626968"))) PPC_WEAK_FUNC(sub_82626968);
PPC_FUNC_IMPL(__imp__sub_82626968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCVRegister v62{};
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
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9bc
	ctx.lr = 0x82626980;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82626b94
	if (cr6.eq) goto loc_82626B94;
	// li r11,720
	r11.s64 = 720;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,208(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826269C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,1108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1108);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,1128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// stfs f9,1396(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// fabs f8,f9
	ctx.f8.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f30
	cr6.compare(ctx.f8.f64, f30.f64);
	// bge cr6,0x82626a0c
	if (!cr6.lt) goto loc_82626A0C;
	// stfs f30,1396(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
loc_82626A0C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,1396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1396);
	f0.f64 = double(temp.f32);
	// lfs f21,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f21.f64 = double(temp.f32);
	// fsubs f1,f21,f0
	ctx.f1.f64 = double(float(f21.f64 - f0.f64));
	// bl 0x82502110
	ctx.lr = 0x82626A20;
	sub_82502110(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,3468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3468);
	f0.f64 = double(temp.f32);
	// lfs f13,-11620(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11620);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// stfs f13,1392(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
	// fcmpu cr6,f13,f21
	cr6.compare(ctx.f13.f64, f21.f64);
	// ble cr6,0x82626a44
	if (!cr6.gt) goto loc_82626A44;
	// stfs f21,1392(r31)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
loc_82626A44:
	// lfs f1,1392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1392);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82227c70
	ctx.lr = 0x82626A4C;
	sub_82227C70(ctx, base);
	// lfs f13,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// fmr f11,f1
	ctx.f11.f64 = ctx.f1.f64;
	// lfs f0,1128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stfs f1,1396(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// li r30,1
	r30.s64 = 1;
	// fsubs f23,f10,f13
	f23.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f24,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f24.f64 = double(temp.f32);
	// fmadds f31,f12,f11,f13
	f31.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fsubs f22,f31,f13
	f22.f64 = double(float(f31.f64 - ctx.f13.f64));
	// fcmpu cr6,f31,f24
	cr6.compare(f31.f64, f24.f64);
	// ble cr6,0x82626a8c
	if (!cr6.gt) goto loc_82626A8C;
	// stb r30,1400(r31)
	PPC_STORE_U8(r31.u32 + 1400, r30.u8);
loc_82626A8C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// lfs f26,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f26.f64 = double(temp.f32);
	// lfs f25,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f25.f64 = double(temp.f32);
	// fsubs f1,f13,f26
	ctx.f1.f64 = double(float(ctx.f13.f64 - f26.f64));
	// lfs f12,360(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f27,f12,f25
	f27.f64 = double(float(ctx.f12.f64 - f25.f64));
	// lfs f29,-12072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12072);
	f29.f64 = double(temp.f32);
	// fadds f11,f0,f29
	ctx.f11.f64 = double(float(f0.f64 + f29.f64));
	// fsubs f2,f11,f31
	ctx.f2.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fcmpu cr6,f2,f30
	cr6.compare(ctx.f2.f64, f30.f64);
	// bne cr6,0x82626acc
	if (!cr6.eq) goto loc_82626ACC;
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// bne cr6,0x82626acc
	if (!cr6.eq) goto loc_82626ACC;
	// fmr f28,f30
	f28.f64 = f30.f64;
	// b 0x82626ad4
	goto loc_82626AD4;
loc_82626ACC:
	// bl 0x823dcdd8
	ctx.lr = 0x82626AD0;
	sub_823DCDD8(ctx, base);
	// frsp f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64));
loc_82626AD4:
	// lfs f0,1128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// fsubs f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fcmpu cr6,f2,f30
	cr6.compare(ctx.f2.f64, f30.f64);
	// bne cr6,0x82626af8
	if (!cr6.eq) goto loc_82626AF8;
	// fcmpu cr6,f27,f30
	cr6.compare(f27.f64, f30.f64);
	// bne cr6,0x82626af8
	if (!cr6.eq) goto loc_82626AF8;
	// fmr f29,f30
	f29.f64 = f30.f64;
	// b 0x82626b04
	goto loc_82626B04;
loc_82626AF8:
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x823dcdd8
	ctx.lr = 0x82626B00;
	sub_823DCDD8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
loc_82626B04:
	// fsubs f27,f22,f23
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f22.f64 - f23.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbf10
	ctx.lr = 0x82626B10;
	sub_823DBF10(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// fadds f12,f13,f26
	ctx.f12.f64 = double(float(ctx.f13.f64 + f26.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823dbf10
	ctx.lr = 0x82626B28;
	sub_823DBF10(ctx, base);
	// lfs f11,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// fsubs f9,f24,f11
	ctx.f9.f64 = double(float(f24.f64 - ctx.f11.f64));
	// frsp f8,f1
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// fdivs f0,f10,f9
	f0.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fmadds f13,f8,f27,f25
	ctx.f13.f64 = double(float(ctx.f8.f64 * f27.f64 + f25.f64));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82626bb4
	if (!cr6.lt) goto loc_82626BB4;
	// fmr f0,f30
	f0.f64 = f30.f64;
loc_82626B4C:
	// fsubs f12,f21,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f21.f64 - f0.f64));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f0,-21460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21460);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fabs f0,f11
	f0.u64 = ctx.f11.u64 & ~0x8000000000000000;
loc_82626B60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82623ee8
	ctx.lr = 0x82626B70;
	sub_82623EE8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625f50
	ctx.lr = 0x82626B90;
	sub_82625F50(ctx, base);
	// stb r30,396(r31)
	PPC_STORE_U8(r31.u32 + 396, r30.u8);
loc_82626B94:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba08
	ctx.lr = 0x82626BA0;
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
loc_82626BB4:
	// fcmpu cr6,f0,f21
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f21.f64);
	// ble cr6,0x82626b4c
	if (!cr6.gt) goto loc_82626B4C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// b 0x82626b60
	goto loc_82626B60;
}

__attribute__((alias("__imp__sub_82626BC8"))) PPC_WEAK_FUNC(sub_82626BC8);
PPC_FUNC_IMPL(__imp__sub_82626BC8) {
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
	// bl 0x8263b730
	ctx.lr = 0x82626BD8;
	sub_8263B730(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r10,248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 248, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82626BFC"))) PPC_WEAK_FUNC(sub_82626BFC);
PPC_FUNC_IMPL(__imp__sub_82626BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82626C00"))) PPC_WEAK_FUNC(sub_82626C00);
PPC_FUNC_IMPL(__imp__sub_82626C00) {
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
	ctx.lr = 0x82626C08;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82635af8
	ctx.lr = 0x82626C14;
	sub_82635AF8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,23536
	ctx.r4.s64 = ctx.r10.s64 + 23536;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82626C28;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82626C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,7
	r11.s64 = 7;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-18584
	ctx.r4.s64 = ctx.r7.s64 + -18584;
	// lwz r31,32(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// bl 0x825ef9a8
	ctx.lr = 0x82626C8C;
	sub_825EF9A8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626CA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-16308
	ctx.r4.s64 = ctx.r9.s64 + -16308;
	// bl 0x825ef9a8
	ctx.lr = 0x82626CB8;
	sub_825EF9A8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9f0
	ctx.lr = 0x82626CC0;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82626CD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-18592
	ctx.r4.s64 = ctx.r6.s64 + -18592;
	// bl 0x825ef9a8
	ctx.lr = 0x82626CE8;
	sub_825EF9A8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x825ef9f0
	ctx.lr = 0x82626CF0;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626D08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-18600
	ctx.r4.s64 = ctx.r9.s64 + -18600;
	// bl 0x825ef9a8
	ctx.lr = 0x82626D18;
	sub_825EF9A8(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x825ef9f0
	ctx.lr = 0x82626D20;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82626D38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r31,r6,-18484
	r31.s64 = ctx.r6.s64 + -18484;
	// addi r29,r5,14088
	r29.s64 = ctx.r5.s64 + 14088;
	// bl 0x825ef9f0
	ctx.lr = 0x82626D50;
	sub_825EF9F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82626D64;
	sub_823DEDD8(ctx, base);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r4,-18288
	ctx.r6.s64 = ctx.r4.s64 + -18288;
	// addi r5,r11,14116
	ctx.r5.s64 = r11.s64 + 14116;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82626D84;
	sub_823DEDD8(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,480(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 480);
	// lhz r26,28(r9)
	r26.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82626DA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82626e28
	if (cr6.eq) goto loc_82626E28;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r28,r11,-22132
	r28.s64 = r11.s64 + -22132;
	// addi r27,r10,23984
	r27.s64 = ctx.r10.s64 + 23984;
loc_82626DC0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626DD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,196(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82626DEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82626E04;
	sub_823DEDD8(ctx, base);
	// stw r26,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r26.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,484(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 484);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82626E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82626dc0
	if (!cr6.eq) goto loc_82626DC0;
loc_82626E28:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r11,30
	r11.s64 = 30;
	// addi r8,r9,24432
	ctx.r8.s64 = ctx.r9.s64 + 24432;
	// li r10,60
	ctx.r10.s64 = 60;
	// stw r11,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r11.u32);
	// stw r11,24432(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24432, r11.u32);
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82626E4C"))) PPC_WEAK_FUNC(sub_82626E4C);
PPC_FUNC_IMPL(__imp__sub_82626E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82626E50"))) PPC_WEAK_FUNC(sub_82626E50);
PPC_FUNC_IMPL(__imp__sub_82626E50) {
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
	// lwz r10,68(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// li r11,0
	r11.s64 = 0;
	// lwz r6,1320(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1320);
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,148(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 148);
	// ble cr6,0x82626ec4
	if (!cr6.gt) goto loc_82626EC4;
	// lwz r8,1316(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1316);
	// addi r9,r3,800
	ctx.r9.s64 = ctx.r3.s64 + 800;
loc_82626E84:
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srawi r5,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 7;
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r5,r5,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// subf r10,r5,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r5.s64;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r5,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// lwz r5,68(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r5,148(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// cmpw cr6,r5,r7
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, xer);
	// blt cr6,0x82626f18
	if (cr6.lt) goto loc_82626F18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x82626e84
	if (cr6.lt) goto loc_82626E84;
loc_82626EC4:
	// lwz r10,1320(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1320);
	// addi r11,r3,800
	r11.s64 = ctx.r3.s64 + 800;
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// beq cr6,0x82626f08
	if (cr6.eq) goto loc_82626F08;
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82626ef0
	if (!cr6.eq) goto loc_82626EF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_82626EF0:
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r4.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r8.u32);
loc_82626F08:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82626F18:
	// addi r5,r1,124
	ctx.r5.s64 = ctx.r1.s64 + 124;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x82621eb8
	ctx.lr = 0x82626F28;
	sub_82621EB8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82626F38"))) PPC_WEAK_FUNC(sub_82626F38);
PPC_FUNC_IMPL(__imp__sub_82626F38) {
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
	ctx.lr = 0x82626F40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822b9708
	ctx.lr = 0x82626F4C;
	sub_822B9708(ctx, base);
	// lis r26,-32112
	r26.s64 = -2104492032;
	// li r31,0
	r31.s64 = 0;
	// lwz r8,24448(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24448);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82626f7c
	if (!cr6.gt) goto loc_82626F7C;
loc_82626F60:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82621870
	ctx.lr = 0x82626F6C;
	sub_82621870(ctx, base);
	// lwz r8,24448(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24448);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x82626f60
	if (cr6.lt) goto loc_82626F60;
loc_82626F7C:
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82627008
	if (!cr6.gt) goto loc_82627008;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r30,r10,-22132
	r30.s64 = ctx.r10.s64 + -22132;
	// addi r29,r11,23984
	r29.s64 = r11.s64 + 23984;
loc_82626F98:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82626ff8
	if (cr6.eq) goto loc_82626FF8;
loc_82626FBC:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82626FD4;
	sub_823DEDD8(ctx, base);
	// bl 0x826247a0
	ctx.lr = 0x82626FD8;
	sub_826247A0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,484(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 484);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82626FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82626fbc
	if (!cr6.eq) goto loc_82626FBC;
loc_82626FF8:
	// lwz r8,24448(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24448);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r8
	cr6.compare<int32_t>(r28.s32, ctx.r8.s32, xer);
	// blt cr6,0x82626f98
	if (cr6.lt) goto loc_82626F98;
loc_82627008:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,24472
	r11.s64 = r11.s64 + 24472;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
	// stw r6,516(r11)
	PPC_STORE_U32(r11.u32 + 516, ctx.r6.u32);
	// stw r9,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r9.u32);
	// ble cr6,0x82627078
	if (!cr6.gt) goto loc_82627078;
loc_82627034:
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// beq cr6,0x8262706c
	if (cr6.eq) goto loc_8262706C;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82627054
	if (!cr6.eq) goto loc_82627054;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_82627054:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,512(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
loc_8262706C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x82627034
	if (cr6.lt) goto loc_82627034;
loc_82627078:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82627080"))) PPC_WEAK_FUNC(sub_82627080);
PPC_FUNC_IMPL(__imp__sub_82627080) {
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
	ctx.lr = 0x82627088;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32112
	r27.s64 = -2104492032;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r8,24448(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 24448);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826270c0
	if (!cr6.gt) goto loc_826270C0;
loc_826270A4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82621870
	ctx.lr = 0x826270B0;
	sub_82621870(ctx, base);
	// lwz r8,24448(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 24448);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x826270a4
	if (cr6.lt) goto loc_826270A4;
loc_826270C0:
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8262714c
	if (!cr6.gt) goto loc_8262714C;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r30,r10,-22132
	r30.s64 = ctx.r10.s64 + -22132;
	// addi r29,r11,23984
	r29.s64 = r11.s64 + 23984;
loc_826270DC:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826270F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8262713c
	if (cr6.eq) goto loc_8262713C;
loc_82627100:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82627118;
	sub_823DEDD8(ctx, base);
	// bl 0x826247a0
	ctx.lr = 0x8262711C;
	sub_826247A0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,484(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 484);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82627100
	if (!cr6.eq) goto loc_82627100;
loc_8262713C:
	// lwz r8,24448(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 24448);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r8
	cr6.compare<int32_t>(r28.s32, ctx.r8.s32, xer);
	// blt cr6,0x826270dc
	if (cr6.lt) goto loc_826270DC;
loc_8262714C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,24472
	r11.s64 = r11.s64 + 24472;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
	// stw r6,516(r11)
	PPC_STORE_U32(r11.u32 + 516, ctx.r6.u32);
	// stw r9,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r9.u32);
	// ble cr6,0x826271bc
	if (!cr6.gt) goto loc_826271BC;
loc_82627178:
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// beq cr6,0x826271b0
	if (cr6.eq) goto loc_826271B0;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x82627198
	if (!cr6.eq) goto loc_82627198;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,512(r11)
	PPC_STORE_U32(r11.u32 + 512, ctx.r10.u32);
loc_82627198:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 520);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,512(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// stw r10,520(r11)
	PPC_STORE_U32(r11.u32 + 520, ctx.r10.u32);
loc_826271B0:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x82627178
	if (cr6.lt) goto loc_82627178;
loc_826271BC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826271C4"))) PPC_WEAK_FUNC(sub_826271C4);
PPC_FUNC_IMPL(__imp__sub_826271C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826271C8"))) PPC_WEAK_FUNC(sub_826271C8);
PPC_FUNC_IMPL(__imp__sub_826271C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826271D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,1320(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1320);
	// lwz r30,24432(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24432);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82627208
	if (!cr6.lt) goto loc_82627208;
	// addi r29,r27,800
	r29.s64 = r27.s64 + 800;
	// subf r31,r30,r11
	r31.s64 = r11.s64 - r30.s64;
loc_826271F4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82621e28
	ctx.lr = 0x82627200;
	sub_82621E28(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x826271f4
	if (!cr0.eq) goto loc_826271F4;
loc_82627208:
	// lwz r11,796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// li r26,0
	r26.s64 = 0;
	// mr r31,r26
	r31.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82627280
	if (!cr6.gt) goto loc_82627280;
	// addi r30,r27,276
	r30.s64 = r27.s64 + 276;
loc_82627220:
	// lwz r11,516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r30.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,60(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82627254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82627270
	if (!cr6.eq) goto loc_82627270;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82621e28
	ctx.lr = 0x8262726C;
	sub_82621E28(ctx, base);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_82627270:
	// lwz r11,796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82627220
	if (cr6.lt) goto loc_82627220;
loc_82627280:
	// lwz r11,796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82627360
	if (!cr6.gt) goto loc_82627360;
	// addi r31,r27,800
	r31.s64 = r27.s64 + 800;
	// addi r30,r27,276
	r30.s64 = r27.s64 + 276;
loc_82627298:
	// lwz r11,516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r9,520(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 520);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r8,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r8.s64 = r11.s32 >> 7;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// subf r5,r6,r11
	ctx.r5.s64 = r11.s64 - ctx.r6.s64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82627308
	if (!cr6.gt) goto loc_82627308;
	// lwz r8,516(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// lwzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
loc_826272D4:
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// srawi r6,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 7;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// subf r3,r4,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r4.s64;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// beq cr6,0x826275d0
	if (cr6.eq) goto loc_826275D0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826272d4
	if (cr6.lt) goto loc_826272D4;
loc_82627308:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8262730C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82627350
	if (!cr6.eq) goto loc_82627350;
	// lwz r11,516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r30.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82627350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82627350:
	// lwz r11,796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82627298
	if (cr6.lt) goto loc_82627298;
loc_82627360:
	// lwz r11,1320(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1320);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82627570
	if (!cr6.gt) goto loc_82627570;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r27,800
	r31.s64 = r27.s64 + 800;
	// addi r30,r27,276
	r30.s64 = r27.s64 + 276;
	// addi r28,r11,24472
	r28.s64 = r11.s64 + 24472;
loc_82627380:
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r9,520(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 520);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r8,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r8.s64 = r11.s32 >> 7;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// subf r5,r6,r11
	ctx.r5.s64 = r11.s64 - ctx.r6.s64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826273f0
	if (!cr6.gt) goto loc_826273F0;
	// lwz r8,516(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
loc_826273BC:
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// srawi r6,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 7;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// subf r3,r4,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r4.s64;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// beq cr6,0x826275d8
	if (cr6.eq) goto loc_826275D8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826273bc
	if (cr6.lt) goto loc_826273BC;
loc_826273F0:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826273F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82627560
	if (!cr6.eq) goto loc_82627560;
	// lwz r11,520(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 520);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82627560
	if (cr6.eq) goto loc_82627560;
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// lwz r4,76(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82627494
	if (!cr6.eq) goto loc_82627494;
	// lwz r11,516(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 516);
	// lwz r10,520(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 520);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,516(r28)
	PPC_STORE_U32(r28.u32 + 516, r11.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// stw r10,520(r28)
	PPC_STORE_U32(r28.u32 + 520, ctx.r10.u32);
	// bne cr6,0x82627464
	if (!cr6.eq) goto loc_82627464;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r11,516(r28)
	PPC_STORE_U32(r28.u32 + 516, r11.u32);
loc_82627464:
	// lwz r10,516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwzx r7,r9,r28
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// srawi r6,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 7;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// subf r3,r4,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r4.s64;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stw r7,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r7.u32);
loc_82627494:
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,108(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x826274C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// li r4,1
	ctx.r4.s64 = 1;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// srawi r11,r3,7
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7F) != 0);
	r11.s64 = ctx.r3.s32 >> 7;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82627500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// lwz r8,520(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 520);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r8,128
	cr6.compare<int32_t>(ctx.r8.s32, 128, xer);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// srawi r3,r4,7
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 7;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// subf r9,r10,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r10.s64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x82627560
	if (cr6.eq) goto loc_82627560;
	// lwz r11,512(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 512);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r30)
	PPC_STORE_U32(r30.u32 + 512, r11.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// bne cr6,0x82627544
	if (!cr6.eq) goto loc_82627544;
	// stw r26,512(r30)
	PPC_STORE_U32(r30.u32 + 512, r26.u32);
loc_82627544:
	// lwz r11,512(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 512);
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r10.u32);
	// lwz r11,520(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 520);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,520(r30)
	PPC_STORE_U32(r30.u32 + 520, ctx.r8.u32);
loc_82627560:
	// lwz r11,1320(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1320);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82627380
	if (cr6.lt) goto loc_82627380;
loc_82627570:
	// lwz r11,796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// mr r31,r26
	r31.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826275c8
	if (!cr6.gt) goto loc_826275C8;
	// addi r30,r27,276
	r30.s64 = r27.s64 + 276;
loc_82627584:
	// lwz r11,516(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 516);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r10,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	ctx.r10.s64 = r11.s32 >> 7;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r30.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,184(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 184);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x826275B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,796(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 796);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x82627584
	if (cr6.lt) goto loc_82627584;
loc_826275C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826275D0:
	// li r11,1
	r11.s64 = 1;
	// b 0x8262730c
	goto loc_8262730C;
loc_826275D8:
	// li r11,1
	r11.s64 = 1;
	// b 0x826273f4
	goto loc_826273F4;
}

__attribute__((alias("__imp__sub_826275E0"))) PPC_WEAK_FUNC(sub_826275E0);
PPC_FUNC_IMPL(__imp__sub_826275E0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,23536
	ctx.r4.s64 = ctx.r10.s64 + 23536;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8262760C;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,196(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82627628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,52(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// stw r7,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_82627648"))) PPC_WEAK_FUNC(sub_82627648);
PPC_FUNC_IMPL(__imp__sub_82627648) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82627650;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8262772c
	if (cr6.eq) goto loc_8262772C;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r27,r1,84
	r27.s64 = ctx.r1.s64 + 84;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r6,r10
	r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262769C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x8217c570
	ctx.lr = 0x826276B0;
	sub_8217C570(ctx, base);
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,45
	ctx.r5.s64 = r11.s64 + 45;
	// addi r29,r1,92
	r29.s64 = ctx.r1.s64 + 92;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r1,88
	r27.s64 = ctx.r1.s64 + 88;
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lwzx r31,r4,r11
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826276E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x8217c570
	ctx.lr = 0x826276F4;
	sub_8217C570(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,172(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 172);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fsqrts f5,f6
	ctx.f5.f64 = double(float(sqrt(ctx.f6.f64)));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f4
	cr6.compare(ctx.f8.f64, ctx.f4.f64);
	// blt cr6,0x82627730
	if (cr6.lt) goto loc_82627730;
loc_8262772C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82627730:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82627738"))) PPC_WEAK_FUNC(sub_82627738);
PPC_FUNC_IMPL(__imp__sub_82627738) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82627740;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826355a8
	ctx.lr = 0x82627758;
	sub_826355A8(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82627a58
	if (cr6.lt) goto loc_82627A58;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r10,24448(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24448);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82627a58
	if (!cr6.lt) goto loc_82627A58;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// addi r29,r31,168
	r29.s64 = r31.s64 + 168;
	// lfs f29,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f31,-11624(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11624);
	f31.f64 = double(temp.f32);
	// lfs f0,31924(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31924);
	f0.f64 = double(temp.f32);
	// lfs f13,1392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1392);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,168(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// bl 0x8217d5e8
	ctx.lr = 0x826277B0;
	sub_8217D5E8(ctx, base);
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,208(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826277C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8217ce80
	ctx.lr = 0x826277D0;
	sub_8217CE80(ctx, base);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r5,-31280
	ctx.r4.s64 = ctx.r5.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x826277E0;
	sub_8217C088(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f30,-1332(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1332);
	f30.f64 = double(temp.f32);
	// bl 0x82178848
	ctx.lr = 0x826277EC;
	sub_82178848(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82627800
	if (cr6.eq) goto loc_82627800;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f30,-1336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1336);
	f30.f64 = double(temp.f32);
loc_82627800:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f4,11536(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11536);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x82627820;
	sub_8217D460(ctx, base);
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r31,128
	ctx.r4.s64 = r31.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8217c570
	ctx.lr = 0x82627834;
	sub_8217C570(ctx, base);
	// bl 0x821771e8
	ctx.lr = 0x82627838;
	sub_821771E8(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,5636(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 5636);
	f0.f64 = double(temp.f32);
	// fdivs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82177198
	ctx.lr = 0x82627868;
	sub_82177198(ctx, base);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// lfs f0,5640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 5640);
	f0.f64 = double(temp.f32);
	// fdivs f3,f0,f4
	ctx.f3.f64 = double(float(f0.f64 / ctx.f4.f64));
	// fmuls f2,f3,f7
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f7.f64));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82621a10
	ctx.lr = 0x8262789C;
	sub_82621A10(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x826278A0;
	sub_825EF9F0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826278B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r10,7760
	ctx.r4.s64 = ctx.r10.s64 + 7760;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82722718
	ctx.lr = 0x826278C8;
	sub_82722718(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,7756
	ctx.r4.s64 = ctx.r9.s64 + 7756;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// bl 0x82722718
	ctx.lr = 0x826278DC;
	sub_82722718(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r8,2612
	ctx.r4.s64 = ctx.r8.s64 + 2612;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722718
	ctx.lr = 0x826278F0;
	sub_82722718(ctx, base);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,144(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 144);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r5,33
	cr6.compare<uint32_t>(ctx.r5.u32, 33, xer);
	// bne cr6,0x82627910
	if (!cr6.eq) goto loc_82627910;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82627910:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r4,r10,-13276
	ctx.r4.s64 = ctx.r10.s64 + -13276;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x82627924;
	sub_827227B8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f13,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-18576
	ctx.r4.s64 = ctx.r8.s64 + -18576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,-29920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29920);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82722718
	ctx.lr = 0x8262794C;
	sub_82722718(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82627960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r29,r11,-19636
	r29.s64 = r11.s64 + -19636;
	// lfs f31,31016(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31016);
	f31.f64 = double(temp.f32);
	// bne cr6,0x826279d0
	if (!cr6.eq) goto loc_826279D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,152(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826279d0
	if (!cr6.gt) goto loc_826279D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f13,152(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82627a34
	if (cr6.gt) goto loc_82627A34;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,24472
	ctx.r3.s64 = ctx.r10.s64 + 24472;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82621fa0
	ctx.lr = 0x826279C4;
	sub_82621FA0(ctx, base);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r9,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r9.u32);
	// b 0x82627a34
	goto loc_82627A34;
loc_826279D0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826279E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82627a34
	if (cr6.eq) goto loc_82627A34;
	// lfs f0,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x82627a34
	if (!cr6.lt) goto loc_82627A34;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x82627a18
	if (!cr6.gt) goto loc_82627A18;
	// stfs f29,152(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
loc_82627A18:
	// lfs f0,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	f0.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722718
	ctx.lr = 0x82627A34;
	sub_82722718(ctx, base);
loc_82627A34:
	// lfs f0,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	f0.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722718
	ctx.lr = 0x82627A50;
	sub_82722718(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8217cb48
	ctx.lr = 0x82627A58;
	sub_8217CB48(ctx, base);
loc_82627A58:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82627A6C"))) PPC_WEAK_FUNC(sub_82627A6C);
PPC_FUNC_IMPL(__imp__sub_82627A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627A70"))) PPC_WEAK_FUNC(sub_82627A70);
PPC_FUNC_IMPL(__imp__sub_82627A70) {
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
	ctx.lr = 0x82627A78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82627aa0
	if (!cr6.eq) goto loc_82627AA0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82627AA0;
	sub_82608A98(ctx, base);
loc_82627AA0:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82627ad0
	if (!cr6.eq) goto loc_82627AD0;
	// bl 0x821c9438
	ctx.lr = 0x82627AC4;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821bed68
	ctx.lr = 0x82627AD0;
	sub_821BED68(ctx, base);
loc_82627AD0:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x82627AD8;
	sub_821C9550(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r30,r9
	r29.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x82627B04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82627b28
	if (cr6.eq) goto loc_82627B28;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x82627b2c
	goto loc_82627B2C;
loc_82627B28:
	// li r11,0
	r11.s64 = 0;
loc_82627B2C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r11,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82627B44"))) PPC_WEAK_FUNC(sub_82627B44);
PPC_FUNC_IMPL(__imp__sub_82627B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627B48"))) PPC_WEAK_FUNC(sub_82627B48);
PPC_FUNC_IMPL(__imp__sub_82627B48) {
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
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82627B78;
	sub_821D2028(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,6548
	ctx.r8.s64 = ctx.r9.s64 + 6548;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x826375a0
	ctx.lr = 0x82627B8C;
	sub_826375A0(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82627ba4
	if (cr6.eq) goto loc_82627BA4;
	// bl 0x82130588
	ctx.lr = 0x82627BA0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82627BA4:
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

__attribute__((alias("__imp__sub_82627BBC"))) PPC_WEAK_FUNC(sub_82627BBC);
PPC_FUNC_IMPL(__imp__sub_82627BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627BC0"))) PPC_WEAK_FUNC(sub_82627BC0);
PPC_FUNC_IMPL(__imp__sub_82627BC0) {
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
	ctx.lr = 0x82627BC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// addi r3,r30,148
	ctx.r3.s64 = r30.s64 + 148;
	// stw r10,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2028
	ctx.lr = 0x82627BEC;
	sub_821D2028(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r8,r9,6548
	ctx.r8.s64 = ctx.r9.s64 + 6548;
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// bl 0x826375a0
	ctx.lr = 0x82627C00;
	sub_826375A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x82627C08;
	sub_826375A0(ctx, base);
	// clrlwi r7,r29,31
	ctx.r7.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82627c20
	if (cr6.eq) goto loc_82627C20;
	// bl 0x82130588
	ctx.lr = 0x82627C1C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82627C20:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82627C28"))) PPC_WEAK_FUNC(sub_82627C28);
PPC_FUNC_IMPL(__imp__sub_82627C28) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82627C30;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d8
	ctx.lr = 0x82627C38;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lwz r11,24996(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// addic. r11,r11,12
	xer.ca = r11.u32 > 4294967283;
	r11.s64 = r11.s64 + 12;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82627e30
	if (cr0.eq) goto loc_82627E30;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f30.f64 = double(temp.f32);
	// bl 0x82237920
	ctx.lr = 0x82627C84;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82627e30
	if (cr6.eq) goto loc_82627E30;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f29.f64 = double(temp.f32);
	// lfs f28,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f28.f64 = double(temp.f32);
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82627CA8:
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 - f0.f64));
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f29,f12
	ctx.f11.f64 = double(float(f29.f64 - ctx.f12.f64));
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lbz r9,9(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 9);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f0,f9
	f0.f64 = double(float(sqrt(ctx.f9.f64)));
	// beq cr6,0x82627d14
	if (cr6.eq) goto loc_82627D14;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82627d14
	if (!cr6.eq) goto loc_82627D14;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// blt cr6,0x82627d0c
	if (cr6.lt) goto loc_82627D0C;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// bge cr6,0x82627d14
	if (!cr6.lt) goto loc_82627D14;
loc_82627D0C:
	// fmr f30,f0
	ctx.fpscr.disableFlushMode();
	f30.f64 = f0.f64;
	// mr r27,r29
	r27.u64 = r29.u64;
loc_82627D14:
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82627ca8
	if (!cr6.eq) goto loc_82627CA8;
	// lhz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82627D2C:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82627d54
	if (!cr6.lt) goto loc_82627D54;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
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
	// beq cr6,0x82627d2c
	if (cr6.eq) goto loc_82627D2C;
	// b 0x82627ca8
	goto loc_82627CA8;
loc_82627D54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82627ca8
	if (!cr6.eq) goto loc_82627CA8;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82627e30
	if (cr6.eq) goto loc_82627E30;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627D7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bge cr6,0x82627e30
	if (!cr6.lt) goto loc_82627E30;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82627e30
	if (!cr6.gt) goto loc_82627E30;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82627e04
	if (!cr6.eq) goto loc_82627E04;
	// lwz r11,80(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 80);
	// addi r3,r26,80
	ctx.r3.s64 = r26.s64 + 80;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r27,r3
	cr6.compare<uint32_t>(r27.u32, ctx.r3.u32, xer);
	// bne cr6,0x82627e04
	if (!cr6.eq) goto loc_82627E04;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,604(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 604);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82627df0
	if (cr6.eq) goto loc_82627DF0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,564(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 564);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82627DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r27,r3
	cr6.compare<uint32_t>(r27.u32, ctx.r3.u32, xer);
	// bne cr6,0x82627e04
	if (!cr6.eq) goto loc_82627E04;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
loc_82627DF0:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8261fef8
	ctx.lr = 0x82627DF8;
	sub_8261FEF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82627e30
	if (cr6.eq) goto loc_82627E30;
loc_82627E04:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x82627E2C;
	// b 0x823d923c
	return;
loc_82627E30:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x82627E40;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82627E44"))) PPC_WEAK_FUNC(sub_82627E44);
PPC_FUNC_IMPL(__imp__sub_82627E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627E48"))) PPC_WEAK_FUNC(sub_82627E48);
PPC_FUNC_IMPL(__imp__sub_82627E48) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,24996(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// addic. r11,r11,12
	xer.ca = r11.u32 > 4294967283;
	r11.s64 = r11.s64 + 12;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82627ef0
	if (cr0.eq) goto loc_82627EF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x82627E84;
	sub_82237920(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82627ef0
	if (cr6.eq) goto loc_82627EF0;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82627E98:
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82627f08
	if (cr6.eq) goto loc_82627F08;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82627e98
	if (!cr6.eq) goto loc_82627E98;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
loc_82627EC0:
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82627ee8
	if (!cr6.lt) goto loc_82627EE8;
	// lwz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82627ec0
	if (cr6.eq) goto loc_82627EC0;
	// b 0x82627e98
	goto loc_82627E98;
loc_82627EE8:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82627e98
	if (!cr6.eq) goto loc_82627E98;
loc_82627EF0:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_82627F08:
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// beq cr6,0x82627f2c
	if (cr6.eq) goto loc_82627F2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r31,128
	ctx.r4.s64 = r31.s64 + 128;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82627F2C:
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

__attribute__((alias("__imp__sub_82627F44"))) PPC_WEAK_FUNC(sub_82627F44);
PPC_FUNC_IMPL(__imp__sub_82627F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627F48"))) PPC_WEAK_FUNC(sub_82627F48);
PPC_FUNC_IMPL(__imp__sub_82627F48) {
	PPC_FUNC_PROLOGUE();
	// b 0x82627e48
	sub_82627E48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82627F4C"))) PPC_WEAK_FUNC(sub_82627F4C);
PPC_FUNC_IMPL(__imp__sub_82627F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82627F50"))) PPC_WEAK_FUNC(sub_82627F50);
PPC_FUNC_IMPL(__imp__sub_82627F50) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82627F58;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627F7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82628064
	if (cr6.eq) goto loc_82628064;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82627F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82628064
	if (cr6.eq) goto loc_82628064;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268d280
	ctx.lr = 0x82627FB8;
	sub_8268D280(ctx, base);
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82628064
	if (!cr6.eq) goto loc_82628064;
	// lwz r11,1512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x8262805c
	if (!cr6.eq) goto loc_8262805C;
	// lbz r11,629(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262805c
	if (cr6.eq) goto loc_8262805C;
	// lwz r11,600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262805c
	if (cr6.eq) goto loc_8262805C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262805c
	if (!cr6.eq) goto loc_8262805C;
	// lwz r3,600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x8262803C;
	sub_826208D0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625f50
	ctx.lr = 0x8262805C;
	sub_82625F50(ctx, base);
loc_8262805C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623ee8
	ctx.lr = 0x82628064;
	sub_82623EE8(ctx, base);
loc_82628064:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82628070"))) PPC_WEAK_FUNC(sub_82628070);
PPC_FUNC_IMPL(__imp__sub_82628070) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r11,24996(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// addic. r11,r11,12
	xer.ca = r11.u32 > 4294967283;
	r11.s64 = r11.s64 + 12;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82628110
	if (cr0.eq) goto loc_82628110;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x826280A4;
	sub_82237920(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82628110
	if (cr6.eq) goto loc_82628110;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826280B8:
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82628124
	if (cr6.eq) goto loc_82628124;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826280b8
	if (!cr6.eq) goto loc_826280B8;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
loc_826280E0:
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82628108
	if (!cr6.lt) goto loc_82628108;
	// lwz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r8
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826280e0
	if (cr6.eq) goto loc_826280E0;
	// b 0x826280b8
	goto loc_826280B8;
loc_82628108:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826280b8
	if (!cr6.eq) goto loc_826280B8;
loc_82628110:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82628124:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,23896
	ctx.r6.s64 = r11.s64 + 23896;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82628140;
	sub_823DEDD8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82628150"))) PPC_WEAK_FUNC(sub_82628150);
PPC_FUNC_IMPL(__imp__sub_82628150) {
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
	// bl 0x82628070
	ctx.lr = 0x82628160;
	sub_82628070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826281d0
	if (cr6.eq) goto loc_826281D0;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826281bc
	if (cr6.eq) goto loc_826281BC;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826281a4
	if (cr6.eq) goto loc_826281A4;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826281A4:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826281BC:
	// bl 0x822a8108
	ctx.lr = 0x826281C0;
	sub_822A8108(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826281D0:
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

__attribute__((alias("__imp__sub_826281E4"))) PPC_WEAK_FUNC(sub_826281E4);
PPC_FUNC_IMPL(__imp__sub_826281E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826281E8"))) PPC_WEAK_FUNC(sub_826281E8);
PPC_FUNC_IMPL(__imp__sub_826281E8) {
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
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfa8
	ctx.lr = 0x82628204;
	sub_8262BFA8(ctx, base);
	// lwz r3,588(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// li r11,0
	r11.s64 = 0;
	// stb r11,630(r31)
	PPC_STORE_U8(r31.u32 + 630, r11.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82628244
	if (cr6.eq) goto loc_82628244;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,448
	ctx.r4.s64 = r31.s64 + 448;
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82628244
	if (cr6.eq) goto loc_82628244;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfc0
	ctx.lr = 0x82628244;
	sub_8262BFC0(ctx, base);
loc_82628244:
	// lbz r11,1424(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82628258
	if (cr6.eq) goto loc_82628258;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82626300
	ctx.lr = 0x82628258;
	sub_82626300(ctx, base);
loc_82628258:
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

__attribute__((alias("__imp__sub_8262826C"))) PPC_WEAK_FUNC(sub_8262826C);
PPC_FUNC_IMPL(__imp__sub_8262826C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82628270"))) PPC_WEAK_FUNC(sub_82628270);
PPC_FUNC_IMPL(__imp__sub_82628270) {
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
	// lis r11,-32158
	r11.s64 = -2107506688;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r11,23160
	ctx.r4.s64 = r11.s64 + 23160;
	// addi r3,r10,-18500
	ctx.r3.s64 = ctx.r10.s64 + -18500;
	// bl 0x82554798
	ctx.lr = 0x82628290;
	sub_82554798(ctx, base);
	// lis r9,-32158
	ctx.r9.s64 = -2107506688;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r4,r9,23216
	ctx.r4.s64 = ctx.r9.s64 + 23216;
	// addi r3,r8,-18528
	ctx.r3.s64 = ctx.r8.s64 + -18528;
	// bl 0x82554798
	ctx.lr = 0x826282A4;
	sub_82554798(ctx, base);
	// lis r7,-32158
	ctx.r7.s64 = -2107506688;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r4,r7,12912
	ctx.r4.s64 = ctx.r7.s64 + 12912;
	// addi r3,r6,-18564
	ctx.r3.s64 = ctx.r6.s64 + -18564;
	// bl 0x82554798
	ctx.lr = 0x826282B8;
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

__attribute__((alias("__imp__sub_826282C8"))) PPC_WEAK_FUNC(sub_826282C8);
PPC_FUNC_IMPL(__imp__sub_826282C8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	// bl 0x823d91e4
	ctx.lr = 0x826282D0;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x826282D8;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826282F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 552);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262830C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82628150
	ctx.lr = 0x82628310;
	sub_82628150(ctx, base);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r23,16
	r23.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r24,32
	r24.s64 = 32;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r25,48
	r25.s64 = 48;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r3,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,0
	r26.s64 = 0;
	// lvx128 v61,r3,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v60,r3,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r26,1530(r31)
	PPC_STORE_U8(r31.u32 + 1530, r26.u8);
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r26,1528(r31)
	PPC_STORE_U8(r31.u32 + 1528, r26.u8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r3,r9,-18472
	ctx.r3.s64 = ctx.r9.s64 + -18472;
	// addi r30,r11,-19728
	r30.s64 = r11.s64 + -19728;
	// addi r28,r10,-22108
	r28.s64 = ctx.r10.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x82628374;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82628388;
	sub_823DEDD8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r3,1512(r31)
	PPC_STORE_U32(r31.u32 + 1512, ctx.r3.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stb r26,1528(r31)
	PPC_STORE_U8(r31.u32 + 1528, r26.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r10,-10028(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r4,r11,4272
	ctx.r4.s64 = r11.s64 + 4272;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x826283B8;
	sub_822249B8(ctx, base);
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826283f4
	if (cr6.eq) goto loc_826283F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826283D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826283f4
	if (cr6.eq) goto loc_826283F4;
	// lwz r3,1544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826283F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826283F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f890
	ctx.lr = 0x826283FC;
	sub_8261F890(ctx, base);
	// lis r11,5
	r11.s64 = 327680;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r11,5168
	ctx.r9.u64 = r11.u64 | 5168;
	// stb r10,716(r31)
	PPC_STORE_U8(r31.u32 + 716, ctx.r10.u8);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfsx f1,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,1524(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1524, temp.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,804(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 804);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82628430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// addi r4,r31,712
	ctx.r4.s64 = r31.s64 + 712;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,800(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 800);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82628448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,812(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 812);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82628464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r5,580(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 580);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82628484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,628(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 628);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82628498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r8,576(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 576);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826284B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lbz r5,378(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 378);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f29,-21460(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21460);
	f29.f64 = double(temp.f32);
	// lfs f28,-18668(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -18668);
	f28.f64 = double(temp.f32);
	// beq cr6,0x8262859c
	if (cr6.eq) goto loc_8262859C;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// li r4,9
	ctx.r4.s64 = 9;
	// ori r27,r10,4672
	r27.u64 = ctx.r10.u64 | 4672;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r27
	ctx.r3.u64 = ctx.r9.u64 + r27.u64;
	// bl 0x8221a2a8
	ctx.lr = 0x826284F0;
	sub_8221A2A8(ctx, base);
	// li r8,352
	ctx.r8.s64 = 352;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f0,1128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	f0.f64 = double(temp.f32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r6,-2092
	ctx.r4.s64 = ctx.r6.s64 + -2092;
	// lvx128 v59,r31,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82628520;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82628534;
	sub_823DEDD8(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f13,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82628598;
	sub_82202EC0(ctx, base);
	// b 0x82628644
	goto loc_82628644;
loc_8262859C:
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82218cb8
	ctx.lr = 0x826285A4;
	sub_82218CB8(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r27,r10,4672
	r27.u64 = ctx.r10.u64 | 4672;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r27
	ctx.r3.u64 = ctx.r9.u64 + r27.u64;
	// bl 0x82219288
	ctx.lr = 0x826285BC;
	sub_82219288(ctx, base);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lfs f13,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// fsubs f12,f28,f13
	ctx.f12.f64 = double(float(f28.f64 - ctx.f13.f64));
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r3,r23
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-18920(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18920);
	f0.f64 = double(temp.f32);
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// lvx128 v54,r3,r24
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r3,r25
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// stvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,244(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// bge cr6,0x82628860
	if (!cr6.lt) goto loc_82628860;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_82628614:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// fabs f0,f13
	f0.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_82628620:
	// lfs f13,248(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r31,1056
	ctx.r4.s64 = r31.s64 + 1056;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x822192f8
	ctx.lr = 0x82628640;
	sub_822192F8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82628644:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r25,r31,1056
	r25.s64 = r31.s64 + 1056;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r7,632(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 632);
	// addis r4,r8,5
	ctx.r4.s64 = ctx.r8.s64 + 327680;
	// addi r4,r4,5088
	ctx.r4.s64 = ctx.r4.s64 + 5088;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82628684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,636(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 636);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262869C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// ori r28,r4,5152
	r28.u64 = ctx.r4.u64 | 5152;
	// ori r10,r3,5184
	ctx.r10.u64 = ctx.r3.u64 | 5184;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v52,r9,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r9,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r4,r7,r28
	ctx.r4.u64 = ctx.r7.u64 + r28.u64;
	// lwz r6,736(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 736);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826286DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,744(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 744);
	// add r4,r4,r28
	ctx.r4.u64 = ctx.r4.u64 + r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826286FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r27
	ctx.r3.u64 = ctx.r10.u64 + r27.u64;
	// bl 0x8221bb90
	ctx.lr = 0x8262870C;
	sub_8221BB90(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,648(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82628724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f28,84(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-10220(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f30,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f30.f64 = double(temp.f32);
	// bl 0x82623350
	ctx.lr = 0x82628758;
	sub_82623350(ctx, base);
	// lfs f12,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f29
	ctx.f10.f64 = double(float(ctx.f12.f64 - f29.f64));
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,636(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 636);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,580(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 580);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826287A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,628(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 628);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826287B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1508(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,592(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 592);
	// lwz r28,0(r5)
	r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826287D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,1508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r9,576(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 576);
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826287EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,548(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 548);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82628804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,592(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 592);
	// lwz r30,104(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262881C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8262882C;
	sub_8262BAB0(ctx, base);
	// stb r26,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r26.u8);
	// stb r26,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r26.u8);
	// lwz r4,1508(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82628844;
	sub_82220980(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f970
	ctx.lr = 0x82628850;
	sub_8261F970(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x8262885C;
	// b 0x823d9234
	return;
loc_82628860:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82628614
	if (!cr6.gt) goto loc_82628614;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// b 0x82628620
	goto loc_82628620;
}

__attribute__((alias("__imp__sub_82628874"))) PPC_WEAK_FUNC(sub_82628874);
PPC_FUNC_IMPL(__imp__sub_82628874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82628878"))) PPC_WEAK_FUNC(sub_82628878);
PPC_FUNC_IMPL(__imp__sub_82628878) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82628880;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d4
	ctx.lr = 0x82628888;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// lwz r11,24996(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// addic. r11,r11,12
	xer.ca = r11.u32 > 4294967283;
	r11.s64 = r11.s64 + 12;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826289e4
	if (cr0.eq) goto loc_826289E4;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f27,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f27.f64 = double(temp.f32);
	// fmr f30,f27
	f30.f64 = f27.f64;
	// bl 0x82237920
	ctx.lr = 0x826288CC;
	sub_82237920(ctx, base);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826289e4
	if (cr6.eq) goto loc_826289E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r25,448
	r25.s64 = 448;
	// lfs f28,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
loc_826288F4:
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262899c
	if (!cr6.eq) goto loc_8262899C;
	// lbz r11,9(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262899c
	if (cr6.eq) goto loc_8262899C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r27,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f31,f10
	f31.f64 = double(float(sqrt(ctx.f10.f64)));
	// bl 0x82620ae8
	ctx.lr = 0x82628970;
	sub_82620AE8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8262899c
	if (cr6.eq) goto loc_8262899C;
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// ble cr6,0x8262898c
	if (!cr6.gt) goto loc_8262898C;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x82628994
	if (cr6.lt) goto loc_82628994;
loc_8262898C:
	// fcmpu cr6,f30,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f27.f64);
	// bne cr6,0x8262899c
	if (!cr6.eq) goto loc_8262899C;
loc_82628994:
	// mr r24,r30
	r24.u64 = r30.u64;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_8262899C:
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826288f4
	if (!cr6.eq) goto loc_826288F4;
	// lhz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_826289B4:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826289dc
	if (!cr6.lt) goto loc_826289DC;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r29,r11,r8
	r29.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826289b4
	if (cr6.eq) goto loc_826289B4;
	// b 0x826288f4
	goto loc_826288F4;
loc_826289DC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826288f4
	if (!cr6.eq) goto loc_826288F4;
loc_826289E4:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba20
	ctx.lr = 0x826289F4;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826289F8"))) PPC_WEAK_FUNC(sub_826289F8);
PPC_FUNC_IMPL(__imp__sub_826289F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82628a74
	if (!cr6.eq) goto loc_82628A74;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,264
	ctx.r10.s64 = ctx.r3.s64 + 264;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x82628A30;
	sub_82237920(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82237920
	ctx.lr = 0x82628A38;
	sub_82237920(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82628a74
	if (cr6.eq) goto loc_82628A74;
loc_82628A44:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,216(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 216);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x82628A68;
	sub_82186D30(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82628a44
	if (!cr6.eq) goto loc_82628A44;
loc_82628A74:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_82628A88"))) PPC_WEAK_FUNC(sub_82628A88);
PPC_FUNC_IMPL(__imp__sub_82628A88) {
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
	ctx.lr = 0x82628A90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x82246108
	ctx.lr = 0x82628AA0;
	sub_82246108(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r28,r31,264
	r28.s64 = r31.s64 + 264;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82628ABC;
	sub_82237920(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82237920
	ctx.lr = 0x82628AC4;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82628b48
	if (cr6.eq) goto loc_82628B48;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82628AD8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82628b48
	if (cr6.eq) goto loc_82628B48;
loc_82628AE0:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82628b00
	if (cr6.eq) goto loc_82628B00;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628B00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82628B00:
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82628ae0
	if (!cr6.eq) goto loc_82628AE0;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82628B18:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82628b40
	if (!cr6.lt) goto loc_82628B40;
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
	// beq cr6,0x82628b18
	if (cr6.eq) goto loc_82628B18;
	// b 0x82628ad8
	goto loc_82628AD8;
loc_82628B40:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82628ae0
	if (!cr6.eq) goto loc_82628AE0;
loc_82628B48:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82608de8
	ctx.lr = 0x82628B50;
	sub_82608DE8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82628B58"))) PPC_WEAK_FUNC(sub_82628B58);
PPC_FUNC_IMPL(__imp__sub_82628B58) {
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
	// bl 0x82637538
	ctx.lr = 0x82628B70;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-18452
	ctx.r9.s64 = r11.s64 + -18452;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r11.u16);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r11,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r11.u16);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stfs f0,168(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
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

__attribute__((alias("__imp__sub_82628BD0"))) PPC_WEAK_FUNC(sub_82628BD0);
PPC_FUNC_IMPL(__imp__sub_82628BD0) {
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
	// addi r10,r11,-18452
	ctx.r10.s64 = r11.s64 + -18452;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,74(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 74);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82628c0c
	if (cr6.eq) goto loc_82628C0C;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82628C0C;
	sub_82130588(ctx, base);
loc_82628C0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x82628C14;
	sub_826375A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82628c2c
	if (cr6.eq) goto loc_82628C2C;
	// bl 0x82130588
	ctx.lr = 0x82628C28;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82628C2C:
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

__attribute__((alias("__imp__sub_82628C44"))) PPC_WEAK_FUNC(sub_82628C44);
PPC_FUNC_IMPL(__imp__sub_82628C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82628C48"))) PPC_WEAK_FUNC(sub_82628C48);
PPC_FUNC_IMPL(__imp__sub_82628C48) {
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
	ctx.lr = 0x82628C50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// sth r9,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r9.u16);
	// li r26,0
	r26.s64 = 0;
	// lhz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82628d28
	if (cr6.eq) goto loc_82628D28;
	// li r28,0
	r28.s64 = 0;
loc_82628C84:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r28,r11
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// bl 0x8224d270
	ctx.lr = 0x82628C98;
	sub_8224D270(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82628d0c
	if (!cr6.gt) goto loc_82628D0C;
loc_82628CA8:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r28,r11
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// bl 0x8224d6f8
	ctx.lr = 0x82628CB8;
	sub_8224D6F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82621d50
	ctx.lr = 0x82628CC8;
	sub_82621D50(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82628d00
	if (cr6.eq) goto loc_82628D00;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82628d00
	if (!cr6.eq) goto loc_82628D00;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82627648
	ctx.lr = 0x82628CE4;
	sub_82627648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82628d00
	if (!cr6.eq) goto loc_82628D00;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8262e420
	ctx.lr = 0x82628CFC;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
loc_82628D00:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82628ca8
	if (cr6.lt) goto loc_82628CA8;
loc_82628D0C:
	// lhz r11,72(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82628c84
	if (cr6.lt) goto loc_82628C84;
	// lhz r11,86(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82628D28:
	// lhz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82628d88
	if (cr6.eq) goto loc_82628D88;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r6,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r6.s64;
	// lwz r31,0(r5)
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// beq cr6,0x82628d7c
	if (cr6.eq) goto loc_82628D7C;
	// bl 0x82130588
	ctx.lr = 0x82628D7C;
	sub_82130588(ctx, base);
loc_82628D7C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82628D88:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82628d98
	if (cr6.eq) goto loc_82628D98;
	// bl 0x82130588
	ctx.lr = 0x82628D98;
	sub_82130588(ctx, base);
loc_82628D98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82628DA4"))) PPC_WEAK_FUNC(sub_82628DA4);
PPC_FUNC_IMPL(__imp__sub_82628DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82628DA8"))) PPC_WEAK_FUNC(sub_82628DA8);
PPC_FUNC_IMPL(__imp__sub_82628DA8) {
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
	// bl 0x823d91dc
	ctx.lr = 0x82628DB0;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628DDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r22,16
	r22.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r23,32
	r23.s64 = 32;
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// li r24,48
	r24.s64 = 48;
	// lvx128 v62,r3,r22
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r31,48
	r27.s64 = r31.s64 + 48;
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lvx128 v61,r3,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,712(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 712);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + 0, temp.u32);
	// lfs f0,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,3020(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3020);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82628e58
	if (!cr6.gt) goto loc_82628E58;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,-7908(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7908);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,32312(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32312);
	f0.f64 = double(temp.f32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lfs f12,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,0(r25)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// b 0x82628e64
	goto loc_82628E64;
loc_82628E58:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
loc_82628E64:
	// bl 0x82628070
	ctx.lr = 0x82628E68;
	sub_82628070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82628e84
	if (cr6.eq) goto loc_82628E84;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r30,736
	ctx.r4.s64 = r30.s64 + 736;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628E84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82628E84:
	// lbz r11,1120(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82628eb4
	if (!cr6.eq) goto loc_82628EB4;
	// addi r11,r30,992
	r11.s64 = r30.s64 + 992;
	// lvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82628EB4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,1396(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1396);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82628ee0
	if (!cr6.gt) goto loc_82628EE0;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_82628EE0:
	// bl 0x827229f0
	ctx.lr = 0x82628EE4;
	sub_827229F0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82628EFC;
	sub_82641CC8(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82628f34
	if (cr6.eq) goto loc_82628F34;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82628F14;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82628f38
	if (!cr6.eq) goto loc_82628F38;
loc_82628F34:
	// mr r28,r27
	r28.u64 = r27.u64;
loc_82628F38:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,492(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 492);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628F4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826290b0
	if (cr6.eq) goto loc_826290B0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628F68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82628ff8
	if (cr6.eq) goto loc_82628FF8;
	// lwz r11,24436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24436);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82628ff8
	if (!cr6.eq) goto loc_82628FF8;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82628ff8
	if (!cr6.eq) goto loc_82628FF8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82628F9C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5680
	ctx.lr = 0x82628FA0;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82628ff8
	if (cr6.eq) goto loc_82628FF8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82628FC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,608(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 608);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82628FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f0,-332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -332);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82628ff8
	if (!cr6.lt) goto loc_82628FF8;
	// li r11,1
	r11.s64 = 1;
	// stb r27,1168(r30)
	PPC_STORE_U8(r30.u32 + 1168, r27.u8);
	// stw r11,24436(r31)
	PPC_STORE_U32(r31.u32 + 24436, r11.u32);
loc_82628FF8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262900C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826290b0
	if (cr6.eq) goto loc_826290B0;
	// lwz r11,24436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24436);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826290b0
	if (!cr6.eq) goto loc_826290B0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,608(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 608);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82629050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,-13148(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826290b0
	if (!cr6.lt) goto loc_826290B0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-12068
	ctx.r3.s64 = r11.s64 + -12068;
	// bl 0x821fa230
	ctx.lr = 0x82629070;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82629080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826290b0
	if (cr6.eq) goto loc_826290B0;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,24436(r31)
	PPC_STORE_U32(r31.u32 + 24436, r11.u32);
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
	ctx.lr = 0x826290AC;
	sub_82207EF0(ctx, base);
	// stb r27,1168(r30)
	PPC_STORE_U8(r30.u32 + 1168, r27.u8);
loc_826290B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_826290C0"))) PPC_WEAK_FUNC(sub_826290C0);
PPC_FUNC_IMPL(__imp__sub_826290C0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x826290C8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
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
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82629280
	if (cr6.eq) goto loc_82629280;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82629280
	if (cr6.eq) goto loc_82629280;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,376(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 376);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82629190
	if (!cr6.eq) goto loc_82629190;
	// bl 0x82387a18
	ctx.lr = 0x82629134;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82629148
	if (cr6.eq) goto loc_82629148;
	// stw r31,612(r30)
	PPC_STORE_U32(r30.u32 + 612, r31.u32);
	// b 0x82629180
	goto loc_82629180;
loc_82629148:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262915C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,608(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 608);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,144(r11)
	PPC_STORE_U32(r11.u32 + 144, ctx.r3.u32);
	// beq cr6,0x82629180
	if (cr6.eq) goto loc_82629180;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r11,128
	ctx.r4.s64 = r11.s64 + 128;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82629180;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82629180:
	// stw r31,600(r30)
	PPC_STORE_U32(r30.u32 + 600, r31.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8261f970
	ctx.lr = 0x82629190;
	sub_8261F970(ctx, base);
loc_82629190:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826291A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r3,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826263c0
	ctx.lr = 0x826291F4;
	sub_826263C0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82629208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82629280
	if (cr6.eq) goto loc_82629280;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826208d0
	ctx.lr = 0x82629220;
	sub_826208D0(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262926c
	if (cr6.eq) goto loc_8262926C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262926c
	if (!cr6.eq) goto loc_8262926C;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82625f50
	ctx.lr = 0x8262926C;
	sub_82625F50(ctx, base);
loc_8262926C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,1552(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 1552);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b800
	ctx.lr = 0x82629280;
	sub_8268B800(ctx, base);
loc_82629280:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82629288"))) PPC_WEAK_FUNC(sub_82629288);
PPC_FUNC_IMPL(__imp__sub_82629288) {
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
	// bl 0x82387a18
	ctx.lr = 0x826292A8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82629350
	if (cr6.eq) goto loc_82629350;
	// bl 0x82623a70
	ctx.lr = 0x826292C0;
	sub_82623A70(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826293b4
	if (cr6.eq) goto loc_826293B4;
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-48
	ctx.r3.s64 = r11.s64 + -48;
	// bne cr6,0x826292e0
	if (!cr6.eq) goto loc_826292E0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_826292E0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826292F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfc0
	ctx.lr = 0x826292FC;
	sub_8262BFC0(ctx, base);
	// lwz r4,612(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// lwz r3,588(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r4,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r4.u32);
	// beq cr6,0x8262932c
	if (cr6.eq) goto loc_8262932C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826293b8
	goto loc_826293B8;
loc_8262932C:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826290c0
	ctx.lr = 0x82629348;
	sub_826290C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826293b8
	goto loc_826293B8;
loc_82629350:
	// bl 0x82628878
	ctx.lr = 0x82629354;
	sub_82628878(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826293b4
	if (cr6.eq) goto loc_826293B4;
	// lwz r11,608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// addi r4,r11,128
	ctx.r4.s64 = r11.s64 + 128;
	// stw r30,144(r11)
	PPC_STORE_U32(r11.u32 + 144, r30.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262937C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfc0
	ctx.lr = 0x82629384;
	sub_8262BFC0(ctx, base);
	// lwz r4,608(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// lwz r3,588(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r4,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r4.u32);
	// beq cr6,0x8262932c
	if (cr6.eq) goto loc_8262932C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826293AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826293b8
	goto loc_826293B8;
loc_826293B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826293B8:
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

__attribute__((alias("__imp__sub_826293D0"))) PPC_WEAK_FUNC(sub_826293D0);
PPC_FUNC_IMPL(__imp__sub_826293D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r2{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// bl 0x823d91f4
	ctx.lr = 0x826293D8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x82635be0
	ctx.lr = 0x826293F0;
	sub_82635BE0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,72
	cr6.compare<uint32_t>(r11.u32, 72, xer);
	// bgt cr6,0x826298fc
	if (cr6.gt) goto loc_826298FC;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,-27584
	r12.s64 = r12.s64 + -27584;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826297D8;
	case 1:
		goto loc_82629840;
	case 2:
		goto loc_82629708;
	case 3:
		goto loc_82629770;
	case 4:
		goto loc_826298FC;
	case 5:
		goto loc_826298FC;
	case 6:
		goto loc_826298FC;
	case 7:
		goto loc_826298FC;
	case 8:
		goto loc_826298FC;
	case 9:
		goto loc_826298FC;
	case 10:
		goto loc_826298FC;
	case 11:
		goto loc_826298FC;
	case 12:
		goto loc_82629670;
	case 13:
		goto loc_8262964C;
	case 14:
		goto loc_826298FC;
	case 15:
		goto loc_826298FC;
	case 16:
		goto loc_826298FC;
	case 17:
		goto loc_826298FC;
	case 18:
		goto loc_826298FC;
	case 19:
		goto loc_826298FC;
	case 20:
		goto loc_826298FC;
	case 21:
		goto loc_826298FC;
	case 22:
		goto loc_826298FC;
	case 23:
		goto loc_826298FC;
	case 24:
		goto loc_826298FC;
	case 25:
		goto loc_826298FC;
	case 26:
		goto loc_826298FC;
	case 27:
		goto loc_826298FC;
	case 28:
		goto loc_826298FC;
	case 29:
		goto loc_826298FC;
	case 30:
		goto loc_826298FC;
	case 31:
		goto loc_826298FC;
	case 32:
		goto loc_826298FC;
	case 33:
		goto loc_826298FC;
	case 34:
		goto loc_826298FC;
	case 35:
		goto loc_826298FC;
	case 36:
		goto loc_826296B4;
	case 37:
		goto loc_82629694;
	case 38:
		goto loc_826298FC;
	case 39:
		goto loc_826298FC;
	case 40:
		goto loc_826298FC;
	case 41:
		goto loc_826298FC;
	case 42:
		goto loc_826298FC;
	case 43:
		goto loc_826298FC;
	case 44:
		goto loc_826298FC;
	case 45:
		goto loc_826298FC;
	case 46:
		goto loc_826298FC;
	case 47:
		goto loc_826298FC;
	case 48:
		goto loc_826298FC;
	case 49:
		goto loc_826298FC;
	case 50:
		goto loc_826298FC;
	case 51:
		goto loc_826298FC;
	case 52:
		goto loc_826298FC;
	case 53:
		goto loc_82629564;
	case 54:
		goto loc_826298FC;
	case 55:
		goto loc_826298A8;
	case 56:
		goto loc_826298FC;
	case 57:
		goto loc_826298FC;
	case 58:
		goto loc_826298FC;
	case 59:
		goto loc_826298FC;
	case 60:
		goto loc_826298FC;
	case 61:
		goto loc_826298FC;
	case 62:
		goto loc_826298FC;
	case 63:
		goto loc_826298FC;
	case 64:
		goto loc_826298FC;
	case 65:
		goto loc_826298FC;
	case 66:
		goto loc_826298FC;
	case 67:
		goto loc_826298FC;
	case 68:
		goto loc_826298FC;
	case 69:
		goto loc_826298FC;
	case 70:
		goto loc_826298FC;
	case 71:
		goto loc_826298FC;
	case 72:
		goto loc_826296D4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-26664(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26664);
	// lwz r19,-26560(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26560);
	// lwz r19,-26872(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26872);
	// lwz r19,-26768(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26768);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-27024(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -27024);
	// lwz r19,-27060(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -27060);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26956(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26956);
	// lwz r19,-26988(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26988);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-27292(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -27292);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26456(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26456);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26372(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26372);
	// lwz r19,-26924(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -26924);
loc_82629564:
	// lbz r11,382(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 382);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82629634
	if (!cr6.eq) goto loc_82629634;
	// bl 0x82387a18
	ctx.lr = 0x82629574;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826295cc
	if (cr6.eq) goto loc_826295CC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,-3624(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 700);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x826295cc
	if (!cr6.eq) goto loc_826295CC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x826295A4;
	sub_82293F60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x826295B4;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x826295B8;
	sub_82293F60(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,-12736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12736);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82629634
	if (!cr6.gt) goto loc_82629634;
loc_826295CC:
	// li r30,0
	r30.s64 = 0;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stb r30,382(r31)
	PPC_STORE_U8(r31.u32 + 382, r30.u8);
	// addi r3,r11,-17880
	ctx.r3.s64 = r11.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x826295E0;
	sub_821E6800(ctx, base);
	// stb r30,1529(r31)
	PPC_STORE_U8(r31.u32 + 1529, r30.u8);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x826295fc
	if (!cr6.eq) goto loc_826295FC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_826295FC:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,776
	ctx.r3.s64 = r11.s64 + 776;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bl 0x8268dff0
	ctx.lr = 0x82629610;
	sub_8268DFF0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82629624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629634:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r11,382(r31)
	PPC_STORE_U8(r31.u32 + 382, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8262964C:
	// lbz r11,1401(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1401);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r11,1184(r31)
	PPC_STORE_U8(r31.u32 + 1184, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629670:
	// lbz r11,1401(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1401);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r11,1185(r31)
	PPC_STORE_U8(r31.u32 + 1185, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629694:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,1184(r31)
	PPC_STORE_U8(r31.u32 + 1184, r11.u8);
	// bl 0x82623bf8
	ctx.lr = 0x826296A4;
	sub_82623BF8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_826296B4:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,1185(r31)
	PPC_STORE_U8(r31.u32 + 1185, r11.u8);
	// bl 0x82623bf8
	ctx.lr = 0x826296C4;
	sub_82623BF8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_826296D4:
	// lbz r10,1484(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1484);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826296e8
	if (cr6.eq) goto loc_826296E8;
	// stb r11,1485(r31)
	PPC_STORE_U8(r31.u32 + 1485, r11.u8);
loc_826296E8:
	// lbz r10,1486(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1486);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// stb r11,1487(r31)
	PPC_STORE_U8(r31.u32 + 1487, r11.u8);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629708:
	// lbz r11,374(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// lbz r11,1184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1185(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1424(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82629288
	ctx.lr = 0x82629760;
	sub_82629288(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629770:
	// lbz r11,374(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// lbz r11,1184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1185(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1424(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82629288
	ctx.lr = 0x826297C8;
	sub_82629288(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_826297D8:
	// lbz r11,374(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// lbz r11,1184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1185(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1424(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82629288
	ctx.lr = 0x82629830;
	sub_82629288(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82629840:
	// lbz r11,374(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// lbz r11,1184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1185(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lbz r11,1424(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826298fc
	if (!cr6.eq) goto loc_826298FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82629288
	ctx.lr = 0x82629898;
	sub_82629288(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_826298A8:
	// lbz r11,377(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 377);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826298fc
	if (cr6.eq) goto loc_826298FC;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-17904
	ctx.r3.s64 = r11.s64 + -17904;
	// bl 0x821e6800
	ctx.lr = 0x826298C0;
	sub_821E6800(ctx, base);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826298D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x826298f0
	if (cr6.eq) goto loc_826298F0;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// b 0x826298f4
	goto loc_826298F4;
loc_826298F0:
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
loc_826298F4:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826298FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826298FC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8262990C"))) PPC_WEAK_FUNC(sub_8262990C);
PPC_FUNC_IMPL(__imp__sub_8262990C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82629910"))) PPC_WEAK_FUNC(sub_82629910);
PPC_FUNC_IMPL(__imp__sub_82629910) {
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
	PPCRegister f0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82629918;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d8
	ctx.lr = 0x82629920;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262993C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82629b90
	if (cr6.eq) goto loc_82629B90;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,1464(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1464);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r31,448
	r30.s64 = r31.s64 + 448;
	// lfs f12,1468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1468);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-11624(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f29,f12,f0
	f29.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261fd58
	ctx.lr = 0x82629978;
	sub_8261FD58(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,208(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262998C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f11,1180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1180);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f29.f64));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmuls f9,f11,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64));
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r28,48
	r28.s64 = 48;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r27,r1,112
	r27.s64 = ctx.r1.s64 + 112;
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lvx128 v11,r3,r28
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// fmuls f8,f10,f30
	ctx.f8.f64 = double(float(ctx.f10.f64 * f30.f64));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f7,f9,f30
	ctx.f7.f64 = double(float(ctx.f9.f64 * f30.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stb r11,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r11.u8);
	// lvlx128 v61,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stb r11,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r11.u8);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stb r11,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r11.u8);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,1
	ctx.r6.s64 = 1;
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vspltw128 v10,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp v9,v0,v12,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v8,v13,v10,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v8,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82625f50
	ctx.lr = 0x82629A40;
	sub_82625F50(ctx, base);
	// lbz r9,496(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82629b90
	if (cr6.eq) goto loc_82629B90;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r6,r31,484
	ctx.r6.s64 = r31.s64 + 484;
	// addi r5,r31,480
	ctx.r5.s64 = r31.s64 + 480;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r9,r11,45
	ctx.r9.s64 = r11.s64 + 45;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82629A78;
	sub_8217C570(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,208(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82629A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,848
	ctx.r5.s64 = 848;
	// li r4,48
	ctx.r4.s64 = 48;
	// lfs f0,572(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 572);
	f0.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f29,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f29.f64 = double(temp.f32);
	// lfs f28,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f28.f64 = double(temp.f32);
	// lvx128 v60,r31,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r3,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// bgt cr6,0x82629acc
	if (cr6.gt) goto loc_82629ACC;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82629ae0
	if (cr6.gt) goto loc_82629AE0;
loc_82629ACC:
	// lfs f12,580(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 580);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x82629b00
	if (cr6.lt) goto loc_82629B00;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82629b00
	if (!cr6.lt) goto loc_82629B00;
loc_82629AE0:
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fadds f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x826263c0
	ctx.lr = 0x82629AFC;
	sub_826263C0(ctx, base);
	// b 0x82629b04
	goto loc_82629B04;
loc_82629B00:
	// lfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f30.f64 = double(temp.f32);
loc_82629B04:
	// lfs f13,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,576(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 576);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x82629b20
	if (cr6.gt) goto loc_82629B20;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82629b34
	if (cr6.gt) goto loc_82629B34;
loc_82629B20:
	// lfs f12,584(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 584);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x82629b48
	if (cr6.lt) goto loc_82629B48;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82629b48
	if (!cr6.lt) goto loc_82629B48;
loc_82629B34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fadds f3,f29,f0
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(f29.f64 + f0.f64));
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x826263c0
	ctx.lr = 0x82629B48;
	sub_826263C0(ctx, base);
loc_82629B48:
	// lbz r11,629(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82629b90
	if (cr6.eq) goto loc_82629B90;
	// lbz r11,1121(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1121);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82629b90
	if (!cr6.eq) goto loc_82629B90;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 568);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x82620158
	ctx.lr = 0x82629B78;
	sub_82620158(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82629b90
	if (!cr6.eq) goto loc_82629B90;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f970
	ctx.lr = 0x82629B90;
	sub_8261F970(ctx, base);
loc_82629B90:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x82629B9C;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82629BA0"))) PPC_WEAK_FUNC(sub_82629BA0);
PPC_FUNC_IMPL(__imp__sub_82629BA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82629BA8;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x82629BB0;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// stfs f29,268(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82629BE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82629fd0
	if (cr6.eq) goto loc_82629FD0;
	// addi r30,r31,448
	r30.s64 = r31.s64 + 448;
	// li r11,464
	r11.s64 = 464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,208(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82629C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r7,48
	ctx.r7.s64 = 48;
	// lbz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f13,1456(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1456);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1460(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1460);
	ctx.f12.f64 = double(temp.f32);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lfs f0,-11624(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lvx128 v127,r3,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f27,f12,f0
	f27.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f0,1180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1180);
	f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82629eb4
	if (cr6.eq) goto loc_82629EB4;
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fmuls f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 * f30.f64));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vor128 v0,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f28,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f28.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f28,112(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f11,f13,f29
	ctx.f11.f64 = double(float(ctx.f13.f64 * f29.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f10,f12,f29
	ctx.f10.f64 = double(float(ctx.f12.f64 * f29.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stfs f28,120(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v0,v62,v59,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826263c0
	ctx.lr = 0x82629CE0;
	sub_826263C0(ctx, base);
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r4,2384
	ctx.r3.s64 = ctx.r4.s64 + 2384;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v126,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v56,v58,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82629d18
	if (!cr6.eq) goto loc_82629D18;
	// stb r28,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, r28.u8);
	// b 0x82629d1c
	goto loc_82629D1C;
loc_82629D18:
	// stb r29,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, r29.u8);
loc_82629D1C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,572(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 572);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82629d34
	if (cr6.gt) goto loc_82629D34;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// blt cr6,0x82629d48
	if (cr6.lt) goto loc_82629D48;
loc_82629D34:
	// lfs f13,580(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 580);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82629d94
	if (cr6.lt) goto loc_82629D94;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82629d94
	if (!cr6.gt) goto loc_82629D94;
loc_82629D48:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fd58
	ctx.lr = 0x82629D50;
	sub_8261FD58(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f28,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stb r28,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r28.u8);
	// lfs f0,1180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1180);
	f0.f64 = double(temp.f32);
	// stb r28,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r28.u8);
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v53,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vmaddfp128 v127,v54,v52,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v52.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82629D94:
	// lfs f0,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	f0.f64 = double(temp.f32);
	// lfs f13,576(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 576);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82629dac
	if (cr6.gt) goto loc_82629DAC;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// blt cr6,0x82629dc0
	if (cr6.lt) goto loc_82629DC0;
loc_82629DAC:
	// lfs f13,584(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 584);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82629e0c
	if (cr6.lt) goto loc_82629E0C;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// ble cr6,0x82629e0c
	if (!cr6.gt) goto loc_82629E0C;
loc_82629DC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fd58
	ctx.lr = 0x82629DC8;
	sub_8261FD58(ctx, base);
	// lfs f0,1180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1180);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f28,120(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stb r28,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r28.u8);
	// stb r28,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r28.u8);
	// fmuls f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp128 v127,v51,v49,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82629E0C:
	// lbz r11,374(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82629e84
	if (cr6.eq) goto loc_82629E84;
	// lbz r11,629(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82629e5c
	if (cr6.eq) goto loc_82629E5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 568);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x82620158
	ctx.lr = 0x82629E3C;
	sub_82620158(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82629e5c
	if (!cr6.eq) goto loc_82629E5C;
	// lwz r11,600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r11.u32);
	// bl 0x8261f970
	ctx.lr = 0x82629E5C;
	sub_8261F970(ctx, base);
loc_82629E5C:
	// lwz r4,604(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 604);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82629e84
	if (cr6.eq) goto loc_82629E84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 568);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826201f8
	ctx.lr = 0x82629E74;
	sub_826201F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82629e84
	if (!cr6.eq) goto loc_82629E84;
	// stw r29,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r29.u32);
loc_82629E84:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r6,r31,484
	ctx.r6.s64 = r31.s64 + 484;
	// addi r5,r31,480
	ctx.r5.s64 = r31.s64 + 480;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r9,r11,45
	ctx.r9.s64 = r11.s64 + 45;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x82629EB0;
	sub_8217C570(ctx, base);
	// b 0x82629f60
	goto loc_82629F60;
loc_82629EB4:
	// fmuls f12,f0,f27
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 * f27.f64));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 * f30.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r29,0
	r29.s64 = 0;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stb r29,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r29.u8);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r29.u8);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stb r29,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r29.u8);
	// fmuls f10,f12,f29
	ctx.f10.f64 = double(float(ctx.f12.f64 * f29.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v45,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f9,f11,f29
	ctx.f9.f64 = double(float(ctx.f11.f64 * f29.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lvlx128 v47,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v47,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// lvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vmaddfp128 v0,v48,v46,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v46.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v127,v11,v11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82625f50
	ctx.lr = 0x82629F60;
	sub_82625F50(ctx, base);
loc_82629F60:
	// addi r11,r1,268
	r11.s64 = ctx.r1.s64 + 268;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r9,848
	ctx.r9.s64 = 848;
	// addi r8,r10,-31664
	ctx.r8.s64 = ctx.r10.s64 + -31664;
	// li r7,1440
	ctx.r7.s64 = 1440;
	// lvlx128 v44,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v43,v44,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// lvx128 v42,r31,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v41,v127,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v42.f32)));
	// vrefp128 v0,v43
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v43.f32)));
	// vor128 v12,v43,v43
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v40,v41,v9
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v40,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,1424(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1424);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82629fcc
	if (cr6.eq) goto loc_82629FCC;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82625f50
	ctx.lr = 0x82629FCC;
	sub_82625F50(ctx, base);
loc_82629FCC:
	// stb r28,396(r31)
	PPC_STORE_U8(r31.u32 + 396, r28.u8);
loc_82629FD0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x82629FEC;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82629FF0"))) PPC_WEAK_FUNC(sub_82629FF0);
PPC_FUNC_IMPL(__imp__sub_82629FF0) {
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
	// bl 0x82130000
	ctx.lr = 0x8262A008;
	sub_82130000(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82628a88
	ctx.lr = 0x8262A010;
	sub_82628A88(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a044
	if (cr6.eq) goto loc_8262A044;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262A044:
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

__attribute__((alias("__imp__sub_8262A058"))) PPC_WEAK_FUNC(sub_8262A058);
PPC_FUNC_IMPL(__imp__sub_8262A058) {
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
	ctx.lr = 0x8262A060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r29,r31,80
	r29.s64 = r31.s64 + 80;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82622178
	ctx.lr = 0x8262A07C;
	sub_82622178(ctx, base);
	// addi r11,r31,228
	r11.s64 = r31.s64 + 228;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262a0a4
	if (cr6.eq) goto loc_8262A0A4;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r10,-10236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r11,248(r10)
	PPC_STORE_U32(ctx.r10.u32 + 248, r11.u32);
	// stb r30,252(r10)
	PPC_STORE_U8(ctx.r10.u32 + 252, r30.u8);
loc_8262A0A4:
	// lis r11,-32121
	r11.s64 = -2105081856;
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
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826290c0
	ctx.lr = 0x8262A0C8;
	sub_826290C0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262A0DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262A0E4"))) PPC_WEAK_FUNC(sub_8262A0E4);
PPC_FUNC_IMPL(__imp__sub_8262A0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

