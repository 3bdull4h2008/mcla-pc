#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822D41C8"))) PPC_WEAK_FUNC(sub_822D41C8);
PPC_FUNC_IMPL(__imp__sub_822D41C8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-15244
	ctx.r10.s64 = r11.s64 + -15244;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822d2bb8
	ctx.lr = 0x822D41F4;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d420c
	if (cr6.eq) goto loc_822D420C;
	// bl 0x82130588
	ctx.lr = 0x822D4208;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D420C:
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

__attribute__((alias("__imp__sub_822D4224"))) PPC_WEAK_FUNC(sub_822D4224);
PPC_FUNC_IMPL(__imp__sub_822D4224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4228"))) PPC_WEAK_FUNC(sub_822D4228);
PPC_FUNC_IMPL(__imp__sub_822D4228) {
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
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x822D423C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4258
	if (cr6.eq) goto loc_822D4258;
	// bl 0x822d3f40
	ctx.lr = 0x822D4248;
	sub_822D3F40(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D4258:
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

__attribute__((alias("__imp__sub_822D426C"))) PPC_WEAK_FUNC(sub_822D426C);
PPC_FUNC_IMPL(__imp__sub_822D426C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4270"))) PPC_WEAK_FUNC(sub_822D4270);
PPC_FUNC_IMPL(__imp__sub_822D4270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d3fb0
	sub_822D3FB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D427C"))) PPC_WEAK_FUNC(sub_822D427C);
PPC_FUNC_IMPL(__imp__sub_822D427C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4280"))) PPC_WEAK_FUNC(sub_822D4280);
PPC_FUNC_IMPL(__imp__sub_822D4280) {
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
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82130528
	ctx.lr = 0x822D4294;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d42b0
	if (cr6.eq) goto loc_822D42B0;
	// bl 0x822d4018
	ctx.lr = 0x822D42A0;
	sub_822D4018(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D42B0:
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

__attribute__((alias("__imp__sub_822D42C4"))) PPC_WEAK_FUNC(sub_822D42C4);
PPC_FUNC_IMPL(__imp__sub_822D42C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D42C8"))) PPC_WEAK_FUNC(sub_822D42C8);
PPC_FUNC_IMPL(__imp__sub_822D42C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d4088
	sub_822D4088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D42D4"))) PPC_WEAK_FUNC(sub_822D42D4);
PPC_FUNC_IMPL(__imp__sub_822D42D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D42D8"))) PPC_WEAK_FUNC(sub_822D42D8);
PPC_FUNC_IMPL(__imp__sub_822D42D8) {
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
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x822D42EC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4308
	if (cr6.eq) goto loc_822D4308;
	// bl 0x822d40f0
	ctx.lr = 0x822D42F8;
	sub_822D40F0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D4308:
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

__attribute__((alias("__imp__sub_822D431C"))) PPC_WEAK_FUNC(sub_822D431C);
PPC_FUNC_IMPL(__imp__sub_822D431C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4320"))) PPC_WEAK_FUNC(sub_822D4320);
PPC_FUNC_IMPL(__imp__sub_822D4320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d4160
	sub_822D4160(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D432C"))) PPC_WEAK_FUNC(sub_822D432C);
PPC_FUNC_IMPL(__imp__sub_822D432C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4330"))) PPC_WEAK_FUNC(sub_822D4330);
PPC_FUNC_IMPL(__imp__sub_822D4330) {
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
	ctx.lr = 0x822D4338;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4364
	if (cr6.eq) goto loc_822D4364;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D4364:
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r30,-7784(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -7784);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4384
	if (cr6.eq) goto loc_822D4384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebd20
	ctx.lr = 0x822D437C;
	sub_822EBD20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4384;
	sub_82130588(ctx, base);
loc_822D4384:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7784(r31)
	PPC_STORE_U32(r31.u32 + -7784, r11.u32);
	// bl 0x826c2578
	ctx.lr = 0x822D4390;
	sub_826C2578(ctx, base);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r3,-24400(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24400);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d43b4
	if (cr6.eq) goto loc_822D43B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D43B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D43B4:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24400(r30)
	PPC_STORE_U32(r30.u32 + -24400, r11.u32);
	// lwz r3,-12012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d43e0
	if (cr6.eq) goto loc_822D43E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D43E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D43E0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12012(r31)
	PPC_STORE_U32(r31.u32 + -12012, r11.u32);
	// bl 0x8272d2d8
	ctx.lr = 0x822D43EC;
	sub_8272D2D8(ctx, base);
	// bl 0x82365218
	ctx.lr = 0x822D43F0;
	sub_82365218(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-10432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4414
	if (cr6.eq) goto loc_822D4414;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D4414:
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10432(r31)
	PPC_STORE_U32(r31.u32 + -10432, r11.u32);
	// lwz r31,-8256(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d443c
	if (cr6.eq) goto loc_822D443C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8236e6a0
	ctx.lr = 0x822D4434;
	sub_8236E6A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D443C;
	sub_82130588(ctx, base);
loc_822D443C:
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-8256(r30)
	PPC_STORE_U32(r30.u32 + -8256, r11.u32);
	// lwz r30,-8252(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -8252);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4464
	if (cr6.eq) goto loc_822D4464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82371200
	ctx.lr = 0x822D445C;
	sub_82371200(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4464;
	sub_82130588(ctx, base);
loc_822D4464:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-8252(r31)
	PPC_STORE_U32(r31.u32 + -8252, r11.u32);
	// bl 0x8239d968
	ctx.lr = 0x822D4470;
	sub_8239D968(ctx, base);
	// bl 0x821d3278
	ctx.lr = 0x822D4474;
	sub_821D3278(ctx, base);
	// bl 0x821bd520
	ctx.lr = 0x822D4478;
	sub_821BD520(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r30,-9996(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -9996);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4498
	if (cr6.eq) goto loc_822D4498;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827285d8
	ctx.lr = 0x822D4490;
	sub_827285D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4498;
	sub_82130588(ctx, base);
loc_822D4498:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-9996(r31)
	PPC_STORE_U32(r31.u32 + -9996, r11.u32);
	// lwz r31,20(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d44bc
	if (cr6.eq) goto loc_822D44BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827275c8
	ctx.lr = 0x822D44B4;
	sub_827275C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D44BC;
	sub_82130588(ctx, base);
loc_822D44BC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// bl 0x8246a7b8
	ctx.lr = 0x822D44C8;
	sub_8246A7B8(ctx, base);
	// bl 0x82469ad8
	ctx.lr = 0x822D44CC;
	sub_82469AD8(ctx, base);
	// bl 0x82507860
	ctx.lr = 0x822D44D0;
	sub_82507860(ctx, base);
	// bl 0x82195a00
	ctx.lr = 0x822D44D4;
	sub_82195A00(ctx, base);
	// bl 0x825032f8
	ctx.lr = 0x822D44D8;
	sub_825032F8(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r31,-27428(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d44f8
	if (cr6.eq) goto loc_822D44F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82490a88
	ctx.lr = 0x822D44F0;
	sub_82490A88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D44F8;
	sub_82130588(ctx, base);
loc_822D44F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27428(r30)
	PPC_STORE_U32(r30.u32 + -27428, r11.u32);
	// bl 0x8239c920
	ctx.lr = 0x822D4504;
	sub_8239C920(ctx, base);
	// bl 0x821e6a68
	ctx.lr = 0x822D4508;
	sub_821E6A68(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x822D450C;
	sub_82130000(ctx, base);
	// bl 0x82465550
	ctx.lr = 0x822D4510;
	sub_82465550(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D4518"))) PPC_WEAK_FUNC(sub_822D4518);
PPC_FUNC_IMPL(__imp__sub_822D4518) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,16000
	ctx.r5.s64 = r11.s64 + 16000;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4548;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,16112
	ctx.r5.s64 = ctx.r5.s64 + 16112;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4598;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D45DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822D45F0"))) PPC_WEAK_FUNC(sub_822D45F0);
PPC_FUNC_IMPL(__imp__sub_822D45F0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,16936
	ctx.r5.s64 = r11.s64 + 16936;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4620;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17008
	ctx.r5.s64 = ctx.r5.s64 + 17008;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4670;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D46B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822D46C8"))) PPC_WEAK_FUNC(sub_822D46C8);
PPC_FUNC_IMPL(__imp__sub_822D46C8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,17024
	ctx.r5.s64 = r11.s64 + 17024;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D46F8;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17096
	ctx.r5.s64 = ctx.r5.s64 + 17096;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4748;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D478C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822D47A0"))) PPC_WEAK_FUNC(sub_822D47A0);
PPC_FUNC_IMPL(__imp__sub_822D47A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,17112
	ctx.r5.s64 = r11.s64 + 17112;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D47D0;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17184
	ctx.r5.s64 = ctx.r5.s64 + 17184;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4820;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D4864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822D4878"))) PPC_WEAK_FUNC(sub_822D4878);
PPC_FUNC_IMPL(__imp__sub_822D4878) {
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
	ctx.lr = 0x822D4880;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_822D4888:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d4888
	if (cr6.eq) goto loc_822D4888;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// addi r3,r10,2192
	ctx.r3.s64 = ctx.r10.s64 + 2192;
	// bl 0x821ce210
	ctx.lr = 0x822D48A8;
	sub_821CE210(ctx, base);
loc_822D48A8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d48a8
	if (cr6.eq) goto loc_822D48A8;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// addi r3,r10,2176
	ctx.r3.s64 = ctx.r10.s64 + 2176;
	// bl 0x821ce210
	ctx.lr = 0x822D48C8;
	sub_821CE210(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82465138
	ctx.lr = 0x822D48D0;
	sub_82465138(ctx, base);
	// bl 0x82465128
	ctx.lr = 0x822D48D4;
	sub_82465128(ctx, base);
	// bl 0x82465140
	ctx.lr = 0x822D48D8;
	sub_82465140(ctx, base);
	// bl 0x82388340
	ctx.lr = 0x822D48DC;
	sub_82388340(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D48E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823971d0
	ctx.lr = 0x822D48EC;
	sub_823971D0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822d48e4
	if (cr6.lt) goto loc_822D48E4;
	// bl 0x8239c6f0
	ctx.lr = 0x822D48FC;
	sub_8239C6F0(ctx, base);
	// bl 0x8238a878
	ctx.lr = 0x822D4900;
	sub_8238A878(ctx, base);
	// bl 0x82397d60
	ctx.lr = 0x822D4904;
	sub_82397D60(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x822D4908;
	sub_82387B90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8238ce30
	ctx.lr = 0x822D4910;
	sub_8238CE30(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x822D4914;
	sub_82387B90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8238ba38
	ctx.lr = 0x822D491C;
	sub_8238BA38(ctx, base);
	// bl 0x82388540
	ctx.lr = 0x822D4920;
	sub_82388540(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822D4928;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d493c
	if (cr6.eq) goto loc_822D493C;
	// bl 0x82490990
	ctx.lr = 0x822D4938;
	sub_82490990(ctx, base);
	// b 0x822d4940
	goto loc_822D4940;
loc_822D493C:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_822D4940:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r3,100
	ctx.r3.s64 = 100;
	// addi r30,r11,-27428
	r30.s64 = r11.s64 + -27428;
	// stw r29,-27428(r11)
	PPC_STORE_U32(r11.u32 + -27428, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x822D4954;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4980
	if (cr6.eq) goto loc_822D4980;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15124
	ctx.r10.s64 = r11.s64 + -15124;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4984
	goto loc_822D4984;
loc_822D4980:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4984:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d4518
	ctx.lr = 0x822D498C;
	sub_822D4518(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,-14964
	r28.s64 = r11.s64 + -14964;
	// addi r5,r10,-14976
	ctx.r5.s64 = ctx.r10.s64 + -14976;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D49AC;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D49B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d49e4
	if (cr6.eq) goto loc_822D49E4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15096
	ctx.r10.s64 = r11.s64 + -15096;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d49e8
	goto loc_822D49E8;
loc_822D49E4:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D49E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d45f0
	ctx.lr = 0x822D49F0;
	sub_822D45F0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-14992
	ctx.r5.s64 = r11.s64 + -14992;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4A08;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D4A14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4a40
	if (cr6.eq) goto loc_822D4A40;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15068
	ctx.r10.s64 = r11.s64 + -15068;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4a44
	goto loc_822D4A44;
loc_822D4A40:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4A44:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d46c8
	ctx.lr = 0x822D4A4C;
	sub_822D46C8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-15004
	ctx.r5.s64 = r11.s64 + -15004;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4A64;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D4A70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4a9c
	if (cr6.eq) goto loc_822D4A9C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15040
	ctx.r10.s64 = r11.s64 + -15040;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4aa0
	goto loc_822D4AA0;
loc_822D4A9C:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4AA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d47a0
	ctx.lr = 0x822D4AA8;
	sub_822D47A0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-15016
	ctx.r5.s64 = r11.s64 + -15016;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4AC0;
	sub_82490A08(ctx, base);
	// bl 0x825032b8
	ctx.lr = 0x822D4AC4;
	sub_825032B8(ctx, base);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82195800
	ctx.lr = 0x822D4ACC;
	sub_82195800(ctx, base);
	// bl 0x82507820
	ctx.lr = 0x822D4AD0;
	sub_82507820(ctx, base);
	// bl 0x82469a98
	ctx.lr = 0x822D4AD4;
	sub_82469A98(ctx, base);
	// bl 0x8239edc0
	ctx.lr = 0x822D4AD8;
	sub_8239EDC0(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822D4AE0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4af0
	if (cr6.eq) goto loc_822D4AF0;
	// bl 0x827279a0
	ctx.lr = 0x822D4AEC;
	sub_827279A0(ctx, base);
	// b 0x822d4af4
	goto loc_822D4AF4;
loc_822D4AF0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_822D4AF4:
	// stw r3,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822D4B00;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d4b1c
	if (cr6.eq) goto loc_822D4B1C;
	// bl 0x82728608
	ctx.lr = 0x822D4B10;
	sub_82728608(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r31,-9996(r11)
	PPC_STORE_U32(r11.u32 + -9996, r31.u32);
	// b 0x822d4b28
	goto loc_822D4B28;
loc_822D4B1C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-9996(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9996, r11.u32);
loc_822D4B28:
	// bl 0x822ca238
	ctx.lr = 0x822D4B2C;
	sub_822CA238(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stb r27,-23664(r11)
	PPC_STORE_U8(r11.u32 + -23664, r27.u8);
	// bl 0x821d4090
	ctx.lr = 0x822D4B38;
	sub_821D4090(ctx, base);
	// bl 0x8239de80
	ctx.lr = 0x822D4B3C;
	sub_8239DE80(ctx, base);
	// bl 0x8236e388
	ctx.lr = 0x822D4B40;
	sub_8236E388(ctx, base);
	// bl 0x82371310
	ctx.lr = 0x822D4B44;
	sub_82371310(ctx, base);
	// lis r3,344
	ctx.r3.s64 = 22544384;
	// bl 0x821e7770
	ctx.lr = 0x822D4B4C;
	sub_821E7770(ctx, base);
	// bl 0x82328648
	ctx.lr = 0x822D4B50;
	sub_82328648(ctx, base);
	// bl 0x82365108
	ctx.lr = 0x822D4B54;
	sub_82365108(ctx, base);
	// bl 0x8272da30
	ctx.lr = 0x822D4B58;
	sub_8272DA30(ctx, base);
	// bl 0x821f2b08
	ctx.lr = 0x822D4B5C;
	sub_821F2B08(ctx, base);
	// bl 0x826ff8c0
	ctx.lr = 0x822D4B60;
	sub_826FF8C0(ctx, base);
	// bl 0x826c2d88
	ctx.lr = 0x822D4B64;
	sub_826C2D88(ctx, base);
	// bl 0x822ec338
	ctx.lr = 0x822D4B68;
	sub_822EC338(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8226f530
	ctx.lr = 0x822D4B70;
	sub_8226F530(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D4B78"))) PPC_WEAK_FUNC(sub_822D4B78);
PPC_FUNC_IMPL(__imp__sub_822D4B78) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// bl 0x82588078
	ctx.lr = 0x822D4BB4;
	sub_82588078(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// beq cr6,0x822d4bf0
	if (cr6.eq) goto loc_822D4BF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// blt cr6,0x822d4bf0
	if (cr6.lt) goto loc_822D4BF0;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bgt cr6,0x822d4bf0
	if (cr6.gt) goto loc_822D4BF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f540
	ctx.lr = 0x822D4BF0;
	sub_8272F540(ctx, base);
loc_822D4BF0:
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

__attribute__((alias("__imp__sub_822D4C04"))) PPC_WEAK_FUNC(sub_822D4C04);
PPC_FUNC_IMPL(__imp__sub_822D4C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4C08"))) PPC_WEAK_FUNC(sub_822D4C08);
PPC_FUNC_IMPL(__imp__sub_822D4C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D4C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4C58"))) PPC_WEAK_FUNC(sub_822D4C58);
PPC_FUNC_IMPL(__imp__sub_822D4C58) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8229e680
	ctx.lr = 0x822D4C70;
	sub_8229E680(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,19320
	ctx.r5.s64 = r11.s64 + 19320;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4C8C;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r9,r10,19464
	ctx.r9.s64 = ctx.r10.s64 + 19464;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82587fe0
	ctx.lr = 0x822D4CA8;
	sub_82587FE0(ctx, base);
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

__attribute__((alias("__imp__sub_822D4CBC"))) PPC_WEAK_FUNC(sub_822D4CBC);
PPC_FUNC_IMPL(__imp__sub_822D4CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4CC0"))) PPC_WEAK_FUNC(sub_822D4CC0);
PPC_FUNC_IMPL(__imp__sub_822D4CC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r11,7
	r11.s64 = 7;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4CD8"))) PPC_WEAK_FUNC(sub_822D4CD8);
PPC_FUNC_IMPL(__imp__sub_822D4CD8) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r8,r9,-14352
	ctx.r8.s64 = ctx.r9.s64 + -14352;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D4D40:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822d4d40
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D4D40;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D4D68:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822d4d68
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D4D68;
	// stb r30,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r30.u8);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x822D4D80;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4d90
	if (cr6.eq) goto loc_822D4D90;
	// bl 0x824f5c00
	ctx.lr = 0x822D4D8C;
	sub_824F5C00(ctx, base);
	// b 0x822d4d94
	goto loc_822D4D94;
loc_822D4D90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822D4D94:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x822D4DA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4db0
	if (cr6.eq) goto loc_822D4DB0;
	// bl 0x824f5c00
	ctx.lr = 0x822D4DAC;
	sub_824F5C00(ctx, base);
	// b 0x822d4db4
	goto loc_822D4DB4;
loc_822D4DB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822D4DB4:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x822D4DC0;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d4de0
	if (cr6.eq) goto loc_822D4DE0;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x822d4de4
	goto loc_822D4DE4;
loc_822D4DE0:
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_822D4DE4:
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

__attribute__((alias("__imp__sub_822D4DFC"))) PPC_WEAK_FUNC(sub_822D4DFC);
PPC_FUNC_IMPL(__imp__sub_822D4DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4E00"))) PPC_WEAK_FUNC(sub_822D4E00);
PPC_FUNC_IMPL(__imp__sub_822D4E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D4E08;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x822D4E1C;
	sub_8226CE68(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x822d51d0
	if (cr6.gt) goto loc_822D51D0;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,20040
	r12.s64 = r12.s64 + 20040;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822D4E6C;
	case 1:
		goto loc_822D4ED0;
	case 2:
		goto loc_822D5020;
	case 3:
		goto loc_822D5050;
	case 4:
		goto loc_822D5070;
	case 5:
		goto loc_822D5070;
	case 6:
		goto loc_822D5080;
	case 7:
		goto loc_822D5108;
	case 8:
		goto loc_822D5178;
	default:
		__builtin_unreachable();
	}
	// lwz r17,20076(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20076);
	// lwz r17,20176(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20176);
	// lwz r17,20512(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20512);
	// lwz r17,20560(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20560);
	// lwz r17,20592(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20592);
	// lwz r17,20592(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20592);
	// lwz r17,20608(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20608);
	// lwz r17,20744(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20744);
	// lwz r17,20856(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20856);
loc_822D4E6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4E74;
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
	ctx.lr = 0x822D4E88;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r31,24
	r29.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x822D4E9C;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x822D4EC0;
	sub_824F6EA0(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D4ED0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x822d5010
	if (!cr6.eq) goto loc_822D5010;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,36
	ctx.r9.s64 = 36;
	// addi r8,r31,88
	ctx.r8.s64 = r31.s64 + 88;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d4fbc
	if (!cr6.eq) goto loc_822D4FBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4F14;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822D4F28;
	sub_82270170(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4F34;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822D4F44;
	sub_82270170(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r25,16(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r24,r31,20
	r24.s64 = r31.s64 + 20;
	// bl 0x824e7118
	ctx.lr = 0x822D4F5C;
	sub_824E7118(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x822D4F68;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r24,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r24.u32);
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// bl 0x824f7308
	ctx.lr = 0x822D4FAC;
	sub_824F7308(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D4FBC:
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r4,r7,-14348
	ctx.r4.s64 = ctx.r7.s64 + -14348;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r3,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r3.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f7468
	ctx.lr = 0x822D5000;
	sub_824F7468(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5010:
	// li r11,6
	r11.s64 = 6;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5020:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x822d5040
	if (cr6.eq) goto loc_822D5040;
	// li r11,6
	r11.s64 = 6;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822D5040:
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5050:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5070:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5080:
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822D5098:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822d5098
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D5098;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D50AC;
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
	ctx.lr = 0x822D50C0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r31,24
	r29.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x822D50D4;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x822D50F8;
	sub_824F6EA0(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5108:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822d51c8
	if (!cr6.eq) goto loc_822D51C8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,38
	ctx.r10.s64 = 38;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// ble cr6,0x822d51c8
	if (!cr6.gt) goto loc_822D51C8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r8,r31,20
	ctx.r8.s64 = r31.s64 + 20;
	// addi r7,r31,44
	ctx.r7.s64 = r31.s64 + 44;
	// li r6,38
	ctx.r6.s64 = 38;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x824f7578
	ctx.lr = 0x822D5158;
	sub_824F7578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r8,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5178:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822d51c8
	if (!cr6.eq) goto loc_822D51C8;
	// lis r11,12336
	r11.s64 = 808452096;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// ori r8,r11,12544
	ctx.r8.u64 = r11.u64 | 12544;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// beq cr6,0x822d51d8
	if (cr6.eq) goto loc_822D51D8;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D51BC:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x822d51bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D51BC;
loc_822D51C8:
	// li r11,11
	r11.s64 = 11;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822D51D0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D51D8:
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D51E8"))) PPC_WEAK_FUNC(sub_822D51E8);
PPC_FUNC_IMPL(__imp__sub_822D51E8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-14352
	ctx.r10.s64 = r11.s64 + -14352;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5220
	if (cr6.eq) goto loc_822D5220;
	// bl 0x82130588
	ctx.lr = 0x822D5220;
	sub_82130588(ctx, base);
loc_822D5220:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x822D5228;
	sub_82130588(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822D5230;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822D5238;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5250
	if (cr6.eq) goto loc_822D5250;
	// bl 0x82130588
	ctx.lr = 0x822D524C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D5250:
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

__attribute__((alias("__imp__sub_822D5268"))) PPC_WEAK_FUNC(sub_822D5268);
PPC_FUNC_IMPL(__imp__sub_822D5268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r3,-27384(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -27384);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D5274"))) PPC_WEAK_FUNC(sub_822D5274);
PPC_FUNC_IMPL(__imp__sub_822D5274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5278"))) PPC_WEAK_FUNC(sub_822D5278);
PPC_FUNC_IMPL(__imp__sub_822D5278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r8,r9,-14368
	ctx.r8.s64 = ctx.r9.s64 + -14368;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,29,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x4;
	// xori r4,r5,4
	ctx.r4.u64 = ctx.r5.u64 ^ 4;
	// lwzx r3,r4,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D52A0"))) PPC_WEAK_FUNC(sub_822D52A0);
PPC_FUNC_IMPL(__imp__sub_822D52A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// bl 0x822d6408
	ctx.lr = 0x822D52BC;
	sub_822D6408(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d52d4
	if (cr6.eq) goto loc_822D52D4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r11,-13576
	r31.s64 = r11.s64 + -13576;
	// b 0x822d52dc
	goto loc_822D52DC;
loc_822D52D4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r11,-13568
	r31.s64 = r11.s64 + -13568;
loc_822D52DC:
	// bl 0x822d63f8
	ctx.lr = 0x822D52E0;
	sub_822D63F8(ctx, base);
	// stfd f1,32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-14036
	ctx.r3.s64 = r11.s64 + -14036;
	// bl 0x82130000
	ctx.lr = 0x822D52F8;
	sub_82130000(ctx, base);
	// bl 0x822d63f8
	ctx.lr = 0x822D52FC;
	sub_822D63F8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822d5318
	if (cr6.gt) goto loc_822D5318;
	// bl 0x822d6408
	ctx.lr = 0x822D5308;
	sub_822D6408(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822d531c
	if (cr6.eq) goto loc_822D531C;
loc_822D5318:
	// li r11,1
	r11.s64 = 1;
loc_822D531C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_822D5338"))) PPC_WEAK_FUNC(sub_822D5338);
PPC_FUNC_IMPL(__imp__sub_822D5338) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d63f8
	sub_822D63F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D533C"))) PPC_WEAK_FUNC(sub_822D533C);
PPC_FUNC_IMPL(__imp__sub_822D533C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5340"))) PPC_WEAK_FUNC(sub_822D5340);
PPC_FUNC_IMPL(__imp__sub_822D5340) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d6310
	sub_822D6310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D5344"))) PPC_WEAK_FUNC(sub_822D5344);
PPC_FUNC_IMPL(__imp__sub_822D5344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5348"))) PPC_WEAK_FUNC(sub_822D5348);
PPC_FUNC_IMPL(__imp__sub_822D5348) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-14472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d53b0
	if (!cr6.eq) goto loc_822D53B0;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822D5370;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5394
	if (cr6.eq) goto loc_822D5394;
	// bl 0x822dadf0
	ctx.lr = 0x822D537C;
	sub_822DADF0(ctx, base);
	// stw r3,-14472(r31)
	PPC_STORE_U32(r31.u32 + -14472, ctx.r3.u32);
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
loc_822D5394:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-14472(r31)
	PPC_STORE_U32(r31.u32 + -14472, ctx.r3.u32);
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
loc_822D53B0:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
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

__attribute__((alias("__imp__sub_822D53D4"))) PPC_WEAK_FUNC(sub_822D53D4);
PPC_FUNC_IMPL(__imp__sub_822D53D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D53D8"))) PPC_WEAK_FUNC(sub_822D53D8);
PPC_FUNC_IMPL(__imp__sub_822D53D8) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-14468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14468);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d5440
	if (!cr6.eq) goto loc_822D5440;
	// li r3,4352
	ctx.r3.s64 = 4352;
	// bl 0x82130528
	ctx.lr = 0x822D5400;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5424
	if (cr6.eq) goto loc_822D5424;
	// bl 0x822df540
	ctx.lr = 0x822D540C;
	sub_822DF540(ctx, base);
	// stw r3,-14468(r31)
	PPC_STORE_U32(r31.u32 + -14468, ctx.r3.u32);
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
loc_822D5424:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-14468(r31)
	PPC_STORE_U32(r31.u32 + -14468, ctx.r3.u32);
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
loc_822D5440:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-14468(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14468);
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

__attribute__((alias("__imp__sub_822D5464"))) PPC_WEAK_FUNC(sub_822D5464);
PPC_FUNC_IMPL(__imp__sub_822D5464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5468"))) PPC_WEAK_FUNC(sub_822D5468);
PPC_FUNC_IMPL(__imp__sub_822D5468) {
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
	// cmpwi cr6,r30,512
	cr6.compare<int32_t>(r30.s32, 512, xer);
	// beq cr6,0x822d54d0
	if (cr6.eq) goto loc_822D54D0;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// cmpwi cr6,r30,1024
	cr6.compare<int32_t>(r30.s32, 1024, xer);
	// bne cr6,0x822d54a8
	if (!cr6.eq) goto loc_822D54A8;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822D549C;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d54d0
	if (!cr6.eq) goto loc_822D54D0;
loc_822D54A8:
	// rlwinm r11,r30,0,19,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d54c8
	if (cr6.eq) goto loc_822D54C8;
	// lwz r11,-7572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lbz r11,14546(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d54d0
	if (!cr6.eq) goto loc_822D54D0;
loc_822D54C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d9078
	ctx.lr = 0x822D54D0;
	sub_822D9078(ctx, base);
loc_822D54D0:
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

__attribute__((alias("__imp__sub_822D54E8"))) PPC_WEAK_FUNC(sub_822D54E8);
PPC_FUNC_IMPL(__imp__sub_822D54E8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D54F0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r25,0
	r25.s64 = 0;
	// addi r28,r11,-27312
	r28.s64 = r11.s64 + -27312;
	// addi r11,r28,384
	r11.s64 = r28.s64 + 384;
loc_822D5508:
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// addi r10,r28,13184
	ctx.r10.s64 = r28.s64 + 13184;
	// addi r11,r11,400
	r11.s64 = r11.s64 + 400;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d5508
	if (cr6.lt) goto loc_822D5508;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r8,r9,57792
	ctx.r8.u64 = ctx.r9.u64 | 57792;
	// lwz r11,-17628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82176058
	ctx.lr = 0x822D554C;
	sub_82176058(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lhz r7,26(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822d55d0
	if (cr6.eq) goto loc_822D55D0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r29,r25
	r29.u64 = r25.u64;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822D557C:
	// lbz r10,-27383(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + -27383);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5590
	if (cr6.eq) goto loc_822D5590;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822d5594
	goto loc_822D5594;
loc_822D5590:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_822D5594:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lfs f5,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lfs f4,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822d7d00
	ctx.lr = 0x822D55B8;
	sub_822D7D00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,304
	r29.s64 = r29.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d557c
	if (cr6.lt) goto loc_822D557C;
loc_822D55D0:
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5608
	if (cr6.eq) goto loc_822D5608;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_822D55E4:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x822d9de0
	ctx.lr = 0x822D55F0;
	sub_822D9DE0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d55e4
	if (cr6.lt) goto loc_822D55E4;
loc_822D5608:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D5614"))) PPC_WEAK_FUNC(sub_822D5614);
PPC_FUNC_IMPL(__imp__sub_822D5614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5618"))) PPC_WEAK_FUNC(sub_822D5618);
PPC_FUNC_IMPL(__imp__sub_822D5618) {
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
	ctx.lr = 0x822D5620;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-7520(r1)
	ea = -7520 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x822d67d0
	ctx.lr = 0x822D562C;
	sub_822D67D0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,-27312
	r28.s64 = r11.s64 + -27312;
	// addi r11,r28,384
	r11.s64 = r28.s64 + 384;
loc_822D563C:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r10,r28,13184
	ctx.r10.s64 = r28.s64 + 13184;
	// addi r11,r11,400
	r11.s64 = r11.s64 + 400;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d563c
	if (cr6.lt) goto loc_822D563C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r8,r9,57792
	ctx.r8.u64 = ctx.r9.u64 | 57792;
	// lwz r11,-17628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82176058
	ctx.lr = 0x822D5680;
	sub_82176058(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822d9490
	ctx.lr = 0x822D5688;
	sub_822D9490(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8217d5e8
	ctx.lr = 0x822D5690;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x8217d5e8
	ctx.lr = 0x822D5698;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56A0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,3280
	ctx.r3.s64 = ctx.r1.s64 + 3280;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56A8;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,4272
	ctx.r3.s64 = ctx.r1.s64 + 4272;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56B0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,5264
	ctx.r3.s64 = ctx.r1.s64 + 5264;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56B8;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,6256
	ctx.r3.s64 = ctx.r1.s64 + 6256;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56C0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e0230
	ctx.lr = 0x822D56C8;
	sub_822E0230(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lhz r7,26(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822d5720
	if (cr6.eq) goto loc_822D5720;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822D56E4:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x822d7120
	ctx.lr = 0x822D5708;
	sub_822D7120(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,304
	r29.s64 = r29.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d56e4
	if (cr6.lt) goto loc_822D56E4;
loc_822D5720:
	// addi r3,r1,6256
	ctx.r3.s64 = ctx.r1.s64 + 6256;
	// bl 0x8217cb48
	ctx.lr = 0x822D5728;
	sub_8217CB48(ctx, base);
	// addi r3,r1,5264
	ctx.r3.s64 = ctx.r1.s64 + 5264;
	// bl 0x8217cb48
	ctx.lr = 0x822D5730;
	sub_8217CB48(ctx, base);
	// addi r3,r1,4272
	ctx.r3.s64 = ctx.r1.s64 + 4272;
	// bl 0x8217cb48
	ctx.lr = 0x822D5738;
	sub_8217CB48(ctx, base);
	// addi r3,r1,3280
	ctx.r3.s64 = ctx.r1.s64 + 3280;
	// bl 0x8217cb48
	ctx.lr = 0x822D5740;
	sub_8217CB48(ctx, base);
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x8217cb48
	ctx.lr = 0x822D5748;
	sub_8217CB48(ctx, base);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x8217cb48
	ctx.lr = 0x822D5750;
	sub_8217CB48(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8217cb48
	ctx.lr = 0x822D5758;
	sub_8217CB48(ctx, base);
	// addi r1,r1,7520
	ctx.r1.s64 = ctx.r1.s64 + 7520;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D5760"))) PPC_WEAK_FUNC(sub_822D5760);
PPC_FUNC_IMPL(__imp__sub_822D5760) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D5768;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// li r27,-1
	r27.s64 = -1;
	// li r28,-1
	r28.s64 = -1;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// li r29,0
	r29.s64 = 0;
	// lfs f0,-13972(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13972);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f30,f0
	f30.f64 = f0.f64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// fmr f31,f0
	f31.f64 = f0.f64;
	// rlwinm r26,r9,31,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x1;
	// lhz r8,26(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// rlwinm r25,r9,30,31,31
	r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5884
	if (cr6.eq) goto loc_822D5884;
	// li r30,0
	r30.s64 = 0;
loc_822D57C0:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822d5820
	if (!cr6.eq) goto loc_822D5820;
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5814
	if (!cr6.eq) goto loc_822D5814;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5820
	if (cr6.eq) goto loc_822D5820;
	// lhz r10,292(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d5820
	if (!cr6.eq) goto loc_822D5820;
loc_822D5814:
	// bl 0x822d9d30
	ctx.lr = 0x822D5818;
	sub_822D9D30(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x822d5860
	goto loc_822D5860;
loc_822D5820:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// lhz r9,292(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 292);
	// lfs f0,260(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	f0.f64 = double(temp.f32);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5850
	if (cr6.eq) goto loc_822D5850;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x822d5860
	if (!cr6.gt) goto loc_822D5860;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// mr r27,r29
	r27.u64 = r29.u64;
	// b 0x822d5860
	goto loc_822D5860;
loc_822D5850:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822d5860
	if (!cr6.gt) goto loc_822D5860;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_822D5860:
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d57c0
	if (cr6.lt) goto loc_822D57C0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x822d5884
	if (cr6.lt) goto loc_822D5884;
	// mulli r10,r28,304
	ctx.r10.s64 = r28.s64 * 304;
	// b 0x822d589c
	goto loc_822D589C;
loc_822D5884:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d58a8
	if (!cr6.eq) goto loc_822D58A8;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x822d58a8
	if (cr6.lt) goto loc_822D58A8;
	// mulli r10,r27,304
	ctx.r10.s64 = r27.s64 * 304;
loc_822D589C:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D58A8;
	sub_822D9D30(ctx, base);
loc_822D58A8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D58B8"))) PPC_WEAK_FUNC(sub_822D58B8);
PPC_FUNC_IMPL(__imp__sub_822D58B8) {
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
	ctx.lr = 0x822D58C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d58ec
	if (cr6.eq) goto loc_822D58EC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D58E0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822D58EC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5924
	if (cr6.eq) goto loc_822D5924;
	// li r30,0
	r30.s64 = 0;
loc_822D5900:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822d8f78
	ctx.lr = 0x822D5910;
	sub_822D8F78(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822d5900
	if (cr6.lt) goto loc_822D5900;
loc_822D5924:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5930"))) PPC_WEAK_FUNC(sub_822D5930);
PPC_FUNC_IMPL(__imp__sub_822D5930) {
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
	ctx.lr = 0x822D5938;
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
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D596C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D5980;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x822df820
	ctx.lr = 0x822D5994;
	sub_822DF820(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D599C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D59AC"))) PPC_WEAK_FUNC(sub_822D59AC);
PPC_FUNC_IMPL(__imp__sub_822D59AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D59B0"))) PPC_WEAK_FUNC(sub_822D59B0);
PPC_FUNC_IMPL(__imp__sub_822D59B0) {
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
	ctx.lr = 0x822D59B8;
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
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D59EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D5A00;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x822db6f0
	ctx.lr = 0x822D5A14;
	sub_822DB6F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D5A1C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D5A2C"))) PPC_WEAK_FUNC(sub_822D5A2C);
PPC_FUNC_IMPL(__imp__sub_822D5A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5A30"))) PPC_WEAK_FUNC(sub_822D5A30);
PPC_FUNC_IMPL(__imp__sub_822D5A30) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822D5A38;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5dc0
	if (cr6.eq) goto loc_822D5DC0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-27381(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27381);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5a74
	if (cr6.eq) goto loc_822D5A74;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,3576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3576);
	f0.f64 = double(temp.f32);
	// b 0x822d5a7c
	goto loc_822D5A7C;
loc_822D5A74:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,3580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3580);
	f0.f64 = double(temp.f32);
loc_822D5A7C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lbz r9,-27382(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -27382);
	// lfs f30,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d5b08
	if (cr6.eq) goto loc_822D5B08;
loc_822D5A98:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5a98
	if (cr6.eq) goto loc_822D5A98;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,-27360(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + -27360);
	// lfs f0,-14064(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14064);
	f0.f64 = double(temp.f32);
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f13,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d5af4
	if (!cr6.gt) goto loc_822D5AF4;
loc_822D5AE0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d5ae0
	if (cr6.eq) goto loc_822D5AE0;
	// std r11,-27360(r10)
	PPC_STORE_U64(ctx.r10.u32 + -27360, r11.u64);
loc_822D5AF4:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// li r11,0
	r11.s64 = 0;
	// bgt cr6,0x822d5b04
	if (cr6.gt) goto loc_822D5B04;
	// li r11,1
	r11.s64 = 1;
loc_822D5B04:
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
loc_822D5B08:
	// bl 0x822bf228
	ctx.lr = 0x822D5B0C;
	sub_822BF228(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f31.f64 = double(temp.f32);
	// bne cr6,0x822d5bb8
	if (!cr6.eq) goto loc_822D5BB8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lwz r30,-8092(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r11,45
	ctx.r4.s64 = r11.s64 + 45;
	// lfs f12,-26236(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -26236);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r6,29952
	r11.s64 = ctx.r6.s64 + 29952;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// lfs f2,3572(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3572);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lfs f9,696(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 696);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fsel f6,f7,f7,f11
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : ctx.f11.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f4,f5,f0,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fmadds f1,f4,f10,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f10.f64 + ctx.f13.f64));
	// bl 0x821ce490
	ctx.lr = 0x822D5B94;
	sub_821CE490(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e5b30
	ctx.lr = 0x822D5B9C;
	sub_822E5B30(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5bb8
	if (cr6.eq) goto loc_822D5BB8;
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// b 0x822d5bbc
	goto loc_822D5BBC;
loc_822D5BB8:
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
loc_822D5BBC:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f13,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f0,3664(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 3664, temp.u32);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x822dcaf0
	ctx.lr = 0x822D5BD8;
	sub_822DCAF0(ctx, base);
	// bl 0x822d79e0
	ctx.lr = 0x822D5BDC;
	sub_822D79E0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r9,-27380
	ctx.r8.s64 = ctx.r9.s64 + -27380;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14389(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14389);
	// bne cr6,0x822d5d5c
	if (!cr6.eq) goto loc_822D5D5C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5d4c
	if (cr6.eq) goto loc_822D5D4C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14356(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14356);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d5d4c
	if (!cr6.eq) goto loc_822D5D4C;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-14464(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14464);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-14464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14464, r11.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x822d5d80
	if (!cr6.gt) goto loc_822D5D80;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lwz r11,-14432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14432);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5c90
	if (cr6.lt) goto loc_822D5C90;
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d5cc4
	if (!cr6.lt) goto loc_822D5CC4;
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822d5ce0
	if (cr6.lt) goto loc_822D5CE0;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lfs f0,-14404(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14404);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lfs f0,-14396(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14396);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d5ce0
	if (!cr6.lt) goto loc_822D5CE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// mulli r10,r10,304
	ctx.r10.s64 = ctx.r10.s64 * 304;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x822d5cd4
	goto loc_822D5CD4;
loc_822D5C90:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14436(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14436);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5cdc
	if (cr6.lt) goto loc_822D5CDC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lfs f0,-14400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14400);
	f0.f64 = double(temp.f32);
	// lfs f13,-14440(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d5cdc
	if (!cr6.lt) goto loc_822D5CDC;
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5ce0
	if (cr6.lt) goto loc_822D5CE0;
loc_822D5CC4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r9,r11,304
	ctx.r9.s64 = r11.s64 * 304;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
loc_822D5CD4:
	// bl 0x822d9d30
	ctx.lr = 0x822D5CD8;
	sub_822D9D30(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_822D5CDC:
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
loc_822D5CE0:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5d80
	if (!cr6.eq) goto loc_822D5D80;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3652);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d5d80
	if (!cr6.lt) goto loc_822D5D80;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5d24
	if (cr6.lt) goto loc_822D5D24;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r9,r11,304
	ctx.r9.s64 = r11.s64 * 304;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D5D20;
	sub_822D9D30(ctx, base);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D24:
	// lwz r11,-14424(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5d80
	if (cr6.lt) goto loc_822D5D80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// mulli r10,r10,304
	ctx.r10.s64 = ctx.r10.s64 * 304;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D5D48;
	sub_822D9D30(ctx, base);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D4C:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-14464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14464, r11.u32);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D5C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5d80
	if (cr6.eq) goto loc_822D5D80;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,11724(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5d80
	if (!cr6.eq) goto loc_822D5D80;
	// li r11,5
	r11.s64 = 5;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_822D5D80:
	// bl 0x822d6428
	ctx.lr = 0x822D5D84;
	sub_822D6428(ctx, base);
	// bl 0x822da940
	ctx.lr = 0x822D5D88;
	sub_822DA940(ctx, base);
	// bl 0x822d54e8
	ctx.lr = 0x822D5D8C;
	sub_822D54E8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-27384(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27384);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5da0
	if (!cr6.eq) goto loc_822D5DA0;
	// bl 0x822d5618
	ctx.lr = 0x822D5DA0;
	sub_822D5618(ctx, base);
loc_822D5DA0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d5dc0
	if (!cr6.eq) goto loc_822D5DC0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d5dc0
	if (cr6.eq) goto loc_822D5DC0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822d5760
	ctx.lr = 0x822D5DC0;
	sub_822D5760(ctx, base);
loc_822D5DC0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5DD0"))) PPC_WEAK_FUNC(sub_822D5DD0);
PPC_FUNC_IMPL(__imp__sub_822D5DD0) {
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
	ctx.lr = 0x822D5DD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r8,r11,-13964
	ctx.r8.s64 = r11.s64 + -13964;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwz r11,-14472(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14472);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// lwz r3,-14472(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14472);
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x822d5e24
	if (!cr6.eq) goto loc_822D5E24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D5E24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D5E24:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5e44
	if (cr6.eq) goto loc_822D5E44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D5E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D5E44:
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822D5E4C;
	sub_82130588(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r11,0
	r11.s64 = 0;
	// stw r11,3528(r10)
	PPC_STORE_U32(ctx.r10.u32 + 3528, r11.u32);
	// lhz r31,26(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d5e90
	if (cr6.eq) goto loc_822D5E90;
	// lwz r28,20(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d5e88
	if (!cr6.gt) goto loc_822D5E88;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_822D5E74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d9080
	ctx.lr = 0x822D5E7C;
	sub_822D9080(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// bne 0x822d5e74
	if (!cr0.eq) goto loc_822D5E74;
loc_822D5E88:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822D5E90;
	sub_82130588(ctx, base);
loc_822D5E90:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2810
	ctx.lr = 0x822D5E98;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5EA0"))) PPC_WEAK_FUNC(sub_822D5EA0);
PPC_FUNC_IMPL(__imp__sub_822D5EA0) {
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
	// bl 0x821d2970
	ctx.lr = 0x822D5EC0;
	sub_821D2970(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-13964
	ctx.r10.s64 = r11.s64 + -13964;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b48f0
	ctx.lr = 0x822D5ED4;
	sub_821B48F0(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x822d5930
	ctx.lr = 0x822D5EDC;
	sub_822D5930(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x822d59b0
	ctx.lr = 0x822D5EE4;
	sub_822D59B0(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822d58b8
	ctx.lr = 0x822D5EF4;
	sub_822D58B8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r11,r9,3528
	r11.s64 = ctx.r9.s64 + 3528;
	// addi r3,r8,-27352
	ctx.r3.s64 = ctx.r8.s64 + -27352;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x821c07c0
	ctx.lr = 0x822D5F0C;
	sub_821C07C0(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r5,r7,-14512
	ctx.r5.s64 = ctx.r7.s64 + -14512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r11,-27382(r6)
	PPC_STORE_U8(ctx.r6.u32 + -27382, r11.u8);
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

__attribute__((alias("__imp__sub_822D5F48"))) PPC_WEAK_FUNC(sub_822D5F48);
PPC_FUNC_IMPL(__imp__sub_822D5F48) {
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
	// bl 0x822d5dd0
	ctx.lr = 0x822D5F68;
	sub_822D5DD0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5f80
	if (cr6.eq) goto loc_822D5F80;
	// bl 0x82130588
	ctx.lr = 0x822D5F7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D5F80:
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

__attribute__((alias("__imp__sub_822D5F98"))) PPC_WEAK_FUNC(sub_822D5F98);
PPC_FUNC_IMPL(__imp__sub_822D5F98) {
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
	ctx.lr = 0x822D5FA0;
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
	ctx.lr = 0x822D5FD4;
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
	// beq cr6,0x822d6040
	if (cr6.eq) goto loc_822D6040;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822d5ea0
	ctx.lr = 0x822D6024;
	sub_822D5EA0(ctx, base);
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
loc_822D6040:
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

__attribute__((alias("__imp__sub_822D6054"))) PPC_WEAK_FUNC(sub_822D6054);
PPC_FUNC_IMPL(__imp__sub_822D6054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6058"))) PPC_WEAK_FUNC(sub_822D6058);
PPC_FUNC_IMPL(__imp__sub_822D6058) {
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
	ctx.lr = 0x822D6060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x822b9708
	ctx.lr = 0x822D606C;
	sub_822B9708(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,19848
	ctx.r4.s64 = ctx.r10.s64 + 19848;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D6084;
	sub_821CA540(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r9,19612
	r30.s64 = ctx.r9.s64 + 19612;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D6098;
	sub_821CA540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D60A4;
	sub_821CA540(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r29,r11,3528
	r29.s64 = r11.s64 + 3528;
	// addi r5,r8,-13924
	ctx.r5.s64 = ctx.r8.s64 + -13924;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x822d5f98
	ctx.lr = 0x822D60C8;
	sub_822D5F98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60D0;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60D8;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60E0;
	sub_821C9A90(ctx, base);
	// bl 0x822d5348
	ctx.lr = 0x822D60E4;
	sub_822D5348(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822d6110
	if (!cr6.eq) goto loc_822D6110;
	// mr r31,r11
	r31.u64 = r11.u64;
	// bl 0x822d53d8
	ctx.lr = 0x822D60FC;
	sub_822D53D8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x822dd450
	ctx.lr = 0x822D610C;
	sub_822DD450(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_822D6110:
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x822dac38
	ctx.lr = 0x822D6118;
	sub_822DAC38(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d94a0
	ctx.lr = 0x822D6120;
	sub_822D94A0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d9560
	ctx.lr = 0x822D6128;
	sub_822D9560(ctx, base);
	// bl 0x822d8d70
	ctx.lr = 0x822D612C;
	sub_822D8D70(ctx, base);
loc_822D612C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d612c
	if (cr6.eq) goto loc_822D612C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// addi r3,r10,-13952
	ctx.r3.s64 = ctx.r10.s64 + -13952;
	// bl 0x82130000
	ctx.lr = 0x822D614C;
	sub_82130000(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// lhz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d618c
	if (cr6.eq) goto loc_822D618C;
	// li r30,0
	r30.s64 = 0;
loc_822D6164:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x822d6a78
	ctx.lr = 0x822D6174;
	sub_822D6A78(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d6164
	if (cr6.lt) goto loc_822D6164;
loc_822D618C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d618c
	if (cr6.eq) goto loc_822D618C;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D61A8"))) PPC_WEAK_FUNC(sub_822D61A8);
PPC_FUNC_IMPL(__imp__sub_822D61A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// li r11,16
	r11.s64 = 16;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r10,-31568
	ctx.r8.s64 = ctx.r10.s64 + -31568;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// lvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r3,r6,2240
	ctx.r3.s64 = ctx.r6.s64 + 2240;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r8,-12736
	ctx.r7.s64 = ctx.r8.s64 + -12736;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v57,v57
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vaddfp128 v11,v57,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v9,v55,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v56,v4
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vsel v2,v11,v3,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// stvx128 v2,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6240"))) PPC_WEAK_FUNC(sub_822D6240);
PPC_FUNC_IMPL(__imp__sub_822D6240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-11856
	r11.s64 = r11.s64 + -11856;
	// lwz r10,-11840(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11840);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d6280
	if (!cr6.eq) goto loc_822D6280;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,-11840(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11840, ctx.r10.u32);
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_822D6280:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r9,-12736
	ctx.r8.s64 = ctx.r9.s64 + -12736;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vmsum3fp128 v56,v57,v57
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vaddfp128 v11,v57,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v9,v55,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v56,v4
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vsel v2,v11,v3,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// stvx128 v2,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6310"))) PPC_WEAK_FUNC(sub_822D6310);
PPC_FUNC_IMPL(__imp__sub_822D6310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v63{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d6334
	if (!cr6.eq) goto loc_822D6334;
	// lbz r10,-14375(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + -14375);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d63ec
	if (!cr6.eq) goto loc_822D63EC;
loc_822D6334:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d637c
	if (!cr6.eq) goto loc_822D637C;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r10,-14348(r7)
	PPC_STORE_U8(ctx.r7.u32 + -14348, ctx.r10.u8);
	// stb r9,-14352(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14352, ctx.r9.u8);
	// beq cr6,0x822d6364
	if (cr6.eq) goto loc_822D6364;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-14375(r8)
	PPC_STORE_U8(ctx.r8.u32 + -14375, r11.u8);
loc_822D6364:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-14444(r10)
	PPC_STORE_U8(ctx.r10.u32 + -14444, r11.u8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_822D637C:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r31,r10,-11984
	r31.s64 = ctx.r10.s64 + -11984;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r10,-14444(r7)
	PPC_STORE_U8(ctx.r7.u32 + -14444, ctx.r10.u8);
	// li r30,16
	r30.s64 = 16;
	// stb r9,-14348(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14348, ctx.r9.u8);
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// stb r4,-14352(r5)
	PPC_STORE_U8(ctx.r5.u32 + -14352, ctx.r4.u8);
	// li r7,32
	ctx.r7.s64 = 32;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v63,r3,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822d63ec
	if (cr6.eq) goto loc_822D63EC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-14375(r8)
	PPC_STORE_U8(ctx.r8.u32 + -14375, r11.u8);
loc_822D63EC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D63F8"))) PPC_WEAK_FUNC(sub_822D63F8);
PPC_FUNC_IMPL(__imp__sub_822D63F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f1,3672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3672);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6404"))) PPC_WEAK_FUNC(sub_822D6404);
PPC_FUNC_IMPL(__imp__sub_822D6404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6408"))) PPC_WEAK_FUNC(sub_822D6408);
PPC_FUNC_IMPL(__imp__sub_822D6408) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14360(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14360);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x822d6420
	if (cr6.gt) goto loc_822D6420;
	// li r11,0
	r11.s64 = 0;
loc_822D6420:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6428"))) PPC_WEAK_FUNC(sub_822D6428);
PPC_FUNC_IMPL(__imp__sub_822D6428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lfs f0,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	f0.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lfs f13,-13544(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13544);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// stfs f0,-14400(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -14400, temp.u32);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// stw r11,-14436(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14436, r11.u32);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// stfs f0,-14404(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -14404, temp.u32);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f13,-14440(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + -14440, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,-14432(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14432, ctx.r10.u32);
	// stfs f13,-14396(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + -14396, temp.u32);
	// stw r9,-14448(r4)
	PPC_STORE_U32(ctx.r4.u32 + -14448, ctx.r9.u32);
	// stw r8,-14424(r31)
	PPC_STORE_U32(r31.u32 + -14424, ctx.r8.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6494"))) PPC_WEAK_FUNC(sub_822D6494);
PPC_FUNC_IMPL(__imp__sub_822D6494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6498"))) PPC_WEAK_FUNC(sub_822D6498);
PPC_FUNC_IMPL(__imp__sub_822D6498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,292(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// rlwinm r10,r11,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FE;
	// rlwinm r10,r10,0,28,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3623(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3623);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6520
	if (cr6.eq) goto loc_822D6520;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-14428
	ctx.r9.s64 = r11.s64 + -14428;
	// lwz r11,-14428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14428);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d64f8
	if (cr6.eq) goto loc_822D64F8;
	// lfs f0,268(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	f0.f64 = double(temp.f32);
loc_822D64D8:
	// lfs f13,268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822d650c
	if (cr6.lt) goto loc_822D650C;
	// addi r9,r11,276
	ctx.r9.s64 = r11.s64 + 276;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,276(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d64d8
	if (!cr6.eq) goto loc_822D64D8;
loc_822D64F8:
	// li r11,0
	r11.s64 = 0;
	// stw r10,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r10.u32);
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// blr 
	return;
loc_822D650C:
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r10,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r10.u32);
	// stw r3,280(r11)
	PPC_STORE_U32(r11.u32 + 280, ctx.r3.u32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// blr 
	return;
loc_822D6520:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-14428(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14428);
	// stw r9,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r9.u32);
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r3,-14428(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14428, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D653C"))) PPC_WEAK_FUNC(sub_822D653C);
PPC_FUNC_IMPL(__imp__sub_822D653C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6540"))) PPC_WEAK_FUNC(sub_822D6540);
PPC_FUNC_IMPL(__imp__sub_822D6540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r7,252(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lbz r11,295(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 295);
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// bne cr6,0x822d657c
	if (!cr6.eq) goto loc_822D657C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3676(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3676);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d657c
	if (cr6.eq) goto loc_822D657C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3664);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d6580
	if (cr6.lt) goto loc_822D6580;
loc_822D657C:
	// li r11,0
	r11.s64 = 0;
loc_822D6580:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d65a4
	if (!cr6.eq) goto loc_822D65A4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-14380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d65a8
	if (!cr6.eq) goto loc_822D65A8;
loc_822D65A4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822D65A8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r11,3612
	ctx.r10.s64 = r11.s64 + 3612;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r5,r11,-14444
	ctx.r5.s64 = r11.s64 + -14444;
	// lbz r4,1(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822d6698
	if (!cr6.eq) goto loc_822D6698;
	// lhz r11,292(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// rlwinm r5,r11,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d669c
	if (cr6.eq) goto loc_822D669C;
	// lbz r11,296(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// bne cr6,0x822d6698
	if (!cr6.eq) goto loc_822D6698;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d662c
	if (cr6.eq) goto loc_822D662C;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822d6668
	if (!cr6.eq) goto loc_822D6668;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d6660
	if (!cr6.eq) goto loc_822D6660;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// b 0x822d6668
	goto loc_822D6668;
loc_822D662C:
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822d6668
	if (!cr6.eq) goto loc_822D6668;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d6660
	if (cr6.eq) goto loc_822D6660;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// b 0x822d6668
	goto loc_822D6668;
loc_822D6660:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x822d669c
	if (cr6.eq) goto loc_822D669C;
loc_822D6668:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,288(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,29952
	ctx.r5.s64 = r11.s64 + 29952;
	// lfs f0,88(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f13,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f11,288(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x822d669c
	if (!cr6.gt) goto loc_822D669C;
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
loc_822D6698:
	// li r9,1
	ctx.r9.s64 = 1;
loc_822D669C:
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, r11.u8);
	// bne cr6,0x822d66b4
	if (!cr6.eq) goto loc_822D66B4;
	// li r11,4
	r11.s64 = 4;
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, r11.u8);
loc_822D66B4:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d66cc
	if (cr6.eq) goto loc_822D66CC;
	// lbz r10,296(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// ori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 | 1;
	// stb r8,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r8.u8);
loc_822D66CC:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stb r9,295(r3)
	PPC_STORE_U8(ctx.r3.u32 + 295, ctx.r9.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,296(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// ori r8,r11,2
	ctx.r8.u64 = r11.u64 | 2;
	// stb r8,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D66E8"))) PPC_WEAK_FUNC(sub_822D66E8);
PPC_FUNC_IMPL(__imp__sub_822D66E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6700
	if (cr6.eq) goto loc_822D6700;
	// li r3,4
	ctx.r3.s64 = 4;
loc_822D6700:
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6714
	if (cr6.eq) goto loc_822D6714;
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_822D6714:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6728
	if (cr6.eq) goto loc_822D6728;
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_822D6728:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d673c
	if (cr6.eq) goto loc_822D673C;
	// li r3,32
	ctx.r3.s64 = 32;
	// blr 
	return;
loc_822D673C:
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6750
	if (cr6.eq) goto loc_822D6750;
	// li r3,64
	ctx.r3.s64 = 64;
	// blr 
	return;
loc_822D6750:
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6764
	if (cr6.eq) goto loc_822D6764;
	// li r3,128
	ctx.r3.s64 = 128;
	// blr 
	return;
loc_822D6764:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6778
	if (cr6.eq) goto loc_822D6778;
	// li r3,512
	ctx.r3.s64 = 512;
	// blr 
	return;
loc_822D6778:
	// rlwinm r10,r11,0,7,7
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d678c
	if (cr6.eq) goto loc_822D678C;
	// li r3,1024
	ctx.r3.s64 = 1024;
	// blr 
	return;
loc_822D678C:
	// rlwinm r10,r11,0,11,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFE;
	// rlwinm r10,r10,0,30,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFE0003;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d67a4
	if (cr6.eq) goto loc_822D67A4;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_822D67A4:
	// rlwinm r10,r11,0,17,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7C00;
	// rlwinm r10,r10,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d67bc
	if (cr6.eq) goto loc_822D67BC;
	// li r3,256
	ctx.r3.s64 = 256;
	// blr 
	return;
loc_822D67BC:
	// rlwinm r11,r11,0,20,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r3,2048
	ctx.r3.s64 = 2048;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D67D0"))) PPC_WEAK_FUNC(sub_822D67D0);
PPC_FUNC_IMPL(__imp__sub_822D67D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D67DC"))) PPC_WEAK_FUNC(sub_822D67DC);
PPC_FUNC_IMPL(__imp__sub_822D67DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D67E0"))) PPC_WEAK_FUNC(sub_822D67E0);
PPC_FUNC_IMPL(__imp__sub_822D67E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stb r3,3622(r11)
	PPC_STORE_U8(r11.u32 + 3622, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D67EC"))) PPC_WEAK_FUNC(sub_822D67EC);
PPC_FUNC_IMPL(__imp__sub_822D67EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D67F0"))) PPC_WEAK_FUNC(sub_822D67F0);
PPC_FUNC_IMPL(__imp__sub_822D67F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-14374(r10)
	PPC_STORE_U8(ctx.r10.u32 + -14374, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6800"))) PPC_WEAK_FUNC(sub_822D6800);
PPC_FUNC_IMPL(__imp__sub_822D6800) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822D6808;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r30,r7,-11984
	r30.s64 = ctx.r7.s64 + -11984;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lbz r11,-14348(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + -14348);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r29,16
	r29.s64 = 16;
	// addi r5,r5,-14348
	ctx.r5.s64 = ctx.r5.s64 + -14348;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r6,-14368
	ctx.r8.s64 = ctx.r6.s64 + -14368;
	// lbz r10,-14352(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + -14352);
	// lbz r9,-14444(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + -14444);
	// li r28,32
	r28.s64 = 32;
	// lwz r7,-14448(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -14448);
	// li r27,48
	r27.s64 = 48;
	// lvx128 v62,r30,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,64
	r31.s64 = 64;
	// stb r11,1(r5)
	PPC_STORE_U8(ctx.r5.u32 + 1, r11.u8);
	// li r26,80
	r26.s64 = 80;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r4,r4,-14352
	ctx.r4.s64 = ctx.r4.s64 + -14352;
	// li r29,96
	r29.s64 = 96;
	// lvx128 v61,r30,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-14444
	ctx.r3.s64 = ctx.r3.s64 + -14444;
	// lvx128 v60,r30,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,112
	r11.s64 = 112;
	// stvx128 v63,r30,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r30,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r8,-14368(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14368, ctx.r8.u32);
	// stb r10,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r10.u8);
	// stvx128 v61,r30,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// stvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x822d68bc
	if (!cr6.lt) goto loc_822D68BC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14389(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14389);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d68bc
	if (cr6.eq) goto loc_822D68BC;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-14360(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14360);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x822d68c4
	goto loc_822D68C4;
loc_822D68BC:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
loc_822D68C4:
	// stw r11,-14360(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14360, r11.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,3528
	ctx.r9.s64 = r11.s64 + 3528;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f0,-14404(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14404);
	f0.f64 = double(temp.f32);
	// lbz r6,28(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 28);
	// stfs f0,3672(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 3672, temp.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r11,3676(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3676, r11.u8);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D68F8"))) PPC_WEAK_FUNC(sub_822D68F8);
PPC_FUNC_IMPL(__imp__sub_822D68F8) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r10,-13000
	ctx.r3.s64 = ctx.r10.s64 + -13000;
	// addi r4,r11,3644
	ctx.r4.s64 = r11.s64 + 3644;
	// li r11,-1
	r11.s64 = -1;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d693c
	if (!cr6.eq) goto loc_822D693C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13020
	ctx.r3.s64 = r11.s64 + -13020;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d6948
	if (cr6.eq) goto loc_822D6948;
loc_822D693C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// bl 0x821c0750
	ctx.lr = 0x822D6948;
	sub_821C0750(ctx, base);
loc_822D6948:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-14340
	ctx.r9.s64 = r11.s64 + -14340;
	// addi r8,r10,-14260
	ctx.r8.s64 = ctx.r10.s64 + -14260;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-14392
	r11.s64 = r11.s64 + -14392;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// beq cr6,0x822d6988
	if (cr6.eq) goto loc_822D6988;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_822D6988:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6998"))) PPC_WEAK_FUNC(sub_822D6998);
PPC_FUNC_IMPL(__imp__sub_822D6998) {
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
	ctx.lr = 0x822D69A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x822d69dc
	if (!cr6.gt) goto loc_822D69DC;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_822D69B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D69D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bne 0x822d69b8
	if (!cr0.eq) goto loc_822D69B8;
loc_822D69DC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822D69E4;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D69EC"))) PPC_WEAK_FUNC(sub_822D69EC);
PPC_FUNC_IMPL(__imp__sub_822D69EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D69F0"))) PPC_WEAK_FUNC(sub_822D69F0);
PPC_FUNC_IMPL(__imp__sub_822D69F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lhz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 84);
	// li r31,0
	r31.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822d6a34
	if (!cr6.gt) goto loc_822D6A34;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
loc_822D6A14:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r4
	cr6.compare<uint32_t>(r30.u32, ctx.r4.u32, xer);
	// bne cr6,0x822d6a24
	if (!cr6.eq) goto loc_822D6A24;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_822D6A24:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822d6a14
	if (cr6.lt) goto loc_822D6A14;
loc_822D6A34:
	// stw r31,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r31.u32);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r31.u32);
	// beq cr6,0x822d6a6c
	if (cr6.eq) goto loc_822D6A6C;
	// addi r10,r5,11
	ctx.r10.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
loc_822D6A6C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6A78"))) PPC_WEAK_FUNC(sub_822D6A78);
PPC_FUNC_IMPL(__imp__sub_822D6A78) {
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
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822D6AA8;
	sub_82137A08(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r7,240(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// addi r5,r10,-13440
	ctx.r5.s64 = ctx.r10.s64 + -13440;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x822D6AC4;
	sub_82137A08(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822D6ACC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d6aec
	if (cr6.eq) goto loc_822D6AEC;
	// bl 0x821e2748
	ctx.lr = 0x822D6ADC;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x822d6af0
	goto loc_822D6AF0;
loc_822D6AEC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822D6AF0:
	// stw r3,248(r30)
	PPC_STORE_U32(r30.u32 + 248, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-13444
	ctx.r5.s64 = r11.s64 + -13444;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x821e2940
	ctx.lr = 0x822D6B0C;
	sub_821E2940(ctx, base);
	// lis r31,-32130
	r31.s64 = -2105671680;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822d6b50
	if (!cr6.eq) goto loc_822D6B50;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13460
	ctx.r3.s64 = r11.s64 + -13460;
	// bl 0x821881b8
	ctx.lr = 0x822D6B28;
	sub_821881B8(ctx, base);
	// stw r3,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13488
	ctx.r3.s64 = ctx.r10.s64 + -13488;
	// bl 0x821881b8
	ctx.lr = 0x822D6B38;
	sub_821881B8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r3,3684(r9)
	PPC_STORE_U32(ctx.r9.u32 + 3684, ctx.r3.u32);
	// stw r11,-14356(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14356, r11.u32);
	// b 0x822d6b5c
	goto loc_822D6B5C;
loc_822D6B50:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-14356(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14356, r11.u32);
loc_822D6B5C:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
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

__attribute__((alias("__imp__sub_822D6B74"))) PPC_WEAK_FUNC(sub_822D6B74);
PPC_FUNC_IMPL(__imp__sub_822D6B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6B78"))) PPC_WEAK_FUNC(sub_822D6B78);
PPC_FUNC_IMPL(__imp__sub_822D6B78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// li r11,16
	r11.s64 = 16;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// vspltw128 v60,v1,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// vspltw128 v59,v1,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// addi r8,r10,-13536
	ctx.r8.s64 = ctx.r10.s64 + -13536;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r9,-13520
	ctx.r7.s64 = ctx.r9.s64 + -13520;
	// lvx128 v58,r4,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v62,2
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v56,v58,2
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmrghw128 v54,v59,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v61,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v52,v61,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v49,v54,v63
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v48,v55,v57
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v47,v52,v63
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v46,v51,v63
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v45,v53,v63
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v44,v48,v63
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vsubfp128 v55,v47,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v60,v59,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vsubfp128 v56,v46,v49
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v54,v45,v49
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v57,v44,v49
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v43,v55,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vsubfp128 v62,v56,v55
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// vspltw128 v0,v55,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// vspltw128 v42,v62,2
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v42,v43
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v41,v0,v63
	simde_mm_store_ps(v41.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d6c50
	if (cr6.eq) goto loc_822D6C50;
	// vmsum3fp128 v40,v62,v62
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v39,v0,v0
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v38,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v38 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v38,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x0));
	// vrefp128 v0,v40
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v40.f32)));
	// vor128 v12,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v39,v9
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6c58
	goto loc_822D6C58;
loc_822D6C50:
	// vor128 v49,v63,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6C58:
	// vsubfp128 v62,v55,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// vspltw128 v37,v54,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vspltw128 v0,v54,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x55));
	// vmulfp128 v60,v61,v60
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v36,v62,2
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v36,v37
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v35,v0,v63
	simde_mm_store_ps(v35.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v35.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6cb8
	if (cr6.eq) goto loc_822D6CB8;
	// vmsum3fp128 v34,v62,v62
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v33,v0,v0
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v32,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v32 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v32,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x0));
	// vrefp128 v0,v34
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v34.f32)));
	// vor128 v12,v34,v34
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v34.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v51,v33,v9
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6cc0
	goto loc_822D6CC0;
loc_822D6CB8:
	// vor128 v51,v63,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6CC0:
	// vsubfp128 v62,v54,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v58,v57,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v0,v57,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x55));
	// vor128 v53,v61,v60
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vspltw128 v60,v59,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// vspltw128 v52,v62,2
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v52,v58
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v58.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v48,v0,v63
	simde_mm_store_ps(v48.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6d24
	if (cr6.eq) goto loc_822D6D24;
	// vmsum3fp128 v47,v62,v62
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v46,v0,v0
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v45,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v45 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v45,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0x0));
	// vrefp128 v0,v47
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v47.f32)));
	// vor128 v12,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v52,v46,v9
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6d2c
	goto loc_822D6D2C;
loc_822D6D24:
	// vor128 v52,v63,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6D2C:
	// vsubfp128 v62,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vspltw128 v44,v56,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vspltw128 v0,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// vmulfp128 v61,v61,v60
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v60,v59,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// vspltw128 v43,v62,2
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v43,v44
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v42,v0,v63
	simde_mm_store_ps(v42.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v42.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6d90
	if (cr6.eq) goto loc_822D6D90;
	// vmsum3fp128 v41,v62,v62
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v40,v0,v0
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v39,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v39 = vTemp;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v39,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x0));
	// vrefp128 v0,v41
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v41.f32)));
	// vor128 v12,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v40,v9
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6d98
	goto loc_822D6D98;
loc_822D6D90:
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6D98:
	// vmulfp128 v38,v62,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v37,v59,3
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x0));
	// vor128 v36,v38,v61
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vor128 v62,v53,v36
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vcmpequw128. v35,v62,v37
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	cr6.setFromMask(simde_mm_load_ps(v35.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6dc4
	if (cr6.eq) goto loc_822D6DC4;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6DC4:
	// vspltw128 v34,v50,0
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vcmpequw128. v33,v62,v34
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6e20
	if (cr6.eq) goto loc_822D6E20;
	// vmsum3fp128 v32,v55,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v60,v62,1
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v62.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x0));
	// vrsqrtefp128 v0,v32
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v32.f32))));
	// vor128 v11,v32,v32
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v32.u8));
	// vcmpeqfp128 v10,v32,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v32,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6E20:
	// vspltw128 v59,v50,1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xAA));
	// vcmpequw128. v55,v62,v59
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6e7c
	if (cr6.eq) goto loc_822D6E7C;
	// vmsum3fp128 v54,v56,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vspltisw128 v53,1
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v52,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v52 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v51,v53,1
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v52,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0x0));
	// vrsqrtefp128 v0,v54
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v54.f32))));
	// vor128 v11,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vcmpeqfp128 v10,v54,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v51,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v54,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6E7C:
	// vspltw128 v48,v50,2
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x55));
	// vcmpequw128. v47,v62,v48
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6ed8
	if (cr6.eq) goto loc_822D6ED8;
	// vmsum3fp128 v46,v57,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vspltisw128 v45,1
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v44,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v44 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v43,v45,1
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v44,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x0));
	// vrsqrtefp128 v0,v46
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v46.f32))));
	// vor128 v11,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vcmpeqfp128 v10,v46,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v43,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v46,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6ED8:
	// vspltw128 v42,v50,3
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x0));
	// vcmpequw128. v41,v62,v42
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6f34
	if (cr6.eq) goto loc_822D6F34;
	// vmsum3fp128 v40,v54,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vspltisw128 v39,1
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v38,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v38 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v37,v39,1
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v38,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x0));
	// vrsqrtefp128 v0,v40
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v40.f32))));
	// vor128 v11,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vcmpeqfp128 v10,v40,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v37,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v40,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6F34:
	// vmaxfp128 v36,v58,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_max_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v52.f32)));
	// vspltisw128 v35,1
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_set1_epi32(int(0x1)));
	// vmaxfp128 v34,v51,v49
	simde_mm_store_ps(v34.f32, simde_mm_max_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// vupkd3d128 v33,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v33 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v32,v35,1
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v33,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0x0));
	// vmaxfp128 v62,v34,v36
	simde_mm_store_ps(v62.f32, simde_mm_max_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v36.f32)));
	// vrsqrtefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v62.f32))));
	// vor128 v11,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vcmpeqfp128 v10,v62,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v32,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v62,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6F80"))) PPC_WEAK_FUNC(sub_822D6F80);
PPC_FUNC_IMPL(__imp__sub_822D6F80) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D6F88;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lvx128 v1,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c148
	ctx.lr = 0x822D6FB0;
	sub_8217C148(ctx, base);
	// lis r28,64
	r28.s64 = 4194304;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ori r28,r28,3
	r28.u64 = r28.u64 | 3;
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x822d6fd0
	if (!cr6.eq) goto loc_822D6FD0;
	// li r28,2
	r28.s64 = 2;
loc_822D6FD0:
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// bl 0x82175f20
	ctx.lr = 0x822D6FF0;
	sub_82175F20(ctx, base);
	// lis r29,1024
	r29.s64 = 67108864;
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// lis r26,4096
	r26.s64 = 268435456;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x822d7014
	if (cr6.eq) goto loc_822D7014;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d7018
	if (!cr6.eq) goto loc_822D7018;
loc_822D7014:
	// li r11,0
	r11.s64 = 0;
loc_822D7018:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// li r11,208
	r11.s64 = 208;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// li r10,224
	ctx.r10.s64 = 224;
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lvx128 v63,r27,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v62,r27,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v63,v127,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v127.f32), 147), 1));
	// vrlimi128 v62,v127,1,1
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v127.f32), 147), 1));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82175508
	ctx.lr = 0x822D7068;
	sub_82175508(ctx, base);
	// rlwinm r8,r3,0,5,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x822d7084
	if (cr6.eq) goto loc_822D7084;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d7088
	if (!cr6.eq) goto loc_822D7088;
loc_822D7084:
	// li r11,0
	r11.s64 = 0;
loc_822D7088:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// lhz r11,196(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d70f8
	if (cr6.eq) goto loc_822D70F8;
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d70b4
	if (cr6.eq) goto loc_822D70B4;
	// lwz r5,192(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 192);
	// b 0x822d70b8
	goto loc_822D70B8;
loc_822D70B4:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822D70B8:
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// bl 0x82175ad8
	ctx.lr = 0x822D70CC;
	sub_82175AD8(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x822d70e8
	if (cr6.eq) goto loc_822D70E8;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d70ec
	if (!cr6.eq) goto loc_822D70EC;
loc_822D70E8:
	// li r11,0
	r11.s64 = 0;
loc_822D70EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
loc_822D70F8:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d923c
	return;
loc_822D710C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D7120"))) PPC_WEAK_FUNC(sub_822D7120);
PPC_FUNC_IMPL(__imp__sub_822D7120) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D7128;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// rlwinm r10,r11,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FE;
	// rlwinm r10,r10,0,28,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7264
	if (cr6.eq) goto loc_822D7264;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d7264
	if (!cr6.eq) goto loc_822D7264;
	// lfs f0,268(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 268);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// blt cr6,0x822d7174
	if (cr6.lt) goto loc_822D7174;
	// lbz r11,295(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d7264
	if (cr6.eq) goto loc_822D7264;
loc_822D7174:
	// addi r29,r31,208
	r29.s64 = r31.s64 + 208;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d61a8
	ctx.lr = 0x822D7184;
	sub_822D61A8(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c278
	ctx.lr = 0x822D7198;
	sub_8217C278(ctx, base);
	// addi r6,r3,-2
	ctx.r6.s64 = ctx.r3.s64 + -2;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r4,22080(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22080);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// lwz r3,-17628(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17628);
	// xori r26,r11,1
	r26.u64 = r11.u64 ^ 1;
	// bl 0x821751a8
	ctx.lr = 0x822D71C8;
	sub_821751A8(ctx, base);
	// li r10,224
	ctx.r10.s64 = 224;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v1,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r31,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174678
	ctx.lr = 0x822D71DC;
	sub_82174678(ctx, base);
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82174ba0
	ctx.lr = 0x822D71F4;
	sub_82174BA0(ctx, base);
	// lwz r9,248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r4,292(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lhz r25,36(r8)
	r25.u64 = PPC_LOAD_U16(ctx.r8.u32 + 36);
	// bl 0x822df830
	ctx.lr = 0x822D7210;
	sub_822DF830(ctx, base);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lhz r5,292(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822df918
	ctx.lr = 0x822D7238;
	sub_822DF918(ctx, base);
	// lwz r6,248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// rotlwi r11,r25,4
	r11.u64 = __builtin_rotateleft32(r25.u32, 4);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r7,r7,-13248
	ctx.r7.s64 = ctx.r7.s64 + -13248;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822e0228
	ctx.lr = 0x822D7264;
	sub_822E0228(ctx, base);
loc_822D7264:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D726C"))) PPC_WEAK_FUNC(sub_822D726C);
PPC_FUNC_IMPL(__imp__sub_822D726C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D7270"))) PPC_WEAK_FUNC(sub_822D7270);
PPC_FUNC_IMPL(__imp__sub_822D7270) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r31,-7572(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lbz r10,14546(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d72c4
	if (!cr6.eq) goto loc_822D72C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D729C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d72bc
	if (cr6.gt) goto loc_822D72BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D72B0;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d72c4
	if (!cr6.lt) goto loc_822D72C4;
loc_822D72BC:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d72c8
	goto loc_822D72C8;
loc_822D72C4:
	// li r11,0
	r11.s64 = 0;
loc_822D72C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d72f0
	if (cr6.eq) goto loc_822D72F0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3684(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3684);
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
loc_822D72F0:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3680(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3680);
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

__attribute__((alias("__imp__sub_822D730C"))) PPC_WEAK_FUNC(sub_822D730C);
PPC_FUNC_IMPL(__imp__sub_822D730C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D7310"))) PPC_WEAK_FUNC(sub_822D7310);
PPC_FUNC_IMPL(__imp__sub_822D7310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d7330
	if (!cr6.eq) goto loc_822D7330;
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// blr 
	return;
loc_822D7330:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D7338"))) PPC_WEAK_FUNC(sub_822D7338);
PPC_FUNC_IMPL(__imp__sub_822D7338) {
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
	ctx.lr = 0x822D7340;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// bl 0x822d69f0
	ctx.lr = 0x822D7364;
	sub_822D69F0(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r30,88(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// beq cr6,0x822d7388
	if (cr6.eq) goto loc_822D7388;
	// addi r11,r25,5
	r11.s64 = r25.s64 + 5;
	// rlwinm r10,r25,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r29,r10,r26
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// lwzx r28,r9,r26
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + r26.u32);
loc_822D7388:
	// bl 0x821908a8
	ctx.lr = 0x822D738C;
	sub_821908A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d746c
	if (cr6.eq) goto loc_822D746C;
	// bl 0x82190880
	ctx.lr = 0x822D739C;
	sub_82190880(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x822d740c
	if (!cr6.eq) goto loc_822D740C;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D73C8:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d73f4
	if (cr6.eq) goto loc_822D73F4;
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r4,r10,0,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// bl 0x8219a7d0
	ctx.lr = 0x822D73F4;
	sub_8219A7D0(ctx, base);
loc_822D73F4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d73c8
	if (!cr0.eq) goto loc_822D73C8;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D740C:
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r28,r10,r28
	r28.u64 = ctx.r10.u64 + r28.u64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D742C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7454
	if (cr6.eq) goto loc_822D7454;
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8219a7d0
	ctx.lr = 0x822D7454;
	sub_8219A7D0(ctx, base);
loc_822D7454:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d742c
	if (!cr0.eq) goto loc_822D742C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D746C:
	// bl 0x82190880
	ctx.lr = 0x822D7470;
	sub_82190880(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d7534
	if (!cr6.eq) goto loc_822D7534;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r24,r27,16
	r24.u64 = r27.u32 & 0xFFFF;
	// add r27,r10,r28
	r27.u64 = ctx.r10.u64 + r28.u64;
	// add r26,r11,r29
	r26.u64 = r11.u64 + r29.u64;
	// subf r25,r31,r30
	r25.s64 = r30.s64 - r31.s64;
loc_822D7498:
	// lhz r11,0(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// and r10,r11,r24
	ctx.r10.u64 = r11.u64 & r24.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d751c
	if (cr6.eq) goto loc_822D751C;
	// ld r11,0(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r30,r10,0,0,28
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187f40
	ctx.lr = 0x822D74CC;
	sub_82187F40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x822d7514
	if (!cr6.gt) goto loc_822D7514;
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_822D74E0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187b88
	ctx.lr = 0x822D74EC;
	sub_82187B88(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187ba8
	ctx.lr = 0x822D7508;
	sub_82187BA8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x822d74e0
	if (cr6.lt) goto loc_822D74E0;
loc_822D7514:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187bd0
	ctx.lr = 0x822D751C;
	sub_82187BD0(ctx, base);
loc_822D751C:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// bne 0x822d7498
	if (!cr0.eq) goto loc_822D7498;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D7534:
	// bl 0x82190880
	ctx.lr = 0x822D7538;
	sub_82190880(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82187f40
	ctx.lr = 0x822D754C;
	sub_82187F40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187b88
	ctx.lr = 0x822D7558;
	sub_82187B88(ctx, base);
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75b0
	if (!cr6.lt) goto loc_822D75B0;
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D757C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d75a0
	if (cr6.eq) goto loc_822D75A0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D75A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D75A0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d757c
	if (!cr0.eq) goto loc_822D757C;
loc_822D75B0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187ba8
	ctx.lr = 0x822D75B8;
	sub_82187BA8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187bd0
	ctx.lr = 0x822D75C0;
	sub_82187BD0(ctx, base);
loc_822D75C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822D75C8"))) PPC_WEAK_FUNC(sub_822D75C8);
PPC_FUNC_IMPL(__imp__sub_822D75C8) {
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
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x822d761c
	if (cr6.eq) goto loc_822D761C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822d7610
	if (cr6.eq) goto loc_822D7610;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7610
	if (cr6.eq) goto loc_822D7610;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D7610;
	sub_82130588(ctx, base);
loc_822D7610:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82540c38
	ctx.lr = 0x822D761C;
	sub_82540C38(ctx, base);
loc_822D761C:
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

__attribute__((alias("__imp__sub_822D7638"))) PPC_WEAK_FUNC(sub_822D7638);
PPC_FUNC_IMPL(__imp__sub_822D7638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_822D7638:
	// lhz r11,20(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// li r8,0
	ctx.r8.s64 = 0;
	// addic. r9,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r9.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x822d7688
	if (cr0.lt) goto loc_822D7688;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
loc_822D764C:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// beq cr6,0x822d7680
	if (cr6.eq) goto loc_822D7680;
	// bge cr6,0x822d7670
	if (!cr6.lt) goto loc_822D7670;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// b 0x822d7674
	goto loc_822D7674;
loc_822D7670:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_822D7674:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x822d764c
	if (!cr6.gt) goto loc_822D764C;
	// b 0x822d7688
	goto loc_822D7688;
loc_822D7680:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822d7698
	if (!cr6.eq) goto loc_822D7698;
loc_822D7688:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d7638
	if (!cr6.eq) goto loc_822D7638;
	// blr 
	return;
loc_822D7698:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D76A8"))) PPC_WEAK_FUNC(sub_822D76A8);
PPC_FUNC_IMPL(__imp__sub_822D76A8) {
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
	ctx.lr = 0x822D76B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d76dc
	if (cr6.eq) goto loc_822D76DC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D76D0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822D76DC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7714
	if (cr6.eq) goto loc_822D7714;
	// li r30,0
	r30.s64 = 0;
loc_822D76F0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822db7a8
	ctx.lr = 0x822D7700;
	sub_822DB7A8(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822d76f0
	if (cr6.lt) goto loc_822D76F0;
loc_822D7714:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D7720"))) PPC_WEAK_FUNC(sub_822D7720);
PPC_FUNC_IMPL(__imp__sub_822D7720) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r31,-24880(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -24880);
	// stw r3,-24880(r11)
	PPC_STORE_U32(r11.u32 + -24880, ctx.r3.u32);
	// beq cr6,0x822d7750
	if (cr6.eq) goto loc_822D7750;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_822D7750:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822d7784
	if (cr6.eq) goto loc_822D7784;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bne 0x822d7784
	if (!cr0.eq) goto loc_822D7784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D7784:
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

__attribute__((alias("__imp__sub_822D7798"))) PPC_WEAK_FUNC(sub_822D7798);
PPC_FUNC_IMPL(__imp__sub_822D7798) {
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
	ctx.lr = 0x822D77A0;
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
	ctx.lr = 0x822D77D4;
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
	// beq cr6,0x822d7840
	if (cr6.eq) goto loc_822D7840;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82490d00
	ctx.lr = 0x822D7824;
	sub_82490D00(ctx, base);
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
loc_822D7840:
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

__attribute__((alias("__imp__sub_822D7854"))) PPC_WEAK_FUNC(sub_822D7854);
PPC_FUNC_IMPL(__imp__sub_822D7854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D7858"))) PPC_WEAK_FUNC(sub_822D7858);
PPC_FUNC_IMPL(__imp__sub_822D7858) {
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
	ctx.lr = 0x822D7860;
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
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D7894;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D78A8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82491010
	ctx.lr = 0x822D78BC;
	sub_82491010(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D78C4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D78D4"))) PPC_WEAK_FUNC(sub_822D78D4);
PPC_FUNC_IMPL(__imp__sub_822D78D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D78D8"))) PPC_WEAK_FUNC(sub_822D78D8);
PPC_FUNC_IMPL(__imp__sub_822D78D8) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r10,-13384
	ctx.r9.s64 = ctx.r10.s64 + -13384;
	// lbz r8,-14373(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d7934
	if (cr6.eq) goto loc_822D7934;
	// lhz r11,36(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7934
	if (cr6.eq) goto loc_822D7934;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13416
	ctx.r3.s64 = ctx.r10.s64 + -13416;
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lwz r5,240(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 240);
	// lwz r4,244(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 244);
	// bl 0x82130000
	ctx.lr = 0x822D7934;
	sub_82130000(ctx, base);
loc_822D7934:
	// addi r31,r30,32
	r31.s64 = r30.s64 + 32;
	// lhz r5,38(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d6998
	ctx.lr = 0x822D7948;
	sub_822D6998(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// sth r11,36(r30)
	PPC_STORE_U16(r30.u32 + 36, r11.u16);
	// sth r11,38(r30)
	PPC_STORE_U16(r30.u32 + 38, r11.u16);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x822D7960;
	sub_82130588(ctx, base);
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x822D7968;
	sub_82130588(ctx, base);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d7988
	if (cr6.eq) goto loc_822D7988;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D7988:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d79a8
	if (cr6.eq) goto loc_822D79A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D79A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D79A8:
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d79c0
	if (cr6.eq) goto loc_822D79C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822d6998
	ctx.lr = 0x822D79C0;
	sub_822D6998(ctx, base);
loc_822D79C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2810
	ctx.lr = 0x822D79C8;
	sub_821D2810(ctx, base);
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

__attribute__((alias("__imp__sub_822D79E0"))) PPC_WEAK_FUNC(sub_822D79E0);
PPC_FUNC_IMPL(__imp__sub_822D79E0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x822D79E8;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-12720(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12720);
	// lbz r10,6212(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6212);
	// stb r10,-14389(r31)
	PPC_STORE_U8(r31.u32 + -14389, ctx.r10.u8);
	// stb r8,6212(r11)
	PPC_STORE_U8(r11.u32 + 6212, ctx.r8.u8);
	// lwz r3,-12720(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12720);
	// bl 0x821d33b0
	ctx.lr = 0x822D7A18;
	sub_821D33B0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lbz r6,-14389(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + -14389);
	// addi r27,r11,3628
	r27.s64 = r11.s64 + 3628;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stfs f1,3652(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 3652, temp.u32);
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x822d7a68
	if (cr6.eq) goto loc_822D7A68;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,3660(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3660);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7a98
	if (!cr6.lt) goto loc_822D7A98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f12,f11,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// b 0x822d7abc
	goto loc_822D7ABC;
loc_822D7A68:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,3656(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3656);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7a98
	if (!cr6.lt) goto loc_822D7A98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f12,f11,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// b 0x822d7abc
	goto loc_822D7ABC;
loc_822D7A98:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fnmsubs f13,f12,f11,f13
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7ac0
	if (!cr6.lt) goto loc_822D7AC0;
loc_822D7ABC:
	// stfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
loc_822D7AC0:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r29,-32130
	r29.s64 = -2105671680;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lbz r11,-14375(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -14375);
	// addi r31,r10,-14240
	r31.s64 = ctx.r10.s64 + -14240;
	// lwz r8,22080(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// addi r7,r9,-14444
	ctx.r7.s64 = ctx.r9.s64 + -14444;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7b48
	if (cr6.eq) goto loc_822D7B48;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f13,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f12,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,240
	ctx.r9.s64 = r11.s64 + 240;
	// lfs f11,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f6,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f1,f11
	cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// ble cr6,0x822d7b48
	if (!cr6.gt) goto loc_822D7B48;
	// li r11,1
	r11.s64 = 1;
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
loc_822D7B48:
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lbz r11,-14374(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + -14374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7b68
	if (cr6.eq) goto loc_822D7B68;
	// li r11,1
	r11.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
	// stb r9,-14374(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14374, ctx.r9.u8);
loc_822D7B68:
	// addi r11,r8,45
	r11.s64 = ctx.r8.s64 + 45;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x822bff40
	ctx.lr = 0x822D7B7C;
	sub_822BFF40(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r30,r11,-12976
	r30.s64 = r11.s64 + -12976;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,22080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x822bff40
	ctx.lr = 0x822D7BA0;
	sub_822BFF40(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,11364(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11364);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217ce78
	ctx.lr = 0x822D7BB4;
	sub_8217CE78(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f30,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8217ce70
	ctx.lr = 0x822D7BC8;
	sub_8217CE70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8217ce78
	ctx.lr = 0x822D7BD4;
	sub_8217CE78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8217ce70
	ctx.lr = 0x822D7BE0;
	sub_8217CE70(ctx, base);
	// li r4,112
	ctx.r4.s64 = 112;
	// li r3,96
	ctx.r3.s64 = 96;
	// lvlx128 v58,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v62,r31,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v59,v63,v57,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822D7C44;
	sub_8217CE80(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// addi r3,r4,-14348
	ctx.r3.s64 = ctx.r4.s64 + -14348;
	// lbz r11,1(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7c68
	if (cr6.eq) goto loc_822D7C68;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-11984
	r11.s64 = r11.s64 + -11984;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x822d7c6c
	goto loc_822D7C6C;
loc_822D7C68:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
loc_822D7C6C:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvlx128 v56,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r9,48
	ctx.r9.s64 = 48;
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v54,r11,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822D7CC8;
	sub_8217CE80(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r5,r8,-14368
	ctx.r5.s64 = ctx.r8.s64 + -14368;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-14428(r7)
	PPC_STORE_U32(ctx.r7.u32 + -14428, r11.u32);
	// stw r10,-14372(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14372, ctx.r10.u32);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D7D00"))) PPC_WEAK_FUNC(sub_822D7D00);
PPC_FUNC_IMPL(__imp__sub_822D7D00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCVRegister v117{};
	PPCVRegister v118{};
	PPCVRegister v119{};
	PPCVRegister v120{};
	PPCVRegister v121{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x822D7D08;
	// stfd f29,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f29.u64);
	// stfd f30,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, f30.u64);
	// stfd f31,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd4fc
	ctx.lr = 0x822D7D1C;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f2,708(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// addi r21,r30,208
	r21.s64 = r30.s64 + 208;
	// fmr f30,f4
	f30.f64 = ctx.f4.f64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r11,292(r30)
	PPC_STORE_U16(r30.u32 + 292, r11.u16);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// bl 0x822d6240
	ctx.lr = 0x822D7D54;
	sub_822D6240(ctx, base);
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v59,r0,r21
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,-31568
	ctx.r7.s64 = ctx.r9.s64 + -31568;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v58,r21,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r3,r5,2240
	ctx.r3.s64 = ctx.r5.s64 + 2240;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r4,-31648
	ctx.r9.s64 = ctx.r4.s64 + -31648;
	// addi r8,r11,-31664
	ctx.r8.s64 = r11.s64 + -31664;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r5,r7,-13504
	ctx.r5.s64 = ctx.r7.s64 + -13504;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r17,r30,268
	r17.s64 = r30.s64 + 268;
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-12736
	ctx.r4.s64 = ctx.r6.s64 + -12736;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v53,v57,v62
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v56,r0,r17
	temp.u32 = r17.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r20,r11,3677
	r20.s64 = r11.s64 + 3677;
	// addi r11,r1,708
	r11.s64 = ctx.r1.s64 + 708;
	// vspltw128 v125,v56,0
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// li r10,-41
	ctx.r10.s64 = -41;
	// vspltw128 v123,v63,0
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v124,r0,r4
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v122,r0,r3
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vor128 v126,v122,v122
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v54,r20,r10
	temp.u32 = r20.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r24,0
	r24.s64 = 0;
	// vspltw128 v118,v54,0
	simde_mm_store_si128((simde__m128i*)v118.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stvx128 v125,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v117,v55,0
	simde_mm_store_si128((simde__m128i*)v117.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// stvx128 v123,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v119,v63,3
	simde_mm_store_si128((simde__m128i*)v119.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vmsum3fp128 v52,v53,v53
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vaddfp128 v51,v53,v59
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v120,v63,1
	simde_mm_store_si128((simde__m128i*)v120.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// vspltw128 v121,v63,2
	simde_mm_store_si128((simde__m128i*)v121.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vrsqrtefp128 v50,v52
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// vor128 v12,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vcmpeqfp128 v11,v50,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v52,v6
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel128 v124,v51,v49,v124
	// stvx128 v124,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r11,-14240
	r28.s64 = r11.s64 + -14240;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// li r22,112
	r22.s64 = 112;
	// li r23,96
	r23.s64 = 96;
	// addi r27,r10,-12976
	r27.s64 = ctx.r10.s64 + -12976;
	// addi r26,r11,-14352
	r26.s64 = r11.s64 + -14352;
	// addi r25,r9,-14348
	r25.s64 = ctx.r9.s64 + -14348;
loc_822D7E84:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x822d7eb0
	if (!cr6.eq) goto loc_822D7EB0;
	// lbz r11,1(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7ea8
	if (cr6.eq) goto loc_822D7EA8;
	// lbz r11,1(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7ec8
	if (cr6.eq) goto loc_822D7EC8;
loc_822D7EA8:
	// mr r31,r28
	r31.u64 = r28.u64;
	// b 0x822d7ecc
	goto loc_822D7ECC;
loc_822D7EB0:
	// lbz r11,1(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7fb0
	if (cr6.eq) goto loc_822D7FB0;
	// lbz r11,1(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7fb0
	if (cr6.eq) goto loc_822D7FB0;
loc_822D7EC8:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D7ECC:
	// lvx128 v48,r31,r23
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v122,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v122.u32), 0xAA));
	// vspltw128 v47,v48,1
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xAA));
	// lvx128 v127,r31,r22
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0xAA));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vcmpgtfp128 v12,v47,v121
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v121.f32)));
	// vsel v11,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vrlimi128 v126,v11,4,1
	simde_mm_store_ps(v126.f32, simde_mm_blend_ps(simde_mm_load_ps(v126.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v11.f32), 147), 4));
	// vor128 v1,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// bl 0x8217c148
	ctx.lr = 0x822D7EF8;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d7f04
	if (cr6.eq) goto loc_822D7F04;
	// li r29,1
	r29.s64 = 1;
loc_822D7F04:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x822d6b78
	ctx.lr = 0x822D7F14;
	sub_822D6B78(ctx, base);
	// lvx128 v3,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x822d7f44
	if (!cr6.eq) goto loc_822D7F44;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x822d7f40
	if (cr6.eq) goto loc_822D7F40;
	// li r11,112
	r11.s64 = 112;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v1,r28,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822d6b78
	ctx.lr = 0x822D7F38;
	sub_822D6B78(ctx, base);
	// lvx128 v125,r0,r3
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822d7f44
	goto loc_822D7F44;
loc_822D7F40:
	// vor128 v125,v3,v3
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
loc_822D7F44:
	// vcmpgtfp128. v46,v3,v119
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v119.f32)));
	cr6.setFromMask(simde_mm_load_ps(v46.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7f64
	if (cr6.eq) goto loc_822D7F64;
	// vcmpgtfp128 v0,v120,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v120.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vor128 v13,v120,v120
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v120.u8));
	// vsel v3,v3,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
loc_822D7F64:
	// vcmpgtfp128. v45,v3,v118
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v118.f32)));
	cr6.setFromMask(simde_mm_load_ps(v45.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7f7c
	if (cr6.eq) goto loc_822D7F7C;
	// li r29,0
	r29.s64 = 0;
loc_822D7F7C:
	// vcmpgtfp128 v0,v123,v3
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vor128 v13,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// vsel v12,v13,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vor128 v123,v12,v12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// beq cr6,0x822d7fa4
	if (cr6.eq) goto loc_822D7FA4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D7FA4:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpwi cr6,r24,2
	cr6.compare<int32_t>(r24.s32, 2, xer);
	// blt cr6,0x822d7e84
	if (cr6.lt) goto loc_822D7E84;
loc_822D7FB0:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,252(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v123,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// lfs f0,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// stfs f0,260(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 260, temp.u32);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stfs f13,0(r17)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// lfs f13,-14400(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14400);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bge cr6,0x822d8020
	if (!cr6.lt) goto loc_822D8020;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8020
	if (!cr6.eq) goto loc_822D8020;
	// lwz r9,-41(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + -41);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d8020
	if (!cr6.lt) goto loc_822D8020;
	// stfs f0,-14400(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14400, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14436(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14436, r11.u32);
loc_822D8020:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14404(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14404);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d8060
	if (!cr6.lt) goto loc_822D8060;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8060
	if (!cr6.eq) goto loc_822D8060;
	// lhz r9,292(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8060
	if (cr6.eq) goto loc_822D8060;
	// stfs f0,-14404(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14404, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14432(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14432, r11.u32);
loc_822D8060:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d80ac
	if (!cr6.gt) goto loc_822D80AC;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d808c
	if (!cr6.eq) goto loc_822D808C;
	// lwz r9,252(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822d80ac
	if (!cr6.eq) goto loc_822D80AC;
loc_822D808C:
	// lhz r9,292(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d80ac
	if (!cr6.eq) goto loc_822D80AC;
	// stfs f0,-14440(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14440, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14448(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14448, r11.u32);
loc_822D80AC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14396(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14396);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d80ec
	if (!cr6.gt) goto loc_822D80EC;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d80ec
	if (cr6.eq) goto loc_822D80EC;
	// lhz r10,292(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d80ec
	if (cr6.eq) goto loc_822D80EC;
	// stfs f0,-14396(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14396, temp.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14424(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14424, r11.u32);
loc_822D80EC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8330
	if (cr6.eq) goto loc_822D8330;
	// lbz r11,0(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + 0);
	// li r31,224
	r31.s64 = 224;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8140
	if (cr6.eq) goto loc_822D8140;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lvx128 v1,r0,r21
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r30,r31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174678
	ctx.lr = 0x822D811C;
	sub_82174678(ctx, base);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821749d0
	ctx.lr = 0x822D812C;
	sub_821749D0(ctx, base);
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// sth r9,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r9.u16);
	// b 0x822d815c
	goto loc_822D815C;
loc_822D8140:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d6f80
	ctx.lr = 0x822D8150;
	sub_822D6F80(ctx, base);
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// or r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 | r11.u64;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D815C:
	// vcmpgtfp128. v44,v117,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v117.f32), simde_mm_load_ps(v125.f32)));
	cr6.setFromMask(simde_mm_load_ps(v44.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d8200
	if (cr6.eq) goto loc_822D8200;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw128 v43,-1
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// vspltw128 v42,v124,3
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), 0x0));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,240
	ctx.r8.s64 = 240;
	// vslw128 v41,v43,v43
	v41.u32[0] = v43.u32[0] << (v43.u8[0] & 0x1F);
	v41.u32[1] = v43.u32[1] << (v43.u8[4] & 0x1F);
	v41.u32[2] = v43.u32[2] << (v43.u8[8] & 0x1F);
	v41.u32[3] = v43.u32[3] << (v43.u8[12] & 0x1F);
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v39,r11,r31
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r8
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v37,v39,v40
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xEF));
	// vmsum3fp128 v36,v39,v38
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vsubfp128 v63,v37,v36
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v36.f32)));
	// vandc128 v35,v63,v41
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vsubfp128 v34,v35,v42
	simde_mm_store_ps(v34.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v42.f32)));
	// vcmpgtfp128. v33,v119,v34
	simde_mm_store_ps(v33.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v119.f32), simde_mm_load_ps(v34.f32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d81dc
	if (cr6.eq) goto loc_822D81DC;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,12
	ctx.r10.u64 = r11.u64 | 12;
	// b 0x822d81fc
	goto loc_822D81FC;
loc_822D81DC:
	// vcmpgtfp128. v32,v119,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v119.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// bne cr6,0x822d81fc
	if (!cr6.eq) goto loc_822D81FC;
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
loc_822D81FC:
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8200:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// vor128 v1,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// lwz r11,-12284(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12284);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x8217c148
	ctx.lr = 0x822D8214;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d8228
	if (cr6.eq) goto loc_822D8228;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,1024
	ctx.r10.u64 = r11.u64 | 1024;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8228:
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822d82a4
	if (!cr6.lt) goto loc_822D82A4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// ori r9,r11,240
	ctx.r9.u64 = r11.u64 | 240;
	// sth r9,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r9.u16);
	// lwz r31,-7572(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// lbz r8,14546(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d8284
	if (!cr6.eq) goto loc_822D8284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D825C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d827c
	if (cr6.gt) goto loc_822D827C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8270;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d8284
	if (!cr6.lt) goto loc_822D8284;
loc_822D827C:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d8288
	goto loc_822D8288;
loc_822D8284:
	// li r11,0
	r11.s64 = 0;
loc_822D8288:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d82a4
	if (cr6.eq) goto loc_822D82A4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,28,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82A4:
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x822d82cc
	if (!cr6.lt) goto loc_822D82CC;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// ori r10,r11,256
	ctx.r10.u64 = r11.u64 | 256;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82CC:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x822d82e0
	if (!cr6.lt) goto loc_822D82E0;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,2048
	ctx.r10.u64 = r11.u64 | 2048;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82E0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x822d8324
	if (!cr6.lt) goto loc_822D8324;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8324:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d6540
	ctx.lr = 0x822D832C;
	sub_822D6540(ctx, base);
	// bl 0x822d6498
	ctx.lr = 0x822D8330;
	sub_822D6498(ctx, base);
loc_822D8330:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd794
	ctx.lr = 0x822D833C;
	// lfd f29,-152(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f30,-144(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_822D834C"))) PPC_WEAK_FUNC(sub_822D834C);
PPC_FUNC_IMPL(__imp__sub_822D834C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D8350"))) PPC_WEAK_FUNC(sub_822D8350);
PPC_FUNC_IMPL(__imp__sub_822D8350) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822D8358;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82130000
	ctx.lr = 0x822D8378;
	sub_82130000(ctx, base);
	// lis r21,-32120
	r21.s64 = -2105016320;
	// lwz r31,-7572(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lbz r10,14546(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d83bc
	if (!cr6.eq) goto loc_822D83BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8394;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d83b4
	if (cr6.gt) goto loc_822D83B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D83A8;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d83bc
	if (!cr6.lt) goto loc_822D83BC;
loc_822D83B4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d83c0
	goto loc_822D83C0;
loc_822D83BC:
	// li r11,0
	r11.s64 = 0;
loc_822D83C0:
	// rlwinm r10,r30,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822d879c
	if (!cr6.eq) goto loc_822D879C;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d878c
	if (!cr6.eq) goto loc_822D878C;
	// lis r12,258
	r12.s64 = 16908288;
	// ori r12,r12,6652
	r12.u64 = r12.u64 | 6652;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d875c
	if (cr6.eq) goto loc_822D875C;
	// bl 0x821908a8
	ctx.lr = 0x822D83F4;
	sub_821908A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d840c
	if (!cr6.eq) goto loc_822D840C;
	// rlwinm r11,r30,0,28,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d840c
	if (cr6.eq) goto loc_822D840C;
	// bl 0x8233a5a0
	ctx.lr = 0x822D840C;
	sub_8233A5A0(ctx, base);
loc_822D840C:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8420;
	sub_822D7338(ctx, base);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D8438;
	sub_822D69F0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d846c
	if (cr6.eq) goto loc_822D846C;
	// rlwinm r11,r30,0,7,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FFFFFC;
	// rlwinm r11,r11,0,28,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF00000F;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d846c
	if (cr6.eq) goto loc_822D846C;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D846C;
	sub_822D7338(ctx, base);
loc_822D846C:
	// rlwinm r29,r30,0,23,27
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d848c
	if (cr6.eq) goto loc_822D848C;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D848C;
	sub_822D7338(ctx, base);
loc_822D848C:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D84A4;
	sub_822D69F0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// addi r26,r11,3624
	r26.s64 = r11.s64 + 3624;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d8590
	if (cr6.eq) goto loc_822D8590;
	// rlwinm r11,r30,0,19,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8590
	if (cr6.eq) goto loc_822D8590;
	// lbz r11,54(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 54);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8534
	if (cr6.eq) goto loc_822D8534;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d8534
	if (cr6.eq) goto loc_822D8534;
	// bl 0x82190880
	ctx.lr = 0x822D84E8;
	sub_82190880(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822D84F4;
	sub_82190870(ctx, base);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8504
	if (cr6.eq) goto loc_822D8504;
	// bl 0x822dacf0
	ctx.lr = 0x822D8504;
	sub_822DACF0(ctx, base);
loc_822D8504:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8518;
	sub_822D7338(ctx, base);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8528
	if (cr6.eq) goto loc_822D8528;
	// bl 0x822dacc8
	ctx.lr = 0x822D8528;
	sub_822DACC8(ctx, base);
loc_822D8528:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82190870
	ctx.lr = 0x822D8530;
	sub_82190870(ctx, base);
	// b 0x822d8590
	goto loc_822D8590;
loc_822D8534:
	// lis r29,-32120
	r29.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822D8550;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8558;
	sub_82190890(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8570;
	sub_822D7338(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8578;
	sub_82190890(ctx, base);
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822D8590;
	sub_823112C0(ctx, base);
loc_822D8590:
	// lbz r11,-4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d85d0
	if (cr6.eq) goto loc_822D85D0;
	// lfs f13,268(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d85d0
	if (!cr6.lt) goto loc_822D85D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D85B4;
	sub_82190890(ctx, base);
	// lwz r11,-14472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822daac8
	ctx.lr = 0x822D85C8;
	sub_822DAAC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190890
	ctx.lr = 0x822D85D0;
	sub_82190890(ctx, base);
loc_822D85D0:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D85E8;
	sub_822D69F0(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// addi r10,r11,-14420
	ctx.r10.s64 = r11.s64 + -14420;
	// lwz r3,-14344(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -14344);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8610;
	sub_8218F8D0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8618;
	sub_82190890(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82190880
	ctx.lr = 0x822D8620;
	sub_82190880(ctx, base);
	// lis r12,258
	r12.s64 = 16908288;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// ori r12,r12,12
	r12.u64 = r12.u64 | 12;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// and r29,r30,r12
	r29.u64 = r30.u64 & r12.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d86a8
	if (cr6.eq) goto loc_822D86A8;
	// rlwinm r11,r30,0,28,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8660
	if (cr6.eq) goto loc_822D8660;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822D8654;
	sub_822F7338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8233a5a0
	ctx.lr = 0x822D865C;
	sub_8233A5A0(ctx, base);
	// b 0x822d8688
	goto loc_822D8688;
loc_822D8660:
	// rlwinm r11,r30,0,7,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0000;
	// rlwinm r11,r11,0,14,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF03FFFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8694
	if (cr6.eq) goto loc_822D8694;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8688
	if (!cr6.eq) goto loc_822D8688;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822D8688;
	sub_822F7338(ctx, base);
loc_822D8688:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822D8694;
	sub_822F74F0(ctx, base);
loc_822D8694:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822D86A4;
	sub_822F3918(ctx, base);
	// b 0x822d86c0
	goto loc_822D86C0;
loc_822D86A8:
	// rlwinm r11,r30,0,19,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d86c0
	if (cr6.eq) goto loc_822D86C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822D86C0;
	sub_82190870(ctx, base);
loc_822D86C0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D86D4;
	sub_822D7338(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d8734
	if (cr6.eq) goto loc_822D8734;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822D86E8;
	sub_822F74F0(ctx, base);
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8704
	if (!cr6.eq) goto loc_822D8704;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822f7338
	ctx.lr = 0x822D8700;
	sub_822F7338(ctx, base);
	// b 0x822d870c
	goto loc_822D870C;
loc_822D8704:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822f7480
	ctx.lr = 0x822D870C;
	sub_822F7480(ctx, base);
loc_822D870C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822D871C;
	sub_822F3918(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8724;
	sub_82190890(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r3,-14344(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -14344);
	// lwz r4,-14408(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14408);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8734;
	sub_8218F8D0(ctx, base);
loc_822D8734:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d8744
	if (cr6.eq) goto loc_822D8744;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8744;
	sub_82190890(ctx, base);
loc_822D8744:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82190870
	ctx.lr = 0x822D8754;
	sub_82190870(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_822D875C:
	// rlwinm r11,r30,0,11,13
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1C0000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x822d879c
	if (cr6.eq) goto loc_822D879C;
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x822d8794
	if (cr6.eq) goto loc_822D8794;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x822d87b0
	if (!cr6.eq) goto loc_822D87B0;
loc_822D878C:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822d87a0
	goto loc_822D87A0;
loc_822D8794:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822d87a0
	goto loc_822D87A0;
loc_822D879C:
	// li r5,1
	ctx.r5.s64 = 1;
loc_822D87A0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D87B0;
	sub_822D7338(ctx, base);
loc_822D87B0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_822D87B8"))) PPC_WEAK_FUNC(sub_822D87B8);
PPC_FUNC_IMPL(__imp__sub_822D87B8) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822D87C0;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// addi r23,r11,3648
	r23.s64 = r11.s64 + 3648;
	// bne cr6,0x822d87fc
	if (!cr6.eq) goto loc_822D87FC;
	// lfs f13,268(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-32(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822d8bac
	if (cr6.gt) goto loc_822D8BAC;
loc_822D87FC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3676(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3676);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d8818
	if (!cr6.eq) goto loc_822D8818;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d8830
	if (cr6.eq) goto loc_822D8830;
loc_822D8818:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3664);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d8834
	if (cr6.lt) goto loc_822D8834;
loc_822D8830:
	// li r11,0
	r11.s64 = 0;
loc_822D8834:
	// rlwinm r10,r26,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x7FE;
	// lwz r9,252(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 252);
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC03;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// bne cr6,0x822d8884
	if (!cr6.eq) goto loc_822D8884;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8884
	if (cr6.eq) goto loc_822D8884;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8884
	if (!cr6.eq) goto loc_822D8884;
	// lbz r11,296(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 296);
	// rlwinm r7,r11,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822d8888
	if (!cr6.eq) goto loc_822D8888;
loc_822D8884:
	// li r11,0
	r11.s64 = 0;
loc_822D8888:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r25,-32120
	r25.s64 = -2105016320;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d88bc
	if (!cr6.eq) goto loc_822D88BC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d88b4
	if (!cr6.eq) goto loc_822D88B4;
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d88bc
	if (!cr6.eq) goto loc_822D88BC;
loc_822D88B4:
	// li r11,0
	r11.s64 = 0;
	// b 0x822d88c0
	goto loc_822D88C0;
loc_822D88BC:
	// li r11,1
	r11.s64 = 1;
loc_822D88C0:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d88ec
	if (!cr6.eq) goto loc_822D88EC;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d88ec
	if (cr6.eq) goto loc_822D88EC;
	// rlwinm r11,r26,0,11,20
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1FF800;
	// rlwinm r11,r11,0,19,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFE1FFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d88f0
	if (!cr6.eq) goto loc_822D88F0;
loc_822D88EC:
	// li r11,0
	r11.s64 = 0;
loc_822D88F0:
	// lis r27,-32120
	r27.s64 = -2105016320;
	// rlwinm r7,r26,0,23,27
	ctx.r7.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1F0;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// beq cr6,0x822d891c
	if (cr6.eq) goto loc_822D891C;
	// lbz r11,370(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 370);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d891c
	if (cr6.eq) goto loc_822D891C;
	// li r30,1
	r30.s64 = 1;
	// li r31,0
	r31.s64 = 0;
loc_822D891C:
	// rlwinm r11,r26,0,7,7
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8968
	if (cr6.eq) goto loc_822D8968;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r7,-14391(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -14391);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822d8958
	if (!cr6.eq) goto loc_822D8958;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d8958
	if (!cr6.eq) goto loc_822D8958;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3668);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d895c
	if (cr6.lt) goto loc_822D895C;
loc_822D8958:
	// li r11,0
	r11.s64 = 0;
loc_822D895C:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r30,r11,27,31,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_822D8968:
	// rlwinm r11,r26,0,28,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d89a8
	if (cr6.eq) goto loc_822D89A8;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d898c
	if (!cr6.eq) goto loc_822D898C;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8990
	if (!cr6.eq) goto loc_822D8990;
loc_822D898C:
	// li r31,0
	r31.s64 = 0;
loc_822D8990:
	// lbz r11,393(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 393);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d89a8
	if (cr6.eq) goto loc_822D89A8;
	// li r31,1
	r31.s64 = 1;
	// li r30,0
	r30.s64 = 0;
loc_822D89A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f29,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f0
	f31.f64 = f0.f64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// beq cr6,0x822d8a3c
	if (cr6.eq) goto loc_822D8A3C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f12,288(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3720(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3720);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x822d89e4
	if (cr6.lt) goto loc_822D89E4;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
loc_822D89E4:
	// fcmpu cr6,f13,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f29.f64);
	// bge cr6,0x822d89fc
	if (!cr6.lt) goto loc_822D89FC;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x822d89fc
	if (cr6.eq) goto loc_822D89FC;
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
loc_822D89FC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfs f13,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fsubs f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fsubs f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsel f7,f9,f9,f29
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsel f31,f8,f10,f0
	f31.f64 = ctx.f8.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fnmsubs f30,f7,f13,f0
	f30.f64 = double(float(-(ctx.f7.f64 * ctx.f13.f64 - f0.f64)));
	// bl 0x822e59e8
	ctx.lr = 0x822D8A2C;
	sub_822E59E8(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822e5ad0
	ctx.lr = 0x822D8A38;
	sub_822E5AD0(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
loc_822D8A3C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8a50
	if (!cr6.eq) goto loc_822D8A50;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8a6c
	if (cr6.eq) goto loc_822D8A6C;
loc_822D8A50:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// clrlwi r5,r24,16
	ctx.r5.u64 = r24.u32 & 0xFFFF;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822d8350
	ctx.lr = 0x822D8A68;
	sub_822D8350(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
loc_822D8A6C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8a80
	if (!cr6.eq) goto loc_822D8A80;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8bac
	if (cr6.eq) goto loc_822D8BAC;
loc_822D8A80:
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// lis r12,20
	r12.s64 = 1310720;
	// ori r12,r12,24576
	r12.u64 = r12.u64 | 24576;
	// and r11,r26,r12
	r11.u64 = r26.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d8b88
	if (!cr6.eq) goto loc_822D8B88;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8ad4
	if (cr6.eq) goto loc_822D8AD4;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822e5ad0
	ctx.lr = 0x822D8AB0;
	sub_822E5AD0(ctx, base);
	// lbz r11,-27(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + -27);
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r3,12
	ctx.r3.s64 = 12;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ac8
	if (cr6.eq) goto loc_822D8AC8;
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
loc_822D8AC8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x822D8AD4;
	sub_8217F768(ctx, base);
loc_822D8AD4:
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// lwz r10,244(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r31,8(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwzx r29,r8,r7
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// li r30,-1
	r30.s64 = -1;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// bne cr6,0x822d8b58
	if (!cr6.eq) goto loc_822D8B58;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822D8B20;
	sub_8217C088(ctx, base);
	// bl 0x82187bf0
	ctx.lr = 0x822D8B24;
	sub_82187BF0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-7572(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822D8B34;
	sub_82205248(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8b4c
	if (cr6.eq) goto loc_822D8B4C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3684(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3684);
	// b 0x822d8b54
	goto loc_822D8B54;
loc_822D8B4C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3680(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3680);
loc_822D8B54:
	// bl 0x82187be0
	ctx.lr = 0x822D8B58;
	sub_82187BE0(ctx, base);
loc_822D8B58:
	// lis r11,8
	r11.s64 = 524288;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r26,r11
	ctx.r10.s64 = r11.s64 - r26.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r5,r9,28,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x2;
	// bl 0x82190bd8
	ctx.lr = 0x822D8B78;
	sub_82190BD8(ctx, base);
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// bne cr6,0x822d8b88
	if (!cr6.eq) goto loc_822D8B88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187be0
	ctx.lr = 0x822D8B88;
	sub_82187BE0(ctx, base);
loc_822D8B88:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8bac
	if (cr6.eq) goto loc_822D8BAC;
	// li r3,12
	ctx.r3.s64 = 12;
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x822D8BA0;
	sub_8217F768(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e62c0
	ctx.lr = 0x822D8BAC;
	sub_822E62C0(ctx, base);
loc_822D8BAC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_822D8BC0"))) PPC_WEAK_FUNC(sub_822D8BC0);
PPC_FUNC_IMPL(__imp__sub_822D8BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d8be0
	if (!cr6.eq) goto loc_822D8BE0;
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// b 0x822d7638
	sub_822D7638(ctx, base);
	return;
loc_822D8BE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D8BE8"))) PPC_WEAK_FUNC(sub_822D8BE8);
PPC_FUNC_IMPL(__imp__sub_822D8BE8) {
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
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d8c1c
	if (cr6.eq) goto loc_822D8C1C;
	// bl 0x8217d890
	ctx.lr = 0x822D8C10;
	sub_8217D890(ctx, base);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
loc_822D8C1C:
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821b5a60
	ctx.lr = 0x822D8C24;
	sub_821B5A60(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,295(r31)
	PPC_STORE_U8(r31.u32 + 295, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stb r11,296(r31)
	PPC_STORE_U8(r31.u32 + 296, r11.u8);
	// bl 0x822d68f8
	ctx.lr = 0x822D8C40;
	sub_822D68F8(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lbz r8,-14373(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + -14373);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8c5c
	if (cr6.eq) goto loc_822D8C5C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13372
	ctx.r3.s64 = r11.s64 + -13372;
	// bl 0x82130000
	ctx.lr = 0x822D8C5C;
	sub_82130000(ctx, base);
loc_822D8C5C:
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

__attribute__((alias("__imp__sub_822D8C74"))) PPC_WEAK_FUNC(sub_822D8C74);
PPC_FUNC_IMPL(__imp__sub_822D8C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D8C78"))) PPC_WEAK_FUNC(sub_822D8C78);
PPC_FUNC_IMPL(__imp__sub_822D8C78) {
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
	ctx.lr = 0x822D8C80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,4
	r30.s64 = 4;
	// addi r31,r29,128
	r31.s64 = r29.s64 + 128;
loc_822D8C90:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ca8
	if (cr6.eq) goto loc_822D8CA8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CA8;
	sub_82130588(ctx, base);
loc_822D8CA8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8c90
	if (!cr0.lt) goto loc_822D8C90;
	// lhz r11,86(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 86);
	// addi r31,r29,80
	r31.s64 = r29.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8cc8
	if (cr6.eq) goto loc_822D8CC8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CC8;
	sub_82130588(ctx, base);
loc_822D8CC8:
	// li r30,4
	r30.s64 = 4;
loc_822D8CCC:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ce4
	if (cr6.eq) goto loc_822D8CE4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CE4;
	sub_82130588(ctx, base);
loc_822D8CE4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8ccc
	if (!cr0.lt) goto loc_822D8CCC;
	// addi r31,r29,40
	r31.s64 = r29.s64 + 40;
	// li r30,4
	r30.s64 = 4;
loc_822D8CF4:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8d0c
	if (cr6.eq) goto loc_822D8D0C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8D0C;
	sub_82130588(ctx, base);
loc_822D8D0C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8cf4
	if (!cr0.lt) goto loc_822D8CF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D8D1C"))) PPC_WEAK_FUNC(sub_822D8D1C);
PPC_FUNC_IMPL(__imp__sub_822D8D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D8D20"))) PPC_WEAK_FUNC(sub_822D8D20);
PPC_FUNC_IMPL(__imp__sub_822D8D20) {
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
	// bl 0x822d78d8
	ctx.lr = 0x822D8D40;
	sub_822D78D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8d58
	if (cr6.eq) goto loc_822D8D58;
	// bl 0x82130588
	ctx.lr = 0x822D8D54;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D8D58:
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

__attribute__((alias("__imp__sub_822D8D70"))) PPC_WEAK_FUNC(sub_822D8D70);
PPC_FUNC_IMPL(__imp__sub_822D8D70) {
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
	ctx.lr = 0x822D8D78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x822D8D84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8da8
	if (cr6.eq) goto loc_822D8DA8;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-13236
	ctx.r4.s64 = ctx.r10.s64 + -13236;
	// lwz r5,-25360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// bl 0x8218fad0
	ctx.lr = 0x822D8DA0;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x822d8dac
	goto loc_822D8DAC;
loc_822D8DA8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822D8DAC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r11,-14344
	r11.s64 = r11.s64 + -14344;
	// addi r4,r10,-13256
	ctx.r4.s64 = ctx.r10.s64 + -13256;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x822D8DCC;
	sub_82182150(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-13280
	ctx.r3.s64 = ctx.r9.s64 + -13280;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// bl 0x821c9790
	ctx.lr = 0x822D8DE4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8DF0;
	sub_822D7638(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-13304
	ctx.r3.s64 = ctx.r7.s64 + -13304;
	// stw r11,-14420(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14420, r11.u32);
	// addi r29,r8,-14420
	r29.s64 = ctx.r8.s64 + -14420;
	// bl 0x821c9790
	ctx.lr = 0x822D8E14;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8E20;
	sub_822D7638(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-13332
	ctx.r3.s64 = ctx.r6.s64 + -13332;
	// bl 0x821c9790
	ctx.lr = 0x822D8E38;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8E44;
	sub_822D7638(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D8E50"))) PPC_WEAK_FUNC(sub_822D8E50);
PPC_FUNC_IMPL(__imp__sub_822D8E50) {
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
	ctx.lr = 0x822D8E58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,-7572(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lwz r31,-14428(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14428);
	// lbz r9,14546(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 14546);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8eac
	if (!cr6.eq) goto loc_822D8EAC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8E84;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d8ea4
	if (cr6.gt) goto loc_822D8EA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8E98;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d8eac
	if (!cr6.lt) goto loc_822D8EAC;
loc_822D8EA4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d8eb0
	goto loc_822D8EB0;
loc_822D8EAC:
	// li r11,0
	r11.s64 = 0;
loc_822D8EB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r8,r10,-14420
	ctx.r8.s64 = ctx.r10.s64 + -14420;
	// rlwinm r7,r9,29,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x4;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// xori r5,r7,4
	ctx.r5.u64 = ctx.r7.u64 ^ 4;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// lwz r3,-14344(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -14344);
	// stw r4,-14408(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14408, ctx.r4.u32);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8EE0;
	sub_8218F8D0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d66e8
	ctx.lr = 0x822D8EE8;
	sub_822D66E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d8f6c
	if (cr6.eq) goto loc_822D8F6C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r27,-32120
	r27.s64 = -2105016320;
	// addi r30,r11,3624
	r30.s64 = r11.s64 + 3624;
loc_822D8F00:
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// and r10,r11,r28
	ctx.r10.u64 = r11.u64 & r28.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d8f60
	if (cr6.eq) goto loc_822D8F60;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d87b8
	ctx.lr = 0x822D8F20;
	sub_822D87B8(ctx, base);
	// lbz r11,-4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8f60
	if (cr6.eq) goto loc_822D8F60;
	// lfs f13,268(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d8f60
	if (!cr6.lt) goto loc_822D8F60;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8F44;
	sub_82190890(ctx, base);
	// lwz r11,-14472(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -14472);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822daac8
	ctx.lr = 0x822D8F58;
	sub_822DAAC8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8F60;
	sub_82190890(ctx, base);
loc_822D8F60:
	// lwz r31,276(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822d8f00
	if (!cr6.eq) goto loc_822D8F00;
loc_822D8F6C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D8F74"))) PPC_WEAK_FUNC(sub_822D8F74);
PPC_FUNC_IMPL(__imp__sub_822D8F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D8F78"))) PPC_WEAK_FUNC(sub_822D8F78);
PPC_FUNC_IMPL(__imp__sub_822D8F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d8be8
	sub_822D8BE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D8F84"))) PPC_WEAK_FUNC(sub_822D8F84);
PPC_FUNC_IMPL(__imp__sub_822D8F84) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D8F88"))) PPC_WEAK_FUNC(sub_822D8F88);
PPC_FUNC_IMPL(__imp__sub_822D8F88) {
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
	ctx.lr = 0x822D8F90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x822D8FA0;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d9068
	if (!cr6.gt) goto loc_822D9068;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r27,r31
	r27.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
loc_822D8FB8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d905c
	if (cr6.eq) goto loc_822D905C;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// lwzx r31,r29,r28
	r31.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d900c
	if (cr6.eq) goto loc_822D900C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D8FE0;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d900c
	if (cr6.eq) goto loc_822D900C;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9010
	if (cr6.eq) goto loc_822D9010;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D8FFC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x822d9010
	goto loc_822D9010;
loc_822D900C:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
loc_822D9010:
	// lwzx r29,r29,r28
	r29.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d9058
	if (cr6.eq) goto loc_822D9058;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82187a38
	ctx.lr = 0x822D902C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d9058
	if (cr6.eq) goto loc_822D9058;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d905c
	if (cr6.eq) goto loc_822D905C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D9048;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d905c
	goto loc_822D905C;
loc_822D9058:
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_822D905C:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822d8fb8
	if (!cr0.eq) goto loc_822D8FB8;
loc_822D9068:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D9074"))) PPC_WEAK_FUNC(sub_822D9074);
PPC_FUNC_IMPL(__imp__sub_822D9074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9078"))) PPC_WEAK_FUNC(sub_822D9078);
PPC_FUNC_IMPL(__imp__sub_822D9078) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d8e50
	sub_822D8E50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D907C"))) PPC_WEAK_FUNC(sub_822D907C);
PPC_FUNC_IMPL(__imp__sub_822D907C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9080"))) PPC_WEAK_FUNC(sub_822D9080);
PPC_FUNC_IMPL(__imp__sub_822D9080) {
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
	// lwz r3,240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// bl 0x82130588
	ctx.lr = 0x822D90A0;
	sub_82130588(ctx, base);
	// lwz r30,248(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d90c8
	if (cr6.eq) goto loc_822D90C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82765168
	ctx.lr = 0x822D90B8;
	sub_82765168(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2a40
	ctx.lr = 0x822D90C0;
	sub_821E2A40(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D90C8;
	sub_82130588(ctx, base);
loc_822D90C8:
	// lhz r11,198(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d90dc
	if (cr6.eq) goto loc_822D90DC;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82130588
	ctx.lr = 0x822D90DC;
	sub_82130588(ctx, base);
loc_822D90DC:
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

__attribute__((alias("__imp__sub_822D90F4"))) PPC_WEAK_FUNC(sub_822D90F4);
PPC_FUNC_IMPL(__imp__sub_822D90F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D90F8"))) PPC_WEAK_FUNC(sub_822D90F8);
PPC_FUNC_IMPL(__imp__sub_822D90F8) {
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
	ctx.lr = 0x822D9100;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r26,r31,24
	r26.s64 = r31.s64 + 24;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// addi r25,r31,32
	r25.s64 = r31.s64 + 32;
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r23,r31,80
	r23.s64 = r31.s64 + 80;
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
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
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// sth r30,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r30.u16);
	// sth r30,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r30.u16);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// sth r30,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r30.u16);
	// sth r30,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r30.u16);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r30.u16);
	// sth r30,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r30.u16);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// sth r30,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r30.u16);
	// sth r30,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r30.u16);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// sth r30,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r30.u16);
	// sth r30,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r30.u16);
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
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// sth r30,100(r31)
	PPC_STORE_U16(r31.u32 + 100, r30.u16);
	// sth r30,102(r31)
	PPC_STORE_U16(r31.u32 + 102, r30.u16);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// sth r30,108(r31)
	PPC_STORE_U16(r31.u32 + 108, r30.u16);
	// sth r30,110(r31)
	PPC_STORE_U16(r31.u32 + 110, r30.u16);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// sth r30,116(r31)
	PPC_STORE_U16(r31.u32 + 116, r30.u16);
	// sth r30,118(r31)
	PPC_STORE_U16(r31.u32 + 118, r30.u16);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// sth r30,124(r31)
	PPC_STORE_U16(r31.u32 + 124, r30.u16);
	// sth r30,126(r31)
	PPC_STORE_U16(r31.u32 + 126, r30.u16);
	// beq cr6,0x822d92b0
	if (cr6.eq) goto loc_822D92B0;
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D91F8;
	sub_82130528(ctx, base);
	// li r24,512
	r24.s64 = 512;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r4,512
	ctx.r4.s64 = 512;
	// sth r24,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r24.u16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d8f88
	ctx.lr = 0x822D9210;
	sub_822D8F88(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r24,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r24.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9220;
	sub_82130528(ctx, base);
	// li r29,128
	r29.s64 = 128;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// sth r29,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r29.u16);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D9238;
	sub_822D8F88(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// sth r29,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r29.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9248;
	sub_82130528(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D925C;
	sub_822D8F88(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// sth r29,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r29.u16);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822D926C;
	sub_82130528(ctx, base);
	// li r28,32
	r28.s64 = 32;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// sth r28,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r28.u16);
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x822d8f88
	ctx.lr = 0x822D9284;
	sub_822D8F88(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// sth r28,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r28.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9294;
	sub_82130528(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// sth r29,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r29.u16);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D92A8;
	sub_822D8F88(ctx, base);
	// sth r29,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r29.u16);
	// b 0x822d9370
	goto loc_822D9370;
loc_822D92B0:
	// li r3,10240
	ctx.r3.s64 = 10240;
	// bl 0x82130528
	ctx.lr = 0x822D92B8;
	sub_82130528(ctx, base);
	// li r24,5120
	r24.s64 = 5120;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r4,5120
	ctx.r4.s64 = 5120;
	// sth r24,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r24.u16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d8f88
	ctx.lr = 0x822D92D0;
	sub_822D8F88(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r24,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r24.u16);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D92E0;
	sub_82130528(ctx, base);
	// li r24,512
	r24.s64 = 512;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// sth r24,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r24.u16);
	// li r4,512
	ctx.r4.s64 = 512;
	// bl 0x822d8f88
	ctx.lr = 0x822D92F8;
	sub_822D8F88(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// sth r24,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r24.u16);
	// li r3,2048
	ctx.r3.s64 = 2048;
	// bl 0x82130528
	ctx.lr = 0x822D9308;
	sub_82130528(ctx, base);
	// li r29,1024
	r29.s64 = 1024;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// bl 0x822d8f88
	ctx.lr = 0x822D9320;
	sub_822D8F88(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// sth r29,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r29.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9330;
	sub_82130528(ctx, base);
	// li r29,128
	r29.s64 = 128;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// sth r29,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r29.u16);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D9348;
	sub_822D8F88(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// sth r29,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r29.u16);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D9358;
	sub_82130528(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// sth r24,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r24.u16);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// li r4,512
	ctx.r4.s64 = 512;
	// bl 0x822d8f88
	ctx.lr = 0x822D936C;
	sub_822D8F88(ctx, base);
	// sth r24,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r24.u16);
loc_822D9370:
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// addi r27,r31,148
	r27.s64 = r31.s64 + 148;
	// addi r29,r31,92
	r29.s64 = r31.s64 + 92;
	// li r28,5
	r28.s64 = 5;
	// li r26,65
	r26.s64 = 65;
loc_822D9384:
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82130528
	ctx.lr = 0x822D938C;
	sub_82130528(ctx, base);
	// stw r3,-4(r29)
	PPC_STORE_U32(r29.u32 + -4, ctx.r3.u32);
	// sth r26,2(r29)
	PPC_STORE_U16(r29.u32 + 2, r26.u16);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// sth r8,0(r29)
	PPC_STORE_U16(r29.u32 + 0, ctx.r8.u16);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x822d9384
	if (!cr0.eq) goto loc_822D9384;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D93CC;
	sub_82130528(ctx, base);
	// li r11,64
	r11.s64 = 64;
	// stw r3,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,6(r23)
	PPC_STORE_U16(r23.u32 + 6, r11.u16);
	// stb r30,193(r31)
	PPC_STORE_U8(r31.u32 + 193, r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D93E8"))) PPC_WEAK_FUNC(sub_822D93E8);
PPC_FUNC_IMPL(__imp__sub_822D93E8) {
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
	ctx.lr = 0x822D93F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,5
	r29.s64 = 5;
	// addi r31,r27,46
	r31.s64 = r27.s64 + 46;
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
loc_822D9408:
	// lhz r11,-40(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d941c
	if (!cr6.eq) goto loc_822D941C;
	// sth r30,-40(r31)
	PPC_STORE_U16(r31.u32 + -40, r30.u16);
	// stw r30,-46(r31)
	PPC_STORE_U32(r31.u32 + -46, r30.u32);
loc_822D941C:
	// sth r30,-42(r31)
	PPC_STORE_U16(r31.u32 + -42, r30.u16);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9434
	if (!cr6.eq) goto loc_822D9434;
	// sth r30,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r30.u16);
	// stw r30,-6(r31)
	PPC_STORE_U32(r31.u32 + -6, r30.u32);
loc_822D9434:
	// sth r30,-2(r31)
	PPC_STORE_U16(r31.u32 + -2, r30.u16);
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9454
	if (!cr6.eq) goto loc_822D9454;
	// sth r28,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r28.u16);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822D9450;
	sub_82130528(ctx, base);
	// stw r3,42(r31)
	PPC_STORE_U32(r31.u32 + 42, ctx.r3.u32);
loc_822D9454:
	// sth r28,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r28.u16);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x822d9408
	if (!cr0.eq) goto loc_822D9408;
	// lhz r10,86(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 86);
	// addi r11,r27,80
	r11.s64 = r27.s64 + 80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d947c
	if (!cr6.eq) goto loc_822D947C;
	// sth r30,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r30.u16);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_822D947C:
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stb r30,193(r27)
	PPC_STORE_U8(r27.u32 + 193, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D948C"))) PPC_WEAK_FUNC(sub_822D948C);
PPC_FUNC_IMPL(__imp__sub_822D948C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9490"))) PPC_WEAK_FUNC(sub_822D9490);
PPC_FUNC_IMPL(__imp__sub_822D9490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x822d93e8
	sub_822D93E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D949C"))) PPC_WEAK_FUNC(sub_822D949C);
PPC_FUNC_IMPL(__imp__sub_822D949C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D94A0"))) PPC_WEAK_FUNC(sub_822D94A0);
PPC_FUNC_IMPL(__imp__sub_822D94A0) {
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
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822D94D0;
	sub_82137A08(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-14388
	r30.s64 = r11.s64 + -14388;
	// lwz r11,-14388(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9548
	if (!cr6.eq) goto loc_822D9548;
loc_822D94E4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d94e4
	if (cr6.eq) goto loc_822D94E4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r7,r10,-13216
	ctx.r7.s64 = ctx.r10.s64 + -13216;
	// addi r5,r9,-13440
	ctx.r5.s64 = ctx.r9.s64 + -13440;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822D9518;
	sub_82137A08(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-17804
	ctx.r5.s64 = ctx.r8.s64 + -17804;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821fdd50
	ctx.lr = 0x822D9534;
	sub_821FDD50(ctx, base);
loc_822D9534:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9534
	if (cr6.eq) goto loc_822D9534;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_822D9548:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
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

__attribute__((alias("__imp__sub_822D9560"))) PPC_WEAK_FUNC(sub_822D9560);
PPC_FUNC_IMPL(__imp__sub_822D9560) {
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
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822D958C;
	sub_82137A08(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,-14384
	r31.s64 = r11.s64 + -14384;
	// addi r30,r10,-13176
	r30.s64 = ctx.r10.s64 + -13176;
	// lwz r3,-14384(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -14384);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d9638
	if (!cr6.eq) goto loc_822D9638;
loc_822D95A8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d95a8
	if (cr6.eq) goto loc_822D95A8;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-14320
	ctx.r8.s64 = ctx.r10.s64 + -14320;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r9,-13204
	ctx.r5.s64 = ctx.r9.s64 + -13204;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x822D95F0;
	sub_82137A08(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,-17804
	ctx.r5.s64 = ctx.r9.s64 + -17804;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821fdd50
	ctx.lr = 0x822D960C;
	sub_821FDD50(ctx, base);
loc_822D960C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d960c
	if (cr6.eq) goto loc_822D960C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d9638
	if (!cr6.eq) goto loc_822D9638;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x822d96f4
	goto loc_822D96F4;
loc_822D9638:
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d96f4
	if (cr6.eq) goto loc_822D96F4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-14380
	r31.s64 = r11.s64 + -14380;
	// lwz r11,-14380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d96f4
	if (!cr6.eq) goto loc_822D96F4;
loc_822D9654:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9654
	if (cr6.eq) goto loc_822D9654;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x822d7720
	ctx.lr = 0x822D966C;
	sub_822D7720(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r11,-13440
	ctx.r5.s64 = r11.s64 + -13440;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822D9688;
	sub_82137A08(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r10,-13208
	ctx.r5.s64 = ctx.r10.s64 + -13208;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x822d7798
	ctx.lr = 0x822D96A4;
	sub_822D7798(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-24880(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24880);
	// stw r11,-24880(r9)
	PPC_STORE_U32(ctx.r9.u32 + -24880, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d96e0
	if (cr6.eq) goto loc_822D96E0;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x822d96e0
	if (!cr0.eq) goto loc_822D96E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D96E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D96E0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d96e0
	if (cr6.eq) goto loc_822D96E0;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_822D96F4:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
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

__attribute__((alias("__imp__sub_822D970C"))) PPC_WEAK_FUNC(sub_822D970C);
PPC_FUNC_IMPL(__imp__sub_822D970C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9710"))) PPC_WEAK_FUNC(sub_822D9710);
PPC_FUNC_IMPL(__imp__sub_822D9710) {
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
	ctx.lr = 0x822D9718;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x822D9728;
	sub_821D2970(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// addi r10,r11,-13384
	ctx.r10.s64 = r11.s64 + -13384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// bl 0x82193cc0
	ctx.lr = 0x822D9740;
	sub_82193CC0(ctx, base);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d975c
	if (cr6.eq) goto loc_822D975C;
	// lwz r10,-24880(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, r11.u32);
loc_822D975C:
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x822d7858
	ctx.lr = 0x822D9764;
	sub_822D7858(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9780
	if (cr6.eq) goto loc_822D9780;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, ctx.r10.u32);
	// stw r23,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r23.u32);
loc_822D9780:
	// addi r24,r27,24
	r24.s64 = r27.s64 + 24;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821b5a60
	ctx.lr = 0x822D978C;
	sub_821B5A60(ctx, base);
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x821b5a60
	ctx.lr = 0x822D9794;
	sub_821B5A60(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r27,32
	ctx.r3.s64 = r27.s64 + 32;
	// bl 0x822d76a8
	ctx.lr = 0x822D97A4;
	sub_822D76A8(ctx, base);
	// lhz r11,36(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9874
	if (cr6.eq) goto loc_822D9874;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_822D97B8:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add. r31,r26,r11
	r31.u64 = r26.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x822d9860
	if (cr0.eq) goto loc_822D9860;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9810
	if (cr6.eq) goto loc_822D9810;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D97E4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d9810
	if (cr6.eq) goto loc_822D9810;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9814
	if (cr6.eq) goto loc_822D9814;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D9800;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d9814
	goto loc_822D9814;
loc_822D9810:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_822D9814:
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d985c
	if (cr6.eq) goto loc_822D985C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D9830;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d985c
	if (cr6.eq) goto loc_822D985C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9860
	if (cr6.eq) goto loc_822D9860;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D984C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d9860
	goto loc_822D9860;
loc_822D985C:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_822D9860:
	// lhz r11,36(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x822d97b8
	if (cr6.lt) goto loc_822D97B8;
loc_822D9874:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D9880"))) PPC_WEAK_FUNC(sub_822D9880);
PPC_FUNC_IMPL(__imp__sub_822D9880) {
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
	ctx.lr = 0x822D9888;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x822d993c
	if (!cr6.eq) goto loc_822D993C;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,68
	r25.s64 = 68;
	// lwz r24,0(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r30,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r30.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bc6b8
	ctx.lr = 0x822D98C0;
	sub_821BC6B8(ctx, base);
	// li r28,60
	r28.s64 = 60;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// li r27,0
	r27.s64 = 0;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// stb r27,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r27.u8);
	// stwx r9,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r9.u32);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// beq cr6,0x822d9908
	if (cr6.eq) goto loc_822D9908;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d9710
	ctx.lr = 0x822D9908;
	sub_822D9710(ctx, base);
loc_822D9908:
	// sth r27,2(r26)
	PPC_STORE_U16(r26.u32 + 2, r27.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// sth r27,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r27.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x822D991C;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x822D9924;
	sub_8276D240(ctx, base);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stwx r27,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r27.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r11.u32);
loc_822D993C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822D9944"))) PPC_WEAK_FUNC(sub_822D9944);
PPC_FUNC_IMPL(__imp__sub_822D9944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9948"))) PPC_WEAK_FUNC(sub_822D9948);
PPC_FUNC_IMPL(__imp__sub_822D9948) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d9880
	sub_822D9880(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D994C"))) PPC_WEAK_FUNC(sub_822D994C);
PPC_FUNC_IMPL(__imp__sub_822D994C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9950"))) PPC_WEAK_FUNC(sub_822D9950);
PPC_FUNC_IMPL(__imp__sub_822D9950) {
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
	ctx.lr = 0x822D9958;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lbz r10,-14373(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9988
	if (cr6.eq) goto loc_822D9988;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,-24880(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// addi r3,r11,-13172
	ctx.r3.s64 = r11.s64 + -13172;
	// bl 0x82130000
	ctx.lr = 0x822D9988;
	sub_82130000(ctx, base);
loc_822D9988:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-14388(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -14388);
	// bl 0x822d7720
	ctx.lr = 0x822D9994;
	sub_822D7720(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x822d9880
	ctx.lr = 0x822D99A0;
	sub_822D9880(ctx, base);
	// lwz r3,-24880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, r11.u32);
	// beq cr6,0x822d99d8
	if (cr6.eq) goto loc_822D99D8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x822d99d8
	if (!cr0.eq) goto loc_822D99D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D99D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D99D8:
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 36);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d9a1c
	if (cr6.eq) goto loc_822D9A1C;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822D99F4:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r9,80
	ctx.r9.s64 = ctx.r9.s64 + 80;
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lhz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 36);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x822d99f4
	if (cr6.lt) goto loc_822D99F4;
loc_822D9A1C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D9A24"))) PPC_WEAK_FUNC(sub_822D9A24);
PPC_FUNC_IMPL(__imp__sub_822D9A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9A28"))) PPC_WEAK_FUNC(sub_822D9A28);
PPC_FUNC_IMPL(__imp__sub_822D9A28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D9A30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x822d9d14
	if (cr6.gt) goto loc_822D9D14;
	// lis r12,-32210
	r12.s64 = -2110914560;
	// addi r12,r12,-25980
	r12.s64 = r12.s64 + -25980;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822D9A98;
	case 1:
		goto loc_822D9B30;
	case 2:
		goto loc_822D9D14;
	case 3:
		goto loc_822D9BF0;
	case 4:
		goto loc_822D9C90;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25960(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25960);
	// lwz r17,-25808(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25808);
	// lwz r17,-25324(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25324);
	// lwz r17,-25616(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25616);
	// lwz r17,-25456(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25456);
loc_822D9A98:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14373(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9ad0
	if (cr6.eq) goto loc_822D9AD0;
	// lfs f1,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r6,248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r10,-13044
	ctx.r3.s64 = ctx.r10.s64 + -13044;
	// lwz r7,11724(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9AD0;
	sub_82130000(ctx, base);
loc_822D9AD0:
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// lfs f13,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,-13048(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13048);
	f0.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r6,r10,-26288
	ctx.r6.s64 = ctx.r10.s64 + -26288;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r10,2
	ctx.r10.s64 = 2;
	// lfs f12,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f12,264(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// stw r8,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r8.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
loc_822D9B30:
	// lbz r11,294(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 294);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9d14
	if (!cr6.eq) goto loc_822D9D14;
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r11,12288
	r11.s64 = 805306368;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r8,r9,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bne cr6,0x822d9b78
	if (!cr6.eq) goto loc_822D9B78;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// lfs f0,-13052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13052);
	f0.f64 = double(temp.f32);
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
loc_822D9B78:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// lfs f13,-30576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30576);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d9d14
	if (!cr6.gt) goto loc_822D9D14;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lfs f0,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x822d9d14
	if (cr6.eq) goto loc_822D9D14;
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,-13048(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13048);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r6,r10,-26288
	ctx.r6.s64 = ctx.r10.s64 + -26288;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
loc_822D9BF0:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lbz r11,-14373(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -14373);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9c1c
	if (cr6.eq) goto loc_822D9C1C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r5,248(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r10,-13088
	ctx.r3.s64 = ctx.r10.s64 + -13088;
	// lwz r6,11724(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9C1C;
	sub_82130000(ctx, base);
loc_822D9C1C:
	// bl 0x82305ad8
	ctx.lr = 0x822D9C20;
	sub_82305AD8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32137
	r11.s64 = -2106130432;
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-11448
	ctx.r6.s64 = r11.s64 + -11448;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r10,-26296
	ctx.r5.s64 = ctx.r10.s64 + -26296;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D9C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-14356(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14356);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d9c60
	if (!cr6.lt) goto loc_822D9C60;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822D9C60:
	// lbz r9,-14373(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -14373);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,-14356(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14356, ctx.r4.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d9c80
	if (cr6.eq) goto loc_822D9C80;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13108
	ctx.r3.s64 = r11.s64 + -13108;
	// bl 0x82130000
	ctx.lr = 0x822D9C80;
	sub_82130000(ctx, base);
loc_822D9C80:
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// b 0x822d9d0c
	goto loc_822D9D0C;
loc_822D9C90:
	// lwz r5,248(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822d9d14
	if (!cr6.eq) goto loc_822D9D14;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r30,-14373(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9ccc
	if (cr6.eq) goto loc_822D9CCC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13144
	ctx.r3.s64 = ctx.r10.s64 + -13144;
	// lwz r6,11724(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9CCC;
	sub_82130000(ctx, base);
loc_822D9CCC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,-14356(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -14356);
	// addic. r4,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r4.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r4,-14356(r11)
	PPC_STORE_U32(r11.u32 + -14356, ctx.r4.u32);
	// bge 0x822d9cec
	if (!cr0.lt) goto loc_822D9CEC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r4,-14356(r11)
	PPC_STORE_U32(r11.u32 + -14356, ctx.r4.u32);
loc_822D9CEC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9d00
	if (cr6.eq) goto loc_822D9D00;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13108
	ctx.r3.s64 = r11.s64 + -13108;
	// bl 0x82130000
	ctx.lr = 0x822D9D00;
	sub_82130000(ctx, base);
loc_822D9D00:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r29,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r29.u32);
	// stb r29,294(r31)
	PPC_STORE_U8(r31.u32 + 294, r29.u8);
loc_822D9D0C:
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stw r29,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r29.u32);
loc_822D9D14:
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D9D30"))) PPC_WEAK_FUNC(sub_822D9D30);
PPC_FUNC_IMPL(__imp__sub_822D9D30) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,-11836(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11836);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9d64
	if (cr6.eq) goto loc_822D9D64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r11,-12984
	ctx.r3.s64 = r11.s64 + -12984;
	// bl 0x82130000
	ctx.lr = 0x822D9D64;
	sub_82130000(ctx, base);
loc_822D9D64:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d9d88
	if (!cr6.eq) goto loc_822D9D88;
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
loc_822D9D88:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d9d98
	if (!cr6.eq) goto loc_822D9D98;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x822d9da4
	goto loc_822D9DA4;
loc_822D9D98:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822d9dc0
	if (!cr6.eq) goto loc_822D9DC0;
	// li r10,2
	ctx.r10.s64 = 2;
loc_822D9DA4:
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,1
	r11.s64 = 1;
	// stw r8,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r8.u32);
	// stw r9,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r9.u32);
	// stb r11,294(r31)
	PPC_STORE_U8(r31.u32 + 294, r11.u8);
loc_822D9DC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d9a28
	ctx.lr = 0x822D9DC8;
	sub_822D9A28(ctx, base);
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

__attribute__((alias("__imp__sub_822D9DE0"))) PPC_WEAK_FUNC(sub_822D9DE0);
PPC_FUNC_IMPL(__imp__sub_822D9DE0) {
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
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d9e30
	if (!cr6.eq) goto loc_822D9E30;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r10,-14368
	ctx.r7.s64 = ctx.r10.s64 + -14368;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,-14372(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -14372);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r9,r6,0,5,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x7FFFFE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stw r10,-14372(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14372, ctx.r10.u32);
loc_822D9E30:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3636(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3636);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d9ec0
	if (!cr6.lt) goto loc_822D9EC0;
	// lbz r11,294(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 294);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9ec0
	if (!cr6.eq) goto loc_822D9EC0;
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d9e70
	if (!cr6.eq) goto loc_822D9E70;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14432);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d9ee8
	if (!cr6.lt) goto loc_822D9EE8;
loc_822D9E70:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3652);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822d9ee8
	if (cr6.lt) goto loc_822D9EE8;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d9ee8
	if (!cr6.eq) goto loc_822D9EE8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-11835(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11835);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9eb4
	if (cr6.eq) goto loc_822D9EB4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r11,-12956
	ctx.r3.s64 = r11.s64 + -12956;
	// bl 0x82130000
	ctx.lr = 0x822D9EB4;
	sub_82130000(ctx, base);
loc_822D9EB4:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822d9ed8
	goto loc_822D9ED8;
loc_822D9EC0:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822d9ed4
	if (cr6.eq) goto loc_822D9ED4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822d9ee8
	if (!cr6.eq) goto loc_822D9EE8;
loc_822D9ED4:
	// li r10,4
	ctx.r10.s64 = 4;
loc_822D9ED8:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
loc_822D9EE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d9a28
	ctx.lr = 0x822D9EF0;
	sub_822D9A28(ctx, base);
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

__attribute__((alias("__imp__sub_822D9F04"))) PPC_WEAK_FUNC(sub_822D9F04);
PPC_FUNC_IMPL(__imp__sub_822D9F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D9F08"))) PPC_WEAK_FUNC(sub_822D9F08);
PPC_FUNC_IMPL(__imp__sub_822D9F08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lbz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// li r11,64
	r11.s64 = 64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d9f24
	if (!cr6.eq) goto loc_822D9F24;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822D9F24:
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D9F38"))) PPC_WEAK_FUNC(sub_822D9F38);
PPC_FUNC_IMPL(__imp__sub_822D9F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f31{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D9F40;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x822e11a0
	ctx.lr = 0x822D9F5C;
	sub_822E11A0(ctx, base);
	// bl 0x822e1b58
	ctx.lr = 0x822D9F60;
	sub_822E1B58(ctx, base);
	// bl 0x822e32e0
	ctx.lr = 0x822D9F64;
	sub_822E32E0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da00c
	if (cr6.eq) goto loc_822DA00C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r26,r31,32
	r26.s64 = r31.s64 + 32;
	// li r25,3
	r25.s64 = 3;
	// lis r27,-32120
	r27.s64 = -2105016320;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822D9F8C:
	// lhz r30,4(r26)
	r30.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822da000
	if (!cr6.gt) goto loc_822DA000;
	// li r29,0
	r29.s64 = 0;
loc_822D9F9C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D9FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x822d9fd8
	if (cr6.eq) goto loc_822D9FD8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D9FD8:
	// lwz r3,-7572(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -7572);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822f10d0
	ctx.lr = 0x822D9FE4;
	sub_822F10D0(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9FF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822d9f9c
	if (!cr0.eq) goto loc_822D9F9C;
loc_822DA000:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,12
	r26.s64 = r26.s64 + 12;
	// bne 0x822d9f8c
	if (!cr0.eq) goto loc_822D9F8C;
loc_822DA00C:
	// bl 0x822e1158
	ctx.lr = 0x822DA010;
	sub_822E1158(ctx, base);
	// bl 0x822e19b0
	ctx.lr = 0x822DA014;
	sub_822E19B0(ctx, base);
	// bl 0x822e3148
	ctx.lr = 0x822DA018;
	sub_822E3148(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822DA02C"))) PPC_WEAK_FUNC(sub_822DA02C);
PPC_FUNC_IMPL(__imp__sub_822DA02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA030"))) PPC_WEAK_FUNC(sub_822DA030);
PPC_FUNC_IMPL(__imp__sub_822DA030) {
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
	ctx.lr = 0x822DA038;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// addi r29,r3,36
	r29.s64 = ctx.r3.s64 + 36;
	// li r28,3
	r28.s64 = 3;
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
loc_822DA04C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da0a0
	if (cr6.eq) goto loc_822DA0A0;
	// addi r31,r29,-4
	r31.s64 = r29.s64 + -4;
loc_822DA05C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da094
	if (cr6.eq) goto loc_822DA094;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DA094:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da05c
	if (!cr6.eq) goto loc_822DA05C;
loc_822DA0A0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// bne 0x822da04c
	if (!cr0.eq) goto loc_822DA04C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822DA0B4"))) PPC_WEAK_FUNC(sub_822DA0B4);
PPC_FUNC_IMPL(__imp__sub_822DA0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA0B8"))) PPC_WEAK_FUNC(sub_822DA0B8);
PPC_FUNC_IMPL(__imp__sub_822DA0B8) {
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
	ctx.lr = 0x822DA0C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r11,-12528
	ctx.r9.s64 = r11.s64 + -12528;
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da130
	if (cr6.eq) goto loc_822DA130;
	// lis r11,0
	r11.s64 = 0;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
loc_822DA0EC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da124
	if (cr6.eq) goto loc_822DA124;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DA124:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da0ec
	if (!cr6.eq) goto loc_822DA0EC;
loc_822DA130:
	// lhz r11,10(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da144
	if (cr6.eq) goto loc_822DA144;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822DA144;
	sub_82130588(ctx, base);
loc_822DA144:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822DA14C"))) PPC_WEAK_FUNC(sub_822DA14C);
PPC_FUNC_IMPL(__imp__sub_822DA14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA150"))) PPC_WEAK_FUNC(sub_822DA150);
PPC_FUNC_IMPL(__imp__sub_822DA150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11828);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DA15C"))) PPC_WEAK_FUNC(sub_822DA15C);
PPC_FUNC_IMPL(__imp__sub_822DA15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA160"))) PPC_WEAK_FUNC(sub_822DA160);
PPC_FUNC_IMPL(__imp__sub_822DA160) {
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
	// bl 0x822da0b8
	ctx.lr = 0x822DA180;
	sub_822DA0B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da198
	if (cr6.eq) goto loc_822DA198;
	// bl 0x82130588
	ctx.lr = 0x822DA194;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DA198:
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

__attribute__((alias("__imp__sub_822DA1B0"))) PPC_WEAK_FUNC(sub_822DA1B0);
PPC_FUNC_IMPL(__imp__sub_822DA1B0) {
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
	ctx.lr = 0x822DA1B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-12516
	ctx.r10.s64 = r11.s64 + -12516;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bl 0x822da030
	ctx.lr = 0x822DA1D0;
	sub_822DA030(ctx, base);
	// addi r31,r29,64
	r31.s64 = r29.s64 + 64;
	// li r30,2
	r30.s64 = 2;
loc_822DA1D8:
	// addi r31,r31,-12
	r31.s64 = r31.s64 + -12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822da0b8
	ctx.lr = 0x822DA1E4;
	sub_822DA0B8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822da1d8
	if (!cr0.lt) goto loc_822DA1D8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DA1F4;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822DA1FC"))) PPC_WEAK_FUNC(sub_822DA1FC);
PPC_FUNC_IMPL(__imp__sub_822DA1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA200"))) PPC_WEAK_FUNC(sub_822DA200);
PPC_FUNC_IMPL(__imp__sub_822DA200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11824(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11824);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DA20C"))) PPC_WEAK_FUNC(sub_822DA20C);
PPC_FUNC_IMPL(__imp__sub_822DA20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA210"))) PPC_WEAK_FUNC(sub_822DA210);
PPC_FUNC_IMPL(__imp__sub_822DA210) {
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
	ctx.lr = 0x822DA218;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822da030
	ctx.lr = 0x822DA224;
	sub_822DA030(ctx, base);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x822DA234;
	sub_8261DBE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// addi r28,r11,-12400
	r28.s64 = r11.s64 + -12400;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-12424
	ctx.r4.s64 = ctx.r9.s64 + -12424;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA26C;
	sub_8261DDE8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r30,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r30.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822DA290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-12444
	ctx.r4.s64 = ctx.r4.s64 + -12444;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA2A4;
	sub_8261DDE8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r29,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r29.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822DA2C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-12464
	ctx.r4.s64 = ctx.r7.s64 + -12464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA2DC;
	sub_8261DDE8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r30,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r30.u32);
	// bl 0x822e13a0
	ctx.lr = 0x822DA2F0;
	sub_822E13A0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e23a8
	ctx.lr = 0x822DA2F8;
	sub_822E23A8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e3a90
	ctx.lr = 0x822DA300;
	sub_822E3A90(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// addi r3,r4,-7536
	ctx.r3.s64 = ctx.r4.s64 + -7536;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822da32c
	if (cr6.eq) goto loc_822DA32C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-12492
	ctx.r4.s64 = ctx.r10.s64 + -12492;
	// b 0x822da334
	goto loc_822DA334;
loc_822DA32C:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-12508
	ctx.r4.s64 = ctx.r10.s64 + -12508;
loc_822DA334:
	// bl 0x821ca540
	ctx.lr = 0x822DA338;
	sub_821CA540(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,-27856(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// lwz r3,2828(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// bl 0x821c04b0
	ctx.lr = 0x822DA35C;
	sub_821C04B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DA364;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x822DA36C;
	sub_8261DCA8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822DA374"))) PPC_WEAK_FUNC(sub_822DA374);
PPC_FUNC_IMPL(__imp__sub_822DA374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA378"))) PPC_WEAK_FUNC(sub_822DA378);
PPC_FUNC_IMPL(__imp__sub_822DA378) {
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
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x822DA38C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da3c0
	if (cr6.eq) goto loc_822DA3C0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-12528
	ctx.r9.s64 = ctx.r10.s64 + -12528;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822DA3C0:
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

__attribute__((alias("__imp__sub_822DA3D4"))) PPC_WEAK_FUNC(sub_822DA3D4);
PPC_FUNC_IMPL(__imp__sub_822DA3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA3D8"))) PPC_WEAK_FUNC(sub_822DA3D8);
PPC_FUNC_IMPL(__imp__sub_822DA3D8) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-12516
	ctx.r8.s64 = ctx.r10.s64 + -12516;
	// addi r7,r9,-12528
	ctx.r7.s64 = ctx.r9.s64 + -12528;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r10,r31,28
	ctx.r10.s64 = r31.s64 + 28;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// sth r11,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r11.u16);
	// sth r11,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r11.u16);
	// stw r7,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r7.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// sth r11,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r11.u16);
	// sth r11,50(r31)
	PPC_STORE_U16(r31.u32 + 50, r11.u16);
	// stw r7,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r7.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// sth r11,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r11.u16);
	// sth r11,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r11.u16);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// bl 0x822e10b0
	ctx.lr = 0x822DA454;
	sub_822E10B0(ctx, base);
	// bl 0x822e18d8
	ctx.lr = 0x822DA458;
	sub_822E18D8(ctx, base);
	// bl 0x822e3208
	ctx.lr = 0x822DA45C;
	sub_822E3208(ctx, base);
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

__attribute__((alias("__imp__sub_822DA474"))) PPC_WEAK_FUNC(sub_822DA474);
PPC_FUNC_IMPL(__imp__sub_822DA474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA478"))) PPC_WEAK_FUNC(sub_822DA478);
PPC_FUNC_IMPL(__imp__sub_822DA478) {
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
	// bl 0x822da1b0
	ctx.lr = 0x822DA498;
	sub_822DA1B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da4b0
	if (cr6.eq) goto loc_822DA4B0;
	// bl 0x82130588
	ctx.lr = 0x822DA4AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DA4B0:
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

__attribute__((alias("__imp__sub_822DA4C8"))) PPC_WEAK_FUNC(sub_822DA4C8);
PPC_FUNC_IMPL(__imp__sub_822DA4C8) {
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
	ctx.lr = 0x822DA4DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da4f8
	if (cr6.eq) goto loc_822DA4F8;
	// bl 0x822da3d8
	ctx.lr = 0x822DA4E8;
	sub_822DA3D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822DA4F8:
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

__attribute__((alias("__imp__sub_822DA50C"))) PPC_WEAK_FUNC(sub_822DA50C);
PPC_FUNC_IMPL(__imp__sub_822DA50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA510"))) PPC_WEAK_FUNC(sub_822DA510);
PPC_FUNC_IMPL(__imp__sub_822DA510) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-11828
	r31.s64 = r11.s64 + -11828;
	// lwz r11,-11828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da644
	if (!cr6.eq) goto loc_822DA644;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822DA540;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da554
	if (cr6.eq) goto loc_822DA554;
	// bl 0x821d5408
	ctx.lr = 0x822DA550;
	sub_821D5408(ctx, base);
	// b 0x822da558
	goto loc_822DA558;
loc_822DA554:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822DA558:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12388
	ctx.r7.s64 = ctx.r10.s64 + -12388;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,-23688
	ctx.r4.s64 = ctx.r8.s64 + -23688;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,3816
	ctx.r9.s64 = ctx.r3.s64 + 3816;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822da5d4
	if (!cr6.eq) goto loc_822DA5D4;
	// bl 0x822e0f60
	ctx.lr = 0x822DA5D0;
	sub_822E0F60(ctx, base);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
loc_822DA5D4:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,3728
	ctx.r9.s64 = ctx.r10.s64 + 3728;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x822DA5F0;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822DA600;
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
	ctx.lr = 0x822DA61C;
	sub_821D41D0(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,3764
	ctx.r4.s64 = ctx.r6.s64 + 3764;
	// bl 0x821d4b00
	ctx.lr = 0x822DA62C;
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
	ctx.lr = 0x822DA644;
	sub_821C0548(ctx, base);
loc_822DA644:
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

__attribute__((alias("__imp__sub_822DA65C"))) PPC_WEAK_FUNC(sub_822DA65C);
PPC_FUNC_IMPL(__imp__sub_822DA65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA660"))) PPC_WEAK_FUNC(sub_822DA660);
PPC_FUNC_IMPL(__imp__sub_822DA660) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-11824
	r31.s64 = r11.s64 + -11824;
	// lwz r11,-11824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da794
	if (!cr6.eq) goto loc_822DA794;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822DA690;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da6a4
	if (cr6.eq) goto loc_822DA6A4;
	// bl 0x821d5408
	ctx.lr = 0x822DA6A0;
	sub_821D5408(ctx, base);
	// b 0x822da6a8
	goto loc_822DA6A8;
loc_822DA6A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822DA6A8:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12372
	ctx.r7.s64 = ctx.r10.s64 + -12372;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,-23352
	ctx.r4.s64 = ctx.r8.s64 + -23352;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,3864
	ctx.r9.s64 = ctx.r3.s64 + 3864;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,28
	ctx.r10.s64 = 28;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-11828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822da724
	if (!cr6.eq) goto loc_822DA724;
	// bl 0x822da510
	ctx.lr = 0x822DA720;
	sub_822DA510(ctx, base);
	// lwz r11,-11828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11828);
loc_822DA724:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,3772
	ctx.r9.s64 = ctx.r10.s64 + 3772;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x822DA740;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822DA750;
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
	ctx.lr = 0x822DA76C;
	sub_821D41D0(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,3808
	ctx.r4.s64 = ctx.r6.s64 + 3808;
	// bl 0x821d4b00
	ctx.lr = 0x822DA77C;
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
	ctx.lr = 0x822DA794;
	sub_821C0548(ctx, base);
loc_822DA794:
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

__attribute__((alias("__imp__sub_822DA7AC"))) PPC_WEAK_FUNC(sub_822DA7AC);
PPC_FUNC_IMPL(__imp__sub_822DA7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA7B0"))) PPC_WEAK_FUNC(sub_822DA7B0);
PPC_FUNC_IMPL(__imp__sub_822DA7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lfs f0,31304(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	f0.f64 = double(temp.f32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DA7E8"))) PPC_WEAK_FUNC(sub_822DA7E8);
PPC_FUNC_IMPL(__imp__sub_822DA7E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// stfs f1,44(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f31,f0,f1
	f31.f64 = double(float(f0.f64 / ctx.f1.f64));
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x822DA838;
	sub_823DBAA8(ctx, base);
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64));
	// bl 0x823dba38
	ctx.lr = 0x822DA848;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f1,f11,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fsubs f10,f30,f12
	ctx.f10.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dbaa8
	ctx.lr = 0x822DA868;
	sub_823DBAA8(ctx, base);
	// lfs f8,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f8,f31
	ctx.f1.f64 = double(float(ctx.f8.f64 * f31.f64));
	// bl 0x823dba38
	ctx.lr = 0x822DA878;
	sub_823DBA38(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// lfs f6,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// fdivs f1,f6,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// fsubs f4,f30,f7
	ctx.f4.f64 = double(float(f30.f64 - ctx.f7.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r8,r9,r30
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r30.s32);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// bl 0x823dba38
	ctx.lr = 0x822DA8AC;
	sub_823DBA38(ctx, base);
	// frsp f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// li r7,48
	ctx.r7.s64 = 48;
	// lfs f1,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / f0.f64));
	// fctiwz f13,f2
	ctx.f13.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f13,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.f13.u32);
	// bl 0x823dba38
	ctx.lr = 0x822DA8CC;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// li r6,52
	ctx.r6.s64 = 52;
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.f11.u32);
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

__attribute__((alias("__imp__sub_822DA8FC"))) PPC_WEAK_FUNC(sub_822DA8FC);
PPC_FUNC_IMPL(__imp__sub_822DA8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA900"))) PPC_WEAK_FUNC(sub_822DA900);
PPC_FUNC_IMPL(__imp__sub_822DA900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822da934
	if (cr6.lt) goto loc_822DA934;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x822da934
	if (cr6.gt) goto loc_822DA934;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x822da934
	if (cr6.lt) goto loc_822DA934;
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bgt cr6,0x822da934
	if (cr6.gt) goto loc_822DA934;
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
loc_822DA934:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DA93C"))) PPC_WEAK_FUNC(sub_822DA93C);
PPC_FUNC_IMPL(__imp__sub_822DA93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA940"))) PPC_WEAK_FUNC(sub_822DA940);
PPC_FUNC_IMPL(__imp__sub_822DA940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,-11808
	ctx.r7.s64 = ctx.r8.s64 + -11808;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,-11808(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11808, ctx.r9.u32);
	// stb r11,-11(r7)
	PPC_STORE_U8(ctx.r7.u32 + -11, r11.u8);
	// stw r10,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DA964"))) PPC_WEAK_FUNC(sub_822DA964);
PPC_FUNC_IMPL(__imp__sub_822DA964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DA968"))) PPC_WEAK_FUNC(sub_822DA968);
PPC_FUNC_IMPL(__imp__sub_822DA968) {
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
	// lis r11,2
	r11.s64 = 131072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// rlwinm r11,r31,0,28,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x822DA9B4;
	sub_82311450(ctx, base);
loc_822DA9B4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-11820(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11820);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822da9dc
	if (cr6.eq) goto loc_822DA9DC;
	// cmpwi cr6,r31,4096
	cr6.compare<int32_t>(r31.s32, 4096, xer);
	// bne cr6,0x822da9f8
	if (!cr6.eq) goto loc_822DA9F8;
loc_822DA9DC:
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-13430(r10)
	PPC_STORE_U8(ctx.r10.u32 + -13430, r11.u8);
loc_822DA9F8:
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daa1c
	if (cr6.eq) goto loc_822DAA1C;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823112c0
	ctx.lr = 0x822DAA1C;
	sub_823112C0(ctx, base);
loc_822DAA1C:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// lis r12,282
	r12.s64 = 18481152;
	// ori r12,r12,14846
	r12.u64 = r12.u64 | 14846;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// bl 0x82190890
	ctx.lr = 0x822DAA4C;
	sub_82190890(ctx, base);
loc_822DAA4C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822DAA60;
	sub_8217C088(ctx, base);
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

__attribute__((alias("__imp__sub_822DAA78"))) PPC_WEAK_FUNC(sub_822DAA78);
PPC_FUNC_IMPL(__imp__sub_822DAA78) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r11,r3,0,19,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daaa8
	if (cr6.eq) goto loc_822DAAA8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823112c0
	ctx.lr = 0x822DAAA8;
	sub_823112C0(ctx, base);
loc_822DAAA8:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-13430(r10)
	PPC_STORE_U8(ctx.r10.u32 + -13430, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DAAC4"))) PPC_WEAK_FUNC(sub_822DAAC4);
PPC_FUNC_IMPL(__imp__sub_822DAAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAAC8"))) PPC_WEAK_FUNC(sub_822DAAC8);
PPC_FUNC_IMPL(__imp__sub_822DAAC8) {
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
	ctx.lr = 0x822DAAD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// lis r12,282
	r12.s64 = 18481152;
	// ori r12,r12,14846
	r12.u64 = r12.u64 | 14846;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dab68
	if (cr6.eq) goto loc_822DAB68;
	// bl 0x8219ab28
	ctx.lr = 0x822DAB1C;
	sub_8219AB28(ctx, base);
	// lis r29,-32120
	r29.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DAB38;
	sub_823112C0(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8219adf0
	ctx.lr = 0x822DAB40;
	sub_8219ADF0(ctx, base);
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DAB58;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DAB60;
	sub_82190890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822DAB68:
	// rlwinm r11,r31,0,28,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xC;
	// li r29,-1
	r29.s64 = -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dab90
	if (cr6.eq) goto loc_822DAB90;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8233a5a0
	ctx.lr = 0x822DAB80;
	sub_8233A5A0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x822DAB8C;
	sub_82311450(ctx, base);
	// b 0x822dabbc
	goto loc_822DABBC;
loc_822DAB90:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x822dabbc
	if (!cr6.eq) goto loc_822DABBC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822DABAC;
	sub_8217C088(ctx, base);
	// bl 0x82187bf0
	ctx.lr = 0x822DABB0;
	sub_82187BF0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x822d7270
	ctx.lr = 0x822DABB8;
	sub_822D7270(ctx, base);
	// bl 0x82187be0
	ctx.lr = 0x822DABBC;
	sub_82187BE0(ctx, base);
loc_822DABBC:
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8219adf0
	ctx.lr = 0x822DABC4;
	sub_8219ADF0(ctx, base);
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x822dabd4
	if (!cr6.eq) goto loc_822DABD4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82187be0
	ctx.lr = 0x822DABD4;
	sub_82187BE0(ctx, base);
loc_822DABD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DABDC;
	sub_82190890(ctx, base);
loc_822DABDC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822DABE4"))) PPC_WEAK_FUNC(sub_822DABE4);
PPC_FUNC_IMPL(__imp__sub_822DABE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DABE8"))) PPC_WEAK_FUNC(sub_822DABE8);
PPC_FUNC_IMPL(__imp__sub_822DABE8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// bl 0x822d5468
	ctx.lr = 0x822DAC10;
	sub_822D5468(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822daac8
	ctx.lr = 0x822DAC1C;
	sub_822DAAC8(ctx, base);
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

__attribute__((alias("__imp__sub_822DAC34"))) PPC_WEAK_FUNC(sub_822DAC34);
PPC_FUNC_IMPL(__imp__sub_822DAC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAC38"))) PPC_WEAK_FUNC(sub_822DAC38);
PPC_FUNC_IMPL(__imp__sub_822DAC38) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822DAC54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dac64
	if (cr6.eq) goto loc_822DAC64;
	// bl 0x8219acb0
	ctx.lr = 0x822DAC60;
	sub_8219ACB0(ctx, base);
	// b 0x822dac68
	goto loc_822DAC68;
loc_822DAC64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DAC68:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,6144
	ctx.r5.s64 = 6144;
	// li r4,3072
	ctx.r4.s64 = 3072;
	// bl 0x8219ad48
	ctx.lr = 0x822DAC7C;
	sub_8219AD48(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822DAC84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dac94
	if (cr6.eq) goto loc_822DAC94;
	// bl 0x8219acb0
	ctx.lr = 0x822DAC90;
	sub_8219ACB0(ctx, base);
	// b 0x822dac98
	goto loc_822DAC98;
loc_822DAC94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DAC98:
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,1025
	ctx.r4.s64 = 1025;
	// bl 0x8219ad48
	ctx.lr = 0x822DACAC;
	sub_8219AD48(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
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

__attribute__((alias("__imp__sub_822DACC8"))) PPC_WEAK_FUNC(sub_822DACC8);
PPC_FUNC_IMPL(__imp__sub_822DACC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,24(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dace4
	if (cr6.eq) goto loc_822DACE4;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dace4
	if (cr6.eq) goto loc_822DACE4;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
loc_822DACE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822DACEC"))) PPC_WEAK_FUNC(sub_822DACEC);
PPC_FUNC_IMPL(__imp__sub_822DACEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DACF0"))) PPC_WEAK_FUNC(sub_822DACF0);
PPC_FUNC_IMPL(__imp__sub_822DACF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,24(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dad0c
	if (cr6.eq) goto loc_822DAD0C;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dad0c
	if (cr6.eq) goto loc_822DAD0C;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
loc_822DAD0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822DAD14"))) PPC_WEAK_FUNC(sub_822DAD14);
PPC_FUNC_IMPL(__imp__sub_822DAD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAD18"))) PPC_WEAK_FUNC(sub_822DAD18);
PPC_FUNC_IMPL(__imp__sub_822DAD18) {
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
	// bl 0x822e6e10
	ctx.lr = 0x822DAD38;
	sub_822E6E10(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// addi r10,r11,-12020
	ctx.r10.s64 = r11.s64 + -12020;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DAD50;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_822DAD6C"))) PPC_WEAK_FUNC(sub_822DAD6C);
PPC_FUNC_IMPL(__imp__sub_822DAD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAD70"))) PPC_WEAK_FUNC(sub_822DAD70);
PPC_FUNC_IMPL(__imp__sub_822DAD70) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11988
	ctx.r9.s64 = r11.s64 + -11988;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DADA8;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14472(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14472, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DADBC;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dadd4
	if (cr6.eq) goto loc_822DADD4;
	// bl 0x82130588
	ctx.lr = 0x822DADD0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DADD4:
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

__attribute__((alias("__imp__sub_822DADEC"))) PPC_WEAK_FUNC(sub_822DADEC);
PPC_FUNC_IMPL(__imp__sub_822DADEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DADF0"))) PPC_WEAK_FUNC(sub_822DADF0);
PPC_FUNC_IMPL(__imp__sub_822DADF0) {
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
	// bl 0x822e6b38
	ctx.lr = 0x822DAE08;
	sub_822E6B38(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,270
	ctx.r10.s64 = 17694720;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-11988
	ctx.r8.s64 = r11.s64 + -11988;
	// ori r7,r10,32766
	ctx.r7.u64 = ctx.r10.u64 | 32766;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DAE3C;
	sub_822E5138(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r4,r5,-11964
	ctx.r4.s64 = ctx.r5.s64 + -11964;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
	// stb r11,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r11.u8);
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
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

__attribute__((alias("__imp__sub_822DAE78"))) PPC_WEAK_FUNC(sub_822DAE78);
PPC_FUNC_IMPL(__imp__sub_822DAE78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-11944
	ctx.r3.s64 = r11.s64 + -11944;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DAE84"))) PPC_WEAK_FUNC(sub_822DAE84);
PPC_FUNC_IMPL(__imp__sub_822DAE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAE88"))) PPC_WEAK_FUNC(sub_822DAE88);
PPC_FUNC_IMPL(__imp__sub_822DAE88) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-11964
	ctx.r10.s64 = r11.s64 + -11964;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822daec8
	if (cr6.eq) goto loc_822DAEC8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8219ace0
	ctx.lr = 0x822DAEC0;
	sub_8219ACE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822DAEC8;
	sub_82130588(ctx, base);
loc_822DAEC8:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822daee4
	if (cr6.eq) goto loc_822DAEE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8219ace0
	ctx.lr = 0x822DAEDC;
	sub_8219ACE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822DAEE4;
	sub_82130588(ctx, base);
loc_822DAEE4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11988
	ctx.r9.s64 = r11.s64 + -11988;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DAF00;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14472(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14472, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DAF14;
	sub_822E6940(ctx, base);
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

__attribute__((alias("__imp__sub_822DAF2C"))) PPC_WEAK_FUNC(sub_822DAF2C);
PPC_FUNC_IMPL(__imp__sub_822DAF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAF30"))) PPC_WEAK_FUNC(sub_822DAF30);
PPC_FUNC_IMPL(__imp__sub_822DAF30) {
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
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82130000
	ctx.lr = 0x822DAF54;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6bc0
	ctx.lr = 0x822DAF5C;
	sub_822E6BC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822daf74
	if (cr6.eq) goto loc_822DAF74;
	// bl 0x82130588
	ctx.lr = 0x822DAF70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DAF74:
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

__attribute__((alias("__imp__sub_822DAF8C"))) PPC_WEAK_FUNC(sub_822DAF8C);
PPC_FUNC_IMPL(__imp__sub_822DAF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DAF90"))) PPC_WEAK_FUNC(sub_822DAF90);
PPC_FUNC_IMPL(__imp__sub_822DAF90) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822DAF98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x822d7310
	ctx.lr = 0x822DAFB4;
	sub_822D7310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x822e47d0
	ctx.lr = 0x822DAFC8;
	sub_822E47D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d8bc0
	ctx.lr = 0x822DAFD4;
	sub_822D8BC0(ctx, base);
	// lis r26,-32120
	r26.s64 = -2105016320;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r31,-7572(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lbz r11,14546(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db01c
	if (!cr6.eq) goto loc_822DB01C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DAFF4;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822db014
	if (cr6.gt) goto loc_822DB014;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DB008;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822db01c
	if (!cr6.lt) goto loc_822DB01C;
loc_822DB014:
	// li r11,1
	r11.s64 = 1;
	// b 0x822db020
	goto loc_822DB020;
loc_822DB01C:
	// li r11,0
	r11.s64 = 0;
loc_822DB020:
	// rlwinm r10,r29,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x2000;
	// clrlwi r24,r11,24
	r24.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822db2c4
	if (!cr6.eq) goto loc_822DB2C4;
	// rlwinm r11,r29,0,17,17
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822db29c
	if (!cr6.eq) goto loc_822DB29C;
	// lis r12,258
	r12.s64 = 16908288;
	// ori r12,r12,6652
	r12.u64 = r12.u64 | 6652;
	// and r11,r29,r12
	r11.u64 = r29.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db26c
	if (cr6.eq) goto loc_822DB26C;
	// bl 0x821908a8
	ctx.lr = 0x822DB054;
	sub_821908A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822db06c
	if (!cr6.eq) goto loc_822DB06C;
	// rlwinm r11,r29,0,28,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db06c
	if (cr6.eq) goto loc_822DB06C;
	// bl 0x8233a5a0
	ctx.lr = 0x822DB06C;
	sub_8233A5A0(ctx, base);
loc_822DB06C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// clrlwi r25,r30,24
	r25.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db090
	if (cr6.eq) goto loc_822DB090;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB090;
	sub_82190BD8(ctx, base);
loc_822DB090:
	// rlwinm r11,r25,0,27,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db1a8
	if (cr6.eq) goto loc_822DB1A8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r10,r11,-14420
	ctx.r10.s64 = r11.s64 + -14420;
	// lwz r3,-14344(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -14344);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8218f8d0
	ctx.lr = 0x822DB0B4;
	sub_8218F8D0(ctx, base);
	// lis r12,258
	r12.s64 = 16908288;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// ori r12,r12,12
	r12.u64 = r12.u64 | 12;
	// li r27,0
	r27.s64 = 0;
	// and r30,r29,r12
	r30.u64 = r29.u64 & r12.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822db134
	if (cr6.eq) goto loc_822DB134;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DB0D8;
	sub_82190890(ctx, base);
	// rlwinm r11,r29,0,28,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xC;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db100
	if (cr6.eq) goto loc_822DB100;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822DB0F4;
	sub_822F7338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8233a5a0
	ctx.lr = 0x822DB0FC;
	sub_8233A5A0(ctx, base);
	// b 0x822db118
	goto loc_822DB118;
loc_822DB100:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db118
	if (!cr6.eq) goto loc_822DB118;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822DB118;
	sub_822F7338(ctx, base);
loc_822DB118:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822DB124;
	sub_822F74F0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822DB134;
	sub_822F3918(ctx, base);
loc_822DB134:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB148;
	sub_82190BD8(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822db198
	if (cr6.eq) goto loc_822DB198;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822DB15C;
	sub_822F74F0(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db178
	if (!cr6.eq) goto loc_822DB178;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822f7338
	ctx.lr = 0x822DB174;
	sub_822F7338(ctx, base);
	// b 0x822db180
	goto loc_822DB180;
loc_822DB178:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822f7480
	ctx.lr = 0x822DB180;
	sub_822F7480(ctx, base);
loc_822DB180:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822DB190;
	sub_822F3918(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82190890
	ctx.lr = 0x822DB198;
	sub_82190890(ctx, base);
loc_822DB198:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-14344(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -14344);
	// lwz r4,-14408(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -14408);
	// bl 0x8218f8d0
	ctx.lr = 0x822DB1A8;
	sub_8218F8D0(ctx, base);
loc_822DB1A8:
	// rlwinm r11,r29,0,23,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db1d4
	if (cr6.eq) goto loc_822DB1D4;
	// rlwinm r11,r25,0,30,30
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db1d4
	if (cr6.eq) goto loc_822DB1D4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB1D4;
	sub_82190BD8(ctx, base);
loc_822DB1D4:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db2e4
	if (!cr6.eq) goto loc_822DB2E4;
	// rlwinm r11,r29,0,19,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// rlwinm r11,r25,0,28,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DB218;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DB220;
	sub_82190890(ctx, base);
	// rlwinm r11,r25,0,29,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x4;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db244
	if (cr6.eq) goto loc_822DB244;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB244;
	sub_82190BD8(ctx, base);
loc_822DB244:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82190890
	ctx.lr = 0x822DB24C;
	sub_82190890(ctx, base);
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DB264;
	sub_823112C0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_822DB26C:
	// rlwinm r11,r29,0,11,13
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1C0000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// beq cr6,0x822db2c4
	if (cr6.eq) goto loc_822DB2C4;
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// beq cr6,0x822db2b0
	if (cr6.eq) goto loc_822DB2B0;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x822db2e4
	if (!cr6.eq) goto loc_822DB2E4;
loc_822DB29C:
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822db2d4
	goto loc_822DB2D4;
loc_822DB2B0:
	// rlwinm r11,r30,0,29,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822db2d4
	goto loc_822DB2D4;
loc_822DB2C4:
	// rlwinm r11,r30,0,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_822DB2D4:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB2E4;
	sub_82190BD8(ctx, base);
loc_822DB2E4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822DB2EC"))) PPC_WEAK_FUNC(sub_822DB2EC);
PPC_FUNC_IMPL(__imp__sub_822DB2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB2F0"))) PPC_WEAK_FUNC(sub_822DB2F0);
PPC_FUNC_IMPL(__imp__sub_822DB2F0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-12004
	ctx.r10.s64 = r11.s64 + -12004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6e68
	ctx.lr = 0x822DB31C;
	sub_822E6E68(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822db334
	if (cr6.eq) goto loc_822DB334;
	// bl 0x82130588
	ctx.lr = 0x822DB330;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB334:
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

__attribute__((alias("__imp__sub_822DB34C"))) PPC_WEAK_FUNC(sub_822DB34C);
PPC_FUNC_IMPL(__imp__sub_822DB34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB350"))) PPC_WEAK_FUNC(sub_822DB350);
PPC_FUNC_IMPL(__imp__sub_822DB350) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822DB358;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r11,r23,0,22,22
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db380
	if (cr6.eq) goto loc_822DB380;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-11816(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11816, r11.u32);
loc_822DB380:
	// rlwinm r11,r23,0,23,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db600
	if (cr6.eq) goto loc_822DB600;
	// rlwinm r11,r23,0,26,26
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x20;
	// li r24,1
	r24.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822db3d8
	if (!cr6.eq) goto loc_822DB3D8;
	// rlwinm r11,r23,0,25,25
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3b4
	if (cr6.eq) goto loc_822DB3B4;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// b 0x822db3d8
	goto loc_822DB3D8;
loc_822DB3B4:
	// rlwinm r11,r23,0,24,24
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3c8
	if (cr6.eq) goto loc_822DB3C8;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x822db3d8
	goto loc_822DB3D8;
loc_822DB3C8:
	// rlwinm r11,r23,0,23,23
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3d8
	if (cr6.eq) goto loc_822DB3D8;
	// li r10,3
	ctx.r10.s64 = 3;
loc_822DB3D8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r27,r11,-11788
	r27.s64 = r11.s64 + -11788;
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r27,-16
	r11.s64 = r27.s64 + -16;
	// lwz r10,-8092(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r30,444(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 444);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r30,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1000;
	// stwx r8,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r8.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822db5d4
	if (cr6.eq) goto loc_822DB5D4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f0,16(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 16);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r8,r11,-30896
	ctx.r8.s64 = r11.s64 + -30896;
	// lfs f13,20(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f12,24(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stb r24,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, r24.u8);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,440(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 440);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8268b2f8
	ctx.lr = 0x822DB468;
	sub_8268B2F8(ctx, base);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lfs f10,28(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f8,16(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f7,20(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// lfs f6,24(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 + f31.f64));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822db4f4
	if (cr6.eq) goto loc_822DB4F4;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c148
	ctx.lr = 0x822DB4D0;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822db4f4
	if (!cr6.eq) goto loc_822DB4F4;
	// addi r11,r27,16
	r11.s64 = r27.s64 + 16;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB4F4:
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lis r6,64
	ctx.r6.s64 = 4194304;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r6,r6,3
	ctx.r6.u64 = ctx.r6.u64 | 3;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// bl 0x82175238
	ctx.lr = 0x822DB514;
	sub_82175238(ctx, base);
	// lis r28,1024
	r28.s64 = 67108864;
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// lis r25,4096
	r25.s64 = 268435456;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// beq cr6,0x822db538
	if (cr6.eq) goto loc_822DB538;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x822db53c
	if (!cr6.eq) goto loc_822DB53C;
loc_822DB538:
	// li r11,0
	r11.s64 = 0;
loc_822DB53C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db564
	if (!cr6.eq) goto loc_822DB564;
	// addi r11,r27,32
	r11.s64 = r27.s64 + 32;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB564:
	// lis r8,64
	ctx.r8.s64 = 4194304;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// ori r8,r8,3
	ctx.r8.u64 = ctx.r8.u64 | 3;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x82174d58
	ctx.lr = 0x822DB584;
	sub_82174D58(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// beq cr6,0x822db5a0
	if (cr6.eq) goto loc_822DB5A0;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x822db5a4
	if (!cr6.eq) goto loc_822DB5A4;
loc_822DB5A0:
	// li r11,0
	r11.s64 = 0;
loc_822DB5A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db5cc
	if (!cr6.eq) goto loc_822DB5CC;
	// addi r11,r27,48
	r11.s64 = r27.s64 + 48;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB5CC:
	// stb r24,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, r24.u8);
	// b 0x822db5f0
	goto loc_822DB5F0;
loc_822DB5D4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// lvx128 v1,r26,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c148
	ctx.lr = 0x822DB5E8;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822db614
	if (cr6.eq) goto loc_822DB614;
loc_822DB5F0:
	// lwzx r10,r31,r27
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r27.u32);
	// add r11,r31,r27
	r11.u64 = r31.u64 + r27.u64;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stwx r11,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, r11.u32);
loc_822DB600:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r6,64(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// lbz r5,74(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 74);
	// lwz r3,12(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// bl 0x822daf90
	ctx.lr = 0x822DB614;
	sub_822DAF90(ctx, base);
loc_822DB614:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822DB620"))) PPC_WEAK_FUNC(sub_822DB620);
PPC_FUNC_IMPL(__imp__sub_822DB620) {
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
	// bl 0x822e6b80
	ctx.lr = 0x822DB640;
	sub_822E6B80(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,270
	ctx.r9.s64 = 17694720;
	// addi r8,r11,-11988
	ctx.r8.s64 = r11.s64 + -11988;
	// ori r7,r9,32766
	ctx.r7.u64 = ctx.r9.u64 | 32766;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r31,-14472(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14472, r31.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DB674;
	sub_822E5138(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822e6ae8
	ctx.lr = 0x822DB684;
	sub_822E6AE8(ctx, base);
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

__attribute__((alias("__imp__sub_822DB6A0"))) PPC_WEAK_FUNC(sub_822DB6A0);
PPC_FUNC_IMPL(__imp__sub_822DB6A0) {
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
	// bl 0x822dae88
	ctx.lr = 0x822DB6C0;
	sub_822DAE88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db6d8
	if (cr6.eq) goto loc_822DB6D8;
	// bl 0x82130588
	ctx.lr = 0x822DB6D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB6D8:
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

__attribute__((alias("__imp__sub_822DB6F0"))) PPC_WEAK_FUNC(sub_822DB6F0);
PPC_FUNC_IMPL(__imp__sub_822DB6F0) {
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
	// beq cr6,0x822db72c
	if (cr6.eq) goto loc_822DB72C;
	// bl 0x822db620
	ctx.lr = 0x822DB710;
	sub_822DB620(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// oris r8,r9,30
	ctx.r8.u64 = ctx.r9.u64 | 1966080;
	// addi r10,r11,-11964
	ctx.r10.s64 = r11.s64 + -11964;
	// ori r8,r8,4576
	ctx.r8.u64 = ctx.r8.u64 | 4576;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
loc_822DB72C:
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

__attribute__((alias("__imp__sub_822DB740"))) PPC_WEAK_FUNC(sub_822DB740);
PPC_FUNC_IMPL(__imp__sub_822DB740) {
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
	ctx.lr = 0x822DB748;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x822e6fc8
	ctx.lr = 0x822DB758;
	sub_822E6FC8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// addi r10,r11,-12004
	ctx.r10.s64 = r11.s64 + -12004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822DB76C;
	sub_821B5A60(ctx, base);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822db79c
	if (cr6.eq) goto loc_822DB79C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e6e10
	ctx.lr = 0x822DB784;
	sub_822E6E10(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-12020
	ctx.r10.s64 = r11.s64 + -12020;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DB79C;
	sub_82130000(ctx, base);
loc_822DB79C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822DB7A8"))) PPC_WEAK_FUNC(sub_822DB7A8);
PPC_FUNC_IMPL(__imp__sub_822DB7A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822db740
	sub_822DB740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822DB7B4"))) PPC_WEAK_FUNC(sub_822DB7B4);
PPC_FUNC_IMPL(__imp__sub_822DB7B4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB7B8"))) PPC_WEAK_FUNC(sub_822DB7B8);
PPC_FUNC_IMPL(__imp__sub_822DB7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r9,160
	ctx.r9.s64 = 160;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,240
	r11.s64 = 240;
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lwz r7,72(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// lwz r6,76(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// stw r6,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r6.u32);
	// lvx128 v59,r4,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f11,100(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,100(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f10,104(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,104(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// lfs f9,108(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,108(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// lfs f8,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,112(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f7,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,116(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f6,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,120(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lfs f5,124(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,124(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// lfs f4,128(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,128(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// lfs f3,132(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,132(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// lfs f2,136(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,136(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// lfs f1,140(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,140(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lfs f0,144(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// lfs f13,148(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,148(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f12,152(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,152(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// lvx128 v58,r4,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,176(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,208(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 208);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,208(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// lfs f9,212(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 212);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,212(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// lfs f8,216(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 216);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,216(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// lfs f7,220(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 220);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,220(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// lfs f6,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,224(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,256(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lfs f4,260(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,260(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// lfs f3,264(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 264);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,264(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// lfs f2,268(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,268(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// lfs f1,272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 272);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,272(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// lfs f0,276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	f0.f64 = double(temp.f32);
	// stfs f0,276(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// lfs f13,280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,280(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// lfs f12,284(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 284);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,284(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB920"))) PPC_WEAK_FUNC(sub_822DB920);
PPC_FUNC_IMPL(__imp__sub_822DB920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20380(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20380);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB92C"))) PPC_WEAK_FUNC(sub_822DB92C);
PPC_FUNC_IMPL(__imp__sub_822DB92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB930"))) PPC_WEAK_FUNC(sub_822DB930);
PPC_FUNC_IMPL(__imp__sub_822DB930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20384(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20384);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB93C"))) PPC_WEAK_FUNC(sub_822DB93C);
PPC_FUNC_IMPL(__imp__sub_822DB93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB940"))) PPC_WEAK_FUNC(sub_822DB940);
PPC_FUNC_IMPL(__imp__sub_822DB940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20388(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20388);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB94C"))) PPC_WEAK_FUNC(sub_822DB94C);
PPC_FUNC_IMPL(__imp__sub_822DB94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB950"))) PPC_WEAK_FUNC(sub_822DB950);
PPC_FUNC_IMPL(__imp__sub_822DB950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20396(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20396);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB95C"))) PPC_WEAK_FUNC(sub_822DB95C);
PPC_FUNC_IMPL(__imp__sub_822DB95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB960"))) PPC_WEAK_FUNC(sub_822DB960);
PPC_FUNC_IMPL(__imp__sub_822DB960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20392(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20392);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB96C"))) PPC_WEAK_FUNC(sub_822DB96C);
PPC_FUNC_IMPL(__imp__sub_822DB96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB970"))) PPC_WEAK_FUNC(sub_822DB970);
PPC_FUNC_IMPL(__imp__sub_822DB970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20400);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DB97C"))) PPC_WEAK_FUNC(sub_822DB97C);
PPC_FUNC_IMPL(__imp__sub_822DB97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DB980"))) PPC_WEAK_FUNC(sub_822DB980);
PPC_FUNC_IMPL(__imp__sub_822DB980) {
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
	// addi r9,r11,-11620
	ctx.r9.s64 = r11.s64 + -11620;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822db9b4
	if (cr6.eq) goto loc_822DB9B4;
	// bl 0x82130588
	ctx.lr = 0x822DB9B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB9B4:
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

__attribute__((alias("__imp__sub_822DB9C8"))) PPC_WEAK_FUNC(sub_822DB9C8);
PPC_FUNC_IMPL(__imp__sub_822DB9C8) {
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
	// addi r9,r11,-11608
	ctx.r9.s64 = r11.s64 + -11608;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822db9fc
	if (cr6.eq) goto loc_822DB9FC;
	// bl 0x82130588
	ctx.lr = 0x822DB9F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB9FC:
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

__attribute__((alias("__imp__sub_822DBA10"))) PPC_WEAK_FUNC(sub_822DBA10);
PPC_FUNC_IMPL(__imp__sub_822DBA10) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-11596
	ctx.r9.s64 = r11.s64 + -11596;
	// addi r8,r10,-11608
	ctx.r8.s64 = ctx.r10.s64 + -11608;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dba50
	if (cr6.eq) goto loc_822DBA50;
	// bl 0x82130588
	ctx.lr = 0x822DBA4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBA50:
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

__attribute__((alias("__imp__sub_822DBA64"))) PPC_WEAK_FUNC(sub_822DBA64);
PPC_FUNC_IMPL(__imp__sub_822DBA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DBA68"))) PPC_WEAK_FUNC(sub_822DBA68);
PPC_FUNC_IMPL(__imp__sub_822DBA68) {
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
	// addi r9,r11,-11584
	ctx.r9.s64 = r11.s64 + -11584;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822dba9c
	if (cr6.eq) goto loc_822DBA9C;
	// bl 0x82130588
	ctx.lr = 0x822DBA98;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBA9C:
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

__attribute__((alias("__imp__sub_822DBAB0"))) PPC_WEAK_FUNC(sub_822DBAB0);
PPC_FUNC_IMPL(__imp__sub_822DBAB0) {
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
	// addi r9,r11,-11572
	ctx.r9.s64 = r11.s64 + -11572;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822dbae4
	if (cr6.eq) goto loc_822DBAE4;
	// bl 0x82130588
	ctx.lr = 0x822DBAE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBAE4:
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

__attribute__((alias("__imp__sub_822DBAF8"))) PPC_WEAK_FUNC(sub_822DBAF8);
PPC_FUNC_IMPL(__imp__sub_822DBAF8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r5,r11,-11560
	ctx.r5.s64 = r11.s64 + -11560;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r10,-11572
	ctx.r3.s64 = ctx.r10.s64 + -11572;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r11,r9,-11584
	r11.s64 = ctx.r9.s64 + -11584;
	// addi r10,r8,-11596
	ctx.r10.s64 = ctx.r8.s64 + -11596;
	// stw r3,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r3.u32);
	// addi r9,r7,-11608
	ctx.r9.s64 = ctx.r7.s64 + -11608;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// addi r8,r6,-11620
	ctx.r8.s64 = ctx.r6.s64 + -11620;
	// stw r10,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r10.u32);
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dbb6c
	if (cr6.eq) goto loc_822DBB6C;
	// bl 0x82130588
	ctx.lr = 0x822DBB68;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBB6C:
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

__attribute__((alias("__imp__sub_822DBB80"))) PPC_WEAK_FUNC(sub_822DBB80);
PPC_FUNC_IMPL(__imp__sub_822DBB80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20496(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20496);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DBB8C"))) PPC_WEAK_FUNC(sub_822DBB8C);
PPC_FUNC_IMPL(__imp__sub_822DBB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DBB90"))) PPC_WEAK_FUNC(sub_822DBB90);
PPC_FUNC_IMPL(__imp__sub_822DBB90) {
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
	// bl 0x824973c8
	ctx.lr = 0x822DBBB0;
	sub_824973C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dbbc8
	if (cr6.eq) goto loc_822DBBC8;
	// bl 0x82130588
	ctx.lr = 0x822DBBC4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBBC8:
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

__attribute__((alias("__imp__sub_822DBBE0"))) PPC_WEAK_FUNC(sub_822DBBE0);
PPC_FUNC_IMPL(__imp__sub_822DBBE0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-11536
	ctx.r10.s64 = r11.s64 + -11536;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DBC04;
	sub_82130000(ctx, base);
	// addi r3,r31,572
	ctx.r3.s64 = r31.s64 + 572;
	// bl 0x82495d58
	ctx.lr = 0x822DBC0C;
	sub_82495D58(ctx, base);
	// addi r3,r31,532
	ctx.r3.s64 = r31.s64 + 532;
	// bl 0x82495d58
	ctx.lr = 0x822DBC14;
	sub_82495D58(ctx, base);
	// addi r3,r31,492
	ctx.r3.s64 = r31.s64 + 492;
	// bl 0x82495d58
	ctx.lr = 0x822DBC1C;
	sub_82495D58(ctx, base);
	// addi r3,r31,452
	ctx.r3.s64 = r31.s64 + 452;
	// bl 0x82495d58
	ctx.lr = 0x822DBC24;
	sub_82495D58(ctx, base);
	// addi r3,r31,412
	ctx.r3.s64 = r31.s64 + 412;
	// bl 0x82495d58
	ctx.lr = 0x822DBC2C;
	sub_82495D58(ctx, base);
	// addi r3,r31,372
	ctx.r3.s64 = r31.s64 + 372;
	// bl 0x82495d58
	ctx.lr = 0x822DBC34;
	sub_82495D58(ctx, base);
	// addi r3,r31,332
	ctx.r3.s64 = r31.s64 + 332;
	// bl 0x82495d58
	ctx.lr = 0x822DBC3C;
	sub_82495D58(ctx, base);
	// addi r3,r31,292
	ctx.r3.s64 = r31.s64 + 292;
	// bl 0x82495d58
	ctx.lr = 0x822DBC44;
	sub_82495D58(ctx, base);
	// addi r3,r31,252
	ctx.r3.s64 = r31.s64 + 252;
	// bl 0x82495d58
	ctx.lr = 0x822DBC4C;
	sub_82495D58(ctx, base);
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// bl 0x82495d58
	ctx.lr = 0x822DBC54;
	sub_82495D58(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x82495d58
	ctx.lr = 0x822DBC5C;
	sub_82495D58(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x82495d58
	ctx.lr = 0x822DBC64;
	sub_82495D58(ctx, base);
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x82495d58
	ctx.lr = 0x822DBC6C;
	sub_82495D58(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x82495d58
	ctx.lr = 0x822DBC74;
	sub_82495D58(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82495d58
	ctx.lr = 0x822DBC7C;
	sub_82495D58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DBC84;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_822DBC98"))) PPC_WEAK_FUNC(sub_822DBC98);
PPC_FUNC_IMPL(__imp__sub_822DBC98) {
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
	// bl 0x822dbbe0
	ctx.lr = 0x822DBCB8;
	sub_822DBBE0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dbcd0
	if (cr6.eq) goto loc_822DBCD0;
	// bl 0x82130588
	ctx.lr = 0x822DBCCC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBCD0:
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

__attribute__((alias("__imp__sub_822DBCE8"))) PPC_WEAK_FUNC(sub_822DBCE8);
PPC_FUNC_IMPL(__imp__sub_822DBCE8) {
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
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// bl 0x821be710
	ctx.lr = 0x822DBD14;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// bl 0x821be710
	ctx.lr = 0x822DBD24;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,44
	ctx.r4.s64 = r31.s64 + 44;
	// bl 0x821be710
	ctx.lr = 0x822DBD34;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// bl 0x821be710
	ctx.lr = 0x822DBD44;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x822DBD54;
	sub_821BE710(ctx, base);
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

__attribute__((alias("__imp__sub_822DBD6C"))) PPC_WEAK_FUNC(sub_822DBD6C);
PPC_FUNC_IMPL(__imp__sub_822DBD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DBD70"))) PPC_WEAK_FUNC(sub_822DBD70);
PPC_FUNC_IMPL(__imp__sub_822DBD70) {
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
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4288
	ctx.r4.s64 = r31.s64 + 4288;
	// lwz r3,816(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 816);
	// bl 0x8218aef8
	ctx.lr = 0x822DBD98;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 820);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4304
	ctx.r4.s64 = r31.s64 + 4304;
	// bl 0x8218aef8
	ctx.lr = 0x822DBDAC;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,824(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 824);
	// addi r4,r31,4320
	ctx.r4.s64 = r31.s64 + 4320;
	// bl 0x8218aef8
	ctx.lr = 0x822DBDC0;
	sub_8218AEF8(ctx, base);
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

__attribute__((alias("__imp__sub_822DBDD4"))) PPC_WEAK_FUNC(sub_822DBDD4);
PPC_FUNC_IMPL(__imp__sub_822DBDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DBDD8"))) PPC_WEAK_FUNC(sub_822DBDD8);
PPC_FUNC_IMPL(__imp__sub_822DBDD8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// addi r4,r10,-11468
	ctx.r4.s64 = ctx.r10.s64 + -11468;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822DBE14;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dbe54
	if (cr6.eq) goto loc_822DBE54;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,832
	ctx.r4.s64 = r30.s64 + 832;
	// bl 0x821be710
	ctx.lr = 0x822DBE2C;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,840
	ctx.r4.s64 = r30.s64 + 840;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x822DBE3C;
	sub_821BE710(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4168
	ctx.r3.s64 = r11.s64 + 4168;
	// bl 0x822dbce8
	ctx.lr = 0x822DBE4C;
	sub_822DBCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x822DBE54;
	sub_821BE610(ctx, base);
loc_822DBE54:
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

__attribute__((alias("__imp__sub_822DBE6C"))) PPC_WEAK_FUNC(sub_822DBE6C);
PPC_FUNC_IMPL(__imp__sub_822DBE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DBE70"))) PPC_WEAK_FUNC(sub_822DBE70);
PPC_FUNC_IMPL(__imp__sub_822DBE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r9,160
	ctx.r9.s64 = 160;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,240
	r11.s64 = 240;
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lfs f12,72(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lfs f11,76(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,76(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// lvx128 v59,r4,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,96(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,96(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f9,100(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,100(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f8,104(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,104(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// lfs f7,108(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,108(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// lfs f6,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,112(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f5,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,116(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f4,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,120(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lfs f3,124(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,124(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// lfs f2,128(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,128(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// lfs f1,132(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,132(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// lfs f0,136(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	f0.f64 = double(temp.f32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// lfs f13,140(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lfs f12,144(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,144(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// lfs f11,148(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,148(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f10,152(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,152(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// lvx128 v58,r4,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,176(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,208(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 208);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,208(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// lfs f7,212(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 212);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,212(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// lfs f6,216(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 216);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,216(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// lfs f5,220(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 220);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,220(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// lfs f4,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,224(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,256(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lfs f2,260(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,260(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// lfs f1,264(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 264);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,264(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// lfs f0,268(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	f0.f64 = double(temp.f32);
	// stfs f0,268(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// lfs f13,272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,272(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// lfs f12,276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,276(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// lfs f11,280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,280(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// lfs f10,284(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 284);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,284(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822DBFD8"))) PPC_WEAK_FUNC(sub_822DBFD8);
PPC_FUNC_IMPL(__imp__sub_822DBFD8) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dc024
	if (cr6.eq) goto loc_822DC024;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DBFFC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822dc024
	if (!cr6.eq) goto loc_822DC024;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dc024
	if (cr6.eq) goto loc_822DC024;
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
	ctx.lr = 0x822DC024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DC024:
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

__attribute__((alias("__imp__sub_822DC038"))) PPC_WEAK_FUNC(sub_822DC038);
PPC_FUNC_IMPL(__imp__sub_822DC038) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11452
	ctx.r9.s64 = r11.s64 + -11452;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DC070;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14468(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14468, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DC084;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dc09c
	if (cr6.eq) goto loc_822DC09C;
	// bl 0x82130588
	ctx.lr = 0x822DC098;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DC09C:
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

__attribute__((alias("__imp__sub_822DC0B4"))) PPC_WEAK_FUNC(sub_822DC0B4);
PPC_FUNC_IMPL(__imp__sub_822DC0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DC0B8"))) PPC_WEAK_FUNC(sub_822DC0B8);
PPC_FUNC_IMPL(__imp__sub_822DC0B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lhz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x822dc0ec
	if (!cr6.gt) goto loc_822DC0EC;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_822DC0D0:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x822dc164
	if (!cr6.lt) goto loc_822DC164;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822dc0d0
	if (cr6.lt) goto loc_822DC0D0;
loc_822DC0EC:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_822DC100:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,-4(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,-16(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,-12(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,-8(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822DC164:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x822dc100
	goto loc_822DC100;
}

__attribute__((alias("__imp__sub_822DC178"))) PPC_WEAK_FUNC(sub_822DC178);
PPC_FUNC_IMPL(__imp__sub_822DC178) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lhz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x822dc1ac
	if (!cr6.gt) goto loc_822DC1AC;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_822DC190:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x822dc224
	if (!cr6.lt) goto loc_822DC224;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822dc190
	if (cr6.lt) goto loc_822DC190;
loc_822DC1AC:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_822DC1C0:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,-4(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,-16(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,-12(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,-8(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822DC224:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x822dc1c0
	goto loc_822DC1C0;
}

__attribute__((alias("__imp__sub_822DC238"))) PPC_WEAK_FUNC(sub_822DC238);
PPC_FUNC_IMPL(__imp__sub_822DC238) {
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
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82495d58
	ctx.lr = 0x822DC25C;
	sub_82495D58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DC264;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dc27c
	if (cr6.eq) goto loc_822DC27C;
	// bl 0x82130588
	ctx.lr = 0x822DC278;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DC27C:
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

__attribute__((alias("__imp__sub_822DC294"))) PPC_WEAK_FUNC(sub_822DC294);
PPC_FUNC_IMPL(__imp__sub_822DC294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DC298"))) PPC_WEAK_FUNC(sub_822DC298);
PPC_FUNC_IMPL(__imp__sub_822DC298) {
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
	ctx.lr = 0x822DC2A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r11,-11428
	ctx.r5.s64 = r11.s64 + -11428;
	// addi r3,r10,-11560
	ctx.r3.s64 = ctx.r10.s64 + -11560;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r11,r9,-11572
	r11.s64 = ctx.r9.s64 + -11572;
	// stw r3,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, ctx.r3.u32);
	// addi r10,r8,-11584
	ctx.r10.s64 = ctx.r8.s64 + -11584;
	// addi r9,r7,-11596
	ctx.r9.s64 = ctx.r7.s64 + -11596;
	// stw r11,4096(r31)
	PPC_STORE_U32(r31.u32 + 4096, r11.u32);
	// addi r8,r6,-11608
	ctx.r8.s64 = ctx.r6.s64 + -11608;
	// stw r10,4080(r31)
	PPC_STORE_U32(r31.u32 + 4080, ctx.r10.u32);
	// addi r7,r4,-11620
	ctx.r7.s64 = ctx.r4.s64 + -11620;
	// stw r9,3952(r31)
	PPC_STORE_U32(r31.u32 + 3952, ctx.r9.u32);
	// stw r8,4048(r31)
	PPC_STORE_U32(r31.u32 + 4048, ctx.r8.u32);
	// addi r30,r31,3840
	r30.s64 = r31.s64 + 3840;
	// stw r7,3856(r31)
	PPC_STORE_U32(r31.u32 + 3856, ctx.r7.u32);
	// li r29,3
	r29.s64 = 3;
loc_822DC304:
	// addi r30,r30,-80
	r30.s64 = r30.s64 + -80;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// bl 0x82495d58
	ctx.lr = 0x822DC310;
	sub_82495D58(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DC318;
	sub_821D2028(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x822dc304
	if (!cr0.lt) goto loc_822DC304;
	// addi r30,r31,3520
	r30.s64 = r31.s64 + 3520;
	// li r29,3
	r29.s64 = 3;
loc_822DC328:
	// addi r30,r30,-656
	r30.s64 = r30.s64 + -656;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dbbe0
	ctx.lr = 0x822DC334;
	sub_822DBBE0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x822dc328
	if (!cr0.lt) goto loc_822DC328;
	// addi r3,r31,848
	ctx.r3.s64 = r31.s64 + 848;
	// bl 0x824973c8
	ctx.lr = 0x822DC344;
	sub_824973C8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82495150
	ctx.lr = 0x822DC34C;
	sub_82495150(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11452
	ctx.r9.s64 = r11.s64 + -11452;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DC368;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14468(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14468, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DC37C;
	sub_822E6940(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822DC384"))) PPC_WEAK_FUNC(sub_822DC384);
PPC_FUNC_IMPL(__imp__sub_822DC384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DC388"))) PPC_WEAK_FUNC(sub_822DC388);
PPC_FUNC_IMPL(__imp__sub_822DC388) {
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
	ctx.lr = 0x822DC390;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r10,r11,-7536
	ctx.r10.s64 = r11.s64 + -7536;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r20,r11,30576
	r20.s64 = r11.s64 + 30576;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// beq cr6,0x822dc3c4
	if (cr6.eq) goto loc_822DC3C4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-11340
	ctx.r4.s64 = ctx.r10.s64 + -11340;
	// b 0x822dc3cc
	goto loc_822DC3CC;
loc_822DC3C4:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-11352
	ctx.r4.s64 = ctx.r10.s64 + -11352;
loc_822DC3CC:
	// bl 0x821ca540
	ctx.lr = 0x822DC3D0;
	sub_821CA540(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x822dbdd8
	ctx.lr = 0x822DC3D8;
	sub_822DBDD8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r21,16
	ctx.r3.s64 = r21.s64 + 16;
	// addi r4,r11,-11360
	ctx.r4.s64 = r11.s64 + -11360;
	// bl 0x82493208
	ctx.lr = 0x822DC3E8;
	sub_82493208(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r22,r11,6912
	r22.s64 = r11.s64 + 6912;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r21,3520
	r29.s64 = r21.s64 + 3520;
	// addi r31,r21,1524
	r31.s64 = r21.s64 + 1524;
	// mr r30,r22
	r30.u64 = r22.u64;
	// lis r23,-32125
	r23.s64 = -2105344000;
	// addi r28,r9,-11516
	r28.s64 = ctx.r9.s64 + -11516;
	// addi r27,r8,-11496
	r27.s64 = ctx.r8.s64 + -11496;
	// addi r26,r7,-11480
	r26.s64 = ctx.r7.s64 + -11480;
	// addi r25,r10,5276
	r25.s64 = ctx.r10.s64 + 5276;
	// addi r24,r11,-11376
	r24.s64 = r11.s64 + -11376;
loc_822DC428:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// lwz r19,0(r30)
	r19.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x822DC43C;
	sub_8261DBE0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,-628
	ctx.r3.s64 = r31.s64 + -628;
	// bl 0x82497d80
	ctx.lr = 0x822DC448;
	sub_82497D80(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r31,-4
	ctx.r6.s64 = r31.s64 + -4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dea0
	ctx.lr = 0x822DC460;
	sub_8261DEA0(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dea0
	ctx.lr = 0x822DC478;
	sub_8261DEA0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r7,9
	ctx.r7.s64 = 9;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261df58
	ctx.lr = 0x822DC490;
	sub_8261DF58(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,2828(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 2828);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// bl 0x821c04b0
	ctx.lr = 0x822DC4AC;
	sub_821C04B0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x822DC4B4;
	sub_8261DCA8(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822DC4C8;
	sub_82137A08(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824981d8
	ctx.lr = 0x822DC4D4;
	sub_824981D8(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r22,16
	r11.s64 = r22.s64 + 16;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// addi r31,r31,656
	r31.s64 = r31.s64 + 656;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822dc428
	if (cr6.lt) goto loc_822DC428;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r21,848
	ctx.r3.s64 = r21.s64 + 848;
	// addi r4,r11,-11392
	ctx.r4.s64 = r11.s64 + -11392;
	// bl 0x82498258
	ctx.lr = 0x822DC4FC;
	sub_82498258(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r21,3840
	ctx.r3.s64 = r21.s64 + 3840;
	// addi r4,r10,-11408
	ctx.r4.s64 = ctx.r10.s64 + -11408;
	// bl 0x82492918
	ctx.lr = 0x822DC50C;
	sub_82492918(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DC514;
	sub_821C9A90(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822DC51C"))) PPC_WEAK_FUNC(sub_822DC51C);
PPC_FUNC_IMPL(__imp__sub_822DC51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DC520"))) PPC_WEAK_FUNC(sub_822DC520);
PPC_FUNC_IMPL(__imp__sub_822DC520) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822DC528;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-2496(r1)
	ea = -2496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// lis r25,-32130
	r25.s64 = -2105671680;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lis r24,-32119
	r24.s64 = -2104950784;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lbzx r9,r26,r27
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// lwz r7,22080(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// lwz r8,-17936(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + -17936);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// bne cr6,0x822dc56c
	if (!cr6.eq) goto loc_822DC56C;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_822DC56C:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// rlwinm r6,r11,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r10,6928
	r29.s64 = ctx.r10.s64 + 6928;
	// li r11,1
	r11.s64 = 1;
	// lfsx f31,r6,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	f31.f64 = double(temp.f32);
loc_822DC580:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// bne cr6,0x822dc590
	if (!cr6.eq) goto loc_822DC590;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_822DC590:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lfsx f0,r6,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// blt cr6,0x822dc580
	if (cr6.lt) goto loc_822DC580;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bne cr6,0x822dc5c8
	if (!cr6.eq) goto loc_822DC5C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f31.f64 = double(temp.f32);
loc_822DC5C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82491158
	ctx.lr = 0x822DC5D0;
	sub_82491158(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r23,896
	r30.s64 = r23.s64 + 896;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f31,f0,f31
	f31.f64 = double(float(f0.f64 / f31.f64));
loc_822DC5E4:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824976a8
	ctx.lr = 0x822DC5F4;
	sub_824976A8(ctx, base);
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dc608
	if (cr6.eq) goto loc_822DC608;
	// lwz r11,22080(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// b 0x822dc60c
	goto loc_822DC60C;
loc_822DC608:
	// lwz r11,-17936(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -17936);
loc_822DC60C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x824921a8
	ctx.lr = 0x822DC628;
	sub_824921A8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82493410
	ctx.lr = 0x822DC634;
	sub_82493410(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,656
	r30.s64 = r30.s64 + 656;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x822dc5e4
	if (cr6.lt) goto loc_822DC5E4;
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r3,r23,3840
	ctx.r3.s64 = r23.s64 + 3840;
	// bl 0x82491aa0
	ctx.lr = 0x822DC654;
	sub_82491AA0(ctx, base);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x822dbe70
	ctx.lr = 0x822DC660;
	sub_822DBE70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,1824
	ctx.r3.s64 = ctx.r1.s64 + 1824;
	// bl 0x822dbe70
	ctx.lr = 0x822DC670;
	sub_822DBE70(ctx, base);
	// lfs f0,4192(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4192);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// bl 0x82493458
	ctx.lr = 0x822DC690;
	sub_82493458(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,1536
	ctx.r3.s64 = ctx.r1.s64 + 1536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82491230
	ctx.lr = 0x822DC6A0;
	sub_82491230(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,2112
	ctx.r3.s64 = ctx.r1.s64 + 2112;
	// bl 0x824921f8
	ctx.lr = 0x822DC6B0;
	sub_824921F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// bl 0x822dbe70
	ctx.lr = 0x822DC6BC;
	sub_822DBE70(ctx, base);
	// addi r4,r1,672
	ctx.r4.s64 = ctx.r1.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822db7b8
	ctx.lr = 0x822DC6C8;
	sub_822DB7B8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,2496
	ctx.r1.s64 = ctx.r1.s64 + 2496;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822DC6DC"))) PPC_WEAK_FUNC(sub_822DC6DC);
PPC_FUNC_IMPL(__imp__sub_822DC6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822DC6E0"))) PPC_WEAK_FUNC(sub_822DC6E0);
PPC_FUNC_IMPL(__imp__sub_822DC6E0) {
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
	// bl 0x822e6b80
	ctx.lr = 0x822DC700;
	sub_822E6B80(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addi r8,r11,-11452
	ctx.r8.s64 = r11.s64 + -11452;
	// ori r7,r9,3
	ctx.r7.u64 = ctx.r9.u64 | 3;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r31,-14468(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14468, r31.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DC734;
	sub_822E5138(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822e6ae8
	ctx.lr = 0x822DC744;
	sub_822E6AE8(ctx, base);
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

__attribute__((alias("__imp__sub_822DC760"))) PPC_WEAK_FUNC(sub_822DC760);
PPC_FUNC_IMPL(__imp__sub_822DC760) {
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
	ctx.lr = 0x822DC768;
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
	ctx.lr = 0x822DC79C;
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
	// beq cr6,0x822dc808
	if (cr6.eq) goto loc_822DC808;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x826122b0
	ctx.lr = 0x822DC7EC;
	sub_826122B0(ctx, base);
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
loc_822DC808:
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

