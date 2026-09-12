#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82499658"))) PPC_WEAK_FUNC(sub_82499658);
PPC_FUNC_IMPL(__imp__sub_82499658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r6,r7,-1476
	ctx.r6.s64 = ctx.r7.s64 + -1476;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// sth r11,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r11.u16);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stb r11,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, r11.u8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stb r11,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, r11.u8);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// stb r11,85(r3)
	PPC_STORE_U8(ctx.r3.u32 + 85, r11.u8);
	// stw r9,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r9.u32);
	// stw r9,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r9.u32);
	// stb r10,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r10.u8);
	// stb r10,97(r3)
	PPC_STORE_U8(ctx.r3.u32 + 97, ctx.r10.u8);
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, r11.u8);
	// stw r5,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r5.u32);
	// stb r11,112(r3)
	PPC_STORE_U8(ctx.r3.u32 + 112, r11.u8);
	// stw r4,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824996FC"))) PPC_WEAK_FUNC(sub_824996FC);
PPC_FUNC_IMPL(__imp__sub_824996FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499700"))) PPC_WEAK_FUNC(sub_82499700);
PPC_FUNC_IMPL(__imp__sub_82499700) {
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
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,0
	ctx.r5.s64 = r11.s64 + 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x82499730;
	sub_821D4268(ctx, base);
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-13432
	ctx.r8.s64 = ctx.r10.s64 + -13432;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lwz r6,12(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_82499778"))) PPC_WEAK_FUNC(sub_82499778);
PPC_FUNC_IMPL(__imp__sub_82499778) {
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
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,0
	ctx.r5.s64 = r11.s64 + 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x824997A8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lwz r6,12(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_824997F0"))) PPC_WEAK_FUNC(sub_824997F0);
PPC_FUNC_IMPL(__imp__sub_824997F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x82499804;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82499820
	if (cr6.eq) goto loc_82499820;
	// bl 0x82499428
	ctx.lr = 0x82499810;
	sub_82499428(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82499820:
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

__attribute__((alias("__imp__sub_82499834"))) PPC_WEAK_FUNC(sub_82499834);
PPC_FUNC_IMPL(__imp__sub_82499834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499838"))) PPC_WEAK_FUNC(sub_82499838);
PPC_FUNC_IMPL(__imp__sub_82499838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x8249984C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82499868
	if (cr6.eq) goto loc_82499868;
	// bl 0x82499658
	ctx.lr = 0x82499858;
	sub_82499658(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82499868:
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

__attribute__((alias("__imp__sub_8249987C"))) PPC_WEAK_FUNC(sub_8249987C);
PPC_FUNC_IMPL(__imp__sub_8249987C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499880"))) PPC_WEAK_FUNC(sub_82499880);
PPC_FUNC_IMPL(__imp__sub_82499880) {
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
	ctx.lr = 0x82499888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x824998A0;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addic. r31,r30,8
	xer.ca = r30.u32 > 4294967287;
	r31.s64 = r30.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x824998d4
	if (cr0.eq) goto loc_824998D4;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x824998CC;
	sub_821C9650(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_824998D4:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824998FC"))) PPC_WEAK_FUNC(sub_824998FC);
PPC_FUNC_IMPL(__imp__sub_824998FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499900"))) PPC_WEAK_FUNC(sub_82499900);
PPC_FUNC_IMPL(__imp__sub_82499900) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20536
	r31.s64 = r11.s64 + 20536;
	// lwz r11,20536(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20536);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82499a00
	if (!cr6.eq) goto loc_82499A00;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82499930;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82499944
	if (cr6.eq) goto loc_82499944;
	// bl 0x821d5408
	ctx.lr = 0x82499940;
	sub_821D5408(ctx, base);
	// b 0x82499948
	goto loc_82499948;
loc_82499944:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82499948:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-1316
	ctx.r7.s64 = ctx.r10.s64 + -1316;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r4,96
	ctx.r4.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r8,-26640
	ctx.r10.s64 = ctx.r8.s64 + -26640;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r9.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824999AC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824999BC;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824999D8;
	sub_821D41D0(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,20532
	ctx.r4.s64 = ctx.r6.s64 + 20532;
	// bl 0x821d4b00
	ctx.lr = 0x824999E8;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x82499A00;
	sub_821C0548(ctx, base);
loc_82499A00:
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

__attribute__((alias("__imp__sub_82499A18"))) PPC_WEAK_FUNC(sub_82499A18);
PPC_FUNC_IMPL(__imp__sub_82499A18) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20544
	r31.s64 = r11.s64 + 20544;
	// lwz r11,20544(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82499b34
	if (!cr6.eq) goto loc_82499B34;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82499A48;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82499a5c
	if (cr6.eq) goto loc_82499A5C;
	// bl 0x821d5408
	ctx.lr = 0x82499A58;
	sub_821D5408(ctx, base);
	// b 0x82499a60
	goto loc_82499A60;
loc_82499A5C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82499A60:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-1288
	ctx.r7.s64 = ctx.r10.s64 + -1288;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25704
	ctx.r9.s64 = r11.s64 + 25704;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,120
	ctx.r5.s64 = 120;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r4,r8,-26568
	ctx.r4.s64 = ctx.r8.s64 + -26568;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,29916(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 29916);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82499acc
	if (!cr6.eq) goto loc_82499ACC;
	// bl 0x824d3318
	ctx.lr = 0x82499AC8;
	sub_824D3318(ctx, base);
	// lwz r4,29916(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 29916);
loc_82499ACC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x82499AD8;
	sub_821D4458(ctx, base);
	// lwz r11,29916(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29916);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x82499AF0;
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
	ctx.lr = 0x82499B0C;
	sub_821D41D0(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,20540
	ctx.r4.s64 = ctx.r8.s64 + 20540;
	// bl 0x821d4b00
	ctx.lr = 0x82499B1C;
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
	ctx.lr = 0x82499B34;
	sub_821C0548(ctx, base);
loc_82499B34:
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

__attribute__((alias("__imp__sub_82499B4C"))) PPC_WEAK_FUNC(sub_82499B4C);
PPC_FUNC_IMPL(__imp__sub_82499B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499B50"))) PPC_WEAK_FUNC(sub_82499B50);
PPC_FUNC_IMPL(__imp__sub_82499B50) {
	PPC_FUNC_PROLOGUE();
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
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// li r6,2
	ctx.r6.s64 = 2;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// addi r5,r7,-1592
	ctx.r5.s64 = ctx.r7.s64 + -1592;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// lfs f0,14992(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	f0.f64 = double(temp.f32);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// lfs f13,32680(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// sth r11,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r11.u16);
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// sth r11,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r11.u16);
	// sth r11,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r11.u16);
	// stfs f31,40(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stb r11,36(r31)
	PPC_STORE_U8(r31.u32 + 36, r11.u8);
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f13,60(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r6.u32);
	// stb r11,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r11.u8);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// bl 0x82499700
	ctx.lr = 0x82499BF0;
	sub_82499700(ctx, base);
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// bl 0x82499778
	ctx.lr = 0x82499BF8;
	sub_82499778(ctx, base);
	// stfs f31,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f31,68(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f10,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f10,76(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f9,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,80(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f31,84(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lfs f8,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,88(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f8,92(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lfs f0,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lfs f12,-1600(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1600);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-6432(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6432);
	ctx.f11.f64 = double(temp.f32);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,116(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f31,120(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f12,124(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f11,128(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
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

__attribute__((alias("__imp__sub_82499C7C"))) PPC_WEAK_FUNC(sub_82499C7C);
PPC_FUNC_IMPL(__imp__sub_82499C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499C80"))) PPC_WEAK_FUNC(sub_82499C80);
PPC_FUNC_IMPL(__imp__sub_82499C80) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82499700
	ctx.lr = 0x82499CA0;
	sub_82499700(ctx, base);
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d42e8
	ctx.lr = 0x82499CB0;
	sub_821D42E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82499cd0
	if (!cr6.eq) goto loc_82499CD0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82499CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82499CD0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824d2cd0
	ctx.lr = 0x82499CD8;
	sub_824D2CD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_82499CF4"))) PPC_WEAK_FUNC(sub_82499CF4);
PPC_FUNC_IMPL(__imp__sub_82499CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499CF8"))) PPC_WEAK_FUNC(sub_82499CF8);
PPC_FUNC_IMPL(__imp__sub_82499CF8) {
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
	ctx.lr = 0x82499D00;
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821d1de0
	ctx.lr = 0x82499D18;
	sub_821D1DE0(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lwz r29,-26876(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82498e98
	ctx.lr = 0x82499D2C;
	sub_82498E98(ctx, base);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// vspltw128 v11,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v9,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v62,r11,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v63,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v8,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v6,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vmulfp128 v5,v0,v60
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v60.f32)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v4,v0,v59
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v3,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmaddfp v2,v0,v7,v8
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v1,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// vspltw128 v31,v63,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v30,v62,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vmaddfp v29,v13,v12,v6
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v13,v10,v5
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v27,v13,v3,v4
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v26,v13,v1,v2
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v25,v12,v11,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v12,v9,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x82499E18;
	sub_8217CE80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8217c658
	ctx.lr = 0x82499E24;
	sub_8217C658(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lfs f1,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217ce78
	ctx.lr = 0x82499E30;
	sub_8217CE78(ctx, base);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82178de8
	ctx.lr = 0x82499E44;
	sub_82178DE8(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178e30
	ctx.lr = 0x82499E50;
	sub_82178E30(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// lwz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82499E88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82178370
	ctx.lr = 0x82499EA8;
	sub_82178370(ctx, base);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82499778
	ctx.lr = 0x82499EB0;
	sub_82499778(ctx, base);
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d42e8
	ctx.lr = 0x82499EC0;
	sub_821D42E8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82499ee4
	if (!cr6.eq) goto loc_82499EE4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82499EE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82499EE4:
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82499F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178de8
	ctx.lr = 0x82499F0C;
	sub_82178DE8(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8217cb48
	ctx.lr = 0x82499F14;
	sub_8217CB48(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82499F1C"))) PPC_WEAK_FUNC(sub_82499F1C);
PPC_FUNC_IMPL(__imp__sub_82499F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499F20"))) PPC_WEAK_FUNC(sub_82499F20);
PPC_FUNC_IMPL(__imp__sub_82499F20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x82499F34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82499f50
	if (cr6.eq) goto loc_82499F50;
	// bl 0x82499b50
	ctx.lr = 0x82499F40;
	sub_82499B50(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82499F50:
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

__attribute__((alias("__imp__sub_82499F64"))) PPC_WEAK_FUNC(sub_82499F64);
PPC_FUNC_IMPL(__imp__sub_82499F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82499F68"))) PPC_WEAK_FUNC(sub_82499F68);
PPC_FUNC_IMPL(__imp__sub_82499F68) {
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
	ctx.lr = 0x82499F70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r26,r3,16
	r26.s64 = ctx.r3.s64 + 16;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// beq cr6,0x8249a00c
	if (cr6.eq) goto loc_8249A00C;
	// li r29,-1
	r29.s64 = -1;
loc_82499F8C:
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82499FA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249a000
	if (cr6.eq) goto loc_8249A000;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82499FC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bl 0x82130528
	ctx.lr = 0x82499FD8;
	sub_82130528(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82499fec
	if (cr0.eq) goto loc_82499FEC;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
loc_82499FEC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_8249A000:
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bne cr6,0x82499f8c
	if (!cr6.eq) goto loc_82499F8C;
loc_8249A00C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8249A014"))) PPC_WEAK_FUNC(sub_8249A014);
PPC_FUNC_IMPL(__imp__sub_8249A014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A018"))) PPC_WEAK_FUNC(sub_8249A018);
PPC_FUNC_IMPL(__imp__sub_8249A018) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-1204
	ctx.r4.s64 = r11.s64 + -1204;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8249A040;
	sub_8218A568(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249a068
	if (cr6.eq) goto loc_8249A068;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-1224
	ctx.r4.s64 = r11.s64 + -1224;
	// bl 0x8218a568
	ctx.lr = 0x8249A05C;
	sub_8218A568(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8249a06c
	if (!cr6.eq) goto loc_8249A06C;
loc_8249A068:
	// li r11,0
	r11.s64 = 0;
loc_8249A06C:
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

__attribute__((alias("__imp__sub_8249A084"))) PPC_WEAK_FUNC(sub_8249A084);
PPC_FUNC_IMPL(__imp__sub_8249A084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A088"))) PPC_WEAK_FUNC(sub_8249A088);
PPC_FUNC_IMPL(__imp__sub_8249A088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8249A090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x8218a788
	ctx.lr = 0x8249A0B8;
	sub_8218A788(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a788
	ctx.lr = 0x8249A0CC;
	sub_8218A788(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,24(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8249A0E0;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,28(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8249A0F4;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,32(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r5,20(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8249A108;
	sub_82189CE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249A110"))) PPC_WEAK_FUNC(sub_8249A110);
PPC_FUNC_IMPL(__imp__sub_8249A110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29940(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29940);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A11C"))) PPC_WEAK_FUNC(sub_8249A11C);
PPC_FUNC_IMPL(__imp__sub_8249A11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A120"))) PPC_WEAK_FUNC(sub_8249A120);
PPC_FUNC_IMPL(__imp__sub_8249A120) {
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
	ctx.lr = 0x8249A128;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-1140
	ctx.r4.s64 = r11.s64 + -1140;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A15C;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,-1160
	ctx.r4.s64 = ctx.r7.s64 + -1160;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A184;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,-1176
	ctx.r4.s64 = ctx.r10.s64 + -1176;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A1AC;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,-1204
	ctx.r4.s64 = ctx.r6.s64 + -1204;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A1D4;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r9,-1224
	ctx.r4.s64 = ctx.r9.s64 + -1224;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A1FC;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249A208"))) PPC_WEAK_FUNC(sub_8249A208);
PPC_FUNC_IMPL(__imp__sub_8249A208) {
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
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8249A21C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249a240
	if (cr6.eq) goto loc_8249A240;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-1184
	ctx.r10.s64 = r11.s64 + -1184;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8249A240:
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

__attribute__((alias("__imp__sub_8249A254"))) PPC_WEAK_FUNC(sub_8249A254);
PPC_FUNC_IMPL(__imp__sub_8249A254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A258"))) PPC_WEAK_FUNC(sub_8249A258);
PPC_FUNC_IMPL(__imp__sub_8249A258) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-10920
	ctx.r9.s64 = r11.s64 + -10920;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8249a28c
	if (cr6.eq) goto loc_8249A28C;
	// bl 0x82130588
	ctx.lr = 0x8249A288;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249A28C:
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

__attribute__((alias("__imp__sub_8249A2A0"))) PPC_WEAK_FUNC(sub_8249A2A0);
PPC_FUNC_IMPL(__imp__sub_8249A2A0) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-1252
	ctx.r10.s64 = r11.s64 + -1252;
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249a300
	if (cr6.eq) goto loc_8249A300;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8249A2D8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249a300
	if (!cr6.eq) goto loc_8249A300;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249a300
	if (cr6.eq) goto loc_8249A300;
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
	ctx.lr = 0x8249A300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249A300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dda48
	ctx.lr = 0x8249A308;
	sub_822DDA48(ctx, base);
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

__attribute__((alias("__imp__sub_8249A320"))) PPC_WEAK_FUNC(sub_8249A320);
PPC_FUNC_IMPL(__imp__sub_8249A320) {
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
	// bl 0x8249a2a0
	ctx.lr = 0x8249A340;
	sub_8249A2A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249a358
	if (cr6.eq) goto loc_8249A358;
	// bl 0x82130588
	ctx.lr = 0x8249A354;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249A358:
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

__attribute__((alias("__imp__sub_8249A370"))) PPC_WEAK_FUNC(sub_8249A370);
PPC_FUNC_IMPL(__imp__sub_8249A370) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-1088
	ctx.r4.s64 = r11.s64 + -1088;
	// bl 0x8218a568
	ctx.lr = 0x8249A390;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A3AC"))) PPC_WEAK_FUNC(sub_8249A3AC);
PPC_FUNC_IMPL(__imp__sub_8249A3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A3B0"))) PPC_WEAK_FUNC(sub_8249A3B0);
PPC_FUNC_IMPL(__imp__sub_8249A3B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x82189ce0
	sub_82189CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8249A3C8"))) PPC_WEAK_FUNC(sub_8249A3C8);
PPC_FUNC_IMPL(__imp__sub_8249A3C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29944);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A3D4"))) PPC_WEAK_FUNC(sub_8249A3D4);
PPC_FUNC_IMPL(__imp__sub_8249A3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A3D8"))) PPC_WEAK_FUNC(sub_8249A3D8);
PPC_FUNC_IMPL(__imp__sub_8249A3D8) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r4,r10,-1088
	ctx.r4.s64 = ctx.r10.s64 + -1088;
	// lwz r11,30516(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A414;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8249A42C"))) PPC_WEAK_FUNC(sub_8249A42C);
PPC_FUNC_IMPL(__imp__sub_8249A42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A430"))) PPC_WEAK_FUNC(sub_8249A430);
PPC_FUNC_IMPL(__imp__sub_8249A430) {
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
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8249A444;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249a468
	if (cr6.eq) goto loc_8249A468;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-1068
	ctx.r10.s64 = r11.s64 + -1068;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8249A468:
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

__attribute__((alias("__imp__sub_8249A47C"))) PPC_WEAK_FUNC(sub_8249A47C);
PPC_FUNC_IMPL(__imp__sub_8249A47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A480"))) PPC_WEAK_FUNC(sub_8249A480);
PPC_FUNC_IMPL(__imp__sub_8249A480) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-1116
	ctx.r10.s64 = r11.s64 + -1116;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249a4e0
	if (cr6.eq) goto loc_8249A4E0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8249A4B8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249a4e0
	if (!cr6.eq) goto loc_8249A4E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249a4e0
	if (cr6.eq) goto loc_8249A4E0;
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
	ctx.lr = 0x8249A4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249A4E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dda48
	ctx.lr = 0x8249A4E8;
	sub_822DDA48(ctx, base);
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

__attribute__((alias("__imp__sub_8249A500"))) PPC_WEAK_FUNC(sub_8249A500);
PPC_FUNC_IMPL(__imp__sub_8249A500) {
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
	// bl 0x8249a480
	ctx.lr = 0x8249A520;
	sub_8249A480(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249a538
	if (cr6.eq) goto loc_8249A538;
	// bl 0x82130588
	ctx.lr = 0x8249A534;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249A538:
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

__attribute__((alias("__imp__sub_8249A550"))) PPC_WEAK_FUNC(sub_8249A550);
PPC_FUNC_IMPL(__imp__sub_8249A550) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-1028
	ctx.r4.s64 = r11.s64 + -1028;
	// bl 0x8218a568
	ctx.lr = 0x8249A570;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A58C"))) PPC_WEAK_FUNC(sub_8249A58C);
PPC_FUNC_IMPL(__imp__sub_8249A58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A590"))) PPC_WEAK_FUNC(sub_8249A590);
PPC_FUNC_IMPL(__imp__sub_8249A590) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8249A598;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f13,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8249A5DC;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,24(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8249A5F0;
	sub_82189CE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249A5F8"))) PPC_WEAK_FUNC(sub_8249A5F8);
PPC_FUNC_IMPL(__imp__sub_8249A5F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29948(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29948);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A604"))) PPC_WEAK_FUNC(sub_8249A604);
PPC_FUNC_IMPL(__imp__sub_8249A604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A608"))) PPC_WEAK_FUNC(sub_8249A608);
PPC_FUNC_IMPL(__imp__sub_8249A608) {
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
	ctx.lr = 0x8249A610;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-1028
	ctx.r4.s64 = r11.s64 + -1028;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A644;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,-1004
	ctx.r4.s64 = ctx.r7.s64 + -1004;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A66C;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249A678"))) PPC_WEAK_FUNC(sub_8249A678);
PPC_FUNC_IMPL(__imp__sub_8249A678) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8249A68C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249a6b0
	if (cr6.eq) goto loc_8249A6B0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-1012
	ctx.r10.s64 = r11.s64 + -1012;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8249A6B0:
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

__attribute__((alias("__imp__sub_8249A6C4"))) PPC_WEAK_FUNC(sub_8249A6C4);
PPC_FUNC_IMPL(__imp__sub_8249A6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A6C8"))) PPC_WEAK_FUNC(sub_8249A6C8);
PPC_FUNC_IMPL(__imp__sub_8249A6C8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-1056
	ctx.r10.s64 = r11.s64 + -1056;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822dda48
	ctx.lr = 0x8249A6F4;
	sub_822DDA48(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249a70c
	if (cr6.eq) goto loc_8249A70C;
	// bl 0x82130588
	ctx.lr = 0x8249A708;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249A70C:
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

__attribute__((alias("__imp__sub_8249A724"))) PPC_WEAK_FUNC(sub_8249A724);
PPC_FUNC_IMPL(__imp__sub_8249A724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A728"))) PPC_WEAK_FUNC(sub_8249A728);
PPC_FUNC_IMPL(__imp__sub_8249A728) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-956
	ctx.r4.s64 = r11.s64 + -956;
	// bl 0x8218a568
	ctx.lr = 0x8249A748;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A764"))) PPC_WEAK_FUNC(sub_8249A764);
PPC_FUNC_IMPL(__imp__sub_8249A764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A768"))) PPC_WEAK_FUNC(sub_8249A768);
PPC_FUNC_IMPL(__imp__sub_8249A768) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8249A770;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r6,36(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x82189ce0
	ctx.lr = 0x8249A798;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8249A7AC;
	sub_82189CE0(ctx, base);
	// lfs f0,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x8218a6e0
	ctx.lr = 0x8249A7D4;
	sub_8218A6E0(ctx, base);
	// lfs f13,28(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x8218a6e0
	ctx.lr = 0x8249A7FC;
	sub_8218A6E0(ctx, base);
	// lfs f12,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,20(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x8249A824;
	sub_8218A6E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249A82C"))) PPC_WEAK_FUNC(sub_8249A82C);
PPC_FUNC_IMPL(__imp__sub_8249A82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A830"))) PPC_WEAK_FUNC(sub_8249A830);
PPC_FUNC_IMPL(__imp__sub_8249A830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29952(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29952);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249A83C"))) PPC_WEAK_FUNC(sub_8249A83C);
PPC_FUNC_IMPL(__imp__sub_8249A83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A840"))) PPC_WEAK_FUNC(sub_8249A840);
PPC_FUNC_IMPL(__imp__sub_8249A840) {
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
	ctx.lr = 0x8249A848;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-900
	ctx.r4.s64 = r11.s64 + -900;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A87C;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-912
	ctx.r4.s64 = ctx.r7.s64 + -912;
	// bl 0x8218a568
	ctx.lr = 0x8249A894;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,-956
	ctx.r4.s64 = ctx.r6.s64 + -956;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A8BC;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r9,-924
	ctx.r4.s64 = ctx.r9.s64 + -924;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A8E4;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r4,r5,-936
	ctx.r4.s64 = ctx.r5.s64 + -936;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x8249A90C;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249A918"))) PPC_WEAK_FUNC(sub_8249A918);
PPC_FUNC_IMPL(__imp__sub_8249A918) {
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
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8249A92C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249a950
	if (cr6.eq) goto loc_8249A950;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-944
	ctx.r10.s64 = r11.s64 + -944;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8249A950:
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

__attribute__((alias("__imp__sub_8249A964"))) PPC_WEAK_FUNC(sub_8249A964);
PPC_FUNC_IMPL(__imp__sub_8249A964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A968"))) PPC_WEAK_FUNC(sub_8249A968);
PPC_FUNC_IMPL(__imp__sub_8249A968) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-984
	ctx.r10.s64 = r11.s64 + -984;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822dda48
	ctx.lr = 0x8249A994;
	sub_822DDA48(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249a9ac
	if (cr6.eq) goto loc_8249A9AC;
	// bl 0x82130588
	ctx.lr = 0x8249A9A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249A9AC:
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

__attribute__((alias("__imp__sub_8249A9C4"))) PPC_WEAK_FUNC(sub_8249A9C4);
PPC_FUNC_IMPL(__imp__sub_8249A9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249A9C8"))) PPC_WEAK_FUNC(sub_8249A9C8);
PPC_FUNC_IMPL(__imp__sub_8249A9C8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20528
	r31.s64 = r11.s64 + 20528;
	// lwz r11,20528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249ab54
	if (!cr6.eq) goto loc_8249AB54;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8249A9F8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249aa0c
	if (cr6.eq) goto loc_8249AA0C;
	// bl 0x821d5408
	ctx.lr = 0x8249AA08;
	sub_821D5408(ctx, base);
	// b 0x8249aa10
	goto loc_8249AA10;
loc_8249AA0C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8249AA10:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-888
	ctx.r7.s64 = ctx.r10.s64 + -888;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25704
	ctx.r9.s64 = r11.s64 + 25704;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,176
	ctx.r5.s64 = 176;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// addi r4,r8,-24800
	ctx.r4.s64 = ctx.r8.s64 + -24800;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r9,r3,-25596
	ctx.r9.s64 = ctx.r3.s64 + -25596;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r3,r8,-25548
	ctx.r3.s64 = ctx.r8.s64 + -25548;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r5,-25524
	ctx.r8.s64 = ctx.r5.s64 + -25524;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,48
	r11.s64 = 48;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r9,56
	ctx.r9.s64 = 56;
	// addi r4,r10,-25572
	ctx.r4.s64 = ctx.r10.s64 + -25572;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// li r11,60
	r11.s64 = 60;
	// lis r6,-32128
	ctx.r6.s64 = -2105540608;
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r10,52
	ctx.r10.s64 = 52;
	// addi r3,r7,-25500
	ctx.r3.s64 = ctx.r7.s64 + -25500;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r8,r6,-25464
	ctx.r8.s64 = ctx.r6.s64 + -25464;
	// addi r7,r5,-25428
	ctx.r7.s64 = ctx.r5.s64 + -25428;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r9,112
	ctx.r9.s64 = 112;
	// li r11,128
	r11.s64 = 128;
	// lwz r4,29916(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 29916);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// bne cr6,0x8249aaec
	if (!cr6.eq) goto loc_8249AAEC;
	// bl 0x824d3318
	ctx.lr = 0x8249AAE8;
	sub_824D3318(ctx, base);
	// lwz r4,29916(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 29916);
loc_8249AAEC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8249AAF8;
	sub_821D4458(ctx, base);
	// lwz r11,29916(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29916);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8249AB10;
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
	ctx.lr = 0x8249AB2C;
	sub_821D41D0(ctx, base);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-25404
	ctx.r4.s64 = ctx.r8.s64 + -25404;
	// bl 0x821d4b00
	ctx.lr = 0x8249AB3C;
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
	ctx.lr = 0x8249AB54;
	sub_821C0548(ctx, base);
loc_8249AB54:
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

__attribute__((alias("__imp__sub_8249AB6C"))) PPC_WEAK_FUNC(sub_8249AB6C);
PPC_FUNC_IMPL(__imp__sub_8249AB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249AB70"))) PPC_WEAK_FUNC(sub_8249AB70);
PPC_FUNC_IMPL(__imp__sub_8249AB70) {
	PPC_FUNC_PROLOGUE();
	// b 0x82499cf8
	sub_82499CF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8249AB74"))) PPC_WEAK_FUNC(sub_8249AB74);
PPC_FUNC_IMPL(__imp__sub_8249AB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249AB78"))) PPC_WEAK_FUNC(sub_8249AB78);
PPC_FUNC_IMPL(__imp__sub_8249AB78) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8249AB80;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8249AB90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249ac04
	if (cr6.eq) goto loc_8249AC04;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lfs f13,17032(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// addi r5,r6,-984
	ctx.r5.s64 = ctx.r6.s64 + -984;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f12,15004(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15004);
	ctx.f12.f64 = double(temp.f32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// stfs f12,28(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stb r4,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r4.u8);
	// b 0x8249ac08
	goto loc_8249AC08;
loc_8249AC04:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8249AC08:
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// addi r30,r27,80
	r30.s64 = r27.s64 + 80;
	// stw r9,68(r27)
	PPC_STORE_U32(r27.u32 + 68, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8249ac60
	if (!cr6.eq) goto loc_8249AC60;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-848
	ctx.r4.s64 = ctx.r10.s64 + -848;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8249AC40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82491948
	ctx.lr = 0x8249AC4C;
	sub_82491948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824924b0
	ctx.lr = 0x8249AC58;
	sub_824924B0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822dbfd8
	ctx.lr = 0x8249AC60;
	sub_822DBFD8(ctx, base);
loc_8249AC60:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249ac74
	if (cr6.eq) goto loc_8249AC74;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8249AC74;
	sub_821CE0D8(ctx, base);
loc_8249AC74:
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r31.u32);
	// beq cr6,0x8249acac
	if (cr6.eq) goto loc_8249ACAC;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8249AC8C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249acac
	if (!cr6.eq) goto loc_8249ACAC;
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
	ctx.lr = 0x8249ACAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249ACAC:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249acc0
	if (cr6.eq) goto loc_8249ACC0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8249ACC0;
	sub_821CE0D8(ctx, base);
loc_8249ACC0:
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r31.u32);
	// beq cr6,0x8249acf8
	if (cr6.eq) goto loc_8249ACF8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8249ACD8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249acf8
	if (!cr6.eq) goto loc_8249ACF8;
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
	ctx.lr = 0x8249ACF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249ACF8:
	// lwz r31,68(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// li r30,-1
	r30.s64 = -1;
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8249AD1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bl 0x82130528
	ctx.lr = 0x8249AD2C;
	sub_82130528(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addic. r11,r10,8
	xer.ca = ctx.r10.u32 > 4294967287;
	r11.s64 = ctx.r10.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8249ad44
	if (cr0.eq) goto loc_8249AD44;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
loc_8249AD44:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x82498c30
	ctx.lr = 0x8249AD60;
	sub_82498C30(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249AD68"))) PPC_WEAK_FUNC(sub_8249AD68);
PPC_FUNC_IMPL(__imp__sub_8249AD68) {
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
	ctx.lr = 0x8249AD70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r10,r11,13284
	ctx.r10.s64 = r11.s64 + 13284;
	// stw r30,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82695df0
	ctx.lr = 0x8249ADA4;
	sub_82695DF0(ctx, base);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824989a8
	ctx.lr = 0x8249ADB8;
	sub_824989A8(ctx, base);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82499880
	ctx.lr = 0x8249ADD0;
	sub_82499880(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x8249ADD8;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249ADE0"))) PPC_WEAK_FUNC(sub_8249ADE0);
PPC_FUNC_IMPL(__imp__sub_8249ADE0) {
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
	ctx.lr = 0x8249ADE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r10,r11,13328
	ctx.r10.s64 = r11.s64 + 13328;
	// stw r30,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82695df0
	ctx.lr = 0x8249AE1C;
	sub_82695DF0(ctx, base);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824989a8
	ctx.lr = 0x8249AE30;
	sub_824989A8(ctx, base);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82499880
	ctx.lr = 0x8249AE48;
	sub_82499880(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x8249AE50;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249AE58"))) PPC_WEAK_FUNC(sub_8249AE58);
PPC_FUNC_IMPL(__imp__sub_8249AE58) {
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
	ctx.lr = 0x8249AE60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r10,r11,13372
	ctx.r10.s64 = r11.s64 + 13372;
	// stw r30,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82695df0
	ctx.lr = 0x8249AE94;
	sub_82695DF0(ctx, base);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824989a8
	ctx.lr = 0x8249AEA8;
	sub_824989A8(ctx, base);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82499880
	ctx.lr = 0x8249AEC0;
	sub_82499880(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x8249AEC8;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249AED0"))) PPC_WEAK_FUNC(sub_8249AED0);
PPC_FUNC_IMPL(__imp__sub_8249AED0) {
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
	ctx.lr = 0x8249AED8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x8249AEE8;
	sub_82130528(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r29,0
	r29.s64 = 0;
	// beq cr6,0x8249af44
	if (cr6.eq) goto loc_8249AF44;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r7,r8,-1252
	ctx.r7.s64 = ctx.r8.s64 + -1252;
	// std r29,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r29.u64);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// stw r29,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r29.u32);
	// stw r29,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r29.u32);
	// stw r29,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r29.u32);
	// stb r28,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, r28.u8);
	// b 0x8249af48
	goto loc_8249AF48;
loc_8249AF44:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8249AF48:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// beq cr6,0x8249af74
	if (cr6.eq) goto loc_8249AF74;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_8249AF74:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// bl 0x824d3a10
	ctx.lr = 0x8249AF80;
	sub_824D3A10(ctx, base);
	// lis r11,21845
	r11.s64 = 1431633920;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// ori r11,r11,21846
	r11.u64 = r11.u64 | 21846;
	// lwz r5,132(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r4,r10,-736
	ctx.r4.s64 = ctx.r10.s64 + -736;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// mulhw r11,r6,r9
	r11.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r3,r6
	r11.s64 = ctx.r6.s64 - ctx.r3.s64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stw r9,28(r5)
	PPC_STORE_U32(ctx.r5.u32 + 28, ctx.r9.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r6,132(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mulhw r11,r5,r8
	r11.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r3,r5
	r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stw r9,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r9.u32);
	// lwz r5,132(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,20580(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20580);
	// bl 0x8249ad68
	ctx.lr = 0x8249B014;
	sub_8249AD68(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,20580(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20580);
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x82499f68
	ctx.lr = 0x8249B024;
	sub_82499F68(ctx, base);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8249B02C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249b06c
	if (cr6.eq) goto loc_8249B06C;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// addi r7,r8,-1116
	ctx.r7.s64 = ctx.r8.s64 + -1116;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// std r29,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r29.u64);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r29.u32);
	// stb r28,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r28.u8);
	// b 0x8249b070
	goto loc_8249B070;
loc_8249B06C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8249B070:
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// beq cr6,0x8249b09c
	if (cr6.eq) goto loc_8249B09C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_8249B09C:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x824d3a58
	ctx.lr = 0x8249B0A8;
	sub_824D3A58(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20580(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20580);
	// addi r4,r11,-760
	ctx.r4.s64 = r11.s64 + -760;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x8249ade0
	ctx.lr = 0x8249B0BC;
	sub_8249ADE0(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,20580(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20580);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82499f68
	ctx.lr = 0x8249B0CC;
	sub_82499F68(ctx, base);
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x8249B0D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249b130
	if (cr6.eq) goto loc_8249B130;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// std r29,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r29.u64);
	// addi r6,r7,-1056
	ctx.r6.s64 = ctx.r7.s64 + -1056;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-17876(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -17876);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r29,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r29.u32);
	// stw r29,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r29.u32);
	// stb r28,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r28.u8);
	// b 0x8249b134
	goto loc_8249B134;
loc_8249B130:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8249B134:
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r4,r9,-780
	ctx.r4.s64 = ctx.r9.s64 + -780;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r7,44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwzx r11,r5,r6
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r3,20580(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20580);
	// bl 0x8249ae58
	ctx.lr = 0x8249B170;
	sub_8249AE58(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249B178"))) PPC_WEAK_FUNC(sub_8249B178);
PPC_FUNC_IMPL(__imp__sub_8249B178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249B188"))) PPC_WEAK_FUNC(sub_8249B188);
PPC_FUNC_IMPL(__imp__sub_8249B188) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20588
	r31.s64 = r11.s64 + 20588;
	// lwz r11,20588(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20588);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249b268
	if (!cr6.eq) goto loc_8249B268;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8249B1B4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249b1c4
	if (cr6.eq) goto loc_8249B1C4;
	// bl 0x821d5408
	ctx.lr = 0x8249B1C0;
	sub_821D5408(ctx, base);
	// b 0x8249b1c8
	goto loc_8249B1C8;
loc_8249B1C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8249B1C8:
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// addi r4,r8,-368
	ctx.r4.s64 = ctx.r8.s64 + -368;
	// addi r9,r11,-20104
	ctx.r9.s64 = r11.s64 + -20104;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8249B214;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8249B224;
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
	ctx.lr = 0x8249B240;
	sub_821D41D0(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,20584
	ctx.r4.s64 = ctx.r8.s64 + 20584;
	// bl 0x821d4b00
	ctx.lr = 0x8249B250;
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
	ctx.lr = 0x8249B268;
	sub_821C0548(ctx, base);
loc_8249B268:
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

__attribute__((alias("__imp__sub_8249B27C"))) PPC_WEAK_FUNC(sub_8249B27C);
PPC_FUNC_IMPL(__imp__sub_8249B27C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249B280"))) PPC_WEAK_FUNC(sub_8249B280);
PPC_FUNC_IMPL(__imp__sub_8249B280) {
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
	ctx.lr = 0x8249B288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// beq cr6,0x8249b2ac
	if (cr6.eq) goto loc_8249B2AC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x8249B2AC;
	sub_821CA540(ctx, base);
loc_8249B2AC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r28,r10,64
	r28.s64 = ctx.r10.s64 + 64;
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
	ctx.lr = 0x8249B2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
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
	ctx.lr = 0x8249B30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249b31c
	if (cr6.eq) goto loc_8249B31C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8249B31C;
	sub_821C9A90(ctx, base);
loc_8249B31C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8218a4e8
	ctx.lr = 0x8249B32C;
	sub_8218A4E8(ctx, base);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,24
	ctx.r3.s64 = ctx.r10.s64 + 24;
	// bl 0x8218a4e8
	ctx.lr = 0x8249B340;
	sub_8218A4E8(ctx, base);
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,16
	ctx.r4.s64 = ctx.r8.s64 + 16;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8249B35C;
	sub_8218B688(ctx, base);
	// stw r3,1256(r30)
	PPC_STORE_U32(r30.u32 + 1256, ctx.r3.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,0
	ctx.r3.s64 = ctx.r7.s64 + 0;
	// bl 0x8218a4e8
	ctx.lr = 0x8249B370;
	sub_8218A4E8(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249B37C"))) PPC_WEAK_FUNC(sub_8249B37C);
PPC_FUNC_IMPL(__imp__sub_8249B37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249B380"))) PPC_WEAK_FUNC(sub_8249B380);
PPC_FUNC_IMPL(__imp__sub_8249B380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x8249B3A0;
	sub_82180430(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// lwz r6,1248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// subfic r11,r6,1344
	xer.ca = ctx.r6.u32 <= 1344;
	r11.s64 = 1344 - ctx.r6.s64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r3,-25232(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25232);
	// addi r4,r7,84
	ctx.r4.s64 = ctx.r7.s64 + 84;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stb r10,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r10.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249B3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,1252(r31)
	PPC_STORE_U32(r31.u32 + 1252, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8249B414"))) PPC_WEAK_FUNC(sub_8249B414);
PPC_FUNC_IMPL(__imp__sub_8249B414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249B418"))) PPC_WEAK_FUNC(sub_8249B418);
PPC_FUNC_IMPL(__imp__sub_8249B418) {
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
	// lwz r31,1252(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1252);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249b474
	if (cr6.eq) goto loc_8249B474;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8249B444;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249b46c
	if (!cr6.eq) goto loc_8249B46C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249b46c
	if (cr6.eq) goto loc_8249B46C;
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
	ctx.lr = 0x8249B46C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249B46C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,1252(r30)
	PPC_STORE_U32(r30.u32 + 1252, r11.u32);
loc_8249B474:
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

__attribute__((alias("__imp__sub_8249B48C"))) PPC_WEAK_FUNC(sub_8249B48C);
PPC_FUNC_IMPL(__imp__sub_8249B48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249B490"))) PPC_WEAK_FUNC(sub_8249B490);
PPC_FUNC_IMPL(__imp__sub_8249B490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r31,1272
	ctx.r5.s64 = r31.s64 + 1272;
	// lwz r11,1248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r9,1292(r31)
	PPC_STORE_U8(r31.u32 + 1292, ctx.r9.u8);
	// subfic r8,r11,1344
	xer.ca = r11.u32 <= 1344;
	ctx.r8.s64 = 1344 - r11.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r7,31
	ctx.r3.u64 = ctx.r7.u32 & 0x1;
	// stb r3,1293(r31)
	PPC_STORE_U8(r31.u32 + 1293, ctx.r3.u8);
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249B4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r3,12
	ctx.r3.s64 = 12;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8217f768
	ctx.lr = 0x8249B504;
	sub_8217F768(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8217f768
	ctx.lr = 0x8249B510;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,1264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// bl 0x8217c658
	ctx.lr = 0x8249B51C;
	sub_8217C658(ctx, base);
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

__attribute__((alias("__imp__sub_8249B534"))) PPC_WEAK_FUNC(sub_8249B534);
PPC_FUNC_IMPL(__imp__sub_8249B534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249B538"))) PPC_WEAK_FUNC(sub_8249B538);
PPC_FUNC_IMPL(__imp__sub_8249B538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
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

__attribute__((alias("__imp__sub_8249B548"))) PPC_WEAK_FUNC(sub_8249B548);
PPC_FUNC_IMPL(__imp__sub_8249B548) {
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v14{};
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8249B550;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d0
	ctx.lr = 0x8249B558;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dd52c
	ctx.lr = 0x8249B560;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// li r10,96
	ctx.r10.s64 = 96;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// li r9,64
	ctx.r9.s64 = 64;
	// stfs f31,532(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// li r8,80
	ctx.r8.s64 = 80;
	// stfs f30,540(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r29,r6,2528
	r29.s64 = ctx.r6.s64 + 2528;
	// addi r28,r5,2240
	r28.s64 = ctx.r5.s64 + 2240;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// vsubfp128 v60,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v59,r3,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r3,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v59,v59
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v56,v58,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r27,r4,-31648
	r27.s64 = ctx.r4.s64 + -31648;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r26,r11,-31664
	r26.s64 = r11.s64 + -31664;
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,696(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 696);
	f0.f64 = double(temp.f32);
	// li r9,112
	ctx.r9.s64 = 112;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f28.f64 = double(temp.f32);
	// vmsum3fp128 v55,v60,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// fmuls f13,f0,f28
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// lvx128 v126,r3,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v54,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vrsqrtefp128 v53,v56
	simde_mm_store_ps(v53.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v9,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// fmuls f29,f13,f3
	ctx.fpscr.disableFlushModeUnconditional();
	f29.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// vrsqrtefp128 v52,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v7,v54,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vcmpeqfp128 v5,v53,v62
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v4,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vcmpeqfp128 v3,v52,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v2,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vsel v13,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v12,v4,v12,v5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vmulfp128 v1,v13,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v31,v12,v12
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v30,v61,v13
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v29,v61,v12
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vsel v0,v2,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v28,v0,v0
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v27,v10,v1,v11
	simde_mm_store_ps(v27.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v26,v9,v31,v11
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v25,v61,v0
	simde_mm_store_ps(v25.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v24,v8,v28,v11
	simde_mm_store_ps(v24.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v23,v27,v30,v13
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v27.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v22,v26,v29,v12
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v21,v24,v25,v0
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v24.f32), simde_mm_load_ps(v25.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v124,v59,v23
	simde_mm_store_ps(v124.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v23.f32)));
	// vmulfp128 v123,v58,v22
	simde_mm_store_ps(v123.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v22.f32)));
	// vmulfp128 v125,v60,v21
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v21.f32)));
	// bl 0x82171600
	ctx.lr = 0x8249B688;
	sub_82171600(ctx, base);
	// fmuls f12,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 * f29.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,27644(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f29,f29,f0
	f29.f64 = double(float(f29.f64 * f0.f64));
	// fmuls f27,f12,f0
	f27.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbf10
	ctx.lr = 0x8249B6A4;
	sub_823DBF10(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbf10
	ctx.lr = 0x8249B6B0;
	sub_823DBF10(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// fmuls f10,f26,f30
	ctx.f10.f64 = double(float(f26.f64 * f30.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmuls f9,f11,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x823dbf10
	ctx.lr = 0x8249B6CC;
	sub_823DBF10(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbf10
	ctx.lr = 0x8249B6D8;
	sub_823DBF10(ctx, base);
	// fmuls f8,f27,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(f27.f64 * f30.f64));
	// stfs f8,84(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f7,f1
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// lvx128 v51,r0,r25
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,532
	ctx.r6.s64 = ctx.r1.s64 + 532;
	// vmsum3fp128 v50,v51,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// vor128 v49,v126,v126
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// li r3,16
	ctx.r3.s64 = 16;
	// vsubfp128 v48,v127,v123
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v123.f32)));
	// addi r11,r1,540
	r11.s64 = ctx.r1.s64 + 540;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v47,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvlx128 v45,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v47,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// lvlx128 v44,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v43,v45,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// lvx128 v42,r25,r3
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v41,v44,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// fmuls f6,f7,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmsum3fp128 v40,v42,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// vmaddfp128 v49,v125,v46,v49
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v46.f32)), simde_mm_load_ps(v49.f32)));
	// vmulfp128 v39,v124,v43
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v43.f32)));
	// li r9,32
	ctx.r9.s64 = 32;
	// vmulfp128 v37,v124,v41
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v41.f32)));
	// lvlx128 v38,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v36,v38,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v20,v63,v63
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r25,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v19,v63,v63
	simde_mm_store_si128((simde__m128i*)v19.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vrsqrtefp128 v35,v50
	simde_mm_store_ps(v35.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vmsum3fp128 v44,v52,v52
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// lvlx128 v33,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp128 v126,v125,v36,v126
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v36.f32)), simde_mm_load_ps(v126.f32)));
	// lvlx128 v34,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v34,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vspltw128 v32,v33,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// vcmpeqfp128 v16,v35,v62
	simde_mm_store_ps(v16.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v62.f32)));
	// vrsqrtefp128 v59,v40
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v40.f32))));
	// vor128 v18,v35,v35
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// vsubfp128 v58,v127,v39
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v39.f32)));
	// lvx128 v53,r25,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v127,v37
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v37.f32)));
	// lvx128 v12,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v48,v60
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v45,v49,v39
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v39.f32)));
	// vor128 v17,v50,v50
	simde_mm_store_si128((simde__m128i*)v17.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vmulfp128 v46,v48,v32
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v32.f32)));
	// vor128 v15,v63,v63
	simde_mm_store_si128((simde__m128i*)v15.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vaddfp128 v43,v126,v37
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v37.f32)));
	// vor128 v10,v44,v44
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v44.u8));
	// vsel v0,v18,v20,v16
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v16.u8), simde_mm_load_si128((simde__m128i*)v20.u8))));
	// vcmpeqfp128 v14,v59,v62
	simde_mm_store_ps(v14.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v13,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vaddfp128 v41,v49,v58
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v58.f32)));
	// vaddfp128 v39,v126,v57
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v57.f32)));
	// vsubfp128 v38,v127,v47
	simde_mm_store_ps(v38.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v47.f32)));
	// vaddfp128 v36,v45,v47
	simde_mm_store_ps(v36.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v47.f32)));
	// vsubfp128 v37,v127,v46
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v46.f32)));
	// vmulfp128 v11,v0,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vrsqrtefp128 v35,v44
	simde_mm_store_ps(v35.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v44.f32))));
	// vsel v13,v13,v19,v14
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v14.u8), simde_mm_load_si128((simde__m128i*)v19.u8))));
	// vmulfp128 v9,v61,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v8,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vnmsubfp v5,v17,v11,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v17.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// vaddfp128 v59,v41,v47
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v47.f32)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vmulfp128 v7,v13,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v6,v61,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vaddfp128 v58,v41,v38
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v38.f32)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// vaddfp128 v60,v45,v38
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v38.f32)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// vaddfp128 v56,v39,v46
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v46.f32)));
	// addi r28,r1,224
	r28.s64 = ctx.r1.s64 + 224;
	// vaddfp128 v54,v39,v37
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v37.f32)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vaddfp128 v55,v43,v37
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v37.f32)));
	// addi r29,r1,256
	r29.s64 = ctx.r1.s64 + 256;
	// vaddfp128 v57,v43,v46
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v46.f32)));
	// addi r27,r1,272
	r27.s64 = ctx.r1.s64 + 272;
	// vcmpeqfp128 v4,v35,v62
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v3,v35,v35
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// addi r26,r1,128
	r26.s64 = ctx.r1.s64 + 128;
	// vmaddfp v1,v5,v9,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r25,r1,144
	r25.s64 = ctx.r1.s64 + 144;
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// vnmsubfp v2,v8,v7,v12
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// li r10,2
	ctx.r10.s64 = 2;
	// stvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v0,v3,v15,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)v15.u8))));
	// vmulfp128 v63,v51,v1
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vmulfp128 v31,v0,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v30,v61,v0
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v29,v2,v6,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmsum3fp128 v34,v63,v36
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v33,v63,v59
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vnmsubfp v28,v10,v31,v12
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v32,v63,v60
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v61,v63,v58
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmulfp128 v62,v42,v29
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v29.f32)));
	// vmsum3fp128 v51,v63,v57
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v50,v63,v56
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmsum3fp128 v49,v63,v55
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v48,v63,v54
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmaddfp v27,v28,v30,v0
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmsum3fp128 v47,v62,v36
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v46,v62,v59
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v45,v62,v60
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v44,v62,v58
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmsum3fp128 v43,v62,v57
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v42,v62,v56
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmsum3fp128 v41,v62,v55
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v40,v62,v54
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmulfp128 v0,v52,v27
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v27.f32)));
	// vmsum3fp128 v39,v0,v36
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// stvx128 v0,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v38,v0,v59
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v37,v0,v60
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v36,v0,v58
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmsum3fp128 v35,v0,v57
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v60,v0,v56
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmsum3fp128 v59,v0,v55
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v58,v0,v54
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v57,v34,v39
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v56,v33,v38
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v55,v32,v37
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v54,v61,v36
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v52,v51,v35
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v51,v50,v60
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vmrghw128 v50,v49,v59
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// vmrghw128 v49,v48,v58
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// vmrghw128 v48,v46,v56
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// vmrghw128 v46,v45,v55
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v45,v47,v57
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v44,v44,v54
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v43,v43,v52
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v42,v42,v51
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v61,v57,v45
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v41,v41,v50
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v40,v40,v49
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v39,v56,v48
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v38,v55,v46
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v37,v54,v44
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v36,v52,v43
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v35,v51,v42
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v34,v50,v41
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v33,v49,v40
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// lfs f10,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
loc_8249B9D8:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// bge cr6,0x8249b9e8
	if (!cr6.lt) goto loc_8249B9E8;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_8249B9E8:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x8249b9f8
	if (!cr6.lt) goto loc_8249B9F8;
	// fmr f6,f13
	ctx.f6.f64 = ctx.f13.f64;
loc_8249B9F8:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249ba08
	if (!cr6.lt) goto loc_8249BA08;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_8249BA08:
	// fcmpu cr6,f12,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f7.f64);
	// ble cr6,0x8249ba14
	if (!cr6.gt) goto loc_8249BA14;
	// fmr f7,f12
	ctx.f7.f64 = ctx.f12.f64;
loc_8249BA14:
	// fcmpu cr6,f13,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8249ba20
	if (!cr6.gt) goto loc_8249BA20;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8249BA20:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x8249ba2c
	if (!cr6.gt) goto loc_8249BA2C;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_8249BA2C:
	// lfs f12,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// bge cr6,0x8249ba3c
	if (!cr6.lt) goto loc_8249BA3C;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_8249BA3C:
	// lfs f13,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x8249ba4c
	if (!cr6.lt) goto loc_8249BA4C;
	// fmr f6,f13
	ctx.f6.f64 = ctx.f13.f64;
loc_8249BA4C:
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249ba5c
	if (!cr6.lt) goto loc_8249BA5C;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_8249BA5C:
	// fcmpu cr6,f12,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f7.f64);
	// ble cr6,0x8249ba68
	if (!cr6.gt) goto loc_8249BA68;
	// fmr f7,f12
	ctx.f7.f64 = ctx.f12.f64;
loc_8249BA68:
	// fcmpu cr6,f13,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8249ba74
	if (!cr6.gt) goto loc_8249BA74;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8249BA74:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x8249ba80
	if (!cr6.gt) goto loc_8249BA80;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_8249BA80:
	// lfs f12,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// bge cr6,0x8249ba90
	if (!cr6.lt) goto loc_8249BA90;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_8249BA90:
	// lfs f13,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x8249baa0
	if (!cr6.lt) goto loc_8249BAA0;
	// fmr f6,f13
	ctx.f6.f64 = ctx.f13.f64;
loc_8249BAA0:
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249bab0
	if (!cr6.lt) goto loc_8249BAB0;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_8249BAB0:
	// fcmpu cr6,f12,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f7.f64);
	// ble cr6,0x8249babc
	if (!cr6.gt) goto loc_8249BABC;
	// fmr f7,f12
	ctx.f7.f64 = ctx.f12.f64;
loc_8249BABC:
	// fcmpu cr6,f13,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8249bac8
	if (!cr6.gt) goto loc_8249BAC8;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8249BAC8:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x8249bad4
	if (!cr6.gt) goto loc_8249BAD4;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_8249BAD4:
	// lfs f12,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// bge cr6,0x8249bae4
	if (!cr6.lt) goto loc_8249BAE4;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
loc_8249BAE4:
	// lfs f13,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// bge cr6,0x8249baf4
	if (!cr6.lt) goto loc_8249BAF4;
	// fmr f6,f13
	ctx.f6.f64 = ctx.f13.f64;
loc_8249BAF4:
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249bb04
	if (!cr6.lt) goto loc_8249BB04;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_8249BB04:
	// fcmpu cr6,f12,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f7.f64);
	// ble cr6,0x8249bb10
	if (!cr6.gt) goto loc_8249BB10;
	// fmr f7,f12
	ctx.f7.f64 = ctx.f12.f64;
loc_8249BB10:
	// fcmpu cr6,f13,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8249bb1c
	if (!cr6.gt) goto loc_8249BB1C;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8249BB1C:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x8249bb28
	if (!cr6.gt) goto loc_8249BB28;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_8249BB28:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8249b9d8
	if (!cr0.eq) goto loc_8249B9D8;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f10,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f7,128(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// vmrghw128 v32,v62,v53
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// vmrghw128 v61,v63,v0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stfs f7,224(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// vmrglw128 v60,v62,v53
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stfs f6,228(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// vmrglw128 v59,v63,v0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stfs f8,232(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// vmrghw128 v58,v61,v32
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// stfs f6,148(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vmrglw128 v57,v61,v32
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v59,v60
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v49,v50,v13
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f28,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r4,-31280
	ctx.r4.s64 = ctx.r4.s64 + -31280;
	// lvlx128 v51,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// vsubfp128 v48,v52,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v13.f32)));
	// fmuls f10,f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v54,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v13.f32)));
	// fmadds f8,f0,f0,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// stvx128 v48,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v12,v11,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f11,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,64(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f5,f12,f12,f8
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// vmsum3fp128 v47,v10,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v46,v10,v58
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmsum3fp128 v45,v10,v57
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// fsqrts f2,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = double(float(sqrt(ctx.f5.f64)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v45,v44
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v9,v44,v43
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// fmuls f7,f0,f0
	ctx.f7.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f31,f2,f9
	f31.f64 = double(float(ctx.f2.f64 * ctx.f9.f64));
	// fmadds f4,f13,f13,f7
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f13,f31,f28
	ctx.f13.f64 = double(float(f31.f64 * f28.f64));
	// fmadds f1,f11,f11,f4
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fsqrts f12,f1
	ctx.f12.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmuls f6,f0,f0
	ctx.f6.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f3,f0,f0,f6
	ctx.f3.f64 = double(float(f0.f64 * f0.f64 + ctx.f6.f64));
	// fmadds f0,f10,f10,f3
	f0.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f3.f64));
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsqrts f10,f0
	ctx.f10.f64 = double(float(sqrt(f0.f64)));
	// lvlx128 v42,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v42,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vmaddfp v7,v0,v8,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v7,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f30,f12,f28
	ctx.fpscr.disableFlushModeUnconditional();
	f30.f64 = double(float(ctx.f12.f64 * f28.f64));
	// fmuls f29,f10,f28
	f29.f64 = double(float(ctx.f10.f64 * f28.f64));
	// bl 0x8217c088
	ctx.lr = 0x8249BCA0;
	sub_8217C088(ctx, base);
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v40,v127,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v40,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x8249BCC0;
	sub_8217CE80(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f6,f31
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f31.f64;
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fneg f3,f29
	ctx.f3.u64 = f29.u64 ^ 0x8000000000000000;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f5.f64 = double(temp.f32);
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x8217cc80
	ctx.lr = 0x8249BCE4;
	sub_8217CC80(ctx, base);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dd7c4
	ctx.lr = 0x8249BCF0;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba1c
	ctx.lr = 0x8249BCF8;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8249BCFC"))) PPC_WEAK_FUNC(sub_8249BCFC);
PPC_FUNC_IMPL(__imp__sub_8249BCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249BD00"))) PPC_WEAK_FUNC(sub_8249BD00);
PPC_FUNC_IMPL(__imp__sub_8249BD00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8249BD08;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r3,12
	ctx.r3.s64 = 12;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// addi r29,r31,192
	r29.s64 = r31.s64 + 192;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x8217f768
	ctx.lr = 0x8249BD40;
	sub_8217F768(ctx, base);
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8217f768
	ctx.lr = 0x8249BD4C;
	sub_8217F768(ctx, base);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lwz r6,1252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1252);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,-26876(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, r11.u32);
	// lwz r3,-25232(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249BD8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,1248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// cmplwi cr6,r9,1344
	cr6.compare<uint32_t>(ctx.r9.u32, 1344, xer);
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// bgt cr6,0x8249bdbc
	if (cr6.gt) goto loc_8249BDBC;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178370
	ctx.lr = 0x8249BDBC;
	sub_82178370(ctx, base);
loc_8249BDBC:
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// vor128 v56,v127,v127
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// addi r8,r9,2528
	ctx.r8.s64 = ctx.r9.s64 + 2528;
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r3,2240
	ctx.r9.s64 = ctx.r3.s64 + 2240;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r7,-31648
	ctx.r5.s64 = ctx.r7.s64 + -31648;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// lvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,1232
	r28.s64 = 1232;
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r31,1184
	r30.s64 = r31.s64 + 1184;
	// lfs f31,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r7,1200
	ctx.r7.s64 = 1200;
	// lfs f0,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r6,1216
	ctx.r6.s64 = 1216;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r26,-32122
	r26.s64 = -2105147392;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v55,v63,99
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vmsum3fp128 v58,v59,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vpermwi128 v8,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stvx128 v56,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v49,v59,v59
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// lis r28,-32256
	r28.s64 = -2113929216;
	// addi r3,r26,2288
	ctx.r3.s64 = r26.s64 + 2288;
	// vmsum3fp128 v48,v49,v49
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// lfs f13,14196(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14196);
	ctx.f13.f64 = double(temp.f32);
	// vrsqrtefp128 v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vrsqrtefp128 v47,v48
	simde_mm_store_ps(v47.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v48.f32))));
	// vor128 v26,v48,v48
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vcmpeqfp128 v10,v57,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vor128 v24,v47,v47
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vsel v0,v9,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v61,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v12,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v54,v59,v4
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v53,v54,135
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x78));
	// vsubfp128 v52,v60,v54
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v54.f32)));
	// vpermwi128 v51,v54,99
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x9C));
	// vmulfp128 v3,v53,v55
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v55.f32)));
	// vor128 v2,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vor128 v1,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// stvx128 v52,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v31,v1,v8,v3
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v50,v31,135
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v31.u32), 0x78));
	// stvx128 v31,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v30,v31,99
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v31.u32), 0x9C));
	// vmulfp128 v29,v50,v51
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// vnmsubfp v28,v30,v2,v29
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v28,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r0,r9
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v25,v47,v62
	simde_mm_store_ps(v25.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v62.f32)));
	// vsel v0,v24,v27,v25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)v24.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vmulfp128 v23,v0,v0
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v22,v63,v0
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v21,v26,v23,v13
	simde_mm_store_ps(v21.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v23.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v20,v21,v22,v0
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v21.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v49,v20
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v20.f32)));
	// stvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f12,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f0,f8
	ctx.f7.f64 = double(float(f0.f64 * ctx.f8.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f6,f12,f11,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fmadds f5,f10,f9,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fsubs f0,f30,f4
	f0.f64 = double(float(f30.f64 - ctx.f4.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249bf64
	if (!cr6.lt) goto loc_8249BF64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f13,-18920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18920);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8249bf64
	if (!cr6.gt) goto loc_8249BF64;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r9,-31632
	ctx.r7.s64 = ctx.r9.s64 + -31632;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249BF64:
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// lvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v42,v45,v45
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
	// vsubfp128 v43,v45,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vsubfp128 v41,v42,v43
	simde_mm_store_ps(v41.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8249BF98;
	sub_82202EC0(ctx, base);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f3,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f2,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8249b548
	ctx.lr = 0x8249BFB4;
	sub_8249B548(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c658
	ctx.lr = 0x8249BFC0;
	sub_8217C658(ctx, base);
	// lwz r3,-26876(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// li r28,16
	r28.s64 = 16;
	// addi r11,r3,384
	r11.s64 = ctx.r3.s64 + 384;
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lvx128 v39,r11,r28
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r29
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r11,r30
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c568
	ctx.lr = 0x8249C008;
	sub_8217C568(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v36,r0,r3
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v35,r3,r28
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v34,r3,r29
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v33,r3,r30
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// stvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v34,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x8249C04C;
	sub_8215E000(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r4,r11,20624
	ctx.r4.s64 = r11.s64 + 20624;
	// lwz r11,20688(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20688);
	// clrlwi r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8249c0c0
	if (!cr6.eq) goto loc_8249C0C0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f31,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f31,8(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stfs f31,12(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f31,16(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// stfs f31,24(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// stw r11,20688(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20688, r11.u32);
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,31492(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31492);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f13,20(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// stfs f31,28(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// stfs f31,32(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 32, temp.u32);
	// stfs f31,36(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// stfs f30,40(r4)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
	// stfs f31,44(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 44, temp.u32);
	// stfs f0,48(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 48, temp.u32);
	// stfs f0,52(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 52, temp.u32);
	// stfs f31,56(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 56, temp.u32);
	// stfs f31,60(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 60, temp.u32);
loc_8249C0C0:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v32,r0,r31
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r31,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r31,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x8249C0FC;
	sub_8215E000(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8249C11C"))) PPC_WEAK_FUNC(sub_8249C11C);
PPC_FUNC_IMPL(__imp__sub_8249C11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C120"))) PPC_WEAK_FUNC(sub_8249C120);
PPC_FUNC_IMPL(__imp__sub_8249C120) {
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
	ctx.lr = 0x8249C128;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,2828(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// beq cr6,0x8249c15c
	if (cr6.eq) goto loc_8249C15C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C154;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x8249c164
	goto loc_8249C164;
loc_8249C15C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,20592(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20592);
loc_8249C164:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c04b0
	ctx.lr = 0x8249C180;
	sub_821C04B0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249C188"))) PPC_WEAK_FUNC(sub_8249C188);
PPC_FUNC_IMPL(__imp__sub_8249C188) {
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
	ctx.lr = 0x8249C190;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x8249C1B0;
	sub_821BFC50(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249c1e0
	if (cr6.eq) goto loc_8249C1E0;
	// lwz r30,2828(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249c1d8
	if (cr6.eq) goto loc_8249C1D8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c0688
	ctx.lr = 0x8249C1D0;
	sub_821C0688(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8249C1D8;
	sub_82130588(ctx, base);
loc_8249C1D8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_8249C1E0:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249c200
	if (cr6.eq) goto loc_8249C200;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C200;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249C200:
	// addi r3,r29,192
	ctx.r3.s64 = r29.s64 + 192;
	// bl 0x8217cb48
	ctx.lr = 0x8249C208;
	sub_8217CB48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x8249C210;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249C218"))) PPC_WEAK_FUNC(sub_8249C218);
PPC_FUNC_IMPL(__imp__sub_8249C218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lfs f5,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-740(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -740);
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

__attribute__((alias("__imp__sub_8249C244"))) PPC_WEAK_FUNC(sub_8249C244);
PPC_FUNC_IMPL(__imp__sub_8249C244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C248"))) PPC_WEAK_FUNC(sub_8249C248);
PPC_FUNC_IMPL(__imp__sub_8249C248) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20592);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249C254"))) PPC_WEAK_FUNC(sub_8249C254);
PPC_FUNC_IMPL(__imp__sub_8249C254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C258"))) PPC_WEAK_FUNC(sub_8249C258);
PPC_FUNC_IMPL(__imp__sub_8249C258) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20592
	r31.s64 = r11.s64 + 20592;
	// lwz r11,20592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20592);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249c3ac
	if (!cr6.eq) goto loc_8249C3AC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8249C288;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249c298
	if (cr6.eq) goto loc_8249C298;
	// bl 0x821d5408
	ctx.lr = 0x8249C294;
	sub_821D5408(ctx, base);
	// b 0x8249c29c
	goto loc_8249C29C;
loc_8249C298:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8249C29C:
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// addi r5,r8,124
	ctx.r5.s64 = ctx.r8.s64 + 124;
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r7,1312
	ctx.r7.s64 = 1312;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r10,r4,13428
	ctx.r10.s64 = ctx.r4.s64 + 13428;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,64
	r11.s64 = 64;
	// addi r7,r3,13452
	ctx.r7.s64 = ctx.r3.s64 + 13452;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// addi r6,r9,13476
	ctx.r6.s64 = ctx.r9.s64 + 13476;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// li r10,76
	ctx.r10.s64 = 76;
	// addi r5,r8,13500
	ctx.r5.s64 = ctx.r8.s64 + 13500;
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r9,80
	ctx.r9.s64 = 80;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// lis r30,-32128
	r30.s64 = -2105540608;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r7,r4,13524
	ctx.r7.s64 = ctx.r4.s64 + 13524;
	// li r11,68
	r11.s64 = 68;
	// addi r6,r8,13548
	ctx.r6.s64 = ctx.r8.s64 + 13548;
	// addi r4,r30,13572
	ctx.r4.s64 = r30.s64 + 13572;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r9,84
	ctx.r9.s64 = 84;
	// li r11,1260
	r11.s64 = 1260;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x8249C358;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8249C368;
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
	ctx.lr = 0x8249C384;
	sub_821D41D0(ctx, base);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,13596
	ctx.r4.s64 = ctx.r8.s64 + 13596;
	// bl 0x821d4b00
	ctx.lr = 0x8249C394;
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
	ctx.lr = 0x8249C3AC;
	sub_821C0548(ctx, base);
loc_8249C3AC:
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

__attribute__((alias("__imp__sub_8249C3C4"))) PPC_WEAK_FUNC(sub_8249C3C4);
PPC_FUNC_IMPL(__imp__sub_8249C3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C3C8"))) PPC_WEAK_FUNC(sub_8249C3C8);
PPC_FUNC_IMPL(__imp__sub_8249C3C8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8249C3D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lfs f13,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// addi r6,r7,112
	ctx.r6.s64 = ctx.r7.s64 + 112;
	// lfs f12,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-32032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	ctx.f11.f64 = double(temp.f32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stfs f13,64(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f12,80(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f11,84(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// bl 0x8217d5e8
	ctx.lr = 0x8249C428;
	sub_8217D5E8(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r4,256
	ctx.r4.s64 = 256;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// stw r30,1252(r31)
	PPC_STORE_U32(r31.u32 + 1252, r30.u32);
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// stw r4,1248(r31)
	PPC_STORE_U32(r31.u32 + 1248, ctx.r4.u32);
	// stb r30,1260(r31)
	PPC_STORE_U8(r31.u32 + 1260, r30.u8);
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// stfs f0,1272(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1272, temp.u32);
	// stfs f0,1276(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1276, temp.u32);
	// stw r3,1280(r31)
	PPC_STORE_U32(r31.u32 + 1280, ctx.r3.u32);
	// stw r30,1284(r31)
	PPC_STORE_U32(r31.u32 + 1284, r30.u32);
	// stw r30,1288(r31)
	PPC_STORE_U32(r31.u32 + 1288, r30.u32);
	// stb r30,1292(r31)
	PPC_STORE_U8(r31.u32 + 1292, r30.u8);
	// stb r30,1293(r31)
	PPC_STORE_U8(r31.u32 + 1293, r30.u8);
	// stb r30,1294(r31)
	PPC_STORE_U8(r31.u32 + 1294, r30.u8);
	// stb r11,1295(r31)
	PPC_STORE_U8(r31.u32 + 1295, r11.u8);
	// stb r11,1296(r31)
	PPC_STORE_U8(r31.u32 + 1296, r11.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// lwz r11,2828(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249c4b0
	if (!cr6.eq) goto loc_8249C4B0;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8249C494;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8249c4ac
	if (cr6.eq) goto loc_8249C4AC;
	// bl 0x821c0580
	ctx.lr = 0x8249C4A4;
	sub_821C0580(ctx, base);
	// stw r28,2828(r29)
	PPC_STORE_U32(r29.u32 + 2828, r28.u32);
	// b 0x8249c4b0
	goto loc_8249C4B0;
loc_8249C4AC:
	// stw r30,2828(r29)
	PPC_STORE_U32(r29.u32 + 2828, r30.u32);
loc_8249C4B0:
	// bl 0x821c4210
	ctx.lr = 0x8249C4B4;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,2828(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2828);
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
	ctx.lr = 0x8249C4D8;
	sub_821C05E8(ctx, base);
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249c514
	if (cr6.eq) goto loc_8249C514;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,-19840
	ctx.r4.s64 = ctx.r10.s64 + -19840;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x8249C4FC;
	sub_821CA540(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,144
	ctx.r4.s64 = ctx.r9.s64 + 144;
	// bl 0x8249c120
	ctx.lr = 0x8249C50C;
	sub_8249C120(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8249C514;
	sub_821C9A90(ctx, base);
loc_8249C514:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,14056
	ctx.r4.s64 = r11.s64 + 14056;
	// bl 0x8249b280
	ctx.lr = 0x8249C524;
	sub_8249B280(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249C530"))) PPC_WEAK_FUNC(sub_8249C530);
PPC_FUNC_IMPL(__imp__sub_8249C530) {
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
	// bl 0x8249c188
	ctx.lr = 0x8249C550;
	sub_8249C188(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249c568
	if (cr6.eq) goto loc_8249C568;
	// bl 0x82130588
	ctx.lr = 0x8249C564;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8249C568:
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

__attribute__((alias("__imp__sub_8249C580"))) PPC_WEAK_FUNC(sub_8249C580);
PPC_FUNC_IMPL(__imp__sub_8249C580) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r8,303(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 303);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x8249c5ec
	if (cr6.lt) goto loc_8249C5EC;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249C5B0:
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 + ctx.f1.f64));
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fadds f1,f8,f10
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// bne 0x8249c5b0
	if (!cr0.eq) goto loc_8249C5B0;
loc_8249C5EC:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r10,212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_8249C604:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 + ctx.f1.f64));
	// bne 0x8249c604
	if (!cr0.eq) goto loc_8249C604;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249C620"))) PPC_WEAK_FUNC(sub_8249C620);
PPC_FUNC_IMPL(__imp__sub_8249C620) {
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
	ctx.lr = 0x8249C628;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lbz r10,301(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 301);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8249c6b8
	if (!cr6.gt) goto loc_8249C6B8;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// rlwinm r8,r9,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r6,r7,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// rlwinm r4,r5,24,8,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r11,r3,16,16,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF;
	// or r11,r11,r3
	r11.u64 = r11.u64 | ctx.r3.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8249C67C;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8249C688;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r5,300(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// lwz r4,256(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// bl 0x823da950
	ctx.lr = 0x8249C69C;
	sub_823DA950(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lbz r5,300(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// lwz r4,260(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// bl 0x823da950
	ctx.lr = 0x8249C6AC;
	sub_823DA950(ctx, base);
	// stw r28,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r28.u32);
	// stw r27,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r27.u32);
	// stb r29,301(r31)
	PPC_STORE_U8(r31.u32 + 301, r29.u8);
loc_8249C6B8:
	// stb r30,300(r31)
	PPC_STORE_U8(r31.u32 + 300, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249C6C4"))) PPC_WEAK_FUNC(sub_8249C6C4);
PPC_FUNC_IMPL(__imp__sub_8249C6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C6C8"))) PPC_WEAK_FUNC(sub_8249C6C8);
PPC_FUNC_IMPL(__imp__sub_8249C6C8) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C6F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,305(r31)
	PPC_STORE_U8(r31.u32 + 305, ctx.r3.u8);
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

__attribute__((alias("__imp__sub_8249C70C"))) PPC_WEAK_FUNC(sub_8249C70C);
PPC_FUNC_IMPL(__imp__sub_8249C70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C710"))) PPC_WEAK_FUNC(sub_8249C710);
PPC_FUNC_IMPL(__imp__sub_8249C710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C73C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 316, temp.u32);
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

__attribute__((alias("__imp__sub_8249C754"))) PPC_WEAK_FUNC(sub_8249C754);
PPC_FUNC_IMPL(__imp__sub_8249C754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C758"))) PPC_WEAK_FUNC(sub_8249C758);
PPC_FUNC_IMPL(__imp__sub_8249C758) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,309(r31)
	PPC_STORE_U8(r31.u32 + 309, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8249C7A8"))) PPC_WEAK_FUNC(sub_8249C7A8);
PPC_FUNC_IMPL(__imp__sub_8249C7A8) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249c7e8
	if (cr6.eq) goto loc_8249C7E8;
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// b 0x8249c7f4
	goto loc_8249C7F4;
loc_8249C7E8:
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_8249C7F4:
	// stb r10,307(r31)
	PPC_STORE_U8(r31.u32 + 307, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8249C80C"))) PPC_WEAK_FUNC(sub_8249C80C);
PPC_FUNC_IMPL(__imp__sub_8249C80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C810"))) PPC_WEAK_FUNC(sub_8249C810);
PPC_FUNC_IMPL(__imp__sub_8249C810) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C83C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249c850
	if (cr6.eq) goto loc_8249C850;
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// b 0x8249c85c
	goto loc_8249C85C;
loc_8249C850:
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_8249C85C:
	// stb r10,307(r31)
	PPC_STORE_U8(r31.u32 + 307, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8249C874"))) PPC_WEAK_FUNC(sub_8249C874);
PPC_FUNC_IMPL(__imp__sub_8249C874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C878"))) PPC_WEAK_FUNC(sub_8249C878);
PPC_FUNC_IMPL(__imp__sub_8249C878) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C8A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249c8b8
	if (cr6.eq) goto loc_8249C8B8;
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// b 0x8249c8c4
	goto loc_8249C8C4;
loc_8249C8B8:
	// lbz r11,307(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
loc_8249C8C4:
	// stb r10,307(r31)
	PPC_STORE_U8(r31.u32 + 307, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8249C8DC"))) PPC_WEAK_FUNC(sub_8249C8DC);
PPC_FUNC_IMPL(__imp__sub_8249C8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C8E0"))) PPC_WEAK_FUNC(sub_8249C8E0);
PPC_FUNC_IMPL(__imp__sub_8249C8E0) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,311(r31)
	PPC_STORE_U8(r31.u32 + 311, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8249C930"))) PPC_WEAK_FUNC(sub_8249C930);
PPC_FUNC_IMPL(__imp__sub_8249C930) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C95C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8249C974"))) PPC_WEAK_FUNC(sub_8249C974);
PPC_FUNC_IMPL(__imp__sub_8249C974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C978"))) PPC_WEAK_FUNC(sub_8249C978);
PPC_FUNC_IMPL(__imp__sub_8249C978) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C9A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,296(r31)
	PPC_STORE_U32(r31.u32 + 296, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8249C9BC"))) PPC_WEAK_FUNC(sub_8249C9BC);
PPC_FUNC_IMPL(__imp__sub_8249C9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249C9C0"))) PPC_WEAK_FUNC(sub_8249C9C0);
PPC_FUNC_IMPL(__imp__sub_8249C9C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,64
	ctx.r4.s64 = ctx.r3.s64 + 64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249C9E0"))) PPC_WEAK_FUNC(sub_8249C9E0);
PPC_FUNC_IMPL(__imp__sub_8249C9E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249CA0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 320, temp.u32);
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

__attribute__((alias("__imp__sub_8249CA24"))) PPC_WEAK_FUNC(sub_8249CA24);
PPC_FUNC_IMPL(__imp__sub_8249CA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249CA28"))) PPC_WEAK_FUNC(sub_8249CA28);
PPC_FUNC_IMPL(__imp__sub_8249CA28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,80
	ctx.r4.s64 = ctx.r3.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CA48"))) PPC_WEAK_FUNC(sub_8249CA48);
PPC_FUNC_IMPL(__imp__sub_8249CA48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,96
	ctx.r4.s64 = ctx.r3.s64 + 96;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CA68"))) PPC_WEAK_FUNC(sub_8249CA68);
PPC_FUNC_IMPL(__imp__sub_8249CA68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,112
	ctx.r4.s64 = ctx.r3.s64 + 112;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CA88"))) PPC_WEAK_FUNC(sub_8249CA88);
PPC_FUNC_IMPL(__imp__sub_8249CA88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,128
	ctx.r4.s64 = ctx.r3.s64 + 128;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CAA8"))) PPC_WEAK_FUNC(sub_8249CAA8);
PPC_FUNC_IMPL(__imp__sub_8249CAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,144
	ctx.r4.s64 = ctx.r3.s64 + 144;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CAC8"))) PPC_WEAK_FUNC(sub_8249CAC8);
PPC_FUNC_IMPL(__imp__sub_8249CAC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r3,160
	ctx.r4.s64 = ctx.r3.s64 + 160;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CAE8"))) PPC_WEAK_FUNC(sub_8249CAE8);
PPC_FUNC_IMPL(__imp__sub_8249CAE8) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249CB14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249c620
	ctx.lr = 0x8249CB20;
	sub_8249C620(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249c620
	ctx.lr = 0x8249CB2C;
	sub_8249C620(ctx, base);
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

__attribute__((alias("__imp__sub_8249CB40"))) PPC_WEAK_FUNC(sub_8249CB40);
PPC_FUNC_IMPL(__imp__sub_8249CB40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249CB6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
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

__attribute__((alias("__imp__sub_8249CB84"))) PPC_WEAK_FUNC(sub_8249CB84);
PPC_FUNC_IMPL(__imp__sub_8249CB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249CB88"))) PPC_WEAK_FUNC(sub_8249CB88);
PPC_FUNC_IMPL(__imp__sub_8249CB88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,80
	r11.s64 = 80;
	// li r7,96
	ctx.r7.s64 = 96;
	// li r8,112
	ctx.r8.s64 = 112;
	// li r9,128
	ctx.r9.s64 = 128;
	// li r10,144
	ctx.r10.s64 = 144;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,160
	r11.s64 = 160;
	// stvx128 v63,r4,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,176
	ctx.r6.s64 = 176;
	// lvx128 v62,r3,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r3,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r4,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249CBE0"))) PPC_WEAK_FUNC(sub_8249CBE0);
PPC_FUNC_IMPL(__imp__sub_8249CBE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 72);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CBF0"))) PPC_WEAK_FUNC(sub_8249CBF0);
PPC_FUNC_IMPL(__imp__sub_8249CBF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CC00"))) PPC_WEAK_FUNC(sub_8249CC00);
PPC_FUNC_IMPL(__imp__sub_8249CC00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,68(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 68);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CC10"))) PPC_WEAK_FUNC(sub_8249CC10);
PPC_FUNC_IMPL(__imp__sub_8249CC10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 84);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249CC20"))) PPC_WEAK_FUNC(sub_8249CC20);
PPC_FUNC_IMPL(__imp__sub_8249CC20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249cc50
	if (cr6.eq) goto loc_8249CC50;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249cc50
	if (cr6.eq) goto loc_8249CC50;
	// lfs f0,176(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249cc54
	if (!cr6.eq) goto loc_8249CC54;
loc_8249CC50:
	// li r11,0
	r11.s64 = 0;
loc_8249CC54:
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249cc88
	if (cr6.eq) goto loc_8249CC88;
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249cc88
	if (cr6.eq) goto loc_8249CC88;
	// lfs f0,180(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,196(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249cc8c
	if (!cr6.eq) goto loc_8249CC8C;
loc_8249CC88:
	// li r11,0
	r11.s64 = 0;
loc_8249CC8C:
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249ccc0
	if (cr6.eq) goto loc_8249CCC0;
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249ccc0
	if (cr6.eq) goto loc_8249CCC0;
	// lfs f0,184(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,200(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249ccc4
	if (!cr6.eq) goto loc_8249CCC4;
loc_8249CCC0:
	// li r11,0
	r11.s64 = 0;
loc_8249CCC4:
	// stb r11,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r11.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249ccf8
	if (cr6.eq) goto loc_8249CCF8;
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249ccf8
	if (cr6.eq) goto loc_8249CCF8;
	// lfs f0,144(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,160(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249ccfc
	if (!cr6.eq) goto loc_8249CCFC;
loc_8249CCF8:
	// li r11,0
	r11.s64 = 0;
loc_8249CCFC:
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r11.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249cd30
	if (cr6.eq) goto loc_8249CD30;
	// rlwinm r11,r11,0,23,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249cd30
	if (cr6.eq) goto loc_8249CD30;
	// lfs f0,148(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249cd34
	if (!cr6.eq) goto loc_8249CD34;
loc_8249CD30:
	// li r11,0
	r11.s64 = 0;
loc_8249CD34:
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r11.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249cd68
	if (cr6.eq) goto loc_8249CD68;
	// rlwinm r11,r11,0,22,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249cd68
	if (cr6.eq) goto loc_8249CD68;
	// lfs f0,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,168(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249cd6c
	if (!cr6.eq) goto loc_8249CD6C;
loc_8249CD68:
	// li r11,0
	r11.s64 = 0;
loc_8249CD6C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249cdc0
	if (!cr6.eq) goto loc_8249CDC0;
	// lbz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249cdc0
	if (!cr6.eq) goto loc_8249CDC0;
	// lbz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249cdc0
	if (!cr6.eq) goto loc_8249CDC0;
	// lbz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249cdc0
	if (!cr6.eq) goto loc_8249CDC0;
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249cdc0
	if (!cr6.eq) goto loc_8249CDC0;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8249cdc4
	if (cr6.eq) goto loc_8249CDC4;
loc_8249CDC0:
	// li r11,1
	r11.s64 = 1;
loc_8249CDC4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249CDCC"))) PPC_WEAK_FUNC(sub_8249CDCC);
PPC_FUNC_IMPL(__imp__sub_8249CDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249CDD0"))) PPC_WEAK_FUNC(sub_8249CDD0);
PPC_FUNC_IMPL(__imp__sub_8249CDD0) {
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
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249ce00
	if (!cr6.eq) goto loc_8249CE00;
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
loc_8249CE00:
	// lwz r5,208(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,212(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// addi r8,r1,81
	ctx.r8.s64 = ctx.r1.s64 + 81;
	// addi r7,r1,82
	ctx.r7.s64 = ctx.r1.s64 + 82;
	// addi r6,r1,83
	ctx.r6.s64 = ctx.r1.s64 + 83;
	// lwzx r11,r5,r4
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,85
	ctx.r4.s64 = ctx.r1.s64 + 85;
	// lbz r11,70(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 70);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// lhz r11,14(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// mulli r11,r3,224
	r11.s64 = ctx.r3.s64 * 224;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8249cc20
	ctx.lr = 0x8249CE4C;
	sub_8249CC20(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249CE5C"))) PPC_WEAK_FUNC(sub_8249CE5C);
PPC_FUNC_IMPL(__imp__sub_8249CE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249CE60"))) PPC_WEAK_FUNC(sub_8249CE60);
PPC_FUNC_IMPL(__imp__sub_8249CE60) {
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
	PPCRegister f29{};
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
	// bl 0x823d91ec
	ctx.lr = 0x8249CE68;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d088
	if (cr6.eq) goto loc_8249D088;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d088
	if (cr6.eq) goto loc_8249D088;
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r1,83
	ctx.r9.s64 = ctx.r1.s64 + 83;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,85
	ctx.r7.s64 = ctx.r1.s64 + 85;
	// addi r6,r1,81
	ctx.r6.s64 = ctx.r1.s64 + 81;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8249cc20
	ctx.lr = 0x8249CECC;
	sub_8249CC20(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d084
	if (cr6.eq) goto loc_8249D084;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r6,81(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// cntlzw r4,r6
	ctx.r4.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// xori r9,r3,1
	ctx.r9.u64 = ctx.r3.u64 ^ 1;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8249cf60
	if (!cr6.eq) goto loc_8249CF60;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8249cf48
	if (cr6.eq) goto loc_8249CF48;
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8249cfa0
	goto loc_8249CFA0;
loc_8249CF48:
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8249cf9c
	if (cr6.eq) goto loc_8249CF9C;
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f0,4(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x8249cfa4
	goto loc_8249CFA4;
loc_8249CF60:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8249cfa4
	if (!cr6.eq) goto loc_8249CFA4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// bne cr6,0x8249cf84
	if (!cr6.eq) goto loc_8249CF84;
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8249cfa0
	goto loc_8249CFA0;
loc_8249CF84:
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8249cf9c
	if (!cr6.eq) goto loc_8249CF9C;
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f0,4(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x8249cfa4
	goto loc_8249CFA4;
loc_8249CF9C:
	// stfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
loc_8249CFA0:
	// stfs f31,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
loc_8249CFA4:
	// lfs f2,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// bne cr6,0x8249cfc4
	if (!cr6.eq) goto loc_8249CFC4;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x8249cfc4
	if (!cr6.eq) goto loc_8249CFC4;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x8249cfcc
	goto loc_8249CFCC;
loc_8249CFC4:
	// bl 0x823dcdd8
	ctx.lr = 0x8249CFC8;
	sub_823DCDD8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
loc_8249CFCC:
	// lfs f2,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// bne cr6,0x8249cfec
	if (!cr6.eq) goto loc_8249CFEC;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x8249cfec
	if (!cr6.eq) goto loc_8249CFEC;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// b 0x8249cff4
	goto loc_8249CFF4;
loc_8249CFEC:
	// bl 0x823dcdd8
	ctx.lr = 0x8249CFF0;
	sub_823DCDD8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
loc_8249CFF4:
	// lfs f2,20(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,24(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// bne cr6,0x8249d014
	if (!cr6.eq) goto loc_8249D014;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x8249d014
	if (!cr6.eq) goto loc_8249D014;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8249d01c
	goto loc_8249D01C;
loc_8249D014:
	// bl 0x823dcdd8
	ctx.lr = 0x8249D018;
	sub_823DCDD8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
loc_8249D01C:
	// li r10,176
	ctx.r10.s64 = 176;
	// fneg f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f30.u64 ^ 0x8000000000000000;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r7,192
	ctx.r7.s64 = 192;
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// subf r9,r29,r27
	ctx.r9.s64 = r27.s64 - r29.s64;
	// lvx128 v62,r28,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,3
	ctx.r10.s64 = 3;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r28,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v60,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v59,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249D060:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfsx f13,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8249d078
	if (!cr6.eq) goto loc_8249D078;
	// stfsx f31,r9,r11
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, temp.u32);
	// stfs f31,0(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_8249D078:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8249d060
	if (!cr0.eq) goto loc_8249D060;
loc_8249D084:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_8249D088:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8249D09C"))) PPC_WEAK_FUNC(sub_8249D09C);
PPC_FUNC_IMPL(__imp__sub_8249D09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249D0A0"))) PPC_WEAK_FUNC(sub_8249D0A0);
PPC_FUNC_IMPL(__imp__sub_8249D0A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d0bc
	if (cr6.eq) goto loc_8249D0BC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lwz r11,192(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	// b 0x8249d0dc
	goto loc_8249D0DC;
loc_8249D0BC:
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r10,212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,70(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwz r5,144(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 144);
	// lwz r11,192(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 192);
loc_8249D0DC:
	// addi r10,r11,32
	ctx.r10.s64 = r11.s64 + 32;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v1,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	// vsubfp128 v60,v62,v63
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f13,-32032(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	f0.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f7.f64 = double(temp.f32);
	// fdivs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f8.f64));
	// fdivs f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 / f0.f64));
	// fdivs f0,f9,f11
	f0.f64 = double(float(ctx.f9.f64 / ctx.f11.f64));
	// fcmpu cr6,f6,f13
	cr6.compare(ctx.f6.f64, ctx.f13.f64);
	// bge cr6,0x8249d1d8
	if (!cr6.lt) goto loc_8249D1D8;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d1a0
	if (!cr6.lt) goto loc_8249D1A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d158
	if (!cr6.lt) goto loc_8249D158;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8249d188
	goto loc_8249D188;
loc_8249D158:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d170
	if (!cr6.lt) goto loc_8249D170;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8249d188
	goto loc_8249D188;
loc_8249D170:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r3,4
	ctx.r3.s64 = 4;
	// lfs f13,-6176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8249d188
	if (cr6.lt) goto loc_8249D188;
	// li r3,6
	ctx.r3.s64 = 6;
loc_8249D188:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// blr 
	return;
loc_8249D1A0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,25088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 25088);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8249d1b8
	if (!cr6.lt) goto loc_8249D1B8;
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8249D1B8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,27532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27532);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8249d1d0
	if (!cr6.lt) goto loc_8249D1D0;
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
loc_8249D1D0:
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
loc_8249D1D8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d1f0
	if (!cr6.lt) goto loc_8249D1F0;
	// li r3,11
	ctx.r3.s64 = 11;
	// blr 
	return;
loc_8249D1F0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-6176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d238
	if (!cr6.lt) goto loc_8249D238;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,25088(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 25088);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8249d218
	if (!cr6.lt) goto loc_8249D218;
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
loc_8249D218:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,27532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27532);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8249d230
	if (!cr6.lt) goto loc_8249D230;
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
loc_8249D230:
	// li r3,14
	ctx.r3.s64 = 14;
	// blr 
	return;
loc_8249D238:
	// li r3,15
	ctx.r3.s64 = 15;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249D240"))) PPC_WEAK_FUNC(sub_8249D240);
PPC_FUNC_IMPL(__imp__sub_8249D240) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8249D248;
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249d7ac
	if (cr6.eq) goto loc_8249D7AC;
	// lbz r22,302(r3)
	r22.u64 = PPC_LOAD_U8(ctx.r3.u32 + 302);
	// rotlwi r11,r22,2
	r11.u64 = __builtin_rotateleft32(r22.u32, 2);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8249D26C;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r24,1
	r24.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8249d300
	if (!cr6.gt) goto loc_8249D300;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lwz r8,208(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// subf r8,r30,r8
	ctx.r8.s64 = ctx.r8.s64 - r30.s64;
	// lfs f13,-31400(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31400);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8249D2A8:
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lfs f12,56(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fsel f9,f10,f12,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : ctx.f11.f64;
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// blt cr6,0x8249d2e8
	if (cr6.lt) goto loc_8249D2E8;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d2ec
	if (cr6.eq) goto loc_8249D2EC;
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r6,r11,29,3,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r7,r6,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// and r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 & ctx.r9.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8249d2ec
	if (cr6.eq) goto loc_8249D2EC;
loc_8249D2E8:
	// stfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8249D2EC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// blt cr6,0x8249d2a8
	if (cr6.lt) goto loc_8249D2A8;
loc_8249D300:
	// li r28,0
	r28.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// cmpwi cr6,r22,4
	cr6.compare<int32_t>(r22.s32, 4, xer);
	// blt cr6,0x8249d5fc
	if (cr6.lt) goto loc_8249D5FC;
	// subfic r23,r30,4
	xer.ca = r30.u32 <= 4;
	r23.s64 = 4 - r30.s64;
	// addi r25,r22,-3
	r25.s64 = r22.s64 + -3;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r29,8
	r29.s64 = 8;
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// subfic r27,r30,-8
	xer.ca = r30.u32 <= 4294967288;
	r27.s64 = -8 - r30.s64;
loc_8249D32C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d34c
	if (cr6.eq) goto loc_8249D34C;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r9,r26,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249d3d4
	if (!cr6.eq) goto loc_8249D3D4;
loc_8249D34C:
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// add r10,r9,r27
	ctx.r10.u64 = ctx.r9.u64 + r27.u64;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lbz r10,69(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 69);
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// beq cr6,0x8249d3d4
	if (cr6.eq) goto loc_8249D3D4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d38c
	if (cr6.eq) goto loc_8249D38C;
	// lwz r21,0(r5)
	r21.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r20,r10,29,3,29
	r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r19,r10,27
	r19.u64 = ctx.r10.u32 & 0x1F;
	// slw r19,r24,r19
	r19.u64 = r19.u8 & 0x20 ? 0 : (r24.u32 << (r19.u8 & 0x3F));
	// lwzx r21,r20,r21
	r21.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// and r21,r19,r21
	r21.u64 = r19.u64 & r21.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8249d3d4
	if (!cr6.eq) goto loc_8249D3D4;
loc_8249D38C:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d3b4
	if (!cr6.lt) goto loc_8249D3B4;
	// stfs f0,-8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D3B4:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8249d3d4
	if (!cr6.lt) goto loc_8249D3D4;
	// stfsx f0,r10,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D3D4:
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d3fc
	if (cr6.eq) goto loc_8249D3FC;
	// addi r10,r6,-1
	ctx.r10.s64 = ctx.r6.s64 + -1;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r8,r10,29,3,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// and r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 & ctx.r7.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8249d488
	if (!cr6.eq) goto loc_8249D488;
loc_8249D3FC:
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// add r10,r9,r27
	ctx.r10.u64 = ctx.r9.u64 + r27.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r10,69(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 69);
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// beq cr6,0x8249d488
	if (cr6.eq) goto loc_8249D488;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d440
	if (cr6.eq) goto loc_8249D440;
	// lwz r21,0(r5)
	r21.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r20,r10,29,3,29
	r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r19,r10,27
	r19.u64 = ctx.r10.u32 & 0x1F;
	// slw r19,r24,r19
	r19.u64 = r19.u8 & 0x20 ? 0 : (r24.u32 << (r19.u8 & 0x3F));
	// lwzx r21,r20,r21
	r21.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// and r21,r19,r21
	r21.u64 = r19.u64 & r21.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8249d488
	if (!cr6.eq) goto loc_8249D488;
loc_8249D440:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d468
	if (!cr6.lt) goto loc_8249D468;
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D468:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8249d488
	if (!cr6.lt) goto loc_8249D488;
	// stfsx f0,r10,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D488:
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d4ac
	if (cr6.eq) goto loc_8249D4AC;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r9,r6,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249d530
	if (!cr6.eq) goto loc_8249D530;
loc_8249D4AC:
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// lbz r10,69(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 69);
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// beq cr6,0x8249d530
	if (cr6.eq) goto loc_8249D530;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d4e8
	if (cr6.eq) goto loc_8249D4E8;
	// lwz r21,0(r5)
	r21.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r20,r10,29,3,29
	r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r19,r10,27
	r19.u64 = ctx.r10.u32 & 0x1F;
	// slw r19,r24,r19
	r19.u64 = r19.u8 & 0x20 ? 0 : (r24.u32 << (r19.u8 & 0x3F));
	// lwzx r21,r20,r21
	r21.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// and r21,r19,r21
	r21.u64 = r19.u64 & r21.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8249d530
	if (!cr6.eq) goto loc_8249D530;
loc_8249D4E8:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d510
	if (!cr6.lt) goto loc_8249D510;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D510:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8249d530
	if (!cr6.lt) goto loc_8249D530;
	// stfsx f0,r10,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D530:
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d558
	if (cr6.eq) goto loc_8249D558;
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r8,r10,29,3,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// and r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 & ctx.r7.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8249d5e0
	if (!cr6.eq) goto loc_8249D5E0;
loc_8249D558:
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// add r10,r9,r23
	ctx.r10.u64 = ctx.r9.u64 + r23.u64;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lbz r10,69(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 69);
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// beq cr6,0x8249d5e0
	if (cr6.eq) goto loc_8249D5E0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d598
	if (cr6.eq) goto loc_8249D598;
	// lwz r21,0(r5)
	r21.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r20,r10,29,3,29
	r20.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r19,r10,27
	r19.u64 = ctx.r10.u32 & 0x1F;
	// slw r19,r24,r19
	r19.u64 = r19.u8 & 0x20 ? 0 : (r24.u32 << (r19.u8 & 0x3F));
	// lwzx r21,r20,r21
	r21.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// and r21,r19,r21
	r21.u64 = r19.u64 & r21.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8249d5e0
	if (!cr6.eq) goto loc_8249D5E0;
loc_8249D598:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d5c0
	if (!cr6.lt) goto loc_8249D5C0;
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D5C0:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfsx f12,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8249d5e0
	if (!cr6.lt) goto loc_8249D5E0;
	// stfsx f0,r10,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D5E0:
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpw cr6,r26,r25
	cr6.compare<int32_t>(r26.s32, r25.s32, xer);
	// blt cr6,0x8249d32c
	if (cr6.lt) goto loc_8249D32C;
loc_8249D5FC:
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// bge cr6,0x8249d6c0
	if (!cr6.lt) goto loc_8249D6C0;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249D608:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d628
	if (cr6.eq) goto loc_8249D628;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r9,r26,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 29) & 0x1FFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8249d6ac
	if (!cr6.eq) goto loc_8249D6AC;
loc_8249D628:
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r11,69(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 69);
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x8249d6ac
	if (cr6.eq) goto loc_8249D6AC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249d664
	if (cr6.eq) goto loc_8249D664;
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r29,r11,29,3,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r27,r11,27
	r27.u64 = r11.u32 & 0x1F;
	// slw r27,r24,r27
	r27.u64 = r27.u8 & 0x20 ? 0 : (r24.u32 << (r27.u8 & 0x3F));
	// lwzx r6,r29,r6
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + ctx.r6.u32);
	// and r6,r27,r6
	ctx.r6.u64 = r27.u64 & ctx.r6.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8249d6ac
	if (!cr6.eq) goto loc_8249D6AC;
loc_8249D664:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lfsx f12,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8249d68c
	if (!cr6.lt) goto loc_8249D68C;
	// stfsx f0,r10,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D68C:
	// lfsx f0,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfsx f12,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8249d6ac
	if (!cr6.lt) goto loc_8249D6AC;
	// stfsx f0,r11,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + r30.u32, temp.u32);
	// mr r28,r24
	r28.u64 = r24.u64;
loc_8249D6AC:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r26,r22
	cr6.compare<int32_t>(r26.s32, r22.s32, xer);
	// blt cr6,0x8249d608
	if (cr6.lt) goto loc_8249D608;
loc_8249D6C0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249d300
	if (!cr6.eq) goto loc_8249D300;
	// lbz r28,303(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 303);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,4
	cr6.compare<int32_t>(r28.s32, 4, xer);
	// blt cr6,0x8249d778
	if (cr6.lt) goto loc_8249D778;
	// addi r11,r28,-4
	r11.s64 = r28.s64 + -4;
	// subfic r6,r4,4
	xer.ca = ctx.r4.u32 <= 4;
	ctx.r6.s64 = 4 - ctx.r4.s64;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r11,r4,8
	r11.s64 = ctx.r4.s64 + 8;
	// subfic r5,r4,-8
	xer.ca = ctx.r4.u32 <= 4294967288;
	ctx.r5.s64 = -8 - ctx.r4.s64;
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249D6FC:
	// lwz r7,212(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// add r8,r5,r11
	ctx.r8.u64 = ctx.r5.u64 + r11.u64;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r7,r7,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lbz r7,12(r7)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lfsx f0,r7,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,-8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// lwz r7,212(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lbz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lfsx f13,r7,r30
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// lwz r8,212(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lbz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lfsx f12,r7,r30
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r8,212(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lbz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lfsx f11,r7,r30
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8249d6fc
	if (!cr0.eq) goto loc_8249D6FC;
loc_8249D778:
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// bge cr6,0x8249d7ac
	if (!cr6.lt) goto loc_8249D7AC;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r29,r28
	ctx.r10.s64 = r28.s64 - r29.s64;
loc_8249D788:
	// lwz r9,212(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lbz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12);
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lfsx f0,r6,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r11,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8249d788
	if (!cr0.eq) goto loc_8249D788;
loc_8249D7AC:
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8249D7B4"))) PPC_WEAK_FUNC(sub_8249D7B4);
PPC_FUNC_IMPL(__imp__sub_8249D7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249D7B8"))) PPC_WEAK_FUNC(sub_8249D7B8);
PPC_FUNC_IMPL(__imp__sub_8249D7B8) {
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
	ctx.lr = 0x8249D7C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r25,-1
	r25.s64 = -1;
	// lbz r11,302(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 302);
	// li r26,-1
	r26.s64 = -1;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d870
	if (cr6.eq) goto loc_8249D870;
	// li r30,0
	r30.s64 = 0;
loc_8249D7F0:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r3,r11,84
	ctx.r3.s64 = r11.s64 + 84;
	// bl 0x823db730
	ctx.lr = 0x8249D804;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249d814
	if (!cr6.eq) goto loc_8249D814;
	// mr r25,r29
	r25.u64 = r29.u64;
	// b 0x8249d834
	goto loc_8249D834;
loc_8249D814:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r3,r11,84
	ctx.r3.s64 = r11.s64 + 84;
	// bl 0x823db730
	ctx.lr = 0x8249D828;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249d834
	if (!cr6.eq) goto loc_8249D834;
	// mr r26,r29
	r26.u64 = r29.u64;
loc_8249D834:
	// lbz r11,302(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 302);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8249d7f0
	if (cr6.lt) goto loc_8249D7F0;
	// cmpwi cr6,r25,-1
	cr6.compare<int32_t>(r25.s32, -1, xer);
	// beq cr6,0x8249d870
	if (cr6.eq) goto loc_8249D870;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x8249d870
	if (cr6.eq) goto loc_8249D870;
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// stbx r25,r11,r24
	PPC_STORE_U8(r11.u32 + r24.u32, r25.u8);
	// lwz r8,260(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// stbx r26,r8,r24
	PPC_STORE_U8(ctx.r8.u32 + r24.u32, r26.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8249D870:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r11,496
	ctx.r3.s64 = r11.s64 + 496;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x8249D884;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8249D88C"))) PPC_WEAK_FUNC(sub_8249D88C);
PPC_FUNC_IMPL(__imp__sub_8249D88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249D890"))) PPC_WEAK_FUNC(sub_8249D890);
PPC_FUNC_IMPL(__imp__sub_8249D890) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// li r5,63
	ctx.r5.s64 = 63;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x823d9890
	ctx.lr = 0x8249D8C4;
	sub_823D9890(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8249D8E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,19620(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 19620);
	// addi r3,r11,956
	ctx.r3.s64 = r11.s64 + 956;
	// lwz r7,968(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 968);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8249D8FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,308(r31)
	PPC_STORE_U8(r31.u32 + 308, ctx.r3.u8);
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

__attribute__((alias("__imp__sub_8249D918"))) PPC_WEAK_FUNC(sub_8249D918);
PPC_FUNC_IMPL(__imp__sub_8249D918) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,255
	ctx.r5.s64 = 255;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824da360
	ctx.lr = 0x8249D944;
	sub_824DA360(ctx, base);
	// stw r3,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8249D95C"))) PPC_WEAK_FUNC(sub_8249D95C);
PPC_FUNC_IMPL(__imp__sub_8249D95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249D960"))) PPC_WEAK_FUNC(sub_8249D960);
PPC_FUNC_IMPL(__imp__sub_8249D960) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249d98c
	if (cr6.eq) goto loc_8249D98C;
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
loc_8249D98C:
	// li r10,255
	ctx.r10.s64 = 255;
	// lwz r9,212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r8,r31,303
	ctx.r8.s64 = r31.s64 + 303;
	// lwz r7,208(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r6,r31,302
	ctx.r6.s64 = r31.s64 + 302;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x824d1030
	ctx.lr = 0x8249D9AC;
	sub_824D1030(ctx, base);
	// lbz r11,304(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 304);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r11,304(r31)
	PPC_STORE_U8(r31.u32 + 304, r11.u8);
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

__attribute__((alias("__imp__sub_8249D9CC"))) PPC_WEAK_FUNC(sub_8249D9CC);
PPC_FUNC_IMPL(__imp__sub_8249D9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249D9D0"))) PPC_WEAK_FUNC(sub_8249D9D0);
PPC_FUNC_IMPL(__imp__sub_8249D9D0) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249DA08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8249DA24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r4,300(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stb r7,300(r31)
	PPC_STORE_U8(r31.u32 + 300, ctx.r7.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249d7b8
	ctx.lr = 0x8249DA40;
	sub_8249D7B8(ctx, base);
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

__attribute__((alias("__imp__sub_8249DA58"))) PPC_WEAK_FUNC(sub_8249DA58);
PPC_FUNC_IMPL(__imp__sub_8249DA58) {
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
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249DA84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,310(r31)
	PPC_STORE_U8(r31.u32 + 310, ctx.r3.u8);
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

__attribute__((alias("__imp__sub_8249DA9C"))) PPC_WEAK_FUNC(sub_8249DA9C);
PPC_FUNC_IMPL(__imp__sub_8249DA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249DAA0"))) PPC_WEAK_FUNC(sub_8249DAA0);
PPC_FUNC_IMPL(__imp__sub_8249DAA0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8249DAA8;
	// clrlwi r29,r5,24
	r29.u64 = ctx.r5.u32 & 0xFF;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// ble cr6,0x8249dba8
	if (!cr6.gt) goto loc_8249DBA8;
loc_8249DABC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8249db9c
	if (cr6.eq) goto loc_8249DB9C;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8249DAC8:
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// bge cr6,0x8249daf0
	if (!cr6.lt) goto loc_8249DAF0;
	// lbz r11,69(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 69);
	// addi r10,r11,-255
	ctx.r10.s64 = r11.s64 + -255;
	// cntlzw r11,r10
	r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x8249db00
	goto loc_8249DB00;
loc_8249DAF0:
	// lbz r10,69(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 69);
	// subf r11,r10,r30
	r11.s64 = r30.s64 - ctx.r10.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8249DB00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249db88
	if (cr6.eq) goto loc_8249DB88;
	// rlwinm r11,r8,2,22,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// stbx r8,r5,r7
	PPC_STORE_U8(ctx.r5.u32 + ctx.r7.u32, ctx.r8.u8);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r31,r8,24
	r31.u64 = ctx.r8.u32 & 0xFF;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// stwx r10,r11,r4
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, ctx.r10.u32);
	// li r11,-1
	r11.s64 = -1;
	// beq cr6,0x8249db30
	if (cr6.eq) goto loc_8249DB30;
	// lbzx r11,r30,r7
	r11.u64 = PPC_LOAD_U8(r30.u32 + ctx.r7.u32);
loc_8249DB30:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r28,r1,-304
	r28.s64 = ctx.r1.s64 + -304;
	// lbz r27,70(r10)
	r27.u64 = PPC_LOAD_U8(ctx.r10.u32 + 70);
	// stbx r11,r31,r28
	PPC_STORE_U8(r31.u32 + r28.u32, r11.u8);
	// cmplwi cr6,r27,255
	cr6.compare<uint32_t>(r27.u32, 255, xer);
	// beq cr6,0x8249db80
	if (cr6.eq) goto loc_8249DB80;
	// lbz r28,71(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 71);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8249db80
	if (cr6.eq) goto loc_8249DB80;
loc_8249DB58:
	// lbz r10,70(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 70);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// stb r8,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r8.u8);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r28,71(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 71);
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// blt cr6,0x8249db58
	if (cr6.lt) goto loc_8249DB58;
loc_8249DB80:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
loc_8249DB88:
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x8249dac8
	if (cr6.lt) goto loc_8249DAC8;
loc_8249DB9C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x8249dabc
	if (cr6.lt) goto loc_8249DABC;
loc_8249DBA8:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8249dc04
	if (!cr6.gt) goto loc_8249DC04;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r8,255
	ctx.r8.s64 = 255;
loc_8249DBBC:
	// addi r10,r1,-304
	ctx.r10.s64 = ctx.r1.s64 + -304;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stb r5,69(r6)
	PPC_STORE_U8(ctx.r6.u32 + 69, ctx.r5.u8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lbz r3,72(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249dbf0
	if (cr6.eq) goto loc_8249DBF0;
	// lbz r6,68(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 68);
	// lbzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// stb r5,68(r10)
	PPC_STORE_U8(ctx.r10.u32 + 68, ctx.r5.u8);
	// b 0x8249dbf4
	goto loc_8249DBF4;
loc_8249DBF0:
	// stb r8,68(r10)
	PPC_STORE_U8(ctx.r10.u32 + 68, ctx.r8.u8);
loc_8249DBF4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// blt cr6,0x8249dbbc
	if (cr6.lt) goto loc_8249DBBC;
loc_8249DC04:
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249DC08"))) PPC_WEAK_FUNC(sub_8249DC08);
PPC_FUNC_IMPL(__imp__sub_8249DC08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,303(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 303);
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x8249dc70
	if (cr6.lt) goto loc_8249DC70;
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249DC34:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 + ctx.f1.f64));
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fadds f1,f8,f10
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// bne 0x8249dc34
	if (!cr0.eq) goto loc_8249DC34;
loc_8249DC70:
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x8249dc94
	if (!cr6.lt) goto loc_8249DC94;
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
loc_8249DC7C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 + ctx.f1.f64));
	// bne 0x8249dc7c
	if (!cr0.eq) goto loc_8249DC7C;
loc_8249DC94:
	// lwz r3,228(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 228);
	// b 0x8258e688
	sub_8258E688(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8249DC9C"))) PPC_WEAK_FUNC(sub_8249DC9C);
PPC_FUNC_IMPL(__imp__sub_8249DC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249DCA0"))) PPC_WEAK_FUNC(sub_8249DCA0);
PPC_FUNC_IMPL(__imp__sub_8249DCA0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8249DCA8;
	// stfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f29.u64);
	// stfd f30,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lbz r10,303(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 303);
	// lbz r11,303(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 303);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8249dce0
	if (!cr6.eq) goto loc_8249DCE0;
	// lbz r11,302(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 302);
	// lbz r10,302(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 302);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8249dcf0
	if (cr6.eq) goto loc_8249DCF0;
loc_8249DCE0:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r4,176(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// addi r3,r11,696
	ctx.r3.s64 = r11.s64 + 696;
	// bl 0x82130000
	ctx.lr = 0x8249DCF0;
	sub_82130000(ctx, base);
loc_8249DCF0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,302(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 302);
	// li r20,0
	r20.s64 = 0;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8249df18
	if (cr6.eq) goto loc_8249DF18;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r21,0
	r21.s64 = 0;
	// addi r18,r11,600
	r18.s64 = r11.s64 + 600;
	// addi r19,r10,536
	r19.s64 = ctx.r10.s64 + 536;
loc_8249DD20:
	// lwz r11,208(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r29,0
	r29.s64 = 0;
	// lwzx r26,r21,r11
	r26.u64 = PPC_LOAD_U32(r21.u32 + r11.u32);
	// addi r24,r26,84
	r24.s64 = r26.s64 + 84;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82183870
	ctx.lr = 0x8249DD40;
	sub_82183870(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8249DD48:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8249dd48
	if (!cr6.eq) goto loc_8249DD48;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subf r30,r20,r22
	r30.s64 = r22.s64 - r20.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r27,0
	r27.s64 = 0;
	// rotlwi r25,r11,0
	r25.u64 = __builtin_rotateleft32(r11.u32, 0);
loc_8249DD6C:
	// lbz r11,302(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 302);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bge cr6,0x8249dfec
	if (!cr6.lt) goto loc_8249DFEC;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8249dd84
	if (cr6.lt) goto loc_8249DD84;
	// li r30,0
	r30.s64 = 0;
loc_8249DD84:
	// lwz r11,208(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// rlwinm r31,r30,2,0,29
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r4,r11,84
	ctx.r4.s64 = r11.s64 + 84;
	// bl 0x82183870
	ctx.lr = 0x8249DDA0;
	sub_82183870(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8249DDA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8249dda8
	if (!cr6.eq) goto loc_8249DDA8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// blt cr6,0x8249ddd0
	if (cr6.lt) goto loc_8249DDD0;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8249DDD0:
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823dd800
	ctx.lr = 0x8249DDE0;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249ddf0
	if (!cr6.eq) goto loc_8249DDF0;
	// lwz r11,208(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// lwzx r29,r31,r11
	r29.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
loc_8249DDF0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8249dd6c
	if (cr6.eq) goto loc_8249DD6C;
loc_8249DE00:
	// lbz r6,71(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 71);
	// lbz r7,71(r26)
	ctx.r7.u64 = PPC_LOAD_U8(r26.u32 + 71);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// beq cr6,0x8249de20
	if (cr6.eq) goto loc_8249DE20;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r5,176(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82130000
	ctx.lr = 0x8249DE20;
	sub_82130000(ctx, base);
loc_8249DE20:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824d0be0
	ctx.lr = 0x8249DE2C;
	sub_824D0BE0(ctx, base);
	// lbz r11,70(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 70);
	// li r31,0
	r31.s64 = 0;
	// lbz r27,71(r26)
	r27.u64 = PPC_LOAD_U8(r26.u32 + 71);
	// lbz r26,70(r29)
	r26.u64 = PPC_LOAD_U8(r29.u32 + 70);
	// lbz r25,71(r29)
	r25.u64 = PPC_LOAD_U8(r29.u32 + 71);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8249df04
	if (!cr6.gt) goto loc_8249DF04;
	// rlwinm r30,r11,4,0,27
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249DE50:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// blt cr6,0x8249de68
	if (cr6.lt) goto loc_8249DE68;
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8249DE68:
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// lwz r9,212(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 212);
	// lwz r10,212(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lwzx r24,r8,r9
	r24.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lfs f30,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f30.f64 = double(temp.f32);
	// lfs f0,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f29,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f29.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// bl 0x824d97f0
	ctx.lr = 0x8249DE98;
	sub_824D97F0(ctx, base);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r11,240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 240);
	// lfs f13,4(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 / f30.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvlx128 v63,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,244(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 244);
	// lfs f11,8(r24)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 / f29.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v59,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8249de50
	if (cr6.lt) goto loc_8249DE50;
loc_8249DF04:
	// lbz r11,302(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 302);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// blt cr6,0x8249dd20
	if (cr6.lt) goto loc_8249DD20;
loc_8249DF18:
	// lwz r11,236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 236);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8249df44
	if (cr6.eq) goto loc_8249DF44;
	// lwz r3,228(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 228);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249DF44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249DF44:
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// addi r4,r23,80
	ctx.r4.s64 = r23.s64 + 80;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x8249DF54;
	sub_823DA950(ctx, base);
	// li r11,64
	r11.s64 = 64;
	// lwz r3,200(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lvx128 v55,r23,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r28,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 320);
	f0.f64 = double(temp.f32);
	// stfs f0,320(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 320, temp.u32);
	// beq cr6,0x8249df88
	if (cr6.eq) goto loc_8249DF88;
	// lwz r4,200(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 200);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8249df88
	if (cr6.eq) goto loc_8249DF88;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x824d97f0
	ctx.lr = 0x8249DF88;
	sub_824D97F0(ctx, base);
loc_8249DF88:
	// lfs f0,316(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 316);
	f0.f64 = double(temp.f32);
	// stfs f0,316(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 316, temp.u32);
	// lbz r11,309(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 309);
	// stb r11,309(r28)
	PPC_STORE_U8(r28.u32 + 309, r11.u8);
	// lfs f13,324(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,324(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 324, temp.u32);
	// lbz r10,311(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 311);
	// stb r10,311(r28)
	PPC_STORE_U8(r28.u32 + 311, ctx.r10.u8);
	// lwz r11,292(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 292);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249dfb8
	if (cr6.eq) goto loc_8249DFB8;
	// stw r11,292(r28)
	PPC_STORE_U32(r28.u32 + 292, r11.u32);
loc_8249DFB8:
	// lwz r11,296(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 296);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249dfc8
	if (cr6.eq) goto loc_8249DFC8;
	// stw r11,296(r28)
	PPC_STORE_U32(r28.u32 + 296, r11.u32);
loc_8249DFC8:
	// lbz r11,310(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 310);
	// stb r11,310(r28)
	PPC_STORE_U8(r28.u32 + 310, r11.u8);
	// lbz r10,307(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249e0c0
	if (cr6.eq) goto loc_8249E0C0;
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// b 0x8249e0cc
	goto loc_8249E0CC;
loc_8249DFEC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8249de00
	if (!cr6.eq) goto loc_8249DE00;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r5,176(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82130000
	ctx.lr = 0x8249E004;
	sub_82130000(ctx, base);
	// lbz r8,71(r26)
	ctx.r8.u64 = PPC_LOAD_U8(r26.u32 + 71);
	// lbz r7,70(r26)
	ctx.r7.u64 = PPC_LOAD_U8(r26.u32 + 70);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x8249e084
	if (cr6.lt) goto loc_8249E084;
	// addi r11,r8,-4
	r11.s64 = ctx.r8.s64 + -4;
	// lwz r9,212(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r6,r9
	r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8249E044:
	// lwz r5,-8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lfs f12,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fadds f31,f8,f10
	f31.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// bne 0x8249e044
	if (!cr0.eq) goto loc_8249E044;
loc_8249E084:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8249e0b8
	if (!cr6.lt) goto loc_8249E0B8;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r10,212(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_8249E0A0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// bne 0x8249e0a0
	if (!cr0.eq) goto loc_8249E0A0;
loc_8249E0B8:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// b 0x8249df04
	goto loc_8249DF04;
loc_8249E0C0:
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
loc_8249E0CC:
	// stb r10,307(r28)
	PPC_STORE_U8(r28.u32 + 307, ctx.r10.u8);
	// lbz r11,307(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249e0ec
	if (cr6.eq) goto loc_8249E0EC;
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// b 0x8249e0f8
	goto loc_8249E0F8;
loc_8249E0EC:
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_8249E0F8:
	// stb r10,307(r28)
	PPC_STORE_U8(r28.u32 + 307, ctx.r10.u8);
	// lbz r11,307(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249e118
	if (cr6.eq) goto loc_8249E118;
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// b 0x8249e124
	goto loc_8249E124;
loc_8249E118:
	// lbz r11,307(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_8249E124:
	// stb r10,307(r28)
	PPC_STORE_U8(r28.u32 + 307, ctx.r10.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r31,300(r23)
	r31.u64 = PPC_LOAD_U8(r23.u32 + 300);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8249c620
	ctx.lr = 0x8249E138;
	sub_8249C620(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8249e170
	if (!cr6.gt) goto loc_8249E170;
loc_8249E144:
	// lwz r10,256(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 256);
	// lwz r9,260(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 260);
	// lwz r8,256(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 256);
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lbzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stbx r7,r8,r11
	PPC_STORE_U8(ctx.r8.u32 + r11.u32, ctx.r7.u8);
	// lwz r5,260(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 260);
	// stbx r6,r11,r5
	PPC_STORE_U8(r11.u32 + ctx.r5.u32, ctx.r6.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// blt cr6,0x8249e144
	if (cr6.lt) goto loc_8249E144;
loc_8249E170:
	// lwz r11,268(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 268);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8249e1e8
	if (cr6.eq) goto loc_8249E1E8;
	// lwz r11,272(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 272);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8249e1dc
	if (!cr6.eq) goto loc_8249E1DC;
	// li r3,364
	ctx.r3.s64 = 364;
	// bl 0x82130528
	ctx.lr = 0x8249E190;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249e1a0
	if (cr6.eq) goto loc_8249E1A0;
	// bl 0x823d69a8
	ctx.lr = 0x8249E19C;
	sub_823D69A8(ctx, base);
	// b 0x8249e1a4
	goto loc_8249E1A4;
loc_8249E1A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8249E1A4:
	// stw r3,272(r28)
	PPC_STORE_U32(r28.u32 + 272, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x824cffd8
	ctx.lr = 0x8249E1B0;
	sub_824CFFD8(ctx, base);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8249E1B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249e1c8
	if (cr6.eq) goto loc_8249E1C8;
	// bl 0x824d6450
	ctx.lr = 0x8249E1C4;
	sub_824D6450(ctx, base);
	// b 0x8249e1cc
	goto loc_8249E1CC;
loc_8249E1C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8249E1CC:
	// stw r3,268(r28)
	PPC_STORE_U32(r28.u32 + 268, ctx.r3.u32);
	// lwz r4,268(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 268);
	// lwz r3,272(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 272);
	// bl 0x824a5490
	ctx.lr = 0x8249E1DC;
	sub_824A5490(ctx, base);
loc_8249E1DC:
	// lwz r4,268(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 268);
	// lwz r3,268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 268);
	// bl 0x824d6798
	ctx.lr = 0x8249E1E8;
	sub_824D6798(ctx, base);
loc_8249E1E8:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r4,252(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 252);
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r11,2384
	ctx.r8.s64 = r11.s64 + 2384;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v54,r23,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r23,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v52,v54,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v51,v53,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v50,v51,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// bl 0x8249d240
	ctx.lr = 0x8249E220;
	sub_8249D240(ctx, base);
	// lbz r7,302(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 302);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8249e258
	if (cr6.eq) goto loc_8249E258;
	// li r30,0
	r30.s64 = 0;
loc_8249E234:
	// lwz r11,208(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x824d0d10
	ctx.lr = 0x8249E244;
	sub_824D0D10(ctx, base);
	// lbz r10,302(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 302);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8249e234
	if (cr6.lt) goto loc_8249E234;
loc_8249E258:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8249E26C"))) PPC_WEAK_FUNC(sub_8249E26C);
PPC_FUNC_IMPL(__imp__sub_8249E26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E270"))) PPC_WEAK_FUNC(sub_8249E270);
PPC_FUNC_IMPL(__imp__sub_8249E270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r8,303(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 303);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8249E28C:
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r7,212(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 212);
	// lwz r6,208(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// lwzx r5,r7,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lbz r4,12(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 12);
	// rotlwi r7,r4,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lfs f13,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8249e2c4
	if (!cr6.lt) goto loc_8249E2C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// b 0x8249e28c
	goto loc_8249E28C;
loc_8249E2C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249E2CC"))) PPC_WEAK_FUNC(sub_8249E2CC);
PPC_FUNC_IMPL(__imp__sub_8249E2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E2D0"))) PPC_WEAK_FUNC(sub_8249E2D0);
PPC_FUNC_IMPL(__imp__sub_8249E2D0) {
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
	ctx.lr = 0x8249E2D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249e334
	if (cr6.eq) goto loc_8249E334;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8249e334
	if (cr6.eq) goto loc_8249E334;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249E30C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249e334
	if (cr6.eq) goto loc_8249E334;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249E320;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8249E334:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249E344"))) PPC_WEAK_FUNC(sub_8249E344);
PPC_FUNC_IMPL(__imp__sub_8249E344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E348"))) PPC_WEAK_FUNC(sub_8249E348);
PPC_FUNC_IMPL(__imp__sub_8249E348) {
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
	ctx.lr = 0x8249E350;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249e3b4
	if (cr6.eq) goto loc_8249E3B4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249e3b4
	if (cr6.eq) goto loc_8249E3B4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249E384;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249e3b4
	if (cr6.eq) goto loc_8249E3B4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249E398;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x8258f980
	ctx.lr = 0x8249E3AC;
	sub_8258F980(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8249E3B4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249E3C4"))) PPC_WEAK_FUNC(sub_8249E3C4);
PPC_FUNC_IMPL(__imp__sub_8249E3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E3C8"))) PPC_WEAK_FUNC(sub_8249E3C8);
PPC_FUNC_IMPL(__imp__sub_8249E3C8) {
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
	ctx.lr = 0x8249E3D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249e434
	if (cr6.eq) goto loc_8249E434;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249e434
	if (cr6.eq) goto loc_8249E434;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249E404;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249e434
	if (cr6.eq) goto loc_8249E434;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249E418;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x824d6590
	ctx.lr = 0x8249E42C;
	sub_824D6590(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8249E434:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249E444"))) PPC_WEAK_FUNC(sub_8249E444);
PPC_FUNC_IMPL(__imp__sub_8249E444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E448"))) PPC_WEAK_FUNC(sub_8249E448);
PPC_FUNC_IMPL(__imp__sub_8249E448) {
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
	ctx.lr = 0x8249E450;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249e4b4
	if (cr6.eq) goto loc_8249E4B4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249e4b4
	if (cr6.eq) goto loc_8249E4B4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249E484;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249e4b4
	if (cr6.eq) goto loc_8249E4B4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249E498;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x824a4670
	ctx.lr = 0x8249E4AC;
	sub_824A4670(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8249E4B4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8249E4C4"))) PPC_WEAK_FUNC(sub_8249E4C4);
PPC_FUNC_IMPL(__imp__sub_8249E4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E4C8"))) PPC_WEAK_FUNC(sub_8249E4C8);
PPC_FUNC_IMPL(__imp__sub_8249E4C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,920(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 920);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r3,916
	r11.s64 = ctx.r3.s64 + 916;
	// addi r8,r9,0
	ctx.r8.s64 = ctx.r9.s64 + 0;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249e50c
	if (cr6.eq) goto loc_8249E50C;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8249E50C:
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8249E520"))) PPC_WEAK_FUNC(sub_8249E520);
PPC_FUNC_IMPL(__imp__sub_8249E520) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8249E524"))) PPC_WEAK_FUNC(sub_8249E524);
PPC_FUNC_IMPL(__imp__sub_8249E524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249E528"))) PPC_WEAK_FUNC(sub_8249E528);
PPC_FUNC_IMPL(__imp__sub_8249E528) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8249E530;
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f29.u64);
	// stfd f30,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// mr r24,r26
	r24.u64 = r26.u64;
	// bne cr6,0x8249e564
	if (!cr6.eq) goto loc_8249E564;
	// lwz r24,288(r28)
	r24.u64 = PPC_LOAD_U32(r28.u32 + 288);
loc_8249E564:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,52(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,56(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,180(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// lfs f12,48(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r31,r22,48
	r31.s64 = r22.s64 + 48;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fmuls f7,f8,f8
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f6,f13,f11
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmadds f4,f6,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fmadds f0,f5,f5,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// beq cr6,0x8249e5cc
	if (cr6.eq) goto loc_8249E5CC;
	// lwz r10,104(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 104);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8249e5cc
	if (cr6.lt) goto loc_8249E5CC;
	// lwz r8,184(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
loc_8249E5CC:
	// lhz r10,220(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 220);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249e6c4
	if (cr6.eq) goto loc_8249E6C4;
	// mr r30,r26
	r30.u64 = r26.u64;
	// fsqrts f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(sqrt(f0.f64)));
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
loc_8249E5E4:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x8249e5fc
	if (cr6.gt) goto loc_8249E5FC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8249e60c
	if (!cr6.eq) goto loc_8249E60C;
loc_8249E5FC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// blt cr6,0x8249e5e4
	if (cr6.lt) goto loc_8249E5E4;
loc_8249E60C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// lwz r11,184(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 184);
	// mr r28,r26
	r28.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8249eb08
	if (!cr6.gt) goto loc_8249EB08;
	// mr r31,r26
	r31.u64 = r26.u64;
	// lis r29,-32115
	r29.s64 = -2104688640;
loc_8249E62C:
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r10,188(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 188);
	// addi r11,r11,908
	r11.s64 = r11.s64 + 908;
	// lwzx r10,r31,r10
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r8,r26,r9
	ctx.r8.s64 = ctx.r9.s64 - r26.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249e69c
	if (cr6.eq) goto loc_8249E69C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249e688
	if (cr6.eq) goto loc_8249E688;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249E684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8249e69c
	goto loc_8249E69C;
loc_8249E688:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249E69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249E69C:
	// lwz r11,184(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 184);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8249e62c
	if (cr6.lt) goto loc_8249E62C;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E6C4:
	// lwz r10,224(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 224);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8249e780
	if (cr6.eq) goto loc_8249E780;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// lwz r10,196(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// fsqrts f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f0.f64)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249e740
	if (cr6.eq) goto loc_8249E740;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// addi r11,r9,48
	r11.s64 = ctx.r9.s64 + 48;
loc_8249E6F0:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x8249e708
	if (cr6.gt) goto loc_8249E708;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8249e718
	if (!cr6.eq) goto loc_8249E718;
loc_8249E708:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// blt cr6,0x8249e6f0
	if (cr6.lt) goto loc_8249E6F0;
loc_8249E718:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lwz r3,19620(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// bl 0x8249e4c8
	ctx.lr = 0x8249E72C;
	sub_8249E4C8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E740:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r11,892
	ctx.r3.s64 = r11.s64 + 892;
	// lwz r9,904(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 904);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8249E76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E780:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r23,1
	r23.s64 = 1;
	// mr r11,r23
	r11.u64 = r23.u64;
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x8249e7a0
	if (cr6.gt) goto loc_8249E7A0;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8249E7A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249e910
	if (cr6.eq) goto loc_8249E910;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,19684(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19684);
	// lfs f7,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsubs f8,f13,f11
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f6,f9,f9
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fsubs f5,f12,f7
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmadds f4,f8,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmadds f0,f5,f5,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// beq cr6,0x8249e80c
	if (cr6.eq) goto loc_8249E80C;
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249eb08
	if (!cr6.lt) goto loc_8249EB08;
loc_8249E80C:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// fsqrts f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(sqrt(f0.f64)));
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// addi r3,r11,892
	ctx.r3.s64 = r11.s64 + 892;
	// lwz r11,904(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 904);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249E838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// lbz r11,8(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// lwz r10,196(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8249e864
	if (!cr6.eq) goto loc_8249E864;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// b 0x8249e870
	goto loc_8249E870;
loc_8249E864:
	// lwz r11,184(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_8249E870:
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249e8b4
	if (cr6.eq) goto loc_8249E8B4;
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r6,100(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 100);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// addi r3,r11,892
	ctx.r3.s64 = r11.s64 + 892;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,904(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 904);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249E8A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E8B4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f31,56(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 56);
	f31.f64 = double(temp.f32);
	// lfs f30,52(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 52);
	f30.f64 = double(temp.f32);
	// lfs f29,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f29.f64 = double(temp.f32);
	// bl 0x824896e8
	ctx.lr = 0x8249E8C8;
	sub_824896E8(ctx, base);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,776
	ctx.r3.s64 = r11.s64 + 776;
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x8249E8FC;
	sub_82130000(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E910:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8249e9dc
	if (!cr6.eq) goto loc_8249E9DC;
	// lwz r11,200(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8249e9dc
	if (cr6.eq) goto loc_8249E9DC;
	// lwz r4,144(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,19684(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19684);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f0,f5,f5,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// beq cr6,0x8249e990
	if (cr6.eq) goto loc_8249E990;
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8249eb08
	if (!cr6.lt) goto loc_8249EB08;
loc_8249E990:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsqrts f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f0.f64)));
	// beq cr6,0x8249e9a4
	if (cr6.eq) goto loc_8249E9A4;
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 + ctx.f1.f64));
loc_8249E9A4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// addi r3,r11,892
	ctx.r3.s64 = r11.s64 + 892;
	// lwz r10,904(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 904);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249E9C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8249E9DC:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// lwz r9,19684(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 19684);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f6,f13,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f3,f10,f10,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f4.f64));
	// fsqrts f31,f3
	f31.f64 = double(float(sqrt(ctx.f3.f64)));
	// beq cr6,0x8249ea30
	if (cr6.eq) goto loc_8249EA30;
	// lfs f0,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_8249EA30:
	// lbz r11,303(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 303);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249eb08
	if (cr6.eq) goto loc_8249EB08;
	// mr r31,r26
	r31.u64 = r26.u64;
	// lis r30,-32115
	r30.s64 = -2104688640;
loc_8249EA44:
	// lwz r11,212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lbz r11,12(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// beq cr6,0x8249eaa4
	if (cr6.eq) goto loc_8249EAA4;
	// lwz r8,12(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// rlwinm r7,r11,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r6,r11,27
	ctx.r6.u64 = r11.u32 & 0x1F;
	// slw r5,r23,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (r23.u32 << (ctx.r6.u8 & 0x3F));
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwzx r3,r7,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// and r8,r3,r5
	ctx.r8.u64 = ctx.r3.u64 & ctx.r5.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8249eaf4
	if (!cr6.eq) goto loc_8249EAF4;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8249eaa4
	if (cr6.eq) goto loc_8249EAA4;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8249eaa4
	if (!cr6.lt) goto loc_8249EAA4;
	// lwz r4,148(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8249eaa8
	if (!cr6.eq) goto loc_8249EAA8;
loc_8249EAA4:
	// lwz r4,144(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
loc_8249EAA8:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249eaf4
	if (cr6.eq) goto loc_8249EAF4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8249eacc
	if (cr6.eq) goto loc_8249EACC;
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// bge cr6,0x8249eaf4
	if (!cr6.lt) goto loc_8249EAF4;
loc_8249EACC:
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// addi r3,r11,892
	ctx.r3.s64 = r11.s64 + 892;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,904(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 904);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249EAF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,19684(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 19684);
loc_8249EAF4:
	// lbz r11,303(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 303);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8249ea44
	if (cr6.lt) goto loc_8249EA44;
loc_8249EB08:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8249EB1C"))) PPC_WEAK_FUNC(sub_8249EB1C);
PPC_FUNC_IMPL(__imp__sub_8249EB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249EB20"))) PPC_WEAK_FUNC(sub_8249EB20);
PPC_FUNC_IMPL(__imp__sub_8249EB20) {
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
	ctx.lr = 0x8249EB28;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-15576
	ctx.r4.s64 = r11.s64 + -15576;
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8249EB44;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249eb6c
	if (!cr6.eq) goto loc_8249EB6C;
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249EB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_8249EB6C:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8249EB74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8249eb74
	if (!cr6.eq) goto loc_8249EB74;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpwi cr6,r10,256
	cr6.compare<int32_t>(ctx.r10.s32, 256, xer);
	// rotlwi r21,r9,0
	r21.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// blt cr6,0x8249ebd8
	if (cr6.lt) goto loc_8249EBD8;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249ebbc
	if (cr6.eq) goto loc_8249EBBC;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x8249EBB0;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8249ebc0
	if (!cr6.eq) goto loc_8249EBC0;
loc_8249EBBC:
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_8249EBC0:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r3,r11,880
	ctx.r3.s64 = r11.s64 + 880;
	// bl 0x82130000
	ctx.lr = 0x8249EBD0;
	sub_82130000(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_8249EBD8:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249ec90
	if (!cr6.eq) goto loc_8249EC90;
	// bl 0x821bbea8
	ctx.lr = 0x8249EBEC;
	sub_821BBEA8(ctx, base);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x8249EBF4;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8249ec78
	if (cr6.eq) goto loc_8249EC78;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,60
	r26.s64 = 60;
	// mr r30,r24
	r30.u64 = r24.u64;
	// li r25,255
	r25.s64 = 255;
loc_8249EC10:
	// lwzx r29,r26,r27
	r29.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8249ec60
	if (cr6.eq) goto loc_8249EC60;
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8249ec60
	if (cr6.eq) goto loc_8249EC60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249EC34;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249ec60
	if (cr6.eq) goto loc_8249EC60;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249EC48;
	sub_8217D890(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwzx r4,r26,r27
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// bl 0x824d9688
	ctx.lr = 0x8249EC5C;
	sub_824D9688(ctx, base);
	// b 0x8249ec64
	goto loc_8249EC64;
loc_8249EC60:
	// stw r22,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r22.u32);
loc_8249EC64:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bge 0x8249ec10
	if (!cr0.lt) goto loc_8249EC10;
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8249ec7c
	goto loc_8249EC7C;
loc_8249EC78:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8249EC7C:
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x8249EC88;
	sub_82130528(ctx, base);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// bl 0x821bbf00
	ctx.lr = 0x8249EC90;
	sub_821BBF00(ctx, base);
loc_8249EC90:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x8249EC98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249ecac
	if (cr6.eq) goto loc_8249ECAC;
	// bl 0x824d9240
	ctx.lr = 0x8249ECA4;
	sub_824D9240(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8249ecb0
	goto loc_8249ECB0;
loc_8249ECAC:
	// mr r30,r22
	r30.u64 = r22.u64;
loc_8249ECB0:
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,68(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8249ECD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,180(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// addi r29,r21,-4
	r29.s64 = r21.s64 + -4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stw r6,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r6.u32);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x8249ECFC;
	sub_82130528(ctx, base);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r7,188(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,5
	ctx.r4.s64 = r11.s64 + 5;
	// lwzx r3,r3,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// bl 0x823db670
	ctx.lr = 0x8249ED2C;
	sub_823DB670(ctx, base);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r11,864
	ctx.r4.s64 = r11.s64 + 864;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// add r7,r11,r21
	ctx.r7.u64 = r11.u64 + r21.u64;
	// stb r22,-4(r7)
	PPC_STORE_U8(ctx.r7.u32 + -4, r22.u8);
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8249ED54;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8249ed64
	if (!cr6.eq) goto loc_8249ED64;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
loc_8249ED64:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8249ED78"))) PPC_WEAK_FUNC(sub_8249ED78);
PPC_FUNC_IMPL(__imp__sub_8249ED78) {
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
	ctx.lr = 0x8249ED80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821bee48
	ctx.lr = 0x8249ED98;
	sub_821BEE48(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249edbc
	if (cr6.eq) goto loc_8249EDBC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8249edbc
	if (!cr6.eq) goto loc_8249EDBC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r31,29964(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 29964);
loc_8249EDBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d4bb0
	ctx.lr = 0x8249EDC4;
	sub_821D4BB0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249EDE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8249EDF0"))) PPC_WEAK_FUNC(sub_8249EDF0);
PPC_FUNC_IMPL(__imp__sub_8249EDF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r10,288
	ctx.r10.s64 = 288;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lvx128 v1,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8249e528
	sub_8249E528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8249EE04"))) PPC_WEAK_FUNC(sub_8249EE04);
PPC_FUNC_IMPL(__imp__sub_8249EE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249EE08"))) PPC_WEAK_FUNC(sub_8249EE08);
PPC_FUNC_IMPL(__imp__sub_8249EE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8249EE10;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x8249EE24;
	sub_821D2970(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r10,1012
	ctx.r9.s64 = ctx.r10.s64 + 1012;
	// li r29,-1
	r29.s64 = -1;
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stfs f31,12(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// stw r30,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r30.u32);
	// addi r3,r31,224
	ctx.r3.s64 = r31.s64 + 224;
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// stw r29,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r29.u32);
	// stw r30,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r30.u32);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// sth r30,220(r31)
	PPC_STORE_U16(r31.u32 + 220, r30.u16);
	// sth r30,222(r31)
	PPC_STORE_U16(r31.u32 + 222, r30.u16);
	// bl 0x8249e2d0
	ctx.lr = 0x8249EE84;
	sub_8249E2D0(ctx, base);
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// stw r30,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r30.u32);
	// stw r30,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r30.u32);
	// stw r30,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r30.u32);
	// stw r30,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r30.u32);
	// stw r30,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r30.u32);
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// bl 0x8249e448
	ctx.lr = 0x8249EEB8;
	sub_8249E448(ctx, base);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stw r30,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r8,2256
	ctx.r6.s64 = ctx.r8.s64 + 2256;
	// stw r30,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r30.u32);
	// stw r30,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r30.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stfs f31,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 316, temp.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// li r4,48
	ctx.r4.s64 = 48;
	// stw r30,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r30.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// stb r30,300(r31)
	PPC_STORE_U8(r31.u32 + 300, r30.u8);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stb r30,301(r31)
	PPC_STORE_U8(r31.u32 + 301, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r30,302(r31)
	PPC_STORE_U8(r31.u32 + 302, r30.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r30,303(r31)
	PPC_STORE_U8(r31.u32 + 303, r30.u8);
	// stw r28,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r28.u32);
	// stb r30,304(r31)
	PPC_STORE_U8(r31.u32 + 304, r30.u8);
	// lfs f0,-11620(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11620);
	f0.f64 = double(temp.f32);
	// stb r7,305(r31)
	PPC_STORE_U8(r31.u32 + 305, ctx.r7.u8);
	// stb r30,306(r31)
	PPC_STORE_U8(r31.u32 + 306, r30.u8);
	// stb r30,307(r31)
	PPC_STORE_U8(r31.u32 + 307, r30.u8);
	// stb r30,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r30.u8);
	// stb r30,309(r31)
	PPC_STORE_U8(r31.u32 + 309, r30.u8);
	// stb r29,310(r31)
	PPC_STORE_U8(r31.u32 + 310, r29.u8);
	// stb r30,311(r31)
	PPC_STORE_U8(r31.u32 + 311, r30.u8);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,320(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 320, temp.u32);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lfs f13,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,116(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f0,136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,160(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f13,164(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f0,324(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// std r30,328(r31)
	PPC_STORE_U64(r31.u32 + 328, r30.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8249EFB4"))) PPC_WEAK_FUNC(sub_8249EFB4);
PPC_FUNC_IMPL(__imp__sub_8249EFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8249EFB8"))) PPC_WEAK_FUNC(sub_8249EFB8);
PPC_FUNC_IMPL(__imp__sub_8249EFB8) {
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
	PPCRegister f0{};
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
	// bl 0x823d91c4
	ctx.lr = 0x8249EFC0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x8249EFD0;
	sub_821D2970(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r19,0
	r19.s64 = 0;
	// addi r10,r11,1012
	ctx.r10.s64 = r11.s64 + 1012;
	// addi r3,r29,224
	ctx.r3.s64 = r29.s64 + 224;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r19,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r19.u32);
	// sth r19,220(r29)
	PPC_STORE_U16(r29.u32 + 220, r19.u16);
	// sth r19,222(r29)
	PPC_STORE_U16(r29.u32 + 222, r19.u16);
	// bl 0x8249e2d0
	ctx.lr = 0x8249EFF4;
	sub_8249E2D0(ctx, base);
	// addi r16,r29,228
	r16.s64 = r29.s64 + 228;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x8249e348
	ctx.lr = 0x8249F000;
	sub_8249E348(ctx, base);
	// addi r15,r29,232
	r15.s64 = r29.s64 + 232;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x8249e348
	ctx.lr = 0x8249F00C;
	sub_8249E348(ctx, base);
	// addi r21,r29,236
	r21.s64 = r29.s64 + 236;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821b5a60
	ctx.lr = 0x8249F018;
	sub_821B5A60(ctx, base);
	// addi r30,r29,268
	r30.s64 = r29.s64 + 268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8249e3c8
	ctx.lr = 0x8249F024;
	sub_8249E3C8(ctx, base);
	// addi r31,r29,272
	r31.s64 = r29.s64 + 272;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249e448
	ctx.lr = 0x8249F030;
	sub_8249E448(ctx, base);
	// addi r3,r29,276
	ctx.r3.s64 = r29.s64 + 276;
	// bl 0x82323eb8
	ctx.lr = 0x8249F038;
	sub_82323EB8(ctx, base);
	// addi r3,r29,280
	ctx.r3.s64 = r29.s64 + 280;
	// bl 0x82323fb8
	ctx.lr = 0x8249F040;
	sub_82323FB8(ctx, base);
	// addi r18,r29,284
	r18.s64 = r29.s64 + 284;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x82323fb8
	ctx.lr = 0x8249F04C;
	sub_82323FB8(ctx, base);
	// addi r17,r29,288
	r17.s64 = r29.s64 + 288;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82324038
	ctx.lr = 0x8249F058;
	sub_82324038(ctx, base);
	// lbz r9,305(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 305);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bge cr6,0x8249f06c
	if (!cr6.lt) goto loc_8249F06C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,305(r29)
	PPC_STORE_U8(r29.u32 + 305, r11.u8);
loc_8249F06C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249f088
	if (cr6.eq) goto loc_8249F088;
	// bl 0x824cffd8
	ctx.lr = 0x8249F07C;
	sub_824CFFD8(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824a5490
	ctx.lr = 0x8249F088;
	sub_824A5490(ctx, base);
loc_8249F088:
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f0b4
	if (cr6.eq) goto loc_8249F0B4;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249f0b4
	if (cr6.eq) goto loc_8249F0B4;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F0A8;
	sub_8217D890(ctx, base);
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,200(r29)
	PPC_STORE_U32(r29.u32 + 200, ctx.r10.u32);
loc_8249F0B4:
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// mr r25,r19
	r25.u64 = r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f0dc
	if (cr6.eq) goto loc_8249F0DC;
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8249f0dc
	if (!cr6.eq) goto loc_8249F0DC;
	// li r25,1
	r25.s64 = 1;
	// stw r19,144(r11)
	PPC_STORE_U32(r11.u32 + 144, r19.u32);
loc_8249F0DC:
	// lwz r4,180(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249f0fc
	if (cr6.eq) goto loc_8249F0FC;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F0F0;
	sub_8217D890(ctx, base);
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,180(r29)
	PPC_STORE_U32(r29.u32 + 180, ctx.r10.u32);
loc_8249F0FC:
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r31,192(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// stw r19,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r19.u32);
	// lwz r3,180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249f11c
	if (cr6.eq) goto loc_8249F11C;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x824d9538
	ctx.lr = 0x8249F11C;
	sub_824D9538(ctx, base);
loc_8249F11C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249f13c
	if (cr6.eq) goto loc_8249F13C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F130;
	sub_8217D890(ctx, base);
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// add r10,r3,r31
	ctx.r10.u64 = ctx.r3.u64 + r31.u64;
	// stw r10,192(r11)
	PPC_STORE_U32(r11.u32 + 192, ctx.r10.u32);
loc_8249F13C:
	// lwz r4,184(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249f15c
	if (cr6.eq) goto loc_8249F15C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F150;
	sub_8217D890(ctx, base);
	// lwz r11,184(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,184(r29)
	PPC_STORE_U32(r29.u32 + 184, ctx.r10.u32);
loc_8249F15C:
	// lwz r4,188(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8249f17c
	if (cr6.eq) goto loc_8249F17C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F170;
	sub_8217D890(ctx, base);
	// lwz r11,188(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,188(r29)
	PPC_STORE_U32(r29.u32 + 188, ctx.r10.u32);
loc_8249F17C:
	// lwz r10,192(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 192);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r26,r19
	r26.u64 = r19.u64;
	// addi r20,r11,-26560
	r20.s64 = r11.s64 + -26560;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8249f2b4
	if (!cr6.gt) goto loc_8249F2B4;
	// mr r28,r19
	r28.u64 = r19.u64;
loc_8249F198:
	// lwz r27,184(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// lwzx r31,r27,r28
	r31.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249f210
	if (cr6.eq) goto loc_8249F210;
	// lwz r30,0(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F1B8;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f1e0
	if (cr6.eq) goto loc_8249F1E0;
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
	// b 0x8249f1f4
	goto loc_8249F1F4;
loc_8249F1E0:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F1F0;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F1F4:
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// stwx r3,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249f210
	if (cr6.eq) goto loc_8249F210;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x824d9538
	ctx.lr = 0x8249F210;
	sub_824D9538(ctx, base);
loc_8249F210:
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r10,184(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// lwz r7,184(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// lwz r6,180(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwzx r5,r7,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// lwz r4,8(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r4,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r4.u32);
	// lwz r27,188(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// lwzx r31,r27,r28
	r31.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249f2a0
	if (cr6.eq) goto loc_8249F2A0;
	// lwz r30,0(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F258;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f280
	if (cr6.eq) goto loc_8249F280;
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
	// b 0x8249f294
	goto loc_8249F294;
loc_8249F280:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F290;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F294:
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stwx r11,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r11.u32);
loc_8249F2A0:
	// lwz r11,192(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 192);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8249f198
	if (cr6.lt) goto loc_8249F198;
loc_8249F2B4:
	// lwz r3,200(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249f2d0
	if (cr6.eq) goto loc_8249F2D0;
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824d9ed8
	ctx.lr = 0x8249F2D0;
	sub_824D9ED8(ctx, base);
loc_8249F2D0:
	// clrlwi r23,r25,24
	r23.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8249f2e8
	if (cr6.eq) goto loc_8249F2E8;
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// stw r10,144(r11)
	PPC_STORE_U32(r11.u32 + 144, ctx.r10.u32);
loc_8249F2E8:
	// lwz r31,208(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// lbz r28,302(r29)
	r28.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249f3d4
	if (cr6.eq) goto loc_8249F3D4;
	// lwz r30,0(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F308;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f330
	if (cr6.eq) goto loc_8249F330;
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
	// b 0x8249f344
	goto loc_8249F344;
loc_8249F330:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F340;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F344:
	// lwz r10,208(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,208(r29)
	PPC_STORE_U32(r29.u32 + 208, r11.u32);
	// ble cr6,0x8249f3d4
	if (!cr6.gt) goto loc_8249F3D4;
	// mr r25,r19
	r25.u64 = r19.u64;
	// mr r24,r28
	r24.u64 = r28.u64;
loc_8249F360:
	// lwz r11,208(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// add. r31,r11,r25
	r31.u64 = r11.u64 + r25.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8249f3c8
	if (cr0.eq) goto loc_8249F3C8;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249f3c4
	if (cr6.eq) goto loc_8249F3C4;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8249f3c4
	if (cr6.eq) goto loc_8249F3C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8249F398;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f3c4
	if (cr6.eq) goto loc_8249F3C4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8249F3AC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x824d0fc8
	ctx.lr = 0x8249F3C0;
	sub_824D0FC8(ctx, base);
	// b 0x8249f3c8
	goto loc_8249F3C8;
loc_8249F3C4:
	// stw r19,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r19.u32);
loc_8249F3C8:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x8249f360
	if (!cr0.eq) goto loc_8249F360;
loc_8249F3D4:
	// lwz r30,204(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249f438
	if (cr6.eq) goto loc_8249F438;
	// lwz r31,0(r22)
	r31.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F3F0;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f418
	if (cr6.eq) goto loc_8249F418;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8249f42c
	goto loc_8249F42C;
loc_8249F418:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F428;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F42C:
	// lwz r10,204(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,204(r29)
	PPC_STORE_U32(r29.u32 + 204, r11.u32);
loc_8249F438:
	// lbz r11,302(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// mr r26,r19
	r26.u64 = r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f4c8
	if (cr6.eq) goto loc_8249F4C8;
	// mr r28,r19
	r28.u64 = r19.u64;
loc_8249F44C:
	// lwz r27,204(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// lwzx r31,r27,r28
	r31.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249f4b4
	if (cr6.eq) goto loc_8249F4B4;
	// lwz r30,0(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F46C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f494
	if (cr6.eq) goto loc_8249F494;
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
	// b 0x8249f4a8
	goto loc_8249F4A8;
loc_8249F494:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F4A4;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F4A8:
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r11.u32);
loc_8249F4B4:
	// lbz r11,302(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8249f44c
	if (cr6.lt) goto loc_8249F44C;
loc_8249F4C8:
	// lbz r11,302(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r9,204(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r10,472
	ctx.r7.s64 = ctx.r10.s64 + 472;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r30,176(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249f544
	if (cr6.eq) goto loc_8249F544;
	// lwz r31,0(r22)
	r31.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F4FC;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f524
	if (cr6.eq) goto loc_8249F524;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8249f538
	goto loc_8249F538;
loc_8249F524:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F534;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F538:
	// lwz r10,176(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,176(r29)
	PPC_STORE_U32(r29.u32 + 176, r11.u32);
loc_8249F544:
	// lwz r30,212(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249f5a8
	if (cr6.eq) goto loc_8249F5A8;
	// lwz r31,0(r22)
	r31.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8249F560;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8249f588
	if (cr6.eq) goto loc_8249F588;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8249f59c
	goto loc_8249F59C;
loc_8249F588:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F598;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F59C:
	// lwz r10,212(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r11.u32);
loc_8249F5A8:
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// mr r28,r19
	r28.u64 = r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f75c
	if (cr6.eq) goto loc_8249F75C;
	// mr r31,r19
	r31.u64 = r19.u64;
loc_8249F5BC:
	// lwz r30,212(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r5,r30,r31
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249f644
	if (cr6.eq) goto loc_8249F644;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249f628
	if (!cr0.gt) goto loc_8249F628;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249F5E8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249f608
	if (cr6.lt) goto loc_8249F608;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249f60c
	if (cr6.lt) goto loc_8249F60C;
loc_8249F608:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F60C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fb90
	if (!cr6.eq) goto loc_8249FB90;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249f5e8
	if (cr6.lt) goto loc_8249F5E8;
loc_8249F628:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F634;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F638:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
loc_8249F644:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8249f688
	if (cr6.eq) goto loc_8249F688;
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stw r19,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, r19.u32);
	// lwz r9,212(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stw r19,152(r8)
	PPC_STORE_U32(ctx.r8.u32 + 152, r19.u32);
	// lwz r7,212(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// stw r19,156(r6)
	PPC_STORE_U32(ctx.r6.u32 + 156, r19.u32);
	// lwz r5,212(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r4,r5,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// stw r19,160(r4)
	PPC_STORE_U32(ctx.r4.u32 + 160, r19.u32);
	// lwz r3,212(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r11,r3,r31
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + r31.u32);
	// stw r19,164(r11)
	PPC_STORE_U32(r11.u32 + 164, r19.u32);
loc_8249F688:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249f6a8
	if (cr6.eq) goto loc_8249F6A8;
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824d9ed8
	ctx.lr = 0x8249F6A8;
	sub_824D9ED8(ctx, base);
loc_8249F6A8:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8249f710
	if (cr6.eq) goto loc_8249F710;
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stw r10,144(r9)
	PPC_STORE_U32(ctx.r9.u32 + 144, ctx.r10.u32);
	// lwz r8,212(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwz r6,200(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r5,152(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 152);
	// stw r5,152(r7)
	PPC_STORE_U32(ctx.r7.u32 + 152, ctx.r5.u32);
	// lwz r3,212(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r10,r3,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + r31.u32);
	// lwz r4,200(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// lwz r11,156(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 156);
	// stw r11,156(r10)
	PPC_STORE_U32(ctx.r10.u32 + 156, r11.u32);
	// lwz r8,212(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwz r9,200(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// lwz r6,160(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// stw r6,160(r7)
	PPC_STORE_U32(ctx.r7.u32 + 160, ctx.r6.u32);
	// lwz r5,200(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// lwz r4,212(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r3,r4,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// lwz r11,164(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 164);
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r11.u32);
loc_8249F710:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r7,144(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 144);
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lwz r6,212(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r5,r6,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// lwz r11,148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f748
	if (cr6.eq) goto loc_8249F748;
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
loc_8249F748:
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8249f5bc
	if (cr6.lt) goto loc_8249F5BC;
loc_8249F75C:
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// lis r26,-32115
	r26.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f9b8
	if (cr6.eq) goto loc_8249F9B8;
	// lwz r5,248(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 248);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249f7f0
	if (cr6.eq) goto loc_8249F7F0;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249f7d4
	if (!cr0.gt) goto loc_8249F7D4;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249F794:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249f7b4
	if (cr6.lt) goto loc_8249F7B4;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249f7b8
	if (cr6.lt) goto loc_8249F7B8;
loc_8249F7B4:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F7B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fbb8
	if (!cr6.eq) goto loc_8249FBB8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249f794
	if (cr6.lt) goto loc_8249F794;
loc_8249F7D4:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F7E0;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F7E4:
	// lwz r10,248(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 248);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,248(r29)
	PPC_STORE_U32(r29.u32 + 248, r11.u32);
loc_8249F7F0:
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// mr r28,r19
	r28.u64 = r19.u64;
	// mr r30,r19
	r30.u64 = r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249f884
	if (cr6.eq) goto loc_8249F884;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r19
	r31.u64 = r19.u64;
	// addi r27,r11,1024
	r27.s64 = r11.s64 + 1024;
loc_8249F810:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r11,192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8249f870
	if (cr6.eq) goto loc_8249F870;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8249f850
	if (!cr6.eq) goto loc_8249F850;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x8249f850
	if (!cr6.eq) goto loc_8249F850;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,176(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// li r28,1
	r28.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x8249F850;
	sub_82130000(ctx, base);
loc_8249F850:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r5,192(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// bl 0x82599f48
	ctx.lr = 0x8249F870;
	sub_82599F48(ctx, base);
loc_8249F870:
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8249f810
	if (cr6.lt) goto loc_8249F810;
loc_8249F884:
	// lwz r5,240(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 240);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249f908
	if (cr6.eq) goto loc_8249F908;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249f8ec
	if (!cr0.gt) goto loc_8249F8EC;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249F8AC:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249f8cc
	if (cr6.lt) goto loc_8249F8CC;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249f8d0
	if (cr6.lt) goto loc_8249F8D0;
loc_8249F8CC:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F8D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fbe0
	if (!cr6.eq) goto loc_8249FBE0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249f8ac
	if (cr6.lt) goto loc_8249F8AC;
loc_8249F8EC:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F8F8;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F8FC:
	// lwz r10,240(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 240);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,240(r29)
	PPC_STORE_U32(r29.u32 + 240, r11.u32);
loc_8249F908:
	// lwz r5,244(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249f98c
	if (cr6.eq) goto loc_8249F98C;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249f970
	if (!cr0.gt) goto loc_8249F970;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249F930:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249f950
	if (cr6.lt) goto loc_8249F950;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249f954
	if (cr6.lt) goto loc_8249F954;
loc_8249F950:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F954:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fc08
	if (!cr6.eq) goto loc_8249FC08;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249f930
	if (cr6.lt) goto loc_8249F930;
loc_8249F970:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249F97C;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249F980:
	// lwz r10,244(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,244(r29)
	PPC_STORE_U32(r29.u32 + 244, r11.u32);
loc_8249F98C:
	// lwz r11,19620(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 19620);
	// lwz r10,0(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lwz r9,768(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lwz r8,0(r16)
	ctx.r8.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lwz r11,19620(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 19620);
	// lwz r7,772(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// stw r7,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r7.u32);
	// lbz r6,307(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 307);
	// ori r5,r6,4
	ctx.r5.u64 = ctx.r6.u64 | 4;
	// stb r5,307(r29)
	PPC_STORE_U8(r29.u32 + 307, ctx.r5.u8);
loc_8249F9B8:
	// lwz r5,256(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249fa3c
	if (cr6.eq) goto loc_8249FA3C;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249fa20
	if (!cr0.gt) goto loc_8249FA20;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249F9E0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249fa00
	if (cr6.lt) goto loc_8249FA00;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249fa04
	if (cr6.lt) goto loc_8249FA04;
loc_8249FA00:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FA04:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fc30
	if (!cr6.eq) goto loc_8249FC30;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249f9e0
	if (cr6.lt) goto loc_8249F9E0;
loc_8249FA20:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249FA2C;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FA30:
	// lwz r10,256(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,256(r29)
	PPC_STORE_U32(r29.u32 + 256, r11.u32);
loc_8249FA3C:
	// lwz r5,260(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249fac0
	if (cr6.eq) goto loc_8249FAC0;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249faa4
	if (!cr0.gt) goto loc_8249FAA4;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249FA64:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249fa84
	if (cr6.lt) goto loc_8249FA84;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249fa88
	if (cr6.lt) goto loc_8249FA88;
loc_8249FA84:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FA88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fc58
	if (!cr6.eq) goto loc_8249FC58;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249fa64
	if (cr6.lt) goto loc_8249FA64;
loc_8249FAA4:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249FAB0;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FAB4:
	// lwz r10,260(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,260(r29)
	PPC_STORE_U32(r29.u32 + 260, r11.u32);
loc_8249FAC0:
	// lwz r5,252(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 252);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8249fb44
	if (cr6.eq) goto loc_8249FB44;
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8249fb28
	if (!cr0.gt) goto loc_8249FB28;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_8249FAE8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x8249fb08
	if (cr6.lt) goto loc_8249FB08;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8249fb0c
	if (cr6.lt) goto loc_8249FB0C;
loc_8249FB08:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FB0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8249fc80
	if (!cr6.eq) goto loc_8249FC80;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8249fae8
	if (cr6.lt) goto loc_8249FAE8;
loc_8249FB28:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821d2378
	ctx.lr = 0x8249FB34;
	sub_821D2378(ctx, base);
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FB38:
	// lwz r10,252(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 252);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,252(r29)
	PPC_STORE_U32(r29.u32 + 252, r11.u32);
loc_8249FB44:
	// lwz r4,0(r18)
	ctx.r4.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8249fcc0
	if (cr6.eq) goto loc_8249FCC0;
	// lwz r3,0(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249fcc0
	if (cr6.eq) goto loc_8249FCC0;
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r11,64(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8249fca8
	if (!cr6.eq) goto loc_8249FCA8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,112(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8249fb88
	if (cr6.gt) goto loc_8249FB88;
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8249FB88:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x8249fcb8
	goto loc_8249FCB8;
loc_8249FB90:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249f628
	if (cr6.eq) goto loc_8249F628;
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
	// b 0x8249f638
	goto loc_8249F638;
loc_8249FBB8:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249f7d4
	if (cr6.eq) goto loc_8249F7D4;
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
	// b 0x8249f7e4
	goto loc_8249F7E4;
loc_8249FBE0:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249f8ec
	if (cr6.eq) goto loc_8249F8EC;
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
	// b 0x8249f8fc
	goto loc_8249F8FC;
loc_8249FC08:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249f970
	if (cr6.eq) goto loc_8249F970;
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
	// b 0x8249f980
	goto loc_8249F980;
loc_8249FC30:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249fa20
	if (cr6.eq) goto loc_8249FA20;
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
	// b 0x8249fa30
	goto loc_8249FA30;
loc_8249FC58:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249faa4
	if (cr6.eq) goto loc_8249FAA4;
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
	// b 0x8249fab4
	goto loc_8249FAB4;
loc_8249FC80:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8249fb28
	if (cr6.eq) goto loc_8249FB28;
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
	// b 0x8249fb38
	goto loc_8249FB38;
loc_8249FCA8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r9,21(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 21);
	// clrlwi r5,r9,31
	ctx.r5.u64 = ctx.r9.u32 & 0x1;
loc_8249FCB8:
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821a1848
	ctx.lr = 0x8249FCC0;
	sub_821A1848(ctx, base);
loc_8249FCC0:
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// li r4,80
	ctx.r4.s64 = 80;
	// li r6,96
	ctx.r6.s64 = 96;
	// li r7,112
	ctx.r7.s64 = 112;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r9,144
	ctx.r9.s64 = 144;
	// li r10,160
	ctx.r10.s64 = 160;
	// li r5,176
	ctx.r5.s64 = 176;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fd18
	if (cr6.eq) goto loc_8249FD18;
	// lvx128 v63,r29,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r29,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r29,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r29,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r29,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249FD18:
	// lwz r11,0(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fd54
	if (cr6.eq) goto loc_8249FD54;
	// lvx128 v57,r29,r4
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r29,r6
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r29,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r29,r8
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r29,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r29,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249FD54:
	// lwz r11,0(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8249fd68
	if (cr6.eq) goto loc_8249FD68;
	// lfs f0,324(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 324);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
loc_8249FD68:
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8249fd7c
	if (cr6.eq) goto loc_8249FD7C;
	// lfs f0,324(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 324);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
loc_8249FD7C:
	// lwz r3,176(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249fd9c
	if (cr6.eq) goto loc_8249FD9C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x8249FD90;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r3,1
	r31.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8249fda0
	if (!cr6.eq) goto loc_8249FDA0;
loc_8249FD9C:
	// lwz r31,176(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 176);
loc_8249FDA0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8249fe2c
	if (cr6.eq) goto loc_8249FE2C;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x8249FDB4;
	sub_823DF058(ctx, base);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// bne cr6,0x8249fe2c
	if (!cr6.eq) goto loc_8249FE2C;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x8249FDC8;
	sub_823DF058(ctx, base);
	// cmpwi cr6,r3,114
	cr6.compare<int32_t>(ctx.r3.s32, 114, xer);
	// bne cr6,0x8249fe2c
	if (!cr6.eq) goto loc_8249FE2C;
	// lbz r11,2(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x8249FDDC;
	sub_823DF058(ctx, base);
	// cmpwi cr6,r3,118
	cr6.compare<int32_t>(ctx.r3.s32, 118, xer);
	// bne cr6,0x8249fe2c
	if (!cr6.eq) goto loc_8249FE2C;
	// lbz r11,3(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3);
	// cmplwi cr6,r11,95
	cr6.compare<uint32_t>(r11.u32, 95, xer);
	// bne cr6,0x8249fe2c
	if (!cr6.eq) goto loc_8249FE2C;
	// lbz r11,302(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fe2c
	if (cr6.eq) goto loc_8249FE2C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r19
	r11.u64 = r19.u64;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
loc_8249FE0C:
	// lwz r9,208(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8, temp.u32);
	// lbz r7,302(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 302);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8249fe0c
	if (cr6.lt) goto loc_8249FE0C;
loc_8249FE2C:
	// lwz r11,19620(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 19620);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fe4c
	if (cr6.eq) goto loc_8249FE4C;
	// addi r3,r11,972
	ctx.r3.s64 = r11.s64 + 972;
	// lwz r11,984(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 984);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249FE4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249FE4C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8249FE58"))) PPC_WEAK_FUNC(sub_8249FE58);
PPC_FUNC_IMPL(__imp__sub_8249FE58) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8249FE60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,1012
	ctx.r9.s64 = r11.s64 + 1012;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r11,19620(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fe98
	if (cr6.eq) goto loc_8249FE98;
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// lwz r11,1000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1000);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8249FE98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249FE98:
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// bl 0x82130588
	ctx.lr = 0x8249FEA0;
	sub_82130588(ctx, base);
	// lwz r3,260(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// bl 0x82130588
	ctx.lr = 0x8249FEA8;
	sub_82130588(ctx, base);
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// bl 0x82130588
	ctx.lr = 0x8249FEB0;
	sub_82130588(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249fed8
	if (cr6.eq) goto loc_8249FED8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8249fed8
	if (!cr6.eq) goto loc_8249FED8;
	// stw r27,144(r11)
	PPC_STORE_U32(r11.u32 + 144, r27.u32);
	// stw r27,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r27.u32);
loc_8249FED8:
	// lwz r3,276(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249fef8
	if (cr6.eq) goto loc_8249FEF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249FEF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249FEF8:
	// lwz r30,280(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249ff14
	if (cr6.eq) goto loc_8249FF14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b6018
	ctx.lr = 0x8249FF0C;
	sub_821B6018(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8249FF14;
	sub_82130588(ctx, base);
loc_8249FF14:
	// lwz r3,288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// bl 0x82130588
	ctx.lr = 0x8249FF1C;
	sub_82130588(ctx, base);
	// lwz r30,284(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8249ff38
	if (cr6.eq) goto loc_8249FF38;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b6018
	ctx.lr = 0x8249FF30;
	sub_821B6018(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8249FF38;
	sub_82130588(ctx, base);
loc_8249FF38:
	// lbz r11,303(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 303);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8249ff84
	if (cr6.eq) goto loc_8249FF84;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8249FF4C:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249ff70
	if (cr6.eq) goto loc_8249FF70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249FF70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249FF70:
	// lbz r11,303(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 303);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8249ff4c
	if (cr6.lt) goto loc_8249FF4C;
loc_8249FF84:
	// lwz r3,212(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// bl 0x82130588
	ctx.lr = 0x8249FF8C;
	sub_82130588(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8249FF94;
	sub_82130588(ctx, base);
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// bl 0x82130588
	ctx.lr = 0x8249FF9C;
	sub_82130588(ctx, base);
	// lwz r3,232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8249ffc4
	if (cr6.eq) goto loc_8249FFC4;
	// lbz r10,-2084(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + -2084);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8249ffc4
	if (cr6.eq) goto loc_8249FFC4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8258e568
	ctx.lr = 0x8249FFC0;
	sub_8258E568(ctx, base);
	// b 0x8249ffe0
	goto loc_8249FFE0;
loc_8249FFC4:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8249ffe0
	if (cr6.eq) goto loc_8249FFE0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249FFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8249FFE0:
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824a0004
	if (cr6.eq) goto loc_824A0004;
	// lbz r10,-2084(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + -2084);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a0004
	if (cr6.eq) goto loc_824A0004;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8258e568
	ctx.lr = 0x824A0000;
	sub_8258E568(ctx, base);
	// b 0x824a0020
	goto loc_824A0020;
loc_824A0004:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0020
	if (cr6.eq) goto loc_824A0020;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A0020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A0020:
	// lwz r3,240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// bl 0x82130588
	ctx.lr = 0x824A0028;
	sub_82130588(ctx, base);
	// lwz r3,244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// bl 0x82130588
	ctx.lr = 0x824A0030;
	sub_82130588(ctx, base);
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x82130588
	ctx.lr = 0x824A0038;
	sub_82130588(ctx, base);
	// lwz r3,236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824a005c
	if (cr6.eq) goto loc_824A005C;
	// lbz r11,-2084(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -2084);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a005c
	if (cr6.eq) goto loc_824A005C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82582fd0
	ctx.lr = 0x824A0058;
	sub_82582FD0(ctx, base);
	// b 0x824a0078
	goto loc_824A0078;
loc_824A005C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0078
	if (cr6.eq) goto loc_824A0078;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A0078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A0078:
	// lbz r11,302(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 302);
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a00c0
	if (cr6.eq) goto loc_824A00C0;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824A008C:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwzx r29,r30,r11
	r29.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824a00ac
	if (cr6.eq) goto loc_824A00AC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824d0f40
	ctx.lr = 0x824A00A4;
	sub_824D0F40(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x824A00AC;
	sub_82130588(ctx, base);
loc_824A00AC:
	// lbz r11,302(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 302);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x824a008c
	if (cr6.lt) goto loc_824A008C;
loc_824A00C0:
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x824A00C8;
	sub_82130588(ctx, base);
	// lwz r3,200(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a00e8
	if (cr6.eq) goto loc_824A00E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A00E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A00E8:
	// lwz r3,272(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824a0120
	if (cr6.eq) goto loc_824A0120;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824a5038
	ctx.lr = 0x824A0104;
	sub_824A5038(ctx, base);
	// lwz r30,272(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824a0120
	if (cr6.eq) goto loc_824A0120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a53f8
	ctx.lr = 0x824A0118;
	sub_824A53F8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x824A0120;
	sub_82130588(ctx, base);
loc_824A0120:
	// lwz r3,268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0140
	if (cr6.eq) goto loc_824A0140;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A0140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A0140:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824a01b0
	if (!cr6.gt) goto loc_824A01B0;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824A0154:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// stw r27,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r27.u32);
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwzx r8,r30,r9
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// stw r27,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r27.u32);
	// lwz r7,184(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwzx r3,r30,r7
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0190
	if (cr6.eq) goto loc_824A0190;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A0190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A0190:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x824A019C;
	sub_82130588(ctx, base);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x824a0154
	if (cr6.lt) goto loc_824A0154;
loc_824A01B0:
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x82130588
	ctx.lr = 0x824A01B8;
	sub_82130588(ctx, base);
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x824A01C0;
	sub_82130588(ctx, base);
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a01e0
	if (cr6.eq) goto loc_824A01E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A01E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824A01E0:
	// lhz r29,220(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 220);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x824a0210
	if (!cr6.gt) goto loc_824A0210;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824A01F0:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x824A01FC;
	sub_82130588(ctx, base);
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r27,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r27.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824a01f0
	if (!cr0.eq) goto loc_824A01F0;
loc_824A0210:
	// lhz r11,222(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 222);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a0224
	if (cr6.eq) goto loc_824A0224;
	// lwz r3,216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// bl 0x82130588
	ctx.lr = 0x824A0224;
	sub_82130588(ctx, base);
loc_824A0224:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x824A022C;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A0234"))) PPC_WEAK_FUNC(sub_824A0234);
PPC_FUNC_IMPL(__imp__sub_824A0234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A0238"))) PPC_WEAK_FUNC(sub_824A0238);
PPC_FUNC_IMPL(__imp__sub_824A0238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8249efb8
	sub_8249EFB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824A0244"))) PPC_WEAK_FUNC(sub_824A0244);
PPC_FUNC_IMPL(__imp__sub_824A0244) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A0248"))) PPC_WEAK_FUNC(sub_824A0248);
PPC_FUNC_IMPL(__imp__sub_824A0248) {
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
	ctx.lr = 0x824A0250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x824A0260;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824a02e0
	if (!cr6.gt) goto loc_824A02E0;
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r28,r30
	r28.u64 = r30.u64;
	// li r27,0
	r27.s64 = 0;
loc_824A0278:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824a02d4
	if (cr6.eq) goto loc_824A02D4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// lwzx r29,r10,r11
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824a02d0
	if (cr6.eq) goto loc_824A02D0;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824a02d0
	if (cr6.eq) goto loc_824A02D0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824A02AC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824a02d0
	if (cr6.eq) goto loc_824A02D0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x824A02C0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x824a02d4
	goto loc_824A02D4;
loc_824A02D0:
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
loc_824A02D4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x824a0278
	if (!cr0.eq) goto loc_824A0278;
loc_824A02E0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824A02EC"))) PPC_WEAK_FUNC(sub_824A02EC);
PPC_FUNC_IMPL(__imp__sub_824A02EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A02F0"))) PPC_WEAK_FUNC(sub_824A02F0);
PPC_FUNC_IMPL(__imp__sub_824A02F0) {
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
	ctx.lr = 0x824A02F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c00e8
	ctx.lr = 0x824A0308;
	sub_821C00E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8249ed78
	ctx.lr = 0x824A031C;
	sub_8249ED78(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,2828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a0340
	if (cr6.eq) goto loc_824A0340;
	// bl 0x821bbea8
	ctx.lr = 0x824A0340;
	sub_821BBEA8(ctx, base);
loc_824A0340:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c5c70
	ctx.lr = 0x824A0348;
	sub_821C5C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824A0350;
	sub_82130588(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824a035c
	if (cr6.eq) goto loc_824A035C;
	// bl 0x821bbf00
	ctx.lr = 0x824A035C;
	sub_821BBF00(ctx, base);
loc_824A035C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824A0368"))) PPC_WEAK_FUNC(sub_824A0368);
PPC_FUNC_IMPL(__imp__sub_824A0368) {
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
	ctx.lr = 0x824A0370;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821cfe80
	ctx.lr = 0x824A0390;
	sub_821CFE80(ctx, base);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r30,r31,268
	r30.s64 = r31.s64 + 268;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,2828(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// bl 0x824a02f0
	ctx.lr = 0x824A03AC;
	sub_824A02F0(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-29628
	ctx.r4.s64 = ctx.r8.s64 + -29628;
	// bl 0x821cfe80
	ctx.lr = 0x824A03C0;
	sub_821CFE80(ctx, base);
	// li r3,364
	ctx.r3.s64 = 364;
	// bl 0x82130528
	ctx.lr = 0x824A03C8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a03d8
	if (cr6.eq) goto loc_824A03D8;
	// bl 0x823d69a8
	ctx.lr = 0x824A03D4;
	sub_823D69A8(ctx, base);
	// b 0x824a03dc
	goto loc_824A03DC;
loc_824A03D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824A03DC:
	// stw r3,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x824cffd8
	ctx.lr = 0x824A03E8;
	sub_824CFFD8(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,272(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// bl 0x824a5490
	ctx.lr = 0x824A03F4;
	sub_824A5490(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824A03FC"))) PPC_WEAK_FUNC(sub_824A03FC);
PPC_FUNC_IMPL(__imp__sub_824A03FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A0400"))) PPC_WEAK_FUNC(sub_824A0400);
PPC_FUNC_IMPL(__imp__sub_824A0400) {
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
	ctx.lr = 0x824A0408;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32178
	r11.s64 = -2108817408;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-30040
	ctx.r4.s64 = r11.s64 + -30040;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0430;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r5,r9,3664
	ctx.r5.s64 = ctx.r9.s64 + 3664;
	// addi r4,r8,1612
	ctx.r4.s64 = ctx.r8.s64 + 1612;
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r8,r7,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0460;
	sub_82614440(ctx, base);
	// lis r4,-32178
	ctx.r4.s64 = -2108817408;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-29592
	ctx.r4.s64 = ctx.r4.s64 + -29592;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A047C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r29,r10,11856
	r29.s64 = ctx.r10.s64 + 11856;
	// addi r4,r9,1604
	ctx.r4.s64 = ctx.r9.s64 + 1604;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82614440
	ctx.lr = 0x824A04B0;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-10096
	ctx.r4.s64 = ctx.r4.s64 + -10096;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A04CC;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r4,r9,1592
	ctx.r4.s64 = ctx.r9.s64 + 1592;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r5,r10,1584
	ctx.r5.s64 = ctx.r10.s64 + 1584;
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A04FC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-9960
	ctx.r4.s64 = ctx.r4.s64 + -9960;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0518;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r28,r10,996
	r28.s64 = ctx.r10.s64 + 996;
	// addi r5,r9,1576
	ctx.r5.s64 = ctx.r9.s64 + 1576;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82614440
	ctx.lr = 0x824A054C;
	sub_82614440(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-14648
	ctx.r4.s64 = ctx.r4.s64 + -14648;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0568;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1560
	ctx.r5.s64 = ctx.r10.s64 + 1560;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0594;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-9888
	ctx.r4.s64 = ctx.r4.s64 + -9888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A05B0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1552
	ctx.r5.s64 = ctx.r10.s64 + 1552;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A05DC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14576
	ctx.r4.s64 = ctx.r4.s64 + -14576;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A05F8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1536
	ctx.r5.s64 = ctx.r10.s64 + 1536;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0624;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14504
	ctx.r4.s64 = ctx.r4.s64 + -14504;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0640;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,1524
	ctx.r5.s64 = ctx.r10.s64 + 1524;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A066C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-14112
	ctx.r4.s64 = ctx.r4.s64 + -14112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0688;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r5,r10,1508
	ctx.r5.s64 = ctx.r10.s64 + 1508;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82614440
	ctx.lr = 0x824A06B4;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14424
	ctx.r4.s64 = ctx.r4.s64 + -14424;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A06D0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1492
	ctx.r5.s64 = ctx.r10.s64 + 1492;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A06FC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14320
	ctx.r4.s64 = ctx.r4.s64 + -14320;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0718;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1472
	ctx.r5.s64 = ctx.r10.s64 + 1472;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0744;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14032
	ctx.r4.s64 = ctx.r4.s64 + -14032;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0760;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1452
	ctx.r5.s64 = ctx.r10.s64 + 1452;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A078C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13960
	ctx.r4.s64 = ctx.r4.s64 + -13960;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A07A8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,1420
	ctx.r5.s64 = ctx.r10.s64 + 1420;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A07D4;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-14216
	ctx.r4.s64 = ctx.r4.s64 + -14216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A07F0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1396
	ctx.r5.s64 = ctx.r10.s64 + 1396;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A081C;
	sub_82614440(ctx, base);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,0
	ctx.r4.s64 = ctx.r4.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0838;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1380
	ctx.r5.s64 = ctx.r10.s64 + 1380;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0864;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13888
	ctx.r4.s64 = ctx.r4.s64 + -13888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0880;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1360
	ctx.r5.s64 = ctx.r10.s64 + 1360;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A08AC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13856
	ctx.r4.s64 = ctx.r4.s64 + -13856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A08C8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1340
	ctx.r5.s64 = ctx.r10.s64 + 1340;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A08F4;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13784
	ctx.r4.s64 = ctx.r4.s64 + -13784;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0910;
	sub_821C2FB0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r11,1324
	ctx.r5.s64 = r11.s64 + 1324;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82614440
	ctx.lr = 0x824A093C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13752
	ctx.r4.s64 = ctx.r4.s64 + -13752;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0958;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1308
	ctx.r5.s64 = ctx.r10.s64 + 1308;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0984;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13720
	ctx.r4.s64 = ctx.r4.s64 + -13720;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A09A0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1292
	ctx.r5.s64 = ctx.r10.s64 + 1292;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A09CC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13688
	ctx.r4.s64 = ctx.r4.s64 + -13688;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A09E8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1276
	ctx.r5.s64 = ctx.r10.s64 + 1276;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0A14;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13656
	ctx.r4.s64 = ctx.r4.s64 + -13656;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0A30;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,1260
	ctx.r5.s64 = ctx.r10.s64 + 1260;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0A5C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13624
	ctx.r4.s64 = ctx.r4.s64 + -13624;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0A78;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1240
	ctx.r5.s64 = ctx.r10.s64 + 1240;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0AA4;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13592
	ctx.r4.s64 = ctx.r4.s64 + -13592;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0AC0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1220
	ctx.r5.s64 = ctx.r10.s64 + 1220;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0AEC;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-9776
	ctx.r4.s64 = ctx.r4.s64 + -9776;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0B08;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1204
	ctx.r5.s64 = ctx.r10.s64 + 1204;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0B34;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-9640
	ctx.r4.s64 = ctx.r4.s64 + -9640;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0B50;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r5,r10,1192
	ctx.r5.s64 = ctx.r10.s64 + 1192;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0B7C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,872
	ctx.r4.s64 = ctx.r4.s64 + 872;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0B98;
	sub_821C2FB0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r11,1176
	ctx.r5.s64 = r11.s64 + 1176;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82614440
	ctx.lr = 0x824A0BC4;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-13504
	ctx.r4.s64 = ctx.r4.s64 + -13504;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0BE0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,1160
	ctx.r5.s64 = ctx.r10.s64 + 1160;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0C0C;
	sub_82614440(ctx, base);
	// lis r4,-32178
	ctx.r4.s64 = -2108817408;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-29448
	ctx.r4.s64 = ctx.r4.s64 + -29448;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0C28;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,1152
	ctx.r4.s64 = ctx.r10.s64 + 1152;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0C54;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13328
	ctx.r4.s64 = ctx.r4.s64 + -13328;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0C70;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-20884
	ctx.r4.s64 = ctx.r10.s64 + -20884;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0C9C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13344
	ctx.r4.s64 = ctx.r4.s64 + -13344;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0CB8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,2068
	ctx.r4.s64 = ctx.r10.s64 + 2068;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0CE4;
	sub_82614440(ctx, base);
	// lis r4,-32179
	ctx.r4.s64 = -2108882944;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,31816
	ctx.r4.s64 = ctx.r4.s64 + 31816;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0D00;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,1136
	ctx.r4.s64 = ctx.r10.s64 + 1136;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0D2C;
	sub_82614440(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824A0D34"))) PPC_WEAK_FUNC(sub_824A0D34);
PPC_FUNC_IMPL(__imp__sub_824A0D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A0D38"))) PPC_WEAK_FUNC(sub_824A0D38);
PPC_FUNC_IMPL(__imp__sub_824A0D38) {
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
	// bl 0x8249fe58
	ctx.lr = 0x824A0D58;
	sub_8249FE58(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a0d70
	if (cr6.eq) goto loc_824A0D70;
	// bl 0x82130588
	ctx.lr = 0x824A0D6C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824A0D70:
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

__attribute__((alias("__imp__sub_824A0D88"))) PPC_WEAK_FUNC(sub_824A0D88);
PPC_FUNC_IMPL(__imp__sub_824A0D88) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824A0D90;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,56576
	r12.u64 = r12.u64 | 56576;
	// subf r31,r12,r1
	r31.s64 = ctx.r1.s64 - r12.s64;
	// lis r12,-1
	r12.s64 = -65536;
	// ori r12,r12,8960
	r12.u64 = r12.u64 | 8960;
	// bl 0x823dbff4
	ctx.lr = 0x824A0DB4;
	sub_823DBFF4(ctx, base);
	// stwux r1,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r14,0(r13)
	r14.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,0
	r25.s64 = 0;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// li r21,60
	r21.s64 = 60;
	// stb r25,302(r30)
	PPC_STORE_U8(r30.u32 + 302, r25.u8);
	// addi r29,r31,1648
	r29.s64 = r31.s64 + 1648;
	// stb r25,303(r30)
	PPC_STORE_U8(r30.u32 + 303, r25.u8);
	// li r26,254
	r26.s64 = 254;
	// stb r25,306(r30)
	PPC_STORE_U8(r30.u32 + 306, r25.u8);
	// stw r25,248(r30)
	PPC_STORE_U32(r30.u32 + 248, r25.u32);
loc_824A0DEC:
	// lwzx r28,r21,r14
	r28.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824a0e3c
	if (cr6.eq) goto loc_824A0E3C;
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824a0e3c
	if (cr6.eq) goto loc_824A0E3C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824A0E10;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824a0e3c
	if (cr6.eq) goto loc_824A0E3C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x824A0E24;
	sub_8217D890(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r4,r21,r14
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// bl 0x824d0fc8
	ctx.lr = 0x824A0E38;
	sub_824D0FC8(ctx, base);
	// b 0x824a0e40
	goto loc_824A0E40;
loc_824A0E3C:
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
loc_824A0E40:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bge 0x824a0dec
	if (!cr0.lt) goto loc_824A0DEC;
	// bl 0x821bbea8
	ctx.lr = 0x824A0E50;
	sub_821BBEA8(ctx, base);
	// addi r3,r30,216
	ctx.r3.s64 = r30.s64 + 216;
	// li r4,255
	ctx.r4.s64 = 255;
	// bl 0x824a0248
	ctx.lr = 0x824A0E5C;
	sub_824A0248(ctx, base);
	// li r29,255
	r29.s64 = 255;
	// stw r3,216(r30)
	PPC_STORE_U32(r30.u32 + 216, ctx.r3.u32);
	// sth r29,222(r30)
	PPC_STORE_U16(r30.u32 + 222, r29.u16);
	// bl 0x821bbf00
	ctx.lr = 0x824A0E6C;
	sub_821BBF00(ctx, base);
	// addi r11,r31,1648
	r11.s64 = r31.s64 + 1648;
	// addi r10,r31,624
	ctx.r10.s64 = r31.s64 + 624;
	// stw r11,208(r30)
	PPC_STORE_U32(r30.u32 + 208, r11.u32);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r10,212(r30)
	PPC_STORE_U32(r30.u32 + 212, ctx.r10.u32);
	// stw r25,224(r30)
	PPC_STORE_U32(r30.u32 + 224, r25.u32);
	// bl 0x82130528
	ctx.lr = 0x824A0E88;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0e9c
	if (cr6.eq) goto loc_824A0E9C;
	// bl 0x824d9240
	ctx.lr = 0x824A0E94;
	sub_824D9240(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x824a0ea0
	goto loc_824A0EA0;
loc_824A0E9C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_824A0EA0:
	// stw r11,180(r30)
	PPC_STORE_U32(r30.u32 + 180, r11.u32);
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614ac0
	ctx.lr = 0x824A0EAC;
	sub_82614AC0(ctx, base);
	// addi r4,r31,2672
	ctx.r4.s64 = r31.s64 + 2672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a0400
	ctx.lr = 0x824A0EB8;
	sub_824A0400(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614588
	ctx.lr = 0x824A0EC8;
	sub_82614588(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,304(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 304);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r28,1
	r28.s64 = 1;
	// li r15,16
	r15.s64 = 16;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r17,32
	r17.s64 = 32;
	// li r16,48
	r16.s64 = 48;
	// addi r19,r11,1788
	r19.s64 = r11.s64 + 1788;
	// addi r20,r10,11856
	r20.s64 = ctx.r10.s64 + 11856;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824a12a0
	if (!cr6.eq) goto loc_824A12A0;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614a10
	ctx.lr = 0x824A0F04;
	sub_82614A10(ctx, base);
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x824A0F0C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a0f20
	if (cr6.eq) goto loc_824A0F20;
	// bl 0x824d9240
	ctx.lr = 0x824A0F18;
	sub_824D9240(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x824a0f24
	goto loc_824A0F24;
loc_824A0F20:
	// mr r27,r25
	r27.u64 = r25.u64;
loc_824A0F24:
	// lis r11,-32178
	r11.s64 = -2108817408;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r11,-31000
	ctx.r4.s64 = r11.s64 + -31000;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0F40;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// addi r4,r9,19832
	ctx.r4.s64 = ctx.r9.s64 + 19832;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0F6C;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-13312
	ctx.r4.s64 = ctx.r4.s64 + -13312;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0F88;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r10,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0FB0;
	sub_82614440(ctx, base);
	// lis r9,-32182
	ctx.r9.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r5,180(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r9,-13296
	ctx.r4.s64 = ctx.r9.s64 + -13296;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821c2fb0
	ctx.lr = 0x824A0FCC;
	sub_821C2FB0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// addi r4,r6,1780
	ctx.r4.s64 = ctx.r6.s64 + 1780;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// ld r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// rldicr r8,r11,32,63
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r7)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r7.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A0FF8;
	sub_82614440(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821cf7f0
	ctx.lr = 0x824A1000;
	sub_821CF7F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614588
	ctx.lr = 0x824A1010;
	sub_82614588(ctx, base);
	// stw r25,200(r30)
	PPC_STORE_U32(r30.u32 + 200, r25.u32);
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x824A101C;
	sub_82130528(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f29,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f29.f64 = double(temp.f32);
	// beq cr6,0x824a1054
	if (cr6.eq) goto loc_824A1054;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// li r8,255
	ctx.r8.s64 = 255;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824d9798
	ctx.lr = 0x824A104C;
	sub_824D9798(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// b 0x824a1058
	goto loc_824A1058;
loc_824A1054:
	// mr r24,r25
	r24.u64 = r25.u64;
loc_824A1058:
	// stw r27,144(r24)
	PPC_STORE_U32(r24.u32 + 144, r27.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824d9a58
	ctx.lr = 0x824A1068;
	sub_824D9A58(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x824a1084
	if (cr6.eq) goto loc_824A1084;
	// stfs f1,8(r24)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r24.u32 + 8, temp.u32);
	// stfs f1,4(r24)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r24.u32 + 4, temp.u32);
	// b 0x824a108c
	goto loc_824A108C;
loc_824A1084:
	// stfs f30,8(r24)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r24.u32 + 8, temp.u32);
	// stfs f30,4(r24)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r24.u32 + 4, temp.u32);
loc_824A108C:
	// stfs f31,316(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 316, temp.u32);
	// stb r25,309(r30)
	PPC_STORE_U8(r30.u32 + 309, r25.u8);
	// stb r25,311(r30)
	PPC_STORE_U8(r30.u32 + 311, r25.u8);
	// li r3,128
	ctx.r3.s64 = 128;
	// stb r28,304(r30)
	PPC_STORE_U8(r30.u32 + 304, r28.u8);
	// stb r28,302(r30)
	PPC_STORE_U8(r30.u32 + 302, r28.u8);
	// bl 0x82130528
	ctx.lr = 0x824A10A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1114
	if (cr6.eq) goto loc_824A1114;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f31,180(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r25,175(r1)
	PPC_STORE_U8(ctx.r1.u32 + 175, r25.u8);
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// stb r29,167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 167, r29.u8);
	// fmr f12,f31
	ctx.f12.f64 = f31.f64;
	// stb r29,159(r1)
	PPC_STORE_U8(ctx.r1.u32 + 159, r29.u8);
	// fmr f11,f31
	ctx.f11.f64 = f31.f64;
	// lfs f3,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f3.f64 = double(temp.f32);
	// stb r29,151(r1)
	PPC_STORE_U8(ctx.r1.u32 + 151, r29.u8);
	// stb r25,143(r1)
	PPC_STORE_U8(ctx.r1.u32 + 143, r25.u8);
	// lfs f1,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// fmr f10,f31
	ctx.f10.f64 = f31.f64;
	// stb r28,135(r1)
	PPC_STORE_U8(ctx.r1.u32 + 135, r28.u8);
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x824d0b38
	ctx.lr = 0x824A1110;
	sub_824D0B38(ctx, base);
	// b 0x824a1118
	goto loc_824A1118;
loc_824A1114:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A1118:
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r10,208(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stb r25,70(r9)
	PPC_STORE_U8(ctx.r9.u32 + 70, r25.u8);
	// lwz r8,208(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lhz r11,208(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 208);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stb r7,71(r5)
	PPC_STORE_U8(ctx.r5.u32 + 71, ctx.r7.u8);
	// lwz r4,208(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stb r25,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r25.u8);
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r29,68(r10)
	PPC_STORE_U8(ctx.r10.u32 + 68, r29.u8);
	// lwz r9,208(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stb r29,69(r8)
	PPC_STORE_U8(ctx.r8.u32 + 69, r29.u8);
	// lwz r7,208(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stfs f31,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// lhz r11,208(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824a123c
	if (!cr6.gt) goto loc_824A123C;
	// li r28,0
	r28.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_824A1188:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x824A1190;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a11a4
	if (cr6.eq) goto loc_824A11A4;
	// bl 0x824d9240
	ctx.lr = 0x824A119C;
	sub_824D9240(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x824a11a8
	goto loc_824A11A8;
loc_824A11A4:
	// li r29,0
	r29.s64 = 0;
loc_824A11A8:
	// lwz r10,196(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r29,128
	r11.s64 = r29.s64 + 128;
	// li r3,192
	ctx.r3.s64 = 192;
	// lwzx r8,r28,r10
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// stw r8,192(r29)
	PPC_STORE_U32(r29.u32 + 192, ctx.r8.u32);
	// lwz r7,196(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// stwx r9,r28,r7
	PPC_STORE_U32(r28.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r10,204(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 204);
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + r26.u64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r15
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r17
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r16
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130528
	ctx.lr = 0x824A11F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1220
	if (cr6.eq) goto loc_824A1220;
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r10,14(r24)
	ctx.r10.u64 = PPC_LOAD_U16(r24.u32 + 14);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f2,8(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824d9798
	ctx.lr = 0x824A121C;
	sub_824D9798(ctx, base);
	// b 0x824a1224
	goto loc_824A1224;
loc_824A1220:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824A1224:
	// addi r11,r31,628
	r11.s64 = r31.s64 + 628;
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,64
	r26.s64 = r26.s64 + 64;
	// stwx r3,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, ctx.r3.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x824a1188
	if (!cr0.eq) goto loc_824A1188;
loc_824A123C:
	// li r4,47
	ctx.r4.s64 = 47;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823db6d0
	ctx.lr = 0x824A1248;
	sub_823DB6D0(ctx, base);
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a127c
	if (cr6.eq) goto loc_824A127C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r11,84
	ctx.r3.s64 = r11.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x824A1268;
	sub_823DB670(ctx, base);
	// lwz r9,208(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stb r10,127(r8)
	PPC_STORE_U8(ctx.r8.u32 + 127, ctx.r10.u8);
	// b 0x824a1288
	goto loc_824A1288;
loc_824A127C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,84(r9)
	PPC_STORE_U8(ctx.r9.u32 + 84, ctx.r10.u8);
loc_824A1288:
	// lhz r11,208(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 208);
	// li r25,0
	r25.s64 = 0;
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stb r9,303(r30)
	PPC_STORE_U8(r30.u32 + 303, ctx.r9.u8);
	// stw r24,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r24.u32);
loc_824A12A0:
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// stw r25,208(r30)
	PPC_STORE_U32(r30.u32 + 208, r25.u32);
	// ori r24,r10,65535
	r24.u64 = ctx.r10.u64 | 65535;
	// stw r25,212(r30)
	PPC_STORE_U32(r30.u32 + 212, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2610
	if (cr6.eq) goto loc_824A2610;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x824A12C4;
	sub_82130528(ctx, base);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// addi r4,r31,624
	ctx.r4.s64 = r31.s64 + 624;
	// stw r3,212(r30)
	PPC_STORE_U32(r30.u32 + 212, ctx.r3.u32);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x823da950
	ctx.lr = 0x824A12D8;
	sub_823DA950(ctx, base);
	// lbz r29,302(r30)
	r29.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// cmplw cr6,r29,r24
	cr6.compare<uint32_t>(r29.u32, r24.u32, xer);
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x824a12ec
	if (!cr6.gt) goto loc_824A12EC;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824A12EC:
	// bl 0x82130528
	ctx.lr = 0x824A12F0;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824a1374
	if (cr6.eq) goto loc_824A1374;
	// addic. r26,r29,-1
	xer.ca = r29.u32 > 0;
	r26.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// mr r29,r25
	r29.u64 = r25.u64;
	// blt 0x824a136c
	if (cr0.lt) goto loc_824A136C;
loc_824A130C:
	// lwzx r28,r21,r14
	r28.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824a135c
	if (cr6.eq) goto loc_824A135C;
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824a135c
	if (cr6.eq) goto loc_824A135C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824A1330;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824a135c
	if (cr6.eq) goto loc_824A135C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x824A1344;
	sub_8217D890(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwzx r4,r21,r14
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// bl 0x824d0fc8
	ctx.lr = 0x824A1358;
	sub_824D0FC8(ctx, base);
	// b 0x824a1360
	goto loc_824A1360;
loc_824A135C:
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
loc_824A1360:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bge 0x824a130c
	if (!cr0.lt) goto loc_824A130C;
loc_824A136C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// b 0x824a1378
	goto loc_824A1378;
loc_824A1374:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_824A1378:
	// stw r4,208(r30)
	PPC_STORE_U32(r30.u32 + 208, ctx.r4.u32);
	// addi r7,r31,368
	ctx.r7.s64 = r31.s64 + 368;
	// addi r3,r31,1648
	ctx.r3.s64 = r31.s64 + 1648;
	// lwz r6,212(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lbz r5,302(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// bl 0x8249daa0
	ctx.lr = 0x824A1390;
	sub_8249DAA0(ctx, base);
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// mr r26,r23
	r26.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a142c
	if (cr6.eq) goto loc_824A142C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r28,r23
	r28.u64 = r23.u64;
	// addi r25,r11,1704
	r25.s64 = r11.s64 + 1704;
loc_824A13AC:
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// mr r29,r23
	r29.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a1418
	if (cr6.eq) goto loc_824A1418;
	// mr r27,r23
	r27.u64 = r23.u64;
loc_824A13C0:
	// cmpw cr6,r26,r29
	cr6.compare<int32_t>(r26.s32, r29.s32, xer);
	// beq cr6,0x824a1404
	if (cr6.eq) goto loc_824A1404;
	// lwz r10,208(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwzx r11,r27,r10
	r11.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// lwzx r10,r28,r10
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// addi r4,r11,84
	ctx.r4.s64 = r11.s64 + 84;
	// addi r3,r10,84
	ctx.r3.s64 = ctx.r10.s64 + 84;
	// bl 0x823db730
	ctx.lr = 0x824A13E0;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824a1404
	if (!cr6.eq) goto loc_824A1404;
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// addi r6,r11,84
	ctx.r6.s64 = r11.s64 + 84;
	// bl 0x82130000
	ctx.lr = 0x824A1404;
	sub_82130000(ctx, base);
loc_824A1404:
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824a13c0
	if (cr6.lt) goto loc_824A13C0;
loc_824A1418:
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x824a13ac
	if (cr6.lt) goto loc_824A13AC;
loc_824A142C:
	// lbz r10,300(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 300);
	// mr r11,r23
	r11.u64 = r23.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a1478
	if (cr6.eq) goto loc_824A1478;
loc_824A143C:
	// lwz r10,256(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// addi r9,r31,368
	ctx.r9.s64 = r31.s64 + 368;
	// addi r8,r31,368
	ctx.r8.s64 = r31.s64 + 368;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// stbx r6,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r6.u8);
	// lwz r10,260(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// lbz r3,300(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 300);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x824a143c
	if (cr6.lt) goto loc_824A143C;
loc_824A1478:
	// lwz r11,180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// lfs f0,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824a1490
	if (cr6.gt) goto loc_824A1490;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824A1490:
	// lbz r8,303(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824a14cc
	if (cr6.eq) goto loc_824A14CC;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
loc_824A14A8:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lfs f0,112(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x824a14c0
	if (!cr6.gt) goto loc_824A14C0;
	// li r9,1
	ctx.r9.s64 = 1;
loc_824A14C0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x824a14a8
	if (!cr0.eq) goto loc_824A14A8;
loc_824A14CC:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a153c
	if (!cr6.eq) goto loc_824A153C;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614a10
	ctx.lr = 0x824A14E0;
	sub_82614A10(ctx, base);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-5344
	ctx.r4.s64 = r11.s64 + -5344;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821c2fb0
	ctx.lr = 0x824A14FC;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x824A1524;
	sub_82614440(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821cf7f0
	ctx.lr = 0x824A152C;
	sub_821CF7F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614588
	ctx.lr = 0x824A153C;
	sub_82614588(ctx, base);
loc_824A153C:
	// lwz r29,192(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// li r25,-1
	r25.s64 = -1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x824a1720
	if (!cr6.gt) goto loc_824A1720;
	// cmplw cr6,r29,r24
	cr6.compare<uint32_t>(r29.u32, r24.u32, xer);
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x824a155c
	if (!cr6.gt) goto loc_824A155C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A155C:
	// bl 0x82130528
	ctx.lr = 0x824A1560;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824a16bc
	if (cr6.eq) goto loc_824A16BC;
	// addic. r28,r29,-1
	xer.ca = r29.u32 > 0;
	r28.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r29,r26
	r29.u64 = r26.u64;
	// blt 0x824a1604
	if (cr0.lt) goto loc_824A1604;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r11,-26560
	r27.s64 = r11.s64 + -26560;
loc_824A1580:
	// lwzx r3,r21,r14
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a15f4
	if (cr6.eq) goto loc_824A15F4;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824a15f4
	if (cr6.eq) goto loc_824A15F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x824a15f4
	if (!cr0.gt) goto loc_824A15F4;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_824A15B4:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824a15d4
	if (cr6.lt) goto loc_824A15D4;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824a15d8
	if (cr6.lt) goto loc_824A15D8;
loc_824A15D4:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824A15D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a160c
	if (!cr6.eq) goto loc_824A160C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x824a15b4
	if (cr6.lt) goto loc_824A15B4;
loc_824A15F4:
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
loc_824A15F8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bge 0x824a1580
	if (!cr0.lt) goto loc_824A1580;
loc_824A1604:
	// mr r29,r26
	r29.u64 = r26.u64;
	// b 0x824a16c0
	goto loc_824A16C0;
loc_824A160C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x824a15f4
	if (cr6.eq) goto loc_824A15F4;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// lhz r10,2(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r11,0(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x824a1670
	if (!cr0.gt) goto loc_824A1670;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_824A1630:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x824a1650
	if (cr6.lt) goto loc_824A1650;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824a1654
	if (cr6.lt) goto loc_824A1654;
loc_824A1650:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824A1654:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a1694
	if (!cr6.eq) goto loc_824A1694;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x824a1630
	if (cr6.lt) goto loc_824A1630;
loc_824A1670:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821d2378
	ctx.lr = 0x824A1678;
	sub_821D2378(ctx, base);
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824A167C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwzx r4,r21,r14
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + r14.u32);
	// bl 0x824d9688
	ctx.lr = 0x824A1690;
	sub_824D9688(ctx, base);
	// b 0x824a15f8
	goto loc_824A15F8;
loc_824A1694:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x824a1670
	if (cr6.eq) goto loc_824A1670;
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
	// b 0x824a167c
	goto loc_824A167C;
loc_824A16BC:
	// mr r29,r23
	r29.u64 = r23.u64;
loc_824A16C0:
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,184(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823da950
	ctx.lr = 0x824A16D4;
	sub_823DA950(ctx, base);
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x824a16e8
	if (!cr6.gt) goto loc_824A16E8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A16E8:
	// bl 0x82130528
	ctx.lr = 0x824A16EC;
	sub_82130528(ctx, base);
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lwz r4,188(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823da950
	ctx.lr = 0x824A1700;
	sub_823DA950(ctx, base);
	// bl 0x821bbea8
	ctx.lr = 0x824A1704;
	sub_821BBEA8(ctx, base);
	// lwz r3,184(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// bl 0x82130588
	ctx.lr = 0x824A170C;
	sub_82130588(ctx, base);
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x824A1714;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x824A1718;
	sub_821BBF00(ctx, base);
	// stw r29,184(r30)
	PPC_STORE_U32(r30.u32 + 184, r29.u32);
	// stw r28,188(r30)
	PPC_STORE_U32(r30.u32 + 188, r28.u32);
loc_824A1720:
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x824A1728;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1738
	if (cr6.eq) goto loc_824A1738;
	// bl 0x82599ca8
	ctx.lr = 0x824A1734;
	sub_82599CA8(ctx, base);
	// b 0x824a173c
	goto loc_824A173C;
loc_824A1738:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_824A173C:
	// stw r3,236(r30)
	PPC_STORE_U32(r30.u32 + 236, ctx.r3.u32);
	// lis r11,1023
	r11.s64 = 67043328;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// rlwinm r3,r11,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// ble cr6,0x824a175c
	if (!cr6.gt) goto loc_824A175C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A175C:
	// bl 0x82130528
	ctx.lr = 0x824A1760;
	sub_82130528(ctx, base);
	// stw r3,248(r30)
	PPC_STORE_U32(r30.u32 + 248, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r4,303(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// lwz r3,236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// bl 0x8259b0a0
	ctx.lr = 0x824A1774;
	sub_8259B0A0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// addi r29,r11,-31280
	r29.s64 = r11.s64 + -31280;
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a181c
	if (cr6.eq) goto loc_824A181C;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
loc_824A1794:
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// li r6,16
	ctx.r6.s64 = 16;
	// lwz r5,236(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// lwz r11,132(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,144(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r10,r15
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r10,r17
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r10,r16
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r29,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,303(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x824a1794
	if (cr6.lt) goto loc_824A1794;
loc_824A181C:
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x824A1824;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1834
	if (cr6.eq) goto loc_824A1834;
	// bl 0x8258f620
	ctx.lr = 0x824A1830;
	sub_8258F620(ctx, base);
	// b 0x824a1838
	goto loc_824A1838;
loc_824A1834:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_824A1838:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r3,228(r30)
	PPC_STORE_U32(r30.u32 + 228, ctx.r3.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lbz r9,-2084(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -2084);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824a185c
	if (cr6.eq) goto loc_824A185C;
	// lhz r11,26(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r11.u16);
loc_824A185C:
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a187c
	if (cr6.eq) goto loc_824A187C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x824A1870;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x824a1880
	if (!cr6.eq) goto loc_824A1880;
loc_824A187C:
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_824A1880:
	// lwz r10,228(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lis r9,4095
	ctx.r9.s64 = 268369920;
	// ori r28,r9,65535
	r28.u64 = ctx.r9.u64 | 65535;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r8,228(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lfs f0,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 324);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 60, temp.u32);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x824a18b0
	if (!cr6.gt) goto loc_824A18B0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A18B0:
	// bl 0x82130528
	ctx.lr = 0x824A18B4;
	sub_82130528(ctx, base);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// stw r3,244(r30)
	PPC_STORE_U32(r30.u32 + 244, ctx.r3.u32);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x824a18cc
	if (!cr6.gt) goto loc_824A18CC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A18CC:
	// bl 0x82130528
	ctx.lr = 0x824A18D0;
	sub_82130528(ctx, base);
	// stw r3,240(r30)
	PPC_STORE_U32(r30.u32 + 240, ctx.r3.u32);
	// lwz r11,180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// stw r23,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r23.u32);
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r28,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r28.u32);
	// beq cr6,0x824a1ac0
	if (cr6.eq) goto loc_824A1AC0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r29,20(r28)
	r29.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// addi r8,r31,352
	ctx.r8.s64 = r31.s64 + 352;
	// addi r7,r31,272
	ctx.r7.s64 = r31.s64 + 272;
	// addi r6,r31,240
	ctx.r6.s64 = r31.s64 + 240;
	// addi r5,r31,216
	ctx.r5.s64 = r31.s64 + 216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8249ce60
	ctx.lr = 0x824A190C;
	sub_8249CE60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a1924
	if (cr6.eq) goto loc_824A1924;
	// lbz r11,307(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 307);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stb r10,307(r30)
	PPC_STORE_U8(r30.u32 + 307, ctx.r10.u8);
loc_824A1924:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x824A192C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1944
	if (cr6.eq) goto loc_824A1944;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821b5e40
	ctx.lr = 0x824A1940;
	sub_821B5E40(ctx, base);
	// b 0x824a1948
	goto loc_824A1948;
loc_824A1944:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_824A1948:
	// stw r3,284(r30)
	PPC_STORE_U32(r30.u32 + 284, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x821b5c60
	ctx.lr = 0x824A1960;
	sub_821B5C60(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821a15b8
	ctx.lr = 0x824A1968;
	sub_821A15B8(ctx, base);
	// stw r3,288(r30)
	PPC_STORE_U32(r30.u32 + 288, ctx.r3.u32);
	// lwz r10,180(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// lwz r11,64(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824a1998
	if (!cr6.eq) goto loc_824A1998;
	// lfs f0,112(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824a1990
	if (cr6.gt) goto loc_824A1990;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824A1990:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x824a19a8
	goto loc_824A19A8;
loc_824A1998:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r9,21(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 21);
	// clrlwi r5,r9,31
	ctx.r5.u64 = ctx.r9.u32 & 0x1;
loc_824A19A8:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,284(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// lwz r3,288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 288);
	// bl 0x821a1848
	ctx.lr = 0x824A19B8;
	sub_821A1848(ctx, base);
	// rlwinm r11,r29,6,0,25
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0xFFFFFFC0;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x824A19C8;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lhz r7,20(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r10,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r10.u32);
	// beq cr6,0x824a1a3c
	if (cr6.eq) goto loc_824A1A3C;
	// addi r11,r10,32
	r11.s64 = ctx.r10.s64 + 32;
	// subfic r8,r10,-32
	xer.ca = ctx.r10.u32 <= 4294967264;
	ctx.r8.s64 = -32 - ctx.r10.s64;
	// li r6,-32
	ctx.r6.s64 = -32;
	// li r7,-16
	ctx.r7.s64 = -16;
loc_824A19F8:
	// lwz r10,284(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r15
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r10,r17
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r10,r16
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lhz r5,20(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// blt cr6,0x824a19f8
	if (cr6.lt) goto loc_824A19F8;
loc_824A1A3C:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x824A1A44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a1a5c
	if (cr6.eq) goto loc_824A1A5C;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821b5e40
	ctx.lr = 0x824A1A58;
	sub_821B5E40(ctx, base);
	// b 0x824a1a60
	goto loc_824A1A60;
loc_824A1A5C:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_824A1A60:
	// stw r3,280(r30)
	PPC_STORE_U32(r30.u32 + 280, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x821b5c60
	ctx.lr = 0x824A1A78;
	sub_821B5C60(ctx, base);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a1ac0
	if (cr6.eq) goto loc_824A1AC0;
	// addi r11,r31,624
	r11.s64 = r31.s64 + 624;
loc_824A1A8C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,144(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// stw r28,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, r28.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,148(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a1aac
	if (cr6.eq) goto loc_824A1AAC;
	// stw r28,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r28.u32);
loc_824A1AAC:
	// lbz r10,303(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x824a1a8c
	if (cr6.lt) goto loc_824A1A8C;
loc_824A1AC0:
	// bl 0x821bbea8
	ctx.lr = 0x824A1AC4;
	sub_821BBEA8(ctx, base);
	// li r3,8192
	ctx.r3.s64 = 8192;
	// bl 0x82130528
	ctx.lr = 0x824A1ACC;
	sub_82130528(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// li r3,8192
	ctx.r3.s64 = 8192;
	// bl 0x82130528
	ctx.lr = 0x824A1AD8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r29.u32);
	// bl 0x821bbf00
	ctx.lr = 0x824A1AE4;
	sub_821BBF00(ctx, base);
	// stw r23,0(r14)
	PPC_STORE_U32(r14.u32 + 0, r23.u32);
	// addi r11,r29,4
	r11.s64 = r29.s64 + 4;
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
	// subf r9,r29,r14
	ctx.r9.s64 = r14.s64 - r29.s64;
	// li r10,2047
	ctx.r10.s64 = 2047;
	// li r15,-1
	r15.s64 = -1;
loc_824A1AFC:
	// stwx r15,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r15.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r15,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r15.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x824a1afc
	if (!cr0.eq) goto loc_824A1AFC;
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// mr r21,r23
	r21.u64 = r23.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x824a1b2c
	if (!cr6.gt) goto loc_824A1B2C;
	// lbz r11,307(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 307);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stb r10,307(r30)
	PPC_STORE_U8(r30.u32 + 307, ctx.r10.u8);
loc_824A1B2C:
	// stb r23,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r23.u8);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r23,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r23.u32);
	// beq cr6,0x824a1e8c
	if (cr6.eq) goto loc_824A1E8C;
	// li r12,-32768
	r12.s64 = -32768;
	// bl 0x823dbff4
	ctx.lr = 0x824A1B44;
	sub_823DBFF4(ctx, base);
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// li r12,-8192
	r12.s64 = -8192;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r3,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r3.u32);
	// bl 0x823dbff4
	ctx.lr = 0x824A1B5C;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// addi r22,r1,192
	r22.s64 = ctx.r1.s64 + 192;
	// bl 0x8244d150
	ctx.lr = 0x824A1B78;
	sub_8244D150(ctx, base);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8244d150
	ctx.lr = 0x824A1B88;
	sub_8244D150(ctx, base);
	// lbz r9,303(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// li r20,0
	r20.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r27,212(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// beq cr6,0x824a1e8c
	if (cr6.eq) goto loc_824A1E8C;
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lwz r26,200(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// subf r17,r22,r11
	r17.s64 = r11.s64 - r22.s64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// mr r25,r22
	r25.u64 = r22.u64;
	// li r18,80
	r18.s64 = 80;
	// addi r19,r11,-31664
	r19.s64 = r11.s64 + -31664;
	// addi r24,r10,2352
	r24.s64 = ctx.r10.s64 + 2352;
	// addi r23,r9,2384
	r23.s64 = ctx.r9.s64 + 2384;
	// addi r16,r8,2256
	r16.s64 = ctx.r8.s64 + 2256;
loc_824A1BD0:
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r9,r31,197
	ctx.r9.s64 = r31.s64 + 197;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r8,r31,196
	ctx.r8.s64 = r31.s64 + 196;
	// addi r7,r31,198
	ctx.r7.s64 = r31.s64 + 198;
	// addi r6,r31,195
	ctx.r6.s64 = r31.s64 + 195;
	// addi r5,r31,193
	ctx.r5.s64 = r31.s64 + 193;
	// lhz r10,14(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 14);
	// addi r4,r31,194
	ctx.r4.s64 = r31.s64 + 194;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// extsh r29,r10
	r29.s64 = ctx.r10.s16;
	// mulli r10,r29,224
	ctx.r10.s64 = r29.s64 * 224;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8249cc20
	ctx.lr = 0x824A1C08;
	sub_8249CC20(ctx, base);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x824a1dbc
	if (cr6.eq) goto loc_824A1DBC;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a1c2c
	if (cr6.eq) goto loc_824A1C2C;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r14
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r14.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x824a1dbc
	if (cr6.eq) goto loc_824A1DBC;
loc_824A1C2C:
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r14
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r14.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x824a1cb8
	if (!cr6.eq) goto loc_824A1CB8;
	// lbz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 12);
	// mr r7,r15
	ctx.r7.u64 = r15.u64;
loc_824A1C44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824a1ca0
	if (cr6.eq) goto loc_824A1CA0;
	// cmpwi cr6,r9,255
	cr6.compare<int32_t>(ctx.r9.s32, 255, xer);
	// beq cr6,0x824a1ca0
	if (cr6.eq) goto loc_824A1CA0;
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,212(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lbz r5,70(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 70);
	// rotlwi r4,r5,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r3,r4,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lhz r10,14(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r14
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r14.u32);
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x824a1c90
	if (cr6.eq) goto loc_824A1C90;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// b 0x824a1c94
	goto loc_824A1C94;
loc_824A1C90:
	// lbz r9,69(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 69);
loc_824A1C94:
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// beq cr6,0x824a1c44
	if (cr6.eq) goto loc_824A1C44;
	// b 0x824a1cac
	goto loc_824A1CAC;
loc_824A1CA0:
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// bne cr6,0x824a1cac
	if (!cr6.eq) goto loc_824A1CAC;
	// li r7,0
	ctx.r7.s64 = 0;
loc_824A1CAC:
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r14
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r14.u32);
	// stwx r10,r8,r14
	PPC_STORE_U32(ctx.r8.u32 + r14.u32, ctx.r10.u32);
loc_824A1CB8:
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r10,r31,228
	ctx.r10.s64 = r31.s64 + 228;
	// lwzx r11,r8,r14
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r14.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r10,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r10.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,144(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 144);
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// stfs f0,224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// addi r11,r10,128
	r11.s64 = ctx.r10.s64 + 128;
	// lwz r28,200(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// lfsx f13,r4,r22
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r22.u32);
	ctx.f13.f64 = double(temp.f32);
	// li r5,48
	ctx.r5.s64 = 48;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// lwz r4,192(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	// stfs f13,228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// lvlx128 v34,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r29,r31,220
	r29.s64 = r31.s64 + 220;
	// lvx128 v47,r11,r3
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lvx128 v51,r11,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r9,r28
	ctx.r10.u64 = ctx.r9.u64 + r28.u64;
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r11,r5
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v50,v51
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// lvx128 v45,r4,r18
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v44,v47,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vand128 v43,v45,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v46,v50,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v42,v47,v49
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// lvlx128 v33,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v33,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// lvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v39,v62,v43
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vmrglw128 v40,v48,v44
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v38,v46,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vrefp128 v0,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v63.f32)));
	// vmrghw128 v37,v48,v44
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmsum4fp128 v36,v39,v40
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// lvx128 v13,r0,r19
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v35,v39,v38
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// vspltw128 v12,v34,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vmsum4fp128 v32,v39,v37
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v37.f32), 0xFF));
	// vmulfp128 v10,v41,v61
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v61.f32)));
	// vnmsubfp v7,v0,v11,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmrghw128 v60,v36,v39
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v59,v32,v35
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmaddfp v5,v0,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmrghw128 v8,v59,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmaddfp v6,v8,v12,v10
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmulfp128 v58,v6,v5
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r8,r14
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r14.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r22
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r22.u32, temp.u32);
	// b 0x824a1e78
	goto loc_824A1E78;
loc_824A1DBC:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r20,r17,r25
	PPC_STORE_U32(r17.u32 + r25.u32, r20.u32);
	// stwx r21,r11,r14
	PPC_STORE_U32(r11.u32 + r14.u32, r21.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r11,192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// bne cr6,0x824a1de4
	if (!cr6.eq) goto loc_824A1DE4;
	// mr r11,r16
	r11.u64 = r16.u64;
loc_824A1DE4:
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v57,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// vor128 v56,v57,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v56,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,144(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 144);
	// vor128 v54,v62,v55
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r11,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v51,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v49,v53,v50
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v47,v53,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v46,v51,v52
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrglw128 v45,v49,v48
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v44,v49,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v43,v47,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmsum4fp128 v42,v54,v45
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v45.f32), 0xFF));
	// vmsum4fp128 v41,v54,v44
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v40,v54,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrghw128 v39,v42,v54
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v41,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v38,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// stvx128 v37,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
loc_824A1E78:
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r20,r11
	cr6.compare<uint32_t>(r20.u32, r11.u32, xer);
	// blt cr6,0x824a1bd0
	if (cr6.lt) goto loc_824A1BD0;
loc_824A1E8C:
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// li r21,0
	r21.s64 = 0;
	// lwz r29,212(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2414
	if (cr6.eq) goto loc_824A2414;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r22,0
	r22.s64 = 0;
	// li r20,0
	r20.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// li r19,128
	r19.s64 = 128;
	// addi r18,r11,-31584
	r18.s64 = r11.s64 + -31584;
	// addi r17,r10,1024
	r17.s64 = ctx.r10.s64 + 1024;
loc_824A1EC4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r26,16
	r26.s64 = 16;
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// li r24,32
	r24.s64 = 32;
	// li r23,48
	r23.s64 = 48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lhz r28,14(r11)
	r28.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// beq cr6,0x824a1fd0
	if (cr6.eq) goto loc_824A1FD0;
	// lwz r11,236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// extsh r10,r28
	ctx.r10.s64 = r28.s16;
	// lwz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r8,r31,288
	ctx.r8.s64 = r31.s64 + 288;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r7,r31,304
	ctx.r7.s64 = r31.s64 + 304;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r6,r31,320
	ctx.r6.s64 = r31.s64 + 320;
	// addi r5,r31,336
	ctx.r5.s64 = r31.s64 + 336;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r4,r31,288
	ctx.r4.s64 = r31.s64 + 288;
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r10,r23
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r10,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r11,r26
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v34,v36,0
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0xFF));
	// lvx128 v33,r11,r24
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v32,v35,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0xFF));
	// lvx128 v63,r11,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v62,v33,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// vspltw128 v11,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmulfp128 v10,v0,v34
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v34.f32)));
	// vspltw128 v9,v36,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0xAA));
	// vmulfp128 v8,v0,v32
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v32.f32)));
	// vspltw128 v7,v35,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0xAA));
	// vmulfp128 v6,v0,v62
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vspltw128 v5,v33,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xAA));
	// vmaddfp v4,v0,v11,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v3,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v2,v36,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0x55));
	// lvx128 v0,r10,r24
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v35,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x55));
	// vspltw128 v31,v33,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0x55));
	// vspltw128 v30,v63,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vmaddfp v29,v13,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v13,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v13,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v13,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v13,v0,v2,v29
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v12,v0,v1,v28
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v11,v0,v31,v27
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v0,v0,v30,v26
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821713c0
	ctx.lr = 0x824A1FC0;
	sub_821713C0(ctx, base);
	// lbz r11,306(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 306);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stb r4,306(r30)
	PPC_STORE_U8(r30.u32 + 306, ctx.r4.u8);
	// b 0x824a2004
	goto loc_824A2004;
loc_824A1FD0:
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// vupkd3d128 v60,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v60 = vTemp;
	// vpermwi128 v59,v60,234
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x15));
	// vpermwi128 v58,v60,186
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x45));
	// vpermwi128 v57,v60,174
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x51));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824A2004:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a22d4
	if (cr6.eq) goto loc_824A22D4;
	// extsh r28,r28
	r28.s64 = r28.s16;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r31,194
	ctx.r9.s64 = r31.s64 + 194;
	// mulli r10,r28,224
	ctx.r10.s64 = r28.s64 * 224;
	// addi r8,r31,193
	ctx.r8.s64 = r31.s64 + 193;
	// addi r7,r31,195
	ctx.r7.s64 = r31.s64 + 195;
	// addi r6,r31,198
	ctx.r6.s64 = r31.s64 + 198;
	// addi r5,r31,196
	ctx.r5.s64 = r31.s64 + 196;
	// addi r4,r31,197
	ctx.r4.s64 = r31.s64 + 197;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8249cc20
	ctx.lr = 0x824A203C;
	sub_8249CC20(ctx, base);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824a20b0
	if (cr6.eq) goto loc_824A20B0;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2060
	if (cr6.eq) goto loc_824A2060;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r14
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r14.u32);
	// cmpw cr6,r10,r21
	cr6.compare<int32_t>(ctx.r10.s32, r21.s32, xer);
	// bne cr6,0x824a20b0
	if (!cr6.eq) goto loc_824A20B0;
loc_824A2060:
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,204(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// lwz r8,212(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lwzx r7,r10,r14
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r14.u32);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// addi r10,r10,80
	ctx.r10.s64 = ctx.r10.s64 + 80;
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r10,r26
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r24
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r10,r23
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824a2164
	goto loc_824A2164;
loc_824A20B0:
	// vspltisw128 v52,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// vupkd3d128 v51,v52,4
	temp.f32 = 3.0f;
	temp.s32 += v52.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v52.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v51 = vTemp;
	// lwzx r21,r10,r14
	r21.u64 = PPC_LOAD_U32(ctx.r10.u32 + r14.u32);
	// vpermwi128 v50,v51,234
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x15));
	// vpermwi128 v49,v51,186
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x45));
	// vpermwi128 v48,v51,174
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x51));
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,144(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 144);
	// lwz r8,192(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x824a2164
	if (cr6.eq) goto loc_824A2164;
	// lwz r8,200(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// rlwinm r7,r21,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// lvx128 v47,r11,r23
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r7,r8
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v46,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r11,r26
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r11,r24
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r10,r23
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r10,r26
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r10,r24
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v37,v43,v45
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmsum3fp128 v36,v42,v45
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmsum3fp128 v35,v44,v45
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmrghw128 v34,v37,v37
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v33,v35,v36
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v32,v33,v34
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vsubfp128 v63,v32,v41
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v41.f32)));
	// vmsum3fp128 v62,v39,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v61,v38,v63
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v60,v40,v63
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmrghw128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v58,v60,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v57,v58,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// stvx128 v57,r9,r19
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824A2164:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// vspltisw128 v56,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r10,248(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r26
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r24
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r10,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r23
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r10,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v47,v51,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmsum3fp128 v46,v50,v48
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmrghw128 v45,v51,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmsum3fp128 v44,v49,v48
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmrghw128 v43,v49,v48
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrglw128 v42,v49,v48
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrglw128 v41,v51,v50
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v40,v45,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v39,v45,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v38,v41,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v37,v47,v46
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v36,v44,v37
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v35,v37,v36
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vor128 v34,v35,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v33,v56,v34
	simde_mm_store_ps(v33.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v34.f32)));
	// stvx128 v33,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 248);
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r10,80
	ctx.r10.s64 = ctx.r10.s64 + 80;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// lvx128 v63,r10,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,32
	ctx.r7.s64 = r11.s64 + 32;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r10,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// lvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r10,r23
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v56,v58,v57
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// vmsum3fp128 v55,v62,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v54,v62,v60
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v53,v62,v59
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v52,v61,v63
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v51,v61,v60
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v50,v61,v59
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v49,v56,v63
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v48,v56,v60
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v47,v56,v59
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v46,v32,v59
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v45,v32,v63
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v44,v32,v60
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmrghw128 v43,v54,v55
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v42,v53,v62
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v41,v51,v52
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v40,v50,v61
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v39,v43,v42
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v38,v48,v49
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v37,v47,v58
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v36,v41,v40
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v34,v46,v32
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v35,v38,v37
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v33,v44,v45
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v32,v33,v34
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// stvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824a22d4
	if (cr6.eq) goto loc_824A22D4;
	// lbz r11,307(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 307);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stb r10,307(r30)
	PPC_STORE_U8(r30.u32 + 307, ctx.r10.u8);
loc_824A22D4:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// lwz r11,144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a23a4
	if (cr6.eq) goto loc_824A23A4;
	// lwz r9,236(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// lwz r8,128(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwzx r28,r8,r20
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + r20.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824a2310
	if (cr6.eq) goto loc_824A2310;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2370
	if (cr6.eq) goto loc_824A2370;
	// lwz r11,148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// b 0x824a2364
	goto loc_824A2364;
loc_824A2310:
	// lwz r28,192(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x824a23a4
	if (cr6.eq) goto loc_824A23A4;
	// lbz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824a2348
	if (!cr6.eq) goto loc_824A2348;
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x824a2348
	if (!cr6.eq) goto loc_824A2348;
	// li r11,1
	r11.s64 = 1;
	// lwz r4,176(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// stb r11,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r11.u8);
	// bl 0x82130000
	ctx.lr = 0x824A2348;
	sub_82130000(ctx, base);
loc_824A2348:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82599f48
	ctx.lr = 0x824A235C;
	sub_82599F48(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,148(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
loc_824A2364:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2370
	if (cr6.eq) goto loc_824A2370;
	// lwz r26,192(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 192);
loc_824A2370:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824a23a4
	if (cr6.eq) goto loc_824A23A4;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lfs f1,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A2394;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,240(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r22,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824a23b0
	goto loc_824A23B0;
loc_824A23A4:
	// lwz r11,240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r22,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824A23B0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824a23e8
	if (cr6.eq) goto loc_824A23E8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824A23D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,244(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r22,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824a23f4
	goto loc_824A23F4;
loc_824A23E8:
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r22,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824A23F4:
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,64
	r27.s64 = r27.s64 + 64;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r22,r22,16
	r22.s64 = r22.s64 + 16;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x824a1ec4
	if (cr6.lt) goto loc_824A1EC4;
loc_824A2414:
	// bl 0x821bbea8
	ctx.lr = 0x824A2418;
	sub_821BBEA8(ctx, base);
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// bl 0x82130588
	ctx.lr = 0x824A2420;
	sub_82130588(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82130588
	ctx.lr = 0x824A2428;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x824A242C;
	sub_821BBF00(ctx, base);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a24a8
	if (cr6.eq) goto loc_824A24A8;
	// lwz r8,240(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// addi r10,r8,8
	ctx.r10.s64 = ctx.r8.s64 + 8;
	// lbz r9,303(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - r11.s64;
loc_824A2450:
	// lfsx f13,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fsel f6,f12,f0,f13
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fsel f4,f5,f6,f11
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f11.f64;
	// fsubs f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// fsel f2,f3,f4,f10
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f10.f64;
	// fsubs f1,f2,f9
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f9.f64));
	// fsel f0,f1,f2,f9
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : ctx.f9.f64;
	// fsubs f13,f0,f8
	ctx.f13.f64 = double(float(f0.f64 - ctx.f8.f64));
	// fsel f12,f13,f0,f8
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f8.f64;
	// fsubs f11,f12,f7
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fsel f0,f11,f12,f7
	f0.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f7.f64;
	// bne 0x824a2450
	if (!cr0.eq) goto loc_824A2450;
loc_824A24A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,307(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 307);
	// stfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// lwz r3,236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f13,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// beq cr6,0x824a24f8
	if (cr6.eq) goto loc_824A24F8;
	// lwz r29,200(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x825832c8
	ctx.lr = 0x824A24DC;
	sub_825832C8(ctx, base);
	// li r11,32
	r11.s64 = 32;
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v61,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824a2500
	goto loc_824A2500;
loc_824A24F8:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8259a580
	ctx.lr = 0x824A2500;
	sub_8259A580(ctx, base);
loc_824A2500:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8249dc08
	ctx.lr = 0x824A2508;
	sub_8249DC08(ctx, base);
	// lwz r3,236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// bl 0x8259a740
	ctx.lr = 0x824A2510;
	sub_8259A740(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// bl 0x8259ada8
	ctx.lr = 0x824A251C;
	sub_8259ADA8(ctx, base);
	// lwz r4,236(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// bl 0x8258e6b8
	ctx.lr = 0x824A2528;
	sub_8258E6B8(ctx, base);
	// lbz r8,303(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// li r9,0
	ctx.r9.s64 = 0;
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// rlwinm r12,r6,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x824A2540;
	sub_823DBFF4(ctx, base);
	// lwz r5,0(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stwux r5,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r1.u32 = ea;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// beq cr6,0x824a2594
	if (cr6.eq) goto loc_824A2594;
	// li r11,0
	r11.s64 = 0;
loc_824A255C:
	// lwz r8,212(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfsx f0,r4,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, temp.u32);
	// lwz r6,144(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 144);
	// lwz r5,192(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 192);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x824a2580
	if (!cr6.eq) goto loc_824A2580;
	// li r9,1
	ctx.r9.s64 = 1;
loc_824A2580:
	// lbz r8,303(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x824a255c
	if (cr6.lt) goto loc_824A255C;
loc_824A2594:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a25ac
	if (!cr6.eq) goto loc_824A25AC;
	// lwz r5,240(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// bl 0x8258e7f0
	ctx.lr = 0x824A25AC;
	sub_8258E7F0(ctx, base);
loc_824A25AC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r8,16383
	ctx.r8.s64 = 1073676288;
	// li r15,16
	r15.s64 = 16;
	// li r25,0
	r25.s64 = 0;
	// ori r24,r8,65535
	r24.u64 = ctx.r8.u64 | 65535;
	// lbz r10,18244(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 18244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a25f4
	if (cr6.eq) goto loc_824A25F4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r9,228(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r11,19620(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// lwz r7,768(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// lwz r11,19620(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// lwz r6,228(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r5,772(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// stw r5,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r5.u32);
	// b 0x824a27e4
	goto loc_824A27E4;
loc_824A25F4:
	// lwz r11,228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// lwz r7,228(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// stw r9,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r9.u32);
	// b 0x824a27e4
	goto loc_824A27E4;
loc_824A2610:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a27e4
	if (cr6.eq) goto loc_824A27E4;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lwz r9,192(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x824a2660
	if (!cr6.eq) goto loc_824A2660;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,1624
	ctx.r3.s64 = r11.s64 + 1624;
	// bl 0x82130000
	ctx.lr = 0x824A2640;
	sub_82130000(ctx, base);
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614a50
	ctx.lr = 0x824A2648;
	sub_82614A50(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_824A2660:
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x824A2668;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2678
	if (cr6.eq) goto loc_824A2678;
	// bl 0x8258f620
	ctx.lr = 0x824A2674;
	sub_8258F620(ctx, base);
	// b 0x824a267c
	goto loc_824A267C;
loc_824A2678:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A267C:
	// stw r3,228(r30)
	PPC_STORE_U32(r30.u32 + 228, ctx.r3.u32);
	// lis r28,-32112
	r28.s64 = -2104492032;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lbz r11,-2084(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -2084);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a26a0
	if (cr6.eq) goto loc_824A26A0;
	// lhz r11,26(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r11.u16);
loc_824A26A0:
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a26c0
	if (cr6.eq) goto loc_824A26C0;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x824A26B4;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x824a26c4
	if (!cr6.eq) goto loc_824A26C4;
loc_824A26C0:
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_824A26C4:
	// lwz r10,228(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r9,228(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lfs f0,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 324);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 60, temp.u32);
	// lwz r8,200(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r4,192(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 192);
	// bl 0x8258e6b8
	ctx.lr = 0x824A26EC;
	sub_8258E6B8(ctx, base);
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r6,200(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,48(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x824A2708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r3,768(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// lwz r11,228(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// stw r3,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r3.u32);
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r10,228(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r9,772(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,200(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r7,148(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 148);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824a27e4
	if (cr6.eq) goto loc_824A27E4;
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x824A2744;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2754
	if (cr6.eq) goto loc_824A2754;
	// bl 0x8258f620
	ctx.lr = 0x824A2750;
	sub_8258F620(ctx, base);
	// b 0x824a2758
	goto loc_824A2758;
loc_824A2754:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A2758:
	// stw r3,232(r30)
	PPC_STORE_U32(r30.u32 + 232, ctx.r3.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lbz r11,-2084(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -2084);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2778
	if (cr6.eq) goto loc_824A2778;
	// lhz r11,26(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r11.u16);
loc_824A2778:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,232(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// bl 0x824896e8
	ctx.lr = 0x824A2784;
	sub_824896E8(ctx, base);
	// stw r3,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r3.u32);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lfs f0,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 324);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// lwz r10,200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r3,232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,148(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// lwz r4,192(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// bl 0x8258e6b8
	ctx.lr = 0x824A27A8;
	sub_8258E6B8(ctx, base);
	// lwz r3,232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,200(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824A27C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r4,228(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r5,768(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// stw r5,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r5.u32);
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// lwz r11,772(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
loc_824A27E4:
	// lwz r11,180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// lfs f0,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x824a2804
	if (!cr6.gt) goto loc_824A2804;
	// lvx128 v59,r11,r15
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	f0.f64 = double(temp.f32);
	// b 0x824a2860
	goto loc_824A2860;
loc_824A2804:
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2824
	if (cr6.eq) goto loc_824A2824;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lvx128 v58,r10,r15
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r30,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// b 0x824a285c
	goto loc_824A285C;
loc_824A2824:
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,70(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwz r5,144(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 144);
	// lvx128 v57,r5,r15
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r30,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r3,70(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 70);
	// rotlwi r11,r3,2
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
loc_824A285C:
	// lfs f0,112(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	f0.f64 = double(temp.f32);
loc_824A2860:
	// stfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
	// lbz r11,303(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 303);
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x82130528
	ctx.lr = 0x824A2870;
	sub_82130528(ctx, base);
	// stw r3,252(r30)
	PPC_STORE_U32(r30.u32 + 252, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8249d240
	ctx.lr = 0x824A2884;
	sub_8249D240(ctx, base);
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x824a289c
	if (!cr6.gt) goto loc_824A289C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824A289C:
	// bl 0x82130528
	ctx.lr = 0x824A28A0;
	sub_82130528(ctx, base);
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// stw r3,204(r30)
	PPC_STORE_U32(r30.u32 + 204, ctx.r3.u32);
	// mr r28,r25
	r28.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a28f0
	if (cr6.eq) goto loc_824A28F0;
	// mr r29,r25
	r29.u64 = r25.u64;
loc_824A28B8:
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,204(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// addi r9,r11,84
	ctx.r9.s64 = r11.s64 + 84;
	// stwx r9,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, ctx.r9.u32);
	// lwz r8,208(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwzx r3,r29,r8
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	// bl 0x824d0d10
	ctx.lr = 0x824A28DC;
	sub_824D0D10(ctx, base);
	// lbz r7,302(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r7
	cr6.compare<int32_t>(r28.s32, ctx.r7.s32, xer);
	// blt cr6,0x824a28b8
	if (cr6.lt) goto loc_824A28B8;
loc_824A28F0:
	// lbz r11,302(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 302);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r9,204(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r10,472
	ctx.r7.s64 = ctx.r10.s64 + 472;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2924
	if (cr6.eq) goto loc_824A2924;
	// lhz r11,236(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824a2928
	if (!cr6.eq) goto loc_824A2928;
loc_824A2924:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_824A2928:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2980
	if (cr6.eq) goto loc_824A2980;
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824a2980
	if (cr6.eq) goto loc_824A2980;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x824A2948;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2958
	if (cr6.eq) goto loc_824A2958;
	// bl 0x82519b70
	ctx.lr = 0x824A2954;
	sub_82519B70(ctx, base);
	// b 0x824a295c
	goto loc_824A295C;
loc_824A2958:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824A295C:
	// stw r3,276(r30)
	PPC_STORE_U32(r30.u32 + 276, ctx.r3.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82527b48
	ctx.lr = 0x824A2980;
	sub_82527B48(ctx, base);
loc_824A2980:
	// addi r3,r31,2672
	ctx.r3.s64 = r31.s64 + 2672;
	// bl 0x82614a50
	ctx.lr = 0x824A2988;
	sub_82614A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824A29A0"))) PPC_WEAK_FUNC(sub_824A29A0);
PPC_FUNC_IMPL(__imp__sub_824A29A0) {
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
	ctx.lr = 0x824A29A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// xori r26,r10,1
	r26.u64 = ctx.r10.u64 ^ 1;
	// beq cr6,0x824a2a1c
	if (cr6.eq) goto loc_824A2A1C;
	// bl 0x821bbea8
	ctx.lr = 0x824A29D8;
	sub_821BBEA8(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824a2a04
	if (!cr6.eq) goto loc_824A2A04;
	// li r3,336
	ctx.r3.s64 = 336;
	// bl 0x82130528
	ctx.lr = 0x824A29E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2a00
	if (cr6.eq) goto loc_824A2A00;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8249ee08
	ctx.lr = 0x824A29F8;
	sub_8249EE08(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x824a2a04
	goto loc_824A2A04;
loc_824A2A00:
	// li r28,0
	r28.s64 = 0;
loc_824A2A04:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824a0d88
	ctx.lr = 0x824A2A18;
	sub_824A0D88(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x824A2A1C;
	sub_821BBF00(ctx, base);
loc_824A2A1C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824a2a48
	if (!cr6.eq) goto loc_824A2A48;
	// li r3,336
	ctx.r3.s64 = 336;
	// bl 0x82130528
	ctx.lr = 0x824A2A2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2a44
	if (cr6.eq) goto loc_824A2A44;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8249ee08
	ctx.lr = 0x824A2A3C;
	sub_8249EE08(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x824a2a48
	goto loc_824A2A48;
loc_824A2A44:
	// li r29,0
	r29.s64 = 0;
loc_824A2A48:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824A2A4C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824a2a4c
	if (!cr6.eq) goto loc_824A2A4C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// bl 0x82130528
	ctx.lr = 0x824A2A74;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_824A2A78:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x824a2a78
	if (!cr6.eq) goto loc_824A2A78;
	// stw r11,176(r29)
	PPC_STORE_U32(r29.u32 + 176, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824a0d88
	ctx.lr = 0x824A2AA8;
	sub_824A0D88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2ac4
	if (!cr6.eq) goto loc_824A2AC4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,1800
	ctx.r3.s64 = r11.s64 + 1800;
	// bl 0x82130000
	ctx.lr = 0x824A2AC4;
	sub_82130000(ctx, base);
loc_824A2AC4:
	// lwz r10,180(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824a2ad8
	if (cr6.eq) goto loc_824A2AD8;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_824A2AD8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// beq cr6,0x824a2b1c
	if (cr6.eq) goto loc_824A2B1C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8249dca0
	ctx.lr = 0x824A2AEC;
	sub_8249DCA0(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2b18
	if (!cr6.eq) goto loc_824A2B18;
	// bl 0x821bbea8
	ctx.lr = 0x824A2AFC;
	sub_821BBEA8(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824A2B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x821bbf00
	ctx.lr = 0x824A2B18;
	sub_821BBF00(ctx, base);
loc_824A2B18:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_824A2B1C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824A2B24"))) PPC_WEAK_FUNC(sub_824A2B24);
PPC_FUNC_IMPL(__imp__sub_824A2B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A2B28"))) PPC_WEAK_FUNC(sub_824A2B28);
PPC_FUNC_IMPL(__imp__sub_824A2B28) {
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
	ctx.lr = 0x824A2B30;
	// stwu r1,-2320(r1)
	ea = -2320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r10,-13284
	ctx.r5.s64 = ctx.r10.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x821ca6a8
	ctx.lr = 0x824A2B64;
	sub_821CA6A8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x824A2B78;
	sub_82183870(ctx, base);
	// li r4,47
	ctx.r4.s64 = 47;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db6d0
	ctx.lr = 0x824A2B84;
	sub_823DB6D0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stb r29,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r29.u8);
loc_824A2B90:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// lbzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stbx r8,r11,r9
	PPC_STORE_U8(r11.u32 + ctx.r9.u32, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x824a2b90
	if (!cr6.eq) goto loc_824A2B90;
	// li r4,47
	ctx.r4.s64 = 47;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x823db6d0
	ctx.lr = 0x824A2BB8;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a2bcc
	if (cr6.eq) goto loc_824A2BCC;
	// stb r29,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r29.u8);
	// addi r24,r3,1
	r24.s64 = ctx.r3.s64 + 1;
	// b 0x824a2bd0
	goto loc_824A2BD0;
loc_824A2BCC:
	// addi r24,r1,336
	r24.s64 = ctx.r1.s64 + 336;
loc_824A2BD0:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824a2be4
	if (!cr6.eq) goto loc_824A2BE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,2320
	ctx.r1.s64 = ctx.r1.s64 + 2320;
	// b 0x823d922c
	return;
loc_824A2BE4:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r29,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, r29.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r25,r11,-29924
	r25.s64 = r11.s64 + -29924;
	// lwz r11,19684(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19684);
	// stw r25,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2c10
	if (cr6.eq) goto loc_824A2C10;
	// lwz r4,580(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 580);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x824a2c18
	if (!cr6.eq) goto loc_824A2C18;
loc_824A2C10:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r11,1952
	ctx.r4.s64 = r11.s64 + 1952;
loc_824A2C18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x824A2C20;
	sub_821CA540(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,1944
	ctx.r5.s64 = r11.s64 + 1944;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x824A2C3C;
	sub_821CA6A8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r9,r10,29968
	ctx.r9.s64 = ctx.r10.s64 + 29968;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a2cf4
	if (cr6.eq) goto loc_824A2CF4;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824a2cf4
	if (cr6.eq) goto loc_824A2CF4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,2828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// bl 0x821c00e8
	ctx.lr = 0x824A2C6C;
	sub_821C00E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x821bbea8
	ctx.lr = 0x824A2C74;
	sub_821BBEA8(ctx, base);
	// lis r3,80
	ctx.r3.s64 = 5242880;
	// bl 0x82130528
	ctx.lr = 0x824A2C7C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821bbf00
	ctx.lr = 0x824A2C84;
	sub_821BBF00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lis r5,80
	ctx.r5.s64 = 5242880;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x824A2C94;
	sub_823D9890(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r8,r10,3998
	ctx.r8.s64 = ctx.r10.s64 + 3998;
	// lis r6,80
	ctx.r6.s64 = 5242880;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,1712
	ctx.r3.s64 = ctx.r1.s64 + 1712;
	// bl 0x821cb740
	ctx.lr = 0x824A2CB4;
	sub_821CB740(ctx, base);
	// bl 0x821cad70
	ctx.lr = 0x824A2CB8;
	sub_821CAD70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,1712
	ctx.r3.s64 = ctx.r1.s64 + 1712;
	// bl 0x821be1d0
	ctx.lr = 0x824A2CC4;
	sub_821BE1D0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824d7bb0
	ctx.lr = 0x824A2CD0;
	sub_824D7BB0(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824a2ce8
	if (cr6.eq) goto loc_824A2CE8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c5c70
	ctx.lr = 0x824A2CE0;
	sub_821C5C70(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x824A2CE8;
	sub_82130588(ctx, base);
loc_824A2CE8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x824A2CF0;
	sub_821BE610(ctx, base);
	// b 0x824a2d14
	goto loc_824A2D14;
loc_824A2CF4:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,1936
	ctx.r5.s64 = r11.s64 + 1936;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x824A2D10;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_824A2D14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824A2D1C;
	sub_821C9A90(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r29,1696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1696, r29.u32);
	// addi r3,r11,1900
	ctx.r3.s64 = r11.s64 + 1900;
	// stw r25,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r25.u32);
	// bl 0x82130000
	ctx.lr = 0x824A2D34;
	sub_82130000(ctx, base);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x821cf7b8
	ctx.lr = 0x824A2D44;
	sub_821CF7B8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824a2d70
	if (cr6.eq) goto loc_824A2D70;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,1868
	ctx.r3.s64 = r11.s64 + 1868;
	// bl 0x82130000
	ctx.lr = 0x824A2D5C;
	sub_82130000(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// bl 0x821cf7b8
	ctx.lr = 0x824A2D6C;
	sub_821CF7B8(ctx, base);
	// addi r29,r1,1152
	r29.s64 = ctx.r1.s64 + 1152;
loc_824A2D70:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,1968
	ctx.r3.s64 = ctx.r1.s64 + 1968;
	// bl 0x821ca980
	ctx.lr = 0x824A2D80;
	sub_821CA980(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r1,1968
	ctx.r4.s64 = ctx.r1.s64 + 1968;
	// bl 0x821ca540
	ctx.lr = 0x824A2D8C;
	sub_821CA540(ctx, base);
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x824a29a0
	ctx.lr = 0x824A2DA4;
	sub_824A29A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824A2DB0;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824a2dc0
	if (cr6.eq) goto loc_824A2DC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x824A2DC0;
	sub_821BE610(ctx, base);
loc_824A2DC0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r10.u32);
	// stw r10,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r10.u32);
	// bl 0x821be610
	ctx.lr = 0x824A2DD8;
	sub_821BE610(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,2320
	ctx.r1.s64 = ctx.r1.s64 + 2320;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824A2DE4"))) PPC_WEAK_FUNC(sub_824A2DE4);
PPC_FUNC_IMPL(__imp__sub_824A2DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A2DE8"))) PPC_WEAK_FUNC(sub_824A2DE8);
PPC_FUNC_IMPL(__imp__sub_824A2DE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20692(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20692);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A2DF4"))) PPC_WEAK_FUNC(sub_824A2DF4);
PPC_FUNC_IMPL(__imp__sub_824A2DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A2DF8"))) PPC_WEAK_FUNC(sub_824A2DF8);
PPC_FUNC_IMPL(__imp__sub_824A2DF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f12,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x824a2e20
	if (cr6.lt) goto loc_824A2E20;
	// li r11,0
	r11.s64 = 0;
loc_824A2E20:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824a2e74
	if (cr6.eq) goto loc_824A2E74;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x824a2e44
	if (cr6.lt) goto loc_824A2E44;
	// li r11,0
	r11.s64 = 0;
loc_824A2E44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2ea8
	if (!cr6.eq) goto loc_824A2EA8;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824a2e60
	if (cr6.lt) goto loc_824A2E60;
	// li r11,0
	r11.s64 = 0;
loc_824A2E60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824A2E6C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_824A2E74:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x824a2e80
	if (cr6.lt) goto loc_824A2E80;
	// li r11,0
	r11.s64 = 0;
loc_824A2E80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2e6c
	if (!cr6.eq) goto loc_824A2E6C;
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824a2e9c
	if (cr6.lt) goto loc_824A2E9C;
	// li r11,0
	r11.s64 = 0;
loc_824A2E9C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824A2EA8:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A2EB0"))) PPC_WEAK_FUNC(sub_824A2EB0);
PPC_FUNC_IMPL(__imp__sub_824A2EB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r6
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwzx r5,r8,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lfs f12,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x824a2ee8
	if (cr6.gt) goto loc_824A2EE8;
	// li r11,0
	r11.s64 = 0;
loc_824A2EE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r8,r9,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824a2f44
	if (cr6.eq) goto loc_824A2F44;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x824a2f14
	if (cr6.gt) goto loc_824A2F14;
	// li r11,0
	r11.s64 = 0;
loc_824A2F14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2f78
	if (!cr6.eq) goto loc_824A2F78;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x824a2f30
	if (cr6.gt) goto loc_824A2F30;
	// li r11,0
	r11.s64 = 0;
loc_824A2F30:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824A2F3C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_824A2F44:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x824a2f50
	if (cr6.gt) goto loc_824A2F50;
	// li r11,0
	r11.s64 = 0;
loc_824A2F50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a2f3c
	if (!cr6.eq) goto loc_824A2F3C;
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x824a2f6c
	if (cr6.gt) goto loc_824A2F6C;
	// li r11,0
	r11.s64 = 0;
loc_824A2F6C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824A2F78:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A2F80"))) PPC_WEAK_FUNC(sub_824A2F80);
PPC_FUNC_IMPL(__imp__sub_824A2F80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r3,-4
	r11.s64 = ctx.r3.s64 + -4;
loc_824A2F88:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r9,r8,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwzx r6,r7,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// lfs f13,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a2fb0
	if (cr6.gt) goto loc_824A2FB0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824A2FB0:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824a2fcc
	if (cr6.eq) goto loc_824A2FCC;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// b 0x824a2f88
	goto loc_824A2F88;
loc_824A2FCC:
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A2FD4"))) PPC_WEAK_FUNC(sub_824A2FD4);
PPC_FUNC_IMPL(__imp__sub_824A2FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A2FD8"))) PPC_WEAK_FUNC(sub_824A2FD8);
PPC_FUNC_IMPL(__imp__sub_824A2FD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// ble cr6,0x824a3038
	if (!cr6.gt) goto loc_824A3038;
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
loc_824A2FF0:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x824a300c
	if (cr6.lt) goto loc_824A300C;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824A300C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824a3038
	if (cr6.eq) goto loc_824A3038;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	r11.s64 = temp.s64;
	// bgt cr6,0x824a2ff0
	if (cr6.gt) goto loc_824A2FF0;
loc_824A3038:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A3044"))) PPC_WEAK_FUNC(sub_824A3044);
PPC_FUNC_IMPL(__imp__sub_824A3044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3048"))) PPC_WEAK_FUNC(sub_824A3048);
PPC_FUNC_IMPL(__imp__sub_824A3048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// ble cr6,0x824a30bc
	if (!cr6.gt) goto loc_824A30BC;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_824A3064:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r8,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x824a3090
	if (cr6.gt) goto loc_824A3090;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824A3090:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824a30bc
	if (cr6.eq) goto loc_824A30BC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srawi r11,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	r11.s64 = r31.s32 >> 1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// bgt cr6,0x824a3064
	if (cr6.gt) goto loc_824A3064;
loc_824A30BC:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r6.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A30CC"))) PPC_WEAK_FUNC(sub_824A30CC);
PPC_FUNC_IMPL(__imp__sub_824A30CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A30D0"))) PPC_WEAK_FUNC(sub_824A30D0);
PPC_FUNC_IMPL(__imp__sub_824A30D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,0
	r11.s64 = 0;
	// ori r7,r11,65535
	ctx.r7.u64 = r11.u64 | 65535;
loc_824A30E8:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r8,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplw cr6,r5,r6
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// bne cr6,0x824a3150
	if (!cr6.eq) goto loc_824A3150;
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x824a3140
	if (!cr6.lt) goto loc_824A3140;
loc_824A3114:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x824a3114
	if (cr6.lt) goto loc_824A3114;
loc_824A3140:
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// b 0x824a3158
	goto loc_824A3158;
loc_824A3150:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
loc_824A3158:
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x824a30e8
	if (cr6.lt) goto loc_824A30E8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A316C"))) PPC_WEAK_FUNC(sub_824A316C);
PPC_FUNC_IMPL(__imp__sub_824A316C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3170"))) PPC_WEAK_FUNC(sub_824A3170);
PPC_FUNC_IMPL(__imp__sub_824A3170) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_824A317C:
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// addi r11,r8,-4
	r11.s64 = ctx.r8.s64 + -4;
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
loc_824A318C:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a31a4
	if (cr6.lt) goto loc_824A31A4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A31A4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a31c0
	if (cr6.eq) goto loc_824A31C0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// b 0x824a318c
	goto loc_824A318C;
loc_824A31C0:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// bne cr6,0x824a317c
	if (!cr6.eq) goto loc_824A317C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A31D4"))) PPC_WEAK_FUNC(sub_824A31D4);
PPC_FUNC_IMPL(__imp__sub_824A31D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A31D8"))) PPC_WEAK_FUNC(sub_824A31D8);
PPC_FUNC_IMPL(__imp__sub_824A31D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// beq cr6,0x824a324c
	if (cr6.eq) goto loc_824A324C;
loc_824A31E8:
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// addi r11,r8,-4
	r11.s64 = ctx.r8.s64 + -4;
	// rlwinm r5,r3,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
loc_824A31F8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r9,r5,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwzx r9,r31,r6
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a3220
	if (cr6.gt) goto loc_824A3220;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824A3220:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824a323c
	if (cr6.eq) goto loc_824A323C;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// b 0x824a31f8
	goto loc_824A31F8;
loc_824A323C:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// bne cr6,0x824a31e8
	if (!cr6.eq) goto loc_824A31E8;
loc_824A324C:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A3254"))) PPC_WEAK_FUNC(sub_824A3254);
PPC_FUNC_IMPL(__imp__sub_824A3254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3258"))) PPC_WEAK_FUNC(sub_824A3258);
PPC_FUNC_IMPL(__imp__sub_824A3258) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x824a32e0
	if (!cr6.lt) goto loc_824A32E0;
loc_824A3280:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,-4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a32a8
	if (cr6.lt) goto loc_824A32A8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A32A8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a32b8
	if (cr6.eq) goto loc_824A32B8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_824A32B8:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// stwx r10,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u32);
	// blt cr6,0x824a3280
	if (cr6.lt) goto loc_824A3280;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
loc_824A32E0:
	// bne cr6,0x824a32fc
	if (!cr6.eq) goto loc_824A32FC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stwx r11,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, r11.u32);
loc_824A32FC:
	// bl 0x824a2fd8
	ctx.lr = 0x824A3300;
	sub_824A2FD8(ctx, base);
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

__attribute__((alias("__imp__sub_824A3314"))) PPC_WEAK_FUNC(sub_824A3314);
PPC_FUNC_IMPL(__imp__sub_824A3314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3318"))) PPC_WEAK_FUNC(sub_824A3318);
PPC_FUNC_IMPL(__imp__sub_824A3318) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x824a33b0
	if (!cr6.lt) goto loc_824A33B0;
loc_824A3340:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,-4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a3378
	if (cr6.gt) goto loc_824A3378;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A3378:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a3388
	if (cr6.eq) goto loc_824A3388;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_824A3388:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// stwx r10,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u32);
	// blt cr6,0x824a3340
	if (cr6.lt) goto loc_824A3340;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
loc_824A33B0:
	// bne cr6,0x824a33cc
	if (!cr6.eq) goto loc_824A33CC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stwx r11,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, r11.u32);
loc_824A33CC:
	// bl 0x824a3048
	ctx.lr = 0x824A33D0;
	sub_824A3048(ctx, base);
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

__attribute__((alias("__imp__sub_824A33E4"))) PPC_WEAK_FUNC(sub_824A33E4);
PPC_FUNC_IMPL(__imp__sub_824A33E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A33E8"))) PPC_WEAK_FUNC(sub_824A33E8);
PPC_FUNC_IMPL(__imp__sub_824A33E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A340C"))) PPC_WEAK_FUNC(sub_824A340C);
PPC_FUNC_IMPL(__imp__sub_824A340C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3410"))) PPC_WEAK_FUNC(sub_824A3410);
PPC_FUNC_IMPL(__imp__sub_824A3410) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8262e420
	ctx.lr = 0x824A3434;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lhz r30,4(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// bl 0x8262e420
	ctx.lr = 0x824A344C;
	sub_8262E420(ctx, base);
	// addi r10,r30,-1
	ctx.r10.s64 = r30.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stb r9,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_824A3474"))) PPC_WEAK_FUNC(sub_824A3474);
PPC_FUNC_IMPL(__imp__sub_824A3474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3478"))) PPC_WEAK_FUNC(sub_824A3478);
PPC_FUNC_IMPL(__imp__sub_824A3478) {
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
	ctx.lr = 0x824A3480;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824a30d0
	ctx.lr = 0x824A3494;
	sub_824A30D0(ctx, base);
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// bne cr6,0x824a34c8
	if (!cr6.eq) goto loc_824A34C8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// beq cr6,0x824a34c0
	if (cr6.eq) goto loc_824A34C0;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x824A34BC;
	sub_82130528(ctx, base);
	// b 0x824a34c4
	goto loc_824A34C4;
loc_824A34C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824A34C4:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_824A34C8:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r29,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r29.u16);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824A34DC"))) PPC_WEAK_FUNC(sub_824A34DC);
PPC_FUNC_IMPL(__imp__sub_824A34DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A34E0"))) PPC_WEAK_FUNC(sub_824A34E0);
PPC_FUNC_IMPL(__imp__sub_824A34E0) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x824A34F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824a352c
	if (cr6.eq) goto loc_824A352C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824A352C:
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

__attribute__((alias("__imp__sub_824A3540"))) PPC_WEAK_FUNC(sub_824A3540);
PPC_FUNC_IMPL(__imp__sub_824A3540) {
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
	ctx.lr = 0x824A3548;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// subf r11,r29,r4
	r11.s64 = ctx.r4.s64 - r29.s64;
	// srawi r28,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r28.s64 = r11.s32 >> 2;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x824a35bc
	if (cr6.lt) goto loc_824A35BC;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lwzx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x824a3258
	ctx.lr = 0x824A358C;
	sub_824A3258(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824a35bc
	if (cr6.eq) goto loc_824A35BC;
loc_824A3594:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824a3258
	ctx.lr = 0x824A35B4;
	sub_824A3258(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x824a3594
	if (!cr6.eq) goto loc_824A3594;
loc_824A35BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A35C4"))) PPC_WEAK_FUNC(sub_824A35C4);
PPC_FUNC_IMPL(__imp__sub_824A35C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A35C8"))) PPC_WEAK_FUNC(sub_824A35C8);
PPC_FUNC_IMPL(__imp__sub_824A35C8) {
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
	ctx.lr = 0x824A35D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// subf r11,r29,r4
	r11.s64 = ctx.r4.s64 - r29.s64;
	// srawi r28,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r28.s64 = r11.s32 >> 2;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x824a3644
	if (cr6.lt) goto loc_824A3644;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lwzx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x824a3318
	ctx.lr = 0x824A3614;
	sub_824A3318(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824a3644
	if (cr6.eq) goto loc_824A3644;
loc_824A361C:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824a3318
	ctx.lr = 0x824A363C;
	sub_824A3318(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x824a361c
	if (!cr6.eq) goto loc_824A361C;
loc_824A3644:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A364C"))) PPC_WEAK_FUNC(sub_824A364C);
PPC_FUNC_IMPL(__imp__sub_824A364C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3650"))) PPC_WEAK_FUNC(sub_824A3650);
PPC_FUNC_IMPL(__imp__sub_824A3650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
loc_824A3654:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x824a366c
	if (cr6.lt) goto loc_824A366C;
	// li r11,0
	r11.s64 = 0;
loc_824A366C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a3680
	if (cr6.eq) goto loc_824A3680;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x824a3654
	goto loc_824A3654;
loc_824A3680:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a369c
	if (cr6.lt) goto loc_824A369C;
	// li r11,0
	r11.s64 = 0;
loc_824A369C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a3680
	if (!cr6.eq) goto loc_824A3680;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// b 0x824a3654
	goto loc_824A3654;
}

__attribute__((alias("__imp__sub_824A36C8"))) PPC_WEAK_FUNC(sub_824A36C8);
PPC_FUNC_IMPL(__imp__sub_824A36C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A36CC"))) PPC_WEAK_FUNC(sub_824A36CC);
PPC_FUNC_IMPL(__imp__sub_824A36CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A36D0"))) PPC_WEAK_FUNC(sub_824A36D0);
PPC_FUNC_IMPL(__imp__sub_824A36D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_824A36D4:
	// lwzx r11,r10,r6
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
loc_824A36DC:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r8,r9,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// lfs f13,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x824a36fc
	if (cr6.gt) goto loc_824A36FC;
	// li r11,0
	r11.s64 = 0;
loc_824A36FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a3710
	if (cr6.eq) goto loc_824A3710;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x824a36dc
	goto loc_824A36DC;
loc_824A3710:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r8,r9,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// lfs f13,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a3734
	if (cr6.gt) goto loc_824A3734;
	// li r11,0
	r11.s64 = 0;
loc_824A3734:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824a3710
	if (!cr6.eq) goto loc_824A3710;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// b 0x824a36d4
	goto loc_824A36D4;
}

__attribute__((alias("__imp__sub_824A3760"))) PPC_WEAK_FUNC(sub_824A3760);
PPC_FUNC_IMPL(__imp__sub_824A3760) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824A3764"))) PPC_WEAK_FUNC(sub_824A3764);
PPC_FUNC_IMPL(__imp__sub_824A3764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3768"))) PPC_WEAK_FUNC(sub_824A3768);
PPC_FUNC_IMPL(__imp__sub_824A3768) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a37a0
	if (cr6.lt) goto loc_824A37A0;
	// li r11,0
	r11.s64 = 0;
loc_824A37A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a37cc
	if (cr6.eq) goto loc_824A37CC;
	// subf. r5,r31,r4
	ctx.r5.s64 = ctx.r4.s64 - r31.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble 0x824a37c4
	if (!cr0.gt) goto loc_824A37C4;
	// subf r11,r5,r4
	r11.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db5b0
	ctx.lr = 0x824A37C4;
	sub_823DB5B0(ctx, base);
loc_824A37C4:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// b 0x824a380c
	goto loc_824A380C;
loc_824A37CC:
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// addi r11,r4,-4
	r11.s64 = ctx.r4.s64 + -4;
loc_824A37D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a37ec
	if (cr6.lt) goto loc_824A37EC;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A37EC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a3808
	if (cr6.eq) goto loc_824A3808;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// b 0x824a37d4
	goto loc_824A37D4;
loc_824A3808:
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r30.u32);
loc_824A380C:
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

__attribute__((alias("__imp__sub_824A3824"))) PPC_WEAK_FUNC(sub_824A3824);
PPC_FUNC_IMPL(__imp__sub_824A3824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3828"))) PPC_WEAK_FUNC(sub_824A3828);
PPC_FUNC_IMPL(__imp__sub_824A3828) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// li r11,1
	r11.s64 = 1;
	// lwzx r7,r9,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a3874
	if (cr6.gt) goto loc_824A3874;
	// li r11,0
	r11.s64 = 0;
loc_824A3874:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824a38a0
	if (cr6.eq) goto loc_824A38A0;
	// subf. r5,r31,r3
	ctx.r5.s64 = ctx.r3.s64 - r31.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble 0x824a3898
	if (!cr0.gt) goto loc_824A3898;
	// subf r11,r5,r3
	r11.s64 = ctx.r3.s64 - ctx.r5.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db5b0
	ctx.lr = 0x824A3898;
	sub_823DB5B0(ctx, base);
loc_824A3898:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// b 0x824a38ac
	goto loc_824A38AC;
loc_824A38A0:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824a2f80
	ctx.lr = 0x824A38AC;
	sub_824A2F80(ctx, base);
loc_824A38AC:
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

__attribute__((alias("__imp__sub_824A38C4"))) PPC_WEAK_FUNC(sub_824A38C4);
PPC_FUNC_IMPL(__imp__sub_824A38C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A38C8"))) PPC_WEAK_FUNC(sub_824A38C8);
PPC_FUNC_IMPL(__imp__sub_824A38C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824A38D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x824a3914
	if (cr6.eq) goto loc_824A3914;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x824a3914
	if (cr6.eq) goto loc_824A3914;
loc_824A38F4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a3768
	ctx.lr = 0x824A3908;
	sub_824A3768(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x824a38f4
	if (!cr6.eq) goto loc_824A38F4;
loc_824A3914:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824A391C"))) PPC_WEAK_FUNC(sub_824A391C);
PPC_FUNC_IMPL(__imp__sub_824A391C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3920"))) PPC_WEAK_FUNC(sub_824A3920);
PPC_FUNC_IMPL(__imp__sub_824A3920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824A3928;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x824a396c
	if (cr6.eq) goto loc_824A396C;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x824a396c
	if (cr6.eq) goto loc_824A396C;
loc_824A394C:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a3828
	ctx.lr = 0x824A3960;
	sub_824A3828(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x824a394c
	if (!cr6.eq) goto loc_824A394C;
loc_824A396C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824A3974"))) PPC_WEAK_FUNC(sub_824A3974);
PPC_FUNC_IMPL(__imp__sub_824A3974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3978"))) PPC_WEAK_FUNC(sub_824A3978);
PPC_FUNC_IMPL(__imp__sub_824A3978) {
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
	ctx.lr = 0x824A3980;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// ble cr6,0x824a39d4
	if (!cr6.gt) goto loc_824A39D4;
	// addi r29,r30,-4
	r29.s64 = r30.s64 + -4;
loc_824A39A0:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r11,-4
	r31.s64 = r11.s64 + -4;
	// lwzx r6,r29,r11
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	ctx.r5.s64 = r31.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r10.u32);
	// bl 0x824a3258
	ctx.lr = 0x824A39C4;
	sub_824A3258(ctx, base);
	// rlwinm r9,r31,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x824a39a0
	if (cr6.gt) goto loc_824A39A0;
loc_824A39D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824A39DC"))) PPC_WEAK_FUNC(sub_824A39DC);
PPC_FUNC_IMPL(__imp__sub_824A39DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A39E0"))) PPC_WEAK_FUNC(sub_824A39E0);
PPC_FUNC_IMPL(__imp__sub_824A39E0) {
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
	ctx.lr = 0x824A39E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// ble cr6,0x824a3a3c
	if (!cr6.gt) goto loc_824A3A3C;
	// addi r29,r30,-4
	r29.s64 = r30.s64 + -4;
loc_824A3A08:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r11,-4
	r31.s64 = r11.s64 + -4;
	// lwzx r6,r29,r11
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	ctx.r5.s64 = r31.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r10.u32);
	// bl 0x824a3318
	ctx.lr = 0x824A3A2C;
	sub_824A3318(ctx, base);
	// rlwinm r9,r31,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x824a3a08
	if (cr6.gt) goto loc_824A3A08;
loc_824A3A3C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824A3A44"))) PPC_WEAK_FUNC(sub_824A3A44);
PPC_FUNC_IMPL(__imp__sub_824A3A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3A48"))) PPC_WEAK_FUNC(sub_824A3A48);
PPC_FUNC_IMPL(__imp__sub_824A3A48) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824A3A50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824a3540
	ctx.lr = 0x824A3A74;
	sub_824A3540(ctx, base);
	// mr r30,r29
	r30.u64 = r29.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x824a3ad4
	if (!cr6.lt) goto loc_824A3AD4;
loc_824A3A80:
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x824a3aa0
	if (cr6.lt) goto loc_824A3AA0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A3AA0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a3ac8
	if (cr6.eq) goto loc_824A3AC8;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// subf r11,r31,r29
	r11.s64 = r29.s64 - r31.s64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r5.s64 = r11.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a3258
	ctx.lr = 0x824A3AC8;
	sub_824A3258(ctx, base);
loc_824A3AC8:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// blt cr6,0x824a3a80
	if (cr6.lt) goto loc_824A3A80;
loc_824A3AD4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a3978
	ctx.lr = 0x824A3AE4;
	sub_824A3978(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A3AEC"))) PPC_WEAK_FUNC(sub_824A3AEC);
PPC_FUNC_IMPL(__imp__sub_824A3AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3AF0"))) PPC_WEAK_FUNC(sub_824A3AF0);
PPC_FUNC_IMPL(__imp__sub_824A3AF0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824A3AF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x824a35c8
	ctx.lr = 0x824A3B1C;
	sub_824A35C8(ctx, base);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplw cr6,r28,r27
	cr6.compare<uint32_t>(r28.u32, r27.u32, xer);
	// bge cr6,0x824a3b8c
	if (!cr6.lt) goto loc_824A3B8C;
loc_824A3B28:
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x824a3b58
	if (cr6.gt) goto loc_824A3B58;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824A3B58:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824a3b80
	if (cr6.eq) goto loc_824A3B80;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// srawi r5,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r5.s64 = r11.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a3318
	ctx.lr = 0x824A3B80;
	sub_824A3318(ctx, base);
loc_824A3B80:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// blt cr6,0x824a3b28
	if (cr6.lt) goto loc_824A3B28;
loc_824A3B8C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a39e0
	ctx.lr = 0x824A3B9C;
	sub_824A39E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A3BA4"))) PPC_WEAK_FUNC(sub_824A3BA4);
PPC_FUNC_IMPL(__imp__sub_824A3BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824A3BA8"))) PPC_WEAK_FUNC(sub_824A3BA8);
PPC_FUNC_IMPL(__imp__sub_824A3BA8) {
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
	ctx.lr = 0x824A3BB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// ble cr6,0x824a3c68
	if (!cr6.gt) goto loc_824A3C68;
loc_824A3BD4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824a3c54
	if (cr6.eq) goto loc_824A3C54;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addi r5,r31,-4
	ctx.r5.s64 = r31.s64 + -4;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824a2df8
	ctx.lr = 0x824A3C08;
	sub_824A2DF8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// bl 0x824a3650
	ctx.lr = 0x824A3C20;
	sub_824A3650(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x824a3ba8
	ctx.lr = 0x824A3C38;
	sub_824A3BA8(ctx, base);
	// subf r6,r30,r29
	ctx.r6.s64 = r29.s64 - r30.s64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// rlwinm r5,r6,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r5,64
	cr6.compare<int32_t>(ctx.r5.s32, 64, xer);
	// bgt cr6,0x824a3bd4
	if (cr6.gt) goto loc_824A3BD4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824A3C54:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824a3a48
	ctx.lr = 0x824A3C68;
	sub_824A3A48(ctx, base);
loc_824A3C68:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A3C70"))) PPC_WEAK_FUNC(sub_824A3C70);
PPC_FUNC_IMPL(__imp__sub_824A3C70) {
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
	ctx.lr = 0x824A3C78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// ble cr6,0x824a3d30
	if (!cr6.gt) goto loc_824A3D30;
loc_824A3C9C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824a3d1c
	if (cr6.eq) goto loc_824A3D1C;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addi r5,r31,-4
	ctx.r5.s64 = r31.s64 + -4;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824a2eb0
	ctx.lr = 0x824A3CD0;
	sub_824A2EB0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// bl 0x824a36d0
	ctx.lr = 0x824A3CE8;
	sub_824A36D0(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x824a3c70
	ctx.lr = 0x824A3D00;
	sub_824A3C70(ctx, base);
	// subf r6,r30,r29
	ctx.r6.s64 = r29.s64 - r30.s64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// rlwinm r5,r6,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r5,64
	cr6.compare<int32_t>(ctx.r5.s32, 64, xer);
	// bgt cr6,0x824a3c9c
	if (cr6.gt) goto loc_824A3C9C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824A3D1C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824a3af0
	ctx.lr = 0x824A3D30;
	sub_824A3AF0(ctx, base);
loc_824A3D30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824A3D38"))) PPC_WEAK_FUNC(sub_824A3D38);
PPC_FUNC_IMPL(__imp__sub_824A3D38) {
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
	ctx.lr = 0x824A3D40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x824a3de0
	if (cr6.eq) goto loc_824A3DE0;
	// subf r10,r31,r30
	ctx.r10.s64 = r30.s64 - r31.s64;
	// li r11,0
	r11.s64 = 0;
	// srawi r29,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	r29.s64 = ctx.r10.s32 >> 2;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x824a3d80
	if (cr6.eq) goto loc_824A3D80;
loc_824A3D70:
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x824a3d70
	if (!cr6.eq) goto loc_824A3D70;
loc_824A3D80:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a3ba8
	ctx.lr = 0x824A3D98;
	sub_824A3BA8(ctx, base);
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// ble cr6,0x824a3dd4
	if (!cr6.gt) goto loc_824A3DD4;
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824a38c8
	ctx.lr = 0x824A3DB8;
	sub_824A38C8(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824a3170
	ctx.lr = 0x824A3DCC;
	sub_824A3170(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824A3DD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a38c8
	ctx.lr = 0x824A3DE0;
	sub_824A38C8(ctx, base);
loc_824A3DE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

