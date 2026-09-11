#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_82144684) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32235
	r11.s64 = -2112552960;
	// addi r3,r11,4384
	ctx.r3.s64 = r11.s64 + 4384;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144684) {
	__imp__sub_82144684(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32235
	r11.s64 = -2112552960;
	// addi r3,r11,4384
	ctx.r3.s64 = r11.s64 + 4384;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144690) {
	__imp__sub_82144690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214469C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32235
	r11.s64 = -2112552960;
	// addi r3,r11,4384
	ctx.r3.s64 = r11.s64 + 4384;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214469C) {
	__imp__sub_8214469C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821446A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32235
	r11.s64 = -2112552960;
	// addi r3,r11,4384
	ctx.r3.s64 = r11.s64 + 4384;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821446A8) {
	__imp__sub_821446A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821446B4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32235
	r11.s64 = -2112552960;
	// addi r3,r11,4384
	ctx.r3.s64 = r11.s64 + 4384;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821446B4) {
	__imp__sub_821446B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821446C0) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821446C0) {
	__imp__sub_821446C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821446C8) {
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
	ctx.lr = 0x821446D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821446f8
	if (cr6.eq) goto loc_821446F8;
	// bl 0x8214d830
	ctx.lr = 0x821446F4;
	sub_8214D830(ctx, base);
	// b 0x821446fc
	goto loc_821446FC;
loc_821446F8:
	// bl 0x8214d6b8
	ctx.lr = 0x821446FC;
	sub_8214D6B8(ctx, base);
loc_821446FC:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82143418
	ctx.lr = 0x82144718;
	sub_82143418(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_821446C8) {
	__imp__sub_821446C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144720) {
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
	ctx.lr = 0x82144728;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x8214d830
	ctx.lr = 0x82144740;
	sub_8214D830(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82143418
	ctx.lr = 0x8214475C;
	sub_82143418(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82144720) {
	__imp__sub_82144720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144764) {
	__imp__sub_82144764(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144768) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x825edac0
	ctx.lr = 0x82144784;
	sub_825EDAC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821447a0
	if (cr6.eq) goto loc_821447A0;
	// lhz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821447A0:
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144768) {
	__imp__sub_82144768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821447B8) {
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
	// bl 0x82160470
	ctx.lr = 0x821447D0;
	sub_82160470(ctx, base);
	// bl 0x82160450
	ctx.lr = 0x821447D4;
	sub_82160450(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821447e4
	if (cr6.eq) goto loc_821447E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82161090
	ctx.lr = 0x821447E4;
	sub_82161090(ctx, base);
loc_821447E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82160460
	ctx.lr = 0x821447EC;
	sub_82160460(ctx, base);
	// bl 0x82160470
	ctx.lr = 0x821447F0;
	sub_82160470(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214480c
	if (cr6.eq) goto loc_8214480C;
loc_821447F8:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x821c91b8
	ctx.lr = 0x82144800;
	sub_821C91B8(ctx, base);
	// bl 0x82160470
	ctx.lr = 0x82144804;
	sub_82160470(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821447f8
	if (!cr6.eq) goto loc_821447F8;
loc_8214480C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,777(r31)
	PPC_STORE_U8(r31.u32 + 777, r11.u8);
	// lbz r10,776(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 776);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144834
	if (cr6.eq) goto loc_82144834;
loc_82144820:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x821c91b8
	ctx.lr = 0x82144828;
	sub_821C91B8(ctx, base);
	// lbz r11,776(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 776);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144820
	if (!cr6.eq) goto loc_82144820;
loc_82144834:
	// lwz r3,780(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// bl 0x821c9168
	ctx.lr = 0x8214483C;
	sub_821C9168(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x8214cfa0
	ctx.lr = 0x82144844;
	sub_8214CFA0(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82144848;
	sub_82130000(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x82160050
	ctx.lr = 0x82144850;
	sub_82160050(ctx, base);
	// bl 0x8215ff90
	ctx.lr = 0x82144854;
	sub_8215FF90(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x82160310
	ctx.lr = 0x8214485C;
	sub_82160310(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a0f8
	ctx.lr = 0x82144864;
	sub_8214A0F8(ctx, base);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8214dd80
	ctx.lr = 0x8214486C;
	sub_8214DD80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82144870;
	sub_82130000(ctx, base);
	// bl 0x82135f48
	ctx.lr = 0x82144874;
	sub_82135F48(ctx, base);
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

PPC_WEAK_FUNC(sub_821447B8) {
	__imp__sub_821447B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144888) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,14200
	ctx.r4.s64 = r11.s64 + 14200;
	// bl 0x821ce1d0
	ctx.lr = 0x821448AC;
	sub_821CE1D0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821ce150
	ctx.lr = 0x821448B4;
	sub_821CE150(ctx, base);
	// ld r10,800(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 800);
	// std r10,792(r31)
	PPC_STORE_U64(r31.u32 + 792, ctx.r10.u64);
	// bl 0x82144f70
	ctx.lr = 0x821448C0;
	sub_82144F70(ctx, base);
	// std r3,800(r31)
	PPC_STORE_U64(r31.u32 + 800, ctx.r3.u64);
	// bl 0x82144fc8
	ctx.lr = 0x821448C8;
	sub_82144FC8(ctx, base);
	// ld r9,800(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 800);
	// ld r8,792(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 792);
	// stw r3,784(r31)
	PPC_STORE_U32(r31.u32 + 784, ctx.r3.u32);
	// subf r3,r8,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r8.s64;
	// bl 0x823dba80
	ctx.lr = 0x821448DC;
	sub_823DBA80(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lbz r11,816(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 816);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,14196(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14196);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,808(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 808, temp.u32);
	// beq cr6,0x82144930
	if (cr6.eq) goto loc_82144930;
	// lbz r10,817(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 817);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82144928
	if (!cr6.eq) goto loc_82144928;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r11,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r11.u32);
	// bl 0x821366d8
	ctx.lr = 0x82144920;
	sub_821366D8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82144950
	goto loc_82144950;
loc_82144928:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144954
	if (!cr6.eq) goto loc_82144954;
loc_82144930:
	// lbz r11,817(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 817);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144954
	if (cr6.eq) goto loc_82144954;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,812(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 812);
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x821366d8
	ctx.lr = 0x8214494C;
	sub_821366D8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
loc_82144950:
	// stb r10,817(r31)
	PPC_STORE_U8(r31.u32 + 817, ctx.r10.u8);
loc_82144954:
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// lwz r4,784(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// bl 0x82160088
	ctx.lr = 0x82144960;
	sub_82160088(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// lwz r4,784(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// bl 0x8214d050
	ctx.lr = 0x8214496C;
	sub_8214D050(ctx, base);
	// lwz r3,784(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// bl 0x82135f80
	ctx.lr = 0x82144974;
	sub_82135F80(ctx, base);
	// lwz r11,6464(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6464);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82144980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821ce170
	ctx.lr = 0x82144988;
	sub_821CE170(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lbz r9,6552(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6552);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821449d0
	if (cr6.eq) goto loc_821449D0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821ce1b0
	ctx.lr = 0x821449A0;
	sub_821CE1B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14060(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14060);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f1
	ctx.f12.f64 = double(float(f0.f64 - ctx.f1.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fsel f11,f12,f12,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f9,f10,f0,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821c91b8
	ctx.lr = 0x821449D0;
	sub_821C91B8(ctx, base);
loc_821449D0:
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

PPC_WEAK_FUNC(sub_82144888) {
	__imp__sub_82144888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821449E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821449E4) {
	__imp__sub_821449E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821449E8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,1344
	ctx.r3.s64 = ctx.r3.s64 + 1344;
	// b 0x8215e588
	sub_8215E588(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821449E8) {
	__imp__sub_821449E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821449F0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,1344
	ctx.r3.s64 = ctx.r3.s64 + 1344;
	// b 0x8215e8c8
	sub_8215E8C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821449F0) {
	__imp__sub_821449F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821449F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,19836
	ctx.r10.s64 = r11.s64 + 19836;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r3,1344
	ctx.r3.s64 = ctx.r3.s64 + 1344;
	// b 0x8215ec10
	sub_8215EC10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821449F8) {
	__imp__sub_821449F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A14) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144A14) {
	__imp__sub_82144A14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A18) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,784(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 784);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144A18) {
	__imp__sub_82144A18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A20) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,700
	ctx.r3.s64 = ctx.r3.s64 + 700;
	// b 0x8214dd40
	sub_8214DD40(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82144A20) {
	__imp__sub_82144A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A28) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,700
	ctx.r3.s64 = ctx.r3.s64 + 700;
	// b 0x8214d6b8
	sub_8214D6B8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82144A28) {
	__imp__sub_82144A28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,5628
	ctx.r10.s64 = r11.s64 + 5628;
	// lbz r3,40(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144A30) {
	__imp__sub_82144A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// b 0x82136480
	sub_82136480(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82144A40) {
	__imp__sub_82144A40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144A4C) {
	__imp__sub_82144A4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// b 0x821364f8
	sub_821364F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82144A50) {
	__imp__sub_82144A50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144A5C) {
	__imp__sub_82144A5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,1316(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1316);
	// li r6,0
	ctx.r6.s64 = 0;
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

PPC_WEAK_FUNC(sub_82144A60) {
	__imp__sub_82144A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,1316(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1316);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_82144A78) {
	__imp__sub_82144A78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144A8C) {
	__imp__sub_82144A8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144A90) {
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
	// bl 0x821447b8
	ctx.lr = 0x82144AA0;
	sub_821447B8(ctx, base);
	// bl 0x82160448
	ctx.lr = 0x82144AA4;
	sub_82160448(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144A90) {
	__imp__sub_82144A90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144AB4) {
	__imp__sub_82144AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144AB8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// stb r10,776(r31)
	PPC_STORE_U8(r31.u32 + 776, ctx.r10.u8);
	// lbz r9,777(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 777);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82144af8
	if (cr6.eq) goto loc_82144AF8;
loc_82144AE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144888
	ctx.lr = 0x82144AEC;
	sub_82144888(ctx, base);
	// lbz r11,777(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 777);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144ae4
	if (!cr6.eq) goto loc_82144AE4;
loc_82144AF8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,776(r31)
	PPC_STORE_U8(r31.u32 + 776, r11.u8);
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

PPC_WEAK_FUNC(sub_82144AB8) {
	__imp__sub_82144AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82144B14) {
	__imp__sub_82144B14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144B18) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32236
	ctx.r10.s64 = -2112618496;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r7,r11,14216
	ctx.r7.s64 = r11.s64 + 14216;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,19128
	ctx.r3.s64 = ctx.r10.s64 + 19128;
	// bl 0x821c9308
	ctx.lr = 0x82144B54;
	sub_821C9308(ctx, base);
	// lbz r9,776(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 776);
	// stw r3,780(r31)
	PPC_STORE_U32(r31.u32 + 780, ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82144b78
	if (!cr6.eq) goto loc_82144B78;
loc_82144B64:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x821c91b8
	ctx.lr = 0x82144B6C;
	sub_821C91B8(ctx, base);
	// lbz r11,776(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 776);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144b64
	if (cr6.eq) goto loc_82144B64;
loc_82144B78:
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

PPC_WEAK_FUNC(sub_82144B18) {
	__imp__sub_82144B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144B90) {
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
	ctx.lr = 0x82144B98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r10,19836
	r30.s64 = ctx.r10.s64 + 19836;
	// li r11,0
	r11.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// stb r11,817(r31)
	PPC_STORE_U8(r31.u32 + 817, r11.u8);
	// stb r11,816(r31)
	PPC_STORE_U8(r31.u32 + 816, r11.u8);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144bcc
	if (cr6.eq) goto loc_82144BCC;
	// stb r11,818(r31)
	PPC_STORE_U8(r31.u32 + 818, r11.u8);
	// b 0x82144bfc
	goto loc_82144BFC;
loc_82144BCC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r10,19816
	ctx.r9.s64 = ctx.r10.s64 + 19816;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144be8
	if (cr6.eq) goto loc_82144BE8;
	// stb r11,818(r31)
	PPC_STORE_U8(r31.u32 + 818, r11.u8);
	// b 0x82144bfc
	goto loc_82144BFC;
loc_82144BE8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,19796
	ctx.r10.s64 = r11.s64 + 19796;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stb r29,818(r31)
	PPC_STORE_U8(r31.u32 + 818, r29.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_82144BFC:
	// bl 0x82144f28
	ctx.lr = 0x82144C00;
	sub_82144F28(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x821602f8
	ctx.lr = 0x82144C08;
	sub_821602F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144c20
	if (!cr6.eq) goto loc_82144C20;
loc_82144C14:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82144C20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a588
	ctx.lr = 0x82144C28;
	sub_8214A588(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,772(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 772);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// lwz r4,1276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1276);
	// bl 0x8214e328
	ctx.lr = 0x82144C48;
	sub_8214E328(ctx, base);
	// bl 0x8215ff48
	ctx.lr = 0x82144C4C;
	sub_8215FF48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x8215ffb8
	ctx.lr = 0x82144C60;
	sub_8215FFB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144ca4
	if (!cr6.eq) goto loc_82144CA4;
	// addi r3,r31,6468
	ctx.r3.s64 = r31.s64 + 6468;
	// lwz r5,1316(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1316);
	// lwz r4,1312(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// bl 0x82135e48
	ctx.lr = 0x82144C88;
	sub_82135E48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,5628
	ctx.r10.s64 = r11.s64 + 5628;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r11,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r11.u32);
loc_82144CA4:
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e1a8
	ctx.lr = 0x82144CAC;
	sub_8215E1A8(ctx, base);
	// bl 0x8214a6d8
	ctx.lr = 0x82144CB0;
	sub_8214A6D8(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144d08
	if (!cr6.eq) goto loc_82144D08;
	// bl 0x8214cee0
	ctx.lr = 0x82144CC0;
	sub_8214CEE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x8214d570
	ctx.lr = 0x82144CD4;
	sub_8214D570(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// bl 0x82130008
	ctx.lr = 0x82144CE4;
	sub_82130008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
	// stb r29,777(r31)
	PPC_STORE_U8(r31.u32 + 777, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144b18
	ctx.lr = 0x82144CFC;
	sub_82144B18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144c14
	if (cr6.eq) goto loc_82144C14;
loc_82144D08:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82160460
	ctx.lr = 0x82144D10;
	sub_82160460(ctx, base);
	// bl 0x82160450
	ctx.lr = 0x82144D14;
	sub_82160450(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82144d24
	if (cr6.eq) goto loc_82144D24;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82161090
	ctx.lr = 0x82144D24;
	sub_82161090(ctx, base);
loc_82144D24:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82144B90) {
	__imp__sub_82144B90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144D30) {
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
	ctx.lr = 0x82144D38;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r6,r11,19836
	ctx.r6.s64 = r11.s64 + 19836;
	// li r11,0
	r11.s64 = 0;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f0,1320(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1320, temp.u32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// stfs f0,1324(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1324, temp.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stfs f0,1328(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1328, temp.u32);
	// stfs f13,808(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 808, temp.u32);
	// stb r3,818(r31)
	PPC_STORE_U8(r31.u32 + 818, ctx.r3.u8);
	// stw r11,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, r11.u32);
	// addi r30,r9,26592
	r30.s64 = ctx.r9.s64 + 26592;
	// stw r11,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r11.u32);
	// stw r11,784(r31)
	PPC_STORE_U32(r31.u32 + 784, r11.u32);
	// std r11,800(r31)
	PPC_STORE_U64(r31.u32 + 800, r11.u64);
	// std r11,792(r31)
	PPC_STORE_U64(r31.u32 + 792, r11.u64);
	// stw r7,6464(r31)
	PPC_STORE_U32(r31.u32 + 6464, ctx.r7.u32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144dd0
	if (cr6.eq) goto loc_82144DD0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r8,r11,14248
	ctx.r8.s64 = r11.s64 + 14248;
	// addi r7,r9,19816
	ctx.r7.s64 = ctx.r9.s64 + 19816;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
loc_82144DD0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r31,6468
	r11.s64 = r31.s64 + 6468;
	// beq cr6,0x82144df8
	if (cr6.eq) goto loc_82144DF8;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
loc_82144DE0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stbx r8,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x82144de0
	if (!cr6.eq) goto loc_82144DE0;
	// b 0x82144e1c
	goto loc_82144E1C;
loc_82144DF8:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r10,6544(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6544);
loc_82144E04:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bne cr6,0x82144e04
	if (!cr6.eq) goto loc_82144E04;
loc_82144E1C:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r5,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, ctx.r5.u32);
	// stw r4,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, ctx.r4.u32);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_82144E2C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82144e2c
	if (!cr6.eq) goto loc_82144E2C;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,6548(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6548);
loc_82144E4C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82144e4c
	if (!cr6.eq) goto loc_82144E4C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82144E60:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82144e60
	if (!cr6.eq) goto loc_82144E60;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// bl 0x82161f48
	ctx.lr = 0x82144E84;
	sub_82161F48(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r29,772(r31)
	PPC_STORE_U32(r31.u32 + 772, r29.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,819(r31)
	PPC_STORE_U8(r31.u32 + 819, ctx.r9.u8);
	// bl 0x821603c8
	ctx.lr = 0x82144EA0;
	sub_821603C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144b90
	ctx.lr = 0x82144EA8;
	sub_82144B90(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82144D30) {
	__imp__sub_82144D30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144EB0) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144d30
	ctx.lr = 0x82144ED8;
	sub_82144D30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82144eec
	if (!cr6.eq) goto loc_82144EEC;
loc_82144EE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82144f10
	goto loc_82144F10;
loc_82144EEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82160800
	ctx.lr = 0x82144EF4;
	sub_82160800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82144ee4
	if (cr6.eq) goto loc_82144EE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,784(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// bl 0x82161210
	ctx.lr = 0x82144F0C;
	sub_82161210(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_82144F10:
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

PPC_WEAK_FUNC(sub_82144EB0) {
	__imp__sub_82144EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144F28) {
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
	// bl 0x821c9788
	ctx.lr = 0x82144F38;
	sub_821C9788(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,26624
	ctx.r3.s64 = r11.s64 + 26624;
	// bl 0x821ce210
	ctx.lr = 0x82144F48;
	sub_821CE210(ctx, base);
loc_82144F48:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144f48
	if (cr6.eq) goto loc_82144F48;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// std r11,26616(r10)
	PPC_STORE_U64(ctx.r10.u32 + 26616, r11.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144F28) {
	__imp__sub_82144F28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
loc_82144F7C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144f7c
	if (cr6.eq) goto loc_82144F7C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r10,26616(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 26616);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x823dba80
	ctx.lr = 0x82144F9C;
	sub_823DBA80(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,14340(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14340);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82144F70) {
	__imp__sub_82144F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82144FC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
loc_82144FD4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82144fd4
	if (cr6.eq) goto loc_82144FD4;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r10,26616(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 26616);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x823dba80
	ctx.lr = 0x82144FF4;
	sub_823DBA80(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,14336(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14336);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
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
}

PPC_WEAK_FUNC(sub_82144FC8) {
	__imp__sub_82144FC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r7,r8,26624
	ctx.r7.s64 = ctx.r8.s64 + 26624;
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// ori r4,r6,64167
	ctx.r4.u64 = ctx.r6.u64 | 64167;
	// lwz r9,26624(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26624);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r9,r4
	ctx.r10.s64 = ctx.r9.s64 * ctx.r4.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// twllei r5,0
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,26624(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26624, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r4,r6,r5
	ctx.r4.s32 = ctx.r6.s32 / ctx.r5.s32;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// mullw r9,r4,r5
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// andc r8,r5,r10
	ctx.r8.u64 = ctx.r5.u64 & ~ctx.r10.u64;
	// subf r10,r9,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r9.s64;
	// twlgei r8,-1
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145020) {
	__imp__sub_82145020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// fsubs f13,f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,26624
	ctx.r7.s64 = ctx.r9.s64 + 26624;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,26624(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26624);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r4,r6
	ctx.r10.s64 = ctx.r4.s64 * ctx.r6.s64;
	// lfs f0,14348(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r10,26624(r9)
	PPC_STORE_U32(ctx.r9.u32 + 26624, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmadds f1,f9,f0,f1
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f1.f64));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145080) {
	__imp__sub_82145080(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821450DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821450DC) {
	__imp__sub_821450DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821450E0) {
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
	// bl 0x82138130
	ctx.lr = 0x821450F8;
	sub_82138130(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// stw r9,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r9.u32);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stb r11,76(r31)
	PPC_STORE_U8(r31.u32 + 76, r11.u8);
	// stb r11,78(r31)
	PPC_STORE_U8(r31.u32 + 78, r11.u8);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stw r8,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r8.u32);
loc_82145138:
	// addi r8,r10,27
	ctx.r8.s64 = ctx.r10.s64 + 27;
	// addi r7,r10,31
	ctx.r7.s64 = ctx.r10.s64 + 31;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// stwx r9,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r9.u32);
	// stwx r11,r4,r31
	PPC_STORE_U32(ctx.r4.u32 + r31.u32, r11.u32);
	// blt cr6,0x82145138
	if (cr6.lt) goto loc_82145138;
	// li r11,1
	r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
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

PPC_WEAK_FUNC(sub_821450E0) {
	__imp__sub_821450E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214518C) {
	__imp__sub_8214518C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,77(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 77);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821451fc
	if (cr6.eq) goto loc_821451FC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821451fc
	if (cr6.eq) goto loc_821451FC;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
loc_821451B8:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r10,r5
	ctx.r7.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x821451e0
	if (!cr6.gt) goto loc_821451E0;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x821451e8
	goto loc_821451E8;
loc_821451E0:
	// bge cr6,0x821451f4
	if (!cr6.lt) goto loc_821451F4;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_821451E8:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x821451b8
	if (!cr6.gt) goto loc_821451B8;
	// blr 
	return;
loc_821451F4:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
loc_821451FC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145190) {
	__imp__sub_82145190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145204) {
	__imp__sub_82145204(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145208) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,77(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 77);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// ld r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// ld r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 28);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r6,120(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r9,36(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lwz r8,36(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,20(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// ble cr6,0x821452cc
	if (!cr6.gt) goto loc_821452CC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8214526C:
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// ldx r11,r10,r9
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lwz r8,44(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// bne cr6,0x821452b4
	if (!cr6.eq) goto loc_821452B4;
	// ld r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 32);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
loc_821452B4:
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214526c
	if (cr6.lt) goto loc_8214526C;
loc_821452CC:
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lwz r7,40(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r6,40(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// ble cr6,0x82145324
	if (!cr6.gt) goto loc_82145324;
	// li r9,0
	ctx.r9.s64 = 0;
loc_821452F8:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lwz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// blt cr6,0x821452f8
	if (cr6.lt) goto loc_821452F8;
loc_82145324:
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145208) {
	__imp__sub_82145208(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145338) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
loc_82145348:
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// addi r9,r11,31
	ctx.r9.s64 = r11.s64 + 31;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// ld r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + r11.u64;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
	// lwz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x82145348
	if (cr6.lt) goto loc_82145348;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145338) {
	__imp__sub_82145338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145398) {
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
	ctx.lr = 0x821453A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82145544
	if (!cr6.gt) goto loc_82145544;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
loc_821453D0:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r8,r10,31
	ctx.r8.s64 = ctx.r10.s64 + 31;
	// lwz r10,5828(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5828);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwzx r8,r7,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r30,r8,r9
	r30.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x82145594
	if (cr6.lt) goto loc_82145594;
	// lwz r8,5832(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 5832);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82145594
	if (cr6.gt) goto loc_82145594;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r8,530
	cr6.compare<uint32_t>(ctx.r8.u32, 530, xer);
	// bgt cr6,0x82145550
	if (cr6.gt) goto loc_82145550;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// rlwinm r7,r8,11,0,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 11) & 0xFFFFF800;
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// clrlwi r30,r4,24
	r30.u64 = ctx.r4.u32 & 0xFF;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r5.u32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r7,r10,31
	ctx.r7.s64 = ctx.r10.s64 + 31;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r8,r10,11,0,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0xFFFFF800;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r6,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r6.u32);
	// stw r6,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r6.u32);
	// stw r6,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r6.u32);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r7,r10,31
	ctx.r7.s64 = ctx.r10.s64 + 31;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r8,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r8.u32);
	// beq cr6,0x821454f4
	if (cr6.eq) goto loc_821454F4;
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r7,r7,31
	ctx.r7.s64 = ctx.r7.s64 + 31;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r7,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwz r7,0(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r7,8(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// ble cr6,0x821454f4
	if (!cr6.gt) goto loc_821454F4;
	// addi r30,r8,-1
	r30.s64 = ctx.r8.s64 + -1;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r7,r7,2048
	ctx.r7.s64 = ctx.r7.s64 + 2048;
	// stw r30,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r30.u32);
	// addi r8,r8,-2048
	ctx.r8.s64 = ctx.r8.s64 + -2048;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
loc_821454F4:
	// lwz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ble cr6,0x8214552c
	if (!cr6.gt) goto loc_8214552C;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_82145508:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r27,32(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stwx r30,r8,r27
	PPC_STORE_U32(ctx.r8.u32 + r27.u32, r30.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lwz r30,52(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplw cr6,r7,r30
	cr6.compare<uint32_t>(ctx.r7.u32, r30.u32, xer);
	// blt cr6,0x82145508
	if (cr6.lt) goto loc_82145508;
loc_8214552C:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x821453d0
	if (cr6.lt) goto loc_821453D0;
loc_82145544:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82145550:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137890
	ctx.lr = 0x82145558;
	sub_82137890(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82145570
	if (cr6.eq) goto loc_82145570;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137890
	ctx.lr = 0x82145568;
	sub_82137890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82145578
	goto loc_82145578;
loc_82145570:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,12540
	ctx.r4.s64 = r11.s64 + 12540;
loc_82145578:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r11,14480
	ctx.r3.s64 = r11.s64 + 14480;
	// bl 0x82130000
	ctx.lr = 0x82145588;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82145594:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,14392
	ctx.r3.s64 = r11.s64 + 14392;
	// bl 0x82130000
	ctx.lr = 0x821455A4;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82145398) {
	__imp__sub_82145398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821455B0) {
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
	ctx.lr = 0x821455B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821455D0;
	sub_821C90C0(ctx, base);
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82145684
	if (!cr6.eq) goto loc_82145684;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bgt cr6,0x82145684
	if (cr6.gt) goto loc_82145684;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r29,136(r31)
	PPC_STORE_U16(r31.u32 + 136, r29.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// sth r29,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r29.u16);
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r8,138(r31)
	PPC_STORE_U8(r31.u32 + 138, ctx.r8.u8);
	// stb r8,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r8.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r9,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r9.u32);
	// stw r7,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r7.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r10.u32);
loc_82145628:
	// addi r7,r11,27
	ctx.r7.s64 = r11.s64 + 27;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// stwx r9,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r9.u32);
	// blt cr6,0x82145628
	if (cr6.lt) goto loc_82145628;
	// stb r8,76(r31)
	PPC_STORE_U8(r31.u32 + 76, ctx.r8.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stb r10,77(r31)
	PPC_STORE_U8(r31.u32 + 77, ctx.r10.u8);
loc_82145650:
	// addi r9,r11,31
	ctx.r9.s64 = r11.s64 + 31;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// stwx r10,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, ctx.r10.u32);
	// blt cr6,0x82145650
	if (cr6.lt) goto loc_82145650;
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
	// stb r8,70(r31)
	PPC_STORE_U8(r31.u32 + 70, ctx.r8.u8);
	// bl 0x82144fc8
	ctx.lr = 0x82145678;
	sub_82144FC8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821372d8
	ctx.lr = 0x82145684;
	sub_821372D8(ctx, base);
loc_82145684:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x8214568C;
	sub_821C9108(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_821455B0) {
	__imp__sub_821455B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145694) {
	__imp__sub_82145694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145698) {
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
	ctx.lr = 0x821456A0;
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
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821456B8;
	sub_821C90C0(ctx, base);
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821456f8
	if (!cr6.eq) goto loc_821456F8;
	// li r11,1
	r11.s64 = 1;
	// sth r30,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r30.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stb r10,76(r31)
	PPC_STORE_U8(r31.u32 + 76, ctx.r10.u8);
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
	// bl 0x82144fc8
	ctx.lr = 0x821456EC;
	sub_82144FC8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821372d8
	ctx.lr = 0x821456F8;
	sub_821372D8(ctx, base);
loc_821456F8:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82145700;
	sub_821C9108(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82145698) {
	__imp__sub_82145698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145708) {
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
	ctx.lr = 0x82145710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,3
	r28.s64 = 3;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x8214572C;
	sub_821C90C0(ctx, base);
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82145778
	if (!cr6.eq) goto loc_82145778;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82145778
	if (!cr6.eq) goto loc_82145778;
	// lhz r11,66(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// clrlwi r10,r30,16
	ctx.r10.u64 = r30.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82145778
	if (!cr6.eq) goto loc_82145778;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bne cr6,0x82145778
	if (!cr6.eq) goto loc_82145778;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r28,0
	r28.s64 = 0;
	// bl 0x821c9108
	ctx.lr = 0x8214576C;
	sub_821C9108(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82145778:
	// lhz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82145794
	if (cr6.eq) goto loc_82145794;
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821457b8
	if (!cr6.eq) goto loc_821457B8;
loc_82145794:
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// bne cr6,0x821457b8
	if (!cr6.eq) goto loc_821457B8;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r28,1
	r28.s64 = 1;
	// bl 0x821c9108
	ctx.lr = 0x821457AC;
	sub_821C9108(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821457B8:
	// lhz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821457c8
	if (!cr6.eq) goto loc_821457C8;
	// li r28,2
	r28.s64 = 2;
loc_821457C8:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x821457D0;
	sub_821C9108(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82145708) {
	__imp__sub_82145708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821457DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821457DC) {
	__imp__sub_821457DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821457E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 77);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r6,120(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,36(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f11,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f12,8876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8884);
	f0.f64 = double(temp.f32);
	// blt cr6,0x82145a04
	if (cr6.lt) goto loc_82145A04;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// lwz r11,20(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_82145848:
	// lwz r10,-32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -32);
	// lwz r5,16(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lhz r4,24(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// extsw r5,r4
	ctx.r5.s64 = ctx.r4.s32;
	// std r10,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r10.u64);
	// lfd f10,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// std r5,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r5.u64);
	// lfd f9,-72(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f9,f3,f10
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f10.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f7,f9,f10,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f6.u64);
	// lwz r10,-60(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x821458b4
	if (!cr6.gt) goto loc_821458B4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_821458B4:
	// lwz r10,-16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// lhz r5,24(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// std r10,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r10.u64);
	// lfd f10,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r5,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r5.u64);
	// lfd f8,-48(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f9,f3,f10
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f10.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f7,f9,f10,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f6.u64);
	// lwz r10,-60(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x82145920
	if (!cr6.gt) goto loc_82145920;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_82145920:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,16(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lhz r4,24(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// extsw r5,r4
	ctx.r5.s64 = ctx.r4.s32;
	// std r10,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r10.u64);
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f10,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f9,-32(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f9,f3,f10
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f10.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f7,f9,f10,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f6.u64);
	// lwz r10,-60(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x8214598c
	if (!cr6.gt) goto loc_8214598C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_8214598C:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lhz r5,24(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// std r10,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r10.u64);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f10,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f9,f3,f10
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f10.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f7,f9,f10,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f6.u64);
	// lwz r10,-60(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x821459f8
	if (!cr6.gt) goto loc_821459F8;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_821459F8:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x82145848
	if (!cr0.eq) goto loc_82145848;
loc_82145A04:
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r10,20(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r9,r8,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_82145A1C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,16(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lhz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// std r5,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r5.u64);
	// lfd f8,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f9,f3,f10
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f10.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f7,f9,f10,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f6.u64);
	// lwz r10,-28(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// ble cr6,0x82145a84
	if (!cr6.gt) goto loc_82145A84;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_82145A84:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82145a1c
	if (!cr0.eq) goto loc_82145A1C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821457E0) {
	__imp__sub_821457E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145A94) {
	__imp__sub_82145A94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145A98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82145AA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,77(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 77);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,-1
	r29.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82145b8c
	if (cr6.eq) goto loc_82145B8C;
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82145b8c
	if (cr6.eq) goto loc_82145B8C;
	// lwz r31,8(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// addic. r9,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r9.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82145b7c
	if (cr0.eq) goto loc_82145B7C;
	// clrldi r8,r30,32
	ctx.r8.u64 = r30.u64 & 0xFFFFFFFF;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lfs f13,8880(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8884);
	f0.f64 = double(temp.f32);
loc_82145B10:
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f9,f2,f11
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f8,f1,f2,f9
	ctx.f8.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : ctx.f9.f64;
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplw cr6,r5,r7
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, xer);
	// blt cr6,0x82145b70
	if (cr6.lt) goto loc_82145B70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82145b10
	if (cr6.lt) goto loc_82145B10;
	// b 0x82145b7c
	goto loc_82145B7C;
loc_82145B70:
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82145b8c
	if (!cr6.eq) goto loc_82145B8C;
loc_82145B7C:
	// bl 0x821457e0
	ctx.lr = 0x82145B80;
	sub_821457E0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// addi r3,r31,-1
	ctx.r3.s64 = r31.s64 + -1;
	// blt cr6,0x82145b90
	if (cr6.lt) goto loc_82145B90;
loc_82145B8C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82145B90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82145A98) {
	__imp__sub_82145A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145B98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 77);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// std r3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r3.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f12,f0,f11
	ctx.f12.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f11,f13,f0,f12
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82145B98) {
	__imp__sub_82145B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145C4C) {
	__imp__sub_82145C4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145C50) {
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
	// li r30,-1
	r30.s64 = -1;
	// bl 0x82145a98
	ctx.lr = 0x82145C70;
	sub_82145A98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82145c88
	if (cr6.lt) goto loc_82145C88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145b98
	ctx.lr = 0x82145C84;
	sub_82145B98(ctx, base);
	// b 0x82145c8c
	goto loc_82145C8C;
loc_82145C88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82145C8C:
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

PPC_WEAK_FUNC(sub_82145C50) {
	__imp__sub_82145C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145CA4) {
	__imp__sub_82145CA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r20{};
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
	ctx.lr = 0x82145CB0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r30,2
	r30.s64 = 2;
	// lbz r11,77(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 77);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82145ec0
	if (cr6.eq) goto loc_82145EC0;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82145ec0
	if (cr6.eq) goto loc_82145EC0;
	// bl 0x821375c8
	ctx.lr = 0x82145CE4;
	sub_821375C8(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82145ec0
	if (cr6.eq) goto loc_82145EC0;
	// li r27,0
	r27.s64 = 0;
	// stb r29,139(r31)
	PPC_STORE_U8(r31.u32 + 139, r29.u8);
	// li r25,1
	r25.s64 = 1;
	// stb r28,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r28.u8);
	// stb r27,138(r31)
	PPC_STORE_U8(r31.u32 + 138, r27.u8);
	// sth r26,136(r31)
	PPC_STORE_U16(r31.u32 + 136, r26.u16);
	// stb r25,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r25.u8);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82145D10;
	sub_821C90C0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82145d3c
	if (cr6.eq) goto loc_82145D3C;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x82145d38
	if (cr6.eq) goto loc_82145D38;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x82145e4c
	if (cr6.eq) goto loc_82145E4C;
	// stb r29,78(r31)
	PPC_STORE_U8(r31.u32 + 78, r29.u8);
	// stw r25,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r25.u32);
loc_82145D38:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82145D3C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82145D44;
	sub_821C9108(ctx, base);
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x82145eb4
	if (!cr6.eq) goto loc_82145EB4;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// addi r8,r11,27
	ctx.r8.s64 = r11.s64 + 27;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// beq cr6,0x82145de8
	if (cr6.eq) goto loc_82145DE8;
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rotlwi r10,r30,1
	ctx.r10.u64 = __builtin_rotateleft32(r30.u32, 1);
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// divw r6,r30,r7
	ctx.r6.s32 = r30.s32 / ctx.r7.s32;
	// andc r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// mullw r4,r6,r7
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// twllei r7,0
	// twlgei r5,-1
	// subf r30,r4,r30
	r30.s64 = r30.s64 - ctx.r4.s64;
loc_82145DA0:
	// addi r10,r11,27
	ctx.r10.s64 = r11.s64 + 27;
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// twllei r7,0
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r5,r6,r7
	ctx.r5.s32 = ctx.r6.s32 / ctx.r7.s32;
	// addi r3,r9,-1
	ctx.r3.s64 = ctx.r9.s64 + -1;
	// mullw r4,r5,r7
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// subf r9,r4,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r4.s64;
	// andc r8,r7,r3
	ctx.r8.u64 = ctx.r7.u64 & ~ctx.r3.u64;
	// stwx r9,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r9.u32);
	// twlgei r8,-1
	// blt cr6,0x82145da0
	if (cr6.lt) goto loc_82145DA0;
loc_82145DE8:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82145eb0
	if (cr6.lt) goto loc_82145EB0;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x82145eb0
	if (!cr6.lt) goto loc_82145EB0;
	// clrlwi r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82145ea0
	if (cr6.eq) goto loc_82145EA0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145708
	ctx.lr = 0x82145E1C;
	sub_82145708(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x82145ea0
	if (cr6.gt) goto loc_82145EA0;
	// lis r12,-32236
	r12.s64 = -2112618496;
	// addi r12,r12,24124
	r12.s64 = r12.s64 + 24124;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,24176(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 24176);
	// lwz r16,24176(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 24176);
	// lwz r16,24224(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 24224);
	// lwz r16,24192(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 24192);
loc_82145E4C:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r27,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r27.u32);
	// mr r30,r27
	r30.u64 = r27.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// stw r9,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r9.u32);
	// b 0x82145d3c
	goto loc_82145D3C;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145698
	ctx.lr = 0x82145E90;
	sub_82145698(ctx, base);
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82145EA0:
	// li r30,2
	r30.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82145EB0:
	// li r30,3
	r30.s64 = 3;
loc_82145EB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82145EC0:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82145CA8) {
	__imp__sub_82145CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82145ECC) {
	__imp__sub_82145ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145ED0) {
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
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82145f14
	if (!cr6.eq) goto loc_82145F14;
	// lbz r11,78(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 78);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x82145398
	ctx.lr = 0x82145F00;
	sub_82145398(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82145f14
	if (cr6.eq) goto loc_82145F14;
	// li r11,2
	r11.s64 = 2;
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
loc_82145F14:
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

PPC_WEAK_FUNC(sub_82145ED0) {
	__imp__sub_82145ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82145F28) {
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
	ctx.lr = 0x82145F30;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r26,0
	r26.s64 = 0;
	// addi r10,r11,5608
	ctx.r10.s64 = r11.s64 + 5608;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r26
	r25.u64 = r26.u64;
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
loc_82145F54:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82145f54
	if (!cr6.eq) goto loc_82145F54;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82145F70;
	sub_821C90C0(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r24,r11,65535
	r24.u64 = r11.u64 | 65535;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// sth r24,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r24.u16);
	// ble cr6,0x82145f94
	if (!cr6.gt) goto loc_82145F94;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82146224
	if (cr6.eq) goto loc_82146224;
loc_82145F94:
	// lhz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// bl 0x821372d8
	ctx.lr = 0x82145F9C;
	sub_821372D8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82145fc4
	if (!cr6.eq) goto loc_82145FC4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// addi r3,r11,14760
	ctx.r3.s64 = r11.s64 + 14760;
	// bl 0x82130000
	ctx.lr = 0x82145FB8;
	sub_82130000(ctx, base);
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// sth r10,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r10.u16);
	// b 0x82146200
	goto loc_82146200;
loc_82145FC4:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_82145FC8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82145fc8
	if (!cr6.eq) goto loc_82145FC8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82145FDC:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82145fdc
	if (!cr6.eq) goto loc_82145FDC;
	// lhz r11,64(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r24,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r24.u16);
	// stb r26,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r26.u8);
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// stb r9,71(r31)
	PPC_STORE_U8(r31.u32 + 71, ctx.r9.u8);
	// sth r11,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r11.u16);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x8214601C;
	sub_821C9108(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821bce68
	ctx.lr = 0x8214602C;
	sub_821BCE68(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x821461b0
	if (cr6.eq) goto loc_821461B0;
	// lwz r30,120(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// mr r28,r26
	r28.u64 = r26.u64;
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// mr r27,r30
	r27.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82146058
	if (cr6.eq) goto loc_82146058;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// b 0x82146154
	goto loc_82146154;
loc_82146058:
	// lwz r29,100(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82146074
	if (cr6.lt) goto loc_82146074;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145a98
	ctx.lr = 0x82146070;
	sub_82145A98(ctx, base);
	// b 0x82146078
	goto loc_82146078;
loc_82146074:
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
loc_82146078:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x821460c4
	if (cr6.lt) goto loc_821460C4;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x82146098
	if (!cr6.lt) goto loc_82146098;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82146098:
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r8,r10,31
	ctx.r8.s64 = ctx.r10.s64 + 31;
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mullw r9,r7,r3
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r30,r7,r11
	r30.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// lwzx r27,r6,r31
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// add r28,r9,r10
	r28.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x82146154
	goto loc_82146154;
loc_821460C4:
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82146110
	if (cr6.lt) goto loc_82146110;
	// bl 0x821372d8
	ctx.lr = 0x821460D4;
	sub_821372D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821460f8
	if (cr6.eq) goto loc_821460F8;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x821460E4;
	sub_821372D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,14672
	ctx.r3.s64 = r11.s64 + 14672;
	// b 0x82146140
	goto loc_82146140;
loc_821460F8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,14672
	ctx.r3.s64 = r11.s64 + 14672;
	// b 0x82146140
	goto loc_82146140;
loc_82146110:
	// bl 0x821372d8
	ctx.lr = 0x82146114;
	sub_821372D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214612c
	if (cr6.eq) goto loc_8214612C;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x82146124;
	sub_821372D8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82146134
	goto loc_82146134;
loc_8214612C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
loc_82146134:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r3,r11,14584
	ctx.r3.s64 = r11.s64 + 14584;
loc_82146140:
	// bl 0x82130000
	ctx.lr = 0x82146144;
	sub_82130000(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bd220
	ctx.lr = 0x8214614C;
	sub_821BD220(ctx, base);
	// mr r30,r26
	r30.u64 = r26.u64;
	// li r25,1
	r25.s64 = 1;
loc_82146154:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821461b4
	if (!cr6.eq) goto loc_821461B4;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bc5e8
	ctx.lr = 0x82146168;
	sub_821BC5E8(ctx, base);
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// ble cr6,0x82146178
	if (!cr6.gt) goto loc_82146178;
	// subf r30,r28,r3
	r30.s64 = ctx.r3.s64 - r28.s64;
loc_82146178:
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821bd600
	ctx.lr = 0x821461A0;
	sub_821BD600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821461b4
	if (!cr6.eq) goto loc_821461B4;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bd220
	ctx.lr = 0x821461B0;
	sub_821BD220(ctx, base);
loc_821461B0:
	// li r25,1
	r25.s64 = 1;
loc_821461B4:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214622c
	if (cr6.eq) goto loc_8214622C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821461C8;
	sub_821C90C0(ctx, base);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821461e8
	if (cr6.eq) goto loc_821461E8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,9484
	ctx.r3.s64 = r11.s64 + 9484;
	// bl 0x82130000
	ctx.lr = 0x821461E4;
	sub_82130000(ctx, base);
	// b 0x821461f8
	goto loc_821461F8;
loc_821461E8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,9456
	ctx.r3.s64 = r11.s64 + 9456;
	// bl 0x82130000
	ctx.lr = 0x821461F8;
	sub_82130000(ctx, base);
loc_821461F8:
	// lhz r11,66(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// sth r11,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r11.u16);
loc_82146200:
	// stb r26,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r26.u8);
	// stb r26,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r26.u8);
	// stb r26,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r26.u8);
	// stw r26,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// sth r24,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r24.u16);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// sth r24,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r24.u16);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
loc_82146224:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x8214622C;
	sub_821C9108(ctx, base);
loc_8214622C:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82145F28) {
	__imp__sub_82145F28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82146234) {
	__imp__sub_82146234(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146238) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82146258;
	sub_821C90C0(ctx, base);
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82146624
	if (cr6.eq) goto loc_82146624;
	// lbz r11,77(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 77);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821465b8
	if (!cr6.eq) goto loc_821465B8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// bl 0x82145208
	ctx.lr = 0x82146280;
	sub_82145208(ctx, base);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lfs f0,14872(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14872);
	f0.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r10.u32);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r8.u32);
	// lwz r7,120(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r5,36(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r11,3
	ctx.r4.s64 = r11.s64 + 3;
	// rlwinm r30,r4,3,0,28
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r30,r6
	ctx.r3.s64 = ctx.r6.s64 - r30.s64;
	// clrldi r11,r3,32
	r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x821462E4;
	sub_823DBA38(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14868(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14868);
	f0.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// clrldi r8,r11,32
	ctx.r8.u64 = r11.u64 & 0xFFFFFFFF;
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f1,f6,f0
	ctx.f1.f64 = double(float(ctx.f6.f64 * f0.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x82146328;
	sub_823DBAA8(ctx, base);
	// frsp f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// lwz r30,100(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r6,r7,11,0,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 11) & 0xFFFFF800;
	// stw r6,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r6.u32);
	// blt cr6,0x8214635c
	if (cr6.lt) goto loc_8214635C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145a98
	ctx.lr = 0x82146358;
	sub_82145A98(ctx, base);
	// b 0x82146360
	goto loc_82146360;
loc_8214635C:
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
loc_82146360:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821463f0
	if (!cr6.eq) goto loc_821463F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145338
	ctx.lr = 0x82146370;
	sub_82145338(ctx, base);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x82145a98
	ctx.lr = 0x82146378;
	sub_82145A98(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r11,r11,27
	r11.s64 = r11.s64 + 27;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r3.u32);
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821463a0
	if (!cr6.lt) goto loc_821463A0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821463A0:
	// li r11,1
	r11.s64 = 1;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x821463e8
	if (!cr6.gt) goto loc_821463E8;
loc_821463B0:
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r10,27
	ctx.r8.s64 = ctx.r10.s64 + 27;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,27
	ctx.r6.s64 = ctx.r10.s64 + 27;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r7,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r4,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r4.u32);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// blt cr6,0x821463b0
	if (cr6.lt) goto loc_821463B0;
loc_821463E8:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// b 0x821466b4
	goto loc_821466B4;
loc_821463F0:
	// ble cr6,0x821464fc
	if (!cr6.gt) goto loc_821464FC;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x82146410
	if (cr6.lt) goto loc_82146410;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82146410:
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mullw r9,r7,r6
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r8,r6,r3
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r3.s32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// add r30,r8,r10
	r30.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x821bc5e8
	ctx.lr = 0x8214644C;
	sub_821BC5E8(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// cmplw cr6,r4,r3
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, xer);
	// ble cr6,0x82146464
	if (!cr6.gt) goto loc_82146464;
	// subf r11,r30,r3
	r11.s64 = ctx.r3.s64 - r30.s64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
loc_82146464:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821bd600
	ctx.lr = 0x82146484;
	sub_821BD600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821466cc
	if (!cr6.eq) goto loc_821466CC;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x82146494;
	sub_821372D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821464ac
	if (cr6.eq) goto loc_821464AC;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x821464A4;
	sub_821372D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821464b4
	goto loc_821464B4;
loc_821464AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,9040
	ctx.r4.s64 = r11.s64 + 9040;
loc_821464B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,14820
	ctx.r3.s64 = r11.s64 + 14820;
	// bl 0x82130000
	ctx.lr = 0x821464C0;
	sub_82130000(ctx, base);
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// b 0x821466cc
	goto loc_821466CC;
loc_821464FC:
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82146548
	if (cr6.lt) goto loc_82146548;
	// bl 0x821372d8
	ctx.lr = 0x8214650C;
	sub_821372D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82146530
	if (cr6.eq) goto loc_82146530;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x8214651C;
	sub_821372D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,14672
	ctx.r3.s64 = r11.s64 + 14672;
	// b 0x82146578
	goto loc_82146578;
loc_82146530:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,14672
	ctx.r3.s64 = r11.s64 + 14672;
	// b 0x82146578
	goto loc_82146578;
loc_82146548:
	// bl 0x821372d8
	ctx.lr = 0x8214654C;
	sub_821372D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82146564
	if (cr6.eq) goto loc_82146564;
	// lhz r3,66(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821372d8
	ctx.lr = 0x8214655C;
	sub_821372D8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8214656c
	goto loc_8214656C;
loc_82146564:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
loc_8214656C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r3,r11,14584
	ctx.r3.s64 = r11.s64 + 14584;
loc_82146578:
	// bl 0x82130000
	ctx.lr = 0x8214657C;
	sub_82130000(ctx, base);
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// ori r10,r8,65535
	ctx.r10.u64 = ctx.r8.u64 | 65535;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// b 0x821466cc
	goto loc_821466CC;
loc_821465B8:
	// bl 0x82145338
	ctx.lr = 0x821465BC;
	sub_82145338(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x82145a98
	ctx.lr = 0x821465C8;
	sub_82145A98(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r10,r11,27
	ctx.r10.s64 = r11.s64 + 27;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r3.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// ble cr6,0x821466ac
	if (!cr6.gt) goto loc_821466AC;
loc_821465E8:
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r10,27
	ctx.r8.s64 = ctx.r10.s64 + 27;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,27
	ctx.r6.s64 = ctx.r10.s64 + 27;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r7,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r4,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r4.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// blt cr6,0x821465e8
	if (cr6.lt) goto loc_821465E8;
	// b 0x821466ac
	goto loc_821466AC;
loc_82146624:
	// bl 0x82145338
	ctx.lr = 0x82146628;
	sub_82145338(ctx, base);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82146650
	if (cr6.lt) goto loc_82146650;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145a98
	ctx.lr = 0x8214663C;
	sub_82145A98(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r11,r11,27
	r11.s64 = r11.s64 + 27;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r3.u32);
	// b 0x82146664
	goto loc_82146664;
loc_82146650:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r9,r11,27
	ctx.r9.s64 = r11.s64 + 27;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, ctx.r10.u32);
loc_82146664:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x821466ac
	if (!cr6.gt) goto loc_821466AC;
loc_82146674:
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r10,27
	ctx.r8.s64 = ctx.r10.s64 + 27;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,27
	ctx.r6.s64 = ctx.r10.s64 + 27;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r7,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r4,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r4.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// blt cr6,0x82146674
	if (cr6.lt) goto loc_82146674;
loc_821466AC:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
loc_821466B4:
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stb r9,71(r31)
	PPC_STORE_U8(r31.u32 + 71, ctx.r9.u8);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stw r7,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r7.u32);
loc_821466CC:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x821466D4;
	sub_821C9108(ctx, base);
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821466e8
	if (!cr6.eq) goto loc_821466E8;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bd220
	ctx.lr = 0x821466E8;
	sub_821BD220(ctx, base);
loc_821466E8:
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

PPC_WEAK_FUNC(sub_82146238) {
	__imp__sub_82146238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146700) {
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
	ctx.lr = 0x82146708;
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
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82146720;
	sub_821C90C0(ctx, base);
	// lbz r11,77(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 77);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214675c
	if (cr6.eq) goto loc_8214675C;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82145190
	ctx.lr = 0x82146744;
	sub_82145190(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8214675c
	if (cr6.lt) goto loc_8214675C;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwzx r29,r10,r9
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8214675C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82146764;
	sub_821C9108(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82146700) {
	__imp__sub_82146700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146770) {
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
	ctx.lr = 0x82146778;
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
	// li r27,3
	r27.s64 = 3;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82146794;
	sub_821C90C0(ctx, base);
	// lbz r11,77(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 77);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821467dc
	if (cr6.eq) goto loc_821467DC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145a98
	ctx.lr = 0x821467B0;
	sub_82145A98(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x821467e0
	if (cr6.lt) goto loc_821467E0;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x821467d4
	if (!cr6.lt) goto loc_821467D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x82145a98
	ctx.lr = 0x821467D4;
	sub_82145A98(ctx, base);
loc_821467D4:
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// bne cr6,0x821467e0
	if (!cr6.eq) goto loc_821467E0;
loc_821467DC:
	// li r29,1
	r29.s64 = 1;
loc_821467E0:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214682c
	if (!cr6.eq) goto loc_8214682C;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214682c
	if (!cr6.eq) goto loc_8214682C;
	// lhz r11,66(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// clrlwi r10,r28,16
	ctx.r10.u64 = r28.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8214682c
	if (!cr6.eq) goto loc_8214682C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214682c
	if (cr6.eq) goto loc_8214682C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r27,0
	r27.s64 = 0;
	// bl 0x821c9108
	ctx.lr = 0x82146820;
	sub_821C9108(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8214682C:
	// lhz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82146848
	if (cr6.eq) goto loc_82146848;
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8214686c
	if (!cr6.eq) goto loc_8214686C;
loc_82146848:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214686c
	if (cr6.eq) goto loc_8214686C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r27,1
	r27.s64 = 1;
	// bl 0x821c9108
	ctx.lr = 0x82146860;
	sub_821C9108(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8214686C:
	// lhz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8214687c
	if (!cr6.eq) goto loc_8214687C;
	// li r27,2
	r27.s64 = 2;
loc_8214687C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82146884;
	sub_821C9108(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82146770) {
	__imp__sub_82146770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146890) {
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
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821468cc
	if (cr6.eq) goto loc_821468CC;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x821c9078
	ctx.lr = 0x821468B8;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821468cc
	if (cr6.eq) goto loc_821468CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82146238
	ctx.lr = 0x821468CC;
	sub_82146238(ctx, base);
loc_821468CC:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821468ec
	if (!cr6.eq) goto loc_821468EC;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821468ec
	if (cr6.eq) goto loc_821468EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145f28
	ctx.lr = 0x821468EC;
	sub_82145F28(ctx, base);
loc_821468EC:
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

PPC_WEAK_FUNC(sub_82146890) {
	__imp__sub_82146890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146900) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823dbbc8
	ctx.lr = 0x82146928;
	sub_823DBBC8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82146938;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f13,0(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

PPC_WEAK_FUNC(sub_82146900) {
	__imp__sub_82146900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214695C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214695C) {
	__imp__sub_8214695C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146960) {
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
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8244d150
	ctx.lr = 0x82146984;
	sub_8244D150(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8244d150
	ctx.lr = 0x82146994;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,23900
	ctx.r10.s64 = 23900;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
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

PPC_WEAK_FUNC(sub_82146960) {
	__imp__sub_82146960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821469CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821469CC) {
	__imp__sub_821469CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821469D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82146a00
	if (!cr6.eq) goto loc_82146A00;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
loc_82146A00:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82146a24
	if (!cr6.eq) goto loc_82146A24;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
loc_82146A24:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821469D0) {
	__imp__sub_821469D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82146a58
	if (!cr6.eq) goto loc_82146A58;
	// li r10,76
	ctx.r10.s64 = 76;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfiwx f13,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.f13.u32);
	// blr 
	return;
loc_82146A58:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82146a74
	if (!cr6.eq) goto loc_82146A74;
	// li r10,80
	ctx.r10.s64 = 80;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfiwx f13,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.f13.u32);
	// blr 
	return;
loc_82146A74:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146A30) {
	__imp__sub_82146A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146A80) {
	__imp__sub_82146A80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,104
	r11.s64 = 104;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146A90) {
	__imp__sub_82146A90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,96(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r3,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146AA0) {
	__imp__sub_82146AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82146AB4) {
	__imp__sub_82146AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146AB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,96(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// stw r3,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146AB8) {
	__imp__sub_82146AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82146ACC) {
	__imp__sub_82146ACC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146AD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrldi r11,r5,32
	r11.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,14892(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14892);
	f0.f64 = double(temp.f32);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// fmuls f30,f12,f0
	f30.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82146B1C;
	sub_823DBBC8(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82146B28;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// addi r11,r11,7444
	r11.s64 = r11.s64 + 7444;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f0,14888(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14888);
	f0.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82146b64
	if (cr6.eq) goto loc_82146B64;
	// fsubs f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 - f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// b 0x82146b80
	goto loc_82146B80;
loc_82146B64:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fadds f10,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f31.f64 + f0.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
loc_82146B80:
	// fadds f10,f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f9,f0,f11
	ctx.f9.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f11,14880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f31,f11
	ctx.f8.f64 = double(float(f31.f64 * ctx.f11.f64));
	// fdivs f7,f0,f10
	ctx.f7.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f6,0(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmuls f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f5,4(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fmuls f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f4,8(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fmuls f3,f8,f7
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfs f3,12(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f2,f9,f7
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f7.f64));
	// stfs f2,16(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82146AD0) {
	__imp__sub_82146AD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82146BE0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82146BE8;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,23900
	ctx.r10.s64 = 23900;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// subfc r8,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r8.s64 = r11.s64 - ctx.r10.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r6,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r9.s64;
	// clrlwi r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// mr r30,r11
	r30.u64 = r11.u64;
	// clrlwi r27,r5,31
	r27.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82146c3c
	if (!cr6.eq) goto loc_82146C3C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821475ec
	if (cr6.eq) goto loc_821475EC;
loc_82146C3C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823eaf00
	ctx.lr = 0x82146C44;
	sub_823EAF00(ctx, base);
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8244d5c0
	ctx.lr = 0x82146C58;
	sub_8244D5C0(ctx, base);
	// addi r28,r31,40
	r28.s64 = r31.s64 + 40;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d5c0
	ctx.lr = 0x82146C6C;
	sub_8244D5C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82146c98
	if (cr6.eq) goto loc_82146C98;
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82146c98
	if (cr6.eq) goto loc_82146C98;
	// stfs f31,176(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
loc_82146C98:
	// clrlwi r27,r27,24
	r27.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82146cc0
	if (cr6.eq) goto loc_82146CC0;
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82146cc0
	if (cr6.eq) goto loc_82146CC0;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_82146CC0:
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x82146d08
	if (cr6.eq) goto loc_82146D08;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82146ad0
	ctx.lr = 0x82146CE0;
	sub_82146AD0(ctx, base);
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f10,20(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_82146D08:
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x82146d54
	if (cr6.eq) goto loc_82146D54;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82146ad0
	ctx.lr = 0x82146D28;
	sub_82146AD0(ctx, base);
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f8,0(r28)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// stfs f9,44(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f10,48(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f12,56(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// b 0x82146d68
	goto loc_82146D68;
loc_82146D54:
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
loc_82146D68:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cntlzw r9,r27
	ctx.r9.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cntlzw r7,r30
	ctx.r7.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r5,101(r31)
	PPC_STORE_U8(r31.u32 + 101, ctx.r5.u8);
	// addi r11,r6,8
	r11.s64 = ctx.r6.s64 + 8;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r8,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r8.u32);
	// stb r4,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r4.u8);
	// b 0x82146db4
	goto loc_82146DB4;
loc_82146DA0:
	// lfs f12,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
loc_82146DB4:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82146e28
	if (cr6.eq) goto loc_82146E28;
	// lfs f7,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f5,f0,f13,f7
	ctx.f5.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f7.f64));
	// lfs f4,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f13,f5,f13,f4
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fmuls f1,f5,f6
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f6.f64));
	// fmuls f4,f5,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f7.f64));
	// fmuls f30,f13,f6
	f30.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// lfs f6,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f29,f13,f7
	f29.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// lfs f7,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f7.f64 = double(temp.f32);
	// fmsubs f1,f0,f6,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f6.f64 - ctx.f1.f64));
	// fmsubs f0,f0,f7,f4
	f0.f64 = double(float(f0.f64 * ctx.f7.f64 - ctx.f4.f64));
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f13,f5,f6,f30
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 - f30.f64));
	// fmsubs f7,f5,f7,f29
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 - f29.f64));
	// stfs f7,176(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f6,f1,f3
	ctx.f6.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// stfs f6,164(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fadds f5,f13,f2
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f2.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_82146E28:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82146e84
	if (cr6.eq) goto loc_82146E84;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f0,f8,f13
	ctx.f7.f64 = double(float(f0.f64 * ctx.f8.f64 + ctx.f13.f64));
	// lfs f6,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f13,f7,f8,f6
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmuls f3,f7,f11
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmuls f2,f7,f12
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmuls f1,f13,f11
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// fmuls f8,f13,f12
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f6,f0,f10,f2
	ctx.f6.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f2.f64));
	// stfs f6,120(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f3,f7,f9,f1
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f9.f64 - ctx.f1.f64));
	// fadds f2,f11,f5
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f5.f64));
	// stfs f2,116(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f1,f7,f10,f8
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 - ctx.f8.f64));
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f13,f3,f4
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_82146E84:
	// stfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82146efc
	if (cr6.eq) goto loc_82146EFC;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_82146EFC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82146f6c
	if (cr6.eq) goto loc_82146F6C;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_82146F6C:
	// stfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82146fe4
	if (cr6.eq) goto loc_82146FE4;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_82146FE4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82147054
	if (cr6.eq) goto loc_82147054;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_82147054:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// beq cr6,0x821470cc
	if (cr6.eq) goto loc_821470CC;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_821470CC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8214713c
	if (cr6.eq) goto loc_8214713C;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_8214713C:
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// beq cr6,0x821471b4
	if (cr6.eq) goto loc_821471B4;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_821471B4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82147224
	if (cr6.eq) goto loc_82147224;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_82147224:
	// stfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8214729c
	if (cr6.eq) goto loc_8214729C;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_8214729C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8214730c
	if (cr6.eq) goto loc_8214730C;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_8214730C:
	// stfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82147384
	if (cr6.eq) goto loc_82147384;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_82147384:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821473f4
	if (cr6.eq) goto loc_821473F4;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_821473F4:
	// stfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8214746c
	if (cr6.eq) goto loc_8214746C;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,168(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
loc_8214746C:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821474dc
	if (cr6.eq) goto loc_821474DC;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f8,f13,f7
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f8,f11
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmsubs f1,f0,f10,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f10.f64 - ctx.f4.f64));
	// fmuls f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmsubs f11,f0,f9,f3
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64 - ctx.f3.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fmsubs f10,f8,f10,f2
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 - ctx.f2.f64));
	// fadds f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f6.f64));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmsubs f6,f8,f9,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 - ctx.f12.f64));
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f5,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_821474DC:
	// stfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82146da0
	if (!cr0.eq) goto loc_82146DA0;
	// lwz r11,164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147504
	if (!cr6.eq) goto loc_82147504;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82147508
	goto loc_82147508;
loc_82147504:
	// lfs f0,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
loc_82147508:
	// lwz r11,172(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// stfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147524
	if (!cr6.eq) goto loc_82147524;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82147528
	goto loc_82147528;
loc_82147524:
	// lfs f0,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	f0.f64 = double(temp.f32);
loc_82147528:
	// lwz r11,168(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147544
	if (!cr6.eq) goto loc_82147544;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82147548
	goto loc_82147548;
loc_82147544:
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
loc_82147548:
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// stfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147564
	if (!cr6.eq) goto loc_82147564;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82147568
	goto loc_82147568;
loc_82147564:
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	f0.f64 = double(temp.f32);
loc_82147568:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147584
	if (!cr6.eq) goto loc_82147584;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82147588
	goto loc_82147588;
loc_82147584:
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
loc_82147588:
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821475a4
	if (!cr6.eq) goto loc_821475A4;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x821475a8
	goto loc_821475A8;
loc_821475A4:
	// lfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	f0.f64 = double(temp.f32);
loc_821475A8:
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821475c4
	if (!cr6.eq) goto loc_821475C4;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x821475c8
	goto loc_821475C8;
loc_821475C4:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
loc_821475C8:
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821475e4
	if (!cr6.eq) goto loc_821475E4;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x821475e8
	goto loc_821475E8;
loc_821475E4:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
loc_821475E8:
	// stfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_821475EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

PPC_WEAK_FUNC(sub_82146BE0) {
	__imp__sub_82146BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82147604) {
	__imp__sub_82147604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147608) {
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
	ctx.lr = 0x82147610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r4,104
	ctx.r4.s64 = 104;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82147638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214767c
	if (cr6.eq) goto loc_8214767C;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,23900
	r11.s64 = 23900;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// addi r6,r8,14900
	ctx.r6.s64 = ctx.r8.s64 + 14900;
	// stw r10,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// stw r7,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r7.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r9,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r9.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// b 0x82147680
	goto loc_82147680;
loc_8214767C:
	// li r31,0
	r31.s64 = 0;
loc_82147680:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214769C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82147608) {
	__imp__sub_82147608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821476AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821476AC) {
	__imp__sub_821476AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821476B0) {
	PPC_FUNC_PROLOGUE();
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
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vcfpsxws128 v62,v2,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_si128((simde__m128i*)v62.s32, simde_mm_vctsxs(simde_mm_load_ps(ctx.v2.f32)));
	// vrfiz128 v61,v2
	simde_mm_store_ps(v61.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v2.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// vspltisw128 v58,-9
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0xFFFFFFF7)));
	// vslw128 v57,v63,v63
	v57.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v57.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v57.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v57.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vcmpeqfp128 v56,v1,v59
	simde_mm_store_ps(v56.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v59.f32)));
	// vupkd3d128 v55,v59,4
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v55 = vTemp;
	// vcmpgtfp128 v54,v59,v2
	simde_mm_store_ps(v54.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vslw128 v53,v63,v58
	v53.u32[0] = v63.u32[0] << (v58.u8[0] & 0x1F);
	v53.u32[1] = v63.u32[1] << (v58.u8[4] & 0x1F);
	v53.u32[2] = v63.u32[2] << (v58.u8[8] & 0x1F);
	v53.u32[3] = v63.u32[3] << (v58.u8[12] & 0x1F);
	// vandc128 v52,v1,v57
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// vcmpeqfp128 v0,v2,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v59.f32)));
	// vand128 v51,v1,v57
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vcmpgtfp128 v50,v59,v1
	simde_mm_store_ps(v50.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vspltw128 v13,v55,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x0));
	// vsrw128 v12,v53,v60
	ctx.v12.u32[0] = v53.u32[0] >> (v60.u8[0] & 0x1F);
	ctx.v12.u32[1] = v53.u32[1] >> (v60.u8[4] & 0x1F);
	ctx.v12.u32[2] = v53.u32[2] >> (v60.u8[8] & 0x1F);
	ctx.v12.u32[3] = v53.u32[3] >> (v60.u8[12] & 0x1F);
	// vlogefp128 v49,v52
	v49.f32[0] = log2f(v52.f32[0]);
	v49.f32[1] = log2f(v52.f32[1]);
	v49.f32[2] = log2f(v52.f32[2]);
	v49.f32[3] = log2f(v52.f32[3]);
	// vand128 v48,v62,v60
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpeqfp128 v47,v2,v61
	simde_mm_store_ps(v47.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v61.f32)));
	// vslw128 v46,v48,v63
	v46.u32[0] = v48.u32[0] << (v63.u8[0] & 0x1F);
	v46.u32[1] = v48.u32[1] << (v63.u8[4] & 0x1F);
	v46.u32[2] = v48.u32[2] << (v63.u8[8] & 0x1F);
	v46.u32[3] = v48.u32[3] << (v63.u8[12] & 0x1F);
	// vandc128 v11,v56,v54
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vand128 v45,v51,v46
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v46.u8)));
	// vor128 v44,v56,v0
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vmulfp128 v43,v49,v2
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vor128 v10,v59,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// vandc128 v42,v50,v47
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vsel v9,v12,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vor128 v8,v42,v44
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vsel v7,v9,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vexptefp128 v41,v43
	v41.f32[0] = exp2f(v43.f32[0]);
	v41.f32[1] = exp2f(v43.f32[1]);
	v41.f32[2] = exp2f(v43.f32[2]);
	v41.f32[3] = exp2f(v43.f32[3]);
	// vor128 v6,v41,v45
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// vsel v1,v6,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821476B0) {
	__imp__sub_821476B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9cc
	ctx.lr = 0x82147750;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82147bfc
	if (!cr6.eq) goto loc_82147BFC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823eaf00
	ctx.lr = 0x82147770;
	sub_823EAF00(ctx, base);
	// lbz r10,97(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f12,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// beq cr6,0x82147bfc
	if (cr6.eq) goto loc_82147BFC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f5,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
loc_821477A8:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// slw r10,r3,r4
	ctx.r10.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r4.u8 & 0x3F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82147be8
	if (cr6.eq) goto loc_82147BE8;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lbz r30,75(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 75);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfsx f7,r6,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f6,r9,r6
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	ctx.f6.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfsx f9,r8,r6
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f9.f64 = double(temp.f32);
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// lfsx f8,r7,r6
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	ctx.f8.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stfs f7,88(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f6,92(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// beq cr6,0x82147a20
	if (cr6.eq) goto loc_82147A20;
loc_821477FC:
	// lfs f4,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// addi r9,r11,20
	ctx.r9.s64 = r11.s64 + 20;
	// fmadds f3,f4,f0,f9
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f9.f64));
	// lfs f30,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f30.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// addi r8,r11,24
	ctx.r8.s64 = r11.s64 + 24;
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f9,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lfs f31,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f31.f64 = double(temp.f32);
	// fmuls f29,f3,f11
	f29.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmadds f7,f3,f0,f7
	ctx.f7.f64 = double(float(ctx.f3.f64 * f0.f64 + ctx.f7.f64));
	// fmuls f28,f3,f10
	f28.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmsubs f29,f4,f13,f29
	f29.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - f29.f64));
	// fmuls f27,f7,f11
	f27.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmuls f26,f7,f10
	f26.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmuls f7,f7,f30
	ctx.f7.f64 = double(float(ctx.f7.f64 * f30.f64));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmsubs f4,f4,f12,f28
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - f28.f64));
	// lfs f7,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f7.f64 = double(temp.f32);
	// fadds f8,f29,f8
	ctx.f8.f64 = double(float(f29.f64 + ctx.f8.f64));
	// fmsubs f30,f3,f13,f27
	f30.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 - f27.f64));
	// fmsubs f3,f3,f12,f26
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 - f26.f64));
	// fmadds f8,f2,f0,f8
	ctx.f8.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f8.f64));
	// fadds f6,f30,f6
	ctx.f6.f64 = double(float(f30.f64 + ctx.f6.f64));
	// fmuls f30,f8,f11
	f30.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmadds f6,f8,f0,f6
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f6.f64));
	// fmuls f29,f8,f10
	f29.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// fmsubs f30,f2,f13,f30
	f30.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 - f30.f64));
	// fmuls f28,f6,f11
	f28.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f7,4(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmuls f27,f6,f10
	f27.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// fadds f6,f30,f4
	ctx.f6.f64 = double(float(f30.f64 + ctx.f4.f64));
	// lfs f4,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f4.f64 = double(temp.f32);
	// fmsubs f7,f8,f13,f28
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 - f28.f64));
	// fmsubs f2,f2,f12,f29
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 - f29.f64));
	// fmsubs f8,f8,f12,f27
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 - f27.f64));
	// fmadds f6,f1,f0,f6
	ctx.f6.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f6.f64));
	// fadds f3,f7,f3
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fmuls f7,f6,f11
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmadds f3,f6,f0,f3
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f3.f64));
	// fmuls f30,f6,f10
	f30.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// fmsubs f7,f1,f13,f7
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - ctx.f7.f64));
	// fmuls f29,f3,f11
	f29.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f4,f3,f4
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f4.f64));
	// stfs f4,8(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmuls f28,f3,f10
	f28.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fadds f3,f7,f2
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f2.f64));
	// lfs f2,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// fmsubs f7,f6,f13,f29
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 - f29.f64));
	// fmsubs f1,f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f12.f64 - f30.f64));
	// fmsubs f6,f6,f12,f28
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f12.f64 - f28.f64));
	// fmadds f4,f9,f0,f3
	ctx.f4.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f3.f64));
	// fadds f3,f7,f8
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// fmuls f8,f4,f11
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmadds f7,f4,f0,f3
	ctx.f7.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f3.f64));
	// fmuls f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fmsubs f8,f9,f13,f8
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 - ctx.f8.f64));
	// fmuls f30,f7,f11
	f30.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmuls f29,f7,f10
	f29.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmuls f2,f7,f2
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// stfs f2,12(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fadds f1,f8,f1
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f1.f64));
	// fmsubs f8,f4,f13,f30
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - f30.f64));
	// fmsubs f7,f4,f12,f29
	ctx.f7.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - f29.f64));
	// fmsubs f3,f9,f12,f3
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f3.f64));
	// lfs f9,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f4,f31,f0,f1
	ctx.f4.f64 = double(float(f31.f64 * f0.f64 + ctx.f1.f64));
	// fadds f2,f8,f6
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f6.f64));
	// fmuls f1,f4,f11
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmadds f8,f4,f0,f2
	ctx.f8.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f2.f64));
	// fmuls f6,f4,f10
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fmsubs f2,f31,f13,f1
	ctx.f2.f64 = double(float(f31.f64 * ctx.f13.f64 - ctx.f1.f64));
	// fmuls f1,f8,f11
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f30,f8,f10
	f30.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// fmuls f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fmsubs f8,f4,f13,f1
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - ctx.f1.f64));
	// fadds f3,f2,f3
	ctx.f3.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// fmsubs f6,f31,f12,f6
	ctx.f6.f64 = double(float(f31.f64 * ctx.f12.f64 - ctx.f6.f64));
	// fmsubs f2,f4,f12,f30
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - f30.f64));
	// fadds f1,f8,f7
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// lfs f8,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r11,28
	ctx.r7.s64 = r11.s64 + 28;
	// fmadds f7,f8,f0,f3
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f3.f64));
	// stfs f9,16(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lfs f3,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f4,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// lfs f31,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f31.f64 = double(temp.f32);
	// fmuls f9,f7,f11
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fmadds f1,f7,f0,f1
	ctx.f1.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f1.f64));
	// fmuls f30,f7,f10
	f30.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmsubs f9,f8,f13,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 - ctx.f9.f64));
	// fmuls f29,f1,f11
	f29.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f3,f1,f3
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f3.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fmuls f28,f1,f10
	f28.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fadds f1,f9,f6
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f6.f64));
	// lfs f9,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmsubs f6,f7,f13,f29
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 - f29.f64));
	// fmsubs f8,f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 - f30.f64));
	// fmsubs f3,f7,f12,f28
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 - f28.f64));
	// fmadds f1,f4,f0,f1
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f1.f64));
	// fadds f7,f6,f2
	ctx.f7.f64 = double(float(ctx.f6.f64 + ctx.f2.f64));
	// fmuls f6,f1,f11
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmadds f2,f1,f0,f7
	ctx.f2.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f7.f64));
	// fmuls f7,f1,f10
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmsubs f6,f4,f13,f6
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - ctx.f6.f64));
	// fmuls f30,f2,f11
	f30.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// fmuls f29,f2,f10
	f29.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f2,f2,f9
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f9.f64));
	// stfs f2,0(r8)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fadds f9,f6,f8
	ctx.f9.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// lfs f8,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// fmsubs f4,f4,f12,f7
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - ctx.f7.f64));
	// fmsubs f7,f1,f13,f30
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - f30.f64));
	// fmsubs f2,f1,f12,f29
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f12.f64 - f29.f64));
	// fmadds f1,f31,f0,f9
	ctx.f1.f64 = double(float(f31.f64 * f0.f64 + ctx.f9.f64));
	// fadds f9,f7,f3
	ctx.f9.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// fmuls f7,f1,f11
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f3,f1,f10
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmadds f6,f1,f0,f9
	ctx.f6.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f9.f64));
	// fmsubs f9,f31,f13,f7
	ctx.f9.f64 = double(float(f31.f64 * ctx.f13.f64 - ctx.f7.f64));
	// fmuls f7,f6,f11
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f30,f6,f10
	f30.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// fmuls f6,f6,f8
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// stfs f6,0(r7)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmsubs f7,f1,f13,f7
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - ctx.f7.f64));
	// fadds f9,f9,f4
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f4.f64));
	// fmsubs f8,f31,f12,f3
	ctx.f8.f64 = double(float(f31.f64 * ctx.f12.f64 - ctx.f3.f64));
	// fmsubs f6,f1,f12,f30
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f12.f64 - f30.f64));
	// fadds f7,f7,f2
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f2.f64));
	// bne 0x821477fc
	if (!cr0.eq) goto loc_821477FC;
	// stfs f7,88(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f6,92(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// b 0x82147b6c
	goto loc_82147B6C;
loc_82147A20:
	// lfs f4,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmadds f3,f4,f0,f9
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f9.f64));
	// lfs f28,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f28.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f9,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lfs f31,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f31.f64 = double(temp.f32);
	// lfs f30,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f30.f64 = double(temp.f32);
	// lfs f29,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f29.f64 = double(temp.f32);
	// lfs f27,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f27.f64 = double(temp.f32);
	// fmuls f26,f3,f11
	f26.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f25,f3,f10
	f25.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmuls f3,f3,f28
	ctx.f3.f64 = double(float(ctx.f3.f64 * f28.f64));
	// stfs f3,0(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f3,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// fmsubs f28,f4,f13,f26
	f28.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - f26.f64));
	// fmsubs f4,f4,f12,f25
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - f25.f64));
	// fadds f8,f28,f8
	ctx.f8.f64 = double(float(f28.f64 + ctx.f8.f64));
	// fmadds f8,f2,f0,f8
	ctx.f8.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f8.f64));
	// fmuls f28,f8,f11
	f28.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f3,f8,f3
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f3.f64));
	// stfs f3,4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmuls f26,f8,f10
	f26.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// lfs f3,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// fmsubs f8,f2,f13,f28
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 - f28.f64));
	// fmsubs f2,f2,f12,f26
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 - f26.f64));
	// fadds f8,f8,f4
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f4.f64));
	// fmadds f4,f1,f0,f8
	ctx.f4.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f8.f64));
	// fmuls f8,f4,f11
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmuls f28,f4,f10
	f28.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fmuls f4,f4,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// stfs f4,8(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmsubs f3,f1,f13,f8
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - ctx.f8.f64));
	// lfs f8,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// fmsubs f4,f1,f12,f28
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f12.f64 - f28.f64));
	// fadds f3,f3,f2
	ctx.f3.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// fmadds f2,f9,f0,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f3.f64));
	// fmuls f1,f2,f11
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// fmuls f3,f2,f10
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f2,f2,f8
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f8.f64));
	// stfs f2,12(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fmsubs f1,f9,f13,f1
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 - ctx.f1.f64));
	// lfs f8,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// fmsubs f3,f9,f12,f3
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f3.f64));
	// fadds f2,f1,f4
	ctx.f2.f64 = double(float(ctx.f1.f64 + ctx.f4.f64));
	// fmadds f1,f31,f0,f2
	ctx.f1.f64 = double(float(f31.f64 * f0.f64 + ctx.f2.f64));
	// fmuls f9,f1,f11
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f2,f1,f8
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// stfs f2,16(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fmuls f4,f1,f10
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmsubs f1,f31,f13,f9
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64 - ctx.f9.f64));
	// lfs f9,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmsubs f8,f31,f12,f4
	ctx.f8.f64 = double(float(f31.f64 * ctx.f12.f64 - ctx.f4.f64));
	// fadds f4,f1,f3
	ctx.f4.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// fmadds f3,f30,f0,f4
	ctx.f3.f64 = double(float(f30.f64 * f0.f64 + ctx.f4.f64));
	// fmuls f2,f3,f11
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f1,f3,f10
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmuls f9,f3,f9
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// stfs f9,20(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// fmsubs f4,f30,f13,f2
	ctx.f4.f64 = double(float(f30.f64 * ctx.f13.f64 - ctx.f2.f64));
	// lfs f3,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// fmsubs f2,f30,f12,f1
	ctx.f2.f64 = double(float(f30.f64 * ctx.f12.f64 - ctx.f1.f64));
	// fadds f1,f4,f8
	ctx.f1.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// fmadds f9,f29,f0,f1
	ctx.f9.f64 = double(float(f29.f64 * f0.f64 + ctx.f1.f64));
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f4,f9,f10
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f3,f9,f3
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f3.f64));
	// stfs f3,24(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// fmsubs f1,f29,f13,f8
	ctx.f1.f64 = double(float(f29.f64 * ctx.f13.f64 - ctx.f8.f64));
	// lfs f9,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// fmsubs f8,f29,f12,f4
	ctx.f8.f64 = double(float(f29.f64 * ctx.f12.f64 - ctx.f4.f64));
	// fadds f4,f1,f2
	ctx.f4.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fmadds f3,f27,f0,f4
	ctx.f3.f64 = double(float(f27.f64 * f0.f64 + ctx.f4.f64));
	// fmuls f2,f3,f11
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f1,f3,f9
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// stfs f1,28(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// fmsubs f9,f27,f13,f2
	ctx.f9.f64 = double(float(f27.f64 * ctx.f13.f64 - ctx.f2.f64));
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// fmuls f4,f3,f10
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fadds f9,f9,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// fmsubs f8,f27,f12,f4
	ctx.f8.f64 = double(float(f27.f64 * ctx.f12.f64 - ctx.f4.f64));
	// bne 0x82147a20
	if (!cr0.eq) goto loc_82147A20;
loc_82147B6C:
	// stfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,0,1,8
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// stfs f8,84(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147b88
	if (!cr6.eq) goto loc_82147B88;
	// fmr f9,f5
	ctx.f9.f64 = ctx.f5.f64;
loc_82147B88:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// stfsx f9,r11,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82147ba4
	if (!cr6.eq) goto loc_82147BA4;
	// fmr f8,f5
	ctx.f8.f64 = ctx.f5.f64;
loc_82147BA4:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// stfsx f8,r11,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82147bc0
	if (!cr6.eq) goto loc_82147BC0;
	// fmr f7,f5
	ctx.f7.f64 = ctx.f5.f64;
loc_82147BC0:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// stfsx f7,r6,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82147bdc
	if (!cr6.eq) goto loc_82147BDC;
	// fmr f6,f5
	ctx.f6.f64 = ctx.f5.f64;
loc_82147BDC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stfsx f6,r11,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
loc_82147BE8:
	// lbz r10,97(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r5,r5,1024
	ctx.r5.s64 = ctx.r5.s64 + 1024;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// blt cr6,0x821477a8
	if (cr6.lt) goto loc_821477A8;
loc_82147BFC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba18
	ctx.lr = 0x82147C0C;
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

PPC_WEAK_FUNC(sub_82147738) {
	__imp__sub_82147738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147C20) {
	__imp__sub_82147C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147C38) {
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
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82147c84
	if (!cr6.eq) goto loc_82147C84;
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x8244d5c0
	ctx.lr = 0x82147C6C;
	sub_8244D5C0(ctx, base);
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
loc_82147C84:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
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

PPC_WEAK_FUNC(sub_82147C38) {
	__imp__sub_82147C38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147CA0) {
	__imp__sub_82147CA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// addi r10,r11,76
	ctx.r10.s64 = r11.s64 + 76;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147CB0) {
	__imp__sub_82147CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147CC8) {
	__imp__sub_82147CC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82147CDC) {
	__imp__sub_82147CDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r3,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r3.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// bnelr 
	if (!cr0.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147CE0) {
	__imp__sub_82147CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82147D10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r20{};
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
	ctx.lr = 0x82147D24;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f13,14892(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14892);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f30,f0,f13
	f30.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bne cr6,0x82148110
	if (!cr6.eq) goto loc_82148110;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bgt cr6,0x82148110
	if (cr6.gt) goto loc_82148110;
	// lis r12,-32236
	r12.s64 = -2112618496;
	// addi r12,r12,32108
	r12.s64 = r12.s64 + 32108;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,32152(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32152);
	// lwz r16,32152(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32152);
	// lwz r16,32316(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32316);
	// lwz r16,32316(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32316);
	// lwz r16,32492(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32492);
	// lwz r16,32492(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32492);
	// lwz r16,32628(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32628);
	// lwz r16,32628(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32628);
	// lwz r16,32744(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32744);
	// lwz r16,32744(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 32744);
	// lwz r16,-32648(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -32648);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,75(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 75);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f29,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82147dbc
	if (cr6.eq) goto loc_82147DBC;
	// fmr f28,f29
	f28.f64 = f29.f64;
	// b 0x82147dc0
	goto loc_82147DC0;
loc_82147DBC:
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	f28.f64 = f31.f64;
loc_82147DC0:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82147DC8;
	sub_823DBBC8(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82147DD4;
	sub_823DBAE8(ctx, base);
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fdivs f1,f29,f13
	ctx.f1.f64 = double(float(f29.f64 / ctx.f13.f64));
	// bl 0x823dbca8
	ctx.lr = 0x82147DE8;
	sub_823DBCA8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f11,f31,f27
	ctx.f11.f64 = double(float(f31.f64 - f27.f64));
	// lfs f0,14880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	f0.f64 = double(temp.f32);
	// fmuls f10,f27,f0
	ctx.f10.f64 = double(float(f27.f64 * f0.f64));
	// fmuls f9,f12,f30
	ctx.f9.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f8,f11,f29
	ctx.f8.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fadds f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 + f31.f64));
	// fsubs f6,f31,f9
	ctx.f6.f64 = double(float(f31.f64 - ctx.f9.f64));
	// fdivs f5,f31,f7
	ctx.f5.f64 = double(float(f31.f64 / ctx.f7.f64));
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// stfs f4,12(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f3,f5,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// stfs f3,16(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fmuls f2,f5,f8
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// stfs f2,20(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f1,f10,f5
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fmuls f0,f6,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// b 0x82148110
	goto loc_82148110;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,75(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 75);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f29,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82147e60
	if (cr6.eq) goto loc_82147E60;
	// fmr f28,f29
	f28.f64 = f29.f64;
	// b 0x82147e64
	goto loc_82147E64;
loc_82147E60:
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	f28.f64 = f31.f64;
loc_82147E64:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82147E6C;
	sub_823DBBC8(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82147E78;
	sub_823DBAE8(ctx, base);
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fdivs f1,f29,f13
	ctx.f1.f64 = double(float(f29.f64 / ctx.f13.f64));
	// bl 0x823dbca8
	ctx.lr = 0x82147E8C;
	sub_823DBCA8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f11,f27,f31
	ctx.f11.f64 = double(float(f27.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,14880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14880);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f0,f27
	ctx.f10.f64 = double(float(f0.f64 - f27.f64));
	// fmuls f9,f27,f13
	ctx.f9.f64 = double(float(f27.f64 * ctx.f13.f64));
	// fmuls f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f7,f11,f29
	ctx.f7.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fadds f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 + f31.f64));
	// fsubs f5,f31,f8
	ctx.f5.f64 = double(float(f31.f64 - ctx.f8.f64));
	// fdivs f4,f31,f6
	ctx.f4.f64 = double(float(f31.f64 / ctx.f6.f64));
	// fmuls f3,f4,f7
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// stfs f3,12(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f2,f10,f4
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// stfs f2,16(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fmuls f1,f4,f7
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// stfs f1,20(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f0,f9,f4
	f0.f64 = double(float(ctx.f9.f64 * ctx.f4.f64));
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fmuls f13,f5,f4
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// b 0x82148110
	goto loc_82148110;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14984(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14984);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,14980(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x823dbf10
	ctx.lr = 0x82147F0C;
	sub_823DBF10(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fdivs f30,f31,f11
	f30.f64 = double(float(f31.f64 / ctx.f11.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82147F24;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// fadds f9,f30,f31
	ctx.f9.f64 = double(float(f30.f64 + f31.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsubs f8,f30,f31
	ctx.f8.f64 = double(float(f30.f64 - f31.f64));
	// lfs f13,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fdivs f6,f31,f9
	ctx.f6.f64 = double(float(f31.f64 / ctx.f9.f64));
	// stfs f6,12(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// fneg f4,f6
	ctx.f4.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// stfs f4,20(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f3,f8,f6
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// stfs f3,28(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// fmuls f2,f5,f30
	ctx.f2.f64 = double(float(ctx.f5.f64 * f30.f64));
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x82148110
	goto loc_82148110;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14984(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14984);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,14980(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x823dbf10
	ctx.lr = 0x82147F94;
	sub_823DBF10(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82147FA0;
	sub_823DBBC8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f10,f31,f0
	ctx.f10.f64 = double(float(f31.f64 + f0.f64));
	// lfs f13,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 - f31.f64));
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fdivs f7,f0,f10
	ctx.f7.f64 = double(float(f0.f64 / ctx.f10.f64));
	// stfs f7,12(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f7,20(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fmuls f5,f9,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f7.f64));
	// stfs f5,28(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// fneg f4,f6
	ctx.f4.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// stfs f4,16(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f4,24(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x82148110
	goto loc_82148110;
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fdivs f31,f0,f13
	f31.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82147FF8;
	sub_823DBAE8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 * f0.f64));
	// fdivs f31,f12,f11
	f31.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82148014;
	sub_823DBBC8(ctx, base);
	// lfs f10,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fdivs f9,f31,f10
	ctx.f9.f64 = double(float(f31.f64 / ctx.f10.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmuls f8,f10,f31
	ctx.f8.f64 = double(float(ctx.f10.f64 * f31.f64));
	// frsp f7,f1
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,14880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14880);
	ctx.f13.f64 = double(temp.f32);
	// fadds f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 + f0.f64));
	// fsubs f3,f0,f8
	ctx.f3.f64 = double(float(f0.f64 - ctx.f8.f64));
	// fmuls f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fsubs f2,f0,f9
	ctx.f2.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fadds f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 + f0.f64));
	// fdivs f1,f0,f6
	ctx.f1.f64 = double(float(f0.f64 / ctx.f6.f64));
	// fmuls f0,f5,f1
	f0.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f13,f4,f1
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f1.f64));
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fmuls f12,f3,f1
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f1.f64));
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f11,f4,f1
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f1.f64));
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fmuls f10,f2,f1
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f1.f64));
	// stfs f10,28(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// b 0x82148110
	goto loc_82148110;
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fdivs f31,f0,f13
	f31.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82148088;
	sub_823DBAE8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 * f0.f64));
	// fdivs f31,f12,f11
	f31.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x821480A4;
	sub_823DBBC8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f9,f1
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14976(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14976);
	f0.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,14880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14880);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fdivs f6,f31,f8
	ctx.f6.f64 = double(float(f31.f64 / ctx.f8.f64));
	// fmuls f5,f8,f31
	ctx.f5.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fadds f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 + f0.f64));
	// fadds f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 + f0.f64));
	// fsubs f2,f0,f5
	ctx.f2.f64 = double(float(f0.f64 - ctx.f5.f64));
	// fsubs f1,f0,f6
	ctx.f1.f64 = double(float(f0.f64 - ctx.f6.f64));
	// fdivs f0,f0,f4
	f0.f64 = double(float(f0.f64 / ctx.f4.f64));
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmuls f12,f7,f0
	ctx.f12.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,20(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmuls f10,f7,f0
	ctx.f10.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fmuls f9,f1,f0
	ctx.f9.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f9,28(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
loc_82148110:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x8214811C;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82147D10) {
	__imp__sub_82147D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214812C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214812C) {
	__imp__sub_8214812C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148130) {
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
	// lbz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r10,72(r31)
	PPC_STORE_U8(r31.u32 + 72, ctx.r10.u8);
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lbz r7,14(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 14);
	// stb r7,74(r31)
	PPC_STORE_U8(r31.u32 + 74, ctx.r7.u8);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// beq cr6,0x821481a8
	if (cr6.eq) goto loc_821481A8;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8214817C:
	// slw r10,r8,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r11.u8 & 0x3F));
	// and r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82148198
	if (cr6.eq) goto loc_82148198;
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r10.u8);
loc_82148198:
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214817c
	if (cr6.lt) goto loc_8214817C;
loc_821481A8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// rotlwi r4,r10,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821481C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lbz r7,73(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rotlwi r4,r7,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,20(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821481E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,73(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// rotlwi r4,r4,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,20(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82148204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// rotlwi r4,r9,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82148224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lbz r7,73(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rotlwi r5,r7,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x8214823C;
	sub_8244D150(ctx, base);
	// lbz r6,73(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rotlwi r5,r6,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82148250;
	sub_8244D150(ctx, base);
	// lbz r5,73(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82148264;
	sub_8244D150(ctx, base);
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82148278;
	sub_8244D150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82147d10
	ctx.lr = 0x82148280;
	sub_82147D10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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

PPC_WEAK_FUNC(sub_82148130) {
	__imp__sub_82148130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214829C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214829C) {
	__imp__sub_8214829C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821482A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82148650
	if (!cr6.eq) goto loc_82148650;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r5,24
	ctx.r5.s64 = 24;
	// lfs f13,8488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8488);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f12,12880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12880);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// bl 0x8244d5c0
	ctx.lr = 0x8214830C;
	sub_8244D5C0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r11,r11,9408
	r11.s64 = r11.s64 + 9408;
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f8.f64 = double(temp.f32);
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lfs f7,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsel f0,f11,f12,f0
	f0.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fsubs f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f5,f6,f13,f0
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f5,48(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f12,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// fsubs f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f3,f4,f9,f0
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// lfs f11,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f1,f8,f13
	ctx.f1.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fmuls f2,f5,f10
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// fsubs f0,f3,f12
	f0.f64 = double(float(ctx.f3.f64 - ctx.f12.f64));
	// fsel f13,f1,f8,f13
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f8.f64 : ctx.f13.f64;
	// fsel f0,f0,f12,f3
	f0.f64 = f0.f64 >= 0.0 ? ctx.f12.f64 : ctx.f3.f64;
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fsubs f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f10,f0,f2
	ctx.f10.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f12,f12,f11,f13
	ctx.f12.f64 = ctx.f12.f64 >= 0.0 ? ctx.f11.f64 : ctx.f13.f64;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fsel f9,f10,f2,f0
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// stfs f9,56(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lfs f13,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f8,f7,f0
	ctx.f8.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f7,f8,f7,f0
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fsel f0,f6,f13,f7
	f0.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// bgt cr6,0x821483c8
	if (cr6.gt) goto loc_821483C8;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
loc_821483C8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x821483d8
	if (cr6.lt) goto loc_821483D8;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_821483D8:
	// lbz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 148);
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// lbz r8,60(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 60);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bgt cr6,0x821483fc
	if (cr6.gt) goto loc_821483FC;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stb r10,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r10.u8);
loc_821483FC:
	// lbz r11,61(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 61);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bge cr6,0x82148414
	if (!cr6.lt) goto loc_82148414;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82148414:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
	// beq cr6,0x8214844c
	if (cr6.eq) goto loc_8214844C;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// beq cr6,0x8214844c
	if (cr6.eq) goto loc_8214844C;
	// cmplwi cr6,r9,5
	cr6.compare<uint32_t>(ctx.r9.u32, 5, xer);
	// beq cr6,0x8214844c
	if (cr6.eq) goto loc_8214844C;
	// cmplwi cr6,r9,7
	cr6.compare<uint32_t>(ctx.r9.u32, 7, xer);
	// beq cr6,0x8214844c
	if (cr6.eq) goto loc_8214844C;
	// cmplwi cr6,r9,9
	cr6.compare<uint32_t>(ctx.r9.u32, 9, xer);
	// beq cr6,0x8214844c
	if (cr6.eq) goto loc_8214844C;
	// cmplwi cr6,r9,10
	cr6.compare<uint32_t>(ctx.r9.u32, 10, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x82148450
	if (!cr6.eq) goto loc_82148450;
loc_8214844C:
	// li r11,1
	r11.s64 = 1;
loc_82148450:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltisw128 v58,-9
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0xFFFFFFF7)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vslw128 v57,v61,v61
	v57.u32[0] = v61.u32[0] << (v61.u8[0] & 0x1F);
	v57.u32[1] = v61.u32[1] << (v61.u8[4] & 0x1F);
	v57.u32[2] = v61.u32[2] << (v61.u8[8] & 0x1F);
	v57.u32[3] = v61.u32[3] << (v61.u8[12] & 0x1F);
	// lfs f11,14996(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14996);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fsubs f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f12,14992(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v56,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// vcfpsxws128 v46,v56,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_si128((simde__m128i*)v46.s32, simde_mm_vctsxs(simde_mm_load_ps(v56.f32)));
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f9,f11,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lvlx128 v62,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrfiz128 v44,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_round_ps(simde_mm_load_ps(v56.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vandc128 v51,v63,v57
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vlogefp128 v49,v51
	ctx.fpscr.enableFlushModeUnconditional();
	v49.f32[0] = log2f(v51.f32[0]);
	v49.f32[1] = log2f(v51.f32[1]);
	v49.f32[2] = log2f(v51.f32[2]);
	v49.f32[3] = log2f(v51.f32[3]);
	// lvlx128 v50,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcfpsxws128 v48,v50,0
	simde_mm_store_si128((simde__m128i*)v48.s32, simde_mm_vctsxs(simde_mm_load_ps(v50.f32)));
	// vrfiz128 v42,v50
	simde_mm_store_ps(v42.f32, simde_mm_round_ps(simde_mm_load_ps(v50.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vand128 v45,v48,v60
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vmulfp128 v40,v49,v50
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vslw128 v53,v61,v58
	v53.u32[0] = v61.u32[0] << (v58.u8[0] & 0x1F);
	v53.u32[1] = v61.u32[1] << (v58.u8[4] & 0x1F);
	v53.u32[2] = v61.u32[2] << (v58.u8[8] & 0x1F);
	v53.u32[3] = v61.u32[3] << (v58.u8[12] & 0x1F);
	// vslw128 v52,v61,v58
	v52.u32[0] = v61.u32[0] << (v58.u8[0] & 0x1F);
	v52.u32[1] = v61.u32[1] << (v58.u8[4] & 0x1F);
	v52.u32[2] = v61.u32[2] << (v58.u8[8] & 0x1F);
	v52.u32[3] = v61.u32[3] << (v58.u8[12] & 0x1F);
	// vcmpeqfp128 v39,v63,v59
	simde_mm_store_ps(v39.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// vcmpgtfp128 v37,v59,v50
	simde_mm_store_ps(v37.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v50.f32)));
	// vand128 v47,v63,v57
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vupkd3d128 v54,v59,4
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v54 = vTemp;
	// vcmpgtfp128 v33,v59,v63
	simde_mm_store_ps(v33.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v55,v61,v61
	v55.u32[0] = v61.u32[0] << (v61.u8[0] & 0x1F);
	v55.u32[1] = v61.u32[1] << (v61.u8[4] & 0x1F);
	v55.u32[2] = v61.u32[2] << (v61.u8[8] & 0x1F);
	v55.u32[3] = v61.u32[3] << (v61.u8[12] & 0x1F);
	// vand128 v63,v46,v60
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpeqfp128 v13,v50,v59
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v59.f32)));
	// vslw128 v38,v45,v61
	v38.u32[0] = v45.u32[0] << (v61.u8[0] & 0x1F);
	v38.u32[1] = v45.u32[1] << (v61.u8[4] & 0x1F);
	v38.u32[2] = v45.u32[2] << (v61.u8[8] & 0x1F);
	v38.u32[3] = v45.u32[3] << (v61.u8[12] & 0x1F);
	// vcmpeqfp128 v36,v62,v59
	simde_mm_store_ps(v36.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32)));
	// vsrw128 v12,v53,v60
	ctx.v12.u32[0] = v53.u32[0] >> (v60.u8[0] & 0x1F);
	ctx.v12.u32[1] = v53.u32[1] >> (v60.u8[4] & 0x1F);
	ctx.v12.u32[2] = v53.u32[2] >> (v60.u8[8] & 0x1F);
	ctx.v12.u32[3] = v53.u32[3] >> (v60.u8[12] & 0x1F);
	// vcmpeqfp128 v0,v56,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v59.f32)));
	// vsrw128 v10,v52,v60
	ctx.v10.u32[0] = v52.u32[0] >> (v60.u8[0] & 0x1F);
	ctx.v10.u32[1] = v52.u32[1] >> (v60.u8[4] & 0x1F);
	ctx.v10.u32[2] = v52.u32[2] >> (v60.u8[8] & 0x1F);
	ctx.v10.u32[3] = v52.u32[3] >> (v60.u8[12] & 0x1F);
	// vcmpgtfp128 v34,v59,v56
	simde_mm_store_ps(v34.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v56.f32)));
	// vcmpgtfp128 v32,v59,v62
	simde_mm_store_ps(v32.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vspltw128 v41,v54,3
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x0));
	// vcmpeqfp128 v60,v56,v44
	simde_mm_store_ps(v60.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v44.f32)));
	// vand128 v35,v47,v38
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v38.u8)));
	// vcmpeqfp128 v58,v50,v42
	simde_mm_store_ps(v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v42.f32)));
	// vand128 v43,v62,v55
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vslw128 v54,v63,v61
	v54.u32[0] = v63.u32[0] << (v61.u8[0] & 0x1F);
	v54.u32[1] = v63.u32[1] << (v61.u8[4] & 0x1F);
	v54.u32[2] = v63.u32[2] << (v61.u8[8] & 0x1F);
	v54.u32[3] = v63.u32[3] << (v61.u8[12] & 0x1F);
	// vexptefp128 v57,v40
	v57.f32[0] = exp2f(v40.f32[0]);
	v57.f32[1] = exp2f(v40.f32[1]);
	v57.f32[2] = exp2f(v40.f32[2]);
	v57.f32[3] = exp2f(v40.f32[3]);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vor128 v11,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vor128 v9,v59,v35
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
	// vandc128 v7,v39,v37
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// vand128 v52,v43,v54
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vor128 v53,v39,v13
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vor128 v51,v36,v0
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsel v6,v12,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vandc128 v5,v36,v34
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vor128 v4,v59,v52
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vandc128 v50,v32,v60
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v32.u8)));
	// vandc128 v49,v33,v58
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v33.u8)));
	// vsel v3,v6,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v2,v10,v4,v5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vor128 v1,v50,v51
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vor128 v31,v49,v53
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vor128 v30,v57,v35
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// vandc128 v48,v62,v55
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vlogefp128 v47,v48
	v47.f32[0] = log2f(v48.f32[0]);
	v47.f32[1] = log2f(v48.f32[1]);
	v47.f32[2] = log2f(v48.f32[2]);
	v47.f32[3] = log2f(v48.f32[3]);
	// vsel v29,v2,v8,v0
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vsel v28,v30,v3,v31
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)v30.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v28,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,52(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// vmulfp128 v46,v47,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v56.f32)));
	// vexptefp128 v45,v46
	v45.f32[0] = exp2f(v46.f32[0]);
	v45.f32[1] = exp2f(v46.f32[1]);
	v45.f32[2] = exp2f(v46.f32[2]);
	v45.f32[3] = exp2f(v46.f32[3]);
	// vor128 v27,v45,v52
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vsel v26,v27,v29,v1
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v27.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v29.u8))));
	// stvx128 v26,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,60(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// bl 0x82147d10
	ctx.lr = 0x821485D8;
	sub_82147D10(ctx, base);
	// lbz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82148634
	if (cr6.eq) goto loc_82148634;
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x821485F8;
	sub_8244D150(ctx, base);
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rotlwi r5,r10,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x8214860C;
	sub_8244D150(ctx, base);
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rotlwi r5,r9,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82148620;
	sub_8244D150(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// rotlwi r5,r8,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82148634;
	sub_8244D150(ctx, base);
loc_82148634:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82148638:
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
loc_82148650:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82148638
	goto loc_82148638;
}

PPC_WEAK_FUNC(sub_821482A0) {
	__imp__sub_821482A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214865C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214865C) {
	__imp__sub_8214865C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r11,15004
	ctx.r9.s64 = r11.s64 + 15004;
	// vspltisw128 v57,-9
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_set1_epi32(int(0xFFFFFFF7)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// vslw128 v58,v61,v61
	v58.u32[0] = v61.u32[0] << (v61.u8[0] & 0x1F);
	v58.u32[1] = v61.u32[1] << (v61.u8[4] & 0x1F);
	v58.u32[2] = v61.u32[2] << (v61.u8[8] & 0x1F);
	v58.u32[3] = v61.u32[3] << (v61.u8[12] & 0x1F);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,14988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-48(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f12,8488(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8488);
	ctx.f12.f64 = double(temp.f32);
	// stb r8,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r8.u8);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// lfs f11,12880(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12880);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stfs f11,56(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// addi r10,r11,9408
	ctx.r10.s64 = r11.s64 + 9408;
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,60(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// addi r6,r1,-48
	ctx.r6.s64 = ctx.r1.s64 + -48;
	// lfs f11,14996(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14996);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,-44
	ctx.r4.s64 = ctx.r1.s64 + -44;
	// stfs f13,-48(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// vandc128 v52,v63,v58
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lfs f12,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// vlogefp128 v48,v52
	ctx.fpscr.enableFlushModeUnconditional();
	v48.f32[0] = log2f(v52.f32[0]);
	v48.f32[1] = log2f(v52.f32[1]);
	v48.f32[2] = log2f(v52.f32[2]);
	v48.f32[3] = log2f(v52.f32[3]);
	// stfs f12,48(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// vcmpeqfp128 v51,v63,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// lfs f12,32(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f13,14992(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// vand128 v45,v63,v58
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// lvlx128 v62,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,-44(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// vupkd3d128 v56,v59,4
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v56 = vTemp;
	// lvlx128 v50,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcfpsxws128 v49,v50,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_si128((simde__m128i*)v49.s32, simde_mm_vctsxs(simde_mm_load_ps(v50.f32)));
	// vrfiz128 v46,v50
	simde_mm_store_ps(v46.f32, simde_mm_round_ps(simde_mm_load_ps(v50.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vand128 v47,v49,v60
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vmulfp128 v39,v48,v50
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32)));
	// vslw128 v55,v61,v57
	v55.u32[0] = v61.u32[0] << (v57.u8[0] & 0x1F);
	v55.u32[1] = v61.u32[1] << (v57.u8[4] & 0x1F);
	v55.u32[2] = v61.u32[2] << (v57.u8[8] & 0x1F);
	v55.u32[3] = v61.u32[3] << (v57.u8[12] & 0x1F);
	// vcmpgtfp128 v44,v59,v50
	simde_mm_store_ps(v44.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v50.f32)));
	// vspltw128 v53,v56,3
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x0));
	// vcmpeqfp128 v0,v50,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v59.f32)));
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// vslw128 v42,v47,v61
	v42.u32[0] = v47.u32[0] << (v61.u8[0] & 0x1F);
	v42.u32[1] = v47.u32[1] << (v61.u8[4] & 0x1F);
	v42.u32[2] = v47.u32[2] << (v61.u8[8] & 0x1F);
	v42.u32[3] = v47.u32[3] << (v61.u8[12] & 0x1F);
	// vcmpgtfp128 v43,v59,v63
	simde_mm_store_ps(v43.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// vsrw128 v13,v55,v60
	ctx.v13.u32[0] = v55.u32[0] >> (v60.u8[0] & 0x1F);
	ctx.v13.u32[1] = v55.u32[1] >> (v60.u8[4] & 0x1F);
	ctx.v13.u32[2] = v55.u32[2] >> (v60.u8[8] & 0x1F);
	ctx.v13.u32[3] = v55.u32[3] >> (v60.u8[12] & 0x1F);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// vor128 v12,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// vslw128 v54,v61,v61
	v54.u32[0] = v61.u32[0] << (v61.u8[0] & 0x1F);
	v54.u32[1] = v61.u32[1] << (v61.u8[4] & 0x1F);
	v54.u32[2] = v61.u32[2] << (v61.u8[8] & 0x1F);
	v54.u32[3] = v61.u32[3] << (v61.u8[12] & 0x1F);
	// addi r6,r1,-44
	ctx.r6.s64 = ctx.r1.s64 + -44;
	// vand128 v40,v45,v42
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v42.u8)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v41,v62,v59
	simde_mm_store_ps(v41.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v38,v50,v46
	simde_mm_store_ps(v38.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v46.f32)));
	// vor128 v11,v59,v40
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vexptefp128 v36,v39
	v36.f32[0] = exp2f(v39.f32[0]);
	v36.f32[1] = exp2f(v39.f32[1]);
	v36.f32[2] = exp2f(v39.f32[2]);
	v36.f32[3] = exp2f(v39.f32[3]);
	// vandc128 v10,v51,v44
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vor128 v37,v51,v0
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsel v9,v13,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v7,v9,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vandc128 v35,v43,v38
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vor128 v8,v36,v40
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vor128 v6,v35,v37
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// vandc128 v33,v62,v54
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgtfp128 v34,v59,v62
	simde_mm_store_ps(v34.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vand128 v32,v62,v54
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// vslw128 v63,v61,v57
	v63.u32[0] = v61.u32[0] << (v57.u8[0] & 0x1F);
	v63.u32[1] = v61.u32[1] << (v57.u8[4] & 0x1F);
	v63.u32[2] = v61.u32[2] << (v57.u8[8] & 0x1F);
	v63.u32[3] = v61.u32[3] << (v57.u8[12] & 0x1F);
	// vsel v5,v8,v7,v6
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vlogefp128 v62,v33
	v62.f32[0] = log2f(v33.f32[0]);
	v62.f32[1] = log2f(v33.f32[1]);
	v62.f32[2] = log2f(v33.f32[2]);
	v62.f32[3] = log2f(v33.f32[3]);
	// vor128 v4,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vsrw128 v3,v63,v60
	ctx.v3.u32[0] = v63.u32[0] >> (v60.u8[0] & 0x1F);
	ctx.v3.u32[1] = v63.u32[1] >> (v60.u8[4] & 0x1F);
	ctx.v3.u32[2] = v63.u32[2] >> (v60.u8[8] & 0x1F);
	ctx.v3.u32[3] = v63.u32[3] >> (v60.u8[12] & 0x1F);
	// stvx128 v5,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,52(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f12,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lfs f12,56(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f9,-44(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcfpsxws128 v57,v58,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_si128((simde__m128i*)v57.s32, simde_mm_vctsxs(simde_mm_load_ps(v58.f32)));
	// vrfiz128 v56,v58
	simde_mm_store_ps(v56.f32, simde_mm_round_ps(simde_mm_load_ps(v58.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vand128 v55,v57,v60
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vmulfp128 v54,v62,v58
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// vcmpgtfp128 v53,v59,v58
	simde_mm_store_ps(v53.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vcmpeqfp128 v0,v58,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// vslw128 v52,v55,v61
	v52.u32[0] = v55.u32[0] << (v61.u8[0] & 0x1F);
	v52.u32[1] = v55.u32[1] << (v61.u8[4] & 0x1F);
	v52.u32[2] = v55.u32[2] << (v61.u8[8] & 0x1F);
	v52.u32[3] = v55.u32[3] << (v61.u8[12] & 0x1F);
	// vand128 v51,v32,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vcmpeqfp128 v50,v58,v56
	simde_mm_store_ps(v50.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v56.f32)));
	// vor128 v2,v59,v51
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vexptefp128 v49,v54
	v49.f32[0] = exp2f(v54.f32[0]);
	v49.f32[1] = exp2f(v54.f32[1]);
	v49.f32[2] = exp2f(v54.f32[2]);
	v49.f32[3] = exp2f(v54.f32[3]);
	// vandc128 v1,v41,v53
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// vor128 v48,v41,v0
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsel v31,v3,v2,v1
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8))));
	// vsel v30,v31,v4,v0
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)v31.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vandc128 v47,v34,v50
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v34.u8)));
	// vor128 v29,v49,v51
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vor128 v28,v47,v48
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vsel v27,v29,v30,v28
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)v30.u8))));
	// stvx128 v27,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,60(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lbz r10,62(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 62);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stb r10,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r10.u8);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82148894
	if (cr6.eq) goto loc_82148894;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82148894:
	// stfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r9,75(r3)
	PPC_STORE_U8(ctx.r3.u32 + 75, ctx.r9.u8);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148660) {
	__imp__sub_82148660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821488B0) {
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
	ctx.lr = 0x821488B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r4,76
	ctx.r4.s64 = 76;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821488E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821488f8
	if (cr6.eq) goto loc_821488F8;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82148660
	ctx.lr = 0x821488F0;
	sub_82148660(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x821488fc
	goto loc_821488FC;
loc_821488F8:
	// li r31,0
	r31.s64 = 0;
loc_821488FC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82148918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_821488B0) {
	__imp__sub_821488B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r1,20
	r11.s64 = ctx.r1.s64 + 20;
	// stfs f1,20(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 20, temp.u32);
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v1,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148928) {
	__imp__sub_82148928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214893C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214893C) {
	__imp__sub_8214893C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// li r11,255
	r11.s64 = 255;
	// lfs f13,8488(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8488);
	ctx.f13.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,23900
	ctx.r9.s64 = 23900;
	// stfs f13,164(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// sth r10,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, ctx.r10.u16);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// sth r10,114(r3)
	PPC_STORE_U16(ctx.r3.u32 + 114, ctx.r10.u16);
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// sth r10,146(r3)
	PPC_STORE_U16(ctx.r3.u32 + 146, ctx.r10.u16);
	// stfs f0,108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stb r11,158(r3)
	PPC_STORE_U8(ctx.r3.u32 + 158, r11.u8);
	// stfs f0,76(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stb r11,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, r11.u8);
	// stfs f13,168(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// stb r11,94(r3)
	PPC_STORE_U8(ctx.r3.u32 + 94, r11.u8);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// sth r9,152(r3)
	PPC_STORE_U16(ctx.r3.u32 + 152, ctx.r9.u16);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// sth r9,120(r3)
	PPC_STORE_U16(ctx.r3.u32 + 120, ctx.r9.u16);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// sth r9,88(r3)
	PPC_STORE_U16(ctx.r3.u32 + 88, ctx.r9.u16);
	// stb r11,157(r3)
	PPC_STORE_U8(ctx.r3.u32 + 157, r11.u8);
	// stb r11,125(r3)
	PPC_STORE_U8(ctx.r3.u32 + 125, r11.u8);
	// stb r11,93(r3)
	PPC_STORE_U8(ctx.r3.u32 + 93, r11.u8);
	// stb r11,198(r3)
	PPC_STORE_U8(ctx.r3.u32 + 198, r11.u8);
	// stw r5,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r5.u32);
	// stw r10,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r10.u32);
	// sth r10,196(r3)
	PPC_STORE_U16(ctx.r3.u32 + 196, ctx.r10.u16);
	// lbz r4,199(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lwz r11,27060(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27060);
	// rlwimi r4,r11,5,0,26
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 5) & 0xFFFFFFE0) | (ctx.r4.u64 & 0xFFFFFFFF0000001F);
	// stb r4,199(r3)
	PPC_STORE_U8(ctx.r3.u32 + 199, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148940) {
	__imp__sub_82148940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821489E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821489E4) {
	__imp__sub_821489E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821489E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// addi r6,r8,26644
	ctx.r6.s64 = ctx.r8.s64 + 26644;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,26640(r7)
	PPC_STORE_U8(ctx.r7.u32 + 26640, r11.u8);
	// stw r10,26644(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26644, ctx.r10.u32);
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821489E8) {
	__imp__sub_821489E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148A10) {
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
	ctx.lr = 0x82148A18;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// addi r30,r10,26644
	r30.s64 = ctx.r10.s64 + 26644;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lbz r11,199(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 199);
	// addi r7,r30,4
	ctx.r7.s64 = r30.s64 + 4;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// ori r11,r9,43691
	r11.u64 = ctx.r9.u64 | 43691;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwzx r28,r8,r30
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// lwzx r29,r8,r7
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r5,r28,1
	ctx.r5.s64 = r28.s64 + 1;
	// addi r24,r28,2
	r24.s64 = r28.s64 + 2;
	// mulhwu r4,r5,r11
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(r11.u32)) >> 32;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// rlwinm r11,r4,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// mulhwu r10,r3,r6
	ctx.r10.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// subf r27,r9,r5
	r27.s64 = ctx.r5.s64 - ctx.r9.s64;
	// subf r23,r8,r3
	r23.s64 = ctx.r3.s64 - ctx.r8.s64;
	// cmplw cr6,r27,r29
	cr6.compare<uint32_t>(r27.u32, r29.u32, xer);
	// bne cr6,0x82148ae8
	if (!cr6.eq) goto loc_82148AE8;
	// lis r22,-32125
	r22.s64 = -2105344000;
	// lbz r11,26640(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 26640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82148ae8
	if (!cr6.eq) goto loc_82148AE8;
	// bl 0x82144fc8
	ctx.lr = 0x82148A9C;
	sub_82144FC8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82144fc8
	ctx.lr = 0x82148AA4;
	sub_82144FC8(ctx, base);
	// addi r26,r26,1000
	r26.s64 = r26.s64 + 1000;
loc_82148AA8:
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bge cr6,0x82148ad8
	if (!cr6.lt) goto loc_82148AD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c91b8
	ctx.lr = 0x82148AB8;
	sub_821C91B8(ctx, base);
	// lbz r10,199(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 199);
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// rlwinm r9,r10,30,2,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r29,r9,r11
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x82144fc8
	ctx.lr = 0x82148ACC;
	sub_82144FC8(ctx, base);
	// cmplw cr6,r27,r29
	cr6.compare<uint32_t>(r27.u32, r29.u32, xer);
	// beq cr6,0x82148aa8
	if (cr6.eq) goto loc_82148AA8;
	// b 0x82148ae8
	goto loc_82148AE8;
loc_82148AD8:
	// cmplw cr6,r27,r29
	cr6.compare<uint32_t>(r27.u32, r29.u32, xer);
	// bne cr6,0x82148ae8
	if (!cr6.eq) goto loc_82148AE8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,26640(r22)
	PPC_STORE_U8(r22.u32 + 26640, r11.u8);
loc_82148AE8:
	// rlwinm r11,r28,5,0,26
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r9,95(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 95);
	// rlwinm r10,r9,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// rlwimi r8,r9,0,29,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x7) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFF8);
	// stb r8,95(r11)
	PPC_STORE_U8(r11.u32 + 95, ctx.r8.u8);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82148b20
	if (!cr6.eq) goto loc_82148B20;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stw r25,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r25.u32);
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82148bbc
	goto loc_82148BBC;
loc_82148B20:
	// addi r9,r23,1
	ctx.r9.s64 = r23.s64 + 1;
	// addi r8,r28,1
	ctx.r8.s64 = r28.s64 + 1;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subf. r10,r10,r25
	ctx.r10.s64 = r25.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvx128 v62,r7,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r6,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r25.u32);
	// lbz r5,95(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 95);
	// rlwinm r9,r5,0,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r4,r9,8
	ctx.r4.s64 = ctx.r9.s64 + 8;
	// vsubfp128 v63,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// rlwimi r4,r5,0,29,31
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x7) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFF8);
	// stb r4,95(r11)
	PPC_STORE_U8(r11.u32 + 95, ctx.r4.u8);
	// beq 0x82148bb4
	if (cr0.eq) goto loc_82148BB4;
	// clrldi r11,r10,32
	r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,15356(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15356);
	f0.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r8,-31664
	ctx.r7.s64 = ctx.r8.s64 + -31664;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vrefp128 v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v63,v9
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82148bbc
	goto loc_82148BBC;
loc_82148BB4:
	// vspltisw128 v57,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82148BBC:
	// addi r11,r27,2
	r11.s64 = r27.s64 + 2;
	// rlwinm r10,r24,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82148BE0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82148be0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82148BE0;
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// addi r10,r27,1
	ctx.r10.s64 = r27.s64 + 1;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v56,r9,r31
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r8,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82148A10) {
	__imp__sub_82148A10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148C14) {
	__imp__sub_82148C14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r4,r11,160
	ctx.r4.s64 = r11.s64 + 160;
	// b 0x82162560
	sub_82162560(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82148C18) {
	__imp__sub_82148C18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C30) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148C30) {
	__imp__sub_82148C30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148C34) {
	__imp__sub_82148C34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r3
	ctx.r5.u64 = r11.u64 + ctx.r3.u64;
	// sth r4,82(r5)
	PPC_STORE_U16(ctx.r5.u32 + 82, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148C38) {
	__imp__sub_82148C38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148C5C) {
	__imp__sub_82148C5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r3
	ctx.r5.u64 = r11.u64 + ctx.r3.u64;
	// sth r4,80(r5)
	PPC_STORE_U16(ctx.r5.u32 + 80, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148C60) {
	__imp__sub_82148C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148C84) {
	__imp__sub_82148C84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148C88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v63,r6,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148C88) {
	__imp__sub_82148C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// rlwinm r6,r7,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// stfsx f1,r6,r3
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148CB0) {
	__imp__sub_82148CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148CD4) {
	__imp__sub_82148CD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// stfs f1,68(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + 68, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148CD8) {
	__imp__sub_82148CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148CFC) {
	__imp__sub_82148CFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// stfs f1,72(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + 72, temp.u32);
	// lbz r5,199(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// rlwinm r4,r5,30,2,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r11,r4,r9
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stfs f2,76(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 76, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148D00) {
	__imp__sub_82148D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148D3C) {
	__imp__sub_82148D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,95
	ctx.r10.s64 = r11.s64 + 95;
	// lbz r5,95(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 95);
	// rlwimi r5,r9,2,29,29
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0x4) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFFB);
	// stb r5,95(r11)
	PPC_STORE_U8(r11.u32 + 95, ctx.r5.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148D40) {
	__imp__sub_82148D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148D74) {
	__imp__sub_82148D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,95
	ctx.r10.s64 = r11.s64 + 95;
	// lbz r5,95(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 95);
	// rlwimi r5,r9,1,30,30
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0x2) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFFD);
	// stb r5,95(r11)
	PPC_STORE_U8(r11.u32 + 95, ctx.r5.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148D78) {
	__imp__sub_82148D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148DAC) {
	__imp__sub_82148DAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,95
	ctx.r10.s64 = r11.s64 + 95;
	// lbz r6,95(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 95);
	// rlwimi r6,r4,0,31,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x1) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r6,95(r11)
	PPC_STORE_U8(r11.u32 + 95, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148DB0) {
	__imp__sub_82148DB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148DE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// stfs f1,84(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + 84, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148DE0) {
	__imp__sub_82148DE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148E04) {
	__imp__sub_82148E04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// stb r4,92(r6)
	PPC_STORE_U8(ctx.r6.u32 + 92, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148E08) {
	__imp__sub_82148E08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148E2C) {
	__imp__sub_82148E2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// lhz r5,80(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 80);
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148E30) {
	__imp__sub_82148E30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148E58) {
	__imp__sub_82148E58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148E7C) {
	__imp__sub_82148E7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r8,r11,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r9,r10,26644
	ctx.r9.s64 = ctx.r10.s64 + 26644;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// lfs f1,84(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148E80) {
	__imp__sub_82148E80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148EA4) {
	__imp__sub_82148EA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148EA8) {
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
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82148edc
	if (cr6.eq) goto loc_82148EDC;
	// bl 0x82162558
	ctx.lr = 0x82148ED4;
	sub_82162558(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
loc_82148EDC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82148eec
	if (cr6.eq) goto loc_82148EEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82162550
	ctx.lr = 0x82148EEC;
	sub_82162550(ctx, base);
loc_82148EEC:
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
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

PPC_WEAK_FUNC(sub_82148EA8) {
	__imp__sub_82148EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F08) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,160
	ctx.r3.s64 = ctx.r3.s64 + 160;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148F08) {
	__imp__sub_82148F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F10) {
	PPC_FUNC_PROLOGUE();
	// stb r4,198(r3)
	PPC_STORE_U8(ctx.r3.u32 + 198, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148F10) {
	__imp__sub_82148F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r3
	ctx.r5.u64 = r11.u64 + ctx.r3.u64;
	// sth r4,88(r5)
	PPC_STORE_U16(ctx.r5.u32 + 88, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148F18) {
	__imp__sub_82148F18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148F3C) {
	__imp__sub_82148F3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,199(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 199);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r8,r10,26644
	ctx.r8.s64 = ctx.r10.s64 + 26644;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r3
	ctx.r5.u64 = r11.u64 + ctx.r3.u64;
	// sth r4,90(r5)
	PPC_STORE_U16(ctx.r5.u32 + 90, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148F40) {
	__imp__sub_82148F40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148F64) {
	__imp__sub_82148F64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,15696
	ctx.r9.s64 = r11.s64 + 15696;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148F68) {
	__imp__sub_82148F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148F80) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,15696
	ctx.r10.s64 = r11.s64 + 15696;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82160450
	ctx.lr = 0x82148FA4;
	sub_82160450(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82148fc0
	if (cr6.eq) goto loc_82148FC0;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82148fc0
	if (cr6.eq) goto loc_82148FC0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821606d0
	ctx.lr = 0x82148FC0;
	sub_821606D0(ctx, base);
loc_82148FC0:
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

PPC_WEAK_FUNC(sub_82148F80) {
	__imp__sub_82148F80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148FD4) {
	__imp__sub_82148FD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addis r9,r11,1
	ctx.r9.s64 = r11.s64 + 65536;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r9.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148FD8) {
	__imp__sub_82148FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82148FEC) {
	__imp__sub_82148FEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82148FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82148FF0) {
	__imp__sub_82148FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149000) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,15696
	ctx.r10.s64 = r11.s64 + 15696;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82160450
	ctx.lr = 0x8214902C;
	sub_82160450(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82149048
	if (cr6.eq) goto loc_82149048;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149048
	if (cr6.eq) goto loc_82149048;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821606d0
	ctx.lr = 0x82149048;
	sub_821606D0(ctx, base);
loc_82149048:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149060
	if (cr6.eq) goto loc_82149060;
	// bl 0x82130588
	ctx.lr = 0x8214905C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82149060:
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

PPC_WEAK_FUNC(sub_82149000) {
	__imp__sub_82149000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82149080:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x821490ac
	if (cr6.eq) goto loc_821490AC;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821490a4
	if (cr6.eq) goto loc_821490A4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r9,24
	cr6.compare<uint32_t>(ctx.r9.u32, 24, xer);
	// blt cr6,0x82149080
	if (cr6.lt) goto loc_82149080;
loc_821490A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821490AC:
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149078) {
	__imp__sub_82149078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821490BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821490BC) {
	__imp__sub_821490BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821490C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r20{};
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
	ctx.lr = 0x821490C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821490ec
	if (cr6.eq) goto loc_821490EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b630
	ctx.lr = 0x821490EC;
	sub_8213B630(ctx, base);
loc_821490EC:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,11364(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	f0.f64 = double(temp.f32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lbz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x82149160
	if (cr6.eq) goto loc_82149160;
	// lbz r11,13(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82149160
	if (!cr6.eq) goto loc_82149160;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r11,r9,6280
	r11.s64 = ctx.r9.s64 + 6280;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82149160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82149160:
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821493ec
	if (!cr6.eq) goto loc_821493EC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// extsh r29,r10
	r29.s64 = ctx.r10.s16;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// beq cr6,0x821491ac
	if (cr6.eq) goto loc_821491AC;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11444(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x821491b0
	goto loc_821491B0;
loc_821491AC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821491B0:
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lbz r5,199(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 199);
	// addi r6,r7,26644
	ctx.r6.s64 = ctx.r7.s64 + 26644;
	// rlwinm r4,r5,30,2,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFF8;
	// addi r3,r6,4
	ctx.r3.s64 = ctx.r6.s64 + 4;
	// lwzx r7,r4,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// rlwinm r7,r7,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lbz r4,95(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 95);
	// rlwinm r3,r4,0,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821491f4
	if (cr6.eq) goto loc_821491F4;
	// lbz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r9.u8);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
loc_821491F4:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82149218
	if (cr6.eq) goto loc_82149218;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r7,11488
	r11.s64 = ctx.r7.s64 * 11488;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x8214921c
	goto loc_8214921C;
loc_82149218:
	// li r11,0
	r11.s64 = 0;
loc_8214921C:
	// lbz r8,199(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// addi r7,r6,4
	ctx.r7.s64 = ctx.r6.s64 + 4;
	// rlwinm r6,r8,30,2,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// rlwinm r8,r5,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + r11.u64;
	// lbz r3,95(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 95);
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149254
	if (cr6.eq) goto loc_82149254;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c198
	ctx.lr = 0x8214924C;
	sub_8213C198(ctx, base);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
loc_82149254:
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// bgt cr6,0x821493ec
	if (cr6.gt) goto loc_821493EC;
	// lis r12,-32235
	r12.s64 = -2112552960;
	// addi r12,r12,-28044
	r12.s64 = r12.s64 + -28044;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,-28028(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -28028);
	// lwz r16,-27896(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -27896);
	// lwz r16,-27800(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -27800);
	// lwz r16,-27732(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -27732);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r8,r11,19856
	ctx.r8.s64 = r11.s64 + 19856;
	// lwz r11,684(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 684);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,684(r8)
	PPC_STORE_U32(ctx.r8.u32 + 684, r11.u32);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821492c0
	if (cr6.eq) goto loc_821492C0;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11444(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821492c4
	goto loc_821492C4;
loc_821492C0:
	// li r11,0
	r11.s64 = 0;
loc_821492C4:
	// lbz r11,199(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821492e4
	if (cr6.eq) goto loc_821492E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e3e0
	ctx.lr = 0x821492DC;
	sub_8213E3E0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x821493ec
	if (!cr6.eq) goto loc_821493EC;
loc_821492E4:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821493ec
	if (cr6.eq) goto loc_821493EC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x82149300;
	sub_8213D890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// lwz r11,688(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 688);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,688(r10)
	PPC_STORE_U32(ctx.r10.u32 + 688, r11.u32);
	// bl 0x8213e3e0
	ctx.lr = 0x82149324;
	sub_8213E3E0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x82149348
	if (cr6.lt) goto loc_82149348;
	// beq cr6,0x821492e4
	if (cr6.eq) goto loc_821492E4;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x821493ec
	if (!cr6.lt) goto loc_821493EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b630
	ctx.lr = 0x82149340;
	sub_8213B630(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82149348:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x821493ec
	if (!cr6.gt) goto loc_821493EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b630
	ctx.lr = 0x82149360;
	sub_8213B630(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// lwz r11,696(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 696);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,696(r10)
	PPC_STORE_U32(ctx.r10.u32 + 696, r11.u32);
	// lbz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214939c
	if (cr6.eq) goto loc_8214939C;
	// bl 0x8213b5c0
	ctx.lr = 0x82149394;
	sub_8213B5C0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8214939C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213e040
	ctx.lr = 0x821493A4;
	sub_8213E040(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// lwz r11,692(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 692);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,692(r10)
	PPC_STORE_U32(ctx.r10.u32 + 692, r11.u32);
	// bl 0x8213f710
	ctx.lr = 0x821493C8;
	sub_8213F710(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821493ec
	if (!cr6.eq) goto loc_821493EC;
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
	ctx.lr = 0x821493EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821493EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_821490C0) {
	__imp__sub_821490C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821493F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821493F4) {
	__imp__sub_821493F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821493F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,14992(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lfs f13,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx v1,0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx v2,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x8214943C;
	sub_821476B0(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,16040(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 16040);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// stvx128 v1,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fsel f1,f13,f12,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821493F8) {
	__imp__sub_821493F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82149474) {
	__imp__sub_82149474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149478) {
	__imp__sub_82149478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149480) {
	__imp__sub_82149480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149488) {
	PPC_FUNC_PROLOGUE();
	// sth r4,68(r3)
	PPC_STORE_U16(ctx.r3.u32 + 68, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149488) {
	__imp__sub_82149488(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149490) {
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
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82149514
	if (!cr6.eq) goto loc_82149514;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82149500
	if (cr6.eq) goto loc_82149500;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821494d8
	if (cr6.eq) goto loc_821494D8;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mulli r10,r11,136
	ctx.r10.s64 = r11.s64 * 136;
	// lwz r11,26656(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26656);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821494dc
	goto loc_821494DC;
loc_821494D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821494DC:
	// bl 0x82149490
	ctx.lr = 0x821494E0;
	sub_82149490(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149500
	if (cr6.eq) goto loc_82149500;
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
loc_82149500:
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
loc_82149514:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
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
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149490) {
	__imp__sub_82149490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149530) {
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
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// rlwinm r11,r11,30,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x821495b4
	if (!cr6.eq) goto loc_821495B4;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821495a0
	if (cr6.eq) goto loc_821495A0;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82149578
	if (cr6.eq) goto loc_82149578;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mulli r10,r11,136
	ctx.r10.s64 = r11.s64 * 136;
	// lwz r11,26656(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26656);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8214957c
	goto loc_8214957C;
loc_82149578:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214957C:
	// bl 0x82149530
	ctx.lr = 0x82149580;
	sub_82149530(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821495a0
	if (cr6.eq) goto loc_821495A0;
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
loc_821495A0:
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
loc_821495B4:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
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
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149530) {
	__imp__sub_82149530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821495D0) {
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
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// rlwinm r11,r11,28,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82149654
	if (!cr6.eq) goto loc_82149654;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82149640
	if (cr6.eq) goto loc_82149640;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82149618
	if (cr6.eq) goto loc_82149618;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mulli r10,r11,136
	ctx.r10.s64 = r11.s64 * 136;
	// lwz r11,26656(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26656);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8214961c
	goto loc_8214961C;
loc_82149618:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214961C:
	// bl 0x821495d0
	ctx.lr = 0x82149620;
	sub_821495D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149640
	if (cr6.eq) goto loc_82149640;
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
loc_82149640:
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
loc_82149654:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
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
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821495D0) {
	__imp__sub_821495D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149670) {
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
	PPCRegister f0{};
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
	// bl 0x823d91f8
	ctx.lr = 0x82149678;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f31,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
	// lhz r9,13(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 13);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x821493f8
	ctx.lr = 0x821496C0;
	sub_821493F8(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// lhz r5,11(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 11);
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f1,f9,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 * f31.f64));
	// bl 0x821493f8
	ctx.lr = 0x821496E8;
	sub_821493F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fsubs f8,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64 - f29.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lhz r6,21(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 21);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lhz r4,23(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 23);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fmadds f5,f8,f30,f29
	ctx.f5.f64 = double(float(ctx.f8.f64 * f30.f64 + f29.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v62.f32[0] = log2f(v63.f32[0]);
	v62.f32[1] = log2f(v63.f32[1]);
	v62.f32[2] = log2f(v63.f32[2]);
	v62.f32[3] = log2f(v63.f32[3]);
	// fcfid f4,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(ctx.f6.s64);
	// addi r10,r7,16320
	ctx.r10.s64 = ctx.r7.s64 + 16320;
	// fcfid f3,f7
	ctx.f3.f64 = double(ctx.f7.s64);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,-276(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -276);
	f0.f64 = double(temp.f32);
	// fsubs f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 - f0.f64));
	// lfs f0,11368(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11368);
	f0.f64 = double(temp.f32);
	// lfs f13,-280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -280);
	ctx.f13.f64 = double(temp.f32);
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// frsp f12,f3
	ctx.f12.f64 = double(float(ctx.f3.f64));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f1,f31
	ctx.f9.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fmuls f8,f12,f31
	ctx.f8.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fsel f7,f2,f10,f13
	ctx.f7.f64 = ctx.f2.f64 >= 0.0 ? ctx.f10.f64 : ctx.f13.f64;
	// stfs f7,4(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fsubs f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f5,f6,f30,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64 + ctx.f9.f64));
	// stfs f5,8(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// beq cr6,0x821497f0
	if (cr6.eq) goto loc_821497F0;
	// addi r30,r31,84
	r30.s64 = r31.s64 + 84;
	// li r29,24
	r29.s64 = 24;
	// lis r31,-32125
	r31.s64 = -2105344000;
loc_821497AC:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821497e4
	if (cr6.eq) goto loc_821497E4;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x821497d4
	if (cr6.eq) goto loc_821497D4;
	// lwz r11,26656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 26656);
	// mulli r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 * 136;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821497d8
	goto loc_821497D8;
loc_821497D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821497D8:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82149670
	ctx.lr = 0x821497E4;
	sub_82149670(ctx, base);
loc_821497E4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bne 0x821497ac
	if (!cr0.eq) goto loc_821497AC;
loc_821497F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82149670) {
	__imp__sub_82149670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82149804) {
	__imp__sub_82149804(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149808) {
	PPC_FUNC_PROLOGUE();
	// sth r4,70(r3)
	PPC_STORE_U16(ctx.r3.u32 + 70, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149808) {
	__imp__sub_82149808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149810) {
	PPC_FUNC_PROLOGUE();
	// sth r4,72(r3)
	PPC_STORE_U16(ctx.r3.u32 + 72, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82149810) {
	__imp__sub_82149810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149818) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82149820;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r9,26652(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r7,r5,24
	ctx.r7.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82149884
	if (cr6.eq) goto loc_82149884;
	// lbz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r8,r10,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82149884
	if (!cr6.eq) goto loc_82149884;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r10,r9
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
loc_82149884:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r5,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r9.u32, temp.u32);
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// lhz r9,68(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 68);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// beq cr6,0x821498f0
	if (cr6.eq) goto loc_821498F0;
	// lbz r9,132(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821498f0
	if (!cr6.eq) goto loc_821498F0;
	// lhz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lhz r11,28(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
loc_821498F0:
	// lhz r9,82(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,28(r5)
	PPC_STORE_U16(ctx.r5.u32 + 28, r11.u16);
	// lhz r10,34(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 34);
	// lhz r11,70(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 70);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82149920
	if (cr6.lt) goto loc_82149920;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82149920:
	// lwz r9,26652(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82149964
	if (cr6.eq) goto loc_82149964;
	// lbz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r8,r10,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82149964
	if (!cr6.eq) goto loc_82149964;
	// lhz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lhz r10,30(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 30);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82149964
	if (cr6.lt) goto loc_82149964;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82149964:
	// lhz r10,82(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,30(r4)
	PPC_STORE_U16(ctx.r4.u32 + 30, ctx.r8.u16);
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lhz r11,72(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 72);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82149998
	if (cr6.gt) goto loc_82149998;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82149998:
	// lwz r9,26652(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821499dc
	if (cr6.eq) goto loc_821499DC;
	// lbz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r8,r10,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821499dc
	if (!cr6.eq) goto loc_821499DC;
	// lhz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lhz r10,32(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x821499dc
	if (cr6.gt) goto loc_821499DC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_821499DC:
	// lhz r10,82(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,32(r4)
	PPC_STORE_U16(ctx.r4.u32 + 32, ctx.r8.u16);
	// lfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149a44
	if (cr6.eq) goto loc_82149A44;
	// lbz r11,132(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r9,r11,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149a44
	if (!cr6.eq) goto loc_82149A44;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149A44:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// stfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149aa8
	if (cr6.eq) goto loc_82149AA8;
	// lbz r11,132(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149aa8
	if (!cr6.eq) goto loc_82149AA8;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149AA8:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// stfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8, temp.u32);
	// lfs f0,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149b0c
	if (cr6.eq) goto loc_82149B0C;
	// lbz r11,132(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149b0c
	if (!cr6.eq) goto loc_82149B0C;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149B0C:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// stfs f0,12(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// lfs f0,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149b70
	if (cr6.eq) goto loc_82149B70;
	// lbz r11,132(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 132);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149b70
	if (!cr6.eq) goto loc_82149B70;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149B70:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// stfs f0,16(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// lfs f0,60(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149bd4
	if (cr6.eq) goto loc_82149BD4;
	// lbz r11,133(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 133);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149bd4
	if (!cr6.eq) goto loc_82149BD4;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,20(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149BD4:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,26652(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26652);
	// stfs f0,20(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 20, temp.u32);
	// lfs f0,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x82149c38
	if (cr6.eq) goto loc_82149C38;
	// lbz r11,133(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 133);
	// rlwinm r9,r11,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82149c38
	if (!cr6.eq) goto loc_82149C38;
	// lhz r11,80(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82149C38:
	// lhz r11,82(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// addi r31,r3,84
	r31.s64 = ctx.r3.s64 + 84;
	// li r29,24
	r29.s64 = 24;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,24(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 24, temp.u32);
loc_82149C60:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82149c94
	if (cr6.eq) goto loc_82149C94;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82149c88
	if (cr6.eq) goto loc_82149C88;
	// lwz r11,26656(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 26656);
	// mulli r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 * 136;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82149c8c
	goto loc_82149C8C;
loc_82149C88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82149C8C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82149818
	ctx.lr = 0x82149C94;
	sub_82149818(ctx, base);
loc_82149C94:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// bne 0x82149c60
	if (!cr0.eq) goto loc_82149C60;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82149818) {
	__imp__sub_82149818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149CA8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lfs f1,92(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82149670
	ctx.lr = 0x82149CD8;
	sub_82149670(ctx, base);
	// lhz r7,27(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 27);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r31,9
	ctx.r8.s64 = r31.s64 + 9;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,16(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// lhz r5,29(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 29);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,20(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// lhz r3,31(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 31);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f2,24(r30)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// lhz r10,33(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 33);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f1,80(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,28(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
	// lhz r8,25(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 25);
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
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,12(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// lhz r6,15(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 15);
	// sth r6,32(r30)
	PPC_STORE_U16(r30.u32 + 32, ctx.r6.u16);
	// lhz r5,17(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 17);
	// sth r5,34(r30)
	PPC_STORE_U16(r30.u32 + 34, ctx.r5.u16);
	// lhz r4,19(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 19);
	// sth r4,36(r30)
	PPC_STORE_U16(r30.u32 + 36, ctx.r4.u16);
	// lbz r3,9(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// stb r3,132(r30)
	PPC_STORE_U8(r30.u32 + 132, ctx.r3.u8);
	// lbz r11,10(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// stb r11,133(r30)
	PPC_STORE_U8(r30.u32 + 133, r11.u8);
	// lwz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5);
	// stw r10,76(r30)
	PPC_STORE_U32(r30.u32 + 76, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_82149CA8) {
	__imp__sub_82149CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82149DCC) {
	__imp__sub_82149DCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82149DD0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82149DD8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// li r30,0
	r30.s64 = 0;
	// li r8,23900
	ctx.r8.s64 = 23900;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// sth r30,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r30.u16);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// sth r8,70(r31)
	PPC_STORE_U16(r31.u32 + 70, ctx.r8.u16);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// sth r30,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r30.u16);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// li r27,136
	r27.s64 = 136;
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// li r24,-1
	r24.s64 = -1;
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// subf r5,r11,r31
	ctx.r5.s64 = r31.s64 - r11.s64;
	// divw r3,r5,r27
	ctx.r3.s32 = ctx.r5.s32 / r27.s32;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// sth r10,82(r31)
	PPC_STORE_U16(r31.u32 + 82, ctx.r10.u16);
	// lwz r10,26652(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26652);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f13,r5,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, temp.u32);
	// lhz r3,82(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// sth r30,28(r10)
	PPC_STORE_U16(ctx.r10.u32 + 28, r30.u16);
	// lwz r10,26652(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26652);
	// lhz r9,82(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lhz r11,82(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,8(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// lhz r3,82(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lhz r5,82(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lhz r10,82(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,26652(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26652);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stfs f0,20(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 20, temp.u32);
	// lhz r3,82(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stfs f13,24(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 24, temp.u32);
	// lhz r5,82(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// sth r8,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r8.u16);
	// lhz r10,82(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// lwz r10,26652(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26652);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// sth r30,32(r8)
	PPC_STORE_U16(ctx.r8.u32 + 32, r30.u16);
	// beq cr6,0x82149f8c
	if (cr6.eq) goto loc_82149F8C;
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// subf r11,r11,r6
	r11.s64 = ctx.r6.s64 - r11.s64;
	// divw r10,r11,r27
	ctx.r10.s32 = r11.s32 / r27.s32;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// b 0x82149f90
	goto loc_82149F90;
loc_82149F8C:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82149F90:
	// sth r11,80(r31)
	PPC_STORE_U16(r31.u32 + 80, r11.u16);
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82149F98:
	// addi r10,r11,42
	ctx.r10.s64 = r11.s64 + 42;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r11,24
	cr6.compare<uint32_t>(r11.u32, 24, xer);
	// sthx r24,r8,r31
	PPC_STORE_U16(ctx.r8.u32 + r31.u32, r24.u16);
	// blt cr6,0x82149f98
	if (cr6.lt) goto loc_82149F98;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82149fc8
	if (!cr6.eq) goto loc_82149FC8;
loc_82149FBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82149FC8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82149fbc
	if (cr6.eq) goto loc_82149FBC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8214d6b8
	ctx.lr = 0x82149FD8;
	sub_8214D6B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82149fbc
	if (cr6.eq) goto loc_82149FBC;
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82149ca8
	ctx.lr = 0x82149FF4;
	sub_82149CA8(ctx, base);
	// lbz r11,35(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 35);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214a090
	if (cr6.eq) goto loc_8214A090;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
loc_8214A008:
	// addi r11,r30,9
	r11.s64 = r30.s64 + 9;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r26
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x8214d830
	ctx.lr = 0x8214A01C;
	sub_8214D830(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82149fbc
	if (cr6.eq) goto loc_82149FBC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 1);
	// bl 0x8214d8f8
	ctx.lr = 0x8214A034;
	sub_8214D8F8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8214A03C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8214a178
	ctx.lr = 0x8214A04C;
	sub_8214A178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214a068
	if (cr6.eq) goto loc_8214A068;
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// divw r10,r11,r27
	ctx.r10.s32 = r11.s32 / r27.s32;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// b 0x8214a06c
	goto loc_8214A06C;
loc_8214A068:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_8214A06C:
	// addi r11,r30,42
	r11.s64 = r30.s64 + 42;
	// addi r9,r30,1
	ctx.r9.s64 = r30.s64 + 1;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// sthx r10,r8,r31
	PPC_STORE_U16(ctx.r8.u32 + r31.u32, ctx.r10.u16);
	// lbz r7,35(r26)
	ctx.r7.u64 = PPC_LOAD_U8(r26.u32 + 35);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8214a008
	if (cr6.lt) goto loc_8214A008;
loc_8214A090:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82149DD0) {
	__imp__sub_82149DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A09C) {
	__imp__sub_8214A09C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A0A0) {
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
	// bl 0x8214dee8
	ctx.lr = 0x8214A0B8;
	sub_8214DEE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// sth r9,96(r31)
	PPC_STORE_U16(r31.u32 + 96, ctx.r9.u16);
	// sth r11,98(r31)
	PPC_STORE_U16(r31.u32 + 98, r11.u16);
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

PPC_WEAK_FUNC(sub_8214A0A0) {
	__imp__sub_8214A0A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A0F8) {
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
	ctx.lr = 0x8214A100;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lwz r4,76(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214a12c
	if (cr6.eq) goto loc_8214A12C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214A124;
	sub_82144A78(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r11.u32);
loc_8214A12C:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r4,26656(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 26656);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214a14c
	if (cr6.eq) goto loc_8214A14C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214A144;
	sub_82144A78(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,26656(r30)
	PPC_STORE_U32(r30.u32 + 26656, r11.u32);
loc_8214A14C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,26652(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 26652);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214a164
	if (cr6.eq) goto loc_8214A164;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214A164;
	sub_82144A78(ctx, base);
loc_8214A164:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214dd80
	ctx.lr = 0x8214A16C;
	sub_8214DD80(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8214A0F8) {
	__imp__sub_8214A0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A174) {
	__imp__sub_8214A174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A178) {
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
	ctx.lr = 0x8214A180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214a1ac
	if (cr6.lt) goto loc_8214A1AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8214A1AC:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mulli r30,r29,136
	r30.s64 = r29.s64 * 136;
	// lwz r11,26656(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x82149dd0
	ctx.lr = 0x8214A1D0;
	sub_82149DD0(ctx, base);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r10,26656(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// add r8,r30,r10
	ctx.r8.u64 = r30.u64 + ctx.r10.u64;
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r8.u32);
	// lwz r11,26656(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8214A178) {
	__imp__sub_8214A178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A200) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bne cr6,0x8214a21c
	if (!cr6.eq) goto loc_8214A21C;
	// blr 
	return;
loc_8214A21C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 76);
loc_8214A228:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x8214a250
	if (!cr6.gt) goto loc_8214A250;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8214a258
	goto loc_8214A258;
loc_8214A250:
	// bge cr6,0x8214a264
	if (!cr6.lt) goto loc_8214A264;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8214A258:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8214a228
	if (!cr6.gt) goto loc_8214A228;
	// blr 
	return;
loc_8214A264:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r11,r7
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A200) {
	__imp__sub_8214A200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_8214A284:
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r7,r10,r4
	ctx.r7.u32 = ctx.r10.u32 / ctx.r4.u32;
	// cmplwi cr6,r7,9
	cr6.compare<uint32_t>(ctx.r7.u32, 9, xer);
	// beq cr6,0x8214a2a4
	if (cr6.eq) goto loc_8214A2A4;
	// cmplwi cr6,r7,10
	cr6.compare<uint32_t>(ctx.r7.u32, 10, xer);
	// bne cr6,0x8214a2ac
	if (!cr6.eq) goto loc_8214A2AC;
loc_8214A2A4:
	// li r7,11
	ctx.r7.s64 = 11;
	// b 0x8214a2b8
	goto loc_8214A2B8;
loc_8214A2AC:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bge cr6,0x8214a2b8
	if (!cr6.lt) goto loc_8214A2B8;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8214A2B8:
	// subf. r11,r7,r9
	r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// beq 0x8214a348
	if (cr0.eq) goto loc_8214A348;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
loc_8214A2D0:
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x8214a32c
	if (!cr6.gt) goto loc_8214A32C;
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r31,r11,r8
	r31.u64 = r11.u64 + ctx.r8.u64;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r8,r10,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,4(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwzx r31,r11,r9
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r8.u32);
loc_8214A32C:
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// subf r8,r7,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// blt cr6,0x8214a2d0
	if (cr6.lt) goto loc_8214A2D0;
loc_8214A348:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bne cr6,0x8214a284
	if (!cr6.eq) goto loc_8214A284;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214a284
	if (!cr6.eq) goto loc_8214A284;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A270) {
	__imp__sub_8214A270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A368) {
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
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// lhz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 96);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r3,26656(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26656);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mulhw r11,r7,r8
	r11.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// clrlwi r30,r5,16
	r30.u64 = ctx.r5.u32 & 0xFFFF;
	// beq cr6,0x8214a3cc
	if (cr6.eq) goto loc_8214A3CC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8214A3C8;
	sub_82130000(ctx, base);
	// sth r30,96(r31)
	PPC_STORE_U16(r31.u32 + 96, r30.u16);
loc_8214A3CC:
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

PPC_WEAK_FUNC(sub_8214A368) {
	__imp__sub_8214A368(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A3E4) {
	__imp__sub_8214A3E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A3E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,96(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 96);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// mulhw r11,r9,r8
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// sth r6,98(r3)
	PPC_STORE_U16(ctx.r3.u32 + 98, ctx.r6.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A3E8) {
	__imp__sub_8214A3E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A418) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,26656(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26656);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lhz r4,98(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 98);
	// b 0x82149818
	sub_82149818(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214A418) {
	__imp__sub_8214A418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A434) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A434) {
	__imp__sub_8214A434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A438) {
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
	ctx.lr = 0x8214A440;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// bne cr6,0x8214a470
	if (!cr6.eq) goto loc_8214A470;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8214A470:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r29,r10,19856
	r29.s64 = ctx.r10.s64 + 19856;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214A488;
	sub_82144A60(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// mulli r4,r9,136
	ctx.r4.s64 = ctx.r9.s64 * 136;
	// bl 0x82144a60
	ctx.lr = 0x8214A4A0;
	sub_82144A60(ctx, base);
	// lis r27,-32125
	r27.s64 = -2105344000;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r11,26656(r27)
	PPC_STORE_U32(r27.u32 + 26656, r11.u32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82144a60
	ctx.lr = 0x8214A4C8;
	sub_82144A60(ctx, base);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stw r3,26652(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26652, ctx.r3.u32);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// ble cr6,0x8214a50c
	if (!cr6.gt) goto loc_8214A50C;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8214A4E4:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stwx r30,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, r30.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lwz r7,72(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x8214a4e4
	if (cr6.lt) goto loc_8214A4E4;
loc_8214A50C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,11416
	ctx.r3.s64 = r11.s64 + 11416;
	// bl 0x821c9790
	ctx.lr = 0x8214A51C;
	sub_821C9790(ctx, base);
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// bge cr6,0x8214a574
	if (!cr6.lt) goto loc_8214A574;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// mulli r29,r30,136
	r29.s64 = r30.s64 * 136;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,26656(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// bl 0x82149dd0
	ctx.lr = 0x8214A554;
	sub_82149DD0(ctx, base);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r10,26656(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// add r8,r29,r10
	ctx.r8.u64 = r29.u64 + ctx.r10.u64;
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
loc_8214A574:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a270
	ctx.lr = 0x8214A57C;
	sub_8214A270(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8214A438) {
	__imp__sub_8214A438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A588) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,15
	ctx.r6.s64 = 15;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,1268(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1268);
	// bl 0x8214e328
	ctx.lr = 0x8214A5B4;
	sub_8214E328(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8214a5d8
	if (!cr6.eq) goto loc_8214A5D8;
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
loc_8214A5D8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a438
	ctx.lr = 0x8214A5E0;
	sub_8214A438(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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

PPC_WEAK_FUNC(sub_8214A588) {
	__imp__sub_8214A588(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A604) {
	__imp__sub_8214A604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A608) {
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
	// bl 0x8213b968
	ctx.lr = 0x8214A620;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// addi r10,r11,16996
	ctx.r10.s64 = r11.s64 + 16996;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821627f8
	ctx.lr = 0x8214A634;
	sub_821627F8(ctx, base);
	// lbz r5,227(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lbz r6,226(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// li r12,211
	r12.s64 = 211;
	// li r11,255
	r11.s64 = 255;
	// and r3,r5,r12
	ctx.r3.u64 = ctx.r5.u64 & r12.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,220(r31)
	PPC_STORE_U8(r31.u32 + 220, r11.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r7,-1000
	ctx.r7.s64 = -1000;
	// stb r3,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r3.u8);
	// clrlwi r4,r6,30
	ctx.r4.u64 = ctx.r6.u32 & 0x3;
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stw r9,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r10,218(r31)
	PPC_STORE_U16(r31.u32 + 218, ctx.r10.u16);
	// stw r9,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r9.u32);
	// stb r11,222(r31)
	PPC_STORE_U8(r31.u32 + 222, r11.u8);
	// stb r11,223(r31)
	PPC_STORE_U8(r31.u32 + 223, r11.u8);
	// stb r11,224(r31)
	PPC_STORE_U8(r31.u32 + 224, r11.u8);
	// sth r7,216(r31)
	PPC_STORE_U16(r31.u32 + 216, ctx.r7.u16);
	// stw r10,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r10.u32);
	// stb r4,226(r31)
	PPC_STORE_U8(r31.u32 + 226, ctx.r4.u8);
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

PPC_WEAK_FUNC(sub_8214A608) {
	__imp__sub_8214A608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A6A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lbz r11,220(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 220);
	// mulli r10,r10,359
	ctx.r10.s64 = ctx.r10.s64 * 359;
	// addi r8,r9,7216
	ctx.r8.s64 = ctx.r9.s64 + 7216;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,232(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,7784(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 7784);
	// srawi r3,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 3;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A6A8) {
	__imp__sub_8214A6A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// li r11,15
	r11.s64 = 15;
	// addi r10,r10,1344
	ctx.r10.s64 = ctx.r10.s64 + 1344;
	// stb r11,6960(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6960, r11.u8);
	// stw r10,26660(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26660, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A6D8) {
	__imp__sub_8214A6D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A6FC) {
	__imp__sub_8214A6FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A700) {
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
	// lbz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// cmplwi cr6,r5,255
	cr6.compare<uint32_t>(ctx.r5.u32, 255, xer);
	// beq cr6,0x8214a738
	if (cr6.eq) goto loc_8214A738;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213ece0
	ctx.lr = 0x8214A730;
	sub_8213ECE0(ctx, base);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r10,220(r31)
	PPC_STORE_U8(r31.u32 + 220, ctx.r10.u8);
loc_8214A738:
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

PPC_WEAK_FUNC(sub_8214A700) {
	__imp__sub_8214A700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A74C) {
	__imp__sub_8214A74C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A750) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,220(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 220);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8214a794
	if (cr6.eq) goto loc_8214A794;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,16384
	ctx.r8.s64 = 1073741824;
	// mulli r11,r11,359
	r11.s64 = r11.s64 * 359;
	// addi r7,r9,7216
	ctx.r7.s64 = ctx.r9.s64 + 7216;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r6,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,232(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// li r11,1
	r11.s64 = 1;
	// lwz r4,7792(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7792);
	// rlwinm r3,r4,0,0,1
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r3,r8
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, xer);
	// beq cr6,0x8214a798
	if (cr6.eq) goto loc_8214A798;
loc_8214A794:
	// li r11,0
	r11.s64 = 0;
loc_8214A798:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A750) {
	__imp__sub_8214A750(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A7A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,220(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 220);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r8,r10,7216
	ctx.r8.s64 = ctx.r10.s64 + 7216;
	// mulli r10,r9,11488
	ctx.r10.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbzx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214a7fc
	if (cr6.eq) goto loc_8214A7FC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// blr 
	return;
loc_8214A7FC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A7A0) {
	__imp__sub_8214A7A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A810) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214a824
	if (cr6.eq) goto loc_8214A824;
	// lbz r11,227(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 227);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
loc_8214A824:
	// lwz r3,212(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214A810) {
	__imp__sub_8214A810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214A82C) {
	__imp__sub_8214A82C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214A830) {
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
	ctx.lr = 0x8214A838;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,6960
	ctx.r4.s64 = r11.s64 + 6960;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8214A850;
	sub_8213E680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214a868
	if (!cr6.eq) goto loc_8214A868;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214A868:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c8f8
	ctx.lr = 0x8214A870;
	sub_8213C8F8(ctx, base);
	// lbz r11,227(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwimi r11,r3,6,0,25
	r11.u64 = (__builtin_rotateleft32(ctx.r3.u32, 6) & 0xFFFFFFC0) | (r11.u64 & 0xFFFFFFFF0000003F);
	// stb r11,227(r31)
	PPC_STORE_U8(r31.u32 + 227, r11.u8);
	// lfs f0,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,196(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r3,26660(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26660);
	// bl 0x8215e4e8
	ctx.lr = 0x8214A894;
	sub_8215E4E8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,32
	cr6.compare<uint32_t>(ctx.r8.u32, 32, xer);
	// stb r8,225(r31)
	PPC_STORE_U8(r31.u32 + 225, ctx.r8.u8);
	// ble cr6,0x8214a8ac
	if (!cr6.gt) goto loc_8214A8AC;
	// li r11,0
	r11.s64 = 0;
	// stb r11,225(r31)
	PPC_STORE_U8(r31.u32 + 225, r11.u8);
loc_8214A8AC:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// bl 0x8213d570
	ctx.lr = 0x8214A8BC;
	sub_8213D570(ctx, base);
	// stb r3,222(r31)
	PPC_STORE_U8(r31.u32 + 222, ctx.r3.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// lfs f2,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x82162830
	ctx.lr = 0x8214A8D4;
	sub_82162830(ctx, base);
	// lbz r9,21(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 21);
	// lbz r8,226(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// rlwimi r8,r9,30,30,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 30) & 0x3) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFFC);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// stb r7,226(r31)
	PPC_STORE_U8(r31.u32 + 226, ctx.r7.u8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8214a900
	if (!cr6.eq) goto loc_8214A900;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// ori r10,r11,3
	ctx.r10.u64 = r11.u64 | 3;
	// stb r10,226(r31)
	PPC_STORE_U8(r31.u32 + 226, ctx.r10.u8);
loc_8214A900:
	// lhz r11,62(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// lis r29,-32125
	r29.s64 = -2105344000;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8214a98c
	if (!cr6.eq) goto loc_8214A98C;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8214a958
	if (!cr6.eq) goto loc_8214A958;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r11,26688(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26688);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8214a950
	if (!cr6.eq) goto loc_8214A950;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,26688(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26688, r11.u32);
	// addi r3,r9,11416
	ctx.r3.s64 = ctx.r9.s64 + 11416;
	// bl 0x821c9790
	ctx.lr = 0x8214A948;
	sub_821C9790(ctx, base);
	// stw r3,26684(r30)
	PPC_STORE_U32(r30.u32 + 26684, ctx.r3.u32);
	// b 0x8214a954
	goto loc_8214A954;
loc_8214A950:
	// lwz r3,26684(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 26684);
loc_8214A954:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8214A958:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x8214a200
	ctx.lr = 0x8214A964;
	sub_8214A200(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214a984
	if (cr6.eq) goto loc_8214A984;
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// li r10,136
	ctx.r10.s64 = 136;
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// b 0x8214a988
	goto loc_8214A988;
loc_8214A984:
	// li r11,-1
	r11.s64 = -1;
loc_8214A988:
	// sth r11,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r11.u16);
loc_8214A98C:
	// lhz r11,62(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x8214a9ac
	if (cr6.eq) goto loc_8214A9AC;
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// mulli r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 * 136;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8214a9b0
	goto loc_8214A9B0;
loc_8214A9AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214A9B0:
	// bl 0x821495d0
	ctx.lr = 0x8214A9B4;
	sub_821495D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbz r10,227(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwimi r10,r9,1,30,30
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0x2) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFD);
	// stb r10,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r10.u8);
	// bl 0x8213c9c0
	ctx.lr = 0x8214A9D0;
	sub_8213C9C0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8214aa14
	if (!cr6.eq) goto loc_8214AA14;
	// lhz r11,62(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x8214a9fc
	if (cr6.eq) goto loc_8214A9FC;
	// lwz r11,26656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26656);
	// mulli r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 * 136;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8214aa00
	goto loc_8214AA00;
loc_8214A9FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214AA00:
	// bl 0x82149490
	ctx.lr = 0x8214AA04;
	sub_82149490(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8214aa18
	if (cr6.eq) goto loc_8214AA18;
loc_8214AA14:
	// li r11,1
	r11.s64 = 1;
loc_8214AA18:
	// lbz r10,227(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r10,r11,0,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// stb r10,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r10.u8);
	// lbz r8,20(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 20);
	// stb r8,221(r31)
	PPC_STORE_U8(r31.u32 + 221, ctx.r8.u8);
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// lbz r7,227(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// rlwinm r6,r6,0,28,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// stb r6,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r6.u8);
	// lbz r4,21(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 21);
	// rlwimi r5,r4,2,28,28
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x8) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r5,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r5.u8);
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// lbz r10,21(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 21);
	// rlwimi r9,r10,2,29,29
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0x4) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFB);
	// stb r9,227(r31)
	PPC_STORE_U8(r31.u32 + 227, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8214A830) {
	__imp__sub_8214A830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214AA70) {
	PPC_FUNC_PROLOGUE();
	// stw r4,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r4.u32);
	// sth r5,218(r3)
	PPC_STORE_U16(ctx.r3.u32 + 218, ctx.r5.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214AA70) {
	__imp__sub_8214AA70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214AA7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214AA7C) {
	__imp__sub_8214AA7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214AA80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r11,r3,46
	r11.s64 = ctx.r3.s64 + 46;
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// subf r9,r3,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r3.s64;
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// lhz r6,16(r4)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r4.u32 + 16);
	// sth r6,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, ctx.r6.u16);
	// lhz r5,18(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 18);
	// sth r5,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r5.u16);
	// lhz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 20);
	// sth r8,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r8.u16);
	// lhz r7,22(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 22);
	// sth r7,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, ctx.r7.u16);
	// lbz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24);
	// stb r6,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r6.u8);
	// lhz r5,26(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 26);
	// sth r5,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r5.u16);
	// lhz r8,28(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// sth r8,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r8.u16);
	// lhz r7,30(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 30);
	// sth r7,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r7.u16);
	// lhz r6,32(r4)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// sth r6,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, ctx.r6.u16);
	// lhz r5,34(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 34);
	// sth r5,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, ctx.r5.u16);
	// lhz r8,36(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 36);
	// sth r8,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r8.u16);
	// lhz r7,38(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 38);
	// sth r7,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r7.u16);
	// lhz r6,40(r4)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r4.u32 + 40);
	// sth r6,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, ctx.r6.u16);
	// lhz r5,42(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 42);
	// sth r5,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, ctx.r5.u16);
	// lhz r8,44(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 44);
	// sth r8,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, ctx.r8.u16);
loc_8214AB24:
	// lhzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x8214ab24
	if (!cr0.eq) goto loc_8214AB24;
	// lbz r11,70(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 70);
	// stb r11,70(r3)
	PPC_STORE_U8(ctx.r3.u32 + 70, r11.u8);
	// lbz r10,71(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 71);
	// stb r10,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, ctx.r10.u8);
	// lbz r9,72(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 72);
	// stb r9,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, ctx.r9.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214AA80) {
	__imp__sub_8214AA80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214AB54) {
	__imp__sub_8214AB54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214AB58) {
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
	ctx.lr = 0x8214AB60;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9b4
	ctx.lr = 0x8214AB68;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x8213d440
	ctx.lr = 0x8214AB78;
	sub_8213D440(ctx, base);
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8214ac20
	if (!cr6.eq) goto loc_8214AC20;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,7216
	r11.s64 = r11.s64 + 7216;
	// lbz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 192);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214bb44
	if (cr6.eq) goto loc_8214BB44;
	// rlwinm r9,r23,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r4,r23,r9
	ctx.r4.u64 = r23.u64 + ctx.r9.u64;
loc_8214ABA8:
	// lbz r9,-1(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + -1);
	// lbzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x8214abfc
	if (!cr6.eq) goto loc_8214ABFC;
	// lbz r7,0(r6)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x8214abe8
	if (cr6.eq) goto loc_8214ABE8;
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lwz r9,232(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x8214abec
	goto loc_8214ABEC;
loc_8214ABE8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8214ABEC:
	// lbz r9,227(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 227);
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,227(r10)
	PPC_STORE_U8(ctx.r10.u32 + 227, ctx.r8.u8);
	// lbz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 192);
loc_8214ABFC:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// addi r6,r6,3
	ctx.r6.s64 = ctx.r6.s64 + 3;
	// cmplw cr6,r5,r9
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, xer);
	// blt cr6,0x8214aba8
	if (cr6.lt) goto loc_8214ABA8;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba00
	ctx.lr = 0x8214AC1C;
	// b 0x823d9228
	return;
loc_8214AC20:
	// lbz r22,220(r21)
	r22.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// cmplwi cr6,r22,255
	cr6.compare<uint32_t>(r22.u32, 255, xer);
	// beq cr6,0x8214bb44
	if (cr6.eq) goto loc_8214BB44;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,6
	ctx.r9.s64 = 6;
	// lfs f28,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f28.f64 = double(temp.f32);
	// fmr f25,f28
	f25.f64 = f28.f64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8214AC48:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8214ac48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214AC48;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// li r8,3
	ctx.r8.s64 = 3;
loc_8214AC5C:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r11,4
	r11.s64 = 4;
loc_8214AC64:
	// stfs f28,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x8214ac64
	if (!cr0.eq) goto loc_8214AC64;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8214ac5c
	if (!cr0.eq) goto loc_8214AC5C;
	// lhz r11,216(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 216);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f30,f28
	f30.f64 = f28.f64;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// fmr f29,f28
	f29.f64 = f28.f64;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f27,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f27.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f27
	ctx.f1.f64 = double(float(ctx.f12.f64 * f27.f64));
	// bl 0x821493f8
	ctx.lr = 0x8214ACB0;
	sub_821493F8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f20,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f20.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f21,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f21.f64 = double(temp.f32);
	// addi r20,r11,7216
	r20.s64 = r11.s64 + 7216;
	// lfs f22,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	f22.f64 = double(temp.f32);
	// lfs f23,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f23.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// lfs f24,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f24.f64 = double(temp.f32);
	// lfs f26,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f26.f64 = double(temp.f32);
	// lfs f19,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f19.f64 = double(temp.f32);
	// lbz r26,192(r20)
	r26.u64 = PPC_LOAD_U8(r20.u32 + 192);
	// fdivs f31,f19,f1
	f31.f64 = double(float(f19.f64 / ctx.f1.f64));
	// lwz r30,232(r20)
	r30.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8214b1c0
	if (cr6.eq) goto loc_8214B1C0;
	// rlwinm r11,r23,1,0,30
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r25,196(r20)
	r25.u64 = PPC_LOAD_U32(r20.u32 + 196);
	// addi r27,r1,208
	r27.s64 = ctx.r1.s64 + 208;
	// add r11,r23,r11
	r11.u64 = r23.u64 + r11.u64;
	// addi r29,r20,2
	r29.s64 = r20.s64 + 2;
	// lbzx r24,r11,r20
	r24.u64 = PPC_LOAD_U8(r11.u32 + r20.u32);
loc_8214AD08:
	// lbz r11,-2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + -2);
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// bne cr6,0x8214b1a8
	if (!cr6.eq) goto loc_8214B1A8;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214ad28
	if (cr6.eq) goto loc_8214AD28;
	// cmplw cr6,r28,r23
	cr6.compare<uint32_t>(r28.u32, r23.u32, xer);
	// bne cr6,0x8214b1a8
	if (!cr6.eq) goto loc_8214B1A8;
loc_8214AD28:
	// lbz r11,-1(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + -1);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214ad50
	if (cr6.eq) goto loc_8214AD50;
	// lbz r9,64(r21)
	ctx.r9.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// mullw r10,r11,r25
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r25.s32);
	// mulli r11,r9,11488
	r11.s64 = ctx.r9.s64 * 11488;
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8214ad54
	goto loc_8214AD54;
loc_8214AD50:
	// li r31,0
	r31.s64 = 0;
loc_8214AD54:
	// lhz r11,216(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 216);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f27
	ctx.f1.f64 = double(float(ctx.f12.f64 * f27.f64));
	// bl 0x821493f8
	ctx.lr = 0x8214AD74;
	sub_821493F8(ctx, base);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// lbz r8,64(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// mulli r10,r8,11488
	ctx.r10.s64 = ctx.r8.s64 * 11488;
	// lbzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214adb0
	if (cr6.eq) goto loc_8214ADB0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r7,r11,96
	ctx.r7.s64 = r11.s64 + 96;
	// b 0x8214adb4
	goto loc_8214ADB4;
loc_8214ADB0:
	// li r7,0
	ctx.r7.s64 = 0;
loc_8214ADB4:
	// lhz r11,26(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214adc8
	if (!cr6.eq) goto loc_8214ADC8;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f28.f64;
	// b 0x8214adf0
	goto loc_8214ADF0;
loc_8214ADC8:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// lfs f0,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
loc_8214ADF0:
	// lhz r11,30(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214ae04
	if (!cr6.eq) goto loc_8214AE04;
	// fmr f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f28.f64;
	// b 0x8214ae2c
	goto loc_8214AE2C;
loc_8214AE04:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
loc_8214AE2C:
	// fsubs f12,f25,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f25.f64 - f0.f64));
	// lhz r11,34(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsel f25,f12,f25,f0
	f25.f64 = ctx.f12.f64 >= 0.0 ? f25.f64 : f0.f64;
	// bne cr6,0x8214ae48
	if (!cr6.eq) goto loc_8214AE48;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214ae70
	goto loc_8214AE70;
loc_8214AE48:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214AE70:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lhz r11,36(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f26,f9
	ctx.f8.f64 = double(float(f26.f64 - ctx.f9.f64));
	// fsel f26,f8,f26,f9
	f26.f64 = ctx.f8.f64 >= 0.0 ? f26.f64 : ctx.f9.f64;
	// bne cr6,0x8214ae9c
	if (!cr6.eq) goto loc_8214AE9C;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214aec4
	goto loc_8214AEC4;
loc_8214AE9C:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214AEC4:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lhz r11,38(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f24,f9
	ctx.f8.f64 = double(float(f24.f64 - ctx.f9.f64));
	// fsel f24,f8,f24,f9
	f24.f64 = ctx.f8.f64 >= 0.0 ? f24.f64 : ctx.f9.f64;
	// bne cr6,0x8214aef0
	if (!cr6.eq) goto loc_8214AEF0;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214af18
	goto loc_8214AF18;
loc_8214AEF0:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214AF18:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lhz r11,40(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f23,f9
	ctx.f8.f64 = double(float(f23.f64 - ctx.f9.f64));
	// fsel f23,f8,f23,f9
	f23.f64 = ctx.f8.f64 >= 0.0 ? f23.f64 : ctx.f9.f64;
	// bne cr6,0x8214af44
	if (!cr6.eq) goto loc_8214AF44;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214af6c
	goto loc_8214AF6C;
loc_8214AF44:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214AF6C:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lhz r11,42(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 42);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f22,f9
	ctx.f8.f64 = double(float(f22.f64 - ctx.f9.f64));
	// fsel f22,f8,f22,f9
	f22.f64 = ctx.f8.f64 >= 0.0 ? f22.f64 : ctx.f9.f64;
	// bne cr6,0x8214af98
	if (!cr6.eq) goto loc_8214AF98;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214afc0
	goto loc_8214AFC0;
loc_8214AF98:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214AFC0:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lhz r11,44(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f21,f9
	ctx.f8.f64 = double(float(f21.f64 - ctx.f9.f64));
	// fsel f21,f8,f21,f9
	f21.f64 = ctx.f8.f64 >= 0.0 ? f21.f64 : ctx.f9.f64;
	// bne cr6,0x8214afec
	if (!cr6.eq) goto loc_8214AFEC;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214b014
	goto loc_8214B014;
loc_8214AFEC:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r8,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8214B014:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// addi r11,r1,164
	r11.s64 = ctx.r1.s64 + 164;
	// addi r9,r7,48
	ctx.r9.s64 = ctx.r7.s64 + 48;
	// li r8,4
	ctx.r8.s64 = 4;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fsubs f8,f20,f9
	ctx.f8.f64 = double(float(f20.f64 - ctx.f9.f64));
	// fsel f20,f8,f20,f9
	f20.f64 = ctx.f8.f64 >= 0.0 ? f20.f64 : ctx.f9.f64;
loc_8214B038:
	// lhz r10,-2(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214b04c
	if (!cr6.eq) goto loc_8214B04C;
	// fmr f12,f28
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f28.f64;
	// b 0x8214b074
	goto loc_8214B074;
loc_8214B04C:
	// rlwinm r6,r10,3,0,13
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r5,r10,22
	ctx.r5.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// addi r3,r10,112
	ctx.r3.s64 = ctx.r10.s64 + 112;
	// rlwinm r10,r4,13,0,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r6,r3,23,0,8
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 23) & 0xFF800000;
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
loc_8214B074:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fsel f6,f7,f11,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// stfs f6,-4(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// bne cr6,0x8214b0a8
	if (!cr6.eq) goto loc_8214B0A8;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214b0d0
	goto loc_8214B0D0;
loc_8214B0A8:
	// rlwinm r6,r10,3,0,13
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r5,r10,22
	ctx.r5.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// addi r3,r10,112
	ctx.r3.s64 = ctx.r10.s64 + 112;
	// rlwinm r10,r4,13,0,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r6,r3,23,0,8
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 23) & 0xFF800000;
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
loc_8214B0D0:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lhz r10,2(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fsel f6,f7,f11,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// stfs f6,0(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// bne cr6,0x8214b104
	if (!cr6.eq) goto loc_8214B104;
	// fmr f12,f28
	ctx.f12.f64 = f28.f64;
	// b 0x8214b12c
	goto loc_8214B12C;
loc_8214B104:
	// rlwinm r6,r10,3,0,13
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r5,r10,22
	ctx.r5.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// addi r3,r10,112
	ctx.r3.s64 = ctx.r10.s64 + 112;
	// rlwinm r10,r4,13,0,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r6,r3,23,0,8
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 23) & 0xFF800000;
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
loc_8214B12C:
	// fmuls f12,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,6
	ctx.r9.s64 = ctx.r9.s64 + 6;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fsel f6,f7,f11,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// stfs f6,4(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x8214b038
	if (!cr0.eq) goto loc_8214B038;
	// lhz r10,18(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 18);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lhz r11,16(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 16);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r9.u64);
	// lfd f11,152(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmuls f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * f31.f64));
	// stfs f12,0(r27)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmadds f30,f7,f12,f30
	f30.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + f30.f64));
	// fmadds f29,f6,f12,f29
	f29.f64 = double(float(ctx.f6.f64 * ctx.f12.f64 + f29.f64));
	// b 0x8214b1ac
	goto loc_8214B1AC;
loc_8214B1A8:
	// stfs f28,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
loc_8214B1AC:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,3
	r29.s64 = r29.s64 + 3;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r28,r26
	cr6.compare<uint32_t>(r28.u32, r26.u32, xer);
	// blt cr6,0x8214ad08
	if (cr6.lt) goto loc_8214AD08;
loc_8214B1C0:
	// fmr f12,f28
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f28.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// blt cr6,0x8214b210
	if (cr6.lt) goto loc_8214B210;
	// addi r10,r26,-4
	ctx.r10.s64 = r26.s64 + -4;
	// addi r11,r1,212
	r11.s64 = ctx.r1.s64 + 212;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8214B1E4:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f13,f0,f12
	ctx.f13.f64 = double(float(f0.f64 + ctx.f12.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fadds f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fadds f12,f8,f10
	ctx.f12.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// bne 0x8214b1e4
	if (!cr0.eq) goto loc_8214B1E4;
loc_8214B210:
	// cmplw cr6,r9,r26
	cr6.compare<uint32_t>(ctx.r9.u32, r26.u32, xer);
	// bge cr6,0x8214b23c
	if (!cr6.lt) goto loc_8214B23C;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// subf r11,r9,r26
	r11.s64 = r26.s64 - ctx.r9.s64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_8214B228:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fadds f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 + ctx.f12.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8214b228
	if (!cr0.eq) goto loc_8214B228;
loc_8214B23C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r7,r11,16696
	ctx.r7.s64 = r11.s64 + 16696;
	// mulli r11,r10,11488
	r11.s64 = ctx.r10.s64 * 11488;
	// lfs f0,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f13,-16(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f25,f0
	ctx.f11.f64 = double(float(f25.f64 - f0.f64));
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// add r8,r22,r11
	ctx.r8.u64 = r22.u64 + r11.u64;
	// lbzx r6,r8,r30
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + r30.u32);
	// fsel f0,f11,f25,f0
	f0.f64 = ctx.f11.f64 >= 0.0 ? f25.f64 : f0.f64;
	// fsel f9,f10,f12,f13
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// fdivs f10,f19,f0
	ctx.f10.f64 = double(float(f19.f64 / f0.f64));
	// fdivs f8,f19,f9
	ctx.f8.f64 = double(float(f19.f64 / ctx.f9.f64));
	// fmuls f13,f8,f30
	ctx.f13.f64 = double(float(ctx.f8.f64 * f30.f64));
	// fmuls f12,f8,f29
	ctx.f12.f64 = double(float(ctx.f8.f64 * f29.f64));
	// beq cr6,0x8214b2a8
	if (cr6.eq) goto loc_8214B2A8;
	// rlwinm r10,r22,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r22,r10
	ctx.r10.u64 = r22.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b2ac
	goto loc_8214B2AC;
loc_8214B2A8:
	// li r11,0
	r11.s64 = 0;
loc_8214B2AC:
	// fsel f0,f0,f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,11776(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11776);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,11772(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11772);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b2d8
	if (!cr6.lt) goto loc_8214B2D8;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b2e0
	if (cr6.gt) goto loc_8214B2E0;
loc_8214B2D8:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b2ec
	if (cr6.eq) goto loc_8214B2EC;
loc_8214B2E0:
	// stfs f28,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// b 0x8214b32c
	goto loc_8214B32C;
loc_8214B2EC:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b2fc
	if (!cr6.gt) goto loc_8214B2FC;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b308
	goto loc_8214B308;
loc_8214B2FC:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b308
	if (!cr6.lt) goto loc_8214B308;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B308:
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// rlwinm r5,r10,16,16,16
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r4,r6,10,0,21
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0xFFFFFC00;
	// or r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 | ctx.r8.u64;
	// or r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 | ctx.r5.u64;
loc_8214B32C:
	// sth r10,26(r11)
	PPC_STORE_U16(r11.u32 + 26, ctx.r10.u16);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r6,r8,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214b370
	if (cr6.eq) goto loc_8214B370;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b374
	goto loc_8214B374;
loc_8214B370:
	// li r11,0
	r11.s64 = 0;
loc_8214B374:
	// lfs f0,-4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	f0.f64 = double(temp.f32);
	// fsubs f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f5,f6,f0,f13
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lhz r10,102(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// sth r10,16(r11)
	PPC_STORE_U16(r11.u32 + 16, ctx.r10.u16);
	// lbz r8,64(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r8,11488
	ctx.r10.s64 = ctx.r8.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214b3d0
	if (cr6.eq) goto loc_8214B3D0;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b3d4
	goto loc_8214B3D4;
loc_8214B3D0:
	// li r11,0
	r11.s64 = 0;
loc_8214B3D4:
	// fctidz f0,f12
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lhz r10,102(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// lbz r8,64(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r8,11488
	ctx.r10.s64 = ctx.r8.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214b424
	if (cr6.eq) goto loc_8214B424;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b428
	goto loc_8214B428;
loc_8214B424:
	// li r11,0
	r11.s64 = 0;
loc_8214B428:
	// fmuls f0,f26,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f26.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b440
	if (!cr6.lt) goto loc_8214B440;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b448
	if (cr6.gt) goto loc_8214B448;
loc_8214B440:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b458
	if (cr6.eq) goto loc_8214B458;
loc_8214B448:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,34(r11)
	PPC_STORE_U16(r11.u32 + 34, ctx.r10.u16);
	// b 0x8214b49c
	goto loc_8214B49C;
loc_8214B458:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b468
	if (!cr6.gt) goto loc_8214B468;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b474
	goto loc_8214B474;
loc_8214B468:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b474
	if (!cr6.lt) goto loc_8214B474;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B474:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,34(r11)
	PPC_STORE_U16(r11.u32 + 34, ctx.r3.u16);
loc_8214B49C:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214b4dc
	if (cr6.eq) goto loc_8214B4DC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b4e0
	goto loc_8214B4E0;
loc_8214B4DC:
	// li r11,0
	r11.s64 = 0;
loc_8214B4E0:
	// fmuls f0,f24,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f24.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b4f8
	if (!cr6.lt) goto loc_8214B4F8;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b500
	if (cr6.gt) goto loc_8214B500;
loc_8214B4F8:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b510
	if (cr6.eq) goto loc_8214B510;
loc_8214B500:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,36(r11)
	PPC_STORE_U16(r11.u32 + 36, ctx.r10.u16);
	// b 0x8214b554
	goto loc_8214B554;
loc_8214B510:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b520
	if (!cr6.gt) goto loc_8214B520;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b52c
	goto loc_8214B52C;
loc_8214B520:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b52c
	if (!cr6.lt) goto loc_8214B52C;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B52C:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,36(r11)
	PPC_STORE_U16(r11.u32 + 36, ctx.r3.u16);
loc_8214B554:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214b594
	if (cr6.eq) goto loc_8214B594;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b598
	goto loc_8214B598;
loc_8214B594:
	// li r11,0
	r11.s64 = 0;
loc_8214B598:
	// fmuls f0,f23,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f23.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b5b0
	if (!cr6.lt) goto loc_8214B5B0;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b5b8
	if (cr6.gt) goto loc_8214B5B8;
loc_8214B5B0:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b5c8
	if (cr6.eq) goto loc_8214B5C8;
loc_8214B5B8:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,38(r11)
	PPC_STORE_U16(r11.u32 + 38, ctx.r10.u16);
	// b 0x8214b60c
	goto loc_8214B60C;
loc_8214B5C8:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b5d8
	if (!cr6.gt) goto loc_8214B5D8;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b5e4
	goto loc_8214B5E4;
loc_8214B5D8:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b5e4
	if (!cr6.lt) goto loc_8214B5E4;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B5E4:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,38(r11)
	PPC_STORE_U16(r11.u32 + 38, ctx.r3.u16);
loc_8214B60C:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214b64c
	if (cr6.eq) goto loc_8214B64C;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b650
	goto loc_8214B650;
loc_8214B64C:
	// li r11,0
	r11.s64 = 0;
loc_8214B650:
	// fmuls f0,f22,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f22.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b668
	if (!cr6.lt) goto loc_8214B668;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b670
	if (cr6.gt) goto loc_8214B670;
loc_8214B668:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b680
	if (cr6.eq) goto loc_8214B680;
loc_8214B670:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,40(r11)
	PPC_STORE_U16(r11.u32 + 40, ctx.r10.u16);
	// b 0x8214b6c4
	goto loc_8214B6C4;
loc_8214B680:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b690
	if (!cr6.gt) goto loc_8214B690;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b69c
	goto loc_8214B69C;
loc_8214B690:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b69c
	if (!cr6.lt) goto loc_8214B69C;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B69C:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,40(r11)
	PPC_STORE_U16(r11.u32 + 40, ctx.r3.u16);
loc_8214B6C4:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214b704
	if (cr6.eq) goto loc_8214B704;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b708
	goto loc_8214B708;
loc_8214B704:
	// li r11,0
	r11.s64 = 0;
loc_8214B708:
	// fmuls f0,f21,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f21.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b720
	if (!cr6.lt) goto loc_8214B720;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b728
	if (cr6.gt) goto loc_8214B728;
loc_8214B720:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b738
	if (cr6.eq) goto loc_8214B738;
loc_8214B728:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,42(r11)
	PPC_STORE_U16(r11.u32 + 42, ctx.r10.u16);
	// b 0x8214b77c
	goto loc_8214B77C;
loc_8214B738:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b748
	if (!cr6.gt) goto loc_8214B748;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b754
	goto loc_8214B754;
loc_8214B748:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b754
	if (!cr6.lt) goto loc_8214B754;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B754:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,42(r11)
	PPC_STORE_U16(r11.u32 + 42, ctx.r3.u16);
loc_8214B77C:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214b7bc
	if (cr6.eq) goto loc_8214B7BC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b7c0
	goto loc_8214B7C0;
loc_8214B7BC:
	// li r11,0
	r11.s64 = 0;
loc_8214B7C0:
	// fmuls f0,f20,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f20.f64 * ctx.f10.f64));
	// fsel f0,f0,f0,f28
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b7d8
	if (!cr6.lt) goto loc_8214B7D8;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b7e0
	if (cr6.gt) goto loc_8214B7E0;
loc_8214B7D8:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b7f0
	if (cr6.eq) goto loc_8214B7F0;
loc_8214B7E0:
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r10.u16);
	// b 0x8214b834
	goto loc_8214B834;
loc_8214B7F0:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b800
	if (!cr6.gt) goto loc_8214B800;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b80c
	goto loc_8214B80C;
loc_8214B800:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b80c
	if (!cr6.lt) goto loc_8214B80C;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B80C:
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r3.u16);
loc_8214B834:
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,164
	ctx.r6.s64 = ctx.r1.s64 + 164;
loc_8214B83C:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214b87c
	if (cr6.eq) goto loc_8214B87C;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b880
	goto loc_8214B880;
loc_8214B87C:
	// li r11,0
	r11.s64 = 0;
loc_8214B880:
	// lfs f0,-4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	f0.f64 = double(temp.f32);
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fsel f0,f13,f13,f28
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b8a0
	if (!cr6.lt) goto loc_8214B8A0;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b8a8
	if (cr6.gt) goto loc_8214B8A8;
loc_8214B8A0:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b8b8
	if (cr6.eq) goto loc_8214B8B8;
loc_8214B8A8:
	// stfs f28,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, r11.u16);
	// b 0x8214b8fc
	goto loc_8214B8FC;
loc_8214B8B8:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b8c8
	if (!cr6.gt) goto loc_8214B8C8;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b8d4
	goto loc_8214B8D4;
loc_8214B8C8:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b8d4
	if (!cr6.lt) goto loc_8214B8D4;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B8D4:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r11,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r11,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// sth r9,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, ctx.r9.u16);
loc_8214B8FC:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214b93c
	if (cr6.eq) goto loc_8214B93C;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b940
	goto loc_8214B940;
loc_8214B93C:
	// li r11,0
	r11.s64 = 0;
loc_8214B940:
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fsel f0,f13,f13,f28
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214b95c
	if (!cr6.lt) goto loc_8214B95C;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214b964
	if (cr6.gt) goto loc_8214B964;
loc_8214B95C:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214b974
	if (cr6.eq) goto loc_8214B974;
loc_8214B964:
	// stfs f28,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// sthx r10,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r10.u16);
	// b 0x8214b9b8
	goto loc_8214B9B8;
loc_8214B974:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214b984
	if (!cr6.gt) goto loc_8214B984;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214b990
	goto loc_8214B990;
loc_8214B984:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214b990
	if (!cr6.lt) goto loc_8214B990;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214B990:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r10,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// sthx r9,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r9.u16);
loc_8214B9B8:
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214b9f8
	if (cr6.eq) goto loc_8214B9F8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214b9fc
	goto loc_8214B9FC;
loc_8214B9F8:
	// li r11,0
	r11.s64 = 0;
loc_8214B9FC:
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	f0.f64 = double(temp.f32);
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fsel f0,f13,f13,f28
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f28.f64;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8214ba1c
	if (!cr6.lt) goto loc_8214BA1C;
	// fcmpu cr6,f0,f7
	cr6.compare(f0.f64, ctx.f7.f64);
	// bgt cr6,0x8214ba24
	if (cr6.gt) goto loc_8214BA24;
loc_8214BA1C:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214ba34
	if (cr6.eq) goto loc_8214BA34;
loc_8214BA24:
	// stfs f28,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// b 0x8214ba78
	goto loc_8214BA78;
loc_8214BA34:
	// fcmpu cr6,f0,f9
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8214ba44
	if (!cr6.gt) goto loc_8214BA44;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x8214ba50
	goto loc_8214BA50;
loc_8214BA44:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// bge cr6,0x8214ba50
	if (!cr6.lt) goto loc_8214BA50;
	// fmr f0,f8
	f0.f64 = ctx.f8.f64;
loc_8214BA50:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r11,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r11,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
loc_8214BA78:
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// addi r6,r6,12
	ctx.r6.s64 = ctx.r6.s64 + 12;
	// cmplwi cr6,r7,72
	cr6.compare<uint32_t>(ctx.r7.u32, 72, xer);
	// blt cr6,0x8214b83c
	if (cr6.lt) goto loc_8214B83C;
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214bac8
	if (cr6.eq) goto loc_8214BAC8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214bacc
	goto loc_8214BACC;
loc_8214BAC8:
	// li r11,0
	r11.s64 = 0;
loc_8214BACC:
	// stfs f19,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r3.u16);
	// lbz r8,64(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lbz r11,220(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 220);
	// mulli r10,r8,11488
	ctx.r10.s64 = ctx.r8.s64 * 11488;
	// lwz r9,232(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 232);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214bb34
	if (cr6.eq) goto loc_8214BB34;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214bb38
	goto loc_8214BB38;
loc_8214BB34:
	// li r11,0
	r11.s64 = 0;
loc_8214BB38:
	// stfs f28,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// sth r10,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r10.u16);
loc_8214BB44:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba00
	ctx.lr = 0x8214BB50;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8214AB58) {
	__imp__sub_8214AB58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214BB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214BB54) {
	__imp__sub_8214BB54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214BB58) {
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
	ctx.lr = 0x8214BB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r9,r10,16996
	ctx.r9.s64 = ctx.r10.s64 + 16996;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r5,255
	cr6.compare<uint32_t>(ctx.r5.u32, 255, xer);
	// beq cr6,0x8214bba0
	if (cr6.eq) goto loc_8214BBA0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ece0
	ctx.lr = 0x8214BB98;
	sub_8213ECE0(ctx, base);
	// li r11,255
	r11.s64 = 255;
	// stb r11,220(r31)
	PPC_STORE_U8(r31.u32 + 220, r11.u8);
loc_8214BBA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8214BBA8;
	sub_8213BA48(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214bbc4
	if (cr6.eq) goto loc_8214BBC4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x8214BBC4;
	sub_8213F7A8(ctx, base);
loc_8214BBC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8214BB58) {
	__imp__sub_8214BB58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214BBD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8214BBD8;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9cc
	ctx.lr = 0x8214BBE0;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-192
	r12.s64 = -192;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8214bc0c
	if (cr6.eq) goto loc_8214BC0C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214cad8
	goto loc_8214CAD8;
loc_8214BC0C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r8,223(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 223);
	// addi r22,r10,7216
	r22.s64 = ctx.r10.s64 + 7216;
	// lbz r7,222(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lhz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 52);
	// lwz r10,232(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r21,r11,26644
	r21.s64 = r11.s64 + 26644;
	// lwz r11,200(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 200);
	// extsh r24,r6
	r24.s64 = ctx.r6.s16;
	// mullw r9,r8,r11
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r23,r9,r10
	r23.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r3,r21,4
	ctx.r3.s64 = r21.s64 + 4;
	// mullw r11,r7,r11
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// lbz r9,199(r23)
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// add r20,r11,r10
	r20.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// rlwinm r7,r9,0,28,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// li r26,0
	r26.s64 = 0;
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r29,r23
	r29.u64 = r23.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v126,r5,r23
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8214bc90
	if (!cr6.eq) goto loc_8214BC90;
	// mr r29,r20
	r29.u64 = r20.u64;
loc_8214BC90:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82148f08
	ctx.lr = 0x8214BC98;
	sub_82148F08(ctx, base);
	// lbz r10,199(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 199);
	// addi r9,r21,4
	ctx.r9.s64 = r21.s64 + 4;
	// lbz r11,226(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// rlwinm r8,r10,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFF8;
	// rlwinm r7,r11,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwzx r6,r8,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r10,r6,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + r29.u64;
	// lbz r4,95(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 95);
	// rlwinm r10,r4,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// beq cr6,0x8214bcd8
	if (cr6.eq) goto loc_8214BCD8;
	// rlwimi r11,r10,2,0,29
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0xFFFFFFFC) | (r11.u64 & 0xFFFFFFFF00000003);
	// li r26,1
	r26.s64 = 1;
	// stb r11,226(r31)
	PPC_STORE_U8(r31.u32 + 226, r11.u8);
loc_8214BCD8:
	// lbz r11,199(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 199);
	// addi r10,r21,4
	ctx.r10.s64 = r21.s64 + 4;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lbz r8,221(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// rlwinm r7,r11,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// li r25,1
	r25.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r11,r7,r10
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v127,r5,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8214bd4c
	if (!cr6.eq) goto loc_8214BD4C;
	// lbz r11,199(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// addi r10,r21,4
	ctx.r10.s64 = r21.s64 + 4;
	// rlwinm r9,r11,30,2,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r23
	ctx.r7.u64 = r11.u64 + r23.u64;
	// lbz r6,92(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 92);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8214bd4c
	if (!cr6.eq) goto loc_8214BD4C;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bge cr6,0x8214bd4c
	if (!cr6.lt) goto loc_8214BD4C;
	// lbz r11,227(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// rlwinm r10,r11,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFC0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214bd60
	if (!cr6.eq) goto loc_8214BD60;
	// b 0x8214bd5c
	goto loc_8214BD5C;
loc_8214BD4C:
	// lbz r11,227(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// rlwinm r10,r11,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFC0;
	// cmplwi cr6,r10,64
	cr6.compare<uint32_t>(ctx.r10.u32, 64, xer);
	// beq cr6,0x8214bd60
	if (cr6.eq) goto loc_8214BD60;
loc_8214BD5C:
	// li r25,0
	r25.s64 = 0;
loc_8214BD60:
	// lhz r11,62(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// lfs f31,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	f31.f64 = double(temp.f32);
	// lhz r10,54(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 54);
	// lfs f30,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f30.f64 = double(temp.f32);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// extsh r28,r10
	r28.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8214bdac
	if (cr6.eq) goto loc_8214BDAC;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,26652(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 26652);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 28);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f30,f0,f30
	f30.f64 = double(float(f0.f64 + f30.f64));
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
loc_8214BDAC:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// lis r10,32640
	ctx.r10.s64 = 2139095040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r19,r11,16696
	r19.s64 = r11.s64 + 16696;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// lfs f12,-20(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + -20);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8214bde8
	if (!cr6.eq) goto loc_8214BDE8;
	// fmr f31,f12
	f31.f64 = ctx.f12.f64;
loc_8214BDE8:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f29,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r8,r9,0,1,8
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7F800000;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214be70
	if (cr6.eq) goto loc_8214BE70;
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7F800000;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
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
	// bne cr6,0x8214bea0
	if (!cr6.eq) goto loc_8214BEA0;
loc_8214BE70:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f29,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f29,112(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f31,f12
	f31.f64 = ctx.f12.f64;
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f30,f12
	f30.f64 = ctx.f12.f64;
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f29,120(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8214BEA0:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8215e0c0
	ctx.lr = 0x8214BEA8;
	sub_8215E0C0(ctx, base);
	// lhz r6,216(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 216);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r5,62(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// lwz r9,26652(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26652);
	// stw r31,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r31.u32);
	// addi r7,r21,4
	ctx.r7.s64 = r21.s64 + 4;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lhz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// sth r5,340(r1)
	PPC_STORE_U16(ctx.r1.u32 + 340, ctx.r5.u16);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// fnmsubs f10,f11,f0,f31
	ctx.f10.f64 = double(float(-(ctx.f11.f64 * f0.f64 - f31.f64)));
	// stfs f10,292(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lbz r9,199(r23)
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r9,r8,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// rlwinm r6,r7,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lfsx f9,r6,r23
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r23.u32);
	ctx.f9.f64 = double(temp.f32);
	// stw r27,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r27.u32);
	// stfs f9,296(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f30,300(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// lhz r9,30(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 30);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stw r10,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r10.u32);
	// blt cr6,0x8214bf34
	if (cr6.lt) goto loc_8214BF34;
	// stw r9,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r9.u32);
loc_8214BF34:
	// lhz r10,50(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 50);
	// lhz r11,32(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// stw r10,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r10.u32);
	// bgt cr6,0x8214bf4c
	if (cr6.gt) goto loc_8214BF4C;
	// stw r11,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r11.u32);
loc_8214BF4C:
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// lbz r10,221(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// lbz r8,225(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 225);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// lfs f13,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 204);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r21,4
	ctx.r6.s64 = r21.s64 + 4;
	// lfs f12,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r21,4
	ctx.r5.s64 = r21.s64 + 4;
	// lbz r4,226(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r21,4
	r30.s64 = r21.s64 + 4;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r21,4
	ctx.r9.s64 = r21.s64 + 4;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r24,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r24.u32);
	// lbz r7,199(r23)
	ctx.r7.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// rlwinm r11,r7,30,2,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r7,r11,r6
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// lfs f0,15364(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 15364);
	f0.f64 = double(temp.f32);
	// lbz r6,227(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// clrlwi r27,r4,30
	r27.u64 = ctx.r4.u32 & 0x3;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r7,r6,31,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x1;
	// add r6,r11,r23
	ctx.r6.u64 = r11.u64 + r23.u64;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lbz r11,92(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 92);
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// stb r10,342(r1)
	PPC_STORE_U8(ctx.r1.u32 + 342, ctx.r10.u8);
	// stb r25,344(r1)
	PPC_STORE_U8(ctx.r1.u32 + 344, r25.u8);
	// stb r26,345(r1)
	PPC_STORE_U8(ctx.r1.u32 + 345, r26.u8);
	// lbz r6,199(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 199);
	// rlwinm r11,r6,30,2,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r10,r11,r5
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// lwz r3,26660(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26660);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r29
	ctx.r6.u64 = r11.u64 + r29.u64;
	// lfs f11,84(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r8.u32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f12,328(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f10,316(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// lbz r5,199(r23)
	ctx.r5.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// rlwinm r11,r5,30,2,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r23
	ctx.r8.u64 = r11.u64 + r23.u64;
	// lbz r5,93(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 93);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,336(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lbz r11,199(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// rlwinm r10,r11,30,2,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r23
	ctx.r8.u64 = r11.u64 + r23.u64;
	// lbz r6,94(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 94);
	// stb r6,343(r1)
	PPC_STORE_U8(ctx.r1.u32 + 343, ctx.r6.u8);
	// stb r27,347(r1)
	PPC_STORE_U8(ctx.r1.u32 + 347, r27.u8);
	// stb r7,346(r1)
	PPC_STORE_U8(ctx.r1.u32 + 346, ctx.r7.u8);
	// bl 0x8215fdc0
	ctx.lr = 0x8214C058;
	sub_8215FDC0(ctx, base);
	// clrlwi r5,r26,24
	ctx.r5.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214c080
	if (cr6.eq) goto loc_8214C080;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,320(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmadds f10,f12,f0,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// stfs f10,208(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
loc_8214C080:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// extsw r11,r28
	r11.s64 = r28.s32;
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// vslw128 v59,v62,v62
	v59.u32[0] = v62.u32[0] << (v62.u8[0] & 0x1F);
	v59.u32[1] = v62.u32[1] << (v62.u8[4] & 0x1F);
	v59.u32[2] = v62.u32[2] << (v62.u8[8] & 0x1F);
	v59.u32[3] = v62.u32[3] << (v62.u8[12] & 0x1F);
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vspltisw128 v58,-9
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0xFFFFFFF7)));
	// vupkd3d128 v57,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v57 = vTemp;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f11,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,292(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// li r30,34
	r30.s64 = 34;
	// lfs f13,11324(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11324);
	ctx.f13.f64 = double(temp.f32);
	// vslw128 v52,v62,v58
	v52.u32[0] = v62.u32[0] << (v58.u8[0] & 0x1F);
	v52.u32[1] = v62.u32[1] << (v58.u8[4] & 0x1F);
	v52.u32[2] = v62.u32[2] << (v58.u8[8] & 0x1F);
	v52.u32[3] = v62.u32[3] << (v58.u8[12] & 0x1F);
	// vspltw128 v13,v57,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x0));
	// fsubs f25,f10,f0
	f25.f64 = double(float(ctx.f10.f64 - f0.f64));
	// addi r29,r1,152
	r29.s64 = ctx.r1.s64 + 152;
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// vsrw128 v12,v52,v61
	ctx.v12.u32[0] = v52.u32[0] >> (v61.u8[0] & 0x1F);
	ctx.v12.u32[1] = v52.u32[1] >> (v61.u8[4] & 0x1F);
	ctx.v12.u32[2] = v52.u32[2] >> (v61.u8[8] & 0x1F);
	ctx.v12.u32[3] = v52.u32[3] >> (v61.u8[12] & 0x1F);
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vandc128 v56,v63,v59
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v50,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vcfpsxws128 v49,v50,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_si128((simde__m128i*)v49.s32, simde_mm_vctsxs(simde_mm_load_ps(v50.f32)));
	// vlogefp128 v55,v56
	v55.f32[0] = log2f(v56.f32[0]);
	v55.f32[1] = log2f(v56.f32[1]);
	v55.f32[2] = log2f(v56.f32[2]);
	v55.f32[3] = log2f(v56.f32[3]);
	// vand128 v47,v49,v61
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vrfiz128 v48,v50
	simde_mm_store_ps(v48.f32, simde_mm_round_ps(simde_mm_load_ps(v50.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vand128 v54,v63,v59
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vcmpeqfp128 v53,v63,v60
	simde_mm_store_ps(v53.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128 v45,v60,v50
	simde_mm_store_ps(v45.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v50.f32)));
	// vslw128 v44,v47,v62
	v44.u32[0] = v47.u32[0] << (v62.u8[0] & 0x1F);
	v44.u32[1] = v47.u32[1] << (v62.u8[4] & 0x1F);
	v44.u32[2] = v47.u32[2] << (v62.u8[8] & 0x1F);
	v44.u32[3] = v47.u32[3] << (v62.u8[12] & 0x1F);
	// vcmpeqfp128 v0,v50,v60
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v60.f32)));
	// vcmpgtfp128 v51,v60,v63
	simde_mm_store_ps(v51.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// vand128 v43,v54,v44
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vmulfp128 v46,v55,v50
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v50.f32)));
	// vor128 v11,v60,v43
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vcmpeqfp128 v42,v50,v48
	simde_mm_store_ps(v42.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v48.f32)));
	// vandc128 v10,v53,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vor128 v40,v53,v0
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vsel v9,v12,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v8,v9,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vexptefp128 v41,v46
	v41.f32[0] = exp2f(v46.f32[0]);
	v41.f32[1] = exp2f(v46.f32[1]);
	v41.f32[2] = exp2f(v46.f32[2]);
	v41.f32[3] = exp2f(v46.f32[3]);
	// vandc128 v39,v51,v42
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vor128 v6,v39,v40
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vor128 v7,v41,v43
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vsel v5,v7,v8,v6
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// stvx128 v5,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f26,f11,f7
	f26.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
loc_8214C170:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c1b0
	if (cr6.eq) goto loc_8214C1B0;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c1b4
	goto loc_8214C1B4;
loc_8214C1B0:
	// li r11,0
	r11.s64 = 0;
loc_8214C1B4:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// fsel f1,f0,f0,f29
	ctx.f1.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// bl 0x8213e850
	ctx.lr = 0x8214C1C4;
	sub_8213E850(ctx, base);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,46
	cr6.compare<uint32_t>(r30.u32, 46, xer);
	// blt cr6,0x8214c170
	if (cr6.lt) goto loc_8214C170;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,4(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r19.u32 + 4);
	f30.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f31.f64 = double(temp.f32);
	// addi r6,r1,188
	ctx.r6.s64 = ctx.r1.s64 + 188;
	// li r7,52
	ctx.r7.s64 = 52;
	// lfs f28,11772(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11772);
	f28.f64 = double(temp.f32);
	// lfs f27,11776(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11776);
	f27.f64 = double(temp.f32);
loc_8214C1F4:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214c234
	if (cr6.eq) goto loc_8214C234;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c238
	goto loc_8214C238;
loc_8214C234:
	// li r11,0
	r11.s64 = 0;
loc_8214C238:
	// lfs f0,-12(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12);
	f0.f64 = double(temp.f32);
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8214c254
	if (!cr6.lt) goto loc_8214C254;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c25c
	if (cr6.gt) goto loc_8214C25C;
loc_8214C254:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c26c
	if (cr6.eq) goto loc_8214C26C;
loc_8214C25C:
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// sth r11,-6(r10)
	PPC_STORE_U16(ctx.r10.u32 + -6, r11.u16);
	// b 0x8214c2b0
	goto loc_8214C2B0;
loc_8214C26C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8214c27c
	if (!cr6.gt) goto loc_8214C27C;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8214c288
	goto loc_8214C288;
loc_8214C27C:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c288
	if (!cr6.lt) goto loc_8214C288;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C288:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r11,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r11,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// sth r9,-6(r10)
	PPC_STORE_U16(ctx.r10.u32 + -6, ctx.r9.u16);
loc_8214C2B0:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214c2f0
	if (cr6.eq) goto loc_8214C2F0;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c2f4
	goto loc_8214C2F4;
loc_8214C2F0:
	// li r11,0
	r11.s64 = 0;
loc_8214C2F4:
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8214c30c
	if (!cr6.lt) goto loc_8214C30C;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c314
	if (cr6.gt) goto loc_8214C314;
loc_8214C30C:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c324
	if (cr6.eq) goto loc_8214C324;
loc_8214C314:
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// sthx r10,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r10.u16);
	// b 0x8214c368
	goto loc_8214C368;
loc_8214C324:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8214c334
	if (!cr6.gt) goto loc_8214C334;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8214c340
	goto loc_8214C340;
loc_8214C334:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c340
	if (!cr6.lt) goto loc_8214C340;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C340:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r10,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// sthx r9,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r9.u16);
loc_8214C368:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214c3a8
	if (cr6.eq) goto loc_8214C3A8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c3ac
	goto loc_8214C3AC;
loc_8214C3A8:
	// li r11,0
	r11.s64 = 0;
loc_8214C3AC:
	// lfs f0,12(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	f0.f64 = double(temp.f32);
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8214c3c8
	if (!cr6.lt) goto loc_8214C3C8;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c3d0
	if (cr6.gt) goto loc_8214C3D0;
loc_8214C3C8:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c3e0
	if (cr6.eq) goto loc_8214C3E0;
loc_8214C3D0:
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// sth r11,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r11.u16);
	// b 0x8214c424
	goto loc_8214C424;
loc_8214C3E0:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8214c3f0
	if (!cr6.gt) goto loc_8214C3F0;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8214c3fc
	goto loc_8214C3FC;
loc_8214C3F0:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c3fc
	if (!cr6.lt) goto loc_8214C3FC;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C3FC:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r11,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r11,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// sth r9,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r9.u16);
loc_8214C424:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214c464
	if (cr6.eq) goto loc_8214C464;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c468
	goto loc_8214C468;
loc_8214C464:
	// li r11,0
	r11.s64 = 0;
loc_8214C468:
	// lfs f0,24(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	f0.f64 = double(temp.f32);
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8214c484
	if (!cr6.lt) goto loc_8214C484;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c48c
	if (cr6.gt) goto loc_8214C48C;
loc_8214C484:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c49c
	if (cr6.eq) goto loc_8214C49C;
loc_8214C48C:
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// sth r11,12(r10)
	PPC_STORE_U16(ctx.r10.u32 + 12, r11.u16);
	// b 0x8214c4e0
	goto loc_8214C4E0;
loc_8214C49C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8214c4ac
	if (!cr6.gt) goto loc_8214C4AC;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8214c4b8
	goto loc_8214C4B8;
loc_8214C4AC:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c4b8
	if (!cr6.lt) goto loc_8214C4B8;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C4B8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r11,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// rlwinm r4,r11,16,16,16
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r3,r5,10,0,21
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0xFFFFFC00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// sth r9,12(r10)
	PPC_STORE_U16(ctx.r10.u32 + 12, ctx.r9.u16);
loc_8214C4E0:
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplwi cr6,r7,58
	cr6.compare<uint32_t>(ctx.r7.u32, 58, xer);
	// blt cr6,0x8214c1f4
	if (cr6.lt) goto loc_8214C1F4;
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r7,100
	ctx.r7.s64 = 100;
	// cmplwi cr6,r11,100
	cr6.compare<uint32_t>(r11.u32, 100, xer);
	// blt cr6,0x8214c504
	if (cr6.lt) goto loc_8214C504;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_8214C504:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r6,r8,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214c544
	if (cr6.eq) goto loc_8214C544;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c548
	goto loc_8214C548;
loc_8214C544:
	// li r11,0
	r11.s64 = 0;
loc_8214C548:
	// sth r7,16(r11)
	PPC_STORE_U16(r11.u32 + 16, ctx.r7.u16);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mulli r10,r9,11488
	ctx.r10.s64 = ctx.r9.s64 * 11488;
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c58c
	if (cr6.eq) goto loc_8214C58C;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c590
	goto loc_8214C590;
loc_8214C58C:
	// li r11,0
	r11.s64 = 0;
loc_8214C590:
	// lwz r10,312(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mulli r10,r8,11488
	ctx.r10.s64 = ctx.r8.s64 * 11488;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8214c5d8
	if (cr6.eq) goto loc_8214C5D8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r30,r11,96
	r30.s64 = r11.s64 + 96;
	// b 0x8214c5dc
	goto loc_8214C5DC;
loc_8214C5D8:
	// li r30,0
	r30.s64 = 0;
loc_8214C5DC:
	// lfs f1,300(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821493f8
	ctx.lr = 0x8214C5E4;
	sub_821493F8(ctx, base);
	// fsel f0,f1,f1,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f29.f64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8214c5f8
	if (!cr6.lt) goto loc_8214C5F8;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c600
	if (cr6.gt) goto loc_8214C600;
loc_8214C5F8:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c610
	if (cr6.eq) goto loc_8214C610;
loc_8214C600:
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r11,26(r30)
	PPC_STORE_U16(r30.u32 + 26, r11.u16);
	// b 0x8214c654
	goto loc_8214C654;
loc_8214C610:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8214c620
	if (!cr6.gt) goto loc_8214C620;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x8214c62c
	goto loc_8214C62C;
loc_8214C620:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c62c
	if (!cr6.lt) goto loc_8214C62C;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C62C:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,9,23,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r9,r11,19,22,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// rlwinm r7,r11,16,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r6,r8,10,0,21
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0xFFFFFC00;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// sth r4,26(r30)
	PPC_STORE_U16(r30.u32 + 26, ctx.r4.u16);
loc_8214C654:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,168(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r31,164
	r29.s64 = r31.s64 + 164;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82162870
	ctx.lr = 0x8214C678;
	sub_82162870(ctx, base);
	// lwz r11,232(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x8214c708
	if (!cr6.gt) goto loc_8214C708;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r8,r9,359
	ctx.r8.s64 = ctx.r9.s64 * 359;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r8,r8,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// lwz r6,7784(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7784);
	// rlwinm r5,r6,0,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8214c708
	if (!cr6.gt) goto loc_8214C708;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c6f0
	if (cr6.eq) goto loc_8214C6F0;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r30,r11,96
	r30.s64 = r11.s64 + 96;
	// bl 0x82162880
	ctx.lr = 0x8214C6E8;
	sub_82162880(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8214c74c
	goto loc_8214C74C;
loc_8214C6F0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82162880
	ctx.lr = 0x8214C700;
	sub_82162880(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8214c74c
	goto loc_8214C74C;
loc_8214C708:
	// lbz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c744
	if (cr6.eq) goto loc_8214C744;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c748
	goto loc_8214C748;
loc_8214C744:
	// li r11,0
	r11.s64 = 0;
loc_8214C748:
	// stfs f26,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_8214C74C:
	// lbz r11,199(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// addi r8,r21,4
	ctx.r8.s64 = r21.s64 + 4;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r6,r11,30,2,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// rlwinm r8,r5,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r8,r23
	ctx.r3.u64 = ctx.r8.u64 + r23.u64;
	// lbzx r8,r4,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// lbz r7,95(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 95);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// rlwinm r7,r7,30,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c7ac
	if (cr6.eq) goto loc_8214C7AC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c7b0
	goto loc_8214C7B0;
loc_8214C7AC:
	// li r11,0
	r11.s64 = 0;
loc_8214C7B0:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// rlwimi r10,r7,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r10.u8);
	// bl 0x821493f8
	ctx.lr = 0x8214C7C4;
	sub_821493F8(ctx, base);
	// lbz r8,199(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// addi r7,r21,4
	ctx.r7.s64 = r21.s64 + 4;
	// lbz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r5,r8,30,2,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFF8;
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r6,11488
	ctx.r10.s64 = ctx.r6.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r8,r4,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 + r23.u64;
	// lbzx r7,r3,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// lfs f0,72(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c820
	if (cr6.eq) goto loc_8214C820;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c824
	goto loc_8214C824;
loc_8214C820:
	// li r11,0
	r11.s64 = 0;
loc_8214C824:
	// fmuls f0,f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lfs f31,4(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 4);
	f31.f64 = double(temp.f32);
	// lfs f30,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f30.f64 = double(temp.f32);
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8214c844
	if (!cr6.lt) goto loc_8214C844;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c84c
	if (cr6.gt) goto loc_8214C84C;
loc_8214C844:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c85c
	if (cr6.eq) goto loc_8214C85C;
loc_8214C84C:
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r10.u16);
	// b 0x8214c8a0
	goto loc_8214C8A0;
loc_8214C85C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8214c86c
	if (!cr6.gt) goto loc_8214C86C;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x8214c878
	goto loc_8214C878;
loc_8214C86C:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c878
	if (!cr6.lt) goto loc_8214C878;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C878:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r3.u16);
loc_8214C8A0:
	// lbz r11,199(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 199);
	// addi r8,r21,4
	ctx.r8.s64 = r21.s64 + 4;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r6,r11,30,2,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFF8;
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r8,r5,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r8,r23
	ctx.r3.u64 = ctx.r8.u64 + r23.u64;
	// lbzx r8,r4,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// lfs f0,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8214c8fc
	if (cr6.eq) goto loc_8214C8FC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214c900
	goto loc_8214C900;
loc_8214C8FC:
	// li r11,0
	r11.s64 = 0;
loc_8214C900:
	// fmuls f0,f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8214c918
	if (!cr6.lt) goto loc_8214C918;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c920
	if (cr6.gt) goto loc_8214C920;
loc_8214C918:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c930
	if (cr6.eq) goto loc_8214C930;
loc_8214C920:
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r10,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r10.u16);
	// b 0x8214c974
	goto loc_8214C974;
loc_8214C930:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8214c940
	if (!cr6.gt) goto loc_8214C940;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x8214c94c
	goto loc_8214C94C;
loc_8214C940:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214c94c
	if (!cr6.lt) goto loc_8214C94C;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214C94C:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,9,23,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FF;
	// rlwinm r8,r10,19,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x3FF;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r10,16,16,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x8000;
	// rlwinm r5,r7,10,0,21
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// sth r3,30(r11)
	PPC_STORE_U16(r11.u32 + 30, ctx.r3.u16);
loc_8214C974:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214c9b4
	if (cr6.eq) goto loc_8214C9B4;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r30,r11,96
	r30.s64 = r11.s64 + 96;
	// b 0x8214c9b8
	goto loc_8214C9B8;
loc_8214C9B4:
	// li r30,0
	r30.s64 = 0;
loc_8214C9B8:
	// lfs f1,296(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821493f8
	ctx.lr = 0x8214C9C0;
	sub_821493F8(ctx, base);
	// fsel f0,f1,f1,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f29.f64;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8214c9d4
	if (!cr6.lt) goto loc_8214C9D4;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x8214c9dc
	if (cr6.gt) goto loc_8214C9DC;
loc_8214C9D4:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// beq cr6,0x8214c9ec
	if (cr6.eq) goto loc_8214C9EC;
loc_8214C9DC:
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r11,32(r30)
	PPC_STORE_U16(r30.u32 + 32, r11.u16);
	// b 0x8214ca30
	goto loc_8214CA30;
loc_8214C9EC:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8214c9fc
	if (!cr6.gt) goto loc_8214C9FC;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x8214ca08
	goto loc_8214CA08;
loc_8214C9FC:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8214ca08
	if (!cr6.lt) goto loc_8214CA08;
	// fmr f0,f28
	f0.f64 = f28.f64;
loc_8214CA08:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,9,23,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// rlwinm r9,r11,19,22,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// rlwinm r7,r11,16,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// rlwinm r6,r8,10,0,21
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0xFFFFFC00;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// sth r4,32(r30)
	PPC_STORE_U16(r30.u32 + 32, ctx.r4.u16);
loc_8214CA30:
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r9,220(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r11,359
	ctx.r10.s64 = r11.s64 * 359;
	// lwz r11,232(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,7792(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 7792);
	// rlwinm r8,r9,0,0,1
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC0000000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214cad4
	if (cr6.eq) goto loc_8214CAD4;
	// lbz r11,7788(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 7788);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214cad4
	if (cr6.eq) goto loc_8214CAD4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d6b0
	ctx.lr = 0x8214CA78;
	sub_8213D6B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cad4
	if (cr6.eq) goto loc_8214CAD4;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214cac4
	if (cr6.eq) goto loc_8214CAC4;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8214cac8
	goto loc_8214CAC8;
loc_8214CAC4:
	// li r11,0
	r11.s64 = 0;
loc_8214CAC8:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_8214CAD4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8214CAD8:
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-192
	r0.s64 = -192;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba18
	ctx.lr = 0x8214CAF4;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_8214BBD0) {
	__imp__sub_8214BBD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CAF8) {
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
	ctx.lr = 0x8214CB00;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,255
	r24.s64 = 255;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// lbz r8,227(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// mr r29,r24
	r29.u64 = r24.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// rlwinm r10,r8,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214cb58
	if (cr6.eq) goto loc_8214CB58;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lbz r7,224(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 224);
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r7,r11
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lbz r29,198(r5)
	r29.u64 = PPC_LOAD_U8(ctx.r5.u32 + 198);
loc_8214CB58:
	// clrlwi r26,r29,24
	r26.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r26,255
	cr6.compare<uint32_t>(r26.u32, 255, xer);
	// beq cr6,0x8214cc30
	if (cr6.eq) goto loc_8214CC30;
	// lbz r11,226(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8214cc30
	if (cr6.eq) goto loc_8214CC30;
	// rlwinm r11,r8,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cba8
	if (cr6.eq) goto loc_8214CBA8;
	// lbz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// cmplwi cr6,r5,255
	cr6.compare<uint32_t>(ctx.r5.u32, 255, xer);
	// beq cr6,0x8214cb9c
	if (cr6.eq) goto loc_8214CB9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ece0
	ctx.lr = 0x8214CB98;
	sub_8213ECE0(ctx, base);
	// stb r24,220(r31)
	PPC_STORE_U8(r31.u32 + 220, r24.u8);
loc_8214CB9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
loc_8214CBA8:
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// twllei r11,0
	// lwz r9,11440(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// subf r8,r9,r31
	ctx.r8.s64 = r31.s64 - ctx.r9.s64;
	// divwu r7,r8,r11
	ctx.r7.u32 = ctx.r8.u32 / r11.u32;
	// clrlwi r28,r7,24
	r28.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x8213d4b8
	ctx.lr = 0x8214CBD8;
	sub_8213D4B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214cc08
	if (cr6.eq) goto loc_8214CC08;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r11,r7,r10
	r11.u32 = ctx.r7.u32 / ctx.r10.u32;
	// b 0x8214cc0c
	goto loc_8214CC0C;
loc_8214CC08:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8214CC0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// subf r10,r11,r26
	ctx.r10.s64 = r26.s64 - r11.s64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r6,r9,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x8213ed68
	ctx.lr = 0x8214CC2C;
	sub_8213ED68(ctx, base);
	// b 0x8214cc3c
	goto loc_8214CC3C;
loc_8214CC30:
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cb9c
	if (cr6.eq) goto loc_8214CB9C;
loc_8214CC3C:
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8214cd4c
	if (!cr6.eq) goto loc_8214CD4C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213f918
	ctx.lr = 0x8214CC54;
	sub_8213F918(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stb r3,220(r31)
	PPC_STORE_U8(r31.u32 + 220, ctx.r3.u8);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214cd4c
	if (cr6.eq) goto loc_8214CD4C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8213f5a0
	ctx.lr = 0x8214CC6C;
	sub_8213F5A0(ctx, base);
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// lhz r10,218(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 218);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// sth r10,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r10.u16);
	// bl 0x8213d378
	ctx.lr = 0x8214CC88;
	sub_8213D378(ctx, base);
	// lbz r9,227(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lbz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 104);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r4,11488
	ctx.r10.s64 = ctx.r4.s64 * 11488;
	// lbz r11,220(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// stb r8,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r8.u8);
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// rlwimi r5,r7,3,28,28
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r7.u32, 3) & 0x8) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFF7);
	// lbz r7,226(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 226);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r6,r5,3,25,26
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 3) & 0x60) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF9F);
	// clrlwi r8,r7,30
	ctx.r8.u64 = ctx.r7.u32 & 0x3;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// lbzx r6,r3,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + r11.u32);
	// rlwinm r5,r7,0,24,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFE;
	// clrlwi r4,r6,31
	ctx.r4.u64 = ctx.r6.u32 & 0x1;
	// ori r3,r5,1
	ctx.r3.u64 = ctx.r5.u64 | 1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stb r3,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r3.u8);
	// beq cr6,0x8214cd10
	if (cr6.eq) goto loc_8214CD10;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// b 0x8214cd14
	goto loc_8214CD14;
loc_8214CD10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214CD14:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8214aa80
	ctx.lr = 0x8214CD1C;
	sub_8214AA80(ctx, base);
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r9,220(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// mulli r10,r10,359
	ctx.r10.s64 = ctx.r10.s64 * 359;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,7784
	ctx.r10.s64 = r11.s64 + 7784;
	// lwz r6,7784(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 7784);
	// rlwimi r6,r8,3,0,28
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 3) & 0xFFFFFFF8) | (ctx.r6.u64 & 0xFFFFFFFF00000007);
	// stw r6,7784(r11)
	PPC_STORE_U32(r11.u32 + 7784, ctx.r6.u32);
loc_8214CD4C:
	// lbz r9,220(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8214ce04
	if (cr6.eq) goto loc_8214CE04;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,359
	r11.s64 = r11.s64 * 359;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,7784(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 7784);
	// rlwinm r6,r7,0,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi cr6,r6,-8
	cr6.compare<int32_t>(ctx.r6.s32, -8, xer);
	// bne cr6,0x8214cdf4
	if (!cr6.eq) goto loc_8214CDF4;
	// cmplwi cr6,r26,255
	cr6.compare<uint32_t>(r26.u32, 255, xer);
	// beq cr6,0x8214cdd0
	if (cr6.eq) goto loc_8214CDD0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d4b8
	ctx.lr = 0x8214CD90;
	sub_8213D4B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214cdc0
	if (cr6.eq) goto loc_8214CDC0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r11,r7,r10
	r11.u32 = ctx.r7.u32 / ctx.r10.u32;
	// b 0x8214cdc4
	goto loc_8214CDC4;
loc_8214CDC0:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8214CDC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bne cr6,0x8214cdf4
	if (!cr6.eq) goto loc_8214CDF4;
loc_8214CDD0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ece0
	ctx.lr = 0x8214CDE0;
	sub_8213ECE0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// stb r24,220(r31)
	PPC_STORE_U8(r31.u32 + 220, r24.u8);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
loc_8214CDF4:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214bbd0
	ctx.lr = 0x8214CE00;
	sub_8214BBD0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8214CE04:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8214CAF8) {
	__imp__sub_8214CAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE10) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214caf8
	sub_8214CAF8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214CE10) {
	__imp__sub_8214CE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214CE14) {
	__imp__sub_8214CE14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE18) {
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
	// lbz r11,223(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 223);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8214ce48
	if (!cr6.eq) goto loc_8214CE48;
	// bl 0x8213d168
	ctx.lr = 0x8214CE44;
	sub_8213D168(ctx, base);
	// stb r3,223(r31)
	PPC_STORE_U8(r31.u32 + 223, ctx.r3.u8);
loc_8214CE48:
	// lbz r11,227(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 227);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214ce70
	if (cr6.eq) goto loc_8214CE70;
	// lbz r11,224(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 224);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8214ce70
	if (!cr6.eq) goto loc_8214CE70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d1e0
	ctx.lr = 0x8214CE6C;
	sub_8213D1E0(ctx, base);
	// stb r3,224(r31)
	PPC_STORE_U8(r31.u32 + 224, ctx.r3.u8);
loc_8214CE70:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214caf8
	ctx.lr = 0x8214CE7C;
	sub_8214CAF8(ctx, base);
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

PPC_WEAK_FUNC(sub_8214CE18) {
	__imp__sub_8214CE18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214CE94) {
	__imp__sub_8214CE94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE98) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214ce18
	sub_8214CE18(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214CE98) {
	__imp__sub_8214CE98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214CE9C) {
	__imp__sub_8214CE9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CEA0) {
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
	// addi r3,r31,136
	ctx.r3.s64 = r31.s64 + 136;
	// bl 0x821629d0
	ctx.lr = 0x8214CEBC;
	sub_821629D0(ctx, base);
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

PPC_WEAK_FUNC(sub_8214CEA0) {
	__imp__sub_8214CEA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214CED4) {
	__imp__sub_8214CED4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CED8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,136
	ctx.r3.s64 = ctx.r3.s64 + 136;
	// b 0x821602f0
	sub_821602F0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214CED8) {
	__imp__sub_8214CED8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CEE0) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// stb r11,26692(r10)
	PPC_STORE_U8(ctx.r10.u32 + 26692, r11.u8);
	// bl 0x821621f0
	ctx.lr = 0x8214CEFC;
	sub_821621F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8214cf1c
	if (!cr6.eq) goto loc_8214CF1C;
loc_8214CF08:
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
loc_8214CF1C:
	// bl 0x82163ad8
	ctx.lr = 0x8214CF20;
	sub_82163AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82163840
	ctx.lr = 0x8214CF30;
	sub_82163840(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82163670
	ctx.lr = 0x8214CF40;
	sub_82163670(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82163330
	ctx.lr = 0x8214CF50;
	sub_82163330(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82162f50
	ctx.lr = 0x8214CF60;
	sub_82162F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82162ed8
	ctx.lr = 0x8214CF70;
	sub_82162ED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214cf08
	if (cr6.eq) goto loc_8214CF08;
	// bl 0x82162e28
	ctx.lr = 0x8214CF80;
	sub_82162E28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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

PPC_WEAK_FUNC(sub_8214CEE0) {
	__imp__sub_8214CEE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214CFA0) {
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
	ctx.lr = 0x8214CFA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8214d010
	if (!cr6.gt) goto loc_8214D010;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8214CFC8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214cffc
	if (cr6.eq) goto loc_8214CFFC;
	// bl 0x82135fb8
	ctx.lr = 0x8214CFD8;
	sub_82135FB8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214cff8
	if (cr6.eq) goto loc_8214CFF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214CFF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8214CFF8:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_8214CFFC:
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8214cfc8
	if (cr6.lt) goto loc_8214CFC8;
loc_8214D010:
	// addi r11,r29,100
	r11.s64 = r29.s64 + 100;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8214D020:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8214d020
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214D020;
	// addi r3,r29,136
	ctx.r3.s64 = r29.s64 + 136;
	// bl 0x82160310
	ctx.lr = 0x8214D034;
	sub_82160310(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8214CFA0) {
	__imp__sub_8214CFA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D03C) {
	__imp__sub_8214D03C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,1
	r11.s64 = 1;
	// stb r11,26692(r10)
	PPC_STORE_U8(ctx.r10.u32 + 26692, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D040) {
	__imp__sub_8214D040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D050) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,26692(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 26692);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214d0a8
	if (cr6.eq) goto loc_8214D0A8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,24
	r30.s64 = 24;
loc_8214D07C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d09c
	if (cr6.eq) goto loc_8214D09C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214D09C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8214D09C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8214d07c
	if (!cr0.eq) goto loc_8214D07C;
loc_8214D0A8:
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

PPC_WEAK_FUNC(sub_8214D050) {
	__imp__sub_8214D050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D0C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,9
	cr6.compare<uint32_t>(ctx.r4.u32, 9, xer);
	// bge cr6,0x8214d0d8
	if (!cr6.lt) goto loc_8214D0D8;
	// addi r11,r4,25
	r11.s64 = ctx.r4.s64 + 25;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
loc_8214D0D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D0C0) {
	__imp__sub_8214D0C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D0E0) {
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
	ctx.lr = 0x8214D0E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8214d210
	if (cr6.eq) goto loc_8214D210;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// addi r3,r31,136
	ctx.r3.s64 = r31.s64 + 136;
	// lbz r9,819(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 819);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8214d12c
	if (cr6.eq) goto loc_8214D12C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,17404
	ctx.r4.s64 = r11.s64 + 17404;
	// b 0x8214d130
	goto loc_8214D130;
loc_8214D12C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_8214D130:
	// bl 0x82162c68
	ctx.lr = 0x8214D134;
	sub_82162C68(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8214d15c
	if (!cr6.eq) goto loc_8214D15C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,17380
	ctx.r3.s64 = r11.s64 + 17380;
	// bl 0x82130000
	ctx.lr = 0x8214D154;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8214D15C:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r27,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r27.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// bl 0x82161cc0
	ctx.lr = 0x8214D17C;
	sub_82161CC0(ctx, base);
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8214D180:
	// lbz r11,1(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1);
	// li r29,3
	r29.s64 = 3;
	// stb r11,112(r30)
	PPC_STORE_U8(r30.u32 + 112, r11.u8);
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// stb r10,113(r30)
	PPC_STORE_U8(r30.u32 + 113, ctx.r10.u8);
loc_8214D194:
	// lbz r11,112(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 112);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d1dc
	if (cr6.eq) goto loc_8214D1DC;
	// li r31,0
	r31.s64 = 0;
loc_8214D1A8:
	// cmplwi cr6,r31,5
	cr6.compare<uint32_t>(r31.u32, 5, xer);
	// bge cr6,0x8214d1dc
	if (!cr6.lt) goto loc_8214D1DC;
	// addi r11,r31,3
	r11.s64 = r31.s64 + 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r10,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82161d10
	ctx.lr = 0x8214D1C4;
	sub_82161D10(ctx, base);
	// addi r9,r31,1
	ctx.r9.s64 = r31.s64 + 1;
	// lbz r8,112(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 112);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplw cr6,r5,r8
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, xer);
	// blt cr6,0x8214d1a8
	if (cr6.lt) goto loc_8214D1A8;
loc_8214D1DC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214D1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8214d194
	if (!cr0.eq) goto loc_8214D194;
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8214d180
	if (!cr6.eq) goto loc_8214D180;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82135fb0
	ctx.lr = 0x8214D210;
	sub_82135FB0(ctx, base);
loc_8214D210:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8214D0E0) {
	__imp__sub_8214D0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D218) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8214D220;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addi r24,r31,100
	r24.s64 = r31.s64 + 100;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8214D244:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8214d244
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214D244;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r23.u32);
	// mr r11,r23
	r11.u64 = r23.u64;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_8214D260:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r8,r1,140
	ctx.r8.s64 = ctx.r1.s64 + 140;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stfsx f31,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// blt cr6,0x8214d260
	if (cr6.lt) goto loc_8214D260;
	// li r11,8
	r11.s64 = 8;
	// li r30,1
	r30.s64 = 1;
	// li r25,5
	r25.s64 = 5;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stb r30,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r25,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r25.u8);
	// addi r29,r31,132
	r29.s64 = r31.s64 + 132;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r10,17520
	ctx.r4.s64 = ctx.r10.s64 + 17520;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D2B0;
	sub_8214D0E0(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r26,4
	r26.s64 = 4;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r26,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r26.u8);
	// addi r28,r31,128
	r28.s64 = r31.s64 + 128;
	// stb r30,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r30.u8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r8,17516
	ctx.r4.s64 = ctx.r8.s64 + 17516;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D2E4;
	sub_8214D0E0(ctx, base);
	// li r27,3
	r27.s64 = 3;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r27,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r27.u8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r27.u32);
	// addi r4,r7,17508
	ctx.r4.s64 = ctx.r7.s64 + 17508;
	// addi r5,r31,112
	ctx.r5.s64 = r31.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D30C;
	sub_8214D0E0(ctx, base);
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r28.u32);
	// stb r27,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r27.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r26,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r26.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r5,17504
	ctx.r4.s64 = ctx.r5.s64 + 17504;
	// addi r5,r31,116
	ctx.r5.s64 = r31.s64 + 116;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D330;
	sub_8214D0E0(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r28.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r4,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// addi r5,r31,124
	ctx.r5.s64 = r31.s64 + 124;
	// stb r27,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r27.u8);
	// addi r4,r3,17492
	ctx.r4.s64 = ctx.r3.s64 + 17492;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D358;
	sub_8214D0E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r9,124(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// li r28,2
	r28.s64 = 2;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r28,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r28.u8);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r25.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r11,r23
	r11.u64 = r23.u64;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stb r28,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r28.u8);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
loc_8214D3A0:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r7,r1,140
	ctx.r7.s64 = ctx.r1.s64 + 140;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// lfsx f0,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stfsx f0,r9,r7
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, temp.u32);
	// blt cr6,0x8214d3a0
	if (cr6.lt) goto loc_8214D3A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,120
	r29.s64 = r31.s64 + 120;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,17476
	ctx.r4.s64 = r11.s64 + 17476;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D3E0;
	sub_8214D0E0(ctx, base);
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8214D3E4:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r8,r1,140
	ctx.r8.s64 = ctx.r1.s64 + 140;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stfsx f31,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// blt cr6,0x8214d3e4
	if (cr6.lt) goto loc_8214D3E4;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r30.u8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r23,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r23.u32);
	// addi r4,r11,17456
	ctx.r4.s64 = r11.s64 + 17456;
	// stb r30,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r30.u8);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D428;
	sub_8214D0E0(ctx, base);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// stb r30,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r10,17432
	ctx.r4.s64 = ctx.r10.s64 + 17432;
	// addi r5,r31,104
	ctx.r5.s64 = r31.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D44C;
	sub_8214D0E0(ctx, base);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// stb r30,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r30.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r28.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r9,17412
	ctx.r4.s64 = ctx.r9.s64 + 17412;
	// addi r5,r31,108
	ctx.r5.s64 = r31.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D470;
	sub_8214D0E0(ctx, base);
	// mr r11,r23
	r11.u64 = r23.u64;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_8214D478:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8214d4a4
	if (cr6.eq) goto loc_8214D4A4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// blt cr6,0x8214d478
	if (cr6.lt) goto loc_8214D478;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8214D4A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_8214D218) {
	__imp__sub_8214D218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D4B4) {
	__imp__sub_8214D4B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D4B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8214D4D0:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stfsx f0,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// blt cr6,0x8214d4d0
	if (cr6.lt) goto loc_8214D4D0;
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stb r10,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// beq cr6,0x8214d544
	if (cr6.eq) goto loc_8214D544;
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// beq cr6,0x8214d53c
	if (cr6.eq) goto loc_8214D53C;
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r7,104(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lwz r6,108(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// stb r8,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r8.u8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// b 0x8214d550
	goto loc_8214D550;
loc_8214D53C:
	// addi r10,r3,116
	ctx.r10.s64 = ctx.r3.s64 + 116;
	// b 0x8214d548
	goto loc_8214D548;
loc_8214D544:
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
loc_8214D548:
	// li r11,1
	r11.s64 = 1;
	// stb r11,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r11.u8);
loc_8214D550:
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D55C;
	sub_8214D0E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D4B8) {
	__imp__sub_8214D4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D56C) {
	__imp__sub_8214D56C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D570) {
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
	// addi r3,r31,136
	ctx.r3.s64 = r31.s64 + 136;
	// bl 0x82162a10
	ctx.lr = 0x8214D58C;
	sub_82162A10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214d5b0
	if (!cr6.eq) goto loc_8214D5B0;
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
loc_8214D5B0:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,24
	ctx.r10.s64 = 24;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8214D5C0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8214d5c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214D5C0;
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d218
	ctx.lr = 0x8214D5D8;
	sub_8214D218(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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

PPC_WEAK_FUNC(sub_8214D570) {
	__imp__sub_8214D570(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D5FC) {
	__imp__sub_8214D5FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D600) {
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
	ctx.lr = 0x8214D608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8214d628
	if (!cr6.eq) goto loc_8214D628;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214D628:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D638;
	sub_821BE250(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214D658;
	sub_82144A60(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214d670
	if (cr6.eq) goto loc_8214D670;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x8214D670;
	sub_823DA950(ctx, base);
loc_8214D670:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D684;
	sub_821BE250(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x8214d6a8
	if (cr6.eq) goto loc_8214D6A8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214D6A8;
	sub_82144A78(ctx, base);
loc_8214D6A8:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8214D600) {
	__imp__sub_8214D600(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D6B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwz r9,60(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 60);
	// bne cr6,0x8214d6d4
	if (!cr6.eq) goto loc_8214D6D4;
	// blr 
	return;
loc_8214D6D4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r7,64(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
loc_8214D6E0:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x8214d708
	if (!cr6.gt) goto loc_8214D708;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8214d710
	goto loc_8214D710;
loc_8214D708:
	// bge cr6,0x8214d71c
	if (!cr6.lt) goto loc_8214D71C;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8214D710:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8214d6e0
	if (!cr6.gt) goto loc_8214D6E0;
	// blr 
	return;
loc_8214D71C:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwzx r11,r11,r7
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D6B8) {
	__imp__sub_8214D6B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D730) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r7,60(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8214d824
	if (cr6.eq) goto loc_8214D824;
	// li r4,13
	ctx.r4.s64 = 13;
loc_8214D748:
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r7,r10,r4
	ctx.r7.u32 = ctx.r10.u32 / ctx.r4.u32;
	// cmplwi cr6,r7,9
	cr6.compare<uint32_t>(ctx.r7.u32, 9, xer);
	// beq cr6,0x8214d768
	if (cr6.eq) goto loc_8214D768;
	// cmplwi cr6,r7,10
	cr6.compare<uint32_t>(ctx.r7.u32, 10, xer);
	// bne cr6,0x8214d770
	if (!cr6.eq) goto loc_8214D770;
loc_8214D768:
	// li r7,11
	ctx.r7.s64 = 11;
	// b 0x8214d77c
	goto loc_8214D77C;
loc_8214D770:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bge cr6,0x8214d77c
	if (!cr6.lt) goto loc_8214D77C;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8214D77C:
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf. r10,r7,r11
	ctx.r10.s64 = r11.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8214d810
	if (cr0.eq) goto loc_8214D810;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
loc_8214D798:
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x8214d7f4
	if (!cr6.gt) goto loc_8214D7F4;
	// lwz r8,64(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r31,r11,r8
	r31.u64 = r11.u64 + ctx.r8.u64;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r8,r10,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,4(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// lwzx r31,r11,r9
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r8.u32);
loc_8214D7F4:
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// subf r8,r7,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// blt cr6,0x8214d798
	if (cr6.lt) goto loc_8214D798;
loc_8214D810:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bne cr6,0x8214d748
	if (!cr6.eq) goto loc_8214D748;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214d748
	if (!cr6.eq) goto loc_8214D748;
loc_8214D824:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D730) {
	__imp__sub_8214D730(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8214d840
	if (!cr6.eq) goto loc_8214D840;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8214D840:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D830) {
	__imp__sub_8214D830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D84C) {
	__imp__sub_8214D84C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D850) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r3,r4,16
	ctx.r3.u64 = ctx.r4.u32 & 0xFFFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D850) {
	__imp__sub_8214D850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D858) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8214d86c
	if (cr6.lt) goto loc_8214D86C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8214D86C:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D858) {
	__imp__sub_8214D858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D87C) {
	__imp__sub_8214D87C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D880) {
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
	ctx.lr = 0x8214D888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8214d8dc
	if (!cr6.gt) goto loc_8214D8DC;
	// li r31,0
	r31.s64 = 0;
loc_8214D8A8:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x8214D8BC;
	sub_821C9790(ctx, base);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x8214d8e8
	if (cr6.eq) goto loc_8214D8E8;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// clrlwi r29,r11,16
	r29.u64 = r11.u32 & 0xFFFF;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214d8a8
	if (cr6.lt) goto loc_8214D8A8;
loc_8214D8DC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214D8E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8214D880) {
	__imp__sub_8214D880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214D8F4) {
	__imp__sub_8214D8F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D8F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,68(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d928
	if (cr6.eq) goto loc_8214D928;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8214d91c
	if (cr6.lt) goto loc_8214D91C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,13684
	ctx.r3.s64 = r11.s64 + 13684;
	// blr 
	return;
loc_8214D91C:
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
loc_8214D928:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214D8F8) {
	__imp__sub_8214D8F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214D930) {
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
	ctx.lr = 0x8214D938;
	// addi r31,r1,-480
	r31.s64 = ctx.r1.s64 + -480;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r20,0
	r20.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stb r20,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r20.u8);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// mr r27,r20
	r27.u64 = r20.u64;
	// mr r22,r20
	r22.u64 = r20.u64;
	// mr r21,r20
	r21.u64 = r20.u64;
	// mr r23,r20
	r23.u64 = r20.u64;
	// mr r28,r20
	r28.u64 = r20.u64;
	// bne cr6,0x8214d978
	if (!cr6.eq) goto loc_8214D978;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,480
	ctx.r1.s64 = r31.s64 + 480;
	// b 0x823d9228
	return;
loc_8214D978:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D988;
	sub_821BE250(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D998;
	sub_821BE250(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// lbz r11,68(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d9f4
	if (cr6.eq) goto loc_8214D9F4;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// li r5,16
	ctx.r5.s64 = 16;
	// add r21,r11,r10
	r21.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214D9C8;
	sub_82144A60(ctx, base);
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214d9f4
	if (cr6.eq) goto loc_8214D9F4;
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x823da950
	ctx.lr = 0x8214D9E0;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r22,44(r30)
	r22.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x82144a78
	ctx.lr = 0x8214D9F0;
	sub_82144A78(ctx, base);
	// stw r20,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r20.u32);
loc_8214D9F4:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// li r5,16
	ctx.r5.s64 = 16;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82144a60
	ctx.lr = 0x8214DA10;
	sub_82144A60(ctx, base);
	// lwz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214da44
	if (cr6.eq) goto loc_8214DA44;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823da950
	ctx.lr = 0x8214DA2C;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// lwz r27,60(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// bl 0x82144a78
	ctx.lr = 0x8214DA3C;
	sub_82144A78(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// stw r20,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r20.u32);
loc_8214DA44:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214db94
	if (cr6.eq) goto loc_8214DB94;
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r25,r28,24
	r25.u64 = r28.u32 & 0xFF;
	// add r28,r11,r26
	r28.u64 = r11.u64 + r26.u64;
loc_8214DA60:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DA70;
	sub_821BE250(ctx, base);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lbz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// bl 0x821be250
	ctx.lr = 0x8214DA80;
	sub_821BE250(ctx, base);
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// lbz r8,68(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stbx r20,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, r20.u8);
	// beq cr6,0x8214dab4
	if (cr6.eq) goto loc_8214DAB4;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// add r3,r23,r22
	ctx.r3.u64 = r23.u64 + r22.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DAA8;
	sub_823DA950(ctx, base);
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_8214DAB4:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DAC4;
	sub_821BE250(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x821c9790
	ctx.lr = 0x8214DAD0;
	sub_821C9790(ctx, base);
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8214db24
	if (cr6.eq) goto loc_8214DB24;
	// mr r11,r20
	r11.u64 = r20.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8214db24
	if (cr6.eq) goto loc_8214DB24;
	// addi r10,r26,4
	ctx.r10.s64 = r26.s64 + 4;
loc_8214DAEC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8214db0c
	if (cr6.eq) goto loc_8214DB0C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8214daec
	if (cr6.lt) goto loc_8214DAEC;
	// b 0x8214db24
	goto loc_8214DB24;
loc_8214DB0C:
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r9,1
	ctx.r9.s64 = 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stwx r7,r8,r26
	PPC_STORE_U32(ctx.r8.u32 + r26.u32, ctx.r7.u32);
loc_8214DB24:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214db4c
	if (!cr6.eq) goto loc_8214DB4C;
	// stw r3,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r3.u32);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
loc_8214DB4C:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,5
	ctx.r10.s64 = r11.s64 + 5;
	// lwz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 5);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,5(r11)
	PPC_STORE_U32(r11.u32 + 5, ctx.r10.u32);
	// bl 0x821be250
	ctx.lr = 0x8214DB84;
	sub_821BE250(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214da60
	if (cr6.lt) goto loc_8214DA60;
loc_8214DB94:
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r26.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r21,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r21.u32);
	// stw r23,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r23.u32);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// bl 0x8214d730
	ctx.lr = 0x8214DBB4;
	sub_8214D730(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DBC4;
	sub_821BE250(ctx, base);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r25,r20
	r25.u64 = r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214dc34
	if (cr6.eq) goto loc_8214DC34;
	// li r26,-1
	r26.s64 = -1;
loc_8214DBD8:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DBE8;
	sub_821BE250(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r10,-8
	r29.s64 = ctx.r10.s64 + -8;
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r28,r11,r27
	r28.u64 = r11.u64 + r27.u64;
	// lwzx r4,r28,r29
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// bl 0x8214d6b8
	ctx.lr = 0x8214DC0C;
	sub_8214D6B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8214dc1c
	if (!cr6.eq) goto loc_8214DC1C;
	// stwx r26,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r26.u32);
	// b 0x8214dc24
	goto loc_8214DC24;
loc_8214DC1C:
	// subf r11,r27,r3
	r11.s64 = ctx.r3.s64 - r27.s64;
	// stwx r11,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r11.u32);
loc_8214DC24:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x8214dbd8
	if (cr6.lt) goto loc_8214DBD8;
loc_8214DC34:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8214DC48;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r28,r20
	r28.u64 = r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x8214dc8c
	if (cr6.eq) goto loc_8214DC8C;
	// mr r29,r20
	r29.u64 = r20.u64;
loc_8214DC64:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x8214DC74;
	sub_821C9790(ctx, base);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r3,r29,r27
	PPC_STORE_U32(r29.u32 + r27.u32, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214dc64
	if (cr6.lt) goto loc_8214DC64;
loc_8214DC8C:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DC9C;
	sub_821BE250(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214dd30
	if (cr6.eq) goto loc_8214DD30;
loc_8214DCAC:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DCBC;
	sub_821BE250(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r8,r11,-8
	ctx.r8.s64 = r11.s64 + -8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r8,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r8.u32);
	// ble cr6,0x8214dd14
	if (!cr6.gt) goto loc_8214DD14;
	// lwzx r9,r7,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// mr r11,r20
	r11.u64 = r20.u64;
loc_8214DCEC:
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r27.u32);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// beq cr6,0x8214dd18
	if (cr6.eq) goto loc_8214DD18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x8214dcec
	if (cr6.lt) goto loc_8214DCEC;
loc_8214DD14:
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8214DD18:
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214dcac
	if (cr6.lt) goto loc_8214DCAC;
loc_8214DD30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,480
	ctx.r1.s64 = r31.s64 + 480;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8214D930) {
	__imp__sub_8214D930(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214DD3C) {
	__imp__sub_8214DD3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DD40) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8214DD60;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d6b8
	ctx.lr = 0x8214DD6C;
	sub_8214D6B8(ctx, base);
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

PPC_WEAK_FUNC(sub_8214DD40) {
	__imp__sub_8214DD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DD80) {
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
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82608de8
	ctx.lr = 0x8214DDA0;
	sub_82608DE8(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// beq cr6,0x8214ddbc
	if (cr6.eq) goto loc_8214DDBC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDBC;
	sub_82144A78(ctx, base);
loc_8214DDBC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214ddd0
	if (cr6.eq) goto loc_8214DDD0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDD0;
	sub_82144A78(ctx, base);
loc_8214DDD0:
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214dde4
	if (cr6.eq) goto loc_8214DDE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDE4;
	sub_82144A78(ctx, base);
loc_8214DDE4:
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214ddf8
	if (cr6.eq) goto loc_8214DDF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDF8;
	sub_82144A78(ctx, base);
loc_8214DDF8:
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

PPC_WEAK_FUNC(sub_8214DD80) {
	__imp__sub_8214DD80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DE10) {
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
	ctx.lr = 0x8214DE18;
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
	// bne cr6,0x8214de40
	if (!cr6.eq) goto loc_8214DE40;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x8214DE40;
	sub_82608A98(ctx, base);
loc_8214DE40:
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
	// bne cr6,0x8214de70
	if (!cr6.eq) goto loc_8214DE70;
	// bl 0x821c9438
	ctx.lr = 0x8214DE64;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821bed68
	ctx.lr = 0x8214DE70;
	sub_821BED68(ctx, base);
loc_8214DE70:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x8214DE78;
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
	ctx.lr = 0x8214DEA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214dec8
	if (cr6.eq) goto loc_8214DEC8;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lhz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// sth r9,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r9.u16);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x8214decc
	goto loc_8214DECC;
loc_8214DEC8:
	// li r11,0
	r11.s64 = 0;
loc_8214DECC:
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

PPC_WEAK_FUNC(sub_8214DE10) {
	__imp__sub_8214DE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214DEE4) {
	__imp__sub_8214DEE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DEE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// sth r11,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r11.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,27(r3)
	PPC_STORE_U8(ctx.r3.u32 + 27, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8214DEE8) {
	__imp__sub_8214DEE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DF00) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82608de8
	sub_82608DE8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214DF00) {
	__imp__sub_8214DF00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214DF08) {
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
	ctx.lr = 0x8214DF10;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	r22.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// add r4,r21,r11
	ctx.r4.u64 = r21.u64 + r11.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214DF44;
	sub_82144A60(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DF58;
	sub_821BE250(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214e108
	if (cr6.eq) goto loc_8214E108;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r30,r10,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// subf r27,r30,r9
	r27.s64 = ctx.r9.s64 - r30.s64;
	// add r24,r11,r26
	r24.u64 = r11.u64 + r26.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DF90;
	sub_823DA950(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DFA4;
	sub_823DA950(ctx, base);
	// addi r23,r31,16
	r23.s64 = r31.s64 + 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82608de8
	ctx.lr = 0x8214DFB0;
	sub_82608DE8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82144a78
	ctx.lr = 0x8214DFBC;
	sub_82144A78(ctx, base);
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r30,r26
	ctx.r4.u64 = r30.u64 + r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DFD0;
	sub_821BE250(ctx, base);
	// add r11,r27,r29
	r11.u64 = r27.u64 + r29.u64;
	// subf r5,r29,r21
	ctx.r5.s64 = r21.s64 - r29.s64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r26
	ctx.r4.u64 = r11.u64 + r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DFE8;
	sub_821BE250(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r11,r22
	r11.u64 = r22.u64;
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ble cr6,0x8214e030
	if (!cr6.gt) goto loc_8214E030;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_8214E000:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r6,r8,r24
	ctx.r6.u64 = ctx.r8.u64 + r24.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x8214e000
	if (cr6.lt) goto loc_8214E000;
loc_8214E030:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8214e07c
	if (!cr6.lt) goto loc_8214E07C;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8214E04C:
	// lwzx r9,r11,r7
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 + r24.u64;
	// add r6,r9,r27
	ctx.r6.u64 = ctx.r9.u64 + r27.u64;
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// blt cr6,0x8214e04c
	if (cr6.lt) goto loc_8214E04C;
loc_8214E07C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r29,r22
	r29.u64 = r22.u64;
	// add. r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8214e0dc
	if (cr0.eq) goto loc_8214E0DC;
	// mr r30,r22
	r30.u64 = r22.u64;
loc_8214E090:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x825edac0
	ctx.lr = 0x8214E0A0;
	sub_825EDAC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8214e0c0
	if (!cr6.eq) goto loc_8214E0C0;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x8214de10
	ctx.lr = 0x8214E0C0;
	sub_8214DE10(ctx, base);
loc_8214E0C0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214e090
	if (cr6.lt) goto loc_8214E090;
loc_8214E0DC:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r24,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r24.u32);
	// add r9,r21,r11
	ctx.r9.u64 = r21.u64 + r11.u64;
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_8214E108:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E118;
	sub_821BE250(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,28(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r11,r29,r10
	r11.u64 = r29.u64 + ctx.r10.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// add r11,r9,r26
	r11.u64 = ctx.r9.u64 + r26.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// bge cr6,0x8214e184
	if (!cr6.lt) goto loc_8214E184;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
loc_8214E144:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// bl 0x8214de10
	ctx.lr = 0x8214E168;
	sub_8214DE10(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// blt cr6,0x8214e144
	if (cr6.lt) goto loc_8214E144;
loc_8214E184:
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r21,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r21.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8214DF08) {
	__imp__sub_8214DF08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E1A0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8214e1cc
	if (!cr6.eq) goto loc_8214E1CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214e1f4
	goto loc_8214E1F4;
loc_8214E1CC:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E1DC;
	sub_821BE250(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r11,-4
	ctx.r5.s64 = r11.s64 + -4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x8214df08
	ctx.lr = 0x8214E1F4;
	sub_8214DF08(ctx, base);
loc_8214E1F4:
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

PPC_WEAK_FUNC(sub_8214E1A0) {
	__imp__sub_8214E1A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214E20C) {
	__imp__sub_8214E20C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E210) {
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
	ctx.lr = 0x8214E218;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r29,r10,3998
	r29.s64 = ctx.r10.s64 + 3998;
	// lwz r6,56(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// beq cr6,0x8214e274
	if (cr6.eq) goto loc_8214E274;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,17852
	ctx.r4.s64 = r11.s64 + 17852;
	// bl 0x823dc018
	ctx.lr = 0x8214E254;
	sub_823DC018(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821ca778
	ctx.lr = 0x8214E264;
	sub_821CA778(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214e280
	if (!cr6.eq) goto loc_8214E280;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
loc_8214E274:
	// li r5,255
	ctx.r5.s64 = 255;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823db670
	ctx.lr = 0x8214E280;
	sub_823DB670(ctx, base);
loc_8214E280:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821ca6a8
	ctx.lr = 0x8214E298;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8214e2b0
	if (!cr6.eq) goto loc_8214E2B0;
loc_8214E2A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
loc_8214E2B0:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E2C0;
	sub_821BE250(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214d600
	ctx.lr = 0x8214E2CC;
	sub_8214D600(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e1a0
	ctx.lr = 0x8214E2E4;
	sub_8214E1A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214d930
	ctx.lr = 0x8214E2FC;
	sub_8214D930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8214E310;
	sub_821BE610(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8214E210) {
	__imp__sub_8214E210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214E324) {
	__imp__sub_8214E324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r6,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r6.u32);
	// stb r5,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r5.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// b 0x8214e210
	sub_8214E210(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8214E328) {
	__imp__sub_8214E328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214E368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8214E368) {
	__imp__sub_8214E368(ctx, base);
}

